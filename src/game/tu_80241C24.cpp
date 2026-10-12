/*
 * Game code, .text 0x80241C24-0x80246D04 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80241C24.h"
#include "game/tu_8026C414.h"
#include "game/goals/tu_8027A84C.h"

int fn_8027CFA8(Goal* a, Goal* b, Player* p, Unk80279BB8* r);

/* Frames to seconds through an inline: the constant-pool loads the inliner copies are not
 * unchanging, so sched1 keeps them below preceding stores (retail's order). */
template <class T> inline float Unk80241C24_Secs(T n)
{
    return (float)n * 0.016666668f;
}

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

struct Unk802C3B60;
int fn_802C41A0(Unk802C3B60* p, int a, int b, int c);
int fn_8023E604(struct Unk8023DB8C_P* p, int k);
extern char* lbl_8061E978;
extern int lbl_8061D384;
extern int lbl_8061D388;
struct Unk80242B4C_P {
    char pad0[0x6BC];
    int m6BC;
    char pad6C0[0x70C - 0x6C0];
    unsigned char m70C;
};
struct Unk80242B4C_O {
    char pad0[0x2C];
    int m2C;
    char pad30[0x64 - 0x30];
    int m64;
    char pad68[4];
    int m6C;
    int m70;
    char pad74[0x80 - 0x74];
    int m80;
};
inline int Unk80242B4C_Has(char* l)
{
    if (*(int*)(l + 0x60) == 0)
        return 0;
    return 1;
}
void fn_80242B4C(Unk80242B4C_P* p, Unk80241C24_B* b, int k, Unk80242B4C_O* o)
{
    if (k != 1 && k != 16) {
        int* l2 = &b->m438->m4;
        int* list = &b->m4;
        int on = 1;
        if (lbl_8061D384 != 0)
            on = lbl_8061D388;
        if (on != 0) {
            fn_8030AF9C(l2, 0);
            int f = 0;
            if (fn_8023E604((Unk8023DB8C_P*)p, k) != 0 || k == 10 || k == 11 || k == 12)
                f = 1;
            int t = fn_802C41A0((Unk802C3B60*)(lbl_8061E978 + 0x11F78), o->m64, k, o->m80);
            if (f != 0 && t <= 0x7A2)
                f = 0;
            fn_8030AF34(list, 0x17);
            if (f != 0) {
                fn_8030AF34(list, 0x28);
            } else if (k == 14 && p->m70C == 0) {
                fn_8030AF34(list, 0x29);
                fn_8030AF34(list, 0x2D);
            } else {
                int id = 0x15;
                if (t <= 0x795) {
                    if (Unk80242B4C_Has((char*)list))
                        id = 0x16;
                }
                fn_8030AF34(list, id);
            }
        } else {
            fn_8030AF34(l2, 0);
        }
        if (p->m6BC == 0) {
            if (o->m2C == 0x12)
                fn_8030AF34(list, 3);
            if (o->m2C == 0x41)
                fn_8030AF34(list, 4);
            if (o->m2C == 0x96) {
                fn_8030AF34(list, 5);
                fn_8030AF34(list, 6);
            }
        }
    }
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

struct Unk80243400_B {
    char pad0[0x60];
    Unk8026C414_V3 m60;
    char pad6C[0x98 - 0x6C];
};
class Unk80243400_V : public Unk80243400_B {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int a);
};
class Unk80243400_X : public Unk80243400_V {
public:
    char pad9C[0x264 - 0x9C];
    int m264;
    char pad268[0x44C - 0x268];
    Unk8022FE34_Ctx* m44C;
    char pad450[8];
    int m458;
    int m45C;
};
extern int lbl_8061D2B0;
void fn_8026CB30(Unk8026C414_M* self, int i);
void fn_80243400(Unk80243400_X* x, int i)
{
    fn_8026CB30((Unk8026C414_M*)x, i);
    if (x->m44C->m6F4 != 1) {
        x->v9(1);
        x->m45C = 13;
    }
    if (x->m264 == 0 && (x->m458 == 13 || x->m458 == 17 || x->m458 == 16 || lbl_8061D2B0 != 0)) {
        Unk8026C414_E* e = (Unk8026C414_E*)((char*)x + (i * 32 + 0xC4));
        e->m10 = 0.0f;
        e->f0 = 0;
        e->pos = x->m60;
        e->m14 = x->m458;
        e->f4 = x->v4();
    }
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

static inline char* GoalData2(Goal* g)
{
    char* r = 0;
    if (g->m10 == 2)
        r = g->m18;
    return r;
}
extern "C" void fn_80244A64(Player* player, Goal* g, int flag)
{
    if (g != 0 && flag == 0 && (*(unsigned*)((char*)player + 0x71C) & 0x1000)) {
        fn_8024497C(player, g);
        return;
    }
    Goal* cur = ((Unk8024B99C_V*)player)->m934;
    Goal* la = 0;
    Goal* lb = 0;
    int found = 0;
    Goal* a = cur;
    int moved = 0;
    Goal* b = g;
    Goal* c;
    if (b != 0) {
        b = fn_8027D2FC(b, -1);
        c = b;
        if (cur != 0) {
            goto test;
        loop:
            a = a->m0;
            c = c->m0;
        test:
            if (a != 0 && c != 0) {
                if (fn_8027CFA8(a, c, player, 0) != 0) {
                    found = 1;
                    moved = 1;
                    lb = a;
                    la = c;
                    goto loop;
                }
                found = 0;
            }
        }
    }
    if (found != 0) {
        fn_8024497C(player, b);
        ((Unk8024B99C_V*)player)->m934 = cur;
        return;
    }
    if (moved != 0) {
        Goal* t1 = la->m0;
        Goal* t2 = lb->m0;
        lb->m0 = t1;
        if (t1 != 0)
            t1->m4 = lb;
        la->m0 = t2;
        if (t2 != 0)
            t2->m4 = la;
        Goal* t = cur;
        cur = b;
        b = t;
    }
    ((Unk8024B99C_V*)player)->m934 = b;
    fn_8024497C(player, cur);
}

void fn_80244BA4(Unk80270BA0_X* x, Goal* g, int flag)
{
    if (g != 0) {
        if (flag == 0 && (x->m71C & 0x1000)) {
            fn_8024497C((Player*)x, g);
            return;
        }
        Goal* top = ((Unk8024B99C_V*)x)->m934;
        if (top != 0) {
            char* d = GoalData2(top);
            if (d != 0) {
                fn_80244A64((Player*)x, g, flag);
                return;
            }
            Goal* tail = fn_8027D31C(top);
            if (GoalData2(tail) != 0) {
                Goal* t = tail;
                tail = tail->m4;
                tail->m0 = (Goal*)d;
                t->m4 = (Goal*)d;
                fn_8024497C((Player*)x, t);
            }
            tail->m0 = g;
            g->m4 = tail;
        } else
            fn_80244A64((Player*)x, g, flag);
    }
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

void fn_802456C8(Unk80270BA0_X* x, int a, int b, float f)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (a == 1) {
        v->m90C = Unk80241C24_Secs(x->m44C->m4C) + f;
        v->m910 = b;
        v->m914 = a;
    } else
        v->m914 = 0;
}

int fn_80245730(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (v->m914 != 0) {
        Goal* g = v->m934;
        v->m914 = 0;
        Unk8027A84C* d = 0;
        if (g != 0) {
            d = ((Unk8027A84C_Owner*)g)->fn_8027C67C();
            g = v->m934;
            if (g->m14 == 1)
                d = ((Unk8027A84C_Owner*)g->m0)->fn_8027C67C();
        }
        int t = v->m910;
        if (t != 0) {
            Unk8027A84C_Owner* o = d->m44;
            char* p = 0;
            if (o->m10 == 6)
                p = o->m18;
            if (p != 0 && (int)d != t)
                return 0;
        }
        float s = (float)(unsigned)v->m44C->m4C * 0.016666668f;
        return s <= v->m90C;
    }
    return 0;
}

void fn_80245828(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
    fn_80245868(a, b, c, d, e, f, g, h, i, j);
}

int fn_80245858(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return i == 0;
}
