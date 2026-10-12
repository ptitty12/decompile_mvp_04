#ifndef GAME_TU_80241C24_H
#define GAME_TU_80241C24_H

#include "game/tu_8024B99C.h"
#include "game/chooser.h"
#include "game/tu_8024EF40.h"

/* Declarations and inline helpers for the player-object unit at 0x80241C24-0x80246D04. */
/* Two views used by the list builders at 0x802423A8-0x80242D9C: A has the mode word at +0x398;
 * B is a list holder: a list header at +4 and two sub-holders at +0x438/+0x43C. */
struct Unk80241C24_A {
    char pad0[0x398];
    int m398;
};
struct Unk80241C24_B {
    char pad0[4];
    int m4;
    char pad8[0x438 - 8];
    Unk80241C24_B* m438;
    Unk80241C24_B* m43C;
};

void fn_8030AF34(void* p, int a);
void fn_8030AF9C(void* p, int a);
void fn_80378A34(void* p, void* q);
void fn_802593EC(int a, Unk80270BA0_X* x, int b);
int fn_802491D8(Unk80270BA0_X* x);
void fn_80242498(int a, int* b, int c, int d, int e);
void fn_8024282C(int a, int* b, int c, int d, int e, int f, int g);
void fn_80242D9C(Unk80241C24_A* a, int* b, int c, int d, int e);
void fn_802423EC(int a, int* s);
void fn_80245868(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
struct Unk8016C788_Obj;
typedef Unk8027C728_Goal Goal;
typedef Unk8027C728_Player Player;
typedef Unk80273498_Vec3 Vec3;
void fn_80244A60(Player* player, Goal* g);
void fn_80244A64(Player* player, Goal* g, int flag);
void fn_80382BC0(Unk80271DBC_Link* l, float f);
int fn_8037EDFC(Unk80271DBC_Link* l, int a, int b, int c, int d, float f1, float f2);
double fn_80410634(double x);
Goal* fn_8027D2FC(Goal* g, int);
Goal* fn_8027D31C(Goal* g);
void fn_8027D150(Goal* g, int a, Unk80279BB8* out, float f, Vec3* b, Unk8027D150_Pair* c, int d);
void fn_80244D4C(Unk80270BA0_X* x, int a, Unk8027D150_Pair* c, Vec3* b, float f);
extern Goal* lbl_8061D37C;
extern char* lbl_8061D378;
extern char lbl_806EF9C4;
extern char lbl_806EF9C7;
extern const Vec3 lbl_806055DC;

inline void SetYaw(Unk80270BA0_X* x, float v)
{
    fn_80382BC0(x->m618, v);
}

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

#endif
