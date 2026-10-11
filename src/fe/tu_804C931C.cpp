/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C931C-0x804CB430 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern const char lbl_8066F0D0[];
extern const char lbl_8066EE28[];
extern const char lbl_80671198[];
extern "C" int fn_804CA1E8(void* x);
extern "C" int fn_804C9810(FeScrN* x);
extern "C" int fn_804C984C(FeScrN* x);
extern "C" int fn_804C9888(FeScrN* x);
extern "C" int fn_804C98C4(FeScrN* x);
extern "C" int fn_804C9900(FeScrN* x);
extern "C" int fn_804C993C(FeScrN* x);
extern "C" int fn_804C9978(FeScrN* x);
extern "C" int fn_804C99B4(FeScrN* x);
extern "C" FeScrN* fn_804CA3F8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804CA448(FeScrN* x);
extern "C" int fn_804CA788(FeScrN* x);
extern "C" int fn_804CA7C8(FeScrN* x);
extern "C" int fn_804CA804(FeScrN* x);
extern "C" int fn_804CA840(FeScrN* x);
extern "C" int fn_804CA87C(FeScrN* x);
extern "C" FeScrN* fn_804CA8B8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804CA908(FeScrN* self);
extern "C" int fn_804CB254(FeScrN* x);
extern "C" int fn_804CB290(FeScrN* x);
extern "C" int fn_804CB2CC(FeScrN* x);
extern "C" int fn_804CB308(FeScrN* x);
extern "C" FeScrN* fn_804CB3DC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_804CA2F0(void* x);
extern "C" void fn_804CA328(FeScrN* x, int a);
extern "C" int fn_804CA38C(FeScrN* x, int a);

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

/* near-miss: 2 slots (retail compares `cmpwi r3,4; bge`, we emit `cmpwi r3,3; bgt`). The
 * comma form below is the closest of ~14 spellings of `n >= 4 && n <= 5`. */
extern "C" FE_OVERLAY int fn_804CA2F0(void* x)
{
    int n = fn_804CA1E8(x);
    int r;
    if (n > 5 || (r = 1, n < 4)) {
        r = 0;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804CA328(FeScrN* x, int a)
{
    if (a == (int)x->m150) {
        if (fn_804CA2F0(x) != 0) {
            fn_801251CC(x->m164, 0, 0x10, 3);
            return;
        }
        fn_80125084(x->m164, 0);
    }
}

extern "C" FE_OVERLAY int fn_804CA38C(FeScrN* x, int a)
{
    if (a == (int)x->m150 && fn_804CA2F0(x) != 0) {
        x->fn_vslot67(3, 0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY FeScrN* fn_804CA3F8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066F0D0);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804CA448(FeScrN* x)
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

extern "C" FE_OVERLAY FeScrN* fn_804CB3DC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80671198);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}
