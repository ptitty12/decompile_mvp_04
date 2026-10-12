/*
 * Front-end overlay code, .frontend_codeoverlay 0x80512D10-0x80516990 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

struct FeP298_1E0 { char pad[0x1E0]; FeW* m1E0; char pad2[0x298 - 0x1E0 - 4]; FeW* m298; };

extern const char lbl_8067EED0[];
extern const char lbl_805FB9A8[];
extern const char lbl_805FB970[];
extern "C" void fn_8051457C(FeScrQ* x, void* y);
extern "C" void fn_805146C0(FeScrQ* x, void* y);
extern "C" void fn_805148D0(FeScrQ* x, void* y);
extern "C" void fn_805140D8(FeScrQ* x);
extern const char lbl_80667920[];
extern "C" FeScrN* fn_80512D10(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80512D60(FeScrD* x);
extern "C" int fn_80512F8C(FeScrK* x);
extern "C" int fn_80512FF8(FeScrB* x);
extern "C" int fn_80513054(FeScrN* x);
extern "C" int fn_80513090(FeScrN* x);
extern "C" int fn_805130CC(FeScrN* x);
extern "C" int fn_80513108(FeScrN* x);
extern "C" void fn_80513144(FeScrN* x, char* dst);
extern "C" int fn_805131B8(FeScrB* x);
extern "C" FeScrQ* fn_80513214(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80513270(FeScrD* x);
extern "C" void fn_80514340(FeScrQ* x, int a);
extern "C" void fn_80514538(FeScrQ* x);
extern "C" void fn_80514B78(void* self, FeP0B0* y);
extern "C" void fn_80514DB0(FeScrQ* x, void* y);
extern "C" int fn_80514DF8(void* self, FeIdTab* y, int v);
extern "C" int fn_805153AC(FeP2A8* x);
extern "C" void fn_805158B0();
extern "C" int fn_80515ED8(FeScrQ* x, int a);
extern "C" int fn_80515F64();
extern "C" int fn_80515F6C(FeScrQ* x, int a);
extern "C" int fn_80516014();
extern "C" int fn_8051601C(FeP2A8* x);
extern "C" int fn_8051605C(FeP2A8* x);
extern "C" int fn_8051609C(FeP2A8* x);
extern "C" int fn_805160DC(FeP2A8* x);
extern "C" int fn_8051611C(FeScrQ* x);
extern "C" int fn_805161E0(FeScrN* x);
extern "C" int fn_8051628C(FeScrQ* x);
extern "C" int fn_80516350(FeScrN* x);
extern "C" int fn_805163FC(FeScrQ* x);
extern "C" int fn_80516474(FeP298_1E0* x);
extern "C" int fn_805164D8(FeScrQ* x);
extern "C" int fn_80516550(FeP298_1E0* x);
extern "C" void fn_8051687C();

extern "C" FE_OVERLAY FeScrN* fn_80512D10(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80667920);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80512D60(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY int fn_80512F8C(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80512FF8(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80513054(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80513090(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_805130CC(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80513108(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY void fn_80513144(FeScrN* x, char* dst)
{
    fn_8040B830(dst, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC, 16);
}

extern "C" FE_OVERLAY int fn_805131B8(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY FeScrQ* fn_80513214(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067EED0);
    self->m130 = 0;
    self->m2A8 = 0;
    self->m2AC = 1;
    self->m2B4 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80513270(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_80514340(FeScrQ* x, int a)
{
    x->m2AC = a;
    fn_805140D8(x);
}

extern "C" FE_OVERLAY void fn_80514538(FeScrQ* x)
{
    fn_80514DB0(x, &x->m134);
    fn_80514DB0(x, (char*)x + 0x1EC);
    fn_805140D8(x);
}

extern "C" FE_OVERLAY void fn_80514B78(void* self, FeP0B0* y)
{
    FeW* w = y->mB0;
    ((FeSub15*)((char*)w + 0xDC))->s15();
    ((FeWX*)w)->s51(0x3FB7, 0);
    ((FeWX*)w)->s51(0x3FB8, 1);
    ((FeWX*)w)->s51(0x3FB9, 2);
    ((FeWX*)w)->s51(0x5A1A, 3);
}

extern "C" FE_OVERLAY void fn_80514DB0(FeScrQ* x, void* y)
{
    fn_8051457C(x, y);
    fn_805146C0(x, y);
    fn_805148D0(x, y);
}

extern "C" FE_OVERLAY int fn_80514DF8(void* self, FeIdTab* y, int v)
{
    int n = y->m88;
    for (int i = 0; i < n; i++) {
        if (v == y->m78[i]) {
            return 1;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_805153AC(FeP2A8* x)
{
    int i = x->m2A8->m94->fn_vslot60();
    int r;
    if (i < x->m2A8->m84) {
        r = x->m2A8->m4[i];
    } else {
        r = 0;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_805158B0()
{
}

extern "C" FE_OVERLAY int fn_80515ED8(FeScrQ* x, int a)
{
    if (x->m2AC > 0) {
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    }
    int v = x->m2AC - 1;
    x->m2AC = v;
    if (v < 0) {
        x->m2AC = 0;
    }
    fn_80514340(x, x->m2AC);
    ((FeWX*)x)->s55(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_80515F64()
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80515F6C(FeScrQ* x, int a)
{
    if (x->m2AC <= 0) {
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    }
    int v = x->m2AC + 1;
    x->m2AC = v;
    if (v > 1) {
        x->m2AC = 1;
    }
    fn_80514340(x, x->m2AC);
    ((FeWX*)x)->s55(a);
    ((FeWX*)x)->s57(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_80516014()
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8051601C(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051605C(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051609C(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_805160DC(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051611C(FeScrQ* x)
{
    if (x->m2AC == 0) {
        fn_800C805C(x->fn_vslot32(lbl_805FB9A8, 1))->fn_vslot40(1);
    } else if (x->m2AC == 1) {
        fn_800C805C(x->fn_vslot32(lbl_805FB970, 1))->fn_vslot40(1);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_805161E0(FeScrN* x)
{
    ((FeWX*)fn_800C805C(x->fn_vslot32(lbl_805FB9A8, 1)))->s41();
    ((FeWX*)fn_800C805C(x->fn_vslot32(lbl_805FB970, 1)))->s41();
    return 0;
}

extern "C" FE_OVERLAY int fn_8051628C(FeScrQ* x)
{
    if (x->m2AC == 0) {
        fn_800C805C(x->fn_vslot32(lbl_805FB9A8, 1))->fn_vslot38(1);
    } else if (x->m2AC == 1) {
        fn_800C805C(x->fn_vslot32(lbl_805FB970, 1))->fn_vslot38(1);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80516350(FeScrN* x)
{
    fn_800C805C(x->fn_vslot32(lbl_805FB9A8, 1))->fn_vslot39();
    fn_800C805C(x->fn_vslot32(lbl_805FB970, 1))->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_805163FC(FeScrQ* x)
{
    if (x->m2AC == 0) {
        ((FeW*)x->m298)->fn_vslot40(1);
    } else if (x->m2AC == 1) {
        ((FeW*)x->m1E0)->fn_vslot40(1);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80516474(FeP298_1E0* x)
{
    ((FeWX*)x->m298)->s41();
    ((FeWX*)x->m1E0)->s41();
    return 0;
}

extern "C" FE_OVERLAY int fn_805164D8(FeScrQ* x)
{
    if (x->m2AC == 0) {
        ((FeW*)x->m298)->fn_vslot38(1);
    } else if (x->m2AC == 1) {
        ((FeW*)x->m1E0)->fn_vslot38(1);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80516550(FeP298_1E0* x)
{
    x->m298->fn_vslot39();
    x->m1E0->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY void fn_8051687C()
{
}
