/*
 * Game code, .text 0x800C7A4C-0x800CB3A8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

extern "C" void fn_800D0D64(void* p, int c);
extern "C" void fn_800D0D90(void* p);
extern "C" void fn_800D0D8C(void* p);
extern "C" void fn_80377488(void* p); /* __builtin_vec_delete */

void Unk800C7A4C_Group::fn_800C7A4C(int v)
{
    m2A = v;
    if (m40 != 0)
        m40->fn_vslot12(v);
    if (m44 != 0)
        m44->fn_vslot12(v);
    if (m48 != 0)
        m48->fn_vslot12(v);
    if (m4C != 0)
        m4C->fn_vslot12(v);
    if (m50 != 0)
        m50->fn_vslot12(v);
}

extern "C" void* fn_800C7B40(Unk800D1614_Raw* d, int name, int idv, int prio, int fb0, int fb1, int s26, int s28, int s2A, int s2C,
                             int fb8, int fb9, int s2E, float scale)
{
    d->b0 = fb0;
    d->b1 = fb1;
    d->b2 = 0;
    d->b3 = 0;
    d->b4 = 0;
    d->b5 = 0;
    d->b6 = 0;
    d->b7 = 0;
    d->b8 = fb8;
    d->b9 = fb9;
    d->b10 = 0;
    d->b11 = 0;
    d->m0 = -1;
    d->m3C = lbl_8065CCE8;
    d->m1C = idv;
    d->m4 = 0;
    d->m8 = 0;
    d->m20 = prio;
    d->m26 = s26;
    d->m28 = s28;
    d->m2A = s2A;
    d->m2C = s2C;
    d->m2E = s2E;
    d->m30 = 0;
    d->m32 = 0;
    d->m34 = 0;
    d->m36 = 0;
    d->m38 = scale;
    fn_8040B830(d->mC, (const char*)name, 16);
    return d;
}

extern "C" void fn_800C7E0C(Unk800C7B40_Data* w, int v)
{
    if (w->b0 != v)
        lbl_8061A330 = 1;
    w->b0 = v;
}

extern "C" void fn_800C7E38(Unk800C7B40_Data* w, int v)
{
    if (w->b3 != v)
        lbl_8061A330 = 1;
    w->b3 = v;
}

extern "C" void fn_800C7E64(Unk800C7B40_Data* w, int v)
{
    if (w->b4 != v)
        lbl_8061A330 = 1;
    w->b4 = v;
}

extern "C" void fn_800C7E90(Unk800C7B40_Data* w, int v)
{
    if (w->b1 != v)
        lbl_8061A330 = 1;
    w->b1 = v;
}

extern "C" void fn_800C7EBC(Unk800C7B40_Data* w, int v)
{
    if (w->b2 != v)
        lbl_8061A330 = 1;
    w->b2 = v;
}

extern "C" void fn_800C8010(Unk800C7B40_Data* w, int a, int b, int c, int d)
{
    w->b6 = 1;
    w->m30 = a;
    w->m32 = b;
    w->m34 = c;
    w->m36 = d;
}

extern "C" void* fn_800C8030(void* p) { return p; }
extern "C" void* fn_800C8034(void* p) { return p; }
extern "C" void* fn_800C8038(void* p) { return p; }
extern "C" void* fn_800C803C(void* p) { return p; }
extern "C" void* fn_800C8040(void* p) { return p; }
extern "C" void* fn_800C8044(void* p) { return p; }
extern "C" void* fn_800C8048(void* p) { return p; }
extern "C" void* fn_800C804C(void* p) { return p; }
extern "C" void* fn_800C8050(void* p) { return p; }
extern "C" void* fn_800C8054(void* p) { return p; }
extern "C" void* fn_800C8058(void* p) { return p; }
extern "C" void* fn_800C805C(void* p) { return p; }
extern "C" void* fn_800C8060(void* p) { return p; }
extern "C" void* fn_800C8064(void* p) { return p; }
extern "C" void* fn_800C8068(void* p) { return p; }
extern "C" void* fn_800C806C(void* p) { return p; }

extern "C" void fn_800C80C0(int* p, int v)
{
    *p = v;
}

/* near-miss: retail sets li r3,0 once before the first compare and then uses beqlr/bnelr for every early exit (o is loaded into r9, not r3) */
extern "C" int fn_800C8070(Unk800C7B40_Data* w)
{
    if (w->m0 != -1)
        return w->m0;
    if (w->m1C == 0)
        return 0;
    Unk800C7B40_Data* o = lbl_8061ABE4;
    if (o == 0)
        return 0;
    if (o->m1C != 0)
        return 0;
    if (o->m0 == -1)
        return 0;
    return o->m0;
}

extern "C" void fn_800C80C8(int* p)
{
    *p = -1;
}

extern "C" int fn_800C80D4()
{
    return 0;
}

extern "C" int fn_800C80DC(Unk800C7B40_Widget* w, int v)
{
    if (w->b0)
        fn_802D7EE4(fn_800C8070(w));
    return 0;
}

extern "C" int fn_800C8110()
{
    return 0;
}

extern "C" void fn_800C83B4(Unk800C7B40_Widget* w, int v)
{
    if (!w->b11) {
        fn_800C80C0(&w->m0, v);
        for (Unk800C7B40_Widget* c = w->m4; c != 0 && (unsigned)c->m20 > (unsigned)w->m20; c = c->m4) {
            if (!c->b11)
                fn_800C80C0(&c->m0, v);
        }
    }
}

extern "C" Unk800D1614_Raw* fn_800C842C(Unk800D1614_Raw* self, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int s1,
                                        int s2, int s3, int s4, float f)
{
    fn_800CEEF0(self, p1, p2, p3, p4, p5, p6, p7, s1, s2, s3, s4, f);
    self->m3C = lbl_806571E8;
    self->m44 = 0;
    self->m48 = 0;
    self->m4C = 0;
    self->m50 = 0;
    self->m54 = 0;
    self->m1C = 0xE;
    return self;
}

extern "C" void fn_800C8B9C(Unk800C7B40_Widget* w, int v)
{
    if (w->b7)
        w->fn_vslot14(fn_800C80D4());
    fn_800CF804(w, v);
}

extern const char* lbl_8061AC30[9];
extern const char* lbl_8061ABE8[3];
extern const char* lbl_8061ABF4[3];
extern const char* lbl_8061AC00[3];
extern const char* lbl_8061AC0C[3];
extern const char* lbl_8061AC18[3];
extern const char* lbl_8061AC24[3];

struct Unk800C8FE8_Flags {
    char pad0[0x68];
    unsigned m68;
};

extern "C" void fn_800C8C08(Unk800D1614_Obj* o, int v)
{
    o->m2A = v;
    if (o->m44 != 0)
        fn_800C8D48(o, v, o->m44);
    if (o->m48 != 0)
        fn_800C8D48(o, v, o->m48);
    if (o->m4C != 0)
        fn_800C8D48(o, v, o->m4C);
    if (o->m50 != 0)
        fn_800C8D48(o, v, o->m50);
    if (o->m54 != 0)
        fn_800C8D48(o, v, o->m54);
}

extern "C" void fn_800C8CA8(Unk800D1614_Obj* o, int v)
{
    o->m2C = v;
    if (o->m44 != 0)
        fn_800C8E98(o, v, o->m44);
    if (o->m48 != 0)
        fn_800C8E98(o, v, o->m48);
    if (o->m4C != 0)
        fn_800C8E98(o, v, o->m4C);
    if (o->m50 != 0)
        fn_800C8E98(o, v, o->m50);
    if (o->m54 != 0)
        fn_800C8E98(o, v, o->m54);
}

extern "C" void fn_800C8D48(Unk800D1614_Obj* o, int v, Unk800C7B40_Widget* unused)
{
    for (int i = 0; i < 3; i++) {
        Unk800C7B40_Widget* a = o->fn_vslot32(lbl_8061ABE8[i], 1);
        Unk800C7B40_Widget* b = o->fn_vslot32(lbl_8061ABF4[i], 1);
        Unk800C7B40_Widget* c = o->fn_vslot32(lbl_8061AC00[i], 1);
        a->fn_vslot9(o->m26);
        b->fn_vslot9(a->m26 + a->m2A);
        b->fn_vslot12(v - a->m2A - c->m2A);
        c->fn_vslot9(b->m26 + b->m2A);
    }
}

extern "C" void fn_800C8E98(Unk800D1614_Obj* o, int v, Unk800C7B40_Widget* unused)
{
    for (int i = 0; i < 3; i++) {
        Unk800C7B40_Widget* a = o->fn_vslot32(lbl_8061AC0C[i], 1);
        Unk800C7B40_Widget* b = o->fn_vslot32(lbl_8061AC18[i], 1);
        Unk800C7B40_Widget* c = o->fn_vslot32(lbl_8061AC24[i], 1);
        a->fn_vslot10(o->m28);
        b->fn_vslot10(a->m28 + a->m2C);
        b->fn_vslot13(v - a->m2C - c->m2C);
        c->fn_vslot10(b->m28 + b->m2C);
    }
}

extern "C" void fn_800C8FE8(void* unused, Unk800C7B40_Widget* w)
{
    w->fn_vslot30(lbl_8061AC30[0], 1);
    for (int i = 0; i < 9; i++) {
        Unk800C7B40_Widget* x = w->fn_vslot30(lbl_8061AC30[i], 1);
        if (x != 0)
            ((Unk800C8FE8_Flags*)fn_800C8038(x))->m68 |= 0x02000000;
    }
}

extern "C" void fn_800C91EC(Unk800D1614_Raw* o, int c)
{
    o->m3C = lbl_806574E0;
    fn_800C97A4(o, c);
    fn_800D0D64((char*)o + 0xDC, 2);
    fn_800D0D64((char*)o + 0xC8, 2);
    fn_800D0D64((char*)o + 0xB4, 2);
    fn_800D0D64((char*)o + 0xA0, 2);
    fn_80356838(o, c);
}

extern "C" void fn_800C9728(Unk800C9728_Obj* o)
{
    fn_800C7EE8(o);
    if (o->m78 != 0)
        o->m78->fn_vslot35(o->m70);
    if (o->m7C != 0)
        o->m7C->fn_vslot35(o->m74);
}

extern "C" void fn_800C97A4(void* p, int unused)
{
    Unk800CB3A8_Grid* g = (Unk800CB3A8_Grid*)p;
    if (*(int**)((char*)g + 0x90) != 0) {
        fn_80377488(*(int**)((char*)g + 0x90));
        *(int**)((char*)g + 0x90) = 0;
    }
    if (g->m98 != 0) {
        fn_80377488(g->m98);
        g->m98 = 0;
    }
    if (g->m9C != 0) {
        fn_80377488(g->m9C);
        g->m9C = 0;
    }
    if (*(int**)((char*)g + 0x88) != 0) {
        fn_80377488(*(int**)((char*)g + 0x88));
        *(int**)((char*)g + 0x88) = 0;
    }
    if (*(int**)((char*)g + 0x8C) != 0) {
        fn_80377488(*(int**)((char*)g + 0x8C));
        *(int**)((char*)g + 0x8C) = 0;
    }
    if (g->m94 != 0) {
        fn_80377488(g->m94);
        g->m94 = 0;
    }
}

extern "C" int fn_800C985C(Unk800CB3A8_Grid* g, int row, int col, int a, int b, int c, int d)
{
    a += g->m60;
    if (row >= a && row <= b && col >= c + g->m64 && col <= d && (!g->b80_2 || g->fn_vslot94(row, col)))
        return 1;
    return 0;
}

extern "C" int fn_800C98E4(Unk800CB3A8_Grid* g, int row, int col, int p3, int p4, int c, int d)
{
    if (row < g->m60 && (col < g->m64 || (col >= c + g->m64 && col <= d)) && (!g->b80_2 || g->fn_vslot94(row, col)))
        return 1;
    return 0;
}

extern "C" int fn_800C9968(Unk800CB3A8_Grid* g, int row, int col, int a, int b, int p5, int p6)
{
    if (col < g->m64 && (row < g->m60 || (row >= a + g->m60 && row <= b)) && (!g->b80_2 || g->fn_vslot94(row, col)))
        return 1;
    return 0;
}

extern "C" int fn_800CA670(Unk800CA670_Obj* o)
{
    fn_800D0D8C((char*)o + 0xA0);
    if (o->b1 == 0)
        return 0;
    if (o->m50 - o->m60 <= 0)
        return 0;
    if (o->m54 == 1) {
        Unk800C7B40_Widget* w = o->fn_vslot32(o->fn_vslot85(), 0);
        for (Unk800C7B40_Widget* c = w->m4; c != 0 && (unsigned)c->m20 > (unsigned)w->m20; c = c->m4) {
            if (c->m1C == 11) {
                ((Unk800C7B40_Widget*)fn_800C805C(c))->fn_vslot41();
                ((Unk800C7B40_Widget*)fn_800C805C(c))->fn_vslot39();
            }
        }
    }
    int old = o->fn_vslot60();
    o->fn_vslot14(0);
    o->fn_vslot118(1);
    if (o->m78 != 0)
        o->m78->fn_vslot45();
    o->fn_vslot14(1);
    if (o->fn_vslot60() != old)
        o->fn_vslot107(0x99);
    Unk800C7B40_Widget* v = o->fn_vslot30("VSPIN", 0);
    if (v != 0)
        ((Unk800C7B40_Widget*)fn_800C805C(((Unk800C7B40_Widget*)fn_800C8044(v))->fn_vslot32("SG1", 1)))->fn_vslot40(1);
    return 1;
}

extern "C" int fn_800CA8C8(Unk800CA8C8_Obj* o)
{
    fn_800D0D90((char*)o + 0xA0);
    if (!o->b1)
        return 0;
    if (o->m78 != 0)
        o->m78->fn_vslot46();
    Unk800C7B40_Widget* w = o->fn_vslot30("VSPIN", 0);
    if (w != 0)
        ((Unk800C7B40_Widget*)fn_800C805C(((Unk800C7B40_Widget*)fn_800C8044(w))->fn_vslot32("SG1", 1)))->fn_vslot41();
    return 1;
}

extern "C" int fn_800CA9A4(Unk800CA670_Obj* o)
{
    fn_800D0D8C((char*)o + 0xB4);
    if (o->b1 == 0)
        return 0;
    if (o->m50 - o->m60 <= 0)
        return 0;
    if (o->m54 == 1) {
        Unk800C7B40_Widget* w = o->fn_vslot32(o->fn_vslot85(), 0);
        for (Unk800C7B40_Widget* c = w->m4; c != 0 && (unsigned)c->m20 > (unsigned)w->m20; c = c->m4) {
            if (c->m1C == 11) {
                ((Unk800C7B40_Widget*)fn_800C805C(c))->fn_vslot41();
                ((Unk800C7B40_Widget*)fn_800C805C(c))->fn_vslot39();
            }
        }
    }
    int old = o->fn_vslot60();
    o->fn_vslot14(0);
    o->fn_vslot118(0);
    if (o->m78 != 0)
        o->m78->fn_vslot47();
    o->fn_vslot14(1);
    if (o->fn_vslot60() != old)
        o->fn_vslot107(0x9A);
    Unk800C7B40_Widget* v = o->fn_vslot30("VSPIN", 0);
    if (v != 0)
        ((Unk800C7B40_Widget*)fn_800C805C(((Unk800C7B40_Widget*)fn_800C8044(v))->fn_vslot32("SG1", 1)))->fn_vslot38(1);
    return 1;
}

extern "C" int fn_800CABFC(Unk800CA8C8_Obj* o)
{
    fn_800D0D90((char*)o + 0xB4);
    if (!o->b1)
        return 0;
    if (o->m78 != 0)
        o->m78->fn_vslot48();
    Unk800C7B40_Widget* w = o->fn_vslot30("VSPIN", 0);
    if (w != 0)
        ((Unk800C7B40_Widget*)fn_800C805C(((Unk800C7B40_Widget*)fn_800C8044(w))->fn_vslot32("SG1", 1)))->fn_vslot39();
    return 1;
}

extern "C" int fn_800CACD8(Unk800CAF58_Obj* o)
{
    fn_800D0D8C((char*)o + 0xDC);
    if (!o->b1 || o->m54 - o->m64 <= 0)
        return 0;
    int old = o->fn_vslot61();
    if (o->m54 == 1) {
        Unk800C7B40_Widget* w = o->fn_vslot32(o->fn_vslot85(), 0);
        for (Unk800C7B40_Widget* c = w->m4; c != 0 && (unsigned)c->m20 > (unsigned)w->m20; c = c->m4) {
            if (c->m1C == 11)
                ((Unk800C7B40_Widget*)fn_800C805C(c))->fn_vslot38(1);
            if (c->m1C == 6)
                ((Unk800C7B40_Widget*)fn_800C804C(c))->fn_vslot47();
        }
    } else {
        o->fn_vslot14(0);
        o->fn_vslot119(0);
        o->fn_vslot14(1);
    }
    if (o->fn_vslot61() != old)
        o->fn_vslot107(0x9A);
    if (o->m7C != 0)
        o->m7C->fn_vslot47();
    Unk800C7B40_Widget* v = o->fn_vslot30("HSPIN", 0);
    if (v != 0)
        ((Unk800C7B40_Widget*)fn_800C805C(((Unk800C7B40_Widget*)fn_800C8044(v))->fn_vslot32("SG1", 1)))->fn_vslot38(0);
    return 1;
}

extern "C" int fn_800CAF58(Unk800CAF58_Obj* o)
{
    fn_800D0D90((char*)o + 0xDC);
    if (!o->b1)
        return 0;
    if (o->m54 == 1 && o->m50 > 0 && o->fn_vslot85()) {
        Unk800C7B40_Widget* w = o->fn_vslot32(o->fn_vslot85(), 0);
        for (Unk800C7B40_Widget* c = w->m4; c != 0 && (unsigned)c->m20 > (unsigned)w->m20; c = c->m4) {
            if (c->m1C == 11)
                ((Unk800C7B40_Widget*)fn_800C805C(c))->fn_vslot39();
            if (c->m1C == 6)
                ((Unk800C7B40_Widget*)fn_800C804C(c))->fn_vslot48();
        }
    }
    if (o->m7C != 0)
        o->m7C->fn_vslot48();
    Unk800C7B40_Widget* v = o->fn_vslot30("HSPIN", 0);
    if (v != 0)
        ((Unk800C7B40_Widget*)fn_800C805C(((Unk800C7B40_Widget*)fn_800C8044(v))->fn_vslot32("SG1", 1)))->fn_vslot39();
    return 1;
}

extern "C" int fn_800CB128(Unk800CAF58_Obj* o)
{
    fn_800D0D8C((char*)o + 0xC8);
    if (o->b1 == 0)
        return 0;
    if (o->m54 - o->m64 <= 0)
        return 0;
    int old = o->fn_vslot61();
    if (o->m54 == 1) {
        Unk800C7B40_Widget* w = o->fn_vslot32(o->fn_vslot85(), 0);
        for (Unk800C7B40_Widget* c = w->m4; c != 0 && (unsigned)c->m20 > (unsigned)w->m20; c = c->m4) {
            if (c->m1C == 11)
                ((Unk800C7B40_Widget*)fn_800C805C(c))->fn_vslot40(1);
            if (c->m1C == 6)
                ((Unk800C7B40_Widget*)fn_800C804C(c))->fn_vslot45();
        }
    } else {
        o->fn_vslot14(0);
        o->fn_vslot119(1);
        o->fn_vslot14(1);
    }
    if (o->fn_vslot61() != old)
        o->fn_vslot107(0x99);
    if (o->m7C != 0)
        o->m7C->fn_vslot45();
    Unk800C7B40_Widget* v = o->fn_vslot30("HSPIN", 0);
    if (v != 0)
        ((Unk800C7B40_Widget*)fn_800C805C(((Unk800C7B40_Widget*)fn_800C8044(v))->fn_vslot32("SG1", 1)))->fn_vslot40(0);
    return 1;
}
