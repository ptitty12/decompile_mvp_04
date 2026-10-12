/*
 * Game code, .text 0x80134A60-0x80137FFC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"

#include "game/tu_8001B190.h"

struct Unk80172120_Data {
    char pad0[0x120];
};
struct Unk80172120_Obj : Unk80172120_Data {
    virtual ~Unk80172120_Obj();
};
struct Unk80134E38 {
    Unk80172120_Obj* m0;
    int m4;
    char pad8[0x20];
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    const void* m48;
};
extern const char lbl_80656A18[];

struct UnkFEState {
    char pad0[0x4E8];
    int m4E8;
    char pad4EC[4];
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

/* Same class as in include/game/tu_80355A6C.h (that header conflicts with this unit's
   declarations): 8 bytes, out-of-line ctor __11Unk803567AC. The trivial destructor makes
   the local BLKmode, so its address is rebuilt (`addi rN,r1,8`) at each call. */
struct Unk803567AC {
    int m0;
    const void* m4;
    Unk803567AC();
    ~Unk803567AC() {}
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
    char pad144[0x18];
    int m15C;
    int m160;
    char pad164[0x18];
    const void* m17C;
    Unk80354D4_Obj* m180;
    int m184[12];
    int m1B4[8];
    int m1D4;
    const char* m1D8;
    int m1DC;
    Unk800C7B40_Widget* m1E0;
    Unk800C7B40_Widget* m1E4;
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
struct Unk800A3E6C;
extern Unk800A3E6C* lbl_80619948;
int fn_800E2BAC();
void fn_800E2BCC();
/* Polymorphic 8-byte object built by fn_80353218 (m0 = 0, vptr lbl_8064B718 at +4); same class as in tu_800A23F4.cpp. */
struct Unk80353218 {
    int m0;
    Unk80353218();
    virtual void vf0();
};
extern "C" {
Unk8061A32C* fn_800B64BC(void* p);
Scr* fn_800B7A94(Unk8061A32C* m, const char* name);
void fn_801725C4(int a, int b);
void fn_80136864(Scr* x);
void fn_80136250(Scr* x, int a, int b, int c);
Unk801361EC_W* fn_800C8040(Unk800C7B40_Widget* p);
void fn_801361EC(Scr* x, Unk801361EC_Arg* a, Unk801361EC_W* w);
UnkFEState* fn_800B555C();
void fn_80072E90(Scr* g, int a, int b, int c, int d, Unk803567AC* v);
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
void fn_800A3DF8(Unk800A3E6C* o, int a, int b, int c, int d);
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
void fn_80134EC8(Unk80134E38* s, int chrg);
void fn_8035686C(void* x, int chrg);
}
extern const char lbl_805C0CD4[];
extern const char lbl_805C0CC0[];
extern const char lbl_8065C4E0[];
extern "C" {
void fn_800C2034(void* p, int a);
void fn_801369B8(Scr* x, const char* s);

}
struct Unk8017191C_Ret {
    int m0;
    int m4;
};
struct Unk80136A14_Obj {
    char pad0[0x48];
    int m48;
    int m4C;
};
extern const char lbl_8064D040[];
extern "C" {
void fn_8013C0A8(Unk800C7B40_Widget* x, int a, int b, int c);
void fn_8013D0E0(Unk800C7B40_Widget* x, int s);
int fn_801718E8(void* p);
Unk8017191C_Ret* fn_8017191C(void* p, int a);
void fn_80172564(int a, int b);

}
extern const char lbl_805BE348[];
extern const char lbl_805BE33C[];
extern const char lbl_80656A18[];
extern "C" {
Unk80172120_Obj* fn_80172120(void* p);
Unk80134E38* fn_80134E38(Unk80134E38* s, int a);
void fn_802B9000();
void fn_802B9058();
void fn_802B961C(int p, int a);
void fn_801350F8(Unk80134E38* s, int a);
void fn_80377488(int p);
}
struct Unk80134D58 {
    char pad0[0xE04];
    int mE04;
};
extern "C" void fn_803FFC58(char* p, int v, int n);
struct Unk80134D74 : Unk800C7B40_Widget {
    char pad40[0xDC4];
    int mE04;
    int mE08;
    int mE0C;
    int mE10;
    int mE14;
};
extern const char lbl_805C0B80[];
extern "C" Unk800C7B40_Widget* fn_800C8044(Unk800C7B40_Widget* p);
extern const char lbl_805C0C90[];
extern const char lbl_805C0C9C[];
extern "C" {
void* fn_800C33D0();
void fn_800C3A4C();
int fn_80073610(Scr* g, int* p, int a);
int fn_802B9300(const char* name, int a, int b, int* p);
void fn_8017227C(Unk80172120_Obj* o, int a, int b, int c);
}
struct Unk800B555C_P8 {
    char pad0[0x4C4];
    int m4C4;
    int m4C8;
    int m4CC;
    int m4D0;
};
extern const char lbl_805C0CA8[];
extern "C" {
void fn_80403144(unsigned short* dst, int src);
void fn_80172334(int a, int b, int c, int d, const char* e);
}
extern "C" void fn_801368FC(Scr* x);
struct Unk80135680_Txt : Unk800C7B40_Widget {
    char pad40[0x2A0];
    void (*m2E0)(int);
    char pad2E4[0xC8];
    void (*m3AC)();
};
extern const char lbl_805BAFF8[];
extern const char lbl_805C0CB4[];
extern "C" {
void fn_80124FA8(Unk800C7B40_Widget* w, Scr* x);
void fn_80125100(Unk800C7B40_Widget* w);
void fn_80125180(Unk800C7B40_Widget* w, int a, int b);
void fn_8013D164(Unk80135680_Txt* t, int v);
void fn_80135264(Scr* x);
void fn_80135F38(int a);
void fn_80135FA8();
void fn_80136014(Scr* x);
void fn_80136174(Scr* x, Unk801361EC_Arg* a);
Unk800C7B40_Widget* fn_800C8060(Unk800C7B40_Widget* p);
void fn_80136864(Scr* x);
}

extern const char lbl_805BA6D0[];

struct UnkI31C {
    char pad0[0x31C];
    int m31C;
};
struct UnkW1DC : Unk800C7B40_Widget {
    char pad40[0x19C];
    Unk800C7B40_Widget* m1DC;
};

extern "C" int fn_80134CD0(Unk80134D58* x)
{
    int i = 0;
    if (i < x->mE04) {
        char* p = (char*)x + 0x534;
        int off = 0;
        do {
            char* q = (char*)KeyAt((char*)x + 0x538, off);
            if (q != 0) {
                delete q;
            }
            fn_803FFC58(p, 0, 0x234);
            i = i + 1;
            p = p + 0x234;
            off = off + 0x234;
        } while (i < x->mE04);
    }
    x->mE04 = 0;
    return 1;
}

extern "C" int fn_80134D58(Unk80134D58* x)
{
    return x->mE04 == 0;
}

extern "C" void fn_80134D68(UnkI31C* x)
{
    x->m31C = 1;
}

extern "C" void fn_80134D74(Unk80134D74* x)
{
    Unk800C7B40_Widget* w = fn_800C8044(x->fn_vslot32(lbl_805C0B80, 1));
    int h = w->m2C;
    w->fn_vslot9(x->mE08 + (x->mE10 - w->m2A) / 2);
    w->fn_vslot10(x->mE0C + (x->mE14 - h) / 2);
}

extern "C" Unk80134E38* fn_80134E38(Unk80134E38* s, int a)
{
    s->m48 = lbl_80656A18;
    s->m0 = 0;
    s->m4 = 6;
    s->m28 = 0x11;
    s->m2C = 0;
    s->m30 = 0;
    s->m34 = 0;
    s->m38 = 0;
    s->m3C = 0;
    s->m40 = 0;
    s->m44 = 0;
    s->m0 = fn_80172120(operator new(0x124, 0x100));
    if (a == 0) {
        fn_802B9000();
    }
    return s;
}

extern "C" void fn_80134EC8(Unk80134E38* s, int chrg)
{
    s->m48 = lbl_80656A18;
    fn_801350F8(s, 0);
    if (s->m0 != 0) {
        delete s->m0;
        s->m0 = 0;
    }
    if (chrg & 1) {
        delete s;
    }
}

extern "C" void fn_80134F48(Unk80134F48* x)
{
    Unk803567AC v;
    fn_80072E90(lbl_8061930C, x->m40, x->m44, x->m28, x->m2C, &v);
}

extern "C" void fn_80134F98(Unk80134F48* x)
{
    if (x->m28 & 0x3000000) {
        fn_800E2BAC();
        fn_800A3DF8(lbl_80619948, x->m40, x->m44, x->m28, x->m2C);
        fn_800E2BCC();
    } else {
        Unk80353218 v;
        fn_80072E90(lbl_8061930C, x->m40, x->m44, x->m28, x->m2C, (Unk803567AC*)&v);
    }
}

extern "C" void fn_8013501C(Unk80134E38* s)
{
    fn_801350F8(s, 1);
    fn_800C33D0();
    fn_800C3A4C();
    s->m40 = fn_80073610(lbl_8061930C, &s->m44, s->m28);
    if (s->m30 == 0) {
        s->m30 = fn_802B9300(lbl_805C0C90, 0x100, 10, &s->m34);
    }
    if (s->m38 == 0) {
        s->m38 = fn_802B9300(lbl_805C0C9C, 0x100, 10, &s->m3C);
    }
    fn_8017227C(s->m0, s->m40, s->m44, 1);
    fn_8017227C(s->m0, s->m30, s->m34, 2);
    fn_8017227C(s->m0, s->m38, s->m3C, 3);
}

extern "C" void fn_801350F8(Unk80134E38* s, int a)
{
    if (a == 0) {
        if (s->m30 != 0) {
            fn_802B961C(s->m30, 10);
            s->m30 = a;
            s->m34 = a;
        }
        if (s->m38 != 0) {
            fn_802B961C(s->m38, 10);
            s->m38 = a;
            s->m3C = a;
        }
        fn_802B9058();
    }
    if (s->m40 != 0) {
        fn_80377488(s->m40);
        s->m40 = 0;
        s->m44 = 0;
    }
}

extern "C" Scr* fn_80135180(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8065C4E0);
    fn_80134E38((Unk80134E38*)&self->m134, i);
    self->m17C = lbl_80656758;
    self->SetVptr(lbl_80656770);
    self->m180 = 0;
    self->m1D4 = 1;
    return self;
}

extern "C" void fn_80135200(Scr* x, int chrg)
{
    x->m17C = lbl_80656758;
    x->SetVptr(lbl_80656770);
    x->m180 = 0;
    fn_80134EC8((Unk80134E38*)&x->m134, 0);
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

extern "C" Scr* fn_80135538(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    Unk80134E38* sub = (Unk80134E38*)&self->m134;
    fn_80135180(self, a, b, c, d, e, f, g, h, 0);
    self->m1D8 = 0;
    self->m1DC = 0;
    self->m1E4 = 0;
    self->m1E8 = 0;
    self->m1EC = 0;
    self->m17C = lbl_80656498;
    self->SetVptr(lbl_806564B0);
    Unk800B555C_P8* p = (Unk800B555C_P8*)((char*)fn_800B555C() + 8);
    self->m138 = p->m4C4;
    self->m15C = p->m4C8;
    self->m160 = p->m4CC;
    int w = p->m4D0;
    fn_80403144((unsigned short*)&self->m13C, w);
    fn_801368FC(self);
    fn_8013501C(sub);
    if (self->m138 == 5) {
        self->m138 = 1;
    } else if (self->m138 == 4) {
        self->m138 = 0;
    }
    if (self->m138 == 1) {
        fn_80134F48((Unk80134F48*)sub);
    }
    fn_80172334(self->m134, self->m138, self->m15C, w, lbl_805C0CA8);
    return self;
}

extern "C" void fn_8013563C(Scr* x, int chrg)
{
    x->m17C = lbl_80656498;
    x->SetVptr(lbl_806564B0);
    x->m1E4 = 0;
    fn_80135200(x, chrg);
}

extern "C" void fn_80135680(Scr* x)
{
    fn_80135264(x);
    fn_80136014(x);
    FE();
    x->m1E0 = (Unk800C7B40_Widget*)fn_800B7A94(lbl_8061A32C, lbl_805BA6D0);
    FE();
    x->m1E4 = (Unk800C7B40_Widget*)fn_800B7A94(lbl_8061A32C, lbl_805BAFF8);
    fn_8013D164((Unk80135680_Txt*)x->m1E4, 10);
    ((Unk80135680_Txt*)x->m1E4)->m2E0 = fn_80135F38;
    ((Unk80135680_Txt*)x->m1E4)->m3AC = fn_80135FA8;
    Unk800C7B40_Widget* w = fn_800C8060(x->fn_vslot32(lbl_805C0CB4, 1));
    x->m1DC = (int)w;
    w->fn_vslot105(1);
    fn_80124FA8(x->m1E0, x);
    if (fn_800B555C()->m4F0 == 0) {
        fn_80125100(x->m1E0);
    } else {
        fn_80125180(x->m1E0, 1, 0x63A);
    }
    fn_80125180(x->m1E0, 0, 0x1A0A);
    x->m1E0->fn_vslot16(1);
    fn_80136174(x, 0);
    fn_80136864(x);
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
    fn_80136864(o);
    fn_801725C4(o->m134, a);
}

extern "C" void fn_80135FA8()
{
    FE();
    Scr* o = fn_800B7A94(lbl_8061A32C, lbl_805BA744);
    fn_80136864(o);
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

extern "C" void fn_80136750(Scr* x)
{
    const char* s = lbl_805C0CD4;
    x->m1D8 = s;
    if (x->m15C & 0x03000000) {
        if (x->m160 == 0) {
            fn_800C2034((char*)fn_800B555C() + 8, 0);
        }
        fn_801369B8(x, s);
    } else {
        fn_801369B8(x, lbl_805C0CC0);
    }
}

extern "C" void fn_801367CC(Scr* x, void* p)
{
    x->fn_vslot16(0);
    fn_8013C0A8(x->m1E4, 3, 0, 0);
    if (p != 0 && fn_801718E8(p) != 0) {
        Unk800C7B40_Widget* w = x->m1E4;
        fn_8013D0E0(w, fn_8017191C(p, 0)->m4);
    }
    x->m1E8 = 1;
}

extern "C" void fn_80136864(Scr* x)
{
    if (x->m1E8 != 0) {
        x->fn_vslot16(1);
        x->m1E4->fn_vslot16(0);
        x->m1E4->fn_vslot8(0);
        x->m1E8 = 0;
    }
}

extern "C" void fn_801368FC(Scr* x)
{
    int t = x->m138;
    if ((t == 1 && x->m15C == 0x200000) || t == 5 || t == 4) {
        int v = fn_800B555C()->m4E8;
        fn_80172564(x->m134, v);
    } else {
        fn_800B555C()->m4E8 = 0;
        fn_80172564(x->m134, 0);
    }
    if (x->m15C == 0x11) {
        ((Unk80136A14_Obj*)x->m134)->m48 = 1;
    }
    if ((x->m15C & 0x03000000) && x->m138 == 0) {
        ((Unk80136A14_Obj*)x->m134)->m4C = 1;
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

extern "C" Scr* fn_80136A9C(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_80136A14(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8064D040);
    self->m13C = 0;
    self->m140 = 0;
    self->m1B4[0] = 0;
    self->m1B4[1] = 0;
    self->m1B4[2] = 0;
    self->m1B4[3] = 0;
    self->m1B4[4] = 0;
    self->m1B4[5] = 0;
    self->m1B4[6] = 0;
    self->m1B4[7] = 0;
    int off = 0;
    for (int i = 0; i < 4; i++) {
        SetAt((char*)self + 0x144, off, 0);
        SetAt((char*)self + 0x148, off, 0);
        SetAt((char*)self + 0x14C, off, -1);
        SetAt((char*)self + 0x150, off, 0);
        SetAt((char*)self + 0x154, off, 0);
        SetAt((char*)self + 0x158, off, 0);
        SetAt((char*)self + 0x15C, off, 0);
        off += 0x1C;
    }
    return self;
}

extern "C" void fn_80136B60(Scr* x, int k, int a)
{
    x->fn_vslot84(k, a);
    if (k == 0) {
        x->fn_vslot32(lbl_805BE348, 1)->fn_vslot8(a);
    } else if (k == 1) {
        x->fn_vslot32(lbl_805BE33C, 1)->fn_vslot8(a);
    }
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

extern "C" int fn_80136CB8(Scr* x, int key)
{
    if (x->fn_vslot90() != 0) {
        int off = 0;
        for (int i = 0; i < 4; i++) {
            if (KeyAt((char*)x + 0x14C, off) == key) {
                return 0;
            }
            off += 0x1C;
        }
        return 1;
    }
    return 0;
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
