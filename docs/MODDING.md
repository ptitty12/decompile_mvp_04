# Roster and team packs: format v1

This file is the contract for roster and team packs: what a pack contains, what each
operation does, how packs are checked, combined and hashed, and how the format may change.
The engine (`engine/mods/`, milestones E6 and E7 in [`ROADMAP.md`](ROADMAP.md)) implements
it. The reference implementation is [`tools/rosters/pack.py`](../tools/rosters/pack.py), with
tests in `tools/rosters/tests/test_pack.py` and an example pack in
[`examples/packs/fictional-league/`](examples/packs/fictional-league/). The data formats it
patches are described in [`ROSTERS.md`](ROSTERS.md).

**Version: format 1.0** (engine mod API 1.0), 2026-10-14. Where this file and `pack.py`
disagree, that is a bug in one of them; fix it before you build on either.

## 1. Purpose and contracts

A pack changes rosters, players, team names, managers and team art. It is applied when the
game loads its data: the engine reads the tables from the player's own disc, applies the
packs in order, and serves the result to the game through the virtual disc
(`ARCHITECTURE.md` §8).

A pack depends on two of the three contracts in `ARCHITECTURE.md` §2, and nothing else:

- **The game's data formats:** table and column names of `database.big`, string ids of the
  LOC files, file paths on the disc, the `unique_team` codes and the `"Last,First"` keys.
- **This format**, versioned by `engine_api` (section 11).

A pack never names a decomp symbol, an address or a struct from `include/`. Renames and
matches in the decomp cannot break it.

**Packs never contain retail data.** A pack holds authored content (new players, new names,
new ratings, new art) and edits keyed by stable keys. It must not contain copies of retail
tables, rows, files, textures, audio or byte dumps. The tools refuse the cases they can
detect: an asset that equals the file it replaces, and a BIG archive or LOC file used as an
asset. A pack that edits a retail player names him by his key and lists only the values it
changes.

**Two levels of checking.** *Static validation* needs no game data, so any machine can run it,
the owner's VPS included. *Full validation* applies the packs to the tables of a disc and
checks the result. It runs where the disc is: in the player's browser, or with
`pack.py validate --disc`.

## 2. Pack layout

```
fictional-league/            a directory, or a .zip of it
  pack.json                  the manifest (section 3)
  patches/players.json       patch files, applied in the order the manifest lists them
  patches/harbor-city.json
  assets/logo.gsh            authored asset files (section 5.6)
  README.md                  anything else: ignored, and not part of the hash
```

- `pack.json` is at the top level. A zip may instead hold exactly one folder with
  `pack.json` in it.
- Paths in the manifest are relative, use `/`, contain only `A-Z a-z 0-9 . _ -` per segment
  (no `.` or `..` segments) and are **case-sensitive**: a pack that works on Windows must work
  on Linux.
- JSON files are UTF-8; a leading byte-order mark is ignored. The JSON is strict:
  - duplicate object keys are an error;
  - numbers must be integers within the signed 32-bit range (no fractions, exponents, `NaN`);
  - object keys are printable ASCII.
- Limits: 16 MiB per patch or asset file, 64 MiB per pack.
- Files that the manifest does not list are ignored.

## 3. The manifest: `pack.json`

```json
{
  "id": "fictional-league",
  "name": "Fictional League: Harbor City Lanterns",
  "version": "1.0.0",
  "game": "GV4E69-0",
  "engine_api": "1.0",
  "description": "Replaces the Anaheim slot with the Harbor City Lanterns.",
  "authors": ["mvp2005-decomp contributors"],
  "license": "CC0-1.0",
  "depends": [{"id": "base-league", "version": "^1.2.0"}],
  "patches": ["patches/players.json", "patches/harbor-city.json"],
  "assets": [{"path": "/data/frontend/logos.big", "entry": "l000.gsh", "file": "assets/logo.gsh"}]
}
```

| Field | Required | Rule |
|---|---|---|
| `id` | yes | 3-64 characters of `a-z 0-9` and single hyphens. Unique in a pack set |
| `name` | yes | 1-100 characters, for display |
| `version` | yes | The pack's own version, `MAJOR.MINOR.PATCH` |
| `game` | yes | `"GV4E69-0"` (MVP Baseball 2005, GameCube, USA, revision 0) |
| `engine_api` | yes | `"MAJOR.MINOR"` of the format the pack targets (section 11) |
| `patches` | yes | Patch files in application order (may be empty) |
| `description` | no | Up to 2000 characters |
| `authors` | no | List of strings |
| `license` | no | An SPDX id; authored packs should say what others may do with them |
| `depends` | no | Packs that must come earlier in the set: `{"id", "version"}`, where `version` is `"^X.Y.Z"` (same major, at least this version; for `0.y.z` the same minor) or `"X.Y.Z"` (exactly this) |
| `assets` | no | Asset mappings (section 5.6) |
| `meta` | no | A free-form object for tools. It is part of the hash |

Unknown fields are errors, so a typo is never silently ignored.

## 4. Keys and values

### 4.1 Players

A player is named by his key text `"Last,First"`, exactly as the game spells it: one comma,
case-sensitive. The game's key is `djb2("Last,First")` (`h = h*33 + c` from 5381, 32 bit),
written as 9 lowercase hex digits in every player table and in `roster`.

- **The name is the identity.** Row ids are never used: the game assigns them in load order,
  so they shift whenever a player is added or removed. A pack edits a player by name.
- **Renaming changes the identity.** `player.rename` re-keys the player in all 13 player
  tables and every roster row. Later ops, and later packs, use the new name.
- Two players can't share a key. That includes two *different* names with the same djb2 hash
  (`"Smith,Ab"` and `"Smith,BA"` collide). Both are errors.
- Name parts use letters, space, `'`, `-` and `.`, and start with a letter. The last name
  has at most 14 characters, the first name at most 13 (the longest shipped names). Commas are
  impossible: the table format has no quoting.
- `"Default,Default"` (row 0 of `attrib` and `pitcher`) is protected: no edit, rename,
  removal or roster place. New players take their unset values from it.

### 4.2 Teams

A team is named by its `unique_team` code (`"Ana"`, `"NYY"`, `"ChC"`, `"AL"`), case-sensitive.
The 126 team slots are fixed (`ROSTERS.md` §4.4, §6). A team pack **keeps the slot's code**
and changes the display fields, the roster, the manager, the text and the art. Packs cannot
change `unique_team`, `team_league`, `team_division` or `team_artid`.

### 4.3 Managers

A manager is named either by his key text `"Last,First"` or by `"team": "<code>"`, meaning
the MLB manager of that club's organization (`org_mlb_manager`). The second form lets a team
pack replace a manager without naming the retail one.

### 4.4 Columns and values

Edits name the on-disc table and column: `"set": {"attrib": {"playerattrib_speed": 80}}`.
Grouping by table is required because column names repeat across tables
(`lrattrib_contact` is in both `lhattrib` and `rhattrib`).

- Integer columns take a JSON integer within the column's range (Appendix A). Columns marked
  "or `-`" also take the string `"-"` (none), for example an absent fourth pitch.
- Team display columns take strings (Appendix A).
- `first_name`, `last_name`, `unique_team`, the league columns and the org link columns
  can't be set; renames and the roster ops cover them.
- Ranges are the shipped values, widened only for rating scales (0-15, 0-99, 0-100) and for
  counting stats up to the narrowest bit field that holds the shipped data. The in-memory
  record layouts are not recovered yet (`ROSTERS.md` §5), so nothing wider is known to be
  safe. Ranges may widen in a minor version (section 11).

## 5. Patch files and operations

A patch file is `{"ops": [ ... ]}`. Each op is an object with an `"op"` field. Ops run in
order: the files in manifest order, the ops in file order. Inside one pack a later op may
change what an earlier op did. Between packs, section 8 applies.

| Op | Fields (optional in brackets) | Effect |
|---|---|---|
| `player.add` | `player`, [`pitcher`], [`set`] | New player |
| `player.edit` | `player`, [`pitcher`], [`set`] | Change fields; `pitcher` adds or drops the pitcher rows |
| `player.remove` | `player` | Delete the player and free his slot |
| `player.rename` | `player`, `to` | Change the name, and with it the key |
| `roster.set` | `team`, `entries`, [`release`] | Replace a team's whole roster and depth chart |
| `roster.replace` | `team`, `out`, `in`, [`release`] | `in` takes `out`'s place on that team |
| `roster.swap` | `a`, `b` | Two players exchange places (a trade, or a depth-chart swap) |
| `team.edit` | `team`, `set` | Fields of `team`, `tstat` and `org` |
| `manager.edit` | `manager` or `team`, `set` | Fields of `manager` |
| `manager.rename` | `manager` or `team`, `to` | Change a manager's name and key; `org` links follow |
| `loc.set` | `file`, `strings` | Replace strings in a LOC text file |

Unknown ops and unknown fields are errors.

### 5.1 Players

```json
{"op": "player.add", "player": "Halvorsen,Bram", "pitcher": true,
 "set": {"attrib": {"playerattrib_primary_position": 0, "playerattrib_throws": 0},
         "pitcher": {"pitchattrib_stamina": 92, "pitchattrib_fastball_velocity": 96}}}
{"op": "player.edit", "player": "Halvorsen,Bram", "set": {"rhattrib": {"lrattrib_power": 12}}}
{"op": "player.edit", "player": "Ostrander,Milo", "pitcher": true}
{"op": "player.rename", "player": "Mabry,Quill", "to": "Mabry,Quillon"}
{"op": "player.remove", "player": "Mabry,Quillon"}
```

- `player.add` creates rows in the 8 batter tables (`attrib`, `lhattrib`, `rhattrib`,
  `bstats`, `fbstats`, `lhbstats`, `rhbstats`, `career`) and, with `"pitcher": true`, in the 5
  pitcher tables (`pitcher`, `pstats`, `lhpstats`, `rhpstats`, `careerp`). **Every column the
  pack does not set takes the value of the same column in the `Default,Default` row** of the
  player's disc. Set at least the positions, handedness and ratings.
- `set` may name only tables the player has. `"pitcher": false` on `player.edit` deletes the
  pitcher rows.
- `player.remove` requires that the player is on no roster any more. Replace him first
  (`roster.replace` with `"release": "remove"` does both).
- There is no team column in the player tables. A player's team is his roster place
  (section 6), so "move a player between teams" is a roster op.

### 5.2 Rosters

A roster entry gives a player and his place in the four lineups the game keeps for every
team:

| Lineup | Used when | Columns in `roster` |
|---|---|---|
| `rh_al` | against a right-handed starter, with a designated hitter | `rh_roster_al_position`, `rh_roster_al_battingorder` |
| `rh_nl` | against a right-handed starter, no designated hitter | `rh_roster_nl_*` |
| `lh_al` | against a left-handed starter, with a designated hitter | `lh_roster_al_*` |
| `lh_nl` | against a left-handed starter, no designated hitter | `lh_roster_nl_*` |

A place is `CODE` or `CODE:N` where `N` (1-9) is the batting order. Codes: `C 1B 2B 3B SS LF
CF RF DH` (fielders and designated hitter), `SP1`-`SP5` (rotation), `LR MR SU CP` (long
relief, middle relief, setup, closer) and `B` (bench). `"pos"` gives all four lineups at once;
a lineup key overrides it.

```json
{"op": "roster.set", "team": "Ana", "release": "remove", "entries": [
  {"player": "Arkwright,Desmond", "pos": "C:8", "lh_al": "B", "lh_nl": "B"},
  {"player": "Penhallow,Rufus", "pos": "B", "lh_al": "C:8", "lh_nl": "C:8"},
  {"player": "Brackenbury,Hollis", "pos": "B", "rh_al": "DH:9", "lh_al": "DH:9"},
  {"player": "Halvorsen,Bram", "pos": "SP1", "rh_nl": "SP1:9", "lh_nl": "SP1:9"},
  {"player": "Northcote,Evander", "pos": "CP"}
]}
{"op": "roster.replace", "team": "Ana", "out": "Lowther,Royce", "in": "Quist,Aldo", "release": "remove"}
{"op": "roster.swap", "a": "Arkwright,Desmond", "b": "Penhallow,Rufus"}
```

(The `roster.set` above is shortened; a real one lists 25 or 22 entries, see section 6.)

- `roster.set` replaces the team's whole list. Entry order is kept: it is the order of the
  game's 25-player list for that team.
- `roster.replace`: `in` takes over `out`'s entry on `team`, with all four lineup places.
- `roster.swap`: `a` and `b` exchange their entries on their own teams (the All-Star sides
  don't count). On different teams this is a trade. On the same team it swaps depth-chart
  places, for example promoting a backup catcher.
- `release` says what happens to players who end up on **no roster at all** after the op:
  `"keep"` (default; another op must place them, or validation fails) or `"remove"` (they are
  deleted, freeing their slots). Players still on another roster, such as an All-Star side,
  are never removed.

### 5.3 Teams

```json
{"op": "team.edit", "team": "Ana", "set": {
  "team": {"team_location": "Harbor City", "team_long_name": "Lanterns",
           "team_short_name": "HCL", "team_steals": 2},
  "tstat": {"team_wins_1sthalf": 0},
  "org": {"org_budget": 60000, "org_mlb_manager": "Quarrington,Basil"}}}
```

`team_location` is the city, `team_long_name` the nickname and `team_short_name` the display
abbreviation. The same names also live in the LOC files: change those with `loc.set`
(section 5.5). `org` exists only for the 30 clubs, the two All-Star sides and the two MVP
teams. Manager columns of `org` take a manager name.

### 5.4 Managers

```json
{"op": "manager.rename", "team": "Ana", "to": "Quarrington,Basil"}
{"op": "manager.edit", "manager": "Quarrington,Basil", "set": {"manager": {"manager_hitting": 84}}}
```

The manager table holds 36 managers (34 used), and v1 has no `manager.add`: a team pack
renames and edits the slot's manager. `Default,Default` is protected.

### 5.5 Text: `loc.set`

```json
{"op": "loc.set", "file": "FEENG.LOC", "strings": {"2010": "Lanterns", "2050": "Harbor City Lanterns"}}
```

- `file` is `FEENG.LOC` (front end), `IGENG.LOC` (in game) or `MC_ENG.loc` (memory card),
  case-insensitive.
- `strings` maps a string id (decimal, as a JSON key) to new text. The id must exist in that
  file; v1 replaces strings and never adds ids.
- Text is at most 400 characters of printable ASCII, plus the five non-ASCII characters the
  retail files use (U+00A0, U+00A9, U+00AE, U+2026, U+2122). Text longer than the string it
  replaces gives warning `W-LOC-LENGTH`, because the screen box may be too small.
- Which ids hold which team's names is in section 13.

### 5.6 Assets

The manifest's `assets` list maps authored files to game paths:

```json
{"path": "/data/frontend/logos.big", "entry": "l000.gsh", "file": "assets/logo.gsh"}
{"path": "/data/frontend/intro.vp6", "file": "assets/intro.vp6"}
```

- `path` is the absolute disc path, matched case-insensitively. v1 accepts paths under
  `/data/frontend/` only; later minor versions may add roots.
- A `.big` archive is changed entry by entry: `entry` names an existing entry, and the
  archive is rebuilt with that entry's payload replaced. Any other file is replaced whole.
- The file's bytes become the payload as they are: the pack supplies the game's own format
  (`.gsh` textures, for example). Converting from PNG is a tooling job, not part of the
  format. The game accepts raw payloads as well as RefPack ones (`ROSTERS.md` §2.2).
- An asset may not be a BIG archive or a LOC file, may not equal the retail bytes it replaces,
  and only one asset per target is allowed in a pack.
- Which entries belong to which team slot is section 13.

## 6. Rosters: the rules the game imposes

The `roster` loader (`fn_8053BEC8`, position parser `fn_8053C550`, team lookup `fn_8053C40C`,
record setup `fn_8053BB80`, all in `src/db/tu_8053967C.cpp`; the loader and the lookup are
near-misses whose differences are instruction order only) ignores the row key and reads, per
row: team key, player key, then four position and batting-order pairs. It keeps at most **25 players
per team**, at most 3 `LR`, 4 `MR`, 2 `SU` and 1 `CP` per lineup, and drops the excess
silently. It reads **pitching roles from `rh_al` only**. A roster row for an unknown team
creates a team record with no capacity check. Packs therefore follow these rules, checked in
full validation:

1. **Size.** Exactly 25 entries for teams of leagues 0-3 and 10 (MLB, All-Star, Triple-A,
   specials) and exactly 22 for leagues 4-9 (Double-A, Class A), as shipped. The loader would
   accept 1-25; whether the game copes with other sizes is open (section 14), so v1 requires
   the shipped sizes.
2. **Each lineup** has exactly one each of `C 1B 2B 3B SS LF CF RF`, `SP1`-`SP5` and `CP`;
   exactly one `DH` in `rh_al` and `lh_al` and none in `rh_nl` and `lh_nl`; at most 3 `LR`,
   4 `MR` and 2 `SU`.
3. **Batting order.** In each lineup the nine batters have orders 1-9, each once. The batters
   are the eight fielders plus `DH` (`_al` lineups) or plus `SP1` (`_nl` lineups). No one
   else has an order.
4. **Pitching roles** (`SP1`-`SP5 LR MR SU CP`) are the same in all four lineups and belong to
   players with pitcher rows. A pitcher without a role gives warning `W-PITCHER-BENCH`.
5. **One home team.** Every player except `Default,Default` is on exactly one roster other than
   `AL` and `NL` (the All-Star sides), and may also be on an All-Star roster. A player on no
   roster at all is an error. A player who is only on an All-Star roster gives warning
   `W-ALLSTAR-ONLY`.
6. No player appears twice on one roster.

All shipped rosters satisfy these rules. On output the `roster` table is rebuilt: teams in
`team` order, entries in list order, keys `000000000`, `000000001`, ... (section 9).

## 7. Validation

### 7.1 Static checks (no disc)

- The manifest: fields, types, id, versions, `game`, `engine_api` compatibility, paths and
  file existence.
- Strict JSON, and the shape of every op: known op, required and allowed fields.
- Names: syntax and lengths. Team codes: syntax.
- `set`: the table is allowed for the op, the column exists and is settable, and the value has
  the right type and range.
- Roster entries: syntax of every place.
- `loc.set`: file name, id syntax, characters and length.
- Assets: path root, `entry` rules, file kinds, duplicate targets.
- The set: unique ids, and every dependency earlier in the order with a matching version.

### 7.2 While applying (needs the disc)

Each op is checked against the current state: the player, team, manager or string id exists
(`E-NOT-FOUND`); a new key is free (`E-KEY-EXISTS`); `Default,Default` is untouched
(`E-PROTECTED`); the roster op makes sense (`E-ROSTER`); no conflict with another pack
(`E-CONFLICT`, section 8). Any error stops the output, but checking goes on so that one run
reports as many problems as possible.

### 7.3 The final state

- **Capacities**, which the game never checks: at most 3,250 players (the `Default` row
  included), 1,800 pitchers and 36 managers. Teams stay at 126 because slots are fixed. Warning
  `W-FREE-SLOTS` when the set leaves fewer free slots than the disc does (329 players and 370
  pitchers on GV4E69): dynasty drafts and created players need them, and how many is not known.
- Every value of every row of the player, `team`, `tstat` and `manager` tables is within its
  column's range, including values that came from defaults.
- Pitches 3-5: each pitch is all five fields or all `"-"`, and they fill in order (no pitch 4
  without pitch 3).
- A player with primary position SP (0) or RP (10) has pitcher rows.
- The roster rules of section 6, for all 126 teams.

### 7.4 Reports

Each problem is one line, `<severity> <code> <where>: <message>`, where `<where>` is
`<pack id>:<file>:ops[<index>] (<op>)` or `result` for final-state rules. `--json` gives the
same as objects `{severity, code, where, message}`. Errors stop `apply`; warnings never change
the output. Codes are stable within a major version:

| Code | Meaning |
|---|---|
| `E-PACK`, `E-PATH`, `E-JSON`, `E-MANIFEST` | The pack can't be read, a path or file is wrong, invalid JSON, bad manifest |
| `E-GAME`, `E-ENGINE-API` | Wrong game id; the pack needs a newer format version |
| `E-OP`, `E-FIELD`, `E-VALUE`, `E-NAME`, `E-LOC`, `E-ASSET` | Bad op, column, value, name, text or asset mapping |
| `E-DUPLICATE`, `E-DEPENDENCY` | Same pack twice; dependency missing, later in the order, or the wrong version |
| `E-NOT-FOUND`, `E-KEY-EXISTS`, `E-PROTECTED` | Unknown key or id; key taken (including djb2 collisions); `Default,Default` |
| `E-ROSTER`, `E-ROSTER-HOME`, `E-PITCHER` | Roster rules (section 6); home-team rule; SP or RP without pitcher rows |
| `E-CAPACITY` | Over a table capacity |
| `E-CONFLICT` | Two packs change the same thing without a dependency (section 8) |
| `E-RETAIL-COPY` | An asset equals the retail bytes it replaces |
| `W-LOC-LENGTH`, `W-FREE-SLOTS`, `W-ALLSTAR-ONLY`, `W-PITCHER-BENCH` | Warnings (above) |

## 8. Composition and conflicts

A **pack set** is an ordered list. The player picks it, and in netplay both players must
have the same set (section 10). Packs apply in list order. A pack's dependencies must appear
earlier in the list.

Applying records which pack last wrote each **cell**:

| Cell | Written by |
|---|---|
| a player's existence | `player.add`, `player.remove`, `player.rename`, removal through `release` |
| one column of one player's row in one table | `player.add` (every column), `player.edit` |
| a player's pitcher status | `player.edit` with `pitcher` |
| a team's roster | `roster.set`, `roster.replace`, `roster.swap` |
| one column of a team's `team`, `tstat` or `org` row | `team.edit` |
| a manager's existence, one manager column | `manager.rename`, `manager.edit` |
| one LOC string (file, id) | `loc.set` |
| one asset target (path, entry) | `assets` |

The rules:

1. **Inside one pack**, ops run in order, and a later op may overwrite an earlier one.
2. **Between packs**, a pack may overwrite a cell another pack wrote, or *use* a player or
   manager another pack created or renamed, only if it depends on that pack, directly or
   through other dependencies. Otherwise the set fails with `E-CONFLICT`, naming both packs.
3. Removing or renaming a player or manager touches every cell of it, so it conflicts with
   any edit to that entity by a pack it does not depend on.
4. Cells that no pack writes keep the disc's values. Packs that write different cells compose
   in any order with the same result.

So unrelated packs (say, one that edits a few ratings and one that renames a team) combine
freely. Order matters only between packs that declare a dependency, and then the later one
wins. Silent "last pack wins" between unrelated packs never happens.

## 9. Determinism and output

Applying the same ordered pack set to the same disc gives byte-identical tables on every
machine. The serialization is the game's own text format (`ROSTERS.md` §4.1), with these
ordering rules:

- **Player tables:** retail rows keep their disc order. A removed player's rows are dropped.
  A renamed player keeps his place. Added players follow, in the order they were added. The
  pitcher tables list their players in `attrib` order, as on the disc.
- **`roster`:** rebuilt as in section 6. Applied to an unchanged roster, this gives the disc's
  bytes.
- **`team`, `tstat`, `org`:** the disc's row order. **`manager`:** the disc's order; a renamed
  manager keeps his place.
- **LOC files:** the disc's string order. Changed strings are replaced in place, and the file
  is re-serialized (`loc.py`, byte-exact for unchanged files).
- Values are written as decimal integers, `-`, or the text.

**Storage.** A table whose text is unchanged keeps its original compressed bytes in
`database.big`. A changed table is RefPack-compressed again and the archive rebuilt with the
game's layout (`big.py`). Which compressor is used is part of the engine build, not of this
format: both netplay peers run the same build (the handshake checks it). The normative output
is the table and LOC text, and the *result hash* (section 10) covers exactly that, so
`pack.py` and the engine can be compared even if their compressors differ. `pack.py` uses
`refpack.compress`, which produces valid streams about 5% larger than EA's.

**Output layout.** `pack.py apply` writes only the changed files, at their disc paths, under
`--out`: `data/database/database.big`, `data/FEENG.LOC`, `data/frontend/logos.big`, and so
on. It also writes `pack-apply.json` with the hashes and the issues. The engine's virtual disc
mounts the same files over the image. `--out` must not be inside a git work tree unless git
ignores it: these files are derived from the disc and are never committed or hosted.

## 10. Hashing

All hashes are SHA-256, written as 64 lowercase hex digits. **Canonical JSON** is RFC 8785
restricted to this format's JSON (integers only, ASCII keys): keys sorted, no whitespace,
strings escaped only where JSON requires it (`"`, `\`, control characters as `\b \f \n \r \t`
or `\u00xx`), UTF-8.

- **File digest.** For a patch file: SHA-256 of the canonical JSON of its parsed content. For
  an asset file: SHA-256 of its bytes.
- **Pack hash** = SHA-256(`"mvp2005-pack-hash/1\n"` + canonical JSON of
  `{"manifest": <parsed pack.json>, "files": {<path>: <file digest>, ...}}`), over every
  file the manifest lists. Line endings, indentation, key order and BOMs don't change it, so
  a git checkout on Windows hashes the same as on Linux. Any change of content does. Files the
  manifest doesn't list don't count.
- **Set hash** = SHA-256(`"mvp2005-packset-hash/1\n"` + canonical JSON of
  `{"packs": [{"id", "version", "hash"}, ...]}`) in set order. The empty set has a hash too.
- **Result hash** = SHA-256(`"mvp2005-result-hash/1\n"` + canonical JSON of
  `{<disc path>[:<entry>]: SHA-256 of its text or payload}`, paths and entry names in lower
  case) over every table of
  `database.big` (decompressed text), the three LOC files and every replaced asset. It
  identifies the patched data independently of compression.

**Netplay.** The handshake (`ARCHITECTURE.md` §8) compares the set hash, along with the engine
build and disc identity. Peers may also compare result hashes after applying. That catches an
engine bug before the match, and a hash is not game data.

## 11. Versioning policy

- **The format version is the engine mod API version**, `MAJOR.MINOR`, now `1.0`. A pack
  declares the version it targets in `engine_api`. An engine with API `X.Y` accepts packs
  with the same `X` and a minor version up to `Y`.
- **A minor version** only adds or relaxes: new ops, new optional fields, more settable
  columns, wider ranges, more asset roots, slot tables (section 13), an error relaxed to a
  warning. Every pack valid under `1.x` stays valid under `1.y` (y > x) and **produces the same
  output and the same hashes**.
- **A major version** is anything else: changed semantics, serialization, ordering, hashing
  or limits that would reject packs. It gets a migration note in `docs/DECISIONS.md` and a
  converter in `pack.py`. The engine keeps loading the previous major for as long as
  practical. The hash prefixes carry the major version (`.../1`).
- v1 is strict on purpose. Every rule that rests on missing evidence (exact roster sizes,
  value ranges, name lengths) can be relaxed in a minor version once a boot test or the
  decomp proves it safe. Tightening would break packs.
- A pack's own `version` is its author's semver: bump MAJOR when packs that depend on it
  must change.
- `pack.py`'s tests are the start of the compatibility suite. The engine must pass the same
  cases.

## 12. Worked example: `fictional-league`

[`examples/packs/fictional-league/`](examples/packs/fictional-league/) replaces the Anaheim slot
(`unique_team` `Ana`, team row 0, AL West) with the **Harbor City Lanterns**. Every name and
number in it is invented.

| File | What it does |
|---|---|
| `pack.json` | id `fictional-league`, version 1.0.0, `engine_api` 1.0, no dependencies, three patch files |
| `patches/players.json` | 25 `player.add`: 13 position players and 12 pitchers (`"pitcher": true`). Each sets positions, handedness and the main ratings; everything else comes from `Default,Default`. The relievers set pitches 3 and 4 to `"-"` |
| `patches/harbor-city.json` | `team.edit` (location, nickname, abbreviation `HCL`, a strategy setting); `loc.set` of ids 2010 (nickname) and 2050 (full name) in `FEENG.LOC` and `IGENG.LOC`; `roster.set` with the full depth chart and `"release": "remove"`; `manager.rename` and `manager.edit` through `"team": "Ana"` |
| `patches/tweaks.json` | `player.edit` of one player's speed; `roster.swap` of the two catchers, so the left-handed hitter starts against right-handers |

The depth chart shows the platoon form: the starting catcher is `"pos": "C:8"` with
`"lh_al": "B", "lh_nl": "B"`, and the backup is the reverse. The designated hitter is `"B"` in
the `_nl` lineups, and `SP1` bats ninth there.

Static validation: no errors. Pack hash
`cabf0cf1272567483667678424437106377851e6343931731fb767aa58515612`, set hash (this pack alone)
`208cb5501ba163ad72bfc95919c4c598531621d15e6eb0ef26c6f4aa94dbed1c`.

Applied to GV4E69 rev 0 (checked locally on 2026-10-14; nothing derived from the disc is in the
repo):

- No errors; 8 warnings:
  - 4 `W-LOC-LENGTH` (the new names are longer than the old ones);
  - 2 `W-FREE-SLOTS` (327 player and 368 pitcher slots left);
  - 2 `W-ALLSTAR-ONLY`: two released Anaheim players are also on the AL All-Star roster, so
    they are kept.
- 23 released players were removed, and 25 were added (12 of them pitchers).
- Re-read with `dbtables.py`:
  - every retail row that the pack did not touch is identical, in the same order;
  - the rosters of the other 125 teams are identical;
  - `tstat` keeps its original compressed bytes;
  - the LOC files differ only at ids 2010 and 2050;
  - the `org` row of Anaheim points to the renamed manager.
- A second run gave byte-identical files.
- `database.big` grew from 1,010,678 to 1,056,803 bytes, because 17 tables were recompressed.

## 13. TODO: team-slot tables

The mechanisms above (explicit `loc.set` ids and explicit asset paths) are complete and stable.
What is missing is the **table of which ids and paths belong to each of the 126 slots**. It
comes from the team-slot asset mapping work (`ROSTERS.md` §7, §10 question 1). When it lands, a
minor version adds it here and may add a slot-level shorthand (for example
`{"slot": "Ana", "kind": "logo", "file": ...}`) that expands to the explicit form. Packs that
use the explicit form stay valid.

| Item | Known so far | Still needed |
|---|---|---|
| Nickname, full name | `FEENG.LOC`/`IGENG.LOC` ids `2000+n` and `2040+n` for the 30 clubs and the All-Star sides (`n` in division order, not team-row order: AL East, Central, West, NL East, Central, West; Anaheim is `n = 10`) | `n` for every slot; ids for the 90 minor-league and 4 special teams; the other copies (around 16000, 17200, 17618-17645, 22177-22208, 22941-22964) |
| Logo | `frontend/logos.big` `l000`-`l125`, `logos_a.big` `a000`-`a125`; index probably `team_artid - 1` | confirm the index; the `l994`-`l999` entries |
| Uniforms | `frontend/uniforms.big` `000`-`123` plus lettered variants; `coopunis.big` `c001`-`c122` | which entry is home, away and alternate for each slot; the in-game uniform textures |
| Load screen | `frontend/load0.big`-`load48.big` | the slot-to-screen map |
| Stadium picture and name | `frontend/stadiums.big`, stadium LOC strings | the team-to-stadium table |
| Announcer clips | `audio/spch_pbp/tnamedat.big` (124 entries), `spch_pa/tnamedat.big` | format; the asset root `/data/audio/` (not allowed in v1) |

## 14. Open questions

These need the engine, a real boot or more decomp. None of them blocks the format: each one
can only relax a v1 rule or fill section 13.

1. **Larger `database.big`.** The game loads the file whole into a buffer sized from the file
   (`ROSTERS.md` §2.2), but nobody has booted a recompressed or larger one. The example grows it
   by 46 KB. Test in E2/E6. The fallback (raw payloads) is larger still.
2. **Roster sizes.** The loader accepts 1-25 players per team. Whether menus, the AI and
   dynasty mode cope with fewer than 25 or 22, or with 25 in a minor-league team, is untested.
3. **Players without a team.** Every shipped player has a roster place. Whether a player on no
   roster loads as a free agent (v1 forbids it) needs a boot.
4. **Name and text lengths.** v1 caps names at the shipped maxima (14 and 13) and team text at
   13 and 12, because the in-memory string sizes aren't recovered.
5. **Value ranges.** In-memory bit widths (`ROSTERS.md` §5, §10 question 5) would let ranges
   widen.
6. **Saves.** Memory-card saves hold their own copy of the records (`ROSTERS.md` §1, item 5).
   Loading a dynasty saved under a different pack set is undefined. The engine should store
   the set hash in the save and warn when it differs.
7. **`hist.dat`.** Career history lines are keyed by the player key. A renamed or removed player
   loses his lines, and an added one has none. v1 does not patch `hist.dat`.
8. **Announcer audio.** Renamed teams and new players have no spoken names until audio packs
   exist (`audioid`, `tnamedat.big`).
9. **Archives with non-standard alignment** (`tnamedat.big`, `stdnmdat.big`, `frontend/misc.big`):
   rebuilding them changes their layout. Check before adding their roots.
10. **The draft.** How many free player slots a dynasty needs (the `W-FREE-SLOTS` threshold).

## Appendix A: settable columns and ranges

Column names are written without the prefix in the second column. Ranges are inclusive;
"or `-`" means the column also takes `"-"`. Columns not listed can't be set.
`tools/rosters/pack.py` (`SCHEMA`) holds the same table in machine-readable form.

| Table | Prefix | Columns and ranges |
|---|---|---|
| `attrib` | `playerattrib_` | jerseynum 0-99; bats 0-2; throws 0-1; primary_position 0-10; secondary_position 0-13; height 18-35; weight 50-190; boneprofile 25-37; face 1-915; face2004style 0-1; skin_tone 0-10; hairstyle 0-9; haircolour 0-6; facialhair 0-7; bodytype 1-2; audioid 0-2665; photo 1-2; platediscipline, bunting, stealing_aggressive, baserunning 0-15; speed 0-99; fielding, range, throwstrength, throwaccuracy, durability 0-15; battingstance 0-65; swingtype 0-6; batcolour 0-7; batglove 0-1; wristband 0-6; elbowguard 0-3; shinguard 0-4; socks 0-2; catchermask 0-1; fieldglovecolour 0-4; ditty 0-6; salary 0-255; contract_length 1-7; starpower 0-4; topprospect, hidden 0-1; birthday 0-32767 (days since 1 January 1948) |
| `lhattrib`, `rhattrib` | `lrattrib_` | contact, power 0-100; hit_ul, hit_um, hit_ur, hit_cl, hit_cm, hit_cr, hit_ll, hit_lm, hit_lr 0-2; lf_pct, cf_pct, rf_pct, hr_pct, fb_pct, ld_pct, gb_pct 0-100; chasefb, chaseslowbreak, chasehardbreak (`rhattrib` only), takefb, takeslowbreak, takehardbreak, missfb, missslowbreak, misshardbreak 0-15 |
| `pitcher` | `pitchattrib_` | stamina 0-99; pickoff 0-15; fastball_movement, fastball_description 0 only; fastball_control 0-99; fastball_velocity 47-101; for pitch2 (always present) and pitch3-pitch5 (each also all `-`): `_type` 1-14, `_movement` 0-15, `_description` 0-7, `_control` 0-99, `_velocity` 47-101; pitcher_delivery 0-58 |
| `bstats` | `batstat_` | g, r 0-255; sb 0-127; cs 0-31 |
| `fbstats` | `fieldstat_` | g 0-255; po 0-2047; a 0-1023; e 0-31 |
| `lhbstats`, `rhbstats` | `lrbatstat_` | 1b 0-255; 2b 0-63; 3b 0-15; hr 0-63; rbi 0-127; so 0-255; bb 0-127; ibb, sh 0-31; sf 0-15; hbp 0-31; tpa 0-1023 |
| `career` | `batcareerstats_` | g 0-4095; ab 0-16383; h 0-8191; hr 0-1023; rbi, r 0-4095; sb 0-1023 |
| `pstats` | `pitchstat_` | g 0-127; gs 0-63; r, er 0-255; w, l 0-31; sv 0-63; blsv, cg 0-15; sho 0-3; pk 0-31; ip 0-255; pip 0-2 |
| `lhpstats`, `rhpstats` | `lrpitchstat_` | so 0-255; bb 0-127; ibb, hbp, sf, sh 0-15; 1b 0-255; 2b 0-63; 3b 0-15; hr 0-63; tpa 0-1023 |
| `careerp` | `pitchcareer_` | g 0-2047; ip 0-8191; pip 0-2; er 0-4095; w, l, sv 0-511; so 0-8191; bb 0-4095 |
| `team` | `team_` | location: text, at most 13; long_name: text, at most 12 (text: `A-Z a-z 0-9`, space, `' . - /`, starting with a letter or digit); short_name: 1-3 of `A-Z 0-9`; climatezone, homeintensity 0-2; the 32 `vs_*` columns 0-2; the 14 strategy columns (pinchhitter ... suicidesqueeze) 0-2 |
| `tstat` | `team_` | wins_1sthalf, losses_1sthalf, wins_2ndhalf, losses_2ndhalf 0-127 or `-` |
| `org` | `org_` | budget 0-100000; mlb_manager, minors_manager: a manager name |
| `manager` | `manager_` | jerseynum 0-99; audioid 5000-5048; height 72 only; weight 200 only; boneprofile 27-37; face 1-915; face2004style 0-1; skintone 0-9; hairstyle 0-3; haircolour 0-4; facialhair 0 only; bodytype 1-2; hitting, baserunning, fielding, pitching 0-100; salary 0-15; reallife 0-1; birthday 0-8191 |

Enumerated codes (positions, handedness, equipment) are listed in `ROSTERS.md` §4.2 and
`GAME_DATA.md` §2. Primary positions: 0 SP, 1 C, 2 1B, 3 2B, 4 3B, 5 SS, 6 LF, 7 CF, 8 RF,
9 DH, 10 RP. Secondary positions add 11 OF, 12 IF, 13 UT.

## Appendix B: the reference tool

`tools/rosters/pack.py` (Python 3, standard library). The owner never needs to run it. Agents
and the engine's tests do:

```
pack.py validate [--disc IMAGE] [--json] PACK...
pack.py apply --disc IMAGE --out DIR [--json] PACK...
pack.py hash PACK...
pack.py new DIR --id ID [--name NAME]
```

`IMAGE` is an ISO or CISO image, or a directory holding an extracted disc. Exit status 0 means
no errors (warnings allowed), 1 means errors, 2 means a usage or I/O problem.
