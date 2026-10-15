// The browser's drift resampler (E2c), the AudioWorklet's side of the audio
// path: the same design as the native one (engine/audio/drift.h, E3b), plus the
// conversion from the game's rate (32 kHz) to the AudioContext's (usually
// 48 kHz).
//
// The engine Worker mixes at the pace of the guest's virtual clock and posts
// each run batch's frames (push). The worklet pulls at the device's pace. The
// resampler reads its buffer at the nominal step inRate / outRate times a
// ratio near 1, steered by the smoothed fill toward a target: fuller than the
// target, it reads faster (at most +0.5 %, inaudible as pitch); emptier,
// slower. Run dry, it fades out and waits until the buffer holds the target
// again (an underrun); far ahead (more than 4 x the target: the emulation ran
// ahead, the tab was in the background), it skips down to the target. A full
// buffer drops what the producer sends. Interpolation is cubic (Catmull-Rom),
// which keeps the images of the 32 kHz signal well down at 48 kHz.
//
// Host-side only: nothing here reaches the engine; the Worker never waits for
// it, and the guest computes the same with or without it.

export interface ResamplerStats {
  inFrames: number;       // frames pushed
  dropped: number;        // ... dropped (buffer full)
  outFrames: number;      // frames produced
  silentFrames: number;   // ... of which silence (not primed, or after an underrun)
  underruns: number;      // times the buffer ran dry
  skipped: number;        // input frames skipped to catch up
  minRatio: number;
  maxRatio: number;
  ratio: number;          // the current drift correction
  fill: number;           // smoothed buffered input frames
  peak: number;           // largest |output sample| (-1..1)
  nonsilentOut: number;   // output frames with a sample above 1/32768
}

const FADE = 64;              // output frames to fade out over after an underrun
const SMOOTH_S = 0.3;         // the fill estimate's time constant, seconds
const GAIN = 0.01;            // ratio change per unit of relative fill error (as native)
const MAX_ADJUST = 0.005;     // +-0.5 %
const SKIP_FACTOR = 4;        // more than 4 x the target buffered: skip down to it

export class DriftResampler {
  readonly outRate: number;
  inRate: number;
  target: number;  // input frames to hold before playing (the latency it adds)
  private readonly cap: number;
  private readonly l: Float32Array;
  private readonly r: Float32Array;
  private w = 0;  // positions only grow
  private rd = 0;
  private primed = false;
  private pos = 0;             // fraction between h[1] and h[2]
  private hl = new Float32Array(4);  // the last four input frames, oldest first
  private hr = new Float32Array(4);
  private fadeL = 0;
  private fadeR = 0;
  private fadeLeft = 0;
  readonly stats: ResamplerStats = {
    inFrames: 0, dropped: 0, outFrames: 0, silentFrames: 0, underruns: 0, skipped: 0,
    minRatio: 1, maxRatio: 1, ratio: 1, fill: 0, peak: 0, nonsilentOut: 0,
  };

  // `targetFrames` of buffering at the input rate; capacity at least 8 x that.
  constructor(outRate: number, inRate: number, targetFrames: number, capacityFrames = 0) {
    this.outRate = outRate;
    this.inRate = inRate;
    this.target = Math.max(64, Math.round(targetFrames));
    let cap = 1;
    while (cap < Math.max(capacityFrames, 8 * this.target, 4096)) cap <<= 1;
    this.cap = cap;
    this.l = new Float32Array(cap);
    this.r = new Float32Array(cap);
  }

  // Frames waiting in the buffer.
  available(): number {
    return this.w - this.rd;
  }

  // Producer: interleaved 16-bit stereo at `rate` Hz. Returns the frames kept.
  push(lr: Int16Array, rate = this.inRate): number {
    if (rate !== this.inRate && rate > 0) this.inRate = rate;
    const frames = lr.length >> 1;
    const space = this.cap - (this.w - this.rd);
    const n = Math.min(frames, space);
    const mask = this.cap - 1;
    for (let i = 0; i < n; ++i) {
      const at = (this.w + i) & mask;
      this.l[at] = lr[2 * i] / 32768;
      this.r[at] = lr[2 * i + 1] / 32768;
    }
    this.w += n;
    this.stats.inFrames += n;
    this.stats.dropped += frames - n;
    return n;
  }

  // Drops everything buffered (a seek, a reset); the next pull primes again.
  reset(): void {
    this.rd = this.w;
    this.primed = false;
    this.fadeLeft = 0;
  }

  private next(): boolean {
    if (this.rd === this.w) return false;
    const at = this.rd & (this.cap - 1);
    this.hl.copyWithin(0, 1);
    this.hr.copyWithin(0, 1);
    this.hl[3] = this.l[at];
    this.hr[3] = this.r[at];
    ++this.rd;
    return true;
  }

  // Fills `outL` and `outR` (same length) at the output rate.
  pull(outL: Float32Array, outR: Float32Array): void {
    const n = outL.length;
    const st = this.stats;
    let have = this.available();
    if (have > SKIP_FACTOR * this.target) {
      const drop = have - this.target;
      this.rd += drop;
      st.skipped += drop;
      st.fill = this.target;
      have = this.available();
    }
    if (!this.primed && have >= this.target) {
      // Start (or restart) with four real frames of history.
      this.primed = true;
      this.pos = 0;
      st.fill = have;
      this.hl.fill(0);
      this.hr.fill(0);
      for (let k = 0; k < 3; ++k) this.next();
    }
    if (this.primed) {
      const alpha = 1 - Math.exp(-n / (SMOOTH_S * this.outRate));
      st.fill += alpha * (this.available() - st.fill);
      const err = (st.fill - this.target) / this.target;
      st.ratio = 1 + Math.max(-MAX_ADJUST, Math.min(MAX_ADJUST, GAIN * err));
      st.minRatio = Math.min(st.minRatio, st.ratio);
      st.maxRatio = Math.max(st.maxRatio, st.ratio);
    }
    const step = (this.inRate / this.outRate) * st.ratio;
    for (let i = 0; i < n; ++i) {
      if (!this.primed) {
        if (this.fadeLeft) {
          const g = this.fadeLeft / FADE;
          outL[i] = this.fadeL * g;
          outR[i] = this.fadeR * g;
          --this.fadeLeft;
        } else {
          outL[i] = 0;
          outR[i] = 0;
        }
        ++st.silentFrames;
        continue;
      }
      const t = this.pos;
      const a = cubic(this.hl, t), b = cubic(this.hr, t);
      outL[i] = a;
      outR[i] = b;
      const m = Math.max(Math.abs(a), Math.abs(b));
      if (m > st.peak) st.peak = m;
      if (m >= 1 / 32768) ++st.nonsilentOut;
      this.pos += step;
      while (this.pos >= 1) {
        this.pos -= 1;
        if (!this.next()) {  // ran dry: fade out, wait for the target again
          this.primed = false;
          ++st.underruns;
          this.fadeL = a;
          this.fadeR = b;
          this.fadeLeft = FADE;
          break;
        }
      }
    }
    st.outFrames += n;
  }
}

// Catmull-Rom between h[1] and h[2] at t in [0, 1).
function cubic(h: Float32Array, t: number): number {
  const p0 = h[0], p1 = h[1], p2 = h[2], p3 = h[3];
  const v = p1 + 0.5 * t * (p2 - p0 + t * (2 * p0 - 5 * p1 + 4 * p2 - p3 + t * (3 * (p1 - p2) + p3 - p0)));
  return v > 1 ? 1 : v < -1 ? -1 : v;
}
