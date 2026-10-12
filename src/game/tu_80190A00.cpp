/*
 * Game code, .text 0x80190A00-0x80194D44 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80190A00.h"
#include "game/tu_8026C414.h"
int fn_8026CA8C(Unk8026C414_M* self, char** pp);

struct Unk80193A4C_Q {
    int a;
    int b;
    int c;
    int d;
};
struct Unk80193A4C_S {
    char pad0[0x10];
    Unk80193A4C_Q m10;
};

inline void Unk80193A4C_Make(Unk80193750_Ent* e, int id, float t, Unk80193A4C_S* s)
{
    e->m0 = id;
    e->m4 = t;
    *(Unk80193A4C_Q*)e->pad8 = s->m10;
}

struct Unk80191458_E {
    float m0;
    Unk80183918_Vec3 m4;
    Unk80183918_Vec3 m10;
    int m1C;
    int m20;
};
struct Unk80191458_O {
    char pad0[0x4F0];
    Unk80191458_E m4F0[50];
    int mBF8;
};

extern "C" float fn_804028E4(float x);

extern int lbl_8061C954;

struct Unk80190CC0_Q {
    float m[4];
};
struct Unk80190CC0_Rec {
    int m0;
    char pad4[0x6C - 4];
    int m6C;
    char pad70[0x7C - 0x70];
    Unk80190CC0_Q m7C;
};
struct Unk80190CC0_G {
    char pad0[0x20];
    int m20;
    char m24[0xC];
    float m30;
};
struct Unk80190CC0_Y {
    char pad0[0x18];
    int m18;
};
struct Unk80190CC0_C {
    char pad0[0x744];
    Unk80190CC0_Y* m744;
};
class Unk80190CC0_Virt : public Unk80190EB4_Base {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Unk80190CC0_Rec* v6();
};
struct Unk80190CC0_Obj : public Unk80190CC0_Virt {
    char pad9C[0x1A0 - 0x9C];
    int m1A0;
    char pad1A4[0x200 - 0x1A4];
    Unk80183918_Vec3 m200;
    char pad20C[0x240 - 0x20C];
    int m240;
    char pad244[0x370 - 0x244];
    int m370;
    char pad374[0x44C - 0x374];
    Unk80190CC0_C* m44C;
    char pad450[0x4D8 - 0x450];
    int m4D8;
    char pad4DC[0x4EC - 0x4DC];
    int m4EC;
};
void fn_8026CCF8(Unk8026C414_M* self, int i, int* a, int* b);
extern "C" {
void fn_80379DA0(Unk80190CC0_Q* out, void* axis, float angle);
int fn_80187D5C(void* o, Unk80183918_Vec3* out);
}

//@80190CC0
/* near-miss (95.7%): same instructions; the pointer-walking loads (lwzu) now match, but a0/b0 and a1/b1 land in
 * swapped registers and the three zero stores in the a0 == b0 == 0 arm come out in another order. */
extern "C" void fn_80190CC0(Unk80190CC0_Obj* o, int p)
{
    int* a = 0;
    int* b = 0;
    fn_8026CCF8((Unk8026C414_M*)o, p, (int*)&a, (int*)&b);
    int z = o->m240;
    if (z != 0) {
        o->m370 = 0;
        return;
    }
    Unk80190CC0_G* g = (Unk80190CC0_G*)lbl_8068BF0C;
    if (g->m20 != 0) {
        Unk80190CC0_Q q;
        fn_80379DA0(&q, g->m24, g->m30);
        Unk80190CC0_Rec* r = o->v6();
        r->m0 = z;
        r->m6C = 1;
        r->m7C = q;
    }
    int* pa = a;
    int* pb = b;
    int a0 = *pa, b0 = *pb;
    pa++;
    pb++;
    int a1 = *pa, b1 = *pb;
    int a2 = pa[1], b2 = pb[1];
    if (a0 == 0) {
        if (b0 == 0) {
            o->m4EC = b0;
            o->m370 = b0;
            o->m4D8 = b0;
        } else {
            o->m370 = b0;
            o->m4D8 = b1;
            o->m4EC = b2 != 0;
        }
    } else {
        o->m370 = a0;
        o->m4D8 = a1;
        o->m4EC = a2 != 0;
    }
    if (o->m44C->m744->m18 != 0) {
        Unk80183918_Vec3 v;
        if (fn_80187D5C(o, &v) != 0) {
            o->m200 = v;
            o->m1A0 = 0;
        }
    }
}

//@BODY
//@80190E40
inline void Put2(int*& p, int v) { *p++ = v; }

extern "C" int fn_80190E40(Unk80190EB4_Obj* o, int** pp)
{
    if (o->m264 != 0)
        return 0;
    fn_8026CA8C((Unk8026C414_M*)o, (char**)pp);
    int* p = *pp;
    int v = fn_80188EF4(o);
    Put2(p, o->m36C);
    Put2(p, o->m4D4);
    Put2(p, v);
    *pp = p;
    return 1;
}

//@80190EB4
extern "C" void fn_80190EB4(Unk80190EB4_Obj* o)
{
    fn_8026CB30(o);
    o->v9(1);
    o->m370 = 0;
}

//@80190F04
extern "C" void fn_80190F04(Unk80190EB4_Obj* o, int v)
{
    o->m394 = v;
}

//@80190F0C
extern "C" float fn_80190F0C(Unk80190EB4_Obj* o)
{
    return o->m41C;
}

//@80190F14
extern "C" int fn_80190F14(Unk80190EB4_Obj* o)
{
    return fn_80196C50(o->m448);
}

inline Unk80183918_Vec3 Unk80190F38_Sub(const Unk80183918_Vec3& a, const Unk80183918_Vec3& b)
{
    Unk80183918_Vec3 r;
    r.m0 = a.m0 - b.m0;
    r.m4 = a.m4 - b.m4;
    r.m8 = a.m8 - b.m8;
    return r;
}

inline float Unk80190F38_LenR(const Unk80183918_Vec3& v)
{
    return fn_804028E4(v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8);
}

//@80190F38
extern "C" void fn_80190F38(Unk80188698* o, float t, const Unk80183918_Vec3* ref, Unk80183918_Vec3* outPos, float* outDist)
{
    if (outPos) {
        *outPos = fn_8018959C(o, t);
        if (outDist) {
            Unk80183918_Vec3 d = Unk80190F38_Sub(*outPos, *ref);
            *outDist = Unk80190F38_LenR(d);
        }
    } else if (outDist) {
        Unk80183918_Vec3 d = Unk80190F38_Sub(fn_8018959C(o, t), *ref);
        *outDist = Unk80190F38_LenR(d);
    }
}

//@8019144C
extern "C" void fn_8019144C(Unk80190EB4_Obj* o)
{
    o->mBF8 = 0;
}

//@80191458
extern "C" void fn_80191458(Unk80191458_O* o, const Unk80183918_Vec3* p1, float t, const Unk80183918_Vec3* p2, int a, int b)
{
    int idx = o->mBF8;
    for (int i = 0; i < o->mBF8; i++) {
        float et = o->m4F0[i].m0;
        if (!(t >= et)) {
            idx = i;
            break;
        }
    }
    if (idx <= 49) {
        o->m4F0[idx].m0 = t;
        o->m4F0[idx].m4 = *p1;
        o->m4F0[idx].m10 = *p2;
        o->m4F0[idx].m1C = b;
        o->m4F0[idx].m20 = a;
        o->mBF8 = idx + 1;
    }
}

//@8019155C
extern "C" int fn_8019155C(Unk80191458_O* o, int* a1, int* a2, int* a3, float* a4, float* a5, float t)
{
    if (lbl_8061C954 != 0) {
        int k = 0;
        *a1 = -1;
        *a2 = -1;
        if (k < o->mBF8) {
            do {
                float et = o->m4F0[k].m0;
                if (!(et >= t)) {
                    *a2 = k;
                    if (o->m4F0[k].m20 != 0)
                        *a1 = k;
                    if (et < t)
                        goto next;
                }
                if (*a1 >= 0 && k > 0 && o->m4F0[k].m20 != 0) {
                    *a3 = k;
                    *a4 = (t - o->m4F0[*a1].m0) / (et - o->m4F0[*a1].m0);
                    *a4 = !(*a4 > 1.0f) ? (*a4 >? 0.0f) : 1.0f;
                    if (*a2 == *a3 - 1) {
                        *a5 = (t - o->m4F0[*a2].m0) / (et - o->m4F0[*a2].m0);
                        *a5 = !(*a5 > 1.0f) ? (*a5 >? 0.0f) : 1.0f;
                    } else
                        *a5 = 0.0f;
                    return 1;
                }
            next:
                k++;
            } while (k < o->mBF8);
        }
    }
    *a1 = 0;
    *a2 = 0;
    *a3 = 0;
    *a4 = 0.0f;
    *a5 = 0.0f;
    return 0;
}

//@80191720
Unk80191720::Unk80191720()
    : Unk8037B3E8(0x0F245603U)
{
}

//@80191800
extern "C" void* fn_80191800(Unk80191720* self)
{
    return fn_8037CF5C(fn_8037C7FC(), 0x0F245603U, self);
}

//@8019183C
Unk8037B3E8* Unk80191720::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk80191720;
}

//@8019186C
Unk8019186C::Unk8019186C()
    : Unk8037B3E8(0xDA319B21U)
{
}

//@80191A68
extern "C" void* fn_80191A68(void* self)
{
    return (void*)fn_8037C7FC()->fn_8037CE98(0xDA319B21U, (int)self, 0);
}

//@80191AA8
Unk8037B3E8* Unk8019186C::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk8019186C;
}

//@80191AD8
extern "C" void fn_80191AD8(Unk80191AD8_S* s, int mode)
{
    s->m0 = mode;
    switch (mode) {
    case 3: {
        Unk80191AD8_Q* q = (Unk80191AD8_Q*)&s->m4;
        q->m0 = -1.0f;
        q->m4 = lbl_806055AC;
        q->m10 = -1.0f;
        s->m18 = lbl_806055AC;
        q->m20 = -1.0f;
        q->m24 = 0;
        break;
    }
    case 1:
        s->m4 = -1.0f;
        break;
    case 2:
        s->m4 = -1.0f;
        break;
    }
}

//@80191B70
extern "C" Unk80191B70_S* fn_80191B70(Unk80191B70_S* s)
{
    Unk80191B70_Sub* sub = &s->m4;
    fn_8037936C(sub, lbl_8069429C);
    *(Unk80183918_Vec3*)((char*)s + 0x14) = lbl_806055AC;
    sub->m1C = 0;
    s->m78 = 0;
    return s;
}

//@80191BE0
extern "C" Unk80191B70_S* fn_80191BE0(Unk80191B70_S* s, void* owner)
{
    Unk80191B70_Sub* sub = &s->m4;
    fn_8037936C(sub, lbl_8069429C);
    *(Unk80183918_Vec3*)((char*)s + 0x14) = lbl_806055AC;
    sub->m1C = 0;
    fn_80191C5C((Unk80191C5C_S*)s, owner);
    return s;
}

//@80191C5C
extern "C" void fn_80191C5C(Unk80191C5C_S* s, void* owner)
{
    s->m24 = 0;
    s->m20 = 3;
    s->m28 = lbl_806055AC;
    s->m34 = lbl_806055AC;
    s->m40 = lbl_806055AC;
    s->m4C = lbl_806055AC;
    s->m58 = 0.0f;
    s->m5C = 1.0f;
    s->m64 = 0;
    s->m68 = 0;
    s->m6C = 0;
    s->m60 = 0.0f;
    s->m74 = 0;
    s->m0 = owner;
    s->m78 = (char*)owner + 0xD4;
    s->m70 = 0;
}

//@80191D34
extern "C" float fn_80191D34(int idx, float t)
{
    int j;
    if (idx <= 3) {
        j = idx;
        if (j < 0)
            j = 0;
    } else
        j = 3;
    float k = 10.0f;
    float w[4] = { 400.0f, 800.0f, 1200.0f, 1600.0f };
    float x = t * 0.1f;
    x = !(x > 1.0f) ? (x >? 0.0f) : 1.0f;
    return x * w[j];
}

//@80193750
extern "C" void* fn_80193750(void* hv, float t)
{
    Unk80193750_H* h = (Unk80193750_H*)hv;
    char* a = (char*)h->m78;
    if (a == 0)
        return 0;
    int n = h->m74;
    int i = 0;
    if (i < n) {
        int off = 0;
        do {
            Unk80193750_Ent* e = (Unk80193750_Ent*)(off + (int)a);
            if (t <= e->m4)
                return e;
            i++;
            off += 0x18;
        } while (i < n);
    }
    return 0;
}

//@801937B4
extern "C" float fn_801937B4(void* hv, int k, float t)
{
    Unk80193750_H* h = (Unk80193750_H*)hv;
    char* a = (char*)h->m78;
    if (a == 0)
        return -1.0f;
    int n = h->m74;
    int i = 0;
    if (i < n) {
        int off = 0;
        do {
            Unk80193750_Ent* e = (Unk80193750_Ent*)(off + (int)a);
            if (!(t > e->m4) && k == e->m0)
                return e->m4;
            i++;
            off += 0x18;
        } while (i < n);
    }
    return -1.0f;
}

//@80193828
extern "C" void* fn_80193828(void* hv, float t)
{
    Unk80193750_H* h = (Unk80193750_H*)hv;
    char* a = (char*)h->m78;
    if (a == 0)
        return 0;
    int i = h->m74 - 1;
    if (i >= 0) {
        int off = i * 0x18;
        do {
            Unk80193750_Ent* e = (Unk80193750_Ent*)(off + (int)a);
            if (t > e->m4)
                return e;
            off -= 0x18;
            i--;
        } while (i >= 0);
    }
    return 0;
}

//@80193880
extern "C" float fn_80193880(Unk80193750_H* h, int k, float t)
{
    char* a = (char*)h->m78;
    if (a == 0)
        return -1.0f;
    int i = h->m74 - 1;
    if (i >= 0) {
        int off = i * 0x18;
        do {
            Unk80193750_Ent* e = (Unk80193750_Ent*)(off + (int)a);
            if (!(t <= e->m4) && k == e->m0)
                return e->m4;
            off -= 0x18;
            i--;
        } while (i >= 0);
    }
    return -1.0f;
}

//@801938F0
extern "C" void fn_801938F0(Unk80193750_H* h, Unk80193750_Ent* rec)
{
    if (h->m78 != 0) {
        int n = h->m74;
        float t = rec->m4;
        if (n <= 99) {
            int pos = -1;
            if (n == 0 || !(t < h->m78[n - 1].m4)) {
                pos = n;
            } else {
                for (int i = 0; i < n; i++) {
                    if (!(t >= h->m78[i].m4)) {
                        pos = i;
                        break;
                    }
                }
            }
            if (pos != -1) {
                for (int j = h->m74; j > pos; j--)
                    h->m78[j] = h->m78[j - 1];
                h->m78[pos] = *rec;
                h->m74 = h->m74 + 1;
            }
        }
    }
}

//@80193A4C
/* near-miss: 24 vs 25 insns: retail copies the source pointer first (`mr r9,r4`, then
 * `addi r11,r9,16` for the 16-byte record) and reads the outer words off r9 and the middle
 * words off r11; ours forms one pointer (addi r9,r4,16). Frame layout, the float slot at
 * 0x28 and the stores already match. ~12 spellings of the inline (param copies, local
 * pointers, byte-wise copies) tried. */
extern "C" void fn_80193A4C(Unk80193750_H* h, Unk80193A4C_S* s, int id, float t)
{
    Unk80193750_Ent e;
    Unk80193A4C_Make(&e, id, t, s);
    fn_801938F0(h, &e);
}

//@80191764
void Unk80191720::fn_vslot2()
{
    fn_8037B7E4(lbl_805CE008);
    fn_8037B50C(lbl_805CE00C, &m4, lbl_805CE014, lbl_805CE020);
    fn_8037B50C(lbl_805CE024, &mC, lbl_805CE030, lbl_805CE03C);
    fn_8037B50C(lbl_805CE040, &m8, lbl_805CE030, lbl_805CE04C);
}

//@801918B0
void Unk8019186C::fn_vslot2()
{
    fn_8037B7E4(lbl_805CE050);
    fn_8037B50C(lbl_805CE054, &m4, lbl_805CE030, 0);
    fn_8037B50C(lbl_805CE05C, &m8, lbl_805CE068, 0);
    fn_8037B494(lbl_805CE074, &m10, 0, 0);
    fn_8037B50C(lbl_805CE084, &mC, lbl_805CE090, 0);
    fn_8037B50C(lbl_805CE09C, &m14, lbl_805CE090, 0);
    fn_8037B50C(lbl_805CE0B4, &m18, lbl_805CE090, 0);
    fn_8037B50C(lbl_805CE0C8, &m1C, lbl_805CE0D8, 0);
    fn_8037B7E8(lbl_805CE0E4);
    fn_8037B458(lbl_805CE0F0, &m20, 0, 0);
    fn_8037B50C(lbl_805CE0FC, &m30, lbl_805CE100, 0);
    fn_8037B50C(lbl_805CB6EC, &m24, lbl_805CE108, 0);
    fn_8037B50C(lbl_805CE114, &m28, lbl_805CE108, 0);
    fn_8037B50C(lbl_805CE118, &m2C, lbl_805CE108, 0);
    fn_8037B830(lbl_805CE0E4);
}
