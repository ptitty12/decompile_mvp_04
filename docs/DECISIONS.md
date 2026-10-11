# DECISIONS (owner-approved only)

Agents may propose entries under "Open questions"; only the owner moves them to "Decided".

## Decided
<!-- YYYY-MM-DD | decision | why | evidence -->

## Open questions for owner
<!-- YYYY-MM-DD | question | context | options -->

- 2026-10-10 | **Target game: MVP Baseball 2005 (GV4E69) instead of 2004?** | The disc in the repo is `GV4E69` "MVP Baseball 2005" (USA, rev 0). The kit, `CLAUDE.md` and the README say 2004. Internally the game was built from a `C:/mvp2004/` tree. | (a) proceed with 2005 and the owner updates the "2004" wording in CLAUDE.md/README; (b) supply a 2004 dump and redo Phase 0
- 2026-10-10 | **Matching path** | Game + EA libs were built with SN ProDG, `GNU C++ 2.95.3 SN BUILD v1.76`. The Dolphin SDK is Nintendo's CodeWarrior build. No symbols. See `docs/RECON_REPORT.md` §2 and §7. | (a) `prodg-hybrid` staged, with a compiler gate after Phase 1 (recommended); (b) `functional` mode for game code; (c) `cw` standard path (evidence says it won't match)
- 2026-10-10 | **Build host** | ProDG `ngccc`/`ngcld` and MWCC are Win32 exes that run natively here. WSL/Linux would need wine for ProDG. | (a) native Windows (recommended); (b) WSL2 Ubuntu + wine/wibo
- 2026-10-10 | **Phase 1 tool downloads** (no game data) | Needed: dtk-template (git clone), decomp-toolkit, objdiff, binutils, community compilers package (ProDG 3.5–3.9.3 + MWCC), ninja; wibo/sjiswrap only if required. | approve as a group / approve individually / supply them yourself
- 2026-10-10 | **GitHub remote + gh auth** | The repo is local only, nothing pushed. Phase 1 needs `gh` for unit issues and CI. | owner creates the PRIVATE repo, runs `gh auth login`, and tells the agent the remote URL
- 2026-10-10 | **SDA/section layout to encode in dtk config** (informational, needs no approval unless dtk can't express it) | r13 = 0x806f69c0 is the only small-data base and r2 is unused. Three overlay sections live inside DOL T1. There are no extab/extabindex sections. `.ctors`/`.dtors` use GCC `-1 … 0` lists. | handled in Phase 1 config; escalate only if it needs dtk changes
