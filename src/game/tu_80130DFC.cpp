/*
 * Game code, .text 0x80130DFC-0x80134A60 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"

#include "game/tu_8001B190.h"
extern const char lbl_805C0B94[];
extern const char lbl_805C0B9C[];
extern const char lbl_805C0BA4[];
extern int lbl_80619948;
extern "C" void fn_80377408(void*);
extern "C" int fn_800A2AE8(int);
extern "C" void fn_80329FA0(void*, ...);
extern "C" void fn_800DD44C(void*, void*, int);
extern "C" void fn_8040316C(void*, const char*, int);
extern "C" int fn_8040321C(void*, int, void*, void*);
extern int lbl_8061A328;
extern "C" void fn_800ECAA4(void*);

/* Front-end screen class (sibling of the one in tu_8012C8CC.cpp: the same flag/state words,
 * shifted by one word after +0x18C). Vtable lbl_80659AD0, base dtor fn_800EC1B8. */
struct Unk80130DFC : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    char pad138[8];
    int m140;
    int m144;
    int m148;
    char pad14C[0x10];
    int m15C;
    int m160;
    int m164;
    char pad168[0xC];
    void (*m174)();
    char pad178[0x10];
    int m188;
    int m18C;
    int m190;
    char pad194[8];
    int m19C;
    char pad1A0[0x13C];
    int (*m2DC)(int, int);
    int (*m2E0)();
    int m2E4;
    int m2E8;
    int m2EC;
    int m2F0;
    int m2F4;
    int m2F8;
    int m2FC;
    int m300;
    int m304;
    float m308;
    int m30C;
    int m310;
    int m314;
    int m318;
    int m31C;
    int m320;
    int m324;
    char* m328;
    char pad32C[0xAD8];
    int mE04;
    int mE08;
    int mE0C;
    int mE10;
    int mE14;
};
typedef Unk80130DFC Scr;

struct Unk8061A32C {
    char padB8[0xB8];
    int mB8;
};
extern Unk8061A32C* lbl_8061A32C;
extern const char lbl_80659AD0[];
extern const char lbl_805C0A08[];
extern const char lbl_805C0A14[];
extern const char lbl_805C0B8C[];
extern const char lbl_805C0C70[];
Unk8001BC8C* fn_8001BC4C();

static inline Unk8061A32C* FE();
extern "C" {
void* fn_800B8144();
void fn_800B83F8(void* p, int a, int b);
void fn_800EC150(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_800ED310(void* x, int a);
void fn_800ECDCC(void* x, int a);
void fn_800ECE34(void* x);
void* fn_800C33D0();
void fn_800C3FEC(void* m, Scr* x, int a, int b);
void fn_800C40B4(void* m, Scr* x, int a, int b);
int fn_8011AA24(int a);
int fn_801A4A94(int a, int b);
void fn_80131C48(Scr* x, int a, float f);
Unk8061A32C* fn_800B64BC(void* p);
Unk800C7B40_Widget* fn_800C8044(Unk800C7B40_Widget* p);
Unk800C7B40_Widget* fn_800C8060(Unk800C7B40_Widget* p);
int fn_80131278(Scr* x, int a);
void fn_801311AC(Scr* x, int a);
void fn_80130FB4(void* unused, Unk800C7B40_Widget* w, int c);
void fn_801318D0(Scr* x, int a, int b);
int fn_80131970(Scr* x);
int fn_80134618(Scr* x, int a);
int fn_80134D58(Scr* x);
void fn_80134CD0(Scr* x);
void fn_800EC1B8(void* x, int chrg);
void fn_800EC278(void* x);
void fn_800EC84C(void* x);
void fn_800ECF18(void* x);
int fn_8013484C();
}

static inline Unk8061A32C* FE()
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    return lbl_8061A32C;
}

extern const float lbl_805C0B78;
extern const float lbl_805C0C84;
extern const char lbl_805C0B7C[];
extern const char lbl_805C0B80[];
extern "C" void fn_801321D4(Scr* x, int a1, int (*a2)(int, int), int (*a3)(), int a4, int a5, int a6, int a7, char* s8, char* sC, char* s10, char* s14, int s18, int s1C);
extern const float lbl_805C0BC4;
extern const char lbl_805C0B7C[];
extern const char lbl_805C0C1C[];
extern "C" {
void fn_802DC9C0();
Unk800C7B40_Widget* fn_800C8068(Unk800C7B40_Widget* p);
}
extern "C" {
void fn_80134680(Scr* x);
void fn_801345F8(Scr* x, int (*f)());
void fn_80134D74(Scr* x);
void fn_80132830(Scr* x, int a, int b, char* c, char* d, char* e, char* f, int g);
void fn_80132A38(Scr* x);
void fn_80132C00(Scr* x, int a, int b, int c, int d, int e, int f, int g);
}
extern const float lbl_805C0BBC;
/* Widget-like object with its vptr at +0x3C whose slots 28 and 30 take just a name, 40 an int. */
struct Unk80132A38_Data {
    char pad0[0x3C];
};
struct Unk80132A38_W : Unk80132A38_Data {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual void fn_vslot28(const char* name);
    virtual void fn_vslot29();
    virtual void fn_vslot30(const char* name);
    virtual void fn_vslot31();
    virtual void fn_vslot32();
    virtual void fn_vslot33();
    virtual void fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37();
    virtual void fn_vslot38();
    virtual void fn_vslot39();
    virtual void fn_vslot40(int a);
};
extern const char lbl_805C0BC8[];
extern const char lbl_805C0BD4[];
extern const char lbl_805C0BDC[];
extern const char lbl_805C0BE4[];
extern const char lbl_805C0BEC[];
extern const char lbl_805BC9DC[];
extern "C" {
Unk80132A38_W* fn_800C8040(Unk800C7B40_Widget* p);
Unk80132A38_W* fn_800C8048(Unk800C7B40_Widget* p);
}
extern int lbl_8061977C;
extern "C" int fn_80090880(int a, int b);
struct Unk80132630_Cfg {
    int m0;
    int m4;
    int m8;
    char mC[0x82];
    char m8E[0x82];
    char m110[0x82];
    char m192[0x82];
    int m214;
    int (*m218)();
    int m21C;
    int m220;
    int m224;
    int m228;
    int m22C;
    float m230;
};
extern "C" int fn_80134A60(Scr* x, Unk80132630_Cfg* c, int a);
/* Indexed access through a base pointer passed as an inline parameter (keeps `base` in a register). */
static inline void SetAt(char* b, int off, int v)
{
    *(int*)(b + off) = v;
}

static inline int KeyAt(char* b, int off)
{
    return *(int*)(b + off);
}

extern "C" {
int fn_80403060(const char* s);
void fn_80403144(char* dst, const char* src);
void fn_80134D68(Scr* x);
}
extern "C" void* fn_803774A8(unsigned n, int heap);

struct UnkI188 {
    char pad0[0x188];
    int m188;
};

extern "C" int fn_80130DFC() { return 0; }

extern "C" int fn_80130E04() { return 0; }

extern "C" int fn_80130E0C() { return 0; }

extern "C" int fn_80130E14() { return 0; }

extern "C" int fn_80130E1C() { return 1; }

extern "C" int fn_80130E24() { return 1; }

extern "C" int fn_80130E2C() { return 1; }

extern "C" int fn_80130E34() { return 1; }

extern "C" int fn_80130E3C() { return 0; }

extern "C" int fn_80130E44() { return 0; }

extern "C" int fn_80130E4C(Scr* x, int a)
{
    if (x->m134 != 0 && fn_80131278(x, a) != 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA0);
        x->fn_vslot8(0);
        x->fn_vslot16(0);
        fn_801311AC(x, 0);
        if (x->m174 != 0) {
            x->m174();
        }
        return 1;
    }
    return 0;
}

extern "C" void fn_80130EFC() {}

extern "C" void fn_80130F00() {}

extern "C" void fn_80130F04(Scr* x)
{
    if (x->m160 != 0) {
        fn_80130FB4(x, fn_800C8044(x->fn_vslot32(lbl_805C0A08, 1)), x->m160);
    }
    if (x->m164 != 0) {
        fn_80130FB4(x, fn_800C8044(x->fn_vslot32(lbl_805C0A14, 1)), x->m164);
    }
}

extern "C" void fn_80130FB4(void* unused, Unk800C7B40_Widget* w, int c)
{
    w->fn_vslot8(c != 0);
    w->fn_vslot16(c != 0);
}

static inline int IsBusy(Scr* x)
{
    if (x->m18C != 0 || x->m190 != 0) {
        return 1;
    }
    return 0;
}

extern "C" void fn_80131040(Scr* x, int which)
{
    int a = 0;
    int b = 0;
    if (IsBusy(x)) {
        a = 1;
        b = 1;
    } else if (which == 0) {
        b = 1;
    } else if (which == 1) {
        a = 1;
    }
    x->m188 = which;
    Unk800C7B40_Widget* w1 = fn_800C8044(x->fn_vslot32(lbl_805C0A08, 1));
    Unk800C7B40_Widget* w2 = fn_800C8044(x->fn_vslot32(lbl_805C0A14, 1));
    w1->fn_vslot16(b);
    w2->fn_vslot16(a);
    x->fn_vslot47(0);
    x->fn_vslot49(0);
}

extern "C" int fn_80131190(UnkI188* p) { return p->m188; }

extern "C" int fn_80131198() { return 0; }

extern "C" void fn_801311A0() {}

extern "C" int fn_801311A4() { return 0; }

extern "C" void fn_801311AC(Scr* x, int a)
{
    if (a != 0) {
        fn_800B83F8(fn_800B8144(), 1, 1);
    } else if (x->m140 == 0) {
        if (!x->b0 || (!x->fn_vslot32(lbl_805C0A08, 1)->b0 && !x->fn_vslot32(lbl_805C0A14, 1)->b0)) {
            fn_800B83F8(fn_800B8144(), 0, 0);
        }
    }
}

extern "C" int fn_80131278(Scr* x, int a)
{
    int r = 0;
    int t = x->m19C;
    if (t == -1 || a == t) {
        r = 1;
    }
    return r;
}

extern "C" void fn_80131298(Scr* x, int v, int which)
{
    if (which == 0) {
        x->m18C = v;
    } else if (which == 1) {
        x->m190 = v;
    }
}

extern "C" void fn_801312B8(Scr* x, int a, int b)
{
    FE();
    if (lbl_8061A32C->mB8 == 1) {
        int c = fn_801A4A94(fn_8011AA24(0), b);
        fn_800C3FEC(fn_800C33D0(), x, a, c);
    } else {
        fn_800C40B4(fn_800C33D0(), x, a, b);
    }
    x->fn_vslot8(1);
}

extern "C" int fn_80131378() { return 0; }

extern "C" Scr* fn_80131380(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC150(self, a, 0, c, d, e, f, g, h);
    self->SetVptr(lbl_80659AD0);
    self->m2DC = 0;
    self->m2E0 = 0;
    self->m2E4 = 0;
    self->m2E8 = 0;
    self->m2EC = 0;
    self->m2F0 = -1;
    self->m2F4 = -1;
    self->m2F8 = 0;
    self->m2FC = 0;
    self->m300 = 0;
    self->m304 = 0;
    self->m308 = lbl_805C0B78;
    self->m310 = 0;
    self->m314 = 0;
    self->m318 = 0;
    self->m31C = 0;
    self->m324 = 1;
    self->m328 = 0;
    self->mE04 = 0;
    self->mE08 = 0;
    self->mE0C = 0;
    self->mE10 = 0;
    self->mE14 = 0;
    fn_800ED310(self, 0);
    fn_800ECDCC(self, 0);
    return self;
}

extern "C" void fn_80131450(Scr* x, int chrg)
{
    x->SetVptr(lbl_80659AD0);
    if (fn_80134D58(x) == 0) {
        fn_80134CD0(x);
    }
    if (x->m328 != 0) {
        delete x->m328;
    }
    fn_800EC1B8(x, chrg);
}

extern "C" void fn_801314B8(Scr* x)
{
    fn_800ECE34(x);
    FE();
    x->mE10 = 0x280;
    FE();
    x->mE14 = 0x1E0;
    if (x->fn_vslot30(lbl_805C0B7C, 1) != 0) {
        Unk800C7B40_Widget* w = fn_800C8044(x->fn_vslot32(lbl_805C0B80, 1));
        x->mE08 = w->m26;
        x->mE0C = w->m28;
        x->mE10 = w->m2A;
        x->mE14 = w->m2C;
    }
}

extern "C" void fn_801315AC(Scr* x)
{
    fn_800ECF18(x);
}

extern "C" void fn_801315CC(Scr* x)
{
    fn_800EC84C(x);
    int f = x->b0;
    if (f != 0) {
        f = 1;
    }
    x->m318 = f;
}

extern "C" int fn_80131610(Scr* x, int a)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    if (lbl_8061A32C->mB8 != 0) {
        x->fn_vslot41(a);
        return 1;
    }
    return 0;
}

/* near-miss: 63/63 insns, one swap: retail loads `li r4,0` before `li r29,1` in the second arm. Tried four orders of m310=0 / r=1. */
extern "C" int fn_80131698(Scr* x, int a)
{
    int r = 0;
    if (fn_80134618(x, a) != 0 && x->m2F8 != 2 && x->m2FC > 0) {
        x->m310 = 0;
        r = 1;
        fn_801318D0(x, fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1))->fn_vslot60(), a);
    } else if (fn_80134618(x, a) != 0 && x->m2F8 != 2 && x->m30C != 0) {
        x->m310 = 0;
        r = 1;
        fn_801318D0(x, 0, a);
    }
    return r;
}

extern "C" void fn_80131794(Scr* x)
{
    if (x->m2FC > 0) {
        x->m310 = 0;
        fn_801318D0(x, fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1))->fn_vslot60(), x->m2F0);
    }
}

extern "C" int fn_80131820(Scr* x, int a)
{
    if (fn_80134618(x, a) != 0 && x->m2F8 != 2 && fn_80131970(x) != 0) {
        if (x->m31C == 0 && x->fn_vslot91() != 0) {
            fn_8001BC4C()->fn_8001BDAC(0xA0);
        }
        x->m31C = 0;
        x->fn_vslot89(1);
    }
    return 1;
}

extern "C" void fn_801318D0(Scr* x, int a, int b)
{
    x->m2F4 = b;
    x->fn_vslot89(1);
    if (x->m31C == 0 && x->fn_vslot91() != 0) {
        fn_8001BC4C()->fn_8001BDAC(0x9D);
    }
    x->m31C = 0;
    x->m2DC(a, x->m148);
}

extern "C" int fn_80131970(Scr* x)
{
    if (x->m2E0() != 0) {
        x->fn_vslot87();
        return 1;
    }
    return 0;
}

extern "C" int fn_801319D0(Scr* x, int a)
{
    int r = 0;
    if (fn_80134618(x, a) != 0) {
        r = 1;
        fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1))->fn_vslot50();
    }
    return r;
}

extern "C" int fn_80131A50(Scr* x, int a)
{
    int r = 0;
    if (fn_80134618(x, a) != 0) {
        r = 1;
        fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1))->fn_vslot51();
    }
    return r;
}

extern "C" int fn_80131AD0(Scr* x, int a)
{
    int r = 0;
    if (fn_80134618(x, a) != 0) {
        r = 1;
        fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1))->fn_vslot52();
    }
    return r;
}

extern "C" int fn_80131B50(Scr* x, int a)
{
    int r = 0;
    if (fn_80134618(x, a) != 0) {
        r = 1;
        fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1))->fn_vslot53();
    }
    return r;
}

extern "C" int fn_80131BD0(Scr* x, Unk800C7B40_Widget* a, int b, int c)
{
    if (a == fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1))) {
        fn_801318D0(x, c, -1);
        return 1;
    }
    return 0;
}

extern "C" void fn_80131C48(Scr* x, int a, float f)
{
    x->m2F8 = a;
    if (x->fn_vslot30(lbl_805C0B7C, 1) != 0) {
        switch (x->m2F8) {
        case 0:
            x->fn_vslot32(lbl_805C0B94, 1)->fn_vslot8(1);
            x->fn_vslot32(lbl_805C0B9C, 1)->fn_vslot8(0);
            x->fn_vslot32(lbl_805C0BA4, 1)->fn_vslot8(x->m30C);
            break;
        case 1:
            x->fn_vslot32(lbl_805C0B94, 1)->fn_vslot8(0);
            x->fn_vslot32(lbl_805C0B9C, 1)->fn_vslot8(1);
            x->fn_vslot32(lbl_805C0BA4, 1)->fn_vslot8(0);
            break;
        case 2:
            x->fn_vslot32(lbl_805C0B94, 1)->fn_vslot8(1);
            x->fn_vslot32(lbl_805C0B9C, 1)->fn_vslot8(0);
            x->fn_vslot32(lbl_805C0BA4, 1)->fn_vslot8(f > 0.0f);
            x->m308 = f >? 0.2f;
            break;
        }
    }
}

extern "C" void fn_80131F34(Scr* x, int a1, int (*a2)(int, int), int (*a3)(), int a4, int a5, int a6, int a7, int s8, int sC, int s10, int s14, int s18, int s1C)
{
    fn_80134680(x);
    x->m30C = s1C;
    fn_80131C48(x, 0, 0.0f);
    x->fn_vslot16(0);
    x->fn_vslot8(0);
    x->m2DC = a2;
    fn_801345F8(x, a3);
    x->fn_vslot88(a1);
    Unk800C7B40_Widget* w = fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1));
    w->fn_vslot79(a5, 0);
    w->fn_vslot3();
    x->m324 = a7;
    x->m2FC = a5;
    int v0;
    if (a4 != 0) {
        v0 = fn_80090880(lbl_8061977C, a4);
    } else {
        v0 = 0;
    }
    int v1;
    if (s8 != 0) {
        v1 = fn_80090880(lbl_8061977C, s8);
    } else {
        v1 = 0;
    }
    int v2;
    if (sC != 0) {
        v2 = fn_80090880(lbl_8061977C, sC);
    } else {
        v2 = 0;
    }
    int v3;
    if (s10 != 0) {
        v3 = fn_80090880(lbl_8061977C, s10);
    } else {
        v3 = 0;
    }
    int v4;
    if (s14 != 0) {
        v4 = fn_80090880(lbl_8061977C, s14);
    } else {
        v4 = 0;
    }
    fn_80132830(x, v0, a5, (char*)v1, (char*)v2, (char*)v3, (char*)v4, s18);
    fn_80132A38(x);
    if (x->fn_vslot30(lbl_805C0B7C, 1) != 0) {
        fn_80132C00(x, 1, 0x19, 4, 0xC, 0xC, 0xC, a6);
    } else {
        fn_80132C00(x, 0, 0x19, 0xC, 0xC, 0xC, 0, a6);
    }
    fn_80134D74(x);
}

extern "C" void fn_801321D4(Scr* x, int a1, int (*a2)(int, int), int (*a3)(), int a4, int a5, int a6, int a7, char* s8, char* sC, char* s10, char* s14, int s18, int s1C)
{
    fn_80134680(x);
    x->m30C = s1C;
    fn_80131C48(x, 0, lbl_805C0BBC);
    x->fn_vslot16(0);
    x->fn_vslot8(0);
    x->m2DC = a2;
    fn_801345F8(x, a3);
    x->fn_vslot88(a1);
    Unk800C7B40_Widget* w = fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1));
    w->fn_vslot79(a5, 0);
    w->fn_vslot3();
    x->m324 = a7;
    x->m2FC = a5;
    fn_80132830(x, a4, a5, s8, sC, s10, s14, s18);
    fn_80132A38(x);
    if (x->fn_vslot30(lbl_805C0B7C, 1) != 0) {
        fn_80132C00(x, 1, 0x19, 4, 0xC, 0xC, 0xC, a6);
    } else {
        fn_80132C00(x, 0, 0x19, 0xC, 0xC, 0xC, 0, a6);
    }
    fn_80134D74(x);
}

extern "C" void fn_801323C8(Scr* self, int a, int (*b)(int, int), int (*c)(), int d, int e, int f, int g, char* h, char* i, char* j, char* k, int l)
{
    fn_801321D4(self, a, b, c, d, e, f, g, h, i, j, k, l, 0);
    fn_80131C48(self, 1, lbl_805C0BC4);
}

extern "C" void fn_80132438(Scr* x, int a1, int a2, int a3, int a4, int a5, int a6, int a7, float f)
{
    fn_80134680(x);
    x->fn_vslot16(0);
    x->fn_vslot8(0);
    fn_80131C48(x, 2, f);
    x->m2E4 = a3;
    x->m2E8 = a2;
    x->m2EC = a4;
    x->fn_vslot88(a1);
    Unk800C7B40_Widget* w = fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1));
    w->fn_vslot79(0, 0);
    w->fn_vslot3();
    x->m324 = a7;
    x->m2FC = 0;
    int v;
    if (a5 != 0) {
        v = fn_80090880(lbl_8061977C, a5);
    } else {
        v = 0;
    }
    fn_80132830(x, v, 0, 0, 0, 0, 0, 0);
    fn_80132A38(x);
    if (x->fn_vslot30(lbl_805C0B7C, 1) != 0) {
        fn_80132C00(x, 1, 0x19, 4, 0xC, 0xC, 0xC, a6);
    } else {
        fn_80132C00(x, 0, 0x19, 0xC, 0xC, 0xC, 0, a6);
    }
    fn_80134D74(x);
}

/* fn_80134A60 returns int (ends li r3,0): with a void declaration the r3 argument move won the sched2 tie */
extern "C" void fn_80132630(Scr* x, int a)
{
    fn_80134680(x);
    x->fn_vslot16(0);
    x->fn_vslot8(0);
    Unk80132630_Cfg* c = (Unk80132630_Cfg*)operator new(0x234, 0x100);
    fn_80134A60(x, c, a);
    x->m2DC = (int (*)(int, int))c->m214;
    fn_801345F8(x, c->m218);
    x->m2E4 = c->m220;
    x->m2E8 = c->m21C;
    x->fn_vslot88(c->m0);
    fn_80131C48(x, c->m22C, c->m230);
    Unk800C7B40_Widget* w = fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1));
    w->fn_vslot79(c->m8, 0);
    w->fn_vslot3();
    int t = c->m8;
    x->m324 = c->m228;
    x->m2FC = t;
    fn_80132830(x, c->m4, t, c->mC, c->m8E, c->m110, c->m192, 0);
    fn_80132A38(x);
    if (x->fn_vslot30(lbl_805C0B7C, 1) != 0) {
        fn_80132C00(x, 1, 0x19, 4, 0xC, 0xC, 0xC, c->m224);
    } else {
        fn_80132C00(x, 0, 0x19, 0xC, 0xC, 0xC, 0, c->m224);
    }
    fn_80134D74(x);
    delete c;
}

extern "C" void fn_80132830(Scr* x, int a, int b, char* c, char* d, char* e, char* f, int g)
{
    if (x->m328 != 0) {
        fn_80377408(x->m328);
        x->m328 = 0;
    }
    if (a != 0) {
        if (g != 0) {
            char buf[0x50];
            int dd[2];
            fn_80329FA0(dd, fn_800A2AE8(lbl_80619948));
            fn_800DD44C(dd, buf, 0);
            x->m328 = (char*)fn_803774A8((fn_80403060((char*)a) + fn_80403060(buf) + fn_80403060((char*)fn_80090880(lbl_8061977C, 0x2393)) + 2) * 2, 0x100);
            char* t = (char*)fn_803774A8((fn_80403060((char*)a) + 1) * 2, 0x100);
            fn_80403144(t, (char*)a);
            fn_8040321C(x->m328, fn_80090880(lbl_8061977C, 0x2393), buf, t);
            fn_80377408(t);
        } else {
            x->m328 = (char*)fn_803774A8((fn_80403060((char*)a) + 1) * 2, 0x100);
            fn_80403144(x->m328, (char*)a);
        }
    } else {
        x->m328 = (char*)a;
    }
    if (x->m2FC > 0) {
        int nc = fn_80403060(c);
        fn_8040316C((char*)x + 0x32C, c, nc);
        *(short*)((char*)x + 0x3AC) = 0;
        if (x->m2FC > 1) {
            int nd = fn_80403060(d);
            fn_8040316C((char*)x + 0x3AE, d, nd);
            *(short*)((char*)x + 0x42E) = 0;
            if (x->m2FC > 2) {
                int ne = fn_80403060(e);
                fn_8040316C((char*)x + 0x430, e, ne);
                *(short*)((char*)x + 0x4B0) = 0;
                if (x->m2FC > 3) {
                    int nf = fn_80403060(f);
                    fn_8040316C((char*)x + 0x4B2, f, nf);
                    *(short*)((char*)x + 0x532) = 0;
                }
            }
        }
    }
}

extern "C" void fn_80132A38(Scr* x)
{
    Unk80132A38_W* w = fn_800C8040(x->fn_vslot32(lbl_805C0BC8, 1));
    w->fn_vslot40(x->m324);
    if (x->m328 != 0) {
        w->fn_vslot28(x->m328);
    } else {
        w->fn_vslot30(lbl_805BC9DC);
    }
    fn_800C8048(x->fn_vslot32(lbl_805C0BD4, 1))->fn_vslot28((char*)x + 0x32C);
    fn_800C8048(x->fn_vslot32(lbl_805C0BDC, 1))->fn_vslot28((char*)x + 0x3AE);
    fn_800C8048(x->fn_vslot32(lbl_805C0BE4, 1))->fn_vslot28((char*)x + 0x430);
    fn_800C8048(x->fn_vslot32(lbl_805C0BEC, 1))->fn_vslot28((char*)x + 0x4B2);
}

extern "C" void fn_8013440C(Scr* x)
{
    fn_802DC9C0();
    if (x->m31C == 0) {
        if (x->fn_vslot90() != 0) {
            fn_8001BC4C()->fn_8001BDAC(0x9D);
        }
    }
    x->m31C = 0;
    x->fn_vslot89(0);
    if (x->fn_vslot30(lbl_805C0B7C, 1) != 0) {
        fn_800C8068(x->fn_vslot32(lbl_805C0C1C, 1))->fn_vslot14(1);
    }
    Unk800C7B40_Widget* w = fn_800C8060(x->fn_vslot32(lbl_805C0B8C, 1));
    w->fn_vslot68(0);
    w->fn_vslot14(1);
}

extern "C" void fn_80134568(Scr* x)
{
    if (x->m320 != 0) {
        Unk800C7B40_Widget* w = x->fn_vslot28(lbl_805C0C70);
        if (w != 0) {
            w->fn_vslot8(0);
        }
        x->m320 = 0;
    }
    x->m2F4 = -1;
    fn_800EC278(x);
}

extern "C" void fn_801345F8(Scr* x, int (*f)())
{
    if (f != 0) {
        x->m2E0 = f;
    } else {
        x->m2E0 = fn_8013484C;
    }
}

struct UnkFEState {
    char pad0[0x570];
    int m570;
};
extern "C" UnkFEState* fn_800B555C();
extern "C" int fn_80134618(Scr* x, int a)
{
    int t = x->m2F0;
    if (t == -99) {
        int s = fn_800B555C()->m570;
        return a == s || s == -1;
    }
    return t == -1 || a == t;
}

extern "C" void fn_80134680(Scr* x)
{
    x->m2DC = 0;
    x->m2E0 = 0;
    x->m2E4 = 0;
    x->m2E8 = 0;
    x->m2EC = 0;
    fn_80131C48(x, 0, lbl_805C0C84);
    x->m304 = 0;
    x->m314 = 0;
    x->m30C = 0;
    if (x->b1) {
        x->fn_vslot87();
    }
}

extern "C" void fn_80134700(Scr* x)
{
    if (x->b1) {
        fn_800ECAA4(x);
        if (x->m2F8 == 2) {
            if (!(x->m308 <= 0.0f)) {
                if (x->m318 == 0)
                    return;
                if (!(x->m308 <= 0.0f) && x->m318 == 1 && x->m304 <= 0)
                    x->m304 = lbl_8061A328 + (int)(x->m308 * 60.0f);
            }
            if (x->m314 == 1) {
                if (lbl_8061A328 >= x->m304) {
                    if (x->m2E4 != 0)
                        ((void (*)(int))x->m2E4)(x->m148);
                    fn_800EC278(x);
                }
            } else {
                if (lbl_8061A328 >= x->m304 && x->m2EC != 0 && x->m318 == 1)
                    ((void (*)(int))x->m2EC)(x->m148);
                if (x->m2E8 != 0 && x->m318 == 1)
                    ((void (*)(int))x->m2E8)(x->m148);
            }
        }
    }
}

extern "C" int fn_8013484C() { return 0; }

extern "C" void fn_80134854() {}

/* near-miss: 130/130 insns, 8 slots: operand order of the four add r3,r3,r31 (retail adds the scaled index first) and which of r0/r9 holds the index in the m2FC store */
extern "C" int fn_80134858(Scr* x)
{
    if (x->m148 == 0) {
        fn_80134D68(x);
        return 0;
    }
    if (x->m328 == 0) {
        x->m328 = (char*)fn_803774A8(2, 0x100);
    }
    char* b = (char*)x + 0x538;
    int n = (fn_80403060(x->m328) + 1) * 2;
    int idx = x->mE04 * 0x234;
    SetAt(b, idx, (int)fn_803774A8(n, 0x100));
    fn_80403144((char*)KeyAt(b, x->mE04 * 0x234), x->m328);
    SetAt((char*)x + 0x53C, x->mE04 * 0x234, x->m2FC);
    if (x->m2FC > 0) {
        fn_80403144((char*)x + x->mE04 * 0x234 + 0x540, (char*)x + 0x32C);
    }
    if (x->m2FC > 1) {
        fn_80403144((char*)x + x->mE04 * 0x234 + 0x5C2, (char*)x + 0x3AE);
    }
    if (x->m2FC > 2) {
        fn_80403144((char*)x + x->mE04 * 0x234 + 0x644, (char*)x + 0x430);
    }
    if (x->m2FC > 3) {
        fn_80403144((char*)x + x->mE04 * 0x234 + 0x6C6, (char*)x + 0x4B2);
    }
    char* p534 = (char*)x + 0x534;
    char* p748 = (char*)x + 0x748;
    char* p74C = (char*)x + 0x74C;
    char* p754 = (char*)x + 0x754;
    char* p750 = (char*)x + 0x750;
    char* p758 = (char*)x + 0x758;
    char* p75C = (char*)x + 0x75C;
    char* p760 = (char*)x + 0x760;
    char* p764 = (char*)x + 0x764;
    SetAt(p534, x->mE04 * 0x234, x->m148);
    SetAt(p748, x->mE04 * 0x234, (int)x->m2DC);
    SetAt(p74C, x->mE04 * 0x234, (int)x->m2E0);
    SetAt(p754, x->mE04 * 0x234, x->m2E4);
    SetAt(p750, x->mE04 * 0x234, x->m2E8);
    SetAt(p758, x->mE04 * 0x234, x->m300);
    SetAt(p75C, x->mE04 * 0x234, x->m324);
    SetAt(p760, x->mE04 * 0x234, x->m2F8);
    *(float*)(p764 + x->mE04 * 0x234) = x->m308;
    x->mE04 = x->mE04 + 1;
    fn_80134D68(x);
    return 1;
}
