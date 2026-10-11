/*
 * Game code, .text 0x8034B8C0-0x8034D550 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8034B370.h"

void fn_8034B8C0(void)
{
}

void fn_8034B8C4(Unk803BA4D0_Obj* self, Unk803B9D60_In1* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0xc8) t = 0xc8;
    self->m4 = t;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034B91C(Unk803BA4D0_Obj* self, Unk803B9D60_In1* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0xc8) t = 0xc8;
    self->m4 = t;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034B974(Unk803BA4D0_Obj* self, Unk803B9D60_In1* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0xc8) t = 0xc8;
    self->m4 = t;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034B9CC(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x3e8) t = 0x3e8;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x64) v = 0x64;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034BA78(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x3e8) t = 0x3e8;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x64) v = 0x64;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

void fn_8034BB24(Unk803BA4D0_Obj* self, Unk803B9D60_In3* in)
{
    int t = in->m0;
    if (t < 0) t = 0; else if (t > 0x3e8) t = 0x3e8;
    self->m4 = t;
    int u = in->m4;
    if (u < 0) u = 0; else if (u > 0xffff) u = 0xffff;
    self->m8 = u;
    int v = in->m8;
    if (v < 0) v = 0; else if (v > 0x64) v = 0x64;
    self->mC = v;
    if (self->m0 != 0)
        fn_803BA4D0(self->m0, &self->m4);
}

int fn_8034BBD0(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034BC90(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034BD50(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034BE10(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034BED0(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034BF90(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C050(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C110(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C1D0(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C290(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C350(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C410(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C4D0(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C590(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C650(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C710(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C7D0(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C890(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034C950(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034CA10(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034CAD0(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034CB90(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034CC50(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034CD10(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034CDD0(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034CE90(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034CF50(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034D010(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034D0D0(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034D190(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034D250(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034D310(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034D3D0(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}

int fn_8034D490(Unk803BA44C_Obj** pp, int flag)
{
    Unk803BA44C_Obj* o = *pp;
    int cnt = 0;
    if (o->m0 != 0)
        fn_803BA44C(o->m0, &cnt);
    if (cnt <= 1 || flag == 1) {
        if (o != 0) {
            if (o->m0 != 0)
                fn_803BA378(o->m0);
            Unk803B9D60_Alloc* a;
            fn_803B9D60(&a);
            fn_803B9DDC();
            a->v2(o, 0);
            fn_803B9E08();
        }
        *pp = 0;
        return 1;
    }
    return 0;
}
