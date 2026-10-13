/*
 * Game code, .text 0x8007CAC4-0x8007DB74 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007A4DC.h"

// Actual database overlay C exports (signatures from src/db/tu_8059A728.cpp and tu_8059FE24.cpp).
struct Db8059AC0C_Name; struct Db8059A728_Obj; struct Db8059B524_Self;
struct Db8059B6AC_Obj; struct Db8059D5C4_Obj; struct Db8059F05C_Obj; struct Db8059FE24_Bits;
extern "C" {
void fn_8059AC0C(Db8059AC0C_Name*, const short*, int);
void fn_8059AC80(const short*, short*, unsigned);
void fn_8059AE4C(Db8059A728_Obj*, int, int, int);
void fn_8059AF50(Db8059B524_Self*, int, int, int, int);
int fn_8059B158(void*, int); int fn_8059B1EC(void*, int);
void fn_8059B280(Db8059A728_Obj*, int, int, short*, int);
int fn_8059B308(Db8059A728_Obj*, int, int, int);
int fn_8059B3D4(Db8059A728_Obj*, int, int); int fn_8059B47C(Db8059A728_Obj*, int, int);
int fn_8059B6AC(Db8059B6AC_Obj*, int); int fn_8059B988(Db8059A728_Obj*, int); int fn_8059BAA4(Db8059A728_Obj*, int);
void fn_8059BCD4(Db8059A728_Obj*, int, int); void fn_8059BCF0(Db8059A728_Obj*, int, unsigned); void fn_8059BD58(Db8059A728_Obj*, unsigned);
int fn_8059BE14(Db8059A728_Obj*, int, int);
int fn_8059D5C4(Db8059D5C4_Obj*, int); int fn_8059D5E8(Db8059D5C4_Obj*, int, int);
int fn_8059D910(Db8059D5C4_Obj*, int, int);
int fn_8059E5D0(Db8059D5C4_Obj*, int, int); int fn_8059E684(Db8059D5C4_Obj*, int, int); int fn_8059E708(Db8059D5C4_Obj*, int);
int fn_8059F040(Db8059D5C4_Obj*, int); int fn_8059F05C(Db8059F05C_Obj*, int); int fn_8059F18C(Db8059D5C4_Obj*, int);
int fn_8059F64C(Db8059D5C4_Obj*, int); int fn_8059F680(void*, int); int fn_8059FA44(void*, int); int fn_8059FADC(void*, int);
int fn_8059FC90(Db8059D5C4_Obj*, int); int fn_8059FCC4(Db8059D5C4_Obj*); int fn_8059FD1C(Db8059D5C4_Obj*);
int fn_8059FD74(Db8059D5C4_Obj*); int fn_8059FDCC(Db8059D5C4_Obj*);
void fn_8059FE24(Db8059FE24_Bits*, unsigned); int fn_8059FE48(Db8059FE24_Bits*, unsigned);
void* fn_800A883C(void**);
}


int Unk8007B2B0_Screen::fn_8007CAC4(int a, int b, int c)
{
    return mF4->v40(a, b, c);
}

int Unk8007B2B0_Screen::fn_8007CAFC()
{
    return fn_800A883C((void**)&m11C) ? ((Obj*)fn_800A883C((void**)&m11C))->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007CB48(int a)
{
    return fn_80071784(m124, a);
}

int Unk8007B2B0_Screen::fn_8007CB6C()
{
    return fn_800A883C((void**)&m13C) ? ((Obj*)fn_800A883C((void**)&m13C))->m4 : 0;
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
    return fn_800A883C((void**)&m14C) ? ((Obj*)fn_800A883C((void**)&m14C))->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007CD6C(int a)
{
    return fn_80071784(m154, a);
}

int Unk8007B2B0_Screen::fn_8007CD90()
{
    return fn_800A883C((void**)&m16C) ? ((Obj*)fn_800A883C((void**)&m16C))->m4 : 0;
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

void Unk8007B2B0_Screen::fn_8007CF44(unsigned i, int a, int b)
{
    fn_8059AC80((const short*)At(i), (short*)a, (unsigned)b);
}

void Unk8007B2B0_Screen::fn_8007CF90(unsigned i, int a)
{
    fn_8059AC0C((Db8059AC0C_Name*)At(i), (const short*)a, 0);
}

Entry* Unk8007B2B0_Screen::fn_8007CFDC(unsigned i)
{
    return At(i);
}

void Unk8007B2B0_Screen::fn_8007D004(unsigned i, int a, int b)
{
    fn_8059BCD4((Db8059A728_Obj*)At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D050(unsigned i, int a)
{
    return fn_8059B988((Db8059A728_Obj*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D098(unsigned i, int a)
{
    return fn_8059BAA4((Db8059A728_Obj*)At(i), a);
}

void Unk8007B2B0_Screen::fn_8007D0E0(unsigned i, int a, int b)
{
    fn_8059BCF0((Db8059A728_Obj*)At(i), a, (unsigned)b);
}

void Unk8007B2B0_Screen::fn_8007D12C(unsigned i, int a, int b, int c)
{
    fn_8059AE4C((Db8059A728_Obj*)At(i), a, b, c);
}

void Unk8007B2B0_Screen::fn_8007D180(unsigned i, int a)
{
    fn_8059BD58((Db8059A728_Obj*)At(i), (unsigned)a);
}

int Unk8007B2B0_Screen::fn_8007D1C8(unsigned i, int a, int b)
{
    return fn_8059BE14((Db8059A728_Obj*)At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D214(unsigned i, int a)
{
    return fn_8059D5C4((Db8059D5C4_Obj*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D25C(unsigned i, int a, int b)
{
    return fn_8059D5E8((Db8059D5C4_Obj*)At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D2A8(unsigned i, int a, int b)
{
    return fn_8059D910((Db8059D5C4_Obj*)At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D2F4(unsigned i, int a, int b)
{
    return fn_8059E5D0((Db8059D5C4_Obj*)At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D340(unsigned i, int a, int b)
{
    return fn_8059E684((Db8059D5C4_Obj*)At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D38C(unsigned i, int a)
{
    return fn_8059E708((Db8059D5C4_Obj*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D3D4(unsigned i, int a)
{
    return fn_8059F040((Db8059D5C4_Obj*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D41C(unsigned i, int a)
{
    return fn_8059F05C((Db8059F05C_Obj*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D464(unsigned i, int a)
{
    return fn_8059F18C((Db8059D5C4_Obj*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D4AC(unsigned i, int a)
{
    return fn_8059F64C((Db8059D5C4_Obj*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D4F4(unsigned i, int a)
{
    return fn_8059F680((void*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D53C(unsigned i, int a)
{
    return fn_8059FA44((void*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D584(unsigned i, int a)
{
    return fn_8059FADC((void*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D5CC(unsigned i, int a)
{
    return fn_8059FC90((Db8059D5C4_Obj*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D614(unsigned i)
{
    return fn_8059FCC4((Db8059D5C4_Obj*)At(i));
}

int Unk8007B2B0_Screen::fn_8007D658(unsigned i)
{
    return fn_8059FD1C((Db8059D5C4_Obj*)At(i));
}

int Unk8007B2B0_Screen::fn_8007D69C(unsigned i)
{
    return fn_8059FD74((Db8059D5C4_Obj*)At(i));
}

int Unk8007B2B0_Screen::fn_8007D6E0(unsigned i)
{
    return fn_8059FDCC((Db8059D5C4_Obj*)At(i));
}

void Unk8007B2B0_Screen::fn_8007D724(unsigned i, int a, int b, int c, int d)
{
    fn_8059AF50((Db8059B524_Self*)At(i), a, b, c, d);
}

int Unk8007B2B0_Screen::fn_8007D77C(unsigned i, int a)
{
    return fn_8059B1EC((void*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D7C4(unsigned i, int a)
{
    return fn_8059B158((void*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D80C(unsigned i, int a)
{
    return fn_8059B6AC((Db8059B6AC_Obj*)At(i), a);
}

int Unk8007B2B0_Screen::fn_8007D854(unsigned i, int a, int b)
{
    return fn_8059B3D4((Db8059A728_Obj*)At(i), a, b);
}

int Unk8007B2B0_Screen::fn_8007D8A0(unsigned i, int a, int b)
{
    return fn_8059B47C((Db8059A728_Obj*)At(i), a, b);
}

void Unk8007B2B0_Screen::fn_8007D8EC(unsigned i, int a, int b, int c, int d)
{
    fn_8059B280((Db8059A728_Obj*)At(i), a, b, (short*)c, d);
}

int Unk8007B2B0_Screen::fn_8007D944(unsigned i, int a, int b, int c)
{
    return fn_8059B308((Db8059A728_Obj*)At(i), a, b, c);
}

void Unk8007B2B0_Screen::fn_8007D998(unsigned i, int a)
{
    fn_8059FE24((Db8059FE24_Bits*)At(i), (unsigned)a);
}

int Unk8007B2B0_Screen::fn_8007D9E0(unsigned i, int a)
{
    return fn_8059FE48((Db8059FE24_Bits*)At(i), (unsigned)a);
}

int Unk8007B2B0_Screen::fn_8007DA28()
{
    return m8->cur;
}

/* The table pointer is held in an int: a pointer-typed local is flagged as a pointer, which makes the index
 * register class include r0 (retail's index is r11, the base then the only pointer-like operand). */
int Unk8007B2B0_Screen::fn_8007DA34(int i)
{
    int r;
    int t = (int)m8;
    if (i == -1)
        r = -1;
    else
        r = ((EntryTable*)t)->list[i];
    return r;
}

void Unk8007B2B0_Screen::fn_8007DA58(int a)
{
    if (a < m8->count)
        m8->cur = a;
    fn_800759F8(this, a);
}

/* Same int table pointer as fn_8007DA34 (index in r11, not r0); the count is read as a plain int. */
void Unk8007B2B0_Screen::fn_8007DA8C(int a, int b)
{
    int t = (int)m8;
    if (b < *(int*)t && a > -1 && a <= 3)
        ((EntryTable*)t)->list[a] = b;
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
