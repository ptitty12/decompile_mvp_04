# E2d log: everything inline, and fast game code in the browser

Working log for E2d (`claude-side-e2d`, 2026-10-14): the WebAssembly emitter
(`engine/translator/wasm_emit.*`, decision E2-W1) inlines floating point, paired
singles, `lmw`/`stmw` and `psq_l`/`psq_st` exactly, and the browser runs the game
fast enough for the intro movie. Background: `docs/engine/E2_SPIKE.md`,
`docs/engine/E2_LOG.md`, `docs/engine/WEB.md`; the FP model: `docs/engine/E0B_LOG.md`
(decisions FP1/FP2) and `engine/ppc/fp.h`.

## Status

| # | Step | State |
|---|---|---|
| 1 | FP arithmetic, compares, conversions, paired singles inline (exact fast path + runtime fallback) | Done |
| 2 | `lmw`/`stmw`, `psq_l`/`psq_st` (GQR), SPR moves, `sraw`, `mfmsr` inline | Done |
| 3 | Exactness: semantics digest through translated code, FP differential fuzz, lockstep, guest hashes | Done |
| 4 | Profile (Node, Chrome) and speed work | In progress |
| 5 | Measurements before and after (Node, browsers, module size) | In progress |

## How to build and run (agents)

As in `E2_LOG.md` ("How to build and run"): `engine/tools/emsdk.cmd` for the
`emscripten` preset, `engine/tools/msvc.cmd` for `msvc`. New development switches:

- `MVP_WASM_NAMES=1` (`mvp-boot-wasm`): the module gets a `name` section, so V8's
  profiler names translated functions and the in-module helpers (`h.rd32`,
  `h.psq_l`, ...). `mvp-xlat`'s module is unchanged by default.
- `MVP_WASM_EXEC_STATS=1` (`mvp-boot-wasm`): counts `rt.exec` calls (instructions
  or slow paths the module leaves to the interpreter's semantics) by opcode and
  prints them at exit.
- Profiling build: a second Emscripten tree with `--profiling-funcs` so the
  runtime's functions keep their names:
  `cmake -S engine -B build/engine/emscripten-prof -G Ninja -DCMAKE_TOOLCHAIN_FILE=<emsdk>/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DCMAKE_BUILD_TYPE=Release -DMVP_GFX_WEBGPU=ON -DCMAKE_EXE_LINKER_FLAGS=--profiling-funcs`
  (inside `emsdk.cmd`; pass `-DCMAKE_MAKE_PROGRAM` to ninja if CMake does not find
  it), then `node --cpu-prof --cpu-prof-dir=<scratch> mvp-boot-wasm.js run ...`.
  Profiles are game-derived only in the sense of function names and timings;
  they stay in the scratchpad.
- `test_wasm_digest` (Emscripten, data-free): `MVP_FUZZ_STATES=N` and
  `MVP_FUZZ_SEED=X` scale and vary the FP differential fuzz for one-off runs.
- Eager compilation under Node (`--no-wasm-lazy-compilation`) needs the event
  loop kept alive while V8 compiles in the background, or Node exits at once
  with no output; `--require` a script holding `setInterval(() => {}, 1000)` does
  it (the run then has to be stopped when it prints its result).

**Benchmarks** (all under Node 24.19.0 = V8 13.6, `mvp-boot-wasm run --until none
--max-entries 1000000000 --trace off --mmio 0`):
- *boot budget*: `--max-ticks 2000000000` (E2_SPIKE §2: 491 VI fields, 8.23 s of
  guest time), MEM1 `ba88879f...`;
- *movie budget*: `--max-ticks 5300000000` (1,305 VI fields, 21.81 s of guest
  time; the intro movie plays from about field 600), MEM1 `2039587f...`. The
  movie part is the difference to `--max-ticks 2440000000` (599 fields, MEM1
  `4ee3dc13...`): 706 fields, 11.77 s of guest time.

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

The bugs the fuzz found on the way (all fixed): a single fused multiply-add
whose product underflowed double on a midpoint (TwoSum cannot see the product's
error); the same product underflowing to an exact zero with a zero addend (the
sign of a zero sum); `ps_rsqrte` without the NI flush.

## 2. lmw/stmw, psq_l/psq_st, SPR moves

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
  (the locked cache is not mapped by the runtime) get the same MMIO writes, in
  the same order, as `sem::psq_store`.
- `mfspr`/`mtspr` of every SPR but DEC and the time base (XER from the SO/CA
  locals and the Cpu struct, GQRs, SRR0/1, HIDs, ...), `mfmsr`, `sraw`.

Left in the runtime: `mtmsr` (the runtime's `msr_changed` hook), `mftb` and DEC
moves (the virtual clock), `icbi`, `mffs`/`mtfs*`/`mcrfs`, string and
reservation instructions. Whole DOL: 1,213,762 instructions inline (82.3%), 129
through the runtime (was 70,202), 260,106 control flow.

## 3. Exactness evidence

- **Semantics digest through translated code** (`test_wasm_digest`, new,
  Emscripten): test_digest's 217,088 executions (every non-branch opcode on
  random states, edge-case FPRs, random FPSCR and GQRs, aliased RAM with
  page-crossing accesses) replayed through translated code, one `word; blr`
  function each (one 49.6 MB module). Every execution's state and RAM equal the
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
  the first MMIO access.
- **Guest state on long runs:** the boot budget (MEM1 `ba88879f...`) and the movie
  budget (1,305 fields, MEM1 `2039587f...`) give the same MEM1 as before E2d,
  when every FP instruction went through the interpreter's semantics.
- `test_wasm_lockstep` (synthetic program, inline and helpers-only; the FP edge
  program now has no runtime instruction at all) passes.

## 4. Profile and speed

(In progress.)

## 5. Measurements

(In progress.)

## Next step

(In progress.)
