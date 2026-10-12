/*
 * Game code, .text 0x8006D05C-0x80070DDC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80070DDC.h"
#include "game/tu_8007FF8C.h"
extern const char lbl_805B2CB0[];
void fn_80080BFC(Unk8007FF8C_Y* y);
extern "C" void fn_800962B4(void* p);
extern "C" void* fn_8008F840__FPt13Unk8008CE64_K1Z15Unk8008CE64_T1C(void* self, const char* name, int a, int count);
struct Unk8006F4D0_Side {
    char pad0[0xE64];
    Unk8006F4D0_Side() { fn_800962B4(this); }
};
struct Unk80353930 {
    char pad0[0x3C];
    Unk80353930();
};
struct Unk8006F4D0_K {
    char pad0[0x28];
    Unk8006F4D0_K(int c) { fn_8008F840__FPt13Unk8008CE64_K1Z15Unk8008CE64_T1C(this, lbl_805B2CB0, 0, c); }
};
struct Unk8006F4D0_Y {
    Unk8006F4D0_Side s[2];
    Unk80353930 z0;
    Unk80353930 z1;
    char pad1D40[0x14];
    Unk8006F4D0_K k0;
    Unk8006F4D0_K k1;
    Unk8006F4D0_Y() : k0(0x10), k1(0xD) { fn_80080BFC((Unk8007FF8C_Y*)this); }
};
struct Unk8006F784_C {
    char pad0[0x24];
    int m24;
    int m28;
    char pad2C[0x3C - 0x2C];
    int m3C;
    int m40;
    int m44[16];
};
struct Unk8006F784_C2 {
    char pad0[0x78];
    int m78;
};
struct Unk8006F784_O {
    char pad0[0xC];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};
struct Unk8006F784_A {
    char pad0[4];
    void* m4;
};
struct Unk8006F784_B {
    char pad0[0x42C];
    int m42C;
};
struct Unk8006F784_G {
    char pad0[0x30];
    Unk8006F784_A* m30;
    Unk8006F784_B* m34;
};
extern Unk8006F784_G* lbl_8061930C;
extern const int lbl_805B62F8[];
Unk8006F784_O* fn_8058F11C(Unk8006F784_B* b, int a);
void* fn_8058F1F0(Unk8006F784_B* b, int a);
int fn_80590188(void* p, int a);
int fn_80593E7C(void* p, int a);
int fn_805948D0(void* p, int a, int b);
struct Unk8006DF80_R {
    char pad0[0x20];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(int a, int b);
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b, int c);
};
struct Unk8006DF80_S {
    char pad0[0x168];
    unsigned char* m168;
    char pad16C[0x174 - 0x16C];
    int m174;
    char pad178[4];
    unsigned char m17C;
    char pad17D[0x924 - 0x17D];
    Unk8006DF80_R* m924[3];
    char pad930[0x954 - 0x930];
    Unk8006DF80_R* m954[3];
    char pad960[0xC9C - 0x960];
    char mC9C[0x30];
};
int fn_8008CFD8(char* p, int a, int b);

void* operator new[](unsigned int size, int heap);
void* operator new(unsigned int size, int heap);
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
struct Unk80070004_Rec {
    unsigned f0 : 7;
    unsigned f1 : 8;
    unsigned f2 : 8;
    unsigned f3 : 7;
    unsigned p0 : 2;
    unsigned f4 : 7;
    unsigned f5 : 8;
    unsigned f6 : 8;
    unsigned f7 : 7;
    unsigned p1 : 2;
    unsigned f8 : 7;
    unsigned f9 : 7;
    unsigned f10 : 7;
    unsigned f11 : 10;
    unsigned p2 : 1;
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
extern const float lbl_805B3B7C;
extern const float lbl_805B3B60;
extern const float lbl_805B3B78;
extern const float lbl_805B3BA0;
extern const float lbl_805B3BA4;
extern const float lbl_805B3BA8;
extern const float lbl_805B3BAC;
extern const float lbl_805B3BB8;
extern const float lbl_805B3B88;
extern const float lbl_805B3B8C;
extern const float lbl_805B3B90;
float fn_80070A60(W* w, int a);

void fn_80071E2C(Unk80071604* self, int a, Unk80070DDC_Stream* io);
float fn_8007057C(void* self, int a);
float fn_800706C0(void* self, int a);
float fn_80070880(void* self, int a);
float fn_80070BC8(void* self, int a);
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

unsigned char* fn_80081CF8(Unk8007FF8C_Y* y, int i);
void fn_8009984C(Unk8006902C_Side* s, int a, int b, int c, int d, int e);

inline int SumRowI(Unk8006902C_Side* s)
{
    int t = 0;
    int i;
    for (i = 0; i < 0x80; i++)
        t += s->m1B4[(unsigned char)i];
    return t;
}

void Unk80069F0C::fn_8006D410()
{
    Unk8006902C_Players* p = m14.m0;
    int side = 0;
    if (p->m1CD0 != 0)
        side = 1;
    Unk8006902C_Side* me = &p->s[side];
    Unk8006902C_Side* other = &p->s[side ^ 1];
    int cnt = 0;
    unsigned k;
    for (k = 0; k <= 2; k++) {
        if (*fn_80081CF8((Unk8007FF8C_Y*)p, k) != 0xFF)
            cnt++;
    }
    int x = fn_80097210(other, 0);
    int s0 = SumRowI(other);
    int s1 = SumRowI(me);
    fn_8009984C(other, x, s0, s1, m14.m0->m1CC8, cnt);
}

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
    int off = idx * 0x34;
    int e = *(int*)((char*)r + off);
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

void Unk80069F0C::fn_8006DF80()
{
    Unk8006902C_Players* p = m14.m0;
    int side = 0;
    if (p->m1CD0 != 0)
        side = 1;
    int z = p->m1CD0 == 0;
    Unk8006DF80_S* mine = (Unk8006DF80_S*)((char*)p + side * 0xE64);
    Unk8006DF80_S* other = (Unk8006DF80_S*)((char*)p + z * 0xE64);
    unsigned char ca = other->m17C;
    unsigned char cb = mine->m168[mine->m174];
    int xa = fn_8008CFD8(other->mC9C, 9, ca) == 0;
    int rb = fn_8008CFD8(mine->mC9C, 8, cb);
    int xb = rb == 0;
    if (rb == 2)
        xb = 1;
    char* ta = (char*)other + 0x924;
    int oa = xb * 4;
    int ob = xa * 4;
    char* tb = (char*)mine + 0x954;
    int na = (*(Unk8006DF80_R**)(ta + oa))->v5(3, ca) + 1;
    (*(Unk8006DF80_R**)(ta + oa))->v8(3, ca, na);
    int nb = (*(Unk8006DF80_R**)(tb + ob))->v5(0xA, cb) + 1;
    (*(Unk8006DF80_R**)(tb + ob))->v8(0xA, cb, nb);
    fn_80353C60(mC->mC, 4);
    fn_80353CB4(mC->mC, 0xE);
    fn_80089164(mC->mC);
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

struct Unk80087A58_O;
Unk80087A58_O* fn_80087FC0(Unk80087A58_O* o);
void fn_8006F6C0(Unk8006902C_Ctx* c);
extern "C" void fn_803785E4(void* sub);
extern "C" void fn_800A6D30(void* p);
extern char lbl_8064A1E0[];
struct Unk8006F594_Obj {
    char pad0[8];
    void* m8;
    Unk80087A58_O* mC;
    float m10;
    int m14;
    float m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    char pad3C[0x40];
    int m7C;
    int m80;
    int m84;
    int m88;
    int m8C;
    float m90;
    float m94;
    float m98;
    float m9C;
    char mA0[0x560];
    int m600;
};

Unk8006902C_Handle* fn_8006F4D0(Unk8006902C_Handle* h)
{
    h->m0 = 0;
    h->m4 = 0;
    h->m8 = 0;
    Unk8006F4D0_Y* y = new (0) Unk8006F4D0_Y;
    h->m4 = 0;
    h->m8 = 0;
    h->mC = 0;
    h->m0 = (Unk8006902C_Players*)y;
    return h;
}

Unk8006902C_Ctx* fn_8006F594(void* p)
{
    Unk8006F594_Obj* self = (Unk8006F594_Obj*)p;
    fn_803785E4(self);
    self->m8 = lbl_8064A1E0;
    self->mC = 0;
    self->m10 = 1.0f;
    self->m14 = 0;
    self->m18 = 0.0f;
    self->m1C = 2;
    self->m20 = 0;
    self->m24 = 0x57;
    self->m28 = 0x38;
    self->m2C = 4;
    self->m30 = 0x1F;
    self->m34 = 0x10;
    self->m38 = 0;
    self->m7C = *(int*)&lbl_806877AC;
    self->m80 = 0;
    self->m84 = 4;
    self->m88 = -1;
    self->m8C = 0;
    self->m90 = 0.0f;
    self->m94 = 0.0f;
    self->m98 = 0.0f;
    self->m9C = 0.0f;
    fn_800A6D30(self->mA0);
    self->m600 = 0;
    if (self->mC == 0)
        self->mC = fn_80087FC0((Unk80087A58_O*)operator new(0x1754, 0));
    fn_8006F6C0((Unk8006902C_Ctx*)self);
    return (Unk8006902C_Ctx*)self;
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

/* near-miss (99%): one lwzx has its base and index registers swapped (retail lwzx r0,r27,r29) */
extern "C" void fn_8006F784(Unk8006902C_Ctx* c, int v)
{
    Unk8006F784_C* cv = (Unk8006F784_C*)c;
    c->m24 = v;
    int t = fn_80075E7C(v);
    c->m28 = t;
    cv->m3C = 0;
    cv->m40 = 0;
    ((Unk8006F784_C2*)c)->m78 = 0;
    if (t == 0x37) {
        if (lbl_8061930C->m34->m42C != 0) {
            int i = 0;
            ((Unk8006F784_C2*)c)->m78 = fn_8058F11C(lbl_8061930C->m34, 0)->v4();
            void* p = fn_8058F1F0(lbl_8061930C->m34, 1);
            do {
                int r = fn_80590188(p, i);
                i++;
                cv->m3C += r;
            } while (i <= 4);
            int seen[13];
            for (int j = 0; j < 13; j++)
                seen[j] = 0;
            i = 0;
            int off = 0;
            do {
                int b = 0;
                do {
                    if (fn_80593E7C(lbl_8061930C->m30->m4, b) > 0 && fn_805948D0(lbl_8061930C->m30->m4, i, b) > 0 && *(int*)(off + (char*)seen) == 0) {
                        *(int*)((char*)seen + off) = 1;
                        cv->m44[cv->m40] = i;
                        cv->m40++;
                    }
                    b++;
                } while (b <= 8);
                i++;
                off += 4;
            } while (i <= 0xC);
        }
    } else {
        cv->m3C = lbl_805B62F8[t];
    }
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

/* Every column yields 0; the original keeps the case tree as dead compares
   (PATTERNS, "Hard-case families 4"). */
int fn_8006FB10(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    }
    return r;
}

int fn_8006FB1C(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    }
    return r;
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

typedef float (W::*Unk8006FBAC_Pmf)(int);
extern Unk8006FBAC_Pmf lbl_805B63D8[];

float fn_8006FBAC(W* o, int i, int a)
{
    float r = (o->*(lbl_805B63D8 + i)[0])(a);
    return r;
}

void fn_8006FC40(void* l, int k, int c, int v)
{
    Unk80071604* a = (Unk80071604*)l;
    if ((unsigned)c < a->m1C) {
        switch ((unsigned)k) {
        case 0: {
            unsigned base = (unsigned)a->m24;
            Unk8006FB28_Rec* r = (Unk8006FB28_Rec*)((unsigned)c * 4 + base);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
                r->b0 = v;
            } else {
                r->b0 = 0xFF;
            }
            return;
        }
        case 1: {
            Unk8006FB28_Rec* r = (Unk8006FB28_Rec*)((unsigned)c * 4 + (unsigned)a->m24);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
                r->b1 = v;
            } else {
                r->b1 = 0xFF;
            }
            return;
        }
        case 2: {
            Unk8006FB28_Rec* r = (Unk8006FB28_Rec*)((unsigned)c * 4 + (unsigned)a->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7F;
            }
            r->f2 = v;
            return;
        }
        case 3: {
            Unk8006FB28_Rec* r = (Unk8006FB28_Rec*)((unsigned)c * 4 + (unsigned)a->m24);
            int t;
            if (v <= 0xFF) {
                t = v;
                if (t < 0)
                    t = 0;
            } else {
                t = 0xFF;
            }
            r->f3 = t;
            return;
        }
        }
    }
}

float fn_8006FD44(W* w, int a)
{
    float x = (float)w->v28(1, a);
    float s = x + (float)w->v28(2, a);
    float r = lbl_805B3B60;
    if (!(s <= lbl_805B3B60))
        r = x / s;
    return r;
}

void fn_8006FE2C(Unk80071604* self, int a, Unk80070DDC_Stream* io)
{
    fn_80071E2C(self, a, io);
    io->v08(a, self->m24, self->m1C << 2);
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

/* Every column yields 0; the original keeps the case tree as dead compares
   (PATTERNS, "Hard-case families 4"). */
int fn_8006FF9C(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    case 4:
        r = 0;
        break;
    case 5:
        r = 0;
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = 0;
        break;
    case 9:
        r = 0;
        break;
    case 10:
        r = 0;
        break;
    case 11:
        r = 0;
        break;
    }
    return r;
}

int fn_8006FFD0(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    case 4:
        r = 0;
        break;
    case 5:
        r = 0;
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = 0;
        break;
    case 9:
        r = 0;
        break;
    case 10:
        r = 0;
        break;
    case 11:
        r = 0;
        break;
    }
    return r;
}

unsigned fn_80070004(void* l, int k, unsigned c)
{
    Unk80071604* a = (Unk80071604*)l;
    unsigned r = 0;
    if (c < a->m1C) {
        switch ((unsigned)k) {
        case 0:
            r = ((Unk80070004_Rec*)a->m24)[c].f0;
            break;
        case 1:
            r = ((Unk80070004_Rec*)a->m24)[c].f1;
            break;
        case 2:
            r = ((Unk80070004_Rec*)a->m24)[c].f2;
            break;
        case 3:
            r = ((Unk80070004_Rec*)a->m24)[c].f3;
            break;
        case 4:
            r = ((Unk80070004_Rec*)a->m24)[c].f4;
            break;
        case 5:
            r = ((Unk80070004_Rec*)a->m24)[c].f5;
            break;
        case 6:
            r = ((Unk80070004_Rec*)a->m24)[c].f6;
            break;
        case 7:
            r = ((Unk80070004_Rec*)a->m24)[c].f7;
            break;
        case 8:
            r = ((Unk80070004_Rec*)a->m24)[c].f8;
            break;
        case 9:
            r = ((Unk80070004_Rec*)a->m24)[c].f9;
            break;
        case 10:
            r = ((Unk80070004_Rec*)a->m24)[c].f10;
            break;
        case 11:
            r = ((Unk80070004_Rec*)a->m24)[c].f11;
            break;
        }
    }
    return r;
}

extern Unk8007FF8C_Pmf lbl_805B63E0[];

extern "C" float fn_800701B0(Unk8007FF8C_PObj* o, int i, int a)
{
    float r = (o->*lbl_805B63E0[i])(a);
    return r;
}


void fn_80070248(void* l, int k, unsigned c, int v)
{
    Unk80071604* a = (Unk80071604*)l;
    if (c < a->m1C) {
        switch ((unsigned)k) {
        case 0: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7F;
            }
            r->f0 = v;
            return;
        }
        case 1: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0xFF;
            }
            r->f1 = v;
            return;
        }
        case 2: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0xFF;
            }
            r->f2 = v;
            return;
        }
        case 3: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7F;
            }
            r->f3 = v;
            return;
        }
        case 4: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7F;
            }
            r->f4 = v;
            return;
        }
        case 5: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0xFF;
            }
            r->f5 = v;
            return;
        }
        case 6: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0xFF;
            }
            r->f6 = v;
            return;
        }
        case 7: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7F;
            }
            r->f7 = v;
            return;
        }
        case 8: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7F;
            }
            r->f8 = v;
            return;
        }
        case 9: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7F;
            }
            r->f9 = v;
            return;
        }
        case 10: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7F;
            }
            r->f10 = v;
            return;
        }
        case 11: {
            Unk80070004_Rec* r = (Unk80070004_Rec*)(c * 12 + (unsigned)a->m24);
            int t;
            if (v <= 0x3FF) {
                t = v;
                if (t < 0)
                    t = 0;
            } else {
                t = 0x3FF;
            }
            r->f11 = t;
            return;
        }
        }
    }
}

float fn_8007057C(void* self, int a)
{
    W* w = (W*)self;
    int s2 = w->v28(2, a);
    int s3 = w->v28(3, a);
    int s4 = w->v28(4, a);
    float r = (float)s2 + (float)s3 + (float)s4 + (float)w->v28(0, a);
    return r;
}

float fn_800706C0(void* self, int a)
{
    W* w = (W*)self;
    int p = w->v28(0xB, a);
    int s6 = w->v28(6, a);
    int sa = w->v28(0xA, a);
    int s8 = w->v28(8, a);
    float r = (float)p - (float)(s6 + sa + s8 + w->v28(9, a));
    if (!(r >= lbl_805B3B78))
        r = lbl_805B3B78;
    return r;
}

float fn_80070810(void* self, int a)
{
    float x = fn_8007057C(self, a);
    float y = fn_800706C0(self, a);
    float r = lbl_805B3B7C;
    if (!(y <= lbl_805B3B7C))
        r = x / y;
    return r;
}

float fn_80070880(void* self, int a)
{
    W* w = (W*)self;
    float x = fn_8007057C(self, a);
    float y = (float)w->v28(6, a);
    float z = (float)w->v28(0xA, a);
    float u = fn_800706C0(self, a);
    float v = (float)w->v28(8, a);
    float r = 0.0f;
    float den = u + y + z + v;
    if (!(den <= 0.0f)) {
        r = (x + y + z) / den;
        int n = (int)(r * 10000.0f);
        if (n % 10 > 4)
            n += 10;
        n = n / 10;
        r = (float)n * 0.001f;
    }
    return r;
}

float fn_80070A60(W* w, int a)
{
    float x = (float)w->v28(2, a);
    float y = (float)w->v28(3, a);
    float z = (float)w->v28(4, a);
    float v = (float)w->v28(0, a);
    float r = v * lbl_805B3BA4 + (z * lbl_805B3BA0 + (x + 2.0f * y));
    return r;
}

float fn_80070BC8(void* self, int a)
{
    W* w = (W*)self;
    float hi = fn_80070A60(w, a);
    float lo = fn_800706C0(self, a);
    float r = 0.0f;
    if (!(lo <= 0.0f)) {
        r = hi / lo;
        int n = (int)(r * 10000.0f);
        if (n % 10 > 4)
            n += 10;
        n = n / 10;
        r = (float)n * 0.001f;
    }
    return r;
}

float fn_80070CC4(void* self, int a)
{
    float r = fn_80070880(self, a) + fn_80070BC8(self, a);
    return r;
}

float fn_80070D18(W* w, int a)
{
    float x = (float)w->v28(6, a);
    float y = (float)w->v28(10, a);
    return x + y;
}
