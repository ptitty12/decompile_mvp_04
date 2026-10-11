/*
 * Front-end overlay code, .frontend_codeoverlay 0x8048E6A0-0x80492680 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" {

extern "C" void fn_800E49DC(FeScrD* x);

FE_OVERLAY int fn_8048E76C(FeScrO* x)
{
    if (x->m148 == 0) {
        fn_8048E6A0(x);
    }
    return x->m148;
}

FE_OVERLAY int fn_8048E7A8(FeScrO* x)
{
    if (x->m14C == 0) {
        fn_8048E6A0(x);
    }
    return x->m14C;
}

FE_OVERLAY int fn_8048E8B0(FeScrO* x)
{
    if (x->m150 == 0) {
        fn_8048E7E4(x);
    }
    return x->m150;
}

FE_OVERLAY int fn_8048E8EC(FeScrO* x)
{
    if (x->m154 == 0) {
        fn_8048E7E4(x);
    }
    return x->m154;
}

FE_OVERLAY void fn_8048E990(void* x)
{
    fn_804D3164(x);
    fn_804D2DC0(x, 0x2422);
}

FE_OVERLAY void fn_8048EB38(FeScrD* x)
{
    fn_800E49DC(x);
}

FE_OVERLAY void fn_8048EC48(FeW* x)
{
    x->fn_vslot80(1);
    fn_8048EA74(x);
}

FE_OVERLAY void fn_8048FC64(void)
{
    ((FeStateX*)fn_800B555C())->m650 = 0;
    fn_800C33D0();
    fn_800C3BE0();
    fn_8001BC4C();
    fn_8001C168();
}

FE_OVERLAY void fn_80491ADC(void* x)
{
    FeI(x, 0x334) = FeMem(x, 0x198)->fn_vslot85();
}

FE_OVERLAY int fn_80491C54(void* x)
{
    ((FeWV*)FeMem(x, 0x248))->s47();
    fn_80492E94(x);
    return 1;
}

FE_OVERLAY int fn_80491CA4(void* x)
{
    FeMem(x, 0x248)->fn_vslot48();
    return 1;
}

FE_OVERLAY int fn_80491CE0(void* x)
{
    ((FeWV*)FeMem(x, 0x248))->s45();
    fn_80492E94(x);
    return 1;
}

FE_OVERLAY int fn_80491D30(void* x)
{
    FeMem(x, 0x248)->fn_vslot46();
    return 1;
}

FE_OVERLAY void fn_80491EE0(char* x)
{
    int i = FeI(x, 0x188);
    int o = i * 4;
    char* a = x + 0x240;
    char* b = x + 0x24C;
    int r = fn_800E2E8C(*(int*)(a + o), i, *(int*)(b + o), 0);
    *(int*)(b + FeI(x, 0x188) * 4) = r;
}

}
