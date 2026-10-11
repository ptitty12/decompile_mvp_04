/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80034BBC-0x80035DF0 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80034BBC.h"

struct Unk80034E14 : public Unk80034D00 {
    int mC;
    int m10;
};

extern "C" void fn_80034BBC(Unk80034B94* self, int chrg)
{
    self->mC = lbl_80649D70;
    if (self->m8 == 1)
        fn_80030C90(fn_80030938(), self->m0);
    if (chrg & 1)
        operator delete(self);
}

extern "C" void fn_80034C1C(Unk80034B94* self, int a, int b, int c)
{
    fn_80030EA4(fn_80030938(), self->m0, a, b, c);
}

extern "C" void fn_80034C68(Unk80034B94* self, float f)
{
    fn_80030F18(fn_80030938(), self->m0, f);
}

extern "C" void fn_80034CA4(Unk80034B94* self)
{
    if (self->m8 == 0) {
        self->m0 = fn_800309AC(fn_80030938(), self, self->m4);
        self->m8 = 1;
    }
    fn_80030F94(fn_80030938(), self->m0);
}

extern "C" Unk80034D00* fn_80034D00(Unk80034D00* self, int a)
{
    self->SetVptr(lbl_80649A90);
    self->m0 = a;
    self->m4 = 0;
    return self;
}

extern "C" void fn_80034D20(Unk80034D00* self, int chrg)
{
    self->SetVptr(lbl_80649A90);
    if (chrg & 1)
        operator delete(self);
}

void Unk80034D00::v2(void* p)
{
    unsigned char* q = (unsigned char*)p;
    unsigned char b1 = q[1];
    int hit = 0;
    unsigned int u = b1 >> 6;
    unsigned int v = (b1 >> 4) & 3;
    unsigned int w = b1 & 0xF;
    if ((unsigned int)fn_8040ABA0() % 100 < q[0]) {
        hit = 1;
        fn_80039A3C(w, v, m4);
    }
    if ((hit == 0 || u == 0) && (unsigned int)fn_8040ABA0() % 100 < q[2]) {
        unsigned char c = q[3];
        fn_80039A3C(c & 0xF, (c >> 4) & 3, m4);
    }
}

extern "C" Unk80034E14* fn_80034E14(Unk80034E14* self)
{
    fn_80034D00(self, 3);
    self->SetVptr(lbl_806499D0);
    self->mC = -1;
    self->m10 = -1;
    return self;
}

extern "C" void fn_80034E60(Unk80034E14* self, int chrg)
{
    self->SetVptr(lbl_806499D0);
    fn_80035E94((int)self);
    fn_80034D20(self, chrg);
}

#define TBL ((Unk80038EB4_Tbl*)fn_80038EB4())

extern "C" void fn_80034EA8(Unk80034E14* self, unsigned int a, unsigned int b, int c)
{
    if (a <= 1 && b <= 3 && c >= 0 && c <= 3 && c >= 0)
        self->v2(&TBL->m500[a][b][c]);
}

extern "C" void fn_80034F3C(Unk80034E14* self, unsigned int a, int b, unsigned int c, int d)
{
    if (a <= 1 && b != 0 && (unsigned int)b <= 3 && c <= 2 && d <= 3 && d >= 0)
        self->v2(&TBL->m0[a][b][c][d]);
}

extern "C" void fn_80034FE4(Unk80034E14* self, unsigned int a, unsigned int b, int c, int d)
{
    if (a <= 1 && b <= 3 && c != 0 && (unsigned int)c <= 2 && d <= 3 && d >= 0)
        self->v2(&TBL->m180[a][b][c][d]);
}

extern "C" void fn_80035090(Unk80034E14* self, unsigned int a, int b, int c, int d)
{
    if (a <= 1 && b != 0 && (unsigned int)b <= 3 && c >= 0 && c <= 9 && d <= 3 && d >= 0)
        self->v2(&TBL->m580[a][b][c][d]);
}

extern "C" void fn_8003514C(Unk80034E14* self, unsigned int a, unsigned int b, int c, int d)
{
    if (a <= 1 && b <= 3 && c != 0 && (unsigned int)c <= 2 && d <= 3 && d >= 0)
        self->v2(&TBL->m300[a][b][c][d]);
}

extern "C" void fn_800351F8(Unk80034E14* self, unsigned int a, int b, int c, int d)
{
    if (a <= 1 && b != 0 && (unsigned int)b <= 3 && c >= 0 && c <= 9 && d <= 3 && d >= 0)
        self->v2(&TBL->mA80[a][b][c][d]);
}

extern "C" void fn_800352B4(Unk80034E14* self, unsigned int a, int b, int c, int d, int e)
{
    int t = (c == 1);
    if (a <= 1 && b != 0 && (unsigned int)b <= 3 && d >= 0 && d <= 9 && e <= 3 && e >= 0)
        self->v2(&TBL->mF80[a][b][t][d][e]);
}

extern "C" void fn_8003538C(Unk80034E14* self, unsigned int a, unsigned int b, int c)
{
    if (a <= 1 && b <= 3 && c >= 0 && c <= 3 && c >= 0)
        self->v2(&TBL->m480[a][b][c]);
}

extern "C" void fn_80035420(Unk80034E14* self, unsigned int a, int b, int c)
{
    if (a <= 1 && b >= 0 && b <= 2 && c <= 3 && c >= 0)
        self->v2(&TBL->m1980[a][b][c]);
}

extern "C" void fn_800354B8(Unk80034E14* self, unsigned int a, int b, int c, int d)
{
    if (a <= 1 && b >= 0 && b <= 4 && c >= 0 && c <= 4)
        self->v2(&TBL->m19E0[a][b][c][d]);
}

extern "C" void fn_8003555C(Unk80034E14* self, unsigned int a, int b, int c, int d, int e, int f)
{
    if (a <= 1 && b >= 0 && b <= 4 && c >= 0 && c <= 2 && f <= 3 && f >= 0) {
        self->m4 = e;
        self->v2(&TBL->m1B70[a][b][c][d][f]);
    }
}

extern "C" void fn_80035628(Unk80034E14* self, unsigned int a, int b, int c, int d, int e, int f, int g)
{
    if (a <= 1 && b >= 0 && b <= 4 && c >= 0 && c <= 4 && g <= 3 && g >= 0) {
        self->m4 = f;
        self->v2(&TBL->m1F30[a][b][c][d][e][g]);
    }
}

extern "C" void fn_80035700(Unk80034E14* self, unsigned int a, int b, int c, int d, int e, int f)
{
    int t = (c == 1);
    int u = (e == 1);
    if (a <= 1 && b != 0 && (unsigned int)b <= 3 && d >= 0 && d <= 9 && f <= 3 && f >= 0)
        self->v2(&TBL->m30B0[a][b][t][d][u][f]);
}

extern "C" void fn_800357F4(Unk80034E14* self, unsigned int a, int b, int c, int d, int e, int f)
{
    int t = (c == 1);
    int u = (d == 1);
    int v = (e == 1);
    if (a <= 1 && b >= 0 && b <= 4 && f <= 3 && f >= 0)
        self->v2(&TBL->m2BB0[a][b][t][u][v][f]);
}

extern "C" void fn_800358D0(Unk80034E14* self, unsigned int a, int b, unsigned int c, int d, int e, int f)
{
    int t = (d == 1);
    if (a <= 1 && c <= 3 && c != 0 && b <= 2 && b >= 0 && e <= 2 && e >= 0 && f <= 3 && f >= 0)
        self->v2(&TBL->m2BB0[a][b][c][t][e][f]);
}

extern "C" void fn_800359BC(Unk80034E14* self, unsigned int a, unsigned int b, int c)
{
    if (a <= 1 && b <= 4 && b != 0 && c <= 3 && c >= 0)
        self->v2(&TBL->m4DB0[a][b - 1][c]);
}

extern "C" void fn_80035A58(Unk80034E14* self, unsigned int a, int b, int c)
{
    int t = (b == 1);
    if (a <= 1 && c <= 3 && c >= 0)
        self->v2(&TBL->m4E30[a][t][c]);
}

extern "C" void fn_80035AE8(void* self, int a, unsigned int b)
{
    if (a == 1) {
        if (b > 3) {
            fn_80039A3C(0, 1, 0);
        } else if (b == 3) {
            fn_80039A3C(0, 0, 0);
        } else if (b == 2) {
            fn_80039A3C(3, 1, 0);
        }
    } else if (a == 0) {
        if (b > 3) {
            fn_80039A3C(4, 2, 0);
        } else if (b == 3) {
            fn_80039A3C(4, 1, 0);
        } else if (b == 2) {
            fn_80039A3C(4, 0, 0);
        }
    }
}

extern "C" void fn_80035B90(void* self, int a, int b)
{
    if (a == 1) {
        switch (b) {
        case 0:
            fn_80039A3C(3, 0, 0);
            break;
        case 1:
            if (fn_8040ABA0() % 100 > 0x31)
                fn_80039A3C(3, 2, 0);
            else
                fn_80039A3C(3, 1, 0);
            break;
        case 2:
            fn_80039A3C(3, 0, 0);
            break;
        case 3:
            if (fn_8040ABA0() % 100 <= 0x18)
                fn_80039A3C(4, 0, 0);
            fn_80039A3C(4, 1, 0);
            break;
        }
    } else if (a == 0) {
        switch (b) {
        case 0:
            fn_80039A3C(7, 0, 0);
            break;
        case 1:
            if (fn_8040ABA0() % 100 > 0x31)
                fn_80039A3C(7, 2, 0);
            else
                fn_80039A3C(7, 1, 0);
            break;
        case 2:
            fn_80039A3C(7, 0, 0);
            break;
        case 3:
            if (fn_8040ABA0() % 100 > 0x31)
                fn_80039A3C(5, 1, 0);
            else
                fn_80039A3C(7, 1, 0);
            break;
        }
    }
}

extern "C" void fn_80035D4C(Unk80034E14* self)
{
    self->mC = fn_800412AC(fn_8004072C(), 0x43, 0, 0, 0, 0);
}

extern "C" void fn_80035D94(Unk80034E14* self)
{
    if (self->mC != -1)
        fn_8004181C(fn_8004072C(), 0x43, self->mC, 0, 0, 0, 0);
    self->mC = -1;
}
