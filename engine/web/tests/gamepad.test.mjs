// The gamepad mapping (src/gamepad.ts), data-free: standard-layout pads,
// triggers, sticks, rebinding, and the stored mapping.
import assert from 'node:assert/strict';
import { test } from 'node:test';
import { load } from './site.mjs';

const g = await load('gamepad.js');
const { PAD } = g;

// A standard-layout pad at rest, with overrides.
function pad({ pressed = [], values = {}, axes = [0, 0, 0, 0], mapping = 'standard' } = {}) {
  const buttons = Array.from({ length: 17 }, (_, i) => ({
    pressed: pressed.includes(i), value: values[i] ?? (pressed.includes(i) ? 1 : 0),
  }));
  return { id: 'test pad', mapping, connected: true, buttons, axes };
}

test('standard layout: face buttons, Start, D-pad, bumpers', () => {
  const m = g.defaultMapping();
  const cases = [
    [0, PAD.A], [1, PAD.B], [2, PAD.X], [3, PAD.Y], [5, PAD.Z], [4, PAD.Z], [9, PAD.START],
    [12, PAD.UP], [13, PAD.DOWN], [14, PAD.LEFT], [15, PAD.RIGHT],
  ];
  for (const [index, bit] of cases) {
    const out = g.mapGamepad(pad({ pressed: [index] }), m);
    assert.equal(out.buttons, bit, `button ${index}`);
  }
  // Unmapped buttons (Back, stick presses, Home) do nothing.
  for (const index of [8, 10, 11, 16]) assert.equal(g.mapGamepad(pad({ pressed: [index] }), m).buttons, 0);
  // Several at once.
  assert.equal(g.mapGamepad(pad({ pressed: [0, 9, 12] }), m).buttons, PAD.A | PAD.START | PAD.UP);
  // At rest: neutral.
  assert.deepEqual(g.mapGamepad(pad(), m), { buttons: 0, stickX: 0, stickY: 0, cX: 0, cY: 0, trigL: 0, trigR: 0 });
});

test('triggers: analog L/R, digital click at the end of the travel', () => {
  const m = g.defaultMapping();
  let out = g.mapGamepad(pad({ values: { 6: 0.5, 7: 0.2 } }), m);
  assert.equal(out.trigL, 128);
  assert.equal(out.trigR, 51);
  assert.equal(out.buttons & (PAD.L | PAD.R), 0);
  out = g.mapGamepad(pad({ values: { 6: 0.89 } }), m);
  assert.equal(out.buttons & PAD.L, 0);
  out = g.mapGamepad(pad({ pressed: [6, 7], values: { 6: 1, 7: 0.95 } }), m);
  assert.equal(out.trigL, 255);
  assert.equal(out.trigR, 242);
  assert.equal(out.buttons, PAD.L | PAD.R);
  // Browsers report a trigger as pressed early in its travel: the value decides.
  out = g.mapGamepad(pad({ pressed: [6], values: { 6: 0.3 } }), m);
  assert.equal(out.trigL, 77);
  assert.equal(out.buttons & PAD.L, 0);
  // A pad that reports a trigger as pressed with value 0 (digital triggers) still clicks.
  out = g.mapGamepad(pad({ pressed: [7], values: { 7: 0 } }), m);
  assert.equal(out.trigR, 255);
  assert.equal(out.buttons, PAD.R);
});

test('sticks: up is positive, radial dead zone, full range, C-stick on the right stick', () => {
  const m = g.defaultMapping();
  let out = g.mapGamepad(pad({ axes: [0, -1, 0, 0] }), m);  // left stick up
  assert.deepEqual([out.stickX, out.stickY], [0, 100]);
  out = g.mapGamepad(pad({ axes: [1, 0, 0, 0] }), m);
  assert.deepEqual([out.stickX, out.stickY], [100, 0]);
  out = g.mapGamepad(pad({ axes: [0.1, -0.1, 0, 0] }), m);  // inside the dead zone (|v| = 0.14)
  assert.deepEqual([out.stickX, out.stickY], [0, 0]);
  out = g.mapGamepad(pad({ axes: [0, 0, -1, 0] }), m);  // right stick left
  assert.deepEqual([out.cX, out.cY], [-100, 0]);
  out = g.mapGamepad(pad({ axes: [0, 0, 0, 1] }), m);   // right stick down
  assert.deepEqual([out.cX, out.cY], [0, -100]);
  out = g.mapGamepad(pad({ axes: [0, 0, -1, 1] }), m);  // a square pad's corner: clamped to the circle
  assert.deepEqual([out.cX, out.cY], [-71, -71]);
  // Diagonal: the magnitude is kept, not squared off.
  out = g.mapGamepad(pad({ axes: [Math.SQRT1_2, -Math.SQRT1_2, 0, 0] }), m);
  assert.ok(Math.abs(out.stickX - 71) <= 1 && Math.abs(out.stickY - 71) <= 1, JSON.stringify(out));
  // Just past the dead zone: small values, not a jump.
  out = g.mapGamepad(pad({ axes: [0.2, 0, 0, 0] }), m);
  assert.ok(out.stickX > 0 && out.stickX < 10, String(out.stickX));
  // Out-of-range or missing axes are harmless.
  out = g.mapGamepad({ buttons: [], axes: [NaN, 5] }, m);
  assert.deepEqual([out.stickX, out.stickY], [0, -100]);
});

test('custom mapping: axis sources for buttons and triggers, inverted axes', () => {
  const m = g.defaultMapping();
  m.buttons.UP = [{ type: 'axis', index: 7, dir: -1 }];   // a hat reported as an axis
  m.triggers.L = [{ type: 'axis', index: 4, dir: 1, full: true }];  // rests at -1
  m.axes.stickY = { index: 1, invert: false };
  const p = { buttons: [], axes: [0, 0.5, 0, 0, -1, 0, 0, -1] };
  let out = g.mapGamepad(p, m);
  assert.equal(out.buttons, PAD.UP);
  assert.equal(out.trigL, 0);
  assert.equal(out.stickY, Math.round(((0.5 - 0.15) / 0.85) * 100));
  p.axes[4] = 1;
  p.axes[7] = 0;
  out = g.mapGamepad(p, m);
  assert.equal(out.trigL, 255);
  assert.equal(out.buttons, PAD.L);
});

test('rebinding: the first new press or axis movement is detected', () => {
  const rest = g.snapshot(pad({ axes: [0, 0, 0, 0, -1] }));
  assert.equal(g.detectSource(rest, rest), null);
  assert.deepEqual(g.detectSource(rest, g.snapshot(pad({ pressed: [3] }))), { type: 'button', index: 3 });
  assert.deepEqual(g.detectSource(rest, g.snapshot(pad({ axes: [0, -0.9, 0, 0, -1] }))), { type: 'axis', index: 1, dir: -1 });
  assert.deepEqual(g.detectSource(rest, g.snapshot(pad({ axes: [0, 0, 0, 0, 1] }))),
                   { type: 'axis', index: 4, dir: 1, full: true });
  // A button already held when rebinding started is not a new press.
  const held = g.snapshot(pad({ pressed: [2] }));
  assert.equal(g.detectSource(held, held), null);
  assert.equal(g.describeSource({ type: 'button', index: 9 }), 'Start');
  assert.equal(g.describeSource({ type: 'axis', index: 2, dir: -1 }), 'axis 2 -');
});

test('storage: saved per browser, malformed entries fall back field by field', () => {
  const store = new Map();
  const storage = {
    getItem: (k) => (store.has(k) ? store.get(k) : null),
    setItem: (k, v) => store.set(k, v),
    removeItem: (k) => store.delete(k),
  };
  assert.deepEqual(g.loadMapping(storage), g.defaultMapping());
  const m = g.defaultMapping();
  m.buttons.A = [{ type: 'button', index: 1 }];
  m.buttons.B = [{ type: 'button', index: 0 }];
  m.deadzone = 0.2;
  g.saveMapping(storage, m);
  assert.ok(store.has(g.STORAGE_KEY));
  assert.deepEqual(g.loadMapping(storage), m);
  // Damage: bad JSON, wrong version, bad fields.
  store.set(g.STORAGE_KEY, '{nope');
  assert.deepEqual(g.loadMapping(storage), g.defaultMapping());
  store.set(g.STORAGE_KEY, JSON.stringify({ ...m, version: 2 }));
  assert.deepEqual(g.loadMapping(storage), g.defaultMapping());
  store.set(g.STORAGE_KEY, JSON.stringify({ ...m, buttons: { ...m.buttons, X: [{ type: 'button', index: -1 }] },
                                             deadzone: 5 }));
  const loaded = g.loadMapping(storage);
  assert.deepEqual(loaded.buttons.A, [{ type: 'button', index: 1 }]);  // kept
  assert.deepEqual(loaded.buttons.X, g.defaultMapping().buttons.X);    // fell back
  assert.equal(loaded.deadzone, g.defaultMapping().deadzone);
  assert.deepEqual(g.resetMapping(storage), g.defaultMapping());
  assert.ok(!store.has(g.STORAGE_KEY));
  // No storage at all (private mode): defaults, no throw.
  assert.deepEqual(g.loadMapping(null), g.defaultMapping());
  const throwing = { getItem() { throw new Error('denied'); }, setItem() { throw new Error('denied'); },
                     removeItem() { throw new Error('denied'); } };
  assert.deepEqual(g.loadMapping(throwing), g.defaultMapping());
  g.saveMapping(throwing, m);
});
