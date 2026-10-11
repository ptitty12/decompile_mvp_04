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

FE_OVERLAY void fn_8049F2A8(void* x)
{
    FeMem(x, 0x180)->fn_vslot8(0);
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

FE_OVERLAY void fn_804A15C0(char* x)
{
    *(int*)(x + 0x144) = 1;
    *(int*)(x + 0x140) = 0;
    *(int*)(x + 0x14C) = 1;
    fn_8049E830(x, 1);
}

FE_OVERLAY void fn_804A2634(void* x, int a, int b)
{
    FeI(x, 0x17C) = a;
    FeI(x, 0x178) = fn_800B5520(b);
    fn_804A0B18(x);
}

FE_OVERLAY void fn_804A2734(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

}
