/**
 * test_puppeteer_mgba.mjs
 * Verifies that Puppeteer can launch headless Chrome, load gba-headless.html, 
 * and initialize mGBA WASM with a real ROM.
 */
import puppeteer from 'puppeteer';
import { readFileSync } from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const __dirname = path.dirname(fileURLToPath(import.meta.url));

const ROM_PATH = path.join(__dirname, 'roms');
const roms = (await import('fs')).readdirSync(ROM_PATH).filter(f => f.endsWith('.gba'));
if (roms.length === 0) {
  console.error('No .gba files found in /roms — cannot test');
  process.exit(1);
}
const romFile = roms[0];
console.log('[Test] Using ROM:', romFile);

const romBytes  = readFileSync(path.join(ROM_PATH, romFile));
const romBase64 = romBytes.toString('base64');

const browser = await puppeteer.launch({
  headless: 'new',
  args: [
    '--no-sandbox',
    '--disable-setuid-sandbox',
    '--enable-features=SharedArrayBuffer',
    '--disable-site-isolation-trials',
  ],
});

const page = await browser.newPage();

// Listen for console messages from inside the headless page
page.on('console', msg => console.log('[Chrome]', msg.text()));
page.on('pageerror', err => console.error('[Chrome Error]', err.message));

let frameCount = 0;
await page.exposeFunction('_onFrameData', (b64) => {
  frameCount++;
  if (frameCount <= 3) console.log('[Test] ✅ Frame', frameCount, 'received! Length:', b64.length, 'chars');
});

// Suppress the audio worker crash — it's non-fatal for emulation
page.on('pageerror', (err) => {
  if (err.message.includes('function signature mismatch') || err.message.includes('SDL')) {
    console.log('[Test] [suppressed audio worker error]');
    return;
  }
  console.error('[Chrome Error]', err.message);
});

await page.goto('http://localhost:3000/gba-headless.html', { waitUntil: 'domcontentloaded' });

// Set up frame callback
await page.evaluate(() => {
  window._onFrame = (pixelData) => {
    const offscreen = new OffscreenCanvas(240, 160);
    const ctx = offscreen.getContext('2d');
    const imgData = new ImageData(new Uint8ClampedArray(pixelData), 240, 160);
    ctx.putImageData(imgData, 0, 0);
    offscreen.convertToBlob({ type: 'image/jpeg', quality: 0.5 }).then(blob => {
      blob.arrayBuffer().then(ab => {
        const b64 = btoa(String.fromCharCode(...new Uint8Array(ab)));
        window._onFrameData(b64);
      });
    });
  };
});

console.log('[Test] Waiting for mGBA ready...');
await page.waitForFunction('window._mgbaReady === true || window._mgbaError != null', { timeout: 30000 });

const err = await page.evaluate(() => window._mgbaError);
if (err) { console.error('[Test] ❌ mGBA init error:', err); process.exit(1); }

const version = await page.evaluate(() => window?.mgba?.version?.projectVersion);
console.log('[Test] ✅ mGBA ready!');

console.log('[Test] Loading ROM:', romFile);
const result = await page.evaluate(({ romBase64, romName }) => window.loadRom(romBase64, romName, null), {
  romBase64, romName: romFile
});
console.log('[Test] loadRom result:', JSON.stringify(result));

if (!result.ok) { console.error('[Test] ❌ Failed to load ROM:', result.error); await browser.close(); process.exit(1); }

console.log('[Test] ✅ ROM loaded! Waiting 2 seconds for frames...');
await new Promise(r => setTimeout(r, 2000));
console.log('[Test] Frames received:', frameCount);

await browser.close();
process.exit(frameCount > 0 ? 0 : 1);
