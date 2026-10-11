/*
 * Game code, .text 0x803543FC-0x80355A6C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8034B370.h"

struct Unk803548BC { char pad0[0x14]; Unk80353E68 m14; };
extern char lbl_8064B5D8[];
struct DtorAt10 { char pad[0x10]; const void* m; };

void fn_803543FC(Unk80353ECC* s)
{
    s->v9();
}

int fn_803544F4(Unk80353E68* s)
{
    return s->mC;
}

void fn_803544FC(Unk80353E68* s, int v)
{
    s->mC = v;
}

void fn_803548BC(Unk803548BC* s)
{
    s->m14.Clear();
}

int fn_80354900(Unk80353E68* s, int v)
{
    unsigned i;
    for (i = 0; i < s->m4; i++) {
        if (s->m0[i] == v)
            return i;
    }
    return -1;
}

struct Unk803549B8 {
    char pad0[0x18];
    int m18;
};
int fn_803549B8(Unk803549B8* s)
{
    return s->m18;
}

int fn_80354CA8(Unk80353E68* s)
{
    int i = 0;
    if (s->m4 != 0)
        i = s->m4 - 1;
    s->mC = i;
    return s->m0[i];
}

int fn_80354CD0(Unk80353E68* s)
{
    return s->mC == 0;
}

int fn_80354CE0(Unk80353E68* s)
{
    int r;
    if (s->m4 != 0)
        r = s->mC == s->m4 - 1;
    else
        r = s->mC == 0;
    return r;
}

void fn_80354D14(Unk80353ECC* s)
{
    s->v10();
}

void fn_80354D48(Unk80353E68* s)
{
    unsigned k = s->m4 - 1;
    s->mC = (s->mC + k) % s->m4;
}

void fn_80354D6C(Unk80353ECC* s)
{
    s->v9();
}

int fn_80354DA0(Unk80353ECC* s, int a)
{
    return s->v3() == a;
}

void fn_80354DEC(Unk80353E68* s, int v)
{
    s->mC = v;
}

int fn_80354FD4(Unk80353234* s)
{
    unsigned i = 0;
    s->mC = i;
    return s->m0[i];
}

int fn_80354FE8(Unk80353234* s)
{
    int i = 0;
    if (s->m4 != 0)
        i = s->m4 - 1;
    s->mC = i;
    return s->m0[i];
}

int fn_8035500C(Unk80353E68* s)
{
    return s->mC == 0;
}

int fn_8035501C(Unk80353E68* s)
{
    int r;
    if (s->m4 != 0)
        r = s->mC == s->m4 - 1;
    else
        r = s->mC == 0;
    return r;
}

void fn_80355050(Unk80353ECC* s)
{
    s->v10();
}

void fn_80355084(Unk80353E68* s)
{
    unsigned k = s->m4 - 1;
    s->mC = (s->mC + k) % s->m4;
}

void fn_803550A8(Unk80353ECC* s)
{
    s->v9();
}

int fn_803550DC(Unk80353ECC* s, int a)
{
    return s->v3() == a;
}

int fn_8035534C(void)
{
    return 0;
}

void fn_803553E0(DtorAt10* self, int chrg)
{
    self->m = lbl_8064B5D8;
    if (chrg & 1)
        fn_80377408(self);
}

int fn_80355518(Unk80353E68* s)
{
    return s->mC == 0;
}

int fn_80355528(Unk80353E68* s)
{
    int r;
    if (s->m4 != 0)
        r = s->mC == s->m4 - 1;
    else
        r = s->mC == 0;
    return r;
}

void fn_8035555C(Unk80353E68* s)
{
    s->mC = (s->mC + 1) % s->m4;
}

void fn_8035557C(Unk80353ECC* s)
{
    s->v10();
}

void fn_803555B0(Unk80353E68* s)
{
    unsigned k = s->m4 - 1;
    s->mC = (s->mC + k) % s->m4;
}

void fn_803555D4(Unk80353ECC* s)
{
    s->v9();
}

int fn_8035569C(Unk80353E68* s)
{
    return s->mC;
}

void fn_803556A4(Unk80353E68* s, int v)
{
    s->mC = v;
}

void fn_803559C0(Unk803548BC* s)
{
    s->m14.Clear();
}
