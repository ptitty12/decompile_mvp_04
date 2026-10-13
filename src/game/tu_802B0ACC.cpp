/*
 * Game code, .text 0x802B0ACC-0x802B5234 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802ACD88.h"

typedef Unk802ACD88_Mgr Mgr;
typedef Unk802B0ACC_T T;
typedef Unk802B0ACC_Rec Rec;
typedef Unk802B0ACC_V4 V4;
typedef Unk802B0ACC_F4 F4;

struct Unk802B1F00_B {
    char pad0[0x1F00];
    unsigned int a1F00[30];
};

struct Unk802B0DB0_M {
    char pad0[0x11E10];
    void* a11E10[30];
    void* a11E88[30];
    unsigned int a11F00[30];
};


void* operator new(unsigned int size, int heap);
void* operator new[](unsigned int size, int heap);

extern int lbl_8061E970;
extern char lbl_80664140[];
extern const char lbl_805E0190[];
extern const char lbl_805E019C[];
extern const char lbl_805E01A8[];
extern const char lbl_805E01B4[];
extern const char lbl_805E01B8[];
extern const char lbl_805E01C4[];
extern const char lbl_805E01D0[];
extern const char lbl_805E01DC[];
extern const char lbl_805E01E8[];
extern const char lbl_805E01F4[];
extern const char lbl_805E01FC[];
extern int* lbl_8061977C;
extern const char* lbl_8061E97C[];
extern const char lbl_805E0160[];
extern const char lbl_805E0164[];
extern const char lbl_805E0168[];
extern const char lbl_805E016C[];
extern const char lbl_805E0170[];
extern const char lbl_805E0280[];
extern const char lbl_805E028C[];
extern const char lbl_805E029C[];
extern const char lbl_805E02A8[];
extern const char lbl_805E02B4[];
extern const char lbl_805E02C0[];

extern "C++" {
int fn_80377F00(void* t, int* a, int* b, int key, int c);
void fn_803EB330(void* p);
char* fn_8040B8FC(const char* s, int c);
char* fn_8040B61C(char* d, const char* s);
char* fn_8040B448(char* d, const char* s);
unsigned int fn_80378568(const char* s, int n);
int fn_8040B574(const char* a, const char* b);
void fn_802B1D44(T* t);
void* fn_802B98AC(const char* name, int a);
int fn_800057D8();
int fn_800057E4();
void* fn_803EB2EC(void* p);
void* fn_802B23F0(void* p, void* a);
int fn_80075E7C(int a);
int fn_8040ABA0();
void fn_80328234(void* p, int a, int b);
int fn_8040B6A0(const char* s);
void fn_802B1E38(T* t, const char* s, int v);
void fn_802B1FC0(T* t);
void* fn_8040B320(void* p, int v, int n);
void fn_802B2268(void* self, void* a, void* b);
void fn_803DD73C(void* a, int b);
}

/* near-miss (parked, 58 vs 59 insns): retail joins the default and found paths before one 16-byte copy whose first word is loaded in each path */
V4 fn_802B0ACC(Mgr* m, int key)
{
    int a = -1;
    int b = -1;
    F4 d;
    V4* src;
    char* t = (char*)m + 0x10000 - 0x580;
    if (fn_80377F00(t, &a, &b, key, 0) == 0) {
        b = -1;
        a = -1;
        if (fn_80377F00(t, &a, &b, lbl_8061E970, 0) == 0) {
            d.a = 0.0f;
            d.d = 0.0f;
            d.c = 0.0f;
            d.b = 0.0f;
            src = (V4*)&d;
        } else {
            src = (V4*)((char*)m + 0x4038 + a * 0x1C);
        }
    } else {
        src = (V4*)((char*)m + 0x4038 + a * 0x1C);
    }
    return *src;
}

void fn_802B0BB8(Mgr* m, int key, V4* val)
{
    int a = -1;
    int b = -1;
    if (fn_80377F00((char*)m + 0xFA80, &a, &b, key, 0) != 0)
        *(V4*)((char*)m + 0x4038 + a * 0x1C) = *val;
}

/* near-miss (parked, 88 vs 86 insns): retail keeps m+0x10000 in r29 and re-forms each table address (+0x1E10 / +0x1E88) per use; the local buffer is ~100 bytes */
void fn_802B0C44(Mgr* m, int t)
{
    Unk802B0DB0_M* mm = (Unk802B0DB0_M*)m;
    if (mm->a11E10[t] == 0) {
        const char* suf = 0;
        switch (*lbl_8061977C) {
        case 0:
        case 1:
            suf = lbl_805E0160;
            break;
        case 2:
            suf = lbl_805E0164;
            break;
        case 3:
        case 4:
            suf = lbl_805E0168;
            break;
        case 5:
            suf = lbl_805E016C;
            break;
        }
        char buf[0x400];
        fn_8040B61C(buf, lbl_8061E97C[t]);
        fn_8040B448(buf, suf);
        fn_8040B448(buf, lbl_805E0170);
        if (t == 0x16)
            mm->a11E10[0x16] = (void*)fn_800057D8();
        else
            mm->a11E10[t] = fn_802B98AC(buf, 0x400);
    }
    if (mm->a11E88[t] == 0) {
        if (t == 0x16)
            mm->a11E88[0x16] = (void*)fn_800057E4();
        else
            mm->a11E88[t] = fn_803EB2EC(mm->a11E10[t]);
        float f = 0.0f;
        *(float*)((char*)mm->a11E88[t] + 0x28) = f;
    }
}

struct Unk802B3130_In {
    char pad0[0x9C];
    int m9C;
};

struct Unk802B3130_Out {
    char pad0[0xC];
    int* mC;
};

struct Unk802B2518_W {
    char pad0[8];
    int m8;
    char padC[0x240 - 0xC];
    void* m240;
};

/* Heap object at lbl_8061EA74 (fn_802B23F0 builds it): vptr at +0x18, handle at +0x24. */
struct Unk802B2BD0_B {
    char pad0[0x18];
};
struct Unk802B2BD0_V : Unk802B2BD0_B {
    virtual ~Unk802B2BD0_V();
};
struct Unk802B2BD0_D : Unk802B2BD0_V {
    char pad1C[8];
    void* m24;
};

struct Unk802B2518_S {
    char pad0[0x18];
    const void* m18;
    char pad1C[0x24 - 0x1C];
    int m24;
    int m28;
    int m2C;
    int e30[1];
    char pad34[0x430 - 0x34];
    float f430[1];
    char pad434[0xC30 - 0x434];
    int mC30;
    char padC34[0x1834 - 0xC34];
    float f1834[1];
    char pad1838[0x1C34 - 0x1838];
    float m1C34;
    char pad1C38[4];
    int m1C3C;
    float m1C40;
    float m1C44;
    int m1C48;
};

extern Unk802B2518_W* lbl_8061E978;

extern T* lbl_8061EA68;
extern void* lbl_8061EA74;
extern const float lbl_805E02DC;

void fn_802B0D9C(Mgr* m)
{
    *(int*)((char*)m + 0x11E68) = 0;
    *(int*)((char*)m + 0x11EE0) = 0;
}

void fn_802B0DB0(Mgr* m)
{
    Unk802B0DB0_M* mm = (Unk802B0DB0_M*)m;
    for (int i = 0; i <= 29; i++) {
        if (i != 22) {
            if (mm->a11E88[i] != 0)
                fn_803EB330(mm->a11E88[i]);
            if (mm->a11E10[i] != 0) {
                delete mm->a11E10[i];
                mm->a11E10[i] = 0;
            }
            mm->a11E88[i] = 0;
        }
    }
}

/* near-miss: retail folds the first table compare into lwz 0x1F00(r8) and re-forms the base inside the loop; here the base is hoisted */
int fn_802B0E34(Mgr* m, const char* s)
{
    char buf[0x20];
    char* p = fn_8040B8FC(s, 0x5F);
    if (p != 0) {
        fn_8040B61C(buf, s);
        buf[p - s] = 0;
    }
    unsigned int h = fn_80378568(buf, 0);
    char* b = (char*)m + 0x10000;
    int r = 0;
    int i;
    for (i = 0; i < 30; ++i) {
        char* t = b + 0x1F00;
        int o = i * 4;
        if (h == *(unsigned int*)(t + o)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" int sprintf(char* buf, const char* fmt, ...);
extern void* (*lbl_8062C668)(int size, int heap);
extern const char lbl_805E017C[];
extern const char lbl_805DFC34[];
extern char lbl_8060D190[];
void* fn_802B9300(const char* name, int a, int b, int* n);
void* fn_802B98AC(int a, int b);
int fn_802B9A04(int a);
void* fn_803E9640(void* a, void* b, int c, void* fn);
void fn_8033E7A4();
void fn_80312700();
void fn_803E9994(void* a, char* tbl, int* n, void* z);
void fn_803D6144(int a, int b);

struct Unk802B10D4_Out {
    void* m0;
    void* m4;
    void* m8;
    int mC;
};
struct Unk802B10D4_Z {
    int m0;
    int m4;
    int m8;
};
struct Unk802B10D4_M {
    char pad0[0x36E0];
    int m36E0;
};

struct Unk802BB948;
void fn_802BB948(Unk802BB948* o);
void fn_802B961C(int p, int a);
void fn_80377408(void* p);

struct Unk802B0EE0_E12 {
    char d[12];
    ~Unk802B0EE0_E12() { fn_802BB948((Unk802BB948*)this); }
};
struct Unk802B0EE0_Own {
    int m0;
    int m4;
    Unk802B0EE0_E12 e8;
    int m14;
    Unk802B0EE0_E12 e18;
    int m24;
    Unk802B0EE0_E12 e28;
    int m34;
    Unk802B0EE0_E12 e38;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    int m5C;
    int m60;
    int m64;
    ~Unk802B0EE0_Own()
    {
        if (m4 != 0)
            m4 = 0;
        fn_802BB948((Unk802BB948*)&e8);
        if (m0 != 0) {
            fn_802B961C(m0, 1);
            m0 = 0;
        }
        if (m44 != 0) {
            fn_802B961C(m44, 1);
            m44 = 0;
        }
        if (m54 != 0) {
            fn_803DD73C((void*)m54, 3);
            m54 = 0;
        }
        if (m58 != 0) {
            fn_803DD73C((void*)m58, 3);
            m58 = 0;
        }
        if (m48 != 0) {
            fn_802B961C(m48, 1);
            m48 = 0;
        }
        if (m4C != 0) {
            fn_802B961C(m4C, 1);
            m4C = 0;
        }
        if (m60 != 0) {
            fn_802B961C(m60, 1);
            m60 = 0;
        }
        if (m50 != 0) {
            fn_803DD73C((void*)m50, 3);
            m50 = 0;
        }
        if (m5C != 0) {
            fn_803DD73C((void*)m5C, 3);
            m5C = 0;
        }
        if (m64 != 0) {
            fn_802B961C(m64, 1);
            m64 = 0;
        }
        if (m14 != 0)
            m14 = 0;
        fn_802BB948((Unk802BB948*)&e18);
        if (m24 != 0)
            m24 = 0;
        fn_802BB948((Unk802BB948*)&e28);
        if (m34 != 0)
            m34 = 0;
        fn_802BB948((Unk802BB948*)&e38);
    }
};

void fn_802B0EE0(Unk802B0EE0_Own* p, int c)
{
    p->~Unk802B0EE0_Own();
    if (c & 1)
        fn_80377408(p);
}

void fn_802B10D4(Mgr* m, int a, int unused, Unk802B10D4_Out* out)
{
    char buf[0x40];
    int n = 0;
    sprintf(buf, lbl_805E017C, unused, lbl_805DFC34);
    out->m0 = fn_802B9300(buf, 0x400, 0xE, &n);
    out->m4 = fn_802B98AC(a, 0x400);
    int h = fn_802B9A04(a);
    void* o = lbl_8062C668(0x30, 0);
    out->m8 = fn_803E9640(o, out->m4, h, (void*)fn_80312700);
    fn_8033E7A4();
    int cnt = 0;
    Unk802B10D4_Z z;
    Unk802B10D4_Z* pz = &z;
    z.m0 = 0;
    pz->m8 = 0;
    fn_803E9994(out->m8, lbl_8060D190, &cnt, pz);
    out->mC = z.m8;
    fn_803D6144(z.m8, (int)out->m0);
    ((Unk802B10D4_M*)m)->m36E0 += h + n;
}

void* fn_802B11E0(Mgr* m, const char* s)
{
    if (fn_8040B574(s, lbl_805E0190) == 0)
        return (char*)m + 0x3704;
    if (fn_8040B574(s, lbl_805E019C) == 0)
        return (char*)m + 0x3714;
    if (fn_8040B574(s, lbl_805E01A8) == 0)
        return (char*)m + 0x3724;
    if (fn_8040B574(s, lbl_805E01B4) == 0)
        return (char*)m + 0x3734;
    if (fn_8040B574(s, lbl_805E01B8) == 0)
        return (char*)m + 0x3744;
    if (fn_8040B574(s, lbl_805E01C4) == 0)
        return (char*)m + 0x3754;
    if (fn_8040B574(s, lbl_805E01D0) == 0)
        return (char*)m + 0x3764;
    if (fn_8040B574(s, lbl_805E01DC) == 0)
        return (char*)m + 0x3774;
    if (fn_8040B574(s, lbl_805E01E8) == 0)
        return (char*)m + 0x3784;
    if (fn_8040B574(s, lbl_805E01F4) == 0)
        return (char*)m + 0x3794;
    if (fn_8040B574(s, lbl_805E01FC) == 0)
        return (char*)m + 0x37a4;
    return 0;
}

extern "C" char* strcpy(char* d, const char* s);
void fn_80329AEC(const char** pp, const char** out, int* pn, int delim);
int fn_80329C4C(const char** pp, int* pn, int* out, int lo, int hi, int delim);
void* fn_803774A8(unsigned n, int heap);

struct Unk802B136C_Rec {
    int m0;
    char* m4;
};

void fn_802B136C(Mgr* m, const char* text, int len)
{
    char name[0x10];
    const char* s = name;
    int i = 0;
    int cnt = i;
    T* t = lbl_8061EA68;
    fn_80329C4C(&text, &len, &cnt, 0, 0x7FFFFFFF, 10);
    t->m304 = cnt;
    for (i = 0; i < t->m304; i++) {
        fn_80329AEC(&text, &s, &len, 10);
        Unk802B136C_Rec* r = (Unk802B136C_Rec*)fn_802B11E0(m, s);
        int c2 = 0;
        fn_80329C4C(&text, &len, &c2, 0, 0x7FFFFFFF, 10);
        r->m0 = c2;
        r->m4 = 0;
        if (c2 != 0)
            r->m4 = (char*)fn_803774A8(c2 * 0x14, 0);
        for (int j = 0; j < c2; j++) {
            fn_80329AEC(&text, &s, &len, 0x2C);
            strcpy(r->m4 + j * 0x14 + 4, s);
            fn_80329C4C(&text, &len, (int*)(r->m4 + j * 0x14), 0, 0x7FFFFFFF, 10);
        }
    }
}

void fn_802B1CB4()
{
    if (lbl_8061EA68 == 0) {
        lbl_8061EA68 = (T*)operator new(0x3F8, 0);
        if (lbl_8061EA68 != 0)
            fn_802B1D44(lbl_8061EA68);
    }
}

void fn_802B1D04()
{
    if (lbl_8061EA68 != 0) {
        delete lbl_8061EA68;
        lbl_8061EA68 = 0;
    }
}

void fn_802B1D44(T* self)
{
    self->m304 = 0;
    self->m300 = 0;
    fn_8040B320(self, 0, 0x300);
    self->m308 = 0;
    self->m3F4 = 0;
    self->m310 = 0;
    self->m314 = 1;
    self->m318 = 1;
    self->m324 = 0;
    self->m320 = 0;
    self->m328 = 0;
    self->m30C = 4;
    fn_802B1E38(self, lbl_805E0280, 3);
    fn_802B1E38(self, lbl_805E028C, 0);
    fn_802B1E38(self, lbl_805E029C, 0);
    fn_802B1E38(self, lbl_805E02A8, 0);
    fn_8040B61C(self->m3CC, lbl_805E02B4);
    fn_802B1FC0(self);
    fn_802B1FC0(self);
    self->m3F0 = 2;
    self->m31C = 1;
    self->m324 = 1;
    self->m3EC = 1;
    self->m3E4 = 0;
}

void fn_802B1E38(T* self, const char* name, int val)
{
    int i;
    for (i = 0; i < self->m300; i++) {
        if (fn_8040B574(name, self->e[i].name) == 0) {
            self->e[i].val = val;
            return;
        }
    }
    fn_8040B61C(self->e[self->m300].name, name);
    self->e[self->m300].val = val;
    self->m300++;
}

int fn_802B1EE8(T* self, const char* name)
{
    int i;
    for (i = 0; i < self->m300; i++) {
        if (fn_8040B574(name, self->e[i].name) == 0)
            return self->e[i].val;
        if (fn_8040B574(name, lbl_805E02C0) == 0)
            return 0;
    }
    return 5;
}

void fn_802B1F88(void* self)
{
    Unk802B2518_W* w = lbl_8061E978;
    void* a = w->m240;
    char* b = (char*)w + 0x370C;
    if (a != 0)
        fn_802B2268(self, a, b);
}

/* near-miss (unmatched, 48 vs 52 insns): retail keeps two offset registers (i*8, i*8+4) with the base re-formed in the loop and a cr7 compare for the pad count */
void fn_802B1FC0(T* self)
{
    char* s = self->m3CC;
    int len = fn_8040B6A0(s);
    int pad = (0x14 - len) >> 1;
    if (pad <= 0)
        pad = 0;
    int k = 0;
    for (int i = 0; i < 20; i++) {
        self->g[i].a = 7;
        self->g[i].b = 3;
        int cur = pad;
        pad--;
        if (cur > 0) {
            self->g[i].a = 7;
            self->g[i].b = 3;
        } else if (k < len) {
            int c = s[k];
            if (c == 0x20) {
                self->g[i].a = 7;
                self->g[i].b = 3;
            } else {
                int d = c - 0x61;
                self->g[i].a = d & 7;
                self->g[i].b = (d >> 3) & 3;
            }
            k++;
        }
    }
}

struct Unk802B2F64_A;
struct Unk802B2F64_B;
void fn_802B2F64(T* self, Unk802B2F64_A* a, Unk802B2F64_B* b, int unused, int flag);
extern int lbl_8061EA6C;
extern int lbl_8061EA70;
extern T* lbl_8061EA68;

void fn_802B2090(char* o)
{
    T* t = lbl_8061EA68;
    if (t->m328 != 0) {
        if (++lbl_8061EA70 == 0x3C) {
            lbl_8061EA70 = 0;
            if (++lbl_8061EA6C > 5)
                lbl_8061EA6C = 0;
        }
        if (*(Unk802B2F64_A**)(o + 0x238) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0x238), (Unk802B2F64_B*)(o + 0x3704), 1, 1);
        if (*(Unk802B2F64_A**)(o + 0x190) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0x190), (Unk802B2F64_B*)(o + 0x3714), 1, 1);
        if (*(Unk802B2F64_A**)(o + 0x228) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0x228), (Unk802B2F64_B*)(o + 0x3724), 1, 1);
        if (*(Unk802B2F64_A**)(o + 0x1a0) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0x1a0), (Unk802B2F64_B*)(o + 0x3734), 1, 1);
        if (*(Unk802B2F64_A**)(o + 0x258) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0x258), (Unk802B2F64_B*)(o + 0x3744), 1, 1);
        if (*(Unk802B2F64_A**)(o + 0x268) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0x268), (Unk802B2F64_B*)(o + 0x3754), 1, 1);
        if (*(Unk802B2F64_A**)(o + 0xab8) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0xab8), (Unk802B2F64_B*)(o + 0x3764), 1, 1);
        if (*(Unk802B2F64_A**)(o + 0xac8) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0xac8), (Unk802B2F64_B*)(o + 0x3774), 1, 1);
        if (*(Unk802B2F64_A**)(o + 0xad8) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0xad8), (Unk802B2F64_B*)(o + 0x3784), 1, 1);
        if (*(Unk802B2F64_A**)(o + 0x248) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0x248), (Unk802B2F64_B*)(o + 0x3794), 1, 1);
        if (*(Unk802B2F64_A**)(o + 0xae8) != 0)
            fn_802B2F64(t, *(Unk802B2F64_A**)(o + 0xae8), (Unk802B2F64_B*)(o + 0x37a4), 1, 1);
    }
}

void fn_802B23EC() {}

Unk802B2518_S* fn_802B23F0(Unk802B2518_S* self, int a)
{
    fn_80328234(self, 6, a);
    self->m1C48 = a;
    self->m2C = 0x100;
    self->m18 = lbl_80664140;
    self->mC30 = 2;
    self->m1C34 = -1.0f;
    self->m1C3C = 1;
    self->m28 = 0;
    self->m1C40 = 0.0f;
    self->m1C44 = 0.0f;
    self->m24 = 0;
    fn_8040B320(self->e30, 1, 0x400);
    for (int i = 0; i < self->m2C; i++) {
        self->e30[i] = 1;
        int r = fn_8040ABA0();
        self->f430[i] = (float)(r % 2) + 2.0f;
        self->f1834[i] = 0.0f;
    }
    return self;
}

void fn_802B2518(Unk802B2518_S* self, int a, float x)
{
    if (fn_80075E7C(lbl_8061E978->m8) <= 29) {
        self->mC30 = a / 2;
        self->m1C40 = x;
        self->m1C44 = 0.0f;
        self->m1C3C = 2;
    }
}

void fn_802B258C(Unk802B2518_S* self)
{
    self->m1C3C = 1;
    self->m1C40 = 0.0f;
    self->m1C44 = 0.0f;
    self->mC30 = 0;
    self->m28 = 0;
    self->m1C34 = -1.0f;
    for (int i = 0; i < self->m2C; i++) {
        self->e30[i] = 1;
        int r = fn_8040ABA0();
        self->f430[i] = (float)(r % 2) + 2.0f;
        self->f1834[i] = 0.0f;
    }
}

void fn_802B2B8C(void* arg)
{
    void** g = &lbl_8061EA74;
    *g = fn_802B23F0(operator new(0x1C4C, 0x400), arg);
}

void fn_802B2BD0()
{
    if (lbl_8061EA74 != 0 && ((Unk802B2BD0_D*)lbl_8061EA74)->m24 != 0) {
        fn_803DD73C(((Unk802B2BD0_D*)lbl_8061EA74)->m24, 3);
        ((Unk802B2BD0_D*)lbl_8061EA74)->m24 = 0;
    }
    if (lbl_8061EA74 != 0) {
        delete (Unk802B2BD0_V*)lbl_8061EA74;
        lbl_8061EA74 = 0;
    }
}

struct Unk802B2C58_S {
    int m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    int m1C;
    char pad20[4];
    void* m24;
    void* m28;
    void* m2C;
    void* m30;
    void* m34;
    void* a38[1];
};

Unk802B2C58_S* fn_802B2C58(Unk802B2C58_S* self)
{
    for (int i = 0; i < 1; i++) {
        void* z = 0;
        self->a38[i] = z;
    }
    self->m24 = 0;
    self->m28 = 0;
    self->m34 = 0;
    self->m30 = 0;
    return self;
}

/* near-miss (2 slots): retail stores m10 before m8 among the float zeros; the head stores' order is the best found by search */
void* fn_802AFA54(Mgr* m, const char* s);
void* fn_803DD628(void* a, void* b);
extern void* (*lbl_8062C668)(int size, int heap);
extern char lbl_8061EA98[];
extern const char lbl_805E0324[];

void fn_802B2C98(Unk802B2C58_S* self)
{
    self->m10 = 0.0f;
    self->m4 = -1.0f;
    self->m18 = -1.0f;
    self->mC = 0.0f;
    self->m8 = 0.0f;
    self->m1C = 0;
    self->m0 = 0;
    self->m24 = 0;
    self->m28 = 0;
    self->m2C = 0;
    for (int i = 0; i < 1; i++) {
        if (self->a38[i] == 0) {
            void* s = fn_802AFA54((Mgr*)lbl_8061E978, lbl_8061EA98 + i * 5);
            if (s != 0) {
                self->a38[i] = fn_803DD628(lbl_8062C668(0x58, 0), s);
                self->m34 = s;
            }
        }
    }
    void* s = fn_802AFA54((Mgr*)lbl_8061E978, lbl_805E0324);
    if (s != 0) {
        void* r = fn_803DD628(lbl_8062C668(0x58, 0), s);
        self->m30 = s;
        self->m24 = r;
        self->m28 = r;
    }
}

extern const char lbl_805E0334[];

int fn_802B2DB8(Unk802B2C58_S* self)
{
    T* g = lbl_8061EA68;
    int r;
    if ((g != 0 && g->m328 != 0 && (lbl_8061E978->m8 == 0x22 || lbl_8061E978->m8 == 0x55) && fn_802B1EE8(g, lbl_805E0334) != 5)
        || self->m18 == -1.0f || self->m14 < self->m18 || !(self->m14 <= self->m18 + 30.0f)) {
        self->m0 = 0;
        r = 0;
    } else {
        self->m0 = 1;
        float d = self->m14 - self->m18;
        d = d * 2.857143f;
        if ((int)d & 1) {
            self->m28 = self->a38[0];
            self->m2C = self->m34;
        } else {
            self->m28 = self->m24;
            self->m2C = self->m30;
        }
        r = 1;
    }
    return r;
}

void fn_802B2ED0(T* self, int a)
{
    *(int*)((char*)self + 0x20) = a;
    *(float*)((char*)self + 0x18) = *(float*)((char*)self + 0x14);
}

void fn_802B2EE0(T* self)
{
    *(float*)((char*)self + 0x18) = -1.0f;
}

struct Unk802B2EF0_S {
    char pad0[0x24];
    void* m24;
    char pad28[0x38 - 0x28];
    void* m38[1];
};

/* near-miss 99.8%: retail skips the m24 store when the handle is null (store inside the if); that form swaps r30/r31 (self/offset) */
void fn_802B2EF0(Unk802B2EF0_S* self)
{
    for (int i = 0; i < 1; i++) {
        if (self->m38[i] != 0)
            fn_803DD73C(self->m38[i], 3);
        self->m38[i] = 0;
    }
    if (self->m24 != 0) {
        fn_803DD73C(self->m24, 3);
    }
    self->m24 = 0;
}

extern "C" int strcmp(const char* a, const char* b);
extern int lbl_8061EA6C;
extern const char lbl_805E0280[];
extern const char lbl_805E028C[];
extern const char lbl_805E029C[];
extern const char lbl_805E02A8[];

struct Unk802B2F64_E {
    short m0;
    short m2;
};
struct Unk802B2F64_A {
    char pad0[0x9C];
    int m9C;
    char padA0[0xC4 - 0xA0];
    char* mC4;
};
struct Unk802B2F64_B {
    char pad0[4];
    char* m4;
    int* m8;
    int* mC;
};

void fn_802B2F64(T* self, Unk802B2F64_A* a, Unk802B2F64_B* b, int unused, int flag)
{
    if (self->m328 == 0)
        return;
    int n = a->m9C;
    char* base = b->m4;
    if (b->m8 == 0 || base == 0)
        return;
    for (int i = 0; i < n; i++) {
        int idx = b->m8[i];
        char* name = base + idx * 0x14 + 4;
        int ok = 1;
        int lvl = fn_802B1EE8(self, name);
        if (strcmp(name, lbl_805E0280) == 0)
            ok = 0;
        if (strcmp(name, lbl_805E029C) == 0)
            ok = 0;
        if (strcmp(name, lbl_805E02A8) == 0)
            ok = 0;
        if (strcmp(name, lbl_805E028C) == 0)
            ok = 0;
        if (flag != 0)
            lvl = lbl_8061EA6C;
        Unk802B2F64_E* e = i < a->m9C ? (Unk802B2F64_E*)(a->mC4 + 4 + i * 4) : 0;
        if (ok != 0) {
            if (*(int*)(base + idx * 0x14) > lvl) {
                e->m2 = 0;
                b->mC[idx] = 1;
            } else {
                b->mC[idx] = 0;
                e->m2 = 1;
            }
        } else {
            if (*(int*)(base + idx * 0x14) == lvl) {
                b->mC[idx] = ok;
                e->m2 = 1;
            } else {
                b->mC[idx] = 1;
                e->m2 = ok;
            }
        }
    }
}

void fn_802B3130(void* unused, Unk802B3130_In* x, Unk802B3130_Out* out)
{
    int n = x->m9C;
    if (n != 0)
        out->mC = new (0) int[n];
    else
        out->mC = (int*)n;
    for (int i = 0; i < n; i++)
        out->mC[i] = 1;
}

struct Unk802B31A0_O {
    char pad0[0x3708];
    char* m3708;
    char* m370C;
    char* m3710;
    char pad3714[4];
    char* m3718;
    char* m371C;
    char* m3720;
    char pad3724[4];
    char* m3728;
    char* m372C;
    char* m3730;
    char pad3734[4];
    char* m3738;
    char* m373C;
    char* m3740;
    char pad3744[4];
    char* m3748;
    char* m374C;
    char* m3750;
    char pad3754[4];
    char* m3758;
    char* m375C;
    char* m3760;
    char pad3764[4];
    char* m3768;
    char* m376C;
    char* m3770;
    char pad3774[4];
    char* m3778;
    char* m377C;
    char* m3780;
    char pad3784[4];
    char* m3788;
    char* m378C;
    char* m3790;
    char pad3794[4];
    char* m3798;
    char* m379C;
    char* m37A0;
    char pad37A4[4];
    char* m37A8;
    char* m37AC;
    char* m37B0;
};

void fn_802B31A0(Unk802B31A0_O* o)
{
    if (o->m3708 != 0) {
        delete[] o->m3708;
        o->m3708 = 0;
    }
    if (o->m370C != 0) {
        delete[] o->m370C;
        o->m370C = 0;
    }
    if (o->m3710 != 0) {
        delete[] o->m3710;
        o->m3710 = 0;
    }
    if (o->m3718 != 0) {
        delete[] o->m3718;
        o->m3718 = 0;
    }
    if (o->m371C != 0) {
        delete[] o->m371C;
        o->m371C = 0;
    }
    if (o->m3720 != 0) {
        delete[] o->m3720;
        o->m3720 = 0;
    }
    if (o->m3728 != 0) {
        delete[] o->m3728;
        o->m3728 = 0;
    }
    if (o->m372C != 0) {
        delete[] o->m372C;
        o->m372C = 0;
    }
    if (o->m3730 != 0) {
        delete[] o->m3730;
        o->m3730 = 0;
    }
    if (o->m3738 != 0) {
        delete[] o->m3738;
        o->m3738 = 0;
    }
    if (o->m373C != 0) {
        delete[] o->m373C;
        o->m373C = 0;
    }
    if (o->m3740 != 0) {
        delete[] o->m3740;
        o->m3740 = 0;
    }
    if (o->m3748 != 0) {
        delete[] o->m3748;
        o->m3748 = 0;
    }
    if (o->m374C != 0) {
        delete[] o->m374C;
        o->m374C = 0;
    }
    if (o->m3750 != 0) {
        delete[] o->m3750;
        o->m3750 = 0;
    }
    if (o->m3758 != 0) {
        delete[] o->m3758;
        o->m3758 = 0;
    }
    if (o->m375C != 0) {
        delete[] o->m375C;
        o->m375C = 0;
    }
    if (o->m3760 != 0) {
        delete[] o->m3760;
        o->m3760 = 0;
    }
    if (o->m3768 != 0) {
        delete[] o->m3768;
        o->m3768 = 0;
    }
    if (o->m376C != 0) {
        delete[] o->m376C;
        o->m376C = 0;
    }
    if (o->m3770 != 0) {
        delete[] o->m3770;
        o->m3770 = 0;
    }
    if (o->m3778 != 0) {
        delete[] o->m3778;
        o->m3778 = 0;
    }
    if (o->m377C != 0) {
        delete[] o->m377C;
        o->m377C = 0;
    }
    if (o->m3780 != 0) {
        delete[] o->m3780;
        o->m3780 = 0;
    }
    if (o->m3788 != 0) {
        delete[] o->m3788;
        o->m3788 = 0;
    }
    if (o->m378C != 0) {
        delete[] o->m378C;
        o->m378C = 0;
    }
    if (o->m3790 != 0) {
        delete[] o->m3790;
        o->m3790 = 0;
    }
    if (o->m3798 != 0) {
        delete[] o->m3798;
        o->m3798 = 0;
    }
    if (o->m379C != 0) {
        delete[] o->m379C;
        o->m379C = 0;
    }
    if (o->m37A0 != 0) {
        delete[] o->m37A0;
        o->m37A0 = 0;
    }
    if (o->m37A8 != 0) {
        delete[] o->m37A8;
        o->m37A8 = 0;
    }
    if (o->m37AC != 0) {
        delete[] o->m37AC;
        o->m37AC = 0;
    }
    if (o->m37B0 != 0) {
        delete[] o->m37B0;
        o->m37B0 = 0;
    }
}
