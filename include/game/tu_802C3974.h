/*
 * Types for game/tu_802C3974.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_802C3974_H
#define GAME_TU_802C3974_H

#include "game/tu_802BF974.h"

/* 0x30-byte element of the array at +0x24C of Unk802C3B60 (fn_802C4030 clears +0x1C..+0x2C of each). */
struct Unk802C40A0_Elem {
    char pad0[0x1C];
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

/* Texture conversion set (ctor fn_802C3B60, deleting dtor fn_802C3C08, vptr at +0x288 = vtable 0x80664238):
 * three Unk802C2188 converters at +0, +0xBC, +0x178, a lazily created fourth at +0x234.
 * Evidence: fn_802C3B60, fn_802C3C08, fn_802C4100, fn_802C41A0. */
struct Unk802C3B60 {
    Unk802C2188 s0;
    Unk802C2188 s1;
    Unk802C2188 s2;
    Unk802C2188* m234;
    int m238;
    int m23C;
    int m240;
    int m244;
    int m248;
    int m24C;
    int m250;
    int m254;
    int m258;
    int m25C;
    int m260;
    int m264;
    int m268;
    int m26C;
    int m270;
    int m274;
    int m278;
    int m27C;
    int m280;
    int m284;
    const void* m288;
};

void fn_802C40A0(Unk802C3B60*, Unk802C40A0_Elem* e);

#endif
