// Messages between the page (main.ts) and the engine Worker (worker.ts).
// The disc image travels as a File object (a handle the Worker reads from
// locally); nothing here ever leaves the browser.

// One controller port in PADStatus terms (runtime/input.h, PadState).
export interface Pad {
  connected: boolean;
  buttons: number;  // pad bits: LEFT 0x1, RIGHT 0x2, DOWN 0x4, UP 0x8, Z 0x10, R 0x20, L 0x40, A 0x100, B 0x200, X 0x400, Y 0x800, START 0x1000
  stickX: number;   // -128..127, up is positive
  stickY: number;
  cX: number;
  cY: number;
  trigL: number;    // 0..255
  trigR: number;
}

// Netplay (E5): this page's role in an online game (engine/net, docs/engine/NETPLAY.md).
export interface NetOptions {
  player: 1 | 2;      // drives controller port 1 or 2
  delay: number;      // proposed input delay in frames (the session uses the larger proposal)
  hashEvery: number;  // frames per state-hash window (desync detection)
}

// What the Worker reports about the netplay session (wasm/net_web.cpp mvp_net_status).
export interface NetStatus {
  state: 'handshake' | 'running' | 'desynced' | 'disconnected' | 'rejected' | 'ended';
  reason: string;
  player: number;
  delay: number;
  frame: number;
  peerFrame: number;
  localHorizon: number;
  remoteHorizon: number;
  rttLast: number;
  rttMin: number;
  rttAvg: number;
  rttMax: number;
  packetsSent: number;
  bytesSent: number;
  packetsReceived: number;
  bytesReceived: number;
  badPackets: number;
  hashesCompared: number;
  stalls: number;
  stallMs: number;
  longestStallMs: number;
  gateMisses: number;
  earlyYields: number;
  latencyAvg: number;  // ms from sampling the local pad to the frame that uses it
  latencyMax: number;
  latencySum: number;
  latencySamples: number;
  windows: number;
  lastWindow: string;
  desync: boolean;
}

export interface RunOptions {
  netplay?: NetOptions;  // an online game: boot only after the handshake
  script: string;      // an mvp-input script (tests); empty: live keyboard/gamepad input
  stopFields: number;  // stop after this many VI fields (0: never)
  stopFrames: number;  // stop at the poll of this frame (0: never)
  fast: boolean;       // run unpaced, as fast as possible (measurements, tests)
  render: boolean;     // false: no WebGPU at all (the guest alone)
}

export type ToWorker =
  | { type: 'start'; file: File; canvas: OffscreenCanvas | null; width: number; height: number; options: RunOptions }
  | { type: 'pad'; port: number; pad: Pad }
  | { type: 'tick'; now: number }  // the page's animation frame, when the Worker has no requestAnimationFrame
  | { type: 'resize'; width: number; height: number }
  | { type: 'pause'; paused: boolean }
  | { type: 'net-open' }                    // the data channel to the other player is open
  | { type: 'net-recv'; data: ArrayBuffer }  // a datagram from the other player
  | { type: 'net-quit' };                   // the page is leaving the game

export interface Status {
  fields: number;
  frames: number;
  instructions: number;
  guest_s: number;
  run_ms: number;
  run_fields: number;
  last_batch_ms: number;
  max_field_ms: number;
  yields: number;
  presents: number;
  stopped: boolean;
  why?: string;
  draws?: number;
  xfb_copies?: number;
  pipelines?: number;
  textures?: number;
  gpu_errors?: number;
  gfx_error?: string;
  disc_reads?: number;
  disc_bytes?: number;
  heap_mb?: number;  // the engine's WebAssembly memory
}

export type FromWorker =
  | { type: 'log'; text: string; error: boolean }
  | { type: 'phase'; name: string; ms: number; detail?: unknown }
  | { type: 'error'; stage: string; message: string }
  | { type: 'disc'; info: { game: string; revision: number; title: string; dol_sha1: string; image: string } }
  | { type: 'gfx'; ok: boolean; message: string }
  | { type: 'first-frame'; fields: number }
  | { type: 'stats'; status: Status; window: { fields: number; ms: number; wallMs: number } }
  | { type: 'stopped'; status: Status; guestLine: string }
  | { type: 'net-send'; data: ArrayBuffer }  // a datagram for the other player
  | { type: 'net'; status: NetStatus; windows?: string; diagnostic?: string };
