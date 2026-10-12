/*
 * Game code, .text 0x800D833C-0x800DC0F4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800D833C.h"

int fn_800D833C(void* t, int idx)
{
    Unk800D8304_Row2* row = &lbl_8061AC5C[idx];
    return (row->m4 >> 12) & 1;
}

int fn_800D8358(void* t, int idx)
{
    Unk800D8304_Row2* row = &lbl_8061AC5C[idx];
    return (row->m4 >> 13) & 1;
}

int fn_800D8374(void* t, int idx)
{
    Unk800D8304_Row2* row = &lbl_8061AC5C[idx];
    return (row->m4 >> 14) & 1;
}

int fn_800D8390(char* t, int idx)
{
    char* b = t + 4;
    int off = idx * 0xC;
    return *(int*)(b + off);
}

int fn_800D83A0()
{
    return fn_80552D98() == 0;
}

int fn_800D867C()
{
    int r;
    if (fn_8007DA28(lbl_8061930C) != -1) {
        int o = lbl_8061930C;
        r = fn_800B5520(fn_8007D098(o, fn_8007DA28(o), 0)) == 0x12;
    } else {
        r = 1;
    }
    return r;
}

int fn_800D86E8(float p)
{
    int r = fn_8040ABA0() % 10000;
    return (float)r * lbl_805BD490 < p;
}

Unk800D876C_A* fn_800D876C(Unk800D876C_A* t)
{
    t->m0 = -1;
    t->m4 = -1;
    t->m8 = 0;
    t->mC = 0;
    return t;
}

void fn_800D878C(Unk800D876C_A* t)
{
    t->m0 = lbl_8061A328;
    lbl_806192E0->m4->m10->m120 = 0;
}

void fn_800D87B4(Unk800D876C_A* t)
{
    t->m4 = lbl_8061A328;
}

int fn_800D87C4(Unk800D876C_A* t)
{
    int a = t->m0;
    int e = a + 0x708;
    if (t->m8 == 0 && a != -1 && lbl_8061A328 > e) {
        fn_800DA544(t, 0);
        return 1;
    }
    return 0;
}

/* near-miss: three separate return paths; retail loads the 1 result before the final compare and keeps the sprintf buffer address last */
int fn_800D8820(Unk800D876C_A* t)
{
    int r;
    if (lbl_8061ADE4 != 0) {
        if (lbl_8061ADE8 != 0 && lbl_8062151C == 0) {
            lbl_8061ADE8 = lbl_8062151C;
            int sp20 = lbl_8062151C;
            char buf[0x18];
            fn_804089B4(buf, lbl_805BD4B4, lbl_805BD4B8);
            fn_803FEBDC(buf, 6, 0x64, &sp20);
            fn_803FEC9C(sp20, 0x64);
            r = 1;
        } else
            r = 0;
    } else {
        Unk800DB5F4_S* g = fn_800B555C();
        int f = 0;
        if (fn_800B59DC(g) != 0 || fn_800B5A70(fn_800B555C()) != 0 || fn_800B5B40(fn_800B555C()) != 0)
            f = 1;
        int m = 0x3C;
        if (f != 0)
            m = 0xA;
        int e = t->m4;
        r = 1;
        if (e == -1 || !(lbl_8061A328 > e + m * 0xE10))
            r = 0;
    }
    return r;
}

void fn_800D92D8(void* t)
{
    int r = fn_8040ABA0() % 3;
    switch (r) {
    case 0:
        fn_800D8EE0(t, 4);
        break;
    case 1:
        fn_800D8EE0(t, 5);
        break;
    default:
        fn_800D9360(t, 7);
        break;
    }
}

static inline int Adv9C18()
{
    int v = lbl_8061ADFC + 1;
    lbl_8061ADFC = v;
    int t = 0;
    if (v <= 0x56)
        t = v;
    lbl_8061ADFC = t;
    return t;
}

Unk80084910_N fn_800D9978(int a, int b)
{
    char buf[0x40] = "";
    Unk80084910_N r;
    int ok = 0;
    Unk80084910_N* rp = &r;
    rp->m0 = ok;
    rp->m4 = ok;
    do {
        int rnd;
        do {
            rnd = fn_8040ABA0() % 15;
            r.m0 = b;
            r.m4 = rnd;
            fn_80086078(&r, buf);
        } while (fn_803FEE14(buf, 0x64) == 0);
        ok = 1;
        if (fn_802C3A2C(b, rnd) == 0)
            ok = 0;
    } while (ok == 0);
    return r;
}

enum E9A64 { E9A64_Neg = -1, E9A64_Lo = 10, E9A64_Hi = 85 };
int fn_800D9A64(int unused)
{
    int r;
    int ok;
    do {
        r = fn_8040ABA0() % 87;
        switch ((E9A64)r) {
        case 10:
        case 34:
        case 37:
        case 38:
        case 71:
        case 72:
        case 77:
        case 79:
        case 80:
        case 81:
        case 83:
        case 85:
            ok = 0;
            break;
        default:
            ok = 1;
            break;
        }
    } while (!ok);
    return r;
}

int fn_800D9B24(int a)
{
    int r;
    if (fn_800D86E8(lbl_805BD790) == 0) {
        int x = fn_800D9EBC(a, 0);
        int y = fn_800DA1AC(a);
        r = fn_80076058(fn_80075D80(fn_800B5520(x)), y);
    } else {
        r = fn_800D9A64(a);
    }
    return r;
}

int fn_800D9B9C(int unused)
{
    int r;
    int ok;
    do {
        r = fn_8040ABA0() % 87;
        switch (r) {
        case 34:
        case 37:
        case 38:
        case 85:
            ok = 0;
            break;
        default:
            ok = 1;
            break;
        }
    } while (!ok);
    return r;
}

/* near-miss: 35 vs 36 insns; retail compares a register copy (`mr r0,r10`) of the wrapped counter after each step */
int fn_800D9C18(int unused)
{
    int r = Adv9C18();
    if (r == 0x22 || r == 0x55) {
        r = Adv9C18();
        if (r == 0x22 || r == 0x55)
            Adv9C18();
    }
    return lbl_8061ADFC;
}

int fn_800D9CA8(Unk800D876C_A* t)
{
    switch (t->mC) {
    case 0:
        if (fn_800D86E8(lbl_805BD794) == 0 && fn_800D867C() == 0) {
            return fn_800D9B24((int)t);
        }
        break;
    case 1:
        return fn_800D9B9C((int)t);
    case 2:
        return fn_800D9C18((int)t);
    }
    return fn_800D9A64((int)t);
}

extern "C" int rand();
extern "C" int fn_8055B000(void* t, int key, unsigned col);

extern const float lbl_805BD798;
extern "C" int rand();

int fn_800D9D44(int a, int b)
{
    int r;
    if (b == 0) {
        int ok;
        do {
            r = rand() % 124;
            switch (r) {
            case 0 ... 25:
            case 27 ... 28:
                ok = 1;
                break;
            case 32:
            case 35:
            case 38:
            case 41:
            case 51:
            case 54 ... 56:
            case 59:
            case 61:
            case 63:
            case 65:
            case 71:
            case 73:
            case 80 ... 84:
            case 88:
                ok = fn_800D86E8(lbl_805BD798);
                break;
            default:
                ok = 0;
                break;
            }
        } while (ok == 0);
    } else {
        r = rand() % 124;
    }
    return fn_800B548C(r);
}

int fn_800D9EBC(int a, int mode)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int g = s->fn_8007D098(s->fn_8007DA28(), 0);
    int r = fn_800B5520(g);
    if (mode == 1) {
        if (s->fn_80078A38(g) == 0) {
            int q = (rand() % 900) / 300;
            r = fn_800B5520(fn_8055B000(*(void**)((char*)s + 0x68), g, q));
        } else {
            int cur = s->fn_8007B8C4(1, g);
            do {
                r = rand() % 124;
                g = fn_800B548C(r);
            } while (cur != s->fn_8007B8C4(1, g));
        }
    }
    return fn_800B548C(r);
}

int fn_800D9FF0(int a, int b)
{
    return fn_800B548C(fn_8040ABA0() % 0x7C);
}

int fn_800DA038(int a, int b)
{
    lbl_8061AE00++;
    int r = 0;
    if (lbl_8061AE00 <= 0x7B) {
        r = lbl_8061AE00;
    }
    lbl_8061AE00 = r;
    return fn_800B548C(r);
}

int fn_800DA07C(Unk800D876C_A* t, int u)
{
    switch (t->mC) {
    case 0:
        if (fn_800D86E8(lbl_805BD79C) == 0 && fn_800D867C() == 0) {
            return fn_800D9EBC((int)t, u);
        }
        break;
    case 1:
        return fn_800D9FF0((int)t, u);
    case 2:
        return fn_800DA038((int)t, u);
    }
    return fn_800D9D44((int)t, u);
}

int fn_800DA12C(int a, Unk800DA12C_B* b)
{
    return b->m2C;
}

int fn_800DA134()
{
    return fn_8040ABA0() % 4;
}

int fn_800DA16C(Unk800D876C_A* t, Unk800DA12C_B* u)
{
    int m = t->mC;
    if (m != 0) {
        if (m >= 0) {
            if (m <= 2) {
                return fn_800DA134();
            }
        }
    }
    return fn_800DA12C((int)t, u);
}

int fn_800DA1AC(int a)
{
    return (fn_8040ABA0() % 0x708) / 600;
}

void fn_800DA3D8(Unk800D876C_A* t, int idx)
{
    Unk800DA3D8_Game* g = lbl_8061B8C0->m8;
    char* base = g->m6F8->m14;
    int o = idx * 0xE64;
    char* rec = base + o + 0x3E8;
    fn_8017DE28(g->m700, fn_801A49F0(g, idx, *(int*)(rec + (*(Unk800DA3D8_Ev**)(base + o))->m1 * 0x34)));
    fn_8017DE28(g->m700, fn_801A49F0(g, idx, *(int*)(rec + (*(Unk800DA3D8_Ev**)(base + o))->m2 * 0x34)));
}

void fn_800DA544(Unk800D876C_A* t, int v)
{
    t->m10 = v;
}

int fn_800DB530(int a, int b)
{
    int n = fn_8007FC20(lbl_8061930C, a, b);
    int m = n + 1;
    if (n == 0) {
        return 1;
    }
    int k = m > 9 ? 9 : m;
    int s = fn_8007FD2C(lbl_8061930C, a, 0, b);
    s = s - fn_8007FC40(lbl_8061930C, a, 0, k - 1, b);
    int u = fn_8007FD2C(lbl_8061930C, a, 1, b);
    if (s > u) {
        return n;
    }
    return m;
}

void fn_800DB5F4()
{
    int v = lbl_8061B2B4;
    if (v != 0) {
        fn_800DB7DC();
    } else {
        fn_800B555C()->m558 = v;
        fn_800B555C()->m55C = v;
    }
    fn_800A1C54(lbl_80619948, 2, 2, 0, 0, 0xA2);
    lbl_8061B2B4 = 1;
}

void fn_800DB7DC()
{
    if (lbl_8061B2B4 != 0) {
        int o = lbl_8061930C;
        fn_8007F858(o);
        fn_8007F8E4(o, 0);
        fn_800766B8(o, 0);
        lbl_8061B2B4 = 0;
    }
}

void fn_800DB840(Unk800DB840_Slot* o, int a, int idx, int b, int c, int d)
{
    if (o == 0) {
        fn_80073710(lbl_8061930C, a, b, d);
    } else {
        Unk800DB840_Slot* p = o + idx;
        fn_80097620(p, a, fn_800968C0(p, b, 1), c);
    }
}

void fn_800DB8B8(Unk800DB840_Slot* o, int a, int idx, int b, int c, int d)
{
    if (o == 0) {
        fn_80074754(lbl_8061930C, a, b, d);
    } else {
        Unk800DB840_Slot* p = o + idx;
        fn_8009764C(p, a, fn_800968C0(p, b, 1), c);
    }
}

void fn_800DB930(Unk800DB840_Slot* o, int a, int idx, int b, int c, int d)
{
    if (o == 0) {
        fn_800748D4(lbl_8061930C, a, b, d);
    } else {
        Unk800DB840_Slot* p = o + idx;
        fn_80097678(p, a, fn_800968C0(p, b, 1), c);
    }
}

int fn_800DB9A8(Unk800DB840_Slot* o, int a, int idx, int b)
{
    int r;
    if (o == 0) {
        r = ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007AB9C(a, b);
    } else {
        Unk800DB840_Slot* p = o + idx;
        int t = fn_800968C0(p, b, 1);
        int v = fn_80089AA0((char*)p + 0xC74, a, t);
        lbl_8068CC18.fn_8023C1E8(a, &v, idx, 1);
        lbl_8068CCA8.fn_8023C1E8(a, &v, idx, 1);
        ((Unk8023BE30*)((char*)p + 0x118))->fn_8023C1E8(a, &v, idx, 1);
        r = v;
    }
    return r;
}

void fn_800DBA74(Unk800DB840_Slot* o, int a, int idx, int b)
{
    if (o == 0) {
        fn_8007ABFC(lbl_8061930C, a, b);
    } else {
        Unk800DB840_Slot* p = o + idx;
        int r = fn_800968C0(p, b, 1);
        fn_80089E48((char*)p + 0xC74, a, r);
    }
}

/* near-miss: retail reloads lbl_8061930C for each method call (kept `lis` register); ours caches the pointer */
extern "C" int fn_800DBAE0(Unk800DB840_Slot* o, int a, int idx, int b)
{
    int* g = &lbl_8061930C;
    if (o != 0) {
        Unk800DB840_Slot* p = o + idx;
        int t = fn_800968C0(p, b, 1);
        int v = fn_8008CFD8((char*)p + 0xC9C, a, t);
        lbl_8068CC18.fn_8023C254(a, &v, idx, 1);
        lbl_8068CCA8.fn_8023C254(a, &v, idx, 1);
        ((Unk8023BE30*)((char*)p + 0x118))->fn_8023C254(a, &v, idx, 1);
        return v;
    }
    if (a == 0x1D)
        return ((Unk8007A4DC_Screen*)*g)->fn_8007A984(b);
    return ((Unk8007A4DC_Screen*)*g)->fn_8007AD34(a, b, ((Unk8007A4DC_Screen*)*g)->fn_8007A6A0(a, b));
}

void fn_800DBBE4(Unk800DB840_Slot* o, int a, int idx, int b)
{
    if (o == 0) {
        fn_8007A768(lbl_8061930C, a, b);
    } else {
        Unk800DB840_Slot* p = o + idx;
        int r = fn_800968C0(p, b, 1);
        fn_8008D7B8((char*)p + 0xC9C, a, r);
    }
}

void fn_800DBC50(Unk800DB840_Slot* o, int a, int idx, int b, int c)
{
    if (o == 0) {
        fn_8007A700(lbl_8061930C, a, b, c);
    } else {
        Unk800DB840_Slot* p = o + idx;
        int r = fn_800968C0(p, b, 1);
        fn_8008D738((char*)p + 0xC9C, a, r, c);
    }
}

void fn_800DBCC8(Unk800DB840_Slot* o, int a, int idx, int b, int c, int d, int e)
{
    if (o == 0) {
        fn_80075094(lbl_8061930C, a, b, e);
    } else {
        Unk800DB840_Slot* p = o + idx;
        fn_80097A9C(p, a, fn_800968C0(p, b, 1), c, d);
    }
}

void fn_800DBD4C(Unk800DB840_Slot* o, int a, int idx, int b, int c, int d, int e)
{
    if (o == 0) {
        fn_800739E0(lbl_8061930C, a, b, e);
    } else {
        Unk800DB840_Slot* p = o + idx;
        fn_80097EA4(p, a, fn_800968C0(p, b, 1), c, d);
    }
}

void fn_800DBDD0(Unk800DB840_Slot* o, int a, int idx, int b, int c, int d, int e)
{
    if (o == 0) {
        fn_80073C10(lbl_8061930C, a, b, e);
    } else {
        Unk800DB840_Slot* p = o + idx;
        fn_80097F68(p, a, fn_800968C0(p, b, 1), c, d);
    }
}

/* near-miss: retail reloads lbl_8061930C for each method call (kept `lis` register); ours caches the pointer */
int fn_800DBE54(Unk800DB840_Slot* o, int a, int idx, int b, int c)
{
    int* g = &lbl_8061930C;
    int r;
    if (o == 0) {
        r = ((Unk8007A4DC_Screen*)*g)->fn_8007ADD0(a, b, ((Unk8007A4DC_Screen*)*g)->fn_8007AA84(a, b, c));
    } else {
        Unk800DB840_Slot* p = o + idx;
        int t = fn_800968C0(p, b, 1);
        int v = fn_80099570(p, a, t, c);
        lbl_8068CC18.fn_8023C2C0(a, &v, idx, 1);
        lbl_8068CCA8.fn_8023C2C0(a, &v, idx, 1);
        ((Unk8023BE30*)((char*)p + 0x118))->fn_8023C2C0(a, &v, idx, 1);
        r = v;
    }
    return r;
}

void fn_800DBF44(Unk800DB840_Slot* o, int a, int idx, int b)
{
    if (o == 0) {
        fn_8007B054(lbl_8061930C, a, b);
    } else {
        Unk800DB840_Slot* p = o + idx;
        fn_80099278(p, a, fn_800968C0(p, b, 1));
    }
}

void fn_800DBFB0(Unk800DB840_Slot* o, int a, int idx, int b)
{
    if (o == 0) {
        fn_8007B0B4(lbl_8061930C, a, b);
    } else {
        Unk800DB840_Slot* p = o + idx;
        fn_800993C0(p, a, fn_800968C0(p, b, 1));
    }
}

void fn_800DC01C(Unk800DB840_Slot* o, int a, int idx, int b)
{
    if (o == 0) {
        fn_8007AEBC(lbl_8061930C, a, b);
    } else {
        Unk800DB840_Slot* p = o + idx;
        fn_8009908C(p, a, fn_800968C0(p, b, 1));
    }
}

void fn_800DC088(Unk800DB840_Slot* o, int a, int idx, int b)
{
    if (o == 0) {
        fn_8007AF1C(lbl_8061930C, a, b);
    } else {
        Unk800DB840_Slot* p = o + idx;
        fn_800991AC(p, a, fn_800968C0(p, b, 1));
    }
}
