/*
 * Game code, .text 0x802CFED4-0x802D3E44 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802CFED4.h"
#include "game/tu_802CBD04.h"

extern Unk802D0B4C_Vec3 lbl_806055AC;
extern const char lbl_805E3BA4[];
extern const char lbl_805E3BB0[];
extern const char lbl_805E3BBC[];
extern const char lbl_805E3488[];
extern const char lbl_805E3BCC[];
extern const char lbl_805E3BDC[];
extern const char lbl_805E382C[];
extern const char lbl_805E3BEC[];
extern const char lbl_805E26D8[];
extern const char lbl_805E2444[];
extern const char lbl_805E3C00[];
extern const char lbl_805E3C14[];
extern const char lbl_805E3C18[];
extern const char lbl_805E3C28[];
extern const char lbl_805E3C2C[];
extern const char lbl_805E3C40[];
extern const char lbl_805E3C48[];
extern const char lbl_805E3C58[];
extern const char lbl_805E3C78[];
extern const char lbl_805E3C84[];
extern const char lbl_805E39F8[];
extern int lbl_806EF9B4;
extern const void* lbl_806646F0[];
extern const void* lbl_80664528[];
extern Unk802D116C lbl_8068DAF4;
extern Unk802D116C lbl_8068DBE8;
extern Unk802D116C lbl_8068DD20;
extern Unk802D116C lbl_8068DD64;
void fn_8037B424(void* p, int c);
void fn_8033CD28(void* p, int c);
extern int lbl_8068DBE4;
extern int lbl_8068DD1C;
extern int lbl_8068DD60;
extern int lbl_8068DDA8;
void* fn_802D10A0(void* p);
void* fn_802D1EA4(void* p);
void* fn_802D3268(void* p);
void* fn_802D1278(void* p);
int fn_80409CF0(void (*f)());
void fn_802D370C();
void fn_802D3738();
void fn_802D3794();
void fn_802D37CC();
extern Unk802D38E8_Cfg* lbl_8061FEDC;
void fn_8014D9EC(void* buf, float a, float b, float c, float d, float e);
void fn_803DFB48(Unk802D3958_Mat* m);

void* operator new(unsigned int n, int heap);
void fn_802CFED4(void* o);
extern int lbl_80620418;
float fn_802D7E2C(int h);
void fn_802D095C(void* o, float a, float b);
void fn_802D0D30(void* o);
void fn_802D0F74(void* o, float t);

Unk802D0B4C::Unk802D0B4C()
{
    mC = lbl_806055AC;
    m18 = 1.0f;
    m0 = 0;
    m4 = 0;
    m8 = 0;
}

void fn_802D0B94(Unk802D0B94_Self* self, Unk8037B3E8* reg)
{
    Unk802D0B94_Reg* r = (Unk802D0B94_Reg*)reg;
    r->fn_8037B7E8(lbl_805E3BA4);
    r->fn_8037B7E8(lbl_805E3BB0);
    r->fn_8037B674(lbl_805E3BBC, (int*)self, lbl_805E3488, 0);
    r->fn_8037B7E8(lbl_805E3BCC);
    r->fn_8037B5C0(lbl_805E3BDC, &self->m4, lbl_805E382C);
    r->fn_8037B830(lbl_805E3BCC);
    r->fn_8037B458(lbl_805E3BEC, &self->m8, 0, lbl_805E26D8);
    r->fn_8037B830(lbl_805E3BB0);
    r->fn_8037B50C(lbl_805E2444, &self->mC, lbl_805E3C00, 0);
    r->fn_8037B50C(lbl_805E3C14, &self->m10, lbl_805E3C18, 0);
    r->fn_8037B50C(lbl_805E3C28, &self->m14, lbl_805E3C00, 0);
    r->fn_8037B548(lbl_805E3C2C, lbl_805E3C40);
    r->fn_8037B548(lbl_805E3C48, lbl_805E3C40);
    r->fn_8037B548(lbl_805E3C58, lbl_805E3C40);
    r->fn_8037B50C(lbl_805E3C78, &self->m18, lbl_805E3C84, lbl_805E39F8);
    r->fn_8037B830(lbl_805E3BA4);
}

struct Unk802CF894_Self;
class Unk802CF894_Reg;
void fn_802CF894(Unk802CF894_Self* s, Unk802CF894_Reg* r);
void fn_802CF368(Unk802CF368_Self* o);

void fn_802D1128(Unk802CF368_Self* self)
{
    fn_802CF368(self);
    fn_802D0B94((Unk802D0B94_Self*)((char*)self + 0xD4), self);
    fn_802CF894((Unk802CF894_Self*)((char*)self + 0x20), (Unk802CF894_Reg*)self);
}

void fn_802D116C(Unk802D116C* p, int c)
{
    p->vptr = lbl_806646F0;
    fn_8037B424(p, c);
}

void fn_802D119C()
{
}

extern const void* lbl_80664658[];
extern const char lbl_805E26DC[];
extern const char lbl_805E3CA0[];
void fn_802CF7A8(void* o);
inline void* operator new(unsigned int, void* p) { return p; }

/* near-miss (33/34 insns): retail stores the base fields m18, m1C first, then the vptr, then m4..m14 (mid-class constructor inlined); the 8 stores here are the best order found by search */
Unk802D10A0::Unk802D10A0()
{
    void* p = this;
    new (p) Unk8037B3E8(lbl_805E26DC);
    int* q = (int*)p;
    q[1] = 0;
    q[5] = 1;
    q[2] = 0;
    q[3] = 0;
    q[4] = 0;
    q[6] = 0;
    q[7] = 1;
    *(const void***)p = lbl_80664658;
    fn_802CF7A8((char*)p + 0x20);
    new ((char*)p + 0xD4) Unk802D0B4C;
    ((Unk8037B3E8*)p)->fn_8037B7E4(lbl_805E3CA0);
}

Unk802D10A0* fn_802D11A0()
{
    return new (lbl_806EF9B4) Unk802D10A0;
}

void fn_802D11D0(char* o)
{
    fn_802D0D30(o + 0xD4);
}

void fn_802D11F4(char* o, float t)
{
    fn_802D0F74(o + 0xD4, t);
}

void fn_802D1220(char* o)
{
    fn_802CFED4(o + 0x20);
}

void fn_802D1244(char* o, float a, float b)
{
    fn_802D095C(o + 0x20, a, b);
}

extern const void* lbl_806645C0[];
extern const char lbl_805E26EC[];
extern unsigned int lbl_8061EDB8;
const char* fn_802D7288();
unsigned int fn_80378568(const char* token, int len);

struct Unk802D1278_F {
    const void* vptr;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    Unk802D0B4C_Vec3 m20;
    Unk802D0B4C_Vec3 m2C;
    float m38;
    int m3C;
    int m40;
};

Unk802D1278::Unk802D1278()
{
    Unk802D1278_F* f = (Unk802D1278_F*)this;
    new (f) Unk8037B3E8(lbl_805E26EC);
    f->vptr = lbl_806645C0;
    f->m4 = 0;
    f->m8 = 0;
    f->mC = 0;
    f->m10 = 0;
    f->m14 = 1;
    f->m1C = 1;
    f->m18 = 0;
    if (lbl_8061EDB8 == 0)
        lbl_8061EDB8 = fn_80378568(fn_802D7288(), 0);
    f->m2C = lbl_806055AC;
    f->m20 = f->m2C;
    f->m38 = 600.0f;
    f->m3C = 0;
    f->m40 = 0;
}

void fn_802D134C()
{
}

class Unk802D1350_V {
public:
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4();
};
class Unk802D1350_Cam : public Unk802D1350_V {
public:
    char pad4[0x20 - 0x4];
    Unk802D0B4C_Vec3 m20;
    Unk802D0B4C_Vec3 m2C;
};

void fn_802D1350(Unk802D1350_Cam* self, Unk802D1350_Cam* other)
{
    if (other != 0) {
        if (self->s4() == other->s4()) {
            other->m20 = self->m20;
            other->m2C = self->m2C;
        }
    }
}

float fn_802D7E2C(int h, int k);
float fn_802CBD90(Unk802CBD04* o);

float fn_802D18C4(int unused, Unk802CBD04* cam)
{
    float s = 0.33333334f;
    int h = lbl_80620418;
    if (h == -1)
        return fn_802CBD90(cam);
    s = s * (1.0f - fn_802D7E2C(h, 0x49));
    float a = s * fn_802D7E2C(h, 0x47);
    float b = s * fn_802D7E2C(h, 0x46);
    float r = (fn_802CBD90(cam) + a) - b;
    return !(r > 72.0f) ? (r >? 0.1f) : 72.0f;
}

/* near-miss (5 slots): retail shares one stw r0,0(r31) between the two arms (r0 = 1/3 from the ternary or (v+1)&3); ours stores in each arm. */
void fn_802D19B8(int* p)
{
    int r;
    if (fn_802D7E2C(lbl_80620418) != 0.0f) {
        r = *p > 1 ? 3 : 1;
        *p = r;
    } else if (*p & 1) {
        r = (*p + 1) & 3;
        *p = r;
    }
}

int fn_802D1A2C(int k)
{
    return k == 2;
}

void fn_802D1A3C()
{
}

void fn_802D1A40(float)
{
}

void fn_802D1A50()
{
}

void fn_802D1A54(float, float)
{
}

void fn_802D1E28(char* o)
{
    char buf[0x10];
    if (*(int*)(o + 0x3C) != 0) {
        fn_8014D9EC(buf, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    }
}

Unk802D1278* fn_802D1E74()
{
    return new (lbl_806EF9B4) Unk802D1278;
}

void fn_802CF894(void* o, void* reg);
void fn_802CF368(Unk802CF368_Self* o);
extern const char lbl_805E2568[];
extern const char lbl_805E26D8[];
extern const char lbl_805E331C[];
extern const char lbl_805E3454[];
extern const char lbl_805E3488[];
extern const char lbl_805E3848[];
extern const char lbl_805E39F8[];
extern const char lbl_805E3BA4[];
extern const char lbl_805E3BEC[];
extern const char lbl_805E3D40[];
extern const char lbl_805E3D44[];
extern const char lbl_805E3D58[];
extern const char lbl_805E3D6C[];
extern const char lbl_805E3D7C[];
extern const char lbl_805E3D8C[];
extern const char lbl_805E3D98[];
extern const char lbl_805E3DA8[];
extern const char lbl_805E3DB4[];
extern const char lbl_805E3DB8[];
extern const char lbl_805E3DC4[];
extern const char lbl_805E3DD0[];
extern const char lbl_805E3DDC[];
extern const char lbl_805E3DE8[];
extern const char lbl_805E3DF0[];
extern const char lbl_805E3E00[];
extern const char lbl_805E3E08[];
extern const char lbl_805E3E10[];
extern const char lbl_805E3E28[];
extern const char lbl_805E3E40[];
extern const char lbl_805E3E54[];
extern const char lbl_805E3E5C[];
extern const char lbl_805E3E68[];
extern const char lbl_805E3E78[];
extern const char lbl_805E3EA4[];
extern const char lbl_805E3EAC[];
extern const char lbl_805E3EB8[];
extern const char lbl_805E3EC4[];
extern const char lbl_805E3ED4[];
extern const char lbl_805E3EE0[];
extern const char lbl_805E3EEC[];
extern const char lbl_805E3EFC[];
extern const char lbl_805E3F00[];
extern const char lbl_805E3F0C[];
extern const char* lbl_8061ECA8;
class Unk802D1FA8_Self : public Unk802CF368_Self {
public:
    Unk802D1FA8_Self(const char* name);   /* never defined */
    int m20;
    int m24;
    float m28;
    char pad2C[0x38 - 0x2C];
    float m38;
    float m3C;
    float m40;
    float m44;
    float m48;
    float m4C;
    float m50;
    float m54;
    float m58;
    float m5C;
    int m60;
    float m64;
    float m68;
    float m6C;
    float m70;
    float m74;
    char pad78[0x12C - 0x78];
    int m12C;
    int m130;
};

extern const void* lbl_80664528[];
extern const char lbl_805E2700[];
void fn_8033CCE0(void* p);

struct Unk802D1EA4_F {
    const void* vptr;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    float m28;
    char pad2C[0x38 - 0x2C];
    Unk802D0B4C_Vec3 m38;
    float m44;
    float m48;
    float m4C;
    float m50;
    float m54;
    float m58;
    float m5C;
    int m60;
    float m64;
    float m68;
    float m6C;
    float m70;
    float m74;
    char pad78[0x12C - 0x78];
    int m12C;
    int m130;
};

Unk802D1EA4::Unk802D1EA4()
{
    Unk802D1EA4_F* f = (Unk802D1EA4_F*)this;
    new (f) Unk8037B3E8(lbl_805E2700);
    f->m4 = 0;
    f->m8 = 0;
    f->mC = 0;
    f->m10 = 0;
    f->m14 = 1;
    f->m18 = 0;
    f->m1C = 1;
    f->vptr = lbl_80664528;
    fn_8033CCE0((char*)f + 0x2C);
    fn_802CF7A8((char*)f + 0x78);
    f->m20 = 0;
    f->m24 = 0;
    f->m38 = lbl_806055AC;
    f->m58 = 0.0f;
    f->m5C = 10.0f;
    f->m60 = 0;
    f->m64 = 10.0f;
    f->m68 = 20.0f;
    f->m6C = 10.0f;
    f->m28 = 1.0f;
    f->m70 = 0.0f;
    f->m74 = 0.0f;
    f->m44 = 0.0f;
    f->m48 = 0.0f;
    f->m4C = 0.0f;
    f->m50 = 0.0f;
    f->m54 = 0.0f;
    f->m12C = 0;
    f->m130 = 1;
}

void fn_802D1FA8(Unk802D1FA8_Self* r)
{
    r->fn_8037B7E4(lbl_805E3D40);
    fn_802CF368(r);
    r->fn_8037B7E8(lbl_805E3BA4);
    r->fn_8037B458(lbl_805E3D44, &r->m12C, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B458(lbl_805E3D58, &r->m130, lbl_805E2568, lbl_805E331C);
    r->fn_8037B7E8(lbl_805E3D6C);
    r->fn_8037B674(lbl_805E3D7C, &r->m20, lbl_805E3488, 0);
    r->fn_8037B458(lbl_805E3BEC, &r->m24, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B50C(lbl_805E3D8C, &r->m28, lbl_805E3D98, lbl_805E39F8);
    r->fn_8037B50C(lbl_805E3DA8, &r->m44, lbl_805E3848, lbl_805E3DB4);
    r->fn_8037B50C(lbl_805E3DB8, &r->m48, lbl_805E3848, lbl_805E3DB4);
    r->fn_8037B50C(lbl_805E3DC4, &r->m4C, lbl_805E3848, lbl_805E3DB4);
    r->fn_8037B50C(lbl_805E3DD0, &r->m50, lbl_805E3848, lbl_805E3DB4);
    r->fn_8037B50C(lbl_805E3DDC, &r->m54, lbl_805E3848, lbl_805E3DB4);
    r->fn_8037B830(lbl_805E3D6C);
    r->fn_8037B50C(lbl_805E3DE8, &r->m38, lbl_805E3DF0, 0);
    r->fn_8037B50C(lbl_805E3E00, &r->m3C, lbl_805E3DF0, 0);
    r->fn_8037B50C(lbl_805E3E08, &r->m40, lbl_805E3DF0, 0);
    r->fn_8037B548(lbl_805E3E10, lbl_805E3E28);
    r->fn_8037B548(lbl_805E3E40, lbl_805E3E28);
    r->fn_8037B50C(lbl_805E3E54, &r->m58, lbl_805E3454, lbl_805E26D8);
    r->fn_8037B728(lbl_805E3E5C, lbl_805E3E68, (char*)r + 0x2C, (int)lbl_805E3E78);
    r->fn_8037B7E8(lbl_805E3EA4);
    r->fn_8037B50C(lbl_805E3EAC, &r->m5C, lbl_805E3EB8, 0);
    r->fn_8037B458(lbl_805E3EC4, &r->m60, lbl_805E2568, lbl_805E26D8);
    r->fn_8037B50C(lbl_805E3ED4, &r->m64, lbl_805E3848, lbl_805E3DB4);
    r->fn_8037B50C(lbl_805E3EE0, &r->m68, lbl_805E3848, lbl_805E3DB4);
    r->fn_8037B50C(lbl_805E3EEC, &r->m6C, lbl_805E3848, lbl_805E3EFC);
    r->fn_8037B830(lbl_805E3EA4);
    r->fn_8037B50C(lbl_805E3F00, &r->m70, lbl_8061ECA8, 0);
    r->fn_8037B50C(lbl_805E3F0C, &r->m74, lbl_8061ECA8, 0);
    r->fn_8037B830(lbl_805E3BA4);
    fn_802CF894((char*)r + 0x78, r);
}

Unk802D1EA4* fn_802D2314()
{
    return new (lbl_806EF9B4) Unk802D1EA4;
}

void fn_802D2344(Unk802D2344* o)
{
    o->m5C = o->m5C * 12.0f;
    o->m38.Scale(12.0f);
    o->m64 = o->m64 * 12.0f;
    o->m68 = o->m68 * 12.0f;
    o->m6C = o->m6C * 12.0f;
}

void fn_802D23B8()
{
}

void fn_802D3210(char* o)
{
    fn_802CFED4(o + 0x78);
}

void fn_802D3234(char* o, float a, float b)
{
    fn_802D095C(o + 0x78, a, b);
}

extern const void* lbl_80664490[];
extern const char lbl_805E270C[];

Unk802D3268::Unk802D3268()
{
    void* p = this;
    new (p) Unk8037B3E8(lbl_805E270C);
    *(const void***)p = lbl_80664490;
    int* q = (int*)p;
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
    q[4] = 0;
    q[5] = 1;
    q[6] = 0;
    q[7] = 1;
    *(Unk802D0B4C_Vec3*)((char*)p + 0x20) = lbl_806055AC;
    *(Unk802D0B4C_Vec3*)((char*)p + 0x30) = lbl_806055AC;
    *(float*)((char*)p + 0x3C) = 30.0f;
}

void fn_802D331C()
{
}

void fn_802D3320(Unk802D3320* o)
{
    o->m20.Scale(12.0f);
}

extern const char lbl_805E3F68[];
extern const char lbl_805E3BA4[];
extern const char lbl_805E3F6C[];
extern const char lbl_805E3DF0[];
extern const char lbl_805E3F78[];
extern const char lbl_805E3F84[];
extern const char lbl_805E3E54[];
extern const char lbl_805E3454[];
extern const char lbl_805E26D8[];
extern const char lbl_805E3464[];
extern const char lbl_805E3F90[];
extern const char lbl_805E3F98[];
extern const char lbl_805E3FA0[];
extern const char lbl_805E39B4[];
extern const char lbl_805E39C0[];
extern const char lbl_805E39C4[];
int fn_804089B4(char* buf, const char* fmt, ...);

class Unk802D3364_Self : public Unk802CF368_Self {
public:
    Unk802D3364_Self(const char* name);   /* never defined */
    char pad20[0x20 - 0x20];
    float m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
};

void fn_802D3364(Unk802D3364_Self* r)
{
    char buf[0x40];
    r->fn_8037B7E4(lbl_805E3F68);
    fn_802CF368(r);
    r->fn_8037B7E8(lbl_805E3BA4);
    r->fn_8037B50C(lbl_805E3F6C, &r->m20, lbl_805E3DF0, 0);
    r->fn_8037B50C(lbl_805E3F78, &r->m24, lbl_805E3DF0, 0);
    r->fn_8037B50C(lbl_805E3F84, &r->m28, lbl_805E3DF0, 0);
    r->fn_8037B50C(lbl_805E3E54, &r->m2C, lbl_805E3454, lbl_805E26D8);
    r->fn_8037B830(lbl_805E3BA4);
    r->fn_8037B7E8(lbl_805E3464);
    r->fn_8037B50C(lbl_805E3F90, &r->m30, lbl_805E3DF0, 0);
    r->fn_8037B50C(lbl_805E3F98, &r->m34, lbl_805E3DF0, 0);
    r->fn_8037B50C(lbl_805E3FA0, &r->m38, lbl_805E3DF0, 0);
    fn_804089B4(buf, lbl_805E39B4, 0.1f, 72.0f);
    r->fn_8037B50C(lbl_805E39C0, &r->m3C, buf, lbl_805E39C4);
    r->fn_8037B830(lbl_805E3464);
}

Unk802D3268* fn_802D34EC()
{
    return new (lbl_806EF9B4) Unk802D3268;
}

struct Unk802D360C_Self {
    char pad0[0x2C];
    float m2C;
};
inline Unk802D0B4C_Vec3 Unk802D360C_Sub(const Unk802D0B4C_Vec3& a, const Unk802D0B4C_Vec3& b)
{
    Unk802D0B4C_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
inline Unk802D0B4C_Vec3 Unk802D360C_Mul(const Unk802D0B4C_Vec3& v, float k)
{
    Unk802D0B4C_Vec3 r;
    r.x = v.x * k;
    r.y = v.y * k;
    r.z = v.z * k;
    return r;
}

struct Unk8026C414_M;
Unk802D0B4C_Vec3 fn_8026CB70(Unk8026C414_M* m, int i);
int fn_802CBDB4(Unk802CBD04* o);

struct Unk802D351C_Self {
    char pad0[0x20];
    Unk802D0B4C_Vec3 m20;
};
inline Unk802D0B4C_Vec3 Unk802D351C_Add(const Unk802D0B4C_Vec3& a, const Unk802D0B4C_Vec3& b)
{
    Unk802D0B4C_Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

void fn_802D351C(Unk802D351C_Self* self, int unused, Unk802D0B4C_Vec3* out, Unk802CBD04* cam)
{
    Unk8026C414_M* m = (Unk8026C414_M*)fn_802CBDB4(cam);
    Unk802D0B4C_Vec3 v = lbl_806055AC;
    if (m != 0)
        v = fn_8026CB70(m, 1);
    *out = Unk802D351C_Add(v, self->m20);
}

void fn_802D360C(Unk802D360C_Self* self, Unk802D0B4C_Vec3* a, Unk802D0B4C_Vec3* b, float t)
{
    Unk802D0B4C_Vec3 d = Unk802D360C_Sub(*b, *a);
    Unk802D0B4C_Vec3 s = Unk802D360C_Mul(d, self->m2C);
    b->x = b->x + s.x;
    b->y = b->y + s.y;
    b->z = b->z + s.z;
}

void fn_802D36D0(Unk802D36D0* o, int, Unk802D0B4C_Vec3* a, float* b)
{
    *b = o->m3C;
    *a = o->m30;
}

void fn_802D36F8(float, float)
{
}

void fn_802D370C()
{
    fn_802D116C(&lbl_8068DAF4, 2);
}

void fn_802D3738()
{
    lbl_8068DBE8.vptr = lbl_80664528;
    fn_8033CD28(lbl_8068DBE8.m2C, 2);
    lbl_8068DBE8.vptr = lbl_806646F0;
    fn_8037B424(&lbl_8068DBE8, 2);
}

void fn_802D3794()
{
    lbl_8068DD20.vptr = lbl_806646F0;
    fn_8037B424(&lbl_8068DD20, 2);
}

void fn_802D37CC()
{
    lbl_8068DD64.vptr = lbl_806646F0;
    fn_8037B424(&lbl_8068DD64, 2);
}

void fn_802D3804()
{
    if (lbl_8068DBE4 == 0) {
        fn_802D10A0(&lbl_8068DAF4);
        lbl_8068DBE4 = 1;
        fn_80409CF0(fn_802D370C);
    }
    if (lbl_8068DD1C == 0) {
        fn_802D1EA4(&lbl_8068DBE8);
        lbl_8068DD1C = 1;
        fn_80409CF0(fn_802D3738);
    }
    if (lbl_8068DD60 == 0) {
        fn_802D3268(&lbl_8068DD20);
        lbl_8068DD60 = 1;
        fn_80409CF0(fn_802D3794);
    }
    if (lbl_8068DDA8 == 0) {
        fn_802D1278(&lbl_8068DD64);
        lbl_8068DDA8 = 1;
        fn_80409CF0(fn_802D37CC);
    }
}

float fn_802D38E8()
{
    Unk802D38E8_Cfg* g = lbl_8061FEDC;
    if (g->m204 != 0 || g->m208 != 0) {
        return 1.3333334f;
    }
    return 1.0f;
}

float fn_802D3920()
{
    Unk802D38E8_Cfg* g = lbl_8061FEDC;
    if (g->m204 != 0 || g->m208 != 0) {
        return 1.7777778f;
    }
    return 1.3333334f;
}

void fn_802D3958(Unk802D3958* o)
{
    o->m120 = o->m20;
    fn_803DFB48(&o->m120);
}

class Unk802D3B40_A {
public:
    virtual ~Unk802D3B40_A();
};
struct Unk802D3B40_BD {
    char pad0[0x98];
};
class Unk802D3B40_B : public Unk802D3B40_BD {
public:
    virtual ~Unk802D3B40_B();
};
struct Unk802D3B40_Self {
    int m0;
    int m4;
    const void* m8;
    char padC[0x68 - 0xC];
    Unk802D3B40_A* m68;
    Unk802D3B40_B* m6C;
    Unk802D3B40_B* m70;
    Unk802D3B40_B* m74;
    Unk802D3B40_B* m78;
};
extern const void* lbl_80664430[];
extern const void* lbl_80649DB8[];
void fn_80378620(void* self, int chrg);

struct Unk802D39EC_V {
    char pad0[0xC];
    void* mC;
};
struct Unk802D39EC_S {
    char pad0[8];
    const void* m8;
    char padC[0x44 - 0xC];
    Unk802CF484 m44;
    int m60;
    Unk802D39EC_V* m64;
    void* m68;
    void* m6C;
    void* m70;
    void* m74;
    void* m78;
    char pad7C[0xC4 - 0x7C];
    int mC4;
    char padC8[0x160 - 0xC8];
    void* m160;
};
extern const void* lbl_80664430[];
extern const char lbl_805E3FF4[];
void fn_803785E4(void* p);
void fn_80378A34(void* p, int q);
void* fn_802CB924(void* mem, int a);
void fn_802D3C80(void* p);
void fn_802CBDBC(Unk802CBD04* o, int a, int b, int kind);
void* fn_802CF168(void* name);

extern "C" void* fn_802D39EC(void* mem, int a, void* owner, int b)
{
    Unk802D39EC_S* self = (Unk802D39EC_S*)mem;
    fn_803785E4(self);
    self->m8 = lbl_80664430;
    new (&self->m44) Unk802CF484;
    self->m60 = a;
    self->m64 = (Unk802D39EC_V*)owner;
    self->mC4 = b;
    self->m68 = 0;
    self->m6C = 0;
    self->m70 = 0;
    self->m74 = 0;
    self->m78 = 0;
    self->m160 = fn_802CF168((void*)lbl_805E3FF4);
    fn_80378A34(self, a + 0x704);
    if (b != 0) {
        self->m70 = fn_802CB924(operator new(0x1E0, 0), a);
        ((Unk802D39EC_V*)owner)->mC = self->m70;
    } else {
        self->m68 = new (0) Unk802D1278;
        self->m74 = fn_802CB924(operator new(0x1E0, 0), a);
        if (self->m74 != 0)
            fn_802CBDBC((Unk802CBD04*)self->m74, (int)self->m68, 1, 0);
        self->m6C = fn_802CB924(operator new(0x1E0, 0), a);
        void* r = fn_802CB924(operator new(0x1E0, 0), a);
        self->m70 = r;
        ((Unk802D39EC_V*)owner)->mC = r;
        self->m78 = fn_802CB924(operator new(0x1E0, 0), a);
    }
    fn_802D3C80(self);
    return self;
}

/* near-miss (80/81 insns, 78 words equal): retail keeps the zero of the m78 store in r30 across the m6C delete and reuses it for m6C; ours loads a second zero (li r0,0) for m6C */
void fn_802D3B40(Unk802D3B40_Self* s, int chrg)
{
    s->m8 = lbl_80664430;
    if (s->m74 != 0) {
        if (s->m68 != 0)
            delete s->m68;
        s->m68 = 0;
        if (s->m74 != 0)
            delete s->m74;
        s->m74 = 0;
    }
    if (s->m78 != 0)
        delete s->m78;
    s->m78 = 0;
    if (s->m6C != 0)
        delete s->m6C;
    s->m6C = 0;
    if (s->m70 != 0)
        delete s->m70;
    s->m70 = 0;
    s->m8 = lbl_80649DB8;
    fn_80378620(s, chrg);
}

void fn_802D3E10(Unk802D3E10* o)
{
    o->s7();
}
