/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803912F8-0x803927E4 (code-only unit, 37 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* FLAGS EVIDENCE (for the lead): this unit has no r13 use and its loops are not strength-reduced or turned into
 * counted (bdnz) loops. fn_803913FC and fn_80391784 match exactly with `-O2 -G0 -fno-strength-reduce`
 * (cflags_ealib plus that flag), and fn_80391E2C and fn_80391C04 as well; under the unit's current lib flags
 * (-O2 default -G8) only the loop-free functions match. The data below is declared as arrays of unknown size
 * so that -G8 does not put it in small data.
 *
 * Resource table of the MAD/VP6 file layer: lbl_806243F8[0] = entries (8 bytes each), lbl_80624400[0] = capacity,
 * lbl_80624404[0] = used count. Evidence: fn_803913FC clears n entries, fn_80391784 searches them. */
struct McEntry {
    int m0;
    void* m4;
};

struct McEntryHdr {
    char pad0[0xA];
    unsigned short mA;
};

/* Declared as arrays of unknown size: retail reaches these with lis/lwz (not r13), i.e. this part of the
 * library was built without small data; an array of unknown size is never put in .sdata by -G8. */
extern McEntry* lbl_806243F8[];
extern int lbl_806243FC[];
extern int lbl_80624400[];
extern int lbl_80624404[];

extern "C" void fn_803912F8()
{
    lbl_806243F8[0] = 0;
    lbl_80624400[0] = 0;
    lbl_80624404[0] = 0;
    lbl_806243FC[0] = 0;
}

extern "C" void fn_80391320()
{
    lbl_806243F8[0] = 0;
    lbl_80624400[0] = 0;
    lbl_80624404[0] = 0;
    lbl_806243FC[0] = 0;
}

extern "C" int fn_803913F4(int x)
{
    return x << 3;
}

extern "C" void fn_803913FC(int n, McEntry* tbl)
{
    lbl_80624400[0] = n;
    lbl_806243F8[0] = tbl;
    if (tbl == 0)
        return;
    for (int i = 0; i < n; i++) {
        tbl[i].m0 = 0;
        tbl[i].m4 = 0;
    }
}

extern "C" int fn_80391734(int idx, unsigned x)
{
    int r = 0;
    McEntry* tbl = lbl_806243F8[0];
    if (tbl != 0 && idx >= 0) {
        McEntryHdr* h = (McEntryHdr*)tbl[idx].m4;
        unsigned v = h->mA;
        if (v != 0xFFFF)
            r = x < v;
    }
    return r;
}

extern "C" int fn_80391784(int x)
{
    for (int i = 0; i < lbl_80624404[0]; i++) {
        if (lbl_806243F8[0][i].m0 == x)
            return i;
    }
    return -1;
}

/* near-miss (with -fno-strength-reduce too): one extra `mr r0,r3` for a; 4 spellings tried. */
extern "C" int fn_80391A10(unsigned a, int b, int c)
{
    int q = b / c;
    unsigned r = b - q * c;
    if (a > r)
        return q * a + r;
    return q * a + a;
}

union McTagU {
    unsigned w;
    struct {
        unsigned short c;
        unsigned char b;
        unsigned char a;
    } f;
};

extern "C" unsigned fn_80391C04(unsigned char a, unsigned char b, unsigned short c)
{
    McTagU t;
    t.f.b = b;
    t.f.c = c;
    t.f.a = a;
    return *(unsigned*)&t;
}

extern McEntry lbl_8069B7CC[8];

extern "C" void fn_80391E2C()
{
    for (int i = 0; i < 8; i++) {
        lbl_8069B7CC[i].m0 = 0;
        lbl_8069B7CC[i].m4 = 0;
    }
}

extern int lbl_8069B80C[];

/* near-miss: retail forms lbl+0x20 first and indexes it; 3 spellings of the +8 index tried. */
extern "C" int fn_80392098(int i)
{
    return (unsigned)lbl_8069B80C[i + 8] <= 15;
}

extern "C" void fn_80392388(int* p)
{
    p[0] = 0;
    p[1] = 0;
}

struct McShortList {
    int m0;
    unsigned short* m4;
};

extern "C" int fn_80392398(int x, McShortList* s)
{
    int r = 0;
    for (int i = 0; i < s->m0; i++) {
        if (s->m4[i] == x) {
            r = 1;
            break;
        }
    }
    return r;
}

extern int lbl_806E2A50[];

extern "C" int fn_803927D0(int i) { return lbl_8069B80C[i]; }
