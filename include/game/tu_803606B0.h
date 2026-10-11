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

#endif
