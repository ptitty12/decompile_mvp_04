/*
 * Game code, .text 0x8035688C-0x8035726C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"

/* TODO fn_8035688C */

void fn_80356898(void* p, int v) { F(int, p, 0x130) = v; }

int fn_803568A0(void* p) { return F(int, p, 0x130); }

void fn_803568A8() {}

void fn_803568AC() {}

void fn_803568B0(void* self, int c)
{
    PUT(0x10, lbl_8064A550);
    if (c & 1)
        fn_80377408(self);
}

/* TODO fn_803568E4 */

/* TODO fn_80356930 */

void fn_80356950(void* self, int c)
{
    PUT(0x1c, lbl_8065BA20);
    if (c & 1)
        fn_80377408(self);
}

/* TODO fn_80356984 */

void fn_803569A4(void* self, int c)
{
    PUT(0x4c, lbl_8065BA00);
    if (c & 1)
        fn_80377408(self);
}

/* TODO fn_803569D8 */

void fn_80356A1C(void* self, int c)
{
    PUT(0x0, lbl_8065B9C0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356A50() {}

void fn_80356A54() {}

void fn_80356A58() {}

void fn_80356A5C() {}

void fn_80356A60(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356A94(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356AC8(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356AFC(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356B30(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356B64(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356B98(void* self, int c)
{
    PUT(0x18, lbl_8065B6A8);
    fn_800AB308(self, c);
}

int fn_80356BC8() { return 1; }

void fn_80356BD0(void* self, int c)
{
    PUT(0xc, lbl_8065B690);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356C04(void* self, int c)
{
    PUT(0x8, lbl_80649DB8);
    fn_80378620(self, c);
}

void fn_80356C34(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

/* TODO fn_80356C68 */

int fn_80356C98(void* p) { return F(int, p, 0x34); }

void fn_80356CA0(void* a, int b) { fn_800D3A38(a, b); }

void fn_80356CC0(void* a, int b) { fn_800C6808(a, b); }

extern "C" void fn_80356CE0(void* self, int c)
{
    PUT(0xc, lbl_80659A60);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356D14(void* self, int c)
{
    PUT(0xc, lbl_80659A60);
    if (c & 1)
        fn_80377408(self);
}

/* TODO fn_80356D48 */

void fn_80356D8C(void* self, int c)
{
    PUT(0xc, lbl_80659A60);
    if (c & 1)
        fn_80377408(self);
}

/* TODO fn_80356DC0 */

void fn_80356E04(void* self, int c)
{
    PUT(0x34, lbl_806597A0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356E38(void* self, int c)
{
    PUT(0x3c, lbl_80658D08);
    fn_8035686C(self, c);
}

int fn_80356E68() { return 1; }

int fn_80356E70() { return 1; }

int fn_80356E78() { return 1; }

int fn_80356E80() { return 1; }

/* TODO fn_80356E88 */

/* TODO fn_80356EAC */

void fn_80356F30(void* self, int c)
{
    PUT(0xbc, lbl_80658188);
    PUT(0x3c, lbl_80658248);
    fn_803567C8(self, c);
}

void fn_80356F68(void* self, int c)
{
    PUT(0x40, lbl_80655E98);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356F9C(void* a, int b) { fn_8035686C(a, b); }

void fn_80356FBC(void* self, int c)
{
    PUT(0x3c, lbl_8064C028);
    fn_8035686C(self, c);
}

/* TODO fn_80356FEC */

/* TODO fn_80357074 */

void* fn_8035709C(void* self)
{
    PUT(0, lbl_8065D2E8);
    return self;
}

/* TODO fn_803570B0 */

int fn_80357104() { return 1; }

/* TODO fn_8035710C */

void fn_80357154(UiPtr0* p) { fn_800FF590(p); }

/* TODO fn_80357174 */

int fn_8035719C() { return 1; }

int fn_803571A4() { return 1; }

int fn_803571AC() { return 0; }

/* TODO fn_803571B4 */

/* TODO fn_803571D8 */

void fn_80357204(void* a, int b, int c) { fn_800FEB30(lbl_805BE138, c); }

int fn_80357230(void* a, VT3C* s) { return s->s29(0x263c); }
