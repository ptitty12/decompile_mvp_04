/*
 * Game code, .text 0x80361580-0x80361F98 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803606B0.h"

extern char lbl_8064A550[];
struct DtorAt10 { char pad[0x10]; const void* m; };
extern char lbl_806839F0[];
struct DtorAt1C { char pad[0x1c]; const void* m; };
extern "C" void fn_80593DD8(void* self, int a);
extern char lbl_80682D68[];
struct DtorAt28 { char pad[0x28]; const void* m; };
extern char lbl_80682CB0[];
struct DtorAt7C0 { char pad[0x7c0]; const void* m; };
extern char lbl_80682C20[];
struct DtorAt34 { char pad[0x34]; const void* m; };
extern "C" void fn_8057E03C(void* self, int a);
extern char lbl_80684820[];
struct DtorAt8 { char pad[0x8]; const void* m; };

//HOISTBLOCK
struct Unk80361580 {
    int m0;
    int m4;
    short m8;
};
//ENDHOIST
void fn_80361580(Unk80361580* s)
{
    s->m0 = 0;
    s->m4 = 0;
    s->m8 = 0;
}

void fn_80361594(DtorAt10* self, int chrg)
{
    self->m = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
extern char lbl_80684130[];
extern char lbl_80684110[];
struct Unk803615C8 {
    int m0;
    const void* m4;
    Unk803615C8();
};
struct Unk803615E4 {
    int m0;
    const void* m4;
    Unk803615E4();
};
//ENDHOIST
Unk803615C8::Unk803615C8()
{
    m0 = 0;
    m4 = lbl_80684130;
}

Unk803615E4::Unk803615E4()
{
    m0 = 0;
    m4 = lbl_80684110;
}

//HOISTBLOCK
struct Unk80361600 : Unk803628A0 {
    Unk80361600();
};
//ENDHOIST
Unk80361600::Unk80361600()
{
    fn_803628A0(this);
}

//HOISTBLOCK
struct Unk80361630 {
    int m0;
    int m4;
    Unk80361630();
};
//ENDHOIST
Unk80361630::Unk80361630()
{
    m0 = 0;
    m4 = 0;
}

//HOISTBLOCK
struct Unk80361644 {
    char pad0[0x10];
    const void* m10;
    char pad14[0x32F0 - 0x14];
    const void* m32F0;
    char pad32F4[0x3500 - 0x32F4];
    char m3500[0x14];
    char pad3514[0x35C8 - 0x3514];
    const void* m35C8;
    char pad35CC[0x13D2C - 0x35CC];
    const void* m13D2C;
};
extern char lbl_80683C48[];
//ENDHOIST
void fn_80361644(Unk80361644* s, int chrg)
{
    s->m13D2C = lbl_80683C48;
    s->m35C8 = lbl_8064A550;
    fn_80361594((DtorAt10*)s->m3500, 2);
    s->m32F0 = lbl_8064A550;
    s->m10 = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(s);
}

int fn_803616B0(float a, float b)
{
    return a > b;
}

void fn_803616D8(DtorAt1C* self, int a)
{
    self->m = lbl_806839F0;
    fn_80593DD8(self, a);
}

int fn_80361708(void)
{
    return 0;
}

int fn_80361710(void)
{
    return 0;
}

void fn_80361718(void)
{
}

void fn_8036171C(void)
{
}

void fn_80361720(char* s, int chrg)
{
    fn_80360AF0((DtorAt14*)(s + 8), 2);
    if (chrg & 1)
        fn_80377408(s);
}

void fn_80361768(DtorAt28* self, int chrg)
{
    self->m = lbl_80682D68;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
extern char lbl_8064B298[];
extern char lbl_8064A3B8[];
struct Unk8036179C_R {
    int* m0;
    unsigned m4;
    int m8;
    unsigned mC;
    const void* m10;
    int m14;
    inline void Init(void* buf, int n, int bytes, const void* vt)
    {
        m10 = vt;
        m0 = (int*)buf;
        m8 = n;
        fn_8040074C(m0, bytes);
        m4 = 0;
        mC = 0;
    }
    inline void P2() { m10 = lbl_8064A550; }
    inline void P3()
    {
        fn_8040074C(m0, m8 << 2);
        m4 = 0;
        mC = 0;
        m14 = 0;
        m10 = lbl_8064A3B8;
    }
};
struct Unk8036179C {
    int m0;
    char pad4[8];
    Unk8036179C_R r;
    char buf[0x32C8];
};
//ENDHOIST
Unk8036179C* fn_8036179C(Unk8036179C* s)
{
    s->r.Init(s->buf, 0xcb2, 0x32c8, lbl_8064B298);
    s->r.P2();
    s->r.P3();
    return s;
}

//HOISTBLOCK
extern char lbl_80682D50[];
struct Unk80361834_ED {
    char pad[0x28];
};
struct Unk80361834_E : Unk80361834_ED {
    virtual ~Unk80361834_E();
};
struct Unk80361834 {
    Unk80361834_E m0[75];
    int mCE4;
    Unk80362930 mCE8;
    char pad[0x3FD4 - 0xCE8 - sizeof(Unk80362930)];
    const void* m3FD4;
    ~Unk80361834();
};
//ENDHOIST
Unk80361834::~Unk80361834()
{
    m3FD4 = lbl_80682D50;
}

//HOISTBLOCK
extern char lbl_80683EF8[];
struct Unk803618C4 {
    char pad0[0x648];
    const void* m648;
    char pad64C[0xA3C - 0x64C];
    const void* mA3C;
};
//ENDHOIST
void fn_803618C4(Unk803618C4* s, int chrg)
{
    s->mA3C = lbl_80683EF8;
    s->m648 = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(s);
}

void fn_80361904(DtorAt7C0* self, int chrg)
{
    self->m = lbl_80682CB0;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80361938(DtorAt34* self, int a)
{
    self->m = lbl_80682C20;
    fn_8057E03C(self, a);
}

void fn_80361968(void* self, int a)
{
    fn_8057E03C(self, a);
}

void fn_80361988(void* self, int a)
{
    fn_8057E03C(self, a);
}

void fn_803619A8(void)
{
}

//HOISTBLOCK
extern Unk803619AC_G* lbl_80619948;
extern "C" int fn_80581374(int a);
extern "C" int fn_80581368(int a, int b);
extern "C" void fn_804EADD4(int a, unsigned b, int c, int d);
//ENDHOIST
int fn_803619AC(Unk80361C58* s)
{
    int r = fn_80581368(fn_80581374(s->m4), s->m0->m10);
    s->m0->m0->fn_8007D180(s->m0->m28, r);
    s->m0->m0->fn_8007D998(s->m0->m28, s->m4);
    fn_804EADD4(lbl_80619948->m64, s->m0->m28, s->m4, fn_80581374(s->m4));
    return r;
}

void fn_80361A4C(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
int fn_80075F1C(int a, int b, int c);
int fn_800736EC(const char* s);
extern const char* lbl_80619D34[];
//ENDHOIST
int fn_80361A80(Unk80361A80* s)
{
    int r = 0;
    if (s->m0->m1C->m198 == s->mC) {
        r = s->mC == fn_800736EC(lbl_80619D34[fn_80075F1C(s->m0->m4->mC->m24, 0, 0)]);
    }
    return r;
}

void fn_80361B00(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

int fn_80361B34(Unk80361A80* s)
{
    int a = s->m0->m0->fn_80078A38(s->m0->mC->m198);
    int r = 0;
    if (a == s->mC)
        r = s->m0->m0->fn_80078A38(s->m0->m1C->m198) == s->mC;
    return r;
}

void fn_80361BA8(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
struct Unk80361BDC {
    char pad0[0xC];
    float mC;
    float m10;
    float m14;
    int m18;
};
//ENDHOIST
int fn_80361BDC(Unk80361BDC* s)
{
    int r = 0;
    if (s->m18 > 2) {
        int ok = 0;
        if (!(s->mC < s->m10))
            ok = s->mC < s->m14;
        if (ok)
            r = 1;
    }
    return r;
}

void fn_80361C24(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

int fn_80361C58(Unk80361C58* s)
{
    int r = 0;
    if (s->m10.pfn((char*)s->m0->mC + s->m10.delta, s->mC) > 0)
        r = 1;
    return r;
}

int fn_80361CB4(Unk80361C58* s)
{
    int i;
    int r = fn_80581368(fn_80581374(s->m4), s->m0->m10);
    for (i = 0; i < s->m10.pfn((char*)s->m0->mC + s->m10.delta, s->mC); i++) {
        s->m0->m0->fn_8007D180(s->m0->m28, r);
        s->m0->m0->fn_8007D998(s->m0->m28, s->m4);
        fn_804EADD4(lbl_80619948->m64, s->m0->m28, s->m4, fn_80581374(s->m4));
    }
    return r;
}

void fn_80361D88(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80361DBC(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80361DF0(Unk80361A80* s)
{
    s->m0->m0->fn_8007D0E0(s->m0->m28, 4, 1);
}

void fn_80361E24(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
struct Unk80361E58 {
    Unk80361A80_Obj* m0;
    char pad4[8];
    unsigned char mC;
};
extern "C" void fn_8009DA60(void* a, int b);
extern "C" void fn_8009DB0C(void* a, int b);
//ENDHOIST
void fn_80361E58(Unk80361E58* s)
{
    fn_8009DA60(s->m0->mC, s->mC);
}

void fn_80361E84(Unk80361A80* s)
{
    s->m0->m0->fn_8007D0E0(s->m0->m28, 3, 1);
}

void fn_80361EB8(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80361EEC(Unk80361E58* s)
{
    fn_8009DB0C(s->m0->mC, s->mC);
}

void fn_80361F18(Unk80361A80* s)
{
    s->m0->m0->fn_8007D0E0(s->m0->m28, 5, 1);
}

void fn_80361F4C(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
struct Unk80361F80 {
    char pad0[0xC];
    int mC;
    int m10;
};
//ENDHOIST
int fn_80361F80(Unk80361F80* s)
{
    return s->mC == s->m10;
}
