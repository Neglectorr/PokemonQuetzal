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
        this.width = options.width || 240;
        this.height = options.height || 160;
        this.fps = options.fps || 60;
        
        // Detect FFmpeg path from available locations
        this.ffmpegPath = options.ffmpegPath || this.findFFmpeg();
        
        this.ffmpeg = null;
        this.isActive = false;
        this.buffer = Buffer.alloc(0);
        this.frameSize = this.width * this.height * 4; // RGBA
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

        // Command: Read raw BGRA pixels from stdin, output individual WebP images to stdout
        // -q:v 60 provides a good balance of quality vs size (~3KB per frame)
        const args = [
            '-f', 'rawvideo',
            '-pixel_format', 'bgra',
            '-video_size', `${this.width}x${this.height}`,
            '-i', '-',
            '-f', 'image2pipe',
            '-vcodec', 'webp',
            '-lossless', '0',
            '-compression_level', '4',
            '-q:v', '60',
            '-'
        ];

        if (!this.ffmpegPath) {
            console.error('[VideoEncoder] No FFmpeg found on system. Disabling compression.');
            return;
        }

        console.log(`[VideoEncoder] Starting FFmpeg: ${this.ffmpegPath}`);
        
        try {
            this.ffmpeg = spawn(this.ffmpegPath, args);
            this.isActive = true;

            this.ffmpeg.on('error', (err) => {
                console.error(`[VideoEncoder] FFmpeg failed to start:`, err.message);
                this.isActive = false;
                this.emit('error', err);
            });
        } catch (e) {
            console.error(`[VideoEncoder] Fatal spawn error:`, e);
            this.isActive = false;
            return;
        }

        this.ffmpeg.stdout.on('data', (data) => {
            this.handleEncodedData(data);
        });

        this.ffmpeg.stderr.on('data', (data) => {
            // Un-comment for debugging
            // console.log(`[FFmpeg Debug]: ${data}`);
        });

        this.ffmpeg.on('close', (code) => {
            console.log(`[VideoEncoder] FFmpeg closed with code ${code}`);
            this.isActive = false;
        });
    }

    /**
     * Feed raw pixels into the encoder.
     */
    write(pixels) {
        if (!this.isActive || !this.ffmpeg) return;
        try {
            this.ffmpeg.stdin.write(pixels);
        } catch (e) {
            console.error('[VideoEncoder] Error writing to FFmpeg stdin:', e);
        }
    }

    /**
     * Handle the output stream of encoded WebP images.
     * WebP files start with 'RIFF' and have a size header.
     */
    handleEncodedData(chunk) {
        this.buffer = Buffer.concat([this.buffer, chunk]);

        while (this.buffer.length > 12) {
            // RIFF header
            if (this.buffer.toString('ascii', 0, 4) !== 'RIFF') {
                // Out of sync? Scan for next RIFF
                const nextRIFF = this.buffer.indexOf('RIFF', 1);
                if (nextRIFF === -1) {
                    this.buffer = Buffer.alloc(0);
                    break;
                }
                this.buffer = this.buffer.slice(nextRIFF);
                continue;
            }

            // WebP total size is at offset 4 (4 bytes, little endian)
            // The value is (fileSize - 8)
            const webpSize = this.buffer.readUInt32LE(4) + 8;
            
            if (this.buffer.length >= webpSize) {
                const frame = this.buffer.slice(0, webpSize);
                this.buffer = this.buffer.slice(webpSize);
                this.emit('frame', frame);
            } else {
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
