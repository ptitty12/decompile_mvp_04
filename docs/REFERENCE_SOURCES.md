# Reference sources: what was checked, and what each gives

Every outside source examined for this decomp, with a verdict, so nobody
re-checks one. Earlier research is in `docs/REUSE.md` and `docs/SPEEDUPS.md`
(items 6, 7, 14-19). Last updated 2026-10-13 by the "REA library usage" side
session, with the owner's material.

**Nothing from any game is committed.** Extracted files live outside the repo,
in `C:\Users\Patrick Taylor\tools-ext\` (`re4-ref\`, `ref-discs\`). Only names,
layouts, formats and our own notes enter the repo.

## Used

| Source | What it gave us | Where it is in the repo |
|---|---|---|
| mitsevox/mvp2005 (public MVP 2005 decomp, CC0) | EA's names for 2,077 of our addresses. 15 EA GameCube builds with symbols or maps were fingerprinted against MVP. Covers 257 of 311 unmatched EA-library functions, all 44 unmatched sound functions and 85 of 134 SDK functions. Almost none of the baseball code. | `config/GV4E69/refnames/`, `tools/match/refnames.py`, `twins.py show` |
| adonis-singh/re4 (Resident Evil 4 GC, same compilers: ProDG GCC 2.95.3, CodeWarrior GC/1.2.5n) | (1) The compiler-behavior notes behind its 526 `COMPILER-DIFF` tags. (2) Dolphin SDK bodies that compile identically with our flags: 10 functions / 8.9 KB merged (`aa9bfc7b`). About 12 KB more needs unit splits along the original SDK files with `-opt nopeephole`; the lead has the list. | `docs/PATTERNS.md` (RE4 section), `docs/DECISIONS.md` (SDK reuse source) |
| UEFA Champions League 2004-2005, GameCube (`GUCP69`), owner's disc | `fifa_z.map`: EA's full SN linker map (demangled signatures, object paths). All 1,250 names in `refnames/uefa.tsv` appear in it. `fifa_z.elf` has no symbol table. | confirms `refnames/uefa.tsv` |
| MVP Baseball 2004 GameCube datafile (text, from the owner's mods folder) | EA datafile class schemas. 110 of its 131 classes are used by 261 MVP 2005 functions (14 unmatched, 15.7 KB on 2026-10-13). | `config/GV4E69/datafile_schemas.tsv` (names only), `tools/match/datafile.py`, `docs/GAME_DATA.md` §1 |
| MVP 2005 PC modding tools (tywiggins's exporter/editor, schedule tools, EAZIP, fshtool, MVPSavReader docs) | Database tables, player-record fields, enums, standings and schedule formats, team order, archive formats | `docs/GAME_DATA.md` §2-5 |

## Checked, nothing usable

| Source | Finding |
|---|---|
| Need for Speed: Most Wanted, GameCube (`GOWE69`), owner's disc | Retail `Speed.dol` only, no symbols. (`refnames/nfsmw.tsv` already covers the NFS names.) |
| FIFA Soccer 2005 (USA) `.bin/.cue` | A PlayStation 1 disc: MIPS, different code base. |
| MVP Baseball (PSP) | `BOOT.BIN` unencrypted, but `.symtab` is empty. No maps. |
| MVP Baseball 2003 / 2004 / 2005 (PS2) | `SLUS_206.50`, `SLUS_208.68` and `SLUS_211.35`, plus the `NTGUI` ELFs: all stripped (2003's `.mdebug` is empty). No map files on the discs. |
| MVP 07 NCAA Baseball (PS2) | `SLUS_215.82` and `EA_DASH.ELF` stripped, no maps. |
| MVP Baseball 2003 Xbox preview build (Dec 2002, a prototype, not an owner disc) | Release and debug PE executables, no COFF symbols, no PDB. The debug build's asserts name 651 source files under `d:/tp/source/...` ("tp" is probably Triple Play, MVP's predecessor), and 56 of them also appear in MVP 2005 GC's asserts. Possible later use: naming our `tu_XXXXXXXX` units through shared strings. |
| mitsevox/tw2004 (Tiger Woods 2004 GC, complete matching decomp, CC0) | EA Tiburon's C engine built with CodeWarrior. No EA SND/EAGL/AV code and a different compiler, so nothing to port. Useful only as an example of a finished EA decomp's workflow (`name_sources.tsv` tiers). |
| Box-art scans (MVP 07, Internet Archive item) | Images only. |
| Dolphin and Cxbx bundles in the mods folder | Stock emulators. The Cxbx symbol cache names only Microsoft Xbox SDK functions. Dolphin's `GV4E69` patch is noted in `docs/GAME_DATA.md` §5. |

## Refused

- A folder of scene releases (a HOODLUM crack with SafeDisc 4 removed,
  CloneCD and mini-images), and the mods folder's `KEYS AND IMAGES`
  (CD key, no-CD executable, SafeDisc shim). CLAUDE.md forbids circumventing
  copy protection; these were not opened beyond their `.nfo` text.

## Still worth looking for (owner's own copies only)

1. **MVP Baseball 2004 for GameCube.** Same platform and compiler, one year
   older. Our 2005 disc ships `/mvp.elf` stripped; if the 2004 disc's ELF or
   any file on it kept symbols, shared code could be matched byte for byte and
   named. This is the best remaining hope for the baseball code.
2. **Magazine or EA sampler demo discs** with an MVP 2004/2005 demo (PS2,
   Xbox, GameCube). Demo builds are often unstripped.
3. **MVP 06 NCAA Baseball (PS2).** Same engine; check its executable and the
   disc for maps.

## Ideas not done yet

- **Overlay builds on our own disc (found 2026-10-14).** `/data/ovlay.big` holds the front-end and
  database code overlays the game reloads at runtime. They are RefPack-compressed and unpack to exactly
  the DOL's `.frontend_codeoverlay` (0xEA448) and `.database_codeoverlay` (0x78990) sizes. The disc
  also carries two other builds that retail code doesn't reference by name:
  - `ovlay_d.big`: database 0x102BE8 bytes, front end 0x1C8B44 bytes, about twice the size;
  - `ovlay_m.big`: database 0x794C0 bytes, front end 0xEED68 bytes.

  If `_d` is a debug or unoptimized build, its strings, asserts and simpler code could name and type
  much of `fe/` and `db/`, which is useful for K2. Read only on the owner's machine; never extract into
  the repo.

- **Unit names from the 2003 debug build's file list:** link our units to
  source files through strings both builds use. This improves readability
  only.
- **A C-flattened header export,** so `m2c --context` gets typed drafts
  (SPEEDUPS #18).
- **mitsevox/mvp2005's `filemap.tsv`** (TU boundaries and EA object names from
  the FIFA05/UEFA maps). Not imported yet; useful for the lead's EA-library
  splits.
