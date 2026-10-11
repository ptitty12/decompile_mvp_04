/*
 * Front-end overlay code, .frontend_codeoverlay 0x80446CE8-0x80448E18 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern "C" FE_OVERLAY int fn_80446CE8(FeScr* self)
{
    self->m138->v51();
    self->m13C->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80446D4C(FeScr* self)
{
    self->m138->v50();
    self->m13C->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80446DB0(FeScr* self)
{
    self->m138->v53();
    self->m13C->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_80446E14(FeScr* self)
{
    self->m138->v52();
    self->m13C->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80446E78(FeScr* self)
{
    self->m138->v57();
    self->m13C->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_80446EDC(FeScr* self)
{
    self->m138->v56();
    self->m13C->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_80446F40(FeScr* self)
{
    self->m138->v55();
    self->m13C->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_80446FA4(FeScr* self)
{
    self->m138->v54();
    self->m13C->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_80447008(FeScr* self)
{
    self->m134->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_80447044(FeScr* self)
{
    ((FeObj1*)self->m134)->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80447084(FeScr* self)
{
    self->m134->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804470C0(FeScr* self)
{
    ((FeObj1*)self->m134)->v38(1);
    return 1;
}

extern char lbl_8067DCB0[];
extern "C" FE_OVERLAY FeScrRaw* fn_80447100(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067DCB0;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8044714C(void* self)
{
    fn_800ECE34(self);
}

extern "C" FE_OVERLAY void fn_8044716C(void* self)
{
    fn_800ECF18(self);
}

extern "C" FE_OVERLAY int fn_8044718C(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80447194(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8044719C(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_804471A4(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_804471AC(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_80447208(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern char lbl_8067DA08[];
extern "C" FE_OVERLAY FeScrRaw* fn_80447264(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067DA08;
    self->m130 = 0;
    self->m134 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m15C = 0;
    self->m160 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804472D4(FeScr_80447264* self)
{
    fn_800ECE34(self);
    self->m134 = fn_800C8060(((FeObj*)self)->v32("CELL", 1));
    self->m13C = fn_800C8058(((FeObj*)self)->v32("ROUND", 1));
    self->m140 = fn_800C805C(((FeObj*)self)->v32("ROUNDSG", 1));
}

extern "C" FE_OVERLAY int fn_80447D64(FeScr_80447264* self)
{
    if (self->m158 != 0) {
        fn_80131F34(self->m14C, self, (FeCb)fn_80447E60, 0, 0x4D9C, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
        self->m14C->v86();
    } else {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_80447E60(int a, FeScr_80447264* self)
{
    if (a != 0) {
        if (self->m150 == 0 && (self->m154 == 1 || fn_800B555C()->m588 != 0))
            fn_800E4B70();
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
    }
}

extern "C" FE_OVERLAY void fn_80447F18(FeScr_80447264* self, int a)
{
    if (a == 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        if (self->m144->m24 < 0)
            fn_80448480(self);
        else
            fn_80448334(self);
    }
}

extern "C" FE_OVERLAY int fn_80447F78(FeScr_80447264* self)
{
    self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80447FB4(FeScr_80447264* self)
{
    self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80447FF0(FeScr_80447264* self)
{
    self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044802C(FeScr_80447264* self)
{
    self->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_80448068(FeScr_80447264* self)
{
    if (self->m150 != 0 && self->m15C != 0)
        ((FeObj1*)self->m140)->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804480C0(FeScr_80447264* self)
{
    if (self->m150 != 0 && self->m15C != 0)
        self->m140->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_80448114(FeScr_80447264* self)
{
    if (self->m150 != 0 && self->m15C != 0)
        ((FeObj1*)self->m140)->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8044816C(FeScr_80447264* self)
{
    if (self->m150 != 0 && self->m15C != 0)
        self->m140->v39();
    return 1;
}

extern "C" FE_OVERLAY void fn_804481C0(FeScr_80447264* self)
{
    self->m160 = (int)((FeObjF*)self->m13C)->v58();
}

extern "C" FE_OVERLAY void fn_80448214(FeScr_80447264* self)
{
    if ((int)((FeObjF*)self->m13C)->v58() != self->m160)
        fn_80448528(self);
    if (((FeObjI*)self->m134)->v61() != 2)
        ((FeObj1*)self->m134)->v69(2);
}

extern "C" FE_OVERLAY void fn_804482BC(FeScr_80447264* self, int a)
{
    if (self->m144->m24 < 0 && a == (int)self->m140)
        fn_80448334(self);
}

extern "C" FE_OVERLAY void fn_804482F8(FeScr_80447264* self, int a)
{
    if (self->m144->m24 < 0 && a == (int)self->m134)
        fn_80448334(self);
}

extern "C" FE_OVERLAY void fn_80448334(FeScr_80447264* self)
{
    int cat = fn_800A1960(lbl_80619948);
    int idx = (int)((FeObjF*)self->m13C)->v58() - 1;
    int r = fn_80546B18(cat, ((FeObjI*)self->m134)->v60(), idx);
    if (r == 0) {
        fn_80448480(self);
        return;
    }
    ((FeObj2*)self->m144)->v84(1, 0);
    FePopup* q = self->m144;
    fn_80126CF4(q, q->m164, r, q->m134, q->m16C, q->m170, 0, q->m138, q->m13C, q->m148, q->m14C);
    fn_801251CC(fn_800B7A94(UiGetMsgMgr(), "NAVBAR"), 3, 0x37A2, 0);
}

extern "C" FE_OVERLAY void fn_80448480(FeScr_80447264* self)
{
    FePopup* q = self->m144;
    fn_80126CF4(q, q->m164, 0, q->m134, q->m16C, q->m170, 0, q->m138, q->m13C, q->m148, q->m14C);
    fn_801251CC(fn_800B7A94(UiGetMsgMgr(), "NAVBAR"), 3, 0x1A2F, 0);
}

extern "C" FE_OVERLAY void fn_80448D68(int a, FeScr_80447264* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    if (self->m150 != 0 && fn_800B5758(fn_800B555C()) != 0) {
        fn_8040B830(p->name, "ADVANCE_OWNER", 15);
        p->name[15] = 0;
    } else {
        fn_8040B830(p->name, "ADVANCE", 15);
        p->name[15] = 0;
    }
    fn_800B7B4C(UiGetMsgMgr(), &m, self);
}
