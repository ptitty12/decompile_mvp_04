/*
 * Front-end overlay code, .frontend_codeoverlay 0x8050C9DC-0x80512D10 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

extern "C" void fn_80510F28(FeScrQ* x, int a);
extern "C" void fn_8055AC44(void* p, int v);
extern "C" void fn_804CEF98(FeScrM* x);
extern "C" void fn_804D292C(FeSlot44* p, int v);
extern const char lbl_80667E70[];
extern "C" void fn_804CF368(void* x);
extern "C" FeScrN* fn_8050C9DC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_8050D6B0(FeScrN* x);
extern "C" int fn_8050D714(FeScrN* x);
extern "C" int fn_8050D778(FeScrN* x);
extern "C" int fn_8050D7DC(FeScrN* x);
extern "C" void fn_8050DAEC(FeScrM* x);
extern "C" void fn_8050DFC8(FeScrD* x);
extern "C" void fn_8050E574();
extern "C" void fn_8050E888(FeScrM* x);
extern "C" void fn_80510020(FeScrD* x);
extern "C" void fn_80510500(FeScrQ* x, int a);
extern "C" void fn_8051052C();
extern "C" int fn_805105A4(FeScrN* x);
extern "C" int fn_805105FC(FeScrN* x);
extern "C" int fn_80510654(FeScrN* x);
extern "C" int fn_805106AC(FeScrN* x);
extern "C" int fn_80510704(FeScrN* x);
extern "C" int fn_8051075C(FeScrN* x);
extern "C" int fn_805107B4(FeScrN* x);
extern "C" int fn_8051080C(FeScrN* x);
extern "C" int fn_80510864(FeScrN* x);
extern "C" int fn_805108A4(FeScrN* x, int a);
extern "C" int fn_805108E0(FeScrN* x);
extern "C" int fn_80510920(FeScrN* x);

extern "C" FE_OVERLAY FeScrN* fn_8050C9DC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80667E70);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_8050D6B0(FeScrN* x)
{
    x->m134->fn_vslot50();
    x->m138->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050D714(FeScrN* x)
{
    x->m134->fn_vslot51();
    x->m138->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050D778(FeScrN* x)
{
    x->m134->fn_vslot52();
    x->m138->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050D7DC(FeScrN* x)
{
    x->m134->fn_vslot53();
    x->m138->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY void fn_8050DAEC(FeScrM* x)
{
    fn_8055AC44((char*)x + 0xB20, 0);
    fn_804CEF98(x);
}

extern "C" FE_OVERLAY void fn_8050DFC8(FeScrD* x)
{
    fn_804CF368(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_8050E574()
{
}

extern "C" FE_OVERLAY void fn_8050E888(FeScrM* x)
{
    fn_8055AC44((char*)x + 0xE08, 0);
    fn_804CEF98(x);
    fn_804D292C(&x->m144, -1);
    fn_804D292C(&x->m188, 0);
}

extern "C" FE_OVERLAY void fn_80510020(FeScrD* x)
{
    fn_804CF368(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_80510500(FeScrQ* x, int a)
{
    if (a == x->m134) {
        fn_80510F28(x, a);
    }
}

extern "C" FE_OVERLAY void fn_8051052C()
{
}

extern "C" FE_OVERLAY int fn_805105A4(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot56();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_805105FC(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot57();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80510654(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot54();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_805106AC(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot55();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80510704(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot50();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051075C(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot51();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_805107B4(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot52();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8051080C(FeScrN* x)
{
    if (*(int*)fn_800B555C() != 0x17) {
        x->m13C->fn_vslot53();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80510864(FeScrN* x)
{
    x->m134->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_805108A4(FeScrN* x, int a)
{
    x->m134->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_805108E0(FeScrN* x)
{
    x->m134->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80510920(FeScrN* x)
{
    x->m134->fn_vslot39();
    return 1;
}
