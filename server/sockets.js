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
      console.log(`[Socket] Connected: ${data.username} (${socket.id})`);
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
      console.log(`[Socket] ${userData.username} joined room "${room.name}" as player ${slot}`);

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
      if (!mapping || !mapping.roomId || !userData) return;

      const room = lobbies.getRoom(mapping.roomId);
      if (!room) return;

      if (room.host.id !== userData.id) return;
      if (room.status === 'playing') return;

      console.log(`[Socket] Starting HYPER-WASM Core for room "${room.name}"`);

      // Launch Server-Side WASM Core
      const WasmEmulator = require('./wasmEmulator');
      room.emulator = new WasmEmulator(room.id, room.maxPlayers);
      
      room.status = 'playing';
      broadcastRoomState(room.id);

      room.emulator.on('frame', (buffer) => {
          // Broadcast raw binary frame to all portal users
          io.to(room.id).emit('frame', {
              slot: 1,
              data: buffer.toString('base64'),
              type: 'rgba'
          });
      });

      try {
          await room.emulator.start(room.rom.path);
          console.log(`[Socket] WASM Core Ready for room "${room.name}"`);
          io.to(room.id).emit('game-started', { mode: 'WASM' });
      } catch (err) {
          console.error("Failed to start WASM Core:", err);
          io.to(room.id).emit('error', { message: 'WASM Core Failure: ' + err.message });
          room.status = 'waiting';
          broadcastRoomState(room.id);
      }
    });

    // Input relay (Prototype: Player 1 controls the master instance)
    socket.on('player-input', (data) => {
        const mapping = socketUsers.get(socket.id);
        if (mapping && mapping.roomId) {
            const room = lobbies.getRoom(mapping.roomId);
            if (room && room.emulator && room.emulator.isReady) {
                // data = { button: 'A', isPressed: true }
                room.emulator.sendInput(data.button, data.isPressed).catch(console.error);
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
