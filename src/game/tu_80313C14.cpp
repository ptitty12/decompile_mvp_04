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
}

void fn_8000446C();

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
