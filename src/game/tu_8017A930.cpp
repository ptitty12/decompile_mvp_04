/*
 * Game code, .text 0x8017A930-0x8017D640 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8017A930.h"

void fn_8017AF7C(Unk8017A930_T* p)
{
    fn_80176B90(p->m3A8);
}

void fn_8017B0A4(Unk8017A930_T* p)
{
    if (p->m4->m6F4 == 0) {
        fn_8017671C(p->m3A8);
    }
}

void fn_8017B47C(Unk8017A930_T* p)
{
    fn_801DBB50(p->m3B8);
}

void fn_8017BB18(Unk8017A930_T* p)
{
    fn_801BB800(p->m3BC);
}

void fn_8017BB3C(Unk8017A930_T* p)
{
    fn_801DBCB4(p->m3B8);
}

void fn_8017C72C(Unk8017A930_T* p)
{
    p->m418 = 1;
    fn_80235AD4(p->m3B0);
}

void fn_8017C808(Unk8017A930_T* p)
{
    fn_80176F04(p->m3A8);
}

void fn_8017C82C(Unk8017A930_T* p)
{
    fn_801DC918(p->m3B8);
    fn_80235A40(p->m3B0);
}

int fn_8017C8C0(Unk8017A930_T* p)
{
    return p->m14;
}

int fn_8017C8C8(Unk8017A930_T* p)
{
    return p->m18;
}

int fn_8017C94C(Unk8017A930_T* p)
{
    return p->m414;
}

int fn_8017C954(Unk8017A930_T* p)
{
    Unk8017C954_Rec* r = p->m4->m6F8->m14;
    return r->m1CCB + r->m1CCA * 4;
}

void fn_8017CF00(Unk8017A930_T* p)
{
    int old = p->m3DC;
    p->m3DC = 2;
    p->m3E0 = old;
}
