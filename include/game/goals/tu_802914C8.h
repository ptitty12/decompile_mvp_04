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

/* Goal object (this of the unit's functions): the goal base plus the fields
 * these functions read. Evidence: fn_802958F4 (+0x4C state, +0x78/+0x7C/+0x80
 * floats, +0x18C flags), fn_802966DC (+0x28, +0x74). */
struct Unk802914C8_Goal : public Unk8027A84C {
    int m4C;
    char pad50[0x74 - 0x50];
    float m74;
    float m78;
    float m7C;
    float m80;
    char pad84[0x18C - 0x84];
    union {
        int m18C;
        Unk802914C8_Flags f18C;
    };

    /* Inline accessors: testing two bits with && directly folds them into one
     * mask test, the original keeps two separate tests (fn_802958F4). */
    int fn_IsF16() { return f18C.f16; }
    int fn_IsF17() { return f18C.f17; }

    int fn_802914C8(Unk80270BA0_X* x);
    float fn_8029589C(Unk80270BA0_X* x, Unk8027AD3C_Obj* o);
    int fn_80295F90(Unk80270BA0_X* x, float t);
    float fn_80296624(float v);
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
    int fn_8029543C(Unk80270BA0_X* x);
    float fn_80295A70(Unk80270BA0_X* x, Unk8027AD3C_Obj* o, int c, float* out);

    /* Accessors in the neighbouring unit (0x80297614..0x80297740). */
    Vec3 fn_80297614();
    int fn_80297668();
    Vec3 fn_802976A8();
};

struct Unk80283934_Goal;
int fn_80285498(Unk80283934_Goal* g);                          /* other unit (tu_80283934.cpp) */

float fn_8041171C(float x);
float fn_80411554(float x);
float fn_80410CE8(float y, float x);
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

#endif /* GAME_GOALS_TU_802914C8_H */
