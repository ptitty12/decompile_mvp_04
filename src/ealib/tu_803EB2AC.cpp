/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803EB2AC-0x803EBF90 (code-only unit, 29 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* Handler table registered through fn_803EB520: hooks at +0xC (enter) and +0x10 (leave). */
struct Unk803EB2AC_Hooks {
    char pad0[0xC];
    void (*mC)();
    void (*m10)();
};

extern Unk803EB2AC_Hooks* lbl_806EE9D8;
extern void* lbl_806EE9DC;
extern int lbl_8062C76C[];

extern "C" void fn_804006FC(void (*cb)());
extern "C" void fn_803FFA60(int* a, int* b, int c);
extern "C" void fn_803EB330(void* p);
extern "C" void fn_803EB560(void);
extern "C" void fn_80400690(void (*cb)());
extern "C" void* fn_803EB2EC(void* self);
extern char lbl_8062C7A0[];
extern "C" int fn_803EC9D4(int c);
extern "C" int fn_803EC03C(char* p);

/* binary search over `n` records of `size` bytes whose first halfword is the key */
extern "C" void* fn_803EB2AC(int key, char* base, int n, int size)
{
    while (n != 0) {
        int off = (n >> 1) * size;
        unsigned short v = *(unsigned short*)(base + off);
        char* p = base + off;
        int d = key - v;
        if (d == 0)
            return p;
        if (d > 0) {
            base = p + size;
            n--;
        }
        n >>= 1;
    }
    return 0;
}

extern "C" void* fn_803EB2EC(void* self)
{
    if (lbl_806EE9D8->mC)
        lbl_806EE9D8->mC();
    return self;
}

extern "C" void fn_803EB330(void* p)
{
    if (lbl_806EE9D8->m10)
        lbl_806EE9D8->m10();
}

/* swaps the case of an ASCII or Latin-1 letter, 0 for anything else */
extern "C" int fn_803EB364(int c)
{
    if ((unsigned)(c - 0x41) <= 0x19)
        return c + 0x20;
    if ((unsigned)(c - 0x61) <= 0x19)
        return c - 0x20;
    if ((unsigned)(c - 0xC0) <= 0x16)
        return c + 0x20;
    if ((unsigned)(c - 0xD8) <= 0x6)
        return c + 0x20;
    if ((unsigned)(c - 0xE0) <= 0x16)
        return c - 0x20;
    if ((unsigned)(c - 0xF8) <= 0x6)
        return c - 0x20;
    return 0;
}

extern "C" int fn_80364B54(void* a, void* b, int c);

extern "C" int fn_803EB3CC(void* a, void* b)
{
    return fn_80364B54(a, b, 0);
}

extern "C" int fn_80364F34(void* a, void* b, int c);

extern "C" int fn_803EB3F0(void* a, void* b)
{
    return fn_80364F34(a, b, 0);
}

extern "C" void fn_80365314(void* menu, int a);

extern "C" void fn_803EB414(void* self, int a)
{
    fn_80365314(self, a);
}

extern "C" void fn_8036578C(void* menu, int a);

extern "C" void fn_803EB434(void* self, int a)
{
    fn_8036578C(self, a);
}

extern "C" void fn_803EB520(Unk803EB2AC_Hooks* h)
{
    lbl_806EE9D8 = h;
}

extern "C" void fn_803EB528(int* p)
{
    fn_803FFA60(lbl_8062C76C, p, *p);
}

extern "C" int fn_803EB558(char* p)
{
    return *(int*)(p + 0x24);
}

extern "C" void fn_803EB560(void)
{
    if (lbl_806EE9DC) {
        fn_803EB330(lbl_806EE9DC);
        lbl_806EE9DC = 0;
        fn_804006FC(fn_803EB560);
    }
}

extern "C" void fn_803EB5A0(void)
{
    if (lbl_806EE9DC == 0) {
        lbl_806EE9DC = fn_803EB2EC(lbl_8062C7A0);
        fn_80400690(fn_803EB560);
    }
}

/* linear search of `n` 4-byte records for the one whose first halfword is `key` */
struct Unk803EB5E4_Rec {
    unsigned short m0;
    signed char m2;
    unsigned char m3;
};

/* near-miss (flags): both functions are exact at -O2 -fno-strength-reduce (0 slots, probed with the unit's other
 * flags); with the configured flags the loop gets strength-reduced and 12 / 14 slots differ. */
extern "C" Unk803EB5E4_Rec* fn_803EB5E4(int n, Unk803EB5E4_Rec* tbl, int key)
{
    for (int i = 0; i < n; i++) {
        if (tbl[i].m0 == key)
            return &tbl[i];
    }
    return 0;
}

extern "C" Unk803EB5E4_Rec* fn_803EB61C(int n, Unk803EB5E4_Rec* tbl, int key, int flag)
{
    for (int i = 0; i < n; i++) {
        if (tbl[i].m0 == key && tbl[i].m3 == flag)
            return &tbl[i];
    }
    return 0;
}

struct Unk803EB660_Entry {
    unsigned short m0;
    char pad2[9];
    unsigned char mB;
    unsigned short mC;
};

struct Unk803EB660_Tbl {
    char pad0[0xC];
    unsigned int mC;
    char pad10[8];
    int m18;
};

extern "C" int fn_803EB660(Unk803EB660_Tbl* t, Unk803EB660_Entry* e, int key)
{
    signed char r = 0;
    if (e->mB) {
        Unk803EB5E4_Rec* f;
        if (t->mC & 0x40000) {
            f = fn_803EB5E4(e->mB, (Unk803EB5E4_Rec*)((char*)t + t->m18 + (e->mC * 4 + 4)), key);
        } else {
            int off = t->m18;
            f = fn_803EB61C(*(int*)((char*)t + off), (Unk803EB5E4_Rec*)((char*)t + off + 4), key, e->m0);
        }
        if (f)
            r = f->m2;
    }
    return r;
}

extern "C" void fn_803EB6F4(void)
{
}

extern "C" int fn_803EB6F8(int c)
{
    if (c == 0)
        c = 0x20;
    char ch = fn_803EC9D4(c);
    return fn_803EC03C(&ch);
}

extern "C" int fn_803EB83C(int k)
{
    switch (k) {
    case 8:
        return 0x100;
    case 4:
        return 0x10;
    default:
        return 0;
    }
}

extern "C" void fn_803EBC70(void* menu, int a);

extern "C" void fn_803EBD14(void* self, int a)
{
    fn_803EBC70(self, a);
}

extern int (*lbl_806EE9E4)(int a, int b, int c, int d, int e);
extern "C" int fn_803EBD34(int x);
extern "C" void fn_803EBDF4(int r, int x);
extern "C" int fn_803EC3D4(int x);

extern "C" int fn_803EBF2C(int x)
{
    int a = fn_803EBD34(x);
    int r = lbl_806EE9E4(fn_803EC3D4(x), a, 0, 0x10, 0x400);
    fn_803EBDF4(r, x);
    return r;
}
