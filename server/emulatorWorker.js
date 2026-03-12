/**
 * Emulator Worker Thread
 * Runs mGBA WASM instances inside a Worker Thread for CPU isolation
 * 
 * For the prototype, this provides a simulated emulation layer that
 * generates real-looking GBA frames and handles serial communication patterns.
 * The architecture is designed so that @thenick775/mgba-wasm can be
 * dropped in as a direct replacement when ready.
 * 
 * Virtual Serial Bus: bridges data between instances for both
 * link cable (SIOCNT Normal/Multi-Player mode) and wireless adapter (RCNT GPIO mode)
 */
const { parentPort, workerData } = require('worker_threads');
const path = require('path');
const fs = require('fs');

const { roomId, players, romDataMap, saveDataMap } = workerData;

// GBA constants
const GBA_WIDTH = 240;
const GBA_HEIGHT = 160;
const FRAME_BYTES = GBA_WIDTH * GBA_HEIGHT * 4;

// Serial port register addresses
const SERIAL_REGS = {
  SIODATA32:  0x04000120,
  SIOMULTI0:  0x04000120,
  SIOMULTI1:  0x04000122,
  SIOMULTI2:  0x04000124,
  SIOMULTI3:  0x04000126,
  SIOCNT:     0x04000128,
  SIODATA_S:  0x0400012A,
  RCNT:       0x04000134,  // Used for wireless adapter GPIO mode
  JOYCNT:     0x04000140
};

/**
 * Emulator Instance - wraps mGBA WASM or provides simulation
 */
class EmulatorInstance {
  constructor(slot, romData, saveData) {
    this.slot = slot;
    this.romData = romData;
    this.saveData = saveData;
    this.running = false;
    this.buttons = 0; // Current button state (bitmask)
    this.frameCount = 0;
    this.lastFrameTime = 0;
    
    // Serial port state for link cable / wireless adapter
    this.serialState = {
      siocnt: 0,
      siodata: new Uint16Array(4), // Multi-player data slots
      rcnt: 0,          // GPIO/wireless adapter control
      pendingSend: null,
      mode: 'idle'      // 'idle' | 'normal' | 'multi' | 'wireless'
    };
  }

  async init() {
    // TODO: Initialize real mGBA WASM instance here
    // For now, create a simulated framebuffer
    this.framebuffer = new Uint8Array(FRAME_BYTES);
    this.running = true;
    return true;
  }

  /**
   * Run one frame of emulation
   */
  runFrame() {
    if (!this.running) return null;
    this.frameCount++;
    
    // Generate a simulated GBA frame
    // This creates a visual representation showing:
    // - Player slot number
    // - Current input state
    // - Frame counter
    // - A GBA-like background
    this.generateSimulatedFrame();
    
    return this.framebuffer;
  }

  /**
   * Generate a simulated frame that looks like a GBA screen
   * Shows player info, connection status, and input visualization
   */
  generateSimulatedFrame() {
    const fb = this.framebuffer;
    const frame = this.frameCount;
    
    // Color scheme per player slot (GBA-themed)
    const colors = [
      [40, 80, 120],   // Slot 1: Deep blue
      [120, 40, 60],   // Slot 2: Deep red  
      [40, 100, 60],   // Slot 3: Deep green
      [100, 80, 40]    // Slot 4: Deep amber
    ];
    
    const baseColor = colors[(this.slot - 1) % 4];
    
    // Fill background with animated gradient
    for (let y = 0; y < GBA_HEIGHT; y++) {
      for (let x = 0; x < GBA_WIDTH; x++) {
        const idx = (y * GBA_WIDTH + x) * 4;
        const wave = Math.sin((x + frame * 2) * 0.03) * 20 + Math.sin((y + frame) * 0.05) * 15;
        
        fb[idx]     = Math.max(0, Math.min(255, baseColor[0] + wave));       // R
        fb[idx + 1] = Math.max(0, Math.min(255, baseColor[1] + wave));       // G
        fb[idx + 2] = Math.max(0, Math.min(255, baseColor[2] + wave + 10)); // B
        fb[idx + 3] = 255; // A
      }
    }
    
    // Draw a "screen border" effect
    for (let x = 0; x < GBA_WIDTH; x++) {
      for (let t = 0; t < 3; t++) {
        const topIdx = (t * GBA_WIDTH + x) * 4;
        const botIdx = ((GBA_HEIGHT - 1 - t) * GBA_WIDTH + x) * 4;
        fb[topIdx] = fb[topIdx+1] = fb[topIdx+2] = 30;
        fb[botIdx] = fb[botIdx+1] = fb[botIdx+2] = 30;
      }
    }
    for (let y = 0; y < GBA_HEIGHT; y++) {
      for (let t = 0; t < 3; t++) {
        const leftIdx = (y * GBA_WIDTH + t) * 4;
        const rightIdx = (y * GBA_WIDTH + GBA_WIDTH - 1 - t) * 4;
        fb[leftIdx] = fb[leftIdx+1] = fb[leftIdx+2] = 30;
        fb[rightIdx] = fb[rightIdx+1] = fb[rightIdx+2] = 30;
      }
    }

    // Draw input visualization (bottom of screen)
    const btnSize = 12;
    const btnY = GBA_HEIGHT - 30;
    const buttons = [
      { name: 'U', mask: 0x040, x: 30, y: btnY - btnSize },
      { name: 'D', mask: 0x080, x: 30, y: btnY + btnSize },
      { name: 'L', mask: 0x020, x: 18, y: btnY },
      { name: 'R', mask: 0x010, x: 42, y: btnY },
      { name: 'A', mask: 0x001, x: 200, y: btnY },
      { name: 'B', mask: 0x002, x: 185, y: btnY + 8 },
      { name: 'ST', mask: 0x008, x: 100, y: btnY + 10 },
      { name: 'SE', mask: 0x004, x: 120, y: btnY + 10 },
    ];

    for (const btn of buttons) {
      const pressed = (this.buttons & btn.mask) !== 0;
      const color = pressed ? [255, 255, 100] : [80, 80, 80];
      this.drawRect(btn.x, btn.y, btnSize - 2, btnSize - 2, color);
    }

    // Draw player slot indicator (top left)
    const slotColor = [200, 200, 255];
    this.drawRect(10, 10, 40, 16, [20, 20, 40]);
    
    // Draw serial mode indicator (top right)  
    const modeColors = {
      'idle': [80, 80, 80],
      'normal': [80, 200, 80],
      'multi': [80, 80, 200],
      'wireless': [200, 80, 200]
    };
    this.drawRect(GBA_WIDTH - 60, 10, 50, 16, modeColors[this.serialState.mode] || [80, 80, 80]);
  }

  drawRect(x, y, w, h, color) {
    const fb = this.framebuffer;
    for (let dy = 0; dy < h; dy++) {
      for (let dx = 0; dx < w; dx++) {
        const px = x + dx;
        const py = y + dy;
        if (px >= 0 && px < GBA_WIDTH && py >= 0 && py < GBA_HEIGHT) {
          const idx = (py * GBA_WIDTH + px) * 4;
          fb[idx] = color[0];
          fb[idx + 1] = color[1];
          fb[idx + 2] = color[2];
          fb[idx + 3] = 255;
        }
      }
    }
  }

  setButtons(buttons) {
    this.buttons = buttons;
  }

  /**
   * Handle serial port write from this instance
   * Returns data to send to connected instances
   */
  serialWrite(register, value) {
    switch (register) {
      case SERIAL_REGS.SIOCNT:
        this.serialState.siocnt = value;
        // Detect serial mode from bits 12-13
        const mode = (value >> 12) & 0x3;
        if (mode === 0) this.serialState.mode = 'normal';
        else if (mode === 2) this.serialState.mode = 'multi';
        break;
      case SERIAL_REGS.RCNT:
        this.serialState.rcnt = value;
        // If bit 15 set, it's GPIO mode (used by wireless adapter)
        if (value & 0x8000) {
          this.serialState.mode = 'wireless';
        }
        break;
      case SERIAL_REGS.SIODATA_S:
        this.serialState.pendingSend = value;
        break;
    }
    
    return {
      from: this.slot,
      register,
      value,
      mode: this.serialState.mode
    };
  }

  getSaveState() {
    // TODO: Get actual mGBA save state
    return new Uint8Array(0);
  }

  getSram() {
    // TODO: Get actual mGBA SRAM
    return this.saveData || new Uint8Array(0);
  }

  destroy() {
    this.running = false;
    this.framebuffer = null;
  }
}

/**
 * Virtual Serial Bus - bridges communication between instances
 * Supports both link cable (Normal/Multi-Player) and wireless adapter modes
 */
class VirtualSerialBus {
  constructor() {
    this.instances = new Map(); // slot -> EmulatorInstance
    this.wirelessRoom = null;   // Wireless adapter room state
  }

  addInstance(slot, instance) {
    this.instances.set(slot, instance);
  }

  /**
   * Route serial data between connected instances
   */
  routeData(serialEvent) {
    const { from, register, value, mode } = serialEvent;

    switch (mode) {
      case 'multi': {
        // Multi-Player mode: broadcast to all connected instances
        for (const [slot, instance] of this.instances) {
          if (slot !== from) {
            instance.serialState.siodata[from - 1] = value;
          }
        }
        break;
      }
      case 'normal': {
        // Normal mode: point-to-point, route to next slot
        const targetSlot = (from % this.instances.size) + 1;
        const target = this.instances.get(targetSlot);
        if (target) {
          target.serialState.siodata[0] = value;
        }
        break;
      }
      case 'wireless': {
        // Wireless adapter mode: broadcast to all in wireless room
        for (const [slot, instance] of this.instances) {
          if (slot !== from) {
            // Mirror the wireless adapter protocol
            instance.serialState.rcnt = value;
          }
        }
        break;
      }
    }
  }
}

// ═══════════════════════════════════════
// Worker Thread Main Loop
// ═══════════════════════════════════════

const instances = new Map();
const serialBus = new VirtualSerialBus();
let running = true;
let frameInterval = null;

async function initialize() {
  try {
    // Create emulator instances for each player
    for (const player of players) {
      const romData = new Uint8Array(romDataMap[player.slot]);
      const saveData = saveDataMap[player.slot] ? new Uint8Array(saveDataMap[player.slot]) : null;
      
      const instance = new EmulatorInstance(player.slot, romData, saveData);
      await instance.init();
      
      instances.set(player.slot, instance);
      serialBus.addInstance(player.slot, instance);
      
      console.log(`[EmulatorWorker] Instance ${player.slot} initialized for ${player.username}`);
    }

    parentPort.postMessage({ type: 'ready' });

    // Start the frame loop (~60 FPS)
    const TARGET_FPS = 60;
    const FRAME_TIME = 1000 / TARGET_FPS;
    let lastTime = Date.now();

    frameInterval = setInterval(() => {
      if (!running) return;
      
      const now = Date.now();
      
      for (const [slot, instance] of instances) {
        const frameData = instance.runFrame();
        if (frameData) {
          // Send frame data to main thread (every other frame to reduce bandwidth)
          if (instance.frameCount % 2 === 0) {
            parentPort.postMessage({
              type: 'frame',
              slot,
              frameData: Buffer.from(frameData.buffer),
              timestamp: now
            });
          }
        }
      }
      
      lastTime = now;
    }, FRAME_TIME);

  } catch (err) {
    parentPort.postMessage({ type: 'error', error: err.message });
  }
}

// Handle messages from main thread
parentPort.on('message', (msg) => {
  switch (msg.type) {
    case 'input': {
      const instance = instances.get(msg.slot);
      if (instance) {
        instance.setButtons(msg.buttons);
      }
      break;
    }
    case 'save-state': {
      const instance = instances.get(msg.slot);
      if (instance) {
        const stateData = instance.getSaveState();
        const fileManager = require('./fileManager');
        const player = players.find(p => p.slot === msg.slot);
        if (player) {
          fileManager.saveStateFile(msg.userId, player.rom, stateData);
        }
        parentPort.postMessage({ type: 'save-complete', slot: msg.slot, kind: 'state' });
      }
      break;
    }
    case 'write-sram': {
      const instance = instances.get(msg.slot);
      if (instance) {
        const sramData = instance.getSram();
        const fileManager = require('./fileManager');
        const player = players.find(p => p.slot === msg.slot);
        if (player) {
          fileManager.saveSramFile(msg.userId, player.rom, sramData);
        }
        parentPort.postMessage({ type: 'save-complete', slot: msg.slot, kind: 'sram' });
      }
      break;
    }
    case 'stop': {
      running = false;
      if (frameInterval) clearInterval(frameInterval);
      for (const [, instance] of instances) {
        instance.destroy();
      }
      instances.clear();
      console.log(`[EmulatorWorker] Room ${roomId} stopped`);
      process.exit(0);
      break;
    }
  }
});

// Initialize on startup
initialize().catch(err => {
  console.error('[EmulatorWorker] Fatal error:', err);
  parentPort.postMessage({ type: 'error', error: err.message });
});
