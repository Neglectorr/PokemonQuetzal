const { spawn } = require('child_process');
const path = require('path');
const fs = require('fs');
const os = require('os');
const rootDir = path.resolve(__dirname, '..');
const LOBBIES_DIR = path.join(rootDir, 'lobbies');
const SAVES_ROOT = path.join(rootDir, 'saves');

class EmulatorInstance {
    constructor(roomId, maxPlayers, onFrame, onAudio, onReady, onError, onProgress) {
        this.roomId = roomId;
        this.maxPlayers = maxPlayers || 4;
        this.onFrame = onFrame;
        this.onAudio = onAudio;
        this.onReady = onReady;
        this.onError = onError;
        this.onProgress = onProgress;

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
        const mgbaExe = path.resolve(rootDir, 'mgba_native', 'mGBA-custom', 'mGBA.exe');
        console.log(`[Emulator] Resolved mGBA path: ${mgbaExe}`);
        
        if (!fs.existsSync(mgbaExe)) {
            const err = `Custom mGBA.exe NOT FOUND at: ${mgbaExe}`;
            console.error(`[Room ${this.roomId}]`, err);
            if (this.onError) this.onError(err);
            return false;
        }

        const romPath = path.resolve(rootDir, 'roms', romFilename);
        console.log(`[Emulator] Loading ROM: ${romPath}`);
        
        if (!fs.existsSync(romPath)) {
            const err = `ROM NOT FOUND at: ${romPath}`;
            console.error(`[Room ${this.roomId}]`, err);
            if (this.onError) this.onError(err);
            return false;
        }

        const lobbyDir = path.join(LOBBIES_DIR, this.roomId);
        if (!fs.existsSync(lobbyDir)) fs.mkdirSync(lobbyDir, { recursive: true });

        this.lastRomBase = romFilename.replace(/\.gba$/i, ''); 

        // 1. Prepare per-player saves in the lobby directory
        for (let slot = 1; slot <= this.maxPlayers; slot++) {
            const player = players.find(p => p.slot === slot);
            if (player) {
                this.syncUserSaveToSlot(slot, player.userId, this.lastRomBase, lobbyDir);
            }
        }

        console.log(`[Room ${this.roomId}] Launching truly headless mGBA...`);
        
        const mgbaArgs = [
            '-m', this.maxPlayers.toString(), 
            '-C', 'ports.qt.videoBackend=opengl',
            '-C', 'pauseOnFocusLost=0',
            '-C', 'muteOnFocusLost=0',
            '-C', 'syncToVideo=0',
            '-C', 'syncToAudio=0',
            '-C', 'limitSpeed=1',
            '-C', 'unlimited=0',
            '-C', 'audio.bufferSamples=2048',
            '-C', 'fpsTarget=60',
            '-C', 'frameskip=0',
            '--sav-path', lobbyDir,
            romPath
        ];

        // Set Node process priority to HIGH to ensure smooth Ring Buffer handling
        try {
            const osPriority = require('os');
            osPriority.setPriority(process.pid, osPriority.constants.priority.PRIORITY_HIGH);
        } catch (e) {}

        this.mGBAProcess = spawn(mgbaExe, mgbaArgs, {
            cwd: lobbyDir,
            stdio: ['ignore', 'ignore', 'pipe'], // Capture stderr only
            env: { 
                ...process.env,
            },
            windowsHide: false
        });

        this.mGBAProcess.stderr.on('data', (data) => {
            console.error(`[mGBA ERR ${this.roomId}]`, data.toString().trim());
        });
        
        // No drainage needed for 'ignore'

        // ⚡ CRITICAL: Disable Windows Efficiency Mode / Power Throttling
        // This is what was causing the 10.1 FPS cap in background mode.
        const fixScript = path.join(__dirname, 'fix_throttling.py');
        spawn('python', [fixScript, this.mGBAProcess.pid], { stdio: 'inherit' });
        
        // Use High Priority to ensure stable clockspeed on Server
        try {
            const osConstants = require('os').constants;
            os.setPriority(this.mGBAProcess.pid, osConstants.priority.PRIORITY_ABOVE_NORMAL);
        } catch (e) {
            console.warn(`[Room ${this.roomId}] Could not set process priority:`, e.message);
        }

        this.mGBAProcess.on('error', (err) => {
            console.error(`[Room ${this.roomId}] FAILED to spawn mGBA process:`, err);
            if (this.onError) this.onError(`Process spawn error: ${err.message}`);
        });
        
        console.log(`[Room ${this.roomId}] mGBA spawned with PID: ${this.mGBAProcess.pid}`);
        
        if (this.onProgress) this.onProgress(20, 'Spawning mGBA core...');
        this.state = 'playing';
        
        // 3. Spawn Input Proxy after a short delay for windows to be created
        const proxyStart = Date.now();
        const proxyDelay = 12000;
        
        this.progressTimer = setInterval(() => {
            if (!this.onProgress) return;
            const elapsed = Date.now() - proxyStart;
            const percent = 20 + Math.min(60, (elapsed / proxyDelay) * 60);
            this.onProgress(Math.floor(percent), 'Initializing input proxy...');
        }, 1000);

        this.proxyTimeout = setTimeout(() => {
            if (this.progressTimer) clearInterval(this.progressTimer);
            if (this.onProgress) this.onProgress(90, 'Finalizing connection...');
            
            if (!this.mGBAProcess || this.state === 'dead') return;
            
            const wrapperScript = path.resolve(__dirname, 'wrapper.py');
            if (!fs.existsSync(wrapperScript)) {
                console.error(`[Room ${this.roomId}] Wrapper script NOT FOUND at ${wrapperScript}`);
                return;
            }

            console.log(`[Room ${this.roomId}] Spawning Wrapper for PID ${this.mGBAProcess.pid}...`);
            this.inputProxy = spawn('python', ['-u', wrapperScript, this.mGBAProcess.pid.toString(), this.maxPlayers.toString()], {
                stdio: ['pipe', 'pipe', 'pipe']
            });

            // Binary parser for wrapper output: [Slot (1b)][Size (4b LE)][PNG Data]
            let buffer = Buffer.alloc(0);
            this.inputProxy.stdout.on('data', (chunk) => {
                buffer = Buffer.concat([buffer, chunk]);
                
                while (buffer.length >= 5) {
                    const slot = buffer[0];
                    const size = buffer.readUInt32LE(1);
                    
                    if (buffer.length < 5 + size) break;
                    
                    const frameData = buffer.slice(5, 5 + size);
                    if (this.onFrame) {
                        this.onFrame(slot, frameData, 240, 160, 'png'); // label as png
                    }
                    
                    buffer = buffer.slice(5 + size);
                }
            });

            this.inputProxy.stderr.on('data', (data) => console.error(`[Wrapper ${this.roomId} ERR]`, data.toString().trim()));
            
            this.inputProxy.on('error', (err) => {
                console.error(`[Room ${this.roomId}] FAILED to spawn Wrapper:`, err.message);
            });
        }, 12000); // 12s delay for Session 0 window creation

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
    syncUserSaveToSlot(slot, userId, romBase, lobbyDir = null) {
        if (!romBase) {
            console.error(`[Room ${this.roomId}] Cannot sync save: romBase is undefined`);
            return;
        }
        if (!lobbyDir) lobbyDir = path.join(LOBBIES_DIR, this.roomId);
        
        // Ensure romBase doesn't have .gba extension
        const cleanRomBase = romBase.replace(/\.gba$/i, '');
        this.slots[slot] = { userId, romBase: cleanRomBase }; 

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

        if (this.proxyTimeout) clearTimeout(this.proxyTimeout);
        if (this.progressTimer) clearInterval(this.progressTimer);

        // 1. Trigger Quick Save for all ACTIVE slots
        for (const slot of Object.keys(this.slots)) {
            this.quickSave(parseInt(slot));
        }

        // 2. Wait for saves to write to disk
        await new Promise(r => setTimeout(r, 2000));

        // 3. Sync files back
        await this.syncSavesBack();


        if (this.inputProxy) {
            this.inputProxy.kill('SIGINT');
            this.inputProxy = null;
        }
        if (this.mGBAProcess) {
            this.mGBAProcess.kill('SIGKILL'); // Hard kill for native GBA on Windows
            this.mGBAProcess = null;
        }
        console.log(`[Room ${this.roomId}] Emulator stalled and synced.`);
    }
}

module.exports = EmulatorInstance;
