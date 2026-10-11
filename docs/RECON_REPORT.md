# Phase 0 Recon Report: MVP Baseball **2005** (GameCube, GV4E69)

- Date: 2026-10-10
- Agent: Claude Opus 5.5 (Claude Code), single session, read-only analysis
- Status: **Phase 0 complete. STOPPED, waiting for owner approval.** No scaffold, no decompiled code.
- Reproduce: scripts in `tools/recon/` (dependency-free Python). All binaries were read from
  `orig/GV4E69/` (gitignored) and extracted only to a temp dir outside the repo.

## TL;DR

1. **The disc is MVP Baseball 2005, not 2004.** Header: `GV4E69`, "MVP Baseball 2005", USA, disc 0, rev 0.
   The kit, `CLAUDE.md` and the README all say 2004. Internally the game was built from a
   `C:/mvp2004/` source tree, so 2005 is the 2004 codebase carried forward. **Owner must confirm the target.**
2. **The toolchain is SN Systems ProDG (GNU C++ 2.95.3, "SN BUILD v1.76"), not CodeWarrior.** Confidence is high:
   about ten independent signals, including a literal compiler banner. Nintendo's Dolphin SDK libraries inside the DOL are
   CodeWarrior-built, as shipped by Nintendo. So this is a **hybrid toolchain**, the "slower path" the README warned about.
3. **No symbols.** `/mvp.elf` on the disc is the linked executable but **stripped**: section headers only, no symtab or DWARF.
   No `.map`. It still gives exact section names, including three **code overlay** sections.
4. **Size: about 5.6 MB of code, about 24,000 functions** (heuristic). Roughly 83% game code, 11% EA shared libraries,
   4% SDK and libc.
5. **Prior art exists for the hard part.** `dbalatoni13/nfsmw` (NFS Most Wanted, another EA GameCube title) is a
   dtk-based matching decomp using **ProDG for game code and MWCC GC/1.2.5n for the SDK**. The community
   compilers package ships ProDG 3.5 / 3.5b140 / 3.7 / 3.8.1 / 3.9.3. None is yet confirmed to be "SN BUILD v1.76".
6. **Recommendation:** a staged **ProDG-hybrid matching** path. The Phase 1 exit (byte-identical DOL from split asm)
   doesn't depend on the compiler. Then a hard gate: find a ProDG build whose codegen matches. If none does, the
   owner chooses between SDK-only matching plus functional mode for game code, or hunting for the exact compiler.

---

## 1. Disc and binary

| Item | Value | Evidence |
|---|---|---|
| Game ID | `GV4E69` (maker `69` = Electronic Arts) | boot.bin @0x0 |
| Title | `MVP Baseball 2005` | boot.bin @0x20 |
| Region / disc / revision | USA (`E`) / disc 0 / rev 0 (`0x00`) | boot.bin @0x3, @0x6, @0x7 |
| Apploader date | `2004/05/21` | disc @0x2440 |
| Build stamp | `TP GC Build Number 2004-12-24_1` | `/version.txt` |
| Image format | CISO (block size 0x200000, 658 blocks present, tail dropped) | `.ciso` header |

### Hashes (owner: compare against redump.org)

| What | SHA-1 |
|---|---|
| **Full disc image, reconstructed (1,459,978,240 bytes), the redump-comparable one** | **`445a5f329aa340703a6e62723f73efc24fc71340`** |
| `.ciso` file as stored | `d4f2491fc0a0653abff7b16894eda339e29633ef` |
| `sys/main.dol` (6,837,728 bytes) | `da6becdbea614d03c4b5eae9f8a0fb08e0a184dd` |
| `/mvp.elf` (6,838,604 bytes) | `7f1c33721e140b2ad4fcef4aa0cb9ee011ffd22b` |

**Why "reconstructed":** CISO drops the disc tail, which on a GameCube disc is pseudo-random "junk" padding that redump
includes in its hash. `tools/recon/junk.py` regenerates that padding. It uses a lagged-Fibonacci generator seeded from
the game ID, disc number and 0x8000-byte sector. Before trusting it, the generator was checked against the
**397,404 bytes of real junk still present** in the image (0x5239efa4–0x52400000): **0 mismatches**.
The full-image hash is therefore expected to equal redump's, assuming the dump itself is good. Nothing was downloaded.

### Executables

- **`main.dol`** at disc offset 0x20300. **No `.rel` / `.rso` modules.**
- **`/mvp.elf`**: big-endian PPC ELF, `e_flags=0x80000000`, entry 0x80003100, 16 section headers, **no `.symtab`,
  no debug sections, no `.comment`**. Every PROGBITS section's bytes are **identical to the DOL**, which I verified
  section by section. It is the pre-`elf2dol` link output with symbols stripped.

### Section table (names from `mvp.elf`; addresses and sizes verified against the DOL)

| Section | Address | Size | DOL slot | Notes |
|---|---|---|---|---|
| `.init` | 0x80003100 | 0x38c | T0 (0x3a0 padded) | SN-style crt0 + `__init_hardware`-style helpers |
| `.text` | 0x800034a0 | 0x43c918 | T1 | game + EA libs + SDK + libc |
| `.frontend_codeoverlay` | 0x8043fdc0 | 0xea448 | T1 (contiguous) | front-end / franchise UI code |
| `.database_codeoverlay` | 0x8052a220 | 0x78990 | T1 (contiguous) | database / roster / trade code |
| `.batter_codeoverlay` | 0x805a2bc0 | 0 | — | empty (NOBITS, size 0) |
| `.ctors` | 0x805a2bc0 | 0x164 | D0 | 89 words: `0xffffffff`, 87 ctors, `0` |
| `.dtors` | 0x805a2d40 | 0x44 | D0 | 17 words: `0xffffffff`, 15 dtors, `0` |
| `.rodata` | 0x805a2da0 | 0x6c36a | D1 | |
| `.data` | 0x8060f120 | 0x77740 | D2 | |
| `.bss` | 0x80686860 | 0x68150 | (bss) | DOL bss = 0x80686860 + 0x693e0 (spans .bss through .sbss2) |
| `.sdata` | 0x806ee9c0 | 0x9a4 | D3 | |
| `.sbss` | 0x806ef380 | 0x8c0 | (bss) | |
| `.sdata2` | 0x806efc40 | 0x13b8 | D4 | |
| `.sbss2` | 0x806f0ff8 | 0 | — | empty |
| `extab` / `extabindex` | — | — | — | **absent** (CodeWarrior always emits these) |
| `.eh_frame` / `.gcc_except_table` | — | — | — | absent, so most likely `-fno-exceptions` |

Registers set by crt0 at 0x80003100: `r1 = 0x80701020`, `r13 = 0x806f69c0` (= `.sdata` + 0x8000, so `_SDA_BASE_`),
`r2 = 0x807069c0`. **r2 is never used as a base register anywhere in the code (0 uses), while r13 has 3,334.**
`.sdata2` sits inside r13's ±32 KB window, so everything small is r13-relative. That differs from the CodeWarrior r2/r13 convention.

### Debug leftovers on disc (the useful ones)

- **No linker map, no symbol file, no unstripped ELF** for the main program.
- **`/data/libmatd.a`**: an `ar` archive of 25 EAGL "render method" objects, all big-endian PPC ELF `.o` files **with
  symbol tables and full DWARF-1 debug info**, plus **the compiler banner** (§2). Its sibling **`/data/libmatz.a`** holds the
  same 25 objects without debug info. EAGL loads these at runtime; they are *not* part of `main.dol`. Their value:
  compiler identification, **EAGL class/struct layouts** (DWARF types from EAGL and GX headers), and real mangled names
  for EAGL runtime functions they import (for example `GetInit__Q24EAGL8DebugLog`).
- `/data/misc/*.o` and `/data/models/irradlitsphere.o`: **little-endian** ELF containers holding EAGL *model data*, not code.
- **Source paths in DOL strings:** 83 distinct `/mvp2004/...` path strings and 32 full `C:/...` paths, mostly from
  asserts. Examples: `C:/mvp2004/source/common/ai/physics/ball.cpp`, `.../ai/bench/benchai.cpp`,
  `.../animation/goals/catchgoal.cpp`, `.../database/components/datalookup.cpp`. Top-level layout:
  `source/common/{ai,animation,database,frontend,geomlib,script,tourneylogic,main,assetmanager}`, `source/gc/exception`,
  `libraries/gamelib/source/{animlib,corelib}`, `libraries/gc/eagl`.
- Many debug-menu, tuning and cheat strings (e.g. "Everybody Power Hitter Cheat Player", "-- Pitch Break Tuning --") and
  class-name strings (`cFEManager`, `cAmbientAudioMixer`, `cPlayManagerArgumentScript`). These are good naming evidence.
- `PS2 stadium texture memory quota exceeded.` and similar strings mean the code is shared with the PS2 build.

### Asset archive formats (identified by magic; nothing extracted into the repo)

| Ext | Magic | Format (probable) | Count / bytes |
|---|---|---|---|
| `.big` | `BIGF` | EA BIG archive | 217 / 828 MB |
| `.ast`, `.asf` | `SCHl` | EA SCHl audio stream | 14 / 232 MB, 9 / 65 MB |
| `.vp6` | `MVhd` | EA VP6 video | 42 / 218 MB |
| `.abk` | `ABKC` | EA audio bank (AEMS) | 24 / 9 MB |
| `.bnk`, `.gen` | `BNKb` | EA sound bank | 2 |
| `.gsh` (+ `.bak`) | `SHPG` | EA shape/texture (GC) | 21 |
| `.tpl` | `0x0020AF30` | Nintendo TPL texture | 4 |
| `.loc` | `LOCH` | EA localization table | 3 |
| `.a1c` / `.csi` | `A1CL` / `MOIR` | EA audio event data | 1 / 1 |
| `.nam` `.txt` `.off` `.evt` | binary/text | speech index tables (PBP, PA, chants) | many |
| `.dat` / `.csv` / `.tsv` / `.ini` | — | database, history, credits, config (`mvp.ini`, `mvporide.ini`) | |
| `.bnr` | `BNR1` | GameCube banner | 1 |

---

## 2. Toolchain: the critical question

### Verdict

| Code | Toolchain | Confidence |
|---|---|---|
| Game code + EA libraries (≈94% of code) | **SN Systems ProDG for GameCube: GNU C++ 2.95.3, "SN BUILD v1.76"**, SN linker (`ngcld`) | **High** that it is ProDG/GCC rather than CodeWarrior. **Medium-high** that the exact build is v1.76 (the banner was observed directly only in the `libmatd.a` objects, built from the same `C:/mvp2004` tree; Phase 1 must confirm by codegen) |
| Dolphin SDK libraries (≈4%) | Nintendo's precompiled libraries, **Metrowerks CodeWarrior**; version TBD (first candidate **GC/1.2.5n**, which nfsmw (a 2005 EA title) uses for its SDK objects) | High |
| C runtime | **SN libc, newlib-derived** (not MSL) + SN crt0 | High |

### Evidence

1. **Literal compiler banner.** The DWARF `.debug` producer string in `libmatd.a(Texture.o)` reads
   `GNU C++ 2.95.3 SN BUILD v1.76 for Nintendo Gamecube`, with source path
   `C:/mvp2004/source/GC/rendermethods/compile/objrms.gcSN/Texture.cpp` (note the `gcSN` build dir) and SDK includes from
   `c:/mvp2004/tools/bin/DOLPHI~1.0/include/dolphin/gx/...`.
2. **Prologue shape**, from about 24k discovered function starts. GCC order (`stwu r1,-N(r1)` then `mflr r0`):
   **17,737**. CodeWarrior order (`mflr r0; stw r0,4(r1); stwu r1,...`): **314**, and 310 of those sit in
   0x80402000–0x8043e9a4, the SDK region. Example: `main` at 0x8014d63c opens `stwu r1,-24(r1); mflr r0; stmw r29,12(r1); stw r0,28(r1)`.
3. **GPR save idiom:** `stmw`/`lmw` appear 11,668/11,659 times. Saves are inline; no `_savegpr_`/`_restgpr_`
   helper calls were seen in sampled prologues.
4. **Small data:** r13 only, r2 unused (see §1). CodeWarrior output uses r2 for `.sdata2`.
5. **crt0 is not the SDK's `__start.c`.** It sets r1/r2/r13 with inline `lis/ori`, clears `.bss`/`.sbss` by calling `memset`
   (0x8040b320, which lives in `.text`; CodeWarrior keeps `memset` in `.init`), then calls `main` (0x8014d63c) and branches to `exit`
   (0x80409e6c). Its hardware-init helper at 0x80003468 does match the SDK `__init_hardware` idiom
   (`__OSPSInit`/`__OSFPRInit`/`__OSCacheInit` calls).
6. **`.ctors`/`.dtors` use GCC crtbegin/crtend lists** with a `0xffffffff` head and `0` terminator. CodeWarrior lists start
   with `__init_cpp_exceptions` and have no `-1` sentinel.
7. **`main`'s first call is to 0x80413908 with no arguments**, inside the GCC-compiled libc block. This is consistent with
   GCC's compiler-inserted `__main()` (global-ctor runner). That is a hypothesis to confirm in Phase 1.
8. **No CodeWarrior/MSL/MetroTRK strings** anywhere in the DOL. **newlib strings are present** (`bug in vfprintf: bad base`).
   A ProDG allocator string is present: `ProDGRegisteredMEM_alloc allocation`.
9. **Mangling is GCC 2.95 cfront-style** in the libmatd symbols: `SetMessage__Q24EAGL11LogFunctioniPce` has no `F`
   for member functions, whereas CodeWarrior would emit `...LogFunctionFiPce`. GCC-only symbols
   `__static_initialization_and_destruction_0` and `_GLOBAL_.I.<file>` also appear.
10. **Overlay sections** (`.*_codeoverlay`) fit the SN linker's overlay support, and there are no `extab`/`extabindex` sections.

### Dolphin SDK version

Build strings all report revision `0x2301`. The libraries were built on **Apr 5 2004** (AI, AR, ARQ, AX, CARD, DSP, DVD, EXI,
GX, PAD, SI) and **Apr 7 2004** (VI). **OS** was built on **May 21 2004 09:28:09**, so OS was patched separately. That date
equals the apploader date. Read together: an April 2004 SDK with a May 2004 OS patch.

### C++

Yes: EAGL namespaces, 87 translation units with static initializers, and about 9k data-to-code pointers (vtables and
callbacks). No RTTI type-name strings were found, so probably `-fno-rtti`. No EH tables, so probably `-fno-exceptions`.
Vtable entry format (GCC 2.95 thunk vs. non-thunk vtables) is not yet characterized; Phase 1 will check it.

### Candidate compilers and how to test them (Phase 1)

- **Game code:** the ProDG builds in the community compilers package used by dtk-template projects (`ProDG/3.5`,
  `ProDG/3.5b140`, `ProDG/3.7`, `ProDG/3.8.1`, `ProDG/3.9.3`, per nfsmw's `tools/project.py`).
  - Step 1: read each build's `ngccc`/`cc1plus` version banner and look for `2.95.3 SN BUILD v1.76`.
  - Step 2: compile one small game leaf function under each candidate (flag axes: `-O1`/`-O2`, `-G` small-data threshold,
    `-fno-rtti -fno-exceptions`, `-mps-nodf`) and check it in objdiff.
  - The `libmatd.a` objects are a **free calibration target**: they were built by v1.76 and come with full debug info.
    That makes it possible to test candidate compilers before any DOL code is touched, without writing a single
    "decompiled" function.
- **SDK:** MWCC `GC/1.2.5n` first, then its neighbors, with standard SDK flags (`-O4,p -proc gekko -fp hardware`
  as in nfsmw). Test on a tiny OS function such as `__OSPSInit`.

---

## 3. Size and shape

| Region | Range | Bytes | Est. functions | CW-style |
|---|---|---|---|---|
| `.init` (crt0) | 0x80003100–0x8000348b | 908 | 6 | — |
| Game `.text` | 0x800034a0–0x8035ffff | 3.36 MB | 14,947 | 1 |
| EA shared libs (probable) | 0x80360000–0x80401fff | 0.63 MB | 2,776 | 2 |
| Dolphin SDK (CW) + SN libc (GCC) | 0x80402000–0x8043fdbf | 0.24 MB | 1,373 | 310 |
| `.frontend_codeoverlay` | 0x8043fdc0–0x8052a207 | 0.92 MB | 3,358 | 0 |
| `.database_codeoverlay` | 0x8052a220–0x805a2baf | 0.47 MB | 1,775 | 0 |
| **Total** | | **5.62 MB** (5,896,860) | **≈24,200** | |

- The function count is a heuristic: the union of `bl` targets, data-to-code pointers, and prologues after returns.
  Treat it as ±10%; dtk's analysis will give the real number in Phase 1.
- Split: **game ≈83%**, **EA shared libraries ≈11%** (EAGL graphics, EA audio/speech, AV/VP6 video, gamelib/animlib),
  **SDK + libc ≈4%**.
- **Shared EA engine code: yes.** EAGL (`libraries/gc/eagl`, "EA Graphics Library"), `gamelib` (`animlib`,
  `corelib`), the EA audio stack (strings `SNDAUTHOR: Tpbuild ...` and `SPCHAUTHOR: TLBuild ...`, AEMS banks), and
  `AV::VideoStreamBuffer` for VP6. These libraries are EA-wide, so other EA GameCube titles of 2003–05 may carry the same code.
  That's worth checking against nfsmw's matched EA code later.
- For comparison, many of the successful GameCube decomps started from a symbol map or debug ELF. This one is large and starts from neither.

---

## 4. Subsystem map (first pass)

**Entry chain:** `__start` 0x80003100 → (crt0 init) → **`main` = 0x8014d63c** → `exit` = 0x80409e6c.
**Top-level loop:** an infinite loop in `main` at 0x8014d664–0x8014d6a0, calling 0x8014c8bc, 0x80148930, 0x8014d1ec,
0x8014d5c0 (inner loop) and 0x8014d488. Names come later; this is the frame loop.

Ranges below come from string cross-references (`lis/addi` pairs plus r13-relative), at 128 KB granularity. Boundaries
are approximate.

| Range | Probable subsystem | Representative evidence |
|---|---|---|
| 0x80000000–0x8001ffff | memory manager, startup, audio volume tuning | `Memory initialized: Mempool is %d bytes`, `GC malloc() allocation` |
| 0x80020000–0x8003ffff | fielding AI tuning, ball | `PopUpInfieldExtension`, `OutFielderDirectDist`, `ai/physics/ball.cpp` refs |
| 0x80040000–0x8007ffff | audio event system, commentary (PBP), crowd, mixers | `EventCategoryConstraints.csv`, `pbp_speech`, `cAmbientAudioMixer`, `backend.cpp` |
| 0x80080000–0x8009ffff | stats/data loading, pitch AI | `lhbstats.dat`, `Obvious pitch - location` |
| 0x800a0000–0x800bffff | front-end manager / screens | `cFEManager::Init() ...` |
| 0x800c0000–0x8011ffff | momentum/sim tuning, in-game HUD | `WinSimPCTEffectOnMomentum`, `PITCHERINFOGRID` |
| 0x80120000–0x8015ffff | **main + game loop**, in-game menus, script VM, camera/replay | `cGoto,cGosub,...`, `REPLAYENTER` |
| 0x80160000–0x801bffff | team AI managers, bullpen/bench, umpire, stadium quotas | `aimanager.cpp`, `bullpenai.cpp`, `defsubstitutionmgr.cpp`, `Variable Strike Zone Call` |
| 0x801c0000–0x8023ffff | **batting/contact model**, fielder positioning, pitch effectiveness | `ContactQuality,...InfluenceOnBallSpeed`, `Pitch_Effectiveness_Spline` |
| 0x80240000–0x802bffff | skills tunables, **animation goals/choosers**, anim banks, asset preload | `catchgoal.cpp`, `reachgoal.cpp`, `animation bank` |
| 0x802c0000–0x8031ffff | camera, **pitch types/movement**, hitting UI, crowd/player LOD | `none,changeup,curve,knuckle,...`, `ImperfectMovSecondary` |
| 0x80320000–0x8035ffff | debug/cheat menus, pitch-break tuning, memory card thread | `-- Pitch Break Tuning --`, `MC_ThreadInterfaceStack` |
| 0x80360000–0x80401fff | **EA libs:** MVP render methods, AV (VP6), EA SND/speech, EAGLAnim, EAGL core | `MVPLitTextureEnvIrrad_Skin`, `AV::VideoStreamBuffer`, `EAGL::SymbolPool::mpSymbolTable` |
| 0x80402000–0x8043fdbf | **Dolphin SDK** (CW) interleaved with **SN newlib** libc | `bug in vfprintf: bad base`, `DVDReadAsync(): ...` |
| 0x8043fdc0–0x8052a207 | **front-end overlay:** franchise/dynasty/owner mode, season sim state machine, PBP text, finances | `Run Player Progression (Dynasty Only)`, `From SIMSTATE_SIMMING`, `grounded into fielder's choice to ...` |
| 0x8052a220–0x805a2baf | **database overlay:** data lookup, trades, rosters, progression and contract CSV tables | `datalookup.cpp`, `TRADEPLAYERS`, `progpinc.csv`, `contract.csv` |

Keyword hit concentration (count of string references, then top 64 KB buckets):

- franchise / dynasty / owner / trade / rating: mostly 0x8044xxxx–0x8052xxxx (overlays).
- pitch (415): 0x800f, 0x8011, 0x8023, 0x802f.
- batting/swing (223): 0x801c–0x801d.
- umpire: 0x801b.
- camera / replay: 0x8015, 0x802d, 0x8035.
- audio / PBP: 0x8004–0x8005.
- EAGL / render (277): 0x803d–0x803e.
- `.big` loading: 0x802b, 0x800c.

---

## 5. Prior art (searched 2026-10-10, nothing downloaded)

- **MVP Baseball (any year) on GameCube:** found no public decompilation or RE project.
- **`dbalatoni13/nfsmw`** (NFS Most Wanted, GameCube `GOWE69`, also EA) is the closest template. Per its
  `configure.py`/`tools/project.py`: dtk `v1.8.32`, objdiff `v3.7.0`, binutils `2.42-1`, compilers package tag `20260903`;
  game code on `ProDG/3.9.3` via `ngccc.exe`/`ngcld.exe`; Dolphin SDK on MWCC `GC/1.2.5n`. On Windows it runs ProDG
  natively; on Linux it goes through wine. **Difference:** nfsmw had an unstripped `NFSMWRELEASE.ELF` with DWARF. We don't.
- `cobanov/nfsu2-decomp` (adapted from nfsmw) also lists SN ProDG for GameCube.
- **SDK reference code:** Dolphin SDK reconstructions exist inside several CodeWarrior game decomps (e.g. Melee, BFBB,
  Twilight Princess `libs/dolphin`). I have **not yet** identified one matching *this* SDK (Apr 2004, rev 0x2301);
  that is a Phase 2a task.
- **Data formats:** BIGF, SCHl, SHPG and VP6 are EA formats long documented by modding communities. The PC version of
  MVP 2005 (same `source/common` tree) has an active modding scene whose roster/ratings/DB knowledge plausibly carries
  over to the `/data/database` and `.big` contents. Not yet verified.

Sources: [nfsmw](https://github.com/dbalatoni13/nfsmw),
[nfsu2-decomp](https://github.com/cobanov/nfsu2-decomp), [decomp-toolkit](https://git.axiodl.com/encounter/decomp-toolkit),
[dtk-template](https://git.axiodl.com/encounter/dtk-template/raw/commit/0427fd1e1d3ac9be5d8b7d77bf79d8dfc5bbca91/README.md),
[ProDG (Wikipedia)](https://en.wikipedia.org/wiki/ProDG_(software)), [Melee decomp](https://github.com/doldecomp/melee),
[BFBB decomp (DeepWiki)](https://deepwiki.com/bfbbdecomp/bfbb).

---

## 6. Host readiness

| Tool | Status |
|---|---|
| OS | Windows 11 Pro 10.0.26200 (native). WSL2 `Ubuntu` is installed (stopped) |
| git | 2.44.0 ✅ |
| Python | 3.12.10 ✅ |
| ninja | ❌ missing |
| Ghidra | ❌ missing |
| JDK | ❌ missing (`java` not on PATH, `JAVA_HOME` unset) |
| Node | v24.18.0 ✅ (meets 24.11+) |
| REA (`rea-agents doctor`) | ❌ not installed; not run, because running it via `npx` would download and install a package |
| GitHub CLI | 2.83.0 installed, **not logged in** |
| Disk | 236 GB free on C: |

Install commands (owner runs these, or approves me running them):

```bash
winget install Ninja-build.Ninja
```
```bash
winget install EclipseAdoptium.Temurin.21.JDK
```
```bash
gh auth login
```

- **Ghidra:** a release from github.com/NationalSecurityAgency/ghidra, plus a GameCube loader extension.
- **REA:** `npx rea-agents setup`, then `npx rea-agents doctor`, as the kit README says.

**Can the compilers run here?** Yes, natively. `ngccc.exe`/`ngcld.exe` (ProDG) and `mwcceppc.exe` (MWCC) are Win32
executables. nfsmw runs them directly on Windows with no wrapper. Under WSL/Linux they'd need wine (ProDG) or wibo (MWCC).
**I recommend native Windows for the build.** The README preferred Linux mainly for REA and wibo; ProDG flips that trade-off.

---

## 7. Recommendation, risks, owner decisions

### Recommended path: `prodg-hybrid` (staged)

1. **Phase 1a, scaffold (compiler-independent):** dtk-template, with the build modeled on nfsmw's ProDG support
   (`ngcld` link, MWCC for SDK objects). Configure `GV4E69` from `main.dol`, with section names taken from `mvp.elf`,
   `_SDA_BASE_`=0x806f69c0, no extab, GCC-style ctor lists, overlay sections. **Exit:** a DOL with SHA-1
   `da6becdb…84dd`, built from split assembly only.
2. **Phase 1b, compiler gate:** identify which ProDG build is "SN BUILD v1.76" or reproduces its codegen. Calibrate on the
   `libmatd.a` objects (known compiler, debug info available), then match one small SDK function (MWCC) and one small
   game function (ProDG) in objdiff.
   - **If no ProDG build reproduces game codegen,** stop and ask: (a) match SDK/libc only and switch game code to
     "functional" mode, or (b) look for the exact compiler build elsewhere (owner-sourced, legally).
3. Then Phase 2a/2b as in `docs/PHASES.md`.

**Alternatives:** `functional` (skip byte-matching for game code entirely; much faster, gives up the verifier). Or `cw`
(standard dtk-template CodeWarrior path), which the evidence says would not work.

### Top 5 risks

1. **Exact compiler build unavailable.** Public packages carry ProDG 3.5–3.9.3, and none is confirmed to be "2.95.3 SN BUILD
   v1.76". Different SN patch levels can change scheduling and register allocation, which breaks matching. GCC 2.95 is
   also generally less forgiving to match than MWCC.
2. **No symbols, no map.** About 24k functions start as `fn_80XXXXXX`, and translation-unit boundaries and link order
   must be inferred. Partial mitigations:
   - 87 `.ctors` entries, one per TU with static init, act as TU anchors.
   - Assert and source-path strings.
   - EAGL DWARF from `libmatd.a`.
   - Debug-menu and class-name strings.
   - Possibly nfsmw's matched EA library code.
3. **Scale.** 5.6 MB of code is several times a typical first-party GameCube decomp. Realistically this is many months,
   and full matching may never finish. Prioritization (sim/ratings/franchise logic first) matters.
4. **Tooling assumptions.** dtk's analysis is tuned for CodeWarrior binaries: r2 as `_SDA2_BASE_`, extab, and
   `__init_cpp_exceptions`. GCC/SN specifics will likely need manual config (symbols, splits, section mapping): r2
   unused, `__main`, crtstuff ctor lists, overlay sections, newlib. Byte-identical relinking may also depend on using
   `ngcld` and reproducing its section and padding behavior.
5. **Target mismatch.** The kit targets 2004, the disc is 2005. If the owner specifically wants 2004 (GameCube ID
   unknown, not on disc here), this recon doesn't transfer at the binary level, though the toolchain finding very likely does.

### What the owner must decide (also logged in `docs/DECISIONS.md`)

1. **Target game:** proceed with **MVP Baseball 2005 (GV4E69)**? If yes, the kit's "2004" wording in `CLAUDE.md`
   and the README should be updated by you; I won't edit `CLAUDE.md` unasked.
2. **Path:** reply `approved: prodg-hybrid` (recommended), `approved: functional`, or redirect.
3. **Host:** native Windows (recommended) or WSL2.
4. **Phase 1 downloads (tools only, no game data):** dtk-template (git clone), decomp-toolkit, objdiff, binutils,
   wibo/sjiswrap if needed, the community compilers package (contains ProDG + MWCC builds), and ninja. Say yes to these as a group.
5. **GitHub:** create the **private** repo and run `gh auth login`. Phase 1 needs `gh` for unit issues and CI.
   Nothing has been pushed; the repo is local only.
6. **`.claude/settings.json`:** copied verbatim from the kit. Once Phase 1 places the verifier, you may need to adjust its
   deny paths (`tools/verify/**`). That file is yours to edit; I'm blocked from it.

### Conflicts noticed between kit files

- `prompts/00_KICKOFF.md` Phase 1 is written "for the standard CodeWarrior path". This project isn't on it, so Phase 1
  steps 2–4 need the ProDG-hybrid adaptation above. `CLAUDE.md` wins on everything else.
- `CLAUDE.md` says "MVP Baseball 2004". The disc is 2005 (decision 1).
