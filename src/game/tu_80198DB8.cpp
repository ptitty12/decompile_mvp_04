/*
 * Game code, .text 0x80198DB8-0x8019C1F8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80198DB8.h"
#include "game/tu_80144CF0.h"
#include "game/tu_8026C414.h"
int fn_8026CA8C(Unk8026C414_M* self, char** pp);

struct Unk8019B04C_Q {
    char pad0[0x708];
    int m708;
    unsigned char m70C;
};
inline void Unk8019B04C_Put(int*& p, int v)
{
    *p++ = v;
}

extern "C" {
float fn_8037A9AC(const Unk80183918_Vec3* a, const Unk80183918_Vec3* b);
void fn_80379DA0(Unk80198CC0_Vec4* out, Unk80183918_Vec3* axis, float angle);
Unk80198CC0_Vec4* fn_8019A4F4(Unk80198CC0_Vec4* out, const Unk80183918_Vec3* a, const Unk80183918_Vec3* b);
}

struct Unk8019B390_P {
    char pad0[0x60];
    Unk80183918_Vec3 m60;
    char pad6C[0xB68 - 0x6C];
    int mB68;
};
struct Unk8019B390_E {
    Unk8019B390_P* m0;
    char pad4[4];
    float m8;
    int mC;
};
struct Unk8019B390_C {
    char pad0[0x374];
    int m374;
    char pad378[0x38C - 0x378];
    int m38C;
};
struct Unk8019B390_T {
    char pad0[0x6CC];
    Unk8019B390_C* m6CC;
};
struct Unk8019B390_O {
    char pad0[0x24];
    Unk8019B390_T* m24;
    Unk8019B390_E m28[60];
    int m3E8;
};
int fn_8026D940(Unk8026C414_O* o, Unk8026C414_X* x);

struct Unk8019BC10_P {
    float x;
    float z;
};

struct Unk8019F8C0_Owner;
struct Unk8019B490_V {
    char pad0[0x24];
    Unk801808A4_Ctx* m24;
    char pad28[0x3E8 - 0x28];
    int m3E8;
};
int fn_801A48F8(Unk8019F8C0_Owner* o, int side);
int fn_801A4C74(Unk8019F8C0_Owner* o, int i);
extern "C" {
void* fn_801A4910(Unk8019F8C0_Owner* o, int side, int i);
}

extern "C" {
int fn_8019CCE4(int a);
int fn_802C0218(int a, int b, int c, float* t, void* p1, void* p2, float k);
}

struct Unk80199928_O {
    char pad0[0x384];
    int m384;
    char pad388[0x3E4 - 0x388];
    Unk80183918_Vec3 m3E4;
    Unk80183918_Vec3 m3F0;
};
extern "C" {
int fn_80199418(Unk80199928_O* o, int a);
void fn_80199AF8(Unk80199928_O* o, int a, int b, int c, int d, int e, int f, float x, float y);
}

extern Unk80183918_Vec3 lbl_806055B8;
extern Unk80183918_Vec3 lbl_806055F8;

struct Unk80379324 {
    Unk80379324();
    float m0, m4, m8, mC;
};
struct Unk8019A998_Ring {
    int m0;
    char* m4;
    char pad8[4];
    int mC;
};
struct Unk8019A998_Base {
    int m0;
    char pad4[0x6C - 4];
    int m6C;
    char pad70[0x7C - 0x70];
    Unk80379324 m7C;
    char pad8C[0x98 - 0x8C];
};
class Unk8019A998_Virt : public Unk8019A998_Base {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3(void* p);
};
struct Unk8019A998_Obj : public Unk8019A998_Virt {
    char pad9C[0x384 - 0x9C];
    int m384;
    int m388;
    char pad38C[0x3E4 - 0x38C];
    Unk80183918_Vec3 m3E4;
    Unk80183918_Vec3 m3F0;
    Unk8019A998_Ring m3FC;
};
extern "C" void fn_80198694(Unk8019A998_Ring* r, char* a, char* b, char* c, void* p1, void* p2);

struct Unk80198F68_X {
    char pad0[0xAB8];
    void* mAB8;
};
struct Unk80198F68_C {
    char pad0[0x4C];
    unsigned m4C;
};
struct Unk80198F68_Obj : public Unk8019A998_Virt {
    char pad9C[0xBC - 0x9C];
    Unk80198F68_C* mBC;
    char padC0[0x378 - 0xC0];
    Unk80198F68_X* m378;
    char pad37C[0x3FC - 0x37C];
    Unk8019A998_Ring m3FC;
};
inline float Unk80198F68_Secs(unsigned n)
{
    return (float)n * 0.016666668f;
}
extern "C" int fn_8035A97C(Unk8019A998_Ring* r, int v);
inline void Unk80198F68_Cp(Unk80379324* d, const Unk80379324& s)
{
    *d = s;
}
inline void Unk80198F68_Push(Unk8019A998_Ring* r, Unk8018A254_Ret* m, float t)
{
    int need = 0;
    if (r->mC == -1 || !(*(float*)((char*)((r->mC << 7) + (int)r->m4)) >= t))
        need = 1;
    if (need) {
        r->mC = fn_8035A97C(r, r->mC);
        *(Unk8018A254_Ret*)((char*)((r->mC << 7) + (int)r->m4) + 0x20) = *m;
        *(float*)((char*)((r->mC << 7) + (int)r->m4)) = t;
        *(int*)((char*)((r->mC << 7) + (int)r->m4) + 0x60) = 1;
    }
}
extern "C" void fn_8019A404(void* o, void* x, float* out);
//@BODY
//@80198DB8
extern "C" void* fn_80198DB8(void* o)
{
    return fn_80198CC0(o);
}

//@80198DD8
extern "C" void fn_80198DD8(Unk80198E5C_Obj* o, int v)
{
    if (v)
        o->v8(0);
    *(int*)((char*)o + 0x378) = v;
    if (v)
        o->m384 = 1;
    else if (o->m384 == 1)
        o->m384 = v;
}

//@80198E5C
extern "C" void fn_80198E5C(Unk80198E5C_Obj* o, int v)
{
    if (v == 0)
        o->m384 = 0;
    o->m264 = v;
}

//@80198E70
extern "C" void fn_80198E70(Unk80198E5C_Obj* o, int v)
{
    o->m37C = v;
}

//@80198E78
extern "C" char* fn_80198E78(Unk80198E5C_Obj* o)
{
    int m = o->m37C;
    if (m == 1)
        return lbl_805D053C;
    if (m == 3)
        return lbl_805D056C;
    return lbl_805D059C;
}

//@80198EB0
extern "C" char* fn_80198EB0(Unk80198E5C_Obj* o)
{
    int m = o->m37C;
    if (m == 1)
        return lbl_805D051C;
    if (m == 3)
        return lbl_805D054C;
    return lbl_805D057C;
}

//@80198EE8
extern "C" char* fn_80198EE8(Unk80198E5C_Obj* o)
{
    int m = o->m37C;
    if (m == 1)
        return lbl_805D052C;
    if (m == 3)
        return lbl_805D055C;
    return lbl_805D058C;
}

//@80198F20
extern "C" float fn_80198F20(Unk80198E5C_Obj* o)
{
    if (o->m37C == 3)
        return 1.25f;
    return 1.0f;
}

//@80198F44
extern "C" float fn_80198F44(Unk80198E5C_Obj* o)
{
    if (o->m37C == 2)
        return 1.25f;
    return 1.35f;
}

//@80198F68
/* near-miss (99.8%): identical instructions; the q.m4 / q.m8 words of the Unk80379324 copy into o->m7C land in
 * swapped registers (retail r6/r5, here r5/r6). Tried: Cp by reference/pointer, explicit field order, qp alias. */
extern "C" void fn_80198F68(void* op)
{
    Unk80198F68_Obj* o = (Unk80198F68_Obj*)op;
    if (o->m378 != 0) {
        Unk8018A254_Ret m;
        fn_80389BD8(o->m378->mAB8, lbl_806EF9C4, &m, 3);
        Unk8019A998_Ring* r = &o->m3FC;
        Unk80183918_Vec3 v;
        Unk80379324 q;
        fn_8019A404(&m, &q, (float*)&v);
        o->v3(&v);
        o->m0 = 0;
        o->m6C = 1;
        Unk80198F68_Cp(&o->m7C, q);
        float f = Unk80198F68_Secs(o->mBC->m4C);
        Unk80198F68_Push(r, &m, f);
    }
}

//@80199158
extern "C" void fn_80199158(Unk80198E5C_Obj* o)
{
    switch (o->m384) {
    case 0:
        break;
    case 1:
        fn_80198F68(o);
        break;
    case 2:
        fn_80199554(o);
        break;
    case 3:
        fn_80199414();
        break;
    }
}

//@80199414
extern "C" void fn_80199414()
{
}

inline void Unk80199928_ScaleRf(Unk80183918_Vec3& v, float s)
{
    v.m0 *= s;
    v.m4 *= s;
    v.m8 *= s;
}

inline void Unk80199928_Damp(Unk80183918_Vec3& v)
{
    Unk80199928_ScaleRf(v, 0.1f);
}

//@80199928
/* near-miss (98.3%): identical instructions; one scheduling swap remains (retail loads the 0.1f constant
 * before `addi r5,r31,0x3F0`, here the addi comes first; tried the Scale/Damp inline shapes). */
extern "C" void fn_80199928(Unk80199928_O* o, int a1, int a2, int a3, int a4, int a5, int a6)
{
    fn_80198F20((Unk80198E5C_Obj*)o);
    int c5 = fn_80199418(o, a5);
    fn_80198F44((Unk80198E5C_Obj*)o);
    int c6 = fn_80199418(o, a6);
    if (c5 != 0) {
        if (c6 != 0) {
            o->m3E4.m4 = o->m3E4.m4 * (!(o->m3E4.m4 >= 0.0f) ? -0.25f : 0.25f);
            Unk80199928_Damp(o->m3F0);
            if (!(o->m3E4.m4 >= 10.0f)) {
                o->m3E4 = lbl_806055AC;
                o->m3F0 = lbl_806055AC;
                o->m384 = 0;
            }
            return;
        }
        fn_80199AF8(o, a2, a3, a1, a5, a6, a4, fn_80198F20((Unk80198E5C_Obj*)o), fn_80198F44((Unk80198E5C_Obj*)o));
    }
    if (c6 != 0)
        fn_80199AF8(o, a3, a2, a1, a6, a5, a4, fn_80198F44((Unk80198E5C_Obj*)o), fn_80198F20((Unk80198E5C_Obj*)o));
}

//@8019A314
extern "C" void fn_8019A314(Unk8019A314_O* o, float* a, void* out1, void* out2)
{
    float len = Unk8019A314_Len(o->m3F0);
    if (!(len < 0.0001f)) {
        Unk8018A254_Ret m;
        fn_803DF74C(&m);
        fn_803DFD90(&m, -a[0], -a[1], -a[2]);
        fn_803DFD40(&m, len * 0.9549296f, o->m3F0.m0, o->m3F0.m4, o->m3F0.m8);
        fn_803DFD90(&m, a[0], a[1], a[2]);
        fn_804023C4(out1, &m, out1);
        fn_804023C4(out2, &m, out2);
    }
}

//@8019A404
extern "C" void fn_8019A404(void* o, void* x, float* out)
{
    fn_8019A44C(o, x);
    out[0] = *(float*)((char*)o + 0x30);
    out[1] = *(float*)((char*)o + 0x34);
    out[2] = *(float*)((char*)o + 0x38);
}

inline Unk80183918_Vec3 Unk8019A4F4_Cross(const Unk80183918_Vec3& a, const Unk80183918_Vec3& b)
{
    Unk80183918_Vec3 r;
    r.m0 = a.m4 * b.m8 - b.m4 * a.m8;
    r.m8 = a.m0 * b.m4 - b.m0 * a.m4;
    r.m4 = b.m0 * a.m8 - a.m0 * b.m8;
    return r;
}

inline void Unk8019A44C_Cp(Unk80183918_Vec3* d, const Unk80183918_Vec3* s)
{
    *d = *s;
}

//@8019A44C
extern "C" void fn_8019A44C(void* o, void* x)
{
    Unk80198CC0_Vec4 t;
    Unk80183918_Vec3 b;
    fn_804023C4(&lbl_806055F8, (Unk8018A254_Ret*)o, &t);
    Unk80198CC0_Vec4* tp = &t;
    Unk80198CC0_Vec4 q;
    q.m[0] = tp->m[0];
    q.m[1] = tp->m[1];
    q.m[2] = tp->m[2];
    Unk8019A44C_Cp(&b, (Unk80183918_Vec3*)&q);
    fn_8019A4F4(&q, &lbl_806055B8, &b);
    *(Unk80198CC0_Vec4*)x = q;
}

//@8019A4F4
extern "C" Unk80198CC0_Vec4* fn_8019A4F4(Unk80198CC0_Vec4* out, const Unk80183918_Vec3* a, const Unk80183918_Vec3* b)
{
    float ang = fn_8037A9AC(a, b);
    if (!(ang >= 1e-6) && !(ang <= -1e-6)) {
        fn_8037936C(out, (const char*)&lbl_8069428C);
    } else {
        Unk80183918_Vec3 axis = Unk8019A4F4_Cross(*a, *b);
        fn_80379DA0(out, &axis, ang);
    }
    return out;
}

inline void Unk8019A998_Cp(Unk80183918_Vec3* d, const Unk80183918_Vec3* s)
{
    *d = *s;
}

//@8019A998
extern "C" void fn_8019A998(Unk8019A998_Obj* o)
{
    Unk8019A998_Ring* r = &o->m3FC;
    fn_80198F68(o);
    o->m388 = 0;
    o->m384 = 2;
    fn_80198DD8((Unk80198E5C_Obj*)o, 0);
    Unk80379324 q;
    Unk80379324* qp = &q;
    Unk80183918_Vec3 v;
    if (r->mC == -1) {
        Unk8019A998_Cp(&v, &lbl_806055AC);
        *qp = *(Unk80379324*)&lbl_8069428C;
    } else {
        fn_8019A404(r->m4 + (r->mC << 7) + 0x20, qp, (float*)&v);
    }
    o->m0 = 0;
    o->m6C = 1;
    o->m7C = q;
    o->v3(&v);
    fn_80198694(r, fn_80198E78((Unk80198E5C_Obj*)o), fn_80198EB0((Unk80198E5C_Obj*)o), fn_80198EE8((Unk80198E5C_Obj*)o), &o->m3E4, &o->m3F0);
}

//@8019AAF0
extern "C" void fn_8019AAF0(Unk8019AC78_Obj* o, void* a)
{
    int m = o->m370;
    if (m == 1) {
        fn_8030AC88(a);
    } else if (m == 2) {
        fn_8030AF34(a, 0);
        fn_8030AF9C(a, 1);
    } else if (m == 3) {
        fn_8030AF9C(a, 0);
        fn_8030AF34(a, 1);
    }
}

//@8019AC78
extern "C" void fn_8019AC78(Unk8019AC78_Obj* o)
{
    void* e = fn_80319330((char*)o + 0x244, 0x17);
    fn_803116D4(fn_803119C0(), e, 0, 0, 1, o->m3E0->m54C, o->m3E0->m550, 0, 0.0f);
}

//@8019ACE0
extern "C" void fn_8019ACE0(Unk8019AC78_Obj* o)
{
    if (lbl_8061B894 != 0 && o->m36C == 0 && o->m240 == 0 && o->mBC->m54C->m10->m14 == 0) {
        fn_8019AB74(o);
        fn_8019AC78(o);
        if (lbl_8061C9F8 == 0) {
            fn_803DE374(1, 0);
            fn_8026CA5C(o);
            fn_803DE374(0, 0);
        }
    }
}

//@8019AD84
extern "C" void fn_8019AD84(Unk8019AD84_Obj* o)
{
    if (lbl_8061B894 != 0) {
        Unk8019AD84_X* x = o->m36C;
        if (x != 0) {
            Unk8018A254_Ret m;
            fn_80389BD8(x->mAB8, lbl_806EF9C4, &m, 1);
            o->m3A0 = m;
            fn_8019AB74(o);
            fn_8019AC78((Unk8019AC78_Obj*)o);
            fn_8026CA5C(o);
        }
    }
}

//@8019AE68
extern "C" void fn_8019AE68(void* o, float f)
{
    fn_8026CC04(o, f);
}

//@8019B004
extern "C" void fn_8019B004(Unk80198E5C_Obj* o)
{
    fn_8026CB30(o);
    o->v9(1);
}

extern "C" int fn_8019B04C(Unk80198E5C_Obj* o, int** pp)
{
    if (o->m264 == 0) {
        fn_8026CA8C((Unk8026C414_M*)o, (char**)pp);
        Unk8019B04C_Q* q = *(Unk8019B04C_Q**)((char*)o + 0x378);
        int a = 0xFF;
        int b = 0;
        int* p = *pp;
        if (q) {
            a = q->m70C;
            b = q->m708;
        }
        Unk8019B04C_Put(p, o->m380);
        Unk8019B04C_Put(p, o->m37C);
        Unk8019B04C_Put(p, a);
        Unk8019B04C_Put(p, b);
        *pp = p;
        return 1;
    }
    return 0;
}

//@8019B0E4
extern "C" void fn_8019B0E4(Unk8019B0E4_Obj* self, int chrg)
{
    self->mB8 = lbl_8065F760;
    self->m368 = lbl_8065F738;
    self->m3FC = lbl_8065F720;
    self->m98 = lbl_8065F7F0;
    fn_8019755C((Unk8019755C_Data*)((char*)self + 0x36C), 0);
    void* sub = &self->m360;
    *(const void**)((char*)sub + 8) = lbl_80649DB8;
    fn_80378620(sub, 0);
    fn_8026C864(self, chrg);
}

//@8019B174
extern "C" void fn_8019B174(Unk80198E5C_Obj* o, int v)
{
    o->m404 = v;
}

//@8019B17C
extern "C" void fn_8019B17C(Unk80198E5C_Obj* o, int v)
{
    o->m264 = v;
}

//@8019B184
extern "C" void fn_8019B184(Unk80198E5C_Obj* o)
{
    fn_80197604((char*)o + 0x36C);
}

//@8019B1A8
extern "C" void fn_8019B1A8(Unk80198E5C_Obj* o)
{
    fn_8019B174(o, 0);
}

//@8019B1CC
extern "C" void fn_8019B1CC()
{
}

//@8019B1D0
extern "C" void fn_8019B1D0(void* o, float f)
{
    fn_8026CC04(o, f);
}

//@8019B1F8
extern "C" void fn_8019B1F8()
{
}

//@8019B1FC
extern "C" void fn_8019B1FC(Unk80198E5C_Obj* o)
{
    fn_8026CB30(o);
    o->v9(1);
}

//@8019B244
extern "C" int fn_8019B244()
{
    return 0;
}

//@8019B24C
extern "C" Unk8019B24C_Obj* fn_8019B24C(Unk8019B24C_Obj* self, void* owner)
{
    fn_80328234(self, 4, owner);
    self->m24 = owner;
    self->m18 = lbl_8065F688;
    fn_8019B2A0((Unk80198E5C_Obj*)self);
    return self;
}

//@8019B2A0
extern "C" void fn_8019B2A0(Unk80198E5C_Obj* o)
{
    o->m3E8 = 0;
}

//@8019B2AC
extern "C" void fn_8019B2AC(VT18* o)
{
    o->s17();
}

//@8019B2E0
extern "C" void fn_8019B2E0(char* o, Unk8019B2E0_P* p, int flag)
{
    if (p == 0)
        return;
    int busy = p->m264;
    int st = p->m458;
    if (busy != 0)
        return;
    if (st == 13)
        return;
    int idx = *(int*)(o + 0x3E8);
    Unk8019B2E0_Rec* r = (Unk8019B2E0_Rec*)(o + 0x28 + idx * 16);
    int kind = 2;
    if (flag) {
        kind = 0;
        if (!(p->m590 & 0x40000000)) {
            kind = 3;
            if ((unsigned)(st - 9) <= 3)
                kind = st - 6;
        }
    } else if (p->m450 != 0) {
        kind = 1;
    }
    r->m4 = kind;
    r->m0 = p;
    r->m8 = 0.0f;
    r->mC = p->mB68 != 0;
    *(int*)(o + 0x3E8) = *(int*)(o + 0x3E8) + 1;
}

//@8019B390
extern "C" void fn_8019B390(Unk8019B390_O* o)
{
    Unk8019B390_C* c = o->m24->m6CC;
    int a = c->m374;
    int is3 = c->m38C == 3;
    for (int i = 0; i < o->m3E8; i++) {
        Unk8019B390_P* p = o->m28[i].m0;
        Unk80183918_Vec3 d = p->m60;
        o->m28[i].m8 = fn_804028E4(d.m0 * d.m0 + d.m8 * d.m8);
        int f = 1;
        if (o->m28[i].m0->mB68 == 0)
            f = 0;
        o->m28[i].mC = f;
        if ((is3 && a == (int)o->m28[i].m0) || fn_8026D940((Unk8026C414_O*)o->m28[i].m0, 0) != 0)
            o->m28[i].mC = 1;
    }
}

//@8019B490
extern "C" void fn_8019B490(void* oo)
{
    Unk8019B490_V* o = (Unk8019B490_V*)oo;
    int i;
    o->m3E8 = 0;
    int side = 0;
    if (o->m24->m6F8->m14->m1CD0 != 0)
        side = 1;
    int n = fn_801A48F8((Unk8019F8C0_Owner*)o->m24, side);
    for (i = 0; i < n; i++)
        fn_8019B2E0((char*)o, (Unk8019B2E0_P*)fn_801A4910((Unk8019F8C0_Owner*)o->m24, side, i), 1);
    int other = o->m24->m6F8->m14->m1CD0 == 0;
    n = fn_801A48F8((Unk8019F8C0_Owner*)o->m24, other);
    for (i = 0; i < n; i++)
        fn_8019B2E0((char*)o, (Unk8019B2E0_P*)fn_801A4910((Unk8019F8C0_Owner*)o->m24, other, i), 0);
    i = 0;
    do {
        fn_8019B2E0((char*)o, (Unk8019B2E0_P*)fn_801A4C74((Unk8019F8C0_Owner*)o->m24, i), 0);
        i++;
    } while (i <= 3);
}

//@8019B5AC
extern "C" int fn_8019B5AC(float* a, float* b)
{
    if (a[2] < b[2])
        return -1;
    return a[2] != b[2];
}

//@8019B99C
extern "C" void fn_8019B99C(Unk8019B99C_Obj* o)
{
    if (o->m24->m6F4 != 1)
        fn_8019B490(o);
}

//@8019B9CC
Unk8019B9CC::Unk8019B9CC(int a)
{
    m4 = a;
    m0 = lbl_8061E978->m3650;
}

//@8019B9F4
Unk8019B9CC::~Unk8019B9CC()
{
    m0 = 0;
}

//@8019BA30
extern "C" void fn_8019BA30(void** o, float t)
{
    fn_802C0888(*o, t);
}

//@8019BA5C
/* near-miss (98.9%): same instructions; callee-saved registers differ (retail: a r30, b r29, hit r26,
 * p1 r28, p2 r27, r1 r25; here p1 r30, p2 r29, hit r28, a r27, b r26). The cr4 save/restore matches. */
extern "C" int fn_8019BA5C(int* ctx, int a, int b, float t, int c, int flag, float* hit, Unk80183918_Vec3* p1, Unk80183918_Vec3* p2, int* sx, int* sy, int sz)
{
    if (flag == 0 && fn_8019CCE4(*ctx) != 0)
        return -1;
    *sy = 1;
    int r1 = ((int (*)(int, int, int, float*, void*, void*, int*, int, float))fn_802C0888)(*ctx, a, b, hit, p1, p2, sx, sz, t);
    int r2 = -1;
    Unk80183918_Vec3 v10;
    Unk80183918_Vec3 v20;
    float f30;
    if (flag != 0 || c != 0 || *sx != 0)
        r2 = fn_802C0218(*ctx, a, b, &f30, &v10, &v20, t);
    if (r2 != -1 && (r1 == -1 || !(f30 >= *hit))) {
        *hit = f30;
        *p1 = v10;
        *p2 = v20;
    }
    int r = r1;
    if (r == -1)
        r = r2;
    return r;
}

//@8019BBC0
extern "C" int fn_8019BBC0(void** o, void* a, void* b, float* t, void* p1, void* p2, float k)
{
    return fn_802C0050(*o, a, b, t, p1, p2, k);
}

//@8019BBEC
extern "C" void fn_8019BBEC(void** o)
{
    fn_802C0EC4(*o);
}

//@8019BC10
extern "C" int fn_8019BC10(const Unk8019BC10_P* a, const Unk8019BC10_P* b, void* obj)
{
    float pts[4][3];
    char b38[16];
    char b48[16];
    float f58, f5C, f60;
    for (int i = 0; i < 4; i++) {
        pts[i][0] = i <= 1 ? a->x : b->x;
        pts[i][1] = 0.0f;
        pts[i][2] = (unsigned)(i - 1) <= 1 ? b->z : a->z;
    }
    int i = 0;
    for (;;) {
        int next = i + 1;
        int j = next % 4;
        if (((int (*)(void*, void*, void*, void*, void*, void*, void*, void*, float))fn_802C0888)(obj, pts[i], pts[j], &f58, b38, b48, &f60, &f5C, 0.0f) == -1) {
            i = next;
            if (i > 3)
                return 1;
        } else
            return 0;
    }
}
