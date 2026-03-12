/**
 * Auth Client - Login page logic
 */
(function() {
  const loginForm = document.getElementById('login-form');
  const usernameInput = document.getElementById('username-input');
  const loginBtn = document.getElementById('login-btn');
  const loginError = document.getElementById('login-error');

  // Check if already authenticated
  fetch('/auth/status')
    .then(r => r.json())
    .then(data => {
      if (data.authenticated) {
        window.location.href = '/dashboard';
      }
    })
    .catch(() => {});

  // Handle debug login
  if (loginForm) {
    loginForm.addEventListener('submit', async (e) => {
      e.preventDefault();
      const username = usernameInput.value.trim();

      if (username.length < 2) {
        showError('Username must be at least 2 characters');
        return;
      }

      loginBtn.disabled = true;
      loginBtn.querySelector('.btn-text').textContent = 'Connecting...';

      try {
        const res = await fetch('/auth/debug', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ username })
        });

        if (!res.ok) {
          const text = await res.text();
          let errorMsg = `Server error (${res.status})`;
          try {
            const errData = JSON.parse(text);
            errorMsg = errData.error || errorMsg;
          } catch(e) {}
          showError(errorMsg);
          return;
        }

        const data = await res.json();

        if (data.success) {
          window.location.href = '/dashboard';
        } else {
          showError(data.error || 'Login failed');
        }
      } catch (err) {
        console.error('Login error:', err);
        showError('Network error. Check if the server is reachable.');
      } finally {
        loginBtn.disabled = false;
        loginBtn.querySelector('.btn-text').textContent = 'Enter the Arena';
      }
    });
  }

  // Focus username input with animation
  if (usernameInput) {
    usernameInput.focus();
    
    // Add typing animation to placeholder
    usernameInput.addEventListener('focus', () => {
      usernameInput.parentElement.classList.add('focused');
    });
    usernameInput.addEventListener('blur', () => {
      usernameInput.parentElement.classList.remove('focused');
    });
  }

  function showError(message) {
    if (loginError) {
      loginError.textContent = message;
      loginError.hidden = false;
      setTimeout(() => { loginError.hidden = true; }, 5000);
    }
  }
})();
