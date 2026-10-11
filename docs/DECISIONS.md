# DECISIONS (owner-approved only)

Agents may propose entries under "Open questions"; only the owner moves them to "Decided".

## Decided
<!-- YYYY-MM-DD | decision | why | evidence -->

- 2026-10-10 | **Target is MVP Baseball 2005, GameCube `GV4E69` (USA, rev 0).** Owner said in chat: "yes we are using 2005, you can edit all of that yourself"; the agent updated the game name in CLAUDE.md, README.md and prompts/00_KICKOFF.md. | The owner's disc is 2005. | `docs/RECON_REPORT.md` §1
- 2026-10-10 | **Path: `prodg-hybrid`.** Game code and EA libraries are matched with SN ProDG. The Dolphin SDK is matched with Metrowerks CodeWarrior. | Toolchain evidence | `docs/RECON_REPORT.md` §2, §7
- 2026-10-10 | **Host: native Windows.** | ProDG `ngccc`/`ngcld` and MWCC are Win32 executables and run natively. | `docs/RECON_REPORT.md` §6
- 2026-10-10 | **Phase 1 tool downloads approved** (no game data): dtk-template, decomp-toolkit, objdiff, binutils, community compilers package, ninja. | Needed for the scaffold | owner reply in chat
- 2026-10-10 | **GitHub remote: private repo `ptitty12/decompile_mvp_04`.** The owner logged in to `gh`; the repo is private. | The kit and the dtk docs require private hosting. | owner reply in chat; `gh repo view` shows `PRIVATE`
- 2026-10-10 | **Blanket approval.** Owner, in chat: "yes i approve all things good job, don't come back to me with action items unless you physically need my help, i trust you for all other things". All open questions below were resolved on that basis. | — | owner reply in chat
- 2026-10-10 | **Phase 1 build pipeline approved as implemented**:
  - split input is an analysis DOL made from `/mvp.elf` (`tools/mkdol.py --per-section`);
  - link with SN `ngcld` 1.5.1.692 and `config/GV4E69/ldscript.ld`;
  - DOL packed by `tools/mkdol.py --layout config/GV4E69/dol_layout.txt`;
  - overlay input sections renamed `.feoverlay`/`.dboverlay`;
  - `LONG(0)` terminators for `.ctors`/`.dtors`;
  - documented `add_relocations`;
  - marked ProDG patch in `tools/project.py`.

  | Upstream dtk-template can't reproduce this game's DOL. `mkdol --segments`/`--layout` turn retail `/mvp.elf` into retail main.dol byte-for-byte. | commits `f91c043`, `84e39d7`
- 2026-10-10 | **Compilers.** Game code + EA libraries: ProDG 3.9.3 = `GNU C++ 2.95.3 SN BUILD v1.76` (exact banner match with the on-disc EAGL objects). Dolphin SDK: MWCC GC/1.2.5n. Flags are pinned per library as functions match; see the "Flags" entries below. | Banner match; objdiff probes at 100% | `docs/RECON_REPORT.md` §2
- 2026-10-10 | **Small-data bases (SN convention):** `_SDA_BASE_` = .sdata + 0x8000 (r13 = 0x806F69C0); `_SDA2_BASE_` = .sdata + 0x18000 (r2 = 0x807069C0, unusable, so .sdata2 is reached via r13). | retail crt0 @ 0x80003108..0x80003114 | `config/GV4E69/ldscript.ld`
- 2026-10-10 | **Flags: SN libgcc** = ProDG 3.9.3 `-O2 -G0`. | `__do_global_ctors` + `__main` at 100% | `libgcc/_main.c`
- 2026-10-10 | **Flags: game code** = ProDG 3.9.3 `-Os -G0 -fno-rtti -fno-exceptions` (`cflags_game` in configure.py). Evidence:
  - `-Os`: `-O2` gave wrong register choices (r30/r31 swapped) in fn_802709D0; `-Os` matched every function tried.
  - `-G0`: no r13 small-data use anywhere in game .text or the overlays.
  - no RTTI: empty RTTI vtable slots.
  - no EH: no exception tables in the binary.

  EA shared libraries do use r13 small data, so their flags differ (TBD). | 19 functions at 100% in `animation/choosers/playeridchooser.cpp` | commit `6ea98bd`
- 2026-10-10 | **Flags: game code += `-ffloat-store`.** Float locals live in stack slots with a store/reload after every assignment (e.g. fn_8026D504, fn_802721E0, fn_802726BC), which is what `-ffloat-store` produces; mitsevox/mvp2005 also measured it for game code. Adding it changes none of the 44 chooser functions (43/44 match with and without it). Applies to the whole `game` lib. | 43/44 chooser functions unchanged | this commit
- 2026-10-10 | **Flags: Dolphin SDK OS (first datapoint)** = MWCC GC/1.2.5n, template base flags + `-char unsigned -opt nopeephole`. Other SDK libraries (built Apr 5 rather than May 21) may differ; confirm per library. | `OSRegisterVersion` at 100% | `dolphin/os/OS.c`
- 2026-10-10 | **The three Phase 1 probe functions are committed as the first matches.** | They're public-source functions (GCC `libgcc2.c`; Dolphin SDK). | owner approval
- 2026-10-10 | **Verifier + CI installed** from `proposed/`. CLAUDE.md's "verification tooling" means `tools/verify/**`, `.github/workflows/**` and the files listed in `tools/verify/protected.sha256`. | owner approval of the staged files | `tools/verify/`
- 2026-10-10 | **CI hosting:**
  - The `integrity` job runs on GitHub-hosted runners (no game data).
  - The full-build job runs only on a self-hosted runner, and only when the repository variable `GV4E69_SELF_HOSTED` is `true`. No runner is set up yet: that would install a persistent service on the owner's machine, which the agent didn't do unprompted.
  - Until then, agents run `python tools/verify/verify.py --baseline-ref origin/main` locally before every push.

  | Game files never leave the owner's machine | `.github/workflows/build.yml`
- 2026-10-10 | **Original-assembly functions stay as split assembly.** The CLAUDE.md no-asm rule is kept as written. Functions that were hand-written assembly in the original sources are excluded from matching and listed in `docs/UNITS.md` as "original-asm". Examples: SN crt0, PPCArch `PPCMf*/PPCMt*`, `PPCHalt`, OSContext save/restore, `__save_gpr`/`__restore_gpr`. | Keeps the hard rule intact; the agent chose the conservative option under the blanket approval. | CLAUDE.md hard rules
- 2026-10-10 | **Push to `origin` and create one GitHub issue per provisional unit** (`docs/UNITS.md`). | owner approval | —
- 2026-10-10 | **No human in the loop: agents push straight to `main`.** Owner, in chat: "i never need to code review anything, you can push straight, there should be no human in the loop". This replaces the PR and review steps in `prompts/10_WORKER.md`. The gate is the verifier: `python tools/verify/verify.py --baseline-ref origin/main` must PASS on the exact commit being pushed. Never force-push; rebase on `origin/main` if it moved, then verify again. One unit per commit (CLAUDE.md); close or update unit issues with `gh`. | owner reply in chat | —
- 2026-10-10 | **SDK units that contain original-assembly functions or unreproduced data stay NonMatching (not linked).** Their C functions count as matched when objdiff reports 100%. Example: `dolphin/os/OS.c` (its .sdata/.data must be complete, and its exception-vector functions are original asm). | Linking a partial MWCC unit shifts .sdata (8-byte section alignment). | commit `17f0041`

- 2026-10-10 | **Verifier rename/code-less-unit fix installed by the owner** (commit `87d2cc9`): functions missing by name fall back to (unit, address, size); code-less units are skipped at the unit level. | Two false positives blocked pushing new units. | Tested PASS on both false-positive cases, FAIL on synthetic real drops.
- 2026-10-10 | **The lead holds full decision authority.** Owner in chat: "yeah i have faith in you do whatever you have fill authority" (after approving the Opus-lead + Sonnet-worker plan with "go"). Decisions taken under it are marked *[lead, owner authority]*. It does not cover relaxing the verifier (its rules, allowlist or config): those stay the owner's specific call. Protected files (`tools/verify/**`, `.github/workflows/**`, `.claude/**`) still need the owner's own hands: agents are denied edits there by `.claude/settings.json`. | Owner wants the project to run without owner steps. | chat, 2026-10-10
- 2026-10-11 | **The animation choosers/goals region is one retail TU (a unity build)** *[lead, owner authority]*. Evidence: one static initializer (`fn_802AA7A4`, 0x106C bytes, called from `_GLOBAL_.I` at 0x802ACD88) sets up globals used across all the chooser "files" (type hashes such as 0x8068D57C, 0x8068D580); every chooser and helper vtable, slot 3/4 getter and implicit dtor sits after it (0x802AB810..0x802ACD88) in reverse declaration order, as g++ 2.95 emits them at the end of a TU; assert paths name several files (playeridchooser.cpp, randomchooser.cpp, randomloadedchooser.cpp, catchgoal.cpp, reachgoal.cpp, userpickupballgoal.cpp) inside it; and cCircleChooser's `.rodata` (an 8-aligned double at 0x805DC7D8) only fits if its section did not start at 0x805DC70C. Consequences:
  - Keep one split unit per source file for matching (objdiff compares functions either way). Units that already link byte-identically (cEvent/cHand/cPitch) stay linked.
  - Units with doubles in `.rodata` or with helper-class vtables can't link standalone; they stay NonMatching (code-matched) until the region's unity TU (`#include` of each file, then the tail) is assembled and linked as one object.
  - The `#pragma interface`/`#pragma implementation` plan is not needed for this region; the pragmas stay allowed but unused unless another region needs them.
  | Explains the vtable block and the cCircleChooser alignment finding without tricks. | fn_802AA7A4, docs/UNITS.md anchor 45, worker report on tu_80271F14

- 2026-10-10 | **Owner allowed six pragma lines** (commit `f08b79d`; `tools/verify/pragma_allowlist.txt`). Note: verify.py skips every allowlist line starting with `#` as a comment, so the entries have no effect until the one-line fix in open questions is applied:
  - `#pragma cplusplus on` / `#pragma cplusplus reset` and `#pragma dont_inline on` / `#pragma dont_inline reset`: MWCC switches used by the public Dolphin SDK reconstructions we port (W2's pad/si/vi/dsp; `include/libc/math.h`). They reproduce the SDK's own build settings and generate no code by themselves.
  - `#pragma interface` / `#pragma implementation` (g++): every chooser and chooser-helper vtable, the slot 3/4 getters and the implicit dtors sit in one TU at 0x802AC8xx in reverse declaration order (vtables 0x80661EA0..0x80662538). A ProDG 3.9.3 scratch test reproduces this: with `#pragma interface` in the header, the TU defining the class's virtuals emits no vtable, and a TU with a bare `#pragma implementation` emits the vtables in reverse declaration order. This is the only non-trick way to link the helper-class units (cCircleChooser, cLinearChooser, ...). Planned layout: class declarations in `include/game/choosers.h` (`#pragma interface`), implementation TU `src/animation/choosers/choosers.cpp` (bare `#pragma implementation`, same basename).
  - Why: needed to land W2 (80 SDK functions, builds byte-identical) and to link helper-class units. Options: allow all six / allow only the SDK four / allow only interface+implementation / none (W2 stays unmerged; helper-class units stay code-matched but unlinked).

- 2026-10-11 | **Flags: EA shared libraries = ProDG 3.9.3 `-O2 -G0 -fno-rtti -fno-exceptions`** *[lead, owner authority]* (`cflags_ealib`). Evidence (W4, direct compiles): the 0x320 clone function in 5 units matches only at `-O2` (200/200 insns; `-Os` 90%); the 0x704 clone reaches identical structure only at `-O2` (79% vs 55%, registers only); `-O2` hoists loop invariants and initializes a GXColor the way retail does; `-fno-strength-reduce` makes it worse (retail has strength-reduced induction variables); `-ffloat-store` changes nothing here. Every matched static-init pair in all EA-lib units and W5's ealibs units compile identically either way. | -Os was provisional | W4 report, 2026-10-11

- 2026-10-11 | **Original source paths via `#line`** *[lead, owner authority]*: a unit whose retail strings contain its own `__FILE__` (assert/RNG paths like `C:/mvp2004/source/common/animation/choosers/randomchooser.cpp`) starts with `#line 1 "<that path>"`, so `__FILE__` expands to the original bytes. Standard C preprocessor, not a pragma; changes no code. | Our build path differs from the original build machine's. | playeridchooser/randomchooser/randomloadedchooser: strings now equal retail, matches unchanged

- 2026-10-11 | **Early game TUs (0x800034A0..0x8000F598) use the game flags** *[lead, owner authority]*: -Os (a factory loop only matches at -Os; -O1/-O2 fail), -G0 (without it a global loads via r13), -ffloat-store (float-parameter spills). Evidence table in the tu_80008540 merge (031d2d6). | Confirms cflags_game for real standalone TUs, not only the unity TU. | W12 report
- 2026-10-11 | **Known linking issue for real TUs (not blocking matching):** ProDG g++ emits implicit dtors and vtables into .gnu.linkonce.* sections; retail keeps those dtors in the TU's .text (in reverse order) and vtables in its data. `-fno-weak` moves them into .text/.rodata but in a different order. To be solved before the early TUs can link (candidate: link-order/ldscript handling of linkonce sections, which is a protected file). | Recorded so linking work starts from it. | W12 report on tu_80008540
- 2026-10-11 | **0x803401A8..0x803663B0 is game code (`cflags_game`)** *[lead, owner authority]*. objdiff probes:
  - fn_8034151C, fn_80360EF8 and fn_803622B0 score 100% with the game flags.
  - With `cflags_ealib` they score 60.3%, 54.6% and 48.4%: -O2 hoists the loop invariants that retail recomputes inside the loop.
  - Exception: fn_80365C10 (0x7A0 bytes) sits alone after a 0xC-byte alignment gap at 0x80365C04, just before ealib/tu_803663B0. That gap marks an object boundary, so it got its own unit, `game/tu_80365C10`. Its flags are not confirmed.

  | Region split into 38 code-only units for range workers. | setup commits on work/setup-tail
- 2026-10-11 | **Code overlay units** *[lead, owner authority]*:
  - **Declaration.** Units are declared with the split input section: `fe/tu_X.cpp: .feoverlay start:.. end:..` and `db/tu_X.cpp: .dboverlay ...`. They live in the configure.py libs `fe_overlay` and `db_overlay`, which use `cflags_game`.
  - **Section attribute.** objdiff pairs functions only within sections of the same name. A function compiled into `.text` stays unpaired (no score) against the `.feoverlay` target, and `-c combineTextSections=true` doesn't change that. GCC 2.95/ProDG has no flag that renames the text section; the cc1plus and ngccc option strings were searched. So every function defined in `src/fe/` or `src/db/` carries `FE_OVERLAY` or `DB_OVERLAY` from `include/game/overlay.h`, which expands to `__attribute__((section(".feoverlay")))` or `.dboverlay`. It only sets placement and changes no instruction. It is also what the protected ldscript (`*(.feoverlay)`, `*(.dboverlay)`) needs to link a matched overlay object.
  - **Flags.** The overlays use the game flags: retail spills and reloads float parameters, which is the `-ffloat-store` tell.
    - fn_804BC414 (fe): 100% with the game flags, 32.5% with `cflags_ealib`.
    - fn_8052A3C0 (db): 100% vs 71.8%.
    - fn_8047D1AC, fn_8043FDC0 and fn_8043FE44 (fe): 100%.
  - **Limit.** Compiler-generated functions (implicit dtors, out-of-line inlines, thunks) can't take the attribute. They land in `.text` or `.gnu.linkonce.*` and won't pair; same family as the linkonce issue above.
  - **Link-order evidence.** The dtk write-back puts the overlay units at the top of splits.txt. The last fe unit (.ctors 0x805A2C40) and the last db unit (.ctors 0x805A2C44) sort between game/tu_803401A8 (0x805A2C3C) and ealib/tu_803663B0 (0x805A2C48). So in the retail link, the overlays' final TUs came between those two objects.

  | 77 fe and 41 db code-only units for range workers. Build OK; main.dol == retail. | probe on work/setup-tail

## Open questions for owner
<!-- YYYY-MM-DD | question | context | options -->

- 2026-10-11 | **verify.py ignores every `#pragma` line in its allowlist** (it treats lines starting with `#` as comments). Owner's approved pragmas therefore have no effect. One-line fix: treat lines starting with `#pragma` as entries. The exact PowerShell command was given to the owner in chat. Options: apply / leave (W2 can't merge).

