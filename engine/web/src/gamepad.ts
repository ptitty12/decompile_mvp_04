// Gamepad mapping (E2c): a controller seen through the Gamepad API -> the
// GameCube pad's controls. Pure functions over plain data, so the mapping is
// unit-tested without a browser (tests/gamepad.test.mjs); input.ts polls the
// pads and merges the result with the keyboard.
//
// The default is for the Gamepad API's "standard" layout (an Xbox-style or
// PlayStation-style pad): bottom face button = A, right = B, left = X, top = Y,
// right bumper = Z (where Z sits on a GameCube pad), left bumper = Z as well,
// triggers = L/R (analog, with the digital click at the end of their travel),
// Start = START, D-pad, left stick = main stick, right stick = C-stick.
// Every control can be rebound (controls.ts); mappings are stored per browser and
// per controller (controls-store.ts). Q3 added: D-pads reported as one "hat" axis,
// the GameCube's octagonal gate for the sticks, and the profile/assignment layers
// in gamepad-profiles.ts, controls-store.ts and pad-manager.ts.

export const PAD = {
  LEFT: 0x0001, RIGHT: 0x0002, DOWN: 0x0004, UP: 0x0008, Z: 0x0010, R: 0x0020, L: 0x0040,
  A: 0x0100, B: 0x0200, X: 0x0400, Y: 0x0800, START: 0x1000,
} as const;

export type GcButton = 'A' | 'B' | 'X' | 'Y' | 'Z' | 'START' | 'UP' | 'DOWN' | 'LEFT' | 'RIGHT';
export const GC_BUTTONS: readonly GcButton[] = ['A', 'B', 'X', 'Y', 'Z', 'START', 'UP', 'DOWN', 'LEFT', 'RIGHT'];
export type GcTrigger = 'L' | 'R';
export type GcAxis = 'stickX' | 'stickY' | 'cX' | 'cY';
export const GC_AXES: readonly GcAxis[] = ['stickX', 'stickY', 'cX', 'cY'];

// Where a control's value comes from.
//   button: a button (pressed, or its analog value for triggers)
//   axis:   one direction of an axis (dir +1 or -1); `full`: the axis rests at
//           -dir and travels to +dir (triggers reported as axes)
//   hat:    one direction of a D-pad that the browser reports as a single axis
//           (eight steps of 2/7 from -1 = up, clockwise; neutral is beyond +-1)
export type HatDir = 'up' | 'down' | 'left' | 'right';
export type Source =
  | { type: 'button'; index: number }
  | { type: 'axis'; index: number; dir: 1 | -1; full?: boolean }
  | { type: 'hat'; index: number; dir: HatDir };

export interface AxisBinding {
  index: number;    // the gamepad axis
  invert: boolean;  // the Gamepad API's y grows downwards: up on the stick = -1
}

export interface GamepadMapping {
  version: 1;
  buttons: Record<GcButton, Source[]>;
  triggers: Record<GcTrigger, Source[]>;
  axes: Record<GcAxis, AxisBinding>;
  deadzone: number;       // radial, of the stick's travel (0..1)
  buttonThreshold: number; // an axis source counts as a pressed button past this
  triggerClick: number;   // the trigger's digital click (L/R bits) at this much travel
  stickRange: number;     // full stick travel in PADStatus units (the real pad reaches about +-100)
  octagon: boolean;       // shape the sticks like the GameCube's octagonal gate (see octagonScale)
}

// What a gamepad contributes to the pad (PADStatus terms).
export interface PadPart {
  buttons: number;
  stickX: number;
  stickY: number;
  cX: number;
  cY: number;
  trigL: number;  // 0..255
  trigR: number;
}

// The part of the Gamepad API's Gamepad this needs (tests pass plain objects).
export interface GamepadLike {
  id?: string;
  mapping?: string;
  connected?: boolean;
  buttons: ReadonlyArray<{ pressed: boolean; value: number } | undefined>;
  axes: ReadonlyArray<number>;
}

const b = (index: number): Source => ({ type: 'button', index });

export function defaultMapping(): GamepadMapping {
  return {
    version: 1,
    buttons: {
      A: [b(0)], B: [b(1)], X: [b(2)], Y: [b(3)], Z: [b(5), b(4)], START: [b(9)],
      UP: [b(12)], DOWN: [b(13)], LEFT: [b(14)], RIGHT: [b(15)],
    },
    triggers: { L: [b(6)], R: [b(7)] },
    axes: {
      stickX: { index: 0, invert: false }, stickY: { index: 1, invert: true },
      cX: { index: 2, invert: false }, cY: { index: 3, invert: true },
    },
    deadzone: 0.15,
    buttonThreshold: 0.5,
    triggerClick: 0.9,
    stickRange: 100,
    octagon: true,
  };
}

const clamp = (x: number, lo: number, hi: number) => (x < lo ? lo : x > hi ? hi : x);

// A source's value, 0..1. An analog button's value counts as it is (browsers
// set `pressed` on triggers early in their travel); a digital one is 0 or 1.
export function sourceValue(gp: GamepadLike, s: Source): number {
  if (s.type === 'button') {
    const btn = gp.buttons[s.index];
    if (!btn) return 0;
    const v = Number.isFinite(btn.value) ? clamp(btn.value, 0, 1) : 0;
    return v > 0 ? v : btn.pressed ? 1 : 0;
  }
  const a = gp.axes[s.index];
  if (a === undefined || Number.isNaN(a)) return 0;
  if (s.type === 'hat') return hatDirections(a).includes(s.dir) ? 1 : 0;
  const v = a * s.dir;
  return clamp(s.full ? (v + 1) / 2 : v, 0, 1);
}

// The directions a hat axis reports (none when neutral). Browsers give a hat as
// -1 (up), then 2/7 steps clockwise to 1 (up and left); at rest it is outside
// the range (1.2857 and 3.2857 are common).
const HAT: readonly (readonly HatDir[])[] = [
  ['up'], ['up', 'right'], ['right'], ['down', 'right'], ['down'], ['down', 'left'], ['left'], ['up', 'left'],
];
export function hatDirections(v: number): readonly HatDir[] {
  if (!(v >= -1.05 && v <= 1.05)) return [];  // also NaN
  return HAT[(Math.round((v + 1) * 3.5) + 8) % 8];
}

function pressed(gp: GamepadLike, s: Source, threshold: number): boolean {
  if (s.type === 'button') {
    const btn = gp.buttons[s.index];
    return !!btn && (btn.pressed || btn.value >= threshold);
  }
  return sourceValue(gp, s) >= threshold;
}

// The GameCube stick's gate is an octagon: eight notches (the four directions
// and the four diagonals) at the full distance, flat between them, so the rim
// at 22.5 degrees off a notch is cos(22.5 deg) = 92.4 % out. This is the
// distance of the gate's edge at the direction of (x, y), relative to a notch.
export function octagonScale(x: number, y: number): number {
  const a = Math.atan2(Math.abs(y), Math.abs(x));  // 0 .. pi/2
  const d = a % (Math.PI / 4);
  const phi = Math.min(d, Math.PI / 4 - d);        // distance from the nearest notch, 0 .. 22.5 deg
  return Math.cos(Math.PI / 8) / Math.cos(Math.PI / 8 - phi);
}

// One stick (input in -1..1, up positive after the binding's inversion):
// radial dead zone, the rest rescaled to the full range, optionally shaped to
// the octagon. The outputs are PADStatus units.
export function shapeStick(ax: number, ay: number, m: GamepadMapping): [number, number] {
  if (Number.isNaN(ax)) ax = 0;
  if (Number.isNaN(ay)) ay = 0;
  const mag = Math.hypot(ax, ay);
  if (mag <= m.deadzone || mag === 0) return [0, 0];
  const scaled = Math.min(1, (mag - m.deadzone) / (1 - m.deadzone));
  const k = (scaled / mag) * m.stickRange * (m.octagon ? octagonScale(ax, ay) : 1);
  return [clamp(Math.round(ax * k), -128, 127) || 0, clamp(Math.round(ay * k), -128, 127) || 0];  // no -0
}

function stick(gp: GamepadLike, x: AxisBinding, y: AxisBinding, m: GamepadMapping): [number, number] {
  let ax = gp.axes[x.index] ?? 0, ay = gp.axes[y.index] ?? 0;
  if (Number.isNaN(ax)) ax = 0;
  if (Number.isNaN(ay)) ay = 0;
  if (x.invert) ax = -ax;
  if (y.invert) ay = -ay;
  return shapeStick(ax, ay, m);
}

export function mapGamepad(gp: GamepadLike, m: GamepadMapping): PadPart {
  const out: PadPart = { buttons: 0, stickX: 0, stickY: 0, cX: 0, cY: 0, trigL: 0, trigR: 0 };
  for (const name of GC_BUTTONS)
    if (m.buttons[name].some((s) => pressed(gp, s, m.buttonThreshold))) out.buttons |= PAD[name];
  const trig = (t: GcTrigger) => m.triggers[t].reduce((v, s) => Math.max(v, sourceValue(gp, s)), 0);
  const l = trig('L'), r = trig('R');
  out.trigL = Math.round(l * 255);
  out.trigR = Math.round(r * 255);
  if (l >= m.triggerClick) out.buttons |= PAD.L;
  if (r >= m.triggerClick) out.buttons |= PAD.R;
  [out.stickX, out.stickY] = stick(gp, m.axes.stickX, m.axes.stickY, m);
  [out.cX, out.cY] = stick(gp, m.axes.cX, m.axes.cY, m);
  return out;
}

// ---- storage (per browser) ----

export const STORAGE_KEY = 'mvp.gamepad.mapping.v1';

export interface StorageLike {
  getItem(key: string): string | null;
  setItem(key: string, value: string): void;
  removeItem(key: string): void;
}

function validSource(s: unknown): s is Source {
  if (!s || typeof s !== 'object') return false;
  const o = s as Record<string, unknown>;
  if (!Number.isInteger(o.index) || (o.index as number) < 0 || (o.index as number) > 63) return false;
  if (o.type === 'button') return true;
  if (o.type === 'hat') return o.dir === 'up' || o.dir === 'down' || o.dir === 'left' || o.dir === 'right';
  return o.type === 'axis' && (o.dir === 1 || o.dir === -1) && (o.full === undefined || typeof o.full === 'boolean');
}

// A stored mapping, checked field by field; anything missing or malformed
// falls back to the default for that field.
export function parseMapping(text: string | null): GamepadMapping {
  if (!text) return defaultMapping();
  let o: unknown;
  try {
    o = JSON.parse(text);
  } catch {
    return defaultMapping();
  }
  return mappingFromObject(o);
}

// The same for an already parsed value (the per-controller store keeps them inside a bigger object).
export function mappingFromObject(value: unknown): GamepadMapping {
  const m = defaultMapping();
  const o = value as Record<string, unknown>;
  if (!o || typeof o !== 'object' || o.version !== 1) return m;
  const sources = (v: unknown, fallback: Source[]) =>
    Array.isArray(v) && v.length <= 4 && v.every(validSource) ? (v as Source[]).map((s) => ({ ...s })) : fallback;
  const buttons = (o.buttons ?? {}) as Record<string, unknown>;
  for (const name of GC_BUTTONS) m.buttons[name] = sources(buttons[name], m.buttons[name]);
  const triggers = (o.triggers ?? {}) as Record<string, unknown>;
  for (const t of ['L', 'R'] as const) m.triggers[t] = sources(triggers[t], m.triggers[t]);
  const axes = (o.axes ?? {}) as Record<string, unknown>;
  for (const a of GC_AXES) {
    const v = axes[a] as Record<string, unknown> | undefined;
    if (v && Number.isInteger(v.index) && (v.index as number) >= 0 && (v.index as number) < 16 && typeof v.invert === 'boolean')
      m.axes[a] = { index: v.index as number, invert: v.invert };
  }
  const num = (v: unknown, lo: number, hi: number, fallback: number) =>
    typeof v === 'number' && v >= lo && v <= hi ? v : fallback;
  m.deadzone = num(o.deadzone, 0, 0.9, m.deadzone);
  m.buttonThreshold = num(o.buttonThreshold, 0.05, 1, m.buttonThreshold);
  m.triggerClick = num(o.triggerClick, 0.05, 1, m.triggerClick);
  m.stickRange = num(o.stickRange, 10, 127, m.stickRange);
  if (typeof o.octagon === 'boolean') m.octagon = o.octagon;
  return m;
}

export function loadMapping(storage: StorageLike | null): GamepadMapping {
  try {
    return parseMapping(storage?.getItem(STORAGE_KEY) ?? null);
  } catch {
    return defaultMapping();
  }
}

export function saveMapping(storage: StorageLike | null, m: GamepadMapping): void {
  try {
    storage?.setItem(STORAGE_KEY, JSON.stringify(m));
  } catch {
    // private browsing or storage full: the mapping lasts until the page closes
  }
}

export function resetMapping(storage: StorageLike | null): GamepadMapping {
  try {
    storage?.removeItem(STORAGE_KEY);
  } catch {
    // as above
  }
  return defaultMapping();
}

// ---- rebinding ----

// What changed between two snapshots of a pad: the first button newly pressed,
// else the first axis that moved past `threshold` away from where it rested.
// Used by the remapping UI ("press the button for A").
export interface Snapshot {
  buttons: number[];  // values
  axes: number[];
}

export function snapshot(gp: GamepadLike): Snapshot {
  return {
    buttons: gp.buttons.map((x) => (x ? Math.max(x.pressed ? 1 : 0, x.value || 0) : 0)),
    axes: gp.axes.map((a) => (Number.isNaN(a) ? 0 : a)),
  };
}

export function detectSource(rest: Snapshot, now: Snapshot, threshold = 0.6): Source | null {
  for (let i = 0; i < now.buttons.length; ++i)
    if (now.buttons[i] >= 0.5 && (rest.buttons[i] ?? 0) < 0.5) return { type: 'button', index: i };
  for (let i = 0; i < now.axes.length; ++i) {
    const r = rest.axes[i] ?? 0, v = now.axes[i];
    // A hat: an axis that rests outside -1..1 and now reports a direction.
    if (hatDirections(r).length === 0 && Math.abs(r) > 1.05 && hatDirections(v).length > 0)
      return { type: 'hat', index: i, dir: hatDirections(v)[0] };
    if (Math.abs(r) > 1.05) continue;  // a hat at rest (or still between steps)
    if (Math.abs(v - r) < threshold) continue;
    const dir: 1 | -1 = v > r ? 1 : -1;
    // An axis that rests at one end (a trigger as an axis) travels its full range.
    return Math.abs(r) > 0.8 ? { type: 'axis', index: i, dir, full: true } : { type: 'axis', index: i, dir };
  }
  return null;
}

const STANDARD_NAMES = ['A / Cross', 'B / Circle', 'X / Square', 'Y / Triangle', 'LB / L1', 'RB / R1', 'LT / L2',
                        'RT / R2', 'Back / Select', 'Start', 'Left stick press', 'Right stick press', 'D-pad up',
                        'D-pad down', 'D-pad left', 'D-pad right', 'Home'];

export function describeSource(s: Source, standard = true): string {
  if (s.type === 'button') return standard && STANDARD_NAMES[s.index] ? STANDARD_NAMES[s.index] : `button ${s.index}`;
  if (s.type === 'hat') return `D-pad ${s.dir} (axis ${s.index})`;
  return `axis ${s.index} ${s.dir > 0 ? '+' : '-'}${s.full ? ' (full)' : ''}`;
}
