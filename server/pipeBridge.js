const fs = require('fs');
const EventEmitter = require('events');

/**
 * PipeBridge
 * Connects to an mGBA named pipe and parses the STRM protocol.
 * Protocol:
 * [Magic (4b: "STRM")][Type (1b: 0=Video, 1=Audio)][Size (4b LE)][Payload (Size bytes)]
 * Video Payload: [Width (4b)][Height (4b)][Raw Pixels (W*H*4 bytes)]
 */
class PipeBridge extends EventEmitter {
    constructor(pipeName, slot) {
        super();
        this.pipePath = `\\\\.\\pipe\\${pipeName}`;
        this.slot = slot;
        this.stream = null;
        this.buffer = Buffer.alloc(0);
        this.connected = false;
        this.reconnectTimer = null;
    }

    connect() {
        console.log(`[PipeBridge P${this.slot}] Connecting to ${this.pipePath}...`);
        
        try {
            this.stream = fs.createReadStream(this.pipePath);
            
            this.stream.on('data', (chunk) => {
                if (!this.connected) {
                    this.connected = true;
                    console.log(`[PipeBridge P${this.slot}] Stream pipe connected.`);
                    this.emit('connected');
                }
                this.handleData(chunk);
            });

            this.stream.on('error', (err) => {
                if (err.code === 'ENOENT') {
                    // Pipe not ready yet, retry
                    this.retry();
                } else {
                    console.error(`[PipeBridge P${this.slot}] Error:`, err.message);
                    this.emit('error', err);
                    this.retry();
                }
            });

            this.stream.on('end', () => {
                console.log(`[PipeBridge P${this.slot}] Stream ended.`);
                this.connected = false;
                this.retry();
            });

        } catch (e) {
            console.error(`[PipeBridge P${this.slot}] Connection failed:`, e.message);
            this.retry();
        }
    }

    retry() {
        if (this.reconnectTimer) return;
        this.connected = false;
        this.reconnectTimer = setTimeout(() => {
            this.reconnectTimer = null;
            this.connect();
        }, 1000);
    }

    handleData(chunk) {
        this.buffer = Buffer.concat([this.buffer, chunk]);

        while (this.buffer.length >= 9) { // Header size (4 + 1 + 4)
            // Check Magic: "STRM" (0x53 0x54 0x52 0x4D)
            const magic = this.buffer.readUInt32BE(0);
            if (magic !== 0x5354524D) {
                // Seek for magic if misaligned
                const index = this.buffer.indexOf(Buffer.from([0x53, 0x54, 0x52, 0x4D]));
                if (index !== -1) {
                    this.buffer = this.buffer.slice(index);
                    continue;
                } else {
                    if (this.buffer.length > 1024) this.buffer = Buffer.alloc(0);
                    break;
                }
            }

            const type = this.buffer.readUInt8(4);
            const totalSize = this.buffer.readUInt32LE(5);

            if (this.buffer.length < 9 + totalSize) break;

            const payload = this.buffer.slice(9, 9 + totalSize);
            this.buffer = this.buffer.slice(9 + totalSize);

            if (type === 0) { // Video
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
