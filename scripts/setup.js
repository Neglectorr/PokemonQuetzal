import { existsSync, mkdirSync, readFileSync, readdirSync, writeFileSync, copyFileSync } from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';
import { spawnSync } from 'child_process';

// ES Module dirname
const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const rootDir = path.resolve(__dirname, '..');

const COLORS = {
  reset: "\x1b[0m",
  bright: "\x1b[1m",
  green: "\x1b[32m",
  yellow: "\x1b[33m",
  blue: "\x1b[34m",
  magenta: "\x1b[35m",
  cyan: "\x1b[36m",
  red: "\x1b[31m",
};

function log(msg, color = COLORS.reset) {
  console.log(`${color}${msg}${COLORS.reset}`);
}

/**
 * Helper to patch INI files
 */
function applyIniPatches(content, patches) {
  let newContent = content;
  for (const [section, settings] of Object.entries(patches)) {
    if (!newContent.includes(section)) {
      newContent += `\n${section}\n`;
    }
    for (const [key, value] of Object.entries(settings)) {
      const regex = new RegExp(`^${key}=.*$`, 'm');
      if (newContent.match(regex)) {
        newContent = newContent.replace(regex, `${key}=${value}`);
      } else {
        const sectionPos = newContent.indexOf(section);
        const nextLinePos = newContent.indexOf('\n', sectionPos) + 1;
        newContent = newContent.slice(0, nextLinePos) + `${key}=${value}\n` + newContent.slice(nextLinePos);
      }
    }
  }
  return newContent;
}

async function setup() {
  log("\n🚀 Starting Project Antigravity Setup...", COLORS.bright + COLORS.cyan);

  // 1. Ensure Directories Exist
  const dirs = ['roms', 'saves', 'lobbies', 'tmp', 'mgba_native'];
  log("\n📁 Checking directories...", COLORS.bright);
  dirs.forEach(dir => {
    const fullPath = path.join(rootDir, dir);
    if (!existsSync(fullPath)) {
      mkdirSync(fullPath, { recursive: true });
      log(`  ✅ Created /${dir}`, COLORS.green);
    } else {
      log(`  ℹ️  /${dir} already exists`, COLORS.blue);
    }
  });

  // 1b. Patch mgba-wasm to include FakeAudioContext (Essential for Headless JS fallback)
  log("\n🩹 Patching @thenick775/mgba-wasm...", COLORS.bright + COLORS.magenta);
  const mgbaWasmPath = path.join(rootDir, 'node_modules', '@thenick775', 'mgba-wasm', 'dist', 'mgba.js');
  if (existsSync(mgbaWasmPath)) {
    try {
      let content = readFileSync(mgbaWasmPath, 'utf8');
      if (!content.includes('class FakeAudioContext')) {
        const patch = `
// Antigravity Patch: Fake AudioContext for Headless Node.js
if (typeof AudioContext === 'undefined') {
  class FakeAudioContext {
    constructor() { this.sampleRate = 44100; this.destination = {}; }
    createScriptProcessor() { return { connect: () => {} }; }
    decodeAudioData() { return Promise.resolve(); }
  }
  global.AudioContext = FakeAudioContext;
}
`;
        content = patch + content;
        writeFileSync(mgbaWasmPath, content);
        log("  ✅ mgba.js patched with FakeAudioContext.", COLORS.green);
      } else {
        log("  ℹ️  mgba.js already patched.", COLORS.blue);
      }
    } catch (err) {
      log(`  ❌ Failed to patch mgba.js: ${err.message}`, COLORS.red);
    }
  }

  // 2. mGBA Binaries Check & Configuration
  log("\n🎮 Configuring mGBA binaries...", COLORS.bright);
  const mgbaCustomDir = path.join(rootDir, 'mgba_native', 'mGBA-custom');
  const mgbaCustomExe = path.join(mgbaCustomDir, 'mGBA.exe');
  const qwindowsDll = path.join(mgbaCustomDir, 'platforms', 'qwindows.dll');

  if (existsSync(mgbaCustomExe)) {
    log("  ✅ Custom mGBA found.", COLORS.green);
    
    // Patch config.ini and qt.ini for the custom build
    [path.join(mgbaCustomDir, 'config.ini'), path.join(mgbaCustomDir, 'qt.ini')].forEach(iniPath => {
        try {
            let content = existsSync(iniPath) ? readFileSync(iniPath, 'utf8') : '';
            if (iniPath.endsWith('config.ini')) {
                content = applyIniPatches(content, {
                    '[ports.qt]': { 'videoBackend': 'software', 'mute': '1', 'hwaccelVideo': '0' }
                });
            } else {
                content = applyIniPatches(content, {
                    '[General]': { 'displayDriver': '0' }
                });
            }
            writeFileSync(iniPath, content.trim() + '\n');
            log(`  ✅ Configured ${path.basename(iniPath)}`, COLORS.green);
        } catch (e) {}
    });

    if (!existsSync(qwindowsDll)) {
        log("  ⚠️  platforms/qwindows.dll is MISSING! Headless mode will FAIL.", COLORS.red);
    }
  } else {
    log("  ⚠️  Native mGBA.exe not found at mgba_native/mGBA-custom/. Please ensure it's compiled.", COLORS.yellow);
  }

  // 3. Environment Check
  log("\n🔐 Checking environment...", COLORS.bright);
  const envPath = path.join(rootDir, '.env');
  const envExamplePath = path.join(rootDir, '.env.example');

  if (!existsSync(envPath)) {
    if (existsSync(envExamplePath)) {
        log("  📦 Copying .env.example to .env...", COLORS.yellow);
        copyFileSync(envExamplePath, envPath);
        log("  ✅ .env created. Please update it with your secrets!", COLORS.green);
    } else {
        log("  ❌ .env.example not found. Manual .env creation required.", COLORS.red);
    }
  } else {
    log("  ✅ .env file exists.", COLORS.green);
  }

  // 4. Python Dependencies
  log("\n🐍 Checking Python dependencies for Headless Input Proxy...", COLORS.bright + COLORS.blue);
  const pythonDeps = [
    { module: 'win32gui', package: 'pywin32' },
    { module: 'psutil', package: 'psutil' }
  ];

  try {
    const missingDeps = [];
    for (const dep of pythonDeps) {
      const check = spawnSync('python', ['-c', `import ${dep.module}`]);
      if (check.status !== 0) missingDeps.push(dep.package);
    }

    if (missingDeps.length > 0) {
      log(`  📦 Installing: ${missingDeps.join(', ')}...`, COLORS.yellow);
      spawnSync('pip', ['install', ...missingDeps], { stdio: 'inherit' });
    } else {
      log("  ✅ Python dependencies are ready.", COLORS.green);
    }
  } catch (err) {
    log("  ⚠️  Python/pip not found. Input proxy will fail.", COLORS.yellow);
  }

  // 5. Final ROMs Check
  const romsDir = path.join(rootDir, 'roms');
  const romCount = existsSync(romsDir) ? readdirSync(romsDir).length : 0;
  if (romCount === 0) log("\n🕹️  Note: Place .gba ROMs in /roms to begin.", COLORS.yellow);

  log("\n✨ Setup complete! Run 'npm start' to launch the server.\n", COLORS.bright + COLORS.green);
}

setup().catch(err => {
  console.error("Critical error during setup:", err);
  process.exit(1);
});
