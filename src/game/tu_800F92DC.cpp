/*
 * Game code, .text 0x800F92DC-0x800FD438 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"

struct UiOwner3E0 {
    char pad0[0x3E0];
    int m3E0;
};
inline int UiIntAt(char* b, int i)
{
    int o = i * 4;
    return *(int*)(b + o);
}
struct UiG65C {
    char pad0[0x65C];
    int m65C;
};
struct UiScr138_1AC_1E4 : UiObj {
    char pad40[0x138 - 0x40];
    int m138;
    char pad13C[0x1AC - 0x13C];
    int m1AC;
    char pad1B0[0x1E4 - 0x1B0];
    UiObj* m1E4;
};
struct Unk8017A930_T;
struct UiAA24x {
    char pad0[0x720];
    struct UiAA24y* m720;
};
struct UiAA24y {
    char pad0[0xD0];
    int mD0;
};
struct UiScrFB : UiBase {
    const void* m3C;
    char pad40[0x130 - 0x40];
    int m130;
    int m134;
    int m138;
    int m13C;
    float m140;
    char pad144[4];
    char m148[0x84];
    int m1CC;
    int m1D0;
    int m1D4;
    int m1D8;
    int m1DC;
    int m1E0;
    int m1E4;
    int a1E8[2];
    int a1F0[2];
    int a1F8[2];
    int a200[2];
    int a208[2];
    int a210[2];
    int a218[2];
    int a220[2];
    int a228[2];
    int m230;
    int m234;
    int m238;
    int m23C;
    int m240;
    int m244;
    int m248;
    int a24C[4];
    int m25C;
    int m260;
    char pad264[4];
    int m268;
    int m26C;
};

int fn_8017C8C8(Unk8017A930_T* a);
class UiSub98 {
    char pad0[0x24];
public:
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
};


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

extern char lbl_805BA6D0[];
void fn_800F94AC(UiObj* self)
{
    fn_800ECF18(self);
    if (lbl_806192E0->m4->m10->m120 == 1) {
        self->v8(0);
        self->v67(0, fn_800B555C()->m570);
        return;
    }
    fn_802DC9C0();
    UiObj* o = fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D0);
    fn_80124FA8(o, self);
    fn_801251CC(o, 0, 0x1A0A, 0);
    fn_800C80C0(o, fn_800B555C()->m570);
    fn_800C80C0(self, fn_800B555C()->m570);
    switch (fn_8011AA4C()) {
    case 5:
        fn_800F96E0(self);
        return;
    case 6:
        fn_800F988C(self);
        return;
    }
}

extern char lbl_805B97B4[];
extern char lbl_805BE6BC[];
void fn_800F95E4(UiObj* self, int a, int b)
{
    if (fn_800F9B70(self, b) != 0 && a == 0) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        if (UiGetMsgMgr()->mBC != 0 || fn_800B57EC(fn_800B555C()) != 0) {
            fn_8040B830(p->name, lbl_805B97B4, 15);
            p->name[15] = 0;
        } else {
            fn_8040B830(p->name, lbl_805BE6BC, 15);
            p->name[15] = 0;
        }
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
    }
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

extern char lbl_80658FB0[];
extern int lbl_80619D10;
extern float lbl_805BE70C;
UiScrFB* fn_800F9D0C(UiScrFB* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648((UiScrA70C*)self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m1CC = 0;
    self->m1D0 = 0;
    self->m1D4 = 0;
    self->m3C = lbl_80658FB0;
    self->m140 = lbl_805BE70C;
    self->m1D8 = 0;
    self->m1DC = 0;
    self->m1E0 = 0;
    self->m1E4 = 0;
    self->m230 = 0;
    self->m234 = 0;
    self->m238 = 0;
    self->m23C = 0;
    self->m240 = 0;
    self->m244 = 0;
    self->m13C = 0xC7;
    self->m248 = 0;
    self->m25C = 0;
    self->m260 = 0;
    fn_803FFC58(self->m148, 0, 0x84);
    for (int i = 0; i < 2; i++) {
        self->a1E8[i] = 0;
        self->a1F0[i] = 0;
        self->a1F8[i] = 0;
        self->a200[i] = 0;
        self->a208[i] = 0;
        self->a210[i] = 0;
        self->a218[i] = 0;
        self->a220[i] = 0;
        self->a228[i] = 0;
    }
    for (int i = 0; i < 4; i++)
        self->a24C[i] = 0;
    self->m268 = 0;
    self->m26C = 0;
    return self;
}

void fn_800F9E4C(UiScrRaw* self, int a)
{
    self->m3C = lbl_80658FB0;
    fn_800AB6B8(lbl_80619D10);
    fn_8035686C(self, a);
}

extern char lbl_805BEC18[];
extern char lbl_805BEC28[];
extern char lbl_805BEC38[];
void fn_800FAF38(UiV_138i_13Ci* self, char* out)
{
    if (self->m138 != 0) {
        self->m138 = 0;
        lbl_8061B8C0->m24 = 1;
        fn_802D7ADC();
        fn_8040B830(out, lbl_805BEC18, 16);
    } else {
        switch (self->m13C) {
        case 0xC7:
            *out = 0;
            break;
        case 0x36:
            fn_8040B830(out, lbl_805BEC28, 16);
            break;
        case 0xA0:
            fn_8011AA24(0);
            if (UiGetMsgMgr()->mBC == 0)
                fn_8040B830(out, lbl_805BEC38, 16);
            break;
        }
    }
}

extern char lbl_805BEAE0[];
void fn_800FB02C(UiObj* self)
{
    fn_802D7ACC();
    fn_800C8044(self->v32((int)lbl_805BEAE0, 1))->v8((lbl_806192E0->m4->m10->m120 ^ 1) == 0);
    fn_800B555C()->m570 = -1;
    fn_802D8294(1);
    fn_802D7A74();
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
}

void fn_800FB0E4(UiScrFB* self)
{
    fn_800ED254((UiObj*)self);
    self->m13C = 0xC7;
    fn_803FFC58(self->m148, 0, 0x84);
    self->m1D8 = 0;
    self->m1D4 = 0;
    self->m1D0 = 0;
    self->m1CC = 0;
    for (int i = 0; i < 2; i++) {
        self->a1E8[i] = 0;
        self->a1F0[i] = 0;
        self->a1F8[i] = 0;
        self->a200[i] = 0;
        self->a208[i] = 0;
        self->a210[i] = 0;
        self->a218[i] = 0;
        self->a220[i] = 0;
        self->a228[i] = 0;
    }
    self->m230 = 0;
    self->m1E0 = 0;
    self->m1E4 = 0;
    self->m234 = 0;
    self->m238 = 0;
    self->m23C = 0;
    self->m240 = 0;
    for (int i = 0; i < 4; i++)
        self->a24C[i] = 0;
    fn_802D8294(2);
    fn_802D7A64();
    fn_802D7ADC();
    ((UiAA24x*)fn_8011AA24(0))->m720->mD0 = 5;
}

int fn_800FB200(UiScr138_1AC_1E4* self, int a)
{
    Ui6F8_10* t = fn_8011AA24(0)->m6F8->m10;
    int ok;
    if (((UiG65C*)fn_8011AA24(0))->m65C == 0)
        ok = 0;
    else
        ok = 1;
    if (ok != 0) {
        if (self->m1E4->m24 < 0)
            return 1;
        if (fn_800C8044(self->m1AC)->m24 >= 0) {
            fn_800B555C()->m570 = a;
            int hit = 0;
            if (a == t->m70 || a == ((int*)t)[0x6C / 4])
                hit = 1;
            if (hit != 0) {
                if (fn_8017C8C8((Unk8017A930_T*)fn_8011AA24(0)->m700) == 0)
                    fn_800B7ADC(UiGetMsgMgr(), self);
            } else {
                self->m138 = 1;
                fn_800B7ADC(UiGetMsgMgr(), self);
            }
        }
    }
    return 1;
}

int fn_800FB83C(int a, int b, UiObj* p, float f)
{
    if (p != 0) {
        if (!(f <= 0.75f)) {
            ((UiSub98*)((char*)p + 0x98))->q6();
            p->v8(1);
            return 1;
        }
        p->v8(0);
    }
    return 0;
}

int fn_800FC084()
{
    return 1;
}

void fn_800FC08C(UiV_13Ci* self, int id, int* msg)
{
    if (id == 0x93) {
        int* p;
        if (msg != 0) {
            p = 0;
            if (id == *msg)
                p = msg;
        } else
            p = 0;
        fn_800FCB38(self, p);
        return;
    }
    if (id == 0x94) {
        int* p;
        if (msg != 0) {
            p = 0;
            if (id == *msg)
                p = msg;
        } else
            p = 0;
        fn_800FCD0C(self, p);
        return;
    }
    self->m13C = id;
    fn_800B7ADC(UiGetMsgMgr(), self);
}

void fn_800FC160(UiV_1E8i_1ECi_1F0i_1F4i_1F8i_1FCi_200i_204i_208i_20Ci_210i_214i_218i_21Ci_220i_224i_228i_22Ci* self)
{
    if (fn_8011B4E4() != 0) {
        fn_801184F4(self->m1E8, self->m1F0, self->m1F8, self->m200, self->m208, self->m210, self->m218, 0, 0);
        return;
    }
    fn_801184F4(self->m1EC, self->m1F4, self->m1FC, self->m204, self->m20C, self->m214, self->m21C, self->m224, self->m22C);
}

extern char lbl_805B9A9C[];
extern char lbl_805B9AA4[];
extern char lbl_805B9ACC[];
void fn_800FC6B4(UiV_25Ci_260i* self)
{
    fn_800C8044(self->v32((int)lbl_805B9A9C, 1))->v8(0);
    self->m25C = 0;
    fn_800C8044(self->v32((int)lbl_805B9AA4, 1))->v8(0);
    fn_800C8044(self->v32((int)lbl_805B9ACC, 1))->v8(0);
    self->m260 = 0;
}

UiObj* fn_800FC7B4(UiV_158i_15Ci_160i_164i_168i* self, int idx)
{
    switch (idx) {
    case 0:
        return fn_800C8044(self->m158);
    case 1:
        return fn_800C8044(self->m15C);
    case 2:
        return fn_800C8044(self->m160);
    case 3:
        return fn_800C8044(self->m164);
    case 4:
        return fn_800C8044(self->m168);
    default:
        return 0;
    }
}

UiObj* fn_800FC844(UiV_170i_174i_178i_17Ci_180i* self, int idx)
{
    switch (idx) {
    case 0:
        return fn_800C8054(self->m170);
    case 1:
        return fn_800C8054(self->m174);
    case 2:
        return fn_800C8054(self->m178);
    case 3:
        return fn_800C8054(self->m17C);
    case 4:
        return fn_800C8054(self->m180);
    default:
        return 0;
    }
}

UiObj* fn_800FC8D4(UiV_184i_188i_18Ci_190i_194i* self, int idx)
{
    switch (idx) {
    case 0:
        return fn_800C8038(self->m184);
    case 1:
        return fn_800C8038(self->m188);
    case 2:
        return fn_800C8038(self->m18C);
    case 3:
        return fn_800C8038(self->m190);
    case 4:
        return fn_800C8038(self->m194);
    default:
        return 0;
    }
}

void fn_800FC964(UiV_1A0i_1A4i* self, int a)
{
    if (fn_8011B4E4() != 0) {
        fn_800C8044(self->m1A4)->v8(0);
        fn_800C8044(self->m1A0)->v8(a);
        return;
    }
    fn_800C8044(self->m1A4)->v8(a);
    fn_800C8044(self->m1A0)->v8(0);
}

void fn_800FCA30(UiV_1E0b* self)
{
    self->m1E0->v8();
}

void fn_800FCA68(UiV_1E4b* self)
{
    self->m1E4->v8();
}

void fn_800FCAA0(UiV_1E4* self)
{
    Ui8011AA24* g = fn_8011AA24(0);
    int z = 0;
    int ok = self->m1E4->m24 >= z;
    int k = ((UiOwner3E0*)g->m700)->m3E0;
    if (ok) {
        if (UiIntAt((char*)fn_8011AA24(0)->m6F8->m10 + 0x6C, k) == -1)
            return;
    }
    self->m1E4->v8(ok);
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
