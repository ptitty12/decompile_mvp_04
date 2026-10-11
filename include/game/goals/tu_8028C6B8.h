/*
 * Types for animation/goals/tu_8028C6B8.cpp (reach goal logic, reconstructed,
 * placeholder names). Layouts come from the offsets that unit reads and writes;
 * nothing here is from original headers. Fields not listed are unknown.
 */
#ifndef GAME_GOALS_TU_8028C6B8_H
#define GAME_GOALS_TU_8028C6B8_H

#include "game/chooser.h"
#include "game/goals/tu_8027FD64.h"   /* AngleDiff, Length */

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

/* Position holder behind Ctx::m6CC; its +0x36C is the player object
 * (fn_8028D0EC). */
struct Unk8028C6B8_Pos6CC {
    char pad0[0x36C];
    Unk80270BA0_X* m36C;
};

/* Context object behind the player (Unk80270BA0_X::m44C, same object as
 * Unk8014D8AC_Ctx). Evidence: fn_8028EE4C and fn_8028D8D8 pass +0x6B8 to
 * fn_801837F4; fn_8028D0EC reads +0x554 (RNG) and +0x6CC. */
struct Unk8028C6B8_Ctx {
    char pad0[0x554];
    Unk8014D8AC* m554;
    char pad558[0x6B8 - 0x558];
    void* m6B8;
    char pad6BC[0x6CC - 0x6BC];
    Unk8028C6B8_Pos6CC* m6CC;
};

/* Angle/state block at Unk80270BA0_X+0x734 (same object as Unk802726BC_Angles):
 * pairs of slots indexed by m190 (0 or 1). Evidence: the slot writes in
 * fn_8028C6B8 (float slots +0x98 and +0xB8, int slots +0xA0, +0xA8, +0xC8,
 * +0xF0, +0x160, +0x180). */
struct Unk8028C6B8_Angles {
    char pad0[0x98];
    float m98[2];
    int mA0[2];
    int mA8[2];
    char padB0[0xB8 - 0xB0];
    float mB8[2];
    char padC0[0xC8 - 0xC0];
    int mC8[2];
    char padD0[0xF0 - 0xD0];
    int mF0[2];
    char padF8[0x160 - 0xF8];
    int m160[2];
    char pad168[0x180 - 0x168];
    int m180[2];
    char pad188[0x190 - 0x188];
    int m190;
};

/* Link object at Unk80270BA0_X::m618 (same object as Unk80271DBC_Link):
 * fn_8028D4E4 and fn_8028C6B8 read an id at +0x838 and +0x83C. */
struct Unk8028C6B8_Link {
    char pad0[0x838];
    int m838;
    int m83C;
};

/* The player object (Unk80270BA0_X) with the fields this unit reads. The
 * functions here take it by pointer only. Evidence: fn_8028F0F4 (+0x44C, +0x458
 * unsigned compare), fn_8028EF98 (float at +0x724), fn_8028D8D8 (+0x708),
 * fn_8028D808 (+0x58C passed to fn_8025596C). */
struct Unk8028C6B8_X {
    char pad0[0x60];
    Unk80273498_Vec3 m60;
    char pad6C[0x44C - 0x6C];
    Unk8028C6B8_Ctx* m44C;
    char pad450[0x458 - 0x450];
    unsigned int m458;
    char pad45C[0x58C - 0x45C];
    char m58C[4];
    char pad590[0x618 - 0x590];
    Unk8028C6B8_Link* m618;
    char pad61C[0x708 - 0x61C];
    int m708;
    char pad70C[0x724 - 0x70C];
    float m724;
    char pad728[0x734 - 0x728];
    Unk8028C6B8_Angles m734;

    /* Inline by-value getter: passing its result gives retail's direct temp. */
    Unk80273498_Vec3 fn_GetPos() { return m60; }
};
void fn_8025596C(void* p, int n);
float fn_80248FC8(Unk8028C6B8_X* x, int a);
float fn_80410CE8(float a, float b);
float fn_80382BB8(Unk8028C6B8_Link* p);
Unk80273498_Vec3 fn_8014E388(int a);

/* Heading of the player relative to pi/2. fn_8028DA0C calls it and drops the
 * result; the inline form is what gives retail's dead temp slot. */
inline float Unk8028DA0C_FacingDiff(Unk8028C6B8_X* x)
{
    float d = AngleDiff(fn_80382BB8(x->m618), 1.5707964f);
    return d;
}

/* Reads the float at +0x540 of the object returned by the virtual call in
 * fn_8028D0EC (a player, Unk80270BA0_X). */
inline float Unk8028D0EC_M540(Unk80270BA0_X* r)
{
    return *(float*)((char*)r + 0x540);
}

/* Animation/path state object at Goal::m8 (class name from the mangled
 * callee names in symbols.txt). */
class Unk8027A05C {
public:
    void fn_8027A17C(int a, int b, int c, int d);
    void fn_8027A078();
    void fn_8027A0B8(float a, float b, float c);
    void fn_8027A148(unsigned char a);
    float fn_8027A280(int a);
    Unk80273498_Vec3 fn_8027A358(int a);
};

/* Object at Unk8028C6B8_Goal::m4. Its methods are in the next unit
 * (0x8028F178..), only their addresses are known here. Evidence: the copies
 * of +0x34/+0x38/+0x40/+0xC in fn_8028F0F4 and fn_8028E7B0, the bitfield
 * stores at +0x18C. */
struct Unk8028F45C_Inner {
    int fn_8028F45C(Unk80273498_Vec3 v);
    void fn_8028F528(Unk80273498_Vec3 v);
    void fn_8028F5CC(float f);
    void fn_8028F5F4(float f);
    void fn_8028F610();
    void fn_8028F848();
    int fn_80290D1C(Unk8028C6B8_X* x);
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
    int m98;
    char pad9C[0x18C - 0x9C];
    Unk8028C6B8_Flags m18C;

    /* Inline setter: its float parameter gets a stack slot of its own. */
    void fn_SetM78(float f) { m78 = f; }
};

/* Owner of the goals (Goal::m44); fn_8028E9E8 reads an int at +0x14. */
struct Unk8028C6B8_Owner {
    char pad0[0x14];
    int m14;
};

/* The reach goal. Evidence: the offsets used by every function of this unit.
 * The setter methods (fn_8028ED00..fn_8028F0D0) and the update logic
 * (fn_8028C6B8..fn_8028E9E8) share the object: m4 points to the object the
 * setters forward to, m8 to the animation state. +0x4C and +0x60 are read
 * as int in some functions and float in others. */
struct Unk8028C6B8_Goal {
    int m0;
    Unk8028F45C_Inner* m4;
    Unk8027A05C* m8;
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
    Unk8028C6B8_Owner* m44;
    int m48;
    union {
        int m4C;
        float m4CF;
    };
    int m50;
    float m54;
    int m58;
    float m5C;
    union {
        float m60;
        int m60I;
    };
    float m64;
    float m68;
    float m6C;
    float m70;
    char pad74[0x78 - 0x74];
    int m78;
    char pad7C[0xA8 - 0x7C];
    Unk8028C6B8_Flags mA8;

    void fn_8028ED00();
    Unk8028C6B8_Goal* fn_8028EEF4();
    Unk8028C6B8_Goal* fn_8028ED30(Unk80273498_Vec3 v);
    Unk8028C6B8_Goal* fn_8028EDD0(int idx);
    Unk8028C6B8_Goal* fn_8028EE4C(int idx, Unk80273498_Vec3* pos);
    Unk8028C6B8_Goal* fn_8028EF14(Unk80273498_Vec3 v);
    Unk8028C6B8_Goal* fn_8028EF98(float f);
    void fn_8028F0F4(Unk8028C6B8_X* x);
    void fn_8028D0EC(Unk8028C6B8_X* x, Unk8028C6B8_Ctx* ctx);
    void fn_8028D200(Unk8028C6B8_X* x, int c);
    int fn_8028D8D8(Unk8028C6B8_X* x);
    void fn_8028D808(Unk8028C6B8_X* x, int c);
    int fn_8028D4E4(int mode, Unk8028C6B8_X* x, int c);
    void fn_8028C6B8(Unk8028C6B8_X* x, int c);
    void fn_8028E7B0(Unk8028C6B8_X* x);
    int fn_8028E944(Unk8028C6B8_X* x, int c);
    int fn_8028E9E8(Unk8028C6B8_Goal* other, Unk8028C6B8_X* x);
    int fn_8028C560(int a, int b);
    void fn_8027AD3C(Unk8028C6B8_X* x, int c, Unk80273498_Vec3* outPos, float* outHeading, float* outSpeed, int* outA, int* outB, int* outC);

    /* Methods of the goal base (animation/goals/tu_8027A84C.cpp). */
    Unk8028C6B8_X* fn_8027A90C();
    Unk8014D8AC_Ctx* fn_8027A918();
    Unk80273498_Vec3 fn_8027AF54(unsigned int idx);
    void fn_8027A898(Unk80273498_Vec3 v);
    void fn_8027AFA8(Unk8028C6B8_Ctx* ctx, Unk8028C6B8_X* x, int a);

    /* Inline setter: the by-value parameter gives the temp copy of retail. */
    void fn_SetTarget(Unk80273498_Vec3 v) { m10 = v; }
    /* Inline by-value getters: passing their result gives retail's direct frame copy. */
    Unk80273498_Vec3 fn_GetTarget() { return m10; }
    Unk80273498_Vec3 fn_GetM1C() { return m1C; }
    Unk8028C6B8_Goal* fn_8028F01C(float f);
    Unk8028C6B8_Goal* fn_8028F068(float f);
    void fn_8028F0AC();
    void fn_8028F0D0();
};

unsigned int fn_8028E73C(void* g, int k);
/* Same function as Unk8028F45C_Inner::fn_8028F588 declared with the object last:
 * a free function evaluates the float argument before the object pointer
 * (fn_8028EF98 loads f1 first, then r3). */
void fn_8028F588(float f, Unk8028F45C_Inner* i);
int fn_8026DC18(Unk8028C6B8_X* x, int a);
float fn_80249298(Unk8028C6B8_X* x, int a, int b);
extern float lbl_8061E700[27];            /* squared distances, indexed by Goal::m4C */

/* Vector difference with by-value parameters (each lvalue argument is copied to a
 * stack temp first, as in fn_8028E9E8). */
inline Unk80273498_Vec3 Unk8028E9E8_Sub(Unk80273498_Vec3 a, Unk80273498_Vec3 b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

/* Returns a position for an object (sret): Unk80273498_Vec3 by value. */
Unk80273498_Vec3 fn_801837F4(void* obj, int idx);

#endif /* GAME_GOALS_TU_8028C6B8_H */
