/*
 * Game code, .text 0x8009BC3C-0x8009FC5C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80090880.h"

extern const char lbl_805B3B4C[];

/* near-miss: retail indexes (o + 0x40A)[base + slot * 0x34] and returns -1 first */
extern "C" int fn_8009DC00(char* o, int slot, int base, int kind)
{
    if (kind == 1)
        return ((signed char*)(o + 0x40A))[base + slot * 0x34];
    if (kind != 0)
        return -1;
    return ((signed char*)(o + 0x412))[base + slot * 0x34];
}

struct Unk8009DC48 {
    char pad0[0x114];
    int m114;
    char m118[1];
};

extern "C" void fn_8023C858(void* p, int a, int b);

extern "C" void fn_8009DC48(Unk8009DC48* o, int v)
{
    o->m114 = v;
    fn_8023C858(o->m118, 1, o->m114);
    fn_8023C858(o->m118, 2, o->m114);
    fn_8023C858(o->m118, 0xD, o->m114);
}

struct Unk8009DCAC {
    char pad0[0x114];
    int m114;
};

extern "C" void fn_8009DC48(Unk8009DC48* o, int v);

extern "C" void fn_8009DCAC(Unk8009DC48* o, int x) { fn_8009DC48(o, o->m114 + x); }

RecC::RecC(const char* name, DbObj* db, int c) : Rec(name, db, c), m24(0)
{
    m24 = new (0) Ent3C[m1C];
    fn_8040074C(m24, m1C * 0x3C);
    m14 = fn_800736EC(lbl_805B3B4C);
}

RecC::~RecC()
{
    if (m24) {
        delete[] m24;
        m24 = 0;
    }
}

struct Unk8009DDA8 {
    char pad0[0x1C];
    unsigned m1C;
    char pad20[4];
    Ent3C* m24;
};

extern "C" void fn_8009DDA8(Unk8009DDA8* p, unsigned i)
{
    if (i < p->m1C)
        fn_8040074C(&p->m24[i], 0x3C);
}
