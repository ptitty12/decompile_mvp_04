/*
 * Game code, .text 0x80264378-0x80268190 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_Q Q;
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;

extern "C++" {
struct Unk80266418_R {
    P* m0[4];
    P* m10[4];
    P* m20[4];
    P* m30[4];
    int m40;
};
typedef Unk80266418_R R4;
void fn_80265EA4(void* self);
void* fn_8035E604(void* p);
void fn_802663B8(void* p);
void fn_802663D8(R4* r);
void fn_80266434(R4* r, P* p, int a);
void fn_80266CC0(void* p);
void fn_801DC1CC(int a, int b, int c);
}

P* fn_80264844(I* self)
{
    return self->m434;
}

void fn_80265858(void* self)
{
    fn_80265EA4(self);
}

void fn_80265878()
{
}

void fn_80265EA4()
{
}

void* fn_80266358(void* self)
{
    fn_8035E604(self);
    return self;
}

void* fn_80266388(void* self)
{
    fn_802663B8(self);
    return self;
}

void fn_802663B8(void* self)
{
    fn_802663D8((R4*)self);
}

void fn_802663D8(R4* self)
{
    for (int i = 0; i < 4; i++) {
        self->m0[i] = 0;
        self->m30[i] = 0;
        self->m10[i] = 0;
        self->m20[i] = 0;
    }
    self->m40 = 6;
}

void fn_80266418(R4* self, int a)
{
    self->m40 = a;
}

void fn_80266420(R4* self, P* p)
{
    self->m0[p->m458 - 9] = p;
}

void fn_80266434(R4* self, P* p, int a)
{
    int idx = p->m458 - 9;
    if (a == 1)
        self->m10[idx] = p;
    else
        self->m30[idx] = p;
}

void fn_80266464(R4* self, P* p)
{
    self->m20[p->m458 - 9] = p;
}
