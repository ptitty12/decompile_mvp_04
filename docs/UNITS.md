# Units (provisional): GV4E69

There is no symbol map, so **translation-unit boundaries are not known yet**. This is
the first-pass anchor list the unit issues will be created from (one issue per unit,
labels `sdk|game`, `size:S|M|L`, `subsystem:<name>`) once the owner OKs creating
GitHub issues. Regenerate the table with:

```bash
python -I tools/recon/units.py build/GV4E69/orig/main_sections.dol config/GV4E69/symbols.txt build/units.json build/units_table.md
```

## Anchors found (2026-10-10)

| Kind | Count | What it gives |
|---|---|---|
| `sdk` | 13 | The Dolphin SDK library, via its `<< Dolphin SDK - X >>` version string and the init function that registers it |
| `ctor` | 87 | One game/EA TU each. GCC emits the TU's `_GLOBAL_.I.<file>` static initializer at the **end** of the TU's `.text`, so each one marks a TU end |
| `dtor` | 15 | `_GLOBAL_.D.<file>` static destructors (subset of the ctor TUs) |
| `srcpath` | 23 | A named TU, via an assert/`__FILE__` string (`C:/mvp2004/source/...`) and the functions referencing it |

Already identified outside this table: crt0 (`.init`, 0x80003100–0x8000348C, SN-style);
`libgcc/_main.c` = `__do_global_ctors` 0x80413878 + `__main` 0x80413908 (100% matched as a probe, not committed);
newlib-derived libc around 0x80406000–0x80414000.

## Proposed order (Phase 2a then 2b)

1. **Runtime, to lock in the ProDG flags:** `libgcc/_main.c` (2 functions; the probe matched with
   ProDG 3.9.3 `-O2 -G0`), then other libgcc helpers next to it.
2. **Small SDK libraries, to lock in MWCC version and flags:** AI (≈0x670 between anchors), ARQ (≈0x2D8),
   PAD, SI, DSP, VI, then OS (the probe matched with GC/1.2.5n `-O4,p -opt nopeephole`), EXI, AR, DVD, CARD, AX, GX.
   *Caveat:* some SDK functions are hand-written assembly in Nintendo's sources (e.g. PPCArch accessors,
   OSContext). CLAUDE.md forbids asm, so those stay as split assembly (see the DECISIONS open question).
3. **Small named game TUs:** `ai/scenes/scene.cpp`, `animation/goals/catchgoal.cpp`, `reachgoal.cpp`,
   `animation/choosers/playeridchooser.cpp`, `ai/bench/benchai.cpp`. They're small, named, and teach the
   class layouts.
4. **Game logic outward** per `docs/PHASES.md` (sim/ratings/franchise in the two overlays; batting/pitching
   physics around 0x8018B000–0x802F0000).

Sizes: the SDK spans between consecutive anchors are rough upper bounds (anchors are init
functions, not library starts). Game TU sizes are unknown until boundaries are set.

## Anchor table

"Unit" is provisional. For `ctor`/`dtor` rows it lists any source-path names whose code falls
between the previous TU end and this one, as candidates only.

| # | Kind | Address | Region | Unit (provisional) | Evidence |
|---|---|---|---|---|---|
| 1 | ctor | 0x80004284 | game .text | unknown TU | ctor entry @0x805A2BC4 -> `fn_80004284` (TU ends ~0x800042B0) |
| 2 | ctor | 0x800057AC | game .text | unknown TU | ctor entry @0x805A2BC8 -> `fn_800057AC` (TU ends ~0x800057D8) |
| 3 | ctor | 0x80008514 | game .text | unknown TU | ctor entry @0x805A2BCC -> `fn_80008514` (TU ends ~0x80008540) |
| 4 | ctor | 0x8000C298 | game .text | unknown TU | ctor entry @0x805A2BD0 -> `fn_8000C298` (TU ends ~0x8000C2C4) |
| 5 | ctor | 0x8000D624 | game .text | unknown TU | ctor entry @0x805A2BD4 -> `fn_8000D624` (TU ends ~0x8000D650) |
| 6 | ctor | 0x8000E5EC | game .text | unknown TU | ctor entry @0x805A2BD8 -> `fn_8000E5EC` (TU ends ~0x8000E618) |
| 7 | ctor | 0x8000F56C | game .text | unknown TU | ctor entry @0x805A2BDC -> `fn_8000F56C` (TU ends ~0x8000F598) |
| 8 | ctor | 0x80069000 | game .text | unknown TU | ctor entry @0x805A2BE0 -> `fn_80069000` (TU ends ~0x8006902C) |
| 9 | ctor | 0x80069EE0 | game .text | unknown TU | ctor entry @0x805A2BE4 -> `fn_80069EE0` (TU ends ~0x80069F0C) |
| 10 | srcpath | 0x8006C088 | game .text | source/common/database/ingamedata/backend.cpp | source path string; refs 0x8006C088-0x8006C17C |
| 11 | ctor | 0x800A88B8 | game .text | source/common/database/ingamedata/backend.cpp | ctor entry @0x805A2BE8 -> `fn_800A88B8` (TU ends ~0x800A88E4) |
| 12 | dtor | 0x800A88E4 | game .text | unknown TU | dtor entry @0x805A2D44 -> `fn_800A88E4` (TU ends ~0x800A8910) |
| 13 | ctor | 0x80147E90 | game .text | unknown TU | ctor entry @0x805A2BEC -> `fn_80147E90` (TU ends ~0x80147EBC) |
| 14 | srcpath | 0x8014F05C | game .text | source/gc/exception/ddtrap.cpp | source path string; refs 0x8014F05C-0x8014F34C |
| 15 | ctor | 0x80150DC4 | game .text | source/gc/exception/ddtrap.cpp | ctor entry @0x805A2BF0 -> `fn_80150DC4` (TU ends ~0x80150DF0) |
| 16 | dtor | 0x80150DF0 | game .text | unknown TU | dtor entry @0x805A2D48 -> `fn_80150DF0` (TU ends ~0x80150E1C) |
| 17 | ctor | 0x8016FF14 | game .text | unknown TU | ctor entry @0x805A2BF4 -> `fn_8016FF14` (TU ends ~0x8016FF40) |
| 18 | ctor | 0x801757E4 | game .text | unknown TU | ctor entry @0x805A2BF8 -> `fn_801757E4` (TU ends ~0x80175810) |
| 19 | ctor | 0x801765F4 | game .text | unknown TU | ctor entry @0x805A2BFC -> `fn_801765F4` (TU ends ~0x80176620) |
| 20 | srcpath | 0x80177C74 | game .text | source/common/ai/bullpen/bullpenai.cpp | source path string; refs 0x80177C74-0x80178228 |
| 21 | srcpath | 0x801799AC | game .text | source/common/ai/bench/benchai.cpp | source path string; refs 0x801799AC-0x80179B58 |
| 22 | srcpath | 0x8017CD04 | game .text | source/common/ai/general/aimanager.cpp | source path string; refs 0x8017CD04-0x8017D5F8 |
| 23 | srcpath | 0x80182590 | game .text | source/common/ai/general/stadium.cpp | source path string; refs 0x80182590-0x80182BE0 |
| 24 | srcpath | 0x8018B9D8 | game .text | source/common/ai/physics/ball.cpp | source path string; refs 0x8018B9D8-0x8018E45C |
| 25 | srcpath | 0x8019A5E0 | game .text | source/common/ai/physics/bat.cpp | source path string; refs 0x8019A5E0-0x8019A998 |
| 26 | srcpath | 0x801A0AA8 | game .text | source/common/ai/scenes/scene.cpp | source path string; refs 0x801A0AA8-0x801A0DE0 |
| 27 | srcpath | 0x801AC258 | game .text | source/common/ai/team/defsubstitutionmgr.cpp | source path string; refs 0x801AC258-0x801AC594 |
| 28 | srcpath | 0x801AE5F0 | game .text | source/common/ai/team/offstrategymgr.cpp | source path string; refs 0x801AE5F0-0x801B032C |
| 29 | srcpath | 0x801B5880 | game .text | source/common/ai/team/substitutionmgr.cpp | source path string; refs 0x801B5880-0x801B5A44 |
| 30 | srcpath | 0x801B9A18 | game .text | source/common/ai/umpire/umpireai.cpp | source path string; refs 0x801B9A18-0x801BF66C |
| 31 | ctor | 0x801C195C | game .text | source/common/ai/bench/benchai.cpp, source/common/ai/bullpen/bullpenai.cpp, source/common/ai/general/aimanager.cpp, source/common/ai/general/stadium.cpp | ctor entry @0x805A2C00 -> `fn_801C195C` (TU ends ~0x801C1988) |
| 32 | dtor | 0x801C1988 | game .text | unknown TU | dtor entry @0x805A2D4C -> `fn_801C1988` (TU ends ~0x801C19B4) |
| 33 | ctor | 0x801D9748 | game .text | unknown TU | ctor entry @0x805A2C04 -> `fn_801D9748` (TU ends ~0x801D9774) |
| 34 | ctor | 0x8022E654 | game .text | unknown TU | ctor entry @0x805A2C08 -> `fn_8022E654` (TU ends ~0x8022E680) |
| 35 | ctor | 0x8023BD5C | game .text | unknown TU | ctor entry @0x805A2C0C -> `fn_8023BD5C` (TU ends ~0x8023BD88) |
| 36 | ctor | 0x80256F44 | game .text | unknown TU | ctor entry @0x805A2C10 -> `fn_80256F44` (TU ends ~0x80256F70) |
| 37 | dtor | 0x80256F70 | game .text | unknown TU | dtor entry @0x805A2D50 -> `fn_80256F70` (TU ends ~0x80256F9C) |
| 38 | ctor | 0x8026C630 | game .text | unknown TU | ctor entry @0x805A2C14 -> `fn_8026C630` (TU ends ~0x8026C65C) |
| 39 | srcpath | 0x8027011C | game .text | source/common/animation/choosers/randomchooser.cpp | source path string; refs 0x8027011C-0x80270730 |
| 40 | srcpath | 0x80270D64 | game .text | source/common/animation/choosers/playeridchooser.cpp | source path string; refs 0x80270D64-0x80270EE4 |
| 41 | srcpath | 0x8027985C | game .text | source/common/animation/choosers/randomloadedchooser.cpp | source path string; refs 0x8027985C-0x80279AE4 |
| 42 | srcpath | 0x802816D0 | game .text | source/common/animation/goals/catchgoal.cpp | source path string; refs 0x802816D0-0x802817A0 |
| 43 | srcpath | 0x8028D0EC | game .text | source/common/animation/goals/reachgoal.cpp | source path string; refs 0x8028D0EC-0x8028D200 |
| 44 | srcpath | 0x8029B70C | game .text | source/common/animation/goals/userpickupballgoal.cpp | source path string; refs 0x8029B70C-0x8029C024 |
| 45 | ctor | 0x802ACD88 | game .text | source/common/animation/choosers/playeridchooser.cpp, source/common/animation/choosers/randomchooser.cpp, source/common/animation/choosers/randomloadedchooser.cpp, source/common/animation/goals/catchgoal.cpp | ctor entry @0x805A2C18 -> `fn_802ACD88` (TU ends ~0x802ACDB4) |
| 46 | ctor | 0x802CB7B0 | game .text | unknown TU | ctor entry @0x805A2C1C -> `fn_802CB7B0` (TU ends ~0x802CB7DC) |
| 47 | dtor | 0x802CB7DC | game .text | unknown TU | dtor entry @0x805A2D54 -> `fn_802CB7DC` (TU ends ~0x802CB808) |
| 48 | ctor | 0x802D73BC | game .text | unknown TU | ctor entry @0x805A2C20 -> `fn_802D73BC` (TU ends ~0x802D73E8) |
| 49 | ctor | 0x802DE344 | game .text | unknown TU | ctor entry @0x805A2C24 -> `fn_802DE344` (TU ends ~0x802DE370) |
| 50 | ctor | 0x802F3A90 | game .text | unknown TU | ctor entry @0x805A2C28 -> `fn_802F3A90` (TU ends ~0x802F3ABC) |
| 51 | ctor | 0x80303A6C | game .text | unknown TU | ctor entry @0x805A2C2C -> `fn_80303A6C` (TU ends ~0x80303A98) |
| 52 | dtor | 0x80303A98 | game .text | unknown TU | dtor entry @0x805A2D58 -> `fn_80303A98` (TU ends ~0x80303AC4) |
| 53 | ctor | 0x80323AE4 | game .text | unknown TU | ctor entry @0x805A2C30 -> `fn_80323AE4` (TU ends ~0x80323B10) |
| 54 | dtor | 0x80323B10 | game .text | unknown TU | dtor entry @0x805A2D5C -> `fn_80323B10` (TU ends ~0x80323B3C) |
| 55 | ctor | 0x803249A8 | game .text | unknown TU | ctor entry @0x805A2C34 -> `fn_803249A8` (TU ends ~0x803249D4) |
| 56 | ctor | 0x80328208 | game .text | unknown TU | ctor entry @0x805A2C38 -> `fn_80328208` (TU ends ~0x80328234) |
| 57 | ctor | 0x8034144C | game .text | unknown TU | ctor entry @0x805A2C3C -> `fn_8034144C` (TU ends ~0x80341478) |
| 58 | dtor | 0x80341478 | game .text | unknown TU | dtor entry @0x805A2D60 -> `fn_80341478` (TU ends ~0x803414A4) |
| 59 | ctor | 0x803666C0 | EA libs (probable) | unknown TU | ctor entry @0x805A2C48 -> `fn_803666C0` (TU ends ~0x803666EC) |
| 60 | ctor | 0x80367114 | EA libs (probable) | unknown TU | ctor entry @0x805A2C4C -> `fn_80367114` (TU ends ~0x80367140) |
| 61 | ctor | 0x8036762C | EA libs (probable) | unknown TU | ctor entry @0x805A2C50 -> `fn_8036762C` (TU ends ~0x80367658) |
| 62 | ctor | 0x8036827C | EA libs (probable) | unknown TU | ctor entry @0x805A2C54 -> `fn_8036827C` (TU ends ~0x803682A8) |
| 63 | ctor | 0x80368E38 | EA libs (probable) | unknown TU | ctor entry @0x805A2C58 -> `fn_80368E38` (TU ends ~0x80368E64) |
| 64 | ctor | 0x8036984C | EA libs (probable) | unknown TU | ctor entry @0x805A2C5C -> `fn_8036984C` (TU ends ~0x80369878) |
| 65 | ctor | 0x8036A464 | EA libs (probable) | unknown TU | ctor entry @0x805A2C60 -> `fn_8036A464` (TU ends ~0x8036A490) |
| 66 | ctor | 0x8036AEB8 | EA libs (probable) | unknown TU | ctor entry @0x805A2C64 -> `fn_8036AEB8` (TU ends ~0x8036AEE4) |
| 67 | ctor | 0x8036BEA0 | EA libs (probable) | unknown TU | ctor entry @0x805A2C68 -> `fn_8036BEA0` (TU ends ~0x8036BECC) |
| 68 | ctor | 0x8036CBDC | EA libs (probable) | unknown TU | ctor entry @0x805A2C6C -> `fn_8036CBDC` (TU ends ~0x8036CC08) |
| 69 | ctor | 0x8036D880 | EA libs (probable) | unknown TU | ctor entry @0x805A2C70 -> `fn_8036D880` (TU ends ~0x8036D8AC) |
| 70 | ctor | 0x8036E630 | EA libs (probable) | unknown TU | ctor entry @0x805A2C74 -> `fn_8036E630` (TU ends ~0x8036E65C) |
| 71 | ctor | 0x8036F420 | EA libs (probable) | unknown TU | ctor entry @0x805A2C78 -> `fn_8036F420` (TU ends ~0x8036F44C) |
| 72 | ctor | 0x8036FE74 | EA libs (probable) | unknown TU | ctor entry @0x805A2C7C -> `fn_8036FE74` (TU ends ~0x8036FEA0) |
| 73 | ctor | 0x803708C8 | EA libs (probable) | unknown TU | ctor entry @0x805A2C80 -> `fn_803708C8` (TU ends ~0x803708F4) |
| 74 | ctor | 0x8037131C | EA libs (probable) | unknown TU | ctor entry @0x805A2C84 -> `fn_8037131C` (TU ends ~0x80371348) |
| 75 | ctor | 0x80371D70 | EA libs (probable) | unknown TU | ctor entry @0x805A2C88 -> `fn_80371D70` (TU ends ~0x80371D9C) |
| 76 | ctor | 0x803728BC | EA libs (probable) | unknown TU | ctor entry @0x805A2C8C -> `fn_803728BC` (TU ends ~0x803728E8) |
| 77 | ctor | 0x80372F34 | EA libs (probable) | unknown TU | ctor entry @0x805A2C90 -> `fn_80372F34` (TU ends ~0x80372F60) |
| 78 | ctor | 0x80373AAC | EA libs (probable) | unknown TU | ctor entry @0x805A2C94 -> `fn_80373AAC` (TU ends ~0x80373AD8) |
| 79 | ctor | 0x8037455C | EA libs (probable) | unknown TU | ctor entry @0x805A2C98 -> `fn_8037455C` (TU ends ~0x80374588) |
| 80 | ctor | 0x8037500C | EA libs (probable) | unknown TU | ctor entry @0x805A2C9C -> `fn_8037500C` (TU ends ~0x80375038) |
| 81 | ctor | 0x80375ABC | EA libs (probable) | unknown TU | ctor entry @0x805A2CA0 -> `fn_80375ABC` (TU ends ~0x80375AE8) |
| 82 | ctor | 0x8037656C | EA libs (probable) | unknown TU | ctor entry @0x805A2CA4 -> `fn_8037656C` (TU ends ~0x80376598) |
| 83 | ctor | 0x8037701C | EA libs (probable) | unknown TU | ctor entry @0x805A2CA8 -> `fn_8037701C` (TU ends ~0x80377048) |
| 84 | ctor | 0x8037B380 | EA libs (probable) | unknown TU | ctor entry @0x805A2CAC -> `fn_8037B380` (TU ends ~0x8037B3AC) |
| 85 | srcpath | 0x8037D0E8 | EA libs (probable) | libraries/gamelib/source/animlib/offline/offlinetablemanager.cpp | source path string; refs 0x8037D0E8-0x8037D140 |
| 86 | srcpath | 0x80384C88 | EA libs (probable) | libraries/gamelib/source/animlib/animation/pathlist.cpp | source path string; refs 0x80384C88-0x8038501C |
| 87 | ctor | 0x8038BC00 | EA libs (probable) | libraries/gamelib/source/animlib/animation/pathlist.cpp, libraries/gamelib/source/animlib/offline/offlinetablemanager.cpp | ctor entry @0x805A2CB0 -> `fn_8038BC00` (TU ends ~0x8038BC2C) |
| 88 | dtor | 0x8038BC2C | EA libs (probable) | unknown TU | dtor entry @0x805A2D64 -> `fn_8038BC2C` (TU ends ~0x8038BC58) |
| 89 | ctor | 0x8038EC00 | EA libs (probable) | unknown TU | ctor entry @0x805A2CB4 -> `fn_8038EC00` (TU ends ~0x8038EC2C) |
| 90 | dtor | 0x8038EC2C | EA libs (probable) | unknown TU | dtor entry @0x805A2D68 -> `fn_8038EC2C` (TU ends ~0x8038EC58) |
| 91 | ctor | 0x8038F6E4 | EA libs (probable) | unknown TU | ctor entry @0x805A2CB8 -> `fn_8038F6E4` (TU ends ~0x8038F710) |
| 92 | dtor | 0x8038F710 | EA libs (probable) | unknown TU | dtor entry @0x805A2D6C -> `fn_8038F710` (TU ends ~0x8038F73C) |
| 93 | ctor | 0x803A6D54 | EA libs (probable) | unknown TU | ctor entry @0x805A2CBC -> `fn_803A6D54` (TU ends ~0x803A6D80) |
| 94 | ctor | 0x803A9804 | EA libs (probable) | unknown TU | ctor entry @0x805A2CC0 -> `fn_803A9804` (TU ends ~0x803A9830) |
| 95 | ctor | 0x803BA9B0 | EA libs (probable) | unknown TU | ctor entry @0x805A2CC4 -> `fn_803BA9B0` (TU ends ~0x803BA9DC) |
| 96 | ctor | 0x803BD918 | EA libs (probable) | unknown TU | ctor entry @0x805A2CC8 -> `fn_803BD918` (TU ends ~0x803BD944) |
| 97 | ctor | 0x803D7804 | EA libs (probable) | unknown TU | ctor entry @0x805A2CCC -> `fn_803D7804` (TU ends ~0x803D7830) |
| 98 | ctor | 0x803D7EA8 | EA libs (probable) | unknown TU | ctor entry @0x805A2CD0 -> `fn_803D7EA8` (TU ends ~0x803D7ED4) |
| 99 | ctor | 0x803D8208 | EA libs (probable) | unknown TU | ctor entry @0x805A2CD4 -> `fn_803D8208` (TU ends ~0x803D8234) |
| 100 | ctor | 0x803D9FBC | EA libs (probable) | unknown TU | ctor entry @0x805A2CD8 -> `fn_803D9FBC` (TU ends ~0x803D9FE8) |
| 101 | ctor | 0x803DA15C | EA libs (probable) | unknown TU | ctor entry @0x805A2CDC -> `fn_803DA15C` (TU ends ~0x803DA188) |
| 102 | ctor | 0x803DA4C0 | EA libs (probable) | unknown TU | ctor entry @0x805A2CE0 -> `fn_803DA4C0` (TU ends ~0x803DA4EC) |
| 103 | ctor | 0x803DBFC8 | EA libs (probable) | unknown TU | ctor entry @0x805A2CE4 -> `fn_803DBFC8` (TU ends ~0x803DBFF4) |
| 104 | ctor | 0x803DDCA8 | EA libs (probable) | unknown TU | ctor entry @0x805A2CE8 -> `fn_803DDCA8` (TU ends ~0x803DDCD4) |
| 105 | ctor | 0x803DE3E8 | EA libs (probable) | unknown TU | ctor entry @0x805A2CEC -> `fn_803DE3E8` (TU ends ~0x803DE414) |
| 106 | ctor | 0x803E0950 | EA libs (probable) | unknown TU | ctor entry @0x805A2CF0 -> `fn_803E0950` (TU ends ~0x803E097C) |
| 107 | ctor | 0x803E0AA0 | EA libs (probable) | unknown TU | ctor entry @0x805A2CF4 -> `fn_803E0AA0` (TU ends ~0x803E0ACC) |
| 108 | ctor | 0x803E1F6C | EA libs (probable) | unknown TU | ctor entry @0x805A2CF8 -> `fn_803E1F6C` (TU ends ~0x803E1F98) |
| 109 | ctor | 0x803E221C | EA libs (probable) | unknown TU | ctor entry @0x805A2CFC -> `fn_803E221C` (TU ends ~0x803E2248) |
| 110 | ctor | 0x803E3228 | EA libs (probable) | unknown TU | ctor entry @0x805A2D00 -> `fn_803E3228` (TU ends ~0x803E3254) |
| 111 | dtor | 0x803E3254 | EA libs (probable) | unknown TU | dtor entry @0x805A2D70 -> `fn_803E3254` (TU ends ~0x803E3280) |
| 112 | ctor | 0x803E3BB0 | EA libs (probable) | unknown TU | ctor entry @0x805A2D04 -> `fn_803E3BB0` (TU ends ~0x803E3BDC) |
| 113 | dtor | 0x803E3BDC | EA libs (probable) | unknown TU | dtor entry @0x805A2D74 -> `fn_803E3BDC` (TU ends ~0x803E3C08) |
| 114 | ctor | 0x803E9BC8 | EA libs (probable) | unknown TU | ctor entry @0x805A2D08 -> `fn_803E9BC8` (TU ends ~0x803E9BF4) |
| 115 | dtor | 0x803E9BF4 | EA libs (probable) | unknown TU | dtor entry @0x805A2D78 -> `fn_803E9BF4` (TU ends ~0x803E9C20) |
| 116 | ctor | 0x803EAF24 | EA libs (probable) | unknown TU | ctor entry @0x805A2D0C -> `fn_803EAF24` (TU ends ~0x803EAF50) |
| 117 | ctor | 0x803ED6D4 | EA libs (probable) | unknown TU | ctor entry @0x805A2D10 -> `fn_803ED6D4` (TU ends ~0x803ED700) |
| 118 | ctor | 0x803F00A4 | EA libs (probable) | unknown TU | ctor entry @0x805A2D14 -> `fn_803F00A4` (TU ends ~0x803F00D0) |
| 119 | dtor | 0x803F00D0 | EA libs (probable) | unknown TU | dtor entry @0x805A2D7C -> `fn_803F00D0` (TU ends ~0x803F00FC) |
| 120 | ctor | 0x803FAE68 | EA libs (probable) | unknown TU | ctor entry @0x805A2D18 -> `fn_803FAE68` (TU ends ~0x803FAE94) |
| 121 | ctor | 0x804027B0 | sdk/runtime area | unknown TU | ctor entry @0x805A2D1C -> `fn_804027B0` (TU ends ~0x804027DC) |
| 122 | sdk | 0x80415344 | sdk/runtime area | dolphin/ai | `<< Dolphin SDK - AI >>` (Apr  5 2004 04:15:02); used by fn_80415344@0x80415344 |
| 123 | sdk | 0x804159AC | sdk/runtime area | dolphin/ar | `<< Dolphin SDK - AR >>` (Apr  5 2004 04:15:03); used by fn_804159AC@0x804159AC |
| 124 | sdk | 0x804174E4 | sdk/runtime area | dolphin/arq | `<< Dolphin SDK - ARQ >>` (Apr  5 2004 04:15:04); used by fn_804174E4@0x804174E4 |
| 125 | sdk | 0x804177BC | sdk/runtime area | dolphin/ax | `<< Dolphin SDK - AX >>` (Apr  5 2004 04:15:05); used by fn_804177BC@0x804177BC |
| 126 | sdk | 0x8041B75C | sdk/runtime area | dolphin/card | `<< Dolphin SDK - CARD >>` (Apr  5 2004 04:15:35); used by fn_8041B75C@0x8041B75C |
| 127 | sdk | 0x80421CBC | sdk/runtime area | dolphin/dsp | `<< Dolphin SDK - DSP >>` (Apr  5 2004 04:15:32); used by fn_80421CBC@0x80421CBC |
| 128 | sdk | 0x80422FD8 | sdk/runtime area | dolphin/dvd | `<< Dolphin SDK - DVD >>` (Apr  5 2004 04:14:51); used by fn_80422FD8@0x80422FD8 |
| 129 | sdk | 0x80427F18 | sdk/runtime area | dolphin/exi | `<< Dolphin SDK - EXI >>` (Apr  5 2004 04:14:14); used by fn_80427F18@0x80427F18 |
| 130 | sdk | 0x804290B8 | sdk/runtime area | dolphin/gx | `<< Dolphin SDK - GX >>` (Apr  5 2004 04:14:28); used by GXInit@0x804290B8, __GXInitGX@0x804296B8 |
| 131 | sdk | 0x8043188C | sdk/runtime area | dolphin/os | `<< Dolphin SDK - OS >>` (May 21 2004 09:28:09); used by fn_8043188C@0x8043188C, fn_80431D6C@0x80431D6C |
| 132 | sdk | 0x804394C8 | sdk/runtime area | dolphin/pad | `<< Dolphin SDK - PAD >>` (Apr  5 2004 04:14:49); used by fn_804394C8@0x804394C8 |
| 133 | sdk | 0x8043A3D0 | sdk/runtime area | dolphin/si | `<< Dolphin SDK - SI >>` (Apr  5 2004 04:14:16); used by fn_8043A3D0@0x8043A3D0, fn_8043A6CC@0x8043A6CC, fn_8043AC68@0x8043AC68 |
| 134 | sdk | 0x8043BE24 | sdk/runtime area | dolphin/vi | `<< Dolphin SDK - VI >>` (Apr  7 2004 04:13:59); used by fn_8043BE24@0x8043BE24, fn_8043C0D0@0x8043C0D0, fn_8043CA48@0x8043CA48 |
| 135 | ctor | 0x8052A1DC | frontend overlay | unknown TU | ctor entry @0x805A2C40 -> `fn_8052A1DC` (TU ends ~0x8052A208) |
| 136 | srcpath | 0x8052AE7C | database overlay | source/common/database/components/datalookup.cpp | source path string; refs 0x8052AE7C-0x8052B1DC |
| 137 | srcpath | 0x80541F40 | database overlay | source/common/tourneylogic/offseason/audionames.cpp | source path string; refs 0x80541F40-0x80541F98 |
| 138 | ctor | 0x805A2B84 | database overlay | source/common/database/components/datalookup.cpp, source/common/tourneylogic/offseason/audionames.cpp | ctor entry @0x805A2C44 -> `fn_805A2B84` (TU ends ~0x805A2BB0) |
