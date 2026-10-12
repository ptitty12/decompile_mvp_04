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
