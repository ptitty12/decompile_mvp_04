/*
 * Front-end overlay code, .frontend_codeoverlay 0x80516990-0x80519600 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"

extern "C" void fn_8051667C(void* x);
extern "C" void fn_80517518(void* x, int a, int b);
extern const char lbl_80669A50[];
extern "C" void fn_80517910(void* x, int a);
extern "C" void fn_80518784(void* x, int a);
extern "C" void fn_80518AAC(void* x);
extern "C" int fn_805190D8(void* x);
extern "C" void fn_80528524(int a, void* x);
extern "C" void fn_80516990(int a, void* x);
extern "C" void fn_805169BC(int a, FeScrT* x);
extern "C" int fn_80516A3C(FeScrT* x);
extern "C" int fn_80516A84(FeScrT* x);
extern "C" int fn_80516ACC(FeScrT* x);
extern "C" int fn_80516B1C(FeScrT* x);
extern "C" void fn_80516D24(FeScrT* x, char* dst);
extern "C" void fn_80516D54(FeScrT* x, int a);
extern "C" int fn_80516DA8(void* self, FeTab* t, int k);
extern "C" FeScrN* fn_80517200(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_805174CC(void* x, int a, int b);
extern "C" void fn_80517C48(FeScrD* x);
extern "C" int fn_80517C70(void* x);
extern "C" int fn_80517CEC(void* x);
extern "C" int fn_80517D58(FeScrN* x);
extern "C" int fn_80517D98(FeScrN* x, int a);
extern "C" int fn_80517DD4(FeScrN* x);
extern "C" int fn_80517E14(FeScrN* x);
extern "C" void fn_8051840C(FeScrD* x);
extern "C" int fn_8051848C(FeScrN* x);
extern "C" int fn_805184C8(FeScrN* x);
extern "C" int fn_80518504(FeScrN* x);
extern "C" int fn_80518540(FeScrN* x);
extern "C" int fn_8051857C(FeScrF* x);
extern "C" int fn_805185B8(FeScrF* x);
extern "C" int fn_805185F4(FeScrF* x);
extern "C" int fn_80518630(FeScrF* x);
extern "C" int fn_8051866C(FeScrN* x);
extern "C" int fn_80518718(void* x);
extern "C" void fn_80517BD4(void* x, int a);
extern "C" void fn_80518434(void* x, int a);
extern "C" void fn_80518FF8(void* x, int i);
extern "C" void fn_80519038(FeScrN* x, int a);
extern "C" void fn_80516FEC(FeScrT* x);

extern "C" FE_OVERLAY void fn_80516990(int a, void* x)
{
    if (a == 1) {
        fn_8051667C(x);
    }
}

extern "C" FE_OVERLAY void fn_805169BC(int a, FeScrT* x)
{
    if (a == 1) {
        x->m2C0 = a;
        x->fn_vslot80(1);
        fn_800B7ADC(FeGetMgr(), x);
    }
}

extern "C" FE_OVERLAY int fn_80516A3C(FeScrT* x)
{
    return x->m2BC->fn_vslot86() != 0;
}

extern "C" FE_OVERLAY int fn_80516A84(FeScrT* x)
{
    return x->m2BC->fn_vslot87() != 0;
}

extern "C" FE_OVERLAY int fn_80516ACC(FeScrT* x)
{
    FeSubA* p = x->m2A8;
    if (p == (FeSubA*)((char*)x + 0x1EC)) {
        return fn_80516A3C(x);
    }
    return p == (FeSubA*)((char*)x + 0x134) ? fn_80516A84(x) : 0;
}

extern "C" FE_OVERLAY int fn_80516B1C(FeScrT* x)
{
    int r = 0;
    if (fn_80516A3C(x) != 0 || fn_80516A84(x) != 0) {
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_80516D24(FeScrT* x, char* dst)
{
    *dst = 0;
    if (x->m2C0 != 0) {
        *(FeS5*)dst = lbl_805F4450;
    }
}

extern "C" FE_OVERLAY void fn_80516D54(FeScrT* x, int a)
{
    fn_800ED310(x, a);
    x->m2A8->m94->fn_vslot14(a);
}

extern "C" FE_OVERLAY int fn_80516DA8(void* self, FeTab* t, int k)
{
    int n = t->m84;
    int i = 0;
    if (i < n) {
        int o = 0;
        do {
            int v = t->m78[k];
            char* b = (char*)t + 4;
            if (v == *(int*)(b + o)) {
                return i;
            }
            i++;
            o += 4;
        } while (i < n);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80516FEC(FeScrT* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
    int b = 0x4DA0;
    if (x->m2A8 == (FeSubA*)((char*)x + 0x134)) {
        b = 0x4D9F;
    }
    fn_80131F34(p, x, fn_80528524, 0, b, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY FeScrN* fn_80517200(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80669A50);
    FeI(self, 0x130) = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_805174CC(void* x, int a, int b)
{
    fn_80517518(x, a, ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B8C4(0, b));
}

extern "C" FE_OVERLAY void fn_80517BD4(void* x, int a)
{
    if (a == FeI(x, 0x134)) {
        int v = ((FeSub24*)((char*)FeP(x, 0x138) + 0xDC))->s11();
        fn_80517910(x, ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B8C4(0, v));
    }
}

extern "C" FE_OVERLAY void fn_80517C48(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_80517C70(void* x)
{
    if (((FeState0*)fn_800B555C())->m0 != 0x2F || fn_800B5898(fn_800B555C()) == 0) {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80517CEC(void* x)
{
    if (((FeState0*)fn_800B555C())->m0 == 0x2F) {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80517D58(FeScrN* x)
{
    x->m134->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80517D98(FeScrN* x, int a)
{
    x->m134->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_80517DD4(FeScrN* x)
{
    x->m134->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80517E14(FeScrN* x)
{
    x->m134->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY void fn_8051840C(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_80518434(void* x, int a)
{
    if (a == FeI(x, 0x13C)) {
        fn_80518784(x, a);
        fn_80518AAC(x);
        return;
    }
    if (a == FeI(x, 0x140)) {
        fn_80518AAC(x);
    }
}

extern "C" FE_OVERLAY int fn_8051848C(FeScrN* x)
{
    x->m138->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_805184C8(FeScrN* x)
{
    x->m138->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_80518504(FeScrN* x)
{
    x->m138->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_80518540(FeScrN* x)
{
    x->m138->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051857C(FeScrF* x)
{
    x->m138->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_805185B8(FeScrF* x)
{
    x->m138->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_805185F4(FeScrF* x)
{
    x->m138->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80518630(FeScrF* x)
{
    x->m138->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051866C(FeScrN* x)
{
    if (((FeState0*)fn_800B555C())->m0 == 0x2F) {
        if (FeI(x, 0x134) > -1) {
            fn_800B7ADC(FeGetMgr(), x);
        }
    } else {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80518718(void* x)
{
    if (((FeState0*)fn_800B555C())->m0 == 0x2F) {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_80518FF8(void* x, int i)
{
    char* b = (char*)x + 0x168;
    int o = i * 4;
    if (*(int*)(b + o) == 0) {
        *(int*)(b + o) = fn_805190D8(x);
    }
}

extern "C" FE_OVERLAY void fn_80519038(FeScrN* x, int a)
{
    ((FeSubV*)((char*)x->m154 + 0x98))->s20(a, 0);
    ((FeSubV*)((char*)x->m158 + 0x98))->s20(a, 0);
    ((FeSubV*)((char*)x->m15C + 0x98))->s20(a, 0);
}
