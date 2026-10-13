/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x8038BC58-0x8038EC58 (code-only unit, 58 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

#include "../../include/ealib/tu_8038BC58.h"

inline void* operator new(unsigned, void* p)
{
    return p;
}

struct DtorAt0 { const void* m; };

struct VdQ16 {
    int m0;
    int m4;
    int m8;
    int mC;
};
struct LowMem {
    char pad[0xF8];
    unsigned busClock;
    unsigned cpuClock;
};
#define LOWMEM ((LowMem*)0x80000000)

extern "C" int fn_803A975C();
extern "C" int fn_803A979C();
extern "C" int fn_803AB8A4(int h, void* out);
extern "C" int fn_803AB644(int h, void* out);
extern "C" int fn_8038E468(VdClock* c);
extern "C" unsigned fn_8038E080(VdMain* s);
extern "C" int fn_803A925C();
extern unsigned lbl_800000F8;


extern "C" void fn_8038C058(DtorAt0*, int);
extern "C" void fn_8038E61C(VdRes* o, int chrg);

extern "C" VdMain* fn_8038BCD0(VdMain* p, int a, int b, int c);
extern "C" void fn_803D9E00(void* a, int* b, int* c);

extern "C" VdMain* fn_8038BC58(int a, int b, int unused, char* c)
{
    int sp8;
    int spC;
    fn_803D9E00(c + 0x10, &sp8, &spC);
    VdMain* p = (VdMain*)lbl_80699B94.m0("", 0x98, 0, 0, lbl_80699B94.m8);
    return fn_8038BCD0(p, a, b, spC);
}

extern "C" void fn_8038BF80(VdFilter* o, float a, float b, float c)
{
    o->m84 = o->m70 * o->m8C + a;
    o->m88 = o->m74 * o->m90 + b;
    o->m7C = a;
    o->m80 = b;
    o->m78 = c;
}

extern "C" void fn_8038BFB0(VdFilter* o, float a, float b)
{
    o->m84 = o->m70 * a + o->m7C;
    o->m8C = a;
    o->m90 = b;
    o->m88 = o->m74 * b + o->m80;
}

extern "C" void fn_8038C6E0(VdMain* self, int v)
{
    if (self->m6C != 0)
        fn_8038EA64(self->m0, self->m6C);
    self->m6C = v;
    ((void (*)(VdMain*))fn_8038C058)(self);
}

extern "C" void fn_8038C72C(DtorAt0* s, int chrg)
{
    fn_8038C058(s, chrg);
}

extern "C" void fn_8038C74C()
{
}

struct DtorAt4 { char pad[0x4]; const void* m; };

extern char lbl_80605EC8[];

extern "C" void fn_80377408(void* p);

extern "C" void fn_8038C750(DtorAt4* self, int chrg)
{
    self->m = lbl_80605EC8;
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" void fn_8038C784()
{
}

extern "C" void fn_8038C788(VdBufs* s)
{
    fn_8038D110((char*)s->m600);
    fn_8038D110((char*)s->m604);
    lbl_80699B94.m4(s);
}

/* 8038BFDC */
VdMain::~VdMain()
{
    fn_8038C788(m8);
    if (m6C != 0)
        fn_8038EA64(m0, m6C);
}

extern "C" void GXInitTlutObj(void* obj, void* data, int fmt, int n);
extern "C" void fn_80432FD4(void* p, int n);
extern "C" int fn_8038D170(int x);
/* near-miss (96.4%): retail loads the 0x4330 high word into r4 and the byte 255 into r5; ours has them swapped (4 slots). */
extern "C" unsigned char* fn_8038C7D4(int a, int b)
{
    unsigned char* t = (unsigned char*)lbl_80699B94.m0("VD::tBigSwizzler", 0x640, 0x20, 0, lbl_80699B94.m8);
    unsigned char* u = t + 0x200;
    unsigned char* v = t + 0x400;
    *(int*)(t + 0x600) = fn_8038D170(a);
    *(int*)(t + 0x604) = fn_8038D170(b);
    for (int i = 0; i < 256; i++) {
        t[i * 2] = 0xFF;
        t[i * 2 + 1] = i;
        t[0x200 + i * 2] = (int)(((float)i - 128.0f) * 0.701f + 128.0f);
        t[0x201 + i * 2] = (int)(((float)i - 128.0f) * -0.35705f + 85.333336f);
        t[0x400 + i * 2] = (int)(((float)i - 128.0f) * -0.17205f + 42.666668f);
        t[0x401 + i * 2] = (int)(((float)i - 128.0f) * 0.886f + 128.0f);
    }
    fn_80432FD4(t, 0x200);
    fn_80432FD4(u, 0x200);
    fn_80432FD4(v, 0x200);
    GXInitTlutObj(t + 0x608, t, 0, 0x100);
    GXInitTlutObj(t + 0x614, u, 0, 0x100);
    GXInitTlutObj(t + 0x620, v, 0, 0x100);
    return t;
}

struct GXColor {
    unsigned char r, g, b, a;
};
struct GXTexSize {
    unsigned w;
    unsigned h;
};
extern "C" {
void GXSetIndTexCoordScale(int id, int s, int t);
void GXInitTexObjLOD(void* obj, int a, int b, float x, float y, float z, int c, int d, int e);
void GXLoadTlut(void* tlut, int id);
void GXLoadTexObj(void* obj, int id);
void GXSetTevKColor(int id, GXColor c);
void GXSetTevSwapModeTable(int id, int a, int b, int c, int d);
void GXSetNumTexGens(int n);
void GXSetTexCoordGen2(int a, int b, int c, int d, int e, int f);
void GXSetIndTexMtx(int id, float* m, int scale);
void GXSetNumIndStages(int n);
void GXSetIndTexOrder(int a, int b, int c);
void GXSetTevIndirect(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
void GXSetNumTevStages(int n);
void GXSetTevOrder(int a, int b, int c, int d);
void GXSetTevIndRepeat(int n);
void GXSetTevColorOp(int a, int b, int c, int d, int e, int f);
void GXSetTevColorIn(int a, int b, int c, int d, int e);
void GXSetTevAlphaOp(int a, int b, int c, int d, int e, int f);
void GXSetTevAlphaIn(int a, int b, int c, int d, int e);
void GXSetTevSwapMode(int a, int b, int c);
void GXSetTevKColorSel(int a, int b);
}
#define F0 0.0f
#define K 0.0625f

/* near-miss (99.96%): same 420 instructions; only the frame size (0x88 vs 0x78) and the conv-temp displacement differ: retail
   has 16 more bytes of locals between cb and the unsigned->float temp (an unused local array or spill slots; none of the
   spellings tried reproduces a slot there). GX calls are fn_ names (no SDK names in symbols.txt yet). */
extern "C" void fn_8038C99C(VdBufs* s, void* t1, void* t2, void* t3)
{
    GXColor kt;
    GXColor ca = { 0xff, 0xff, 0, 0 };
    GXColor cb = { 0, 0xff, 0xff, 0 };
    GXTexSize* p1 = (GXTexSize*)s->m604;
    char* p0 = (char*)s->m600;
    float m[6];
    GXSetIndTexCoordScale(0, 0, 0);
    GXSetIndTexCoordScale(1, 0, 0);
    GXSetIndTexCoordScale(2, 0, 0);
    GXSetIndTexCoordScale(3, 0, 0);
    GXInitTexObjLOD(t3, 0, 0, F0, F0, F0, 0, 0, 0);
    GXInitTexObjLOD(t2, 0, 0, F0, F0, F0, 0, 0, 0);
    GXInitTexObjLOD(t1, 0, 0, F0, F0, F0, 0, 0, 0);
    GXLoadTlut((char*)s + 0x620, 0);
    GXLoadTlut((char*)s + 0x614, 1);
    GXLoadTlut((char*)s + 0x608, 2);
    GXLoadTexObj(t3, 0);
    GXLoadTexObj(t2, 1);
    GXLoadTexObj(t1, 2);
    GXLoadTexObj((char*)p1 + 0x14, 3);
    GXLoadTexObj((char*)p1 + 0x40, 4);
    GXLoadTexObj(p0 + 0x14, 5);
    GXLoadTexObj(p0 + 0x40, 6);
    kt = ca;
    GXSetTevKColor(0, kt);
    kt = cb;
    GXSetTevKColor(1, kt);
    GXSetTevSwapModeTable(1, 3, 0, 0, 0);
    GXSetTevSwapModeTable(2, 1, 3, 1, 1);
    GXSetNumTexGens(2);
    GXSetTexCoordGen2(0, 1, 0xc, 0x3c, 0, 0x7d);
    GXSetTexCoordGen2(1, 1, 0xc, 0x3c, 0, 0x7d);
    m[0] = (float)(unsigned)p1->w * K;
    m[1] = F0;
    m[4] = (float)(unsigned)p1->h * K;
    m[3] = F0;
    m[2] = F0;
    m[5] = F0;
    GXSetIndTexMtx(1, m, 4);
    m[0] = K;
    m[4] = K;
    m[1] = F0;
    m[3] = F0;
    m[2] = F0;
    m[5] = F0;
    GXSetIndTexMtx(2, m, 4);
    GXSetNumIndStages(4);
    GXSetIndTexOrder(0, 0, 3);
    GXSetTevIndirect(0, 0, 0, 0, 1, 6, 6, 0, 0, 0);
    GXSetIndTexOrder(1, 0, 4);
    GXSetTevIndirect(1, 1, 0, 2, 2, 6, 0, 1, 0, 0);
    GXSetIndTexOrder(2, 1, 5);
    GXSetTevIndirect(3, 2, 0, 0, 1, 6, 6, 0, 0, 0);
    GXSetIndTexOrder(3, 1, 6);
    GXSetTevIndirect(4, 3, 0, 2, 2, 6, 0, 1, 0, 0);
    GXSetNumTevStages(5);
    GXSetTevOrder(0, 0, 0, 0xff);
    GXSetTevOrder(1, 0, 0, 0xff);
    GXSetTevIndRepeat(2);
    GXSetTevOrder(2, 0, 1, 0xff);
    GXSetTevOrder(3, 1, 2, 0xff);
    GXSetTevOrder(4, 1, 2, 0xff);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(0, 0xf, 0xf, 0xf, 0xf);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 0xf, 8, 0xe, 0xf);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 7);
    GXSetTevSwapMode(1, 1, 2);
    GXSetTevKColorSel(1, 0xd);
    GXSetTevColorOp(2, 0, 2, 1, 0, 0);
    GXSetTevColorIn(2, 0xf, 8, 0xe, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(2, 7, 7, 7, 7);
    GXSetTevSwapMode(2, 1, 1);
    GXSetTevKColorSel(2, 0xc);
    GXSetTevColorOp(3, 0, 0, 0, 0, 0);
    GXSetTevColorIn(3, 0xf, 0xf, 0xf, 0);
    GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(3, 7, 7, 7, 7);
    GXSetTevColorOp(4, 0, 0, 0, 1, 0);
    GXSetTevColorIn(4, 8, 0xf, 0xf, 0);
    GXSetTevAlphaOp(4, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(4, 7, 7, 7, 4);
}

extern "C" void fn_8038D02C(VdTile* t, unsigned a, unsigned b, unsigned c, unsigned d)
{
    t->m0 = a;
    t->m4 = b;
    t->m8 = c;
    unsigned cm = c - 1;
    t->mC = d;
    unsigned dm = d - 1;
    t->m10 = (cm + a) / a;
    t->m14 = (dm + b) / b;
    t->m18 = a * b;
}

extern "C" void fn_8038D068(int* out, unsigned x, unsigned y, VdTile* t)
{
    unsigned lin = y * t->m8 + x;
    unsigned a = x % t->m0 + (lin / t->m18 % t->m10) * t->m0;
    unsigned q = lin % t->m18 / t->m0;
    unsigned r = y / t->m4;
    out[0] = a;
    out[1] = q + r * t->m4;
}

extern "C" int fn_8038D0E0(int x, int y, int w)
{
    return ((((y >> 2) * ((w + 3) >> 2)) + (x >> 2)) << 5) + (((y & 3) << 3) + ((x & 3) << 1));
}

extern "C" void fn_8038D110(char* o)
{
    lbl_80699B94.m4(*(void**)(o + 0x10));
    lbl_80699B94.m4(*(void**)(o + 0x3C));
    lbl_80699B94.m4(o);
}

/* Swizzled-texture record built by fn_8038D170: block size m0/m4, size m8/mC, two swizzle maps (m10, m3C) with GX texture objects at +0x14 and +0x40. */
struct VdSwz {
    int m0;
    int m4;
    unsigned m8;
    unsigned mC;
    unsigned char* m10;
    char pad14[0x34 - 0x14];
    unsigned m34;
    unsigned m38;
    unsigned char* m3C;
    char pad40[0x60 - 0x40];
};
extern "C" unsigned GXGetTexObjWidth(int tex);
extern "C" unsigned GXGetTexObjHeight(int tex);
extern "C" int GXGetTexObjFmt(int tex);
extern "C" void GXInitTexObj(void* obj, void* img, int w, int h, int fmt, int ws, int wt, int mip);
extern "C" void GXInitTexObjLOD(void* obj, int a, int b, float x, float y, float z, int c, int d, int e);
extern char lbl_80605F5C[];

struct VdM2 {
    char pad0[0x64];
    int m64;
    char pad68[0x7C - 0x68];
    VdA m7C[2];
};
extern "C" void fn_8038D57C(VdM2* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern "C" int fn_8038D170(int tex)
{
    unsigned bw = 0;
    unsigned bh = 0;
    unsigned w = GXGetTexObjWidth(tex);
    unsigned h = GXGetTexObjHeight(tex);
    switch (GXGetTexObjFmt(tex)) {
    case 0:
    case 8:
        bw = 8;
        bh = 8;
        break;
    case 1:
    case 2:
    case 9:
        bw = 8;
        bh = 4;
        break;
    case 3:
    case 4:
    case 5:
        bw = 4;
        bh = 4;
        break;
    }
    VdTile t;
    int sp[2];
    fn_8038D02C(&t, bw, bh, w, h);
    unsigned y = 0;
    const char* nm = lbl_80605F5C;
    VdSwz* p = (VdSwz*)lbl_80699B94.m0(nm, 0x60, 0, 0, lbl_80699B94.m8);
    p->m0 = bw;
    p->m4 = bh;
    p->m8 = w;
    p->mC = bh;
    unsigned sz = w * bh * 2;
    p->m10 = (unsigned char*)lbl_80699B94.m0(nm, sz, 0x20, 0, lbl_80699B94.m8);
    p->m34 = w;
    p->m38 = bh;
    p->m3C = (unsigned char*)lbl_80699B94.m0(nm, sz, 0x20, 0, lbl_80699B94.m8);
    for (; y < p->mC; y++) {
        for (unsigned x = 0; x < p->m8; x++) {
            fn_8038D068(sp, x, y, &t);
            int idx = fn_8038D0E0(x, y, p->m34);
            idx = idx / 2 * 2;
            unsigned char* q = p->m10 + idx;
            q[0] = (unsigned)sp[0] / bw;
            q[1] = (unsigned)sp[1] / bh;
        }
    }
    GXInitTexObj((char*)p + 0x14, p->m10, (unsigned short)p->m8, (unsigned short)p->mC, 3, 0, 1, 0);
    y = 0;
    GXInitTexObjLOD((char*)p + 0x14, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    for (; y < p->m38; y++) {
        for (unsigned x = 0; x < p->m34; x++) {
            fn_8038D068(sp, x, y, &t);
            int idx = fn_8038D0E0(x, y, p->m34);
            idx = idx / 2 * 2;
            unsigned char* q = p->m3C + idx;
            q[0] = (unsigned)sp[0] % bw;
            q[1] = (unsigned)sp[1] % bh - y + 0x80;
        }
    }
    GXInitTexObj((char*)p + 0x40, p->m3C, (unsigned short)p->m34, (unsigned short)p->m38, 3, 0, 1, 0);
    GXInitTexObjLOD((char*)p + 0x40, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    fn_80432FD4(p->m10, p->m8 * p->mC * 2);
    fn_80432FD4(p->m3C, p->m34 * p->m38 * 2);
    return (int)p;
}

extern "C" VdM2* fn_8038D4E4(VdM2* self, int a, int b, int c, int d)
{
    self->m64 = 0;
    VdA* p = self->m7C;
    int n = 1;
    do {
        new (p) VdA;
        p++;
    } while (n-- != 0);
    fn_8038D57C(self, a, 0, b, 0, 0, 0, 0, 0, c, d);
    return self;
}

extern "C" int fn_8038DDE8(VdMain* s, float f)
{
    s->m48 = f;
    s->m78 = fn_8038E9D8(s->m68, (unsigned)f);
    s->m44 = fn_8038E944(s->m68);
    return s->m78;
}

extern "C" int fn_8038DE6C(VdMain* s)
{
    unsigned t = fn_8038E080(s);
    float f = fn_8038E98C(s->m68);
    t += s->m40;
    float r = (float)t * 0.001f * f;
    s->m48 = r;
    return r > (float)s->m44;
}

extern "C" int fn_8038E748(VdRes* o);

extern "C" int fn_8038DF08(int* s)
{
    VdRes* p = *(VdRes**)s;
    return p ? fn_8038E748(p) : 1;
}

extern "C" int fn_8038DF3C(I* s, unsigned rate)
{
    if (rate > 0x4000)
        rate = 0x4000;
    if (s->m0 != 0)
        fn_8038E694(s->m0, rate);
    VdClock* c = s->m60;
    unsigned long long t = fn_80438628();
    if (c->m10 == 0x1000)
        c->m8 += t - c->m0;
    else
        c->m8 += ((unsigned long long)c->m10 * (t - c->m0)) >> 12;
    c->m0 = t;
    c->m10 = rate;
    return 0;
}

extern "C" void fn_8038E038(I* i)
{
    fn_8038DF3C(i, 0);
}

extern "C" void fn_8038E05C(I* p)
{
    fn_8038DF3C(p, 0x1000);
}

extern "C" int fn_8038E1A8(int a, int b);

/* near-miss (99.46%): only the r9/r11 assignment of the shifted value and the zero in the last block differs. */
extern "C" unsigned fn_8038E080(VdMain* s)
{
    VdClock* c = s->m60;
    fn_8038E468(c);
    unsigned tk = c->m8 / (LOWMEM->busClock / 4000);
    int t = tk - s->m4C;
    if (s->m58 != 0) {
        struct { int w, x, y, z; } b;
        struct { int w, x, y, z; } a;
        fn_803A975C();
        fn_803AB8A4(s->m0->mC, &a);
        fn_803AB644(a.x, &b);
        fn_803A979C();
        int v = b.x - fn_803A925C();
        if (v > s->m54) {
            int diff = v - t;
            s->m54 = v;
            s->m5C = s->m5C - s->m5C / 8 + diff;
            int ad = -s->m5C;
            if (ad < s->m5C)
                ad = s->m5C;
            if (ad > 0x108) {
                int m = s->m4C - s->m5C / 8;
                s->m5C = 0;
                s->m4C = m;
                t = tk - s->m4C;
            }
        }
    }
    return t;
}

extern "C" int fn_8038E3EC(int a, int* b)
{
    return fn_8038E1A8(*b, a);
}

extern "C" int fn_803FE7E0(int a, int b);

extern "C" int fn_8038E418(char* a, int* b)
{
    return fn_803FE7E0(*(int*)(a + 0x30), *b);
}

extern "C" int fn_8038E440(int a, int* b, int c)
{
    return fn_8038E418((char*)*b, (int*)c);
}

extern "C" int fn_8038E468(VdClock* c)
{
    unsigned long long t = fn_80438628();
    if (c->m10 == 0x1000)
        c->m8 += t - c->m0;
    else
        c->m8 += ((unsigned long long)c->m10 * (t - c->m0)) >> 12;
    c->m0 = t;
}

extern "C" int fn_803AC11C();
extern "C" void fn_804005DC();
extern "C" void fn_803A9204(void* out);
extern "C" int fn_803AB4E0(int a, int b);
extern "C" int fn_803AB13C(int a, void* b, int c, int d, int e, int f);
extern "C" int fn_803AB5C8(int a, int b, int c);
struct VdRes2 {
    float m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
extern "C" VdRes2* fn_8038E534(VdRes2* o, int a, int b)
{
    if (fn_803AC11C() == 0) {
        fn_804005DC();
    } else {
        char q[24];
        o->m4 = 0;
        o->m10 = -1;
        o->mC = -1;
        fn_803A9204(q);
        int sz = fn_803AB4E0(1, 0x1E);
        int p = (int)lbl_80699B94.m0("AV::audiobuff", sz, 0, 0, lbl_80699B94.m8);
        o->m4 = p;
        o->mC = fn_803AB13C(a, q, 1, 0x1E, p, sz);
        o->m10 = fn_803AB5C8(o->mC, -1, b);
        o->m0 = 1.0f;
    }
    return o;
}

extern "C" void fn_803AA95C(int a);
extern "C" int fn_803AB56C(int a, int b);
extern "C" int fn_803AB3D8(int a, int b);

extern "C" void fn_8038E61C(VdRes* o, int chrg)
{
    if (o->m4 != 0) {
        fn_803AA95C(o->mC);
        lbl_80699B94.m4(o->m4);
        o->m4 = 0;
    }
    if (chrg & 1)
        lbl_80699B94.m4(o);
}

extern "C" int fn_8038E694(VdRes* o, int a)
{
    if (o->mC != -1) {
        fn_803A975C();
        int r = fn_803AB56C(o->mC, a);
        fn_803A979C();
        return r;
    }
    return 0;
}

extern "C" int fn_8038E6F0(VdRes* o)
{
    if (o->m10 != -1) {
        fn_803A975C();
        int r = fn_803AB3D8(o->m10, 0);
        fn_803A979C();
        return r;
    }
    return 0;
}

/* Static object: allocator hooks. m0 = allocate(tag, size, 0, 0, m8), m4 = free(ptr), filled in at run time;
 * the compiler-made static initializer is 0x8038EB78 (with 0x8038EBCC, 0x8038EC00 and 0x8038EC2C after it). */
VdC lbl_80699B94;


extern "C" int fn_8038E748(VdRes* o)
{
    VdQ16 a;
    VdQ16 b;
    fn_803A975C();
    if (fn_803AB8A4(o->mC, &b) >= 0 && fn_803AB644(b.m4, &a) >= 0) {
        fn_803A979C();
        return a.m8 == 0;
    }
    fn_803A979C();
    return 0;
}

/* 8038E7B8 */
VdC::VdC()
{
    m0 = 0;
    m4 = 0;
}

/* 8038E7D8 */
VdD::VdD(const VdB* s)
{
    m4 = *s;
    m14 = 0;
    m0 = 0;
}

extern "C" int fn_8038E8A4(VdCbObj* s, VdObj5* obj, int v)
{
    s->m0 = v;
    s->m14 = obj;
    obj->v2(s);
}

extern "C" void fn_8038E8EC(VdCbObj* s)
{
    VdObj5* p = s->m14;
    if (p != 0) {
        delete p;
        s->m14 = 0;
    }
}

/* 8038E84C */
VdD::~VdD()
{
    fn_8038E8EC((VdCbObj*)this);
}

extern "C" int fn_8038E944(VdCbObj* s)
{
    VdObj5* p = s->m14;
    if (p == 0)
        return 0;
    return p->v4();
}

extern "C" float fn_8038E98C(VdCbObj* s)
{
    VdObj5* p = s->m14;
    if (p == 0)
        return 0.0f;
    return p->v5();
}

extern "C" int fn_8038E9D8(VdCbObj* s, int a)
{
    if (s->m14 == 0 && s->m0 == 0)
        s->m8(s, s->m4, (int*)s);
    if (s->m14 == 0)
        return 0;
    return s->m14->v3(a);
}

extern "C" int fn_8038EA64(VdCbObj* h, int)
{
    return h->m14->v6();
}

extern "C" int fn_8038EA9C(VdCbObj* s)
{
    int v = s->m0;
    if (v != 0) {
        s->m0 = 0;
        return v;
    }
    s->m8(s, s->m4, &v);
    return v;
}

extern "C" void fn_8038EAF4(VdCb* s, int b)
{
    s->mC(s, s->m4, b);
}

/* 8038EB28 */
VdA::VdA()
{
    m4 = 0;
    m8 = 0;
    m0 = 0;
}

/* 8038EB40 */
VdB::VdB()
{
    mC = 2;
    m0 = 0;
    m4 = 0;
    m8 = 0;
}

/* 8038EB60 */
VdB::VdB(int a, int b, int c, int d)
{
    mC = d;
    m0 = a;
    m4 = b;
    m8 = c;
}

struct DtorAtC { char pad[0xc]; const void* m; };

extern char lbl_80606108[];

/* 8038EBCC: deleting dtor of VdC (the class's own copy is linkonce and unpairable). */
extern "C" void fn_8038EBCC(DtorAtC* self, int chrg)
{
    self->m = lbl_80606108;
    if (chrg & 1)
        fn_80377408(self);
}

/* 8038D9B4 */
struct VdA2 {
    int m0;
    int m4;
    int m8;
    ~VdA2() {}
};
struct VdAlloc {
    int op;
    int pad4;
    void (*fn)(void*);
    int padC[3];
};
extern "C" void fn_803FDC80(int p);
extern "C" void fn_803FACFC(VdAlloc* a);
class VdX2 {
public:
    VdRes* m0;
    void* m4;
    void* m8;
    char padC[8];
    int m14;
    char pad18[8];
    void* m20;
    char pad24[4];
    void* m28;
    char pad2C[4];
    int m30;
    int m34;
    char pad38[0x28];
    void* m60;
    char pad64[4];
    VdD* m68;
    char pad6C[0x10];
    VdA2 m7C[2];
    ~VdX2();
    void operator delete(void* p) { lbl_80699B94.m4(p); }
};
VdX2::~VdX2()
{
    if (m68 != 0) {
        delete m68;
        m68 = 0;
    }
    if (m0 != 0) {
        fn_8038E61C(m0, 3);
        m0 = 0;
    }
    if (m60 != 0) {
        lbl_80699B94.m4(m60);
        m60 = 0;
    }
    fn_803FDC80(m30);
    m30 = 0;
    if (m14 != 0) {
        fn_803FDC80(m34);
        m34 = 0;
    }
    void* p = m20;
    if (p != 0) {
        VdAlloc a;
        a.op = 0x14;
        fn_803FACFC(&a);
        a.fn(p);
        m20 = 0;
    }
    void* q = m28;
    if (q != 0) {
        VdAlloc a;
        a.op = 0x14;
        fn_803FACFC(&a);
        a.fn(q);
        m28 = 0;
    }
    if (m4 != 0) {
        lbl_80699B94.m4(m4);
        m4 = 0;
    }
    if (m8 != 0) {
        lbl_80699B94.m4(m8);
        m8 = 0;
    }
}
