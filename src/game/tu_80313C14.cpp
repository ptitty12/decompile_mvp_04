/*
 * Game code, .text 0x80313C14-0x80317B88 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802F8324.h"

struct lbl_Node;
class lbl_Owner {
public:
    char pad0[0x8];
    void* m8;
    void fn_803DA038();
    void fn_803DA098(lbl_Node* node);
};

extern int lbl_8061FF44;
struct Unk80313C14_Q {
    int w[4];
};
extern Unk80313C14_Q lbl_8068F1C4;
struct Unk80313C14_F {
    char pad0[4];
    float m4;
    char pad8[8];
    float m10;
    char pad14[8];
    float m1C;
};
extern Unk80313C14_F lbl_8061FEB0;

struct Unk80313C14_P38C {
    char pad0[0xC];
    int mC;
};
struct Unk80313C14_P38 {
    char pad0[0x38];
    Unk80313C14_P38C* m38;
};
struct Unk80313C14_P38O {
    char pad0[0x38];
    lbl_Owner* m38;
};
struct Unk80313C14_Own4 {
    char pad0[4];
    lbl_Owner* m4;
};
struct Unk80313C14_P38H {
    char pad0[0x38];
    Unk80313C14_Own4* m38;
};
struct Unk80313C14_P58 {
    char pad0[0x58];
    int m58;
};
struct Unk80313C14_P4 {
    char pad0[4];
    void* m4;
    void* m8;
};
struct Unk80313C14_P200 {
    char pad0[0x200];
    int m200;
};
struct Unk80313C14_Cmp88 {
    char pad0[0x88];
    int m88;
    int m8C;
};
struct Unk80313C14_Cmp18 {
    char pad0[0x18];
    int m18;
    int m1C;
};
class Unk80313C14_Big {
public:
    char pad0[0x18];
    virtual ~Unk80313C14_Big();
};
extern Unk80313C14_Big* lbl_8061FF44_big;

struct Unk80313C14_Slot {
    char pad0[0x20];
    int m20;
};
struct Unk80313C14_Eng {
    char pad0[0x11E88];
    Unk80313C14_Slot* t[1];
    char pad11E8C[0x11EE0 - 0x11E8C];
    int m11EE0;
};
extern Unk80313C14_Eng* lbl_8061E978;
struct Unk80313C14_Fl {
    char pad0[0x18];
    int m18;
    char pad1C[0x1E0 - 0x1C];
    float m1E0;
    float m1E4;
    float m1E8;
    float m1EC;
};
class Unk80313C14_VC {
public:
    char pad0[0xC];
    virtual int s1();
    virtual int s2();
};
struct Unk80313C14_P38V {
    char pad0[4];
    Unk80313C14_VC* m4;
};
struct Unk80313C14_Sd {
    char pad0[0x38];
    Unk80313C14_P38V* m38;
};
struct Unk80313C14_Ld {
    char pad0[0xC];
    int mC;
    int m10;
};
struct Unk80313C14_P38I {
    char pad0[4];
    int m4;
};
struct Unk80313C14_SdI {
    char pad0[0x38];
    Unk80313C14_P38I* m38;
};
extern int lbl_8061FEAC;
extern int lbl_8061FF10;
extern int lbl_8061E9F4;
extern int lbl_8061D46C;
extern float lbl_8061D470;
extern void* (*lbl_8062C668)(int, int);

struct Unk80313C14_Sz {
    char pad0[0x14];
    int m14;
    int m18;
};
struct Unk80313C14_Tbl {
    char pad0[8];
    int m8;
    char padC[8];
    int m14;
};
struct Unk80313C14_Nd {
    char pad0[8];
    void* m8;
};
struct Unk80313C14_Fx3C {
    char pad0[0x3C];
    Unk802F8324_VT18* m3C;
};
struct Unk80313C14_Scr {
    char pad0[0x14];
    int m14;
    char pad18[0x10];
    int m28;
    int m2C;
    char pad30[0x204 - 0x30];
    int m204;
};
extern Unk80313C14_Scr* lbl_8061FEDC;
extern int lbl_8061FF48;
extern float lbl_8061FF4C;
extern float lbl_8068E518;
extern int lbl_8068E51C;
struct Unk80313C14_TxO {
    char m0;
    char pad1[0xB];
    unsigned mC;
};
struct Unk80313C14_TxP {
    char pad0[4];
    char* m4;
};
struct Unk80313C14_Tx {
    char pad0[4];
    Unk80313C14_TxO* m4;
    void* m8;
    char padC[8];
    int m14;
    int m18;
    char pad1C[0x38 - 0x1C];
    Unk80313C14_TxP* m38;
};
struct Unk80313C14_Col {
    float m0;
    float m4;
    float m8;
    float mC;
};
extern const char lbl_805E9AFC[];
extern const char lbl_805E9B24[];
extern int lbl_8061FF38;
extern int lbl_8061FF3C;


extern "C" {
void fn_803EB454(Unk80313C14_Slot* s, char* str, ...);
void fn_803EB3CC(Unk80313C14_Slot* s, int x, float a, float b);
void fn_803D982C(int h, int x);
void fn_8033E958(const char* fmt, ...);
int fn_803E4A50(void* o);
void fn_803E4C30(int t);
int fn_803E6E9C(int t);
void fn_803DBE38(int h, int k);
void fn_803DBE78(int h, int k);
void fn_803EB414(int h, int x, float* a, float* b, float* c, float* d);
int fn_803063F8(int a, int b, int c);
void fn_80314B4C(Unk80313C14_P58* p);
void fn_80306438();
void fn_80377408(void* p);
void fn_803DD73C(void* h, int k);
int fn_803D9E1C(int k);
int fn_80400C1C(void (*f)(), int a, int b);
void* fn_80317810(void* p, int a, int b, int c, int d);
int fn_803E9994(void* a, char* tbl, int* n, void* z);
void fn_803D6144(int a, int b);
int fn_803E9A54(void* a, const char* key, int* n, int* out);
void fn_803DD7C8(int h, int v);
char* fn_803EC3D4(void* p);
void fn_803EC814(void* t, int i, char* out);
void fn_803D74A0(void* h, char* s, void* v);
unsigned int strlen(const char* s);
void fn_803E1DB0(void* n, float a, float b);
void fn_803E0F9C(void* n);
void fn_8031883C(void* o);
void fn_8031F04C(void* n, int k);
void fn_8031E110(void* n);
void fn_803E1E88(void* n);
void fn_80315C90(void* self);
void fn_80314368(void* c, unsigned short* s, int a, int b, float x, float y);
void fn_80317624(int* a, int* b, int c);
Unk80313C14_TxO* fn_803EBBA4(int a, int b, int c, int d, int e, int f, int g, int h);
int fn_803EB864(int a, int b, int c, int d, int e, int f, int g);
void fn_80433004(void* a, int n);
void* fn_803DD628(void* a, void* b);
void fn_803D9E70(void* o, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_803D9ECC(void* o, void* img, int a, int b, int c);
void* fn_800057E4();
void fn_8014D9EC(Unk80313C14_Col* c, float a, float b, float d, float e, float f);
int fn_8014DDAC(Unk80313C14_Col* c);
void fn_803EB3F0(Unk80313C14_Slot* s, unsigned short* str, float a, float b);
void fn_80322164(void* s, char* a, int n, char* b, int m);
int fn_802B9300(char* name, int a, int b, int* c);
void fn_802B961C(int h, int k);
int fn_803FC480(int h, char* s);
int fn_804017D0();
void* fn_803ED604(const char* name, int sz, int k);
void fn_80401710(int h, void* b);
void fn_80433004(void* a, int n);
int fn_80400DA4();
void* fn_803DD628(void* a, void* b);
void fn_803155B4(void* self, int tex, int a, int b, float f1, float f2, float f3, float f4);
void fn_803EDA0C(void* b);
void fn_803220F4(void* s, char* a, int n, char* b, int m);
void fn_803221D4(void* s, char* a, int n, char* b, int m);
}

struct Unk80313C14_Z {
    int m0;
    int m4;
    int m8;
};
extern char lbl_8060D190[];
extern const char lbl_8060D1CC[];
struct Unk802ACD88_Mgr;
void fn_802B8418(Unk802ACD88_Mgr* m);
struct Unk80313C14_Eng2 {
    char padA[0xAF4];
    int mAF4;
    char padB[0x18718 - 0xAF8];
    int m18718;
};
struct Unk80313C14_V4 {
    float m0;
    float m4;
    float m8;
    float mC;
};
extern Unk80313C14_V4 lbl_806E2124;

void fn_8000446C();

extern "C" int fn_80313C14(void* obj, int a, int* out)
{
    int h = 0;
    int n = 0;
    Unk80313C14_Z z;
    Unk80313C14_Z* pz = &z;
    z.m0 = 0;
    pz->m8 = 0;
    fn_803E9994(obj, lbl_8060D190, &n, pz);
    h = z.m8;
    fn_803D6144(h, a);
    n = 0;
    int v;
    int r = fn_803E9A54(obj, lbl_8060D1CC, &n, &v);
    if (r)
        *out = v;
    else
        *out = r;
    return h;
}

void fn_80313CBC(void* a, Unk80313C14_Tbl* t)
{
    int i = 0;
    int n = t->m8;
    if (i < n) {
        int* e = &t->m14;
        do {
            char buf[5];
            char* node = (char*)t + *e;
            e += 2;
            char* s = fn_803EC3D4(node);
            if (s == 0 || strlen(s) > 4) {
                fn_803EC814(t, i, buf);
                char* p = buf + 3;
                while (p >= buf && *p == 0x20) {
                    *p = 0;
                    p--;
                }
                s = buf;
            }
            s[4] = 0;
            i++;
            fn_803D74A0(a, s, node);
        } while (i < n);
    }
}

extern "C" void fn_80313D9C(void* sp, int kind)
{
    Unk80313C14_Sd* self = (Unk80313C14_Sd*)sp;
    if (kind == 3) {
        if (lbl_8061D46C != 0)
            lbl_8061D470 = 0.1f;
        self->m38->m4->s1();
    }
}

extern "C" void fn_80313E00(void* sp, int kind)
{
    Unk80313C14_Sd* self = (Unk80313C14_Sd*)sp;
    if (kind == 3) {
        self->m38->m4->s2();
        int v = lbl_8061FEAC;
        if (v != lbl_8061FF10) {
            lbl_8061FF10 = v;
            fn_803D982C(((Unk80313C14_SdI*)self)->m38->m4, v ^ 1);
            fn_8033E958("%d Switching it
", lbl_8061E9F4);
        }
    }
}

extern "C" float fn_80313E94(void* sp, int x)
{
    Unk80313C14_Fl* self = (Unk80313C14_Fl*)sp;
    float a = 0.0f;
    float b = 0.0f;
    float c = 0.0f;
    float d = 0.0f;
    fn_803EB414(lbl_8061E978->m11EE0, x, &a, &b, &c, &d);
    return d / (float)self->m18;
}

extern "C" float fn_80313F28(void* sp, int x)
{
    Unk80313C14_Fl* self = (Unk80313C14_Fl*)sp;
    float a = 0.0f;
    float b = 0.0f;
    float c = 0.0f;
    float d = 0.0f;
    fn_803EB414(lbl_8061E978->m11EE0, x, &a, &b, &c, &d);
    return c / (float)((Unk80313C14_Sz*)self)->m14;
}

void fn_80313FBC(Unk80313C14_Ld* self)
{
    int t = fn_803E4A50(lbl_8062C668(0xC8, 0));
    self->mC = t;
    fn_803E4C30(t);
    int h = fn_803E6E9C(self->mC);
    fn_803DBE38(h, 1);
    fn_803DBE78(h, 1);
    self->m10 = 1;
}

extern "C" void fn_803145D8(void* pp, int unused, int v, float a, float b, int idx)
{
    Unk80313C14_Sz* p = (Unk80313C14_Sz*)pp;
    if (lbl_8061E978 != 0) {
        if (lbl_8061E978->t[idx] != 0) {
            lbl_8061E978->t[idx]->m20 = v;
            fn_803EB3CC(lbl_8061E978->t[idx], unused, a * (float)p->m14, b * (float)p->m18);
        }
    }
}

/* near-miss: 51 vs 46 instructions; retail reloads the slot after forming the floats and keeps a junk copy of an unset register */
extern "C" void fn_80314688(void* o, int x, int y, char* str, int flag, int idx)
{
    if (lbl_8061E978 != 0) {
        if (lbl_8061E978->t[idx] != 0) {
            lbl_8061E978->t[idx]->m20 = flag == 0 ? 0x80B5AC95 : 0x80FFFFFF;
            fn_803EB454(lbl_8061E978->t[idx], str, (float)x, (float)y);
        }
    }
}

extern "C" void fn_8031479C(void* g)
{
    ((Unk80313C14_P200*)g)->m200 = 1;
    Unk80313C14_Eng2* e = (Unk80313C14_Eng2*)lbl_8061E978;
    int h = e->m18718;
    if (e->mAF4 == 0) {
        lbl_806E2124.m0 = 1279.0f;
        lbl_806E2124.m4 = 447.0f;
        lbl_806E2124.m8 = 1.0f;
        lbl_806E2124.mC = 1.0f;
        fn_802B8418((Unk802ACD88_Mgr*)e);
    } else {
        lbl_806E2124.m0 = 1.0f;
        lbl_806E2124.m4 = 1.0f;
        lbl_806E2124.m8 = 1.0f;
        lbl_806E2124.mC = 1.0f;
        fn_802B8418((Unk802ACD88_Mgr*)e);
    }
    fn_803DD7C8(h, 0);
}

void fn_80314740(Unk80313C14_P38H* p)
{
    p->m38->m4->fn_803DA038();
}

void fn_80314768(Unk80313C14_P38H* p, lbl_Node* n)
{
    p->m38->m4->fn_803DA098(n);
}

int fn_80314790(Unk80313C14_P38* p)
{
    return p->m38->mC;
}

void fn_80314854(Unk80313C14_P58* p)
{
    fn_80314B4C(p);
    p->m58 = fn_803063F8(0x100, 0x100, 0x10);
}

void fn_80314B4C(Unk80313C14_P58* p)
{
    if (p->m58 != 0) {
        fn_80306438();
        p->m58 = 0;
    }
}

void fn_80314D08(int a, void* b)
{
    lbl_8068F1C4 = *(Unk80313C14_Q*)((char*)b + 0xE84);
}

void fn_80314D38(float v)
{
    lbl_8061FEB0.m4 = v;
    lbl_8061FEB0.m10 = v;
    lbl_8061FEB0.m1C = v;
}

void fn_80314D60()
{
}

void fn_803157B4(Unk80313C14_Tx* self)
{
    int w = self->m14;
    int h = self->m18;
    self->m4 = fn_803EBBA4(w, h, 0x20, 0, 0, 0x100, 0, 0);
    int sz = fn_803EB864(w, h, 0x20, 0xF, 0, 0, 0);
    if (self->m4 != 0) {
        fn_80433004(self->m4, sz);
        self->m4->m0 = 0x16;
        self->m4->mC |= 0x20000000;
        void* o = lbl_8062C668(0x58, 0);
        self->m8 = fn_803DD628(o, self->m4);
        if (self->m8 != 0) {
            fn_803D9E70(self->m38->m4 + 0x10, 0, 0, self->m14, self->m18, w, h, 6, 0);
            fn_803D9ECC(self->m38->m4 + 0x10, self->m8, 0, 1, 0);
        }
    }
}

void fn_80315AD8(Unk80313C14_P4* p)
{
    if (p->m4) {
        fn_80377408(p->m4);
        p->m4 = 0;
    }
    if (p->m8) {
        fn_803DD73C(p->m8, 3);
        p->m8 = 0;
    }
}

void fn_80315B34(Unk80313C14_Fx3C* self, unsigned short* name, int flag)
{
    fn_80313D9C(self, 3);
    Unk80313C14_Nd* nd = (Unk80313C14_Nd*)fn_80314790((Unk80313C14_P38*)self);
    fn_803E1DB0(nd->m8, 0.0f, 200.0f);
    fn_803E0F9C(nd->m8);
    fn_8031883C(self->m3C);
    fn_8031F04C(nd, 0);
    fn_8031E110(nd);
    self->m3C->s12();
    if (flag != 0)
        fn_80315C90(self);
    const float a = 0.5f;
    const float b = 0.5f;
    fn_80314368(self, name, 1, 0x16, a, b);
    fn_803E1E88(nd->m8);
    fn_80313E00(self, 3);
}

void fn_80315C20(float* p, float* v, float a, float b, float c)
{
    *p = a + *v;
    if (!(*p <= b)) {
        *v = -*v;
        *p = b;
    }
    if (!(*p >= c)) {
        *v = -*v;
        *p = c;
    }
}

/* near-miss: 100/100 insns, 5 slots differ: retail keeps the fn_803FC480 result in r30 and the fn_804017D0 size in r29; ours swaps them (local-alloc priority 2 refs/10 insns vs 3 refs/14 insns); inline wrappers and declaration order did not change it */
void fn_80315FFC(char* self)
{
    char a[256];
    char b[256];
    fn_80322164(self + 0x1F0, a, 0x100, b, 0x100);
    int h1 = fn_802B9300(a, 0x500, 0xE, 0);
    int h2 = fn_803FC480(h1, b);
    int sz = fn_804017D0();
    char* buf = (char*)fn_803ED604(lbl_805E9AFC, sz, 0x500);
    fn_80401710(h2, buf);
    fn_802B961C(h1, 0xE);
    fn_80433004(buf, sz);
    fn_803D9E1C(0);
    lbl_8061FF38 = fn_80400DA4();
    int tex = (int)fn_803DD628(lbl_8062C668(0x58, 0), buf + *(int*)(buf + 0x14));
    fn_803155B4(lbl_8061FEDC, tex, 1, 1, 0.0f, 0.0f, 1.0f, 1.0f);
    fn_803155B4(lbl_8061FEDC, tex, 1, 1, 0.0f, 0.0f, 1.0f, 1.0f);
    fn_803155B4(lbl_8061FEDC, tex, 1, 1, 0.0f, 0.0f, 1.0f, 1.0f);
    fn_80313D9C(lbl_8061FEDC, 3);
    fn_80313E00(lbl_8061FEDC, 3);
    if (tex != 0)
        fn_803DD73C((void*)tex, 3);
    fn_803EDA0C(buf);
}

/* near-miss: 100/100 insns, 5 slots differ: retail keeps the fn_803FC480 result in r30 and the fn_804017D0 size in r29; ours swaps them (local-alloc priority 2 refs/10 insns vs 3 refs/14 insns); inline wrappers and declaration order did not change it */
extern "C" void fn_8031618C(char* self)
{
    char a[256];
    char b[256];
    fn_803220F4(self + 0x1F0, a, 0x100, b, 0x100);
    int h1 = fn_802B9300(a, 0x500, 0xE, 0);
    int h2 = fn_803FC480(h1, b);
    int sz = fn_804017D0();
    char* buf = (char*)fn_803ED604(lbl_805E9AFC, sz, 0x500);
    fn_80401710(h2, buf);
    fn_802B961C(h1, 0xE);
    fn_80433004(buf, sz);
    fn_803D9E1C(0);
    int tex = (int)fn_803DD628(lbl_8062C668(0x58, 0), buf + *(int*)(buf + 0x14));
    fn_803155B4(lbl_8061FEDC, tex, 1, 1, 0.0f, 0.0f, 1.0f, 1.0f);
    fn_803155B4(lbl_8061FEDC, tex, 1, 1, 0.0f, 0.0f, 1.0f, 1.0f);
    fn_803155B4(lbl_8061FEDC, tex, 1, 1, 0.0f, 0.0f, 1.0f, 1.0f);
    fn_80313D9C(lbl_8061FEDC, 3);
    fn_80313E00(lbl_8061FEDC, 3);
    if (tex != 0)
        fn_803DD73C((void*)tex, 3);
    fn_803EDA0C(buf);
}

/* near-miss: 100/100 insns, 5 slots differ: retail keeps the fn_803FC480 result in r30 and the fn_804017D0 size in r29; ours swaps them (local-alloc priority 2 refs/10 insns vs 3 refs/14 insns); inline wrappers and declaration order did not change it */
void fn_80316310(char* self)
{
    char a[256];
    char b[256];
    fn_803221D4(self + 0x1F0, a, 0x100, b, 0x100);
    int h1 = fn_802B9300(a, 0x500, 0xE, 0);
    int h2 = fn_803FC480(h1, b);
    int sz = fn_804017D0();
    char* buf = (char*)fn_803ED604(lbl_805E9B24, sz, 0x500);
    fn_80401710(h2, buf);
    fn_802B961C(h1, 0xE);
    fn_80433004(buf, sz);
    fn_803D9E1C(0);
    int tex = (int)fn_803DD628(lbl_8062C668(0x58, 0), buf + *(int*)(buf + 0x14));
    fn_803155B4(lbl_8061FEDC, tex, 1, 1, 0.0f, 0.0f, 1.0f, 1.0f);
    fn_803155B4(lbl_8061FEDC, tex, 1, 1, 0.0f, 0.0f, 1.0f, 1.0f);
    fn_803155B4(lbl_8061FEDC, tex, 1, 1, 0.0f, 0.0f, 1.0f, 1.0f);
    fn_80313D9C(lbl_8061FEDC, 3);
    fn_80313E00(lbl_8061FEDC, 3);
    if (tex != 0)
        fn_803DD73C((void*)tex, 3);
    fn_803EDA0C(buf);
    lbl_8061FF3C = fn_80400DA4();
}

int fn_803164A0()
{
    return fn_803D9E1C(1);
}

void fn_803167F0(Unk80313C14_Fl* p, float a, float b, float c, float d)
{
    p->m1E0 = a;
    p->m1E4 = b;
    p->m1E8 = c;
    p->m1EC = d;
}

void fn_80316B88()
{
}

void fn_80316B8C()
{
}

int fn_80316B90()
{
    return fn_80400C1C(fn_8000446C, 1, 0);
}

void fn_80316BC0(Unk80313C14_P200* p)
{
    p->m200 = 1;
}

float fn_8031708C()
{
    return 0.0f;
}

void fn_80317098()
{
}

void fn_8031709C()
{
}

int fn_803170A0(Unk80313C14_Cmp88* a, Unk80313C14_Cmp88* b)
{
    if (a->m88 < b->m88)
        return -1;
    if (a->m88 > b->m88)
        return 1;
    if (a->m8C < b->m8C)
        return -1;
    return 1;
}

int fn_803170E0(Unk80313C14_Cmp18* a, Unk80313C14_Cmp18* b)
{
    if (a->m18 < b->m18)
        return -1;
    if (a->m18 > b->m18)
        return 1;
    if (a->m1C < b->m1C)
        return -1;
    return 1;
}

extern "C" void fn_80317120(int a, int b)
{
    lbl_8061FF48 = a;
    if (a != 0 && lbl_8061FEDC->m204 != 0) {
        if (lbl_8068E51C == 0) {
            float* q = &lbl_8068E518;
            int v = lbl_8061FEDC->m28 != 0 ? lbl_8061FEDC->m2C : lbl_8061FEDC->m14;
            lbl_8068E51C = 1;
            *q = (float)v;
        }
        int base = b - 0x140;
        int sp8 = base;
        int spC = 0;
        fn_80317624(&sp8, &spC, 1);
        lbl_8061FF4C = (float)(sp8 - base) / lbl_8068E518;
        return;
    }
    lbl_8061FF4C = 0.0f;
}

void fn_80317AB0(int flag)
{
    if (lbl_8061FF44 == 0) {
        if (flag)
            lbl_8061FF44 = (int)fn_80317810(operator new(0x168, 0x100), 0x10E, 0, 0x1000, 0x12C);
        else
            lbl_8061FF44 = (int)fn_80317810(operator new(0x168, 0x100), 0x82, 0x1E, 0x800, 0xA5);
    }
}

void fn_80317B30()
{
    if (lbl_8061FF44_big) {
        delete lbl_8061FF44_big;
        lbl_8061FF44_big = 0;
    }
}
