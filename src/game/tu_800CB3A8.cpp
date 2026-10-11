/*
 * Game code, .text 0x800CB3A8-0x800CF178 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

extern char lbl_80687A68[0x64];
extern char lbl_80687ACC[0x64];
extern char lbl_80687B30[0x64];

#define GRID_BOOL_CELL(g, row, col) ((g)->m98[(row) * (g)->m54 + (col)])

extern "C" int fn_800CB578(Unk800CB3A8_Grid* g, int row, int col)
{
    if (g->b80_2)
        return (GRID_BOOL_CELL(g, row, col) >> 1) & 1;
    return g->fn_vslot73(row, col)->b1;
}

extern "C" int fn_800CB5E4(Unk800CB3A8_Grid* g, int row, int col)
{
    if (g->b80_2)
        return (GRID_BOOL_CELL(g, row, col) >> 2) & 1;
    return g->fn_vslot73(row, col)->b0;
}

extern "C" int fn_800CB650(Unk800CB3A8_Grid* g, int row, int col)
{
    if (g->b80_2) {
        int r = 0;
        if (GRID_BOOL_CELL(g, row, col) & 1)
            r = 1;
        return r;
    }
    return g->fn_vslot73(row, col)->b2;
}

extern "C" void fn_800CB6C8(Unk800CB3A8_Grid* g, int row, int col, float v)
{
    Unk800C7B40_Widget* w = g->fn_vslot74(row, col);
    if (w != 0)
        w->fn_vslot20(v);
    if (g->b80_2)
        g->m9C[row * g->m54 + col] = v;
}

extern "C" float fn_800CB760(Unk800CB3A8_Grid* g, int row, int col)
{
    if (g->b80_2)
        return g->m9C[row * g->m54 + col];
    return g->fn_vslot73(row, col)->fn_vslot19();
}

extern "C" void fn_800CBCE4(Unk800CB3A8_Grid* g, int a, int* arr, int c, int start, int end)
{
    int last;
    if (end == -1)
        last = g->m50 - 1;
    else
        last = end;
    for (int i = start; i <= last; i++)
        g->fn_vslot42(i, a, arr[i - start], c);
}

extern "C" void fn_800CBD84(Unk800CB3A8_Grid* g, int a, int* arr, int c, int start, int end)
{
    int last;
    if (end == -1)
        last = g->m54 - 1;
    else
        last = end;
    for (int i = start; i <= last; i++)
        g->fn_vslot42(a, i, arr[i - start], c);
}

extern "C" void fn_800CBF48(Unk800CB3A8_Grid* g, int a, int* arr, int c, int start, int end)
{
    int last;
    if (end == -1)
        last = g->m50 - 1;
    else
        last = end;
    for (int i = start; i <= last; i++)
        g->fn_vslot43(i, a, arr[i - start], c);
}

extern "C" void fn_800CBFE8(Unk800CB3A8_Grid* g, int a, int* arr, int c, int start, int end)
{
    int last;
    if (end == -1)
        last = g->m54 - 1;
    else
        last = end;
    for (int i = start; i <= last; i++)
        g->fn_vslot43(a, i, arr[i - start], c);
}

extern "C" void fn_800CC4C0(Unk800CB3A8_Grid* g, int a, int* arr, int c, int start, int end)
{
    int last;
    if (end == -1)
        last = g->m50 - 1;
    else
        last = end;
    for (int i = start; i <= last; i++)
        g->fn_vslot44(i, a, arr[i - start], c);
}

extern "C" void fn_800CC560(Unk800CB3A8_Grid* g, int a, int* arr, int c, int start, int end)
{
    int last;
    if (end == -1)
        last = g->m54 - 1;
    else
        last = end;
    for (int i = start; i <= last; i++)
        g->fn_vslot44(a, i, arr[i - start], c);
}

extern "C" char* fn_800CD2DC(Unk800CB3A8_Grid* g, int p1, int p2)
{
    int a;
    int b;
    if (g->fn_vslot112(p1, p2, &a, &b)) {
        fn_804089B4(lbl_80687A68, "X%dY%d", b, a);
        return lbl_80687A68;
    }
    return 0;
}

extern "C" int fn_800CD354(Unk800CB3A8_Grid* g, int row, int col, int* outRow, int* outCol)
{
    int c = col;
    if (g->b80_2) {
        if (row >= g->m60) {
            row -= g->m70;
            if (row < g->m60)
                return 0;
        }
        if (c >= g->m64) {
            c -= g->m74;
            if (c < g->m64)
                return 0;
        }
    }
    *outRow = row;
    *outCol = c;
    if (*outRow < 0 || *outRow >= g->m48 || c < 0 || c >= g->m4C)
        return 0;
    return 1;
}

extern "C" char* fn_800CD3E0(Unk800CB3A8_Grid* g, int id)
{
    int v = id;
    v = v == -1 ? g->m6C : v;
    if (v >= g->m64)
        v -= g->m74;
    fn_804089B4(lbl_80687ACC, "X%dHILITE", v);
    return lbl_80687ACC;
}

extern "C" char* fn_800CD44C(Unk800CB3A8_Grid* g, int id)
{
    int v = id;
    v = v == -1 ? g->m68 : v;
    if (v >= g->m60)
        v -= g->m70;
    fn_804089B4(lbl_80687B30, "Y%dHILITE", v);
    return lbl_80687B30;
}

void Unk800CD5A4_Obj::fn_800CD5A4()
{
    fn_vslot73(m68, m6C);
}

void Unk800CD5A4_Obj::fn_800CD5E4()
{
    fn_vslot74();
}

extern "C" int fn_800CD618(Unk800CB3A8_Grid* g, int p1, int p2)
{
    int a;
    int b;
    if (g->fn_vslot112(p1, p2, &a, &b))
        return g->m94[a * g->m4C + b];
    return 0;
}

extern "C" void fn_800CD690(Unk800CB3A8_Grid* g)
{
    Unk800C7B40_Widget* a = g->fn_vslot30("METER", 1);
    if (a != 0) {
        Unk800C7B40_Widget* b = ((Unk800C7B40_Widget*)fn_800C8044(a))->fn_vslot30("METERBAR", 1);
        if (b == 0)
            return;
        g->mF0 = ((Unk800C7B40_Widget*)fn_800C8038(b))->m2A;
    } else
        g->mF0 = 0.0f;
}

void Unk800CD5A4_Obj::fn_800CDA14(int a, int b, int c)
{
    fn_vslot125(a, b, 0, c, 0);
}

void Unk800CD5A4_Obj::fn_800CDA54(int a, int b, int c)
{
    fn_vslot125(a, b, c, 0, 0);
}

extern "C" void fn_800CDA90(char* s)
{
    int i = 0;
    char* p = s;
    while (i < fn_8040B6A0(s)) {
        if (*p == ',') {
            int n = fn_8040B6A0(s);
            for (int j = i + 1; j < n - 1; j++)
                *p = p[1];
            s[n - 1] = 0;
        } else {
            p++;
            i++;
        }
    }
}

extern "C" int fn_800CE23C(void* unused, const char* s)
{
    if (fn_8040B6A0(s) > 3 && s[1] == '.' && s[2] == ' ')
        return 1;
    return 0;
}

extern "C" void fn_800CE3D4(Unk800CB3A8_Grid* g, int row, int col, int flag)
{
    Unk800C7B40_Widget* w = g->fn_vslot74(row, col);
    if (w != 0) {
        if (w->m4 != 0)
            w->m4->fn_vslot17(flag);
        w->fn_vslot17(flag);
    }
    if (g->b80_2) {
        if (flag != 0)
            g->m98[row * g->m54 + col] |= 1;
        else
            g->m98[row * g->m54 + col] &= ~1;
    }
}

extern "C" void fn_800CE620(Unk800CB3A8_Grid* g, int row, int col, int flag)
{
    Unk800C7B40_Widget* w = g->fn_vslot74(row, col);
    if (w != 0)
        w->fn_vslot8(flag);
    if (g->b80_2) {
        if (flag != 0)
            g->m98[row * g->m54 + col] |= 4;
        else
            g->m98[row * g->m54 + col] &= ~4;
    }
}

extern "C" void fn_800CE6E4(Unk800CB3A8_Grid* g)
{
    g->fn_vslot14(0);
    if (g->m74 > 0)
        g->m74 = g->m74 - 1;
    g->fn_vslot14(1);
}

extern "C" void fn_800CE758(Unk800CB3A8_Grid* g)
{
    g->fn_vslot14(0);
    if (g->m74 < g->m54 - g->m5C)
        g->m74 = g->m74 + 1;
    g->fn_vslot14(1);
}

extern "C" void fn_800CE7D8(Unk800CB3A8_Grid* g, int a, int c)
{
    if (g->m50 != 0) {
        int n = g->fn_vslot58();
        for (int i = 0; i < n; i++)
            g->fn_vslot90(a, i, c);
    }
}

extern "C" void fn_800CE86C(Unk800CB3A8_Grid* g, int a, int c)
{
    if (g->m50 != 0) {
        int n = g->fn_vslot58();
        for (int i = 0; i < n; i++)
            g->fn_vslot91(a, i, c);
    }
}

extern "C" void fn_800CE900(Unk800CB3A8_Grid* g, int a, int c)
{
    if (g->m50 != 0) {
        int n = g->fn_vslot58();
        for (int i = 0; i < n; i++)
            g->fn_vslot92(a, i, c);
    }
}

extern "C" int fn_800CE994(Unk800CB3A8_Grid* g, const char* s, int* row, int* col)
{
    if (fn_80408A94(s, "X%dY%d", col, row) != 2)
        return 0;
    if (g->b80_2) {
        if (*row >= g->m60)
            *row = *row + g->m70;
        if (*col >= g->m64)
            *col = *col + g->m74;
    }
    return 1;
}

extern "C" void fn_800CEA38(Unk800CB3A8_Grid* g)
{
    g->fn_vslot14(0);
    int old = g->m68;
    g->fn_vslot118(1);
    if (old != g->m68)
        g->fn_vslot107(0x99);
    g->fn_vslot120();
    g->fn_vslot14(1);
}

extern "C" void fn_800CEAF8(Unk800CB3A8_Grid* g)
{
    g->fn_vslot14(0);
    int old = g->m68;
    g->fn_vslot118(0);
    if (old != g->m68)
        g->fn_vslot107(0x9A);
    g->fn_vslot120();
    g->fn_vslot14(1);
}

extern "C" void fn_800CEBB8()
{
}

extern "C" void fn_800CEBBC(Unk800CB3A8_Grid* g, int a)
{
    if (g->b80_8)
        fn_8001BC4C()->fn_8001BDAC(a);
}

extern "C" void fn_800CEBFC(Unk800CB3A8_Grid* g, int id)
{
    char buf[100];
    int v = id;
    v = v == -1 ? g->m68 : v;
    if (g->b80_2 && v >= g->m60)
        v -= g->m70;
    fn_804089B4(buf, "Y%dFLASH", v);
    g->fn_vslot30(buf, 1);
}

extern "C" Unk800D1614_Raw* fn_800CEEF0(Unk800D1614_Raw* self, int p1, int p2, int p3, int p4, int p5, int p6, int p7,
                                        int s1, int s2, int s3, int s4, float f)
{
    fn_800C7B40(self, p1, 3, p2, p3, p4, p5, p6, p7, s1, s3, s4, 0, f);
    self->m3C = lbl_8065CA08;
    self->m40 = 0;
    self->b7 = s2;
    return self;
}

extern "C" void fn_800CEF98(Unk800CB3A8_Grid* g)
{
    for (Unk800C7B40_Widget* c = g->m40; c != 0; c = c->m8)
        c->fn_vslot3();
}

extern "C" void fn_800CEFEC(Unk800CB3A8_Grid* g, int v)
{
    Unk800C7B40_Widget* c = g->m40;
    g->m2E = v;
    for (; c != 0; c = c->m8)
        c->fn_vslot18(v);
}

void Unk800C7A4C_Group::fn_800CF114(int v)
{
    fn_800C7E38(this, v);
    for (Unk800C7B40_Widget* c = m40; c != 0; c = c->m8)
        c->fn_vslot14(v);
}
