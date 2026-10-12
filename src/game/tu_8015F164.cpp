/*
 * Game code, .text 0x8015F164-0x80163390 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8015AA94.h"
#include "game/tu_80167DCC.h"

extern const Unk80326F44_Out lbl_805EBA10;

extern "C" void fn_80326ED4(Unk801527C8_Sub* s, float* a, float* b);

extern "C" int fn_803270C4(Unk801527C8_Sub* s, int id, int n, float t);
struct V2s80161924 { float x; float y; };
inline int Chk80161924(Unk801527C8_Sub* s, int id, int n, float t) { return fn_803270C4(s, id, n, t) != 0; }
extern "C" int fn_80176FD4__FP13Unk8017706C_Ti(void* t, int i);
extern "C" void fn_801615C0(Unk80159F28* self, int i);
struct Unk80359624 { int a; int b; int c; };
struct Unk8019F8C0_Owner;
extern const Unk8015AB2C_Blk lbl_8068B828;
void fn_80359624(Unk80359624* s);
extern "C" void fn_803596DC(void* p);
struct ElemRec8015F164 {
    char name[0x44];
    Unk80359624 x44;
    Unk80326F44_Out r50;
    Unk80326F44_Out r68;
    Unk80326F44_Out r80;
    int m98;
    int m9C;
    ElemRec8015F164();
};
inline Unk80326F44_Out DefRec8015F164() { return lbl_805EBA10; }
inline void SetRecs8015F164(ElemRec8015F164* e, Unk80326F44_Out a, Unk80326F44_Out b, Unk80326F44_Out c)
{
    e->r50 = a;
    e->r68 = b;
    e->r80 = c;
}
inline ElemRec8015F164::ElemRec8015F164()
{
    SetRecs8015F164(this, DefRec8015F164(), DefRec8015F164(), DefRec8015F164());
    fn_80359624(&x44);
    fn_803596DC(this);
}
struct Unk803597C4;
void fn_803597C4(Unk803597C4* s);
struct RecObj8015F164 {
    ElemRec8015F164 e[8];
    RecObj8015F164() { fn_803597C4((Unk803597C4*)this); }
};
Unk8016ACAC* fn_801A6D84(Unk8019F8C0_Owner* o, int i);
inline int IsValid(const Unk80326F44_Out& o)
{
    return o.m0 != 0xC7;
}

int Unk80159F28::fn_8015F164(Unk8015F164_Evt* e) /* 8015F164 */
{
    const float c = 0.6f;
    Unk80326F44_Out a = mC->m50.fn_80326F44(0x39, 0, e->m4);
    if (IsValid(a)) {
        if (a.m4 - e->m4 < c) {
            return 1;
        }
    }
    return 0;
}

Unk80326F44_Out Unk80159F28::fn_8015F1F4(Unk8015F164_Evt* e) /* 8015F1F4 */
{
    Unk801527C8_Sub* s = &mC->m50;
    const float c = 0.6f;
    int id;
    switch (e->mC) {
    case 0:
        id = 0xC0;
        break;
    case 1:
        id = 0xC1;
        break;
    case 2:
        id = 0xC2;
        break;
    case 3:
        id = 0xC3;
        break;
    default:
        return lbl_805EBA10;
    }
    Unk80326F44_Out a = s->fn_80326F44(id, 1, e->m4 - c);
    if (IsValid(a)) {
        if (!(a.m4 - e->m4 >= c)) {
            return a;
        }
    }
    return lbl_805EBA10;
}

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

int Unk80159F28::fn_8015F840() /* 8015F840 */
{
    return fn_801A4B34(mC)->fn_v4();
}

void Unk80159F28::fn_8015F87C() /* 8015F87C */
{
    Unk801527C8_Actor* a = mC;
    if (!((float)*(unsigned int*)&a->m4C * 0.016666668f > 21600.0f)) {
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

extern "C" void fn_80161924(Unk80159F28* self) /* 80161924 */
{
    int r = self->mC->m6F8->fn_8006BE18();
    if (r == 0) {
        Unk801527C8_Sub* s = &self->mC->m50;
        V2s80161924 v;
        fn_80326ED4(s, &v.x, &v.y);
        int ok = Chk80161924(s, 0x42, 1, -1.0f);
        if (ok != 0 && self->mC->m6F8->m14->m1CC9 != 3) {
            if (self->m2C != 0) {
                self->m2C = 0;
                if (fn_80176FD4__FP13Unk8017706C_Ti(self->mC->m700->m3A8, 1) != 0) {
                    fn_801615C0(self, 1);
                }
            } else if (self->m28 != 0) {
                self->m28 = 0;
                if (fn_80176FD4__FP13Unk8017706C_Ti(self->mC->m700->m3A8, 0) != 0) {
                    fn_801615C0(self, 0);
                }
            }
        }
    }
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

extern "C" int fn_80162664(Unk80159F28* self) /* 80162664 */
{
    if (self->m1C == 0) {
        return 0;
    }
    RecObj8015F164 rec;
    self->fn_80157514(0x63, (int)&rec, 1, 0x26, 0, lbl_8068B828);
    fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    return 1;
}

extern "C" int fn_80162850(Unk80159F28* self) /* 80162850 */
{
    if (self->m20 == 0) {
        return 0;
    }
    RecObj8015F164 rec;
    self->fn_80157514(0x64, (int)&rec, 1, 0x27, 0, lbl_8068B828);
    fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    return 1;
}

extern "C" int fn_80162A3C(Unk80159F28* self) /* 80162A3C */
{
    if (self->m24 == 0) {
        return 0;
    }
    RecObj8015F164 rec;
    self->fn_80157514(0x65, (int)&rec, 1, 0x28, 0, lbl_8068B828);
    fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    return 1;
}
