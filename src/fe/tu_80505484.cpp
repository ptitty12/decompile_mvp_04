/*
 * Front-end overlay code, .frontend_codeoverlay 0x80505484-0x80508C98 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

extern "C" void fn_80507DD0(FeScrQ* x);
extern "C" void fn_80507D10(FeScrQ* x);
extern int lbl_806222A4;
extern int lbl_806222A8;
extern int lbl_806222AC;
extern "C" void fn_80505E60(FeScrQ* x);
extern "C" void fn_80505760(FeScrD* x);
extern "C" void fn_80505E40(FeScrD* x);
extern "C" void fn_80505F1C(FeScrQ* x, int a);
extern "C" void fn_80506C18();
extern "C" int fn_80506C1C();
extern "C" void fn_80506E70();
extern "C" int fn_80507038();
extern "C" int fn_805070A4();
extern "C" int fn_8050712C(FeScrN* x);
extern "C" int fn_80507204(FeScrN* x);
extern "C" int fn_8050787C(FeScrN* x, int a);
extern "C" int fn_80507A6C(FeScrN* x);
extern "C" int fn_80507C38(FeScrA* x);
extern "C" int fn_80507C80(FeScrA* x);
extern "C" int fn_80507CC8(FeScrA* x);
extern "C" int fn_80507DC4(void* self, int a);
extern "C" FeW* fn_80507F8C(FeScrN* x);
extern "C" int fn_80507FB8(FeScrN* x);
extern "C" int fn_805082B8(int c);

extern "C" FE_OVERLAY void fn_80505760(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_80505E40(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_80505F1C(FeScrQ* x, int a)
{
    x->m154 = a;
    fn_80505E60(x);
}

extern "C" FE_OVERLAY void fn_80506C18()
{
}

extern "C" FE_OVERLAY int fn_80506C1C()
{
    lbl_806222A4 = -1;
    lbl_806222A8 = -1;
    lbl_806222AC = -1;
    return 1;
}

extern "C" FE_OVERLAY void fn_80506E70()
{
}

extern "C" FE_OVERLAY int fn_80507038()
{
    return 1;
}

extern "C" FE_OVERLAY int fn_805070A4()
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8050712C(FeScrN* x)
{
    fn_80507F8C(x)->fn_vslot51();
    fn_80507DD0((FeScrQ*)x);
    fn_80507D10((FeScrQ*)x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80507204(FeScrN* x)
{
    fn_80507F8C(x)->fn_vslot53();
    fn_80507DD0((FeScrQ*)x);
    fn_80507D10((FeScrQ*)x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050787C(FeScrN* x, int a)
{
    x->m14C->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_80507A6C(FeScrN* x)
{
    x->m14C->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_80507C38(FeScrA* x)
{
    if (x->m138->fn_vslot86() != 0) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507C80(FeScrA* x)
{
    if (x->m138->fn_vslot87() != 0) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507CC8(FeScrA* x)
{
    if (x->m154 == 0) {
        return fn_80507C38(x);
    }
    if (x->m154 == 1) {
        return fn_80507C80(x);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507DC4(void* self, int a)
{
    return a == 0;
}

extern "C" FE_OVERLAY FeW* fn_80507F8C(FeScrN* x)
{
    int c = (int)x->m154;
    if (c == 1) {
        return x->m140;
    }
    if (c == 0) {
        return x->m13C;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507FB8(FeScrN* x)
{
    return ((FeSub11*)((char*)x->m150 + 0xDC))->s11();
}

extern "C" FE_OVERLAY int fn_805082B8(int c)
{
    int t = c - 0x41;
    if ((unsigned char)t > 0x19) {
        t = -1;
    }
    return t;
}
