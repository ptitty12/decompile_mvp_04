/*
 * Game code, .text 0x8023A6C8-0x8023DB8C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8023A6C8.h"
#include "game/goals/tu_8027A84C.h"

extern const int lbl_805D9E50[];

Unk8023BE30::Unk8023BE30()
{
    m0 = 0;
}

extern int lbl_8061D194;
extern int lbl_8068CCDC;
extern int lbl_8068CCE0;
extern int lbl_8068CCE4;
extern int lbl_8068CCE8;
extern int lbl_8068CCEC;
extern int lbl_8068CCF4;
extern int lbl_8068CCF8;
extern int lbl_8068CCFC;
void fn_802398D4();
void fn_80236FD8(Unk802362A8_Slots* s);
int fn_801A2034(Unk8022FE34_Ctx* c, int i);
int fn_80088234(void* o, int i);

extern const float lbl_805D7D0C;
extern const float lbl_805D7D10;
Unk8022FE34_X6D* fn_801A6DB8(Unk8022FE34_Ctx* c);
void fn_8023AC54(int a, int b);

struct Unk8023A6C8_Pt {
    char pad0[0x14];
    float m14;
    float m18;
};

void Unk802362A8_Cpu::fn_8023A6C8(int a)
{
    Unk8022FE34_Ctx* c = m2E4;
    Unk8023A6C8_Pt* p = (Unk8023A6C8_Pt*)((char*)m2E0 + 0xc);
    if (c->m6F4 == 3) {
        fn_8023A13C();
    } else if (fn_801A6DB8(c)->m40 != 0) {
        p->m18 = lbl_805D7D0C;
        p->m14 = lbl_805D7D10;
    } else if (fn_801A6DB8(m2E4)->m44 != 0) {
        p->m18 = lbl_805D7D0C;
        if (m2E4->m6F4 == 7)
            p->m14 = m2E8;
        else
            p->m14 = lbl_805D7D10;
    } else
        fn_8023A1C8(a);
}

void fn_8023A79C()
{
    fn_802398D4();
}

int fn_8023A7BC()
{
    return 0;
}

int Unk802362A8_Cpu::fn_8023A7C4()
{
    if (m2E4->m6F4 == 3)
        return m2E0->m7C;
    return 1;
}

void fn_8023A7E8(int* p)
{
    *p = 0;
}

void Unk802362A8_Cpu::fn_8023A7F4()
{
    fn_80236FD8(&m4);
    Unk8022FE34_VObj* o = fn_801C1638(m2E4, 0);
    if (o != 0) {
        if (fn_801A2034(m2E4, *(int*)((char*)o + 0x708)) == -1) {
            void* gm = m2E4->m6F8->mC->mC;
            int k = *(int*)((char*)fn_801C1638(m2E4, 0) + 0x708);
            if (fn_80088234(gm, k) > 5)
                m2DC->m38.fn_80230BBC(*(int*)((char*)o + 0x708));
        }
    }
}

struct Unk8023A888_O {
    char pad0[0x14];
    int m14;
    char pad18[8];
    float m20;
    float m24;
    int m28;
};
extern int lbl_8061D150[];
inline float Unk8023A888_Dot(Unk8023A888_O* o, float x, float y)
{
    return o->m20 * x + o->m24 * y;
}
extern int lbl_8061D150[];
inline float Unk8023A888_Dot(Unk8022FE34_Ent* o, float x, float y)
{
    return o->m20 * x + o->m24 * y;
}
extern "C" float fn_8023A888(Unk8022FE34_Ent* o)
{
    float tbl[4] = { 0.0f, 0.2f, 0.3f, 0.4f };
    float a = tbl[o->m28];
    float c = 1.0f - a;
    float b = 0.0f;
    if (o->m14 <= 1) {
        int v = lbl_8061D150[o->m14];
        int t = 0;
        if (v > 5)
            t = v - 5;
        b = (float)t * 0.028571429f;
    }
    float x = (c + (a - a * b)) >? 0.01f;
    float y = a * b;
    return o->m20 * x + o->m24 * y;
}

extern const char lbl_805D7978[];
/* near-miss (99.9%, 2 slots): retail scales the table index in place (slwi r30,r30,2 / lwzx r30,r9,r30), ours
   uses r0 for the scaled index; tried s*=4, s<<=2, char* base + byte offset, separate switch variable */
void Unk802362A8_Cpu::fn_8023A9A0(int* out)
{
    static const int t0[3] = { 0x50, 0, 0x65 };
    static const int t1[3] = { 0x50, 0x57, 0x65 };
    static const int t2[3] = { 0x4B, 0x57, 0x65 };
    static const int t3[3] = { 0x46, 0x55, 0x65 };
    int v = *(int*)((char*)m2E4->m6F8->m14 + 0x1CD0);
    int f = 0;
    if (v != 0)
        f = 1;
    int a = f ^ 1;
    int s = 0;
    if (v != 0)
        s = 1;
    int r = ((Unk8014D8AC*)m2E4->m554)->fn_8014D8AC(100, lbl_805D7978, 0x8DA);
    const int* t = t0;
    int* tb = (int*)(m2E4->m6F8->m10 + 0x14);
    s = tb[s];
    switch (s) {
    case 0:
        break;
    case 1:
        t = t1;
        break;
    case 2:
        t = t2;
        break;
    case 3:
        t = t3;
        break;
    }
    int k = 0;
    for (k = 0; k < 3; k++) {
        if (r < t[k])
            break;
    }
    Unk8022FE34_Ent e;
    m2DC->m38.fn_8023003C(a, k, &e, 1);
    *out = e.m0;
}

inline float Unk8023AAD0_Rand(Unk8014D8AC_Ctx* c, float scale, const char* file, int line)
{
    return (float)(unsigned)((Unk8014D8AC*)c->m554)->fn_8014D8AC(1000000, file, line) * scale * 1e-6f;
}
int Unk802362A8_Cpu::fn_8023AAD0(float* out)
{
    const float one = 0.5f;
    out[0] = Unk8023AAD0_Rand((Unk8014D8AC_Ctx*)m2E4, one, lbl_805D7978, 0x93B) - 0.25f;
    out[0] = !(out[0] > 1.0f) ? (out[0] >? -1.0f) : 1.0f;
    out[1] = Unk8023AAD0_Rand((Unk8014D8AC_Ctx*)m2E4, 0.5f, lbl_805D7978, 0x93E) - 0.25f;
    out[1] = !(out[1] > 1.0f) ? (out[1] >? -1.0f) : 1.0f;
    m0 = 1;
    return 1;
}

int fn_8023BD44()
{
    return lbl_8061D194;
}

int fn_8023BD50()
{
    return 0x1011A855;
}

void fn_8023BD5C()
{
    fn_8023AC54(1, 0xFFFF);
}

enum Unk8023BD88_E { Unk8023BD88_Neg = -1, Unk8023BD88_Hi = 27 };

int Unk8023BE30::fn_8023BD88(int k)
{
    int r = 0;
    switch ((Unk8023BD88_E)k) {
    case 4:
    case 9:
    case 14:
    case 19:
    case 24:
        r = 13;
        break;
    case 0:
    case 27:
        r = 14;
        break;
    }
    return r;
}

int Unk8023BE30::fn_8023BDF0(int k)
{
    if ((unsigned)(k - 12) > 9)
        return 0;
    return k - 9;
}

int Unk8023BE30::fn_8023BE08(int k)
{
    int r = 0;
    switch (k) {
    case 0:
        r = 1;
        break;
    case 1:
        r = 2;
        break;
    }
    return r;
}

int Unk8023BE30::fn_8023BE4C(int a, int b)
{
    int r = 0;
    if (b == 1) {
        if (!v30())
            return 0;
    }
    if (v08()) {
        int x = fn_8023BD88(a);
        r = (unsigned)(x - 1) <= 13;
    }
    return r;
}

int Unk8023BE30::fn_8023BEEC(int a, int b)
{
    int r = 0;
    if (b == 1) {
        if (!v30())
            return 0;
    }
    if (v08()) {
        int x = fn_8023BE08(a);
        r = (unsigned)(x - 1) <= 13;
    }
    return r;
}

int Unk8023BE30::fn_8023BF8C(int a, int b)
{
    int r = 0;
    if (b == 1) {
        if (!v30())
            return 0;
    }
    if (v08()) {
        int x = fn_8023BDF0(a);
        r = (unsigned)(x - 1) <= 13;
    }
    return r;
}

int Unk8023BE30::fn_8023C02C(int a, int b, int c)
{
    int m = fn_8023BE08(a);
    return v28(m, b, c);
}

int Unk8023BE30::fn_8023C084(int a, int b, int c)
{
    int m = fn_8023BDF0(a);
    return v28(m, b, c);
}

int Unk8023BE30::fn_8023C0DC(int a, int b, int c)
{
    int m = fn_8023BD88(a);
    return v28(m, b, c);
}

int fn_8023C134(int k)
{
    int r = 0;
    if (k == 3 || k == 5 || k == 6 || k == 7 || k == 8 || k == 9 || k == 10 || k == 11 || k == 12)
        r = 1;
    return r;
}

int fn_8023C18C(int v)
{
    for (int i = 0; i < 68; i++) {
        if (lbl_805D9E50[i] > v)
            return i > 0 ? i - 1 : 0;
    }
    return 67;
}

int Unk8023BE30::fn_8023C1D8()
{
    return m0;
}

void Unk8023BE30::fn_8023C1E0(int v)
{
    m0 = v;
}

void Unk8023BE30::fn_8023C1E8(int a, int* p, int c, int d)
{
    if (fn_8023BE4C(a, d))
        *p = v10(a, *p, c);
}

void Unk8023BE30::fn_8023C254(int a, int* p, int c, int d)
{
    if (fn_8023BF8C(a, d))
        *p = v18(a, *p, c);
}

void Unk8023BE30::fn_8023C2C0(int a, int* p, int c, int d)
{
    if (fn_8023BEEC(a, d))
        *p = v20(a, *p, c);
}

void Unk8023C32C_Row::fn_8023C32C()
{
    m4 = 0x43;
    m8 = 0x36;
    mC = 0x37;
    m10 = 0x3e;
    m14 = 0x41;
    m18 = 0x41;
    m1C = 0x41;
    m20 = 0x41;
    m24 = 0x4b;
    m28 = 0x46;
    m2C = 0x1e;
    m30 = 0x37;
    m34 = 0x37;
    m38 = 0x37;
}

Unk8023C388::Unk8023C388()
{
    fn_8023C1E0(1);
    m8.fn_8023C32C();
    m44.fn_8023C32C();
}

int Unk8023C4C4::fn_8023C3E0(int a, int b)
{
    char* p = (char*)this + 8;
    int o = a * 4 + b * 0x3c;
    int v = *(int*)(p + o);
    if (v <= 99) {
        if (v < 0)
            v = 0;
    } else
        v = 99;
    return v;
}

static inline int Cl99(int x)
{
    if (x <= 99) {
        if (x < 0)
            x = 0;
    } else
        x = 99;
    return x;
}

/* near-miss: retail clamps into a separate r3 copy (cmpwi r31,99 / mr r3,r31 / cmpwi r3,0) then moves it back to r31;
   tried inline Cl99 forms (4 variants), ours keeps the clamp in r31 */
int Unk8023C4C4::fn_8023C414(int a, int unused, int c)
{
    char* p = (char*)this + 8;
    int o = a * 4 + c * 0x3c;
    int v = Cl99(*(int*)(p + o));
    if (fn_8023C134(a))
        v = fn_8023C18C(v);
    return v;
}

void Unk8023C4C4::fn_8023C490(int a, int b, int d)
{
    char* p = (char*)this + 8;
    int o = a * 4 + b * 0x3c;
    *(int*)(p + o) = d;
}

void fn_8023C4A8(int* p)
{
    for (int i = 0; i < 15; i++)
        p[i] = 0;
}

Unk8023C4C4::Unk8023C4C4()
{
    mC = 0;
    fn_8023C1E0(0);
}

Unk8023C744::Unk8023C744()
{
    fn_8023C1E0(0);
    fn_8023C794();
}

/* near-miss: result accumulator shape. Retail puts li r3,15 out of line after the main path and shares li r3,0 with
   the else-branch clamp; our all-return and result-variable forms (9 variants) put the li before the branch */
struct Unk8023C514_R {
    char pad0[0x14];
    char* m14;
};
struct Unk8023C514_C {
    char pad0[0x6F8];
    Unk8023C514_R* m6F8;
};
struct Unk8023C514_O {
    int m0;
    int m4;
    int m8;
    int mC;
    char* m10;
    char* m14;
    char* m18;
    char* m1C;
};
extern char lbl_8061D228[];
extern char lbl_8061D264[];
int fn_8009E1D4(void* p, int a, int b);
int fn_80084114(int a);
void fn_8023C514(Unk8023C514_O* o, Unk8023C514_C* c)
{
    o->m10 = lbl_8061D228;
    o->m14 = lbl_8061D264;
    o->m18 = lbl_8061D264;
    o->m1C = lbl_8061D264;
    char* r = c->m6F8->m14;
    int a = fn_8009E1D4(r + 0x8C, 0, 0);
    int b = fn_8009E1D4(r + 0xEF0, 0, 0);
    if (a == 10)
        a = 0;
    if (b == 10)
        b = 0;
    int x = fn_80084114(a);
    int y = fn_80084114(b);
    int cx;
    if (x <= 3) {
        if (x >= 0)
            cx = x;
        else
            cx = 0;
    } else
        cx = 3;
    int cy;
    if (y <= 3) {
        if (y >= 0)
            cy = y;
        else
            cy = 0;
    } else
        cy = 3;
    int m = cx;
    if (m > cy)
        m = cy;
    o->mC = m;
    o->m8 = (unsigned)(m - 1) <= 2;
}

int Unk8023C744::fn_8023C620(int i, int d)
{
    int v = ((int*)fn_8023C730())[i];
    if (fn_8023C134(i)) {
        if (d + fn_8023C18C(v) > 15)
            return 15;
        if (d + fn_8023C18C(v) < 0)
            return 0;
        return d + fn_8023C18C(v);
    }
    int t = d + v;
    if (t > 99)
        return 99;
    if (t >= 0)
        return t;
    return 0;
}

int Unk8023C744::fn_8023C6C4(int i)
{
    return ((int*)fn_8023C730())[i];
}

void Unk8023C744::fn_8023C6F8(int i, int v)
{
    ((int*)fn_8023C730())[i] = v;
}

int Unk8023C744::fn_8023C730()
{
    return m10[mC];
}

void Unk8023C744::fn_8023C794()
{
    fn_8023C4A8(m10);
}

/* near-miss: same as fn_8023C620 */
int Unk8023C744::fn_8023C7B8(int i, int d)
{
    int v = m10[i];
    if (fn_8023C134(i)) {
        if (d + fn_8023C18C(v) > 15)
            return 15;
        if (d + fn_8023C18C(v) < 0)
            return 0;
        return d + fn_8023C18C(v);
    }
    int t = d + v;
    if (t > 99)
        return 99;
    if (t >= 0)
        return t;
    return 0;
}

extern "C" void fn_8023C858(Unk8023C744* p, int i, int v)
{
    p->m10[i] = v;
}

int* fn_8023CAF0()
{
    return &lbl_8068CCDC;
}

int* fn_8023CAFC()
{
    return &lbl_8068CCE0;
}

int* fn_8023CB08()
{
    return &lbl_8068CCE4;
}

int* fn_8023CB14()
{
    return &lbl_8068CCE8;
}

int* fn_8023CB20()
{
    return &lbl_8068CCEC;
}

int* fn_8023CB2C()
{
    return &lbl_8068CCF4;
}

int* fn_8023CB38()
{
    return &lbl_8068CCF8;
}

int* fn_8023CB44()
{
    return &lbl_8068CCFC;
}

void fn_8023CD70(void* p);

class Unk8023DB44_Q {
public:
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

struct Unk8023D9C4_N {
    Unk8023D9C4_N* m0;
    Unk8023D9C4_N* m4;
    char pad8[4];
    int mC;
};
extern char* lbl_8061D378;
extern Unk8023D9C4_N* lbl_8061D37C;
extern "C" void* fn_803774A8(unsigned int size, int heap);
inline void* operator new(unsigned int, void* p) { return p; }

void fn_8023D9C4()
{
    char** q = &lbl_8061D378;
    if (lbl_8061D378 == 0) {
        char* arr = (char*)fn_803774A8(0x102C8, 0) + 8;
        *(int*)(arr - 8) = 0x50;
        int k = 0x4F;
        char* e = arr;
        do {
            new (e) Unk8027C654;
            e += 0x33C;
        } while (k-- != 0);
        *q = arr;
        ((Unk8023D9C4_N*)lbl_8061D378)->m4 = 0;
        int off = 0;
        int i = 0x4F;
        char* base;
        do {
            base = lbl_8061D378;
            Unk8023D9C4_N* g = (Unk8023D9C4_N*)(off + (int)base);
            Unk8023D9C4_N* nx = (Unk8023D9C4_N*)((char*)g + 0x33C);
            *(Unk8023D9C4_N**)(off + (int)base) = nx;
            nx->m4 = g;
            off += 0x33C;
            g->mC = 0;
        } while (--i != 0);
        *(Unk8023D9C4_N**)(base + 0xFF84) = 0;
        lbl_8061D37C = (Unk8023D9C4_N*)base;
    }
}

struct Unk8023DA90_O {
    int m0;
    char pad4[0x8C - 4];
    float m8C;
    float m90;
    float m94;
    char pad98[0x390 - 0x98];
    unsigned m390;
    char pad394[0xAB4 - 0x394];
    float mAB4;
};
extern float lbl_8061D5F8;
inline void Unk8023DA90_Set(Unk8023DA90_O* d, float a, float b, float c)
{
    d->m8C = a;
    d->m90 = b;
    d->m94 = c;
}
void fn_8023DA90(Unk8023DA90_O* o, float f)
{
    o->m390 = (int)f;
    fn_8023CAFC();
    o->m0 = 0;
    o->mAB4 = (float)o->m390 / (lbl_8061D5F8 * 12.0f);
    Unk8023DA90_Set(o, o->mAB4, o->mAB4, o->mAB4);
}

void fn_8023DB44(void* p)
{
    fn_8023CD70(p);
    ((Unk8023DB44_Q*)((char*)p + 0xA0))->v13();
}
