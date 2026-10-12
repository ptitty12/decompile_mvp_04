/*
 * Front-end overlay code, .frontend_codeoverlay 0x804DE730-0x804E02E0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804D08D0.h"

extern "C" void fn_80535650(FeTmp18* t, int v);

extern "C" {

FE_OVERLAY void fn_804DE9B8(void)
{
    if (lbl_8061ABD8 != 0) {
        fn_800C33D0();
        fn_800C3BE0();
    }
}

FE_OVERLAY unsigned fn_804DE9EC(unsigned n)
{
    return (unsigned)fn_804027DC() % n;
}

FE_OVERLAY unsigned fn_804DEA24(void)
{
    return fn_804DE9EC(0x57);
}

FE_OVERLAY int fn_804DEA48(void)
{
    int v = fn_800B548C(fn_804DE9EC(0x79));
    FeTmp18 t;
    int buf[0x28];
    FeTmp18* q = &t;
    q->C1(buf, 0x28);
    q->C2();
    q->C3(lbl_8064A4C8);
    fn_8040074C(q->m0, q->m8 << 2);
    q->m4 = 0;
    q->mC = 0;
    q->m14 = 0;
    fn_80535650(q, v);
    int r = q->At(fn_804DE9EC(q->Count()));
    t.D();
    return r;
}

FE_OVERLAY void fn_804DEEF4(FeS804DE5F8* x)
{
    int z = 0;
    fn_802D7EE4(fn_800C8070(x));
    if (x->m150 != 0 || (fn_802D7EE4(fn_800C8070(x)), x->m154 != 0)) {
        fn_800D878C__FP13Unk800D876C_A(x->m138);
        fn_802D7EE4(fn_800C8070(x));
        x->m150 = z;
        fn_802D7EE4(fn_800C8070(x));
        x->m154 = z;
    }
}

FE_OVERLAY int fn_804DEF74(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    return 1;
}

FE_OVERLAY int fn_804DEF9C(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804DF010(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804DF084(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804DF0F8(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_804DF16C(FeS804DE5F8* x, int a)
{
    ((FeState*)fn_800B555C())->m570 = a;
    fn_800B7ADC(FeGetMgr(), x);
    return 1;
}

FE_OVERLAY int fn_804DF1D4(void) { return 1; }

FE_OVERLAY void fn_804DF1DC(void) {}

FE_OVERLAY void fn_804DF460(FeS804DE5F8* x, int a)
{
    fn_800ED310(x, a);
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot14(a);
}

/* near-miss: registers/branch layout only (switch and if-else forms tried) */
FE_OVERLAY void fn_804DF4D4(FeS804DE5F8* x, signed char a)
{
    FeMsg m;
    FeMsg* mp = &m;
    switch (a) {
    case 0:
        fn_800D878C__FP13Unk800D876C_A(x->m138);
        fn_8035682C(mp);
        fn_8040B830(mp->name, lbl_805F5B98, 15);
        mp->name[15] = a;
        fn_800B7B4C(FeGetMgr(), mp, x);
        return;
    case 1:
        fn_8035682C(mp);
        fn_8040B830(mp->name, lbl_805F98D4, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        return;
    }
}

FE_OVERLAY void fn_804DF5CC(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_800E25E0__Fii(p, 0);
}

FE_OVERLAY void fn_804DF634(FeS804DE5F8* x)
{
    fn_80131F34((FeW*)x->m134, x, fn_804DF6E4, 0, 0x56C3, 2, 0x1C2, 1, 0x3E8, 0x3E9, 0, 0, 0, 0);
    ((FeWY*)x->m134)->s84(1);
    ((FeW*)x->m134)->fn_vslot86();
}

FE_OVERLAY void fn_804DF6E4(int a, void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    if (a != 1) {
        fn_8040B830(mp->name, lbl_805F98E0, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
    }
}

FE_OVERLAY void fn_804DF774(FeS804DE5F8* x)
{
    if (lbl_8061ABD8 != 0) {
        fn_800C3AB4(fn_800C33D0(), 9);
        x->fn_vslot32(lbl_805F9874, 1)->fn_vslot8(1);
    }
    fn_800ECF18(x);
    void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125100(p);
    fn_801250D8(p);
}

FE_OVERLAY int fn_804DF850(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

FE_OVERLAY void fn_804DFA08(int a, FeW* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F8034, 15);
    mp->name[15] = 0;
    if (a != 0) {
        if (a == 1) {
            x->fn_vslot80(1);
            fn_800B7B4C(FeGetMgr(), mp, x);
        }
    }
}

FE_OVERLAY int fn_804DFABC(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1))->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804DFB1C(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1))->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804DFB7C(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1))->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804DFBDC(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1))->fn_vslot53();
    return 1;
}

FE_OVERLAY void fn_804DFC3C(FeS804DE5F8* x, char* out)
{
    if (lbl_8061ABD8 != 0) {
        fn_8040B830(out, lbl_805F4450, 16);
        return;
    }
    FeW* w = fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1))->fn_vslot70();
    fn_8040B830(out, (char*)w->fn_vslot33(1, 1) + 0xC, 16);
    if (fn_8040B574(out, lbl_805F98FC) == 0) {
        fn_8040B830(out, lbl_805F9908, 16);
    }
}

FE_OVERLAY void fn_804E0024(FeW* x)
{
    fn_800ECAA4(x);
    if (lbl_8061ABD8 != 0) {
        fn_804DFE9C(x);
    }
}

FE_OVERLAY void fn_804E0068(void)
{
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY FeS804E008C* fn_804E008C(FeS804E008C* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066DD00);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

FE_OVERLAY void fn_804E00DC(FeS804E008C* x)
{
    fn_800ECF18(x);
    x->m134 = 0;
    void* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125100(p);
    fn_801250D8(p);
}

FE_OVERLAY int fn_804E0160(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804E01C0(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804E0220(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804E0280(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot53();
    return 1;
}

}
