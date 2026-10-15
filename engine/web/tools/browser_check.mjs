// Local browser check for E2 (needs the player's disc; never run in CI): serves
// the site, opens it in a real browser with Playwright, picks the disc image
// through the page's file input, and records the startup phases, the cold
// start (pick -> first frame), frame times, canvas screenshots and the
// determinism line.
//
//   node engine/web/tools/browser_check.mjs --browser chrome|msedge|chromium|firefox|webkit
//        [--disc PATH] [--out DIR] [--script FILE] [--fields N] [--frames N] [--fast]
//        [--shots F1,F2,...] [--keys F1:KEY,F2:KEY,...] [--headed] [--timeout SECONDS] [--no-render]
//        [--js-flags FLAGS] [--tag NAME]
//
//   --disc     the image (default: $MVP_DISC). It goes to the page's file input
//              locally; nothing is uploaded anywhere.
//   --out      where screenshots and the summary go (default build/engine/web-check);
//              keep it under build/: screenshots are game-derived, never committed
//   --script   an mvp-input script file (runtime/input.h) for the run
//   --fields / --frames   stop there and print the guest line (MEM1 SHA-1)
//   --fast     unpaced (as fast as possible); default paced to 59.94 fields/s
//   --shots    VI fields at which to screenshot the canvas (approximately: the
//              page reports progress twice a second)
//   --keys     live keyboard input: press KEY (a KeyboardEvent key name, e.g.
//              Enter, x, ArrowDown) for 150 ms once the run reaches field F
//   --js-flags V8 flags for Chrome/Edge/Chromium (experiments, e.g. --no-wasm-tier-up)
//   --tag      added to the output file names (summary-BROWSER-TAG.json, ...)
//
// Exit status: 0 when the run reached its first frame (and its stop, if any),
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
const label = tag ? `${browserName}-${tag}` : browserName;
const chromiumArgs = ['--enable-unsafe-webgpu', ...(jsFlags ? [`--js-flags=${jsFlags}`] : [])];
const shots = opt('--shots', '').split(',').filter(Boolean).map(Number).sort((a, b) => a - b);
const keys = opt('--keys', '').split(',').filter(Boolean).map((k) => {
  const [f, key] = k.split(':');
  return { field: Number(f), key };
}).sort((a, b) => a.field - b.field);

if (!disc || !existsSync(disc)) {
  console.error('browser_check: no disc image (--disc or MVP_DISC)');
  process.exit(77);
}
mkdirSync(out, { recursive: true });

// The server, on a free port.
const server = spawn(process.execPath, [join(here, 'serve.mjs'), '--port', '0'], { stdio: ['ignore', 'pipe', 'inherit'] });
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
    firefoxUserPrefs: { 'dom.webgpu.enabled': true, 'dom.webgpu.workers.enabled': true, 'gfx.webgpu.ignore-blocklist': true },
  }),
  webkit: () => webkit.launch({ headless: !headed }),
};
if (!launchers[browserName]) {
  console.error(`browser_check: unknown browser ${browserName}`);
  process.exit(2);
}

const summary = { browser: browserName, tag: tag || null, jsFlags: jsFlags || null, headed, fast, fields, frames,
                  script: scriptFile || null };
let rc = 1;
let browser;
try {
  browser = await launchers[browserName]();
  summary.version = browser.version();
  const page = await browser.newPage({ viewport: { width: 1100, height: 1100 } });
  const consoleErrors = [];
  page.on('console', (m) => {
    if (m.type() === 'error') consoleErrors.push(m.text());
  });
  page.on('pageerror', (e) => consoleErrors.push(String(e)));
  // Only the local server's own files: the disc goes in through the file input.
  const requests = [];
  page.on('request', (r) => requests.push(r.url()));

  const q = new URLSearchParams();
  if (scriptFile) q.set('script', readFileSync(scriptFile, 'utf8'));
  if (fields) q.set('fields', String(fields));
  if (frames) q.set('frames', String(frames));
  if (fast) q.set('fast', '1');
  if (!render) q.set('render', '0');
  await page.goto(`${base}?${q}`);
  summary.webgpu = await page.evaluate(() => 'gpu' in navigator);
  // Whether the page itself gets an adapter (the engine asks from its Worker).
  summary.pageAdapter = await page.evaluate(async () => {
    try {
      const a = await navigator.gpu?.requestAdapter();
      return a ? `${a.info?.vendor ?? ''} ${a.info?.architecture ?? ''}`.trim() || 'yes' : null;
    } catch (e) {
      return `error: ${e}`;
    }
  });
  const t0 = Date.now();
  await page.setInputFiles('#disc', disc);

  const deadline = t0 + timeoutS * 1000;
  const mvp = () => page.evaluate(() => {
    const s = window.mvp;
    return { phases: s.phases, translate: s.translate, disc: s.disc, gfx: s.gfx, firstFrameMs: s.firstFrameMs,
             firstFrameField: s.firstFrameField, stats: s.stats, stopped: s.stopped, error: s.error };
  });
  const windows = [];
  let lastWindow = '', state = await mvp(), shotIndex = 0, keyIndex = 0;
  summary.keysPressed = [];
  while (Date.now() < deadline) {
    state = await mvp();
    if (state.error) break;
    if (state.stats && JSON.stringify(state.stats) !== lastWindow) {
      lastWindow = JSON.stringify(state.stats);
      windows.push({ field: state.stats.status.fields, ...state.stats.window });
    }
    const field = state.stats?.status.fields ?? 0;
    while (keyIndex < keys.length && field >= keys[keyIndex].field) {
      const { key } = keys[keyIndex++];
      await page.keyboard.down(key);
      await page.waitForTimeout(150);
      await page.keyboard.up(key);
      summary.keysPressed.push({ key, field });
      console.log(`pressed ${key} at field ${field}`);
    }
    while (shotIndex < shots.length && field >= shots[shotIndex]) {
      const path = join(out, `${label}-field-${String(field).padStart(5, '0')}.png`);
      await page.locator('#screen').screenshot({ path });
      console.log(`screenshot at field ${field}: ${path}`);
      ++shotIndex;
    }
    const wantStop = fields || frames;
    if (wantStop ? state.stopped
                 : (state.firstFrameMs !== undefined && shotIndex >= shots.length && keyIndex >= keys.length)) break;
    await page.waitForTimeout(200);
  }
  if (state.stopped || state.firstFrameMs !== undefined) {
    const path = join(out, `${label}-final.png`);
    await page.locator('#screen').screenshot({ path });
  }
  summary.phases = state.phases;
  summary.translate = state.translate;
  summary.disc = state.disc;
  summary.gfx = state.gfx;
  summary.firstFrameMs = state.firstFrameMs;
  summary.firstFrameField = state.firstFrameField;
  summary.windows = windows;
  summary.final = state.stopped?.status ?? state.stats?.status ?? null;
  summary.guestLine = state.stopped?.guestLine ?? null;
  summary.error = state.error ?? null;
  summary.consoleErrors = consoleErrors.slice(0, 20);
  const origin = new URL(base).origin;
  summary.foreignRequests = requests.filter((u) => !u.startsWith(origin) && !u.startsWith('blob:') && !u.startsWith('data:'));
  summary.requests = [...new Set(requests.map((u) => u.replace(origin, '')))];
  const ok = state.firstFrameMs !== undefined || (!render && state.stopped);
  rc = ok && !state.error && (!(fields || frames) || state.stopped) ? 0 : 1;
} catch (e) {
  summary.exception = String(e?.stack ?? e);
} finally {
  await browser?.close();
  server.kill();
}
writeFileSync(join(out, `summary-${label}.json`), JSON.stringify(summary, null, 2));
console.log(JSON.stringify(summary, null, 2));
process.exit(rc);
