const puppeteer = require('puppeteer');
const EventEmitter = require('events');

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
                        
                        // Pixel pusher
                        setInterval(() => {
                            const ctx = canvas.getContext('2d');
                            const data = ctx.getImageData(0, 0, 240, 160).data;
                            window.onPixels(Array.from(data));
                        }, 33); // 30 FPS stream
                    }
                    init();
                </script>
            </body>
            </html>
        `;

        await this.page.exposeFunction('onPixels', (pixels) => {
            this.emit('frame', Buffer.from(pixels));
        });

        this.page.on('console', msg => {
            if (msg.text() === 'WASM_READY') this.isReady = true;
            console.log(`[WasmCore LOG]`, msg.text());
        });

        await this.page.setContent(html);
        
        // Wait for ready
        while(!this.isReady) await new Promise(r => setTimeout(r, 100));

        // Load ROM
        const fs = require('fs');
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

    async stop() {
        if (this.browser) await this.browser.close();
    }
}

module.exports = WasmEmulator;
