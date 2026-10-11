/*
 * Types for animation/goals/tu_8028C6B8.cpp (reach goal logic, reconstructed,
 * placeholder names). Layouts come from the offsets that unit reads and writes;
 * nothing here is from original headers. Fields not listed are unknown.
 */
#ifndef GAME_GOALS_TU_8028C6B8_H
#define GAME_GOALS_TU_8028C6B8_H

#include "game/chooser.h"

extern "C" float fabsf(float x);          /* inlined as fabs */

extern int lbl_806242B4;
extern const char lbl_805DD780[];         /* "C:/mvp2004/source/common/animation/goals/reachgoal.cpp" */

/* A 32-bit flag word. fN is bit N counted from the most significant bit
 * (mask 0x80000000 >> N), as in tu_8027FD64.h. */
struct Unk8028C6B8_Flags {
    unsigned int f0 : 1, f1 : 1, f2 : 1, f3 : 1, f4 : 1, f5 : 1, f6 : 1, f7 : 1;
    unsigned int f8 : 1, f9 : 1, f10 : 1, f11 : 1, f12 : 1, f13 : 1, f14 : 1, f15 : 1;
    unsigned int f16 : 1, f17 : 1, f18 : 1, f19 : 1, f20 : 1, f21 : 1, f22 : 1, f23 : 1;
    unsigned int f24 : 1, f25 : 1, f26 : 1, f27 : 1, f28 : 1, f29 : 1, f30 : 1, f31 : 1;
};

/* Object at Unk8028C6B8_Goal::m4. Its methods are in the next unit
 * (0x8028F178..), only their addresses are known here. Evidence: the copies
 * of +0x34/+0x38/+0x40/+0xC in fn_8028F0F4 and fn_8028E7B0, the bitfield
 * stores at +0x18C. */
struct Unk8028F45C_Inner {
    int fn_8028F45C(Unk80273498_Vec3 v);
    void fn_8028F528(Unk80273498_Vec3 v);
    void fn_8028F588(float f);
    void fn_8028F5CC(float f);
    void fn_8028F5F4(float f);
    void fn_8028F610();
    void fn_8028F848();
    int fn_80290D1C(Unk80270BA0_X* x);
    void fn_8028F4B8(int a);

    char pad0[0xC];
    int mC;
    char pad10[0x28 - 0x10];
    int m28;
    char pad2C[0x34 - 0x2C];
    int m34;
    int m38;
    char pad3C[0x40 - 0x3C];
    int m40;
    char pad44[0x4C - 0x44];
    int m4C;
    char pad50[0x54 - 0x50];
    int m54;
    char pad58[0x78 - 0x58];
    float m78;
    char pad7C[0x98 - 0x7C];
    float m98;
    char pad9C[0x18C - 0x9C];
    Unk8028C6B8_Flags m18C;
};

/* Request/parameter part of the reach goal: filled by the setter methods
 * fn_8028ED00..fn_8028F068 (which return `this`) and forwarded to the object at
 * +0x4. */
struct Unk8028ED00_Req {
    int m0;
    Unk8028F45C_Inner* m4;
    char pad8[0x10 - 0x8];
    Unk80273498_Vec3 m10;
    char pad1C[0x28 - 0x1C];
    int m28;
    char pad2C[0x48 - 0x2C];
    int m48;
    float m4C;
    int m50;
    float m54;
    int m58;
    float m5C;
    int m60;

    void fn_8028ED00();
    Unk8028ED00_Req* fn_8028EEF4();
    Unk8028ED00_Req* fn_8028F01C(float f);
    Unk8028ED00_Req* fn_8028F068(float f);
    void fn_8028F0AC();
    void fn_8028F0D0();
};

#endif /* GAME_GOALS_TU_8028C6B8_H */
