/*
 * Game code, .text 0x802CBD04-0x802CFED4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802CBD04.h"

extern int lbl_8061ECAC[];
extern Unk802CF70C_Flags* lbl_8061B8C0;
float fn_802CF5CC(int a, int b, float x, float y, float z);
void fn_802CC0E8(Unk802CC48C* o, Unk802CC48C_Mat* out);

void fn_802CBE5C(Unk802CBD04* o, Unk802CBD04_Vec3* a, Unk802CBD04_Vec3* b, Unk802CBD04_Vec3* c);
void fn_80402A04(int a, int b, Unk802CBD04_Vec3* c, void* d);
void fn_80402B0C(void* m, Unk802CBD04_Vec3* a, Unk802CBD04_Vec3* b);
void fn_802CC748(int e, int a, int b, Unk802CBD04_Vec3* v);
struct Unk8037C7FC;
extern "C" Unk8037C7FC* fn_8037C7FC();
extern "C" void* fn_8037CF5C(Unk8037C7FC* c, unsigned int hash, void* obj);
extern "C" void* fn_8037CE98(Unk8037C7FC* c, unsigned int hash, void* obj, int z);

float fn_802CBD90(Unk802CBD04* o)
{
    return (o->mA4 / (1.0f - o->mA8)) * o->mAC;
}

void fn_802CBDBC(Unk802CBD04* o, int a, int b, int kind)
{
    o->mA0 = (Unk802CC53C_Target*)a;
    switch (kind) {
    case 1:
        o->mDC = 1;
        o->mE0 = 1;
        break;
    case 2:
        o->mDC = 0;
        o->mE0 = 0;
        break;
    case 0:
    default:
        o->mDC = b;
        o->mE0 = 1;
        break;
    }
}

extern "C" void fn_802CBE04(Unk802CBD04* o, Unk802CBD04_Vec3* a, Unk802CBD04_Vec3* b, Unk802CBD04_Vec3* c)
{
    *a = o->m160;
    *b = o->m16C;
    *c = o->m178;
}

void fn_802CC038(Unk802CBD04* o)
{
    fn_802CBE5C(o, &o->m160, &o->m16C, &o->m178);
}

void fn_802CC064(Unk802CBD04* o, Unk802CBD04_Vec3* a, Unk802CBD04_Vec3* b, int c)
{
    char sp8[0x10];
    Unk802CBD04_Vec3 sp18;
    Unk802CBD04_Vec3 sp28;
    Unk802CBD04_Vec3 sp38 = o->m60;
    fn_802CBE04(o, &sp18, a, &sp28);
    fn_80402A04(1, c, &sp38, sp8);
    fn_80402B0C(sp8, a, b);
}

void fn_802CC48C(Unk802CC48C* o, Unk802CC48C_Mat* out)
{
    if (o->m0 == 0) {
        fn_802CC0E8(o, out);
    }
    o->m0 = 1;
    *out = o->m20;
}

void fn_802CC53C(Unk802CBD04* o)
{
    Unk802CC53C_Target* t = o->mA0;
    if (t != 0) {
        t->s11(o);
    }
}

void fn_802CC888(Unk802CBD04* o, int idx, int a, int b, Unk802CBD04_Vec3* v)
{
    int e;
    if ((unsigned)idx <= 0xC) {
        e = o->m65C[idx];
    } else {
        e = 0;
    }
    Unk802CBD04_Vec3 t = *v;
    fn_802CC748(e, a, b, &t);
}

int fn_802CC8EC(Unk802CBD04* o)
{
    Unk802CC53C_Target* t = o->mA0;
    int r = -1;
    if (t != 0) {
        int k = t->s16();
        r = lbl_8061ECAC[k];
    }
    return r;
}

void fn_802CF168(void* o)
{
    fn_8037CF5C(fn_8037C7FC(), 0xB38E54D3, o);
}

void fn_802CF1A4(void* o)
{
    fn_8037CE98(fn_8037C7FC(), 0xB38E54D3, o, 0);
}

void fn_802CF70C(Unk802CF70C_In* a, Unk802CF70C_Out* o, int p, int q)
{
    if (a->m0 != 0 && lbl_8061B8C0->m24 == 0) {
        o->x = o->x + fn_802CF5CC(p, q, a->m8, a->mC, a->m4);
        o->y = o->y + fn_802CF5CC(p, q, a->m14, a->m18, a->m10);
    }
}
