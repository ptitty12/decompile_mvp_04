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
struct Ctx8014ECA8 {
    int r[32];
    int cr;
    int lr;
    char pad88[0x198 - 0x88];
    int srr0;
    int srr1;
};
struct Frame8014EF0C { Frame8014EF0C* next; int lr; };
struct Unk8014E15C_Y { char pad0[0x14]; void* m14; };
struct Unk8014E15C_Ctx { char pad0[0x6F4]; int m6F4; Unk8014E15C_Y* m6F8; };
struct Unk8014E15C_Obj { Unk8014E15C_Ctx* m0; int m4; int m8; int* mC; int* m10; int* m14; };
extern "C" int fn_80081B60__FP13Unk8007FF8C_Y(void* y);
struct Unk80634ADC;
struct Self8014E9E0 {
    char pad0[0x280];
    void* m280;
    char m284;
    char pad285[0x2AC - 0x285];
    char m2AC[0x10];
    char m2BC[0x10];
    char m2CC[0x10];
};
int fn_803D817C();
void fn_803D81FC();
void fn_8000C4A8(unsigned char* fb, Unk80634ADC* rmode);
class V0_8014D6A4 { public: virtual ~V0_8014D6A4(); };
extern int lbl_8061B9B8;
extern VT18* lbl_80620140;
extern VT18* lbl_8062013C;
extern int lbl_8061F688;
extern V0_8014D6A4* lbl_8061B984;
extern VT18* lbl_8068F1F4;
extern VT18* lbl_8068F1FC;
class V2DC_8014D488 { public: char pad0[0x2DC]; virtual ~V2DC_8014D488(); };
struct Unk806192E0_8014D488 { int m0; int m4; };
extern int lbl_8061FEDC;
extern int lbl_8061FE20;
extern int lbl_8061C688;
extern V2DC_8014D488* lbl_8061B99C;
extern VT18* lbl_8061B998;
extern void* lbl_8061E978;
extern Unk806192E0_8014D488* lbl_806192E0;

extern "C" {
int fn_8031C6A8();
void fn_8031C6B4();
void fn_80149DD4(void* a, int b);
void fn_80312018(int a);
void fn_802B832C__FP15Unk802ACD88_Mgr(void* mgr);
void* fn_802BB19C__Fv();
void fn_802BB1E4__FP15Unk802BB1E4_Obji(void* o, int i);
}
extern "C" {
void fn_80329A50();
void fn_8031D0F0();
void fn_8014BC64();
void fn_8037C764();
void fn_8037B8EC();
void fn_802E3980__15Unk802E3980_Mgr(int self);
void fn_8024F6CC__Fv();
void fn_8037C7FC__Fv();
void fn_8001C394__Fv();
void fn_8001C410__11Unk8001C314();
void fn_802B8BBC__Fv();
}
extern "C" {
void fn_8014F3A8(const char* str);
void fn_8014F47C(void* p);
void fn_803D9E00(int a, unsigned char** b, Unk80634ADC** c);
void* fn_80433E14(unsigned short sig, void* handler);
int sprintf(char* buf, const char* fmt, ...);
void fn_8014F4B4(int a, char* s);
void fn_8014F738(int a);
void OSReport(const char* msg, ...);
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
void fn_8014DD30(Vec4f8014DAFC* v);
int fn_8014DD68(int a0, int a1, unsigned a2, unsigned a3);
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
unsigned fn_8014DDAC(Vec4f8014DAFC* v);
extern Unk2C lbl_8061BAD4[];
extern char lbl_8061B9CC[];
extern char lbl_8061BA7C[];
void fn_8014E15C(Unk8014E15C_Obj*);
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

void fn_8014D488()
{
    int x = lbl_8061FEDC;
    if (fn_8031C6A8() != 0) {
        fn_8031C6A8();
        fn_8031C6B4();
    }
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    ((VT18*)lbl_8061A32C)->s19();
    if (lbl_8061B99C != 0) {
        delete lbl_8061B99C;
        lbl_8061B99C = 0;
    }
    if (lbl_8061B998 != 0) {
        delete lbl_8061B998;
        lbl_8061B998 = 0;
    }
    fn_802B832C__FP15Unk802ACD88_Mgr(lbl_8061E978);
    fn_80149DD4(lbl_8068B618, lbl_806192E0->m4);
    fn_80312018(x + 0x40);
    lbl_8061FE20 = 0;
    fn_802BB1E4__FP15Unk802BB1E4_Obji(fn_802BB19C__Fv(), 0);
    fn_8014C4E8();
    lbl_8061C688 = 0;
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

void fn_8014D6A4()
{
    if (lbl_8061B9B8 == 0) {
        lbl_8061B9B8 = 1;
        if (lbl_80620140 != 0) {
            delete lbl_80620140;
            lbl_80620140 = 0;
        }
        lbl_80620140 = 0;
        if (lbl_8062013C != 0) {
            delete lbl_8062013C;
            lbl_8062013C = 0;
        }
        lbl_8062013C = 0;
        fn_80329A50();
        if (lbl_8061F688 != 0) {
            fn_802E3980__15Unk802E3980_Mgr(lbl_8061F688);
        }
        fn_8024F6CC__Fv();
        if (lbl_8061B984 != 0) {
            delete lbl_8061B984;
            lbl_8061B984 = 0;
        }
        if (lbl_8068F1F4 != 0) {
            delete lbl_8068F1F4;
            lbl_8068F1F4 = 0;
        }
        if (lbl_8068F1FC != 0) {
            delete lbl_8068F1FC;
            lbl_8068F1FC = 0;
        }
        fn_8031D0F0();
        fn_8014BC64();
        fn_8037C7FC__Fv();
        fn_8037C764();
        fn_8001C394__Fv();
        fn_8001C410__11Unk8001C314();
        fn_802B8BBC__Fv();
        fn_8037B8EC();
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

void fn_8014D9EC(Vec4f8014DAFC* out, float x, float y, float z, float w, float m)
{
    float inv = 1.0f / m;
    out->x = inv * (!(x > m) ? (x >? 0.0f) : m);
    out->y = inv * (!(y > m) ? (y >? 0.0f) : m);
    out->z = inv * (!(z > m) ? (z >? 0.0f) : m);
    out->w = inv * (!(w > m) ? (w >? 0.0f) : m);
}

Vec4f8014DAFC fn_8014DAFC(Vec4f8014DAFC v, float s)
{
    Vec4f8014DAFC t = Div8014DAFC(v, s);
    return t;
}

void fn_8014DBA0(Vec4f8014DAFC* out, int r, int g, int b, int a)
{
    float k = 0.003921569f;
    out->x = r > 255 ? 1.0f : ((float)r >? 0.0f) * 0.003921569f;
    out->y = g > 255 ? 1.0f : ((float)g >? 0.0f) * 0.003921569f;
    out->z = b > 255 ? 1.0f : ((float)b >? 0.0f) * 0.003921569f;
    out->w = a > 255 ? 1.0f : ((float)a >? 0.0f) * 0.003921569f;
}

void fn_8014DD30(Vec4f8014DAFC* v)
{
    unsigned c = fn_8014DDAC(v);
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

Unk8014E09C_Obj* fn_8014E09C(Unk8014E09C_Obj* p, int a, int b)
{
    Unk2C* t = &lbl_8061BAD4[b];
    p->m0 = a;
    p->m8 = 0;
    p->mC = lbl_8061B9CC;
    p->m10 = lbl_8061BA7C;
    p->m14 = t;
    p->m4 = b;
    fn_8014E15C((Unk8014E15C_Obj*)p);
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

void fn_8014E15C(Unk8014E15C_Obj* p)
{
    int type;
    Unk8014E15C_Ctx* c = p->m0;
    switch (c->m6F4) {
    case 0:
    case 12:
        type = 0;
        break;
    case 2:
    case 5:
        type = 1;
        break;
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
        type = 2;
        break;
    case 9:
        type = 3;
        break;
    default:
        type = 1;
        break;
    }
    int k = fn_80081B60__FP13Unk8007FF8C_Y(c->m6F8->m14) == 1 ? 0 : 1;
    int idx = p->m8;
    p->mC = (int*)&((Unk2C*)lbl_8061B9CC)[type];
    p->m10 = (int*)&((Unk2C*)lbl_8061BA7C)[k];
    p->m14 = (int*)&lbl_8061BAD4[p->m4];
    while (*(int*)((char*)p->mC + (idx << 2)) == 0 || *(int*)((char*)p->m10 + (idx << 2)) == 0 || *(int*)((char*)p->m14 + (idx << 2)) == 0) {
        int v;
        if (idx > 9) {
            v = idx;
        } else {
            v = idx + 1;
        }
        p->m8 = v;
        idx = v;
    }
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

int fn_8014E6E0(void* sv, char* buf, int n)
{
    Self8014E588* s = (Self8014E588*)sv;
    if (s->m200C != 0 || s->m2014 == 0) {
        *buf = 0;
        return 0;
    }
    int i = 0;
    char c = fn_8014E614(s);
    while (c != 10 && c != 0 && i < n) {
        buf[i] = c;
        i++;
        c = fn_8014E614(s);
    }
    if (i < n) {
        if (i > 0 && c == 10 && buf[i - 1] == 13) {
            i--;
        }
        buf[i] = 0;
    } else {
        buf[n - 1] = 0;
        while (c != 10 && c != 0) {
            c = fn_8014E614(s);
        }
    }
    return s->m200C ^ 1;
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

void* fn_8014E9E0(void* sv)
{
    Self8014E9E0* s = (Self8014E9E0*)sv;
    void* old[18];
    s->m280 = 0;
    if (lbl_8061B9BC != 0) {
        s->m284 = 0;
        s->m2AC[0] = 0;
        s->m2BC[0] = 0;
        s->m2CC[0] = 0;
        s->m280 = fn_8014E88C(operator new(0x4060, 0));
        fn_8014F47C(s);
        unsigned char* fb = 0;
        Unk80634ADC* rm = 0;
        fn_803D81FC();
        fn_803D9E00(fn_803D817C() + 0x10, &fb, &rm);
        fn_8000C4A8(fb, rm);
        void* h = (void*)fn_8014F008;
        old[6] = fn_80433E14(6, h);
        old[10] = fn_80433E14(10, h);
        old[12] = fn_80433E14(12, h);
        old[0] = fn_80433E14(0, h);
        old[1] = fn_80433E14(1, h);
        old[2] = fn_80433E14(2, h);
        old[3] = fn_80433E14(3, h);
        old[5] = fn_80433E14(5, h);
        old[11] = fn_80433E14(11, h);
        old[13] = fn_80433E14(13, h);
        old[14] = fn_80433E14(14, h);
        old[15] = fn_80433E14(15, h);
    }
    return s;
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

/* near-miss (3 slots): retail schedules li r29,0 (loop counter) before the first OSReport call, ours after it */
void fn_8014ECA8(int unused, Ctx8014ECA8* c, int dsisr, int dar)
{
    int i;
    for (i = 0, OSReport("Registers\n"); i < 16; i++) {
        OSReport("r%-2d  = 0x%08x (%14d)  r%-2d  = 0x%08x (%14d)\n", i, c->r[i], c->r[i], i + 16, c->r[i + 16], c->r[i + 16]);
    }
    OSReport("LR   = 0x%08x                   CR   = 0x%08x\n", c->lr, c->cr);
    OSReport("SRR0 = 0x%08x                   SRR1 = 0x%08x\n", c->srr0, c->srr1);
    OSReport("DSISR= 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
    OSReport("\n");
}

/* near-miss (2 slots): the first fn_8000C674 call loads r3 before r4 here, r4 (2) before r3 (1) in retail */
void fn_8014ED80(int a, unsigned* addr)
{
    fn_8000C674(1, 2, "Disassembly:");
    unsigned* p = addr - 4;
    OSReport("\nDisassembly:\n");
    int row = 13;
    fn_8014F3A8("\nDisassembly:\n");
    do {
        char buf[16] = "";
        if (p == addr) {
            OSReport("      -->");
            fn_8000C674(3, row - 10, "      -->");
            fn_8014F3A8("-->");
        } else {
            OSReport("%08x:", p);
            sprintf(buf, "%08x:", p);
            fn_8000C674(3, row - 10, buf);
            fn_8014F3A8(buf);
        }
        if (fn_8014EC94(a, (unsigned)p, 4) != 0) {
            OSReport("%08x:\n", *p);
            sprintf(buf, "%08x:", *p);
            fn_8000C674(0xC, row - 10, buf);
            fn_8014F3A8(buf);
        }
        row++;
        p++;
        fn_8014F3A8("\n");
    } while (row <= 19);
}

void fn_8014EF0C(int a, int unused, Frame8014EF0C* sp0)
{
    OSReport("\nAddress:      Back Chain    LR Save\n");
    Frame8014EF0C* sp = sp0;
    unsigned i = 0;
    while (sp != 0 && sp != (Frame8014EF0C*)-1 && i++ <= 31) {
        if (sp->lr != 0) {
            char buf[16] = "";
            OSReport("  0x%08x:   0x%08x    0x%08x\n", sp, sp->next, sp->lr);
            sprintf(buf, "%08x", sp->lr);
            fn_8014F4B4(a, buf);
        } else {
            OSReport("--------");
        }
        sp = sp->next;
    }
    fn_8014F738(a);
}

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
