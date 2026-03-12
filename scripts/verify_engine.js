const EmulatorInstance = require('../server/emulator');
const fs = require('fs');
const path = require('path');

async function runTest() {
    console.log('🚀 Starting Direct Engine PNG Verification...');

    const roomId = 'test-png-room';
    const romName = 'QuetzalEnglishAlpha8v4.gba';
    const players = [
        { slot: 1, userId: 'user-1' }
    ];

    // Simulate Session 0 (Headless) by hiding windows
    process.env.WRAPPER_HIDE_WINDOWS = '1';
    let framesCaptured = { 1: false };

    const instance = new EmulatorInstance(
        roomId,
        4,
        (slot, data, width, height) => {
            if (slot === 1 && !framesCaptured[1]) {
                const now = Date.now();
                const elapsedSinceReady = now - (instance.readyTime || 0);
                if (elapsedSinceReady < 12000) return; // Wait 12s for splash screen to appear

                let buffer;
                if (typeof data === 'string' && data.startsWith('iVBOR')) { // Base64 PNG start
                    buffer = Buffer.from(data, 'base64');
                } else if (Buffer.isBuffer(data)) {
                    buffer = data;
                } else if (typeof data === 'string' && data.includes(',')) {
                    buffer = Buffer.from(data.split(',')[1], 'base64');
                } else {
                    return; // Unknown format
                }

                const savePath = path.resolve(process.cwd(), `verify_slot_${slot}.png`);
                
                try {
                    console.log(`📸 Slot ${slot} frame received (Software Mode). Saving -> ${savePath}`);
                    fs.writeFileSync(savePath, buffer);
                    console.log(`✅ Slot ${slot} saved! size=${buffer.length}`);
                    framesCaptured[slot] = true;
                } catch (err) {
                    console.error(`❌ Failed to write file ${savePath}:`, err.message);
                }
            }
        },
        null, // audio
        () => {
            console.log('✅ Emulator Ready!');
            instance.readyTime = Date.now();
        },
        (err) => console.error('❌ Emulator Error:', err)
    );

    console.log('[Test] Loading ROM (Software Rendering + Session 0)...');
    const ok = await instance.loadRom(romName, players);
    if (!ok) {
        console.error('❌ Failed to load ROM');
        process.exit(1);
    }

    console.log('⌛ Waiting 20s for splash screen in headless software mode...');
    
    setTimeout(() => {
        instance.kill();
        const finalPath = path.resolve(process.cwd(), 'verify_slot_1.png');
        if (fs.existsSync(finalPath)) {
            console.log(`🎉 SUCCESS! Splash PNG generated at: ${finalPath}`);
            process.exit(0);
        } else {
            console.error('❌ FAILED: PNG proof was not generated.');
            process.exit(1);
        }
    }, 20000);
}

runTest();
