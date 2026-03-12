/**
 * test_canvas_check.mjs — checks if mGBA renders any pixels after ROM load
 */
import puppeteer from 'puppeteer';
import { readFileSync, readdirSync, writeFileSync } from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const ROM_PATH  = path.join(__dirname, 'roms');
const romFiles  = readdirSync(ROM_PATH).filter(f => f.endsWith('.gba'));
if (!romFiles.length) { console.error('No ROMs'); process.exit(1); }

const romFile   = romFiles[0];
const romBytes  = readFileSync(path.join(ROM_PATH, romFile));
const romBase64 = Buffer.from(romBytes).toString('base64');
console.log('[Test] ROM:', romFile, '(', (romBytes.length / 1024 / 1024).toFixed(1), 'MB)');

const browser = await puppeteer.launch({
  headless: 'new',
  args: ['--no-sandbox','--disable-setuid-sandbox','--disable-web-security',
         '--mute-audio','--disable-audio-output',
         '--enable-features=SharedArrayBuffer','--disable-site-isolation-trials'],
});

const page = await browser.newPage();
page.on('console', msg => {
  const t = msg.text();
  if (!t.includes('deprecated') && !t.includes('worker sent')) console.log('[Chrome]', t);
});
page.on('pageerror', err => {
  const m = err.message;
  if (!m.includes('signature mismatch') && m !== 'ErrorEvent') {
    console.error('[PageError]', m.substring(0, 120));
  }
});

await page.goto('http://localhost:3000/gba-headless.html', { waitUntil: 'domcontentloaded' });
await page.waitForFunction('window._mgbaReady === true || window._mgbaError != null', { timeout: 30000 });

const initErr = await page.evaluate(() => window._mgbaError);
if (initErr) { console.error('mGBA error:', initErr); await browser.close(); process.exit(1); }
console.log('[Test] ✅ mGBA ready!');

const result = await page.evaluate(
  ({ romBase64, romName }) => window.loadRom(romBase64, romName, null),
  { romBase64, romName: romFile }
);
console.log('[Test] loadRom:', JSON.stringify(result));
if (!result.ok) { await browser.close(); process.exit(1); }

console.log('[Test] Waiting 3s for game loop to run...');
await new Promise(r => setTimeout(r, 3000));

// Read canvas pixels
const pixelInfo = await page.evaluate(() => {
  const canvas = document.getElementById('gba-canvas');
  const ctx    = canvas.getContext('2d');
  const imgData = ctx.getImageData(0, 0, 240, 160);
  let nonZero  = 0;
  let maxR = 0, maxG = 0, maxB = 0;
  for (let i = 0; i < imgData.data.length; i += 4) {
    const r = imgData.data[i], g = imgData.data[i+1], b = imgData.data[i+2];
    if (r > 5 || g > 5 || b > 5) nonZero++;
    if (r > maxR) maxR = r;
    if (g > maxG) maxG = g;
    if (b > maxB) maxB = b;
  }
  return { nonZero, maxR, maxG, maxB, total: imgData.data.length / 4 };
});

console.log('[Test] Canvas pixel stats:', JSON.stringify(pixelInfo));

// Take a screenshot for visual inspection
const shot = await page.screenshot({ type: 'jpeg', quality: 90 });
const outPath = path.join(__dirname, 'mgba_test_frame.jpg');
writeFileSync(outPath, shot);
console.log('[Test] Screenshot:', outPath);

if (pixelInfo.nonZero > 100) {
  console.log('[Test] ✅ SUCCESS — game is rendering real GBA frames!');
} else {
  console.log('[Test] ❌ Canvas is black — game loop may not be running');
}

await browser.close();
process.exit(pixelInfo.nonZero > 100 ? 0 : 1);
