/*
 * Game code, .text 0x80357A70-0x803597C4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"

void* fn_80357A70(void* self)
{
    fn_80358588(self);
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
    fn_8035859C(self);
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

/* TODO fn_803584D8 */

char* fn_803584E8(char* p) { return p + 0x4; }

int fn_803584F0() { return 4; }

int fn_803584F8() { return 1; }

int fn_80358500() { return -1; }

void fn_80358508(void* p, int v) { F(int, p, 0x10) = v; }

int fn_80358510(void* p) { return F(int, p, 0x10); }

int fn_80358518() { return 1; }

/* TODO fn_80358520 */

/* TODO fn_80358544 */

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

/* TODO fn_803585B0 */

/* TODO fn_803585DC */

/* TODO fn_80358604 */

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

/* TODO fn_803592CC */

void fn_803595C4(void* a, int b) { fn_80328374(a, b); }

void fn_803595E4(void* a, int b) { fn_8037B424(a, b); }

extern "C" void fn_80359604(void* a, int b) { fn_8037B424(a, b); }

/* TODO fn_80359624 */

/* TODO fn_803596DC */
