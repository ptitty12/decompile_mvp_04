/*
 * Front-end overlay code, .frontend_codeoverlay 0x804AA58C-0x804ABCBC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" {

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
