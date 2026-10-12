/*
 * Game code, .text 0x80101254-0x80104E24 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"

extern "C" void* fn_800C8058(int);

#include "game/tu_8001B190.h"
extern char lbl_805BF3D4[];
extern char lbl_805BF468[];
extern char lbl_805BF470[];
extern char lbl_805BF478[];
extern char lbl_805BF480[];
extern char lbl_805BF488[];
void fn_8011A2F4(int a, Ui8011AA24* g, UiObj* c, char* s, int f);
void fn_8011A2AC(int a, UiObj* c, char* s);
void fn_8011A3CC(int a, UiObj* c, char* s);
void fn_8011A414(int a, UiObj* c, char* s);
void fn_8011A468(int a, UiObj* c, char* s);
extern char lbl_805BF3C4[];
extern char lbl_805BE5B8[];
extern char lbl_805BE3BC[];
extern char lbl_805BE5C0[];
extern char lbl_805BE5C8[];
extern char lbl_805BF458[];
extern char lbl_805BF460[];
extern char lbl_805BF564[];
struct UiP70C {
    char pad0[0x70C];
    unsigned char m70C;
};
struct UiEnt {
    char pad0[0x17C];
    unsigned char m17C;
    char pad17D[0xC9C - 0x17D];
    char mC9C[1];
};
extern "C" int fn_80099570(void* o, int a, unsigned char b, int c);
int fn_8008CFD8(char* p, int a, unsigned char b);
extern char lbl_805BF3A8[];
extern char lbl_805BEAB8[];
extern char lbl_805BEAC0[];
extern char lbl_805BEA84[];
extern char lbl_805BF3B4[];
struct UiQ1CC8 {
    char pad0[0x198];
    int m198;
    char pad19C[0xFFC - 0x19C];
    int mFFC;
    char pad1000[0x1CC8 - 0x1000];
    unsigned char m1CC8;
    char pad1CC9[7];
    int m1CD0;
};
struct UiP54 {
    char pad0[0x14];
    UiQ1CC8* m14;
    char pad18[0x54 - 0x18];
    int m54;
};
void fn_80118770(UiObj* a);
void fn_8011A0A4(int a, UiObj* b, char* c);
extern char lbl_805BF240[];
extern char lbl_805BE5A4[];
Unk8001BC8C* fn_8001BC4C();
void fn_801006D4(UiV_20i_24i_28i_2Ci* self, int idx);
void fn_801015EC(void* self, UiObj* obj, int idx);

inline int UiIntAt(char* b, int i)
{
    int o = i * 4;
    return *(int*)(b + o);
}

extern int lbl_8061B3B8;
struct Ui2B4Obj : UiObj {
    char pad40[0x198 - 0x40];
    int m198;
};
struct UiScr2B4 : UiScr2A8 {
    char pad2B0[4];
    Ui2B4Obj* m2B4;
};
extern char lbl_805BF19C[];

extern char lbl_806592A0[];
extern char lbl_806597A0[];
extern char lbl_80659828[];
extern char lbl_80659908[];
extern char lbl_80659A60[];
extern "C" void fn_80356CE0(void*, int);
void fn_80356D14(void*, int);
void fn_80356D8C(void*, int);
struct UiDtor101278 {
    char pad0[0x3C];
    const char* m3C;
    char pad40[0x19C - 0x40];
    const char* m19C;
    char pad1A0[0x1E0 - 0x1A0];
    const char* m1E0;
    char pad1E4[0x1F0 - 0x1E4];
    const char* m1F0;
    char pad1F4[0x208 - 0x1F4];
    const char* m208;
    char pad20C[0x220 - 0x20C];
    const char* m220;
    char pad224[0x238 - 0x224];
    const char* m238;
    char pad23C[0x2A4 - 0x23C];
    const char* m2A4;
};

int fn_80101254(void* self)
{
    return fn_800B555C()->m570;
}

void fn_80101278(UiDtor101278* self, int chrg)
{
    self->m3C = lbl_806592A0;
    lbl_8061B3BC = 0;
    self->m2A4 = lbl_806597A0;
    self->m238 = lbl_80659A60;
    self->m220 = lbl_80659A60;
    self->m208 = lbl_80659A60;
    self->m1F0 = lbl_80659A60;
    self->m1E0 = lbl_80659A60;
    char* a = (char*)self + 0x1A0;
    *(const char**)(a + 0xC) = lbl_80659828;
    fn_80356CE0(a, 2);
    self->m19C = lbl_80659A60;
    char* b = (char*)self + 0x15C;
    *(const char**)(b + 0xC) = lbl_80659908;
    fn_80356CE0(b, 2);
    fn_80356D8C((char*)self + 0x148, 2);
    fn_80356D14((char*)self + 0x134, 2);
    fn_8035686C((UiScrRaw*)self, chrg);
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

void fn_801016A0(UiScr2A8* self)
{
    Ui8011AA24* g = fn_8011AA24(0);
    self->m2AC = 0;
    int pid = UiIntAt((char*)g->m6F8->m10 + 0x6C, self->m2AC);
    if (pid != fn_80101254(self))
        self->m2AC = 1;
    lbl_8061B3BC = 1;
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    for (int i = 0; i < 10; i++)
        self->m244[i]->w10(0);
    UiObj* o = (UiObj*)fn_800C8058(self->m2A8->v32((int)lbl_805BF19C, 1));
    ((UiSubAtDC*)((char*)o + 0xDC))->v15();
    if (fn_80101344((UiV_2ACi*)self) != 0) {
        fn_801015EC(self, o, 0);
        fn_801015EC(self, o, 1);
        fn_801015EC(self, o, 2);
        fn_801015EC(self, o, 3);
        fn_801015EC(self, o, 4);
        fn_801015EC(self, o, 5);
    } else {
        fn_801015EC(self, o, 1);
        fn_801015EC(self, o, 0);
        fn_801015EC(self, o, 2);
        fn_801015EC(self, o, 3);
        fn_801015EC(self, o, 4);
        fn_801015EC(self, o, 5);
        fn_801015EC(self, o, 6);
        fn_801015EC(self, o, 7);
        fn_801015EC(self, o, 8);
        fn_801015EC(self, o, 9);
    }
    fn_801006D4((UiV_20i_24i_28i_2Ci*)((char*)self + 0x270), self->m2AC);
    self->m26C = 10;
    self->m2A8->v37(0);
    fn_801018F4(self);
    fn_80101A64(self);
}

void fn_801018F4(UiScr2A8* self)
{
    if (self->m26C != 10)
        self->m244[self->m26C]->w10(0);
    self->m26C = ((UiSubAtDC*)((char*)fn_800C8058(self->m2A8->v32((int)lbl_805BF19C, 1)) + 0xDC))->v11();
    self->m244[self->m26C]->w3();
    self->m244[self->m26C]->w10(1);
    fn_80101A64(self);
}

void fn_801019F0(UiObj* self)
{
    if (lbl_8061B8C0->m24 == 0) {
        int r = fn_80101254(self);
        if (fn_802D7DB4(r, 0x78) != 0)
            self->v67(0, r);
    }
}

void fn_80101A64(UiScr2A8* x)
{
    UiScr2B4* self = (UiScr2B4*)x;
    int a, b;
    self->m244[self->m26C]->w7(&a, &b);
    if (b == 0) {
        self->m2B4->v8(0);
        self->m2B4->m198 = -1;
    } else {
        self->m2B4->v8(1);
        self->m2B4->m198 = -0x63;
        Ui6F8* p = fn_8011AA24(0)->m6F8;
        if (lbl_8061B3B8 != 0)
            fn_801268C4(self->m2B4, p, 5, 0, a, b, 0, 1, 0, 0, 1, 0, 0, 0, 1);
        else
            fn_801268C4(self->m2B4, p, a, b, 5, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1);
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

extern char lbl_805BEA94[];
extern char lbl_805BEA8C[];
void fn_801029E0(UiV_134_138* self)
{
    fn_800ECF18(self);
    self->m134 = fn_800C8044(self->v32((int)lbl_805BEA94, 1));
    self->m134->v8(0);
    fn_80102BD4(self, 0, self->m134);
    self->m138 = fn_800C8044(self->v32((int)lbl_805BEA8C, 1));
    fn_80102BD4(self, 1, self->m138);
    self->m138->v8(0);
    if (((Ui80619D10*)lbl_80619D10)->m444 == 10) {
        fn_80102B7C(self, 1);
        fn_80102B0C(self, 0);
        return;
    }
    fn_80102B7C(self, 0);
    fn_80102B0C(self, 1);
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

extern char lbl_805BE138[];
extern char lbl_805B955C[];
void fn_80102E70(UiObj* self, int a)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    switch (a) {
    case 0:
        fn_8040B830(p->name, lbl_805BE138, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
        return;
    case 1:
        fn_8040B830(p->name, lbl_805B955C, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
        return;
    }
}

extern char lbl_8065C238[];
UiScrRaw* fn_80102F5C(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8065C238;
    self->m130 = 0;
    return self;
}

void fn_80102FA8(UiObj* self)
{
    fn_800ECF18(self);
    Ui1CD0* base = fn_8011AA24(0)->m6F8->m14;
    int t = 0;
    if (base->m1CD0 != 0)
        t = 1;
    Ui1CD0* e = (Ui1CD0*)((char*)base + (t ^ 1) * 0xE64);
    UiObj* o = fn_800C8040(self->v32((int)lbl_805BF240, 1));
    switch (fn_800B555C()->m624) {
    case 0:
        o->v29(0x2607);
        break;
    case 1:
        o->v29(0x4061);
        break;
    case 2:
        o->v29(0x4062);
        break;
    }
    ((UiSubAt98*)((char*)fn_800C8054(self->v32((int)lbl_805BE5A4, 1)) + 0x98))->v20(e->m198, 0);
}

extern char lbl_80652B78[];
UiScrRaw* fn_801030F0(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80652B78;
    self->m130 = 0;
    return self;
}

void fn_8010313C(UiObj* self)
{
    fn_800ECF18(self);
    fn_800C3AB4(fn_800C33D0(), 2);
    Ui8011AA24* g = fn_8011AA24(0);
    int r = 0;
    int t = g->m6F8->m14->m1CD0;
    int v = t == 0;
    if (v <= 1) {
        if (v >= 0)
            r = fn_801A497C(g, v);
    }
    int flag = 1;
    int k = ((Ui80619D10*)lbl_80619D10)->m444;
    switch (k) {
    case 3:
        break;
    case 2:
        flag = 0;
        break;
    case 4:
        v = 0;
        break;
    case 5:
        v = 1;
        break;
    }
    if ((unsigned)(k - 4) <= 1)
        r = fn_801770E8(g->m700->m3A8, v);
    fn_8010325C(self, v, r, flag);
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

void fn_80103BA4(UiObj* self)
{
    fn_800ECF18(self);
    UiP54* p = (UiP54*)fn_8011AA24(0)->m6F8;
    UiQ1CC8* q = p->m14;
    UiObj* a = (UiObj*)fn_800C8060(self->v32((int)lbl_805BF3A8, 1));
    ((UiSubAtDC*)((char*)fn_800C8058(a->v73(1, 0)->v32((int)lbl_805BEAB8, 1)) + 0xDC))->v20(q->mFFC, 0);
    ((UiSubAtDC*)((char*)fn_800C8058(a->v73(2, 0)->v32((int)lbl_805BEAC0, 1)) + 0xDC))->v20(q->m198, 0);
    fn_80118770(a);
    int var;
    if (p->m54 != 0 && p->m14->m1CD0 != 0)
        var = p->m14->m1CC8;
    else
        var = p->m14->m1CC8 + 1;
    int k = 0x260;
    UiObj* c = fn_800C8044(self->v32((int)lbl_805BEA84, 1));
    fn_8011A0A4(var, c, lbl_805BEA84);
    if (var == 1)
        k = 0x3A63;
    fn_800C8040(c->v32((int)lbl_805BF3B4, 1))->v29(k);
}

void fn_80103DAC(Ui8010B1E0* a, int b, UiObj* c, int d)
{
    int t = fn_8025416C((char*)a + 0x588, 5);
    if (fn_80097288(b, a->m704) == 0 && t != 0 && t != 10) {
        fn_800C8040(c->v32(d, 1))->v30(fn_800E5F38(t));
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

void fn_80104544(UiObj* self, int a)
{
    Ui8011AA24* g = fn_8011AA24(0);
    UiObj* c = fn_800C8044(self->v32((int)lbl_805BF3D4, 1));
    c->v8(1);
    fn_800C8040(c->v32((int)lbl_805BE5B8, 1))->v29(0x196A);
    fn_8011A2F4(a, g, c, lbl_805BE3BC, 1);
    fn_800C8040(c->v32((int)lbl_805BE5C0, 1))->v29(0x196B);
    fn_8011A2AC(a, c, lbl_805BE5C8);
    fn_800C8040(c->v32((int)lbl_805BF458, 1))->v29(0x199E);
    fn_8011A3CC(a, c, lbl_805BF460);
    fn_800C8040(c->v32((int)lbl_805BF468, 1))->v29(0x1997);
    fn_8011A414(a, c, lbl_805BF470);
    fn_800C8040(c->v32((int)lbl_805BF478, 1))->v29(0x2012);
    fn_8011A468(a, c, lbl_805BF480);
    fn_800ED2B0((int)self, lbl_805BF488);
    fn_800CFB38();
}

/* near-miss: two arg moves swapped (retail: mr r3,r29 before mr r5,r27 before the sprintf-like call) */
void fn_80104798(short* out, int n, int strId, int flag)
{
    short buf[20];
    short tmp[12];
    int g = lbl_8061977C;
    buf[0] = 0;
    if (flag != 0)
        fn_800DFF0C(buf, (short*)fn_80090880(g, 0x19B5));
    if (n > 1) {
        short* fmt = (short*)fn_80090880(g, 0x19B3);
        fn_80403DE4(tmp, fmt, n, (short*)fn_80090880(g, strId));
        fn_800DFF0C(buf, tmp);
    } else
        fn_800DFF0C(buf, (short*)fn_80090880(g, strId));
    fn_800DFF0C(out, buf);
}

void fn_8010486C(int unused, int p, int a, int sel)
{
    int k = 0;
    switch (sel) {
    case 5:
        fn_80097620(p, 1, a, 0);
        return;
    case 0:
        k = 2;
        break;
    case 1:
        k = 3;
        break;
    case 2:
        k = 4;
        break;
    case 3:
        break;
    case 4:
        k = 1;
        break;
    case 6:
        k = 6;
        break;
    case 9:
        k = 5;
        break;
    case 10:
        k = 10;
        break;
    case 7:
        k = 8;
        break;
    case 8:
        k = 9;
        break;
    }
    fn_80097EA4(p, k, a, 2, 0);
}

void fn_80104BF8(UiObj* self, UiP70C* a1, UiEnt* a2, UiEnt* a3)
{
    int b = a1->m70C;
    int e = fn_8008CFD8(a2->mC9C, 9, a2->m17C) == 1;
    int f = !e;
    int s1 = fn_80099570(a3, 0, b, f);
    int s2 = fn_80099570(a3, 1, b, f);
    int s3 = fn_8008CFD8(a3->mC9C, 0xD, b);
    UiObj* c = fn_800C8044(self->v32((int)lbl_805BF3C4, 1));
    c->v8(1);
    UiObj* d = fn_800C8040(c->v32((int)lbl_805BE5B8, 1));
    d->v29(!f ? 0x2443 : 0x2442);
    fn_8011A0A4(s1, c, lbl_805BE3BC);
    d = fn_800C8040(c->v32((int)lbl_805BE5C0, 1));
    d->v29(!f ? 0x2445 : 0x2444);
    fn_8011A0A4(s2, c, lbl_805BE5C8);
    fn_800C8040(c->v32((int)lbl_805BF458, 1))->v29(0x2457);
    fn_8011A0A4(s3, c, lbl_805BF460);
    fn_800ED2B0((int)self, lbl_805BF564);
    fn_800CFB38();
}
