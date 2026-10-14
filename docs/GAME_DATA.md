# Game data: what the code reads, and in what format

What is known about MVP Baseball 2005's data from outside the code: EA's
datafile format, the database tables and their enums, schedules and standings,
and the archive formats. Gathered 2026-10-13 from the owner's reference
material (docs/REFERENCE_SOURCES.md). Use it to name struct fields, enum
constants and functions. It verifies nothing; objdiff and the verifier do.

No game data is in this repo: only names, layouts and formats.

## 1. EA "datafile" records (tuning data)

The game's tuning values live in EA datafile records. Each text record starts
with a 32-bit hash:

- **Schema record:** `0x<hash> <field count> <n>;<index> <FieldName>;...`
  It maps field indices to names, e.g. the pitching-control class
  `0x0D7C089C`: `ControlXScale%`, `ControlYScale%`, `PitchAfterTouchSize`,
  `PitchCrossHair`, `BattingBoxSize`, `MinAnalogMovement`, `PitchSpeedFactor`.
- **Instance record:** `0x<hash> <field count><<name>>;<index> <value>;...`
  It is a named object with one value per field, e.g. `<baseball>`,
  `<ThrowStrength>`, camera shots, animation entries.

The code builds class hashes with `lis rX,hi` + `ori/addi rX,rX,lo`. Of the 131
classes in MVP Baseball 2004's GameCube data files, **110 appear in MVP 2005's
code, in 261 functions** (14 of them unmatched, 15.7 KB, on 2026-10-13). Their
schemas, with field names only, are in `config/GV4E69/datafile_schemas.tsv`.

- `python tools/match/datafile.py <fn>` lists the classes a function builds
  hashes for, with their fields. `--schema 0x...` shows one class and its
  users; `--stats` shows coverage.
- `twins.py show` prints them too ("reads datafile class ...").
- A field index loaded next to the hash usually names the value read. The
  schemas come from the 2004 game, so 2005 may have added fields at the end.

Examples:

| Class | Fields (abridged) | Read by |
|---|---|---|
| `0x6D896082` | game impact / momentum: `PlayoffImpact`, `RivalGameImpact`, `FacingElimination`, `ClinchingGame`, `LosePlayPCTEffectOnMomentum`, ... (54) | `fn_800D697C`, `fn_800D6FA0`, `fn_801446B8` |
| `0x971949A6` | catch types: `Type_StJmpDvClmb`, `Difficulty`, `Direction`, `CatchSpread`, `Juggle`, `BackHand`, `BareHand`, `OverShoulder` | 8 fielding functions incl. `cCatchBall`'s ctor, `fn_802762A0`, `cFudgePosRotWarp` |
| `0x2F71A764` | `ThrowStrengthMPH`, `temp`, `Difficulty` | `fn_802FA22C` |
| `0x440397DE` | `TagDirection`, `TagSpread` | `fn_80276808` |
| `0x8CA866F4` | front-end screen: `x`, `y`, `isminimized`, `isgamestate`, `gamestate`, `fullname`, `translist`, `filename`, `layoutname`, `assettype` | `fn_800AA1A8`, `fn_800AA67C`, `fn_800AAF1C`, `fn_80144604` |
| `0x6A8513FF` | front-end transition: `Conditions_For_Transition`, `ControlName`, `PreviousFlow`, `ActionList`, `ChangeSoundFX`, `ChangeMovie`, `SetGameMode`, `To`, ... (16) | `fn_800AAA8C`, `fn_800AABA4`, `fn_80144B88` |

`feflow.txt` (front-end flow) names every front-end screen as
`<module>.<Screen>`, with its layout file and transitions, e.g.
`fe_foffseason.FReSignContract` (`fes_fplayercontract.fel`),
`fe_tresults.TChamps`, `fe_fsimgame.FTeamSelect2`. The prefixes are probably
`F` for franchise/dynasty and `T` for tournament. `igflow.txt` does the same for in-game flow. Per-stadium
records come in day and night files named by a 4-letter code: `fenwday`,
`fenwnite`, `metrdome`, `olymdome` and so on.

## 2. Database tables (rosters, dynasty)

Table files (`data/database/*.dat` on PC; the same tables are in memory on every
platform): `attrib`, `lhattrib`, `rhattrib`, `pitcher`, `roster`, `bstats`,
`lhbstats`, `rhbstats`, `fbstats` (plus `fbstatsAAA/AA/A`), `career`, `pstats`,
`rhpstats`, `lhpstats`, `careerp`, `team`, `tstat`, `cy-*` (current-year copies),
`manager`, `org`, `hist`, `histdata`, `histindex`. The database code is in
`src/db/` (the database overlay).

Player record, as the PC tools see it in memory (`attrib`, packed bit fields;
bit order differs on big-endian PowerPC, but the fields and widths are the same):

| Field | Range / meaning |
|---|---|
| energy | 0-100 |
| contract type | 0-35 (table below) |
| injury type | 0-49; 0 none, 49 suspended |
| injury time | days until healed, 0-255 |
| disabled list slot | -1 none, else 0-503: 4 per team (2 × 15-day, 2 × 60-day); Angels are 0-3 |
| day put on DL | -1 none; day 1 = 1 January 1948 (16-bit) |
| unknown (happiness) | two fields, 0-15 and 0-31 |
| pitcher current stamina | 0-100 |

About 3,250 players exist in a default database. Generated (created) players
use bone profile 25.

**Contract types (0-35):** for each level MLB, AAA, AA, A in turn (5 per level),
pitchers are Ace, Starter, Spot Starter, Closer, Relief (0-19). Position players
follow (20-35), 4 per level: Indispensable, Everyday, Situational, Backup.
So 0 = MLB Ace, 5 = AAA Ace, 20 = MLB Indispensable, 35 = A Backup.

**Injury types (0-49):** 0 none, 1 pulled hamstring, 2 pulled groin, 3 sprained
ankle, 4/5 strained left/right forearm, 6 strained lower back, 7/8 strained
left/right ribcage, 9/10 inflamed left/right shoulder, 11/12 inflamed left/right
elbow, 13 finger blister, 14 dislocated finger, 15 sprained wrist, 16 shin
splints, 17 minor ACL, 18 minor PCL, 19 minor MCL, 20 minor wrist tendonitis,
21 minor meniscus, 22 minor concussion, 23 bruised ankle, 24 fractured nose,
25/26 torn left/right shoulder muscle, 27/28 strained right/left hip flexor,
29 major wrist tendonitis, 30 elbow tendonitis, 31 knee tendonitis, 32 Achilles
tendonitis, 33/34 fractured right/left knee, 35 fractured toe, 36 fractured
finger, 37 fractured ankle, 38 hernia, 39 concussion, 40 fractured hand,
41 torn rotator cuff, 42 fractured leg, 43 fractured arm, 44 separated
shoulder, 45 torn ACL, 46 torn MCL, 47 torn PCL, 48 torn knee meniscus,
49 suspended.

**Other player fields and their values** (labels from the MVP2005 Editor):
- **Positions:** SP, C, 1B, 2B, 3B, SS, LF, CF, RF, DH, RP, OF, IF, UT. Each player has a primary and a secondary position.
- **Bats / throws:** R, L, S.
- **Batting stance:** Generic, Bent, Crouched, Upright, Open, High, Closed, then 56 named star stances (Ichiro, Alou, Bagwell, ..., Williams) and Classic 1-3.
- **Swing type:** 2 hands, 1 hand.
- **Ditty (walk-up music):** Country, Dance, Hip Hop, Pop, Rock, Hv. Rock, Latin.
- **Bone profile:** 0-63. 25-37 are named: Athletic(Created), Slim, Slim Big Chest, Athletic, Athletic Big Legs, Athletic Big Chest, Stocky, Stocky Big Chest, Stocky Big Legs, Plump Big Legs, Plump Big Chest, Plump, Heavy.
- **Body type:** Small, Average, Large.
- **Skin tone:** 1-16.
- **Hair style:** None, Mullet, Long Hair, Normal, Sideburns, Slick, Slick + Sideburns, Short Hair, Short Hair + Sideburns, Cornrolls.
- **Hair color:** Black, Blonde, Dk Blonde, Red, Brown, Dk Brown, Gray.
- **Facial hair:** None, Beard, Mustache, Mustache Long, Mustache No Ridge, Full Goatee, Goatee, Barbiche.
- **Bat color:** Light Brown, Dark Brown, Red, Black, Light/Black, Dark/Black, Red/Black, Dark/Red.
- **Glove color:** Light Brown, Brown, Black, Blue, Red, Custom 1, Custom 2.
- **Equipment:** catcher's mask (Normal, Hockey); batting gloves (No, Yes); wristband (None, Large Left, Large Right, Large Both, Normal Left, Normal Right, Normal Both); elbow guard (None, Black Plastic, Black Pad, White Plastic); shin guard (None, Black, White); socks (Normal, High, Low).
- **Other:** birthday; star power (1-5 stars, Hidden, Top Prospect); photo type (2 = generic cyberface 901-915); jersey; face; 2004 face.

Batting spray RF = 100 - LF - CF, and the HR share = 100 - Fly - Ground - Liner
(the editor derives them).

## 3. Teams, standings, schedules

- **Team index order (30):** ANA, OAK, SEA, TEX, CWS, CLE, DET, KC, MIN, BAL, BOS,
  NYY, TB, TOR, ARI, COL, LAD, SD, SF, CHC, CIN, HOU, MIL, PIT, STL, ATL, FLA,
  WAS, NYM, PHI. Free agents sit on four extra teams: MVP Legends, MVP Heroes,
  Burnaby Chimaera, Burnaby Argonauts.
- **Standings in memory:** 30 records × 4 bytes. Either `[W][L][0][0]`, or
  `[W1][L1][W2][L2]` split by season half (u8 each). Found by scanning RAM on
  GameCube (Dolphin) and Xbox; the address is heap-dependent.
- **Season lengths:** MLB 162, AAA 144, AA 140, A 140.
- **Schedules:** `mlb162_1.dat`, `mlb162_2.dat`, `mlb162_3.dat` inside
  `schedule.big`, one per dynasty year (year 3 is shifted by two years), plus
  minor-league files (`a140`, `aa140`, ...). They may be EA-compressed. Each
  game carries a half flag: 0 before the trade deadline, 1 after, and the
  All-Star game is marked separately.
- **Dynasty dates:** day 1 = 1 January 1948.

## 4. Archives and textures

- **BIG / VIV archives:** EA's container (`*.big`). Tools: BigGUI, EAZIP
  (nba2kstuff). EAZIP handles the old VIV, BIGVIV (2k3) and BIGVIV4 (2k5)
  variants, with quad-word alignment options.
- **Compression:** EA's RefPack (the "compress/uncompress fsh" in EAZIP;
  `*_compressed.dat` schedules). The game decompresses on load.
- **FSH:** EA's texture container (fshtool, documented in its `fshtool.txt`).
  The PC build uses it for portraits (`frontend/portrait.big`) and models
  (`models.big`). The GameCube build's texture formats are not checked.
- **Save files:** dynasty, owner and roster saves; Xbox saves use `.dat`. The
  MVPSavReader tool parses PS2, PC and Xbox saves (its layouts are inside its
  executable, not documented).

## 5. Emulation notes (for a future PC port)

Dolphin ships one patch for `GV4E69`, "Fix 2D Rendering": the word at
`0x80319214` becomes `0x48113250`, a branch to `0x8042C464` (the GX library
range). It works around broken 2D rendering under emulation, so a port's
renderer may hit the same path.
