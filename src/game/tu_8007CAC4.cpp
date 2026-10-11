/*
 * Game code, .text 0x8007CAC4-0x8007DB74 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007A4DC.h"

int Unk8007B2B0_Screen::fn_8007CAC4(int a, int b, int c)
{
    return mF4->v40(a, b, c);
}

int Unk8007B2B0_Screen::fn_8007CAFC()
{
    return fn_800A883C(&m11C) ? fn_800A883C(&m11C)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007CB48(int a)
{
    return fn_80071784(m124, a);
}

int Unk8007B2B0_Screen::fn_8007CB6C()
{
    return fn_800A883C(&m13C) ? fn_800A883C(&m13C)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007CBB8(int a, int b)
{
    return m124->v28(a, fn_80071814(m124, b));
}

int Unk8007B2B0_Screen::fn_8007CC18(int a, int b, int c)
{
    return m124->v40(a, fn_80071814(m124, b), c);
}

int Unk8007B2B0_Screen::fn_8007CC80(int a, int b, char* c)
{
    return m124->v30(a, fn_80071814(m124, b), c);
}

int Unk8007B2B0_Screen::fn_8007CCE8(int a, int b, int c)
{
    return m124->v40(a, b, c);
}

int Unk8007B2B0_Screen::fn_8007CD20()
{
    return fn_800A883C(&m14C) ? fn_800A883C(&m14C)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007CD6C(int a)
{
    return fn_80071784(m154, a);
}

int Unk8007B2B0_Screen::fn_8007CD90()
{
    return fn_800A883C(&m16C) ? fn_800A883C(&m16C)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007CDDC(int a, int b)
{
    return m154->v28(a, fn_80071814(m154, b));
}

int Unk8007B2B0_Screen::fn_8007CE3C(int a, int b, int c)
{
    return m154->v40(a, fn_80071814(m154, b), c);
}

int Unk8007B2B0_Screen::fn_8007CEA4(int a, int b, char* c)
{
    return m154->v30(a, fn_80071814(m154, b), c);
}

int Unk8007B2B0_Screen::fn_8007CF0C(int a, int b, int c)
{
    return m154->v40(a, b, c);
}

int Unk8007B2B0_Screen::fn_8007CF44(unsigned i, int a, int b)
{
    return fn_8059AC80(At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007CF90(unsigned i, int a)
{
    return fn_8059AC0C(At(i), a, 0);
}

Entry* Unk8007B2B0_Screen::fn_8007CFDC(unsigned i)
{
    return At(i);
}

int Unk8007B2B0_Screen::fn_8007D004(unsigned i, int a, int b)
{
    return fn_8059BCD4(At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D050(unsigned i, int a)
{
    return fn_8059B988(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D098(unsigned i, int a)
{
    return fn_8059BAA4(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D0E0(unsigned i, int a, int b)
{
    return fn_8059BCF0(At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D12C(unsigned i, int a, int b, int c)
{
    return fn_8059AE4C(At(i), a, b, c);
}

int Unk8007B2B0_Screen::fn_8007D180(unsigned i, int a)
{
    return fn_8059BD58(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D1C8(unsigned i, int a, int b)
{
    return fn_8059BE14(At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D214(unsigned i, int a)
{
    return fn_8059D5C4(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D25C(unsigned i, int a, int b)
{
    return fn_8059D5E8(At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D2A8(unsigned i, int a, int b)
{
    return fn_8059D910(At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D2F4(unsigned i, int a, int b)
{
    return fn_8059E5D0(At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D340(unsigned i, int a, int b)
{
    return fn_8059E684(At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D38C(unsigned i, int a)
{
    return fn_8059E708(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D3D4(unsigned i, int a)
{
    return fn_8059F040(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D41C(unsigned i, int a)
{
    return fn_8059F05C(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D464(unsigned i, int a)
{
    return fn_8059F18C(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D4AC(unsigned i, int a)
{
    return fn_8059F64C(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D4F4(unsigned i, int a)
{
    return fn_8059F680(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D53C(unsigned i, int a)
{
    return fn_8059FA44(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D584(unsigned i, int a)
{
    return fn_8059FADC(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D5CC(unsigned i, int a)
{
    return fn_8059FC90(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D614(unsigned i)
{
    return fn_8059FCC4(At(i));
}

int Unk8007B2B0_Screen::fn_8007D658(unsigned i)
{
    return fn_8059FD1C(At(i));
}

int Unk8007B2B0_Screen::fn_8007D69C(unsigned i)
{
    return fn_8059FD74(At(i));
}

int Unk8007B2B0_Screen::fn_8007D6E0(unsigned i)
{
    return fn_8059FDCC(At(i));
}

int Unk8007B2B0_Screen::fn_8007D724(unsigned i, int a, int b, int c, int d)
{
    return fn_8059AF50(At(i), a, b, c, d);
}

int Unk8007B2B0_Screen::fn_8007D77C(unsigned i, int a)
{
    return fn_8059B1EC(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D7C4(unsigned i, int a)
{
    return fn_8059B158(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D80C(unsigned i, int a)
{
    return fn_8059B6AC(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D854(unsigned i, int a, int b)
{
    return fn_8059B3D4(At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D8A0(unsigned i, int a, int b)
{
    return fn_8059B47C(At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D8EC(unsigned i, int a, int b, int c, int d)
{
    return fn_8059B280(At(i), a, b, c, d);
}

int Unk8007B2B0_Screen::fn_8007D944(unsigned i, int a, int b, int c)
{
    return fn_8059B308(At(i), a, b, c);
}

int Unk8007B2B0_Screen::fn_8007D998(unsigned i, int a)
{
    return fn_8059FE24(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D9E0(unsigned i, int a)
{
    return fn_8059FE48(At(i), a);
}

int Unk8007B2B0_Screen::fn_8007DA28()
{
    return m8->cur;
}

/* near-miss: 2 slots, the scaled index lands in r0 instead of r11 (slwi/lwzx). */
int Unk8007B2B0_Screen::fn_8007DA34(int i)
{
    int r;
    EntryTable* t = m8;
    if (i == -1)
        r = -1;
    else
        r = t->list[i];
    return r;
}

void Unk8007B2B0_Screen::fn_8007DA58(int a)
{
    if (a < m8->count)
        m8->cur = a;
    fn_800759F8(this, a);
}

/* near-miss: 2 slots, the scaled index lands in r0 instead of r11 (slwi/stwx). */
void Unk8007B2B0_Screen::fn_8007DA8C(int a, int b)
{
    if (b < m8->count && a > -1 && a <= 3)
        m8->list[a] = b;
    fn_800759F8(this, b);
}

int Unk8007B2B0_Screen::fn_8007DADC(unsigned i)
{
    return At(i)->m38_0;
}

void Unk8007B2B0_Screen::fn_8007DB0C(unsigned i)
{
    At(i)->m38_0 = 0;
}

void Unk8007B2B0_Screen::fn_8007DB40(unsigned i)
{
    At(i)->m38_0 = 1;
}
