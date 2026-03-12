/**
 * Socket.io Event Handlers
 * Real-time room management, player sync, heartbeat, and emulator bridge
 */
const { v4: uuidv4 } = require('uuid');

// Track socket -> user/room mappings
const socketUsers = new Map(); // socketId -> { userId, username, roomId, role }
const disconnectTimers = new Map(); // userId -> timeout

let io;
let lobbyModule;

function init(socketIo, lobby) {
  io = socketIo;
  lobbyModule = lobby;

  io.on('connection', (socket) => {
    const session = socket.request.session;
    const passportUser = session?.passport?.user;
    const debugMode = process.env.DEBUG_AUTH === 'true';

    // Resolve user from session (passport may or may not have run on the WS upgrade)
    const auth = require('./auth');
    let userData = passportUser ? auth.users.get(passportUser) : null;

    // In debug mode: if we still have no user, create a transient guest keyed by session ID
    if (!userData && debugMode) {
      const sid = session?.id || socket.id;
      const guestId = `debug_guest_${sid.substring(0, 8)}`;
      userData = auth.users.get(guestId);
      if (!userData) {
        userData = { id: guestId, username: `Guest_${sid.substring(0, 5)}`, avatar: null, provider: 'debug' };
        auth.users.set(guestId, userData);
      }
    }

    if (userData) {
      console.log(`[Socket] Connected: ${userData.username} (${socket.id})`);
      if (disconnectTimers.has(userData.id)) {
        clearTimeout(disconnectTimers.get(userData.id));
        disconnectTimers.delete(userData.id);
        console.log(`[Socket] Reconnection: ${userData.username} - cancelling disconnect timer`);
      }
    } else {
      console.log(`[Socket] Anonymous lobby connection (${socket.id})`);
    }

    // ═══════════════════════════════════════
    // JOIN ROOM
    // ═══════════════════════════════════════
    socket.on('join-room', ({ roomId, role, rom }) => {
      if (!userData) {
        socket.emit('error', { message: 'Authentication required to join a room' });
        return;
      }

      const room = lobbyModule.getRoom(roomId);
      if (!room) {
        socket.emit('error', { message: 'Room not found' });
        return;
      }

      // Leave any previous room
      leaveCurrentRoom(socket);

      if (role === 'spectator') {
        room.spectators.set(socket.id, {
          id: userData.id,
          username: userData.username,
          avatar: userData.avatar
        });
        socketUsers.set(socket.id, { userId: userData.id, username: userData.username, roomId, role: 'spectator' });
      } else {
        // Check player capacity
        if (room.players.size >= room.maxPlayers) {
          socket.emit('error', { message: 'Room is full' });
          return;
        }

        // ROM compatibility check
        if (rom && room.rom) {
          const romMatcher = require('./romMatcher');
          const result = romMatcher.canConnect(rom, room.rom);
          if (!result.compatible) {
            socket.emit('error', { message: `ROM "${rom}" is not compatible with room ROM "${room.rom}"` });
            return;
          }
        }

        // Assign player slot (1-based, host is always slot 1)
        const usedSlots = new Set();
        for (const [, p] of room.players) usedSlots.add(p.slot);
        let slot = 1;
        while (usedSlots.has(slot)) slot++;

        room.players.set(socket.id, {
          id: userData.id,
          username: userData.username,
          avatar: userData.avatar,
          slot,
          rom: rom || room.rom
        });
        socketUsers.set(socket.id, { userId: userData.id, username: userData.username, roomId, role: 'player', slot });

        // If the game is already playing, sync this player's save to the emulator instance
        if (room.status === 'playing' && room.emulator) {
          room.emulator.syncUserSaveToSlot(slot, userData.id, room.rom);
        }
      }

      socket.join(roomId);
      broadcastRoomState(roomId);

      console.log(`[Socket] ${userData.username} joined room "${room.name}" as ${role || 'player'}`);
    });

    // ═══════════════════════════════════════
    // LEAVE ROOM
    // ═══════════════════════════════════════
    socket.on('leave-room', () => {
      leaveCurrentRoom(socket);
    });

    // ═══════════════════════════════════════
    // PLAYER INPUT (GBA buttons)
    // ═══════════════════════════════════════
    socket.on('player-input', (inputData) => {
      const mapping = socketUsers.get(socket.id);
      if (!mapping || mapping.role !== 'player') return;

      const room = lobbyModule.getRoom(mapping.roomId);
      if (!room || !room.emulator) return;

      // Forward input to the emulator bridge
      // inputData = { buttons: number } (bitmask of GBA button states)
      room.emulator.sendInput(mapping.slot, inputData.buttons);
    });

    // ═══════════════════════════════════════
    // CHAT MESSAGE
    // ═══════════════════════════════════════
    socket.on('chat-message', ({ message }) => {
      if (!userData) return;
      const mapping = socketUsers.get(socket.id);
      if (!mapping) return;

      const cleanMsg = (message || '').trim().substring(0, 200);
      if (!cleanMsg) return;

      io.to(mapping.roomId).emit('chat-message', {
        userId: userData.id,
        username: userData.username,
        message: cleanMsg,
        timestamp: Date.now()
      });
    });

    // ═══════════════════════════════════════
    // START GAME (host only)
    // ═══════════════════════════════════════
    socket.on('start-game', () => {
      if (!userData) return;
      const mapping = socketUsers.get(socket.id);
      if (!mapping) return;

      const room = lobbyModule.getRoom(mapping.roomId);
      if (!room) return;

      // Verify host
      if (room.host.id !== userData.id) {
        socket.emit('error', { message: 'Only the host can start the game' });
        return;
      }

      if (room.status === 'playing') {
        socket.emit('error', { message: 'Game already in progress' });
        return;
      }

      // Start the emulation bridge
      const EmulatorInstance = require('./emulator');
      room.emulator = new EmulatorInstance(
        room.id,
        room.maxPlayers,
        (slot, b64Frame, width, height) => {
          io.to(mapping.roomId).emit('frame', { slot, data: b64Frame, width, height, raw: !!width });
        },
        (slot, audioBuffer) => {
          // Broadcast raw PCM audio to all users with slot info
          io.to(mapping.roomId).emit('audio', { slot, data: audioBuffer });
        },
        () => {
          room.status = 'playing';
          broadcastRoomState(mapping.roomId);
          io.to(mapping.roomId).emit('emulator-ready', { players: room.players.size });
          console.log(`[Socket] Native Game started in room "${room.name}"`);
        },
        (err) => {
          console.error(`[Socket] Emulator error in room "${room.name}":`, err);
          io.to(mapping.roomId).emit('emulator-error', { message: err });
          room.status = 'waiting';
          broadcastRoomState(mapping.roomId);
        }
      );

      // Collect player info for save syncing
      const players = [];
      for (const [, p] of room.players) {
        players.push({ slot: p.slot, userId: p.id });
      }

      room.emulator.loadRom(room.rom, players).then((ok) => {
        if (!ok) {
          socket.emit('error', { message: 'Failed to launch Native mGBA backend.' });
        }
      });
    });

    // ═══════════════════════════════════════
    // QUICK SAVE / LOAD
    // ═══════════════════════════════════════
    socket.on('quick-save', () => {
      const mapping = socketUsers.get(socket.id);
      if (!mapping || !mapping.roomId) return;
      const room = lobbyModule.getRoom(mapping.roomId);
      if (room && room.emulator && mapping.slot) {
        room.emulator.quickSave(mapping.slot);
      }
    });

    socket.on('quick-load', () => {
      const mapping = socketUsers.get(socket.id);
      if (!mapping || !mapping.roomId) return;
      const room = lobbyModule.getRoom(mapping.roomId);
      if (room && room.emulator && mapping.slot) {
        room.emulator.quickLoad(mapping.slot);
      }
    });

    // ═══════════════════════════════════════
    // STOP GAME (host only)
    // ═══════════════════════════════════════
    socket.on('stop-game', () => {
      if (!userData) return;
      const mapping = socketUsers.get(socket.id);
      if (!mapping) return;

      const room = lobbyModule.getRoom(mapping.roomId);
      if (!room || room.host.id !== userData.id) return;

      if (room.emulator) {
        room.emulator.kill();
        room.emulator = null;
      }
      room.status = 'waiting';
      broadcastRoomState(mapping.roomId);
      console.log(`[Socket] Game stopped in room "${room.name}"`);
    });

    // ═══════════════════════════════════════
    // DISCONNECT
    // ═══════════════════════════════════════
    socket.on('disconnect', () => {
      if (!userData) return; // anonymous lobby connection, nothing to clean up
      console.log(`[Socket] Disconnected: ${userData.username} (${socket.id})`);

      const mapping = socketUsers.get(socket.id);
      if (!mapping) return;

      // Start 30-second grace period for reconnection
      const timer = setTimeout(() => {
        console.log(`[Socket] Grace period expired for ${userData.username} - auto-saving and removing`);
        disconnectTimers.delete(userData.id);

        // Auto-save state on timeout
        const room = lobbyModule.getRoom(mapping.roomId);
        if (room && room.emulator && mapping.slot) {
          room.emulator.handlePlayerLeave(mapping.slot);
        }

        // Remove from room
        if (room) {
          room.players.delete(socket.id);
          room.spectators.delete(socket.id);

          // If host left, either transfer or close room
          if (room.host.id === userData.id) {
            if (room.players.size > 0) {
              const newHost = room.players.values().next().value;
              room.host = { id: newHost.id, username: newHost.username, avatar: newHost.avatar };
              console.log(`[Socket] Host transferred to ${newHost.username}`);
            } else {
              // No players left, clean up
              if (room.emulator) {
                room.emulator.kill();
              }
              lobbyModule.deleteRoom(room.id);
              console.log(`[Socket] Room "${room.name}" closed (host left, no players)`);
            }
          }

          broadcastRoomState(mapping.roomId);
        }

        socketUsers.delete(socket.id);
      }, 30000); // 30 second grace period

      disconnectTimers.set(userData.id, timer);
    });
  });
}

function leaveCurrentRoom(socket) {
  const mapping = socketUsers.get(socket.id);
  if (!mapping) return;

  const room = lobbyModule.getRoom(mapping.roomId);
  if (room) {
    if (room.emulator && mapping.slot) {
      room.emulator.handlePlayerLeave(mapping.slot);
    }
    
    room.players.delete(socket.id);
    room.spectators.delete(socket.id);
    socket.leave(mapping.roomId);
    
    // Check if room is completely empty
    if (room.players.size === 0) {
      if (room.emulator) {
        room.emulator.kill();
        room.emulator = null;
      }
      lobbyModule.deleteRoom(room.id);
      console.log(`[Socket] Room "${room.name}" closed (last player left)`);
    } else {
      // If host left but room isn't empty, transfer host
      if (room.host.id === mapping.userId) { // fallback
        const newHost = room.players.values().next().value;
        room.host = { id: newHost.id, username: newHost.username, avatar: newHost.avatar };
        console.log(`[Socket] Host transferred to ${newHost.username}`);
      }
      broadcastRoomState(mapping.roomId);
    }
  }
  socketUsers.delete(socket.id);
}

function broadcastRoomState(roomId) {
  const room = lobbyModule.getRoom(roomId);
  if (!room) return;

  const players = [];
  for (const [sid, p] of room.players) {
    players.push({ id: p.id, username: p.username, avatar: p.avatar, slot: p.slot, rom: p.rom, socketId: sid });
  }

  const spectators = [];
  for (const [, s] of room.spectators) {
    spectators.push({ id: s.id, username: s.username, avatar: s.avatar });
  }

  io.to(roomId).emit('room-state', {
    id: room.id,
    name: room.name,
    host: room.host,
    players,
    spectators,
    maxPlayers: room.maxPlayers,
    rom: room.rom,
    romGroup: room.romGroup,
    status: room.status
  });

  // Also broadcast to lobby for room list updates
  io.emit('room-list-update', {
    id: room.id,
    name: room.name,
    host: room.host,
    playerCount: players.length,
    spectatorCount: spectators.length,
    maxPlayers: room.maxPlayers,
    rom: room.rom,
    status: room.status
  });
}

module.exports = { init };
