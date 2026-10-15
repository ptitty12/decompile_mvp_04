// Host input for port 1: the keyboard and the first gamepad (Gamepad API, main
// thread only), merged into one GameCube pad. The Worker applies the latest
// state at the game's next frame poll (runtime/input.h): input enters guest
// state only there, once per frame.
//
// Keyboard: Enter = START, X = A, Z = B, C = X, V = Y, arrows = D-pad,
// I/J/K/L = main stick, Q = L, E = R, Space = Z.
// Gamepad ("standard" mapping): A/B/X/Y, Start, D-pad, sticks, LB = Z,
// LT/RT = L/R (analog).

import type { Pad } from './protocol.js';

export const PAD = {
  LEFT: 0x0001, RIGHT: 0x0002, DOWN: 0x0004, UP: 0x0008, Z: 0x0010, R: 0x0020, L: 0x0040,
  A: 0x0100, B: 0x0200, X: 0x0400, Y: 0x0800, START: 0x1000,
} as const;

const KEYS: Record<string, number> = {
  Enter: PAD.START, KeyX: PAD.A, KeyZ: PAD.B, KeyC: PAD.X, KeyV: PAD.Y,
  ArrowUp: PAD.UP, ArrowDown: PAD.DOWN, ArrowLeft: PAD.LEFT, ArrowRight: PAD.RIGHT,
  KeyQ: PAD.L, KeyE: PAD.R, Space: PAD.Z,
};
const STICK_KEYS: Record<string, [number, number]> = {
  KeyI: [0, 1], KeyK: [0, -1], KeyJ: [-1, 0], KeyL: [1, 0],
};
const STICK_RANGE = 100;  // the pad's usual reach after origin correction

export class HostInput {
  private keys = new Set<string>();
  private last = '';

  constructor(target: EventTarget, private readonly onChange: (pad: Pad) => void) {
    target.addEventListener('keydown', (e) => this.key(e as KeyboardEvent, true));
    target.addEventListener('keyup', (e) => this.key(e as KeyboardEvent, false));
    target.addEventListener('blur', () => this.keys.clear());
  }

  private key(e: KeyboardEvent, down: boolean): void {
    if (!(e.code in KEYS) && !(e.code in STICK_KEYS)) return;
    e.preventDefault();
    if (down) this.keys.add(e.code);
    else this.keys.delete(e.code);
    this.poll();
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
    const gp = typeof navigator.getGamepads === 'function' ? navigator.getGamepads().find((g) => g) : null;
    if (gp) {
      const b = (i: number) => gp.buttons[i]?.pressed ?? false;
      const v = (i: number) => gp.buttons[i]?.value ?? 0;
      const axis = (i: number) => {
        const a = gp.axes[i] ?? 0;
        return Math.abs(a) < 0.15 ? 0 : a;  // dead zone
      };
      if (b(0)) pad.buttons |= PAD.A;
      if (b(1)) pad.buttons |= PAD.B;
      if (b(2)) pad.buttons |= PAD.X;
      if (b(3)) pad.buttons |= PAD.Y;
      if (b(4)) pad.buttons |= PAD.Z;
      if (b(9)) pad.buttons |= PAD.START;
      if (b(12)) pad.buttons |= PAD.UP;
      if (b(13)) pad.buttons |= PAD.DOWN;
      if (b(14)) pad.buttons |= PAD.LEFT;
      if (b(15)) pad.buttons |= PAD.RIGHT;
      pad.trigL = Math.max(pad.trigL, Math.round(v(6) * 255));
      pad.trigR = Math.max(pad.trigR, Math.round(v(7) * 255));
      if (v(6) > 0.9) pad.buttons |= PAD.L;
      if (v(7) > 0.9) pad.buttons |= PAD.R;
      pad.stickX += Math.round(axis(0) * STICK_RANGE);
      pad.stickY -= Math.round(axis(1) * STICK_RANGE);  // the Gamepad API's y grows downwards
      pad.cX += Math.round(axis(2) * STICK_RANGE);
      pad.cY -= Math.round(axis(3) * STICK_RANGE);
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
