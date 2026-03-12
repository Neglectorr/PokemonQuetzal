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
            const err = 'Custom mGBA.exe not found. Ensure it is built in mgba_src and copied to mgba_native/mGBA-custom.';
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

        const ROMS_DIR = path.join(__dirname, '..', 'roms');
        const romBase = romFilename.replace(/\.gba$/i, '');
        const SAVES_ROOT = path.join(__dirname, '..', 'saves');
        
        // Use a single Hard Link for the entire room to ensure unique saves without duplication
        const roomRomName = `${romBase}_${this.roomId}.gba`;
        const roomRomPath = path.join(ROMS_DIR, roomRomName);
        
        if (!fs.existsSync(roomRomPath)) {
            try {
                fs.linkSync(romPath, roomRomPath);
                console.log(`[Room ${this.roomId}] Created hard link for room ROM.`);
            } catch (e) {
                console.log(`[Room ${this.roomId}] Hard link failed, falling back to copy:`, e.message);
                fs.copyFileSync(romPath, roomRomPath);
            }
        }

        // Pipe name base for this lobby
        const pipeBase = `streamer_${this.roomId}`;
        this.pipeBridges = [];

        // 1. Prepare per-player saves (mGBA handles suffixes .sav, .sa2, etc. based on the ROM basename)
        for (let slot = 1; slot <= this.maxPlayers; slot++) {
            const player = players.find(p => p.slot === slot);
            if (player) {
                // Suffixes based on roomRomPath base
                this.syncUserSaveToSlot(slot, player.userId, roomRomName.replace(/\.gba$/i, ''));
            }

            // Setup Pipe Bridge for this slot
            const PipeBridge = require('./pipeBridge');
            const bridge = new PipeBridge(`${pipeBase}_${slot-1}`, slot);
            bridge.on('video', (data) => {
                // emit RGBA frame to frontend
                if (this.onFrame) {
                    // Send as raw Buffer for better performance
                    this.onFrame(slot, data.data, data.width, data.height);
                }
            });
            bridge.on('audio', (payload) => {
                if (this.onAudio) this.onAudio(slot, payload);
            });
            bridge.connect();
            this.pipeBridges.push(bridge);
        }

        console.log(`[Room ${this.roomId}] Launching custom mGBA with on-demand streaming...`);
        
        // Spawn mGBA with --stream-pipe. We only need the ONE ROM path.
        // mGBA -m 4 path.gba will open 4 windows all loading that path.
        const mgbaArgs = ['-m', this.maxPlayers.toString(), '--stream-pipe', pipeBase, roomRomPath];
        this.mGBAProcess = spawn(mgbaExe, mgbaArgs, {
            cwd: path.dirname(mgbaExe),
            stdio: ['ignore', 'pipe', 'pipe']
        });
        
        const mGbaPid = this.mGBAProcess.pid;
        console.log(`[Room ${this.roomId}] mGBA spawned with PID: ${mGbaPid}`);

        this.mGBAProcess.stdout.on('data', (data) => console.log(`[mGBA ${this.roomId}]`, data.toString().trim()));
        this.mGBAProcess.stderr.on('data', (data) => console.error(`[mGBA ${this.roomId} ERR]`, data.toString().trim()));
        
        this.mGBAProcess.on('error', (err) => {
            console.error(`[Room ${this.roomId}] Failed to spawn mGBA:`, err);
            if (this.onError) this.onError(`Spawn error: ${err.message}`);
        });

        this.mGBAProcess.on('exit', (code) => {
            console.log(`[Room ${this.roomId}] mGBA process exited with code`, code);
            this.kill();
        });

        // 2. Wait for stabilization (Our custom -m handles window linking and loading internally)
        console.log(`[Room ${this.roomId}] Waiting for custom mGBA windows to stabilize...`);
        await new Promise(r => setTimeout(r, 4000));

        // 3. Spawn Python wrapper - now passing expected window count and disabling legacy capture
        const wrapperScript = path.join(__dirname, 'wrapper.py');
        this.wrapperProcess = spawn('python', ['-u', wrapperScript, mGbaPid.toString(), this.maxPlayers.toString(), '--no-capture'], {
            stdio: ['pipe', 'pipe', 'pipe']
        });

        this.wrapperProcess.stderr.on('data', (data) => {
            const msg = data.toString().trim();
            if (msg) console.log(`[Python ${this.roomId}]`, msg);
        });

        // Frame reading (Audio is disabled in wrapper.py for now)
        let buffer = Buffer.alloc(0);
        let expectedSize = -1;
        let expectedSlot = 1;

        this.wrapperProcess.stdout.on('data', (chunk) => {
            buffer = Buffer.concat([buffer, chunk]);
            while (true) {
                if (expectedSize === -1) {
                    if (buffer.length >= 5) {
                        expectedSlot = buffer.readUInt8(0);
                        expectedSize = buffer.readUInt32LE(1);
                        buffer = buffer.slice(5);
                    } else break;
                }
                if (expectedSize !== -1 && buffer.length >= expectedSize) {
                    const frameData = buffer.slice(0, expectedSize);
                    buffer = buffer.slice(expectedSize);
                    expectedSize = -1;
                    if (expectedSlot === 0) {
                        // Audio is disabled, but if we ever re-enable it:
                        // if (this.onAudio) this.onAudio(frameData);
                    } else if (this.onFrame) {
                        this.onFrame(expectedSlot, frameData.toString('base64'));
                    }
                } else break;
            }
        });

        this.wrapperProcess.on('exit', (code) => {
            console.log(`[Room ${this.roomId}] Python wrapper exited with code`, code);
            this.kill();
        });

        this.state = 'playing';
        
        // 4. Auto-load save states for assigned slots
        setTimeout(() => {
            for (const slot of Object.keys(this.slots)) {
                this.quickLoad(parseInt(slot));
            }
        }, 5000); // Wait for ROMs to be fully loaded

        if (this.onReady) this.onReady();
        return true;
    }
    getSlotSaveExtensions(slot) {
        // mGBA Multiplayer: P1 uses .sav, P2 uses .sa2, P3 uses .sa3, P4 uses .sa4
        if (slot === 1) return ['.sav'];
        return [`.sa${slot}`, '.sav']; // Check .saX first, then .sav as fallback
    }

    syncUserSaveToSlot(slot, userId, romBase) {
        const SAVES_ROOT = path.join(__dirname, '..', 'saves');
        const ROMS_DIR = path.join(__dirname, '..', 'roms');
        
        const pRomPath = path.join(ROMS_DIR, `${romBase}_${this.roomId}_P${slot}.gba`);
        const pSavePath = path.join(ROMS_DIR, `${romBase}_${this.roomId}_P${slot}.sav`);
        const pStatePath = path.join(ROMS_DIR, `${romBase}_${this.roomId}_P${slot}.ss1`);

        this.slots[slot] = { userId, romBase };

        try {
            // Ensure ROM exists for this slot
            const baseRomPath = path.join(ROMS_DIR, `${romBase}.gba`);
            if (!fs.existsSync(pRomPath)) {
                fs.copyFileSync(baseRomPath, pRomPath);
            }

            const userDir = path.join(SAVES_ROOT, userId);
            if (!fs.existsSync(userDir)) fs.mkdirSync(userDir, { recursive: true });

            const userSave = path.join(userDir, `${romBase}.sav`);
            const userState = path.join(userDir, `${romBase}.state`);

            if (fs.existsSync(userSave)) {
                // To be safe, we sync to BOTH .sav and the .saX variant so mGBA finds it
                const extensions = this.getSlotSaveExtensions(slot);
                const baseRomPath = path.join(ROMS_DIR, `${romBase}.gba`);
                extensions.forEach(ext => {
                    const targetPath = baseRomPath.replace(/\.gba$/i, `_${this.roomId}_P${slot}${ext}`);
                    fs.copyFileSync(userSave, targetPath);
                });
                console.log(`[Room ${this.roomId}] Syncing SRAM for P${slot} (${userId})`);
            } else {
                // Remove any existing temporary saves if user has none
                const extensions = this.getSlotSaveExtensions(slot);
                const baseRomPath = path.join(ROMS_DIR, `${romBase}.gba`);
                extensions.forEach(ext => {
                    const targetPath = baseRomPath.replace(/\.gba$/i, `_${this.roomId}_P${slot}${ext}`);
                    if (fs.existsSync(targetPath)) fs.unlinkSync(targetPath);
                });
            }

            if (fs.existsSync(userState)) {
                fs.copyFileSync(userState, pStatePath);
                console.log(`[Room ${this.roomId}] Syncing State for P${slot} (${userId})`);
                
                // If game is already playing, trigger the load
                if (this.state === 'playing') {
                    setTimeout(() => this.quickLoad(slot), 500);
                }
            } else {
                // CRITICAL: If player has no state, remove any stale state in this slot
                // to prevent loading someone else's progress
                if (fs.existsSync(pStatePath)) {
                    fs.unlinkSync(pStatePath);
                    console.log(`[Room ${this.roomId}] Cleared stale state for P${slot}`);
                }
            }
        } catch (e) {
            console.error(`[Room ${this.roomId}] Sync failed for P${slot}:`, e);
        }
    }


    async syncSavesBack(targetSlot = null) {
        const ROMS_DIR = path.join(__dirname, '..', 'roms');
        const SAVES_ROOT = path.join(__dirname, '..', 'saves');

        let lastRomBase = null;
        const slotsToSync = targetSlot ? [[targetSlot, this.slots[targetSlot]]] : Object.entries(this.slots);

        for (const [slot, data] of slotsToSync) {
            if (!data) continue;
            const { userId, romBase } = data;
            lastRomBase = romBase;
            
            const pSave = path.join(ROMS_DIR, `${romBase}_${this.roomId}_P${slot}.sav`);
            const pState = path.join(ROMS_DIR, `${romBase}_${this.roomId}_P${slot}.ss1`);
            
            const userDir = path.join(SAVES_ROOT, userId);
            const userSave = path.join(userDir, `${romBase}.sav`);
            const userState = path.join(userDir, `${romBase}.state`);

            try {
                // SRAM Verification: Ensure file actually has data. Check both .sav and .saX
                const extensions = this.getSlotSaveExtensions(slot);
                for (const ext of extensions) {
                    const pSaveExt = path.join(ROMS_DIR, `${romBase}_${this.roomId}_P${slot}${ext}`);
                    if (fs.existsSync(pSaveExt)) {
                        const stats = fs.statSync(pSaveExt);
                        if (stats.size > 0) {
                            fs.copyFileSync(pSaveExt, userSave);
                            break; // Priority found
                        }
                    }
                }
                
                // State Verification: Savestates for GBA are typically > 100KB
                if (fs.existsSync(pState)) {
                    const stats = fs.statSync(pState);
                    if (stats.size > 10000) { // Safety threshold
                        fs.copyFileSync(pState, userState);
                    }
                }
                console.log(`[Room ${this.roomId}] Bulletproof sync complete for ${userId} (Slot ${slot})`);
            } catch (e) {
                console.error(`[Room ${this.roomId}] CRITICAL: Sync failed for ${userId}:`, e);
            }
        }
        
        // Final cleanup on room destruction
        if (!targetSlot && lastRomBase) {
            console.log(`[Room ${this.roomId}] Final cleanup of temporary room files...`);
            for (let slot = 1; slot <= this.maxPlayers; slot++) {
                try {
                    const base = path.join(ROMS_DIR, `${lastRomBase}_${this.roomId}_P${slot}`);
                    const extensions = ['.gba', '.sav', '.ss1', '.state', '.sa1', '.sa2', '.sa3', '.sa4'];
                    extensions.forEach(ext => {
                        const fp = base + ext;
                        if (fs.existsSync(fp)) fs.unlinkSync(fp);
                    });
                } catch(e) {}
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
        if (!this.wrapperProcess || this.state !== 'playing') return;

        for (const { mask, name } of this.BUTTON_NAMES) {
            const nowPressed = (buttons    & mask) !== 0;
            const wasPressed = (this.lastButtons[slot] & mask) !== 0;

            if (nowPressed && !wasPressed) {
                this.wrapperProcess.stdin.write(`${slot},${name},1\n`);
            } else if (!nowPressed && wasPressed) {
                this.wrapperProcess.stdin.write(`${slot},${name},0\n`);
            }
        }
        this.lastButtons[slot] = buttons;
    }

    quickSave(slot) {
        if (!this.wrapperProcess) return;
        console.log(`[Room ${this.roomId}] Triggering Quick Save for slot ${slot}`);
        this.wrapperProcess.stdin.write(`${slot},Shift,1\n`);
        this.wrapperProcess.stdin.write(`${slot},F1,1\n`);
        setTimeout(() => {
            this.wrapperProcess.stdin.write(`${slot},F1,0\n`);
            this.wrapperProcess.stdin.write(`${slot},Shift,0\n`);
        }, 100);
    }

    quickLoad(slot) {
        if (!this.wrapperProcess) return;
        console.log(`[Room ${this.roomId}] Triggering Quick Load for slot ${slot}`);
        this.wrapperProcess.stdin.write(`${slot},F1,1\n`);
        setTimeout(() => {
            this.wrapperProcess.stdin.write(`${slot},F1,0\n`);
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

        if (this.wrapperProcess) {
            this.wrapperProcess.kill('SIGINT');
            this.wrapperProcess = null;
        }
        if (this.mGBAProcess) {
            this.mGBAProcess.kill('SIGINT');
            this.mGBAProcess = null;
        }
        console.log(`[Room ${this.roomId}] Emulator stalled and synced.`);
    }
}

module.exports = EmulatorInstance;
