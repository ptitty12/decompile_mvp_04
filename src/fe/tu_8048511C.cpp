/*
 * Front-end overlay code, .frontend_codeoverlay 0x8048511C-0x80488CDC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

extern "C" FE_OVERLAY FeScrH* fn_8048511C(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80676880);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = -1;
    FeI(self, 0x158) = -1;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = 0;
    FeI(self, 0x254) = 0;
    FeI(self, 0x258) = 0;
    FeI(self, 0x25C) = 0;
    FeI(self, 0x260) = 1;
    return self;
}

extern "C" FE_OVERLAY void fn_804851B0(FeScrB* self)
{
    fn_800ECE34(self);
    fn_800C3AB4(fn_800C33D0(), 9);
}

extern "C" FE_OVERLAY void fn_80485944(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_80485C28(void* x)
{
    if (fn_80488178(x) != 0)
        return 0;
    int idx = FeWp(x, 0x150)->fn_vslot60();
    FeW* cur = FeWp(x, 0x150);
    if (cur == FeWp(x, 0x13C))
        fn_80487A64(x, idx);
    else if (cur == FeWp(x, 0x140))
        fn_80487BD4(x, idx);
    fn_804873B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80485CC4(void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    int v = FeI(fn_800B555C(), 0x598);
    if (v != 0) {
        fn_8040B830(p->name, "DEPTHCHART", 15);
        p->name[15] = 0;
    } else {
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
    return 1;
}

extern "C" FE_OVERLAY void fn_80486018(void* x, int w, int dir)
{
    if (w == FeI(x, 0x14C)) {
        if (dir == 0) {
            int t = FeI(x, 0x250) - 1;
            if (t >= 0)
                FeI(x, 0x250) = t;
            else
                FeI(x, 0x250) = 5;
        } else {
            int t = FeI(x, 0x250) + 1;
            if (t <= 5)
                FeI(x, 0x250) = t;
            else
                FeI(x, 0x250) = 0;
        }
    } else if (w == FeI(x, 0x244)) {
        FeW* a = FeWp(x, 0x24C);
        void* g = lbl_8061930C;
        FeI(x, 0x254) = fn_80075948__18Unk8007B2B0_Screeni(g, fn_800B548C(((FeSubB*)((char*)a + 0x98))->s5()));
    }
    fn_80486800(x);
    fn_80486D7C(x);
    fn_804873B4(x);
}

extern "C" FE_OVERLAY int fn_804860F8(void* x, int a, int b, int c)
{
    if (a == FeI(x, 0x13C)) {
        int t = FeI(x, 0x154);
        if ((t == -1 && FeI(x, 0x158) == -1) || t == c || t != -1)
            fn_80487A64(x, c);
        fn_80487FE0(x, FeI(x, 0x13C));
    } else if (a == FeI(x, 0x140)) {
        if (FeI(x, 0x154) == -1)
            fn_80487BD4(x, c);
        fn_80487FE0(x, FeI(x, 0x140));
    }
    fn_804873B4(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_804861A8(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x13C)) {
        fn_80487FE0(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    } else if (w == FeWp(x, 0x140)) {
        fn_80487FE0(x, (int)w);
        w->fn_vslot68(c);
        ((FeWV*)x)->s44(fn_800C8070(x));
    }
    fn_804873B4(x);
    return 0;
}

extern "C" FE_OVERLAY int fn_804862A0(void* x)
{
    FeAt(x, 0x150)->fn_vslot50();
    fn_804873B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804862F0(void* x)
{
    FeAt(x, 0x150)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048632C(void* x)
{
    FeAt(x, 0x150)->fn_vslot52();
    fn_804873B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8048637C(void* x)
{
    FeAt(x, 0x150)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804863B8(void* x)
{
    if (FeI(x, 0x150) != FeI(x, 0x13C))
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    fn_80487FE0(x, FeI(x, 0x13C));
    return 0;
}

extern "C" FE_OVERLAY int fn_8048640C(void* x)
{
    if (FeI(x, 0x150) != FeI(x, 0x140))
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    fn_80487FE0(x, FeI(x, 0x140));
    return 0;
}

extern "C" FE_OVERLAY int fn_80486460(void* x)
{
    FeAt(x, 0x14C)->fn_vslot40(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_804864A0(void* x, int a)
{
    FeAt(x, 0x14C)->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_804864DC(void* x)
{
    FeAt(x, 0x14C)->fn_vslot38(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_8048651C(void* x)
{
    FeAt(x, 0x14C)->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_80486558(void* x)
{
    FeAt(x, 0x244)->fn_vslot40(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_80486598(void* x, int a)
{
    FeAt(x, 0x244)->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_804865D4(void* x)
{
    FeAt(x, 0x244)->fn_vslot38(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_80486614(void* x)
{
    FeAt(x, 0x244)->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY void fn_80487FE0(void* x, int wi)
{
    FeW* w = (FeW*)wi;
    FeWp(x, 0x13C)->fn_vslot14(0);
    FeWp(x, 0x140)->fn_vslot14(0);
    FeWp(x, 0x150) = w;
    w->fn_vslot14(1);
    if (w == FeWp(x, 0x13C))
        FeWp(x, 0x138)->fn_vslot84(0, 0);
    else if (w == FeWp(x, 0x140))
        FeWp(x, 0x138)->fn_vslot84(1, 0);
    fn_80486650(x);
}

extern "C" FE_OVERLAY int fn_804880D8(void* x)
{
    if (FeI(x, 0x150) == FeI(x, 0x13C)) {
        if (FeWp(x, 0x138)->fn_vslot86() != 0)
            return 1;
    }
    if (FeI(x, 0x150) == FeI(x, 0x140)) {
        if (FeWp(x, 0x138)->fn_vslot87() != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80488178(void* x)
{
    int r = 0;
    if (FeWp(x, 0x138)->fn_vslot86() != 0 || FeWp(x, 0x138)->fn_vslot87() != 0)
        r = 1;
    return r;
}

extern "C" FE_OVERLAY void fn_804884C0(int a, void* x)
{
    FeWp(x, 0x13C)->fn_vslot16(1);
    FeWp(x, 0x140)->fn_vslot16(1);
    if (a == 0) {
        fn_80487D44(x, FeI(x, 0x154), FeI(x, 0x158));
    } else if (FeI(x, 0x150) == FeI(x, 0x13C)) {
        FeI(x, 0x154) = -1;
    } else {
        FeI(x, 0x158) = -1;
    }
}

extern "C" FE_OVERLAY void fn_8048884C(int a, void* x)
{
    if (a == 0) {
        ((FeWV90*)FeWp(x, 0x13C))->s90(FeI(x, 0x154), 1, 0);
        FeI(x, 0x154) = -1;
    } else if (a == 1) {
        int i = FeI(x, 0x154);
        void* g = lbl_8061930C;
        int o = i * 4;
        char* b = (char*)x + 0x164;
        int v = *(int*)(b + o);
        fn_8007F29C__FP13Unk8007F198_Aii(g, FeI(x, 0x258), v);
        fn_8007F330__FP13Unk8007F198_Aii(g, FeI(x, 0x25C), v);
        ((FeWV90*)FeWp(x, 0x13C))->s90(FeI(x, 0x154), 1, 0);
        FeI(x, 0x154) = -1;
        fn_80486D7C(x);
        fn_804873B4(x);
    }
}

extern "C" FE_OVERLAY void fn_80488930(int a, void* x)
{
    if (a == 0) {
        ((FeWV90*)FeWp(x, 0x140))->s90(FeI(x, 0x158), 1, 0);
        FeI(x, 0x158) = -1;
    } else if (a == 1) {
        int i = FeI(x, 0x158);
        void* g = lbl_8061930C;
        int o = i * 4;
        char* b = (char*)x + 0x1C8;
        int v = *(int*)(b + o);
        fn_8007F29C__FP13Unk8007F198_Aii(g, FeI(x, 0x25C), v);
        fn_8007F330__FP13Unk8007F198_Aii(g, FeI(x, 0x258), v);
        ((FeWV90*)FeWp(x, 0x140))->s90(FeI(x, 0x158), 1, 0);
        FeI(x, 0x158) = -1;
        fn_80486D7C(x);
        fn_804873B4(x);
    }
}

extern "C" FE_OVERLAY void fn_80488CD4(void) {}

extern "C" FE_OVERLAY void fn_80488CD8(void) {}
