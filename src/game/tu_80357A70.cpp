/*
 * Game code, .text 0x80357A70-0x803597C4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"

void* fn_80357A70(void* self)
{
    fn_80358588__FPv(self);
    PUT(0, lbl_8065D748);
    return self;
}

void fn_80357AAC(void* self, int c)
{
    PUT(0x18, lbl_8065D5A0);
    fn_80328374(self, c);
}

void fn_80357ADC() {}

void fn_80357AE0() {}

void fn_80357AE4() {}

void fn_80357AE8() {}

void* fn_80357AEC(void* self)
{
    fn_8035859C__FPv(self);
    PUT(0, lbl_8065D730);
    return self;
}

void fn_80357B28(void* self, int c)
{
    PUT(0x2dc, lbl_8065D550);
    fn_80330778(self, c);
}

/* TODO fn_80357B58 */

extern "C" void fn_80358484(void* a, int b) { fn_8037B424(a, b); }

void fn_803584A4(void* self, int c)
{
    PUT(0x0, lbl_8065D448);
    if (c & 1)
        fn_80377408(self);
}

char* fn_803584D8(char* self, int i) { return self + 4 + i * 12; }

char* fn_803584E8(char* p) { return p + 0x4; }

int fn_803584F0() { return 4; }

int fn_803584F8() { return 1; }

int fn_80358500() { return -1; }

void fn_80358508(void* p, int v) { F(int, p, 0x10) = v; }

int fn_80358510(void* p) { return F(int, p, 0x10); }

int fn_80358518() { return 1; }

const char* fn_80358520(int* self)
{
    return self[4] == 0 ? lbl_805F31CC : lbl_805F31EC;
}

const char* fn_80358544(int* self)
{
    return self[4] == 0 ? lbl_805F320C : lbl_805F321C;
}

int fn_80358568() { return 1; }

int fn_80358570() { return 1; }

int fn_80358578() { return 1; }

int fn_80358580() { return 2; }

void* fn_80358588(void* self)
{
    PUT(0, lbl_8065D868);
    return self;
}

void* fn_8035859C(void* self)
{
    PUT(0, lbl_8065D850);
    return self;
}

void fn_803585B0(void* a, void* b, int c) { fn_802B9300(b, c, 14); }

void fn_803585DC(void* a, void* b) { fn_802B96C4(b, 0); }

void fn_80358604(float a, float b, float c, float d, float e) { fn_8033D14C(a, b, c, d, e); }

void fn_8035864C(void* self, int c)
{
    PUT(0x2dc, lbl_8065D6E0);
    fn_80330778(self, c);
}

/* TODO fn_8035867C */

void fn_80358868(void* self, int c)
{
    PUT(0x2dc, lbl_8065D690);
    fn_80330778(self, c);
}

/* TODO fn_80358898 */

void fn_80358F54(void* self, int c)
{
    PUT(0x2dc, lbl_8065D640);
    fn_80330778(self, c);
}

/* TODO fn_80358F84 */

void fn_8035929C(void* self, int c)
{
    PUT(0x2dc, lbl_8065D800);
    fn_80330778(self, c);
}

struct Unk54 {
    char pad0[0x54];
};
void fn_803592CC(void* self)
{
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C484C, lbl_80691CAC, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C485C, lbl_80691CB0, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C4870, lbl_80691CB4, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C4884, lbl_80691CB8, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C4898, lbl_80691CBC, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C48A8, lbl_80691CC0, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C48B8, lbl_80691CC4, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C48CC, lbl_80691CDC, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C48E4, lbl_80691CE0, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C48F0, lbl_80691CE4, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C4904, lbl_80691CE8, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C4918, lbl_80691CEC, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C4924, lbl_80691CF0, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C4930, lbl_80691CF4, 0));
    fn_80330ACC(self, fn_8032F19C(new (0) Unk54, lbl_805C4944, lbl_80691D14, 0));
}

void fn_803595C4(void* a, int b) { fn_80328374(a, b); }

void fn_803595E4(void* a, int b) { fn_8037B424(a, b); }

extern "C" void fn_80359604(void* a, int b) { fn_8037B424(a, b); }

struct Unk80359624 {
    int m0;
    int m4;
    int m8;
    Unk805EBA10 mC;
    Unk805EBA10 m24;
    Unk805EBA10 m3C;
};
void fn_80359624(Unk80359624* s)
{
    s->m0 = 0;
    s->m4 = 0;
    s->m8 = 0;
    s->mC = lbl_805EBA10;
    s->m24 = lbl_805EBA10;
    s->m3C = lbl_805EBA10;
}

extern "C" void fn_803596DC(Unk803596DC* s) { s->Init(); }
