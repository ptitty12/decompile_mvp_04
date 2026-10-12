/*
 * Shared types for the front-end overlay units fe/tu_80516990 .. fe/tu_80529364
 * (0x80516990..0x8052A208; reconstructed, placeholder names, nothing here comes from
 * original headers). Builds on fe_804BE560.h / fe_80459228.h (widget base FeW, screens FeScrN).
 */
#ifndef GAME_FE_80516990_H
#define GAME_FE_80516990_H

#include "game/fe_804BE560.h"

/* Word at byte offset `off` of any object (accessors on fields of screens whose layout is unknown). */
inline int& FeI(void* p, int off)
{
    return *(int*)((char*)p + off);
}

/* Object whose vtable pointer sits at byte offset OFF (deleting destructors with a lone vptr store). */
template <int OFF>
struct FeVptr {
    char pad[OFF];
    const void* vp;
};

/* Object with its vptr at +0x10 (fn_80528DC8..fn_80528F78: tiny setters forwarding to a virtual). The
 * slot number is the vtable byte offset / 8. */
class FeV10 {
public:
    char pad0[0x10];
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
};
struct FeV10D : FeV10 {
    int m14;
    int m18;
    int m1C;
    int m20;
};

/* Sub-object at +0xDC of the object returned by fn_8051F4D8, with its vptr at +0x24. */
class FeSub24 {
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
};
extern "C" void* fn_8051F4D8(void* x);
inline FeSub24* FeSubOf(void* x)
{
    return (FeSub24*)((char*)fn_8051F4D8(x) + 0xDC);
}

/* Pointer-valued / word fields at a byte offset of a screen whose layout is partly unknown. */
inline FeW*& FeP(void* p, int off)
{
    return *(FeW**)((char*)p + off);
}

/* First word of the state object returned by fn_800B555C(). */
struct FeState0 {
    int m0;
};
extern "C" int fn_800B5898(void* st);

/* Screen with sub-widgets embedded at +0x134 and +0x1EC; m2A8 points at one of them (fn_80516ACC). */
struct FeSubA {
    char pad0[0x94];
    FeW* m94;
};
struct FeScrT : FeW {
    char pad40[0x2A8 - 0x40];
    FeSubA* m2A8;
    char pad2AC[0x2BC - 0x2AC];
    FeW* m2BC;
    int m2C0;
};
/* Table of ids (fn_80516DA8): m4[] are the stored ids, m78[] the probes, m84 the count. */
struct FeTab {
    int m0;
    int m4[29];
    int m78[3];
    int m84;
};

/* Five-byte string copied by value (fn_80516D24). */
struct FeS5 {
    char c[5];
};
extern const FeS5 lbl_805F4450;

#endif
