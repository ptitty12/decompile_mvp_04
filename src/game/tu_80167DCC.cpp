/*
 * Game code, .text 0x80167DCC-0x8016BF30 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80167DCC.h"

extern float lbl_805C943C;

extern const char lbl_805C7994[];
extern const char lbl_805C9458[];
extern const char lbl_805C9464[];
extern const char lbl_805C9470[];
extern const char lbl_805C947C[];

extern Unk80619D10* lbl_80619D10;
int fn_8040B6A0(const char* s);
int fn_8016DB74(const char* s);
void fn_8016D2F4(Unk801527C8_Ctx* ctx, const char* s);
void fn_8016C4A0(void* p);
void fn_8037CD38();
Unk801527C8_Actor* fn_801A04A8(Unk801527C8_Actor* a, int i);
void fn_8018CA5C(Unk80189300* o, float* a, float* b, float* c);

void Unk80159F28::fn_80167DCC(int p, Unk8015FB08_Rec rec) /* 80167DCC */
{
    switch (rec.m4.w[2]) {
    case 2:
        fn_8015FB08(0x8D, p, rec);
        break;
    case 3:
        fn_8015FB08(0x8E, p, rec);
        break;
    case 4:
        fn_8015FB08(0x8F, p, rec);
        break;
    case 5:
        fn_8015FB08(0x94, p, rec);
        break;
    case 0:
        fn_8015FB08(0x93, p, rec);
        break;
    case 6:
        fn_8015FB08(0x90, p, rec);
        break;
    case 7:
        fn_8015FB08(0x91, p, rec);
        break;
    case 8:
        fn_8015FB08(0x92, p, rec);
        break;
    case 1:
        fn_8015FB08(0x95, p, rec);
        break;
    }
}

void Unk80159F28::fn_8016818C(int p, Unk8015FB08_Rec rec) /* 8016818C */
{
    switch (rec.m4.w[2]) {
    case 2:
        fn_8015FB08(0x8D, p, rec);
        break;
    case 3:
        fn_8015FB08(0x8E, p, rec);
        break;
    case 4:
        fn_8015FB08(0x8F, p, rec);
        break;
    case 5:
        fn_8015FB08(0x94, p, rec);
        break;
    case 1:
        fn_8015FB08(0x95, p, rec);
        break;
    case 0:
        fn_8015FB08(0x8B, p, rec);
        break;
    case 6:
        fn_8015FB08(0x88, p, rec);
        break;
    case 7:
        fn_8015FB08(0x89, p, rec);
        break;
    case 8:
        fn_8015FB08(0x8A, p, rec);
        break;
    }
}

void Unk80159F28::fn_80169458(int p, Unk8015FB08_Rec rec) /* 80169458 */
{
    float a, b, c;
    int d = fn_80165CC8();
    fn_8018CA5C(mC->m6CC, &a, &b, &c);
    if (d != 0) {
        if (fn_8015F840() != 0) {
            fn_8015FB08(0x77, p, rec);
        } else {
            fn_8015FB08(0x78, p, rec);
        }
    } else {
        if (!(a <= lbl_805C943C)) {
            fn_8015FB08(0x96, p, rec);
        } else {
            fn_8015FB08(0x97, p, rec);
        }
    }
}

void Unk80159F28::fn_80169674() /* 80169674 */
{
    for (int i = 0; i <= 5; i++) {
        Unk801527C8_Actor* o = fn_801A04A8(mC, i);
        if (o != 0) {
            void* p = o->m40;
            if (p != 0) {
                fn_8016C4A0(p);
            }
        }
    }
    fn_8037C7FC();
    fn_8037CD38();
}

cScriptLoadAnimations::cScriptLoadAnimations() : Unk80359B48(0x339C4BD0u) /* 801696D8 */
{
    m4[0] = 0;
    mE[0] = 0;
    m18[0] = 0;
}

void cScriptLoadAnimations::fn_vslot2() /* 8016972C */
{
    fn_8037B584(lbl_805C9458, m4, 9, 0);
    fn_8037B584(lbl_805C9464, mE, 9, 0);
    fn_8037B584(lbl_805C9470, m18, 9, 0);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C947C);
}

int cScriptLoadAnimations::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 801697C4 */
{
    if (fn_8040B6A0(m4) != 0) {
        fn_8016D2F4(ctx, m4);
    }
    if (fn_8040B6A0(mE) != 0) {
        fn_8016D2F4(ctx, mE);
    }
    if (fn_8040B6A0(m18) != 0) {
        fn_8016D2F4(ctx, m18);
    }
}

int cScriptLoadAnimations::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 8016985C */
{
    return 1;
}

Unk8037B3E8* cScriptLoadAnimations::fn_vslot5() /* 80169878 */
{
    return new (lbl_806EF9B4) cScriptLoadAnimations;
}

/* near-miss: 6 diff lines in the hash compares: retail merges only the first nine consecutive hashes into a range test; one instruction more here */
int Unk8016ACAC::fn_8016ACAC() /* 8016ACAC */
{
    int r = 0;
    for (int i = 0; i < 3; i++) {
        unsigned int h = m1E28[i].mA20;
        if (h - 0x0DDDB385u <= 8 || h == 0x0DDDB3A5u || h == 0x0DDDB3A6u || h == 0x0DDDB3A7u || h == 0x0DDDB3A8u
            || h == 0x0DDDB3A9u || h == 0x0DDDB3AAu) {
            r = 1;
        }
    }
    return r;
}

int Unk8016ACAC::fn_8016AD44() /* 8016AD44 */
{
    int r = 0;
    Unk8016ACAC_Slot* s = m1E28;
    for (int i = 0; i < 3; i++, s++) {
        if (s->mA20 == 0xC9D138D4) {
            r = 1;
        }
    }
    return r;
}

/* near-miss: idx != 3 flip: retail compares before moving k into idx (3 diff lines); 3 variants tried */
int Unk8016ACAC::fn_8016AD7C(int idx) /* 8016AD7C */
{
    Unk801527C8_Actor* a = m3D3C;
    if (idx > 2) {
        int k = 0;
        if (a->m6F8->m14->m1CD0 != 0) {
            k = 1;
        }
        if (idx != 3) {
            k ^= 1;
        }
        idx = k;
    }
    return m429C[idx];
}

int Unk8016ACAC::fn_8016ADC4() /* 8016ADC4 */
{
    int r = 0;
    Unk8016ACAC_Slot* s = m1E28;
    for (int i = 0; i <= 2; s++, i++) {
        int h = s->mA20;
        if (h == 0x710572A7 || h == 0x40121546 || h == 0x19A6161E || h == (int)0xE8B2B8BD) {
            r = 1;
            break;
        }
    }
    return r;
}

int Unk8016ACAC::fn_8016AE34() /* 8016AE34 */
{
    int r = 0;
    Unk8016ACAC_Slot* s = m1E28;
    for (int i = 0; i <= 2; s++, i++) {
        int h = s->mA20;
        if (h == (int)0xA45FDBA4 || h == (int)0xF3E5697C || h == (int)0x88AF32A7) {
            r = 1;
            break;
        }
    }
    return r;
}

/* near-miss: retail peels the first slot and keeps mulli indexing in the loop (22 insns vs 15); do/while, for and while forms tried */
int Unk8016ACAC::fn_8016AE94() /* 8016AE94 */
{
    int r = 0;
    for (int i = 0; i <= 2; i++) {
        if (m1E28[i].mA20 == (int)0x9A02146A) {
            r = 1;
            break;
        }
    }
    return r;
}

int Unk8016ACAC::fn_8016AEEC() /* 8016AEEC */
{
    int r = fn_8016AE94() == 0;
    if (fn_8016AE34() != 0) {
        r = 0;
    }
    if (fn_8016AF9C() != 0) {
        r = 0;
    }
    return r;
}

int Unk8016ACAC::fn_8016AF4C() /* 8016AF4C */
{
    int r = 0;
    Unk8016ACAC_Slot* s = m1E28;
    for (int i = 0; i <= 2; s++, i++) {
        int h = s->mA20;
        if (h == (int)0x99948727 || h == 0x231AA27A) {
            r = 1;
            break;
        }
    }
    return r;
}

void fn_8016B148() /* 8016B148 */
{
    lbl_80619D10->fn_800AB9A8(4);
}

int Unk8016ACAC::fn_8016B174() /* 8016B174 */
{
    for (int i = 0; i <= 7; i++) {
        if (fn_8040B6A0(m3D94[i]) != 0) {
            return 0;
        }
    }
    return fn_8016DB74((char*)this + 4);
}

void Unk8016ACAC::fn_8016B2B8() /* 8016B2B8 */
{
    fn_8016B2F0();
    m3D90 = fn_8016C39C();
}
