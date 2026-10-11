/*
 * Types for animation/goals/tu_802914C8.cpp (goal logic, reconstructed).
 * Nothing here comes from original headers: layouts are inferred from the
 * field offsets that unit uses; names are placeholders.
 */
#ifndef GAME_GOALS_TU_802914C8_H
#define GAME_GOALS_TU_802914C8_H

#include "game/chooser.h"
#include "game/goals/tu_8027A84C.h"

typedef Unk80273498_Vec3 Vec3;

/* View of the player object (Unk80270BA0_X) for the bytes chooser.h hides in
 * its padding. Evidence: fn_80296924 reads +0x5BC (compared with -1);
 * fn_80295F90 and fn_80296030 read the floats +0x720..+0x72C. */
struct Unk802914C8_X {
    char pad0[0x5BC];
    int m5BC;
    char pad5C0[0x720 - 0x5C0];
    float m720;
    float m724;
    float m728;
    float m72C;
};

/* Bit view of a goal's flag word at +0x18C. fN is bit N counted from the most
 * significant bit (mask 0x80000000 >> N); separate tests of two bits show
 * that the original reads them as bit fields (fn_802958F4). */
struct Unk802914C8_Flags {
    unsigned int f0 : 1, f1 : 1, f2 : 1, f3 : 1, f4 : 1, f5 : 1, f6 : 1, f7 : 1;
    unsigned int f8 : 1, f9 : 1, f10 : 1, f11 : 1, f12 : 1, f13 : 1, f14 : 1, f15 : 1;
    unsigned int f16 : 1, f17 : 1, f18 : 1, f19 : 1, f20 : 1, f21 : 1, f22 : 1, f23 : 1;
    unsigned int f24 : 1, f25 : 1, f26 : 1, f27 : 1, f28 : 1, f29 : 1, f30 : 1, f31 : 1;
};

/* The angle block at Unk80270BA0_X+0x734 (Unk802726BC_Angles in chooser.h) with
 * the entries fn_80296030 writes. Each is a pair indexed by m190 (0 or 1).
 * Evidence: fn_80296030 (stores at +0x8, +0x10, +0x18, +0x100, +0x140, +0x158). */
struct Unk802914C8_Angles {
    char pad0[8];
    float m8[2];
    float m10[2];
    int m18[2];
    char pad20[0x100 - 0x20];
    float m100[2];
    char pad108[0x140 - 0x108];
    float m140[2];
    char pad148[0x158 - 0x148];
    int m158[2];
    char pad160[0x190 - 0x160];
    int m190;
};

/* Writes entry m190 of a pair and, for index 1, entry 0 first (fn_80296030).
 * Two nested inline levels: the parameter slots are 8 bytes apart. */
inline void SetPairFi(Unk802914C8_Angles* a, int off, float t)
{
    if (a->m190 == 1) {
        *(float*)((char*)a + off) = t;
    }
    *(float*)((char*)a + (a->m190 * 4 + off)) = t;
}

inline void SetPairF(Unk802914C8_Angles* a, int off, float p)
{
    SetPairFi(a, off, p);
}

inline void SetPairI(Unk802914C8_Angles* a, int off, int v)
{
    if (a->m190 == 1) {
        *(int*)((char*)a + off) = v;
    }
    *(int*)((char*)a + (a->m190 * 4 + off)) = v;
}

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

/* Goal object (this of the unit's functions): the goal base plus the fields
 * these functions read. Evidence: fn_802958F4 (+0x4C state, +0x78/+0x7C/+0x80
 * floats, +0x18C flags), fn_802966DC (+0x28, +0x74). */
struct Unk802914C8_Goal : public Unk8027A84C {
    int m4C;
    int m50;
    char pad54[0x74 - 0x54];
    float m74;
    float m78;
    float m7C;
    float m80;
    char pad84[0x88 - 0x84];
    float m88;
    char pad8C[0x18C - 0x8C];
    union {
        int m18C;
        Unk802914C8_Flags f18C;
    };

    /* Inline accessors: testing two bits with && directly folds them into one
     * mask test, the original keeps two separate tests (fn_802958F4). */
    int fn_IsF16() { return f18C.f16; }
    int fn_IsF17() { return f18C.f17; }

    /* The vector at +0x10 hides in Unk8027A84C's padding. */
    Vec3& fn_Pos10() { return *(Vec3*)((char*)this + 0x10); }

    int fn_802914C8(Unk80270BA0_X* x);
    float fn_8029589C(Unk80270BA0_X* x, Unk8027AD3C_Obj* o);
    int fn_80295F90(Unk80270BA0_X* x, float t);
    float fn_80296624(float v);
    float fn_802966DC(Unk80270BA0_X* x);
    float fn_80296030(Unk80270BA0_X* x, float f1, float f2, float f3, float f4, float f5, float f6);
    void fn_80296924(Unk80270BA0_X* x);
    void fn_80296C60(int* arr, int value, int* count);

    int fn_802931B0(Unk80270BA0_X* x);
    float fn_802958F4(Unk80270BA0_X* x, Unk8027AD3C_Obj* o, float b);
    float fn_802962D0(Unk80270BA0_X* x, Unk8027AD3C_Obj* o);
    float fn_802963C4(Unk80270BA0_X* x, Unk8027AD3C_Obj* ob, float f);
    float fn_802964C4(Vec3 pos, Vec3 target, float angle, float speed);
    int fn_80296998(int kind, int h);
    int fn_80296B4C(int kind, int* out);

    int fn_802931D0(Unk80270BA0_X* x);
    int fn_802908FC(Unk80270BA0_X* x);                         /* other unit */
    int fn_80290274(int a, Unk80270BA0_X* x, int b);           /* other unit */
    int fn_80290B78(Unk80270BA0_X* x);                         /* other unit */
    int fn_8029771C();                                         /* neighbouring unit */
    int fn_8029543C(Unk80270BA0_X* x);
    float fn_80295A70(Unk80270BA0_X* x, Unk8027AD3C_Obj* o, int c, float* out);

    /* Accessors in the neighbouring unit (0x80297614..0x80297740). */
    Vec3 fn_80297614();
    int fn_80297668();
    Vec3 fn_802976A8();
};

struct Unk80283934_Goal;
int fn_80285498(Unk80283934_Goal* g);                          /* other unit (tu_80283934.cpp) */

float fn_804028E4(float x);                                    /* square root */
float fn_8041171C(float x);
float fn_80411554(float x);
float fn_80410CE8(float y, float x);
float fn_80249298(Unk80270BA0_X* x, int a, int b);              /* other unit */
void fn_80244858(Unk80270BA0_X* x, float v);                   /* other unit */
float fn_80248FC8(Unk80270BA0_X* x, int a);                    /* other unit */
float fn_8024D0F8(Unk80270BA0_X* x, int a);                    /* other unit */

/* Unit vector for an angle (as in animation/goals/tu_80283934.h). */
inline Vec3 Direction(float angle)
{
    Vec3 r;
    r.x = fn_8041171C(angle);
    r.y = 0.0f;
    r.z = fn_80411554(angle);
    return r;
}

inline float Remap(float x, float k, float c)
{
    return x * k - c;
}

struct FloatBox {
    float f;
};

inline float Sign(float f)
{
    return !(f >= 0.0f) ? -1.0f : 1.0f;
}

inline Vec3 operator+(Vec3 a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

inline Vec3 VSub(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

/* First operand by value: the caller makes a stack copy (fn_802966DC). */
inline Vec3 VSubV(Vec3 a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

/* Same helper as Length in tu_8027FD64.h. */
inline float Length(Vec3 v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline float LengthR(const Vec3& v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}

/* Position with y cleared; the parameter copy is where retail zeroes y. */
inline Vec3 Flatten(Vec3 v)
{
    v.y = 0.0f;
    return v;
}

inline Vec3 VScale(Vec3 v, float s)
{
    Vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

inline float Lerp(float a, float t, float b)
{
    return a + (b - a) * t;
}


int fn_8026D9D0(Unk80270BA0_X* x, int a);                      /* other unit */
int fn_8026D890(Unk80270BA0_X* x, int a);                      /* other unit */
int fn_8026D940(Unk80270BA0_X* x, int a);                      /* other unit */
void fn_80381E9C(Unk80271DBC_Link* l, int v, int a, int b);   /* other unit */
float fn_80249188(Unk80270BA0_X* x, float f);                  /* other unit */
extern int lbl_806242B4;                                       /* other units' .data */

#endif /* GAME_GOALS_TU_802914C8_H */
