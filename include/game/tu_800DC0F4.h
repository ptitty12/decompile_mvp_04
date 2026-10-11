#ifndef GAME_TU_800DC0F4_H
#define GAME_TU_800DC0F4_H

#include "game/tu_800EBF2C.h"

/*
 * Declarations for game/tu_800DC0F4.cpp (reconstructed; placeholders only).
 */

extern int lbl_8061977C;
extern int lbl_8061E978;
extern int lbl_805C2EB4[];
extern int lbl_805C2E84[];
extern int lbl_805C2EE4[];
extern const unsigned char lbl_805B6F58;
extern const unsigned short lbl_805BDADC;
extern const unsigned short lbl_805BDAE0;
extern const unsigned short lbl_805BDAE4;
extern const unsigned short lbl_805BDAE8;
struct Unk800DE930_T {
    int m[6];
};
extern Unk800DE930_T lbl_805BD9BC;
struct Unk800DD610_P {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
};
struct Unk800DEDC0_Row {
    int m0;
    int m4;
};
extern Unk800DEDC0_Row lbl_805BD894[];

void* fn_80090880(int obj, int id);
int fn_8032A130(int a, int b, int c);
int fn_803EB434(int h, void* s, float* a, float* b, float* c, float* d);
void fn_800DC3D8(int* a, int* b, int c);
int fn_800DB9A8(int a, int b, int c, int d);

struct Unk800DB840_Slot {
    char m0[0xE64];
};
float fn_800DBA74(Unk800DB840_Slot* s, int a, int b, int c);
int fn_8007824C(int a, UiW* b);
void fn_800DF254(UiS* self, int a, int b, float f);
int fn_8008CFD8(char* p, int a, int b);
char* fn_804031BC(char* dst, const char* src);
int fn_800968C0(void* p, int b, int c);
int fn_8040321C(char* dst, char* fmt, char* a, const char* b);
extern char lbl_805BC188[];
extern char lbl_805BD8C0[];
extern float lbl_805BD8BC;
extern char lbl_805BDBA8[];
void* fn_800DE160(int x);
int fn_800DE930(int i);
int fn_800DE980(int i, int id);
int fn_80403DE4(char* dst, const char* fmt, ...);
extern char lbl_805BA46C[];
#endif
