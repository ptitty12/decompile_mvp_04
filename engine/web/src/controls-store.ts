// What the Controls panel keeps per browser (Q3): each controller model's
// mapping and settings, which controller drives which port, which port the
// keyboard drives, the keyboard keys, and the vibration switch. One JSON value
// in localStorage (`mvp.controls.v2`), read field by field: anything missing or
// malformed falls back to the default for that field, and a browser without
// storage (private mode) just keeps the choices until the page closes.
//
// E2c stored one mapping under `mvp.gamepad.mapping.v1`; it is read once as the
// mapping for every controller that has none of its own (`devices['*']`).

import { defaultKeyMap, parseKeyMap, type KeyMap } from './controls-keys.js';
import { STORAGE_KEY as LEGACY_KEY, mappingFromObject, type GamepadMapping, type StorageLike } from './gamepad.js';

// The ports the page can drive on its own: player 1 and 2 (the game has two
// human players). Online, only this page's player matters (NETPLAY.md).
export const PORTS = 2;

export type PortAssign =
  | { mode: 'auto' }                                     // the next controller to be used
  | { mode: 'none' }                                     // no controller (the keyboard may still)
  | { mode: 'device'; key: string; nth: number; name?: string };  // the nth connected pad of this model

export interface ControlsConfig {
  version: 2;
  devices: Record<string, GamepadMapping>;  // by deviceKey(); '*' = the E2c mapping, for any pad without its own
  ports: PortAssign[];                      // PORTS entries
  keyboardPort: number;                     // the port the keyboard drives, -1 for none
  keys: KeyMap;
  rumble: boolean;
}

export const CONFIG_KEY = 'mvp.controls.v2';
const MAX_DEVICES = 24;

export function defaultConfig(): ControlsConfig {
  return {
    version: 2, devices: {}, ports: Array.from({ length: PORTS }, (): PortAssign => ({ mode: 'auto' })),
    keyboardPort: 0, keys: defaultKeyMap(), rumble: true,
  };
}

function parseAssign(v: unknown): PortAssign {
  const o = (v ?? {}) as Record<string, unknown>;
  if (o.mode === 'none') return { mode: 'none' };
  if (o.mode === 'device' && typeof o.key === 'string' && o.key.length > 0 && o.key.length <= 120 &&
      Number.isInteger(o.nth) && (o.nth as number) >= 0 && (o.nth as number) < 8) {
    const a: PortAssign = { mode: 'device', key: o.key, nth: o.nth as number };
    if (typeof o.name === 'string') a.name = o.name.slice(0, 80);
    return a;
  }
  return { mode: 'auto' };
}

export function parseConfig(text: string | null, legacy: string | null = null): ControlsConfig {
  const c = defaultConfig();
  if (legacy) {
    try {
      c.devices['*'] = mappingFromObject(JSON.parse(legacy));
    } catch {
      // damaged old mapping: ignore it
    }
  }
  if (!text) return c;
  let o: Record<string, unknown>;
  try {
    o = JSON.parse(text) as Record<string, unknown>;
  } catch {
    return c;
  }
  if (!o || typeof o !== 'object' || o.version !== 2) return c;
  const devices = (o.devices ?? {}) as Record<string, unknown>;
  if (devices && typeof devices === 'object') {
    for (const [key, v] of Object.entries(devices).slice(0, MAX_DEVICES)) {
      if (key.length > 0 && key.length <= 120 && v && typeof v === 'object') c.devices[key] = mappingFromObject(v);
    }
  }
  if (Array.isArray(o.ports)) c.ports = c.ports.map((_, i) => parseAssign((o.ports as unknown[])[i]));
  if (Number.isInteger(o.keyboardPort) && (o.keyboardPort as number) >= -1 && (o.keyboardPort as number) < PORTS)
    c.keyboardPort = o.keyboardPort as number;
  c.keys = parseKeyMap(o.keys);
  if (typeof o.rumble === 'boolean') c.rumble = o.rumble;
  return c;
}

export function loadConfig(storage: StorageLike | null): ControlsConfig {
  try {
    return parseConfig(storage?.getItem(CONFIG_KEY) ?? null, storage?.getItem(LEGACY_KEY) ?? null);
  } catch {
    return defaultConfig();
  }
}

export function saveConfig(storage: StorageLike | null, c: ControlsConfig): void {
  try {
    storage?.setItem(CONFIG_KEY, JSON.stringify(c));
  } catch {
    // private browsing or storage full: the choices last until the page closes
  }
}

// The mapping to use for a pad whose own stored mapping may not exist.
export function storedMapping(c: ControlsConfig, key: string): GamepadMapping | null {
  return c.devices[key] ?? c.devices['*'] ?? null;
}

// Helpers that return a changed copy (the panel replaces the config, the manager re-reads it).
export function withMapping(c: ControlsConfig, key: string, m: GamepadMapping): ControlsConfig {
  const next: ControlsConfig = { ...c, devices: { ...c.devices, [key]: m } };
  const keys = Object.keys(next.devices);
  if (keys.length > MAX_DEVICES) delete next.devices[keys.find((k) => k !== key && k !== '*') ?? ''];
  return next;
}

export function withoutMapping(c: ControlsConfig, key: string): ControlsConfig {
  const devices = { ...c.devices };
  delete devices[key];
  return { ...c, devices };
}

export function withPort(c: ControlsConfig, port: number, a: PortAssign): ControlsConfig {
  const ports = c.ports.map((p, i) => (i === port ? a : p));
  // A pad drives one port: choosing it here frees it elsewhere.
  if (a.mode === 'device') {
    for (let i = 0; i < ports.length; ++i) {
      const p = ports[i];
      if (i !== port && p.mode === 'device' && p.key === a.key && p.nth === a.nth) ports[i] = { mode: 'auto' };
    }
  }
  return { ...c, ports };
}
