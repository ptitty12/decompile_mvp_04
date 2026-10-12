/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803E6FB8-0x803E9C20 (code-only unit, 39 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* Two-element container: elements at +0 and +0x14 (the same method set is instantiated twice, the second
 * copy at 0x803E7160..0x803E72EC). */
struct Unk803E7008_Pair {
    char pad0[0x14];
    char m14[1];
};

struct Unk803E7008_Ent {
    char pad0[0x10];
    int m10;
};

extern int lbl_8062C674;
extern char lbl_806AAB6C[];

extern "C" void fn_80377408(void* p);
extern "C" void fn_803ED634(void* a, void* b, int c);
extern "C" void fn_803EA0E4(void* p, int chrg);
extern "C" void fn_803E9E30(void* p, int a);
extern "C" void fn_803EA160(void* p, int a, int b);
extern "C" void* fn_803E9F50(void* p, int a, int* count);
extern "C" void fn_803EA08C(void* p);
extern "C" void fn_803EDA0C(void* menu, int a);

extern "C" void fn_803E6FB8(void* a, void* b)
{
    fn_803ED634(b, a, 0);
}

extern "C" void fn_803E6FE8(void* self, int a)
{
    fn_803EDA0C(self, a);
}

extern "C" void fn_803E7008(Unk803E7008_Pair* p, int chrg)
{
    fn_803EA0E4(p, 2);
    fn_803EA0E4(p->m14, 2);
    fn_803EA0E4(p->m14, 2);
    fn_803EA0E4(p, 2);
    if (chrg & 1)
        fn_80377408(p);
}

extern "C" void fn_803E7074(Unk803E7008_Pair* p, int a)
{
    fn_803E9E30(p, a);
    fn_803E9E30(p->m14, a);
}

extern "C" void fn_803E70B0(Unk803E7008_Pair* p, int a, int b, int c)
{
    fn_803EA160(p, a, b);
    fn_803EA160(p->m14, a, c);
}

extern "C" void* fn_803E70F4(Unk803E7008_Pair* p, int a)
{
    int n;
    void* r = fn_803E9F50(p, a, &n);
    if (n == 0)
        r = 0;
    return r;
}

extern "C" void* fn_803E7128(Unk803E7008_Pair* p, int a)
{
    int n;
    void* r = fn_803E9F50(p->m14, a, &n);
    if (n == 0)
        r = 0;
    return r;
}

extern "C" void fn_803E7160(Unk803E7008_Pair* p, int chrg)
{
    fn_803EA0E4(p, 2);
    fn_803EA0E4(p->m14, 2);
    fn_803EA0E4(p->m14, 2);
    fn_803EA0E4(p, 2);
    if (chrg & 1)
        fn_80377408(p);
}

extern "C" void fn_803E71CC(Unk803E7008_Pair* p, int a)
{
    fn_803E9E30(p, a);
    fn_803E9E30(p->m14, a);
}

extern "C" void fn_803E7208(Unk803E7008_Pair* p, int a, int b, int c)
{
    fn_803EA160(p, a, b);
    fn_803EA160(p->m14, a, c);
}

extern "C" void* fn_803E724C(Unk803E7008_Pair* p, int a)
{
    int n;
    void* r = fn_803E9F50(p, a, &n);
    if (n == 0)
        r = 0;
    return r;
}

extern "C" void* fn_803E7280(Unk803E7008_Pair* p, int a)
{
    int n;
    void* r = fn_803E9F50(p->m14, a, &n);
    if (n == 0)
        r = 0;
    return r;
}

extern "C" void fn_803E72B8(Unk803E7008_Pair* p)
{
    fn_803EA08C(p);
    fn_803EA08C(p->m14);
}

extern "C" void fn_803E72EC(Unk803E7008_Pair* p)
{
    fn_803EA08C(p);
    fn_803EA08C(p->m14);
}

extern "C" void fn_803E73F4(int v)
{
    lbl_8062C674 = v;
}

/* Static initializer / destructor for lbl_806AAB6C, lbl_806AAB80 and lbl_806AABA8 (single element, two pairs). */
extern Unk803E7008_Pair lbl_806AAB80;
extern Unk803E7008_Pair lbl_806AABA8;
extern "C" void fn_803EA068(void* p);

extern "C" void fn_803E9594(int initialize, int priority)
{
    if (priority == 0xFFFF) {
        if (initialize) {
            fn_803EA068(lbl_806AAB6C);
            Unk803E7008_Pair* a = &lbl_806AAB80;
            fn_803EA068(a);
            fn_803EA068(a->m14);
            Unk803E7008_Pair* b = &lbl_806AABA8;
            fn_803EA068(b);
            fn_803EA068(b->m14);
        } else {
            fn_803E7160(&lbl_806AABA8, 2);
            fn_803E7008(&lbl_806AAB80, 2);
            fn_803EA0E4(lbl_806AAB6C, 2);
        }
    }
}

struct Unk803E9640 {
    int m0, m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C;
};

extern void (*lbl_8062C66C)(void* p, int size);
extern "C" void fn_803E864C(void* o, int a);
extern "C" void fn_803E7FD0(void* o);
extern "C" int fn_803E973C(void* o);

extern "C" Unk803E9640* fn_803E9640(Unk803E9640* o, int a, int b, int c)
{
    o->m10 = a;
    o->m14 = b;
    o->m0 = 0;
    o->m4 = 0;
    o->m8 = 0;
    o->mC = 0;
    o->m18 = 0;
    o->m1C = c;
    o->m20 = 0;
    o->m24 = 0;
    o->m28 = 0;
    o->m2C = 0;
    fn_803E864C(o, c);
    fn_803E7FD0(o);
    fn_803E973C(o);
    return o;
}

extern "C" Unk803E9640* fn_803E96B8(Unk803E9640* o, int a, int b, int c, int skip, int d)
{
    o->m10 = a;
    o->m14 = b;
    o->m18 = c;
    o->m0 = 0;
    o->m4 = 0;
    o->m8 = 0;
    o->mC = 0;
    o->m1C = d;
    o->m20 = 0;
    o->m24 = 0;
    o->m28 = 0;
    o->m2C = 0;
    fn_803E864C(o, d);
    if (skip == 0)
        fn_803E7FD0(o);
    fn_803E973C(o);
    return o;
}

extern "C" int fn_803E973C(void* o)
{
    return 1;
}

extern "C" void fn_803E97C4(void* o);
extern "C" void fn_803E98A0(void* o);

extern "C" void fn_803E9744(Unk803E9640* o, int chrg)
{
    fn_803E97C4(o);
    fn_803E98A0(o);
    if (o->m28)
        lbl_8062C66C((void*)o->m28, o->m24);
    o->m28 = 0;
    if (chrg & 1)
        lbl_8062C66C(o, 0x30);
}

extern "C" int fn_803E9978(Unk803E7008_Ent** pp)
{
    Unk803E7008_Ent* e = *pp;
    if (!e)
        return 0;
    return e->m10;
}

extern "C" void fn_803E9B3C(int a, int b)
{
    fn_803EA160(lbl_806AAB6C, a, b);
}

extern "C" void fn_803E9B6C(int a)
{
    fn_803E9E30(lbl_806AAB6C, a);
}

extern "C" void* fn_803E9B98(int a, int* count)
{
    return fn_803E9F50(lbl_806AAB6C, a, count);
}

extern "C" void fn_803E9BC8()
{
    fn_803E9594(1, 0xFFFF);
}

extern "C" void fn_803E9BF4()
{
    fn_803E9594(0, 0xFFFF);
}
