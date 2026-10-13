/*
 * Game code, .text 0x80353930-0x803543FC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8034B370.h"
extern "C" void* memcpy(void*, const void*, unsigned);
#include "game/tu_803606B0.h"

extern char lbl_8064A208[];
struct DtorAt7E0 { char pad[0x7e0]; const void* m; };
extern char lbl_80649DA0[];
struct DtorAt4 { char pad[0x4]; const void* m; };
extern char lbl_8064A170[];
struct DtorAt30 { char pad[0x30]; const void* m; };
extern char lbl_8064A030[];
struct DtorAt10 { char pad[0x10]; const void* m; };
extern char lbl_8064A0F0[];
extern char lbl_8064B298[];
struct Unk80353A9C { Unk80353A9C_R m0; Unk80353A9C_R m14; char m28[8]; char m30[0x120]; };
extern char lbl_8064B698[];
extern char lbl_8064B5D8[];
#include "game/tu_80087A58.h"
extern char lbl_80649EC0[];
struct DtorAt8 { char pad[0x8]; const void* m; };

Unk80353930::Unk80353930()
{
    fn_80355354(this);
}

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

Unk80353A9C* fn_80353A9C(Unk80353A9C* s)
{
    s->m0.Init(s->m30, 8, 0x120, lbl_8064A0F0);
    s->m0.m10 = lbl_8064A030;
    s->m14.Init(s->m28, 2, 8, lbl_8064B298);
    return s;
}

Unk80353A9C* fn_80353B3C(Unk80353A9C* s)
{
    s->m0.Init(s->m30, 4, 0x70, lbl_8064B698);
    s->m0.m10 = lbl_8064B5D8;
    s->m14.Init(s->m28, 2, 8, lbl_8064B298);
    return s;
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

void* fn_80087B14();
void fn_80353C60(Unk80087A58_O* o, int a)
{
    if (fn_80087B14() != 0)
        o->mF5C[o->m8].b10.b = a;
}

struct Unk80353CB4_B { char pad0[0x1CD0]; int m1CD0; };
struct Unk80353CB4_A { char pad0[0x14]; Unk80353CB4_B* m14; };
struct Unk80087A58_V2 { float x; float y; };
extern float lbl_805B6288;
void fn_80087F7C(Unk80087A58_H* h, int v);
int fn_80088FFC(Unk80087A58_O* o, int i);
Unk80087A58_Pair* fn_8008903C(Unk80087A58_Pair* out, Unk80087A58_O* o, int i);
void fn_800896AC(char* base, int a, int b, int c, Unk80087A58_V2* v);
inline Unk80087A58_V2 MakeV2(float x, float y)
{
    Unk80087A58_V2 r;
    r.x = x;
    r.y = y;
    return r;
}
void fn_80353CB4(Unk80087A58_O* o, int a)
{
    if (fn_80087B14() != 0) {
        fn_80087F7C(&o->mF60, a);
        int r28 = 0;
        int z = ((Unk80353CB4_A*)o->m0)->m14->m1CD0 == 0;
        Unk80087A58_V2 p = MakeV2(lbl_805B6288, lbl_805B6288);
        if (o->m4 != 0) {
            r28 = fn_80088FFC(o, -1);
            Unk80087A58_Pair t;
            /* every caller of fn_8008903C sets cr1 for varargs (crclr), so call it as variadic */
            ((Unk80087A58_Pair* (*)(Unk80087A58_Pair*, Unk80087A58_O*, ...))fn_8008903C)(&t, o, -1);
            p = *(Unk80087A58_V2*)&t;
        }
        ((void (*)(char*, int, int, int, Unk80087A58_V2))fn_800896AC)(o->padC, z, r28, a, p);
    }
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

void fn_80353FF4(Unk80353E68* self, char** cursor, Unk803622F0* st)
{
    int tmp;
    unsigned cnt;
    unsigned cur;
    if (st->v2() == 1) {
        unsigned i = 0;
        memcpy(*cursor, &self->m4, 4);
        *cursor += 4;
        memcpy(*cursor, &self->mC, 4);
        *cursor += 4;
        for (; i < self->m4; i++) {
            int o = i * 4;
            tmp = *(int*)((char*)self->m0 + o);
            st->v1(cursor, &tmp, 4);
        }
    } else {
        unsigned j;
        memcpy(&cnt, *cursor, 4);
        *cursor += 4;
        memcpy(&cur, *cursor, 4);
        *cursor += 4;
        if (st->m0 == 0) {
            self->m4 = cnt;
            self->mC = cur;
            self->Clear();
        }
        for (j = 0; j < cnt; j++) {
            st->v1(cursor, &tmp, 4);
            if (st->m0 == 0)
                self->Add(tmp);
        }
        if (st->m0 == 0)
            self->mC = cur;
    }
}

Unk803541D4_E fn_803541D4(Unk803541D4* s)
{
    s->mC = 0;
    return s->m0[0];
}

Unk803541D4_E fn_80354244(Unk803541D4* s)
{
    int i = 0;
    if (s->m4 != 0)
        i = s->m4 - 1;
    s->mC = i;
    return s->m0[i];
}

Unk803541D4_E fn_803542CC(Unk803541D4* s)
{
    return s->m0[s->mC];
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
