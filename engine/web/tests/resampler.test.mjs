// The AudioWorklet's drift resampler (src/resampler.ts), data-free: 32 kHz in,
// 48 kHz out, bursty input at the Worker's pace, clock drift, underruns,
// catching up, and the pitch of a tone.
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
function simulate(rs, seconds, { inHz = IN, hz = 1000, burstFields = 1, stopAt = Infinity } = {}) {
  const state = { n: 0 };
  const L = new Float32Array(QUANTUM), R = new Float32Array(QUANTUM);
  const collected = [];
  let produced = 0;
  const fieldS = 1 / 59.94;
  let nextBurst = 0;
  const quanta = Math.round((seconds * OUT) / QUANTUM);
  for (let q = 0; q < quanta; ++q) {
    const t = (q * QUANTUM) / OUT;
    while (t >= nextBurst && t < stopAt) {
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
  // Refill: plays again.
  const state = { n: 0 };
  rs.push(sine(Math.round(0.07 * IN), 1000, state), IN);
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
  const space = 32768 - rs.available();
  const big = rs.push(sine(40000, 440, state), IN);
  assert.equal(big, space);
  assert.equal(rs.stats.dropped, 40000 - big);
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
