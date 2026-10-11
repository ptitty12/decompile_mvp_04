/*
 * Game code, .text 0x8033FAFC-0x803401A8 (debug-menu item and menu helpers;
 * original file and TU boundaries unknown, placeholder). Every data object is
 * extern by its lbl_ name.
 */
#include "game/tu_80331C60.h"

extern const char lbl_80666EC0[];
extern const char lbl_8064B298[];

struct UnkAt1C { char pad0[0x1C]; int m1C; };
struct UnkAt8V { char pad0[0x8]; const void* m8; };
struct UnkAt8V58V { char pad0[0x8]; const void* m8; char pad1[0x4C]; const void* m58; };
struct UnkNameBuf { char pad0[0x10]; char m10[0x30]; char* m40; int m44; };
struct UnkAtC { char pad0[0xC]; int mC; };
struct UnkAt48 { char pad0[0x48]; int m48; };
struct UnkAt4C { char pad0[0x4C]; int m4C; };
struct UnkAt4CT { char pad0[0x4C]; int m4C; char pad50[0x10]; int* m60; };

extern const char lbl_80666978[];
extern const char lbl_80666928[];
extern const char lbl_806668D8[];
extern const char lbl_805EC0D4[], lbl_805EC0E8[], lbl_805EC100[], lbl_805EC114[], lbl_805EC128[];
extern const char lbl_805EC134[], lbl_805EC148[], lbl_805EC15C[];
extern char lbl_80691CA4[], lbl_80620400[], lbl_805ECE54[];
extern float lbl_806203DC, lbl_806203E0, lbl_806203E4, lbl_806202A0;
extern float lbl_806203E8;
extern int lbl_806203F0, lbl_806203F4, lbl_806203F8;

struct UnkMenu174 { MItem* items[93]; int m174; int m178; char pad17C[0x80]; int m1FC; int m200; int m204; int m208; };
/* embedded item vptr resets in the dtors */
inline void SetVp(void* p, int off, const void* v) { *(const void**)((char*)p + off) = v; }

extern "C" {

void fn_8033FAFC(UnkAt1C* p, int v) { p->m1C = v; }

void fn_8033FB04() {}

void fn_8033FB08(UnkAt8V* p, int c) { p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

char* fn_8033FB3C(UnkNameBuf* p) { return p->m44 ? p->m40 : p->m10; }

void fn_8033FB58(UnkAtC* p) { p->mC = 1; }

void fn_8033FB64(UnkAtC* p) { p->mC = 0; }

void fn_8033FB70(UnkAt8V* p, int c) { p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

void fn_8033FBA4(UnkAt8V* p, int c) { p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

void fn_8033FBD8(UnkAt48* p, int v) { p->m48 = v; }

void fn_8033FBE0(UnkAt8V* p, int c) { p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

void fn_8033FC14(UnkAt8V* p, int c) { p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

void fn_8033FC48(UnkAt8V* p, int c) { p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

void fn_8033FC7C(UnkAt8V* p, int c) { p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

void fn_8033FCB0(UnkAt8V* p, int c) { p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

void fn_8033FCE4(UnkAt8V* p, int c) { p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

int fn_8033FD18(UnkAt4C* p) { return p->m4C; }

void fn_8033FD20(MItem* p, int idx) { fn_8032F574(p, idx); }

void fn_8033FD40(UnkAt8V* p, int c) { p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

int fn_8033FD74(UnkAt4CT* p) { return p->m60[p->m4C]; }

void fn_8033FD88(UnkAt8V58V* p, int c) { p->m58 = lbl_8064B298; p->m8 = lbl_80666EC0; if (c & 1) fn_80377408(p); }

void fn_8033FDC8(UnkMenu174* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_8033FE40() {}

float fn_8033FE44(Menu* p) { return p->m20C; }

void fn_8033FE4C(Menu* p, int c)
{
    p->m2DC = lbl_80666978;
    SetVp(p, 0xc5c, lbl_80666EC0);
    SetVp(p, 0xc08, lbl_80666EC0);
    SetVp(p, 0xbb4, lbl_80666EC0);
    SetVp(p, 0xb60, lbl_80666EC0);
    SetVp(p, 0xb0c, lbl_80666EC0);
    SetVp(p, 0xab8, lbl_80666EC0);
    SetVp(p, 0xa64, lbl_80666EC0);
    SetVp(p, 0xa10, lbl_80666EC0);
    SetVp(p, 0x9bc, lbl_80666EC0);
    SetVp(p, 0x968, lbl_80666EC0);
    SetVp(p, 0x914, lbl_80666EC0);
    SetVp(p, 0x8b0, lbl_80666EC0);
    SetVp(p, 0x85c, lbl_80666EC0);
    SetVp(p, 0x7f8, lbl_80666EC0);
    SetVp(p, 0x7a4, lbl_80666EC0);
    SetVp(p, 0x740, lbl_80666EC0);
    SetVp(p, 0x6ec, lbl_80666EC0);
    SetVp(p, 0x698, lbl_80666EC0);
    SetVp(p, 0x630, lbl_80666EC0);
    SetVp(p, 0x5e4, lbl_80666EC0);
    SetVp(p, 0x580, lbl_80666EC0);
    SetVp(p, 0x504, lbl_80666EC0);
    SetVp(p, 0x4a0, lbl_80666EC0);
    SetVp(p, 0x44c, lbl_80666EC0);
    SetVp(p, 0x404, lbl_80666EC0);
    SetVp(p, 0x3b0, lbl_80666EC0);
    SetVp(p, 0x34c, lbl_80666EC0);
    SetVp(p, 0x2E8, lbl_80666EC0);
    fn_80330870(p, c);
}

void fn_8033FEF4(Menu* p, int c)
{
    p->m2DC = lbl_80666928;
    SetVp(p, 0x614, lbl_80666EC0);
    SetVp(p, 0x5ac, lbl_80666EC0);
    SetVp(p, 0x544, lbl_80666EC0);
    SetVp(p, 0x4dc, lbl_80666EC0);
    SetVp(p, 0x474, lbl_80666EC0);
    SetVp(p, 0x40c, lbl_80666EC0);
    SetVp(p, 0x3a4, lbl_80666EC0);
    SetVp(p, 0x33c, lbl_80666EC0);
    SetVp(p, 0x2E8, lbl_80666EC0);
    fn_80330870(p, c);
}

void fn_8033FF50(Menu* p, int c) { p->m2DC = lbl_806668D8; fn_80330778(p, c); }

void fn_8033FF80(Menu* p)
{
    fn_80330ACC(p, fn_8032FA3C(operator new(0x64, 0), lbl_805EC0D4, lbl_80691CA4, lbl_80620400, lbl_805ECE54, 3, 0));
    fn_80330ACC(p, fn_8032E7C0(operator new(0x64, 0), lbl_805EC0E8, &lbl_806203DC, &lbl_806203E8, 0.0f, 0.0f, 180.0f));
    fn_80330ACC(p, fn_8032E7C0(operator new(0x64, 0), lbl_805EC100, &lbl_806203E0, &lbl_806203E8, 0.0f, 0.0f, 180.0f));
    fn_80330ACC(p, fn_8032E7C0(operator new(0x64, 0), lbl_805EC114, &lbl_806203E4, &lbl_806203E8, 0.0f, 0.0f, 150.0f));
    fn_80330ACC(p, fn_8032E7C0(operator new(0x64, 0), lbl_805EC128, &lbl_806203E8, &lbl_806202A0, 1.0f, 0.0f, 10.0f));
    fn_80330ACC(p, fn_8032EB84(operator new(0x68, 0), lbl_805EC134, &lbl_806203F0, 1, 1, 1, 10));
    fn_80330ACC(p, fn_8032EB84(operator new(0x68, 0), lbl_805EC148, &lbl_806203F4, 1, 1, 1, 10));
    fn_80330ACC(p, fn_8032EB84(operator new(0x68, 0), lbl_805EC15C, &lbl_806203F8, 1, 1, 1, 10));
}

}
