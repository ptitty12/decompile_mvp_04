// Summarizes a Chrome performance trace that browser_check.mjs --trace wrote
// (P1, development): where the engine Worker's thread spent its time, from
// V8's sampling profiler, and how busy the GPU process's main thread was.
//
//   node trace_summary.mjs TRACE.json [--top N] [--inclusive NAME,NAME...]
//
// Buckets (self time of each sample's leaf function):
//   translated  the game's code (the module translated in the browser)
//   engine      mvp-web.wasm: runtime, GX processor, renderer, mixer, ...
//   js          JavaScript: the Emscripten glue (WebGPU calls), the shell
//   gc, program, idle   as V8 names them
// With a profiling build (--profiling-funcs, MVP_WEB_NAMES) the functions have
// names; --inclusive adds the inclusive time of the named functions.
import { readFileSync } from 'node:fs';

const args = process.argv.slice(2);
const file = args[0];
const opt = (name, def) => {
  const i = args.indexOf(name);
  return i >= 0 && i + 1 < args.length ? args[i + 1] : def;
};
const top = Number(opt('--top', '40'));
const inclusiveNames = opt('--inclusive', '').split(',').filter(Boolean);

const raw = JSON.parse(readFileSync(file, 'utf8'));
const events = Array.isArray(raw) ? raw : raw.traceEvents;

const threadNames = new Map();
for (const e of events)
  if (e.ph === 'M' && e.name === 'thread_name') threadNames.set(`${e.pid}:${e.tid}`, e.args.name);

// Profiles: a 'Profile' event, then 'ProfileChunk' events with the same id.
const profiles = new Map();
for (const e of events) {
  if (e.name === 'Profile') {
    profiles.set(`${e.pid}:${e.id}`, { pid: e.pid, tid: e.tid, start: e.args.data.startTime, nodes: new Map(),
                                         samples: [], deltas: [] });
  } else if (e.name === 'ProfileChunk') {
    const p = profiles.get(`${e.pid}:${e.id}`);
    if (!p) continue;
    const d = e.args.data;
    for (const n of d.cpuProfile?.nodes ?? []) p.nodes.set(n.id, n);
    p.samples.push(...(d.cpuProfile?.samples ?? []));
    p.deltas.push(...(d.timeDeltas ?? []));
  }
}

function bucketOf(cf) {
  const fn = cf.functionName || '';
  if (fn === '(garbage collector)') return 'gc';
  if (fn === '(program)') return 'program';
  if (fn === '(idle)') return 'idle';
  if (fn === '(root)') return 'root';
  const url = cf.url || '';
  if (url.endsWith('mvp-web.wasm') || url.includes('mvp-web.wasm')) return 'engine';
  if (url.startsWith('wasm://')) return 'translated';
  if (url.endsWith('.js') || url.includes('.js')) return 'js';
  return cf.codeType === 'wasm' || /wasm-function/.test(fn) ? 'wasm?' : 'other';
}

for (const p of profiles.values()) {
  const name = threadNames.get(`${p.pid}:${p.tid}`) ?? `${p.pid}:${p.tid}`;
  if (p.samples.length < 50) continue;
  // Sample times: deltas are per sample (microseconds).
  const self = new Map(), buckets = new Map(), incl = new Map();
  let total = 0;
  for (let i = 0; i < p.samples.length; ++i) {
    const dt = (p.deltas[i + 1] ?? p.deltas[i] ?? 0) / 1000;  // the time until the next sample, ms
    if (dt <= 0 || dt > 50) continue;
    const node = p.nodes.get(p.samples[i]);
    if (!node) continue;
    total += dt;
    const cf = node.callFrame;
    const key = `${cf.functionName || '(anonymous)'} [${bucketOf(cf)}]`;
    self.set(key, (self.get(key) ?? 0) + dt);
    const b = bucketOf(cf);
    buckets.set(b, (buckets.get(b) ?? 0) + dt);
    if (inclusiveNames.length) {
      const seen = new Set();
      for (let n = node; n; n = n.parent !== undefined ? p.nodes.get(n.parent) : null) {
        const f = n.callFrame.functionName;
        for (const want of inclusiveNames)
          if (f && f.includes(want) && !seen.has(want)) {
            seen.add(want);
            incl.set(want, (incl.get(want) ?? 0) + dt);
          }
      }
    }
  }
  console.log(`\n== thread ${name}: ${p.samples.length} samples, ${total.toFixed(0)} ms`);
  const pct = (v) => `${(100 * v / total).toFixed(1)}%`;
  for (const [b, v] of [...buckets].sort((a, c) => c[1] - a[1])) console.log(`  ${b.padEnd(12)} ${v.toFixed(0).padStart(7)} ms ${pct(v)}`);
  console.log('  top self:');
  for (const [k, v] of [...self].sort((a, c) => c[1] - a[1]).slice(0, top))
    console.log(`    ${pct(v).padStart(6)} ${v.toFixed(0).padStart(6)} ms  ${k}`);
  for (const [k, v] of incl) console.log(`  inclusive ${k}: ${v.toFixed(0)} ms ${pct(v)}`);
}

// The GPU process's main thread: time inside top-level tasks.
for (const [key, name] of threadNames) {
  if (name !== 'CrGpuMain') continue;
  const [pid, tid] = key.split(':').map(Number);
  let busy = 0, first = Infinity, last = 0;
  for (const e of events) {
    if (e.pid !== pid || e.tid !== tid || e.ph !== 'X' || !e.dur) continue;
    if (e.name !== 'ThreadControllerImpl::RunTask' && e.name !== 'RunTask') continue;
    busy += e.dur / 1000;
    first = Math.min(first, e.ts);
    last = Math.max(last, e.ts + e.dur);
  }
  if (busy) console.log(`\n== GPU process main thread: busy ${busy.toFixed(0)} ms of ${((last - first) / 1000).toFixed(0)} ms`);
}
