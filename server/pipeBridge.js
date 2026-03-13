const net = require('net');
const EventEmitter = require('events');

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
        this.reconnectTimer = null;
        this.destroyed = false;
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
            // Peek header
            let header = Buffer.concat(this.chunks, 9);
            const magic = header.readUInt32LE(0);
            
            if (magic !== 0x5354524D) {
                // Seek logic (rarely needed if protocol is stable)
                let fullBuf = Buffer.concat(this.chunks);
                const index = fullBuf.indexOf(Buffer.from([0x4D, 0x52, 0x54, 0x53]));
                if (index !== -1) {
                    let discarded = index;
                    this.chunks = [fullBuf.slice(index)];
                    this.totalLen = this.chunks[0].length;
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

            // Extract full packet
            let fullPacket = Buffer.concat(this.chunks, totalPacketSize);
            const payload = fullPacket.slice(9);

            // Update internal buffer state (consume)
            let remaining = Buffer.concat(this.chunks).slice(totalPacketSize);
            this.chunks = [remaining];
            this.totalLen = remaining.length;

            if (type === 0) { // Video
                this.frameCount = (this.frameCount || 0) + 1;
                
                // Log every 1 second (60 frames) to check clock jitter
                if (this.frameCount % 60 === 0) {
                    const now = new Date();
                    const timestamp = `${now.getHours()}:${now.getMinutes()}:${now.getSeconds()}`;
                    console.log(`[PipeBridge P${this.slot}] @ ${timestamp}: 60 frames sent. Total: ${this.frameCount}`);
                }
                
                if (payload.length >= 8) {
                    const width = payload.readUInt32LE(0);
                    const height = payload.readUInt32LE(4);
                    const pixelData = payload.slice(8);
                    this.emit('video', { width, height, data: pixelData });
                }
            } else if (type === 1) { // Audio
                this.emit('audio', payload);
            }
        }
    }

    close() {
        if (this.reconnectTimer) clearTimeout(this.reconnectTimer);
        if (this.stream) {
            this.stream.destroy();
            this.stream = null;
        }
    }
}

module.exports = PipeBridge;
