# E6 log: roster packs in the engine

Working log for milestone E6 (`docs/ROADMAP.md`): pack loading in the engine, a pack
picker on the page, and the pack-set hash in the netplay handshake. Exit: a pack that
changes a team's roster is chosen on the page, the game shows the change, and both
netplay players play with it (both peers must have the same pack set). Newest state
first in "Status"; a later session resumes from "Next step".

## Status (2026-10-15)

| # | Task | State |
|---|---|---|
| 1 | `engine/mods`: format v1 (MODDING.md), cross-checked against `pack.py` | Done: 65 scenarios identical; the real disc byte for byte |
| 2 | `engine/vfs`: RefPack, BIG, the virtual disc's mod overlay | Done; the game boots with the patched files |
| 3 | Native evidence: the example pack on screen | Done (captures local, `build/engine/e6/`) |
| 4 | Page: the Roster packs panel; packs in the Worker | In progress |
| 5 | Netplay: the set hash in the handshake; a mismatch refused | In progress |

## How to build and run (agents)

Native as E1/E3a (`engine/tools/msvc.cmd`, preset `msvc`). From Git Bash, whose
environment drops `ProgramFiles(x86)`, call `vcvars64.bat` directly from a small `.cmd`
wrapper in the scratchpad (vswhere then prints a harmless error).

- `mvp-pack validate|apply|hash|mount-check` (`engine/mods/tools/mvp_pack.cpp`): pack.py's
  commands on the engine's implementation. `apply --out` refuses directories inside a
  git work tree except under its `build/`.
- `mvp-play --pack PATH` (repeatable, set order): packs mounted before boot.
- Tests: `test_common` (SHA-256), `test_vfs` (overlay), `test_mods` (data-free; JSON
  vectors from pack.py, the example pack's documented hashes, a zip), `mods_crosscheck`
  (`python -I engine/mods/tests/crosscheck.py --mvp-pack <exe> --repo .`).

## 1. `engine/mods` (done)

A port of `tools/rosters/pack.py`, module for module: `json` (strict reader with
Python's own error messages and positions, CPython 3.12's scanner; canonical JSON;
Python `repr` for messages), `tables` (database.big tables, LOC files, djb2), `zip`
(central directory, stored and deflate with a small inflate, CRC-32), `pack` (schema,
manifest, every op's static checks, sources: directory, zip, files handed over by a
browser; composition; pack and set hashes), `apply` (model, applier with cell
ownership, final-state rules, rebuilt tables, LOC files and archives, result hash),
`mount` (a pack set on a `vfs::Disc`).

**Cross-check** (`engine/mods/tests/crosscheck.py`, ctest `mods_crosscheck`): pack.py's
own synthetic disc (`test_pack.make_disc`) and test packs (`write_pack`, `new_player`),
65 scenarios: every `test_pack.py` case, static error cases (manifest, ops, assets,
JSON), composition and conflicts, team slots, a kitchen-sink pack plus a dependent one,
zips, the example pack, and the same disc as a GameCube image (pack.py reads it
through gcdisc). For each: the issue lists (severity, code, place, message, in order),
pack hashes, set hash, result hash, changed tables and every output file are
**identical**. On the image, `mvp-pack mount-check` mounts the packs on the virtual
disc and reads every file back through it.

**On the real disc** (local, outputs under `build/engine/e6/`, never committed): the
example pack, applied by `pack.py apply` (4.7 s) and `mvp-pack apply` (0.6 s): the same
9 warnings, set hash `b9a04e65...`, result hash `181b6977...`, and `database.big`
(1,056,803 bytes), `FEENG.LOC` and `IGENG.LOC` byte-identical. `mount-check`: 405
files, 3 replaced (1,531,803 bytes), 0 mismatches.

pack.py behaviours the engine does not copy (bugs in pack.py by MODDING.md's rule
"where they disagree, one is wrong"; none affects a valid pack or any hash of one):
- Python's `re` `$` matches before a trailing newline, so pack.py accepts `"abc\n"` as a
  pack id, `"1.0.0\n"` as a version, `"HCL\n"` as an abbreviation (it then crashes
  serializing team.dat) and `"C:8\n"` as a roster place; `\d` also matches non-ASCII
  digits in versions. The engine follows MODDING.md (no newline, ASCII digits).
  Fix in pack.py: `re.fullmatch` or `\Z`, and `[0-9]`.
- `manager.edit` with `"set": {}` passes the static checks and crashes pack.py's
  applier (`KeyError`); the engine applies nothing.
- `str.upper()` maps U+0131 to `I`, so pack.py accepts `"ıgeng.loc"`; the engine
  compares ASCII case only.

## 2. `engine/vfs` (done)

- `refpack`: decompressor, and pack.py's greedy compressor instruction for instruction
  (hash chains over exact 3-byte keys, the 64 most recent positions), so rebuilt
  archives equal pack.py's.
- `big`: parse, case-insensitive find, rebuild keeping the archive's alignment.
- `overlay`: replaced files are placed past the end of the image on 32 KiB boundaries
  (in path order), their FST entries repointed (the FST keeps its size and names, and is
  patched in place), the GCM re-read. The image ends on the next 32 KiB boundary: the
  game reads in 32-byte units, and the first boot failed reading past the end of the
  relocated `database.big` until the end was padded. The disc identity of the netplay
  handshake is computed before mounting.

## 3. Native evidence (done)

`mvp-play --headless --pack docs/examples/packs/fictional-league` with an E3a-style
script (`nav6` up to Play Now, then UP x4 at Select Team, A, A, A):
- Select Team, home side: **"Harbor City Lanterns"**, rank 28th, category ranks 30th /
  24th / 1st / 28th, with Anaheim's logo (the pack replaces no art). Without the pack the
  same frame shows "Anaheim Angels", rank 6th (20th / 6th / 2nd / 1st). UP from Boston
  reaches the slot after 4 presses: the slot keeps Anaheim's place in the list.
- In game at Angel Stadium, the pre-game **Defensive Lineup** of the home team: J.
  Falkenrath CF, C. Merriweather LF, S. Dunmore RF, O. Varga-Lund SS, F. Quenby 2B, B.
  Halvorsen P, E. Thistlewood 3B, M. Ostrander 1B, D. Arkwright C: the pack's depth chart
  (tweaks.json's catcher swap puts Arkwright in against a left-handed starter). The
  players wear Angels uniforms (no art in the pack).
- MODDING.md §14 question 1 (a larger, recompressed `database.big`): the game loads it
  and plays into a game.
- Without packs nothing changes: MEM1 at frame 1,900 of the menu path is `768b36a8...`,
  E3a's value.

## Next step

Page panel, Worker integration, handshake wiring, browser checks (sections 4 and 5).
