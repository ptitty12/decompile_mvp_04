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
extern float lbl_8061D220;
extern const float lbl_805D7B1C;
extern const float lbl_805D7A94;
extern const float lbl_805D7A98;
struct Unk80270BA0_X;
float fn_8024D0C4(Unk80270BA0_X* x, int a, float f1, float f2);
extern "C" float fn_8024F048(char* a, int b, int c, int d, int e);
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

/* Array element read with the byte offset in a local: base-first lwzx (PATTERNS, indexing). */
inline int At(char* base, int i)
{
    int o = i * 4;
    return *(int*)(base + o);
}

void Unk802362A8_Cpu::fn_80237B60(float* out)
{
    float tbl[4] = { -0.6f, -0.5f, -0.3f, -0.2f };
    Unk8022FE34_Game* g = m2E4->m6F8;
    int idx = g->m14[2].m8 == 0;
    int pl = At(g->m10 + 0x14, idx);
    float f = fn_8024D0C4((Unk80270BA0_X*)fn_801C1638(m2E4, 0), 2, lbl_805D7A94, lbl_805D7A98);
    f = f + tbl[pl];
    *out = *out * f;
}

int Unk802362A8_Cpu::fn_80238088(Unk802362A8_Req* p)
{
    if (fn_80238B84()) {
        return 9;
    }
    char* g = m2E4->m680;
    int r;
    if (!(fn_8024F048(g + 0xA0C, *(int*)(g + 0xA04), *(int*)(g + 0x44C), *(int*)(g + 0x708), 1) >= lbl_805D7B1C) && p->m14 == 0) {
        r = 0;
    } else {
        r = 1;
    }
    return r;
}

int Unk802362A8_Cpu::fn_80239448()
{
    int b = m2E4->m6F8->m14[2].m0;
    int a = fn_80238110();
    int c = fn_802394CC();
    if (a != 0) {
        if (c == 0) {
            return 0;
        }
    } else {
        int r = 0;
        if (c != 0) {
            r = 1;
        }
        return r;
    }
    return (unsigned)(b - 5) > 1;
}

void Unk802362A8_Cpu::fn_8023A13C()
{
    char* p = (char*)m2E0 + 0xC;
    float t = fn_801A0AA8(m2E4, 0.5f, lbl_8061D220);
    t = Lerp(-1.0f, t, 1.0f);
    *(float*)(p + 0x18) = t;
    *(float*)(p + 0x14) = 1.0f;
}
