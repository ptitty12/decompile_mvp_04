# PROGRESS

## Snapshot (update each session)
- Phase: **1 (scaffold) exit criteria met; waiting for owner review** (verifier install, CI hosting, push/issues; see `docs/DECISIONS.md`)
- Target: MVP Baseball **2005**, GameCube `GV4E69` (USA, rev 0). `main.dol` SHA-1 `da6becdbea614d03c4b5eae9f8a0fb08e0a184dd`
- Build: `python configure.py && ninja` rebuilds a byte-identical `build/GV4E69/main.dol` from dtk-split assembly (24,158 functions, 5,896,176 code bytes, 199 auto objects)
- Toolchain:
  - game + EA libs: SN ProDG 3.9.3, `GNU C++ 2.95.3 SN BUILD v1.76`. Flags for game code TBD; SN's libgcc matches with `-O2 -G0`.
  - Dolphin SDK: MWCC GC/1.2.5n, template base flags + `-char unsigned -opt nopeephole` (one function so far: OS)
  - linker: SN ngcld 1.5.1.692 + `config/GV4E69/ldscript.ld`; DOL packed by `tools/mkdol.py --layout`
- Functions matched (committed): 0 / 24,158 (0%) | game: 0 | sdk/runtime: 0
  - Not committed: 3 probe functions at 100% in a scratch clone (`__do_global_ctors`, `__main`, `OSRegisterVersion`)
- Last audit: none yet

## Session log (newest last)
<!-- YYYY-MM-DD | agent/model | unit | matched N, abandoned M | blockers | owner decisions needed -->
- 2026-10-10 | Claude Opus 5.5 | Phase 0 recon (no unit) | matched 0, abandoned 0 | Blocked on owner approval. Disc is 2005, not 2004. Toolchain is ProDG GCC 2.95.3 rather than CodeWarrior. No symbols; `/mvp.elf` is stripped. Missing on host: ninja, Ghidra, JDK, REA; `gh` not logged in. | Decide: target game, path (`prodg-hybrid` recommended), host (native Windows recommended), Phase 1 tool downloads, GitHub remote
- 2026-10-10 | Claude Opus 5.5 | Phase 1 scaffold (no unit) | matched 0 committed (3 probe functions 100% in a scratch clone), abandoned 0 | None blocking. Notes:
  - Upstream dtk-template can't build this game, so a ProDG pipeline was added (analysis DOL from `/mvp.elf`, ngcld + static linker script, mkdol layout packing).
  - Verified from a clean clone of `f91c043`: `main.dol: OK`. Final check from a clean clone of `4a1d8de`, with the staged verifier installed as the owner would: `VERIFY PASS` (integrity, hard rules, retail hash, regressions vs HEAD~1).
  - The verifier/CI is staged in `proposed/`, because the agent is denied the target paths. It was tested with 6 pass/fail cases.
  - GitHub issues were not created; that needs the owner's OK.
  - Ghidra/JDK/REA are still not installed (not needed yet).
  | Decide:
  - install the verifier;
  - CI hosting (self-hosted runner recommended);
  - commit the probes?;
  - original-asm SDK functions policy;
  - push + create unit issues;
  - review the Phase 1 pipeline choices.
- 2026-10-10 | Claude Sonnet 5.5 (W3) | ealib/tu_803663B0, 803666EC ... 8036E65C (12 units) | matched 24 funcs (12x __static_initialization_and_destruction_0 + 12x _GLOBAL_.I), setup fns (0x2b0-0xc40) not attempted | none | none
- 2026-10-10 | W4 (Sonnet 5.5) | ealib/tu_8036FEA0 .. tu_80376598 (issues #66-#76) | matched 22 funcs (11x static-init pair), 0 abandoned; 44 large funcs (0x224-0x8x0 param-table ctors/creators) not attempted | none | none
- 2026-10-10 | W5 (Claude Sonnet 5.5) | ealibs/tu_803D9FE8.cpp (#91), ealibs/tu_803D7ED4.cpp (#88/#89 range) | matched 20 (5/6 and 15/16), parked 2 (fn_803DA038 mr r11 near-miss after 6 variants; fn_803D8094 not attempted) | none | EA lib flags -Os -G0 provisional
- 2026-10-10 | Claude Sonnet 5.5 (W1) | dolphin/ai/AI.c (#108) | matched 6 (152 B), attempted 12, parked 6 (AIInitDMA, AIStartDMA, AIStopDMA, AISetStreamPlayState, AISetStreamVolLeft/Right: RMW on constant register base does not reproduce lis+addi base) | unmatched also: AIInit, AISetDSPSampleRate, AISetStreamSampleRate, __AI_SRC_INIT (large), 3 handlers (not attempted) | none
- 2026-10-11 | Claude Opus 5.5 (lead) + Sonnet workers | choosers (tu_80271748/940/C64 linked; tu_80271F14, tu_80272B20), swarm integration, team pipeline | main: 46 -> 142 functions at 100% (W1/W3/W4/W5 merged 74; cCircleChooser 10/11; cLinearChooser 12/13; cEvent/cHand/cPitch 18 linked earlier), every pushed merge verified per commit | Notes:
  - Owner approved the team plan (Opus lead, Sonnet workers; 7 running at session end) and gave the lead full authority; CLAUDE.md now says the owner never runs commands.
  - Flags: game code += -ffloat-store; EA libs switched -Os -> -O2 on W4's evidence (DECISIONS).
  - Found: the animation choosers/goals region is one unity TU (DECISIONS); helper-class units are code-matched but can't link standalone.
  - MISTAKE: cc5d94b (cMatrixChooser setup) reached main with a failing build: the push was gated on a pipe's exit code, not verify.py's. Fixed forward in 9f743e2 (verified against f065b4a). Since then every lead push goes through `tools/team/integrate.py --push` (lead mode), which gates on verify.py per commit.
  - Parked: see docs/NEARMISS.md (cCircleChooser slot 17 at 97.9%, others).
  | Owner: verify.py reads every `#pragma` allowlist entry as a comment (DECISIONS open question). That one-line fix is in tools/verify, which only the owner can edit; W2's 80 SDK functions wait on it.
