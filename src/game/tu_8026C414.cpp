/*
 * Game code, .text 0x8026C414-0x8026DDE8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8026C414.h"

typedef Unk8026C414_O O;
typedef Unk8026C414_X X;
typedef Unk8026C414_W W;

typedef Unk8026C414_M M;
typedef Unk8026C414_E E;
typedef Unk8026C414_V3 V3;

extern "C++" {
int fn_8026D55C(O* self, X* ctx);
void fn_8026AA0C(int a, int b);
void fn_8031925C(void* x);
/* near-miss: retail emits the flag read-modify-write before loading the 0.0f constant; ours hoists the lfs and orders the stores differently */
void fn_8026CB30(M* self, int i);
void fn_8026CCF8(M* self, int i, int* a, int* b);
float fn_8037B1F0(X* x);
float fn_80382BB8(W* w);
float fn_80382BD8(W* w, int a);
}

inline int Ge(int s, int lo)
{
    return s >= lo;
}

void fn_8026C630()
{
    fn_8026AA0C(1, 0xFFFF);
}

void fn_8026CA58() {}

void fn_8026CA5C(M* self)
{
    if (self->m240 == 0)
        fn_8031925C(self->m244);
}

/* near-miss: retail emits the flag read-modify-write before loading the 0.0f constant; ours hoists the lfs and orders the stores differently */
void fn_8026CB30(M* self, int i)
{
    E* e = (E*)((char*)(i * 0x20 + (int)self) + 0xC4);
    e->f0 = 1;
    e->f1 = 0;
    e->f4 = 0;
    e->m10 = 0.0f;
    e->m14 = -1;
    e->m18 = 0;
    e->m1C = 0;
}

extern V3 lbl_806055AC;

V3 fn_8026CB70(M* self, int i)
{
    return self->e[i].pos;
}

void fn_8026CB9C(M* self, int i)
{
    E* d = &self->e[i];
    E* s = &self->e[1];
    *d = *s;
}

void fn_8026CDE4(M* self, int i)
{
    int a = 0;
    int b = 0;
    fn_8026CCF8(self, i, &a, &b);
}

void fn_8026CE18(M* self, int i)
{
    fn_8026CB30(self, i);
    ((Unk8026C414_VT98*)self)->s9(1);
}

float fn_8026D504(O* self, X* ctx)
{
    float r = 0.0f;
    if (ctx != 0 && (ctx->mBC & 1))
        r = fn_8037B1F0(ctx);
    else
        r = fn_80382BB8(self->m618);
    return r;
}

int fn_8026D55C(O* self, X* ctx)
{
    return ctx ? ctx->mCC : self->m618->m830;
}

int fn_8026D578(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 4;
}

int fn_8026D5A4(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 5;
}

int fn_8026D5D0(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 6;
}

int fn_8026D5FC(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 7;
}

int fn_8026D628(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 8;
}

int fn_8026D654(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 10;
}

int fn_8026D680(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 11;
}

int fn_8026D6AC(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 12;
}

int fn_8026D6D8(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 13;
}

int fn_8026D704(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 14;
}

int fn_8026D730(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 15;
}

int fn_8026D75C(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 16;
}

int fn_8026D788(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 17;
}

int fn_8026D7B4(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 20;
}

int fn_8026D7E0(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 24;
}

int fn_8026D80C(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 27;
}

int fn_8026D838(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 28;
}

int fn_8026D864(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 29;
}

int fn_8026D890(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 30;
}

int fn_8026D8BC(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 32;
}

int fn_8026D8E8(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 33;
}

int fn_8026D914(O* self, X* ctx)
{
    return fn_8026D55C(self, ctx) == 34;
}

int fn_8026D940(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s <= 27)
        r = Ge(s, 20);
    return r;
}

int fn_8026D988(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s <= 15)
        r = Ge(s, 13);
    return r;
}

int fn_8026D9D0(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s <= 29)
        r = Ge(s, 28);
    return r;
}

int fn_8026DA18(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s <= 31)
        r = Ge(s, 30);
    return r;
}

int fn_8026DA60(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s == 22 || s == 25)
        r = 1;
    return r;
}

int fn_8026DAA4(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s == 23 || s == 26)
        r = 1;
    return r;
}

int fn_8026DAE8(O* self, X* ctx)
{
    switch (fn_8026D55C(self, ctx)) {
    case 3:
    case 4:
    case 7:
    case 16:
        return 1;
    }
    return 0;
}

int fn_8026DB3C(O* self, X* ctx)
{
    int s = fn_8026D55C(self, ctx);
    float f = 0.0f;
    if (ctx == 0)
        f = fn_80382BD8(self->m618, 0);
    switch (s) {
    case 3:
    case 4:
    case 7:
    case 16:
    case 20:
        return 1;
    case 12:
        return f <= 0.1f;
    case 13:
    case 14:
    case 15:
        return f > 0.8f;
    }
    return 0;
}

int fn_8026DC18(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s == 9 || s == 11)
        r = 1;
    return r;
}

int fn_8026DC5C(O* self, X* ctx)
{
    int s = fn_8026D55C(self, ctx);
    int r = 0;
    float f = 0.0f;
    if (ctx == 0)
        f = fn_80382BD8(self->m618, 0);
    switch (s) {
    case 9:
    case 10:
    case 11:
    case 24:
    case 25:
    case 26:
        r = 1;
        break;
    case 12:
        r = f > 0.1f;
        break;
    case 13:
    case 14:
    case 15:
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

int fn_8026DD18(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s <= 19)
        r = Ge(s, 16);
    return r;
}

int fn_8026DD60(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s == 14 || s == 19)
        r = 1;
    return r;
}

int fn_8026DDA4(O* self, X* ctx)
{
    int r = 0;
    int s = fn_8026D55C(self, ctx);
    if (s == 22 || s == 25)
        r = 1;
    return r;
}
