/*
 * Game code, .text 0x80104E24-0x80107F74 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


extern char lbl_806520D8[];
UiScrRaw* fn_80104EC0(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_806520D8;
    self->m130 = 0;
    return self;
}

void fn_80104F0C(UiObj* self)
{
    fn_800ECF18(self);
}

void fn_80104F2C(UiObj* self)
{
    fn_800EC84C();
    self->v8(0);
}

extern char lbl_80651E30[];
UiScrRaw* fn_80104F74(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80651E30;
    self->m130 = 0;
    return self;
}

void fn_80104FC0(UiObj* self)
{
    fn_800ECF18(self);
    Ui1CD0* g = fn_8011AA24(0)->m6F8->m14;
    int b = 0;
    if (g->m1CD0 != 0)
        b = 1;
    int idx = b ^ 1;
    fn_80105048(self, idx, (char*)g + idx * 0xE64);
    int t = fn_800B5520(g->mFFC);
    fn_801051D0(self, t, fn_800B5520(g->m198));
}

extern char lbl_8064F620[];
UiScrRaw* fn_80105344(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064F620;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m144 = 0;
    self->m148 = 0;
    return self;
}

void fn_80105974()
{
    int i = fn_800B555C()->m570;
    if (i == -1) {
        fn_800B555C()->m570 = 0;
        for (i = 0; i <= 3; i++) {
            if (fn_802D7DB4(i, 5) != 0) {
                fn_800B555C()->m570 = i;
                break;
            }
        }
    }
}

int fn_801059E4()
{
    int r = 0;
    Ui6F8* g = fn_8011AA24(0)->m6F8;
    if (fn_800B555C()->m570 == g->m10->m70)
        r = 1;
    else
        fn_800B555C();
    return r;
}

void fn_80105A40(UiV_144i* self)
{
    if (self->m144 == 1) {
        if (fn_80105AB8() == 1) {
            fn_80105AE8(self, 0x39E1, 0);
            return;
        }
        fn_80105AE8(self, 0x39E2, 2);
        return;
    }
    fn_80105AE8(self, 0x39D6, 0);
}

int fn_80105AB8()
{
    switch (lbl_8068B618->m8->m564->m14) {
    case 6:
    case 7:
        return 0;
    }
    return 1;
}

void fn_80105C58(int a, int b)
{
    switch (a) {
    case 0:
        fn_80105CA4(b);
        break;
    case 1:
        fn_80105CA8(b);
        break;
    }
}

void fn_80105C9C()
{
}

void fn_80105CA0()
{
}

void fn_80105CA4(int a)
{
}

extern char lbl_805BF5E0[];
extern char lbl_805BF5F0[];
char* fn_80105E94(UiV_140* self)
{
    char* s = self->m140->v70()->v33(5, 1)->name;
    if (fn_8040B3B4(s, lbl_805BF5E0) == 0)
        s = lbl_805BF5F0;
    return s;
}

int fn_8010607C(UiV_140i* self, int a)
{
    if (a == self->m140) {
        self->v67(1, fn_800C8070(self));
        return 1;
    }
    return 0;
}

int fn_801060EC(UiObj* self, int a)
{
    return fn_800B555C()->m570 == a;
}

int fn_80106128(UiScr140* self, int a)
{
    if (fn_801060EC(self, a))
        self->m140->v50();
    return 1;
}

int fn_8010617C(UiScr140* self, int a)
{
    if (fn_801060EC(self, a))
        self->m140->v51();
    return 1;
}

int fn_801061D0(UiScr140* self, int a)
{
    if (fn_801060EC(self, a))
        self->m140->v52();
    return 1;
}

int fn_80106224(UiScr140* self, int a)
{
    if (fn_801060EC(self, a))
        self->m140->v53();
    return 1;
}

extern char lbl_8065BF08[];
UiScrRaw* fn_80106278(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8065BF08;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m140 = 0;
    return self;
}

void fn_80106580()
{
    fn_8017E264(fn_8011AA24(0)->m700);
}

extern char lbl_805BE138[];
void fn_80106690(int a, UiObj* b)
{
    if (a == 1) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805BE138, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, b);
    }
}

int fn_8010671C()
{
    return 0;
}

int fn_80106724(UiV_13C_140i* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        if (self->m140 != 0) {
            fn_80131F34(self->m13C, self, fn_80106690, fn_8010671C, 0x3364, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
            self->m13C->v86();
        } else
            fn_80106690(1, self);
    }
    return 1;
}

extern char lbl_805B955C[];
int fn_801067EC(UiObj* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        fn_80106890(self);
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805B955C, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
    return 1;
}

void fn_80106FB4(UiV_134* self, int a)
{
    fn_800ED310(self);
    self->m134->v14(a);
}

void fn_80107004(UiV_140i* self)
{
    self->m140 = 1;
}

int fn_80107010(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v50();
    return 1;
}

int fn_8010706C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v51();
    return 1;
}

int fn_801070C8(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v52();
    return 1;
}

int fn_80107124(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v53();
    return 1;
}

int fn_80107180(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v56();
    return 1;
}

int fn_801071DC(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v57();
    return 1;
}

int fn_80107238(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v54();
    return 1;
}

int fn_80107294(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v55();
    return 1;
}

int fn_8010750C(UiScr8010750C* self, int a)
{
    if (fn_800B555C()->m570 == a || self->m14C != 0)
        fn_80108070(self, ((unsigned)self->m1AC->m24 >> 31) ^ 1);
    return 1;
}

void fn_80107570(void* self, char* out)
{
    *out = 0;
}

void fn_80107BDC(UiV_14Ci_158i_15Ci_160i_164i_168i_16Ci_170i_174i_178i_17Ci_180i_184i_188i_18Ci_19Ci* self)
{
    if (self->m14C != 0) {
        int z = 0;
        lbl_8061EE14 = z;
    }
    fn_800ED254(self);
    lbl_8061B8C0->m24 = 1;
    fn_802D7ADC();
    fn_801A750C(self->m19C, 0);
    fn_802D7A64();
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m16C = 0;
    self->m170 = 0;
    self->m174 = 0;
    self->m178 = 0;
    self->m17C = 0;
    self->m180 = 0;
    self->m184 = 0;
    self->m188 = 0;
    self->m18C = 0;
}

void fn_80107C84(UiV_150i* self)
{
    self->m150 += 1;
}

void fn_80107DB0(UiObj* self)
{
    fn_80107C94(self);
}

int fn_80107F3C(UiV_148i* self)
{
    if (self->m148 == 0)
        return fn_800ED00C(self);
    return 0;
}
