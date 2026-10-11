/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic after userpickupballgoal (33 functions). Original file boundary unknown; placeholder.
 *
 * .text 0x8029EE50-0x802A3704 only: this region's data is interleaved with
 * other parts of the TU, so every data object it uses is declared extern by
 * its lbl_ name (no .rodata/.data split for this unit).
 */
#include "game/goals/tu_8029EE50.h"

void fn_8029EE50(Unk8029B70C_Goal* g)
{
    g->m88 = g->m88 - (float)lbl_8061B9C8 * 0.016666668f;
    if (!(g->m88 <= 0.0f)) {
        g->mD0.f8 = 0;
    }
    if (g->mD0.f9) {
        g->m74 = g->m74 - (float)lbl_8061B9C8 * 0.016666668f;
    } else if (g->mD0.f8) {
        g->m74 = -0.016666668f;
        g->mD0.f9 = 1;
        g->m88 = 0.33333334f;
    }
}

void fn_8029EF28(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80271DBC_Link* link)
{
    if (!lbl_8061F8FC) {
        fn_802771A0(1);
        if (lbl_806EF9D4) {
            lbl_8061F8FC = 2;
            fn_802D7B88(fn_801A2034(((Unk8027A84C*)g)->fn_8027A918(), 4), 1, 1.0f, 8);
        }
        fn_802771A0(0);
    }
}

float fn_802A28A4(Unk8029B70C_Goal* g, Unk80270BA0_X* x)
{
    float r = 0.0f;
    if (g->mD0.f0) {
        r = fn_80249188(x, g->m68);
    }
    return r;
}

void fn_802A2B7C(Unk8029B70C_Goal* g, Unk80270BA0_X* x, Unk80279BB8* out, int a, Unk80273498_Vec3* b, int c, int d, float f)
{
    ((Unk8027A84C*)g)->fn_8027AC90((Unk8037B128_Mtx*)out, d, c, b);
    out->mD8 = 0;
}

int fn_802A2BC0(Unk8029B70C_Goal* a, Unk8029B70C_Goal* b)
{
    if (b) {
        a->m6C = b->m6C;
        a->m60 = b->m60;
        a->mD0.f1 = b->mD0.f1;
        a->m68 = b->mD0.f0 ? b->m68 : -1.0f;
        a->mD0.f0 = b->mD0.f0;
        a->mD0.f8 = b->mD0.f8;
        return 1;
    }
    return 0;
}

float fn_802A2C40(Unk8029B70C_Goal* g, Unk80270BA0_X* x)
{
    float a = 1.5f;
    float b = 0.8f;
    if (x->m71C & 0x2000) {
        return b;
    }
    return a;
}

void fn_802A2DA4(Unk802A2DA4_Goal* g)
{
    g->m0 = 2;
    g->m4C = -1.0f;
    g->m48 = -1.0f;
}

Unk802A2DA4_Goal* fn_802A2DC0(Unk802A2DA4_Goal* g, float f)
{
    g->m4C = -1.0f;
    g->m48 = f;
    return g;
}

/* near-miss: 23 of 23 instructions, 11 differ: retail keeps `out` in r31
 * (stw r31, no stmw) and spills the unused float parameter first. Here the
 * single-block pseudo lands in r30. Tried: local float, += form, member cast,
 * &out->m0, an inline Add(float*, float) and Add(float&, float) (this one). */
inline void Unk802A2EB0_Add(float& dst, float v)
{
    dst = dst + v;
}

void fn_802A2EB0(Unk802A2DA4_Goal* g, Unk80270BA0_X* x, Unk80279BB8* out, int a, Unk80273498_Vec3* b, int c, int d, float f)
{
    Unk802A2EB0_Add(out->mD4, g->m48);
    ((Unk8027A84C*)g)->fn_8027AC90((Unk8037B128_Mtx*)out, d, c, b);
    out->mD8 = 1;
}

int fn_802A2F0C(Unk802A2DA4_Goal* a, Unk802A2DA4_Goal* b)
{
    return b != 0;
}

void fn_802A2F20(Unk802A2F20_Goal* g)
{
    g->m48 = 0;
}

int fn_802A3094(Unk802A2F20_Goal* a, Unk802A2F20_Goal* b)
{
    return 0;
}

void fn_802A309C(Unk802A309C_Goal* g)
{
    g->m48 = 0;
    g->m4C = 0;
    g->m50 = 0;
}

void fn_802A36B0(Unk802A309C_Goal* g)
{
    fn_802A309C(g);
    fn_801CE9D8(((Unk8027A84C*)g)->fn_8027A918()->m700->m3A4);
    ((Unk802A36B0_Ctx*)((Unk8027A84C*)g)->fn_8027A918())->m720->mC8 = 1;
}
