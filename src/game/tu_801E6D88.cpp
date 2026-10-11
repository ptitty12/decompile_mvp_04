/*
 * Game code, .text 0x801E6D88-0x801EA36C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801DB948.h"

typedef Unk801DD660 I;
typedef Unk801DB948_Vec3 Vec3;
typedef Unk80270BA0_X P;

extern const char lbl_80660AC0[];
extern const Vec3 lbl_805D4040[];
extern const Vec3 lbl_805D4070[];
extern const Vec3 lbl_805D40A0[];
extern const Vec3 lbl_805D40D0[];
extern const Vec3 lbl_805D3F98[];
extern const float lbl_805D4254;
extern const float lbl_805D4A0C;
extern float lbl_805D4A00;
extern float lbl_805D4A04;
extern float lbl_805D4A08;

struct Unk801E6D88_W {
    int m0;
    int m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    int m1C;
    int m20;
};

extern "C" void fn_801E99A0(Unk801E6D88_W* s, int a);

struct Unk801E6D88_F160 {
    char pad0[0x160];
    float m160;
};
struct Unk801E6D88_S {
    char pad0[0xC];
    char pad_c[0x20 - 0xC];
    int m20;
    int m24;
    int m28;
};

extern "C" {
int fn_802055F4(Unk801DD660_Ctx* c);
int fn_801E923C(I* i, int v);
int fn_801E9280(I* i, int v);
void fn_801E8328(I* i, int b, float f);
int fn_801A2034(Unk801DB948_Game* g, int a);
int fn_801A700C(Unk801DB948_Game* g, int a, int b);
int fn_802D7DB4(int a, int b);
void fn_801E9AC4(I* i);
void fn_801F5E18(I* i);
void fn_801F5EF0(I* i);
void fn_8014E09C(Unk801DB948_It* it, Unk801DB948_Game* g, int k);
P* fn_801A497C(Unk801DB948_Game* g, int a, int b);
int fn_802D7DB4(int a, int b);
int fn_8020543C(Unk801DD660_Ctx* c);
void fn_802053AC(Unk801DD660_Ctx* c);
void fn_80253950(void* o, void* a);
void fn_80253A30(void* o, void* a, void* b);
void fn_801F5FD4(I* s, void* a);
}

struct Unk801EA03C_A {
    char pad0[0x5B8];
    int m5B8;
};
struct Unk801EA03C_Obj {
    char pad0[0x580];
    char m580[1];
};

extern "C" void fn_801E6E48(I* s, int chrg)
{
    *(const void**)((char*)s + 0x98) = lbl_80660AC0;
    if (chrg & 1)
        operator delete(s);
}

extern "C" Vec3 fn_801E73B8(void* self, int k)
{
    return lbl_805D4040[k];
}

extern "C" Vec3 fn_801E73E8(void* self, int k, int sel)
{
    if (sel == 1)
        return lbl_805D4070[k];
    return lbl_805D40A0[k];
}

extern "C" Vec3 fn_801E7448(void* self, int k)
{
    return lbl_805D40D0[k];
}

extern "C" Vec3 fn_801E7DD0(void* self, int k)
{
    return lbl_805D3F98[k];
}

/* near-miss: retail tests a == 2 first and uses cmpwi cr7,r7,4 + LT bit for d < 4 (we get <= 3) */
extern "C" int fn_801E7FD8(void* self, int a, int b, int c, int d)
{
    int r = 0;
    if (a == 2) {
        if (b != 3)
            return r;
        r = 1;
        if (d > 5)
            return r;
        return d < 4;
    }
    if (a == 4) {
        int f = 1;
        if (b == 1)
            f = 0;
        if (f != 1)
            return r;
        r = 1;
        if (c == 9 || (c >= 12 && c <= 14))
            r = 0;
        if (d > 5)
            return r;
        if (d < 3)
            return r;
        return 0;
    }
    return r;
}

extern "C" void fn_801E8068(I* s)
{
    s->m798 = 0;
    Unk801DB948_It it;
    fn_8014E09C(&it, s->m9C->m0, 1);
    while (it.Cur() != 10) {
        P* p = fn_801A497C(s->m9C->m0, 4, it.Cur());
        if (p != 0)
            p->m71C = p->m71C & 0xFFFFBFFF;
        it.Next();
    }
}

extern "C" void fn_801E80F0(I* s, int v)
{
    if (s->m798 <= 2 && fn_801E923C(s, v) == 0) {
        int n = s->m798;
        s->m7A8[n] = v;
        s->m798 = n + 1;
        P* p = fn_801A497C(s->m9C->m0, 4, v);
        p->m71C = p->m71C | 0x4000;
    }
}

extern "C" int fn_801E816C(I* s, int i)
{
    return s->m7A8[i];
}

extern "C" int fn_801E817C(I* s, int a)
{
    if (fn_802055F4(s->m9C) == 0)
        return 0;
    return fn_801E923C(s, a);
}

extern "C" void fn_801E81C8(I* s)
{
    s->m794 = 0;
    Unk801DB948_It it;
    fn_8014E09C(&it, s->m9C->m0, 1);
    while (it.Cur() != 10) {
        P* p = fn_801A497C(s->m9C->m0, 4, it.Cur());
        if (p != 0)
            p->m71C = p->m71C & 0xFFFFDFFF;
        it.Next();
    }
}

extern "C" void fn_801E8250(I* s, int v)
{
    if (s->m794 <= 2 && fn_801E9280(s, v) == 0) {
        int n = s->m794;
        s->m79C[n] = v;
        s->m794 = n + 1;
        P* p = fn_801A497C(s->m9C->m0, 4, v);
        p->m71C = p->m71C | 0x2000;
    }
}

extern "C" int fn_801E82CC(I* s, int i)
{
    return s->m79C[i];
}

extern "C" int fn_801E82DC(I* s, int a)
{
    if (fn_802055F4(s->m9C) == 0)
        return 0;
    return fn_801E9280(s, a);
}

extern "C" int fn_801E85D0()
{
    return 1;
}

extern "C" void fn_801E8640(Unk801E6D88_F160* s, float v)
{
    s->m160 = v;
}

extern "C" float fn_801E8658(Unk801E6D88_F160* s)
{
    return s->m160;
}

extern "C" int fn_801E87C4(I* s, int a, int* out1, int b, int* out2)
{
    Unk801E6D88_S* sub = (Unk801E6D88_S*)((char*)s->m9C->m0->m700->m3B0 + 0xC);
    *out1 = sub->m28;
    if (sub->m20 == 1) {
        *out2 = sub->m24 == 1;
        return 1;
    }
    return 0;
}

static inline void CallF(I* s, int b, float f)
{
    fn_801E8328(s, b, f);
}

/* near-miss: retail returns via cmpwi r3,1; li r3,1; beq; li r3,0 instead of the xori/subfic/adde bool (10 slots) */
extern "C" int fn_801E8B80(I* s)
{
    if (fn_802055F4(s->m9C) == 0)
        return 0;
    int k = fn_801A2034(s->m9C->m0, 4);
    return fn_801A700C(s->m9C->m0, k, 0xC4) == 1;
}

/* near-miss: retail emits fmr f1,f0 before the stfs of the inline's float parameter (2 slots) */
extern "C" void fn_801E8BEC(I* s, int b)
{
    CallF(s, b, lbl_805D4254);
}

extern "C" int fn_801E90F4(I* s)
{
    int k = fn_801A2034(s->m9C->m0, 4);
    return fn_801A700C(s->m9C->m0, k, 0xC5) == 1;
}

extern "C" int fn_801E914C(I* s)
{
    int k = fn_801A2034(s->m9C->m0, 4);
    return fn_801A700C(s->m9C->m0, k, 0xC5) == 1;
}

extern "C" int fn_801E91A4(I* s)
{
    int k = fn_801A2034(s->m9C->m0, 4);
    return fn_801A700C(s->m9C->m0, k, 0xC7) == 1;
}

extern "C" int fn_801E91FC(I* s)
{
    return fn_802D7DB4(fn_801A2034(s->m9C->m0, 4), 0xBE) == 1;
}

extern "C" int fn_801E923C(I* s, int v)
{
    int n = s->m798;
    for (int i = 0; i < n; i++) {
        if (v == s->m7A8[i])
            return 1;
    }
    return 0;
}

extern "C" int fn_801E9280(I* s, int v)
{
    int n = s->m794;
    for (int i = 0; i < n; i++) {
        if (v == s->m79C[i])
            return 1;
    }
    return 0;
}

extern "C" void fn_801E98C0(I* s)
{
    fn_802053AC(s->m9C);
    s->mC0 = 0;
    Unk801DD660_Blk* b = &s->mF8;
    s->mF8.m0 = lbl_805D4A00;
    b->m4 = 0;
    b->m8 = lbl_805D4A00;
    b->mC = lbl_805D4A00;
    b->m10 = lbl_805D4A00;
    b->m14 = lbl_805D4A04;
    b->m20 = 1;
    b->m18 = lbl_805D4A08;
    b->m1C = 0;
    s->mF0 = lbl_805D4A00;
    s->mAC.m4 = -1;
    s->mE8 = lbl_805D4A00;
    s->mEC = lbl_805D4A00;
    s->mF4 = lbl_805D4A00;
    s->mAC.m0 = -1;
    fn_801E99A0((Unk801E6D88_W*)s->mC4, (int)s->m9C->m0);
    s->mBC = 1;
    s->mB8 = 0;
}

/* near-miss: float store order (3 slots) */
extern "C" Unk801E6D88_W* fn_801E9970(Unk801E6D88_W* s, int a)
{
    fn_801E99A0(s, a);
    return s;
}

/* near-miss: float store order (3 slots) */
extern "C" void fn_801E99A0(Unk801E6D88_W* s, int a)
{
    s->m1C = -1;
    s->m0 = a;
    s->m4 = 0;
    s->m8 = lbl_805D4A0C;
    s->m20 = 0;
    s->mC = lbl_805D4A0C;
    s->m18 = lbl_805D4A0C;
    s->m14 = lbl_805D4A0C;
    s->m10 = lbl_805D4A0C;
}

/* near-miss: s/f registers swapped (r29/r30) */
extern "C" void fn_801E99D8(Unk801E6D88_W* s)
{
    int f = 0;
    int k = fn_801A2034((Unk801DB948_Game*)s->m0, 4);
    if (fn_802D7DB4(k, 0xC0) != 0 || fn_802D7DB4(k, 0xC1) != 0 || fn_802D7DB4(k, 0xC2) != 0 || fn_802D7DB4(k, 0xC3) != 0)
        f = 1;
    if (f == 0)
        s->m1C = -1;
}

extern "C" void fn_801E9A74(I* s)
{
    Unk801DD660_Ctx* c = s->m9C;
    c->m3A6C = 0;
    c->m3A68 = 0;
    s->mBC = 1;
    fn_801E9AC4(s);
    s->mAC.m0 = -1;
    s->mAC.m4 = -1;
}

extern "C" void fn_801E9BE4(I* s)
{
    s->mAC.m0 = -1;
    s->mBC = 1;
    s->mAC.m4 = -1;
}

extern "C" void fn_801E9BFC(I* s)
{
    s->mBC = 1;
}

extern "C" int fn_801E9DE4(I* s)
{
    if (s->mC0 != 3)
        return -1;
    int r = s->m9C->mA4;
    if (r == -1) {
        P* p = s->m9C->m4->m36C;
        if (p != 0)
            r = p->m460;
    }
    return r;
}

extern "C" void fn_801E9E20(I* s)
{
    fn_801F5E18(s);
    fn_801F5EF0(s);
    s->m9C->m44 = 1;
}

extern "C" void fn_801E9E60(I* s)
{
    fn_801F5E18(s);
    fn_801F5EF0(s);
}

extern "C" int fn_801E9E94(I* s)
{
    Unk801DD660_Ctx* c = s->m9C;
    if ((unsigned)(c->m30 - 5) <= 2 || c->m44 == 1)
        return 1;
    return fn_8020543C(c) > 2;
}

/* near-miss: GCC shares the cur != -1 compare across the first call (cmpwi cr4 + mfcr/mtcrf), retail recomputes it (3 insns) */
extern "C" void fn_801EA03C(I* s, Unk801EA03C_A* a, P* p, int k)
{
    if (p != 0) {
        int v = p->m460;
        Unk801DD660_Hist* h = &s->mAC;
        if (v != h->m0) {
            h->m4 = h->m0;
            h->m0 = v;
        }
    }
    int cur = s->mAC.m0;
    if (cur != -1 && k != 6) {
        Unk801EA03C_Obj** tbl = (Unk801EA03C_Obj**)((char*)s->m9C + 8);
        fn_80253950(tbl[cur]->m580, a);
    }
    int prev = s->mAC.m4;
    if (prev != -1 && cur != -1 && k != 6) {
        Unk801EA03C_Obj** tbl = (Unk801EA03C_Obj**)((char*)s->m9C + 8);
        fn_80253A30(tbl[prev]->m580, a, tbl[cur]);
    }
    if (a->m5B8 != -1)
        fn_801F5FD4(s, a);
}
