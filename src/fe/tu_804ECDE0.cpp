/*
 * Front-end overlay code, .frontend_codeoverlay 0x804ECDE0-0x804F81E0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

extern char lbl_8067F178[];

extern "C" FE_OVERLAY FeScrRaw* fn_804ECDE0(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067F178;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_804F7DF8(FeWf604b* self)
{
    self->m604->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804F7E38(FeWf604* self)
{
    self->m604->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804F7E74(FeWf604b* self)
{
    self->m604->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804F7EB4(FeWf604* self)
{
    self->m604->v39();
    return 1;
}
