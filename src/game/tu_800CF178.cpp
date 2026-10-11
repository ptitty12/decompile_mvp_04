/*
 * Game code, .text 0x800CF178-0x800D1758 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

void Unk800C7A4C_Group::fn_800CF178(int v)
{
    fn_800C7E90(this, v);
    for (Unk800C7B40_Widget* c = m40; c != 0; c = c->m8)
        c->fn_vslot16(v);
}

void Unk800C7A4C_Group::fn_800CF1DC(int v)
{
    fn_800C7EBC(this, v);
    for (Unk800C7B40_Widget* c = m40; c != 0; c = c->m8)
        c->fn_vslot17(v);
}

void Unk800C7A4C_Group::fn_800CF240(int v)
{
    fn_800C7E64(this, v);
    for (Unk800C7B40_Widget* c = m40; c != 0; c = c->m8)
        c->fn_vslot15(v);
}

/* ---- pass-2 additions ---- */

extern "C" void fn_800CF2A4(Unk800C7A4C_Group* g, int v)
{
    g->b5 = v;
    for (Unk800C7B40_Widget* c = g->m40; c != 0; c = c->m8)
        c->fn_vslot24(v);
}

inline void SetM38(Unk800C7B40_Data* d, float v)
{
    d->m38 = v;
}

extern "C" void fn_800CF30C(Unk800C7A4C_Group* g, float f)
{
    SetM38(g, f);
    for (Unk800C7B40_Widget* c = g->m40; c != 0; c = c->m8)
        c->fn_vslot20(f);
}

inline void Unused(float v)
{
}

extern "C" void fn_800CF378(Unk800C7A4C_Group* g, float f)
{
    Unused(f);
    for (Unk800C7B40_Widget* c = g->m40; c != 0; c = c->m8)
        c->fn_vslot21(f);
}

extern "C" void fn_800CF3DC(Unk800C7A4C_Group* g, int v)
{
    int d = v - g->m26;
    g->m26 = v;
    for (Unk800C7B40_Widget* c = g->m40; c != 0; c = c->m8)
        c->fn_vslot9(c->m26 + d);
}

extern "C" void fn_800CF444(Unk800C7A4C_Group* g, int v)
{
    int d = v - g->m28;
    g->m28 = v;
    for (Unk800C7B40_Widget* c = g->m40; c != 0; c = c->m8)
        c->fn_vslot10(c->m28 + d);
}

extern "C" Unk800C7B40_Widget* fn_800CF4AC(Unk800C7A4C_Group* g, const char* name)
{
    int n = 0;
    char buf[16];
    fn_80378D40(name, '/', &n);
    fn_8040B830(buf, name, n);
    buf[n] = 0;
    int last = name[n] == 0;
    name += n + 1;
    for (Unk800C7B40_Widget* c = g->m40; c != 0; c = c->m8) {
        if (fn_8040B574(c->mC, buf) == 0) {
            if (last)
                return c;
            int t = c->m1C;
            if (t == 3 || t == 8 || t == 0 || t == 11) {
                Unk800C7B40_Widget* r = c->fn_vslot28(name);
                if (r)
                    return r;
            }
        }
    }
    return 0;
}

/* near-miss: retail keeps the null check (mr. / li 0 / beq / mr) on the slot-28 result; every ternary form folds it away */
extern "C" Unk800C7B40_Widget* fn_800CF5AC(Unk800C7B40_Widget* w, const char* a, int b)
{
    Unk800C7B40_Widget* r = w->fn_vslot28(a);
    return r ? r : 0;
}

/* near-miss: same null check as fn_800CF5AC (slot 30) */
extern "C" Unk800C7B40_Widget* fn_800CF738(Unk800C7B40_Widget* w, const char* a, int b)
{
    Unk800C7B40_Widget* r = w->fn_vslot30(a, b);
    return r ? r : 0;
}

extern "C" Unk800C7B40_Widget* fn_800CF77C(Unk800C7B40_Widget* w, const char* a, int b, int c)
{
    return w->fn_vslot31(a, b, c);
}

extern "C" void fn_800CF7B0(Unk800C7B40_Widget* w)
{
    for (Unk800C7B40_Widget* c = w->m4; c != 0 && (unsigned)c->m20 > (unsigned)w->m20; c = c->m4)
        fn_800C7C04(c);
}

extern "C" void fn_800CF804(Unk800C7B40_Widget* w, int v)
{
    if (w->b7) {
        int cur = fn_800C80D4();
        for (Unk800C7B40_Widget* c = w->m4; c != 0 && (unsigned)c->m20 > (unsigned)w->m20; c = c->m4) {
            if (c->b3 != cur)
                c->fn_vslot14(cur);
        }
    }
    fn_800C80DC(w, v);
}

extern "C" Unk800D1614_Raw* fn_800CF8A0(Unk800D1614_Raw* self, int p1, int p2, int p3, int p4, int p5, int p6, int p7,
                                        int s1, int s2, int s3, int s4)
{
    fn_800D0D9C(self, p1, 6, p2, p3, p4, p5, p6, p7, s1, s2, s3, s4);
    self->m3C = lbl_80657A78;
    return self;
}

extern "C" void fn_800CFAC4(Unk800D1614_Obj* o, int v)
{
    o->fn_800D1714(v);
}

struct Unk800CFAE4_Range {
    int m0, m4, m8;
    float mC;
    float m10;
    int m14;
};

extern "C" int fn_800CFAE4(Unk800CFAE4_Range* r, float f)
{
    if ((!(f < r->mC) && f <= r->m10) || (!(f < r->m10) && r->m14 == 0))
        return 1;
    return 0;
}

struct Unk800CFB88_Node {
    char pad0[0x10];
    float m10;
    int m14;
    Unk800CFB88_Node* m18;
};

struct Unk800CFB38_Timer {
    int m0;
    char pad4[0x14];
    float m18;
    float m1C;
    Unk800CFB88_Node* m20;
};

extern int lbl_8061A328;

extern "C" void fn_800CFB38(Unk800CFB38_Timer* t)
{
    t->m0 = 1;
    t->m18 = lbl_8061A328 * 0.016666668f;
}

typedef Unk800CFB38_Timer Unk800CFB88_List;

extern "C" void fn_800CFB88(Unk800CFB88_List* l, Unk800CFB88_Node* n)
{
    l->m1C = !(n->m10 <= l->m1C) ? n->m10 : l->m1C;
    n->m18 = l->m20;
    l->m20 = n;
}

struct Unk800CFBB8_Raw : Unk800CFB38_Timer {
    char pad24[0xC];
    const void* m30;
};
extern const char lbl_8065ABF0[];

extern "C" void fn_800CFBB8(Unk800CFBB8_Raw* o, int c)
{
    o->m30 = lbl_8065ABF0;
    while (o->m20 != 0) {
        Unk800CFB88_Node* n = o->m20;
        o->m20 = n->m18;
        fn_80377408(n);
    }
    if (c & 1)
        fn_80377408(o);
}

extern "C" void fn_800CFE84(Unk800CFB88_List* l)
{
    float best = l->m18 = 0.0f;
    Unk800CFB88_Node* sel = l->m20;
    for (Unk800CFB88_Node* n = l->m20; n != 0; n = n->m18) {
        if (!(n->m10 <= best)) {
            best = n->m10;
            sel = n;
        }
        n->m14 = 1;
    }
    sel->m14 = 0;
}

extern const char lbl_8065A370[];

void Unk800CFEEC_Raw::fn_800CFEEC(int flag)
{
    m24 = lbl_8065A370;
    m0 = 0;
    m4 = 0;
    mC = 0;
    b0 = flag;
    b1 = 0;
    b2 = 1;
    b3 = 0;
    m20 = 0;
    for (int i = 0; i < 4; i++)
        m10[i] = 0;
}

extern "C" void fn_800CFF48(Unk800CFEEC_Data* c, int i)
{
    int last = c->m4 - 1;
    if (i > last)
        c->m0 = last;
    else if (i < 0)
        c->m0 = 0;
    else
        c->m0 = i;
}

extern "C" int fn_800CFF7C(Unk800CFEEC_Data* c)
{
    int n = c->m4;
    int i = c->m0 + 1;
    c->m0 = i;
    if (i >= n) {
        int v = n - 1;
        if (c->b0)
            v = 0;
        c->m0 = v;
    }
    return 1;
}

extern "C" int fn_800CFFB4(Unk800CFEEC_Data* c)
{
    int i = c->m0 - 1;
    c->m0 = i;
    if (i < 0) {
        if (c->b0)
            i = c->m4 - 1;
        else
            i = 0;
        c->m0 = i;
    }
    return 1;
}

extern "C" void fn_800CFFF0(Unk800CFFF0_Obj* o)
{
    while (o->fn_vslot13() > 0)
        o->fn_vslot3(o->fn_vslot13() - 1);
}

extern "C" void fn_800D0210(Unk800CFEEC_Sel* s, Unk800C7B40_Widget* p, int q)
{
    int id = 0;
    if (p != 0)
        id = fn_800E1990(fn_800B5520(p));
    if (id != s->mC)
        fn_800D0074(s, id, q);
    s->fn_vslot8(p);
}

extern void* lbl_8061E978;

extern "C" void fn_800D03B4(Unk800D03B4_Obj* o)
{
    void* t = lbl_8061E978;
    o->m70 = (int)fn_802B0850(t, "rect", 0);
    o->m74 = fn_802B0ACC(t, "rect");
}

struct Unk800D0C84_Row {
    int a, b, c;
};
extern Unk800D0C84_Row lbl_805BC24C[];

/* near-miss: 2 slots differ (retail loads li r7,255 before addi r3,r1,8 for the first call) */
extern "C" void fn_800D0C84(Unk800D0C84_Obj* o, int idx)
{
    const Unk800D0C84_Row& r = lbl_805BC24C[idx];
    Unk800D244C_Vec4 a = fn_8014DBA0(r.a, r.b, r.c, 255);
    Unk800D244C_Vec4 b = fn_8014DBA0(255, 255, 255, 255);
    o->m44 = a;
    o->m54 = b;
}

Unk800D0D3C_Obj::Unk800D0D3C_Obj()
{
    m0 = 0.555f;
    m4 = 0.18f;
    m8 = 0;
}

extern "C" void fn_800D0D64(void* p, int c)
{
    if (c & 1)
        fn_80377408(p);
}

extern "C" void fn_800D0D8C()
{
}

extern "C" void fn_800D0D90()
{
}

extern "C" int fn_800D0D94()
{
    return 0;
}

extern "C" Unk800D1614_Raw* fn_800D0D9C(Unk800D1614_Raw* self, int a, int b, int c, int d, int e, int f, int g, int h, int i,
                                        int j, int k, int l)
{
    fn_800C7B40(self, a, b, c, d, e, f, g, h, i, k, l, 0, 1.0f);
    self->m3C = lbl_80657C18;
    self->m40 = j;
    self->m44 = 0;
    self->m48 = 0;
    self->m4C = 0;
    self->m50 = 0;
    self->m54 = 0;
    return self;
}

extern "C" void fn_800D0E24(Unk800D1614_Raw* o, int c)
{
    o->m3C = lbl_80657C18;
    if (o->m48 != 0)
        delete o->m48;
    if (o->m4C != 0)
        delete o->m4C;
    if (o->m50 != 0)
        delete o->m50;
    if (o->m54 != 0)
        delete o->m54;
    o->m3C = lbl_8065CCE8;
    if (c & 1)
        fn_80377408(o);
}

extern "C" int fn_800D0F18(Unk800D0F18_Obj* o)
{
    if (!o->b1)
        return 0;
    o->m48->fn_vslot15(1);
    o->m44 = o->m44 - 1;
    if (o->m44 < 0)
        o->m44 = 0;
    return 1;
}

extern "C" int fn_800D0F94(Unk800D0F18_Obj* o)
{
    if (o->b1 == 0)
        return 0;
    o->m48->fn_vslot15(0);
    return 1;
}

extern "C" int fn_800D0FE8(Unk800D0F18_Obj* o)
{
    if (!o->b1)
        return 0;
    o->m4C->fn_vslot15(1);
    o->m44 = o->m44 + 1;
    if (o->m44 >= o->m40)
        o->m44 = o->m40 - 1;
    return 1;
}

extern "C" int fn_800D1068(Unk800D0F18_Obj* o)
{
    if (o->b1 == 0)
        return 0;
    o->m4C->fn_vslot15(0);
    return 1;
}

extern "C" void fn_800D10BC(Unk800D1614_Obj* o)
{
    if (o->b0) {
        if (o->m50 != 0)
            o->m50->fn_vslot2();
        if (o->m54 != 0)
            o->m54->fn_vslot2();
        if (o->m48 != 0)
            o->m48->fn_vslot2();
        if (o->m4C != 0)
            o->m4C->fn_vslot2();
    }
}

extern "C" void fn_800D1180(Unk800D1614_Obj* o)
{
    fn_800C7EE8(o);
    o->fn_vslot44();
    if (o->m48 != 0)
        o->m48->fn_vslot4();
    if (o->m4C != 0)
        o->m4C->fn_vslot4();
    if (o->m50 != 0)
        o->m50->fn_vslot4();
    if (o->m54 != 0)
        o->m54->fn_vslot4();
}

extern "C" void fn_800D1254(Unk800C7B40_Data* w, int v)
{
    fn_800C7E38(w, v);
}

extern "C" void fn_800D1274(Unk800D1614_Obj* o, int a, int b, int c, int d)
{
    fn_800C8010(o, a, b, c, d);
    if (o->m48 != 0)
        o->m48->fn_vslot5(a, b, c, d);
    if (o->m4C != 0)
        o->m4C->fn_vslot5(a, b, c, d);
    if (o->m50 != 0)
        o->m50->fn_vslot5(a, b, c, d);
    if (o->m54 != 0)
        o->m54->fn_vslot5(a, b, c, d);
}

extern "C" void fn_800D1380(Unk800D1614_Obj* o, int v)
{
    int d = v - o->m26;
    o->m26 = v;
    if (o->m48 != 0)
        o->m48->fn_vslot9(o->m48->m26 + d);
    if (o->m4C != 0)
        o->m4C->fn_vslot9(o->m4C->m26 + d);
    if (o->m50 != 0)
        o->m50->fn_vslot9(o->m50->m26 + d);
    if (o->m54 != 0)
        o->m54->fn_vslot9(o->m54->m26 + d);
}

extern "C" void fn_800D1464(Unk800D1614_Obj* o, int v)
{
    int d = v - o->m28;
    o->m28 = v;
    if (o->m48 != 0)
        o->m48->fn_vslot10(o->m48->m28 + d);
    if (o->m4C != 0)
        o->m4C->fn_vslot10(o->m4C->m28 + d);
    if (o->m50 != 0)
        o->m50->fn_vslot10(o->m50->m28 + d);
    if (o->m54 != 0)
        o->m54->fn_vslot10(o->m54->m28 + d);
}

extern "C" void fn_800D1548(Unk800D1614_Obj* o, int v)
{
    o->m2E = v;
    if (o->m48 != 0)
        o->m48->fn_vslot18(v);
    if (o->m4C != 0)
        o->m4C->fn_vslot18(v);
    if (o->m50 != 0)
        o->m50->fn_vslot18(v);
    if (o->m54 != 0)
        o->m54->fn_vslot18(v);
}

void Unk800D1614_Obj::fn_800D1614(Unk800C7B40_Widget* c)
{
    m48 = c;
    c->fn_vslot18(m2E);
}

void Unk800D1614_Obj::fn_800D1654(Unk800C7B40_Widget* c)
{
    m4C = c;
    c->fn_vslot18(m2E);
}

void Unk800D1614_Obj::fn_800D1694(Unk800C7B40_Widget* c)
{
    m50 = c;
    c->fn_vslot18(m2E);
}

void Unk800D1614_Obj::fn_800D16D4(Unk800C7B40_Widget* c)
{
    m54 = c;
    c->fn_vslot18(m2E);
}

void Unk800D1614_Obj::fn_800D1714(int v)
{
    m40 = v;
    fn_vslot8(v > 1);
}
