/**
 * Authentication Module
 * Dual-auth: Google OAuth 2.0 + DEBUG_AUTH (username-only) fallback
 */
const express = require('express');
const GoogleStrategy = require('passport-google-oauth20').Strategy;
const router = express.Router();

// In-memory user store (swap for DB in production)
const users = new Map();

function configure(passport) {
  // Serialize/deserialize
  passport.serializeUser((user, done) => done(null, user.id));
  passport.deserializeUser((id, done) => {
    let user = users.get(id);
    // Auto-reconstruct debug users after server restart (id = "debug_username")
    if (!user && id && id.startsWith('debug_') && process.env.DEBUG_AUTH === 'true') {
      const username = id.replace(/^debug_/, '').replace(/_/g, ' ');
      // Restore capitalisation best-effort
      const displayName = username.charAt(0).toUpperCase() + username.slice(1);
      user = { id, username: displayName, avatar: null, provider: 'debug' };
      users.set(id, user);
    }
    done(null, user || null);
  });

  // Google OAuth strategy (only if credentials provided)
  if (process.env.GOOGLE_CLIENT_ID && process.env.GOOGLE_CLIENT_ID !== 'your-google-client-id') {
    passport.use(new GoogleStrategy({
      clientID: process.env.GOOGLE_CLIENT_ID,
      clientSecret: process.env.GOOGLE_CLIENT_SECRET,
      callbackURL: process.env.GOOGLE_CALLBACK_URL || '/auth/google/callback'
    }, (accessToken, refreshToken, profile, done) => {
      let user = users.get(profile.id);
      if (!user) {
        user = {
          id: profile.id,
          username: profile.displayName,
          avatar: profile.photos?.[0]?.value || null,
          provider: 'google'
        };
        users.set(user.id, user);
      }
      return done(null, user);
    }));

    // Google auth routes
    router.get('/google', passport.authenticate('google', { scope: ['profile', 'email'] }));
    router.get('/google/callback',
      passport.authenticate('google', { failureRedirect: '/' }),
      (req, res) => res.redirect('/dashboard')
    );
  }

  // Debug auth (simple username login for development)
  if (process.env.DEBUG_AUTH === 'true') {
    router.post('/debug', (req, res) => {
      const username = (req.body.username || '').trim();
      if (!username || username.length < 2 || username.length > 20) {
        return res.status(400).json({ error: 'Username must be 2-20 characters' });
      }

      // Create deterministic ID from username
      const id = 'debug_' + username.toLowerCase().replace(/[^a-z0-9]/g, '_');
      let user = users.get(id);
      if (!user) {
        user = {
          id,
          username,
          avatar: null,
          provider: 'debug'
        };
        users.set(id, user);
      }

      req.login(user, (err) => {
        if (err) return res.status(500).json({ error: 'Login failed' });
        res.json({ success: true, user });
      });
    });
  }
}

// Auth status check
router.get('/status', (req, res) => {
  if (req.isAuthenticated && req.isAuthenticated()) {
    return res.json({ authenticated: true, user: req.user });
  }
  res.json({ authenticated: false });
});

// Logout
router.post('/logout', (req, res) => {
  req.logout(() => {
    req.session.destroy(() => {
      res.json({ success: true });
    });
  });
});

// Middleware for protecting routes
function ensureAuth(req, res, next) {
  if (req.isAuthenticated && req.isAuthenticated()) return next();
  res.status(401).json({ error: 'Authentication required' });
}

// Middleware for auto-login in dev mode
function autoLogin(req, res, next) {
  if (process.env.NODE_ENV === 'development' && process.env.DISABLE_AUTO_LOGIN !== 'true' && (!req.isAuthenticated || !req.isAuthenticated())) {
    const id = 'debug_testuser';
    let user = users.get(id);
    if (!user) {
      user = { id, username: 'TestUser', avatar: null, provider: 'debug' };
      users.set(id, user);
    }
    
    req.login(user, (err) => {
      if (err) console.error('[Auth] Dev auto-login failed:', err);
      else console.log('[Auth] Dev mode: Auto-logged in as TestUser');
      next();
    });
  } else {
    next();
  }
}

module.exports = { router, configure, ensureAuth, autoLogin, users };
