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
UiS* fn_800DF254(UiS* self, int a, int b, float f);
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
void fn_80403DE4(char* dst, const char* fmt, ...);
extern char lbl_805BA46C[];
struct Udd344_T {
    unsigned char m0;
    unsigned char m1;
};
int fn_80403144(void* dst, const char* src);
int fn_800DBC50(Unk800DB840_Slot* o, int a, int idx, int b, int c);
int fn_800DBAE0(Unk800DB840_Slot* o, int a, int idx, int b);
const char* fn_800E5F38(int x);
void fn_800DE6A8(int a0, char* a, char* b, int fl, int v, char* c);
struct Unk8024EF40_W;
char* fn_802542E8(Unk8024EF40_W* sub, int a, int out);
int fn_8040B320(char* dst, int a, int n, ...);
char* fn_8040B61C(char* dst, const char* src);
void fn_8008D738(char* p, int a, unsigned r, char* out);
struct UdE274_T {
    char pad0[0x384];
    unsigned m384;
    char pad388[0x704 - 0x388];
    int m704;
};
struct UdE354_T {
    char pad0[0x14];
    char* m14;
};
extern char lbl_805BD90C[];
extern char lbl_805BD904[];
extern char lbl_805BD914[];
extern char lbl_805BD918[];
extern char lbl_805BD91C[];
extern char lbl_805BD920[];
extern char lbl_805BD924[];
extern char lbl_806E02B8[];
extern float lbl_805BD900;
void fn_800D4254(int a, int e, float* x, float* y);
int fn_800DD5E8(int i);
int fn_800DD5FC(int i);
int fn_800DD610(Unk800DD610_P* p);
char* fn_800DD6D4(int n);
extern float lbl_805BD8CC;
extern float lbl_805BD8D0;
#endif
