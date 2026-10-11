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

## Open questions for owner
<!-- YYYY-MM-DD | question | context | options -->

(none)
