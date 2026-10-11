/*
 * Declarations for game/tu_8003AEE4.cpp (reconstructed, placeholder names).
 * The object type Unk8003A5DC is in tu_80039B04.h.
 */
#ifndef GAME_TU_8003AEE4_H
#define GAME_TU_8003AEE4_H

#include "game/tu_80039B04.h"

/* Record handed to fn_8003B0F4: old/new state pairs at +0xC/+0x10, +0x14/+0x18,
 * +0x1C/+0x20 and +0x24/+0x28 (compared pairwise there). */
struct Unk8003B0F4_Arg {
    char pad0[0xC];
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
};

void fn_8003AF68(Unk8003A5DC* self);
void fn_8003B008(Unk8003A5DC* self);

#endif
