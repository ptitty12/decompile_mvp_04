// The AudioWorklet processor (E2c, Q2): plays what the engine Worker mixes.
//
// The page creates this node on the first user gesture (the autoplay policy)
// and hands it one end of a MessageChannel whose other end goes to the engine
// Worker. The frames (interleaved 16-bit stereo at the game's rate) come one
// of two ways:
// - Q2, where the page is cross-origin isolated: through a ring in shared
//   memory ('ring': web_audio.h AudioRing). The threaded engine's mixer writes
//   into it inside the run, as it mixes; the single-threaded engine's Worker
//   copies each run batch into a ring of its own. This processor drains the ring
//   into the resampler at every render quantum.
// - Elsewhere through the port: each run batch's frames ('pcm', the buffer
//   transferred), as E2c did.
// Either way no audio passes through the page's main thread. The drift
// resampler (resampler.ts) converts 32 kHz to the context's rate, absorbs the
// drift between the guest's virtual clock and the device's, stretches the
// sound when the emulation runs behind, and holds more after an underrun.
// Nothing goes back to the Worker; statistics go to the page about four times
// a second.

import { DriftResampler } from './resampler.js';
import type { WorkletIn, WorkletStats } from './protocol.js';

// The AudioWorkletGlobalScope (not in TypeScript's DOM library).
declare const sampleRate: number;
declare const currentTime: number;
declare class AudioWorkletProcessor {
  readonly port: MessagePort;
  constructor(options?: unknown);
}
declare function registerProcessor(name: string, ctor: new (options: { processorOptions?: unknown }) => unknown): void;

interface Options {
  inRate: number;
  targetMs: number;
}

// The reader's side of an AudioRing (web_audio.h): header int32s
// [magic, capacity, rate, write, read, dropped, data byte address, ...].
const H_MAGIC = 0, H_CAP = 1, H_RATE = 2, H_WRITE = 3, H_READ = 4, H_DROPPED = 5, H_DATA = 6;
const MAGIC = 0x4d565041;

class Ring {
  readonly cap: number;
  private readonly h: Int32Array;
  private readonly frames: Int16Array;

  constructor(sab: SharedArrayBuffer, header: number) {
    this.h = new Int32Array(sab, header, 16);
    if (Atomics.load(this.h, H_MAGIC) !== MAGIC) throw new Error('not an audio ring');
    this.cap = Atomics.load(this.h, H_CAP);
    this.frames = new Int16Array(sab, Atomics.load(this.h, H_DATA) >>> 0, 2 * this.cap);
  }

  dropped(): number {
    return Atomics.load(this.h, H_DROPPED) >>> 0;
  }

  // Moves what the producer wrote into the resampler (as much as it has room for).
  drain(rs: DriftResampler): number {
    const w = Atomics.load(this.h, H_WRITE) >>> 0, r = Atomics.load(this.h, H_READ) >>> 0;
    let n = (w - r) >>> 0;
    if (!n) return 0;
    const rate = Atomics.load(this.h, H_RATE) || rs.inRate;
    n = Math.min(n, rs.space());
    const at = r & (this.cap - 1), first = Math.min(n, this.cap - at);
    rs.pushFrom(this.frames, at, first, rate);
    if (n > first) rs.pushFrom(this.frames, 0, n - first, rate);
    Atomics.store(this.h, H_READ, (r + n) | 0);
    return n;
  }
}

class MvpAudioProcessor extends AudioWorkletProcessor {
  private rs: DriftResampler;
  private ring: Ring | null = null;
  private sinceStats = 0;
  private chunks = 0;
  private lastChunkAt = 0;
  private maxGapMs = 0;

  constructor(options: { processorOptions?: unknown }) {
    super();
    const o = (options.processorOptions ?? {}) as Partial<Options>;
    const inRate = o.inRate ?? 32000;
    this.rs = new DriftResampler(sampleRate, inRate, ((o.targetMs ?? 60) / 1000) * inRate);
    this.port.onmessage = (ev: MessageEvent<WorkletIn>) => this.control(ev.data);
  }

  private arrived(): void {
    const now = currentTime * 1000;
    if (this.chunks++ > 0) this.maxGapMs = Math.max(this.maxGapMs, now - this.lastChunkAt);
    this.lastChunkAt = now;
  }

  private control(msg: WorkletIn): void {
    if (msg.type === 'source') {
      msg.port.onmessage = (ev: MessageEvent<WorkletIn>) => this.control(ev.data);
    } else if (msg.type === 'pcm') {
      this.rs.push(msg.data, msg.rate);
      this.arrived();
    } else if (msg.type === 'ring') {
      try {
        this.ring = new Ring(msg.sab, msg.header);
      } catch {
        this.ring = null;  // the Worker keeps posting 'pcm' only if it has no ring; nothing else to do
      }
    } else if (msg.type === 'reset') {
      this.rs.reset();
    } else if (msg.type === 'target') {
      this.rs.setTarget((msg.ms / 1000) * this.rs.inRate);
    }
  }

  process(_inputs: Float32Array[][], outputs: Float32Array[][]): boolean {
    if (this.ring && this.ring.drain(this.rs)) this.arrived();
    const out = outputs[0];
    if (out && out.length) this.rs.pull(out[0], out[1] ?? out[0]);
    this.sinceStats += out?.[0]?.length ?? 128;
    if (this.sinceStats >= sampleRate / 4) {
      this.sinceStats = 0;
      const s = this.rs.stats;
      const stats: WorkletStats = {
        ...s, sampleRate, inRate: this.rs.inRate, target: this.rs.target, available: this.rs.available(),
        chunks: this.chunks, maxGapMs: this.maxGapMs, transport: this.ring ? 'ring' : 'port',
        ringDropped: this.ring ? this.ring.dropped() : 0,
      };
      this.port.postMessage(stats);
      this.maxGapMs = 0;
    }
    return true;
  }
}

registerProcessor('mvp-audio', MvpAudioProcessor);
