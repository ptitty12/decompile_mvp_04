/*
 * Types for animation/goals/tu_8027DE3C.cpp (reconstructed; placeholders).
 * Nothing here comes from original headers: layouts are inferred from the
 * offsets the functions of that unit use.
 */
#ifndef GAME_GOALS_TU_8027DE3C_H
#define GAME_GOALS_TU_8027DE3C_H

#include "game/chooser.h"

/* Bit view of the flag word at +0xE8 (fn_8027E070 inserts bit 8 from the MSB). */
struct Unk8027DE3C_Flags {
    unsigned int pad0 : 8;
    unsigned int f8 : 1;
    unsigned int rest : 23;
};

/* Object at Unk8027DE3C+0x4. Offsets seen: +0x28 (tested for zero in
 * fn_8027EA14), passed to fn_80290D1C. */
struct Unk8027DE3C_Owner {
    char pad0[0x28];
    int m28;
};

class Unk8027DE3C;

/* Goal object ("this" of the unit's functions). Offsets seen: +0x0 code
 * (passed to fn_8027FC20), +0x4 owner object, +0xC mode (0..4 in
 * fn_8027E084), +0x28 (tested for zero), +0x34 and +0x38 copied to the owner by
 * fn_8027E084, +0x78 state, +0x7C sub-state (1..4), +0x98 float, +0x9C/+0xA0
 * pair set by fn_8027DF88, fn_8027DFA8, fn_8027E008 and fn_8027E068,
 * +0xA4/+0xB0/+0xBC three float vectors, +0xC8 float, +0xE8 flag word. */
class Unk8027DE3C {
public:
    int m0;
    Unk8027DE3C_Owner* m4;
    char pad8[4];
    int mC;
    char pad10[0x1C - 0x10];
    float m1C;
    char pad20[4];
    float m24;
    int m28;
    char pad2C[0x78 - 0x2C];
    int m78;
    int m7C;
    char pad80[0x98 - 0x80];
    float m98;
    int m9C;
    int mA0;
    Unk80273498_Vec3 mA4;
    Unk80273498_Vec3 mB0;
    Unk80273498_Vec3 mBC;
    float mC8;
    char padCC[0xE8 - 0xCC];
    union {
        unsigned int mE8;
        Unk8027DE3C_Flags mE8bits;
    };

    void fn_8027DDE8(int a);                                   /* other unit */
    Unk8027DE3C* fn_8027DE3C(const Unk80273498_Vec3* a, const Unk80273498_Vec3* b);
    Unk8027DE3C* fn_8027DE88(const Unk80273498_Vec3* a, const Unk80273498_Vec3* b);
    Unk8027DE3C* fn_8027DED4();
    Unk8027DE3C* fn_8027DF08();
    Unk8027DE3C* fn_8027DF1C(int a);
    void fn_8027DF7C();
    Unk8027DE3C* fn_8027DF88(int a);
    Unk8027DE3C* fn_8027DFA8(int a);
    void fn_8027DFBC(int a, const Unk80273498_Vec3* v);
    Unk8027DE3C* fn_8027E008(int a);
    void fn_8027E01C(int a, const Unk80273498_Vec3* v);
    void fn_8027E068(int a);
    Unk8027DE3C* fn_8027E070(int a);

    int fn_8027EA14(Unk80270BA0_X* x);
    void fn_8027EB34(int st, Unk80270BA0_X* x);
    void fn_8027EC58(Unk80270BA0_X* x, int h);
    int fn_8027EE9C(Unk80270BA0_X* x, int h);
    float fn_8027EF48(float a);
    float fn_8027EFB8(Unk80270BA0_X* x, float a);
    void fn_8027F504(Unk80270BA0_X* x, int h, float f);
    float fn_8027F28C(Unk80270BA0_X* x, float a);
    int fn_8027FC20(int a);
    int fn_8027FC80(Unk80270BA0_X* x);

    int fn_802853E4();                                         /* other unit */
    float fn_80286F9C();                                       /* other unit */
    Unk80273498_Pos* fn_8027B304(Unk80270BA0_X* x);            /* other unit */
    int fn_80285498();                                         /* other unit */
    int fn_8027B1A0(Unk80270BA0_X* x, Unk80273498_Vec3* v);    /* other unit */
    Unk80273498_Vec3 fn_802850EC();                            /* other unit */
    Unk80273498_Vec3 fn_80286E70();                            /* other unit */
};

float __builtin_fabsf(float x);
float fn_80410CE8(float a, float b);                           /* other unit */
float fn_80382BB8(Unk80271DBC_Link* l);                        /* other unit (see tu_80272B20.cpp) */
float fn_80382BD8(Unk80271DBC_Link* l, int a);                 /* other unit */
extern float lbl_8061E6CC;                                     /* .data 0x8061E6CC = 0.6f */

/* Same helper as in animation/choosers/tu_80271F14.cpp and tu_80272B20.cpp
 * (to be shared when the unity TU is assembled). */
inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

void fn_80381B38(Unk80271DBC_Link* l);                         /* other unit */
void fn_80381E9C(Unk80271DBC_Link* l, int v, int a, int b);   /* other unit */
/* Slot reached through Unk8027DE3C_Holder+0x934: a goal embedded at +0x18,
 * valid when +0x10 is 6 (fn_8027F28C). */
struct Unk8027DE3C_Slot {
    char pad0[0x10];
    int m10;
    char pad14[4];
    Unk8027DE3C m18;
};
class Unk8027DE3C_Holder {
public:
    char pad0[0x934];
    Unk8027DE3C_Slot* m934;

    int fn_8026D940(int a);                                    /* other unit */
};
float fn_801DC5C4(int id);                                     /* other unit */
Unk8027DE3C_Holder* fn_801DC570(int id);                       /* other unit */
Unk80273498_Vec3 fn_80189618(Unk80273498_Pos* p, float f);     /* other unit */
int fn_8026DAA4(Unk80270BA0_X* x, int a);                      /* other unit */
Unk80273498_Vec3 fn_8018959C(Unk80273498_Pos* p, float f);     /* other unit */
extern int lbl_806242B4;                                       /* other units' .data */

int fn_80290D1C(Unk8027DE3C_Owner* o, Unk80270BA0_X* x);                        /* other unit */

#endif /* GAME_GOALS_TU_8027DE3C_H */
