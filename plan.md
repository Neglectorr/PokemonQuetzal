7
plan.md: Project Antigravity – Multi-instance GBA Cloud Platform
1. Project Vision
A high-performance, server-side emulation platform for GBA multiplayer (focused on Pokémon Quetzal). The server handles all game logic and "Virtual Link Cable" synchronization, while the client acts as a "Thin Client" for input handling and canvas rendering.

2. System Architecture
Backend: Node.js (Express) with Socket.io for real-time binary data I/O.

Emulation: Headless mGBA (libretro) cores running within a "Super-instance" (Worker Thread) per lobby.

Synchronization: Shared-memory bus between instances in a single room for zero-latency link-cable emulation.

Rendering: Server-side Framebuffer Extraction. Transmit compressed pixel diffs (delta-updates) via binary WebSockets or WebRTC DataChannels.

Frontend: HTML5 Canvas with Input Latency Compensation (immediate local UI feedback on button press).

Networking: Optimized for running behind a Caddy Proxy (Trusting proxy headers for Secure Cookies and Socket.io WSS).

3. Environment & Configuration
Codefragment
NODE_ENV=production
PORT=3000
SESSION_SECRET=your-long-random-string-here
CLIENT_ORIGIN=https://roms.wesleypostma.nl
GOOGLE_CLIENT_ID=653921646139...
GOOGLE_CLIENT_SECRET=GOCSPX-29...
GOOGLE_CALLBACK_URL=https://roms.wesleypostma.nl/auth/google/callback
DEBUG_AUTH=true # Enable simple username-only login for testing
TRUST_PROXY=true # Required for Caddy/Reverse Proxy header support
4. Feature Roadmap (AI Agent Task List)
Phase 1: Authentication & File System
[ ] Dual-Auth System: Implement Passport.js with Google Strategy AND a DEBUG_AUTH fallback (simple form field for username).

[ ] Proxy Configuration: Configure Express to trust proxy to correctly handle X-Forwarded-For and X-Forwarded-Proto from Caddy.

[ ] Directory Structure:

/roms: Read-only storage for .gba files.

/saves/{user_id}/: Storage for .sav (SRAM) and .state (mGBA Savestates).

[ ] Party Parser: Integrate a .sav parser (e.g., pkm-js) to extract and display the current Pokémon party icons in the web UI.

Phase 2: Lobby & Room Management
[ ] Lobby Logic: Main dashboard showing active rooms and a "Create Room" option.

[ ] Roles & Permissions:

Host (Player 1): Room creator, selects base ROM.

Player (2-4): Active participant with compatible ROM.

Spectator: Unlimited viewers.

[ ] ROM Matching Engine:

Ruby/Sapphire/Emerald -> Peers can only join with titles from this trio.

FireRed/LeafGreen -> Peers can only join with titles from this duo.

Fallback: If no match, only the host's exact ROM is offered.

Phase 3: The Emulation Bridge
[ ] Worker Threads: Orchestrate one Node.js Worker Thread per active lobby to isolate CPU load.

[ ] Memory Linking: Configure mGBA cores to inter-connect serial ports virtually (SGB/Link mode) within the shared process memory.

[ ] Frame Streamer: Capture framebuffer at 60fps, calculate pixel diffs, and broadcast binary payloads to the socket room.

Phase 4: Frontend UI
[ ] Main Stage: Primary canvas for the local player's gameplay.

[ ] Grid View: 2x2 layout showing all 4 players via WebRTC "Star" distribution (Host/Server broadcasts to spectators).

[ ] Input Handler: Map Keyboard & Gamepad API to GBA inputs; send low-latency binary packets to the server.

5. Exit Strategy & Persistence
[ ] Heartbeat Monitor: On socket disconnect, maintain the instance for 30 seconds. If no reconnect:

Trigger emulator_save_state() (.state).

Trigger emulator_write_sram() (.sav).

[ ] Auto-Resume: Upon login, check for the most recent .state for the selected ROM and load it automatically to resume gameplay.
