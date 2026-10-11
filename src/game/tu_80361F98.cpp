/*
 * Game code, .text 0x80361F98-0x80362A30 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_803606B0.h"

extern char lbl_80684820[];
struct DtorAt8 { char pad[0x8]; const void* m; };
extern char lbl_8064A030[];
struct DtorAt10 { char pad[0x10]; const void* m; };
extern char lbl_8064B5D8[];
extern char lbl_8064A550[];
extern char lbl_806848C8[];
struct DtorAt1C { char pad[0x1c]; const void* m; };

void fn_80361F98(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
struct Unk80361FCC_Y {
    char pad0[0x1B4];
    unsigned char m1B4[128];
};
struct Unk80361FCC_O {
    char pad0[0xC];
    Unk80361FCC_Y* mC;
    char pad10[0xC];
    Unk80361FCC_Y* m1C;
    char pad20[0xC];
    int m2C;
};
struct Unk80361FCC {
    Unk80361FCC_O* m0;
};
inline int Unk80361FCC_At(char* b, int off)
{
    return *(unsigned char*)(b + off);
}
//ENDHOIST
/* near-miss (14 of 32 slots): retail holds the byte index in r9 and the element
 * address (row + 0x1B4) in r11; here the index lands in r11 and the address in
 * r9. Same open SumRow family as fn_8001F788 / fn_8002A2D4. */
int fn_80361FCC(Unk80361FCC* s)
{
    Unk80361FCC_O* o = s->m0;
    int r = 0;
    if (o->m2C > 9) {
        int a = 0;
        for (int i = 0; i < 128; i++)
            a += Unk80361FCC_At((char*)o->mC + 0x1b4, (unsigned char)i);
        int c = 0;
        for (int j = 0; j < 128; j++)
            c += Unk80361FCC_At((char*)o->m1C + 0x1b4, (unsigned char)j);
        if (a > c)
            r = 1;
    }
    return r;
}

void fn_8036204C(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
struct Unk80362080 {
    char pad0[0xC];
    unsigned mC;
    unsigned m10;
};
struct Unk803620CC {
    char pad0[0xC];
    int mC;
    int m10;
    int m14;
};
//ENDHOIST
int fn_80362080(Unk80362080* s)
{
    return s->mC >= s->m10;
}

void fn_80362098(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

int fn_803620CC(Unk803620CC* s)
{
    int r = 0;
    if (!(s->mC < s->m10))
        r = s->mC < s->m14;
    return r;
}

int fn_803620F8(Unk803620CC* s)
{
    return s->mC >= s->m10;
}

int fn_80362114(Unk80353E68* s)
{
    s->mC = 0;
    return s->m0[0];
}

int fn_80362128(Unk80353E68* s)
{
    int i = 0;
    if (s->m4 != 0)
        i = s->m4 - 1;
    s->mC = i;
    return s->m0[i];
}

int fn_80362150(Unk80353E68* s)
{
    return s->m0[s->mC];
}

int fn_80362164(Unk80353E68* s)
{
    return s->mC == 0;
}

int fn_80362174(Unk80353E68* s)
{
    int r;
    if (s->m4 != 0)
        r = s->mC == s->m4 - 1;
    else
        r = s->mC == 0;
    return r;
}

void fn_803621A8(Unk80353E68* s)
{
    s->mC = (s->mC + 1) % s->m4;
}

void fn_803621C8(Unk80353ECC* s)
{
    s->v10();
}

void fn_803621FC(Unk80353E68* s)
{
    unsigned k = s->m4 - 1;
    s->mC = (s->mC + k) % s->m4;
}

void fn_80362220(Unk80353ECC* s)
{
    s->v9();
}

int fn_80362254(Unk80353ECC* s, int a)
{
    return s->v3() == a;
}

int fn_803622A0(Unk80353E68* s)
{
    return s->mC;
}

void fn_803622A8(Unk80353E68* s, int v)
{
    s->mC = v;
}

int fn_803622B0(Unk80353E68* s, int v)
{
    unsigned i;
    for (i = 0; i < s->m4; i++) {
        if (s->m0[i] == v)
            return i;
    }
    return -1;
}

void fn_803622F0(Unk80353E68* self, char** cursor, Unk803622F0* st)
{
    int tmp;
    unsigned cnt;
    unsigned cur;
    if (st->v2() == 1) {
        unsigned i = 0;
        fn_8040B190(*cursor, &self->m4, 4);
        *cursor += 4;
        fn_8040B190(*cursor, &self->mC, 4);
        *cursor += 4;
        for (; i < self->m4; i++) {
            int o = i * 4;
            tmp = *(int*)((char*)self->m0 + o);
            st->v1(cursor, &tmp, 4);
        }
    } else {
        unsigned j;
        fn_8040B190(&cnt, *cursor, 4);
        *cursor += 4;
        fn_8040B190(&cur, *cursor, 4);
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

float fn_803624D0(Unk803624D0* s)
{
    s->mC = 0;
    return s->m0[0];
}

float fn_803624E4(Unk803624D0* s)
{
    int i = 0;
    if (s->m4 != 0)
        i = s->m4 - 1;
    s->mC = i;
    return s->m0[i];
}

float fn_8036250C(Unk803624D0* s)
{
    return s->m0[s->mC];
}

int fn_80362520(Unk803624D0* s)
{
    return s->mC == 0;
}

int fn_80362530(Unk803624D0* s)
{
    int r;
    if (s->m4 != 0)
        r = s->mC == s->m4 - 1;
    else
        r = s->mC == 0;
    return r;
}

void fn_80362564(Unk803624D0* s)
{
    s->mC = (s->mC + 1) % s->m4;
}

void fn_80362584(Unk803624D0V* s)
{
    s->v10();
}

void fn_803625B8(Unk803624D0* s)
{
    unsigned k = s->m4 - 1;
    s->mC = (s->mC + k) % s->m4;
}

void fn_803625DC(Unk803624D0V* s)
{
    s->v9();
}

int fn_80362610(Unk803624D0V* s, float a)
{
    return s->v3() == a;
}

int fn_80362658(Unk803624D0* s)
{
    return s->mC;
}

void fn_80362660(Unk803624D0* s, int v)
{
    s->mC = v;
}

int fn_80362668(Unk803624D0* s, float v)
{
    unsigned i;
    for (i = 0; i < s->m4; i++) {
        if (s->m0[i] == v)
            return i;
    }
    return -1;
}

void fn_803626B8(Unk803624D0* self, char** cursor, Unk803622F0* st)
{
    float tmp;
    unsigned cnt;
    unsigned cur;
    if (st->v2() == 1) {
        unsigned i = 0;
        fn_8040B190(*cursor, &self->m4, 4);
        *cursor += 4;
        fn_8040B190(*cursor, &self->mC, 4);
        *cursor += 4;
        for (; i < self->m4; i++) {
            int o = i * 4;
            tmp = *(float*)((char*)self->m0 + o);
            st->v1(cursor, &tmp, 4);
        }
    } else {
        unsigned j;
        fn_8040B190(&cnt, *cursor, 4);
        *cursor += 4;
        fn_8040B190(&cur, *cursor, 4);
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

//HOISTBLOCK
extern float lbl_80602EC8;
//ENDHOIST
void fn_803628A0(Unk803628A0* s)
{
    s->m0 = 0;
    s->m4 = lbl_80602EC8;
    s->m8 = lbl_80602EC8;
    s->mC = lbl_80602EC8;
    s->m10 = lbl_80602EC8;
    s->m14 = lbl_80602EC8;
}

void fn_803628C8(DtorAt10* self, int chrg)
{
    self->m = lbl_8064A030;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_803628FC(DtorAt10* self, int chrg)
{
    self->m = lbl_8064B5D8;
    if (chrg & 1)
        fn_80377408(self);
}

Unk80362930::~Unk80362930()
{
    m1C = lbl_8064A550;
}

void fn_80362964(DtorAt8* self, int chrg)
{
    self->m = lbl_80684820;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80362998(DtorAt1C* self, int chrg)
{
    self->m = lbl_806848C8;
    if (chrg & 1)
        fn_80377408(self);
}

//HOISTBLOCK
extern "C" void fn_8037704C(void* heap, const char* name, int a, int b, int c);
extern void* lbl_80624234;
extern char lbl_80605478[];
struct Unk803629CC {
    int m0;
};
//ENDHOIST
void fn_803629CC(Unk803629CC* s, int a)
{
    fn_8037704C(lbl_80624234, lbl_80605478, a, s->m0, 0);
}

void fn_80362A08(void* s, int* p)
{
    delete[] p;
}
