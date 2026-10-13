/*
 * Game code, .text 0x802CBD04-0x802CFED4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/chooser.h"
#include "game/tu_802CBD04.h"

extern int lbl_8061ECAC[];
Unk802CC580_T* fn_801A04A8(Unk802CC580_Data* d, int k);
int fn_803272D0(char* tbl, int idx);
extern const char lbl_805E2568[];
extern const char lbl_805E331C[];
extern const char lbl_805E32DC[];
extern const char lbl_805E32E8[];
extern const char lbl_805E32F8[];
extern const char lbl_805E3308[];
extern const char lbl_805E3310[];
extern const char lbl_805E3320[];
extern const char lbl_805E3330[];
extern const char lbl_805E3334[];
extern const char lbl_805E3340[];
extern const char lbl_805E26D8[];
extern const char lbl_805E3358[];
extern const char lbl_805E3364[];
extern const char lbl_805E3374[];
extern const char lbl_805E3384[];
extern const char lbl_805E3390[];
extern const char lbl_805E33A8[];
extern const char lbl_805E33C0[];
extern const char lbl_805E33D0[];
extern const char lbl_805E33E4[];
extern const char lbl_805E33FC[];
extern Unk802CF70C_Flags* lbl_8061B8C0;
float fn_802CF5CC(int a, int b, float x, float y, float z);
void fn_802CC0E8(Unk802CC48C* o, Unk802CC48C_Mat* out);

void fn_802CBE5C(Unk802CBD04* o, Unk802CBD04_Vec3* a, Unk802CBD04_Vec3* b, Unk802CBD04_Vec3* c);
void fn_80402A04(int a, int b, Unk802CBD04_Vec3* c, void* d);
void fn_80402B0C(void* m, Unk802CBD04_Vec3* a, Unk802CBD04_Vec3* b);
class Unk802CC608_Obj;
void fn_802CC748(Unk802CC608_Obj* o, Unk802CC608_Obj** best, float* bestD, Unk802CBD04_Vec3* p);
extern "C" void* fn_8037CF5C(Unk8037C7FC* c, unsigned int hash, void* obj);

class Unk802CBD04_Iface : public Unk802CC53C_Target {
public:
    virtual void s17(float f, int a, Unk802CBD04* o, int b, int c);
};

extern "C" void fn_802CBD04(Unk802CBD04* o, int x)
{
    Unk802CBD04_Iface* t = (Unk802CBD04_Iface*)o->mA0;
    if (t != 0) {
        if (o->mE0 != 0 || o->mDC != 0 || *(int*)((char*)t + 0x18) == 0) {
            t->s17(0.016666668f, x, o, o->mDC, o->mE0);
        }
        o->mDC = 0;
        o->mE0 = 0;
    }
}

float fn_802CBD90(Unk802CBD04* o)
{
    return (o->mA4 / (1.0f - o->mA8)) * o->mAC;
}

int fn_802CBDB4(Unk802CBD04* o)
{
    return o->mD4;
}

void fn_802CBDBC(Unk802CBD04* o, int a, int b, int kind)
{
    o->mA0 = (Unk802CC53C_Target*)a;
    switch (kind) {
    case 1:
        o->mDC = 1;
        o->mE0 = 1;
        break;
    case 2:
        o->mDC = 0;
        o->mE0 = 0;
        break;
    case 0:
    default:
        o->mDC = b;
        o->mE0 = 1;
        break;
    }
}

extern "C" void fn_802CBE04(Unk802CBD04* o, Unk802CBD04_Vec3* a, Unk802CBD04_Vec3* b, Unk802CBD04_Vec3* c)
{
    *a = o->m160;
    *b = o->m16C;
    *c = o->m178;
}

void fn_802CC038(Unk802CBD04* o)
{
    fn_802CBE5C(o, &o->m160, &o->m16C, &o->m178);
}

void fn_802CC064(Unk802CBD04* o, Unk802CBD04_Vec3* a, Unk802CBD04_Vec3* b, int c)
{
    char sp8[0x10];
    Unk802CBD04_Vec3 sp18;
    Unk802CBD04_Vec3 sp28;
    Unk802CBD04_Vec3 sp38 = o->m60;
    fn_802CBE04(o, &sp18, a, &sp28);
    fn_80402A04(1, c, &sp38, sp8);
    fn_80402B0C(sp8, a, b);
}

void fn_802CC48C(Unk802CC48C* o, Unk802CC48C_Mat* out)
{
    if (o->m0 == 0) {
        fn_802CC0E8(o, out);
    }
    o->m0 = 1;
    *out = o->m20;
}

void fn_802CC53C(Unk802CBD04* o)
{
    Unk802CC53C_Target* t = o->mA0;
    if (t != 0) {
        t->s11(o);
    }
}

inline int Unk802CC580_Get(Unk802CC580_Data* d, unsigned idx)
{
    if (idx <= 0xC)
        return d->m65C[idx];
    return 0;
}
int fn_802CC580(Unk802CBD04* o, int k, unsigned idx)
{
    Unk802CC580_T* t = fn_801A04A8(o->mD8, k);
    if (t == 0) {
        t = fn_801A04A8(o->mD8, 1);
    }
    int r;
    if (t->m44 == 0) {
        r = Unk802CC580_Get(o->mD8, idx);
    } else {
        r = fn_803272D0(o->mD8->m50, idx);
    }
    return r;
}

/* Object with its vptr at +0x98 (slot 6 returns the object whose +0x60 position is used while lbl_806202F8 is 0). */
class Unk802CC608_Obj {
public:
    char pad0[0x60];
    Unk802CBD04_Vec3 m60;
    char pad6C[0x98 - 0x6C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual Unk802CC608_Obj* s6();
};
extern int lbl_806202F8;
float fn_804028E4(float x);
inline Unk802CBD04_Vec3 Unk802CC608_Sub(const Unk802CBD04_Vec3& a, const Unk802CBD04_Vec3& b)
{
    Unk802CBD04_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
inline float Unk802CC608_Len(const Unk802CBD04_Vec3& v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}

void fn_802CC608(Unk802CC608_Obj* o, Unk802CC608_Obj** best, float* bestD, Unk802CBD04_Vec3* p)
{
    if (o != 0) {
        float d = 0.0f;
        if (lbl_806202F8 == 0) {
            Unk802CBD04_Vec3 v = Unk802CC608_Sub(o->s6()->m60, *p);
            d = Unk802CC608_Len(v);
        } else {
            Unk802CBD04_Vec3 v = Unk802CC608_Sub(o->m60, *p);
            d = Unk802CC608_Len(v);
        }
        if (!(d <= *bestD)) {
            *best = o;
            *bestD = d;
        }
    }
}

void fn_802CC748(Unk802CC608_Obj* o, Unk802CC608_Obj** best, float* bestD, Unk802CBD04_Vec3* p)
{
    if (o != 0) {
        float d = 0.0f;
        if (lbl_806202F8 == 0) {
            Unk802CBD04_Vec3 v = Unk802CC608_Sub(o->s6()->m60, *p);
            d = Unk802CC608_Len(v);
        } else {
            Unk802CBD04_Vec3 v = Unk802CC608_Sub(o->m60, *p);
            d = Unk802CC608_Len(v);
        }
        if (!(d >= *bestD)) {
            *best = o;
            *bestD = d;
        }
    }
}

void fn_802CC888(Unk802CBD04* o, int idx, int a, int b, Unk802CBD04_Vec3* v)
{
    int e;
    if ((unsigned)idx <= 0xC) {
        e = o->m65C[idx];
    } else {
        e = 0;
    }
    Unk802CBD04_Vec3 t = *v;
    fn_802CC748((Unk802CC608_Obj*)e, (Unk802CC608_Obj**)a, (float*)b, &t);
}

int fn_802CC8EC(Unk802CBD04* o)
{
    Unk802CC53C_Target* t = o->mA0;
    int r = -1;
    if (t != 0) {
        int k = t->s16();
        r = lbl_8061ECAC[k];
    }
    return r;
}

struct Unk8019F8C0_Owner;
struct Unk802CE2C4_Obj {
    char pad0[0x3D44];
    int m3D44;
};
Unk802CE2C4_Obj* fn_801A6D84(Unk8019F8C0_Owner* o, int i);
extern "C" Unk802CBD04_Vec3 fn_80183918(int a, int b, int c);
extern "C" void fn_80402B48(const Unk802CBD04_Vec3* v, Unk802CBD04_Vec3* out);
extern Unk802CBD04_Vec3 lbl_806055AC;
inline Unk802CBD04_Vec3 Unk802CE2C4_Sub(const Unk802CBD04_Vec3& a, const Unk802CBD04_Vec3& b)
{
    Unk802CBD04_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

void fn_802CE2C4(Unk802CBD04* o, int k, int kind, Unk802CBD04_Vec3* out)
{
    *out = lbl_806055AC;
    if (o->mD8 != 0) {
        if (kind == 0x2F) {
            Unk802CE2C4_Obj* ow = fn_801A6D84((Unk8019F8C0_Owner*)o->mD8, k);
            int h = 0;
            if (ow != 0)
                h = ow->m3D44;
            if (o->mD8->m6B8 != 0) {
                Unk802CBD04_Vec3 b;
                Unk802CBD04_Vec3 a;
                a = fn_80183918(o->mD8->m6B8, h, 0);
                b = fn_80183918(o->mD8->m6B8, h, 2);
                *out = Unk802CE2C4_Sub(b, a);
                fn_80402B48(out, out);
            }
        } else {
            *out = lbl_806055AC;
        }
    }
}

void* fn_802CF168(void* o)
{
    return fn_8037CF5C(fn_8037C7FC(), 0xB38E54D3, o);
}

void fn_802CF1A4(void* o)
{
    fn_8037C7FC()->fn_8037CE98(0xB38E54D3, (int)o, 0);
}

void fn_802CF368(Unk802CF368_Self* o)
{
    o->fn_8037B458(lbl_805E32DC, &o->m8, lbl_805E2568, lbl_805E26D8);
    o->fn_8037B458(lbl_805E32E8, &o->mC, lbl_805E2568, lbl_805E26D8);
    o->fn_8037B458(lbl_805E32F8, &o->m4, lbl_805E2568, lbl_805E26D8);
    o->fn_8037B458(lbl_805E3308, &o->m10, lbl_805E2568, lbl_805E26D8);
    o->fn_8037B458(lbl_805E3310, &o->m14, lbl_805E2568, lbl_805E331C);
    o->fn_8037B458(lbl_805E3320, &o->m18, lbl_805E2568, lbl_805E26D8);
    o->fn_8037B458(lbl_805E3330, &o->m1C, lbl_805E2568, lbl_805E331C);
    o->fn_8037B548(lbl_805E3334, 0);
    o->fn_8037B548(lbl_805E3340, 0);
}

Unk802CF484::Unk802CF484()
{
    m0 = 0;
    m4 = 0.0f;
    m8 = 0.0f;
    mC = 0.0f;
    m10 = 0.0f;
    m14 = 0.0f;
    m18 = 0.0f;
}

void fn_802CF4B4(Unk802CF4B4_Self* self, Unk8037B3E8* reg)
{
    reg->fn_8037B7E8(lbl_805E3358);
    reg->fn_8037B458(lbl_805E3364, (int*)self, lbl_805E26D8, lbl_805E26D8);
    reg->fn_8037B50C(lbl_805E3374, &self->m4, lbl_805E3384, 0);
    reg->fn_8037B50C(lbl_805E3390, &self->m8, lbl_805E3384, 0);
    reg->fn_8037B50C(lbl_805E33A8, &self->mC, lbl_805E33C0, 0);
    reg->fn_8037B50C(lbl_805E33D0, &self->m10, lbl_805E3384, 0);
    reg->fn_8037B50C(lbl_805E33E4, &self->m14, lbl_805E3384, 0);
    reg->fn_8037B50C(lbl_805E33FC, &self->m18, lbl_805E33C0, 0);
    reg->fn_8037B830(lbl_805E3358);
}

float fn_80323848(int p);
double fn_80410634(double x);
float fn_8041171C(float x);
extern "C" int rand();

float fn_802CF5CC(int a, int b, float x, float y, float z)
{
    Unk802CC580_T* t = fn_801A04A8(((Unk802CBD04*)a)->mD8, b);
    float ph = (t->m44 != 0 || t->m48 == 0) ? t->m4C : fn_80323848(t->m48);
    float w = ph - (float)fn_80410634(ph * 0.15915494f) * 6.2831855f;
    float s = x * fn_8041171C(y * w);
    float lo = -1.0f;
    float r = (float)(rand() % 10000) * 0.0001f;
    float hi = 1.0f;
    s += z * (r * (hi - lo) + lo);
    return s;
}

void fn_802CF70C(Unk802CF70C_In* a, Unk802CF70C_Out* o, int p, int q)
{
    if (a->m0 != 0 && lbl_8061B8C0->m24 == 0) {
        o->x = o->x + fn_802CF5CC(p, q, a->m8, a->mC, a->m4);
        o->y = o->y + fn_802CF5CC(p, q, a->m14, a->m18, a->m10);
    }
}

extern const char lbl_805E2568[];
extern const char lbl_805E26D8[];
extern const char lbl_805E3444[];
extern const char lbl_805E3454[];
extern const char lbl_805E3460[];
extern const char lbl_805E3464[];
extern const char lbl_805E346C[];
extern const char lbl_805E3478[];
extern const char lbl_805E3488[];
extern const char lbl_805E37EC[];
extern const char lbl_805E37F8[];
extern const char lbl_805E380C[];
extern const char lbl_805E383C[];
extern const char lbl_805E3848[];
extern const char lbl_805E385C[];
extern const char lbl_805E3868[];
extern const char lbl_805E3874[];
extern const char lbl_805E3880[];
extern const char lbl_805E3890[];
extern const char lbl_805E389C[];
extern const char lbl_805E38A4[];
extern const char lbl_805E38B0[];
extern const char lbl_805E38C4[];
extern const char lbl_805E38D4[];
extern const char lbl_805E38E0[];
extern const char lbl_805E38EC[];
extern const char lbl_805E38FC[];
extern const char lbl_805E3908[];
extern const char lbl_805E3914[];
extern const char lbl_805E391C[];
extern const char lbl_805E3924[];
extern const char lbl_805E392C[];
extern const char lbl_805E3940[];
extern const char lbl_805E3954[];
extern const char lbl_805E3968[];
extern const char lbl_805E3978[];
extern const char lbl_805E3980[];
extern const char lbl_805E398C[];
extern const char lbl_805E3998[];
extern const char lbl_805E39A4[];
extern const char lbl_805E39AC[];
extern const char lbl_805E39C0[];
extern const char lbl_805E39C4[];
extern const char lbl_805E39CC[];
extern const char lbl_805E39E0[];
extern const char lbl_805E39EC[];
extern const char lbl_805E39F8[];
extern const char lbl_805E39FC[];
extern const char lbl_805E3A08[];
extern const char lbl_805E3A10[];
extern const char lbl_805E3A20[];
extern const char lbl_805E3A2C[];
extern const char lbl_805E3A40[];
extern const char lbl_805E3A50[];
extern const char lbl_805E3A5C[];
extern const char lbl_805E3A70[];
extern const char lbl_805E3A80[];
extern const char lbl_805E3A90[];
extern const char lbl_805E3A9C[];
extern const char lbl_805E3AAC[];
extern const char lbl_805E3AB8[];
extern const char lbl_805E3AD0[];
extern const char lbl_805E3AE0[];
extern const char lbl_805E3AF0[];
extern const char lbl_805E3B08[];
extern const char lbl_805E3B18[];
extern const char lbl_805E3B28[];
extern const char lbl_805E3B34[];
extern const char lbl_805E3B44[];
extern const char* lbl_8061ECA8;
int fn_804089B4(char* buf, const char* fmt, ...);
extern const char lbl_805E381C[];
extern const char lbl_805E382C[];
extern const char lbl_805E39B4[];
class Unk802CF894_Reg : public Unk8037B3E8 {
public:
    Unk802CF894_Reg(const char* name);   /* never defined */
    void fn_8037B548(const char* name, const char* def);
    void fn_8037B5C0(const char* name, int* field, const char* values);
};

struct Unk802CF894_Self {
    float m0;
    float m4;
    float m8;
    int mC;
    float m10;
    int m14;
    float m18;
    float m1C;
    int m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    int m34;
    int m38;
    int m3C;
    float m40;
    float m44;
    float m48;
    int m4C;
    int m50;
    float m54;
    int m58;
    float m5C;
    float m60;
    float m64;
    float m68;
    int m6C;
    int m70;
    float m74;
    float m78;
    float m7C;
    float m80;
    int m84;
    int m88;
    int m8C;
    float m90;
    float m94;
};

/* near-miss (3 slots): retail stores m78 first, then m34, with m74 late; ours hoists m74 above m78 and moves m34 after m38's group */
inline void* operator new(unsigned int, void* p) { return p; }

struct Unk802CF7A8_F {
    float m0;
    float m4;
    float m8;
    int mC;
    float m10;
    int m14;
    float m18;
    float m1C;
    int m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    int m34;
    int m38;
    int m3C;
    char pad40[0xc];
    int m4C;
    int m50;
    float m54;
    int m58;
    float m5C;
    float m60;
    float m64;
    float m68;
    int m6C;
    int m70;
    float m74;
    float m78;
    float m7C;
    float m80;
    int m84;
    int m88;
    int m8C;
    float m90;
    float m94;
};

void* fn_802CF7A8(void* o)
{
    Unk802CF7A8_F* f = (Unk802CF7A8_F*)o;
    new ((char*)o + 0x98) Unk802CF484;
    f->m78 = 0.0f;
    f->m18 = 1.0f;
    f->m1C = 88.0f;
    f->m38 = 0;
    f->m4C = 0;
    f->m50 = 0;
    f->m54 = 0.0f;
    f->m0 = 0.0f;
    f->m4 = 0.0f;
    f->m8 = 0.0f;
    f->m10 = 0.0f;
    f->m14 = 0;
    f->m28 = 0.0f;
    f->m2C = 0.0f;
    f->m24 = 0.0f;
    f->m30 = 0.0f;
    f->m3C = 0;
    f->mC = 0;
    f->m20 = 0;
    f->m58 = 0;
    f->m5C = 0.0f;
    f->m60 = 0.0f;
    f->m64 = 0.0f;
    f->m68 = 0.5f;
    f->m6C = 0;
    f->m70 = 0;
    f->m34 = 0;
    f->m74 = 0.0f;
    f->m7C = 20.0f;
    f->m80 = 20.0f;
    f->m84 = 0;
    f->m88 = 0;
    f->m8C = 0;
    f->m90 = 0.5f;
    f->m94 = 0.5f;
    return o;
}

void fn_802CF894(Unk802CF894_Self* s, Unk802CF894_Reg* r)
{
    char buf[0x68];
    r->fn_8037B50C(lbl_805E3444, &s->m68, lbl_805E3454, lbl_805E3460);
    r->fn_8037B7E8(lbl_805E3464);
    r->fn_8037B7E8(lbl_805E346C);
    r->fn_8037B674(lbl_805E3478, &s->m34, lbl_805E3488, 0);
    r->fn_8037B674(lbl_805E37EC, &s->m38, lbl_805E37F8, 0);
    r->fn_8037B7E8(lbl_805E380C);
    r->fn_8037B5C0(lbl_805E381C, &s->m3C, lbl_805E382C);
    r->fn_8037B830(lbl_805E380C);
    r->fn_8037B50C(lbl_805E383C, &s->m40, lbl_805E3848, lbl_805E26D8);
    r->fn_8037B50C(lbl_805E385C, &s->m44, lbl_805E3848, lbl_805E26D8);
    r->fn_8037B50C(lbl_805E3868, &s->m48, lbl_805E3848, lbl_805E26D8);
    r->fn_8037B830(lbl_805E346C);
    r->fn_8037B7E8(lbl_805E3874);
    r->fn_8037B674(lbl_805E3880, &s->m4C, lbl_805E3488, 0);
    r->fn_8037B674(lbl_805E3890, &s->m50, lbl_805E37F8, 0);
    r->fn_8037B50C(lbl_805E389C, &s->m54, lbl_805E38A4, 0);
    r->fn_8037B7E8(lbl_805E38B0);
    r->fn_8037B458(lbl_805E38C4, &s->m58, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B50C(lbl_805E38D4, &s->m5C, lbl_805E38E0, 0);
    r->fn_8037B50C(lbl_805E38EC, &s->m60, lbl_805E38FC, 0);
    r->fn_8037B830(lbl_805E38B0);
    r->fn_8037B830(lbl_805E3874);
    r->fn_8037B7E8(lbl_805E3908);
    r->fn_8037B50C(lbl_805E3914, &s->m0, lbl_8061ECA8, 0);
    r->fn_8037B50C(lbl_805E391C, &s->m4, lbl_8061ECA8, 0);
    r->fn_8037B50C(lbl_805E3924, &s->m8, lbl_8061ECA8, 0);
    r->fn_8037B458(lbl_805E392C, &s->mC, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B548(lbl_805E3940, lbl_805E3954);
    r->fn_8037B548(lbl_805E3968, lbl_805E3954);
    r->fn_8037B830(lbl_805E3908);
    r->fn_8037B7E8(lbl_805E3978);
    r->fn_8037B50C(lbl_805E3980, &s->m24, lbl_805E3454, 0);
    r->fn_8037B50C(lbl_805E398C, &s->m28, lbl_805E3454, 0);
    r->fn_8037B50C(lbl_805E3998, &s->m2C, lbl_805E3454, 0);
    r->fn_8037B50C(lbl_805E39A4, &s->m30, lbl_805E3454, lbl_805E26D8);
    r->fn_8037B830(lbl_805E3978);
    fn_802CF4B4((Unk802CF4B4_Self*)((char*)s + 0x98), r);
    r->fn_8037B7E8(lbl_805E39AC);
    fn_804089B4(buf, lbl_805E39B4, 0.1f, 72.0f);
    r->fn_8037B50C(lbl_805E39C0, &s->m10, buf, lbl_805E39C4);
    r->fn_8037B458(lbl_805E39CC, &s->m20, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B458(lbl_805E39E0, &s->m14, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B50C(lbl_805E39EC, &s->m18, buf, lbl_805E39F8);
    r->fn_8037B50C(lbl_805E39FC, &s->m1C, buf, lbl_805E3A08);
    r->fn_8037B830(lbl_805E39AC);
    r->fn_8037B50C(lbl_805E3A10, &s->m64, lbl_805E3A20, 0);
    r->fn_8037B548(lbl_805E3A2C, lbl_805E39C0);
    r->fn_8037B548(lbl_805E3A40, lbl_805E39C0);
    r->fn_8037B7E8(lbl_805E3A50);
    r->fn_8037B458(lbl_805E3A5C, &s->m6C, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B674(lbl_805E3A70, &s->m70, lbl_805E3488, 0);
    r->fn_8037B50C(lbl_805E3A80, &s->m74, lbl_805E3A90, lbl_805E26D8);
    r->fn_8037B50C(lbl_805E3A9C, &s->m7C, lbl_805E3AAC, lbl_805E26D8);
    r->fn_8037B458(lbl_805E3AB8, &s->m84, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B50C(lbl_805E3AD0, &s->m78, lbl_805E3A90, lbl_805E26D8);
    r->fn_8037B50C(lbl_805E3AE0, &s->m80, lbl_805E3AAC, lbl_805E26D8);
    r->fn_8037B458(lbl_805E3AF0, &s->m88, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B830(lbl_805E3A50);
    r->fn_8037B7E8(lbl_805E3B08);
    r->fn_8037B458(lbl_805E3B18, &s->m8C, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B50C(lbl_805E3B28, &s->m90, lbl_805E3454, lbl_805E3460);
    r->fn_8037B50C(lbl_805E3B34, &s->m94, lbl_805E3454, lbl_805E3460);
    r->fn_8037B830(lbl_805E3B44);
    r->fn_8037B830(lbl_805E3B08);
}
