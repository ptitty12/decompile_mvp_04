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
    char pad1D8[0x998 - 0x1D8];
    void* m998;
    int m99C;
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
