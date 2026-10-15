// The keyboard as a GameCube pad (Q3): the default keys, rebinding with conflict
// handling, the stored form, and the mapping from the held keys to the pad.
// Keys are KeyboardEvent.code values (physical positions, not letters), so the
// default layout works on every keyboard language; labels use the browser's
// layout map where it has one. Pure functions; tests/controls.test.mjs.
//
// Default keys (E2, unchanged): Enter = START, X = A, Z = B, C = X, V = Y,
// arrows = D-pad, I/J/K/L = main stick, Q = L, E = R, Space = Z. New in Q3: the
// C-stick on the numeric keypad (8/4/2/6), and every key can be changed.

import { PAD, type PadPart } from './gamepad.js';

export type KeyAction =
  | 'A' | 'B' | 'X' | 'Y' | 'Z' | 'START' | 'UP' | 'DOWN' | 'LEFT' | 'RIGHT' | 'L' | 'R'
  | 'stickUp' | 'stickDown' | 'stickLeft' | 'stickRight' | 'cUp' | 'cDown' | 'cLeft' | 'cRight';

export const KEY_ACTIONS: readonly KeyAction[] = [
  'A', 'B', 'X', 'Y', 'Z', 'START', 'L', 'R', 'UP', 'DOWN', 'LEFT', 'RIGHT',
  'stickUp', 'stickDown', 'stickLeft', 'stickRight', 'cUp', 'cDown', 'cLeft', 'cRight',
];

export const KEY_ACTION_LABELS: Record<KeyAction, string> = {
  A: 'A button', B: 'B button', X: 'X button', Y: 'Y button', Z: 'Z button', START: 'START', L: 'L trigger (full press)',
  R: 'R trigger (full press)', UP: 'D-pad up', DOWN: 'D-pad down', LEFT: 'D-pad left', RIGHT: 'D-pad right',
  stickUp: 'Main stick up', stickDown: 'Main stick down', stickLeft: 'Main stick left', stickRight: 'Main stick right',
  cUp: 'C-stick up', cDown: 'C-stick down', cLeft: 'C-stick left', cRight: 'C-stick right',
};

export type KeyMap = Record<KeyAction, string[]>;

export function defaultKeyMap(): KeyMap {
  return {
    A: ['KeyX'], B: ['KeyZ'], X: ['KeyC'], Y: ['KeyV'], Z: ['Space'], START: ['Enter'], L: ['KeyQ'], R: ['KeyE'],
    UP: ['ArrowUp'], DOWN: ['ArrowDown'], LEFT: ['ArrowLeft'], RIGHT: ['ArrowRight'],
    stickUp: ['KeyI'], stickDown: ['KeyK'], stickLeft: ['KeyJ'], stickRight: ['KeyL'],
    cUp: ['Numpad8'], cDown: ['Numpad2'], cLeft: ['Numpad4'], cRight: ['Numpad6'],
  };
}

const BUTTON_BITS: Partial<Record<KeyAction, number>> = {
  A: PAD.A, B: PAD.B, X: PAD.X, Y: PAD.Y, Z: PAD.Z, START: PAD.START,
  UP: PAD.UP, DOWN: PAD.DOWN, LEFT: PAD.LEFT, RIGHT: PAD.RIGHT, L: PAD.L, R: PAD.R,
};

// The keys the page itself uses (F fullscreen, M sound, P pause), and keys a
// page cannot take from the browser or that would be a trap.
const RESERVED = new Set(['KeyF', 'KeyM', 'KeyP', 'Escape', 'Tab', 'ContextMenu', 'MetaLeft', 'MetaRight', 'OS',
                          'ControlLeft', 'ControlRight', 'AltLeft', 'AltRight', 'PrintScreen', 'CapsLock',
                          'NumLock', 'ScrollLock', 'Pause', 'Insert', 'Delete', 'Home', 'End', 'PageUp', 'PageDown']);

export function bindable(code: string): { ok: true } | { ok: false; why: string } {
  if (!/^[A-Za-z0-9]{1,24}$/.test(code)) return { ok: false, why: 'that key cannot be used' };
  if (code === 'KeyF' || code === 'KeyM' || code === 'KeyP') {
    return { ok: false, why: `${code.slice(3)} is the page's own key (fullscreen, sound, pause)` };
  }
  if (code === 'Escape') return { ok: false, why: 'Escape cancels' };
  if (RESERVED.has(code) || /^F\d{1,2}$/.test(code)) return { ok: false, why: 'the browser keeps that key' };
  return { ok: true };
}

export function keyCodes(map: KeyMap): Set<string> {
  const s = new Set<string>();
  for (const a of KEY_ACTIONS) for (const c of map[a]) s.add(c);
  return s;
}

// The held keys as a pad part. Opposite stick keys cancel; both axes at once
// are limited to the gate's diagonal notch, the same distance as one axis.
export function keysToPad(held: ReadonlySet<string>, map: KeyMap, range = 100): PadPart {
  const out: PadPart = { buttons: 0, stickX: 0, stickY: 0, cX: 0, cY: 0, trigL: 0, trigR: 0 };
  const down = (a: KeyAction) => map[a].some((c) => held.has(c));
  for (const a of KEY_ACTIONS) {
    const bit = BUTTON_BITS[a];
    if (bit && down(a)) out.buttons |= bit;
  }
  if (out.buttons & PAD.L) out.trigL = 255;
  if (out.buttons & PAD.R) out.trigR = 255;
  const axis = (neg: KeyAction, pos: KeyAction): number => (down(pos) ? 1 : 0) - (down(neg) ? 1 : 0);
  const sx = axis('stickLeft', 'stickRight'), sy = axis('stickDown', 'stickUp');
  const cx = axis('cLeft', 'cRight'), cy = axis('cDown', 'cUp');
  const k = (x: number, y: number) => (x !== 0 && y !== 0 ? range * Math.SQRT1_2 : range);
  out.stickX = Math.round(sx * k(sx, sy));
  out.stickY = Math.round(sy * k(sx, sy));
  out.cX = Math.round(cx * k(cx, cy));
  out.cY = Math.round(cy * k(cx, cy));
  return out;
}

export interface Rebound {
  map: KeyMap;
  swapped: KeyAction[];  // other actions that had the key (they got this action's old key, or none)
}

// Gives `action` the key `code`. An action that already had the key swaps with
// it, so no key does two things and nothing is silently left without a key.
export function rebindKey(map: KeyMap, action: KeyAction, code: string): Rebound | { error: string } {
  const check = bindable(code);
  if (!check.ok) return { error: check.why };
  const next = structuredClone(map);
  const old = next[action][0];
  const swapped: KeyAction[] = [];
  for (const a of KEY_ACTIONS) {
    if (a === action || !next[a].includes(code)) continue;
    swapped.push(a);
    next[a] = next[a].filter((c) => c !== code);
    if (old && old !== code) next[a].push(old);
  }
  next[action] = [code];
  return { map: next, swapped };
}

export function resetKey(map: KeyMap, action: KeyAction): KeyMap {
  const next = structuredClone(map);
  next[action] = defaultKeyMap()[action];
  return next;
}

// A stored key map, checked: anything wrong (not an object, a bad code, one key
// on two actions, an action without keys) gives the default for the whole map.
export function parseKeyMap(v: unknown): KeyMap {
  const d = defaultKeyMap();
  if (!v || typeof v !== 'object') return d;
  const o = v as Record<string, unknown>;
  const m = {} as KeyMap;
  const seen = new Set<string>();
  for (const a of KEY_ACTIONS) {
    const list = o[a];
    if (!Array.isArray(list) || list.length < 1 || list.length > 3) return d;
    for (const c of list) {
      if (typeof c !== 'string' || !bindable(c).ok || seen.has(c)) return d;
      seen.add(c);
    }
    m[a] = [...list] as string[];
  }
  return m;
}

// A readable name for a key code. `layout` is the browser's KeyboardLayoutMap
// (navigator.keyboard.getLayoutMap(): code -> the character the key types).
export function keyLabel(code: string, layout?: { get(code: string): string | undefined } | null): string {
  const typed = layout?.get(code);
  if (typed && typed.length === 1) return typed.toUpperCase();
  let m: RegExpExecArray | null;
  if ((m = /^Key([A-Z])$/.exec(code))) return m[1];
  if ((m = /^Digit(\d)$/.exec(code))) return m[1];
  if ((m = /^Numpad(\d)$/.exec(code))) return `Numpad ${m[1]}`;
  if ((m = /^Arrow(Up|Down|Left|Right)$/.exec(code))) return `${m[1]} arrow`;
  if ((m = /^(Shift|Control|Alt|Meta)(Left|Right)$/.exec(code))) return `${m[2]} ${m[1]}`;
  const names: Record<string, string> = {
    Space: 'Space', Enter: 'Enter', Backspace: 'Backspace', Comma: ',', Period: '.', Slash: '/', Semicolon: ';',
    Quote: "'", BracketLeft: '[', BracketRight: ']', Backslash: '\\', Minus: '-', Equal: '=', Backquote: '`',
    NumpadAdd: 'Numpad +', NumpadSubtract: 'Numpad -', NumpadMultiply: 'Numpad *', NumpadDivide: 'Numpad /',
    NumpadEnter: 'Numpad Enter', NumpadDecimal: 'Numpad .',
  };
  return names[code] ?? code;
}

// ---- storage ----

export function sameKeyMap(a: KeyMap, b: KeyMap): boolean {
  return KEY_ACTIONS.every((k) => a[k].length === b[k].length && a[k].every((c, i) => c === b[k][i]));
}
