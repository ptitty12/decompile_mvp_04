/*
 * Game code, .text 0x8014BEA4-0x8014F47C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80144CF0.h"

struct UnkB8_Obj { char pad0[0xB8]; int mB8; };
void* operator new(unsigned int size, int heap);
struct Unk8014D860_Obj { int m0; int m4; int m8; int mC; int m10; int m14; int m18; };
struct Unk8014D9C4_Obj { float m0; float m4; float m8; float mC; };
struct Unk2C { char b[0x2C]; };
struct Unk8014E09C_Obj { int m0; int m4; int m8; const char* mC; const char* m10; Unk2C* m14; };
struct Unk8014E108_Obj { char pad0[8]; int m8; };
struct V3i { int a; int b; int c; };
struct UnkAt2014 { char pad0[0x2014]; int m2014; };
struct UnkAt2ACS { char pad0[0x2AC]; char m2AC[0x10]; };
struct UnkAt2BCS { char pad0[0x2BC]; char m2BC[0x10]; };
struct UnkAt2CCS { char pad0[0x2CC]; char m2CC[0x10]; };

void fn_8000C674(short x, short y, const char* fmt, ...);

#include "game/tu_8006902C.h"
void fn_802D7538();
struct Unk8014D5C0_Obj { char pad0[0x6F8]; Unk80069F0C* m6F8; };
struct Unk8014D5C0_Own { char pad0[8]; Unk8014D5C0_Obj* m8[3]; };
inline Unk8014D5C0_Obj* Get8014D5C0(Unk8014D5C0_Own* p, unsigned i) { return i <= 2 ? p->m8[i] : 0; }
void fn_80071F00();
/* Polymorphic 8-byte object built by fn_80353218 (m0 = 0, vptr lbl_8064B718 at +4); same class as in tu_800A23F4.cpp. */
struct Unk80353218 {
    int m0;
    Unk80353218(); /* fn_80353218 */
    virtual void vf0();
};
#include "game/tu_8000E618.h"
/* 8-byte object built by __11Unk803567AC (m0 = 0, vptr-like pointer at +4). */
struct Unk803567AC {
    int m0;
    Unk803567AC();
    virtual void vf0();
};
unsigned fn_800734D4(void* self, unsigned flags);
Unk8000E618* fn_8000E65C();
void fn_80071F48();
struct Vec3f8014E40C { float x; float y; float z; };
struct Unk8014E40C_Obj { char pad0[0x60]; Vec3f8014E40C m60; };
extern "C" void fn_8014E388(V3i* p, unsigned i);
inline Vec3f8014E40C DiffAt8014E40C(Unk8014E40C_Obj* self, unsigned i)
{
    Vec3f8014E40C t;
    fn_8014E388((V3i*)&t, i);
    const Vec3f8014E40C& b = self->m60;
    Vec3f8014E40C r;
    r.x = t.x - b.x;
    r.y = t.y - b.y;
    r.z = t.z - b.z;
    return r;
}
inline Vec3f8014E40C DiffAtP8014E498(Vec3f8014E40C* pb, unsigned i)
{
    Vec3f8014E40C t;
    fn_8014E388((V3i*)&t, i);
    const Vec3f8014E40C& b = *pb;
    Vec3f8014E40C r;
    r.x = b.x - t.x;
    r.y = b.y - t.y;
    r.z = b.z - t.z;
    return r;
}
struct Vec4f8014DAFC { float x; float y; float z; float w; };
inline Vec4f8014DAFC Div8014DAFC(const Vec4f8014DAFC& a, float s)
{
    Vec4f8014DAFC r;
    float inv = 1.0f / s;
    r.x = a.x * inv;
    r.y = a.y * inv;
    r.z = a.z * inv;
    r.w = a.w * inv;
    return r;
}
inline Vec4f8014DAFC Copy8014DF5C(const Vec4f8014DAFC* p) { return *p; }

struct PackBits8014E01C { unsigned a : 8; unsigned b : 8; unsigned c : 8; unsigned d : 8; };
union Pack8014E01C { PackBits8014E01C p; unsigned u; };
extern "C" {
void fn_80422EE4(void* blk, void* buf, int len, int off, void* cb, int prio);
int fn_80425064(void* blk);
void fn_80437A10();
void* fn_803774A8(unsigned n, int heap);
int fn_80072E90(void* g, void* a, int b, int c, int d, void* out);
void fn_800A59F0(void* p);
void fn_80377488(void* p);
extern void* lbl_8061B9B4;
extern int lbl_8061B9B0;
extern void* lbl_80619948;
int fn_80148404(void*);
void fn_80148438(void*);
int fn_8014E6E0(void* self, char* buf, int n);
void fn_8040B320(char*, int, int, ...);
int fn_8040B574(const char* a, const char* b);
void fn_80422C3C(void* p);
int fn_80422B74(const char* a, void* p);
int fn_803FEC74(int buf, int pos, const char* s, int len, int n);
unsigned int strlen(const char* s);
void fn_8014BEA4();
void fn_8014C3BC();
void fn_8014C4E8();
void fn_8014C540();
void fn_8014D63C(int a, int b);
void fn_8014D81C(int* p);
void fn_8014D860(Unk8014D860_Obj* p, int a);
Unk8014D9C4_Obj* fn_8014D9C4(Unk8014D9C4_Obj* p);
void fn_8014DD30();
int fn_8014DD68(int a0, int a1, unsigned a2, unsigned a3);
/* near-miss (27 vs 30 insns): all 720 store orders tried; retail computes the element pointer with mulli/add
   before the vptr-like stores and keeps the three symbol addresses in distinct registers */
Unk8014E09C_Obj* fn_8014E09C(Unk8014E09C_Obj* p, int a, int b);
void* fn_8014E108(Unk8014E108_Obj* p);
int fn_8014E2B4(int a);
int fn_8014E310(int a);
int fn_8014E374(int a);
/* near-miss: struct-copy form schedules like retail, but the two arms are joined by a cross-jump
   (retail keeps two separate copy+blr tails); field-wise copies schedule differently */
void fn_8014E388(V3i* p, unsigned i);
int fn_8014E3E0(int a);
void fn_8014E57C(UnkAt2014* p);
void* fn_8014E88C(void* p);
void fn_8014E8DC(void* p);
void* fn_8014EB44();
void fn_8014EBEC(UnkAt2ACS* p, const char* s);
void fn_8014EC24(UnkAt2BCS* p, const char* s);
void fn_8014EC5C(UnkAt2CCS* p, const char* s);
int fn_8014EC94(int a, unsigned b, unsigned c);
void* fn_8014F008(int a, int b, int c, int d);
void fn_8014F34C(int a);
void fn_8014F42C();
extern const void* lbl_8068B3CC;
extern const char lbl_8065D448[];
void fn_80378744();
extern UnkB8_Obj* lbl_8061A32C;
UnkB8_Obj* fn_800B64BC(void*);
void fn_8014C468();
extern void* lbl_8061930C;
void fn_80072B98(void*);
void fn_8014C3DC();
extern Unk8014D5C0_Own* lbl_8068B618;
void __main();
void fn_8014C5A4(int, int);
void fn_8014C8BC();
int fn_80148930(void*);
int fn_8014D1EC();
void fn_8014D5C0();
void fn_8014D488();
extern const char lbl_805C5F90[];
void fn_803FFA60(void*, const char*, int);
extern const float lbl_805C58AC;
extern const float lbl_805C58B0;
unsigned fn_8014DDAC();
extern Unk2C lbl_8061BAD4[];
extern char lbl_8061B9CC[];
extern char lbl_8061BA7C[];
void fn_8014E15C(Unk8014E09C_Obj*, int, int);
void fn_803579D4(void*);
extern V3i lbl_805C5F54[];
extern V3i lbl_805C5F78;
extern const char lbl_805C5A90[];
extern const char lbl_805C5A98[];
void fn_8014E588(void*, const char*);
void fn_8014E7EC(void*, const char*);
extern void* lbl_8061BD74;
void* fn_8014E9E0(void*);
void fn_8040B830(char*, const char*, int);
void* fn_8014F05C(void*, int, int, int, int);
extern int lbl_8068B704;
extern int lbl_8068B700;
extern int lbl_8068B6FC;
int fn_803FEBDC(int, int, int, int*);
int fn_803FEC9C(int, int);

struct Self8014E588 {
    char pad0[0x2000];
    int m2000;
    int m2004;
    int m2008;
    int m200C;
    int m2010;
    int m2014;
    char m2018[0x34];
    int m204C;
};
struct Self8014EB90 {
    char pad0[0x2AB];
    char m2AB;
};
extern int lbl_8061B9BC;

extern const char lbl_805C5020;
extern const char lbl_805C5A64[];
extern const char lbl_805C5ABC[];

void fn_8014BEA4()
{
    lbl_8068B3CC = lbl_8065D448;
}

void fn_8014C3BC() { fn_80378744(); }

void fn_8014C3DC()
{
    unsigned n = fn_800734D4(lbl_8061930C, 0x03531311);
    lbl_8061B9B0 = n;
    lbl_8061B9B4 = fn_803774A8(n, fn_8000E65C()->fn_8000E6F0() | 0x500);
    Unk803567AC sp8;
    fn_80072E90(lbl_8061930C, lbl_8061B9B4, lbl_8061B9B0, 0x03531311, 0, &sp8);
    fn_80071F48();
}

void fn_8014C468()
{
    fn_80071F00();
    Unk80353218 sp8;
    fn_80072E90(lbl_8061930C, lbl_8061B9B4, lbl_8061B9B0, 0x03531311, 0, &sp8);
    fn_800A59F0(lbl_80619948);
    if (lbl_8061B9B4 != 0) {
        fn_80377488(lbl_8061B9B4);
    }
    lbl_8061B9B4 = 0;
}

void fn_8014C4E8()
{
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    lbl_8061A32C->mB8 = 0;
    fn_8014C468();
}

void fn_8014C540()
{
    fn_80072B98(lbl_8061930C);
    fn_8014C3DC();
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    lbl_8061A32C->mB8 = 1;
}

void fn_8014D5C0()
{
    fn_802D7538();
    int i = 0;
    while (i < fn_80148404(lbl_8068B618)) {
        Unk8014D5C0_Obj* o = Get8014D5C0(lbl_8068B618, i);
        i++;
        o->m6F8->fn_8006A070();
    }
    fn_80148438(lbl_8068B618);
}

void fn_8014D63C(int a, int b)
{
    __main();
    fn_8014C5A4(a, b);
    for (;;) {
        fn_8014C8BC();
        fn_80148930(lbl_8068B618);
        if (fn_8014D1EC() == 1) {
            while ((unsigned)(fn_80148930(lbl_8068B618) - 2) <= 1) {
                fn_8014D5C0();
            }
        }
        fn_8014D488();
    }
}

void fn_8014D81C(int* p)
{
    fn_803FFA60(p + 1, lbl_805C5F90, 0x18);
    *p = 0;
}

void fn_8014D860(Unk8014D860_Obj* p, int a)
{
    int t = a + 0xF22D0E56;
    p->m4 = t;
    t = t + 0x96041893;
    p->m8 = t;
    t = t + 0x3DF3B646;
    p->mC = t;
    t = t + 0x40DDE76D;
    p->m10 = t;
    t = t + 0x97327AE1;
    p->m14 = t;
    p->m18 = t + 0xD1A9FBE7;
}

Unk8014D9C4_Obj* fn_8014D9C4(Unk8014D9C4_Obj* p)
{
    p->m0 = lbl_805C58AC;
    p->m4 = lbl_805C58AC;
    p->m8 = lbl_805C58AC;
    p->mC = lbl_805C58B0;
    return p;
}

Vec4f8014DAFC fn_8014DAFC(Vec4f8014DAFC v, float s)
{
    Vec4f8014DAFC t = Div8014DAFC(v, s);
    return t;
}

void fn_8014DD30()
{
    unsigned c = fn_8014DDAC();
    fn_8014DD68(c >> 24, (c >> 16) & 0xFF, (c >> 8) & 0xFF, c & 0xFF);
}

int fn_8014DD68(int a0, int a1, unsigned a2, unsigned a3)
{
    int r;
    if (a3 > 0xDF) {
        r = (a2 >> 3) | (((a0 << 7) & 0x7C00) | ((a1 * 4) & 0x3E0)) | 0x8000;
    } else {
        r = (a2 >> 4) | ((a1 & 0xF0) | ((a0 * 0x10) & 0xF00)) | ((a3 << 7) & 0x7000);
    }
    return r;
}

/* near-miss (27 vs 30 insns): all 720 store orders tried; retail computes the element pointer with mulli/add
   before the vptr-like stores and keeps the three symbol addresses in distinct registers */
void fn_8014DF5C(Vec4f8014DAFC* out, Vec4f8014DAFC* pa, Vec4f8014DAFC* pb, float t)
{
    Vec4f8014DAFC a = Copy8014DF5C(pa);
    Vec4f8014DAFC b = Copy8014DF5C(pb);
    float it = 1.0f - t;
    out->x = it * a.x + t * b.x;
    out->y = it * a.y + t * b.y;
    out->z = it * a.z + t * b.z;
    out->w = it * a.w + t * b.w;
}

unsigned fn_8014E01C(Vec4f8014DAFC* v)
{
    const float s = 255.0f;
    Pack8014E01C c;
    c.p.a = (int)(v->z * s);
    c.p.b = (int)(v->y * s);
    c.p.c = (int)(v->x * s);
    c.p.d = (int)(v->w * s);
    return c.u;
}

/* near-miss (29 vs 27 insns): retail keeps a, b in r4, r5 for the pass-through call; ours copies them to r6, r7 first */
Unk8014E09C_Obj* fn_8014E09C(Unk8014E09C_Obj* p, int a, int b)
{
    Unk2C* t = &lbl_8061BAD4[b];
    p->m0 = a;
    p->m8 = 0;
    p->mC = lbl_8061B9CC;
    p->m10 = lbl_8061BA7C;
    p->m14 = t;
    p->m4 = b;
    fn_8014E15C(p, a, b);
    return p;
}

void* fn_8014E108(Unk8014E108_Obj* p)
{
    int t = p->m8;
    if (t != 0xA) {
        int v;
        if (t > 9) {
            v = t;
        } else {
            v = t + 1;
        }
        p->m8 = v;
        fn_803579D4(p);
    }
    return p;
}

int fn_8014E2B4(int a)
{
    int r = 9;
    switch (a) {
    case -1:
        break;
    case 0:
        r = 10;
        break;
    case 1:
        r = 11;
        break;
    case 2:
        r = 12;
        break;
    case 3:
        r = 18;
        break;
    }
    return r;
}

int fn_8014E310(int a)
{
    switch (a) {
    case 9:
        return -1;
    case 10:
        return 0;
    case 11:
        return 1;
    case 12:
        return 2;
    case 13:
        return 3;
    default:
        return -1;
    }
}

int fn_8014E374(int a)
{
    a = a + 1;
    if (a > 3) {
        a = 3;
    }
    return a;
}

/* near-miss: struct-copy form schedules like retail, but the two arms are joined by a cross-jump
   (retail keeps two separate copy+blr tails); field-wise copies schedule differently */
void fn_8014E388(V3i* p, unsigned i)
{
    if (i <= 3) {
        *p = lbl_805C5F54[i];
        return;
    }
    *p = lbl_805C5F78;
}

int fn_8014E3E0(int a)
{
    if (a > 9) {
        if (a == 10) {
            return 0;
        }
        if (a != 11) {
            return 2;
        }
        return 7;
    }
    return a;
}

float fn_8014E40C(Unk8014E40C_Obj* self, unsigned i)
{
    Vec3f8014E40C d = DiffAt8014E40C(self, i);
    return d.x * d.x + d.z * d.z;
}

int fn_8014E498(Vec3f8014E40C* p, float* out)
{
    int idx = -1;
    int i = 0;
    float d2;
    float best = 144000000.0f;
    do {
        Vec3f8014E40C d = DiffAtP8014E498(p, i);
        d2 = d.x * d.x + d.z * d.z;
        if (!(d2 >= best)) {
            best = d2;
            idx = i;
        }
        i++;
    } while (i <= 3);
    if (out != 0) {
        *out = best;
    }
    return idx;
}

void fn_8014E57C(UnkAt2014* p) { p->m2014 = 0x0; }

void fn_8014E588(void* sv, const char* a)
{
    Self8014E588* s = (Self8014E588*)sv;
    if (s->m2014 != 0) {
        fn_80422C3C(s->m2018);
        s->m2014 = 0;
    }
    s->m2010 = 1;
    s->m2004 = 0;
    s->m200C = 0;
    int ok = fn_80422B74(a, s->m2018);
    int t = 1;
    if (ok == 0) {
        t = 0;
    }
    s->m2014 = t;
    if (t != 0) {
        t = s->m204C;
    }
    s->m2008 = t;
}

char fn_8014E614(Self8014E588* s)
{
    if (s->m2014 == 0) {
        return 0;
    }
    if (s->m2010 != 0 || s->m2000 > 0x1FFF) {
        s->m2000 = 0;
        char* blk = s->m2018;
        fn_80422EE4(blk, s, 0x2000, s->m2004, 0, 2);
        int r;
        while ((r = fn_80425064(blk)) != 0) {
            fn_80437A10();
        }
        s->m2010 = r;
        s->m2004 += 0x2000;
        if (s->m2004 >= s->m2008) {
            s->m200C = 1;
        }
    }
    int i = s->m2000;
    s->m2000 = i + 1;
    return ((char*)s)[i];
}

void fn_8014E7EC(void* self, const char* target)
{
    char buf[0x2000];
    buf[0] = lbl_805C5020;
    fn_8040B320(buf + 1, 0, 0x1FFF);
    do {
        int ok = fn_8014E6E0(self, buf, 0x2000);
        if (ok != 1 || strlen(buf) > 0x1FFF) {
            fn_8000C674(0, 0x1A, lbl_805C5A64);
        }
    } while (fn_8040B574(buf, target) != 0);
}

void* fn_8014E88C(void* p)
{
    fn_8014E57C((UnkAt2014*)p);
    fn_8014E588(p, lbl_805C5A90);
    fn_8014E7EC(p, lbl_805C5A98);
    return p;
}

void fn_8014E8DC(void* p)
{
    fn_8014E588(p, lbl_805C5A90);
}

/* near-miss: 55/55 insns, 2 slots: retail keeps 'bad = r ^ 1' in r24 with a real xori on entry and on return;
   ours folds the two xor 1 into a move (== 0 gives subfic/adde) */
int fn_8014E904(char* self, char* a, char* b, char* c)
{
    *a = 0;
    *b = 0;
    *c = 0;
    int bad = fn_8014E6E0(self, self + 0x2060, 0x2000) ^ 1;
    int n = strlen(self + 0x2060);
    if (n > 0x1FFF) {
        fn_8000C674(0, 0x1A, lbl_805C5ABC);
    }
    if (n > 0) {
        fn_8040B830(a, self + 0x2060, 9);
        a[8] = 0;
    }
    if (n > 9) {
        fn_8040B830(b, self + 0x2069, 9);
        b[8] = 0;
    }
    if (n > 0x17) {
        fn_8040B830(c, self + 0x2077, 0x401);
        c[0x400] = 0;
    }
    return bad ^ 1;
}

void* fn_8014EB44() { if (!lbl_8061BD74) lbl_8061BD74 = fn_8014E9E0(operator new(0x2DC, 0)); return lbl_8061BD74; }

void fn_8014EB90(Self8014EB90* s, int* a, const char* name)
{
    if (lbl_8061B9BC != 0 && a == 0) {
        fn_8040B830((char*)s + 0x284, name, 0x28);
        s->m2AB = 0;
        *a = 0;
    }
}

void fn_8014EBEC(UnkAt2ACS* p, const char* s) { p->m2AC[0] = 0; if (s) fn_8040B830(p->m2AC, s, 0x10); }

void fn_8014EC24(UnkAt2BCS* p, const char* s) { p->m2BC[0] = 0; if (s) fn_8040B830(p->m2BC, s, 0x10); }

void fn_8014EC5C(UnkAt2CCS* p, const char* s) { p->m2CC[0] = 0; if (s) fn_8040B830(p->m2CC, s, 0x10); }

int fn_8014EC94(int a, unsigned b, unsigned c) { return (b & (c - 1)) == 0; }

void* fn_8014F008(int a, int b, int c, int d)
{
    void* r = fn_8014EB44();
    if (r != 0) {
        r = fn_8014F05C(r, a, b, c, d);
    }
    return r;
}

void fn_8014F34C(int a)
{
    lbl_8068B700 = 1;
    lbl_8068B704 = 0;
    int r = fn_803FEBDC(a, 6, 0x64, &lbl_8068B6FC);
    if (r == 0) {
        lbl_8068B700 = r;
    }
}

void fn_8014F3A8(const char* str)
{
    if (lbl_8068B700 != 0) {
        if (str == 0) {
            lbl_8068B700 = 0;
        } else {
            int pos = lbl_8068B704;
            lbl_8068B704 += fn_803FEC74(lbl_8068B6FC, pos, str, strlen(str), 100);
        }
    }
}

void fn_8014F42C()
{
    if (lbl_8068B700 != 0) {
        int r = fn_803FEC9C(lbl_8068B6FC, 0x64);
        if (r == 0) {
            lbl_8068B700 = r;
        }
    }
}

}
