/*
 * Game code, .text 0x80194D44-0x80198DB8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80194D44.h"

/* Views and helpers for the functions below. Offsets come from the original code of each user. */
extern Unk80183918_Vec3 lbl_806055AC;
extern Unk80183918_Vec3 lbl_805D0064;
void fn_8035AD80();
void fn_8035AD84();
extern "C" {
void fn_80191C5C(Unk80191C5C_S* s, void* owner);
void fn_80191AD8(Unk80191AD8_S* s, int mode);
Unk80191B70_S* fn_80191BE0(Unk80191B70_S* s, void* owner);
}

/* fn_801980F0 / fn_80197A6C: Vec3 scaled by dt and added to a position. */
struct Unk801980F0_O {
    char pad0[0xC];
    Unk80183918_Vec3 mC;
};

inline void Unk801980F0_Add(Unk80183918_Vec3* a, const Unk80183918_Vec3& b)
{
    a->m0 += b.m0;
    a->m4 += b.m4;
    a->m8 += b.m8;
}

inline Unk80183918_Vec3 Unk801980F0_Scale(const Unk80183918_Vec3& a, float s)
{
    Unk80183918_Vec3 r;
    r.m0 = a.m0 * s;
    r.m4 = a.m4 * s;
    r.m8 = a.m8 * s;
    return r;
}

struct Unk80197A6C_O {
    Unk80183918_Vec3 m0;
    Unk80183918_Vec3 mC;
    char pad18[0x48 - 0x18];
    float m48;
    float m4C;
};
inline float Unk80197A6C_AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

/* fn_801964C8: playback cursor (count at +0x40, start/end times at +0x44/+0x48, base index
 * at +0x50, last index at +0x54). */
struct Unk801964C8_O {
    char pad0[0x40];
    int m40;
    float m44;
    float m48;
    char pad4C[4];
    int m50;
    int m54;
};

/* 0x20-byte path point: name Vec4 (fn_8037936C), position at +0x10, flag at +0x1C. */
struct Unk801973F4_P {
    char pad0[0x10];
    Unk80183918_Vec3 m10;
    int m1C;
    Unk801973F4_P()
    {
        ((int (*)(void*, const char*))fn_8037936C)(this, lbl_8069429C);
        m10 = lbl_806055AC;
        m1C = 0;
    }
};
extern "C" {
float fn_80196990(Unk80195404* o, Unk801973F4_P* a, Unk801973F4_P* b, float t);
}

/* fn_80195974: re-targets the 0x7C-byte record at +0xA34 (fn_80191C5C layout). */
struct Unk80195974_P {
    Unk80198CC0_Vec4 m0;
    Unk80183918_Vec3 m10;
    int m1C;
};
struct Unk80195974_O {
    char pad0[0xA34];
    char mA34[4];
    Unk80195974_P mA38;
    int mA58;
    Unk80183918_Vec3 mA5C;
    Unk80183918_Vec3 mA68;
    Unk80183918_Vec3 mA74;
    Unk80183918_Vec3 mA80;
    char padA8C[4];
    float mA90;
};

/* fn_80195A9C / ctor fn_80195404: mode record copy at +0xAB4 (0x3C bytes: Vec3, float, then
 * the Unk80191AD8_S mode record). The 0x7C-byte records at +0x58 and +0xA34 are
 * Unk80191C5C_S / Unk80191B70_S. */
struct Unk80195A9C_T {
    Unk80183918_Vec3 m0;
    float mC;
    Unk80191AD8_S m10;
    Unk80195A9C_T()
    {
        m0 = lbl_806055AC;
        mC = 0.0f;
    }
};
struct Unk80195A9C_O {
    char pad0[0x44];
    float m44;
    float m48;
    int m4C;
    int m50;
    int m54;
    Unk80191C5C_S m58;
    char padD4[0xA34 - 0xD4];
    Unk80191C5C_S mA34;
    char padAB0[0xAB4 - 0xAB0];
    Unk80195A9C_T mAB4;
};
inline void Unk80195A9C_Init(Unk80195A9C_T* t)
{
    t->m0 = lbl_806055AC;
    t->mC = 0.0f;
}

struct Unk80195404_E {
    int m0;
    float m4;
    char pad8[0x10];
};
struct Unk80195404_V {
    Unk80187190* m0;
    char pad4[0x28 - 4];
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    char pad40[0x58 - 0x40];
    Unk80191B70_S m58;
    Unk80195404_E mD4[100];
    Unk80191B70_S mA34;
    int* mAB0;
    Unk80195A9C_T mAB4;
    int mAF0;
};
extern "C" {
void fn_80195A9C(Unk80195A9C_O* o);
}

//@BODY
//@80194D44
extern "C" int fn_80194D44(Unk80194D44_O* o)
{
    int r = fn_80193AB0(o);
    fn_8019427C(o);
    o->m58 = o->m58 + 0.016666668f;
    return r;
}

//@80194D94
extern "C" int fn_80194D94(Unk80194D44_O* o)
{
    if (o->m70 != 0)
        return 0;
    if (o->m20 == 6 || o->m20 == 2)
        o->m70 = 1;
    return 1;
}

//@80195404
/* near-miss: 85/89 insns, 97%: the 100-entry init loop keeps `lis` before `li r30,0`
 * (retail has li first); also tried do/while, indexed, zero temp and swapped stores. */
Unk80195404::Unk80195404(Unk80187190* owner, int flag)
{
    Unk80195404_V* v = (Unk80195404_V*)this;
    v->m0 = owner;
    v->m28 = flag ? 2.0f : 0.5f;
    v->m2C = flag ? 12.25f : 2.5f;
    v->m30 = flag ? 13.0f : 3.5f;
    v->m34 = flag ? 2.0f : 0.5f;
    v->m38 = flag ? 6.0f : 2.75f;
    v->m3C = flag ? 4.0f : 2.75f;
    fn_80191BE0(&v->m58, this);
    Unk80195404_E* e = v->mD4;
    for (int i = 0; i < 100; i++, e++) {
        e->m4 = -1.0f;
        e->m0 = 0;
    }
    fn_80191BE0(&v->mA34, this);
    v->mAB0 = 0;
    Unk80195A9C_Init(&v->mAB4);
    v->mAB4.m10.m0 = 0;
    v->mAF0 = 1;
    fn_80195A9C((Unk80195A9C_O*)this);
}

//@80195568
Unk80195404::~Unk80195404()
{
    if (mAB0)
        delete[] mAB0;
    mAB0 = 0;
}

//@80195928
extern "C" void fn_80195928(Unk80194D44_O* o, int i)
{
    for (int k = 0; k < 3; k++)
        o->mAF8[k] = 0;
    int j = i;
    if (j <= 2) {
        if (j < 0)
            j = 0;
    } else
        j = 2;
    o->mAF8[j] = 1;
}

//@80195974
extern "C" void fn_80195974(Unk80195974_O* o, const Unk80183918_Vec3* p1, const Unk80183918_Vec3* p2, const Unk80183918_Vec3* p3, const Unk80183918_Vec3* p4, const Unk80198CC0_Vec4* hdr, int k, float t)
{
    char* s = o->mA34;
    fn_80191C5C((Unk80191C5C_S*)s, o);
    Unk80195974_P* q = &o->mA38;
    o->mA38.m10 = *p1;
    q->m1C = 3;
    q->m0 = *hdr;
    o->mA74 = *p3;
    ((void (*)(void*))fn_8035AD80)(s);
    o->mA80 = *p4;
    ((void (*)(void*))fn_8035AD84)(s);
    o->mA58 = k;
    o->mA5C = *p1;
    o->mA68 = *p2;
    o->mA90 = t;
}

//@80195E60
/* near-miss: 32 vs 30 insns: retail reloads the state word at +0x7C for each test (three
 * lwz) and tests the +0x6C field before the second +0x7C compare; here the loads are CSE'd. */
extern "C" int fn_80195E60(Unk80194D44_O* o, Unk80195E60_Q* q)
{
    if (o->m4C == 0)
        return 0;
    Unk80195E60_P* p = (Unk80195E60_P*)((char*)o + 0x58);
    if (p->m24 == 3 && o->m78 == 3)
        return 0;
    if (p->m68 != 0 || p->m6C != 0)
        return 1;
    if (p->m24 == 3 && q->m38 == 0)
        return 1;
    return (p->m24 ^ 2) == 0;
}

//@80195EE0
extern "C" float fn_80195EE0(Unk80194D44_O* o)
{
    if (fn_80195E60(o, (Unk80195E60_Q*)((char*)o + 0xAB4))) {
        Unk80195E60_P* p = (Unk80195E60_P*)((char*)o + 0x58);
        if (p->m68 != 0 || p->m24 == 2)
            return 0.1f;
        return 0.25f;
    }
    return o->m34;
}

//@80195F50
extern "C" void fn_80195F50(Unk80194D44_O* o, float t)
{
    float x = fn_80195EE0(o);
    if (fn_80195FD8(o, t) == 1) {
        float d = t + o->m30 - o->m48;
        if (!(d <= x))
            d = x;
        fn_8019601C(o, d);
    }
}

//@80195FD8
extern "C" int fn_80195FD8(Unk80194D44_O* o, float t)
{
    float d = o->m48 - t;
    if (!(d > o->m2C)) {
        if (o->mC8 == 0)
            return 1;
    }
    return 0;
}

//@801964C8
//@801964C8
//@801964C8
//@801964C8
extern "C" int fn_801964C8(Unk801964C8_O* o, float* out, float t)
{
    t -= o->m44;
    if (!(t >= 0.0f)) {
        if (out)
            *out = 0.0f;
        return o->m50;
    }
    if (!(t <= o->m48 - o->m44)) {
        if (out)
            *out = 0.0f;
        int r = o->m54 - 1;
        if (r < 0)
            r = o->m40 - 1;
        return r;
    }
    float fl = (float)fn_80410634(t * 60.0f);
    if (out)
        *out = t * 60.0f - fl;
    return ((int)fl + o->m50) % o->m40;
}

//@80196990
extern "C" float fn_80196990(Unk80195404* o, Unk801973F4_P* a, Unk801973F4_P* b, float t)
{
    float frac;
    Unk801964C8_O* v = (Unk801964C8_O*)o;
    int i = fn_801964C8(v, &frac, t);
    int j = (i + 1) % v->m40;
    if (j == v->m54)
        j = i;
    *a = ((Unk801973F4_P*)o->mAB0)[i];
    *b = ((Unk801973F4_P*)o->mAB0)[j];
    return frac;
}

//@801973F4
//@801973F4
//@801973F4
extern "C" int fn_801973F4(Unk80195404* o, float t)
{
    Unk801973F4_P a;
    Unk801973F4_P b;
    float r = fn_80196990(o, &a, &b, t);
    if (r >= 0.5f)
        return b.m1C;
    return a.m1C;
}

//@801974C4
/* near-miss: 38 vs 37 insns: same call and argument shuffle, but retail copies four of the
 * incoming argument registers into r27..r30 up front (an extra saved register and moves via
 * r3) where this keeps them in volatile registers. The float spills match. */
extern "C" int fn_801974C4(int a0, Unk80188698** pp, int a2, int a3, int a4, int a5, int a6, int a7,
    float f0, float f1, float f2, float f3, float f4)
{
    Unk80188698* o = *pp;
    fn_8019D03C(a0, *(void**)((char*)o->m44C + 0x6C8), o, a2, a3, a4, a5, a6, a7, f0, f1, f2, f3, f4);
    return a0;
}

//@8019755C
extern "C" void fn_8019755C(Unk8019755C_Data* self, int chrg)
{
    self->m90 = lbl_8065F848;
    if (self->m5C) {
        fn_80377488(self->m5C);
        self->m5C = 0;
    }
    if (self->m60) {
        fn_80377488(self->m60);
        self->m60 = 0;
    }
    if (self->m64) {
        fn_80377488(self->m64);
        self->m64 = 0;
    }
    if (self->m68) {
        fn_80377488(self->m68);
        self->m68 = 0;
    }
    if (chrg & 1)
        fn_80377408(self);
}

//@80197A6C
extern "C" void fn_80197A6C(void* self, Unk80197A6C_O* o, float dt)
{
    Unk801980F0_Add(&o->m0, Unk801980F0_Scale(o->mC, dt));
    o->m48 += o->m4C * dt;
    o->m48 = Unk80197A6C_AngleDiff(o->m48, 0.0f);
}

//@80197B88
extern "C" void fn_80197B88(Unk80197B88_O* o, Unk80197B88_P* p, void* out)
{
    Unk8018A254_Ret m;
    fn_803DF4E4(&m, p->m48 * 57.295776f, p->m3C, p->m40, p->m44);
    fn_803DFD90(&m, p->m0, p->m4, p->m8);
    fn_803DF028(&m, o->m6C, o->m5C, 12, out, 12);
}

//@80197D94
extern "C" int fn_80197D94(float* a, float* b)
{
    if (*a < *b)
        return -1;
    return *a > *b;
}

//@801980F0
extern "C" void fn_801980F0(void* self, Unk801980F0_O* o)
{
    Unk80183918_Vec3 d = Unk801980F0_Scale(lbl_805D0064, 0.016666668f);
    Unk801980F0_Add(&o->mC, d);
}

//@80198188
extern "C" int fn_80198188(Unk80198188_Ring* r)
{
    int cur = r->mC;
    if (cur == -1)
        return -1;
    int next = (cur + 1) % r->m0;
    if (*(int*)(r->m4 + next * 128 + 0x60) != 0)
        return next;
    return 0;
}

//@80198C18
extern "C" void fn_80198C18(Unk80198C18_Obj* self, int chrg)
{
    self->mB8 = lbl_806603D8;
    self->m368 = lbl_806603B0;
    char* s3 = self->m3FC;
    self->m98 = lbl_80660468;
    *(const void**)(s3 + 0x10) = lbl_806604C8;
    if (*(void**)(s3 + 4))
        fn_80377488(*(void**)(s3 + 4));
    if (*(void**)(s3 + 8))
        fn_80377488(*(void**)(s3 + 8));
    void* sub = &self->m360;
    *(const void**)((char*)sub + 8) = lbl_80649DB8;
    fn_80378620(sub, 0);
    fn_8026C864(self, chrg);
}

//@80198CC0
/* near-miss: 62/62 insns, ~20 slots differ: all instructions match; only register numbers
 * (retail: ring pointer r31, shared zero/offset r29, one r28; here r28/r31/r29) and the order of
 * the field stores differ. Declaring `off` before the stores gave retail's shared zero. */
extern "C" void fn_80198CC0(Unk80198CC0_Obj* o)
{
    int off = 0;
    fn_8026C8FC(o);
    Unk80198CC0_Ring* r = &o->m3FC;
    o->m0 = 0;
    o->m6C = 1;
    o->m7C = lbl_8069428C;
    fn_803DF74C(&o->m3A0);
    o->m37C = 1;
    o->m384 = 0;
    o->m388 = 0;
    o->m36C = 0;
    o->m370 = 1;
    o->m374 = 0;
    o->m378 = 0;
    o->m380 = 0;
    fn_80198DD8((Unk80198E5C_Obj*)o, 0);
    fn_8035A900(r);
    for (int i = 0; i < r->m0; i++, off += 128) {
        char* e = r->m4 + off;
        *(float*)e = 0.0f;
        fn_803DF74C((Unk8018A254_Ret*)(e + 0x20));
        *(int*)(e + 0x60) = 0;
    }
    r->mC = -1;
}
