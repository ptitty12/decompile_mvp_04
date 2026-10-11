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

#endif
