/*
 * Game code, .text 0x80167DCC-0x8016BF30 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80167DCC.h"

extern float lbl_805CAD10;
extern float lbl_805CAD14;

extern float lbl_805C943C;

extern const char lbl_805C7994[];
extern const char lbl_805C9458[];
extern const char lbl_805C9464[];
extern const char lbl_805C9470[];
extern const char lbl_805C947C[];

extern Unk80619D10* lbl_80619D10;
int fn_8040B6A0(const char* s);
extern void* lbl_8061E978;
void fn_802AEBF0(void* mgr, const char* s);
int fn_8016DB74(const char* s);
void fn_80030938();
void fn_80031088();
Unk8016D9A0_Rec fn_8016DC5C();
Unk801A6D84_Obj* fn_801A6D84(Unk801527C8_Actor* a, int i);
void fn_802D7ADC();
struct Unk8068B618_Obj {
    char pad0[0x2C];
    int m2C;
};
extern Unk8068B618_Obj* lbl_8068B618;
void fn_8017C72C(Unk801527C8_Slots* s);
int fn_80169DC4(char* b);
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
        ctx->fn_8016D2F4(m4);
    }
    if (fn_8040B6A0(mE) != 0) {
        ctx->fn_8016D2F4(mE);
    }
    if (fn_8040B6A0(m18) != 0) {
        ctx->fn_8016D2F4(m18);
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

/* near-miss: retail adds the +0x44 offset to the base before the indexed load (addi; lwzx) where this uses add; lwz 0x44(rX); 4 variants tried */
int fn_80169DC4(char* base) /* 80169DC4 */
{
    int p = (int)base;
    int off = 0;
    int end = (int)base + 0x460;
    do {
        if (fn_8040B6A0((char*)p) != 0) {
            int v = *(int*)(&base[0x44] + off);
            if ((unsigned int)(v - 0x2A) <= 0x30) {
                return 1;
            }
        }
        p += 0xA0;
        off += 0xA0;
    } while (p <= end);
    return 0;
}

void Unk8016ACAC_Slot::fn_8016A6AC() /* 8016A6AC */
{
    for (int i = 0; i <= 12; i++) {
        fn_8016CE5C(i + 2);
    }
    mA20 = 0;
    ((Unk801527C8_Ctx*)this)->fn_8016AC3C();
    mLists[0].fn_8016D258();
}

void Unk8016ACAC::fn_8016A7A8(Unk8016D9A0_Rec* rec) /* 8016A7A8 */
{
    if (m3D40 == 0) {
        m4.fn_8016D9A0(rec);
        m3D90 = fn_8016C39C();
    }
    if (fn_801A04A8(m3D3C, 1) == m4294) {
        fn_8017C72C(m3D3C->m700);
    }
}

void Unk8016ACAC::fn_8016A814(Unk8016D9A0_Rec* rec) /* 8016A814 */
{
    if (m3D40 == 0) {
        m4.fn_8016DA48(rec);
        m3D90 = fn_8016C39C();
    }
    if (fn_801A04A8(m3D3C, 1) == m4294) {
        fn_8017C72C(m3D3C->m700);
    }
}

/* near-miss: retail keeps this in r28 and re-forms this+0xA24 for the byte store; one instruction more in retail; 2 variants tried */
void Unk801527C8_Ctx::fn_8016AC3C() /* 8016AC3C */
{
    int off = 0;
    char* p = mA24[0];
    for (int i = 4; i != 0; i--, p += 10, off += 10) {
        if (fn_8040B6A0(p) != 0) {
            fn_802AEBF0(lbl_8061E978, p);
            mA24[0][off] = 0;
        }
    }
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

/* extern "C" like its callers' declaration (tu_80021BE8.h); retail takes the manager in r3 */
extern "C" int fn_8016ADC4(Unk8016ACAC* m) /* 8016ADC4 */
{
    int r = 0;
    Unk8016ACAC_Slot* s = m->m1E28;
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

void Unk8016ACAC::fn_8016B1D4() /* 8016B1D4 */
{
    Unk8016ACAC_Slot* s0 = m1E28;
    int a = s0->mLists[0].fn_8016C1EC();
    if ((void*)fn_801A6D84(m3D3C, 1) == (void*)this) {
        if (a != 0) {
            int b = fn_8016B174();
            float f = s0->mLists[0].fn_8016BF94();
            if (b != 0) {
                if (!(f <= lbl_805CAD10) && !(f >= lbl_805CAD14)) {
                    fn_8016B95C();
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        m1E28[i].fn_8016B3A8();
    }
    int c = s0->mLists[0].fn_8016C1EC();
    if (a != 0 && c == 0) {
        fn_8016BCCC();
    }
}

void Unk8016ACAC::fn_8016B2B8() /* 8016B2B8 */
{
    fn_8016B2F0();
    m3D90 = fn_8016C39C();
}

void Unk8016ACAC::fn_8016B2F0() /* 8016B2F0 */
{
    if (m3D40 == 0) {
        if (m4298 > 0) {
            m4298 = m4298 - 1;
            if (m4298 > 0) {
                return;
            }
            fn_8016C4FC();
            fn_80030938();
            fn_80031088();
        }
        int s = fn_8016C344();
        fn_8016B1D4();
        if (fn_8016C344() == 0) {
            Unk8016D9A0* q = &m4;
            if (q->m1E00 != 0) {
                Unk8016D9A0_Rec rec = fn_8016DC5C();
                fn_8016BBF4(&rec);
            } else if (s != 0) {
                fn_8016A880();
            }
        }
    }
}

void Unk8016ACAC::fn_8016B8CC(int x) /* 8016B8CC */
{
    if (m1E28[0].mLists[0].fn_8016C1EC() != 0) {
        int idx = -1;
        for (int i = 1; i <= 2; i++) {
            if (m1E28[i].mLists[0].fn_8016C1EC() == 0) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            m1E28[idx].mLists[0].fn_8016C004(x, 1);
        }
    }
}

void Unk8016ACAC::fn_8016B95C() /* 8016B95C */
{
    if ((void*)fn_801A6D84(m3D3C, 1) == (void*)this) {
        Unk801527C8_Actor* o = fn_801A04A8(m3D3C, 5);
        if (o != 0) {
            Unk8016ACAC* p = (Unk8016ACAC*)o->m40;
            if (p != 0) {
                if (p->m3D90 != 0) {
                    p->fn_8016C4A0();
                }
            }
        }
        lbl_80619D10->fn_v23(0xE);
        ((Unk8016DBAC_Obj*)&m4)->fn_8016DBAC();
    }
}

int Unk8016ACAC::fn_8016B9F4() /* 8016B9F4 */
{
    int r = 0;
    if (fn_80169DC4(m3D94[0]) != 0 || m4.fn_8016DBF0() != 0) {
        r = 1;
    }
    return r;
}

void Unk8016ACAC::fn_8016BA48(int x, int a, int b, Unk8015AB2C_Blk blk, int c) /* 8016BA48 */
{
    if (m3D40 == 0) {
        if (fn_801A04A8(m3D3C, 1) == m4294) {
            fn_802D7ADC();
        }
        m3D44 = b;
        if (c == 0) {
            m3D48 = blk;
        }
        if (a != 0) {
            if (fn_801A04A8(m3D3C, 1) == m4294) {
                lbl_8068B618->m2C = 10;
            }
        }
        m1E28[0].mLists[0].fn_8016C004(x, 1);
        m3D90 = fn_8016C39C();
    }
}

void Unk8016ACAC::fn_8016BB50(const char* name, int a, int b, Unk8015AB2C_Blk blk, int c) /* 8016BB50 */
{
    fn_8016BA48(fn_80378568(name, 0), a, b, blk, c);
}

/* near-miss: retail forms the destination of the 0x500-byte copy in its own register and builds the element pointer (this+0x3D94) only after the copy; here the pointer is shared. 6 forms tried */
void Unk8016ACAC::fn_8016BBF4(Unk8016D9A0_Rec* rec) /* 8016BBF4 */
{
    *(Unk8016D9A0_Rec*)m3D94 = *rec;
    fn_8016A708();
    char* p = m3D94[0];
    int off = 0;
    for (int i = 8; i != 0; i--, p += 0xA0, off += 0xA0) {
        if (fn_8040B6A0(p) != 0 && *(int*)((char*)this + 0x3DD0 + off) != 0) {
            fn_8016BF30(p);
        }
    }
    fn_8016BCCC();
}
