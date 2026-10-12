/*
 * Game code, .text 0x80362A30-0x80362FB4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803606B0.h"

extern char lbl_80684920[];
struct DtorAtC { char pad[0xc]; const void* m; };
extern char lbl_80685000[];
struct DtorAt0 { const void* m; };
extern char lbl_806851A8[];
extern char lbl_80685268[];

void fn_80362A30(void* s, int* p)
{
    delete[] p;
}

//HOISTBLOCK
extern "C" void fn_8037704C(void* heap, const char* name, int a, int b, int c);
extern void* lbl_80624234;
extern char lbl_80605478[];
struct Unk803629CC {
    int m0;
};
//ENDHOIST
void fn_80362A58(Unk803629CC* s, int a)
{
    fn_8037704C(lbl_80624234, lbl_80605478, a, s->m0, 0);
}

void fn_80362A94(void* s, int* p)
{
    delete[] p;
}

void fn_80362ABC(Unk803629CC* s, int a)
{
    fn_8037704C(lbl_80624234, lbl_80605478, a, s->m0, 0);
}

void fn_80362AF8(DtorAtC* self, int chrg)
{
    self->m = lbl_80684920;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
extern char lbl_80684938[];
struct Unk80362B2C_ND {
    int m0;
    int m4;
    void* m8;
};
struct Unk80362B2C_N : Unk80362B2C_ND {
    virtual ~Unk80362B2C_N();
};
struct Unk80362B2C {
    int m0;
    Unk80362B2C_N* m4;
    int m8;
    const void* mC;
};
//ENDHOIST
void fn_80362B2C(Unk80362B2C* s, int chrg)
{
    s->mC = lbl_80684938;
    while (s->m4 != 0) {
        Unk80362B2C_N* n = s->m4;
        s->m4 = (Unk80362B2C_N*)n->m8;
        delete n;
    }
    if (chrg & 1)
        fn_80377408(s);
}

//HOISTBLOCK
extern char lbl_806848E0[];
extern "C" void fn_8037B224(void* p, int c);
struct Unk80362BBC {
    void* m0;
    void* m4;
    int m8;
    const void* mC;
};
//ENDHOIST
void fn_80362BBC(Unk80362BBC* s, int chrg)
{
    s->mC = lbl_806848E0;
    if (s->m0 != 0)
        fn_8037B224(s->m0, 3);
    if (s->m4 != 0)
        fn_8037B224(s->m4, 3);
    if (chrg & 1)
        fn_80377408(s);
}

//HOISTBLOCK
void fn_80362EAC(DtorAt0* s, int chrg);
//ENDHOIST
void fn_80362C4C(DtorAt0* s, int chrg)
{
    fn_80362EAC(s, chrg);
}

//HOISTBLOCK
extern char lbl_80685190[];
struct Unk80362C6C {
    const void* m0;
    Unk80362C6C();
};
//ENDHOIST
Unk80362C6C::Unk80362C6C()
{
    m0 = lbl_80685190;
}

void fn_80362C80(DtorAt0* self, int chrg)
{
    self->m = lbl_80685000;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
extern "C" int fn_8037C7FC(void* s, int a);
extern "C" int fn_8037D028(void* s, int a);
//ENDHOIST
int fn_80362CB4(void* s, int a)
{
    return fn_8037D028((void*)fn_8037C7FC(s, a), a);
}

//HOISTBLOCK
struct Unk80362CE8_S {
    int m0, m4, m8;
    Unk80362CE8_S()
    {
        m0 = 0;
        m4 = 0;
        m8 = 0;
    }
};
struct Unk80362CE8 {
    char pad0[0x28];
    Unk80362CE8_S m28;
    char pad34[0x68 - 0x34];
    Unk80362CE8();
};
//ENDHOIST
Unk80362CE8::Unk80362CE8()
{
}

//HOISTBLOCK
struct Unk80362D00 {
    int m0;
    Unk80362CE8 m4[8];
    Unk80362D00();
};
//ENDHOIST
Unk80362D00::Unk80362D00()
{
}

//HOISTBLOCK
extern char lbl_80685138[];
extern char lbl_806851A8[];
extern "C" void fn_80378620(void* s, int a);
struct Unk80362D4C {
    char pad0[8];
    const void* m8;
    const void* mC;
};
//ENDHOIST
void fn_80362D4C(Unk80362D4C* s, int a)
{
    s->m8 = lbl_80685138;
    s->mC = lbl_806851A8;
    fn_80378620(s, a);
}

//HOISTBLOCK
extern char lbl_80685118[];
extern "C" void fn_803785E4(void* s);
struct Unk80362D84_B {
    char pad0[8];
    Unk80362D84_B()
    {
        fn_803785E4(this);
    }
};
struct Unk80362F30;
struct Unk80362F30 {
    const void* m0;
    Unk80362F30();
};
struct Unk80362D84 : Unk80362D84_B {
    const void* m8;
    Unk80362F30 mC;
    Unk80362D84();
};
//ENDHOIST
Unk80362D84::Unk80362D84()
{
    mC.m0 = lbl_80685118;
    m8 = lbl_80685138;
}

//HOISTBLOCK
struct Unk80362DD4_B {
    char pad0[8];
    unsigned m8a : 4;
    unsigned m8b : 28;
    Unk80362DD4_B()
    {
        m8a = 0;
    }
};
struct Unk80362DD4 : Unk80362DD4_B {
    char padC[0x2C - 0xC];
    Unk80362CE8_S m2C;
    Unk80362DD4();
};
//ENDHOIST
Unk80362DD4::Unk80362DD4()
{
}

//HOISTBLOCK
struct Unk80362DFC {
    char pad0[0x34];
    Unk80362DD4 m34;
    Unk80362DFC();
};
//ENDHOIST
Unk80362DFC::Unk80362DFC()
{
}

//HOISTBLOCK
extern float lbl_80605E20;
struct Unk80362E30 {
    float m0, m4, m8, mC, m10;
};
//ENDHOIST
void fn_80362E30(Unk80362E30* s)
{
    s->m0 = lbl_80605E20;
    s->m4 = lbl_80605E20;
    s->m8 = lbl_80605E20;
    s->mC = lbl_80605E20;
    s->m10 = lbl_80605E20;
}

//HOISTBLOCK
extern char lbl_80684EC0[];
extern "C" void fn_8037B424(void* p, int c);
//ENDHOIST
void fn_80362E50(DtorAt0* s, int chrg)
{
    s->m = lbl_80684EC0;
    fn_8037B424(s, chrg);
}

void fn_80362E80(void)
{
}

void fn_80362E84(void)
{
}

int fn_80362E88(void)
{
    return 0;
}

int fn_80362E90(void)
{
    return 0;
}

int fn_80362E98(void* s, unsigned* p)
{
    *p &= 0x0FFFFFFF;
    return 1;
}

void fn_80362EAC(DtorAt0* s, int chrg)
{
    s->m = lbl_80684EC0;
    fn_8037B424(s, chrg);
}

int fn_80362EDC(void* s, unsigned* p)
{
    *p &= 0x0FFFFFFF;
    return 1;
}

int fn_80362EF0(void)
{
    return 0;
}

int fn_80362EF8(void)
{
    return 0;
}

int fn_80362F00(void)
{
    return 0;
}

int fn_80362F08(void)
{
    return 0;
}

int fn_80362F10(void)
{
    return 0;
}

int fn_80362F18(void)
{
    return 0;
}

int fn_80362F20(void)
{
    return 0;
}

int fn_80362F28(void)
{
    return 1;
}

Unk80362F30::Unk80362F30()
{
    m0 = lbl_806851A8;
}

void fn_80362F44(DtorAt0* self, int chrg)
{
    self->m = lbl_806851A8;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80362F78(void)
{
}

void fn_80362F7C(void)
{
}

void fn_80362F80(DtorAt0* self, int chrg)
{
    self->m = lbl_80685268;
    if (chrg & 1)
        fn_80377408(self);
}
