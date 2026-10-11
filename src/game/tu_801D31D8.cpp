/*
 * Game code, .text 0x801D31D8-0x801D771C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801D31D8.h"

typedef Unk801D31D8 B;

extern float lbl_805D2C40;
extern float lbl_805D2CC0;
extern const float lbl_805D2CC4;
extern float lbl_805D2CC8;
extern float lbl_805D2CCC;
extern float lbl_805D2CD0;
extern float lbl_805D2CD4;
extern float lbl_805D2C50;
extern float lbl_805D2C54;
extern float lbl_805D2C7C;
extern float lbl_805D2D78;
extern float lbl_805D2D7C;
extern float lbl_805D2D80;
extern float lbl_805D2D84;
extern float lbl_8061CBE0;

extern "C" {
void fn_801D5CF0(B* s);
void fn_801D5D00(B* s);
void fn_801D67CC(B* s);
void fn_801D6D30(B* s, float a);
void fn_801D6CE4(B* s, float a, float b);
void fn_801D6A1C(B* s, float* a, float* b);
void fn_801D7084(Unk801D31D8_Pair* s, int i, float v);
int fn_8035B3BC(void* p);
int fn_8018AD20(Unk801D31D8_Obj* o);
float fn_8022E7F0(int a, int b);
float fn_801CF8CC(void* p, float f);
float fn_801CF740(void* p);
}

struct Unk801D31D8_Q {
    char pad0[0x64];
    int m64;
    float m68;
};

extern "C" int fn_801D5974(B* s)
{
    if (((Unk801D31D8_Q*)s)->m64 != 0 && ((Unk801D31D8_Q*)s)->m68 < (float)s->m30->m4C * lbl_805D2C40)
        return 1;
    return 0;
}

extern "C" int fn_801D59D8(B* s)
{
    if (fn_8035B3BC((char*)s->m2C + 0x28C) == 0 || (s->m38 != 0 && s->m44.m0 == 0))
        return 1;
    return fn_8018AD20(s->m30->m6CC) != 0;
}

extern "C" void fn_801D5A50(B* s, float* a, float* b)
{
    *a = s->m44.mC;
    *b = s->m44.m10;
}

/* near-miss: retail stores m44/m38 first, then loads the constant (li r0 before lis); statement order searched */
extern "C" void fn_801D5C1C(B* s)
{
    s->m44.m0 = 0;
    s->m38 = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m20 = 0;
    q->m24 = lbl_805D2C50;
    q->m4 = lbl_805D2C50;
    q->m8 = 0;
    q->mC = lbl_805D2C50;
    q->m10 = lbl_805D2C50;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
}

extern "C" void fn_801D5C5C(B* s)
{
    fn_801D5CF0(s);
}

/* near-miss: same as fn_801D5C1C */
extern "C" void fn_801D5C7C(B* s)
{
    s->m44.m0 = 0;
    s->m38 = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m20 = 0;
    q->m24 = lbl_805D2C54;
    q->m4 = lbl_805D2C54;
    q->m8 = 0;
    q->mC = lbl_805D2C54;
    q->m10 = lbl_805D2C54;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
}

extern "C" void fn_801D5CBC(B* s)
{
    fn_801D5D00(s);
}

extern "C" void fn_801D5CDC(B* s, int* a, int* b)
{
    *a = s->m3C;
    *b = s->m40;
}

extern "C" void fn_801D5CF0(B* s)
{
    s->m3C = 0;
    s->m40 = 0;
}

/* near-miss: same as fn_801D5C1C */
extern "C" void fn_801D5F2C(B* s)
{
    if (s->m30->m6F4 == 0)
        return;
    s->m44.m0 = 0;
    s->m38 = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m20 = 0;
    q->m24 = lbl_805D2C7C;
    q->m4 = lbl_805D2C7C;
    q->m8 = 0;
    q->mC = lbl_805D2C7C;
    q->m10 = lbl_805D2C7C;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
}

/* near-miss: retail re-reads the m1CD0 flag after the first call; nested-call form CSEs it */
extern "C" void fn_801D6108(B* s)
{
    Unk801D31D8_Pair* p = &s->m6C;
    fn_801D7084(p, s->m30->m6F8->m14->m1CD0 == 0, fn_8022E7F0(s->m30->m700->m3B0, s->m30->m6F8->m14->m1CD0 == 0));
}

extern "C" void fn_801D63A8(B* s)
{
    s->m44.mC = lbl_805D2CC0;
    s->m44.m10 = lbl_805D2CC0;
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    float r = fn_801CF8CC(s->m2C, s->m44.mC);
    s->m44.m4 = r;
}

extern "C" void fn_801D6404(B* s, int flag)
{
    s->m44.m10 = lbl_805D2CC4;
    s->m44.mC = lbl_805D2CC4;
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    float a = fn_801CF740(s->m2C);
    float b = fn_801CF8CC(s->m2C, s->m44.mC);
    float c;
    if (flag != 0)
        c = lbl_805D2CC4;
    else
        c = lbl_805D2CC8;
    s->m44.m4 = a * c + b;
}

extern "C" void fn_801D64A0(B* s, int flag)
{
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    s->m44.m10 = lbl_805D2CCC;
    s->m44.mC = lbl_805D2CCC;
    float a = fn_801CF740(s->m2C);
    float b = fn_801CF8CC(s->m2C, s->m44.mC);
    float c;
    if (flag != 0)
        c = lbl_805D2CD0;
    else
        c = lbl_805D2CD4;
    s->m44.m4 = a * c + b;
}

extern "C" void fn_801D67CC(B* s)
{
    s->m44.m0 = 0;
    s->m44.m8 = 0;
}

/* near-miss: retail compares b in f2 (param register), we reload into f0 */
extern "C" void fn_801D6CE4(B* s, float a, float b)
{
    if (!(b >= lbl_8061CBE0))
        fn_801D6D30(s, a);
    else
        fn_801D67CC(s);
}

/* near-miss: 1 slot: k kept in f31 differently */
extern "C" void fn_801D6F6C(B* s)
{
    const float k = lbl_805D2D78;
    float a = k;
    float b = k;
    fn_801D6A1C(s, &a, &b);
    if (!(b <= k))
        fn_801D6CE4(s, a, b);
    else
        fn_801D6D30(s, a);
}

extern "C" Unk801D31D8_Pair* fn_801D6FE4(Unk801D31D8_Pair* s)
{
    fn_801D7084(s, 0, lbl_805D2D7C);
    fn_801D7084(s, 1, lbl_805D2D7C);
    return s;
}

/* near-miss: float local k stored later in retail */
extern "C" void fn_801D7030(Unk801D31D8_Pair* s, int i, float v)
{
    const float k = lbl_805D2D80;
    s->m0[i] = s->m0[i] * lbl_805D2D84 + s->m8[i] * k;
    s->m8[i] = v;
}

extern "C" float fn_801D7078(Unk801D31D8_Pair* s, int i)
{
    return s->m0[i];
}

extern "C" void fn_801D7084(Unk801D31D8_Pair* s, int i, float v)
{
    s->m8[i] = v;
    s->m0[i] = v;
}
