/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x8039B3E4-0x803A0310 (code-only unit, 47 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
#include "../../include/game/tu_803959E0.h"

/* List entry of fn_8039F5CC: next index, sort key, unused. */
/* Four 16-byte entries at +0xCC: m4 = -1 and m8 = 4 after clearing. */
struct Vp6Ent16 {
    int m0;
    int m4;
    short m8;
    short mA;
    int mC;
};

struct Vp6Hdr {
    char padCC[0xCC];
    Vp6Ent16 mCC[4];
};

/* Scan-order tables built by fn_8039B3E4 (offsets inside the decoder context). */
struct Vp6ScanView {
    char pad0[0x19C];
    unsigned char m19C;
    char pad19D[0x5BC - 0x19D];
    unsigned char m5BC[0x40];
    unsigned char m5FC[0x40];
};

/* Context view for fn_8039F94C: the limit table pointer sits at +0x34. */
struct Vp6LimView {
    char pad0[0x34];
    int* m34;
};

struct Vp6Link {
    int next;
    int key;
    int pad;
};

extern unsigned char lbl_8069C140[];
extern const int* lbl_806EF458;

extern const int lbl_80608AC8[];
extern const unsigned char lbl_80608678[];

extern "C" {

void fn_8039FE10(unsigned char* dst, const short* src, int dstride, int sstride);
void fn_80398614(void* p);
void* fn_803985F4(int size, int flags);
int fn_803A0EBC(Vp6Rc* rc);
int fn_8039EF84(Vp6Rc* rc, int n);
int fn_803A0E18(Vp6Rc* rc, int prob);
int fn_8039CC38(Vp6Ctx* c);
void fn_8039C980(Vp6Ctx* c);
int fn_8039E9E0(void* ctx);
void fn_8039F264(Vp6Ctx* c);
void fn_8039EFD4(Vp6Ctx* c);
void fn_8039733C(Vp6Ctx* c, unsigned kind, int val);
void fn_80396114(Vp6Buf* b, const Vp6Params* p);
int fn_8039F0C0(Vp6Ctx* c);
int fn_8039F2EC(Vp6Ctx* c, int n);

/* near-miss: loop structure right, the k counter and table base registers are allocated differently. */
void fn_8039B3E4(Vp6ScanView* v, const unsigned char* order)
{
    int n = 1;
    unsigned k;
    int i;
    v->m5BC[0] = 0;
    for (k = 0; k <= 15; k++) {
        for (i = 1; i < 64; i++) {
            if (order[i] == k) {
                v->m5BC[n] = i;
                n++;
            }
        }
    }
    unsigned max = 0;
    for (i = 0; i < 64; i++) {
        if (v->m5BC[i] > max) {
            max = v->m5BC[i];
        }
        v->m5FC[i] = max;
        if (v->m19C > 6) {
            v->m5FC[i] = max + 1;
        }
    }
}

/* near-miss: same instruction count; scratch registers are numbered differently. */
void fn_8039B47C(const unsigned char* p, int* out)
{
    unsigned c0, A, B, C, E, G;
    out[11] = ((unsigned)p[0] * p[1]) >> 8;
    out[0] = ((unsigned)p[0] * (255U - p[1])) >> 8;
    c0 = 255U - p[0];
    out[1] = (c0 * p[2]) >> 8;
    A = (c0 * (255U - p[2])) >> 8;
    B = (A * p[3]) >> 8;
    out[2] = (B * p[4]) >> 8;
    C = (B * (255U - p[4])) >> 8;
    out[3] = (C * p[5]) >> 8;
    out[4] = (C * (255U - p[5])) >> 8;
    A = (A * (255U - p[3])) >> 8;
    E = (A * p[6]) >> 8;
    out[5] = (E * p[7]) >> 8;
    out[6] = (E * (255U - p[7])) >> 8;
    A = (A * (255U - p[6])) >> 8;
    G = (A * p[8]) >> 8;
    out[7] = (G * p[9]) >> 8;
    out[8] = (G * (255U - p[9])) >> 8;
    A = (A * (255U - p[8])) >> 8;
    out[9] = (A * p[10]) >> 8;
    out[10] = (A * (255U - p[10])) >> 8;
}

/* near-miss: same instruction count; scratch registers are numbered differently. */
void fn_8039B5D8(const unsigned char* p, int* out)
{
    unsigned t, u;
    t = ((unsigned)p[0] * p[1]) >> 8;
    out[0] = (t * p[2]) >> 8;
    out[1] = (t * (255U - p[2])) >> 8;
    t = ((unsigned)p[0] * (255U - p[1])) >> 8;
    out[2] = (t * p[3]) >> 8;
    out[3] = (t * (255U - p[3])) >> 8;
    u = ((((255U - p[0]) * p[4]) >> 8) * p[5]) >> 8;
    out[4] = (u * p[6]) >> 8;
    out[5] = (u * (255U - p[6])) >> 8;
    u = ((((255U - p[0]) * p[4]) >> 8) * (255U - p[5])) >> 8;
    out[6] = (u * p[7]) >> 8;
    out[7] = (u * (255U - p[7])) >> 8;
    out[8] = ((255U - p[0]) * (255U - p[4])) >> 8;
}

void fn_8039BC28(Vp6Hdr* h)
{
    MEMSET_V(&h->mCC[0], 0, 0x10);
    MEMSET_V(&h->mCC[1], 0, 0x10);
    MEMSET_V(&h->mCC[2], 0, 0x10);
    MEMSET_V(&h->mCC[3], 0, 0x10);
    h->mCC[0].m4 = -1;
    h->mCC[1].m4 = -1;
    h->mCC[2].m4 = -1;
    h->mCC[3].m4 = -1;
    h->mCC[0].m8 = 4;
    h->mCC[1].m8 = 4;
    h->mCC[2].m8 = 4;
    h->mCC[3].m8 = 4;
}

int fn_8039CC38(Vp6Ctx* c)
{
    Vp6Rc* rc = &c->m150;
    if (!fn_803A0E18(rc, 0xCD)) {
        return 0;
    }
    int sign = fn_803A0EBC(rc) * -2 + 1;
    if (!fn_803A0E18(rc, 0xAB)) {
        return sign << (3 - fn_803A0E18(rc, 0x53));
    }
    if (!fn_803A0E18(rc, 0xC7)) {
        if (fn_803A0E18(rc, 0x8C)) {
            return sign * 12;
        }
        if (fn_803A0E18(rc, 0x7D)) {
            return sign << 4;
        }
        if (fn_803A0E18(rc, 0x68)) {
            return sign * 20;
        }
        return sign * 24;
    }
    return (sign * fn_8039EF84(rc, 7)) << 2;
}

/* near-miss: 82 vs 84 insns; the original code keeps separate copies of the two table base pointers. */
void fn_8039CD38(Vp6Ctx* c)
{
    Vp6Rc* rc = &c->m150;
    int i;
    int j;
    for (i = 0; i <= 2; i++) {
        if (fn_803A0E18(rc, 0xAE)) {
            int idx = fn_8039EF84(rc, 4);
            const unsigned char* src = lbl_80608678 + (idx * 0x14 + i * 0x140);
            for (j = 0; j < 10; j++) {
                c->m72C[i].b[j] = src[j * 2];
                c->m72C[i].a[j] = src[j * 2 + 1];
            }
        }
        if (fn_803A0E18(rc, 0xFE)) {
            for (j = 0; j <= 9; j++) {
                int v = fn_8039CC38(c) + c->m72C[i].b[j];
                if (v >= 0) {
                    if (v > 255) v = 255;
                    c->m72C[i].b[j] = v;
                } else {
                    c->m72C[i].b[j] = 0;
                }
                v = fn_8039CC38(c) + c->m72C[i].a[j];
                if (v >= 0) {
                    if (v > 255) v = 255;
                    c->m72C[i].a[j] = v;
                } else {
                    c->m72C[i].a[j] = 0;
                }
            }
        }
    }
    fn_8039C980(c);
}

/* near-miss: callee-saved registers are allocated in a different order (stride r28, rows r30 in the original code). */
void fn_8039D058(unsigned char* src, unsigned char* dst, int cols, int rows, int stride)
{
    int i;
    int j;
    MEMCPY_V(dst, src, cols);
    rows--;
    for (i = 1; i < rows; i++) {
        unsigned char* prev = src;
        src += stride;
        unsigned char* next = src + stride;
        dst += stride;
        for (j = 0; j < cols; j++) {
            dst[j] = (prev[j] + src[j] * 2U + next[j] + 2) >> 2;
        }
    }
    MEMCPY_V(dst + stride, src + stride, cols);
}

void fn_8039E914(Vp6BitReader* br, const unsigned char* buf)
{
    br->m0 = buf;
    br->m4 = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
    br->m8 = 0x20;
    br->mC = 4;
}

unsigned fn_8039E958(Vp6BitReader* br, unsigned n)
{
    unsigned hi = 0;
    const unsigned char* buf = br->m0;
    unsigned pos = br->mC;
    unsigned bits = br->m8;
    unsigned cur = br->m4;
    const unsigned char* p = buf + pos;
    if (bits < n) {
        hi = cur >> (32 - bits);
        cur = (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + p[3];
        n -= bits;
        hi <<= n;
        pos += 4;
        bits = 0x20;
    }
    br->m4 = cur << n;
    br->m8 = bits - n;
    br->mC = pos;
    return hi | (cur >> (32 - n));
}

int fn_8039EF48(void* ctx)
{
    int r = 1;
    if (fn_8039E9E0(ctx) == 0) {
        r = 0;
    }
    return r;
}

int fn_8039EF84(Vp6Rc* br, int n)
{
    int v = 0;
    for (int i = n - 1; i >= 0; i--) {
        v |= fn_803A0EBC(br) << i;
    }
    return v;
}

void fn_8039EFD4(Vp6Ctx* c)
{
    if (c->m0) fn_80398614(c->m0);
    c->m0 = 0;
    c->m4 = 0;
    if (c->m14C) fn_80398614(c->m14C);
    c->m14C = 0;
    c->m148 = 0;
    if (c->m118) fn_80398614(c->m118);
    c->m118 = 0;
    c->m10C = 0;
    if (c->m11C) fn_80398614(c->m11C);
    c->m11C = 0;
    c->m110 = 0;
    if (c->m120) fn_80398614(c->m120);
    c->m120 = 0;
    c->m114 = 0;
    if (c->m6F8) fn_80398614(c->m6F8);
    c->m6F8 = 0;
    c->m6EC = 0;
    if (c->m700) fn_80398614(c->m700);
    c->m700 = 0;
    c->m6F4 = 0;
    if (c->m6FC) fn_80398614(c->m6FC);
    c->m6FC = 0;
    c->m6F0 = 0;
}

int fn_8039F0C0(Vp6Ctx* c)
{
    fn_8039EFD4(c);
    c->m0 = fn_803985F4(0x320, 0);
    if (c->m0 != 0) {
        c->m4 = ((int)c->m0 + 0x1F) & ~0x1F;
        c->m118 = fn_803985F4(c->m1F8 * 16 + 0xA0, 0);
        if (c->m118 != 0) {
            c->m10C = ((int)c->m118 + 0x1F) & ~0x1F;
            c->m11C = fn_803985F4(((c->m1F8 << 3) & ~0xF) + 0xA0, 0);
            if (c->m11C != 0) {
                c->m110 = ((int)c->m11C + 0x1F) & ~0x1F;
                c->m120 = fn_803985F4(((c->m1F8 << 3) & ~0xF) + 0xA0, 0);
                if (c->m120 != 0) {
                    c->m114 = ((int)c->m120 + 0x1F) & ~0x1F;
                    c->m6F8 = fn_803985F4(c->m228 + 0x20, 0);
                    if (c->m6F8 != 0) {
                        c->m6EC = ((int)c->m6F8 + 0x1F) & ~0x1F;
                        c->m6FC = fn_803985F4(c->m228 + 0x20, 0);
                        if (c->m6FC != 0) {
                            c->m6F0 = ((int)c->m6FC + 0x1F) & ~0x1F;
                            c->m700 = fn_803985F4(c->m228 * 4 + 0x20, 0);
                            if (c->m700 != 0) {
                                c->m6F4 = ((int)c->m700 + 0x1F) & ~0x1F;
                                c->m14C = fn_803985F4(c->m1FC * 4 + 0x20, 0);
                                if (c->m14C != 0) {
                                    c->m148 = ((int)c->m14C + 0x1F) & ~0x1F;
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fn_8039EFD4(c);
    return 0;
}

void fn_8039F264(Vp6Ctx* c)
{
    if (c->m248) fn_80398614(c->m248);
    if (c->m250) fn_80398614(c->m250);
    if (c->m258) fn_80398614(c->m258);
    if (c->m260) fn_80398614(c->m260);
    c->m248 = 0;
    c->m250 = 0;
    c->m258 = 0;
    c->m244 = 0;
    c->m24C = 0;
    c->m254 = 0;
    c->m260 = 0;
}

int fn_8039F2EC(Vp6Ctx* c, int n)
{
    int size = n + 0x20;
    fn_8039F264(c);
    c->m248 = fn_803985F4(c->m1B0.m8 + size, 0);
    if (c->m248 != 0) {
        c->m244 = ((int)c->m248 + 0x1F) & ~0x1F;
        c->m250 = fn_803985F4(c->m1B0.m8 + size, 0);
        if (c->m250 != 0) {
            c->m24C = ((int)c->m250 + 0x1F) & ~0x1F;
            c->m258 = fn_803985F4(c->m1B0.m8 + size, 0);
            if (c->m258 != 0) {
                c->m254 = ((int)c->m258 + 0x1F) & ~0x1F;
                return 1;
            }
        }
    }
    fn_8039F264(c);
    return 0;
}

/* near-miss: 28 slots; same instruction count, the flag/total temporaries get other callee-saved registers. */
int fn_8039F3A8(Vp6Ctx* c)
{
    if (c->m1A8 != 0) {
        fn_8039733C(c, 1, c->m1A8);
    }
    unsigned w, h, pw, ph, cols, rows, mbs, ysize, lsize, q, total;
    w = c->m1B0.m0;
    h = c->m1B0.m4;
    pw = w + 0x60;
    ph = h + 0x60;
    cols = w / c->m1B0.m10;
    rows = h / c->m1B0.m14;
    mbs = rows * cols;
    ysize = pw * ph;
    lsize = w * h;
    q = ysize / 4;
    total = ysize + q * 2;
    c->m1B0.m8 = pw;
    c->m1B0.mC = (int)pw / 2;
    c->m210 = 0;
    c->m21C = 0;
    c->m1F8 = cols;
    c->m1F4 = rows;
    c->m1FC = mbs * 3 / 2;
    c->m200 = mbs;
    c->m204 = mbs / 4;
    c->m1EC = lsize;
    c->m1F0 = lsize / 4;
    c->m208 = ysize;
    c->m20C = q;
    c->m214 = lsize;
    c->m218 = lsize + lsize / 4;
    c->m220 = ysize;
    c->m224 = ysize + q;
    c->m22C = (h >> 4) + 6 + ((h & 0xF) != 0);
    c->m230 = (w >> 4) + 6 + ((w & 0xF) != 0);
    c->m228 = c->m22C * c->m230;
    for (int i = 0; i < 12; i++) {
        c->m6A8[i] = lbl_80608AC8[i * 2] * c->m230 + lbl_80608AC8[i * 2 + 1];
    }
    fn_80396114(c->m298, &c->m1B0);
    if (!fn_8039F0C0(c)) {
        return 0;
    }
    if (!fn_8039F2EC(c, total)) {
        fn_8039EFD4(c);
        return 0;
    }
    if (c->m264 == 0 && c->m23C != 0) {
        if (c->m1B0.m0 != c->m23C || c->m1B0.m4 != c->m240) {
            c->m268 = fn_803985F4((((c->m23C + 0x20) * ((c->m240 + 0x20) * 3)) >> 1) + 0x20, 0);
            c->m264 = ((int)c->m268 + 0x1F) & ~0x1F;
        }
    }
    return 1;
}

void fn_8039F5BC(Vp6Ctx* c)
{
    c->m1B0.m10 = 8;
    c->m1B0.m14 = 8;
}

void fn_8039F5CC(Vp6Link* t, int idx, int* head)
{
    int cur = *head;
    int prev = cur;
    while (cur != -1 && t[idx].key > t[cur].key) {
        prev = cur;
        cur = t[cur].next;
    }
    if (cur == *head) {
        *head = idx;
        t[idx].next = cur;
    } else {
        t[prev].next = idx;
        t[idx].next = cur;
    }
}

int* fn_8039F94C(Vp6LimView* d, int n)
{
    int* base = d->m34 + 0x100;
    MEMSET_V(d->m34, 0, 0x800);
    for (int i = 0; i < n; i++) {
        base[-(n + i)] = -n + i;
        base[-i] = -i;
        base[i] = i;
        base[n + i] = n - i;
    }
    return base;
}

/* near-miss: same operations; the original code keeps the clip table address in r3 and picks other scratch registers. */
void fn_8039F9F8(void* unused, unsigned char* p, int stride, const int* lim)
{
    for (int i = 0; i < 8; i++) {
        int v = (p[0] - 3 * p[1] + 3 * p[2] - p[3] + 4) >> 3;
        int d = lim[v];
        p[1] = lbl_8069C140[p[1] + d];
        p[2] = lbl_8069C140[p[2] - d];
        p += stride;
    }
}

/* near-miss: same operations; the original code keeps the clip table address in r3 and picks other scratch registers. */
void fn_8039FA68(void* unused, unsigned char* p, int stride, const int* lim)
{
    for (int i = 0; i < 8; i++) {
        int v = (p[-2 * stride] - 3 * p[-stride] + 3 * p[0] - p[stride] + 4) >> 3;
        int d = lim[v];
        p[-stride] = lbl_8069C140[p[-stride] + d];
        p[0] = lbl_8069C140[p[0] - d];
        p++;
    }
}

/* near-miss: same operations; the original code keeps the clip table address in r3 and picks other scratch registers. */
void fn_8039FB00(int x, unsigned char* p, int stride)
{
    int lim = lbl_806EF458[x];
    int lim2 = lim * 2;
    for (int i = 0; i < 8; i++) {
        int v = p[-2] - 3 * p[-1] + 3 * p[0] - p[1] + 4;
        int s = v >> 31;
        int t = ((v >> 3) ^ s) - s;
        int r = 0;
        if (t < lim2) r = t;
        int w = r - lim;
        int sw = w >> 31;
        int e = lim - ((w ^ sw) - sw);
        e = (e + s) ^ s;
        p[-1] = lbl_8069C140[p[-1] + e];
        p[0] = lbl_8069C140[p[0] - e];
        p += stride;
    }
}

/* near-miss: same operations; the original code keeps the clip table address in r3 and picks other scratch registers. */
void fn_8039FBB0(int x, unsigned char* p, int stride)
{
    int lim = lbl_806EF458[x];
    int lim2 = lim * 2;
    for (int i = 0; i < 8; i++) {
        int v = p[-2 * stride] - 3 * p[-stride] + 3 * p[0] - p[stride] + 4;
        int s = v >> 31;
        int t = ((v >> 3) ^ s) - s;
        int r = 0;
        if (t < lim2) r = t;
        int w = r - lim;
        int sw = w >> 31;
        int e = lim - ((w ^ sw) - sw);
        e = (e + s) ^ s;
        p[-stride] = lbl_8069C140[p[-stride] + e];
        p[0] = lbl_8069C140[p[0] - e];
        p++;
    }
}

/* near-miss: 87 insns like the original code; the original keeps the clamped value in r0 and reloads the low byte (lbz) instead of copying it. */
void fn_8039FE10(unsigned char* dst, const short* src, int dstride, int sstride)
{
    int i;
    int v;
    unsigned char r;
    for (i = 0; i < 8; i++) {
        v = src[0];
        if (v >= 0) {
            r = 255;
            if (v <= 255) r = v;
        } else {
            r = 0;
        }
        dst[0] = r;
        v = src[1];
        if (v >= 0) {
            r = 255;
            if (v <= 255) r = v;
        } else {
            r = 0;
        }
        dst[1] = r;
        v = src[2];
        if (v >= 0) {
            r = 255;
            if (v <= 255) r = v;
        } else {
            r = 0;
        }
        dst[2] = r;
        v = src[3];
        if (v >= 0) {
            r = 255;
            if (v <= 255) r = v;
        } else {
            r = 0;
        }
        dst[3] = r;
        v = src[4];
        if (v >= 0) {
            r = 255;
            if (v <= 255) r = v;
        } else {
            r = 0;
        }
        dst[4] = r;
        v = src[5];
        if (v >= 0) {
            r = 255;
            if (v <= 255) r = v;
        } else {
            r = 0;
        }
        dst[5] = r;
        v = src[6];
        if (v >= 0) {
            r = 255;
            if (v <= 255) r = v;
        } else {
            r = 0;
        }
        dst[6] = r;
        v = src[7];
        if (v >= 0) {
            r = 255;
            if (v <= 255) r = v;
        } else {
            r = 0;
        }
        dst[7] = r;
        dst += dstride;
        src += sstride;
    }
}

void fn_8039FF6C(short* tmp, unsigned char* dst, const unsigned char* a, const unsigned char* b, const short* res, int stride)
{
    short* t = tmp;
    int i;
    for (i = 0; i < 8; i++) {
        t[0] = res[0] + ((a[0] + b[0]) >> 1);
        t[1] = res[1] + ((a[1] + b[1]) >> 1);
        t[2] = res[2] + ((a[2] + b[2]) >> 1);
        t[3] = res[3] + ((a[3] + b[3]) >> 1);
        t[4] = res[4] + ((a[4] + b[4]) >> 1);
        t[5] = res[5] + ((a[5] + b[5]) >> 1);
        t[6] = res[6] + ((a[6] + b[6]) >> 1);
        t[7] = res[7] + ((a[7] + b[7]) >> 1);
        a += stride;
        b += stride;
        res += 8;
        t += 8;
    }
    fn_8039FE10(dst, tmp, stride, 8);
}

void fn_803A00A0(const void* src, unsigned n, void* dst)
{
    MEMCPY_V(dst, src, n);
}

void fn_803A00D8()
{
}

/* near-miss: weights and structure as in the original code; load and multiply scheduling differ (67 vs 62 insns). */
void fn_803A00DC(const unsigned char* src, unsigned n, unsigned char* dst)
{
    unsigned i;
    n -= 4;
    for (i = 0; i < n; i += 4) {
        unsigned s0 = src[0], s1 = src[1], s2 = src[2], s3 = src[3], s4 = src[4];
        dst[0] = s0;
        dst[1] = (s0 * 0x33U + s1 * 0xCDU + 0x80) >> 8;
        dst[2] = (s1 * 0x66U + s2 * 0x9AU + 0x80) >> 8;
        dst[3] = (s2 * 0x9AU + s3 * 0x66U + 0x80) >> 8;
        dst[4] = (s3 * 0xCDU + s4 * 0x33U + 0x80) >> 8;
        src += 4;
        dst += 5;
    }
    {
        unsigned s0 = src[0], s1 = src[1], s2 = src[2], s3 = src[3];
        dst[0] = s0;
        dst[1] = (s0 * 0x33U + s1 * 0xCDU + 0x80) >> 8;
        dst[2] = (s1 * 0x66U + s2 * 0x9AU + 0x80) >> 8;
        dst[3] = (s2 * 0x9AU + s3 * 0x66U + 0x80) >> 8;
        dst[4] = s3;
    }
}

/* near-miss: 4 slots, order of the first two loads and multiplies. */
void fn_803A01D4(unsigned char* p, int s, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        unsigned p0 = p[0];
        unsigned p1 = p[s];
        p[s] = (p0 * 0x33U + p1 * 0xCDU + 0x80) >> 8;
        unsigned p2 = p[2 * s];
        unsigned p3 = p[3 * s];
        p[2 * s] = (p1 * 0x66U + p2 * 0x9AU + 0x80) >> 8;
        p[3 * s] = (p2 * 0x9AU + p3 * 0x66U + 0x80) >> 8;
        unsigned p5 = p[5 * s];
        p[4 * s] = (p3 * 0xCDU + p5 * 0x33U + 0x80) >> 8;
        p++;
    }
}

void fn_803A0288(unsigned char* p, int s, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        unsigned p0 = p[0];
        unsigned p1 = p[s];
        p[s] = (p0 * 0x33U + p1 * 0xCDU + 0x80) >> 8;
        unsigned p2 = p[2 * s];
        unsigned p3 = p[3 * s];
        p[2 * s] = (p1 * 0x66U + p2 * 0x9AU + 0x80) >> 8;
        p[3 * s] = (p2 * 0x9AU + p3 * 0x66U + 0x80) >> 8;
        p[4 * s] = p3;
        p++;
    }
}

}
