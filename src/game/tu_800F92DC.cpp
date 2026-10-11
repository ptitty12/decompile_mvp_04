/*
 * Game code, .text 0x800F92DC-0x800FD438 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


int fn_800F92DC(UiV_138* self, int a)
{
    if (self->m138 != 0 && fn_800F9290(self, a))
        self->m138->v50();
    return 1;
}

int fn_800F933C(UiV_138* self, int a)
{
    if (self->m138 != 0 && fn_800F9290(self, a))
        self->m138->v51();
    return 1;
}

int fn_800F939C(UiV_138* self, int a)
{
    if (self->m138 != 0 && fn_800F9290(self, a))
        self->m138->v52();
    return 1;
}

int fn_800F93FC(UiV_138* self, int a)
{
    if (self->m138 != 0 && fn_800F9290(self, a))
        self->m138->v53();
    return 1;
}

extern char lbl_8064FB70[];
UiScrRaw* fn_800F945C(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064FB70;
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

int fn_800F9B70(UiObj* self, int a)
{
    int v = fn_800B555C()->m570;
    if (a == v || v == -1)
        return 1;
    return 0;
}

int fn_800F9BBC(UiScr134* self, int a)
{
    if (fn_800F9B70(self, a))
        self->m134->v50();
    return 1;
}

int fn_800F9C10(UiScr134* self, int a)
{
    if (fn_800F9B70(self, a))
        self->m134->v51();
    return 1;
}

int fn_800F9C64(UiScr134* self, int a)
{
    if (fn_800F9B70(self, a))
        self->m134->v52();
    return 1;
}

int fn_800F9CB8(UiScr134* self, int a)
{
    if (fn_800F9B70(self, a))
        self->m134->v53();
    return 1;
}

/* near-miss: one insn order differs (retail: addi of the vtable address before mr r30,r4) */
extern char lbl_80658FB0[];
extern int lbl_80619D10;
void fn_800F9E4C(UiScrRaw* self, int a)
{
    self->m3C = lbl_80658FB0;
    fn_800AB6B8(lbl_80619D10, a);
    fn_8035686C(self, a);
}

int fn_800FC084()
{
    return 1;
}

void fn_800FCA30(UiV_1E0b* self)
{
    self->m1E0->v8();
}

void fn_800FCA68(UiV_1E4b* self)
{
    self->m1E4->v8();
}

int fn_800FCFA4()
{
    return 0;
}

void fn_800FCFAC()
{
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
    fn_8037893C(fn_8011AA24(0)->m704, 0x9E, 0, 0, 0);
}
