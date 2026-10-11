/*
 * Game code, .text 0x800F56B4-0x800F92DC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


int fn_800F5AA8(UiObj* self, int a, int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        if (a == arr[i])
            return 1;
    }
    return 0;
}

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

extern char lbl_805BE138[];
int fn_800F6024(UiObj* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805BE138, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
    return 1;
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

int fn_800F6608(UiV_134i* self, int a)
{
    if (self->m134 == a)
        self->v41(fn_800B555C()->m570);
    return 0;
}

extern char lbl_8064F8C8[];
UiScrRaw* fn_800F6664(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064F8C8;
    self->m130 = 0;
    return self;
}

void fn_800F6AF4(UiObj* self)
{
    fn_800ED254(self);
    fn_801A3704(fn_8011AA24(0), 0);
}

extern char lbl_8065A640[];
UiScrRaw* fn_800F7084(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_8011BFAC(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8065A640;
    return self;
}

void fn_800F7294(UiObj* self)
{
    fn_8011C15C(self);
    void* t = lbl_8068B618->mC;
    if (fn_801A6D84(lbl_8068B618->m8, 1)->m3D90 != 0 || fn_801A6D84(t, 1)->m3D90 != 0)
        self->v8(0);
    else
        self->v8(1);
}

void fn_800F7708()
{
}

extern char lbl_80650368[];
UiScrRaw* fn_800F770C(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80650368;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 5;
    self->m148 = 5;
    return self;
}

int fn_800F7BE0(UiV_13C_140i* self)
{
    int r = self->m13C->v60();
    if (self->m140 == 1)
        r += 2;
    return r;
}

int fn_800F7C34(UiScr13C* self, int a)
{
    if (fn_800B555C()->m570 == a || (self->m140 == 1 && (a == self->m144 || a == self->m148 || (self->m144 == -1 && self->m148 == -1))))
        return 1;
    return 0;
}

int fn_800F7E64(UiV_13Ci* self, int a)
{
    if (a == self->m13C) {
        self->v67(1, 0);
        return 1;
    }
    return 0;
}

void fn_800F80D8(UiV_134* self, int a)
{
    fn_80131F34(self->m134, self, fn_800F817C, 0, a, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
    fn_800C80C0(self->m134, fn_800B555C()->m570);
    self->m134->v86();
}

void fn_800F817C(int a, UiObj* b)
{
    switch (a) {
    case 0:
        break;
    case 1:
        fn_800F7EBC(b);
        break;
    }
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

extern char lbl_806500C0[];
UiScrRaw* fn_800F8350(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_806500C0;
    self->m130 = 0;
    self->m134 = 11;
    self->m138 = 0;
    return self;
}

void fn_800F84F4(UiV_134i* self)
{
    switch (self->m134) {
    case 5:
        lbl_806192E0->m4->m20 = fn_800ABF3C(lbl_80619D10, fn_8011AA24(0))->m18;
        break;
    case 6:
        fn_800AB5C8(lbl_80619D10);
        fn_800AEC80();
        Ui806192E0_B* b = lbl_806192E0->m4;
        b->m20 = fn_800B1FCC();
        break;
    }
}

void fn_800F91FC(int unused, int a, UiObj* obj)
{
    char buf[36];
    obj->v33(4, 1);
    UiObj* o = fn_800C8040();
    fn_80403DE4(buf, (const char*)fn_80090880(lbl_8061977C, 0x29CD), a);
    o->v28(buf);
}

int fn_800F9290(UiObj* self, int a)
{
    int v = fn_800B555C()->m570;
    if (a == v || v == -1)
        return 1;
    return 0;
}
