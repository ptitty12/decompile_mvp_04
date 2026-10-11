/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8005C514-0x8005D268 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80052794.h"

int fn_8005C514(Unk8005C514_Obj* o, int a, int b)
{
    int ok = 0;
    if (o->m0 == 1) {
        ok = o->m2C >= 0;
    }
    if (ok != 0) {
        int k = lbl_805B09F4[a].mD4;
        if (fn_8005C344(o, k) != 0) {
            return fn_8005A3E8(o->m30[k].m0, a, b);
        }
    }
    return -1;
}

int fn_8005C5B0(Unk8005C514_Obj* o, int a, int b, int c)
{
    int ok = 0;
    if (o->m0 == 1) {
        ok = o->m2C >= 0;
    }
    if (ok != 0) {
        int k = lbl_805B09F4[a].mD4;
        if (fn_8005C344(o, k) != 0) {
            return fn_8005A4F8(o->m30[k].m0, a, b, c);
        }
    }
    return -1;
}

int fn_8005C654(Unk8005C514_Obj* o, int a, int b, int c)
{
    int ok = 0;
    if (o->m0 == 1) {
        ok = o->m2C >= 0;
    }
    if (ok == 1 && fn_8005C344(o, a) == 1) {
        return fn_8005A674(o->m30[a].m0, b, c);
    }
    return 0;
}

int fn_8005C6E0(Unk8005C514_Obj* o, int a)
{
    int r = -1;
    int ok = 0;
    if (o->m0 == 1) {
        ok = o->m2C >= 0;
    }
    if (ok == 1 && fn_8005C344(o, 1) == 1) {
        r = fn_8005A780(o->m30[1].m0, a);
    }
    return r;
}

void fn_8005C75C(Unk8005C514_Obj* o, int a, int b)
{
    int ok = 0;
    if (o->m0 == 1) {
        ok = o->m2C >= 0;
    }
    if (ok == 1) {
        int r = fn_8005C344(o, 1);
        if (r == 1) {
            fn_8005A814(o->m30[a].m0, b);
            o->m4 = r;
            o->m8 = 0;
        }
    }
}

int fn_8005C7E8(Unk8005C514_Obj* o, int a)
{
    int r = 3;
    if (o->m30[a].m0 != 0) {
        r = fn_8005A8B4(o->m30[a].m0);
    }
    return r;
}

int fn_8005C828(Unk8005C514_Obj* o, int a)
{
    int r = -1;
    if (o->m30[a].m0 != 0) {
        r = fn_8005A94C(o->m30[a].m0);
    }
    return r;
}

void fn_8005C868(Unk8005C514_Obj* o)
{
    if (o->m0 == 1 && o->m4 == 1) {
        int any = 0;
        o->m8 = o->m8 + 1;
        if (o->m8 > 4) {
            for (int i = 0; i < 4; i++) {
                if (o->m30[i].m0 != 0) {
                    fn_8005A240(o->m30[i].m0);
                    if (fn_8005A8B4(o->m30[i].m0) == 2) {
                        any = 1;
                        if (fn_8005AB44(o->m30[i].m0) == 0) {
                            fn_8005A9A8(o->m30[i].m0);
                        }
                    }
                }
            }
            if (any == 0) {
                o->m4 = 0;
            }
            o->m8 = 0;
        }
    }
}

int fn_8005C924(int self, int a, int b)
{
    return fn_803AB528(lbl_805AE420[b].e[a].m18, lbl_805AE420[b].e[a].m1C) + lbl_805AE420[b].e[a].m20;
}

Unk8005C97C_Q* fn_8005C97C(Unk8005C97C_Q* self, unsigned n)
{
    self->m0 = n;
    self->mC = &lbl_80649768;
    self->m4 = 0;
    self->m8 = 0;
    self->m8 = new (0) Unk8005C97C_Elem[n];
    fn_803EE7BC();
    return self;
}

Unk8005CA60_Q::~Unk8005CA60_Q()
{
    if (m8 != 0) {
        delete[] m8;
        m8 = 0;
    }
}

void fn_8005CAC0(Unk8005C514_Obj* o)
{
    o->m4 = 0;
}

/* near-miss (7 slots): same instruction stream as retail, but the local
 * allocator gives the byte index r0 and the element address r9 where retail
 * has r9 and r11, which shifts the base/counter registers too. The same loop
 * shape is in fn_80053220 and fn_80054684. */
static inline int SumRow(Unk80052794_Row* r)
{
    int s = 0;
    for (int i = 0; i < 0x80; i++) {
        s += r->vals[(unsigned char)i];
    }
    return s;
}

Unk8005C97C_Elem* fn_8005CD20(Unk8005C97C_Q* q)
{
    unsigned i = 0;
    unsigned cnt = q->m4;
    float v = q->m8[0].m0;
    if (i < cnt && !(q->m8[0].m0 < v)) {
        do {
            i++;
        } while (i < cnt && q->m8[i].m0 >= v);
    }
    unsigned r;
    if (i != 0) {
        r = fn_8040ABA0() % i;
    } else {
        r = 0;
    }
    return &q->m8[r];
}

int fn_8005CDC4(Unk80057204_Mgr* self, Unk80052794_Obj* obj)
{
    Unk80052794_Row* t = obj->m130->m44C->m6F8->m14;
    int s1 = SumRow(&t[0]);
    int s2 = SumRow(&t[1]);
    int d = s1 - s2;
    return (d < 0 ? -d : d) <= 3;
}

/* near-miss (6 slots): same compares; retail keeps the first constant in f13 and
 * the second in f1 (f1 then overwritten by fmr), this picks other float registers. */
float fn_8005CE4C(Unk80057204_Mgr* self, float x)
{
    if (x == lbl_805ADC6C) {
        return lbl_805ADC70;
    }
    if (x == lbl_805ADC70) {
        return lbl_805ADC6C;
    }
    return lbl_805ADC70;
}

float fn_8005CE90(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    float v = lbl_805ADC74;
    if (fn_8005CDC4(self, obj) != 0) {
        v = lbl_805ADC78;
    }
    return v;
}

float fn_8005CED8(void)
{
    return lbl_805ADC7C;
}

float fn_8005CEE4(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    Unk80052794_S6F8* t = obj->m130->m44C->m6F8;
    float v = lbl_805ADC80;
    if (fn_80097520(&t->m14[obj->m3B4], obj->m3B0->m704) != 0) {
        v = lbl_805ADC84;
    }
    return v;
}

float fn_8005CF4C(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    int k = obj->m130->m44C->m6F8->mC->m28;
    if (k == 0x19 || k == 0xA || k == 0x27 || k == 0x18 || k == 0x1E) {
        return lbl_805ADC88;
    }
    return lbl_805ADC8C;
}

float fn_8005CFA0(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    Unk80052794_Row* base = obj->m130->m44C->m6F8->m14;
    int side = 0;
    if (*(int*)((char*)base + 0x1CD0) != 0) {
        side = 1;
    }
    if (fn_80097520(&base[side], obj->m3B0->m704) != 0) {
        return lbl_805ADC90;
    }
    return lbl_805ADC94;
}

float fn_8005D010(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    Unk80052794_Row* base = obj->m130->m44C->m6F8->m14;
    int side = 0;
    if (*(int*)((char*)base + 0x1CD0) != 0) {
        side = 1;
    }
    if (fn_80097520(&base[side], obj->m3B0->m704) != 0) {
        return lbl_805ADC98;
    }
    return lbl_805ADC9C;
}

float fn_8005D080(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    if (obj->m3B0->m388 == 2) {
        return lbl_805ADCA0;
    }
    return lbl_805ADCA4;
}

float fn_8005D0A8(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    Unk80052794_S130* o = obj->m130;
    int k = 0;
    if (o->m458 != 1) {
        k = o->m38C;
    }
    if (k == 1) {
        return lbl_805ADCA8;
    }
    return lbl_805ADCAC;
}

float fn_8005D0E0(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    Unk80052794_S130* o = obj->m130;
    int k = 0;
    if (o->m458 != 1) {
        k = o->m38C;
    }
    if (k == 0) {
        return lbl_805ADCB0;
    }
    return lbl_805ADCB4;
}

float fn_8005D118(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    if (fn_8001F984(obj) == 1) {
        return lbl_805ADCB8;
    }
    return lbl_805ADCBC;
}

float fn_8005D158(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    void* p = fn_80056FAC(self, b);
    if (fn_803440D0(p) != 0) {
        return lbl_805ADCC0;
    }
    return lbl_805ADCC4;
}

float fn_8005D19C(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    void* p = fn_8005713C(self, b);
    if (fn_803440D8(p) != 0) {
        return lbl_805ADCC8;
    }
    return lbl_805ADCCC;
}

float fn_8005D1E0(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    void* p = fn_800571A0(self, b);
    if (fn_803440E0(p) != 0) {
        return lbl_805ADCD0;
    }
    return lbl_805ADCD4;
}

float fn_8005D224(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    void* p = fn_80057010(self, b);
    if (fn_803440E8(p) != 0) {
        return lbl_805ADCD8;
    }
    return lbl_805ADCDC;
}
