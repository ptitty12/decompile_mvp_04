/*
 * Game code, .text 0x80101254-0x80104E24 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


int fn_80101254()
{
    return fn_800B555C()->m570;
}

/* near-miss: same code but the prologue moves a (r4) before self (r3); retail moves self first (two insns swapped) */
int fn_80101BC8(UiScr2A8* self, int a)
{
    if (fn_80101254() != a)
        return 0;
    self->m244[self->m26C]->w4();
    return 1;
}

/* near-miss: same code but the prologue moves a (r4) before self (r3); retail moves self first (two insns swapped) */
int fn_80101C34(UiScr2A8* self, int a)
{
    if (fn_80101254() != a)
        return 0;
    self->m244[self->m26C]->w5();
    return 1;
}

/* near-miss: same code but the prologue moves a (r4) before self (r3); retail moves self first (two insns swapped) */
int fn_80101CA0(UiScr2A8* self, int a)
{
    if (fn_80101254() != a)
        return 0;
    self->m2A8->v40(1);
    return 1;
}

/* near-miss: same code but the prologue moves a (r4) before self (r3); retail moves self first (two insns swapped) */
int fn_80101D04(UiScr2A8* self, int a)
{
    if (fn_80101254() != a)
        return 0;
    self->m2A8->v41();
    return 1;
}

/* near-miss: same code but the prologue moves a (r4) before self (r3); retail moves self first (two insns swapped) */
int fn_80101D64(UiScr2A8* self, int a)
{
    if (fn_80101254() != a)
        return 0;
    self->m2A8->v38(1);
    return 1;
}

/* near-miss: same code but the prologue moves a (r4) before self (r3); retail moves self first (two insns swapped) */
int fn_80101DC8(UiScr2A8* self, int a)
{
    if (fn_80101254() != a)
        return 0;
    self->m2A8->v39();
    return 1;
}

/* near-miss: same code but the prologue moves a (r4) before self (r3); retail moves self first (two insns swapped) */
int fn_80101E28(UiV_2B4b* self, int a)
{
    int r = fn_80101254();
    if (r != a)
        return 0;
    if (self->m2B4 != 0 && self->m2B4->m24 < 0) {
        self->m2B4->v56(r);
        return 1;
    }
    return 0;
}

/* near-miss: same code but the prologue moves a (r4) before self (r3); retail moves self first (two insns swapped) */
int fn_80101EA0(UiV_2B4b* self, int a)
{
    int r = fn_80101254();
    if (r != a)
        return 0;
    if (self->m2B4 != 0 && self->m2B4->m24 < 0) {
        self->m2B4->v57(r);
        return 1;
    }
    return 0;
}

/* near-miss: same code but the prologue moves a (r4) before self (r3); retail moves self first (two insns swapped) */
int fn_80101F18(UiV_2B4b* self, int a)
{
    int r = fn_80101254();
    if (r != a)
        return 0;
    if (self->m2B4 != 0 && self->m2B4->m24 < 0) {
        self->m2B4->v54(r);
        return 1;
    }
    return 0;
}

/* near-miss: same code but the prologue moves a (r4) before self (r3); retail moves self first (two insns swapped) */
int fn_80101F90(UiV_2B4b* self, int a)
{
    int r = fn_80101254();
    if (r != a)
        return 0;
    if (self->m2B4 != 0 && self->m2B4->m24 < 0) {
        self->m2B4->v55(r);
        return 1;
    }
    return 0;
}

extern char lbl_806530C8[];
UiScrRaw* fn_801021E0(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_806530C8;
    self->m130 = 0;
    return self;
}

extern char lbl_80652E20[];
UiScrRaw* fn_8010298C(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80652E20;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern char lbl_8065C238[];
UiScrRaw* fn_80102F5C(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8065C238;
    self->m130 = 0;
    return self;
}

extern char lbl_80652B78[];
UiScrRaw* fn_801030F0(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80652B78;
    self->m130 = 0;
    return self;
}

void fn_80103234(UiObj* self)
{
    fn_800ED254(self);
    fn_800C33D0();
    fn_800C3BE0();
}

extern char lbl_806528D0[];
UiScrRaw* fn_801035BC(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_806528D0;
    self->m130 = 0;
    return self;
}

void fn_80103844(UiObj* self)
{
    fn_800ED254(self);
    fn_800C33D0();
    fn_800C3BE0();
}

extern char lbl_80652628[];
UiScrRaw* fn_8010386C(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80652628;
    self->m130 = 0;
    return self;
}

void fn_801038B8(UiObj* self)
{
    fn_800ECF18(self);
    fn_80103920(self);
}

extern char lbl_80653618[];
UiScrRaw* fn_80103AEC(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80653618;
    self->m130 = 0;
    return self;
}

void fn_80103B38(UiObj* self)
{
    fn_800ECF18(self);
}

extern char lbl_80653370[];
UiScrRaw* fn_80103B58(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80653370;
    self->m130 = 0;
    return self;
}
