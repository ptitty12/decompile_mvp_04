/*
 * Front-end overlay code, .frontend_codeoverlay 0x80512D10-0x80516990 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

struct FeP94 { char pad[0x94]; FeW* m94; };
struct FeP2A8 { char pad[0x2A8]; FeP94* m2A8; };
struct FeP298_1E0 { char pad[0x1E0]; FeW* m1E0; char pad2[0x298 - 0x1E0 - 4]; FeW* m298; };

extern const char lbl_80667920[];
extern "C" FeScrN* fn_80512D10(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80512D60(FeScrD* x);
extern "C" int fn_80512F8C(FeScrK* x);
extern "C" int fn_80512FF8(FeScrB* x);
extern "C" int fn_80513054(FeScrN* x);
extern "C" int fn_80513090(FeScrN* x);
extern "C" int fn_805130CC(FeScrN* x);
extern "C" int fn_80513108(FeScrN* x);
extern "C" void fn_80513144(FeScrN* x, char* dst);
extern "C" int fn_805131B8(FeScrB* x);
extern "C" void fn_80513270(FeScrD* x);
extern "C" int fn_8051601C(FeP2A8* x);
extern "C" int fn_8051605C(FeP2A8* x);
extern "C" int fn_8051609C(FeP2A8* x);
extern "C" int fn_805160DC(FeP2A8* x);
extern "C" int fn_80516474(FeP298_1E0* x);
extern "C" int fn_80516550(FeP298_1E0* x);

extern "C" FE_OVERLAY FeScrN* fn_80512D10(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80667920);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80512D60(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY int fn_80512F8C(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80512FF8(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80513054(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80513090(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_805130CC(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80513108(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY void fn_80513144(FeScrN* x, char* dst)
{
    fn_8040B830(dst, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC, 16);
}

extern "C" FE_OVERLAY int fn_805131B8(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY void fn_80513270(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY int fn_8051601C(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051605C(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051609C(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_805160DC(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_80516474(FeP298_1E0* x)
{
    ((FeWX*)x->m298)->s41();
    ((FeWX*)x->m1E0)->s41();
    return 0;
}

extern "C" FE_OVERLAY int fn_80516550(FeP298_1E0* x)
{
    x->m298->fn_vslot39();
    x->m1E0->fn_vslot39();
    return 0;
}
