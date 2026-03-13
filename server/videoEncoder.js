const { spawn } = require('child_process');
const path = require('path');
const fs = require('fs');
const EventEmitter = require('events');

/**
 * VideoEncoder using FFmpeg to compress raw GBA pixels into WebP/MJPEG.
 * This offloads bandwidth pressure and allows 60fps streaming.
 */
class VideoEncoder extends EventEmitter {
    constructor(options = {}) {
        super();
        this.options = options;
        this.width = options.width || 240;
        this.height = options.height || 160;
        this.fps = options.fps || 60;
        
        // Detect FFmpeg path from available locations
        this.ffmpegPath = options.ffmpegPath || this.findFFmpeg();
        
        this.ffmpeg = null;
        this.isActive = false;
        this.emittedCount = 0;
        
        // OPTIMIZED MJPEG PARSING
        this.buffer = Buffer.alloc(2 * 1024 * 1024); // 2MB Pre-allocated
        this.dataOffset = 0;
        this.SOI = Buffer.from([0xFF, 0xD8]);
        this.EOI = Buffer.from([0xFF, 0xD9]);
    }

    findFFmpeg() {
        const localPath = path.join(__dirname, '..', 'bin', 'ffmpeg.exe');
        if (fs.existsSync(localPath)) return localPath;

        const candidates = [
            'C:\\Program Files\\SteelSeries\\GG\\apps\\moments\\ffmpeg.exe',
            'C:\\Program Files\\Krita (x64)\\bin\\ffmpeg.exe',
            'C:\\Program Files\\net.downloadhelper.coapp\\converter\\build\\win\\64\\ffmpeg.exe',
            'ffmpeg.exe' // Try PATH as last resort
        ];

        for (const p of candidates) {
            if (p === 'ffmpeg.exe') return p;
            if (fs.existsSync(p)) return p;
        }
        return null;
    }

    start() {
        if (this.isActive) return;

        // Command: Read raw pixels from stdin, output MJPEG stream to stdout
        // We use 'bgra' because that's mGBA's native software output on Windows
        const args = [
            '-f', 'rawvideo',
            '-pixel_format', 'rgba',
            '-video_size', `${this.width}x${this.height}`,
            '-i', '-',
            '-f', 'image2pipe',
            '-vcodec', 'mjpeg',
            '-q:v', '5', // Good balance of speed/quality
            '-threads', '0', // AUTO-THREADS for maximum speed
            '-preset', 'ultrafast',
            '-an', '-sn',
            '-'
        ];

        if (!this.ffmpegPath) {
            console.error(`[VideoEncoder P${this.options.slot || '?'}] No FFmpeg found!`);
            return;
        }

        console.log(`[VideoEncoder P${this.options.slot || '?'}] Spawning FFmpeg: ${this.ffmpegPath}`);
        
        try {
            this.ffmpeg = spawn(this.ffmpegPath, args, { windowsHide: true });
            this.isActive = true;

            // Set encoder priority lower to ensure mGBA isn't starved
            try {
                const os = require('os');
                os.setPriority(this.ffmpeg.pid, os.constants.priority.PRIORITY_BELOW_NORMAL);
            } catch (e) {}

            this.ffmpeg.on('error', (err) => {
                console.error(`[VideoEncoder P${this.options.slot || '?'}] Spawn error:`, err.message);
                this.isActive = false;
            });

            this.ffmpeg.stdout.on('data', (data) => {
                this.handleEncodedData(data);
            });

            this.ffmpeg.stderr.on('data', (data) => {
                // Keep an eye on internal FFmpeg errors
                const msg = data.toString();
                if (msg.includes('Error')) console.error(`[FFmpeg P${this.options.slot || '?'}] ${msg.trim()}`);
            });

            this.ffmpeg.on('close', (code) => {
                console.log(`[VideoEncoder P${this.options.slot || '?'}] FFmpeg exited with code ${code}`);
                this.isActive = false;
            });

            // Prevent stdin errors from crashing the server
            this.ffmpeg.stdin.on('error', (e) => {
                if (e.code !== 'EPIPE') console.error('[VideoEncoder] Stdin Error:', e);
            });

        } catch (e) {
            console.error(`[VideoEncoder P${this.options.slot || '?'}] Spawn exception:`, e);
            this.isActive = false;
        }
    }

    /**
     * Feed raw pixels into the encoder.
     */
    write(pixels) {
        if (!this.isActive || !this.ffmpeg) return true;
        try {
            return this.ffmpeg.stdin.write(pixels);
        } catch (e) {
            console.error('[VideoEncoder] Error writing to FFmpeg stdin:', e);
            return false;
        }
    }

    /**
     * Handle the output stream of encoded MJPEG images.
     */
    handleEncodedData(chunk) {
        if (!chunk) return;

        // Copy chunk into our parsing buffer
        if (this.dataOffset + chunk.length > this.buffer.length) {
            this.dataOffset = 0; // Wipe on overflow (shouldn't happen with 2MB for MJPEG)
        }
        chunk.copy(this.buffer, this.dataOffset);
        this.dataOffset += chunk.length;

        let searchStart = 0;
        while (this.dataOffset > 4) {
            const startIdx = this.buffer.indexOf(this.SOI, searchStart);
            if (startIdx === -1 || startIdx > this.dataOffset - 2) break;

            const endIdx = this.buffer.indexOf(this.EOI, startIdx + 2);
            if (endIdx === -1 || endIdx > this.dataOffset - 2) {
                // Keep the partial frame for next chunk
                if (startIdx > 0) {
                    this.buffer.copy(this.buffer, 0, startIdx, this.dataOffset);
                    this.dataOffset -= startIdx;
                }
                break;
            }

            const frameSize = (endIdx - startIdx) + 2;
            const frame = Buffer.allocUnsafe(frameSize);
            this.buffer.copy(frame, 0, startIdx, endIdx + 2);

            this.emittedCount++;
            this.emit('frame', frame);

            // Shift buffer
            const remaining = this.dataOffset - (endIdx + 2);
            if (remaining > 0) {
                this.buffer.copy(this.buffer, 0, endIdx + 2, this.dataOffset);
                this.dataOffset = remaining;
                searchStart = 0;
            } else {
                this.dataOffset = 0;
                break;
            }
        }
    }

    stop() {
        if (this.ffmpeg) {
            this.ffmpeg.kill('SIGKILL');
            this.ffmpeg = null;
        }
        this.isActive = false;
        this.buffer = Buffer.alloc(0);
    }
}

module.exports = VideoEncoder;
