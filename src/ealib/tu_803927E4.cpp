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
    unsigned short m0;
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

struct McHdr5 {
    char pad0[2];
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
};

struct McHdr6 {
    char pad0[4];
    unsigned char m4;
    unsigned char m5;
};

extern "C" int fn_80394FD4(int, int);

struct McHdr7 {
    char pad0[4];
    short m4;
    char pad6[2];
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
};

struct McEnt8 {
    char pad0[4];
    unsigned char m4;
    char pad5;
    unsigned char m6;
    char pad7;
};
struct McSrc {
    char pad0[4];
    signed char m4;
    char pad5[3];
    McEnt8 m8[1];
};

struct McElem12 {
    int m0;
    short m4;
    short m6;
    short m8;
    short pad;
};

struct McRow160 {
    int m0;
    int m4;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    unsigned char mB;
    int mC;
    McElem12 e[12];
};

extern McRow160 lbl_8069B9C0[];

struct McEntry {
    int m0;
    void* m4;
};

extern McEntry* lbl_806243F8[];

extern "C" int fn_803957A4(void*, int, int*, int*);

struct McRec12 {
    char pad0[4];
    short m4;
    char pad6[2];
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    unsigned char mB;
};

struct McBufB {
    char pad0[0x92];
    unsigned char m92[1];
};

struct McRec16 {
    unsigned m0;
    unsigned short m4;
    unsigned char m6;
    unsigned char m7;
    int m8;
    int mC;
};

extern int lbl_8069B80C[];
extern int lbl_80624414;
extern "C" int fn_80392098(int);
extern "C" void fn_803943A8(unsigned);
extern "C" int fn_80394650(unsigned);
extern "C" int fn_80392AA4(unsigned);
extern "C" int fn_80394638(int);
extern "C" int fn_80394C0C(int);

struct McA6 {
    char pad0[6];
    short m6;
};

struct McB {
    char pad0[4];
    unsigned char m4;
    unsigned char m5;
    unsigned char m6;
    char pad7[3];
    unsigned short mA;
};

extern "C" int fn_803931EC(McA6*, McB*, int);

extern "C" int fn_8039223C(int, int, ...);
extern "C" void fn_803912F8();
extern "C" void fn_80391EA4();
extern "C" void fn_80394CD4(int);
extern "C" void fn_80394F24(int);
extern "C" void fn_8039445C();
extern int (*lbl_80624408[])(int, int, ...);
extern signed char lbl_80624454[];
extern int lbl_8069B98C[];
extern int lbl_8069B994[];

struct McHdrP {
    char pad0[2];
    unsigned char m2;
    unsigned char m3;
};

extern "C" int fn_80393D18(McHdrP*, McBufB*, int);
extern "C" void fn_80393E60(int*, McBufB*, McHdrP*);

extern "C" void fn_803927E4(unsigned);

extern "C" void fn_80392BC0(int);

struct McEnt8W {
    unsigned m0;
    unsigned char m4;
    char pad5;
    unsigned char m6;
    char pad7;
};
struct McSrcW {
    char pad0[4];
    signed char m4;
    char pad5[3];
    McEnt8W m8[1];
};
extern "C" int fn_80391DC4(int*, unsigned char**);

extern "C" int fn_80393918(McBufB*, McHdrP*);

extern "C" char* fn_80395774(void*, int);

struct McSp {
    unsigned short a;
    short b;
};

extern "C" void fn_8039539C(int*, int, unsigned char, int*);
extern "C" void fn_8039402C(int*, int, McHdrP*);
extern "C" void fn_80394170(int, int, int*);

extern "C" int fn_803925A8(unsigned);
extern "C" void fn_80392884(unsigned);

struct McCtxA {
    char pad0[0x90];
    unsigned char m90;
    unsigned char m91;
};

extern "C" int fn_8039387C(McHdr5*, McSrc*);
extern "C" int fn_8039305C(McSrc*, unsigned*, McRec12*);
extern "C" int fn_803933E8(McCtxA*, McHdr5*, McRec12*, McSrc*, unsigned*);

extern "C" int fn_80391914(McB*, int);

struct McHdr16 {
    char pad0[6];
    unsigned char m6;
    char pad7[5];
    unsigned short mC[1];
};

/* Object behind a channel record's +8 pointer (fn_80392884): flags byte at +0xA. */
struct McFlagsH {
    char pad0[0xA];
    unsigned char mA;
};

extern "C" void fn_803927E4(unsigned n)
{
    if (n <= 15) {
        char* t = (char*)lbl_8069B80C;
        int* pc = (int*)(t + 0x4c);
        int off = n * 16;
        int v = *(int*)((char*)pc + off);
        if (v != 0) {
            fn_80392BC0(v);
            *(int*)((char*)pc + off) = 0;
        }
        unsigned char* q = (unsigned char*)(t + off);
        q[0x46] = 0;
        int k = q[0x47];
        int* b = (int*)(t + 0x20);
        int k4 = k * 4;
        if (n == *(int*)((char*)b + k4))
            *(int*)((char*)b + k4) = -1;
        int c = *(int*)(t + k4) - 1;
        *(int*)(t + k4) = c;
        if (c < 0)
            *(int*)(t + k4) = 0;
    }
}

/* near-miss (48 of 49 words): the v load is `lwzx r0,r11,r26` here and `lwzx r0,r26,r11` in retail (operand order only);
 * registers and schedule match. About 450 spellings of the table accesses tried. */
extern "C" void fn_80392884(unsigned n)
{
    int off = n * 16;
    char* r = (char*)lbl_8069B80C + off;
    unsigned short h = *(unsigned short*)(r + 0x44);
    unsigned char tag = ((unsigned char*)r)[0x47];
    char* t40 = (char*)lbl_8069B80C + 0x40;
    unsigned v0 = *(unsigned*)(t40 + off);
    char* t48 = (char*)lbl_8069B80C + 0x48;
    for (int i = 0; i <= 15; i++) {
        int io = i * 16;
        char* e = (char*)lbl_8069B80C + io;
        if (i != n && e[0x46] != 0 && (unsigned char)e[0x47] == tag) {
            unsigned v = *(unsigned*)((char*)lbl_8069B80C + 0x40 + io);
            unsigned short hh = *(unsigned short*)(e + 0x44);
            if (v < v0 || (v == v0 && hh < h)) {
                if (!((*(McFlagsH**)((char*)t48 + io))->mA & 4))
                    fn_803927E4(i);
            }
        }
    }
}

extern "C" int fn_80392948(int* p)
{
    int (*f)(int*) = (int (*)(int*))lbl_8069B7C4[0];
    int r = 1;
    if (f != 0)
        r = f(p);
    return r;
}

extern "C" void fn_80392988(unsigned n)
{
    if (lbl_80624414 == 0) {
        lbl_80624414 = 1;
        if (n <= 7 && fn_80392098(n) != 0) {
            char* t = (char*)lbl_8069B80C;
            int* b = (int*)(t + 0x20);
            int id = *(int*)((char*)b + n * 4);
            fn_803943A8(n);
            int r = fn_80394C0C(id);
            fn_803927E4(id);
            if (r != 0)
                fn_80394650(n);
        }
    }
    lbl_80624414 = 0;
}

extern "C" int fn_80392A28(int n)
{
    int r = 0;
    if (lbl_80624414 == 0) {
        lbl_80624414 = 1;
        if (fn_80394638(n) != 0 || fn_80392AA4(n) != 0)
            r = fn_80394650(n);
    }
    lbl_80624414 = 0;
    return r;
}

extern "C" int fn_80392AA4(unsigned n)
{
    int r = 0;
    if (n <= 7 && lbl_8069B80C[n] != 0) {
        char* t = (char*)lbl_8069B80C;
        int* pc = (int*)(t + 0x4c);
        for (;;) {
            int idx = fn_803925A8(n);
            if (idx < 0)
                break;
            int sp = **(int**)((char*)pc + idx * 16);
            if (fn_80392948(&sp) == 1) {
                fn_803943A8(n);
                r = fn_80394C0C(idx);
                if (r == 0)
                    fn_803927E4(idx);
            } else {
                fn_803927E4(idx);
            }
            if (r != 0) {
                fn_80392884(idx);
                fn_803927E4(idx);
                break;
            }
        }
    }
    return r;
}

extern "C" void fn_80392B6C(int (*a)(), void (*b)())
{
    lbl_806243E0[0] = a;
    lbl_806243E4[0] = b;
}

extern "C" int fn_80392B80(int x)
{
    int (*f)(int) = (int (*)(int))lbl_806243E0[0];
    int r = 0;
    if (f != 0)
        r = f(x);
    return r;
}

extern "C" void fn_80392BC0(int v)
{
    if (lbl_806243E4[0] != 0)
        ((void (*)(int))lbl_806243E4[0])(v);
}

/* needs -fno-strength-reduce */
extern "C" void fn_80392BF4()
{
    for (int i = 0; i < 8; i++) {
        lbl_8069B94C[i].m0 = 0xFFFF;
        lbl_8069B94C[i].m4 = 0;
    }
}

extern "C" int fn_80392C28(int a, int b, int c)
{
    int x = a * b / 8;
    switch (c) {
    case 0:
        break;
    case 1:
        x = x / 10;
        break;
    case 2:
        x = x * 2 / 7;
        break;
    }
    return x;
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

extern "C" int fn_80392D08(int a, int b, int c)
{
    lbl_80624454[0] = 0x53;
    if (lbl_806243E0[0] != 0 && lbl_806243E4[0] != 0) {
        fn_80392CC0();
        lbl_8069B7B8.m0 = a;
        lbl_8069B98C[0] = b;
        lbl_8069B990[0] = c;
        lbl_80624408[0] = fn_8039223C;
        fn_80394F24(b);
        fn_8039445C();
        fn_80394CD4(0);
        for (int i = 0; i < 8; i++)
            lbl_8069B994[i] = 0;
        fn_80391E2C();
        fn_80392BF4();
        fn_803912F8();
        fn_80391EA4();
        lbl_806243F4[0] = 0x01789A34;
        return 1;
    }
    return 0;
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

extern "C" void fn_80392E50(McHdr5* p, McSrc* q, unsigned char* r)
{
    int* base = (int*)((char*)p + ((((p->m2 >> 2) + 3) & ~3) + 8)) + p->m4;
    int n = q->m4;
    for (int i = 0; i < n; i++) {
        McEnt8* qe = q->m8;
        McEnt8* e = &qe[i];
        if (e->m4 == 0xfe && (e->m6 & 0x80)) {
            base[e->m6 & 0x7f] |= 1 << r[i];
        }
    }
}

extern "C" int fn_80392ED8(McSrc* p)
{
    int r = 0;
    int n = p->m4;
    for (int i = 0; i < n; i++) {
        McEnt8* qe = p->m8;
        McEnt8* e = &qe[i];
        if (e->m4 == 0xfe) {
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_80392F2C(McHdr5* p, McSrcW* q, int* tab, unsigned char* codes)
{
    int r = 1;
    int n = q->m4;
    int i = 0;
    if (i < n) {
        do {
            unsigned c = codes[i];
            r = 0;
            if (c > 31)
                break;
            McEnt8W* qe = q->m8;
            McEnt8W* e = &qe[i];
            unsigned bit = 1 << c;
            unsigned e4 = e->m4;
            if (bit & e->m0) {
                if (e4 == 0 || e4 == 0xfe) {
                    r = 1;
                } else if (e4 == 0xff) {
                    unsigned b6 = e->m6;
                    if (b6 & 0x80) {
                        int* bits = (int*)((char*)p + ((((p->m2 >> 2) + 3) & ~3) + 8)) + p->m4;
                        if (bit & bits[b6 & 0x7f])
                            r = 1;
                    } else {
                        int sp = *tab;
                        unsigned char* out;
                        if (fn_80391DC4(&sp, &out) != 0 && c == out[b6])
                            r = 1;
                    }
                } else if (bit & tab[e4]) {
                    r = 1;
                }
            }
            if (r == 0)
                break;
            i++;
        } while (i < n);
    }
    return r;
}

extern "C" void fn_80393154(McHdr6* p, int n)
{
    int i = n / 8;
    int k = p->m4 & 0x7f;
    unsigned char* b = (unsigned char*)p + ((p->m5 * (k + 2) + 15) & ~3) + k * 4;
    int j = i + 1;
    unsigned char m = ~(1 << (n - i * 8));
    b[j] = b[j] & m;
}

extern "C" int fn_803931B4(unsigned char* bits, int n)
{
    int i = n / 8;
    unsigned char m = 1 << (n - i * 8);
    return bits[i] & m;
}

extern "C" int fn_803931EC(McA6* a, McB* b, int x)
{
    int r = 0;
    int s = a->m6;
    if (b->mA > s) {
        int c4 = b->m4;
        int c5 = b->m5;
        int idx = x + c5 * s;
        int k = c4 & 0x7f;
        unsigned char* p = (unsigned char*)b + ((c5 * (k + 2) + 15) & ~3) + k * 4;
        int off = 0;
        if (c4 & 0x80)
            off = ((c5 + 7) >> 3) + 1;
        p += off;
        if (b->m6)
            p += b->m6 + 1;
        r = fn_803931B4(p, idx);
    }
    return r;
}

extern "C" int fn_80393284(McA6* a, McB* b, int x)
{
    int r = 1;
    if (x > b->m5) {
        r = 0;
    } else if (a->m6 == -1 || (r = fn_803931EC(a, b, x)) != 0) {
        unsigned c4 = b->m4;
        if (c4 & 0x80) {
            int k = c4 & 0x7f;
            r = fn_803931B4((unsigned char*)b + ((b->m5 * (k + 2) + 15) & ~3) + k * 4 + 1, x);
        }
    }
    return r;
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

extern "C" int fn_8039335C(McSrc* p, McHdr6* q, int* tab)
{
    int r = 1;
    int k = q->m4 & 0x7f;
    int* bits = (int*)((char*)q + ((q->m5 * (k + 2) + 15) & ~3));
    for (int i = 0; i < k; i++) {
        McEnt8* qe = p->m8;
        McEnt8* e = &qe[i];
        if (e->m4 != 0 && e->m4 != 0xff && e->m4 != 0xfe && (bits[i] & tab[e->m4]) == 0) {
            r = 0;
            break;
        }
    }
    return r;
}

extern "C" int fn_803933E8(McCtxA* a, McHdr5* b, McRec12* rec, McSrc* g, unsigned* c)
{
    int has = fn_80392ED8(g);
    int cnt = 0;
    McB* tbl = (McB*)lbl_806243F8[0][rec->m4].m4;
    int best = 0;
    int bestIdx = -1;
    int n = tbl->m5;
    if (fn_8039335C(g, (McHdr6*)tbl, (int*)c) != 0) {
        int stride = (tbl->m4 & 0x7f) + 2;
        unsigned char* p = (unsigned char*)tbl + 0xe;
        int i = 0;
        if (cnt < n) {
            do {
                if (fn_80392F2C(b, (McSrcW*)g, (int*)c, p) != 0 && fn_80393284((McA6*)rec, tbl, i) != 0) {
                    int sc = fn_80391914(tbl, i);
                    if (sc > 0) {
                        if (sc > best) {
                            best = sc;
                            bestIdx = i;
                        }
                    } else {
                        if (((int (*)(McBuf*, int))fn_8039332C)((McBuf*)a, i) != 0)
                            cnt++;
                        if (has != 0)
                            fn_80392E50(b, g, p);
                    }
                }
                i++;
                p += stride;
            } while (i < n);
        }
        char* base = (char*)tbl + 0xc;
        if (cnt == 0 && bestIdx != -1) {
            if (((int (*)(McBuf*, int))fn_8039332C)((McBuf*)a, bestIdx) != 0)
                cnt = 1;
            if (has != 0) {
                p = (unsigned char*)(base + bestIdx * stride);
                fn_80392E50(b, g, p + 2);
            }
        }
    }
    return cnt;
}

extern "C" int fn_80393584(int x)
{
    int r = 0;
    if (lbl_8069B990[0] != 0)
        r = x * 100 / lbl_8069B990[0];
    return r;
}

extern "C" int fn_803935A8(McHdr5* p, McBufB* q)
{
    int sum = 0;
    int cnt = p->m2 >> 2;
    int i = 0;
    if (cnt != 0) {
        do {
            McRec12* e = (McRec12*)q + i;
            int a, b;
            unsigned char c = q->m92[e->mA];
            if (fn_803957A4(lbl_806243F8[0][e->m4].m4, c, &a, &b))
                sum += b;
            i++;
        } while (i < cnt);
    }
    fn_80393584(sum);
}

extern int lbl_80624418[];

extern "C" int fn_80393640(unsigned x)
{
    return (x & 0x1F) * lbl_80624418[(x >> 5) & 7];
}

/* near-miss: 2 slots, the index/base operand order of the first lhzx (idx,base in the original code). */
extern "C" void fn_8039365C(McHdr16* p, unsigned char* out)
{
    int w[256];

    int n = p->m6;
    if (n > 0xff)
        n = 0xff;
    int i = 0;
    int total = 0;
    if (i < n) {
        do {
            unsigned short* mc = p->mC;
            unsigned idx = mc[i] * 4;
            w[i] = fn_80393640(((unsigned char*)p)[idx]);
            i++;
            total += fn_80393640(((unsigned char*)p)[idx]);
        } while (i < n);
    }
    int pos = 0;
    while (total > 0) {
        int r = fn_80394FD4(total, -1);
        i = 0;
        while (i < n) {
            r -= w[i];
            if (r < 0)
                break;
            i++;
        }
        out[pos] = i;
        pos++;
        int v = w[i];
        w[i] = 0;
        total -= v;
    }
    i = 0;
    while (i < n) {
        unsigned short* mc = p->mC;
        if (fn_80393640(((unsigned char*)p)[mc[i] * 4]) == 0) {
            out[pos] = i;
            pos++;
        }
        i++;
    }
}

struct McSlotP {
    unsigned short m0;
    char pad2[6];
    unsigned char m8;
};

extern "C" int fn_8039379C(McSlotP* p, int i)
{
    int r = 1;
    if (p->m0 == lbl_8069B94C[i].m0) {
        int n = p->m8 & 0xf;
        if (n > 0)
            r = lbl_8069B94C[i].m4 < n;
    }
    return r;
}

extern "C" int fn_803937E4(unsigned char* p, int x)
{
    int r = 0;
    int t = p[2] & 3;
    if (t == 1 && x == 2) r = 1;
    else if (t == 2 && x != 2) r = 1;
    else if (t == 0) r = 1;
    return r;
}

extern "C" void fn_80393828(McHdr5* p)
{
    int* base = (int*)((char*)p + ((((p->m2 >> 2) + 3) & ~3) + 8)) + p->m4;
    for (int i = 0; i < p->m3; i++)
        base[i] = 0;
}

extern "C" int fn_80393AD0(McCtxA* a, McHdr5* b, unsigned* c, int d)
{
    int r = 1;
    int tries = 200;
    int all;
    unsigned n = b->m2 >> 2;
    if ((int)n > 12 || fn_803937E4((unsigned char*)b, d) == 0)
        goto fail;
    fn_80393828(b);
    a->m90 = n;
    do {
        all = 1;
        tries--;
        for (int i = 0; i < (int)n; i++) {
            unsigned char* ids = (unsigned char*)b + 8;
            McSrc* g = (McSrc*)((char*)b + ids[i] * 4);
            McRec12* rec = (McRec12*)a + i;
            if (fn_8039387C(b, g) == 0) {
                all = 0;
            } else if (rec->mB == 0) {
                rec->m8 = a->m91;
                if (fn_8039305C(g, c, rec) == 0)
                    goto fail;
                int v = fn_803933E8(a, b, rec, g, c);
                if (v == 0)
                    goto fail;
                rec->m9 = v;
                rec->mB = 1;
            }
        }
    } while (all == 0 && tries > 0);
    if (tries != 0)
        goto done;
fail:
    r = 0;
done:
    return r;
}

extern "C" void fn_80393C00(McHdr5* p, McBufB* q)
{
    int cnt = p->m2 >> 2;
    int i = 0;
    while (i < cnt) {
        McRec12* e = (McRec12*)q + i;
        int next = i + 1;
        unsigned char* a = q->m92 + e->m8;
        int k = e->m9;
        while (k > 1) {
            int j = fn_80394FD4(k, -1);
            unsigned char t = a[j];
            unsigned char u = a[k - 1];
            a[k - 1] = t;
            a[j] = u;
            k--;
        }
        i = next;
    }
}

extern "C" int fn_80393C98(McHdr5* p, McBufB* q)
{
    int r = 0;
    int done = 0;
    int i = (p->m2 >> 2) - 1;
    McRec12* rec = (McRec12*)q + i;
    int t9 = rec->m9;
    int lim = rec->m8 + t9;
    do {
        rec->mA = rec->mA + 1;
        if (rec->mA < lim) {
            done = 1;
        } else {
            rec->mA = rec->m8;
            i--;
            if (i < 0) {
                done = 1;
                r = 1;
            }
            rec = (McRec12*)q + i;
            t9 = rec->m9;
            lim = rec->m8 + t9;
        }
    } while (done == 0);
    return r;
}

extern "C" int fn_80393D18(McHdrP* a, McBufB* b, int x)
{
    int ok = 0;
    int wrapped = 0;
    int cnt = a->m2 >> 2;
    for (int i = 0; i < cnt; i++) {
        McRec12* e = (McRec12*)b + i;
        e->mA = e->m8;
    }
    while (wrapped == 0 && ok == 0) {
        ok = 1;
        if (x != 0)
            ok = fn_803935A8((McHdr5*)a, b) <= x;
        if (ok) {
            if (a->m3 != 0) {
                if (fn_80393918(b, a) == 0)
                    ok = 0;
            }
        }
        if (ok == 0)
            wrapped = fn_80393C98((McHdr5*)a, b);
    }
    return ok;
}

extern "C" int fn_80393E1C(McHdr7* p)
{
    p->mA = p->m8 + fn_80394FD4(p->m9, p->m4);
    return 1;
}

extern "C" void fn_80393E60(int* a, McBufB* b, McHdrP* c)
{
    unsigned char* out;
    if (fn_80391DC4(a, &out) != 0) {
        int n = c->m2 >> 2;
        for (int i = 0; i < n; i++) {
            unsigned char* ids = (unsigned char*)c + 8;
            McSrc* g = (McSrc*)((char*)c + ids[i] * 4);
            for (int j = 0; j < g->m4; j++) {
                McEnt8* ge = g->m8;
                McEnt8* e = &ge[j];
                if (e->m4 == 0xfe && !(e->m6 & 0x80)) {
                    McRec12* rec = (McRec12*)b + i;
                    char* t = fn_80395774(lbl_806243F8[0][rec->m4].m4, b->m92[rec->mA]);
                    if (t != 0)
                        out[e->m6] = t[j];
                }
            }
        }
    }
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

/* near-miss (48 of 50 words): d is kept in r29 here and r31 in retail (the `mr.` and the `mr r5` differ in the register only);
 * `int r = d;` lowers the result variable priority, other spellings left r in the wrong register. */
extern "C" int fn_80393F64(int* a, McBufB* b, McHdrP* c, int unused, int d)
{
    int r = d;
    if (d > 0 || c->m3 != 0) {
        fn_80393C00((McHdr5*)c, b);
        r = fn_80393D18(c, b, d);
        goto join;
    }
    goto start;
fail:
    r = 0;
    goto out;
start:
    {
        int i = 0;
        r = 1;
        int n = c->m2 >> 2;
        for (; i < n; i++) {
            McHdr7* e = (McHdr7*)b + i;
            if (e->m9 == 0 || fn_80393E1C(e) == 0)
                goto fail;
        }
    }
join:
    fn_80393E60(a, b, c);
out:
    return r;
}

extern "C" void fn_8039437C(McTable* p)
{
    p->m91 = 0;
    p->m90 = 0;
    for (int i = 0; i < 12; i++) {
        McRow12* r = (McRow12*)((char*)p + i * 12);
        r->mB = 0;
    }
}

extern "C" void fn_803943A8(unsigned n)
{
    char* t = (char*)lbl_8069B9C0;
    int off = n * 160;
    int* c12 = (int*)(t + 0xc);
    int v = *(int*)((char*)c12 + off);
    if (v != 0) {
        fn_80392BC0(v);
        *(int*)((char*)c12 + off) = 0;
    }
    int* c4 = (int*)(t + 4);
    *(int*)((char*)c4 + off) = 0;
    unsigned char* row = (unsigned char*)(t + off);
    *(int*)(t + off) = 0;
    row[8] = 0;
    row[9] = 0;
    row[10] = 0;
    row[11] = 0;
    *(int*)((char*)c12 + off) = 0;
    int j = 0;
    do {
        char* tt = (char*)lbl_8069B9C0;
        int o = j * 12 + n * 160;
        int* c10 = (int*)(tt + 0x10);
        *(int*)((char*)c10 + o) = -1;
        unsigned char* q = (unsigned char*)(tt + o);
        *(short*)(q + 0x14) = -1;
        *(short*)(q + 0x16) = -1;
        *(short*)(q + 0x18) = 0;
        j++;
    } while (j <= 11);
}

extern "C" void fn_8039445C()
{
    int i = 0;
    do {
        int next = i + 1;
        char* t = (char*)lbl_8069B9C0;
        int off = i * 160;
        *(int*)(t + off) = 0;
        int* c4 = (int*)(t + 4);
        *(int*)((char*)c4 + off) = 0;
        unsigned char* row = (unsigned char*)(t + off);
        row[8] = 0;
        row[9] = 0;
        row[10] = 0;
        row[11] = 0;
        int* c12 = (int*)(t + 12);
        *(int*)((char*)c12 + off) = 0;
        int j = 0;
        do {
            char* tt = (char*)lbl_8069B9C0;
            int o = j * 12 + i * 160;
            int* c10 = (int*)(tt + 0x10);
            *(int*)((char*)c10 + o) = -1;
            unsigned char* q = (unsigned char*)(tt + o);
            *(short*)(q + 0x14) = -1;
            *(short*)(q + 0x16) = -1;
            *(short*)(q + 0x18) = 0;
            j++;
        } while (j <= 11);
        i = next;
    } while (i <= 7);
}

extern "C" int fn_80394638(int i)
{
    McRow160* r = (McRow160*)(i * 0xA0 + (int)lbl_8069B9C0);
    return r->m9;
}

extern "C" int fn_80394650(unsigned n)
{
    int r = 0;
    if (n <= 7 && fn_80394638(n) != 0) {
        char* t = (char*)lbl_8069B9C0;
        int off = n * 160;
        int* c = (int*)(t + 0xc);
        int* p = *(int**)((char*)c + off);
        int sp = *p;
        int* c4 = (int*)(t + 4);
        fn_8039539C(&sp, *(int*)(t + off), ((unsigned char*)(t + off))[8], p);
        fn_8039402C(&sp, *(int*)(t + off), *(McHdrP**)((char*)c4 + off));
        fn_80394170(*(int*)(t + off), *(int*)((char*)c4 + off), &sp);
        r = (*(McHdr5**)((char*)c4 + off))->m2 >> 2;
        char* s = (char*)lbl_8069B94C;
        int so = n * 8;
        int v;
        int* s4;
        if (((McSp*)&sp)->a == *(unsigned short*)(s + so)) {
            s4 = (int*)(s + 4);
            v = *(int*)((char*)s4 + so) + 1;
        } else {
            s4 = (int*)(s + 4);
            ((int*)s)[n * 2] = sp;
            v = 1;
        }
        *(int*)((char*)s4 + so) = v;
    }
    fn_803943A8(n);
    return r;
}
