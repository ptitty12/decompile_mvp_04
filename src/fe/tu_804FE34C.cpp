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
extern "C" int fn_804FEE04(void* x);
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

// Secondary list base: vptr +0x24, selection getter at virtual slot11.
struct FeSelect804FE6B8 {
    char pad[0x24];
    virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual void s9(); virtual void s10(); virtual int s11();
};
inline FeSelect804FE6B8* SelectControl804FE6B8(void* screen) {
    FeSelect804FE6B8* control = *(FeSelect804FE6B8**)((char*)screen + 0x10F8);
    control = (FeSelect804FE6B8*)((char*)control + 0xDC);
    return control;
}
// Retail fn_804FE6B8 builds this six-word array header before a 40-int buffer.
struct FeArray804FE6B8 { int* m0; int m4, m8, mC; const void* vp; int m14; };
extern const char lbl_8064B298[], lbl_8064A550[], lbl_8064A4C8[];
extern "C" void fn_8040074C(void*, int);
extern "C" void fn_80535650(FeArray804FE6B8*, int);
extern "C" void fn_804FE0F4(void*, int);
extern "C" int fn_804D1278(void*);
extern "C" void fn_804D1CB8(void*, int, int);
inline void ArrayBase804FE6B8(FeArray804FE6B8* a, int* buf, int cap) {
    a->vp = lbl_8064B298; a->m0 = buf; a->m8 = cap;
    fn_8040074C(a->m0, cap * 4);
}
inline void ArrayMid804FE6B8(FeArray804FE6B8* a) {
    a->m4 = 0; a->mC = 0; a->vp = lbl_8064A550;
    fn_8040074C(a->m0, a->m8 * 4);
}
inline void ArrayDerived804FE6B8(FeArray804FE6B8* a) {
    a->vp = lbl_8064A4C8; a->m4 = 0; a->mC = 0; a->m14 = 0;
}
inline void ArrayDestroy804FE6B8(FeArray804FE6B8* a) { a->vp = lbl_8064A550; }
// fn_800B555C()+8 exposes the selected team/player and screen index here.
struct FeState804FE6B8 { char pad[0x4F4]; int m4F4, m4F8, m4FC; };
extern "C" FE_OVERLAY void fn_804FE6B8(FeScrRos* x, int kind, int arg)
{
    switch (kind) {
    case 4:
        fn_804FE0F4(x, ((FeSub*)((char*)x->m10F4 + 0xDC))->s5());
        break;
    case 5: {
        int selected = SelectControl804FE6B8(x)->s11();
        if (selected != 0) {
            FeArray804FE6B8 a;
            int buf[40];
            ArrayBase804FE6B8(&a, buf, 40);
            ArrayMid804FE6B8(&a);
            ArrayDerived804FE6B8(&a);
            fn_80535650(&a, selected);
            ((FeWY*)x)->s84((int)&a);
            ArrayDestroy804FE6B8(&a);
        }
        break;
    }
    case 0: {
        FeState804FE6B8* state = (FeState804FE6B8*)((char*)fn_800B555C() + 8);
        state->m4F8 = -1;
        state->m4FC = 0;
        fn_804D1CB8(x, 0, 0);
        break;
    }
    case 1: {
        FeState804FE6B8* state = (FeState804FE6B8*)((char*)fn_800B555C() + 8);
        int team = ((FeSub*)((char*)x->m10F4 + 0xDC))->s5();
        int player = SelectControl804FE6B8(x)->s11();
        state->m4F8 = team;
        state->m4FC = player;
        FeState804FE6B8* state2 = (FeState804FE6B8*)((char*)fn_800B555C() + 8);
        state2->m4F4 = fn_804D1278(x);
        fn_804D1CB8(x, 1, 0);
        break;
    }
    default:
        fn_804D1CB8(x, kind, arg);
        break;
    }
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

// fn_804FEE04 writes these four prompt fields relative to fn_800B555C()+8.
struct FePrompt804FEE04 { char pad[0x4C4]; int m4C4, m4C8, m4CC; const char* m4D0; };
extern "C" int strcmp(const char*, const char*);
extern "C" char* strcpy(char*, const char*);
extern "C" const char* fn_80090880__FP11Unk80090880i(void*, int);
extern const char lbl_805FB544[], lbl_805FB550[], lbl_805FB55C[], lbl_805FB56C[];
extern "C" FE_OVERLAY int fn_804FEE04(void* x)
{
    const char* name = (*(FeW**)((char*)x + 0x134))->fn_vslot70()->fn_vslot33(5, 1)->mC;
    const char* label = fn_80090880__FP11Unk80090880i(lbl_8061977C, 0x60F);
    if (strcmp(name, lbl_805FB544) == 0) {
        FePrompt804FEE04* state = (FePrompt804FEE04*)((char*)fn_800B555C() + 8);
        state->m4C4 = 1;
        state->m4C8 = 0x100;
        state->m4CC = 0;
        state->m4D0 = label;
    } else if (strcmp(name, lbl_805FB550) == 0) {
        FePrompt804FEE04* state = (FePrompt804FEE04*)((char*)fn_800B555C() + 8);
        state->m4C4 = 0;
        state->m4C8 = 0x100;
        state->m4CC = 0;
        state->m4D0 = label;
    } else if (strcmp(name, lbl_805FB55C) == 0) {
        FePrompt804FEE04* state = (FePrompt804FEE04*)((char*)fn_800B555C() + 8);
        state->m4C4 = 2;
        state->m4C8 = 0x100;
        state->m4CC = 0;
        state->m4D0 = label;
    } else if (strcmp(name, lbl_805FB56C) == 0) {
        FeW* popup = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
        fn_80131F34(popup, x, (FeCbF)fn_804FF014, (int)fn_80528450, 0x3761, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
        popup->fn_vslot86();
        return 0;
    }
    strcpy((char*)x + 0x138, name);
    fn_800B7ADC(FeGetMgr(), x);
    return 1;
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
