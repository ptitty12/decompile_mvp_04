/*
 * Game code, .text 0x800D1758-0x800D4D0C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

extern int lbl_8061A328;
extern const float lbl_805BC968;
extern const float lbl_805BC96C;
extern const float lbl_805BC970;
extern const float lbl_805BC974;
extern "C" void fn_800D0D90(void* p);
extern "C" void fn_80377488(void* p); /* __builtin_vec_delete */
extern "C" void fn_800D0D8C(void* p);
extern "C" int fn_800D0D94(void* p);
extern void* lbl_8061E978;

inline void SetM38(Unk800C7B40_Data* d, float v)
{
    d->m38 = v;
}

extern const float lbl_805BC848;
extern const float lbl_805BC84C;
struct Unk800D1A24_Rgba {
    float r, g, b, a;
};
inline float Clamp01(float t)
{
    return !(t > lbl_805BC848) ? (t >? lbl_805BC84C) : lbl_805BC848;
}
/* near-miss: four [0,1] clamps of stack floats; ours copies the loaded value (fmr f0,f12) where retail loads straight into the result register; if/else and ternary spellings were worse */
extern "C" void fn_800D1A24(Unk800D2338_Obj* o)
{
    o->m5C = lbl_8061A328;
    float r = lbl_805BC848;
    float g = lbl_805BC848;
    float b = lbl_805BC848;
    float a = lbl_805BC848;
    Unk800D1A24_Rgba* c = (Unk800D1A24_Rgba*)((char*)o + 0x6C);
    c->r = !(r > lbl_805BC848) ? (r >? lbl_805BC84C) : lbl_805BC848;
    c->g = !(g > lbl_805BC848) ? (g >? lbl_805BC84C) : lbl_805BC848;
    c->b = !(b > lbl_805BC848) ? (b >? lbl_805BC84C) : lbl_805BC848;
    c->a = !(a > lbl_805BC848) ? (a >? lbl_805BC84C) : lbl_805BC848;
}

/* near-miss: 7 slots (retail returns 1 inline after bne and keeps the end pointer in r30 = p + 76) */
extern "C" int fn_800D1CA4(const char* name)
{
    Unk800D1CA4_Tbl t __attribute__((aligned(4))) = lbl_805BC8F0;
    const char** p = t.v;
    do {
        if (fn_8040B574(name, *p++) == 0)
            return 1;
    } while (p < &t.v[19]);
    return 0;
}

#define SEL(o) ((Unk800CFEEC_Sel*)((char*)(o) + 0x98))

extern "C" void fn_800D2338(Unk800D2338_Obj* o, const char* name, int flag)
{
    fn_8040B830(o->m4A, name, 5);
    o->b68_2 = flag;
    if (o->b68_2)
        fn_800D24A4(o);
}

void Unk800D238C_Obj::fn_800D238C(int v)
{
    m5C = lbl_8061A328;
    fn_800C7E38(this, v);
}

void Unk800D238C_Obj::fn_800D23BC(int v)
{
    m5C = lbl_8061A328;
    fn_800C7E64(this, v);
}

void Unk800D238C_Obj::fn_800D23EC(int v)
{
    m5C = lbl_8061A328;
    fn_800C7E0C(this, v);
}

void Unk800D238C_Obj::fn_800D241C(int v)
{
    m5C = lbl_8061A328;
    fn_800C7E90(this, v);
}

void Unk800D238C_Obj::fn_800D244C(const Unk800D244C_Vec4& v)
{
    m6C = v;
}

void Unk800D238C_Obj::fn_800D2474(int v)
{
    m5C = lbl_8061A328;
    fn_800C7EBC(this, v);
}

extern "C" void fn_800D24A4(Unk800D2338_Obj* o)
{
    void* t = lbl_8061E978;
    o->m7C = (int)fn_802B0850(t, o->m4A, &o->m64);
    o->m80 = fn_802B0ACC(t, o->m4A);
}

inline float WrapAngle(float t)
{
    return t - (float)fn_80410634(t * lbl_805BC96C + lbl_805BC970) * lbl_805BC968;
}

/* near-miss: retail recomputes src+0x40 for each string call and keeps only this+0x40 in a saved register */
extern "C" void fn_800D2524(Unk800D2338_Obj* o, Unk800D2338_Obj* a, Unk800D2338_Obj* src, float t)
{
    fn_800C8118(o, a, src, t);
    if (fn_8040B574(o->m40, src->m40) != 0 || fn_8040B574(o->m45, src->m45) != 0)
        o->m5C = lbl_8061A328;
    fn_8040B61C(o->m40, src->m40);
    fn_8040B61C(o->m45, src->m45);
    o->b68_0 = src->b68_0;
    o->b68_1 = src->b68_1;
    o->m50 = src->m50;
    o->m54 = src->m54;
    o->m58 = src->m58;
    o->m60 = src->m60;
    float x = a->m90 + (src->m90 - a->m90) * t;
    fn_800D2614(o, x);
}

extern "C" void fn_800D2614(Unk800D2338_Obj* o, float f)
{
    if (f <= lbl_805BC968)
        o->m90 = f;
    else
        o->m90 = WrapAngle(f);
    if (!(o->m90 >= lbl_805BC974))
        o->m90 = o->m90 + lbl_805BC968;
    o->b68_5 = 1;
}

/* near-miss: 2 slots (retail sets r4 before r3 for the fn_800CFEEC call) */
extern "C" Unk800D26C8_Raw* fn_800D26C8(Unk800D26C8_Raw* self, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int s0,
                                        int s1, int s2, int s3, int s4, int s5, float f1, float f2)
{
    fn_800D1758(self, p1, p2, p3, p4, p5, p6, p7, s0, (int)&lbl_805B6F58, (int)&lbl_805B6F58, 0, 0, 0, s2, s3, s4, s5, f1, f2);
    self->m98.fn_800CFEEC(s1);
    self->m98.m24 = lbl_80658188;
    self->m3C = lbl_80658248;
    self->m210 = 1;
    self->m1C = 9;
    SetM38(self, f1);
    return self;
}

extern "C" void fn_800D279C(Unk800D2338_Obj* o)
{
    if (SEL(o)->fn_vslot13() > 0 && o->b0)
        fn_800D1D5C(o);
}

extern "C" int fn_800D27FC(Unk800D2338_Obj* o)
{
    if (o->b1 == 0)
        return 0;
    fn_800CFF7C((Unk800CFEEC_Data*)SEL(o));
    int i = SEL(o)->fn_vslot5();
    fn_800D2338(o, o->mC0 + i * 5, o->m210);
    return 1;
}

extern "C" int fn_800D287C(Unk800D2338_Obj* o)
{
    if (o->b1 == 0)
        return 0;
    fn_800CFFB4((Unk800CFEEC_Data*)SEL(o));
    int i = SEL(o)->fn_vslot5();
    fn_800D2338(o, o->mC0 + i * 5, o->m210);
    return 1;
}

extern "C" void fn_800D28FC(Unk800D2338_Obj* o, int a)
{
    fn_800CFF48((Unk800CFEEC_Data*)SEL(o), a);
    int i = SEL(o)->fn_vslot5();
    fn_800D2338(o, o->mC0 + i * 5, o->m210);
}

extern "C" void fn_800D2964(Unk800D2338_Obj* o, const char* name, int id, int v)
{
    int n = SEL(o)->fn_vslot13();
    fn_8040B61C(o->mC0 + n * 5, name);
    o->m17C[n] = id;
    o->m210 = v;
    if (n == SEL(o)->fn_vslot5()) {
        int i = SEL(o)->fn_vslot5();
        fn_800D2338(o, o->mC0 + i * 5, o->m210);
    }
    SEL(o)->fn_vslot14(n + 1);
}

extern "C" void fn_800D2A4C(Unk800D2338_Obj* o, int idx)
{
    SEL(o)->fn_vslot14(SEL(o)->fn_vslot13() - 1);
    for (int i = idx; i < SEL(o)->fn_vslot13(); i++) {
        fn_8040B61C(o->mC0 + i * 5, o->mC0 + i * 5 + 5);
        o->m17C[i] = o->m17C[i + 1];
    }
}

extern "C" void fn_800D2B24(Unk800D2338_Obj* o, int a)
{
    o->m210 = a;
    int i = SEL(o)->fn_vslot5();
    fn_800D2338(o, o->mC0 + i * 5, o->m210);
}

extern "C" void fn_800D2B88(Unk800D2338_Obj* o)
{
    int i = SEL(o)->fn_vslot7();
    if (i != -1)
        SEL(o)->fn_vslot3(i);
}

extern "C" void fn_800D2BF0(Unk800D2338_Obj* o)
{
    int i = SEL(o)->fn_vslot7();
    if (i != -1)
        SEL(o)->fn_vslot6(i);
}

extern "C" int fn_800D2C58(Unk800D2338_Obj* o, int id)
{
    for (int i = 0; i < SEL(o)->fn_vslot13(); i++) {
        if (o->m17C[i] == id)
            return i;
    }
    return -1;
}

extern "C" void fn_800D2CD8(Unk800D2CD8_Obj* o, int i, int v)
{
    o->m17C[i] = v;
}

extern "C" int fn_800D2CE8(Unk800D2CD8_Obj* o, int i)
{
    return o->m17C[i];
}

extern const char lbl_805BC978[];

extern "C" void fn_800D2CF8(Unk800C7B40_Widget* w, int id)
{
    char buf[12];
    char c = w->fn_vslot33(0)[0];
    int r = fn_800B548C(id);
    fn_804089B4(buf, lbl_805BC978, c, fn_800E1AC8(id));
    w->fn_vslot31(buf, r, 1);
}

extern "C" void fn_800D2D9C(Unk800C7B40_Widget* w, int id)
{
    char buf[16];
    char c = w->fn_vslot33(0)[0];
    fn_804089B4(buf, lbl_805BC978, c, fn_800E1AC8(fn_800B5520((void*)id)));
    w->fn_vslot31(buf, id, 1);
}

extern "C" Unk800D26C8_Raw* fn_800D30D4(Unk800D26C8_Raw* self, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int s0,
                                        int s1, int s2, int s3, int s4, int s5, float f1, float f2)
{
    fn_800D26C8(self, p1, p2, p3, p4, p5, p6, p7, s0, s1, s2, s3, s4, s5, f1, f2);
    self->m98.m24 = lbl_80657308;
    self->m3C = lbl_806573C8;
    self->m1C = 12;
    return self;
}

extern "C" void fn_800D3164()
{
}

extern "C" Unk800D26C8_Raw* fn_800D3168(Unk800D26C8_Raw* self, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int a,
                                        int b, int c, int d, float f)
{
    fn_800CEEF0(self, p1, p2, p3, p4, p5, p6, p7, a, 0, c, d, f);
    self->m44 = 0;
    self->m48 = 0;
    self->m3C = lbl_80657078;
    new ((char*)self + 0x4C) Unk800D0D3C_Obj;
    new ((char*)self + 0x60) Unk800D0D3C_Obj;
    self->m74 = b;
    self->m1C = 11;
    return self;
}

extern "C" void fn_800CEF98(Unk800D1614_Obj* o);

extern "C" void fn_800D31F8(Unk800D1614_Obj* o)
{
    fn_800CEF98(o);
    o->m44 = (Unk800C7B40_Widget*)fn_800C8034(o->fn_vslot32("NEXT", 1));
    o->m48 = (Unk800C7B40_Widget*)fn_800C8034(o->fn_vslot32("PREV", 1));
}

extern "C" void fn_800D327C(Unk800D1614_Obj* o)
{
    int n = fn_800D0D94((char*)o + 0x4C);
    for (int i = 0; i < n; i++)
        o->fn_vslot38(1);
    n = fn_800D0D94((char*)o + 0x60);
    for (int i = 0; i < n; i++)
        o->fn_vslot40(1);
}

extern "C" void fn_800D331C(Unk800D1614_Obj* o, int a)
{
    if (o->b1) {
        if (o->m44 != 0) {
            if (o->m44->b0 && a != 0)
                fn_8001BC4C()->fn_8001BDAC(0x9C);
            o->m44->fn_vslot15(1);
        }
        o->fn_vslot35();
        fn_800D0D8C((char*)o + 0x4C);
    }
}

extern "C" void fn_800D33BC(Unk800D1614_Obj* o)
{
    if (o->m44 != 0)
        o->m44->fn_vslot15(0);
    fn_800D0D90((char*)o + 0x4C);
}

extern "C" void fn_800D3414(Unk800D1614_Obj* o, int a)
{
    if (o->b1) {
        if (o->m48 != 0) {
            if (o->m48->b0 && a != 0)
                fn_8001BC4C()->fn_8001BDAC(0x9B);
            o->m48->fn_vslot15(1);
        }
        o->fn_vslot36();
        fn_800D0D8C((char*)o + 0x60);
    }
}

extern "C" void fn_800D34B4(Unk800D1614_Obj* o)
{
    if (o->m48 != 0)
        o->m48->fn_vslot15(0);
    fn_800D0D90((char*)o + 0x60);
}

extern "C" void fn_800D372C(Unk800C7B40_Widget* w, int a)
{
    for (Unk800C7B40_Widget* c = w->m4; c != 0 && (unsigned)c->m20 > (unsigned)w->m20; c = c->m4) {
        if (c->m1C == 10)
            ((Unk800CFEEC_Sel*)((char*)fn_800C8058(c) + 0xDC))->fn_vslot6(a);
        else if (c->m1C == 9)
            ((Unk800CFEEC_Sel*)((char*)fn_800C8054(c) + 0x98))->fn_vslot6(a);
    }
}

extern "C" int fn_800D37E4(Unk800C7B40_Data* w)
{
    fn_802D7EE4(fn_800C8070(w));
    fn_802D7EE4(fn_800C8070(w));
    return 0;
}

extern "C" void fn_800D3824(Unk800D1614_Obj* o, int a)
{
    o->m44->fn_vslot8(a);
    o->m48->fn_vslot8(a);
}

extern "C" void fn_800D3A38(Unk800D3A38_Raw* o, int c)
{
    o->m3C = lbl_8065BC68;
    if (o->m40 != 0) {
        fn_80377488(o->m40);
        o->m40 = 0;
    }
    o->m3C = lbl_8065CCE8;
    if (c & 1)
        fn_80377408(o);
}

/* near-miss: retail holds o->m44 in r4 (callers of fn_80090880 pass the id in r4, but the symbol is declared with one parameter) and m68 in r0 */
extern "C" char* fn_800D3EAC(Unk800D3EAC_Obj* o)
{
    if (o->b68_0 || o->m44 == -1 || o->b68_2) {
        char* p = o->m40;
        if (p == 0)
            p = &lbl_8061AC58;
        return p;
    }
    return fn_80090880(lbl_8061977C);
}

extern "C" void fn_800D4208(Unk800C7B40_Widget* w)
{
    char buf[800];
    fn_804031BC(buf);
    w->fn_vslot28(buf);
}

extern "C" int fn_800D4538(Unk800D2338_Obj* o)
{
    if (o->b68_0 && o->b1)
        fn_802D7EE4(fn_800C8070(o));
    return 0;
}

extern "C" int fn_800D4578()
{
    return 0;
}

extern "C" void fn_800D4B88(Unk800D4B88_Obj* o, int a, int c)
{
    o->b0 = a;
    o->m84 = c;
}
