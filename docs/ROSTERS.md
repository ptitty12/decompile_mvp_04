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
- **Logos.** `logos.big` / `logos_a.big`: `l###.gsh` / `a###.gsh`, index probably `team_artid - 1`. [I]
- **Uniforms.** `uniforms.big`: `###.gsh` plus lettered variants; the ini names home `a`, away `b`. `coopunis.big`
  has the co-op menu thumbnails `c001`-`c122`. [I]
- **Load screens.** `load0..load48.big`; which team uses which screen is not mapped. [open]
- **Stadiums.** Each team's stadium is not a column in `team.dat` (`team_artid`, `climatezone` and
  `homeintensity` only). The 4-letter stadium codes (`anahday`/`anahnite`, `fenwday`, `metrdome`...) appear
  in `/data/stadium/` and in the front end; the team-to-stadium table has not been located. [open]
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
4. Assets by index: logo `l###`/`a###`, uniforms `###*`, load screen, `stadiums.big` picture, announcer clips.
5. If `unique_team` must change: also every schedule CSV in `schedule.big`, `stadium.csv` in
   `progress.big`, and the keys (`team`, `tstat`, `org` rows and `roster_teamid`, `org_team_*`).
   Avoid it.
6. A club in a minor-league slot needs only the `team`, `tstat`, `roster` rows and assets.

### More than 126 teams

Needs code hooks: the capacity immediates in 6.1 (`li r4/r6, 0x7E` in `Tbl8009101C::v5`), the stadium factor
table (6.2), the unread 126-element structures, and 127+ assets in every table of 6.3. Not recommended
before the K2 inventory of 6.2 is finished.

## 9. Proposed names

None of these is applied. Evidence is the string argument, the callers or the matched source.

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

## 10. Open questions

1. **Slot-to-asset mapping.** How `team_artid`/team index select the logo, uniform set, load screen,
   stadium and announcer clip, and which table assigns a stadium to a team (section 7). Needed by E7.
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
