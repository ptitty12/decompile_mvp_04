#ifndef GAME_TU_801A96E0_H
#define GAME_TU_801A96E0_H

#include "game/tu_8019F8C0.h"

/*
 * Declarations for game/tu_801A96E0.cpp (reconstructed; placeholders only).
 * One object (about 0x88 bytes, fields from 0xC) is seen through several
 * partial views, one per accessor group; the views overlap in the unknown
 * tail, so each function uses the view whose offsets it touches.
 */

struct Unk801A96E0_Sel {   /* fn_801A9B78..fn_801A9BC0 */
    char pad0[0xC];
    int mC;
    int m10;
    char pad14[0x24 - 0x14];
    int m24;
    int m28;
};

struct Unk801A96E0_Init {  /* fn_801AA248, fn_801AB188, fn_801AA570, fn_801A99B4.. */
    char pad0[8];
    Unk8019F8C0_Owner* m8;
    int mC;
    int m10;
    int m14[4];
    char pad24[0x24 - 0x24];
    int m24;
    int m28;
    int m2C[3];
    int m38[2];
    int m40[2];
    int m48[2];
    int m50[2];
    int m58;
    int m5C;
    int m60;
    int m64;
    int m68;
    int m6C;
};

struct Unk801A96E0_Late {  /* fn_801AB470, fn_801A9D48 */
    char pad0[8];
    Unk8019F8C0_Owner* m8;
    char padC[0x68 - 0xC];
    int m68;
    int m6C;
    int m70;
    int m74;
    int m78;
    float m7C;
};

struct Unk801A96E0_Pair {  /* fn_801A9D3C */
    char pad0[0x70];
    int m70;
    int m74;
};

#endif
