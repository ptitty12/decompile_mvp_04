/*
 * Shared types for the front-end overlay units fe/tu_80471EBC .. fe/tu_8048E6A0
 * (0x80471EBC..0x8048E6A0; reconstructed, placeholder names, nothing here comes from
 * original headers). Builds on fe_80459228.h (widget base FeW, FeWV slot views).
 */
#ifndef GAME_FE_80471EBC_H
#define GAME_FE_80471EBC_H

#include "game/fe_80459228.h"

/* The widget stored at byte offset `off` of a screen (nav-button wrappers: virtual call on it). */
static inline FeW* FeAt(void* x, int off)
{
    return *(FeW**)((char*)x + off);
}


/* Field accessors by byte offset, for screens whose layout is not worth a struct yet. */
static inline int& FeI(void* x, int off)
{
    return *(int*)((char*)x + off);
}
static inline float& FeF(void* x, int off)
{
    return *(float*)((char*)x + off);
}
static inline short& FeS(void* x, int off)
{
    return *(short*)((char*)x + off);
}
static inline unsigned char& FeB(void* x, int off)
{
    return *(unsigned char*)((char*)x + off);
}
static inline FeW*& FeWp(void* x, int off)
{
    return *(FeW**)((char*)x + off);
}
static inline void* FeP(void* x, int off)
{
    return (char*)x + off;
}
struct FeA70 {
    char pad0[0x70];
    int m70;
};
struct FeAFFC {
    char pad0[0xFFC];
    int mFFC;
};
struct FeNode4 {
    char pad0[0x10];
    FeA70* m10;
    FeAFFC* m14;
};
struct FeRoot4 {
    int m0;
    FeNode4* m4;
};
extern FeRoot4* lbl_806192E0;
static inline void*& FeVp(void* x, int off)
{
    return *(void**)((char*)x + off);
}
/* FeSub (fe_80459228.h) with the slots that take no arguments. */
struct FeSubB : FeSubData {
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
    virtual void s6();
};
typedef void (*FeCbT)(int, void*);

/* Widget view whose slot 91 takes (int a, int b, int c). */
struct FeWV91 : Unk800C7B40_Data {
    virtual ~FeWV91();
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
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
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
/* Element load with the base pointer first (lwzx base,index). */
static inline int FePick(char* b, int o)
{
    return *(int*)(b + o);
}

struct FeScrCell : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
    void* m138;
    void* m13C;
};
inline void FeSet(char* b, int o, int v)
{
    *(int*)(b + o) = v;
}
/* Fixed-size buffer object embedded at +0x148 of the screen of lbl_80676330 (vptr slot m10 swapped
 * through three tables by its inline ctor/reset code). */
struct FeArr {
    char* m0;
    int m4;
    int m8;
    int mC;
    const void* m10;
    int m14;
    void Reset()
    {
        m4 = 0;
        mC = 0;
    }
    void Reset2()
    {
        mC = 0;
        m4 = 0;
    }
};
struct FeScrArr : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    FeArr m148;
    char m160[1];
};

/* Widget view whose slot 90 takes (int a, int b, int c). */
struct FeWV90 : Unk800C7B40_Data {
    virtual ~FeWV90();
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
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90(int a, int b, int c);
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
/* FeSub (fe_80459228.h) with 21 slots (slot 21 returns int). */
struct FeSubC : FeSubData {
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
    virtual void s20();
    virtual int s21();
};
/* Sub-object view (vptr at +0x24 of the sub-object): slot 8 takes (int a). */
struct FeSubV8 : FeSubData {
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8(int a);
};

/* Widget view whose slot 29 takes (int a). */
struct FeWV29 : Unk800C7B40_Data {
    virtual ~FeWV29();
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
    virtual void s29(int a);
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
    virtual void s84();
    virtual void s85();
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

/* Widget view whose slot 93 takes (int a, int b). */
struct FeWV93 : Unk800C7B40_Data {
    virtual ~FeWV93();
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
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual int s93(int a, int b);
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

/* Widget view whose slot 30 takes (char* a). */
struct FeWV30 : Unk800C7B40_Data {
    virtual ~FeWV30();
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
    virtual void s30(char* a);
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
    virtual void s84();
    virtual void s85();
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
/* Sub-object view (vptr at +0x24 of the sub-object): slot 20 takes (int a, int b). */
struct FeSubV20 : FeSubData {
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
struct FeScrArr2 : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[0x370 - 0x134];
    int m370;
    int m374;
    int m378;
    int m37C;
    int m380;
    int m384;
    int m388;
    int m38C;
    int m390;
    int m394;
    int m398;
    int m39C;
    char pad3A0[0xD78 - 0x3A0];
    FeArr mD78;
    char mD90[1];
};

/* Widget view whose slot 51 takes (int a, int b). */
struct FeWV51 : Unk800C7B40_Data {
    virtual ~FeWV51();
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
    virtual void s51(int a, int b);
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
    virtual void s84();
    virtual void s85();
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

/* Widget view whose slot 28 takes (void* a). */
struct FeWV28 : Unk800C7B40_Data {
    virtual ~FeWV28();
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
    virtual void s28(void* a);
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
    virtual void s84();
    virtual void s85();
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
/* Sub-object view (vptr at +0x24 of the sub-object): slot 15 takes (). */
struct FeSubV15 : FeSubData {
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
};

/* BEGIN-HAND */
extern const char lbl_805F619C[];
extern const char lbl_80677818[];
extern "C" {
int fn_800B5758();
void fn_80473560(FeScrD* x);
void fn_80476A84(FeScrD* x);
void fn_8047C47C(void* p);
}
extern "C" void fn_80125BC0(void*);
extern "C" int fn_80476C44(void*);
extern "C" void fn_80477608(void*, void*, const char*);
extern "C" void fn_804834AC(void*, int);
extern "C" void fn_80483094(void*);
extern int lbl_806217E8[];
extern "C" void fn_8048E7E4(void*);
extern "C" void fn_8048E6A0(void*);
extern "C" void fn_804089B4(char*, const char*, ...);
extern "C" void fn_804873B4(void*);
extern "C" void fn_8055AC44(void*, int);
extern int lbl_806217D8[];
extern int lbl_806217C4[];
extern "C" void fn_8047D02C(void*);
extern "C" FeW* fn_800C8060();
extern "C" void* fn_8007F7D0__FP13Unk8007F198_BUi(void*, int);
extern "C" void fn_8007B780__18Unk8007B2B0_Screen(void*, void*, int);
extern "C" void fn_8055EAFC(void*);
extern "C" void fn_8047B15C(void*);
extern "C" void fn_8048BCE4(void*);
extern "C" int fn_8007A270__18Unk8007A4DC_Screeni(void*, int);
extern int lbl_805FD54C[];
extern int lbl_805FD4FC[];
extern "C" void* fn_8007F9B4__FP13Unk8007F198_C(void*);
extern "C" void* fn_8056681C(void*, void*);
extern "C" void fn_80560B44(void*, void*, int);
extern "C" void fn_8047E8E0(void*);
extern "C" void* fn_80548E1C(int, int);
extern "C" void fn_804A96A4(void*, void*, int, int, int, int, int, int);
extern "C" void fn_80487A64(void*, int);
extern "C" void fn_80487BD4(void*, int);
extern "C" void fn_80479C9C(void*, int);
extern "C" int fn_8007FDA8__FP13Unk8007F198_Cii(void*, int, int);
extern "C" FeW* fn_800C8038();
extern "C" FeW* fn_800C8044();
extern "C" void fn_80081BA8__FP13Unk8007FF8C_Yiii(void*, int, int, int);
extern "C" void fn_80480A58(void*);
extern "C" void* fn_800C8058();
extern "C" void fn_80483A9C(void*);
extern "C" FeW* fn_8048E8B0(void*);
extern "C" void fn_80484178(void*, int);
extern "C" void fn_8048432C(void*, int);
extern "C" void fn_8047C9A0(void*, int);
extern "C" int fn_8007B3E0__18Unk8007B2B0_Screenii(void*, int, void*);
extern "C" void* fn_8007B320__18Unk8007B2B0_Screenii(void*, int, void*);
extern "C" int fn_8007B8C4__18Unk8007B2B0_Screenii(void*, int, void*);
extern "C" void fn_805819A4(void*, void*, int);
extern "C" void fn_804757EC(void*);
extern "C" void fn_80475EF0(void*);
extern "C" void fn_8040074C(void*, int);
extern "C" void fn_8007F29C__FP13Unk8007F198_Aii(void*, int, int);
extern "C" void fn_8007F330__FP13Unk8007F198_Aii(void*, int, int);
extern "C" void fn_80486D7C(void*);
extern "C" void fn_800D0074(void*, int, int);
extern "C" void fn_80123858(void*, int, int);
extern "C" void fn_8047E244(void*);
extern "C" void fn_80480380(void*);
extern "C" void fn_80480380(void*);
extern "C" void fn_80486650(void*);
extern "C" void fn_80486650(void*);
extern "C" void fn_800C2034(void*, int);
extern "C" int fn_80075948__18Unk8007B2B0_Screeni(void*, int);
extern "C" void fn_8055F5A0(int);
extern "C" void fn_80562E34(int);
extern "C" int fn_800A3270(void*, int*, int*);
extern "C" void fn_80482DBC(void*);
extern "C" void fn_80122D40(void*, int, int, int, int, int, void*);
extern "C" void* fn_800C8054();
extern "C" void fn_80475FFC(void*);
extern "C" void fn_80086EC0(void*, int, int);
extern "C" int fn_8059897C();
extern "C" void fn_80487D44(void*, int, int);
extern "C" void* fn_800C8040();
extern "C" void fn_80472724(void*);
extern "C" void fn_80486800(void*);
extern "C" int fn_8007FB98__FP13Unk8007F198_Ciii(void*, int, int, int);
extern "C" void fn_8049A1F0(void*, int, int, int, int, int, int, int, int);
extern "C" void fn_80329FA0(void*, ...);
extern "C" void fn_800DD44C(void*, void*, int);

/* END-HAND */
/* auto: callees */
extern "C" {
void fn_8001BC4C__Fv();
void fn_8001BDAC__11Unk8001BC8Ci(int);
int fn_8006A1B4__11Unk80069F0C(void*);
int fn_8006BC74(void*, int);
int fn_800739E0(int, int, int, int, int);
float fn_80073C10(int, int, int, int, int);
void* fn_80074754(int, int, int, int);
float fn_800748D4(int, int, int, int);
int fn_80075094(int, int, int, int, int);
int fn_80075808__Fi(int);
int fn_80075CF0__Fii(int, int);
void fn_8007824C(int, int);
void fn_80079564(void*, int, int, void**);
void fn_800798BC(int, int, void*, float*, float*);
float fn_800799D0__18Unk8007B2B0_Screeni(void*, int);
int fn_80079A58__18Unk8007B2B0_Screenf(void*, float);
float fn_80079B14__18Unk8007B2B0_Screeni(void*, int);
float fn_80079B5C__18Unk8007B2B0_Screenii(void*, int, int);
float fn_80079E74__18Unk8007B2B0_Screeni(void*, void*);
float fn_80079EFC__18Unk8007B2B0_Screeni(void*, void*);
int fn_80079F90__18Unk8007B2B0_Screenf(void*, float);
void fn_8007A6A0__18Unk8007A4DC_Screenii(void*, int, int);
float fn_8007A768__18Unk8007A4DC_Screenii(void*, int, int);
void fn_8007A7C8__18Unk8007A4DC_ScreeniiPc(void*, int, int, void*);
void fn_8007A808__18Unk8007A4DC_Screeniii(void*, int, int, int);
char fn_8007AA84__18Unk8007A4DC_Screeniii(int, int, int, int);
char fn_8007AB9C__18Unk8007A4DC_Screenii(int, int, int);
int fn_8007B2B0__18Unk8007B2B0_Screen(void*);
void* fn_8007B2FC__18Unk8007B2B0_Screeni(void*, int);
void fn_8007B4A8__18Unk8007B2B0_Screeniii(void*, int, void*, int);
void fn_8007B924__18Unk8007B2B0_ScreeniiPc(void*, int, int, void*);
void fn_8007B9F4__18Unk8007B2B0_ScreeniiPc(void*, int, void*, void*);
void fn_8007DD38__FP13Unk8007DB74_Aiiii(int, int*, int, int, int);
int fn_8007E10C__FP13Unk8007DB74_A(int, int*, int*);
int fn_8007E154__FP13Unk8007DB74_Aii(int, int*, int);
int fn_8007E1F8__FP13Unk8007DB74_A(int, int*);
void fn_8007E34C__FP13Unk8007DB74_Aii(int, int*, int);
void fn_8007E39C__FP13Unk8007DB74_Aiii(int, int*, int, int);
void fn_8007E43C__FP13Unk8007DB74_Aii(int, int*, int);
int fn_8007E48C__FP13Unk8007DB74_Aii(int, int*, int);
void fn_8007E598__FP13Unk8007DB74_Aii(int, int*, int);
void fn_8007E618__FP13Unk8007DB74_Aii(int, int*, int);
void fn_8007E6D0__FP13Unk8007DB74_Aiii(int, int*, int, int);
int fn_8007E74C__FP13Unk8007DB74_Aii(int, int*, int);
int fn_8007E7A8__FP13Unk8007DB74_Ai(int, int*);
int fn_8007E7F0__FP13Unk8007DB74_Aii(int, int*, int, int);
void fn_8007E814__FP13Unk8007DB74_AiiPi(int, int*, int, int*);
void fn_8007E898__FP13Unk8007DB74_Aii(int, int*, int);
void fn_8007E918__FP13Unk8007DB74_Aiii(int, int*, int, int);
void fn_8007E994__FP13Unk8007DB74_Aii(int, int*, int);
int fn_8007EA4C__FP13Unk8007DB74_Aii(int, int*, int);
int fn_8007EAA8__FP13Unk8007DB74_Ai(int, int*);
int fn_8007EAF0__FP13Unk8007DB74_Aii(int, int*, int);
void fn_8007EB14__FP13Unk8007DB74_AiiPi(int, int*, int, int*);
void fn_8007EB98__FP13Unk8007DB74_Aii(int, int*, int);
void fn_8007EC18__FP13Unk8007DB74_Aiii(int, int*, int, int);
void fn_8007EC94__FP13Unk8007DB74_Aii(int, int*, int);
int fn_8007ED4C__FP13Unk8007DB74_Aii(int, int*, int);
int fn_8007EDA8__FP13Unk8007DB74_Ai(int, int*);
int fn_8007EDF0__FP13Unk8007DB74_Aii(int, int*, int);
void fn_8007EE14__FP13Unk8007DB74_AiiPi(int, int*, int, int*);
void fn_8007EE98__FP13Unk8007DB74_Aii(int, int*, int);
void fn_8007EF18__FP13Unk8007DB74_Aiii(int, int*, int, int);
void fn_8007EF94__FP13Unk8007DB74_Aii(int, int*, int);
int fn_8007F04C__FP13Unk8007DB74_Aii(int, int*, int);
int fn_8007F0A8__FP13Unk8007DB74_Ai(int, int*);
int fn_8007F0F0__FP13Unk8007DB74_Aii(int, int*, int);
void fn_8007F114__FP13Unk8007DB74_AiiPi(int, int*, int, int*);
unsigned fn_8007F198__FP13Unk8007F198_A(int, int);
unsigned fn_8007FB2C__FP13Unk8007F198_Ci(int, int);
unsigned fn_8007FB40__FP13Unk8007F198_Ci(int, int);
int fn_8007FBC0__FP13Unk8007F198_Cii(int, unsigned, int);
unsigned fn_8007FBDC__FP13Unk8007F198_Cii(int, unsigned, int);
int fn_8007FD2C__FP13Unk8007F198_Ciii(int, int, int, int);
void* fn_8007FE04__FP13Unk8007F198_D(void*, void**);
int fn_80081B60__FP13Unk8007FF8C_Y(int);
unsigned char* fn_80081D08__FP13Unk8007FF8C_Yi(int, int);
int fn_80083F6C__Fi(int);
int fn_80084014__Fii(int, int);
int fn_80084114__Fi(int);
int fn_80084408();
int fn_80084728(int);
int fn_80089AA0(void*, int, unsigned char);
int fn_8008CFD8(void*, int, int);
int fn_80090880__FP11Unk80090880(int, int);
int fn_800968C0(void*, int, int);
int fn_80097148(void*, int);
int fn_800971C8(void*, int);
int fn_80097210(void*, int);
int fn_80097288(void*, int);
int fn_80097300(void*, int);
int fn_8009764C(void*, int, unsigned char, int);
float fn_80097678(void*, int, unsigned char, int);
int fn_8009841C(void*, int, int);
int fn_80099704(void*);
void fn_8009C6CC();
float fn_8009FE90(void*, int, int);
int fn_800A1960(void*);
void* fn_800A1978(void*);
void* fn_800A199C(void*);
int fn_800A1A6C(void*);
int fn_800A2E6C(void*);
int fn_800A2EB4(void*);
int fn_800A2EFC(int, int*);
void fn_800A2F9C(void*, int, void**);
void fn_800A3490(void*, int, int, int);
void fn_800A3578(void*);
int fn_800A35A8(void*);
void fn_800A3640(void*);
void fn_800A3670(void*);
float fn_800A39C4(void*, void*);
int fn_800A3C98(void*, int, void*);
int fn_800A4558(void*, int);
int fn_800A4EA4(void*);
int fn_800B5520(int);
int fn_800B56C4();
int fn_800B57EC();
void fn_800B5BD4();
int* fn_800B5CBC();
void fn_800B8144();
void fn_800B82D0(int, int);
void fn_800B83F8(int, int);
int fn_800C203C(int);
void fn_800C3ED4(int, void*, int);
void* fn_800C8048();
void fn_800D6FA0__Fv();
float fn_800D7008__FP15Unk800D7008_Obji(void*);
void fn_800DB7DC__Fv();
void fn_800DC50C(float, float);
void fn_800DC580(float);
void fn_800DD204(void*, int);
void fn_800DD344(void*, void*);
void fn_800DD800(void*, void*, int, int);
void fn_800DE440(void*, int, int);
char fn_800DEDC0__Fii(int, int);
void fn_800DEE38(int, int);
int fn_800DEEB0(int, int);
int fn_800DF034__FPc(void*);
void fn_800DF254(void*, int, int, float);
void fn_800DFE40(void*, int);
void fn_800DFF0C(void*, int);
float fn_800E0164(float);
char fn_800E01C8__Ff();
void fn_800E0AD4(int, int, int, int);
int fn_800E190C__Fi(void*);
void fn_800E2F24(void*, int, int);
void fn_800E31A8(void*, int, int);
void fn_800E4234(int*, int, void*);
void fn_800E442C(int);
void fn_800E4C1C(void*, void*);
int fn_800E4FDC__Fv();
void fn_800E5380();
int fn_800E5D74(int);
int fn_800E5E4C();
int fn_800E5F38(int);
int fn_800E60E0__Fi();
void fn_80119F48(void*, float);
void fn_80119FF0(void*, float);
void fn_80124B40(void*, void*, int, int, void*);
void fn_80125128(void*, int);
void fn_80125154(void*, int);
void fn_80125AAC(int);
void fn_8012E1C4(int, int, int);
void fn_801321D4(void*, void*, void*, void*, void*, float*, int, int, int);
void fn_8014DBA0(void*, int, int, int, int);
void fn_8032A0C0(void*, unsigned);
void fn_80402EF8(float*, void*);
void fn_80403144(void*, int);
void fn_804031BC(void*, void*, void**);
void fn_804031F8(void*, int, int);
void fn_8040321C(void*, int, void*, void*);
void fn_80403DE4(void*, void*, void*, void*, void*, void*);
int fn_8040ABA0();
void fn_8040B70C(void*);
void fn_804707B8(void*, int);
void* fn_8048E76C(void*);
void* fn_8048E7A8(void*);
void* fn_8048E8EC(void*);
void fn_8049A988(int);
void fn_804A763C(void*, int);
void fn_804A768C();
void fn_804A7760(void*);
void fn_80535360(void**, int);
void fn_80535764(void**, int);
void fn_805362AC(void**, int);
void fn_805364E0(void**, int);
void fn_80536990(void*, int);
void fn_80536D68(void**, int*);
void fn_80539128(void**, int);
int fn_80546B18(int, int, int);
int fn_80546CA8(int, int, int);
void fn_80548BA0(int, int, int, float*, int, int, void*);
void fn_80548C7C(void*, int, void*);
int* fn_80548E2C(void*, int);
void* fn_80548E48(void*, int);
int fn_805494DC(int, int, int, int, int, int, int, float);
int fn_80553260();
int fn_805559D4(int, void*, int, int);
void fn_80556348(void*);
int fn_805563C4(void*);
int fn_80556410(void*);
void fn_80563F3C(int, int, int, float*, float**, int*, int, int);
int fn_8056469C(int, int, int, int, int, float, float);
int fn_8056A2F8(int, int, int, int, int, void*, int, int);
int fn_8056A580(int, int, int, int);
int fn_8056A5B0(int, int, int, int);
void* fn_8056A5F4(int, int, int, void*);
int fn_8056AAE4(int, int, int);
int fn_8056AC44(int, int, int);
int fn_8056AD54(int, int);
int fn_8056ADD4(int, int, void*, int, int);
int fn_8056B658(int, int, void*);
int fn_8057CE00(int);
int fn_8057CF60(int);
int* fn_8057CFA8(int);
void fn_80590CA8(int);
float fn_80592288(void*, int);
float fn_805922EC(void*, int);
}
/* auto: data */
extern char lbl_805F37A4[];
extern char lbl_805F4450[];
extern char lbl_805F4ECC[];
extern char lbl_805F4ED0[];
extern char lbl_805F4EF4[];
extern char lbl_805F4F20[];
extern char lbl_805F4F48[];
extern char lbl_805F4F8C[];
extern char lbl_805F4FAC[];
extern char lbl_805F5004[];
extern char lbl_805F5010[];
extern char lbl_805F5024[];
extern char lbl_805F5050[];
extern char lbl_805F5058[];
extern char lbl_805F5060[];
extern char lbl_805F5068[];
extern char lbl_805F5074[];
extern char lbl_805F5080[];
extern char lbl_805F5088[];
extern char lbl_805F5098[];
extern char lbl_805F50A4[];
extern char lbl_805F50B4[];
extern char lbl_805F50C0[];
extern char lbl_805F50D0[];
extern char lbl_805F50E0[];
extern char lbl_805F50F0[];
extern char lbl_805F5100[];
extern char lbl_805F510C[];
extern char lbl_805F5118[];
extern char lbl_805F511C[];
extern char lbl_805F514C[];
extern char lbl_805F51DC[];
extern char lbl_805F51EC[];
extern char lbl_805F5258[];
extern char lbl_805F5274[];
extern char lbl_805F52B4[];
extern char lbl_805F52C4[];
extern char lbl_805F52F0[];
extern char lbl_805F5324[];
extern char lbl_805F532C[];
extern char lbl_805F5338[];
extern char lbl_805F5340[];
extern char lbl_805F5348[];
extern char lbl_805F5350[];
extern char lbl_805F535C[];
extern char lbl_805F5364[];
extern char lbl_805F538C[];
extern char lbl_805F5394[];
extern char lbl_805F54DC[];
extern char lbl_805F54F8[];
extern char lbl_805F5500[];
extern char lbl_805F5530[];
extern char lbl_805F55C8[];
extern char lbl_805F55D4[];
extern char lbl_805F55DC[];
extern char lbl_805F55E4[];
extern char lbl_805F55F0[];
extern char lbl_805F55F8[];
extern char lbl_805F5600[];
extern char lbl_805F5644[];
extern char lbl_805F5818[];
extern char lbl_805F5828[];
extern char lbl_805F5840[];
extern char lbl_805F5854[];
extern char lbl_805F588C[];
extern char lbl_805F58F4[];
extern char lbl_805F59CC[];
extern char lbl_805F5ABC[];
extern char lbl_805F5BA4[];
extern char lbl_805F5BAC[];
extern char lbl_805F5C34[];
extern char lbl_805F5C94[];
extern char lbl_805F5D8C[];
extern char lbl_805F5D94[];
extern char lbl_805F5DA0[];
extern char lbl_805F5DA8[];
extern float lbl_805F5DB0;
extern char lbl_805F5DB4[];
extern float lbl_805F5DBC;
extern float lbl_805F5DC0;
extern char lbl_805F5DC4[];
extern char lbl_805F5DD4[];
extern char lbl_805F5DE4[];
extern char lbl_805F5E00[];
extern char lbl_805F5E08[];
extern char lbl_805F5E18[];
extern char lbl_805F5E28[];
extern char lbl_805F5E44[];
extern char lbl_805F5E58[];
extern char lbl_805F5E68[];
extern char lbl_805F5E74[];
extern char lbl_805F5E7C[];
extern char lbl_805F5E84[];
extern char lbl_805F5E8C[];
extern char lbl_805F5E94[];
extern char lbl_805F5E9C[];
extern char lbl_805F5EA4[];
extern char lbl_805F5EB4[];
extern char lbl_805F5EB8[];
extern float lbl_805F5EC0;
extern float lbl_805F5EC4;
extern float lbl_805F5EC8;
extern float lbl_805F5ECC;
extern char lbl_805F5ED0[];
extern double lbl_805F5EE0;
extern float lbl_805F5EE8;
extern char lbl_805F5EEC[];
extern float lbl_805F5EF4;
extern double lbl_805F5EF8;
extern char lbl_805F5F00[];
extern char lbl_805F5F08[];
extern char lbl_805F5F10[];
extern char lbl_805F5F20[];
extern float lbl_805F5F30;
extern char lbl_805F5F34[];
extern char lbl_805F5F48[];
extern char lbl_805F5F5C[];
extern char lbl_805F5F80[];
extern char lbl_805F5FA4[];
extern char lbl_805F5FC8[];
extern char lbl_805F5FEC[];
extern char lbl_805F5FF8[];
extern char lbl_805F6004[];
extern char lbl_805F600C[];
extern char lbl_805F6014[];
extern char lbl_805F601C[];
extern char lbl_805F6028[];
extern char lbl_805F6030[];
extern char lbl_805F603C[];
extern char lbl_805F6048[];
extern char lbl_805F6050[];
extern char lbl_805F605C[];
extern double lbl_805F6068;
extern float lbl_805F6070;
extern char lbl_805F6074[];
extern char lbl_805F607C[];
extern char lbl_805F6080[];
extern char lbl_805F6090[];
extern char lbl_805F609C[];
extern char lbl_805F60AC[];
extern char lbl_805F60BC[];
extern char lbl_805F60D4[];
extern char lbl_805F60EC[];
extern char lbl_805F60F4[];
extern char lbl_805F6100[];
extern char lbl_805F6110[];
extern char lbl_805F6120[];
extern char lbl_805F6130[];
extern char lbl_805F6140[];
extern char lbl_805F614C[];
extern char lbl_805F6158[];
extern char lbl_805F6164[];
extern char lbl_805F6170[];
extern char lbl_805F6174[];
extern char lbl_805F6184[];
extern char lbl_805F618C[];
extern float lbl_805F61AC;
extern double lbl_805F61B0;
extern float lbl_805F61B8;
extern int lbl_805F61BC[];
extern double lbl_805F61D0;
extern float lbl_805F61D8;
extern char lbl_805F61DC[];
extern char lbl_805F61E8[];
extern char lbl_805F61F0[];
extern char lbl_805F61FC[];
extern char lbl_805F6200[];
extern char lbl_805F6208[];
extern char lbl_805F6210[];
extern char lbl_805F6218[];
extern char lbl_805F6224[];
extern char lbl_805F6230[];
extern char lbl_805F623C[];
extern char lbl_805F6248[];
extern char lbl_805F6254[];
extern char lbl_805F6268[];
extern char lbl_805F6274[];
extern char lbl_805F6288[];
extern char lbl_805F6294[];
extern char lbl_805F629C[];
extern char lbl_805F62A8[];
extern char lbl_805F62B4[];
extern char lbl_805F62BC[];
extern char lbl_805F62C4[];
extern char lbl_805F62CC[];
extern char lbl_805F62D4[];
extern char lbl_805F62F0[];
extern char lbl_805F630C[];
extern char lbl_805F631C[];
extern char lbl_805F632C[];
extern char lbl_805F6338[];
extern char lbl_805F6344[];
extern char lbl_805F6350[];
extern char lbl_805F635C[];
extern char lbl_805F636C[];
extern char lbl_805F637C[];
extern char lbl_805F6388[];
extern char lbl_805F6390[];
extern char lbl_805F63A4[];
extern char lbl_805F63B8[];
extern char lbl_805F63D4[];
extern char lbl_805F63F4[];
extern char lbl_805F6418[];
extern char lbl_805F6438[];
extern char lbl_805F645C[];
extern char lbl_805F6464[];
extern char lbl_805F646C[];
extern char lbl_805F6480[];
extern char lbl_805F648C[];
extern char lbl_805F6494[];
extern char lbl_805F64A0[];
extern float lbl_805F64AC;
extern float lbl_805F64B0;
extern char lbl_805F64B4[];
extern char lbl_805F64C0[];
extern char lbl_805F64CC[];
extern char lbl_805F64DC[];
extern double lbl_805F64E8;
extern char lbl_805F64F0[];
extern char lbl_805F64FC[];
extern char lbl_805F650C[];
extern char lbl_805F6518[];
extern char lbl_805F6524[];
extern char lbl_805F6530[];
extern char lbl_805F653C[];
extern char lbl_805F6548[];
extern char lbl_805F6554[];
extern char lbl_805F6564[];
extern char lbl_805F6570[];
extern char lbl_805F657C[];
extern char lbl_805F6588[];
extern char lbl_805F6598[];
extern char lbl_805F65A4[];
extern char lbl_805F65AC[];
extern char lbl_805F65D8[];
extern char lbl_805F6604[];
extern char lbl_805F6614[];
extern char lbl_805F6620[];
extern char lbl_805F662C[];
extern char lbl_805F6634[];
extern char lbl_805F663C[];
extern char lbl_805F6644[];
extern char lbl_805F664C[];
extern char lbl_805F665C[];
extern char lbl_805F6668[];
extern char lbl_805F6674[];
extern char lbl_805F6680[];
extern char lbl_805F6688[];
extern char lbl_805F6694[];
extern double lbl_805F66A0;
extern float lbl_805F66A8;
extern char lbl_805F66AC[];
extern float lbl_805F66B8;
extern char lbl_805F66BC[];
extern char lbl_805FD4F0[];
extern int lbl_8061977C;
extern int lbl_806217C0;
extern char lbl_8064A3B8[];
extern char lbl_8064A440[];
extern char lbl_8064A4C8[];
extern char lbl_8064A550[];
extern char lbl_8064B298[];
extern char lbl_8065C1B0[];
extern char lbl_80676330[];
extern char lbl_806765D8[];
extern char lbl_80676880[];
extern char lbl_80676B28[];
extern char lbl_80676DD0[];
extern char lbl_80677078[];
extern char lbl_80677AC0[];
extern char lbl_80677D68[];
extern char lbl_80678010[];
extern char lbl_806782B8[];
extern char lbl_80678560[];
extern char lbl_80678808[];
extern char lbl_80678AB0[];
extern char lbl_80682508[];

/* BEGIN-PROTOS (functions defined in the units) */
#ifndef NOPROTO_fn_80471EBC
extern "C" FeScrH* fn_80471EBC(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_804726A0
extern "C" void fn_804726A0(void* x);
#endif
#ifndef NOPROTO_fn_80472BBC
extern "C" int fn_80472BBC(void* x);
#endif
#ifndef NOPROTO_fn_80472BF8
extern "C" int fn_80472BF8(void* x);
#endif
#ifndef NOPROTO_fn_80472C34
extern "C" int fn_80472C34(void* x);
#endif
#ifndef NOPROTO_fn_80472C70
extern "C" int fn_80472C70(void* x);
#endif
#ifndef NOPROTO_fn_80472CAC
extern "C" int fn_80472CAC(FeW* x, FeW* w, int b, int c);
#endif
#ifndef NOPROTO_fn_80472D24
extern "C" void fn_80472D24(void* x, int w);
#endif
#ifndef NOPROTO_fn_80472E04
extern "C" FeScrH* fn_80472E04(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_804730A4
extern "C" void fn_804730A4(void* x);
#endif
#ifndef NOPROTO_fn_804731C4
extern "C" void fn_804731C4(FeScrD* x);
#endif
#ifndef NOPROTO_fn_804731E4
extern "C" int fn_804731E4(void* x);
#endif
#ifndef NOPROTO_fn_80473220
extern "C" int fn_80473220(void* x);
#endif
#ifndef NOPROTO_fn_8047325C
extern "C" int fn_8047325C(void* x);
#endif
#ifndef NOPROTO_fn_80473298
extern "C" int fn_80473298(void* x);
#endif
#ifndef NOPROTO_fn_804732D4
extern "C" int fn_804732D4(FeW* x);
#endif
#ifndef NOPROTO_fn_8047336C
extern "C" int fn_8047336C(FeW* x, int a, int b, int c);
#endif
#ifndef NOPROTO_fn_804733C4
extern "C" void fn_804733C4(void* x, char* buf);
#endif
#ifndef NOPROTO_fn_80473440
extern "C" void fn_80473440(void* x);
#endif
#ifndef NOPROTO_fn_80473560
extern "C" void fn_80473560(FeScrD* x);
#endif
#ifndef NOPROTO_fn_80473630
extern "C" void fn_80473630(FeScrD* x);
#endif
#ifndef NOPROTO_fn_80473650
extern "C" void fn_80473650(int a, void* b);
#endif
#ifndef NOPROTO_fn_80473684
extern "C" void fn_80473684(int a, FeW* x);
#endif
#ifndef NOPROTO_fn_80473718
extern "C" int fn_80473718(void* x);
#endif
#ifndef NOPROTO_fn_804739BC
extern "C" void fn_804739BC(FeW* x);
#endif
#ifndef NOPROTO_fn_80473A98
extern "C" void fn_80473A98(void* x, int a);
#endif
#ifndef NOPROTO_fn_80473AE8
extern "C" FeScrH* fn_80473AE8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_80473D44
extern "C" int fn_80473D44(void* x);
#endif
#ifndef NOPROTO_fn_80473E48
extern "C" int fn_80473E48(FeScrK* x);
#endif
#ifndef NOPROTO_fn_80473EB4
extern "C" int fn_80473EB4(void* x);
#endif
#ifndef NOPROTO_fn_80473EF0
extern "C" int fn_80473EF0(void* x);
#endif
#ifndef NOPROTO_fn_80473F2C
extern "C" int fn_80473F2C(void* x);
#endif
#ifndef NOPROTO_fn_80473F68
extern "C" int fn_80473F68(void* x);
#endif
#ifndef NOPROTO_fn_80473FA4
extern "C" int fn_80473FA4(void* x);
#endif
#ifndef NOPROTO_fn_804740A8
extern "C" FeScrH* fn_804740A8(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_80474660
extern "C" int fn_80474660(FeScrK* x);
#endif
#ifndef NOPROTO_fn_804746CC
extern "C" int fn_804746CC(FeW* x);
#endif
#ifndef NOPROTO_fn_804747E8
extern "C" int fn_804747E8(void* x);
#endif
#ifndef NOPROTO_fn_80474824
extern "C" int fn_80474824(void* x);
#endif
#ifndef NOPROTO_fn_80474860
extern "C" int fn_80474860(void* x);
#endif
#ifndef NOPROTO_fn_8047489C
extern "C" int fn_8047489C(void* x);
#endif
#ifndef NOPROTO_fn_804748D8
extern "C" int fn_804748D8(void* x);
#endif
#ifndef NOPROTO_fn_80474914
extern "C" void fn_80474914(void* x, char* buf);
#endif
#ifndef NOPROTO_fn_80474988
extern "C" void fn_80474988(void* x, int a);
#endif
#ifndef NOPROTO_fn_804749D8
extern "C" void fn_804749D8(FeW* x);
#endif
#ifndef NOPROTO_fn_80474A98
extern "C" void fn_80474A98(int a);
#endif
#ifndef NOPROTO_fn_80474AF8
extern "C" void fn_80474AF8(FeW* x);
#endif
#ifndef NOPROTO_fn_80474BB8
extern "C" void fn_80474BB8(int a);
#endif
#ifndef NOPROTO_fn_80474C44
extern "C" FeScrH* fn_80474C44(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_804753E8
extern "C" void fn_804753E8(FeW* x, int sel, int c);
#endif
#ifndef NOPROTO_fn_804754C0
extern "C" int fn_804754C0(void* x);
#endif
#ifndef NOPROTO_fn_804754FC
extern "C" int fn_804754FC(void* x);
#endif
#ifndef NOPROTO_fn_80475538
extern "C" int fn_80475538(void* x);
#endif
#ifndef NOPROTO_fn_80475574
extern "C" int fn_80475574(void* x);
#endif
#ifndef NOPROTO_fn_804755B0
extern "C" int fn_804755B0(void* x);
#endif
#ifndef NOPROTO_fn_804755EC
extern "C" int fn_804755EC(void* x);
#endif
#ifndef NOPROTO_fn_80475628
extern "C" int fn_80475628(void* x);
#endif
#ifndef NOPROTO_fn_80475664
extern "C" int fn_80475664(void* x);
#endif
#ifndef NOPROTO_fn_804756A0
extern "C" void fn_804756A0(void* x, int a);
#endif
#ifndef NOPROTO_fn_804756F0
extern "C" void fn_804756F0(void* x);
#endif
#ifndef NOPROTO_fn_80475774
extern "C" int fn_80475774(int a, int b, int c);
#endif
#ifndef NOPROTO_fn_80476134
extern "C" int fn_80476134(int x, int b);
#endif
#ifndef NOPROTO_fn_80476178
extern "C" int fn_80476178(int x, int b);
#endif
#ifndef NOPROTO_fn_804761D0
extern "C" int fn_804761D0(int x, int b);
#endif
#ifndef NOPROTO_fn_80476220
extern "C" int fn_80476220(int x, int b);
#endif
#ifndef NOPROTO_fn_804766FC
extern "C" void fn_804766FC(void* x);
#endif
#ifndef NOPROTO_fn_80476A28
extern "C" void fn_80476A28(int a, void* x);
#endif
#ifndef NOPROTO_fn_80476C24
extern "C" void fn_80476C24(FeScrD* x);
#endif
#ifndef NOPROTO_fn_80476DB4
extern "C" int fn_80476DB4(void* x);
#endif
#ifndef NOPROTO_fn_80476DEC
extern "C" void fn_80476DEC(void* x, int a);
#endif
#ifndef NOPROTO_fn_80476E50
extern "C" int fn_80476E50(FeW* x, int a);
#endif
#ifndef NOPROTO_fn_80477000
extern "C" FeScrH* fn_80477000(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_80477068
extern "C" void fn_80477068(FeScrD* x);
#endif
#ifndef NOPROTO_fn_80477418
extern "C" void fn_80477418(void* x);
#endif
#ifndef NOPROTO_fn_80477498
extern "C" void fn_80477498(FeW* x);
#endif
#ifndef NOPROTO_fn_80477540
extern "C" void fn_80477540(FeScrD* x);
#endif
#ifndef NOPROTO_fn_80477560
extern "C" void fn_80477560(void* x);
#endif
#ifndef NOPROTO_fn_80477594
extern "C" void fn_80477594(void* x);
#endif
#ifndef NOPROTO_fn_804775D0
extern "C" void fn_804775D0(void* x);
#endif
#ifndef NOPROTO_fn_80477C04
extern "C" void fn_80477C04(void* x, void* y, void* z);
#endif
#ifndef NOPROTO_fn_80477C54
extern "C" int fn_80477C54(void);
#endif
#ifndef NOPROTO_fn_80477E48
extern "C" int fn_80477E48(FeW* x, char* y);
#endif
#ifndef NOPROTO_fn_80477EE4
extern "C" int fn_80477EE4(FeW* x);
#endif
#ifndef NOPROTO_fn_80477F44
extern "C" int fn_80477F44(FeW* x);
#endif
#ifndef NOPROTO_fn_80477FA4
extern "C" int fn_80477FA4(FeW* x);
#endif
#ifndef NOPROTO_fn_80478004
extern "C" int fn_80478004(FeW* x);
#endif
#ifndef NOPROTO_fn_80478064
extern "C" int fn_80478064(FeW* x, int a);
#endif
#ifndef NOPROTO_fn_8047809C
extern "C" FeScrH* fn_8047809C(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_80479378
extern "C" void fn_80479378(int a, FeW* x);
#endif
#ifndef NOPROTO_fn_80479480
extern "C" void fn_80479480(void* x);
#endif
#ifndef NOPROTO_fn_804795D0
extern "C" int fn_804795D0(char* x);
#endif
#ifndef NOPROTO_fn_80479614
extern "C" void fn_80479614(void* x, int a);
#endif
#ifndef NOPROTO_fn_804799E8
extern "C" int fn_804799E8(char* x);
#endif
#ifndef NOPROTO_fn_80479A28
extern "C" void fn_80479A28(int a);
#endif
#ifndef NOPROTO_fn_8047A384
extern "C" void fn_8047A384(FeW* x);
#endif
#ifndef NOPROTO_fn_8047AA20
extern "C" void fn_8047AA20(char* x);
#endif
#ifndef NOPROTO_fn_8047AD30
extern "C" void fn_8047AD30(int u, FeW* x, int b, int c, int d);
#endif
#ifndef NOPROTO_fn_8047AE14
extern "C" void fn_8047AE14(void* x, int v);
#endif
#ifndef NOPROTO_fn_8047AE1C
extern "C" int fn_8047AE1C(void* x);
#endif
#ifndef NOPROTO_fn_8047AE9C
extern "C" int fn_8047AE9C(void* x);
#endif
#ifndef NOPROTO_fn_8047AF1C
extern "C" int fn_8047AF1C(void* x);
#endif
#ifndef NOPROTO_fn_8047AF9C
extern "C" int fn_8047AF9C(void* x);
#endif
#ifndef NOPROTO_fn_8047B01C
extern "C" void fn_8047B01C(void* x);
#endif
#ifndef NOPROTO_fn_8047B064
extern "C" int fn_8047B064(FeW* x, int a);
#endif
#ifndef NOPROTO_fn_8047B9AC
extern "C" int fn_8047B9AC(void* x);
#endif
#ifndef NOPROTO_fn_8047BA20
extern "C" int fn_8047BA20(void* x);
#endif
#ifndef NOPROTO_fn_8047BA94
extern "C" int fn_8047BA94(void* x);
#endif
#ifndef NOPROTO_fn_8047BB10
extern "C" int fn_8047BB10(void* x);
#endif
#ifndef NOPROTO_fn_8047BB8C
extern "C" FeScrArr2* fn_8047BB8C(FeScrArr2* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_8047BF48
extern "C" void fn_8047BF48(FeScrD* x);
#endif
#ifndef NOPROTO_fn_8047BF70
extern "C" int fn_8047BF70(void* x);
#endif
#ifndef NOPROTO_fn_8047C004
extern "C" void fn_8047C004(void* x, int sel);
#endif
#ifndef NOPROTO_fn_8047C058
extern "C" int fn_8047C058(void* x);
#endif
#ifndef NOPROTO_fn_8047C0E8
extern "C" int fn_8047C0E8(void* x);
#endif
#ifndef NOPROTO_fn_8047C124
extern "C" int fn_8047C124(void* x);
#endif
#ifndef NOPROTO_fn_8047C1B4
extern "C" int fn_8047C1B4(void* x);
#endif
#ifndef NOPROTO_fn_8047C1F0
extern "C" int fn_8047C1F0(void* x);
#endif
#ifndef NOPROTO_fn_8047C22C
extern "C" int fn_8047C22C(void* x);
#endif
#ifndef NOPROTO_fn_8047C268
extern "C" int fn_8047C268(void* x);
#endif
#ifndef NOPROTO_fn_8047C2A4
extern "C" int fn_8047C2A4(void* x);
#endif
#ifndef NOPROTO_fn_8047C2E0
extern "C" int fn_8047C2E0(void* x, FeW* w, int b, int c, int d);
#endif
#ifndef NOPROTO_fn_8047C444
extern "C" int fn_8047C444(char* x, int key);
#endif
#ifndef NOPROTO_fn_8047C900
extern "C" void fn_8047C900(void* x);
#endif
#ifndef NOPROTO_fn_8047C958
extern "C" void fn_8047C958(char* buf, int v);
#endif
#ifndef NOPROTO_fn_8047CDC0
extern "C" void fn_8047CDC0(void* x);
#endif
#ifndef NOPROTO_fn_8047CE94
extern "C" void fn_8047CE94(void* x, FeW* w, int b, int c);
#endif
#ifndef NOPROTO_fn_8047CF5C
extern "C" void fn_8047CF5C(void* x);
#endif
#ifndef NOPROTO_fn_8047D150
extern "C" void fn_8047D150();
#endif
#ifndef NOPROTO_fn_8047D1AC
extern "C" void fn_8047D1AC(void* x, float v);
#endif
#ifndef NOPROTO_fn_8047D1DC
extern "C" float fn_8047D1DC(void* x);
#endif
#ifndef NOPROTO_fn_8047D21C
extern "C" void fn_8047D21C(char* x, int i, char v);
#endif
#ifndef NOPROTO_fn_8047D228
extern "C" unsigned char fn_8047D228(char* x, int i);
#endif
#ifndef NOPROTO_fn_8047D234
extern "C" void fn_8047D234(char* x, int i, char v);
#endif
#ifndef NOPROTO_fn_8047D240
extern "C" unsigned char fn_8047D240(char* x, int i);
#endif
#ifndef NOPROTO_fn_8047D3D0
extern "C" FeScrH* fn_8047D3D0(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_8047DC70
extern "C" int fn_8047DC70(void* x);
#endif
#ifndef NOPROTO_fn_8047DD0C
extern "C" int fn_8047DD0C(void* x);
#endif
#ifndef NOPROTO_fn_8047E028
extern "C" int fn_8047E028(void* x);
#endif
#ifndef NOPROTO_fn_8047E078
extern "C" int fn_8047E078(void* x);
#endif
#ifndef NOPROTO_fn_8047E0B4
extern "C" int fn_8047E0B4(void* x);
#endif
#ifndef NOPROTO_fn_8047E104
extern "C" int fn_8047E104(void* x);
#endif
#ifndef NOPROTO_fn_8047E140
extern "C" int fn_8047E140(void* x);
#endif
#ifndef NOPROTO_fn_8047E19C
extern "C" int fn_8047E19C(void* x);
#endif
#ifndef NOPROTO_fn_8047E204
extern "C" int fn_8047E204(void);
#endif
#ifndef NOPROTO_fn_8047E20C
extern "C" int fn_8047E20C(void);
#endif
#ifndef NOPROTO_fn_8047E214
extern "C" int fn_8047E214(void);
#endif
#ifndef NOPROTO_fn_8047E21C
extern "C" int fn_8047E21C(void);
#endif
#ifndef NOPROTO_fn_8047E224
extern "C" int fn_8047E224(void);
#endif
#ifndef NOPROTO_fn_8047E22C
extern "C" int fn_8047E22C(void);
#endif
#ifndef NOPROTO_fn_8047E234
extern "C" int fn_8047E234(void);
#endif
#ifndef NOPROTO_fn_8047E23C
extern "C" int fn_8047E23C(void);
#endif
#ifndef NOPROTO_fn_8047E490
extern "C" void fn_8047E490(void* x);
#endif
#ifndef NOPROTO_fn_8047E5B0
extern "C" int fn_8047E5B0(void* x, int a, int b, int c);
#endif
#ifndef NOPROTO_fn_8047E660
extern "C" int fn_8047E660(FeW* x, FeW* w, int b, int c);
#endif
#ifndef NOPROTO_fn_8047E758
extern "C" void fn_8047E758(void* x, int a);
#endif
#ifndef NOPROTO_fn_8047E7E8
extern "C" void fn_8047E7E8(void* x, int wi);
#endif
#ifndef NOPROTO_fn_8047F0A4
extern "C" void fn_8047F0A4(void* x, int a);
#endif
#ifndef NOPROTO_fn_8047F1C0
extern "C" void fn_8047F1C0(void* x, int a);
#endif
#ifndef NOPROTO_fn_8047F2DC
extern "C" void fn_8047F2DC(char* x, int a, int b);
#endif
#ifndef NOPROTO_fn_8047F3B0
extern "C" int fn_8047F3B0(void* x);
#endif
#ifndef NOPROTO_fn_8047F450
extern "C" int fn_8047F450(void* x);
#endif
#ifndef NOPROTO_fn_8047F4CC
extern "C" int fn_8047F4CC(void* x);
#endif
#ifndef NOPROTO_fn_8047F508
extern "C" FeScrH* fn_8047F508(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_8047FD94
extern "C" int fn_8047FD94(void* x);
#endif
#ifndef NOPROTO_fn_8047FE30
extern "C" int fn_8047FE30(FeScrB* x);
#endif
#ifndef NOPROTO_fn_80480164
extern "C" int fn_80480164(void* x);
#endif
#ifndef NOPROTO_fn_804801B4
extern "C" int fn_804801B4(void* x);
#endif
#ifndef NOPROTO_fn_804801F0
extern "C" int fn_804801F0(void* x);
#endif
#ifndef NOPROTO_fn_80480240
extern "C" int fn_80480240(void* x);
#endif
#ifndef NOPROTO_fn_8048027C
extern "C" int fn_8048027C(void* x);
#endif
#ifndef NOPROTO_fn_804802D8
extern "C" int fn_804802D8(void* x);
#endif
#ifndef NOPROTO_fn_80480340
extern "C" int fn_80480340(void);
#endif
#ifndef NOPROTO_fn_80480348
extern "C" int fn_80480348(void);
#endif
#ifndef NOPROTO_fn_80480350
extern "C" int fn_80480350(void);
#endif
#ifndef NOPROTO_fn_80480358
extern "C" int fn_80480358(void);
#endif
#ifndef NOPROTO_fn_80480360
extern "C" int fn_80480360(void);
#endif
#ifndef NOPROTO_fn_80480368
extern "C" int fn_80480368(void);
#endif
#ifndef NOPROTO_fn_80480370
extern "C" int fn_80480370(void);
#endif
#ifndef NOPROTO_fn_80480378
extern "C" int fn_80480378(void);
#endif
#ifndef NOPROTO_fn_804805B4
extern "C" void fn_804805B4(void* x);
#endif
#ifndef NOPROTO_fn_804806D4
extern "C" int fn_804806D4(void* x, int a, int b, int c);
#endif
#ifndef NOPROTO_fn_80480784
extern "C" int fn_80480784(FeW* x, FeW* w, int b, int c);
#endif
#ifndef NOPROTO_fn_8048087C
extern "C" void fn_8048087C(void* x, int a);
#endif
#ifndef NOPROTO_fn_80480960
extern "C" void fn_80480960(void* x, int wi);
#endif
#ifndef NOPROTO_fn_80481200
extern "C" void fn_80481200(void* x, int a);
#endif
#ifndef NOPROTO_fn_8048131C
extern "C" void fn_8048131C(void* x, int a);
#endif
#ifndef NOPROTO_fn_80481438
extern "C" void fn_80481438(char* x, int a, int b);
#endif
#ifndef NOPROTO_fn_804814DC
extern "C" int fn_804814DC(void* x);
#endif
#ifndef NOPROTO_fn_8048157C
extern "C" int fn_8048157C(void* x);
#endif
#ifndef NOPROTO_fn_804815F8
extern "C" int fn_804815F8(void* x);
#endif
#ifndef NOPROTO_fn_80481634
extern "C" FeScrH* fn_80481634(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_80482348
extern "C" int fn_80482348(void* x);
#endif
#ifndef NOPROTO_fn_804828CC
extern "C" int fn_804828CC(void* x);
#endif
#ifndef NOPROTO_fn_8048291C
extern "C" int fn_8048291C(void* x);
#endif
#ifndef NOPROTO_fn_80482958
extern "C" int fn_80482958(void* x);
#endif
#ifndef NOPROTO_fn_804829A8
extern "C" int fn_804829A8(void* x);
#endif
#ifndef NOPROTO_fn_804829E4
extern "C" int fn_804829E4(void* x);
#endif
#ifndef NOPROTO_fn_80482A40
extern "C" int fn_80482A40(void* x);
#endif
#ifndef NOPROTO_fn_80482A9C
extern "C" int fn_80482A9C(void* x);
#endif
#ifndef NOPROTO_fn_80482ADC
extern "C" int fn_80482ADC(void* x, int a);
#endif
#ifndef NOPROTO_fn_80482B18
extern "C" int fn_80482B18(void* x);
#endif
#ifndef NOPROTO_fn_80482B58
extern "C" int fn_80482B58(void* x);
#endif
#ifndef NOPROTO_fn_80482B94
extern "C" int fn_80482B94(void* x);
#endif
#ifndef NOPROTO_fn_80482BFC
extern "C" int fn_80482BFC(void* x);
#endif
#ifndef NOPROTO_fn_80482C58
extern "C" int fn_80482C58(void* x);
#endif
#ifndef NOPROTO_fn_80482CC0
extern "C" int fn_80482CC0(void* x);
#endif
#ifndef NOPROTO_fn_80482D1C
extern "C" void fn_80482D1C(void* x);
#endif
#ifndef NOPROTO_fn_804831CC
extern "C" void fn_804831CC(void* x, FeW* w);
#endif
#ifndef NOPROTO_fn_804832BC
extern "C" void fn_804832BC(void* x, int a, int b);
#endif
#ifndef NOPROTO_fn_804832F4
extern "C" int fn_804832F4(void* x, int a, int b, int c);
#endif
#ifndef NOPROTO_fn_804833B4
extern "C" int fn_804833B4(FeW* x, FeW* w, int b, int c);
#endif
#ifndef NOPROTO_fn_80483654
extern "C" void fn_80483654(void* x, int a);
#endif
#ifndef NOPROTO_fn_80483708
extern "C" void fn_80483708(void* x, int wi);
#endif
#ifndef NOPROTO_fn_8048495C
extern "C" int fn_8048495C(void* x);
#endif
#ifndef NOPROTO_fn_804849FC
extern "C" int fn_804849FC(void* x);
#endif
#ifndef NOPROTO_fn_80484A78
extern "C" void fn_80484A78(void* x, int a);
#endif
#ifndef NOPROTO_fn_80484B18
extern "C" void fn_80484B18(void* x, int a);
#endif
#ifndef NOPROTO_fn_80485008
extern "C" void fn_80485008(int a, void* x);
#endif
#ifndef NOPROTO_fn_8048511C
extern "C" FeScrH* fn_8048511C(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_804851B0
extern "C" void fn_804851B0(FeScrB* self);
#endif
#ifndef NOPROTO_fn_80485944
extern "C" void fn_80485944(FeScrD* x);
#endif
#ifndef NOPROTO_fn_80485C28
extern "C" int fn_80485C28(void* x);
#endif
#ifndef NOPROTO_fn_80485CC4
extern "C" int fn_80485CC4(void* x);
#endif
#ifndef NOPROTO_fn_80486018
extern "C" void fn_80486018(void* x, int w, int dir);
#endif
#ifndef NOPROTO_fn_804860F8
extern "C" int fn_804860F8(void* x, int a, int b, int c);
#endif
#ifndef NOPROTO_fn_804861A8
extern "C" int fn_804861A8(FeW* x, FeW* w, int b, int c);
#endif
#ifndef NOPROTO_fn_804862A0
extern "C" int fn_804862A0(void* x);
#endif
#ifndef NOPROTO_fn_804862F0
extern "C" int fn_804862F0(void* x);
#endif
#ifndef NOPROTO_fn_8048632C
extern "C" int fn_8048632C(void* x);
#endif
#ifndef NOPROTO_fn_8048637C
extern "C" int fn_8048637C(void* x);
#endif
#ifndef NOPROTO_fn_804863B8
extern "C" int fn_804863B8(void* x);
#endif
#ifndef NOPROTO_fn_8048640C
extern "C" int fn_8048640C(void* x);
#endif
#ifndef NOPROTO_fn_80486460
extern "C" int fn_80486460(void* x);
#endif
#ifndef NOPROTO_fn_804864A0
extern "C" int fn_804864A0(void* x, int a);
#endif
#ifndef NOPROTO_fn_804864DC
extern "C" int fn_804864DC(void* x);
#endif
#ifndef NOPROTO_fn_8048651C
extern "C" int fn_8048651C(void* x);
#endif
#ifndef NOPROTO_fn_80486558
extern "C" int fn_80486558(void* x);
#endif
#ifndef NOPROTO_fn_80486598
extern "C" int fn_80486598(void* x, int a);
#endif
#ifndef NOPROTO_fn_804865D4
extern "C" int fn_804865D4(void* x);
#endif
#ifndef NOPROTO_fn_80486614
extern "C" int fn_80486614(void* x);
#endif
#ifndef NOPROTO_fn_80487FE0
extern "C" void fn_80487FE0(void* x, int wi);
#endif
#ifndef NOPROTO_fn_804880D8
extern "C" int fn_804880D8(void* x);
#endif
#ifndef NOPROTO_fn_80488178
extern "C" int fn_80488178(void* x);
#endif
#ifndef NOPROTO_fn_804884C0
extern "C" void fn_804884C0(int a, void* x);
#endif
#ifndef NOPROTO_fn_8048884C
extern "C" void fn_8048884C(int a, void* x);
#endif
#ifndef NOPROTO_fn_80488930
extern "C" void fn_80488930(int a, void* x);
#endif
#ifndef NOPROTO_fn_80488CDC
extern "C" FeScrH* fn_80488CDC(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_80488D30
extern "C" void fn_80488D30(FeScrB* self);
#endif
#ifndef NOPROTO_fn_80489324
extern "C" void fn_80489324(void);
#endif
#ifndef NOPROTO_fn_8048977C
extern "C" int fn_8048977C(void* x);
#endif
#ifndef NOPROTO_fn_804897B8
extern "C" int fn_804897B8(void* x);
#endif
#ifndef NOPROTO_fn_804897F4
extern "C" int fn_804897F4(void* x);
#endif
#ifndef NOPROTO_fn_80489830
extern "C" int fn_80489830(void* x);
#endif
#ifndef NOPROTO_fn_8048986C
extern "C" int fn_8048986C(FeW* x, int w);
#endif
#ifndef NOPROTO_fn_8048A2AC
extern "C" FeScrArr* fn_8048A2AC(FeScrArr* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_8048A378
extern "C" void fn_8048A378(FeScrCell* x);
#endif
#ifndef NOPROTO_fn_8048AB24
extern "C" void fn_8048AB24(void* x);
#endif
#ifndef NOPROTO_fn_8048AB50
extern "C" void fn_8048AB50(void* x);
#endif
#ifndef NOPROTO_fn_8048AC44
extern "C" int fn_8048AC44(void* x);
#endif
#ifndef NOPROTO_fn_8048AC80
extern "C" int fn_8048AC80(void* x);
#endif
#ifndef NOPROTO_fn_8048ACBC
extern "C" int fn_8048ACBC(void* x);
#endif
#ifndef NOPROTO_fn_8048ACF8
extern "C" int fn_8048ACF8(void* x);
#endif
#ifndef NOPROTO_fn_8048AD34
extern "C" int fn_8048AD34(void* x);
#endif
#ifndef NOPROTO_fn_8048AD80
extern "C" int fn_8048AD80(void* x);
#endif
#ifndef NOPROTO_fn_8048ADCC
extern "C" int fn_8048ADCC(void* x);
#endif
#ifndef NOPROTO_fn_8048AE18
extern "C" int fn_8048AE18(void* x);
#endif
#ifndef NOPROTO_fn_8048AE64
extern "C" int fn_8048AE64(FeW* x, FeW* w, int b, int c);
#endif
#ifndef NOPROTO_fn_8048B248
extern "C" FeScrH* fn_8048B248(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
#endif
#ifndef NOPROTO_fn_8048B2C0
extern "C" void fn_8048B2C0(void* x);
#endif
#ifndef NOPROTO_fn_8048B76C
extern "C" void fn_8048B76C(void* x);
#endif
#ifndef NOPROTO_fn_8048B7A0
extern "C" void fn_8048B7A0(FeW* x);
#endif
#ifndef NOPROTO_fn_8048B9B8
extern "C" int fn_8048B9B8(FeW* x);
#endif
#ifndef NOPROTO_fn_8048BB94
extern "C" int fn_8048BB94(FeW* x);
#endif
#ifndef NOPROTO_fn_8048BBF4
extern "C" void fn_8048BBF4(void* x, int v);
#endif
#ifndef NOPROTO_fn_8048BC18
extern "C" void fn_8048BC18(void* x);
#endif
#ifndef NOPROTO_fn_8048E3BC
extern "C" void fn_8048E3BC(FeW* x);
#endif
#ifndef NOPROTO_fn_8048E450
extern "C" int fn_8048E450(void* x);
#endif
#ifndef NOPROTO_fn_8048E480
extern "C" int fn_8048E480(void* x);
#endif
#ifndef NOPROTO_fn_8048E4D8
extern "C" int fn_8048E4D8(void* x);
#endif
/* END-PROTOS */
#endif
