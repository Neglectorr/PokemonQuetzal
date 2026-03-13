const { spawn } = require('child_process');
const path = require('path');
const fs = require('fs');

class EmulatorInstance {
    constructor(roomId, maxPlayers, onFrame, onAudio, onReady, onError) {
        this.roomId = roomId;
        this.maxPlayers = maxPlayers || 4;
        this.onFrame = onFrame;
        this.onAudio = onAudio;
        this.onReady = onReady;
        this.onError = onError;

        this.mGBAProcess = null;
        this.wrapperProcess = null;
        this.state = 'initializing';
        
        // Track which user is in which slot for save syncing
        this.slots = {}; // { slot: { userId, romBase } }
        
        // Input state mapping to check changes
        this.lastButtons = { 1: 0, 2: 0, 3: 0, 4: 0 };
        this.BUTTON_NAMES = [
            { mask: 0x001, name: 'A' },
            { mask: 0x002, name: 'B' },
            { mask: 0x004, name: 'Select' },
            { mask: 0x008, name: 'Start' },
            { mask: 0x010, name: 'Right' },
            { mask: 0x020, name: 'Left' },
            { mask: 0x040, name: 'Up' },
            { mask: 0x080, name: 'Down' },
            { mask: 0x100, name: 'R' },
            { mask: 0x200, name: 'L' }
        ];
    }

    async loadRom(romFilename, players = []) {
        const mgbaExe = path.join(__dirname, '..', 'mgba_native', 'mGBA-custom', 'mGBA.exe');
        if (!fs.existsSync(mgbaExe)) {
            const err = 'Custom mGBA.exe not found.';
            console.error(`[Room ${this.roomId}]`, err);
            if (this.onError) this.onError(err);
            return false;
        }

        const romPath = path.join(__dirname, '..', 'roms', romFilename);
        if (!fs.existsSync(romPath)) {
            const err = `ROM not found: ${romPath}`;
            console.error(`[Room ${this.roomId}]`, err);
            if (this.onError) this.onError(err);
            return false;
        }

        const LOBBIES_DIR = path.join(__dirname, '..', 'lobbies');
        const lobbyDir = path.join(LOBBIES_DIR, this.roomId);
        if (!fs.existsSync(lobbyDir)) fs.mkdirSync(lobbyDir, { recursive: true });

        const pipeBase = `streamer_${this.roomId}`;
        this.pipeBridges = [];
        this.lastRomBase = romFilename.replace(/\.gba$/i, ''); 

        // 1. Prepare per-player saves in the lobby directory
        for (let slot = 1; slot <= this.maxPlayers; slot++) {
            const player = players.find(p => p.slot === slot);
            if (player) {
                this.syncUserSaveToSlot(slot, player.userId, this.lastRomBase, lobbyDir);
            }

            // Setup Pipe Bridge for this slot
            const PipeBridge = require('./pipeBridge');
            const bridge = new PipeBridge(`${pipeBase}_${slot-1}`, slot);
            bridge.on('video', (data) => {
                if (this.onFrame) {
                    // Send raw RGBA buffer to sockets.js
                    this.onFrame(slot, data.data, data.width, data.height);
                }
            });
            bridge.on('audio', (payload) => {
                if (this.onAudio) this.onAudio(slot, payload);
            });
            bridge.connect();
            this.pipeBridges.push(bridge);
        }

        console.log(`[Room ${this.roomId}] Launching truly headless mGBA...`);
        
        // 2. Launch mGBA with -platform offscreen for Session 0 compatibility.
        // We use dummy audio and disable sync to video/audio to let the pipe handle timing.
        // Passing the ROM once - mGBA -m replicates it internally.
        const mgbaArgs = [
            '-platform', 'offscreen',
            '-m', this.maxPlayers.toString(), 
            '-C', 'audio.driver=dummy',
            '-C', 'qt.displayDriver=0', // Force Software rendering
            '-C', 'syncToVideo=0',
            '-C', 'syncToAudio=1',     // Sync to Dummy audio (timed consuming) for stable clocks
            '--stream-pipe', pipeBase, 
            '--sav-path', lobbyDir,
            romPath
        ];

        this.mGBAProcess = spawn(mgbaExe, mgbaArgs, {
            cwd: lobbyDir,
            stdio: ['pipe', 'pipe', 'pipe'], // Open stdin for future direct control
            env: { ...process.env, QT_QPA_PLATFORM: 'offscreen' }
        });
        
        console.log(`[Room ${this.roomId}] mGBA spawned with PID: ${this.mGBAProcess.pid} (Offscreen)`);

        this.mGBAProcess.stdout.on('data', (data) => console.log(`[mGBA ${this.roomId}]`, data.toString().trim()));
        this.mGBAProcess.stderr.on('data', (data) => {
            const msg = data.toString().trim();
            if (msg.includes('error') || msg.includes('failed')) {
                console.error(`[mGBA ${this.roomId} ERR]`, msg);
            }
        });
        
        this.mGBAProcess.on('exit', (code) => {
            console.log(`[Room ${this.roomId}] mGBA process exited with code`, code);
            this.kill();
        });

        this.state = 'playing';
        
        // 3. Spawn Input Proxy after a short delay for windows to be created
        setTimeout(() => {
            const proxyScript = path.join(__dirname, 'input_proxy.py');
            this.inputProxy = spawn('python', ['-u', proxyScript, this.mGBAProcess.pid.toString(), this.maxPlayers.toString()], {
                stdio: ['pipe', 'pipe', 'pipe']
            });
            this.inputProxy.stdout.on('data', (data) => console.log(`[InputProxy ${this.roomId}]`, data.toString().trim()));
            this.inputProxy.stderr.on('data', (data) => console.error(`[InputProxy ${this.roomId} ERR]`, data.toString().trim()));
        }, 5000);

        // Auto-load save states for assigned slots after a delay
        setTimeout(() => {
            for (const slot of Object.keys(this.slots)) {
                this.quickLoad(parseInt(slot));
            }
        }, 8000); 

        if (this.onReady) this.onReady();
        return true;
    }
    getSlotSaveExtensions(slot) {
        // mGBA Multiplayer: P1 uses .sav, P2 uses .sa2, P3 uses .sa3, P4 uses .sa4
        if (slot === 1) return ['.sav'];
        return [`.sa${slot}`, '.sav']; // Check .saX first, then .sav as fallback
    }

    syncUserSaveToSlot(slot, userId, romBase, lobbyDir) {
        const SAVES_ROOT = path.join(__dirname, '..', 'saves');
        
        this.slots[slot] = { userId, romBase }; // Original ROM name for user dir

        try {
            const userDir = path.join(SAVES_ROOT, userId);
            if (!fs.existsSync(userDir)) fs.mkdirSync(userDir, { recursive: true });

            const userSave = path.join(userDir, `${romBase}.sav`);
            const userState = path.join(userDir, `${romBase}.state`);

            if (fs.existsSync(userSave)) {
                // Determine target suffix (.sav, .sa2, etc.) in the lobbyDir
                const ext = slot === 1 ? '.sav' : `.sa${slot}`;
                const targetPath = path.join(lobbyDir, `${romBase}${ext}`);
                fs.copyFileSync(userSave, targetPath);
                console.log(`[Room ${this.roomId}] Syncing SRAM for P${slot} (${userId}) -> ${ext}`);
            }

            // state sync is lobby-specific for now
            const pStatePath = path.join(lobbyDir, `${romBase}.ss1`);
            if (fs.existsSync(userState) && slot === 1) { 
                fs.copyFileSync(userState, pStatePath);
                console.log(`[Room ${this.roomId}] Syncing State for P${slot} (${userId})`);
            }
        } catch (e) {
            console.error(`[Room ${this.roomId}] Sync failed for P${slot}:`, e);
        }
    }


    async syncSavesBack(targetSlot = null) {
        const SAVES_ROOT = path.join(__dirname, '..', 'saves');
        const LOBBIES_DIR = path.join(__dirname, '..', 'lobbies');
        const lobbyDir = path.join(LOBBIES_DIR, this.roomId);

        if (!fs.existsSync(lobbyDir)) return;

        const slotsToSync = targetSlot ? [[targetSlot, this.slots[targetSlot]]] : Object.entries(this.slots);

        for (const [slotStr, data] of slotsToSync) {
            const slot = parseInt(slotStr);
            if (!data) continue;
            const { userId, romBase } = data; 
            
            // mGBA Suffixes in lobbyDir
            const ext = slot === 1 ? '.sav' : `.sa${slot}`;
            const pSavePath = path.join(lobbyDir, `${romBase}${ext}`);
            const pStatePath = path.join(lobbyDir, `${romBase}.ss1`);
            
            const userDir = path.join(SAVES_ROOT, userId);
            const userSave = path.join(userDir, `${romBase}.sav`);
            const userState = path.join(userDir, `${romBase}.state`);

            try {
                if (fs.existsSync(pSavePath)) {
                    const stats = fs.statSync(pSavePath);
                    if (stats.size > 0) {
                        fs.copyFileSync(pSavePath, userSave);
                        console.log(`[Room ${this.roomId}] Synced SRAM back for P${slot} (${userId})`);
                    }
                }
                
                if (slot === 1 && fs.existsSync(pStatePath)) {
                    const stats = fs.statSync(pStatePath);
                    if (stats.size > 10000) {
                        fs.copyFileSync(pStatePath, userState);
                        console.log(`[Room ${this.roomId}] Synced State back for P${slot} (${userId})`);
                    }
                }
            } catch (e) {
                console.error(`[Room ${this.roomId}] Sync back failed for ${userId}:`, e);
            }
        }
        
        // Final cleanup on room destruction
        if (!targetSlot) {
            console.log(`[Room ${this.roomId}] Cleaning up lobby directory...`);
            const LOBBIES_DIR = path.join(__dirname, '..', 'lobbies');
            const lobbyDir = path.join(LOBBIES_DIR, this.roomId);
            if (fs.existsSync(lobbyDir)) {
                try {
                    fs.rmSync(lobbyDir, { recursive: true, force: true });
                } catch (e) {
                    console.error(`[Room ${this.roomId}] Cleanup failed:`, e.message);
                }
            }
        }
    }

    async handlePlayerLeave(slot) {
        if (!this.slots[slot]) return;
        console.log(`[Room ${this.roomId}] Player left slot ${slot}. Saving progress...`);
        
        // 1. Initial Quick Save
        this.quickSave(slot);
        
        // 2. Wait for file write
        await new Promise(r => setTimeout(r, 1500));
        
        // 3. Sync that specific slot back
        await this.syncSavesBack(slot);
        
        // 4. Remove from active slots so we don't sync it again later
        delete this.slots[slot];
    }

    sendInput(slot, buttons) {
        if (!this.inputProxy || this.state !== 'playing') return;

        for (const { mask, name } of this.BUTTON_NAMES) {
            const nowPressed = (buttons    & mask) !== 0;
            const wasPressed = (this.lastButtons[slot] & mask) !== 0;

            if (nowPressed && !wasPressed) {
                this.inputProxy.stdin.write(`${slot},${name},1\n`);
            } else if (!nowPressed && wasPressed) {
                this.inputProxy.stdin.write(`${slot},${name},0\n`);
            }
        }
        this.lastButtons[slot] = buttons;
    }

    quickSave(slot) {
        if (!this.inputProxy) return;
        console.log(`[Room ${this.roomId}] Triggering Quick Save for slot ${slot}`);
        this.inputProxy.stdin.write(`${slot},Shift,1\n`);
        this.inputProxy.stdin.write(`${slot},F1,1\n`);
        setTimeout(() => {
            this.inputProxy.stdin.write(`${slot},F1,0\n`);
            this.inputProxy.stdin.write(`${slot},Shift,0\n`);
        }, 100);
    }

    quickLoad(slot) {
        if (!this.inputProxy) return;
        console.log(`[Room ${this.roomId}] Triggering Quick Load for slot ${slot}`);
        this.inputProxy.stdin.write(`${slot},F1,1\n`);
        setTimeout(() => {
            this.inputProxy.stdin.write(`${slot},F1,0\n`);
        }, 100);
    }

    async kill() {
        if (this.state === 'dead') return;
        this.state = 'dead';

        // 1. Trigger Quick Save for all ACTIVE slots
        for (const slot of Object.keys(this.slots)) {
            this.quickSave(parseInt(slot));
        }

        // 2. Wait for saves to write to disk
        await new Promise(r => setTimeout(r, 2000));

        // 3. Sync files back
        await this.syncSavesBack();

        if (this.pipeBridges) {
            this.pipeBridges.forEach(b => b.close());
            this.pipeBridges = [];
        }

        if (this.inputProxy) {
            this.inputProxy.kill('SIGINT');
            this.inputProxy = null;
        }
        if (this.mGBAProcess) {
            this.mGBAProcess.kill('SIGINT');
            this.mGBAProcess = null;
        }
        console.log(`[Room ${this.roomId}] Emulator stalled and synced.`);
    }
}

module.exports = EmulatorInstance;
