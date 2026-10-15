// Two-browser netplay check for E5 (needs the player's disc; never run in CI).
// Starts the netplay server (engine/server, built with `npm run build`) with a
// throwaway password in front of the built site, opens two isolated browser
// contexts (two players with their own cookies), logs both in, lets player 1
// create a game and player 2 open the invite link, gives both pages the disc
// through their file inputs, and runs both games in lockstep with the same
// mvp-input script (each page drives only its own port from it). Both stop at
// the poll of frame N and report their guest line (MEM1 SHA-1) and their
// state-hash windows; they must be identical, with zero desyncs.
//
//   node engine/web/tools/netplay_check.mjs [--browser chrome|msedge|chromium|firefox] [--browser2 NAME]
//        [--disc PATH] [--script FILE] [--frames N] [--delay D] [--fast] [--headed]
//        [--expect "guest: ..."] [--out DIR] [--tag NAME] [--timeout SECONDS] [--no-render]
//        [--steady-from FRAME]
//
//   --expect   a guest line both pages must also match (e.g. the native
//              `mvp-netplay solo` run of the same script, frames and delay)
//   --steady-from  measure input latency, frame rate, stalls and bandwidth from
//              this frame on (default N/2: past the boot and the intro movie)
//
// Writes netplay-BROWSER[-TAG].json to --out (default build/engine/web-check).
// Exit status: 0 when both pages stopped at frame N with identical guest lines
// and windows and no desync, 1 otherwise, 77 without a disc.

import { spawn } from 'node:child_process';
import { randomBytes } from 'node:crypto';
import { existsSync, mkdirSync, readFileSync, writeFileSync } from 'node:fs';
import { join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { chromium, firefox } from 'playwright';

const here = fileURLToPath(new URL('.', import.meta.url));
const repo = resolve(here, '..', '..', '..');
const argv = process.argv.slice(2);
const opt = (name, fallback) => {
  const i = argv.indexOf(name);
  return i >= 0 && i + 1 < argv.length ? argv[i + 1] : fallback;
};
const flag = (name) => argv.includes(name);

const browserName = opt('--browser', 'chrome');
const browserName2 = opt('--browser2', browserName);  // player 2's browser (mixed-browser games)
const disc = opt('--disc', process.env.MVP_DISC ?? '');
const out = resolve(opt('--out', join(repo, 'build', 'engine', 'web-check')));
const scriptFile = opt('--script', '');
const frames = Number(opt('--frames', '1200'));
const delay = Number(opt('--delay', '3'));
const fast = flag('--fast');
const headed = flag('--headed');
const render = !flag('--no-render');
const expect = opt('--expect', '');
const tag = opt('--tag', '');
const timeoutS = Number(opt('--timeout', '900'));
const site = resolve(opt('--site', join(repo, 'build', 'engine', 'emscripten', 'web', 'site')));
const serverMain = join(repo, 'engine', 'server', 'dist', 'src', 'main.js');
const label = `netplay-${browserName}${browserName2 !== browserName ? `-${browserName2}` : ''}${tag ? `-${tag}` : ''}`;

if (!disc || !existsSync(disc)) {
  console.error('netplay_check: no disc image (--disc or MVP_DISC)');
  process.exit(77);
}
if (!existsSync(serverMain)) {
  console.error('netplay_check: build the server first (npm ci && npm run build in engine/server)');
  process.exit(2);
}
mkdirSync(out, { recursive: true });
const script = scriptFile ? readFileSync(scriptFile, 'utf8') : '';

// The server: a throwaway password, port 0, no disc route (the pages use the file input).
const password = randomBytes(18).toString('base64url');
const server = spawn(process.execPath, [serverMain], {
  env: { ...process.env, MVP_PASSWORD: password, MVP_SITE: site, MVP_PORT: '0', MVP_HOST: '127.0.0.1', MVP_DISC_IMAGE: '' },
  stdio: ['ignore', 'pipe', 'inherit'],
});
const base = await new Promise((resolveUrl, reject) => {
  server.stdout.on('data', (d) => {
    const m = /listening on (http:\/\/\S+);/.exec(String(d));
    if (m) resolveUrl(m[1]);
  });
  server.on('exit', (code) => reject(new Error(`server exited ${code}`)));
});

const chromiumArgs = ['--enable-unsafe-webgpu', '--disable-features=WebRtcHideLocalIpsWithMdns'];
const launchers = {
  chrome: () => chromium.launch({ channel: 'chrome', headless: !headed, args: chromiumArgs }),
  msedge: () => chromium.launch({ channel: 'msedge', headless: !headed, args: chromiumArgs }),
  chromium: () => chromium.launch({ headless: !headed, args: chromiumArgs }),
  firefox: () => firefox.launch({
    headless: !headed,
    firefoxUserPrefs: { 'dom.webgpu.enabled': true, 'dom.webgpu.workers.enabled': true, 'gfx.webgpu.ignore-blocklist': true,
                        'media.peerconnection.ice.obfuscate_host_addresses': false },
  }),
};

const summary = { browser: browserName, browser2: browserName2, tag: tag || null, frames, delay, fast, render, script: scriptFile || null };
let rc = 1;
const browsers = [];
try {
  browsers.push(await launchers[browserName]());
  if (browserName2 !== browserName) browsers.push(await launchers[browserName2]());
  summary.version = browsers.map((b) => b.version());
  const pages = [];
  for (const who of ['p1', 'p2']) {
    const browser = who === 'p2' ? browsers[browsers.length - 1] : browsers[0];
    const ctx = await browser.newContext({ viewport: { width: 1000, height: 1000 } });
    const page = await ctx.newPage();
    const errors = [];
    page.on('console', (m) => {
      if (m.type() === 'error') errors.push(m.text());
    });
    page.on('pageerror', (e) => errors.push(String(e)));
    const requests = [];
    page.on('request', (r) => requests.push(r.url()));
    // Log in through the form, as a player would.
    await page.goto(`${base}/`);
    await page.fill('input[name=password]', password);
    await Promise.all([page.waitForURL(`${base}/`), page.click('button[type=submit]')]);
    pages.push({ who, page, errors, requests });
  }
  const q = new URLSearchParams();
  if (script) q.set('script', script);
  q.set('frames', String(frames));
  if (fast) q.set('fast', '1');
  if (!render) q.set('render', '0');

  const [a, b] = pages;
  await a.page.goto(`${base}/?online=create&delay=${delay}&${q}`);
  await a.page.waitForFunction(() => window.mvp?.net?.invite, null, { timeout: 15000 });
  const invite = await a.page.evaluate(() => window.mvp.net.invite);
  summary.invite = invite.replace(/room=[a-z0-9]+/, 'room=<id>');
  await b.page.goto(`${invite}&${q}`);
  await b.page.waitForFunction(() => window.mvp?.net?.player === 2, null, { timeout: 15000 });
  const t0 = Date.now();
  await Promise.all(pages.map((p) => p.page.setInputFiles('#disc', disc)));

  const read = (p) => p.page.evaluate(() => {
    const s = window.mvp;
    return { phases: s.phases, firstFrameMs: s.firstFrameMs, stats: s.stats, stopped: s.stopped, error: s.error,
             net: s.net && { ...s.net, windows: undefined, diagnostic: s.net.diagnostic } , windows: s.net?.windows };
  });
  const deadline = t0 + timeoutS * 1000;
  let states = [];
  const timeline = [];
  const samples = [[], []];  // per page: {t, status, transport} while running
  let lastT = 0;
  while (Date.now() < deadline) {
    states = await Promise.all(pages.map(read));
    const now = Date.now();
    states.forEach((st, k) => {
      if (st.net?.status?.state === 'running' && !st.stopped)
        samples[k].push({ t: now, status: st.net.status, transport: st.net.transport });
    });
    if (now - lastT >= 5000) {
      lastT = now;
      const row = { s: Math.round((now - t0) / 1000) };
      for (const [k, st] of states.entries()) {
        const n = st.net?.status;
        row[pages[k].who] = n ? { state: n.state, frame: n.frame, stalls: n.stalls, stallMs: n.stallMs, rtt: n.rttAvg }
                              : { fields: st.stats?.status.fields };
      }
      timeline.push(row);
      console.log(JSON.stringify(row));
    }
    const done = states.every((st) => st.stopped && st.windows !== undefined);
    const failed = states.some((st) => st.error || (st.net?.status && ['desynced', 'rejected', 'disconnected'].includes(st.net.status.state)
                                                    && !st.stopped));
    if (done || failed) break;
    await new Promise((r) => setTimeout(r, 500));
  }
  // Let the final reports arrive.
  await new Promise((r) => setTimeout(r, 1500));
  states = await Promise.all(pages.map(read));
  summary.wallSeconds = (Date.now() - t0) / 1000;
  summary.timeline = timeline;
  summary.pages = states.map((st, k) => ({
    who: pages[k].who,
    phases: st.phases,
    error: st.error ?? null,
    guestLine: st.stopped?.guestLine ?? null,
    why: st.stopped?.status.why ?? null,
    net: st.net ? { ...st.net, diagnostic: st.net.diagnostic ? st.net.diagnostic.slice(0, 4000) : undefined } : null,
    windowsCount: (st.windows ?? '').split('\n').filter(Boolean).length,
    consoleErrors: pages[k].errors.slice(0, 20),
    foreignRequests: pages[k].requests.filter((u) => !u.startsWith(base) && !u.startsWith('blob:') && !u.startsWith('data:')),
  }));
  // Steady state: from the first sample at or after frame steadyFrom to the last one.
  const steadyFrom = Number(opt('--steady-from', String(Math.floor(frames / 2))));
  summary.steady = samples.map((list, k) => {
    const first = list.find((x) => x.status.frame >= steadyFrom);
    const last = list[list.length - 1];
    if (!first || !last || last === first) return { who: pages[k].who, note: 'not enough samples' };
    const dt = (last.t - first.t) / 1000;
    const d = (f) => f(last) - f(first);
    const latN = d((x) => x.status.latencySamples);
    return {
      who: pages[k].who,
      fromFrame: first.status.frame,
      toFrame: last.status.frame,
      seconds: dt,
      framesPerSecond: d((x) => x.status.frame) / dt,
      inputLatencyMs: latN ? d((x) => x.status.latencySum) / latN : null,
      stallMsPerSecond: d((x) => x.status.stallMs) / dt,
      payloadBytesPerSecondOut: d((x) => x.status.bytesSent) / dt,
      payloadPacketsPerSecondOut: d((x) => x.status.packetsSent) / dt,
      transportBytesPerSecondOut: first.transport && last.transport ? (last.transport.bytesSent - first.transport.bytesSent) / dt : null,
      transportPacketsPerSecondOut: first.transport && last.transport ? (last.transport.packetsSent - first.transport.packetsSent) / dt : null,
      rttAvgMs: last.status.rttAvg,
    };
  });
  const [sa, sb] = states;
  const sameGuest = !!sa.stopped && sa.stopped.guestLine === sb.stopped?.guestLine;
  const sameWindows = !!sa.windows && sa.windows === sb.windows;
  const netA = sa.net?.status, netB = sb.net?.status;
  const noDesync = !!netA && !!netB && !netA.desync && !netB.desync;
  const stoppedAtN = [sa, sb].every((st) => st.stopped?.status.why === `ran ${frames} frames`);
  const matchesExpect = !expect || sa.stopped?.guestLine === expect;
  summary.checks = { sameGuest, sameWindows, noDesync, stoppedAtN, matchesExpect, windows: summary.pages[0].windowsCount };
  if (expect) summary.expect = expect;
  rc = sameGuest && sameWindows && noDesync && stoppedAtN && matchesExpect ? 0 : 1;
} catch (e) {
  summary.exception = String(e?.stack ?? e);
} finally {
  for (const b of browsers) await b.close();
  server.kill();
}
writeFileSync(join(out, `${label}.json`), JSON.stringify(summary, null, 2));
console.log(JSON.stringify({ checks: summary.checks, exception: summary.exception, steady: summary.steady,
                             pages: summary.pages?.map((p) => ({ who: p.who, guestLine: p.guestLine, why: p.why, error: p.error,
                                                                 net: p.net?.status, route: p.net?.route, transport: p.net?.transport })) },
                           null, 2));
console.log(rc === 0 ? 'PASS: both browsers stayed in lockstep' : 'FAIL');
process.exit(rc);
