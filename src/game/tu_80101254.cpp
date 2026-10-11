/*
 * Game code, .text 0x80101254-0x80104E24 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


int fn_80101254(void* self)
{
    return fn_800B555C()->m570;
}

int fn_80101344(UiV_2ACi* self)
{
    int a = self->m2AC;
    int b;
    if (fn_8011AA24(0)->m6F8->m14->m1CD0 != 0)
        b = 1;
    else
        b = 0;
    return a == b;
}

void fn_801019F0(UiObj* self)
{
    if (lbl_8061B8C0->m24 == 0) {
        int r = fn_80101254(self);
        if (fn_802D7DB4(r, 0x78) != 0)
            self->v67(0, r);
    }
}

int fn_80101BC8(UiScr2A8* self, int a)
{
    if (fn_80101254(self) != a)
        return 0;
    self->m244[self->m26C]->w4();
    return 1;
}

int fn_80101C34(UiScr2A8* self, int a)
{
    if (fn_80101254(self) != a)
        return 0;
    self->m244[self->m26C]->w5();
    return 1;
}

int fn_80101CA0(UiScr2A8* self, int a)
{
    if (fn_80101254(self) != a)
        return 0;
    self->m2A8->v40(1);
    return 1;
}

int fn_80101D04(UiScr2A8* self, int a)
{
    if (fn_80101254(self) != a)
        return 0;
    self->m2A8->v41();
    return 1;
}

int fn_80101D64(UiScr2A8* self, int a)
{
    if (fn_80101254(self) != a)
        return 0;
    self->m2A8->v38(1);
    return 1;
}

int fn_80101DC8(UiScr2A8* self, int a)
{
    if (fn_80101254(self) != a)
        return 0;
    self->m2A8->v39();
    return 1;
}

int fn_80101E28(UiV_2B4b* self, int a)
{
    int r = fn_80101254(self);
    if (r != a)
        return 0;
    if (self->m2B4 != 0 && self->m2B4->m24 < 0) {
        self->m2B4->v56(r);
        return 1;
    }
    return 0;
}

int fn_80101EA0(UiV_2B4b* self, int a)
{
    int r = fn_80101254(self);
    if (r != a)
        return 0;
    if (self->m2B4 != 0 && self->m2B4->m24 < 0) {
        self->m2B4->v57(r);
        return 1;
    }
    return 0;
}

int fn_80101F18(UiV_2B4b* self, int a)
{
    int r = fn_80101254(self);
    if (r != a)
        return 0;
    if (self->m2B4 != 0 && self->m2B4->m24 < 0) {
        self->m2B4->v54(r);
        return 1;
    }
    return 0;
}

int fn_80101F90(UiV_2B4b* self, int a)
{
    int r = fn_80101254(self);
    if (r != a)
        return 0;
    if (self->m2B4 != 0 && self->m2B4->m24 < 0) {
        self->m2B4->v55(r);
        return 1;
    }
    return 0;
}

extern char lbl_805BE138[];
void fn_80102008(UiScr2A8* self, int a, int b)
{
    if (fn_80101254(self) == b) {
        Ui8011AA24* g = fn_8011AA24(0);
        switch (a) {
        case 0:
            self->m244[self->m26C]->w6(g, self->m2AC);
            return;
        case 1:
            fn_800FEB30(lbl_805BE138, self->m2AC);
            break;
        }
    }
}

void fn_801020A4(UiScr2A8* self)
{
    self->m244[self->m26C]->w9();
}

void fn_801020E8(UiScr2A8* self, UiObjB* a)
{
    if (a == self->m2A8)
        fn_801018F4(self);
}

void fn_80102114(UiScr2A8* self)
{
    self->m244[self->m26C]->w8();
    fn_80101A64(self);
}

void fn_8010216C(UiScr2A8* self)
{
    fn_8010098C((char*)self + 0x270, self->m2AC);
    if (self->m26C != 10)
        self->m244[self->m26C]->w10(0);
    lbl_8061B3BC = 0;
}

extern char lbl_806530C8[];
UiScrRaw* fn_801021E0(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_806530C8;
    self->m130 = 0;
    return self;
}

extern char lbl_805BE138[];
extern char lbl_805B955C[];
void fn_801028D8(UiObj* self, int a)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    const char* s = 0;
    switch (a) {
    case 0:
        s = lbl_805BE138;
        break;
    case 1:
        s = lbl_805B955C;
        break;
    }
    if (s != 0) {
        fn_8040B830(p->name, s, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
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

void fn_80102B0C(UiV_134_138* self, int a)
{
    if (a == 1)
        self->m138->v8(0);
    else if (a == 0)
        self->m134->v8(0);
}

void fn_80102B7C(UiV_134_138* self, int a)
{
    UiObj* p = 0;
    if (a == 1)
        p = self->m138;
    else if (a == 0)
        p = self->m134;
    p->v8(1);
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

void fn_801038EC(UiObj* self)
{
    fn_800ED254(self);
    fn_800C33D0();
    fn_800C3BE0();
    fn_800C33D0()->m5DA4 = 2;
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

void fn_80103DAC(Ui8010B1E0* a, int b, UiObj* c, int d)
{
    int t = fn_8025416C((char*)a + 0x588, 5);
    if (fn_80097288(b, a->m704) == 0 && t != 0 && t != 10) {
        c->v32(d, 1);
        fn_800C8040()->v30(fn_800E5F38(t));
        return;
    }
    fn_8011A1D4(a, b, c, d);
}

extern char lbl_80652380[];
UiScrRaw* fn_80103E80(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80652380;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 1;
    return self;
}

void fn_801044C4()
{
    fn_800C33D0();
    fn_800C3BE0();
}

void fn_801044E8(UiV_134* self, int a, UiObj* obj)
{
    self->m134 = obj;
    obj->v8(0);
    fn_800C3DCC(fn_800C33D0(), self->m134, a);
}
