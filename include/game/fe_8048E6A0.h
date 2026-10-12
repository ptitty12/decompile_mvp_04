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
#include "game/clampiter.h"


/* The widget stored at byte offset `off` of a screen. */
static inline FeW* FeMem(void* x, int off)
{
    return *(FeW**)((char*)x + off);
}

/* Widget base viewed with every slot taking one int argument (a cast target when a call site passes one argument to a slot FeW declares without it). */
struct FeWQ : Unk800C7B40_Data {
    virtual ~FeWQ();
    virtual void s2(int a);
    virtual void s3(int a);
    virtual void s4(int a);
    virtual void s5(int a);
    virtual void s6(int a);
    virtual void s7(int a);
    virtual void s8(int a);
    virtual void s9(int a);
    virtual void s10(int a);
    virtual void s11(int a);
    virtual void s12(int a);
    virtual void s13(int a);
    virtual void s14(int a);
    virtual void s15(int a);
    virtual void s16(int a);
    virtual void s17(int a);
    virtual void s18(int a);
    virtual void s19(int a);
    virtual void s20(int a);
    virtual void s21(int a);
    virtual void s22(int a);
    virtual void s23(int a);
    virtual void s24(int a);
    virtual void s25(int a);
    virtual void s26(int a);
    virtual void s27(int a);
    virtual void s28(int a);
    virtual void s29(int a);
    virtual void s30(int a);
    virtual void s31(int a);
    virtual void s32(int a);
    virtual void s33(int a);
    virtual void s34(int a);
    virtual void s35(int a);
    virtual void s36(int a);
    virtual void s37(int a);
    virtual void s38(int a);
    virtual void s39(int a);
    virtual void s40(int a);
    virtual void s41(int a);
    virtual void s42(int a);
    virtual void s43(int a);
    virtual void s44(int a);
    virtual void s45(int a);
    virtual void s46(int a);
    virtual void s47(int a);
    virtual void s48(int a);
    virtual void s49(int a);
    virtual void s50(int a);
    virtual void s51(int a);
    virtual void s52(int a);
    virtual void s53(int a);
    virtual void s54(int a);
    virtual void s55(int a);
    virtual void s56(int a);
    virtual void s57(int a);
    virtual void s58(int a);
    virtual void s59(int a);
    virtual void s60(int a);
    virtual void s61(int a);
    virtual void s62(int a);
    virtual void s63(int a);
    virtual void s64(int a);
    virtual void s65(int a);
    virtual void s66(int a);
    virtual void s67(int a);
    virtual void s68(int a);
    virtual void s69(int a);
    virtual void s70(int a);
    virtual void s71(int a);
    virtual void s72(int a);
    virtual void s73(int a);
    virtual void s74(int a);
    virtual void s75(int a);
    virtual void s76(int a);
    virtual void s77(int a);
    virtual void s78(int a);
    virtual void s79(int a);
    virtual void s80(int a);
    virtual void s81(int a);
    virtual void s82(int a);
    virtual void s83(int a);
    virtual void s84(int a);
    virtual void s85(int a);
    virtual void s86(int a);
    virtual void s87(int a);
    virtual void s88(int a);
    virtual void s89(int a);
    virtual void s90(int a);
    virtual void s91(int a);
    virtual void s92(int a);
    virtual void s93(int a);
    virtual void s94(int a);
    virtual void s95(int a);
    virtual void s96(int a);
    virtual void s97(int a);
    virtual void s98(int a);
    virtual void s99(int a);
    virtual void s100(int a);
    virtual void s101(int a);
    virtual void s102(int a);
    virtual void s103(int a);
    virtual void s104(int a);
    virtual void s105(int a);
    virtual void s106(int a);
    virtual void s107(int a);
    virtual void s108(int a);
    virtual void s109(int a);
    virtual void s110(int a);
    virtual void s111(int a);
    virtual void s112(int a);
    virtual void s113(int a);
    virtual void s114(int a);
    virtual void s115(int a);
    virtual void s116(int a);
    virtual void s117(int a);
    virtual void s118(int a);
    virtual void s119(int a);
    virtual void s120(int a);
    virtual void s121(int a);
    virtual void s122(int a);
    virtual void s123(int a);
    virtual void s124(int a);
    virtual void s125(int a);
    virtual void s126(int a);
    virtual void s127(int a);
};
/* Widget base viewed with every slot taking two int arguments. */
struct FeWR : Unk800C7B40_Data {
    virtual ~FeWR();
    virtual void s2(int a, int b);
    virtual void s3(int a, int b);
    virtual void s4(int a, int b);
    virtual void s5(int a, int b);
    virtual void s6(int a, int b);
    virtual void s7(int a, int b);
    virtual void s8(int a, int b);
    virtual void s9(int a, int b);
    virtual void s10(int a, int b);
    virtual void s11(int a, int b);
    virtual void s12(int a, int b);
    virtual void s13(int a, int b);
    virtual void s14(int a, int b);
    virtual void s15(int a, int b);
    virtual void s16(int a, int b);
    virtual void s17(int a, int b);
    virtual void s18(int a, int b);
    virtual void s19(int a, int b);
    virtual void s20(int a, int b);
    virtual void s21(int a, int b);
    virtual void s22(int a, int b);
    virtual void s23(int a, int b);
    virtual void s24(int a, int b);
    virtual void s25(int a, int b);
    virtual void s26(int a, int b);
    virtual void s27(int a, int b);
    virtual void s28(int a, int b);
    virtual void s29(int a, int b);
    virtual void s30(int a, int b);
    virtual void s31(int a, int b);
    virtual void s32(int a, int b);
    virtual void s33(int a, int b);
    virtual void s34(int a, int b);
    virtual void s35(int a, int b);
    virtual void s36(int a, int b);
    virtual void s37(int a, int b);
    virtual void s38(int a, int b);
    virtual void s39(int a, int b);
    virtual void s40(int a, int b);
    virtual void s41(int a, int b);
    virtual void s42(int a, int b);
    virtual void s43(int a, int b);
    virtual void s44(int a, int b);
    virtual void s45(int a, int b);
    virtual void s46(int a, int b);
    virtual void s47(int a, int b);
    virtual void s48(int a, int b);
    virtual void s49(int a, int b);
    virtual void s50(int a, int b);
    virtual void s51(int a, int b);
    virtual void s52(int a, int b);
    virtual void s53(int a, int b);
    virtual void s54(int a, int b);
    virtual void s55(int a, int b);
    virtual void s56(int a, int b);
    virtual void s57(int a, int b);
    virtual void s58(int a, int b);
    virtual void s59(int a, int b);
    virtual void s60(int a, int b);
    virtual void s61(int a, int b);
    virtual void s62(int a, int b);
    virtual void s63(int a, int b);
    virtual void s64(int a, int b);
    virtual void s65(int a, int b);
    virtual void s66(int a, int b);
    virtual void s67(int a, int b);
    virtual void s68(int a, int b);
    virtual void s69(int a, int b);
    virtual void s70(int a, int b);
    virtual void s71(int a, int b);
    virtual void s72(int a, int b);
    virtual void s73(int a, int b);
    virtual void s74(int a, int b);
    virtual void s75(int a, int b);
    virtual void s76(int a, int b);
    virtual void s77(int a, int b);
    virtual void s78(int a, int b);
    virtual void s79(int a, int b);
    virtual void s80(int a, int b);
    virtual void s81(int a, int b);
    virtual void s82(int a, int b);
    virtual void s83(int a, int b);
    virtual void s84(int a, int b);
    virtual void s85(int a, int b);
    virtual void s86(int a, int b);
    virtual void s87(int a, int b);
    virtual void s88(int a, int b);
    virtual void s89(int a, int b);
    virtual void s90(int a, int b);
    virtual void s91(int a, int b);
    virtual void s92(int a, int b);
    virtual void s93(int a, int b);
    virtual void s94(int a, int b);
    virtual void s95(int a, int b);
    virtual void s96(int a, int b);
    virtual void s97(int a, int b);
    virtual void s98(int a, int b);
    virtual void s99(int a, int b);
    virtual void s100(int a, int b);
    virtual void s101(int a, int b);
    virtual void s102(int a, int b);
    virtual void s103(int a, int b);
    virtual void s104(int a, int b);
    virtual void s105(int a, int b);
    virtual void s106(int a, int b);
    virtual void s107(int a, int b);
    virtual void s108(int a, int b);
    virtual void s109(int a, int b);
    virtual void s110(int a, int b);
    virtual void s111(int a, int b);
    virtual void s112(int a, int b);
    virtual void s113(int a, int b);
    virtual void s114(int a, int b);
    virtual void s115(int a, int b);
    virtual void s116(int a, int b);
    virtual void s117(int a, int b);
    virtual void s118(int a, int b);
    virtual void s119(int a, int b);
    virtual void s120(int a, int b);
    virtual void s121(int a, int b);
    virtual void s122(int a, int b);
    virtual void s123(int a, int b);
    virtual void s124(int a, int b);
    virtual void s125(int a, int b);
    virtual void s126(int a, int b);
    virtual void s127(int a, int b);
};

/* Widget base viewed with every slot returning int. */
struct FeWI : Unk800C7B40_Data {
    virtual ~FeWI();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int s10();
    virtual int s11();
    virtual int s12();
    virtual int s13();
    virtual int s14();
    virtual int s15();
    virtual int s16();
    virtual int s17();
    virtual int s18();
    virtual int s19();
    virtual int s20();
    virtual int s21();
    virtual int s22();
    virtual int s23();
    virtual int s24();
    virtual int s25();
    virtual int s26();
    virtual int s27();
    virtual int s28();
    virtual int s29();
    virtual int s30();
    virtual int s31();
    virtual int s32();
    virtual int s33();
    virtual int s34();
    virtual int s35();
    virtual int s36();
    virtual int s37();
    virtual int s38();
    virtual int s39();
    virtual int s40();
    virtual int s41();
    virtual int s42();
    virtual int s43();
    virtual int s44();
    virtual int s45();
    virtual int s46();
    virtual int s47();
    virtual int s48();
    virtual int s49();
    virtual int s50();
    virtual int s51();
    virtual int s52();
    virtual int s53();
    virtual int s54();
    virtual int s55();
    virtual int s56();
    virtual int s57();
    virtual int s58();
    virtual int s59();
    virtual int s60();
    virtual int s61();
    virtual int s62();
    virtual int s63();
    virtual int s64();
    virtual int s65();
    virtual int s66();
    virtual int s67();
    virtual int s68();
    virtual int s69();
    virtual int s70();
    virtual int s71();
    virtual int s72();
    virtual int s73();
    virtual int s74();
    virtual int s75();
    virtual int s76();
    virtual int s77();
    virtual int s78();
    virtual int s79();
    virtual int s80();
    virtual int s81();
    virtual int s82();
    virtual int s83();
    virtual int s84();
    virtual int s85();
    virtual int s86();
    virtual int s87();
    virtual int s88();
    virtual int s89();
    virtual int s90();
    virtual int s91();
    virtual int s92();
    virtual int s93();
    virtual int s94();
    virtual int s95();
    virtual int s96();
    virtual int s97();
    virtual int s98();
    virtual int s99();
    virtual int s100();
    virtual int s101();
    virtual int s102();
    virtual int s103();
    virtual int s104();
    virtual int s105();
    virtual int s106();
    virtual int s107();
    virtual int s108();
    virtual int s109();
    virtual int s110();
    virtual int s111();
    virtual int s112();
    virtual int s113();
    virtual int s114();
    virtual int s115();
    virtual int s116();
    virtual int s117();
    virtual int s118();
    virtual int s119();
    virtual int s120();
    virtual int s121();
    virtual int s122();
    virtual int s123();
    virtual int s124();
    virtual int s125();
    virtual int s126();
    virtual int s127();
};

/* Store one word of an indexed record: b is the record array base plus the field offset, o the
 * byte offset of the record (retail: addi base,field; stwx v,base,o). */
inline void FeSt(char* b, int o, int v)
{
    *(int*)(b + o) = v;
}
inline void FeStF(char* b, int o, float v)
{
    *(float*)(b + o) = v;
}

/* Sub-object at +0x98 of a widget (data pad 0x24, vptr at +0x24 of it); slot 20 takes (a, b). */
struct FeSubBD {
    char pad0[0x24];
};
struct FeSubB : FeSubBD {
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20(int a, int b);
};

/* Sub-object at +0xDC of a widget, every slot returning int (vptr at +0x24 of it). */
struct FeSubI : FeSubBD {
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int s10();
    virtual int s11();
    virtual int s12();
    virtual int s13();
    virtual int s14();
    virtual int s15();
    virtual int s16();
    virtual int s17();
    virtual int s18();
    virtual int s19();
    virtual int s20();
};

/* fn_80125084 returns a value (int); fe_80459228.h declares it void, so value-using callers go through this. */
#define FeW125084 ((int (*)(void*, int))fn_80125084)

/* Raw field access by byte offset (placeholder for named fields of the screens). */
#define FeI(x, off) (*(int*)((char*)(x) + (off)))
#define FeP(x, off) (*(void**)((char*)(x) + (off)))

/* Callees and helpers shared by the units in this range (types refined as functions match). */
struct FeStateX {
    char pad0[0x650];
    int m650;
};
void fn_8001C168();
int fn_800D83A0();
void fn_800E2944(int a, int b);

/* Screen of fn_804AB940 (vtable lbl_80674328): m144 is a 0x80-byte buffer cleared with fn_8040B320. */
struct FeScrM : FeScrH {
    int m134;
    int m138;
    int m13C;
    int m140;
    char m144[0x80];
    int m1C4;
    int m1C8;
};
struct FeNm {
    char s[200];
};
struct FeCfgC {
    char pad0[0x1D48];
    float m1D48;
};
struct FeCfgB {
    char pad0[0x14];
    FeCfgC* m14;
};
struct FeCfgA {
    char pad0[4];
    FeCfgB* m4;
};
extern FeCfgA* const lbl_806192E0;

/* Object kind with its vptr at +0x10 (returned by fn_804D2ED0); virtuals are placeholders
 * (same layout as UiX in tu_800F1AEC.h). */
struct FeD10 {
    char pad0[0x10];
};
class FeX10 : public FeD10 {
public:
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual int x4();
};
struct FeStateY {
    char pad0[0x28];
    int m28;
    int m2C;
};
extern const char lbl_80674DC8[];
extern const char lbl_80674B20[];
extern const char lbl_806755C0[];
extern const char lbl_80681F30[];
extern const char lbl_80682260[];
extern const float lbl_805F7708;
extern const char lbl_805F4EF4[];
extern const char lbl_806217F8[];
extern const char lbl_80676060[];
extern const char lbl_80677448[];
extern const float lbl_805F7434;
extern const char lbl_806735E0[];
extern const char lbl_80674328[];
extern const char lbl_805F6B18[];
extern const char lbl_805F6B74[];
extern const char lbl_805F5500[];
extern const char lbl_805F7114[];
extern const float lbl_805F7110;
extern const char lbl_805F5ABC[];
extern const char lbl_805F4F84[];
extern const float lbl_805F66FC;
extern const char lbl_806745D0[];
extern const char lbl_805F535C[];
extern const char lbl_805F7654[];
extern const char lbl_805F765C[];
extern const char lbl_805F5510[];
extern const char lbl_805F73E0[];
extern const char lbl_805F7328[];
extern const char lbl_805F755C[];
extern const char lbl_805F5060[];
extern const float lbl_805F7448;
extern const float lbl_805F744C;
extern const char lbl_805F73EC[];
extern const char lbl_805F75B8[];
extern const char lbl_805F4450[];
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
FeW* fn_800C8060(FeW* w);
FeScrH* fn_8049AE48(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
FeScrH* fn_804A7288(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
int fn_8049A480(char* x);
int fn_8049DF3C(FeW* x);
int fn_8049DF9C(FeW* x);
void fn_804A32F4(void* a, void* b);
FeScrH* fn_804A33A4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
int fn_804A507C(void* x);
int fn_804A50E0(void* x);
int fn_804A5140(void* x);
FeX10* fn_804D2ED0(void* x, int a);
void fn_8007295C__18Unk8007A4DC_Screen(void* g);
void* fn_80081B60__FP13Unk8007FF8C_Y(void* p);
int fn_80096988(void* p, int a, int b);
void fn_804982C0(void* x);
void fn_8040B320(void* p, int v, int n);
void fn_804AAEB0(void* x);
void fn_804AAF34(void* x);
void fn_804AAFE8(void* x);
void fn_804AB0C8(void* x);
void fn_804AB188(void* x);
FeScrH* fn_8048E928(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_8048EB58(void* x);
void fn_8049693C(char* x);
FeScrL* fn_8049A1F0(FeScrL* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_8049A988(FeScrL* x, int a);
FeScrH* fn_804A93E4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_804AAA28(void* x, int a);
FeScrL* fn_8046FED8(FeScrL* self, int a, int b, int c, int d, int e, int f, int g, int h);
FeW* fn_800C8040(FeW* w);
FeW* fn_800C8044(FeW* w);
FeW* fn_800C8054(FeW* w);
void fn_804031BC(char* dst, const char* src);
int fn_800DE440(char* buf, int o, int a); /* tail-returns fn_800DE6A8 */
int fn_80403DE4(char* dst, const char* fmt, ...);
void fn_80492BA8(void* x, char* s);
void fn_804A96A4(void* a, int b, int c, int d, int e, int f, int g, int h);
void fn_8048EBC8(void);
void fn_804933D4(void* x, int a);
void fn_8049364C(void* x, int a);
void fn_80498880(FeW* x);
void fn_8049DE70(char* x);
void fn_8049F00C(char* x);
void fn_80470F20(FeScrL* x, int a);
void fn_8007F3E8__FP13Unk8007F198_Aii(void* g, int a, int b);
int fn_800B57EC(void* s);
int fn_804A7FFC(void* x);
void fn_804A8F98(void* x);
void fn_804A86BC(void* x);
void* fn_803774A8(int n, int heap);
void fn_80496560(void* x);
void fn_80497C48(void* x);
void fn_804983AC(void* x);
void fn_8049A330(void* x, int a);
void fn_804A740C(FeW* x);
void fn_804A7760(FeW* x);
int fn_8049DFFC(FeW* x);
int fn_8049E05C(FeW* x);
int fn_804A80DC(void* x);
void fn_80125154(void* w, int a);
void fn_80125268(void* w, int a, void* cb, int b);
void fn_80497B74(char* x, int idx);
void fn_80498590(int a, void* x);
void fn_8049CC98(void* x);
void fn_8049ED34(void* a, void* cb);
void fn_804A2964(void);
FeW* fn_804D2D50(void* x);
void fn_804D3BA0(void* x);
void fn_80132438(void* w, void* self, void (*a)(void*), void (*b)(FeW*), void (*c)(), int d, int e, int f, float g);
int fn_8048E9C8(void* x, int a);
void fn_8049C440(FeScrB* x);
void fn_8049CBD4(void* x);
void fn_804A0A78(void* x, int a);
FeScrH* fn_804A4048(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_804A4AEC(void* x);
FeW* fn_800C8058(FeW* w);
void fn_80125128(void* w, int a);
void fn_80499B08(void* x);
void fn_8049FF38(FeW* x, FeW* y);
int fn_804A1510(void* x, FeEvt* ev);
int fn_80499740(FeW* x);
int fn_80499910(FeW* x);
void fn_804A2674(FeW* x, int a);
int fn_804A5348(void* x);
int fn_804A554C(void* x);
void fn_800DC50C(void* a, float b, float c);
void fn_80471830(void* x);
void fn_8049A3B8(char* x);
void fn_8049CD30(void* x, FeW* y);
void fn_804A8ED4(void* x);
int fn_800B5758(void* s);
void* fn_8007F7D0__FP13Unk8007F198_BUi(void* g, unsigned a);
int fn_8007B3E0__18Unk8007B2B0_Screenii(void* g, int a, void* t);
void fn_8007B4A8__18Unk8007B2B0_Screeniii(void* g, int a, void* t, int v);
int fn_804999D0(FeW* x, FeW* y, int z);
void fn_804A256C(void* a, FeW* x);
void fn_804A29F4(FeW* x);
int fn_804A3224(FeW* x);
void fn_804983A8(void);
void fn_80498580(void);
void fn_804987E8(void);
void fn_8049AD4C(void);
void fn_8049AD50(void);
void fn_8049AD54(void);
int fn_8049AE10(void);
void fn_8049B134(void);
void fn_8049B138(void);
void fn_8049B13C(void);
int fn_8049B280(void);
int fn_804A0470(void);
int fn_804A0478(void);
int fn_804A0480(void);
int fn_804A0488(void);
void fn_804A3218(void);
void fn_804A321C(void);
void fn_804A3220(void);
int fn_804A334C(void);
int fn_804A3354(void);
void fn_804A7284(void);
void fn_804A7E68(void);
int fn_804A7FAC(void);
int fn_804A7FB4(void);
}

/* Widget base viewed with every slot taking three int arguments (cast target; slots 2..100 only). */
#define FEW3_(n) virtual void s##n(int a, int b, int c);
struct FeW3 : Unk800C7B40_Data {
    virtual ~FeW3();
    FEW3_(2) FEW3_(3) FEW3_(4) FEW3_(5) FEW3_(6) FEW3_(7) FEW3_(8) FEW3_(9) FEW3_(10) FEW3_(11)
    FEW3_(12) FEW3_(13) FEW3_(14) FEW3_(15) FEW3_(16) FEW3_(17) FEW3_(18) FEW3_(19) FEW3_(20)
    FEW3_(21) FEW3_(22) FEW3_(23) FEW3_(24) FEW3_(25) FEW3_(26) FEW3_(27) FEW3_(28) FEW3_(29)
    FEW3_(30) FEW3_(31) FEW3_(32) FEW3_(33) FEW3_(34) FEW3_(35) FEW3_(36) FEW3_(37) FEW3_(38)
    FEW3_(39) FEW3_(40) FEW3_(41) FEW3_(42) FEW3_(43) FEW3_(44) FEW3_(45) FEW3_(46) FEW3_(47)
    FEW3_(48) FEW3_(49) FEW3_(50) FEW3_(51) FEW3_(52) FEW3_(53) FEW3_(54) FEW3_(55) FEW3_(56)
    FEW3_(57) FEW3_(58) FEW3_(59) FEW3_(60) FEW3_(61) FEW3_(62) FEW3_(63) FEW3_(64) FEW3_(65)
    FEW3_(66) FEW3_(67) FEW3_(68) FEW3_(69) FEW3_(70) FEW3_(71) FEW3_(72) FEW3_(73) FEW3_(74)
    FEW3_(75) FEW3_(76) FEW3_(77) FEW3_(78) FEW3_(79) FEW3_(80) FEW3_(81) FEW3_(82) FEW3_(83)
    FEW3_(84) FEW3_(85) FEW3_(86) FEW3_(87) FEW3_(88) FEW3_(89) FEW3_(90) FEW3_(91) FEW3_(92)
    FEW3_(93) FEW3_(94) FEW3_(95) FEW3_(96) FEW3_(97) FEW3_(98) FEW3_(99) FEW3_(100)
};

#endif
