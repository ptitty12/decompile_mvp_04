/*
 * Front-end overlay code, .frontend_codeoverlay 0x8051E878-0x80520BE0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"

extern const char lbl_805F5648[];
extern const char lbl_805F7944[];
extern const char lbl_805FBB40[];
extern "C" void fn_8052007C(FeScrD* x);
extern "C" int fn_804DC75C(void* p, int a, int b, int c, int d);
extern const char lbl_8067A5E8[];
extern const char lbl_8067A2E0[];
extern "C" void fn_8051E878(void* x, int a);
extern "C" int fn_8051E890(void* x, int a, int b, int c, int d);
extern "C" FeW* fn_8051F42C(FeV10* x);
extern "C" void* fn_8051F470(FeV10* x);
extern "C" void* fn_8051F4D8(void* x);
extern "C" FeW* fn_8051F51C(FeV10* x);
extern "C" void fn_8051F6A4(void* x);
extern "C" void fn_8051F6E0(FeV10* x, int a);
extern "C" void fn_8051F748(void* x);
extern "C" void fn_8051F784(FeV10* x, int a);
extern "C" void fn_8051F964(FeV10* x);
extern "C" void fn_8051F9C0(FeV10* x);
extern "C" void fn_8051FE58(FeV10* x);
extern "C" void fn_8051FEA8(FeV10* x);
extern "C" void fn_8052005C(FeScrD* x);
extern "C" void fn_80520128(FeV10* x);
extern "C" void fn_80520178(FeV10* x);
extern "C" void fn_805203B8(FeV10* x);
extern "C" void fn_80520408(FeV10* x);
extern "C" void fn_805206EC(FeV10* x);
extern "C" void fn_8052073C(FeV10* x);
extern "C" void fn_80520794(FeV10* x);
extern "C" void fn_805207E4(FeV10* x);
extern "C" void fn_8052088C(FeV10B* x);
extern "C" void fn_805208E0(FeV10B* x);

extern "C" FE_OVERLAY void fn_8051E878(void* x, int a)
{
    if (FeI(x, 0x5A4) != 0) {
        FeI(x, 0x43C) = a;
        FeI(x, 0x5A0) = a;
    }
}

/* near-miss: retail lays the zero case first (beq to the body, li r3,0, b end); 4 spellings tried */
extern "C" FE_OVERLAY int fn_8051E890(void* x, int a, int b, int c, int d)
{
    if (FeI(x, 0x5A8) == 1) {
        fn_804DC75C((char*)x + 0x2DC, a, b, c, d);
        fn_804DC75C((char*)x + 0x440, a, b, c, d);
        return 1;
    } else {
        return 0;
    }
}

extern "C" FE_OVERLAY FeW* fn_8051F42C(FeV10* x)
{
    return FePool(x);
}

extern "C" FE_OVERLAY void* fn_8051F470(FeV10* x)
{
    return fn_800C8048(FePool(x)->fn_vslot29(lbl_805F5648));
}

extern "C" FE_OVERLAY void* fn_8051F4D8(void* x)
{
    return fn_800C8058(fn_8051F51C((FeV10*)x)->fn_vslot29(lbl_805FBB40));
}

extern "C" FE_OVERLAY FeW* fn_8051F51C(FeV10* x)
{
    return fn_800C805C(FePool(x)->fn_vslot29(lbl_805F7944));
}

extern "C" FE_OVERLAY void fn_8051F6A4(void* x)
{
    FeSubOf(x)->s5();
}

extern "C" FE_OVERLAY void fn_8051F6E0(FeV10* x, int a)
{
    FeSubOf(x)->s6(a);
    x->s9();
}

extern "C" FE_OVERLAY void fn_8051F748(void* x)
{
    FeSubOf(x)->s11();
}

/* near-miss: the else-arm FeSubOf(x)->s8(a) call gets the two-register delta form in ours, retail uses add r3,r3,r0 (int/void s8 both tried) */
extern "C" FE_OVERLAY void fn_8051F784(FeV10* x, int a)
{
    if (FeSubOf(x)->s7(a) == -1) {
        FeSubOf(x)->s6(0);
    } else {
        FeSubOf(x)->s8(a);
        x->s9();
    }
}

extern "C" FE_OVERLAY void fn_8051F964(FeV10* x)
{
    x->s5(fn_8051E910(x->m4, lbl_80622648));
}

/* near-miss: retail loads x->m4 and lbl into callee-saved regs between fn_8051F4D8 and the vcall; ours reorders (4 spellings tried) */
extern "C" FE_OVERLAY void fn_8051F9C0(FeV10* x)
{
    FeSub24* s = FeSubOf(x);
    fn_8051EDDC(x->m4, lbl_80622648, s->s11());
}

extern "C" FE_OVERLAY void fn_8051FE58(FeV10* x)
{
    x->s5(FeGetSet()->m520);
}

extern "C" FE_OVERLAY void fn_8051FEA8(FeV10* x)
{
    FeSet* st = FeGetSet();
    st->m520 = x->s4();
}

//@8051FEF4
FE_OVERLAY FeRecA::FeRecA(int a)
{
    m0 = -1;
    m4 = a;
    m8 = 0x3BEE;
    mC = 0;
    m10 = lbl_8067A5E8;
}

extern "C" FE_OVERLAY void fn_8051FF84(void) {}

extern "C" FE_OVERLAY void fn_8052005C(FeScrD* x)
{
    fn_8052007C(x);
}

extern "C" FE_OVERLAY void fn_80520128(FeV10* x)
{
    x->s5(FeGetSet()->m580);
}

extern "C" FE_OVERLAY void fn_80520178(FeV10* x)
{
    FeSet* st = FeGetSet();
    st->m580 = x->s4();
}

extern "C" FE_OVERLAY void fn_805203B8(FeV10* x)
{
    x->s5(FeGetSet()->m588);
}

extern "C" FE_OVERLAY void fn_80520408(FeV10* x)
{
    FeSet* st = FeGetSet();
    st->m588 = x->s4();
}

extern "C" FE_OVERLAY void fn_805206EC(FeV10* x)
{
    x->s5(FeGetSet()->m524);
}

extern "C" FE_OVERLAY void fn_8052073C(FeV10* x)
{
    FeSet* st = FeGetSet();
    st->m524 = x->s4() == 1;
}

extern "C" FE_OVERLAY void fn_80520794(FeV10* x)
{
    x->s5(FeGetSet()->m528);
}

extern "C" FE_OVERLAY void fn_805207E4(FeV10* x)
{
    FeSet* st = FeGetSet();
    st->m528 = x->s4() == 1;
}

//@8052083C
FE_OVERLAY FeRecC::FeRecC(int a, int b, int c, int d, int e)
{
    m0 = -1;
    m4 = a;
    m8 = b;
    m10 = lbl_8067A2E0;
    m14 = c;
    m18 = d;
    m1C = e;
    m20 = 0;
    mC = d / e;
}

extern "C" FE_OVERLAY void fn_8052088C(FeV10B* x)
{
    int v = fn_8051E910(x->m4, lbl_80622648);
    x->s3(v);
}

extern "C" FE_OVERLAY void fn_805208E0(FeV10B* x)
{
    fn_8051EDDC(x->m4, lbl_80622648, x->s2());
}
