#ifndef GAME_TU_803606B0_H
#define GAME_TU_803606B0_H

#include "game/tu_8034B370.h"

/*
 * Shared types for the game tail 0x803606B0..0x803663B0 (range 30).
 */

/* Float variant of the ring container of tu_8034B370.h (fn_803624D0 ..
 * fn_803626B8): m0 is the element buffer, m4 the count, mC the cursor; the
 * polymorphic variant has its vptr at +0x10 (virtual 3 returns the current
 * element). Evidence: the float getters fn_803624D0 / fn_803624E4 /
 * fn_8036250C mirror the int ones fn_80362114 / fn_80362128 / fn_80362150. */
struct Unk803624D0 {
    float* m0;
    unsigned m4;
    int m8;
    unsigned mC;
};
struct Unk803624D0V : Unk803624D0 {
    virtual void v1();
    virtual void v2();
    virtual float v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

/* Game-flow task wrappers (tu_80360C18): a task holds its owner at +0 and its
 * vptr (lbl_80667118) at +4. The owner is a class whose vptr sits at +0x18
 * (virtual 5 steps the owner), with a state word at +0x74 and a mode word at
 * +0x80. Evidence: fn_80361034 .. fn_80361494 loop `while (owner->m74 == 2)`
 * around fn_800A2F9C(owner, 1) after calling virtual 5. */
struct Unk80361034_Pad18 {
    char pad[0x18];
};
struct Unk80361034_OwnV : Unk80361034_Pad18 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
struct Unk80361034_Own : Unk80361034_OwnV {
    char pad1C[0x74 - 0x1C];
    int m74;
    char pad78[0x80 - 0x78];
    int m80;
};
struct Unk80361034 {
    Unk80361034_Own* m0;
    const void* m4;
};
extern "C" int fn_800A29C4(Unk80361034_Own* o, int a);
extern "C" int fn_800A2948(Unk80361034_Own* o);
extern "C" int fn_800A2F9C(Unk80361034_Own* o, int a);
extern "C" int fn_800A3270(Unk80361034_Own* o, int* a, int* b);
extern "C" void fn_8055EAFC(int a);
extern "C" int fn_800A1A6C(Unk80361034_Own* o);
extern "C" int fn_800A2EFC(Unk80361034_Own* o);
extern "C" int fn_800A1B20(Unk80361034_Own* o);
extern "C" int fn_800A2E90(Unk80361034_Own* o);
extern "C" int fn_800A3430(Unk80361034_Own* o);

#endif
