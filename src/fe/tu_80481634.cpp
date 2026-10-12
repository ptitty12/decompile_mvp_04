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

extern "C" FE_OVERLAY int fn_80482348(void* x)
{
    if (fn_804849FC(x) != 0)
        return 0;
    int idx = FeWp(x, 0x16C)->fn_vslot60();
    FeW* cur = FeWp(x, 0x16C);
    if (cur == FeWp(x, 0x13C))
        fn_80484178(x, idx);
    else if (cur == FeWp(x, 0x140))
        fn_8048432C(x, idx);
    return 1;
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

extern "C" FE_OVERLAY int fn_804829E4(void* x)
{
    if (FeI(x, 0x16C) != FeI(x, 0x13C))
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    fn_80483708(x, FeI(x, 0x13C));
    fn_80483094(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_80482A40(void* x)
{
    if (FeI(x, 0x16C) != FeI(x, 0x140))
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    fn_80483708(x, FeI(x, 0x140));
    fn_80483094(x);
    return 0;
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

extern "C" FE_OVERLAY int fn_80482BFC(void* x)
{
    if (FeI(x, 0x244) != 0) {
        ((FeWV*)FeWp(x, 0x148))->s41();
        fn_80482D1C(x);
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

extern "C" FE_OVERLAY int fn_80482CC0(void* x)
{
    if (FeI(x, 0x244) != 0) {
        ((FeWV*)FeWp(x, 0x148))->s39();
        fn_80482D1C(x);
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_80482D1C(void* x)
{
    FeW* a = FeWp(x, 0x15C);
    int v = ((FeSubB*)((char*)a + 0xDC))->s5();
    fn_800D0074((char*)FeWp(x, 0x14C) + 0x98, v, 1);
    fn_800D0074((char*)FeWp(x, 0x150) + 0xDC, v, 1);
    FeW* b = FeWp(x, 0x14C);
    fn_804834AC(x, ((FeSubC*)((char*)b + 0x98))->s21());
}

extern "C" FE_OVERLAY void fn_804831CC(void* x, FeW* w)
{
    if (w == FeWp(x, 0x144)) {
        FeW* a = FeWp(x, 0x150);
        fn_804834AC(x, ((FeSubC*)((char*)a + 0xDC))->s21());
    } else if (w == FeWp(x, 0x148)) {
        FeW* a = FeWp(x, 0x15C);
        int v = ((FeSubB*)((char*)a + 0xDC))->s5();
        fn_800D0074((char*)FeWp(x, 0x14C) + 0x98, v, 1);
        fn_800D0074((char*)FeWp(x, 0x150) + 0xDC, v, 1);
        FeW* b = FeWp(x, 0x14C);
        fn_804834AC(x, ((FeSubC*)((char*)b + 0x98))->s21());
    }
    fn_80483094(x);
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

extern "C" FE_OVERLAY int fn_804833B4(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x13C)) {
        fn_80483708(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    } else if (w == FeWp(x, 0x140)) {
        fn_80483708(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
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

extern "C" FE_OVERLAY void fn_80483708(void* x, int wi)
{
    FeW* w = (FeW*)wi;
    FeWp(x, 0x13C)->fn_vslot14(0);
    FeWp(x, 0x140)->fn_vslot14(0);
    FeWp(x, 0x16C) = w;
    w->fn_vslot14(1);
    if (w == FeWp(x, 0x13C))
        FeWp(x, 0x164)->fn_vslot84(0, 0);
    else if (w == FeWp(x, 0x140))
        FeWp(x, 0x164)->fn_vslot84(1, 0);
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

extern "C" FE_OVERLAY int fn_804849FC(void* x)
{
    int r = 0;
    if (FeWp(x, 0x164)->fn_vslot86() != 0 || FeWp(x, 0x164)->fn_vslot87() != 0)
        r = 1;
    return r;
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

extern "C" FE_OVERLAY void fn_80484B18(void* x, int a)
{
    int i = 0;
    int o = 0;
    for (; i < FeWp(x, 0x140)->fn_vslot59(); i++) {
        if (FePick((char*)x + 0x1DC, o) == 0) {
            int j;
            for (j = 0; j < FeWp(x, 0x140)->fn_vslot58(); j++)
                ((FeWV91*)FeWp(x, 0x140))->s91(i, j, a);
        }
        o += 4;
    }
}

extern "C" FE_OVERLAY void fn_80485008(int a, void* x)
{
    if (a != 0) {
        if (a == 1) {
            if (fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x240)) == 0) {
                fn_8055F5A0(FeI(x, 0x240));
            } else {
                int sp18;
                int sp1C;
                fn_80562E34(FeI(x, 0x240));
                sp18 = 0;
                sp1C = 0;
                if (fn_800A3270(lbl_80619948, &sp18, &sp1C) == 0)
                    fn_8055EAFC((void*)FeI(x, 0x240));
            }
            fn_80483A9C(x);
            fn_80483094(x);
            fn_80482DBC(x);
        } else if (a == 2) {
            FeMsg m;
            FeMsg* p = &m;
            fn_8035682C(p);
            fn_8040B830(p->name, "BACK", 15);
            p->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), p, x);
        }
    }
}
