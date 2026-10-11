/*
 * Types for animation/goals/tu_8027A84C.cpp (goal logic, reconstructed).
 * Nothing here comes from original headers: layouts are inferred from the
 * functions of that unit and from the callers' use of them.
 */
#ifndef GAME_GOALS_TU_8027A84C_H
#define GAME_GOALS_TU_8027A84C_H

#include "game/chooser.h"

struct Unk8027A84C;

/* Object whose position/velocity helpers fn_8018959C and fn_80189618 take;
 * only +0x36C is read here (fn_8027B924, fn_8018959C). */
struct Unk8018959C_Obj {
    char pad0[0x36C];
    int m36C;
};

/* Motion state object passed to fn_8027AD3C (null for "none"): a larger relative
 * of Unk8027A9AC_Req. Evidence: matrix at +0 (fn_8037B128/fn_8037B1F0), +0xA0 and
 * +0xBC as in the request, +0xCC int and +0xD0 float read by fn_8027AD3C. */
struct Unk8027AD3C_Obj {
    Unk8037B128_Mtx mtx;
    char pad40[0xA0 - 0x40];
    int mA0;
    char padA4[0xBC - 0xA4];
    int mBC;
    char padC0[0xCC - 0xC0];
    int mCC;
    float mD0;
};

struct Unk8027BBA8_Obj;

/* Request record built on the stack by fn_8027A9AC / fn_8027AAB0 and passed
 * to fn_8038614C / fn_80386110 (size 0xC0). Evidence: both functions zero
 * +0x44 (4-bit field), +0x68..+0x70, +0xA0 and +0xBC first, then set +0x40 and
 * the matrix; +0xA0 receives the first int argument and +0xBC the value 0xB.
 * fn_8037B128 / fn_8037B1F0 read the matrix (position, heading). */
struct Unk8027A9AC_Zero3 {
    int m0;
    int m4;
    int m8;

    Unk8027A9AC_Zero3()
    {
        m0 = 0;
        m8 = 0;
        m4 = 0;
    }
};

struct Unk8027A9AC_Req {
    Unk8037B128_Mtx mtx;
    float m40;
    unsigned int type : 4;
    unsigned int pad44 : 28;
    char pad48[0x68 - 0x48];
    Unk8027A9AC_Zero3 m68;
    char pad74[0xA0 - 0x74];
    int mA0;
    char padA4[0xBC - 0xA4];
    int mBC;

    Unk8027A9AC_Req()
    {
        type = 0;
        mBC = 0;
        mA0 = 0;
    }
};

extern const Unk8037B128_Mtx lbl_8060E938;       /* identity-like initial matrix (other unit's .rodata) */

Unk80273498_Vec3 fn_8037B128(const Unk8037B128_Mtx* m);   /* position (row 3) */
float fn_8037B1F0(const Unk8037B128_Mtx* m);              /* heading */
void fn_8037D768(Unk80270BA0_X* x);
Unk80273498_Vec3 fn_8018959C(float f, Unk8018959C_Obj* o);
Unk80273498_Vec3 fn_80189618(float f, Unk8018959C_Obj* o);
int fn_8024D41C(Unk80270BA0_X* x);
int fn_80380964(Unk80271DBC_Link* link);
int fn_801BBC30(int v);
int fn_801BBEFC(int v);
int fn_8018AD2C(Unk80273498_Pos* p);
void fn_80249B40(Unk80270BA0_X* x, float f, int a, int b, int c);
void fn_80249DF8(Unk80270BA0_X* x, int a);
void fn_80249958(Unk80270BA0_X* x, Unk80273498_Vec3* v, int a, float f);
void fn_80249B08(Unk80270BA0_X* x, int a, float f);
extern const Unk80273498_Vec3 lbl_806055AC;
extern int lbl_8061B9C8;
int fn_80386110(Unk80271DBC_Link* link, Unk8027A9AC_Req* req, int a, int b, float* c, int flags);
int fn_8038614C(Unk80271DBC_Link* link, Unk8027A9AC_Req* req, int a, int b, float* c, int d, int e, int f, int flags);

/* Object that embeds the goals. Evidence: fn_8027A84C stores owner+0x104 and
 * owner+0x294 in the goal; fn_8027A8F0 reads +0x0; fn_8027A90C and
 * fn_8027A918 read +0xC (the player, Unk80270BA0_X); fn_8027C67C switches on
 * +0x10 and returns +0x18 (the goal storage). */
struct Unk8027A84C_Owner {
    Unk8027A84C_Owner* m0;
    char pad4[0xC - 0x4];
    Unk80270BA0_X* mC;
    int m10;
    char pad14[0x18 - 0x14];
    char m18[0x104 - 0x18];
    char m104[0x294 - 0x104];
    char m294[4];

    Unk8027A84C* fn_8027C67C();
};

/* Goal base. Evidence: fn_8027A84C (constructor-like: stores +0xC, +0x28..+0x48),
 * fn_8027A898 (+0x1C vector, +0x2C non-zero flag), fn_8027A928 (+0x38 selector),
 * fn_8027A8F0 / fn_8027A90C / fn_8027A918 (+0x44 owner). The goal at
 * owner+0x104 is its own root: +0x4 points to it and its +0x48 to the active goal. */
struct Unk8027A84C {
    int m0;
    Unk8027A84C* m4;
    void* m8;
    int mC;
    char pad10[0x1C - 0x10];
    Unk80273498_Vec3 m1C;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    Unk8027A84C_Owner* m44;
    Unk8027A84C* m48;

    void fn_8027A84C(Unk8027A84C_Owner* owner);
    void fn_8027A898(const Unk80273498_Vec3* v);
    Unk8027A84C_Owner* fn_8027A8F0();
    Unk80270BA0_X* fn_8027A90C();
    Unk8014D8AC_Ctx* fn_8027A918();
    float fn_8027A928();
    int fn_8027B2CC(Unk80270BA0_X* p);
    int fn_8027B2F0(int x);
    Unk80273498_Pos* fn_8027B304(Unk80270BA0_X* p);
    Unk80273498_Vec3 fn_8027AF54(unsigned int idx);
    int fn_8027A9AC(Unk80270BA0_X* x, int a, int b, float* c, int d, int e, int f);
    int fn_8027AAB0(Unk80270BA0_X* x, int a, int b, float* c, Unk80273498_Vec3* d, float* e, int f);
    void fn_8027AC90(Unk8037B128_Mtx* m, int n, int unused, Unk80273498_Vec3* out);
    int fn_8027B1A0(Unk80270BA0_X* x, const Unk80273498_Vec3* pos);
    int fn_8027B924(Unk80270BA0_X* x, Unk8018959C_Obj* o, float f);
    int fn_8027BA64(float a, float b, float c);
    void fn_8027AD3C(Unk80270BA0_X* x, Unk8027AD3C_Obj* o, Unk80273498_Vec3* outPos, float* outHeading,
                     float* outSpeed, int* outA, int* outB, int* outC);
    void fn_8027AFA8(Unk8014D8AC_Ctx* ctx, Unk80270BA0_X* x, int a);
    void fn_8027B31C(int state, const Unk80273498_Vec3* pos, float angle, const Unk80273498_Vec3* target, int flag,
                     float* out1, float* out2, Unk80273498_Vec3* outPos);
    int fn_8027BB88(Unk80270BA0_X* x, Unk8027BBA8_Obj* o, int a, int b, int c);
    int fn_8027BBA8(Unk80270BA0_X* x, Unk8027BBA8_Obj* o, int a, int b, int c);
};

/* Small object with a vtable at 0x806626A8 (slot 1 = 0x8035EB48, a dtor that
 * sets the vptr and deletes; slot 2 empty) and a constructor at 0x8027C654.
 * The vptr is at +0x8 after two data words, which g++ 2.95 only produces when
 * the polymorphic part is a second base (with an inline constructor, so that
 * only one vptr store is emitted); +0xC, +0x10, +0x14 are own data. The
 * constructor leaves +0x10 untouched. */
struct Unk8027C654_Base {
    int m0;
    int m4;
};
class Unk8027C654_VBase {
public:
    Unk8027C654_VBase() {}
    virtual void fn_vslot1();
    virtual void fn_vslot2();
};
class Unk8027C654 : public Unk8027C654_Base, public Unk8027C654_VBase {
public:
    Unk8027C654();
    int mC;
    int m10;
    int m14;
};

#endif /* GAME_GOALS_TU_8027A84C_H */
