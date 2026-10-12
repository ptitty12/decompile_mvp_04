/*
 * Game code, .text 0x80246D04-0x8024B99C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024B99C.h"
#include "game/chooser.h"
#include "game/tu_8026C414.h"
#include "game/goals/tu_8027A84C.h"
#include "game/goals/tu_8028C6B8.h"

struct Unk80249070_A {
    char pad0[0x38];
    int m38;
    char pad3C[0x4C - 0x3C];
    float m4C;
};
struct Unk80256C80_M;
int fn_80259440(Unk80256C80_M* self);
float fn_8024902C();
float fn_80249048(Unk80270BA0_X* x);
float fn_80249064(Unk80270BA0_X* x);
float fn_8024D0C4(Unk80270BA0_X* x, int a, float f1, float f2);
extern const float lbl_805D93B8;
inline float Unk80249070_Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}

struct Unk802494C4_Obj {
    char pad0[0x110];
    int m110;
};
struct Unk802494C4_C {
    char pad0[0x6F8];
    Unk8022FE34_Game* m6F8;
    char pad6FC[0x738 - 0x6FC];
    void* m738;
};
struct Unk802494C4_X {
    char pad0[0x60];
    Unk80273498_Vec3 m60;
    char pad6C[0x44C - 0x6C];
    Unk802494C4_C* m44C;
    char pad450[0xAC4 - 0x450];
    int mAC4;
    char pad_AC8[0xAD0 - 0xAC8];
    float mAD0;
    Unk80273498_Vec3 mAD4;
};
extern Unk802494C4_Obj* lbl_8061FE10;
extern const float lbl_805D9410;
extern const float lbl_805D9414;
extern const float lbl_805D9418;
extern float lbl_8061D4C0;
extern "C" void fn_8030D1E4(void* pp, int idx, Unk80273498_Vec3* a, void* b, int depth, float f);

/* Views of the player object for fn_8024A468 (offsets from the asm). */
struct Unk8024A468_Sub {
    char pad0[0x20];
    int m20;
};
struct Unk8024A468_Ref {
    char pad0[0x44];
    int m44;
};
struct Unk8024A468_Ctx {
    char pad0[0x54C];
    Unk8024A468_Ref* m54C;
    char pad550[0x6CC - 0x550];
    Unk8026C414_M* m6CC;
    char pad6D0[0x744 - 0x6D0];
    Unk8024A468_Sub* m744;
};
struct Unk8024A468_X {
    char pad0[0x44C];
    Unk8024A468_Ctx* m44C;
    char pad450[0x71C - 0x450];
    unsigned m71C;
    char pad720[0xAB8 - 0x720];
    int mAB8;
    char padABC[0xB20 - 0xABC];
    char mB20[0xC];
    char mB2C[0xC];
    float mB38;
    unsigned mB3C;
};
extern int lbl_8061D2B4;
extern const float lbl_805D94C0;
Unk8026C414_V3 fn_8026CB70(Unk8026C414_M* self, int i);
extern "C" void fn_8038AC30(int a, float f, const Unk8026C414_V3& b, int c, void* d);

extern "C" void fn_80244A64(Unk80270BA0_X* x, Unk8027C728_Goal* g, int flag);
extern "C" void fn_8037EBE8(Unk80271DBC_Link* l);
extern "C" void fn_803814A4(Unk80271DBC_Link* l, unsigned hash, int a, float b);
extern const float lbl_805D94C4;

/* Frames to seconds through an inline: the constant-pool loads the inliner copies are not
 * unchanging, so sched1 keeps them below preceding stores (retail's order). */
template <class T> inline float Unk80246D04_Secs(T n)
{
    return (float)n * 0.016666668f;
}

extern const float lbl_805D93D0;
extern const float lbl_805D93D4;
extern const float lbl_805D93D8;
extern const float lbl_805D93DC;
extern const float lbl_805D93E0;
extern const float lbl_805D93E4;
extern const float lbl_805D93E8;
extern const float lbl_805D93EC;
extern const float lbl_805D93F0;
extern const float lbl_805D93F4;
extern const float lbl_805D9484;
float fn_80248370(Unk80270BA0_X* x, Unk80273498_Vec3* p, Unk80273498_Vec3* q, int c, int d, int e);
void fn_80254784(void* p);

extern const float lbl_805D93AC;
extern const float lbl_805D93B0;
extern const float lbl_805D93B4;
extern const float lbl_805D93CC;
extern const float lbl_805D9440;
extern float lbl_8061D4B4;
void fn_8014E498(Unk80273498_Vec3 v);
float fn_80249070(Unk80270BA0_X* x);
void fn_80249750(Unk80270BA0_X* x);
void fn_80249B40(Unk80270BA0_X* x, Unk80273498_Pos* p, int a, int b, float f);
void fn_80249D64(Unk80270BA0_X* x, int a);
float fn_8023C868(Unk80270BA0_X* x);

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline float Unk80246D04_LenSq(const Unk80273498_Vec3& v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

inline Unk80273498_Vec3 Unk80246D04_Copy(const Unk80273498_Vec3* p)
{
    return *p;
}

extern const float lbl_805D9278;
extern "C" Unk8027C728_Goal* fn_802448F4(Unk80270BA0_X* p, int k);
void fn_8027C728(Unk8027C728_Goal* g);
int fn_8027D390(Unk8027C728_Goal* g, float* a, Unk80273498_Vec3* b, Unk80273498_Vec3* c, float* d);
void fn_8027D368(Unk8027C728_Goal* g);

extern const float lbl_805D9270;
void fn_8024A674(Unk80270BA0_X* x, Unk80273498_Pos* p);
extern "C" void fn_80255058__Fv(void* p);
float fn_804028E4(float x);

int fn_8024778C(Unk80270BA0_X* x, Unk80273498_Vec3* p)
{
    Unk80273498_Pos* t = ((Unk8024B99C_V*)x)->m928;
    if (t != 0) {
        if (!(fn_804028E4(Unk80246D04_LenSq(*p - t->m60)) >= lbl_805D9270)) {
            fn_8024A674(x, t);
            fn_80255058__Fv((char*)t + 0x58C);
        }
    }
    return 1;
}

void fn_80247858(Unk80270BA0_X* x)
{
    fn_8014E498(x->m60);
}

float fn_804028E4(float x);
float fn_8024796C(Unk80270BA0_X* x, int b, int c, int d, int e, float* f, int g, Unk80273498_Vec3* h, float dist);
float atan2f(float y, float x);
/* near-miss (99.5%, 6 slots): retail keeps x in r29 and e in r28; ours has them swapped (callee-saved allocation of two
   equal-priority parameters); tried single-call, result-variable and else forms */
extern "C" float fn_802478A0(void* o, void* p, int a, int b)
{
    float f;
    Unk8027C728_Goal* g = fn_802448F4((Unk80270BA0_X*)o, 1);
    Unk8027A84C* g104;
    ((Unk8028C6B8_Goal*)(g->m10 = 4, g104 = (Unk8027A84C*)g->m104, fn_8027C728(g), g->m18))->fn_8028ED30(*(Unk80273498_Vec3*)p);
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m38 = a;
    g104->m38 = a;
    ((Unk8027A84C_Owner*)g)->fn_8027C67C()->m40 = b;
    g104->m40 = b;
    if (fn_8027D390(g, &f, 0, 0, 0) == 0)
        f = lbl_805D9278;
    fn_8027D368(g);
    return f;
}

float fn_80248370(Unk80270BA0_X* x, Unk80273498_Vec3* p, Unk80273498_Vec3* q, int c, int d, int e)
{
    float len = fn_804028E4((p->x - q->x) * (p->x - q->x) + (p->z - q->z) * (p->z - q->z));
    if (len > 24.0f) {
        float ang = atan2f(q->x - p->x, q->z - p->z);
        return fn_8024796C(x, 0, c, d, e, &ang, 0, q, len);
    }
    return fn_8024796C(x, 0, c, d, e, 0, 0, q, len);
}

extern "C" float fn_80248450(Unk80270BA0_X* x, int a, int b, int c)
{
    return fn_80248370(x, &x->m60, (Unk80273498_Vec3*)a, b, c, 0);
}

float fn_80248F70(Unk80270BA0_X* x, float f)
{
    float a = ((Unk8024B99C_V*)x)->m8EC;
    if (((Unk8024B99C_V*)x)->m458 != -1) {
        float r = fn_8023C868(x);
        a = a * r;
    }
    return a * f;
}

float fn_80248FC8(Unk80270BA0_X* x, int k)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    float r = lbl_805D93AC;
    switch (k) {
    case 3:
    case 4:
        r = v->m72C;
        break;
    case 2:
        r = v->m728;
        break;
    case 1:
        r = v->m724;
        break;
    case 0:
        r = v->m720;
        break;
    }
    return r;
}

float fn_8024902C()
{
    float r = lbl_805D93B0;
    return r;
}

float fn_80249048(Unk80270BA0_X* x)
{
    float r = lbl_805D93B4;
    return r;
}

float fn_80249064(Unk80270BA0_X* x)
{
    return lbl_8061D4B4;
}

float fn_80249070(Unk80270BA0_X* x)
{
    float a = fn_8024902C();
    float b = fn_80249048(x);
    Unk80249070_A* ctl = (Unk80249070_A*)((char*)x + 0x58C);
    float t = ctl->m4C;
    if (x->m458 == 9 && ctl->m38 < 0) {
        Unk8027107C_Outer* o = x->m44C->m700;
        if (o != 0 && fn_80259440((Unk80256C80_M*)o->m3B4) != 0) {
            float d = fn_80249064(x);
            float e = d - (a - d);
            float g = fn_8024D0C4(x, 0x3F, e, a);
            b = g;
        }
    }
    if (!(t >= lbl_805D93B8))
        t = lbl_805D93B8;
    float r = Unk80249070_Lerp(b, t, a);
    return fn_80248F70(x, r);
}

float fn_80249188(Unk80270BA0_X* x, float f)
{
    float c = lbl_805D93CC;
    float p = fn_80249070(x);
    float r = c + f * (p - c);
    return r;
}

void fn_802491D8(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    Unk8022FE34_Ctx* c = v->m44C;
    if (c && c->m6F4 != 1 && v->m708 != 2) {
        int m = *(int*)((char*)x + 0x704);
        if (m != 0) {
            char* row = (char*)c->m6F8->m14 + v->m708 * 0xE64;
            if (m != *(int*)(row + 0x1A0))
                fn_80254784((char*)x + 0x58C);
        }
    }
    float f = fn_80249070(x);
    v->m728 = f * lbl_805D93D0;
    v->m724 = f * lbl_805D93D4;
    v->m72C = f;
    v->m720 = f * lbl_805D93D8;
}

float fn_80249298(Unk80270BA0_X* x, int a, int b)
{
    float r = lbl_805D93DC;
    switch (a) {
    case 0:
        r = lbl_805D93E0;
        break;
    case 1:
    case 2:
    case 3:
        r = lbl_805D93E4;
        break;
    case 4:
    case 7:
        r = lbl_805D93E8;
        break;
    case 5:
    case 8:
        r = lbl_805D93EC;
        break;
    case 6:
    case 9:
    case 10:
        r = lbl_805D93F0;
        break;
    case 11:
        r = lbl_805D93F4;
        break;
    }
    if (b != 0)
        return r * r;
    return r;
}

struct Unk802495CC_C {
    char pad0[0x4C];
    unsigned m4C;
    char pad50[0x738 - 0x50];
    int m738;
};
struct Unk802495CC_X {
    char pad0[0x44C];
    Unk802495CC_C* m44C;
    char pad450[0xAC4 - 0x450];
    int mAC4;
    float mAC8;
    float mACC;
    float mAD0;
};
extern float lbl_8061D4C4;
void fn_802494C4(Unk80270BA0_X* x, int a, float f);
void fn_802495CC(Unk802495CC_X* x)
{
    Unk802495CC_C* c = x->m44C;
    if (c->m738 != 0) {
        float s = (float)c->m4C * 0.016666668f;
        if (x->mAC4 == 0) {
            if (!(x->mAC8 <= 0.0f) && !(s < x->mAC8))
                fn_802494C4((Unk80270BA0_X*)x, 1, s);
        } else {
            if (!(s <= x->mAD0 + lbl_8061D4C4)) {
                if (!(s >= x->mACC)) {
                    fn_802494C4((Unk80270BA0_X*)x, 0, s);
                } else {
                    x->mAC4 = 0;
                    x->mAC8 = -1.0f;
                    x->mACC = -1.0f;
                }
            }
        }
    }
}

void fn_802496BC(Unk80270BA0_X* x, int a)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    v->mAE0 = a;
    v->mAE4 = Unk80246D04_Secs(x->m44C->m4C);
    v->mAE8 = 1;
    fn_80249750(x);
}

void fn_80249724(Unk80270BA0_X* x)
{
    if (((Unk8024B99C_V*)x)->mAE8 != 0)
        fn_80249750(x);
}

void fn_80249B08(Unk80270BA0_X* x, int a, float f)
{
    fn_80249B40(x, x->m44C->m6CC, a, 1, f);
}

/* near-miss: retail compares s < 1 (cmpwi 1; bltlr); g++ folds s >= 1 into s > 0 (4 forms tried) */
int fn_80249D44(Unk80270BA0_X* x)
{
    int s = ((Unk8024B99C_V*)x)->mB0C;
    int r = 0;
    if (s <= 6) {
        if (s >= 1)
            r = 1;
    }
    return r;
}

static inline void SetB3C(Unk80270BA0_X* x, int a)
{
    ((Unk8024B99C_V*)x)->mB3C.m3 = a;
}

void fn_80249D64(Unk80270BA0_X* x, int a)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (a != 0) {
        int s = v->mB0C;
        if (s != 0) {
            if (s == 2)
                v->mB0C = 1;
        } else {
            v->mB0C = 1;
            v->mB10 = lbl_805D9484;
        }
    } else {
        switch (v->mB0C) {
        case 1:
        case 4:
        case 5:
            v->mB0C = 2;
            break;
        case 3:
            v->mB10 = v->mB14;
            v->mB0C = 2;
            break;
        case 6:
            v->mB0C = a;
            break;
        }
    }
}

void fn_80249DF8(Unk80270BA0_X* x, int a)
{
    SetB3C(x, a);
    fn_80249D64(x, a);
}

void fn_8024A468(Unk8024A468_X* x)
{
    if (lbl_8061D2B4 == 0) {
        Unk8024A468_Ctx* c = x->m44C;
        int t = (x->m71C >> 12) & 1;
        if (c->m744->m20 != 0 || c->m54C->m44 != 0)
            t = 0;
        if (x->mB38 != lbl_805D94C0 && t == 0) {
            if (c->m6CC != 0 && (x->mB3C & 0x40000000) != 0) {
                fn_8038AC30(x->mAB8, x->mB38, fn_8026CB70(c->m6CC, 1), 0, x->mB2C);
            } else {
                fn_8038AC30(x->mAB8, x->mB38, *(Unk8026C414_V3*)x->mB20, 0, x->mB2C);
            }
        }
    }
}

void fn_8024A550(Unk80270BA0_X* x, float f)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (f != v->mB14) {
        v->mB10 *= f / v->mB14;
        v->mB14 = f;
    }
}

void fn_8024A584(Unk80270BA0_X* x, float f)
{
    ((Unk8024B99C_V*)x)->mB18 = f;
}

void fn_8024A59C(Unk80270BA0_X* x, int s)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (v->m264 != s) {
        if (s != 0) {
            fn_80244A64(x, 0, 0);
            for (int i = 0; i < 3; i++) {
                Unk80271DBC_Link* l = v->m618[i];
                fn_8037EBE8(l);
                fn_803814A4(l, 0, 0, lbl_805D94C4);
            }
        }
        v->m264 = s;
        if (s == 0 && v->m934 == 0) {
            Unk8027C728_Goal* g = fn_802448F4(x, 1);
            g->m10 = 2;
            fn_8027C728(g);
            fn_80244A64(x, g, 0);
        }
    }
}

void fn_8024A674(Unk80270BA0_X* x, Unk80273498_Pos* p) {}
