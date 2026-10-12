/*
 * Front-end overlay code, .frontend_codeoverlay 0x804FE34C-0x804FF6B4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

struct FeP10F0 { char pad[0x10F0]; FeW* m10F0; };
struct FeP10EC { char pad[0x10EC]; FeW* m10EC; };

extern const char lbl_805FB52C[];
extern "C" int fn_800A3348(FeGlobal80619948* g, int* a, int* b);
extern const char lbl_80680960[];
extern const char lbl_805F4EF4[];
extern const char lbl_805F4F84[];
extern const char lbl_805F4450[];
extern "C" int fn_80075948(void* g, int a);
extern "C" void fn_8055F5A0(int a);
extern "C" void fn_8055EAFC(int a);
extern void* lbl_8061930C;
extern "C" char* fn_8040B61C(char* dst, const char* src);
extern "C" void fn_804FEE04(void* x);
extern const char lbl_806806B8[];
extern "C" int fn_804FE34C(FeP10F0* x);
extern "C" int fn_804FE38C(FeP10F0* x);
extern "C" int fn_804FE3CC(FeP10F0* x, int a);
extern "C" int fn_804FE408(FeP10F0* x);
extern "C" int fn_804FE444(FeP10EC* x);
extern "C" int fn_804FE484(FeP10EC* x);
extern "C" int fn_804FE4C4(FeP10EC* x, int a);
extern "C" int fn_804FE500(FeP10EC* x);
extern "C" void fn_804FE53C(FeScrRos* x, int a);
extern "C" void fn_804FE5B8(FeScrRos* x);
extern "C" void fn_804FE620(FeScrRos* x);
extern "C" FeScrRos* fn_804FE8AC(FeScrRos* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804FE8FC(FeScrD* x);
extern "C" int fn_804FEB40(FeScrJ* x);
extern "C" int fn_804FEB64(FeScrRos* x);
extern "C" int fn_804FECF4(FeScrN* x);
extern "C" int fn_804FED30(FeScrN* x);
extern "C" int fn_804FED6C(FeScrN* x);
extern "C" int fn_804FEDA8(FeScrN* x);
extern "C" void fn_804FEDE4(FeScrD* x);
extern "C" void fn_804FF014(int kind, FeScrRos* x);
extern "C" void fn_804FF0F8(int kind, FeScrRos* x);
extern "C" char* fn_804FF18C(FeScrJ* x, char* out);
extern "C" void fn_804FF1C0(FeScrN* x, int a);
extern "C" void fn_804FF210(void* self, int a, int b);
extern "C" void fn_804FF31C(int kind, FeScrRos* x);
extern "C" FeScrH* fn_804FF39C(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804FF3E8(FeScrD* x);
extern "C" void fn_804FF408(FeScrN* x);
extern "C" void fn_804FF4B0(FeScrD* x);
extern "C" void fn_804FF4D0(FeScrD* x);
extern "C" void fn_804FF4F0();
extern "C" void fn_804FF4F4();
extern "C" void fn_804FF4F8();
extern "C" int fn_804FF4FC(FeScrB* x);
extern "C" int fn_804FF558(FeScrK* x);
extern "C" int fn_804FF5C4(FeScrN* x);
extern "C" int fn_804FF600(FeScrN* x);
extern "C" int fn_804FF63C(FeScrN* x);
extern "C" int fn_804FF678(FeScrN* x);

extern "C" FE_OVERLAY int fn_804FE34C(FeP10F0* x)
{
    x->m10F0->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804FE38C(FeP10F0* x)
{
    x->m10F0->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804FE3CC(FeP10F0* x, int a)
{
    x->m10F0->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_804FE408(FeP10F0* x)
{
    x->m10F0->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FE444(FeP10EC* x)
{
    x->m10EC->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804FE484(FeP10EC* x)
{
    x->m10EC->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804FE4C4(FeP10EC* x, int a)
{
    x->m10EC->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_804FE500(FeP10EC* x)
{
    x->m10EC->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY void fn_804FE53C(FeScrRos* x, int a)
{
    if (a == (int)x->m10EC) {
        x->fn_vslot67(4, 0);
    } else if (a == (int)x->m10F0) {
        x->fn_vslot67(5, 0);
    }
}

extern "C" FE_OVERLAY void fn_804FE5B8(FeScrRos* x)
{
    x->m10EC->fn_vslot16(0);
    x->m10F0->fn_vslot16(0);
}

extern "C" FE_OVERLAY void fn_804FE620(FeScrRos* x)
{
    x->m10EC->fn_vslot16(1);
    int v = ((FeSub*)((char*)x->m10F4 + 0xDC))->s5();
    x->m10F0->fn_vslot16(v != 4 ? 1 : 0);
}

extern "C" FE_OVERLAY FeScrRos* fn_804FE8AC(FeScrRos* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80680960);
    self->m130 = 0;
    self->m19C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804FE8FC(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY int fn_804FEB40(FeScrJ* x)
{
    fn_804FEE04(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804FEB64(FeScrRos* x)
{
    if (FeW24(x->fn_vslot32(lbl_805FB52C, 1)) < 0) {
        int z = 0;
        int sp20;
        x->m19C = z;
        sp20 = z;
        if (fn_800A3348(lbl_80619948, &x->m19C, &sp20) == 0) {
            fn_804FF210(x, x->m19C, sp20);
        } else {
            FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
            fn_80131F34(p, x, fn_804FF0F8, (int)fn_80528450, 0x394F, 2, -1, 1, 0x3E9, 0x3E8, z, z, z, z);
            p->fn_vslot86();
        }
    } else {
        fn_8040B61C(x->m138, lbl_805F4450);
        x->fn_vslot80(0);
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804FECF4(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FED30(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FED6C(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FEDA8(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY void fn_804FEDE4(FeScrD* x)
{
    fn_804FEE04(x);
}

extern "C" FE_OVERLAY void fn_804FF014(int kind, FeScrRos* x)
{
    if (kind != 0) {
        if (kind == 1) {
            ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007295C();
            FePopup* p = (FePopup*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
            fn_80134D68(p);
            fn_80131F34(p, x, fn_8052844C, (int)fn_80528450, 0x3762, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
            p->fn_vslot86();
        }
    }
}

extern "C" FE_OVERLAY void fn_804FF0F8(int kind, FeScrRos* x)
{
    if (kind != 0) {
        if (kind == 1) {
            fn_8040B61C(x->m138, lbl_805F4450);
            x->fn_vslot80(1);
            fn_800B7ADC(FeGetMgr(), x);
        }
    }
}

extern "C" FE_OVERLAY char* fn_804FF18C(FeScrJ* x, char* out)
{
    out[0] = 0;
    return fn_8040B61C(out, (char*)x + 0x138);
}

extern "C" FE_OVERLAY void fn_804FF1C0(FeScrN* x, int a)
{
    fn_800ED310(x, a);
    x->m134->fn_vslot14(a);
}

extern "C" FE_OVERLAY void fn_804FF210(void* self, int a, int b)
{
    char buf[0x7D0];
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
    fn_800E4234__FiiPUs(a, b, buf);
    fn_800DFF0C(buf, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x44D1));
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(p, self, fn_804FF31C, 0, buf, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_804FF31C(int kind, FeScrRos* x)
{
    if (kind != 0) {
        if (kind == 1) {
            if (fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, x->m19C) == 0) {
                fn_8055F5A0(x->m19C);
            } else {
                fn_8055EAFC(x->m19C);
            }
            ((FeWX*)x)->s42(0);
        }
    }
}

extern "C" FE_OVERLAY FeScrH* fn_804FF39C(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806806B8);
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804FF3E8(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_804FF408(FeScrN* x)
{
    fn_800ECF18(x);
    x->m134 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
    void* nav = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(nav, x);
    fn_801250D8(nav);
    fn_80125100(nav);
}

extern "C" FE_OVERLAY void fn_804FF4B0(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_804FF4D0(FeScrD* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY void fn_804FF4F0()
{
}

extern "C" FE_OVERLAY void fn_804FF4F4()
{
}

extern "C" FE_OVERLAY void fn_804FF4F8()
{
}

extern "C" FE_OVERLAY int fn_804FF4FC(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804FF558(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804FF5C4(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FF600(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FF63C(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FF678(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}
