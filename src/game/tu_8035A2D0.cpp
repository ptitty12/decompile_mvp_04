/*
 * Game code, .text 0x8035A2D0-0x8035AB44 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"

void fn_8035A2D0(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

extern "C" void fn_8035A304(void* a, int b) { fn_8037B424(a, b); }

extern "C" void fn_8035A324(void* a, int b) { fn_8037B424(a, b); }

extern "C" void fn_8035A344(void* a, int b) { fn_8037B424(a, b); }

void fn_8035A364(void* a, int b) { fn_8035AB14(a, b); }

void fn_8035A384(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A3A4(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A3C4(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A3E4(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A404(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A424(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A444(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A464(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A484(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A4A4(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A4C4(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A4E4(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A504(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A524(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A544(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A564(void* a, int b) { fn_80356C04(a, b); }

void fn_8035A584(void* a, int b) { fn_80356C04(a, b); }

extern "C" void fn_8035A5A4(void* a, int b) { fn_8037B424(a, b); }

void fn_8035A5C4(void* self, int c)
{
    PUT(0xc, lbl_8065B690);
    if (c & 1)
        fn_80377408(self);
}

struct Unk8035A5F8 {
    int m0;
    int m4;
    int m8;
    const void* mC;
    Unk8035A5F8();
};
Unk8035A5F8::Unk8035A5F8()
{
    m0 = 0;
    m4 = 0;
    mC = lbl_80660638;
}

extern "C" /* near-miss: 4 slots. Retail loads lbl_805CFFE8 (f13) before lbl_805CFFE4 (f0) and stores 0x8C/0x94/0x90 in
   another order; store-order hill climbing and chained assignments stay at 4 */
void fn_8035A618(Unk8035A618_S* s)
{
    s->m0 = 0;
    s->m78 = lbl_805CFFE8;
    s->m6C = 0;
    s->m90 = lbl_805CFFE4;
    s->m94 = lbl_805CFFE4;
    s->m8C = lbl_805CFFE4;
    s->m74 = lbl_805CFFE8;
    s->m70 = lbl_805CFFE8;
    s->m7C = lbl_8069429C;
    s->m68 = lbl_805CFFE8;
    s->m64 = lbl_805CFFE8;
    s->m60 = lbl_805CFFE8;
}

void fn_8035A688(void* self, int c)
{
    PUT(0x98, lbl_806604F8);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035A6BC(Unk8035A618_S* s, float x, float y, float z)
{
    s->m0 = 0;
    s->m60 = x;
    s->m64 = y;
    s->m68 = z;
}

struct Unk8035A6F4_V {
    int m0;
    int m4;
    int m8;
};
void fn_8035A6F4(char* s, Unk8035A6F4_V* v)
{
    F(int, s, 0) = 0;
    *(Unk8035A6F4_V*)(s + 0x60) = *v;
}

/* TODO fn_8035A71C */

void fn_8035A7D8(void* self, int c)
{
    PUT(0x164, lbl_806604E0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035A80C(char* s)
{
    F(float, s, 0) = lbl_805CFFEC;
    fn_803DF74C(s + 0x20);
    F(int, s, 0x60) = 0;
}

struct Unk8035A850 {
    Unk806055AC m0;
    Unk806055AC mC;
    int m18;
};
void fn_8035A850(Unk8035A850* s)
{
    s->m0 = lbl_806055AC;
    s->mC = lbl_806055AC;
    s->m18 = 0;
}

void fn_8035A898(char* self, int c)
{
    PUT(0x10, lbl_806604C8);
    void* p = F(void*, self, 4);
    if (p != 0)
        fn_80377488(p);
    void* q = F(void*, self, 8);
    if (q != 0)
        fn_80377488(q);
    if (c & 1)
        fn_80377408(self);
}

extern "C" void fn_8035A900(Unk8035A900* s)
{
    for (int i = 0; i < s->cnt - 1; i++) {
        Unk8035A900_E* e = (Unk8035A900_E*)(i * 0x1c + (int)s->m8);
        e->m0 = lbl_806055AC;
        e->mC = lbl_806055AC;
        e->m18 = 0;
    }
}

int fn_8035A97C(int* s, int v) { return (v + 1) % s[0]; }

void fn_8035A994(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035A9C8(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035A9FC(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AA30(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AA64(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AA98(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AACC(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

extern "C" void* fn_8035AB00(void* self)
{
    PUT(0, lbl_80660620);
    return self;
}

void fn_8035AB14(void* self, int c)
{
    PUT(0x8, lbl_80649DB8);
    fn_80378620(self, c);
}
