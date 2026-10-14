// Development tool (E2): how long V8 takes to compile a WebAssembly module.
//
//   node [V8 flags] engine/tools/wasm_compile_bench.mjs <module.wasm> [runs]
//
// Useful V8 flags (Node passes them through):
//   (none)                                        V8's default (lazy compilation, Liftoff, tier-up)
//   --no-wasm-lazy-compilation --liftoff --no-wasm-tier-up   eager Liftoff only (baseline compiler)
//   --no-wasm-lazy-compilation --no-liftoff                  eager TurboFan only (optimizing compiler)
//
// Prints the module size, the time of a synchronous new WebAssembly.Module (which
// also reports a validation error) and of WebAssembly.compile (async, what a
// browser page would use), and the resident memory after each. Every compile
// gets a distinct trailing custom section, so V8's module cache cannot serve a
// compile from an earlier one. The module stays where it is (under build/).
import { readFileSync } from 'node:fs';
import { performance } from 'node:perf_hooks';

const path = process.argv[2];
const runs = Number(process.argv[3] ?? 3);
if (!path) {
  console.error('usage: node [v8 flags] wasm_compile_bench.mjs <module.wasm> [runs]');
  process.exit(2);
}
const original = readFileSync(path);
// The module plus a custom section "run<n>" (ignored by the engine).
function variant(n) {
  const name = Buffer.from(`run${n}`);
  const body = Buffer.concat([Buffer.from([name.length]), name]);
  return Buffer.concat([original, Buffer.from([0, body.length]), body]);
}
const bytes = original;
const mib = (n) => (n / (1024 * 1024)).toFixed(1);
console.log(`module ${path}: ${mib(bytes.length)} MiB`);
console.log(`flags: ${process.execArgv.join(' ') || '(V8 defaults)'}`);
// V8's background compile jobs do not keep Node's event loop alive.
const keepalive = setInterval(() => {}, 1000);
for (let k = 0; k < runs; ++k) {
  let t0 = performance.now();
  let m2;
  try {
    m2 = new WebAssembly.Module(variant(2 * k));
  } catch (e) {
    console.log(`invalid module: ${e.message}`);
    process.exit(1);
  }
  const syncMs = performance.now() - t0;
  const rss2 = process.memoryUsage().rss;
  t0 = performance.now();
  const m1 = await WebAssembly.compile(variant(2 * k + 1));
  const asyncMs = performance.now() - t0;
  const rss1 = process.memoryUsage().rss;
  console.log(`run ${k}: sync compile ${syncMs.toFixed(0)} ms (rss ${mib(rss2)} MiB), ` +
              `async compile ${asyncMs.toFixed(0)} ms (rss ${mib(rss1)} MiB)`);
  void m1;
  void m2;
}
clearInterval(keepalive);
