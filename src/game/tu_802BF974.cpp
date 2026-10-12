/*
 * Game code, .text 0x802BF974-0x802C3974 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802BF974.h"

void fn_80377408(void* p);
void fn_80377488(void* p);
void fn_803FFA60(void* dst, void* src, int n);
void fn_802B961C(const char* p, int a);
void fn_802C2254(Unk802C2188* o);
void fn_802C2408(Unk802C2188* o, Unk802C2188_Pair* a);
void fn_802C2A20(Unk802C2188* o, Unk802C2188_Pair* a, int b);
void fn_802C2BB8(Unk802C2188* o, Unk802C2188_Pair* a);
void fn_802C3974(Unk802C2188* o);
void fn_802C2FF4(void* im, int w, int h, int fmt, int hw, int z);
void* fn_803EBF2C(int h);
int fn_803EC03C(void* im);
void fn_802C36DC(Unk802C2188* o);
int fn_8040B6A0(const char* s);
int fn_80329C4C(const char** cur, int* len, void* out, int lo, int hi, int base);
int fn_80329B98(const char** cur, int* len, void* out, int n);
void* fn_803774A8(unsigned n, int heap);
struct Unk80084910_N;
void fn_800861A8(Unk80084910_N* self, char* buf);
int fn_802B96C4(const char* name, int a);
int fn_802B98AC(const char* name, int a);
int fn_802C2CCC(Unk802C2188* o, Unk802C2188_Pair* a);

/* near-miss (73 vs 73 insns, schedule only): retail sets r3 = &sp8 last in each call; the pointer-local recipe made it worse. */
int* fn_802C1288(const char* text)
{
    int len = fn_8040B6A0(text);
    int count;
    int row = 0;
    fn_80329C4C(&text, &len, &count, 0, 100000, 10);
    int* blk = (int*)fn_803774A8((count * 0x30) | 4, 0);
    *blk = count;
    if (row < *blk) {
        char* p = (char*)blk + 4;
        do {
            int off = 0;
            int j = 3;
            char* q3 = p + 0xC;
            char* q2 = p + 8;
            char* q1 = p + 4;
            do {
                fn_80329B98(&text, &len, p + off, 0x2C);
                off += 0x10;
                fn_80329B98(&text, &len, q1, 0x2C);
                q1 += 0x10;
                fn_80329B98(&text, &len, q2, 0xA);
                q2 += 0x10;
                fn_80329C4C(&text, &len, q3, 0, -1, 0xA);
                q3 += 0x10;
            } while (--j != 0);
            row++;
            p += 0x30;
        } while (row < *blk);
    }
    return blk;
}

void fn_802C212C(int* o, int v)
{
    *o = v;
}

void fn_802C2134(Unk802C2134* o, int c)
{
    if (o->m0 != 0) {
        fn_80377488(o->m0);
        o->m0 = 0;
    }
    if (c & 1) {
        fn_80377408(o);
    }
}

Unk802C2188* fn_802C2188(Unk802C2188* o)
{
    o->m4 = 0;
    o->m9C = 0x10;
    o->m90 = 0;
    o->m94 = 0;
    o->m98 = 0;
    o->mA4.Clear();
    o->mB0 = 0x7D4;
    o->mB4 = 0;
    o->mB8 = 0;
    for (int i = 0; i < 0x22; i++) {
        o->a8[i] = 0;
    }
    fn_802C2254(o);
    return o;
}

void fn_802C2214(Unk802C2188* o, int c)
{
    fn_802C2254(o);
    if (c & 1) {
        fn_80377408(o);
    }
}

void fn_802C2254(Unk802C2188* o)
{
    fn_802C36DC(o);
    for (int i = 0; i < 0x22; i++) {
        o->a8[i] = 0;
    }
    if (o->m4 != 0) {
        fn_802B961C(o->m4, o->m0);
        o->m4 = 0;
    }
    if (o->m94 != 0) {
        fn_80377408(o->m94);
        o->m94 = 0;
    }
    if (o->m90 != 0) {
        fn_80377408(o->m90);
        o->m90 = 0;
    }
    o->m9C = 0x10;
    o->mAC.Set(0x7C, 0x10, 0, 2);
}

int fn_802C2304(Unk802C2188* o, int i)
{
    return o->a8[i];
}

void fn_802C2314(Unk802C2188* o, Unk802C2188_Pair* a)
{
    if (o->m90 != 0 || o->m94 != 0 || o->m4 != 0) {
        fn_802C2254(o);
    }
    fn_802C2408(o, a);
    fn_802C2A20(o, a, 0);
    fn_802C2BB8(o, a);
    o->mA0 = a->x;
    o->m9C = a->y;
    o->mA4 = *a;
    fn_802C3974(o);
}

void fn_802C23BC(Unk802C2188* o, Unk802C2188_Pair* a)
{
    if (o->m4 != 0) {
        fn_802C2254(o);
    }
    fn_802C2A20(o, 0, (int)a);
}

void fn_802C2BB8(Unk802C2188* o, Unk802C2188_Pair* a)
{
    char buf[0x40];
    fn_800861A8((Unk80084910_N*)a, buf);
    int ok = fn_802B96C4(buf, 0);
    if (ok == 0) {
        o->m90 = 0;
        buf[4] = 0x61;
        ok = fn_802B96C4(buf, 0);
    }
    if (ok != 0) {
        o->m90 = (char*)fn_802B98AC(buf, 0x400);
    }
    if (o->m90 != 0 && fn_802C2CCC(o, a) != 0) {
        buf[0] = 0x61;
        o->m94 = (char*)fn_802B98AC(buf, 0x400);
        o->m98 = 1;
    } else {
        o->m94 = 0;
        o->m98 = 0;
    }
}

void fn_802C2C84(Unk802C2188* o)
{
    Unk802C2188_Pair p;
    p.x = 0;
    p.y = 0;
    p.x = o->mA0;
    p.y = o->m9C;
    fn_802C2CCC(o, &p);
}

/* near-miss (94 vs 95 insns): retail repeats the second (a == 0x4A) test with its own cmpwi cr0; ours CSEs the duplicated compare into cr7 (shared cmpwi cr7,r9,74).
   Separate ifs matched everything else; one big ||/&& expression is worse (81 slots). */
int fn_802C2CCC(Unk802C2188* o, Unk802C2188_Pair* p)
{
    int a = p->x;
    if (a == 0x10) {
        if (p->y == 2) {
            return 1;
        }
    }
    if (a == 0xC) {
        int b = p->y;
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return 1;
        }
        if (b == 2) {
            return 1;
        }
        if (b == 3) {
            return 1;
        }
    }
    if (a == 0xE) {
        int b = p->y;
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return 1;
        }
        if (b == 14) {
            return 1;
        }
        if (b == 2) {
            return 1;
        }
    }
    if (a == 0x0) {
        int b = p->y;
        if (b == 8) {
            return 1;
        }
        if (b == 9) {
            return 1;
        }
    }
    if (a == 0x8) {
        int b = p->y;
        if (b == 8) {
            return 1;
        }
        if (b == 9) {
            return 1;
        }
    }
    if (a == 0x28) {
        int b = p->y;
        if (b == 1) {
            return 1;
        }
    }
    if (a == 0x29) {
        int b = p->y;
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return 1;
        }
    }
    if (a == 0x4A) {
        int b = p->y;
        if (b == 1) {
            return 1;
        }
    }
    if (a == 0x3F) {
        int b = p->y;
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return 1;
        }
    }
    if (a == 0x4A) {
        int b = p->y;
        if (b == 1) {
            return 1;
        }
    }
    if (a == 0x5A) {
        int b = p->y;
        if (b == 1) {
            return 1;
        }
    }
    if (a == 0x78) {
        int b = p->y;
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return 1;
        }
    }
    if (a == 0x76) {
        int b = p->y;
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return 1;
        }
    }
    return 0;
}

int fn_802C2E48(unsigned char* p)
{
    int r = 2;
    if (*p == 0x1E) {
        r = 0;
    }
    return r;
}

/* near-miss (same length, register names only): retail extracts the second field into the register that held the old word
   (extrwi r0,r0,2,2), ours takes a fresh r10 for it; swap spellings (t = a; a = b; b = t, and five others) tried. */
void fn_802C2E60(Unk802C2E60* b)
{
    Unk802C2E60_Idx x = b->idx;
    unsigned t;
    t = x.f0;
    x.f0 = x.f3;
    x.f3 = t;
    t = x.f1;
    x.f1 = x.f2;
    x.f2 = t;
    t = x.f4;
    x.f4 = x.f7;
    x.f7 = t;
    t = x.f5;
    x.f5 = x.f6;
    x.f6 = t;
    t = x.f8;
    x.f8 = x.f11;
    x.f11 = t;
    t = x.f9;
    x.f9 = x.f10;
    x.f10 = t;
    t = x.f12;
    x.f12 = x.f15;
    x.f15 = t;
    t = x.f13;
    x.f13 = x.f14;
    x.f14 = t;
    b->idx = x;
}

void fn_802C2F08(Unk802C2E60* a)
{
    Unk802C2E60* p1 = a + 1;
    Unk802C2E60* p2 = a + 2;
    Unk802C2E60* p3 = a + 3;
    fn_802C2E60(a);
    fn_802C2E60(p1);
    fn_802C2E60(p2);
    fn_802C2E60(p3);
    Unk802C2E60 b0 = a[0];
    Unk802C2E60 b1 = a[1];
    Unk802C2E60 b2 = a[2];
    Unk802C2E60 b3 = a[3];
    a[0] = b1;
    a[1] = b0;
    a[2] = b3;
    a[3] = b2;
}

void fn_802C2F98(void* a, void* b)
{
    char tmp[0x20];
    fn_803FFA60(tmp, a, 0x20);
    fn_803FFA60(a, b, 0x20);
    fn_803FFA60(b, tmp, 0x20);
}

void fn_802C36DC(Unk802C2188* o)
{
    if (o->a8[28] != 0) {
        fn_80377408((void*)o->a8[28]);
        o->a8[28] = 0;
    }
    if (o->a8[29] != 0) {
        fn_80377408((void*)o->a8[29]);
        o->a8[29] = 0;
    }
    if (o->a8[30] != 0) {
        fn_80377408((void*)o->a8[30]);
        o->a8[30] = 0;
    }
    if (o->a8[32] != 0) {
        fn_80377408((void*)o->a8[32]);
        o->a8[32] = 0;
    }
    if (o->a8[31] != 0) {
        fn_80377408((void*)o->a8[31]);
        o->a8[31] = 0;
    }
    if (o->a8[33] != 0) {
        fn_80377408((void*)o->a8[33]);
        o->a8[33] = 0;
    }
}

void* fn_802C3794(int, int, int h)
{
    Unk802C3794_Img* im = (Unk802C3794_Img*)fn_803EBF2C(h);
    int w = im->w;
    int ht = im->h;
    fn_802C2FF4(im, w, ht, fn_803EC03C(im), w / 2, 0);
    return im;
}
