/*
 * Types for animation/goals/tu_8028F178.cpp (goal logic, reconstructed).
 * Nothing here comes from original headers: layouts are inferred from the
 * offsets that unit reads and writes. Names are placeholders.
 */
#ifndef GAME_GOALS_TU_8028F178_H
#define GAME_GOALS_TU_8028F178_H

#include "game/chooser.h"
#include "game/goals/tu_8027A84C.h"

extern "C" float fabsf(float x);          /* inlined as fabs */

struct Unk8028F178_Goal;

/* Owner of the goals (same object as Unk8027A84C_Owner, which has a pad where
 * +0x14 is read here). Evidence: fn_8028F178 reads +0x14; fn_8028FAEC reads +0x0;
 * fn_80290274 / fn_80290B78 / fn_80290D3C read +0x10 (a goal-kind selector, 6 or
 * 10) and take the goal storage at +0x18 when it matches. */
struct Unk8028F178_Owner {
    Unk8028F178_Owner* m0;
    char pad4[0x10 - 0x4];
    int m10;
    int m14;
    char m18[4];
};

/* Motion request record (0xDC bytes), the class constructed by 0x80279BB8
 * (animation/choosers/tu_80279AE4.cpp). Evidence: fn_8028F178 sets +0xD8,
 * fn_80291378 reads +0xD4 and builds it with the constructor taking the player. */
class Unk80279BB8 {
public:
    Unk80279BB8(Unk80270BA0_X* x);
    Unk80270BA0_Mtx m0;
    char pad40[0xD4 - 0x40];
    float mD4;
    int mD8;
};
typedef Unk80279BB8 Unk8028F178_Req;

/* Player fields read by fn_80291378 (callers cast): +0x724 and +0x728 floats. */
struct Unk8028F178_Player {
    char pad0[0x724];
    float m724;
    float m728;
};

/* The flag word at +0x18C of the goal. fN is bit N counted from the most
 * significant bit (mask 0x80000000 >> N). The top byte is written as a whole
 * (`stb`) by fn_8028F34C. */
struct Unk8028F178_Flags {
    int top : 8;
    unsigned int f8 : 1, f9 : 1, f10 : 1, f11 : 1, f12 : 1, f13 : 1, f14 : 1, f15 : 1;
    unsigned int f16 : 1, f17 : 1, f18 : 1, f19 : 1, f20 : 1, f21 : 1, f22 : 1, f23 : 1;
    unsigned int f24 : 1, f25 : 1, f26 : 1, f27 : 1, f28 : 1, f29 : 1, f30 : 1, f31 : 1;
};

/* Goal object (this of every function here; r3, or r4 when a Vec3 is returned).
 * Evidence: offsets used by fn_8028F178..fn_80291378. The first 0x4C bytes are
 * the Unk8027A84C base (calls to its members cast to it); +0x10 is a Vec3 here
 * where Unk8027A84C only knows padding. The goal's +0x4 points to the root
 * goal (owner+0x104) and +0x48 to its active goal. */
struct Unk8028F178_Goal {
    int m0;
    Unk8028F178_Goal* m4;
    char pad8[0xC - 0x8];
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
    Unk8028F178_Owner* m44;
    Unk8028F178_Goal* m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    int m5C;
    char pad60[0x6C - 0x60];
    float m6C;
    float m70;
    float m74;
    float m78;
    float m7C;
    float m80;
    float m84;
    float m88;
    Unk80273498_Vec3 m8C;
    int m98;
    char pad9C[0x158 - 0x9C];
    float m158;
    float m15C;
    int m160;
    Unk80273498_Vec3 m164;
    Unk80273498_Vec3 m170;
    int m17C;
    int m180;
    float m184;
    float m188;
    Unk8028F178_Flags m18C;

    /* Vector at +0x10 returned by value (a temp copy, as in fn_8028F610). */
    Unk80273498_Vec3 fn_GetM10() { return m10; }

    /* Vector result of the goal at 0x80286E70 (tu_80283934 or later unit). */
    Unk80273498_Vec3 fn_80286E70();
};

/* Same object as Unk8014D8AC_Ctx (reached through Unk80270BA0_X::m44C) with the
 * fields this unit reads; callers cast. Evidence: fn_8028F610 (+0x4C, a frame
 * counter converted to seconds), fn_80290D3C (+0x4C, +0x6CC), fn_80291378. */
struct Unk8028F178_Pos6CC {
    char pad0[0x36C];
    Unk80270BA0_X* m36C;
};
struct Unk8028F178_Ctx {
    char pad0[0x4C];
    unsigned int m4C;
    char pad50[0x6CC - 0x50];
    Unk8028F178_Pos6CC* m6CC;
};

int fn_802977FC(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk80279BB8* r, int a, int b, int c, int d, float f);
void fn_802987C8(Unk8028F178_Goal* a, Unk8028F178_Goal* b);

int fn_8029771C(Unk8028F178_Goal* g);
int fn_80297740(Unk8028F178_Goal* g);
float fn_80382BD8(Unk80271DBC_Link* link, int a);
void fn_803814A4(Unk80271DBC_Link* link, unsigned int hash, float f, int c);
int fn_8038614C(Unk80271DBC_Link* link, Unk80279BB8* req, int a, int b, float* c, int d, int e, int f, int flags);
int fn_8026DAE8(Unk80270BA0_X* x, int a);
int fn_8026D7B4(Unk80270BA0_X* x, int a);
int fn_8026D838(Unk80270BA0_X* x, int a);
float fn_80249298(Unk80270BA0_X* x, int a, int b);

Unk80273498_Vec3 fn_80297614(Unk8028F178_Goal* g);
int fn_80297668(Unk8028F178_Goal* g);
Unk80273498_Vec3 fn_802976A8(Unk8028F178_Goal* g);
int fn_8026DC18(Unk80270BA0_X* x, void* a);
int fn_8026D7E0(Unk80270BA0_X* x, void* a);
int fn_8026D6AC(Unk80270BA0_X* x, void* a);
float fn_80248FC8(Unk80270BA0_X* x, int a);
float fn_802966DC(Unk8028F178_Goal* g, Unk80270BA0_X* x);
int fn_8026D5A4(Unk80270BA0_X* x, int a);
int fn_80247858(Unk80270BA0_X* x, int a);
int fn_80294EE4(Unk8028F178_Goal* g, Unk80270BA0_X* x);
void fn_80296C78(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8028F178_Ctx* ctx);
int fn_80297764(Unk8028F178_Goal* g);
int fn_802977B0(Unk8028F178_Goal* g);
void fn_80296924(Unk8028F178_Goal* g, Unk80270BA0_X* x);
int fn_8027C2D0(Unk8028F178_Goal* g, Unk80270BA0_X* x, int a);
int fn_8029543C(Unk8028F178_Goal* g, Unk80270BA0_X* x);
int fn_802914C8(Unk8028F178_Goal* g, Unk80270BA0_X* x);
int fn_8029155C(Unk8028F178_Goal* g, Unk80270BA0_X* x);
int fn_80291F74(Unk8028F178_Goal* g, Unk80270BA0_X* x);
int fn_802924D4(Unk8028F178_Goal* g, Unk80270BA0_X* x);
int fn_80292ABC(Unk8028F178_Goal* g, Unk80270BA0_X* x);
int fn_80293EE0(Unk8028F178_Goal* g, Unk80270BA0_X* x);
int fn_802931B0(Unk8028F178_Goal* g, Unk80270BA0_X* x);
int fn_8029055C(Unk8028F178_Goal* g, Unk80270BA0_X* x);
extern Unk80273498_Vec3 lbl_805DED28[];
int fn_8027B55C(Unk8028F178_Goal* g, Unk80270BA0_X* x, int a, Unk80273498_Vec3* p, Unk80273498_Vec3* q, int b, int c,
                int* d, int* e, float f);

/* fn_8028F220 looks up a cMatrixChooser by hash and runs its fn_8026FB80 once (flag in
 * lbl_8061E770, result floats in lbl_806E0B70). Evidence: the vtable slot 4 call (class-name hash)
 * compared with 0x42D34230, the fallback through slots 18 and 24, and the call of
 * fn_8026FB80__14cMatrixChooserP15Unk80270BA0_ObjPf (animation/choosers/tu_8026DDE8.cpp). */
class Unk8028F220_Chooser : public Unk8037B3E8 {
public:
    Unk8028F220_Chooser();
    virtual Unk8028F220_Chooser* fn_vslot18(int a);
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual int fn_vslot24();
};
struct Unk8028F220_Entry {
    char pad0[0x28];
    int m28;
};
class cMatrixChooser {
public:
    int fn_8026FB80(Unk80270BA0_Obj* obj, float* out);
};
Unk8028F220_Entry* fn_80384A48(unsigned int hash);
Unk8028F220_Chooser* fn_8037D028(Unk8037C7FC* mgr, int a);
extern int lbl_8061E770[2];
extern int lbl_806242B4;
extern int lbl_806242B8;
extern float lbl_806E0B70[2][5];

#endif /* GAME_GOALS_TU_8028F178_H */
