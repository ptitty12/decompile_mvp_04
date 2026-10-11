/*
 * Game code, .text 0x80347F7C-0x80349880 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803401A8.h"

extern char lbl_806870CC[];
extern char lbl_806870D4[];
extern char lbl_806870DC[];
extern char lbl_806870E4[];
extern char lbl_806870EC[];
extern char lbl_806870F4[];
extern char lbl_80686F6C[];
extern char lbl_80686FCC[];
extern char lbl_80686FFC[];
extern char lbl_80687054[];
extern char lbl_806870FC[];
extern char lbl_80687104[];
extern char lbl_8068710C[];
extern char lbl_80687114[];
extern char lbl_8068711C[];
extern char lbl_80687124[];
extern char lbl_8068712C[];
extern char lbl_80687134[];
extern char lbl_8068713C[];
extern char lbl_80687144[];
extern char lbl_8068714C[];
extern char lbl_80687154[];
extern char lbl_8068715C[];
extern char lbl_80687164[];
extern char lbl_8068716C[];
extern char lbl_80687174[];
extern char lbl_8068717C[];
extern char lbl_80687184[];
extern char lbl_80686E1C[];
extern char lbl_8068721C[];
extern char lbl_80687234[];
extern char lbl_8068723C[];
extern char lbl_806871F4[];
extern char lbl_8068722C[];
extern char lbl_8068718C[];
extern char lbl_80687194[];
extern char lbl_806871A4[];
extern char lbl_806871DC[];
extern char lbl_806871E4[];
extern char lbl_806871EC[];

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

Unk803B9D60_Rec* fn_80347F7C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870CC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348004(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870D4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034808C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870DC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348114(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870E4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034819C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870EC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348224(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870F4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803482AC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F6C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348334(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FCC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803483BC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686FFC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348444(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687054, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803484CC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806870FC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348554(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687104, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803485DC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068710C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348664(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687114, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803486EC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068711C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348774(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687124, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803487FC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068712C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348884(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687134, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034890C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068713C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348994(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687144, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348A1C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068714C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348AA4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687154, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348B2C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068715C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348BB4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687164, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348C3C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068716C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348CC4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687174, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348D4C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068717C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348DD4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687184, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348E5C(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0xc8) v = 0xc8;
    r->mC = v;
    fn_803BA240(lbl_80686E1C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80348F60(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x3e8) t = 0x3e8;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0x3e8) v = 0x3e8;
    r->mC = v;
    fn_803BA240(lbl_8068721C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349064(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x64) t = 0x64;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0x64) u = 0x64;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0xbb8) v = 0xbb8;
    r->mC = v;
    fn_803BA240(lbl_80687234, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034915C(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x64) t = 0x64;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0x64) u = 0x64;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0xbb8) v = 0xbb8;
    r->mC = v;
    fn_803BA240(lbl_8068723C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349254(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806871F4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803492DC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068722C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349364(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x3e8) t = 0x3e8;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0x3e8) v = 0x3e8;
    r->mC = v;
    fn_803BA240(lbl_8068718C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349468(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x3e8) t = 0x3e8;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0x3e8) v = 0x3e8;
    r->mC = v;
    fn_803BA240(lbl_80687194, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034956C(Unk803B9D60_In3* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x10, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4, z = s->m8;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x3e8) t = 0x3e8;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    int v = z;
    if (v < 0) v = 0; else if (v > 0x3e8) v = 0x3e8;
    r->mC = v;
    fn_803BA240(lbl_806871A4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349670(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0xc8);
    fn_803BA240(lbl_806871DC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349720(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0xc8);
    fn_803BA240(lbl_806871E4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803497D0(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0xc8);
    fn_803BA240(lbl_806871EC, &r->m4, r);
    return r;
}
