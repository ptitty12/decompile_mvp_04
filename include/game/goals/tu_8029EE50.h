/*
 * Types for animation/goals/tu_8029EE50.cpp (goal logic after
 * userpickupballgoal, reconstructed).
 *
 * Nothing here comes from original headers: layouts are inferred from the
 * functions in that unit. Names are placeholders (Unk<addr>, m<offset>,
 * fn_<addr>) until evidence exists. The goal object of the first part of the
 * unit is Unk8029B70C_Goal (tu_8029B70C.h); the small goals at the end of the
 * unit have their own records below.
 */
#ifndef GAME_GOALS_TU_8029EE50_H
#define GAME_GOALS_TU_8029EE50_H

#include "game/goals/tu_8029B70C.h"
#include "game/goals/tu_8027A84C.h"

/* Data objects of the unity TU outside this unit's split. */
extern int lbl_8061F8FC;
extern int lbl_806EF9D4;
extern float lbl_8061E83C;

/* Motion request record (0xDC bytes), the class constructed by 0x80279BB8
 * (animation/choosers/tu_80279AE4.cpp). Layout as in tu_8028F178.h: fn_802A2B7C
 * and fn_802A2EB0 write +0xD4 and +0xD8 and pass it to Unk8027A84C::fn_8027AC90
 * as the matrix. */
class Unk80279BB8 {
public:
    Unk80279BB8(Unk80270BA0_X* x);
    Unk80270BA0_Mtx m0;
    char pad40[0xD4 - 0x40];
    float mD4;
    int mD8;
};

/* Small goal of fn_802A2DA4..fn_802A2F0C (init, execute, step, compare). It has
 * the Unk8027A84C base (+0xC phase counter); +0x48/+0x4C hold floats here. */
struct Unk802A2DA4_Goal {
    int m0;
    char pad4[0xC - 0x4];
    int mC;
    char pad10[0x48 - 0x10];
    float m48;
    float m4C;
};

/* Small goal of fn_802A2F20..fn_802A2F2C: +0x48 is a selector (1..9). */
struct Unk802A2F20_Goal {
    char pad0[0x48];
    int m48;
};

/* Small goal of fn_802A309C..fn_802A3408. */
struct Unk802A309C_Goal {
    char pad0[0x48];
    int m48;
    int m4C;
    int m50;
};

/* Fields of the objects reached from the context (player+0x44C) by fn_802A36B0. */
struct Unk802A36B0_Obj {
    char pad0[0xC8];
    int mC8;
};
struct Unk802A36B0_Ctx {
    char pad0[0x720];
    Unk802A36B0_Obj* m720;
};

/* Mirror helper for the +0x90 table of the angle block (fn_802A2C7C): same
 * shape as the ones in tu_8029B70C.h. */
UNK8029B70C_MIRROR(Unk8029B70C_Mirror90, int, 0x90)

float fn_804028E4(float f);
int fn_8026DC18(Unk80270BA0_X* x, int a);
int fn_8026D988(Unk80270BA0_X* x, int a);
int fn_8026D578(Unk80270BA0_X* x, int a);
void fn_803814A4(Unk80271DBC_Link* link, unsigned int hash, int a, float f);
int fn_8026CF70(Unk80270BA0_X* x, Unk80273498_Pos* p, int* a, int* idx, float* d);
int fn_8026CFF8(int a, Unk80273498_Vec3* pos, int idx, Unk80273498_Vec3* out);
void fn_80249B08(Unk80270BA0_X* x, int a, float f);
void fn_80249B40(Unk80270BA0_X* x, Unk80273498_Pos* p, int a, int b, float f);
void fn_80249DF8(Unk80270BA0_X* x, int a);

inline float LenSq3(const Unk80273498_Vec3& v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

/* Player fields read by fn_802A2604 (callers cast): two floats before the angle block. */
struct Unk802A2604_Player {
    char pad0[0x720];
    float m720;
    float m724;
    float m728;
    float m72C;
};

/* Object chain reached from the context by fn_802A2604: ctx+0x6F8 -> +0x10 -> +0x188. */
struct Unk802A2604_Obj2 {
    char pad0[0x188];
    int m188;
};
struct Unk802A2604_Obj {
    char pad0[0x10];
    Unk802A2604_Obj2* m10;
};
struct Unk802A2604_Ctx {
    char pad0[0x6F8];
    Unk802A2604_Obj* m6F8;
};

extern int lbl_8061E7A4;
extern int lbl_8061E7DC;
extern int lbl_80691DE0;
extern float lbl_8061E864;
extern float lbl_8061E868;

int fn_8026D8E8(Unk80270BA0_X* x, int a);
int fn_8026D914(Unk80270BA0_X* x, int a);

/* Player field written by fn_802A3408 (callers cast): a vector at +0x320. */
struct Unk802A3408_Player {
    char pad0[0x320];
    Unk80273498_Vec3 m320;
};

int fn_801CEADC(Unk8027107C_Inner* p);
void fn_801CEA44(Unk80273498_Vec3* out, Unk8027107C_Inner* p, int k);
int fn_802A30B0(Unk802A309C_Goal* g, Unk80270BA0_X* x);
void fn_802A36B0(Unk802A309C_Goal* g);
extern const float lbl_805DE118;

/* Two float parameters, each with a frame slot of its own (fn_802A3408). */
inline void Unk802A3408_SetXY(Unk80270BA0_X* x, float a, float b)
{
    x->m96C = a;
    x->m970 = b;
}

UNK8029B70C_MIRROR(Unk8029B70C_Mirror10, float, 0x10)
UNK8029B70C_MIRROR(Unk8029B70C_Mirror140, float, 0x140)
UNK8029B70C_MIRROR(Unk8029B70C_Mirror18, int, 0x18)
UNK8029B70C_MIRROR(Unk8029B70C_Mirror158, int, 0x158)

struct Unk8027C728_Player;
int fn_8027D708(void* g, Unk8027C728_Player* x, Unk8027C728_Player* p);
extern int lbl_806242B4;
int fn_8026DC5C(Unk80270BA0_X* x, int a);
int fn_8026DB3C(Unk80270BA0_X* x, int a);

UNK8029B70C_MIRROR(Unk8029B70C_Mirror108, float, 0x108)
UNK8029B70C_MIRROR(Unk8029B70C_Mirror50, float, 0x50)
UNK8029B70C_MIRROR(Unk8029B70C_Mirror110, float, 0x110)

int fn_8029CFDC(Unk8029B70C_Goal* g, const Unk80273498_Vec3* a, const Unk80273498_Vec3* b);
extern const Unk80273498_Vec3 lbl_805DED34;     /* (1080, 0, 1080) */
extern const Unk80273498_Vec3 lbl_805DED4C;     /* (7.5, 0, 7.5) */
extern float lbl_8061E7D4;
extern float lbl_8061E7D8;

/* Position of the player with y cleared. Reading x->m60 inside the inline
 * (rather than passing it by reference) gives retail's instruction order
 * (fn_802A253C, fn_802A0754). */
inline Unk80273498_Vec3 FlatPosOf(Unk80270BA0_X* x)
{
    Unk80273498_Vec3 r = x->m60;
    r.y = 0.0f;
    return r;
}

/* Object at context+0x6CC as seen by fn_802A1790: position at +0x60, owner
 * at +0x36C, two ints at +0x38C/+0x390 (tested against 1). */
struct Unk802A1790_Pos {
    char pad0[0x60];
    Unk80273498_Vec3 m60;
    char pad6C[0x36C - 0x6C];
    Unk80270BA0_X* m36C;
    char pad370[0x38C - 0x370];
    int m38C;
    int m390;
};

float fn_8041171C(float a);        /* sin */
float fn_80411554(float a);        /* cos */

/* Unary minus on a vector: three negations (fn_802A1790). */
inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a)
{
    Unk80273498_Vec3 r;
    r.x = -a.x;
    r.y = -a.y;
    r.z = -a.z;
    return r;
}

inline float Unk802A1790_Yaw(Unk80273498_Vec3 v)
{
    return fn_80410CE8(v.x, v.z);
}

inline Unk80273498_Vec3 Unk802A1790_Dir(float a)
{
    Unk80273498_Vec3 r;
    r.x = fn_8041171C(a);
    r.y = 0.0f;
    r.z = fn_80411554(a);
    return r;
}

inline Unk80273498_Vec3 Unk802A1790_Scale(Unk80273498_Vec3 v, float s)
{
    Unk80273498_Vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

float fn_8024D0C4(Unk80270BA0_X* x, int a, float f1, float f2);
int fn_8024D408(Unk80270BA0_X* x);
int fn_8026D654(Unk80270BA0_X* x, int a);
void fn_80191068(Unk802A1790_Pos* p, Unk80273498_Vec3* v, int a, float* out, float f1, float f2);
extern float lbl_8061E858;
extern float lbl_8061E85C;
/* The second probe of fn_802A1790 takes its position by value (a copy in the
 * inline's own frame). */
inline void Unk802A1790_Probe(Unk802A1790_Pos* p, Unk80273498_Vec3 v, float* out)
{
    fn_80191068(p, &v, 0, out, lbl_8061E858, lbl_8061E85C);
}
extern float lbl_8061E850;
extern float lbl_8061E854;

/* Writes the vector through the first argument (fn_802A1790). The same
 * address is declared in tu_8027A84C.h as returning the vector by value; the
 * register usage is identical. */
void fn_80189618(Unk80273498_Vec3* out, Unk8018959C_Obj* o, float f);

/* fn_802A168C: retail's parameter order is (goal, player, float, hash): the
 * float parameter is spilled before the hash is moved, which only happens when
 * it is declared first. tu_8029B70C.h declares the other order, which compiles
 * to the same argument registers (the callers there are unaffected). */
int fn_802A168C(Unk8029B70C_Goal* g, Unk80270BA0_X* x, float f, unsigned int hash);

void fn_802A28EC(Unk8029B70C_Goal* g, Unk80270BA0_X* a, Unk80273498_Pos* b);
int fn_8029D7D4(Unk8029B70C_Goal* g, Unk80270BA0_X* x, int a, int b, int c, int d);

void fn_802771A0(int a);
void fn_802D7B88(int a, int b, float f, int c);
float fn_804028E4(float f);
int fn_80380964(Unk80271DBC_Link* link);
float fn_80249188(Unk80270BA0_X* x, float f);
void fn_801CE9D8(Unk8027107C_Inner* p);

#endif /* GAME_GOALS_TU_8029EE50_H */
