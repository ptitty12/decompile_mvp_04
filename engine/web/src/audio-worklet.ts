// The AudioWorklet processor (E2c): plays what the engine Worker mixes.
//
// The page creates this node on the first user gesture (the autoplay policy)
// and hands it one end of a MessageChannel whose other end goes to the engine
// Worker; the Worker posts each run batch's frames straight here ('pcm':
// interleaved 16-bit stereo at the game's rate, the buffer transferred), so no
// audio passes through the page's main thread. The drift resampler
// (resampler.ts) converts 32 kHz to the context's rate and absorbs the drift
// between the guest's virtual clock and the device's. Nothing goes back to the
// Worker; statistics go to the page about four times a second.
//
// Why a MessagePort and not a SharedArrayBuffer ring: see docs/engine/WEB.md
// ("Audio"): no cross-origin isolation headers are needed on any server, and the
// latency is set by the Worker's batches (one animation frame), not the transport.

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

class MvpAudioProcessor extends AudioWorkletProcessor {
  private rs: DriftResampler;
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

  private control(msg: WorkletIn): void {
    if (msg.type === 'source') {
      msg.port.onmessage = (ev: MessageEvent<WorkletIn>) => this.control(ev.data);
    } else if (msg.type === 'pcm') {
      this.rs.push(msg.data, msg.rate);
      const now = currentTime * 1000;
      if (this.chunks++ > 0) this.maxGapMs = Math.max(this.maxGapMs, now - this.lastChunkAt);
      this.lastChunkAt = now;
    } else if (msg.type === 'reset') {
      this.rs.reset();
    } else if (msg.type === 'target') {
      this.rs.target = Math.max(64, Math.round((msg.ms / 1000) * this.rs.inRate));
    }
  }

  process(_inputs: Float32Array[][], outputs: Float32Array[][]): boolean {
    const out = outputs[0];
    if (out && out.length) this.rs.pull(out[0], out[1] ?? out[0]);
    this.sinceStats += out?.[0]?.length ?? 128;
    if (this.sinceStats >= sampleRate / 4) {
      this.sinceStats = 0;
      const s = this.rs.stats;
      const stats: WorkletStats = {
        ...s, sampleRate, inRate: this.rs.inRate, target: this.rs.target, available: this.rs.available(),
        chunks: this.chunks, maxGapMs: this.maxGapMs,
      };
      this.port.postMessage(stats);
      this.maxGapMs = 0;
    }
    return true;
  }
}

registerProcessor('mvp-audio', MvpAudioProcessor);
