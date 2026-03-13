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
        this.buffer = Buffer.alloc(0);
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
        this.buffer = Buffer.concat([this.buffer, chunk]);

        while (this.buffer.length >= 9) { // Header size (4 + 1 + 4)
            // Check Magic: "STRM" (0x53 0x54 0x52 0x4D)
            const magic = this.buffer.readUInt32LE(0);
            if (magic !== 0x5354524D) {
                // Seek for magic if misaligned
                const index = this.buffer.indexOf(Buffer.from([0x4D, 0x52, 0x54, 0x53])); // "M R T S" (LE "STRM")
                if (index !== -1) {
                    this.buffer = this.buffer.slice(index);
                    continue;
                } else {
                    if (this.buffer.length > 2048) this.buffer = this.buffer.slice(this.buffer.length - 4);
                    break;
                }
            }

            const type = this.buffer.readUInt8(4);
            const totalSize = this.buffer.readUInt32LE(5);

            if (this.buffer.length < 9 + totalSize) break;

            const payload = this.buffer.slice(9, 9 + totalSize);
            this.buffer = this.buffer.slice(9 + totalSize);

            if (type === 0) { // Video
                this.frameCount = (this.frameCount || 0) + 1;
                if (this.frameCount === 1 || this.frameCount % 240 === 0) {
                    console.log(`[PipeBridge P${this.slot}] Received ${this.frameCount} frames. Size: ${payload.length} bytes`);
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
