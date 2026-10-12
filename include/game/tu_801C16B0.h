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
    char pad18[0x3B0 - 0x18];
    void* m3B0;
    int m3B4;
    int m3B8;
    char pad3BC[0x418 - 0x3BC];
    int m418;
};

/* Pair of vectors at Z::m29C (stride 0x18); Z::m29C[1].a is at +0x2B4. */
struct Unk801C16B0_VP {
    Vec3 a;
    Vec3 b;
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
    char m8[0xE0 - 8];
    char mE0[4];
    char padE4[0xEC - 0xE4];
    int mEC;
    int mF0;
    int mF4;
    char padF8[0x118 - 0xF8];
    int m118;
    int m11C;
    int m120;
    int m124;
    int m128;
    int m12C;
    int m130;
    char pad134[0x13C - 0x134];
    float m13C;
    float m140;
    float m144;
    float m148;
    float m14C;
    float m150[2];
    char pad158[0x180 - 0x158];
    float m180;
    char pad184[0x1A8 - 0x184];
    int m1A8;
    int m1AC;
    Vec3 m1B0;
    char pad1BC[0x1C8 - 0x1BC];
    int m1C8;
    int m1CC;
    float m1D0;
    float m1D4;
    float m1D8;
    float m1DC[6];
    char pad1F4[0x1FC - 0x1F4];
    float m1FC;
    char pad200[0x204 - 0x200];
    Unk801B7FB0_P* m204;
    int m208;
    char m20C[4];
    char pad210[0x288 - 0x210];
    int m288;
    Unk801C16B0_Mode m28C;
    float m294;
    char pad298[0x29C - 0x298];
    Unk801C16B0_VP m29C[3];
};

#endif
