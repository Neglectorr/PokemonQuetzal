const puppeteer = require('puppeteer');
const EventEmitter = require('events');
const fs = require('fs');

class WasmEmulator extends EventEmitter {
    constructor(roomId, maxPlayers = 4) {
        super();
        this.roomId = roomId;
        this.maxPlayers = maxPlayers;
        this.browser = null;
        this.page = null;
        this.isReady = false;
    }

    async start(romPath) {
        console.log(`[WasmCore ${this.roomId}] Initializing Next-Gen Engine...`);
        
        this.browser = await puppeteer.launch({
            headless: true,
            args: ['--no-sandbox', '--disable-setuid-sandbox']
        });

        this.page = await this.browser.newPage();
        
        // The "Secret Sauce": A headless page that runs the WASM core
        const html = `
            <!DOCTYPE html>
            <html>
            <body>
                <canvas id="c" width="240" height="160"></canvas>
                <script type="module">
                    import mGBA from 'https://unpkg.com/@thenick775/mgba-wasm@2.4.1/dist/mgba.js';
                    
                    async function init() {
                        const canvas = document.getElementById('c');
                        const module = await mGBA({ canvas });
                        await module.FSInit();
                        window.mgba = module;
                        console.log("WASM_READY");
                        
                        // Pixel pusher - RGBA format
                        setInterval(() => {
                            const ctx = canvas.getContext('2d');
                            const imageData = ctx.getImageData(0, 0, 240, 160);
                            window.onPixels(Array.from(imageData.data));
                        }, 33);
                    }
                    init();
                </script>
            </body>
            </html>
        `;

        await this.page.exposeFunction('onPixels', (pixels) => {
            if (this.isReady) {
                this.emit('frame', Buffer.from(pixels));
            }
        });

        this.page.on('console', msg => {
            if (msg.text() === 'WASM_READY') this.isReady = true;
            if (msg.text() !== 'WASM_READY') console.log(`[WasmCore LOG]`, msg.text());
        });

        await this.page.setContent(html);
        
        // Wait for core
        let timeout = 0;
        while(!this.isReady && timeout < 100) {
            await new Promise(r => setTimeout(r, 100));
            timeout++;
        }

        if (!this.isReady) throw new Error("WASM Core failed to signal READY");

        // Load ROM
        console.log(`[WasmCore ${this.roomId}] Injecting ROM...`);
        const romB64 = fs.readFileSync(romPath).toString('base64');
        await this.page.evaluate(async (b64) => {
            const res = await fetch(`data:application/octet-stream;base64,${b64}`);
            const buf = await res.arrayBuffer();
            window.mgba.FS.writeFile('/data/game.gba', new Uint8Array(buf));
            window.mgba.loadGame('/data/game.gba');
            window.mgba.resumeGame();
        }, romB64);

        console.log(`[WasmCore ${this.roomId}] Engine Heartbeat Detected!`);
    }

    async sendInput(button, isPressed) {
        if (!this.page || !this.isReady) return;
        await this.page.evaluate((btn, pressed) => {
            if (window.mgba) {
                if (pressed) window.mgba.buttonPress(btn);
                else window.mgba.buttonUnpress(btn);
            }
        }, button, isPressed);
    }

    async stop() {
        if (this.browser) await this.browser.close();
        this.isReady = false;
        this.page = null;
        this.browser = null;
    }
}

module.exports = WasmEmulator;
