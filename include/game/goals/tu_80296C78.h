/*
 * Types for animation/goals/tu_80296C78.cpp (goal logic). Reconstructed from
 * the field offsets that unit uses; names are placeholders.
 */
#ifndef GAME_GOALS_TU_80296C78_H
#define GAME_GOALS_TU_80296C78_H

#include "game/chooser.h"
#include "game/goals/tu_8027A84C.h"

typedef Unk80273498_Vec3 Vec3;

float fn_80382BB8(Unk80271DBC_Link* l);
float fn_80382BD8(Unk80271DBC_Link* l, int a);
float fn_804028E4(float x);               /* square root */
float fn_8041171C(float x);
float fn_80411554(float x);
float fn_80410CE8(float y, float x);
double fn_80410634(double x);                 /* rounds down */

struct Unk80296C78_Goal;

/* What a goal's +4 points at (the animation goal it drives). Offsets seen in
 * fn_80299100 and fn_802993D4; the methods take Vec3 by value (PPC EABI passes
 * the address of a caller-made copy). */
struct Unk80296C78_Ent {
    char pad0[0x28];
    int m28;
    char pad2C[0x38 - 0x2C];
    int m38;
    char pad3C[4];
    int m40;
    char pad44[0x4C - 0x44];
    int m4C;
    char pad50[0x98 - 0x50];
    Unk80270BA0_X* m98;

    void fn_8028F34C();
    void fn_8028F440();
    void fn_8028F45C(Vec3 v);
    void fn_8028F528(Vec3 v);
};

/* The goal's flag word at +0x18C. fN is bit N counted from the most
 * significant bit (mask 0x80000000 >> N). Evidence that it is a bitfield:
 * fn_80297668 tests f9 with andis. and extracts f10 with extrwi. */
struct Unk80296C78_Flags {
    unsigned int f0 : 1, f1 : 1, f2 : 1, f3 : 1, f4 : 1, f5 : 1, f6 : 1, f7 : 1;
    unsigned int f8 : 1, f9 : 1, f10 : 1, f11 : 1, f12 : 1, f13 : 1, f14 : 1, f15 : 1;
    unsigned int f16 : 1, f17 : 1, f18 : 1, f19 : 1, f20 : 1, f21 : 1, f22 : 1, f23 : 1;
    unsigned int f24 : 1, f25 : 1, f26 : 1, f27 : 1, f28 : 1, f29 : 1, f30 : 1, f31 : 1;
};

/* Goal record of the +0x18C-flag family. Evidence: offsets used by the
 * functions of animation/goals/tu_80296C78.cpp (0x80296C78..0x80299920). */
struct Unk80296C78_Goal {
    int m0;                        /* goal code (9 in fn_80298B74, 2 in fn_80298E50) */
    Unk80296C78_Ent* m4;           /* fn_80299100 / fn_802993D4 */
    char pad8[0xC - 8];
    int mC;
    Vec3 m10;
    Vec3 m1C;
    int m28;
    int m2C;
    char pad30[0x38 - 0x30];
    int m38;
    char pad3C[0x40 - 0x3C];
    int m40;
    int* m44;
    union {
        int m48;
        Unk80296C78_Goal* m48p;    /* fn_802987C8 reads m48p->m38 */
    };
    int m4C;
    Vec3 m50;
    char pad5C[4];
    int m60;
    int m64;
    int m68;
    int m6C;
    char pad70[4];
    float m74;
    char pad78[0x80 - 0x78];
    float m80;
    float m84;
    char pad88[0x158 - 0x88];
    float m158;
    char pad15C[0x160 - 0x15C];
    int m160;
    Vec3 m164;
    Vec3 m170;
    int m17C;
    int m180;
    char pad184[0x18C - 0x184];
    union {
        unsigned int m18C;
        Unk80296C78_Flags m18Cbits;
    };

    /* Testing two bits with && directly folds them into one mask compare;
     * the original keeps separate andis. tests (as in tu_8027FD64.h). */
    int IsF8() const { return m18Cbits.f8; }
    int IsF9() const { return m18Cbits.f9; }
    int IsF13() const { return m18Cbits.f13; }
    int IsF12() const { return m18Cbits.f12; }
};

/* Position getter by value: gives retail's temp copy when assigned (fn_80298E9C). */
inline Vec3 GetPos(const Unk80296C78_Goal* p)
{
    return p->m10;
}

/* Same for the vector at +0x50 (fn_80299834: the by-value result gives retail's temp). */
inline Vec3 GetPos50(const Unk80296C78_Goal* p)
{
    return p->m50;
}

/* Writes through a by-value parameter: gives retail's temp-to-member copy. */
inline void SetVec(Vec3& dst, Vec3 v)
{
    dst = v;
}

extern const Vec3 lbl_806055AC;
extern int lbl_806242B4;

/* By-value operands (fn_802987C8 copies both into temps). */
inline Vec3 Sub(Vec3 a, Vec3 b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline Vec3 operator+(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

inline Vec3 operator*(Vec3 v, float s)
{
    Vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

/* Unit vector for an angle (as in animation/goals/tu_80283934.h). */
inline Vec3 Direction(float angle)
{
    Vec3 r;
    r.x = fn_8041171C(angle);
    r.y = 0.0f;
    r.z = fn_80411554(angle);
    return r;
}

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

extern "C" double fabs(double x);

float fn_80249298(int a, int b, int c);
int fn_8027CFA8(int a, int b);

/* Squared length in the x/z plane; by value, as retail copies the argument. */
inline float DistSq2D(Vec3 v)
{
    return v.x * v.x + v.z * v.z;
}

/* Request record built by the +0x18C-family goals (fn_80298CB8, fn_802997F0):
 * the Unk8027A9AC_Req prefix (0xC0 bytes) plus the fields at +0xCC..+0xD8
 * (Unk8027AD3C_Obj has +0xCC and +0xD0 too). */
struct Unk80298CB8_Req : public Unk8027A9AC_Req {
    char padC0[0xCC - 0xC0];
    int mCC;
    float mD0;
    float mD4;
    int mD8;
};

/* Angle block of the player (Unk802726BC_Angles) with the int pair at +0x78. */
struct Unk80296C78_Angles {
    char pad0[0x78];
    int m78[2];
    char pad80[0x190 - 0x80];
    int m190;
};

/* Sets entry i of the int table at +0x78 (as Unk8027FD64_SetSlot168). */
inline void SetSlot78(Unk80296C78_Angles* a, int i, int v)
{
    int off = i * 4 + 0x78;
    *(int*)((char*)a + off) = v;
}

int fn_8026D654(Unk80270BA0_X* p, int a);
int fn_8026D6AC(Unk80270BA0_X* p, int a);
int fn_8026DAE8(Unk80270BA0_X* p, int a);
int fn_8027D708(Unk80296C78_Goal* g, Unk80270BA0_X* x, Unk80270BA0_X* p);

int fn_8026CF70(Unk80270BA0_X* x, Unk80270BA0_X* p, int* o1, int* o2, float* o3);
int fn_8026CFF8(int a, Vec3* from, int b, Vec3* to);
int fn_80290D1C(Unk80296C78_Ent* e, Unk80270BA0_X* x);

/* Fields of the player object (Unk80270BA0_X) hidden in chooser.h padding. */
struct Unk80296C78_Player {
    char pad0[0x264];
    int m264;
    char pad268[0x590 - 0x268];
    unsigned int m590;
    char pad594[0x934 - 0x594];
    Unk8027A84C_Owner* m934;
};

/* 0xC-byte object at 0x80695950 (shared with other units); fn_803834D8 is its method. */
struct Unk80695950 {
    char pad0[0xC];
    int fn_803834D8(Unk80270BA0_Obj* o);
};
extern Unk80695950 lbl_80695950;

/* Functions of the unit referenced before their definition. */
int fn_80298DB8(Unk80296C78_Goal* g, int code, int* out);
int fn_80299100(Unk80296C78_Goal* g, Unk80270BA0_X* x, Unk80270BA0_X* target);
int fn_802993B4(Unk80296C78_Goal* g, Unk80270BA0_X* x, Unk80270BA0_X* target);
int fn_802993D4(Unk80296C78_Goal* g, Unk80270BA0_X* x, Unk80270BA0_X* target);


/* Link object reached through Unk80270BA0_X::m618 (see Unk80271DBC_Link). */
void fn_80381E9C(Unk80271DBC_Link* l, int v, int a, int b);

#endif /* GAME_GOALS_TU_80296C78_H */
