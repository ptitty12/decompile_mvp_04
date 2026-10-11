/*
 * Game code, .text 0x803606B0-0x80360C18 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803606B0.h"

extern "C" void fn_8035686C(void* self, int a);
extern char lbl_8064A550[];
struct DtorAt15C { char pad[0x15c]; const void* m; };
struct DtorAt1A0 { char pad[0x1a0]; const void* m; };
struct DtorAt10 { char pad[0x10]; const void* m; };
extern char lbl_806841F8[];
struct DtorAt14 { char pad[0x14]; const void* m; };
extern char lbl_806827B0[];

void fn_803606B0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803606D0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803606F0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360710(DtorAt15C* self, int a)
{
    self->m = lbl_8064A550;
    fn_8035686C(self, a);
}

void fn_80360740(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360760(DtorAt15C* self, int a)
{
    self->m = lbl_8064A550;
    fn_8035686C(self, a);
}

void fn_80360790(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803607B0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803607D0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803607F0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360810(DtorAt1A0* self, int a)
{
    self->m = lbl_8064A550;
    fn_8035686C(self, a);
}

void fn_80360840(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360860(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360880(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803608A0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803608C0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803608E0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360900(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360920(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360940(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360960(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360980(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803609A0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803609C0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_803609E0(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360A00(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360A20(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360A40(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360A60(void* self, int a)
{
    fn_8035686C(self, a);
}

void fn_80360A80(DtorAt10* self, int chrg)
{
    self->m = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
extern char lbl_806841F8[];
extern char lbl_80682810[];
struct Unk80360AB4 {
    int m0, m4, m8, mC, m10;
    const void* m14;
    Unk80360AB4(const Unk80360AB4& o);
};
struct Unk80360B24 : Unk80360AB4 {
    Unk80360B24(const Unk80360B24& o);
};
//ENDHOIST
Unk80360AB4::Unk80360AB4(const Unk80360AB4& o)
{
    m14 = lbl_806841F8;
    m0 = o.m0;
    m4 = o.m4;
    m8 = o.m8;
    mC = o.mC;
    m10 = o.m10;
}

void fn_80360AF0(DtorAt14* self, int chrg)
{
    self->m = lbl_806841F8;
    if (chrg & 1)
        fn_80377408(self);
}

Unk80360B24::Unk80360B24(const Unk80360B24& o) : Unk80360AB4(o)
{
    m14 = lbl_80682810;
}

void fn_80360B60(void* self, int a)
{
    fn_8035686C(self, a);
}

//HOISTBLOCK
struct Unk80360B80 { int m0; int m4; };
//ENDHOIST
extern "C" void fn_80360B80(Unk80360B80* s)
{
    s->m0 = 0;
    s->m4 = 4;
}

void fn_80360B94(void)
{
}

void fn_80360B98(void)
{
}

//HOISTBLOCK
struct Unk80360B9C_E { int m0; int m4; };
struct Unk80360B9C { char pad[0x14]; Unk80360B9C_E* m14; };
//ENDHOIST
int fn_80360B9C(Unk80360B9C* s, int i)
{
    return s->m14[i].m4;
}

int fn_80360BB0(Unk80360B9C* s, int i)
{
    return s->m14[i].m0;
}

void fn_80360BC0(DtorAt10* self, int chrg)
{
    self->m = lbl_806827B0;
    if (chrg & 1)
        fn_80377408(self);
}

int fn_80360BF4(Unk80360B9C* s, int i)
{
    return s->m14[i].m4;
}

int fn_80360C08(Unk80360B9C* s, int i)
{
    return s->m14[i].m0;
}
