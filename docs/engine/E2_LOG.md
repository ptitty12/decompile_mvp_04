# E2 log: browser groundwork

Working log for the E2 groundwork session (`claude-side-e2`): the engine builds
for WebAssembly, a baseline of the C++-emitted DOL in wasm, the WebAssembly
emitter, and the in-browser translate-and-compile budget (`docs/engine/E0_SURVEY.md`
§7, E2 risk #2). Results and the verdict go to `docs/engine/E2_SPIKE.md`.
Toolchain versions: `docs/engine/TOOLCHAIN.md` ("Browser: Emscripten").

## Status

| # | Step | State |
|---|---|---|
| 1 | Engine builds for wasm; data-free tests pass under Node; FP exactness native = wasm | Done |
| 2 | Baseline: C++-emitted whole DOL compiled with Emscripten (dev path) | |
| 3 | WebAssembly emitter (`translator/wasm_emit.*`) | |
| 4 | `docs/engine/E2_SPIKE.md` (numbers, verdict on risk #2) | |

## 1. The engine builds for wasm (done)

- Preset `emscripten` (`engine/CMakePresets.json`): Ninja, the SDK's CMake toolchain
  file, `Release`. `engine/tools/emsdk.cmd` runs a command with the SDK's
  environment (see TOOLCHAIN.md). Build: about 30 s at `-j 8`.
- `ctest --preset emscripten`: **all 13 data-free tests pass under Node 24.19.0**
  (the three local tests skip without the disc), including the pureikyubu fuzz
  (30,000 random programs, 32 s under Node), `test_emit_lockstep` (the synthetic
  program translated to C++ at build time by `mvp-synth-emit` running under Node,
  then run in lockstep with the interpreter), and the new digest test.
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
