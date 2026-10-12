/*
 * Front-end overlay code, .frontend_codeoverlay 0x804987EC-0x8049B0CC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern const char lbl_80675B10[];
extern const float lbl_805F7254;
extern "C" void fn_80471390(void* x);
extern "C" void fn_80470FAC(void* x);
extern const float lbl_805F7438;
extern const char lbl_805F73C8[];
extern void* lbl_8061977C;
extern "C" int fn_805560A8(void* o, int i);
extern "C" int fn_804CE0C8(int k);
extern "C" char* fn_80090880__FP11Unk80090880(void* t, int k);
extern "C" void fn_801321D4(FeW* w, void* self, void (*cb)(int, void*), int a, const char* b, int c, int d, int e, const char* f, int g, int h, int i, int j, int k);
extern const char lbl_805F730C[];
extern float lbl_805F7324;
extern const float lbl_805FC520[];
extern "C" int fn_800A35A8(void* g);
extern "C" void fn_800DA54C(void* a, int b, void* c, int d, int e);
extern "C" char* strncpy(char*, const char*, unsigned);
extern "C" {

FE_OVERLAY FeScrH* fn_804987EC(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80675B10);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = -1;
    *(float*)((char*)self + 0x144) = lbl_805F7254;
    FeI(self, 0x148) = 1;
    FeI(self, 0x14C) = 2;
    FeI(self, 0x150) = 0;
    *(float*)((char*)self + 0x164) = lbl_805F7254;
    FeI(self, 0x168) = 0;
    FeI(self, 0x16C) = 0;
    FeI(self, 0x170) = 0;
    FeI(self, 0x174) = 0;
    return self;
}

FE_OVERLAY void fn_80498880(FeW* x)
{
    fn_800ECE34(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    FeI(x, 0x150) = (int)fn_800C8044(x->fn_vslot32(lbl_805F5500, 0));
    *(float*)((char*)x + 0x164) = lbl_806192E0->m4->m14->m1D48;
}

FE_OVERLAY void fn_80498F9C(void)
{
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY void fn_80498FC0(FeW* x)
{
    fn_800ECAA4(x);
    if (FeI(x, 0x138) == 0 && FeI(x, 0x134) == 0) {
        int done = 0;
        *(float*)((char*)x + 0x144) = *(float*)((char*)x + 0x144) + lbl_805F7324;
        while (done == 0 && *(float*)((char*)x + 0x144) >= lbl_805FC520[FeI(x, 0x148)]) {
            done = fn_800A35A8(lbl_80619948);
            fn_800DA54C(lbl_806192E0->m4, done, fn_800C8060(x->fn_vslot29(lbl_805F730C)), 0, 0);
            FeI(x, 0x174) = fn_800E2E8C(FeI(x, 0x16C), 1, FeI(x, 0x174), 0);
            FeI(x, 0x170) = fn_800E2E8C(FeI(x, 0x168), 0, FeI(x, 0x170), 0);
            *(float*)((char*)x + 0x144) = *(float*)((char*)x + 0x144) - lbl_805FC520[FeI(x, 0x148)];
        }
        if (done != 0) {
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            strncpy(mp->name, lbl_805F7114, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
        }
    }
}

FE_OVERLAY int fn_80499630(FeW* x)
{
    switch (FeI(x, 0x134)) {
    case 0:
        if (((FeWI*)fn_800C8058(x->fn_vslot29(lbl_805F73C8)))->s32() != 0x3C9B) {
            fn_800C805C(x->fn_vslot29(lbl_805F73E0))->fn_vslot40(1);
        }
        break;
    case 1:
        fn_800C8060(FeMem(x, 0x150)->fn_vslot32(lbl_805F7328, 0))->fn_vslot56();
        break;
    }
    return 1;
}

FE_OVERLAY int fn_80499740(FeW* x)
{
    switch (FeI(x, 0x134)) {
    case 0:
        ((FeWV*)fn_800C805C(x->fn_vslot29(lbl_805F73E0)))->s41();
        break;
    case 1:
        fn_800C8060(FeMem(x, 0x150)->fn_vslot32(lbl_805F7328, 0))->fn_vslot57();
        break;
    }
    return 1;
}

FE_OVERLAY int fn_80499800(FeW* x)
{
    switch (FeI(x, 0x134)) {
    case 0:
        if (((FeWI*)fn_800C8058(x->fn_vslot29(lbl_805F73C8)))->s32() != 0x3C9D) {
            fn_800C805C(x->fn_vslot29(lbl_805F73E0))->fn_vslot38(1);
        }
        break;
    case 1:
        fn_800C8060(FeMem(x, 0x150)->fn_vslot32(lbl_805F7328, 0))->fn_vslot54();
        break;
    }
    return 1;
}

FE_OVERLAY int fn_80499910(FeW* x)
{
    switch (FeI(x, 0x134)) {
    case 0:
        fn_800C805C(x->fn_vslot29(lbl_805F73E0))->fn_vslot39();
        break;
    case 1:
        fn_800C8060(FeMem(x, 0x150)->fn_vslot32(lbl_805F7328, 0))->fn_vslot55();
        break;
    }
    return 1;
}

FE_OVERLAY int fn_804999D0(FeW* x, FeW* y, int z)
{
    if (y == fn_800C8060(FeMem(x, 0x150)->fn_vslot32(lbl_805F7328, 0)) || y == fn_800C8060(FeMem(x, 0x150)->fn_vslot32(lbl_805F73EC, 0))) {
        x->fn_vslot67(0, fn_800C8070((void*)z));
    }
    return 1;
}

FE_OVERLAY void fn_80499A9C(void* x, FeW* w, int dir)
{
    if (dir == 0) {
        if (FeI(x, 0x148) != 0) {
            FeI(x, 0x148) = FeI(x, 0x148) - 1;
        }
    } else {
        if (FeI(x, 0x148) != 2) {
            FeI(x, 0x148) = FeI(x, 0x148) + 1;
        }
    }
    w->fn_vslot37(FeI(x, 0x148));
}

FE_OVERLAY void fn_80499B08(void* x)
{
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    FeW125084(w, 0);
    FeW125084(w, 1);
    FeW125084(w, 3);
    switch (FeI(x, 0x134)) {
    case 0:
    case 1:
        ((int (*)(void*, int))fn_80125128)(w, 0);
        fn_801251CC(w, 2, 0x3FC7, 2);
        break;
    }
}

FE_OVERLAY FeScrL* fn_8049A1F0(FeScrL* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_8046FED8(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80677448);
    FeI(self, 0x35C) = 0;
    FeI(self, 0x360) = 0;
    FeI(self, 0x364) = 0x3C;
    *(float*)((char*)self + 0x368) = lbl_805F7434;
    FeI(self, 0x36C) = 0;
    return self;
}

FE_OVERLAY void fn_8049A258(char* x)
{
    int t = 0x3C;
    FeGlobal80619948* g = lbl_80619948;
    int lo = g->m8C; int hi = g->m90;
    if (hi - lo <= 6 || FeI(x, 0x314) == 5 || FeI(x, 0x314) == 0xB || FeI(x, 0x314) == 0xC) {
        FeI(x, 0x36C) = 1;
        if (FeI(x, 0x314) == 0xB) {
            t = 0x1E0;
        }
    } else {
        FeI(x, 0x36C) = 0;
    }
    if (FeI(x, 0x36C) != 0) {
        int now = lbl_8061A328;
        *(float*)(x + 0x368) = lbl_805F7438;
        FeI(x, 0x35C) = now;
        FeI(x, 0x360) = now + t;
        fn_800DC50C(FeP(x, 0x34C), *(float*)(x + 0x32C), lbl_805F7438);
        fn_80471390(x);
    } else {
        fn_80470FAC(x);
    }
}

FE_OVERLAY void fn_8049A330(void* x, int a)
{
    if (FeI(x, 0x338) != 0 && ((FeWI*)x)->s120() == 0) {
        ((FeWI*)x)->s117();
    } else {
        FeI(x, 0x36C) = 0;
        fn_80470F20((FeScrL*)x, a);
    }
}

FE_OVERLAY void fn_8049A3B8(char* x)
{
    if (FeI(x, 0x36C) != 0) {
        if (FeI(x, 0x338) != 0) {
            float f = (float)(lbl_8061A328 - FeI(x, 0x35C)) * lbl_805F7448;
            if (lbl_8061A328 > FeI(x, 0x360)) {
                f = lbl_805F744C;
            }
            if (!(f <= *(float*)(x + 0x368))) {
                *(float*)(x + 0x368) = f;
                fn_800DC50C(FeP(x, 0x34C), *(float*)(x + 0x32C), f);
            }
        }
    } else {
        fn_80471830(x);
    }
}

FE_OVERLAY int fn_8049A480(char* x)
{
    if (FeI(x, 0x36C) != 0) {
        if ((float)*(short*)((char*)FeP(x, 0x34C) + 0x2A) < *(float*)(x + 0x32C)) {
            return 0;
        }
    }
    return 1;
}

FE_OVERLAY void fn_8049A6C4(FeScrL* x)
{
    x->m314 = 8;
    if (lbl_80619948->m80 == 9) {
        lbl_80619948->m74 = 0;
        lbl_80619948->m80 = 0;
        lbl_80619948->mA4 = 0;
    }
    int v = fn_800A2AE8(lbl_80619948) + 0x16D;
    x->m318 = v;
    fn_800A29C4(lbl_80619948, v);
    x->m330 = 6;
    fn_80470E30(x, 0, 1, 7, -1);
    FeI(fn_800B555C(), 0x63C) = 0;
}

FE_OVERLAY void fn_8049A760(FeScrL* x)
{
    x->m314 = 6;
    FeGlobal80619948* g = lbl_80619948;
    if (g->m80 == 8) {
        g->m74 = 0;
        g->m80 = 0;
        FeI(g, 0xA4) = 0;
    }
    ((void (*)(FeGlobal80619948*))fn_800A2948)(g);
    x->m330 = 3;
    fn_80470E30(x, 0, 1, 5, -1);
    fn_8001BC4C()->fn_8001BDAC(0x9D);
}

FE_OVERLAY void fn_8049A988(FeScrL* x, int a)
{
    x->m314 = 0xA;
    FeGlobal80619948* g = lbl_80619948;
    if (g->m80 == 0xB) {
        g->m74 = 0;
        g->m80 = 0;
        FeI(g, 0xA4) = 0;
    }
    fn_800A2948(g, a);
    x->m330 = 3;
    fn_80470E30(x, 0, 1, 9, -1);
}

FE_OVERLAY void fn_8049AA00(FeW* x)
{
    char buf[0x320];
    void** pt = &lbl_8061977C;
    void* t = *pt;
    void* r = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
    int a = fn_804CE0C8(fn_805560A8(r, 0));
    int b = fn_804CE0C8(fn_805560A8(r, 1));
    int c = fn_804CE0C8(fn_805560A8(r, 2));
    int d = fn_804CE0C8(fn_805560A8(r, 3));
    char* s0 = fn_80090880__FP11Unk80090880(t, 0x38F0);
    char* s1 = fn_80090880__FP11Unk80090880(t, a);
    char* s2 = fn_80090880__FP11Unk80090880(t, b);
    char* s3 = fn_80090880__FP11Unk80090880(t, c);
    char* s4 = fn_80090880__FP11Unk80090880(t, d);
    ((void (*)(char*, const char*, ...))fn_80403DE4)(buf, s0, s1, s2, s3, s4);
    fn_801321D4(FeMem(x, 0x2E0), x, (void (*)(int, void*))fn_8049AB70, 0, buf, 1, -1, 1, fn_80090880__FP11Unk80090880(*pt, 0x26DE), 0, 0, 0, 1, 0);
    FeMem(x, 0x2E0)->fn_vslot86();
}

FE_OVERLAY void fn_8049AB70(void* a, void* b)
{
    fn_8049A4DC(b);
}

FE_OVERLAY void fn_8049AB94(FePopup* p)
{
    FeScrL* x = (FeScrL*)p;
    x->m314 = 0xB;
    x->m330 = 3;
    fn_80470E30(x, 0, 1, 0xA, -1);
}

FE_OVERLAY void fn_8049ABD4(FePopup* p)
{
    FeScrL* x = (FeScrL*)p;
    x->m314 = 0xC;
    x->m330 = 3;
    fn_80470E30(x, 0, 1, 0xB, -1);
}

extern const char lbl_80675868[];
FE_OVERLAY FeScrH* fn_8049AC14(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80675868);
    self->m130 = 0;
    return self;
}

FE_OVERLAY void fn_8049AC60(FeScrD* x)
{
    fn_800ECE34(x);
}

FE_OVERLAY void fn_8049AC80(void* x)
{
    fn_800ECF18(x);
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(w, x);
    ((int (*)(void*, int, int))fn_80125180)(w, 1, 0x1A0C);
    fn_80125180(w, 0, 0x1A0D);
}

FE_OVERLAY void fn_8049AD0C(FeScrD* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY void fn_8049AD2C(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_8049AD4C(void) {}

FE_OVERLAY void fn_8049AD50(void) {}

FE_OVERLAY void fn_8049AD54(void) {}

FE_OVERLAY int fn_8049AD58(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_8049ADB4(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_8049AE10(void) { return 0; }

FE_OVERLAY void fn_8049AE18(int a, char* dst)
{
    fn_8040B830(dst, &lbl_805F36A0.c0, 16);
}

FE_OVERLAY FeScrH* fn_8049AE48(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806755C0);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    return self;
}

FE_OVERLAY void fn_8049AE98(FeScrD* x)
{
    fn_800ECE34(x);
}

}
