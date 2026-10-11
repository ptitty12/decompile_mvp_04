/*
 * Game code, .text 0x80353930-0x803543FC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8034B370.h"

extern char lbl_8064A208[];
struct DtorAt7E0 { char pad[0x7e0]; const void* m; };
extern char lbl_80649DA0[];
struct DtorAt4 { char pad[0x4]; const void* m; };
extern char lbl_8064A170[];
struct DtorAt30 { char pad[0x30]; const void* m; };
extern char lbl_8064A030[];
struct DtorAt10 { char pad[0x10]; const void* m; };
extern char lbl_80649EC0[];
struct DtorAt8 { char pad[0x8]; const void* m; };

void fn_80353984(DtorAt7E0* self, int chrg)
{
    self->m = lbl_8064A208;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_803539B8(Unk80353E68* s)
{
    s->m4 = 0;
    s->m8 = 0;
    s->mC = 0;
}

void fn_803539CC(DtorAt4* self, int chrg)
{
    self->m = lbl_80649DA0;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80353A00(DtorAt4* self, int chrg)
{
    self->m = lbl_80649DA0;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80353A34(DtorAt30* self, int chrg)
{
    self->m = lbl_8064A170;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80353A68(DtorAt10* self, int chrg)
{
    self->m = lbl_8064A030;
    if (chrg & 1)
        fn_80377408(self);
}

int fn_80353BDC(Unk80353E68* s)
{
    return s->m0[s->mC];
}

int fn_80353BF0(Unk80353E68* s)
{
    return s->mC;
}

void fn_80353BF8(void)
{
    for (int i = 0; i < 6; i++) {
    }
}

int fn_80353C08(Unk80353E68* s)
{
    s->mC = 0;
    return s->m0[0];
}

int fn_80353C1C(Unk80353E68* s)
{
    s->mC = 0;
    return s->m0[0];
}

void fn_80353C30(Unk80353E68* s)
{
    s->mC = (s->mC + 1) % s->m4;
}

unsigned* fn_80353C50(Unk80353E68* s)
{
    return &s->m4;
}

int* fn_80353C58(Unk80353E68* s)
{
    return &s->m8;
}

int fn_80353D90(Unk80353E68* s)
{
    return s->m4 - 1;
}

int fn_80353D9C(Unk80353E68* s)
{
    return s->m4;
}

void fn_80353DA4(Unk80353E68* s, int v)
{
    s->mC = v;
}

int fn_80353DAC(Unk80353234* s, int v)
{
    unsigned i;
    for (i = 0; i < s->m4; i++) {
        if (s->m0[i] == v)
            return i;
    }
    return -1;
}

void fn_80353DE4(DtorAt8* self, int chrg)
{
    self->m = lbl_80649EC0;
    if (chrg & 1)
        fn_80377408(self);
}

int fn_80353E18(Unk80353E68* s)
{
    s->mC = 0;
    return s->m0[0];
}

int fn_80353E2C(Unk80353E68* s)
{
    int i = 0;
    if (s->m4 != 0)
        i = s->m4 - 1;
    s->mC = i;
    return s->m0[i];
}

int fn_80353E54(Unk80353E68* s)
{
    return s->m0[s->mC];
}

int fn_80353E68(Unk80353E68* s)
{
    return s->mC == 0;
}

int fn_80353E78(Unk80353E68* s)
{
    int r;
    if (s->m4 != 0)
        r = s->mC == s->m4 - 1;
    else
        r = s->mC == 0;
    return r;
}

void fn_80353EAC(Unk80353E68* s)
{
    s->mC = (s->mC + 1) % s->m4;
}

void fn_80353ECC(Unk80353ECC* s)
{
    s->v10();
}

void fn_80353F00(Unk80353E68* s)
{
    unsigned k = s->m4 - 1;
    s->mC = (s->mC + k) % s->m4;
}

void fn_80353F24(Unk80353ECC* s)
{
    s->v9();
}

int fn_80353F58(Unk80353ECC* s, int a)
{
    return s->v3() == a;
}

int fn_80353FA4(Unk80353E68* s)
{
    return s->mC;
}

void fn_80353FAC(Unk80353E68* s, int v)
{
    s->mC = v;
}

int fn_80353FB4(Unk80353E68* s, int v)
{
    unsigned i;
    for (i = 0; i < s->m4; i++) {
        if (s->m0[i] == v)
            return i;
    }
    return -1;
}

int fn_80354340(Unk80353E68* s)
{
    return s->mC == 0;
}

int fn_80354350(Unk80353E68* s)
{
    int r;
    if (s->m4 != 0)
        r = s->mC == s->m4 - 1;
    else
        r = s->mC == 0;
    return r;
}

void fn_80354384(Unk80353E68* s)
{
    s->mC = (s->mC + 1) % s->m4;
}

void fn_803543A4(Unk80353ECC* s)
{
    s->v10();
}

void fn_803543D8(Unk80353E68* s)
{
    unsigned k = s->m4 - 1;
    s->mC = (s->mC + k) % s->m4;
}
