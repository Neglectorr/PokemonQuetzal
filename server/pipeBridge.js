const net = require('net');
const EventEmitter = require('events');
const VideoEncoder = require('./videoEncoder');

/**
 * PipeBridge
 * Connects to an mGBA named pipe and parses the STRM protocol.
 */
class PipeBridge extends EventEmitter {
    constructor(pipeName, slot) {
        super();
        this.pipePath = `\\\\.\\pipe\\${pipeName}`;
        this.slot = slot;
        this.socket = null;
        this.frameCount = 0;
        this.skippedCount = 0;
        
        // HIGH-PERFORMANCE BUFFER
        this.buffer = Buffer.alloc(10 * 1024 * 1024); // 10MB Pre-allocated
        this.writePos = 0;
        this.readPos = 0;
        this.dataLen = 0;

        // Encoder setup for 50x bandwidth reduction
        this.encoder = new VideoEncoder({ slot: this.slot });
        this.encoder.on('frame', (webpData) => {
            this.emit('video', { 
                width: 240, 
                height: 160, 
                data: webpData,
                compressed: true 
            });
        });
        this.encoder.start();
    }

    connect() {
        if (this.destroyed) return;
        console.log(`[PipeBridge P${this.slot}] Connecting to ${this.pipePath}...`);
        
        this.socket = net.createConnection({
            path: this.pipePath,
            readableHighWaterMark: 1024 * 1024 // 1MB buffer
        });

        this.socket.on('connect', () => {
            if (this.reconnectTimer) {
                clearTimeout(this.reconnectTimer);
                this.reconnectTimer = null;
            }
            this.connected = true;
            this.socket.setNoDelay(true); // Disable Nagle's algorithm for raw throughput
            console.log(`[PipeBridge P${this.slot}] Stream pipe connected via NET.`);
            this.emit('connected');
        });

        this.socket.on('data', (chunk) => {
            this.handleData(chunk);
        });

        this.socket.on('error', (err) => {
            if (!this.connected) {
                // Initial connection failed, silently retry
                this.retry();
            } else {
                console.error(`[PipeBridge P${this.slot}] Socket Error:`, err.message);
                this.retry();
            }
        });

        this.socket.on('close', () => {
            if (this.connected) {
                console.log(`[PipeBridge P${this.slot}] Stream pipe closed.`);
                this.connected = false;
            }
            this.retry();
        });
    }

    retry() {
        if (this.reconnectTimer || this.destroyed) return;
        this.reconnectTimer = setTimeout(() => {
            this.reconnectTimer = null;
            this.connect();
        }, 1000);
    }

    handleData(chunk) {
        if (!chunk) return;

        // 1. Write incoming chunk to ring buffer
        if (this.dataLen + chunk.length > this.buffer.length) {
            console.warn(`[PipeBridge P${this.slot}] Buffer Overflow! Purging to recover...`);
            this.dataLen = 0;
            this.writePos = 0;
            this.readPos = 0;
        }

        chunk.copy(this.buffer, this.writePos);
        this.writePos += chunk.length;
        this.dataLen += chunk.length;

        // 2. Parse packets from ring buffer
        const STRM_MAGIC = 0x5354524D;
        
        while (this.dataLen >= 9) {
            const magic = this.buffer.readUInt32LE(this.readPos);
            
            if (magic !== STRM_MAGIC) {
                // Out of sync - find next magic
                let found = false;
                for (let i = 1; i < this.dataLen - 4; i++) {
                    if (this.buffer.readUInt32LE((this.readPos + i) % this.buffer.length) === STRM_MAGIC) {
                        this.readPos = (this.readPos + i) % this.buffer.length;
                        this.dataLen -= i;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    this.dataLen = 0;
                    this.writePos = 0;
                    this.readPos = 0;
                    break;
                }
                continue;
            }

            const type = this.buffer.readUInt8(this.readPos + 4);
            const payloadSize = this.buffer.readUInt32LE(this.readPos + 5);
            const packetSize = 9 + payloadSize;

            if (this.dataLen < packetSize) break;

            // Extract payload
            const payload = Buffer.allocUnsafe(payloadSize);
            this.buffer.copy(payload, 0, this.readPos + 9, this.readPos + packetSize);
            
            this.readPos += packetSize;
            this.dataLen -= packetSize;

            if (type === 0) { // Video
                this.frameCount++;
                if (payload.length >= 8) {
                    const pixelData = payload.slice(8);
                    
                    if (this.lastPixelBuffer && this.lastPixelBuffer.equals(pixelData)) {
                        this.skippedCount++;
                        continue;
                    }
                    this.lastPixelBuffer = Buffer.from(pixelData);

                    if (this.encoder && this.encoder.isActive) {
                        if (this.encoder.ffmpeg.stdin.writableLength < 1000000) {
                            this.encoder.write(pixelData);
                        }
                    } else {
                        this.emit('video', { width: 240, height: 160, data: pixelData });
                    }
                }
            } else if (type === 1) { // Audio
                this.emit('audio', payload);
            }

            // Cleanup Pos if buffer is empty
            if (this.dataLen === 0) {
                this.readPos = 0;
                this.writePos = 0;
            }
        }
    }

    close() {
        if (this.reconnectTimer) clearTimeout(this.reconnectTimer);
        if (this.socket) {
            this.socket.destroy();
            this.socket = null;
        }
        if (this.encoder) {
            this.encoder.stop();
            this.encoder = null;
        }
        this.destroyed = true;
    }
}

module.exports = PipeBridge;
