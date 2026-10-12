/*
 * Front-end overlay code, .frontend_codeoverlay 0x8049E0BC-0x804A2AB4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" {

FE_OVERLAY int fn_8049E0BC(void* x)
{
    FeMem(x, 0x154)->fn_vslot40(1);
    return 1;
}

FE_OVERLAY int fn_8049E0FC(void* x)
{
    ((FeWV*)FeMem(x, 0x154))->s41();
    return 1;
}

FE_OVERLAY int fn_8049E138(void* x)
{
    FeMem(x, 0x154)->fn_vslot38(1);
    return 1;
}

FE_OVERLAY int fn_8049E178(void* x)
{
    FeMem(x, 0x154)->fn_vslot39();
    return 1;
}

FE_OVERLAY FeScrH* fn_8049E1B4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80674DC8);
    self->m130 = 0;
    FeI(self, 0x16C) = 0;
    return self;
}

FE_OVERLAY void fn_8049ED34(void* a, void* cb)
{
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    if (FeI(fn_800B555C(), 0x588) == 0) {
        fn_80125268(w, 2, cb, 0);
    } else {
        fn_80125084(w, 2);
    }
}

FE_OVERLAY void fn_8049F00C(char* x)
{
    Unk8006A138_It<3> it(0);
    int i = 0;
    do {
        char* b = x + 0x18C;
        int o = i * 0x28;
        FeW* w = *(FeW**)(b + o);
        w->fn_vslot8(0);
        i = it.Next();
    } while (i <= 3);
}

FE_OVERLAY void fn_8049F2A8(void* x)
{
    FeMem(x, 0x180)->fn_vslot8(0);
}

FE_OVERLAY void fn_8049FF38(FeW* x, FeW* y)
{
    if (y == fn_800C805C(x->fn_vslot32(lbl_805F59C4, 1)) && FeI(x, 0x148) != 0) {
        FeI(x, 0x178) = fn_800B5520(((FeSubI*)((char*)fn_800C8058(y->fn_vslot32(lbl_805F535C, 1)) + 0xDC))->s11());
        fn_804A0B18(x);
    }
}

FE_OVERLAY int fn_804A0470(void) { return 0; }

FE_OVERLAY int fn_804A0478(void) { return 0; }

FE_OVERLAY int fn_804A0480(void) { return 0; }

FE_OVERLAY int fn_804A0488(void) { return 0; }

FE_OVERLAY void fn_804A0900(void* a, int b, int c)
{
    int id = fn_80083FC0(b);
    fn_800B5520(fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, id, c));
}

FE_OVERLAY void fn_804A0A78(void* x, int a)
{
    ((FeSubB*)((char*)FeP(x, 0x224) + 0x98))->s20(a, 0);
    ((FeSubB*)((char*)FeP(x, 0x228) + 0x98))->s20(a, 0);
    ((FeSubB*)((char*)FeP(x, 0x22C) + 0x98))->s20(a, 0);
}

FE_OVERLAY int fn_804A1510(void* x, FeEvt* ev)
{
    char* name = ev->name;
    if (FeI(x, 0x13C) != 0 && ev->m1C == 5 && (fn_8040B574(name, lbl_805F7654) == 0 || fn_8040B574(name, lbl_805F765C) == 0)) {
        fn_800B7ADC(FeGetMgr(), x);
        return 1;
    }
    return 0;
}

FE_OVERLAY void fn_804A15C0(char* x)
{
    *(int*)(x + 0x144) = 1;
    *(int*)(x + 0x140) = 0;
    *(int*)(x + 0x14C) = 1;
    fn_8049E830(x, 1);
}

FE_OVERLAY void fn_804A256C(void* a, FeW* x)
{
    x->fn_vslot80(1);
    fn_800B7ADC(FeGetMgr(), x);
    if (fn_800D83A0() == 0) {
        void* t = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
        int n = fn_8007B3E0__18Unk8007B2B0_Screenii(lbl_8061930C, 0xF, t);
        fn_8007B4A8__18Unk8007B2B0_Screeniii(lbl_8061930C, 0xF, t, n == 0x1D ? 0 : n + 1);
    }
}

FE_OVERLAY void fn_804A2634(void* x, int a, int b)
{
    FeI(x, 0x17C) = a;
    FeI(x, 0x178) = fn_800B5520(b);
    fn_804A0B18(x);
}

FE_OVERLAY void fn_804A2674(FeW* x, int a)
{
    fn_800ED310(x, a);
    x->fn_vslot32(lbl_805F755C, 1)->fn_vslot14(a);
    if (FeI(x, 0x14C) != 0) {
        FeMem(x, 0x180)->fn_vslot32(lbl_805F5060, 1)->fn_vslot14(a);
    }
}

FE_OVERLAY void fn_804A2734(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY void fn_804A2964(void)
{
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    ((FeWQ*)w)->s85(0);
    FeGlobal80619948* g = lbl_80619948;
    FeI(w, 0x314) = 1;
    fn_800A2030(g, 1);
}

/* near-miss (47/48 ins): retail's ternary sets r3 and r4 in each arm and shares r31 with the lbl_8061A32C lis. */
FE_OVERLAY void fn_804A29F4(FeW* x)
{
    FeMsg m;
    FeMsg* p = &m;
    x->fn_vslot80(1);
    fn_8035682C(p);
    fn_8040B830(p->name, fn_800B5758(fn_800B555C()) == 1 ? lbl_805F75B8 : lbl_805F4450, 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), &m, x);
}

}
