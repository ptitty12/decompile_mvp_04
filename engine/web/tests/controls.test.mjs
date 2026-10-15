// The Controls layers (Q3), data-free: D-pad hats and the octagonal gate (gamepad.ts),
// controller identification and profiles, the keyboard map, the stored settings,
// the pad manager (hot-plug, ports, auto-claim), and the press-to-bind state machine.
import assert from 'node:assert/strict';
import { test } from 'node:test';
import { load } from './site.mjs';

const g = await load('gamepad.js');
const prof = await load('gamepad-profiles.js');
const keys = await load('controls-keys.js');
const store = await load('controls-store.js');
const mgr = await load('pad-manager.js');
const reb = await load('controls-rebind.js');
const { PAD } = g;

const XBOX_CHROME = 'Xbox Wireless Controller (STANDARD GAMEPAD Vendor: 045e Product: 0b13)';
const DS4_CHROME = 'Wireless Controller (STANDARD GAMEPAD Vendor: 054c Product: 09cc)';
const DS4_FIREFOX = '054c-09cc-Wireless Controller';
const PRO_CHROME = 'Pro Controller (STANDARD GAMEPAD Vendor: 057e Product: 2009)';
const MAYFLASH = 'MAYFLASH GameCube Controller Adapter (Vendor: 0079 Product: 1843)';
const XPAD_FIREFOX = '045e-028e-Microsoft X-Box 360 pad';

// A gamepad like the browser's, with helpers.
function pad({ index = 0, id = XBOX_CHROME, mapping = 'standard', buttons = 17, axes = 4, axisRest = {} } = {}) {
  const p = {
    index, id, mapping, connected: true, timestamp: 0,
    buttons: Array.from({ length: buttons }, () => ({ pressed: false, touched: false, value: 0 })),
    axes: Array.from({ length: axes }, (_, i) => axisRest[i] ?? 0),
  };
  p.press = (i, v = 1) => { p.buttons[i] = { pressed: v > 0.5, touched: v > 0, value: v }; return p; };
  p.release = (i) => { p.buttons[i] = { pressed: false, touched: false, value: 0 }; return p; };
  p.axis = (i, v) => { p.axes[i] = v; return p; };
  return p;
}

const emptyKeys = new Set();

// ---- hats and the octagon (gamepad.ts) ----

test('hat axis: eight directions in steps of 2/7, neutral outside the range', () => {
  const d = (v) => g.hatDirections(v).join('+');
  assert.equal(d(-1), 'up');
  assert.equal(d(-0.7142857), 'up+right');
  assert.equal(d(-0.4285714), 'right');
  assert.equal(d(-0.1428571), 'down+right');
  assert.equal(d(0.1428571), 'down');
  assert.equal(d(0.4285714), 'down+left');
  assert.equal(d(0.7142857), 'left');
  assert.equal(d(1), 'up+left');
  for (const rest of [1.2857143, 3.2857143, NaN, 5, -3]) assert.equal(d(rest), '');
  const m = g.defaultMapping();
  m.buttons.UP = [{ type: 'hat', index: 9, dir: 'up' }];
  m.buttons.RIGHT = [{ type: 'hat', index: 9, dir: 'right' }];
  const p = { buttons: [], axes: [0, 0, 0, 0, 0, 0, 0, 0, 0, -0.7142857] };
  assert.equal(g.mapGamepad(p, m).buttons, PAD.UP | PAD.RIGHT);  // a diagonal presses both
  p.axes[9] = 1.2857143;
  assert.equal(g.mapGamepad(p, m).buttons, 0);
});

test('rebinding a hat: an axis resting outside -1..1 that reports a direction', () => {
  const rest = g.snapshot({ buttons: [], axes: [0, 0, 1.2857143] });
  assert.equal(g.detectSource(rest, rest), null);
  const down = g.snapshot({ buttons: [], axes: [0, 0, 0.1428571] });
  assert.deepEqual(g.detectSource(rest, down), { type: 'hat', index: 2, dir: 'down' });
  assert.equal(g.describeSource({ type: 'hat', index: 2, dir: 'down' }), 'D-pad down (axis 2)');
  // Storage keeps hat sources and rejects a bad direction.
  const m = g.defaultMapping();
  m.buttons.UP = [{ type: 'hat', index: 9, dir: 'up' }];
  assert.deepEqual(g.parseMapping(JSON.stringify(m)).buttons.UP, [{ type: 'hat', index: 9, dir: 'up' }]);
  m.buttons.UP = [{ type: 'hat', index: 9, dir: 'sideways' }];
  assert.deepEqual(g.parseMapping(JSON.stringify(m)).buttons.UP, g.defaultMapping().buttons.UP);
});

test('octagonal gate: notches at the full distance, 92.4 % between them', () => {
  const near = (a, b, eps = 1e-9) => assert.ok(Math.abs(a - b) < eps, `${a} vs ${b}`);
  near(g.octagonScale(1, 0), 1);
  near(g.octagonScale(0, 1), 1);
  near(g.octagonScale(1, 1), 1);
  near(g.octagonScale(-1, 1), 1);
  const a22 = (Math.PI / 8);
  near(g.octagonScale(Math.cos(a22), Math.sin(a22)), Math.cos(Math.PI / 8));
  near(g.octagonScale(Math.cos(3 * a22), Math.sin(3 * a22)), Math.cos(Math.PI / 8));
  // Through the mapping: a full push at 22.5 degrees is 92 units, with the octagon off 100.
  const m = g.defaultMapping();
  const pt = { buttons: [], axes: [Math.cos(a22), -Math.sin(a22), 0, 0] };
  const o = g.mapGamepad(pt, m);
  near(Math.hypot(o.stickX, o.stickY), 92.4, 1);
  m.octagon = false;
  const c = g.mapGamepad(pt, m);
  near(Math.hypot(c.stickX, c.stickY), 100, 1);
  // The notches (cardinals and diagonals) reach the same distance.
  m.octagon = true;
  for (const [x, y] of [[1, 0], [0, -1], [-1, 0], [Math.SQRT1_2, -Math.SQRT1_2], [-1, 1]]) {
    const r = g.mapGamepad({ buttons: [], axes: [x, y, 0, 0] }, m);
    near(Math.hypot(r.stickX, r.stickY), 100, 1);
  }
  // A push past the circle (a square gate) is limited, never beyond the range.
  const big = g.mapGamepad({ buttons: [], axes: [1, 1, 1, -1] }, m);
  assert.ok(Math.hypot(big.stickX, big.stickY) <= 100.5 && Math.hypot(big.cX, big.cY) <= 100.5);
  // Octagon storage.
  m.octagon = false;
  assert.equal(g.parseMapping(JSON.stringify(m)).octagon, false);
  assert.equal(g.parseMapping(JSON.stringify({ ...m, octagon: 'yes' })).octagon, true);
});

test('dead zone is configurable and radial, the first step past it is small', () => {
  const m = g.defaultMapping();
  m.deadzone = 0.3;
  assert.deepEqual(Object.values(g.shapeStick(0.29, 0, m)), [0, 0]);
  const [x] = g.shapeStick(0.35, 0, m);
  assert.ok(x > 0 && x < 12, String(x));
  assert.equal(g.shapeStick(1, 0, m)[0], 100);
  assert.equal(g.shapeStick(NaN, 0, m)[0], 0);
});

// ---- identification and profiles ----

test('ids: Chrome and Firefox spell the same pad differently, the key is the same', () => {
  assert.deepEqual(prof.parseId(DS4_CHROME), { vendor: '054c', product: '09cc', name: 'Wireless Controller' });
  assert.deepEqual(prof.parseId(DS4_FIREFOX), { vendor: '054c', product: '09cc', name: 'Wireless Controller' });
  assert.deepEqual(prof.parseId(MAYFLASH), { vendor: '0079', product: '1843', name: 'MAYFLASH GameCube Controller Adapter' });
  assert.deepEqual(prof.parseId('Xbox 360 Controller (XInput STANDARD GAMEPAD)'),
                   { vendor: null, product: null, name: 'Xbox 360 Controller' });
  assert.equal(prof.parseId('45e-2ea-Xbox One S pad').vendor, '045e');
  assert.equal(prof.parseId('').name, 'Controller');
  const info = (id, mapping = 'standard') => ({ id, mapping, nButtons: 17, nAxes: 4 });
  assert.equal(prof.deviceKey(info(DS4_CHROME)), '054c:09cc');
  assert.equal(prof.deviceKey(info(DS4_FIREFOX, '')), '054c:09cc');
  assert.match(prof.deviceKey({ id: 'Some Pad', mapping: '', nButtons: 12, nAxes: 6 }), /^some pad\|12b6a$/);
});

test('families: Xbox, PlayStation, Nintendo, GameCube adapters, the rest', () => {
  const f = (id) => prof.familyOf({ id, mapping: '', nButtons: 12, nAxes: 6 });
  assert.equal(f(XBOX_CHROME), 'xbox');
  assert.equal(f('Xbox 360 Controller (XInput STANDARD GAMEPAD)'), 'xbox');
  assert.equal(f(DS4_FIREFOX), 'playstation');
  assert.equal(f(PRO_CHROME), 'nintendo');
  assert.equal(f(MAYFLASH), 'gamecube');
  assert.equal(f('Nintendo Co., Ltd. Wii U GameCube Controller Adapter (Vendor: 057e Product: 0337)'), 'gamecube');
  assert.equal(f('057e-0337-NGC Controller'), 'gamecube');
  assert.equal(f('USB Gamepad (Vendor: 0810 Product: e501)'), 'generic');
});

test('profiles: standard pads use the standard layout, Nintendo pads their own button names', () => {
  const std = prof.profileFor({ id: XBOX_CHROME, mapping: 'standard', nButtons: 17, nAxes: 4 });
  assert.equal(std.id, 'standard');
  assert.deepEqual(std.mapping, g.defaultMapping());
  const nin = prof.profileFor({ id: PRO_CHROME, mapping: 'standard', nButtons: 17, nAxes: 4 });
  assert.equal(nin.id, 'standard-nintendo');
  // The Pro's A is the right button (standard index 1), its B the bottom one (0), X on top (3), Y on the left (2).
  const press = (i) => g.mapGamepad(pad({ id: PRO_CHROME }).press(i), nin.mapping).buttons;
  assert.equal(press(1), PAD.A);
  assert.equal(press(0), PAD.B);
  assert.equal(press(3), PAD.X);
  assert.equal(press(2), PAD.Y);
  assert.equal(press(9), PAD.START);
  assert.equal(prof.needsSetup({ id: XBOX_CHROME, mapping: 'standard', nButtons: 17, nAxes: 4 }), false);
  // PlayStation pads are standard in the browsers that know them.
  assert.equal(prof.profileFor({ id: DS4_CHROME, mapping: 'standard', nButtons: 18, nAxes: 4 }).id, 'standard');
});

test('profiles: an Xbox pad without the standard mapping (Linux joystick order)', () => {
  const info = { id: XPAD_FIREFOX, mapping: '', nButtons: 11, nAxes: 8 };
  const p = prof.profileFor(info);
  assert.equal(p.id, 'xbox-raw');
  assert.equal(prof.needsSetup(info), false);
  const raw = () => pad({ id: XPAD_FIREFOX, mapping: '', buttons: 11, axes: 8, axisRest: { 2: -1, 5: -1 } });
  assert.equal(g.mapGamepad(raw().press(0), p.mapping).buttons, PAD.A);
  assert.equal(g.mapGamepad(raw().press(7), p.mapping).buttons, PAD.START);
  assert.equal(g.mapGamepad(raw().press(5), p.mapping).buttons, PAD.Z);
  assert.equal(g.mapGamepad(raw().axis(7, -1), p.mapping).buttons, PAD.UP);
  assert.equal(g.mapGamepad(raw().axis(6, 1), p.mapping).buttons, PAD.RIGHT);
  // Triggers rest at -1 and click at the end of their travel.
  let o = g.mapGamepad(raw(), p.mapping);
  assert.deepEqual([o.trigL, o.trigR, o.buttons], [0, 0, 0]);
  o = g.mapGamepad(raw().axis(2, 1).axis(5, 0), p.mapping);
  assert.deepEqual([o.trigL, o.trigR, o.buttons], [255, 128, PAD.L]);
  o = g.mapGamepad(raw().axis(0, 1).axis(1, -1).axis(3, -1).axis(4, 1), p.mapping);
  assert.deepEqual([o.stickX, o.stickY, o.cX, o.cY], [71, 71, -71, -71]);  // a square push is clamped to the gate
});

test('profiles: GameCube adapters and unknown pads start from a guess and want the guided setup', () => {
  const gc = { id: MAYFLASH, mapping: '', nButtons: 12, nAxes: 6 };
  assert.equal(prof.profileFor(gc).id, 'gamecube-adapter');
  assert.equal(prof.needsSetup(gc), true);
  const unknown = { id: 'USB Gamepad (Vendor: 0810 Product: e501)', mapping: '', nButtons: 10, nAxes: 4 };
  assert.equal(prof.profileFor(unknown).id, 'generic');
  assert.equal(prof.needsSetup(unknown), true);
  // The guess is enough for the menus: face buttons, a hat D-pad, the left stick.
  const m = prof.profileFor(unknown).mapping;
  assert.equal(g.mapGamepad({ buttons: [{ pressed: true, value: 1 }], axes: [] }, m).buttons, PAD.A);
  assert.equal(g.mapGamepad({ buttons: [], axes: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0.1428571] }, m).buttons, PAD.DOWN);
});

// ---- the keyboard ----

test('keyboard: the E2 keys still work, the C-stick is on the keypad', () => {
  const map = keys.defaultKeyMap();
  const p = (...codes) => keys.keysToPad(new Set(codes), map);
  assert.equal(p('Enter').buttons, PAD.START);
  assert.equal(p('KeyX').buttons, PAD.A);
  assert.equal(p('KeyZ').buttons, PAD.B);
  assert.equal(p('KeyC').buttons, PAD.X);
  assert.equal(p('KeyV').buttons, PAD.Y);
  assert.equal(p('Space').buttons, PAD.Z);
  assert.equal(p('ArrowUp', 'ArrowLeft').buttons, PAD.UP | PAD.LEFT);
  assert.deepEqual([p('KeyQ').buttons, p('KeyQ').trigL, p('KeyE').trigR], [PAD.L, 255, 255]);
  assert.deepEqual([p('KeyI').stickY, p('KeyK').stickY, p('KeyJ').stickX, p('KeyL').stickX], [100, -100, -100, 100]);
  assert.deepEqual([p('KeyI', 'KeyK').stickY, p('KeyJ', 'KeyL').stickX], [0, 0]);  // opposite keys cancel
  // A diagonal is at the gate's notch, not beyond.
  const d = p('KeyI', 'KeyL');
  assert.deepEqual([d.stickX, d.stickY], [71, 71]);
  const c = p('Numpad8', 'Numpad4');
  assert.deepEqual([c.cX, c.cY], [-71, 71]);
  assert.deepEqual(p().buttons, 0);
});

test('keyboard: rebinding swaps with the key it takes, refuses the page keys', () => {
  const map = keys.defaultKeyMap();
  let r = keys.rebindKey(map, 'A', 'KeyN');
  assert.deepEqual(r.map.A, ['KeyN']);
  assert.deepEqual(r.swapped, []);
  assert.equal(keys.keysToPad(new Set(['KeyN']), r.map).buttons, PAD.A);
  assert.equal(keys.keysToPad(new Set(['KeyX']), r.map).buttons, 0);
  // Taking B's key gives B the key A had: no key does two things, nothing is left without one.
  r = keys.rebindKey(map, 'A', 'KeyZ');
  assert.deepEqual(r.map.A, ['KeyZ']);
  assert.deepEqual(r.map.B, ['KeyX']);
  assert.deepEqual(r.swapped, ['B']);
  assert.equal(new Set(keys.KEY_ACTIONS.flatMap((a) => r.map[a])).size, keys.KEY_ACTIONS.length);
  for (const code of ['KeyF', 'KeyM', 'KeyP', 'Escape', 'Tab', 'F5', 'ControlLeft', 'Bad Key'])
    assert.ok('error' in keys.rebindKey(map, 'A', code), code);
  assert.deepEqual(keys.resetKey(r.map, 'A').A, ['KeyX']);
});

test('keyboard: stored map is checked as a whole, labels follow the keyboard layout', () => {
  const map = keys.defaultKeyMap();
  assert.deepEqual(keys.parseKeyMap(JSON.parse(JSON.stringify(map))), map);
  assert.deepEqual(keys.parseKeyMap(null), map);
  assert.deepEqual(keys.parseKeyMap({ ...map, A: ['KeyZ'] }), map);       // KeyZ twice: whole map falls back
  assert.deepEqual(keys.parseKeyMap({ ...map, A: [] }), map);
  assert.deepEqual(keys.parseKeyMap({ ...map, A: ['KeyF'] }), map);       // reserved
  assert.deepEqual(keys.parseKeyMap({ ...map, A: [5] }), map);
  assert.equal(keys.keyLabel('KeyX'), 'X');
  assert.equal(keys.keyLabel('ArrowUp'), 'Up arrow');
  assert.equal(keys.keyLabel('Numpad8'), 'Numpad 8');
  assert.equal(keys.keyLabel('KeyZ', new Map([['KeyZ', 'w']])), 'W');  // an AZERTY keyboard
  assert.equal(keys.keyLabel('Space'), 'Space');
});

// ---- the stored settings ----

function memStorage() {
  const m = new Map();
  return { getItem: (k) => (m.has(k) ? m.get(k) : null), setItem: (k, v) => m.set(k, v), removeItem: (k) => m.delete(k), m };
}

test('settings: saved per browser, read field by field', () => {
  const s = memStorage();
  assert.deepEqual(store.loadConfig(s), store.defaultConfig());
  let c = store.defaultConfig();
  const m = g.defaultMapping();
  m.buttons.A = [{ type: 'button', index: 3 }];
  m.deadzone = 0.22;
  c = store.withMapping(c, '054c:09cc', m);
  c = store.withPort(c, 1, { mode: 'device', key: '054c:09cc', nth: 0, name: 'Wireless Controller' });
  c = { ...c, keyboardPort: -1, rumble: false, keys: keys.rebindKey(c.keys, 'A', 'KeyN').map };
  store.saveConfig(s, c);
  assert.deepEqual(store.loadConfig(s), c);
  // Damage: not JSON, a wrong version, bad pieces.
  s.setItem(store.CONFIG_KEY, '{nope');
  assert.deepEqual(store.loadConfig(s), store.defaultConfig());
  s.setItem(store.CONFIG_KEY, JSON.stringify({ ...c, version: 3 }));
  assert.deepEqual(store.loadConfig(s), store.defaultConfig());
  s.setItem(store.CONFIG_KEY, JSON.stringify({
    ...c, ports: [{ mode: 'device', key: '', nth: 0 }, { mode: 'device', key: 'x', nth: -1 }], keyboardPort: 7, rumble: 'yes',
    devices: { '054c:09cc': { ...m, deadzone: 9 }, '': m, bad: 5 },
  }));
  const d = store.loadConfig(s);
  assert.deepEqual(d.ports, [{ mode: 'auto' }, { mode: 'auto' }]);
  assert.equal(d.keyboardPort, 0);
  assert.equal(d.rumble, true);
  assert.deepEqual(d.devices['054c:09cc'].buttons.A, [{ type: 'button', index: 3 }]);  // kept
  assert.equal(d.devices['054c:09cc'].deadzone, g.defaultMapping().deadzone);          // fell back
  assert.equal(Object.keys(d.devices).includes(''), false);
  // No storage, or storage that throws: defaults, no error.
  assert.deepEqual(store.loadConfig(null), store.defaultConfig());
  const throwing = { getItem() { throw new Error('denied'); }, setItem() { throw new Error('denied'); }, removeItem() {} };
  assert.deepEqual(store.loadConfig(throwing), store.defaultConfig());
  store.saveConfig(throwing, c);
});

test('settings: the E2c mapping is read once, for every pad without its own', () => {
  const s = memStorage();
  const old = g.defaultMapping();
  old.buttons.A = [{ type: 'button', index: 1 }];
  old.buttons.B = [{ type: 'button', index: 0 }];
  s.setItem(g.STORAGE_KEY, JSON.stringify(old));
  const c = store.loadConfig(s);
  assert.deepEqual(store.storedMapping(c, 'anything'), old);
  const own = g.defaultMapping();
  own.buttons.X = [{ type: 'button', index: 9 }];
  const c2 = store.withMapping(c, 'k', own);
  assert.deepEqual(store.storedMapping(c2, 'k'), own);
  assert.deepEqual(store.storedMapping(c2, 'other'), old);
  assert.equal(store.storedMapping(store.defaultConfig(), 'k'), null);
  assert.equal(store.storedMapping(store.withoutMapping(c2, 'k'), 'k').buttons.A[0].index, 1);
});

test('settings: one pad drives one port', () => {
  let c = store.defaultConfig();
  c = store.withPort(c, 0, { mode: 'device', key: 'k', nth: 0 });
  c = store.withPort(c, 1, { mode: 'device', key: 'k', nth: 0 });
  assert.deepEqual(c.ports, [{ mode: 'auto' }, { mode: 'device', key: 'k', nth: 0 }]);
  c = store.withPort(c, 0, { mode: 'device', key: 'k', nth: 1 });
  assert.deepEqual(c.ports[1], { mode: 'device', key: 'k', nth: 0 });
});

// ---- the pad manager ----

function manager(pads, config = store.defaultConfig()) {
  const events = [];
  const m = new mgr.PadManager(() => pads.list, config);
  m.onEvent = (e) => events.push(`${e.kind}:${e.device.name}${e.port === undefined ? '' : `@${e.port}`}`);
  const set = { list: pads.list };
  return { m, events, set };
}
const bag = (...list) => ({ list });

test('manager: no controller, the keyboard plays port 1 and port 2 is empty', () => {
  const { m } = manager(bag());
  m.keys = new Set(['Enter', 'KeyL']);
  const [p1, p2] = m.sample();
  assert.deepEqual(p1, { connected: true, buttons: PAD.START, stickX: 100, stickY: 0, cX: 0, cY: 0, trigL: 0, trigR: 0 });
  assert.equal(p2.connected, false);
  assert.equal(m.devices.length, 0);
});

test('manager: a pad is idle until it is used, then it is player 1 (Chrome shows it on its first press)', () => {
  const x = pad();
  const { m, events } = manager(bag(x));
  let [p1] = m.sample();
  assert.equal(m.devices[0].active, false);
  assert.equal(m.devices[0].port, -1);
  assert.deepEqual(events, ['connected:Xbox Wireless Controller']);
  x.press(0);
  [p1] = m.sample();
  assert.equal(m.devices[0].active, true);
  assert.equal(m.devices[0].port, 0);
  assert.equal(p1.buttons, PAD.A);
  assert.deepEqual(events, ['connected:Xbox Wireless Controller', 'claimed:Xbox Wireless Controller@0']);
  // A pad that already shows a pressed button when it first appears (Chrome) claims at once.
  const y = pad({ index: 0 }).press(9);
  const t = manager(bag(y));
  assert.equal(t.m.sample()[0].buttons, PAD.START);
  assert.equal(t.m.devices[0].port, 0);
});

test('manager: analog sticks, triggers and the keyboard merge on one port', () => {
  const x = pad().press(0);
  const { m } = manager(bag(x));
  m.keys = new Set(['KeyZ', 'KeyI']);
  x.axis(0, 1).press(6, 1).press(7, 0.5);
  const [p1] = m.sample();
  assert.equal(p1.buttons, PAD.A | PAD.B | PAD.L);
  assert.deepEqual([p1.stickX, p1.stickY], [100, 100]);
  assert.deepEqual([p1.trigL, p1.trigR], [255, 128]);
  // Merged sticks stay inside the byte range.
  m.keys = new Set(['KeyL']);
  assert.equal(m.sample()[0].stickX, 127);
});

test('manager: hot-plug, the pad goes away and comes back', () => {
  const x = pad().press(0);
  const bagx = bag(x);
  const { m, events } = manager(bagx);
  m.sample();
  assert.equal(m.devices[0].port, 0);
  bagx.list = [null, null];                       // unplugged: the slot is empty
  let [p1] = m.sample();
  assert.equal(m.devices.length, 0);
  assert.equal(p1.connected, true);                // port 1 stays plugged in for the keyboard
  assert.deepEqual([p1.buttons, p1.stickX], [0, 0]);
  assert.equal(events.at(-1), 'disconnected:Xbox Wireless Controller');
  const back = pad({ index: 1 }).press(1);        // plugged in again, another slot
  bagx.list = [null, back];
  [p1] = m.sample();
  assert.equal(p1.buttons, PAD.B);
  assert.equal(m.devices[0].port, 0);
  assert.equal(events.at(-1), 'claimed:Xbox Wireless Controller@0');
  // A pad that reports connected = false counts as gone.
  back.connected = false;
  m.sample();
  assert.equal(m.devices.length, 0);
});

test('manager: the second pad to be used is player 2, and keeps it', () => {
  const a = pad({ index: 0 }), b = pad({ index: 1, id: DS4_CHROME });
  const list = bag(a, b);
  const { m } = manager(list);
  m.sample();
  b.press(0);                                      // the PlayStation pad is used first
  let ports = m.sample();
  assert.equal(m.devices.find((d) => d.index === 1).port, 0);
  assert.equal(ports[0].buttons, PAD.A);
  assert.equal(ports[1].connected, false);
  a.press(1);
  ports = m.sample();
  assert.equal(m.devices.find((d) => d.index === 0).port, 1);
  assert.equal(ports[1].connected, true);
  assert.equal(ports[1].buttons, PAD.B);
  // Player 1's pad leaves: player 2 keeps port 2, and the next pad used takes port 1.
  list.list = [a, null];
  ports = m.sample();
  assert.equal(m.devices[0].port, 1);
  assert.equal(ports[0].connected, true);
  assert.equal(ports[0].buttons, 0);
  assert.equal(ports[1].buttons, PAD.B);
});

test('manager: idle phantoms (an adapter lists its empty ports) never take a port', () => {
  const ghosts = [0, 1, 2, 3].map((i) => pad({ index: i, id: MAYFLASH, mapping: '', buttons: 12, axes: 6, axisRest: { 4: -1, 5: -1 } }));
  const { m } = manager(bag(...ghosts));
  m.sample();
  assert.deepEqual(m.devices.map((d) => d.port), [-1, -1, -1, -1]);
  assert.deepEqual(m.devices.map((d) => d.nth), [0, 1, 2, 3]);
  ghosts[2].press(1);                              // the controller in the third socket is used
  m.sample();
  assert.deepEqual(m.devices.map((d) => d.port), [-1, -1, 0, -1]);
  // A trigger resting at -1 and moving to +1 is use too; noise below the threshold is not.
  ghosts[0].axis(3, 0.2);
  m.sample();
  assert.equal(m.devices[0].port, -1);
  ghosts[3].axis(4, 1);
  m.sample();
  assert.equal(m.devices[3].port, 1);
});

test('manager: ports assigned by hand, by model and by order among equal models', () => {
  const a = pad({ index: 0 }), b = pad({ index: 1 });   // two of one model
  let c = store.defaultConfig();
  c = store.withPort(c, 0, { mode: 'device', key: '045e:0b13', nth: 1 });
  c = store.withPort(c, 1, { mode: 'device', key: '045e:0b13', nth: 0 });
  const { m } = manager(bag(a, b), c);
  b.press(0);                                           // used or not, the assignment holds
  const ports = m.sample();
  assert.deepEqual(m.devices.map((d) => d.port), [1, 0]);
  assert.equal(ports[0].buttons, PAD.A);
  assert.equal(ports[1].buttons, 0);
  assert.equal(ports[1].connected, true);
  // A port set to none takes nothing, even a used pad; the keyboard can move to port 2.
  c = store.withPort(store.defaultConfig(), 0, { mode: 'none' });
  c = { ...c, keyboardPort: 1 };
  const t = manager(bag(pad().press(0)), c);
  t.m.keys = new Set(['KeyX']);
  const out = t.m.sample();
  assert.equal(t.m.devices[0].port, 1);                 // auto skips the port set to none
  assert.equal(out[0].buttons, 0);
  assert.equal(out[1].buttons, PAD.A);                  // keyboard X and the pad's A on player 2
  // A pad set for a port that is not connected leaves it empty.
  const u = manager(bag(), store.withPort(store.defaultConfig(), 1, { mode: 'device', key: 'zz', nth: 0 }));
  assert.equal(u.m.sample()[1].connected, false);
});

test('manager: each model has its own mapping and settings', () => {
  const x = pad().press(0), y = pad({ index: 1, id: DS4_CHROME }).press(0);
  let c = store.defaultConfig();
  const mine = g.defaultMapping();
  mine.buttons.A = [{ type: 'button', index: 3 }];
  c = store.withMapping(c, '054c:09cc', mine);
  const { m } = manager(bag(x, y), c);
  m.sample();
  const byIndex = (i) => m.devices.find((d) => d.index === i);
  assert.equal(byIndex(0).part.buttons, PAD.A);       // untouched model: the standard layout
  assert.equal(byIndex(1).part.buttons, 0);           // remapped: button 0 is no longer A
  assert.equal(byIndex(1).custom, true);
  assert.equal(byIndex(0).custom, false);
  y.release(0).press(3);                               // the button that is now A (and still Y: nothing was unbound)
  m.sample();
  assert.equal(byIndex(1).part.buttons, PAD.A | PAD.Y);
  // Config changes apply at the next sample.
  m.config = store.withoutMapping(m.config, '054c:09cc');
  m.sample();
  assert.equal(byIndex(1).part.buttons, PAD.Y);
});

test('manager: while the panel rebinds, neither pad nor keyboard reaches the game', () => {
  const x = pad().press(0);
  const { m } = manager(bag(x));
  m.keys = new Set(['KeyZ']);
  assert.equal(m.sample()[0].buttons, PAD.A | PAD.B);
  m.capture = true;
  const [p1] = m.sample();
  assert.deepEqual([p1.connected, p1.buttons, p1.stickX], [true, 0, 0]);
  m.capture = false;
  assert.equal(m.sample()[0].buttons, PAD.A | PAD.B);
});

test('manager: online only the local player plays, whichever port the pad was set for', () => {
  const x = pad().press(0);
  let c = store.withPort(store.defaultConfig(), 1, { mode: 'device', key: '045e:0b13', nth: 0 });
  c = store.withPort(c, 0, { mode: 'none' });
  const { m } = manager(bag(x), c);
  m.keys = new Set(['KeyZ']);
  let ports = m.sample();
  assert.equal(ports[0].buttons, PAD.B);              // offline: the keyboard is player 1
  assert.equal(ports[1].buttons, PAD.A);
  m.online = true;
  ports = m.sample();
  assert.equal(ports[0].buttons, PAD.A | PAD.B);      // online: one pad, the local player's
  assert.equal(ports[1].connected, false);
  assert.equal(m.localDevice().name, 'Xbox Wireless Controller');
  m.config = { ...m.config, keyboardPort: -1 };
  assert.equal(m.sample()[0].buttons, PAD.A);         // the keyboard can be turned off
  const none = manager(bag());
  none.m.online = true;
  assert.equal(none.m.localDevice(), null);
  assert.equal(none.m.sample()[0].connected, true);
});

test('manager: a browser without the Gamepad API, or one that throws, is no controller', () => {
  const m = new mgr.PadManager(() => { throw new Error('policy'); }, store.defaultConfig());
  assert.equal(m.sample()[0].connected, true);
  assert.equal(m.devices.length, 0);
});

// ---- press-to-bind ----

const snap = (buttons = [], axes = []) => ({ buttons, axes });

test('rebind: waits for rest, takes the first press, waits for the release', () => {
  const controls = [{ kind: 'button', name: 'A' }, { kind: 'button', name: 'B' }];
  const r = new reb.Rebinder(controls, snap([0, 0, 0, 0], [0, 0]));
  // A button still held from before is not the answer.
  assert.deepEqual(r.update(snap([0, 1, 0, 0], [0, 0]), 0), []);
  assert.equal(r.phase, 'neutral');
  assert.equal(r.prompt, 'Let go of every button and stick...');
  assert.deepEqual(r.update(snap([0, 0, 0, 0], [0, 0]), 10), [{ type: 'prompt', step: 0, control: controls[0] }]);
  assert.equal(r.prompt, 'Press the A button (the big one)');
  assert.deepEqual(r.update(snap([0, 0, 1, 0], [0, 0]), 20),
                   [{ type: 'bound', step: 0, control: controls[0], source: { type: 'button', index: 2 } }]);
  assert.equal(r.phase, 'release');
  assert.deepEqual(r.update(snap([0, 0, 1, 0], [0, 0]), 30), []);       // still down
  assert.deepEqual(r.update(snap([0, 0, 0, 0], [0, 0]), 40), []);       // released: on to B
  assert.equal(r.step, 1);
  assert.equal(r.phase, 'neutral');
  assert.deepEqual(r.update(snap([0, 0, 0, 0], [0, 0]), 50), [{ type: 'prompt', step: 1, control: controls[1] }]);
  const done = r.update(snap([1, 0, 0, 0], [0, 0]), 60);
  assert.equal(done[0].type, 'bound');
  const end = r.update(snap([0, 0, 0, 0], [0, 0]), 70);
  assert.deepEqual(end, [{ type: 'done', cancelled: false }]);
  assert.equal(r.control, null);
});

test('rebind: a stick or a trigger on an axis, a hat for the D-pad, buttons ignored for sticks', () => {
  const rest = snap([0, 0], [0, 0, -1, 1.2857143]);
  const stick = new reb.Rebinder([{ kind: 'axis', name: 'stickY' }], rest);
  stick.update(rest, 0);
  assert.deepEqual(stick.update(snap([1, 0], [0, 0, -1, 1.2857143]), 5), []);                       // a button is not a stick
  const ev = stick.update(snap([0, 0], [0, -0.95, -1, 1.2857143]), 10);
  assert.deepEqual(ev[0].source, { type: 'axis', index: 1, dir: -1 });
  const trig = new reb.Rebinder([{ kind: 'trigger', name: 'L' }], rest);
  trig.update(rest, 0);
  assert.deepEqual(trig.update(snap([0, 0], [0, 0, 1, 1.2857143]), 5)[0].source, { type: 'axis', index: 2, dir: 1, full: true });
  const dpad = new reb.Rebinder([{ kind: 'button', name: 'UP' }], rest);
  dpad.update(rest, 0);
  assert.deepEqual(dpad.update(snap([0, 0], [0, 0, -1, -1]), 5)[0].source, { type: 'hat', index: 3, dir: 'up' });
});

test('rebind: a trigger takes its analog axis over the click button that comes with it', () => {
  const rest = snap([0, 0, 0], [0, 0, -1]);
  const r = new reb.Rebinder([{ kind: 'trigger', name: 'L' }], rest);
  r.update(rest, 0);
  const ev = r.update(snap([0, 1, 0], [0, 0, 1]), 5);   // the axis and the end-of-travel click in one frame
  assert.deepEqual(ev[0].source, { type: 'axis', index: 2, dir: 1, full: true });
  // A pad whose trigger is only a button still works.
  const r2 = new reb.Rebinder([{ kind: 'trigger', name: 'R' }], rest);
  r2.update(rest, 0);
  assert.deepEqual(r2.update(snap([0, 1, 0], [0, 0, -1]), 5)[0].source, { type: 'button', index: 1 });
});

test('rebind: times out, skips, goes back, cancels', () => {
  const rest = snap([0], [0]);
  const controls = reb.allControls().slice(0, 3);
  const r = new reb.Rebinder(controls, rest, 1000);
  r.update(rest, 0);
  assert.deepEqual(r.update(rest, 999), []);
  assert.deepEqual(r.update(rest, 1001), [{ type: 'timeout', step: 0, control: controls[0] }]);
  assert.equal(r.step, 1);
  r.update(rest, 1002);
  assert.deepEqual(r.skip(), []);
  assert.equal(r.step, 2);
  r.back();
  assert.equal(r.step, 1);
  assert.deepEqual(r.cancel(), [{ type: 'done', cancelled: true }]);
  assert.equal(r.phase, 'finished');
  assert.deepEqual(r.update(snap([1], [0]), 5000), []);
  assert.deepEqual(r.cancel(), []);
});

test('rebind: applying a binding moves a physical control from its old job', () => {
  const m = g.defaultMapping();
  let n = reb.applyBinding(m, { kind: 'button', name: 'B' }, { type: 'button', index: 0 });  // the A button's place
  assert.deepEqual(n.buttons.B, [{ type: 'button', index: 0 }]);
  assert.deepEqual(n.buttons.A, []);                                                        // A lost it
  assert.deepEqual(m.buttons.A, [{ type: 'button', index: 0 }]);                            // the input is untouched
  n = reb.applyBinding(m, { kind: 'trigger', name: 'R' }, { type: 'button', index: 6 });    // L's button
  assert.deepEqual(n.triggers.R, [{ type: 'button', index: 6 }]);
  assert.deepEqual(n.triggers.L, []);
  n = reb.applyBinding(m, { kind: 'axis', name: 'cY' }, { type: 'axis', index: 5, dir: 1 });
  assert.deepEqual(n.axes.cY, { index: 5, invert: false });
  n = reb.applyBinding(m, { kind: 'axis', name: 'cY' }, { type: 'axis', index: 5, dir: -1 });
  assert.deepEqual(n.axes.cY, { index: 5, invert: true });
  assert.equal(reb.applyBinding(m, { kind: 'axis', name: 'cY' }, { type: 'button', index: 1 }), null);
  assert.equal(reb.applyBinding(m, { kind: 'trigger', name: 'L' }, { type: 'hat', index: 9, dir: 'up' }), null);
  // Every control is in the guided setup once, and each can be set alone.
  assert.equal(new Set(reb.allControls().map(reb.controlId)).size, 16);
  assert.equal(reb.settableControls().length, 16);
});

test('rebind: a whole guided setup of a pad that is not standard, then it plays', () => {
  // A made-up pad: buttons 3 5 7 9 are A B X Y ..., the sticks on axes 4/5 and 2/3.
  const press = {
    'button:A': { b: 3 }, 'button:B': { b: 5 }, 'button:X': { b: 7 }, 'button:Y': { b: 9 }, 'button:Z': { b: 11 },
    'button:START': { b: 1 }, 'trigger:L': { a: [6, 1, true] }, 'trigger:R': { a: [7, 1, true] },
    'button:UP': { h: [8, 'up'] }, 'button:DOWN': { h: [8, 'down'] }, 'button:LEFT': { h: [8, 'left'] },
    'button:RIGHT': { h: [8, 'right'] },
    'axis:stickX': { a: [4, 1] }, 'axis:stickY': { a: [5, -1] }, 'axis:cX': { a: [2, 1] }, 'axis:cY': { a: [3, -1] },
  };
  const rest = () => pad({ id: 'Odd Pad', mapping: '', buttons: 12, axes: 9, axisRest: { 6: -1, 7: -1, 8: 1.2857143 } });
  let m = g.defaultMapping();
  const controls = reb.allControls();
  const r = new reb.Rebinder(controls, g.snapshot(rest()));
  let t = 0;
  for (const c of controls) {
    r.update(g.snapshot(rest()), (t += 10));                          // rest: the prompt
    assert.equal(r.control && reb.controlId(r.control), reb.controlId(c));
    const p = rest();
    const how = press[reb.controlId(c)];
    if (how.b !== undefined) p.press(how.b);
    else if (how.h) p.axis(how.h[0], { up: -1, down: 0.1428571, left: 0.7142857, right: -0.4285714 }[how.h[1]]);
    else p.axis(how.a[0], how.a[1] * (how.a[2] ? 1 : 1));
    const ev = r.update(g.snapshot(p), (t += 10));
    const bound = ev.find((e) => e.type === 'bound');
    assert.ok(bound, reb.controlId(c));
    m = reb.applyBinding(m, bound.control, bound.source);
    assert.ok(m, reb.controlId(c));
    r.update(g.snapshot(rest()), (t += 10));                          // let go
  }
  assert.equal(r.phase, 'finished');
  const play = (f) => g.mapGamepad(f(rest()), m);
  assert.equal(play((p) => p.press(3)).buttons, PAD.A);
  assert.equal(play((p) => p.press(1)).buttons, PAD.START);
  assert.equal(play((p) => p.axis(8, -1)).buttons, PAD.UP);
  assert.equal(play((p) => p.axis(8, 0.7142857)).buttons, PAD.LEFT);
  const trig = play((p) => p.axis(6, 1));
  assert.deepEqual([trig.trigL, trig.buttons], [255, PAD.L]);
  assert.equal(play((p) => p).trigL, 0);
  const st = play((p) => p.axis(4, 1).axis(5, -1));
  assert.deepEqual([st.stickX, st.stickY], [71, 71]);
  const cs = play((p) => p.axis(2, -1));
  assert.deepEqual([cs.cX, cs.cY], [-100, 0]);
});
