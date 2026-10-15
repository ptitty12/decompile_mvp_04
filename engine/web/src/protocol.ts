// Messages between the page (main.ts) and the engine Worker (worker.ts), and
// between the Worker and the AudioWorklet (audio-worklet.ts). A picked disc
// image travels as a File object (a handle the Worker reads from locally); on
// the owner's deployment it is a same-origin URL the Worker reads with Range
// requests (disc.ts). Nothing here ever leaves the browser.

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

// Roster packs (E6, docs/MODDING.md): what the player picked on the page, in set
// order. A picked folder is its files (paths inside the folder, '/'-separated); a
// zip is one file. The engine reads them (engine/mods); they never leave the browser.
export interface PackFile {
  path: string;
  data: ArrayBuffer;
}
export interface PackInput {
  label: string;             // the folder's or the zip's name, for messages
  kind: 'files' | 'zip';
  files: PackFile[];
}
export interface PackIssue {
  severity: 'error' | 'warning';
  code: string;              // E-... / W-... (MODDING.md §7.4)
  where: string;
  message: string;
}
// The engine's report on a pack set (mods::set_json): before the disc, the static
// checks and hashes; after mounting, also the result of applying it.
export interface PackSetReport {
  ok: boolean;
  set_hash: string;          // the netplay handshake's pack-set field
  packs: { label: string; id: string | null; name: string; version: string; hash: string | null }[];
  issues: PackIssue[];
  fatal?: string;
  result_hash?: string;      // covers the patched tables and text (MODDING.md §10)
  changed_tables?: string[];
  files?: string[];          // disc paths now served from memory
  bytes?: number;
}

export interface RunOptions {
  netplay?: NetOptions;  // an online game: boot only after the handshake
  packs?: PackInput[];   // roster packs to apply to the disc before the boot (E6)
  script: string;      // an mvp-input script (tests); empty: live keyboard/gamepad input
  stopFields: number;  // stop after this many VI fields (0: never)
  stopFrames: number;  // stop at the poll of this frame (0: never)
  fast: boolean;       // run unpaced, as fast as possible (measurements, tests)
  render: boolean;     // false: no WebGPU at all (the guest alone)
  audio: boolean;      // false: never mix (the guest is the same either way)
  cache: boolean;      // use and fill the browser's cache of the translated module
  traceDisc?: boolean; // development: record the picked image's reads (offsets and sizes)
  discCache?: { blockKib?: number; maxBlocks?: number; maxRun?: number; ahead?: number };  // the server image's cache
}

// The disc image: a file the player picked, or the server's image (disc.ts).
export type DiscSource = { kind: 'file'; file: File } | { kind: 'url'; url: string };

export type ToWorker =
  | { type: 'start'; disc: DiscSource; canvas: OffscreenCanvas | null; width: number; height: number; options: RunOptions }
  | { type: 'pad'; port: number; pad: Pad }
  | { type: 'tick'; now: number }  // the page's animation frame, when the Worker has no requestAnimationFrame
  | { type: 'resize'; width: number; height: number }
  | { type: 'pause'; paused: boolean }
  | { type: 'audio-port'; port: MessagePort }  // the AudioWorklet's channel (after the first user gesture)
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
  net?: { requests: number; fetched: number; hits: number; misses: number; prefetched: number; prefetch_used: number;
          prefetch_wasted: number; blocked_ms: number };  // the server's image (block cache)
  audio?: { frames: number; rate: number; voice_ms: number; aux_returns: number; nonsilent: number; peak: number;
            dropped: number };  // the mixer, while attached
  pad_last?: number;   // port 1's buttons at the last frame poll (live input)
  pad_polls?: number;  // frame polls that returned a pressed button
}

export interface CacheReport {
  key: string | null;
  hit: boolean;
  readMs?: number;     // reading the entry into the engine
  storedMs?: number;   // writing it (after the first frame)
  bytes?: number;
  error?: string;
}

export type FromWorker =
  | { type: 'log'; text: string; error: boolean }
  | { type: 'phase'; name: string; ms: number; detail?: unknown }
  | { type: 'progress'; text: string; step: number; steps: number }
  | { type: 'error'; stage: string; message: string; login?: boolean }
  | { type: 'disc'; info: { game: string; revision: number; title: string; dol_sha1: string; image: string } }
  | { type: 'packs'; report: PackSetReport }  // the pack set applied to the disc (or why not)
  | { type: 'gfx'; ok: boolean; message: string }
  | { type: 'first-frame'; fields: number }
  | { type: 'cache'; report: CacheReport }
  | { type: 'audio'; attachedAtField: number }
  | { type: 'stats'; status: Status; window: { fields: number; ms: number; wallMs: number } }
  | { type: 'stopped'; status: Status; guestLine: string; discTrace?: string }
  | { type: 'net-send'; data: ArrayBuffer }  // a datagram for the other player
  | { type: 'net'; status: NetStatus; windows?: string; diagnostic?: string };

// Worker (or page) -> AudioWorklet.
export type WorkletIn =
  | { type: 'source'; port: MessagePort }               // the Worker's channel
  | { type: 'pcm'; rate: number; data: Int16Array }     // interleaved stereo frames
  | { type: 'reset' }
  | { type: 'target'; ms: number };

// AudioWorklet -> page, about four times a second.
export interface WorkletStats {
  inFrames: number;
  dropped: number;
  outFrames: number;
  silentFrames: number;
  underruns: number;
  skipped: number;
  minRatio: number;
  maxRatio: number;
  ratio: number;
  fill: number;
  peak: number;
  nonsilentOut: number;
  sampleRate: number;
  inRate: number;
  target: number;
  available: number;
  chunks: number;
  maxGapMs: number;
}
