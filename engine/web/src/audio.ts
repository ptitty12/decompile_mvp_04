// Browser audio, the page's side (E2c): the AudioContext, the worklet node
// (audio-worklet.ts) and the channel between the node and the engine Worker.
//
// Browsers start audio only after a user gesture (the autoplay policy), so the
// context is created on the first pointer press, key press or touch on the page
// (unlock()). Until then the Worker does not mix at all. The node gets one end
// of a MessageChannel and the Worker the other (onPort), so the Worker's frames
// go straight to the audio thread. An AnalyserNode taps the node's output for
// the level meter and the browser check (probe()).
//
// When the tab is hidden the page pauses the Worker's loop and suspends the
// context; nothing about audio timing ever goes back to the Worker.

import type { WorkletIn, WorkletStats } from './protocol.js';

export interface AudioState {
  state: 'off' | 'waiting-for-gesture' | 'starting' | 'running' | 'suspended' | 'failed' | 'muted';
  error?: string;
  sampleRate?: number;
  baseLatencyMs?: number;
  outputLatencyMs?: number;
  worklet?: WorkletStats;
}

export class AudioOut {
  readonly info: AudioState = { state: 'waiting-for-gesture' };
  private ctx: AudioContext | null = null;
  private analyser: AnalyserNode | null = null;
  private gain: GainNode | null = null;
  private probeBuf: Float32Array<ArrayBuffer> | null = null;
  private muted = false;

  // `onPort` receives the Worker's end of the channel once the node exists.
  constructor(private readonly onPort: (port: MessagePort) => void,
              private readonly targetMs: number,
              private readonly onChange: (s: AudioState) => void = () => {}) {}

  // Call from a user gesture's handler (synchronously: the context must be
  // created inside the gesture).
  unlock(): void {
    if (this.ctx) {
      if (this.ctx.state === 'suspended' && !document.hidden) void this.ctx.resume();
      return;
    }
    try {
      this.ctx = new AudioContext({ latencyHint: 'interactive' });
    } catch (e) {
      this.fail(`no AudioContext: ${e}`);
      return;
    }
    this.info.state = 'starting';
    this.changed();
    void this.start(this.ctx);
  }

  private async start(ctx: AudioContext): Promise<void> {
    try {
      await ctx.audioWorklet.addModule(new URL('./audio-worklet.js', import.meta.url));
      const node = new AudioWorkletNode(ctx, 'mvp-audio', {
        numberOfInputs: 0, numberOfOutputs: 1, outputChannelCount: [2],
        processorOptions: { inRate: 32000, targetMs: this.targetMs },
      });
      const gain = ctx.createGain();
      gain.gain.value = this.muted ? 0 : 1;
      node.connect(gain).connect(ctx.destination);
      const analyser = ctx.createAnalyser();
      analyser.fftSize = 2048;
      node.connect(analyser);  // the tap: the worklet's own output, before the volume
      node.port.onmessage = (ev: MessageEvent<WorkletStats>) => {
        this.info.worklet = ev.data;
        this.changed();
      };
      const ch = new MessageChannel();
      const msg: WorkletIn = { type: 'source', port: ch.port1 };
      node.port.postMessage(msg, [ch.port1]);
      this.gain = gain;
      this.analyser = analyser;
      this.onPort(ch.port2);
      if (ctx.state === 'suspended' && !document.hidden) await ctx.resume();
      this.info.state = this.muted ? 'muted' : ctx.state === 'running' ? 'running' : 'suspended';
      this.info.sampleRate = ctx.sampleRate;
      this.info.baseLatencyMs = (ctx.baseLatency ?? 0) * 1000;
      this.info.outputLatencyMs = (ctx.outputLatency ?? 0) * 1000;
      ctx.onstatechange = () => {
        if (this.info.state !== 'failed') this.info.state = this.muted ? 'muted' : ctx.state === 'running' ? 'running' : 'suspended';
        this.info.outputLatencyMs = (ctx.outputLatency ?? 0) * 1000;
        this.changed();
      };
      this.changed();
    } catch (e) {
      this.fail(String(e));
    }
  }

  private fail(message: string): void {
    this.info.state = 'failed';
    this.info.error = message;
    this.changed();
  }

  private changed(): void {
    this.onChange(this.info);
  }

  // Tab hidden or shown: the context stops with the game.
  setPaused(paused: boolean): void {
    if (!this.ctx) return;
    if (paused) void this.ctx.suspend();
    else void this.ctx.resume();
  }

  setMuted(muted: boolean): void {
    this.muted = muted;
    if (this.gain) this.gain.gain.value = muted ? 0 : 1;
    if (this.ctx && this.info.state !== 'failed')
      this.info.state = muted ? 'muted' : this.ctx.state === 'running' ? 'running' : 'suspended';
    this.changed();
  }

  isMuted(): boolean {
    return this.muted;
  }

  // The worklet's output right now: RMS and peak over the analyser's window.
  probe(): { rms: number; peak: number } | null {
    if (!this.analyser) return null;
    if (!this.probeBuf) this.probeBuf = new Float32Array(this.analyser.fftSize);
    this.analyser.getFloatTimeDomainData(this.probeBuf);
    let sum = 0, peak = 0;
    for (const v of this.probeBuf) {
      sum += v * v;
      peak = Math.max(peak, Math.abs(v));
    }
    return { rms: Math.sqrt(sum / this.probeBuf.length), peak };
  }
}
