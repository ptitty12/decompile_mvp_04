# Phase 0 recon checklist

Every item gets an answer + evidence in `docs/RECON_REPORT.md`. "Unknown" is an
acceptable answer if you say what would resolve it.

## Disc and binary
- [ ] Game ID, region, revision (from disc header)
- [ ] SHA-1 of the disc image (owner verifies against redump.org)
- [ ] Main executable(s): `main.dol`, any `.rel` / `.rso` modules
- [ ] Section table: `.init`, `.text`, `.ctors`, `.dtors`, `.rodata`, `.data`,
      `.sdata`, `.sdata2`, `.bss`, `.sbss`, `extab`, `extabindex` — sizes/addresses
- [ ] Any linker `.map`, symbol list, unstripped ELF, or debug strings left on disc
- [ ] Asset archive formats (names/extensions only; no extraction into the repo)

## Toolchain (the critical question)
- [ ] CodeWarrior vs. ProDG/GCC vs. other — verdict, confidence, evidence
- [ ] Dolphin SDK build date strings → SDK version
- [ ] MSL / runtime library identification
- [ ] C++ present? (vtables, RTTI strings, exception tables, mangled names)
- [ ] Prologue/epilogue idioms and save/restore helpers
- [ ] Small-data areas (r2/r13) usage
- [ ] Candidate compiler versions + how to test them (a tiny SDK function in objdiff)

## Size and shape
- [ ] `.text` size and approximate function count
- [ ] SDK/library vs. game-code split (rough %)
- [ ] Shared EA Canada engine code identified? (same libs used by other EA GC titles)

## Subsystem map (first pass)
- [ ] `main` and top-level loop
- [ ] Probable ranges for: file I/O & archives, roster/ratings data, franchise/dynasty,
      pitch/bat/ball physics, fielding AI, rendering (GX), audio, UI/menus, memory card
- [ ] Top strings that name subsystems

## Prior art (search, don't download game files)
- [ ] Existing public decomps sharing this SDK/runtime version (for SDK units)
- [ ] Community docs on MVP data formats (PC modding community knowledge of
      rosters/ratings/archives may carry over; note which parts plausibly apply)
- [ ] Any prior MVP GameCube reverse-engineering work

## Host readiness
- [ ] git, Python 3, ninja, Ghidra + JDK, Node, REA doctor result, gh CLI
- [ ] Can the chosen compiler run here (natively or via wibo)?

## Output
- [ ] Recommended path + top 5 risks + what the owner must decide
