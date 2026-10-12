/*
 * Front-end overlay code, .frontend_codeoverlay 0x804FF6B4-0x805002DC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

extern const char lbl_80680C08[];
extern const char lbl_805FA738[];
extern "C" int fn_804FF6B4(FeScrB* x);
extern "C" void fn_804FF834(FeScrD* x);
extern "C" int fn_804FF8F8(FeS1EC* x, int a);
extern "C" void fn_804FFBA8();
extern "C" FeScrN* fn_804FFCB4(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_804FFDBC(FeScrF* x);
extern "C" int fn_804FFDF8(FeScrF* x);
extern "C" int fn_804FFE34(FeScrF* x);
extern "C" int fn_804FFE70(FeScrF* x);
extern "C" int fn_804FFEAC(FeScrN* x);
extern "C" void fn_80500030(void* x);

extern "C" FE_OVERLAY int fn_804FF6B4(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY void fn_804FF834(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY int fn_804FF8F8(FeS1EC* x, int a)
{
    x->m1EC = a;
    return 1;
}

extern "C" FE_OVERLAY void fn_804FFBA8()
{
}

extern "C" FE_OVERLAY FeScrN* fn_804FFCB4(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80680C08);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_804FFDBC(FeScrF* x)
{
    x->m138->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FFDF8(FeScrF* x)
{
    x->m138->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FFE34(FeScrF* x)
{
    x->m138->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FFE70(FeScrF* x)
{
    x->m138->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FFEAC(FeScrN* x)
{
    x->fn_vslot67(1, 0);
    return 1;
}

extern "C" FE_OVERLAY void fn_80500030(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805FA738, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}
