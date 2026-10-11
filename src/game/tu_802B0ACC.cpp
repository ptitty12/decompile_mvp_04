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

void fn_802B2ED0(T* self, int a)
{
    *(int*)((char*)self + 0x20) = a;
    *(float*)((char*)self + 0x18) = *(float*)((char*)self + 0x14);
}

void fn_802B2EE0(T* self)
{
    *(float*)((char*)self + 0x18) = -1.0f;
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
