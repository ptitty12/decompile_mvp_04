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
};

/* Same, for the screen whose widget sits at +0xE0C (fn_804CD794, fn_804CD810); +0xE04 holds the
 * vptr of a sub-object that fn_804CD2FC resets. */
struct FeScrE0C : FeScrN {
    char pad160[0xE04 - 0x160];
    const void* mE04;
    int mE08;
    FeW* mE0C;
};

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
struct FeScrM : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[0x144 - 0x134];
    FeSlot44 m144;
    FeSlot44 m188;
    FeW* m1CC;
    FeW* m1D0;
    char pad1D4[0x998 - 0x1D4];
    void* m998;
    int m99C;
};

extern "C" {
void fn_8035686C(void* self);
void fn_80444890(void* x);
void fn_80330BC8(void* x);
void fn_80377488(void* p);
}

#endif
