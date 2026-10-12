/*
 * Game code, .text 0x802CBD04-0x802CFED4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/chooser.h"
#include "game/tu_802CBD04.h"

extern int lbl_8061ECAC[];
Unk802CC580_T* fn_801A04A8(Unk802CC580_Data* d, int k);
int fn_803272D0(char* tbl, int idx);
extern const char lbl_805E2568[];
extern const char lbl_805E331C[];
extern const char lbl_805E32DC[];
extern const char lbl_805E32E8[];
extern const char lbl_805E32F8[];
extern const char lbl_805E3308[];
extern const char lbl_805E3310[];
extern const char lbl_805E3320[];
extern const char lbl_805E3330[];
extern const char lbl_805E3334[];
extern const char lbl_805E3340[];
extern const char lbl_805E26D8[];
extern const char lbl_805E3358[];
extern const char lbl_805E3364[];
extern const char lbl_805E3374[];
extern const char lbl_805E3384[];
extern const char lbl_805E3390[];
extern const char lbl_805E33A8[];
extern const char lbl_805E33C0[];
extern const char lbl_805E33D0[];
extern const char lbl_805E33E4[];
extern const char lbl_805E33FC[];
extern Unk802CF70C_Flags* lbl_8061B8C0;
float fn_802CF5CC(int a, int b, float x, float y, float z);
void fn_802CC0E8(Unk802CC48C* o, Unk802CC48C_Mat* out);

void fn_802CBE5C(Unk802CBD04* o, Unk802CBD04_Vec3* a, Unk802CBD04_Vec3* b, Unk802CBD04_Vec3* c);
void fn_80402A04(int a, int b, Unk802CBD04_Vec3* c, void* d);
void fn_80402B0C(void* m, Unk802CBD04_Vec3* a, Unk802CBD04_Vec3* b);
void fn_802CC748(int e, int a, int b, Unk802CBD04_Vec3* v);
extern "C" void* fn_8037CF5C(Unk8037C7FC* c, unsigned int hash, void* obj);

float fn_802CBD90(Unk802CBD04* o)
{
    return (o->mA4 / (1.0f - o->mA8)) * o->mAC;
}

int fn_802CBDB4(Unk802CBD04* o)
{
    return o->mD4;
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

inline int Unk802CC580_Get(Unk802CC580_Data* d, unsigned idx)
{
    if (idx <= 0xC)
        return d->m65C[idx];
    return 0;
}
int fn_802CC580(Unk802CBD04* o, int k, unsigned idx)
{
    Unk802CC580_T* t = fn_801A04A8(o->mD8, k);
    if (t == 0) {
        t = fn_801A04A8(o->mD8, 1);
    }
    int r;
    if (t->m44 == 0) {
        r = Unk802CC580_Get(o->mD8, idx);
    } else {
        r = fn_803272D0(o->mD8->m50, idx);
    }
    return r;
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

void* fn_802CF168(void* o)
{
    return fn_8037CF5C(fn_8037C7FC(), 0xB38E54D3, o);
}

void fn_802CF1A4(void* o)
{
    fn_8037C7FC()->fn_8037CE98(0xB38E54D3, (int)o, 0);
}

void fn_802CF368(Unk802CF368_Self* o)
{
    o->fn_8037B458(lbl_805E32DC, &o->m8, lbl_805E2568, lbl_805E26D8);
    o->fn_8037B458(lbl_805E32E8, &o->mC, lbl_805E2568, lbl_805E26D8);
    o->fn_8037B458(lbl_805E32F8, &o->m4, lbl_805E2568, lbl_805E26D8);
    o->fn_8037B458(lbl_805E3308, &o->m10, lbl_805E2568, lbl_805E26D8);
    o->fn_8037B458(lbl_805E3310, &o->m14, lbl_805E2568, lbl_805E331C);
    o->fn_8037B458(lbl_805E3320, &o->m18, lbl_805E2568, lbl_805E26D8);
    o->fn_8037B458(lbl_805E3330, &o->m1C, lbl_805E2568, lbl_805E331C);
    o->fn_8037B548(lbl_805E3334, 0);
    o->fn_8037B548(lbl_805E3340, 0);
}

Unk802CF484::Unk802CF484()
{
    m0 = 0;
    m4 = 0.0f;
    m8 = 0.0f;
    mC = 0.0f;
    m10 = 0.0f;
    m14 = 0.0f;
    m18 = 0.0f;
}

void fn_802CF4B4(Unk802CF4B4_Self* self, Unk8037B3E8* reg)
{
    reg->fn_8037B7E8(lbl_805E3358);
    reg->fn_8037B458(lbl_805E3364, (int*)self, lbl_805E26D8, lbl_805E26D8);
    reg->fn_8037B50C(lbl_805E3374, &self->m4, lbl_805E3384, 0);
    reg->fn_8037B50C(lbl_805E3390, &self->m8, lbl_805E3384, 0);
    reg->fn_8037B50C(lbl_805E33A8, &self->mC, lbl_805E33C0, 0);
    reg->fn_8037B50C(lbl_805E33D0, &self->m10, lbl_805E3384, 0);
    reg->fn_8037B50C(lbl_805E33E4, &self->m14, lbl_805E3384, 0);
    reg->fn_8037B50C(lbl_805E33FC, &self->m18, lbl_805E33C0, 0);
    reg->fn_8037B830(lbl_805E3358);
}

void fn_802CF70C(Unk802CF70C_In* a, Unk802CF70C_Out* o, int p, int q)
{
    if (a->m0 != 0 && lbl_8061B8C0->m24 == 0) {
        o->x = o->x + fn_802CF5CC(p, q, a->m8, a->mC, a->m4);
        o->y = o->y + fn_802CF5CC(p, q, a->m14, a->m18, a->m10);
    }
}
