/*
 * Game code, .text 0x803597C4-0x8035A2D0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"

void fn_803597C4(Unk803597C4* s)
{
    for (int i = 0; i < 8; i++)
        s->m0[i].Init();
}

struct Unk803598A0_E {
    int m0;
    int m4;
    int m8;
    float mC;
    float m10;
};
struct Unk803598A0_F {
    float v;
};
extern Unk803598A0_F lbl_805CADB4;
void* fn_803598A0(char* self)
{
    Unk803598A0_E* e = (Unk803598A0_E*)(self + 4);
    for (int i = 0; i < 8; i++) {
        e[i].m0 = 0;
        e[i].m4 = 0;
        e[i].m8 = 0;
        e[i].m10 = e[i].mC = lbl_805CADB4.v;
    }
    fn_80359B3C((int*)(self + 0xa4));
    fn_80359B04(self);
    return self;
}

extern "C" void fn_80359910(int* self)
{
    fn_80359948(self, 0);
    *self = 0;
}

extern "C" struct Unk80359948_E {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
struct Unk80359948 {
    int cnt;
    Unk80359948_E a[8];
};
void fn_80359948(void* p, int v)
{
    Unk80359948* self = (Unk80359948*)p;
    if (self->cnt < 0)
        return;
    self->a[self->cnt].m0 = v;
}

int fn_80359964(char* self) { return F(int, self, 0x1e00) == 0; }

void fn_80359974(float a, float b, float c) {}

int fn_8035998C(float a, float b, float c) { return 1; }

float fn_803599A8(float a) { return lbl_805CADB8; }

void fn_803599C0(void* self, int c)
{
    PUT(0x0, lbl_8065EB00);
    if (c & 1)
        fn_80377408(self);
}

void fn_803599F4() {}

void fn_803599F8(char* self, int c)
{
    fn_80151048(self + 8, 2);
    if (c & 1)
        fn_80377408(self);
}

extern "C" void fn_80359A40(Unk80359A40* s)
{
    s->m0 = 0;
    s->m4 = 0;
    s->m8 = lbl_805CADBC;
    s->mC = 0;
    s->m10 = 0;
}

void fn_80359A64(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80359A98(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

struct Unk80359ACC {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};
void fn_80359ACC(Unk80359ACC* s)
{
    s->m0 = 0;
    s->m4 = lbl_8062087C;
    s->m8 = 0;
    s->mC = 0;
    s->m10 = 0;
    s->m14 = 0;
    s->m18 = 0;
}

void fn_80359AF8(int* p) { *p = 0; }

void fn_80359B04(char* self)
{
    int z = 0;
    F(int, self, 0x0) = z;
    fn_80359910((int*)self);
    F(int, self, 0xa4) = z;
}

void fn_80359B3C(int* p) { *p = 0; }

void fn_80359B48(void* self, int c)
{
    PUT(0x0, lbl_8065EC68);
    fn_8037B424(self, c);
}

extern "C" void fn_80359B78(void* self, int c)
{
    PUT(0x0, lbl_80649C48);
    if (c & 1)
        fn_80377408(self);
}

extern "C" Unk803442CC* fn_80359BAC()
{
    if (lbl_8068B880 == 0) {
        fn_8035A15C(&lbl_8068B87C);
        lbl_8068B880 = 1;
        fn_80409CF0(fn_8017045C);
    }
    return &lbl_8068B87C;
}

void fn_80359C08(void* self, int c)
{
    PUT(0, lbl_8065EDB8);
    fn_804007FC((char*)self + 4);
    if (c & 1)
        fn_80377408(self);
}

extern "C" /* near-miss: 1 slot. Retail's first memset (after the vptr store) has `crclr cr1eq`, the second does not: the
   first is a compiler-generated clear (a polymorphic class: vptr store and member init), the second an
   explicit call. A `m4()` member initialiser clears before the base ctor call instead. */
Unk80359C58* fn_80359C58()
{
    if (lbl_8068B8A8 == 0) {
        new (&lbl_8068B884) Unk80359C58;
        lbl_8068B8A8 = 1;
        fn_80409CF0(fn_80170488);
    }
    return &lbl_8068B884;
}

/* near-miss: same crclr slot as fn_80359C58 (inline ctor of Unk80359C58) */
Unk80359C58* fn_80359CF8() { return new (0x100) Unk80359C58; }

int fn_80359D78(int* self) { return ++self[8]; }

int fn_80359D8C(Unk80359C58* o)
{
    int c = --o->m20;
    if (c <= 0) {
        delete (Unk80359D8C_VT*)o;
        return 0;
    }
    return c;
}

void fn_80359DE8(char* self) { fn_80400828(self + 4); }

void fn_80359E0C(char* self) { fn_8040084C(self + 4); }

void fn_80359E30(char* self, int c)
{
    PUT(0, lbl_8065ED60);
    if (F(int, self, 0x330) != 0)
        fn_8035A09C(self, 0);
    fn_803FFEB8(self + 0x14);
    if (c & 1)
        fn_80377408(self);
}

/* fn_80359E94: not matched. Lazy singleton of the 0x334-byte thread object (same crclr memset issue as fn_80359C58,
   plus a dead lis/ori 0x19000); the original code stays linked */

/* fn_80359F30: not matched. Factory for the same object (see fn_80359E94); the original code stays linked */

int fn_80359FB0(int* o)
{
    int c = --o[1];
    if (c <= 0) {
        delete (Unk80359FB0_VT*)o;
        return 0;
    }
    return c;
}

int fn_8035A00C(int* self) { return ++self[1]; }

void fn_8035A020(void* p, int v) { F(int, p, 0xc) = v; }

void fn_8035A028(char* self, int v)
{
    F(int, self, 0x8) = v;
    int h = fn_803ED5E0(lbl_805CB03C, F(int, self, 0xc), 0x10, 0, 0x100);
    F(int, self, 0x10) = h;
    fn_803FFE3C(self + 0x14, (void (*)(void*))fn_8035A198, self, h, F(int, self, 0xc), F(int, self, 0x32c));
    F(int, self, 0x330) = 1;
}

extern "C" void fn_8035A09C(char* self, int unused)
{
    fn_80400114(self + 0x14, 0);
    fn_803EDA0C(F(int, self, 0x10));
    F(int, self, 0x330) = 0;
}

void fn_8035A0E0(void* a, int b) { fn_803FFFA8(b); }

void fn_8035A104(char* self, int v)
{
    F(int, self, 0x32c) = v;
    fn_80400068(self + 0x14, v);
}

void* fn_8035A134(void* self)
{
    PUT(0, lbl_8065EF20);
    return self;
}

void* fn_8035A148(void* self)
{
    PUT(0, lbl_8065EEE8);
    return self;
}

Unk803442CC* fn_8035A15C(Unk803442CC* self)
{
    fn_803445A8(self);
    PUT(0, lbl_8065EEB0);
    return self;
}

void fn_8035A198(void* t)
{
    while (!fn_8035A2C8(t))
        fn_803FFFA8(1);
    ((void (*)(void*))fn_8035A2C0(t))(t);
}

int fn_8035A1F4() { return 0; }

int fn_8035A1FC() { return 0; }

int fn_8035A204() { return 0; }

int fn_8035A20C() { return 0; }

struct Unk8035A214_Opt {
    int kind;
    int m4;
    Unk8035A214_Opt* m8;
};
void fn_8035A214(void* a, int b, Unk8035A214_Opt* p)
{
    int v1 = 0;
    int v2 = 0;
    Unk8035A214_Opt* q;
    if (p->kind != 0 && (q = p) != 0) {
        do {
            switch (q->kind) {
            case 1:
                v1 = q->m4;
                break;
            case 2:
                v2 = q->m4;
                break;
            }
            q = q->m8;
        } while (q != 0);
    }
    fn_803ED5E0((const void*)v1, b, v2, 0, 0x100);
}

void fn_8035A28C(void* a, int b) { fn_803EDA0C(b); }

int fn_8035A2B0() { return 0; }

int fn_8035A2B8() { return 0; }

int fn_8035A2C0(void* p) { return F(int, p, 0x8); }

int fn_8035A2C8(void* p) { return F(int, p, 0x330); }
