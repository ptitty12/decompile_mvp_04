// Q5: the picture's Auto setting and the GPU (src/autoscale.ts), data-free: a
// GPU whose frames take too long lowers Auto's ceiling one step at a time; it
// rises again only after a hold, while the next scale should fit, with the hold
// doubling when a raise has to be undone.
import assert from 'node:assert/strict';
import { test } from 'node:test';
import { load } from './site.mjs';

const { AutoScale } = await load('autoscale.js');

// Reports every 500 ms for `seconds`, with `gpuMs(scale)` per frame at the scale in use (the smaller of
// the ceiling and `wanted`), 30 probes a report.
function run(a, seconds, gpuMs, wanted = 3, t0 = 0) {
  const counters = run.c ?? (run.c = { n: 0, ms: 0, over: 0 });
  let t = t0;
  const scales = [];
  for (; t < t0 + seconds * 1000; t += 500) {
    const scale = Math.min(a.ceiling, wanted);
    const ms = gpuMs(scale);
    counters.n += 30;
    counters.ms += 30 * ms;
    counters.over += ms > 14 ? 30 : 0;
    a.update(t, counters, scale, wanted);
    scales.push(scale);
  }
  return { t, scales };
}

// A GPU like a laptop's integrated one at a high-DPI screen: 3x takes 20 ms a frame, 2x 9, 1x 2.3.
const igpu = (s) => ({ 1: 2.3, 2: 9, 3: 20 })[s];

test('a GPU that cannot keep up at 3x: down to 2x in about two seconds, and it stays there', () => {
  run.c = null;
  const a = new AutoScale();
  const { scales } = run(a, 60, igpu);
  assert.equal(a.ceiling, 2);
  assert.ok(scales.indexOf(2) > 0 && scales.indexOf(2) <= 8, `stepped down after ${scales.indexOf(2)} reports`);
  assert.deepEqual(a.steps.map((s) => [s.from, s.to]), [[3, 2]]);  // 2x at 9 ms: 3x would need 20, not tried again
});

test('a fast GPU: Auto keeps 3x', () => {
  run.c = null;
  const a = new AutoScale();
  run(a, 30, (s) => s * 1.2);
  assert.equal(a.ceiling, 3);
  assert.equal(a.steps.length, 0);
});

test('slower still: down to 1x one step at a time; back up when the load goes away, after the hold', () => {
  run.c = null;
  const a = new AutoScale();
  let heavy = true;
  const gpu = (s) => (heavy ? s * s * 3 : s * s * 0.8);  // heavy: 1x 3, 2x 12 (slow at the edge), 3x 27
  let r = run(a, 10, gpu);
  assert.equal(a.ceiling, 2);  // 2x at 12 ms is not over the 12 ms mean, nor over 14
  heavy = true;
  const gpu2 = (s) => s * s * 4;  // 2x 16: slow
  r = run(a, 10, gpu2, 3, r.t);
  assert.equal(a.ceiling, 1);
  heavy = false;
  r = run(a, 10, gpu, 3, r.t);  // the load is gone, but the hold (20 s) is not over
  assert.equal(a.ceiling, 1);
  r = run(a, 30, gpu, 3, r.t);  // 1x 0.8 ms: 2x should take 3.2, 3x 7.2: up one step, then another
  assert.equal(a.ceiling, 3);
  assert.deepEqual(a.steps.map((s) => [s.from, s.to]), [[3, 2], [2, 1], [1, 2], [2, 3]]);
});

test('a raise that has to be undone doubles the hold', () => {
  run.c = null;
  const a = new AutoScale();
  // 3x is slow; 2x looks fast enough for 3x by the pixel count (2x 3.5 ms -> 3x predicted 7.9) but is not.
  const gpu = (s) => ({ 1: 1, 2: 3.5, 3: 18 })[s];
  run(a, 120, gpu);
  const downs = a.steps.filter((s) => s.to < s.from).map((s) => s.at);
  const ups = a.steps.filter((s) => s.to > s.from).map((s) => s.at);
  assert.ok(downs.length >= 3, JSON.stringify(a.steps));
  // Each hold (the time at 2x before trying 3x again, less the 5 s the fit must last) twice the one before:
  // 20 s, 40 s, ...
  const hold = (k) => ups[k] - downs[k] - a.o.upAfterMs;
  assert.ok(ups.length >= 2, JSON.stringify(a.steps));
  assert.ok(Math.abs(hold(0) - 20000) <= 500, JSON.stringify(a.steps));
  for (let k = 1; k < ups.length; ++k) assert.ok(Math.abs(hold(k) - 2 * hold(k - 1)) <= 1000, JSON.stringify(a.steps));
});

test('a window too small for 2x: never above what the size asks for; nothing without GPU reports', () => {
  run.c = null;
  const a = new AutoScale();
  run(a, 40, (s) => s, 1);
  assert.equal(a.ceiling, 3);
  assert.equal(a.steps.length, 0);
  assert.equal(a.update(0, null, 2, 3), 3);
});
