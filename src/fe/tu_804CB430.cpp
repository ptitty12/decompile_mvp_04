/*
 * Front-end overlay code, .frontend_codeoverlay 0x804CB430-0x804CE408 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern const char lbl_80670EF0[];
extern const char lbl_80672168[];
extern "C" void fn_804CD878(FeScrE0C* x);
extern const char lbl_8066EB80[];

extern "C" FE_OVERLAY int fn_804CD194(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD1D0(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD20C(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD248(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY void fn_804CD2FC(FeScrE0C* x)
{
    x->SetVptr(lbl_80670EF0);
    x->mE04 = lbl_80672168;
    fn_8035686C(x);
}

extern "C" FE_OVERLAY int fn_804CD754(FeScrE0C* x)
{
    x->mE0C->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD794(FeScrE0C* x)
{
    x->mE0C->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD7D0(FeScrE0C* x)
{
    x->mE0C->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804CD810(FeScrE0C* x, int a)
{
    x->mE0C->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY void fn_804CD84C(FeScrE0C* x, int a)
{
    if (a == (int)x->mE0C) {
        fn_804CD878(x);
    }
}

extern "C" FE_OVERLAY FeScrH* fn_804CDE24(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066EB80);
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804CDE70(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_804CDE90(FeScrH* x)
{
    fn_800ECF18(x);
    void* w = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(w, x);
    fn_801250D8(w);
}

extern "C" FE_OVERLAY void fn_804CDF04(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_804CDF24(FeScrD* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY void fn_804CDF44(void) {}

extern "C" FE_OVERLAY void fn_804CDF48(void) {}

extern "C" FE_OVERLAY void fn_804CDF4C(void) {}

extern "C" FE_OVERLAY int fn_804CDF50(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804CDFAC(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804CDFB4(int a, char* dst)
{
    fn_8040B830(dst, lbl_805F3CA8, 16);
}

extern "C" FE_OVERLAY void fn_804CDFE4(FePair* p)
{
    p->a = 0x23;
    p->b = 0;
}

extern "C" FE_OVERLAY void fn_804CDFF8(FePair* p, int a, int b)
{
    p->b = b;
    p->a = a;
}

extern "C" FE_OVERLAY int fn_804CE0C8(int k)
{
    switch (k) {
    case 0:
        return 0x4637;
    case 2:
        return 0x4635;
    case 4:
        return 0x4636;
    default:
        return 0x4637;
    }
}
