/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic between cShortestPathChooser and catchgoal.cpp.
 * Original file name unknown; placeholder. 18 functions.
 *
 * .text 0x8027FD64-0x80283934, .rodata 0x805DD24C-0x805DD3F4, .data 0x8061E6D0-0x8061E6D4.
 */
#include "game/chooser.h"
#include "game/goals/tu_8027FD64.h"

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

void fn_802803A4(Unk8027FD64_Goal* g, Unk80270BA0_X* x, int c, int d)
{
    fn_80280418(g, x, d);
    if (fn_802834E8(g, x, c)) {
        fn_80280418(g, x, d);
        fn_802834E8(g, x, c);
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
