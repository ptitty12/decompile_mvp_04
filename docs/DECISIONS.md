# DECISIONS (owner-approved only)

Agents may propose entries under "Open questions"; only the owner moves them to "Decided".

## Decided
<!-- YYYY-MM-DD | decision | why | evidence -->

- 2026-10-10 | **Target is MVP Baseball 2005, GameCube `GV4E69` (USA, rev 0).** Owner said in chat: "yes we are using 2005, you can edit all of that yourself"; the agent updated the game name in CLAUDE.md, README.md and prompts/00_KICKOFF.md. | The owner's disc is 2005. | `docs/RECON_REPORT.md` §1
- 2026-10-10 | **Path: `prodg-hybrid`.** Game code and EA libraries are matched with SN ProDG (GCC 2.95.3 "SN BUILD v1.76", exact build to be located). The Dolphin SDK is matched with Metrowerks CodeWarrior. There is a compiler gate after the Phase 1 scaffold: if no available ProDG build reproduces game codegen, stop and ask the owner. | Toolchain evidence | `docs/RECON_REPORT.md` §2, §7
- 2026-10-10 | **Host: native Windows** (owner: "use whatever"; agent's recommendation). | ProDG `ngccc`/`ngcld` and MWCC are Win32 executables and run natively; no wine/wibo needed. | `docs/RECON_REPORT.md` §6
- 2026-10-10 | **Phase 1 tool downloads approved** (no game data): dtk-template, decomp-toolkit, objdiff, binutils, community compilers package, ninja. Ghidra/JDK/REA were not part of this approval. | Needed for the scaffold | owner reply in chat
- 2026-10-10 | **GitHub remote deferred.** The owner will log in to GitHub later. Until then the repo stays local; GitHub issues, CI runs and pushes wait. | — | owner reply in chat

## Open questions for owner
<!-- YYYY-MM-DD | question | context | options -->

- 2026-10-10 | **SDA/section layout to encode in dtk config** (informational, needs no approval unless dtk can't express it) | r13 = 0x806f69c0 is the only small-data base and r2 is unused. Three overlay sections live inside DOL T1. There are no extab/extabindex sections. `.ctors`/`.dtors` use GCC `-1 … 0` lists. | handled in Phase 1 config; escalate only if it needs dtk changes
