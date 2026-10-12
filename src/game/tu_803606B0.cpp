/*
 * Game code, .text 0x803606B0-0x80360C18 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

struct U {
    char pad0[0x4000];
};

extern "C" void fn_8035686C(void* p, int chrg);

extern "C" void fn_803606B0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803606D0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803606F0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360740(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360790(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803607B0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803607D0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803607F0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360840(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360860(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360880(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803608A0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803608C0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803608E0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360900(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360920(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360940(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360960(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360980(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803609A0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803609C0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_803609E0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360A00(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360A20(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360A40(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern "C" void fn_80360A60(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_8064A550[];

extern "C" void fn_80377408(void* p);

extern "C" void fn_80360A80(U* self, int chrg)
{
    PUT(0x10, lbl_8064A550);
    if (chrg & 1)
        fn_80377408(self);
}

extern char lbl_806841F8[];

extern "C" void fn_80360AF0(U* self, int chrg)
{
    PUT(0x14, lbl_806841F8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" void fn_80360B60(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

extern char lbl_806827B0[];

extern "C" void fn_80360BC0(U* self, int chrg)
{
    PUT(0x10, lbl_806827B0);
    if (chrg & 1)
        fn_80377408(self);
}
