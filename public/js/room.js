/**
 * Game Room Client
 * Canvas rendering, Socket.io communication, frame display, chat, game controls
 */
(function() {
  const GBA_WIDTH = 240;
  const GBA_HEIGHT = 160;
  const SCALE = 3; // Default canvas scale

  let socket = null;
  let currentUser = null;
  let roomId = null;
  let roomState = null;
  let mySlot = null;
  let isHost = false;
  let currentView = 'single'; // 'single' | 'grid'

  // Canvas references
  let mainCanvas, mainCtx;
  const gridCanvases = {};
  const gridContexts = {};
  
  // Audio state
  let audioContext = null;
  let nextAudioTime = 0;

  // ═══════════════════════════════════════
  // INITIALIZATION
  // ═══════════════════════════════════════
  async function init() {
    // Extract room ID from URL
    const pathParts = window.location.pathname.split('/');
    roomId = pathParts[pathParts.length - 1];
    const role = new URLSearchParams(window.location.search).get('role') || 'player';

    if (!roomId) {
      window.location.href = '/dashboard';
      return;
    }

    // Check auth
    try {
      const res = await fetch('/api/me');
      if (!res.ok) { window.location.href = '/'; return; }
      const data = await res.json();
      currentUser = data.user;
    } catch (err) {
      window.location.href = '/';
      return;
    }

    // Setup canvases
    setupCanvases();

    // Connect socket and join room
    connectSocket(role);

    // Setup event listeners
    setupEventListeners();

    // Initialize input handler
    GBAInput.init((buttons) => {
      if (socket && socket.connected) {
        socket.emit('player-input', { buttons });
      }
    });

    // Interaction to enable audio (Browser policy)
    document.addEventListener('mousedown', initAudio, { once: true });
    document.addEventListener('keydown', initAudio, { once: true });
    document.addEventListener('touchstart', initAudio, { once: true });
  }

  // ═══════════════════════════════════════
  // CANVAS SETUP
  // ═══════════════════════════════════════
  function setupCanvases() {
    mainCanvas = document.getElementById('main-canvas');
    mainCtx = mainCanvas.getContext('2d');

    // Scale main canvas for crisp pixel art
    mainCanvas.width = GBA_WIDTH;
    mainCanvas.height = GBA_HEIGHT;
    mainCtx.imageSmoothingEnabled = false;

    // Setup grid canvases
    for (let i = 1; i <= 4; i++) {
      const canvas = document.getElementById(`grid-canvas-${i}`);
      if (canvas) {
        canvas.width = GBA_WIDTH;
        canvas.height = GBA_HEIGHT;
        canvas.style.width = '100%';
        const ctx = canvas.getContext('2d');
        ctx.imageSmoothingEnabled = false;
        gridCanvases[i] = canvas;
        gridContexts[i] = ctx;
      }
    }

    // Fill with initial black
    mainCtx.fillStyle = '#0f0f23';
    mainCtx.fillRect(0, 0, GBA_WIDTH, GBA_HEIGHT);
    for (const ctx of Object.values(gridContexts)) {
      ctx.fillStyle = '#0f0f23';
      ctx.fillRect(0, 0, GBA_WIDTH, GBA_HEIGHT);
    }
  }

  // ═══════════════════════════════════════
  // SOCKET CONNECTION
  // ═══════════════════════════════════════
  function connectSocket(role) {
    socket = io({ withCredentials: true });

    socket.on('connect', () => {
      updateConnectionStatus(true);
      // Join the room
      socket.emit('join-room', {
        roomId,
        role,
        rom: null // Server assigns ROM from room
      });
    });

    socket.on('disconnect', () => {
      updateConnectionStatus(false);
      addSystemMessage('Disconnected from server. Attempting to reconnect...');
    });

    socket.on('reconnect', () => {
      addSystemMessage('Reconnected!');
      socket.emit('join-room', { roomId, role: 'player' });
    });

    // Room state updates
    socket.on('room-state', (state) => {
      roomState = state;
      updateRoomUI(state);

      // MOBILE OPTIMIZATION: Maximize canvas and disable swiping when playing
      const isMobile = GBAInput.getMobile();
      if (isMobile && state.status === 'playing') {
        document.body.classList.add('canvas-locked');
      } else {
        document.body.classList.remove('canvas-locked');
      }
    });

    // Frame data from emulator
    socket.on('frame', (data) => {
      const isMobile = GBAInput.getMobile();
      // On mobile, only render our own slot (or Slot 1 if not assigned) to save resources
      if (isMobile) {
        if (mySlot) {
          if (data.slot === mySlot) renderFrame(data.slot, data.data, data.width, data.height, data.raw);
        } else if (data.slot === 1) {
          renderFrame(data.slot, data.data, data.width, data.height, data.raw);
        }
        return;
      }
      
      renderFrame(data.slot, data.data, data.width, data.height, data.raw);
    });

    // Chat messages
    socket.on('chat-message', (msg) => {
      addChatMessage(msg.username, msg.message);
    });

    // Emulator events
    socket.on('emulator-ready', (data) => {
      addSystemMessage(`Emulator ready! ${data.players} player(s) connected.`);
      completeMacroProgress();
      document.getElementById('canvas-overlay').classList.add('hidden');
    });

    socket.on('emulator-error', (data) => {
      addSystemMessage(`⚠️ Emulator error: ${data.message}`);
      showToast(data.message, 'error');
    });

    // Audio stream from backend (Raw PCM 16-bit Stereo 44100Hz)
    socket.on('audio', (data) => {
        // Only play if it's our slot, or if we are Slot 1 (for host/spectators)
        if (mySlot) {
            if (data.slot === mySlot) playAudioBuffer(data.data);
        } else if (data.slot === 1) {
            playAudioBuffer(data.data);
        }
    });

    // Errors
    socket.on('error', (data) => {
      showToast(data.message, 'error');
    });
  }

  function updateConnectionStatus(connected) {
    const statusEl = document.getElementById('connection-status');
    if (!statusEl) return;
    const dot = statusEl.querySelector('.connection-dot');
    const text = statusEl.querySelector('.connection-text');
    if (connected) {
      dot.className = 'connection-dot connection-dot--connected';
      text.textContent = 'Connected';
    } else {
      dot.className = 'connection-dot connection-dot--disconnected';
      text.textContent = 'Disconnected';
    }
  }

  // ═══════════════════════════════════════
  // FRAME RENDERING
  // ═══════════════════════════════════════
  function renderFrame(slot, frameData, width, height, raw) {
    if (!frameData) return;

    if (raw && width && height) {
      // Raw RGBA binary data (ArrayBuffer)
      const imageData = new ImageData(new Uint8ClampedArray(frameData), width, height);
      
      if (currentView === 'single') {
        if (slot === mySlot || (!mySlot && slot === 1)) {
          mainCtx.putImageData(imageData, 0, 0);
        }
      } else {
        const targetCtx = gridContexts[slot];
        if (targetCtx) {
          targetCtx.putImageData(imageData, 0, 0);
        }
      }
    } else {
      // Legacy Base64 PNG/JPEG
      const img = new Image();
      img.onload = () => {
        if (currentView === 'single') {
          if (slot === mySlot || (!mySlot && slot === 1)) {
            mainCtx.drawImage(img, 0, 0, GBA_WIDTH, GBA_HEIGHT);
          }
        } else {
          const targetCtx = gridContexts[slot];
          if (targetCtx) {
            targetCtx.drawImage(img, 0, 0, GBA_WIDTH, GBA_HEIGHT);
          }
        }
      };
      img.src = 'data:image/png;base64,' + frameData;
    }
  }

  // ═══════════════════════════════════════
  // AUDIO PLAYBACK
  // ═══════════════════════════════════════
  async function playAudioBuffer(buffer) {
    if (!audioContext) return;
    
    // Resume context if suspended (browser policy)
    if (audioContext.state === 'suspended') {
        try { await audioContext.resume(); } catch(e) { return; }
    }

    // buffer is an ArrayBuffer from Socket.io (Int16 Stereo)
    const int16Array = new Int16Array(buffer);
    const frameCount = int16Array.length / 2;
    const audioBuffer = audioContext.createBuffer(2, frameCount, 44100);
    
    const leftChannel = audioBuffer.getChannelData(0);
    const rightChannel = audioBuffer.getChannelData(1);
    
    for (let i = 0; i < frameCount; i++) {
        leftChannel[i] = int16Array[i * 2] / 32768.0;
        rightChannel[i] = int16Array[i * 2 + 1] / 32768.0;
    }

    const source = audioContext.createBufferSource();
    source.buffer = audioBuffer;
    source.connect(audioContext.destination);

    // Schedule playback to avoid gaps
    const currentTime = audioContext.currentTime;
    if (nextAudioTime < currentTime) {
        nextAudioTime = currentTime + 0.05; // Small buffer for network jitter
    }
    
    source.start(nextAudioTime);
    nextAudioTime += audioBuffer.duration;
  }

  function initAudio() {
    if (audioContext) return;
    audioContext = new (window.AudioContext || window.webkitAudioContext)({
        sampleRate: 44100
    });
    addSystemMessage('🔊 Audio initialized.');
  }

  // ═══════════════════════════════════════
  // ROOM UI UPDATES
  // ═══════════════════════════════════════
  function updateRoomUI(state) {
    // Title
    document.getElementById('room-title').textContent = state.name;
    document.title = `${state.name} | Project Antigravity`;

    // Status badge
    const badge = document.getElementById('room-status-badge');
    badge.textContent = state.status.toUpperCase();
    badge.className = `room-status room-status--${state.status}`;

    // ROM info
    document.getElementById('room-rom-info').textContent = state.rom || 'No ROM';

    // Determine if we are the host
    isHost = currentUser && state.host && state.host.id === currentUser.id;

    // Find our player slot
    if (currentUser) {
      const myPlayer = state.players.find(p => p.id === currentUser.id);
      if (myPlayer) mySlot = myPlayer.slot;
    }

    // Show/hide game controls for host
    const startBtn = document.getElementById('start-game-btn');
    const stopBtn = document.getElementById('stop-game-btn');
    if (isHost) {
      if (state.status === 'waiting') {
        startBtn.classList.remove('hidden');
        stopBtn.classList.add('hidden');
      } else {
        startBtn.classList.add('hidden');
        stopBtn.classList.remove('hidden');
      }
    } else {
      startBtn.classList.add('hidden');
      stopBtn.classList.add('hidden');
    }

    // Player list
    const playerList = document.getElementById('player-list');
    playerList.innerHTML = state.players.map(p => `
      <div class="player-item">
        <span class="player-slot player-slot--${p.slot}">P${p.slot}</span>
        <span class="player-name">${escapeHtml(p.username)}</span>
        ${state.host && p.id === state.host.id ? '<span class="player-host-badge">HOST</span>' : ''}
      </div>
    `).join('');

    // Add spectators
    if (state.spectators && state.spectators.length > 0) {
      playerList.innerHTML += '<div style="margin-top:8px;font-size:0.75rem;color:var(--text-muted);">Spectators:</div>';
      playerList.innerHTML += state.spectators.map(s => `
        <div class="player-item" style="opacity:0.6;">
          <span class="player-slot" style="background:var(--text-muted);">👁</span>
          <span class="player-name">${escapeHtml(s.username)}</span>
        </div>
      `).join('');
    }

    // Update grid labels & visibility
    updateGridLayout(state.maxPlayers);
    for (let i = 1; i <= 4; i++) {
      const label = document.getElementById(`grid-label-${i}`);
      if (label) {
        const player = state.players.find(p => p.slot === i);
        label.textContent = player ? player.username : `Slot ${i} (empty)`;
      }
    }

    // Canvas overlay
    const overlay = document.getElementById('canvas-overlay');
    if (state.status === 'playing') {
      overlay.classList.add('hidden');
    } else {
      overlay.classList.remove('hidden');
      overlay.querySelector('h3').textContent = state.status === 'waiting' 
        ? '⏳ Waiting for game to start' 
        : '⏸ Game paused';
      overlay.querySelector('p').textContent = isHost 
        ? 'Click "Start Game" when ready' 
        : 'The host needs to start the game';
    }
  }

  function updateGridLayout(maxPlayers) {
    const gridView = document.getElementById('grid-view');
    if (!gridView) return;

    // Apply specific layout class
    gridView.classList.remove('grid-view--2', 'grid-view--3', 'grid-view--4');
    gridView.classList.add(`grid-view--${maxPlayers}`);

    // Hide containers beyond maxPlayers
    for (let i = 1; i <= 4; i++) {
      const canvas = gridCanvases[i];
      if (canvas && canvas.parentElement) {
        if (i <= maxPlayers) {
          canvas.parentElement.style.display = 'block';
        } else {
          canvas.parentElement.style.display = 'none';
        }
      }
    }
  }

  // ═══════════════════════════════════════
  // CHAT
  // ═══════════════════════════════════════
  function addChatMessage(username, message) {
    const container = document.getElementById('chat-messages');
    const div = document.createElement('div');
    div.className = 'chat-message';
    div.innerHTML = `<span class="chat-message-user">${escapeHtml(username)}</span>: <span class="chat-message-text">${escapeHtml(message)}</span>`;
    container.appendChild(div);
    container.scrollTop = container.scrollHeight;
  }

  function addSystemMessage(message) {
    const container = document.getElementById('chat-messages');
    const div = document.createElement('div');
    div.className = 'chat-message chat-message--system';
    div.textContent = message;
    container.appendChild(div);
    container.scrollTop = container.scrollHeight;
  }

  // ═══════════════════════════════════════
  // EVENT LISTENERS
  // ═══════════════════════════════════════
  function setupEventListeners() {
    // Back button
    document.getElementById('back-btn').addEventListener('click', () => {
      if (socket) socket.emit('leave-room');
      window.location.href = '/dashboard';
    });

    // Leave button
    document.getElementById('leave-room-btn').addEventListener('click', () => {
      if (socket) socket.emit('leave-room');
      window.location.href = '/dashboard';
    });

    // Controls Modal
    const controlsBtn = document.getElementById('controls-btn');
    const controlsModal = document.getElementById('controls-modal');
    const controlsClose = document.getElementById('controls-close');

    if (controlsBtn && controlsModal) {
      controlsBtn.addEventListener('click', () => {
        controlsModal.classList.remove('hidden');
      });
    }

    if (controlsClose && controlsModal) {
      controlsClose.addEventListener('click', () => {
        controlsModal.classList.add('hidden');
      });
      // Close on overlay click
      controlsModal.addEventListener('click', (e) => {
        if (e.target === controlsModal) controlsModal.classList.add('hidden');
      });
    }

    // Start game (host)
    document.getElementById('start-game-btn').addEventListener('click', () => {
      if (socket) {
        socket.emit('start-game');
        startMacroProgress();
      }
    });

    // Stop game (host)
    document.getElementById('stop-game-btn').addEventListener('click', () => {
      if (socket) socket.emit('stop-game');
    });

    // View toggle
    document.querySelectorAll('.view-toggle-btn').forEach(btn => {
      btn.addEventListener('click', () => {
        document.querySelectorAll('.view-toggle-btn').forEach(b => b.classList.remove('active'));
        btn.classList.add('active');

        const view = btn.dataset.view;
        currentView = view;

        if (view === 'single') {
          document.getElementById('single-view').classList.remove('hidden');
          document.getElementById('grid-view').classList.add('hidden');
        } else {
          document.getElementById('single-view').classList.add('hidden');
          document.getElementById('grid-view').classList.remove('hidden');
        }
      });
    });

    // Chat
    const chatInput = document.getElementById('chat-input');
    const chatSend = document.getElementById('chat-send-btn');

    function sendChat() {
      const msg = chatInput.value.trim();
      if (msg && socket) {
        socket.emit('chat-message', { message: msg });
        chatInput.value = '';
      }
    }

    chatInput.addEventListener('keydown', (e) => {
      if (e.key === 'Enter') {
        e.preventDefault();
        sendChat();
      }
    });

    // Quick Save / Load hotkeys
    window.addEventListener('keydown', (e) => {
      const isS = e.key.toLowerCase() === 's';
      const isL = e.key.toLowerCase() === 'l';

      if (e.ctrlKey && (isS || isL)) {
        e.preventDefault(); // This OVERRIDES the default browser Save/Search functions
        
        if (socket && socket.connected && roomState && roomState.status === 'playing') {
          if (isS) {
            socket.emit('quick-save');
            showToast('Attempting Quick Save...', 'info');
          } else {
            socket.emit('quick-load');
            showToast('Attempting Quick Load...', 'info');
          }
        }
      }
    });
  }

  // ═══════════════════════════════════════
  // UTILITIES
  // ═══════════════════════════════════════
  function escapeHtml(text) {
    const div = document.createElement('div');
    div.textContent = text;
    return div.innerHTML;
  }

  function showToast(message, type = 'info') {
    const container = document.getElementById('toast-container');
    if (!container) return;
    const toast = document.createElement('div');
    toast.className = `toast toast--${type}`;
    toast.textContent = message;
    container.appendChild(toast);
    setTimeout(() => {
      toast.style.opacity = '0';
      toast.style.transform = 'translateX(20px)';
      toast.style.transition = 'all 0.3s ease';
      setTimeout(() => toast.remove(), 300);
    }, 4000);
  }

  // ═══════════════════════════════════════
  // MACRO PROGRESS BAR
  // ═══════════════════════════════════════
  let macroProgressInterval = null;
  function startMacroProgress() {
    const container = document.getElementById('macro-progress');
    const fill = document.getElementById('macro-progress-fill');
    const status = document.getElementById('macro-progress-status');
    if (!container || !fill || !status) return;

    container.classList.add('active');
    fill.style.width = '0%';
    status.textContent = 'Spawning instances...';

    const startTime = Date.now();
    const duration = 20000; // Estimated 20s for 4 players (increased due to server delays)

    if (macroProgressInterval) clearInterval(macroProgressInterval);
    
    macroProgressInterval = setInterval(() => {
      const elapsed = Date.now() - startTime;
      let progress = (elapsed / duration) * 90; // Animate to 90%
      
      if (progress >= 90) {
        progress = 90;
        status.textContent = 'Linking windows...';
        clearInterval(macroProgressInterval);
      } else if (progress > 60) {
        status.textContent = 'Loading ROMs...';
      } else if (progress > 30) {
        status.textContent = 'Synchronizing saves...';
      }

      fill.style.width = `${progress}%`;
    }, 100);
  }

  function completeMacroProgress() {
    const container = document.getElementById('macro-progress');
    const fill = document.getElementById('macro-progress-fill');
    const status = document.getElementById('macro-progress-status');
    
    if (macroProgressInterval) clearInterval(macroProgressInterval);
    
    if (fill) fill.style.width = '100%';
    if (status) status.textContent = 'Game Ready!';
    
    setTimeout(() => {
      if (container) container.classList.remove('active');
    }, 1000);
  }

  // Handle page unload
  window.addEventListener('beforeunload', () => {
    if (socket) {
      socket.emit('leave-room');
      socket.disconnect();
    }
    GBAInput.destroy();
  });

  // Initialize
  init();
})();
