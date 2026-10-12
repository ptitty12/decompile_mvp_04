/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803927E4-0x80394744 (code-only unit, 52 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* FLAGS EVIDENCE (for the lead): like tu_803912F8 this unit has no r13 use and keeps `mulli`/`slwi` index math
 * inside its loops (no strength reduction, no bdnz); the functions marked below match with
 * `-O2 -G0 -fno-strength-reduce` and not with the unit's current -O2 -G8 flags. Data is declared as arrays of
 * unknown size so that -G8 does not place it in small data. */

extern int (*lbl_8069B7C4[])();
extern int (*lbl_806243E0[])();
extern void (*lbl_806243E4[])();
extern int lbl_806243F4[];
extern int lbl_8069B990[];

struct McSlotA {
    short m0;
    short pad2;
    int m4;
};

extern McSlotA lbl_8069B94C[];

struct McCfg {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

extern McCfg lbl_8069B7B8;

extern "C" void fn_80391320();
extern "C" void fn_80391E2C();

/* near-miss: retail keeps the result in r9 (mr r9,r3 / mr r3,r9) and sets it before the call; 6 spellings tried. */
extern "C" int fn_80392948()
{
    int (*f)() = lbl_8069B7C4[0];
    int r = 1;
    if (f != 0)
        r = f();
    return r;
}

extern "C" void fn_80392B6C(int (*a)(), void (*b)())
{
    lbl_806243E0[0] = a;
    lbl_806243E4[0] = b;
}

/* near-miss: same as fn_80392948 */
extern "C" int fn_80392B80()
{
    int (*f)() = lbl_806243E0[0];
    int r = 0;
    if (f != 0)
        r = f();
    return r;
}

extern "C" void fn_80392BC0()
{
    if (lbl_806243E4[0] != 0)
        lbl_806243E4[0]();
}

/* needs -fno-strength-reduce */
extern "C" void fn_80392BF4()
{
    for (int i = 0; i < 8; i++) {
        lbl_8069B94C[i].m0 = -1;
        lbl_8069B94C[i].m4 = 0;
    }
}

extern "C" void fn_80392C94(int a, int b)
{
    if (lbl_806243F4[0] == 0x01789A34) {
        lbl_8069B7B8.m4 = a;
        lbl_8069B7B8.m8 = b;
    }
}

extern "C" void fn_80392CC0()
{
    lbl_8069B7B8.m0 = 0;
    lbl_8069B7B8.m4 = 0;
    lbl_8069B7B8.m8 = 0;
    lbl_8069B7B8.mC = 0;
    lbl_8069B7B8.m10 = 0;
}

extern "C" void fn_80392CE4(int (*a)())
{
    if (lbl_806243F4[0] == 0x01789A34)
        lbl_8069B7C4[0] = a;
}

extern "C" void fn_80392DF4()
{
    if (lbl_806243F4[0] == 0x01789A34) {
        lbl_806243F4[0] = 0;
        fn_80392CC0();
        fn_80391320();
        fn_80391E2C();
    }
}

struct McTag2 {
    char pad0[8];
    unsigned char m8;
    unsigned char m9;
};

extern "C" void fn_80392E3C(McTag2* p, int* a, int* b)
{
    *a = p->m8;
    *b = p->m9;
}

/* near-miss: retail masks the shifted bit with clrlwi 24 before the and; ours folds it away. */
extern "C" int fn_803931B4(unsigned char* bits, int n)
{
    int i = n / 8;
    return bits[i] & (unsigned char)(1 << (n - i * 8));
}

struct McBuf {
    char pad0[0x91];
    unsigned char m91;
    unsigned char m92[1];
};

extern "C" int fn_8039332C(McBuf* p, unsigned char v)
{
    int r = 0;
    unsigned c = p->m91;
    if (c <= 254) {
        p->m92[c] = v;
        r = 1;
        p->m91 = p->m91 + 1;
    }
    return r;
}

extern "C" int fn_80393584(int x)
{
    int r = 0;
    if (lbl_8069B990[0] != 0)
        r = x * 100 / lbl_8069B990[0];
    return r;
}

extern int lbl_80624418[];

extern "C" int fn_80393640(unsigned x)
{
    return (x & 0x1F) * lbl_80624418[(x >> 5) & 7];
}

/* needs -fno-strength-reduce */
struct McRow12 {
    char pad0[0xB];
    unsigned char mB;
};

struct McTable {
    char pad0[0x90];
    unsigned char m90;
    unsigned char m91;
};

extern "C" void fn_8039437C(McTable* p)
{
    p->m91 = 0;
    p->m90 = 0;
    for (int i = 0; i < 12; i++) {
        McRow12* r = (McRow12*)((char*)p + i * 12);
        r->mB = 0;
    }
}

struct McRow160 {
    char pad0[9];
    unsigned char m9;
    char pad1[0xA0 - 10];
};

extern McRow160 lbl_8069B9C0[];

extern "C" int fn_80394638(int i)
{
    McRow160* r = (McRow160*)(i * 0xA0 + (int)lbl_8069B9C0);
    return r->m9;
}
