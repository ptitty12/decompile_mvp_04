/*
 * Types shared by game/tu_802F8324.cpp .. game/tu_80313C14.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * The code is the batter/pitcher gameplay block (cBatterPitcher and friends,
 * chooser classes with vtables in .data). Functions are written as extern "C"
 * functions taking the object explicitly and storing the retail vtable
 * (lbl_ data object) by hand, so no vtables are emitted in code-only units.
 */
#ifndef GAME_TU_802F8324_H
#define GAME_TU_802F8324_H

#include "game/chooser.h"
#include "game/tu_8001B190.h"
#include "game/tu_8000C2C4.h"

inline void* operator new(unsigned int, void* p) { return p; }

struct Unk802F8324_V2 {
    float x;
    float y;
};

#endif /* GAME_TU_802F8324_H */
