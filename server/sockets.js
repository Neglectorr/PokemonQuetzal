const lobbyModule = require('./lobby');

// Internal state for tracking users across sockets
const socketUsers = new Map();

/**
 * Socket.io Event Handlers
 */
function init(io, lobbies) {
  io.on('connection', (socket) => {
    let userData = null;

    // Handle initial auth
    socket.on('auth', (data) => {
      userData = { ...data, socketId: socket.id };
      socketUsers.set(socket.id, userData);
      console.log(`[Socket] Auth successful: ${data.username} (${data.id}) on socket ${socket.id}`);
    });

    socket.on('disconnect', () => {
      if (userData) {
        console.log(`[Socket] Disconnected: ${userData.username} (${socket.id})`);
        
        // Find if user was in a room
        const mapping = socketUsers.get(socket.id);
        if (mapping && mapping.roomId) {
          const room = lobbies.getRoom(mapping.roomId);
          if (room) {
            room.players.delete(userData.id);
            if (room.players.size === 0) {
              // Kill emulator if room empty
              if (room.emulator) {
                  room.emulator.stop().catch(console.error);
              }
              lobbies.deleteRoom(room.id);
            } else {
              // Re-assign host if needed
              if (room.host.id === userData.id) {
                room.host = Array.from(room.players.values())[0];
              }
              broadcastRoomState(room.id);
            }
          }
        }
        socketUsers.delete(socket.id);
      }
    });

    // ═══════════════════════════════════════
    // LOBBY ACTIONS
    // ═══════════════════════════════════════

    socket.on('join-room', (roomId) => {
      if (!userData) return;
      const room = lobbies.getRoom(roomId);
      if (!room) return;

      if (room.players.size >= room.maxPlayers) {
        socket.emit('error', { message: 'Room is full' });
        return;
      }

      // Assign first available slot
      const usedSlots = Array.from(room.players.values()).map(p => p.slot);
      let slot = 1;
      while (usedSlots.includes(slot)) slot++;

      const playerInfo = { ...userData, slot };
      room.players.set(userData.id, playerInfo);
      
      const mapping = socketUsers.get(socket.id);
      if (mapping) {
          mapping.roomId = roomId;
          mapping.slot = slot;
      }

      socket.join(roomId);
      console.log(`[Socket] ${userData.username} (ID: ${userData.id}) joined room "${room.name}" as player ${slot}`);
      
      broadcastRoomState(roomId);
      socket.emit('joined-room', { roomId, slot });
    });

    function broadcastRoomState(roomId) {
      const room = lobbies.getRoom(roomId);
      if (room) {
        io.to(roomId).emit('room-update', {
          id: room.id,
          name: room.name,
          host: room.host,
          status: room.status,
          players: Array.from(room.players.values()),
          maxPlayers: room.maxPlayers,
          rom: room.rom
        });
      }
    }

    // ═══════════════════════════════════════
    // GAME ACTIONS
    // ═══════════════════════════════════════

    socket.on('start-game', async () => {
      const mapping = socketUsers.get(socket.id);
      if (!mapping || !mapping.roomId || !userData) {
          console.warn(`[Socket] start-game denied: Missing mapping or userData. Socket: ${socket.id}`);
          return;
      }

      const room = lobbies.getRoom(mapping.roomId);
      if (!room) {
          console.warn(`[Socket] start-game denied: Room ${mapping.roomId} not found.`);
          return;
      }

      console.log(`[Socket] start-game received from ${userData.username} for room ${room.id}. Host: ${room.host.id}, User: ${userData.id}`);

      if (room.host.id != userData.id) {
          console.warn(`[Socket] start-game denied: User ${userData.id} is not host ${room.host.id}`);
          return;
      }
      
      if (room.status === 'playing') {
          console.warn(`[Socket] start-game ignored: Room already playing.`);
          return;
      }

      console.log(`[Socket] Starting WASM MULTI-CORE for room "${room.name}"`);

      // Resolve ROM Filename accurately
      let romName = (room.rom && typeof room.rom === 'object') ? room.rom.name : room.rom;
      if (!romName || romName === 'Quetzal') romName = 'QuetzalEnglishAlpha8v4.gba';
      
      console.log(`[Socket] Selected ROM for WASM Multi-Core: ${romName}`);

      room.emulator = new WasmMultiCore(room.id, room.maxPlayers, romName);
      
      room.emulator.on('frame', (slot, buffer) => {
          // Broadcast frame for the specific slot
          io.to(room.id).emit('frame', {
              slot: slot,
              data: buffer,
              width: 240,
              height: 160
          });
      });

      room.emulator.on('ready', () => {
          console.log(`[Socket] WASM Multi-Core Ready for room "${room.name}"`);
          io.to(room.id).emit('game-started', { mode: 'WASM_MULTI' });
      });

      room.emulator.on('error', (err) => {
          console.error(`[Socket] WASM Multi-Core Error (${room.id}):`, err);
          io.to(room.id).emit('emulator-error', err);
      });
      // The original code had a macro-progress callback here, but WasmMultiCore uses events.
      // If macro-progress is needed, it should be implemented as an event listener for WasmMultiCore.
      
      room.status = 'playing';
      broadcastRoomState(room.id);

      room.emulator.start().catch(err => {
          console.error('[Socket] Failed to start WASM Multiplayer:', err);
          io.to(room.id).emit('emulator-error', 'WASM Core Failure: ' + err.message);
          room.status = 'waiting';
          broadcastRoomState(room.id);
      });
    });

    // Input relay (Prototype: Player 1 controls the master instance)
    socket.on('player-input', (data) => {
        const mapping = socketUsers.get(socket.id);
        if (mapping && mapping.roomId) {
            const room = lobbies.getRoom(mapping.roomId);
            if (room && room.emulator && (room.emulator.isReady || room.emulator.state === 'playing')) {
                if (data.buttons !== undefined) {
                    if (room.emulator.syncInput) {
                        room.emulator.syncInput(mapping.slot, data.buttons).catch(console.error);
                    } else if (room.emulator.sendInput) {
                        // Native backend uses sendInput(slot, buttons)
                        room.emulator.sendInput(mapping.slot, data.buttons);
                    }
                } else {
                    if (room.emulator.sendInput) {
                        room.emulator.sendInput(mapping.slot, data.button, data.isPressed).catch(console.error);
                    }
                }
            }
        }
    });

    // ═══════════════════════════════════════
    // LINK RELAY
    // ═══════════════════════════════════════
    socket.on('link-data', (data) => {
        const mapping = socketUsers.get(socket.id);
        if (!mapping || !mapping.roomId) return;
        socket.to(mapping.roomId).emit('link-data', { from: socket.id, payload: data });
    });

    socket.on('chat-message', ({ message }) => {
      const mapping = socketUsers.get(socket.id);
      if (mapping && mapping.roomId && userData) {
        io.to(mapping.roomId).emit('chat-message', {
          username: userData.username,
          message: message,
          time: new Date().toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })
        });
      }
    });
  });
}

module.exports = { init };
