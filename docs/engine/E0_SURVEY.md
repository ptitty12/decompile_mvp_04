# E0a: GameCube recompiler survey, and decisions D1 and D4

Milestone E0a (`docs/ROADMAP.md` §4). Researched 2026-10-14 by reading each project's
LICENSE files, READMEs and source through the GitHub API. Nothing was cloned or run.
Facts here were read in a source; anything inferred says so. The design these
recommendations serve is `docs/ARCHITECTURE.md` (§3-5, §9, §10).

**Short answer.**
- **D1:** write our own translator in C++20. Nothing we may legally reuse emits
  WebAssembly or runs in a browser, and everything mature for GameCube is GPL.
  Reuse specific permissive pieces: gcn-recomp (MIT), pureikyubu (CC0), Aurora (MIT)
  and N64Recomp's patterns (MIT). The GPL projects are references only.
- **D4:** resumable guest threads on one host thread. A switch unwinds the host stack;
  the target thread resumes at its guest PC from state held entirely in guest memory
  and the CPU context. This is the only option that also gives save states, rollback
  and joining a match from a save state later (§6).

## 1. Comparison

"Vendor?" applies our rule: only MIT, BSD, zlib, Apache-2.0 or CC0 may enter the repo.

| Project | License (from LICENSE) | Vendor? | Language, output | Functions, jump tables | Guest time | Guest threads | SDK, GX, audio | State (last push) | WebAssembly |
|---|---|---|---|---|---|---|---|---|---|
| [ExpansionPak/DolRecomp](https://github.com/ExpansionPak/DolRecomp) | GPL-3.0-or-later | No | C11; C or LLVM objects (x86-64, aarch64) | No discovery: fixed chunks, any PC enterable; every indirect branch returns to a dispatcher | Virtual (cycle downcount) | Guest OS code through the trampoline | CPU only | Active, 164 commits (2026-10-10) | None |
| [ExpansionPak/GCRecompiler](https://github.com/ExpansionPak/GCRecompiler) | None (all rights reserved); archived | No | C++; C | Heuristics (prologues, code pointers in data) | Wall clock | None | HLE stubs by address | Dead, DolRecomp's *predecessor* (2026-05-16) | None |
| [ExpansionPak/ModernGekko](https://github.com/ExpansionPak/ModernGekko) | GPL-3.0-or-later, wraps Dolphin (GPL-2.0-or-later) | No | C++23; runtime | (DolRecomp modules) | Dolphin CoreTiming (virtual) | Dolphin LLE | LLE: all of Dolphin | Claims Sunshine, Melee, Brawl (2026-09-17) | None |
| [ant0-blase/GekkoAOT](https://github.com/ant0-blase/GekkoAOT) | GPL-3.0-or-later (plus Dolphin DSP code) | No | C++; patched DolRecomp (LLVM/C) | DolRecomp chunks plus per-instruction re-entry | **Host real time** | Cooperative single-CPU "NativeOS" | Fingerprinted SDK HLE; GX into Aurora; AX HLE | Pre-alpha, ~10 of 23 titles reach gameplay (2026-10-13) | Roadmap mention only |
| [ant0-blase/HPCOS-GC-RECOMP](https://github.com/ant0-blase/HPCOS-GC-RECOMP) | GPL-3.0 plus vendored Dolphin | No | DolRecomp + ModernGekko | Chunks | Dolphin (virtual) | Dolphin LLE | LLE | One game claimed playable; commits translated game code (2026-09-26) | None |
| [ethannicholas/gcn-recomp](https://github.com/ethannicholas/gcn-recomp) | **MIT** since commit `3041bbd2` (2026-10-12) | **Yes** (upstream only) | Python generator; C++20 runtime; C | **dtk `symbols.txt`**, `jumptable_` objects, pointer scans | **Virtual** (back-edge count), idle skip | Host thread per guest context, baton, setjmp/longjmp | SDK scheduler runs as guest code; HLE only OSSave/LoadContext, OSReport, OSPanic; own HW models; OpenGL GX; AX HLE | One week old, several commits a day; Wave Race, Prime 1-2, Burnout 2 (2026-10-14) | None (GL, host threads) |
| [Pokalie566/gcn-recomp](https://github.com/Pokalie566/gcn-recomp) | None | No | (stale fork of the above, taken before the MIT license) | | | | | Frozen | |
| [sp00nznet/gcrecomp](https://github.com/sp00nznet/gcrecomp) (behind [ww](https://github.com/sp00nznet/ww), [luigismansion](https://github.com/sp00nznet/luigismansion), ikaruga) | MIT, plus a notice (portions from CC0/zlib projects); game repos MIT with a scope note | Yes, low value | C++20; C++ | bl scan, prologue heuristics, symbol maps; `bctr` backscan | Wall clock (`rdtsc`, chrono) | None (stubs) | ~65 OS HLE functions; GX HLE to D3D11 | No game reaches gameplay (2026-08-21) | None (Windows only) |
| [jackpoison-prog/RingOut](https://github.com/jackpoison-prog/RingOut) | GPL-2.0-or-later, bundles DolRecomp, ModernGekko, Dolphin | No | C; DolRecomp chunks | Chunks | Dolphin CoreTiming | Dolphin LLE | LLE | Most mature: one game playable start to finish, v1.6.7 (2026-10-08) | None |
| [emu-russia/pureikyubu](https://github.com/emu-russia/pureikyubu) (Dolwin) | **CC0-1.0** (a few files excluded, §2) | **Yes** (selected files) | C++17 emulator | n/a (interpreter, x86 JIT) | Per instruction | LLE | LLE hardware; GL and software GX | Boots several titles (2026-10-09) | None |
| [KaiserGranatapfel/GameCubeRecompiled](https://github.com/KaiserGranatapfel/GameCubeRecompiled) | CC0-1.0 text, but an EULA.md contradicts it | Avoid | Rust; Rust | Linear sweep | None | None | Unused stubs | No game boots (2026-06-30) | None |
| [dynamiteswag81/webcompiled](https://github.com/dynamiteswag81/webcompiled) | GPL-3.0 | No | WiiCompiled C++ through Emscripten | (WiiCompiled) | | **JSPI**, one shadow stack per guest thread | Aurora ported to browser WebGPU | Mario Kart Wii in Chrome 137+, author's claim (2026-10-10) | **Yes** (Wii, built ahead of time) |
| [N64Recomp](https://github.com/N64Recomp/N64Recomp) | MIT (runtime [N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime) and [Zelda64Recomp](https://github.com/Zelda64Recomp/Zelda64Recomp) are GPL-3.0) | Yes (tool only) | C++20; C, or native code via sljit | Symbol TOML; jump-table dataflow | (runtime) | Host threads, one runs at a time | HLE by name | 8.2k stars (2026-05-27) | Upstream no; [N64Recomp-browser](https://github.com/amazingalek/N64Recomp-browser) (GPL-3.0) yes |
| [hedge-dev/XenonRecomp](https://github.com/hedge-dev/XenonRecomp) | MIT, but `thirdparty/disasm/` is GPL binutils | Ideas only | C++20; C++ | `.pdata`, bl scan, switch-table TOML | `rdtsc` | n/a | None | Idle since 2025-08-04 | None |
| [encounter/aurora](https://github.com/encounter/aurora) | **MIT** (dependencies permissive) | **Yes** | C++20; GX API to an internal FIFO to WebGPU (Dawn) | n/a | n/a | Render worker thread | GX, VI, PAD, DVD (nod) | Daily commits, 560 stars, used by Dusklight (2026-10-13) | No Emscripten upstream; WebCompiled ported it |

## 2. Per-project notes

**DolRecomp / GCRecompiler / ModernGekko (ExpansionPak).** GCRecompiler came first
(2026-03 to 2026-05, archived, no license); DolRecomp is a from-scratch C11 rewrite
(2026-06). DolRecomp cuts code into fixed windows with an entry `switch`, so any address
is enterable and no function or jump-table recovery is needed; every `blr`/`blrl`/`bctr`
returns to a dispatcher. Its CPU semantics are the most exact we found: Gekko's 25-bit
rounding of the C operand in `fmadds`, FPSCR sticky bits, NI flushing, full GQR
quantization (`src/cpu/cpu.c`). Rounding modes use `fesetround`/MXCSR, which don't exist
in WebAssembly. ModernGekko is a thin wrapper over a Dolphin fork: the SDK runs as guest
code on Dolphin's hardware models. GPL throughout, so reference only. Forks: gcnlle (LLE
IPL, GPL), JBranch, a mobile front end; aharonahdoot/GXRuntime is a GPL non-Dolphin runtime.

**GekkoAOT.** DolRecomp plus 84 patches, a large C++ runtime, Aurora for graphics, and
fail-closed SDK fingerprinting (replace an SDK function only when its structure proves
it). Its "NativeOS" runs one CPU state at a time and switches by loading registers from
the guest `OSContext`, which works because any PC is re-enterable. Guest time follows
the host clock, so it is not deterministic. GPL-3.0-or-later.

**HPCOS-GC-RECOMP and siblings** (Animaniacs, MOH Frontline): DolRecomp + ModernGekko
per game. Useful idea: the lockstep verifier that reruns every native block on an
interpreter and compares registers and memory. The repo commits ~124 MB of C translated
from the retail game, which our rules forbid.

**gcn-recomp (ethannicholas).** The closest match to our plan, and permissive. Input is
a dtk `symbols.txt` (the format our decomp maintains) plus small per-game files:
`hle.txt`, `special_calls.txt` (OSSaveContext call sites become resume points),
`idle.txt` (the scheduler's idle spin, where guest time skips to the next event).
Virtual clock by default: guest time counts backward branches; `IRQ_CHECK` on every back
edge delivers interrupts. The SDK's own scheduler runs unmodified; only
OSSaveContext/OSLoadContext are replaced
([`runtime/threads.cpp`](https://github.com/ethannicholas/gcn-recomp/blob/main/runtime/threads.cpp)).
Weak spots for us: FP is not hardware-exact (nearest rounding only, no NI), the generator
is Python emitting C (it can't run in a browser), the renderer is OpenGL, and the
pipeline uses several host threads. It is one week old and moves fast; vendor pinned
files with notices, don't fork. The `Pokalie566` repo is a stale, unlicensed fork.

**sp00nznet gcrecomp, ww, luigismansion, ikaruga.** One author's MIT toolkit. Wall-clock
time, no thread switching, direct `bl` bypasses HLE. Every game stalls in the OS
scheduler or a hardware poll loop and gets hand-patched (ww carries 15+ patches; Luigi's
Mansion wedges on an empty interrupt table). Useful as a warning: stubbing threads and
interrupts doesn't scale. The same author's
[model3recomp](https://github.com/sp00nznet/model3recomp) (MIT, PowerPC 603e) has the best
determinism design among them (virtual clock, save states only at safe points,
interpreter-vs-lifted differential tests), but its hardware code is under an open GPL
dispute, so ideas only.

**RingOut.** Most mature GameCube recomp (one game, playable). DolRecomp chunks on a
Dolphin chassis: virtual time from CoreTiming, idle-loop detection, self-modifying-code
hashes, lockstep verification. GPL and Linux/Vulkan/PGO-specific.

**pureikyubu (Dolwin).** CC0, active, boots commercial games. Its interpreter is a good
oracle for integer, branch, CR, XER and load/store semantics, but **not** for FP
(`fmadd` unfused, `fres` = 1/x, no NI or rounding modes). Reusable:
[`src/gqr.h`](https://github.com/emu-russia/pureikyubu/blob/master/src/gqr.h) (paired-single
quantization, with its test), the `testing/gekko_bench` random-instruction fuzz harness
design, idle-wait skipping (`wiki/idleskip.md`), and GX register definitions plus GLSL
TEV/XF shaders as WGSL templates. Never copy `src/bootrtc.cpp`'s IPL descrambler,
`build/Data/*.szp`, `makemap.dat` or the SDK demo screenshots.

**GameCubeRecompiled.** Rust, low fidelity (no XER.CA, PS as scalar, no `psq_*`), no
game boots, and an EULA that contradicts its CC0 file. Skip.

**N64Recomp.** The design to copy: an abstract `Generator` with C and live (sljit)
backends over one instruction walker
([`generator.h`](https://github.com/N64Recomp/N64Recomp/blob/main/include/recompiler/generator.h)),
semantics as data tables, symbol and patch TOML, and a mod system (replace, entry and
return hooks, exports, events, a manifest with dependencies). Its live recompiler and its
function patching (`jmp` written over code) can't work in WebAssembly; the browser port
redirects through an entry check instead.

**XenonRecomp.** Literal per-instruction C++ for PowerPC: CR as eight byte-structs, XER
as three bytes, bswap loads from a base pointer, indirect calls through a host-pointer
table indexed by guest address, `__imp__` weak aliases for hooks, mid-asm hooks, and
per-function tracking of the flush-to-zero mode. MIT, but its decoder is GPL binutils
code, so ideas only.

**Aurora.** MIT, C++20, `webgpu_cpp.h` throughout. It takes **GX API calls**, serializes
them to a GX byte FIFO in its own dialect (host pointers for arrays and textures), and
interprets that. We take the hardware FIFO (D6), so the command processor needs
adapting, but these are directly reusable for E1:
[`lib/gx/shader.cpp`](https://github.com/encounter/aurora/blob/main/lib/gx/shader.cpp)
(TEV to WGSL), `lib/gfx/texture_convert.cpp` (all GC texture formats and TLUTs),
`tex_copy_conv.cpp` (EFB copies), the pipeline cache. No Emscripten support upstream:
device setup is Dawn-native (`DawnNative.h`, toggles, timed waits), it renders on a
worker thread and caches pipelines in SQLite. WebCompiled ported it to browser WebGPU,
so the port is possible. For determinism use `AuroraSetDrawsBlocking(true)`.

## 3. Newer work found (2026)

- **Browser precedents.** WebCompiled (GPL) runs Mario Kart Wii from WiiCompiled C++
  built ahead of time: 29,637 functions, a 122 MiB wasm, Chrome/Edge 137+, guest threads
  on JSPI. A Rabbids Go Home web port (no license) runs each guest thread in its own Web
  Worker over shared memory. [ps2-web-recomp](https://github.com/snuri00/ps2-web-recomp)
  (MIT, 815 stars) unwinds the host stack on a thread switch and resumes at the guest
  address, so it needs no stack per guest thread. N64Recomp-browser (GPL) needs
  `-pthread` (COOP/COEP), wasm exceptions, SIMD and **tail calls**. Without tail calls,
  chains of guest jumps overflowed the browser stack.
- **None of them translates in the browser.** All compile generated C/C++ ahead of time.
  Our D2 (translate in the player's browser) has no precedent.
- **JSPI** ships in Chrome 137 and Firefox 153 (2026-07). Safari 27 added it in beta;
  stable release unconfirmed. Emscripten calls `-sJSPI` stable since 6.0.8.
  **Core stack switching** (`cont.new`/`resume`) is behind flags everywhere. Emscripten
  fibers need Asyncify.
- **FP in WebAssembly** is IEEE round-to-nearest and deterministic **except NaN sign and
  payload**. There is no scalar FMA, no rounding-mode control and no flush-to-zero.
  `relaxed_madd` may or may not fuse depending on the host, so it is
  nondeterministic ([spec](https://webassembly.github.io/spec/core/exec/numerics.html),
  [Nondeterminism.md](https://github.com/WebAssembly/design/blob/main/Nondeterminism.md)).
- **Engine limits** ([JS-API §limits](https://webassembly.github.io/spec/js-api/index.html#limits),
  same in V8, SpiderMonkey and JSC): 1 GiB module, 1,000,000 functions, 7,654,321-byte
  function body, 50,000 locals, 10,000,000 table entries; `br_table` ≤ 65,520 in V8 and
  SpiderMonkey. V8 compiles lazily with Liftoff and tiers hot functions up to TurboFan;
  only streaming-compiled modules get TurboFan code cached.
- **Analysis tools.** [decomp-toolkit](https://github.com/encounter/decomp-toolkit)
  (Apache-2.0) is a binary, not a library; its outputs (our `config/`) are what we
  consume. [powerpc-rs](https://github.com/encounter/powerpc-rs) (MIT OR Apache-2.0)
  decodes Gekko including paired singles. The old `ppc750cl` 0.1.0 is GPL; avoid it.

## 4. What our binary needs (measured 2026-10-14)

Counted over the split assembly of the whole code image: 1,474,044 instructions and
24,158 functions (`symbols.txt` covers all 5,896,176 code bytes); .text 1,110,598,
`.feoverlay` 239,890, `.dboverlay` 123,492. Only counts; no code is reproduced here.

| Feature | Count | Where | Consequence |
|---|---:|---|---|
| `bctr` (jump tables) | 22 in 20 functions | all in the Nintendo SDK (0x80424xxx-0x8043Dxxx) | Game code (ProDG GCC) has none. Recovery is a closed, small problem |
| `blrl` / `bctrl` (indirect calls) | 22,167 / 4, in 6,023 functions | vtables and callbacks everywhere | Indirect dispatch must be one table load plus `call_indirect` |
| `bl` / cross-function `b` | 92,982 / 46 | | Direct calls dominate; only 46 tail branches need `return_call` |
| `lmw` / `stmw` | 11,659 / 11,668 | GCC prologues | Unroll inline |
| Fused multiply-add (scalar) | 6,189 in 1,073 functions (`fmadds` 5,593) | game and SDK | Needs software FMA in WebAssembly |
| `frsp` | 3,483 | | Single rounding on every single result |
| Paired singles | 499 `ps_*` (13 opcodes) + 729 `psq_*`, in 34 functions | ~14 EA math functions (0x803A31C0-0x803A3E08, 0x803EA3EC, 0x803EB000), SDK MTX/GX, context save/restore | Small surface; GQR quantization still exact |
| `mftb` | 33 in 18 functions | `fn_8014C8BC` (the first call in `main`'s loop), EA libraries, OSGetTime/OSGetTick | All read the virtual clock (K3) |
| MMIO (`lis rX,0xCC00/0xCC01`) | 776 in 260 functions | 394 in EA graphics code (0x803xxxxx), the rest SDK | The write-gather pipe is fed by game code: confirms D6 |
| `sc`, `rfi`, `mtmsr`, `mfmsr` | 3, 18, 19, 30 | 36 SDK functions | Replaced, or a virtual MSR |
| `lwarx`/`stwcx.`, `dcbz` | 0, 0 | | Nothing to do |
| FPSCR writes | 7 `mtfsf`, 1 `mtfsb1` | `fn_8041A6BC` does `mtfsb1 29` (sets **NI**), called from `fn_8043188C` (OSInit) | The game runs in non-IEEE mode: denormal results flush to zero on hardware |
| `OSCreateThread` (`fn_80437A4C`) | 4 call sites | `snd/tu_803AC88C` (EA SND), `ealib/tu_803FEB34`, `ealib/tu_803FFD9C` (two) | Real guest threads besides main and idle |

The largest function is 17,568 bytes (4,392 instructions), far below every engine limit.
`__start` (0x80003100) sets r1/r2/r13 itself, clears .bss, checks the debugger flag at
0x800000F4, calls DBInit (`fn_80421B84`) and OSInit (`fn_8043188C`), then
`fn_80438704` and `main`. `main` (0x8014D63C) calls `__main` (static constructors) and
`fn_8014C5A4` (init), then loops forever over `fn_8014C8BC`, a state check and
`fn_8014D488`. At the progress build, the K1 names still missing are 46 OS, 10 DVD,
2 PAD, 42 GX, 11 AX, 11 MTX, 10 CARD and 5 AR functions; VI is complete.

## 5. Recommendation for D1: write our own translator

**Write `engine/translator/` ourselves in C++20.** Use one decoder and IR with two emitters:
- a **WebAssembly emitter**, the product;
- a **C++ emitter** for native development: debuggers, sanitizers, fast iteration.

A **reference interpreter** uses the same semantics library. It is the oracle in tests
and the path that resumes unwound frames (§6).

Why not adopt or fork:
1. **License.** Every mature GameCube recompiler or runtime is GPL: DolRecomp,
   ModernGekko, GekkoAOT, RingOut, HPCOS, WebCompiled, N64ModernRuntime. The permissive
   ones are either one week old (gcn-recomp), stalled (sp00nznet), or emulators
   (pureikyubu).
2. **D2 has no precedent.** We translate in the player's browser and emit WebAssembly.
   Every candidate emits C, C++ or LLVM IR for a native compiler. A C compiler in a
   browser tab isn't practical. So the emitter, which is the bulk of a translator, is
   new work whatever we choose. Adopting would only save the decoder and analysis.
3. **Our hardest analysis problems are already solved.** `symbols.txt` gives all 24,158
   functions with sizes. The only jump tables are 22 SDK `bctr` sites. There are 13
   paired-single opcodes, no reservations and 46 tail branches (§4). Most of the
   machinery in these projects (function discovery, jump-table heuristics, chunking) is
   there because they *lack* a symbol map.
4. **Determinism and exactness need our own semantics anyway.** We need software FMA
   with Gekko's 25-bit C operand, NaN canonicalization, a decided NI policy, a virtual
   clock, and no host time anywhere. None of the permissive projects has these.
5. **D3 fits.** C++20 + Emscripten + `webgpu.h` is exactly what Aurora and gcn-recomp's
   runtime use, so their pieces drop in without a language change.

**What to reuse** (record each in `docs/REUSE.md` with its notice and pinned commit):

| Source | License | Take | When |
|---|---|---|---|
| gcn-recomp (upstream, at or after `3041bbd2`) | MIT | Design of the OS boundary (HLE only the context primitives; the idle-skip point; virtual back-edge clock); hardware-register models (`runtime/hw/`) and AX HLE as starting points where they fit | E0b-E3 |
| pureikyubu | CC0-1.0 | `src/gqr.h` + its test; the fuzz harness design (random programs, state hash, two engines); idle-wait skip; GX register definitions; GLSL TEV/XF as WGSL templates. Its interpreter as a non-FP oracle, run in tests | E0b, E1 |
| Aurora | MIT | TEV-to-WGSL generator, texture decoders, EFB copy conversion, pipeline cache, display-list handling; the command processor adapted to the hardware FIFO | E1 |
| N64Recomp | MIT | Generator-interface pattern; symbol and patch config shape; the mod model (replace, entry/return hooks, exports, events, manifest), redesigned for indirection instead of code patching | E0b (shape), E6 |
| powerpc-rs | MIT OR Apache-2.0 | Cross-check only (it's Rust; we write the C++ decoder) | E0b |

**Read, don't copy:** DolRecomp `cpu.c` (FP/PSQ exactness), GekkoAOT NativeOS and SDK
fingerprinting, RingOut/RecompCore lockstep verification, XenonRecomp codegen,
WebCompiled's `docs/web-port.md`, N64Recomp-browser's lessons, Dolphin.

## 6. Recommendation for D4: resumable guest threads

**All guest-thread state lives in guest memory and the CPU context. A switch unwinds the
host stack to the dispatcher, which resumes the target at its guest PC. One host thread
runs all guest code.**

- The SDK's own scheduler runs as translated code (gcn-recomp shows this works). We
  replace only the context primitives:
  - `OSSaveContext` stores the registers into the guest `OSContext`, with the resume PC
    at its return address and r3 = 1 in the saved copy, and returns 0.
  - `OSLoadContext` loads them and unwinds to the dispatcher, so the saved thread
    later "returns" from `OSSaveContext` with 1.
  - If the context to load is the one already running, nothing unwinds.
- **Interrupts** arrive at safe points (function entries, loop back-edges) while the
  virtual MSR.EE is set. The safe point saves the registers into the current
  `OSContext` and calls the SDK's interrupt dispatcher as an ordinary nested call. A
  switch only happens if the SDK then loads another context.
- **Resuming mid-function:** the unwound frames no longer exist on the host. The
  dispatcher runs the resumed frame in the **reference interpreter**: calls it makes go
  to translated code natively, and its `blr` continues into the caller's frame,
  interpreted. Only the remainders of the few suspended frames (scheduler, wait, frame
  end, a thread's root loop) are interpreted.
  - If measurement shows hot loops stuck in the interpreter, add generated resume
    entries (a second, resumable variant per affected function, made lazily).
- **Unwinding:** natively a C++ exception; in WebAssembly an exception, or a flag checked
  after each call. Choose by measurement in E0b.

Why this one:
- **Save states and rollback.** A host stack can't be serialized. With host threads or
  JSPI, every parked thread holds translated frames that a snapshot can't capture or
  restore. Rollback, joining a match from a save state, and desync dumps (ARCHITECTURE
  §8, ROADMAP "Later") all need state that is entirely guest memory + CPU context.
  model3recomp hit exactly this limit.
- **Deterministic by construction.** There is no host scheduler, no SharedArrayBuffer
  and no wall clock.
- **One model, native and browser.** It needs no COOP/COEP, no JSPI (new in Firefox,
  beta in Safari) and no per-thread stacks.
- **Precedents:** DolRecomp and GekkoAOT (any PC re-enterable, cooperative CPU state)
  natively; ps2-web-recomp (unwind and resume at the guest address) in the browser.

Rejected:
- **Host thread per guest thread with a baton:** gcn-recomp, N64ModernRuntime, and the
  Rabbids port (workers). Proven and simplest to build, but it blocks save states and
  needs SharedArrayBuffer. It is the **fallback** if E0b measures the resumable path as
  too costly.
- **JSPI:** WebCompiled shows it works, but it has the same snapshot problem, fixed-size
  suspended stacks, and no native equivalent.
- **Asyncify / Emscripten fibers:** they instrument every function that can reach a
  switch. With safe-point interrupts that is all 1.47M instructions.

## 7. Risks

### E0b (native boot spike)

| Risk | Why it matters | What retires it |
|---|---|---|
| Semantics bugs (CR/XER carry, `rlwinm`, FP edge cases, PSQ) corrupt state silently | Boot fails far from the cause | Instruction vectors per mnemonic; lockstep differential runs (translated vs interpreter, compare registers after every call); fuzzing in the pureikyubu `gekko_bench` style. Optional: boot MVP under gcn-recomp (MIT) on the dev machine as a black-box trace reference, outputs in `build/` only |
| Hardware polling before the first retrace (DSP mailbox handshake, ARAM DMA, DI, VI, EXI) | Every sp00nznet game stalled here | Stubs written from our matched SDK source, which shows each poll; log every MMIO read and stop on unknown registers; idle and poll detection |
| Unnamed SDK functions (§4) block HLE by name | Calls go to raw hardware code | The K1 sweep. The boot stops at the first call into an unnamed SDK function and prints its address |
| D4 mechanism (unwind, interpreter resume) costs too much or deadlocks | Threads hang, or performance suffers | E0b item 9 measures it: switches per frame, interpreted share, two-run identical traces. Fall back to baton threads if needed |
| Boot environment: low-memory globals, BI2, arena, exception-vector copies | OSInit reads them; OSInit copies exception stubs to low memory and invalidates the instruction cache | Read OSInit (matched source); the `icbi` overlay check ignores the vector area |

### E2 (browser boot)

| Risk | Why it matters | What retires it |
|---|---|---|
| **Translate and compile time in the browser.** Our own emitter has no LLVM behind it; the module could be 20-60 MB (inferred); Liftoff, then TurboFan. Code for generated (non-fetched) bytes is not cached | Cold start, and speed if our code is naive | An early spike, right after E0b item 6: emit WebAssembly for the whole DOL, then measure translation time, compile time, peak memory and a CPU-bound benchmark against native in Chrome, Firefox and Safari. Keep register caching in locals and flag elimination in the emitter. Fallbacks: per-unit modules, lazy translation (D2 allows it) |
| **FP determinism and fidelity.** No scalar FMA (6,189 sites), no FTZ (the game sets NI), no rounding modes, NaN bits vary | Desyncs between browsers if NaN bits reach memory; small physics differences from hardware | Software FMA. For single precision: exact product in f64, then an emulated round-to-odd sum, then demote; the rare double `fmadd` (54 sites) goes through a full software FMA. Canonicalize NaNs on FP stores and conversions. Decide NI by measurement (flush on stores vs ignore). Vectors run on all three engines in CI |
| Engine differences (Safari's WebGPU, JSC tiering on big functions, wasm exceptions, tail calls) | "Works in Chrome only" | A conformance page in CI on all three engines; keep functions small; `return_call` only at the 46 tail branches |

**Top three:** FP determinism and fidelity in WebAssembly; the in-browser translate and
compile budget, plus code quality without LLVM; and the thread and interrupt model (D4
plus the virtual clock) together with hardware polls before the first frame.

## 8. E0b plan: native boot to the first VI retrace

Goal (ROADMAP E0b): translate `main.dol` on the dev machine, run it with stub HLE from
`__start` (0x80003100) through `main` (0x8014D63C) into the frame loop, reach the first
VI retrace, and log every SDK call by name. Rules for every item:
- outputs and disc-derived files stay in `build/`;
- tests that need no game data run in CI;
- tests that need the disc skip cleanly without it.

| # | Work item | Exit (checkable) |
|---|---|---|
| 1 | **Skeleton.** `engine/` with CMake presets (MSVC and clang natively; Emscripten later), a test runner, and CI that builds and runs the data-free tests. `docs/REUSE.md` entries for anything vendored. | CI green; `ctest` passes locally |
| 2 | **Disc and DOL.** Read the player's CISO or ISO (the local disc is a CISO), parse the FST, extract `main.dol`, check its SHA-1 (`da6becdb...`), map its sections. | The section table printed equals `config/GV4E69/dol_layout.txt`; the hash check passes; a synthetic-DOL test passes in CI |
| 3 | **Decoder and disassembler** for every Gekko form the DOL uses (243 mnemonics, including paired singles and the SPRs in §4). | Disassembly of all 1,474,044 code words matches dtk's listing in `build/GV4E69/asm` word for word (local test); hand vectors in CI |
| 4 | **Semantics library and reference interpreter.** Exact Gekko semantics: CR/XER (CA, OV, SO), `lmw`/`stmw`, single rounding, FMA with the 25-bit C operand, `fctiwz`, NI flushing, NaN rules, PSQ with GQR (gqr.h). | Vectors for every mnemonic pass in CI; random-program fuzzing against pureikyubu's interpreter shows zero integer/branch/CR/XER differences |
| 5 | **Functions and CFGs** from `symbols.txt`: blocks, call vs tail call vs local branch, `blrl`/`bctrl`, `blr`, the 22 `bctr` tables, and every resume point (each call's return address and each safe point). | Zero unresolved branch targets; all 22 `bctr` resolved; cross-function branches only to known function starts |
| 6 | **IR and C++ emitter.** Translate the whole DOL to C++ in `build/engine/`. Guest memory big-endian (D8), MEM1 at 0x80000000 and 0xC0000000, MMIO at 0xCC000000 to handlers; a dense guest-address-to-function table for indirect calls with an "unknown target" trap. | The whole DOL compiles and links; lockstep mode (every call checked against the interpreter) runs from `__start` to the first MMIO access with zero divergences |
| 7 | **Boot environment.** Set what the IPL and apploader leave in low memory (0x80000000-0x800000FF and 0x800030xx: disc ID, magic, memory size, console type, arena, FST, clocks, BI2 with no debugger), then enter 0x80003100. Virtual MSR, HID and GQR; cache ops are no-ops except the `icbi` overlay hash check. | The trace shows `__start` calling DBInit, OSInit and `fn_80438704`, and reaching `main` |
| 8 | **HLE boundary and SDK log.** Route calls by `symbols.txt` name to host replacements, log every call into SDK units, and stop at calls into unnamed SDK functions. | Every SDK call in the log has a name; an unnamed one stops the run with its address (input for K1) |
| 9 | **Virtual clock, interrupts and threads (D4 prototype).** Time base and decrementer from guest instructions counted between safe points (a fixed CPI). DEC and PI interrupts at safe points under MSR.EE. Idle-spin skip to the next event. OSSaveContext/OSLoadContext per §6, with interpreter resume. | The four `OSCreateThread` sites run; two runs give byte-identical traces; switches per frame and the interpreted-instruction share are reported |
| 10 | **Devices to the first retrace.** VI (registers, retrace interrupt into `__VIRetraceHandler`); PI; DSP, ARAM and AI "ready" answers; DVD through HLE on the virtual disc; SI with no pads; EXI with no card and a fixed RTC; CP/PE with the write-gather pipe captured to a buffer. | `VIWaitForRetrace` returns after the first retrace; the SDK log is complete; two runs give byte-identical logs (only the log's hash may be committed) |

After item 10, the WebAssembly emitter is added behind the same IR (E1/E2). Every boot
trace is compared across the interpreter, the C++ build and the WebAssembly build. The
in-browser compile spike (§7) can start as soon as item 6 lands.

## 9. Follow-ups for the lead

- Record D1 and D4 in `docs/DECISIONS.md` (E0a exit) and update `ARCHITECTURE.md` §9.
  D4 then settles in E0b on the item 9 measurements.
- Add the reuse sources in §5 to `docs/REUSE.md` as they are vendored. Pin gcn-recomp
  at or after `3041bbd2`, never the Pokalie566 fork.
- K1 priority for E0b: the 46 OS, 10 DVD and 2 PAD names (§4).

## Sources

All read 2026-10-14, through the GitHub API or by the survey's web research.

Repositories:
- GameCube recompilers: [DolRecomp](https://github.com/ExpansionPak/DolRecomp),
  [GCRecompiler](https://github.com/ExpansionPak/GCRecompiler),
  [ModernGekko](https://github.com/ExpansionPak/ModernGekko),
  [GekkoAOT](https://github.com/ant0-blase/GekkoAOT),
  [HPCOS-GC-RECOMP](https://github.com/ant0-blase/HPCOS-GC-RECOMP),
  [gcn-recomp](https://github.com/ethannicholas/gcn-recomp) and its
  [fork](https://github.com/Pokalie566/gcn-recomp),
  [gcrecomp](https://github.com/sp00nznet/gcrecomp), [ww](https://github.com/sp00nznet/ww),
  [luigismansion](https://github.com/sp00nznet/luigismansion),
  [RingOut](https://github.com/jackpoison-prog/RingOut),
  [GameCubeRecompiled](https://github.com/KaiserGranatapfel/GameCubeRecompiled).
- Emulator: [pureikyubu](https://github.com/emu-russia/pureikyubu).
- Design references: [N64Recomp](https://github.com/N64Recomp/N64Recomp),
  [N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime),
  [XenonRecomp](https://github.com/hedge-dev/XenonRecomp),
  [Aurora](https://github.com/encounter/aurora),
  [model3recomp](https://github.com/sp00nznet/model3recomp).
- Browser ports: [webcompiled](https://github.com/dynamiteswag81/webcompiled),
  [rabbids-go-home-web-port](https://github.com/teaserlua/rabbids-go-home-web-port),
  [ps2-web-recomp](https://github.com/snuri00/ps2-web-recomp),
  [N64Recomp-browser](https://github.com/amazingalek/N64Recomp-browser).
- Tools: [decomp-toolkit](https://github.com/encounter/decomp-toolkit),
  [powerpc-rs](https://github.com/encounter/powerpc-rs).

Specifications and platform status:
- [WebAssembly numerics](https://webassembly.github.io/spec/core/exec/numerics.html),
  [JS-API limits](https://webassembly.github.io/spec/js-api/index.html#limits),
  [Nondeterminism.md](https://github.com/WebAssembly/design/blob/main/Nondeterminism.md).
- [JSPI overview](https://github.com/WebAssembly/js-promise-integration/blob/main/proposals/js-promise-integration/Overview.md),
  [features.json](https://github.com/WebAssembly/website/blob/main/features.json),
  [Chrome 137](https://developer.chrome.com/blog/new-in-chrome-137),
  [Firefox 153](https://developer.mozilla.org/en-US/docs/Mozilla/Firefox/Releases/153),
  [Safari 27 beta](https://webkit.org/blog/17967/news-from-wwdc26-webkit-in-safari-27-beta/).
