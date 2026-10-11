/*
 * Game code, .text 0x8035DA48-0x8035E50C (code-only unit; original file and TU
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
extern char lbl_80649DA0[];
extern char lbl_80660E18[];
extern char lbl_80660E48[];
extern char lbl_80660F08[];
extern char lbl_80660F20[];
extern char lbl_80660F38[];
extern char lbl_80660F50[];
extern char lbl_80661368[];
extern char lbl_80661380[];
extern char lbl_80661498[];
extern char lbl_806614B0[];
extern char lbl_806614E0[];
extern char lbl_806614F8[];
extern char lbl_80661658[];
extern char lbl_80661670[];
extern char lbl_80661688[];
extern char lbl_806616A0[];
extern const float lbl_805D7D90;
extern char lbl_806616B8[];
extern char lbl_80660E00[];
extern char lbl_80660E30[];
extern char lbl_80661510[];
extern char lbl_806615A0[];
extern char lbl_80661618[];
extern const float lbl_805D7D90;
void fn_8026C864(void* p, int chrg);
void fn_8014E310(void* p);
struct Unk8035DD24_Heap {
    int m0;
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void* p);
};
extern Unk8035DD24_Heap* lbl_8061F68C;
struct Unk8035DA94 {
    char pad0[0x94];
    VElem34 m94[11];
    char pad2D0[4];
    const void* m2D4;
    ~Unk8035DA94();
};
struct Unk8035DA94I {
    char pad0[0x94];
    VElem34 m94[11];
    char pad2D0[4];
    const void* m2D4;
    ~Unk8035DA94I() { m2D4 = lbl_80660E30; }
};
struct Unk8035DB68 {
    int m0;
    Unk8035DA94I m4;
    char pad2DC[0x2F0 - 0x2DC];
    const void* m2F0;
    ~Unk8035DB68();
};
struct Unk8035DC4C {
    char pad0[0x444];
    Unk8035DA94I m444;
    char pad71C[0x730 - 0x71C];
    const void* m730;
    ~Unk8035DC4C();
};
extern const float lbl_805D9DFC;
extern char lbl_805DABF0[];
void fn_8035DA48(U* self);
struct Unk8035E4D8_S {
    int m0;
    int m4;
    Unk8035E4D8_S() { fn_8035DA48((U*)this); }
};
struct Unk8035E4D8 {
    char pad0[0x10];
    Unk8035E4D8_S m10;
    Unk8035E4D8();
};
extern const float lbl_805DB7A0;
struct Unk8035E410_V3 {
    int m0;
    int m4;
    int m8;
};
extern Unk8035E410_V3 lbl_806055AC;
struct Unk8035E410 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    float m18;
    float m1C;
    int m20;
    int m24;
    Unk8035E410_V3 m28;
    int m34;
    Unk8035E410(int a = 0, const char* b = lbl_805DABF0, int c = 0x2A);
};
void fn_8035E410(Unk8035E410* self, int a, const char* b, int c);
inline Unk8035E410::Unk8035E410(int a, const char* b, int c) { fn_8035E410(this, a, b, c); }
struct Unk8035E47C {
    int m0;
    Unk8035E410 m4[4];
    Unk8035E47C();
};
struct Unk8035DEAC {
    float m0;
    float m4;
    float m8;
    char padC[0x28 - 0xC];
    int m28[3];
    int m34[3];
    int m40[3];
};

void fn_8035DA48(U* self)
{
    PUTI(0x4, 0);
    PUTI(0x0, 0);
}

int fn_8035DA58(U* self) { return GETI(0x0); }

void fn_8035DA60(U* self, int chrg)
{
    PUT(0x30, lbl_80660E48);
    if (chrg & 1)
        fn_80377408(self);
}

Unk8035DA94::~Unk8035DA94()
{
    m2D4 = lbl_80660E30;
}

void fn_8035DB18(U* self, int chrg)
{
    PUT(0x18, lbl_80660E18);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035DB4C(U* self, int a, int b, int c, int d, int e, int f)
{
    PUTI(0x0, a);
    PUTI(0x4, b);
    PUTI(0x8, c);
    PUTI(0xC, d);
    PUTI(0x10, e);
    PUTI(0x14, f);
}

Unk8035DB68::~Unk8035DB68()
{
    m2F0 = lbl_80660E00;
}

/* near-miss: 14 store slots; retail order is 0xC, 0x28, 0x1C, 0x38, 0x34, 0x2C, 0x20, 0x10, 0, 0x30, 4, 8, 0x14, 0x18; ascending field order and two hill-climbs from the stored order stay at 5-10 differing slots. */
void fn_8035DC00(U* self)
{
    PUTI(0xc, 0);
    PUTI(0x28, -1);
    PUTF(0x1c, lbl_805D7D90);
    PUTI(0x38, 0);
    PUTI(0x34, 0);
    PUTI(0x2c, 0);
    PUTI(0x20, 0);
    PUTI(0x10, 0);
    PUTI(0x0, 0);
    PUTI(0x30, 0);
    PUTI(0x4, 0);
    PUTI(0x8, 0);
    PUTF(0x14, lbl_805D7D90);
    PUTF(0x18, lbl_805D7D90);
}

Unk8035DC4C::~Unk8035DC4C()
{
    m730 = lbl_80660E00;
}

void fn_8035DCE4(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035DD18(U* self)
{
    PUTB(0x3, 1);
}

void fn_8035DD24(U* self, int chrg)
{
    PUT(0x5C, lbl_80661618);
    if (chrg & 1)
        lbl_8061F68C->v5(self);
}

void fn_8035DD78() {}

char* fn_8035DD7C(char* p) { return p + 0x4; }

char* fn_8035DD84(char* p) { return p + 0x8; }

char* fn_8035DD8C(char* p) { return p + 0x1; }

char* fn_8035DD94(char* p) { return p + 0xc; }

void fn_8035DD9C(U* self, int v) { PUTB(0x2, v); }

void fn_8035DDA4(U* self, int chrg)
{
    PUT(0xB8, lbl_80661510);
    PUT(0x98, lbl_806615A0);
    fn_8026C864(self, chrg);
}

void fn_8035DDDC(U* self, int chrg)
{
    PUT(0x54, lbl_806614F8);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035DE10(U* self, int chrg)
{
    PUT(0x58, lbl_806614E0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035DE44(U* self, int chrg)
{
    PUT(0x58, lbl_806614E0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035DE78(U* self, int chrg)
{
    PUT(0x4, lbl_806614B0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035DEAC(Unk8035DEAC* self)
{
    self->m0 = lbl_805D9DFC;
    self->m4 = lbl_805D9DFC;
    self->m8 = lbl_805D9DFC;
    for (int i = 0; i < 3; i++) {
        self->m28[i] = 0;
        self->m34[i] = 0;
        self->m40[i] = 0;
    }
}

void fn_8035DEF4(U* self, int chrg)
{
    PUT(0xa4, lbl_80661498);
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk8035DF28 {
    char pad0[0x400];
    Unk8035DF28();
};

Unk8035DF28::Unk8035DF28()
{
    CPUT(0x0, lbl_806616B8);
}

void fn_8035DF3C(U* self, int chrg)
{
    PUT(0x54, lbl_80661380);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035DF70(U* self, int chrg)
{
    PUT(0x198, lbl_80661368);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035DFA4(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035DFD8(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E00C(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E040(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E074(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E0A8(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E0DC(U* self, int chrg)
{
    PUT(0x0, lbl_80660F50);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E110(U* self, int chrg)
{
    PUT(0x0, lbl_80660F38);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E144(U* self, int chrg)
{
    PUT(0x0, lbl_80660F20);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E178(U* self, int chrg)
{
    PUT(0x0, lbl_80660F08);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E1AC(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E1E0(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E214(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E248(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E27C(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E2B0(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E2E4(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E318(U* self)
{
    fn_8014E310(*(char**)((char*)*(char**)self + 0x458));
}

void fn_8035E340(U* self, int chrg)
{
    PUT(0x0, lbl_806616A0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E374(U* self, int chrg)
{
    PUT(0x0, lbl_80661688);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E3A8(U* self, int chrg)
{
    PUT(0x0, lbl_80661670);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035E3DC(U* self, int chrg)
{
    PUT(0x0, lbl_80661658);
    if (chrg & 1)
        fn_80377408(self);
}

/* near-miss: 4 slots; retail interleaves the m1C float store (stfs after li/lis) and the m10 argument store later than the permutation search reaches. */
void fn_8035E410(Unk8035E410* self, int a, const char* b, int c)
{
    self->m4 = 0;
    self->m14 = 0;
    self->m8 = 4;
    self->mC = -1;
    self->m10 = a;
    self->m20 = 6;
    self->m18 = lbl_805DB7A0;
    self->m0 = 0;
    self->m28 = lbl_806055AC;
    self->m1C = lbl_805DB7A0;
    self->m24 = 0;
    self->m34 = 0;
}

Unk8035E47C::Unk8035E47C() {}

Unk8035E4D8::Unk8035E4D8() {}
