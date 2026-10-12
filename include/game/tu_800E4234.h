#ifndef GAME_TU_800E4234_H
#define GAME_TU_800E4234_H

#define GAME_LBL_8061930C_INT
#include "game/tu_800EBF2C.h"

/*
 * Declarations for game/tu_800E4234.cpp (reconstructed; placeholders only).
 */

extern int lbl_8061930C;
struct Unk800E49A4_S {
    char m0[0x510];
    int m510;
    int m514;
    int m518;
    int m51C;
};
struct Unk800E60E0_T {
    int m[3];
};
extern Unk800E60E0_T lbl_805BDFC8;
struct Unk800E6470_O {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    char m14[0xC8];
    int mDC;
    int mE0;
    int mE4;
    int mE8;
    int mEC;
    int mF0;
    int mF4;
};

int fn_8007DA28(int o);
void fn_800E6158();
void fn_800E6258(int a, int b);
int fn_800E62C4(int a, int b);
int fn_800E4504(int a);
void fn_800E6318(int a);
int fn_8007D3D4(int o, int a, int b);
void fn_80377408(void* p);

extern float lbl_805C3C70[];
float fn_805520E4(int a, int b, int c, int d, int e);
struct Ue12 {
    char pad0[0x12];
    unsigned short m12;
};
int fn_80080070(int s);
Ue12* fn_8008007C(int s, unsigned i);
int fn_800E46FC(void* a, Ue12* e);
int fn_80591A50(int* p);
int fn_80592E04(int* p, int i);
int fn_8059394C(int* p, int i);
int fn_8007B7A4(Unk8007B2B0_Screen* s, void* o);
int fn_8007B7EC(Unk8007B2B0_Screen* s, void* o, int i);
void* fn_8007F7D0(int s, unsigned i);
void fn_800DC580(void* w, float f);
extern char lbl_805BC180[];
extern unsigned char lbl_8060E9F1[];
extern char lbl_805BDE14[];
int fn_804089B4(char* dst, const char* fmt, ...);
void fn_800A1F24(void* g, int a, int b, int c);
int fn_8040B6A0(const char* s);
struct Ue63A4 {
    char pad0[0xC];
    int mC;
    int m10;
    int m14;
    int m18;
    char pad1C[0x148 - 0x1C];
    int m148;
    int m14C;
    char pad150[0x184 - 0x150];
    int m184;
    int m188;
};
struct Ue6888 {
    UiS* p0;
    UiS* p4;
    char pad8[8];
    int m10;
};
extern char lbl_805BDEC8[];
extern char lbl_805B6F58[];
extern char lbl_805BDECC[];
extern char lbl_805BDED0[];
extern char lbl_805BDED4[];
extern char lbl_805BDED8[];
extern char lbl_805BA658[];
extern char lbl_805BA6A4[];
extern char lbl_805BDEDC[];
extern char lbl_805BDEE0[];
extern char lbl_805BDEE4[];
struct Ui80619948;
extern Ui80619948* lbl_80619948;
extern char lbl_805BDEE8[];
extern char lbl_805BDEEC[];
extern char lbl_805BDEF0[];
extern char lbl_805BDEF4[];
extern char lbl_805BDEF8[];
void fn_80075A44(Unk8007B2B0_Screen* s, int h, int i);
int fn_800B5758(Ui800B555C* p);
int fn_8008FE14(int id);
extern char lbl_805BDC74[];
int fn_800B56C4(Ui800B555C* p);
char* fn_800DF254(char* dst, int a, int b, float f);
struct Ue1E0 {
    char pad0[0x1DC];
    int m1DC;
    int m1E0;
};
Ue1E0* fn_8007FE04(Unk8007B2B0_Screen* s);
int fn_8007B7C8(Unk8007B2B0_Screen* s, void* o, int i);
int fn_8007B834(Unk8007B2B0_Screen* s, void* o, int i);
int fn_8007B858(Unk8007B2B0_Screen* s, void* o, int i);
struct Ue6058_T {
    int m[50];
};
extern Ue6058_T lbl_805BDF00;
float fn_80551A80(int a, int b);
extern int lbl_8061977C;
unsigned short* fn_80090880(int obj, int id);
int fn_80403DE4(char* dst, const char* fmt, ...);
char* fn_804031BC(char* dst, const char* src);
int fn_8040321C(unsigned short* dst, unsigned short* fmt, char* a, char* b);
int fn_804031F8(unsigned short* dst, unsigned short* fmt, char* a);
int fn_80083F6C(int a);
extern char lbl_805BC1A8[];
int fn_80403144(unsigned short* dst, const unsigned short* src);
void fn_800DFF0C(unsigned short* dst, unsigned short* s);
void fn_800DE440(char* buf, int a, int b);
unsigned fn_80599C40(int a, int b);
int fn_80599C50(int a, int b, unsigned char c);
int fn_80077BC4(Unk8007B2B0_Screen* s, int a);
#endif
