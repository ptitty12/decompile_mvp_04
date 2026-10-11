/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C713C-0x804C931C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern "C" void fn_804C92B0(FeScrD* x);
extern "C" void fn_804C81A0(FeScrD* x);
extern "C" void fn_804C8634(void* x);
extern const char lbl_805F8060[];
extern const char lbl_805F806C[];
extern "C" void fn_804C7FE4(FeScrD* x);
extern const char lbl_8066F378[];

extern "C" FE_OVERLAY void fn_804C7724(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_804C7744(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_804C77C0(FeScrN* x)
{
    x->m138->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C77FC(FeScrN* x)
{
    x->m138->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C7838(FeScrN* x)
{
    x->m138->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C7874(FeScrN* x)
{
    x->m138->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C78B0(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78B8(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78C0(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78C8(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78D0(FeScrN* x, int a)
{
    if (a == (int)x->m138) {
        fn_804C92B0((FeScrD*)x);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804C7900(FeScrN* x, FeW* w, int c, int d)
{
    if ((int)w == (int)x->m138) {
        w->fn_vslot68(d);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804C794C(FeScrD* x)
{
    fn_804C92B0(x);
}

extern "C" FE_OVERLAY void fn_804C796C(FeScrD* x)
{
    fn_804C81A0(x);
}

extern "C" FE_OVERLAY void fn_804C798C(void) {}

extern "C" FE_OVERLAY void fn_804C7990(FeScrJ* x, int a)
{
    fn_800ED310(x, a);
    x->m138->fn_vslot14(a);
}

extern "C" FE_OVERLAY void fn_804C85BC()
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F522C);
    p->m30C = (void*)fn_804C8634;
    fn_8049ABD4(p);
}

extern "C" FE_OVERLAY void fn_804C8634()
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F8060);
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F806C, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, p);
}

extern "C" FE_OVERLAY void fn_804C92B0(FeScrD* x)
{
    fn_804C7FE4(x);
}

extern "C" FE_OVERLAY FeScrH* fn_804C92D0(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066F378);
    self->m130 = 0;
    return self;
}
