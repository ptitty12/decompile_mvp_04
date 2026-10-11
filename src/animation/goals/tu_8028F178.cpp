/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x8028F178-0x802914C8, .rodata 0x805DD848-0x805DD938.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/chooser.h"
#include "game/goals/tu_8028F178.h"

/* near-miss: 32 of 32 instructions, 3 differ in order only (retail spills f1 right after the first
 * lwz, mine places the stfs after `mr r11,r9`). The temps for the three root stores give retail's
 * value-before-pointer loads. Tried: owner pointer local, copy of the float parameter, local copy
 * of `a`, all three loads before the stores. */
void fn_8028F178(Unk8028F178_Goal* g, Unk80270BA0_X* x, Unk8028F178_Req* r, int a, int b, int c, int d, float f)
{
    if (g->m44->m14 != 0) {
        r->mD8 = 1;
        return;
    }
    if (a == 1) {
        a = g->m0;
    }
    int t1 = g->m38;
    g->m4->m38 = t1;
    int t2 = g->m34;
    g->m4->m34 = t2;
    int t3 = g->m40;
    g->m4->m40 = t3;
    fn_802977FC(g->m4, x, r, a, b, c, d, f);
}

void fn_8028F1F8(Unk8028F178_Goal* g, Unk8028F178_Goal* o)
{
    fn_802987C8(g->m4, o->m4);
}

/* The shared local `m1` gives retail's single -1 register for the byte store and the two ints. The
 * statement order was found by a hill-climb on the order of independent stores (see PATTERNS). */
void fn_8028F34C(Unk8028F178_Goal* g)
{
    int m1 = -1;
    g->m0 = 2;
    g->m4C = 0;
    g->m50 = m1;
    g->m5C = m1;
    g->m158 = 0.0f;
    g->m15C = 0.0f;
    g->m88 = 0.0f;
    g->m70 = -1.0f;
    g->m84 = -1.0f;
    g->m78 = -1.0f;
    g->m54 = 0;
    g->m18C.f12 = 0;
    g->m18C.f13 = 0;
    g->m18C.f14 = 0;
    g->m18C.f15 = 0;
    g->m18C.f16 = 0;
    g->m18C.f17 = 0;
    g->m18C.f18 = 0;
    g->m18C.top = m1;
    g->m58 = 0;
    g->m7C = -1.0f;
    g->m184 = 0.0f;
    g->m188 = 1.0f;
    g->m160 = 0;
    g->m18C.f8 = 0;
    g->m18C.f9 = 0;
    g->m164 = lbl_806055AC;
    g->m170 = lbl_806055AC;
    g->m180 = 2;
    g->m98 = 0;
    g->m18C.f10 = 0;
    g->m18C.f11 = 0;
    g->m18C.f19 = 0;
    g->m17C = 5;
}

void fn_8028F440(Unk8028F178_Goal* g)
{
    g->mC = 0;
    g->m4C = 0;
    g->m50 = 0;
    g->m54 = 0;
    g->m58 = 0;
}

/* Inline setter taking the vector by value: reading the temp copy back word by word is retail's shape. */
inline void SetVec10(Unk8028F178_Goal* g, Unk80273498_Vec3 t)
{
    g->m10 = t;
}

Unk8028F178_Goal* fn_8028F45C(Unk8028F178_Goal* g, Unk80273498_Vec3 v)
{
    v.y = 0.0f;
    SetVec10(g, v);
    g->m28 = 1;
    return g;
}

Unk8028F178_Goal* fn_8028F4B8(Unk8028F178_Goal* g, unsigned int idx)
{
    g->m5C = idx;
    Unk80273498_Vec3 v = ((Unk8027A84C*)g)->fn_8027AF54(idx);
    fn_8028F45C(g, v);
    return g;
}

Unk8028F178_Goal* fn_8028F528(Unk8028F178_Goal* g, Unk80273498_Vec3* v)
{
    v->y = 0.0f;
    Unk80273498_Vec3 t = *v;
    ((Unk8027A84C*)g)->fn_8027A898(&t);
    return g;
}

void fn_8028F588(Unk8028F178_Goal* g, float f)
{
    if (!(f <= 0.0f)) {
        g->m74 = f;
        g->m18C.f12 = 1;
    } else {
        g->m18C.f12 = 0;
    }
}

Unk8028F178_Goal* fn_8028F5CC(Unk8028F178_Goal* g, float f)
{
    g->m80 = f;
    g->m18C.f13 = 1;
    return g;
}

Unk8028F178_Goal* fn_8028F5F4(Unk8028F178_Goal* g, float f)
{
    g->m84 = f;
    return g;
}

int fn_8028F848(Unk8028F178_Goal* g)
{
    Unk80270BA0_X* x = ((Unk8027A84C*)g)->fn_8027A90C();
    if (x && x->m618 && x->m618->m838 == 0x998C3D11) {
        return 1;
    }
    return 0;
}

int fn_80290D3C(Unk8028F178_Goal* g, Unk80270BA0_X* x);

int fn_80290D1C(Unk8028F178_Goal* g, Unk80270BA0_X* x)
{
    return fn_80290D3C(g, x);
}
