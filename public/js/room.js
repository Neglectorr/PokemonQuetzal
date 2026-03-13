/**
 * room.js - Premium Game Room Logic
 * Handles high-fidelity rendering, mobile input, and multiplayer synchronization.
 */

(function() {
    'use strict';
    console.log('[Antigravity] Room UI Version 2.1 (Headless Refactor) Loaded');

    const socket = io();
    const GBA_WIDTH = 240;
    const GBA_HEIGHT = 160;

    let mySlot = null;
    let isHost = false;
    let currentView = 'single'; // 'single' or 'grid'

    // Canvas & Contexts
    const mainCanvas = document.getElementById('main-canvas');
    const mainCtx = mainCanvas.getContext('2d', { alpha: false });
    mainCanvas.width = GBA_WIDTH;
    mainCanvas.height = GBA_HEIGHT;

    const gridCanvas = {
        1: document.getElementById('grid-canvas-1'),
        2: document.getElementById('grid-canvas-2'),
        3: document.getElementById('grid-canvas-3'),
        4: document.getElementById('grid-canvas-4')
    };
    const gridContexts = {};
    Object.keys(gridCanvas).forEach(slot => {
        const c = gridCanvas[slot];
        c.width = GBA_WIDTH;
        c.height = GBA_HEIGHT;
        gridContexts[slot] = c.getContext('2d', { alpha: false });
    });

    // Audio Setup
    let audioCtx = null;
    let nextAudioTime = 0;

    function initAudio() {
        if (!audioCtx) {
            audioCtx = new (window.AudioContext || window.webkitAudioContext)({
                sampleRate: 44100
            });
            nextAudioTime = audioCtx.currentTime;
        }
        if (audioCtx.state === 'suspended') {
            audioCtx.resume();
        }
    }

    function playAudioBuffer(buffer) {
        if (!audioCtx) return;
        
        // buffer is an ArrayBuffer (16-bit PCM Stereo)
        const pcm16 = new Int16Array(buffer);
        const float32 = new Float32Array(pcm16.length);
        for(let i=0; i<pcm16.length; i++) {
            float32[i] = pcm16[i] / 32768.0;
        }

        const audioBuffer = audioCtx.createBuffer(2, float32.length / 2, 44100);
        const left = audioBuffer.getChannelData(0);
        const right = audioBuffer.getChannelData(1);

        for(let i=0; i<float32.length/2; i++) {
            left[i] = float32[i*2];
            right[i] = float32[i*2 + 1];
        }

        const source = audioCtx.createBufferSource();
        source.buffer = audioBuffer;
        source.connect(audioCtx.destination);

        const currentTime = audioCtx.currentTime;
        if (nextAudioTime < currentTime) nextAudioTime = currentTime;
        
        source.start(nextAudioTime);
        nextAudioTime += audioBuffer.duration;
    }

    // ═══════════════════════════════════════
    // SOCKET EVENT HANDLERS
    // ═══════════════════════════════════════

    socket.on('connect', () => {
        updateConnectionStatus(true);
        const roomId = window.location.pathname.split('/').pop();
        socket.emit('join-room', { roomId });
    });

    socket.on('disconnect', () => updateConnectionStatus(false));

    socket.on('room-state', (room) => {
        isHost = room.isHost;
        mySlot = room.mySlot;
        
        document.getElementById('room-title').textContent = room.name;
        document.getElementById('room-rom-info').textContent = room.rom;
        
        updatePlayerList(room.players);
        updateStatusBadge(room.status);
        
        if (isHost) {
            document.getElementById('host-controls').classList.remove('hidden');
            document.getElementById('start-game-btn').classList.toggle('hidden', room.status === 'playing');
            document.getElementById('stop-game-btn').classList.toggle('hidden', room.status !== 'playing');
        }

        if (room.status === 'playing') {
            document.getElementById('canvas-overlay').classList.add('hidden');
        } else {
            document.getElementById('canvas-overlay').classList.remove('hidden');
        }
    });

    socket.on('frame', (data) => {
        // data: { slot, data: Buffer, width, height, raw: true }
        if (!window.firstFrameReceived) {
            console.log(`[Room] First frame received for slot ${data.slot}: ${data.width}x${data.height}`);
            window.firstFrameReceived = true;
        }
        renderFrame(data.slot, data.data, data.width, data.height);
    });

    socket.on('audio', (data) => {
        // Only play if it's our slot or if we are a spectator watching P1
        if (mySlot) {
            if (data.slot === mySlot) playAudioBuffer(data.data);
        } else if (data.slot === 1) {
            playAudioBuffer(data.data);
        }
    });

    socket.on('emulator-ready', () => {
        addSystemMessage("Server-side emulation started.");
        document.getElementById('canvas-overlay').classList.add('hidden');
        document.getElementById('macro-progress').classList.remove('active');
    });

    socket.on('emulator-error', (msg) => {
        showToast(msg, 'error');
        document.getElementById('macro-progress').classList.remove('active');
    });

    socket.on('chat-message', (msg) => addChatMessage(msg.username, msg.message));

    // ═══════════════════════════════════════
    // UI & RENDERING
    // ═══════════════════════════════════════

    function renderFrame(slot, frameData, width, height) {
        if (!frameData || !width || !height) return;

        // Check if this is a compressed WebP frame (starts with 'RIFF')
        const isWebP = (frameData.byteLength > 12 && 
                      new Uint8Array(frameData.slice(0, 4)).reduce((a, b) => a + String.fromCharCode(b), '') === 'RIFF');

        if (isWebP) {
            const blob = new Blob([frameData], { type: 'image/webp' });
            createImageBitmap(blob).then(bitmap => {
                if (currentView === 'single') {
                    if (slot === mySlot || (!mySlot && slot === 1)) {
                        mainCtx.drawImage(bitmap, 0, 0);
                    }
                } else {
                    const ctx = gridContexts[slot];
                    if (ctx) ctx.drawImage(bitmap, 0, 0);
                }
                bitmap.close();
            });
        } else {
            // Legacy/Raw RGBA fallback
            const uint8 = (frameData instanceof Uint8Array) ? frameData : new Uint8ClampedArray(frameData);
            if (uint8.length < width * height * 4) return;
            const imageData = new ImageData(uint8, width, height);
            
            if (currentView === 'single') {
                if (slot === mySlot || (!mySlot && slot === 1)) {
                    mainCtx.putImageData(imageData, 0, 0);
                }
            } else {
                const ctx = gridContexts[slot];
                if (ctx) ctx.putImageData(imageData, 0, 0);
            }
        }
    }

    function updatePlayerList(players) {
        const list = document.getElementById('player-list');
        list.innerHTML = '';
        
        players.forEach(p => {
            const card = document.createElement('div');
            card.className = `player-card ${p.id === socket.id ? 'is-me' : ''}`;
            card.innerHTML = `
                <div class="slot-indicator slot-${p.slot}">${p.slot}</div>
                <div class="player-name">${p.username} ${p.isHost ? '<span class="player-host-badge">HOST</span>' : ''}</div>
            `;
            list.appendChild(card);
        });
    }

    function updateStatusBadge(status) {
        const badge = document.getElementById('room-status-badge');
        badge.textContent = status.charAt(0).toUpperCase() + status.slice(1);
        badge.className = `room-status room-status--${status}`;
    }

    function updateConnectionStatus(connected) {
        const badge = document.getElementById('connection-status');
        badge.querySelector('.connection-dot').className = `connection-dot ${connected ? 'connection-dot--connected' : 'connection-dot--disconnected'}`;
        badge.querySelector('.connection-text').textContent = connected ? 'Connected' : 'Reconnecting...';
    }

    function addChatMessage(user, msg) {
        const container = document.getElementById('chat-messages');
        const div = document.createElement('div');
        div.className = 'chat-message';
        div.innerHTML = `<span class="chat-message-user">${user}:</span> <span class="chat-message-text">${msg}</span>`;
        container.appendChild(div);
        container.scrollTop = container.scrollHeight;
    }

    function addSystemMessage(msg) {
        const container = document.getElementById('chat-messages');
        const div = document.createElement('div');
        div.className = 'chat-message chat-message--system';
        div.textContent = msg;
        container.appendChild(div);
        container.scrollTop = container.scrollHeight;
    }

    function showToast(msg, type = 'info') {
        const container = document.getElementById('toast-container');
        const toast = document.createElement('div');
        toast.className = `toast toast--${type}`;
        toast.textContent = msg;
        container.appendChild(toast);
        setTimeout(() => toast.remove(), 4000);
    }

    // ═══════════════════════════════════════
    // INTERACTION
    // ═══════════════════════════════════════

    document.getElementById('start-game-btn').addEventListener('click', () => {
        console.log('[Room] Start Headless Session button clicked. Sending start-game event...');
        initAudio(); // User interaction required for audio
        socket.emit('start-game');
        document.getElementById('macro-progress').classList.add('active');
        document.getElementById('macro-progress-fill').style.width = '100%';
    });

    document.getElementById('stop-game-btn').addEventListener('click', () => socket.emit('stop-game'));
    
    document.getElementById('back-btn').addEventListener('click', () => window.location.href = '/dashboard');
    document.getElementById('leave-room-btn').addEventListener('click', () => window.location.href = '/dashboard');

    // Immersive HUD Auto-hide
    const canvasWrapper = document.getElementById('single-view');
    const gameHud = document.getElementById('game-hud');
    let hudTimeout;

    function showHud() {
        gameHud.classList.add('active');
        clearTimeout(hudTimeout);
        hudTimeout = setTimeout(() => {
            gameHud.classList.remove('active');
        }, 3000);
    }

    canvasWrapper.addEventListener('mousemove', showHud);
    canvasWrapper.addEventListener('touchstart', showHud);

    document.getElementById('hud-fullscreen').addEventListener('click', () => {
        const elem = document.querySelector('.game-column');
        if (elem.requestFullscreen) elem.requestFullscreen();
        else if (elem.webkitRequestFullscreen) elem.webkitRequestFullscreen();
    });

    document.getElementById('hud-gamepad').addEventListener('click', () => {
        document.getElementById('virtual-gamepad').classList.toggle('hidden');
    });

    document.getElementById('hud-scanlines').addEventListener('click', () => {
        document.getElementById('scanlines').classList.toggle('hidden');
    });

    document.getElementById('hud-save').addEventListener('click', () => {
        socket.emit('quick-save');
        showToast('Saving state...', 'info');
    });

    document.getElementById('hud-load').addEventListener('click', () => {
        socket.emit('quick-load');
        showToast('Loading state...', 'info');
    });

    document.getElementById('hud-screenshot').addEventListener('click', () => {
        const link = document.createElement('a');
        link.download = `quetzal-capture-${Date.now()}.png`;
        link.href = mainCanvas.toDataURL('image/png');
        link.click();
        showToast('Screenshot saved!', 'success');
    });

    document.getElementById('chat-send-btn').addEventListener('click', sendMessage);
    document.getElementById('chat-input').addEventListener('keypress', e => e.key === 'Enter' && sendMessage());

    function sendMessage() {
        const input = document.getElementById('chat-input');
        if (!input.value.trim()) return;
        socket.emit('chat-message', { message: input.value });
        input.value = '';
    }

    // View Toggling
    document.querySelectorAll('.view-toggle-btn').forEach(btn => {
        btn.addEventListener('click', () => {
            document.querySelectorAll('.view-toggle-btn').forEach(b => b.classList.remove('active'));
            btn.classList.add('active');
            currentView = btn.dataset.view;
            document.getElementById('single-view').classList.toggle('hidden', currentView !== 'single');
            document.getElementById('grid-view').classList.toggle('hidden', currentView !== 'grid');
        });
    });

    // Controls Modal
    const modal = document.getElementById('controls-modal');
    document.getElementById('controls-btn').addEventListener('click', () => modal.classList.add('active'));
    document.getElementById('controls-close').addEventListener('click', () => modal.classList.remove('active'));

    // Virtual Gamepad
    document.querySelectorAll('.virtual-gamepad button').forEach(btn => {
        const name = btn.dataset.btn;
        btn.addEventListener('touchstart', (e) => {
            e.preventDefault();
            GBAInput.setButton(name, true);
        });
        btn.addEventListener('touchend', (e) => {
            e.preventDefault();
            GBAInput.setButton(name, false);
        });
    });

    // Global Input Integration (assumes input.js is loaded)
    window.addEventListener('keydown', () => initAudio(), { once: true });

    GBAInput.init((buttons) => {
        if (mySlot) {
            socket.emit('player-input', { buttons });
        }
    });

})();
