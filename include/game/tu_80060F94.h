#ifndef GAME_TU_80060F94_H
#define GAME_TU_80060F94_H

#include "game/tu_8005DF2C.h"
#include "game/tu_80060250.h"

/*
 * 0x80060F94..0x80061C6C: action handlers with the signature
 * void f(A* a, O* out, Ctx* ctx): r3 is a handle whose first word is the
 * object passed to fn_8004CC8C / used for +0xA14, r4 is a record whose word at
 * +4 receives a constant id (0xF6, 0x55, 0xBC, 0x168, 0x144), r5 is the Ctx of
 * tu_8005DF2C.h. Handlers that do not use all three still take them.
 *
 * Unk80060F94_G0 / G1: the nested globals reached through lbl_806192E0
 * (->m4->m14 is the array of 0xE64-byte records indexed by +0x708 of the
 * Ctx's m3B0 object, as in tu_8005F4E4.cpp).
 */
struct Unk80060F94_G1;
struct Unk80060F94_G0;

struct Unk80060F94_G1 {
    char pad0[0x14];
    Unk8005DF2C_Y* m14;
};

struct Unk80060F94_G0 {
    char pad0[0x4];
    Unk80060F94_G1* m4;
};



#endif
