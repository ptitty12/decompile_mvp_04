/*
 * Game code, .text 0x8035B60C-0x8035BF0C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8035B60C.h"
#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))
#define PUTI(o, v) (*(int*)((char*)self + (o)) = (v))
#define PUTB(o, v) (*(unsigned char*)((char*)self + (o)) = (v))
#define PUTF(o, v) (*(float*)((char*)self + (o)) = (v))
#define CPUT(o, v) (*(const void**)((char*)this + (o)) = (v))
#define CPUTI(o, v) (*(int*)((char*)this + (o)) = (v))
#define CPUTB(o, v) (*(unsigned char*)((char*)this + (o)) = (v))
#define CPUTF(o, v) (*(float*)((char*)this + (o)) = (v))
#define GETI(o) (*(int*)((char*)self + (o)))
struct U {
    char pad0[0x4000];
};
void fn_80377408(void* p);
extern char lbl_80649DA0[];
extern char lbl_806608E0[];
extern char lbl_80660910[];
extern char lbl_80660928[];
extern char lbl_80660958[];
extern char lbl_80660970[];
extern char lbl_80660988[];
extern char lbl_806609A0[];
extern char lbl_806609B8[];
extern char lbl_806609D0[];
extern char lbl_806609E8[];
extern char lbl_80660A00[];
extern char lbl_80660A30[];
extern char lbl_80660A48[];
extern char lbl_80660A90[];
extern const float lbl_805D6740;
extern const float lbl_805D6744;
extern const float lbl_805D6748;
extern const float lbl_805D674C;
extern const float lbl_805D6750;
extern const float lbl_805D6754;
void fn_80211B58(void* p, int chrg);
extern char lbl_806608F8[];
extern char lbl_80660940[];
extern char lbl_80660A18[];
extern char lbl_80660AA8[];
void fn_8035D710(void* p);
void fn_8020DF6C(void* p);
void fn_80211C04(void* p);
void fn_8035D85C(void* p);
void fn_8035B940(U* self, int v);
extern float lbl_805D6758;
struct Unk8035B718_Sub {
    char pad0[0xAC];
    Unk8035B718_Sub() { fn_8035D710(this); }
};
struct Unk8035B718 {
    Unk8035B718_Sub m0[9];
    Unk8035B718();
};
struct Unk8035BE7C_Sub {
    int m0;
    float m4;
    float m8;
    int mC;
    int m10;
};
struct Unk8035BE7C {
    Unk8035BE7C_Sub m0[4];
    int m50;
    Unk8035BE7C();
    void fn_8035BED0(int v);
};
struct Unk8035BA50 {
    int m0;
    int m4;
    float m8;
    float mC;
    float m10;
    const void* m14;
    Unk8035BA50(const Unk8035BA50& o);
};
struct Unk8035BBEC_W {
    int m0;
    const void* m4;
    ~Unk8035BBEC_W() { m4 = lbl_80660A30; }
};
struct Unk8035BBEC {
    char pad0[0x1C];
    VElem34 m1C[4];
    VElem1C mEC[4];
    VElem14 m15C[4];
    VElem40 m1AC[4];
    Unk8035BBEC_W m2AC;
    VElem2C m2B4[4];
    const void* m364;
    ~Unk8035BBEC();
};
struct Unk8035BDF8 {
    VElem14 m0[4];
    char pad50[4];
    const void* m54;
    ~Unk8035BDF8();
};

void fn_8035B60C(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B640(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B674(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B6A8(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B6DC(U* self, int chrg)
{
    PUT(0x4, lbl_80649DA0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B710(U* self, int v) { PUTI(0x7c, v); }

Unk8035B718::Unk8035B718() {}

void fn_8035B764(U* self, int chrg)
{
    PUT(0x14, lbl_80660AA8);
    fn_8020DF6C(self);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B7B0(U* self)
{
    PUTI(0x0, -1);
    PUTF(0x4, lbl_805D6740);
    PUTF(0x8, lbl_805D6744);
}

void fn_8035B7D4(U* self)
{
    PUTI(0x0, -1);
    PUTF(0x4, lbl_805D6748);
    PUTF(0x8, lbl_805D674C);
}

void fn_8035B7F8(U* self, int chrg)
{
    PUT(0x8, lbl_80660A90);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B82C(U* self, int chrg)
{
    PUT(0x8, lbl_80660A90);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B860(U* self, int chrg)
{
    PUT(0x8, lbl_80660A90);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B894(U* self, int chrg)
{
    PUT(0x10, lbl_80660A48);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B8C8(U* self, int chrg)
{
    fn_80211B58(self, chrg);
}

void fn_8035B8E8(U* self, int chrg)
{
    PUT(0x4, lbl_80660A30);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B91C(U* self)
{
    fn_8035B940(self, -1);
}

void fn_8035B940(U* self, int v) { PUTI(0x0, v); }

void fn_8035B948(U* self, int chrg)
{
    PUT(0xCC, lbl_80660A18);
    PUT(0xC8, lbl_80660A30);
    if (chrg & 1)
        fn_80377408(self);
}

U* fn_8035B988(U* self)
{
    fn_80211C04(self);
    fn_8035D85C(self);
    return self;
}

void fn_8035B9C0(U* self, int chrg)
{
    PUT(0x10, lbl_80660A00);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035B9F4(U* self)
{
    PUTI(0x8, -1);
    PUTI(0xc, -1);
    PUTI(0x0, -1);
    PUTI(0x4, -1);
}

void fn_8035BA0C(U* self, int chrg)
{
    PUT(0x8, lbl_806609E8);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035BA40(U* self)
{
    PUTI(0x4, -1);
    PUTI(0x0, -1);
}

Unk8035BA50::Unk8035BA50(const Unk8035BA50& o)
{
    m14 = (const void*)lbl_806609D0;
    m0 = o.m0;
    m4 = o.m4;
    m8 = o.m8;
    mC = o.mC;
    m10 = o.m10;
}

void fn_8035BA8C(U* self, int chrg)
{
    PUT(0x14, lbl_806609D0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035BAC0(U* self)
{
    PUTI(0x0, -1);
    PUTI(0x4, 0);
    PUTF(0x8, lbl_805D6750);
    PUTF(0xc, lbl_805D6750);
    PUTF(0x10, lbl_805D6750);
}

void fn_8035BAE8(U* self, int chrg)
{
    PUT(0x28, lbl_806609B8);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035BB1C(U* self, int chrg)
{
    PUT(0x30, lbl_806609A0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035BB50(U* self, int chrg)
{
    PUT(0x18, lbl_80660988);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035BB84(U* self, int chrg)
{
    PUT(0x10, lbl_80660970);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035BBB8(U* self, int chrg)
{
    PUT(0x3c, lbl_80660958);
    if (chrg & 1)
        fn_80377408(self);
}

Unk8035BBEC::~Unk8035BBEC()
{
    m364 = lbl_80660940;
}

void fn_8035BD70(U* self, int chrg)
{
    PUT(0xc, lbl_80660928);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035BDA4(U* self, int chrg)
{
    PUT(0x10, lbl_80660910);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035BDD8(U* self)
{
    PUTI(0x0, 0);
    PUTI(0xc, 0);
    PUTF(0x4, lbl_805D6754);
    PUTF(0x8, lbl_805D6754);
}

Unk8035BDF8::~Unk8035BDF8()
{
    m54 = lbl_806608F8;
}

/* near-miss: 6 slots; retail stores m0 before loading lbl_805D6758 and keeps the float load after it (lis, li, stw, lfs); the 24 statement orders and const/non-const extern float both schedule lfs first. */
void fn_8035BE7C(Unk8035BE7C* self)
{
    Unk8035BE7C_Sub* p = self->m0;
    for (int i = 0; i < 4; i++) {
        p->m0 = 0;
        p->mC = 0;
        p->m4 = lbl_805D6758;
        p->m8 = lbl_805D6758;
        p++;
    }
    self->fn_8035BED0(0);
}

void Unk8035BE7C::fn_8035BED0(int v)
{
    m50 = v;
}

void fn_8035BED8(U* self, int chrg)
{
    PUT(0x1c, lbl_806608E0);
    if (chrg & 1)
        fn_80377408(self);
}
