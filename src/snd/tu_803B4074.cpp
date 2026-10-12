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

extern "C" unsigned int fn_803B4610(int i)
{
    return lbl_80626418[i];
}
