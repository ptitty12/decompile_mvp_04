/*
 * Game code, .text 0x80241C24-0x80246D04 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024B99C.h"
#include "game/chooser.h"

extern const float lbl_805D9128;

Unk8027C728_Goal* fn_80244C84(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = ((Unk8024B99C_V*)x)->m934;
    while (g != 0 && g->m14 == 1)
        g = g->m0;
    return g;
}

int fn_80244E3C(Unk80270BA0_X* x, Unk80273498_Vec3* out)
{
    if (x->m618->m838 == (int)0x94C34DBD) {
        *out = x->m60;
        return 1;
    }
    return 0;
}

void fn_80245694(Unk80270BA0_X* x, int a, float f, int b, int c, int d, int e, int g, int h)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    v->m5F4 = f;
    v->m5F8 = a;
    v->m5FC = b;
    v->m600 = c;
    v->m604 = d;
    v->m608 = e;
    v->m60C = g;
    v->m610 = h;
}

/* near-miss: only the order of the lbl_805D9128 load vs the reload of f differs (f11/f12 swapped) */
void fn_802456C8(Unk80270BA0_X* x, int a, int b, float f)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (a == 1) {
        v->m90C = (float)x->m44C->m4C * lbl_805D9128 + f;
        v->m910 = b;
        v->m914 = a;
    } else
        v->m914 = 0;
}
