/*
 * Shared types for game code 0x80275F24-0x80279758 (unit game/tu_80275F24;
 * reconstructed, placeholder names, everything is named by offset). This is
 * chooser code (base Unk8037B3E8 in game/chooser.h) in the animation unity TU.
 */
#ifndef GAME_TU_80275F24_H
#define GAME_TU_80275F24_H

#include "game/chooser.h"

struct Unk80275F24_S {
    char pad0[4];
    int m4;
};

/* Helper list embedded at +4 of the chooser below (vtable 0x80662068, ctor 0x80275F24,
 * dtor 0x80275F70). m4 is registered as the chooser's "LogicType" enum (+8 of the
 * chooser); m8/mC look like a count and an array deleted with delete[]. */
struct Unk80275F24_Elem {
    unsigned int m0;
    char pad4[0x3C - 4];
};

class Unk80275F24 : public Unk80356798 {
public:
    Unk80275F24();
    virtual void fn_vslot1(char* buf, int len);
    virtual ~Unk80275F24();

    int m4;
    int m8;
    Unk80275F24_Elem* mC;
    int m10;
};

/* Sort record compared by fn_80276198 / fn_80276758 (floats at +8, +0x14, +0x2C, +0x34; a signed
 * byte at +0x20). Layout is only what the comparators read. */
struct Unk80276758_Rec {
    char pad0[8];
    float m8;
    char padC[0x14 - 0xC];
    float m14;
    char pad18[0x20 - 0x18];
    signed char m20;
    char pad21[0x2C - 0x21];
    float m2C;
    char pad30[4];
    float m34;
};

/* Static table rows (0x328 bytes each) cleared by the chooser constructor. */
struct Unk80276DB8_Row {
    int m0;
    char pad4[0x328 - 4];
};

/* Chooser with the "LogicType"/"animlist"/"CatchInAirOnly" attributes (size 0x34,
 * ctor 0x80276DB8, dtor 0x80276F4C, slot 2 0x80276E40, factory 0x80276F9C). */
class Unk80276DB8 : public Unk8037B3E8 {
public:
    Unk80276DB8();
    virtual ~Unk80276DB8();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();

    Unk80275F24 m4;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    float m30;
};

#endif /* GAME_TU_80275F24_H */
