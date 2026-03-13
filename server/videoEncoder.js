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
        this.buffer = Buffer.alloc(0);
        this.frameSize = this.width * this.height * 4; // RGBA
        this.emittedCount = 0;
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
        this.buffer = this.buffer.length ? Buffer.concat([this.buffer, chunk]) : chunk;

        // Skip manual parsing if possible, but for MJPEG we need to find boundaries
        while (this.buffer.length > 4) {
            const startIdx = this.buffer.indexOf(Buffer.from([0xFF, 0xD8]));
            if (startIdx === -1) {
                this.buffer = this.buffer.slice(Math.max(0, this.buffer.length - 1));
                break;
            }

            if (startIdx > 0) {
                this.buffer = this.buffer.slice(startIdx);
            }

            const endIdx = this.buffer.indexOf(Buffer.from([0xFF, 0xD9]));
            if (endIdx === -1) break;

            const frameSize = endIdx + 2;
            const frame = this.buffer.slice(0, frameSize);
            
            // Slice the buffer BEFORE emitting to avoid re-concats if emission is slow
            this.buffer = this.buffer.slice(frameSize);

            this.emittedCount++;
            if (this.emittedCount % 300 === 0) {
                console.log(`[VideoEncoder P${this.options.slot || '?'}] Stream health OK: ${this.emittedCount} frames.`);
            }
            this.emit('frame', frame);
            
            // Limit loop to prevent long-running blocking
            if (this.emittedCount % 60 === 0) break; 
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
