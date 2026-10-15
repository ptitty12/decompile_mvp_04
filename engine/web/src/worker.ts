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
//
// P2: where the page is cross-origin isolated (SharedArrayBuffer available) the
// Worker loads the threaded engine, mvp-web-mt.js: the GX processor and the
// WebGPU renderer run on a render thread (wasm/render_thread.h), to which this
// Worker hands the page's frame port (the page shows each frame as an
// ImageBitmap) or its canvas. Elsewhere, or with threads=0, it loads mvp-web.js
// and renders inline as before (into its own canvas and the frame port when the
// page gave one).

import type { MvpEngine, MvpEngineOptions } from './mvp-web.js';
import { probeDiscUrl } from './disc.js';
import { cacheKey, clearCache, readCached, writeCached } from './module-cache.js';
import { feedPacks, readReport, summarize } from './packs-core.js';
import type {
  CacheReport, DiscSource, FromWorker, NetOptions, NetStatus, Pad, RunOptions, Status, ToWorker, WorkletIn,
} from './protocol.js';

interface WorkerScope {
  postMessage(msg: FromWorker, transfer?: Transferable[]): void;
  onmessage: ((ev: MessageEvent<ToWorker>) => void) | null;
  requestAnimationFrame?: (cb: (now: number) => void) => number;
}
const scope = self as unknown as WorkerScope;

const FIELD_MS = 1000 / 59.94;   // NTSC field rate
const MAX_FIELDS_PER_FRAME = 4;  // catch-up limit per animation frame
const FAST_BUDGET_MS = 40;       // unpaced mode: run this long, then let the canvas present
const MAX_PREFETCH = 2;          // read-ahead requests in flight (server image)

let M: MvpEngine | null = null;
let mt = false;  // the threaded engine (P2)
let vsync: SharedArrayBuffer | null = null;  // the page's display refreshes (P2), for the render thread
let frames: MessagePort | null = null;       // P2: the page shows the frames sent here (instead of a canvas)
let opts: RunOptions | null = null;
let running = false, paused = false, firstFrame = false, booted = false;
let pacedStart = 0, pacedFields = 0;
let fieldsRun = 0, slowApplied = false;  // Q2 (development): hostSlow from hostSlowFrom on
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

function post(msg: FromWorker, transfer: Transferable[] = []): void {
  scope.postMessage(msg, transfer);
}

// ---- Netplay (E5) ----
// The page owns the WebRTC data channel; datagrams cross as messages. The
// session (wasm/net_web.cpp) is pumped every few milliseconds, and the run
// loop runs only while the next frame's input is known (mvp_run_fields stops
// early otherwise: `gated`). A datagram that arrives while gated retries at
// once instead of waiting for the next animation frame.
let net: NetOptions | undefined;
let gated = false;
let netTimer = 0;
let netLastReport = 0;
let netReportedEnd = false;
let channelOpen!: () => void;
const channelOpened = new Promise<void>((resolve) => (channelOpen = resolve));

function netStatus(): NetStatus {
  return JSON.parse(cstr(M!._mvp_net_status())) as NetStatus;
}

function reportNet(final: boolean): void {
  const status = netStatus();
  const ended = status.state !== 'handshake' && status.state !== 'running';
  post({
    type: 'net',
    status,
    windows: final || ended ? cstr(M!._mvp_net_windows()) : undefined,
    diagnostic: ended ? cstr(M!._mvp_net_diagnostic()) : undefined,
  });
}

function pumpNet(): void {
  if (!M) return;
  const state = M._mvp_net_pump();
  if (running && gated && !paused) runPaced(performance.now());
  const now = performance.now();
  const ended = state >= 2;
  if (now - netLastReport >= 500 || (ended && !netReportedEnd)) {
    netLastReport = now;
    if (ended) netReportedEnd = true;
    reportNet(false);
  }
}

async function buildId(parts: Uint8Array[]): Promise<string> {
  const all = new Uint8Array(parts.reduce((n, p) => n + p.length, 0));
  let at = 0;
  for (const p of parts) {
    all.set(p, at);
    at += p.length;
  }
  const h = new Uint8Array(await crypto.subtle.digest('SHA-256', all));
  return 'web-' + Array.from(h.slice(0, 12), (b) => b.toString(16).padStart(2, '0')).join('');
}

// Starts the session once the channel is open and waits for the handshake's end.
async function startNetplay(o: NetOptions, symbols: Uint8Array): Promise<boolean> {
  const fetchBytes = async (name: string) =>
    new Uint8Array(await (await fetch(new URL(name, import.meta.url))).arrayBuffer());
  // The engine build id: the engine module, its JS glue and the symbol map
  // (function boundaries are safe points): both players must run the same.
  const build = await buildId([await fetchBytes('mvp-web.wasm'), await fetchBytes('mvp-web.js'), symbols]);
  M!.mvpNetSend = (d: Uint8Array) => {
    const copy = d.slice().buffer;
    post({ type: 'net-send', data: copy }, [copy]);
  };
  await channelOpened;
  const r = crypto.getRandomValues(new Uint32Array(2));
  const nonce = r[0]! * 2 ** 21 + (r[1]! & 0x1fffff);  // 53 bits, exact in a double
  const ok = withBytes(new TextEncoder().encode(build), (p, n) => M!._mvp_net_begin(o.player, o.delay, o.hashEvery, p, n, nonce));
  if (!ok) return false;
  netTimer = setInterval(pumpNet, 4) as unknown as number;
  for (;;) {
    const state = M!._mvp_net_pump();
    if (state !== 0) {
      reportNet(false);
      return state === 1;
    }
    await new Promise((resolve) => setTimeout(resolve, 5));
  }
}

function cstr(ptr: number): string {
  return M ? M.UTF8ToString(ptr) : '';
}

// The engine's memory as bytes. The threaded engine's memory is shared and can be
// grown by the render thread, which leaves this thread's HEAPU8 too short: a
// fresh view then (P2).
function heap(): Uint8Array {
  const h = M!.HEAPU8, mem = M!.wasmMemory;
  return mem && h.buffer !== mem.buffer ? new Uint8Array(mem.buffer) : h;
}

// The engine module: the threaded one where this Worker may share memory with
// threads (cross-origin isolated) and the page did not ask for threads=0, else
// the single-threaded one.
async function loadEngine(threads: boolean, o: MvpEngineOptions): Promise<MvpEngine> {
  const canShare = (self as unknown as { crossOriginIsolated?: boolean }).crossOriginIsolated === true &&
                   typeof SharedArrayBuffer !== 'undefined';
  if (threads && canShare) {
    try {
      const m = await import('./mvp-web-mt.js');
      const engine = await m.default(o);
      mt = true;
      return engine;
    } catch (e) {
      post({ type: 'log', text: `mvp: the threaded engine did not load (${String(e)}); single-threaded`, error: true });
    }
  }
  const m = await import('./mvp-web.js');
  return m.default(o);
}

function status(): Status {
  return JSON.parse(cstr(M!._mvp_status())) as Status;
}

function withBytes<T>(bytes: Uint8Array, f: (ptr: number, len: number) => T): T {
  const ptr = M!._malloc(Math.max(1, bytes.length));
  heap().set(bytes, ptr);
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
    return heap().subarray(ptr, ptr + size);
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
  const head = M!._mvp_module_blob();
  if (!head) return;
  const len = M!._mvp_module_bytes_len(), n = head + len;
  // A copy outside the engine's heap (which can grow while the write awaits).
  const bytes = new Uint8Array(n);
  const hp = M!._mvp_module_blob_ptr(), bp = M!._mvp_module_bytes_ptr();
  bytes.set(heap().subarray(hp, hp + head), 0);
  bytes.set(heap().subarray(bp, bp + len), head);
  M!._mvp_module_release();
  const r = await writeCached(key, bytes);
  post({ type: 'cache', report: { key, hit: false, bytes: n, ...('ms' in r ? { storedMs: r.ms } : { error: r.error }) } });
}

function enableAudio(): void {
  if (!M || !booted || !opts?.audio || !audioPort || audioAttached) return;
  M._mvp_audio_enable(1);
  audioAttached = true;
  audioRing();
  post({ type: 'audio', attachedAtField: status().fields });
}

// Q2: where memory can be shared (a cross-origin isolated page), the frames go
// to the worklet through a ring in shared memory (web_audio.h's AudioRing
// layout): the threaded engine's mixer writes into one in the engine's own
// memory as it mixes; the single-threaded engine's batches are copied into one
// here. Elsewhere (or audioRing=0) each batch is a message.
const RING_FRAMES = 16384;  // about half a second at 32 kHz
let ringOut: { h: Int32Array; frames: Int16Array; cap: number } | null = null;
function audioRing(): void {
  const canShare = (self as unknown as { crossOriginIsolated?: boolean }).crossOriginIsolated === true &&
                   typeof SharedArrayBuffer !== 'undefined';
  if (!M || !audioPort || opts?.audioRing === false || !canShare) return;
  let msg: WorkletIn | null = null;
  if (mt && M.wasmMemory) {
    const header = M._mvp_audio_ring(RING_FRAMES);
    if (header) msg = { type: 'ring', sab: M.wasmMemory.buffer as unknown as SharedArrayBuffer, header };
  }
  if (!msg) {
    const sab = new SharedArrayBuffer(64 + 4 * RING_FRAMES);
    const h = new Int32Array(sab, 0, 16);
    h.set([0x4d565041, RING_FRAMES, 32000, 0, 0, 0, 64]);
    ringOut = { h, frames: new Int16Array(sab, 64, 2 * RING_FRAMES), cap: RING_FRAMES };
    msg = { type: 'ring', sab, header: 0 };
  }
  audioPort.postMessage(msg);
}

// The batch's mixed frames, to the worklet: into the Worker's ring, or as a
// message (the buffer transferred). Nothing to do with the engine's own ring.
function pumpAudio(): void {
  if (!audioAttached || !audioPort || !M) return;
  const n = M._mvp_audio_take();
  if (!n) return;
  const ptr = M._mvp_audio_ptr();
  if (ringOut) {
    const { h, frames, cap } = ringOut;
    const w = Atomics.load(h, 3) >>> 0, used = (w - (Atomics.load(h, 4) >>> 0)) >>> 0;
    const k = Math.min(n, cap - used), at = w & (cap - 1), first = Math.min(k, cap - at);
    const src = new Int16Array(heap().buffer, ptr, 2 * n);
    frames.set(src.subarray(0, 2 * first), 2 * at);
    if (k > first) frames.set(src.subarray(2 * first, 2 * k), 0);
    Atomics.store(h, 2, M._mvp_audio_rate());
    Atomics.store(h, 3, (w + k) | 0);
    if (k < n) Atomics.add(h, 5, n - k);
    return;
  }
  // A copy in its own (never shared) buffer, to transfer.
  const data = new Int16Array(heap().slice(ptr, ptr + 4 * n).buffer);
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
  M = await loadEngine(options.threads !== false, {
    print: (text) => post({ type: 'log', text, error: false }),
    printErr: (text) => post({ type: 'log', text, error: true }),
  });
  M.mvpOnProgress = (text, step, steps) => post({ type: 'progress', text, step, steps });
  phase('engine', t, { threads: mt });

  // Ask for the GPU first: the adapter and device requests complete while
  // the DOL is translated.
  let gfxReady: Promise<boolean> = Promise.resolve(false);
  if (options.render && (canvas || frames) && 'gpu' in navigator) {
    // P2: with a frame port the engine draws into a canvas of its own and sends
    // each frame to the page as an ImageBitmap; else into the page's canvas.
    if (frames && !mt) {
      M.specialHTMLTargets['#mvp-canvas'] = new OffscreenCanvas(width, height);
      M.mvpFrames = frames;
    } else if (canvas) {
      M.specialHTMLTargets['#mvp-canvas'] = canvas;
    }
    // P2: the render thread takes the canvas or the frame port (the engine posts it there).
    if (mt) {
      M.mvpCanvas = canvas;
      M.mvpFrames = frames;
      M.mvpVsync = vsync;
      M._mvp_set_threaded(1);
      const tune = options.rtTune;
      if (tune) M._mvp_render_tune(tune[0] ?? -1, tune[1] ?? -1, tune[2] ?? 0, tune[3] ?? -1);
    }
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

  // Roster packs (E6): checked, applied to this disc's tables and mounted on the
  // virtual disc before anything boots. The handshake below carries their set hash.
  if (options.packs?.length) {
    t = performance.now();
    post({ type: 'progress', text: 'Applying the roster packs to your disc', step: 0, steps: 0 });
    feedPacks(M, options.packs);
    const ok = M._mvp_packs_mount();
    const report = readReport(M);
    post({ type: 'packs', report });
    if (!ok) {
      post({ type: 'error', stage: 'packs', message: summarize(report) });
      return;
    }
    phase('packs', t, { files: report.files, bytes: report.bytes });
  }

  // The translation: this browser's cache, else the translator.
  const fetchSymbols = async () => new Uint8Array(await (await fetch(new URL('symbols.txt', import.meta.url))).arrayBuffer());
  let symbols: Uint8Array | null = null;
  const report: CacheReport = { key: null, hit: false };
  t = performance.now();
  if (options.cache) report.key = await cacheKey(info.dol_sha1, new URL('build-id.json', import.meta.url), mt);
  if (report.key && (await loadCached(report.key, report))) {
    phase('translate', t, JSON.parse(cstr(M._mvp_translate_info())));
  } else {
    // symbols.txt is repository metadata served with the engine.
    t = performance.now();
    post({ type: 'progress', text: 'Translating: fetching the symbol map', step: 0, steps: 5 });
    symbols = await fetchSymbols();
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

  if (options.netplay) {
    net = options.netplay;
    t = performance.now();
    // The netplay build id hashes symbols.txt too (a warm start did not fetch it).
    if (!(await startNetplay(options.netplay, symbols ?? (await fetchSymbols())))) {
      const st = netStatus();
      post({ type: 'error', stage: 'netplay', message: st.reason || 'the online game could not start' });
      return;
    }
    phase('netplay-handshake', t);
  }

  t = performance.now();
  post({ type: 'progress', text: 'Booting', step: 5, steps: 5 });
  if (options.ioLog) M._mvp_io_log_enable();
  if (options.inputLog) M._mvp_input_log_enable();
  const script = new TextEncoder().encode(options.script);
  const ok = withBytes(script, (p, n) => M!._mvp_boot(p, options.script ? n : 0, options.stopFields,
                                                      options.stopFrames));
  if (!ok) {
    post({ type: 'error', stage: 'boot', message: cstr(M._mvp_last_error()) });
    return;
  }
  booted = true;
  if (options.tracePresent) M._mvp_trace(1);
  if (options.digest) M._mvp_digest(1, options.digestDetail?.[0] ?? 1, options.digestDetail?.[1] ?? 0);
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
  if (options.fast || options.fastUntil) setTimeout(fastLoop, 0);
  else if (scope.requestAnimationFrame) scope.requestAnimationFrame(frame);
  // else: the page sends 'tick' messages from its own animation frames.
}

function afterRun(ran: number, ms: number): boolean {
  winFields += Math.max(0, ran);
  winMs += ms;
  fieldsRun += Math.max(0, ran);
  if (opts?.hostSlow && !slowApplied && fieldsRun >= (opts.hostSlowFrom ?? 0)) {
    slowApplied = true;
    M!._mvp_host_slow(opts.hostSlow);
  }
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
    const trace = opts?.tracePresent ? JSON.parse(cstr(M!._mvp_trace_take())) as unknown[] : undefined;
    const digest = opts?.digest ? cstr(M!._mvp_digest_take()) : undefined;
    const sat = saturatedMs + (saturated ? now - saturatedSince : 0);
    post({ type: 'stats', status: status(),
           window: { fields: winFields, ms: winMs, wallMs: now - winWall, trace, digest, saturatedMs: sat,
                     fieldCost } });
    winFields = 0;
    winMs = 0;
    winWall = now;
  }
  if (ran < 0) {
    running = false;
    if (opts?.digest) {  // the last fields' digests (the render thread has drawn them by now, threaded or not)
      const digest = cstr(M!._mvp_digest_take());
      if (digest) post({ type: 'stats', status: status(), window: { fields: 0, ms: 0, wallMs: 0, digest } });
    }
    const discTrace = opts?.traceDisc ? cstr(M!._mvp_disc_trace()) : undefined;
    const ioLog = opts?.ioLog ? cstr(M!._mvp_io_log()) : undefined;
    const inputLog = opts?.inputLog ? cstr(M!._mvp_input_log()) : undefined;
    post({ type: 'stopped', status: status(), guestLine: cstr(M!._mvp_guest_line()), discTrace, ioLog, inputLog });
    if (net) reportNet(true);
    return false;
  }
  return true;
}

// Paced: run the fields the wall clock asks for, then present once.
//
// P1 (chase, the default): a field that takes longer than the display's refresh
// used to cost a whole refresh (its frame showed only at the animation frame
// after the next), and the animation frame after that ran two to four fields at
// once: in heavy scenes the picture moved in jumps of 33-67 ms. Now at most two
// fields run per batch (two only when two are due), and while the clock is
// still ahead of the run the next batch runs in its own task at once, without
// waiting for an animation frame; each batch's frame is presented when its task
// ends. Ahead of the clock the loop waits for animation frames as before.
// pacing=raf (URL) keeps the earlier batches of up to four fields per animation frame.
//
// Q2 (saturated): on a machine that cannot run the game at full speed (the
// fields take longer than the display's refresh on average), chasing the clock
// only made it worse: two-field batches showed every other frame of the game
// (its picture moved in 33 ms jumps), and debts of up to eight fields came and
// went in bursts. While the host time per field (smoothed over about a second)
// is a whole field or more, every batch is one field, each followed by
// its present, back to back, and the clock never waits for more than two
// fields of debt: the game runs evenly in slow motion, every frame shown, and
// the sound stretches to match (resampler.ts). Under 90 % it chases again.
// Threaded engine only: there the render thread presents, so a present per
// field costs the emulation nothing; the single-threaded engine presents
// inline (measured: a present per field cost it 10 % of its speed on this
// PC), so it keeps chasing with two-field batches. Guest state is the same
// either way (wall time decides only how many fields run per batch).
const CHASE_FIELDS = 2;
const SATURATED_ON = 1.0, SATURATED_OFF = 0.9, SATURATED_S = 1.0;
let fieldCost = 0;          // smoothed host ms per field, as a share of a field
let saturated = false;
let saturatedMs = 0;        // statistics: wall time spent saturated
let saturatedSince = 0;
const chase = new MessageChannel();
let chasePending = false;
chase.port1.onmessage = () => {
  chasePending = false;
  runPaced(performance.now());
};

function runPaced(now: number): void {
  if (!running || paused || !M) return;
  let due = Math.floor((now - pacedStart) / FIELD_MS) - pacedFields;
  const slowMotion = saturated && mt;  // the threaded engine: presenting costs the emulation nothing
  if (due > (slowMotion ? 2 : MAX_FIELDS_PER_FRAME * 2)) {
    // Too far behind (a slow stretch, a background tab, a slow machine): drop the debt.
    pacedStart = now - pacedFields * FIELD_MS;
    due = 1;
  }
  const rafOnly = opts?.pacing === 'raf';
  due = Math.min(due, rafOnly ? MAX_FIELDS_PER_FRAME : slowMotion ? 1 : due >= 3 ? CHASE_FIELDS : 1);
  if (due <= 0) return;
  const t0 = performance.now();
  const ran = M._mvp_run_fields(due);
  const ms = performance.now() - t0;
  pacedFields += Math.max(0, ran);
  if (ran > 0) {
    fieldCost += (1 - Math.exp(-(ran * FIELD_MS) / (1000 * SATURATED_S))) * (ms / ran / FIELD_MS - fieldCost);
    if (!saturated && fieldCost >= SATURATED_ON) {
      saturated = true;
      saturatedSince = t0;
    } else if (saturated && fieldCost < SATURATED_OFF) {
      saturated = false;
      saturatedMs += t0 - saturatedSince;
    }
  }
  gated = !!net && ran >= 0 && ran < due;
  if (!afterRun(ran, ms) || rafOnly || gated) return;
  // Still behind: the next batch now, in its own task (this one's frame is presented when it ends).
  if (!chasePending && Math.floor((performance.now() - pacedStart) / FIELD_MS) - pacedFields >= 1) {
    chasePending = true;
    chase.port2.postMessage(0);
  }
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
    if (net && r === 0) break;  // waiting for the other player: let datagrams in
  }
  if (!afterRun(ran, performance.now() - t0)) return;
  if (!opts?.fast && opts?.fastUntil && status().fields >= opts.fastUntil) {
    // Development (fastUntil): from here on paced, as a player runs it.
    pacedStart = performance.now();
    pacedFields = 0;
    if (scope.requestAnimationFrame) scope.requestAnimationFrame(frame);
    return;
  }
  setTimeout(fastLoop, 0);
}

scope.onmessage = (ev: MessageEvent<ToWorker>) => {
  const msg = ev.data;
  switch (msg.type) {
    case 'start':
      vsync = msg.vsync ?? null;
      frames = msg.frames ?? null;
      start(msg.disc, msg.canvas, msg.width, msg.height, msg.options).catch((e: unknown) =>
        post({ type: 'error', stage: 'worker', message: String(e) }));
      break;
    case 'pad':
      setPad(msg.port, msg.pad);
      break;
    case 'tick':
      // Only without the Worker's own animation frames; this Worker's clock, not the page's.
      if (opts && !opts.fast && !opts.fastUntil && !scope.requestAnimationFrame) runPaced(performance.now());
      break;
    case 'resize':
      M?._mvp_canvas_resize(msg.width, msg.height);
      break;
    case 'net-open':
      channelOpen();
      break;
    case 'net-recv':
      if (M) {
        withBytes(new Uint8Array(msg.data), (p, n) => M!._mvp_net_recv(p, n));
        if (running && gated && !paused) {
          M._mvp_net_pump();
          runPaced(performance.now());
        }
      }
      break;
    case 'net-quit':
      if (M && net) {
        M._mvp_net_quit();
        clearInterval(netTimer);
      }
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
