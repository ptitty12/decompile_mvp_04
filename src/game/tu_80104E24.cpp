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

int fn_8010671C()
{
    return 0;
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

void fn_80107570(void* self, char* out)
{
    *out = 0;
}

void fn_80107C84(UiV_150i* self)
{
    self->m150 += 1;
}

void fn_80107DB0(UiObj* self)
{
    fn_80107C94(self);
}
