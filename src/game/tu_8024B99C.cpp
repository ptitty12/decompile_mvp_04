/*
 * Game code, .text 0x8024B99C-0x8024EF40 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024B99C.h"
#include "game/chooser.h"
#include "game/tu_8024EF40.h"

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
