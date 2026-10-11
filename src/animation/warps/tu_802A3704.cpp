/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11); original file name unknown, placeholder.
 *
 * .text 0x802A3704-0x802A4584, .rodata 0x805DE11C-0x805DE2F8, .data 0x8061E86C-0x8061E87C.
 *
 * Classes (names from vtable slot 3 -> name pointer -> string):
 * cCycleTimeWarp (vtable 0x80661E20), cGeneralRotationWarp (0x80661DA0),
 * cSetPosRotWarp (0x80661D20), cFudgePosRotWarp (0x80661CA0).
 *
 * All four derive from Unk8035EAE8 (dtor 0x8035EAE8, slots 11-14 empty
 * functions at 0x8035EB08..0x8035EB14), which derives from the root Unk8037B3E8
 * (see include/game/warp.h). The warps' ctors call the root ctor directly
 * (the mid class has an inline ctor), and the dtors pass their in-charge
 * argument on to fn_8035EAE8. Slot 3/4 and the vtables sit in the unity TU's
 * tail (0x802ACBA4..0x802ACBF8).
 */
#include "game/warp.h"

/* Class name; read by cCycleTimeWarp's vtable slot 3 (0x802ACBA4). */
const char* lbl_8061E86C = "cCycleTimeWarp";

class cCycleTimeWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cCycleTimeWarp();
    virtual void fn_vslot2();
    virtual ~cCycleTimeWarp();
    virtual void fn_vslot12(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h);
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* "enabled" */
};

cCycleTimeWarp::cCycleTimeWarp() : Unk8035EAE8(0x395EE741u)
{
    m4 = 1;
}

void cCycleTimeWarp::fn_vslot2()
{
    fn_8037B458("enabled", &m4, 0, 0);
}

cCycleTimeWarp::~cCycleTimeWarp()
{
}

void cCycleTimeWarp::fn_vslot12(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h)
{
    float total = 0.0f;

    if (m4) {
        int n = h->count;

        for (int i = 0; i < n; i++) {
            total += e[i].m1C;
        }
        if (total != 0.0f) {
            float acc = 0.0f;

            total = 1.0f / total;
            for (int i = 0; i < n; i++) {
                acc += (e[i].m10 - e[i].m14) * total * e[i].m1C;
            }
            for (int i = 0; i < n; i++) {
                e[i].m10 = e[i].m14 + acc;
            }
        }
    }
}

Unk8037B3E8* cCycleTimeWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cCycleTimeWarp;
}

/* Class name; read by cGeneralRotationWarp's vtable slot 3 (0x802ACBBC). */
const char* lbl_8061E870 = "cGeneralRotationWarp";

extern unsigned int lbl_8068D5A4;    /* type hash, set by the static initializer fn_802AA7A4 */

class cGeneralRotationWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cGeneralRotationWarp();
    virtual void fn_vslot2();
    virtual ~cGeneralRotationWarp();
    virtual void fn_vslot13(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    float m4;                  /* "Direction" */
};

cGeneralRotationWarp::cGeneralRotationWarp() : Unk8035EAE8(lbl_8068D5A4)
{
    m4 = 0.0f;
}

void cGeneralRotationWarp::fn_vslot2()
{
    fn_8037B50C("Direction", &m4, "-6.29,6.29,3", 0);
}

cGeneralRotationWarp::~cGeneralRotationWarp()
{
}

void cGeneralRotationWarp::fn_vslot13(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h, Unk80270BA0_Obj* obj)
{
    char buf[0x220];           /* unused local that retail allocates (frame 0x228); real type unknown */
    obj->fn_vslot1();
}

Unk8037B3E8* cGeneralRotationWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cGeneralRotationWarp;
}

/* Class name; read by cSetPosRotWarp's vtable slot 3 (0x802ACBD4). */
const char* lbl_8061E874 = "cSetPosRotWarp";

extern unsigned int lbl_8068D5A8;    /* type hash, set by the static initializer fn_802AA7A4 */

class cSetPosRotWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cSetPosRotWarp();
    virtual void fn_vslot2();
    virtual ~cSetPosRotWarp();
    virtual void fn_vslot13(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* "SetPos" */
    int m8;                    /* "SetDir" */
};

cSetPosRotWarp::cSetPosRotWarp() : Unk8035EAE8(lbl_8068D5A8)
{
    m8 = 0;
    m4 = 0;
}

void cSetPosRotWarp::fn_vslot2()
{
    fn_8037B458("SetDir", &m8, 0, 0);
    fn_8037B458("SetPos", &m4, 0, 0);
}

cSetPosRotWarp::~cSetPosRotWarp()
{
}

void cSetPosRotWarp::fn_vslot13(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h, Unk80270BA0_Obj* obj)
{
    int n = h->count;

    if (e->m10 < e->m14 || e->m14 == 0.0f || n == 0) {
        Unk80270BA0_X* x = obj->fn_vslot1();

        if (m4) {
            x->fn_vslot3(x->GetM320());
        }
        if (m8) {
            x->fn_80244858(x->GetM32C().y);
        }
    }
}

Unk8037B3E8* cSetPosRotWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cSetPosRotWarp;
}

/* Class name; read by cFudgePosRotWarp's vtable slot 3 (0x802ACBEC). */
const char* lbl_8061E878 = "cFudgePosRotWarp";


/* Helper types of fn_802A3D8C (all layouts inferred from that one function). */
extern int lbl_806242B0;     /* "no event" ids compared against the warp's event handles */
extern int lbl_806242B4;
extern char lbl_806EF9C7;    /* default event value */

/* Entry of the event list: id at +0, time at +8 (stride 0x10). */
struct Unk8037E64C_Entry {
    int id;
    int m4;
    float m8;
    int mC;
};

class Unk8037E600_U {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual int fn_vslot14();
};

/* Event object returned by Unk8037E64C::fn_8037E600. */
class Unk8037E600_T {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual Unk8037E600_U* fn_vslot13();
};

/* Event list (size 0x10 at +0x10 of Unk8037E64C_Owner). */
class Unk8037E64C {
public:
    int fn_8037E64C(int id);
    Unk8037E600_T* fn_8037E600(int idx);
    int m0;
    int m4;                    /* count */
    Unk8037E64C_Entry* m8;
    int mC;
};

struct Unk8037E64C_Owner {
    char pad0[4];
    float m4;
    char pad8[0x10 - 8];
    Unk8037E64C m10;
};

/* Animation player chain: Unk802A3D8C_State::m4 -> fn_vslot12 -> fn_vslot18. */
class Unk80384070 {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual Unk8037E64C_Owner* fn_vslot24();
    virtual int fn_vslot25();
    void fn_80384070(Unk80270BA0_Obj* obj, int a, int* ev, Unk80273498_Vec3* out, float* outF, int b, float t);
};

class Unk80384070_Q {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual Unk80384070* fn_vslot18();
};

class Unk80384070_P {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual Unk80384070_Q* fn_vslot12();
};

float fn_80382BD8(Unk80271DBC_Link* p, int a);
int fn_80380964(Unk80271DBC_Link* p);
int fn_80189698(Unk80189698_Ctx* c, float t);
Unk80273498_Vec3 fn_8018959C(Unk80189698_Ctx* c, float t);      /* hidden result pointer in r3 */
void fn_8018C4D0(Unk80189698_Ctx* c, Unk80273498_Vec3* v, int a, float b, float c2, float d);

/* 4x4 matrix built by fn_803DF824 on the stack. */
struct Unk803DF824_Mtx {
    float m[16];
};
void fn_803DF824(Unk803DF824_Mtx* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
void fn_803DFAB4(Unk803DF824_Mtx* m);
void fn_803DED40(Unk803DF824_Mtx* m, const Unk80273498_Vec3* in, Unk80273498_Vec3* out);

/* Local transform object of fn_802A3D8C (size 0x9C, vptr at +0x98 with the
 * vtable at 0x806604F8; ctor inlined, member +0x7C built by fn_80379324). */
struct Unk80379324 {
    Unk80379324();             /* 0x80379324: zeroes the four floats */
    float m0, m4, m8, mC;
};

class Unk8035A618 {
public:
    Unk8035A618();
    virtual ~Unk8035A618();
    virtual void fn_vslot2(float a, float b, float c);
    virtual void fn_vslot3(const Unk80273498_Vec3& v);
    void fn_8035A618();
    void fn_8037D8DC(Unk80273498_Vec3* in, Unk80273498_Vec3* out);
    void SetM74(float a)
    {
        m0 = 0;
        m6C = 0;
        m70.y = a;
    }

    int m0;
    char pad4[0x60 - 4];
    Unk80273498_Vec3 m60;
    int m6C;
    Unk80273498_Vec3 m70;
    Unk80379324 m7C;
    float m8C;
    float m90;
    float m94;
};

inline Unk8035A618::Unk8035A618()
{
    fn_8035A618();
}

inline Unk8035A618::~Unk8035A618()
{
}

class cFudgePosRotWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cFudgePosRotWarp();
    virtual void fn_vslot2();
    virtual ~cFudgePosRotWarp();
    virtual void fn_vslot11(Unk802A3D8C_State* st, Unk80270BA0_Obj* obj);
    virtual void fn_vslot14(Unk80270BA0_Obj* obj, Unk8037B128* b);
    virtual Unk8037B3E8* fn_vslot5();
    void fn_802A3D8C(const Unk80273498_Vec3& a, Unk802A3D8C_State* st, Unk80270BA0_X* x, int flag, int n, const Unk80273498_Vec3& pos, float yaw);

    int m4;                    /* "Start" */
    int m8;                    /* "End" */
    int mC;                    /* "Enter" */
    int m10;                   /* "Target" */
};

cFudgePosRotWarp::cFudgePosRotWarp() : Unk8035EAE8(0x1B26D314u)
{
}

void cFudgePosRotWarp::fn_vslot2()
{
    fn_8037B638("Start", &m4, "_start_time_event_,Start,cReleaseBall,cCatchBall,cTouchBase,cBeginWarp");
    fn_8037B638("End", &m8, "_end_time_event_,End,cReleaseBall,cCatchBall,cTouchBase,cEndWarp");
    fn_8037B638("Enter", &mC, "_enter_event_,Start,cBlend1,cBlend2,cBlend3,cBeginWarp");
    fn_8037B638("Target", &m10, "_target_event_,End,cReleaseBall,cCatchBall,cTouchBase,cEndWarp");
}

cFudgePosRotWarp::~cFudgePosRotWarp()
{
}

void cFudgePosRotWarp::fn_vslot11(Unk802A3D8C_State* st, Unk80270BA0_Obj* obj)
{
    Unk80270BA0_X* x = obj->fn_vslot1();
    Unk80273498_Vec3 a = x->GetM93C();
    Unk80273498_Vec3 pos = x->m60;

    fn_802A3D8C(a, st, x, 1, x->m618->m838, pos, fn_80382BB8(x->m618));
}

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline float LengthSq(Unk80273498_Vec3 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

/* Within maxY vertically and sqrt(maxD2) overall. */
inline int InRange(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b, float maxD2, float maxY)
{
    int ok = 1;
    float dy = a.y - b.y;

    if (dy > maxY) {
        ok = 0;
    } else {
        float len2 = LengthSq(a - b);

        if (!(len2 <= maxD2)) {
            ok = 0;
        }
    }
    return ok;
}

inline void Query(Unk80384070* r, Unk80270BA0_Obj* o, int ev, Unk80273498_Vec3* out, float* outF, float t)
{
    r->fn_80384070(o, 1, &ev, out, outF, 0, t);
}

/* near-miss (464 vs 465 instructions, ~94% of the instruction sequence). Left:
 * - the callee-saved registers of st and x are swapped (retail: st r31, x r29);
 * - retail keeps x+0x734 in a register and indexes with (idx*4)+0x48; here the
 *   offset folds into x+0x77C (tried: reference, pointer, inline getter);
 * - the matrix, result and subtraction temporaries sit 0x20 lower than in
 *   retail, which keeps the debug block's locals (q, r, InRange's floats) alive
 *   to the end of the function. Declaring them at function scope fixes the
 *   slots but changes the register allocation (kept out: 86% overall);
 * - scheduling of the second Query call's argument setup. */
void cFudgePosRotWarp::fn_802A3D8C(const Unk80273498_Vec3& a, Unk802A3D8C_State* st, Unk80270BA0_X* x, int flag, int n, const Unk80273498_Vec3& pos, float yaw)
{
    if (a.y == -1000.0f) {
        return;
    }
    Unk80271DBC_Link* link = x->m618;
    float t = 0.0f;
    int ok = 1;

    if (flag) {
        ok = fn_80380964(link) == 0;
        t = fn_80382BD8(link, 0);
    } else if (n == link->m838) {
        t = fn_80382BD8(link, 0);
    } else {
        t = 0.0f;
    }
    if (st->m24 != 0 || !ok) {
        return;
    }

    Unk80384070* player = st->m4->fn_vslot12()->fn_vslot18();
    Unk8037E64C_Owner* owner = player->fn_vslot24();
    Unk8037E64C* list = &owner->m10;
    float cnt = (float)player->fn_vslot25();

    st->m3C = t;
    float start = t * (cnt - 1.0f);
    float v;
    float lo;
    float w;

    if (m4 != 0 && m4 != lbl_806242B0) {
        int idx = list->fn_8037E64C(m4);
        if (idx >= 0) {
            v = list->m8[idx].m8 / cnt;
            if (!(v <= st->m3C)) {
                st->m3C = v;
            }
        }
    }
    st->m40 = 1.0f;
    if (m8 != 0 && m8 != lbl_806242B4) {
        int idx = list->fn_8037E64C(m8);
        if (idx >= 0) {
            v = list->m8[idx].m8 / cnt;
            if (!(v >= st->m40)) {
                st->m40 = v;
            }
        }
    }
    v = 9999.0f;
    int ev = lbl_806EF9C7;
    if (m10 != 0 && m10 != lbl_806242B4) {
        int idx = list->fn_8037E64C(m10);
        if (idx >= 0) {
            v = list->m8[idx].m8;
            ev = list->fn_8037E600(idx)->fn_vslot13()->fn_vslot14();
        }
    }
    lo = start;
    if (mC != lbl_806242B0) {
        int idx = list->fn_8037E64C(mC);
        if (idx >= 0) {
            w = list->m8[idx].m8;
            if (!(w <= lo)) {
                lo = w;
            }
        }
    }

    Unk80273498_Vec3 p30;
    Unk80273498_Vec3 p40;

    Query(player, x, ev, &p30, 0, v);
    if (flag && m10 == 0x971949A6) {
        Unk80189698_Ctx* c = x->m44C->m6CC;
        float d = v - start;
        Unk802726BC_Angles& ang = x->m734;
        float k = ang.m48[ang.m190];

        d = d / owner->m4;
        if (!(k <= 0.0f)) {
            d = d / k;
        }
        Unk80273498_Vec3 q = a;
        if (fn_80189698(c, d) == 3) {
            Unk80273498_Vec3 r = fn_8018959C(c, d);
            int near = InRange(r, q, 14400.0f, 60.0f);

            if (near) {
                q.y = p30.y * x->mAB4;
                fn_8018C4D0(c, &q, 0, 0.0f, d, -1.0f);
            }
        }
    }
    Query(player, x, lbl_806EF9C7, &p40, &w, lo);
    p30.x = p30.x - p40.x;
    p30.y = 0.0f;
    p30.z = p30.z - p40.z;
    if (x->fn_vslot4()) {
        Unk8035A618 rot;
        Unk80273498_Vec3 q;

        rot.SetM74(-w);
        rot.fn_8037D8DC(&p30, &q);
        p30.x = -q.x;
        p30.y = q.y;
        p30.z = q.z;
    }
    Unk80273498_Vec3 base = x->m8C;
    Unk803DF824_Mtx m;

    fn_803DF824(&m, base.x, base.y, base.z, 0.0f, yaw * 57.295773f, 0.0f, pos.x, pos.y, pos.z);
    fn_803DFAB4(&m);
    Unk80273498_Vec3 res;
    fn_803DED40(&m, &a, &res);
    st->m30 = res - p30;
    st->m30.y = 0.0f;
    if (flag) {
        if (x->fn_vslot4()) {
            st->m30.x = -st->m30.x;
        }
    }
    st->m24 = 1;
}

void cFudgePosRotWarp::fn_vslot14(Unk80270BA0_Obj* obj, Unk8037B128* b)
{
    Unk80273498_Vec3 pos = b->fn_8037B128();
    float yaw = b->fn_8037B1F0();
    Unk80270BA0_X* x = obj->fn_vslot1();

    fn_802A3D8C(b->mA4, &b->m44, x, 0, b->mA0, pos, yaw);
}

Unk8037B3E8* cFudgePosRotWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cFudgePosRotWarp;
}
