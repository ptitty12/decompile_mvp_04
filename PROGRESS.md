# PROGRESS

## Snapshot (update each session)
- Phase: **0 (recon) complete, waiting for owner approval** (see `docs/RECON_REPORT.md`, `docs/DECISIONS.md`)
- Target: MVP Baseball **2005**, GameCube `GV4E69` (USA, rev 0). `main.dol` SHA-1 `da6becdbea614d03c4b5eae9f8a0fb08e0a184dd`
- Toolchain:
  - game + EA libs: SN ProDG, `GNU C++ 2.95.3 SN BUILD v1.76` (seen in on-disc objects; exact build not yet located)
  - Dolphin SDK: Nintendo's CodeWarrior build (MWCC version TBD; first candidate GC/1.2.5n)
  - flags: TBD
- Functions matched: 0 / ≈24,200 (0%)   | game: 0 / ≈22,800   | sdk+libc: 0 / ≈1,370   (estimates; dtk will give real counts)
- Last audit: none yet

## Session log (newest last)
<!-- YYYY-MM-DD | agent/model | unit | matched N, abandoned M | blockers | owner decisions needed -->
- 2026-10-10 | Claude Opus 5.5 | Phase 0 recon (no unit) | matched 0, abandoned 0 | Blocked on owner approval. Disc is 2005, not 2004. Toolchain is ProDG GCC 2.95.3 rather than CodeWarrior. No symbols; `/mvp.elf` is stripped. Missing on host: ninja, Ghidra, JDK, REA; `gh` not logged in. | Decide: target game, path (`prodg-hybrid` recommended), host (native Windows recommended), Phase 1 tool downloads, GitHub remote
