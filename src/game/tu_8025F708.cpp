/*
 * Game code, .text 0x8025F708-0x80264378 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_Q Q;
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;

extern "C++" {
int fn_8026BE3C(I* self, P* p);
void fn_8025F89C(I* self, P* p);
}

inline int EntLevel(Unk8024EF40_Ent* e)
{
    return *((unsigned char*)e + 0x1CC9);
}

/* near-miss (parked, 28 vs 28 insns, 8 slots): only the callee-saved pair is swapped (retail self=r31, p=r30; ours the reverse);
   no passthru hit, extra uses of self not found */
int fn_8025F7F0(I* self, P* p)
{
    int r = 0;
    if (p != 0) {
        if (fn_8026BE3C(self, p) == 0)
            fn_8025F89C(self, p);
        r = fn_8026BE3C(self, p) != 0;
    }
    return r;
}

void fn_8025F860(I* self, P* p, int a)
{
    self->m4C4[p->m458 - 9] = a;
}

void fn_8025F878(I* self)
{
    for (int i = 0; i < 4; i++)
        self->m4C4[i] = 0;
}

int fn_80261AFC(I* self, P* p)
{
    A* a = &p->m58C;
    if (a->b2 != 0 || a->m44 == 2)
        return 1;
    Q* q = self->m1EC;
    int lvl = EntLevel(q->m6F8->m14);
    if (lvl > 2)
        return 1;
    if (a->m44 == 1) {
        P* c = q->m6CC;
        if (c->m388 == 3 && c->m38C == 1 && lvl <= 1)
            return 0;
        return 1;
    }
    return 0;
}
