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
        this.chunks = [];
        this.totalLen = 0;
        this.connected = false;
        this.destroyed = false;

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
        
        this.socket = net.createConnection(this.pipePath);

        this.socket.on('connect', () => {
            if (this.reconnectTimer) {
                clearTimeout(this.reconnectTimer);
                this.reconnectTimer = null;
            }
            this.connected = true;
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
        if (chunk) {
            this.chunks.push(chunk);
            this.totalLen += chunk.length;
        }

        while (this.totalLen >= 9) {
            // 1. Get header to find out packet size
            let header;
            if (this.chunks[0].length >= 9) {
                header = this.chunks[0];
            } else {
                header = Buffer.concat(this.chunks, 9);
            }

            const magic = header.readUInt32LE(0);
            if (magic !== 0x5354524D) {
                // Lost sync - very rare, scan for next STRM magic
                const full = Buffer.concat(this.chunks);
                const idx = full.indexOf(Buffer.from([0x53, 0x54, 0x52, 0x4D]));
                if (idx !== -1) {
                    const recovered = full.slice(idx);
                    this.chunks = [recovered];
                    this.totalLen = recovered.length;
                    continue;
                } else {
                    this.chunks = [];
                    this.totalLen = 0;
                    break;
                }
            }

            const type = header.readUInt8(4);
            const payloadSize = header.readUInt32LE(5);
            const totalPacketSize = 9 + payloadSize;

            if (this.totalLen < totalPacketSize) break;

            // 2. Efficiently pull the full packet without frequent full-concats
            let fullPacket;
            if (this.chunks[0].length === totalPacketSize) {
                fullPacket = this.chunks.shift();
            } else if (this.chunks[0].length > totalPacketSize) {
                fullPacket = this.chunks[0].slice(0, totalPacketSize);
                this.chunks[0] = this.chunks[0].slice(totalPacketSize);
            } else {
                // Packet spans multiple chunks
                fullPacket = Buffer.allocUnsafe(totalPacketSize);
                let offset = 0;
                while (offset < totalPacketSize) {
                    const chunk = this.chunks[0];
                    const bytesToCopy = Math.min(chunk.length, totalPacketSize - offset);
                    chunk.copy(fullPacket, offset, 0, bytesToCopy);
                    offset += bytesToCopy;
                    
                    if (bytesToCopy === chunk.length) {
                        this.chunks.shift();
                    } else {
                        this.chunks[0] = chunk.slice(bytesToCopy);
                    }
                }
            }
            this.totalLen -= totalPacketSize;
            const payload = fullPacket.slice(9);

            if (type === 0) { // Video
                this.frameCount = (this.frameCount || 0) + 1;
                
                if (this.frameCount % 120 === 0) {
                    console.log(`[PipeBridge P${this.slot}] Received ${this.frameCount} packets from mGBA. (Encoder: ${this.encoder.isActive ? 'ACTIVE (MJPEG)' : 'INACTIVE'})`);
                }
                
                if (payload.length >= 8) {
                    // Start after width/height header
                    const pixelData = payload.slice(8);
                    if (this.encoder && this.encoder.isActive) {
                        const ok = this.encoder.write(pixelData);
                        if (!ok && this.frameCount % 60 === 0) {
                            console.warn(`[PipeBridge P${this.slot}] FFmpeg stdin BACKPRESSURE detected at frame ${this.frameCount}`);
                        }
                    } else {
                        // Fallback to raw if encoder fails
                        this.emit('video', { width: 240, height: 160, data: pixelData });
                    }
                }
            } else if (type === 1) { // Audio
                this.emit('audio', payload);
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
