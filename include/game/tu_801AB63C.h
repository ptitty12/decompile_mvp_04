#ifndef GAME_TU_801AB63C_H
#define GAME_TU_801AB63C_H

#include "game/tu_8019F8C0.h"

/*
 * Declarations for game/tu_801AB63C.cpp (reconstructed; placeholders only).
 */

/* Entry of the 0x14-byte table at +0x60 of the controller (fn_801AE008, fn_801AE018). */
struct Unk801AB63C_Ent {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

/* Controller object: m4 helper, m8 game-flow owner, m5C counter, table at 0x60. */
struct Unk801AB63C_P {
    int m0;
    void* m4;
    Unk8019F8C0_Owner* m8;
    char padC[0x5C - 0xC];
    int m5C;
    Unk801AB63C_Ent m60[1];
};

/* Argument object read by the controller: index at +0x708, flags at +0x4D0. */
struct Unk801AB63C_Q {
    char pad0[0x4D0];
    int m4D0;
    char pad4D4[0x708 - 0x4D4];
    int m708;
};

#endif
