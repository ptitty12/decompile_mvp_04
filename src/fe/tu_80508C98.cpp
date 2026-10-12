/*
 * Front-end overlay code, .frontend_codeoverlay 0x80508C98-0x8050C9DC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

extern "C" void fn_8050A970(void* x);
extern "C" void fn_8050A9F0(void* x);
extern const char lbl_805FB738[];
extern const char lbl_805FB744[];
extern const char lbl_805FB750[];
extern const char lbl_805F4EF4[];
extern const char lbl_805F4450[];
extern "C" void fn_80508FBC(FeScrD* x);
extern "C" void fn_8050A4A8(void* x, int a);
extern "C" int fn_8050A4FC(FeScrN* x);
extern "C" int fn_8050A570(FeScrN* x);
extern "C" int fn_8050A5E4(FeScrN* x);
extern "C" int fn_8050A658(FeScrN* x);
extern "C" int fn_8050A6CC(FeScrN* x);
extern "C" int fn_8050A72C(FeScrN* x);
extern "C" int fn_8050A78C(FeScrN* x);
extern "C" int fn_8050A7EC(FeScrN* x);
extern "C" int fn_8050A8E0(void);
extern "C" void fn_8050A8EC(void* x);
extern "C" void fn_8050BED4(FeScrD* x);
extern "C" int fn_8050BFC0(FeScrN* x);
extern "C" int fn_8050C000(FeScrN* x, int a);
extern "C" int fn_8050C03C(FeScrN* x);
extern "C" int fn_8050C07C(FeScrN* x);
extern "C" int fn_8050C0B8(FeScrN* x);
extern "C" int fn_8050C0F4(FeScrN* x);
extern "C" int fn_8050C130(FeScrN* x);
extern "C" int fn_8050C16C(FeScrN* x);
extern "C" int fn_8050C1A8(FeScrN* x);
extern "C" int fn_8050C1E4(FeScrN* x);
extern "C" int fn_8050C220(FeScrN* x);
extern "C" int fn_8050C25C(FeScrN* x);
extern "C" FeW* fn_8050C380(FeScrN* x, int idx);
extern "C" FeW* fn_8050C408(FeScrN* x);

extern "C" FE_OVERLAY void fn_80508FBC(FeScrD* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY void fn_8050A4A8(void* x, int a)
{
    switch (a) {
    case 0:
        fn_8050A8EC(x);
        break;
    case 1:
        fn_8050A970(x);
        break;
    case 2:
        fn_8050A9F0(x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_8050A4FC(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot56();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A570(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot57();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A5E4(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot54();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A658(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot55();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A6CC(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A72C(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A78C(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A7EC(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A8E0(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_8050A8EC(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F4450, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY void fn_8050BED4(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_8050BFC0(FeScrN* x)
{
    x->m13C->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C000(FeScrN* x, int a)
{
    x->m13C->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C03C(FeScrN* x)
{
    x->m13C->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C07C(FeScrN* x)
{
    x->m13C->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C0B8(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C0F4(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C130(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C16C(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C1A8(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C1E4(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C220(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C25C(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY FeW* fn_8050C380(FeScrN* x, int idx)
{
    if (idx == 0) {
        return fn_800C8060(x->fn_vslot32(lbl_805FB738, 1));
    }
    if (idx == 1) {
        return fn_800C8060(x->fn_vslot32(lbl_805FB744, 1));
    }
    if (idx == 2) {
        return fn_800C8060(x->fn_vslot32(lbl_805FB750, 1));
    }
    return 0;
}

extern "C" FE_OVERLAY FeW* fn_8050C408(FeScrN* x)
{
    return fn_8050C380(x, (int)x->m134);
}
