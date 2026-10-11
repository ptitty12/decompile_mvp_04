/*
 * Game code, .text 0x80355A6C-0x803560F8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"

int fn_80355A6C(Cont* self) { return self->m14.m4; }

/* near-miss: retail re-reads the int-list count (v->m4) at the loop bottom; ours hoists it into a register
   (inline Count(), while form and v->m0[i] data reads tried; the last gives 14 slots, this form 19) */
int fn_80355A74(Cont* self, int idx)
{
    IntVec* v = &self->m14;
    Rec1C* r = &self->m0[idx];
    for (unsigned i = 0; i < v->m4; i++) {
        if (r->m0 == self->m14.m0[i])
            return 0;
    }
    return 1;
}

int fn_80355AD0(Cont* self)
{
    int n = 0;
    for (unsigned i = 0; i < self->m4; ) {
        if (self->s19(i++) == 1)
            n++;
    }
    return n;
}

Rec1C* fn_80355B48(Cont* self, unsigned k)
{
    unsigned n = 0;
    for (unsigned i = 0; i < self->m4; i++) {
        if (self->s19(i) == 1) {
            if (n++ >= k)
                return &self->m0[i];
        }
    }
    return self->m0;
}

inline void SetRec(Cont0* c, unsigned i, Rec1C v)
{
    if (i >= c->m4)
        c->m4 = i + 1;
    c->m0[i] = v;
}

void fn_80355BE4(Cont* self, unsigned k, Rec1C* rec)
{
    unsigned n = 0;
    for (unsigned i = 0; i < self->m4; i++) {
        if (self->s19(i) == 1) {
            if (n++ >= k) {
                SetRec(self, i, *rec);
                return;
            }
        }
    }
}

void* fn_80355D08(void* self)
{
    fn_8035709C__FPv(self);
    PUT(0, lbl_8065D240);
    return self;
}

void* fn_80355D44(void* self)
{
    fn_8035709C__FPv(self);
    PUT(0, lbl_8065D1D0);
    return self;
}

void* fn_80355D80(void* self)
{
    fn_8035709C__FPv(self);
    PUT(0, lbl_8065D2B0);
    return self;
}

void* fn_80355DBC(void* self)
{
    fn_80355D80__FPv(self);
    PUT(0, lbl_8065D198);
    return self;
}

void* fn_80355DF8(void* self)
{
    fn_80355D80__FPv(self);
    PUT(0, lbl_8065D160);
    return self;
}

void* fn_80355E34(void* self)
{
    fn_8035709C__FPv(self);
    PUT(0, lbl_8065D278);
    return self;
}

void* fn_80355E70(void* self)
{
    fn_80355E34__FPv(self);
    PUT(0, lbl_8065D128);
    return self;
}

void* fn_80355EAC(void* self)
{
    fn_80355E34__FPv(self);
    PUT(0, lbl_8065D0F0);
    return self;
}

void* fn_80355EE8(void* self)
{
    fn_80355D80__FPv(self);
    PUT(0, lbl_8065D0B8);
    return self;
}

void* fn_80355F24(void* self)
{
    fn_80355D80__FPv(self);
    PUT(0, lbl_8065D080);
    return self;
}

void* fn_80355F60(void* self)
{
    fn_8035709C__FPv(self);
    PUT(0, lbl_8065D048);
    return self;
}

void* fn_80355F9C(void* self)
{
    fn_8035709C__FPv(self);
    PUT(0, lbl_8065D010);
    return self;
}

void fn_80355FD8(void* a, int b) { fn_8035686C(a, b); }

void fn_80355FF8(void* a, int b) { fn_8035686C(a, b); }

void fn_80356018(void* a, int b) { fn_8035686C(a, b); }

void fn_80356038(void* a, int b) { fn_80356C04(a, b); }

void fn_80356058(void* a, int b) { fn_80356C04(a, b); }

void fn_80356078(void* a, int b) { fn_80356C04(a, b); }

void fn_80356098(void* a, int b) { fn_80356C04(a, b); }

void fn_803560B8(void* a, int b) { fn_80356C04(a, b); }

void fn_803560D8(void* a, int b) { fn_80356C04(a, b); }
