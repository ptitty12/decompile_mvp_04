// Browser check for controllers (Q3): the Controls panel, hot-plug, port
// assignment, press-to-bind, the keyboard map, storage, and the lobby's
// controller line, driven by injected fake gamepads (fake_pads.mjs: Playwright
// cannot emulate a real one). Deterministic: every step waits for the page's
// own animation frames and asserts on what the page sent to the engine
// (window.mvp.pads) or shows.
//
//   node engine/web/tools/pad_check.mjs [--browser chrome|msedge|chromium|firefox]
//        [--out DIR] [--site DIR] [--headed] [--only NAME[,NAME]]
//        [--game --disc PATH [--frames N]]     the game part (needs the disc; local only)
//
// Without --game it needs no game data: the page is served without a disc and
// the engine never starts. Exit status 0 when every check passed.

import { spawn } from 'node:child_process';
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { chromium, firefox } from 'playwright';
import { GCADAPTER_ACTIONS, PADS, PROMPTS, installFakePads } from './fake_pads.mjs';

const here = fileURLToPath(new URL('.', import.meta.url));
const repo = resolve(here, '..', '..', '..');
const argv = process.argv.slice(2);
const opt = (name, fallback) => {
  const i = argv.indexOf(name);
  return i >= 0 && i + 1 < argv.length ? argv[i + 1] : fallback;
};
const flag = (name) => argv.includes(name);

const browserName = opt('--browser', 'chrome');
const out = resolve(opt('--out', join(repo, 'build', 'engine', 'pad-check')));
const site = resolve(opt('--site', join(repo, 'build', 'engine', 'emscripten', 'web', 'site')));
const only = opt('--only', '').split(',').filter(Boolean);
const headed = flag('--headed');
mkdirSync(out, { recursive: true });

const PAD = { LEFT: 0x1, RIGHT: 0x2, DOWN: 0x4, UP: 0x8, Z: 0x10, R: 0x20, L: 0x40, A: 0x100, B: 0x200, X: 0x400, Y: 0x800, START: 0x1000 };

// ---- the server (serve.mjs, no disc) ----
const server = spawn(process.execPath, [join(here, 'serve.mjs'), '--port', '0', '--root', site], { stdio: ['ignore', 'pipe', 'inherit'] });
const base = await new Promise((resolveUrl, reject) => {
  server.stdout.on('data', (d) => {
    const m = /serving (http:\/\/[^\s;]+)/.exec(String(d));
    if (m) resolveUrl(m[1].endsWith('/') ? m[1] : `${m[1]}/`);
  });
  server.on('exit', (code) => reject(new Error(`server exited ${code}`)));
});

const launchers = {
  chrome: () => chromium.launch({ channel: 'chrome', headless: !headed }),
  msedge: () => chromium.launch({ channel: 'msedge', headless: !headed }),
  chromium: () => chromium.launch({ headless: !headed }),
  firefox: () => firefox.launch({ headless: !headed }),
};
const browser = await launchers[browserName]();

// ---- helpers ----
const results = [];
function assert(cond, message) {
  if (!cond) throw new Error(message);
}
function eq(actual, expected, message) {
  if (JSON.stringify(actual) !== JSON.stringify(expected)) {
    throw new Error(`${message}: expected ${JSON.stringify(expected)}, got ${JSON.stringify(actual)}`);
  }
}

// Waits for n of the page's animation frames (the page samples the pads in each).
const frames = (page, n = 3) => page.evaluate((count) => new Promise((resolveFrames) => {
  let k = 0;
  const step = () => (++k >= count ? resolveFrames() : requestAnimationFrame(step));
  requestAnimationFrame(step);
}), n);
const port = (page, p = 0) => page.evaluate((i) => window.mvp.pads?.[i] ?? null, p);
const pads = (page) => page.evaluate(() => window.mvp.controls());
const text = (page, sel) => page.$eval(sel, (e) => e.textContent);
const chip = (page) => text(page, '#pad-chip');
const pad = (page, slot, buttons = {}, axes = {}) => page.evaluate(([s, b, a]) => window.__pads.set(s, b, a), [slot, buttons, axes]);
const connect = (page, slot, spec) => page.evaluate(([s, sp]) => window.__pads.connect(s, sp), [slot, spec]);
const disconnect = (page, slot) => page.evaluate((s) => window.__pads.disconnect(s), slot);
const rest = (page, slot) => page.evaluate((s) => window.__pads.rest(s), slot);
const readout = (page) => page.$eval('#ctl-readout', (e) => ({ ...e.dataset }));

async function openPage(context, query = '', openPanel = true) {
  const page = await context.newPage();
  const errors = [];
  // (Firefox reports a request cut off by a reload as an error of the old page.)
  page.on('pageerror', (e) => { if (!/Navigated away/.test(String(e))) errors.push(String(e)); });
  page.on('console', (m) => {
    if (m.type() === 'error' && !/WebGPU|Failed to load resource|Navigated away/.test(m.text())) errors.push(m.text());
  });
  await page.addInitScript(installFakePads);
  // No disc and no lobby server unless a check sets one up: the engine never starts.
  await page.route('**/config.json', (r) => r.fulfill({ status: 404, body: 'no' }));
  await page.goto(`${base}${query}`);
  await page.waitForSelector('#controls .ctl-status', { state: 'attached' });
  if (openPanel) await page.$eval('#controls-details', (d) => { d.open = true; });
  await frames(page, 2);
  page.__errors = errors;
  return page;
}

// Answers the guided setup like a person pressing each control of the made-up GameCube adapter.
async function runWizard(page, slot) {
  const done = new Set();
  for (let guard = 0; guard < 400; ++guard) {
    if (await page.$eval('#ctl-prompt', (e) => e.hidden)) return [...done];
    const prompt = await text(page, '#ctl-prompt-text');
    const control = PROMPTS[prompt];
    if (control && !done.has(control)) {
      const a = GCADAPTER_ACTIONS[control];
      await pad(page, slot, a.buttons, a.axes);
      await frames(page, 4);
      await rest(page, slot);
      done.add(control);
    }
    await frames(page, 1);
  }
  throw new Error(`the guided setup did not finish (answered: ${[...done].join(' ')})`);
}

const checks = [];
const check = (name, fn) => checks.push({ name, fn });

// ---- the checks ----

check('keyboard only: the default keys reach player 1, player 2 is empty', async (context) => {
  const page = await openPage(context);
  eq(await chip(page), 'No controller (keyboard)', 'chip');
  assert((await text(page, '#ctl-status')).includes('No controller found'), 'status says no controller');
  await page.keyboard.down('Enter');
  await frames(page);
  eq((await port(page)).buttons, PAD.START, 'Enter is START');
  await page.keyboard.up('Enter');
  await page.keyboard.down('KeyL');
  await frames(page);
  eq((await port(page)).stickX, 100, 'L is the stick right');
  await page.keyboard.up('KeyL');
  await frames(page);
  eq((await port(page)).stickX, 0, 'released');
  eq((await port(page, 1)).connected, false, 'player 2 not plugged in');
  await page.close();
});

check('standard pad: shown after its first press, plays player 1, live test follows', async (context) => {
  const page = await openPage(context);
  await connect(page, 0, PADS.xbox);                // Chrome keeps it hidden until used
  await frames(page);
  eq(await chip(page), 'No controller (keyboard)', 'hidden pad not shown');
  await pad(page, 0, { 0: 1 });                      // A / Cross
  await frames(page, 3);
  eq(await chip(page), 'Controller: Xbox Wireless Controller', 'chip names it');
  eq((await port(page)).buttons, PAD.A, 'A reaches the game');
  const info = await pads(page);
  eq([info.devices.length, info.devices[0].port, info.devices[0].standard, info.devices[0].profile], [1, 0, true, 'standard'], 'device');
  eq((await readout(page)).buttons, 'A', 'live test shows A');
  assert((await text(page, '#ctl-status')).includes('player 1'), 'status says player 1');
  // Sticks and triggers.
  await pad(page, 0, { 0: 0, 7: 1, 6: 0.5 }, { 0: 1, 1: -1 });
  await frames(page, 3);
  const p = await port(page);
  eq([p.stickX, p.stickY, p.trigL, p.trigR, p.buttons], [71, 71, 128, 255, PAD.R], 'stick up-right, triggers');
  eq((await readout(page)).triggers, '128,255', 'live triggers');
  await rest(page, 0);
  await frames(page, 3);
  eq((await port(page)).buttons, 0, 'at rest');
  await page.close();
});

check('hot-plug: unplug mid-game releases everything, a new slot is claimed again', async (context) => {
  const page = await openPage(context);
  await connect(page, 0, PADS.xbox);
  await pad(page, 0, { 9: 1 }, { 0: -1 });           // Start held, stick left
  await frames(page, 3);
  eq([(await port(page)).buttons, (await port(page)).stickX], [PAD.START, -100], 'held');
  await disconnect(page, 0);
  await frames(page, 3);
  eq(await chip(page), 'No controller (keyboard)', 'chip after unplug');
  eq(await port(page), { connected: true, buttons: 0, stickX: 0, stickY: 0, cX: 0, cY: 0, trigL: 0, trigR: 0 }, 'neutral, port still plugged in');
  assert((await text(page, '#ctl-status')).includes('unplugged'), 'status says unplugged');
  await connect(page, 2, PADS.xbox);
  await pad(page, 2, { 1: 1 });
  await frames(page, 3);
  eq([(await port(page)).buttons, (await pads(page)).devices[0].index], [PAD.B, 2], 'plays from slot 2');
  await page.close();
});

check('two pads: the second one used is player 2, and goes when unplugged', async (context) => {
  const page = await openPage(context);
  await connect(page, 0, PADS.xbox);
  await pad(page, 0, { 0: 1 });
  await frames(page, 3);
  await connect(page, 1, PADS.ds4);
  await frames(page, 2);
  eq((await port(page, 1)).connected, false, 'idle pad takes no port');
  await pad(page, 1, { 1: 1 });
  await frames(page, 3);
  eq([(await port(page, 1)).connected, (await port(page, 1)).buttons, (await port(page)).buttons], [true, PAD.B, PAD.A], 'two players');
  eq(await chip(page), 'Controller: Xbox Wireless Controller +1', 'chip counts both');
  assert((await text(page, '#ctl-status')).includes('player 2'), 'status names player 2');
  await disconnect(page, 1);
  await frames(page, 3);
  eq((await port(page, 1)).connected, false, 'player 2 unplugged');
  await page.close();
});

check('assignment: choose the pad for each player, the keyboard for player 2, persisted', async (context) => {
  const page = await openPage(context);
  await connect(page, 0, PADS.xbox);
  await connect(page, 1, PADS.ds4);
  await pad(page, 0, { 0: 1 });
  await frames(page, 2);
  await pad(page, 1, { 1: 1 });
  await frames(page, 3);
  eq([(await port(page)).buttons, (await port(page, 1)).buttons], [PAD.A, PAD.B], 'xbox P1, ds4 P2');
  await page.selectOption('#ctl-port-0', 'dev:054c:09cc:0');         // the PlayStation pad plays player 1
  await frames(page, 3);
  eq([(await port(page)).buttons, (await port(page, 1)).buttons], [PAD.B, PAD.A], 'swapped');
  await page.selectOption('#ctl-port-0', 'none');                    // nobody on player 1
  await page.selectOption('#ctl-kbport', '1');                       // the keyboard plays player 2
  await frames(page, 3);
  await page.keyboard.down('Enter');
  await frames(page, 3);
  const [p1, p2] = [await port(page), await port(page, 1)];
  eq([p1.buttons, p2.buttons & PAD.START], [0, PAD.START], 'keyboard is on player 2');
  await page.keyboard.up('Enter');
  // Reload: the choices are still there (the pads are plugged in again by the page's harness).
  await page.reload();
  await page.waitForSelector('#controls .ctl-status', { state: 'attached' });
  eq(await page.$eval('#ctl-port-0', (e) => e.value), 'none', 'player 1 still none');
  eq(await page.$eval('#ctl-kbport', (e) => e.value), '1', 'keyboard still on player 2');
  await page.close();
});

check('non-standard pad: shown as needing setup, the guided setup teaches it, stored for next time', async (context) => {
  const page = await openPage(context, '', false);
  await connect(page, 0, PADS.gcadapter);            // listed at once (Firefox style), idle
  await frames(page, 3);
  eq((await pads(page)).devices[0].active, false, 'idle until used');
  eq((await port(page, 1)).connected, false, 'idle pad takes no port');
  assert(!(await page.$eval('#ctl-notice', (e) => e.hidden)), 'the setup notice is shown');
  await pad(page, 0, { 1: 1 });                      // the guess has button 1 as B
  await frames(page, 3);
  eq((await port(page)).buttons, PAD.B, 'the generic guess plays the menus (button 1 = B)');
  assert(await page.$eval('#controls-details', (e) => e.open), 'the panel opened for a pad it does not know');
  await rest(page, 0);
  await page.click('#ctl-setup-all');
  eq((await port(page)).buttons, 0, 'nothing reaches the game while teaching');
  const answered = await runWizard(page, 0);
  eq(answered.length, 16, `all sixteen controls asked (answered: ${answered.join(' ')})`);
  const play = async (buttons, axes) => {
    await rest(page, 0);
    await pad(page, 0, buttons, axes);
    await frames(page, 3);
    return port(page);
  };
  eq((await play({ 1: 1 })).buttons, PAD.A, 'A');
  eq((await play({ 2: 1 })).buttons, PAD.B, 'B');
  eq((await play({ 0: 1 })).buttons, PAD.X, 'X');
  eq((await play({ 3: 1 })).buttons, PAD.Y, 'Y');
  eq((await play({ 7: 1 })).buttons, PAD.Z, 'Z');
  eq((await play({ 9: 1 })).buttons, PAD.START, 'START');
  eq((await play({ 12: 1 })).buttons, PAD.UP, 'D-pad up');
  eq((await play({ 15: 1 })).buttons, PAD.LEFT, 'D-pad left');
  const l = await play({}, { 4: 1 });
  eq([l.trigL, l.buttons], [255, PAD.L], 'L trigger on an axis resting at -1');
  const half = await play({}, { 5: 0 });
  eq([half.trigR, half.buttons], [128, 0], 'R half way, no click');
  const s = await play({}, { 0: 1, 1: -1 });
  eq([s.stickX, s.stickY], [71, 71], 'main stick');
  const c = await play({}, { 3: -1, 2: -1 });
  eq([c.cX, c.cY], [-71, 71], 'C-stick');
  const info = await pads(page);
  eq([info.devices[0].custom, info.devices[0].known], [true, false], 'marked as set up');
  assert(await page.$eval('#ctl-notice', (e) => e.hidden), 'the notice is gone');
  // Next visit: the stored mapping, no setup.
  await page.reload();
  await page.waitForSelector('#controls .ctl-status', { state: 'attached' });
  await connect(page, 3, PADS.gcadapter);
  await frames(page, 2);
  await pad(page, 3, { 1: 1 });
  await frames(page, 3);
  eq((await port(page)).buttons, PAD.A, 'remembered after a reload (and in another slot)');
  eq(page.__errors, [], 'no page errors');
  await page.close();
});

check('one control: Set binds the next press, Esc cancels, the old button stops doing it', async (context) => {
  const page = await openPage(context);
  await connect(page, 0, PADS.xbox);
  await pad(page, 0, { 0: 1 });
  await frames(page, 3);
  await rest(page, 0);
  await page.click('[data-set="button:A"]');
  assert(!(await page.$eval('#ctl-prompt', (e) => e.hidden)), 'prompt shown');
  await frames(page, 2);
  eq(await text(page, '#ctl-prompt-text'), 'Press the A button (the big one)', 'asks for A');
  await pad(page, 0, { 7: 1 });
  await frames(page, 3);
  eq((await port(page)).buttons, 0, 'the press that sets a binding never reaches the game');
  await rest(page, 0);
  await frames(page, 6);
  assert(await page.$eval('#ctl-prompt', (e) => e.hidden), 'prompt gone');
  await pad(page, 0, { 7: 1 });
  await frames(page, 3);
  eq((await port(page)).buttons, PAD.A | 0, 'RT button 7 is A now');
  await rest(page, 0);
  await pad(page, 0, { 0: 1 });
  await frames(page, 3);
  eq((await port(page)).buttons, 0, 'the old button no longer does A');
  await rest(page, 0);
  // Esc cancels.
  await page.click('[data-set="button:B"]');
  await frames(page, 2);
  await page.keyboard.press('Escape');
  await frames(page, 2);
  assert(await page.$eval('#ctl-prompt', (e) => e.hidden), 'Esc closed the prompt');
  await pad(page, 0, { 1: 1 });
  await frames(page, 3);
  eq((await port(page)).buttons, PAD.B, 'B unchanged');
  await rest(page, 0);
  // Reset to defaults.
  await page.click('#ctl-reset');
  await frames(page, 3);
  await pad(page, 0, { 0: 1 });
  await frames(page, 3);
  eq((await port(page)).buttons, PAD.A, 'defaults back');
  await page.close();
});

check('keyboard: keys can be changed, taken keys swap, the page keys are refused, kept per browser', async (context) => {
  const page = await openPage(context);
  eq(await page.$eval('#ctl-target', (e) => e.value), 'keyboard', 'the keyboard is the target without a pad');
  await page.click('[data-set-key="A"]');
  await page.keyboard.press('KeyF');                 // the page's fullscreen key: refused, still waiting
  await frames(page, 2);
  assert((await text(page, '#ctl-prompt-text')).includes("page's own key"), 'F refused');
  await page.keyboard.press('KeyN');
  await frames(page, 2);
  assert(await page.$eval('#ctl-prompt', (e) => e.hidden), 'bound');
  await page.keyboard.down('KeyN');
  await frames(page, 3);
  eq((await port(page)).buttons, PAD.A, 'N is A');
  await page.keyboard.up('KeyN');
  await page.keyboard.down('KeyX');
  await frames(page, 3);
  eq((await port(page)).buttons, 0, 'X is not A any more');
  await page.keyboard.up('KeyX');
  // Taking B's key swaps: B gets A's old key (N).
  await page.click('[data-set-key="A"]');
  await page.keyboard.press('KeyZ');
  await frames(page, 2);
  await page.keyboard.down('KeyN');
  await frames(page, 3);
  eq((await port(page)).buttons, PAD.B, 'B took the key A gave up');
  await page.keyboard.up('KeyN');
  await page.keyboard.down('Space');                 // Space on a focused button must not click it again
  await page.keyboard.up('Space');
  await frames(page, 2);
  assert(await page.$eval('#ctl-prompt', (e) => e.hidden), 'no second prompt from the Space key-up');
  await page.reload();
  await page.waitForSelector('#controls .ctl-status', { state: 'attached' });
  await page.$eval('#controls-details', (d) => { d.open = true; });
  await page.keyboard.down('KeyZ');
  await frames(page, 3);
  eq((await port(page)).buttons, PAD.A, 'kept after a reload (Z is A now)');
  await page.keyboard.up('KeyZ');
  await page.click('#ctl-reset');
  await page.keyboard.down('KeyX');
  await frames(page, 3);
  eq((await port(page)).buttons, PAD.A, 'reset to the defaults');
  await page.keyboard.up('KeyX');
  await page.close();
});

check('sticks: dead zone slider and the octagon gate change what the game gets', async (context) => {
  const page = await openPage(context);
  await connect(page, 0, PADS.xbox);
  await pad(page, 0, { 0: 1 });
  await frames(page, 3);
  await rest(page, 0);
  const a = Math.PI / 8;
  const push = async (x, y) => {
    await pad(page, 0, {}, { 0: x, 1: -y });
    await frames(page, 3);
    const p = await port(page);
    return Math.hypot(p.stickX, p.stickY);
  };
  const octagon = await push(Math.cos(a), Math.sin(a));
  assert(Math.abs(octagon - 92.4) < 1.5, `octagon rim at 22.5 degrees is ~92 (got ${octagon})`);
  await page.uncheck('#ctl-octagon');
  await frames(page, 3);
  const circle = await push(Math.cos(a), Math.sin(a));
  assert(Math.abs(circle - 100) < 1.5, `circle rim is 100 (got ${circle})`);
  await page.check('#ctl-octagon');
  await frames(page, 2);
  const small = await push(0.25, 0);
  assert(small > 0, 'a push of 0.25 moves the stick at the default dead zone');
  await page.$eval('#ctl-deadzone', (e) => { e.value = '0.3'; e.dispatchEvent(new Event('input', { bubbles: true })); });
  await frames(page, 3);
  eq(await push(0.25, 0), 0, 'inside the 30 % dead zone');
  eq(await push(1, 0), 100, 'full range outside it');
  await page.close();
});

check('vibration: the test button vibrates the selected pad when it has an actuator', async (context) => {
  const page = await openPage(context);
  await connect(page, 0, PADS.xbox);
  await pad(page, 0, { 0: 1 });
  await frames(page, 3);
  await page.click('#ctl-rumble-test');
  await frames(page, 2);
  const calls = await page.evaluate(() => window.__pads.rumbles);
  eq([calls.length, calls[0]?.type], [1, 'dual-rumble'], 'one effect played');
  await page.close();
});

check('lobby: the controller line says keyboard / connected / ready, and online only the local player plays', async (context) => {
  const page = await context.newPage();
  const errors = [];
  page.on('pageerror', (e) => errors.push(String(e)));
  await page.addInitScript(installFakePads);
  // A lobby server that answers {} (no disc) and a WebSocket that puts this page in a room as player 2.
  await page.route('**/config.json', (r) => r.fulfill({ status: 200, contentType: 'application/json', body: '{}' }));
  await page.routeWebSocket(/\/ws$/, (ws) => {
    ws.send(JSON.stringify({ t: 'welcome', v: 1, iceServers: [] }));
    ws.onMessage((raw) => {
      const m = JSON.parse(String(raw));
      if (m.t === 'join') ws.send(JSON.stringify({ t: 'room', room: m.room, player: 2, invite: `${base}?room=${m.room}`, delay: 3, peer: false }));
    });
  });
  await page.goto(base);
  await page.waitForSelector('#online-pad', { state: 'attached' });
  await page.$eval('#controls-details', (d) => { d.open = true; });
  await frames(page, 2);
  eq(await page.$eval('#online-pad', (e) => e.dataset.state), 'keyboard', 'keyboard only');
  assert((await text(page, '#online-pad')).includes('keyboard only'), 'text says so');
  await connect(page, 0, PADS.xbox);
  await pad(page, 0, { 0: 1 });
  await frames(page, 3);
  eq(await page.$eval('#online-pad', (e) => e.dataset.state), 'ready', 'controller ready');
  assert((await text(page, '#online-pad')).includes('Xbox Wireless Controller is ready'), 'text names the pad');
  // Joining a room as player 2: only this page's controller plays, as the one local player.
  await page.goto(`${base}?room=abc`);
  await page.waitForSelector('#online-pad', { state: 'attached' });
  await page.$eval('#controls-details', (d) => { d.open = true; });
  await connect(page, 0, PADS.xbox);
  await pad(page, 0, { 0: 1 });
  await frames(page, 4);
  await page.waitForFunction(() => window.mvp.net?.player === 2);
  await frames(page, 3);
  assert((await text(page, '#online-pad')).includes('plays as player 2'), 'lobby line names the player');
  assert((await text(page, '[for="ctl-port-0"]')).includes('player 2'), 'panel row is "You (player 2)"');
  assert(await page.$eval('#ctl-port-1', (e) => e.closest('.ctl-row').hidden), 'the second player row is hidden');
  eq([(await port(page)).buttons, (await port(page, 1)).connected], [PAD.A, false], 'port 0 plays, port 1 empty');
  eq(errors, [], 'no page errors');
  await page.close();
});

// ---- run ----
let failed = 0;
for (const { name, fn } of checks) {
  if (only.length && !only.some((o) => name.includes(o))) continue;
  const t0 = Date.now();
  // Each check gets a clean browser profile: no stored settings from the one before.
  const context = await browser.newContext({ viewport: { width: 1100, height: 1400 } });
  try {
    await fn(context);
    results.push({ name, ok: true, ms: Date.now() - t0 });
    console.log(`ok     ${name} (${Date.now() - t0} ms)`);
  } catch (e) {
    failed++;
    results.push({ name, ok: false, ms: Date.now() - t0, error: String(e.message ?? e) });
    console.log(`FAILED ${name}: ${flag('--verbose') ? String(e.stack ?? e) : String(e.message ?? e).split(String.fromCharCode(10))[0]}`);
    const page = context.pages()[0];
    if (page) await page.screenshot({ path: join(out, `fail-${browserName}-${results.length}.png`), fullPage: true }).catch(() => {});
  }
  await context.close();
}
await browser.close();
server.kill();
writeFileSync(join(out, `summary-${browserName}.json`), JSON.stringify({ browser: browserName, results }, null, 2));
console.log(`${results.length - failed} of ${results.length} checks passed`);
process.exit(failed ? 1 : 0);
