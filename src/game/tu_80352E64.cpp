/*
 * Game code, .text 0x80352E64-0x80353930 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8034B370.h"

struct DtorAt0 { const void* m; };
extern char lbl_80649E88[];
extern char lbl_8064B718[];
extern char lbl_8064A638[];
struct DtorAt1C { char pad[0x1c]; const void* m; };
extern char lbl_8064A620[];
struct DtorAt8 { char pad[0x8]; const void* m; };
extern char lbl_8064A608[];
struct DtorAt24 { char pad[0x24]; const void* m; };
extern char lbl_8064A5F0[];
struct DtorAt18 { char pad[0x18]; const void* m; };
extern char lbl_8064A550[];
struct DtorAt10 { char pad[0x10]; const void* m; };
extern char lbl_8064B218[];
extern char lbl_80649DA0[];
struct DtorAt4 { char pad[0x4]; const void* m; };

void fn_80352E64(void)
{
}

void fn_80352E68(void)
{
}

void fn_80352F34(DtorAt0* s, int chrg);
void fn_80352E6C(DtorAt0* s, int chrg)
{
    fn_80352F34(s, chrg);
}

void fn_80352F94(DtorAt0* s, int chrg);
void fn_80352E8C(DtorAt0* s, int chrg)
{
    fn_80352F94(s, chrg);
}

void fn_80352EAC(DtorAt0* self, int chrg)
{
    self->m = lbl_80649E88;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80352EE0(void)
{
}

void fn_80352EE4(void)
{
}

void fn_80352EE8(void)
{
}

void fn_80352EEC(DtorAt0* self, int chrg)
{
    self->m = lbl_80649E88;
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80352F20_A {
    int pad0;
    int m4;
    int m8;
};
struct Unk80352F20_B {
    char pad0[0x44];
    int m44;
    int m48;
};
void fn_80352F20(Unk80352F20_A* a, Unk80352F20_B* b)
{
    a->m8 = b->m48;
    a->m4 = b->m44;
}

void fn_80352F34(DtorAt0* self, int chrg)
{
    self->m = lbl_80649E88;
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80352F68_B {
    char pad0[0x40];
    int m40;
};
void fn_80352F68(Unk8034151C* a, Unk80352F68_B* b)
{
    if (b->m40 != 0)
        fn_80341598(a, b->m40);
}

void fn_80352F94(DtorAt0* self, int chrg)
{
    self->m = lbl_80649E88;
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80352FC8_B {
    char pad0[0x3C];
    int m3C;
};
void fn_80352FC8(Unk803415F0* a, Unk80352FC8_B* b)
{
    if (b->m3C != 0)
        fn_8034166C(a, b->m3C);
}

void fn_80352FF4(Unk803415F0* t)
{
    t->mFE = 0;
}

void fn_80353000(Unk8034151C* t)
{
    t->m9A = 0;
}

void fn_80353214(void)
{
}

struct Unk80353218 {
    int m0;
    const void* m4;
};
Unk80353218* fn_80353218(Unk80353218* s)
{
    s->m0 = 0;
    s->m4 = lbl_8064B718;
    return s;
}

int fn_80353234(Unk80353234* s)
{
    return s->m0[s->mC];
}

int fn_80353244(Unk80353E68* s)
{
    return s->mC;
}

void fn_8035324C(DtorAt1C* self, int chrg)
{
    self->m = lbl_8064A638;
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk80353280_ED { char pad[0x1c]; };
struct Unk80353280_E : Unk80353280_ED { virtual ~Unk80353280_E(); };
struct Unk80353280 {
    int m0;
    Unk80353280_E m4[16];
    ~Unk80353280();
};
Unk80353280::~Unk80353280()
{
}

void fn_803532F8(DtorAt8* self, int chrg)
{
    self->m = lbl_8064A620;
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk8035332C {
    short m0;
    int m4;
};
void fn_8035332C(Unk8035332C* s)
{
    s->m0 = 0;
    s->m4 = 0;
}

void fn_80353340(DtorAt24* self, int chrg)
{
    self->m = lbl_8064A608;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80353374(DtorAt18* self, int chrg)
{
    self->m = lbl_8064A5F0;
    if (chrg & 1)
        fn_80377408(self);
}

struct Unk803533A8_AD { char pad[0x24]; };
struct Unk803533A8_A : Unk803533A8_AD { virtual ~Unk803533A8_A(); };
struct Unk803533A8_BD { char pad[8]; };
struct Unk803533A8_B : Unk803533A8_BD { virtual ~Unk803533A8_B(); };
struct Unk803533A8_Mid {
    char pad0[0x80];
    Unk803533A8_A m80[6];
    Unk803533A8_B m170[4];
    char pad1[0x6ec - 0x1a0];
    ~Unk803533A8_Mid() {}
};
struct Unk803533A8 {
    char pad0[0x18];
    Unk803533A8_Mid m18[4];
    ~Unk803533A8();
};
Unk803533A8::~Unk803533A8()
{
}

struct Unk80353478_ED { char pad[0x14]; };
struct Unk80353478_E : Unk80353478_ED { virtual ~Unk80353478_E(); };
struct Unk80353478 {
    int m0;
    Unk80353478_E m4[32];
    ~Unk80353478();
};
Unk80353478::~Unk80353478()
{
}

struct Unk803534F0_ED { char pad[0x1c]; };
struct Unk803534F0_E : Unk803534F0_ED { virtual ~Unk803534F0_E(); };
struct Unk803534F0 {
    Unk803534F0_E m0[25];
    ~Unk803534F0();
};
Unk803534F0::~Unk803534F0()
{
}

void fn_80353564(DtorAt10* self, int chrg)
{
    self->m = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80353598(DtorAt10* self, int chrg)
{
    self->m = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_803535CC(DtorAt10* self, int chrg)
{
    self->m = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80353600(DtorAt10* self, int chrg)
{
    self->m = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80353634(DtorAt10* self, int chrg)
{
    self->m = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80353668(DtorAt10* self, int chrg)
{
    self->m = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(self);
}

int fn_8035369C(Unk80353E68* s)
{
    return s->m0[s->mC];
}

void fn_803536B0(Unk803536B0* s)
{
    s->m0 = 4;
    s->m4.Clear();
    for (int i = 0; i < 10; i++)
        s->m18[i] = 0xff;
    s->m24 = 0;
}

void fn_8009619C(void* p);
void fn_803536B0(Unk803536B0* s);
Unk803536B0* fn_803537FC(Unk803536B0* s)
{
    s->m4.Init(s->m28, 9, lbl_8064B218);
    fn_803536B0(s);
    fn_8009619C(s->m34);
    return s;
}

struct Unk80353870 {
    char pad0[0x168];
    Unk80353234 m168;
};
int fn_80353870(Unk80353870* s)
{
    return s->m168.m0[s->m168.mC];
}

void fn_80353880(Unk80353E68* s)
{
    s->mC = (s->mC + 1) % s->m4;
}

struct Unk803538A0 {
    Unk80353234 m0;
    int m10;
    unsigned char m14[2];
};
void fn_803538A0(Unk803538A0* s)
{
    s->m0.Clear();
    for (int i = 0; i < 2; i++)
        s->m14[i] = 0;
}

void fn_803538FC(DtorAt4* self, int chrg)
{
    self->m = lbl_80649DA0;
    if (chrg & 1)
        fn_80377408(self);
}
