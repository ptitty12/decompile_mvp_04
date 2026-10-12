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

extern "C" {

void fn_803A2DEC(Vp6McView* c, int dst, int mode);

void fn_8039868C(Vp6BufView* b, unsigned char* base);
void fn_803A0884(Vp6BufView* b, unsigned char* base, Vp6Out* r, int a, int c);

int fn_803A0EBC(Vp6Rc* rc);
int fn_803A0E18(Vp6Rc* rc, int prob);

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

}
