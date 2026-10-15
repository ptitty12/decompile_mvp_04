# E2d log: everything inline, and fast game code in the browser

Working log for E2d (`claude-side-e2d`, 2026-10-14): the WebAssembly emitter
(`engine/translator/wasm_emit.*`, decision E2-W1) inlines floating point, paired
singles, `lmw`/`stmw` and `psq_l`/`psq_st` exactly, takes E3a's floating-point
unavailable exception, and the browser runs game code fast enough for the intro
movie. Background: `docs/engine/E2_SPIKE.md`, `docs/engine/E2_LOG.md`,
`docs/engine/WEB.md`; the FP model: `docs/engine/E0B_LOG.md` (decisions FP1/FP2),
`engine/ppc/fp.h` and E3a's shortcuts (`docs/engine/E3A_LOG.md`, E3a-FP2).

**Exit met:** FP, paired singles, `lmw`/`stmw` and `psq` are inline (130 of the
DOL's 1,473,997 instructions still go to the runtime, none of them FP
arithmetic); zero lockstep divergences and the cross-build digest unchanged and
reproduced through translated code; guest lines equal native at the WEB.md
checkpoints in Chrome and Firefox; the intro movie runs at 1.0x real time paced
and about 2.2x unpaced in Chrome (it ran at 0.26x).

## Status

| # | Step | State |
|---|---|---|
| 1 | FP arithmetic, compares, conversions, paired singles inline (exact fast path + runtime fallback) | Done |
| 2 | `lmw`/`stmw`, `psq_l`/`psq_st` (GQR), SPR moves, `sraw`, `mfmsr`, integer compares inline | Done |
| 3 | E3a semantics in the emitter: floating-point unavailable, `mtspr WPAR` through the runtime | Done |
| 4 | Exactness: digest through translated code, FP differential fuzz, lockstep, guest lines = native | Done |
| 5 | Profile (Node; Chrome and Firefox frame times), speed work, the TurboFan question | Done |
| 6 | Measurements before and after (Node, Chrome, Firefox, module size) | Done |

## How to build and run (agents)

As in `E2_LOG.md` ("How to build and run"): `engine/tools/emsdk.cmd` for the
`emscripten` preset, `engine/tools/msvc.cmd` for `msvc` (native references:
`-DMVP_GAME_OPT=-Od` builds the translated code in about a minute; E3a showed
`/Od` and `/O2` give the same guest state). New development switches:

- `MVP_WASM_NAMES=1` (`mvp-boot-wasm`): the module gets a `name` section, so V8's
  profiler names translated functions and the in-module helpers (`h.rd32`,
  `h.psq_l`, ...). Off by default (the browser module has none).
- `MVP_WASM_EXEC_STATS=1` (`mvp-boot-wasm`): counts `rt.exec` calls (instructions
  or slow paths the module leaves to the interpreter's semantics) by opcode and
  prints them at exit.
- Profiling build: a second Emscripten tree with `--profiling-funcs` so the
  runtime's functions keep their names:
  `cmake -S engine -B build/engine/emscripten-prof -G Ninja -DCMAKE_TOOLCHAIN_FILE=<emsdk>/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DCMAKE_BUILD_TYPE=Release -DMVP_GFX_WEBGPU=ON -DCMAKE_EXE_LINKER_FLAGS=--profiling-funcs`
  (inside `emsdk.cmd`; pass `-DCMAKE_MAKE_PROGRAM` if CMake does not find ninja),
  then `node --cpu-prof --cpu-prof-dir=<scratch> mvp-boot-wasm.js run ...`.
  Profiles hold function names and timings only; they stay in the scratchpad.
- `test_wasm_digest` (Emscripten, data-free): `MVP_FUZZ_STATES=N` and
  `MVP_FUZZ_SEED=X` scale and vary the FP differential fuzz for one-off runs.
- Eager compilation under Node (`--no-wasm-lazy-compilation`): V8 compiles in the
  background and Node exits at once with no output unless the event loop is kept
  alive; `--require` a script holding an interval that calls
  `process.exit(process.exitCode)` once Emscripten has set the exit code.

**Benchmarks** (under Node 24.19.0 = V8 13.6, `mvp-boot-wasm run --until none
--max-entries 1000000000 --trace off --mmio 0`; the minimum of 3-6 runs, the
builds compared interleaved, because other sessions share the machine and move
single runs by 5-10%):
- *boot budget*: `--max-ticks 2000000000` (E2_SPIKE §2: 491 VI fields, 8.23 s of
  guest time, 1.29 billion instructions executed); MEM1 `ba88879f...` before E3a,
  `5d329cb4...` since (native `mvp-boot` and the wasm build agree);
- *movie budget*: `--max-ticks 5300000000` (1,305 VI fields, 21.81 s of guest
  time; the intro movie plays from about field 600); MEM1 `2039587f...` before
  E3a, `11f597ad...` since. The *movie segment* is the difference to
  `--max-ticks 2440000000` (599 fields): 706 fields, 11.77 s of guest time.

## 1. Floating point inline (exact)

`FuncGen::emit_fp` (wasm_emit.cpp, "floating point"; the rules are in the comment
there). FPRs stay in the Cpu struct as raw IEEE bits. Each arithmetic instruction
gets an inline fast path on WebAssembly's f64 arithmetic, taken only where its
result is provably the exact model's (`ppc/fp.h`); anything else calls `rt.exec`
(the interpreter's semantics), which recomputes the whole instruction from the
untouched registers. So the fallback is exact by construction, and the fast path
only has to be exact where it is taken:

- **FPSCR guard:** RN = 0 and NI = 1 (the game's FPSCR after OSInit); anything
  else goes to the runtime.
- **No WebAssembly NaN reaches guest state:** a NaN result (NaN operand or
  invalid operation) goes to the runtime. Only exact bit patterns are stored.
- **Double results** (`fadd`, `fsub`, `fmul`, `fdiv`): the IEEE result; a
  subnormal flushes to a signed zero (NI).
- **Single results:** r = RN53(x) is rounded again by `f32.demote`. That equals
  RN24(x) except when r is a midpoint between two singles that x is not. On a
  midpoint: an exact sum or product is demoted as is (ties to even); otherwise
  TwoSum gives the sum's exact error and r moves one double ulp towards x before
  the demotion; a quotient on a midpoint goes to the runtime. |r| < 2^-126 flushes
  (then |x| < 2^-126 too); |r| = 2^-126 goes to the runtime.
- **Fused multiply-adds:** single: the product a * force25(c) is exact when a has
  at most 27 significant bits (force25(c) has at most 26); else runtime. A product
  that underflowed double goes to the runtime on a midpoint and when it is zero
  (the zero-sum sign rules need the exact product). Double: sig(a) + sig(c) <= 53
  and no underflow of nonzero operands.
- **Exact everywhere, no fallback:** `fcmpu`/`fcmpo`/`ps_cmp*` (IEEE compares),
  `fsel`/`ps_sel` (bit selects), `fctiwz` (`i32.trunc_sat_f64_s` plus the NaN and
  negative-zero rules).
- `frsp`, `fctiw` (with `f64.nearest`), `fres`/`ps_res`, `frsqrte`/`ps_rsqrte`,
  `ps_sum0/1`, `ps_muls0/1`, `ps_madds0/1` follow the same rules.
- `lfs` and `psq_l` float types convert with `f64.promote_f32`, exact for every
  non-NaN single; NaNs keep their payload by the bit formula.
- The runtime fallback (`rt.exec`) runs `ppc::execute_plain`, so since E3a it
  also benefits from E3a's host-double shortcuts in `fp.cpp` (E3a-FP2); the
  emitter's own rules do not depend on them.

The bugs the fuzz found on the way (all fixed): a single fused multiply-add
whose product underflowed double on a midpoint (TwoSum cannot see the product's
error); the same product underflowing to an exact zero with a zero addend (the
sign of a zero sum); `ps_rsqrte` without the NI flush.

## 2. lmw/stmw, psq_l/psq_st, SPR moves, compares

- `lmw`/`stmw`: in-module helpers (`h.lmw`, `h.stmw`) move words between guest
  memory and the Cpu struct's GPRs, with the helper dataflow (dirty sources
  spilled before, written registers reloaded after only when live), so a
  prologue's `stmw` reads no locals and an epilogue's `lmw` reloads nothing. One
  mapped page: direct byte-swapped copies; otherwise word by word through `h.rd32`
  / `h.wr32` (MMIO, page crossings and unmapped pages take the runtime's path).
- `psq_l`/`psq_st` (all forms): in-module helpers on the effective address, the
  GQR read at run time; float types like `lfs`/`stfs` (`double_to_single_ftz` for
  stores), integer types dequantize exactly (`f64.convert_i32_s` times 2^-scale)
  and quantize with `f32.demote` (round to single, subnormals kept), the exact
  power-of-two scale, `i32.trunc_sat` and the type's bounds; a NaN saturates high.
  One mapped page: direct accesses; otherwise element by element through the
  memory helpers, so the write-gather pipe (0xCC008000) and any unmapped region
  (the runtime maps no locked cache) get the same MMIO writes, in the same order,
  as `sem::psq_store`.
- `mfspr`/`mtspr` of every SPR but DEC, the time base and (for `mtspr`) WPAR:
  XER from the SO/CA locals and the Cpu struct, GQRs, SRR0/1, HIDs, ... as plain
  words. `mtspr WPAR` stays in the runtime: since E3a (c26e76cf) `write_spr`
  resets the write-gather pipe there through a hook.
- `mfmsr`, `sraw`, and `cmp`/`cmpi`/`cmpl`/`cmpli` and the record forms' CR0
  (inline LT GT EQ SO instead of a helper call).

Left in the runtime (`rt.exec`): `mtmsr` (the runtime's `msr_changed` hook),
`mftb` and DEC moves (the virtual clock), `icbi`, `mffs`/`mtfs*`/`mcrfs`, byte-
reversed, string and reservation instructions, `mfsr`/`mtsr`: 130 static
instructions. At run time on the movie budget: `mtmsr` 1.19 million calls, `mftb`
154,000, `icbi` 10,000, DEC moves 3,200, and about 1,000 FP slow paths (a NaN, a
quotient on a midpoint, 2^-126 exactly, a double `fmadd` with a long product).

## 3. E3a's floating-point unavailable exception

E3a (180eb0d2) made FPU instructions with MSR[FP] clear raise exception 0x800
before they start, which the OS uses to switch FPU contexts lazily (the root
cause of the movie's specks). The wasm emitter now does the same: a check of
MSR[FP] before an FPU instruction (`rt.fp_unavailable`, a new import calling
`rt::fp_unavailable`, which runs the OS handler to its rfi), with the dirty
registers spilled, the return path checked and the live registers reloaded, as
at a safe point; no tick is counted before it. The checks are placed by a
forward "must" dataflow: MSR[FP] is known set after a checked or executed FPU
instruction until a safe point, a call, `mtmsr` or `sc`, and unknown at entries
and resume labels. That needs fewer checks than the C++ emitter's per-block rule
(the module: 64.5 MB with per-block checks, 62.1 MB with the dataflow) and gives
the same semantics: the exception is taken at the first FPU instruction that runs
with MSR[FP] clear. `WasmEmitOptions::fpu_checks` is off only in
`test_wasm_digest`, whose reference (`execute_plain`) has no check.

`test_wasm_lockstep`, disabled on main at the E3a merge, runs again with E3a's
setup (MSR 0, a handler at 0x800 that sets FP in SRR1): one exception on each
side in each of the three programs, the handler's six instructions interpreted.

## 4. Exactness evidence

- **Semantics digest through translated code** (`test_wasm_digest`, new,
  Emscripten, data-free): test_digest's 217,088 executions (every non-branch
  opcode on random states, edge-case FPRs, random FPSCR and GQRs, aliased RAM with
  page-crossing accesses) replayed through translated code, one `word; blr`
  function each (one 56 MB module). Every execution's state and RAM equal the
  interpreter's (0 differences) and the hash is the constant both builds of
  `test_ppc_digest` print: `e4104538...`. `test_ppc_digest` itself: native MSVC
  and Emscripten pass with the unchanged constants (`e4104538...`,
  `408b94ae...`) after moving its generators to `ppc/tests/digest_gen.h`.
- **FP differential fuzz** (same test): 59 opcodes (FP arithmetic, paired
  singles, psq, lmw/stmw, sraw, SPR moves) x 24 random words x 2,500 states =
  3.54 million executions in ctest, a third of them with constructed operands:
  exact single midpoints, sums and products within less than half a double ulp of
  one (and exactly half), 2^-126, FLT_MAX's binade and the overflow midpoint,
  products that underflow double with zero, tiny or midpoint addends; FPRs from
  singles, small integers, 2^52 + n, subnormals, NaN payloads, infinities; FPSCR
  RN=0/NI=1 three times in four, else random. 0 differences. One-off runs with
  `MVP_FUZZ_STATES=60000`: 84,960,000 executions each (28.3 million with
  constructed operands) under seeds `0x1234567` and `0xBADC0DE5`: 0 differences
  (the first such run, before the last fix, found the zero-product sign case).
- **Lockstep** (`mvp-boot-wasm lockstep`, `MVP_WASM_PRECISE=1`): 153 function
  entries, 219,257 reference instructions, 10 MEM1 comparisons, 0 divergences to
  the first MMIO access (before and after E3a).
- **Guest state on long runs**, before E3a: the boot and movie budgets kept their
  MEM1 (`ba88879f...`, `2039587f...`) through every step, the same as when every
  FP instruction went through the interpreter; Chrome's line at 3,600 fields
  (menus) was native's `95f5c597...`. After E3a: the boot budget `5d329cb4...`
  and the movie budget `11f597ad...` equal native `mvp-boot`; Chrome 155 and
  Firefox 157 (sound on, unpaced) equal native `mvp-play` at all three WEB.md
  checkpoints: 700 fields `73e856d4...`, 2,400 fields (START x4) `c70ca6c5...`,
  3,600 fields (menus) `5e150b6c...` (also paced, and `mvp-boot-wasm` under Node).
- **The translator is deterministic across hosts:** the native (MSVC) and the
  wasm-built `mvp-xlat` write byte-identical modules (SHA-1 `b4c56c75...`).
- Tests: `ctest --preset emscripten -LE local` 29/29; `ctest --preset msvc -LE
  local` 30/30 (one skipped: the server's Node tests).

## 5. Profile and speed work

**Before E2d** (movie budget under Node, V8's profiler with names): 75% of the
time was FP through the interpreter: `fp::round_pack` alone 55%,
`execute_plain`/`decode`/`rt.exec` 11%, `quantize`/`dequantize`/`psq_*` 5%. After
the FP work the movie budget went from 42 s to 6.4 s.

**After** (movie budget): the in-module helpers 37% (`h.psq_l` 12%, `h.psq_st`
11%, `h.rd32` 6%, `h.wr32` 4%), translated code 46% (the VP6 decoder:
`FilterBlock2dBil_GC`, `VP6_DecodeBlock`, `ScalarReconInter_GC`, ...), the
runtime 12% (half of it the translator's own startup), the `rt` imports 3%. The
main menu (the last 4 s of the menus run): `FONT_findkern12` 21% (a linear search
of the kerning table per glyph pair: an `lhzx`, two compares and a back edge per
pair), `h.rd16` 11%, `h.rd32` 9%, `h.wr32` 5%, the runtime's hardware model
about 15% (`Hardware::write`, `gp_run`, `pi_cause`, `gp_distance`, `wgp_burst`),
`Sha1::block` 2.5%.

**What was done** (each measured against the previous build, minimum of
interleaved runs):

| Change | Effect |
|---|---|
| FP, paired singles, psq, lmw/stmw, SPR moves inline (§1, §2) | movie budget 44.2 -> 6.9 s; boot 1.39 -> 1.27 s |
| `psq` helpers: one page lookup per access, direct loads; `s2d` by `f64.promote_f32` | in the profile (h.rd8 calls gone) |
| integer compares inline | 3-4% on both budgets, +1.6 MB |
| loops without inner labels: their own wasm `loop`, a direct `br` back | movie budget 6.87 -> 6.21 s; boot unchanged |
| prologue: the return-path check only after the hook or the safe point ran | about 1% |
| MSR[FP] checks by dataflow (§3) | -2.4 MB against per-block checks; speed within noise |

**Tried and dropped:** inline fast paths for every integer and FP load and
store (page lookup and byte swap in place, the helper only on the slow path):
the module grew from 57 to 103 MB with no measurable gain, compiled lazily or
eagerly. Calls to the small `h.rd*`/`h.wr*` helpers are not where the time goes.

**The TurboFan question** (E2_SPIKE §6 item 5). Boot budget, minimum of 2:

| V8 mode (Node) | before E2d | after E2d |
|---|---:|---:|
| default: lazy Liftoff, dynamic tier-up | 1.38 s | 1.31 s |
| `--liftoff-only` (the runtime's own module too) | 3.25 s | 2.49 s |
| `--no-liftoff` (lazy TurboFan) | 5.33 s | 6.21 s |
| eager TurboFan (`--no-wasm-lazy-compilation --no-liftoff`) | 1.19 s | **1.00 s** |
| eager Liftoff, tier-up on | 1.31 s | 1.17 s |
| eager Liftoff, tier-up off | 1.33 s | 1.15 s |

TurboFan's code is not slower: it is 10-15% faster than Liftoff's (boot budget
1.00 s against 1.15 s; movie budget 6.58 s against 7.20 s). E2_SPIKE's
observation came from compilation inside the timed run: `--no-liftoff` still
compiles lazily, so each function's first call runs a synchronous TurboFan
compile. The default mode also pays lazy Liftoff compilation inside the run
(about 0.15 s on the boot budget) and tiers up gradually. In the browser this is
a one-time cost per session; nothing on the page can force eager tier-up.

**What is left** (in order of expected gain): `psq` inline at its 730 sites with
the GQR index constant (the helpers are 23% of the movie budget); structured
multi-block loops, so back edges of loops with inner labels (the kerning search)
skip the dispatcher too; `mtmsr` through a dedicated import instead of
`rt.exec` (1.2 million calls on the movie budget); on the runtime side (E3a's
area) the hardware model's register paths in the menus.

## 6. Measurements

**Node** (minimum of interleaved runs; before = `origin/main` 45de368e, the E2c
merge, without E2d; after = this branch with E3a):

| | before | after |
|---|---:|---:|
| boot budget: time in `rt::run` | 1.377 s | 1.244 s |
| boot budget: guest instructions executed per second | 937 M | 1,037 M |
| movie budget (1,305 fields) | 41.9 s | 6.15 s |
| movie segment (706 fields, 11.77 s guest) | 39.8 s (0.30x real time) | 4.45 s (2.65x) |
| eager TurboFan, boot budget | 1.19 s | 1.00 s (1,291 M/s) |

**Browsers** (the menus script, 3,600 fields, E2c's client with sound on,
`--no-cache`; host ms per field; WEB.md §3 "Frame time, E2d" has every scene):

| | Chrome 155 before | Chrome after | Firefox 157 before | Firefox after |
|---|---:|---:|---:|---:|
| intro movie, paced | 60.4 ms (15.8 fields/s) | **7.0 ms (60/s)** | 53.7 ms (17.8/s) | **7.2 ms (60/s)** |
| intro movie, unpaced | 0.25x real time | **2.26x** | (disturbed run) | **2.14x** |
| main menu, paced | 9.1 ms | **5.0 ms** | 8.1 ms | **5.6 ms** |
| main menu, unpaced | 1.79x | 3.31x | (disturbed run) | 2.96x |
| audio underruns in the movie | 107 | 0 | 106 | 0 |

**Module and translation** (whole DOL):

| | before | after |
|---|---:|---:|
| module bytes | 49,468,954 | 62,141,945 |
| instructions inline / runtime / control | 1,143,689 / 70,202 / 260,106 | 1,213,761 / 130 / 260,106 |
| spills / reloads (static) | 857,971 / 774,286 | 919,524 / 901,866 |
| emit (Chrome; Node `mvp-xlat`) | 275-295 ms; 296 ms | 340-360 ms; 344 ms |
| compile: V8 lazy; Firefox | 16-21 ms; 122 ms | 19-21 ms; 180-240 ms |
| cold start, Chrome (pick -> first frame) | 685-730 ms | 760-810 ms |

The module grew by 12.7 MB: the FP fast paths and their runtime fallbacks (about
7.6 MB), the MSR[FP] checks and the spills and reloads they force (2.9 MB), the
inline compares (1.6 MB) and the prologue (0.5 MB).

## Decisions to record (for the lead)

- E2-W6 (E2d): the wasm emitter computes floating point inline on IEEE f64
  arithmetic only where the result is provably the exact model's (FPSCR RN=0 and
  NI=1; no WebAssembly-made NaN ever stored; single results not on an unresolved
  midpoint; exact products for fused multiply-adds), else the whole instruction
  goes through `rt.exec`. Proven by the semantics digest through translated code
  and the edge-case fuzz (`test_wasm_digest`).
- E2-W7 (E2d): the wasm emitter takes E3a's floating-point unavailable exception
  with checks placed by a must-dataflow on MSR[FP] (fewer than the C++ emitter's
  per-block checks, same semantics).

## Next step

1. Merge `engine/e2d` (E2d's exit is met; guest lines equal native in Chrome and
   Firefox).
2. If more browser speed is wanted: the items in §5 "What is left", then a Chrome
   performance trace of the menus (this log's profiles are Node's).
3. Safari with WebGPU still needs a Mac (WEB.md §5).
