/*
 * Game code, .text 0x801800FC-0x8018423C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801800FC.h"

/* Attribute names and range strings of the skeleton class. */
extern const char lbl_805CB958[];
extern const char lbl_805CCD18[];
extern const char lbl_805CCD1C[];
extern const char lbl_805CCD30[];
extern const char lbl_805CCD3C[];
extern const char lbl_805CCD40[];
extern const char lbl_805CCD58[];
extern const char lbl_805CCD5C[];
extern const char lbl_805CCD70[];
extern const char lbl_805CCD7C[];
extern const char lbl_805CCD80[];
extern const char lbl_805CCD98[];
extern const char lbl_805CCDAC[];
extern const char lbl_805CCDB0[];
extern const char lbl_805CCDC8[];
extern const char lbl_805CCDDC[];
extern const char lbl_805CCDE4[];
extern const char lbl_805CCDFC[];
extern const char lbl_805CCE08[];
extern const char lbl_805CCE14[];
extern const char lbl_805CCE24[];
extern const char lbl_805CCE28[];
extern const char lbl_805CCE38[];
extern const char lbl_805CCE48[];
extern const char lbl_805CCE58[];
extern const char lbl_805CCE6C[];
extern const char lbl_805CCE7C[];
extern const char lbl_805CCE90[];
extern const char lbl_805CCEA8[];
extern const char lbl_805CCEC4[];
extern const char lbl_805CCEDC[];
extern const char lbl_805CCEF4[];
extern const char lbl_805CCF0C[];
extern const char lbl_805CCF28[];
extern const char lbl_805CCF30[];
extern const char lbl_805CCF40[];
extern const char lbl_805CCF44[];
extern const char lbl_805CCF58[];
extern const char lbl_805CCF68[];
extern const char lbl_805CCF74[];
extern const char lbl_805CCF78[];
extern const char lbl_805CCF8C[];
extern const char lbl_805CCFA0[];
extern const char lbl_805CCFA4[];
extern const char lbl_805CCFBC[];
extern const char lbl_805CCFCC[];
extern const char lbl_805CCFD0[];
extern const char lbl_805CCFE4[];
extern const char lbl_805CCFF8[];
extern const char lbl_805CCFFC[];
extern const char lbl_805CD014[];
extern const char lbl_805CD01C[];
extern const char lbl_805CD030[];
extern const char lbl_805CD044[];
extern const char lbl_805CD04C[];
extern const char lbl_805CD064[];
extern const char lbl_805CD078[];
extern const char lbl_805CD080[];
//@BODY
//@801800FC
Unk801800FC::~Unk801800FC()
{
}

//@80180124
extern "C" void fn_80180124(Unk801800FC* s)
{
    s->m10 = 0;
    s->m14 = 0;
    s->m18 = 0;
    s->m1C = 0;
    s->m0 = 0;
    s->m4 = 0;
    s->m8 = 0;
    s->mC = 0;
    s->m24[0] = 0;
    s->m24[10] = 0;
    s->m3B = 0;
    s->m3C = 0;
    s->m38 = 0;
    s->m39 = 0;
    s->m3A = 0;
}

//@80180168
extern "C" int fn_80180168(Unk801800FC* s, int row)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += s->m24[i + row * 10];
    return sum;
}

//@80180534
extern "C" Unk80270BA0_X* fn_80180534(Unk801808A4_Ctx* self)
{
    int side = 0;
    Unk801808A4_Z* z = self->m6F8->m14;
    if (z->m1CD0)
        side = 1;
    Unk801808A4_Side* p = &z->m0[side];
    int n = p->m16C;
    Unk80270BA0_X* r = 0;
    int i = 1;
    int j = -1;
    for (; i < n - 3; j--, i++) {
        r = fn_801A49F0(self, side, fn_80097300(p, fn_80097190(p, j)));
        if (r != 0 && r->m458 == 13)
            break;
        r = 0;
    }
    return r;
}

//@801805EC
extern "C" int fn_801805EC(Unk801808A4_Ctx* self, int a, int b, int c)
{
    int r;
    if (b == 9)
        r = fn_80180A34(self, c);
    else
        r = fn_801806C8(self, a, b, c);
    return r;
}

//@80180620
extern "C" int fn_80180620(Unk80270BA0_X* o)
{
    if (o == 0)
        return 0;
    void* sub = (char*)o + 0x58C;
    unsigned int v = fn_8035E318(sub);
    if (v <= 2)
        fn_80081CCC(((Unk801808A4_Ctx*)o->m44C)->m6F8->m14, v);
    fn_801A656C(o->m44C, o, 0xD);
    fn_802547C0(sub, 1);
    o->fn_vslot8(1);
    fn_80244A64(o, 0, 0);
    return 1;
}

//@801808A4
/* near-miss: 100/100 insns, same instructions; ~9 slots differ only in register numbers of
 * the sum loop (retail r6/r7/r8/r10, here r7/r8/r10/r11). Loop-variable declaration order
 * and a hoisted side pointer already match the li/addi order. ~8 forms tried. */
extern "C" int fn_801808A4(Unk801808A4_Ctx* self, Unk801800FC* rec)
{
    Unk801808A4_Y* y = self->m6F8;
    Unk801808A4_Side* sides[2];
    sides[0] = &y->m14->m0[0];
    sides[1] = &y->m14->m0[1];
    int changed = 0;
    int i = 0;
    int row = 0;
    for (; i <= 1; i++) {
        int want = fn_80180168(rec, i);
        int have = 0;
        Unk801808A4_Side* s = sides[i];
        for (int k = 0; k < 0x80; k++)
            have += s->m1B4[(unsigned char)k];
        if (want != have) {
            for (unsigned char k = 0; k <= 9; k++) {
                int v = rec->m24[k + row];
                if (v != sides[i]->m1B4[k]) {
                    sides[i]->m1B4[k] = v;
                    changed = 1;
                }
            }
        }
        row += 10;
    }
    if (rec->m38 != y->m14->m1CC9) {
        y->m14->m1CC9 = rec->m38;
        changed = 1;
    }
    if (rec->m39 != y->m14->m1CCB) {
        y->m14->m1CCB = rec->m39;
        changed = 1;
    }
    if (rec->m3A != y->m14->m1CCA) {
        y->m14->m1CCA = rec->m3A;
        changed = 1;
    }
    if (rec->m3B != y->m14->m1CC8) {
        y->m14->m1CC8 = rec->m3B;
        changed = 1;
    }
    int b = rec->m3C == 0;
    if (b != y->m14->m1CD0) {
        y->m14->m1CD0 = b == 1 ? 0 : 1;
        changed = 1;
    }
    return changed;
}

//@80180B58
void Unk80180FE8::fn_vslot2()
{
    fn_8037B7E4(lbl_805CCD18);
    fn_8037B50C(lbl_805CCD1C, &m48, lbl_805CCD30, lbl_805CCD3C);
    fn_8037B458(lbl_805CCD40, &m4, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCD5C, &m4C, lbl_805CCD70, lbl_805CCD7C);
    fn_8037B458(lbl_805CCD80, &m8, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCD98, &m50, lbl_805CCD30, lbl_805CCDAC);
    fn_8037B458(lbl_805CCDB0, &mC, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCDC8, &m54, lbl_805CCD70, lbl_805CCDDC);
    fn_8037B458(lbl_805CCDE4, &m10, lbl_805CCD58, lbl_805CB958);
    fn_8037B7E8(lbl_805CCDFC);
    fn_8037B50C(lbl_805CCE08, &m58, lbl_805CCE14, lbl_805CCE24);
    fn_8037B458(lbl_805CCE28, &m14, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCE38, &m5C, lbl_805CCE48, lbl_805CCE24);
    fn_8037B458(lbl_805CCE58, &m18, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCE6C, &m60, lbl_805CCE48, lbl_805CCE24);
    fn_8037B458(lbl_805CCE7C, &m1C, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCE90, &m64, lbl_805CCE14, lbl_805CCE24);
    fn_8037B458(lbl_805CCEA8, &m20, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCEC4, &m68, lbl_805CCE14, lbl_805CCE24);
    fn_8037B458(lbl_805CCEDC, &m24, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCEF4, &m6C, lbl_805CCE14, lbl_805CCE24);
    fn_8037B458(lbl_805CCF0C, &m28, lbl_805CCD58, lbl_805CB958);
    fn_8037B830(lbl_805CCDFC);
    fn_8037B7E8(lbl_805CCF28);
    fn_8037B50C(lbl_805CCF30, &m70, lbl_805CCD70, lbl_805CCF40);
    fn_8037B458(lbl_805CCF44, &m2C, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCF58, &m74, lbl_805CCF68, lbl_805CCF74);
    fn_8037B458(lbl_805CCF78, &m30, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCF8C, &m78, lbl_805CCF68, lbl_805CCFA0);
    fn_8037B458(lbl_805CCFA4, &m34, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCFBC, &m7C, lbl_805CCF68, lbl_805CCFCC);
    fn_8037B458(lbl_805CCFD0, &m38, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CCFE4, &m80, lbl_805CCF68, lbl_805CCFF8);
    fn_8037B458(lbl_805CCFFC, &m3C, lbl_805CCD58, lbl_805CB958);
    fn_8037B7E8(lbl_805CD014);
    fn_8037B50C(lbl_805CD01C, &m84, lbl_805CD030, lbl_805CD044);
    fn_8037B458(lbl_805CD04C, &m40, lbl_805CCD58, lbl_805CB958);
    fn_8037B50C(lbl_805CD064, &m88, lbl_805CD030, lbl_805CD078);
    fn_8037B458(lbl_805CD080, &m44, lbl_805CCD58, lbl_805CB958);
    fn_8037B830(lbl_805CD014);
    fn_8037B830(lbl_805CCF28);
}

//@80180FE8
Unk80180FE8::Unk80180FE8()
    : Unk8037B3E8(0x6F618F85U)
{
}

//@8018102C
Unk80180FE8::~Unk80180FE8()
{
}

//@8018105C
extern "C" void* fn_8018105C(Unk80180FE8* self)
{
    return fn_8037CF5C(fn_8037C7FC(), 0x6F618F85U, self);
}

//@80181098
Unk8037B3E8* Unk80180FE8::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk80180FE8;
}

//@801810C8
extern "C" void fn_801810C8()
{
    for (int i = 0; i < 4; i++)
        lbl_806E03C8[i] = fn_8018105C(lbl_8061C714[i]);
    lbl_806E03C8[4] = fn_8018105C(lbl_8061C724);
}

//@8018112C
extern "C" void* fn_8018112C(int i)
{
    return lbl_806E03C8[i];
}

//@80181140
/* near-miss: 80/80 insns; the scalar stores after the copy loop come out in a different
 * order (m53C hoisted first; retail: m1D40, m360, m1144, m374, m540, m53C). All 5040
 * orders of the seven trailing statements were tried (2500 sampled). */
extern "C" Unk80181140* fn_80181140(Unk80181140* self, Unk801808A4_Ctx* owner)
{
    fn_8026C75C(self, 0xf, owner);
    self->mB8 = lbl_8065FF08;
    self->m98 = lbl_8065FF98;
    self->m370 = 0;
    Unk80181140_E* e = self->m1160;
    int i = 15;
    do {
        e->m20 = lbl_8060E938;
        e->m68 = e->m64 = e->m60 = lbl_805CD510.m0;
        e++;
    } while (i-- != 0);
    //P{
    self->m360 = 1;
    self->m1144 = 0;
    self->m374 = 0;
    self->m540 = 0;
    self->m53C = 0;
    self->m1D40 = owner;
    self->m364 = lbl_806055AC;
    //P}
    fn_80181280(self);
    return self;
}

//@80181280
extern "C" void fn_80181280(Unk80181140* o)
{
    o->m1D6C = 0;
    fn_80181D84(o);
    fn_80181D48(o);
    fn_80182140(o);
    fn_80182590(o);
}

//@801812CC
extern "C" void fn_801812CC(Unk80181140* o)
{
    fn_80181280(o);
}

//@80181D48
extern "C" void fn_80181D48(Unk80181140* o)
{
    fn_80181670(o, 0);
    fn_80181670(o, 1);
}

//@8018240C
/* near-miss family (this and the getters at 0x80183918, 0x8018398C, 0x801839F8, 0x80183A44,
 * 0x80183AB8, 0x80183B38): the side select matches instruction for instruction, except that
 * retail compares the incoming index register (cmpwi r4,2) where this compiles cmpwi r0,2
 * (the copy t), and schedules the ctx load before `mr r0,r4`. Nine spellings of the select
 * (t copy, else arm, early returns, ternary, f^=1) were scored; none changes the compare. */
extern "C" int fn_8018240C(Unk80181140* o, int side)
{
    int t = Unk801808A4_Sel(o->m1D40, side);
    if (t)
        return o->m1D6C ^ 1;
    return o->m1D6C;
}

//@80182464
extern "C" int fn_80182464(void* self, int key, Unk80183918_Vec3* out)
{
    Unk80182464_Rec* r = fn_80150FC0(key);
    if (r != 0) {
        Unk80183918_Vec3 v = Unk80182464_Pos(r);
        *out = v;
        return 1;
    }
    return 0;
}

//@801824DC
extern "C" int fn_801824DC(void* self, int key, Unk80183918_Vec3* out)
{
    Unk80182464_Rec* r = fn_80150FC0(key);
    if (r != 0) {
        Unk80183918_Vec3 v = Unk80182464_Pos(r);
        *out = v;
        out[1].m0 = r->m10;
        return 1;
    }
    return 0;
}

//@8018255C
extern "C" void fn_8018255C(Unk80181140* o)
{
    fn_8026CA58(o);
    fn_801829FC(o);
}

//@80182E30
extern "C" void fn_80182E30(Unk80181140* o, float f)
{
    if (o->m378 != f)
        o->m378 = f;
}

//@80183918
extern "C" Unk80183918_Vec3 fn_80183918(Unk80181140* o, int idx, int k)
{
    return o->m1C60[Unk801808A4_Sel(o->mBC, idx)][k];
}

//@8018398C
extern "C" Unk80183918_Vec3 fn_8018398C(Unk80181140* o, int idx)
{
    return o->m1D20[Unk801808A4_Sel(o->mBC, idx)].v;
}

//@801839F8
extern "C" float fn_801839F8(Unk80181140* o, int idx)
{
    return o->m1D20[Unk801808A4_Sel(o->mBC, idx)].mC;
}

//@80183A44
extern "C" Unk80183918_Vec3 fn_80183A44(Unk80181140* o, int idx, int k)
{
    return o->m1CC0[Unk801808A4_Sel(o->mBC, idx)][k];
}

//@80183AB8
extern "C" Unk80183918_Vec3 fn_80183AB8(Unk80181140* o, int idx, unsigned int k)
{
    if (k > 8)
        k = 0;
    return o->m1B60[Unk801808A4_Sel(o->mBC, idx)][k].v;
}

//@80183B38
extern "C" float fn_80183B38(Unk80181140* o, int idx, unsigned int k)
{
    if (k > 8)
        k = 0;
    return o->m1B60[Unk801808A4_Sel(o->mBC, idx)][k].mC;
}

//@80183FB8
extern "C" int fn_80183FB8(int v)
{
    switch (v) {
    case 3:
    case 7:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        return 15;
    case 4:
    case 5:
    case 6:
        return v - 1;
    case 8:
    case 9:
    case 10:
        return v - 2;
    }
    return v;
}

//@80183FFC
extern "C" void fn_80183FFC(Unk80181140* o, int k, void* x, void* y, int z)
{
    int r = fn_80183EA0(o, y, k);
    if (z)
        fn_80308C60(x, fn_80183FB8(k), r);
}

//@8018405C
extern "C" void fn_8018405C(Unk80181140* o, void* x, void* y, int z)
{
    fn_8030AC88(y);
    float a[4];
    float b[4];
    float c[4];
    Unk80273498_Pos* p = ((Unk8014D8AC_Ctx*)o->mBC)->m54C->mC;
    Unk80273498_Vec3 pos = p->m60;
    fn_802CBE04(p, a, b, c);
    fn_80183FFC(o, 0, x, y, z);
    fn_80183FFC(o, 1, x, y, z);
    fn_80183FFC(o, 4, x, y, z);
    fn_80183FFC(o, 2, x, y, z);
    fn_80183FFC(o, 3, x, y, z);
    fn_80183FFC(o, 6, x, y, z);
    fn_80183FFC(o, 7, x, y, z);
    fn_80183FFC(o, 8, x, y, z);
    fn_80183FFC(o, 9, x, y, z);
    fn_80183FFC(o, 10, x, y, z);
    fn_80183FFC(o, 11, x, y, z);
    fn_80183FFC(o, 12, x, y, z);
    fn_80183FFC(o, 13, x, y, z);
    fn_80183FFC(o, 14, x, y, z);
    fn_80183FFC(o, 15, x, y, z);
}

