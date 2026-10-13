/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x80394744-0x803959E0 (code-only unit, 28 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* See ealib/tu_803912F8.cpp: this part of the library is not built with small data and does not
 * strength-reduce its loops; data is declared as unknown-size arrays to keep -G8 out of it. The last function
 * (0x803959D8) does use r13 (lbl_806EE9C0 is small data) and belongs to the next unit's object. */

extern int lbl_8069B9B4[];
extern int lbl_80624450[];
extern char lbl_806243E8[];
extern int (*lbl_806243F0[])();
extern void* lbl_806EE9C0;

struct McPair {
    unsigned short a;
    unsigned short b;
};

extern McPair lbl_8069BEC0[];

struct McRec {
    char pad0[4];
    unsigned char m4;
    unsigned char m5;
};

struct McRec1 {
    char pad0[1];
    unsigned char m1;
};

extern "C" int fn_80394FD4(int a, int b);
extern "C" int fn_80395150(int x, unsigned y);
extern "C" void fn_803958FC(int x);

struct McRec67 {
    char pad0[6];
    unsigned char m6;
    unsigned char m7;
};

extern "C" void fn_8039566C(McRec67*, int, int*, int*);

struct McObjB {
    char pad0[0xB];
    signed char mB;
};

typedef void* (*McMemcpyV)(void*, const void*, ...);
extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" McObjB* fn_80391CCC(int*);
extern "C" int fn_80392B80(int);
extern "C" int fn_803920BC(int*);
extern "C" void fn_80392BC0(int);

struct McCfg2 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
extern McCfg2 lbl_8069B7B8;
extern int lbl_8069B80C[];
extern "C" int fn_803948C0(int);

extern "C" unsigned fn_80394CE0();
extern "C" int fn_80394E3C(int a, int n, int b);
extern "C" void fn_80394EE4(int a, int b);

/* Record of fn_803958FC: +4 offset of a table of 32-byte entries, +8/+9 tag bytes, +0xB "built" flag, +0x10 entry
 * count, +0x18 halfword indices. */
struct McRecD {
    char pad0[4];
    int m4;
    unsigned char m8;
    unsigned char m9;
    char padA;
    unsigned char mB;
    char padC[4];
    unsigned short m10;
    char pad12[6];
    unsigned short m18[1];
};

struct McEntD {
    int m0;
    int m4;
    char m8[8];
    char m10[8];
    void* m18;
    unsigned m1C;
};

extern "C" unsigned fn_80391C04(unsigned char a, unsigned char b, unsigned short c);
extern "C" void fn_803B9858(void* a, void* b);
extern "C" void fn_803BA118(void* a, void* b);
extern "C" void fn_80395870(void* src, int key);

struct McEntH {
    char pad0[8];
    void* m8;
    unsigned mC;
};

/* Record behind the lbl_8069B7CC slots (see tu_803912F8.cpp McRec/McSlot): +8/+9 tag bytes, +0x10 halfword,
 * +0x12 byte count, byte ring after the header. */
struct McHdrB {
    char pad0[8];
    unsigned char m8;
    unsigned char m9;
    char padA[6];
    unsigned short m10;
    unsigned char m12;
};

struct McSlotB {
    McHdrB* m0;
    int m4;
};

extern McSlotB lbl_8069B7CC[];
extern "C" void fn_80392E3C(int x, int* a, int* b);
extern "C" void fn_803950B4(int key);

extern "C" int fn_80394744(unsigned v, int a, int idx)
{
    int r = 0;
    unsigned t = (v >> (idx * 2)) & 3;
    switch (t) {
    case 1:
        if (a != 0)
            r = 1;
        break;
    case 2:
        if (a != -1)
            r = 1;
        break;
    }
    return r;
}

extern "C" int fn_8039487C(McRec1* p)
{
    return fn_80394FD4(100, -1) < p->m1;
}

extern "C" int fn_80394C0C(int idx)
{
    int r = 0;
    char* t = (char*)lbl_8069B80C;
    int* pc = (int*)(t + 0x4c);
    int off = idx * 16;
    int v = *(int*)((char*)pc + off);
    if (v != 0) {
        r = fn_803948C0(v);
        if (r == 0 && lbl_8069B7B8.m10 != 0) {
            int k = 0;
            int q;
            do {
                q = ((int (*)(int, int))lbl_8069B7B8.m10)(k, v);
                if (q >= 0)
                    r = fn_803948C0(v);
                k++;
            } while (r == 0 && q > 0);
        }
        if (r < 0)
            r = 0;
    }
    return r;
}

extern "C" void fn_80394CD4(int x)
{
    lbl_8069B9B4[0] = x;
}

extern int lbl_80624438[];

extern "C" void fn_80394DE8(int x)
{
    int a = x + 0xF22D0E56;
    lbl_80624438[0] = a;
    int b = a + 0x96041893;
    lbl_80624438[1] = b;
    int c = b + 0x3DF3B646;
    lbl_80624438[2] = c;
    int d = c + 0x40DDE76D;
    lbl_80624438[3] = d;
    int e = d + 0x97327AE1;
    lbl_80624438[4] = e;
    lbl_80624438[5] = e + 0xD1A9FBE7;
}

extern "C" int fn_80394E3C(int a, int n, int b)
{
    int r = -1;
    if (n > 0x20)
        n = 0x20;
    int idx = lbl_80624450[0];
    int cnt = 0;
    int steps = 0;
    int done = 0;
    do {
        if (cnt < n) {
            if (lbl_8069BEC0[idx].b == b) {
                cnt++;
                if (lbl_8069BEC0[idx].a == a) {
                    done = 1;
                    r = cnt - 1;
                }
            }
        } else {
            done = 1;
        }
        idx--;
        if (idx < 0)
            idx += 0x20;
        steps++;
        if (steps > 0x20)
            done = 1;
    } while (done == 0);
    return r;
}

extern "C" void fn_80394EE4(int a, int b)
{
    lbl_80624450[0] = lbl_80624450[0] + 1;
    if (lbl_80624450[0] > 31)
        lbl_80624450[0] = 0;
    lbl_8069BEC0[lbl_80624450[0]].a = a;
    lbl_8069BEC0[lbl_80624450[0]].b = b;
}

extern "C" void fn_80394F24(int seed)
{
    int i;
    for (i = 0; i < 32; i++) {
        lbl_8069BEC0[i].a = -1;
        lbl_8069BEC0[i].b = -1;
    }
    seed = seed + (seed << 16);
    lbl_80624450[0] = 0;
    fn_80394DE8(seed);
    int n = 0x20 - (seed % 32);
    for (i = 0; i < n; i++)
        fn_80394FD4(10, -1);
}

extern "C" int fn_80394FD4(int a, int b)
{
    int cnt = 0;
    int done = 0;
    int n = a / 2;
    int best = -1;
    if (n > 10)
        n = 10;
    unsigned v = ((fn_80394CE0() >> 16) * a) >> 16;
    unsigned pick = v;
    if (b != -1) {
        b = (unsigned short)b;
        do {
            int r = fn_80394E3C(v, n, b);
            if (r == -1) {
                pick = v;
                done = 1;
            } else if (r > best) {
                best = r;
                pick = v;
            }
            cnt++;
            if (cnt > 0x1F)
                done = 1;
            if (done == 0)
                v = ((fn_80394CE0() >> 16) * a) >> 16;
        } while (done == 0);
        fn_80394EE4(pick, b);
    }
    return v;
}

/* near-miss 96.9%: same code; retail keeps the slot offset in r7, the record in r10 and the byte index in r8 (ours r8,
 * r11, r10) and loads the table size before the inner test. */
extern "C" void fn_803950B4(int key)
{
    int i = 0;
    do {
        McHdrB* s = lbl_8069B7CC[i].m0;
        if (s != 0 && lbl_8069B7CC[i].m4 == key) {
            int j = 0;
            unsigned char* tab = (unsigned char*)s + ((((s->m10 * 2) + 3) & ~3) + 0x18);
            while (j < lbl_8069B7CC[i].m0->m12) {
                tab[j] = 0xFF;
                j++;
            }
        }
        i++;
    } while (i <= 7);
}

extern "C" int fn_80395150(int x, unsigned y)
{
    int r = 0;
    if ((*(int*)x & 0xFFFF0000) == 0x03120000) {
        int a;
        int b;
        fn_80392E3C(x, &a, &b);
        int i;
        for (i = 0; i <= 7; i++) {
            McHdrB* s = lbl_8069B7CC[i].m0;
            if (s != 0 && s->m9 == b && s->m8 == a)
                goto out;
        }
        for (i = 0; i <= 7; i++) {
            if (lbl_8069B7CC[i].m0 == 0) {
                lbl_8069B7CC[i].m0 = (McHdrB*)x;
                r = 1;
                lbl_8069B7CC[i].m4 = y;
                break;
            }
        }
        fn_803950B4(y);
    }
out:
    return r;
}

extern "C" int fn_80395250(int x, unsigned y)
{
    int r = 0;
    if (y <= 7) {
        r = fn_80395150(x, y);
        fn_803958FC(x);
    }
    return r;
}

struct McRec6 {
    char pad0[6];
    unsigned char m6;
};

struct McTri {
    int a;
    int b;
    int c;
};

inline unsigned char* McT(McRec6* p)
{
    int n = p->m6 * 2;
    n = (n + 3) & ~3;
    return (unsigned char*)p + (n + 0xc);
}

extern "C" int fn_80395350(McRec6* p, int i)
{
    McTri v;
    int t = (int)McT(p);
    int k = i * 3;
    v.a = *(unsigned char*)(k + t);
    v.b = *(unsigned char*)(k + t + 1);
    v.c = *(unsigned char*)(k + t + 2);
    return v.a;
}

extern "C" int fn_80395714(McRec67* p, int i, int c, int d)
{
    int x;
    int y;
    fn_8039566C(p, i, &x, &y);
    y = y & ~d;
    x = x & y;
    return (y & c) == x;
}

/* near-miss: retail uses mullw (i * size) with a different add order and one fewer instruction; 4 spellings tried. */
extern "C" char* fn_80395774(McRec* p, int i)
{
    if (i >= p->m5)
        return 0;
    return (char*)p + i * ((p->m4 & 0x7F) + 2) + 0xE;
}

extern "C" int fn_8039582C()
{
    int r = 0;
    int (*f)() = lbl_806243F0[0];
    if (f != 0)
        r = f();
    return r;
}

extern "C" char* fn_80395864()
{
    return lbl_806243E8;
}

extern "C" void fn_80395870(void* src, int key)
{
    int sp = key;
    McObjB* o = fn_80391CCC(&sp);
    if (o != 0) {
        int sz = o->mB * 4;
        int* buf = (int*)fn_80392B80(sz + 4);
        if (buf != 0) {
            buf[0] = sp;
            ((McMemcpyV)memcpy)(buf + 1, src, sz);
            if (fn_803920BC(buf) == 0)
                fn_80392BC0((int)buf);
        }
    }
}

extern "C" void fn_803958FC(int x)
{
    McRecD* r = (McRecD*)x;
    if (r != 0 && r->m4 != 0 && r->mB == 0) {
        McEntD* base = (McEntD*)((char*)r + r->m4);
        McEntD* end = base + r->m10;
        int i;
        for (i = 0; i < r->m10; i++) {
            int off = i << 5;
            McEntD* e = (McEntD*)(off + (int)base);
            e->m0 = (int)end + e->m0;
            fn_803B9858(e->m8, e);
            McEntH* e2 = (McEntH*)((char*)e + 0x10);
            e2->m8 = (void*)fn_80395870;
            int ioff = i * 2;
int tb = (int)r->m18;
            e2->mC = fn_80391C04(r->m8, r->m9, *(unsigned short*)((char*)r + *(unsigned short*)(ioff + tb) * 4));
            fn_803BA118(e->m8, e2);
        }
        r->mB = 1;
    }
}

extern "C" void fn_803959D8(void* p)
{
    lbl_806EE9C0 = p;
}

/* Same six-word additive generator as fn_804027DC; signed seed words are viewed as unsigned for carry tests. */
struct Gen6 { unsigned w0,w1,w2,w3,w4,w5; };

extern "C" unsigned fn_80394CE0()
{
    unsigned c = 0;
    unsigned x = ((Gen6*)lbl_80624438)->w5 + ((Gen6*)lbl_80624438)->w4;
    if (x < ((Gen6*)lbl_80624438)->w5 || x < ((Gen6*)lbl_80624438)->w4)
        c = 1;
    unsigned o0 = ((Gen6*)lbl_80624438)->w0;
    unsigned o3 = ((Gen6*)lbl_80624438)->w3;
    unsigned o2 = ((Gen6*)lbl_80624438)->w2;
    unsigned o1 = ((Gen6*)lbl_80624438)->w1;
    ((Gen6*)lbl_80624438)->w4 = x;
    x = x + o3 + c;
    ((volatile Gen6*)lbl_80624438)->w3 = x;
    x = x + o2 + (x < o3);
    ((volatile Gen6*)lbl_80624438)->w2 = x;
    x = x + o1 + (x < o2);
    ((volatile Gen6*)lbl_80624438)->w1 = x;
    x = x + o0 + (x < o1);
    ((Gen6*)lbl_80624438)->w0 = x;
    if (++((Gen6*)lbl_80624438)->w5 == 0)
        if (++((Gen6*)lbl_80624438)->w4 == 0)
            if (++((Gen6*)lbl_80624438)->w3 == 0)
                if (++((Gen6*)lbl_80624438)->w2 == 0)
                    if (++((Gen6*)lbl_80624438)->w1 == 0)
                        x = ++((Gen6*)lbl_80624438)->w0;
    return x;
}