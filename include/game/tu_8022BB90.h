/*
 * Types for src/game/tu_8022BB90.cpp (0x8022BB90..0x8022FE34, reconstructed).
 * Nothing here comes from original headers; layouts are inferred from the
 * functions in that unit. Names are placeholders (Unk<addr>, m<offset>).
 */
#ifndef GAME_TU_8022BB90_H
#define GAME_TU_8022BB90_H

#include "game/tu_8020EE9C.h"

struct Pair8 {
    float x;
    float y;
};

struct Pair438 {
    int m0;
    int m4;
    void Clear()
    {
        m4 = 0;
        m0 = 0;
    }
};
struct Sub440 {
    char pad0[0x734 - 0x440];
};
struct Sub38 {
    char pad0[0x22C - 0x38];
};

/* Data object of 0x73C bytes built by fn_8022F17C (new(0x73C) in fn_8022E680)
 * and held at Fe8022::m4. */
struct Fe73C {
    int m0;
    void* m4;
    int m8;
    int mC;
    float m10;
    float m14;
    int m18;
    int m1C;
    Pair8 m20;
    Pair8 m28;
    Pair8 m30;
    Sub38 m38; /* sub-object (fn_8022FF2C) */
    float m22C[1];
    char pad230[0x430 - 0x230];
    int m430;
    int m434;
    Pair438 m438;
    Sub440 m440; /* sub-object (fn_802376A0) */
    int m734;                 /* sub-object (fn_802361C0) */
    int m738;
};

/* Context objects reached through Fe8022::m8 (fn_8022E998). */
struct FeCtxB {
    char pad0[0x65C];
    Player* m65C;
    char pad660[0x6F4 - 0x660];
    int m6F4;
};
struct FeCtxA {
    int m0;
    FeCtxB* m4;
    char pad8[0x3B4 - 8];
    void* m3B4;
};
struct FeObj84 {
    char pad0[0x84];
    int m84;
};

/* Object returned by fn_80235FA8. */
struct FeOther {
    char pad0[0x6F4];
    int m6F4;
    char pad6F8[0x720 - 0x6F8];
    int m720;
};

/* Sub-object at Fe8022+0xC (initialised by fn_8035DC00). */
struct FeSub {
    char pad0[0x3C];
    int m3C;
    int m40;
    char pad44[0x54 - 0x44];
};

/* Object with a vptr at +0 (lbl_80660D80) and the data object at +4. */
struct Fe8022 {
    void* vptr;
    Fe73C* m4;
    FeCtxA* m8;
    FeSub mC;
    int m60;
    int m64;
    short m68;
    char pad6A[2];
    float m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
    int m80;
};

#endif
