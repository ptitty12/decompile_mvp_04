/*
 * Game code, .text 0x8009BC3C-0x8009FC5C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80090880.h"

extern const char lbl_805B3B4C[];

/* near-miss (18 of 27 slots): retail jumps to the shared fn_8009D0D4 tail differently */
extern "C" void fn_8009CBC8(void* o, int x);
extern "C" void fn_8009CF6C(void* o, int x);
extern "C" void fn_8009D0D4(void* o);

extern "C" void fn_8009CB5C(void* o, int kind, int x)
{
    if (kind != 0) {
        switch (kind) {
        case 1:
            fn_8009CBC8(o, x);
            break;
        case 2:
            fn_8009CF6C(o, x);
            break;
        }
        fn_8009D0D4(o);
    }
}

extern "C" int fn_8009CDC8(void* self, int* arr)
{
    int best = 0;
    int idx = -1;
    volatile int sp8 = 0;
    int i = 0;
    do {
        int v = arr[i];
        if (v > best) {
            best = v;
            idx = i;
        }
        int t;
        if (i > 9)
            t = i;
        else
            t = i + 1;
        sp8 = t;
        i = t;
    } while (i <= 9);
    return idx;
}

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

union Unk8009DDE4_Val {
    int i;
    float f;
};

/* Column default: 5 for columns 54 and 55, 0 otherwise. The value lives in a
   union, so it stays in its stack slot. */
extern "C" int fn_8009DDE4(void* l, int k)
{
    Unk8009DDE4_Val v;
    v.i = 0;
    switch ((unsigned)k) {
    case 0:
        v.i = 0;
        break;
    case 1:
        v.i = 0;
        break;
    case 2:
        v.i = 0;
        break;
    case 3:
        v.i = 0;
        break;
    case 4:
        v.i = 0;
        break;
    case 5:
        v.i = 0;
        break;
    case 6:
        v.i = 0;
        break;
    case 7:
        v.i = 0;
        break;
    case 8:
        v.i = 0;
        break;
    case 9:
        v.i = 0;
        break;
    case 10:
        v.i = 0;
        break;
    case 11:
        v.i = 0;
        break;
    case 12:
        v.i = 0;
        break;
    case 13:
        v.i = 0;
        break;
    case 14:
        v.i = 0;
        break;
    case 15:
        v.i = 0;
        break;
    case 16:
        v.i = 0;
        break;
    case 17:
        v.i = 0;
        break;
    case 18:
        v.i = 0;
        break;
    case 19:
        v.i = 0;
        break;
    case 20:
        v.i = 0;
        break;
    case 21:
        v.i = 0;
        break;
    case 22:
        v.i = 0;
        break;
    case 23:
        v.i = 0;
        break;
    case 24:
        v.i = 0;
        break;
    case 25:
        v.i = 0;
        break;
    case 26:
        v.i = 0;
        break;
    case 27:
        v.i = 0;
        break;
    case 28:
        v.i = 0;
        break;
    case 29:
        v.i = 0;
        break;
    case 30:
        v.i = 0;
        break;
    case 31:
        v.i = 0;
        break;
    case 32:
        v.i = 0;
        break;
    case 33:
        v.i = 0;
        break;
    case 34:
        v.i = 0;
        break;
    case 35:
        v.i = 0;
        break;
    case 36:
        v.i = 0;
        break;
    case 37:
        v.i = 0;
        break;
    case 38:
        v.i = 0;
        break;
    case 39:
        v.i = 0;
        break;
    case 40:
        v.i = 0;
        break;
    case 41:
        v.i = 0;
        break;
    case 42:
        v.i = 0;
        break;
    case 43:
        v.i = 0;
        break;
    case 44:
        v.i = 0;
        break;
    case 45:
        v.i = 0;
        break;
    case 46:
        v.i = 0;
        break;
    case 47:
        v.i = 0;
        break;
    case 48:
        v.i = 0;
        break;
    case 49:
        v.i = 0;
        break;
    case 50:
        v.i = 0;
        break;
    case 51:
        v.i = 0;
        break;
    case 52:
        v.i = 0;
        break;
    case 53:
        v.i = 0;
        break;
    case 54:
        v.i = 5;
        break;
    case 55:
        v.i = 5;
        break;
    }
    return v.i;
}

/* Every column yields 0; the original keeps the case tree as dead compares
   (PATTERNS, "Hard-case families 4"). */
extern "C" int fn_8009E060(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    case 4:
        r = 0;
        break;
    case 5:
        r = 0;
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = 0;
        break;
    case 9:
        r = 0;
        break;
    case 10:
        r = 0;
        break;
    case 11:
        r = 0;
        break;
    case 12:
        r = 0;
        break;
    case 13:
        r = 0;
        break;
    case 14:
        r = 0;
        break;
    case 15:
        r = 0;
        break;
    case 16:
        r = 0;
        break;
    case 17:
        r = 0;
        break;
    case 18:
        r = 0;
        break;
    case 19:
        r = 0;
        break;
    case 20:
        r = 0;
        break;
    case 21:
        r = 0;
        break;
    case 22:
        r = 0;
        break;
    case 23:
        r = 0;
        break;
    case 24:
        r = 0;
        break;
    case 25:
        r = 0;
        break;
    case 26:
        r = 0;
        break;
    case 27:
        r = 0;
        break;
    case 28:
        r = 0;
        break;
    case 29:
        r = 0;
        break;
    case 30:
        r = 0;
        break;
    case 31:
        r = 0;
        break;
    case 32:
        r = 0;
        break;
    case 33:
        r = 0;
        break;
    case 34:
        r = 0;
        break;
    case 35:
        r = 0;
        break;
    case 36:
        r = 0;
        break;
    case 37:
        r = 0;
        break;
    case 38:
        r = 0;
        break;
    case 39:
        r = 0;
        break;
    case 40:
        r = 0;
        break;
    case 41:
        r = 0;
        break;
    case 42:
        r = 0;
        break;
    case 43:
        r = 0;
        break;
    case 44:
        r = 0;
        break;
    case 45:
        r = 0;
        break;
    case 46:
        r = 0;
        break;
    case 47:
        r = 0;
        break;
    case 48:
        r = 0;
        break;
    case 49:
        r = 0;
        break;
    case 50:
        r = 0;
        break;
    case 51:
        r = 0;
        break;
    case 52:
        r = 0;
        break;
    case 53:
        r = 0;
        break;
    case 54:
        r = 0;
        break;
    case 55:
        r = 0;
        break;
    }
    return r;
}

/* near-miss (39 of 50 slots): retail tests kind linearly (1, <1, 2, 3), the switch makes a binary tree */
struct Unk8009E93C {
    char pad0[0x1C];
    unsigned m1C;
    char pad20[4];
    char* m24;
};

extern "C" char* fn_8040B61C(char* dst, const char* src);

extern "C" char* fn_8009E93C(Unk8009E93C* p, int kind, unsigned idx, char* out)
{
    if (idx < p->m1C) {
        switch (kind) {
        default:
            fn_8040B61C(out, p->m24 + idx * 0x3C + 0x10);
            break;
        case 1:
            fn_8040B61C(out, p->m24 + idx * 0x3C + 0x14);
            break;
        case 2:
            fn_8040B61C(out, p->m24 + idx * 0x3C + 0x28);
            break;
        case 3:
            fn_8040B61C(out, p->m24 + idx * 0x3C + 0x2C);
            break;
        }
    }
    return out;
}
