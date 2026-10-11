/*
 * Front-end overlay code, .frontend_codeoverlay 0x8045B134-0x8045EDDC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"

extern "C" {
FE_OVERLAY void fn_8045B4E8(void)
{
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY int fn_8045BC74(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_8045BCD0(FeScrB* x)
{
    x->m1B8->fn_vslot50();
    if (x->m1B8->fn_vslot60() == 1) {
        ((FeWV*)x->m1B8)->s101(0, 1);
        x->m1B8->fn_vslot68(0);
        ((FeWV*)x->m1B8)->s101(0, 0);
        x->m1B8->fn_vslot68(1);
    }
    fn_8045D338(x);
    fn_8045C8C0(x);
    return 1;
}

FE_OVERLAY int fn_8045BDD4(FeScrB* x)
{
    x->m1B8->fn_vslot52();
    fn_8045D338(x);
    fn_8045C8C0(x);
    return 1;
}

FE_OVERLAY int fn_8045BE2C(FeScrB* x)
{
    x->m1B8->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_8045BE68(FeScrB* x)
{
    x->m1B8->fn_vslot53();
    return 1;
}

FE_OVERLAY void fn_8045BEA4(FeScrB* x, int a)
{
    if (a == 0) {
        if (FeW24(x->m1EC) >= 0) {
            int id = x->m1B8->fn_vslot60();
            if (((FeWV*)x->m1B8)->s94(id, 2) != 0) {
                int r = fn_8045D420(x, id);
                FeList* l = x->m1EC;
                fn_80126CF4(l, l->m164, r, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                x->m1EC->fn_vslot84(1, 0);
                x->m1EC->fn_vslot8(1);
                x->m1B8->fn_vslot16(0);
                fn_8045D338(x);
            }
        } else {
            x->m1EC->fn_vslot84(2, 0);
            x->m1EC->fn_vslot8(0);
            x->m1B8->fn_vslot16(1);
            fn_8045D338(x);
        }
    }
}

FE_OVERLAY int fn_8045C04C(FeScrB* x, FeW* w, int b, int c)
{
    int r;
    if (w != x->m1B8) {
        r = 0;
    } else {
        w->fn_vslot68(c);
        fn_8045C8C0(x);
        fn_8045D338(x);
        r = 1;
    }
    return r;
}

FE_OVERLAY void fn_8045C0BC(FeScrB* x, int a, int b)
{
    x->m134 = b;
    fn_8045C79C(x);
    fn_8045C8C0(x);
    fn_8045D338(x);
}

FE_OVERLAY void fn_8045D338(FeScrB* x)
{
    if (FeW24(x->m1EC) < 0) {
        fn_80125084(x->m1F0, 0);
        fn_801251CC(x->m1F0, 3, 0x37A2, 0);
    } else {
        fn_80125084(x->m1F0, 0);
        fn_80125084(x->m1F0, 3);
        int id = x->m1B8->fn_vslot60();
        if (((FeWV*)x->m1B8)->s94(id, 2) != 0) {
            fn_80125180(x->m1F0, 0, 0x10);
            fn_801251CC(x->m1F0, 3, 0x1A2F, 0);
        }
    }
    fn_80125100(x->m1F0);
}

FE_OVERLAY int fn_8045D420(FeScrB* x, int idx)
{
    int r = 0;
    int found = 0;
    int a = x->m138;
    a = a >? 1;
    int b = x->m13C;
    b = b >? 1;
    int c = x->m140;
    c = c >? 1;
    int k = idx - 1;
    if (k <= a) {
        r = x->m144[k];
        found = 1;
    }
    k -= a;
    k -= 1;
    if (found == 0 && k <= b) {
        r = x->m1A8[k];
        found = 1;
    }
    k -= b;
    k -= 1;
    if (found == 0 && k <= c) {
        r = x->m1B0[k];
        found = 1;
    }
    if (found == 0) {
        return 0;
    }
    return r;
}

FE_OVERLAY void fn_8045D4D8(int which, FeScrB* x)
{
    int id = fn_8045D420(x, x->m1B8->fn_vslot60());
    switch (x->m1F4[which]) {
    case 0:
        fn_8045D5B0(x, id);
        break;
    case 1:
        fn_8045D71C(x, id, 0);
        break;
    case 2:
        fn_8045D71C(x, id, 1);
        break;
    }
    fn_8045C79C(x);
    fn_8045C8C0(x);
    fn_8045D338(x);
}

FE_OVERLAY int fn_8045D5A8(void) { return 1; }

FE_OVERLAY void fn_8045EBBC(FeScrD* x)
{
    int v = ((FeSub*)((char*)x->m154 + 0xDC))->s5();
    fn_800B555C()->m57C = v;
}

FE_OVERLAY void fn_8045EC0C(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY void fn_8045EC34(FeScrD* x, int kind)
{
    switch (kind) {
    case 0:
        fn_804615DC(x);
        break;
    case 1:
        fn_804617C8(x);
        break;
    case 2:
        fn_80461910(x);
        break;
    case 3:
        fn_80461A14(x);
        break;
    case 4:
        fn_80461B18(x);
        break;
    case 5:
        fn_80461BF8(x);
        break;
    case 6:
        fn_80461D0C(x);
        break;
    case 7:
        fn_80461DB8(x);
        break;
    case 8:
        fn_80461E5C(x);
        break;
    }
}

FE_OVERLAY int fn_8045ECEC(FeScrD* x)
{
    x->m14C->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_8045ED28(FeScrD* x)
{
    x->m14C->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_8045ED64(FeScrD* x)
{
    x->m14C->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_8045EDA0(FeScrD* x)
{
    x->m14C->fn_vslot53();
    return 1;
}

}
