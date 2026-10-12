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
    short a;
    short b;
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

extern "C" int fn_80395250(int x, unsigned y)
{
    int r = 0;
    if (y <= 7) {
        r = fn_80395150(x, y);
        fn_803958FC(x);
    }
    return r;
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

extern "C" void fn_803959D8(void* p)
{
    lbl_806EE9C0 = p;
}
