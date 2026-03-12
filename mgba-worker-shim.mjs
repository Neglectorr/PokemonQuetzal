// mgba-worker-shim.mjs — loaded by each Emscripten pthread worker
// Sets up required global polyfills before mgba.js initializes in the worker context
import { readFileSync } from 'fs';
import { createRequire } from 'module';
import { fileURLToPath, pathToFileURL } from 'url';
import path from 'path';

const __filename = fileURLToPath(import.meta.url);
const __dirname  = path.dirname(__filename);
const require    = createRequire(__filename);

// ── WASM fetch polyfill ────────────────────────────────────────────────────
const wasmPath  = path.resolve(__dirname, 'node_modules/@thenick775/mgba-wasm/dist/mgba.wasm');
const wasmBytes = readFileSync(wasmPath);

global.fetch = async (url) => {
  const u = String(url);
  const bytes = u.endsWith('.wasm') ? wasmBytes : Buffer.alloc(0);
  return {
    ok:true, status:200, url:u,
    arrayBuffer: async () => bytes.buffer.slice(bytes.byteOffset, bytes.byteOffset + bytes.byteLength),
    json:async()=>({}), text:async()=>'', headers:{get:()=>null},
  };
};

global.self       = global;
global.window     = global;
global.location   = { href:'', protocol:'file:' };
global.performance = { now: () => Date.now() };
try { global.AudioContext = class{}; } catch {}
try { global.WebGLRenderingContext = undefined; } catch {}
try { global.WebGL2RenderingContext = undefined; } catch {}
try {
  Object.defineProperty(global,'navigator',{
    value:{userAgent:'Node.js',hardwareConcurrency:4}, writable:false, configurable:true
  });
} catch {}

// The shim is complete — mgba.js worker code will be loaded by Emscripten after this
