/*
 * Game code, .text 0x801BAC74-0x801BDD60 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801BAC74.h"

typedef Unk801B7FB0_P P;
typedef Unk801B7FB0_B B;
typedef Unk801B7FB0_Ai A;

extern "C" {
P* fn_801A4C74(P* ctx, int i);
int fn_801BA130(B* b, unsigned i, int* p, float f);
void fn_801BDDC8(B* b, void* p);
void fn_801B7FD4(P* p);
void fn_801B9EC0(B* b);
int fn_801BA958(B* b);
int fn_801BA974(B* b);
int fn_801BA9A4(B* b);
int fn_801BA9B8(B* b);
void fn_801BE0A4(B* b);
void fn_801B6AC4(P* p);
void fn_801B6CD0(P* p);
void fn_801B7394(P* p);
void fn_801B9004(P* p);
void fn_801BCFA8(A* a);
void fn_801BB0C8(A* a);
}

extern "C" int fn_801BAC74(A* a, unsigned i, int* p, float f) { return fn_801BA130(a->m8, i, p, f); }

extern "C" void fn_801BAE90(A* a)
{
    void* v = a->m14->m65C[9];
    if (v) {
        for (int i = 0; i <= 3; i++) {
            P* p = fn_801A4C74(a->m14, i);
            if (p)
                p->v31(v);
        }
    }
}

extern "C" void fn_801BAF08(A* a)
{
    if (a->m14->m6F4 == 0) {
        for (int i = 0; i <= 3; i++) {
            P* p = fn_801A4C74(a->m14, i);
            if (p)
                p->v33();
        }
    }
    a->m14->m6F8->m14->t[0].m110 = 0;
    Unk801B7FB0_Team* e = &a->m14->m6F8->m14->t[1];
    e->m110 = 0;
}

extern "C" void fn_801BB0C8(A* a)
{
    a->m14->m6F8->m14->t[0].m10C = 0;
    Unk801B7FB0_Team* e = &a->m14->m6F8->m14->t[1];
    e->m10C = 0;
}

extern "C" void fn_801BB0F4(A* a)
{
    fn_801BB0C8(a);
    fn_801BDDC8(a->m8, a->m14->m6CC);
    a->m8->m28 = 4;
}

extern "C" void fn_801BB13C(A* a)
{
    fn_801BB0C8(a);
    B* b = a->m8;
    b->mC = 1;
    b->m2C = 6;
    P* p = fn_801A4C74(a->m14, 0);
    if (p)
        fn_801B7FD4(p);
}

extern "C" void fn_801BB194(A* a) { a->m8->m18 = 1; }
extern "C" void fn_801BB1A4(A* a) { fn_801BDDC8(a->m8, a->m14->m6CC); }
extern "C" void fn_801BB1D0(A* a) { a->m8->m1C = 1; }

extern "C" void fn_801BB4D8(A* a, int x)
{
    B* b = a->m8;
    b->mC = 2;
    b->m2C = x;
}
extern "C" int fn_801BB4EC(A* a) { return a->m8->m0 == -1 ? 0 : 1; }
extern "C" int fn_801BB508(A* a) { return a->m8->m0 == 1; }
extern "C" void fn_801BB520(A* a) { fn_801B9EC0(a->m8); }
extern "C" void fn_801BB65C(A* a) { a->m1C = 1; }
extern "C" void fn_801BB988(A* a) { a->m24 = 0; }

extern "C" void fn_801BB994(A* a)
{
    fn_801BE0A4(a->m8);
    a->m8->m28 = 0;
    int i = 0;
    do {
        P* p = fn_801A4C74(a->m14, i++);
        if (p)
            p->v34();
    } while (i <= 3);
}

extern "C" void fn_801BBA0C(A* a)
{
    if (a->m14->m6F4 == 0) {
        for (int i = 0; i <= 3; i++) {
            P* p = fn_801A4C74(a->m14, i);
            if (p)
                fn_801B6AC4(p);
        }
    }
}
extern "C" void fn_801BBA6C(A* a)
{
    if (a->m14->m6F4 == 0) {
        for (int i = 0; i <= 3; i++) {
            if (i != 0) {
                P* p = fn_801A4C74(a->m14, i);
                if (p)
                    fn_801B6CD0(p);
            }
        }
    }
}
extern "C" void fn_801BBAD4(A* a)
{
    if (a->m14->m6F4 == 0) {
        for (int i = 0; i <= 3; i++) {
            P* p = fn_801A4C74(a->m14, i);
            if (p)
                fn_801B7394(p);
        }
    }
}
extern "C" void fn_801BBB34(A* a)
{
    P* c = a->m14;
    if (c->m6F4 == 0) {
        P* p = fn_801A4C74(c, 0);
        if (p)
            fn_801B9004(p);
    }
}

extern "C" int fn_801BBC0C(A* a) { return fn_801BA958(a->m8); }
extern "C" int fn_801BBC30(A* a) { return fn_801BA974(a->m8); }
extern "C" int fn_801BBC54(A* a) { return fn_801BA9A4(a->m8); }
extern "C" int fn_801BBC78(A* a) { return fn_801BA9B8(a->m8); }

extern "C" int fn_801BBED4(A* a)
{
    int r = 0;
    if (a->m1C != 0 || a->m20 != 0)
        r = 1;
    return r;
}
extern "C" int fn_801BBEFC(A* a) { return a->m1C; }
extern "C" int fn_801BBF04(A* a) { return a->m20; }
extern "C" int fn_801BBF0C(A* a) { return a->m8->m18; }
extern "C" int fn_801BBF18(A* a) { return a->m8->m1C; }
extern "C" int fn_801BBF24(A* a) { return a->m8->m2C; }
extern "C" void fn_801BCF88(A* a) { fn_801BCFA8(a); }
