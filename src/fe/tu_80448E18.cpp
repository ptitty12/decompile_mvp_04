/*
 * Front-end overlay code, .frontend_codeoverlay 0x80448E18-0x8044C508 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern char lbl_8067D760[];
extern "C" FE_OVERLAY FeScrRaw* fn_80448E18(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067D760;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80448E64(void* self)
{
    fn_800ECE34(self);
}

extern "C" FE_OVERLAY void fn_80448E84(void* self)
{
    fn_800ECF18(self);
}

extern "C" FE_OVERLAY int fn_80448EA4(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80448EAC(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80448EB4(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80448EBC(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80448EC4(void* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_80448F20(void* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_80448F7C(void* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_80448FD8(void* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern char lbl_8067D478[];
extern "C" FE_OVERLAY FeMeterRaw* fn_80449034(FeMeterRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC150(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067D478;
    self->m2DC = 0;
    self->m2E0 = 0;
    self->m2E4 = 0;
    self->m2E8 = 0;
    self->m2EC = 0x3C;
    self->m2F0 = 0.0f;
    self->m2F4 = 0;
    self->m2F8 = 0;
    self->m2FC = 0;
    self->m300 = 0;
    self->m304 = 0;
    self->m308 = 0;
    self->m30C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804490BC(FeMeter* self)
{
    ((FeObj1*)self)->v8(0);
    ((FeObj1*)self)->v16(0);
    FeObj* bar = ((FeObj*)self)->v32("METERBAR", 1);
    self->m304 = bar;
    self->m2E0 = bar->m2A;
    ((FeObj1*)bar)->v12(0);
}

extern "C" FE_OVERLAY void fn_80449300(FeMeter* self)
{
    ((FeObj*)self)->v87();
    if (self->m308 != 0)
        self->m308(self->m30C);
}

extern char lbl_8067D1D0[];
extern "C" FE_OVERLAY FeScrRawL* fn_8044974C(FeScrRawL* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648((FeScrRaw*)self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067D1D0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m16C = -1;
    self->m170 = -1;
    self->m174 = 0;
    self->m240 = 0;
    self->m244 = 0;
    self->m248 = 1;
    return self;
}

extern "C" FE_OVERLAY int fn_8044A8D8(FeScr_8044974C* self)
{
    self->m168->v50();
    fn_8044B050(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_8044A928(FeScr_8044974C* self)
{
    self->m168->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044A964(FeScr_8044974C* self)
{
    self->m168->v52();
    fn_8044B050(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_8044A9B4(FeScr_8044974C* self)
{
    self->m168->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044A9F0(FeScr_8044974C* self)
{
    if (self->m168 != self->m13C)
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    fn_8044B6A4(self, self->m13C);
    fn_8044B050(self);
    return 0;
}

extern "C" FE_OVERLAY int fn_8044AA4C(FeScr_8044974C* self)
{
    if ((self->m140->m24 & 0x40000000) != 0) {
        if (self->m168 != self->m140)
            fn_8001BC4C()->fn_8001BDAC(0x9C);
        fn_8044B6A4(self, self->m140);
        fn_8044B050(self);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8044AAB4(FeScr_8044974C* self)
{
    ((FeObj1*)self->m144)->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8044AAF4(FeScr_8044974C* self)
{
    self->m144->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044AB30(FeScr_8044974C* self)
{
    ((FeObj1*)self->m144)->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8044AB70(FeScr_8044974C* self)
{
    self->m144->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044ABAC(FeScr_8044974C* self)
{
    ((FeObj1*)self->m148)->v40(1);
    fn_8044AD04(self);
    fn_8044B050(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_8044AC08(FeScr_8044974C* self)
{
    self->m148->v41();
    fn_8044AD04(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_8044AC58(FeScr_8044974C* self)
{
    ((FeObj1*)self->m148)->v38(1);
    fn_8044AD04(self);
    fn_8044B050(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_8044ACB4(FeScr_8044974C* self)
{
    self->m148->v39();
    fn_8044AD04(self);
    return 1;
}

extern "C" FE_OVERLAY void fn_8044B278(FeScr_8044974C* self, int a, int b)
{
    fn_8044B454(self, b);
    fn_8044B050(self);
}
