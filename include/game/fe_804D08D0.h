/*
 * Shared types for the front-end overlay units fe/tu_804D08D0 .. fe/tu_804DE730
 * (0x804D08D0..0x804E02E0; reconstructed, placeholder names, nothing here comes from
 * original headers). Same conventions as fe_80459228.h: the screens derive from the
 * widget base (vptr at +0x3C, {delta, pfn} vtable entries), their vtables are .data
 * objects, so the methods are written as extern "C" functions taking the screen explicitly.
 */
#ifndef GAME_FE_804D08D0_H
#define GAME_FE_804D08D0_H

#include "game/fe_80459228.h"

/* BEGIN-FEWX */
/* Widget base views with the slot signatures that differ from FeW's (reached by a cast). Slot N = vtable byte offset / 8. */
struct FeWX : Unk800C7B40_Data {
    virtual ~FeWX();
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
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67(int a);
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86(int a, int b);
    virtual void s87();
    virtual int s88(int a);
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95(int a, int b);
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual void s116();
    virtual void s117();
    virtual void s118();
    virtual void s119();
    virtual void s120();
    virtual void s121();
    virtual void s122();
    virtual void s123();
    virtual void s124();
    virtual void s125();
    virtual void s126();
    virtual void s127();
};
struct FeWY : Unk800C7B40_Data {
    virtual ~FeWY();
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
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84(int a);
    virtual void s85(int a);
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99(int a);
    virtual void s100();
    virtual void s101();
    virtual int s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual void s116();
    virtual void s117();
    virtual void s118();
    virtual void s119();
    virtual void s120();
    virtual void s121();
    virtual void s122();
    virtual void s123();
    virtual void s124();
    virtual void s125();
    virtual void s126();
    virtual void s127();
};
struct FeWZ : Unk800C7B40_Data {
    virtual ~FeWZ();
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
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84(int a, int b, int c);
    virtual void s85();
    virtual void s86();
    virtual void s87(int a, int b, int c);
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual void s116();
    virtual void s117();
    virtual void s118();
    virtual void s119();
    virtual void s120();
    virtual void s121();
    virtual void s122();
    virtual void s123();
    virtual void s124();
    virtual void s125();
    virtual void s126();
    virtual void s127();
};
/* END-FEWX */


/* The popup widget (FePopup) with its fields past m30C. */
struct FePop : FePopup {
    int m310;
    int m314;
};

/* ---- unit 804D08D0 ------------------------------------------------------------------ */

/* Navigation group (ctor fn_804D1FD4, size 0x44, vptr lbl_80655E98 at +0x40): up to 5 widgets
 * in m0[] (count m28) and up to 2 (a, widget) pairs in m14[] (count m2C); m30 is the current
 * index into m0, m34 the current index into m14 (-1 = none). Evidence: fn_804D2144,
 * fn_804D2310, fn_804D24E8, fn_804D29F0. */
struct FeNavEnt {
    int a;
    FeW* w;
    FeNavEnt()
    {
        a = 0;
        w = 0;
    }
};
struct FeNav {
    FeW* m0[5];
    FeNavEnt m14[2];
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    FeW* m3C;
    const void* m40;
    FeNav();
};
extern const char lbl_80655E98[];
inline int FeNavSub(FeNav* n)
{
    int r = 1;
    if (n->m34 == -1) {
        r = 0;
    }
    return r;
}
extern "C" {
void fn_804D2118(FeNav* n, int a);
void fn_804D2144(FeNav* n, int a);
FeW* fn_804D2310(FeNav* n);
int fn_804D2470(FeNav* n);
void fn_804D24E8(FeNav* n, FeW* w);
int fn_804D24B0(FeNav* n);
void fn_804D2654(FeNav* n);
void fn_804D292C(FeNav* n, int a);
}

/* Screen whose methods start unit 804D08D0 (its ctor is in an earlier unit): m134 is the grid
 * widget; m144 and m188 are two navigation groups. */
struct FeS804D08D0 : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
    char pad138[0x144 - 0x138];
    FeNav m144;
    FeNav m188;
    char pad1CC[0x1D8 - 0x1CC];
    int m1D8;
    int m1DC;
};

/* Screen of lbl_80681180 (ctor fn_804D1070). m134 is the PLAYERGRID widget, m138 the NAVBAR
 * popup, m13C the PLAYERINFOBAR list; m14C a table of 1000 ids. */
struct FeS804D1070 : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
    FeW* m138;
    FeList* m13C;
    int m140;
    int m144;
    int m148;
    int m14C[1000];
};
extern const char lbl_80681180[];
extern const char lbl_805F54B8[];
extern const char lbl_805F4F84[];
extern const char lbl_805F4F8C[];
extern const char lbl_805F4F0C[];
extern const char lbl_805F3CA8[];
extern float lbl_805F8518;
extern char* lbl_80621AEC;
struct FeG3 {
    char pad0[0x600];
    int m600;
};
struct FeG2 {
    char padC[0xC];
    FeG3* mC;
};
struct FeG1 {
    char pad0[4];
    FeG2* m4;
};
extern FeG1* lbl_806192E0;
extern "C" {
void fn_804D0E98(int a, FeS804D08D0* x);
void fn_804D1B7C(void* x);
void fn_804D1AFC();
int fn_804D1278(FeS804D1070* x);
void fn_800E49A4();
int fn_800B57EC();
FeW* fn_800C8060(FeW* w);
void fn_80132438(FePopup* o, void* self, int a, void (*cb2)(void*), void (*cb3)(), int b, int c, int d, float e);
void fn_80125154(void* w, int a);
void fn_8012E1C4(void* w, int a, int b);
void fn_8007DA8C__18Unk8007B2B0_Screenii(void* g, int a, int b);
}

#endif
