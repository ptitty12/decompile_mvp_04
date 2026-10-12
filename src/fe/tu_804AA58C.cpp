/*
 * Front-end overlay code, .frontend_codeoverlay 0x804AA58C-0x804ABCBC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" {

FE_OVERLAY void fn_804AAA28(void* x, int a)
{
    switch (a) {
    case 0:
        fn_804AAEB0(x);
        break;
    case 1:
        fn_804AAF34(x);
        break;
    case 2:
        fn_804AAFE8(x);
        break;
    case 3:
        fn_804AB0C8(x);
        break;
    case 4:
        fn_804AB188(x);
        break;
    }
}

FE_OVERLAY void fn_804AAA9C(void* x, int a)
{
    if (a == FeI(x, 0x140)) {
        fn_804AB774(x);
        fn_804AB860(x);
    }
}

FE_OVERLAY int fn_804AABD8(void* x)
{
    FeMem(x, 0x140)->fn_vslot50();
    return 0;
}

FE_OVERLAY int fn_804AAC14(void* x)
{
    FeMem(x, 0x140)->fn_vslot51();
    return 0;
}

FE_OVERLAY int fn_804AAC50(void* x)
{
    FeMem(x, 0x140)->fn_vslot52();
    return 0;
}

FE_OVERLAY int fn_804AAC8C(void* x)
{
    FeMem(x, 0x140)->fn_vslot53();
    return 0;
}

FE_OVERLAY int fn_804AACC8(void* x)
{
    FeMem(x, 0x140)->fn_vslot56();
    return 0;
}

FE_OVERLAY int fn_804AAD04(void* x)
{
    FeMem(x, 0x140)->fn_vslot57();
    return 0;
}

FE_OVERLAY int fn_804AAD40(void* x)
{
    FeMem(x, 0x140)->fn_vslot54();
    return 0;
}

FE_OVERLAY int fn_804AAD7C(void* x)
{
    FeMem(x, 0x140)->fn_vslot55();
    return 0;
}

FE_OVERLAY int fn_804AADB8(void* x)
{
    FeMem(x, 0x144)->fn_vslot40(1);
    return 1;
}

FE_OVERLAY int fn_804AADF8(void* x)
{
    ((FeWV*)FeMem(x, 0x144))->s41();
    return 1;
}

FE_OVERLAY int fn_804AAE34(void* x)
{
    FeMem(x, 0x144)->fn_vslot38(1);
    return 1;
}

FE_OVERLAY int fn_804AAE74(void* x)
{
    FeMem(x, 0x144)->fn_vslot39();
    return 1;
}

/* near-miss (2 slots): retail stores the vptr before addi r3,self+0x144; all 5040 statement orders tried. */
FE_OVERLAY FeScrM* fn_804AB940(FeScrM* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80674328);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m1C4 = 0;
    self->m1C8 = -1;
    fn_8040B320(self->m144, 0, 0x80);
    return self;
}

FE_OVERLAY int fn_804ABBCC(void* x)
{
    FeMem(x, 0x134)->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804ABC08(void* x)
{
    FeMem(x, 0x134)->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804ABC44(void* x)
{
    FeMem(x, 0x134)->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804ABC80(void* x)
{
    FeMem(x, 0x134)->fn_vslot53();
    return 1;
}

}
