# Near-miss and parked queue

Functions a worker parked (8 attempts used) that are worth another pass, best
first. A stronger model (Opus, high effort) takes these; for C units the
permuter is an option too. decomp-permuter parses C only, so it can't run on
our C++ game units as they are.

| Function | Unit | Best | What differs | Tried |
|---|---|---|---|---|
| fn_8027D3E8 | animation/goals/tu_8027C728.cpp | 99/99 insns, 3 differ | the &out pointer of the GetResult part is r4 in retail, r9 here (global-alloc pass 0 picks a reg already used and not preferred by a conflicting pseudo; the source of retail's r4 is unknown) | ~1500 forms (W5), param order, member, pointer local (sweep) |
| fn_802931D0 | animation/goals/tu_802914C8.cpp | 339/339, 5 differ | only the final `mC = 4`: retail m190 index r9 / the 4 in r0. The index is an index register of the flagged `a` (r0 allowed); giving every SetPairF the cast expression (unflagged pointer) fixes it but loses the alias-based scheduling of the earlier stores; doing it for the last call only changes nothing (gcse merges it with `a`) | `int k4 = 4`, setter/Finish inlines, store order (sweep) |
| fn_vslot17 (0x802726BC, cCircleChooser) | animation/choosers/tu_80271F14.cpp | 281/281, 6 differ | case 1 only: dead copy `mr r8,r11` and the pi/4 constant's lis get r8/r10 swapped, c2 reloaded through f13 vs f0 | ~1700 orders (W3), not retried |
| fn_802857C4 | animation/goals/tu_80283934.cpp | 120/120, 6 differ | the eq scratch of the first return is r11 (retail r9) and Speed's pointer r9 with andis. scratch r11 (retail r3/r9): probably one cascade from the scratch choice | operand/temp forms of the eq, Speed via a local (sweep) |
| fn_8027A84C | animation/goals/tu_8027A84C.cpp | 19/19, 14 differ | same instructions, stores permuted: sched1's register-weight rule moves stores that kill a register first; retail keeps source order | 200 permutations (W), chained/variable constants, root local (sweep) |
| fn_802A3D8C | animation/warps/tu_802A3704.cpp | 465/465, 20 differ | matrix/result/subtraction temps 0x20 lower (retail does not reuse the debug block's slots); second Query call moves `mr r3,r26` first | CurAngle48 accessor fixed the rest; q/r at function scope (worse), direct call, ev local (sweep) |
| fn_80296030 | animation/goals/tu_802914C8.cpp | 168/168, 22 differ | sched1 lets each SetPairF parameter `stfs` (and AngleDiff's) pass the stwx/stfsx through `a`; retail lets frame loads pass it but not frame stores | 8 (W), unflagged pointer, reference stores (sweep) |
| fn_80288F1C | animation/goals/tu_80287600.cpp | 196 vs 195, aligned 15 | ctx pointer c in r6 (retail r3) and case 9's shared `r = 0x94C34DBD` block layout | case 9 as an inline, late c (sweep) |
| fn_8028C264 | animation/goals/tu_8028B194.cpp | 175 vs 191 | hash switch: g++ drops the "continue" cases that share the default target and roots the tree at the median; retail keeps all 11 compares under root 0x858075AA (case routing now right) | goto/default/order forms (sweep) |
| fn_80287600 | animation/goals/tu_80287600.cpp | 302 vs 295 | frame 8 bytes bigger, d == 3 temporaries in other slots, Vec4 build after the loop scheduled differently (clamp and operator* literals fixed) | rec, operator* forms, nested len (sweep) |
| fn_8027A4A4 | animation/choosers/tu_80279AE4.cpp | ~75% | retail tests `flag` early into cr4 (CR saved), flags RMW as `add rX,this,idx*40; lwz 0x44(rX)`, load scheduling | ~10 forms incl. 27 RMW combinations (W1) |
| fn_vslot17 (cMatrixChooser slot 17, 0x6C4), fn_8026E364 (0x904), fn_8026F590 (0x5D0) | animation/choosers/tu_8026DDE8.cpp | slot 17: 431/433, 214 differ | c..f in other callee-saved regs; switch tree; the m170/m178/m38 reads use grouped offsets off x+0x734 (`slwi; addi 368; lfsx`). Reading them through `CurF(&x->m734, off)` (offset accessor, unflagged pointer) gives 131 differ but then the t1/t2 loads no longer pass the float-local stores (retail's reads are in-struct) | W5, hard-case pass, CurF accessor (sweep) |
| fn_803DA038 | ealibs/tu_803D9FE8.cpp | 95% | see W5 notes in git log | W5 |
| fn_8001ADF4, fn_8001AE3C, fn_8001AE84 + 14 in tu_8001B190 (trace wrappers, family B, K != 0, N == 0) | game/tu_8001A6B8.cpp, game/tu_8001B190.cpp | same insns, 2 slots differ | retail emits `li r5` before `li r3` (sched1 order). These `li`s are ready at block start, so adjust_priority never boosts r5. A later r5 reference (any third argument to lbl_80624408) gives retail's order but costs a visible move (PATTERNS, "Hard-case families") | earlier sweep list, then tag-as-id forms, unused/this params, struct return, uninitialised arg, -O2, no sched1 (Opus) |
| fn_802735F4 (cLinearChooser slot 17, 0x2930) | animation/choosers/tu_80272B20.cpp | not attempted | 10.5 KB, float-heavy switch; notes in the worker report: sets helper+0x10, calls fn_80272E28 with a [0,1]-clamped value, fn_8027342C, fn_80273498, fn_8026D504 | none (tier C) |
| fn_8028F178 | animation/goals/tu_8028F178.cpp | 32/32, 2 differ (with a `*(char**)` read of m44->m14) | the float parameter's stfs must sit between `lwz r11,0x44(r3)` and `lwz r0,0x14(r11)`; see PATTERNS, "Hard-case families 2" | alias-type casts of the m14 read, sched dumps (Opus 2) |
| fn_80097318 (+ clones 97380, 973E8, 97450, 974B8) | game/tu_80094578.cpp | 22 vs 26 insns | retail's loop re-reads +0, +4, +0x3E8 every pass and keeps the index as an int with clrlwi per use; ours hoists and rotates the loop differently | read only (Opus 2) |
| fn_80079F54 | game/tu_80077238.cpp | 15/15, 3 differ | fmadds operand/register order: retail loads m204 before the int->float conversion and m1F4 after it | operand orders, float temp (Opus 2) |
| fn_803302D4 | game/tu_8032ECD8.cpp | 44/44, 2 differ | widget with a 10-int ring at +0x48: retail stores the vptr (lbl_80666A68) before m5C; every order of the tail stores puts m5C first or swaps the ring/vtable registers r28/r29. The ring vptr lbl_8064B298 is stored twice (via r28 in the ring init, via self at +0x58), which suggests the ring is a base or member whose vtable g++ re-stores | 24+720 tail orders, FxRingInit inline vs open-coded (Opus 3) |
| fn_8033C490 | game/tu_80338ECC.cpp | 179/179, 6 differ | loop giv order only: retail initialises/increments the item pointer second (o-name, item, o+0x14, offset); ours puts it last | k/nm temporaries, index forms (Opus 3) |
| fn_8032FD58 | game/tu_8032ECD8.cpp | not written | widget ctor with a 126-int ring at +0x48 (same family as fn_803302D4) plus a fill loop from a singleton (fn_800B64BC); FxWidInit + FxRingInit cover the head | none (Opus 3) |
| fn_80536F28, fn_80537054, fn_8053923C | db/tu_80535360.cpp | 75/75, callee-saved regs permuted | the &bufB address pseudo (4 refs over 13 insns) outranks self (11 refs over 66) in global-alloc; retail has self in r31, bufB r30, y r28 (fn_80533120's copy recipe does not apply) | `i = r` copies, int/unsigned mixes (Opus 4); yp/y declaration and loop forms, a bufB pointer local, store order (Opus 5) |
| fn_8056A908, fn_8056B658 | db/tu_8056A248.cpp | 39 vs 41 insns | retail neither strength-reduces i*28 nor hoists the table load, but weights refs like a real loop; its first KeyAt reuses the table pointer (r11) so jump2 does not cross-jump it with the loop's copy | cached table local, for(;;)/while/goto loops, -fno-strength-reduce as a diagnostic (Opus 5) |
| fn_80555D88 | db/tu_80554628.cpp | 90% | same family as fn_8056A908 (rotated loop vs entry jump) | not attempted (Opus 5) |
| fn_8052849C, fn_80528588, fn_80528648 | fe/tu_805283C4.cpp | 99%, 3-4 slots | member-vptr dtor: retail's self copy is r8 because some pseudo held r9 and vanished later | all six store orders, inline member-dtor helpers (Opus 5) |
| fn_8052390C (+4 siblings) | fe/tu_80520BE0.cpp | 21/21, 1 slot | combine merges the call-result copy into the compare (`mr.`); retail has `cmpwi r3,0` and returns r3 untouched on the false path. Dropping the copy gives cmpwi but CSE turns the false return into `li r3,0` | ternary, switch, inline, unsigned, assignment-in-condition, early return (Opus 5) |
| fn_80104798 (game/tu_80101254), fn_800D649C (game/tu_800D4D0C), fn_800E25E0 (game/tu_800E0164) | busy units | match in scratch | callee return types: fn_80403DE4 void in tu_800F1AEC.h; fn_800D0D9C returns UiScrRaw2*; fn_801254EC int + fn_8007CF44 void in tu_800E0164.h (PATTERNS, Hard-case families 5) | patches in scratchpad/W8o5/busy_*.patch |
| fn_8053DB30 | db/tu_8053CC9C.cpp | 129 vs 131 insns | the by-value Date copy (8) and the date buffer (12) sit at swapped frame offsets; fn_8053DD68's recipe (unit-local buffer type with a trivial dtor) fixes the per-call `addi r3,r1,N` but allocates the buffer at declaration, before the copy temp | inline wrapper, BLKmode buffer (Opus 4) |
| fn_800B08B0 | game/tu_800AF248.cpp | 4/4, 2 slots | `int r = 0; switch (p->m10) { case 0..3: r = 0; }` gives `lwz; cmpwi; li; blr`, retail has the `li r3,0` before the dead `cmpwi` | case ranges 0..5, int/unsigned, if forms (Opus 4) |
| fn_803F73B0 | ealib/tu_803F73B0.cpp | not written; best 60 slots | error-code table: cases -128 and -14..0 (value = -k, -128 -> 15), default 16; case set and values right, tree layout differs | `r = v` / `return v` forms, -14/-15 lower bound (Opus 4b) |
| fn_803ABCB4, fn_803ABDD0, fn_803AC164 | snd/tu_803AB310.cpp | not written | dead `cmpwi -18/-10/-7` trees after calls: an error-code switch with empty arms (PATTERNS, Hard-case families 4); the port/mvp2005 reference source should give the rest | none (Opus 4b) |
| fn_80022DF8 | game/tu_80021BE8.cpp | 99/100 insns | retail reloads `b` (`lfs f13,8(r1)`) before the cross-jumped tail; GCSE keeps it in f13 here; the goto reconstruction is probably not the original if/else | inline tails (spill), goto layouts (earlier); PATTERNS, Hard-case families 6 |
| fn_80027CF0, fn_8002B430 | game/tu_80026A48.cpp, game/tu_8002B430.cpp | not written | family 3 shape: use the Secs inline (PATTERNS, Hard-case families 6); fn_80027CF0 also has a volatile saturating loop over m270[0..2] and undeclared fields m740/m798/m7C8/m7CC | none (Opus 6) |

Matched by the near-miss sweep (W4, 2026-10-11; recipes in PATTERNS.md,
"Near-miss sweep"): cTimeWarp::cTimeWarp, fn_8027F504, fn_8027FC80,
fn_8027EC58, fn_80280F08, fn_80282B78, fn_80296624, fn_802958F4, fn_802966DC,
fn_8027A9AC, fn_8027AAB0, fn_8028BDB8, fn_8026FB80, fn_8027BA64, fn_802855C4,
fn_8027B924, fn_8027AD3C, fn_8027B1A0.

Matched by Opus hard-case families 2 (2026-10-11; recipes in PATTERNS.md, "Hard-case
families 2"): fn_8004961C, fn_8004A8F8, fn_8004B538, fn_800488C4, fn_80051E68,
fn_80051014, fn_8006473C, fn_80088EFC, fn_80077238, fn_80077320, fn_80077404,
fn_80077684, fn_8007776C, fn_80077850, fn_80077934, fn_80078D00, fn_800A3DF8.

Matched by Opus hard-case families 3 (2026-10-11; recipes in PATTERNS.md, "Hard-case
families 3"): fn_8032ECD8, fn_8032F120, fn_8032F19C, fn_8032F38C, fn_8032F428,
fn_8032F4CC, fn_8032DC2C, fn_8032DD00, fn_8032E0B4, fn_8032E1DC, fn_8032E70C,
fn_8032E7C0, fn_8032E894, fn_8032EB84, fn_8032EC38, fn_800AEA68, __5FxRec, __3FxSi,
__3FxU, fn_80331DB8, fn_80332978, fn_80332DBC, fn_80333A70.

Matched by Opus hard-case families 4 (2026-10-11; recipes in PATTERNS.md, "Hard-case
families 4"): fn_8006FB10, fn_8006FB1C, fn_8006FF9C, fn_8006FFD0, fn_80071138,
fn_80071154, fn_8009FDC8, fn_8009FDD4, fn_8009DDE4, fn_8009E060, fn_80055D84,
v8__11Tbl80094800, v8__11Tbl800956D8, fn_800E9074, fn_80598AB4, fn_80598B3C,
fn_8059B280, fn_8059F680, fn_8059FADC.

Matched by Opus hard-case families 4b (2026-10-11; PATTERNS.md, "Hard-case families 4",
second pass): fn_8052CB74, fn_8052CC18, fn_8052E754, fn_8052E8D8, fn_8052F554,
fn_8052F590, fn_80530024, fn_805300D0, fn_8053CDB0, fn_8053CE50, fn_8053DD68,
fn_80084B24, fn_80084BDC, fn_800898D0, fn_80089A0C, fn_8008AC18, fn_8008AC68,
fn_8008B368, fn_8008B3E8, fn_8008BEF0, fn_8008BF24, fn_8008CC0C, fn_8008CE64,
fn_8008EB90, fn_8008EC78, fn_804CF304, fn_804CF368, fn_80084728, fn_804F9C64,
fn_8056A1DC, fn_803EB83C, fn_803F644C, fn_80166440, fn_8010F4D4, fn_80134F48.

Matched by Opus hard-case families 5 (2026-10-12; PATTERNS.md, "Hard-case families 5"):
fn_80586560, fn_8058BF68, fn_8058C020, fn_8058E180, fn_80593F30, fn_8059403C, fn_804ACA20,
fn_800D26C8, fn_805881E4, fn_805898A4, fn_804933D4, fn_8049364C, fn_801399A8, fn_8003C804,
fn_80132630, fn_80110DDC, fn_800DE1C4, fn_800DE274, fn_800DE440, fn_8010AE78, fn_800E4FE4,
fn_800E1A1C, fn_80096244, fn_80085F2C, fn_802B8548, fn_802B8B34, fn_802B8BFC, fn_8029C914,
fn_8007A2B4, fn_8007C328, fn_8006B880, fn_805A0000, fn_80533120, fn_804E2014, fn_8025F7F0,
fn_802AF624, fn_80255284, fn_80254EA4, fn_802AE474, fn_802AE4C0, fn_8058FDCC.

Matched by Opus hard-case families 6 (2026-10-12; PATTERNS.md, "Hard-case families 6"):
fn_80163CC4, fn_80143134, fn_80022780, fn_80022A28, fn_80022BE0, fn_8002395C, fn_800292EC,
fn_800297D4, fn_80029FE4, fn_8002BB3C, fn_8002BE10, fn_8002BF20, fn_8002C540, fn_800243D4,
fn_800263D4, fn_800264F4, fn_80291378, fn_8029D094, fn_802456C8, fn_802496BC.
