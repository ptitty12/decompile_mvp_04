// Local browser check for E2/E2c (needs the player's disc; never run in CI):
// serves the site, opens it in a real browser with Playwright, gives it the
// disc image (through the page's file input, or from the mock deployment's
// /config.json with --server-disc), and records the startup phases, the cold
// start (start -> first frame), frame times, canvas screenshots, audio levels,
// and the determinism line.
//
//   node engine/web/tools/browser_check.mjs --browser chrome|msedge|chromium|firefox|webkit
//        [--disc PATH] [--out DIR] [--script FILE] [--fields N] [--frames N] [--fast]
//        [--shots F1,F2,...] [--keys F1:KEY,F2:KEY,...] [--headed] [--timeout SECONDS] [--no-render]
//        [--js-flags FLAGS] [--tag NAME]
//        [--server-disc [--login] [--latency MS] [--rate MBPS]] [--audio | --no-audio] [--audible]
//        [--audio-latency MS] [--pad F:button:I,F:axis:I:V,...] [--runs N] [--clear-cache] [--no-cache]
//        [--hide F:MS] [--trace-disc] [--disc-cache PARAMS] [--hold MS]
//
//   --disc     the image (default: $MVP_DISC). It goes to the page's file input
//              locally (or, with --server-disc, to the mock server on 127.0.0.1)
//   --out      where screenshots and the summary go (default build/engine/web-check);
//              keep it under build/: screenshots are game-derived, never committed
//   --script   an mvp-input script file (runtime/input.h) for the run
//   --fields / --frames   stop there and print the guest line (MEM1 SHA-1)
//   --fast     unpaced (as fast as possible); default paced to 59.94 fields/s
//   --shots    VI fields at which to screenshot the canvas (approximately: the
//              page reports progress twice a second)
//   --keys     live keyboard input: press KEY (a KeyboardEvent key name, e.g.
//              Enter, x, ArrowDown) for 150 ms (--hold MS) once the run reaches field F
//   --js-flags V8 flags for Chrome/Edge/Chromium (experiments, e.g. --no-wasm-tier-up)
//   --tag      added to the output file names (summary-BROWSER-TAG.json, ...)
//   --server-disc  the mock deployment (serve.mjs --disc): the page finds the
//              image in /config.json and loads it without the picker. --login:
//              the mock's API wants a login (expect the login error); --latency,
//              --rate: a slow server
//   --audio    click the page first (the user gesture that starts audio), then
//              sample the worklet's output through the page's AnalyserNode tap.
//              The browser's output is muted (--audible: not muted)
//   --no-audio the page never mixes (audio=0), for the determinism comparison
//   --pad      a fake standard gamepad (navigator.getGamepads replaced before the
//              page loads): at field F press button I for 150 ms, or hold axis I
//              at V for 300 ms
//   --runs N   N runs in one browser context (one profile): run 1 is cold, later
//              runs find the translation cached; --clear-cache empties the cache
//              first; --no-cache: cache=0
//   --hide     at field F, report the tab hidden for MS ms (the pause), then shown
//   --trace-disc  record the picked image's reads (offsets and sizes, no data)
//              into OUT/disc-trace-*.txt, to tune the server image's cache
//   --disc-cache  that cache's settings as page parameters (discBlock=KIB&
//              discBlocks=N&discRun=N&discAhead=N)
//
// Exit status: 0 when every run reached its first frame (and its stop, if any),
// 1 otherwise, 77 without a disc.

import { spawn } from 'node:child_process';
import { existsSync, mkdirSync, readFileSync, writeFileSync } from 'node:fs';
import { join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { chromium, firefox, webkit } from 'playwright';

const here = fileURLToPath(new URL('.', import.meta.url));
const repo = resolve(here, '..', '..', '..');
const argv = process.argv.slice(2);
const opt = (name, fallback) => {
  const i = argv.indexOf(name);
  return i >= 0 && i + 1 < argv.length ? argv[i + 1] : fallback;
};
const flag = (name) => argv.includes(name);

const browserName = opt('--browser', 'chrome');
const disc = opt('--disc', process.env.MVP_DISC ?? '');
const out = resolve(opt('--out', join(repo, 'build', 'engine', 'web-check')));
const scriptFile = opt('--script', '');
const fields = Number(opt('--fields', '0'));
const frames = Number(opt('--frames', '0'));
const fast = flag('--fast');
const headed = flag('--headed');
const render = !flag('--no-render');
const timeoutS = Number(opt('--timeout', '600'));
const jsFlags = opt('--js-flags', '');
const tag = opt('--tag', '');
const serverDisc = flag('--server-disc');
const login = flag('--login');
const latency = opt('--latency', '');
const rate = opt('--rate', '');
const audio = flag('--audio');
const noAudio = flag('--no-audio');
const audible = flag('--audible');
const audioLatency = opt('--audio-latency', '');
const runs = Math.max(1, Number(opt('--runs', '1')));
const clearCache = flag('--clear-cache');
const noCache = flag('--no-cache');
const traceDisc = flag('--trace-disc');
const discParams = opt('--disc-cache', '');  // e.g. discBlock=256&discRun=8&discAhead=8
const label = tag ? `${browserName}-${tag}` : browserName;
const chromiumArgs = ['--enable-unsafe-webgpu', ...(audible ? [] : ['--mute-audio']),
                      ...(jsFlags ? [`--js-flags=${jsFlags}`] : [])];
const shots = opt('--shots', '').split(',').filter(Boolean).map(Number).sort((a, b) => a - b);
const keys = opt('--keys', '').split(',').filter(Boolean).map((k) => {
  const [f, key] = k.split(':');
  return { field: Number(f), key };
}).sort((a, b) => a.field - b.field);
const pads = opt('--pad', '').split(',').filter(Boolean).map((p) => {
  const [f, kind, index, value] = p.split(':');
  return { field: Number(f), kind, index: Number(index), value: value === undefined ? 1 : Number(value) };
}).sort((a, b) => a.field - b.field);
const hide = opt('--hide', '') ? opt('--hide', '').split(':').map(Number) : null;
const holdMs = Number(opt('--hold', '150'));  // how long --keys and --pad buttons stay down

if (!disc || !existsSync(disc)) {
  console.error('browser_check: no disc image (--disc or MVP_DISC)');
  process.exit(77);
}
mkdirSync(out, { recursive: true });

// The server, on a free port.
const serverArgs = [join(here, 'serve.mjs'), '--port', '0'];
if (serverDisc) {
  serverArgs.push('--disc', disc);
  if (login) serverArgs.push('--login');
  if (latency) serverArgs.push('--latency', latency);
  if (rate) serverArgs.push('--rate', rate);
}
const server = spawn(process.execPath, serverArgs, { stdio: ['ignore', 'pipe', 'inherit'] });
const base = await new Promise((resolveUrl, reject) => {
  server.stdout.on('data', (d) => {
    const m = /serving (http:\/\/\S+)/.exec(String(d));
    if (m) resolveUrl(m[1]);
  });
  server.on('exit', (code) => reject(new Error(`server exited ${code}`)));
});

const launchers = {
  chrome: () => chromium.launch({ channel: 'chrome', headless: !headed, args: chromiumArgs }),
  msedge: () => chromium.launch({ channel: 'msedge', headless: !headed, args: chromiumArgs }),
  chromium: () => chromium.launch({ headless: !headed, args: chromiumArgs }),
  firefox: () => firefox.launch({
    headless: !headed,
    firefoxUserPrefs: {
      'dom.webgpu.enabled': true, 'dom.webgpu.workers.enabled': true, 'gfx.webgpu.ignore-blocklist': true,
      ...(audible ? {} : { 'media.volume_scale': '0.0' }),
    },
  }),
  webkit: () => webkit.launch({ headless: !headed }),
};
if (!launchers[browserName]) {
  console.error(`browser_check: unknown browser ${browserName}`);
  process.exit(2);
}

// A fake standard gamepad (Playwright cannot emulate one): the page's
// navigator.getGamepads returns window.__fakePad, which the check edits.
function fakeGamepad() {
  const pad = {
    id: 'browser_check fake pad (STANDARD GAMEPAD)', index: 0, connected: true, mapping: 'standard', timestamp: 0,
    buttons: Array.from({ length: 17 }, () => ({ pressed: false, touched: false, value: 0 })),
    axes: [0, 0, 0, 0],
  };
  window.__fakePad = pad;
  Object.defineProperty(navigator, 'getGamepads', { value: () => [pad, null, null, null], configurable: true });
}

// The tab hidden or shown, as the page sees it.
function setHidden(hidden) {
  Object.defineProperty(document, 'hidden', { value: hidden, configurable: true });
  Object.defineProperty(document, 'visibilityState', { value: hidden ? 'hidden' : 'visible', configurable: true });
  document.dispatchEvent(new Event('visibilitychange'));
}

async function runOnce(context, run) {
  const summary = { run };
  const page = await context.newPage();
  const consoleErrors = [];
  page.on('console', (m) => {
    if (m.type() === 'error') consoleErrors.push(m.text());
  });
  page.on('pageerror', (e) => consoleErrors.push(String(e)));
  // Only the local server's own files: the disc goes in through the file input
  // or from the mock deployment on the same origin.
  const requests = [];
  page.on('request', (r) => requests.push(r.url()));
  if (pads.length) await page.addInitScript(fakeGamepad);

  const q = new URLSearchParams();
  if (scriptFile) q.set('script', readFileSync(scriptFile, 'utf8'));
  if (fields) q.set('fields', String(fields));
  if (frames) q.set('frames', String(frames));
  if (fast) q.set('fast', '1');
  if (!render) q.set('render', '0');
  if (noAudio) q.set('audio', '0');
  if (noCache) q.set('cache', '0');
  if (audioLatency) q.set('audioLatency', audioLatency);
  if (traceDisc) q.set('traceDisc', '1');
  for (const [k, v] of new URLSearchParams(discParams)) q.set(k, v);
  const t0 = Date.now();
  await page.goto(`${base}?${q}`);
  if (run === 1 && clearCache) {
    await page.evaluate(async () => {
      const root = await navigator.storage.getDirectory();
      await root.removeEntry('mvp-translated', { recursive: true }).catch(() => undefined);
    });
  }
  summary.webgpu = await page.evaluate(() => 'gpu' in navigator);
  // The user gesture that starts audio: a real click on the page.
  if (audio) await page.mouse.click(5, 5);
  if (!serverDisc) await page.setInputFiles('#disc', disc);

  const deadline = t0 + timeoutS * 1000;
  const mvp = () => page.evaluate(() => {
    const s = window.mvp;
    return { source: s.source, phases: s.phases, translate: s.translate, disc: s.disc, gfx: s.gfx,
             firstFrameMs: s.firstFrameMs, firstFrameField: s.firstFrameField, stats: s.stats, stopped: s.stopped,
             error: s.error, cache: s.cache, audio: s.audio, audioAttachedAtField: s.audioAttachedAtField,
             paused: s.paused, pad: s.pad, probe: s.audioProbe(), discTrace: s.discTrace };
  });
  const windows = [];
  const audioSamples = { n: 0, nonsilent: 0, maxRms: 0, maxPeak: 0, firstNonsilentField: null };
  let lastWindow = '', state = await mvp(), shotIndex = 0, keyIndex = 0, padIndex = 0, hidden = null;
  summary.keysPressed = [];
  summary.padEvents = [];
  while (Date.now() < deadline) {
    state = await mvp();
    if (state.error) break;
    if (state.stats && JSON.stringify(state.stats) !== lastWindow) {
      lastWindow = JSON.stringify(state.stats);
      const w = state.audio?.worklet;
      windows.push({ field: state.stats.status.fields, ...state.stats.window,
                     audio: w ? { fill: w.fill, underruns: w.underruns, skipped: w.skipped } : undefined });
    }
    const field = state.stats?.status.fields ?? 0;
    if (state.probe) {
      ++audioSamples.n;
      audioSamples.maxRms = Math.max(audioSamples.maxRms, state.probe.rms);
      audioSamples.maxPeak = Math.max(audioSamples.maxPeak, state.probe.peak);
      if (state.probe.rms > 1e-4) {
        ++audioSamples.nonsilent;
        audioSamples.firstNonsilentField ??= field;
      }
    }
    while (keyIndex < keys.length && field >= keys[keyIndex].field) {
      const { key } = keys[keyIndex++];
      await page.keyboard.down(key);
      await page.waitForTimeout(holdMs);
      await page.keyboard.up(key);
      summary.keysPressed.push({ key, field });
      console.log(`pressed ${key} at field ${field}`);
    }
    while (padIndex < pads.length && field >= pads[padIndex].field) {
      const ev = pads[padIndex++];
      const set = (on) => page.evaluate(([e, down]) => {
        const p = window.__fakePad;
        if (e.kind === 'button') p.buttons[e.index] = { pressed: down, touched: down, value: down ? 1 : 0 };
        else p.axes[e.index] = down ? e.value : 0;
        p.timestamp = performance.now();
      }, [ev, on]);
      await set(true);
      await page.waitForTimeout(ev.kind === 'button' ? holdMs : Math.max(300, holdMs));
      const during = await page.evaluate(() => window.mvp.pad);
      await set(false);
      summary.padEvents.push({ ...ev, at: field, pageSaw: during });
      console.log(`gamepad ${ev.kind} ${ev.index} at field ${field}: page pad ${JSON.stringify(during)}`);
    }
    if (hide && !hidden && field >= hide[0]) {
      const before = (await mvp()).stats?.status.fields ?? 0;
      await page.evaluate(setHidden, true);
      const t = Date.now();
      await page.waitForTimeout(hide[1]);
      const mid = await mvp();
      await page.evaluate(setHidden, false);
      hidden = { atField: before, ms: Date.now() - t, fieldsWhileHidden: (mid.stats?.status.fields ?? 0) - before,
                 paused: mid.paused, audio: mid.audio?.state };
      console.log(`hidden for ${hidden.ms} ms at field ${before}: ${hidden.fieldsWhileHidden} fields ran meanwhile`);
    }
    while (shotIndex < shots.length && field >= shots[shotIndex]) {
      const path = join(out, `${label}-r${run}-field-${String(field).padStart(5, '0')}.png`);
      await page.locator('#screen').screenshot({ path });
      console.log(`screenshot at field ${field}: ${path}`);
      ++shotIndex;
    }
    const wantStop = fields || frames;
    if (wantStop ? state.stopped
                 : (state.firstFrameMs !== undefined && shotIndex >= shots.length && keyIndex >= keys.length &&
                    padIndex >= pads.length && (!hide || hidden) && (!audio || audioSamples.nonsilent > 0))) break;
    await page.waitForTimeout(200);
  }
  if (state.discTrace) writeFileSync(join(out, `disc-trace-${label}-r${run}.txt`), state.discTrace);
  delete state.discTrace;
  if (state.stopped || state.firstFrameMs !== undefined) {
    const path = join(out, `${label}-r${run}-final.png`);
    await page.locator('#screen').screenshot({ path }).catch(() => undefined);
  }
  Object.assign(summary, {
    source: state.source, phases: state.phases, translate: state.translate, disc: state.disc, gfx: state.gfx,
    firstFrameMs: state.firstFrameMs, firstFrameField: state.firstFrameField, cache: state.cache,
    windows, final: state.stopped?.status ?? state.stats?.status ?? null, guestLine: state.stopped?.guestLine ?? null,
    error: state.error ?? null, consoleErrors: consoleErrors.slice(0, 20), hidden,
    audio: { page: state.audio, attachedAtField: state.audioAttachedAtField, samples: audioSamples },
  });
  const origin = new URL(base).origin;
  summary.foreignRequests = requests.filter((u) => !u.startsWith(origin) && !u.startsWith('blob:') && !u.startsWith('data:'));
  summary.requests = [...new Set(requests.map((u) => u.replace(origin, '').replace(/\?.*$/, '?...')))];
  if (serverDisc) summary.mockServer = await (await fetch(`${base}_stats`)).json();
  await page.close();
  const ok = state.firstFrameMs !== undefined || (!render && state.stopped);
  summary.ok = ok && !state.error && (!(fields || frames) || !!state.stopped);
  return summary;
}

const all = { browser: browserName, tag: tag || null, jsFlags: jsFlags || null, headed, fast, fields, frames,
              script: scriptFile || null, serverDisc, login, latency: latency || null, rate: rate || null, runs: [] };
let rc = 1;
let browser;
try {
  browser = await launchers[browserName]();
  all.version = browser.version();
  const context = await browser.newContext({ viewport: { width: 1100, height: 1100 } });
  for (let run = 1; run <= runs; ++run) {
    const s = await runOnce(context, run);
    all.runs.push(s);
    console.log(`run ${run}: first frame ${s.firstFrameMs?.toFixed(0)} ms, cache ${JSON.stringify(s.cache)}, ` +
                `guest line ${s.guestLine}`);
  }
  rc = all.runs.every((s) => s.ok) ? 0 : 1;
} catch (e) {
  all.exception = String(e?.stack ?? e);
} finally {
  await browser?.close();
  server.kill();
}
writeFileSync(join(out, `summary-${label}.json`), JSON.stringify(all, null, 2));
console.log(JSON.stringify(all, (k, v) => (k === 'windows' || k === 'requests' ? undefined : v), 2));
process.exit(rc);
