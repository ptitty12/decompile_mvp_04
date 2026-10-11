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
