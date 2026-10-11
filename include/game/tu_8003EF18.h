/*
 * Declarations for game/tu_8003EF18.cpp (reconstructed, placeholder names).
 * The object type Unk8003A5DC is in tu_80039B04.h.
 */
#ifndef GAME_TU_8003EF18_H
#define GAME_TU_8003EF18_H

#include "game/tu_80039B04.h"

/* One of the two 0xE64-byte records at Unk8003B3F4_Sub14 +0 / +0xE64 (the
 * array ends at 0x1CC8, where Unk8003B3F4_Sub14::m1CC8 sits). +0x8C is handed
 * to fn_8009E1D4; the 0x80 bytes at +0x1B4 are summed by fn_8003FC18..FFC4. */
struct Unk8003FC18_Entry {
    char pad0[0x8C];
    char m8C[0x1B4 - 0x8C];
    unsigned char m1B4[0x80];
    char pad234[0xE64 - 0x234];
};

#endif
