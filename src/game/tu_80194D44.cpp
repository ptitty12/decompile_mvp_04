/*
 * Game code, .text 0x80194D44-0x80198DB8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80194D44.h"
//@BODY
//@80194D44
extern "C" int fn_80194D44(Unk80194D44_O* o)
{
    int r = fn_80193AB0(o);
    fn_8019427C(o);
    o->m58 = o->m58 + 0.016666668f;
    return r;
}

//@80194D94
extern "C" int fn_80194D94(Unk80194D44_O* o)
{
    if (o->m70 != 0)
        return 0;
    if (o->m20 == 6 || o->m20 == 2)
        o->m70 = 1;
    return 1;
}

//@80195568
Unk80195404::~Unk80195404()
{
    if (mAB0)
        delete[] mAB0;
    mAB0 = 0;
}

//@80195928
/* near-miss: 19/19 insns, 5 slots differ: only the registers of the zeroing loop (offset
 * in r11 / base in r10 in retail, swapped here). The clamp shape matches. */
extern "C" void fn_80195928(Unk80194D44_O* o, int i)
{
    for (int k = 0; k < 3; k++)
        o->mAF8[k] = 0;
    if (i <= 2) {
        if (i < 0)
            i = 0;
    } else
        i = 2;
    o->mAF8[i] = 1;
}

//@80195E60
/* near-miss: 32 vs 30 insns: retail reloads the state word at +0x7C for each test (three
 * lwz) and tests the +0x6C field before the second +0x7C compare; here the loads are CSE'd. */
extern "C" int fn_80195E60(Unk80194D44_O* o, Unk80195E60_Q* q)
{
    if (o->m4C == 0)
        return 0;
    Unk80195E60_P* p = (Unk80195E60_P*)((char*)o + 0x58);
    if (p->m24 == 3 && o->m78 == 3)
        return 0;
    if (p->m68 != 0 || p->m6C != 0)
        return 1;
    if (p->m24 == 3 && q->m38 == 0)
        return 1;
    return (p->m24 ^ 2) == 0;
}

//@80195EE0
extern "C" float fn_80195EE0(Unk80194D44_O* o)
{
    if (fn_80195E60(o, (Unk80195E60_Q*)((char*)o + 0xAB4))) {
        Unk80195E60_P* p = (Unk80195E60_P*)((char*)o + 0x58);
        if (p->m68 != 0 || p->m24 == 2)
            return 0.1f;
        return 0.25f;
    }
    return o->m34;
}

//@80195F50
extern "C" void fn_80195F50(Unk80194D44_O* o, float t)
{
    float x = fn_80195EE0(o);
    if (fn_80195FD8(o, t) == 1) {
        float d = t + o->m30 - o->m48;
        if (!(d <= x))
            d = x;
        fn_8019601C(o, d);
    }
}

//@80195FD8
extern "C" int fn_80195FD8(Unk80194D44_O* o, float t)
{
    float d = o->m48 - t;
    if (!(d > o->m2C)) {
        if (o->mC8 == 0)
            return 1;
    }
    return 0;
}

//@801974C4
/* near-miss: 38 vs 37 insns: same call and argument shuffle, but retail copies four of the
 * incoming argument registers into r27..r30 up front (an extra saved register and moves via
 * r3) where this keeps them in volatile registers. The float spills match. */
extern "C" int fn_801974C4(int a0, Unk80188698** pp, int a2, int a3, int a4, int a5, int a6, int a7,
    float f0, float f1, float f2, float f3, float f4)
{
    Unk80188698* o = *pp;
    fn_8019D03C(a0, *(void**)((char*)o->m44C + 0x6C8), o, a2, a3, a4, a5, a6, a7, f0, f1, f2, f3, f4);
    return a0;
}

//@8019755C
extern "C" void fn_8019755C(Unk8019755C_Data* self, int chrg)
{
    self->m90 = lbl_8065F848;
    if (self->m5C) {
        fn_80377488(self->m5C);
        self->m5C = 0;
    }
    if (self->m60) {
        fn_80377488(self->m60);
        self->m60 = 0;
    }
    if (self->m64) {
        fn_80377488(self->m64);
        self->m64 = 0;
    }
    if (self->m68) {
        fn_80377488(self->m68);
        self->m68 = 0;
    }
    if (chrg & 1)
        fn_80377408(self);
}

//@80197B88
extern "C" void fn_80197B88(Unk80197B88_O* o, Unk80197B88_P* p, void* out)
{
    Unk8018A254_Ret m;
    fn_803DF4E4(&m, p->m48 * 57.295776f, p->m3C, p->m40, p->m44);
    fn_803DFD90(&m, p->m0, p->m4, p->m8);
    fn_803DF028(&m, o->m6C, o->m5C, 12, out, 12);
}

//@80197D94
extern "C" int fn_80197D94(float* a, float* b)
{
    if (*a < *b)
        return -1;
    return *a > *b;
}

//@80198188
extern "C" int fn_80198188(Unk80198188_Ring* r)
{
    int cur = r->mC;
    if (cur == -1)
        return -1;
    int next = (cur + 1) % r->m0;
    if (*(int*)(r->m4 + next * 128 + 0x60) != 0)
        return next;
    return 0;
}

//@80198C18
extern "C" void fn_80198C18(Unk80198C18_Obj* self, int chrg)
{
    self->mB8 = lbl_806603D8;
    self->m368 = lbl_806603B0;
    char* s3 = self->m3FC;
    self->m98 = lbl_80660468;
    *(const void**)(s3 + 0x10) = lbl_806604C8;
    if (*(void**)(s3 + 4))
        fn_80377488(*(void**)(s3 + 4));
    if (*(void**)(s3 + 8))
        fn_80377488(*(void**)(s3 + 8));
    void* sub = &self->m360;
    *(const void**)((char*)sub + 8) = lbl_80649DB8;
    fn_80378620(sub, 0);
    fn_8026C864(self, chrg);
}

//@80198CC0
/* near-miss: 62/62 insns, ~20 slots differ: all instructions match; only register numbers
 * (retail: ring pointer r31, shared zero/offset r29, one r28; here r28/r31/r29) and the order of
 * the field stores differ. Declaring `off` before the stores gave retail's shared zero. */
extern "C" void fn_80198CC0(Unk80198CC0_Obj* o)
{
    int off = 0;
    fn_8026C8FC(o);
    Unk80198CC0_Ring* r = &o->m3FC;
    o->m0 = 0;
    o->m6C = 1;
    o->m7C = lbl_8069428C;
    fn_803DF74C(&o->m3A0);
    o->m37C = 1;
    o->m384 = 0;
    o->m388 = 0;
    o->m36C = 0;
    o->m370 = 1;
    o->m374 = 0;
    o->m378 = 0;
    o->m380 = 0;
    fn_80198DD8((Unk80198E5C_Obj*)o, 0);
    fn_8035A900(r);
    for (int i = 0; i < r->m0; i++, off += 128) {
        char* e = r->m4 + off;
        *(float*)e = 0.0f;
        fn_803DF74C((Unk8018A254_Ret*)(e + 0x20));
        *(int*)(e + 0x60) = 0;
    }
    r->mC = -1;
}

