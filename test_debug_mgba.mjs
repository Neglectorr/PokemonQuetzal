/**
 * test_debug_mgba.mjs — in-depth diagnostic of mGBA headless state
 */
import puppeteer from 'puppeteer';
import { readFileSync } from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const romFile   = 'test.gba';
const romBytes  = readFileSync(path.join(__dirname, 'roms', romFile));
const romBase64 = Buffer.from(romBytes).toString('base64');

const browser = await puppeteer.launch({
  headless: false,
  args: ['--no-sandbox','--disable-setuid-sandbox','--disable-web-security',
         '--enable-features=SharedArrayBuffer','--disable-site-isolation-trials'],
});

const page = await browser.newPage();
page.on('console', msg => console.log('[Chrome]', msg.text().substring(0, 150)));
page.on('pageerror', err => {
  const m = err.message;
  if (!m.includes('signature mismatch') && m !== 'ErrorEvent')
    console.error('[PageError]', m.substring(0, 150));
});

await page.goto('http://localhost:3000/gba-headless.html', { waitUntil: 'domcontentloaded' });
await page.waitForFunction('window._mgbaReady === true || window._mgbaError != null', { timeout: 30000 });

const initErr = await page.evaluate(() => window._mgbaError);
if (initErr) { console.error('❌ mGBA error:', initErr); await browser.close(); process.exit(1); }

// Instrument the page with frame counting
await page.evaluate(() => {
  window._frameCount = 0;
  window._cbCount    = 0;
  window._hasGameName = () => window.mgba?.gameName;
  window._getMainLoopMode = () => {
    try { return window.mgba?.getMainLoopTimingMode?.(); } catch { return -1; }
  };
  window._getMainLoopValue = () => {
    try { return window.mgba?.getMainLoopTimingValue?.(); } catch { return -1; }
  };
});

const result = await page.evaluate(
  ({ romBase64, romName }) => window.loadRom(romBase64, romName, null),
  { romBase64, romName: romFile }
);
console.log('[Test] loadRom:', JSON.stringify(result));

// Poll every 500ms for 5 seconds
for (let i = 0; i < 10; i++) {
  await new Promise(r => setTimeout(r, 500));
  const info = await page.evaluate(() => ({
    frameCount:    window._frameCount,
    cbCount:       window._cbCount,
    gameName:      window._hasGameName(),
    mainLoopMode:  window._getMainLoopMode(),
    mainLoopValue: window._getMainLoopValue(),
    // Sample a few pixels
    pixels: (() => {
      const ctx = document.getElementById('gba-canvas')?.getContext('2d');
      if (!ctx) return null;
      const d = ctx.getImageData(0, 0, 10, 10).data;
      let sum = 0;
      for (let i = 0; i < d.length; i++) sum += d[i];
      return sum;
    })(),
  }));
  console.log(`[${(i+1)*0.5}s]`, JSON.stringify(info));
}

await browser.close();
