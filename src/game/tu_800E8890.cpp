/*
 * Game code, .text 0x800E8890-0x800EBF2C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800E8890.h"

inline int KeyAt8890(char* base, int off)
{
    return *(int*)(base + off);
}

void fn_800E8890(Ue8890* t, int idx, int a2, int a3)
{
    UiS* scr = t->p0;
    char* row = t->m8->m14 + idx * 0xE64;
    int cnt = 0;
    unsigned char n = *(unsigned char*)(row + 0x3E4);
    int* pc = &t->m10;
    char b8[0x190];
    char b198[0x190];
    unsigned char b328[0x18];
    fn_80403144(b8, fn_80090880(lbl_8061977C, a2));
    int k = 0;
    fn_800DFEAC(b8, lbl_805BE020);
    if (cnt < n) {
        do {
            unsigned char kk = k;
            int r = fn_80097EA4(row, a3, kk, 2, 0);
            if (r > 0) {
                cnt++;
                if (cnt > 1)
                    fn_800DFEAC(b8, lbl_805BE024);
                char* tb = row + 0x3E8;
                int off = kk * 0x34;
                fn_800DE354((int)b198, t->m8, idx, KeyAt8890(tb, off), 1);
                b328[0] = *(unsigned char*)lbl_805B6F58;
                if (r > 1)
                    fn_804089B4((char*)b328, lbl_805BE02C, r);
                fn_800DFEAC(b198, (char*)b328);
                int l1 = fn_80403060(b8);
                if (l1 + fn_80403060(b198) > 0x3E) {
                    ((UiVM*)scr)->v43(*pc, 0, b8, 4);
                    fn_80403144(b8, b198);
                    *pc = *pc + 1;
                } else
                    fn_800DFF0C(b8, b198);
            }
            k++;
        } while (k < n);
    }
    if (cnt > 0) {
        ((UiVM*)scr)->v43(*pc, 0, b8, 4);
        *pc = *pc + 1;
    }
}

/* near-miss: 3 slots, lwzx base/index order of the quad table reads (retail: lwzx r25,r27,r30 and a precomputed &loc+4) */
void fn_800E8A6C(Ue8A6C* m)
{
    int i = 0;
    fn_800E6708(m);
    while (i < m->mF4) {
        int k = m->mEC[i];
        i++;
        fn_800E694C(m, k);
        fn_800E71E0(m, k);
        fn_800E7598(m, k);
        fn_800E7888(m, k);
        fn_800E7AD8(m, k);
    }
    i = 0;
    while (i < m->mF4) {
        int k = m->mEC[i];
        i++;
        fn_800E7E48(m, k);
    }
    UiQuad loc = lbl_805BE0E0;
    char* q = (char*)&loc;
    int off = 0;
    int j = 2;
    do {
        i = 0;
        int v = *(int*)(q + off);
        while (i < m->mF4) {
            int k = m->mEC[i];
            i++;
            fn_800E8890(m, k, *(int*)(q + 4 + off), v);
        }
        off += 8;
        j--;
    } while (j != 0);
    fn_800E6888(m);
}

void fn_800E8BCC(UiS* self)
{
    fn_800EC1E8(self);
    self->p2E0 = fn_800B7AB8(UiGetMsgMgr(), lbl_805BA6D8);
    self->m308 = 0;
    self->m304 = 0;
}

int fn_800E8C3C(UiS* self, int a)
{
    Ui80619948* g = lbl_80619948;
    self->m2DC = a;
    int v = g->m80;
    self->m2E4 = v;
    if (g->m74 == 2) {
        switch (v) {
        case 21:
            self->v109();
            break;
        case 5:
            self->v96();
            break;
        case 6:
            self->v97();
            break;
        case 3:
            self->v93();
            break;
        case 4:
            ((UiVN*)self)->v94();
            break;
        case 1:
            self->v98();
            break;
        case 10:
            self->v107();
            break;
        case 8: {
            int z = fn_800B555C()->m518;
            if (z != 0) {
                self->m2E8 = 0;
                return 0;
            }
            self->v105();
            g->m74 = z;
            g->m80 = z;
            g->mA4 = z;
            break;
        }
        case 11: {
            int z = fn_800B555C()->m524;
            if (z != 0) {
                self->m2E8 = 0;
                return 0;
            }
            self->v108();
            g->m74 = z;
            g->m80 = z;
            g->mA4 = z;
            break;
        }
        default:
            self->m2E8 = 0;
            return 0;
        }
        self->m2E8 = 1;
        return 1;
    } else {
        int t = self->m2E8;
        if (t != 0) {
            self->m2E8 = 0;
            self->m2EC = 1;
            return 1;
        }
        if (self->m2EC != 0) {
            self->m2EC = t;
            return 1;
        }
        return 0;
    }
}

/* Bound computed into q before `id = 0x4556`, inner test as if/else: each id `li` then
   follows the last call on its path and id stays in r4 (no saved register). */
void fn_800E9074(UiS* x)
{
    Ui80619948* g = lbl_80619948;
    Unk8007B2B0_Screen* s = lbl_8061930C;
    int flag = 1;
    int a = fn_800A3244(g);
    int b = ((Unk8007A4DC_Screen*)s)->fn_8007A6A0(0x1E, a);
    int c = ((Unk8007A4DC_Screen*)s)->fn_8007A6A0(0x1F, a);
    char buf20[0xC8];
    char bufE8[0x190];
    fn_800DE440((int)buf20, a, 1);
    if (x->m2DC == 0)
        flag = 0;
    if (b == 0x31) {
        fn_80403DE4(bufE8, (const char*)fn_80090880(lbl_8061977C, 0x4647), buf20, c);
    } else {
        int p = fn_800A2AE8(g);
        int q = fn_8056B7D0(lbl_80619948->m28) - p;
        int id = 0x4556;
        if (c >= q) {
            if (fn_800A2E6C(g) != 0)
                id = 0x4D52;
            else
                id = 0x4D50;
        }
        const char* f = (const char*)fn_80090880(lbl_8061977C, id);
        fn_80403DE4(bufE8, f, buf20, fn_80090880(lbl_8061977C, fn_800E6058(b)), c);
    }
    UiS* d = x->p2E0;
    int s1 = (int)fn_80090880(lbl_8061977C, 0x4557);
    int s2 = (int)fn_80090880(lbl_8061977C, 0x4558);
    fn_801321D4(d, x, (void (*)(void*, UiS*))fn_800E9248, 0, (int)bufE8, 2, -1, 1, s1, s2, 0, 0, flag, 0);
    x->p2E0->v86();
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

void fn_800E95FC(int a, UiS* x)
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
        x->v80(1);
        Unk8007B2B0_Screen* s = lbl_8061930C;
        const char* nm;
        if (((Unk8007A4DC_Screen*)s)->fn_8007A270(fn_800A31FC(lbl_80619948)) != 0)
            nm = lbl_805BE0F0;
        else
            nm = lbl_805BE100;
        fn_8040B830(p->name, nm, 15);
        p->name[15] = 0;
        char* t = (char*)fn_800B555C() + 8;
        Unk8007B2B0_Screen* s2 = lbl_8061930C;
        fn_800C2034(t, s2->fn_80078A38(fn_80077BC4(s2, fn_800A31FC(lbl_80619948))));
        lbl_80619948->m74 = 0;
        lbl_80619948->m80 = 0;
        lbl_80619948->mA4 = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    }
    case 2:
        lbl_80619948->m74 = 0;
        lbl_80619948->m80 = 0;
        lbl_80619948->mA4 = 0;
        x->v114(x->m2E4);
        break;
    }
}

void fn_800E97B4(UiS* x)
{
    Ui80619948* g = lbl_80619948;
    int mins = 0x3C;
    int a = fn_800A324C(g);
    int b = fn_800A3264(g);
    char buf20[0xC8];
    char bufE8[0x7D0];
    fn_800DE440((int)buf20, a, 1);
    UiS* c = x->p2E0;
    if (b == 0)
        mins = 0xF;
    int flag = 1;
    if (x->m2DC == 0)
        flag = 0;
    fn_80403DE4(bufE8, (const char*)fn_80090880(lbl_8061977C, 0x45C5), buf20, mins);
    int s1 = (int)fn_80090880(lbl_8061977C, 0x4557);
    int s2 = (int)fn_80090880(lbl_8061977C, 0x4558);
    fn_801321D4(c, x, (void (*)(void*, UiS*))fn_800E98D8, 0, (int)bufE8, 2, -1, 1, s1, s2, 0, 0, flag, 0);
    c->v86();
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

/* near-miss: 100 vs 99 insns; the u8 counter is clamped once and shared by both calls (extra callee-saved register), retail clamps per call */
void fn_800E9CB8(int arg0)
{
    UiS* t = fn_800B7AB8(UiGetMsgMgr(), lbl_805BA7A8);
    char* g = lbl_80619948->mA8;
    int w0 = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80075948(fn_80599C80(g, 0));
    int w1 = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80075948(fn_80599C80(g, 1));
    unsigned c0 = fn_80599C40(g, 0);
    unsigned c1 = fn_80599C40(g, 1);
    unsigned m = c1;
    if (m < c0)
        m = c0;
    fn_80523824(t, arg0, 1, fn_800EA91C, w0, w1, m);
    int j = 0;
    do {
        int flag = 1;
        if (j == 0)
            flag = 0;
        unsigned k = 0;
        while (k < fn_80599C40(g, j)) {
            int e = fn_80599C50(g, j, k);
            fn_80523C94(t, e, flag, k, fn_80599C80(g, j));
            k++;
        }
        j++;
    } while (j <= 1);
    t->v86();
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

void fn_800EA9F4(UiS* self)
{
    char buf[0x7D0];
    fn_800E5100((unsigned short*)buf, (int)lbl_80619948->mA8);
    UiS* p = self->p2E0;
    int id = (int)fn_80090880(lbl_8061977C, 0x26DE);
    fn_801321D4(p, self, (void (*)(void*, UiS*))fn_800EAAA4, 0, (int)buf, 1, -1, 1, id, 0, 0, 0, 0, 0);
    self->p2E0->v86();
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

/* near-miss: 8 slots, load order of p134 and the cached sub->m38 */
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
