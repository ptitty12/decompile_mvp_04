/*
 * Declarations for game/tu_8003DF80.cpp (reconstructed, placeholder names).
 * The object type Unk8003A5DC is in tu_80039B04.h.
 */
#ifndef GAME_TU_8003DF80_H
#define GAME_TU_8003DF80_H

#include "game/tu_80039B04.h"

/* Player-like record behind Unk8003A5DC::m130 (see Unk8003C9A0_Pl): the word
 * at +0x704 is compared with the two five-entry tables m1B8/m1CC in
 * fn_8003DF80; fn_8025416C takes the address + 0x588. */
struct Unk8003DF80_Pl {
    char pad0[0x704];
    int m704;
    int m708;
};

#endif
