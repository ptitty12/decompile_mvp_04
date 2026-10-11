/*
 * Types for animation/goals/tu_8028989C.cpp (reconstructed; placeholders).
 * Nothing here comes from original headers: layouts are inferred from the
 * offsets the functions of that unit use.
 */
#ifndef GAME_GOALS_TU_8028989C_H
#define GAME_GOALS_TU_8028989C_H

#include "game/chooser.h"

extern const Unk80273498_Vec3 lbl_806055AC;    /* zero vector */

/* Handle whose method fn_8014E388 returns a position (called by fn_80289944). */
struct Unk8014E388_H {
    char pad0[4];
};

/* Goal parameter block ("this" of the unit's first functions). Offsets seen:
 * +0 type (6 after fn_8028989C), +0xC mode (compared with 1 and 2), +0x10 target
 * position, +0x1C direction, +0x28 "has target" flag, +0x48 kind (1..6), +0x4C
 * sub-kind, +0x50..+0x6C floats, +0x70 flag. */
struct Unk8028989C_Goal {
    int m0;
    char pad4[0xC - 4];
    int mC;
    Unk80273498_Vec3 m10;
    Unk80273498_Vec3 m1C;
    int m28;
    char pad2C[0x40 - 0x2C];
    int m40;
    char pad44[0x48 - 0x44];
    int m48;
    int m4C;
    float m50;
    Unk80273498_Vec3 m54;
    float m60;
    float m64;
    float m68;
    float m6C;
    int m70;
};

/* Functions of other units used here. */
float fn_80410CE8(float x, float z);                       /* heading of (x, z) */
void fn_80244858(Unk80270BA0_X* x, float angle);
void fn_80242E6C(Unk80270BA0_X* x);
void fn_80381E9C(Unk80271DBC_Link* link, int hash, int a, int b);

#define UNK8028989C_STATE_A 0x75027FEF

#endif /* GAME_GOALS_TU_8028989C_H */
