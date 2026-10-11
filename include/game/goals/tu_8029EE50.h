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
    char pad724[0x72C - 0x724];
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

void fn_802771A0(int a);
void fn_802D7B88(int a, int b, float f, int c);
float fn_804028E4(float f);
int fn_80380964(Unk80271DBC_Link* link);
float fn_80249188(Unk80270BA0_X* x, float f);
void fn_801CE9D8(Unk8027107C_Inner* p);

#endif /* GAME_GOALS_TU_8029EE50_H */
