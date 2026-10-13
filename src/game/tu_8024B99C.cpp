/*
 * Game code, .text 0x8024B99C-0x8024EF40 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024B99C.h"
#include "game/chooser.h"
#include "game/tu_8024EF40.h"

struct Unk8023DA90_O;
inline unsigned& Fl4C08(Unk8024B99C_V* v)
{
    return *(unsigned*)&v->mB3C;
}
void fn_8023DA90(Unk8023DA90_O* o, float f);
int fn_802542E8(Unk8024EF40_W* self, int a, int b);
int fn_8040B3B4(const char* a, const char* b);
extern const float lbl_805D9618;
extern const float lbl_805D961C;
extern const float lbl_805D9620;
extern const float lbl_805D9624;
extern const float lbl_805D9628;

extern const float lbl_805D9680;
extern const float lbl_805D9684;
extern const float lbl_805D9690;
extern int lbl_8061D4D0;
extern int lbl_8061D4D4;

int fn_80386110(Unk80271DBC_Link* link, Unk80279BB8* q, int a, int b, float* out, int c);
extern const float lbl_805D967C;

extern const Unk8024B99C_V3 lbl_806055DC;
int fn_8025416C(Unk8024EF40_W* self, int a);
float fn_801A20F8(Unk8022FE34_Ctx* c, int a, float f1, float f2);
float fn_801A2158(Unk8022FE34_Ctx* c, int a);
float fn_8024D0C4(Unk80270BA0_X* x, int a, float f1, float f2);
int fn_801A2034(Unk8022FE34_Ctx* c, int i);
Unk8027C728_Goal* fn_80244C84(Unk80270BA0_X* x);
int fn_8024E1B8(Unk80270BA0_X* x);
int fn_8024D144(Unk80270BA0_X* x);
int fn_8026DD60(Unk80270BA0_X* x, int a);
char* fn_8024D2E8(Unk80270BA0_X* x);
char* fn_8024D330(Unk80270BA0_X* x);
char* fn_8024D378(Unk80270BA0_X* x);
int fn_8023CB14(Unk80270BA0_X* x);
int fn_8024E3D8(Unk80270BA0_X* x, float f);

inline float FAt(const float* a, int i)
{
    int o = i * 4;
    return *(const float*)((const char*)a + o);
}

int fn_8023CB20(Unk80270BA0_X* x);
int fn_8023CB2C(Unk80270BA0_X* x);
int fn_8023CB38(Unk80270BA0_X* x);
extern const float lbl_8061D694[];
extern const float lbl_8061D6B0[];
extern const float lbl_8061D7D8[];
extern const float lbl_8061D7F8[];
extern const float lbl_805D9704;
extern const float lbl_805D9754;
extern const float lbl_8061D684[];
extern const float lbl_8061D674[];
extern const float lbl_8061D7E8[];
extern const float lbl_8061D808[];
extern const char lbl_805D9694[];
int fn_8024E860(Unk80270BA0_X* x, float f);
struct Unk8035DEAC;
int fn_8024DEC4(Unk80270BA0_X* x, int a);
extern const float lbl_805D96E4;
extern const float lbl_8061D6A4;
extern const float lbl_8061D6A8;
extern const float lbl_8061D6AC;
struct Unk8024E0A8_S {
    int m0;
    int m4;
    int m8;
    int mC;
};
struct Unk8024BE80_Q {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
};
struct Unk8024D4C0_R {
    char pad0[0x14];
    int m14;
};
void fn_8035DEAC(Unk8035DEAC* p);
void fn_8024EAE4(struct Unk8024EA50_T* t);
void fn_8024EB7C(struct Unk8024EA50_T* t);
void fn_8024EBE0(struct Unk8024EA50_T* t, int k);
float fn_8025454C(Unk8024EF40_W* w, int idx);
void fn_80254784(Unk8024EF40_A* a);
void fn_802526D8(void* p);
void fn_8024FF48(void* s);
void fn_8026C75C(Unk80270BA0_X* x, int a, Unk8022FE34_Ctx* c);
void fn_8026C8FC(Unk80270BA0_X* x);
void fn_8024DD80(Unk80270BA0_X* x);
void fn_8024DDDC(void* p);
/* 0x74-byte sub-object at x+0x360 / x+0x3D4 (fn_8024DD80 passes both): +0x20 a hashed name,
 * bitfields at +0x24 (7 bits) and +0x3C (10, 1, 5, 6 bits). */
struct Unk8024DDDC_T {
    char name[0x20];
    unsigned m20;
    unsigned a24 : 7;
    unsigned r24 : 25;
    int m28;
    int m2C;
    int m30;
    int m34;
    union {
        int m38;
        struct {
            unsigned f0 : 1;
            unsigned f1 : 4;
            unsigned f5 : 4;
            unsigned f9 : 3;
            unsigned f12 : 7;
            unsigned f19 : 3;
            unsigned r38 : 10;
        };
    };
    unsigned a3C : 10;
    unsigned b3C : 1;
    unsigned c0 : 1;
    unsigned c1 : 1;
    unsigned c2 : 1;
    unsigned c3 : 1;
    unsigned c4 : 1;
    unsigned d3C : 6;
    unsigned r3C : 10;
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    int m5C;
    int m60;
    int m64;
    int m68;
    int m6C;
    int m70;
};
struct Unk8024C118_V {
    char pad0[0x360];
    Unk8024DDDC_T s0;
    Unk8024DDDC_T s1;
};
extern "C" char* strcpy(char* d, const char* s);
extern "C" void fn_803296AC();
extern const float lbl_805D9770;
extern const float lbl_805D9774;
extern char lbl_80661498[];
extern char lbl_80661510[];
extern char lbl_806615A0[];

/* 0x4C-byte element of the two-element table at the start of Unk8024EA50_T (ctor fn_8024EA50:
 * fn_8035DEAC on each element, seven floats at +0xC..+0x24; fn_8024EAE4 clears +0, +4, +8 and the
 * three int triples at +0x28, +0x34, +0x40). */
struct Unk8024EA50_F {
    float m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
};
struct Unk8024EA50_E {
    float m0;
    float m4;
    float m8;
    Unk8024EA50_F f;
    int a28[3];
    int a34[3];
    int a40[3];
};
struct Unk8024EA50_T {
    Unk8024EA50_E e[2];
    float m98;
    float m9C;
    Unk8024EF40_P* mA0;
    const void* mA4;
};
inline void InitF(Unk8024EA50_F* f)
{
    f->m0 = lbl_805D9770;
    f->m4 = lbl_805D9770;
    f->m8 = lbl_805D9770;
    f->mC = lbl_805D9770;
    f->m10 = lbl_805D9770;
    f->m14 = lbl_805D9770;
    f->m18 = lbl_805D9770;
}

inline void InitE(Unk8024EA50_E* e)
{
    InitF(&e->f);
    fn_8035DEAC((Unk8035DEAC*)e);
}

inline void ClearE(Unk8024EA50_E* e)
{
    e->m0 = lbl_805D9774;
    e->m4 = lbl_805D9774;
    e->m8 = lbl_805D9774;
    for (int i = 0; i < 3; i++) {
        e->a28[i] = 0;
        e->a34[i] = 0;
        e->a40[i] = 0;
    }
}

void fn_8024BE80(Unk80270BA0_X* x, int k)
{
    if (k == 0xD || k == -1)
        x->fn_vslot8(1);
    if (x->m458 != k) {
        x->m458 = k;
        ((Unk8024BE80_Q*)((char*)x + 0xA0))->v13();
    }
}

int fn_8024E9C0(Unk80270BA0_X* x, float f);
extern const float lbl_805D976C;

void fn_8024BF04(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (v->m8D4 < v->m8D8)
        v->m8D4++;
}

extern const double lbl_805D9548;
extern const float lbl_805D9550;

float fn_8024BF20(Unk80270BA0_X* x, float f)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    int a = v->m8D4;
    int b = v->m8D8;
    if (a < b && b > 0) {
        float t = (float)a / (float)b;
        float q = lbl_805D9550 - t;
        float p = f * t;
        p = v->m8D0 * q + p;
        return p;
    }
    return f;
}

void fn_8024BFD0(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (v->m8E0 < v->m8E4)
        v->m8E0++;
}

extern const float lbl_805D9560;

float fn_8024BFEC(Unk80270BA0_X* x, float f)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    int a = v->m8E0;
    int b = v->m8E4;
    if (a < b && b > 0) {
        float t = (float)a / (float)b;
        float q = lbl_805D9560 - t;
        float p = f * t;
        p = v->m8DC * q + p;
        return p;
    }
    return f;
}

/* near-miss: retail emits 'li r0,0; b end' for the k <= 27 arm; ours threads it into 'ble end' (12 vs 13 insns).
   Tried nested-if, ternary and if/else-chain forms */
int fn_8024C09C(unsigned k)
{
    int r = 1;
    if (k > 25) {
        if (k <= 27)
            r = 0;
        else if (k <= 34)
            r = 1;
        else
            r = 2;
    }
    return r;
}

void fn_8024C0D0(int v)
{
    char* p = (char*)v;
    fn_80254784((Unk8024EF40_A*)(p + 0x58C));
    fn_802526D8(p + 0x480);
    fn_8024FF48(p + 0x4D8);
    fn_8024EB7C((Unk8024EA50_T*)(p + 0xA0C));
}

extern "C" void fn_8024C118(void* o)
{
    Unk8024C118_V* v = (Unk8024C118_V*)o;
    v->s0.a3C = 0x385;
    v->s0.b3C = 0;
    strcpy(v->s0.name, "");
    v->s0.m20 = fn_80378568(v->s0.name, 0);
    v->s0.d3C = 0;
    v->s0.f1 = 6;
    v->s0.f5 = 0;
    v->s0.f9 = 0;
    v->s0.f19 = 0;
    v->s0.a24 = 0;
    v->s1 = v->s0;
    fn_803296AC();
}

void fn_8024CC08(Unk80270BA0_X* x)
{
    char a[0x40] = "";
    char b[0x40] = "";
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (v->m708 != 2) {
        Unk8024EF40_W* w = (Unk8024EF40_W*)((char*)x + 0x588);
        fn_802542E8(w, 1, (int)a);
        fn_802542E8(w, 0, (int)b);
        Fl4C08(v) &= 0xF0FFFFFF;
        if (fn_8040B3B4(a, "paterson") == 0) {
            if (fn_8040B3B4(b, "keegan") == 0) {
                Fl4C08(v) |= 0x03000000;
                fn_8023DA90((Unk8023DA90_O*)x, lbl_805D9618);
            }
            if (fn_8040B3B4(b, "jacob") == 0) {
                Fl4C08(v) |= 0x03000000;
                fn_8023DA90((Unk8023DA90_O*)x, lbl_805D961C);
            }
            if (fn_8040B3B4(b, "isaiah") == 0) {
                Fl4C08(v) |= 0x03000000;
                fn_8023DA90((Unk8023DA90_O*)x, lbl_805D9620);
            }
            if (fn_8040B3B4(b, "sean") == 0) {
                Fl4C08(v) |= 0x03000000;
                fn_8023DA90((Unk8023DA90_O*)x, lbl_805D9624);
            }
        }
        if (fn_8040B3B4(a, "curran") == 0 && fn_8040B3B4(b, "mark") == 0)
            Fl4C08(v) |= 0x08000000;
        if (fn_8040B3B4(a, "kram") == 0 && fn_8040B3B4(b, "les") == 0)
            Fl4C08(v) |= 0x08000000;
        if (fn_8040B3B4(a, "clark") == 0 && fn_8040B3B4(b, "g") == 0)
            Fl4C08(v) |= 0x08000000;
        if (fn_8040B3B4(a, "larmour") == 0 && fn_8040B3B4(b, "avery") == 0) {
            Fl4C08(v) |= 0x05000000;
            fn_8023DA90((Unk8023DA90_O*)x, lbl_805D9628);
        }
    }
}

float fn_8024D050(Unk80270BA0_X* x, int a, int b, float f1, float f2)
{
    float r;
    if (fn_8024D144(x))
        r = fn_8024D0C4(x, a, f1, f2);
    else
        r = fn_8024D0C4(x, b, f1, f2);
    return r;
}

float fn_8024D0C4(Unk80270BA0_X* x, int a, float f1, float f2)
{
    return fn_801A20F8(((Unk8024B99C_V*)x)->m44C, a, f1, f2);
}

float fn_8024D0F8(Unk80270BA0_X* x, int a)
{
    return fn_801A2158(((Unk8024B99C_V*)x)->m44C, a);
}

int fn_8024D11C(Unk80270BA0_X* x)
{
    return fn_8024D144(x) == 0;
}

int fn_8024D144(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    return fn_801A2034(v->m44C, v->m708) == -1;
}

void fn_8024D178(Unk80270BA0_X* x, int a)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    v->m918 = a;
    v->m91C = lbl_806055DC;
}

void fn_8024D1A4(Unk80270BA0_X* x, const Unk8024B99C_V3* p)
{
    ((Unk8024B99C_V*)x)->m8F8 = *p;
}

char* fn_8024D1C4(Unk80270BA0_X* x)
{
    char* r = 0;
    Unk8027C728_Goal* g = fn_80244C84(x);
    while (g) {
        if (g->m10 == 6) {
            r = g->m18;
            break;
        }
        g = g->m0;
    }
    return r;
}

char* fn_8024D218(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (g) {
        char* r = 0;
        if (g->m10 == 6)
            r = g->m18;
        return r;
    }
    return 0;
}

int fn_8024D260(Unk80270BA0_X* x)
{
    if ((unsigned)((Unk8024B99C_V*)x)->m458 <= 8) {
        if (fn_8024D378(x) != 0)
            return 1;
        char* p = fn_8024D2E8(x);
        if (p) {
            if (*(int*)(p + 0x60) != 0)
                return 1;
        }
        p = fn_8024D330(x);
        if (p) {
            if (*(int*)(p + 0x78) != 0)
                return 1;
        }
    }
    return 0;
}

static inline char* GoalData10(Unk8027C728_Goal* g)
{
    if (g) {
        char* r = 0;
        if (g->m10 == 10)
            r = g->m18;
        return r;
    }
    return 0;
}

char* fn_8024D2E8(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (g) {
        char* r = 0;
        if (g->m10 == 14)
            r = g->m18;
        return r;
    }
    return 0;
}

char* fn_8024D330(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (g) {
        char* r = 0;
        if (g->m10 == 10)
            r = g->m18;
        return r;
    }
    return 0;
}

char* fn_8024D378(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (g) {
        char* r = 0;
        if (g->m10 == 13)
            r = g->m18;
        return r;
    }
    return 0;
}

char* fn_8024D3C0(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (g) {
        char* r = 0;
        if (g->m10 == 5)
            r = g->m18;
        return r;
    }
    return 0;
}

extern "C" int fn_8024D408(Unk80270BA0_X* x)
{
    return (unsigned)((Unk8024B99C_V*)x)->m458 <= 5;
}

int fn_8024D41C(Unk80270BA0_X* x)
{
    return (unsigned)(((Unk8024B99C_V*)x)->m458 - 6) <= 2;
}

int fn_8024D434(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (fn_8026DD60(x, 0) == 0) {
        char* p = GoalData10(g);
        if (p)
            return (unsigned)(*(int*)(p + 0x4c) - 11) <= 5;
    }
    return 0;
}

int fn_8024D4C0(Unk80270BA0_X* x)
{
    int a = 0x10, b = 0xF;
    if (x->m458 == a || x->m458 == b)
        return 1;
    Unk8024D4C0_R* r = *(Unk8024D4C0_R**)((char*)x->m44C + 0x564);
    int v = r->m14;
    int lo = 1, hi = 2;
    if (v <= hi && v >= lo)
        return 1;
    return 0;
}

class Unk8024D9A0_VT {
public:
    char pad0[0x98];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};
extern const float lbl_8061D780[];
extern const char lbl_805D9188[];
extern int lbl_8061D3C4;
int fn_802536D0(Unk8024EF40_P* p);
int fn_8024D708(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (lbl_8061D3C4 != 0)
        return 1;
    float t = v->m540;
    int k = fn_8024E3D8(x, t);
    fn_8023CB20(x);
    float chance = lbl_8061D780[k];
    const float z = 0.0f;
    float arr[4] = { 2.0f, 2.4f, 2.6f, 2.8f };
    float m = fn_8024D0C4(x, 0x1F, z, arr[fn_802536D0((Unk8024EF40_P*)x)]);
    chance = chance * m;
    chance = !(chance > 100.0f) ? (chance >? z) : 100.0f;
    float r = RandPct((Unk8024EF40_P*)x, lbl_805D9188, 0x3271);
    return r <= chance;
}

int fn_8024D8A0(Unk80270BA0_X* x, int* outA, float* outB)
{
    Unk8027C728_Goal* g = ((Unk8024B99C_V*)x)->m934;
    int r = 0;
    if (outA)
        *outA = 0;
    if (outB)
        *outB = lbl_805D967C;
    if (g) {
        char* p = 0;
        if (g->m10 == 0x11)
            p = g->m18;
        if (p) {
            int k = *(int*)(p + 0x48);
            if ((unsigned)(k - 1) <= 1 && *(int*)(p + 0x4C) != 0) {
                r = 1;
                if (outB) {
                    Unk80279BB8 q(x);
                    float f;
                    Unk80271DBC_Link* l = x->m618;
                    if (fn_80386110(l, &q, l->m838, 0xA0756559, &f, 0) & 0x10000)
                        *outB = f;
                }
                if (k == 1 && outA)
                    *outA = k;
            }
        }
    }
    return r;
}

int fn_8024D9A0(Unk80270BA0_X* x, int* out)
{
    int r = 0;
    Unk8024EF40_W* w = (Unk8024EF40_W*)((char*)x + 0x588);
    int a = fn_8025416C(w, 0x21);
    int b = fn_8025416C(w, 0);
    if (((Unk8024D9A0_VT*)x)->v4()) {
        if (a == 37 && b == 461) {
            r = 1;
            *out = 2;
        }
        else if (a == 17 && b == 333) {
            r = 1;
            *out = 3;
        }
        else if (a == 15 && b == 302) {
            r = 1;
            *out = 4;
        }
        else if (a == 26 && b == 660) {
            r = 1;
            *out = 13;
        }
        else if (a == 0 && b == 240) {
            r = 1;
            *out = 14;
        }
    } else {
        if (a == 35 && b == 830) {
            r = 1;
            *out = 5;
        }
        else if (a == 9 && b == 832) {
            r = 1;
            *out = 6;
        }
        else if (a == 36 && b == 96) {
            r = 1;
            *out = 7;
        }
        else if (a == 52 && b == 1239) {
            r = 1;
            *out = 8;
        }
        else if (a == 21 && b == 757) {
            r = 1;
            *out = 9;
        }
        else if (a == 12 && b == 339) {
            r = 1;
            *out = 10;
        }
        else if (a == 19 && b == 808) {
            r = 1;
            *out = 11;
        }
        else if (a == 8 && b == 724) {
            r = 1;
            *out = 12;
        }
    }
    return r;
}

void fn_8024DB54() {}

/* near-miss: 3 slots differ: retail numbers the hi reload f0 and the constant f13 in the last compare.
   A "case 4:" label before default makes the switch root 2 as in retail. Tried switch/if forms, declaration orders, operand orders */
void fn_8024DB58(Unk80270BA0_X* x, int k, float* e)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    float lo = lbl_805D9680;
    float hi = lbl_805D9680;
    if (k == 13) {
        lo = e[1];
        hi = e[2];
    } else if (k == 14) {
        lo = e[1];
        hi = e[2];
    }
    if (!(lo < lbl_805D9684)) {
        float t[4];
        float frac;
        float w;
        float r;
        volatile int pad;
        float s;
        int i = (int)lo;
        frac = lo - (float)i;
        t[0] = v->m720;
        t[1] = v->m724;
        t[2] = v->m728;
        t[3] = v->m72C;
        w = lbl_805D9684 - frac;
        r = lbl_805D9680;
        switch (i) {
        case 0:
            break;
        case 1:
            r = w * t[0] + frac * t[1];
            break;
        case 2:
            r = w * t[1] + frac * t[2];
            break;
        case 3:
            r = w * t[2] + frac * t[3];
            break;
        case 4:
        default:
            r = t[3];
            break;
        }
        s = r;
        v->m8D4 = 0;
        v->m8D8 = lbl_8061D4D0;
        v->m8D0 = s;
    }
    if (hi > lbl_805D9690 || !(hi >= lbl_805D9690)) {
        float s2;
        float r2 = lbl_805D9690 * hi;
        s2 = r2;
        v->m8E4 = lbl_8061D4D4;
        v->m8E0 = 0;
        v->m8DC = s2;
    }
}

int fn_8024DCFC(int k)
{
    if (k == 17 || k == 18 || k == 30 || k == 24)
        return 1;
    return 0;
}

Unk80270BA0_X* fn_8024DD28(Unk80270BA0_X* x, int a, Unk8022FE34_Ctx* c)
{
    fn_8026C75C(x, a, c);
    ((Unk8024B99C_V*)x)->m44C = c;
    *(const void**)((char*)x + 0xB8) = lbl_80661510;
    *(const void**)((char*)x + 0x98) = lbl_806615A0;
    fn_8024DD80(x);
    return x;
}

void fn_8024DD80(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    fn_8026C8FC(x);
    fn_8024DDDC((char*)x + 0x360);
    fn_8024DDDC((char*)x + 0x3D4);
    v->m448 = 0;
    v->m450 = 0;
    v->m454 = 0;
    v->m458 = -1;
    v->m45C = -1;
    v->m460 = -1;
}

extern const float lbl_8061D634[];
extern const float lbl_8061D634[];
extern int lbl_8061D460;
extern int lbl_8061D468;
void fn_8024DDDC(void* p)
{
    Unk8024DDDC_T* t = (Unk8024DDDC_T*)p;
    t->m20 = fn_80378568("", 0);
    t->a24 = 0;
    t->m30 = 0x48;
    t->m34 = 200;
    t->f0 = 0;
    t->f1 = 0;
    t->f5 = 0;
    t->f9 = 0;
    t->f12 = 0;
    t->f19 = 0;
    t->r38 = 0;
    t->m28 = 0;
    t->m2C = 0;
    t->a3C = 0x385;
    t->b3C = 0;
    if (lbl_8061D460 != 0)
        t->a3C = lbl_8061D468;
    t->m70 = 0;
    t->m40 = 0;
    t->m44 = 0;
    t->c0 = 0;
    t->c1 = 0;
    t->c2 = 0;
    t->c3 = 0;
    t->c4 = 0;
    t->m48 = 0;
    t->m4C = 0;
    t->m50 = 0;
    t->m54 = 0;
    t->m58 = 0;
    t->m64 = 0;
    t->m68 = 0;
    t->m5C = 0;
    t->m60 = 0;
    t->m6C = 0;
    t->d3C = 0;
}

int fn_8024DEC4(Unk80270BA0_X* x, int idx)
{
    float prev = 0.0f;
    float sum = 0.0f;
    float r = RandPct((Unk8024EF40_P*)x, lbl_805D9694, 0x6F);
    fn_8023CB14(x);
    const float* p = lbl_8061D634 + idx * 4;
    for (int i = 0; i < 4; i++) {
        float w = *p++;
        sum += w;
        if (!(r < prev) && r < sum)
            return i;
        prev = sum;
    }
    return 3;
}

int fn_8024DFD4(Unk80270BA0_X* x, float f)
{
    for (int i = 0; i < 3; i++) {
        fn_8023CB14(x);
        int o = i * 4;
        float t = *(const float*)((const char*)lbl_8061D694 + o);
        if (!(f >= t))
            return i;
    }
    return 3;
}

float fn_8024E050(Unk80270BA0_X* x, int idx, int flag)
{
    if (flag == 1) {
        fn_8023CB14(x);
        return lbl_8061D674[idx];
    } else {
        fn_8023CB14(x);
        return lbl_8061D684[idx];
    }
}

float fn_8024E0A8(Unk80270BA0_X* x, Unk8024E0A8_S* s)
{
    float t = ((Unk8024B99C_V*)x)->m540;
    t = t * lbl_805D96E4;
    if (s->m8 == 1) {
        fn_8023CB14(x);
        t = t + lbl_8061D6A4;
    }
    if (s->m0 == 1) {
        fn_8023CB14(x);
        t = t + lbl_8061D6A8;
    }
    if (s->m4 == 1) {
        fn_8023CB14(x);
        t = t + lbl_8061D6AC;
    }
    int a = fn_8024DFD4(x, t);
    int b = fn_8024DEC4(x, a);
    float r = fn_8024E050(x, b, s->mC);
    return r;
}

int fn_8024E194(Unk80270BA0_X* x)
{
    return fn_8024E1B8(x) ^ 1;
}

int fn_8024E3D8(Unk80270BA0_X* x, float f)
{
    float s = f * lbl_805D9704;
    for (int i = 0; i < 3; i++) {
        fn_8023CB20(x);
        int o = i * 4;
        float t = *(const float*)((const char*)lbl_8061D6B0 + o);
        if (!(s >= t))
            return i;
    }
    return 3;
}

inline float Unk8024E468_Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}
inline float Unk8024E468_Rand(Unk8024EF40_P* x, const char* f, int line)
{
    float k = 1.0f;
    return (float)fn_8014D8AC(x->m44C->m554, 1000000, f, line) * k * 0.000001f;
}
int fn_8024E468(Unk80270BA0_X* x)
{
    const float lo = 0.5f;
    const float hi = 0.95f;
    float t = 1.0f - ((Unk8024B99C_V*)x)->m540;
    float p = Unk8024E468_Lerp(lo, t, hi);
    return Unk8024E468_Rand((Unk8024EF40_P*)x, lbl_805D9694, 0x139) < p;
}

struct Unk8024E540_E {
    float a;
    float b;
};
extern const Unk8024E540_E lbl_8061D760[];
int fn_8024E540(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    Unk8022FE34_Ctx* c = v->m44C;
    if (c == 0)
        return 0;
    char* g = c->m6F8->m10;
    if (g != 0 && *(int*)(g + 0x28) == 0)
        return 0;
    float t = v->m540;
    int k = fn_8024E3D8(x, t);
    fn_8023CB20(x);
    float chance = lbl_8061D760[k].b;
    float m = fn_8024D050(x, 0x1D, 0x1C, 0.0f, 2.0f);
    chance = chance * m;
    chance = !(chance > 100.0f) ? (chance >? 0.0f) : 100.0f;
    return RandPct((Unk8024EF40_P*)x, lbl_805D9694, 0x15C) < chance;
}

int fn_8024E6A4(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    Unk8022FE34_Ctx* c = v->m44C;
    if (c == 0)
        return 0;
    char* g = c->m6F8->m10;
    if (g != 0 && *(int*)(g + 0x28) == 0)
        return 0;
    float t = v->m540;
    int k = fn_8024E3D8(x, t);
    fn_8023CB20(x);
    float chance = lbl_8061D760[k].a;
    float m = fn_8024D050(x, 0x1D, 0x1C, 0.0f, 2.0f);
    chance = chance * m;
    chance = !(chance > 100.0f) ? (chance >? 0.0f) : 100.0f;
    return RandPct((Unk8024EF40_P*)x, lbl_805D9694, 0x17F) < chance;
}

float fn_8024E804(Unk80270BA0_X* x)
{
    float t = ((Unk8024B99C_V*)x)->m538;
    int k = fn_8024E860(x, t);
    fn_8023CB2C(x);
    int o = k * 4;
    float r = *(const float*)((const char*)lbl_8061D7E8 + o);
    return r;
}

int fn_8024E860(Unk80270BA0_X* x, float f)
{
    float s = f * lbl_805D9754;
    for (int i = 0; i < 3; i++) {
        fn_8023CB2C(x);
        int o = i * 4;
        float t = *(const float*)((const char*)lbl_8061D7D8 + o);
        if (!(s >= t))
            return i;
    }
    return 3;
}

int fn_8024E8F0(Unk80270BA0_X* x)
{
    float t = ((Unk8024B99C_V*)x)->m4A0;
    int k = fn_8024E9C0(x, t);
    fn_8023CB38(x);
    int o = k * 4;
    float chance = *(const float*)((const char*)lbl_8061D808 + o);
    float pct = RandPct((Unk8024EF40_P*)x, lbl_805D9694, 0x1C7);
    return chance > pct;
}

int fn_8024E9C0(Unk80270BA0_X* x, float f)
{
    float s = f * lbl_805D976C;
    for (int i = 0; i < 3; i++) {
        fn_8023CB38(x);
        int o = i * 4;
        float t = *(const float*)((const char*)lbl_8061D7F8 + o);
        if (!(s >= t))
            return i;
    }
    return 3;
}

Unk8024EA50_T* fn_8024EA50(Unk8024EA50_T* t, Unk8024EF40_P* p)
{
    t->mA4 = lbl_80661498;
    Unk8024EA50_E* e = t->e;
    int k = 1;
    do {
        InitE(e);
        e++;
    } while (k-- != 0);
    t->mA0 = p;
    fn_8024EAE4(t);
    return t;
}

void fn_8024EAE4(Unk8024EA50_T* t)
{
    t->m98 = lbl_805D9774;
    t->m9C = lbl_805D9774;
    t->e[0].m0 = lbl_805D9774;
    t->e[0].m4 = lbl_805D9774;
    t->e[0].m8 = lbl_805D9774;
    for (int i = 0; i < 3; i++) {
        t->e[0].a28[i] = 0;
        t->e[0].a34[i] = 0;
        t->e[0].a40[i] = 0;
    }
    ClearE(&t->e[1]);
}

void fn_8024EB7C(Unk8024EA50_T* t)
{
    fn_8024EBE0(t, 0);
    fn_8024EBE0(t, 1);
    t->m98 = fn_8025454C(&t->mA0->m588, 0xC);
    t->m9C = fn_8025454C(&t->mA0->m588, 0x13);
}
