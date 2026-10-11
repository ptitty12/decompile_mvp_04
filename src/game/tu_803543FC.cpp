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

int fn_80354430(Unk80354430* s, const Unk803541D4_E* key)
{
    Unk803541D4_E e = s->v3();
    return e.EqAll(*key);
}

int fn_803544F4(Unk80353E68* s)
{
    return s->mC;
}

void fn_803544FC(Unk80353E68* s, int v)
{
    s->mC = v;
}

int fn_80354504(Unk803541D4* s, const Unk803541D4_E* key)
{
    unsigned i;
    for (i = 0; i < s->m4; i++) {
        if (s->m0[i].EqAll(*key))
            return i;
    }
    return -1;
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

void fn_80354940(Unk80354940* s, int v)
{
    if (s->m14.Find(v) == -1)
        s->m14.Add(v);
}

struct Unk803549B8 {
    char pad0[0x18];
    int m18;
};
int fn_803549B8(Unk803549B8* s)
{
    return s->m18;
}

int fn_80354A1C(Unk80354940* s)
{
    int n = 0;
    for (unsigned i = 0; i < s->m4;) {
        if (s->v19(i++) == 1)
            n++;
    }
    return n;
}

Unk803541D4_E* fn_80354A94(Unk80354940* s, unsigned n)
{
    unsigned cnt = 0;
    for (unsigned i = 0; i < s->m4; i++) {
        if (s->v19(i) == 1) {
            if (cnt++ >= n)
                return &s->m0[i];
        }
    }
    return s->m0;
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

struct Unk803552F8 {
    int m0;
};
void fn_803552F8(Unk803552F8* self, char** cursor, void* dst, int n)
{
    if (self->m0 == 0)
        fn_8040B190(dst, *cursor, n);
    *cursor += n;
}

int fn_8035534C(void)
{
    return 0;
}

void fn_80355354(Unk80353930* z)
{
    z->m8 = 1;
    z->b0 = 0;
    z->b1 = 0;
    z->b3 = 0;
    z->b2 = 0;
    z->b4 = 0;
    z->b5 = 0;
    Unk8006A138_It<3> it(0);
    int k = 0;
    do {
        fn_80080B98((Unk8007FF8C_Q*)&z->q[k]);
        k = it.Next();
    } while (k <= 3);
}

void fn_803553E0(DtorAt10* self, int chrg)
{
    self->m = lbl_8064B5D8;
    if (chrg & 1)
        fn_80377408(self);
}

Unk80355414_E fn_80355414(Unk80355414* s)
{
    s->mC = 0;
    return s->m0[0];
}

Unk80355414_E fn_80355460(Unk80355414* s)
{
    int i = 0;
    if (s->m4 != 0)
        i = s->m4 - 1;
    s->mC = i;
    return s->m0[i];
}

Unk80355414_E fn_803554C8(Unk80355414* s)
{
    return s->m0[s->mC];
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

int fn_80355608(Unk80355608* s, const Unk80355414_E* key)
{
    Unk80355414_E e = s->v3();
    return e.Eq(*key);
}

int fn_8035569C(Unk80353E68* s)
{
    return s->mC;
}

void fn_803556A4(Unk80353E68* s, int v)
{
    s->mC = v;
}

int fn_803556AC(Unk80355414* s, const Unk80355414_E* key)
{
    unsigned i;
    for (i = 0; i < s->m4; i++) {
        if (s->m0[i].Eq(*key))
            return i;
    }
    return -1;
}

void fn_803559C0(Unk803548BC* s)
{
    s->m14.Clear();
}

int fn_80354900(Unk80353E68* s, int v);
void fn_80355A04(Unk80354940* s, int v)
{
    if (fn_80354900(&s->m14, v) == -1)
        s->m14.Add(v);
}
