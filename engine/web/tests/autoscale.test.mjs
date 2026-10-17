// Q5: the picture's Auto setting and the GPU (src/autoscale.ts), data-free: a
// GPU busy nearly all the time lowers Auto's ceiling one step at a time; it
// rises again only after a hold, while the next scale should fit, with the hold
// doubling when a raise has to be undone.
import assert from 'node:assert/strict';
import { test } from 'node:test';
import { load } from './site.mjs';

const { AutoScale } = await load('autoscale.js');

// Reports every 500 ms for `seconds`: the GPU busy `busy(scale)` of the time at the scale in use (the
// smaller of the ceiling and `wanted`), 30 frames a report.
function run(a, seconds, busy, wanted = 3, t0 = 0) {
  const c = run.c ?? (run.c = { n: 0, ms: 0 });
  let t = t0;
  const scales = [];
  for (; t < t0 + seconds * 1000; t += 500) {
    const scale = Math.min(a.ceiling, wanted);
    c.n += 30;
    c.ms += 500 * Math.min(1, busy(scale));
    a.update(t, c, scale, wanted);
    scales.push(scale);
  }
  return { t, scales };
}

// A GPU like a laptop's integrated one at a high-DPI screen: at 3x always busy, 2x 50 %, 1x 13 %.
const igpu = (s) => ({ 1: 0.13, 2: 0.5, 3: 1.1 })[s];

test('a GPU that cannot keep up at 3x: down to 2x in about two seconds, and it stays there', () => {
  run.c = null;
  const a = new AutoScale();
  const { scales } = run(a, 60, igpu);
  assert.equal(a.ceiling, 2);
  assert.ok(scales.indexOf(2) > 0 && scales.indexOf(2) <= 8, `stepped down after ${scales.indexOf(2)} reports`);
  assert.deepEqual(a.steps.map((s) => [s.from, s.to]), [[3, 2]]);  // 2x at 50 %: 3x would need 113 %, not tried
});

test('a step down counts only once the renderer draws at the new scale', () => {
  run.c = null;
  const a = new AutoScale();
  const c = { n: 0, ms: 0 };
  let t = 0;
  const report = (scale, busy) => {
    t += 500;
    c.n += 30;
    c.ms += 500 * busy;
    return a.update(t, c, scale, 3);
  };
  for (let k = 0; k < 6; ++k) report(3, 1);
  assert.equal(a.ceiling, 2);
  for (let k = 0; k < 8; ++k) report(3, 1);  // the renderer still draws 3x for a while: no second step
  assert.equal(a.steps.length, 1);
  for (let k = 0; k < 8; ++k) report(2, 0.45);
  assert.equal(a.ceiling, 2);
  assert.equal(a.steps.length, 1);
});

test('a fast GPU: Auto keeps 3x', () => {
  run.c = null;
  const a = new AutoScale();
  run(a, 30, (s) => s * 0.1);
  assert.equal(a.ceiling, 3);
  assert.equal(a.steps.length, 0);
});

test('slower still: down to 1x one step at a time; back up when the load goes away, after the hold', () => {
  run.c = null;
  const a = new AutoScale();
  let r = run(a, 10, (s) => s * s * 0.2);  // 1x 20 %, 2x 80 % (fits, just), 3x 180 %
  assert.equal(a.ceiling, 2);
  r = run(a, 10, (s) => s * s * 0.25, 3, r.t);  // 2x 100 %: down again
  assert.equal(a.ceiling, 1);
  const light = (s) => s * s * 0.05;  // 1x 5 %: 2x should take 20 %, 3x 45 %
  r = run(a, 10, light, 3, r.t);  // the hold (20 s) is not over
  assert.equal(a.ceiling, 1);
  r = run(a, 30, light, 3, r.t);  // up one step, then another
  assert.equal(a.ceiling, 3);
  assert.deepEqual(a.steps.map((s) => [s.from, s.to]), [[3, 2], [2, 1], [1, 2], [2, 3]]);
});

test('a raise that has to be undone doubles the hold', () => {
  run.c = null;
  const a = new AutoScale();
  // 3x is too much; 2x looks light enough for 3x by the pixel count (2x 20 % -> 3x predicted 45 %) but is not.
  run(a, 120, (s) => ({ 1: 0.05, 2: 0.2, 3: 1 })[s]);
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
  run(a, 40, (s) => s * 0.1, 1);
  assert.equal(a.ceiling, 3);
  assert.equal(a.steps.length, 0);
  assert.equal(a.update(0, null, 2, 3), 3);
});
