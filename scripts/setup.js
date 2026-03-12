import { existsSync, mkdirSync, readFileSync, readdirSync, writeFileSync } from 'fs';
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
        // Find section and insert after header
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
  const dirs = ['roms', 'saves', 'sessions', 'tmp', 'mgba_native'];
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

  // 2. Extract mGBA if needed
  log("\n🎮 Checking mGBA binaries...", COLORS.bright);
  const mgbaExe = path.join(rootDir, 'mgba_native', 'mGBA-0.10.3-win64', 'mGBA.exe');
  const archive = path.join(rootDir, 'mGBA.7z');

  if (existsSync(mgbaExe)) {
    log("  ✅ mGBA is already extracted.", COLORS.green);
  } else if (existsSync(archive)) {
    log("  📦 Extracting mGBA.7z...", COLORS.yellow);
    try {
      const { createRequire } = await import('module');
      const require = createRequire(import.meta.url);
      const { path7za } = require('7zip-bin');

      const result = spawnSync(path7za, ['x', archive, `-o${path.join(rootDir, 'mgba_native')}`, '-y']);
      
      if (result.status === 0) {
        log("  ✅ Extraction successful!", COLORS.green);
      } else {
        log(`  ❌ Extraction failed with status ${result.status}`, COLORS.red);
        console.error(result.stderr.toString());
      }
    } catch (err) {
      log(`  ❌ Error during extraction: ${err.message}`, COLORS.red);
    }
  } else {
    log("  ⚠️  mGBA.7z not found. Manual installation may be required.", COLORS.yellow);
  }

  // 2b. Always Patch config.ini and qt.ini if mGBA exists (Ensures settings are forced)
  if (existsSync(mgbaExe)) {
    log("\n🔧 Ensuring mGBA is configured correctly...", COLORS.bright + COLORS.cyan);
    const mgbaDir = path.dirname(mgbaExe);
    
    // Patch config.ini
    const configPath = path.join(mgbaDir, 'config.ini');
    try {
      let config = existsSync(configPath) ? readFileSync(configPath, 'utf8') : '';
      const configPatches = {
        '[ports.qt]': {
          'videoBackend': 'software',
          'pauseOnFocusLost': '0',
          'mute': '1',
          'hwaccelVideo': '0',
          'fpsTarget': '60'
        }
      };
      config = applyIniPatches(config, configPatches);
      writeFileSync(configPath, config.trim() + '\n');
      log("  ✅ mGBA config.ini patched (Software Rendering + Server Settings).", COLORS.green);
    } catch (err) {
      log(`  ❌ Failed to patch config.ini: ${err.message}`, COLORS.red);
    }

    // Patch qt.ini (Shortcuts and Display Driver)
    const qtPath = path.join(mgbaDir, 'qt.ini');
    try {
      let qt = existsSync(qtPath) ? readFileSync(qtPath, 'utf8') : '';
      const qtPatches = {
        '[General]': {
          'displayDriver': '0' // 0 = Software
        },
        '[shortcutKey]': {
          'multiWindow': 'Ctrl+M'
        }
      };
      qt = applyIniPatches(qt, qtPatches);
      writeFileSync(qtPath, qt.trim() + '\n');
      log("  ✅ mGBA qt.ini patched (Shortcuts: Ctrl+M + Display Driver).", COLORS.green);
    } catch (err) {
      log(`  ❌ Failed to patch qt.ini: ${err.message}`, COLORS.red);
    }
  }

  // 3. Environment Check
  log("\n🔐 Checking environment...", COLORS.bright);
  const envPath = path.join(rootDir, '.env');
  const envExamplePath = path.join(rootDir, '.env.example');

  if (existsSync(envPath)) {
    log("  ✅ .env file found.", COLORS.green);
  } else {
    log("  ⚠️  .env file is MISSING!", COLORS.bright + COLORS.yellow);
    log("     Please copy .env.example to .env and fill in your credentials.");
    if (existsSync(envExamplePath)) {
       log(`     Command: copy .env.example .env`, COLORS.cyan);
    }
  }

  // 4. Python Dependencies
  log("\n🐍 Checking Python dependencies...", COLORS.bright + COLORS.blue);
  const pythonDeps = [
    { module: 'keyboard', package: 'keyboard' },
    { module: 'win32gui', package: 'pywin32' },
    { module: 'psutil', package: 'psutil' },
    { module: 'pywinauto', package: 'pywinauto' },
    { module: 'numpy', package: 'numpy' },
    { module: 'cv2', package: 'opencv-python' },
    { module: 'soundcard', package: 'soundcard' }
  ];

  try {
    const missingDeps = [];
    for (const dep of pythonDeps) {
      const check = spawnSync('python', ['-c', `import ${dep.module}`]);
      if (check.status !== 0) {
        missingDeps.push(dep.package);
      }
    }

    if (missingDeps.length === 0) {
      log("  ✅ All Python dependencies are installed.", COLORS.green);
    } else {
      log(`  📦 Installing missing Python dependencies: ${missingDeps.join(', ')}...`, COLORS.yellow);
      const pipResult = spawnSync('pip', ['install', ...missingDeps]);
      if (pipResult.status === 0) {
        log("  ✅ Python dependencies installed successfully!", COLORS.green);
      } else {
        log("  ❌ Failed to install Python dependencies via pip.", COLORS.red);
        log(`     Please run: pip install ${missingDeps.join(' ')}`, COLORS.bright + COLORS.yellow);
      }
    }
  } catch (err) {
    log("  ⚠️  Python or pip not found. Native multiplayer macros will not work.", COLORS.yellow);
    log("     Ensure Python 3 is installed and in your PATH.", COLORS.cyan);
  }

  // 5. ROMs Check
  log("\n🕹️  Checking ROMs...", COLORS.bright);
  const romsDir = path.join(rootDir, 'roms');
  const roms = existsSync(romsDir) ? readdirSync(romsDir) || [] : [];
  if (roms.length === 0) {
    log("  ⚠️  No ROMs found in /roms directory.", COLORS.yellow);
    log("     Please place your .gba files in the /roms folder to start playing.");
  } else {
    log(`  ✅ Found ${roms.length} file(s) in /roms.`, COLORS.green);
  }

  log("\n✨ Setup process complete!\n", COLORS.bright + COLORS.green);
}

setup().catch(err => {
  console.error("Critical error during setup:", err);
  process.exit(1);
});
