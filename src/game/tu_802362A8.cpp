/*
 * Game code, .text 0x802362A8-0x8023A6C8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_802362A8.h"

extern const char lbl_805D7380[];
extern const char lbl_805D7384[];
extern const char lbl_805D7394[];
extern const char lbl_805D73A0[];
extern const char lbl_805D73AC[];
extern const char lbl_805D73B8[];
extern const char lbl_805D73BC[];
extern const char lbl_805D73CC[];
extern const char lbl_805D73D0[];
extern const char lbl_805D73E8[];
extern const char lbl_805D7400[];
extern const char lbl_805D740C[];
extern const char lbl_805D7428[];
extern const char lbl_805D7440[];
extern const char lbl_805D7458[];
extern const char lbl_805D7470[];
extern const char lbl_805D748C[];
extern const char lbl_805D74A4[];
extern const char lbl_805D74C0[];
extern const char lbl_805D74D8[];
extern const char lbl_805D74F0[];
extern const char lbl_805D7508[];
extern const char lbl_805D7524[];
extern const char lbl_805D753C[];
extern const char lbl_805D7558[];
extern const char lbl_805D7570[];
extern const char lbl_805D7588[];
extern const char lbl_805D75A0[];
extern const char lbl_805D75BC[];
extern const char lbl_805D75D4[];
extern const char lbl_805D75F0[];
extern const char lbl_805D7608[];
extern const char lbl_805D7620[];
extern const char lbl_805D7638[];
extern const char lbl_805D7644[];
extern const char lbl_805D7660[];
extern const char lbl_805D7684[];
extern const char lbl_805D7698[];
extern int lbl_8068CA8C;
extern const float lbl_805D7C18;
extern const char lbl_805D7978[];
extern const float lbl_805D7C8C;
extern const float lbl_805D7C90;
extern const float lbl_805D7C94;
extern float lbl_8061D220;
extern "C" float fn_801A0AA8(Unk8022FE34_Ctx* c, float a, float b);

inline float Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}

cPitcherTunables::cPitcherTunables() : Unk8037B3E8(0x1011A855)
{
}

void cPitcherTunables::fn_vslot2()
{
    fn_8037B7E4(lbl_805D7380);
    fn_8037B50C(lbl_805D7384, &m24, lbl_805D7394, 0);
    fn_8037B50C(lbl_805D73A0, &m1C, lbl_805D73AC, lbl_805D73B8);
    fn_8037B50C(lbl_805D73BC, &m20, lbl_805D73AC, lbl_805D73CC);
    fn_8037B7E8(lbl_805D73D0);
    fn_8037B50C(lbl_805D73E8, &m28, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D740C, &m2C, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7428, &m30, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7440, &m34, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7458, &m68, lbl_805D7400, 0);
    fn_8037B830(lbl_805D73D0);
    fn_8037B7E8(lbl_805D7470);
    fn_8037B50C(lbl_805D748C, &m38, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D74A4, &m3C, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D74C0, &m40, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D74D8, &m44, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D74F0, &m6C, lbl_805D7400, 0);
    fn_8037B830(lbl_805D7470);
    fn_8037B7E8(lbl_805D7508);
    fn_8037B50C(lbl_805D7524, &m48, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D753C, &m4C, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7558, &m50, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7570, &m54, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7588, &m70, lbl_805D7400, 0);
    fn_8037B830(lbl_805D7508);
    fn_8037B7E8(lbl_805D75A0);
    fn_8037B50C(lbl_805D75BC, &m58, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D75D4, &m5C, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D75F0, &m60, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7608, &m64, lbl_805D7400, 0);
    fn_8037B50C(lbl_805D7620, &m74, lbl_805D7400, 0);
    fn_8037B830(lbl_805D75A0);
    fn_8037B728(lbl_805D7638, lbl_805D7644, &m4, (int)lbl_805D7660);
    fn_8037B728(lbl_805D7638, lbl_805D7684, &m10, (int)lbl_805D7698);
}

Unk8037B3E8* cPitcherTunables::fn_vslot5()
{
    return new (lbl_806EF9B4) cPitcherTunables;
}

void cPitcherTunables::fn_vslot8() {}

void fn_802366B0()
{
    fn_8037C7FC()->fn_8037CE98(0x1011A855, lbl_8068CA8C, 0);
}

void fn_80236B8C() {}

char* Unk802362A8_Slots::fn_80236B90()
{
    return (char*)this + 0x268;
}

char* Unk802362A8_Slots::fn_80236B98()
{
    return (char*)this + 0x29C;
}

char* Unk802362A8_Slots::fn_80236BA0(int k)
{
    int idx;
    if (k == 6) {
        int a[3] = { 1, 5, 7 };
        idx = a[m90->m554->fn_8014D8AC(3, lbl_805D7978, 0xCA)];
    } else if (k == 7) {
        int a[2] = { 3, 4 };
        idx = a[m90->m554->fn_8014D8AC(2, lbl_805D7978, 0xD1)];
    } else {
        int a[3] = { 2, 6, 8 };
        idx = a[m90->m554->fn_8014D8AC(3, lbl_805D7978, 0xD7)];
    }
    return (char*)this + (idx * 0x34 + 0x94);
}

float fn_802398C8()
{
    return lbl_805D7C18;
}

/* near-miss: retail presets li r3,0 and ends in a shared 'li r3,0; blr'; case 6 then returns through beqlr.
   Tried return-chain, int r preset (39 vs 41 insns) and empty-case-6 forms */
int fn_80236F34(void* p, int k)
{
    switch (k) {
    case 2:
        return 5;
    case 3:
        return 1;
    case 4:
        return 7;
    case 5:
        return 3;
    case 6:
        return 0;
    case 7:
        return 4;
    case 8:
        return 6;
    case 9:
        return 2;
    case 10:
        return 8;
    }
    return 0;
}

void Unk802362A8_Slots::fn_80237114()
{
    for (int i = 0; i < 11; i++) {
        m0[i] = -1;
        m2C[i] = -1;
        m58[i] = -1;
    }
    m84 = 0;
    m88 = 0;
    m8C = 0;
}

/* near-miss: 35/35 insns, 6 slots; retail loads lbl_8061D220 (f2) before lbl_805D7C8C (f1) for the fn_801A0AA8 call,
   ours the reverse. Tried const/non-const globals, declaration order, a local for the second argument */
void Unk802362A8_Cpu::fn_8023A13C()
{
    char* p = (char*)m2E0 + 0xC;
    float t = fn_801A0AA8(m2E4, lbl_805D7C8C, lbl_8061D220);
    t = Lerp(lbl_805D7C90, t, lbl_805D7C94);
    *(float*)(p + 0x14) = lbl_805D7C94;
    *(float*)(p + 0x18) = t;
}
