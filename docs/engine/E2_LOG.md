# E2 log: browser groundwork

Working log for the E2 groundwork session (`claude-side-e2`): the engine builds
for WebAssembly, a baseline of the C++-emitted DOL in wasm, the WebAssembly
emitter, and the in-browser translate-and-compile budget (`docs/engine/E0_SURVEY.md`
§7, E2 risk #2). Results and the verdict: `docs/engine/E2_SPIKE.md`.
Toolchain versions: `docs/engine/TOOLCHAIN.md` ("Browser: Emscripten").

## Status

| # | Step | State |
|---|---|---|
| 1 | Engine builds for wasm; data-free tests pass under Node; FP exactness native = wasm | Done |
| 2 | Baseline: C++-emitted whole DOL compiled with Emscripten (dev path) | Done |
| 3 | WebAssembly emitter (`translator/wasm_emit.*`) | Done (subset + runtime fallback = whole DOL) |
| 4 | `docs/engine/E2_SPIKE.md` (numbers, verdict on risk #2) | Done |

## How to build and run (agents)

- `engine/tools/emsdk.cmd` runs one command with the pinned SDK (TOOLCHAIN.md):
  `cmake --preset emscripten`, `cmake --build --preset emscripten -j 8`,
  `ctest --preset emscripten`. With `MVP_DISC` set at configure time the build
  also has the local targets: `mvp-boot` (C++-emitted DOL, step 2) and
  `mvp-boot-wasm` (the DOL translated to wasm at startup, step 3).
- From Git Bash: `cd build/engine/emscripten/runtime && cmd //c
  "..\\..\\..\\..\\engine\\tools\\emsdk.cmd node mvp-boot-wasm.js run --until none
  --max-entries 1000000000 --max-ticks 2000000000"`. `lockstep` works the same
  way (set `MVP_WASM_PRECISE=1` for the exact state at the MMIO stop).
  `--trace off` (new in `mvp-boot run`) drops the per-entry trace hook for speed
  runs.
- `mvp-xlat emit-wasm FILE` (native or wasm build) translates the whole DOL and
  prints timings, coverage and the opcodes still going through the runtime.
  FILE goes under `build/` only.
- `engine/tools/wasm_compile_bench.mjs` measures V8 compile time of a module with
  any V8 flags.
- Native comparison builds: the `msvc` preset (translated code at `/Od`) and the
  same preset in `build/engine/msvc-o2` with `-DMVP_GAME_OPT=-O2` (new cache
  variable; `/O2` is mangled by Git Bash's path conversion, `-O2` is not).

## 1. The engine builds for wasm (done)

- Preset `emscripten` (`engine/CMakePresets.json`): Ninja, the SDK's CMake toolchain
  file, `Release`. Build: about 30 s at `-j 8`.
- `ctest --preset emscripten`: **all data-free tests pass under Node 24.19.0**
  (the local tests skip without the disc), including the pureikyubu fuzz
  (30,000 random programs), `test_emit_lockstep` (the synthetic program
  translated to C++ at build time by `mvp-synth-emit` running under Node), and
  the new tests below.
- Only one source change was needed: pureikyubu's profiling reads the x86 cycle
  counter (`__builtin_ia32_rdtsc`); `third_party/pureikyubu/pk_wasm_shim.h` stubs it
  under Emscripten (force-included; upstream files unchanged).
- **FP exactness check (FP1/FP2):** `ppc/tests/test_digest.cpp` (`test_ppc_digest`)
  hashes (a) every non-branch opcode (212 of them) on 1,024 random states each,
  217,088 executions, FPRs drawn from edge cases (signed zeros, infinities, SNaN
  and QNaN payloads, double and single denormals, the single normal and denormal
  limits, FLT_MAX and its rounding boundary, ties, fctiw limits), random FPSCR (all
  rounding modes, NI on and off), random GQRs, over aliased RAM so every address is
  valid and page-crossing accesses take the slow path; and (b) the fp:: functions
  directly, 60,000 operand triples in all four rounding modes with and without NI,
  single and double, all four madd forms, force25, frsp, fctiw(z), estimates, load
  and store conversions, quantization. The hashes are constants in the test.
  **Native MSVC and Emscripten/Node print the same two digests**
  (`e4104538...`, `408b94ae...`): no differences to fix. That is expected by
  construction: FP1 computes all floating point in integer arithmetic (128-bit
  products, explicit sticky bits), so no host FPU, NaN payload, FTZ or FMA
  behaviour can reach a result, and WebAssembly's integer operations are fully
  deterministic. The only host floating point left in the engine is OSReport's
  `%f` formatting in the developer log, which never reaches guest state.

## 2. Baseline: the C++-emitted DOL in wasm (done)

Dev path only: `mvp-xlat emit-cpp` (itself running as wasm under Node) writes the
48 C++ shards into `build/engine/emscripten/gen`, em++ compiles them at `-O1`
(the existing setting for clang), and `mvp-boot.js` links them with the runtime.
Nothing of it leaves `build/`.

| | |
|---|---|
| Translate to C++ (mvp-xlat.js under Node) | 1.9 s, 168 MB of C++ |
| em++ `-O1`, 48 shards, `-j 8` | 122 s wall, 930 s CPU |
| Link (wasm-ld, wasm-opt `-O3`, glue) | 293 s (first link) |
| Module | 132.5 MB (`mvp-boot.wasm`, runtime included) |
| Boot budget (below), trace off | 1.38 s in `rt::run`, 938 M guest instructions/s (native `/O2`: 1.19 s); E2_SPIKE.md §5 |
| SDK call log | **identical to native**: sha1 `80d06295...`, 143,011,121 bytes |

The local tests run under Node too (`ctest --preset emscripten -L local`: 6 pass,
`local_disasm` skips without dtk's listing). `local_boot_twice` and
`local_input_start` call `mvp-boot` from a CMake script, which now receives the
cross-compiling emulator (`-DEMULATOR`, empty natively). **Their logs are the
same bytes natively and in wasm:** boot-twice SDK log `0054fb22...` (E0c's
native hash), the START-press runs `c6d85264...` and `e652d99f...`, and the frame
logs. Under Node `local_input_start` takes 77 s against 135 s for the native
`/Od` build.

For comparison, the native `/O2` build of the same C++ takes 17 min 22 s at `-j 8`
(MSVC, 3,086 s CPU); `/Od` about 35 s.

**Boot budget used for every speed number:** `mvp-boot run --until none
--max-entries 1000000000 --max-ticks 2000000000`: 2,000,000,009 counted guest
instructions, of which 710,222,785 are skipped by the idle skip, so 1,289,777,224
are executed; 8.230 s of guest time, 491 VI fields, 23,462,170 function entries,
4,976 thread switches. Same counters and the same SDK-log hash on every build.

## 3. The WebAssembly emitter (done for the spike)

`translator/wasm_emit.h/.cpp` (+ `wasm_binary.h`), host side `runtime/wasm_host.*`,
tools `mvp-xlat emit-wasm` and `mvp-boot-wasm` (`runtime/tools/wasm_game.cpp`).
Design in the header of `wasm_emit.h`; the points that matter:

- **One module, emitted directly** (no C compiler): imports the runtime's memory
  and function table, three runtime addresses and 18 `rt` services; its element
  segment fills table slots from an imported base, so every translated function
  is an ordinary `void (*)(Cpu&)` for the runtime (rt::run, call_indirect, HLE).
- **Registers in locals** (GPRs, CR, LR, CTR, CA, SO). Per function, a forward
  "dirty" and a backward "live" dataflow over `ppc::effects()` (new, checked
  against sem by `test_ppc_effects`) decide what is spilled before calls,
  returns and runtime helpers and what is reloaded after them. A spill counts as
  a use, so a local that may be dirty at a spill is always valid there.
- **Inline:** integer ALU and carries, compares, rotates and shifts (except
  `sraw`), CR logic, mfcr/mtcrf, LR/CTR moves, all integer loads and stores
  (through in-module helpers that read the big-endian page table, D8; MMIO,
  page crossings and unmapped pages go to the runtime with the exact PC and
  instruction count), and since the second pass the FP loads, stores and moves
  (lfs/lfd/stfs/stfd/stfiwx with exact integer conversions, fmr, fneg, fabs,
  fnabs, ps_mr, ps_neg/abs/nabs, ps_merge*). **Everything else calls the
  interpreter's `execute_plain`** (`rt.exec`) with only its own registers spilled
  and reloaded, so the whole DOL is covered from day one and inlining only
  changes speed.
- **Control flow:** one block per label so forward branches are `br`; backward
  branches, jump tables (br_table), secondary entries and E0c resume labels go
  through a loop + br_table dispatcher (19,058 of 24,153 functions need one,
  mostly because every call's return address is a resume label). `return_call`
  only at guest tail calls. Safe points, idle spins, unwinding by return, the
  resume block (rt.resume = resume_target + the label's dispatcher index) as in
  the C++ emitter.
- **Virtual clock:** a local, added up per segment and stored exactly where the
  runtime can see it (calls, helpers, safe points, MMIO slow paths, returns).

**Coverage** (whole DOL, 1,473,997 instructions):

| | inline | through the runtime | control flow |
|---|---:|---:|---:|
| first pass (integer subset) | 69.1% | 13.2% | 17.6% |
| second pass (+ FP moves) | **77.6%** | **4.8%** | 17.6% |

Left in the runtime (static counts): stmw 11,668, lmw 11,659 (cheap: no spills),
FP arithmetic (fmuls 10,588, fcmpu 7,654, fsubs 7,308, fmadds 5,593, fadds 3,730,
frsp 3,483, fsub 3,383, fdivs 1,718, fctiwz 1,047, ...), psq_l/psq_st, the
remaining mfspr/mtspr, sraw.

**Lockstep and equivalence results:**
- `test_wasm_lockstep` (data-free, Emscripten): the synthetic program translated
  in-process, run against the interpreter: **pass, with the C++ emitter's exact
  counts** (2 unwinds, 2 in-frame resumes, 3 resume entries, 2 interpreted
  instructions), both with inline code and with every instruction through the
  runtime; plus an FP program over 96 edge-case records (denormals, NaN
  payloads, the stfs denormalizing range) for the inline conversions: pass.
- `mvp-boot-wasm lockstep` on the whole DOL (`MVP_WASM_PRECISE=1`): **153
  function-entry events, 219,257 reference instructions, 10 full MEM1
  comparisons, zero divergences**, the same first MMIO access as the C++ path.
- `mvp-boot-wasm run` on the boot budget: **SDK call log identical to native**
  (sha1 `80d06295...`), and every counter identical (23,462,170 entries, 4,976
  unwinds, 40,021 in-frame resumes, 14,890 resume entries, 154,970 interpreted
  instructions, 67,823 MMIO accesses, 338 DVD commands, 1,589 AX frames).

Numbers (translate, compile, run): `docs/engine/E2_SPIKE.md`.

## Decisions to record (for the lead)

- E2-W1: the browser backend emits one wasm module directly from the CFG, with
  registers in locals, the interpreter's semantics as the fallback for any
  instruction not emitted inline, and the C++ emitter's call protocol (E0c), so
  wasm-emitted and C++-emitted functions are interchangeable table entries.
- E2-W2: the engine's own wasm build uses native wasm exceptions only to end a
  run (GuestFault, StopRun); the translated module uses none.

## Next step

See E2_SPIKE.md §6. In short: move the translator and runtime into a browser
page (worker, OPFS cache) and measure on Chrome, Firefox and Safari; inline the
FP arithmetic through the integer softfloat; shrink the module (spill/reload
sharing, smaller memory-access sites).
