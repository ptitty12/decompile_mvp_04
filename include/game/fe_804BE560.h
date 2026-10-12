/*
 * Shared types for the front-end overlay units fe/tu_804BE560 .. fe/tu_804CE408
 * (0x804BE560..0x804D08D0; reconstructed, placeholder names, nothing here comes from
 * original headers). Builds on fe_80459228.h (widget base FeW, message manager, popups).
 *
 * The code is methods of menu screens derived from the widget base (vptr at +0x3C, own fields
 * from +0x130). Their vtables are .data objects, so methods are written as extern "C"
 * functions taking the screen explicitly.
 */
#ifndef GAME_FE_804BE560_H
#define GAME_FE_804BE560_H

#include "game/fe_80459228.h"
#include "game/tu_8007A4DC.h"

/* Widget view with every slot returning int (vptr at +0x3C, slot N at vtable +8N): reached by a cast when a
 * call site uses the value of a slot FeW declares void; same shape as the game-code VT3C of tu_80144CF0.h. */
class FeVQ {
public:
    char pad0[0x3C];
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
    virtual int s20(float a);
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
    virtual int s46(int a);
    virtual int s47(int a);
    virtual int s48(int a);
    virtual int s49(int a);
    virtual int s50(int a);
    virtual int s51(int a, int b);
    virtual int s52(int a);
    virtual int s53(int a);
    virtual int s54(int a);
    virtual int s55(int a);
    virtual int s56(int a);
    virtual int s57(int a);
    virtual int s58(int a);
    virtual int s59(int a);
    virtual int s60(int a);
    virtual int s61(int a);
    virtual int s62();
    virtual int s63();
    virtual int s64();
    virtual int s65();
    virtual int s66(int a);
    virtual int s67(int a, int b);
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
    virtual FeVQ* s84(int a);
    virtual int s85();
    virtual int s86();
    virtual int s87();
    virtual int s88();
    virtual int s89();
    virtual int s90();
    virtual int s91();
    virtual int s92();
    virtual int s93();
    virtual int s94(int a);
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
    virtual int s111(int a, int b);
};
/* Generic screen: widget pointers from +0x134 (button handlers fn_804BF148 etc. forward
 * to the widget at m134/m138/m14C/m150/m154 through its virtuals; the widget kind is not
 * identified). */
struct FeScrN : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
    FeW* m138;
    FeW* m13C;
    FeW* m140;
    FeW* m144;
    FeW* m148;
    FeW* m14C;
    FeW* m150;
    FeW* m154;
    FeW* m158;
    FeW* m15C;
    FeW* m160;
    FeW* m164;
    FeW* m168;
    FeW* m16C;
    FeW* m170;
    FeW* m174;
    FeW* m178;
    FeW* m17C;
    FeW* m180;
    FeW* m184;
    FeW* m188;
    FeW* m18C;
    FeW* m190;
};

/* Same, for the screen whose widget sits at +0xE0C (fn_804CD794, fn_804CD810); +0xE04 holds the
 * vptr of a sub-object that fn_804CD2FC resets. */
struct FeScrE0C : FeScrN {
    char pad194[0xE04 - 0x194];
    const void* mE04;
    int mE08;
    FeW* mE0C;
    int mE10;
    FeW* mE14;
};

/* Object whose vptr sits at +0x20 (fn_804C0298: slot 13 returns an id). */
class FeVt20 {
public:
    char pad0[0x20];
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
    virtual int s13();
};

/* Sub-object at +0x98 of a widget with its vptr at +0x24 of the sub-object (fn_804C68B4, slot 20). */
class FeSubV {
public:
    char pad0[0x24];
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

/* Record the gameplay screen object (lbl_8061930C+0x30) keeps four counters in. */
struct FeStats {
    char pad0[0x14];
    int m14;
    int m18;
    int m1C;
    int m20;
};

/* Chain behind lbl_806192E0 (fn_804CF8AC reads two ids at +0x6C/+0x70 of the third level). */
struct FeLink10 {
    char pad0[0x6C];
    int m6C;
    int m70;
};
struct FeLink4 {
    char pad0[0x10];
    FeLink10* m10;
};
struct Fe806192E0 {
    char pad0[4];
    FeLink4* m4;
};
extern Fe806192E0* lbl_806192E0;

/* Object whose +0x20 member is a vtable pointer reset by its destructor (fn_804BFB3C). */
struct FeD20 {
    char pad0[0x20];
    const void* m20;
};

struct FeObj10 {
    char pad0[0x10];
    int m10;
};
/* Fields of lbl_80619948 / fn_800B555C() not declared in fe_80459228.h (read through casts). */
struct Fe19948X {
    char pad0[0x28];
    int m28;
};
struct FeStateX {
    char pad0[0x608];
    int m608;
};

inline int FeAt(char* a, int i)
{
    int o = i * 4;
    return *(int*)(a + o);
}

/* Object (not a widget) whose +0x24 member is a widget (fn_804BFD98). */
struct FeObjP {
    char pad0[0x24];
    FeW* m24;
};

/* Two 0x44-byte records at +0x144 and +0x188 of the screen of fn_804CE408; fn_804CF92C picks
 * the one whose id (+0x38) equals a given value. */
struct FeSlot44 {
    char pad0[0x38];
    int m38;
    char pad3C[8];
};
extern int lbl_80621968;
extern int lbl_8062163C;

struct UiScrRaw;
struct UiS;
UiScrRaw* fn_800EB2F4(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_800EB41C(UiS* self);

/* One 0x60-byte row of the table at +0x3E8 of the screen of fn_804CE408 (fn_804CEBAC compares its
 * id at +0x4C with m97C[i]). */
struct FeRow60 {
    char pad0[0x4C];
    int m4C;
    char pad50[0x10];
};
struct FeScrM : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    FeW* m138;
    char pad13C[0x144 - 0x13C];
    FeSlot44 m144;
    FeSlot44 m188;
    FeW* m1CC;
    FeW* m1D0;
    int m1D4;
    char pad1D8[0x3E8 - 0x1D8];
    FeRow60 m3E8[7];
    char pad688[0x960 - 0x688];
    int m960[7];
    int m97C[7];
    void* m998;
    int m99C;
    int m9A0;
    int m9A4;
    int m9A8;
    int m9AC;
    char m9B0[1];
};

extern "C" {
void fn_8035686C(void* self);
void fn_80444890(void* x);
void fn_80330BC8(void* x);
void fn_80377488(void* p);
void fn_804D1FD4(FeSlot44* p);
void fn_804D21B8(FeSlot44* p, FePair* q);
FeW* fn_804D2310(FeSlot44* p);
void fn_800E5404(int a, int b, int c);
}

#endif
