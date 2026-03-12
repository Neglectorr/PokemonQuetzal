# Project Antigravity — Multi-instance GBA Cloud Platform

## 🚀 Getting Started

Deploying the project is now simpler than ever. Follow these steps to get your server running:

### 1. Installation
Pull the repository and run the install command. This will automatically set up the required folders and extract the native mGBA binaries.
```bash
npm install
```

### 2. Manual Configuration (Required)
The setup script handles the boilerplate, but you still need to provide your specific data:

- **Environment**: Copy `.env.example` to `.env` and fill in your Google OAuth credentials and secrets.
- **ROMs**: Place your `.gba` files in the `roms/` directory. The server will detect them automatically.

### 3. Running the Server
Once configured, start the server in development or production mode:
```bash
# Development mode (with nodemon)
npm run dev

# Production mode
npm start
```

---

## Technical Overview
- **Backend**: Node.js (Express) + Socket.io
- **Emulation**: Native mGBA (Windows) orchestrated via Worker Threads.
- **Multiplayer**: Virtual Link Cable synchronization for up to 4 players.
pt
