/*
 * Game code, .text 0x80275F24-0x80279758 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80275F24.h"

typedef Unk80275F24_S S;
typedef Unk80275F24 H;
typedef Unk80276758_Rec Rec;

extern const char* lbl_8061E674;
extern Unk80276DB8_Row lbl_8068D5E4[];
extern const char lbl_805DCD08[];
extern const char lbl_805DCD14[];
extern const char lbl_805DC538[];
extern const char lbl_805DCD20[];
extern const char lbl_805DCD2C[];
extern const char lbl_805DCD3C[];
extern const char lbl_805DBD58[];
extern const char lbl_805DCD40[];
extern const char lbl_805DCD4C[];
extern const char lbl_805DCD64[];
extern const char lbl_805DCD6C[];
extern const char lbl_805DCD70[];
extern const char lbl_805DCD80[];
extern const char lbl_805DCD88[];
extern const char lbl_805DCD8C[];
extern const char lbl_805DCD9C[];
extern void* lbl_806EF9D0;
extern int lbl_806EF9D4;

double __builtin_fabs(double x);

inline float AbsF(float v)
{
    return (float)__builtin_fabs(v);
}

extern "C++" {
float fn_8037AF10(void* a, void* b, void* c, int d, int e);
void fn_80278F1C(int a, int b, int c);
}

int fn_80275FD4(S* self);
int fn_80275FD4(S* self)
{
    switch (self->m4) {
    case 0:
        return 3;
    case 1:
        return 1;
    default:
        return 1;
    }
}

int fn_80276004(S* self)
{
    switch (self->m4) {
    case 0:
        return 1;
    case 1:
        return 3;
    default:
        return 1;
    }
}

int fn_80276198(Rec* a, Rec* b)
{
    if (a->m14 < b->m14)
        return -1;
    if (a->m14 > b->m14)
        return 1;
    {
        float x = AbsF((float)a->m20);
        float y = AbsF((float)b->m20);
        if (x < y)
            return -1;
        if (!(x <= y))
            return 1;
    }
    {
        float v;
        float u;
        u = AbsF(a->m8 - 12.0f);
        v = AbsF(b->m8 - 12.0f);
        if (u < v)
            return -1;
        return u > v;
    }
}

int fn_80276758(Rec* a, Rec* b)
{
    if (a->m2C < b->m2C)
        return -1;
    if (a->m2C > b->m2C)
        return 1;
    if (AbsF(a->m34) < b->m34)
        return -1;
    if (!(AbsF(a->m34) <= b->m34))
        return 1;
    if (AbsF(a->m14) < AbsF(b->m14))
        return -1;
    return AbsF(a->m14) > AbsF(b->m14);
}

void fn_802771A0(void* p)
{
    if (p)
        lbl_806EF9D4 = 0;
    lbl_806EF9D0 = p;
}

int fn_802781AC(int x)
{
    return (x + 60) % 30;
}

float fn_80278B10(void* a, void* b, void* c, float x)
{
    float t = fn_8037AF10(a, b, c, 1, 0);
    if (!(t >= x))
        x = t;
    return x;
}

void fn_80278EFC(int a, int b, int c)
{
    fn_80278F1C(a, b, c);
}

H::Unk80275F24()
{
    m10 = 0;
    m8 = 0;
    mC = 0;
}

H::~Unk80275F24()
{
    if (m8 != 0) {
        if (mC != 0)
            delete[] mC;
    }
}

Unk80276DB8::Unk80276DB8() : Unk80362C2C(lbl_8061E674)
{
    m20 = 0;
    m24 = 0;
    m30 = 1.0f;
    for (int i = 0; i < 1; i++)
        lbl_8068D5E4[i].m0 = 0;
}

void Unk80276DB8::fn_vslot2()
{
    fn_8037B674(lbl_805DCD08, &m4.m4, lbl_805DCD14, 0);
    fn_8037B728(lbl_805DC538, lbl_805DCD20, &m4, 0);
    fn_8037B458(lbl_805DCD2C, &m20, lbl_805DCD3C, lbl_805DBD58);
    fn_8037B458(lbl_805DCD40, &m24, lbl_805DCD3C, lbl_805DBD58);
    fn_8037B50C(lbl_805DCD4C, &m30, lbl_805DCD64, lbl_805DCD6C);
    fn_8037B494(lbl_805DCD70, &m2C, lbl_805DCD80, lbl_805DCD88);
    fn_8037B494(lbl_805DCD8C, &m28, lbl_805DCD9C, lbl_805DCD88);
}

Unk80276DB8::~Unk80276DB8() {}

Unk8037B3E8* Unk80276DB8::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk80276DB8;
}

void H::fn_vslot1(char* buf, int len)
{
    m10 = 0;
    if (len != 0) {
        char* cursor;
        int remaining;
        char* token;
        int tokenLen;
        remaining = len;
        cursor = buf;
        fn_80378E48(&cursor, &remaining, '#', &token, &tokenLen);
        if (mC != 0)
            delete[] mC;
        int i = 0;
        m8 = fn_80409DAC(token);
        int a = fn_80275FD4((S*)this);
        int b = fn_80276004((S*)this);
        mC = new (lbl_806EF9B4) Unk80275F24_Elem[m8 * a * b];
        while (i < m8 * fn_80275FD4((S*)this) * fn_80276004((S*)this)) {
            int off = i * 0x3C;
            int j;
            fn_80378E48(&cursor, &remaining, '#', &token, &tokenLen);
            j = 0;
            while (j < fn_80275FD4((S*)this) * fn_80276004((S*)this)) {
                j++;
                i++;
                *(unsigned int*)(off + (int)mC) = fn_80378568(token, tokenLen);
                off += 0x3C;
            }
        }
        fn_80378E48(&cursor, &remaining, '#', &token, &tokenLen);
    }
}
