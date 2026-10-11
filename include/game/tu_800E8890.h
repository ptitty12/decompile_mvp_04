#ifndef GAME_TU_800E8890_H
#define GAME_TU_800E8890_H

#include "game/tu_800EBF2C.h"

/*
 * Declarations for game/tu_800E8890.cpp (reconstructed; placeholders only).
 */

struct Unk800EAD5C_T {
    char m0[0x17C];
    int m17C;
};
struct Unk800EAD5C_C {
    char m0[0x2F0];
    void (*m2F0)();
};
void fn_800EAD5C(Unk800EAD5C_C* t);
UiS* fn_804D2310(char* p);

struct Ui80619948 {
    char pad0[0x74];
    int m74;
    char pad78[0x80 - 0x78];
    int m80;
    char pad84[0xA4 - 0x84];
    int mA4;
    char mA8[8];
};
extern Ui80619948* lbl_80619948;
struct UiP2 {
    int a;
    int b;
};
extern UiP2 lbl_805BC074;
extern UiP2 lbl_805BC06C;
extern char lbl_805BE0F0[];
extern char lbl_805BE100[];
extern char lbl_805BE110[];
extern char lbl_805B6F58[];
extern char lbl_80655BA8[];
extern char lbl_80654430[];
extern char lbl_805BA6D8[];
extern char lbl_805BE120[];
void fn_80546258(char* p);
void fn_800EA9F4(void* self);
void fn_80134CD0(UiS* x);
void fn_80132630(UiS* o, int a);
void fn_800EAD38(void* t, Unk800EAD5C_C* u);
void fn_800EAD8C(void* unused, UiS* x);
void fn_800EAAA4(void* unused, UiS* x);
void fn_804D1FD4(char* p);
void fn_804D21B8(char* p, UiP2* q);
void fn_800EC1E8(void* t);
void fn_800EB41C(UiS* self);
UiScrRaw* fn_800EB2F4(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80086EC0(char* p, int a, int b);
struct Unk80090880;
char* fn_80090880(Unk80090880* p, int id);
extern Unk80090880* lbl_8061977C;
void fn_801321D4(UiS* o, UiS* self, void (*cb)(void*, UiS*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
extern char lbl_805BAF60[];
extern char lbl_805BAF10[];
extern char lbl_805BAF40[];
struct Ui1E8 {
    char pad0[0x1E8];
    int m1E8;
};
Ui1E8* fn_8007FE04(void* p);
void fn_800A2F9C(Ui80619948* p, int a);
void fn_800C2110(char* dst, char* src);
extern int lbl_8061A48C;
void fn_800EAAEC();
void fn_800EAE04(int a, UiS* x);
int fn_800A3270(Ui80619948* g, int* a, int* b);
struct UiSub144 {
    char pad0[0x38];
    int m38;
};
int fn_800A3258(Ui80619948* g);
void fn_800C2034(char* a, int b);
void fn_8055EAFC(void* o);
extern char lbl_805BE110[];
const char* fn_800EAE8C(int a);
void* fn_8007F7D0(Unk8007B2B0_Screen* s, unsigned i);
extern char lbl_805BE138[];
int fn_800A3244(Ui80619948* g);
int fn_80077BC4(Unk8007B2B0_Screen* s, int a);
#endif
