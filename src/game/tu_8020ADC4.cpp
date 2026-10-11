/*
 * Game code, .text 0x8020ADC4-0x8020EE9C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801EE438.h"

typedef Unk801EE438_Scr Scr;

struct Unk8020C5FC_Tbl {
    int m[4];
};
extern Unk8020C5FC_Tbl lbl_805D5950;
extern Unk8020C5FC_Tbl lbl_805D5960;

struct Unk8020DF6C_Buf {
    int* m0;
    int m4;
};

extern "C" {
void fn_80377488(void* p);
int fn_8020B944(Scr* p);
int fn_8020C4B4(Scr* p);
int fn_8020C5FC(Scr* p);
int fn_8020C5F4(Scr* p);
}

extern "C" int fn_8020B898(Scr* p)
{
    int r = 0;
    switch (p->m0->m34) {
    case 0:
        break;
    case 1:
        p->m0->mCA4 = fn_8020B944(p);
        break;
    case 3:
        r = 1;
        p->m0->mCA4 = fn_8020C5FC(p);
        break;
    case 2:
        r = 1;
        p->m0->mCA4 = fn_8020C4B4(p);
        break;
    case 4:
        r = 1;
        p->m0->mCA4 = fn_8020C5F4(p);
        break;
    }
    return r;
}

extern "C" int fn_8020C5F4(Scr* p)
{
    return 0x42;
}

/* near-miss (17 slots): retail computes idx*4 and loads the first table word inside each branch and
 * cross-jumps only the rest of the 16-byte copy; if/else struct assignment gets the right length
 * but schedules the copy differently. */
extern "C" int fn_8020C5FC(Scr* p)
{
    Unk801EE438_G* g = p->m0;
    int idx = g->mC88;
    if (idx == -1)
        idx = 1;
    Unk8020C5FC_Tbl t;
    if (g->mC8C == 1)
        t = lbl_805D5950;
    else
        t = lbl_805D5960;
    return t.m[idx];
}

/* near-miss (6 slots): saturating-decrement loop and volatile counter match; retail puts the final
 * player-slot index/result in r11/r3 where ours uses r0, and schedules cmpwi before the addi. */
extern "C" int fn_8020C90C(Scr* p)
{
    volatile int sp8;
    int t = 3;
    int r = -1;
    int h = p->m0->m0->m700->m3B4;
    int e;
    while (sp8 = t, e = sp8, e > 0) {
        if (fn_80259C50(h, e) != 0) {
            r = sp8;
            break;
        }
        int c = sp8;
        t = c - 1;
        if (c <= -1)
            t = c;
    }
    int s = sp8;
    if (s <= 2) {
        Unk801EE438_Owner* o = p->m0->m0;
        unsigned k = fn_8014E2B4(s);
        Unk801EE438_Player* pl;
        if (k <= 12)
            pl = o->m65C[k];
        else
            pl = 0;
        if (pl != 0)
            r = 3;
    }
    return r;
}

/* near-miss: body matches except for register choice: retail copies p to r10 up front and loads the
 * three m65C[10..12] tests into r3; ours keeps p in r3 and loads into r0 (same shape as fn_8020C90C). */
extern "C" int fn_8020C9CC(Scr* p, int* out)
{
    volatile int sp8;
    int e;
    if (out != 0) {
        sp8 = 0;
        e = 0;
        do {
            out[e] = 0;
            int c = sp8;
            int t;
            if (c > 3)
                t = c;
            else
                t = c + 1;
            sp8 = t;
            e = t;
        } while (e <= 2);
    }
    int r = 0;
    if (p->m0->m0->m65C[10] != 0) {
        r = 1;
        if (out != 0)
            out[0] = 1;
    }
    if (p->m0->m0->m65C[11] != 0) {
        r = 2;
        if (out != 0)
            out[1] = 1;
    }
    if (p->m0->m0->m65C[12] != 0) {
        r = 3;
        if (out != 0)
            out[2] = 1;
    }
    return r;
}

extern "C" int fn_8020CCFC(int unused, int k)
{
    return (unsigned)(k - 6) <= 2;
}

extern "C" int fn_8020CD10(int unused, int k)
{
    return fn_8020CCFC(unused, k) == 0;
}

extern "C" int fn_8020CD38(int unused, int a, int b)
{
    int r = 0;
    switch (a) {
    case 0:
        if (b == 2)
            r = 1;
        break;
    case 1:
        if (b == 3 || b == 5)
            r = 1;
        break;
    case 2:
        if (b == 4)
            r = 1;
        break;
    case 3:
        if (b == 1)
            r = 1;
        break;
    }
    return r;
}

extern "C" void fn_8020DF6C(Unk8020DF6C_Buf* b)
{
    if (b->m0 != 0) {
        delete[] b->m0;
        b->m0 = 0;
        b->m4 = 0;
    }
}

extern "C" void fn_8020DFB0(int x, int a, int b, int c)
{
    fn_80248488(a, b, b, c, 9, 0, 0);
}

extern "C" void fn_8020DFE4(Scr* p, int a1, int a2, int a3, Unk801EE438_Vec v, int a5, int a6, int a7, int a8)
{
    fn_8020E074(p, a1, a2, v, fn_80216590(p, a2, v, a3, a5, a6), a7, a8);
}

extern "C" void fn_8020E20C(Scr* p, int a1, int a2, int a3, Unk801EE438_Vec v, int a5, int a6, int a7, int a8)
{
    fn_8020E2A0(p, a1, a2, v, fn_80216590(p, a2, v, a3, a5, a6), a7, a8, 0);
}

extern "C" void fn_8020E6A0(Scr* p, int a1, int a2, int a3, Unk801EE438_Vec v, int a5, int a6)
{
    fn_8020E71C(p, a1, a2, v, fn_80216590(p, a2, v, a3, a5, a6));
}

/* near-miss (2 slots): the two argument moves for the fn_80216590 call (mr r8,r9 / mr r5,r11) are
 * ordered the other way round than retail. */
extern "C" void fn_8020E82C(Scr* p, int a1, int a2, int a3, Unk801EE438_Vec v, int a5, int a6, int a7)
{
    fn_8020E8B4(p, a1, a2, v, fn_80216590(p, a2, v, a3, a5, a6), a7);
}
