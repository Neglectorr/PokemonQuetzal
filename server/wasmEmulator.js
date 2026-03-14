const puppeteer = require('puppeteer');
const EventEmitter = require('events');
const fs = require('fs');
const path = require('path');

class WasmEmulator extends EventEmitter {
    constructor(roomId, slot = 0, maxPlayers = 4) {
        super();
        this.roomId = roomId;
        this.slot = slot;
        this.playerId = `${roomId}_${slot}`;
        this.maxPlayers = maxPlayers;
        this.browser = null;
        this.page = null;
        this.isReady = false;
        this.gameLoaded = false;
        
        // Link Hub Integration
        this.linkHub = require('./wasmLinkHub');
    }

    async start(romPath) {
        console.log(`[WasmCore ${this.roomId}] Initializing Isolated Headless Instance (Slot ${this.slot})...`);
        this.linkHub.join(this.playerId);
        
        try {
            this.browser = await puppeteer.launch({
                headless: true,
                args: [
                    '--no-sandbox', 
                    '--disable-setuid-sandbox',
                    '--disable-dev-shm-usage',
                    '--disable-accelerated-2d-canvas',
                    '--no-first-run',
                    '--mute-audio',
                    '--enable-features=SharedArrayBuffer',
                    '--disable-background-timer-throttling',
                    '--disable-backgrounding-occluded-windows',
                    '--disable-renderer-backgrounding',
                    '--js-flags="--max-old-space-size=4096"'
                ]
            });

            this.page = await this.browser.newPage();
            
            // Critical Pipe for Pixel Data
            await this.page.exposeFunction('onPixels', (dataUrl) => {
                const base64Data = dataUrl.split(',')[1];
                if (base64Data) {
                    this.emit('frame', Buffer.from(base64Data, 'base64'));
                }
            });

            // SIO Link Cable Pipe
            await this.page.exposeFunction('onSioTransfer', (data) => {
                // console.log(`[WasmCore ${this.roomId} SIO] Slot ${this.slot} sending ${data}`);
                this.linkHub.signalReady(this.playerId, data);
            });

            // Listen for sync results from hub (Room Broadcast)
            this.linkHub.on(`sync-all:${this.roomId}`, (allData) => {
                if (this.page) {
                    this.page.evaluate((data) => {
                        if (window.setSioData) window.setSioData(data);
                    }, allData).catch(e => {});
                }
            });

            // Mirror console for real-time diagnostics
            this.page.on('console', msg => {
                const text = msg.text();
                // Check for life signals
                if (text === 'WASM_READY') {
                    this.isReady = true;
                    console.log(`[WasmCore ${this.roomId}] Engine READY Signal Received.`);
                } else if (text === 'GAME_STARTED') {
                    this.gameLoaded = true;
                    console.log(`[WasmCore ${this.roomId}] ROM Successfully Booted.`);
                } else if (text.includes('HEARTBEAT_PUMP')) {
                    // console.log(`[WasmCore ${this.roomId}] Heartbeat: Active`);
                } else {
                    console.log(`[WasmCore ${this.roomId} LOG]: ${text}`);
                }
            });

            this.page.on('pageerror', err => {
                console.error(`[WasmCore ${this.roomId} CRITICAL_PAGE_ERROR]:`, err.message);
                this.emit('error', err.message);
            });

            // Target the local headless host
            console.log(`[WasmCore ${this.roomId}] Navigating to bridge...`);
            await this.page.goto('http://127.0.0.1:3000/wasm-headless.html', {
                waitUntil: 'networkidle2',
                timeout: 30000
            });
            
            // Wait for Engine Startup
            let waitCount = 0;
            while(!this.isReady && waitCount < 150) { // 30s max wait for WASM compile/init
                await new Promise(r => setTimeout(r, 200));
                waitCount++;
            }

            if (!this.isReady) {
                const title = await this.page.title();
                console.error(`[WasmCore ${this.roomId}] BOOT_TIMEOUT: Final title was "${title}"`);
                throw new Error(`WASM Engine timed out. Page state: ${title}`);
            }

            console.log(`[WasmCore ${this.roomId}] Proceeding to ROM Fetch Phase...`);
            const romFilename = path.basename(romPath);
            
            await this.page.evaluate(async (filename) => {
                try {
                    console.log(`WASM_LOAD_ROM_FETCH_START: ${filename}`);
                    const res = await fetch(`/roms-internal/${filename}`);
                    if (!res.ok) throw new Error(`HTTP ${res.status} while fetching ROM`);
                    
                    const buf = await res.arrayBuffer();
                    const uint8 = new Uint8Array(buf);
                    console.log(`WASM_ROM_FETCH_COMPLETE: ${uint8.length} bytes`);
                    
                    window.mgba.FS.writeFile('/data/game.gba', uint8);
                    const success = window.mgba.loadGame('/data/game.gba');
                    console.log(`WASM_LOAD_RESULT: ${success}`);
                    
                    if (success) {
                        window.mgba.resumeGame();
                        if (window.mgba.setMainLoopTiming) {
                            // Mode 0 = setTimeout, 60fps = 100% speed
                            window.mgba.setMainLoopTiming(0, 60); 
                            console.log("WASM_TIMING_FORCED_SETTIMEOUT_60");
                        }
                        console.log("GAME_STARTED");
                    } else {
                        console.error("WASM_LOAD_FAILURE: loadGame returned false");
                    }
                } catch (e) {
                    console.error("WASM_LOAD_ROM_ERROR:", e.message);
                }
            }, romFilename);

            console.log(`[WasmCore ${this.roomId}] Session Fully Active.`);
        } catch (err) {
            console.error(`[WasmCore ${this.roomId}] BOOT_FAILURE:`, err.message);
            if (this.browser) await this.browser.close();
            throw err;
        }
    }

    async sendInput(button, isPressed) {
        if (!this.page || !this.isReady) return;
        await this.page.evaluate((btnIdx, pressed) => {
            if (window.mgba && window.GBA_KEYS) {
                const key = window.GBA_KEYS[btnIdx];
                if (key) {
                    if (pressed) window.mgba.buttonPress(key);
                    else window.mgba.buttonUnpress(key);
                }
            }
        }, button, isPressed);
    }

    async syncInput(bitmask) {
        if (!this.page || !this.isReady) return;
        // Optimization: Handle the entire state on the headless page
        await this.page.evaluate((mask) => {
            if (window.mgba && window.GBA_KEYS) {
                for (let i = 0; i < window.GBA_KEYS.length; i++) {
                    const key = window.GBA_KEYS[i];
                    if (mask & (1 << i)) {
                        window.mgba.buttonPress(key);
                    } else {
                        window.mgba.buttonUnpress(key);
                    }
                }
            }
        }, bitmask);
    }

    async stop() {
        if (this.browser) {
            try {
                await this.browser.close();
            } catch (err) {
                console.error(`[WasmCore ${this.roomId}] Close Error:`, err);
            }
        }
        this.isReady = false;
        this.gameLoaded = false;
        this.page = null;
        this.browser = null;
    }
}

module.exports = WasmEmulator;
