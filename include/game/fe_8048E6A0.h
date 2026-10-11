/*
 * Shared types for the front-end overlay units fe/tu_8048E6A0 .. fe/tu_804ABCBC
 * (0x8048E6A0..0x804ABCBC; reconstructed, placeholder names, nothing here comes
 * from original headers). Builds on the widget-world header fe_80459228.h: screens
 * are Unk800C7B40_Widget-derived (vptr at +0x3C), methods are written as extern "C"
 * functions taking the screen explicitly. Add new screen structs below; evidence
 * (offsets, users) goes in a comment above each one.
 */
#ifndef GAME_FE_8048E6A0_H
#define GAME_FE_8048E6A0_H

#include "game/fe_80459228.h"


/* The widget stored at byte offset `off` of a screen. */
static inline FeW* FeMem(void* x, int off)
{
    return *(FeW**)((char*)x + off);
}

/* Raw field access by byte offset (placeholder for named fields of the screens). */
#define FeI(x, off) (*(int*)((char*)(x) + (off)))
#define FeP(x, off) (*(void**)((char*)(x) + (off)))

/* Callees and helpers shared by the units in this range (types refined as functions match). */
struct FeStateX {
    char pad0[0x650];
    int m650;
};
void fn_8001C168();
struct FeStateY {
    char pad0[0x28];
    int m28;
    int m2C;
};
extern const char lbl_80674DC8[];
extern const char lbl_80674B20[];
extern const char lbl_805F763C[];
extern const char lbl_805F7648[];
int fn_80083FC0(int a);

/* Screen of fn_8048E6A0..fn_8048E8EC: m148/m14C/m150/m154 are lazily created art widgets
 * (fn_8048E6A0 for 148/14C "OWNERART"/"DYNASTYART", fn_8048E7E4 for 150/154 "OWNERTOP"). */
struct FeScrO : FeW {
    char pad40[0x108];
    int m148;
    int m14C;
    int m150;
    int m154;
};
extern "C" {
int fn_8007B320__18Unk8007B2B0_Screenii(void* g, int a, int b);
void fn_8048E6A0(FeScrO* x);
void fn_8048E7E4(FeScrO* x);
void fn_804930F8(void* x);
void fn_80492FB4(void* x);
void fn_804920B8(void* x, int a);
void fn_8049A4DC(void* x);
void fn_804A7874(void* x, int a);
void fn_80495248(void* x);
void fn_8049535C(void* x);
void fn_80377488(void* p);
void fn_8049E830(void* x, int a);
void fn_800ECDCC(void* x, int a);
void fn_804A763C(void* x, int a);
void fn_804A7FBC(void* x, int a);
int fn_804A8004(void* x, int a);
void fn_804A8750(void* x);
void fn_804A89D0(void* x);
void fn_804A8118(void* x);
void fn_804A83D0(void* x);
void fn_804A8B9C(void* x);
void fn_804A8C1C(void* x);
void fn_800ECAA4(void* x);
void fn_800CFB38(void* p);
int fn_800B5520(int a);
void fn_804A0B18(void* x);
void fn_804A4558(void* x, void* c);
void fn_804A560C(void* x);
void fn_804A5854(void* x, int a);
void fn_804AB774(void* x);
void fn_804AB860(void* x);
void fn_800ECF18(void* x);
int fn_8048E76C(FeScrO* x);
int fn_8048E7A8(FeScrO* x);
int fn_8048E8B0(FeScrO* x);
int fn_8048E8EC(FeScrO* x);
void fn_8048E990(void* x);
void fn_8048EB38(FeScrD* x);
void fn_8048FC64(void);
void fn_80491ADC(void* x);
int fn_80491CA4(void* x);
int fn_80491D30(void* x);
void fn_804933A0(void* x);
int fn_804977FC(char* x);
void fn_80497C08(void* x, int a);
void fn_80498438(char* x);
void fn_80498584(void);
void fn_804987C0(void* a, void* b);
void fn_80498F9C(void);
void fn_8049AB70(void* a, void* b);
FeScrH* fn_8049AC14(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_8049AC60(FeScrD* x);
void fn_8049AD0C(FeScrD* x);
void fn_8049AD2C(FeScrD* x);
int fn_8049AD58(FeScrB* x);
int fn_8049ADB4(FeScrB* x);
void fn_8049AE18(int a, char* dst);
void fn_8049AE98(FeScrD* x);
void fn_8049B0CC(void* x);
void fn_8049B114(FeScrD* x);
int fn_8049B140(FeScrB* x);
void fn_8049B288(int a, char* dst);
FeScrH* fn_8049B2B8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_8049B7A8(FeScrB* x, int a, int b);
int fn_8049B7E8(void* x);
int fn_8049B824(void* x);
int fn_8049B860(void* x);
int fn_8049B89C(void* x);
void fn_8049B8D8(FeScrB* x);
FeScrH* fn_8049C4D8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_8049CC78(FeScrD* x);
int fn_8049CDF4(FeScrF* x);
int fn_8049CE30(FeScrF* x);
int fn_8049CE6C(FeScrF* x);
int fn_8049CEA8(FeScrF* x);
void fn_8049D430(char* x);
void fn_8049DEEC(FeScrJ* x, int a);
int fn_8049E0BC(void* x);
int fn_8049E0FC(void* x);
int fn_8049E138(void* x);
int fn_8049E178(void* x);
void fn_8049F2A8(void* x);
void fn_804A0900(void* a, int b, int c);
void fn_804A15C0(char* x);
void fn_804A2634(void* x, int a, int b);
void fn_804A2734(FeScrD* x);
int fn_804A2DBC(FeScrK* x);
int fn_804A2E28(FeScrB* x);
int fn_804A2E84(void* x);
int fn_804A2EC0(void* x);
int fn_804A2EFC(void* x);
int fn_804A2F38(void* x);
int fn_804A2F74(FeScrB* x);
FeScrH* fn_804A3044(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_804A3090(FeScrD* x);
void fn_804A31D8(FeScrD* x);
void fn_804A31F8(FeScrD* x);
void fn_804A335C(void* x, char* dst);
void fn_804A34F8(FeW* x);
void fn_804A3658(void* x);
void fn_804A40EC(FeScrD* x);
void fn_804A410C(FeScrD* x);
void fn_804A4AA8(void* x, int a, void* c);
int fn_804A721C(FeScrB* x);
void fn_804A7278(void* a, char* p);
void fn_804A748C(void* x, int a);
void fn_804A74C8(FeW* x, int v);
void fn_804A7DD4(void* x);
int fn_804A7E08(char* x, int a);
void fn_804A7E44(void* a, int b, int c);
int fn_804A7E6C(void* x);
int fn_804A7EA8(void* x);
int fn_804A7EE4(void* x);
int fn_804A7F20(void* x);
int fn_804A7F5C(char* x);
int fn_804A7F84(char* x);
void fn_804A80E4(void* x);
void fn_804A91FC(int a, void* b);
void fn_804A93B8(int a, void* b);
void fn_804A9620(FeScrD* x);
void fn_804A9648(FeScrD* x);
void fn_804A9668(FeW* x);
void fn_804AA554(FeScrL* x);
void fn_804AAA9C(void* x, int a);
int fn_804AABD8(void* x);
int fn_804AAC14(void* x);
int fn_804AAC50(void* x);
int fn_804AAC8C(void* x);
int fn_804AACC8(void* x);
int fn_804AAD04(void* x);
int fn_804AAD40(void* x);
int fn_804AAD7C(void* x);
int fn_804AADB8(void* x);
int fn_804AADF8(void* x);
int fn_804AAE34(void* x);
int fn_804AAE74(void* x);
int fn_804ABBCC(void* x);
int fn_804ABC08(void* x);
int fn_804ABC44(void* x);
int fn_804ABC80(void* x);
void fn_8048EA74(FeW* x);
void fn_80492E94(void* x);
int fn_800E2E8C(int a, int b, int c, int d);
void fn_804A77AC(void* x, int a);
int fn_800C203C(void* p);
void fn_8048EC48(FeW* x);
int fn_80491C54(void* x);
int fn_80491CE0(void* x);
void fn_80491EE0(char* x);
FeScrH* fn_8049E1B4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
FeScrH* fn_804A2AB4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
int fn_804A74F4(void* x);
int fn_804A7548(void* x);
int fn_804A7598(void* x);
int fn_804A75EC(void* x);
void fn_804A7760(FeW* x);
}

#endif
