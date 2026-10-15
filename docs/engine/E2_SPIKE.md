# E2 spike: translating and compiling the game in the browser

Answers E2 risk #2 of `docs/engine/E0_SURVEY.md` §7: is it viable to translate
the whole DOL to WebAssembly in the player's browser (D2) and compile it there,
what does a cold start cost, and do we need per-unit modules or lazy
translation? Measured 2026-10-14 by `claude-side-e2`. How each number was taken:
`docs/engine/E2_LOG.md`. Nothing measured here (modules, logs, translated code)
left `build/`; only counts, times and hashes are recorded.

## 1. Verdict

**Viable, with a wide margin. One module for the whole DOL, translated at
startup, is enough; per-unit modules and lazy translation are not needed now.**

- **Translation is cheap.** Our own emitter (`engine/translator/wasm_emit.*`, no
  C compiler) turns the whole DOL (24,159 functions, 1,473,997 instructions) into
  one 49.5 MB module in **0.33 s** when the translator itself runs as
  WebAssembly (CFG 0.10 s + emit 0.23 s), plus 0.05 s to read the DOL and
  symbols. The wasm-built and native translators produce byte-identical modules.
- **Compilation is not the bottleneck either.** With V8's defaults (lazy
  compilation, Liftoff first, dynamic tier-up) `new WebAssembly.Module` takes
  **25-45 ms** and instantiation 3 ms; functions compile when first called.
  Even compiling everything eagerly with Liftoff takes 0.22 s (0.85 s on one
  thread).
- **Cold start on this machine: about 0.45 s** from the DOL's bytes to running
  game code. A 4-core laptop at roughly half the single-thread speed should
  stay around 1 s (translation is single-threaded; Liftoff spreads over the
  cores it has).
- **The code is fast.** On the same deterministic boot budget the
  wasm-emitted DOL runs at **946 million guest instructions per second**, 87% of
  native MSVC `/O2` (1,085 M/s) and level with clang `-O1` + `wasm-opt -O3` of
  the C++ emitter's output (938 M/s). The engine's clock charges 243 M
  instructions per second of guest time (E0b), so this is about 4x the
  console's instruction rate with the whole runtime included, and 6x real time
  on this budget, where the idle skip covers the waits.
- **It is exact.** The wasm-emitted DOL boots with the same SDK call log as
  native (sha1 `80d06295...`, 143,011,121 bytes) and identical counters
  (entries, unwinds, resumes, interrupts, DVD, AX, MMIO); lockstep against the
  interpreter from `__start` to the first MMIO access shows zero divergences.
- **The dev path (C++ emitter + Emscripten) is no product route:** 7 minutes
  of compile and link on 28 threads for a 132.5 MB module. It is a good
  reference: same hash, same speed class.

What this does not settle (next steps, §6): Firefox and Safari were not
measured (V8 only, through Node 24.19.0 = V8 13.6); the process holds 365 MiB
after loading; TurboFan's code was slower than Liftoff's on this workload.

## 2. Setup

- Machine: Intel Core i7-14700K (20 cores, 28 threads), 64 GB, Windows 11.
  Other agents shared the machine; every speed number is the minimum of 5 to 7
  runs, and timings still vary by about 10% between batches.
- Toolchain: Emscripten 6.0.12, Node 24.19.0 (V8 13.6.233.17), MSVC (VS 2026)
  for native (`docs/engine/TOOLCHAIN.md`).
- **Boot budget** for every speed number: `mvp-boot run --until none
  --max-entries 1000000000 --max-ticks 2000000000`, from power-on: 2,000,000,009
  counted guest instructions, of which 1,289,777,224 are executed (the rest are
  skipped by the idle skip), 8.23 s of guest time, 491 VI fields, 23,462,170
  function entries, 4,976 thread switches. `--trace off` (new) runs without the
  per-entry trace hook; the time is the host time inside `rt::run`, printed by
  `mvp-boot` (startup excluded).

## 3. Translation

| Whole DOL | CFG | emit | output |
|---|---:|---:|---|
| wasm emitter, translator built with Emscripten, under Node (min of 5) | 0.10 s | 0.23 s | 49.5 MB module |
| wasm emitter, translator native (MSVC, min of 5) | 0.13 s | 0.25 s | the same bytes |
| C++ emitter under Node (dev path) | | 1.9 s | 168 MB of C++, then 122 s em++ at `-j 8` (930 s CPU) and 293 s link + `wasm-opt -O3` |

Inside `mvp-boot-wasm` the whole startup is: read the disc's DOL and
`symbols.txt` 0.05 s, CFG 0.11 s, emit 0.23-0.33 s, compile 25-33 ms,
instantiate 3 ms.

**What the module contains** (second pass of the emitter):

| | |
|---|---|
| wasm functions | 24,177 (+10 in-module helpers): one per function, plus entry stubs and HLE stubs |
| function body size | median 916 bytes, 99th percentile 18 KB, largest 147 KB (3 above 100 KB) |
| code bytes per guest instruction | 33.5 |
| instructions inline | 77.6% (integer ALU, compares, rotates, CR logic, integer and FP loads/stores, FP moves) |
| through the runtime (`rt.exec` = the interpreter's semantics) | 4.8% (FP arithmetic, lmw/stmw, psq_l/st, rare SPRs) |
| control flow | 17.6% |
| functions with a br_table dispatcher | 19,058 (resume labels at every call return force most of them) |
| resume labels | 125,534 |
| register spills / reloads (static) | 857,971 / 774,286 |

For comparison, the C++ emitter's output compiled by clang `-O1` + `wasm-opt -O3`
is 132.5 MB (runtime included; median function 2.3 KB, largest 587 KB).

## 4. Compilation and instantiation (V8, Node 24.19.0)

`engine/tools/wasm_compile_bench.mjs`; each compile gets a distinct trailing
custom section so V8's module cache cannot answer it.

| Module | V8 default (lazy) | eager Liftoff | eager Liftoff, 1 thread | eager TurboFan | eager TurboFan, 1 thread |
|---|---:|---:|---:|---:|---:|
| wasm emitter, 49.5 MB | 25-65 ms | 0.22-0.24 s | 0.85 s | 8.6-8.7 s | 57 s |
| C++ emitter + emcc, 132.5 MB | 79 ms | 0.50 s | | 40.6 s | |

Resident memory after an eager Liftoff compile of the emitter's module: about
350 MB for the Node process; after a lazy compile, about 175-220 MB.

## 5. Execution speed

Boot budget of §2, trace off, host time inside `rt::run`, minimum of 7 runs (5
for the TurboFan row):

| Build | time | guest instructions/s | vs native `/O2` |
|---|---:|---:|---:|
| native MSVC, translated code `/Od` (the `msvc` preset) | 6.56 s | 196 M | 0.18 |
| native MSVC, translated code `/O2` | 1.19 s | 1,085 M | 1.00 |
| C++ emitter + em++ `-O1` + `wasm-opt -O3`, V8 default | 1.38 s | 938 M | 0.86 |
| **wasm emitter, V8 default** (Liftoff, dynamic tier-up) | **1.36 s** | **946 M** | **0.87** |
| wasm emitter, Liftoff only | 1.38 s | 932 M | 0.86 |
| wasm emitter, TurboFan only (eager; 11.9 s synchronous compile first) | 2.17 s | 594 M | 0.55 |
| wasm emitter, every non-branch instruction through the runtime | 8.47 s | 152 M | 0.14 |

With the trace hook on (30 million entries, each decoding its call site, and
the 143 MB SDK log hashed) all fast builds land at 4.9-5.5 s and the hook
dominates; every one of them produces the SDK log hash `80d06295...`.

Observations:
- Our emitter, with no optimizer behind it, matches clang + Binaryen on this
  workload. The share of the time spent in the runtime (hardware model,
  scheduler, HLE) rather than in translated code was not profiled; it bounds
  what better code can gain.
- Inlining matters: the helper-only mode is 6.2x slower. The first emitter
  pass (69% inline) was not timed with `--trace off`; the second pass moved FP
  loads and stores inline.
- V8's TurboFan made this code slower than Liftoff. A likely cause is the shape
  of our functions (a deep nest of blocks per function, up to ~50 live locals
  across every merge), but it was not investigated. V8's default dynamic
  tiering loses nothing here, since it starts every function in Liftoff.
  **Corrected by E2d (`docs/engine/E2D_LOG.md` §5):** TurboFan's code is not
  slower. With `--no-liftoff` V8 still compiles lazily, so every function's
  first call runs a synchronous TurboFan compile inside the timed run (5.3 s on
  this budget); compiled eagerly (`--no-wasm-lazy-compilation --no-liftoff`,
  compile outside the timing) TurboFan's code is 10-15% faster than Liftoff's
  (boot budget 0.999 s against 1.150 s, after E2d).
- The idle skip makes this budget mostly real game code: 8.23 s of guest time
  in 1.36 s of host time is about 6x real time, before rendering and audio.

## 6. Risk #2: answers and what is left

| Question | Answer |
|---|---|
| Is in-browser translation plus compilation viable? | Yes. 0.33 s to translate the whole DOL inside wasm, 25-45 ms to compile lazily, 0.22 s if everything is compiled with Liftoff up front |
| Cold-start cost | About 0.45 s here from the DOL's bytes to running code (plus reading the DOL from the player's disc image). Expected about 1 s on a 4-core laptop |
| Per-unit modules or lazy translation? | Not needed. A single module is translated and accepted fast enough that splitting buys nothing yet. Keep them as fallbacks if Safari or Firefox compile far slower, or if memory becomes the limit |
| Code quality without LLVM | Level with clang `-O1` + `wasm-opt -O3` on the boot budget, 87% of native `/O2` |
| Should the translated module be cached (D2)? | Optional for speed: re-translating costs about 0.35 s. Caching the bytes in OPFS mainly saves the work on weak devices; browsers do not cache code compiled from generated bytes, so V8 recompiles lazily either way |

**Left open (next steps, in order):**
1. **A browser page.** Run the translator and the runtime in a Worker of a real
   page (synchronous `WebAssembly.Module` is limited to 8 MB on Chrome's main
   thread; a Worker or `WebAssembly.compile` avoids it), the disc picked by the
   player, and measure Chrome, Firefox and Safari. This is E2 risk #3 (engine
   differences: JSC with 24,000 functions and tail calls, SpiderMonkey's tiers).
2. **Profile the split** between translated code and the runtime on the boot
   budget before optimizing either.
3. **Inline the rest:** FP arithmetic through in-module calls into the integer
   softfloat (or an exact fast path), lmw/stmw unrolled, psq_l/psq_st for the
   common GQR types. 4.8% of instructions still call the interpreter.
   *Done in E2d* (`E2D_LOG.md`): exact inline fast paths, 130 instructions left
   to the runtime.
4. **Smaller modules:** about 11 MB are spills and reloads (share them per call
   site group, or keep fewer registers live across calls), and each memory
   access carries a 6-byte PC constant and a ticks expression only its slow
   path uses.
5. **TurboFan:** find out why its code is slower here before relying on tier-up
   in other engines. *Answered in E2d:* it was lazy compilation in the timed
   run, not the code (above).
6. **Memory:** the process holds 365 MiB after loading; the module bytes (49.5 MB)
   and the CFG can be released after instantiation.
