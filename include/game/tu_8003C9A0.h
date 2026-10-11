/*
 * Declarations for game/tu_8003C9A0.cpp (reconstructed, placeholder names).
 * The object type Unk8003A5DC is in tu_80039B04.h.
 */
#ifndef GAME_TU_8003C9A0_H
#define GAME_TU_8003C9A0_H

#include "game/tu_80039B04.h"

/* Object behind Unk8003A5DC::m130 / m134 (a player-like record; Unk8003A5DC
 * keeps it as an int). Only the flag word at +0x590 is read here (fn_8003C9A0);
 * fn_8025416C is called with the object address + 0x588. */
struct Unk8003C9A0_Pl {
    char pad0[0x460];
    int m460;
    char pad464[0x590 - 0x464];
    unsigned int m590;
};

struct Unk805B1A8C_Ent {
    int m0;
    int m4;
};

int fn_8003D944(Unk8003A5DC* self, int id, int time, int a3, int a4);

#endif
