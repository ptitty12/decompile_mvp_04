/*
 * Types for game/tu_801C16B0.cpp (reconstructed, placeholder names). The player
 * object (Unk801B7FB0_P) is shared with game/tu_801B7FB0.cpp.
 */
#ifndef GAME_TU_801C16B0_H
#define GAME_TU_801C16B0_H

#include "game/tu_801B7FB0.h"

/* Empty helper class whose comparison methods take two ints (fn_801C184C and
 * the following predicates): `this` is unused. */
struct Unk801C16B0_Cmp {
    int pad0;
};

/* Object at Z::m4 (fn_801C21EC clears the word at +0x14 through a sub-struct
 * pointer at +8, as the compiler shows addi 8 / stw 0xC). */
struct Unk801C16B0_Sub8 {
    int m0;
    int m4;
    int m8;
    int mC;
    void SetC(int v) { mC = v; }
};
struct Unk801C16B0_M4 {
    char pad0[8];
    Unk801C16B0_Sub8 s8;
};

/* Sub-object at Z::m28C: a flag word and a mode (fn_801C2724). */
struct Unk801C16B0_Mode {
    int m0;
    int m4;
};

/* Play-state object (fn_801C2144, fn_801C21EC, fn_801C2724): the AI wrapper at
 * +4, the player context at +0x204, nested state helpers at +0xE0 and +0x20C. */
struct Unk801C16B0_Z {
    char pad0[4];
    Unk801C16B0_M4* m4;
    char pad8[0xE0 - 8];
    char mE0[4];
    char padE4[0x124 - 0xE4];
    int m124;
    char pad128[0x204 - 0x128];
    Unk801B7FB0_P* m204;
    int m208;
    char m20C[4];
    char pad210[0x288 - 0x210];
    int m288;
    Unk801C16B0_Mode m28C;
};

#endif
