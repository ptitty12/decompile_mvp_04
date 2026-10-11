/*
 * Types for animation/goals/tu_8029B70C.cpp (goal logic, reconstructed).
 *
 * Nothing here comes from original headers: layouts are inferred from the
 * functions in that unit. Names are placeholders (Unk<addr>, m<offset>,
 * fn_<addr>) until evidence exists. The "views" below describe fields of
 * objects whose main declarations live in game/chooser.h; they are reached
 * with a pointer cast so that chooser.h need not change.
 */
#ifndef GAME_GOALS_TU_8029B70C_H
#define GAME_GOALS_TU_8029B70C_H

#include "game/chooser.h"

/* Path of the source file this unit's assert/RNG call names (fn_8029B70C). */
#define UNK8029B70C_PICKUP_FILE "C:/mvp2004/source/common/animation/goals/userpickupballgoal.cpp"

/* Fields of the player object (Unk80270BA0_X) not declared in chooser.h. */
struct Unk8029B70C_Player {
    char pad0[0x540];
    float m540;
};

/* The goal object's flag word at +0xD0. fN is bit N counted from the most
 * significant bit (mask 0x80000000 >> N). Evidence: fn_8029C27C extracts bit
 * 6 with extrwi and reuses the zero it tested. */
struct Unk8029B70C_Flags {
    unsigned int f0 : 1, f1 : 1, f2 : 1, f3 : 1, f4 : 1, f5 : 1, f6 : 1, f7 : 1;
    unsigned int f8 : 1, f9 : 1, f10 : 1, f11 : 1, f12 : 1, f13 : 1, f14 : 1, f15 : 1;
    unsigned int f16 : 1, f17 : 1, f18 : 1, f19 : 1, f20 : 1, f21 : 1, f22 : 1, f23 : 1;
    unsigned int f24 : 1, f25 : 1, f26 : 1, f27 : 1, f28 : 1, f29 : 1, f30 : 1, f31 : 1;
};

/* The goal object. Offsets seen in this unit. The goal state functions are
 * (goal, player, float time) and return a small state code. */
struct Unk8029B70C_Goal {
    char pad0[0x4];
    struct Unk8029B70C_Sub* m4;
    char pad8[0x48 - 0x8];
    int m48;
    int m4C;
    int m50;
    float m54;
    float m58;
    float m5C;
    void* m60;
    char pad64[0x6C - 0x64];
    float m6C;
    float m70;
    char pad74[0x9C - 0x74];
    Unk80273498_Vec3 m9C;
    float mA8;
    char padAC[0xCC - 0xAC];
    int mCC;
    Unk8029B70C_Flags mD0;            /* flags */
};

/* Query record built on the stack and filled in by fn_80386110. Size 0xC0;
 * same layout as Unk80386110_Query in tu_8027FD64.h (+0x44 nibble, +0x68
 * vector cleared with integer stores, +0xA0, +0xBC); fn_8029C27C and
 * fn_8029C4E4 construct it the same way. */
struct Unk8029B70C_Zero3 {
    int x;
    int y;
    int z;
    Unk8029B70C_Zero3()
    {
        x = 0;
        y = 0;
        z = 0;
    }
};

struct Unk8029B70C_Query {
    char pad0[0x44];
    unsigned int mType : 4;
    unsigned int mTypePad : 28;
    char pad48[0x68 - 0x48];
    Unk8029B70C_Zero3 m68;
    char pad74[0xA0 - 0x74];
    int mA0;
    char padA4[0xBC - 0xA4];
    int mBC;
    char padC0[0xC0 - 0xC0];

    Unk8029B70C_Query() : mType(0), mA0(0), mBC(0)
    {
    }
};
int fn_80386110(Unk80271DBC_Link* link, Unk8029B70C_Query* q, int a, unsigned int hash, float* out, int flags);

/* Sets entry i of the float table at +8 of the angle block: an inline
 * function, since the constant offset stays in an index register. */
inline void Unk8029B70C_SetM8(Unk802726BC_Angles* a, int i, float v)
{
    int off = i * 4 + 8;
    *(float*)((char*)a + off) = v;
}

float fn_80382BB8(Unk80271DBC_Link* l);       /* current animation time/angle */
float fn_80410CE8(float y, float x);          /* atan2 */
double fn_80410634(double x);                 /* floor */
void fn_80244858(Unk80270BA0_X* x, float v);
int fn_8024D504(Unk80270BA0_X* x, int a, int b, int c, int d);
int fn_801DC658(int a, Unk80273498_Vec3* pos, float* out);
extern const Unk80273498_Vec3 lbl_806055AC;     /* zero vector */
extern const Unk80273498_Vec3 lbl_805DED58;     /* (513.3595, 0, 513.3595) */

Unk80273498_Vec3 fn_8023F29C(Unk80270BA0_X* x);
void fn_8024B99C(Unk80270BA0_X* x, Unk80273498_Vec3* a, Unk80273498_Vec3* b, Unk80273498_Vec3* c, int d, int e);
Unk8014D8AC_Ctx* fn_8027A918(Unk8029B70C_Goal* g);        /* tu_8027A84C.cpp */

extern float lbl_8061E80C;
extern float lbl_8061E810;

/* One float parameter per slot under -ffloat-store: the inline function's
 * params and local each get a frame slot (fn_8029B70C). */
inline float Unk8029B70C_Ratio(float lo, float v, float hi)
{
    float range = hi - lo;
    if (!(range <= 0.0f)) {
        return (v - lo) / range;
    }
    return 0.0f;
}

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

inline Unk80273498_Vec3 FlatPos(const Unk80273498_Vec3& p)
{
    Unk80273498_Vec3 r = p;
    r.y = 0.0f;
    return r;
}

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline Unk80273498_Vec3 operator+(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

inline Unk80273498_Vec3 operator*(const Unk80273498_Vec3& a, float s)
{
    Unk80273498_Vec3 r;
    r.x = a.x * s;
    r.y = a.y * s;
    r.z = a.z * s;
    return r;
}

#endif /* GAME_GOALS_TU_8029B70C_H */
