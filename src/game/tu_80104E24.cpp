/*
 * Game code, .text 0x80104E24-0x80107F74 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"
extern char lbl_805BF58C[];
extern char lbl_805BE37C[];
extern char lbl_805BF5B8[];
extern char lbl_805BF544[];
extern char lbl_805BF5C0[];
char* fn_801A49F0(Ui8011AA24* g, int a, int v);
int fn_80097190(char* t, int i);
int fn_80097300(char* t, int x);
void fn_8011A268(char* r, UiObj* c, char* s);
void fn_8011A2F4(char* r, Ui8011AA24* g, UiObj* c, char* s, int f);
extern "C" void* fn_800C8058(int);
struct Ui106890 : UiObj {
    char pad40[0x134 - 0x40];
    UiObj* m134;
    char pad138[0x148 - 0x138];
    int a148[1];
};
void fn_80087A58(Ui6F8_10* o, int pid, int y, int z, int w);
void fn_80118770(UiObj* a);
extern char lbl_805BF3A8[];
extern char lbl_805BF5CC[];
int fn_800E1968(int a);
struct Ui105AE8 : UiObj {
    char pad40[0x138 - 0x40];
    Ui2F0Obj* m138;
};
int fn_80147C8C();
void fn_80105C58(int a, int b);
void fn_80105C9C();
void fn_80105CA0();
struct Ui19C {
    char pad0[0x38];
    int m38;
};
struct UiB1C {
    char pad0[0x1C];
    int m1C;
};
struct Ui107DD0 : UiObj {
    char pad40[0x144 - 0x40];
    int m144;
    char pad148[0x158 - 0x148];
    UiB1C* m158;
    UiB1C* m15C;
    UiB1C* m160;
    UiB1C* m164;
    UiB1C* m168;
    UiB1C* m16C;
    UiB1C* m170;
    char pad174[0x184 - 0x174];
    UiB1C* m184;
    UiB1C* m188;
    UiB1C* m18C;
    UiB1C* m190;
    int m194;
    char pad198[0x19C - 0x198];
    Ui19C* m19C;
    char pad1A0[0x1AC - 0x1A0];
    UiObj* m1AC;
};
int fn_800C8048(UiB1C* a);
struct Ui107A4 : UiObj {
    char pad40[0x148 - 0x40];
    int m148;
    int m14C;
};
extern int lbl_80620298;
extern char lbl_805BA6D8[];
extern char lbl_805BADC8[];
void fn_8010817C(int a, UiObj* b);
struct Ui107C94 : UiObj {
    char pad40[0x190 - 0x40];
    int m190;
    char pad194[0x19C - 0x194];
    Ui19C* m19C;
    UiObj* m1A0;
    UiObj* m1A4;
    UiObj* m1A8;
    UiObj* m1AC;
};
extern char lbl_805BAFF0[];
void fn_8040321C(short* a, int b, int c, int d);


extern char lbl_805B955C[];

void fn_80104E24(UiV_138q* self)
{
    fn_800ECAA4(self);
    int* p = self->m138;
    if (p != 0) {
        int v = *p;
        if (v == 0) {
            UiMsg m;
            UiMsg* q = &m;
            fn_8035682C(q);
            fn_8040B830(q->name, lbl_805B955C, 15);
            q->name[15] = 0;
            fn_800B7B4C(UiGetMsgMgr(), q, self);
        }
    }
}

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

void fn_80105048(UiObj* self, int a, Ui1CD0* t)
{
    int i = 0;
    Ui8011AA24* g = fn_8011AA24(0);
    UiObj* c = fn_800C8044(self->v32((int)lbl_805BF58C, 1));
    ((UiSubAt98*)((char*)fn_800C8054(self->v32((int)lbl_805BE37C, 1)) + 0x98))->v20(t->m198, 0);
    /* addresses of the strings lbl_805BF594 / lbl_805BF59C / lbl_805BF5A4, as literals (a pointer table's relocations are not followed by check_literals) */
    int tbl[3] = { 0x805BF594, 0x805BF59C, 0x805BF5A4 };
    do {
        UiObj* d = fn_800C8044(c->v32(tbl[i], 1));
        char* r = fn_801A49F0(g, a, fn_80097300((char*)t, fn_80097190((char*)t, i)));
        i++;
        fn_8011A14C(r, d, lbl_805BF5B8, 0);
        fn_8011A268(r, d, lbl_805BF544);
        fn_8011A2F4(r, g, d, lbl_805BF5C0, 1);
    } while (i <= 2);
}

void fn_801051D0(UiObj* self, int a, int b)
{
    int ra = fn_800E1968(a);
    int rb = fn_800E1968(b);
    UiObj* h = (UiObj*)fn_800C8060(self->v32((int)lbl_805BF3A8, 1));
    int g = lbl_8061977C;
    fn_800C8040(h->v73(1, 0)->v32((int)lbl_805BF5CC, 1))->v28((char*)fn_80090880(g, ra));
    fn_800C8040(h->v73(2, 0)->v32((int)lbl_805BF5CC, 1))->v28((char*)fn_80090880(g, rb));
    fn_80118770(h);
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

void fn_80105AE8(Ui105AE8* self, int a, int mode)
{
    switch (mode) {
    case 0:
        fn_80131F34(self->m138, self, (void (*)(int, UiObj*))fn_80105C58, fn_80147C8C, a, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
        break;
    case 1:
        fn_80131F34(self->m138, self, (void (*)(int, UiObj*))fn_80105C9C, fn_80147C8C, a, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
        break;
    case 2:
        fn_80131F34(self->m138, self, (void (*)(int, UiObj*))fn_80105CA0, fn_80147C8C, a, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
        break;
    }
    self->m138->m2F0 = -0x63;
    fn_800C80C0(self->m138, fn_800B555C()->m570);
    self->m138->v86();
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

void fn_80106890(Ui106890* self)
{
    for (int i = 0; i < self->m134->v59(); i++) {
        int y = (int)((UiObj*)fn_800C8058((int)self->m134->v73(i, 0)->v33(10, 1)))->v58() + 0x32;
        int z = fn_801059E4();
        int pid = self->a148[i];
        switch (fn_8011AA4C()) {
        case 1:
        case 2:
            fn_80087A58(fn_8011AA24(0)->m6F8->m10, pid, y, z, 0);
            fn_80087A58(fn_8011AA24(1)->m6F8->m10, pid, y, z, 0);
            break;
        case 0:
        case 3:
        case 6:
            fn_80087A58(fn_8011AA24(0)->m6F8->m10, pid, y, z, 0);
            break;
        }
    }
}

void fn_80106EAC(UiV_144i* self)
{
    if (fn_8011AA4C() == 0) {
        int tbl[6] = { 0xC82, 0xC83, 0xC84, 0xC85, 0x5AA, 0xC82 };
        int g = lbl_8061977C;
        short buf[100];
        fn_8040321C(buf, fn_80090880(g, 0x5AB), fn_80090880(g, 0x577), fn_80090880(g, tbl[self->m144]));
        fn_800C8040(self->v32((int)lbl_805BAFF0, 1))->v28((char*)buf);
    }
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

extern char lbl_8065B3E8[];
Ui72F0* fn_801072F0(Ui72F0* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8065B3E8;
    self->m130 = 0;
    self->m134 = 1.0f;
    self->m140 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m194 = 0;
    self->m198 = 0;
    self->m19C = 0;
    self->m1A4 = 0;
    self->m1AC = 0;
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
    return self;
}

int fn_801073A4(Ui107A4* self, int a)
{
    if (fn_800B555C()->m570 == a || self->m14C != 0) {
        if (self->m148 == 0) {
            if (self->m14C != 0) {
                lbl_80620298 = 0;
                int one = 1;
                lbl_8061EE14 = one;
                UiObj* o = fn_800B7AB8(UiGetMsgMgr(), lbl_805BA6D8);
                fn_80131F34(o, self, fn_8010817C, 0, 0x3913, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
                o->v86();
            } else {
                UiMsg m;
                UiMsg* p = &m;
                fn_8035682C(p);
                fn_8040B830(p->name, lbl_805BADC8, 15);
                p->name[15] = 0;
                fn_800B7B4C(UiGetMsgMgr(), p, self);
            }
        }
    }
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

void fn_80107C94(Ui107C94* self)
{
    int v = self->m19C->m38;
    ((UiSubAtDC*)((char*)self->m1A0 + 0xDC))->v6(v);
    self->m190 = 0;
    if (v == 0) {
        self->m1A4->v16(1);
        self->m1A8->v8(0);
    } else {
        self->m1A4->v16(0);
        if (self->m1AC->m24 < 0)
            self->m1A8->v8(1);
        else
            self->m1A8->v8(0);
    }
}

void fn_80107DB0(UiObj* self)
{
    fn_80107C94(self);
}

int fn_80107DD0(Ui107DD0* self, UiB1C* it)
{
    int flag = 0;
    UiObj* cur = self->m1AC;
    if (cur->m24 < 0) {
        if (it == (UiB1C*)cur)
            goto set144;
        if (it->m1C == 1) {
            if (self->m19C->m38 == 0 || it == self->m15C || it == self->m158 || it == self->m160 || it == self->m164
                || it == self->m168 || it == self->m16C)
                flag = 1;
            if (it == self->m170) {
                fn_80108070(self, 0);
                flag = 1;
            } else if (it == self->m184) {
                flag = 1;
                self->v45(fn_800B555C()->m570);
            }
        } else if (it == self->m18C || it == self->m188) {
            flag = 1;
        }
    } else if (it->m1C == 5 && fn_800C8048(it) == self->m194) {
        fn_80108070(self, 1);
    set144:
        self->m144 = 1;
    }
    if (flag != 0)
        self->m190 = it;
    return 0;
}

int fn_80107F3C(UiV_148i* self)
{
    if (self->m148 == 0)
        return fn_800ED00C(self);
    return 0;
}
