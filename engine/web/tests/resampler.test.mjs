// The AudioWorklet's drift resampler (src/resampler.ts), data-free: 32 kHz in,
// 48 kHz out, bursty input at the Worker's pace, clock drift, underruns,
// catching up, and the pitch of a tone; Q2: an emulation that runs behind is
// time-stretched (no underruns, the same pitch), a stall raises the target.
import assert from 'node:assert/strict';
import { test } from 'node:test';
import { load } from './site.mjs';

const { DriftResampler } = await load('resampler.js');

const IN = 32000, OUT = 48000, QUANTUM = 128;

// A sine at `hz`, as interleaved 16-bit stereo, continuing from `phase`.
function sine(frames, hz, state) {
  const out = new Int16Array(2 * frames);
  for (let i = 0; i < frames; ++i) {
    const v = Math.round(16000 * Math.sin(2 * Math.PI * hz * (state.n++ / IN)));
    out[2 * i] = v;
    out[2 * i + 1] = -v;
  }
  return out;
}

// Runs `seconds` of audio-device time: the device pulls 128-frame quanta at
// OUT Hz; the producer delivers its frames in bursts of one 16.7 ms field (the
// Worker's batches), at `inHz` (the guest's clock as the device sees it).
function simulate(rs, seconds, { inHz = IN, hz = 1000, burstFields = 1, stopAt = Infinity, stall = null } = {}) {
  const state = { n: 0 };
  const L = new Float32Array(QUANTUM), R = new Float32Array(QUANTUM);
  const collected = [];
  let produced = 0;
  const fieldS = 1 / 59.94;
  let nextBurst = 0;
  const quanta = Math.round((seconds * OUT) / QUANTUM);
  for (let q = 0; q < quanta; ++q) {
    const t = (q * QUANTUM) / OUT;
    while (t >= nextBurst && t < stopAt && !(stall && t >= stall[0] && t < stall[1])) {
      const due = Math.round((nextBurst + burstFields * fieldS) * inHz) - produced;
      rs.push(sine(due, hz, state), IN);
      produced += due;
      nextBurst += burstFields * fieldS;
    }
    rs.pull(L, R);
    collected.push(Float32Array.from(L));
  }
  const all = new Float32Array(collected.length * QUANTUM);
  collected.forEach((c, k) => all.set(c, k * QUANTUM));
  return all;
}

// Rising zero crossings per second over a stretch of output.
function frequency(samples, from, to) {
  let crossings = 0;
  for (let i = from + 1; i < to; ++i) if (samples[i - 1] < 0 && samples[i] >= 0) ++crossings;
  return crossings / ((to - from) / OUT);
}

test('steady state: no underruns after priming, the tone keeps its pitch at 48 kHz', () => {
  const rs = new DriftResampler(OUT, IN, 0.06 * IN);
  const out = simulate(rs, 10);
  assert.equal(rs.stats.underruns, 0);
  assert.equal(rs.stats.skipped, 0);
  assert.equal(rs.stats.dropped, 0);
  const f = frequency(out, 2 * OUT, 10 * OUT);
  assert.ok(Math.abs(f - 1000) < 6, `1 kHz came out at ${f.toFixed(1)} Hz`);
  assert.ok(rs.stats.peak > 0.45 && rs.stats.peak <= 0.5, `peak ${rs.stats.peak}`);
  // The buffer holds about the target (within one burst).
  assert.ok(Math.abs(rs.stats.fill - rs.target) < 600, `fill ${rs.stats.fill}, target ${rs.target}`);
});

test('drift: a guest clock 0.3 % fast or slow is absorbed without underruns or skips', () => {
  for (const inHz of [IN * 1.003, IN * 0.997]) {
    const rs = new DriftResampler(OUT, IN, 0.06 * IN);
    simulate(rs, 30, { inHz });
    assert.equal(rs.stats.underruns, 0, `inHz ${inHz}`);
    assert.equal(rs.stats.skipped, 0, `inHz ${inHz}`);
    const expect = inHz / IN;
    assert.ok(Math.abs(rs.stats.ratio - expect) < 0.0015, `ratio ${rs.stats.ratio} for ${expect}`);
    assert.ok(Math.abs(rs.stats.fill - rs.target) < 0.5 * rs.target, `fill ${rs.stats.fill}`);
  }
});

test('bursts of three fields (slow animation frames) play without underruns at a 60 ms target', () => {
  const rs = new DriftResampler(OUT, IN, 0.06 * IN);
  simulate(rs, 10, { burstFields: 3 });
  assert.equal(rs.stats.underruns, 0);
});

test('underrun: the output fades to silence, then plays again once the target is buffered', () => {
  const rs = new DriftResampler(OUT, IN, 0.06 * IN);
  const out = simulate(rs, 4, { stopAt: 2 });  // the producer stops at 2 s
  assert.equal(rs.stats.underruns, 1);
  // The tail is silent, and the fade has no step larger than the signal's own.
  const tail = out.subarray(3 * OUT);
  assert.ok(tail.every((v) => v === 0));
  let maxStep = 0;
  for (let i = 2 * OUT; i < 3 * OUT; ++i) maxStep = Math.max(maxStep, Math.abs(out[i] - out[i - 1]));
  assert.ok(maxStep < 0.1, `largest step ${maxStep}`);
  // Refill: plays again (once half the target is there).
  const state = { n: 0 };
  rs.push(sine(Math.round(0.04 * IN), 1000, state), IN);
  const L = new Float32Array(QUANTUM), R = new Float32Array(QUANTUM);
  rs.pull(L, R);
  assert.ok(L.some((v) => v !== 0));
});

test('far ahead: more than 4 x the target is skipped down to the target; a full buffer drops', () => {
  const rs = new DriftResampler(OUT, IN, 0.06 * IN, 32768);
  const state = { n: 0 };
  const kept = rs.push(sine(5 * rs.target, 440, state), IN);
  assert.equal(kept, 5 * rs.target);
  const L = new Float32Array(QUANTUM), R = new Float32Array(QUANTUM);
  rs.pull(L, R);
  assert.equal(rs.stats.skipped, 5 * rs.target - rs.target);
  assert.ok(rs.available() <= rs.target);
  // (The capacity is at least 8 x the largest target, 200 ms since Q2: 65,536 frames here.)
  const space = rs.space();
  assert.ok(space >= 65536 - rs.available() - 256, `space ${space}`);
  const big = rs.push(sine(80000, 440, state), IN);
  assert.equal(big, space);
  assert.equal(rs.stats.dropped, 80000 - big);
});

test('rate: input at 48 kHz (an AI rate change) plays at its own pitch', () => {
  const rs = new DriftResampler(OUT, IN, 0.06 * IN);
  const state = { n: 0 };
  // 1 kHz at a 48 kHz input rate: as frames, a 1000 * 32000 / 48000 Hz sine at IN.
  const L = new Float32Array(QUANTUM), R = new Float32Array(QUANTUM);
  const out = [];
  for (let k = 0; k < 400; ++k) {
    rs.push(sine(QUANTUM, (1000 * IN) / 48000, state), 48000);
    rs.pull(L, R);
    out.push(...L);
  }
  assert.equal(rs.inRate, 48000);
  const f = frequency(Float32Array.from(out), 100 * QUANTUM, 400 * QUANTUM);
  assert.ok(Math.abs(f - 1000) < 15, `${f}`);
});

test('Q2: at full speed nothing is stretched (the input plays as is)', () => {
  const rs = new DriftResampler(OUT, IN, 0.06 * IN);
  simulate(rs, 20, { burstFields: 2 });
  assert.equal(rs.stats.underruns, 0);
  assert.equal(rs.stats.stretched, 0);
  assert.equal(rs.stats.splices, 0);
  assert.ok(Math.abs(rs.stats.speed - 1) < 0.01, `speed ${rs.stats.speed}`);
});

test('Q2: an emulation at 0.97x, 0.8x, 0.6x and 0.35x plays on, stretched, at the same pitch', () => {
  for (const k of [0.97, 0.8, 0.6, 0.35]) {
    const rs = new DriftResampler(OUT, IN, 0.06 * IN);
    const out = simulate(rs, 30, { inHz: IN * k, burstFields: 2 });
    // (Dropping to 0.6x or below at once can empty the 60 ms buffer a few times before the speed has settled.)
    assert.ok(rs.stats.underruns <= (k < 0.7 ? 3 : 0), `${k}x: ${rs.stats.underruns} underruns`);
    if (k < 0.7) assert.ok(rs.stats.gapMs < (k < 0.5 ? 200 : 50), `${k}x: ${rs.stats.gapMs} ms of silence`);
    assert.ok(Math.abs(rs.stats.stretch - k) < 0.03, `${k}x: stretch ${rs.stats.stretch}`);
    assert.ok(rs.stats.splices > 0);
    const f = frequency(out, 10 * OUT, 30 * OUT);
    assert.ok(Math.abs(f - 1000) < 25, `${k}x: 1 kHz came out at ${f.toFixed(1)} Hz`);  // splices add a few crossings
    // No silence once playing, and no clicks: no step larger than the tone's own (2 pi 1000 / 48000 x 0.49).
    let maxStep = 0;
    for (let i = 2 * OUT; i < 30 * OUT; ++i) maxStep = Math.max(maxStep, Math.abs(out[i] - out[i - 1]));
    assert.ok(maxStep < 0.08, `${k}x: largest step ${maxStep}`);
    let silent = 0;
    for (let i = 2 * OUT; i < 30 * OUT; ++i) if (out[i] === 0 && out[i - 1] === 0) ++silent;
    assert.ok(silent < 0.001 * 28 * OUT, `${k}x: ${silent} silent samples`);
  }
});

test('Q2: a jittery producer at full speed (batches of 1 to 4 fields) plays without underruns', () => {
  const rs = new DriftResampler(OUT, IN, 0.06 * IN);
  const state = { n: 0 };
  const L = new Float32Array(QUANTUM), R = new Float32Array(QUANTUM);
  let seed = 12345, produced = 0, next = 0;
  const rnd = () => ((seed = (seed * 1103515245 + 12345) & 0x7fffffff) / 0x7fffffff);
  for (let q = 0; q < (20 * OUT) / QUANTUM; ++q) {
    const t = (q * QUANTUM) / OUT;
    if (t >= next) {
      next += (1 + Math.floor(rnd() * 4)) / 59.94;
      const due = Math.round(next * IN) - produced;
      rs.push(sine(due, 500, state), IN);
      produced += due;
    }
    rs.pull(L, R);
  }
  assert.equal(rs.stats.underruns, 0);
});

test('Q2: a stall of 300 ms underruns once, plays again 30 ms later, raises the target 20 ms, 10 ms back per 30 s', () => {
  const rs = new DriftResampler(OUT, IN, 0.06 * IN);
  simulate(rs, 4, { stall: [2, 2.3] });
  assert.equal(rs.stats.underruns, 1);
  assert.equal(rs.stats.gaps, 1);
  assert.ok(Math.abs(rs.stats.targetMs - 80) < 0.5, `target ${rs.stats.targetMs} ms`);
  const rs2 = new DriftResampler(OUT, IN, 0.06 * IN);
  simulate(rs2, 40, { stall: [2, 2.3] });
  assert.equal(rs2.stats.underruns, 1);
  assert.ok(Math.abs(rs2.stats.targetMs - 70) < 0.5, `target ${rs2.stats.targetMs} ms after 38 quiet seconds`);
  // The silence was the stall (300 ms less the 60 ms buffered) and the 30 ms restart, not a whole buffer more.
  assert.ok(rs2.stats.gapMs < 300 - 60 + 30 + 10, `silence ${rs2.stats.gapMs} ms`);
});

test('Q2: input pushed from an offset (the shared-memory ring) equals the same input pushed whole', () => {
  const a = new DriftResampler(OUT, IN, 0.06 * IN), b = new DriftResampler(OUT, IN, 0.06 * IN);
  const state = { n: 0 };
  const src = sine(4000, 700, state);
  a.push(src.subarray(2000), IN);
  b.pushFrom(src, 1000, 3000, IN);
  const La = new Float32Array(QUANTUM), Ra = new Float32Array(QUANTUM), Lb = new Float32Array(QUANTUM), Rb = new Float32Array(QUANTUM);
  for (let k = 0; k < 10; ++k) {
    a.pull(La, Ra);
    b.pull(Lb, Rb);
    assert.deepEqual(Lb, La);
  }
});
