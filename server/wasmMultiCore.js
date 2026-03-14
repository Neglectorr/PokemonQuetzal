
const EventEmitter = require('events');
const WasmEmulator = require('./wasmEmulator');

class WasmMultiCore extends EventEmitter {
    constructor(roomId, slotCount, romPath) {
        super();
        this.roomId = roomId;
        this.slotCount = slotCount;
        this.romPath = romPath;
        this.instances = [];
        this.isReady = false;
        this.readyCount = 0;
    }

    async start() {
        console.log(`[WasmMultiCore ${this.roomId}] Spawning ${this.slotCount} instances...`);
        
        for (let i = 0; i < this.slotCount; i++) {
            const instance = new WasmEmulator(this.roomId, i + 1, this.slotCount);
            
            instance.on('frame', (buffer) => {
                this.emit('frame', i + 1, buffer);
            });

            instance.on('error', (err) => {
                this.emit('error', `Slot ${i+1}: ${err}`);
            });

            this.instances.push(instance);
        }

        // Start all instances
        const startPromises = this.instances.map(instance => instance.start(this.romPath));
        
        try {
            await Promise.all(startPromises);
            this.isReady = true;
            console.log(`[WasmMultiCore ${this.roomId}] All instances started and linked.`);
            this.emit('ready');
        } catch (err) {
            console.error(`[WasmMultiCore ${this.roomId}] Failed to start all instances:`, err);
            this.emit('error', err.message);
            this.stop();
        }
    }

    sendInput(slot, button, isPressed) {
        // slot is 1-indexed here
        const instance = this.instances[slot - 1];
        if (instance) {
            instance.sendInput(button, isPressed);
        }
    }

    async syncInput(slot, bitmask) {
        const instance = this.instances[slot - 1];
        if (instance) {
            return instance.syncInput(bitmask);
        }
    }

    async stop() {
        console.log(`[WasmMultiCore ${this.roomId}] Stopping all instances...`);
        const stopPromises = this.instances.map(instance => instance.stop());
        await Promise.all(stopPromises);
        this.instances = [];
        this.isReady = false;
    }
}

module.exports = WasmMultiCore;
