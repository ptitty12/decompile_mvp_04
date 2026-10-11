#ifndef GAME_TU_8005EDCC_H
#define GAME_TU_8005EDCC_H

#include "game/tu_8005DF2C.h"

/*
 * 0x8005EDCC..0x8005F4E4: more float score functions on the Ctx record of
 * tu_8005DF2C.h (same signature: arg, int, int, Ctx*), plus a helper
 * (fn_8005F0AC) that scans three 0x18-byte entries at +0x3D48 of the object
 * returned by fn_801A6D84 and returns 100.0 for the first one that satisfies
 * a predicate, with five thin wrappers that pass it one predicate each.
 *
 * Unk8005EDCC_Ent: 0x18 bytes; fn_8005F0AC treats m0 == 0xC7 as "empty" and
 * fn_8005F140/158/170/188 test flag bits of m14.
 */
struct Unk8005EDCC_Ent;
struct Unk8005EDCC_T;
struct Unk8005EDCC_G;

struct Unk8005EDCC_Ent {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

struct Unk8005EDCC_T {
    char pad0[0x3D48];
    Unk8005EDCC_Ent m3D48[3];
};

struct Unk8005EDCC_G {
    char pad0[0x3E4];
    int m3E4;
};



#endif
