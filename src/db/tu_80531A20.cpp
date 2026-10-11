/*
 * Database overlay code, .database_codeoverlay 0x80531A20-0x80534078 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"
#include "game/tu_8052A220.h"

extern float lbl_805FE96C;
extern float lbl_805FE9D0;
extern float lbl_805FE9F0;
extern float lbl_805FEA0C;
extern float lbl_805FEA24;
extern float lbl_805FEA3C;
extern float lbl_805FEA50;
extern float lbl_805FEA68;
extern float lbl_805FEAB0;
extern float lbl_805FEAC8;
extern float lbl_805FEAE4;
extern float lbl_805FEAF8;
extern float lbl_805FEAF4;
extern float lbl_805FE9E4;
extern "C" float fn_80532050(Unk80531D2C_T3* self, int a, int b, int c);
extern float lbl_805FE9EC;
extern float lbl_805FEA64;
extern float lbl_805FEAAC;
extern float lbl_805FEAC4;
extern float lbl_805FEAE0;
extern "C" float fn_80532DA0(Unk80532D68_T* self, int i);
extern "C" float fn_80533108(Unk80531A20_Tbl<10, 4>* self, int i, int j);

extern "C" DB_OVERLAY void fn_80531A20(Unk80531A20_T14* self)
{
    unsigned i;
    for (i = 0; i <= 13; i++) {
        self->m8[i] = lbl_805FE96C;
        unsigned j;
        for (j = 0; j < 5; j++)
            self->m40[i][j] = lbl_805FE96C;
    }
}

extern "C" DB_OVERLAY float fn_80531D04(Unk80531A20_T14* self, int i)
{
    return self->m8[i];
}

extern "C" DB_OVERLAY float fn_80531D14(Unk80531A20_T14* self, int i, int j)
{
    return self->m40[i][j];
}

extern "C" DB_OVERLAY void fn_80531D2C(Unk80531D2C_T3* self)
{
    unsigned i;
    for (i = 0; i <= 4; i++) {
        unsigned j;
        for (j = 0; j <= 7; j++) {
            unsigned k;
            for (k = 0; k < 20; k++)
                self->m8[i][j][k] = lbl_805FE9D0;
        }
    }
}

extern "C" DB_OVERLAY float fn_80532050(Unk80531D2C_T3* self, int a, int b, int c)
{
    return self->m8[a][b][c];
}

extern "C" DB_OVERLAY void fn_80532078(Unk80531D2C_T3* self, int a, int b, int c, float f)
{
    self->m8[a][b][c] = f;
}

extern "C" DB_OVERLAY int fn_805320B0(Unk80531D2C_T3* self, int a, int b, float x)
{
    int r = 0;
    float acc = lbl_805FE9E4;
    unsigned i;
    for (i = 0; i <= 19; i++) {
        acc = acc + fn_80532050(self, a, b, i);
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_80532144(Unk80531A20_Tbl<20, 3>* self, int i, int j, float f)
{
    if (i <= 0x13 && j <= 2)
        self->m8[i][j] = f;
}

/* near-miss: loop and exits match; retail keeps the result in r3 (base pointer in r10) and branches
 * the first compare with blt, ours reuses r3 for the base. */
extern "C" DB_OVERLAY int fn_8053217C(Unk80531A20_Tbl<20, 3>* self, int col, float x)
{
    float acc = lbl_805FE9EC;
    int r = 0;
    unsigned i = 0;
    acc = acc + self->m8[0][col];
    if (!(x < acc)) {
        while (++i <= 19) {
            acc = acc + self->m8[i][col];
            if (!(x >= acc)) {
                r = i;
                break;
            }
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_80532200(Unk80531A20_Tbl<20, 3>* self)
{
    unsigned i;
    for (i = 0; i <= 0x13; i++) {
        unsigned j;
        for (j = 0; j < 3; j++)
            self->m8[i][j] = lbl_805FE9F0;
    }
}

extern "C" DB_OVERLAY void fn_805323E0(Unk80531A20_Tbl<20, 5>* self, int i, int j, float f)
{
    if (i <= 0x13 && j <= 4)
        self->m8[i][j] = f;
}

extern "C" DB_OVERLAY void fn_80532418(Unk80531A20_Tbl<20, 5>* self)
{
    unsigned i;
    for (i = 0; i <= 0x13; i++) {
        unsigned j;
        for (j = 0; j < 5; j++)
            self->m8[i][j] = lbl_805FEA0C;
    }
}

extern "C" DB_OVERLAY void fn_805325F8(Unk805325F8_T20* self)
{
    unsigned i;
    for (i = 0; i < 20; i++)
        self->m8[i] = lbl_805FEA24;
}

extern "C" DB_OVERLAY void fn_80532764(Unk80531A20_Tbl<20, 2>* self, int i, int j, float f)
{
    if (i <= 0x13)
        self->m8[i][j] = f;
}

extern "C" DB_OVERLAY void fn_80532794(Unk80531A20_Tbl<20, 2>* self)
{
    unsigned i;
    for (i = 0; i <= 0x13; i++) {
        unsigned j;
        for (j = 0; j <= 1; j++)
            self->m8[i][j] = lbl_805FEA3C;
    }
}

extern "C" DB_OVERLAY void fn_80532A18(Unk80532A18_T4* self)
{
    unsigned a;
    for (a = 0; a <= 6; a++) {
        unsigned b;
        for (b = 0; b <= 2; b++) {
            unsigned c;
            for (c = 0; c <= 1; c++) {
                unsigned d;
                for (d = 0; d <= 1; d++)
                    self->m8[a][b][c][d] = lbl_805FEA50;
            }
        }
    }
}

extern "C" DB_OVERLAY void fn_80532D68(Unk80532D68_T* self, int i, int a, float f, int b, int c)
{
    self->m8[i].m0 = a;
    self->m8[i].m4 = f;
    self->m8[i].m8 = b;
    self->m8[i].mC = c;
}

extern "C" DB_OVERLAY float fn_80532DA0(Unk80532D68_T* self, int i)
{
    return self->m8[i].m4;
}

extern "C" DB_OVERLAY int fn_80532DB0(Unk80532D68_T* self, float x)
{
    int r = 0;
    float acc = lbl_805FEA64;
    unsigned i;
    for (i = 0; i <= 14; i++) {
        acc = acc + fn_80532DA0(self, i);
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_80532E34(Unk80532D68_T* self)
{
    unsigned i;
    for (i = 0; i < 15; i++) {
        self->m8[i].m0 = 0;
        self->m8[i].m4 = lbl_805FEA68;
        self->m8[i].m8 = 0;
        self->m8[i].mC = 0;
    }
}

extern "C" DB_OVERLAY void fn_805330E0(Unk80531A20_Tbl<10, 4>* self, int i, int j, float f)
{
    self->m8[i][j] = f;
}

extern "C" DB_OVERLAY float fn_80533108(Unk80531A20_Tbl<10, 4>* self, int i, int j)
{
    return self->m8[i][j];
}

extern "C" DB_OVERLAY int fn_80533120(Unk80531A20_Tbl<10, 4>* self, int col, float x)
{
    int r = 0;
    float acc = lbl_805FEAAC;
    unsigned i;
    for (i = 0; i <= 9; i++) {
        acc = acc + fn_80533108(self, i, col);
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_805331AC(Unk80531A20_Tbl<10, 4>* self)
{
    unsigned i;
    for (i = 0; i <= 9; i++) {
        unsigned j;
        for (j = 0; j < 4; j++)
            self->m8[i][j] = lbl_805FEAB0;
    }
}

extern "C" DB_OVERLAY void fn_805334B0(Unk805334B0_T* self, int a, int c, float f)
{
    unsigned k = c - 0x42;
    if (k <= 0x12) {
        self->m8[k].m8 = c;
        self->m8[k].m4 = a;
        self->m8[k].m0 = f;
    }
}

extern "C" DB_OVERLAY int fn_805334EC(Unk805334B0_T* self, unsigned i)
{
    int r = 0;
    if (i <= 0x12)
        r = self->m8[i].m4;
    return r;
}

extern "C" DB_OVERLAY int fn_8053350C(Unk805334B0_T* self, unsigned i)
{
    int r = 0x42;
    if (i <= 0x12)
        r = self->m8[i].m8;
    return r;
}

extern "C" DB_OVERLAY int fn_8053352C(Unk805334B0_T* self, float x)
{
    int r = 0;
    float acc = lbl_805FEAC4;
    unsigned i;
    for (i = 0; i <= 18; i++) {
        acc = acc + self->m8[i].m0;
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_805335A8(Unk805334B0_T* self)
{
    unsigned i;
    for (i = 0; i < 19; i++) {
        self->m8[i].m8 = 0;
        self->m8[i].m4 = 0;
        self->m8[i].m0 = lbl_805FEAC8;
    }
}

extern "C" DB_OVERLAY void fn_805337C8(Unk805337C8_T* self, int v, int c, float f)
{
    unsigned k = (unsigned)(v - 0x96) / 10;
    if (k <= 13 && c <= 2) {
        self->m8[c][k].m0 = f;
        self->m8[c][k].m4 = v;
    }
}

extern "C" DB_OVERLAY int fn_8053381C(Unk805337C8_T* self, int a, unsigned b)
{
    int r = 0;
    if (a <= 2 && b <= 13)
        r = self->m8[a][b].m4;
    return r;
}

extern "C" DB_OVERLAY int fn_8053384C(Unk805337C8_T* self, int row, float x)
{
    int r = 0;
    float acc = lbl_805FEAE0;
    unsigned i;
    for (i = 0; i <= 13; i++) {
        acc = acc + self->m8[row][i].m0;
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_805338D0(Unk805337C8_T* self)
{
    unsigned i;
    for (i = 0; i <= 2; i++) {
        unsigned j;
        for (j = 0; j < 14; j++) {
            self->m8[i][j].m0 = lbl_805FEAE4;
            self->m8[i][j].m4 = 0;
        }
    }
}

extern "C" DB_OVERLAY void fn_80533B74(Unk80533B74_T* self, int v, int c, int d)
{
    unsigned k = (unsigned)(v - 0x96) / 10;
    unsigned r = c - 0x42;
    if (k <= 13 && r <= 18)
        self->m8[r][k] = d;
}

extern "C" DB_OVERLAY int fn_80533BB4(Unk80533B74_T* self, int v, int c)
{
    int out = 0;
    unsigned k = (unsigned)(v - 0x96) / 10;
    unsigned r = c - 0x42;
    if (k <= 13 && r <= 18)
        out = self->m8[r][k];
    return out;
}

extern "C" DB_OVERLAY void fn_80533BFC(Unk80533B74_T* self)
{
    unsigned i;
    for (i = 0; i <= 18; i++) {
        unsigned j;
        for (j = 0; j < 14; j++)
            self->m8[i][j] = 0;
    }
}

extern "C" DB_OVERLAY int fn_80533D80(Unk80533E14_T* self, int row, float x)
{
    int r = 2;
    float acc = lbl_805FEAF4;
    unsigned i;
    for (i = 0; i <= 13; i++) {
        acc = acc + self->m8[row][i];
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_80533E14(Unk80533E14_T* self)
{
    unsigned i;
    for (i = 0; i <= 13; i++) {
        unsigned j;
        for (j = 0; j < 14; j++)
            self->m8[i][j] = lbl_805FEAF8;
    }
}
