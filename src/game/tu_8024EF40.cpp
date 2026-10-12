/*
 * Game code, .text 0x8024EF40-0x802520F8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_W W;

extern "C++" {
extern char lbl_805D990C[];
int fn_80250AC4(P* x);
int fn_80250A90(P* x, int k);
float fn_80251000(P* x, int k);
void* fn_8023CB44(P* x);
void fn_80250B28(P* x, int k);
extern float lbl_8061DC08;
extern int lbl_80691CAC;
extern float lbl_8061DC0C;
extern int lbl_80691CB0;
extern float lbl_8061DC10;
extern int lbl_80691CB4;
extern float lbl_8061DC14;
extern int lbl_80691CB8;
extern float lbl_8061DC18;
extern int lbl_80691CBC;
extern float lbl_8061DC1C;
extern int lbl_80691CC0;
extern float lbl_8061DC2C;
extern int lbl_80691CE0;
extern float lbl_8061DC3C;
extern int lbl_80691CF0;
extern int lbl_8061DC54;
inline float G_8061DC08(void* p) { return lbl_8061DC08; }
inline float G_8061DC0C(void* p) { return lbl_8061DC0C; }
inline float G_8061DC10(void* p) { return lbl_8061DC10; }
inline float G_8061DC14(void* p) { return lbl_8061DC14; }
inline float G_8061DC18(void* p) { return lbl_8061DC18; }
inline float G_8061DC1C(void* p) { return lbl_8061DC1C; }
inline float G_8061DC2C(void* p) { return lbl_8061DC2C; }
inline float G_8061DC3C(void* p) { return lbl_8061DC3C; }
extern int lbl_8061D51C[];
extern int lbl_8061D4DC[];
extern char lbl_8068CD00[];
extern char lbl_80660F50[];
extern char lbl_80660F38[];
extern char lbl_80660F20[];
extern char lbl_80660F08[];
void fn_8033CD74(void* p);
int fn_8017EEB0(void* p, int a, int b);
struct Unk8024F6F4_C {
    const void* m0;
    Unk8024F6F4_C();
};
struct Unk8024F708_C {
    const void* m0;
    Unk8024F708_C();
};
struct Unk8024F71C_C {
    const void* m0;
    Unk8024F71C_C();
};
struct Unk8024F730_C {
    const void* m0;
    Unk8024F730_C();
};
struct Unk8024FD00_S {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
struct Unk80250244_S {
    int m0;
    int m4;
    Unk8024FD00_S m8[4];
    char pad58[4];
    float m5C;
    float m60;
    float m64;
    float m68;
    float m6C;
    int m70;
    float m74;
    int m78;
    int m7C;
    float m80;
    int m84;
    int m88;
    float m8C;
    char pad90[4];
    int m94;
    int m98;
    int m9C;
    float mA0;
    P* mA4;
};
float fn_8025454C(void* p, int idx);
int fn_801BA4AC(int a);
void fn_8024FD00(Unk8024FD00_S* self);
}

int fn_8024F59C(int x)
{
    if (x <= 15) {
        if (x < 0)
            x = 0;
    } else {
        x = 15;
    }
    return lbl_8061D51C[x];
}

int fn_8024F5CC(int x)
{
    if (x <= 15) {
        if (x < 0)
            x = 0;
    } else {
        x = 15;
    }
    return lbl_8061D4DC[x];
}

extern "C" void* fn_8024F5FC(void* p);

extern int lbl_806EF9B4;

extern "C" void* fn_8024F69C()
{
    return fn_8024F5FC(operator new(0x4, lbl_806EF9B4));
}


void fn_8024F6CC()
{
    fn_8033CD74(lbl_8068CD00);
}

Unk8024F6F4_C::Unk8024F6F4_C()
{
    m0 = lbl_80660F50;
}

Unk8024F708_C::Unk8024F708_C()
{
    m0 = lbl_80660F38;
}

Unk8024F71C_C::Unk8024F71C_C()
{
    m0 = lbl_80660F20;
}

Unk8024F730_C::Unk8024F730_C()
{
    m0 = lbl_80660F08;
}

void fn_8024F7C8(Unk80250244_S* self)
{
    self->m4 = 0;
    for (int i = 0; i < 4; i++)
        fn_8024FD00(&self->m8[i]);
}

void fn_8024FC74(Unk80250244_S* self)
{
    fn_8024F7C8(self);
}

void fn_8024FCF8(void** self, void* a)
{
    *self = a;
}

void fn_8024FD00(Unk8024FD00_S* self)
{
    self->m4 = 0;
    self->m8 = 0;
    self->mC = -1;
    self->m10 = -1;
}

void fn_8024FD1C(Unk8024FD00_S* self, int a, int b)
{
    if (b <= 2) {
        self->mC = b;
        self->m8 = a;
        self->m4 = 1;
    }
}

void fn_8024FE3C(Unk8024FD00_S* self, int a)
{
    self->m10 = a;
    self->m4 = 2;
}

void fn_8024FF48(Unk80250244_S* self)
{
    self->m5C = fn_8025454C(&self->mA4->m588, 0xF);
    self->m60 = fn_8025454C(&self->mA4->m588, 0xE);
    self->m68 = fn_8025454C(&self->mA4->m588, 0x10);
    self->m6C = fn_8025454C(&self->mA4->m588, 0x11);
}

void fn_80250180(Unk80250244_S* self, int a)
{
    const float k = 0.2f;
    self->m80 = Secs(self->mA4->m44C) + k;
    self->m84 = a;
    self->m88 = 0;
}

void fn_802501E0(Unk80250244_S* self)
{
    const float k = 0.5f;
    self->m80 = Secs(self->mA4->m44C) + k;
    self->m88 = 1;
    self->m84 = -1;
}

void fn_80250244(Unk80250244_S* self)
{
    self->m84 = -1;
    self->m88 = 0;
    self->m80 = 0.0f;
}

void fn_8025068C(Unk80250244_S* self, int a)
{
    if (a != self->m9C) {
        self->m9C = a;
        self->mA0 = Secs(self->mA4->m44C);
    }
}

void fn_802506E4(Unk80250244_S* self)
{
    P* p = self->mA4;
    self->m98 = 1;
    if (p != 0)
        fn_801BA4AC(p->m44C->m700->m3BC);
}

int fn_80250A90(P* self, int a)
{
    return fn_8017EEB0((char*)self->m44C->m700 + 0x228, *(int*)((char*)self + 0x704), a);
}

void fn_80251124(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 0) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x433);
        float t = fn_80251000(x, 0x29) * G_8061DC08(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CAC != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 0);
    }
}

void fn_8025124C(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 1) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x445);
        float t = fn_80251000(x, 0x29) * G_8061DC0C(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CB0 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 1);
    }
}

void fn_8025147C(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 2) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x468);
        float t = fn_80251000(x, 0x29) * G_8061DC10(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CB4 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 2);
    }
}

void fn_802515A4(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 3) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x47B);
        float t = fn_80251000(x, 0x2C) * G_8061DC14(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CB8 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 3);
    }
}

void fn_802516CC(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 4) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x48D);
        float t = fn_80251000(x, 0x2A) * G_8061DC18(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CBC != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 4);
    }
}

void fn_802517F4(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 5) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x49F);
        float t = fn_80251000(x, 0x2A) * G_8061DC1C(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CC0 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 5);
    }
}

void fn_80251D58(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 0xD) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x52F);
        float t = fn_80251000(x, 0x2C) * G_8061DC2C(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CE0 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 0xD);
    }
}

void fn_80251FD0(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 0x11) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x57F);
        float t = fn_80251000(x, 0x2C) * G_8061DC3C(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CF0 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 0x11);
    }
}
