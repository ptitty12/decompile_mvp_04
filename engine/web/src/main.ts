// The page (E2): the disc picker, the canvas, input, and what the engine
// Worker reports. The player's disc image is handed to the Worker as a File
// (a local handle); it is never uploaded, and the page fetches nothing but
// the engine's own files from its origin.
//
// URL parameters (development and the local browser check, tools/browser_check.mjs):
//   script=TEXT   an mvp-input script instead of live input (newlines as %0A)
//   fields=N      stop after N VI fields; frames=N: at the poll of frame N
//   fast=1        run unpaced, as fast as possible
//   render=0      no WebGPU at all
// The page publishes its state as `window.mvp` for the browser check.

import { HostInput } from './input.js';
import type { FromWorker, Pad, RunOptions, Status, ToWorker } from './protocol.js';

interface PageState {
  pickedAt: number;            // performance.now() when the image was picked
  phases: Record<string, number>;
  translate?: unknown;
  disc?: unknown;
  gfx?: { ok: boolean; message: string };
  firstFrameMs?: number;       // from the pick to the first frame on the canvas
  firstFrameField?: number;
  stats?: { status: Status; window: { fields: number; ms: number; wallMs: number } };
  stopped?: { status: Status; guestLine: string };
  error?: { stage: string; message: string };
  log: string[];
}

const state: PageState = { pickedAt: 0, phases: {}, log: [] };
(window as unknown as { mvp: PageState }).mvp = state;

const $ = <T extends HTMLElement>(id: string) => document.getElementById(id) as T;
const picker = $<HTMLInputElement>('disc');
const canvas = $<HTMLCanvasElement>('screen');
const statusEl = $<HTMLElement>('status');
const phasesEl = $<HTMLElement>('phases');
const statsEl = $<HTMLElement>('stats');
const logEl = $<HTMLElement>('log');
const errorEl = $<HTMLElement>('error');

const params = new URLSearchParams(location.search);
const options: RunOptions = {
  script: params.get('script') ?? '',
  stopFields: Number(params.get('fields') ?? 0) || 0,
  stopFrames: Number(params.get('frames') ?? 0) || 0,
  fast: params.get('fast') === '1',
  render: params.get('render') !== '0',
};

const hasWebGPU = 'gpu' in navigator;
const hasOffscreen = typeof canvas.transferControlToOffscreen === 'function';
setStatus(hasWebGPU ? 'Pick your disc image to start.'
                    : 'This browser has no WebGPU: the game can run, but nothing will be drawn.');

function setStatus(text: string): void {
  statusEl.textContent = text;
}

function log(text: string, error = false): void {
  state.log.push(text);
  if (state.log.length > 2000) state.log.splice(0, state.log.length - 2000);
  const line = document.createElement('div');
  line.textContent = text;
  if (error) line.className = 'err';
  logEl.append(line);
  while (logEl.childElementCount > 500) logEl.firstElementChild?.remove();
}

function showError(stage: string, message: string): void {
  state.error = { stage, message };
  const reason = stage === 'disc'
    ? `This image cannot be used. The engine runs MVP Baseball 2005 for GameCube, USA (GV4E69), revision 0 only. (${message})`
    : `${stage}: ${message}`;
  errorEl.textContent = reason;
  errorEl.hidden = false;
  setStatus('Stopped.');
}

function showPhases(): void {
  const names: Record<string, string> = {
    engine: 'engine module', gpu: 'WebGPU device', disc: 'disc check (DOL SHA-1)', 'symbols-fetch': 'symbols.txt',
    translate: 'translate + compile', boot: 'boot', 'gpu-wait': 'wait for WebGPU',
  };
  const rows = Object.entries(state.phases).map(([k, v]) => `${names[k] ?? k}: ${v.toFixed(0)} ms`);
  const t = state.translate as Record<string, number> | undefined;
  if (t) rows.push(`  (CFG ${t.cfg_ms.toFixed(0)} ms, emit ${t.emit_ms.toFixed(0)} ms, compile ${t.compile_ms.toFixed(0)} ms, ` +
                   `instantiate ${t.instantiate_ms.toFixed(0)} ms, module ${(t.module_bytes / 1048576).toFixed(1)} MB)`);
  if (state.firstFrameMs !== undefined) rows.push(`first frame: ${state.firstFrameMs.toFixed(0)} ms after the pick`);
  phasesEl.textContent = rows.join('\n');
}

let worker: Worker | null = null;
const input = new HostInput(window, (pad: Pad) => send({ type: 'pad', port: 0, pad }));

function send(msg: ToWorker, transfer: Transferable[] = []): void {
  worker?.postMessage(msg, transfer);
}

function onWorker(msg: FromWorker): void {
  switch (msg.type) {
    case 'log':
      log(msg.text, msg.error);
      break;
    case 'phase':
      state.phases[msg.name] = msg.ms;
      if (msg.name === 'translate') state.translate = msg.detail;
      if (msg.name === 'translate') setStatus('Booting...');
      showPhases();
      break;
    case 'disc':
      state.disc = msg.info;
      setStatus(`${msg.info.title} (${msg.info.game} rev ${msg.info.revision}, ${msg.info.image}): translating...`);
      break;
    case 'gfx':
      state.gfx = { ok: msg.ok, message: msg.message };
      log(`WebGPU: ${msg.ok ? 'ready on ' : ''}${msg.message}`, !msg.ok);
      break;
    case 'first-frame':
      state.firstFrameMs = performance.now() - state.pickedAt;
      state.firstFrameField = msg.fields;
      setStatus('Running. Enter = START, X = A, Z = B, arrows = D-pad.');
      showPhases();
      break;
    case 'stats': {
      state.stats = { status: msg.status, window: msg.window };
      const s = msg.status, w = msg.window;
      const perField = w.fields ? w.ms / w.fields : 0;
      statsEl.textContent =
        `field ${s.fields}, frame ${s.frames}, guest ${s.guest_s.toFixed(1)} s | ` +
        `${w.fields} fields in ${(w.wallMs / 1000).toFixed(2)} s (${(w.fields / (w.wallMs / 1000)).toFixed(1)}/s), ` +
        `${perField.toFixed(2)} ms per field | draws ${s.draws ?? 0}, GPU errors ${s.gpu_errors ?? 0}`;
      break;
    }
    case 'stopped':
      state.stopped = { status: msg.status, guestLine: msg.guestLine };
      setStatus(`Stopped: ${msg.status.why ?? ''}`);
      log(msg.guestLine);
      break;
    case 'error':
      showError(msg.stage, msg.message);
      break;
  }
}

picker.addEventListener('change', () => {
  const file = picker.files?.[0];
  if (!file || worker) return;
  state.pickedAt = performance.now();
  picker.disabled = true;
  errorEl.hidden = true;
  setStatus(`Reading ${file.name}...`);
  worker = new Worker(new URL('./worker.js', import.meta.url), { type: 'module' });
  worker.onmessage = (ev: MessageEvent<FromWorker>) => onWorker(ev.data);
  worker.onerror = (ev) => showError('worker', ev.message || 'the engine Worker failed to start');
  const dpr = Math.min(window.devicePixelRatio || 1, 2);
  const width = Math.round(canvas.clientWidth * dpr), height = Math.round(canvas.clientHeight * dpr);
  let off: OffscreenCanvas | null = null;
  if (hasOffscreen && options.render) {
    canvas.width = width;
    canvas.height = height;
    off = canvas.transferControlToOffscreen();
  }
  send({ type: 'start', file, canvas: off, width, height, options }, off ? [off] : []);
  input.poll();
  new ResizeObserver(() => {
    const w = Math.round(canvas.clientWidth * dpr), h = Math.round(canvas.clientHeight * dpr);
    if (w > 0 && h > 0) send({ type: 'resize', width: w, height: h });
  }).observe(canvas);
});

document.addEventListener('visibilitychange', () => send({ type: 'pause', paused: document.hidden }));

function tick(now: number): void {
  input.poll();
  send({ type: 'tick', now });
  requestAnimationFrame(tick);
}
requestAnimationFrame(tick);
