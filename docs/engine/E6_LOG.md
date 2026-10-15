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
| 4 | Page: the Roster packs panel; packs in the Worker | Done: Chrome shows the change; browser == native with the pack |
| 5 | Netplay: the set hash in the handshake; a mismatch refused | Done: same set in lockstep; different sets refused, no boot |

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
  (`python -I engine/mods/tests/crosscheck.py --mvp-pack <exe> --repo .`),
  `test_net_protocol` (the refusal text), `test_web_shell` (`tests/packs.test.mjs`: the
  browser module on the example pack as a folder and a zip, a broken pack, the empty set).
- Browser (Emscripten preset, `engine/tools/emsdk.cmd`): targets `mvp-web` (now also
  builds `mvp-packs`). `engine/server` needs `npm ci && npm run build` once for
  `netplay_check.mjs`. Checks: `browser_check.mjs --packs DIR_OR_ZIP,...` and
  `netplay_check.mjs --packs ... [--packs2 ...|none] [--expect-reject]`; outputs and
  screenshots under `build/engine/e6/web/`.

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

## 4. The page and the Worker (done)

- **Panel** (`src/packs.ts`, `#packs` above the disc picker): add pack folders (a
  directory input) and `.zip` files, order them (Up, Down, Remove). Every change is
  checked by `mvp-packs.js` (engine/mods alone, 0.58 MB of wasm, loaded on the first
  pick): each pack's name, id, version, hash prefix; the set hash; every issue with its
  code and place. After the start: locked, with the engine's result (patched files,
  result hash). `window.mvp.packs` for the checks.
- **Worker**: after the disc check, `feedPacks` + `mvp_packs_mount`: the packs are applied
  to this disc and mounted on the virtual disc before the translation and the handshake.
  Errors stop the start: "The roster packs cannot be used with this disc, so the game did
  not start: <first problems>".
- **Handshake** (`wasm/net_web.cpp`): the disc identity is computed when the disc is
  checked (the overlay rewrites the FST), the pack-set field is the mounted set's hash.
- **Chrome** (local, `browser_check.mjs --packs docs/examples/packs/fictional-league`): the
  panel showed set `b9a04e65...` and no issues before the disc; the Worker applied the pack
  in 278 ms with result hash `181b6977...` (= native = pack.py); with UP x4 at Select Team,
  frame 2,280 shows **Harbor City Lanterns**, rank 28th. The guest line equals mvp-play's
  for the same script and pack (16,991,561,020 instructions, MEM1 `9531f1af...`): the
  overlay gives the same game in the browser as natively.

## 5. Netplay (done)

Two Chrome pages through the netplay server (`netplay_check.mjs`, D = 3, `--fast`):
- **Same set** (the example pack on both): 2,280 frames (P1 picks the Lanterns), identical
  guest lines (MEM1 `2f4ca83c...`) and all 38 state-hash windows, no desync; both screens
  on Select Team with "Harbor City Lanterns".
- **Different sets**: player 2 with no packs, and player 2 with the same pack at version
  1.0.1. Both pages are refused at the handshake and neither boots: "the players chose
  different roster packs (player 1: pack set b9a04e6578e789b4, player 2:
  f5e1298911db13ad); both must pick the same packs in the same order" (player 2 shows the
  same text, received in player 1's BYE; the text names players, not "here").
- **Into the match (not reached, not a pack problem).** With the pack on both pages, P1
  picks the Lanterns and presses A three times (frames 2,300 / 3,100 / 3,300) to start the
  game. Both pages stayed in lockstep to frame ~3,310 (55 windows, no desync), then one
  page stopped with E5's guard "netplay: frame 3310 was polled before its input arrived
  (gate missed)" as the match's loading began. **The same run without packs stops the
  same way** (frame 3,308, the other page), so this is a netplay limitation E5 never met
  (its runs ended at frame 1,200, in the menus). Likely cause, not yet confirmed: during
  the loading the frame poll runs where no yieldable safe point follows it before the
  next poll (`YieldingHooks` never yields with `g_exception_depth > 0`, e.g. a poll from
  an interrupt-level callback while the main thread idles). Owner of the fix: netplay /
  runtime (E5 follow-up or E3c), not E6. Until then an online game can play the menus
  with packs but not start the match in the browser.

## Notes for the lead (docs outside docs/engine/)

- ROADMAP/DECISIONS: E6's exit is met (sections 3-5). Decision candidates: **E6-M1** the
  engine's pack code is a port of pack.py and must stay byte-compatible
  (`mods_crosscheck` in ctest); **E6-V1** the virtual disc places replaced files past the
  end of the image on 32 KiB boundaries and pads the end; **E6-N1** the handshake's disc
  identity is the unpatched disc's, packs are compared by the set hash.
- pack.py bugs to fix in `tools/rosters/pack.py` (section 1): the `$` and `\d` regex
  quirks, `manager.edit` with an empty `set`.
- PROGRESS.md was not touched (this session's scope is `engine/` and `docs/engine/`).

## Next step

0. **Netplay into the match** (E5 follow-up, see section 5): reproduce the gate miss at
   the loading after the difficulty screen, find the polls without a yieldable safe
   point between them, and make the gate hold there (or yield outside the handler
   first). Then rerun `netplay_check.mjs --packs docs/examples/packs/fictional-league
   --script <nav into the match> --frames 4420`: both screens should show the Lanterns'
   defensive line-up, as natively (section 3).
1. **Persist the picked packs** in the browser (IndexedDB) so a player picks them once;
   optionally packs the server lists (the deployment serves authored packs only).
2. **Show the pack set in the lobby** (the room carries the creator's set hash and pack
   names, so a joiner sees a mismatch before the handshake).
3. **Art and audio packs**: an example pack with authored `.gsh` logos and uniforms (the
   format supports them; v1 cannot check `.gsh` layouts, MODDING.md §14 question 9).
4. **Saves**: store the set hash in a memory-card save and warn on load (MODDING.md §14
   question 6).
5. The `--pack` option for `mvp-netplay` (native netplay) if native peers need packs.
