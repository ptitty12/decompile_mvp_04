// The picture's Auto setting, with the GPU in mind (Q5).
//
// Q1's Auto draws the game at 1x, 2x or 3x the console's pixels, by the size of
// the picture on screen. On a laptop's integrated GPU with a high-DPI screen 3x
// can cost the GPU more than a field's time, and then the frames come late or
// the emulation waits for the renderer. The engine measures the GPU's time per
// frame (wasm/render_side.h: after each present, how long the GPU queue takes to
// finish the work submitted so far) and reports it about twice a second. This
// controller turns those reports into a ceiling for Auto:
//
// - Down: when the GPU's frames have been slow for a while (their mean over
//   kSlowMs, or a quarter of them over 14 ms, in every report for kDownAfterMs),
//   the ceiling drops one step below the scale in use.
// - Up again, with hysteresis: only after kHoldMs at the lower scale (doubling
//   each time a step up had to be undone within a minute, up to 5 minutes), and
//   only while the frames are fast enough that the next scale up should still
//   fit (the mean times the pixel ratio, ((s + 1) / s)^2, under kFitMs) for
//   kUpAfterMs.
//
// A fixed Picture setting (1x, 2x, 3x) is never changed. Rendering only: the
// internal resolution changes what is drawn, never guest state.

export interface GpuReport {
  n: number;      // GPU probes so far
  ms: number;     // their total time
  over: number;   // of them over 14 ms
}

export interface AutoScaleOptions {
  slowMs: number;       // a report's mean over this: slow
  slowShare: number;    // ... or this share of its probes over 14 ms
  downAfterMs: number;  // slow this long: one step down
  fitMs: number;        // the next scale's predicted mean under this: it would fit
  upAfterMs: number;    // fitting this long (after the hold): one step up
  holdMs: number;       // the first hold after a step down
  maxHoldMs: number;
  undoWithinMs: number; // a step down this soon after a step up doubles the hold
  minProbes: number;    // a report needs this many new probes to count
}

export const DEFAULT_AUTOSCALE: AutoScaleOptions = {
  slowMs: 12, slowShare: 0.25, downAfterMs: 2000, fitMs: 9, upAfterMs: 5000, holdMs: 20000, maxHoldMs: 300000,
  undoWithinMs: 60000, minProbes: 3,
};

export class AutoScale {
  readonly o: AutoScaleOptions;
  /** The highest scale Auto may use now (1-3). */
  ceiling = 3;
  steps: { at: number; from: number; to: number; meanMs: number }[] = [];  // statistics
  private last: GpuReport | null = null;
  private lastScale = 0;
  private slowSince = -1;
  private fitSince = -1;
  private downAt = -Infinity;
  private upAt = -Infinity;
  private hold: number;
  lastMean: number | null = null;

  constructor(options: Partial<AutoScaleOptions> = {}) {
    this.o = { ...DEFAULT_AUTOSCALE, ...options };
    this.hold = this.o.holdMs;
  }

  /**
   * A report from the engine: the GPU counters so far and the scale in use; `wanted`: what Auto would
   * draw at by the picture's size alone. Returns the ceiling.
   */
  update(now: number, gpu: GpuReport | null, scale: number, wanted: number): number {
    const o = this.o;
    if (!gpu) return this.ceiling;
    const prev = this.last;
    this.last = { ...gpu };
    if (scale !== this.lastScale) {  // a new scale: its own numbers from here on
      this.lastScale = scale;
      this.slowSince = this.fitSince = -1;
      return this.ceiling;
    }
    if (!prev) return this.ceiling;
    const n = gpu.n - prev.n;
    if (n < o.minProbes) return this.ceiling;
    const mean = (gpu.ms - prev.ms) / n, share = (gpu.over - prev.over) / n;
    this.lastMean = mean;
    const slow = mean > o.slowMs || share > o.slowShare;
    if (slow) {
      this.fitSince = -1;
      if (this.slowSince < 0) this.slowSince = now;
      if (now - this.slowSince >= o.downAfterMs && scale > 1) {
        if (now - this.upAt < o.undoWithinMs) this.hold = Math.min(o.maxHoldMs, this.hold * 2);
        this.ceiling = scale - 1;
        this.steps.push({ at: now, from: scale, to: this.ceiling, meanMs: mean });
        this.downAt = now;
        this.slowSince = -1;
      }
      return this.ceiling;
    }
    this.slowSince = -1;
    const next = scale + 1;
    const fits = next <= 3 && this.ceiling < wanted && mean * (next / scale) ** 2 < o.fitMs;
    if (!fits || now - this.downAt < this.hold) {
      this.fitSince = -1;
      return this.ceiling;
    }
    if (this.fitSince < 0) this.fitSince = now;
    if (now - this.fitSince >= o.upAfterMs) {
      this.ceiling = next;
      this.steps.push({ at: now, from: scale, to: next, meanMs: mean });
      this.upAt = now;
      this.fitSince = -1;
    }
    return this.ceiling;
  }
}
