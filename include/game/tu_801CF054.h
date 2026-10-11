/*
 * Types for game/tu_801CF054.cpp (reconstructed, placeholder names). The player
 * object (Unk801B7FB0_P) is shared with game/tu_801B7FB0.cpp.
 */
#ifndef GAME_TU_801CF054_H
#define GAME_TU_801CF054_H

#include "game/tu_801C16B0.h"

/* Batter-AI state helper: the word at +4 is a state number 0..7 that the
 * predicates fn_801D0294..fn_801D0368 classify. */
struct Unk801CF054_Y {
    char pad0[4];
    int m4;
    char pad8[0x28 - 8];
    int m28;
    void* m2C;
    void* m30;
    void* m34;
    int m38;
    char pad3C[8];
    char m44[0x28];
    char m6C[4];
    char pad70[0x1F4 - 0x70];
    int m1F4;
};

#endif
