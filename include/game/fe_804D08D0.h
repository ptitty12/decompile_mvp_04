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

/* A list record: name text at +0, a type byte at +3. */
struct FeRec3 {
    char name[3];
    unsigned char m3;
};
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
    virtual void s17(int a);
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
    virtual void s29(int a);
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual FeRec3* s33(int a);
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
    virtual void s44(int a);
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
    virtual void s104(int a);
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
    virtual void s30(const char* a);
    virtual void s31();
    virtual int s32();
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
    virtual void s91(int a, int b, int c);
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
struct FeG10 {
    char pad0[0x14];
    int m14;
    int m18;
    char pad1C[0x6C - 0x1C];
    int m6C;
    int m70;
};
struct FeTeamRec;
struct FeG2 {
    char padC[0xC];
    FeG3* mC;
    FeG10* m10;
    FeTeamRec* m14;
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

/* ---- unit 804D2AC0 ------------------------------------------------------------------ */

/* The first words of the state object returned by fn_800B555C (m4 is a flag word). */
struct FeStateB {
    int m0;
    int m4;
};
/* The message manager's heap id at +0x38 (FeMsgMgr only declares the fields up to mB8). */
struct FeMgr38 {
    char pad0[0x38];
    int m38;
};

/* A list item (created by fn_80521184); its vptr is at +0x10, m4 holds the item id. */
struct FeItemData {
    int m0;
    int m4;
    int m8;
    int mC;
};
struct FeItem : FeItemData {
    virtual ~FeItem();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10(int a);
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16(int a);
};

/* Base of the list-style menu screens (ctor fn_804D2AC0, vtable lbl_80679EC0, dtor fn_804D2BCC):
 * m15C holds m154 items created from the m158 table; m144/m148/m14C are the lazily looked-up
 * widgets (fn_804D2C7C/2CE0/2D50). Evidence: fn_804D2AC0, fn_804D2EC0, fn_804D3164. */
struct FeBase2 : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    FeW* m144;
    FeW* m148;
    FeW* m14C;
    int m150;
    int m154;
    int* m158;
    FeItem** m15C;
    int m160;
    int m164;
    int m168;
    int m16C;
    int m170;
};
extern const char lbl_80679EC0[];
extern const char lbl_805F4EF4[];
extern const char lbl_805F54F8[];
extern const char lbl_805F851C[];
extern const char lbl_805F7BBC[];
extern const char lbl_805F4450[];
extern const char lbl_805F7944[];
extern const char lbl_805F852C[];
extern void* lbl_8061977C;
extern void* lbl_80622648;
extern FeW* lbl_80622644;
extern "C" {
FeW* fn_804D3CA8(FeBase2* x, int a);
void* fn_805210A0();
FeItem* fn_80521184(void* mgr, int id);
void fn_805228DC();
void fn_8035686C(void* x, int c);
void* fn_803774A8(unsigned size, int heap);
void fn_80377488(void* p);
const char* fn_80090880__FP11Unk80090880(void* g, int id);
void fn_800DD204__FP3UiST0(FeW* a, FeW* b);
FeW* fn_800C8038(FeW* w);
FeW* fn_800C8040(FeW* w);
FeW* fn_800C8044(FeW* w);
FeW* fn_8051F42C(FeItem* it);
int fn_8051F51C(FeItem* it);
int fn_802D7CE0(int a, int b);
int fn_802D7D64__Fi(int a);
FeW* fn_801389A4(FeW* w, int a);
void fn_80528FB4();
FeW* fn_804D2C7C(FeBase2* x);
FeW* fn_804D2CE0(FeBase2* x);
FeW* fn_804D2D50(FeBase2* x);
FeItem* fn_804D2EC0(FeBase2* x, int i);
FeItem* fn_804D2ED0(FeBase2* x, int id);
void fn_804D2F38(FeBase2* x);
void fn_804D2F9C(FeBase2* x);
void fn_804D3000(FeBase2* x);
void fn_804D304C(FeBase2* x);
void fn_804D3098(FeBase2* x);
int fn_804D3B18(FeBase2* x, int a);
int fn_804D3B48(FeBase2* x, int a);
void fn_804D3570(int a, void* x);
int fn_804D3328(FeBase2* x, int a);
int fn_804D3A54(FeBase2* x, int a);
void fn_800EC594__FP8UiScrRawiiiiiiii(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_800EC5F4__FP8UiScrRaw(void* self);
}

/* Screen of lbl_8067FA30 (ctor fn_804D3D74, base ctor fn_800EC594). */
struct FeS804D3D74 : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[4];
    int m138;
    int m13C;
    char pad140[8];
    int m148;
    char pad14C[8];
    FeW* m154;
    int m158;
    FeW* m15C;
    FeW* m160;
    int m164;
};
extern const char lbl_8067FA30[];

/* ---- unit 804D3E00 ------------------------------------------------------------------ */

/* A second base object (vptr at +0x24 of the sub-object) with the slots used here. */
struct FeSubX : FeSubData {
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
    virtual void s6(int a);
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual int s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20(int a, int b);
    virtual int s21();
};
extern const char lbl_805F853C[];
extern const char lbl_805F8554[];
extern const char lbl_805F8584[];
extern const char lbl_805F859C[];
extern const char lbl_805F85CC[];
extern const char lbl_805F85D8[];
extern "C" {
void fn_800EC624__FP13Unk800EC624_Tiii(void* x, void* w, int a);
FeW* fn_800C8054(FeW* w);
int fn_8040ABA0();
int fn_800B5B04(FeState* s);
void fn_804D4430(FeS804D3D74* x);
int fn_804D46B8(FeS804D3D74* x, int n);
}


/* Screen of lbl_806800B0 (ctor fn_804D4704, base ctor fn_800EC594). m188 is the LEAGUE button
 * list, m194..m1AC spinner controls (sub-object at +0x98, or +0xDC for m1A0). */
struct FeS804D4704 : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[4];
    int m138;
    char pad13C[4];
    FeW* m140;
    int m144;
    char pad148[0xC];
    int m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    FeW* m168;
    FeW* m16C;
    int m170;
    void* m174;
    void* m178;
    void* m17C;
    int* m180;
    FeW* m184;
    FeW* m188;
    FeW* m18C;
    int m190;
    FeW* m194;
    FeW* m198;
    FeW* m19C;
    FeW* m1A0;
    FeW* m1A4;
    FeW* m1A8;
    FeW* m1AC;
};
struct FeBuf464 {
    char b[0x45C];
};
extern const char lbl_806800B0[];
extern const char lbl_805F8798[];
extern const char lbl_805F5A48[];
extern const char lbl_805F5080[];
extern "C" {
FeW* fn_800C8058(FeW* w);
int* fn_800ED2B0(FeW* w, const char* name);
int fn_800ED4F0(void* x, int a);
void fn_800CFB38(void* w);
void fn_800D0074(void* w, int a, int b);
void fn_8055AC44(FeBuf464* out, int a);
void fn_800DD800(void* w, FeBuf464* b, int a, int c);
int fn_80075948__18Unk8007B2B0_Screeni(void* g, int a);
int fn_8007B3E0__18Unk8007B2B0_Screenii(void* g, int a, int b);
int fn_8057CF60(int a, int b);
void fn_804D53B8(FeS804D4704* x, int a);
void fn_804D54DC(FeS804D4704* x);
void fn_804D563C(FeS804D4704* x);
void fn_804D512C(FeS804D4704* x);
void fn_804D60AC(FeS804D4704* x, int a);
}


/* ---- unit 804D6180 ------------------------------------------------------------------ */

/* Screen of lbl_8067FD70 (ctor fn_804D6184, base ctor fn_800EC594). m160 is a list control
 * (sub-object at +0x98: s5 = selected index, s13 = count; its vslot 33 returns the record). */
struct FeS804D6184 : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    FeW* m140;
    char pad144[4];
    int m148;
    char pad14C[8];
    FeW* m154;
    int m158;
    FeW* m15C;
    FeW* m160;
    FeW* m164;
    FeW* m168;
    int m16C;
    int m170;
    int m174;
    int m178;
    int m17C;
    FeW* m180;
    FeW* m184;
};
extern const char lbl_8067FD70[];
extern const char* lbl_80621AF8[];
extern int lbl_805FCADC[];
extern unsigned char lbl_806221BC[];
inline FeRec3* FeCurRec(FeS804D6184* x)
{
    int i = ((FeSubX*)((char*)x->m160 + 0x98))->s5();
    return ((FeWX*)x->m160)->s33(i);
}
extern "C" {
int fn_8007DA28__18Unk8007B2B0_Screen(void* g);
int fn_8007DA34__18Unk8007B2B0_Screeni(void* g, int a);
int fn_800E62C4__Fii(int a, int b);
int fn_8040B574(const char* a, const char* b);
void fn_804D7C78(FeS804D6184* x);
int fn_804D6EC0(FeS804D6184* x);
}


/* Screen of lbl_8066E840 (ctor fn_804D7FE0, base ctor fn_800EC594): m154 is the TOPBAR widget,
 * m170 a second panel; m164 caches the selected index. */
struct FeS804D7FE0 : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[4];
    int m138;
    char pad13C[0x18];
    FeW* m154;
    FeW* m158;
    FeW* m15C;
    int m160;
    int m164;
    int m168;
    int m16C;
    FeW* m170;
};
extern const char lbl_8066E840[];
extern const char lbl_805F9614[];
extern const char lbl_805F962C[];
extern const char lbl_805F9644[];
extern const char lbl_805F9660[];
extern const char lbl_805F9678[];
extern const char lbl_805F9690[];
extern const char lbl_805F4EE0[];
extern const char lbl_805F565C[];
extern const char lbl_805F96B8[];
extern const char lbl_805F96C4[];
extern const char lbl_805F96D8[];
extern "C" {
void fn_804D81DC(FeS804D7FE0* x);
void fn_804D87CC(FeS804D7FE0* x);
}
struct FeStateC {
    char pad0[0x664];
    int m664;
};
inline int FeFlag()
{
    fn_800B555C();
    return fn_800B57EC();
}


extern const char lbl_805F95D4[];
extern const char lbl_805F95DC[];
extern const char lbl_805F95E8[];
extern int lbl_80621AF4;
extern "C" {
void fn_80125128(void* w, int a);
void fn_800C4720(void* a, FeW* w);
}


/* ---- unit 804DA10C ------------------------------------------------------------------ */

/* A team record (0xE64 bytes each, two of them at FeG2::m14). */
struct FeTeamRec {
    char pad0[0x164];
    int m164;
    char pad168[0x198 - 0x168];
    int m198;
    char pad19C[0xE64 - 0x19C];
};

/* Roster screen (methods start unit 804DA10C): m13C = home flag, m158 the SPGRID list, m160 the
 * team record shown; m168 holds the id of each list row. Twin of FeS804DB050. */
struct FeS804DA10C : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[8];
    int m13C;
    FeW* m140;
    int m144;
    int m148;
    int m14C;
    char pad150[4];
    FeW* m154;
    FeW* m158;
    FeW* m15C;
    FeTeamRec* m160;
    int m164;
    int m168[8];
    FeW* m188;
};
/* Twin screen (methods from 804DB050): m168/m16C are widgets, m18C the row ids. */
struct FeS804DB050 : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[4];
    int m138;
    int m13C;
    char pad140[8];
    int m148;
    int m14C;
    char pad150[8];
    FeW* m158;
    FeW* m15C;
    char pad160[8];
    FeW* m168;
    FeW* m16C;
    FeTeamRec* m170;
    char pad174[4];
    int m178;
    char pad17C[8];
    int m184;
    char pad188[4];
    int m18C[9];
};
extern const char lbl_805F9720[];
extern const char lbl_805F972C[];
extern const char lbl_805F9738[];
extern const char lbl_805F5828[];
extern const char lbl_805F9740[];
extern const char lbl_805F55DC[];
extern "C" {
int fn_800E18D4__Fi(int a);
int fn_80097148(FeTeamRec* t);
int fn_80097210(FeTeamRec* t, int a);
void fn_80096830(FeTeamRec* t, int a);
void fn_80125084(void* w, int a);
void fn_804DA6D8(FeS804DA10C* x);
void fn_804DA74C(FeS804DA10C* x);
void fn_804DB4E0(FeS804DB050* x, int a);
void fn_804DB444(FeS804DB050* x);
int fn_804DBC40(FeS804DB050* x);
}

extern int lbl_8061B2B8;
extern "C" {
void fn_800E1388(FeW* w, int a, int b, int c);
void fn_800E0C38(FeW* w, int a, int b, int c);
}

extern const char lbl_805F9770[];
extern "C" {
int fn_8007A6A0__18Unk8007A4DC_Screenii(void* g, int a, int b);
void fn_8009C54C(FeTeamRec* t, int a);
}


/* ---- unit 804DC128 ------------------------------------------------------------------ */

/* Screen of lbl_80668EA0 (ctor fn_804DC128, base ctor fn_800EC594): m158 is the list widget,
 * two embedded button panels (the FeS804DB050 type) sit at +0x1E0 and +0x434. */
struct FeS804DC128 : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[4];
    int m138;
    int m13C;
    FeW* m140;
    char pad144[0xC];
    int m150;
    FeW* m154;
    FeW* m158;
    FeW* m15C;
    int m160;
    char pad164[0x17C - 0x164];
    int m17C;
    char pad180[0x1C0 - 0x180];
    int m1C0;
    char pad1C4[0x1D4 - 0x1C4];
    int m1D4;
    char pad1D8[8];
    FeW* m1E0;
    FeW* m1E4;
    FeW* m1E8;
    FeW* m1EC;
    char pad1F0[0x688 - 0x1F0];
    FeW* m688;
    FeW* m68C;
    FeW* m690;
    FeW* m694;
    FeW* m698;
    FeW* m69C;
};
struct FeS804DD760 : FeW {
    char pad40[0xF0];
    int m130;
};
struct FeS804DD904 : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
};
struct FeStateD {
    char pad0[0x650];
    int m650;
};
extern const char lbl_80668EA0[];
extern const char lbl_805F85E0[];
extern const char lbl_805F8698[];
extern const char lbl_805F977C[];
extern const char lbl_80681998[];
extern const char lbl_8066D508[];
extern "C" {
void fn_804CF368(void* x);
void fn_804CEF98(void* x);
int fn_804DD6A0(FeS804DC128* x, int a);
int fn_804DD6EC(FeS804DC128* x, int a);
void fn_804DC344(FeS804DC128* x);
void fn_804DC64C(FeS804DC128* x);
void fn_804CF948(void* x, int a, int b);
int fn_800B5BD4(FeState* s);
void fn_800A3578(FeGlobal80619948* g);
void fn_80131380(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80131450(void* x);
void fn_801314B8(FeS804DD760* x);
void fn_801315AC(FeS804DD760* x);
void fn_801315CC(FeS804DD760* x);
void fn_80134700(FeS804DD760* x);
}

extern const char lbl_805F9788[];
extern const char lbl_805F97CC[];
extern "C" {
void fn_804DC4A4(FeS804DC128* x);
void fn_804DC764(FeS804DC128* x);
void fn_804DC854(FeS804DC128* x);
}

extern const char lbl_805F978C[];
extern const char lbl_805F97A0[];
extern const char lbl_805F97D8[];
extern const char lbl_805F97EC[];


/* ---- unit 804DDAB4 ------------------------------------------------------------------ */

struct FeS804DDB20 : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
};
/* Screen of lbl_8066CCF8 (ctor fn_804DDDA8): an embedded object at +0x134 (ctor fn_80134E38,
 * dtor fn_80134EC8) with its own vptr at +0x17C; m180 the list widget, m184 the popup. */
struct FeS804DDDA8 : FeW {
    char pad40[0xF0];
    int m130;
    char m134[0x48];
    const void* m17C;
    FeW* m180;
    FeW* m184;
    int m188;
    int m18C;
    int m190;
    int m194;
    int m198;
};
struct FeS804DE5F8 : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    char m138[0x14];
    int m14C;
    int m150;
    int m154;
    int m158;
};
struct FeStateE {
    char pad0[0x4C4];
    int m4C4;
    int m4C8;
    int m4CC;
    int m4D0;
};
extern const char lbl_8065C4E0[];
extern const char lbl_8066CCE0[];
extern const char lbl_8066CCF8[];
extern const char lbl_8066D7B0[];
extern const char lbl_805F9804[];
extern const char lbl_805F9810[];
extern const char lbl_805F981C[];
extern float lbl_805F9830;
extern int lbl_8061ABD8;
extern "C" {
void fn_80134E38(void* p, int a);
void fn_80134EC8(void* p, int a);
void fn_800D876C__FP13Unk800D876C_A(void* p);
void* fn_8007FDD4__FP13Unk8007F198_D(void* g, int a);
void fn_80529784();
void fn_804DE138(FeS804DDDA8* x);
void fn_804DE13C(FeS804DDDA8* x);
void fn_804DE55C(int a, void* x);
void fn_804DE558(void* x);
}


/* ---- unit 804DE730 ------------------------------------------------------------------ */

struct FeS804E008C : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
};
extern const char lbl_805F7B70[];
extern const char lbl_8066DD00[];
extern const char lbl_805F98E0[];
extern const char lbl_805F8034[];
extern "C" {
int fn_804027DC();
unsigned fn_804DE9EC(unsigned n);
void fn_800D878C__FP13Unk800D876C_A(void* p);
void fn_802D7EE4(int a);
void fn_800E25E0__Fii(void* w, int a);
void fn_804DF6E4(int a, void* x);
void fn_804DFE9C(FeW* x);
}

extern const char lbl_805F5B98[];
extern const char lbl_805F98D4[];
extern const char lbl_805F9874[];
extern const char lbl_805F98FC[];
extern const char lbl_805F9908[];

#endif
