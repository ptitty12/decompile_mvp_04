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
    char padB;
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
extern "C" int fn_80394650(int);
extern "C" int fn_80392AA4(int);
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
extern "C" void fn_80393E60(int, McBufB*, McHdrP*);

extern "C" void fn_803927E4(unsigned);

extern "C" void fn_80392BC0();

extern "C" void fn_803927E4(unsigned n)
{
    if (n <= 15) {
        char* t = (char*)lbl_8069B80C;
        int* pc = (int*)(t + 0x4c);
        int off = n * 16;
        int v = *(int*)((char*)pc + off);
        if (v != 0) {
            ((void (*)(int))fn_80392BC0)(v);
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

/* near-miss: retail keeps the result in r9 (mr r9,r3 / mr r3,r9) and sets it before the call; 6 spellings tried. */
extern "C" int fn_80392948()
{
    int (*f)() = lbl_8069B7C4[0];
    int r = 1;
    if (f != 0)
        r = f();
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

extern "C" void fn_80393154(McHdr6* p, int n)
{
    int i = n / 8;
    int k = p->m4 & 0x7f;
    unsigned char* b = (unsigned char*)p + ((p->m5 * (k + 2) + 15) & ~3) + k * 4;
    int j = i + 1;
    unsigned char m = ~(1 << (n - i * 8));
    b[j] = b[j] & m;
}

/* near-miss: retail masks the shifted bit with clrlwi 24 before the and; ours folds it away. */
extern "C" int fn_803931B4(unsigned char* bits, int n)
{
    int i = n / 8;
    return bits[i] & (unsigned char)(1 << (n - i * 8));
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

extern "C" int fn_80393584(int x)
{
    int r = 0;
    if (lbl_8069B990[0] != 0)
        r = x * 100 / lbl_8069B990[0];
    return r;
}

extern "C" void fn_803935A8(McHdr5* p, McBufB* q)
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

extern "C" int fn_80393E1C(McHdr7* p)
{
    p->mA = p->m8 + fn_80394FD4(p->m9, p->m4);
    return 1;
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

extern "C" int fn_80394638(int i)
{
    McRow160* r = (McRow160*)(i * 0xA0 + (int)lbl_8069B9C0);
    return r->m9;
}
