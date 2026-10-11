/*
 * Types for animation/goals/tu_80299920.cpp (goal logic, 0x80299920-0x8029B6C8).
 *
 * Nothing here comes from original headers: layouts are inferred from the
 * functions in that unit and its neighbours. Names are placeholders
 * (Unk<addr> = class named after its first function, fn_<addr>, m<offset>).
 */
#ifndef GAME_GOALS_TU_80299920_H
#define GAME_GOALS_TU_80299920_H

#include "game/chooser.h"
#include "game/goals/tu_8027A84C.h"

typedef Unk80273498_Vec3 Vec3;

struct Unk80299920_Req;
struct Unk80299920_Out;
struct Unk80299920_Ref;
class Unk80299920_XV;

/* Object at ctx+0x6B8; fn_8018514C returns a height for a position. */
struct Unk8018514C_Obj {
    float fn_8018514C(Vec3 v, Vec3* out);
};
inline float Unk8018514C_Height(Unk8018514C_Obj* o, Vec3 v)
{
    Vec3 out;

    return o->fn_8018514C(v, &out);
}

/* Flag word at goal+0xD0. fN is bit N counted from the most significant bit
 * (mask 0x80000000 >> N); fn_8029B520 clears and sets several adjacent bits and
 * fn_8029B648 sets/clears f1. */
struct Unk80299920_Flags {
    unsigned int f0 : 1, f1 : 1, f2 : 1, f3 : 1, f4 : 1, f5 : 1, f6 : 1, f7 : 1;
    unsigned int f8 : 1, f9 : 1, f10 : 1, f11 : 1, f12 : 1, f13 : 1, f14 : 1, f15 : 1;
    unsigned int f16 : 1, f17 : 1, f18 : 1, f19 : 1, f20 : 1, f21 : 1, f22 : 1, f23 : 1;
    unsigned int f24 : 1, f25 : 1, f26 : 1, f27 : 1, f28 : 1, f29 : 1, f30 : 1, f31 : 1;
};

/* Position holder behind ctx+0x6CC (chooser.h's Unk80273498_Pos has more):
 * the player it is bound to at +0x36C, position at +0x60. */
struct Unk80299920_Pos {
    char pad0[0x36C];
    Unk80270BA0_X* m36C;
};

/* Object behind goal+0x50 (a player?): +0x5B4 a mode, +0x934 an object. */
struct Unk80299920_Tgt {
    char pad0[0x5B4];
    int m5B4;
    char pad5B8[0x934 - 0x5B8];
    int m934;
};

/* Goal object ("this" of most functions here); it extends the Unk8027A84C base
 * (the base methods are reached through a cast). Offsets seen: +0 and +0xC
 * phase counters, +0x10 position, +0x1C direction (x, z at +0x24), +0x28 and
 * +0x2C flags, +0x48 kind, +0x4C target holder (position at +0x60), +0x50
 * object, +0x54/+0x58/+0x5C floats, +0x60 flag. */
struct Unk80299920_Goal {
    int m0;
    char pad4[0xC - 4];
    int mC;
    Vec3 m10;
    Vec3 m1C;
    int m28;
    int m2C;
    char pad30[0x48 - 0x30];
    int m48;
    int m4C;
    Unk80299920_Tgt* m50;
    union {
        float m54;
        int m54i;
    };
    float m58;
    float m5C;
    int m60;
    char pad64[0x6C - 0x64];
    float m6C;
    char pad70[4];
    float m74;
    float m78;
    float m7C;
    float m80;
    float m84;
    float m88;
    float m8C;
    int m90;
    float m94;
    float m98;
    Vec3 m9C;
    float mA8;
    Vec3 mAC;
    Vec3 mB8;
    int mC4;
    float mC8;
    int mCC;
    Unk80299920_Flags mD0;

    Vec3 GetM10() const { return m10; }
    int fn_80299920(Unk80270BA0_X* x);
    void fn_802999D4(float t, Unk80270BA0_X* x, Unk80299920_Req* req, int a6, Vec3* out, int unused, int n);
    int fn_80299AE8(const Unk80299920_Goal* o) const;
    void fn_80299EE4();
    Unk80299920_Goal* fn_80299F0C(Vec3* v);
    void fn_80299F5C(Unk80299920_Tgt* t);
    void fn_80299F64(int v);
    int fn_80299F6C(Unk80299920_XV* x);
    void fn_80299FD4(Unk80299920_XV* x);
    int fn_8029A308(Unk80299920_XV* x, unsigned int hash);
    int fn_8029A54C(Unk80299920_XV* x);
    float fn_8029A5C4(Unk80299920_XV* x, Vec3* target, Unk8027AD3C_Obj* obj, int flag);
    int fn_8029A768(Unk80299920_XV* x);
    int fn_8029A788(Unk80299920_XV* x);
    float fn_8029A948();
    void fn_8029A9A4(float t, Unk80299920_XV* x, Unk80299920_Req* req, int k, Unk80299920_Out* out, Unk80299920_Ref* ref, int c);
    void fn_8029AC74(float* outA, int* outB);
    unsigned int fn_8029ADC8(int kind);
    unsigned int fn_8029B000(int k);
    void fn_8029B030(Unk80299920_XV* x, Unk8027AD3C_Obj* obj, int flag);
    int fn_8029B3F8(const Unk80299920_Goal* o) const;
    void fn_8029B520();
    Unk80299920_Goal* fn_8029B648(const Vec3* v);
};

/* View of the context at Unk80270BA0_X+0x44C (chooser.h's Unk8014D8AC_Ctx has
 * more): +0x4C tick counter, +0x6B8 object passed to fn_8018514C, +0x6CC
 * position holder, +0x6F4 mode. */
struct Unk80299920_Ctx {
    char pad0[0x4C];
    unsigned int m4C;
    char pad50[0x6B8 - 0x50];
    Unk8018514C_Obj* m6B8;
    char pad6BC[0x6CC - 0x6BC];
    Unk80299920_Pos* m6CC;
    char pad6D0[0x6F4 - 0x6D0];
    int m6F4;
};

/* chooser.h's angle block with the saved index right after it (+0x194):
 * fn_8029AC74 parks m190 there while it queries. */
struct Unk80299920_Angles : public Unk802726BC_Angles {
    int m194;
};

/* Output pair filled by fn_8029A9A4: a position and a second vector. */
struct Unk80299920_Out {
    Vec3 a;
    Vec3 b;
};

/* Object whose +4 is compared with lbl_8061EC9C by fn_8029A9A4. */
struct Unk80299920_Ref {
    int m0;
    int m4;
};

/* Result of fn_80386188's motion query (10th argument): +0x20 a float, +0x24 an int. */
struct Unk80386188_Result {
    char pad0[0x20];
    float m20;
    int m24;
};

/* Component embedded in the player object at +0xA0 (vptr at +0x18, called through
 * slot 13 by fn_80299B98). */
class Unk80299920_Comp {
public:
    char pad0[0x18];
    virtual void fn_comp1();
    virtual void fn_comp2();
    virtual void fn_comp3();
    virtual void fn_comp4();
    virtual void fn_comp5();
    virtual void fn_comp6();
    virtual void fn_comp7();
    virtual void fn_comp8();
    virtual void fn_comp9();
    virtual void fn_comp10();
    virtual void fn_comp11();
    virtual void fn_comp12();
    virtual void fn_comp13();
};

struct Unk80299920_Gap {
    char pad0[4];
};

/* View of the player object (Unk80270BA0_X) with the virtual calls and fields
 * this unit needs: slot 3 takes a position, slot 6 returns another such
 * object. Callers cast; the real declarations are in game/chooser.h. */
class Unk80299920_XVirt : public Unk80270BA0_XBase {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3(const Vec3& v);
    virtual int fn_vslot4();
    virtual void fn_vslot5();
    virtual Unk80299920_XVirt* fn_vslot6();
};

class Unk80299920_XV : public Unk80299920_XVirt, public Unk80299920_Gap, public Unk80299920_Comp {
public:
    char padBC[0x320 - 0xBC];
    Vec3 m320;
    Vec3 m32C;
    char pad338[0x44C - 0x338];
    Unk80299920_Ctx* m44C;
    char pad450[8];
    int m458;
    char pad45C[0x4D8 - 0x45C];
    char m4D8[0x570 - 0x4D8];
    int m570;
    char pad574[0x618 - 0x574];
    Unk80271DBC_Link* m618[3];
    char pad624[0x734 - 0x624];
    Unk80299920_Angles m734;
};

/* Motion request / state record passed to fn_8037B10C (position), fn_8037B16C
 * (angle), fn_80386110/fn_80386188 and Unk8027A84C::fn_8027AC90 (as its matrix).
 * Evidence: fn_802999D4 and fn_8029A9A4 write +0x40, +0xA0, +0xBC, +0xCC, +0xD0,
 * +0xD4 (time) and +0xD8 (valid flag). */
struct Unk80299920_Req {
    void fn_8037B10C(Vec3 v);
    void fn_8037B16C(float f);
    Unk8037B128_Mtx mtx;
    float m40;
    char pad44[0xA0 - 0x44];
    int mA0;
    char padA4[0xBC - 0xA4];
    unsigned int mBC;
    char padC0[0xCC - 0xC0];
    int mCC;
    float mD0;
    float mD4;
    int mD8;

    /* Inline setters: a float parameter of an inline function gets its own
     * stack slot (stored then reloaded), as in fn_802999D4. */
    void SetScale(float f) { fn_8037B16C(f); }
    void SetD0(float f) { mD0 = f; }
    void AddD4(float f) { mD4 = mD4 + f; }
    void SetD4(float f) { mD4 = f; }
};

float fn_80410CE8(float y, float x);
int fn_80381E9C(Unk80271DBC_Link* link, int a, int b, int c);
void fn_803814A4(Unk80271DBC_Link* link, int a, float t, int b);
void fn_80244858(Unk80270BA0_X* x, float v);
extern const Vec3 lbl_806055AC;          /* the zero vector (shared) */
extern const Vec3 lbl_806055DC;          /* another shared 0xC-byte vector */


/* Sets both lanes of a float pair in the angle block when the index is 1,
 * then the indexed lane: the byte offset sits in a local, which keeps the
 * +off out of the indexed store (fn_80299B98, fn_80299FD4, fn_8029B030). */
inline void Unk80299920_SetPair(Unk802726BC_Angles* a, int base, float v)
{
    if (a->m190 == 1) {
        *(float*)((char*)a + base) = v;
    }
    int off = a->m190 * 4 + base;
    *(float*)((char*)a + off) = v;
}
inline void Unk80299920_SetPairI(Unk802726BC_Angles* a, int base, int v)
{
    if (a->m190 == 1) {
        *(int*)((char*)a + base) = v;
    }
    int off = a->m190 * 4 + base;
    *(int*)((char*)a + off) = v;
}
/* Wrappers: the float parameter of each inline level gets its own stack slot. */
inline void Unk80299920_SetM8(Unk802726BC_Angles* a, float f)
{
    Unk80299920_SetPair(a, 8, f);
}
inline void Unk80299920_SetM48(Unk802726BC_Angles* a, float f)
{
    Unk80299920_SetPair(a, 0x48, f);
}
inline Vec3 GetPos(const Unk8037B128_Mtx* m)
{
    Vec3 v = fn_8037B128(m);
    return v;
}
inline Vec3 CopyVec(const Vec3& v)
{
    return v;
}
inline void SetVec(Vec3* dst, Vec3 v)
{
    *dst = v;
}
float fn_80382BB8(Unk80271DBC_Link* p);
int fn_80188EF4(Unk80299920_Pos* p);
void fn_8024D178(Unk80270BA0_X* x, int a);
float fn_8041171C(float x);
float fn_80411554(float x);
extern "C" float fabsf(float x);          /* inlined as fabs */
inline float Unk80299920_Abs(float v)
{
    return fabsf(v);
}
inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}
inline Vec3 Direction(float angle)
{
    Vec3 r;
    r.x = fn_8041171C(angle);
    r.y = 0.0f;
    r.z = fn_80411554(angle);
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
inline float DistSq2D(Vec3 a, Vec3 b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.z - b.z) * (a.z - b.z);
}
inline Vec3 Sub(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
extern int lbl_806242B4;
int fn_80386188(Unk80271DBC_Link* link, Unk8027A9AC_Req* req, unsigned int a, unsigned int b, float* t,
                int c, int d, int e, int f, Unk80386188_Result** res, int flags);
int fn_80386188(Unk80271DBC_Link* link, Unk80299920_Req* req, unsigned int a, unsigned int b, float* t,
                int c, Unk80299920_Ref* d, Unk80299920_Out* e, int f, Unk80386188_Result** res, int flags);
int fn_80386110(Unk80271DBC_Link* link, Unk80299920_Req* req, unsigned int a, unsigned int b, float* t, int flags);
int fn_8026D9D0(Unk80299920_XV* x, Unk80299920_Req* req);
extern signed char lbl_8061EC9C;      /* first byte of a shared 0xC-byte object */
extern int lbl_806242B0;
/* Stack record of float parameters in fn_80299FD4 (+0 ratio, +0x18 upper and +0x1C lower clamp). */
struct Unk80299920_Params {
    float m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    float m1C;
};

/* Query record helper classes (same layouts and names as animation/choosers/tu_80279AE4.cpp,
 * where they are defined; copied here for the goal logic that builds one on the stack). */
class Unk8035EB7C {
public:
    Unk80270BA0_Mtx m0;
    float m40;
    unsigned int m44 : 4;
    unsigned int m44r : 28;
    char pad48[0x68 - 0x48];
    int m68[3];
    char pad74[0xA0 - 0x74];
    int mA0;
    char padA4[0xBC - 0xA4];
    unsigned int mBC;
};
class Unk80279BB8 : public Unk8035EB7C {
public:
    Unk80279BB8();
    void fn_80279DD0(Unk80270BA0_X* x);
    char padC0[0xCC - 0xC0];
    int mCC;
    float mD0;
    float mD4;
    int mD8;
};
void fn_80386110(Unk80271DBC_Link* link, Unk8035EB7C* q, int a, int b, float* out, int c);

/* Event object queued by fn_80299FD4: a base with an id and a vptr (base vtable
 * 0x80649DA0), and a derived class (vtable 0x80660EF0, dtor 0x8035E1AC) that adds the
 * player and a flag. The same event is built in the unit at 0x80247684. */
class Unk80649DA0 {
public:
    Unk80649DA0() {}
    int m0;
    virtual ~Unk80649DA0();
};
class Unk8035E1AC : public Unk80649DA0 {
public:
    Unk8035E1AC(int id, Unk80270BA0_X* x)
    {
        m0 = id;
        m8 = x;
    }
    virtual ~Unk8035E1AC();
    Unk80270BA0_X* m8;
    int mC;
};
void fn_8037893C(void* queue, int id, Unk80649DA0* ev, int a, int b);
int fn_8027D3E8(int a, int b, float* c, int d, int e, int f);
int fn_8026D7B4(Unk80299920_XV* x, int a);
extern const Vec3 lbl_805DED34;
unsigned int fn_80299E54(Unk80270BA0_X* x);
void fn_80299B98(Unk80270BA0_X* x, const Vec3& pos, float* ang);

#endif /* GAME_GOALS_TU_80299920_H */
