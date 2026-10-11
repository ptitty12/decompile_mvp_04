/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C3ECC-0x804C713C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern "C" void fn_804C6AA4(FeScrD* x);
extern "C" void fn_804C4D18(FeScrD* x);
extern "C" void fn_804C68B4(void* x, int v);

extern "C" FE_OVERLAY void fn_804C4520(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_804C4608(FeScrN* x)
{
    x->m154->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C4644(FeScrN* x)
{
    x->m154->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C4680(FeScrN* x)
{
    x->m154->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C46BC(FeScrN* x)
{
    x->m154->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C474C(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C47A8(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C47B0(FeScrN* x)
{
    x->m158->fn_vslot40(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C47F0(FeScrN* x, int a)
{
    x->m158->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C482C(FeScrN* x)
{
    x->m158->fn_vslot38(1);
    return 0;
}

extern "C" FE_OVERLAY int fn_804C486C(FeScrN* x)
{
    x->m158->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY void fn_804C4958(FeScrD* x)
{
    fn_804C6AA4(x);
}

extern "C" FE_OVERLAY void fn_804C4B30(FeScrD* x, FeScrD* y)
{
    if (x != 0) {
        fn_804C4D18(y);
    }
}

extern "C" FE_OVERLAY void fn_804C686C(void* x, int a)
{
    fn_804C68B4(x, ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(0, a));
}
