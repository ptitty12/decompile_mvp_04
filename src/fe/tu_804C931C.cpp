/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C931C-0x804CB430 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

/* tu_8007A4DC.h declares fn_80402EF8 with C++ linkage; the symbol is plain. */
#define fn_80402EF8 fe_fn_80402EF8_cxx
#include "game/fe_804BE560.h"
#undef fn_80402EF8
struct FeG40 {
    char pad0[0x40];
    int m40;
};
class FeWF : public Unk800C7B40_Data {
public:
    virtual ~FeWF();
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
    virtual void s59(float a);
    virtual void s60();
    virtual float s61();
};
extern "C" void fn_80564ABC(int h, int s, int a, int c, void* d, void* e, int f);
extern "C" void fn_80402EF8(char* dst, const char* src);
extern "C" void fn_80403DE4(char* dst, const char* fmt, ...);
extern const char lbl_805F80F4[];
extern "C" int fn_80125154(void* w, int a);
extern "C" FeW* fn_800C8060(FeW* w);
struct FeCfg430 {
    char pad0[0x430];
    int m430;
};
struct FeMgr34 {
    char pad0[0x34];
    FeCfg430* m34;
};
extern const char lbl_805F8118[];
extern const char lbl_805F8134[];
extern const char lbl_805F4EF4[];
extern "C" int fn_80125128(void* w, int a);

extern void* lbl_8061977C;
extern "C" const char* fn_80090880__FP11Unk80090880(void* t, int id);
void fn_800DE538(int out, int a, int b, int c);
extern "C" void fn_804031F8(char* out, const char* a, const char* b);
extern "C" void fn_801321D4(FeW* o, void* self, void (*cb)(int, void*), int (*cb2)(), char* b, int c, int d, int e,
                            const char* s1, const char* s2, const char* s3, int f, int g, int h);
extern "C" int fn_8013484C();
extern "C" char* fn_800DF254(char* out, int a, int b, float f);

extern const char lbl_805F8108[];
struct Unk8007F198_B;
int fn_8007F7D0(Unk8007F198_B* b, unsigned i);
extern const char lbl_805F3CA8[];
extern "C" void fn_8013013C(void* w, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);

extern const char lbl_8066F0D0[];
extern const char lbl_8066EE28[];
extern const char lbl_80671198[];
extern "C" int fn_804CA1E8(void* x);
extern "C" int fn_804C9810(FeScrN* x);
extern "C" int fn_804C984C(FeScrN* x);
extern "C" int fn_804C9888(FeScrN* x);
extern "C" int fn_804C98C4(FeScrN* x);
extern "C" int fn_804C9900(FeScrN* x);
extern "C" int fn_804C993C(FeScrN* x);
extern "C" int fn_804C9978(FeScrN* x);
extern "C" int fn_804C99B4(FeScrN* x);
extern "C" FeScrN* fn_804CA3F8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804CA448(FeScrN* x);
extern "C" int fn_804CA788(FeScrN* x);
extern "C" int fn_804CA7C8(FeScrN* x);
extern "C" int fn_804CA804(FeScrN* x);
extern "C" int fn_804CA840(FeScrN* x);
extern "C" int fn_804CA87C(FeScrN* x);
extern "C" FeScrN* fn_804CA8B8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804CA908(FeScrN* self);
extern "C" int fn_804CB254(FeScrN* x);
extern "C" int fn_804CB290(FeScrN* x);
extern "C" int fn_804CB2CC(FeScrN* x);
extern "C" int fn_804CB308(FeScrN* x);
extern "C" FeScrN* fn_804CB3DC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_804CA2F0(void* x);
extern "C" void fn_804CA328(FeScrN* x, int a);
extern "C" int fn_804CA38C(FeScrN* x, int a);

extern "C" void fn_804C9A40(void* x);

extern "C" void fn_804C9AC4(void*);

extern "C" void fn_804C9D58(FeScrN* x);
extern "C" void fn_804CA12C(int a);

extern "C" FE_OVERLAY void fn_804C9738(FeW* x, int sel, int c)
{
    switch (sel) {
    case 0:
        fn_804C9A40(x);
        break;
    case 1:
        fn_804C9AC4(x);
        break;
    case 2:
        fn_804C9D58((FeScrN*)x);
        break;
    case 3: {
        int r = fn_804CA1E8(x);
        if (r == 4)
            x->fn_vslot67(1, c);
        else if (r == 5)
            x->fn_vslot67(2, c);
        break;
    }
    }
}

extern "C" FE_OVERLAY int fn_804C9810(FeScrN* x)
{
    x->m150->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C984C(FeScrN* x)
{
    x->m150->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C9888(FeScrN* x)
{
    x->m150->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C98C4(FeScrN* x)
{
    x->m150->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C9900(FeScrN* x)
{
    x->m150->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C993C(FeScrN* x)
{
    x->m150->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C9978(FeScrN* x)
{
    x->m150->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C99B4(FeScrN* x)
{
    x->m150->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY void fn_804C99F0(FeScrN* x, int a)
{
    fn_800ED310(x, a);
    x->m150->fn_vslot14(a);
}

extern const char lbl_805F4450[];

extern "C" FE_OVERLAY void fn_804C9A40(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F4450, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY void fn_804C9D58(FeScrN* x)
{
    char big[0x200];
    char small[0x80];
    fn_800DE538((int)small, fn_8008FD78((int)x->m13C), (int)x->m138, 1);
    fn_804031F8(big, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x1A47), small);
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(x->m154, x, (void (*)(int, void*))fn_804CA12C, fn_8013484C, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    x->m154->fn_vslot86();
}

/* near-miss: 3 of 102 slots. Retail forms the first fn_800DF254 buffer argument with its own `addi r3,r1,16` and orders
 * the argument moves r3, r5, r4; ours copies the saved pointer (`mr r3,r30`). Pointer-local spellings, an inline
 * wrapper and return-type flips of the callees were tried. */
extern "C" FE_OVERLAY void fn_804C9E44(FeScrN* x)
{
    float sp8;
    char b10[0xC8];
    char bD8[0x20];
    float t;
    float pad;
    unsigned sp100;
    fn_80564ABC(((FeG40*)lbl_80619948)->m40, fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0), (int)x->m138, (int)x->m13C, &sp8, &sp100, 0);
    t = sp8;
    fn_800DF254(b10, 0, 3, t);
    ((FeWV*)x->m15C)->s28(b10);
    fn_80402EF8(bD8, lbl_805F80F4);
    fn_80403DE4(b10, bD8, sp100);
    ((FeWV*)x->m160)->s28(b10);
    ((FeWF*)x->m148)->s59(!(((FeWF*)x->m148)->s61() >= sp8) ? ((FeWF*)x->m148)->s61() : sp8);
    ((FeWF*)x->m14C)->s59((float)sp100);
}

extern "C" FE_OVERLAY void fn_804C9FDC(FeScrN* x)
{
    char buf[0x80];
    float v = *(float*)((char*)*(void**)((Unk8007B2B0_Screen*)lbl_8061930C)->m30 + 0x12B78);
    fn_800DF254(buf, 0, 3, v);
    ((FeWV*)x->m144)->s28(buf);
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    float w = s->fn_80079E74(fn_8007F7D0((Unk8007F198_B*)s, 0));
    fn_800DF254(buf, 0, 3, w);
    ((FeWV*)x->m140)->s28(buf);
}

extern "C" FE_OVERLAY void fn_804CA0A8(void) {}

extern "C" FE_OVERLAY void fn_804CA0AC(int a, FeScrN* x)
{
    if (x != 0) {
        int s = fn_800B555C()->m38;
        int t = fn_800B555C()->m34;
        fn_8013013C(x->m158, 0, s, t, fn_800B555C()->m38, 0, 1, 0, 0, 0, 0, 0);
        fn_804C9A40(x);
    }
}

extern "C" FE_OVERLAY void fn_804CA12C(int a)
{
    if (a != 0) {
        if (a == 1) {
            Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
            int st = fn_800B555C()->m34;
            s->fn_8007C328(st, fn_8007F7D0((Unk8007F198_B*)s, 0));
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, lbl_805F8108, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, 0);
        }
    }
}

extern "C" FE_OVERLAY int fn_804CA1E8(void* x)
{
    FeW* w = ((FeScrN*)x)->m150->fn_vslot70();
    if (w->fn_vslot30("SALARY", 1) != 0)
        return 0;
    if (w->fn_vslot30("TERM", 1) != 0)
        return 1;
    if (w->fn_vslot30("RESIGNPLAYERST", 1) != 0)
        return 4;
    w->fn_vslot30("RELEASEPLAYERST", 1);
    return 5;
}

/* near-miss: 2 slots (retail compares `cmpwi r3,4; bge`, we emit `cmpwi r3,3; bgt`). The
 * comma form below is the closest of ~14 spellings of `n >= 4 && n <= 5`. */
extern "C" FE_OVERLAY int fn_804CA2F0(void* x)
{
    int n = fn_804CA1E8(x);
    int r;
    if (n > 5 || (r = 1, n < 4)) {
        r = 0;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804CA328(FeScrN* x, int a)
{
    if (a == (int)x->m150) {
        if (fn_804CA2F0(x) != 0) {
            fn_801251CC(x->m164, 0, 0x10, 3);
            return;
        }
        fn_80125084(x->m164, 0);
    }
}

extern "C" FE_OVERLAY int fn_804CA38C(FeScrN* x, int a)
{
    if (a == (int)x->m150 && fn_804CA2F0(x) != 0) {
        x->fn_vslot67(3, 0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY FeScrN* fn_804CA3F8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066F0D0);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804CA448(FeScrN* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_804CA468(FeScrN* x)
{
    fn_800ECF18(x);
    FePopup* p = (FePopup*)fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125154(p, 0);
    fn_80125128(p, 1);
    x->m134 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
    if (((FeMgr34*)lbl_8061930C)->m34->m430 != 0) {
        x->fn_vslot29(lbl_805F8118)->fn_vslot8(1);
        x->fn_vslot29(lbl_805F8134)->fn_vslot8(0);
    } else {
        x->m134->fn_vslot79(((FeVQ*)x->m134)->s62() - 1, 0);
        x->fn_vslot29(lbl_805F8118)->fn_vslot8(0);
        x->fn_vslot29(lbl_805F8134)->fn_vslot8(1);
    }
}

extern "C" FE_OVERLAY void fn_804CA664(FeScrN* x, int sel)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    switch (sel) {
    case 0:
        fn_8040B830(mp->name, "BACK", 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    case 1:
        fn_8040B830(mp->name, (char*)x->m134->fn_vslot70()->fn_vslot33(5, 1) + 0xC, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_804CA788(FeScrN* x)
{
    x->fn_vslot67(1, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA7C8(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA804(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA840(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA87C(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY FeScrN* fn_804CA8B8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066EE28);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804CA908(FeScrN* self)
{
    self->SetVptr(lbl_8066EE28);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_804CB254(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CB290(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CB2CC(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CB308(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY void fn_804CB344(void* x, int b)
{
    if (b == 0) {
        fn_800A2030(lbl_80619948, 0);
        FeMsg m;
        FeMsg* mp = &m;
        fn_8035682C(mp);
        fn_8040B830(mp->name, lbl_805F3CA8, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
    }
}

extern "C" FE_OVERLAY FeScrN* fn_804CB3DC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80671198);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}
