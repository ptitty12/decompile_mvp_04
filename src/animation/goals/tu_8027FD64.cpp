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

/* near-miss: 92 of 92 instructions, but the position copy, distance test and
 * their stack temporaries differ from retail (retail keeps two Vec3 copies at
 * sp+0x10 and sp+0x20 and has no dx/dz locals). Tried: an inline by-value
 * Dist2D and getter (extra temp copies), locals for dx/dz, and the order of
 * the zeroing store. The first SetSlot168 store folds its constant index into
 * a displacement here, retail keeps `li r9,0x168; stwx`. */
void fn_80280F08(Unk8027FD64_Goal* g, Unk80270BA0_X* x)
{
    int zero = 0;
    Unk802726BC_Angles* p = &x->m734;

    if (p->m190 == 1) {
        Unk8027FD64_SetSlot168(p, 0, zero);
    }
    Unk8027FD64_SetSlot168(p, p->m190, zero);
    if (g->mE8.f1 && g->m74 == 2 && g->mA0 == 0) {
        Unk8027FD64_Ctx* ctx = (Unk8027FD64_Ctx*)x->m44C;
        int active = 0;

        if (fn_80257B40(ctx->m700->m3B4)->m458 == 9 || ((Unk8027FD64_Ctx*)x->m44C)->m6F8->m14->m1CC9 > 1) {
            active = 1;
        }
        if (active) {
            Unk80273498_Vec3 pos = ctx->m680->m60;
            float dx = pos.x - lbl_805DED28.x;
            float dz = pos.z - lbl_805DED28.z;
            float d2 = dx * dx + dz * dz;

            pos.y = 0.0f;
            if (!(d2 <= lbl_8061E6D0 * (lbl_8061E6D0 * 144.0f))) {
                int one = 1;

                if (p->m190 == 1) {
                    *(int*)((char*)p + 0x168) = one;
                }
                Unk8027FD64_SetSlot168(p, p->m190, one);
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

/* near-miss: 56 of 56 instructions, 6 differ in registers and order only.
 * Retail clears bits 4/5 in r0 and tests bit 14 on that cleared word (andis.
 * r9,r0,2); here the test reads the original word in r11 (combine folds the
 * cleared copy away), and the spill of f1 is placed earlier. Tried: statement
 * orders of the clears, m94 store and test, a local for the call result, a
 * reference for the flag word. */
void fn_80282B78(Unk8027FD64_Goal* g, Unk80270BA0_X* x, float f)
{
    float lim = 76176.0f;

    g->mE8.f4 = 0;
    g->mE8.f5 = 0;
    g->m94 = 5;
    if (!g->mE8.f14) {
        int hit = fn_8024D41C(x);

        if (hit) {
            g->m94 = 5;
            g->mE8.f4 = f < lim;
            g->mE8.f5 = 0;
        } else {
            Unk8027FD64_Ctx* ctx = (Unk8027FD64_Ctx*)x->m44C;

            g->m94 = 0;
            g->mE8.f4 = 1;
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
