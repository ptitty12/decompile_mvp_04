/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C931C-0x804CB430 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern const char lbl_8066F0D0[];
extern const char lbl_8066EE28[];

extern "C" FE_OVERLAY int fn_804C9810(FeScrN* x)
{
    x->m150->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C984C(FeScrN* x)
{
    x->m150->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C9888(FeScrN* x)
{
    x->m150->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C98C4(FeScrN* x)
{
    x->m150->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C9900(FeScrN* x)
{
    x->m150->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C993C(FeScrN* x)
{
    x->m150->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C9978(FeScrN* x)
{
    x->m150->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C99B4(FeScrN* x)
{
    x->m150->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY void fn_804CA0A8(void) {}

extern "C" FE_OVERLAY FeScrN* fn_804CA3F8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066F0D0);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804CA448(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY int fn_804CA788(FeScrN* x)
{
    x->fn_vslot67(1, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA7C8(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA804(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA840(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA87C(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY FeScrN* fn_804CA8B8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066EE28);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804CA908(FeScrN* self)
{
    self->SetVptr(lbl_8066EE28);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_804CB254(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CB290(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CB2CC(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CB308(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}
