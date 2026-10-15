// The page's controllers as GameCube ports (Q3): which pads are connected
// (hot-plug), which has been used, which drives player 1 and player 2, and each
// port's pad built from the keyboard and that pad. Pure logic over a function
// that returns the Gamepad objects (navigator.getGamepads in the page, plain
// objects in the tests), so tests/controls.test.mjs covers it without a browser.
//
// Determinism: this only turns host input into PadState-shaped values on the
// main thread. They reach the guest solely through the engine's input queue at
// the frame poll (E0c-IN1); nothing here reads a clock or talks to the engine.
//
// Assignment (the Controls panel edits ControlsConfig.ports):
//   - a port set to a pad ("device") is driven by the n-th connected pad of that
//     model, whether or not it has been touched;
//   - a port on "auto" is taken by the first pad that is *used* (a button
//     pressed or a stick moved), then the next one; it keeps that pad while it
//     stays connected. So idle phantoms never take a port: a GameCube adapter
//     lists its four ports whether or not a controller sits in them, and
//     Firefox lists every pad it sees;
//   - the keyboard drives ControlsConfig.keyboardPort, merged with that
//     port's pad.

import { PAD, detectSource, mapGamepad, snapshot, type GamepadLike, type GamepadMapping, type PadPart, type Snapshot } from './gamepad.js';
import { friendlyName, deviceKey, profileFor, type PadInfo } from './gamepad-profiles.js';
import { keysToPad } from './controls-keys.js';
import { PORTS, storedMapping, type ControlsConfig } from './controls-store.js';
import type { Pad } from './protocol.js';

// What the page's pads look like to this code: a Gamepad.
export interface PadSource extends GamepadLike {
  index: number;
  id: string;
  mapping: string;
  vibrationActuator?: { playEffect?(type: string, params: Record<string, number>): Promise<unknown>; reset?(): Promise<unknown> } | null;
}

export interface Device {
  handle: string;     // index and id: unique among the connected pads
  index: number;
  id: string;
  key: string;        // deviceKey(): the model
  nth: number;        // among the connected pads of this model
  name: string;
  standard: boolean;
  nButtons: number;
  nAxes: number;
  profile: { id: string; label: string; known: boolean };
  custom: boolean;    // has its own stored mapping
  active: boolean;    // used since it appeared
  port: number;       // the port it drives, -1 none
  part: PadPart;      // its mapped controls now
  raw: PadSource;
}

export type DeviceEvent =
  | { kind: 'connected'; device: Device }
  | { kind: 'disconnected'; device: Device }
  | { kind: 'claimed'; device: Device; port: number };

const EMPTY: PadPart = { buttons: 0, stickX: 0, stickY: 0, cX: 0, cY: 0, trigL: 0, trigR: 0 };
const clamp8 = (x: number) => Math.max(-128, Math.min(127, x));

interface Track {
  handle: string;
  rest: Snapshot;
  active: boolean;
  seq: number;        // activation order
  device: Device;
}

export function mergeParts(a: PadPart, b: PadPart): PadPart {
  return {
    buttons: a.buttons | b.buttons,
    stickX: clamp8(a.stickX + b.stickX), stickY: clamp8(a.stickY + b.stickY),
    cX: clamp8(a.cX + b.cX), cY: clamp8(a.cY + b.cY),
    trigL: Math.max(a.trigL, b.trigL), trigR: Math.max(a.trigR, b.trigR),
  };
}

export function infoOf(g: PadSource): PadInfo {
  return { id: g.id ?? '', mapping: g.mapping ?? '', nButtons: g.buttons.length, nAxes: g.axes.length };
}

export class PadManager {
  config: ControlsConfig;
  /** Keyboard codes held now (the page's key handlers fill it). */
  keys: ReadonlySet<string> = new Set();
  /** While the Controls panel rebinds, neither pads nor keys reach the game. */
  capture = false;
  /** Online (E5): only this page's player, port 0 of the page, reaches the game. */
  online = false;
  onEvent: (e: DeviceEvent) => void = () => {};
  devices: Device[] = [];

  private tracks = new Map<string, Track>();
  private autoOwner = new Map<number, string>();  // port -> handle
  private seq = 0;

  constructor(private readonly getGamepads: () => ArrayLike<PadSource | null | undefined>, config: ControlsConfig) {
    this.config = config;
  }

  /** The mapping this pad uses: its stored one, else its profile's. */
  mappingFor(d: Pick<Device, 'key' | 'raw'>): GamepadMapping {
    return storedMapping(this.config, d.key) ?? profileFor(infoOf(d.raw)).mapping;
  }

  deviceAt(port: number): Device | null {
    return this.devices.find((d) => d.port === port) ?? null;
  }

  private list(): PadSource[] {
    let all: ArrayLike<PadSource | null | undefined>;
    try {
      all = this.getGamepads();
    } catch {
      return [];  // a permissions policy can forbid the Gamepad API
    }
    const out: PadSource[] = [];
    for (let i = 0; i < all.length; ++i) {
      const g = all[i];
      if (g && g.connected !== false) out.push(g);
    }
    return out.sort((a, b) => a.index - b.index);
  }

  /** Reads the pads and returns the PORTS ports' pads. Call once per animation frame. */
  sample(): Pad[] {
    const pads = this.list();
    const seen = new Set<string>();
    const perKey = new Map<string, number>();
    const next: Device[] = [];
    for (const g of pads) {
      const info = infoOf(g);
      const handle = `${g.index}:${g.id}`;
      seen.add(handle);
      const key = deviceKey(info);
      const nth = perKey.get(key) ?? 0;
      perKey.set(key, nth + 1);
      const profile = profileFor(info);
      let t = this.tracks.get(handle);
      const fresh = !t;
      if (!t) {
        const snap = snapshot(g);
        t = { handle, rest: snap, active: snap.buttons.some((v) => v >= 0.5), seq: 0, device: undefined as unknown as Device };
        if (t.active) t.seq = ++this.seq;
        this.tracks.set(handle, t);
      } else if (!t.active) {
        if (detectSource(t.rest, snapshot(g), 0.5)) {
          t.active = true;
          t.seq = ++this.seq;
        }
      }
      const d: Device = {
        handle, index: g.index, id: g.id, key, nth, name: friendlyName(info), standard: g.mapping === 'standard',
        nButtons: info.nButtons, nAxes: info.nAxes, profile: { id: profile.id, label: profile.label, known: profile.known },
        custom: this.config.devices[key] !== undefined, active: t.active, port: -1, part: EMPTY, raw: g,
      };
      t.device = d;
      d.part = mapGamepad(g, this.mappingFor(d));
      next.push(d);
      if (fresh) this.onEvent({ kind: 'connected', device: d });
    }
    for (const [handle, t] of this.tracks) {
      if (seen.has(handle)) continue;
      this.tracks.delete(handle);
      this.onEvent({ kind: 'disconnected', device: t.device });
    }
    this.devices = next;
    this.assign();
    return this.ports();
  }

  private assign(): void {
    const byHandle = new Map(this.devices.map((d) => [d.handle, d]));
    const taken = new Set<string>();
    const manual = new Map<number, Device>();
    for (let p = 0; p < PORTS; ++p) {
      const a = this.config.ports[p];
      if (a?.mode !== 'device') continue;
      const dev = this.devices.find((d) => d.key === a.key && d.nth === a.nth);
      if (dev && !taken.has(dev.handle)) {
        manual.set(p, dev);
        taken.add(dev.handle);
      }
    }
    const isAuto = (p: number) => (this.config.ports[p]?.mode ?? 'auto') === 'auto';
    for (const [p, handle] of [...this.autoOwner]) {
      if (!isAuto(p) || !byHandle.has(handle) || taken.has(handle)) this.autoOwner.delete(p);
      else taken.add(handle);
    }
    const claimants = this.devices.filter((d) => d.active && !taken.has(d.handle))
      .sort((a, b) => this.tracks.get(a.handle)!.seq - this.tracks.get(b.handle)!.seq);
    for (const d of claimants) {
      let port = -1;
      for (let p = 0; p < PORTS; ++p) if (isAuto(p) && !this.autoOwner.has(p)) { port = p; break; }
      if (port < 0) break;
      this.autoOwner.set(port, d.handle);
      this.onEvent({ kind: 'claimed', device: d, port });
    }
    for (const [p, dev] of manual) dev.port = p;
    for (const [p, handle] of this.autoOwner) {
      const d = byHandle.get(handle);
      if (d) d.port = p;
    }
  }

  /** The pad that plays this page's game: player 1's, else (online) whichever port has one. */
  localDevice(): Device | null {
    return this.deviceAt(0) ?? (this.online ? this.deviceAt(1) : null);
  }

  private ports(): Pad[] {
    const kb = this.capture ? EMPTY : keysToPad(this.keys, this.config.keys);
    const toPad = (connected: boolean, part: PadPart): Pad => connected
      ? { connected, buttons: part.buttons & 0x1F7F, stickX: part.stickX, stickY: part.stickY, cX: part.cX, cY: part.cY,
          trigL: part.trigL, trigR: part.trigR }
      : { connected: false, buttons: 0, stickX: 0, stickY: 0, cX: 0, cY: 0, trigL: 0, trigR: 0 };
    const out: Pad[] = [];
    if (this.online) {
      // E5: this page plays one player; the engine puts port 0 of the page on its player's port.
      const d = this.localDevice();
      let part = this.config.keyboardPort >= 0 ? kb : EMPTY;
      if (d && !this.capture) part = mergeParts(part, d.part);
      out.push(toPad(true, part));
      for (let p = 1; p < PORTS; ++p) out.push(toPad(false, EMPTY));
      return out;
    }
    for (let p = 0; p < PORTS; ++p) {
      let part = this.config.keyboardPort === p ? kb : EMPTY;
      const d = this.deviceAt(p);
      if (d && !this.capture) part = mergeParts(part, d.part);
      // Port 1 is always plugged in (the keyboard works before any pad is touched);
      // player 2 only while a pad or the keyboard is on it.
      out.push(toPad(p === 0 || d !== null || this.config.keyboardPort === p, part));
    }
    return out;
  }

  /** Whether any pad's A or START is down (the page's own "press A to play"). */
  confirmPressed(): boolean {
    return this.devices.some((d) => d.active && (d.part.buttons & (PAD.A | PAD.START)) !== 0);
  }
}
