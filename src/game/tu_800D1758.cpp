/*
 * Game code, .text 0x800D1758-0x800D4D0C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

extern int lbl_8061A328;
extern "C" void fn_800D0D90(void* p);
extern "C" void fn_80377488(void* p); /* __builtin_vec_delete */
extern "C" void fn_800D0D8C(void* p);
extern "C" int fn_800D0D94(void* p);
extern void* lbl_8061E978;

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

extern "C" void fn_800D3164()
{
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
extern "C" char* fn_800D3EAC(Unk800D2338_Obj* o)
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
