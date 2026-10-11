/*
 * Front-end overlay code, .frontend_codeoverlay 0x8044F550-0x80452120 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern char lbl_8067C328[];
extern "C" FE_OVERLAY FeScrRaw* fn_8044F634(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067C328;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_8044F984(FeW138* self)
{
    self->m138->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044F9C0(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044F9FC(FeW138* self)
{
    self->m138->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044FA38(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY void fn_8045055C(void* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "EDIT", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), &m, self);
}

extern "C" FE_OVERLAY int fn_80450C44(void)
{
    return 1;
}
