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
    int m0;
    int m4;
    int m8;
    int mC;
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4();
    virtual void s5(int a);
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

/* Same object with slot 2 returning an int and slot 3 taking one (fn_8052088C, fn_805208E0). */
class FeV10B {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    virtual void s1();
    virtual int s2();
    virtual void s3(int a);
    virtual int s4();
    virtual void s5(int a);
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
    virtual void s6(int a);
    virtual int s7(int a);
    virtual int s8(int a);
    virtual void s9();
    virtual void s10();
    virtual int s11();
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

/* Destructor-like helpers called with an in-charge argument (members: fn_800EC5F4 with 2, base: fn_8035686C
 * with the caller's own argument). */
typedef void (*FeDtorFn)(void* self, int c);

/* Object with a vptr at +0xCC0 whose slot 27 takes two floats (fn_80529470). */
class FeVCC0 {
public:
    char pad0[0xCC0];
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
    virtual void s27(float a, float b);
    virtual void s28();
    virtual void s29();
    virtual void s30();
};

/* Byte-offset load through a base pointer (stride records). */
inline int FeKeyAt(char* base, int off)
{
    return *(int*)(base + off);
}

/* Settings block at +8 of the state object returned by fn_800B555C(); the option classes (vptr at +0x10,
 * fn_8051FE58..fn_80520794) copy values between their virtual slots 4/5 and these fields. */
struct FeSet {
    char pad0[0x520];
    int m520;
    int m524;
    int m528;
    char pad52C[0x580 - 0x52C];
    int m580;
    char pad584[4];
    int m588;
    char pad58C[4];
    int m590;
};
inline FeSet* FeGetSet()
{
    return (FeSet*)((char*)fn_800B555C() + 8);
}

extern "C" void* fn_800C8058(void* p);
extern "C" void* fn_800C8048(void* p);
extern FeW* lbl_80622644;
extern int lbl_80622648;
extern "C" int fn_8051E910(int a, int b);
extern "C" void fn_8051EDDC(int a, int b, int c);
/* Widget pool lookup by index (fn_8051F42C and the callers that inline it). */
inline FeW* FePool(FeV10* x)
{
    return lbl_80622644->fn_vslot73(x->m0, 0);
}

/* Small option records (vtable pointer at +0x10, set by hand: the vtables are .data objects). Their
 * constructors are the out-of-line ones fn_8051FEF4, fn_80520BE0 and fn_8052083C. */
struct FeRecA {
    int m0;
    int m4;
    int m8;
    int mC;
    const void* m10;
    FeRecA(int a);
};
struct FeRecB {
    int m0;
    int m4;
    int m8;
    int mC;
    const void* m10;
    FeRecB(int a, int b);
};
struct FeRecC {
    int m0;
    int m4;
    int m8;
    int mC;
    const void* m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    FeRecC(int a, int b, int c, int d, int e);
};

/* Singleton at lbl_8062264C (0xBC bytes, ctor fn_80521144): 42 words, three more words, then the vptr
 * at +0xB8 (stored by hand; the vtable is a .data object). FeSingleV is the same object seen through
 * its virtual destructor (slot 1). */
struct FeSingle {
    int m0[42];
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    const void* mB8;
    FeSingle();
};
class FeSingleV {
public:
    char pad0[0xB8];
    virtual ~FeSingleV();
};
class FeSingleW {
public:
    char pad0[0xB8];
    virtual void s1(int c);
};
extern FeSingle* lbl_8062264C;

#endif
