/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic between cShortestPathChooser and catchgoal.cpp.
 * Original file name unknown; placeholder. 18 functions.
 *
 * .text 0x8027FD64-0x80283934, .rodata 0x805DD24C-0x805DD3F4, .data 0x8061E6D0-0x8061E6D4.
 */
#include "game/chooser.h"
#include "game/goals/tu_8027FD64.h"

float lbl_8061E6D0 = 45.0f;
extern Unk80273498_Vec3 lbl_805DED28;

void fn_80280418(Unk8027FD64_Goal* g, Unk80270BA0_X* x, int d);
int fn_802834E8(Unk8027FD64_Goal* g, Unk80270BA0_X* x, int c);

int fn_8027FD64(Unk8027FD64_Goal* g, Unk80270BA0_X* x)
{
    if (g->mE8.f10) {
        float angle = Unk8027FD64_GetAngle(&x->m734);
        float unused1;             /* never read: reserves stack slot 0xC */
        float diff = AngleDiff(angle, 0.0f);
        if (fabsf(diff) < 0.7853982f) {
            return 1;
        }
    }
    return 0;
}

float fn_80280230(Unk8027FD64_Goal* g, Unk80270BA0_X* x, int c)
{
    Unk80280230_Anim* pl = (Unk80280230_Anim*)x->m618;
    float b = 0.0f;
    float a = 0.0f;
    Unk80386110_Query q;

    q.mBC = 0;
    if (g->m78 == 1) {
        int h = pl->m838;
        if (h != 0x7942CA79 && h != 0xCA50EF74 && h != 0x9FE2E6D1 && h != 0xA84A0C58 && h != 0xF90D27A1) {
            fn_80386110(pl, &q, 0xFA52B1B5, lbl_806242B4, &a, 0);
        }
    } else if (g->m78 == 8) {
        if (pl->m838 == 0x225A007B) {
            fn_80386110(pl, &q, 0x225A007B, lbl_806242B4, &a, 0);
        }
    }
    fn_80386110(pl, &q, c, fn_8027FC20(g, *(int*)g), &b, 0);
    b += a;
    return b;
}

void fn_802803A4(Unk8027FD64_Goal* g, Unk80270BA0_X* x, int c, int d)
{
    fn_80280418(g, x, d);
    if (fn_802834E8(g, x, c)) {
        fn_80280418(g, x, d);
        fn_802834E8(g, x, c);
    }
}

/* Both history slots of the int table at +0x168. The m190 == 1 slot is written
 * at index m190 - 1: CSE knows that is 0 and puts the zero in t's register, so
 * for t == 0 the offset becomes a register constant ("li r9,0x168; stwx"), for
 * t == 1 a displacement, as in retail. Taking &x->m734 at each call (no
 * pointer local) keeps the pointer unflagged, so the offset gets BASE_REGS. */
inline void Unk8027FD64_SetBoth168(Unk802726BC_Angles* p, int t)
{
    if (p->m190 == 1) {
        Unk8027FD64_SetSlot168(p, p->m190 - 1, t);
    }
    Unk8027FD64_SetSlot168(p, p->m190, t);
}

/* Squared xz distance; both vectors by reference. */
inline float Unk8027FD64_DistSqXZ(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.z - b.z) * (a.z - b.z);
}

/* Copy of a vector with y cleared: by-value parameter and return give
 * retail's two frame copies (0x10, 0x20). */
inline Unk80273498_Vec3 Unk8027FD64_FlatY(Unk80273498_Vec3 v)
{
    v.y = 0.0f;
    return v;
}

/* Returning the byte as int keeps the later `> 1` a signed compare (cmpwi);
 * a direct unsigned char read is shortened to cmplwi. */
inline int Unk8027FD64_Get1CC9(Unk80270BA0_X* x)
{
    return ((Unk8027FD64_Ctx*)x->m44C)->m6F8->m14->m1CC9;
}

void fn_80280F08(Unk8027FD64_Goal* g, Unk80270BA0_X* x)
{
    Unk8027FD64_SetBoth168(&x->m734, 0);
    if (g->mE8.f1 && g->m74 == 2 && g->mA0 == 0) {
        Unk8027FD64_Ctx* ctx = (Unk8027FD64_Ctx*)x->m44C;
        int active = 0;

        if (fn_80257B40(ctx->m700->m3B4)->m458 == 9) {
            active = 1;
        } else if (Unk8027FD64_Get1CC9(x) > 1) {
            active = 1;
        }
        if (active) {
            float d2 = Unk8027FD64_DistSqXZ(Unk8027FD64_FlatY(ctx->m680->fn_GetPos()), lbl_805DED28);

            if (!(d2 <= lbl_8061E6D0 * (lbl_8061E6D0 * 144.0f))) {
                Unk8027FD64_SetBoth168(&x->m734, 1);
            }
        }
    }
}

float fn_802816D0(Unk8027FD64_Goal* g, Unk8014D8AC_Ctx* ctx)
{
    float result = 0.0f;
    float r;
    float scale = 1.0f;

    r = (float)(unsigned int)ctx->m554->fn_8014D8AC(1000000, UNK8027FD64_CATCHGOAL_FILE, 2775) * scale * 0.000001f;

    if (!(r >= 0.33f)) {
        result = -60.0f;
    }
    if (!(r <= 0.66f)) {
        result = 60.0f;
    }
    return result;
}

void fn_80282B78(Unk8027FD64_Goal* g, Unk80270BA0_X* x, float f)
{
    float lim = 76176.0f;

    g->mE8.f4 = 0;
    g->mE8.f5 = 0;
    g->m94 = 5;
    if (!g->fn_IsF14()) {
        int hit = fn_8024D41C(x);

        if (hit) {
            g->m94 = 5;
            g->mE8.f4 = f < lim;
            g->mE8.f5 = 0;
        } else {
            g->m94 = 0;
            g->mE8.f4 = 1;
            Unk8027FD64_Ctx* ctx = (Unk8027FD64_Ctx*)x->m44C;
            int t = 0;
            if (ctx->m6CC && ctx->m6CC->m38C == 1) {
                t = f < lim;
            }
            g->mE8.f5 = t;
        }
    }
}

void fn_80282C58(Unk8027FD64_Goal* g, unsigned int* out1, int* out2)
{
    *out1 = 0xEA68D008;
    *out2 = 0;
    if (g->mE8.f5) {
        *out2 = fn_80296998(g->m4, 8, 0);
    } else {
        *out2 = fn_80296998(g->m4, 0x10, 0);
    }
}

void fn_80282CC0(Unk8027FD64_Goal* g, Unk80270BA0_X* p)
{
    float c1 = 0.52359885f;
    float c2 = 1.5f;

    if (g->mE8.f8) {
        if (g->m2C) {
            float ang = fn_80410ABC(g->fn_GetVec().y / Length(g->fn_GetVec()));
            Unk80273498_Vec3 rel = g->fn_80286E70();

            if (!(rel.y <= 48.0f)) {
                if (!(ang <= c1) && !(g->m80 <= c2)) {
                    g->mE8.f9 = 1;
                    Unk8014D8AC_Ctx* ctx = p->m44C;
                    g->m8C = fn_802816D0(g, ctx);
                    if (!(Unk8027FD64_Abs(g->m8C) <= 0.0f)) {
                        g->m90 = 0.0f;
                    } else {
                        g->m90 = fn_802816D0(g, ctx);
                    }
                    g->mE8.f22 = 1;
                }
            } else {
                float thr = 0.26179942f;

                if (!(ang <= thr)) {
                    g->mE8.f10 = 1;
                }
            }
        }
    }
}

int fn_80282E5C(Unk8027FD64_Goal* g)
{
    int result = 0;

    if (g->fn_IsF12() || g->fn_IsF11()) {
        Unk8027B304_Obj* o = fn_8027B304(g);
        if (o) {
            float v = o->m3F4;
            float d = o->fn_8018CDB8(v, 10) - v;
            result = d < g->m80;
        }
    }
    return result;
}

class Unk8027A05C {
public:
    float fn_8027A280(int a);
};

struct Unk802831B0_Ext {
    char pad0[0xD4];
    float mD4;
};

int fn_802831B0(Unk8027FD64_Goal* g, Unk80270BA0_X* x, float a, Unk802831B0_Ext* p, int c, float b)
{
    float lo, mid, hi, r, t;

    if (!(b <= 36.0f)) {
        lo = fn_80248FC8(x, 1);
        mid = fn_80248FC8(x, 0);
        hi = fn_80248FC8(x, 2);
        r = lo;
        if (!(b >= 60.0f)) {
            t = (b - 36.0f) * 0.041666668f;
            r = t * (lo - mid) + mid;
        }
        if (g->mE8.f14) {
            r = mid;
        } else if (g->mE8.f17) {
            r = hi;
        }
        int kind = g->m38;
        if (g->m3C != -1) {
            kind = g->m3C;
        }
        if (kind == 4) {
            t = fn_80248FC8(x, 2) - 39.37008f;
            if (c) {
                t = fn_80248FC8(x, 1);
            }
            r = t;
        }
        return a < r;
    }
    if (!(g->m80 > 0.0f)) {
        return 1;
    }
    int idx = fn_8027FC20(g, g->m0);
    t = g->m8->fn_8027A280(idx);
    r = b / fn_80248FC8(x, 1);
    t += r;
    if (p) {
        t += p->mD4;
    }
    mid = 0.25f;
    hi = t / g->m80;
    if (g->mE8.f1 && g->m68 == 7) {
        mid = 0.6f;
    }
    return hi < 1.0f - mid;
}

void fn_802833E8(void* unused, Unk802833E8_Req* o, int a5, int a6, int a7, Unk80273498_Vec3* v, float* f1, float* f2)
{
    if (a6) {
        o->fn_80279F40(a6);
    } else {
        o->fn_80279DD0(a5);
    }
    if (v) {
        o->fn_8037B10C(*v);
        o->mBC |= 1;
    }
    if (f1) {
        o->fn_SetScale(*f1);
        o->mBC |= 1;
    }
    if (f2) {
        o->fn_SetD0(*f2);
    }
    o->m40 = 0.0f;
    o->mBC |= 2;
    if (a7) {
        o->mA0 = a7;
        o->mBC |= 8;
    }
}
