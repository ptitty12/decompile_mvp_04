#ifndef GAME_TU_8005F4E4_H
#define GAME_TU_8005F4E4_H

#include "game/tu_8005DF2C.h"

/*
 * 0x8005F4E4..0x80060250: more Ctx score functions (see tu_8005DF2C.h).
 *
 * Unk8005F4E4_G: the object returned by fn_800B555C(); fn_800B57EC() is a
 * predicate on it, and the 16 bytes at +0x688 are copied to a stack record
 * whose first word is compared with -1 (fn_8005FC04, FD4C, FF24 and the two
 * differences that call them).
 */
struct Unk8005F4E4_Id16;
struct Unk8005F4E4_G;
struct Unk8005F4E4_Buf;

struct Unk8005F4E4_Id16 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Unk8005F4E4_G {
    char pad0[0x688];
    Unk8005F4E4_Id16 m688;
};

struct Unk8005F4E4_Buf {
    int m0;
    char pad4[0x4];
    int m8;
    char padC[0x4];
};



#endif
