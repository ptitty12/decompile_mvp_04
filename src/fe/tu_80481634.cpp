/*
 * Front-end overlay code, .frontend_codeoverlay 0x80481634-0x8048511C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

extern "C" FE_OVERLAY FeScrH* fn_80481634(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80677AC0);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x154) = 0;
    FeI(self, 0x158) = 0;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = 0;
    FeI(self, 0x164) = 0;
    FeI(self, 0x168) = 0;
    FeI(self, 0x16C) = 0;
    FeI(self, 0x170) = -1;
    FeI(self, 0x174) = -1;
    FeI(self, 0x240) = 0;
    FeI(self, 0x244) = 1;
    FeI(self, 0x248) = 1;
    FeI(self, 0x24C) = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_804828CC(void* x)
{
    FeAt(x, 0x16C)->fn_vslot50();
    fn_80483094(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8048291C(void* x)
{
    FeAt(x, 0x16C)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80482958(void* x)
{
    FeAt(x, 0x16C)->fn_vslot52();
    fn_80483094(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804829A8(void* x)
{
    FeAt(x, 0x16C)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_80482A9C(void* x)
{
    FeAt(x, 0x144)->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80482ADC(void* x, int a)
{
    FeAt(x, 0x144)->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_80482B18(void* x)
{
    FeAt(x, 0x144)->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80482B58(void* x)
{
    FeAt(x, 0x144)->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_80482B94(void* x)
{
    if (FeI(x, 0x244) != 0) {
        FeWp(x, 0x148)->fn_vslot40(1);
        fn_80482D1C(x);
        fn_80483094(x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80482C58(void* x)
{
    if (FeI(x, 0x244) != 0) {
        FeWp(x, 0x148)->fn_vslot38(1);
        fn_80482D1C(x);
        fn_80483094(x);
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_804832BC(void* x, int a, int b)
{
    fn_804834AC(x, b);
    fn_80483094(x);
}

extern "C" FE_OVERLAY int fn_804832F4(void* x, int a, int b, int c)
{
    if (a == FeI(x, 0x13C)) {
        int t = FeI(x, 0x170);
        if ((t == -1 && FeI(x, 0x174) == -1) || t == c)
            fn_80484178(x, c);
        fn_80483708(x, FeI(x, 0x13C));
    } else if (a == FeI(x, 0x140)) {
        if (FeI(x, 0x170) == -1 && (FeI(x, 0x174) == -1 || FeI(x, 0x174) == c))
            fn_8048432C(x, c);
        fn_80483708(x, FeI(x, 0x140));
    }
    fn_80483094(x);
    return 0;
}

extern "C" FE_OVERLAY void fn_80483654(void* x, int a)
{
    FeI(x, 0x138) = a;
    FeW* w = FeWp(x, 0x158);
    ((FeSubB*)((char*)w + 0xDC))->s6();
    fn_80483A9C(x);
    FeWp(x, 0x16C)->fn_vslot68(0);
    FeWp(x, 0x13C)->fn_vslot14(0);
    FeWp(x, 0x140)->fn_vslot14(0);
}

extern "C" FE_OVERLAY int fn_8048495C(void* x)
{
    if (FeI(x, 0x16C) == FeI(x, 0x13C)) {
        if (FeWp(x, 0x164)->fn_vslot86() != 0)
            return 1;
    }
    if (FeI(x, 0x16C) == FeI(x, 0x140)) {
        if (FeWp(x, 0x164)->fn_vslot87() != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80484A78(void* x, int a)
{
    int i;
    int n = FeWp(x, 0x13C)->fn_vslot59();
    for (i = 0; i < n; i++) {
        int o = i * 4;
        char* b = (char*)x + 0x178;
        if (*(int*)(b + o) == 0)
            ((FeWV*)FeWp(x, 0x13C))->s101(i, a);
    }
}
