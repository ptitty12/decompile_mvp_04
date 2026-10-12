/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80029000-0x8002B430 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800239F4.h"
#include "game/clampiter.h"

extern const float lbl_805A62E0;
extern const float lbl_805A62E4;
extern const float lbl_805A6348;
extern const float lbl_805A6350;
extern const float lbl_805A6368;
extern const float lbl_805A6378;
extern const float lbl_805A6388;
extern "C" void fn_80021E30(Unk80023AC4_Obj* x, Unk8001F2C4_World* ctx, int n);
extern "C" void fn_80023F98(Unk80023AC4_Obj* x);
struct Unk80029DB8_Outer {
    char pad0[0x3BC];
    int* m3BC;
};
extern "C" void fn_8002F038(Unk80023AC4_Obj* x);

extern "C" void fn_80029000(Unk80023AC4_Obj* x)
{
    x->m56C = 1;
    x->m564 = fn_801C3E28(x->m80[0]->m700->m3A4);
}

extern "C" void fn_80029044(Unk80023AC4_Obj* x)
{
    x->m570 = 1;
}

extern "C" void fn_80029050(Unk80023AC4_Obj* x)
{
    fn_800220EC(x, x->m80[0]);
}

extern "C" void fn_80029074(Unk80023AC4_Obj* x)
{
    x->m530 = x->m530 + 1;
    int t = x->m514 == 0;
    int pl = x->m80[0]->m700->m3B0;
    if (fn_8022EC70(pl) != 0) {
        fn_80030794(x, &x->m3F8[0][t]);
        fn_80030794(x, &x->m3F8[7][t]);
        fn_80030794(x, &x->m3F8[5][t]);
        fn_80030794(x, &x->m3F8[9][t]);
    }
    if (fn_8022ED28(pl) != 0 && x->m294[x->m3D4].m0 == 0) {
        fn_80030778(x, &x->m3F8[1][t], 0x14);
        x->m3F8[2][t] = x->m3F8[2][t] + 1;
    }
    if (fn_8022EDC4(pl) != 0) {
        fn_80030778(x, &x->m3F8[3][t], 0x14);
        fn_80030794(x, &x->m3F8[8][t]);
        x->m3F8[4][t] = x->m3F8[4][t] + 1;
    }
    if (fn_8022EECC(pl) != 0) {
        x->m3F8[6][t] = x->m3F8[6][t] + 1;
        fn_80030794(x, &x->m3F8[1][t]);
        fn_80030794(x, &x->m3F8[5][t]);
        fn_80030794(x, &x->m3F8[9][t]);
    }
    if (fn_8022EF84(pl) != 0)
        fn_80030778(x, &x->m3F8[7][t], 0xF);
    if (fn_8022F024(pl) != 0) {
        fn_80030778(x, &x->m3F8[8][t], 0xF);
        fn_80030794(x, &x->m3F8[3][t]);
    }
    if (fn_8022EE5C(pl) != 0 && x->m294[x->m3D4].m0 == 0)
        fn_80030778(x, &x->m3F8[5][t], 0xF);
    if (fn_8022F0C4(pl) != 0)
        fn_80030778(x, &x->m3F8[9][t], 0xF);
    fn_800245D0(x);
    int cap = *lbl_8061B9C4;
    if (x->m530 > cap)
        x->m530 = cap;
}

/* near-miss: 101/101 insns, 2 slots swapped: retail issues `stw r0,0x12c(r31)` before the
 * `lwz r9,0x80(r31)` that loads the context for the duration conversion (store/load order). */
/* Frames to seconds through an inline: the constant-pool loads the inliner copies are not
 * unchanging, so they stay below the preceding field stores (m12C, the m190 counter) while
 * their lis halves are hoisted above them (retail's lis cluster). Written in place, the
 * lfd/lfs move above the stores too. */
inline float Unk80029000_Secs(Unk8001F2C4_World* w)
{
    return (float)w->m48 * 0.016666668f;
}

extern "C" void fn_800292EC(Unk80023AC4_Obj* x)
{
    int v = fn_80253F0C((char*)x->m510 + 0x588, 5, 2, 0);
    int d = x->mD0;
    if (d != 0) {
        if (x->m56C != 0) {
            int a = x->m514;
            int b = x->m634;
            int c = fn_8002A3DC(x);
            fn_800351F8(d, a, b, c, fn_8002A2D4(x));
        } else {
            int a = x->m514;
            int b = x->m634;
            int c = fn_8002A3DC(x);
            fn_80035090(d, a, b, c, fn_8002A2D4(x));
        }
    }
    int f = 0;
    x->m12C = x->m79C;
    x->m130.i = x->m56C;
    fn_8002A244(x, 8, Unk80029000_Secs(x->m80[0]));
    int pl = x->m80[0]->m700->m3B0;
    Unk80023F98_Vec2 sp = fn_80235BE0(pl);
    if (fn_8022EA7C(pl, &sp, lbl_805A62E4) == 0 && x->m570 != 0)
        f = 1;
    int m6 = x->m6C8;
    int s = x->m56C;
    fn_8003BB78(m6, s, v, f, fn_8018B654(x->m80[0]->m6CC));
}

extern "C" void fn_80029480(Unk80023AC4_Obj* x)
{
    int one = 1;
    x->m294[x->m3D4].mC = one;
    x->m530 = x->m530 + 1;
    int t = x->m514 == 0;
    char* b448 = (char*)x + 0x448;
    char* b4F8 = (char*)x + 0x4F8;
    int o4 = t * 4;
    int o12 = t * 0xC;
    *(int*)(b448 + o4) = *(int*)(b448 + o4) + 1;
    *(int*)(b4F8 + o12) = *(int*)(b4F8 + o12) + 1;
    int pl = x->m80[0]->m700->m3B0;
    if (fn_8022EC70(pl) != 0) {
        fn_80030794(x, &x->m3F8[0][t]);
        fn_80030794(x, &x->m3F8[7][t]);
        fn_80030794(x, &x->m3F8[5][t]);
        fn_80030794(x, &x->m3F8[9][t]);
    }
    if (fn_8022ED28(pl) != 0 && x->m294[x->m3D4].m0 == 0) {
        fn_80030778(x, &x->m3F8[1][t], 0x14);
        x->m3F8[2][t] = x->m3F8[2][t] + 1;
    }
    if (fn_8022EDC4(pl) != 0) {
        fn_80030778(x, &x->m3F8[3][t], 0x14);
        fn_80030794(x, &x->m3F8[8][t]);
        x->m3F8[4][t] = x->m3F8[4][t] + 1;
    }
    if (fn_8022EECC(pl) != 0) {
        x->m3F8[6][t] = x->m3F8[6][t] + 1;
        fn_80030794(x, &x->m3F8[1][t]);
        fn_80030794(x, &x->m3F8[5][t]);
        fn_80030794(x, &x->m3F8[9][t]);
    }
    if (fn_8022EF84(pl) != 0)
        fn_80030778(x, &x->m3F8[7][t], 0xF);
    if (fn_8022F024(pl) != 0) {
        fn_80030778(x, &x->m3F8[8][t], 0xF);
        fn_80030794(x, &x->m3F8[3][t]);
    }
    if (fn_8022EE5C(pl) != 0 && x->m294[x->m3D4].m0 == 0)
        fn_80030778(x, &x->m3F8[5][t], 0xF);
    if (fn_8022F0C4(pl) != 0)
        fn_80030778(x, &x->m3F8[9][t], 0xF);
    fn_800245D0(x);
    int cap = *lbl_8061B9C4;
    if (x->m530 > cap)
        x->m530 = cap;
    if (*lbl_8061B9C4 > x->m530) {
        Unk8001F2C4_World* w = x->m80[0];
        if (((Unk80029DB8_Outer*)w->m700)->m3BC[9] != 0)
            fn_8002A244(x, 0x60, (float)w->m48 * 0.016666668f);
        else if (x->m56C == 0)
            x->fn_800233B4(5, 0x5A, 0);
        else
            x->fn_800233B4(5, 0xA, 0);
    }
    fn_80023F98(x);
}


void fn_8003514C(int d, int a, int b, int c, int e);
void fn_80034FE4(int d, int a, int b, int c, int e);
void fn_8003B914(int m, int a, int b, int c, int d);
extern const float lbl_805A6304;

extern "C" void fn_800297D4(Unk80023AC4_Obj* x)
{
    int n = x->m530;
    if (*lbl_8061B9C4 > n) {
        int d = x->mD0;
        if (d != 0) {
            if (x->m160.m50 == 0) {
                if (x->m56C != 0) {
                    int a = x->m514;
                    int b = x->m52C;
                    fn_8003514C(d, a, b, n, fn_8002A2D4(x));
                } else {
                    int a = x->m514;
                    int b = x->m52C;
                    fn_80034FE4(d, a, b, n, fn_8002A2D4(x));
                }
            }
            fn_8002F038(x);
        }
        int f = 0;
        x->m12C = x->m56C;
        fn_8002A244(x, 7, Unk80029000_Secs(x->m80[0]));
        int pl = x->m80[0]->m700->m3B0;
        Unk80023F98_Vec2 sp = fn_80235BE0(pl);
        if (fn_8022EA7C(pl, &sp, lbl_805A6304) == 0 && x->m570 != 0)
            f = 1;
        int m6 = x->m6C8;
        int a = x->m530;
        int b = x->m56C;
        fn_8003B914(m6, a, b, f, fn_8018B654(x->m80[0]->m6CC));
    }
}

struct Unk8001CE80 {
    void fn_8001CCE0(Unk8001CE80* o);
};

extern "C" void fn_80029958(Unk80023AC4_Obj* x)
{
    int one = 1;
    int t = x->m514 == 0;
    char* b450 = (char*)x + 0x450;
    char* b4C8 = (char*)x + 0x4C8;
    int o4 = t * 4;
    int o12 = t * 0xC;
    *(int*)(b450 + o4) = *(int*)(b450 + o4) + 1;
    *(int*)(b4C8 + o12) = *(int*)(b4C8 + o12) + 1;
    x->m294[x->m3D4].m4 = one;
    if (x->m294[x->m3D4].m0 != 0)
        x->m3E0 = x->m3E0 + 1;
    fn_800245D0(x);
    Unk8001F2C4_World* w = x->m80[0];
    x->m52C = x->m52C + 1;
    int pl = w->m700->m3B0;
    ((Unk8001CE80*)&x->m160)->fn_8001CCE0((Unk8001CE80*)w->m6CC);
    if (fn_8022EC70(pl) != 0) {
        fn_80030778(x, &x->m3F8[0][t], 0x14);
        fn_80030794(x, &x->m3F8[7][t]);
        fn_80030794(x, &x->m3F8[5][t]);
        fn_80030794(x, &x->m3F8[9][t]);
    }
    if (fn_8022ED28(pl) != 0 && x->m294[x->m3D4].m0 == 0)
        fn_80030778(x, &x->m3F8[1][t], 0x14);
    if (fn_8022EDC4(pl) != 0) {
        fn_80030778(x, &x->m3F8[3][t], 0x14);
        fn_80030794(x, &x->m3F8[8][t]);
    }
    if (fn_8022EE5C(pl) != 0 && x->m294[x->m3D4].m0 == 0)
        fn_80030778(x, &x->m3F8[5][t], 0xF);
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x48);
    int v = m->m8;
    x->m6D4 = v;
    if (v == 1 && x->m714 == 0) {
        fn_8002A244(x, 0x3C, (float)x->m80[0]->m48 * 0.016666668f);
        x->m714 = v;
    }
    if (x->m52C > 4)
        x->m52C = 4;
    if (x->m52C != 4) {
        Unk8001F2C4_World* w2 = x->m80[0];
        if (((Unk80029DB8_Outer*)w2->m700)->m3BC[9] != 0)
            fn_8002A244(x, 0x60, (float)w2->m48 * 0.016666668f);
        else
            x->fn_800233B4(4, 0x3C, 0);
    }
    fn_80023F98(x);
    x->m6BC = 0;
}

void fn_80034F3C(int a, int b, int c, int d, int e);
void fn_8003BDE8(int a, int b, int c);
void fn_8003B6D0(int a, int b, int c, int d, int e);
struct Unk8022FE34_U {
    int fn_80234E44();
};

extern "C" void fn_80029C38(Unk80023AC4_Obj* x)
{
    if (x->m6DC == 0) {
        int r = fn_80253E7C((char*)x->m290 + 0x588, 0, 2, 0);
        int mode = x->m52C;
        if (mode != 4) {
            int d = x->mD0;
            if (d != 0) {
                if (x->m160.m50 == 0) {
                    int a = x->m514;
                    int b = x->m530;
                    fn_80034F3C(d, a, mode, b, fn_8002A2D4(x));
                }
                fn_8002F038(x);
            }
            int pl = x->m80[0]->m700->m3B0;
            if (x->m6D4 == 0 && ((Unk8022FE34_U*)pl)->fn_80234E44() == 0)
                fn_8002A244(x, 9, (float)x->m80[0]->m48 * 0.016666668f);
            if (fn_8022EC70(pl) != 0 && x->m52C == 3) {
                int m6 = x->m6C8;
                int s = x->m570;
                fn_8003BDE8(m6, s, fn_8018B654(x->m80[0]->m6CC));
                return;
            }
            int m6 = x->m6C8;
            int md = x->m52C;
            int s = x->m570;
            fn_8003B6D0(m6, r, md, s, fn_8018B654(x->m80[0]->m6CC));
        }
    }
}

int fn_80254EA4(void* p, int a);

extern "C" void fn_80029DB8(Unk80023AC4_Obj* x)
{
    int one = 1;
    x->m52C = x->m52C + 1;
    int z = x->m514 == 0;
    char* b460 = (char*)x + 0x460;
    char* b4E0 = (char*)x + 0x4E0;
    char* b190 = (char*)x + 0x190;
    int o4 = z * 4;
    int o12 = z * 0xC;
    *(int*)(b460 + o4) = *(int*)(b460 + o4) + 1;
    *(int*)(b4E0 + o12) = *(int*)(b4E0 + o12) + 1;
    *(int*)(b190 + o4) = *(int*)(b190 + o4) + 1;
    *(int*)((char*)x + 0x560) = one;
    for (int i = 0; i < x->m260; i++) {
        if (fn_80254EA4((char*)x->m1D0[i].m0 + 0x58C, 1) != -1)
            x->m1D0[i].m14 = -1;
    }
    if (x->m264 == 3) {
        char* b188 = (char*)x + 0x188;
        int o = x->m514 * 4;
        *(int*)(b188 + o) = *(int*)(b188 + o) + 1;
    }
    fn_800245D0(x);
    if (x->m6DC == 0) {
        x->m264 = fn_8002A4C0(x, x->m80[0]);
        x->m270[0].m0 = fn_8002A534(x, x->m80[0]);
        x->m270[1].m0 = fn_8002A53C(x, x->m80[0]);
        x->m270[2].m0 = fn_8002A544(x, x->m80[0]);
    }
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x3A);
    x->m6D4 = m->m10;
    x->m6DC = m->m14;
    if (x->m52C > 4)
        x->m52C = 4;
    if (x->m6DC == 1)
        fn_80021E30(x, x->m80[0], x->m1BC);
    Unk8001F2C4_World* w = x->m80[0];
    if (((Unk80029DB8_Outer*)w->m700)->m3BC[9] != 0)
        fn_8002A244(x, 0x60, (float)w->m48 * 0.016666668f);
    else
        x->fn_800233B4(0xB, 0x3C, 0);
    x->m6BC = 0;
    fn_80023F98(x);
}

void fn_80034EA8(int d, int a, unsigned b, int c);
void fn_80036064(int a, int b, int c, int d);
void fn_8003C270(int m, int r);
void fn_8003C188(int m);
void fn_8003BFE0(int m, int r, int s, int t);

extern "C" void fn_80029FE4(Unk80023AC4_Obj* x)
{
    int r = fn_80253E7C((char*)x->m290 + 0x588, 0, 2, 0);
    if (x->m6DC == 0) {
        int d = x->mD0;
        if (d != 0) {
            int a = x->m514;
            unsigned b = fn_8002A4C0(x, x->m80[0]);
            fn_80034EA8(d, a, b, fn_8002A2D4(x));
        }
        if (x->m6D4 == 1) {
            fn_8002A244(x, 0x2F, Unk80029000_Secs(x->m80[0]));
        } else {
            int t = x->m514 == 0;
            char* b190 = (char*)x + 0x190;
            int o4 = t * 4;
            *(int*)(b190 + o4) = *(int*)(b190 + o4) + 1;
            fn_8002A244(x, 0xF, Unk80029000_Secs(x->m80[0]));
        }
    } else {
        int d = x->mD0;
        if (d != 0) {
            int a = x->m514;
            fn_80036064(d, a, 1, fn_8002A2D4(x));
        }
        x->m12C = *(int*)((char*)fn_801A4B34(x->m80[0]) + 0x92C);
        fn_8002A244(x, 0x1A, Unk80029000_Secs(x->m80[0]));
    }
    if (x->m6DC == 1) {
        int k = fn_80253E7C((char*)x->m290 + 0x588, 3, 2, 0);
        fn_8003C270(x->m6C8, k);
    } else if (x->m6D4 == 1) {
        fn_8003C188(x->m6C8);
    } else {
        int m6 = x->m6C8;
        int s = x->m570;
        fn_8003BFE0(m6, r, s, fn_8018B654(x->m80[0]->m6CC));
    }
    x->fn_800233B4(0xC, 0xA, 0);
}

extern "C" void fn_8002A218(Unk80023AC4_Obj* x)
{
    if (x->m6DC == 0)
        fn_800289F8(x);
}

extern "C" void fn_8002A244(Unk80023AC4_Obj* x, int id, float f)
{
    fn_800488C4(fn_800475EC(), id, f, &x->m12C, &x->m160, x->m80[0]);
}

extern "C" void fn_8002A290(Unk80023AC4_Obj* x, int i, float f)
{
    if (i >= 0)
        fn_80039790(fn_80038EB4(), f);
}

extern "C" void fn_8002A2C4(Unk80023AC4_Obj* x, float f)
{
}

/* Row sums: the table pointer is re-read through x->mC8 each time (a local pointer variable makes the
 * compiler share the m14 load across the two loops; retail reloads it). */
extern "C" int fn_8002A2D4(Unk80023AC4_Obj* x)
{
    unsigned a = Unk8001F5CC_RowSum(&x->mC8->m14->e[0]);
    unsigned b = Unk8001F5CC_RowSum(&x->mC8->m14->e[1]);
    int r = 0;
    if (a >= b + 4)
        return 2;
    if (b >= a + 4)
        return 3;
    if (!((float)(x->mC8->m14->m1CC8 + 1) / (float)x->mC8->m10->m1C <= lbl_805A6350))
        r = 1;
    return r;
}

extern "C" int fn_8002A3DC(Unk80023AC4_Obj* x)
{
    int r = 9;
    if (x->m634 > 2) {
        if (fn_8006BE18(x->m80[0]->m6F8) == 1) {
            r = 8;
        } else if (x->m514 == 0) {
            int v = x->m160.m40;
            if (v > 2) {
                r = 3;
            } else if (v == 0) {
                r = fn_8002A4C0(x, x->m80[0]) > 1;
            } else if (v <= 2) {
                r = 2;
            }
        } else {
            int v = x->m160.m40;
            if (v == 0) {
                r = 5;
                if (fn_8002A4C0(x, x->m80[0]) <= 1)
                    r = 4;
            } else {
                r = 7;
                if (v <= 2)
                    r = 6;
            }
        }
    }
    return r;
}

extern "C" unsigned fn_8002A4C0(Unk80023AC4_Obj* x, Unk8001F2C4_World* y)
{
    unsigned n = 0;
    if (fn_8002A534(x, y) != 0)
        n = 1;
    if (fn_8002A53C(x, y) != 0)
        n = n + 1;
    if (fn_8002A544(x, y) != 0)
        n = n + 1;
    return n;
}

extern "C" int fn_8002A534(Unk80023AC4_Obj* x, Unk8001F2C4_World* y)
{
    return y->m684;
}

extern "C" int fn_8002A53C(Unk80023AC4_Obj* x, Unk8001F2C4_World* y)
{
    return y->m688;
}

extern "C" int fn_8002A544(Unk80023AC4_Obj* x, Unk8001F2C4_World* y)
{
    return y->m68C;
}

struct Unk8002A54C_Outer {
    char pad0[0x3B8];
    int m3B8;
};
extern "C" Unk801A4B34_Pos* fn_801DC570(int id);
extern "C" void fn_8002A68C(Unk80023AC4_Obj* x, Unk801A4B34_Pos* p, float a, float b);

extern "C" void fn_8002A54C(Unk80023AC4_Obj* x, float a, float b)
{
    Unk801A4B34_Pos* p = 0;
    int i;
    Unk801A4B34_Pos* q = fn_801DC570(((Unk8002A54C_Outer*)x->m80[0]->m700)->m3B8);
    x->m5C0 = q;
    x->m718 = 0;
    x->m6AC = 0;
    if (q != 0) {
        fn_8002A68C(x, q, a, b);
    }
    if (x->m6AC == 0) {
        int t = x->m5A8;
        if (t == 2 || (t == 1 && !(a <= x->m8C->mA4))) {
            for (i = 6; i <= 8; i++) {
                p = fn_801A497C(x->m80[0], 4, i);
                fn_8002A68C(x, p, a, b);
                if (x->m6AC == 1) {
                    break;
                }
            }
        }
        if (x->m6AC == 0) {
            for (i = 0; i <= 5; i++) {
                p = fn_801A497C(x->m80[0], 4, i);
                fn_8002A68C(x, p, a, b);
                if (x->m6AC == 1) {
                    break;
                }
            }
        }
    }
}

extern "C" void fn_8002A920(Unk80023AC4_Obj* x)
{
    if (x->mD4 == 1) {
        if (x->mB4 != 0) {
            for (int i = 0; i < 10; i++) {
                if (x->e[i].m4 != 0) {
                    x->e[i].m4 = x->e[i].m4 - 1;
                    if (x->e[i].m4 == 0) {
                        for (int j = 0; j <= 0x31; j++) {
                            if (lbl_8061690C[j].key == x->e[i].m0) {
                                (x->*lbl_8061690C[j].fn)();
                                break;
                            }
                        }
                        x->mB4 = x->mB4 - 1;
                    }
                }
            }
        }
        fn_800307B4(x);
        ((Unk8002A920_Vt*)x->m6C8)->fn_vslot11();
    }
}

void fn_80039A3C(int a, int b, int c);

extern "C" void fn_8002AA5C(Unk80023AC4_Obj* x)
{
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x5E);
    int id = m->m8;
    int r6 = m->mC;
    int j = 0;
    Unk8006A138_It<3> it(j);
    for (; j <= 1; j = it.Next()) {
        if (x->m270[j].m0 == id) {
            r6 = j + 1;
            break;
        }
    }
    for (int i = 0; i < x->m260; i++) {
        if (x->m1D0[i].m0 == id) {
            x->m1D0[i].m14 = r6;
            x->m1D0[i].m20 = 0;
        }
    }
    x->m160.m50 = x->m160.m50 + 1;
    x->m6BC = 0;
    for (int k = 0; k <= 2; k++) {
        if (x->m77C[k] == 0) {
            x->m77C[k] = id;
            x->m788[k] = r6;
            break;
        }
    }
    x->fn_800233B4(0x1A, 0x1E, 0);
    fn_80039A3C(0xA, 1, 0x122);
}

extern "C" void fn_8002ABC4(Unk80023AC4_Obj* x)
{
    x->m12C = 0;
    x->m130.i = -1;
    for (int i = 0; i <= 2; i++) {
        if (x->m77C[i] != 0) {
            x->m12C = x->m77C[i];
            x->m130.i = x->m788[i];
            x->m77C[i] = 0;
            break;
        }
    }
    if (x->m12C != 0)
        fn_8002A244(x, 0x24, (float)x->m80[0]->m48 * lbl_805A6368);
    fn_8003CC98(x->m6C8);
}

extern "C" void fn_8002ACB8(Unk80023AC4_Obj* x, int unused, int v)
{
    int d = x->mD0;
    if (d != 0) {
        int c = x->m514;
        fn_80035A58(d, c, 1, fn_8002A2D4(x));
    }
    x->m12C = v;
    fn_8002A244(x, 0x34, (float)x->m80[0]->m48 * lbl_805A6378);
}

extern "C" void fn_8002AD50(Unk80023AC4_Obj* x)
{
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x5F);
    x->m774 = fn_801A4910(x->m80[0], x->m514, m->m10);
    x->m778 = m->m8;
    x->m6BC = 0;
    if (!(x->m774->m58C.m4 & 0x20000000))
        x->m160.m54 = x->m160.m54 + 1;
    else
        x->m6F5 = x->m6F5 + 1;
    if (x->m160.m54 + x->m6F4 + x->m6F5 == x->m160.m50) {
        int d = x->mD0;
        if (d != 0) {
            int c = x->m514;
            fn_80035A58(d, c, 1, fn_8002A2D4(x));
        }
        x->fn_800233B4(0x20, 1, 0);
    }
}

extern "C" void fn_8002AE4C(Unk80023AC4_Obj* x)
{
    if (x->m160.m54 + x->m6F4 + x->m6F5 == x->m160.m50) {
        x->m12C = (int)x->m774;
        x->m130.i = x->m778;
        fn_8002A244(x, 0x25, (float)x->m80[0]->m48 * lbl_805A6388);
    }
}
