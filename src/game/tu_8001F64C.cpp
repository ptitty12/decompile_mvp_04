/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8001F64C-0x8001FDA8 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8001E444.h"

extern const float lbl_805A5398;

extern "C" int fn_8001F64C(Unk8001E444_Obj* x)
{
    int v = fn_802540E4(x->m3B0->m588, 6, 2);
    int r = 0;
    if (v == 0xAF)
        r = 8;
    else if (v == 0x96)
        r = 4;
    else if (v == 0x7D)
        r = 2;
    else if (v == 0x64)
        r = 1;
    return r;
}

extern "C" int fn_8001F6C0(Unk8001E444_Obj* x)
{
    int v = fn_8025405C(x->m130->m588, 0, 2);
    int r = 0;
    if (v == 0x64)
        r = 0x40;
    else if (v == 0x5A)
        r = 0x20;
    else if (v == 0x50)
        r = 0x10;
    else if (v == 0x46)
        r = 8;
    else if (v == 0x3C)
        r = 4;
    else if (v == 0x32)
        r = 2;
    else if (v == 0x28)
        r = 1;
    return r;
}

extern "C" int fn_8001F764(Unk8001F764_Obj* x)
{
    int n = x->mC;
    if (n > 1)
        return 1 << ((n >> 1) - 1);
    return 0;
}

extern "C" int fn_8001F788(Unk8001E444_Obj* x)
{
    Unk8001E444_Owner* o = x->m130;
    Unk8001F5CC_Tbl* t = o->m44C->m6F8;
    Unk8001F218_Pair* base = t->m14;
    int r = 2;
    int s0 = 0;
    unsigned char i = 0;
    do {
        s0 += base->e[o->m708].m1B4[i];
        i++;
    } while (i != 0x80);
    int s1 = 0;
    unsigned char j = 0;
    do {
        s1 += base->e[o->m708 == 0].m1B4[j];
        j++;
    } while (j != 0x80);
    if (x->m364 != 0) {
        int n = x->m360;
        if (n <= 3 && x->m0 >= (int)((float)t->m10->m1C * lbl_805A5398) && s0 >= s1)
            r = 1;
        else if (n > 3 && s0 < s1)
            r = 4;
    }
    return r;
}

extern "C" int fn_8001F8B8(Unk8001F8B8_Obj* x)
{
    int r = (x->m60 >= 2) << 24;
    if (x->m64 > 1)
        r |= 0x2000000;
    if (x->m68 > 1)
        r |= 0x4000000;
    if (x->m284 > 2)
        r |= 0x800000;
    return r;
}

extern "C" int fn_8001F904()
{
    return 0;
}

extern "C" int fn_8001F90C()
{
    return 0;
}

extern "C" int fn_8001F914(Unk8001E444_Obj* x)
{
    int v = x->m130->m44C->m6F8->mC->m28;
    int r = 2;
    if (v == 10 || v == 0x19 || v == 0x27 || v == 0x1E)
        r = 1;
    return r;
}

extern "C" void fn_8001F954(Unk8001E444_Obj* x)
{
    fn_80045F88(fn_8025454C(x->m3B0->m588, 0xD));
}

extern "C" void fn_8001F984(Unk8001E444_Obj* x)
{
    fn_80046C64(fn_8025454C(x->m3B0->m588, 0xC));
}

extern "C" void fn_8001F9B4(Unk8001E444_Obj* x)
{
    fn_800431BC(fn_80253F0C(x->m3B0->m588, 5, 2, 0));
}

extern "C" void fn_8001F9EC(Unk8001E444_Obj* x)
{
    fn_80043208(fn_802540E4(x->m3B0->m588, 5, 2));
}

extern "C" void fn_8001FA20(Unk8001E444_Obj* x)
{
    fn_80043124(fn_80253F54(x->m3B0->m588, 1, 2, 0));
}

extern "C" void fn_8001FA58(Unk8001E444_Obj* x)
{
    fn_80043178(fn_80253F54(x->m3B0->m588, 0, 2, 0));
}

extern "C" int fn_8001FA90(Unk8001E444_Obj* x)
{
    return fn_80253F0C(x->m3B0->m588, 0, 2, 0);
}

extern "C" int fn_8001FAC4(Unk8001E444_Obj* x)
{
    return fn_80253F0C(x->m3B0->m588, 1, 2, 0);
}

extern "C" int fn_8001FAF8(Unk8001E444_Obj* x)
{
    return fn_80253F0C(x->m3B0->m588, 2, 2, 0);
}

extern "C" int fn_8001FB2C(Unk8001E444_Obj* x)
{
    return fn_80253F0C(x->m3B0->m588, 3, 2, 0);
}

extern "C" int fn_8001FB60(Unk8001E444_Obj* x)
{
    return fn_80253F0C(x->m3B0->m588, 4, 2, 0);
}

extern "C" int fn_8001FB94(Unk8001E444_Obj* x)
{
    return fn_80253DB0(x->m3B0->m588, 1, 0);
}

extern "C" int fn_8001FBC4(Unk8001E444_Obj* x)
{
    return fn_80253DB0(x->m3B0->m588, 3, 0);
}

extern "C" int fn_8001FBF4(Unk8001E444_Obj* x)
{
    return fn_80253F0C(x->m3B0->m588, 6, 2, 0);
}

extern "C" void fn_8001FC28(Unk8001E444_Obj* x)
{
    fn_80042DBC(fn_80253F54(x->m3B0->m588, 0, 2, 0));
}

extern "C" void fn_8001FC60(Unk8001E444_Obj* x)
{
    fn_80042DBC(fn_8025401C(x->m130->m588, 6));
}

extern "C" void fn_8001FC90(Unk8001E444_Obj* x)
{
    fn_80042DBC(fn_8025401C(x->m130->m588, 5));
}

extern "C" int fn_8001FCC0(Unk8001E444_Obj* x)
{
    return fn_80253FDC(x->m130->m588, 3);
}

extern "C" int fn_8001FCEC(Unk8001E444_Obj* x)
{
    return fn_80253FDC(x->m130->m588, 4);
}

extern "C" int fn_8001FD18(Unk8001E444_Obj* x)
{
    return fn_80253FDC(x->m130->m588, 1);
}

extern "C" int fn_8001FD44(Unk8001E444_Obj* x)
{
    return fn_8025405C(x->m130->m588, 2, 2);
}

extern "C" void fn_8001FD74(Unk8001E444_Obj* x)
{
    fn_80042E24(fn_802540A0(x->m130->m588, 3, 2));
}
