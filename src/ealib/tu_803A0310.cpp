/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803A0310-0x803A4214 (code-only unit, 39 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
#include "../../include/game/tu_803959E0.h"

struct Vp6Mul {
    int mul;
    int add;
};
extern const Vp6Mul lbl_8060918C[];

/* Output frame descriptor passed to the macroblock copy functions (fn_803A0884 / fn_803A0AF4). */
struct Vp6Out {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[8];
    unsigned char* m18;
    unsigned char* m1C;
    unsigned char* m20;
};

/* Decoder fields used by fn_803A0C9C (offsets inside the frame buffer set). */
struct Vp6BufView {
    char pad0[8];
    int m8;
    char pad0C[0x40 - 0xC];
    unsigned m40;
    unsigned m44;
    char pad48[0x68 - 0x48];
    unsigned m68;
    char pad6C[4];
    unsigned m70;
    unsigned m74;
    int m78;
    int m7C;
    int m80;
    char pad84[0x98 - 0x84];
    int m98;
    int m9C;
};

typedef void (*Vp6Fn5)(int, int, int, int, int);
typedef void (*Vp6Fn4)(int, int, int, int);
typedef void (*Vp6Fn3)(int, int, int);
extern Vp6Fn5 lbl_806EF418;
extern Vp6Fn4 lbl_806EF428;
extern Vp6Fn4 lbl_806EF414;
extern const int lbl_80624494[];

/* Decoder context fields used by fn_803A30D0 (not part of Vp6Ctx yet). */
struct Vp6McView {
    char pad0[8];
    int m8;
    char padC[0x70 - 0xC];
    int m70;
    int m74;
    char pad78[0x244 - 0x78];
    int m244;
    char pad248[0x24C - 0x248];
    int m24C;
    char pad250[4];
    int m254;
    char pad258[0x270 - 0x258];
    int m270;
    char pad274[0x284 - 0x274];
    int m284;
};

/* Scaler descriptor: source and destination width/height pairs at +0x58..+0x64 (fn_803A0604). */
struct Vp6ScView {
    char pad0[0x58];
    int m58;
    int m5C;
    int m60;
    int m64;
};
extern Vp6Fn3 lbl_806EF3B0;
extern Vp6Fn3 lbl_806EF3B4;
extern Vp6Fn3 lbl_806EF3B8;
extern Vp6Fn3 lbl_806EF3BC;
extern Vp6Fn4 lbl_806EF3C0;
extern Vp6Fn4 lbl_806EF3C4;
extern Vp6Fn4 lbl_806EF3C8;
extern Vp6Fn3 lbl_806EF3CC;
extern Vp6Fn3 lbl_806EF3D0;

/* Decoder fields used by the motion vector reader fn_803A2A44 (not part of Vp6Ctx yet). */
struct Vp6MvView {
    char pad0[0x3C];
    short m3C;
    short m3E;
    char pad40[4];
    int m44;
    short m48;
    short m4A;
    char pad4C[4];
    int m50;
    char pad54[0x150 - 0x54];
    Vp6Rc m150;
    char pad168[0x704 - 0x168];
    unsigned char m704[2];
    unsigned char m706[2];
    unsigned char m708[14];
    char pad716[6];
    unsigned char m71C[16];
};
/* Macroblock decode context fields used by fn_803A2244 (offsets read from the original code). */
struct Vp6MbView {
    char pad0[8];
    int m8;
    char pad0C[0x64 - 0xC];
    int m64;
    int m68;
    char pad6C[4];
    int m70;
    int m74;
    int m78;
    int m7C;
    int m80;
    char pad84[4];
    int m88;
    char pad8C[0xBC - 0x8C];
    int mBC;
    void* mC0;
    void* mC4;
    int mC8;
    char padCC[0x10C - 0xCC];
    int m10C;
    int m110;
    int m114;
    char pad118[0x150 - 0x118];
    Vp6Rc m150;
    char pad168[0x1AC - 0x168];
    unsigned char m1AC;
    char pad1AD[0xB];
    int m1B8;
    int m1BC;
    char pad1C0[0x1DC - 0x1C0];
    int m1DC;
    char pad1E0[0x21C - 0x1E0];
    int m21C;
    int m220;
    int m224;
    char pad228[0x6EB - 0x228];
    unsigned char m6EB;
};
extern "C" {

void fn_803A00A0(int, int, int, int);
void fn_803A00D8(int, int, int);
void fn_803A0FCC(Vp6MbView* c, int mbx, unsigned mby, int blk);
void fn_803A26D4(Vp6MbView* c, int mbx, unsigned mby);

void fn_803A2DEC(Vp6McView* c, int dst, int mode);

void fn_8039868C(Vp6BufView* b, unsigned char* base);
void fn_803A0884(Vp6BufView* b, unsigned char* base, Vp6Out* r, int a, int c);

int fn_803A0EBC(Vp6Rc* rc);
int fn_803A0E18(Vp6Rc* rc, unsigned prob);

extern const int lbl_8062501C[];
extern const int lbl_80624F9C[];
void fn_803A3D84(const unsigned char* src, short* dst, int stride, int rows, const int* taps);
void fn_803A3E08(const unsigned char* src, short* dst, int stride, const int* tapsA, const int* tapsB);
void fn_80397CD0(const unsigned char* src, short* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps);
void fn_80397F98(const unsigned char* src, short* dst, int stride, const int* tapsA, const int* tapsB);

struct Vp6McView2 {
    char pad0[0x74];
    int m74;
    char pad78[4];
    int m7C;
    char pad80[8];
    int m88;
    char pad8C[0x13C - 0x8C];
    Vp6Tbl* m13C;
    char pad140[0x290 - 0x140];
    int m290;
};

extern Vp6Fn3 lbl_806EF3A4;
extern Vp6Fn3 lbl_806EF3A0;
extern Vp6Fn4 lbl_806EF43C;

/* near-miss: same weights as fn_803A00DC; load and multiply scheduling differ (72 vs 62 insns). */
void fn_803A0310(const unsigned char* src, unsigned n, unsigned char* dst)
{
    unsigned i;
    n -= 3;
    for (i = 0; i < n; i += 3) {
        dst[0] = src[0];
        dst[1] = (src[0] * 0x66U + src[1] * 0x9AU + 0x80) >> 8;
        dst[2] = (src[1] * 0xCDU + src[2] * 0x33U + 0x80) >> 8;
        dst[4] = (src[2] * 0x9AU + src[3] * 0x66U + 0x80) >> 8;
        dst[3] = (src[1] * 0x33U + src[2] * 0xCDU + 0x80) >> 8;
        src += 3;
        dst += 5;
    }
    dst[0] = src[0];
    dst[1] = (src[0] * 0x66U + src[1] * 0x9AU + 0x80) >> 8;
    dst[2] = (src[1] * 0xCDU + src[2] * 0x33U + 0x80) >> 8;
    dst[3] = (src[1] * 0x33U + src[2] * 0xCDU + 0x80) >> 8;
    dst[4] = src[2];
}

/* near-miss: 4 slots, order of the first two loads and multiplies. */
void fn_803A0408(unsigned char* p, int s, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        unsigned p0 = p[0];
        unsigned p1 = p[s];
        p[s] = (p0 * 0x66U + p1 * 0x9AU + 0x80) >> 8;
        unsigned p2 = p[2 * s];
        p[2 * s] = (p1 * 0xCDU + p2 * 0x33U + 0x80) >> 8;
        p[3 * s] = (p1 * 0x33U + p2 * 0xCDU + 0x80) >> 8;
        unsigned p5 = p[5 * s];
        p[4 * s] = (p2 * 0x9AU + p5 * 0x66U + 0x80) >> 8;
        p++;
    }
}

void fn_803A04BC(unsigned char* p, int s, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        unsigned p0 = p[0];
        unsigned p1 = p[s];
        p[s] = (p0 * 0x66U + p1 * 0x9AU + 0x80) >> 8;
        unsigned p2 = p[2 * s];
        p[2 * s] = (p1 * 0xCDU + p2 * 0x33U + 0x80) >> 8;
        p[3 * s] = (p1 * 0x33U + p2 * 0xCDU + 0x80) >> 8;
        p[4 * s] = p2;
        p++;
    }
}

/* near-miss: 1 slot (add operand order) */
void fn_803A0554(const unsigned char* src, unsigned n, unsigned char* dst)
{
    unsigned i;
    n--;
    for (i = 0; i < n; i++) {
        unsigned a = src[0];
        src++;
        unsigned b = src[0];
        dst[0] = a;
        dst[1] = (b + a + 1) >> 1;
        dst += 2;
    }
    unsigned c = src[0];
    dst[0] = c;
    dst[1] = c;
}

void fn_803A05A0(unsigned char* p, int stride, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        p[stride] = (p[0] + p[2 * stride] + 1U) >> 1;
        p++;
    }
}

void fn_803A05DC(unsigned char* p, int stride, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        p[stride] = p[0];
        p++;
    }
}

//// a
//// a
int fn_803A0604(Vp6ScView* c, int a1, int a2, int a3, int unused, int a5, int a6, int a7, unsigned a8)
{
    unsigned n1 = 0;
    unsigned n2 = 0;
    int ok = 1;
    Vp6Fn4 fa = 0;
    Vp6Fn3 fb = 0;
    Vp6Fn3 fc = 0;
    unsigned k;
    unsigned m;
    int dh = c->m64;
    int dd = c->m60;
    switch (c->m5C * 10 / c->m58) {
    case 8:
        fa = lbl_806EF3C8;
        break;
    case 6:
        fa = lbl_806EF3C4;
        break;
    case 5:
        fa = lbl_806EF3C0;
        break;
    case 10:
        fa = (Vp6Fn4)fn_803A00A0;
        break;
    default:
        ok = 0;
        break;
    }
    switch (dh * 10 / dd) {
    case 8:
        fb = lbl_806EF3B0;
        n1 = 4;
        fc = lbl_806EF3B4;
        n2 = 5;
        break;
    case 6:
        fb = lbl_806EF3B8;
        n1 = 3;
        fc = lbl_806EF3BC;
        n2 = 5;
        break;
    case 5:
        fb = lbl_806EF3CC;
        n1 = 1;
        fc = lbl_806EF3D0;
        n2 = 2;
        break;
    case 10:
        n1 = 4;
        fc = (Vp6Fn3)fn_803A00D8;
        n2 = 4;
        fb = fc;
        break;
    default:
        ok = 0;
        break;
    }
    if (!ok) {
        return ok;
    }
    {
        fa(a1, a3, a5, a7);
        for (k = 0; k < (a8 + n2 - 1) / n2 - 1; k++) {
            for (m = 1; m < n1; m++) {
                fa(a1 + a2 * m, a3, a5 + a6 * m, a7);
            }
            int na = a1 + n1 * a2;
            int nd = a5 + n2 * a6;
            fa(na, a3, nd, a7);
            a1 = na;
            fb(a5, a6, a7);
            a5 = nd;
        }
        for (m = 1; m < n1; m++) {
            fa(a1 + a2 * m, a3, a5 + a6 * m, a7);
        }
        fc(a5, a6, a7);
    }
    return ok;
}

void fn_803A0AF4(Vp6BufView* b, unsigned char* base, Vp6Out* r)
{
    unsigned i;
    unsigned hh = (r->m4 - b->m44) >> 1;
    unsigned ww = (r->m0 - b->m40) >> 1;
    unsigned char* dst = base + b->m78;
    unsigned char* src = r->m18 + hh * r->m0 + ww;
    for (i = 0; i < b->m44; i++) {
        MEMCPY_V(src, dst, b->m40);
        src += r->m0;
        dst += b->m98;
    }
    src = r->m1C + ((int)hh / 2) * r->mC + ((int)ww / 2);
    dst = base + b->m7C;
    for (i = 0; i < (b->m44 >> 1); i++) {
        MEMCPY_V(src, dst, b->m40 >> 1);
        src += r->mC;
        dst += b->m9C;
    }
    src = r->m20 + ((int)hh / 2) * r->mC + ((int)ww / 2);
    dst = base + b->m80;
    for (i = 0; i < (b->m44 >> 1); i++) {
        MEMCPY_V(src, dst, b->m40 >> 1);
        src += r->mC;
        dst += b->m9C;
    }
}

void fn_803A0C9C(Vp6BufView* b, unsigned char* base, Vp6Out* r)
{
    if (b->m8 != 0) {
        fn_8039868C(b, base);
    }
    switch (b->m68) {
    case 0:
    case 1: {
        unsigned t = (r->m4 - b->m74) >> 1;
        unsigned u = (r->m0 - b->m70) >> 1;
        fn_803A0884(b, base, r, t * r->m0 + u, ((int)t >> 1) * r->mC + ((int)u >> 1));
        break;
    }
    case 2:
        fn_803A0AF4(b, base, r);
        break;
    }
}

void fn_803A0D54(Vp6Ctx* c)
{
    const unsigned char* in = reinterpret_cast<unsigned char*>(c) + 0x3A0;
    unsigned char* out = reinterpret_cast<unsigned char*>(c) + 0x542;
    unsigned i;
    unsigned j;
    int k;
    int lo = 1;
    for (i = 0; i <= 1; i++) {
        for (j = 0; j <= 2; j++) {
            for (k = 0; k < 5; k++) {
                int v = (in[i * 11 + k] * lbl_8060918C[k * 3 + j].mul + 0x80) >> 8;
                v += lbl_8060918C[k * 3 + j].add;
                if (v > 255) v = 255;
                if (v < lo) v = lo;
                out[i * 15 + j * 5 + k] = v;
            }
        }
    }
}

/* near-miss: 41 insns like the original code; range/value swap r7/r8 (the original keeps range in r8). */
int fn_803A0E18(Vp6Rc* rc, unsigned prob)
{
    unsigned range = rc->m4;
    int bit = 0;
    unsigned value = rc->m8;
    int count = rc->mC;
    unsigned split = (((range - 1) * prob) >> 8) + 1;
    unsigned big = split << 24;
    if (value >= big) {
        range = rc->m4 - split;
        value -= big;
        bit = 1;
    } else {
        range = split;
    }
    if (range > 127) {
        rc->m4 = range;
        rc->m8 = value;
        return bit;
    }
    do {
        range <<= 1;
        value <<= 1;
        count--;
        if (count == 0) {
            value |= rc->m14[rc->m10];
            rc->m10++;
            count = 8;
        }
    } while (range < 128);
    rc->m4 = range;
    rc->mC = count;
    rc->m8 = value;
    return bit;
}

int fn_803A0EBC(Vp6Rc* rc)
{
    unsigned range = rc->m4;
    unsigned value = rc->m8;
    int count = rc->mC;
    unsigned split = (range + 1) >> 1;
    unsigned big = split << 24;
    int bit;
    if (value >= big) {
        range = (range - split) << 1;
        value = (value - big) << 1;
        bit = 1;
    } else {
        range = split << 1;
        value <<= 1;
        bit = 0;
    }
    count--;
    if (count == 0) {
        value |= rc->m14[rc->m10];
        rc->m10++;
        count = 8;
    }
    rc->mC = count;
    rc->m8 = value;
    rc->m4 = range;
    return bit;
}

/* near-miss: 37 insns like the original code; range and value swap r7/r8. */
int fn_803A0F38(Vp6Rc* rc, unsigned prob)
{
    unsigned range = rc->m4;
    int bit = 0;
    int count = rc->mC;
    unsigned value = rc->m8;
    unsigned split = (((range - 1) * prob) >> 8) + 1;
    unsigned big = split << 24;
    if (value >= big) {
        range -= split;
        value -= big;
        bit = 1;
    } else {
        range = split;
    }
    while (range < 128) {
        range <<= 1;
        value <<= 1;
        count--;
        if (count == 0) {
            value |= rc->m14[rc->m10];
            rc->m10++;
            count = 8;
        }
    }
    rc->m4 = range;
    rc->mC = count;
    rc->m8 = value;
    return bit;
}

//// a
/* near-miss 96.5%: same instructions; about 28 slots differ in the order of the independent field stores and the t8/t10 registers. */
void fn_803A2244(Vp6MbView* c, int mbx, unsigned mby)
{
    int step;
    int v;
    if (c->m1DC != 0) {
        unsigned char p = c->m6EB;
        if (mby > 3) {
            if (c->mC8 != 0) {
                p = p - (p >> 1);
            } else {
                p = p + ((0x100 - p) >> 1);
            }
        }
        c->mC8 = fn_803A0F38(&c->m150, p);
    } else {
        c->mC8 = 0;
    }
    if (c->m1AC == 0) {
        c->m8 = 1;
    } else {
        fn_803A26D4(c, mbx, mby);
    }
    if (c->mC8 == 0) {
        c->m74 = c->m1B8;
        step = 8;
    } else {
        step = 1;
        c->m74 = c->m1B8 * 2;
    }
    int t10 = c->m1B8;
    int t8 = mbx * 16;
    int t27 = mby * 16;
    int t29 = mby << 5;
    c->m68 = t27;
    void* t28 = (char*)c + 0xCC;
    int t30 = c->m21C + t8 * t10 + t27;
    c->m70 = t30;
    c->mC0 = t28;
    c->m7C = 2;
    c->m80 = 3;
    c->m64 = t8;
    int t25 = t29 + 16;
    c->m88 = t10;
    void* t26 = (char*)c + 0xDC;
    c->mC4 = (char*)c + 0x124;
    c->m78 = 0;
    c->mBC = c->m10C + t29;
    fn_803A0FCC(c, mbx, mby, 0);
    c->mC0 = t28;
    c->m70 = c->m70 + 8;
    c->mBC = c->m10C + t25;
    c->m68 = c->m68 + 8;
    fn_803A0FCC(c, mbx, mby, 1);
    c->mC0 = t26;
    c->m68 = c->m68 - 8;
    c->mBC = c->m10C + t29;
    c->m70 = t30 + step * c->m1B8;
    c->m64 = c->m64 + step;
    fn_803A0FCC(c, mbx, mby, 2);
    c->mC0 = t26;
    c->m70 = c->m70 + 8;
    c->mBC = c->m10C + t25;
    c->m68 = c->m68 + 8;
    fn_803A0FCC(c, mbx, mby, 3);
    int u10 = c->m1BC;
    int u28 = mbx * 8;
    int u29 = mby * 8;
    int u8 = u28 * u10;
    c->m7C = 3;
    int u9 = c->m110 + t27;
    c->mC4 = (char*)c + 0x12C;
    void* u7 = (char*)c + 0xEC;
    c->m80 = 7;
    c->m70 = c->m220 + u8 + u29;
    c->mBC = u9;
    c->mC0 = u7;
    c->m88 = u10;
    c->m78 = 1;
    c->m74 = u10;
    c->m64 = u28;
    c->m68 = u29;
    fn_803A0FCC(c, mbx, mby, 4);
    void* w8 = (char*)c + 0xFC;
    void* w7 = (char*)c + 0x134;
    int w10 = c->m68;
    c->m78 = 2;
    c->mBC = c->m114 + t27;
    c->mC0 = w8;
    int w9 = c->m224 + c->m64 * c->m74 + w10;
    c->mC4 = w7;
    c->m70 = w9;
    fn_803A0FCC(c, mbx, mby, 5);
}

int fn_803A2524(Vp6Ctx* c)
{
    Vp6Rc* rc = &c->m150;
    int v = fn_803A0EBC(rc) * 2;
    v += fn_803A0EBC(rc);
    switch (v) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 4;
    }
    return 0;
}

int fn_803A25A8(Vp6Ctx* c, int a, int b)
{
    Vp6Rc* rc = &c->m150;
    int r = a;
    const unsigned char* t = reinterpret_cast<unsigned char*>(c) + 0x77C;
    int idx = b * 10;
    if (fn_803A0E18(rc, t[a + idx]) == 0) {
        const unsigned char* p = reinterpret_cast<unsigned char*>(c) + (b * 0x5A + 0x7A4) + a * 9;
        if (fn_803A0E18(rc, p[0])) {
            if (fn_803A0E18(rc, p[2])) {
                if (fn_803A0E18(rc, p[6])) {
                    r = fn_803A0E18(rc, p[8]) + 8;
                } else {
                    r = fn_803A0E18(rc, p[7]) + 5;
                }
            } else {
                r = 1;
                if (fn_803A0E18(rc, p[5])) {
                    r = 7;
                }
            }
        } else {
            if (fn_803A0E18(rc, p[1])) {
                r = fn_803A0E18(rc, p[4]) + 3;
            } else {
                r = fn_803A0E18(rc, p[3]) << 1;
            }
        }
    }
    return r;
}

//// a
static inline unsigned char Vp6Rd(Vp6MvView* c, int k, int idx)
{
    unsigned char* b = (unsigned char*)c + k;
    return b[idx];
}

/* near-miss 99.1%: 4 slots differ; the final v + py / v + px adds take their operands in the other order, and one loop-invariant addi sits one slot earlier. */
void fn_803A2A44(Vp6MvView* c, short* out, int mode)
{
    int v;
    short px = 0;
    short py = 0;
    unsigned i;
    int j;
    int k;
    Vp6Rc* rc;
    if (mode == 2) {
        if (c->m44 <= 1) {
            px = c->m3C;
            py = c->m3E;
        }
    } else if (c->m50 <= 1) {
        px = c->m48;
        py = c->m4A;
    }
    i = 0;
    rc = &c->m150;
    j = 0;
    k = 0;
    do {
        if (!fn_803A0E18(rc, Vp6Rd(c, 0x706, i))) {
            if (fn_803A0E18(rc, Vp6Rd(c, 0x708, j))) {
                if (fn_803A0E18(rc, Vp6Rd(c, 0x70C, j))) {
                    v = fn_803A0E18(rc, Vp6Rd(c, 0x70E, j)) + 6;
                } else {
                    v = fn_803A0E18(rc, Vp6Rd(c, 0x70D, j)) + 4;
                }
            } else if (fn_803A0E18(rc, Vp6Rd(c, 0x709, j))) {
                v = fn_803A0E18(rc, Vp6Rd(c, 0x70B, j)) + 2;
            } else {
                v = fn_803A0E18(rc, Vp6Rd(c, 0x70A, j));
            }
        } else {
            v = fn_803A0E18(rc, Vp6Rd(c, 0x71C, k));
            v += fn_803A0E18(rc, Vp6Rd(c, 0x71D, k)) * 2;
            v += fn_803A0E18(rc, Vp6Rd(c, 0x71E, k)) * 4;
            v += fn_803A0E18(rc, Vp6Rd(c, 0x723, k)) << 7;
            v += fn_803A0E18(rc, Vp6Rd(c, 0x722, k)) << 6;
            v += fn_803A0E18(rc, Vp6Rd(c, 0x721, k)) << 5;
            v += fn_803A0E18(rc, Vp6Rd(c, 0x720, k)) * 16;
            if (v & 0xF0) {
                v += fn_803A0E18(rc, Vp6Rd(c, 0x71F, k)) * 8;
            } else {
                v += 8;
            }
        }
        if (v != 0 && fn_803A0E18(rc, Vp6Rd(c, 0x704, i))) {
            v = -v;
        }
        if (i != 0) {
            out[1] = py + v;
        } else {
            out[0] = px + v;
        }
        i++;
        k += 8;
        j += 7;
    } while (i <= 1);
}

void fn_803A30D0(Vp6McView* c, int mode)
{
    int m = c->m8;
    if (m == 0) {
        lbl_806EF418(c->m284, c->m244 + c->m70, c->m254 + c->m70, c->m270, c->m74);
    } else if (lbl_80624494[m] != 0) {
        fn_803A2DEC(c, c->m284, mode);
        lbl_806EF428(c->m284, c->m270, c->m244 + c->m70, c->m74);
    } else if (m == 5) {
        lbl_806EF418(c->m284, c->m244 + c->m70, c->m24C + c->m70, c->m270, c->m74);
    } else {
        lbl_806EF414(c->m284, c->m244 + c->m70, c->m270, c->m74);
    }
}

void fn_803A3D0C(const short* a, const short* b, short* out)
{
    int dc = (a[0] * b[0] + 15) >> 5;
    unsigned packed = dc;
    packed = (packed & 0xFFFF) | ((packed << 16) & 0xFFFF0000);
    for (int i = 0; i < 8; i++) {
        int* o = reinterpret_cast<int*>(out);
        o[0] = packed;
        o[1] = packed;
        o[2] = packed;
        o[3] = packed;
        out += 8;
    }
}

void fn_803A3F0C(const unsigned char* a, const unsigned char* b, short* dst, int stride, int i, int j, int flag)
{
    int d = b - a;
    if (d < 0) {
        const unsigned char* t = a;
        a = b;
        d = t - a;
    }
    if (flag == 0) {
        if (d == 1) {
            fn_803A3D84(a, dst, stride, 1, lbl_8062501C + i * 2);
            return;
        }
        if (d == stride) {
            fn_803A3D84(a, dst, stride, stride, lbl_8062501C + j * 2);
            return;
        }
        if (d == stride - 1)
            fn_803A3E08(a - 1, dst, stride, lbl_8062501C + i * 2, lbl_8062501C + j * 2);
        else
            fn_803A3E08(a, dst, stride, lbl_8062501C + i * 2, lbl_8062501C + j * 2);
        return;
    }
    if (d == 1) {
        fn_80397CD0(a, dst, stride, 1, 8, 8, lbl_80624F9C + i * 4);
        return;
    }
    if (d == stride) {
        fn_80397CD0(a, dst, stride, stride, 8, 8, lbl_80624F9C + j * 4);
        return;
    }
    if (d == stride - 1)
        fn_80397F98(a - 1, dst, stride, lbl_80624F9C + i * 4, lbl_80624F9C + j * 4);
    else
        fn_80397F98(a, dst, stride, lbl_80624F9C + i * 4, lbl_80624F9C + j * 4);
}

unsigned fn_803A4094(const unsigned char* p, int stride)
{
    unsigned sum = 0;
    unsigned sq = 0;
    int i;
    stride *= 2;
    for (i = 0; i < 4; i++) {
        unsigned a = p[0];
        unsigned b = p[2];
        unsigned c = p[4];
        unsigned d = p[6];
        sum += a;
        sum += b;
        sum += c;
        sum += d;
        sq += a * a;
        sq += b * b;
        sq += c * c;
        sq += d * d;
        p += stride;
    }
    return (sq * 16 - sum * sum) >> 8;
}

void fn_803A4104(Vp6McView2* c, int base, int a, int b)
{
    int p = c->m290;
    int x, y;
    if (a > 0)
        x = a >> c->m7C;
    else
        x = -(-a >> c->m7C);
    if (b > 0)
        y = b >> c->m7C;
    else
        y = -(-b >> c->m7C);
    int d = c->m88 * y + x - c->m74 * 2 - 2;
    lbl_806EF43C(base + d, p, c->m74, 16);
    int rx = (8 - (x & 7)) & 7;
    int ry = (8 - (y & 7)) & 7;
    if (rx != 0) {
        int o1 = rx + 2;
        lbl_806EF3A4(c->m13C->m0, p + o1, 16);
    }
    if (ry != 0) {
        Vp6Tbl* tb = c->m13C;
        int o2 = ry * 16 + 0x20;
        lbl_806EF3A0(tb->m0, p + o2, 16);
    }
}

}
