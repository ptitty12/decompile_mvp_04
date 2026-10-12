/*
 * Front-end overlay code, .frontend_codeoverlay 0x804740A8-0x80477068 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"
extern "C" {
int fn_800E5D74__Fi(int v);
int fn_8013484C();
}

extern "C" FE_OVERLAY FeScrH* fn_804740A8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806782B8);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_80474660(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804746CC(FeW* x)
{
    if (fn_8040B574((char*)FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1) + 0xC, "AUTODOROSTERS") == 0) {
        fn_804749D8(x);
    } else if (fn_8040B574((char*)FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1) + 0xC, "AUTOSELECT") == 0) {
        fn_80474AF8(x);
    } else {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804747E8(void* x)
{
    FeAt(x, 0x134)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80474824(void* x)
{
    FeAt(x, 0x134)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_80474860(void* x)
{
    FeAt(x, 0x134)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047489C(void* x)
{
    FeAt(x, 0x134)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804748D8(void* x)
{
    ((FeW*)x)->fn_vslot41(0);
    return 1;
}

extern "C" FE_OVERLAY void fn_80474914(void* x, char* buf)
{
    FeW* w = FeWp(x, 0x134)->fn_vslot70()->fn_vslot33(5, 1);
    fn_8040B830(buf, (char*)w + 0xC, 16);
}

extern "C" FE_OVERLAY void fn_80474988(void* x, int a)
{
    fn_800ED310(x, a);
    FeWp(x, 0x134)->fn_vslot14(a);
}

extern "C" FE_OVERLAY void fn_804749D8(FeW* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    fn_80131F34(p, x, (FeCbT)fn_80474A98, 0, 0x4DA7, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_80474A98(int a)
{
    if (a == 1) {
        void* s = lbl_8061930C;
        fn_8007B780__18Unk8007B2B0_Screen(s, fn_8007F7D0__FP13Unk8007F198_BUi(s, 0), 0);
        fn_8055EAFC(fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0));
    }
}

extern "C" FE_OVERLAY void fn_80474AF8(FeW* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), "POPUP");
    fn_80131F34(p, x, (FeCbT)fn_80474BB8, 0, 0x5A3D, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_80474BB8(int a)
{
    FeGlobal80619948* g = lbl_80619948;
    if (a == 1) {
        void* s = lbl_8061930C;
        fn_8007B780__18Unk8007B2B0_Screen(s, fn_8007F7D0__FP13Unk8007F198_BUi(s, 0), 1);
        void* t = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
        void* h = fn_8007F9B4__FP13Unk8007F198_C(lbl_8061930C);
        fn_80560B44(t, fn_8056681C(FeVp(g, 0x48), h), 1);
    }
}

extern "C" FE_OVERLAY FeScrH* fn_80474C44(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80677818);
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804753E8(FeW* x, int sel, int c)
{
    switch (sel) {
    case 0:
        fn_804756F0(x);
        break;
    case 1:
        fn_804757EC(x);
        break;
    case 2:
        fn_80475EF0(x);
        break;
    case 3: {
        int r = fn_80476C44(x);
        if (r == 4)
            x->fn_vslot67(1, c);
        else if (r == 5)
            x->fn_vslot67(2, c);
        break;
    }
    }
}

extern "C" FE_OVERLAY int fn_804754C0(void* x)
{
    FeAt(x, 0x164)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804754FC(void* x)
{
    FeAt(x, 0x164)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80475538(void* x)
{
    FeAt(x, 0x164)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80475574(void* x)
{
    FeAt(x, 0x164)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804755B0(void* x)
{
    FeAt(x, 0x164)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804755EC(void* x)
{
    FeAt(x, 0x164)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_80475628(void* x)
{
    FeAt(x, 0x164)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_80475664(void* x)
{
    FeAt(x, 0x164)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY void fn_804756A0(void* x, int a)
{
    fn_800ED310(x, a);
    FeWp(x, 0x164)->fn_vslot14(a);
}

extern "C" FE_OVERLAY void fn_804756F0(void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
}

/* near-miss: 6 of 30 slots differ (scheduling of mr r31,r5 vs the lbl_8061930C load; r9/r11 roles in the offset math) */
extern "C" FE_OVERLAY int fn_80475774(int a, int b, int c)
{
    int* t;
    int o;
    if (fn_8007A270__18Unk8007A4DC_Screeni(lbl_8061930C, a) == 0) {
        o = (b << 2) + (c << 4);
        t = lbl_805FD54C;
    } else {
        o = (b << 2) + c * 20;
        t = lbl_805FD4FC;
    }
    return *(int*)((char*)t + o);
}

extern "C" FE_OVERLAY void fn_80475EF0(void* x)
{
    char small[200];
    char big[1000];
    fn_800DE440(small, FeI(x, 0x138), 1);
    fn_804031F8(big, fn_80090880__FP11Unk80090880(lbl_8061977C, fn_800E5D74__Fi(FeI(x, 0x138))), (int)small);
    ((FeWV*)FeWp(x, 0x168))->s84(1);
    const char* s1 = (const char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = (const char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(FeWp(x, 0x168), x, (FeCbT)fn_80476A28, (int)fn_8013484C, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    FeWp(x, 0x168)->fn_vslot86();
}

extern "C" FE_OVERLAY int fn_80476134(int x, int b)
{
    if (b != 0)
        return 3 - x / 5;
    return 3 - x / 4;
}

extern "C" FE_OVERLAY int fn_80476178(int x, int b)
{
    if (b != 0)
        return 4 - x % 5;
    return 3 - x % 4;
}

extern "C" FE_OVERLAY int fn_804761D0(int x, int b)
{
    int* t;
    if (b == 0) {
        b = 0;
        t = lbl_806217D8;
    } else {
        t = lbl_806217C4;
    }
    return t[fn_80476178(x, b)];
}

extern "C" FE_OVERLAY int fn_80476220(int x, int b)
{
    return lbl_806217E8[fn_80476134(x, b)];
}

extern "C" FE_OVERLAY void fn_804766FC(void* x)
{
    FeW* w = FeWp(x, 0x15C);
    void* g = lbl_8061930C;
    ((FeSubV15*)((char*)w + 0xDC))->s15();
    if (fn_8007A270__18Unk8007A4DC_Screeni(g, FeI(x, 0x138)) != 0) {
        int i;
        for (i = 0; i < 5; i++)
            ((FeWV51*)FeWp(x, 0x15C))->s51(lbl_806217C4[i], 0);
    } else {
        int i;
        for (i = 0; i < 4; i++)
            ((FeWV51*)FeWp(x, 0x15C))->s51(lbl_806217D8[i], 0);
    }
}

extern "C" FE_OVERLAY void fn_80476A28(int a, void* x)
{
    FeWp(x, 0x164)->fn_vslot14(1);
    if (a == 1)
        fn_80475FFC(x);
}

extern "C" FE_OVERLAY void fn_80476C24(FeScrD* x)
{
    fn_80476A84(x);
}

extern "C" FE_OVERLAY int fn_80476DB4(void* x)
{
    switch (fn_80476C44(x)) {
    case 4:
    case 5:
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80476DEC(void* x, int a)
{
    if (a == FeI(x, 0x164)) {
        if (fn_80476DB4(x) != 0)
            fn_801251CC(FeVp(x, 0x178), 0, 0x10, 3);
        else
            fn_80125084(FeVp(x, 0x178), 0);
    }
}

extern "C" FE_OVERLAY int fn_80476E50(FeW* x, int a)
{
    int r;
    if (a == FeI(x, 0x164) && fn_80476DB4(x)) {
        x->fn_vslot67(3, 0);
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

extern "C" FE_OVERLAY FeScrH* fn_80477000(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80676DD0);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = -1;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 4;
    FeI(self, 0x144) = -1;
    return self;
}
