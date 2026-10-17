// The picture's Auto setting, with the GPU in mind (Q5).
//
// Q1's Auto draws the game at 1x, 2x or 3x the console's pixels, by the size of
// the picture on screen. On a laptop's integrated GPU with a high-DPI screen 3x
// can cost the GPU more than a field's time: then the frames come late and the
// emulation waits for the renderer. The engine times its render passes on the
// GPU (timestamp queries, gfx/wgpu/gpu_timer.h) and reports the GPU's time in
// all about twice a second (frames whose read-back is still busy are not timed:
// they count at the mean of the others); its share of the wall time is how busy
// the GPU is.
// This controller turns those reports into a ceiling for Auto:
//
// - Down: when the GPU has been busy more than 85 % of the time in every report
//   for two seconds, the ceiling drops one step below the scale in use.
// - Up again, with hysteresis: only after a hold at the lower scale (20 s,
//   doubling each time a step up had to be undone within a minute, up to 5
//   minutes), and only while the next scale up should still fit (the busy share
//   times the pixel ratio, ((s + 1) / s)^2, under 60 %) for five seconds.
//
// Without timestamp queries (a browser that lacks them) nothing changes: Auto
// goes by the picture's size, as before. A fixed Picture setting (1x, 2x, 3x) is
// never changed. Rendering only: the internal resolution changes what is drawn,
// never guest state.

export interface GpuReport {
  n: number;         // frames timed so far
  ms: number;        // their GPU time in all
  dropped?: number;  // frames presented but not timed (their read-back still busy): as costly as the timed ones
}

export interface AutoScaleOptions {
  busyShare: number;    // a report with the GPU busy more than this share of the time: too busy
  downAfterMs: number;  // too busy this long: one step down
  fitShare: number;     // the next scale's predicted share under this: it would fit
  upAfterMs: number;    // fitting this long (after the hold): one step up
  holdMs: number;       // the first hold after a step down
  maxHoldMs: number;
  undoWithinMs: number; // a step down this soon after a step up doubles the hold
  minFrames: number;    // a report needs this many new frames to count
}

export const DEFAULT_AUTOSCALE: AutoScaleOptions = {
  busyShare: 0.85, downAfterMs: 2000, fitShare: 0.6, upAfterMs: 5000, holdMs: 20000, maxHoldMs: 300000,
  undoWithinMs: 60000, minFrames: 3,
};

export class AutoScale {
  readonly o: AutoScaleOptions;
  /** The highest scale Auto may use now (1-3). */
  ceiling = 3;
  steps: { at: number; from: number; to: number; busy: number }[] = [];  // statistics
  /** The GPU's busy share in the last report (null before one). */
  lastBusy: number | null = null;
  private last: (GpuReport & { at: number }) | null = null;
  private lastScale = 0;
  private slowSince = -1;
  private fitSince = -1;
  private downAt = -Infinity;
  private upAt = -Infinity;
  private hold: number;

  constructor(options: Partial<AutoScaleOptions> = {}) {
    this.o = { ...DEFAULT_AUTOSCALE, ...options };
    this.hold = this.o.holdMs;
  }

  /**
   * A report from the engine at `now` (ms): the GPU counters so far and the scale in use; `wanted`: what
   * Auto would draw at by the picture's size alone. Returns the ceiling.
   */
  update(now: number, gpu: GpuReport | null, scale: number, wanted: number): number {
    const o = this.o;
    if (!gpu) return this.ceiling;
    const prev = this.last;
    this.last = { n: gpu.n, ms: gpu.ms, dropped: gpu.dropped ?? 0, at: now };
    if (scale > this.ceiling) return this.ceiling;  // a step down not in effect yet (the renderer changes at a frame's start)
    if (scale !== this.lastScale) {  // a new scale: its own numbers from here on
      this.lastScale = scale;
      this.slowSince = this.fitSince = -1;
      return this.ceiling;
    }
    if (!prev || now <= prev.at || gpu.n - prev.n < o.minFrames) return this.ceiling;
    // The mean GPU time of the frames timed, times every frame presented (timed or not), over the time.
    const n = gpu.n - prev.n, all = n + (gpu.dropped ?? 0) - (prev.dropped ?? 0);
    const busy = (((gpu.ms - prev.ms) / n) * all) / (now - prev.at);
    this.lastBusy = busy;
    if (busy > o.busyShare) {
      this.fitSince = -1;
      if (this.slowSince < 0) this.slowSince = now;
      if (now - this.slowSince >= o.downAfterMs && scale > 1) {
        if (now - this.upAt < o.undoWithinMs) this.hold = Math.min(o.maxHoldMs, this.hold * 2);
        this.ceiling = scale - 1;
        this.steps.push({ at: now, from: scale, to: this.ceiling, busy });
        this.downAt = now;
        this.slowSince = -1;
      }
      return this.ceiling;
    }
    this.slowSince = -1;
    const next = scale + 1;
    const fits = next <= 3 && this.ceiling < wanted && busy * (next / scale) ** 2 < o.fitShare;
    if (!fits || now - this.downAt < this.hold) {
      this.fitSince = -1;
      return this.ceiling;
    }
    if (this.fitSince < 0) this.fitSince = now;
    if (now - this.fitSince >= o.upAfterMs) {
      this.ceiling = next;
      this.steps.push({ at: now, from: scale, to: next, busy });
      this.upAt = now;
      this.fitSince = -1;
    }
    return this.ceiling;
  }
}
