/**
 * test_minimal.mjs
 * Pure, unmodified mGBA WASM execution in Puppeteer to find the baseline crash.
 */
import puppeteer from 'puppeteer';
import { readFileSync } from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const romBytes  = readFileSync(path.join(__dirname, 'roms', 'test.gba'));
const romBase64 = Buffer.from(romBytes).toString('base64');

console.log('[Test] Launching pure headless Chrome...');
const browser = await puppeteer.launch({
  headless: 'new',
  args: ['--no-sandbox','--disable-web-security','--enable-features=SharedArrayBuffer','--disable-site-isolation-trials']
});

const page = await browser.newPage();
page.on('console', msg => { if (!msg.text().includes('deprecated')) console.log('[Chrome]', msg.text()); });
page.on('pageerror', err => console.error('[PageError]', err.message));

await page.goto('http://localhost:3000/', { waitUntil: 'domcontentloaded' });

const result = await page.evaluate(async (base64) => {
  const canvas = document.createElement('canvas');
  canvas.width = 240; canvas.height = 160;
  document.body.appendChild(canvas);

  try {
    const { default: mx } = await import('http://localhost:3000/mgba/mgba.js');
    const mgba = await mx({ canvas });
    await mgba.FSInit();
    mgba.setVolume(0);

    const romBytes = Uint8Array.from(atob(base64), c => c.charCodeAt(0));
    const paths = mgba.filePaths();
    mgba.FS.writeFile(`${paths.gamePath}/test.gba`, romBytes);

    mgba.addCoreCallbacks({
      videoFrameEndedCallback: function() { console.log('frame'); }
    });

    const ok = mgba.loadGame(`${paths.gamePath}/test.gba`);
    return { ok: !!ok, error: null };
  } catch (err) {
    return { ok: false, error: err.stack };
  }
}, romBase64);

console.log('[Test] loadGame result:', result);

if (result.ok) {
  console.log('[Test] Waiting 3s to see if worker crashes...');
  await new Promise(r => setTimeout(r, 3000));
}

await browser.close();
process.exit(result.ok ? 0 : 1);
