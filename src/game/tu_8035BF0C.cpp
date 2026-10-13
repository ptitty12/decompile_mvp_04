/*
 * Game code, .text 0x8035BF0C-0x8035DA48 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8035B60C.h"
#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))
#define PUTI(o, v) (*(int*)((char*)self + (o)) = (v))
#define PUTB(o, v) (*(unsigned char*)((char*)self + (o)) = (v))
#define PUTF(o, v) (*(float*)((char*)self + (o)) = (v))
#define CPUT(o, v) (*(const void**)((char*)this + (o)) = (v))
#define CPUTI(o, v) (*(int*)((char*)this + (o)) = (v))
#define CPUTB(o, v) (*(unsigned char*)((char*)this + (o)) = (v))
#define CPUTF(o, v) (*(float*)((char*)this + (o)) = (v))
#define GETI(o) (*(int*)((char*)self + (o)))
struct U {
    char pad0[0x4000];
};
void fn_80377408(void* p);
extern "C" void fn_8033CD28(void* p, int in_chrg);
extern "C" void fn_8037B424(void* p, int in_chrg);
struct Unk8035D710_V {
    float x;
    float y;
    float z;
};
extern const Unk8035D710_V lbl_806055AC;
struct Unk8035D710 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    Unk8035D710_V m28;
    Unk8035D710_V m34;
    Unk8035D710_V m40;
    Unk8035D710_V m4C;
    Unk8035D710_V m58;
    Unk8035D710_V m64;
    float m70;
    float m74;
    float m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    int m8C;
    int m90;
    int m94;
    int m98;
    int m9C;
    int mA0;
    int mA4;
    int mA8;
};
extern char lbl_80660850[];
extern const float lbl_805D675C;
void fn_801DD420(void* p, int chrg);
#include "game/clampiter.h"
void fn_8035D868(U* self);
void fn_8035D8F4(void* p);
void fn_8035D230(U* self);
void fn_8035D224(U* self);
struct Unk8035D9B0_E {
    char pad[0xD8];
    ~Unk8035D9B0_E() {}
};
struct Unk8035D9B0 {
    int m0;
    Unk8035D9B0_E m4[6];
    ~Unk8035D9B0();
};
struct Unk8035D96C {
    Unk8035D9B0 m0;
    ~Unk8035D96C();
};
struct Unk8035D908 {
    Unk8035D96C m0[9];
    ~Unk8035D908();
};
struct Unk8035D87C {
    int m0;
    VElem18 m4[9];
    ~Unk8035D87C();
};
struct Unk8035BF3C_S {
    int m0;
    int m4;
    int m8;
};
inline void Unk8035BF3C_Clear(Unk8035BF3C_S* s)
{
    s->m0 = -1;
    s->m4 = -1;
    s->m8 = -1;
}

U* fn_8035BF0C(U* self)
{
    fn_8035D868(self);
    return self;
}

void fn_8035BF3C(U* self)
{
    Unk8035BF3C_Clear((Unk8035BF3C_S*)self);
    Unk8035BF3C_Clear((Unk8035BF3C_S*)((char*)self + 0xC));
    PUTI(0x18, 0);
}

extern char lbl_806608C8[];
extern char lbl_806608E0[];
extern char lbl_806608F8[];
extern char lbl_80660928[];
extern char lbl_80660940[];
extern char lbl_806609E8[];
extern char lbl_80660A00[];
extern char lbl_80660A18[];
extern char lbl_80660A30[];
extern char lbl_80660A48[];
struct B8_W1 {
    int m0;
    const void* m4;
    ~B8_W1() { m4 = lbl_80660A30; }
};
struct B8_BDF8 {
    VElem14 m0[4];
    char pad50[4];
    const void* m54;
    ~B8_BDF8() { m54 = lbl_806608F8; }
};
struct B8_BBEC {
    char pad0[0x1C];
    VElem34 m1C[4];
    VElem1C mEC[4];
    VElem14 m15C[4];
    VElem40 m1AC[4];
    B8_W1 m2AC_;
    VElem2C m2B4[4];
    const void* m364;
    ~B8_BBEC() { m364 = lbl_80660940; }
};
struct B8_VP {
    const void* m;
    ~B8_VP() { m = lbl_80660928; }
};
struct B8_Base {
    char pad0[0xA0];
    const void* mA0;
    char padA4[0xB4 - 0xA4];
    const void* mB4;
    char padB8[0x180 - 0xB8];
    const void* m180;
    const void* m184;
    char pad188[0x198 - 0x188];
    const void* m198;
    char pad19C[0x1A4 - 0x19C];
    const void* m1A4;
    ~B8_Base()
    {
        m1A4 = lbl_806609E8;
        m198 = lbl_80660A00;
        m184 = lbl_80660A18;
        m180 = lbl_80660A30;
        mB4 = lbl_80660A48;
        mA0 = lbl_80660A48;
    }
};
struct B8_X : B8_Base {
    Unk8035D87C m1A8;
    B8_BBEC m284;
    char pad5EC[0x5F8 - 0x5EC];
    B8_VP m5F8;
    B8_BDF8 m5FC;
    char pad654[0x670 - 0x654];
    const void* m670;
    const void* m674;
    ~B8_X()
    {
        m674 = lbl_806608C8;
        m670 = lbl_806608E0;
    }
};
struct B8_XQ : B8_Base {
    Unk8035D87C m1A8;
    B8_BBEC m284;
    char pad5EC[0x5F8 - 0x5EC];
    B8_VP m5F8;
    B8_BDF8 m5FC;
    char pad654[0x670 - 0x654];
    const void* m670;
    const void* m674;
    ~B8_XQ() { m674 = lbl_806608C8; }
};
void fn_8035BF68(U* self, int chrg)
{
    ((B8_X*)self)->~B8_X();
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035C1B0(U* self)
{
    Unk8006A138_It<3> it(0);
    int idx = 0;
    while (idx <= 3) {
        fn_8035D8F4((char*)self + (idx * 0xC + 0xC));
        idx = it.Next();
    }
}

void fn_8035C218(U* self)
{
    PUTI(0x0, -1);
    PUTI(0x4, 0);
    PUTI(0x8, 0);
}

void fn_8035C230(U* self)
{
    PUTI(0x600, 0);
    PUTI(0x5fc, 0);
    PUTI(0x5f4, 0);
    PUTI(0x5f0, 0);
    PUTI(0x5ec, 0);
}

extern char lbl_806608B0[];
extern char lbl_8065F9B0[];
/* near-miss: 99.9%; retail stores the 0x674 vptr (P-relative) before the 0x6A0 one (object-relative); ours emits them swapped.
 * The 0x6A0 store is kept outside the inline dtor so it is addressed from self; B8_XQ is B8_X without that store.
 * Tried: pointer local, base-class model (B8_A, B8_X0, B8_R2, B8_R3), swapped store order inside the dtor (6 attempts). */
void fn_8035C24C(U* self, int chrg)
{
    PUT(0x2C, lbl_806608B0);
    ((Unk8035D908*)((char*)self + 0xCA8))->~Unk8035D908();
    PUT(0x6A0, lbl_806608E0);
    ((B8_XQ*)((char*)self + 0x30))->~B8_XQ();
    PUT(0x2C, lbl_8065F9B0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035CD68(U* self, int chrg)
{
    PUT(0x8, lbl_80660850);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035CD9C(U* self)
{
    PUTI(0x0, -1);
    PUTI(0x4, -1);
}

void fn_8035D1D8(U* self, float v) { PUTF(0x18, v); }

void fn_8035D1F0(U* self)
{
    fn_8035D230(self);
    fn_8035D224(self);
}

void fn_8035D224(U* self)
{
    PUTI(0x4, 0);
}

void fn_8035D230(U* self)
{
    PUTI(0x8, 0);
    PUTI(0xc, -1);
    PUTF(0x10, lbl_805D675C);
    PUTF(0x14, lbl_805D675C);
}

void fn_8035D254(U* self, int chrg)
{
    fn_801DD420(self, chrg);
}

void fn_8035D85C(U* self)
{
    PUTI(0x20, 0);
}

void fn_8035D868(U* self)
{
    PUTI(0x0, -1);
    PUTI(0x4, -1);
    PUTI(0x8, -1);
}

Unk8035D87C::~Unk8035D87C() {}

void fn_8035D8F4(U* self)
{
    PUTI(0x0, 0);
    PUTI(0x4, 0);
    PUTI(0x8, 0);
}

Unk8035D908::~Unk8035D908() {}

Unk8035D96C::~Unk8035D96C() {}

Unk8035D9B0::~Unk8035D9B0() {}

extern "C" void fn_8035D710(Unk8035D710* s)
{
    s->m4 = 0;
    s->m8 = 2;
    s->mC = 2;
    s->m1C = 0;
    s->m20 = 0;
    s->m10 = -1;
    s->m28 = lbl_806055AC;
    s->m18 = 5;
    s->m14 = 0;
    s->m0 = 0;
    s->m70 = 0.0f;
    s->m34 = lbl_806055AC;
    s->m40 = lbl_806055AC;
    s->m64 = lbl_806055AC;
    s->m4C = lbl_806055AC;
    s->m58 = lbl_806055AC;
    s->m74 = -1.0f;
    s->m78 = 0.0f;
    s->m9C = 0x11;
    s->mA0 = -1;
    s->m7C = 0;
    s->m80 = 0;
    s->m84 = 0;
    s->m88 = 0;
    s->m24 = 0;
    s->m8C = 0;
    s->m90 = 0;
    s->m94 = 0;
    s->m98 = 0;
    s->mA4 = 0;
    s->mA8 = 0;
}

extern "C" void fn_8035D9F8(U* self, int chrg)
{
    fn_8033CD28((char*)self + 0x10, 2);
    fn_8033CD28((char*)self + 4, 2);
    fn_8037B424(self, chrg);
}
