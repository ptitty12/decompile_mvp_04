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

extern "C" int SHAPE_isclut(int);
extern "C" int GetSwizzledPixelOffset(int, int, int, int, int);

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

extern "C" int MEM_allocaligna(int, int, int, int, int, int);

struct RcBlk {
    unsigned char tag;
    char pad1[3];
    union {
        int i;
        struct {
            short s4;
            short s6;
        } s;
        struct {
            unsigned short us4;
            unsigned short us6;
        } u;
    } m4;
    int m8;
    unsigned mC;
    int m10;
};

extern "C" int fn_803EC084(RcBlk*, int, int, int);
extern "C" unsigned char* SHAPE_getpixeladr(RcBlk*, int, int, int);
extern "C" int SHAPE_swizzleat(RcBlk*, RcBlk*);
extern "C" int SHAPE_swizzle32(unsigned char*, volatile unsigned char*, int, int);
extern "C" int SHAPE_swizzle16(unsigned char*, volatile unsigned char*, int, int);
extern "C" int SHAPE_swizzle8(unsigned char*, volatile unsigned char*, int, int);
extern "C" int SHAPE_swizzle4(unsigned char*, volatile unsigned char*, int, int);
extern "C" int strlen(const char* s);
extern "C" int sizerefpack(void*, int*);
extern "C" int fn_803EC568(unsigned char, short, short, int, int);
extern "C" RcBlk* SHAPE_clone(RcBlk*);

extern "C" RcNode* SHAPE_clut(RcNode* n)
{
    if (n != 0) {
        do {
            if (SHAPE_isclut(n->tag) != 0)
                return n;
            n = RcNext(n);
        } while (n != 0);
    }
    return 0;
}

extern "C" char* SHAPE_comment(RcNode* n)
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

extern "C" void SHAPE_destroy(char* p)
{
    *p = 0;
    lbl_806EE9E8(p);
}

extern "C" char* SHAPE_hotspots(RcNode* n)
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

extern "C" int SHAPE_isclut(int c)
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

extern "C" char* SHAPE_longname(RcNode* n)
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

extern "C" unsigned SHAPE_readpixel(RcBlk* t, int x, int y, int lvl)
{
    unsigned r = 0;
    if (x >= 0 && x < t->m4.s.s4 && y >= 0 && y < t->m4.s.s6 && lvl >= 0 && lvl <= (int)((t->mC >> 12) & 0xf)) {
        int off = fn_803EC084(t, x, y, lvl);
        unsigned char* b;
        if (t->mC & 0x10000000)
            b = (unsigned char*)t + t->m10;
        else
            b = (unsigned char*)t + 0x10;
        int idx = off >> 3;
        unsigned char* p = b + idx;
        switch (fn_803EC03C((RcNode*)t)) {
        case 4:
            if (off & 4)
                r = b[idx] & 0xf;
            else
                r = b[idx] >> 4;
            break;
        case 8:
            r = b[idx];
            break;
        case 0xf:
        case 0x10:
            r = *(unsigned short*)(b + idx);
            break;
        case 0x18:
            r = (b[idx] << 16) | (p[1] << 8) | p[2];
            break;
        case 0x20:
            if (t->mC & 0x20000000)
                r = (*(unsigned short*)(b + idx) << 16) | *(unsigned short*)(p + 0x20);
            else
                r = *(unsigned*)(b + idx);
            break;
        }
    }
    return r;
}

extern "C" int fn_803ECF4C(int, int);
extern "C" int fn_803ECF68(int, int);
extern "C" int fn_803ECF84(int, int);
extern "C" int fn_803ECFA0(int, int);
extern "C" int fn_803EC568(unsigned char tag, short w, short h, int levels, int flag)
{
    struct RcTmpN {
        unsigned char tag;
        char pad[15];
    } tmpn;
    tmpn.tag = tag;
    int total = 0;
    int bpp = fn_803EC03C((RcNode*)&tmpn);
    if (bpp == 0xf)
        bpp = 0x10;
    unsigned i;
    if (flag != 0) {
        i = 0;
        if ((unsigned)total <= (unsigned)levels) {
            do {
                switch (bpp) {
                case 0x20:
                    total += fn_803ECF4C(w >> i, h >> i);
                    break;
                case 0xf:
                case 0x10:
                    total += fn_803ECF68(w >> i, h >> i);
                    break;
                case 8:
                    total += fn_803ECF84(w >> i, h >> i);
                    break;
                case 4:
                    total += fn_803ECFA0(w >> i, h >> i);
                    break;
                }
                i++;
            } while (i <= (unsigned)levels);
        }
    } else {
        i = 0;
        if ((unsigned)total <= (unsigned)levels) {
            do {
                int cw = w >> i;
                int ch = h >> i;
                if (cw <= 0)
                    cw = 1;
                if (ch <= 0)
                    ch = 1;
                if (tag == 0x1e) {
                    cw = (cw + 7) & ~7;
                    ch = (ch + 7) & ~7;
                }
                if (total != 0)
                    total = (total + 0x1f) & ~0x1f;
                total += ((cw * bpp + 7) / 8) * ch;
                i++;
            } while (i <= (unsigned)levels);
        }
    }
    if (total != 0)
        total += 0x10;
    return total;
}

extern "C" int SHAPE_size(RcBlk* n)
{
    int r = 0;
    switch ((unsigned)n->tag) {
    case 0x70:
        return strlen((char*)n + 4) + 5;
    case 0x6f:
        return n->m4.i + 8;
    case 0x7c:
        return n->m4.i * 8 + 8;
    case 0x69:
        if (n->m4.u.us6 & 0x10)
            return n->m4.u.us4 + 0x10;
        return 0x10;
    default: {
        if (n->tag & 0x80) {
            int sp8 = 0;
            char* p;
            if (n->mC & 0x10000000)
                p = (char*)n + n->m10;
            else
                p = (char*)n + 0x10;
            if (sizerefpack(p, &sp8) != 0)
                r = sp8 + 0x10;
        } else {
            r = fn_803EC568(n->tag, n->m4.s.s4, n->m4.s.s6, (n->mC >> 12) & 0xf, (n->mC >> 29) & 1);
        }
    }
    }
    return r;
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

extern "C" int SHAPE_swizzleat(RcBlk* dst, RcBlk* src)
{
    int i = 0;
    int ok = 1;
    int w = src->m4.s.s4;
    int h = src->m4.s.s6;
    int n = ((src->mC >> 12) & 0xf) + 1;
    while (i < n && ok != 0) {
        unsigned char* a = SHAPE_getpixeladr(src, 0, 0, i);
        unsigned char* b = SHAPE_getpixeladr(dst, 0, 0, i);
        switch (fn_803EC03C((RcNode*)src)) {
        case 4:
            SHAPE_swizzle4(b, a, w, h);
            break;
        case 8:
            SHAPE_swizzle8(b, a, w, h);
            break;
        case 0xf:
        case 0x10:
            SHAPE_swizzle16(b, a, w, h);
            break;
        case 0x20:
            SHAPE_swizzle32(b, a, w, h);
            break;
        default:
            ok = 0;
            break;
        }
        i++;
        w >>= 1;
        h >>= 1;
    }
    dst->mC |= 0x20000000;
    return ok;
}

extern "C" RcBlk* SHAPE_swizzle(RcBlk* x)
{
    RcBlk* p = SHAPE_clone(x);
    if (p != 0 && (p->mC & 0x20000000) == 0)
        SHAPE_swizzleat(p, x);
    return p;
}

extern "C" int SHAPE_type(int c)
{
    int r = 0;
    switch (c) {
    case 4:
        r = 0x18;
        break;
    case 8:
        r = 0x19;
        break;
    case 0x10:
    case 0x235:
        r = 0x14;
        break;
    case 0xf:
    case 0x22b:
    case 0x613:
    case 0xde3:
        r = 0x15;
        break;
    case 0x20:
    case 0x22b8:
        r = 0x16;
        break;
    }
    return r;
}

extern "C" void SHAPE_writepixel(RcBlk* t, int x, int y, int lvl, unsigned val)
{
    if (x < 0 || x >= t->m4.s.s4 || y < 0 || y >= t->m4.s.s6 || lvl < 0 || lvl > (int)((t->mC >> 12) & 0xf))
        return;
    int off = fn_803EC084(t, x, y, lvl);
    unsigned char* b;
    if (t->mC & 0x10000000)
        b = (unsigned char*)t + t->m10;
    else
        b = (unsigned char*)t + 0x10;
    int idx = off >> 3;
    unsigned char* p = b + idx;
    switch (fn_803EC03C((RcNode*)t)) {
    case 4:
        if (off & 4)
            b[idx] = (b[idx] & 0xf0) | val;
        else
            b[idx] = (b[idx] & 0x0f) | (val << 4);
        break;
    case 8:
        b[idx] = val;
        break;
    case 0xf:
        *(short*)(b + idx) = val;
        break;
    case 0x10:
        *(short*)(b + idx) = val;
        break;
    case 0x18:
        b[idx] = val >> 16;
        p[1] = val >> 8;
        p[2] = val;
        break;
    case 0x20:
        if (t->mC & 0x20000000) {
            *(short*)(b + idx) = val >> 16;
            *(short*)(p + 0x20) = val;
        } else
            *(int*)(b + idx) = val;
        break;
    }
}

extern "C" void GC_swizzle32(volatile unsigned char* src, int w, int h, int pitch, unsigned char* dst)
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

extern "C" void GC_swizzle16(volatile unsigned char* src, int w, int h, int pitch, unsigned char* dst)
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

extern "C" void GC_swizzle8(volatile unsigned char* src, int w, int h, int pitch, unsigned char* dst)
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

extern "C" void GC_swizzle4(volatile unsigned char* src, int w, int h, int pitch, unsigned char* dst)
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

extern "C" int SHAPE_swizzle32(unsigned char* dst, volatile unsigned char* src, int w, int h)
{
    GC_swizzle32(src, w, h, (w << 5) >> 3, dst);
    return 1;
}

extern "C" int SHAPE_swizzle16(unsigned char* dst, volatile unsigned char* src, int w, int h)
{
    GC_swizzle16(src, w, h, (w << 4) >> 3, dst);
    return 1;
}

extern "C" int SHAPE_swizzle8(unsigned char* dst, volatile unsigned char* src, int w, int h)
{
    GC_swizzle8(src, w, h, (w << 3) >> 3, dst);
    return 1;
}

extern "C" int SHAPE_swizzle4(unsigned char* dst, volatile unsigned char* src, int w, int h)
{
    GC_swizzle4(src, w, h, ((w << 2) + 7) >> 3, dst);
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

extern "C" int SHAPE_cluttype(int k)
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

extern "C" int GC_swizzleGetPixelOffset32(int x, int y, int w);
extern "C" int fn_803ED0E0(int x, int y, int w);
extern "C" int GC_swizzleGetPixelOffset8(int x, int y, int w);
extern "C" int GC_swizzleGetPixelOffset4(int x, int y, int w);

extern "C" int GetSwizzledPixelOffset(int x, int y, int w, int h, int bpp)
{
    int r = 0;
    switch (bpp) {
    case 0x20:
        r = GC_swizzleGetPixelOffset32(x, y, w);
        break;
    case 0xf:
        r = fn_803ED0E0(x, y, w);
        break;
    case 0x10:
        r = fn_803ED0E0(x, y, w);
        break;
    case 8:
        r = GC_swizzleGetPixelOffset8(x, y, w);
        break;
    case 4:
        r = GC_swizzleGetPixelOffset4(x, y, w);
        if (x & 1)
            return (r << 3) | 4;
        break;
    }
    return r << 3;
}

extern "C" int GC_swizzleGetPixelOffset32(int x, int y, int w)
{
    return ((((y >> 2) * ((w + 3) >> 2) + (x >> 2)) << 6) | (((y & 3) << 3) + ((x & 3) << 1)));
}

extern "C" int fn_803ED0E0(int x, int y, int w)
{
    return ((((y >> 2) * ((w + 3) >> 2) + (x >> 2)) << 5) + (((y & 3) << 3) + ((x & 3) << 1)));
}

extern "C" int GC_swizzleGetPixelOffset8(int x, int y, int w)
{
    return ((((y >> 2) * ((w + 7) >> 3) + (x >> 3)) << 5) + (((y & 3) << 3) + (x & 7)));
}

extern "C" int GC_swizzleGetPixelOffset4(int x, int y, int w)
{
    return ((((y >> 3) * ((w + 7) >> 3) + (x >> 3)) << 5) + (((y & 7) << 2) + ((x >> 1) & 3)));
}

extern "C" int fn_803ED170(int a, int idx)
{
    return lbl_806AABF4[idx & 0x3f]->m30;
}

extern "C" int fn_803ED5E0(int a, int b, int c, int d, int e)
{
    return MEM_allocaligna(a, b, c, d, e, 1);
}

extern "C" int fn_803ED604(int a, int b, int c)
{
    return MEM_allocaligna(a, b, 0, 0, c, 1);
}

extern "C" int fn_803ED634(int a, int b, int c)
{
    return MEM_allocaligna(a, b, 0, 0, c, 0);
}

extern "C" int MEM_allocsize(int a)
{
    return MEM_allocaligna(0, a, 0, 0, 0, 1);
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
