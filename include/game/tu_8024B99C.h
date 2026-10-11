#ifndef GAME_TU_8024B99C_H
#define GAME_TU_8024B99C_H

#include "game/tu_8022FE34.h"
#include "game/goals/tu_8027C728.h"

/*
 * Player-object helpers at 0x80241C24-0x8024EF40 (units tu_80241C24, tu_80246D04,
 * tu_8024B99C). The object is Unk80270BA0_X (include/game/chooser.h); these
 * functions are free functions taking it, as the callers in the goal units declare
 * them. Unk8024B99C_V is a local view of the fields they touch (offsets from the asm):
 * +0x44C the AI context, +0x458 a state id, +0x708 an id passed to fn_801A2034,
 * +0x8D4/+0x8D8 and +0x8E0/+0x8E4 saturating counters (fn_8024BF04/BFD0), +0x8F8 and
 * +0x91C Vec3 copies (fn_8024D1A4/D178), +0x918 an int.
 */
struct Unk80270BA0_X;

struct Unk8024B99C_V3 {
    int a;
    int b;
    int c;
};

struct Unk8024B99C_V {
    char pad0[0x44C];
    Unk8022FE34_Ctx* m44C;
    char pad450[0x458 - 0x450];
    int m458;
    char pad45C[0x708 - 0x45C];
    int m708;
    char pad70C[0x8D0 - 0x70C];
    float m8D0;
    int m8D4;
    int m8D8;
    float m8DC;
    int m8E0;
    int m8E4;
    char pad8E8[0x8F8 - 0x8E8];
    Unk8024B99C_V3 m8F8;
    char pad904[0x918 - 0x904];
    int m918;
    Unk8024B99C_V3 m91C;
};

#endif
