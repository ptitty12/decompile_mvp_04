/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E02E0-0x804E1A6C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

extern "C" void fn_804D32A0(void* menu, int a);

extern "C" FE_OVERLAY int fn_804E0498(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern char lbl_8066CFA0[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E059C(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066CFA0;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_804E08B0(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY void fn_804E0B8C(void* self, int a)
{
    fn_804D32A0(self, a);
}

extern "C" FE_OVERLAY int fn_804E0EF4(void)
{
    return 1;
}
