/*
 * Game code, .text 0x8024B99C-0x8024EF40 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024B99C.h"
#include "game/chooser.h"

extern const Unk8024B99C_V3 lbl_806055DC;
float fn_801A20F8(Unk8022FE34_Ctx* c, int a, float f1, float f2);
float fn_801A2158(Unk8022FE34_Ctx* c, int a);
float fn_8024D0C4(Unk80270BA0_X* x, int a, float f1, float f2);
int fn_801A2034(Unk8022FE34_Ctx* c, int i);
Unk8027C728_Goal* fn_80244C84(Unk80270BA0_X* x);
int fn_8024E1B8(Unk80270BA0_X* x);
int fn_8024D144(Unk80270BA0_X* x);
int fn_8026DD60(Unk80270BA0_X* x, int a);
char* fn_8024D2E8(Unk80270BA0_X* x);
char* fn_8024D330(Unk80270BA0_X* x);
char* fn_8024D378(Unk80270BA0_X* x);

void fn_8024BF04(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (v->m8D4 < v->m8D8)
        v->m8D4++;
}

extern const double lbl_805D9548;
extern const float lbl_805D9550;

float fn_8024BF20(Unk80270BA0_X* x, float f)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    int a = v->m8D4;
    int b = v->m8D8;
    if (a < b && b > 0) {
        float t = (float)a / (float)b;
        float q = lbl_805D9550 - t;
        float p = f * t;
        p = v->m8D0 * q + p;
        return p;
    }
    return f;
}

void fn_8024BFD0(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (v->m8E0 < v->m8E4)
        v->m8E0++;
}

extern const float lbl_805D9560;

float fn_8024BFEC(Unk80270BA0_X* x, float f)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    int a = v->m8E0;
    int b = v->m8E4;
    if (a < b && b > 0) {
        float t = (float)a / (float)b;
        float q = lbl_805D9560 - t;
        float p = f * t;
        p = v->m8DC * q + p;
        return p;
    }
    return f;
}

/* near-miss: retail emits 'li r0,0; b end' for the k <= 27 arm; ours threads it into 'ble end' (12 vs 13 insns).
   Tried nested-if, ternary and if/else-chain forms */
int fn_8024C09C(unsigned k)
{
    int r = 1;
    if (k > 25) {
        if (k <= 27)
            r = 0;
        else {
            r = 2;
            if (k <= 34)
                r = 1;
        }
    }
    return r;
}

float fn_8024D050(Unk80270BA0_X* x, int a, int b, float f1, float f2)
{
    float r;
    if (fn_8024D144(x))
        r = fn_8024D0C4(x, a, f1, f2);
    else
        r = fn_8024D0C4(x, b, f1, f2);
    return r;
}

float fn_8024D0C4(Unk80270BA0_X* x, int a, float f1, float f2)
{
    return fn_801A20F8(((Unk8024B99C_V*)x)->m44C, a, f1, f2);
}

float fn_8024D0F8(Unk80270BA0_X* x, int a)
{
    return fn_801A2158(((Unk8024B99C_V*)x)->m44C, a);
}

int fn_8024D11C(Unk80270BA0_X* x)
{
    return fn_8024D144(x) == 0;
}

int fn_8024D144(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    return fn_801A2034(v->m44C, v->m708) == -1;
}

void fn_8024D178(Unk80270BA0_X* x, int a)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    v->m918 = a;
    v->m91C = lbl_806055DC;
}

void fn_8024D1A4(Unk80270BA0_X* x, const Unk8024B99C_V3* p)
{
    ((Unk8024B99C_V*)x)->m8F8 = *p;
}

char* fn_8024D1C4(Unk80270BA0_X* x)
{
    char* r = 0;
    Unk8027C728_Goal* g = fn_80244C84(x);
    while (g) {
        if (g->m10 == 6) {
            r = g->m18;
            break;
        }
        g = g->m0;
    }
    return r;
}

char* fn_8024D218(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (g) {
        char* r = 0;
        if (g->m10 == 6)
            r = g->m18;
        return r;
    }
    return 0;
}

int fn_8024D260(Unk80270BA0_X* x)
{
    if ((unsigned)((Unk8024B99C_V*)x)->m458 <= 8) {
        if (fn_8024D378(x) != 0)
            return 1;
        char* p = fn_8024D2E8(x);
        if (p) {
            if (*(int*)(p + 0x60) != 0)
                return 1;
        }
        p = fn_8024D330(x);
        if (p) {
            if (*(int*)(p + 0x78) != 0)
                return 1;
        }
    }
    return 0;
}

static inline char* GoalData10(Unk8027C728_Goal* g)
{
    if (g) {
        char* r = 0;
        if (g->m10 == 10)
            r = g->m18;
        return r;
    }
    return 0;
}

char* fn_8024D2E8(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (g) {
        char* r = 0;
        if (g->m10 == 14)
            r = g->m18;
        return r;
    }
    return 0;
}

char* fn_8024D330(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (g) {
        char* r = 0;
        if (g->m10 == 10)
            r = g->m18;
        return r;
    }
    return 0;
}

char* fn_8024D378(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (g) {
        char* r = 0;
        if (g->m10 == 13)
            r = g->m18;
        return r;
    }
    return 0;
}

char* fn_8024D3C0(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (g) {
        char* r = 0;
        if (g->m10 == 5)
            r = g->m18;
        return r;
    }
    return 0;
}

extern "C" int fn_8024D408(Unk80270BA0_X* x)
{
    return (unsigned)((Unk8024B99C_V*)x)->m458 <= 5;
}

int fn_8024D41C(Unk80270BA0_X* x)
{
    return (unsigned)(((Unk8024B99C_V*)x)->m458 - 6) <= 2;
}

int fn_8024D434(Unk80270BA0_X* x)
{
    Unk8027C728_Goal* g = fn_80244C84(x);
    if (fn_8026DD60(x, 0) == 0) {
        char* p = GoalData10(g);
        if (p)
            return (unsigned)(*(int*)(p + 0x4c) - 11) <= 5;
    }
    return 0;
}

void fn_8024DB54() {}

int fn_8024DCFC(int k)
{
    if (k == 17 || k == 18 || k == 30 || k == 24)
        return 1;
    return 0;
}

int fn_8024E194(Unk80270BA0_X* x)
{
    return fn_8024E1B8(x) ^ 1;
}
