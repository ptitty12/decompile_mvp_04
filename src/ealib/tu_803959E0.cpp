/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803959E0-0x80397CAC (code-only unit, 43 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
#include "../../include/game/tu_803959E0.h"

extern Vp6Allocator* lbl_806EE9C0;
extern int lbl_806EF39C;
extern int lbl_806EF448;
extern int lbl_806EF44C;
extern int lbl_806EF450;
extern int lbl_806EF454;
extern int lbl_806EF458;
extern const short lbl_80607A68[];
#define lbl_80607A68u ((const unsigned short*)lbl_80607A68)
extern int lbl_8069BF40[];
extern unsigned char lbl_8069C040[];
extern int lbl_8069C6A8[];
extern char lbl_8069C4A0;
extern const char lbl_8062457C[];
extern const char lbl_8062467C[];
extern const char lbl_8062477C[];
extern const char lbl_80624C7C[];
extern const char lbl_80624D7C[];
extern const char lbl_80624E7C[];
extern const Vp6Blk100 lbl_80607468;
extern const int lbl_80608068[];
extern const int lbl_80608168[];
extern const Vp6Blk100 lbl_80607568;
extern const unsigned short lbl_80607A68s[];
extern const unsigned short lbl_80607AE8[];
extern void (*lbl_806EF410)(Vp6Tbl*, int);
extern const double lbl_80607418[];
extern const double lbl_80607420[];

extern const char lbl_80608490[];
extern const char lbl_806084A0[];
extern const char lbl_806084A4[];
extern int lbl_806EE9C8;

extern "C" {
void* fopen(const char* path, const char* mode);
int fprintf(void* f, const char* fmt, ...);
int fclose(void* f);
void fn_8039E914(Vp6BitReader* br, const unsigned char* buf);
int fn_8039EF48(Vp6Ctx* c);
void fn_80398634(Vp6Rc* rc, const unsigned char* buf);
void fn_8039C63C(Vp6Ctx* c);
void fn_8039868C(Vp6Buf* b, unsigned char* base);
void fn_80395A94(Vp6Ctx* c);
int fn_80395B38(Vp6Ctx* c);
void fn_80395E18(int* a, int* b, int* c, unsigned d);
void fn_80395F00(Vp6Buf* b);
Vp6Buf* fn_8039620C(const Vp6Params* p);
void fn_80396114(Vp6Buf* b, const Vp6Params* p);
double fn_8040FCA0(double x);
double fn_804101AC(double x);
void* fn_803985F4(int size, int flags);
void fn_80398614(void* p);
void fn_80396DA8(Vp6TblHolder* h);
void fn_80396274(Vp6SubB* b);
void fn_8039894C(Vp6Buf* b, int v, int s);
int fn_8039F3A8(Vp6Ctx* c);
void fn_8039EFD4(Vp6Ctx* c);
void fn_8039F264(Vp6Ctx* c);
void fn_8039F5BC(Vp6Ctx* c);
void fn_803962CC(Vp6Buf* b, int v);
int fn_8039847C();
void fn_80398484();
void fn_80397CAC();
void fn_80398324(unsigned d);
}

extern "C" {

void* fn_803959E0(int size)
{
    Vp6Allocator* a = lbl_806EE9C0;
    if (a != 0) {
        return a->Alloc(size, Vp6AllocArgs());
    }
    return fn_8000E5BC(size);
}

void fn_80395A44(void* p)
{
    Vp6Allocator* a = lbl_806EE9C0;
    if (a != 0) {
        a->Free(p, 0);
    } else {
        fn_8040ABC4(p);
    }
}

void fn_80395A94(Vp6Ctx* c)
{
    if (c->m274) fn_80398614(c->m274);
    if (c->m28C) fn_80398614(c->m28C);
    if (c->m288) fn_80398614(c->m288);
    if (c->m280) fn_80398614(c->m280);
    if (c->m268) fn_80398614(c->m268);
    c->m274 = 0;
    c->m28C = 0;
    c->m288 = 0;
    c->m280 = 0;
    c->m268 = 0;
    c->m270 = 0;
    c->m290 = 0;
    c->m284 = 0;
    c->m27C = 0;
    c->m264 = 0;
}

int fn_80395B38(Vp6Ctx* c)
{
    fn_80395A94(c);
    c->m274 = fn_803985F4(0xA0, 0);
    if (c->m274 != 0) {
        c->m270 = ((int)c->m274 + 0x1F) & ~0x1F;
        c->m288 = fn_803985F4(0xA0, 0);
        if (c->m288 != 0) {
            c->m284 = ((int)c->m288 + 0x1F) & ~0x1F;
            c->m28C = fn_803985F4(0x120, 0);
            if (c->m28C != 0) {
                c->m290 = ((int)c->m28C + 0x1F) & ~0x1F;
                c->m280 = fn_803985F4(0xA0, 0);
                if (c->m280 != 0) {
                    c->m27C = ((int)c->m280 + 0x1F) & ~0x1F;
                    return 1;
                }
            }
        }
    }
    fn_80395A94(c);
    return 0;
}

void fn_80395C08(Vp6Ctx** h)
{
    if (*h) {
        fn_80395A94(*h);
        fn_80396DA8((Vp6TblHolder*)((char*)*h + 0x13C));
        fn_80396274((Vp6SubB*)((char*)*h + 0x298));
    }
    fn_80398614(*h);
    *h = 0;
}

struct Vp6Frm {
    unsigned m0;
    unsigned m4;
    unsigned m8;
    unsigned mC;
    unsigned m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
};

struct Vp6SizeView {
    char pad0[0x148];
    int m148;
    char pad14C[0x19C - 0x14C];
    unsigned char m19C;
    char pad19D[3];
    int m1A0;
    char pad1A4[8];
    unsigned char m1AC;
    char pad1AD[3];
    unsigned m1B0;
    unsigned m1B4;
    int m1B8;
    int m1BC;
    char pad1C0[0x1DC - 0x1C0];
    int m1DC;
    char pad1E0[0x208 - 0x1E0];
    int m208;
    int m20C;
    char pad210[0x21C - 0x210];
    int m21C;
    int m220;
    int m224;
    char pad228[0x23C - 0x228];
    int m23C;
    int m240;
    char pad244[0x254 - 0x244];
    int m254;
    char pad258[4];
    int m25C;
    int m260;
    int m264;
    char pad268[0x298 - 0x268];
    Vp6Buf* m298;
    char pad29C[0x6A0 - 0x29C];
    int m6A0;
    char pad6A4[0x493C - 0x6A4];
    int m493C;
    int m4940;
    int m4944;
};

typedef void (*Vp6Fn5R)(Vp6Buf*, int, int, int, int);
extern Vp6Fn5R lbl_806EF400;
extern "C" void fn_803A0C9C(Vp6Buf*, int, Vp6Frm*);
extern "C" void fn_80396604(Vp6Buf*, unsigned char, unsigned char, int, int, int, int, int, int, int);

/* near-miss: 4 slots (li r4 / stw order around the memsets). */
Vp6Ctx* fn_80395C68()
{
    Vp6Params p;
    Vp6Params* pp = &p;
    MEMSET_V(pp, 0, sizeof(p));
    p.m10 = 8;
    p.m14 = 8;
    Vp6Ctx* c = (Vp6Ctx*)fn_803985F4(0x4954, 0);
    if (c == 0) {
        return 0;
    }
    MEMSET_V(c, 0, 0x4954);
    c->m1B0 = p;
    if (!fn_80395B38(c)) {
        fn_80398614(c);
        return 0;
    }
    c->m1A8 = 0x46;
    c->m294 = &lbl_8069C4A0;
    MEMSET_V((char*)c + 0x3A0, 0, 0x16);
    MEMSET_V((char*)c + 0x3B6, 0, 0x18C);
    return c;
}

void fn_80395D94()
{
    lbl_806EF39C = fn_8039847C();
    fn_80398484();
    for (int i = 0; i < 0x40; i++) {
        lbl_8069BF40[i] = lbl_80607A68[i] / 2 + 2;
    }
    fn_80395E18(lbl_8069BF40, lbl_8069BF40, lbl_8069BF40, 7);
    fn_80397CAC();
}

void fn_80395E14()
{
}

void fn_80395E18(int* a, int* b, int* c, unsigned d)
{
    for (int i = 0; i < 0x300; i++) {
        int t = i - 0x100;
        if (t >= 0) {
            if (t > 0xFF) t = 0xFF;
            lbl_8069C040[i] = t;
        } else {
            lbl_8069C040[i] = 0;
        }
    }
    lbl_806EF448 = (int)a;
    lbl_806EF44C = (int)b;
    lbl_806EF450 = (int)c;
    for (int i = 0; i < 0x40; i++) {
        lbl_8069C6A8[i] = c[i];
    }
    if (d > 5) {
        lbl_806EF458 = (int)lbl_80624E7C;
        lbl_806EF454 = (int)lbl_8062477C;
    } else if (d > 4) {
        lbl_806EF458 = (int)lbl_80624D7C;
        lbl_806EF454 = (int)lbl_8062467C;
    } else {
        lbl_806EF458 = (int)lbl_80624C7C;
        lbl_806EF454 = (int)lbl_8062457C;
    }
    fn_80398324(d);
}

void fn_80395F00(Vp6Buf* b)
{
    if (b->mB8) fn_80398614(b->mB8);
    b->mB8 = 0;
    b->mBC = 0;
    if (b->mA0) fn_80398614(b->mA0);
    b->mA0 = 0;
    b->m34 = 0;
    if (b->mA4) fn_80398614(b->mA4);
    b->mA4 = 0;
    b->m3C = 0;
    if (b->mA8) fn_80398614(b->mA8);
    b->mA8 = 0;
    b->m24 = 0;
    if (b->mAC) fn_80398614(b->mAC);
    b->mAC = 0;
    b->m28 = 0;
    if (b->mB0) fn_80398614(b->mB0);
    b->mB0 = 0;
    b->m2C = 0;
}

int fn_80395FBC(Vp6Buf* b)
{
    fn_80395F00(b);
    unsigned n = b->m98 * (b->m40.m4 + b->mB4 * 2);
    b->mB8 = fn_803985F4(n * 3 / 2 + 0x20, 0);
    if (b->mB8 != 0) {
        b->mBC = (void*)(((int)b->mB8 + 0x1F) & ~0x1F);
        b->mA0 = fn_803985F4(0x820, 0);
        if (b->mA0 != 0) {
            b->m34 = (void*)(((int)b->mA0 + 0x1F) & ~0x1F);
            b->mA4 = fn_803985F4(0x820, 0);
            if (b->mA4 != 0) {
                b->m3C = (void*)(((int)b->mA4 + 0x1F) & ~0x1F);
                b->mA8 = fn_803985F4(b->m8C * 4 + 0x20, 0);
                if (b->mA8 != 0) {
                    b->m24 = (void*)(((int)b->mA8 + 0x1F) & ~0x1F);
                    b->mAC = fn_803985F4(b->m8C * 4 + 0x20, 0);
                    if (b->mAC != 0) {
                        b->m28 = (void*)(((int)b->mAC + 0x1F) & ~0x1F);
                        b->mB0 = fn_803985F4(b->m8C + 0x20, 0);
                        if (b->mB0 != 0) {
                            b->m2C = (void*)(((int)b->mB0 + 0x1F) & ~0x1F);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    fn_80395F00(b);
    return 0;
}

/* near-miss: same arithmetic, callee-saved and scratch registers allocated differently. */
void fn_80396114(Vp6Buf* b, const Vp6Params* p)
{
    b->m40 = *p;
    unsigned w8 = b->m40.m0 >> 3;
    unsigned h = b->m40.m8;
    unsigned dh = b->m40.m4;
    unsigned rem = h - (w8 << 3);
    unsigned q = dh >> 3;
    unsigned half = rem >> 1;
    unsigned area = w8 * q;
    unsigned q4 = area >> 2;
    unsigned rq = rem >> 2;
    unsigned t9 = h * (dh + half * 2);
    unsigned t0 = b->m40.mC * ((dh >> 1) + half);
    unsigned t6 = rq * b->m40.mC;
    b->m90 = w8;
    b->m9C = b->m40.mC;
    b->m98 = h;
    b->m94 = q;
    b->m84 = area;
    b->m8C = area + q4 * 2;
    b->mB4 = half;
    b->m80 = t9 + t0 + t6 + rq;
    b->m7C = t9 + t6 + rq;
    b->m78 = half * h + half;
    b->m88 = q4;
}

Vp6Buf* fn_8039620C(const Vp6Params* p)
{
    Vp6Buf* b = (Vp6Buf*)fn_803985F4(0xC8, 0);
    if (b == 0) {
        return 0;
    }
    memset(b, 0, 0xC8);
    fn_80396114(b, p);
    b->mC4 = 1;
    return b;
}

void fn_80396274(Vp6SubB* s)
{
    if (s->m0) {
        fn_80395F00(s->m0);
        fn_80398614(s->m0);
        s->m0 = 0;
    }
}

void fn_803962BC(Vp6Buf* b, int v)
{
    b->m40.m18[5] = v;
}

void fn_803962C4(Vp6Buf* b, int v)
{
    b->mC0 = v;
}

void fn_803962CC(Vp6Buf* b, int v)
{
    b->mC4 = v;
}

void fn_803962D4(Vp6Mb* m)
{
    int v = m->mC;
    for (unsigned i = 0; i < m->m8C; i++) {
        if (m->m18[i * m->m1C] & m->m20) {
            m->m24[i] = v;
        }
    }
}

double fn_80396328(double a, double b, double c)
{
    double buf[2];
    double d = c - b;
    double e = fn_8040FCA0(-d * d / (a * 2.0 * a));
    return lbl_80607420[0] / (a * fn_804101AC(lbl_80607418[0])) * e;
}

void fn_80396ADC(Vp6Tbl* t)
{
    *(Vp6Blk100*)((char*)t + 0x3C) = lbl_80607468;
}

void fn_80396B50(Vp6Tbl* t)
{
    t->m13C = lbl_80608168;
    for (int i = 0; i < 0x40; i++) {
        t->m140[lbl_80608068[i]] = i;
    }
}

void fn_80396B8C(Vp6Tbl* t, int x)
{
    int i;
    for (i = 1; i < 0x40; i++) {
        t->m180[t->m140[i]] = ((const Vp6Q*)&lbl_80607468)[t->m0].b << 2;
    }
    t->m180[0] = lbl_80607A68u[t->m0] << 2;
    for (i = 1; i < 0x40; i++) {
        t->m184[t->m140[i]] = ((const Vp6Q*)&lbl_80607568)[t->m0].b << 2;
    }
    t->m184[0] = lbl_80607AE8[t->m0] << 2;
}

void fn_80396C5C(Vp6Tbl* t, int x)
{
    if (t->m3C[t->m0] != t->m38) {
        t->m38 = t->m4;
        lbl_806EF410(t, x);
        fn_80396B8C(t, x);
    }
}

void fn_80396CC4(Vp6Tbl* t)
{
    if (t->m188) fn_80398614(t->m188);
    t->m188 = 0;
    t->m180 = 0;
    if (t->m18C) fn_80398614(t->m18C);
    t->m18C = 0;
    t->m184 = 0;
}

int fn_80396D20(Vp6Tbl* t)
{
    fn_80396CC4(t);
    t->m188 = fn_803985F4(0xA0, 0);
    if (t->m188 != 0) {
        t->m180 = (unsigned short*)(((int)t->m188 + 0x1F) & ~0x1F);
        t->m18C = fn_803985F4(0xA0, 0);
        if (t->m18C != 0) {
            t->m184 = (unsigned short*)(((int)t->m18C + 0x1F) & ~0x1F);
            return 1;
        }
    }
    fn_80396CC4(t);
    return 0;
}

void fn_80396DA8(Vp6TblHolder* h)
{
    if (h->m0) {
        fn_80396CC4(h->m0);
        fn_80398614(h->m0);
        h->m0 = 0;
    }
}

Vp6Tbl* fn_80396DF0()
{
    Vp6Tbl* t = 0;
    t = (Vp6Tbl*)fn_803985F4(0x990, 0);
    if (t == 0) {
        return 0;
    }
    memset(t, 0, 0x990);
    if (fn_80396D20(t) == 0) {
        fn_80396DA8((Vp6TblHolder*)&t);
    }
    return t;
}

int fn_80397270(Vp6Ctx** out, int w, int h)
{
    *out = fn_80395C68();
    (*out)->m234 = w;
    (*out)->m238 = h;
    (*out)->m23C = w;
    (*out)->m240 = h;
    (*out)->m1B0.m0 = w;
    (*out)->m1B0.m4 = h;
    (*out)->m298 = fn_8039620C(&(*out)->m1B0);
    (*out)->m13C = fn_80396DF0();
    (*out)->m1A4 = lbl_806EF39C;
    if (!fn_8039F3A8(*out)) {
        fn_80395C08(out);
        return 0;
    }
    (*out)->m13C->m38 = 0;
    fn_8039F5BC(*out);
    return 1;
}

void fn_8039733C(Vp6Ctx* c, unsigned kind, int val)
{
    switch (kind) {
    case 1:
        c->m1A8 = val;
        c->m1A0 = 0;
        break;
    case 9:
        c->m4948 = val;
        fn_803962CC(c->m298, val);
        break;
    case 7:
        fn_8039894C(c->m298, val, c->m254);
        fn_8039894C(c->m298, val, c->m24C);
        break;
    case 0:
        if (val == 9) {
            fn_8039733C(c, 1, 0x46);
        } else {
            c->m1A0 = val;
            c->m1A8 = 0;
        }
        break;
    case 8:
        c->m4944 = val;
        break;
    case 5:
        c->m493C = val;
        break;
    case 6:
        c->m4940 = val;
        break;
    }
}

void fn_80397438(Vp6SizeView* c, Vp6Frm* o)
{
    if (c->m1A0 != 0 || (c->m1DC != 0 && c->m4944 != 0)) {
        if (c->m25C == 0) {
            int t0 = c->m208 + c->m20C * 2 + 0x20;
            int sz = c->m1B8 + t0;
            int p = (int)fn_803985F4(sz, 0);
            c->m260 = p;
            c->m25C = (p + 0x1f) & ~0x1f;
            fn_80395FBC(c->m298);
        }
        fn_80396604(c->m298, c->m19C, c->m1AC, c->m1A0, c->m6A0, c->m254, c->m25C, c->m148, 4, 1);
        if (c->m493C != 0)
            lbl_806EF400(c->m298, c->m493C, c->m4940, c->m25C, c->m25C);
    }
    unsigned w = c->m1B0;
    if (w < c->m23C || c->m1B4 < c->m240) {
        int a = c->m23C + 0x20;
        o->m0 = a;
        int h = a / 2;
        int b = c->m240 + 0x20;
        o->m8 = a;
        o->mC = h;
        o->m14 = h;
        o->m4 = b;
        int hb = b / 2;
        int ab = a * b;
        o->m10 = hb;
        int hh = h * hb;
        o->m18 = c->m264;
        o->m1C = c->m264 + ab;
        o->m20 = c->m264 + ab + hh;
        o->m24 = c->m264;
        if (c->m1A0 != 0)
            fn_803A0C9C(c->m298, c->m25C, o);
        else
            fn_803A0C9C(c->m298, c->m254, o);
        o->m18 = o->m18 + ((((o->m4 - c->m240) >> 1) * o->m8) + ((o->m0 - c->m23C) >> 1));
        o->m0 = c->m23C;
        o->m4 = c->m240;
        o->m1C = o->m1C + ((((o->m10 - ((unsigned)c->m240 >> 1)) >> 1) * o->m14) + ((o->mC - ((unsigned)c->m23C >> 1)) >> 1));
        o->m20 = o->m20 + ((((o->m10 - ((unsigned)c->m240 >> 1)) >> 1) * o->m14) + ((o->mC - ((unsigned)c->m23C >> 1)) >> 1));
        o->mC = (unsigned)c->m23C >> 1;
        o->m10 = (unsigned)c->m240 >> 1;
        return;
    }
    o->m0 = w;
    o->m4 = c->m1B4;
    o->m8 = c->m1B8;
    o->mC = c->m1B0 >> 1;
    o->m10 = c->m1B4 >> 1;
    o->m14 = c->m1BC;
    if (c->m1A0 != 0 || (c->m1DC != 0 && c->m4944 != 0)) {
        int t18 = c->m21C + c->m1B8 * 0x30 + 0x30;
        o->m18 = c->m25C + t18;
        int t1C = c->m220 + c->m1BC * 0x18 + 0x18;
        o->m1C = c->m25C + t1C;
        int t20 = c->m224 + c->m1BC * 0x18 + 0x18;
        o->m20 = c->m25C + t20;
        o->m24 = c->m25C + c->m21C;
    } else {
        int t18 = c->m21C + c->m1B8 * 0x30 + 0x30;
        o->m18 = c->m254 + t18;
        int t1C = c->m220 + c->m1BC * 0x18 + 0x18;
        o->m1C = c->m254 + t1C;
        int t20 = c->m224 + c->m1BC * 0x18 + 0x18;
        o->m20 = c->m254 + t20;
        o->m24 = c->m254 + c->m21C;
    }
}

/* near-miss: 10 slots, register choice for the m6A0 value (r0 in the original code). */
int fn_803977FC(Vp6Ctx* c, const unsigned char* buf, int size)
{
    c->m1E8 = size;
    fn_8039E914(&c->m450C, buf);
    if (!fn_8039EF48(c)) {
        return -1;
    }
    if (c->m944 != 0 || c->m19D == 0) {
        if (c->m4520 != 0) {
            c->m190 = 0;
            c->m194 = 0;
            c->m198 = buf + c->m451C;
        } else {
            fn_80398634(&c->m170, buf + c->m451C);
        }
    }
    fn_8039C63C(c);
    int t = c->m244;
    c->m244 = c->m254;
    c->m254 = t;
    fn_8039868C(c->m298, (unsigned char*)t);
    if (c->m1AC == 0 || c->m698 != 0) {
        MEMCPY_V((void*)c->m24C, (void*)c->m254, c->m208 + c->m20C * 2);
    }
    unsigned v;
    if (c->m1AC == 0) {
        v = c->m13C->m0;
    } else {
        v = ((unsigned)c->m6A0 * 3 + (c->m13C->m0 + 2)) >> 2;
    }
    c->m6A0 = v;
    if (c->m150.m10 > (unsigned)c->m1E8) {
        void* f = fopen(lbl_80608490, lbl_806084A0);
        fprintf(f, lbl_806084A4, lbl_806EE9C8, c->m150.m10, c->m1E8);
        fclose(f);
    }
    lbl_806EE9C8++;
    return 0;
}

int fn_80397A4C(Vp6Ctx** h)
{
    if (*h) {
        fn_80396DA8((Vp6TblHolder*)((char*)*h + 0x13C));
        fn_80396274((Vp6SubB*)((char*)*h + 0x298));
        fn_8039EFD4(*h);
        fn_8039F264(*h);
        fn_80395C08(h);
    }
    return 1;
}

void fn_80397AB0()
{
}

void fn_80397AB4(const unsigned char* a, const unsigned char* b, short* out, int stride)
{
    for (int i = 0; i < 8; i++) {
        out[0] = (a[0] + b[0]) >> 1;
        out[1] = (a[1] + b[1]) >> 1;
        out[2] = (a[2] + b[2]) >> 1;
        out[3] = (a[3] + b[3]) >> 1;
        out[4] = (a[4] + b[4]) >> 1;
        out[5] = (a[5] + b[5]) >> 1;
        out[6] = (a[6] + b[6]) >> 1;
        out[7] = (a[7] + b[7]) >> 1;
        a += stride;
        b += stride;
        out += 8;
    }
}

void fn_80397B70(const unsigned char* src, short* diff, int stride)
{
    for (int i = 0; i < 8; i++) {
        diff[0] = src[0] - diff[0];
        diff[1] = src[1] - diff[1];
        diff[2] = src[2] - diff[2];
        diff[3] = src[3] - diff[3];
        diff[4] = src[4] - diff[4];
        diff[5] = src[5] - diff[5];
        diff[6] = src[6] - diff[6];
        diff[7] = src[7] - diff[7];
        src += stride;
        diff += 8;
    }
}

void fn_80397C0C(const unsigned char* src, unsigned char* dst, int stride)
{
    for (int i = 0; i < 8; i++) {
        ((int*)dst)[0] = ((const int*)src)[0];
        ((int*)dst)[1] = ((const int*)src)[1];
        src += stride;
        dst += stride;
    }
}

void fn_80397C34(const unsigned char* src, unsigned char* dst, int sstride, int dstride)
{
    for (int i = 0; i < 12; i++) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst[4] = src[4];
        dst[5] = src[5];
        dst[6] = src[6];
        dst[7] = src[7];
        dst[8] = src[8];
        dst[9] = src[9];
        dst[10] = src[10];
        dst[11] = src[11];
        src += sstride;
        dst += dstride;
    }
}

}
