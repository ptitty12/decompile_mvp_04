/*
 * Game code, .text 0x800F56B4-0x800F92DC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


int fn_800F5AE0(UiObj* self, int a)
{
    return fn_800B555C()->m570 == a;
}

void fn_800F5D54(UiV_134* self, int a)
{
    fn_800ED310(self);
    self->m134->v14(a);
}

int fn_800F5DA4(UiScr134* self, int a)
{
    if (fn_800F5AE0(self, a))
        self->m134->v50();
    return 1;
}

int fn_800F5DF8(UiScr134* self, int a)
{
    if (fn_800F5AE0(self, a))
        self->m134->v51();
    return 1;
}

int fn_800F5E4C(UiScr134* self, int a)
{
    if (fn_800F5AE0(self, a))
        self->m134->v52();
    return 1;
}

int fn_800F5EA0(UiScr134* self, int a)
{
    if (fn_800F5AE0(self, a))
        self->m134->v53();
    return 1;
}

extern char lbl_80650B78[];
UiScrRaw* fn_800F5EF4(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80650B78;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

int fn_800F62D8(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v50();
    return 1;
}

int fn_800F6334(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v51();
    return 1;
}

int fn_800F6390(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v52();
    return 1;
}

int fn_800F63EC(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v53();
    return 1;
}

int fn_800F6448(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v54();
    return 1;
}

int fn_800F64A4(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v55();
    return 1;
}

int fn_800F6500(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v56();
    return 1;
}

int fn_800F655C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v57();
    return 1;
}

void fn_800F65B8(UiV_134* self, int a)
{
    fn_800ED310(self);
    self->m134->v14(a);
}

extern char lbl_8064F8C8[];
UiScrRaw* fn_800F6664(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064F8C8;
    self->m130 = 0;
    return self;
}

void fn_800F7708()
{
}

int fn_800F7C34(UiScr13C* self, int a)
{
    if (fn_800B555C()->m570 == a || (self->m140 == 1 && (a == self->m144 || a == self->m148 || (self->m144 == -1 && self->m148 == -1))))
        return 1;
    return 0;
}

void fn_800F81B0(UiV_13C* self, int a)
{
    fn_800ED310(self);
    self->m13C->v14(a);
}

int fn_800F8200(UiScr13C* self, int a)
{
    if (fn_800F7C34(self, a))
        self->m13C->v50();
    return 1;
}

int fn_800F8254(UiScr13C* self, int a)
{
    if (fn_800F7C34(self, a))
        self->m13C->v51();
    return 1;
}

int fn_800F82A8(UiScr13C* self, int a)
{
    if (fn_800F7C34(self, a))
        self->m13C->v52();
    return 1;
}

int fn_800F82FC(UiScr13C* self, int a)
{
    if (fn_800F7C34(self, a))
        self->m13C->v53();
    return 1;
}

int fn_800F9290(UiObj* self, int a)
{
    int v = fn_800B555C()->m570;
    if (a == v || v == -1)
        return 1;
    return 0;
}
