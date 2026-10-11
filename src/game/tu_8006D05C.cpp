/*
 * Game code, .text 0x8006D05C-0x80070DDC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80070DDC.h"

void* operator new[](unsigned int size, int heap);
extern char lbl_80649DB8[];
extern char lbl_8064B0C8[];
extern char lbl_8064B058[];
extern const char lbl_805B3B4C[];
struct Unk8006F6C0_Date {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
};
extern Unk8006F6C0_Date lbl_806877AC;
struct Unk8006FB28_Rec {
    unsigned b0 : 8;
    unsigned b1 : 8;
    unsigned f2 : 7;
    unsigned f3 : 8;
    unsigned f4 : 1;
};
struct Unk8006F690_Obj {
    char pad0[8];
    void* m8;
};
void fn_80378620(Unk8006F690_Obj* self, int chrg);
struct Unk8006F9EC_Obj {
    char pad0[0x40];
    int m40;
    int m44;
};
Unk80071604* fn_80071604(Unk80071604* self, const char* name, Obj* type, unsigned count);
void fn_80071688(Unk80071604* self, int chrg);
void fn_8040074C(void* p, unsigned n);
unsigned fn_8007366C(const char* a, const char* b);
int fn_80075E7C(int x);
void fn_8008928C(void* ctx);
void fn_8006F74C(Unk8006902C_Ctx* c);
void fn_80089094(void* ctx, int a);
int fn_80353870(Unk8006902C_Side* s);
int fn_80097210(Unk8006902C_Side* s, int k);
void fn_800881FC(void* ctx, int side, int a, int b, int c);
void fn_80353C60(void* ctx, int k);
void fn_80353CB4(void* ctx, int k);
void fn_80089164(void* ctx);
extern int* lbl_8061B9C4;
int fn_80080724(void* l, int k, int c);
void fn_80080828(void* l, int k, int c, int v);
int fn_800968C0(Unk8006902C_Side* s, int e, int k);
int fn_80097620(Unk8006902C_Side* s, int a, int b, int c);
void fn_8009757C(Unk8006902C_Side* s, int a, int b, int c, int d);
int fn_8006FB28(void* l, int k, int c);
void fn_8006FC40(void* l, int k, int c, int v);
int fn_8008B42C(void* l, int k, int c);
void fn_8008B690(void* l, int k, int c, int v);
int fn_80099620(Unk8006902C_Side* s);
int fn_8009764C(Unk8006902C_Side* s, int a, int b, int c);
void fn_800975A8(Unk8006902C_Side* s, int a, int b, int c, int d);

/* near-miss: 1 slot (lwzx operand order, r30/r3 swapped). */
void Unk80069F0C::fn_8006D508()
{
    m44 = 0;
    m4C = 0;
    m50 = 0;
    m48 = -1;
    int side = 0;
    if (m14.m0->m1CD0 != 0)
        side = 1;
    Unk8006902C_Side* s = &m14.m0->s[side];
    int idx = fn_80353870(s);
    Unk8006902C_Rec* r = s->m3E8;
    int e = *(int*)((char*)r + idx * 0x34);
    if (mC->mC)
        fn_80089094(mC->mC, e);
}

void fn_8006DD60(void)
{
}

void Unk80069F0C::fn_8006DD64(int a)
{
    int side = 0;
    if (m14.m0->m1CD0 != 0)
        side = 1;
    Unk8006902C_Side* s = &m14.m0->s[side];
    int r = fn_80097210(&m14.m0->s[side ^ 1], 0);
    int idx = fn_80353870(s);
    Unk8006902C_Rec* rr = s->m3E8;
    fn_800881FC(mC->mC, side, r, *(int*)((char*)rr + idx * 0x34), a);
}

void Unk80069F0C::fn_8006DDF4()
{
    fn_80353C60(mC->mC, 5);
    fn_80089164(mC->mC);
    Unk8006902C_Players* p = m14.m0;
    int a = p->m1CCC;
    int b = p->m1CCA;
    if (a <= 0xFE)
        p->m1CCC = a + 1;
    if (b <= 1) {
        m14.m0->m1CCA = b + 1;
    } else {
        Unk8006902C_Players* q = m14.m0;
        int c = q->m1CCD;
        if (c <= 0xFE)
            q->m1CCD = c + 1;
    }
}

void Unk80069F0C::fn_8006DE84(Unk8006902C_EvDE84* ev)
{
    if (ev != 0 && ev->mC == 0) {
        fn_80353C60(mC->mC, 4);
        fn_80089164(mC->mC);
    } else {
        mC->mC->m1750 = 1;
    }
    m14.m0->m1CCB++;
}

void Unk80069F0C::fn_8006DF00()
{
    fn_80353C60(mC->mC, 2);
    if (m14.m0->m1CCA == *lbl_8061B9C4)
        fn_80353CB4(mC->mC, 0xF);
    fn_80089164(mC->mC);
    m14.m0->m1CCA++;
}

void Unk80069F0C::fn_8006E0F8(Unk8006902C_EvC17C* ev)
{
    Unk8006902C_Players* p = m14.m0;
    int idx = p->m1CD0 == 0;
    Unk8006902C_Side* s = &p->s[idx];
    unsigned char c = s->m17C[ev->mC];
    char* l = s->m95C;
    fn_80080828(l, 0, c, fn_80080724(l, 0, c) + 1);
}

void Unk80069F0C::fn_8006E168(Unk8006902C_EvC17C* ev)
{
    fn_8006F258(ev);
    m44 = 1;
    int side = 0;
    int id = ev->mC;
    m48 = id;
    if (m14.m0->m1CD0 != 0)
        side = 1;
    Unk8006902C_Side* s = &m14.m0->s[side ^ 1];
    unsigned char c = s->m17C[id];
    char* l = s->m95C;
    fn_80080828(l, 1, c, fn_80080724(l, 1, c) + 1);
}

void Unk80069F0C::fn_8006E1FC(Unk8006902C_EvC17C* ev)
{
    Unk8006902C_Players* p = m14.m0;
    unsigned id = ev->mC;
    int side = 0;
    if (p->m1CD0 != 0)
        side = 1;
    side ^= 1;
    if (id <= 9) {
        Unk8006902C_Side* s = &p->s[side];
        unsigned char c = s->m17C[id];
        char* l = s->m95C;
        fn_80080828(l, 2, c, fn_80080724(l, 2, c) + 1);
    }
}

void Unk80069F0C::fn_8006E280(Unk8006902C_EvE280* ev)
{
    Unk8006902C_Side* s = &m14.m0->s[ev->m10];
    int r = fn_800968C0(s, ev->mC, 1);
    if (fn_80097620(s, 0, r, 0) == 0)
        fn_8009757C(s, 0, r, 1, 0);
}

void Unk80069F0C::fn_8006E2FC(Unk8006902C_EvE2FC* ev)
{
    Unk8006902C_Players* p = m14.m0;
    int side = 0;
    if (p->m1CD0 != 0)
        side = 1;
    unsigned char c = ev->m14;
    Unk8006902C_Side* s = &p->s[side];
    char* l = s->m92C;
    fn_8006FC40(l, 2, c, fn_8006FB28(l, 2, c) + 1);
}

void Unk80069F0C::fn_8006E36C(Unk8006902C_EvE36C* ev)
{
    Unk8006902C_Players* p = m14.m0;
    int side = 0;
    if (p->m1CD0 != 0)
        side = 1;
    unsigned char c = ev->mF;
    Unk8006902C_Side* s = &p->s[side ^ 1];
    char* l = s->m8FC;
    fn_8008B690(l, 0xC, c, fn_8008B42C(l, 0xC, c) + 1);
}

void Unk80069F0C::fn_8006E5FC(Unk8006902C_EvE5FC* ev)
{
    int off = ev->m10->m708 * 0xE64;
    if (fn_80099620((Unk8006902C_Side*)((char*)m14.m0 + off)) == 0)
        ((Unk8006902C_Side*)((char*)m14.m0 + off))->m234 = 0;
}

void Unk80069F0C::fn_8006E650(Unk8006902C_EvE650* ev)
{
    int off = ev->m14->m708 * 0xE64;
    if (fn_80099620((Unk8006902C_Side*)((char*)m14.m0 + off)) == 0)
        ((Unk8006902C_Side*)((char*)m14.m0 + off))->m234 = 0;
}

void Unk80069F0C::fn_8006E6A4()
{
    Unk8006902C_Players* p = m14.m0;
    int idx = p->m1CD0 == 0;
    Unk8006902C_Side* s = &p->s[idx];
    unsigned char c = s->m17C[0];
    fn_800975A8(s, 0xD, c, fn_8009764C(s, 0xD, c, 0) + 1, 0);
}

void fn_8006F690(Unk8006F690_Obj* self, int chrg)
{
    self->m8 = lbl_80649DB8;
    fn_80378620(self, chrg);
}

void fn_8006F6C0(Unk8006902C_Ctx* c)
{
    c->m24 = 9;
    c->m28 = fn_80075E7C(9);
    c->m30 = 10;
    c->m2C = 0;
    c->m80 = 0;
    c->m34 = 0;
    Unk8006F6C0_Date d;
    d.m0 = lbl_806877AC.m0;
    d.m1 = lbl_806877AC.m1;
    d.m2 = 2005;
    c->m600 = 0;
    c->m7C = *(int*)&d;
    fn_8006F74C(c);
}

void fn_8006F74C(Unk8006902C_Ctx* c)
{
    fn_8008928C(c->mC);
    c->m20 = 0;
}

int* fn_8006F9EC(Unk8006F9EC_Obj* o, int* out)
{
    *out = o->m40;
    return &o->m44;
}

Unk80071604* fn_8006F9FC(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_8064B0C8;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C << 2, 0);
    fn_8040074C(self->m24, self->m1C << 2);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B3B4C);
    return self;
}

void fn_8006FA78(Unk80071604* self, int chrg)
{
    self->m20 = lbl_8064B0C8;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

void fn_8006FAD4(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + i * 4, 4);
}

int fn_8006FB28(void* l, int k, int c)
{
    Unk80071604* a = (Unk80071604*)l;
    int r = 0;
    if ((unsigned)c < a->m1C) {
        switch ((unsigned)k) {
        case 0:
            r = ((Unk8006FB28_Rec*)a->m24)[c].b0;
            break;
        case 1:
            r = ((Unk8006FB28_Rec*)a->m24)[c].b1;
            break;
        case 2:
            r = ((Unk8006FB28_Rec*)a->m24)[c].f2;
            break;
        case 3:
            r = ((Unk8006FB28_Rec*)a->m24)[c].f3;
            break;
        }
    }
    return r;
}

Unk80071604* fn_8006FE88(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_8064B058;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C * 12, 0);
    fn_8040074C(self->m24, self->m1C * 12);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B3B4C);
    return self;
}

void fn_8006FF04(Unk80071604* self, int chrg)
{
    self->m20 = lbl_8064B058;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

void fn_8006FF60(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + i * 12, 12);
}
