/**
 * GBA Input Handler
 * Maps keyboard, gamepad, AND touch inputs to GBA button bitmask
 * Provides immediate visual feedback for input latency compensation
 * Touch controls use multi-touch for simultaneous button presses
 */
const GBAInput = (function() {
  // GBA button bitmask values
  const BUTTONS = {
    A:      0x001,
    B:      0x002,
    SELECT: 0x004,
    START:  0x008,
    RIGHT:  0x010,
    LEFT:   0x020,
    UP:     0x040,
    DOWN:   0x080,
    R:      0x100,
    L:      0x200
  };

  // Default keyboard mapping (EmulatorJS style)
  const KEY_MAP = {
    'ArrowUp':    BUTTONS.UP,
    'ArrowDown':  BUTTONS.DOWN,
    'ArrowLeft':  BUTTONS.LEFT,
    'ArrowRight': BUTTONS.RIGHT,
    'KeyX':       BUTTONS.A,
    'KeyZ':       BUTTONS.B,
    'KeyS':       BUTTONS.A,   // Alternative
    'KeyA':       BUTTONS.B,   // Alternative
    'KeyQ':       BUTTONS.L,
    'KeyW':       BUTTONS.R,
    'Enter':      BUTTONS.START,
    'ShiftRight': BUTTONS.SELECT,
    'ShiftLeft':  BUTTONS.SELECT,
    'Backspace':  BUTTONS.SELECT
  };

  // Gamepad button mapping (standard gamepad layout)
  const GAMEPAD_MAP = {
    0:  BUTTONS.A,
    1:  BUTTONS.B,
    8:  BUTTONS.SELECT,
    9:  BUTTONS.START,
    12: BUTTONS.UP,
    13: BUTTONS.DOWN,
    14: BUTTONS.LEFT,
    15: BUTTONS.RIGHT,
    4:  BUTTONS.L,
    5:  BUTTONS.R
  };

  // Touch button name -> bitmask
  const TOUCH_MAP = {
    'A':      BUTTONS.A,
    'B':      BUTTONS.B,
    'SELECT': BUTTONS.SELECT,
    'START':  BUTTONS.START,
    'RIGHT':  BUTTONS.RIGHT,
    'LEFT':   BUTTONS.LEFT,
    'UP':     BUTTONS.UP,
    'DOWN':   BUTTONS.DOWN,
    'R':      BUTTONS.R,
    'L':      BUTTONS.L
  };

  let keyboardButtons = 0;
  let touchButtons = 0;
  let gamepadButtons = 0;
  let previousCombined = 0;
  let onInputChange = null;
  let gamepadAnimFrame = null;
  let enabled = false;
  let isMobile = false;

  // Track active touches for multi-touch
  const activeTouches = new Map(); // touchId -> btnName

  /**
   * Initialize the input handler
   * @param {Function} callback - Called with button bitmask on state change
   */
  function init(callback) {
    onInputChange = callback;
    enabled = true;
    isMobile = detectMobile();

    // Keyboard events
    document.addEventListener('keydown', handleKeyDown);
    document.addEventListener('keyup', handleKeyUp);

    // Touch controls
    if (isMobile) {
      initTouchControls();
    }

    // Gamepad events
    window.addEventListener('gamepadconnected', (e) => {
      console.log(`[Input] Gamepad connected: ${e.gamepad.id}`);
      showToast(`Gamepad connected: ${e.gamepad.id}`, 'success');
      startGamepadPolling();
    });

    window.addEventListener('gamepaddisconnected', (e) => {
      console.log(`[Input] Gamepad disconnected: ${e.gamepad.id}`);
      showToast('Gamepad disconnected', 'warning');
    });

    const gamepads = navigator.getGamepads();
    for (const gp of gamepads) {
      if (gp) { startGamepadPolling(); break; }
    }
  }

  /**
   * Detect mobile/touch device
   */
  function detectMobile() {
    const hasTouchScreen = ('ontouchstart' in window) || 
      (navigator.maxTouchPoints > 0) ||
      (navigator.msMaxTouchPoints > 0);
    const isMobileUA = /Android|iPhone|iPad|iPod|webOS|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent);
    const isSmallScreen = window.innerWidth <= 768;
    return (hasTouchScreen && isMobileUA) || (hasTouchScreen && isSmallScreen);
  }

  /**
   * Initialize touch controls with multi-touch support
   */
  function initTouchControls() {
    // Activate mobile mode
    document.body.classList.add('mobile-mode');

    // Prevent default touch behaviors on the game area
    const canvasArea = document.getElementById('canvas-area');
    if (canvasArea) {
      canvasArea.addEventListener('touchmove', e => e.preventDefault(), { passive: false });
    }

    // Get all touch buttons
    const touchBtns = document.querySelectorAll('.touch-btn[data-btn]');
    
    touchBtns.forEach(btn => {
      const btnName = btn.dataset.btn;
      const mask = TOUCH_MAP[btnName];
      if (!mask) return;

      // Use touchstart/touchend for immediate response
      btn.addEventListener('touchstart', (e) => {
        e.preventDefault();
        e.stopPropagation();
        
        // Track this touch
        for (const touch of e.changedTouches) {
          activeTouches.set(touch.identifier, btnName);
        }
        
        btn.classList.add('pressed');
        touchButtons |= mask;
        emitChange();

        // Haptic feedback if available
        if (navigator.vibrate) {
          navigator.vibrate(15);
        }
      }, { passive: false });

      btn.addEventListener('touchend', (e) => {
        e.preventDefault();
        e.stopPropagation();
        
        // Remove tracked touches
        for (const touch of e.changedTouches) {
          activeTouches.delete(touch.identifier);
        }
        
        // Check if any remaining touches are on this button
        let stillPressed = false;
        for (const [, name] of activeTouches) {
          if (name === btnName) { stillPressed = true; break; }
        }
        
        if (!stillPressed) {
          btn.classList.remove('pressed');
          touchButtons &= ~mask;
          emitChange();
        }
      }, { passive: false });

      btn.addEventListener('touchcancel', (e) => {
        for (const touch of e.changedTouches) {
          activeTouches.delete(touch.identifier);
        }
        btn.classList.remove('pressed');
        touchButtons &= ~mask;
        emitChange();
      }, { passive: false });

      // Prevent context menu on long press
      btn.addEventListener('contextmenu', e => e.preventDefault());
    });

    // Setup mobile menu button
    const menuBtn = document.getElementById('mobile-menu-btn');
    const sidebar = document.querySelector('.room-sidebar');
    
    if (menuBtn && sidebar) {
      // Create overlay element for closing sidebar
      const overlay = document.createElement('div');
      overlay.className = 'sidebar-overlay';
      overlay.id = 'sidebar-overlay';
      document.body.appendChild(overlay);

      menuBtn.addEventListener('click', () => {
        const isOpen = sidebar.classList.contains('open');
        sidebar.classList.toggle('open');
        overlay.classList.toggle('open');
        menuBtn.textContent = isOpen ? '☰' : '✕';
      });

      overlay.addEventListener('click', () => {
        sidebar.classList.remove('open');
        overlay.classList.remove('open');
        menuBtn.textContent = '☰';
      });
    }

    // Setup fullscreen button
    const fsBtn = document.getElementById('mobile-fullscreen-btn');
    if (fsBtn) {
      fsBtn.addEventListener('click', () => {
        if (!document.fullscreenElement) {
          document.documentElement.requestFullscreen().catch(() => {});
          // Try to lock landscape on mobile
          try {
            screen.orientation.lock('landscape').catch(() => {});
          } catch (e) {}
          fsBtn.textContent = '⊠';
        } else {
          document.exitFullscreen();
          fsBtn.textContent = '⛶';
        }
      });
    }

    console.log('[Input] Mobile touch controls initialized');
  }

  // ─── Keyboard Handlers ───
  function handleKeyDown(e) {
    if (!enabled) return;
    if (e.target.tagName === 'INPUT' || e.target.tagName === 'TEXTAREA') return;

    const mask = KEY_MAP[e.code];
    if (mask) {
      e.preventDefault();
      keyboardButtons |= mask;
      emitChange();
    }
  }

  function handleKeyUp(e) {
    if (!enabled) return;
    if (e.target.tagName === 'INPUT' || e.target.tagName === 'TEXTAREA') return;

    const mask = KEY_MAP[e.code];
    if (mask) {
      e.preventDefault();
      keyboardButtons &= ~mask;
      emitChange();
    }
  }

  // ─── Gamepad Polling ───
  function startGamepadPolling() {
    if (gamepadAnimFrame) return;

    function poll() {
      const gamepads = navigator.getGamepads();
      let gpBtns = 0;
      
      for (const gp of gamepads) {
        if (!gp) continue;

        for (const [index, mask] of Object.entries(GAMEPAD_MAP)) {
          if (gp.buttons[index] && gp.buttons[index].pressed) {
            gpBtns |= mask;
          }
        }

        const DEADZONE = 0.4;
        if (gp.axes[0] < -DEADZONE) gpBtns |= BUTTONS.LEFT;
        if (gp.axes[0] > DEADZONE) gpBtns |= BUTTONS.RIGHT;
        if (gp.axes[1] < -DEADZONE) gpBtns |= BUTTONS.UP;
        if (gp.axes[1] > DEADZONE) gpBtns |= BUTTONS.DOWN;
      }

      if (gpBtns !== gamepadButtons) {
        gamepadButtons = gpBtns;
        emitChange();
      }

      gamepadAnimFrame = requestAnimationFrame(poll);
    }
    poll();
  }
  /**
   * Manually set a button state (useful for on-screen controls)
   * @param {string} btnName - Button name (A, B, UP, etc)
   * @param {boolean} pressed - Pressed state
   */
  function setButton(btnName, pressed) {
    const mask = BUTTONS[btnName.toUpperCase()];
    if (!mask) return;

    if (pressed) {
        touchButtons |= mask;
        if (navigator.vibrate) navigator.vibrate(10);
    } else {
        touchButtons &= ~mask;
    }
    emitChange();
  }

  // ─── Combined State ───
  function emitChange() {
    const combined = keyboardButtons | touchButtons | gamepadButtons;
    if (combined !== previousCombined) {
      previousCombined = combined;
      if (onInputChange) {
        onInputChange(combined);
      }
    }
  }

  function destroy() {
    enabled = false;
    document.removeEventListener('keydown', handleKeyDown);
    document.removeEventListener('keyup', handleKeyUp);
    if (gamepadAnimFrame) {
      cancelAnimationFrame(gamepadAnimFrame);
      gamepadAnimFrame = null;
    }
  }

  function getButtons() {
    return keyboardButtons | touchButtons | gamepadButtons;
  }

  function getMobile() {
    return isMobile;
  }

  function showToast(message, type) {
    const container = document.getElementById('toast-container');
    if (!container) return;
    const toast = document.createElement('div');
    toast.className = `toast toast--${type}`;
    toast.textContent = message;
    container.appendChild(toast);
    setTimeout(() => {
      toast.style.opacity = '0';
      setTimeout(() => toast.remove(), 300);
    }, 3000);
  }

  return { init, destroy, getButtons, getMobile, setButton, BUTTONS };
})();
