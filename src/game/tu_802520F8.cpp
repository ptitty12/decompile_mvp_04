/*
 * Game code, .text 0x802520F8-0x802547C0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_W W;
typedef Unk8024EF40_Q Q;

extern "C++" {
int fn_80250AC4(P* x);
int fn_80250A90(P* x, int k);
float fn_80251000(P* x, int k);
void* fn_8023CB44(P* x);
void fn_80250B28(P* x, int k);
int fn_80097620(Unk8024EF40_Ent* e, int x0, int x1, int x2);
int fn_8009764C(Unk8024EF40_Ent* e, int x0, int x1, int x2);
float fn_80097678(Unk8024EF40_Ent* e, int x0, int x1, int x2);
int fn_80097A9C(Unk8024EF40_Ent* e, int x0, int x1, int x2, int x3);
float fn_80097B60(Unk8024EF40_Ent* e, int x0, int x1, int x2, int x3);
int fn_80097EA4(Unk8024EF40_Ent* e, int x0, int x1, int x2, int x3);
float fn_80097F68(Unk8024EF40_Ent* e, int x0, int x1, int x2, int x3);
int fn_800983C8(Unk8024EF40_Ent* e, int x0, int x1);
int fn_8009841C(Unk8024EF40_Ent* e, int x0, int x1);
float fn_80098470(Unk8024EF40_Ent* e, int x0, int x1);
int fn_8009896C(Unk8024EF40_Ent* e, int x0, int x1, int x2);
int fn_800989C8(Unk8024EF40_Ent* e, int x0, int x1, int x2);
int fn_80098C68(Unk8024EF40_Ent* e, int x0, int x1, int x2);
float fn_80098CC4(Unk8024EF40_Ent* e, int x0, int x1, int x2);
extern char lbl_8068CC18[];
extern char lbl_8068CCA8[];
int fn_8008CFD8(char* p, int a, unsigned char b);
void fn_8023C254(void* tbl, int a, int* out, int idx, int z);
int fn_80099570(Unk8024EF40_Ent* e, int a, int b, int c);
void fn_8023C2C0(void* tbl, int a, int* out, int idx, int z);
void fn_8008D738(void* p, int a, int b, int c);
float fn_8008D7B8(void* p, int a, int b);
int fn_80089AA0(char* e, int a, int v);
void fn_8023C1E8(void* tbl, int a, int* out, int idx, int z);
float fn_80089E48(void* p, int a, int b);
float fn_800718F0(void* w, int a, int val);
extern char lbl_805D990C[];
extern int lbl_8061DC54;
extern float lbl_8061DC44;
extern int lbl_80691CDC;

inline float G_8061DC44(void* p) { return lbl_8061DC44; }

extern float lbl_8061DC48;
extern int lbl_80691D14;
inline float G_8061DC48(void* p) { return lbl_8061DC48; }

struct Unk802531FC_C {
    int m0;
    P* m4;
    int m8;
    float mC;
    float m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    unsigned f0 : 1;
    unsigned f1 : 1;
    unsigned f2 : 1;
    unsigned f3 : 29;
    int m48;
    int m4C;
    P* m50;
};
typedef Unk802531FC_C C;
extern char lbl_80661010[];
extern char lbl_80660FF8[];
extern char lbl_80660FE0[];
extern char lbl_80660FC8[];
/* Event message built on the stack: vptr at +4 (base lbl_80649DA0, derived per message), id at +0. */
struct Unk80253888_Msg {
    int m0;
    const void* vptr;
    float m8;
    int mC;
    int m10;
    int m14;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
    }
    void Derived1()
    {
        vptr = lbl_80661010;
        m8 = -1.0f;
        mC = -1;
    }
    void Derived2()
    {
        vptr = lbl_80660FF8;
        m8 = -1.0f;
        mC = -1;
        m10 = -1;
    }
    void Derived3()
    {
        vptr = lbl_80660FE0;
        m8 = -1.0f;
        mC = -1;
        m14 = -1;
        m10 = -1;
    }
    void Derived4()
    {
        vptr = lbl_80660FC8;
        m8 = -1.0f;
        mC = -1;
        m10 = -1;
    }
    void Fill1(P* p)
    {
        float t = Secs(p->m44C);
        m8 = t;
        mC = p->m460;
    }
    void Fill2(P* p, P* a)
    {
        float t = Secs(p->m44C);
        m8 = t;
        mC = p->m460;
        m10 = a->m460;
    }
    void Fill3(P* p, P* a, P* b)
    {
        float t = Secs(p->m44C);
        m8 = t;
        mC = p->m460;
        m10 = a->m460;
        m14 = b->m460;
    }
    void Dtor() { vptr = lbl_80649DA0; }
};
struct Unk80253888_Msg1 {
    int m0;
    const void* vptr;
    float m8;
    int mC;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
    }
    void Derived1()
    {
        vptr = lbl_80661010;
        m8 = -1.0f;
        mC = -1;
    }
    void Fill1(P* p)
    {
        float t = Secs(p->m44C);
        m8 = t;
        mC = p->m460;
    }
    void Dtor() { vptr = lbl_80649DA0; }
};
struct Unk80253678_V : Unk80256A90_Data {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual int v22();
};
void fn_80252EB8(C* self, float v);
extern const float lbl_805D9C20;
extern const float lbl_805D9C24;
extern const float lbl_805D9C28;

float fn_80253434(C* self);
extern "C" float fn_8025356C(void* p);
extern const float lbl_805D9B94;
extern const float lbl_805D9BA4;
extern const float lbl_805D9BA8;
extern const float lbl_805D9BAC;
extern char lbl_805D9B60[];

struct Unk80253C74_Rec {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
struct Unk80253C74_Tbl {
    Unk80253C74_Rec r[5];
};
extern Unk80253C74_Tbl lbl_805D9C7C;
extern const float lbl_805D9C10;
extern const float lbl_805D9C14;
extern const int lbl_805D9E94[5];

class Unk8023BE30 {
public:
    int fn_8023C0DC(int a, int b, int c);
};
struct Unk80089894_PackTabD;
void fn_80089EE0(Unk80089894_PackTabD* self, unsigned t, unsigned i, int v);
int fn_802530E8(C* self);
void fn_80252C1C(C* self);
extern float lbl_805D9BB4;
extern float lbl_805D9BB8;
struct Unk80253678_S {
    int m0;
    Unk80253678_V* m4;
};
struct Unk802537E0_E {
    char pad0[0x18];
    int m18;
    char pad1C[8];
    int m24;
    char pad28[0x5C - 0x28];
    float m5C;
    char pad60[8];
    float m68;
};
void fn_8037893C(void* q, int id, void* o, int a, int b);
int fn_80097318(Unk8024EF40_Ent* e, int a);
int fn_800973E8(Unk8024EF40_Ent* e, int a);
int fn_80097380(Unk8024EF40_Ent* e, int a);
int fn_80097450(Unk8024EF40_Ent* e, int a);
int fn_800974B8(Unk8024EF40_Ent* e, int a);
int fn_801A2034(Q* q, int pos);
int* fn_801A6DB8(Q* q);
void fn_8025283C(C* self);
void fn_80252964(C* self);
void fn_802529F0(C* self);
void fn_802526D4(C* self);
int fn_80254374(W* self, int a);
float fn_8025454C(W* self, int a);
void fn_8024DB54();
extern "C" void* fn_8018112C(int i);
int fn_802536D0(P* self);
void fn_800B555C();
int fn_800B57EC();
Unk8024EF40_Ref* fn_801C0478(A* a);
extern float lbl_805D9CF4;
extern float lbl_805D9CF8;
int fn_8025374C(P* self);
float fn_80254618(W* self, int a);
int fn_80253100(C* self, int a);
}

/* near-miss: 71 vs 71 instructions, ~40 slots differ in register choice. Retail sums with `addi r11,ea,0x1B4` inside the bdnz loop and lbzx on the masked index;
   ours folds the 0x1B4 into the lbz displacement. unsigned char counter gives andi./no bdnz. Tried int counter with unsigned char k, separate k++, int-cast address forms */

inline float RandUnit_2A94(Unk8024EF40_Q* q, const char* f, int line)
{
    float k = lbl_805D9B94;
    return (float)fn_8014D8AC(q->m554, 1000000, f, line) * k * 0.000001f;
}

inline float Lerp_2A94(float a, float t, float b)
{
    return a + t * (b - a);
}

inline float Clamp01_356C(float x)
{
    return !(x > lbl_805D9C24) ? (x >? lbl_805D9C20) : lbl_805D9C24;
}

inline float Clamp01_3434(float x)
{
    return !(x > lbl_805D9C14) ? (x >? lbl_805D9C10) : lbl_805D9C14;
}

void fn_80252460(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 0xC) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x62E);
        float t = fn_80251000(x, 0x2B) * G_8061DC44(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CDC != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 0xC);
    }
}

void fn_80252588(P* x, int k)
{
    if ((k == 5 || k == 7 || k == 6 || k == 8) && fn_80250AC4(x) != 0 && fn_80250A90(x, 0x1A) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x648);
        float t = fn_80251000(x, 0x2B) * G_8061DC48(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691D14 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 0x1A);
    }
}

void fn_802526D4(C* self)
{
}

void fn_802526D8(C* self)
{
    self->m0 = 2;
    fn_802526D4(self);
    fn_802529F0(self);
    self->m8 = fn_80254374(&self->m4->m588, 0x1A);
    self->mC = (float)fn_80254374(&self->m4->m588, 4);
    self->m10 = (float)fn_80254374(&self->m4->m588, 9);
    self->m14 = (float)fn_80254374(&self->m4->m588, 0xE);
    self->m18 = (float)fn_80254374(&self->m4->m588, 0x13);
    self->m1C = (float)fn_80254374(&self->m4->m588, 0x18);
    self->m20 = fn_80254618(&self->m4->m588, 1);
    fn_8025283C(self);
    fn_80252964(self);
}

void fn_8025283C(C* self)
{
    float a = (float)fn_80254374(&self->m4->m588, 0);
    float b = (float)fn_80254374(&self->m4->m588, 0x1B);
    if (!(b <= a)) {
        int c = ((Unk8023BE30*)lbl_8068CCA8)->fn_8023C0DC(0x1B, 0, 0);
        P* p = self->m4;
        fn_80089EE0((Unk80089894_PackTabD*)((char*)EntOf(p) + 0xC74), 0x1B, p->m70C, (int)((b - (float)c) + 0.5f));
    }
}

void fn_80252964(C* self)
{
    float v = (float)fn_80254374(&self->m4->m588, 0);
    self->m28 = !(v <= 0.0f) ? self->m24 / v : 0.0f;
}

void fn_802529F0(C* self)
{
    if (self->m4->m44C->m6F8->m10 != 0) {
        fn_8025283C(self);
        fn_800B555C();
        if (fn_800B57EC() != 0)
            self->m24 = (float)fn_80254374(&self->m4->m588, 0x1B);
        else
            self->m24 = (float)fn_80254374(&self->m4->m588, 0);
    }
    fn_80252964(self);
}

void fn_80252A90()
{
}

/* near-miss: 97 vs 98 instructions; retail loads the two float constants (1.0, 0.3) once into f30/f31 and reuses them across the calls, ours reloads lbl_805D9B94 after the second call. Tried const float locals and a k parameter */
void fn_80252A94(C* self, int a)
{
    self->f0 = a;
    fn_80252A90();
    fn_80252C1C(self);
    Unk8024EF40_Q* q = self->m4->m44C;
    if (q->m6F4 != 8) {
        float roll = RandUnit_2A94(q, lbl_805D9B60, 0xC4);
        float lo = Lerp_2A94(lbl_805D9BA4, fn_8025356C((char*)self->m4 + 0x480), lbl_805D9BA8);
        float hi = Lerp_2A94(lbl_805D9BAC, fn_8025356C((char*)self->m4 + 0x480), lbl_805D9BA4);
        self->m0 = 1;
        if (a != 0) {
            if (!(roll >= lo))
                self->m0 = 0;
            else if (!(roll <= lbl_805D9B94 - hi))
                self->m0 = 2;
        }
    }
}

void fn_80252C1C(C* self)
{
    self->m40 = 0;
    if (fn_802530E8(self) != 0) {
        P* p = self->m4;
        int idx = p->m708;
        Unk8024EF40_Sub6F8* s6 = p->m44C->m6F8;
        if (idx > 2) {
            int f = 0;
            if (*(int*)((char*)s6->m14 + 0x1CD0) != 0)
                f = 1;
            idx = idx == 3 ? f : f ^ 1;
        }
        Unk8024EF40_Ent* ea = s6->m14 + idx;
        int a = 0;
        for (int i = 0; i < 128; i++)
            a += ((unsigned char*)((char*)ea + 0x1B4))[(unsigned char)i];
        self->m40 = a;
        int o;
        if (idx > 2)
            o = idx == 3 ? 4 : 3;
        else
            o = idx == 0;
        Unk8024EF40_Ent* eb = s6->m14 + o;
        int b = 0;
        for (int i = 0; i < 128; i++)
            b += ((unsigned char*)((char*)eb + 0x1B4))[(unsigned char)i];
        self->m40 = self->m40 - b;
    }
}

void fn_80252D38(C* self)
{
    self->m8 = 0;
    self->m28 = 0.0f;
    self->m24 = 0.0f;
    self->f2 = 0;
    self->f0 = 0;
    self->m3C = -1;
    self->mC = 0.0f;
    self->m20 = 0.0f;
    self->m1C = 0.0f;
    self->m18 = 0.0f;
    self->m14 = 0.0f;
    self->m10 = 0.0f;
    self->m2C = 0.0f;
    self->m30 = 0;
    self->m34 = 0;
    self->m40 = 0;
    self->f1 = 0;
    self->m38 = 0;
    self->m50 = 0;
    self->m48 = fn_80253100(self, 0xF);
    self->m4C = fn_80253100(self, 0xFF);
}

void fn_80252DD8(C* self, P* p)
{
    if (p != 0)
        self->m50 = (P*)p->m704;
    else
        self->m50 = p;
}

inline float Clamp2DF4(float x)
{
    return !(x > lbl_805D9BB4) ? (x >? lbl_805D9BB8) : lbl_805D9BB4;
}

extern "C" void fn_80252DF4(char* p, float v)
{
    C* self = (C*)p;
    v = Clamp2DF4(v);
    float n = (float)fn_80254374(&self->m4->m588, 0);
    float m = n * v;
    self->m24 = m;
    fn_80252EB8(self, lbl_805D9BB8);
}

void fn_8025309C(C* self, float v)
{
    self->m2C = v;
    self->f1 = 1;
    ((void (*)(P*, const char*, int))fn_8024DB54)(self->m4, "Mound Visit Boost:", 0x20);
}

int fn_802530E8(C* self)
{
    return self->m4C != 0xFF;
}

int fn_80253100(C* self, int a)
{
    P* p = self->m4;
    int t = p->m708;
    int n;
    if (t == 2 || (n = p->m704) == 0 || p->m44C->m6F4 != 0)
        return 15;
    Unk8024EF40_Ent* e = p->m44C->m6F8->m14 + t;
    int r = a;
    if (fn_80097318(e, n) != 0)
        r = 15;
    else if (fn_800973E8(e, n) != 0)
        r = 16;
    else if (fn_80097380(e, n) != 0)
        r = 17;
    else if (fn_80097450(e, n) != 0)
        r = 18;
    else if (fn_800974B8(e, n) != 0)
        r = 19;
    return r;
}

/* near-miss: one register (li r10 vs r11) differs; store order and byte-load spellings tried */
void fn_802531FC(C* self)
{
    self->m3C = *((unsigned char*)self->m4->m44C->m6F8->m14 + 0x1CC8);
    self->m38 = 0;
}

void fn_80253220(C* self)
{
    self->m38 = self->m38 + 1;
    if (self->f1)
        self->f1 = 0;
}

/* near-miss: same 78 instructions, register choice differs (retail n in r10 with m38/m30 loaded into r9/r10; ours r0/r11). Tried operand order, temps, table pointer */
float fn_80253434(C* self)
{
    if (fn_802530E8(self) == 0)
        return lbl_805D9C10;
    int n = self->m30 + self->m38 * 5;
    if (n < 0)
        n = 0;
    unsigned idx = 0;
    unsigned t = self->m48 - 0xF;
    if (t <= 4)
        idx = t;
    int lim = lbl_805D9E94[idx];
    if (*(int*)((char*)self->m4 + 0x4C4) < 0 || self->f2 || n >= lim)
        return lbl_805D9C14;
    float x = (float)n / (float)lim;
    return Clamp01_3434(x);
}

extern "C" float fn_8025356C(void* p)
{
    C* self = (C*)p;
    if (fn_802530E8(self) == 0)
        return lbl_805D9C20;
    float a = self->m28 + self->m2C;
    float b = fn_80253434(self);
    b = Clamp01_356C(b);
    if (!(b >= lbl_805D9C24)) {
        float t = (lbl_805D9C24 - b) * lbl_805D9C28;
        a = a - t;
    }
    a = Clamp01_356C(a);
    return a;
}

int fn_80253678(Unk80253678_S* self)
{
    Unk80253678_V* o = self->m4;
    if (o == 0)
        return 1;
    return o->v22() != 1;
}

int fn_802536D0(P* self)
{
    if (self->m44C->m6F4 == 1)
        return 1;
    if (fn_801A2034(self->m44C, self->m708) == -1)
        return *fn_801A6DB8(self->m44C);
    return Pick(self->m44C->m6F8->m10, self->m708);
}

int fn_8025374C(P* self)
{
    if (self->m44C->m6F4 == 1)
        return 1;
    if (fn_801A2034(self->m44C, self->m708) != -1)
        return fn_802536D0(self);
    int k = self->m708;
    if (k == 0)
        k = 1;
    else if (k == 1)
        k = 0;
    return Pick(self->m44C->m6F8->m10, k);
}

/* near-miss: 2 slots (retail has `cmpwi r0,0` before `li r3,4`; ours schedules the li first). Tried ternary, if/else, inline selector, == 0 forms */
float fn_802537E0(P* self)
{
    int k = fn_802536D0(self);
    int idx = ((Unk802537E0_E*)fn_8018112C(k))->m18 ? k : 4;
    float t = ((Unk802537E0_E*)fn_8018112C(idx))->m5C;
    return t;
}

/* near-miss: 2 slots, same as fn_802537E0 */
float fn_80253834(P* self)
{
    int k = fn_8025374C(self);
    int idx = ((Unk802537E0_E*)fn_8018112C(k))->m24 ? k : 4;
    float t = ((Unk802537E0_E*)fn_8018112C(idx))->m68;
    return t;
}

void fn_80253888(W* w)
{
    Unk80253888_Msg1 m;
    m.Base(0x82);
    m.Derived1();
    m.Fill1(w->m0);
    fn_8037893C(w->m0->m44C->m704, m.m0, &m, 0, 0);
    m.Dtor();
}

extern "C" void fn_80253950(void* o, void* a0)
{
    W* w = (W*)o;
    P* a = (P*)a0;
    Unk80253888_Msg m;
    m.Base(0x83);
    m.Derived2();
    m.Fill2(w->m0, a);
    fn_8037893C(w->m0->m44C->m704, m.m0, &m, 0, 0);
    fn_80253888(w);
    m.Dtor();
}

extern "C" void fn_80253A30(void* o, void* a0, void* b0)
{
    W* w = (W*)o;
    P* a = (P*)a0;
    P* b = (P*)b0;
    Unk80253888_Msg m;
    m.Base(0x85);
    m.Derived3();
    m.Fill3(w->m0, a, b);
    fn_8037893C(w->m0->m44C->m704, m.m0, &m, 0, 0);
    fn_80253888(w);
    m.Dtor();
}

void fn_80253B1C(W* w, P* a)
{
    Unk80253888_Msg m;
    m.Base(0x84);
    m.Derived4();
    m.Fill2(w->m0, a);
    fn_8037893C(w->m0->m44C->m704, m.m0, &m, 0, 0);
    fn_80253888(w);
    m.Dtor();
}

void fn_80253BFC(W* self)
{
    fn_8037893C(self->m0->m44C->m704, 0x53, 0, 0, 0);
}

void fn_80253C38(W* self)
{
    fn_8037893C(self->m0->m44C->m704, 0x54, 0, 0, 0);
}

int fn_80253C74(W* w, int* sel, int* key, Unk80253C74_Rec* out)
{
    Unk80253C74_Tbl tbl = lbl_805D9C7C;
    int found = 0;
    if (sel != 0) {
        found = 1;
        *out = tbl.r[*sel];
    } else if (key != 0) {
        for (int i = 0; i <= 4; i++) {
            int v;
            if (i == 0)
                v = 15;
            else
                v = fn_80254374(w, tbl.r[i].m0);
            if (v == *key) {
                found = 1;
                *out = tbl.r[i];
                break;
            }
        }
    }
    return found;
}

int fn_80253DB0(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_80097620(EntOf(p), a, p->m70C, b);
}

int fn_80253DF4(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_8009764C(EntOf(p), a, p->m70C, b);
}

float fn_80253E38(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_80097678(EntOf(p), a, p->m70C, b);
}

int fn_80253E7C(Unk8024EF40_W* self, int a, int b, int c)
{
    P* p = self->m0;
    return fn_80097A9C(EntOf(p), a, p->m70C, b, c);
}

float fn_80253EC4(Unk8024EF40_W* self, int a, int b, int c)
{
    P* p = self->m0;
    return fn_80097B60(EntOf(p), a, p->m70C, b, c);
}

int fn_80253F0C(Unk8024EF40_W* self, int a, int b, int c)
{
    P* p = self->m0;
    return fn_80097EA4(EntOf(p), a, p->m70C, b, c);
}

float fn_80253F54(Unk8024EF40_W* self, int a, int b, int c)
{
    P* p = self->m0;
    return fn_80097F68(EntOf(p), a, p->m70C, b, c);
}

int fn_80253F9C(Unk8024EF40_W* self, int a)
{
    P* p = self->m0;
    return fn_800983C8(EntOf(p), a, p->m70C);
}

int fn_80253FDC(Unk8024EF40_W* self, int a)
{
    P* p = self->m0;
    return fn_8009841C(EntOf(p), a, p->m70C);
}

float fn_8025401C(Unk8024EF40_W* self, int a)
{
    P* p = self->m0;
    return fn_80098470(EntOf(p), a, p->m70C);
}

int fn_8025405C(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_8009896C(EntOf(p), a, p->m70C, b);
}

int fn_802540A0(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_800989C8(EntOf(p), a, p->m70C, b);
}

int fn_802540E4(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_80098C68(EntOf(p), a, p->m70C, b);
}

float fn_80254128(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_80098CC4(EntOf(p), a, p->m70C, b);
}

int fn_8025416C(W* self, int a)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    r = fn_8008CFD8((char*)e + 0xC9C, a, p->m70C);
    fn_8023C254(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C254(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C254((char*)e + 0x118, a, &r, self->m0->m708, 0);
    return r;
}

int fn_80254228(W* self, int a, int b)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    r = fn_80099570(e, a, p->m70C, b);
    fn_8023C2C0(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C2C0(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C2C0((char*)e + 0x118, a, &r, self->m0->m708, 0);
    return r;
}

void fn_802542E8(W* self, int a, int b)
{
    P* p = self->m0;
    fn_8008D738((char*)EntOf(p) + 0xC9C, a, p->m70C, b);
}

float fn_80254330(W* self, int a)
{
    P* p = self->m0;
    return fn_8008D7B8((char*)EntOf(p) + 0xC9C, a, p->m70C);
}

int fn_80254374(W* self, int a)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    r = fn_80089AA0((char*)e + 0xC74, a, p->m70C);
    fn_8023C1E8(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C1E8(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C1E8((char*)e + 0x118, a, &r, self->m0->m708, 0);
    return r;
}

float fn_80254430(W* self, int a)
{
    P* p = self->m0;
    return fn_80089E48((char*)EntOf(p) + 0xC74, a, p->m70C);
}

float fn_80254474(W* self, int a, int b)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    r = fn_80099570(e, a, p->m70C, b);
    fn_8023C2C0(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C2C0(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C2C0((char*)e + 0x118, a, &r, self->m0->m708, 0);
    int o = b * 4;
    char* bb = (char*)e + 0xCC4;
    return fn_800718F0(*(void**)(bb + o), a, r);
}

float fn_8025454C(W* self, int a)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    char* q = (char*)e + 0xC9C;
    r = fn_8008CFD8(q, a, p->m70C);
    fn_8023C254(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C254(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C254((char*)e + 0x118, a, &r, self->m0->m708, 0);
    return fn_800718F0(q, a, r);
}

float fn_80254618(W* self, int a)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    char* q = (char*)e + 0xC74;
    r = fn_80089AA0(q, a, p->m70C);
    fn_8023C1E8(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C1E8(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C1E8((char*)e + 0x118, a, &r, self->m0->m708, 0);
    return fn_800718F0(q, a, r);
}

void fn_802546E4(A* self)
{
    self->b0 = 0;
    self->b1 = 0;
    self->b2 = 0;
    self->b3 = 0;
    self->m14 = lbl_805D9CF4;
    self->mC = lbl_805D9CF4;
    self->m8 = lbl_805D9CF4;
    self->m48 = lbl_805D9CF4;
    self->m1C = -1;
    self->m20 = 0;
    self->m10 = -1;
    self->m24 = 0;
    self->m18 = lbl_805D9CF4;
    self->m3C = -1;
    self->m38 = -1;
    self->m34 = -1;
    self->m30 = -1;
    self->m2C = -1;
    self->m28 = 0x1A;
    self->m40 = -1;
    self->m44 = 0;
    self->m4C = lbl_805D9CF8;
    self->m50 = fn_801C0478(self);
}

void fn_80254784(A* self)
{
    self->m4C = fn_8025454C(&self->m0->m588, 0xD);
}
