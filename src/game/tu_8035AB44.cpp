/*
 * Game code, .text 0x8035AB44-0x8035B60C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"

void fn_8035AB44(void* self, int c)
{
    PUT(0x8, lbl_80649DB8);
    fn_80378620(self, c);
}

void* fn_8035AB74(void* self)
{
    fn_803785E4(self);
    PUT(8, lbl_80660100);
    return self;
}

extern "C" void fn_8035ABB0(Unk8035ABB0* s)
{
    s->m0 = lbl_805CFFF4;
    s->m4 = lbl_806055AC;
    s->m10 = lbl_8069429C;
}

void* fn_8035AC10(Unk8035AC10* s, Unk8035AC10* o)
{
    fn_8037936C(s, o);
    s->m10 = o->m10;
    s->m1C = o->m1C;
    return s;
}

/* TODO fn_8035AC6C */

void fn_8035AD80() {}

void fn_8035AD84() {}

void fn_8035AD88(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035ADBC(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035ADF0(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AE24(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AE58(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AE8C(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AEC0(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AEF4(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

int fn_8035AF28(void* p) { return F(int, p, 0x38); }

void fn_8035AF30(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AF64(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AF98(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035AFCC(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B000(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B034(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B068(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B09C(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B0D0(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B104(void* self, int c)
{
    PUT(0x0, lbl_8065F9B0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B138(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

extern "C" void fn_8035B16C(char* self, int c)
{
    fn_8033CD28(self + 0x1d4, 2);
    fn_8033CD28(self + 0x1c8, 2);
    fn_8033CD28(self + 0x1bc, 2);
    fn_8037B424(self, c);
}

extern "C" void fn_8035B1C8(Unk8035B1C8* s)
{
    s->m0 = 0;
    s->m4 = lbl_805D30A4;
    s->m8 = 0;
    s->mC = lbl_805D30A4;
    s->m10 = lbl_805D30A4;
    s->m24 = lbl_805D30A4;
    s->m14 = 0;
    s->m18 = 0;
    s->m1C = 0;
    s->m20 = 0;
}

/* TODO fn_8035B200 */

void fn_8035B3AC(int* p)
{
    p[0] = 0;
    p[1] = 0;
}

extern "C" int fn_8035B3BC(void* p) { return F(int, p, 0x0); }

struct Unk8035B3C4 {
    Unk806055AC m0;
    Unk806055AC mC;
};
void fn_8035B3C4(Unk8035B3C4* s)
{
    s->m0 = lbl_806055AC;
    s->mC = lbl_806055AC;
}

void fn_8035B404(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B438(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B46C(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B4A0(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B4D4(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B508(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

extern "C" void* fn_8035B53C(char* self)
{
    fn_8014D9C4(self + 0x14);
    return self;
}

void fn_8035B570(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B5A4(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_8035B5D8(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}
