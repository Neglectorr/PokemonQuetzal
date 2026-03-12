const EmulatorInstance = require('../server/emulator');
const fs = require('fs');
const path = require('path');

async function runStressTest() {
    console.log('🚀 Starting Concurrent Room Stress Test...');

    const rooms = [
        { id: 'stress-room-A', players: [{ slot: 1, userId: 'user-A1' }, { slot: 2, userId: 'user-A2' }] },
        { id: 'stress-room-B', players: [{ slot: 1, userId: 'user-B1' }, { slot: 2, userId: 'user-B2' }] }
    ];

    const romName = 'QuetzalEnglishAlpha8v4.gba';
    const instances = [];

    for (const room of rooms) {
        console.log(`[Stress] Launching Room ${room.id}...`);
        const instance = new EmulatorInstance(
            room.id,
            2, // 2 players each
            (slot, data) => {
                // Heartbeat log every 100 frames
                if (!instance.frameCount) instance.frameCount = {};
                instance.frameCount[slot] = (instance.frameCount[slot] || 0) + 1;
                if (instance.frameCount[slot] % 100 === 0) {
                    console.log(`📡 [${room.id}] Slot ${slot}: Received ${instance.frameCount[slot]} frames`);
                }
            },
            null,
            () => console.log(`✅ [${room.id}] Emulator Ready!`),
            (err) => console.error(`❌ [${room.id}] Emulator Error:`, err)
        );
        
        const ok = await instance.loadRom(romName, room.players);
        if (!ok) {
            console.error(`❌ [${room.id}] Failed to load ROM`);
            process.exit(1);
        }
        instances.push(instance);
    }

    console.log('⌛ Stress test running for 30 seconds (Shared ROM, 4 active players, 2 instances)...');
    
    setTimeout(() => {
        console.log('🧹 Cleaning up stress test...');
        instances.forEach(inst => inst.kill());
        console.log('🎉 Stress test complete! Check for any crashed pids or collisions.');
        process.exit(0);
    }, 30000);
}

runStressTest();
