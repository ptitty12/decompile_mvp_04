// The engine Worker (E2, E2c). Loads the engine module, opens the disc image
// (the File the player picked, read with FileReaderSync; or the server's image
// on the owner's deployment, read with Range requests), translates the DOL (or
// loads the translation this browser cached on an earlier visit), boots the
// machine and runs it one VI field at a time, drawing into the OffscreenCanvas
// the page transferred here and posting the mixed audio to the AudioWorklet.
//
// Pacing: each animation frame decides how many whole VI fields to run so the
// guest's virtual time keeps up with the wall clock (at most a few per frame;
// a long stall drops the debt instead of racing). Wall time decides only how
// many fields run, never what happens inside one: guest state depends on the
// disc and the per-frame pad inputs alone. Audio goes one way, Worker ->
// worklet, after each batch; nothing about its timing comes back.

import createMvpEngine, { type MvpEngine } from './mvp-web.js';
import { probeDiscUrl } from './disc.js';
import { cacheKey, clearCache, readCached, writeCached } from './module-cache.js';
import type { CacheReport, DiscSource, FromWorker, Pad, RunOptions, Status, ToWorker, WorkletIn } from './protocol.js';

interface WorkerScope {
  postMessage(msg: FromWorker): void;
  onmessage: ((ev: MessageEvent<ToWorker>) => void) | null;
  requestAnimationFrame?: (cb: (now: number) => void) => number;
}
const scope = self as unknown as WorkerScope;

const FIELD_MS = 1000 / 59.94;   // NTSC field rate
const MAX_FIELDS_PER_FRAME = 4;  // catch-up limit per animation frame
const FAST_BUDGET_MS = 40;       // unpaced mode: run this long, then let the canvas present
const MAX_PREFETCH = 2;          // read-ahead requests in flight (server image)

let M: MvpEngine | null = null;
let opts: RunOptions | null = null;
let running = false, paused = false, firstFrame = false, booted = false;
let pacedStart = 0, pacedFields = 0;
// Stats window (reported about twice a second).
let winFields = 0, winMs = 0, winWall = performance.now();
// Audio: the worklet's channel, once the page has one (first user gesture).
let audioPort: MessagePort | null = null;
let audioAttached = false;
// The server's image (read-ahead), and the cache entry to write after the first frame.
let discUrl: string | null = null;
let discSize = 0;
let prefetching = 0;
let storeKey: string | null = null;

function post(msg: FromWorker): void {
  scope.postMessage(msg);
}

function cstr(ptr: number): string {
  return M ? M.UTF8ToString(ptr) : '';
}

function status(): Status {
  return JSON.parse(cstr(M!._mvp_status())) as Status;
}

function withBytes<T>(bytes: Uint8Array, f: (ptr: number, len: number) => T): T {
  const ptr = M!._malloc(Math.max(1, bytes.length));
  M!.HEAPU8.set(bytes, ptr);
  try {
    return f(ptr, bytes.length);
  } finally {
    M!._free(ptr);
  }
}

function setPad(port: number, p: Pad): void {
  M?._mvp_set_pad(port, p.connected ? 1 : 0, p.buttons, p.stickX, p.stickY, p.cX, p.cY, p.trigL, p.trigR);
}

async function openDisc(disc: DiscSource): Promise<boolean> {
  if (disc.kind === 'file') {
    M!.mvpDisc = disc.file;
    if (opts?.traceDisc) M!._mvp_disc_trace_enable();
    return !!M!._mvp_open_disc(disc.file.size);
  }
  post({ type: 'progress', text: 'Connecting to the disc image on the server', step: 0, steps: 0 });
  const probe = await probeDiscUrl(disc.url);
  if (!probe.ok) {
    post({ type: 'error', stage: 'server', message: probe.message, login: probe.login });
    return false;
  }
  discUrl = disc.url;
  discSize = probe.size;
  M!.mvpDiscUrl = disc.url;
  const c = opts?.discCache ?? {};
  return !!M!._mvp_open_disc_url(probe.size, c.blockKib ?? 0, c.maxBlocks ?? 0, c.maxRun ?? 0, c.ahead ?? -1);
}

// The translated module from this browser's cache, if it has one for this
// DOL and engine build. Returns false to translate instead.
async function loadCached(key: string, report: CacheReport): Promise<boolean> {
  const t = performance.now();
  post({ type: 'progress', text: 'Loading the translation cached in this browser', step: 1, steps: 2 });
  let ptr = 0;
  const n = await readCached(key, (size) => {
    ptr = M!._malloc(size);
    return M!.HEAPU8.subarray(ptr, ptr + size);
  });
  if (!n) {
    if (ptr) M!._free(ptr);
    return false;
  }
  const ok = M!._mvp_translate_cached(ptr, n);
  M!._free(ptr);
  report.bytes = n;
  report.readMs = performance.now() - t;
  if (!ok) {
    report.error = cstr(M!._mvp_last_error());
    await clearCache();
    return false;
  }
  report.hit = true;
  return true;
}

// After the first frame: serialize the module the translator kept and store it.
async function storeModule(key: string): Promise<void> {
  const n = M!._mvp_module_blob();
  if (!n) return;
  const ptr = M!._mvp_module_blob_ptr();
  const bytes = M!.HEAPU8.slice(ptr, ptr + n);  // a copy: the heap can grow while the write awaits
  M!._mvp_module_release();
  const r = await writeCached(key, bytes);
  post({ type: 'cache', report: { key, hit: false, bytes: n, ...('ms' in r ? { storedMs: r.ms } : { error: r.error }) } });
}

function enableAudio(): void {
  if (!M || !booted || !opts?.audio || !audioPort || audioAttached) return;
  M._mvp_audio_enable(1);
  audioAttached = true;
  post({ type: 'audio', attachedAtField: status().fields });
}

// The batch's mixed frames, to the worklet (the buffer is transferred).
function pumpAudio(): void {
  if (!audioAttached || !audioPort || !M) return;
  const n = M._mvp_audio_take();
  if (!n) return;
  const ptr = M._mvp_audio_ptr();
  const data = new Int16Array(M.HEAPU8.buffer.slice(ptr, ptr + 4 * n));
  const msg: WorkletIn = { type: 'pcm', rate: M._mvp_audio_rate(), data };
  audioPort.postMessage(msg, [data.buffer]);
}

// Read-ahead for the server's image: fetch what a sequential stream will want
// next while the guest runs, so its reads find the blocks in memory.
function pumpDisc(): void {
  if (!M || !discUrl || prefetching >= MAX_PREFETCH) return;
  const count = M._mvp_disc_want();
  if (!count) return;
  const first = M._mvp_disc_want_first(), block = M._mvp_disc_block();
  const start = first * block, end = Math.min(discSize, (first + count) * block) - 1;
  ++prefetching;
  fetch(discUrl, { headers: { Range: `bytes=${start}-${end}` }, credentials: 'same-origin', cache: 'no-store' })
    .then(async (r) => {
      if (r.status !== 206) throw new Error(`HTTP ${r.status}`);
      return new Uint8Array(await r.arrayBuffer());
    })
    .then((bytes) => withBytes(bytes, (p, n) => M!._mvp_disc_insert(first, count, p, n, 1)))
    .catch(() => M?._mvp_disc_insert(first, count, 0, 0, 0))
    .finally(() => --prefetching);
}

async function start(disc: DiscSource, canvas: OffscreenCanvas | null, width: number, height: number,
                     options: RunOptions): Promise<void> {
  opts = options;
  const phase = (name: string, t0: number, detail?: unknown) =>
    post({ type: 'phase', name, ms: performance.now() - t0, detail });

  let t = performance.now();
  post({ type: 'progress', text: 'Loading the engine', step: 0, steps: 0 });
  M = await createMvpEngine({
    print: (text) => post({ type: 'log', text, error: false }),
    printErr: (text) => post({ type: 'log', text, error: true }),
  });
  M.mvpOnProgress = (text, step, steps) => post({ type: 'progress', text, step, steps });
  phase('engine', t);

  // Ask for the GPU first: the adapter and device requests complete while
  // the DOL is translated.
  let gfxReady: Promise<boolean> = Promise.resolve(false);
  if (options.render && canvas && 'gpu' in navigator) {
    M.specialHTMLTargets['#mvp-canvas'] = canvas;
    const tg = performance.now();
    gfxReady = new Promise<boolean>((resolve) => {
      M!.mvpOnGfx = (ok, message) => {
        post({ type: 'gfx', ok: !!ok, message });
        phase('gpu', tg);
        resolve(!!ok);
      };
    });
    withBytes(new TextEncoder().encode('#mvp-canvas\0'), (p) => M!._mvp_gfx_init(p, width, height));
  } else {
    post({ type: 'gfx', ok: false, message: options.render ? 'WebGPU is not available in this browser' : 'rendering off' });
  }

  // The disc: identity first (GV4E69 rev 0, by the DOL's SHA-1).
  t = performance.now();
  if (!(await openDisc(disc))) {
    const message = cstr(M._mvp_last_error());
    if (message) post({ type: 'error', stage: 'disc', message });
    return;
  }
  phase('disc', t);
  const info = JSON.parse(cstr(M._mvp_disc_info())) as { dol_sha1: string; game: string; revision: number;
                                                         title: string; image: string };
  post({ type: 'disc', info });

  // The translation: this browser's cache, else the translator.
  const report: CacheReport = { key: null, hit: false };
  t = performance.now();
  if (options.cache) report.key = await cacheKey(info.dol_sha1, new URL('build-id.json', import.meta.url));
  if (report.key && (await loadCached(report.key, report))) {
    phase('translate', t, JSON.parse(cstr(M._mvp_translate_info())));
  } else {
    // symbols.txt is repository metadata served with the engine.
    t = performance.now();
    post({ type: 'progress', text: 'Translating: fetching the symbol map', step: 0, steps: 5 });
    const symbols = new Uint8Array(await (await fetch(new URL('symbols.txt', import.meta.url))).arrayBuffer());
    phase('symbols-fetch', t);
    t = performance.now();
    if (report.key) M._mvp_keep_module(1);
    const ok = withBytes(symbols, (p, n) => M!._mvp_translate(p, n));
    if (!ok) {
      post({ type: 'error', stage: 'translate', message: cstr(M._mvp_last_error()) });
      return;
    }
    phase('translate', t, JSON.parse(cstr(M._mvp_translate_info())));
    storeKey = report.key;
  }
  post({ type: 'cache', report });

  t = performance.now();
  post({ type: 'progress', text: 'Booting', step: 5, steps: 5 });
  const script = new TextEncoder().encode(options.script);
  const ok = withBytes(script, (p, n) => M!._mvp_boot(p, options.script ? n : 0, options.stopFields,
                                                      options.stopFrames));
  if (!ok) {
    post({ type: 'error', stage: 'boot', message: cstr(M._mvp_last_error()) });
    return;
  }
  booted = true;
  enableAudio();
  phase('boot', t);

  // The renderer must see the command stream from the start: wait for it.
  t = performance.now();
  await gfxReady;
  phase('gpu-wait', t);

  running = true;
  pacedStart = performance.now();
  pacedFields = 0;
  winWall = performance.now();
  if (options.fast) setTimeout(fastLoop, 0);
  else if (scope.requestAnimationFrame) scope.requestAnimationFrame(frame);
  // else: the page sends 'tick' messages from its own animation frames.
}

function afterRun(ran: number, ms: number): boolean {
  winFields += Math.max(0, ran);
  winMs += ms;
  pumpAudio();
  pumpDisc();
  if (M!._mvp_present() && !firstFrame) {
    firstFrame = true;
    post({ type: 'first-frame', fields: status().fields });
    if (storeKey) {
      const key = storeKey;
      storeKey = null;
      setTimeout(() => void storeModule(key), 0);
    }
  }
  const now = performance.now();
  if (now - winWall >= 500) {
    post({ type: 'stats', status: status(), window: { fields: winFields, ms: winMs, wallMs: now - winWall } });
    winFields = 0;
    winMs = 0;
    winWall = now;
  }
  if (ran < 0) {
    running = false;
    const discTrace = opts?.traceDisc ? cstr(M!._mvp_disc_trace()) : undefined;
    post({ type: 'stopped', status: status(), guestLine: cstr(M!._mvp_guest_line()), discTrace });
    return false;
  }
  return true;
}

// Paced: run the fields the wall clock asks for, then present once.
function runPaced(now: number): void {
  if (!running || paused || !M) return;
  let due = Math.floor((now - pacedStart) / FIELD_MS) - pacedFields;
  if (due > MAX_FIELDS_PER_FRAME * 2) {
    // Too far behind (a slow stretch, a background tab): drop the debt.
    pacedStart = now - pacedFields * FIELD_MS;
    due = 1;
  }
  due = Math.min(due, MAX_FIELDS_PER_FRAME);
  if (due <= 0) return;
  const t0 = performance.now();
  const ran = M._mvp_run_fields(due);
  pacedFields += Math.max(0, ran);
  afterRun(ran, performance.now() - t0);
}

function frame(now: number): void {
  runPaced(now);
  if (running) scope.requestAnimationFrame!(frame);
}

// Unpaced: as many fields as fit in the budget, then back to the event loop
// so the canvas shows the last one.
function fastLoop(): void {
  if (!running || !M) return;
  if (paused) {
    setTimeout(fastLoop, 50);
    return;
  }
  const t0 = performance.now();
  let ran = 0;
  while (performance.now() - t0 < FAST_BUDGET_MS) {
    const r = M._mvp_run_fields(1);
    if (r < 0) {
      ran = -1;
      break;
    }
    ran += r;
  }
  if (afterRun(ran, performance.now() - t0)) setTimeout(fastLoop, 0);
}

scope.onmessage = (ev: MessageEvent<ToWorker>) => {
  const msg = ev.data;
  switch (msg.type) {
    case 'start':
      start(msg.disc, msg.canvas, msg.width, msg.height, msg.options).catch((e: unknown) =>
        post({ type: 'error', stage: 'worker', message: String(e) }));
      break;
    case 'pad':
      setPad(msg.port, msg.pad);
      break;
    case 'tick':
      // Only without the Worker's own animation frames; this Worker's clock, not the page's.
      if (opts && !opts.fast && !scope.requestAnimationFrame) runPaced(performance.now());
      break;
    case 'resize':
      M?._mvp_canvas_resize(msg.width, msg.height);
      break;
    case 'pause':
      paused = msg.paused;
      if (!paused) {
        pacedStart = performance.now() - pacedFields * FIELD_MS;
      }
      break;
    case 'audio-port':
      audioPort = msg.port;
      enableAudio();
      break;
  }
};
