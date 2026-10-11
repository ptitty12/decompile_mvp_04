/*
 * Types for game/tu_801D31D8 (batter AI, /mvp2004/source/common/ai/batter/
 * batteraicpu.cpp per the strings passed to fn_8014D8AC). Reconstructed from
 * field offsets only; names are placeholders.
 */
#ifndef GAME_TU_801D31D8_H
#define GAME_TU_801D31D8_H

#include "game/chooser.h"

/* Block at Unk801D31D8::m44 reset by fn_801D5C1C and its clones (float value varies). */
struct Unk801D31D8_Blk {
    int m0;
    float m4;
    int m8;
    float mC;
    float m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    float m24;
    void Clear(float f)
    {
        m20 = 0;
        m24 = f;
        m4 = f;
        m8 = 0;
        mC = f;
        m10 = f;
        m14 = 0;
        m18 = 0;
        m1C = 0;
    }
};

struct Unk801D31D8_T2 {
    char pad0[0x1CD0];
    int m1CD0;
};
struct Unk801D31D8_T {
    char pad0[0x14];
    Unk801D31D8_T2* m14;
};
struct Unk801D31D8_X700 {
    char pad0[0x3B0];
    int m3B0;
};
struct Unk801D31D8_Obj;

/* Game context at Unk801D31D8::m30 (only the fields read here). */
struct Unk801D31D8_Game {
    char pad0[0x4C];
    unsigned m4C;
    char pad50[0x554 - 0x50];
    Unk8014D8AC* m554;
    char pad558[0x6CC - 0x558];
    Unk801D31D8_Obj* m6CC;
    char pad6D0[0x6F4 - 0x6D0];
    int m6F4;
    Unk801D31D8_T* m6F8;
    char pad6FC[0x700 - 0x6FC];
    Unk801D31D8_X700* m700;
};

/* Two float pairs (blend state), sub-object at Unk801D31D8::m6C. */
struct Unk801D31D8_Pair {
    float m0[2];
    float m8[2];
};

/* Batter AI object. */
struct Unk801D31D8 {
    char pad0[0x2C];
    void* m2C;
    Unk801D31D8_Game* m30;
    char pad34[4];
    int m38;
    int m3C;
    int m40;
    Unk801D31D8_Blk m44;
    Unk801D31D8_Pair m6C;
};

#endif
