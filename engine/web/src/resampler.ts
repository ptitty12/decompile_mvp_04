// The browser's drift resampler (E2c, Q2), the AudioWorklet's side of the audio
// path: the same design as the native one (engine/audio/drift.h, E3b), plus the
// conversion from the game's rate (32 kHz) to the AudioContext's (usually
// 48 kHz), a time-stretch for an emulation that runs behind, and a buffer
// target that grows after underruns.
//
// The engine mixes at the pace of the guest's virtual clock and its frames
// arrive here in bursts (push): each run batch's frames through a MessagePort,
// or as they are mixed through a ring in shared memory (audio-worklet.ts). The
// worklet pulls at the device's pace.
//
// - Drift: the resampler reads its buffer at the nominal step inRate / outRate
//   times a ratio near 1, steered by the smoothed fill toward the target:
//   fuller than the target, it reads faster (at most +0.5 %, inaudible as
//   pitch); emptier, slower. Interpolation is cubic (Catmull-Rom), which keeps
//   the images of the 32 kHz signal well down at 48 kHz.
// - Behind (Q2): when the emulation produces less than real time (a slow
//   machine, a heavy scene), the drift range cannot absorb it and the buffer
//   used to run dry over and over (the sound went on, off, on, off). Now the
//   input is time-stretched instead, with its pitch kept (a WSOLA-style splice):
//   once the buffer falls well under the target the reader plays the input
//   slower (down to a quarter speed), at a speed steered by the fill (proportional
//   and integral: it settles at the emulation's own speed with the buffer at
//   the target) until the input keeps up again. It plays contiguous
//   stretches of the input; where its position runs more than 4 ms (less on a
//   low buffer) ahead of the speed's ideal track it jumps back to the point
//   near the ideal position that best matches what would have played next
//   (both channels compared, the nearest of equal matches), cross-faded over
//   4 ms, so the sound slows down rather than stopping. At full speed the
//   input plays as is.
// - Underrun: run dry (the producer stalled), it fades out and plays again
//   once half the base target is buffered (30 ms by default: the stretch
//   then rebuilds the rest while it plays, so the silence is the stall and not
//   the stall plus a whole buffer); each underrun raises the target by 20 ms
//   (up to 200 ms; not when the stretch was already at its slowest, where more
//   buffer would not help), and every 30 s without one lowers it by 10 ms again
//   (down to the base). The first start waits for the whole base target.
// - The pace (Q5): an online game whose players' machines cannot both keep up
//   runs at a planned pace below full speed (pacer.ts), and the Worker says so
//   (setPace). The stretch then starts at that speed at once, instead of after
//   the buffer has run low enough to find it; the fill keeps trimming it. Back
//   at full speed the stretch ends by itself as the buffer fills.
// - Far ahead (more than 4 x the target: the emulation ran ahead, the tab was in
//   the background), it skips down to the target. A full buffer drops what the
//   producer sends.
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
  // Q2: the silences underruns made (from the underrun until the buffer plays again):
  gaps: number;           // how many ended
  gaps20: number;         // ... of them longer than 20 ms
  gapMs: number;          // their total length
  longestGapMs: number;
  // Q2: the time-stretch and the target.
  speed: number;          // the input's measured rate / the nominal rate (smoothed over about a second; statistics)
  stretch: number;        // the input's current playback speed (1: as is; < 1: stretched)
  minStretch: number;
  stretched: number;      // input frames played while stretching
  splices: number;        // jumps back to a similar point (each one cross-faded)
  targetMs: number;       // the current buffer target
  maxTargetMs: number;
}

const FADE = 64;              // output frames to fade out over after an underrun
const SMOOTH_S = 0.3;         // the fill estimate's time constant, seconds
const RATE_S = 1.0;           // the input rate estimate's time constant, seconds
const GAIN = 0.01;            // ratio change per unit of relative fill error (as native)
const MAX_ADJUST = 0.005;     // +-0.5 %
const SKIP_FACTOR = 4;        // more than 4 x the target buffered: skip down to it
// The time-stretch (at the input rate).
const HOP = 64;               // a splice is considered every HOP input frames (2 ms at 32 kHz)
const XF = 128;               // ... and cross-fades over XF frames (4 ms)
const SEEK = 128;             // how far a splice point may be from the ideal position (4 ms)
const CORR = 64;              // frames compared to find a splice point
const FAST_S = 0.05;          // the stretch's own fill estimate's time constant, seconds
const STRETCH_ON = -0.4;      // the buffer this far under the target (relative): stretch
const KP = 0.5;               // the speed: 1 + KP * relative fill error + its integral (KI per second)
const KI = 2.0;
const MIN_SPEED = 0.25;
// The adaptive target.
const GROW_MS = 20;
const MAX_TARGET_MS = 200;
const SHRINK_MS = 10;
const SHRINK_AFTER_S = 30;
const RESTART_SHARE = 1 / 2;  // after an underrun, play again once half the base target is buffered

// The cross-fade: WIN[i] rises over XF frames; 1 - WIN[i] falls.
const WIN = (() => {
  const w = new Float32Array(XF);
  for (let i = 0; i < XF; ++i) w[i] = 0.5 - 0.5 * Math.cos((Math.PI * (i + 0.5)) / XF);
  return w;
})();

export class DriftResampler {
  readonly outRate: number;
  inRate: number;
  target: number;      // input frames to hold (the latency it adds); grows after underruns
  baseTarget: number;  // ... and where it returns to; the buffer must hold this much to start
  private readonly cap: number;
  private readonly l: Float32Array;
  private readonly r: Float32Array;
  private w = 0;       // positions only grow
  private rd = 0;      // the next input frame to play
  private keep = 0;    // frames from here on stay in the buffer (a splice may reach back to them)
  private primed = false;
  private pos = 0;             // fraction between h[1] and h[2]
  private hl = new Float32Array(4);  // the last four input frames, oldest first
  private hr = new Float32Array(4);
  private fadeL = 0;
  private fadeR = 0;
  private fadeLeft = 0;
  private gapFrom = -1;  // output frame of the last underrun, while its silence lasts
  // The time-stretch: the ideal input position at the current speed, and the
  // hop in progress (a cross-fade from the frames at xfFrom on to those at rd on, when xfFrom >= 0).
  private stretching = false;
  private integ = 0;     // the stretch controller's integral term
  private fastFill = 0;
  private ideal = 0;
  private hopLeft = HOP;
  private xfFrom = -1;
  private xfAt = 0;
  // The input rate estimate.
  private rateEst: number;
  private lastIn = 0;
  private lastOut = 0;
  private sinceChange = 0;  // output frames since the last underrun or target change
  readonly stats: ResamplerStats;

  // `targetFrames` of buffering at the input rate; capacity at least 8 x the largest target.
  constructor(outRate: number, inRate: number, targetFrames: number, capacityFrames = 0) {
    this.outRate = outRate;
    this.inRate = inRate;
    this.target = this.baseTarget = Math.max(64, Math.round(targetFrames));
    let cap = 1;
    const most = Math.max(this.target, Math.round((MAX_TARGET_MS / 1000) * inRate));
    while (cap < Math.max(capacityFrames, 8 * most, 4096)) cap <<= 1;
    this.cap = cap;
    this.l = new Float32Array(cap);
    this.r = new Float32Array(cap);
    this.rateEst = inRate;
    const ms = (this.target * 1000) / inRate;
    this.stats = {
      inFrames: 0, dropped: 0, outFrames: 0, silentFrames: 0, underruns: 0, skipped: 0,
      minRatio: 1, maxRatio: 1, ratio: 1, fill: 0, peak: 0, nonsilentOut: 0,
      gaps: 0, gaps20: 0, gapMs: 0, longestGapMs: 0,
      speed: 1, stretch: 1, minStretch: 1, stretched: 0, splices: 0, targetMs: ms, maxTargetMs: ms,
    };
  }

  // Frames waiting in the buffer.
  available(): number {
    return this.w - this.rd;
  }

  // Room for this many more frames.
  space(): number {
    return this.cap - (this.w - Math.min(this.keep, this.rd));
  }

  // Producer: interleaved 16-bit stereo at `rate` Hz. Returns the frames kept.
  push(lr: Int16Array, rate = this.inRate): number {
    return this.pushFrom(lr, 0, lr.length >> 1, rate);
  }

  // The same for `frames` frames from frame `from` of `lr` on.
  pushFrom(lr: Int16Array, from: number, frames: number, rate = this.inRate): number {
    if (rate !== this.inRate && rate > 0) this.setRate(rate);
    const n = Math.max(0, Math.min(frames, this.space()));
    const mask = this.cap - 1;
    for (let i = 0, k = 2 * from; i < n; ++i, k += 2) {
      const at = (this.w + i) & mask;
      this.l[at] = lr[k] / 32768;
      this.r[at] = lr[k + 1] / 32768;
    }
    this.w += n;
    this.stats.inFrames += n;
    this.stats.dropped += frames - n;
    return n;
  }

  // An AI rate change: the targets keep their length in time.
  private setRate(rate: number): void {
    const k = rate / this.inRate;
    this.target = Math.round(this.target * k);
    this.baseTarget = Math.round(this.baseTarget * k);
    this.rateEst *= k;
    this.inRate = rate;
  }

  // Drops everything buffered (a seek, a reset); the next pull primes again.
  reset(): void {
    this.rd = this.keep = this.w;
    this.primed = false;
    this.fadeLeft = 0;
    this.xfFrom = -1;
    this.hopLeft = HOP;
  }

  // Q5: the game's planned pace (1 = full speed). Below full speed the stretch
  // plays at it from now on (the controller's integral term holds it; the fill
  // trims it); at full speed nothing is forced: the stretch ends as the input
  // keeps up again.
  setPace(speed: number): void {
    const s = Math.max(MIN_SPEED, Math.min(1, speed));
    if (!(s < 0.995)) return;
    if (!this.stretching) {
      this.stretching = true;
      this.ideal = this.rd;
    }
    this.integ = s - 1;
  }

  // A new base target (the page's setting): the current one starts there again.
  setTarget(frames: number): void {
    this.target = this.baseTarget = Math.max(64, Math.round(frames));
    this.sinceChange = 0;
    this.noteTarget();
  }

  private noteTarget(): void {
    const ms = (this.target * 1000) / this.inRate;
    this.stats.targetMs = ms;
    this.stats.maxTargetMs = Math.max(this.stats.maxTargetMs, ms);
  }

  private frameL(p: number): number {
    return this.l[p & (this.cap - 1)];
  }

  private frameR(p: number): number {
    return this.r[p & (this.cap - 1)];
  }

  // The next input frame into the interpolation history, through the
  // time-stretch. False when the buffer has run dry.
  private next(): boolean {
    if (this.hopLeft === 0) this.startHop();
    if (this.rd >= this.w) return false;
    let vl = this.frameL(this.rd), vr = this.frameR(this.rd);
    if (this.xfFrom >= 0) {
      // Cross-fade from the continuation of what played to the splice point's.
      const g = WIN[this.xfAt++];
      vl = vl * g + this.frameL(this.xfFrom) * (1 - g);
      vr = vr * g + this.frameR(this.xfFrom) * (1 - g);
      ++this.xfFrom;
      if (this.xfAt >= XF) this.xfFrom = -1;
    }
    this.hl.copyWithin(0, 1);
    this.hr.copyWithin(0, 1);
    this.hl[3] = vl;
    this.hr[3] = vr;
    ++this.rd;
    --this.hopLeft;
    if (this.stretching) ++this.stats.stretched;
    return true;
  }

  // A new hop: the ideal position moves on by the speed's share of a hop. While
  // the input played as is stays within SEEK of it, nothing changes; further
  // ahead, the input jumps back to the frame near the ideal position whose
  // neighbourhood best matches what would have played next, cross-faded over
  // this hop. The frames a later splice may reach back to stay buffered.
  private startHop(): void {
    this.hopLeft = HOP;
    if (!this.stretching) {
      this.ideal = this.rd;  // as is: the ideal track is the input
      this.keep = this.rd - SEEK;
      return;
    }
    const st = this.stats;
    this.ideal += st.stretch * HOP;
    const centre = Math.floor(this.ideal);
    // Only with the cross-fade's frames (what would play next) buffered, and the last fade done. The
    // position may run ahead of the ideal one by SEEK, less on a low buffer (it would run dry first).
    const tolerance = Math.min(SEEK, Math.max(16, (this.w - this.rd) >> 2));
    if (this.rd - this.ideal <= tolerance || this.xfFrom >= 0 || this.w - this.rd < XF) {
      this.keep = Math.min(this.rd, centre - SEEK);
      return;
    }
    const lo = Math.max(centre - SEEK, this.keep), hi = Math.min(centre + SEEK, this.rd - 1);
    if (hi < lo) {
      this.keep = Math.min(this.rd, centre - SEEK);
      return;
    }
    // Candidates from the ideal position outward: on a periodic sound many match equally well, and the
    // nearest keeps the playback closest to its track.
    let best = Math.min(hi, Math.max(lo, centre)), bestScore = -Infinity;
    for (let d = 0; d <= 2 * SEEK; d += 2) {
      const c = d & 2 ? centre - (d >> 1) - 1 : centre + (d >> 1);
      if (c < lo || c > hi) continue;
      let dot = 0, energy = 1e-9;
      for (let k = 0; k < CORR; k += 2) {  // both channels (a mono sum cancels out on opposite-phase stereo)
        const al = this.frameL(c + k), ar = this.frameR(c + k);
        dot += al * this.frameL(this.rd + k) + ar * this.frameR(this.rd + k);
        energy += al * al + ar * ar;
      }
      const score = dot / Math.sqrt(energy);
      if (score > bestScore * (bestScore > 0 ? 1.001 : 0.999) || bestScore === -Infinity) {
        bestScore = score;
        best = c;
      }
    }
    // The fade starts in what would have played (rd on) and ends in the splice point's continuation.
    this.xfFrom = this.rd;
    this.xfAt = 0;
    this.rd = best;
    ++st.splices;
    this.keep = Math.min(best, centre - SEEK);
  }

  // The playback speed while stretching, from the buffer's fill (a PI
  // controller with a dead zone: nothing changes until the buffer is well under
  // the target), and the input rate for the statistics.
  private steer(n: number): void {
    const st = this.stats;
    const dt = n / this.outRate;
    const inc = st.inFrames - this.lastIn, outc = st.outFrames - this.lastOut;
    this.lastIn = st.inFrames;
    this.lastOut = st.outFrames;
    if (outc > 0) this.rateEst += (1 - Math.exp(-dt / RATE_S)) * ((inc * this.outRate) / outc - this.rateEst);
    st.speed = this.rateEst / this.inRate;
    this.fastFill += (1 - Math.exp(-dt / FAST_S)) * (this.available() - this.fastFill);
    const err = (this.fastFill - this.target) / this.target;
    if (!this.stretching && err < STRETCH_ON) {
      this.stretching = true;
      this.ideal = this.rd;
    }
    if (this.stretching) {
      this.integ = Math.max(MIN_SPEED - 1, Math.min(0, this.integ + KI * err * dt));
      st.stretch = Math.max(MIN_SPEED, Math.min(1, 1 + KP * err + this.integ));
      st.minStretch = Math.min(st.minStretch, st.stretch);
      if (this.integ > -0.003 && err > -0.1) this.stretching = false;
    }
    if (!this.stretching) st.stretch = 1;
  }

  // Fills `outL` and `outR` (same length) at the output rate.
  pull(outL: Float32Array, outR: Float32Array): void {
    const n = outL.length;
    const st = this.stats;
    let have = this.available();
    if (have > SKIP_FACTOR * this.target) {
      const drop = have - this.target;
      this.rd += drop;
      this.keep = this.rd;
      this.ideal = this.rd;
      this.xfFrom = -1;
      st.skipped += drop;
      st.fill = this.target;
      have = this.available();
    }
    const start = this.gapFrom >= 0 ? Math.max(2 * HOP, Math.round(this.baseTarget * RESTART_SHARE)) : this.baseTarget;
    if (!this.primed && have >= start) {
      // Start (or restart) with four real frames of history.
      this.primed = true;
      if (this.gapFrom >= 0) {
        const ms = ((st.outFrames - this.gapFrom) * 1000) / this.outRate;
        ++st.gaps;
        if (ms > 20) ++st.gaps20;
        st.gapMs += ms;
        st.longestGapMs = Math.max(st.longestGapMs, ms);
        this.gapFrom = -1;
      }
      this.pos = 0;
      st.fill = have;
      this.hl.fill(0);
      this.hr.fill(0);
      this.ideal = this.rd;
      this.xfFrom = -1;
      this.hopLeft = HOP;
      this.lastIn = st.inFrames;
      this.lastOut = st.outFrames;
      this.fastFill = have;
      this.stretching = this.integ < -0.003;  // still behind after an underrun: stretch on from here
      for (let k = 0; k < 3; ++k) this.next();
    }
    if (this.primed) {
      const alpha = 1 - Math.exp(-n / (SMOOTH_S * this.outRate));
      st.fill += alpha * (this.available() - st.fill);
      this.steer(n);
      const err = (st.fill - this.target) / this.target;
      st.ratio = this.stretching ? 1 : 1 + Math.max(-MAX_ADJUST, Math.min(MAX_ADJUST, GAIN * err));
      st.minRatio = Math.min(st.minRatio, st.ratio);
      st.maxRatio = Math.max(st.maxRatio, st.ratio);
      // The target comes back down after a quiet stretch.
      this.sinceChange += n;
      if (this.target > this.baseTarget && this.sinceChange >= SHRINK_AFTER_S * this.outRate) {
        this.sinceChange = 0;
        this.target = Math.max(this.baseTarget, this.target - Math.round((SHRINK_MS / 1000) * this.inRate));
        this.noteTarget();
      }
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
        if (!this.next()) {  // ran dry: fade out, wait for the base target again, hold more from now on
          this.primed = false;
          ++st.underruns;
          this.gapFrom = st.outFrames + i;
          this.fadeL = a;
          this.fadeR = b;
          this.fadeLeft = FADE;
          // At its slowest the stretch could not keep up (an emulation under a quarter speed): more buffer would
          // not help. Otherwise (a stall) hold more from now on.
          if (!(this.stretching && st.stretch <= MIN_SPEED))
            this.target = Math.min(Math.round((MAX_TARGET_MS / 1000) * this.inRate),
                                   this.target + Math.round((GROW_MS / 1000) * this.inRate));
          this.stretching = false;  // the integral term stays: the speed it had found
          st.stretch = 1;
          this.xfFrom = -1;
          this.keep = this.rd;
          this.sinceChange = 0;
          this.noteTarget();
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
