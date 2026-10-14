# Rosters and teams: where the data lives and how to patch it

Knowledge target K2 (`docs/ROADMAP.md`). This file says where the roster and team data
sits on the GameCube disc, the format of every table, what the code does with it, every
hard-coded team count and table capacity found so far, and what a roster pack or team pack
must change. The tools that read and write these formats are in `tools/rosters/`
(`big.py`, `refpack.py`, `dbtables.py`, `loc.py`).

Written 2026-10-14 from the owner's own `GV4E69` disc image. **No game data is in this repo.**
This file holds formats, counts, names of fields and addresses only.

**Legend.** **[V]** verified: reproduced byte for byte by the tools on the disc image, or read
directly in the matched source or in the assembly (addresses given). **[I]** inferred: a
reading that fits the evidence but no test or disassembly proves it. Treat [I] as a lead.

## 1. What matters most

1. **The tables on disc are plain text, not bit-packed.** `database.big` holds 18 RefPack-compressed
   text tables in a CSV-like format. The bit-packed records that PC tools show are what the game
   builds in memory from this text. A pack therefore patches text fields by name. [V]
2. **Every player and team row is found by a 32-bit key: djb2 hash of a string.** Player key =
   `djb2("Last,First")`; team key = `djb2(unique_team)`; manager key = `djb2("Last,First")`.
   Two players with the same "Last,First" cannot both exist. [V]
3. **Hard capacities are baked into the code, with no check while loading.** Players 3250
   (2920 used + the `Default` row), pitchers 1800, teams 126 (all used), organizations 34
   (all used), managers 36 (34 used). A pack that adds players must stay under the cap; a pack cannot add a 127th
   team without code hooks. [V for the values, I for "no check" beyond the sorted-key array]
4. **The team's stable identity is `unique_team` (3 letters, e.g. `Ana`).** Schedules, stadium
   park factors and the team key all use it. Display names are separate fields
   and also live in the LOC text files. A slot replacement should keep `unique_team` and change
   the display data. [V]
5. **Saves bypass these tables.** The memory-card serializer writes the in-memory record arrays
   wholesale (`fn_80070DDC`). Packs affect new games; a loaded dynasty restores its own rows. [I]

## 2. Archive layout

### 2.1 BIGF [V]

All 215 BIGF archives on the disc parse with one layout (the two other `.big` files, in `audio/stadium`, are
not BIGF). `big.py` rebuilt the 197 that are under 20 MB: 193 are byte for byte identical; the other 4 (`audio/spch_pa/tnamedat.big`,
`audio/spch_pbp/tnamedat.big`, `audio/spch_pbp/stdnmdat.big` and `frontend/misc.big`) use a different payload alignment.

```
0x00  "BIGF"
0x04  u32 LITTLE-endian   total file size
0x08  u32 big-endian      entry count
0x0C  u32 big-endian      header size (entry table + 8-byte trailer; not aligned)
0x10  entries x count: u32 BE offset, u32 BE size, NUL-terminated name
....  trailer: "L234" + u32 BE flag
....  payloads, each starting on a multiple of 4, zero padded; the last ends at end of file
```

- The trailer flag seen: 0 in `progress.big` and `misc.big` (raw entries), 1 in most archives,
  2 in `anims.big` and the audio archives, 3 in `fonts.big`. The game does not use it to choose
  how to read a payload (see 2.2). [I for the meaning]
- The game's own reader agrees: `fn_803FC300` accepts `"BIG"` (kind 3) at byte 0; `fn_803FC610`
  reads the header size at +0x0C; `fn_803FC698` reads the trailer as one letter, three digits
  (`234`) and a u32 flag, at `file + header size - 8`. [V]
- Entry names are usually bare file names (`attrib.dat`); the nested `initstay.big` and `initpurge.big` use
  `models/...` paths. The tools look names up case-insensitively.
- Archives can nest: `initstay.big` is a RefPack payload that is itself a BIGF.

### 2.2 RefPack [V]

Header `flags magic size`: `0x10 0xFB` + 24-bit big-endian unpacked size (the 32-bit form is
`0x90 0xFB`). The game decodes only flags `0x10` and `0x90` (`p[0] & 0xFE`; `fn_80401710`,
size from `fn_804017D0`, decoder `fn_80401924`). A payload is compressed if byte 1 is `0xFB`;
anything else is passed through as raw bytes (`fn_802B9300`, the "not RefPack" branch copies the
bytes). Several archives mix raw and compressed payloads, so check each entry.

Commands (documented in `refpack.py`): 2-byte, 3-byte and 4-byte copy forms with 0-3 literals
riding along, `0xE0-0xFB` literal runs of 4-112 bytes, and `0xFC-0xFF` stop with 0-3 literals.
`refpack.py` decompresses every payload of `database.big`, `rookie.big`, `schedule.big` and
`ovlay*.big` correctly.

**The compressor is not EA's.** `refpack.compress` produces valid streams, but about 5% larger
(`database.big` grows from 1,010,678 to 1,058,652 bytes when every table is recompressed). Matching
EA's output byte for byte was not attempted. Two ways to avoid the question: keep untouched
tables' original bytes (`Database.to_bytes` does), and remember that raw payloads are accepted too.
Whether the game tolerates a larger `database.big` is expected (the file is loaded whole into a
buffer sized from the file, `fn_802B9300`) but untested [I]; E2/E6 should test it.

## 3. The files in `/data/database/`

| File | Format | Purpose | Loaded by |
|---|---|---|---|
| `database.big` | BIGF, 18 RefPack text tables | players, stats, teams, rosters, organizations, managers | `fn_802B8CCC` (path string `lbl_805E0EEC`) |
| `schedule.big` | BIGF, 9 RefPack CSV files | game schedules (`mlb162_1/2/3`, `mlbspr_1`, `aaa144_1/2`, `aa140_1/2`, `a140_1`) | `fn_802B8D74` |
| `progress.big` | BIGF, 8 raw CSV files, trailer flag 0 | progression, contracts, park factors (`stadium.csv`) | `fn_802B8E1C` |
| `rookie.big` | BIGF, 26 RefPack CSV files | draft-class generator: name pools, rating distributions | `fn_802B8EC4` |
| `hist.dat` | binary | season history lines per player | `fn_80083E18` (path `lbl_805B4254`) |
| `resign.csv` | CSV | chance of re-signing by age and star level | `fn_80553284` (`db/tu_8054FA04`, string `lbl_805FF50C`) |

Order of events at database setup [V, `fn_8007295C`]: `fn_802B8CCC` loads `database.big`; `v7` of
the five table groups (`Tbl80094800`, `Tbl800956D8`, `Tbl8009101C`, `Tbl80091760`, `Tbl80090B28`) loads
their record sets; `fn_802B8D34` frees the archive; the rest of the dynasty setup follows.
The other three `.big` files are loaded and freed by the functions that use them (schedule: `fn_805650DC`,
`fn_8056516C`, `fn_800766B8`; progress: `fn_80534530`, `fn_80556D20`, `fn_805744D4`; rookie: `fn_80072B60`).

`mvp.ini` and `mvporide.ini` on the disc are leftovers: the game says the ini is "disabled when we ship",
and none of its variable names (`skip_fe`, `home_team`, `random_seed_to_use`...) appear as strings in the DOL.
They are useful only as a list of what the developers could set. [V for the strings, I for the rest]

## 4. `database.big`: the 18 tables

All tables share the text format in 4.1. Counts are for GV4E69 rev 0 as dumped by
`dbtables.py list`; **every table re-serializes byte for byte** (see 11).

| Table | Records | Cols | Key | Purpose |
|---|---:|---:|---|---|
| `attrib` | 2921 | 46 | `djb2("Last,First")` | static player attributes (the master player list; row 0 is `Default,Default`) |
| `lhattrib` | 2921 | 28 | same | batting ratings against left-handed pitchers |
| `rhattrib` | 2921 | 29 | same | batting ratings against right-handed pitchers |
| `pitcher` | 1430 | 29 | same | pitching ratings (pitchers only; `Default` row included) |
| `bstats` | 2921 | 6 | same | batting season stats: g, r, sb, cs |
| `lhbstats`, `rhbstats` | 2921 each | 14 | same | batting splits vs LHP / RHP: 1b..hr, rbi, so, bb, ibb, sh, sf, hbp, tpa |
| `fbstats` | 2921 | 6 | same | fielding season stats: g, po, a, e |
| `career` | 2921 | 9 | same | batting career totals |
| `pstats` | 1430 | 15 | same | pitching season stats |
| `lhpstats`, `rhpstats` | 1430 each | 13 | same | pitching splits vs LHB / RHB |
| `careerp` | 1430 | 11 | same | pitching career totals |
| `team` | 126 | 55 | `djb2(unique_team)` | team definitions |
| `tstat` | 126 | 5 | team key | win-loss by season half |
| `roster` | 2970 | 10 | sequential index, `%09x` | team membership and depth chart |
| `org` | 34 | 14 | `djb2(unique_team)` | MLB club to its AAA/AA/A affiliates, managers |
| `manager` | 34 | 21 | `djb2("Last,First")` | managers (capacity 36) |

A player is one key present in all 8 batter tables (`attrib`, `lhattrib`, `rhattrib`, `bstats`, `lhbstats`,
`rhbstats`, `fbstats`, `career`), and also in all 5 pitcher tables (`pitcher`, `pstats`, `lhpstats`,
`rhpstats`, `careerp`) if he pitches. In the shipped data all 13 player tables contain the same keys,
in the same order as `attrib`, with the same first and last name text; the pitcher tables are the
subset whose primary position is SP or RP (plus one two-way player). [V]

### 4.1 Text format [V]

```
<idx> <name>,<idx> <name>,...,;CRLF          header: columns 0..N-1, in order
<key>,<idx> <value>,<idx> <value>,...,;CRLF   one line per record
```

- Every line, the last included, ends with `,;` and CR LF. The header has no key.
- `<key>` is 9 lowercase hex digits (the 32-bit key with a leading `0`). In `roster` it is a plain row index.
- Every record carries every column, in index order (true of all 33,808 records). Values are ASCII
  text without `,` `;` CR LF. Numbers are decimal; `-` means "none" (an absent third pitch, a team
  with no standings yet).
- Values are never quoted. A name containing a comma cannot be written.

How the game reads it [V, `fn_80071A10`, 0x80071A10-0x80071E28]: it loads the text with
`fn_802B9300(name, 0x100, 4, &size)`; reads the header and, for each column, looks the name up in a
global name registry (`lbl_80619300`, built by `fn_8052AE7C`, `datalookup.cpp`), getting a field kind and
field id; at most 128 columns fit its stack arrays. For each line it parses the key as hex, finds or
creates a row id for that key (`fn_80377E90` / `fn_80377CD8`: the id is the number of keys inserted so
far, so ids follow file order of the first table that mentions a key), then for each value calls a
virtual setter: kind 0 = integer (`atoi`), kind 3 = string. A column whose name is not registered gets
id -1 and an empty string, so it is skipped. A record set whose file is missing (`mfbstats.dat`,
requested three times, is not on the disc) is skipped. Because columns are matched by **name**, a patch
may reorder or drop columns that the registry knows; a pack should not rely on that. [I]

### 4.2 Player attributes: `attrib`

Columns (index: name, observed range). Ranges are from the shipped data and say how wide the
in-memory field must be at least; they are not the limits.

| Idx | Name | Range | Meaning |
|---:|---|---|---|
| 0, 1 | `first_name`, `last_name` | text, up to 13 / 14 | key = `djb2("Last,First")` |
| 2 | `playerattrib_jerseynum` | 0-99 | |
| 3 | `playerattrib_bats` | 0-2 | R, L, S (`GAME_DATA.md` order) |
| 4 | `playerattrib_throws` | 0-1 | |
| 5, 6 | `..._primary_position`, `..._secondary_position` | 0-10, 0-13 | 0 SP, 1 C, 2 1B, 3 2B, 4 3B, 5 SS, 6 LF, 7 CF, 8 RF, 9 DH, 10 RP, then OF, IF, UT |
| 7, 8 | `..._height`, `..._weight` | 18-35, 50-190 | scaled units, not inches or pounds |
| 9 | `..._boneprofile` | 26-37 | body model; 25 is used by generated players |
| 10 | `..._face` | 1-915 | 901-915 are generic cyberfaces (used by 2,456 of 2,921 rows) |
| 11 | `..._face2004style` | 0-1 | |
| 12-16 | `skin_tone`, `hairstyle`, `haircolour`, `facialhair`, `bodytype` | 0-10, 0-9, 0-6, 0-7, 1-2 | |
| 17 | `..._audioid` | 0-2665 | announcer pronunciation id (`rookie.big/audioid.csv`, `pnamedat.big`) |
| 18 | `..._photo` | 1-2 | |
| 19-22 | `platediscipline`, `bunting`, `stealing_aggressive`, `baserunning` | 0-15 | 4-bit ratings |
| 23 | `..._speed` | 39-99 | |
| 24-28 | `fielding`, `range`, `throwstrength`, `throwaccuracy`, `durability` | 0-15 | 4-bit ratings |
| 29-39 | `battingstance` (0-65), `swingtype`, `batcolour`, `batglove`, `wristband`, `elbowguard`, `shinguard`, `socks`, `catchermask`, `fieldglovecolour`, `ditty` | small enums | equipment and look; labels in `GAME_DATA.md` section 2 |
| 40, 41 | `..._salary`, `..._contract_length` | 0-251, 1-7 | |
| 42-44 | `starpower`, `topprospect`, `hidden` | 0-4, 0-1, 0-1 | |
| 45 | `..._birthday` | 7-17204 | days since 1 January 1948 |

**There is no team, contract role, injury, energy or disabled-list column on disc.** The game's name
registry has 55 attrib ids; the 11 that the file does not carry are `offercount`, `personality`,
`playedtoday`, `energylevel`, `injurytype`, `injuryduration`, `promisedrole`, `tooinjured`,
`contractvalueadj`, `contractyearadj`, `contractroleadj`. They are the "dynamic" fields that
`GAME_DATA.md` section 2 describes (energy, injury type and time, contract type, DL slot); they
start at defaults when the tables load and change during play. [V for the names, I for "defaults"]

### 4.3 Splits and pitchers

`lhattrib` / `rhattrib` (`lrattrib_*`): `contact`, `power` (0-100); `hit_ul..hit_lr`, nine zone flags
(0-2); `lf_pct`, `cf_pct`, `rf_pct` (spray), `hr_pct`, `fb_pct`, `ld_pct`, `gb_pct` (batted-ball mix);
then `chase`/`take`/`miss` for `fb`, `slowbreak`, `hardbreak` (0-15, nine fields). `rhattrib`
has all 27 rating columns; **`lhattrib` omits `lrattrib_chasehardbreak`** (28 columns, not 29), though
the registry knows it. [V]

`pitcher` (`pitchattrib_*`): `stamina` (30-99), `pickoff` (0-15), then five pitches. The fastball has
`movement`, `description` (both 0 in the data), `control`, `velocity` (78-101); pitches 2-5 each have
`type` (1-14), `movement`, `description`, `control`, `velocity`; pitches 3-5 are `-` when absent;
`pitcher_delivery` (0-58). The registry adds `pitchattrib_current_stamina_nl` (runtime). [V]

Stats tables hold the real 2004-style counting stats and are keyed like `attrib`; their ranges are
in `dbtables.py ranges`. `pstats.pitchstat_ip` is 0-255 and `pitchstat_pip` 0-2 (thirds of an inning);
the registry adds `pitchstat_wp` (not on disc).

### 4.4 Teams

**`team` (126 records, 55 columns).** `unique_team` (3 letters), `team_location`, `team_long_name`
(the nickname), `team_short_name` (the display abbreviation: `unique_team` in capitals in all 126 rows), `team_league` (0-10), `team_division` (0-25), `team_artid`,
`team_climatezone` (0-2), `team_homeintensity` (0-2), then 32 columns `team_vs_<abbr>` (30 MLB
clubs, then `al`, `nl`; values 0-2; meaning not determined) and 14 manager-strategy settings
(`team_pinchhitter` ... `team_suicidesqueeze`, each 0-2). The registry adds `team_hidden`,
`team_windtype`, `team_winddirection`, `team_tier_payroll`, `team_tier_winpct`. [V]

Row order [V]:

| Team index | Count | What |
|---|---:|---|
| 0-29 | 30 | MLB clubs. 0-13 league 0 (AL), 14-29 league 1 (NL). Order is `GAME_DATA.md` section 3 |
| 30, 31 | 2 | AL and NL All-Star teams (league 0 / 1) |
| 32-61 | 30 | Triple-A (leagues 2, 3) |
| 62-91 | 30 | Double-A (leagues 4, 5, 6) |
| 92-121 | 30 | Class A (leagues 7, 8, 9) |
| 122-125 | 4 | MVP Legends, MVP Heroes, Burnaby Argonauts, Burnaby Chimaera (league 10) |

`team_artid` is the row index plus 1 (1-126). Each MLB club has three affiliates, one per level,
named in `org`. `team_league`/`team_division` encode the league structure (11 leagues, 26 divisions);
changing a club's league needs matching schedule files.

**`tstat`.** Same 126 keys in the same order; `team_wins_1sthalf`, `team_losses_1sthalf`,
`team_wins_2ndhalf`, `team_losses_2ndhalf`; `-` for teams that do not play a season (the four extras).

**`org` (34 records).** One per organization: the 30 clubs plus the AL and NL All-Star sides, Legends
and Heroes. Columns: `unique_team`; `org_team_mlb`, `org_team_aaa`, `org_team_aa`, `org_team_a`
(the **decimal** team keys of the four levels; 0 = none); `org_is_franchise`, `org_spring`, `org_budget`
(0-100000), `org_penalty1..4`; `org_mlb_manager`, `org_minors_manager` (manager keys as a **signed**
32-bit decimal, e.g. a negative number). All 34 `org_mlb_manager` values resolve to `manager` rows;
`org_minors_manager` points the 30 clubs at one shared "A Manager" row; the four extras (AL, NL, Legends, Heroes) hold a value that is not a manager key. The registry
has 35 org ids; the rest (`org_*_hittingcoach_nl`, `org_*_scout_nl`, `org_trainer_nl`, `org_numyearsin`,
`org_tieratstart`, `org_dailytrade`, `org_cpu_accepted_trades`, `org_tradecount`, `org_frangoal1..8`,
`org_completekeygoals`) and the hitting-coach, pitching-coach, scout and trainer tables
(`hittingcoach_*` ...) are franchise state with no file. [V for the names]

**`manager` (34 records).** `manager_jerseynum`, `audioid` (5000-5048), height/weight (72/200 for all),
`boneprofile`, `face`, `skintone`, `hairstyle`, `haircolour`, `facialhair`, `bodytype`, four ratings
(`hitting`, `baserunning`, `fielding`, `pitching`, 70-100), `salary`, `reallife`, `birthday`. Row 0 is
the `Default` manager and the last is a generic "A Manager". [V]

**`roster` (2970 records, 10 columns).** Key = row index (`000000000`, `000000001`, ...). Columns:
`roster_teamid` and `roster_playerid` (keys with a leading 0), then four pairs of
(position code, batting order): `rh_roster_al_*`, `rh_roster_nl_*`, `lh_roster_al_*`, `lh_roster_nl_*`
(lineup against right/left-handed starters, with or without a designated hitter). Rows are grouped by
team in team-table order, **25 rows for each MLB, All-Star, Triple-A and special team (indices 0-61,
122-125) and 22 for each Double-A and Class A team (62-121)**: 66 x 25 + 60 x 22 = 2970. Position codes:
`C`, `1B`, `2B`, `3B`, `SS`, `LF`, `CF`, `RF`, `DH`, `SP1`-`SP5`, `LR`, `MR`, `SU`, `CP` and `B` (bench);
batting order is 1-9 for the nine lineup slots, `-1` otherwise. The 50 players that appear on two teams are probably the
two All-Star rosters [I]. This is the **only** place a player's team is recorded. All 2,920 non-default
players appear; the `Default` row does not. [V]

### 4.5 Other files

- `hist.dat` [V for size, I for fields]: a big-endian u32 record count (11,989), then fixed 25-byte
  records: a u32 player key (`djb2("Last,First")`, 1,304 distinct players, some of them retired players
  not in `attrib`), a constant byte `01`, then packed fields containing a big-endian u16 season at
  offset 9 (1890-2004).
- `rookie.big` [V names, I use]: `names.csv` (first, last, "use full name" flag), `audioid.csv` (announcer id to
  surname), and rating-distribution tables for generated players (`power`, `contact`, `baserun`,
  `fielding`, `movement`, `control`, `stamina`, `durable`, `platepit`, `discipli`, `pickoff`, `buntgen`,
  `hittend`, `hczone`, `4sfbvel`, `knuckle`, `body`, `height`, `weight`, `hair`, `ethnic`, `secpos`,
  `star`, `retire`).
- `progress.big` [V]: `contract.csv` (asking prices by age and star level), `progbadj/progbinc/progbdec` and
  `progpadj/progpinc/progpdec` (batter and pitcher progression odds by age), and `stadium.csv`: 30 rows
  of park factors (`Hr`, `Hit`, `3B`, `2B` modifiers) keyed by the **`unique_team` string of the 30 MLB clubs**.
- `schedule.big` [V]: `DATE,Time,Home,Road,Half` CSV, teams by `unique_team` text. `mlb162_1`..`_3`
  are the three dynasty years.

## 5. Loader and in-memory structures

All [V] unless marked.

- `fn_80071FA0` (0x80071FA0, size 0x590): constructor of the 0x210-byte database object. It builds 14
  table-group objects (the `Tbl80090B28` ... `Tbl800956D8` classes, `src/game/tu_80070DDC.cpp`
  fields `t38` ... `t1C0`). Each group owns a `DbObj`, which is a sorted key array (`SortArr`,
  `fn_803779B8`: capacity `cap` entries of 12 bytes: key, value 1, value 2) and several record sets
  (`Rec`, `RecA`, `RecB`, `RecC`, ...). A record set named like a file loads that file; one with the
  empty name (`lbl_805B2CB0` is `""`) has no file and holds runtime state, for example current-year stats. [I for "current year"]
- `SortArr` insertion (`fn_80377B1C`, source in `src/gamelib/tu_80377048.cpp`) shifts entries up and bumps the count **without
  comparing to the capacity**; inserting a duplicate key into a table with the duplicate flag clear
  returns the old slot. Overflow therefore corrupts the heap.
- Row ids are insertion order; memory-card saves write the raw record arrays (`fn_80070DDC` writes
  `count * 0xC` bytes for one class). [I for the save format of other classes]
- Record sets are bit-packed: `Unk80071170_Rec` in `tu_80070DDC.cpp` shows 12/14/6/13/10/9... bit
  fields in 32-bit words. The per-field bit offsets and widths of the real records are **not**
  recovered; `dbtables.py ranges` prints the minimum bit width from the data.
- The name registry `fn_8052AE7C` (0x8052AE7C, `datalookup.cpp`) registers each table's field names
  with a kind (0 = int, 3 = string) and an id, from the `.data` pointer arrays `lbl_806195D8` (attrib, 55
  ids), `lbl_806196BC` (left/right attrib), `lbl_806194E0` (pitcher), `lbl_80619848` (team, 56), `lbl_80619928`
  (team strings), `lbl_80619938` (tstat), `lbl_8062294C` (org, 35 + staff), `lbl_80619358` (manager), the stats
  arrays, and others. The order of an array is the id order of the in-memory fields.

## 6. Capacities and hard-coded counts

### 6.1 Table capacities [V]

Set in the `v5` setup function of each table group (`tablemanager.cpp`, the source line is the
last argument to `fn_803779B8`). All immediates are in `li` instructions.

| Group | `v5` address | Capacity | Record sets (file name) |
|---|---|---:|---|
| `Tbl80094800` (batters) | `0x80094C6C` | **3250** (`0xCB2`) | `attrib`, `lhattrib`, `rhattrib`, `bstats`, `lhbstats`, `rhbstats`, `fbstats`, `mfbstats` (x3, missing on disc), `career`, plus unnamed copies |
| `Tbl800956D8` (pitchers) | `0x80095A88` | **1800** (`0x708`) | `pitcher`, `pstats`, `rhpstats`, `lhpstats`, `careerp`, plus unnamed copies |
| `Tbl8009101C` (teams) | `0x80091240` | **126** (`0x7E`) | `team`, `roster`, `tstat`, plus unnamed sets (`li` at 0x8009126C, 0x800912B0, 0x800912E0, 0x80091310, 0x80091340, 0x80091370) |
| `Tbl80090B28` (orgs) | `0x80090CB8` | **34** (`0x22`) | `org`, one unnamed set (`li` at 0x80090CE8, 0x80090D28, 0x80090D58) |
| `Tbl80091760`, second instance (`this+0x8C`) | `0x8009191C` | **36** (`0x24`) | `manager` (the name `lbl_805B3CC8` is passed in `fn_80071FA0` at 0x8007203C) |
| `Tbl80091760` first instance (`this+0x6C`), `80091EAC`, `80092370`, `800927D0`, `80092C94`, `800930F4`, `800935B8`, `80093A18`, `80093EDC`, `8009433C` | `fn_80071FA0` passes the sizes (0x80072030-0x800720C8) | 116, then 80 x5, 120 x2, 50 x2 | unnamed (no file on disc); probably franchise staff and state (coaches, scouts, trainers: not mapped to names yet) [I] |

Free room in the shipped data: **329 player slots** (3250 - 2921), **370 pitcher slots** (1800 - 1430),
**2 manager slots** (36 - 34), **0 team slots**, **0 org slots**. Generated rookies and created players use free player slots,
so a pack that fills the table leaves nothing for the draft.

### 6.2 Counts of 126 and 34 in code

- **Verified 126:** `fn_80574478` (0x80574478, stadium park-factor table: loop `i < 0x7E`, 16 bytes
  per team; fed by `stadium.csv` in `fn_805744D4`), its getters `fn_80574750`, `fn_80574798`,
  `fn_805747E4`, `fn_80574830` (bound `i <= 0x7D`, else a default); the setup in `fn_8032FD58`
  (0x8032FD58: `li 0x7E` as an element count and `li 0x1F8` = 504 bytes zeroed, which is a 126-entry int
  array; what it holds is [I]); the team group in 6.1.
- **DL slots 0-503** (`GAME_DATA.md`) = 126 x 4. [I]
- **Likely 126, not read yet:** `fn_8056C610` and `fn_8056C1C4` (0x7E/0x7D stack lists, `db/tu_8056BAEC`),
  `fn_8057DA7C` (0x7E; `db/tu_8057CDB8`), `fn_8059F680` (0x7D), `fn_80546600` (0x7D loop),
  and in game code `fn_80163CC4`, `fn_80165F94`, `fn_801D8330`, `fn_80314B8C`, `fn_8030AD10`,
  `fn_8006A2C4`, `fn_80365C10`, and `fe/fn_8047C444`. Immediates of 0x7D-0x7F also occur in audio and
  controller code (127), so each hit needs a look.
- **34-way switches** in the database overlay: `fn_8052A404` and `fn_8052A894` (`db/tu_8052A220`:
  per-index bit-field setter and getter, clamp 0-31), `fn_8052E754`, `fn_8052E9C4`, `fn_8052EE14`
  (`db/tu_8052E4C0`). The index range is 0-33 (bounds `0x21`/`0x22`) and 0-29/30 is the MLB part, so these are
  probably per-organization values. [I]
- **30-clubs loops** (`0x1D`/`0x1E` bounds) appear in about 40 database overlay functions, for example
  `fn_80535EAC`, `fn_8053967C`, `fn_8054CF78`, `fn_8055A3B0`, `fn_8059A028`, `fn_805A07C4`, and in the end of
  `Tbl80094800::v7` (0x80095178). They mean "the 30 MLB clubs" and are unaffected by slot replacement. [I]

### 6.3 Asset counts that fix the team count

| Asset | Count | Evidence |
|---|---|---|
| `frontend/logos.big`, `logos_a.big` | `l000`-`l125` / `a000`-`a125` (126) + `l994`-`l999` / `a994`-`a999` | entry names |
| `frontend/uniforms.big` | 588 entries; `000.gsh`-`123.gsh` (124) and a lettered family per index (`a`, `b`, `c`, `g`, `h`, `i`, `j`, `k`, `o`, `s`, ...) | entry names |
| `frontend/load0..load48.big` | 49 load screens, one `loadN.gsh` each | file list |
| `frontend/stadiums.big`, `data/stadium/*.big` | 93 entries / about 93 stadium day-night files | file list |
| `audio/spch_pbp/tnamedat.big` | 124 entries (`01.dat`-`124.dat`), probably team-name announcer clips [I]; `spch_pa/tnamedat.big` 91 | file list |
| `audio/spch_pbp/stdnmdat.big` | 94 stadium-name clips | file list |

## 7. Where names and looks come from

- **Team names.** Three sources, all of which a team pack must keep consistent:
  1. `team.dat`: `team_location`, `team_long_name`, `team_short_name`, `unique_team`. [V]
  2. `FEENG.LOC` (front end) and `IGENG.LOC` (in game), UTF-16LE text files, format in `loc.py`
     (`LOCH`, `LOCI` = (string id, index) pairs, `LOCL` = offset table plus strings; all three English
     files re-serialize byte for byte). The 30 MLB clubs and the AL/NL sides have the nickname at id
     `2000+n` and the full name at `2040+n` (`n` follows division order: AL East, Central, West,
     NL East, Central, West, i.e. not the `team.dat` order), plus more copies (ids around 16000, 17200,
     17618-17645, 22177-22208, 22941-22964). Triple-A and below have their own ranges (for example 20190, 20191
     in the first rows). Stadium names are also LOC strings (for example 8001, 13565). [V for the
     format and examples, I for the exact id map of all 126 teams]
  3. Announcer audio (`tnamedat.big`): the spoken name. A new name is silent or wrong until the clip is replaced. [I]
     Which text comes from which source, and the id tables, are in section 12.6.
- **Logos.** `logos.big` / `logos_a.big`: `l###.gsh` / `a###.gsh`, `###` = `team_artid - 1` = the `team.dat` row. [V, section 12.4]
- **Uniforms.** `uniforms.big` (front end) and `models.big` (in game): `###` plus a letter `a`-`p`; `a` is the first
  slot and `b` the second. Section 12.5. `coopunis.big` has the co-op menu thumbnails `c001`-`c122`; they are not
  per slot. [V]
- **Load screens.** `load0..load48.big` are not tied to a team at all: the game picks one at random (section 12.9). [V]
- **Stadiums.** Each team's stadium is not a column in `team.dat`. It is a table in the program itself
  (`lbl_805B64A8`, 124 entries, `.rodata`), which gives a stadium id; three more tables give the park file
  names. The chain, and the 4-letter codes, are in section 12.7. [V]
- **Player faces and photos.** `attrib.face` / `photo` select assets in `frontend/portrait.big` (2393 entries,
  `NNNN.gsh` and letter names), `ghead.big` (8400 in-game head textures) and `models.big`. The mapping
  from the id to the entry name is not decoded (only 278 of 465 non-generic face ids match a
  four-digit portrait name directly). [open]

## 8. What a pack must patch

Patches are semantic and applied to the tables read from the player's own disc (`ARCHITECTURE.md`
section 8). The unit of change is a keyed record.

### Roster pack (existing team slots)

1. **Player records.** For every player, the same key in all 8 batter tables, and in all 5 pitcher
   tables for pitchers. Stats rows may be zero rows. `first_name`/`last_name` must repeat the same text
   in every table. Compute the key with `djb2("Last,First")` and write it as `%09x`. Two players
   with the same "Last,First" cannot coexist. [V]
2. **Team membership and depth chart.** Replace the `roster` rows of the affected teams: 25 rows (MLB,
   Triple-A, All-Star, special teams) or 22 (Double-A, Class A), with the position codes and batting
   orders above. Row keys must stay a dense sequence if rows are added or removed (the shipped file is
   `000000000`..`000000b99`). [V for the data, I for "must"]
3. **Capacity.** Total players <= 3250 and pitchers <= 1800, leaving spare slots for the draft. [V]
4. **Related assets**, optional: `audioid` and `pnamedat.big` for the announcer, `face`/`photo` for portraits,
   `hist.dat` for career history lines.
5. **Not on disc:** contract role, injury, energy, DL slot, happiness (section 4.2). A pack cannot set them by patching
   `database.big`; they come from game rules at setup. Whether a pack should set initial contracts is open.

### Team pack (replace a slot)

Keep `unique_team` and the row position; change the display data:

1. `team.dat` display fields (`team_location`, `team_long_name`, `team_short_name`) and, only if intended,
   league/division/climate/strategy columns. Keep `team_artid`.
2. The LOC strings for that team in `FEENG.LOC` and `IGENG.LOC` (nickname, full name, location, abbreviation
   copies, and the stadium name if changed).
3. `roster` rows for the team and, for an MLB club, its three affiliates; `org` links if affiliates change;
   `manager` row and `org_*_manager` (signed key).
4. Assets by index: logo `l###`/`a###`, uniforms `###*` (front end) and `u###*`/`f###*` (in game), `stadiums.big`
   picture, announcer clips `NN.dat`/`NN.hdr`. `###` is the `team.dat` row, `NN` is `team_artid`. There is no
   per-team load screen. The full list, with the exact names, is section 12.11.
5. If `unique_team` must change: also every schedule CSV in `schedule.big`, `stadium.csv` in
   `progress.big`, and the keys (`team`, `tstat`, `org` rows and `roster_teamid`, `org_team_*`).
   Avoid it.
6. A club in a minor-league slot needs only the `team`, `tstat`, `roster` rows and assets.

### More than 126 teams

Needs code hooks: the capacity immediates in 6.1 (`li r4/r6, 0x7E` in `Tbl8009101C::v5`), the stadium factor
table (6.2), the unread 126-element structures, and 127+ assets in every table of 6.3. Not recommended
before the K2 inventory of 6.2 is finished.

## 9. Proposed names

None of the proposals in this table is applied: none has tier E (EA name), S (a string that names the
function) or K (SDK name) evidence, only the string argument, the callers or the matched source. The rows
marked **(named)** at the end are different: names pass 01 (2026-10-14, `tools/goals/renames/names01.tsv`)
applied them from EA's reference-build names for the same code.

| Address | Name | Evidence |
|---|---|---|
| `fn_802B8CCC` | `LoadDatabaseBig` | loads `"database\\database.big"` into `lbl_8061EABC` through `fn_802B9300` |
| `fn_802B8D34` | `UnloadDatabaseBig` | frees `lbl_8061EABC`; called by `fn_8007295C` after the table loads |
| `fn_802B8D74` | `LoadScheduleBig` | string `"database\\schedule.big"` into `lbl_8061EAC0` |
| `fn_802B8E1C` | `LoadProgressBig` | string `"database\\progress.big"` into `lbl_8061EAC4` |
| `fn_802B8EC4` | `LoadRookieBig` | string `"database\\rookie.big"` into `lbl_8061EAC8` |
| `fn_802B9300` | `AssetLoadFile` | `(path, mode 0x100/0x400/0x500, kind, &size) -> buffer`; callers pass `.dat`, `.csv`, `.gsh`, `.orl`, `.big` names |
| `fn_802B961C` | `AssetFreeFile` | called with the buffer after every parse (kind repeated) |
| `fn_8007295C` | `LoadDatabaseFromDisc` (method of `Unk8007A4DC_Screen`) | loads `database.big`, `v7` of the five table groups, frees it |
| `fn_80071A10` | `RecLoadTableText` | the text-table parser described in 4.1 |
| `fn_80071FA0` | `Database::Database` | builds the 14 table groups (section 5) |
| `Tbl80094800` | `BatterTables` | `v5` sets up 15 record sets (nine file names) with capacity 3250 |
| `Tbl800956D8` | `PitcherTables` | `v5` sets up 8 record sets (five file names) with capacity 1800 |
| `Tbl8009101C` | `TeamTables` | `v5`: `team.dat`, `roster.dat`, `tstat.dat`, capacity 126 |
| `Tbl80090B28` | `OrgTables` | `v5`: `org.dat`, capacity 34 |
| `fn_8052AE7C` | `DatalookupRegisterFieldNames` | registers field names (`datalookup.cpp` path in `UNITS.md`) |
| `fn_80378568` | `HashDjb2` | `h = h*33 + c` from 5381, as `src/gamelib/tu_80377CD4.cpp` already says; matches every key |
| `fn_80574478` | `StadiumFactors::StadiumFactors` | 126-entry float table, loads `stadium.csv` |
| `fn_805744D4` | `StadiumFactors::LoadCsv` | calls `fn_802B8E1C`, loads `"stadium.csv"` |
| `fn_80401710` | `unpackz` **(named)** | RefPack decode entry (section 2.2); E: EA `unpackz` in fifa05, ge, moh4, uefa |
| `fn_804017D0` | `unpacksizez` **(named)** | RefPack unpacked size (section 2.2), called by `fn_802B9300`; E: EA name in fifa05, ge, moh4, uefa |
| `fn_80401924` | `REF_decode` **(named)** | RefPack decoder (section 2.2); E: EA name in fifa05, ge, moh4, uefa |
| `fn_80401644` | `sizerefpack` **(named)** | RefPack size scan; E: EA name in fifa05, ge, moh3, moh4, uefa |
| `fn_803FFA60` | `MEM_copy` **(named)** | the copy `fn_802B9300` uses for uncompressed payloads; E: EA name (ge, hp, moh4, nfsmw) |
| `fn_803F9C58` / `fn_803F9D74` | `FILESYS_open` / `FILESYS_read` **(named)** | the EA file layer that `fn_802B9CCC` (the disc-read path of `fn_802B9300`) opens and reads through, with `FILESYS_waitop`, `FILESYS_size`; E: EA names in fifa05, ge, moh3, moh4, uefa |

## 10. Open questions

1. ~~**Slot-to-asset mapping.**~~ Answered in section 12 (2026-10-14); what is left of it is in 12.12.
2. **Full inventory of team-sized structures.** Section 6.2 lists verified and candidate sites. Each candidate
   must be read, and the engine can test what breaks (a 127th team, a team count of 120) with
   a hooked build. Without it, "more than 126 teams" stays off the table.
3. **Initial dynamic state.** Where contract role, energy, injuries, DL slots and happiness are initialised for a new
   exhibition or dynasty (`contract.csv`? the roster position?), and what a memory-card save stores
   (`fn_80070DDC` family), so that packs do not fight saves.
4. Does the game accept a larger `database.big` and `refpack.py`-compressed payloads (section 2.2)? Test in the E2
   VFS, or serve the tables uncompressed.
5. In-memory record layouts: bit offsets and widths of each table's record (section 5), needed if packs ever
   patch memory instead of files.
6. The `team_vs_*` columns, the `hist.dat` field layout, the staff tables and the unnamed record sets.
7. Why `lhattrib` omits `lrattrib_chasehardbreak`, and what the game does with a missing column (it appears to
   leave the field at its default).

## 11. Reproduce the checks

On a machine with the disc image (Git Bash: `export MSYS_NO_PATHCONV=1`):

```
python -I tools/rosters/dbtables.py check "image.ciso:/data/database/database.big"
python -I tools/rosters/dbtables.py list  "image.ciso:/data/database/database.big"
python -I tools/rosters/loc.py check FEENG.LOC     # after extracting with big.py / gcdisc.py into a scratch dir
python -I -m unittest discover -s tools/rosters/tests
```

Result on 2026-10-14 (GV4E69 rev 0): the archive layout is canonical; **all 18 tables re-serialize byte for
byte** (33,808 records); an unchanged `Database.to_bytes()` reproduces `database.big` byte for byte; with
every table recompressed by `refpack.compress` the archive is 1,058,652 bytes (original 1,010,678) and
reads back identical. 193 of 197 `.big` archives on the disc rebuild identically. `FEENG.LOC`, `IGENG.LOC`
and `MC_ENG.loc` re-serialize identically. Nothing from these runs is committed.

## 12. Team slot assets

How a team slot selects each of its assets. This answers open question 1 and is the input for E7 (team packs).
Written 2026-10-14 from the disc image (only archive and entry names, sizes and container headers were read),
the matched sources in `src/` and the split assembly. No asset bytes are quoted. Tags as in the legend at the top:
**[V]** read in code or reproduced on the disc, **[I]** inferred. `fn_`/`lbl_` names are the project's names for
addresses in the DOL; a "data" table means the words are in `main.dol` itself.

### 12.1 Short answer

1. **Three numberings select a team's assets, and they are not the same.** [V]

   | Name | Range | Definition | Selects |
   |---|---|---|---|
   | **row** `r` | 0-125 | the row of the team in `team.dat`; `team_artid = r + 1` on all 126 rows | art file names: logo `l<r>`, uniforms `<r>` / `u<r>` / `f<r>`; announcer clip number `r + 1` |
   | **tid** | 0-123 | position in the program's own team list `lbl_80619D34` (124 `unique_team` strings, `.data`): MLB 0-29 in alphabetical order (Ana, Ari, Atl, Bal, Bos, ChC, CWS, Cin, Cle, Col, Det, Fla, Hou, KC, LA, Mil, Min, NYM, NYY, Oak, Phi, Pit, SD, SF, Sea, StL, TB, Tex, Tor, Was), 30 AL, 31 NL, 32-61 AAA, 62-91 AA, 92-121 A (each level alphabetical by city), 122 Leg, 123 Hro | every table that is compiled into the DOL: row translation, LOC string ids, home park. Rows 124 and 125 (Burnaby) have no tid |
   | **stadium id** `S` | 0-55 | `lbl_805B64A8[tid]` | park variant, park picture, park name text, park name clip |

2. **`unique_team` and the row are code constants.** The game turns every team into a tid by hashing: `fn_800B5414`
   (0x800B5414) computes `djb2(lbl_80619D34[i])` for the 124 tids; `fn_800B5520` (0x800B5520) finds a key by linear search
   and **returns 0 (Anaheim) when it is not found**. The strings are compared as hashes, so they are case sensitive
   (`ChC`, `CWS`, `StL`, `TB`...). A slot keeps its `unique_team` and its row, always. All 124 strings equal the
   `team.dat` `unique_team` values, and `lbl_805C36C0[tid]` equals the `team.dat` row of that team for all 124 tids (checked
   by script). [V]
3. **File-overridable** (replace an entry inside a `.big`, or a text file): logos and team colours, uniforms (front end and in
   game), announcer team-name clips, `team.dat` strings, LOC strings, park contents and pictures, stadium-name clips.
   **Not file-overridable:** which park a team plays in, the tid list, the LOC-id tables, the 16-letter uniform limit.
   Those are words in `main.dol` (12.9); the engine needs a data-patch hook to change them. [V]
4. **Load screens are not per team**: the game picks one at random (12.9). **Team colours are not a table**: the colour bar,
   gradient and cap shapes are images inside the logo container (12.4). [V]

### 12.2 One-page map

| Asset | Selector (see 12.1) | Archive and entry | Overridable by file |
|---|---|---|---|
| Logo (front end) | row, through the tid table | `frontend/logos.big`: `l<r>.gsh` | yes |
| Logo (in game, scoreboard) | `team_artid - 1`, read from the database | `frontend/logos.big` `l<r>.gsh` + `frontend/logos_a.big` `a<r>.gsh` | yes |
| Colour bar, gradient, cap shape | same as the logo | images `e`, `g`, `d` inside `l<r>.gsh` | yes |
| Uniform pick list, preview | row, letter | `frontend/uniforms.big`: `<r>.gsh`, `<r><x>.gsh` | yes |
| Uniform on the field | row, letter | `models.big`: `u<r><x>.gsh`, `f<r><x>.gsh`, `a<r><x>.gsh` | yes |
| Names, abbreviation, city | tid (LOC) and key (`team.dat`) | `database.big/team.dat`, `FEENG.LOC`, `IGENG.LOC` | yes |
| Load screen | none (random) | `frontend/load<N>.big`, N 0-48 | only as a global change |
| Home park choice | tid, then `S`, then variant | tables in `main.dol` | **no** (engine patch) |
| Park contents | variant name | `stadium/<name>.big`, `datafile.big/<name>.txt`, `stadium/lighting.csv` | yes |
| Park picture, field icon | variant | `frontend/stadiums.big`, `frontend/fields.big` | yes |
| Team-name announcer clip | `team_artid` | `audio/spch_pbp/tnamedat.big` + `tnamehdr.big`, `audio/spch_pa/...` | yes (needs an EA SCHl stream) |
| Park-name announcer clip | `S` | `audio/spch_pbp/stdnmdat.big` + `stdnmhdr.big` | yes |
| Team crowd events | team code | `audio/crowddb/audiocsv.big/chants.csv` | yes [I] |

### 12.3 Identity machinery [V]

| Item | Where | Notes |
|---|---|---|
| tid list | `lbl_80619D34`, 124 string pointers, `.data` | read by `fn_800B548C` (0x800B548C, tid to key) and `fn_800B5414` |
| key list | `lbl_80619F24`, 124 ints, `.data`, filled at run time | `fn_800B5520` key to tid (0 if absent) |
| artid list | `lbl_8061A114`, 124 ints, `.data`, filled at run time | `team_artid` of each tid, read from the team record set (field 2); `fn_800B54BC` (0x800B54BC). Its only caller is the in-game logo loader |
| tid to row | `lbl_805C36C0`, 124 ints, `.rodata` | `fn_800E1AC8` (0x800E1AC8); used by the front end for logo, uniform and gradient names |
| level of a tid | `fn_800E1990` (0x800E1990) | 0 for tid 0-31 (and 122, 123), 1 for 32-61, 2 for 62-91, 3 for 92-121; `fn_800E19CC` is 1 for tid 0-29 and 122, 123 |
| team record field order | registry `lbl_80619848` | 0 `team_league`, 1 `team_division`, 2 `team_artid` (7 bits in the in-game record, `fn_8009E1D4` 0x8009E1D4), 3 `team_homeintensity`, 4 `team_hidden`, 5 `team_climatezone`, ... |

Slot rules that follow: a pack replaces rows 0-123 (a row has a tid), keeps `unique_team`, `team_artid = row + 1` and the
row order, and puts every asset at the row's number (12.11). Rows 124 and 125 are not usable slots.

### 12.4 Logos and colours

| Item | Detail | Tag |
|---|---|---|
| Archives | `frontend/logos.big`: `l000`-`l125` (126 slots) and `l994`-`l999`, 132 entries, all RefPack. `frontend/logos_a.big`: `a000`-`a125`, `a994`-`a999`, 132 entries, all RefPack | V |
| Container | each entry is an SHPG shape group (magic `SHPG`, image count, image directory of 4-letter names). `l<r>.gsh` holds 7 images named `l`, `j`, `i`, `g`, `e`, `d`, `a` followed by the 3-digit number: `l` 128x64, `j` 32x16, `i` and `g` 64x64, `e` and `d` 8x32, `a` 128x64, 4 bits per pixel with a palette. `a<r>.gsh` (about 100 KB unpacked) holds the same 7 names with 32 bits per pixel. `l994`, `l997`-`l999` hold 6 images (no `l`) | V names and sizes, I pixel formats (from sizes) |
| Front end | a logo widget names its image `<c><nnn>`: format `%c%03d` (0x805BC978) in `fn_800D2D9C` (0x800D2D9C) and `fn_800D2CF8` (0x800D2CF8); `c` is the first letter of the widget's own image name and `nnn = fn_800E1AC8(tid)`, the row. Widgets: `LOGOS`, `MEDIUMLOGOS`, `LARGELOGOS`, `CROPPEDLOGOS`, `TEAMGRADS/*` | V |
| Colours | the player-card widgets take `CAPLARGE` the image `g`, `TEAMBAR` the image `e` and `TEAMGRAD` the image `d`, format `%c%3d` (0x805C0518) and the number 999 when there is no team (`fn_801275EC`, 0x801275EC; default names `e999`, `d999` at 0x805C0520). So the cap (64x64), the colour bar and the gradient (8x32 each) are images inside the same container as the logo: there is no colour table | V |
| In game | at game start `fn_800C1A24` (0x800C1A24) takes the home and away team keys, converts each to a tid and reads that tid's artid (`fn_800B54BC`), builds `l%03d.gsh` (0x805BB110) with `artid - 1`, opens `frontend/logos.big` (0x805BB0FC); `fn_802B0224` (0x802B0224) loads that entry, replaces the first letter by `a`, loads the entry from `frontend/logos_a.big` (0x805E0138) and joins them (`fn_802B9FF0`). Only the two teams of the game are loaded | V |
| Two paths, one number | the front end uses the static row, the game uses `team_artid`. They are equal in the shipped data; a pack keeps them equal | V |
| Special numbers | `999` is the "no team" set. `994`, `997`, `998` are other generic sets (use not traced). `l995`/`l996` and `a995`/`a996` have the sizes of 125 and 124 (copies of the Burnaby logos) | V sizes, open use |
| Override | replace `l<r>.gsh` in `logos.big` and `a<r>.gsh` in `logos_a.big`, same image names and sizes. An uncompressed entry is accepted by the generic loader (`fn_802B9300` passes non-RefPack data through, section 2.2) | I |

### 12.5 Uniforms

Letters: 16 slots `a`-`p` (`lbl_805B6B98`, bytes `abcdefghijklmnop`). A uniform choice is a pair (tid, letter index), the
object `Unk80084910_N` in `src/game/tu_80084910.cpp`. Formatters (all take the pair):

| Function | Format | Result |
|---|---|---|
| `fn_80086030` (0x80086030) | `%03d` (0x805B45CC) | `<r>` |
| `fn_80086078` (0x80086078) | `%03d%c.%s` (0x805B45D4) | `<r><x>.gsh`, front end file |
| `fn_800860E0` (0x800860E0) | `%03d%c` (0x805B45E4) | `<r><x>`, image name |
| `fn_80086140` (0x80086140) | `u%03d%c.%s` (0x805B45EC) | `u<r><x>.gsh`, in-game jersey sheet |
| `fn_800861A8` (0x800861A8) | `f%03d%c.%s` (0x805B45F8) | `f<r><x>.gsh`, in-game number/letter sheet |

with `<r> = fn_800E1AC8(tid)` (the row). [V]

| Part | Detail | Tag |
|---|---|---|
| Pick list (front end) | `fn_800C45C8` (0x800C45C8) tries the 16 letters and offers a letter when the entry `<r><x>.gsh` exists in `frontend/uniforms.big` (existence test of `archive\|entry`). The list is therefore data driven: more entries, more choices | V |
| `uniforms.big` | 124 containers `000.gsh`-`123.gsh` (SHPG, one 64x128 4-bit image per letter named `<r><x>`) plus one stub `<r><x>.gsh` per letter (74-116 bytes packed, one 1x1 image). Letters present: `a` 124 rows, `b` 120, `o` 30, `s` 30, `g` and `h` 28, `c` 24, `j` 20, `i` and `k` 18, `d` 13, `l` 5, `m`, `n`, `p`, `x` 1 each. `s` and `x` are not among `a`-`p`, so they are never offered [I]. Rows 30, 31, 122, 123 have only `a`; rows 32-121 have `a` and `b` | V |
| `models.big` | `u<r><x>.gsh`: jersey sheet, an SHPG of 28 named parts (cap `hat `, helmet `hhlm` `hlm1`, jersey `jers` `jerf` `jerk` `jert`, sleeves `slvl` `slvr` `aslv` `mslv`, legs `lega`-`legd`, `shoe`, `chst`, `bglb` `bglt`, `lace`, `wrbn`, masks `msk1`-`msk3`...); about 210 KB unpacked. `f<r><x>.gsh`: number and name glyph sheet (`zig0`-`zig9` 32x64, `A___`-`Z___` 16x32); about 55 KB. `a<r><x>.gsh`: optional second digit set (`zig0`-`zig9`), 27 entries on 13 rows. All 126 rows have `u<r>a` and `f<r>a`, including rows 124, 125; `u<r>b` is missing for rows 30, 31, 122-125 (`f<r>b` for 31, 122-125); a few `f` sheets have a letter with no `u` sheet (rows 7, 18, 21, 28, 30, 31) | V names, I use of `a<r>` |
| Loader | `fn_802C2A20` (0x802C2A20): builds `u<r><x>.gsh` with `fn_80086140`, tests that it exists, **if not replaces character 4 (the letter) by `a`**, loads it. `fn_802C2BB8` (0x802C2BB8): the same for `f<r><x>.gsh`, then tries the accessory `a<r><x>.gsh` (first letter replaced by `a`) when `fn_802C2CCC` accepts. Both in `src/game/tu_802BF974.cpp`. Without a (tid, letter) pair (the umpire case) `fn_802C2A20` builds `umpire.gsh` or `umpirec.gsh` (formats at 0x805E13AC, 0x805E13B8) | V |
| Level flags | `fn_800E1990` and `fn_800E19CC` of the tid set two flags in the loader (`mB4`, `mB8`) | V, I meaning |
| Home / away defaults | the ini names home `a` and away `b`; the code that picks the default letters of a new game was not traced | open |
| Co-op sets | `coopunis.big` `c001`-`c122` (122 thumbnails), `coopteam.big` `ct01`-`ct04`, `coopstad.big` `cs01`-`cs16` (+ `loc4`, `mst4`), `coopplyr.big` `cp01`-`cp64` (+ `loc2`, `mst2`): front-end art for the Cooperstown lists. They are chosen from fixed name arrays (`lbl_8061A864`, `lbl_8061AA40`, `lbl_8061AB3C`, `lbl_8061AB78`, used by `fn_800C47DC` and neighbours) by list position, not by slot. The `c###.gsh/.ord/.orl` files in `models.big` (504 of each) are player body models, not uniforms. A team pack does not need any of them | V arrays, I list meaning |

Override: add or replace `<r>.gsh` and `<r><x>.gsh` in `uniforms.big`, and `u<r><x>`, `f<r><x>` (and optionally `a<r><x>`) in
`models.big`. A slot works with `a` and `b` only; any further letter among `a`-`p` shows up in the pick list by itself. [V for the
front end enumeration, I for the in-game side accepting letters beyond the shipped ones]

### 12.6 Text: names, city, abbreviation, nickname

| Text | `team.dat` column | LOC id table (indexed by tid) | Id ranges, by tid group (MLB+AL/NL, AAA, AA, A, Leg+Hro) | Tag |
|---|---|---|---|---|
| full name | none (location + nickname) | `lbl_805C2F00`, `fn_800E18F8` (0x800E18F8), key form `fn_800E18D4` | 2040-2071, 20190-20219, 20220-20249, 22908-22937, 18099 and 18102; both LOC files | V |
| nickname | `team_long_name` | `lbl_805C30F0`, `fn_800E1930`, key form `fn_800E190C` | 2000-2031, 16010-16039, 16040-16069, 22938-22967, 18100 and 18103; both | V |
| abbreviation | `team_short_name` | `lbl_805C32E0`, `fn_800E1968`, key form `fn_800E1944` | 7200-7231, 16207-16236, 16237-16266, 22968-22997, 18101 and 18104; both | V |
| city | `team_location` | `lbl_805C34D0`, `fn_800E197C` | 17618-17647, 17648-17677, 17671-17706 (shared city strings), 22998-23027, 17707; `FEENG.LOC` only | V |
| park name | none | `lbl_805C38B0[S]`, `fn_800E1B68` (0x800E1B68), 56 ids | 13554-13559, 13565-13594, 14804, 17450-17458, 22002, 22276-22280, 22299, 22364, 22365, 22369, 23134, 23135; both | V |
| code | `unique_team` | the tid list (12.3) | not text | V |

Each id is a LOC string id (`loc.py`); the table gives one id per tid, so a pack looks the ids up through the tid of its
row (tid list in 12.3, tid to row in `lbl_805C36C0`). Checked: the strings behind these ids equal `team.dat` for 121 of 124
teams; the three exceptions are all the city text: row 101 (`team.dat` abbreviates it) and rows 122, 123 (a different
word). [V]

The `team.dat` strings are live as well: `Unk8007B2B0_Screen::fn_8007B924` (0x8007B924) reads string field 0-3
(`unique_team`, `team_long_name`, `team_short_name`, `team_location`) and is called by the franchise and roster screens in
the database overlay (`src/db/tu_80535360.cpp`, `tu_80584CBC.cpp`), by front-end screens (`src/fe/tu_8049E0BC.cpp`,
`tu_804FF6B4.cpp`, `tu_80519600.cpp`, `tu_80477068.cpp`, `tu_80488CDC.cpp`) and by `fn_800E4234` (0x800E4234), which
builds message text. So a pack must change both the `team.dat` strings and the LOC strings. [V]

### 12.7 Stadium

The chain from a team to its park files [V]:

```
home team key --fn_800B5520--> tid --lbl_805B64A8 (fn_80075D80)--> S (0-55)
S --lbl_805B6888 / lbl_805B6968 / lbl_805B6A48 (fn_80076058, kind 0 / 1 / 2)--> variant v (0-86)
v --lbl_8061C728[v] (fn_8018466C)--> "stadium\<name>.big"   (fn_802B5794, 0x802B5794; suffix .big at 0x805E03D0)
v --lbl_8061A5AC[v]--> frontend/stadiums.big/<code>.gsh ;  v + 87 --> frontend/fields.big/<code>.gsh
S --lbl_805C38B0--> park name (LOC) ;  S --lbl_805B1634--> park-name clip number
```

* `fn_80075D48`/`fn_80075D80` (src/game/tu_80073914.cpp): `S = lbl_805B64A8[tid]` when it is `>= 0`, else 0. A second tid
  table `lbl_805B6698` (also 124 ints) is all `-1` in the shipped data and so unused. Reverse lookups: `fn_80075E7C` (variant
  to `S`), `fn_80075F1C`, `fn_80076104`.
* The three variant tables have 56 entries (one per `S`). For a given `S` kind 0 or kind 1 holds the day variant (never both),
  kind 2 the night variant; `-1` means none. `fn_80076058` (0x80076058) returns the asked kind, else tries kind 1, then 2,
  then 0. So a dome or a classic park (day only) or a minor-league night park is returned for every kind.
* Exhibition: `fn_800D9B24` (0x800D9B24) computes `fn_80076058(fn_80075D80(fn_800B5520(homeKey)), kind)`; `kind =
  (rand % 1800) / 600` (`fn_800DA1AC`, 0x800DA1AC) is 0, 1 or 2 with equal chance when the time of day is random. Because of the
  fallback order a typical park (day in kind 0, night in kind 2) then plays at night 2 times in 3; a park whose day variant
  is in kind 1 and that also has a night variant (Bos, Atl) plays by day 2 times in 3, and a park with one variant always
  gets it. A random park is chosen instead when the ini flag at
  0x805BD790 is set (`fn_800D9A64`). The user's own choice of park skips the table [I].
* All-Star host: `lbl_805B6428` (32 ints), `fn_80075CC0` (0x80075CC0), index `(year - 2005) % 32` gives an `S`.
* Park pictures: `fn_8013E240` (0x8013E240, front end) reads `lbl_8061A5AC[v]`; `stadiums.big` has 93 entries, one image
  each (1024x256, 4 bits per pixel); `fields.big` icons are 128x128. The `fields.big` names are `lbl_8061A5AC[87 + v]` [I].

Home parks, from the data tables (rows are `team.dat` rows; file names are `stadium/<name>.big`):

| row | `unique_team` | tid | `S` | park files | `stadiums.big` | name clip |
|---:|---|---:|---:|---|---|---:|
| 0 | Ana | 0 | 1 | anahday / anahnite | ana / anan | 01 |
| 1 | Oak | 19 | 15 | netwday / netwnite | oak / oakn | 02 |
| 2 | Sea | 24 | 21 | safeday / safenite | sea / sean | 03 |
| 3 | Tex | 27 | 0 | arliday / arlinite | tex / texn | 04 |
| 4 | CWS | 6 | 27 | usceday / uscenite | cws / cwsn | 05 |
| 5 | Cle | 8 | 11 | jacoday / jaconite | cle / clen | 06 |
| 6 | Det | 10 | 5 | comeday / comenite | det / detn | 07 |
| 7 | KC | 13 | 12 | kaufday / kaufnite | kc / kcn | 08 |
| 8 | Min | 16 | 10 | metrdome | min | 09 |
| 9 | Bal | 3 | 16 | orioday / orionite | bal / baln | 10 |
| 10 | Bos | 4 | 8 | fenwday / fenwnite | bos / bosn | 11 |
| 11 | NYY | 18 | 29 | yankday / yanknite | nyy / nyyn | 12 |
| 12 | TB | 26 | 25 | tropdome | tb | 13 |
| 13 | Tor | 28 | 24 | skydday / skydnite | tor / torn | 14 |
| 14 | Ari | 1 | 2 | bankday / banknite | ari / arin | 15 |
| 15 | Col | 9 | 6 | coorday / coornite | col / coln | 16 |
| 16 | LA | 14 | 7 | dodgday / dodgnite | la / lan | 17 |
| 17 | SD | 22 | 17 | petoday / petonite | sd / sdn | 18 |
| 18 | SF | 23 | 22 | sbcpday / sbcpnite | sf / sfn | 19 |
| 19 | ChC | 5 | 28 | wrigday / wrignite | chc / chcn | 20 |
| 20 | Cin | 7 | 9 | gabaday / gabanite | cin / cinn | 21 |
| 21 | Hou | 12 | 14 | minuday / minunite | hou / houn | 22 |
| 22 | Mil | 15 | 13 | millday / millnite | mil / miln | 23 |
| 23 | Pit | 21 | 18 | pncpday / pncpnite | pit / pitn | 24 |
| 24 | StL | 25 | 3 | bushday / bushnite | stl / stln | 25 |
| 25 | Atl | 2 | 26 | turnday / turnnite | atl / atln | 26 |
| 26 | Fla | 11 | 19 | propday / propnite | fla / flan | 27 |
| 27 | Was | 29 | 20 | rfksday / rfksnite | rfk / rfkn | 44 |
| 28 | NYM | 17 | 23 | sheaday / sheanite | nym / nymn | 29 |
| 29 | Phi | 20 | 4 | citiday / citinite | cit / citn | 30 |
| 30, 31 | AL, NL | 30, 31 | 5 | comeday / comenite (Det's park) | det / detn | 07 |

Other `S` values [V]:

| Rows | `S` | Park files | Shared by |
|---|---|---|---|
| 32-61 (AAA) | 46, 47, 48 | `aaa1nite`, `aaa2nite`, `aaa3nite` (night only) | 10 teams each |
| 62-91 (AA) | 49, 50, 51 | `aa01nite`, `aa02nite`, `aa03nite` (night only) | 10 teams each |
| 92-121 (A) | 52, 53, 54 | `a001day`, `a002day`, `a003day` (day only) | 10 teams each |
| 122 (Legends), 123 (Heroes) | 29, 7 | Yankee and Dodger files above | the NYY and LA parks |
| none | 30-45 | classic parks: `astrdome`, `cineday`, `clevday`, `crosday`, `fencday`, `forbday`, `grifday`, `hiranite`, `metpnite`, `olymdome`, `poloday`, `qualnite`, `shibday`, `spotday`, `tigrnite`, `veteday` | stadium choice only |
| none | 55 | `venuday`, `venunite` (the create-a-park slot) | stadium choice only |

What a park consists of (names only) [V]:

| Part | Files |
|---|---|
| `stadium/<name>.big` (93 entries, RefPack) | model pairs `.ord`/`.orl`: `sky0`-`sky4`, `mfield0`-`mfield2`, `mstadium`, `crowd`, `net`, `jumbo`, `mshadow`, `alphablend`, `remcrowd0`-`remcrowd5`, `3dcrowd`, `3dflag`...; textures `cram.gsh` (about 0.8 MB), `field0`-`field2`, `crowd0`-`crowd2`, `sky0`-`sky4`; 83-byte placeholder images `back0`-`back2`, `clay`, `dert`, `brik`, `logo0`-`logo2`; data `stadium.ifo`, `wall.dat`, `shadow.dat`, `coll.dat`, `crowd.dat`, `tanim.csv`, `ganim.csv`, `flags.csv`, `remap.ifo`, `render.ifo` |
| `datafile/datafile.big/<name>.txt` | per-park tuning text (cameras and fly-ins; EA datafile records, `GAME_DATA.md` section 1), same stem as the park file |
| `stadium/lighting.csv` (1,470 bytes) | 87 rows `<name>,<lighting preset>`; the preset is a `datafile.big` text such as `04day`. Loaded by `fn_802ACF58` (0x802ACF58) and parsed by `fn_802ACE20` |
| `database/progress.big/stadium.csv` | park factors by `unique_team` for the 30 clubs (section 4.5) |

Override: park contents, pictures and name clips can be replaced by file. Which park a team plays in cannot: the tables
`lbl_805B64A8`, `lbl_805B6888`, `lbl_805B6968`, `lbl_805B6A48` (`.rodata`) and `lbl_8061C728`, `lbl_8061A5AC` (`.data`) are in
`main.dol`. For MLB slots (one park per club) a team pack just replaces its park's files. For minor-league slots the park
is shared by 10 clubs, so replacing the files changes all 10 unless the engine patches `lbl_805B64A8`.
The placeholder `logo0`-`logo2` entries in a park suggest that the home logo is applied at run time [I, open].

### 12.8 Announcer and other audio

| Item | Detail | Tag |
|---|---|---|
| Team-name clip, play by play | `audio/spch_pbp/tnamedat.big` entry `NN.dat` and `audio/spch_pbp/tnamehdr.big` entry `NN.hdr`, `NN` = `team_artid` printed with `%02d` (0x805AE398; 3 digits above 99). 124 entries, `01`-`124`: every row 0-123, none for Burnaby. Opened by `Unk800642F0::fn_80064AB0` (0x80064AB0) for the home and the away team, with `NN` from `fn_8009E1D4(teamRecord, 2, 0)` | V |
| Team-name clip, public address | `audio/spch_pa/tnamedat.big` / `tnamehdr.big`, same `NN`. 91 entries: `01`-`92` without `28` (Was). `fn_80064BFC` (0x80064BFC) | V |
| Missing clip | `fn_8006473C` (0x8006473C) appends `.hdr`, tests that the entry exists and only then opens `NN.dat`; when it is missing the clip is simply not added (silence). Rows 92-121 and 122, 123 have no PA clip; Was has none | V, I effect |
| Format | `NN.dat` is an EA `SCHl` audio stream (first bytes `SCHl`, platform header); payload alignment in these archives is 128 bytes, not 4 (the archives that `big.py` cannot rebuild exactly, section 2.1). `NN.hdr` is 28-148 bytes: PBP files start `4A 9A`, PA files `20 11`, then `NN` as a big-endian 16-bit number (true of all 215 files), then (offset, id) pairs, probably the cut points of the words of the name | V layout, I meaning |
| Park-name clip | `stdnmdat.big`/`stdnmhdr.big`, 94 entries `NNa`, `NNb` (format `%02da`, 0x805AE3A0): `fn_80064D48` (0x80064D48) with `NN = lbl_805B1634[S]` (56 ints). the 29 older MLB parks use their club's `team_artid` (01-30), RFK (Was) uses 44, classic parks use 28 (Olympic), 31-43, classic Fenway reuses 11; `S = 55` (the create-a-park slot) takes `NN` from `lbl_805A928C` (16 values, 101-116); the minor-league parks, Cleveland Municipal and Veterans give 0 and so no clip | V |
| Park sound effects | `audio/stadium/std_spec.txt` (`stadiums:NN`) and `audio/hmrn_sfx/hrnsfx.txt` (`teamspecific:NN`) use the same `NN` (03 train, 19 fog horn and cable car, 29 aircraft) | I |
| Crowd | `audio/crowddb/audiocsv.big/chants.csv` has rows for `HOME_TEAM_ANA_RALLY_MONKEY_*`, `HOME_TEAM_ATL_TOMAHAWK`, `ROAD_TEAM_ANTI_LA_*`, `ROAD_TEAM_ANTI_ARI_*`; the event names are strings in the DOL (0x805A7134-0x805A72A4). They follow the team code, not the row; the selection code was not traced | I |
| Not per team | walk-up music (`attrib.ditty`, `rally/dtty_org.txt`), player-name clips (`audioid`), the other crowd CSVs | V |

### 12.9 What is in `main.dol`, and the other kinds

* **Load screens.** `frontend/load0.big`-`load48.big`, 49 files, each holding one entry `load<N>.gsh` (a 1024x512 4-bit image).
  `fn_8032222C` (0x8032222C) formats `frontend/load%d.big` (0x805EA8D8) and `load%d.%s` (0x805EA8EC) for a number N from
  `fn_80322290` (0x80322290: 0-7, starts at `rand % 8`, then +1 and wraps) or `fn_8032234C` (0x8032234C: 8-48, starts at
  `8 + rand % 41`, then +1 and wraps). Two sets, 8 + 41 = 49. The first set is used by `fn_80315FFC` (0x80315FFC) from
  `fn_801498C0` (0x801498C0), at the start of a game, the second by `fn_8031618C` (0x8031618C) from `fn_80149DD4`
  (0x80149DD4), when a game ends [I for the two moments]. No team, row or stadium goes into the choice. [V] A pack cannot give
  a team its own load screen without changing code; it can replace screens for everybody.
* **Backgrounds.** `frontend/bkgnds.big` entries `NN` + a two-letter code are per screen, not per team [I].
* **Mascots, walk-up music.** Nothing per team was found except the crowd rows above.
* **Tables in `main.dol` that a team pack cannot change by file:** `lbl_80619D34` (tid list), `lbl_805C36C0`, `lbl_805C2F00`,
  `lbl_805C30F0`, `lbl_805C32E0`, `lbl_805C34D0` (row and LOC ids), `lbl_805B64A8`, `lbl_805B6698` (home park), `lbl_805B6888`,
  `lbl_805B6968`, `lbl_805B6A48`, `lbl_805B6428` (All-Star hosts), `lbl_805C38B0`, `lbl_805B1634`, `lbl_805A928C` (park name and
  clip), `lbl_8061C728`, `lbl_8061A5AC` (park file and picture names), `lbl_805B6B98` (uniform letters). If a pack ever needs a
  different park for a slot, a different tid string, or a 17th uniform letter, the engine patches these words after load.

### 12.10 Slots that lack assets, and the fallbacks

| Rows | Logos | Uniform letters (front end / game) | Name clip PBP / PA | Park | LOC and `team.dat` |
|---|---|---|---|---|---|
| 0-29 MLB | yes | `a`, `b` and up to 10 more (12 letters at most) / the same | 01-30 / 01-30 without 28 | own park | yes |
| 30, 31 AL, NL All-Stars | yes | `a` only / `a` only | 31, 32 / 31, 32 | `S` 5 (Det's park), host by year in the season code | yes |
| 32-61 AAA | yes | `a`, `b` / `a`, `b` | 33-62 / 33-62 | shared, night only | yes |
| 62-91 AA | yes | `a`, `b` / `a`, `b` | 63-92 / 63-92 | shared, night only | yes |
| 92-121 A | yes | `a`, `b` / `a`, `b` | 93-122 / none | shared, day only | yes |
| 122, 123 Legends, Heroes | yes | `a` only / `a` only | 123, 124 / none | NYY and LA parks | yes (the LOC city text differs from `team_location`) |
| 124, 125 Burnaby | `l124`, `l125` (and the 995/996 copies) | none / `a` only | none / none | none | no LOC ids, no tid |

Fallbacks seen in the code [V unless marked]:
* A key that is not in the tid list becomes tid 0, so a Burnaby team shows Anaheim's front-end logo, uniforms and park.
* A missing uniform letter becomes `a` (in game). If `a` is missing too, the texture pointers stay 0 [I: nothing is drawn or
  the default texture shows].
* No team: logo set `999`, `umpire.gsh`/`umpirec.gsh`, `uniform.gsh`, `teamfont.gsh` in `models.big` [I for the last two].
* A missing announcer clip is skipped (silence).
* A variant that does not exist for the asked time of day: the other one (12.7). A tid with a negative `lbl_805B64A8` entry
  gets `S = 0` (the Texas park); no shipped row does.

### 12.11 What a team pack must provide

For a slot with `team.dat` row `r` (0-123), `team_artid = r + 1`, code `U`, tid `t`:

1. **Keep:** `unique_team = U`, `team_artid`, the row position, `team_league`/`team_division` (unless the schedules change).
2. **`team.dat` strings:** `team_location`, `team_long_name`, `team_short_name`.
3. **LOC strings** in both `FEENG.LOC` and `IGENG.LOC` for the ids `lbl_805C2F00[t]` (full name), `lbl_805C30F0[t]` (nickname),
   `lbl_805C32E0[t]` (abbreviation), and in `FEENG.LOC` `lbl_805C34D0[t]` (city). E7 reads these tables from the player's own
   `main.dol` (addresses in 12.6) instead of shipping them.
4. **Logo container:** `l<r>.gsh` in `frontend/logos.big` and `a<r>.gsh` in `frontend/logos_a.big`, both SHPG with the 7 images
   `l j i g e d a` + number at the sizes of 12.4. This also carries the team colours.
5. **Uniforms:** in `frontend/uniforms.big` the container `<r>.gsh` and a stub `<r>a.gsh`, `<r>b.gsh`; in `models.big`
   `u<r>a.gsh`, `u<r>b.gsh`, `f<r>a.gsh`, `f<r>b.gsh` (jersey sheet with the 28 parts, glyph sheet with `zig0-9` and
   `A___`-`Z___`). Optional: more letters, and `a<r><x>.gsh`.
6. **Announcer:** `NN.dat` and `NN.hdr` (`NN = r + 1`) in `audio/spch_pbp/tnamedat.big` / `tnamehdr.big`, as EA `SCHl` streams
   with the `4A 9A` header (12.8); optional PA clip for `r + 1 <= 92`. Without it the slot is silent (or says the old name if the
   old clip stays).
7. **Roster, depth chart, manager, org rows** (section 8).
8. **Optional park:** the files of the slot's park (12.7: `stadium/<name>.big`, `datafile.big/<name>.txt`, `stadiums.big`
   and `fields.big` pictures, the LOC park-name id, the `NNa`/`NNb` clip). MLB slots own their park; minor-league parks are
   shared.
9. **Not needed:** a load screen, colour data, Cooperstown art, `coop*.big`.

Rules for the validator: rows 124, 125 are not slots; one entry per name; entry names are matched without case; every
image in 4 and 5 keeps the container's image names; `a` must exist for every letter that is offered, because `a` is the
fallback; do not reorder `team.dat` rows (the in-game logo reads `team_artid`, the front end reads the static row).

### 12.12 Open questions left

1. Default uniform letters of a new game (home `a`, away `b`) and the unlock logic behind the strings
   `UNLOCKABLE_JERSEYS`/`UNLOCKABLE_STADIUMS`: which letters are locked for which rows.
2. Pixel formats and size limits the GSH loader enforces on authored images (palette size, mip levels), and whether the
   `fn_802B9FF0` join of `l` and `a` logos needs identical layouts. Only sizes were checked.
3. The meaning of the `.hdr` pairs of a name clip, and a tool that writes `SCHl` GameCube streams: needed to make new
   name clips. A slot may keep a silent or old clip until then.
4. Whether the `logo0`-`logo2`, `back0`-`back2`, `clay`, `dert`, `brik` placeholders in a park are replaced at run time (home
   logo, field art) and from where.
5. Use of the logo sets `994`, `997`, `998`, the copies `995`/`996`, and the letters `s`, `x` in `uniforms.big`.
6. Which code selects the team crowd events (`chants.csv` rows) and whether they are tied to the team code or the park.
7. The ordering tables in `fn_800E1ADC` (0x800E1ADC; `lbl_805C3990`, `lbl_805C3A10`, `lbl_805C3A88`, `lbl_805C3B00`,
   `lbl_805C3B78`): row permutations by level, probably the team-select display order; not decoded.
8. Whether a user's own park choice (stadium list in the team screens) reads the same tables or lists all 87 variants.
9. Which in-game widgets (scoreboard, overlays) fetch logos by the static row and which by `team_artid`; they agree on a
   shipped disc, so nothing breaks as long as a pack keeps `team_artid = row + 1`.

### 12.13 Reproduce

Git Bash, `export MSYS_NO_PATHCONV=1`; `<disc>` is the player's image. Nothing is written into the repository.

```
python -I tools/rosters/big.py list "<disc>:/data/frontend/logos.big"
python -I tools/rosters/big.py list "<disc>:/data/frontend/uniforms.big"
python -I tools/rosters/big.py list "<disc>:/data/models.big"
python -I tools/rosters/big.py list "<disc>:/data/audio/spch_pbp/tnamedat.big"
python -I tools/rosters/loc.py dump FEENG.LOC --grep Angels          # after extracting with big.py / gcdisc.py
python tools/match/asm_show.py "$B/asm" show fn_800B5414             # $B = build/<...>/GV4E69
python tools/match/asm_show.py "$B/asm" show fn_80076058
```

The table values quoted above come from reading the words at the `lbl_` addresses in `main.dol` (the DOL extracted from the
disc with `tools/recon/gcdisc.py`); the pointer arrays resolve to the strings named in the tables.
