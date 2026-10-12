/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803EBF90-0x803ED700 (code-only unit, 43 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern unsigned char lbl_8062E4A0[];
struct RcObj30 {
    char pad[0x30];
    int m30;
};
extern RcObj30* lbl_806AABF4[64];
extern int lbl_806AABE4[4];
extern void (*lbl_806EE9E8)(char*);

extern "C" int fn_803EC368(int);
extern "C" int fn_803ED010(int, int, int, int, int);

struct RcNode {
    unsigned char tag;
};

inline RcNode* RcNext(RcNode* n)
{
    int o = (*(int*)n << 8) >> 8;
    RcNode* r = 0;
    if (o != 0)
        r = (RcNode*)((char*)n + o);
    return r;
}

extern "C" int fn_803ED188(int, int, int, int, int, int);

extern "C" RcNode* fn_803EBF90(RcNode* n)
{
    if (n != 0) {
        do {
            if (fn_803EC368(n->tag) != 0)
                return n;
            n = RcNext(n);
        } while (n != 0);
    }
    return 0;
}

extern "C" char* fn_803EBFF8(RcNode* n)
{
    if (n != 0) {
        do {
            if (n->tag == 0x6f)
                return (char*)n + 8;
            n = RcNext(n);
        } while (n != 0);
    }
    return 0;
}

extern "C" int fn_803EC03C(RcNode* n)
{
    return lbl_8062E4A0[n->tag & 0x7f];
}

extern "C" void fn_803EC054(char* p)
{
    *p = 0;
    lbl_806EE9E8(p);
}

extern "C" char* fn_803EC324(RcNode* n)
{
    if (n != 0) {
        do {
            if (n->tag == 0x7c)
                return (char*)n + 8;
            n = RcNext(n);
        } while (n != 0);
    }
    return 0;
}

extern "C" int fn_803EC368(int c)
{
    int r = 0;
    switch (c) {
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x24:
    case 0x29:
    case 0x2a:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x38:
        r = 1;
        break;
    }
    return r;
}

extern "C" char* fn_803EC3D4(RcNode* n)
{
    if (n != 0) {
        do {
            if (n->tag == 0x70)
                return (char*)n + 4;
            n = RcNext(n);
        } while (n != 0);
    }
    return 0;
}

struct RcArr {
    int m0, m4, m8, mC;
};

extern "C" int* fn_803EC814(RcArr* a, int i, int* out)
{
    int v = 0;
    if (i < a->m8)
        v = *(int*)((char*)a + i * 8 + 0x10);
    *out = v;
    return out;
}

extern "C" void fn_803ECBD0(volatile unsigned char* src, int w, int h, int pitch, unsigned char* dst)
{
    int tpr = (w + 3) >> 2;
    w = w << 2;
    int y, x;
    for (y = 0; y < h; y++) {
        int a = (y >> 2) * tpr;
        int b = (y & 3) << 3;
        int c = y * pitch;
        for (x = 0; x < w; x++) {
            dst[((((x >> 4) + a) << 6) + b) + ((x & 2) << 4) + ((x >> 1) & 6) + (x & 1)] = src[x + c];
        }
    }
}

extern "C" void fn_803ECC78(volatile unsigned char* src, int w, int h, int pitch, unsigned char* dst)
{
    int tpr = (w + 3) >> 2;
    w = w + w;
    int y, x;
    for (y = 0; y < h; y++) {
        int a = (y >> 2) * tpr;
        int b = (y & 3) << 3;
        int c = y * pitch;
        for (x = 0; x < w; x++) {
            dst[(((x >> 3) + a) << 5) + ((x & 7) + b)] = src[x + c];
        }
    }
}

extern "C" void fn_803ECD10(volatile unsigned char* src, int w, int h, int pitch, unsigned char* dst)
{
    int tpr = (w + 7) >> 3;
    int y, x;
    for (y = 0; y < h; y++) {
        int a = (y >> 2) * tpr;
        int b = (y & 3) << 3;
        int c = y * pitch;
        for (x = 0; x < w; x++) {
            dst[(((x >> 3) + a) << 5) + ((x & 7) + b)] = src[x + c];
        }
    }
}

extern "C" void fn_803ECDA4(volatile unsigned char* src, int w, int h, int pitch, unsigned char* dst)
{
    int tpr = (w + 7) >> 3;
    w = (w + 1) / 2;
    int y, x;
    for (y = 0; y < h; y++) {
        int a = (y >> 3) * tpr;
        int b = (y & 7) << 2;
        int c = y * pitch;
        for (x = 0; x < w; x++) {
            dst[(((x >> 2) + a) << 5) + ((x & 3) + b)] = src[x + c];
        }
    }
}

extern "C" int fn_803ECE48(unsigned char* dst, volatile unsigned char* src, int w, int h)
{
    fn_803ECBD0(src, w, h, (w << 5) >> 3, dst);
    return 1;
}

extern "C" int fn_803ECE88(unsigned char* dst, volatile unsigned char* src, int w, int h)
{
    fn_803ECC78(src, w, h, (w << 4) >> 3, dst);
    return 1;
}

extern "C" int fn_803ECEC8(unsigned char* dst, volatile unsigned char* src, int w, int h)
{
    fn_803ECD10(src, w, h, (w << 3) >> 3, dst);
    return 1;
}

extern "C" int fn_803ECF08(unsigned char* dst, volatile unsigned char* src, int w, int h)
{
    fn_803ECDA4(src, w, h, ((w << 2) + 7) >> 3, dst);
    return 1;
}

extern "C" int fn_803ECF4C(int w, int h)
{
    return (((w + 3) >> 2) * ((h + 3) >> 2)) << 6;
}

extern "C" int fn_803ECF68(int w, int h)
{
    return (((w + 3) >> 2) * ((h + 3) >> 2)) << 5;
}

extern "C" int fn_803ECF84(int w, int h)
{
    return (((w + 7) >> 3) * ((h + 3) >> 2)) << 5;
}

extern "C" int fn_803ECFA0(int w, int h)
{
    return (((w + 7) >> 3) * ((h + 7) >> 3)) << 5;
}

extern "C" int fn_803ECFBC(int k)
{
    int r = 0;
    switch (k) {
    case 0xf:
        r = 0x32;
        break;
    case 0x10:
        r = 0x31;
        break;
    case 0x12:
        r = 0;
        break;
    case 0x18:
        r = 0;
        break;
    case 0x20:
        r = 0x33;
        break;
    }
    return r;
}

extern "C" int fn_803ED0B0(int x, int y, int w);
extern "C" int fn_803ED0E0(int x, int y, int w);
extern "C" int fn_803ED110(int x, int y, int w);
extern "C" int fn_803ED140(int x, int y, int w);

extern "C" int fn_803ED010(int x, int y, int w, int h, int bpp)
{
    int r = 0;
    switch (bpp) {
    case 0x20:
        r = fn_803ED0B0(x, y, w);
        break;
    case 0xf:
        r = fn_803ED0E0(x, y, w);
        break;
    case 0x10:
        r = fn_803ED0E0(x, y, w);
        break;
    case 8:
        r = fn_803ED110(x, y, w);
        break;
    case 4:
        r = fn_803ED140(x, y, w);
        if (x & 1)
            return (r << 3) | 4;
        break;
    }
    return r << 3;
}

extern "C" int fn_803ED0B0(int x, int y, int w)
{
    return ((((y >> 2) * ((w + 3) >> 2) + (x >> 2)) << 6) | (((y & 3) << 3) + ((x & 3) << 1)));
}

extern "C" int fn_803ED0E0(int x, int y, int w)
{
    return ((((y >> 2) * ((w + 3) >> 2) + (x >> 2)) << 5) + (((y & 3) << 3) + ((x & 3) << 1)));
}

extern "C" int fn_803ED110(int x, int y, int w)
{
    return ((((y >> 2) * ((w + 7) >> 3) + (x >> 3)) << 5) + (((y & 3) << 3) + (x & 7)));
}

extern "C" int fn_803ED140(int x, int y, int w)
{
    return ((((y >> 3) * ((w + 7) >> 3) + (x >> 3)) << 5) + (((y & 7) << 2) + ((x >> 1) & 3)));
}

extern "C" int fn_803ED170(int a, int idx)
{
    return lbl_806AABF4[idx & 0x3f]->m30;
}

extern "C" int fn_803ED5E0(int a, int b, int c, int d, int e)
{
    return fn_803ED188(a, b, c, d, e, 1);
}

extern "C" int fn_803ED604(int a, int b, int c)
{
    return fn_803ED188(a, b, 0, 0, c, 1);
}

extern "C" int fn_803ED634(int a, int b, int c)
{
    return fn_803ED188(a, b, 0, 0, c, 0);
}

extern "C" int fn_803ED664(int a)
{
    return fn_803ED188(0, a, 0, 0, 0, 1);
}

extern "C" void fn_803ED69C(int a, int b)
{
    if (b != 0xffff)
        return;
    if (a == 0)
        return;
    lbl_806AABE4[0] = 0;
    lbl_806AABE4[1] = 0;
    lbl_806AABE4[2] = 0;
    lbl_806AABE4[3] = 0;
}

extern "C" void fn_803ED6D4()
{
    fn_803ED69C(1, 0xffff);
}
