// The input delay an online game uses, chosen from the link (Q5).
//
// Lockstep (docs/engine/NETPLAY.md section 1) applies the controller sampled at
// frame F to frame F + D on both sides, so the other player's input for a frame
// is needed D frames after it was sampled. Over the network it takes the
// one-way latency, plus the hop between the page and the engine's Worker and up
// to a field's run (about 10 ms), plus whatever the link's jitter adds. E5's
// rule of thumb (E5_LOG.md section 4): D x 18 ms must cover the one-way latency
// plus about 10 ms, plus the jitter; 18 ms is a frame of the game's own pace
// (55.4 frame polls per guest second in the menus).
//
// Before the game starts, each page measures the link over the data channel
// (netplay.ts: about 20 small text pings, which the engine never sees) and picks
// D with chooseDelay(). Each player proposes their D and the session uses the
// larger proposal (HELLO), so both games run with the same D. It is a session
// constant: the engine's determinism does not depend on how it was chosen.
// The lobby's manual choice (2 to 6) overrides it.

export const FRAME_MS = 18;      // a frame of the game's pace
export const OVERHEAD_MS = 10;   // the page-to-Worker hop and a field's run
export const MIN_DELAY = 2;      // E5: D = 2 keeps full speed on a local link; less leaves no room
export const MAX_DELAY = 6;      // the lobby's largest choice

export interface DelayChoice {
  delay: number;
  samples: number;
  rttMs: number;     // the median round trip
  minMs: number;
  jitterMs: number;  // one way: half the spread from the fastest to the 90th percentile round trip
  oneWayMs: number;
  needMs: number;    // what D frames must cover
}

/** The input delay for round trips `rtts` (ms, page to page), or null without enough samples. */
export function chooseDelay(rtts: readonly number[], minSamples = 5): DelayChoice | null {
  const v = rtts.filter((x) => Number.isFinite(x) && x >= 0).sort((a, b) => a - b);
  if (v.length < minSamples) return null;
  const at = (p: number) => v[Math.min(v.length - 1, Math.floor(p * v.length))]!;
  const rtt = at(0.5), min = v[0]!, p90 = at(0.9);
  const oneWay = rtt / 2;
  const jitter = (p90 - min) / 2;
  const need = oneWay + OVERHEAD_MS + jitter;
  const delay = Math.max(MIN_DELAY, Math.min(MAX_DELAY, Math.ceil(need / FRAME_MS)));
  return { delay, samples: v.length, rttMs: rtt, minMs: min, jitterMs: jitter, oneWayMs: oneWay, needMs: need };
}
