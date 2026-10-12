/*
 * Shared types for the front-end overlay units fe/tu_804FE34C .. fe/tu_80516990
 * (0x804FE34C..0x80516990; reconstructed, placeholder names, nothing here comes from
 * original headers). Builds on fe_804BE560.h (widget base FeW, screen FeScrN, message manager).
 *
 * Same conventions as the earlier fe headers: the code is methods of menu screens (vptr at +0x3C,
 * own fields from +0x130) written as extern "C" functions that take the screen explicitly.
 * Structs below only name the fields the matched functions of these units touch (offsets read
 * from the disassembly of the function that uses them).
 */
#ifndef GAME_FE_804FE34C_H
#define GAME_FE_804FE34C_H

#include "game/fe_804BE560.h"

/* Widget base with the slot signatures needed by these units (copy of FeWV; edit a slot line here
 * when a call site proves another argument list). Reached by a cast. Slot N is the vtable byte
 * offset / 8. */
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
    virtual void s15(int a);
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
    virtual void s42(int a);
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
    virtual void s55(int a);
    virtual void s56();
    virtual void s57(int a);
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
    virtual void s69(int a);
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
    virtual int s84();
    virtual void s85(int a);
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual int s94(int a, int b);
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101(int a, int b);
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

/* Screen reached through an offset-only view: one int field at +0x1EC (fn_804FF8F8). */
struct FeS1EC : FeW {
    char pad40[0x1EC - 0x40];
    int m1EC;
};

/* Shared callees of these units. The string table accessor and the 8-pixel text helper keep the
 * mangled symbol names the retail map gives them (their other-unit declarations take one
 * argument; callers here pass the rest through). */
typedef void (*FeCbF)(int, void*);
extern void* lbl_8061977C;
extern const char lbl_805F4450[];
extern const char lbl_805F4EF4[];
extern "C" {
const char* fn_80090880__FP11Unk80090880(void* t, int id);
void fn_800E4234__FiiPUs(int a, int b, char* out);
void fn_800DFF0C(char* a, const char* b);
void fn_801321D4(FeW* o, void* self, FeCbF cb, int a, void* b, int c, int d, int e, const char* s1, const char* s2,
                 const char* s3, int f, int g, int h);
void fn_80134D68(void* p);
char* fn_8040B61C(char* dst, const char* src);
FeW* fn_800C8060(FeW* w);
int fn_80075948__18Unk8007B2B0_Screeni(void* g, int a);
void fn_8055F5A0(int a);
void fn_8055EAFC(int a);
void fn_8052844C(int a, void* x);
void fn_80528450(int a, void* x);
}

/* Screen with every word from +0x134 on read as an int (int-field accessors of these units). */
struct FeScrQ : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    int m168;
    int m16C;
    int m170;
    int m174;
    int m178;
    int m17C;
    int m180;
    int m184;
    int m188;
    int m18C;
    int m190;
    int m194;
    int m198;
    int m19C;
    int m1A0;
    int m1A4;
    int m1A8;
    int m1AC;
    int m1B0;
    int m1B4;
    int m1B8;
    int m1BC;
    int m1C0;
    int m1C4;
    int m1C8;
    int m1CC;
    int m1D0;
    int m1D4;
    int m1D8;
    int m1DC;
    int m1E0;
    int m1E4;
    int m1E8;
    int m1EC;
    int m1F0;
    int m1F4;
    int m1F8;
    int m1FC;
    int m200;
    int m204;
    int m208;
    int m20C;
    int m210;
    int m214;
    int m218;
    int m21C;
    int m220;
    int m224;
    int m228;
    int m22C;
    int m230;
    int m234;
    int m238;
    int m23C;
    int m240;
    int m244;
    int m248;
    int m24C;
    int m250;
    int m254;
    int m258;
    int m25C;
    int m260;
    int m264;
    int m268;
    int m26C;
    int m270;
    int m274;
    int m278;
    int m27C;
    int m280;
    int m284;
    int m288;
    int m28C;
    int m290;
    int m294;
    int m298;
    int m29C;
    int m2A0;
    int m2A4;
    int m2A8;
    int m2AC;
    int m2B0;
    int m2B4;
    int m2B8;
    int m2BC;
};

/* Sub-object of a list control (second base at +0xDC, vptr at +0x24 of it) whose slot 11 returns an int. */
struct FeSub11 : FeSubData {
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
    virtual int s11();
};

/* Record with a 4-entry id table at +0x78 and its count at +0x88 (fn_80514DF8). */
struct FeIdTab {
    char pad0[0x78];
    int m78[4];
    int m88;
};

/* Screen whose +0x134 word points at an id table indexed by the int at +0x140 (fn_804FFBAC). */
struct FeScrIdx : FeW {
    char pad40[0xF0];
    int m130;
    int* m134;
    char pad138[8];
    int m140;
};

/* Screen with a list of up to 12 0x28-byte records at +0x14C, count at +0x148 (fn_8050C42C, ctor fn_8050AB58). */
struct FeRec28 {
    int m0;
    char pad4[0x24];
};
struct FeRecList : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[0x148 - 0x134];
    int m148;
    FeRec28 m14C[12];
};

/* Id list object at +0x2A8 of the screen of fn_80516474: ids from +4, count at +0x84, a widget at +0x94. */
struct FeIdList {
    int m0;
    int m4[32];
    int m84;
    char pad88[0xC];
    FeW* m94;
};
struct FeP2A8 {
    char pad[0x2A8];
    FeIdList* m2A8;
};

/* Roster-main screen (ctor fn_804FE8AC, vtable lbl_80680960). m138 is a name buffer
 * (fn_804FF0F8 strcpy's into it, fn_804FF18C copies it out); m10EC/m10F0 are two widgets, m10F4
 * a list control whose second base object sits at +0xDC. */
struct FeScrRos : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[4];
    char m138[0x19C - 0x138];
    int m19C;
    char pad1A0[0x10EC - 0x1A0];
    FeW* m10EC;
    FeW* m10F0;
    FeW* m10F4;
};

#endif
