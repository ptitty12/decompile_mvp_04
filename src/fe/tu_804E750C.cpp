/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E750C-0x804EA2E4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

extern "C" FE_OVERLAY void fn_804E7860(void* self, int a)
{
    fn_800ECAA4(self);
}

extern "C" FE_OVERLAY int fn_804E7880(FeS7* self)
{
    if (self->m140->m24 & 0x40000000) {
        int a = ((FeObjK*)self->m140)->v60();
        if (a == ((FeObjK*)self->m140)->v59() - 1)
            fn_804E7D44(self, 0);
        else
            fn_804E7D44(self, 1);
    } else
        ((FeObj2*)self)->v67(0, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7940(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v50();
    else
        self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E79A8(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v51();
    else
        self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7A10(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v52();
    else
        self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7A78(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v53();
    else
        self->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7AE0(FeWf134* self)
{
    self->m134->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7B1C(FeWf134* self)
{
    self->m134->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7B58(FeWf134* self)
{
    self->m134->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7B94(FeWf134* self)
{
    self->m134->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7BD0(void)
{
    return 0;
}

extern char lbl_8066BA30[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E80FC(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066BA30;
    self->m130 = 0;
    self->m134 = -1;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m160 = -1;
    self->m16C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E8640(void)
{
}

extern "C" FE_OVERLAY void fn_804E8B40(void)
{
}

extern "C" FE_OVERLAY void fn_804E8C20(void)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "USERPROFEDIT");
    ((FeObj1*)p)->v16(1);
    ((FeObj1*)p)->v8(1);
}

extern "C" FE_OVERLAY void fn_804E8CB4(FeS9* self)
{
    self->m13C->v28();
    fn_804E8644(self);
}

extern "C" FE_OVERLAY void fn_804E9220(FeS7* self)
{
    fn_800E29CC((int)self->m134);
}

extern "C" FE_OVERLAY void fn_804E9244(FeS7* self, int a)
{
    fn_800ED310(self, a);
    if (a != 0)
        ((FeObj1*)self->m138)->v14(1);
    else
        ((FeObj1*)self->m138)->v14(0);
}

extern "C" FE_OVERLAY int fn_804E92C0(FeS11* self)
{
    self->m138->v50();
    int a = ((FeObjK*)self->m138)->v60() + 1;
    if (a == ((FeObjK*)self->m138)->v59() || ((FeObjK*)self->m138)->v60() == 0)
        fn_801251CC(self->m164, 0, 16, 0);
    else
        fn_80125084(self->m164, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E9394(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E93D0(FeS11* self)
{
    self->m138->v52();
    int a = ((FeObjK*)self->m138)->v60() + 1;
    if (a == ((FeObjK*)self->m138)->v59() || ((FeObjK*)self->m138)->v60() == 0)
        fn_801251CC(self->m164, 0, 16, 0);
    else
        fn_80125084(self->m164, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E94A4(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E94E0(FeWf138* self)
{
    self->m138->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E951C(FeWf138* self)
{
    self->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E9558(FeWf138* self)
{
    self->m138->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E9594(FeWf138* self)
{
    self->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E95D0(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804E95D8(FeS8* self, int a)
{
    if (a == self->m144) {
        fn_800D0074(&self->m158->mDC, ((FeSub*)&self->m148->mDC)->s11(), 0);
        fn_800D0074(&self->m15C->m98, ((FeSub*)&self->m148->mDC)->s11(), 0);
    }
}

extern char lbl_8066B788[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E9810(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066B788;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E9868(FeS7* self)
{
    fn_800ECE34(self);
    self->m134 = fn_800C8060(self->v32("PROFILES", 1));
    ((FeObj1*)self->m134)->v105(1);
    self->m138 = fn_800C8044(self->v32("INFO", 1));
    if (fn_800B555C()->m0 == 0x4D)
        self->m13C = 1;
    else if (fn_800B555C()->m4 & 0x200)
        self->m13C = 2;
}

extern "C" FE_OVERLAY int fn_804E9C20(FeS7* self)
{
    int r;
    if (self->m13C != 0)
        r = ((FeObjK*)self->m134)->v60();
    else
        r = ((FeObjK*)self->m134)->v60() - 1;
    return r;
}

extern "C" FE_OVERLAY void fn_804EA038(FeS7* self, int a)
{
    if (a == (int)self->m134)
        fn_800E26B4(fn_804E9C20(self), (int)self->m138);
}

extern "C" FE_OVERLAY int fn_804EA078(FeScr_80447264* self)
{
    self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA0B4(FeScr_80447264* self)
{
    self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA0F0(FeScr_80447264* self)
{
    self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA12C(FeScr_80447264* self)
{
    self->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA168(void)
{
    return 0;
}
