/**
 * File Manager
 * ROM listing and save file management
 * Windows/AMP compatible path handling
 */
const express = require('express');
const path = require('path');
const fs = require('fs');
const { ensureAuth } = require('./auth');
const router = express.Router();

const ROMS_DIR = path.join(__dirname, '..', 'roms');
const SAVES_DIR = path.join(__dirname, '..', 'saves');

// List available ROMs
router.get('/roms', ensureAuth, (req, res) => {
  try {
    if (!fs.existsSync(ROMS_DIR)) {
      return res.json({ roms: [] });
    }

    const files = fs.readdirSync(ROMS_DIR);
    const roms = files
      .filter(f => /\.gba$/i.test(f))
      .map(f => {
        const stats = fs.statSync(path.join(ROMS_DIR, f));
        return {
          filename: f,
          name: f.replace(/\.gba$/i, '').replace(/[_\-\.]/g, ' '),
          size: stats.size,
          sizeFormatted: formatBytes(stats.size)
        };
      });

    res.json({ roms });
  } catch (err) {
    console.error('[FileManager] Error listing ROMs:', err);
    res.status(500).json({ error: 'Failed to list ROMs' });
  }
});

// Get ROM file for emulator loading
router.get('/roms/:filename', ensureAuth, (req, res) => {
  const filePath = path.join(ROMS_DIR, path.basename(req.params.filename));
  if (!fs.existsSync(filePath)) {
    return res.status(404).json({ error: 'ROM not found' });
  }
  res.sendFile(filePath);
});

// List saves for current user
router.get('/saves', ensureAuth, (req, res) => {
  const userDir = path.join(SAVES_DIR, req.user.id);
  if (!fs.existsSync(userDir)) {
    return res.json({ saves: [] });
  }

  const files = fs.readdirSync(userDir);
  const saves = files.map(f => {
    const stats = fs.statSync(path.join(userDir, f));
    return {
      filename: f,
      type: path.extname(f) === '.state' ? 'savestate' : 'sram',
      size: stats.size,
      modified: stats.mtime
    };
  });

  res.json({ saves });
});

// Get latest save state for a ROM
router.get('/saves/latest/:romName', ensureAuth, (req, res) => {
  const userDir = path.join(SAVES_DIR, req.user.id);
  if (!fs.existsSync(userDir)) {
    return res.json({ saveState: null, sram: null });
  }

  const romBase = req.params.romName.replace(/\.gba$/i, '');
  const files = fs.readdirSync(userDir);

  let latestState = null;
  let latestSram = null;

  for (const f of files) {
    if (f.startsWith(romBase)) {
      const stats = fs.statSync(path.join(userDir, f));
      if (f.endsWith('.state') && (!latestState || stats.mtime > latestState.modified)) {
        latestState = { filename: f, modified: stats.mtime };
      }
      if (f.endsWith('.sav') && (!latestSram || stats.mtime > latestSram.modified)) {
        latestSram = { filename: f, modified: stats.mtime };
      }
    }
  }

  res.json({ saveState: latestState, sram: latestSram });
});

// Download save file
router.get('/saves/download/:filename', ensureAuth, (req, res) => {
  const filePath = path.join(SAVES_DIR, req.user.id, path.basename(req.params.filename));
  if (!fs.existsSync(filePath)) {
    return res.status(404).json({ error: 'Save not found' });
  }
  res.sendFile(filePath);
});

// Upload save file
router.post('/saves/upload', ensureAuth, (req, res) => {
  // Handle raw binary upload
  const chunks = [];
  req.on('data', chunk => chunks.push(chunk));
  req.on('end', () => {
    const userDir = path.join(SAVES_DIR, req.user.id);
    if (!fs.existsSync(userDir)) {
      fs.mkdirSync(userDir, { recursive: true });
    }

    const filename = req.headers['x-filename'] || 'upload.sav';
    const filePath = path.join(userDir, path.basename(filename));
    fs.writeFileSync(filePath, Buffer.concat(chunks));
    res.json({ success: true, filename });
  });
});

/**
 * Save emulator state to disk
 */
function saveStateFile(userId, romName, stateData) {
  const userDir = path.join(SAVES_DIR, userId);
  if (!fs.existsSync(userDir)) fs.mkdirSync(userDir, { recursive: true });

  const romBase = romName.replace(/\.gba$/i, '');
  const filename = `${romBase}.state`;
  fs.writeFileSync(path.join(userDir, filename), Buffer.from(stateData));
  console.log(`[FileManager] Saved state: ${userId}/${filename}`);
}

/**
 * Save SRAM data to disk
 */
function saveSramFile(userId, romName, sramData) {
  const userDir = path.join(SAVES_DIR, userId);
  if (!fs.existsSync(userDir)) fs.mkdirSync(userDir, { recursive: true });

  const romBase = romName.replace(/\.gba$/i, '');
  const filename = `${romBase}.sav`;
  fs.writeFileSync(path.join(userDir, filename), Buffer.from(sramData));
  console.log(`[FileManager] Saved SRAM: ${userId}/${filename}`);
}

/**
 * Load ROM data from disk
 */
function loadRomData(romFilename) {
  const filePath = path.join(ROMS_DIR, path.basename(romFilename));
  if (!fs.existsSync(filePath)) return null;
  return fs.readFileSync(filePath);
}

/**
 * Load save state from disk
 */
function loadStateFile(userId, romName) {
  const userDir = path.join(SAVES_DIR, userId);
  const romBase = romName.replace(/\.gba$/i, '');
  const filePath = path.join(userDir, `${romBase}.state`);
  if (!fs.existsSync(filePath)) return null;
  return fs.readFileSync(filePath);
}

/**
 * Load SRAM from disk
 */
function loadSramFile(userId, romName) {
  const userDir = path.join(SAVES_DIR, userId);
  const romBase = romName.replace(/\.gba$/i, '');
  const filePath = path.join(userDir, `${romBase}.sav`);
  if (!fs.existsSync(filePath)) return null;
  return fs.readFileSync(filePath);
}

/**
 * Get full path to a ROM file
 */
function getRomPath(romFilename) {
  return path.join(ROMS_DIR, path.basename(romFilename));
}

function formatBytes(bytes) {
  if (bytes === 0) return '0 B';
  const k = 1024;
  const sizes = ['B', 'KB', 'MB', 'GB'];
  const i = Math.floor(Math.log(bytes) / Math.log(k));
  return parseFloat((bytes / Math.pow(k, i)).toFixed(1)) + ' ' + sizes[i];
}

module.exports = { router, saveStateFile, saveSramFile, loadRomData, loadStateFile, loadSramFile, getRomPath, ROMS_DIR, SAVES_DIR };

