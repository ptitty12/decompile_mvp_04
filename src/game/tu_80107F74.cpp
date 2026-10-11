/*
 * Game code, .text 0x80107F74-0x8010A0A4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


void fn_80107F74(UiArr158* self, int i, int a)
{
    fn_800C8034(self->m158[i])->v15(a);
}

void fn_80107FC8(UiV_158_15C* self, int a)
{
    self->m158->v8(a ^ 1);
    self->m15C->v8(a);
}

extern int lbl_8061A330;
void fn_80108034(UiV_134f_198i* self, float f)
{
    fn_800DC50C(self->m198, self->m134, f);
    lbl_8061A330 = 1;
}

extern char lbl_805BA240[];
void fn_8010817C(int a, UiObj* b)
{
    int one = 1;
    lbl_80620298 = one;
    if (a == one) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805BA240, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, b);
    }
}

extern char lbl_8064F0D0[];
UiScrRaw* fn_80108214(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064F0D0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

void fn_8010838C(UiObj* self)
{
    fn_800ED254(self);
}

int fn_8010846C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v50();
    return 1;
}

int fn_801084C8(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v51();
    return 1;
}

int fn_80108524(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v52();
    return 1;
}

int fn_80108580(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v53();
    return 1;
}

int fn_801085DC(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v54();
    return 1;
}

int fn_80108638(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v55();
    return 1;
}

int fn_80108694(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v56();
    return 1;
}

int fn_801086F0(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v57();
    return 1;
}

int fn_8010874C(UiV_134i* self, int a, int b, int c)
{
    if (a == self->m134) {
        fn_80108958(self, c);
        return 1;
    }
    return 0;
}

void fn_8010878C(UiV_134* self, char* out)
{
    UiObj* o = self->m134->v70();
    fn_8040B830(out, o->v33(5, 1)->name, 16);
}

void fn_80108958(UiObj* a, int b)
{
    switch (b) {
    case 1:
        break;
    case 2:
        fn_801089E4(a, 0);
        break;
    case 3:
        fn_801089E4(a, 1);
        break;
    }
    fn_800B7ADC(UiGetMsgMgr(), a);
}

void fn_801089E4(UiObj* self, int a)
{
    int v = fn_801059E4();
    if (a == 1)
        v = v == 0;
    Ui8011AA24* o = fn_8011AA24(0);
    o->m788 = v;
    fn_801A3704(o, 1);
}

extern char lbl_8064EE28[];
UiScrRaw* fn_80108A38(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064EE28;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

void fn_80108DB0(int a, UiObj* obj)
{
    obj->v67(2, fn_800B555C()->m570);
}

void fn_80108E04(UiObj* self)
{
    fn_800ED254(self);
}

int fn_80108EE4(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v50();
    return 1;
}

int fn_80108F40(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v51();
    return 1;
}

int fn_80108F9C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v52();
    return 1;
}

int fn_80108FF8(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v53();
    return 1;
}

int fn_80109054(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v54();
    return 1;
}

int fn_801090B0(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v55();
    return 1;
}

int fn_8010910C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v56();
    return 1;
}

int fn_80109168(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v57();
    return 1;
}

int fn_801092A0(UiV_134i* self, int a, int b, int c)
{
    if (a == self->m134) {
        fn_801094AC(self, c);
        return 1;
    }
    return 0;
}

void fn_801092E0(UiV_134* self, char* out)
{
    UiObj* o = self->m134->v70();
    fn_8040B830(out, o->v33(5, 1)->name, 16);
}

void fn_801094AC(UiObj* a, int b)
{
    if (b <= 3) {
        if (b >= 0)
            fn_800B7ADC(UiGetMsgMgr(), a);
    }
}

extern char lbl_8064EB80[];
extern char lbl_805B6F58[];
UiScrRaw* fn_80109514(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064EB80;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = (int)lbl_805B6F58;
    return self;
}

void fn_80109640(UiObj* self)
{
    fn_800ED254(self);
}

int fn_801097B8(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v50();
    return 1;
}

int fn_80109814(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v51();
    return 1;
}

int fn_80109870(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v52();
    return 1;
}

int fn_801098CC(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v53();
    return 1;
}

int fn_80109928(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v54();
    return 1;
}

int fn_80109984(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v55();
    return 1;
}

int fn_801099E0(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v56();
    return 1;
}

int fn_80109A3C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v57();
    return 1;
}

int fn_80109BDC(UiV_134i* self, int a, int b, int c)
{
    if (a == self->m134) {
        fn_80109E0C(self, c);
        return 1;
    }
    return 0;
}

void fn_80109C1C(UiV_134* self, char* out)
{
    UiObj* o = self->m134->v70();
    fn_8040B830(out, o->v33(5, 1)->name, 16);
}

int fn_80109F50()
{
    return 0;
}
