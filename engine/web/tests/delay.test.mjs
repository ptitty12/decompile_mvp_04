// Q5: the automatic input delay (src/delay.ts), data-free: E5's rule of thumb
// (D x 18 ms covers the one-way latency plus about 10 ms, plus the jitter) on
// round trips measured page to page, between 2 and 6.
import assert from 'node:assert/strict';
import { test } from 'node:test';
import { load } from './site.mjs';

const { chooseDelay, FRAME_MS, OVERHEAD_MS } = await load('delay.js');

const around = (ms, spread, n = 20) => Array.from({ length: n }, (_, k) => ms + (spread * k) / (n - 1));

test('a local link: the smallest delay, 2 (E5 measured full speed with it)', () => {
  const c = chooseDelay(around(0.6, 1.5));
  assert.equal(c.delay, 2);
  assert.equal(c.samples, 20);
  assert.ok(c.rttMs > 0.6 && c.rttMs < 2.2);
});

test('E5\'s simulated slow network (40-50 ms one way): 4, as measured (3 waited at times, 4 hardly)', () => {
  // Each page delays its datagrams by 40 ms plus up to 10 ms: round trips 80-100 ms.
  const c = chooseDelay(around(80, 20));
  assert.equal(c.delay, 4);
  assert.ok(c.needMs > 3 * FRAME_MS && c.needMs <= 4 * FRAME_MS, `need ${c.needMs}`);
});

test('the rule: D frames cover half the round trip, the overhead and the one-way jitter', () => {
  for (const [rtt, spread, want] of [[20, 2, 2], [40, 4, 2], [50, 2, 3], [60, 10, 3], [90, 0, 4], [100, 30, 5], [150, 0, 5], [180, 40, 6]]) {
    const c = chooseDelay(around(rtt, spread));
    const need = c.rttMs / 2 + OVERHEAD_MS + c.jitterMs;
    assert.equal(c.delay, Math.max(2, Math.min(6, Math.ceil(need / FRAME_MS))), `rtt ${rtt} +${spread}`);
    assert.equal(c.delay, want, `rtt ${rtt} +${spread}: ${JSON.stringify(c)}`);
  }
});

test('outliers: the median and the 90th percentile, not the worst ping', () => {
  const v = around(10, 2);
  v[3] = 400;  // one ping stuck behind something
  assert.equal(chooseDelay(v).delay, 2);
});

test('never above 6, never below 2; too few answers: no choice (the page keeps 3)', () => {
  assert.equal(chooseDelay(around(600, 100)).delay, 6);
  assert.equal(chooseDelay(around(0, 0)).delay, 2);
  assert.equal(chooseDelay([1, 2, 3]), null);
  assert.equal(chooseDelay([1, 2, NaN, -1, Infinity, 3, 4]), null);
  assert.equal(chooseDelay([1, 2, 3, 4, 5]).delay, 2);
});
