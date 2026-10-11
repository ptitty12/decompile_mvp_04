/*
 * Game code, .text 0x8025877C-0x8025B59C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_Q Q;
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;

extern "C++" {
Q* fn_802570D4(M* self);
P* fn_80257B40(M* self);
P* fn_80257BD0(M* self, P* p, int a);
int fn_80254A34(A* a);
int fn_80254B60(A* a);
int fn_80254984(A* a);
void fn_8026BAB8(I* i);
void fn_8025D054(I* i, int a);
void fn_802684B0(void* p);
void fn_8026B9D8(I* i);
void fn_80259E3C(void* p);
void fn_8025596C(A* a, int v);
void fn_80266464(void* p, int a);
void fn_8026A0F4(void* p, int a);
void fn_80268684(void* p, int a);
void fn_802686E4(void* p, int a);
float fn_80259EE8(void* p, int a, int b, int c);
void fn_80268DB0(void* p);
void fn_80265D24(I* i, int a);
void fn_80377408(void* p);
}

int fn_80258C90(M* self)
{
    int r;
    if (*((unsigned char*)fn_802570D4(self)->m6F8->m14 + 0x1CC9) == 3) {
        r = 0;
    } else {
        int f = 0;
        P* p = fn_80257B40(self);
        while (p != 0) {
            if (fn_80254A34(&p->m58C) != 0) {
                f = 1;
                break;
            }
            p = fn_80257BD0(self, p, 0);
        }
        r = f;
    }
    return r;
}

int fn_80258D18(M* self)
{
    int r;
    if (*((unsigned char*)fn_802570D4(self)->m6F8->m14 + 0x1CC9) == 3) {
        r = 0;
    } else {
        int f = 0;
        P* p = fn_80257B40(self);
        while (p != 0) {
            if (fn_80254B60(&p->m58C) != 0) {
                f = 1;
                break;
            }
            p = fn_80257BD0(self, p, 0);
        }
        r = f;
    }
    return r;
}

int fn_80258DA0(M* self)
{
    int r;
    if (*((unsigned char*)fn_802570D4(self)->m6F8->m14 + 0x1CC9) == 3) {
        r = 0;
    } else {
        int f = 0;
        P* p = fn_80257B40(self);
        while (p != 0) {
            if (fn_80254984(&p->m58C) != 0) {
                f = 1;
                break;
            }
            p = fn_80257BD0(self, p, 0);
        }
        r = f;
    }
    return r;
}

int fn_80258E28(M* self)
{
    return self->m4->m1FC == 3;
}

void fn_80258E40(M* self)
{
    fn_8026BAB8(self->m4);
}

void fn_80258E64()
{
}

void fn_80258E68(M* self, int a)
{
    self->m18 = a;
}

void fn_80258E70(M* self)
{
    fn_8025D054(self->m4, 6);
}

void fn_80258E98(M* self)
{
    self->m14 = 0;
    self->m18 = 0;
}

void fn_802591CC()
{
}

void fn_802592B4(M* self)
{
    if (self->m4->m1FC != 8)
        fn_8025D054(self->m4, 9);
}

void fn_802592E8(M* self)
{
    fn_802684B0((char*)self->m4 + 0x124);
    fn_8026B9D8(self->m4);
    fn_80259E3C((char*)self->m4 + 0x468);
}

int fn_80259330(M* self)
{
    return self->m4->m128;
}

int fn_80259434(M* self)
{
    return self->m4->m1FC;
}

void fn_8025956C(M* self, P* p)
{
    if (p->m458 == 9 && p->m618->m838 != 0x1463E9BA)
        fn_8025596C(&p->m58C, 0);
}

void fn_802595B8(M* self, int a)
{
    fn_80266464((char*)self->m4 + 4, a);
}

void fn_80259C00(M* self, int a)
{
    fn_8026A0F4((char*)self->m4 + 0x190, a);
}

void fn_80259C28(M* self, int a)
{
    fn_80268684((char*)self->m4 + 0x124, a);
}

void fn_80259C50(M* self, int a)
{
    fn_802686E4((char*)self->m4 + 0x124, a);
}

float fn_80259DB4(M* self, int a)
{
    float t = fn_80259EE8((char*)self->m4 + 0x468, 0, a, -1);
    return t;
}

void fn_80259DF0(M* self)
{
    fn_80268DB0((char*)self->m4 + 0xBC);
}

void fn_80259E18(M* self, int a)
{
    fn_80265D24(self->m4, a);
}

void* fn_80259E90(void* x)
{
    fn_80259E3C(x);
    return x;
}

void fn_80259EC0(void* x, int a)
{
    if (a & 1)
        fn_80377408(x);
}

int fn_8025A664(void* self, P* p)
{
    return p->m458 - 9;
}

int fn_8025AC04()
{
    return 0;
}
