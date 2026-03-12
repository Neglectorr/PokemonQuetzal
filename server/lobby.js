/**
 * Lobby & Room Management
 * In-memory room store with REST API
 */
const express = require('express');
const { v4: uuidv4 } = require('uuid');
const { ensureAuth } = require('./auth');
const romMatcher = require('./romMatcher');
const router = express.Router();

// Room store
const rooms = new Map();

/**
 * Room model:
 * {
 *   id: string,
 *   name: string,
 *   host: { id, username, avatar },
 *   players: Map<socketId, { id, username, avatar, slot, rom }>,
 *   spectators: Map<socketId, { id, username, avatar }>,
 *   rom: string (filename),
 *   romGroup: string,
 *   status: 'waiting' | 'playing' | 'paused',
 *   maxPlayers: number (2-4),
 *   createdAt: Date,
 *   emulator: null | reference
 * }
 */

// List all rooms
router.get('/rooms', ensureAuth, (req, res) => {
  const roomList = [];
  for (const [id, room] of rooms) {
    roomList.push({
      id: room.id,
      name: room.name,
      host: room.host,
      playerCount: room.players.size,
      spectatorCount: room.spectators.size,
      maxPlayers: room.maxPlayers,
      rom: room.rom,
      romGroup: room.romGroup,
      status: room.status,
      createdAt: room.createdAt
    });
  }
  res.json({ rooms: roomList });
});

// Get single room
router.get('/rooms/:id', ensureAuth, (req, res) => {
  const room = rooms.get(req.params.id);
  if (!room) return res.status(404).json({ error: 'Room not found' });

  const players = [];
  for (const [, p] of room.players) {
    players.push({ id: p.id, username: p.username, avatar: p.avatar, slot: p.slot, rom: p.rom });
  }

  const spectators = [];
  for (const [, s] of room.spectators) {
    spectators.push({ id: s.id, username: s.username, avatar: s.avatar });
  }

  res.json({
    id: room.id,
    name: room.name,
    host: room.host,
    players,
    spectators,
    maxPlayers: room.maxPlayers,
    rom: room.rom,
    romGroup: room.romGroup,
    status: room.status,
    createdAt: room.createdAt
  });
});

// Create room
router.post('/rooms', ensureAuth, (req, res) => {
  const { name, rom, maxPlayers } = req.body;

  if (!name || !rom) {
    return res.status(400).json({ error: 'Room name and ROM are required' });
  }

  const max = Math.min(Math.max(parseInt(maxPlayers) || 2, 2), 4);
  const romGroup = romMatcher.getRomGroup(rom);

  const room = {
    id: uuidv4(),
    name: name.substring(0, 40),
    host: { id: req.user.id, username: req.user.username, avatar: req.user.avatar },
    players: new Map(),
    spectators: new Map(),
    rom,
    romGroup,
    status: 'waiting',
    maxPlayers: max,
    createdAt: new Date(),
    emulator: null,
    disconnectTimers: new Map()
  };

  rooms.set(room.id, room);
  console.log(`[Lobby] Room created: "${room.name}" by ${req.user.username} (ROM: ${rom})`);

  res.json({
    id: room.id,
    name: room.name,
    host: room.host,
    rom: room.rom,
    romGroup,
    maxPlayers: max
  });
});

// Delete room (host only)
router.delete('/rooms/:id', ensureAuth, (req, res) => {
  const room = rooms.get(req.params.id);
  if (!room) return res.status(404).json({ error: 'Room not found' });
  if (room.host.id !== req.user.id) return res.status(403).json({ error: 'Only the host can delete the room' });

  rooms.delete(req.params.id);
  console.log(`[Lobby] Room deleted: "${room.name}"`);
  res.json({ success: true });
});

function getRoom(id) { return rooms.get(id); }
function getAllRooms() { return rooms; }
function deleteRoom(id) { rooms.delete(id); }

module.exports = { router, getRoom, getAllRooms, deleteRoom };
