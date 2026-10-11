#ifndef GAME_TU_80060250_H
#define GAME_TU_80060250_H

#include "game/tu_8005DF2C.h"
#include "game/tu_8005F4E4.h"

/*
 * 0x80060250..0x80060F94: more Ctx score functions (see tu_8005DF2C.h), plus
 * fn_800605E8, which returns a 0x18-byte record by value (hidden pointer in
 * r3) read from fn_80326F44 and used by the four flag tests that follow it
 * (bits 0x1000..0x8000 of word 5).
 */
struct Unk80060250_S;
struct Unk80060250_O;

struct Unk80060250_S {
    int m0;
    char pad4[0x10];
    int m14;
};

struct Unk80060250_O {
    char pad0[0x4];
    int m4;
};



#endif
