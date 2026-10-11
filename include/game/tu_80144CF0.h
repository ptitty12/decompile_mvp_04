/*
 * Types shared by game/tu_80144CF0.cpp .. game/tu_8014F47C.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * The functions are methods of front-end screen/widget classes whose vtables live
 * in .data (e.g. TITLESLIDE, vtable lbl_8065A640, vptr at +0x3C). They are written
 * as extern "C" functions taking the object explicitly. The classes below declare
 * only the virtual slots the code calls through (slot N is at vtable +8N); the
 * other slots are filler. Each class is named after the offset of its vptr.
 */
#ifndef GAME_TU_80144CF0_H
#define GAME_TU_80144CF0_H


struct Z8 { int a; int b; };   /* 8-byte constants passed by value (lbl_805B99xx) */

/* vptr at +0x8 */
class VT8 {
public:
    char pad0[0x8];
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
};
/* vptr at +0x24 (sub-object at +0xDC / +0x98 of the screen classes) */
class VT24 {
public:
    char pad0[0x24];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9(int a, int b);
    virtual int s10(int a);
    virtual int s11();
};
/* vptr at +0x3C: TITLESLIDE family (vtable lbl_8065A640, 91+ slots) */
class VT3C {
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
    virtual int s46(int a);
    virtual int s47(int a);
    virtual int s48(int a);
    virtual int s49(int a);
    virtual int s50(int a);
    virtual int s51(int a);
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
    virtual VT3C* s84(int a);
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
};
/* vptr at +0x1C8 */
class VT1C8 {
public:
    char pad0[0x1C8];
    virtual int s1();
    virtual int s2();
    virtual int s3(int a, Z8 z);
};

#endif
