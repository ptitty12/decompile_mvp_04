/*
 * Game code, .text 0x8035726C-0x80357A70 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"

void fn_8035726C(Act* self, Scr700* scr, int c)
{
    switch (self->m4) {
    case 0: {
        void* h = scr->m700;
        char* name = (char*)fn_8035799C(self);
        fn_8017D640((Unk8017A930_T*)h, c, name, fn_801C1638(scr, 0), 0);
        break;
    }
    case 1: {
        void* h = scr->m700;
        fn_8017DF2C(h, fn_8035799C(self));
        break;
    }
    }
    fn_800FEB30(lbl_805BE138, c);
}

int fn_80357308(Act* self) { return fn_8035799C(self)->m704; }

void fn_8035732C(Act* self, VT3C* scr)
{
    char buf[0xC8];
    char name[0xC8];
    fn_800DE274(name, fn_8035799C(self), 1);
    int id = 0x263a;
    if (self->m4 == 0)
        id = 0x2639;
    fn_80403DE4(buf, fn_80090880(lbl_8061977C, id), name);
    scr->s28(buf);
}

int fn_803573C0(Act* self, Scr700* scr, int c)
{
    if (fn_8035799C(self) == 0)
        return 0;
    if (self->m4 == 0) {
        int t = 0;
        if (scr->m6F8->m14->m1CD0 != 0)
            t = 1;
        if (t == c)
            return 0;
    }
    return 1;
}

int fn_8035743C(Act* self, void* a, int b)
{
    if (self->m4 != 0)
        return 1;
    return fn_8011BD3C(a, b);
}

void fn_80357474(void* a, int b, int c) { fn_800FEB30(lbl_805BEE80, c); }

int fn_803574A0(void* a, VT3C* s) { return s->s29(0x501); }

int fn_803574DC(void* a, Scr700* scr, int c) { return fn_8017DD64((Unk8017DD64_T*)scr->m700, c) <= 1; }

void fn_80357514(void* a, int b, int c) { fn_800FEB30(lbl_805BEE90, c); }

int fn_80357540(void* a, VT3C* s) { return s->s29(0x2628); }

void fn_8035757C(void* a, void* b, int c) { fn_8011BD3C(b, c); }

void fn_803575A4(void* a, Scr700* scr, int c)
{
    fn_8017D378(scr->m700, 0);
    fn_800FEB30(lbl_805BE138, c);
}

int fn_803575E8(void* a, VT3C* s) { return s->s29(0x2632); }

int fn_80357624(void* a, Scr700* scr) { return fn_8017C974((Unk8017A930_T*)scr->m700); }

void fn_80357648(void* a, int b, int c) { fn_800FEB30(lbl_805BEEA0, c); }

int fn_80357674(void* a, VT3C* s) { return s->s29(0x2625); }

void fn_803576B0(void* a, void* b, int c) { fn_8011BD94(b, c); }

void fn_803576D8(void* a, int b, int c) { fn_800FEB30(lbl_805BEEAC, c); }

int fn_80357704(void* a, VT3C* s) { return s->s29(0x2626); }

void fn_80357740(void* a, void* b, int c) { fn_8011BE1C(b, c); }

void fn_80357768(void* a, int b, int c) { fn_800FEB30(lbl_805BEEB8, c); }

int fn_80357794(void* a, VT3C* s) { return s->s29(0x263e); }

void fn_803577D0(void* a, int b, int c) { fn_800FEB30(lbl_805BEEC4, c); }

int fn_803577FC(void* a, VT3C* s) { return s->s29(0x4f84); }

void fn_80357838(void* a, void* b, int c) { fn_8011BD0C(b, c); }

void fn_80357860(void* a, int b, int c) { fn_800FEB30(lbl_805BEED4, c); }

int fn_8035788C(void* a, VT3C* s) { return s->s29(0x262b); }

void fn_803578C8(void* a, void* b, int c) { fn_8011BF1C(b, c); }

void fn_803578F0(void* a, Scr700* scr, int c)
{
    fn_8017CD04(scr->m700, c, 1);
    fn_800FEB30(lbl_805BE138, c);
}

int fn_80357938(void* a, VT3C* s) { return s->s29(0x5bd0); }

void fn_80357974(void* a, Scr700* scr, int c) { fn_8017CA14((Unk8017A930_T*)scr->m700, c); }

Unk704* fn_8035799C(Act* self) { return fn_8011BC98(self->m8); }

void* fn_803579C0(void* self)
{
    PUT(0, lbl_8065D780);
    return self;
}

extern "C" void fn_803579D4(Unk803579D4* o)
{
    int i = o->m8;
    int k = i * 4;
    while (*(int*)((char*)o->mC + k) == 0 || *(int*)((char*)o->m10 + k) == 0 || *(int*)((char*)o->m14 + k) == 0) {
        int t;
        if (i > 9)
            t = i;
        else
            t = i + 1;
        o->m8 = t;
        i = t;
        k = i * 4;
    }
}

extern "C" void* fn_80357A5C(void* self)
{
    PUT(0, lbl_8065D768);
    return self;
}
