/*
 * Game code, .text 0x80344E90-0x8034699C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803401A8.h"

extern char lbl_80686DDC[];
extern char lbl_80686DFC[];
extern char lbl_80686E54[];
extern char lbl_80686E3C[];
extern char lbl_80686DD4[];
extern char lbl_80686EB4[];
extern char lbl_80686EBC[];
extern char lbl_80686E44[];
extern char lbl_80686E6C[];
extern char lbl_80686EDC[];
extern char lbl_80686E94[];
extern char lbl_80686E5C[];
extern char lbl_80686EA4[];
extern char lbl_80686E9C[];
extern char lbl_80686E84[];
extern char lbl_80686E64[];
extern char lbl_80686E74[];
extern char lbl_80686E7C[];
extern char lbl_80686EAC[];
extern char lbl_80686E24[];
extern char lbl_80686E2C[];
extern char lbl_80686F04[];
extern char lbl_80686F0C[];
extern char lbl_80686E8C[];
extern char lbl_80686EE4[];
extern char lbl_80686EEC[];
extern char lbl_80686E34[];
extern char lbl_80686EF4[];
extern char lbl_80686EFC[];
extern char lbl_80686F14[];
extern char lbl_80686F1C[];
extern char lbl_80686F24[];
extern char lbl_80686F2C[];
extern char lbl_80686F34[];
extern char lbl_80686F3C[];
extern char lbl_80686F44[];
extern char lbl_80686F4C[];
extern char lbl_80686F54[];
extern char lbl_80686F5C[];
extern char lbl_80686F64[];

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

Unk803B9D60_Rec* fn_80344E90(Unk803B9D60_In3* s)
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
    fn_803BA240(lbl_80686DDC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80344F94(Unk803B9D60_In2* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0xc, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    fn_803BA240(lbl_80686DFC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345074(Unk803B9D60_In3* s)
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
    if (v < 0) v = 0; else if (v > 0x3e8) v = 0x3e8;
    r->mC = v;
    fn_803BA240(lbl_80686E54, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345178(Unk803B9D60_In3* s)
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
    if (v < 0) v = 0; else if (v > 0x78) v = 0x78;
    r->mC = v;
    fn_803BA240(lbl_80686E3C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034527C(Unk803B9D60_In3* s)
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
    if (v < 0) v = 0; else if (v > 0x96) v = 0x96;
    r->mC = v;
    fn_803BA240(lbl_80686DD4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345380(Unk803B9D60_In3* s)
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
    if (v < 0) v = 0; else if (v > 0x10) v = 0x10;
    r->mC = v;
    fn_803BA240(lbl_80686EB4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345484(Unk803B9D60_In2* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0xc, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    fn_803BA240(lbl_80686EBC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345564(Unk803B9D60_In2* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0xc, Unk803B9D60_Z());
    fn_803B9E08();
    int x = s->m0, y = s->m4;
    int t = x;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    r->m4 = t;
    int u = y;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    r->m8 = u;
    fn_803BA240(lbl_80686E44, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345644(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x258);
    fn_803BA240(lbl_80686E6C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803456F4(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x2);
    fn_803BA240(lbl_80686EDC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803457A4(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x2);
    fn_803BA240(lbl_80686E94, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345854(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x2);
    fn_803BA240(lbl_80686E5C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345904(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x2);
    fn_803BA240(lbl_80686EA4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803459B4(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x2);
    fn_803BA240(lbl_80686E9C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345A64(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x2);
    fn_803BA240(lbl_80686E84, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345B14(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x2);
    fn_803BA240(lbl_80686E64, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345BC4(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x2);
    fn_803BA240(lbl_80686E74, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345C74(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x2);
    fn_803BA240(lbl_80686E7C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345D24(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686EAC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345DAC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686E24, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345E34(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686E2C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345EBC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F04, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345F44(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F0C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80345FCC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686E8C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346054(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686EE4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803460DC(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686EEC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346164(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686E34, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803461EC(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x7);
    fn_803BA240(lbl_80686EF4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034629C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686EFC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346324(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F14, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803463AC(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x1e);
    fn_803BA240(lbl_80686F1C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034645C(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp2(s->m0, 0x64, 0x71);
    fn_803BA240(lbl_80686F24, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034650C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F2C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346594(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F34, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034661C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F3C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803466A4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F44, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034672C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F4C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_803467B4(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0xfa0);
    fn_803BA240(lbl_80686F54, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346864(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x1e);
    fn_803BA240(lbl_80686F5C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80346914(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80686F64, &r->m4, r);
    return r;
}
