// Controller identification and built-in profiles (Q3): what a browser's
// Gamepad object is (its id string), and the GameCube mapping to start from.
//
// The Gamepad API gives `mapping === "standard"` to the controllers the browser
// recognises (Xbox, PlayStation, Switch Pro and many others in Chrome and
// Edge; fewer in Firefox and Safari): the same button positions on every one.
// Everything else has mapping "" and raw button/axis numbers that depend on the
// pad, the OS and the browser. For those this file has:
//   - the profiles whose raw layout is well known (the Linux/Firefox layout of
//     Xbox pads), and
//   - a generic guess that makes the menus usable, plus the knowledge that the
//     pad needs the guided setup (controls.ts: "Set up this controller").
// GameCube controllers on USB adapters (Mayflash and similar) are recognised
// by name and vendor and offered the guided setup: their raw layouts differ
// between adapter firmware, modes, OSes and browsers, and a wrong built-in
// guess is worse than pressing each control once.
//
// Pure functions over strings and numbers; tests/controls.test.mjs covers them.

import { defaultMapping, type GamepadMapping, type Source } from './gamepad.js';

// What identifies a pad: the Gamepad's id, its mapping and the sizes of its arrays.
export interface PadInfo {
  id: string;
  mapping: string;
  nButtons: number;
  nAxes: number;
}

export type Family = 'xbox' | 'playstation' | 'nintendo' | 'gamecube' | 'generic';

export interface Ident {
  vendor: string | null;   // 4 lowercase hex digits
  product: string | null;
  name: string;            // the id without the vendor/product decoration
}

const hex4 = (h: string) => h.toLowerCase().padStart(4, '0');

// Chrome, Edge and Safari: "Name (STANDARD GAMEPAD Vendor: 054c Product: 09cc)" or
// "Name (Vendor: 0079 Product: 1843)"; Firefox: "054c-09cc-Name" (the ids are
// hex without a prefix; Firefox on Windows may drop leading zeros).
export function parseId(id: string): Ident {
  let vendor: string | null = null, product: string | null = null;
  let name = id;
  const chrome = /Vendor:\s*([0-9a-fA-F]{1,4})\s+Product:\s*([0-9a-fA-F]{1,4})/.exec(id);
  const firefox = /^([0-9a-fA-F]{1,4})-([0-9a-fA-F]{1,4})-(.+)$/.exec(id);
  if (chrome) {
    vendor = hex4(chrome[1]);
    product = hex4(chrome[2]);
    name = id.replace(/\(([^()]*?)\bVendor:[^()]*\)/, '').replace(/\s*\(\s*\)/, '');
  } else if (firefox) {
    vendor = hex4(firefox[1]);
    product = hex4(firefox[2]);
    name = firefox[3];
  }
  name = name.replace(/\((?:[^()]*\b)?STANDARD GAMEPAD\)/i, '').replace(/\(XInput[^)]*\)/i, '')
             .replace(/\s+/g, ' ').trim();
  return { vendor, product, name: name || 'Controller' };
}

export function friendlyName(info: PadInfo): string {
  return parseId(info.id).name;
}

// A key that names this model of pad across reloads and browsers where it can:
// the vendor and product ids, else the cleaned name and the array sizes. Two
// pads of one model share it (the n-th of a key is told apart by order).
export function deviceKey(info: PadInfo): string {
  const { vendor, product, name } = parseId(info.id);
  if (vendor && product) return `${vendor}:${product}`;
  return `${name.toLowerCase()}|${info.nButtons}b${info.nAxes}a`;
}

export function familyOf(info: PadInfo): Family {
  const { vendor, product, name } = parseId(info.id);
  const n = name.toLowerCase();
  // GameCube controller adapters: Nintendo's own (057e:0337), Mayflash's PC-mode
  // adapters (0079:1843, 0079:1844 and relatives) and anything that says so.
  if ((vendor === '057e' && product === '0337') || (vendor === '0079' && (product === '1843' || product === '1844')) ||
      /game\s?cube|\bngc\b|\bgc\b.*(adapter|controller)/.test(n)) return 'gamecube';
  if (vendor === '045e' || /xbox|x-box|xinput/.test(n) || /xinput/i.test(info.id)) return 'xbox';
  if (vendor === '054c' || /dualshock|dualsense|playstation|wireless controller/.test(n)) return 'playstation';
  if (vendor === '057e' || /nintendo|switch|joy-?con|pro controller/.test(n)) return 'nintendo';
  return 'generic';
}

const b = (index: number): Source => ({ type: 'button', index });
const ax = (index: number, dir: 1 | -1, full?: boolean): Source => (full ? { type: 'axis', index, dir, full } : { type: 'axis', index, dir });
const hat = (index: number, dir: 'up' | 'down' | 'left' | 'right'): Source => ({ type: 'hat', index, dir });

export interface Profile {
  id: string;
  label: string;
  // Whether the layout is a documented one (a browser's standard layout, or the
  // Linux joystick order of Xbox pads), so no guided setup is needed. Not a
  // claim of hardware testing: Q3_LOG.md says what was and was not tried.
  known: boolean;
  mapping: GamepadMapping;
}

// ---- the profiles ----

function standard(): Profile {
  return { id: 'standard', label: 'Standard layout', known: true, mapping: defaultMapping() };
}

// Nintendo's pads label the buttons by name, not position: their A is the right
// button, B the bottom one, X the top one, Y the left. A GameCube A on the
// Switch Pro's A feels right, so the standard layout's A/B and X/Y swap.
function nintendoStandard(): Profile {
  const m = defaultMapping();
  m.buttons.A = [b(1)];
  m.buttons.B = [b(0)];
  m.buttons.X = [b(3)];
  m.buttons.Y = [b(2)];
  return { id: 'standard-nintendo', label: 'Standard layout, Nintendo button names', known: true, mapping: m };
}

// Xbox 360/One pads where the browser does not apply the standard mapping
// (Firefox on Linux, older Chrome): the Linux joystick order. Triggers are axes
// 2 and 5 resting at -1; the D-pad is axes 6 and 7.
function xboxRaw(): Profile {
  const m = defaultMapping();
  m.buttons = {
    A: [b(0)], B: [b(1)], X: [b(2)], Y: [b(3)], Z: [b(5), b(4)], START: [b(7)],
    UP: [ax(7, -1)], DOWN: [ax(7, 1)], LEFT: [ax(6, -1)], RIGHT: [ax(6, 1)],
  };
  m.triggers = { L: [ax(2, 1, true)], R: [ax(5, 1, true)] };
  m.axes = {
    stickX: { index: 0, invert: false }, stickY: { index: 1, invert: true },
    cX: { index: 3, invert: false }, cY: { index: 4, invert: true },
  };
  return { id: 'xbox-raw', label: 'Xbox pad, raw (Linux joystick order)', known: true, mapping: m };
}

// A guess for a pad that is not recognised, enough to find the menus:
// the first four buttons as A B X Y, a D-pad on buttons 12-15 or on the hat axis
// Chrome uses (axis 9), two sticks on axes 0-3, bumpers as L and R.
function generic(): Profile {
  const m = defaultMapping();
  m.buttons = {
    A: [b(0)], B: [b(1)], X: [b(2)], Y: [b(3)], Z: [b(6)], START: [b(7)],
    UP: [b(12), hat(9, 'up')], DOWN: [b(13), hat(9, 'down')], LEFT: [b(14), hat(9, 'left')], RIGHT: [b(15), hat(9, 'right')],
  };
  m.triggers = { L: [b(4)], R: [b(5)] };
  m.axes = {
    stickX: { index: 0, invert: false }, stickY: { index: 1, invert: true },
    cX: { index: 2, invert: false }, cY: { index: 3, invert: true },
  };
  return { id: 'generic', label: 'Unrecognised layout (a guess)', known: false, mapping: m };
}

function gamecubeAdapter(): Profile {
  const p = generic();
  return { ...p, id: 'gamecube-adapter', label: 'GameCube adapter (set it up once)' };
}

// The profile to start from for this pad.
export function profileFor(info: PadInfo): Profile {
  const family = familyOf(info);
  const { vendor } = parseId(info.id);
  if (info.mapping === 'standard') return vendor === '057e' || family === 'nintendo' ? nintendoStandard() : standard();
  if (family === 'xbox') return xboxRaw();
  if (family === 'gamecube') return gamecubeAdapter();
  return generic();
}

// Whether the panel should offer the guided setup first: not a standard layout
// and not a layout we know.
export function needsSetup(info: PadInfo): boolean {
  return !profileFor(info).known;
}
