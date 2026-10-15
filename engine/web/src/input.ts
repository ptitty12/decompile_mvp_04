// Host input for port 1: the keyboard and the first connected gamepad (Gamepad
// API, main thread only), merged into one GameCube pad. The Worker applies the
// latest state at the game's next frame poll (runtime/input.h, E0c-IN1): input
// enters guest state only there, once per frame.
//
// Keyboard: Enter = START, X = A, Z = B, C = X, V = Y, arrows = D-pad,
// I/J/K/L = main stick, Q = L, E = R, Space = Z.
// Gamepad: the mapping in gamepad.ts (standard layout by default, rebindable,
// stored per browser).

import { PAD, loadMapping, mapGamepad, saveMapping, type GamepadLike, type GamepadMapping } from './gamepad.js';
import type { Pad } from './protocol.js';

export { PAD };

const KEYS: Record<string, number> = {
  Enter: PAD.START, KeyX: PAD.A, KeyZ: PAD.B, KeyC: PAD.X, KeyV: PAD.Y,
  ArrowUp: PAD.UP, ArrowDown: PAD.DOWN, ArrowLeft: PAD.LEFT, ArrowRight: PAD.RIGHT,
  KeyQ: PAD.L, KeyE: PAD.R, Space: PAD.Z,
};
const STICK_KEYS: Record<string, [number, number]> = {
  KeyI: [0, 1], KeyK: [0, -1], KeyJ: [-1, 0], KeyL: [1, 0],
};
const STICK_RANGE = 100;  // the pad's usual reach after origin correction

function storage(): Storage | null {
  try {
    return window.localStorage;
  } catch {
    return null;
  }
}

export class HostInput {
  private keys = new Set<string>();
  private last = '';
  private mappingValue: GamepadMapping = loadMapping(storage());
  // The pad last read (for the controller panel), and whether the remapping UI
  // holds the gamepad (it reads the raw pad itself meanwhile).
  gamepad: Gamepad | null = null;
  capture = false;

  constructor(target: EventTarget, private readonly onChange: (pad: Pad) => void) {
    target.addEventListener('keydown', (e) => this.key(e as KeyboardEvent, true));
    target.addEventListener('keyup', (e) => this.key(e as KeyboardEvent, false));
    target.addEventListener('blur', () => this.keys.clear());
  }

  get mapping(): GamepadMapping {
    return this.mappingValue;
  }

  set mapping(m: GamepadMapping) {
    this.mappingValue = m;
    saveMapping(storage(), m);
  }

  private key(e: KeyboardEvent, down: boolean): void {
    if (!(e.code in KEYS) && !(e.code in STICK_KEYS)) return;
    if (e.target instanceof HTMLInputElement || e.target instanceof HTMLSelectElement ||
        e.target instanceof HTMLButtonElement) return;
    e.preventDefault();
    if (down) this.keys.add(e.code);
    else this.keys.delete(e.code);
    this.poll();
  }

  // The first connected gamepad (getGamepads() has holes for unplugged ones).
  static firstGamepad(): Gamepad | null {
    if (typeof navigator.getGamepads !== 'function') return null;
    try {
      return navigator.getGamepads().find((g) => g && g.connected !== false) ?? null;
    } catch {
      return null;  // a permissions policy can forbid the Gamepad API
    }
  }

  // Called on every animation frame (gamepads have no events for buttons).
  poll(): void {
    const pad: Pad = { connected: true, buttons: 0, stickX: 0, stickY: 0, cX: 0, cY: 0, trigL: 0, trigR: 0 };
    for (const k of this.keys) {
      if (k in KEYS) pad.buttons |= KEYS[k];
      if (k in STICK_KEYS) {
        pad.stickX += STICK_KEYS[k][0] * STICK_RANGE;
        pad.stickY += STICK_KEYS[k][1] * STICK_RANGE;
      }
    }
    if (pad.buttons & PAD.L) pad.trigL = 255;
    if (pad.buttons & PAD.R) pad.trigR = 255;
    this.gamepad = HostInput.firstGamepad();
    if (this.gamepad && !this.capture) {
      const g = mapGamepad(this.gamepad as GamepadLike, this.mappingValue);
      pad.buttons |= g.buttons;
      pad.trigL = Math.max(pad.trigL, g.trigL);
      pad.trigR = Math.max(pad.trigR, g.trigR);
      pad.stickX += g.stickX;
      pad.stickY += g.stickY;
      pad.cX += g.cX;
      pad.cY += g.cY;
    }
    const clamp = (x: number) => Math.max(-128, Math.min(127, x));
    pad.stickX = clamp(pad.stickX);
    pad.stickY = clamp(pad.stickY);
    pad.cX = clamp(pad.cX);
    pad.cY = clamp(pad.cY);
    const key = JSON.stringify(pad);
    if (key !== this.last) {
      this.last = key;
      this.onChange(pad);
    }
  }
}
