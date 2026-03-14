/**
 * Project Antigravity - Server Entry Point
 * Multi-instance GBA Cloud Platform with mGBA emulation
 */
const express = require('express');
const http = require('http');
const path = require('path');
const { Server } = require('socket.io');
const session = require('express-session');
const passport = require('passport');
const cors = require('cors');
const fs = require('fs');

require('dotenv').config({ path: path.join(__dirname, '..', '.env') });

// Ensure required directories exist
const dirs = [
  path.join(__dirname, '..', 'roms'),
  path.join(__dirname, '..', 'saves'),
  path.join(__dirname, '..', 'sessions')
];
dirs.forEach(dir => { if (!fs.existsSync(dir)) fs.mkdirSync(dir, { recursive: true }); });

const app = express();
const server = http.createServer(app);

// Trust proxy for Caddy/AMP reverse proxy
if (process.env.TRUST_PROXY === 'true') {
  app.set('trust proxy', 1);
}

// Session configuration
const FileStore = require('session-file-store')(session);
let sessionStore;
try {
  sessionStore = new FileStore({
    path: path.join(__dirname, '..', 'sessions'),
    ttl: 86400,
    retries: 5,
    reapInterval: -1 // Disable automatic cleanup to prevent race conditions on Windows
  });
} catch (e) {
  console.warn('File session store unavailable, using memory store:', e.message);
  sessionStore = new session.MemoryStore();
}

const sessionMiddleware = session({
  store: sessionStore,
  secret: process.env.SESSION_SECRET || 'dev-secret-change-me',
  resave: false,
  saveUninitialized: false,
  cookie: {
    secure: process.env.NODE_ENV === 'production',
    httpOnly: true,
    maxAge: 24 * 60 * 60 * 1000, // 24 hours
    sameSite: 'lax'
  }
});

// Middleware
app.use(cors({
  origin: process.env.CLIENT_ORIGIN || 'http://localhost:3000',
  credentials: true
}));
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(sessionMiddleware);
app.use(passport.initialize());
app.use(passport.session());

// COOP/COEP headers required for mGBA WASM SharedArrayBuffer (Emscripten threads)
app.use((req, res, next) => {
  res.setHeader('Cross-Origin-Opener-Policy', 'same-origin');
  res.setHeader('Cross-Origin-Embedder-Policy', 'require-corp');
  next();
});

// Serve mGBA WASM dist files at /mgba/
const MGBA_DIST = path.join(__dirname, '..', 'node_modules', '@thenick775', 'mgba-wasm', 'dist');

const mgbaHeaders = (res) => {
  res.setHeader('Cross-Origin-Opener-Policy', 'same-origin');
  res.setHeader('Cross-Origin-Embedder-Policy', 'require-corp');
  res.setHeader('Cross-Origin-Resource-Policy', 'same-origin');
};

let _patchedMgbaJs = null;
app.get('/mgba/mgba.js', (req, res) => {
  if (!_patchedMgbaJs) {
    const raw = fs.readFileSync(path.join(MGBA_DIST, 'mgba.js'), 'utf8');
    
    // Inject a robust fake AudioContext into all workers (and main frame)
    // This perfectly satisfies mGBA/SDL's initialization requirements so loadGame() returns true,
    // but the fake ScriptProcessorNode NEVER fires onaudioprocess, totally bypassing the Wasm crash!
    const patchPayload = `
      self.AudioContext = class FakeAudioContext {
        constructor() {
          this.sampleRate = 44100;
          this.state = 'running';
          this.destination = { maxChannelCount: 2 };
        }
        createScriptProcessor(bufferSize, numInput, numOutput) {
          return {
            connect: function() {},
            disconnect: function() {},
            get onaudioprocess() { return this._cb; },
            set onaudioprocess(cb) { this._cb = cb; } // Store the WASM callback but NEVER fire it
          };
        }
        createGain() { return { connect: function() {}, gain: { value: 1 } }; }
        resume() { return Promise.resolve(); }
        suspend() { return Promise.resolve(); }
        close() { return Promise.resolve(); }
      };
      self.webkitAudioContext = self.AudioContext;
    `;
    
    _patchedMgbaJs = patchPayload + "\n" + raw;
    console.log('[Server] mgba.js patched: FakeAudioContext injected to safely silence audio callbacks');
  }
  mgbaHeaders(res);
  res.setHeader('Content-Type', 'application/javascript');
  res.setHeader('Cache-Control', 'no-store');
  res.send(_patchedMgbaJs);
});

app.use('/mgba', express.static(MGBA_DIST, { setHeaders: mgbaHeaders }));


// Static files
app.use('/js', express.static(path.join(__dirname, '../public/js')));
app.use('/wasm', express.static(path.join(__dirname, '../node_modules/@thenick775/mgba-wasm/dist')));
app.use('/roms-internal', express.static(path.join(__dirname, '../roms'))); // Internal bridge use
app.use(express.static(path.join(__dirname, '..', 'public')));


// Auth routes
const auth = require('./auth');
auth.configure(passport);
app.use(auth.autoLogin); // Auto-login in dev mode
app.use('/auth', auth.router);

// API routes
const lobby = require('./lobby');
app.use('/api', lobby.router);

const fileManager = require('./fileManager');
app.use('/api/files', fileManager.router);

// Page routes - serve HTML pages
app.get('/dashboard', (req, res) => {
  if (!req.isAuthenticated || !req.isAuthenticated()) {
    return res.redirect('/');
  }
  res.sendFile(path.join(__dirname, '..', 'public', 'dashboard.html'));
});

app.get('/room/:id', (req, res) => {
  if (!req.isAuthenticated || !req.isAuthenticated()) {
    return res.redirect('/');
  }
  
  const room = lobby.getRoom(req.params.id);
  if (!room) {
    return res.redirect('/dashboard');
  }
  
  res.sendFile(path.join(__dirname, '..', 'public', 'room.html'));
});

// User info endpoint
app.get('/api/me', (req, res) => {
  if (!req.isAuthenticated || !req.isAuthenticated()) {
    return res.status(401).json({ error: 'Not authenticated' });
  }
  res.json({ user: req.user });
});

// Socket.io setup
const io = new Server(server, {
  cors: {
    origin: (origin, callback) => {
        // Allow if origin is same-origin (undefined) or matches any of our known origins
        const allowedOrigins = [
            process.env.CLIENT_ORIGIN,
            'http://localhost:3000',
            'https://roms.wesleypostma.nl'
        ].filter(Boolean);

        if (!origin || allowedOrigins.includes(origin) || process.env.NODE_ENV === 'development') {
            callback(null, true);
        } else {
            console.warn(`[Socket.io] CORS blocked for origin: ${origin}`);
            callback(new Error('Not allowed by CORS'));
        }
    },
    methods: ["GET", "POST"],
    credentials: true
  },
  maxHttpBufferSize: 1e7 // 10MB for frame data
});

// Share session with Socket.io securely without crashing on headers during handshake
io.use((socket, next) => {
  const req = socket.request;
  const res = req.res || {
    getHeader: () => {},
    setHeader: () => {},
    on: () => {},
    end: () => {}
  };
  sessionMiddleware(req, res, next);
});

// Socket handlers
const sockets = require('./sockets');
sockets.init(io, lobby);

// Periodic cleanup of orphaned lobby directories (every 30 minutes)
setInterval(() => {
    const LOBBIES_DIR = path.join(__dirname, '..', 'lobbies');
    if (!fs.existsSync(LOBBIES_DIR)) return;

    console.log('[Cleanup] Running periodic sweep for orphaned lobby directories...');
    const rooms = fs.readdirSync(LOBBIES_DIR);
    
    let deletedCount = 0;
    rooms.forEach(roomId => {
        // If lobby doesn't exist in the memory store, and no emulator is active, it's an orphan
        if (!lobby.getRoom(roomId)) {
            try {
                const lobbyPath = path.join(LOBBIES_DIR, roomId);
                fs.rmSync(lobbyPath, { recursive: true, force: true });
                deletedCount++;
            } catch (e) {
                // Ignore errors (might be in use)
            }
        }
    });

    if (deletedCount > 0) {
        console.log(`[Cleanup] Removed ${deletedCount} orphaned lobby directories.`);
    }
}, 30 * 60 * 1000);

// Start server
const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
  console.log(`
  ╔══════════════════════════════════════════════╗
  ║     Project Antigravity - GBA Cloud          ║
  ║     Server running on port ${PORT}              ║
  ║     Mode: ${process.env.NODE_ENV || 'development'}                    ║
  ║     Debug Auth: ${process.env.DEBUG_AUTH === 'true' ? 'ENABLED' : 'DISABLED'}                  ║
  ╚══════════════════════════════════════════════╝
  `);
});

process.on('uncaughtException', (err) => {
    console.error('[CRITICAL] Uncaught Exception:', err.stack);
});

process.on('unhandledRejection', (reason, promise) => {
    console.error('[CRITICAL] Unhandled Rejection at:', promise, 'reason:', reason);
});
