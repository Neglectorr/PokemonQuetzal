/**
 * Dashboard Client - Lobby management, room listing, create/join rooms
 */
(function() {
  let currentUser = null;
  let socket = null;
  let rooms = [];
  let availableRoms = [];

  // ═══════════════════════════════════════
  // INITIALIZATION
  // ═══════════════════════════════════════
  async function init() {
    // Check auth
    try {
      const res = await fetch('/api/me');
      if (!res.ok) {
        window.location.href = '/';
        return;
      }
      const data = await res.json();
      currentUser = data.user;
      updateUserUI();
    } catch (err) {
      window.location.href = '/';
      return;
    }

    // Load ROMs
    await loadRoms();

    // Connect socket
    connectSocket();

    // Load initial room list
    await loadRooms();

    // Setup event listeners
    setupEventListeners();
  }

  // ═══════════════════════════════════════
  // USER UI
  // ═══════════════════════════════════════
  function updateUserUI() {
    const nameEl = document.getElementById('user-name');
    const avatarEl = document.getElementById('user-avatar');
    if (nameEl) nameEl.textContent = currentUser.username;
    if (avatarEl) {
      avatarEl.textContent = currentUser.username.charAt(0).toUpperCase();
    }
  }

  // ═══════════════════════════════════════
  // SOCKET CONNECTION
  // ═══════════════════════════════════════
  function connectSocket() {
    socket = io({ withCredentials: true });

    socket.on('connect', () => {
      updateConnectionStatus(true);
    });

    socket.on('disconnect', () => {
      updateConnectionStatus(false);
    });

    // Real-time room list updates
    socket.on('room-list-update', (roomData) => {
      updateRoomInList(roomData);
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
  // ROOM LIST
  // ═══════════════════════════════════════
  async function loadRooms() {
    try {
      const res = await fetch('/api/rooms', { credentials: 'include' });
      const data = await res.json();
      rooms = data.rooms || [];
      renderRooms();
    } catch (err) {
      console.error('Failed to load rooms:', err);
      showToast('Failed to load rooms', 'error');
    }
  }

  function updateRoomInList(roomData) {
    const index = rooms.findIndex(r => r.id === roomData.id);
    if (index >= 0) {
      rooms[index] = { ...rooms[index], ...roomData };
    } else {
      rooms.push(roomData);
    }
    renderRooms();
  }

  function renderRooms() {
    const grid = document.getElementById('rooms-grid');
    const emptyState = document.getElementById('empty-state');

    if (rooms.length === 0) {
      grid.style.display = 'none';
      emptyState.style.display = 'block';
      return;
    }

    grid.style.display = 'grid';
    emptyState.style.display = 'none';

    grid.innerHTML = rooms.map(room => `
      <div class="glass-card room-card" data-room-id="${room.id}">
        <div class="room-card-header">
          <span class="room-name">${escapeHtml(room.name)}</span>
          <span class="room-status room-status--${room.status}">${room.status.toUpperCase()}</span>
        </div>
        <div class="room-meta">
          <div class="room-meta-row">
            <span class="room-meta-icon">👑</span>
            <span>${escapeHtml(room.host?.username || 'Unknown')}</span>
          </div>
          <div class="room-meta-row">
            <span class="room-meta-icon">🎮</span>
            <span>${escapeHtml(room.rom || 'No ROM')}</span>
          </div>
          <div class="room-meta-row">
            <span class="room-meta-icon">🔗</span>
            <span>${room.romGroup || 'Unknown'}</span>
          </div>
        </div>
        <div class="room-players">
          ${renderPlayerDots(room.playerCount || 0, room.maxPlayers || 4)}
        </div>
        <div class="room-actions">
          <button class="btn btn-sm btn-primary join-room-btn" data-room-id="${room.id}">Join</button>
          <button class="btn btn-sm btn-secondary spectate-room-btn" data-room-id="${room.id}">Spectate</button>
        </div>
      </div>
    `).join('');

    // Add click handlers
    grid.querySelectorAll('.join-room-btn').forEach(btn => {
      btn.addEventListener('click', (e) => {
        e.stopPropagation();
        joinRoom(btn.dataset.roomId, 'player');
      });
    });

    grid.querySelectorAll('.spectate-room-btn').forEach(btn => {
      btn.addEventListener('click', (e) => {
        e.stopPropagation();
        joinRoom(btn.dataset.roomId, 'spectator');
      });
    });
  }

  function renderPlayerDots(filled, max) {
    let html = '';
    for (let i = 0; i < max; i++) {
      if (i < filled) {
        html += `<div class="room-player-dot room-player-dot--filled">P${i + 1}</div>`;
      } else {
        html += `<div class="room-player-dot room-player-dot--empty">+</div>`;
      }
    }
    return html;
  }

  // ═══════════════════════════════════════
  // ROM LOADING
  // ═══════════════════════════════════════
  async function loadRoms() {
    try {
      const res = await fetch('/api/files/roms', { credentials: 'include' });
      const data = await res.json();
      availableRoms = data.roms || [];
      
      const select = document.getElementById('rom-select');
      if (availableRoms.length === 0) {
        select.innerHTML = '<option value="">No ROMs found — place .gba files in /roms</option>';
      } else {
        select.innerHTML = availableRoms.map(rom => 
          `<option value="${escapeHtml(rom.filename)}">${escapeHtml(rom.name)} (${rom.sizeFormatted})</option>`
        ).join('');
      }
    } catch (err) {
      console.error('Failed to load ROMs:', err);
    }
  }

  // ═══════════════════════════════════════
  // CREATE & JOIN ROOMS
  // ═══════════════════════════════════════
  async function createRoom(name, rom, maxPlayers) {
    try {
      const res = await fetch('/api/rooms', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        credentials: 'include',
        body: JSON.stringify({ name, rom, maxPlayers })
      });

      const data = await res.json();
      if (res.ok) {
        showToast(`Room "${name}" created!`, 'success');
        // Auto-join the room we just created
        window.location.href = `/room/${data.id}`;
      } else {
        showToast(data.error || 'Failed to create room', 'error');
      }
    } catch (err) {
      showToast('Connection error', 'error');
    }
  }

  function joinRoom(roomId, role) {
    window.location.href = `/room/${roomId}?role=${role}`;
  }

  // ═══════════════════════════════════════
  // EVENT LISTENERS
  // ═══════════════════════════════════════
  function setupEventListeners() {
    // Create room button
    document.getElementById('create-room-btn').addEventListener('click', () => {
      document.getElementById('create-modal').classList.add('active');
    });

    // Cancel modal
    document.getElementById('cancel-modal-btn').addEventListener('click', () => {
      document.getElementById('create-modal').classList.remove('active');
    });

    // Click outside modal
    document.getElementById('create-modal').addEventListener('click', (e) => {
      if (e.target === e.currentTarget) {
        e.currentTarget.classList.remove('active');
      }
    });

    // Create room form
    document.getElementById('create-room-form').addEventListener('submit', (e) => {
      e.preventDefault();
      const name = document.getElementById('room-name-input').value.trim();
      const rom = document.getElementById('rom-select').value;
      const maxPlayers = parseInt(document.getElementById('max-players-select').value);

      if (!name) {
        showToast('Please enter a room name', 'warning');
        return;
      }
      if (!rom) {
        showToast('Please select a ROM', 'warning');
        return;
      }

      createRoom(name, rom, maxPlayers);
      document.getElementById('create-modal').classList.remove('active');
    });

    // Logout
    document.getElementById('logout-btn').addEventListener('click', async () => {
      await fetch('/auth/logout', { method: 'POST', credentials: 'include' });
      window.location.href = '/';
    });

    // Keyboard: Escape closes modal
    document.addEventListener('keydown', (e) => {
      if (e.key === 'Escape') {
        document.getElementById('create-modal').classList.remove('active');
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

  // Initialize on load
  init();
})();
