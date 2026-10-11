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
    char pad0[0x28];
    int m28;
    char pad2C[0x74 - 0x2C];
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
int fn_800A31FC(Ui80619948* g);
struct Ue6888 {
    UiS* p0;
    UiS* p4;
    char pad8[8];
    int m10;
};
void fn_800E6888(Ue6888* t);
struct Ue8A6C : public Ue6888 {
    char pad14[0xEC - 0x14];
    int mEC[2];
    int mF4;
};
struct UiQuad {
    int m[4];
};
extern UiQuad lbl_805BE0E0;
void fn_800E6708(Ue8A6C* m);
void fn_800E694C(Ue8A6C* m, int k);
void fn_800E71E0(Ue8A6C* m, int k);
void fn_800E7598(Ue8A6C* m, int k);
void fn_800E7888(Ue8A6C* m, int k);
void fn_800E7AD8(Ue8A6C* m, int k);
void fn_800E7E48(Ue8A6C* m, int k);
void fn_800E8890(Ue8A6C* m, int k, int a, int b);
void fn_800E5100(unsigned short* out, int arg1);
int fn_800A324C(Ui80619948* g);
int fn_800A3264(Ui80619948* g);
extern "C" void fn_800DE440(int a0, int a1, int a2);
int fn_80403DE4(char* dst, const char* fmt, ...);
void fn_800E98D8(int a, UiS* x);
extern char lbl_805BA7A8[];
unsigned fn_80599C40(char* g, int j);
int fn_80599C50(char* g, int j, unsigned char k);
int fn_80599C80(char* g, int j);
void fn_80523824(UiS* t, int a0, int b, void (*cb)(int, UiS*), int w0, int w1, unsigned m);
void fn_80523C94(UiS* t, int e, int flag, unsigned char k, int w);
void fn_800EA91C(int a, UiS* x);
struct UdE354_T {
    char pad0[0x14];
    char* m14;
};
struct Ue8890 {
    UiS* p0;
    char pad4[4];
    UdE354_T* m8;
    char padC[4];
    int m10;
};
void fn_800DE354(int a0, UdE354_T* o, int idx, int b, int fl);
int fn_80097EA4(char* p, int a, unsigned char b, int c, int d);
int fn_80403060(const char* s);
void fn_80403144(char* dst, const char* src);
void fn_800DFEAC(char* dst, const char* name);
void fn_800DFF0C(char* dst, const char* s);
extern char lbl_805BE020[];
extern char lbl_805BE024[];
extern char lbl_805BE02C[];
int fn_804089B4(char* dst, const char* fmt, ...);
int fn_800A2AE8(Ui80619948* g);
int fn_800A2E6C(Ui80619948* g);
int fn_8056B7D0(int a);
int fn_800E6058(int x);
void fn_800E9248(int a, UiS* x);
#endif
