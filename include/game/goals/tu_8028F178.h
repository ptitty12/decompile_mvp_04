/*
 * Types for animation/goals/tu_8028F178.cpp (goal logic, reconstructed).
 * Nothing here comes from original headers: layouts are inferred from the
 * offsets that unit reads and writes. Names are placeholders.
 */
#ifndef GAME_GOALS_TU_8028F178_H
#define GAME_GOALS_TU_8028F178_H

#include "game/chooser.h"
#include "game/goals/tu_8027A84C.h"

extern "C" float fabsf(float x);          /* inlined as fabs */

struct Unk8028F178_Goal;

/* Owner of the goals (same object as Unk8027A84C_Owner, which has a pad where
 * +0x14 is read here). Evidence: fn_8028F178 reads +0x14; fn_8028FAEC reads +0x0;
 * fn_80290274 / fn_80290B78 / fn_80290D3C read +0x10 (a goal-kind selector, 6 or
 * 10) and take the goal storage at +0x18 when it matches. */
struct Unk8028F178_Owner {
    Unk8028F178_Owner* m0;
    char pad4[0x10 - 0x4];
    int m10;
    int m14;
    char m18[4];
};

/* Request record written by fn_8028F178 (only +0xD8 is touched here). */
struct Unk8028F178_Req {
    char pad0[0xD8];
    int mD8;
};

/* The flag word at +0x18C of the goal. fN is bit N counted from the most
 * significant bit (mask 0x80000000 >> N). The top byte is written as a whole
 * (`stb`) by fn_8028F34C. */
struct Unk8028F178_Flags {
    int top : 8;
    unsigned int f8 : 1, f9 : 1, f10 : 1, f11 : 1, f12 : 1, f13 : 1, f14 : 1, f15 : 1;
    unsigned int f16 : 1, f17 : 1, f18 : 1, f19 : 1, f20 : 1, f21 : 1, f22 : 1, f23 : 1;
    unsigned int f24 : 1, f25 : 1, f26 : 1, f27 : 1, f28 : 1, f29 : 1, f30 : 1, f31 : 1;
};

/* Goal object (this of every function here; r3, or r4 when a Vec3 is returned).
 * Evidence: offsets used by fn_8028F178..fn_80291378. The first 0x4C bytes are
 * the Unk8027A84C base (calls to its members cast to it); +0x10 is a Vec3 here
 * where Unk8027A84C only knows padding. The goal's +0x4 points to the root
 * goal (owner+0x104) and +0x48 to its active goal. */
struct Unk8028F178_Goal {
    int m0;
    Unk8028F178_Goal* m4;
    char pad8[0xC - 0x8];
    int mC;
    Unk80273498_Vec3 m10;
    Unk80273498_Vec3 m1C;
    int m28;
    int m2C;
    char pad30[0x34 - 0x30];
    int m34;
    int m38;
    char pad3C[0x40 - 0x3C];
    int m40;
    Unk8028F178_Owner* m44;
    Unk8028F178_Goal* m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    int m5C;
    char pad60[0x6C - 0x60];
    float m6C;
    float m70;
    float m74;
    float m78;
    float m7C;
    float m80;
    float m84;
    float m88;
    Unk80273498_Vec3 m8C;
    int m98;
    char pad9C[0x158 - 0x9C];
    float m158;
    float m15C;
    int m160;
    Unk80273498_Vec3 m164;
    Unk80273498_Vec3 m170;
    int m17C;
    int m180;
    float m184;
    float m188;
    Unk8028F178_Flags m18C;

    /* Vector at +0x10 returned by value (a temp copy, as in fn_8028F610). */
    Unk80273498_Vec3 fn_GetM10() { return m10; }
};

/* Same object as Unk8014D8AC_Ctx (reached through Unk80270BA0_X::m44C) with the
 * fields this unit reads; callers cast. Evidence: fn_8028F610 (+0x4C, a frame
 * counter converted to seconds), fn_80290D3C (+0x4C, +0x6CC), fn_80291378. */
struct Unk8028F178_Ctx {
    char pad0[0x4C];
    unsigned int m4C;
    char pad50[0x6CC - 0x50];
    Unk80273498_Pos* m6CC;
};

int fn_802977FC(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8028F178_Req* r, int a, int b, int c, int d, float f);
void fn_802987C8(Unk8028F178_Goal* a, Unk8028F178_Goal* b);

int fn_8029771C(Unk8028F178_Goal* g);
float fn_80249298(Unk80270BA0_X* x, int a, int b);

Unk80273498_Vec3 fn_80297614(Unk8028F178_Goal* g);
int fn_80297668(Unk8028F178_Goal* g);
Unk80273498_Vec3 fn_802976A8(Unk8028F178_Goal* g);
int fn_8026DC18(Unk80270BA0_X* x, int a);

#endif /* GAME_GOALS_TU_8028F178_H */
