/*
 * Game code, .text 0x80134A60-0x80137FFC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"

#include "game/tu_8001B190.h"

struct UnkFEState {
    char pad0[0x4F0];
    int m4F0;
    char pad4F4[0x7C];
    int m570;
};
Unk8001BC8C* fn_8001BC4C();
extern const char lbl_80656498[];
extern const char lbl_806564B0[];
extern const char lbl_8064D320[];
extern int lbl_8061B5A0;

/* Front-end screen with a 4-entry table at +0x148 (0x1C-byte entries: value, key, ...). */
/* Widget-like object with its vptr at +0x3C whose slots 28 and 30 take just a name. */
struct Unk801361EC_Data {
    char pad0[0x3C];
};
struct Unk801361EC_W : Unk801361EC_Data {
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
};
struct Unk801361EC_Arg {
    char pad0[0xC];
    const char* mC;
};
struct Unk80136C3C {
    char pad0[0x148];
    int m148;
};
struct Unk8061930C_Obj {};

struct Unk803567AC_V {
    int m0;
    int m4;
};
struct Unk80134F48 {
    char pad0[0x28];
    int m28;
    int m2C;
    char pad30[0x10];
    int m40;
    int m44;
};
struct Unk80135D90 {
    char pad0[0x134];
    int m134;
    char pad138[0xB4];
    int m1EC;
};
struct Unk80135ED4 {
    char pad0[0x1D8];
    const char* m1D8;
    int m1DC;
};
/* Front-end screen class (ctor fn_80136A14 / fn_80137F4C; lbl_8061B59C holds the live instance). */
struct Unk80354D4_Obj : Unk800C7B40_Widget {    /* object at +0x180: the unit-2 screen class, +0x2F0 */
    char pad40[0x2B0];
    int m2F0;
};
struct Unk80135680 : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    char pad144[0x38];
    const void* m17C;
    Unk80354D4_Obj* m180;
    int m184[12];
    int m1B4[8];
    int m1D4;
    const char* m1D8;
    int m1DC;
    int m1E0;
    int m1E4;
    int m1E8;
    int m1EC;
};
typedef Unk80135680 Scr;
extern Scr* lbl_8061B59C;
extern Scr* lbl_8061930C;
struct Unk8061A32C {
    char padB8[0xB8];
    int mB8;
};
extern Unk8061A32C* lbl_8061A32C;
extern const char lbl_805BA6D8[];
extern const char lbl_805BA744[];
extern const char lbl_805BC9DC[];
extern const char lbl_805BEC94[];
static inline Unk8061A32C* FE();
extern "C" {
Unk8061A32C* fn_800B64BC(void* p);
Scr* fn_800B7A94(Unk8061A32C* m, const char* name);
void fn_801725C4(int a, int b);
void fn_80136864();
void fn_80136250(Scr* x, int a, int b, int c);
Unk801361EC_W* fn_800C8040(Unk800C7B40_Widget* p);
void fn_801361EC(Scr* x, Unk801361EC_Arg* a, Unk801361EC_W* w);
UnkFEState* fn_800B555C();
Unk803567AC_V fn_803567AC();
void fn_80072E90(Scr* g, int a, int b, int c, int d, Unk803567AC_V* v);
void fn_801354D4(Scr* g);
void fn_801723F8(int a, int b);
void fn_80135200(Scr* x, int chrg);
void fn_801365F4(Scr* x);
void fn_80172514(int a);
char* fn_8040B61C(char* dst, const char* src);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_800ECE34(void* x);
void fn_80138080(void* x);
int fn_800ED2B0(void* x, int a);
void fn_800CFB38();
}

/* 0x1C-byte table entries: the base pointer goes through an inline parameter, which keeps
 * `x + 0x14C` in a register and gives the indexed loads of retail. */
static inline int KeyAt(char* b, int off)
{
    return *(int*)(b + off);
}
static inline void SetAt(char* b, int off, int v)
{
    *(int*)(b + off) = v;
}
static inline Unk8061A32C* FE()
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    return lbl_8061A32C;
}
extern const char lbl_8064C578[];
extern const char lbl_80656758[];
extern const char lbl_80656770[];
extern "C" {
void fn_800B7ADC(Unk8061A32C* m, Scr* x);
void fn_80134EC8(int* p, int a);
void fn_8035686C(void* x, int chrg);
}

struct UnkI31C {
    char pad0[0x31C];
    int m31C;
};
struct UnkW1DC : Unk800C7B40_Widget {
    char pad40[0x19C];
    Unk800C7B40_Widget* m1DC;
};

struct Unk80134D58 {
    char pad0[0xE04];
    int mE04;
};
extern "C" int fn_80134D58(Unk80134D58* x)
{
    return x->mE04 == 0;
}

extern "C" void fn_80134D68(UnkI31C* x)
{
    x->m31C = 1;
}

/* near-miss: 21/20 insns: retail keeps no register for &v (addi r3,r1,8 and addi r8,r1,8 after the call, frame 0x18); here the 8-byte local lives in r29. Tried inline wrappers, int[2], struct return. */
extern "C" void fn_80134F48(Unk80134F48* x)
{
    Unk803567AC_V v;
    fn_803567AC(&v);
    fn_80072E90(lbl_8061930C, x->m40, x->m44, x->m28, x->m2C, &v);
}

extern "C" void fn_80135200(Scr* x, int chrg)
{
    x->m17C = lbl_80656758;
    x->SetVptr(lbl_80656770);
    x->m180 = 0;
    fn_80134EC8(&x->m134, 0);
    fn_8035686C(x, chrg);
}

extern "C" void fn_80135264(Scr* x)
{
    FE();
    x->m180 = (Unk80354D4_Obj*)fn_800B7A94(lbl_8061A32C, lbl_805BA6D8);
    lbl_8061B59C = x;
    fn_801354D4(x);
}

extern "C" int fn_801352D4() { return 0; }

extern "C" void fn_801352DC(int i)
{
    fn_801354D4(lbl_8061B59C);
    fn_801723F8(lbl_8061B59C->m134, lbl_8061B59C->m184[i]);
}

extern "C" void fn_801354D4(Scr* x)
{
    if (x->m1D4 != 0) {
        x->m180->fn_vslot87();
        x->m1D4 = 0;
        x->m180->m2F0 = -1;
    }
}

extern "C" void fn_8013563C(Scr* x, int chrg)
{
    x->m17C = lbl_80656498;
    x->SetVptr(lbl_806564B0);
    x->m1E4 = 0;
    fn_80135200(x, chrg);
}

extern "C" void fn_80135D54(Scr* x)
{
    fn_800B555C()->m4F0 = 0;
    fn_801365F4(x);
}

extern "C" int fn_80135D90(Scr* x)
{
    fn_800B555C()->m4F0 = 0;
    fn_80172514(x->m134);
    fn_8001BC4C()->fn_8001BDAC(0xA0);
    x->m1EC = 1;
    return 1;
}

extern "C" int fn_80135DE4(UnkW1DC* x)
{
    x->m1DC->fn_vslot50();
    return 1;
}

extern "C" int fn_80135E20(UnkW1DC* x)
{
    x->m1DC->fn_vslot51();
    return 1;
}

extern "C" int fn_80135E5C(UnkW1DC* x)
{
    x->m1DC->fn_vslot52();
    return 1;
}

extern "C" int fn_80135E98(UnkW1DC* x)
{
    x->m1DC->fn_vslot53();
    return 1;
}

extern "C" int fn_80135ED4(Scr* x, int a)
{
    if (a == x->m1DC) {
        fn_801365F4(x);
    }
    return 0;
}

extern "C" void fn_80135F04(Scr* x, char* buf)
{
    buf[0] = 0;
    fn_8040B61C(buf, x->m1D8);
}

extern "C" void fn_80135F38(int a)
{
    FE();
    Scr* o = fn_800B7A94(lbl_8061A32C, lbl_805BA744);
    fn_80136864();
    fn_801725C4(o->m134, a);
}

extern "C" void fn_80135FA8()
{
    FE();
    Scr* o = fn_800B7A94(lbl_8061A32C, lbl_805BA744);
    fn_80136864();
    fn_801725C4(o->m134, 0);
}

extern "C" void fn_80136174(Scr* x, Unk801361EC_Arg* a)
{
    fn_801361EC(x, a, fn_800C8040(x->fn_vslot32(lbl_805BEC94, 1)));
    fn_80136250(x, (int)a, x->m1DC, 1);
}

extern "C" void fn_801361EC(Scr* unused, Unk801361EC_Arg* a, Unk801361EC_W* w)
{
    if (a != 0) {
        w->fn_vslot28(a->mC);
    } else {
        w->fn_vslot30(lbl_805BC9DC);
    }
}

extern "C" void fn_801369B8(Scr* x, const char* s)
{
    x->m1D8 = s;
    FE();
    fn_800B7ADC(lbl_8061A32C, x);
}

extern "C" Scr* fn_80136A14(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8064D320);
    self->m134 = 1;
    self->m138 = 1;
    return self;
}

extern "C" void fn_80136A6C(Scr* x, int k, int v)
{
    if (k == 1) {
        x->m134 = v;
    } else {
        x->m138 = v;
    }
}

extern "C" int fn_80136A84(Scr* x, int k)
{
    if (k == 1) {
        return x->m134;
    }
    return x->m138;
}

extern "C" void fn_80136C3C(Unk80136C3C* x, int key, int v)
{
    int off = 0;
    for (int i = 0; i < 4; i++) {
        if (KeyAt((char*)x + 0x14C, off) == key) {
            SetAt((char*)x + 0x148, off, v);
            return;
        }
        off += 0x1C;
    }
}

extern "C" int fn_80136C70(Unk80136C3C* x, int key)
{
    int i = 0;
    int off = 0;
    for (int n = 0; n < 4; n++) {
        if (KeyAt((char*)x + 0x14C, off) == key) {
            return i;
        }
        off += 0x1C;
        i++;
    }
    return -1;
}

extern "C" int fn_80136CA8(Unk80136C3C* x, int i)
{
    return KeyAt((char*)x + 0x14C, i * 0x1C);
}

extern "C" int fn_80137848() { return 0; }

extern "C" int fn_80137A58() { return 0; }

extern "C" Scr* fn_80137F4C(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8064C578);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    return self;
}

extern "C" void fn_80137FA8(Scr* x)
{
    fn_800ECE34(x);
    fn_80138080(x);
    x->m134 = fn_800ED2B0(x, lbl_8061B5A0);
    if (x->m134 != 0) {
        fn_800CFB38();
    }
}
