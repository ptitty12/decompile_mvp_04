/*
 * Game code, .text 0x800E8890-0x800EBF2C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800E8890.h"

void fn_800E8BCC(UiS* self)
{
    fn_800EC1E8(self);
    self->p2E0 = fn_800B7AB8(UiGetMsgMgr(), lbl_805BA6D8);
    self->m308 = 0;
    self->m304 = 0;
}

void fn_800E9248(int a, UiS* x)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    switch (a) {
    case 0:
        fn_800A2F9C(lbl_80619948, 1);
        x->v114(x->m2E4);
        break;
    case 1: {
        Unk8007B2B0_Screen* s = lbl_8061930C;
        const char* nm;
        if (((Unk8007A4DC_Screen*)s)->fn_8007A270(fn_800A3244(lbl_80619948)) != 0)
            nm = lbl_805BE0F0;
        else
            nm = lbl_805BE100;
        fn_8040B830(p->name, nm, 15);
        p->name[15] = 0;
        char* t = (char*)fn_800B555C() + 8;
        Unk8007B2B0_Screen* s2 = lbl_8061930C;
        fn_800C2034(t, s2->fn_80078A38(fn_80077BC4(s2, fn_800A3244(lbl_80619948))));
        lbl_80619948->m74 = 0;
        lbl_80619948->m80 = 0;
        lbl_80619948->mA4 = 0;
        x->v80(1);
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    }
    }
}

void fn_800E98D8(int a, UiS* x)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    switch (a) {
    case 0:
        fn_800A2F9C(lbl_80619948, 1);
        x->v114(x->m2E4);
        break;
    case 1:
        x->v80(1);
        char* t = (char*)fn_800B555C() + 8;
        Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
        fn_800C2034(t, s->fn_80078A38(fn_800A3258(lbl_80619948)));
        lbl_80619948->m74 = 0;
        lbl_80619948->m80 = 0;
        lbl_80619948->mA4 = 0;
        fn_8040B830(p->name, lbl_805BE110, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    }
}

void fn_800E9A04(UiS* self, int a)
{
    int flag = self->m2DC != 0;
    UiS* p = self->p2E0;
    int id = (int)fn_80090880(lbl_8061977C, 0x26DE);
    fn_801321D4(p, self, fn_800EAD8C, 0, a, 1, -1, 1, id, 0, 0, 0, flag, 0);
    self->p2E0->v86();
}

void fn_800E9AB8(UiS* self)
{
    if (self->m2DC == 0) {
        fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAD8C, 0, 0x11CA, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
        self->p2E0->v86();
    } else {
        fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAE04, 0, 0x11CA, 2, -1, 1, 0x1A81, 0x1A80, 0, 0, 1, 0);
        self->p2E0->v86();
    }
}

void fn_800E9BB8(UiS* self)
{
    if (self->m2DC == 0) {
        fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAD8C, 0, 0xFFA, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
        self->p2E0->v86();
    } else {
        fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAE04, 0, 0xFFA, 2, -1, 1, 0x1A81, 0x1A80, 0, 0, 1, 0);
        self->p2E0->v86();
    }
}

void fn_800E9E44(UiS* self)
{
    Ui80619948* g = lbl_80619948;
    UiS* c = self->p2E0;
    self->m304 = 0;
    self->m308 = 0;
    int r = fn_800A3270(g, &self->m304, &self->m308);
    if (r != 0) {
        if (g->m74 == 2) {
            fn_800A2F9C(lbl_80619948, 1);
            self->v114(self->m2E4);
        }
    } else {
        fn_80131F34(c, self, (void (*)(int, void*))fn_800EAAEC, 0, 0x46D7, 2, -1, 1, 0x4DA6, 0x4558, 0, 0, 0, 0);
        c->v86();
    }
}

void fn_800E9F34(UiS* self)
{
    fn_80132630(self->p2E0, 0);
    self->p2E0->v86();
}

void fn_800E9F84(UiS* self, int a)
{
    int id = 0;
    switch (a) {
    case 2:
        id = 0x38CD;
        break;
    case 4:
        id = 0x38CC;
        break;
    }
    if (self->m2DC == 0)
        fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAD8C, 0, id, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    else
        fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAE04, 0, id, 2, -1, 1, 0x1A81, 0x1A80, 0, 0, 1, 0);
    fn_800B555C()->m560 = 1;
    self->p2E0->v86();
}

void fn_800EA090(UiS* self, int a)
{
    int id = 0;
    switch (a) {
    case 2:
        id = 0x3917;
        fn_800B555C()->m564 = 1;
        break;
    case 4:
        id = 0x3916;
        fn_800B555C()->m568 = 1;
        break;
    }
    fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAD8C, 0, id, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    self->p2E0->v86();
}

void fn_800EA6C8(UiS* self)
{
    fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAD38, 0, 0x3886, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    self->p2E0->v86();
    fn_800B555C()->m518 = 1;
}

void fn_800EA760(UiS* self)
{
    fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAD38, 0, 0x3887, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    self->p2E0->v86();
    fn_800B555C()->m520 = 1;
}

void fn_800EA7F8(UiS* self)
{
    fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAD8C, 0, 0x488D, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    self->p2E0->v86();
}

void fn_800EA884(UiS* self)
{
    fn_80131F34(self->p2E0, self, (void (*)(int, void*))fn_800EAD38, 0, 0x3885, 1, 0x12C, 1, 0x26DE, 0, 0, 0, 0, 0);
    self->p2E0->v86();
    fn_800B555C()->m524 = 1;
}

void fn_800EA91C(int a, UiS* x)
{
    if (lbl_8061A48C != 0)
        a = fn_8040ABA0() % 2 == 1;
    Ui80619948* g = lbl_80619948;
    switch (a) {
    case 1:
        x->v111();
        break;
    case 0:
        fn_80134CD0(x->p2E0);
        fn_800A2F9C(g, 1);
        break;
    case 2:
        x->v110();
        fn_80134CD0(x->p2E0);
        break;
    }
}

void fn_800EAAA4(void* unused, UiS* x)
{
    fn_80134CD0(x->p2E0);
    x->v99();
}

void fn_800EAAEC(int a, UiS* x)
{
    Ui80619948* g = lbl_80619948;
    void* o = fn_8007F7D0(lbl_8061930C, 0);
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    switch (a) {
    case 0:
        fn_8055EAFC(o);
        if (g->m74 == 2) {
            fn_800A2F9C(lbl_80619948, 1);
            x->v114(x->m2E4);
        }
        break;
    case 1:
        x->v80(1);
        g->m74 = 0;
        g->m80 = 0;
        g->mA4 = 0;
        char* t = (char*)fn_800B555C() + 8;
        fn_800C2034(t, ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(x->m304));
        fn_8040B830(p->name, fn_800EAE8C(x->m308), 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    }
}

void fn_800EAC30(UiS* self)
{
    self->v80(1);
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805BE120, 15);
    p->name[15] = 0;
    Ui80619948* g = lbl_80619948;
    g->m74 = 0;
    g->m80 = 0;
    g->mA4 = 0;
    fn_800C2110((char*)fn_800B555C() + 8, g->mA8);
    fn_800B7B4C(UiGetMsgMgr(), p, self);
}

void fn_800EACF8(void* self)
{
    fn_80546258(lbl_80619948->mA8);
    fn_800EA9F4(self);
}

void fn_800EAD38(void* t, Unk800EAD5C_C* u)
{
    fn_800EAD5C(u);
}

void fn_800EAD5C(Unk800EAD5C_C* t)
{
    if (t->m2F0 != 0) {
        t->m2F0();
    }
}

void fn_800EAD8C(void* unused, UiS* x)
{
    x->v112(x->m2E4);
    lbl_80619948->m74 = 0;
    lbl_80619948->m80 = 0;
    lbl_80619948->mA4 = 0;
    x->v114(x->m2E4);
}

void fn_800EAE04(int a, UiS* x)
{
    lbl_80619948->m74 = 0;
    lbl_80619948->m80 = 0;
    lbl_80619948->mA4 = 0;
    switch (a) {
    case 0:
        x->v114(x->m2E4);
        break;
    case 1:
        x->v113(x->m2E4);
        break;
    }
}

const char* fn_800EAE8C(int a)
{
    switch (a) {
    case 1:
    case 2:
        return lbl_805BE0F0;
    case 4:
        return lbl_805BE100;
    case 6:
        return lbl_805BE110;
    }
    return lbl_805B6F58;
}

void fn_800EB0F4(int a, UiS* x)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    switch (a) {
    case 0:
        fn_800A2F9C(lbl_80619948, 1);
        x->v114(x->m2E4);
        break;
    case 1:
        fn_8040B830(p->name, lbl_805BE138, 15);
        p->name[15] = 0;
        lbl_80619948->m74 = 0;
        lbl_80619948->m80 = 0;
        lbl_80619948->mA4 = 0;
        x->v80(1);
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    case 2:
        fn_8007FE04(lbl_8061930C)->m1E8 = 0;
        fn_800A2F9C(lbl_80619948, 1);
        x->v114(x->m2E4);
        break;
    }
}

void fn_800EB248(int a, UiS* x)
{
    switch (a) {
    case 0:
        fn_800A2F9C(lbl_80619948, 1);
        x->v114(x->m2E4);
        break;
    case 1:
        fn_8007FE04(lbl_8061930C)->m1E8 = 0;
        fn_800A2F9C(lbl_80619948, 1);
        x->v114(x->m2E4);
        break;
    }
}

UiScrRaw* fn_800EB2F4(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80655BA8;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    return self;
}

void fn_800EB350(UiS* self)
{
    fn_800ECE34(self);
    self->p13C = fn_800B7A94(UiGetMsgMgr(), lbl_805BAF60);
    self->p134 = fn_800B7A94(UiGetMsgMgr(), lbl_805BAF10);
    self->p138 = fn_800B7A94(UiGetMsgMgr(), lbl_805BAF40);
}

void fn_800EB41C(UiS* self)
{
    fn_800ECF18(self);
    self->v90();
}

void fn_800EB460(UiS* self)
{
    if (self->p134 != 0) {
        char* r30 = lbl_806192E0->m4->m10;
        fn_80086EC0(r30, 1, ((UiVB*)self->p134)->v88(1));
        fn_80086EC0(r30, 0, ((UiVB*)self->p134)->v88(0));
        ((UiVB*)self)->v89();
    }
}

UiScrRaw* fn_800EB518(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EB2F4(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80654430;
    fn_804D1FD4((char*)self + 0x144);
    fn_804D1FD4((char*)self + 0x188);
    return self;
}

void fn_800EB704(UiS* self)
{
    fn_800EB41C(self);
    if (fn_800B57EC(fn_800B555C()) == 0) {
        if (fn_800B555C()->m4 & 1) {
            Unk8007B2B0_Screen* s = lbl_8061930C;
            for (int i = 0; i <= 3; i++)
                s->fn_8007DA8C(i, -1);
            int t = self->m17C;
            s->fn_8007DA8C(t, s->fn_8007DA28());
        }
    }
    self->v94(1);
    UiP2 q = lbl_805BC06C;
    fn_804D21B8((char*)self + 0x144, &q);
}

void fn_800EB7D4(UiS* self)
{
    fn_800ED254(self);
    UiP2 s = lbl_805BC074;
    fn_804D21B8((char*)self + 0x144, &s);
}

void fn_800EB824(UiS* self)
{
    UiSub144* sub = (UiSub144*)((char*)self + 0x144);
    fn_800ECAA4(self);
    self->v90();
    if (fn_802D7CE0(sub->m38, 0) == 0 && sub->m38 != -1) {
        fn_804D27B4((char*)sub, 0);
        self->v93();
    }
    fn_804D233C((char*)sub);
}

void fn_800EB8B8(UiS* self)
{
    fn_804D2310((char*)self + 0x144)->v71();
}

void fn_800EB8F4(UiS* self)
{
    fn_804D2310((char*)self + 0x144)->v72();
}

int fn_800EB930(Unk800EAD5C_T* t, int x)
{
    return x == t->m17C;
}

UiS* fn_800EB944(char* t)
{
    return fn_804D2310(t + 0x144);
}

void fn_800EBCC4(UiS* self, int a, int b)
{
    fn_804D2310((char*)self + 0x144)->v68(a, b);
}

void fn_800EBD18(UiS* self, int a)
{
    fn_804D2310((char*)self + 0x144)->v69(a);
}

void fn_800EBD64(UiS* self, int a)
{
    fn_804D2310((char*)self + 0x144)->v73(a);
}

int fn_800EBDB0()
{
    return 0;
}

int fn_800EBDB8()
{
    return 0;
}

void fn_800EBDC0(UiS* self)
{
    if (self->p134 != 0 && self->v91() == 0) {
        UiSub144* sub = (UiSub144*)((char*)self + 0x144);
        int v = ((UiVB*)self->p134)->v88(1);
        if (sub->m38 != -1 && v == -1)
            self->v67(-3);
        if (sub->m38 != v) {
            fn_804D292C((char*)sub, v);
            ((Ui198*)self->p138)->m198 = v;
            self->v94(0);
        }
    }
}

void fn_800EBEA8(UiS* self, int a, int b, int c)
{
    if (a == 0 && self->p134 != 0) {
        ((UiVB*)self->p134)->v86(1, 0);
        if (c != 0)
            self->v94(1);
    }
}
