/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x8039B3E4-0x803A0310 (code-only unit, 47 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
#include "../../include/game/tu_803959E0.h"

/* Bit reader over a big-endian byte buffer (fn_8039E914 initialises it). */
struct Vp6BitReader {
    const unsigned char* m0;
    unsigned m4;
    unsigned m8;
    unsigned mC;
};

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

struct Vp6Link {
    int next;
    int key;
    int pad;
};

extern unsigned char lbl_8069C140[];
extern const int* lbl_806EF458;

extern "C" {

void fn_80398614(void* p);
void* fn_803985F4(int size, int flags);
int fn_803A0EBC(Vp6BitReader* br);
int fn_8039E9E0(void* ctx);
void fn_8039F264(Vp6Ctx* c);

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

int fn_8039EF84(Vp6BitReader* br, int n)
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
