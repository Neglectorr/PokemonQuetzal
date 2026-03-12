import { EmulatorInstance } from '../server/emulator.js';
import fs from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const __dirname = path.dirname(fileURLToPath(import.meta.url));

async function runTest() {
    console.log('🚀 Starting Direct Engine 4-Player Verification...');

    const roomId = 'test-verification-room';
    const romName = 'QuetzalEnglishAlpha8v4.gba';
    const players = [
        { slot: 1, userId: 'user-1' },
        { slot: 2, userId: 'user-2' },
        { slot: 3, userId: 'user-3' },
        { slot: 4, userId: 'user-4' }
    ];

    let framesCaptured = { 1: false, 2: false, 3: false, 4: false };

    const instance = new EmulatorInstance(
        roomId,
        4,
        (slot, b64Data, width, height) => {
            if (!framesCaptured[slot]) {
                console.log(`📸 Captured frame for Slot ${slot} (${width}x${height})`);
                const buffer = Buffer.from(b64Data.split(',')[1], 'base64');
                fs.writeFileSync(path.join(__dirname, '..', `verify_slot_${slot}.png`), buffer);
                framesCaptured[slot] = true;
            }
        },
        null, // audio
        () => console.log('✅ Emulator Ready!'),
        (err) => console.error('❌ Emulator Error:', err)
    );

    console.log('[Test] Loading ROM...');
    const ok = await instance.loadRom(romName, players);
    if (!ok) {
        console.error('❌ Failed to load ROM');
        process.exit(1);
    }

    console.log('⌛ Waiting for all 4 slots to produce frames...');
    
    // Give it 30 seconds
    const timeout = setTimeout(() => {
        console.log('⚠️ Timeout waiting for all frames. Captured:', framesCaptured);
        cleanup();
    }, 30000);

    const checkInterval = setInterval(() => {
        if (Object.values(framesCaptured).every(v => v === true)) {
            console.log('🎉 All 4 frames captured successfully!');
            clearTimeout(timeout);
            clearInterval(checkInterval);
            cleanup();
        }
    }, 1000);

    function cleanup() {
        console.log('🧹 Cleaning up...');
        instance.kill();
        process.exit(0);
    }
}

// mGBA emulator class is CommonJS, we are in ESM for verified script
// We need to wrap it if needed or just use require if node allows it.
// Since package.json doesn't have type: module, and emulator.js is CJS:
// I'll write the script as CommonJS to be safe.
runTest();
