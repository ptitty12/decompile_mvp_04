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

/* near-miss: 15 vs 16 instructions (retail branches on cmpwi 1 / cmpwi 2 through a shared tail). */
extern "C" int fn_80394744(unsigned v, int a, int idx)
{
    int r = 0;
    unsigned t = (v >> (idx * 2)) & 3;
    if (t == 1) {
        if (a != 0)
            r = 1;
    } else if (t == 2) {
        if (a != -1)
            r = 1;
    }
    return r;
}

extern "C" int fn_8039487C(McRec1* p)
{
    return fn_80394FD4(100, -1) < p->m1;
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

extern "C" int fn_80395250(int x, unsigned y)
{
    int r = 0;
    if (y <= 7) {
        r = fn_80395150(x, y);
        fn_803958FC(x);
    }
    return r;
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

extern "C" void fn_803959D8(void* p)
{
    lbl_806EE9C0 = p;
}
