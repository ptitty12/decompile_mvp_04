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

struct Unk803E945C_Ent {
    int m0;
    int m4;
    short m8;
    short mA;
    short mC;
    unsigned short mE;
};

struct Unk803E945C_Rec {
    char pad0[0x10];
    int m10;
    char pad14[0x28 - 0x14];
};

struct Unk803E945C_Aux {
    char pad0[0x30];
    unsigned short m30;
};

struct Unk803E945C_T {
    char pad0[8];
    char* m8;
    char padC[4];
    unsigned int m10;
    Unk803E945C_Ent* m14;
    Unk803E945C_Rec* m18;
    Unk803E945C_Aux* m1C;
    int m20[256];
    int* m420;
    int* m424;
};

extern char lbl_8060D8BC[];
extern "C" int fn_803E7320(int level, const char* fmt, ...);

/* near-miss: 3 slots; the bound t->m10 is loaded into r6 (ours r0) and the entry address is ents + i*16 in the other operand order */
extern "C" int fn_803E945C(Unk803E945C_T* t, const char* name)
{
    const char* p = name;
    Unk803E945C_Ent* ents = t->m14;
    unsigned int h = 0;
    if (*p != 0) {
        do {
            int c = *p;
            p++;
            h = (h << 4) + c;
            unsigned int g = h & 0xf0000000;
            if (g != 0)
                h ^= g >> 24;
            h &= ~g;
        } while (*p != 0);
    }
    unsigned int i = t->m20[h & 0xff];
    if (i != 0xffffffff) {
        do {
            if (i > t->m10)
                fn_803E7320(0, lbl_8060D8BC, i);
            if (t->m424[i] != 0) {
                Unk803E945C_Ent* e = &ents[i];
                if (strcmp(name, t->m8 + e->m0) == 0) {
                    int k = e->mE;
                    if (k > 0 && k < t->m1C->m30)
                        return t->m18[k].m10 + e->m4;
                }
            }
            i = t->m420[i];
        } while (i != 0xffffffff);
    }
    return 0;
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

extern "C" void fn_803E97C4(Unk803E9640* o);
extern "C" void fn_803E98A0(Unk803E9640* o);

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

/* 0x430-byte block of an intrusive doubly-linked list (next at +0, previous-link at +4) headed by lbl_8062C67C;
 * m420 / m424 are two arrays of m10 words. */
struct Unk803E97C4_Blk {
    Unk803E97C4_Blk* m0;
    Unk803E97C4_Blk** m4;
    char pad8[8];
    int m10;
    char pad14[0x420 - 0x14];
    void* m420;
    void* m424;
};

extern Unk803E97C4_Blk* lbl_8062C67C;

/* near-miss: instruction-for-instruction identical except that the block pointer and the object swap r30/r31
 * (retail keeps the object in r31). */
extern "C" void fn_803E97C4(Unk803E9640* o)
{
    Unk803E97C4_Blk* b = (Unk803E97C4_Blk*)o->m0;
    if (b) {
        Unk803E97C4_Blk** link = b->m4;
        if (link)
            *link = b->m0;
        else
            lbl_8062C67C = b->m0;
        Unk803E97C4_Blk* next = b->m0;
        if (next)
            next->m4 = b->m4;
        if (b->m420)
            lbl_8062C66C(b->m420, b->m10 << 2);
        if (b->m424)
            lbl_8062C66C(b->m424, b->m10 << 2);
        lbl_8062C66C(b, 0x430);
        b = 0;
        o->m0 = (int)b;
    }
    o->m2C = 0;
}

struct Unk803E98A0_Ent {
    void (*fn)(int);
    int arg;
};

struct Unk803E98A0_Node {
    void (*fn)(int, int);
    int a;
    int b;
    Unk803E98A0_Node* next;
};

extern "C" void fn_803E98A0(Unk803E9640* o)
{
    if (o->m8 != 0) {
        int i;
        for (i = o->m4 - 1; i >= 0; i--) {
            int off = i * 8;
            int base = o->m8;
            void (*f)(int) = *(void (**)(int))(off + base);
            Unk803E98A0_Ent* e = (Unk803E98A0_Ent*)(off + base);
            f(e->arg);
        }
        lbl_8062C66C((void*)o->m8, o->m4 * 8);
        o->m8 = 0;
    }
    Unk803E98A0_Node* n = (Unk803E98A0_Node*)o->mC;
    if (n != 0) {
        do {
            Unk803E98A0_Node* nx = n->next;
            n->fn(n->a, n->b);
            lbl_8062C66C(n, 0x10);
            n = nx;
        } while (n != 0);
    }
    o->mC = 0;
}

extern "C" int fn_803E9978(Unk803E7008_Ent** pp)
{
    Unk803E7008_Ent* e = *pp;
    if (!e)
        return 0;
    return e->m10;
}

struct Unk803E9994_Ent {
    int m0;
    const char* m4;
    int m8;
    int mC;
    Unk803E9994_Ent()
    {
        m0 = 0;
        m8 = 0;
    }
};

struct Unk803E9994_Hdr {
    char pad0[0x10];
    int m10;
};

extern "C" Unk803E9994_Ent fn_803E92E8(Unk803E9994_Hdr** c, int i);
extern "C" int strcmp(const char* a, const char* b);

inline int Unk803E9994_Count(Unk803E9994_Hdr** c)
{
    Unk803E9994_Hdr* h = *c;
    int n = 0;
    if (h != 0)
        n = h->m10;
    return n;
}

inline int Unk803E9994_Find(Unk803E9994_Hdr** c, const char* key, int* idx, Unk803E9994_Ent* out)
{
    while (*idx < Unk803E9994_Count(c)) {
        Unk803E9994_Ent e = fn_803E92E8(c, *idx);
        if (strcmp(key, e.m4) == 0) {
            *out = e;
            (*idx)++;
            return 1;
        }
        (*idx)++;
    }
    return 0;
}

extern "C" int fn_803E9994(Unk803E9994_Hdr** c, const char* key, int* idx, Unk803E9994_Ent* out)
{
    while (*idx < Unk803E9994_Count(c)) {
        Unk803E9994_Ent e = fn_803E92E8(c, *idx);
        if (strcmp(key, e.m4) == 0) {
            *out = e;
            (*idx)++;
            return 1;
        }
        (*idx)++;
    }
    return 0;
}

extern "C" int fn_803E9A54(Unk803E9994_Hdr** c, const char* key, int* idx, int* out)
{
    Unk803E9994_Ent loc;
    if (Unk803E9994_Find(c, key, idx, &loc)) {
        *out = loc.m8;
        return 1;
    }
    return 0;
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
