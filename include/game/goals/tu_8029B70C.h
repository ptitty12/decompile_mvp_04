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

double __builtin_fabs(double x);

/* Path of the source file this unit's assert/RNG call names (fn_8029B70C). */
#define UNK8029B70C_PICKUP_FILE "C:/mvp2004/source/common/animation/goals/userpickupballgoal.cpp"

/* Fields of the player object (Unk80270BA0_X) not declared in chooser.h. */
struct Unk8029B70C_Player {
    char pad0[0x540];
    float m540;
};

/* Request record (0x58 bytes) returned by value by fn_8029E4AC: cleared with
 * memset, then a few flags set. Offsets from the stores in fn_8029E4AC. */
struct Unk8029B70C_Req {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    char pad2C[0x58 - 0x2C];
};

/* Sub-goal object at goal+0x4 (fn_8029C914). Offsets seen. */
struct Unk8029B70C_Sub {
    char pad0[0x28];
    int m28;
    char pad2C[0x38 - 0x2C];
    int m38;
    char pad3C[0x40 - 0x3C];
    int m40;
    char pad44[0x98 - 0x44];
    void* m98;

    void fn_8028F45C(Unk80273498_Vec3 v);
    void fn_8028F528(Unk80273498_Vec3 v);
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
    Unk8029B70C_Sub* m4;
    char pad8[0x38 - 0x8];
    int m38;
    char pad3C[0x48 - 0x3C];
    int m48;
    int m4C;
    int m50;
    float m54;
    float m58;
    float m5C;
    Unk80273498_Pos* m60;
    char pad64[0x68 - 0x64];
    float m68;
    float m6C;
    float m70;
    float m74;
    float m78;
    char pad7C[0x88 - 0x7C];
    float m88;
    char pad8C[0x9C - 0x8C];
    Unk80273498_Vec3 m9C;
    float mA8;
    char padAC[0xB8 - 0xAC];
    Unk80273498_Vec3 mB8;
    int mC4;
    char padC8[0xCC - 0xC8];
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

/* Angle block (Unk802726BC_Angles at player+0x734) tables written by the goal
 * state functions: one entry per m190 (0 or 1), mirrored into entry 0 when
 * m190 is 1. Each helper is an inline function, since the constant offset
 * stays in an index register (fn_8029C27C, fn_8029C4E4). */
inline void Unk8029B70C_SetM78(Unk802726BC_Angles* a, int i, int v)
{
    int off = i * 4 + 0x78;
    *(int*)((char*)a + off) = v;
}
inline void Unk8029B70C_SetM98(Unk802726BC_Angles* a, int i, float v)
{
    int off = i * 4 + 0x98;
    *(float*)((char*)a + off) = v;
}
inline void Unk8029B70C_SetMB8(Unk802726BC_Angles* a, int i, float v)
{
    int off = i * 4 + 0xB8;
    *(float*)((char*)a + off) = v;
}
inline void Unk8029B70C_SetM120(Unk802726BC_Angles* a, int i, int v)
{
    int off = i * 4 + 0x120;
    *(int*)((char*)a + off) = v;
}
inline void Unk8029B70C_SetM48(Unk802726BC_Angles* a, int i, float v)
{
    int off = i * 4 + 0x48;
    *(float*)((char*)a + off) = v;
}

/* Write entry 0 as well when m190 is 1, then entry m190 (the pattern seen in
 * every goal state function). Two nested inline functions: the float
 * parameter of each gets a frame slot of its own (fn_8029C4E4 stores a value
 * to three consecutive slots), and the constant offset stays in the index
 * register of the second store. */
#define UNK8029B70C_MIRROR(name, type, off)     inline void name##Inner(Unk802726BC_Angles* a, type v)     {         if (a->m190 == 1) {             *(type*)((char*)a + off) = v;         }         int idx = a->m190 * 4 + off;         *(type*)((char*)a + idx) = v;     }     inline void name(Unk802726BC_Angles* a, type v)     {         name##Inner(a, v);     }
UNK8029B70C_MIRROR(Unk8029B70C_Mirror8, float, 8)
UNK8029B70C_MIRROR(Unk8029B70C_Mirror98, float, 0x98)
UNK8029B70C_MIRROR(Unk8029B70C_MirrorB8, float, 0xB8)
UNK8029B70C_MIRROR(Unk8029B70C_Mirror48, float, 0x48)
UNK8029B70C_MIRROR(Unk8029B70C_Mirror78, int, 0x78)
UNK8029B70C_MIRROR(Unk8029B70C_Mirror120, int, 0x120)

/* Fields of the context (player+0x44C) and the object at ctx+0x6CC. */
struct Unk8029B70C_Pos {
    char pad0[0x36C];
    Unk80270BA0_X* m36C;
};

/* Goal state functions of this unit, called before their definition. */
int fn_8029D184(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f);
int fn_8029D7F4(Unk8029B70C_Goal* g, Unk80270BA0_X* x, int a, int b, int c, int d);
Unk8029B70C_Req fn_8029DB14(Unk8029B70C_Goal* g, Unk80270BA0_X* x, int a, int b, int c);
int fn_8029E6BC(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80271DBC_Link* link, int a, int b, Unk8029B70C_Req r);
Unk8029B70C_Req fn_8029E4AC(Unk8029B70C_Goal* g, Unk80270BA0_X* x, int kind, int a, int b, Unk8029B70C_Req o);
int fn_8029EC30(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80271DBC_Link* link, int kind, int a, int b, Unk8029B70C_Req o);
void fn_8029EE50(Unk8029B70C_Goal* g);
void fn_8029EF28(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80271DBC_Link* link);
int fn_8026D184(int a, int b);
int fn_8026D940(Unk80270BA0_X* x, int a);
extern int lbl_806242B0;
float fn_8029CF14(Unk8029B70C_Goal* g, Unk80270BA0_X* x);
int fn_8029D7C4(Unk8029B70C_Goal* g);

float fn_80382BB8(Unk80271DBC_Link* l);       /* current animation time/angle */
float fn_80410CE8(float y, float x);          /* atan2 */
double fn_80410634(double x);                 /* floor */
void fn_80244858(Unk80270BA0_X* x, float v);
int fn_8024D504(Unk80270BA0_X* x, int a, int b, int c, int d);
int fn_801DC658(int a, Unk80273498_Vec3* pos, float* out);
extern const Unk80273498_Vec3 lbl_806055AC;     /* zero vector */
extern const Unk80273498_Vec3 lbl_805DED58;     /* (513.3595, 0, 513.3595) */

Unk80273498_Vec3 fn_8023F29C(Unk80270BA0_X* x);
int fn_8024B99C(Unk80270BA0_X* x, Unk80273498_Vec3* a, Unk80273498_Vec3* b, Unk80273498_Vec3* c, int d, int e);
Unk8014D8AC_Ctx* fn_8027A918(Unk8029B70C_Goal* g);        /* tu_8027A84C.cpp */

int fn_802A2604(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f, int a);
int fn_802A1790(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f);
int fn_802A168C(Unk8029B70C_Goal* g, Unk80270BA0_X* x, unsigned int hash, float f);
int fn_8026D628(Unk80270BA0_X* x, int a);
int fn_8026DAE8(Unk80270BA0_X* x, int a);
int fn_8026D6AC(Unk80270BA0_X* x, int a);
int fn_8026DC18(Unk80270BA0_X* x, int a);
int fn_8026D7E0(Unk80270BA0_X* x, int a);
int fn_8027B1A0(Unk8029B70C_Goal* g, Unk80270BA0_X* x, const Unk80273498_Vec3* pos);   /* tu_8027A84C.cpp */
int fn_80381E9C(Unk80271DBC_Link* link, unsigned int hash, int a, int b);
int fn_8024D218(Unk80270BA0_X* x);
int fn_8026DB3C(Unk80270BA0_X* x, int a);
int fn_802D7DB4(int a, int b);
unsigned int fn_8029D2E0(Unk8029B70C_Goal* g, Unk80270BA0_X* x, int kind, int a);

void fn_802A2A64(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80273498_Pos* p);
int fn_801A2034(Unk8014D8AC_Ctx* ctx, int a);
int fn_8026D344(int a, int b);
void* fn_8040B320(void* dst, int c, unsigned int n);     /* memset */
void fn_8028F34C(Unk8029B70C_Sub* s);
void fn_8028F440(Unk8029B70C_Sub* s);
int fn_80290D1C(Unk8029B70C_Sub* s, Unk80270BA0_X* x);
extern const Unk80273498_Vec3 lbl_805DED28[];     /* position table */

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

inline float Abs(float v)
{
    return __builtin_fabs(v);
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
