/*
 * Front-end overlay code, .frontend_codeoverlay 0x8047D454-0x80481634 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

extern "C" FE_OVERLAY int fn_8047DC70(void* x)
{
    if (fn_8047F450(x) != 0 || FeI(x, 0x220) != 0)
        return 0;
    int idx = FeWp(x, 0x14C)->fn_vslot60();
    FeW* cur = FeWp(x, 0x14C);
    if (cur == FeWp(x, 0x138))
        fn_8047F0A4(x, idx);
    else if (cur == FeWp(x, 0x13C))
        fn_8047F1C0(x, idx);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E028(void* x)
{
    FeAt(x, 0x14C)->fn_vslot50();
    fn_8047E490(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E078(void* x)
{
    FeAt(x, 0x14C)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E0B4(void* x)
{
    FeAt(x, 0x14C)->fn_vslot52();
    fn_8047E490(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E104(void* x)
{
    FeAt(x, 0x14C)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E19C(void* x)
{
    if (FeI(x, 0x220) == 0) {
        if (FeI(x, 0x14C) != FeI(x, 0x13C))
            fn_8001BC4C()->fn_8001BDAC(0x9C);
        fn_8047E7E8(x, FeI(x, 0x13C));
        fn_8047E490(x);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8047E204(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E20C(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E214(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E21C(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E224(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E22C(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E234(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E23C(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8047E5B0(void* x, int a, int b, int c)
{
    if (a == FeI(x, 0x138)) {
        int t = FeI(x, 0x150);
        if ((t == -1 && FeI(x, 0x154) == -1) || t == c || t != -1)
            fn_8047F0A4(x, c);
        fn_8047E7E8(x, FeI(x, 0x138));
    } else if (a == FeI(x, 0x13C)) {
        if (FeI(x, 0x150) == -1)
            fn_8047F1C0(x, c);
        fn_8047E7E8(x, FeI(x, 0x13C));
    }
    fn_8047E490(x);
    return 0;
}

extern "C" FE_OVERLAY void fn_8047E758(void* x, int a)
{
    FeI(x, 0x134) = a;
    fn_8047E8E0(x);
    FeWp(x, 0x14C)->fn_vslot68(0);
    FeWp(x, 0x138)->fn_vslot14(0);
    FeWp(x, 0x13C)->fn_vslot14(0);
}

extern "C" FE_OVERLAY int fn_8047F3B0(void* x)
{
    if (FeWp(x, 0x14C) == FeWp(x, 0x138)) {
        if (FeWp(x, 0x144)->fn_vslot86() != 0)
            return 1;
    }
    if (FeWp(x, 0x14C) == FeWp(x, 0x13C)) {
        if (FeWp(x, 0x144)->fn_vslot87() != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8047F4CC(void* x)
{
    FeNode4* n = lbl_806192E0->m4;
    FeA70* a = n->m10;
    FeAFFC* b = n->m14;
    if (FeI(x, 0x134) == b->mFFC && a->m70 != -1)
        return 1;
    return 0;
}

extern "C" FE_OVERLAY int fn_8047FD94(void* x)
{
    if (fn_8048157C(x) != 0 || FeI(x, 0x230) != 0)
        return 0;
    int idx = FeWp(x, 0x15C)->fn_vslot60();
    FeW* cur = FeWp(x, 0x15C);
    if (cur == FeWp(x, 0x138))
        fn_80481200(x, idx);
    else if (cur == FeWp(x, 0x13C))
        fn_8048131C(x, idx);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047FE30(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80480164(void* x)
{
    FeAt(x, 0x15C)->fn_vslot50();
    fn_804805B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804801B4(void* x)
{
    FeAt(x, 0x15C)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804801F0(void* x)
{
    FeAt(x, 0x15C)->fn_vslot52();
    fn_804805B4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80480240(void* x)
{
    FeAt(x, 0x15C)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804802D8(void* x)
{
    if (FeI(x, 0x230) == 0) {
        if (FeI(x, 0x15C) != FeI(x, 0x13C))
            fn_8001BC4C()->fn_8001BDAC(0x9C);
        fn_80480960(x, FeI(x, 0x13C));
        fn_804805B4(x);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80480340(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480348(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480350(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480358(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480360(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480368(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480370(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80480378(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_804806D4(void* x, int a, int b, int c)
{
    if (a == FeI(x, 0x138)) {
        int t = FeI(x, 0x160);
        if ((t == -1 && FeI(x, 0x164) == -1) || t == c || t != -1)
            fn_80481200(x, c);
        fn_80480960(x, FeI(x, 0x138));
    } else if (a == FeI(x, 0x13C)) {
        if (FeI(x, 0x160) == -1)
            fn_8048131C(x, c);
        fn_80480960(x, FeI(x, 0x13C));
    }
    fn_804805B4(x);
    return 0;
}

extern "C" FE_OVERLAY void fn_80481438(char* x, int a, int b)
{
    int idx = fn_804815F8(x);
    FeNode4* n = lbl_806192E0->m4;
    char* base = (char*)n->m14;
    char* rec = base + idx * 0xE64;
    int o1 = b * 4;
    char* b1 = x + 0x1CC;
    int r = fn_800968C0(rec, *(int*)(b1 + o1), 1);
    int o2 = a * 4;
    char* b2 = x + 0x168;
    fn_80081BA8__FP13Unk8007FF8C_Yiii(base, idx, fn_80097288(rec, *(int*)(b2 + o2)), r);
    fn_80480A58(x);
    fn_804805B4(x);
}

extern "C" FE_OVERLAY int fn_804814DC(void* x)
{
    if (FeWp(x, 0x15C) == FeWp(x, 0x138)) {
        if (FeWp(x, 0x154)->fn_vslot86() != 0)
            return 1;
    }
    if (FeWp(x, 0x15C) == FeWp(x, 0x13C)) {
        if (FeWp(x, 0x154)->fn_vslot87() != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804815F8(void* x)
{
    FeNode4* n = lbl_806192E0->m4;
    FeA70* a = n->m10;
    FeAFFC* b = n->m14;
    if (FeI(x, 0x134) == b->mFFC && a->m70 != -1)
        return 1;
    return 0;
}
