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
