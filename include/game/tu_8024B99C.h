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

struct Unk8024B99C_Flags {
    unsigned pad : 3;
    unsigned m3 : 1;
    unsigned rest : 28;
};

struct Unk8024B99C_V {
    char pad0[0x44C];
    Unk8022FE34_Ctx* m44C;
    char pad450[0x458 - 0x450];
    int m458;
    char pad45C[0x5F4 - 0x45C];
    float m5F4;
    int m5F8;
    int m5FC;
    int m600;
    int m604;
    int m608;
    int m60C;
    int m610;
    char pad614[0x708 - 0x614];
    int m708;
    char pad70C[0x720 - 0x70C];
    float m720;
    float m724;
    float m728;
    float m72C;
    char pad730[0x8D0 - 0x730];
    float m8D0;
    int m8D4;
    int m8D8;
    float m8DC;
    int m8E0;
    int m8E4;
    float m8E8;
    float m8EC;
    char pad8F0[0x8F8 - 0x8F0];
    Unk8024B99C_V3 m8F8;
    char pad904[0x90C - 0x904];
    float m90C;
    int m910;
    int m914;
    int m918;
    Unk8024B99C_V3 m91C;
    char pad928[0x934 - 0x928];
    Unk8027C728_Goal* m934;
    char pad938[0xAE0 - 0x938];
    int mAE0;
    float mAE4;
    int mAE8;
    char padAEC[0xB0C - 0xAEC];
    int mB0C;
    float mB10;
    float mB14;
    float mB18;
    char padB1C[0xB3C - 0xB1C];
    Unk8024B99C_Flags mB3C;
};

#endif
