/**
 * test_mgba.mjs — headless mGBA in Node.js
 *
 * How it works:
 *  1. Set up browser-API polyfills (canvas, audio, fetch, Worker)
 *  2. Intercept Worker constructor: when Emscripten spawns a pthread worker
 *     pointing to its own mgba.js URL, redirect to our shim that first
 *     sets up the same polyfills inside the worker thread.
 *  3. Provide wasmBinary directly so Emscripten skips fetch/streaming.
 */
import { readFileSync } from 'fs';
import { fileURLToPath } from 'url';
import path from 'path';
import BaseWorker from 'web-worker';

const __dirname  = path.dirname(fileURLToPath(import.meta.url));
const GBA_WIDTH  = 240;
const GBA_HEIGHT = 160;

// ── WASM bytes (bypass streaming compile) ─────────────────────────────────
const wasmPath  = path.resolve(__dirname, 'node_modules/@thenick775/mgba-wasm/dist/mgba.wasm');
const wasmBytes = new Uint8Array(readFileSync(wasmPath));
const mgbaJsPath = path.resolve(__dirname, 'node_modules/@thenick775/mgba-wasm/dist/mgba.js');
const mgbaJsUrl  = 'file:///' + mgbaJsPath.replace(/\\/g, '/');
const shimUrl    = 'file:///' + path.resolve(__dirname, 'mgba-worker-shim.mjs').replace(/\\/g, '/');

// ── Canvas polyfill ────────────────────────────────────────────────────────
const pixelBuffer = Buffer.alloc(GBA_WIDTH * GBA_HEIGHT * 4);
const fake2DCtx = {
  drawImage:()=>{},
  getImageData:(x,y,w,h)=>({data:new Uint8ClampedArray(w*h*4),width:w,height:h}),
  putImageData:(d)=>{ if(d?.data) pixelBuffer.set(Buffer.from(d.data.buffer)); },
  clearRect:()=>{}, fillRect:()=>{}, fillStyle:'',
  save:()=>{}, restore:()=>{}, scale:()=>{}, translate:()=>{},
};
const fakeCanvas = {
  width:GBA_WIDTH, height:GBA_HEIGHT,
  style:{cssText:'',width:'',height:'',display:''},
  addEventListener:()=>{}, removeEventListener:()=>{}, dispatchEvent:()=>{},
  getContext:(t)=> t==='2d' ? fake2DCtx : null,
  getBoundingClientRect:()=>({left:0,top:0,right:GBA_WIDTH,bottom:GBA_HEIGHT,width:GBA_WIDTH,height:GBA_HEIGHT}),
  focus:()=>{},
};

// ── Audio polyfill ─────────────────────────────────────────────────────────
class FakeAudioContext {
  constructor(){ this.sampleRate=48000; this.state='running'; this.destination={}; }
  createGain(){ return {gain:{value:1,setValueAtTime:()=>{}},connect:()=>{}}; }
  createScriptProcessor(){ return {connect:()=>{},onaudioprocess:null}; }
  createBuffer(ch,fr){ return {getChannelData:()=>new Float32Array(fr)}; }
  resume(){ return Promise.resolve(); }
  close(){ return Promise.resolve(); }
}

// ── fetch polyfill ─────────────────────────────────────────────────────────
global.fetch = async (url) => {
  const u = String(url);
  const bytes = u.endsWith('.wasm') ? wasmBytes : Buffer.alloc(0);
  return {
    ok:true, status:200, url:u,
    arrayBuffer: async () => bytes.buffer.slice(bytes.byteOffset, bytes.byteOffset+bytes.byteLength),
    json:async()=>({}), text:async()=>'', headers:{get:()=>null},
  };
};

// ── Worker interceptor ─────────────────────────────────────────────────────
// Emscripten creates Workers pointing to mgba.js; redirect to our shim.
class MgbaWorker extends BaseWorker {
  constructor(url, options={}) {
    const u = String(url);
    // If Emscripten is spawning a pthread worker from mgba.js, use our shim
    const target = (u.includes('mgba') || u.includes('em-pthread')) ? shimUrl : u;
    super(target, { ...options, type:'module' });
  }
}

// ── install globals ────────────────────────────────────────────────────────
const def = (k,v)=>{ try{global[k]=v;}catch{Object.defineProperty(global,k,{value:v,writable:true,configurable:true}); }};

def('Worker',     MgbaWorker);
def('document', {
  createElement:(t)=>t==='canvas'?fakeCanvas:{style:{},appendChild:()=>{}},
  getElementById:()=>null,
  body:{appendChild:()=>{}}, head:{appendChild:()=>{}},
  createElementNS:()=>({style:{}}),
  hidden:false, onvisibilitychange:null,
});
def('window',   global);
def('self',     global);
def('AudioContext', FakeAudioContext);
def('WebGLRenderingContext', undefined);
def('WebGL2RenderingContext', undefined);
def('location', {href:'',protocol:'file:'});
try { Object.defineProperty(global,'navigator',{value:{userAgent:'Node.js',hardwareConcurrency:4},configurable:true}); } catch{}

// ── initialize mGBA ────────────────────────────────────────────────────────
console.log('[Test] Starting headless mGBA init...');
(async ()=>{
  try {
    const { default: mGBAInit } = await import('@thenick775/mgba-wasm');
    console.log('[Test] Module loaded, calling mGBA()...');

    const mgba = await mGBAInit({ canvas:fakeCanvas, wasmBinary:wasmBytes });

    console.log('[Test] ✅ mGBA initialized! version:', mgba.version?.projectVersion);
    console.log('[Test] filePaths:', JSON.stringify(mgba.filePaths()));
    process.exit(0);
  } catch(err) {
    console.error('[Test] ❌ Error:', err.message);
    console.error(err.stack?.split('\n').slice(0,10).join('\n'));
    process.exit(1);
  }
})();
