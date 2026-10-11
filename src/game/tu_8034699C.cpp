/*
 * Game code, .text 0x8034699C-0x80347F7C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803401A8.h"

extern char lbl_80686F74[];
extern char lbl_80686F7C[];
extern char lbl_80686F84[];
extern char lbl_80686F8C[];
extern char lbl_80686F94[];
extern char lbl_80686F9C[];
extern char lbl_80686FA4[];
extern char lbl_80686FAC[];
extern char lbl_80686FB4[];
extern char lbl_80686FBC[];
extern char lbl_80686FC4[];
extern char lbl_80686FD4[];
extern char lbl_80686FDC[];
extern char lbl_80686FE4[];
extern char lbl_80686FEC[];
extern char lbl_80686FF4[];
extern char lbl_80687004[];
extern char lbl_8068700C[];
extern char lbl_80687014[];
extern char lbl_8068701C[];
extern char lbl_80687024[];
extern char lbl_8068702C[];
extern char lbl_80687034[];
extern char lbl_8068703C[];
extern char lbl_80687044[];
extern char lbl_8068704C[];
extern char lbl_8068705C[];
extern char lbl_80687064[];
extern char lbl_8068706C[];
extern char lbl_80687074[];
extern char lbl_8068707C[];
extern char lbl_80687084[];
extern char lbl_8068708C[];
extern char lbl_80687094[];
extern char lbl_8068709C[];
extern char lbl_806870A4[];
extern char lbl_806870AC[];
extern char lbl_806870B4[];
extern char lbl_806870BC[];
extern char lbl_806870C4[];

inline int Clamp(int v, int hi)
{
    if (v < 0)
        v = 0;
    else if (v > hi)
        v = hi;
    return v;
}

inline int Clamp2(int v, int lo, int hi)
{
    if (v <= lo - 1)
        v = lo;
    else if (v > hi)
        v = hi;
    return v;
}

Unk803B9D60_Rec* fn_8034699C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F74, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346A24(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F7C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346AAC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F84, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346B34(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F8C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346BBC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F94, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346C44(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F9C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346CCC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FA4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346D54(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FAC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346DDC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FB4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346E64(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0xfa0);
    fn_803BA240(lbl_80686FBC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346F14(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FC4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346F9C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FD4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347024(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FDC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803470AC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FE4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347134(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FEC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803471BC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FF4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347244(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0xfa0);
    fn_803BA240(lbl_80687004, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803472F4(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0xfa0);
    fn_803BA240(lbl_8068700C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803473A4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687014, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034742C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068701C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803474B4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687024, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034753C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068702C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803475C4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687034, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034764C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068703C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803476D4(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0xfa0);
    fn_803BA240(lbl_80687044, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347784(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068704C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034780C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068705C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347894(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687064, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034791C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068706C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803479A4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687074, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347A2C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068707C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347AB4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687084, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347B3C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068708C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347BC4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687094, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347C4C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068709C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347CD4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870A4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347D5C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870AC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347DE4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870B4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347E6C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870BC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80347EF4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870C4, &r->m4, r);
    return r;
}
