# Near-miss and parked queue

Functions a worker parked (8 attempts used) that are worth another pass, best
first. A stronger model (Opus, high effort) takes these; for C units the
permuter is an option too. decomp-permuter parses C only, so it can't run on
our C++ game units as they are.

| Function | Unit | Best | What differs | Tried |
|---|---|---|---|---|
| fn_8053FCC4 | db/tu_8053E240.cpp | 82/82 exact | Requires canonical C by-value `fn_80329FA0(int,...)`; shared DB header exposes explicit-buffer form used by other TUs, so an isolated declaration change is not ABI-coherent | Exact typed by-value result; blocked pending coherent shared caller migration |
| fn_8053FE0C | db/tu_8053E240.cpp | 51/51 exact | Same `fn_80329FA0` cross-TU declaration conflict as fn_8053FCC4 | Exact typed by-value result; blocked pending coherent shared caller migration |
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
| fn_803DA038 | ealibs/tu_803D9FE8.cpp | resolved | Return linked node; canonical C provider imports, 24/24 words | Codex |
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


## 2026-10-13 bounded Codex probes

Read this table before assigning more near-match agents. These are failed trials,
not accepted source changes. Retry only with new callee/layout/compiler evidence
or a new mechanism; varying the same spelling again wastes the attempt budget.
The ignored scratch paths are in the attached Codex worktree, so a different
checkout may need the sources reconstructed from these notes. Farm candidates
still require real branch/target/literal checks and the unmodified verifier.

| Function(s) | Unit | Result / attempted mechanism |
|---|---|---|
| fn_cslot11 | game/tu_801527C8 | Stack-only 820 B lead parked: actual getter uses a twelve-byte Vec3 and returns a pointer; no evidence for padding, larger result or hidden parameter. Do not shrink/invent buffers from frame size alone. |
| fn_8052FC4C | db/tu_8052E4C0 | Eight source reconstructions: counter initialization, signed index loads, end pointer and loop forms. Best 95/95 words, eight different. Frozen scratch build/probe-8052fc4c; no accepted draft. |
| fn_8054F970 | db/tu_8054CBBC | Eight float/double/const/register/helper forms; actual provider fn_800D8108 returns void with three integers, string and float. Float-store forces a stack temp instead of retail f31. Frozen scratch build/probe-8054f970. |
| fn_8054F748 | db/tu_8054CBBC | Eight counter initialization/scope forms retained the two initialization differences. build/float-audit. |
| fn_801971B8 | game/tu_80194D44 | Ten reciprocal/local/helper forms did not move the sole float spill from sp+0x7c to retail sp+0x74. |
| fn_802B2C98 | game/tu_802B0ACC | All 120 distinct five-float-store orders failed. No source retained. |
| fn_80392884 | ealib/tu_803927E4 | Eight index/base commutations failed to produce retail lwzx operand order. |
| fn_8032F684, fn_803A0554, fn_8053B6CC | game/tu_8032ECD8; ealib/tu_803A0310; db/tu_8053967C | Bounded min/add/index source variants failed; last two were accidentally repeated by another audit with the same one-word residual. Search notes before dispatch. |
| fn_802684B0, fn_801EAAE0, fn_804B3110 | game/tu_80268190; game/tu_801EA36C; fe/tu_804B13FC | Bounded compare/counter/copy forms did not improve single-word residuals. |
| fn_8058C3C4 | db/tu_8058BF2C | Seven variants: true int index parameter, named float-to-int result, and known-zero last argument. Best remains seven words of call setup/result-register scheduling. build/probe-8058c3c4. |
| fn_800653F8 | game/tu_80064D48 | Eight variants: getter temporaries, m4/m8 store order, saved ok flag, evaluation order and nested conditions. Best four words: two argument moves and two stores; compiler CSE uses known p==1 instead of saved ok. Frozen build/agent-vector/shortcut-800653f8. |
| fn_8013F60C | game/tu_8013BE4C | Five aggregate-member views changed virtual-call behavior/code and were discarded. Existing held-subobject load is one word different but addresses the same vptr at w+0x100; fresh-expression/holder trials already recorded in source. Frozen build/probe-8013f60c. |
| fn_804245BC | dolphin/dvd/tu_804227D4 | Eight pointer/local/inline forms: best retains the adjacent INITSTREAM addi/lwz swap (406/406 words). Frozen build/probe-804245bc. No new volatile qualifiers or compiler flags used. |
| fn_803F0D94 | ealib/tu_803F00FC | Four extra trials using the new active/-active dependency, with short-zero store early/late and inactive=active-1. Best nine words unchanged; farm's string-event constant recipe does not fix this family. Frozen build/probe-803f0d94. |
| fn_8035B16C | game/tu_8035AB44 | Real provider is Unk8037B3E8 destructor at 0x8037B424. Typed destructor call hardcodes in-charge=2; target forwards caller's argument. No legal exact typed call found; no alias or fake prototype accepted. |

The current exact-layout, zero-missing-import source-link shortlist is exhausted.
The next promotion needs new evidence for data ownership, imports or real TU
boundaries. Existing verified source linking and function matching are distinct
measures; the final DOL still contains extracted code for unmatched units.


Follow-up with the new event-state dependency: fn_803F0FCC reached three differing
words (from five) but no exact match. fn_803F108C's three active/zero variants were
worse. The accepted string-event trio is recorded in PATTERNS.md; these remaining
functions still need a new mechanism, not more permutations of the same stores.


### Shared table v4 ABI migration (2026-10-13)

Candidate source set: `v4-final/src/tu_80090880.cpp`, `tu_800928B0.cpp`, `tu_80094578.cpp`, `tu_8007B714.cpp`; shared final header copies are under `v4-final/include/game/`. The three provider TUs change 14 names from `v4__11Tbl<Class>` to `v4__11Tbl<Class>i` while retaining all function addresses, sizes, instructions, local branch destinations, and allocated section sizes. Per-TU rename maps and direct-compile/object evidence are in `staging-manifest.json`, `comparison-output.json`, and `allocated-layout-output.txt`.

B714 now gives pointer-typed formals where current call sites establish pointers: `void*` object followed by integer indices/values for B714/B780/B7C8/B7EC/B810/B834/B858/B8A0; B738/B7A4/B87C take `void*`. The DB provider APIs still receive the original 32-bit value via explicit pointer-to-int conversion where needed. B714 compiles with all 60 functions exactly matching target and unchanged from source, text size 5040 bytes.

Caller source migration evidence: `src/game/tu_800E4234.cpp:384-399` calls B7A4/B7C8/B7EC/B834/B858 with `void* o` and row index; `src/fe/tu_80459228.cpp:411,422` passes `FeScrA::m160` (`void*`, header line 214) to B714/B738; `src/fe/tu_8046C6F8.cpp:228-239` and `src/fe/tu_804740A8.cpp:146,163` pass a widget pointer plus flag to B780; `src/game/tu_80073914.cpp:772` passes a widget pointer then five ints to B8A0; `src/game/tu_800A23F4.cpp:111` passes a widget pointer to B87C. Corresponding old free-function prototypes are in `include/game/tu_800E4234.h`, `include/game/fe_80459228.h`, and `include/game/fe_80471EBC.h`.

No tracked source/config/verification file was edited; these are scratch findings only. Full verifier/hash/regression gates have not been run.


The clone scanner now has only three shape candidates: two already parked in game/tu_80174318, and the 32-byte destructor at 0x80362C2C. The latter calls the same in-charge destructor family as the parked fn_8035B16C; the free-function clone reports a missing function after compilation because the retail target is a destructor symbol. No match was accepted.


### Bounded continuation trials (2026-10-13)

- fn_8038B630 (gamelib/tu_80387E28): eight forms total. Const source, explicit
  members, taking the source address before the preceding call, and an inline
  value-return helper did not remove the base-addi/first-lwz swap. Best two
  differences; no source change. build/clone-snapshot/build/probe-8038b630*.
- fn_8035C24C: the two remaining aggregate-destructor/store-order forms failed;
  the eight-attempt budget is exhausted. build/agent-abi-next.
- fn_801F0004 (game/tu_801EE438): eight initialization, declaration-order and
  constness forms. Best retains two float-store ordering differences; copy and
  mutable-threshold forms add instructions. build/clone-snapshot/build/probe-801f0004*.
- fn_8038871C: four float/threshold forms; fn_8001CCE0: sum/temp forms;
  fn_803BE594: six pointer/offset forms; fn_803A0408: four product/load forms;
  fn_803FC064: three argument forms; fn_8031E960: linkage correction and constant
  order forms. None matched. Separate C-linkage issue in fn_8031E960 is recorded
  in scratch but not accepted alone. build/agent-float-math-* and agent-call-eval-*.

Bounded near-miss probe summary (2026-10-13)

- `game/tu_800A9858::fn_800AABA4` (456B, 112/114 matched): 3 behavior-preserving reorder variants in `near-800AABA4/` all retained the same 2-instruction swap (target stw r9,0(r29) then mr r3,r30; source reverse). Moving the first embedded initializer ahead of the header writes created 20 mismatches. Park after 3 meaningful variants.
- `game/tu_800437AC::fn_80043884` (116B, 29 instructions): 4 forms (sum order reversed, direct compare, XOR temporary, natural pointer/stride form) failed; best remains 7 instruction-register differences. Control-flow/algorithm matches, but compiler register allocation is stubborn. Park.
- `game/tu_800AB0E8::fn_800AC128` (212B, 53 instructions): 8 bounded forms (pointer increment while/for, explicit count locals, direct pointer-range, pointer-based index) failed. Best variants retain the 6-slot pre-loop register-order mismatch; end-pointer and reverse forms were worse. Park.
- `game/tu_8001CACC::Unk8001C314::fn_8001CACC` (312B, 78 instructions): 4 semantically equivalent status-flag/control-flow forms did not yield the retail r30=this/r31=ok allocation; best had 7 instruction differences. Park.

No target reached exact instruction/branch match. Compiler scoring was direct scratch-only using the unit's `-Os -G0 -ffloat-store -fno-rtti -fno-exceptions -Iinclude` flags.


Park note — game/tu_80089894 (scratch audit)

The source object has 60 functions / 13,776B .text, but also emits 152B .rodata while the retail split object allocates only .text. Every referenced source pool offset maps by paired function relocations to existing retail objects: 0x00–0x24 -> lbl_805B4BB4..lbl_805B4BD8; 0x28,0x30,0x34,0x38 -> lbl_805B4C70, lbl_805B4C78, lbl_805B4C7C, lbl_805B4C80; 0x40,0x48,0x50,0x58,0x5c,0x60,0x68,0x70,0x78,0x80,0x88,0x90 -> lbl_805B4E08..lbl_805B4E80. Direct extern substitutions shrank the pool by only 16B and changed code scheduling (fn_8008A624: 38 target instructions vs 36 candidate), so this is not a safe source-link fix.

Six imports remain: __builtin_vec_delete, __vn__FUii, fn_80071604__FPv, fn_80071688__FPvi, fn_80071E2C__FPviT0, fn_8040074C__FPvi. Source/provider evidence: fn_80071604 is actually (Unk80071604*, const char*, Obj*, unsigned), but local source calls it with only self; fn_80071688 is the one-int charge overload; fn_80071E2C is (Unk80071604*, int, Unk80070DDC_Stream*); fn_8040074C is C-linkage memset-like (void*, unsigned). ABI repairs need caller evidence and still would not solve the extra literal pool. Park.




### Further bounded leads (2026-10-13)

- fn_803FDFB4: six byte-decode association, temporary, inline-decoder and unsigned
  forms failed to remove the final OR/compare result-register pair; no source
  retained. build/clone-snapshot/build/probe-803fdfb4.
- fn_801C4C3C: inline DifferenceFromPosition returns the vector difference and
  fixes all fifty masked words/stack offsets, but the original local sqrt
  declaration has C++ linkage and float input. Real export is C; provider source
  currently declares double input. Correct C/double declaration changes four
  FPR/FMA words; four further typed variants fail. Across 358 caller functions
  in 128 objects, arguments are float-valued in f1, and the provider forwards f1
  to sqrt then rounds the result. These observations cannot distinguish float
  and double formals. No provider type was changed to force a match; this lead
  remains unaccepted. build/probe_801c4c3c*, build/801c4c3c-final.cpp.
- fn_801D14A0: eight structural/lifetime forms fail. The actual by-value vector
  is eight bytes, so enlarging it is unsupported. A separate RandF4 C-linkage
  correction retains the stack differences and is scratch-only. Evidence in
  build/agent-stack-801d14a0/proof.json.
- fn_8025AC0C: four inline-return/lifetime forms; fn_800F6F0C: six compiling
  declaration/pointer forms. None match. build/stack_lead_attempts.json.
- fe/tu_80529364: code matches, but .ctors points to fn_8052A1DC, which calls
  startup helper fn_80525670(1,-1) in the preceding split. Source has no global
  object/dynamic initializer that naturally emits that entry. No dummy global,
  constructor attribute, manual section pointer or other hook was introduced.


### Continuation source-form sweep (2026-10-13)

- fn_803E910C: root and a worker accidentally overlapped index-expression
  trials. None removed the r0/r9 scaled-index register difference. Seven root
  plus eight worker forms are parked; no more source spelling permutations.
- fn_803E7A60: four older plus four new output-variable/scope/array forms retain
  four stack-offset differences. sscanf outputs and the following copy/callee
  addresses match the recorded retail order; build/agent-803e7a60.
- fn_8053AF9C: seven equivalent loop/control forms retain two compare/backedge
  differences; fn_80531D84: three counter/index forms; fn_8057D62C: three float
  evaluation/declaration forms. No exact candidate. build/agent-db.
- fn_80479A90: declaration/assignment/lifetime forms retain the two global-load
  slots or worsen registers; fn_804969A8: scaled-index forms retain the mulli/lwzx
  pair, with later variants exceeding the intended cap. Both parked.
- fn_80492FB4 already had eight earlier variants; it was not retried.
- fn_801790BC, fn_80244DC4 and Unk800085B0::vslot22: four small float/spill forms
  per target, with mangled-symbol/provider types checked; no exact match.
- fn_8041A55C (Dolphin AX): eight pointer/index/base-expression and lifetime
  forms retain the five register differences. build/clone-snapshot/build/probe-8041a55c*.

- fn_80596D88: caller fn_8059053C at 8059051C stores returned r3 at +0x28. Pointer-result correction matches the initial register setup but moves the final +0x2C store early. Eight return/store-order forms, no exact match; build/80596d88-{return,order*,reverse}.cpp. Do not repeat spelling permutations.
- fn_80563F0C / fn_80564A98: allocation callers at 800A10D8/800A10F8 store returned r3. Typed return-self corrections alone leave initialization/register ordering differences (12/11 and 9/8 target/source words). Scratch build/agent-game-db-returnself; no source change accepted.
- AX fn_804188D0: moving the actual helper-definition chain reduces unwanted inlining to 109 words versus retail 110, but changes other callers as helper visibility shifts. Bounded ordering probes did not produce an exact all-function candidate; build/agent-ax. No flags, attributes or invented boundaries used.

### Twelve-worker conventional matching pass (2026-10-13)

All failed candidates below stayed scratch-only. Do not repeat these source
spelling/lifetime forms without new compiler or layout evidence. Detailed
evidence and worktree mapping: `docs/SWARM_SESSION_2026-10-13.md`.

- `game/tu_800F1AEC::fn_800F2148`: eight boolean predicate forms; best 35/35
  instructions with 13 differing slots (conditional branch versus mfcr and
  r9/r11 allocation). `fn_801015EC` in `game/tu_80101254`: six table-copy and
  virtual-call forms; best 45/45 instructions with four scheduling/counter
  differences. Worker 01 scratch.
- `animation/goals/tu_8028989C`: eight forms each for `fn_802898FC` (clamp
  store/cross-jump placement), `fn_80289944` (temporary copy and store order;
  original remains closest), and `fn_8028B13C` (m0 store insertion order;
  baseline-equivalent four differing words). Worker 03 scratch.
- `fe/tu_804BFB3C::fn_804C03A8`: deferred because the real
  `fn_8035686C(void*, int)` conflicts with the shared header's one-argument
  C declaration; requires an evidence-based shared ABI repair.
  `fe/tu_80459228::fn_8045AD28`: four variants; best 69/69 instructions but
  copy addressing/store order and search-base hoisting differ. Worker 05.
- `game/tu_802E22EC::fn_802E301C`: one scratch form, 70 compiled instructions
  versus 72 retail; not exhausted. Worker 07. Its other target `fn_802E7FA8`
  was accepted separately.
- `snd/tu_803B4BEC::fn_803B58E8`: four conventional bitmask/filter loop forms;
  best 42 instructions versus 47 retail. CSE removes repeated index/mode
  loads and changes branches. `fn_803B5B6C` was skipped because source already
  records exhausted earlier attempts. Worker 08.
- `gamelib/tu_80382BB8::fn_80382BD8`: eight switch/modulo/address forms;
  first 30 words exact, best 43 versus 45 instructions. Compiler combines
  object and index*136 and uses lfs+20 instead of separate base and lfsx.
  `fn_80383394`: eight pointer/integer loop forms; signed comparison restored,
  but best 7 versus 8 instructions, missing retail's extra mr r11,r3.
  `fn_80380964` inspected only; not attempted. Worker 09.
- `dolphin/gx/tu_8042F93C::fn_8042FF38`: eight natural C boolean/bit-insertion
  variants with actual MWCC flags. Best remains eight changed register words
  across 53 instructions; narrower/comparison forms change instruction count.
  `CARDInit`/`fn_8041B75C` skipped due an existing source park. Worker 11.
- `db/tu_805467E0::fn_80547D28`: eight iterator/setup forms; best 58/58
  instructions with six initial scheduling differences. Iterator stack store
  moves before base calculation/count load; remaining words match masked.
  Fresh untouched alternatives: `fn_80582B7C`, `fn_8053EA68`. Worker 12.

### Source-object placement and bounded follow-up (2026-10-13)

- ealibs/tu_803D9FE8: all six functions and existing .bss/.ctors bytes are exact, but a full source-link trial fails the retail hash because the compiler emits static initialization at .text+0x124 while retail has it first. The node methods consequently start 0x50 too early; _GLOBAL_.I is at +0x174 in both. This is an actual function-order blocker, not a claim that section flags/alignment alone prevent linking. Trial was restored; build/data-rejected/tu_803D9FE8. No manual constructor pointer or compiler-attribute workaround.
- fn_803EDA0C: eight scalar/mask forms retain two register-only lhz/rlwinm slots; fn_8039365C: eight legal index/address forms retain two register-order slots or worsen. Scratch build/agent-event/{v,w}*.cpp.
- fn_801790BC: actual helper returns int and accepts (Sub*,void*,float); caller stores returned r3 and passes an object pointer in the integer-typed slot. A typed scratch return correction fixes callee bindings but retains the known integer-store/float-spill order. No further float permutations.
- fn_8037C3F8, fn_8037BFCC, fn_80379094, fn_80385470: audited residuals are register allocation/address order only. fn_803772E0 counted-loop variants worsen the missing exhausted-scan zero assignment. No exact candidate accepted.
- GXAttr: rounded data end 0x80634958 would overlap the real object starting at 0x80634954. The exact 0x274-byte jump-table extent ends at 0x80634954; that exact split passes the full hash. Do not claim a neighboring object prefix as padding.
- DSP task: assigning its zero state section at 0x806EF618 creates a real section-order cycle with earlier EA text and later EA small-BSS. The accepted source leaves those globals external and owns only its proven .data format strings.

- fe/tu_804DE730 is now 42/42 code matched after fn_804DF4D4 pointer-lifetime fix. Source linking still needs its shared strings: externalizing inline title/license copies via normal memcpy retains one missing compiler-generated crclr before zero-tail memset (161/162 words). Aggregate-return and in-class constructor forms either add helper calls or reverse required copy/zero order. Bounded forms parked; no variadic cast/wrong memset prototype added. build/agent-event/tu_804DE730-{pool,aggregate*,buffer*}*.cpp.
- fn_80160F14 missing body: five grounded C++ variants use existing Teams/Team fields, sum the two 128-byte arrays, compare the absolute difference to 3 and select a band by m1CC8/3. Best56 words vsretail60; loop addressing, signed division and return-control shape remain unmatched. Scratch build/clone-snapshot/build/agent-fn80160f14.
### Persistent FE swarm14 (2026-10-13)

- `fe/tu_804F81E0::fn_804F9FD8`: seven conventional forms; best48/48words with identical FPR/frame/branches, but four induction registers/initialization order differ (12words). Nested inline setter reproduces sunk float argument slots +8/+16; member array views preserve indexed stores; explicit five counters preserve strength reduction. Shared index formulas prevent induction optimization. Scratch build/swarm14/F9FD8-v*.cpp inSW01. Restored.
- `fe/tu_804E1A6C::fn_804E2E00`: three forms; best75vs74words. First-arm global HA reloads through scratchr9 instead of savedr30. Explicit global address adds unwantedLOaddi; inline getter/goto form unchanged. >=4 becomescmpwi3/ble instead of4/blt. Restored.
- Same unit `fn_804E2F7C`: four forms, no exact. Plain switch/inline message assignment121vs118words; final &message does recover saved global HA and frame-relative call argument. Char local adds extsb; explicit known-zero mode/flag and conditional-name forms shorten to114words and lose first-arm flag lifetime/cross-jump. New code must explicitly forward fn_800B555C() state to fn_800B57EC; no shared ABI repair retained. Restored.
- `fe/tu_80452120::fn_80454BB0`: six forms; best83/83instructions, all words after initial id/global-snapshot prefix exact. Initial id loads/stores use r0/r11/r9 and secondstore4(r28) versus retail r9/r10/r11 and sp+12. Splitting nested getter before setter avoids caching screen fields across the getter and recovers the body. Inline pointer initialization, pair constructor, aggregate pair (adds zero stores), separate scalar declarations did not improve prefix. Source restored; build/swarm14/454BB0-v*.cpp inSW01.
- `fe/tu_8049B0CC::fn_8049DCE0`: two int/char flag forms; both103vs100words. Compiler preserves flag condition inCR4 across format/widgetcalls and addsCRsave/restore; retail keeps flagr28 and repeatscmpwi. Buffer200bytes andfloat slotsD0/D4 match. Restored; build/swarm14/49DCE0-v*.cpp inSW01.
- `fe/tu_804ECDE0::fn_804F4960`: eight forms exhausted. Best115/115words, all control flow and values exact, widget/outputr29/r30 pair swapped(16words). Separatecasebodies retain15-way switchtree; groupedlabels shrinkto101words. Separate if/else writes retainoutputreload/valueinr0; ternariesforwardargreg4(109words). A volatile-output diagnostic still differs and is rejected; explicitsubobject view devirtualizes(97words). Inlinecontrolwrapper, referenceformal, ascendingcaseorder retainregisterswap. Restored; build/swarm14/4F4960-v*.cpp inSW01.



### Continued bounded source probes (2026-10-13 afternoon)

- game/tu_800A8684::fn_800A96A4: eight return/boolean/control forms leave normalization and branch placement differences (24-27 compiled words versus 28 retail). Existing 112-byte function remains unmatched. Scratch build/800a96a4-v0..7.cpp.
- ealib/tu_803F2000::fn_803F6754: missing UTF-16 version-component parser; eight typed while/postincrement/arithmetic/cached-cursor forms emit 27-31 words versus 29 retail. Digit-loop peeling and register allocation differ. Scratch build/803f6754-v0..7.cpp.
- ealib/tu_803FFD9C::fn_80400690: missing 64-slot shutdown callback registration (skip an existing callback, otherwise use first empty slot). Eight counted/pointer/index/first-slot forms emit 22-29 words versus 27 retail; second-loop strength reduction differs. Existing callback-table type retained. Scratch build/80400690-v0..7.cpp.
- game/tu_80107F74::fn_80108268: grounded statement-order/direct-member-call variant preserves the existing 288-byte miss against 292 retail. Actual ProDG flags and existing v32/v91 contracts retained. Scratch build/agent-80108268/reorder.cpp.
- fe/tu_804F81E0::fn_804F9FD8: missing 41-float copy into two global ranges followed by two flag updates. Three typed index/cursor forms emit 41/46 words versus 48 retail; global reloads and float spills differ. No exact candidate.
- fe/tu_8044928B::fn_804D2AC0: constructor-like result/argument-order probes worsen the current 67-word near-match. Lazy manager initialization and heap-field store scheduling remain different; no new exact candidate.
- ealib/tu_80394744::fn_803957A4: nine typed record-byte parser forms; best 34/34 words with register/scheduling differences. Preserve the retail negative-index behavior, record stride/scale and final endpoint layout. Scratch build/agent-event/fn957a4-*.cpp.
- ealib/tu_803A0310::fn_803A3D84: paired-single kernel lacks a supported source expression for the retail immediate addressing. The compiler's actual three-argument __builtin_psq_l requires -mps-float; a scratch flag probe leaves existing functions unchanged but the new body emits 42 words versus 33 retail. No flags/source promoted, no assembly workaround. The earlier fn_803A3D4C probe is also unmatched.

- db/tu_8059377C source-link: truthful class-specific array allocation/deallocation wrappers and POD direct providers preserve all 25 code functions and six shared-header users, but its private 88-byte .rodata pool maps to scattered retail float/double objects. Externalizing six explicit float references preserves code; 48 bytes remain (250000/125000 plus five compiler-generated 2^52 biases), with no contiguous target placement. Externalizing the first pair worsens fn_80593A00 scheduling. No source/header changes promoted. Scratch build/agent-db-alloc.
- ealib/tu_803E1F98 and tu_803DDCD4 source-link: current source has exact text but omits the actual .ctors entry. A real typed 12-byte Head(4,4,1) global gives E1F98 the exact total 688 text bytes and wrapper placement, but the compiler appends the static-init helper after the ordinary methods (offset588 versus424), shifting their locations. Moving the global declaration does not fix placement. The 12-byte BSS ownership also needs a real transfer. Dummy initialized integers and callback-wrapper objects add extra state/code and were rejected. No manual constructor registration or attributes used. Scratch build/agent-event/ctor-source-link-audit.json.
- `fn_805474B8`: two counter initialization forms retain the single `li` versus retail zero-copy `mr`; baseline 96.18%. Scratch SW02/build/swarm16.
- `fn_805483C4`: one explicit loop-bound capture removes retail's required reload (54/55 instructions); baseline 97.69% bound/increment scheduling remains parked. Scratch SW02/build/swarm16.
- `fn_80553CA8`: two temporary/arithmetic forms retain the base/triple register allocation differences (62/62 instructions; baseline 99.19%). Scratch SW02/build/swarm16.
- `fn_80551A80`: two named-call/inline-getter forms retain the five r30/r31 swap words or worsen float spills (best 106/106; baseline 99.76%). Scratch SW02/build/swarm16.
- `ealib/tu_803CECA4::fn_803D1E54`: four product-temporary forms; best101/101words retains seven float-load/product scheduling words (99.4% inherited). Restored; batch17.
- `fe/tu_80520BE0::fn_80523960`: two early-return forms23vs21words; inherited21/21word form retains `mr.` versus retail `cmpwi` (96.9%). Restored; batch17.

- fe/tu_80492680::fn_80494108 (99.59%): eight typed index/record/parameter forms retain three r11-versus-r0 allocation differences; scratch build/root-80494108.
- fe/tu_80492680::fn_80493F20 (99.14%): eight byte/unsigned/accessor/condition forms leave the retail redundant byte extension absent or change allocation; scratch build/root-80493F20.

- fe/tu_80492680::fn_80492BA8 (97.58%): eight provider-grounded float/layout/accessor forms leave eight widget/conversion register slots; corrected two-float output contract in scratch build/root-80492BA8, no source change promoted.
- `fn_8056EC68`: explicit boolean-result form loses the retail CR4 lifetime; baseline 96.61% retains the two next-index/call scheduling slots. Scratch SW02/build/swarm22.
- `fn_805706B8`: existing source casts the shared int-declared fn_8007189C to a float provider; canonical return-type repair is required before further matching. Baseline 99.54%; no new casts or aliases added.
- `fe/tu_804439E4` `fn_804459D0` (swarm22, 2 forms): existing 96.18%; 81/82 words, aligned 7. False bit-test path reuses zero in r0 rather than retail explicit li; first virtual-table load/store scheduling also differs.
- `snd/tu_803A9830` `fn_803A9CF4`: 99.615%, 26/26 instructions; rlwinm/lwzx index r3 versus retail r0 remains after byte/local/accessor/const forms.
- `ealib/tu_80394744` `fn_803950B4`: 96.923%, 39/39 instructions; count-load scheduling and register allocation remain; separate count and if/do forms regress.
- `ealib/tu_803D50E4` `fn_803D675C`: 84/84 instructions, 2 load operands differ (stack versus current-iterator base); member iterator/end-return/increment forms converge, remaining source trials parked.

- `ealib/tu_803FEB34` `fn_803FF058`: 97.022%, 89/89 instructions after eight ordinary path-opening drafts; host/end/path registers and initial byte-load scheduling differ; 256-byte buffer and canonical DVD imports preserved.
- `ealib/tu_803FEB34` `fn_803FF888`: 96.716%, 67/67 instructions after eight timer initializer forms; callback address addi and initialized-byte store are reversed; canonical OSTime/alarm ABI and hardware-clock layout used, no instruction/config workaround.
- `db/tu_805881E4` `fn_80588A3C` (swarm24, 2 forms): existing 95.69%; 130/130 words, best 30 register/schedule slots. Index-first setup fixes two words, but id/screen/predicate occupy r29/r31/r30 rather than retail r31/r30/r29.
- `db/tu_805881E4` `fn_8058B048` (swarm27, 5 forms): scratch 144/144 words; held for shared ABI repair. Retail at 8058B1E0 consumes canonical BB28 return in f1, but game provider and member header still declare int; no new conflicting declaration retained.
- `fe/tu_8043FDC0::fn_80440210`: three countdown forms recover19/19words but swap the two saved induction registers (six words); source restored, batch21.
- `fe/tu_804F81E0::fn_804FAB88`: six offset/local/inline-accessor forms; best16/16words has correct global half constant and OR4 indexing, five words swap the two offset registers. Restored, batch21.
- `fe/tu_804F81E0::fn_804F8668`: one explicit-break form shortens to43vs49words; inherited49/49words retains106/bge versus105/bgt bound normalization (99.9%). Restored, batch21.
- `fe/tu_8043FDC0::fn_80442AA0`: accurate canonical one-argument F198 call gives169vs170words; two-register ABI dataflow is proven at8007F1B0/805A19DC, but exact source is blocked on Claude-owned F198 provider/canonical ABI repair. Incompatible call cast removed; recovery ref codex/swarm21-f198-recovery, batch21.
- `ealib/tu_803912F8::fn_803923E8`: three ordinary drafts; best111vs112words/97.1%, selection-update factoring and saved-register allocation remain. Restored, batch21.
- ealib/tu_803BE8BC::fn_803C1B50 (98.29%): eight local/sentinel/zero-chain initialization forms retain constant-register and store scheduling differences; scratch build/root-803C1B50.
- fe/tu_8044F550::fn_80451028 (99.48%): eight indexed-access/local-condition/helper forms retain six index/base register slots or change branch layout; scratch build/root-80451028.
- fe/tu_8050C9DC::fn_8050DA2C (99.23%) / fn_8050E7B0 (99.31%): existing two-argument FeDtorFn casts target canonical one-argument fn_800EC5F4 provider in game/tu_800EBF2C; coherent destructor ABI repair crosses GAME ownership, so no further cast-based variants.

- `db/tu_805721F8` `fn_805721F8`: 99.21965%, 173/173 instructions; roster score array view recovers indexed loads, but round/found/clamped-value registers and the initial search-index copy differ after seventeen bounded forms; new code dropped.
- `db/tu_80574AE4` `fn_80577218`: 99.49468%, 188/188 instructions; comparator branches and the two 12-byte statistics constructors match, but winning-rate denominator/zero FPR allocation differs after ten forms; source dropped.
- 2026-10-13 | db/tu_80565FD4 fn_8056A058 | Eight ordinary C forms; best 97/97 words (98.6%), four table address/load preparation differences. Boolean CR4 preservation and data flow exact; failed body retained only in build/swarm23, source restored.
- 2026-10-13 | ealib/tu_803A0310 fn_803A2C9C | Six ordinary C forms; best 83/84 words (97.2%), first-vector saved register/copy and final store order remain; failed body in build/swarm23 only, source restored.
- `ealib/tu_803959E0` `fn_803977FC` (swarm31, four forms): existing 95.38%; best 101/101 words with 11 differing slots. Result register allocation and history/base load plus common-store scheduling remain unmatched. Scratch SW02/build/swarm29.
- ealib/tu_803E9C20::fn_803E9E30: eight forms yield scratch 72/72 words and local edges exact, but runtime free override GAME8031268C is one-argument while callback contract is (void*, int); retain build/root-803E9E30/v7-integer-address.cpp pending coherent GAME-owned callback repair, no body promoted.

- `db/tu_80574AE4` `fn_8057AF3C`: 99.02778%, 216/216 instructions; one argument move crosses four setup instructions after twenty bounded forms; canonical round queries and the observed nine-word record swap preserved in scratch only.

- db/tu_805721F8::fn_805744D4: 99.966446%, 149/149 instructions; eight source forms leave one local edge at slot 55 (retail +0xE4, candidate +0xEC), skipping the pointer-bound compare. Candidate reverted.
