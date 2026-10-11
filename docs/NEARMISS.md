# Near-miss and parked queue

Functions a worker parked (8 attempts used) that are worth another pass, best
first. A stronger model (Opus, high effort) takes these; for C units the
permuter is an option too. decomp-permuter parses C only, so it can't run on
our C++ game units as they are.

| Function | Unit | Best | What differs | Tried |
|---|---|---|---|---|
| fn_vslot17 (0x802726BC, 0x464) | animation/choosers/tu_80271F14.cpp | 97.9% (275/281 insns) | case 1 only: registers r8/r10 swapped around the int-to-float conversion, a c2 reload through f0 instead of f13, `lis r0,0x4330` scheduled earlier | ~1,700 statement/declaration orders, int types, nested inlines |
| fn_80373AD8 family (x5, 0x704) and fn_803666EC family (x5, 0x6A8) | ealib/tu_80373AD8.. tu_80376598; tu_803666EC, tu_8036A490, tu_8036FEA0, tu_803708F4, tu_80371348 | 99.31% / 98.99% (all insns present) | registers only: i/j swapped (r9/r11) in two default-case index loops; `li r25,1` / `mr r4,r28` order; family 2 also b in r27 vs r26 | ~15 loop-shape/declaration variants (W4); Opus pass in progress |
| fn_80270BA0 (ICommonPlayerID slot 17) | animation/choosers/playeridchooser.cpp | near (r28/r29 swap) | callee-saved register assignment of two pointers | ~14 variants |
| fn_803DA038 | ealibs/tu_803D9FE8.cpp | 95% | see W5 notes in git log | W5 |
| fn_802735F4 (cLinearChooser slot 17, 0x2930) | animation/choosers/tu_80272B20.cpp | not attempted | 10.5 KB, float-heavy switch; notes in the worker report: sets helper+0x10, calls fn_80272E28 with a [0,1]-clamped value, fn_8027342C, fn_80273498, fn_8026D504 | none (tier C) |
