/*
 * Front-end overlay code, .frontend_codeoverlay 0x8044C508-0x8044F550 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern "C" void fn_80444890(FeX24* self);
extern "C" FE_OVERLAY void fn_8044C77C(FeX24* self)
{
    ((FeObj1*)self->m24)->v8(0);
    fn_80444890(self);
}

extern "C" FE_OVERLAY void fn_8044D3D8(FeX14* self)
{
    int v = lbl_8061930C->fn_80078A38(lbl_8062163C);
    fn_8007FDA8((Unk8007F198_C*)lbl_8061930C, self->m14, v);
}

extern "C" FE_OVERLAY void* fn_8044DBC0(char* base, int idx)
{
    int r = idx / 7;
    return base + (r * 0x118 + 0x174) + (idx - r * 7) * 0x28;
}

extern "C" FE_OVERLAY void* fn_8044DC00(char* base, int a, int b)
{
    return base + (a * 0x118 + 0x174) + b * 0x28;
}

extern "C" FE_OVERLAY void fn_8044E398(int a, FeObj* o)
{
    if (a == 0)
        ((FeObj2*)o)->v67(0, 0);
}

/*
 * Front-end overlay code, .frontend_codeoverlay 0x8044C508-0x8044F550 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */


extern char lbl_8067C5D0[];
extern "C" FE_OVERLAY FeScrRaw* fn_8044EB7C(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067C5D0;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_8044F0D4(FeW138* self)
{
    self->m138->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044F110(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044F14C(FeW138* self)
{
    self->m138->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044F188(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY void fn_8044F4CC(void* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "DONE", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), &m, self);
}
