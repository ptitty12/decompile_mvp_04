#ifndef GAME_TU_801B23A8_H
#define GAME_TU_801B23A8_H

#include "game/tu_801AB63C.h"

/*
 * Declarations for game/tu_801B23A8.cpp (reconstructed; placeholders only).
 */

/* Float block at +0x4D8 of the argument object (sum at +0x5C and +0x68). */
struct Unk801B23A8_F {
    char pad0[0x5C];
    float m5C;
    char pad60[0x68 - 0x60];
    float m68;
};

/* Argument object of the controller helpers: flags at +0x4C4/+0x4C8, floats at +0x4D8 and
 * +0x5D8, pointer-like tag at +0x588, state at +0x704/+0x708. */
struct Unk801B23A8_Q {
    char pad0[0x44C];
    void* m44C;
    char pad450[0x460 - 0x450];
    int m460;
    char pad464[0x4C4 - 0x464];
    unsigned m4C4;
    int m4C8;
    char pad4CC[0x4D8 - 0x4CC];
    Unk801B23A8_F m4D8;
    char pad544[0x588 - (0x4D8 + sizeof(Unk801B23A8_F))];
    char m588[4];
    char pad58C[0x5D8 - 0x58C];
    float m5D8;
    char pad5DC[0x704 - 0x5DC];
    int m704;
    int m708;
    char pad70C[0xA04 - 0x70C];
    void* mA04;
};

/* Controller seen through its slot table: m8 owner, 2 x 9 pointers at +0x14. */
struct Unk801B23A8_V {
    char pad0[8];
    Unk8019F8C0_Owner* m8;
    char padC[8];
    Unk801B23A8_Q* m14[2][9];
};

#endif
