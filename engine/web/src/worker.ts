// The engine Worker (E2). Loads the engine module, reads the player's disc
// image from the File the page sent (never uploaded: FileReaderSync reads
// slices of it on demand, inside this Worker), translates the DOL, boots the
// machine and runs it one VI field at a time, drawing into the OffscreenCanvas
// the page transferred here.
//
// Pacing: each animation frame decides how many whole VI fields to run so the
// guest's virtual time keeps up with the wall clock (at most a few per frame;
// a long stall drops the debt instead of racing). Wall time decides only how
// many fields run, never what happens inside one: guest state depends on the
// disc and the per-frame pad inputs alone.

import createMvpEngine, { type MvpEngine } from './mvp-web.js';
import type { FromWorker, Pad, RunOptions, Status, ToWorker } from './protocol.js';

interface WorkerScope {
  postMessage(msg: FromWorker): void;
  onmessage: ((ev: MessageEvent<ToWorker>) => void) | null;
  requestAnimationFrame?: (cb: (now: number) => void) => number;
}
const scope = self as unknown as WorkerScope;

const FIELD_MS = 1000 / 59.94;   // NTSC field rate
const MAX_FIELDS_PER_FRAME = 4;  // catch-up limit per animation frame
const FAST_BUDGET_MS = 40;       // unpaced mode: run this long, then let the canvas present

let M: MvpEngine | null = null;
let opts: RunOptions | null = null;
let running = false, paused = false, firstFrame = false;
let pacedStart = 0, pacedFields = 0;
// Stats window (reported about twice a second).
let winFields = 0, winMs = 0, winWall = performance.now();

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

async function start(file: File, canvas: OffscreenCanvas | null, width: number, height: number,
                     options: RunOptions): Promise<void> {
  opts = options;
  const phase = (name: string, t0: number, detail?: unknown) =>
    post({ type: 'phase', name, ms: performance.now() - t0, detail });

  let t = performance.now();
  M = await createMvpEngine({
    print: (text) => post({ type: 'log', text, error: false }),
    printErr: (text) => post({ type: 'log', text, error: true }),
  });
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
  M.mvpDisc = file;
  if (!M._mvp_open_disc(file.size)) {
    post({ type: 'error', stage: 'disc', message: cstr(M._mvp_last_error()) });
    return;
  }
  phase('disc', t);
  post({ type: 'disc', info: JSON.parse(cstr(M._mvp_disc_info())) });

  // symbols.txt is repository metadata served with the engine.
  t = performance.now();
  const symbols = new Uint8Array(await (await fetch(new URL('symbols.txt', import.meta.url))).arrayBuffer());
  phase('symbols-fetch', t);

  t = performance.now();
  const ok = withBytes(symbols, (p, n) => M!._mvp_translate(p, n));
  if (!ok) {
    post({ type: 'error', stage: 'translate', message: cstr(M._mvp_last_error()) });
    return;
  }
  phase('translate', t, JSON.parse(cstr(M._mvp_translate_info())));

  t = performance.now();
  const script = new TextEncoder().encode(options.script);
  const booted = withBytes(script, (p, n) => M!._mvp_boot(p, options.script ? n : 0, options.stopFields,
                                                          options.stopFrames));
  if (!booted) {
    post({ type: 'error', stage: 'boot', message: cstr(M._mvp_last_error()) });
    return;
  }
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
  if (M!._mvp_present() && !firstFrame) {
    firstFrame = true;
    post({ type: 'first-frame', fields: status().fields });
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
    post({ type: 'stopped', status: status(), guestLine: cstr(M!._mvp_guest_line()) });
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
      start(msg.file, msg.canvas, msg.width, msg.height, msg.options).catch((e: unknown) =>
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
  }
};
