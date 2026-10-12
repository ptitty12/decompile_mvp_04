/*
 * Game code, .text 0x80241C24-0x80246D04 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80241C24.h"

extern const float lbl_805D9128;

void fn_802423A8(int a, Unk80241C24_B* b)
{
    fn_802423EC(a, &b->m4);
    fn_802423EC(a, &b->m43C->m4);
}

void fn_802423EC(int a, int* s)
{
    int i = 0;
    int n = *s;
    for (; i < n; i++)
        fn_8030AF9C(s, i);
}

void fn_8024243C(int a, Unk80241C24_B* b, int c, int d, int e)
{
    fn_80242498(a, &b->m4, c, d, e);
    fn_80242498(a, &b->m43C->m4, c, d, e);
}

void fn_802427BC(int a, Unk80241C24_B* b, int c, int d, int e, int f)
{
    fn_8024282C(a, &b->m4, c, d, e, 0, f);
    fn_8024282C(a, &b->m43C->m4, c, d, e, 1, f);
}

void fn_80242D24(Unk80241C24_A* a, Unk80241C24_B* b, int c, int d, int e)
{
    fn_80242D9C(a, &b->m4, c, d, e);
    if (a->m398 < 0)
        fn_8030AF34(&b->m438->m4, 0);
    fn_80242D9C(a, &b->m43C->m4, c, d, e);
}

void fn_80242D9C(Unk80241C24_A* a, int* b, int c, int d, int e)
{
    if (a->m398 >= 0) {
        fn_8030AF34(b, 0x29);
        fn_8030AF34(b, 0x2D);
    } else {
        fn_8030AF34(b, 0x2B);
        fn_8030AF34(b, 0x2C);
    }
    fn_8030AF34(b, 0x19);
    if (c == 0)
        fn_8030AF34(b, 0x2A);
}

void fn_80242E28(Unk80270BA0_X* x, float f)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    float old = v->m8EC;
    v->m8EC = f;
    if (old != v->m8EC)
        fn_802491D8(x);
}

void fn_80242E6C(Unk80270BA0_X* x, int a)
{
    Unk8014D8AC_Ctx* c = (Unk8014D8AC_Ctx*)((Unk8024B99C_V*)x)->m44C;
    fn_802593EC(c->m700->m3B4, x, a);
}

int fn_80243944()
{
    return 0;
}

int fn_8024394C()
{
    return 0;
}

void fn_80244858(Unk80270BA0_X* x, float f)
{
    float t = AngleDiff(f, 0.0f);
    fn_80382BC0(x->m618, t);
}

extern "C" Goal* fn_802448F4(Unk8016C788_Obj* o, int n)
{
    Goal* first = lbl_8061D37C;
    Goal* last = first;
    while (n-- != 0) {
        last = lbl_8061D37C;
        Goal* nx = last->m0;
        last->mC = 0;
        last->m14 = 0;
        lbl_8061D37C = nx;
    }
    if (lbl_8061D37C != 0)
        lbl_8061D37C->m4 = 0;
    first->m4 = 0;
    last->m0 = 0;
    for (Goal* p = first; p != 0; p = p->m0)
        p->mC = (Player*)o;
    return first;
}

void fn_8024497C(Player* player, Goal* g)
{
    if (g != 0) {
        Goal* top = fn_8027D2FC(g, 0x50);
        if (top != 0) {
            Goal* tail = fn_8027D31C(top);
            fn_80244A60(player, tail);
            tail->m0 = lbl_8061D37C;
            lbl_8061D37C->m4 = tail;
            lbl_8061D37C = top;
            fn_80244A60(player, top);
        }
    }
}

void fn_802449F4(Unk8024EF40_P* p)
{
    int off = 0;
    int i = 0x4F;
    do {
        Player* o = *(Player**)((char*)(off + (int)lbl_8061D378) + 0xC);
        off += 0x33C;
        if (o != 0 && p->m264 != 0)
            fn_80244A64(o, 0, 0);
    } while (--i != 0);
}

void fn_80244A60(Unk8027C728_Player* player, Unk8027C728_Goal* g)
{
}

Unk8027C728_Goal* fn_80244C84(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = ((Unk8024B99C_V*)x)->m934;
    while (g != 0 && g->m14 == 1)
        g = g->m0;
    return g;
}

/* near-miss: 4 slots (retail's lwz r8,8(r9) / extsb order and stw r0,0x20(r1) after lfs f1; ours r11 and stw before lfs) */
Vec3 fn_80244CB8(Unk80270BA0_X* x, float f)
{
    Unk8027D150_Pair p;
    int d = lbl_806EF9C7;
    Vec3 v = lbl_806055DC;
    p.m0 = d;
    fn_80244D4C(x, 1, &p, &v, f);
    return v;
}

/* near-miss: only the spill slot of f1 (retail stfs f1,8(r1) first in the function; ours after the field load) */
void fn_80244D4C(Unk80270BA0_X* x, int d, Unk8027D150_Pair* c, Vec3* b, float f)
{
    if (((Unk8024B99C_V*)x)->m934 != 0) {
        Unk80279BB8 q((Player*)x);
        Goal* top = fn_8027D31C(((Unk8024B99C_V*)x)->m934);
        fn_8027D150(top, 2, &q, f, b, c, d);
    }
}

/* near-miss: only the spill slot of f1 (retail stores it between lis and ori; ours just before f2) */
int fn_80244DC4(Unk80270BA0_X* x, int a, int b, float f1, float f2)
{
    int id = x->m618->m838;
    if (id != 0x53CFCF84 && id != 0x294A8535)
        return 0;
    return fn_8037EDFC(x->m618, lbl_806EF9C4, 0, a, b, f1, f2);
}

int fn_80244E3C(Unk80270BA0_X* x, Unk80273498_Vec3* out)
{
    if (x->m618->m838 == (int)0x94C34DBD) {
        *out = x->m60;
        return 1;
    }
    return 0;
}

void fn_80244E80(Unk80270BA0_X* x, int a, int i)
{
    int* b = (int*)((char*)x + 0x618);
    int o = i * 4;
    *(int*)((char*)b + o) = a;
    fn_80378A34((char*)x + 0x5E4, (void*)a);
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

void fn_80245828(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
    fn_80245868(a, b, c, d, e, f, g, h, i, j);
}

int fn_80245858(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return i == 0;
}
