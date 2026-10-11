# Near-miss and parked queue

Functions a worker parked (8 attempts used) that are worth another pass, best
first. A stronger model (Opus, high effort) takes these; for C units the
permuter is an option too. decomp-permuter parses C only, so it can't run on
our C++ game units as they are.

| Function | Unit | Best | What differs | Tried |
|---|---|---|---|---|
| fn_vslot17 (0x802726BC, 0x464) | animation/choosers/tu_80271F14.cpp | 97.9% (275/281 insns) | case 1 only: registers r8/r10 swapped around the int-to-float conversion, a c2 reload through f0 instead of f13, `lis r0,0x4330` scheduled earlier | ~1,700 statement/declaration orders, int types, nested inlines |
| fn_8026FDB0 (0x108) | animation/choosers/tu_8026DDE8.cpp | 66/66 insns, 10 differ | float clamp: retail keeps the result in f0 (t's register), ours copies to f13; the post-CSE jump pass hoists the else-value copy. Same clamp issue blocks slot 17 (0x8026EE6C, ~10 clamps) | ~190 source forms (W5); read `-da` jump/cse dumps first |
| fn_8026FB80 (0x230) | animation/choosers/tu_8026DDE8.cpp | 139/140 insns, ~37 differ | callee-saved numbering; count read as 16(this) vs 4(&mC); final copy loop becomes bdnz (retail mr/addic./bne) | W5 |
| fn_8026EE6C slot 17 (0x6C4), fn_8026E364 (0x904), fn_8026F590 (0x5D0) | animation/choosers/tu_8026DDE8.cpp | draft 419/433 / not written | clamps as above; c..f land in other regs; switch tree | W5 |
| fn_8027A4A4 (0x3A8) | animation/choosers/tu_80279AE4.cpp | ~75% (reg-normalized) | retail tests `flag` early into cr4 (CR saved in prologue, frame 0x148 vs 0x150); flags RMW as `add rX,this,idx*40; lwz 0x44(rX)`; load scheduling | ~10 forms incl. 27 RMW combinations (W1) |
| fn_802A3D8C (0x744, cFudgePosRotWarp worker) | animation/warps/tu_802A3704.cpp | ~94% (464/465 insns) | st/x callee-saved regs swapped; retail keeps x+0x734 and indexes (idx*4)+0x48; temp slots 0x20 lower (debug-block locals live to the end); arg scheduling of 2nd Query call | >8 passes (W2) |
| fn_80270BA0 (ICommonPlayerID slot 17) | animation/choosers/playeridchooser.cpp | near (r28/r29 swap) | callee-saved register assignment of two pointers | ~14 variants |
| fn_803DA038 | ealibs/tu_803D9FE8.cpp | 95% | see W5 notes in git log | W5 |
| fn_802735F4 (cLinearChooser slot 17, 0x2930) | animation/choosers/tu_80272B20.cpp | not attempted | 10.5 KB, float-heavy switch; notes in the worker report: sets helper+0x10, calls fn_80272E28 with a [0,1]-clamped value, fn_8027342C, fn_80273498, fn_8026D504 | none (tier C) |
