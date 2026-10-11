#ifndef GAME_TU_8034B370_H
#define GAME_TU_8034B370_H

#include "game/tu_803401A8.h"

/*
 * Shared types for the game tail 0x8034B370..0x80355A6C (range 27).
 */

/* Release family (fn_8034BBD0 and 151 clones): *pp points to an object whose
 * first word is an observer list (fn_803BA44C counts it, fn_803BA378 drops it);
 * the object is freed through virtual 2 of the allocator (vtable entry 2:
 * lha delta at +0x10, lwz pfn at +0x14) and *pp is cleared.  The release only
 * happens when the count is <= 1 or flag == 1. */
struct Unk803BA44C_Obj {
    void* m0;
};
int fn_803BA44C(void* list, int* count);
int fn_803BA378(void* list);

/* Ring / array containers (fn_80353244 .. fn_80353F58 and the clones at
 * 0x80354xxx, 0x80355xxx, five instantiations of the same template): m0 is the
 * element buffer, m4 the element count, mC the cursor; a polymorphic variant
 * has its vptr at +0x10 (Unk80353ECC). Evidence: the getter/setter pair
 * fn_80353244 / fn_80353DA4, the wrap-around steps fn_80353880 / fn_80353F00
 * (unsigned modulo of mC by m4) and the virtual wrappers fn_80353ECC / F24. */
struct Unk80353E68 {
    int* m0;
    unsigned m4;
    int m8;
    unsigned mC;
};
struct Unk80353ECC : Unk80353E68 {
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

void fn_80377408(void* p);
void fn_80377488(void* p);

#endif
