// Host input (E2, E2c, Q3): the keyboard and the connected gamepads (Gamepad
// API, main thread only), merged into one GameCube pad per port (pad-manager.ts
// decides which pad drives which port). The Worker applies the latest state at
// the game's next frame poll (runtime/input.h, E0c-IN1): input enters guest state
// only there, once per frame. Nothing here talks to the engine except `onChange`,
// which the page turns into a `pad` message.
//
// Keyboard: Enter = START, X = A, Z = B, C = X, V = Y, arrows = D-pad, I/J/K/L =
// main stick, numeric keypad 8/4/2/6 = C-stick, Q = L, E = R, Space = Z (all
// changeable in the Controls panel: controls-keys.ts).
// Gamepads: the profile and mapping per controller model (gamepad-profiles.ts,
// gamepad.ts), stored per browser (controls-store.ts).

import { PAD } from './gamepad.js';
import { keyCodes } from './controls-keys.js';
import { PORTS, loadConfig, saveConfig, type ControlsConfig } from './controls-store.js';
import { PadManager, type DeviceEvent, type PadSource } from './pad-manager.js';
import type { Pad } from './protocol.js';

export { PAD };

function storage(): Storage | null {
  try {
    return window.localStorage;
  } catch {
    return null;
  }
}

export class HostInput {
  readonly manager: PadManager;
  private readonly keys = new Set<string>();
  private bound: Set<string>;
  private last: string[] = Array.from({ length: PORTS }, () => '');
  private ownConfig: ControlsConfig;
  /** Counts changes of the settings (the panel redraws when it moves). */
  rev = 0;
  /** Device changes (a controller connected, claimed a port, left): the panel and the lobby listen. */
  onDevice: (e: DeviceEvent) => void = () => {};
  /** Every sample, after the ports changed or not (the panel's live test). */
  onSample: () => void = () => {};

  constructor(target: EventTarget, private readonly onChange: (pad: Pad, port: number) => void) {
    this.ownConfig = loadConfig(storage());
    this.bound = keyCodes(this.ownConfig.keys);
    this.manager = new PadManager(() => HostInput.gamepads(), this.ownConfig);
    this.manager.keys = this.keys;
    this.manager.onEvent = (e) => this.onDevice(e);
    target.addEventListener('keydown', (e) => this.key(e as KeyboardEvent, true));
    target.addEventListener('keyup', (e) => this.key(e as KeyboardEvent, false));
    target.addEventListener('blur', () => this.releaseKeys());
    document.addEventListener('visibilitychange', () => this.releaseKeys());
    // A button clicked with the mouse must not keep the keyboard: Enter and Space would press it
    // again, and the game's keys would be ignored until the player clicked the game.
    let pointerAt = -1e9;
    target.addEventListener('pointerdown', () => { pointerAt = performance.now(); }, true);
    target.addEventListener('click', (e) => {
      const t = e.target;
      if (t instanceof HTMLButtonElement && (e as MouseEvent).detail > 0) t.blur();
    }, true);
    target.addEventListener('change', (e) => {  // a choice made in a list with the mouse
      const t = e.target;
      if (t instanceof HTMLSelectElement && performance.now() - pointerAt < 4000) t.blur();
    }, true);
    // Chrome shows a pad only after its first press and tells the page with these.
    target.addEventListener('gamepadconnected', () => this.poll());
    target.addEventListener('gamepaddisconnected', () => this.poll());
  }

  get config(): ControlsConfig {
    return this.ownConfig;
  }

  /** Replaces the settings and stores them in this browser. */
  set config(c: ControlsConfig) {
    this.ownConfig = c;
    ++this.rev;
    this.manager.config = c;
    this.bound = keyCodes(c.keys);
    saveConfig(storage(), c);
  }

  /** The Controls panel is rebinding: neither pad nor keyboard reaches the game meanwhile. */
  get capture(): boolean {
    return this.manager.capture;
  }

  set capture(on: boolean) {
    this.manager.capture = on;
    if (on) this.releaseKeys();
  }

  /** Online (E5): only this page's player plays; the engine puts it on the player's port. */
  set online(on: boolean) {
    this.manager.online = on;
  }

  private releaseKeys(): void {
    if (this.keys.size === 0) return;
    this.keys.clear();
    this.poll();
  }

  private key(e: KeyboardEvent, down: boolean): void {
    if (!down) {  // a key that is let go is always let go, whatever has the focus now
      if (this.keys.delete(e.code)) this.poll();
      return;
    }
    if (this.manager.capture || !this.bound.has(e.code)) return;
    if (e.target instanceof HTMLInputElement || e.target instanceof HTMLSelectElement ||
        e.target instanceof HTMLButtonElement || e.target instanceof HTMLTextAreaElement) return;
    if (e.ctrlKey || e.altKey || e.metaKey) return;  // browser shortcuts (Ctrl+C, Alt+Left)
    e.preventDefault();
    this.keys.add(e.code);
    this.poll();
  }

  // The connected gamepads (getGamepads() has holes for unplugged ones).
  static gamepads(): ArrayLike<PadSource | null> {
    if (typeof navigator.getGamepads !== 'function') return [];
    try {
      return navigator.getGamepads() as unknown as ArrayLike<PadSource | null>;
    } catch {
      return [];  // a permissions policy can forbid the Gamepad API
    }
  }

  // Called on every animation frame (gamepads have no events for buttons) and
  // when a key changes: reads the pads and reports each port whose pad changed.
  poll(): void {
    const ports = this.manager.sample();
    for (let p = 0; p < ports.length; ++p) {
      const key = JSON.stringify(ports[p]);
      if (key === this.last[p]) continue;
      this.last[p] = key;
      this.onChange(ports[p], p);
    }
    this.onSample();
  }
}
