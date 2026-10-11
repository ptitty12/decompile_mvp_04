/*
 * Game code, .text 0x80349880-0x8034B370 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803401A8.h"

extern char lbl_806871AC[];
extern char lbl_806871BC[];
extern char lbl_806871C4[];
extern char lbl_806871CC[];
extern char lbl_8068719C[];
extern char lbl_806871D4[];
extern char lbl_806871B4[];
extern char lbl_8068721C[];
extern char lbl_80687224[];
extern char lbl_80687204[];
extern char lbl_8068720C[];
extern char lbl_80687214[];
extern char lbl_806871FC[];
extern char lbl_80687244[];
extern char lbl_8068725C[];
extern char lbl_80687264[];
extern char lbl_8068726C[];
extern char lbl_80687274[];
extern char lbl_8068728C[];
extern char lbl_80687294[];
extern char lbl_8068724C[];
extern char lbl_80687254[];
extern char lbl_8068729C[];
extern char lbl_80687284[];
extern char lbl_8068727C[];

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

Unk803B9D60_Rec* fn_80349880(Unk803B9D60_In3* s)
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
    fn_803BA240(lbl_806871AC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349984(Unk803B9D60_In3* s)
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
    if (v < 0) v = 0; else if (v > 0x64) v = 0x64;
    r->mC = v;
    fn_803BA240(lbl_806871BC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349A88(Unk803B9D60_In3* s)
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
    if (v < 0) v = 0; else if (v > 0x64) v = 0x64;
    r->mC = v;
    fn_803BA240(lbl_806871C4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349B8C(Unk803B9D60_In3* s)
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
    if (v < 0) v = 0; else if (v > 0x64) v = 0x64;
    r->mC = v;
    fn_803BA240(lbl_806871CC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349C90(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp(s->m0, 0x4);
    fn_803BA240(lbl_8068719C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349D40(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806871D4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349DC8(Unk803B9D60_In3* s)
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
    fn_803BA240(lbl_806871B4, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_80349ECC(Unk803B9D60_In3* s)
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

Unk803B9D60_Rec* fn_80349FD0(Unk803B9D60_In3* s)
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
    fn_803BA240(lbl_80687224, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A0D4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687204, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A15C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068720C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A1E4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687214, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A26C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_806871FC, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A2F4(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687244, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A37C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068725C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A404(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687264, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A48C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068726C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A514(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687274, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A59C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068728C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A624(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687294, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A6AC(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp2(s->m0, 0x1, 0x2);
    fn_803BA240(lbl_8068724C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A75C(Unk803B9D60_In1* s)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    r->m4 = Clamp2(s->m0, 0x1, 0x4);
    fn_803BA240(lbl_80687254, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A80C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068729C, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A894(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_80687284, &r->m4, r);
    return r;
}

Unk803B9D60_Rec* fn_8034A91C(void)
{
    Unk803B9D60_Alloc* a;
    fn_803B9D60(&a);
    fn_803B9DDC();
    Unk803B9D60_Rec* r = a->v1(0x8, Unk803B9D60_Z());
    fn_803B9E08();
    fn_803BA240(lbl_8068727C, &r->m4, r);
    return r;
}

void fn_8034A9A4(Unk803BA4D0_Obj* self, Unk803B9D60_In4* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0xc8) v = 0xc8;
    self->mC = v;
    int w = in->mC;
    if (w < 0) w = 0; else if (w > 0x2) w = 0x2;
    self->m10 = w;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034AA74(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x78) v = 0x78;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034AB20(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x78) v = 0x78;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034ABCC(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x96) v = 0x96;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034AC78(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0xc8) v = 0xc8;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034AD24(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x78) v = 0x78;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034ADD0(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x2710) t = 0x2710;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x78) v = 0x78;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034AE7C(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0xc8) v = 0xc8;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034AF28(Unk803BA4D0_Obj* self, Unk803B9D60_In2* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034AFB0(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x3e8) v = 0x3e8;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034B05C(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x78) v = 0x78;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034B108(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x96) v = 0x96;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034B1B4(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x10) v = 0x10;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034B260(Unk803BA4D0_Obj* self, Unk803B9D60_In2* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034B2E8(Unk803BA4D0_Obj* self, Unk803B9D60_In2* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x1f4) t = 0x1f4;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}
