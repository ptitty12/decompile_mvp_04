/*
 * Front-end overlay code, .frontend_codeoverlay 0x804BE560-0x804BFB3C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"
struct FeWV101 : Unk800C7B40_Data {
    virtual ~FeWV101();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101(int a, int b);
};
extern "C" int fn_800B57EC(FeState* s);
extern "C" int fn_800A2E6C(FeGlobal80619948* g);
class FeV1Ci {
public:
    char pad0[0x1C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual int s9();
};
extern void* lbl_8061977C;
extern char lbl_805F4450[];
extern "C" const char* fn_80090880__FP11Unk80090880(void* g, int id);
extern "C" char* fn_80403144(char* dst, const char* src);
extern "C" float fn_8058FA38(void* w, int n);
extern char lbl_805F5854[];
struct FeScrT : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    FeW* m138;
    char pad13C[0x460 - 0x13C];
    char* m460;
};
extern char lbl_805F4EF4[];
extern "C" FeW* fn_800C8060(FeW* w);
extern "C" FeW* fn_800C8040(FeW* w);
extern "C" void fn_800DF254(char* out, int a, int b, float f);
extern "C" void fn_800E5380__FP3UiS(void* w);
extern "C" int fn_80125154(void* w, int a);
extern "C" int fn_80125128(void* w, int a);

extern const char lbl_80670968[];
extern const char lbl_806706C0[];

extern "C" FE_OVERLAY void fn_804BE944(FeScrN* x)
{
    fn_80125154(x->m13C, 0);
    FeW* w = x->m134;
    if (FeW24(w) & 0x40000000) {
        int o = w->fn_vslot60() * 8;
        char* b = (char*)x + 0x144;
        if (*(int*)(b + o) != -1) {
            fn_801251CC(x->m13C, 0, 0xEA6, 1);
        } else {
            fn_80125084(x->m13C, 0);
        }
    } else {
        fn_80125084(x->m13C, 0);
    }
}

extern "C" FE_OVERLAY void fn_804BE9E8(FeScrT* x)
{
    char buf[0x400];
    fn_800DF254(buf, 0, 0, *(float*)(x->m460 + 0x12B78));
    fn_800C8040(x->m138->fn_vslot32(lbl_805F5854, 1))->fn_vslot28(buf);
    fn_800E5380__FP3UiS(x->m138);
    x->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_804BEA94(FeScrN* x, int k)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    switch (k) {
    case 0:
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    case 1:
        x->fn_vslot88(x->m134->fn_vslot60());
        break;
    }
}

extern "C" FE_OVERLAY void fn_804BEE04(int a, FeW* w)
{
    if (a == 1) {
        ((FeWV*)w)->s89();
    }
}

extern "C" FE_OVERLAY int fn_804BF0E8(FeScrN* x)
{
    x->m134->fn_vslot52();
    x->fn_vslot87();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF148(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF184(FeScrN* x)
{
    x->m134->fn_vslot50();
    x->fn_vslot87();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF1E4(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY void fn_804BF220(void* unused, FeV1Ci* w, char* out)
{
    if (w->s9() <= 0) {
        fn_80403144(out, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x1A4B));
    } else {
        float sum = 0.0f;
        for (int n = w->s9(); n > 0; n--) {
            sum += fn_8058FA38(w, n);
        }
        fn_800DF254(out, 0, 3, sum);
    }
}

extern "C" FE_OVERLAY FeScrN* fn_804BF2EC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80670968);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804BF33C(FeScrN* self)
{
    self->SetVptr(lbl_80670968);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_804BF36C(FeScrN* x)
{
    fn_800ECF18(x);
    FePopup* p = (FePopup*)fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125154(p, 0);
    fn_80125128(p, 1);
    x->m134 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
    if (fn_800B57EC(fn_800B555C()) != 0 && fn_800A2E6C(lbl_80619948) != 0) {
        ((FeWV101*)x->m134)->s101(1, 0);
        ((FeWV101*)x->m134)->s101(2, 0);
        ((FeWV101*)x->m134)->s101(3, 0);
    }
}

extern "C" FE_OVERLAY void fn_804BF4AC(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY int fn_804BF4CC(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF508(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF544(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF580(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF5BC(FeScrN* x)
{
    x->fn_vslot67(1, 0);
    return 1;
}

extern "C" FE_OVERLAY void fn_804BF5FC(FeScrN* x, int k)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    switch (k) {
    case 0:
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    case 1:
        ((FeWV*)x)->s79(p);
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    }
}

extern "C" FE_OVERLAY void fn_804BF6E8(FeScrN* x, char* dst)
{
    fn_8040B830(dst, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC, 16);
}

extern "C" FE_OVERLAY FeScrN* fn_804BF75C(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806706C0);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804BF7AC(FeScrN* self)
{
    self->SetVptr(lbl_806706C0);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_804BF7DC(FeScrN* x)
{
    fn_800ECF18(x);
    FePopup* p = (FePopup*)fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125154(p, 0);
    fn_80125128(p, 1);
    x->m134 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
}

extern "C" FE_OVERLAY void fn_804BF88C(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY int fn_804BF8AC(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF8E8(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF924(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF960(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804BF99C(FeScrN* x)
{
    x->fn_vslot67(1, 0);
    return 1;
}

extern "C" FE_OVERLAY void fn_804BF9DC(FeScrN* x, int k)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    switch (k) {
    case 0:
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    case 1:
        ((FeWV*)x)->s79(p);
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    }
}

extern "C" FE_OVERLAY void fn_804BFAC8(FeScrN* x, char* dst)
{
    fn_8040B830(dst, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC, 16);
}
