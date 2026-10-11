/*
 * Game code, .text 0x800EE048-0x800F1AEC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800EE048.h"

int fn_800EE048(UiS* self, int a)
{
    if (self->m138 != 0 || fn_800B555C()->m570 == a) {
        fn_800C8060(self->v32(lbl_805BE1CC, 1))->v51();
        fn_800C8060(self->v32(lbl_805BE1C4, 1))->v51();
    }
    return 1;
}

int fn_800EE114(UiS* self, int a)
{
    if (self->m138 != 0 || fn_800B555C()->m570 == a) {
        fn_800C8060(self->v32(lbl_805BE1CC, 1))->v52();
        fn_800C8060(self->v32(lbl_805BE1C4, 1))->v52();
    }
    return 1;
}

int fn_800EE1E0(UiS* self, int a)
{
    if (self->m138 != 0 || fn_800B555C()->m570 == a) {
        fn_800C8060(self->v32(lbl_805BE1CC, 1))->v53();
        fn_800C8060(self->v32(lbl_805BE1C4, 1))->v53();
    }
    return 1;
}

int fn_800EE2AC(UiS* self, int a)
{
    if (self->m138 != 0 || fn_800B555C()->m570 == a)
        fn_800C8060(self->v32(lbl_805BE1C4, 1))->v54();
    return 1;
}

int fn_800EE338(UiS* self, int a)
{
    if (self->m138 != 0 || fn_800B555C()->m570 == a)
        fn_800C8060(self->v32(lbl_805BE1C4, 1))->v55();
    return 1;
}

int fn_800EE3C4(UiS* self, int a)
{
    if (self->m138 != 0 || fn_800B555C()->m570 == a)
        fn_800C8060(self->v32(lbl_805BE1C4, 1))->v56();
    return 1;
}

int fn_800EE450(UiS* self, int a)
{
    if (self->m138 != 0 || fn_800B555C()->m570 == a)
        fn_800C8060(self->v32(lbl_805BE1C4, 1))->v57();
    return 1;
}

UiScrRaw* fn_800EE4DC(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80651628;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 2;
    self->m144 = 0;
    return self;
}

void fn_800EE540(UiS* self)
{
    fn_800ECF18(self);
    self->p13C = fn_800B7AB8(UiGetMsgMgr(), lbl_805BA6D8);
    self->p144 = fn_800B7AB8(UiGetMsgMgr(), lbl_805BA6D0);
    fn_80124FA8(self->p144, self);
    fn_800C80C0(self->p144, fn_800B555C()->m570);
    fn_800C80C0(self, fn_800B555C()->m570);
    UiR3D90* o = fn_801A6D84(fn_8011AA24(0), 5);
    if (o != 0 && o->m3D90 != 0)
        fn_8016C4A0(o);
    int one = 1;
    lbl_8061EE14 = one;
}

void fn_800EEAE0(UiS* self)
{
    fn_800ED254(self);
    int z = 0;
    lbl_8061EE14 = z;
    switch (fn_8011AA4C()) {
    case 0:
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        fn_800C3BE0(fn_800C33D0());
        break;
    }
}

void fn_800EEB2C(Unk800EEB2C_T* t)
{
    t->m138 = 1;
}

int fn_800EEB38(Unk800EEB2C_T* t, int x)
{
    if (x != t->m140) {
        return 1;
    }
    return 0;
}

void fn_800EEB50(Unk800EEB2C_T* t, int x)
{
    t->m140 = x;
}

void fn_800EEB58(UiS* self, int a)
{
    fn_80125490(self->p144, 1, 4, 0x38C8, 1);
    if (a != 0)
        fn_801251CC(self->p144, 0, 0x1A0A, 2);
    else
        fn_80125084(self->p144, 0);
    if (self->m138 == 0)
        fn_801251CC(self->p144, 1, 0x26DF, 0);
    else
        fn_80125084(self->p144, 1);
    if (self->m134 != 0 && fn_8011AB48(1) == -1 && fn_8011AB48(0) == -1) {
        fn_80125084(self->p144, 0);
        fn_80125084(self->p144, 4);
    }
}

void fn_800EEC3C(UiS* self, int a)
{
    if (a != 0)
        fn_80131F34(self->p13C, self, (void (*)(int, void*))fn_800EED20, 0, 0x5CDA, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
    else
        fn_80131F34(self->p13C, self, (void (*)(int, void*))fn_800EED68, 0, 0x5CDA, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
    self->p13C->v86();
}

void fn_800EED20(int a, void* b)
{
    switch (a) {
    case 0:
        break;
    case 1:
        fn_800F0650(b);
        fn_800EEDB0((UiS*)b);
        break;
    }
}

void fn_800EED68(int a, void* b)
{
    switch (a) {
    case 0:
        break;
    case 1:
        fn_800F0650(b);
        fn_800F0678(b);
        break;
    }
}

void fn_800EEDB0(UiS* t)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805BADC8, 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, t);
    UiEvtRaw e;
    const void* base = lbl_80649DA0;
    e.vt = base;
    e.id = 0x9E;
    e.vt = lbl_8065B888;
    fn_8037893C(fn_8011AA24(0)->m704, e.id, &e, 0, 0);
    e.vt = base;
}

UiScrRaw* fn_800EEE74(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EE4DC(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80651370;
    return self;
}

void fn_800EF2B8(UiScrRaw* self)
{
    fn_800EE63C((UiS*)self);
    self->m1A8 = fn_8011AB48(0);
    self->m1AC = fn_8011AB48(1);
}

enum E48Sel { E48Sel_Neg = -1, E48Sel_Lo = 0, E48Sel_Hi = 1 };
/* near-miss: 136 vs 139 insns; local UiStr4 copies and field reads through byte offsets differ */
int fn_800EF7D8(UiS* self, int idx)
{
    fn_8001BC4C()->fn_8001BDAC(0x9C);
    int sel = -1;
    UiStr4 a = lbl_805BE2DC;
    UiStr4 b = lbl_805BE2FC;
    UiS* o1 = self->v32(a.m[idx], 1);
    UiS* o2 = self->v32(b.m[idx], 1);
    if (idx == fn_8011AB48(0))
        sel = 0;
    else if (idx == fn_8011AB48(1))
        sel = 1;
    switch ((E48Sel)sel) {
    case 0:
        break;
    case 1: {
        int o = idx * 16;
        ((UiVJ*)o1)->v5(*(int*)((char*)self + 0x148 + o), *(int*)((char*)self + 0x14C + o), lbl_8061A328, lbl_8061A328 + 0xC);
        ((UiVJ*)o2)->v5(*(int*)((char*)self + 0x150 + o), *(int*)((char*)self + 0x154 + o), lbl_8061A328, lbl_8061A328 + 0xC);
        fn_8011ABDC(1, -1);
        break;
    }
    case -1:
        if (fn_8011AB48(0) == -1 && fn_800EEB38((Unk800EEB2C_T*)self, 0) != 0) {
            ((UiVJ*)o1)->v5(self->m188, self->m18C, lbl_8061A328, lbl_8061A328 + 0xC);
            ((UiVJ*)o2)->v5(self->m198, self->m19C, lbl_8061A328, lbl_8061A328 + 0xC);
            fn_8011ABDC(0, idx);
        }
        break;
    }
    return 1;
}

/* near-miss: 132 vs 137 insns; local UiStr4 copies and field reads through byte offsets differ */
int fn_800EFA04(UiS* self, int idx)
{
    fn_8001BC4C()->fn_8001BDAC(0x9B);
    int sel = -1;
    UiStr4 a = lbl_805BE2DC;
    UiStr4 b = lbl_805BE2FC;
    UiS* o1 = self->v32(a.m[idx], 1);
    UiS* o2 = self->v32(b.m[idx], 1);
    if (idx == fn_8011AB48(0))
        sel = 0;
    else if (idx == fn_8011AB48(1))
        sel = 1;
    switch ((E48Sel)sel) {
    case 0: {
        int o = idx * 16;
        ((UiVJ*)o1)->v5(*(int*)((char*)self + 0x148 + o), *(int*)((char*)self + 0x14C + o), lbl_8061A328, lbl_8061A328 + 0xC);
        ((UiVJ*)o2)->v5(*(int*)((char*)self + 0x150 + o), *(int*)((char*)self + 0x154 + o), lbl_8061A328, lbl_8061A328 + 0xC);
        fn_8011ABDC(0, -1);
        break;
    }
    case -1:
        if (fn_8011AB48(1) == -1 && fn_800EEB38((Unk800EEB2C_T*)self, 1) != 0) {
            ((UiVJ*)o1)->v5(self->m190, self->m194, lbl_8061A328, lbl_8061A328 + 0xC);
            ((UiVJ*)o2)->v5(self->m1A0, self->m1A4, lbl_8061A328, lbl_8061A328 + 0xC);
            fn_8011ABDC(1, idx);
        }
        break;
    }
    return 1;
}

void fn_800F04E0(UiS* self, int a)
{
    UiS* w = fn_800C8044(self->v32(lbl_805BE32C, 1));
    if (a == 1) {
        self->v32(lbl_805BE200, 1)->v8(0);
        w->v32(lbl_805BE33C, 1)->v8(0);
    } else {
        self->v32(lbl_805BE20C, 1)->v8(0);
        w->v32(lbl_805BE348, 1)->v8(0);
    }
    fn_800EEB50((Unk800EEB2C_T*)self, a);
}

void fn_800F0650(void* t)
{
    UiX600* c = lbl_806192E0->m4->mC;
    if (c->m600 == 0) {
        c->m600 = 1;
    }
}

void fn_800F0678(UiS* self)
{
    int sel = fn_800B555C()->m0 == 0x21;
    if (fn_802D7CE0(self->m1B0, 0) == 0) {
        self->m1B0 = self->m1A8 == -1 ? self->m1AC : self->m1A8;
    }
    fn_800B555C()->m570 = self->m1B0;
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805BACB4, 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
    if (sel) {
        UiEvtRaw e;
        const void* base = lbl_80649DA0;
        e.vt = base;
        e.id = 0x9E;
        e.vt = lbl_8065B888;
        fn_8037893C(fn_8011AA24(0)->m704, e.id, &e, 0, 0);
        e.vt = base;
    }
}

UiScrRaw* fn_800F0790(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_806510C8;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    return self;
}

int fn_800F07EC()
{
    return 1;
}

void fn_800F07F4(UiS* self)
{
    self->v45();
}

int fn_800F0828(void* t, int b)
{
    switch (fn_800F1740(t)) {
    case 0:
        fn_800F1604(t);
        break;
    case 1:
        fn_800F13C0(t, 0x514, b);
        break;
    case 2:
        fn_800F181C(t);
        fn_800F13C0(t, 0x3913, b);
        break;
    }
    return 1;
}

void fn_800F08B8(UiS* self, char* out)
{
    *out = 0;
    if (self->v81() != 0 || fn_800F1740(self) != 2)
        fn_8040B830(out, self->p13C->v70()->v33(5, 1)->name, 16);
}

void fn_800F0968(void* t)
{
    fn_800ECE34((UiS*)t);
}

void fn_800F1210(void* t)
{
    fn_800ED254((UiS*)t);
}

int fn_800F1230(UiS* self, int a)
{
    if (a == self->m13C) {
        switch (fn_800F1740(self)) {
        case 0:
            fn_800F1604(self);
            break;
        case 1:
            fn_800F13C0(self, 0x514, -1);
            break;
        case 2:
            fn_800F181C(self);
            fn_800F13C0(self, 0x3913, -1);
            break;
        }
        return 1;
    }
    return 0;
}

int fn_800F12D0(UiP13C* self)
{
    self->m13C->v50();
    return 1;
}

int fn_800F130C(UiP13C* self)
{
    self->m13C->v51();
    return 1;
}

int fn_800F1348(UiP13C* self)
{
    self->m13C->v52();
    return 1;
}

int fn_800F1384(UiP13C* self)
{
    self->m13C->v53();
    return 1;
}

void fn_800F13C0(UiS* self, int a, int b)
{
    if (self->m134 != 0)
        fn_800F14F8(self);
    self->p134 = fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D8);
    self->v16(0);
    self->p138->v16(0);
    fn_80131F34(self->p134, self, (void (*)(int, void*))fn_800F15AC, fn_800F15A4, a, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
    self->p134->m2F0 = -0x63;
    fn_800C80C0(self->p134, b);
    self->p134->v86();
}

void fn_800F14F8(UiS* self)
{
    self->p134->v16(0);
    self->p134->v8(0);
    self->m134 = 0;
    self->v16(1);
    self->p138->v16(1);
}

int fn_800F15A4()
{
    return 0;
}

void fn_800F15AC(int a, void* b)
{
    switch (a) {
    case 0:
        fn_800F1820(b);
        break;
    case 1:
        fn_800F1604(b);
        break;
    }
    fn_800F14F8(b);
}

int fn_800F1604(UiS* self)
{
    switch (fn_800F1740(self)) {
    case 0:
        fn_800B7ADC(UiGetMsgMgr(), self);
        return 1;
    case 1:
        self->v80(1);
        lbl_8061B8C0->m20 = 2;
        fn_800B7ADC(UiGetMsgMgr(), self);
        return 1;
    case 2:
        self->v80(1);
        fn_800B7ADC(UiGetMsgMgr(), self);
        return 1;
    }
    return 0;
}

void fn_800F16F0(UiP13C* self, int a)
{
    fn_800ED310((UiS*)self, a);
    self->m13C->v14(a);
}

int fn_800F1740(UiS* self)
{
    return fn_800F17B4(self, fn_800C8048(self->p13C->v70()->v33(5, 1))->name);
}

int fn_800F17B4(void* t, const char* s)
{
    for (int i = 0; i < 3; i++) {
        if (fn_8040B574(lbl_8061B328[i], s) == 0)
            return i;
    }
    return 0;
}

void fn_800F181C(void* t)
{
}

void fn_800F1820(void* t)
{
}

UiScrRaw* fn_800F1824(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 3, lbl_8061B334);
    self->m3C = lbl_8064BD58;
    return self;
}

void fn_800F188C(UiScrRaw* self)
{
    fn_804D3164(self);
    fn_804D2DC0(self, 0x5B04);
}

int fn_800F18C4(UiS* self, int a)
{
    fn_800B555C()->m570 = a;
    fn_80132438(fn_804D2D50(self), self, fn_804D3BA0, fn_800F1AEC, fn_800F1A6C, 0x3A61, -1, 1, lbl_805BE3CC);
    fn_804D2D50(self)->v86();
    self->v40();
    return 1;
}

void fn_800F1970(UiS* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_804D32A0(self, fn_800B555C()->m570);
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805B955C, 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
}

void fn_800F1A04()
{
    fn_800DB5F4();
}

void fn_800F1A24(UiScrRaw* self)
{
    if (self->m170 == 0) {
        ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007295C();
        self->m170 = 1;
    }
}

void fn_800F1A6C()
{
    UiS* o = fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D8);
    o->v85(0);
    o->m314 = 1;
}
