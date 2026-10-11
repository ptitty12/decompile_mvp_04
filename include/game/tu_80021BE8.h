/*
 * Types for game/tu_80021BE8.cpp (reconstructed; nothing here comes from original
 * headers). Shares the game-context types of tu_8001E444.h and the abstract table
 * class Unk80021A60 of tu_8001FDA8.h.
 */
#ifndef GAME_TU_80021BE8_H
#define GAME_TU_80021BE8_H

#include "game/tu_8001FDA8.h"

/* Object whose first three floats are used as a 2D position by fn_800222B4 callers. */
typedef Unk801A4B34_Vec3 Unk80021BE8_Vec3;

extern "C" {
void fn_800222B4(Unk8001F2C4_World* ctx, int* outX, int* outY, Unk801A4B34_Vec3 pos);
void fn_800412AC(Unk8004072C_Obj* o, int kind, int x, int y, int p, int q);
int fn_801C3F00(Unk8001F2C4_Inner* v);
int fn_8016ADC4();
}

#endif
