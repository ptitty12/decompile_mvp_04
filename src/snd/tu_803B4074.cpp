/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B4074-0x803B4B40 (code-only unit, 14 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

struct U {
    char pad0[0x4000];
};

#define PUTI(o, v) (*(int*)((char*)self + (o)) = (v))

#include "snd/cmn/sndcmn.h"

extern unsigned short lbl_80626418[];

struct Unk803B4074_Parser {
    unsigned char* m0;
    int m4;
    int m8;
    unsigned char* mC;
    unsigned int m10;
};

extern "C" int fn_803B3F60(const unsigned char* p, int n);

extern "C" int fn_803B4074(Unk803B4074_Parser* s)
{
    int c;
    while (*s->m0 == 0xFC)
        s->m0++;
    c = *s->m0;
    s->m4 = c;
    if (c == 0xFF)
        return 0;
    s->m0++;
    if (c == 0xFD)
        return 1;
    if (c == 0xFE)
        return 1;
    s->m10 = *s->m0;
    if (s->m10 == 0xFF) {
        s->m10 = fn_803B3F60(s->m0 + 1, 4);
        s->m0 = s->m0 + 4;
    }
    s->m0 = s->m0 + 1;
    s->mC = s->m0;
    if (s->m10 <= 4)
        s->m8 = fn_803B3F60(s->m0, s->m10);
    s->m0 = s->m0 + s->m10;
    return 1;
}

extern "C" int fn_803B4160(int shandle, int cutoff)
{
    int setvoice;
    int voice = SNDVOICEI_get(shandle);
    if (voice >= 0) {
        setvoice = -1;
        while (iSNDpatchkey(voice, &setvoice))
            SNDPLATFORM_highpass(setvoice, cutoff);
    }
    return voice;
}

struct Unk803B41C8_Ch {
    char pad0[0x2B];
    signed char m2B;
    char pad2C[0xC];
    float m38;
    char pad3C[4];
    short m40;
    char pad42[6];
    float m48;
    char pad4C[0x1F];
    unsigned char m6B;
    char pad6C[8];
    SCALINGTABLE* m74;
    char pad78[4];
    SCALINGTABLE* m7C;
    char pad80[0x10];
};
extern Unk803B41C8_Ch* lbl_8069CA48;

extern "C" void fn_803B41C8(int ch)
{
    Unk803B41C8_Ch* pv = &lbl_8069CA48[ch];
    float v = (float)pv->m2B * pv->m38 * (float)pv->m40 * 6.200012e-05f;
    pv->m48 = v;
    if (pv->m7C != 0)
        pv->m48 = v * (float)pv->m7C->xlate[pv->m6B] * 0.007874016f;
    if (pv->m74 != 0) {
        float t = pv->m48 * 127.0f;
        int r = (int)(t >= 0.0f ? t + 0.5f : t - 0.5f);
        pv->m48 = (float)pv->m74->xlate[r];
    }
    pv->m48 = pv->m48 * Snd::gMasterVol;
}

extern "C" void fn_803B4330(SNDLINKLIST* list)
{
    list->phead = 0;
    list->ptail = 0;
    list->items = 0;
}

extern "C" void fn_803B4344(SNDLINKLIST* list, SNDLINKNODE* node)
{
    SNDLINKNODE* head = list->phead;
    node->pprev = 0;
    node->pnext = head;
    if (list->phead != 0)
        list->phead->pprev = node;
    else
        list->ptail = node;
    list->phead = node;
    list->items++;
}

extern "C" void fn_803B4380(SNDLINKLIST* list, SNDLINKNODE* node)
{
    node->pnext = 0;
    node->pprev = list->ptail;
    if (list->ptail != 0)
        list->ptail->pnext = node;
    else
        list->phead = node;
    list->ptail = node;
    list->items++;
}

extern "C" SNDLINKNODE* fn_803B43BC(SNDLINKLIST* list)
{
    SNDLINKNODE* node = list->phead;
    if (node != 0) {
        list->phead = node->pnext;
        if (list->phead == 0)
            list->ptail = 0;
        else
            list->phead->pprev = 0;
        list->items--;
    }
    return node;
}

extern "C" void fn_803B43FC(SNDLINKLIST* list, SNDLINKNODE* node)
{
    if (node == list->phead)
        list->phead = node->pnext;
    if (node == list->ptail)
        list->ptail = node->pprev;
    if (node->pprev != 0)
        node->pprev->pnext = node->pnext;
    if (node->pnext != 0)
        node->pnext->pprev = node->pprev;
    list->items--;
}

extern "C" int fn_803B445C(int shandle, int cutoff)
{
    int setvoice;
    int voice = SNDVOICEI_get(shandle);
    if (voice >= 0) {
        setvoice = -1;
        while (iSNDpatchkey(voice, &setvoice))
            SNDPLATFORM_lowpass(setvoice, cutoff);
    }
    return voice;
}

extern "C" float fn_803B44E4(float x)
{
    while (x > 6.2831855f)
        x -= 6.2831855f;
    float x2 = x * x;
    float x4 = x2 * x2;
    float x6 = x2 * x4;
    float x8 = x4 * x4;
    float x10 = x2 * x8;
    float x12 = x6 * x6;
    return x12 * 2.0876758e-09f + (x8 * 2.4801588e-05f + ((x4 * 0.041666668f + (1.0f - x2 * 0.5f)) - x6 * 0.0013888889f) - x10 * 2.755732e-07f);
}

extern "C" float fn_803B457C(float x)
{
    while (x > 6.2831855f)
        x -= 6.2831855f;
    float x2 = x * x;
    float x3 = x2 * x;
    float x5 = x2 * x3;
    float x7 = x2 * x5;
    float x9 = x2 * x7;
    float x11 = x2 * x9;
    float x13 = x2 * x11;
    return x13 * 1.6059e-10f + (x9 * 2.7557319e-06f + (x5 * 0.00833333f + (x - x3 * 0.16666667f) - x7 * 0.0001984127f) - x11 * 2.5052108e-08f);
}

extern "C" unsigned int fn_803B4610(int i)
{
    return lbl_80626418[i];
}

int SNDMEM_gethighwater()
{
    SNDMEMSTATE* mm = sndgs.mm;
    return (mm->heapsize - mm->lowmark) * 100 / mm->heapsize;
}
