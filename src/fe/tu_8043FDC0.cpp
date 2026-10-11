/*
 * Front-end overlay code, .frontend_codeoverlay 0x8043FDC0-0x804439E4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern "C" FE_OVERLAY void fn_8043FDC0(void)
{
}

extern "C" FE_OVERLAY void fn_8043FDC4(void)
{
}

extern "C" FE_OVERLAY void fn_8043FDC8(void)
{
}

extern "C" FE_OVERLAY void fn_8043FDCC(void)
{
}

extern "C" FE_OVERLAY void fn_8043FDD0(void)
{
    int i = lbl_8061930C->fn_8007DA28();
    if (i != -1) {
        lbl_8061930C->fn_8007D180(i, (int)FeTunableGet(&lbl_8061B9A0->m1DE0));
    }
}

extern "C" FE_OVERLAY void fn_8043FE44(void)
{
    fn_800A3DF4(lbl_80619948);
}

extern "C" FE_OVERLAY void fn_8043FE6C(void)
{
    unsigned n = fn_800734D4(lbl_8061930C, 0x100);
    void* a = fn_803774A8(n, 0x100);
    void* b = fn_803774A8(n, 0x100);
    Fe803567AC sp8;
    fn_80072E90(lbl_8061930C, a, n, 0x100, 0, &sp8);
    int len = fn_80401610(a, n, b, 1);
    fn_803FBFE0("rost.bin", b, len);
    fn_80377408(a);
    fn_80377408(b);
}

extern "C" FE_OVERLAY void fn_8043FF1C(void)
{
}

extern "C" FE_OVERLAY void fn_8043FF20(void)
{
}

extern "C" FE_OVERLAY void fn_80440210(void)
{
    int i;
    int n = lbl_80621608;
    for (i = 0; i < n; i++) {
        fn_8043FF24(i + 1);
    }
}

extern "C" FE_OVERLAY void fn_8044025C(void)
{
    unsigned n = fn_800734D4(lbl_8061930C, 0x100);
    void* a = fn_803774A8(n, 0x100);
    Fe803567AC sp8;
    fn_80072E90(lbl_8061930C, a, n, 0x100, 0, &sp8);
    fn_803FBFE0("urost.bin", a, n);
}

extern "C" FE_OVERLAY void fn_804402D8(void)
{
}

extern "C" FE_OVERLAY void fn_804402DC(void)
{
    fn_800B8AF0((char*)UiGetMsgMgr() + 0x38);
    fn_80331294((char*)lbl_8061B998 + 0x24);
}

extern "C" FE_OVERLAY void fn_80440340(void)
{
    fn_8005B9D4(fn_8005ACE4(), 0);
}

extern "C" FE_OVERLAY void fn_80440368(void)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), &m, 0);
}

extern "C" void fn_80330BC8(void* self);
extern "C" FE_OVERLAY void fn_80442364(void* self)
{
    fn_80330BC8(self);
}

extern "C" FE_OVERLAY void fn_80443610(void)
{
}

extern "C" FE_OVERLAY void fn_80443864(void)
{
}
