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
    Unk801B7FB0_P* m30;
    void* m34;
    int m38;
    char pad3C[8];
    char m44[0xC];
    float m50;
    float m54;
    char pad58[0x6C - 0x58];
    char m6C[4];
    char pad70[0x1F4 - 0x70];
    int m1F4;
};

/* Object at game->mC->mC (Unk80087A58_O in game/tu_80087A58.h): only +0x174C is read here. */
struct Unk801CF054_O {
    char pad0[0x174C];
    int m174C;
};

#endif
