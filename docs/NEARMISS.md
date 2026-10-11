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
| fn_802735F4 (cLinearChooser slot 17, 0x2930) | animation/choosers/tu_80272B20.cpp | not attempted | 10.5 KB, float-heavy switch; notes in the worker report: sets helper+0x10, calls fn_80272E28 with a [0,1]-clamped value, fn_8027342C, fn_80273498, fn_8026D504 | none (tier C) |

Matched by the near-miss sweep (W4, 2026-10-11; recipes in PATTERNS.md,
"Near-miss sweep"): cTimeWarp::cTimeWarp, fn_8027F504, fn_8027FC80,
fn_8027EC58, fn_80280F08, fn_80282B78, fn_80296624, fn_802958F4, fn_802966DC,
fn_8027A9AC, fn_8027AAB0, fn_8028BDB8, fn_8026FB80, fn_8027BA64, fn_802855C4,
fn_8027B924, fn_8027AD3C, fn_8027B1A0.
