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

