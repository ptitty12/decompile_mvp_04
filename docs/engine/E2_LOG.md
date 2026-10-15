# E2 log: browser groundwork and browser boot

Working log for milestone E2. Steps 1-4: the groundwork session (`claude-side-e2`):
the engine builds for WebAssembly, a baseline of the C++-emitted DOL in wasm, the
WebAssembly emitter, and the in-browser translate-and-compile budget
(`docs/engine/E0_SURVEY.md` §7, E2 risk #2; verdict in `docs/engine/E2_SPIKE.md`).
Steps 5-9: the browser boot session (`claude-side-e2b`): the page, the Worker, the
renderer in the browser, measurements in four browsers (`docs/engine/WEB.md`).
Toolchain versions: `docs/engine/TOOLCHAIN.md` ("Browser: Emscripten" and
"Browser: WebGPU, the web shell and browser checks").

**E2's exit is met (2026-10-14):** see section 4.

## Status

| # | Step | State |
|---|---|---|
| 1 | Engine builds for wasm; data-free tests pass under Node; FP exactness native = wasm | Done |
| 2 | Baseline: C++-emitted whole DOL compiled with Emscripten (dev path) | Done |
| 3 | WebAssembly emitter (`translator/wasm_emit.*`) | Done (subset + runtime fallback = whole DOL) |
| 4 | `docs/engine/E2_SPIKE.md` (numbers, verdict on risk #2) | Done |
| 5 | Renderer in the browser (emdawnwebgpu, canvas surface, async device) | Done |
| 6 | Host yields: `rt::run()` returns at every VI field, invisibly to the guest | Done (native and browser checks) |
| 7 | Web shell: page, Worker, disc picker, identity check, pacing, keyboard and gamepad | Done (OPFS cache not done: optional) |
| 8 | Local dev server and Playwright browser check | Done |
| 9 | Measurements and determinism in Chrome, Edge, Firefox, WebKit; `docs/engine/WEB.md` | Done (Safari itself needs a Mac) |

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
  *Since the E3a merge* the `msvc` preset builds the translated code at `/O2` by
  default (E3a-B1, about 5.5 minutes at `-j 8`); the `/Od` comparison build is the
  same preset with `-DMVP_GAME_OPT=-Od`. `MVP_GAME_OPT` keeps one meaning: it
  overrides the level of the translated code only (empty: `/O2` on MSVC, `-O1`
  elsewhere).
- **The browser build** (E2b): target `mvp-web` of the same preset, the site in
  `build/engine/emscripten/web/site/`, `engine/web/tools/serve.mjs` to serve it and
  `engine/web/tools/browser_check.mjs` to drive Chrome, Edge, Firefox or WebKit:
  `docs/engine/WEB.md` §1.

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

## 4. Browser boot (E2b, `claude-side-e2b`, 2026-10-14): exit met

**E2's exit is met:** in Chrome (and Edge and Firefox), the player picks their
own disc image, the page translates it in the browser, and the title screen
renders through WebGPU on a canvas; the server holds and sends no game data.
Design, build, measurements: `docs/engine/WEB.md`.

**What was built:**
- **Renderer in the browser** (`engine/gfx`, window/surface layer and build only):
  emdawnwebgpu from the native Dawn's release as an Emscripten local port;
  `Gpu::create_async` (adapter and device without blocking); `Window` on a canvas
  selector (no explicit Present in the browser); read-backs native only. One
  renderer line: the EFB pass sets its depth clear value (browsers reject
  webgpu.h's NaN default). The `emscripten` preset now builds the renderer.
- **Host yields** (`runtime/host_yield.h`, `rt::yield_run`, `rt::g_yield`):
  `rt::run()` returns at every VI field by an unwind like a thread switch's, and
  the safe point the yield interrupted is not repeated when the guest continues
  there. `mvp-play --yield` uses it natively; `local_play_determinism` now also
  runs 700 fields with `--yield` and requires the same guest line (PASS). Natively
  with the START script: 2,400 fields, 2,399 yields, 1,290 repeated safe points
  skipped, guest line identical to the run without yields.
- **Engine module** `mvp-web` (`engine/web/wasm/mvp_web.cpp`): a Worker ES module
  with exports for the disc (FileReaderSync on the picked File, CISO or ISO,
  identity by the DOL's SHA-1), translation, boot, renderer start, running whole
  VI fields, present, pad state, status and the guest line. Live input latches
  presses until the game's next frame poll.
- **Web shell** (`engine/web/src`, TypeScript 6.0.3, compiled by `tsc` in the
  build): page, Worker, keyboard and Gamepad API input, pacing from
  requestAnimationFrame (whole VI fields at 59.94/s, at most 4 per frame, debt
  dropped when far behind).
- **Dev server** `engine/web/tools/serve.mjs` (the site directory only, localhost)
  and **browser check** `engine/web/tools/browser_check.mjs` (Playwright 1.64.0).

**Exit evidence** (screenshots of the canvas under `build/engine/web-check/`,
never committed; looked at with the Read tool):
- Chrome 155, headless, `menus` script, paced: field 6 onwards the boot loading
  screen (baseball photo, EA SPORTS MVP Baseball 2005 badge, "Loading..." bar);
  about field 650 the intro movie's EA logo, 700 the EA SPORTS ring (with E1's
  known movie specks); 1741 the licence screen (MLB and Players Choice logos, "Team
  Rosters Current as of 01/12/05"); **2124 the title screen: the Red Sox batter
  photo, "MVP Baseball 2005" and the copyright line, and the "PRESS START" box**;
  2305 the "No Memory Card found in Slot A." dialog over the title; 3005 the main
  menu (Play Now, Game Modes, My MVP, ...) under the user-profile dialog. 0 WebGPU
  errors, 98,608 draws, 2,138 XFB copies, 5 pipelines, 1,001 textures.
- Edge 155 (headless) and Firefox 157 (headed) show the same screens (Edge's title
  shot caught the PRESS START box over the fading background).
- Live keyboard (Chrome, no script): Enter at fields 803 and 1000 skipped the
  intro movie (licence screen at 1526), further presses reached the memory card
  dialog (2707).
- Identity: a random file gives "GCM: bad disc magic at 0x1C"; a synthetic GCM
  claiming GV4E69 rev 0 with a made-up DOL gives "main.dol SHA-1 056ef58c... is not
  GV4E69 rev 0"; the page shows both under "This image cannot be used...".
- Requests: the page fetched only `/`, `style.css`, `main.js`, `input.js`,
  `worker.js`, `mvp-web.js`, `mvp-web.wasm`, `symbols.txt`; nothing outside the
  local origin, in every run.

**Measurements** (WEB.md §3): cold start from the pick to the first frame 0.67-0.79 s
in Chrome, 1.09 s in Edge, 0.82-0.86 s in Firefox; translation 0.50-0.53 s
(Firefox 0.67 s: its compile of the 49.5 MB module takes 0.15 s against V8's
0.02 s); title 1.2-1.4 ms per field, main menu 8-13 ms per field, all at
59.94 fields/s; the intro movie at 12-18 fields/s (FP through the interpreter).

**Determinism** (WEB.md §4): the guest line at 700, 2,400 and 3,600 fields equals
native `mvp-play` in Chrome, Edge, Firefox and WebKit (MEM1 `eef70ba3...`,
`4df06af1...`, `95f5c597...`).

**Tests:** native `ctest --preset msvc`: 22 data-free pass; local tests pass
(`local_play_determinism` with the new yield run, `local_boot_twice`,
`local_input_start`, `local_lockstep`, `local_boot_main`, `local_cfg`, `local_disc`;
`local_disasm` skipped, no dtk listing). `ctest --preset emscripten -LE local`:
21 pass under Node.

**Problems met:** browsers reject a NaN depth clear value (fixed); emdawnwebgpu
aborts on `wgpuSurfacePresent` and on `WaitAny` without Asyncify (the browser path
uses neither); headless Firefox has no WebGPU adapter (run headed); Playwright's
Windows WebKit has no WebGPU at all (ran without rendering); quick live taps fell
between the game's frame polls during the slow intro movie (latched now).

### Merged with E3b audio (2026-10-14, `claude-side-e2merge`)

`engine/e2b` merged origin/main (E3b: `engine/audio/`, AX2, `mvp-play` sound and
`--audio-wav`, `mvp-boot` `--audio-wav`/`--count`/`--peek`). Conflicts resolved as
the union; also: SDL3 audio output is not built under Emscripten (`MVP_SDL3_DIR`
names the native package there; the browser will use an AudioWorklet),
`mvp-boot-wasm` links `engine_audio` (it shares `mvp_boot.cpp`), and
`local_audio_determinism` passes the cross-compiling emulator, so it runs under
Node too.

**Yields and audio frames:** an AX frame runs inside the guest's DSP mailbox
write (`Hardware::dsp_receive`), from the AI DMA interrupt's handler, and a host
yield is taken only at the end of a safe point outside interrupt handlers, with
the repeated safe point skipped; no guest instruction, so no mail, is dropped or
repeated. Checked: `mvp-play --no-render --audio-wav` with the START script to
2,400 fields, with and without `--yield` (2,399 yields): the same 7,958 mixed
frames, a byte-identical WAV (sha1 `4dcd69d8...`) and the same guest line (MEM1
`4df06af1...`, unchanged by AX2). `local_audio_determinism` gives the same WAV
(`471e427a...`), SDK log (`09cfc165...`) and frame log natively and under Node.

Tests after the merge: `ctest --preset msvc` 34 tests, all pass (`local_disasm`
skipped in the full run without `MVP_DTK_ASM`, then passed with it set to the
progress bot's dtk listing); `ctest --preset emscripten` 31 tests under Node, all
pass, local tests included. Chrome 155 (headless, unpaced, the START script,
2,400 fields): the same guest line as native (MEM1 `4df06af1...`), 0 WebGPU
errors, only the engine's own files requested.

## Decisions to record (for the lead)

- E2-W1: the browser backend emits one wasm module directly from the CFG, with
  registers in locals, the interpreter's semantics as the fallback for any
  instruction not emitted inline, and the C++ emitter's call protocol (E0c), so
  wasm-emitted and C++-emitted functions are interchangeable table entries.
- E2-W2: the engine's own wasm build uses native wasm exceptions only to end a
  run (GuestFault, StopRun); the translated module uses none.
- E2-W3 (E2b): the browser gets control back between VI fields by host yields:
  an unwind at the end of a safe point (the same mechanism as a thread switch),
  with the interrupted safe point not repeated on re-entry. No Asyncify, no JSPI,
  no second thread; the guest runs the same instructions with or without them
  (checked natively and in four browsers).
- E2-W4 (E2b): the browser engine runs in one dedicated module Worker that owns
  the disc File (read with FileReaderSync), the translator, the runtime and the
  OffscreenCanvas; the page only forwards input and shows status. No
  SharedArrayBuffer, so no COOP/COEP headers. `symbols.txt` is served with the
  engine as repository metadata.
- E2-W5 (E2b): live input is applied at the game's frame polls, and a button
  pressed since the previous poll counts as pressed at the next one (a latch), so
  taps shorter than the game's frame survive; what each poll returned is the only
  host input in guest state.

## Next step

E2 is done. Suggested follow-ups:

1. **Speed** (E3a's area): the intro movie runs at 20-30% of real time in the
   browser and the main menu takes 8-13 ms of each 16.7 ms field; inline the FP
   and paired-single arithmetic (E2_SPIKE §6 item 3), then profile game code
   against the runtime in the main menu.
2. **Safari** on a Mac (WebGPU and JavaScriptCore's tiers with this module);
   Playwright's Windows WebKit has no WebGPU.
3. **Audio in the browser** (E3b): an AudioWorklet fed from the Worker.
4. Optional: cache the translated module and the image handle in OPFS; an
   input recorder in the page (export the per-frame inputs as an mvp-input
   script) for bug reports and the netplay work.
5. Before the VPS: production headers (CSP, caching, compression) and serving
   `licenses/` with the engine.

## E2c follow-up (2026-10-14, `claude-side-e2c`)

The browser client after E2: sound through an AudioWorklet, the gamepad mapping,
the disc from the owner's server, the translation cached in the browser,
fullscreen, pause and clearer errors. Evidence and measurements:
`docs/engine/E2C_LOG.md`; the design: `docs/engine/WEB.md`. Next steps 3 and 4
above are done there (audio; the module cache, not the image). One correction:
in E2c's runs, START before field ~1100 does not skip the intro movie (the game
ignores it during the EA SPORTS logo part); a press at field ~1200 does.
