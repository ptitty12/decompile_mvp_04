

/*
 * Game code, .text 0x8015F164-0x80163390 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8015AA94.h"

extern float lbl_805C8EE8;
extern float lbl_805C8EEC;

int Unk80159F28::fn_8015F744(Unk8015F744_Evt* e) /* 8015F744 */
{
    int k = e->m0 == 0x39;
    switch (e->mC) {
    case 3:
        return k ? 0x3F : 0x3E;
    case 0:
        return k ? 0x35 : 0x34;
    case 1:
        if (!k) {
            return 0x36;
        }
    default:
        return 0x37;
    case 2:
        return k ? 0x3B : 0x3A;
    }
}

int Unk80159F28::fn_8015F7D0(Unk8015F744_Evt* e) /* 8015F7D0 */
{
    int k = e->m0 == 0x5F;
    switch (e->mC) {
    case 3:
        return k ? 0x40 : 0x41;
    case 1:
        if (!k) {
            return 0x39;
        }
    default:
        return 0x38;
    case 2:
        return k ? 0x3C : 0x3D;
    }
}

void Unk80159F28::fn_8015F840() /* 8015F840 */
{
    fn_801A4B34(mC)->fn_v4();
}

void Unk80159F28::fn_8015F87C() /* 8015F87C */
{
    Unk801527C8_Actor* a = mC;
    if (!((float)*(unsigned int*)&a->m4C * lbl_805C8EE8 > lbl_805C8EEC)) {
        Unk801527C8_Mgr* m = a->m6F8;
        int r = m->m10->m13C;
        if (m->fn_8006BE18() != 0 && r != 0) {
            r = 4;
        }
        fn_8015F918(r);
    }
}

void Unk80159F28::fn_8015FB08(int a, int b, Unk8015FB08_Rec rec) /* 8015FB08 */
{
    fn_80157514(a, b, 0, rec.m0, 0, rec.m4);
}

void Unk80159F28::fn_8015FB84(int a, int b, Unk8015FB08_Rec rec) /* 8015FB84 */
{
    fn_80157514(a, b, 0, 0, 0, rec.m4);
}

int Unk80159F28::fn_80160DEC() /* 80160DEC */
{
    int r = fn_80160E64();
    if (r > 2) {
        return 0xD;
    }
    if (r == 2) {
        return 0xB;
    }
    return 9;
}

int Unk80159F28::fn_80160E28() /* 80160E28 */
{
    int r = fn_80160E64();
    if (r > 2) {
        return 0xC;
    }
    if (r == 2) {
        return 0xA;
    }
    return 8;
}

/* near-miss: same code except the register allocation of mC/the sums (retail keeps mC in r7, c in r5); 6 source orderings tried */
int Unk80159F28::fn_80160E64() /* 80160E64 */
{
    Unk801527C8_Teams* t0 = mC->m6F8->m14;
    int c = t0->m1CC8;
    int a = 0;
    for (int i = 0; i < 128; i++) {
        a += t0->m0[0].m1B4[(unsigned char)i];
    }
    int b = 0;
    Unk801527C8_Team* t1 = &mC->m6F8->m14->m0[1];
    for (int i = 0; i < 128; i++) {
        b += t1->m1B4[(unsigned char)i];
    }
    int d = __builtin_abs(a - b);
    if (c > 7 && d <= 1) {
        return 3;
    }
    if (c > 5 && d <= 1) {
        return 2;
    }
    return 1;
}

void Unk80159F28::fn_80161A34() /* 80161A34 */
{
    for (int i = 0; i < 7; i++) {
        m30C[i] = 0;
    }
    m328 = 0;
}

int* Unk80159F28::fn_80161A5C(int a, int b) /* 80161A5C */
{
    return (int*)((char*)this + 0x50 + a * 0x64 + b * 4);
}

int Unk80159F28::fn_80162534() /* 80162534 */
{
    if (fn_801A6D84(mC, 1)->m3D90 != 0 || fn_801A6D84(mC, 5)->m3D90 != 0) {
        return 0;
    }
    return 1;
}

int Unk80159F28::fn_80162598() /* 80162598 */
{
    if (fn_801A6D84(mC, 1)->m3D90 != 0 || fn_801A6D84(mC, 5)->m3D90 != 0) {
        return 0;
    }
    return 1;
}

int Unk80159F28::fn_801625FC() /* 801625FC */
{
    int r = 0;
    if (fn_80162664() != 0) {
        r = 1;
    }
    if (fn_80162850() != 0) {
        r = 1;
    }
    if (fn_80162A3C() != 0) {
        r = 1;
    }
    return r;
}
