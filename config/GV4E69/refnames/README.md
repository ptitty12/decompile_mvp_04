# Reference names (EA's own names for our functions)

Imported 2026-10-13 from the public MVP 2005 decomp
[mitsevox/mvp2005](https://github.com/mitsevox/mvp2005) (`config/GV4E69/refnames/`, commit
`f1e1763bf76b`). They are released under CC0-1.0. Names and addresses only: no code or data from
any game is here.

Each TSV lists MVP Baseball 2005 (`GV4E69`) addresses whose code matched a function in one EA
GameCube build that ships a symbol file or linker map, with that build's name for it. The match
fingerprints each function with linked addresses masked (branch targets and the 16-bit
immediates of loads, stores, `addi`, `addis`, `lis`), and counts it only when the fingerprint is
unique on both sides and the function has at least 12 instructions.

Columns, tab-separated, no header: MVP address, size, name in the reference build, the reference
build's object path. The object path is filled only for builds that ship a linker map (fifa05,
sims2, uefa); those names are demangled with full parameter types.

| File | Source build (GameCube) |
|---|---|
| bond.tsv | 007: Agent Under Fire |
| ff.tsv | Freedom Fighters |
| fifa03.tsv | FIFA Soccer 2003 |
| fifa04.tsv | FIFA Soccer 2004 |
| fifa05.tsv | FIFA Soccer 2005 |
| ge.tsv | GoldenEye: Rogue Agent |
| hp.tsv | Harry Potter and the Goblet of Fire |
| moh2.tsv | Medal of Honor: Frontline |
| moh3.tsv | Medal of Honor: Rising Sun |
| moh4.tsv | Medal of Honor: European Assault |
| nascar.tsv | NASCAR 2005: Chase for the Cup |
| nfsmw.tsv | Need for Speed: Most Wanted |
| nfsu.tsv | Need for Speed: Underground |
| sims2.tsv | The Sims 2 |
| uefa.tsv | UEFA Champions League 2004-2005 |

How reliable they are, per the source project's own checks:
- FIFA 2005 and UEFA (two maps) name 1,082 of the same functions and never disagree.
- The library block (EA graphics/audio/video/system libraries, SDK, C library) is reliable.
- Hits in MVP's game code are mostly look-alikes from other games; tools flag them.

Checked 2026-10-13 against the owner's own UEFA Champions League 2004-2005 disc (`GUCP69`): all
1,250 names in uefa.tsv appear in that disc's `fifa_z.map`.

Use `python tools/match/refnames.py <fn>` to look a function up. `twins.py show` prints the
reference names of a target and its callees. Names here are hints and naming evidence (tier E2,
"name from a related EA build"); renaming a symbol is still a symbols.txt change with the evidence
in the commit.
