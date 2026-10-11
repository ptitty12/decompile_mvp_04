/*
 * Game code, .text 0x802CFED4-0x802D3E44 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802CFED4.h"

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

void fn_802D116C(Unk802D116C* p, int c)
{
    p->vptr = lbl_806646F0;
    fn_8037B424(p, c);
}

void fn_802D119C()
{
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

void fn_802D134C()
{
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

void fn_802D331C()
{
}

void fn_802D3320(Unk802D3320* o)
{
    o->m20.Scale(12.0f);
}

Unk802D3268* fn_802D34EC()
{
    return new (lbl_806EF9B4) Unk802D3268;
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

void fn_802D3E10(Unk802D3E10* o)
{
    o->s7();
}
