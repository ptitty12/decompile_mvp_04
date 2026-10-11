/*
 * Game code, .text 0x80246D04-0x8024B99C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024B99C.h"
#include "game/chooser.h"

extern const float lbl_805D93D0;
extern const float lbl_805D93D4;
extern const float lbl_805D93D8;
extern const float lbl_805D93DC;
extern const float lbl_805D93E0;
extern const float lbl_805D93E4;
extern const float lbl_805D93E8;
extern const float lbl_805D93EC;
extern const float lbl_805D93F0;
extern const float lbl_805D93F4;
extern const float lbl_805D9484;
void fn_80248370(Unk80270BA0_X* x, Unk80273498_Vec3* p, int a, int b, int c, int d);
void fn_80254784(void* p);

extern const float lbl_805D93AC;
extern const float lbl_805D93B0;
extern const float lbl_805D93B4;
extern const float lbl_805D93CC;
extern const float lbl_805D9440;
extern float lbl_8061D4B4;
void fn_8014E498(Unk80273498_Vec3 v);
float fn_80249070(Unk80270BA0_X* x);
void fn_80249750(Unk80270BA0_X* x);
void fn_80249B40(Unk80270BA0_X* x, Unk80273498_Pos* p, int a, int b, float f);
void fn_80249D64(Unk80270BA0_X* x, int a);
float fn_8023C868(Unk80270BA0_X* x);

void fn_80247858(Unk80270BA0_X* x)
{
    fn_8014E498(x->m60);
}

float fn_80248F70(Unk80270BA0_X* x, float f)
{
    float a = ((Unk8024B99C_V*)x)->m8EC;
    if (((Unk8024B99C_V*)x)->m458 != -1) {
        float r = fn_8023C868(x);
        a = a * r;
    }
    return a * f;
}

float fn_80248FC8(Unk80270BA0_X* x, int k)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    float r = lbl_805D93AC;
    switch (k) {
    case 3:
    case 4:
        r = v->m72C;
        break;
    case 2:
        r = v->m728;
        break;
    case 1:
        r = v->m724;
        break;
    case 0:
        r = v->m720;
        break;
    }
    return r;
}

float fn_8024902C()
{
    float r = lbl_805D93B0;
    return r;
}

float fn_80249048()
{
    float r = lbl_805D93B4;
    return r;
}

float fn_80249064()
{
    return lbl_8061D4B4;
}

float fn_80249188(Unk80270BA0_X* x, float f)
{
    float c = lbl_805D93CC;
    float p = fn_80249070(x);
    float r = c + f * (p - c);
    return r;
}

void fn_802491D8(Unk80270BA0_X* x)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    Unk8022FE34_Ctx* c = v->m44C;
    if (c && c->m6F4 != 1 && v->m708 != 2) {
        int m = *(int*)((char*)x + 0x704);
        if (m != 0) {
            char* row = (char*)c->m6F8->m14 + v->m708 * 0xE64;
            if (m != *(int*)(row + 0x1A0))
                fn_80254784((char*)x + 0x58C);
        }
    }
    float f = fn_80249070(x);
    v->m728 = f * lbl_805D93D0;
    v->m724 = f * lbl_805D93D4;
    v->m72C = f;
    v->m720 = f * lbl_805D93D8;
}

float fn_80249298(Unk80270BA0_X* x, int a, int b)
{
    float r = lbl_805D93DC;
    switch (a) {
    case 0:
        r = lbl_805D93E0;
        break;
    case 1:
    case 2:
    case 3:
        r = lbl_805D93E4;
        break;
    case 4:
    case 7:
        r = lbl_805D93E8;
        break;
    case 5:
    case 8:
        r = lbl_805D93EC;
        break;
    case 6:
    case 9:
    case 10:
        r = lbl_805D93F0;
        break;
    case 11:
        r = lbl_805D93F4;
        break;
    }
    if (b != 0)
        return r * r;
    return r;
}

/* near-miss: only the order of 'stw r4,0xae0' vs 'lwz r8,0x44c' differs (3 source orderings tried) */
void fn_802496BC(Unk80270BA0_X* x, int a)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    v->mAE0 = a;
    v->mAE4 = (float)x->m44C->m4C * lbl_805D9440;
    v->mAE8 = 1;
    fn_80249750(x);
}

void fn_80249724(Unk80270BA0_X* x)
{
    if (((Unk8024B99C_V*)x)->mAE8 != 0)
        fn_80249750(x);
}

void fn_80249B08(Unk80270BA0_X* x, int a, float f)
{
    fn_80249B40(x, x->m44C->m6CC, a, 1, f);
}

/* near-miss: retail compares s < 1 (cmpwi 1; bltlr); g++ folds s >= 1 into s > 0 (4 forms tried) */
int fn_80249D44(Unk80270BA0_X* x)
{
    int s = ((Unk8024B99C_V*)x)->mB0C;
    int r = 0;
    if (s <= 6) {
        if (s >= 1)
            r = 1;
    }
    return r;
}

static inline void SetB3C(Unk80270BA0_X* x, int a)
{
    ((Unk8024B99C_V*)x)->mB3C.m3 = a;
}

void fn_80249D64(Unk80270BA0_X* x, int a)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (a != 0) {
        int s = v->mB0C;
        if (s != 0) {
            if (s == 2)
                v->mB0C = 1;
        } else {
            v->mB0C = 1;
            v->mB10 = lbl_805D9484;
        }
    } else {
        switch (v->mB0C) {
        case 1:
        case 4:
        case 5:
            v->mB0C = 2;
            break;
        case 3:
            v->mB10 = v->mB14;
            v->mB0C = 2;
            break;
        case 6:
            v->mB0C = a;
            break;
        }
    }
}

void fn_80249DF8(Unk80270BA0_X* x, int a)
{
    SetB3C(x, a);
    fn_80249D64(x, a);
}

void fn_8024A550(Unk80270BA0_X* x, float f)
{
    Unk8024B99C_V* v = (Unk8024B99C_V*)x;
    if (f != v->mB14) {
        v->mB10 *= f / v->mB14;
        v->mB14 = f;
    }
}

void fn_8024A584(Unk80270BA0_X* x, float f)
{
    ((Unk8024B99C_V*)x)->mB18 = f;
}

void fn_8024A674() {}


void fn_80248450(Unk80270BA0_X* x, int a, int b, int c)
{
    fn_80248370(x, &x->m60, a, b, c, 0);
}
