/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x80397CAC-0x8039B3E4 (code-only unit, 33 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
#include "../../include/game/tu_803959E0.h"

extern const int lbl_8069C340[];
extern const int lbl_8069C360[];

struct Vp6TapPair {
    int a, b;
};
extern const Vp6TapPair lbl_8062453C[];

/* Plane copy descriptor (fn_8039894C): luma rows/stride, then chroma. */
struct Vp6Planes {
    int m0, m4, m8, mC, m10, m14;
    const unsigned char* m18;
    const unsigned char* m1C;
    const unsigned char* m20;
};

typedef void (*Vp6Fn)();
extern Vp6Fn lbl_806EF3F8, lbl_806EF3FC, lbl_806EF3F0, lbl_806EF3DC, lbl_806EF3E0;
typedef int* (*Vp6DqFn)(Vp6Dq*, int);
extern Vp6DqFn lbl_806EF3F4;
extern const int* lbl_806EF454;
extern int* lbl_806EF448;
extern int* lbl_806EF44C;
typedef void (*Vp6McFn)(Vp6Buf*, unsigned char*, unsigned char*, int, unsigned, int, int*);
extern Vp6McFn lbl_806EF3EC;
extern Vp6McFn lbl_806EF3E4;
extern Vp6McFn lbl_806EF3E8;
extern int* lbl_806EF450;
extern Vp6Fn lbl_806EF3D4, lbl_806EF3D8, lbl_806EF3C0;
extern Vp6Fn lbl_806EF3CC, lbl_806EF3D0, lbl_806EF3C4, lbl_806EF3B8, lbl_806EF3BC, lbl_806EF3C8;
extern Vp6Fn lbl_806EF3B0, lbl_806EF3B4, lbl_806EF3AC, lbl_806EF3A8, lbl_806EF3A4, lbl_806EF3A0;
extern Vp6Fn lbl_806EF404, lbl_806EF400, lbl_806EF408;
extern Vp6Fn lbl_806EF424, lbl_806EF414, lbl_806EF418, lbl_806EF41C, lbl_806EF434, lbl_806EF430;
extern Vp6Fn lbl_806EF428, lbl_806EF42C, lbl_806EF438, lbl_806EF43C, lbl_806EF440, lbl_806EF444;
extern Vp6Fn lbl_806EF410;
extern Vp6Fn lbl_8069C4A0[0x41];
extern Vp6Fn lbl_8069C5A4[0x41];

extern "C" {

void fn_80398494();
void fn_80398498();
void fn_80396B50();
void fn_80397AB0();
void fn_80397AB4();
void fn_80397B70();
void fn_80397C0C();
void fn_80397C34();
void fn_803A31C0();
void fn_803A3214();
void fn_803A3270();
void fn_803A32CC();
void fn_803A3998();
void fn_803A3D0C();
void fn_803A3D4C();
void fn_803A3F0C();
void fn_8039FF6C();
void fn_8039F9F8();
void fn_8039FA68();
void fn_8039F94C();
int* fn_80398B40(Vp6Dq* d, int n);
void fn_8039D830();
void fn_8039D120();
void fn_80398FE0();
void fn_80399EA8();
void fn_8039A778();
void fn_80396E5C();
void fn_80396F4C();
void fn_803A0554();
void fn_803A05A0();
void fn_803A05DC();
void fn_803A0310();
void fn_803A0408();
void fn_803A04BC();
void fn_803A00DC();
void fn_803A01D4();
void fn_803A0288();
void fn_8039FB00();
void fn_8039FBB0();
void fn_8039FC88();
void fn_8039FD38();
void fn_8039D058();
void fn_80398A78(Vp6Buf* b, int lo, int hi, unsigned char* dst, const unsigned char* src);
void fn_80396398();
void fn_80397DBC(const unsigned char* src, int* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps);
void fn_80397EA8(const int* src, short* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps);
void fn_8039800C(const unsigned char* src, int* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps);
void fn_8039868C(Vp6Buf* b, unsigned char* base);
void fn_8039B058(Vp6Buf* b, int stride, int a, unsigned w, unsigned h, unsigned char* src, unsigned char* dst, int* tbl);
void fn_80399808(Vp6Buf* b, unsigned char* x, unsigned char* y, int stride, unsigned w, int a, int* tbl);
void fn_80398C5C(Vp6Buf* b, unsigned char* x, unsigned char* y, int stride, unsigned w, int a, int* tbl);
void fn_80399BF0(Vp6Buf* b, unsigned char* x, unsigned char* y, int stride, unsigned w, int a, int* tbl);
void fn_8039AE60(Vp6Buf* b, unsigned char* src, unsigned char* dst, unsigned plane);
void fn_80398BEC(Vp6Dq* d);
void fn_80398138(const int* src, unsigned char* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps);

void fn_80397CAC()
{
    fn_80398494();
    fn_80398498();
}

void fn_80397CD0(const unsigned char* src, short* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps)
{
    for (unsigned r = 0; r < rows; r++) {
        for (unsigned c = 0; c < cols; c++) {
            int v = (src[-step] * taps[0] + src[0] * taps[1] + src[step] * taps[2] + src[step * 2] * taps[3] + 0x40) >> 7;
            if (v < 0) {
                v = 0;
            } else if (v > 255) {
                v = 255;
            }
            dst[c] = v;
            src++;
        }
        src += stride - cols;
        dst += cols;
    }
}

void fn_80397DBC(const unsigned char* src, int* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps)
{
    for (unsigned r = 0; r < rows; r++) {
        for (unsigned c = 0; c < cols; c++) {
            int v = (src[-step] * taps[0] + src[0] * taps[1] + src[step] * taps[2] + src[step * 2] * taps[3] + 0x40) >> 7;
            if (v < 0) {
                v = 0;
            } else if (v > 255) {
                v = 255;
            }
            dst[c] = v;
            src++;
        }
        src += stride - cols;
        dst += cols;
    }
}

void fn_80397EA8(const int* src, short* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps)
{
    for (unsigned r = 0; r < rows; r++) {
        for (unsigned c = 0; c < cols; c++) {
            int v = (src[-step] * taps[0] + src[0] * taps[1] + src[step] * taps[2] + src[step * 2] * taps[3] + 0x40) >> 7;
            if (v < 0) {
                v = 0;
            } else if (v > 255) {
                v = 255;
            }
            dst[c] = v;
            src++;
        }
        src += stride - cols;
        dst += cols;
    }
}

void fn_80397F98(const unsigned char* src, short* dst, int stride, const int* tapsA, const int* tapsB)
{
    fn_80397DBC(src - stride, (int*)lbl_8069C340, stride, 1, 11, 8, tapsA);
    fn_80397EA8(lbl_8069C360, dst, 8, 8, 8, 8, tapsB);
}

void fn_8039800C(const unsigned char* src, int* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps)
{
    for (unsigned r = 0; r < rows; r++) {
        for (unsigned c = 0; c < cols; c++) {
            dst[c] = (src[0] * taps[0] + src[step] * taps[1] + 0x40) >> 7;
            src++;
        }
        src += stride - cols;
        dst += cols;
    }
}

void fn_803980A8(const unsigned char* src, unsigned char* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps)
{
    for (unsigned r = 0; r < rows; r++) {
        for (unsigned c = 0; c < cols; c++) {
            dst[c] = (src[0] * taps[0] + src[step] * taps[1] + 0x40) >> 7;
            src++;
        }
        src += stride - cols;
        dst += cols;
    }
}

void fn_80398138(const int* src, unsigned char* dst, int stride, int step, unsigned rows, unsigned cols, const int* taps)
{
    for (unsigned r = 0; r < rows; r++) {
        for (unsigned c = 0; c < cols; c++) {
            dst[c] = (src[0] * taps[0] + src[step] * taps[1] + 0x40) >> 7;
            src++;
        }
        src += stride - cols;
        dst += cols;
    }
}

void fn_803981D0(const unsigned char* src, unsigned char* dst, int stride, const int* tapsA, const int* tapsB)
{
    fn_8039800C(src, (int*)lbl_8069C340, stride, 1, 9, 8, tapsA);
    fn_80398138(lbl_8069C340, dst, 8, 8, 8, 8, tapsB);
}

void fn_80398238(const unsigned char* p0, const unsigned char* p1, unsigned char* dst, int stride, int i, int j)
{
    int d = p1 - p0;
    if (d < 0) {
        const unsigned char* t = p0;
        p0 = p1;
        d = t - p1;
    }
    if (d == 1) {
        fn_803980A8(p0, dst, stride, 1, 8, 8, &lbl_8062453C[i].a);
    } else if (d == stride) {
        fn_803980A8(p0, dst, stride, stride, 8, 8, &lbl_8062453C[j].a);
    } else if (d == stride - 1) {
        fn_803981D0(p0 - 1, dst, stride, &lbl_8062453C[i].a, &lbl_8062453C[j].a);
    } else if (d == stride + 1) {
        fn_803981D0(p0, dst, stride, &lbl_8062453C[i].a, &lbl_8062453C[j].a);
    }
}

void fn_80398324()
{
    lbl_806EF3F8 = fn_8039F9F8;
    lbl_806EF3FC = fn_8039FA68;
    lbl_806EF3F0 = fn_8039F94C;
    lbl_806EF3F4 = fn_80398B40;
    lbl_806EF3DC = fn_8039D830;
    lbl_806EF3E0 = fn_8039D120;
    lbl_806EF3E4 = (Vp6McFn)fn_80398FE0;
    lbl_806EF3E8 = (Vp6McFn)fn_80399EA8;
    lbl_806EF3EC = (Vp6McFn)fn_8039A778;
    lbl_806EF3D4 = fn_80396E5C;
    lbl_806EF3D8 = fn_80396F4C;
    lbl_806EF3C0 = fn_803A0554;
    lbl_806EF3CC = fn_803A05A0;
    lbl_806EF3D0 = fn_803A05DC;
    lbl_806EF3C4 = fn_803A0310;
    lbl_806EF3B8 = fn_803A0408;
    lbl_806EF3BC = fn_803A04BC;
    lbl_806EF3C8 = fn_803A00DC;
    lbl_806EF3B0 = fn_803A01D4;
    lbl_806EF3B4 = fn_803A0288;
    lbl_806EF3AC = fn_8039FB00;
    lbl_806EF3A8 = fn_8039FBB0;
    lbl_806EF3A4 = fn_8039FC88;
    lbl_806EF3A0 = fn_8039FD38;
    lbl_806EF404 = fn_8039D058;
    lbl_806EF400 = (Vp6Fn)fn_80398A78;
    lbl_806EF408 = fn_80396398;
}

int fn_8039847C()
{
    return 0;
}

void fn_80398484()
{
    lbl_806EF410 = fn_80396B50;
}

void fn_80398494()
{
}

void fn_80398498()
{
    int i;
    for (i = 0; i < 0x41; i++) {
        if (i <= 1) {
            lbl_8069C4A0[i] = fn_803A3D0C;
        } else if (i <= 10) {
            lbl_8069C4A0[i] = fn_803A3998;
        } else {
            lbl_8069C4A0[i] = fn_803A32CC;
        }
    }
    for (i = 0; i < 0x41; i++) {
        if (i <= 1) {
            lbl_8069C5A4[i] = fn_803A3D0C;
        } else if (i <= 10) {
            lbl_8069C5A4[i] = fn_803A3998;
        } else {
            lbl_8069C5A4[i] = fn_803A32CC;
        }
    }
    lbl_806EF424 = fn_80397AB0;
    lbl_806EF414 = fn_803A31C0;
    lbl_806EF418 = fn_803A3214;
    lbl_806EF41C = fn_8039FF6C;
    lbl_806EF434 = fn_80397AB4;
    lbl_806EF430 = fn_803A3D4C;
    lbl_806EF428 = fn_803A3270;
    lbl_806EF42C = fn_80397B70;
    lbl_806EF438 = fn_80397C0C;
    lbl_806EF43C = fn_80397C34;
    lbl_806EF440 = (Vp6Fn)fn_80398238;
    lbl_806EF444 = fn_803A3F0C;
}

void* fn_803985F4(int size, int flags)
{
    return fn_803959E0(size);
}

void fn_80398614(void* p)
{
    fn_80395A44(p);
}

void fn_80398634(Vp6Rc* rc, const unsigned char* buf)
{
    rc->m0 = 0;
    rc->m4 = 0xFF;
    rc->mC = 8;
    rc->m10 = 0;
    rc->m14 = buf;
    rc->m8 = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
    rc->m10 = 4;
}

/* near-miss: same structure as the original code, but callee-saved registers are
   allocated differently (b in r23 vs r24) and the chroma blocks differ in CSE; 170 slots. */
void fn_8039868C(Vp6Buf* b, unsigned char* base)
{
    unsigned char* p = base + b->m78;
    int border = b->mB4;
    unsigned char* right = p + (b->m90 << 3);
    int stride = b->m98;
    unsigned char* left = p - border;
    unsigned char* last = right - 1;
    int rows = b->m94 << 3;
    int i;
    for (i = 0; i < rows; i++) {
        memset(left, *p, border);
        p += stride;
        left += stride;
        memset(right, *last, border);
        last += stride;
        right += stride;
    }
    unsigned char* top = base;
    unsigned char* src = base + border * stride;
    int bw = (unsigned)border >> 1;
    unsigned char* lastrow = src + b->m94 * (stride << 3) - stride;
    unsigned char* bot = lastrow + stride;
    for (i = 0; i < border; i++) {
        MEMCPY_V(top, src, stride);
        top += stride;
        MEMCPY_V(bot, lastrow, stride);
        bot += stride;
    }

    p = base + b->m7C;
    right = p + (b->m90 << 2);
    stride = b->m9C;
    left = p - bw;
    last = right - 1;
    rows = b->m94 << 2;
    for (i = 0; i < rows; i++) {
        memset(left, *p, bw);
        p += stride;
        left += stride;
        memset(right, *last, bw);
        last += stride;
        right += stride;
    }
    src = base + b->m7C - bw;
    lastrow = src + b->m94 * (stride << 2) - stride;
    top = src - bw * stride;
    bot = lastrow + stride;
    for (i = 0; i < bw; i++) {
        MEMCPY_V(top, src, stride);
        top += stride;
        MEMCPY_V(bot, lastrow, stride);
        bot += stride;
    }

    p = base + b->m80;
    right = p + (b->m90 << 2);
    left = p - bw;
    last = right - 1;
    for (i = 0; i < rows; i++) {
        memset(left, *p, bw);
        p += stride;
        left += stride;
        memset(right, *last, bw);
        last += stride;
        right += stride;
    }
    src = base + b->m80 - bw;
    lastrow = src + b->m94 * (stride << 2) - stride;
    top = src - bw * stride;
    bot = lastrow + stride;
    for (i = 0; i < bw; i++) {
        MEMCPY_V(top, src, stride);
        top += stride;
        MEMCPY_V(bot, lastrow, stride);
        bot += stride;
    }
}

void fn_8039894C(Vp6Buf* b, Vp6Planes* f, unsigned char* base)
{
    unsigned char* p = base + b->m78;
    const unsigned char* q = f->m18;
    for (int i = 0; i < f->m4; ) {
        i++;
        MEMCPY_V(p, q, f->m0);
        q += f->m8;
        p += b->m98;
    }
    p = base + b->m7C;
    q = f->m1C;
    for (int i = 0; i < f->m10; ) {
        i++;
        MEMCPY_V(p, q, f->mC);
        q += f->m14;
        p += b->m9C;
    }
    p = base + b->m80;
    q = f->m20;
    for (int i = 0; i < f->m10; ) {
        i++;
        MEMCPY_V(p, q, f->mC);
        q += f->m14;
        p += b->m9C;
    }
    fn_8039868C(b, base);
}

void fn_80398A78(Vp6Buf* b, int lo, int hi, unsigned char* dst, const unsigned char* src)
{
    unsigned char lut[256];
int cols = b->m90 << 3;
    int rows = b->m94 << 3;
    dst += b->m78;
    int stride = b->m98;
    src += b->m78;
    for (int i = 0; i < 256; i++) {
        lut[i] = i;
        if (i < lo) lut[i] = lo;
        if (i > 255 - hi) lut[i] = ~hi;
    }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            dst[c] = lut[src[c]];
        }
        dst += stride;
        src += stride;
    }
}

int* fn_80398B40(Vp6Dq* d, int n)
{
    int* base = d->m3C + 0x100;
    MEMSET_V(d->m3C, 0, 0x800);
    for (int i = 0; i < n; i++) {
        base[-(n + i)] = -n + i;
        base[-i] = -i;
        base[i] = i;
        base[n + i] = n - i;
    }
    return base;
}

void fn_80398BEC(Vp6Dq* d)
{
    if (d->m0 > 1) {
        d->m38 = fn_80398B40(d, lbl_806EF454[d->mC]);
    } else {
        d->m38 = lbl_806EF3F4(d, lbl_806EF454[d->mC]);
    }
}

/* near-miss: 126 vs 125 insns; plane setup registers allocated differently. */
void fn_8039AE60(Vp6Buf* b, unsigned char* a, unsigned char* c, unsigned plane)
{
    Vp6McFn fn;
    Vp6McFn end;
    int* tbl = 0;
    int off;
    int stride;
    int base;
    unsigned w;
    unsigned h;
    unsigned char* dst;
    unsigned char* src;
    unsigned i;
    unsigned j;
    int k;
    if (reinterpret_cast<Vp6Dq*>(b)->m0 > 1) {
        fn = lbl_806EF3E8;
        end = fn_80399808;
    } else {
        fn = lbl_806EF3E4;
        end = fn_80398C5C;
    }
    if (plane == 0) {
        off = b->m78;
        base = 0;
        stride = b->m98;
        dst = c + off;
        src = a + off;
        w = b->m90;
        h = b->m94;
    } else if (plane == 1) {
        off = b->m7C;
        w = (unsigned)b->m90 >> 1;
        h = (unsigned)b->m94 >> 1;
        dst = c + off;
        src = a + off;
        stride = b->m9C;
        base = b->m84;
    } else {
        off = b->m80;
        w = (unsigned)b->m90 >> 1;
        h = (unsigned)b->m94 >> 1;
        dst = c + off;
        src = a + off;
        stride = b->m9C;
        base = b->m84 + b->m88;
    }
    if (reinterpret_cast<Vp6Dq*>(b)->m0 > 1) {
        if (plane == 0) {
            tbl = lbl_806EF448;
        } else if (plane <= 2) {
            tbl = lbl_806EF44C;
        }
    } else {
        tbl = lbl_806EF450;
    }
    for (i = 0; i <= 3; i++) {
        k = i * stride;
        for (j = 0; j < (unsigned)stride; j++) {
            dst[k] = src[k];
            k++;
        }
    }
    for (j = 1; j < h; j++) {
        base += w;
        src += stride << 3;
        dst += stride << 3;
        fn(b, src, dst, stride, w, base, tbl);
    }
    for (i = 0; i <= 3; i++) {
        k = (i + 4) * stride;
        for (j = 0; j < (unsigned)stride; j++) {
            dst[k] = src[k];
            k++;
        }
    }
    end(b, src, dst, stride, w, base, tbl);
}

/* near-miss: 75 insns like the original code; stride and the copy pointer swap r29/r30 (priority of the loop pointer). */
void fn_8039B058(Vp6Buf* b, int stride, int a, unsigned w, unsigned h, unsigned char* X, unsigned char* Y, int* tbl)
{
    Vp6McFn fn = lbl_806EF3EC;
    Vp6McFn last = fn_80399BF0;
    unsigned i;
    unsigned j;
    unsigned char* x = X;
    unsigned char* y = Y;
    for (i = 0; i <= 3; i++) {
        MEMCPY_V(y, x, stride);
        x += stride;
        y += stride;
    }
    for (j = 1; j < h; j++) {
        X += stride << 3;
        Y += stride << 3;
        fn(b, X, Y, stride, w, a, tbl);
        a += w;
    }
    y = Y + stride * 4;
    x = X + stride * 4;
    for (i = 0; i <= 3; i++) {
        MEMCPY_V(y, x, stride);
        x += stride;
        y += stride;
    }
    last(b, X, Y, stride, w, a, tbl);
}

void fn_8039B184(Vp6Buf* b, unsigned char* src, unsigned char* dst)
{
    memset(b->m28, 0, b->m8C * 4);
    if (reinterpret_cast<Vp6Dq*>(b)->m0 > 1) {
        fn_80398BEC(reinterpret_cast<Vp6Dq*>(b));
    }
    if (reinterpret_cast<Vp6Dq*>(b)->m0 > 4) {
        fn_8039B058(b, b->m98, 0, b->m90, b->m94, src + b->m78, dst + b->m78, lbl_806EF448);
        fn_8039B058(b, b->m9C, 0, (unsigned)b->m90 >> 1, (unsigned)b->m94 >> 1, src + b->m7C, dst + b->m7C, lbl_806EF44C);
        fn_8039B058(b, b->m9C, 0, (unsigned)b->m90 >> 1, (unsigned)b->m94 >> 1, src + b->m80, dst + b->m80, lbl_806EF44C);
    } else {
        fn_8039AE60(b, src, dst, 0);
        fn_8039AE60(b, src, dst, 1);
        fn_8039AE60(b, src, dst, 2);
    }
}

void fn_8039B2B0(Vp6Buf* b, unsigned char* a, unsigned char* c)
{
    fn_80398BEC(reinterpret_cast<Vp6Dq*>(b));
    void* save = b->m28;
    memset(save, 0, b->m8C * 4);
    fn_8039B058(b, b->m98 * 2, 0, b->m90, (unsigned)b->m94 >> 1, a + b->m78, c + b->m78, lbl_806EF448);
    b->m28 = reinterpret_cast<int*>(b->m28) + (((unsigned)(b->m90 * b->m94)) >> 1);
    fn_8039B058(b, b->m98 * 2, 0, b->m90, (unsigned)b->m94 >> 1, a + (b->m78 + b->m98), c + (b->m78 + b->m98), lbl_806EF448);
    b->m28 = save;
    fn_8039B058(b, b->m9C, b->m84, (unsigned)b->m90 >> 1, (unsigned)b->m94 >> 1, a + b->m7C, c + b->m7C, lbl_806EF44C);
    fn_8039B058(b, b->m9C, b->m84 + b->m88, (unsigned)b->m90 >> 1, (unsigned)b->m94 >> 1, a + b->m80, c + b->m80, lbl_806EF44C);
}

}
