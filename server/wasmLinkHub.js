
const events = require('events');

class WasmLinkHub extends events.EventEmitter {
    constructor() {
        super();
        this.dataCache = [0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF];
        this.players = new Map(); // id -> slotIndex
    }

    join(playerId) {
        // playerId is roomId_slot
        const parts = playerId.split('_');
        const slot = parseInt(parts[parts.length - 1]);
        this.players.set(playerId, slot);
        console.log(`[LinkHub] Player ${playerId} assigned to slot ${slot}`);
        return slot;
    }

    // Update the cached data for a player
    updateData(playerId, data) {
        const slot = this.players.get(playerId);
        if (slot !== undefined) {
            this.dataCache[slot] = data;
        }
    }

    // Force a synchronization exchange
    // Usually triggered by the Master (Slot 0)
    signalReady(playerId, multiData) {
        const slot = this.players.get(playerId);
        if (slot === undefined) return;

        this.dataCache[slot] = multiData;
        
        // In GBA Multi-player, Slot 0 is usually the master who starts the transfer.
        // We broadcast the current cache to everyone.
        const result = [...this.dataCache];
        // console.log(`[LinkHub] Exchange for ${playerId}: ${result.join(', ')}`);
        
        // We can either emit to everyone, or just respond to the one who asked.
        // For Multi-player mode, everyone needs to win.
        this.emit(`sync-all:${playerId.split('_')[0]}`, result);
    }
    
    leave(playerId) {
        this.players.delete(playerId);
    }
}

module.exports = new WasmLinkHub();
