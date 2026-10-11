/*
 * Types shared by game/tu_802F8324.cpp .. game/tu_80313C14.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * The code is the batter/pitcher gameplay block (cBatterPitcher and friends,
 * chooser classes with vtables in .data). Functions are written as extern "C"
 * functions taking the object explicitly and storing the retail vtable
 * (lbl_ data object) by hand, so no vtables are emitted in code-only units.
 */
#ifndef GAME_TU_802F8324_H
#define GAME_TU_802F8324_H

#include "game/chooser.h"
#include "game/tu_8001B190.h"
#include "game/tu_8000C2C4.h"

inline void* operator new(unsigned int, void* p) { return p; }

struct Unk802F8324_V2 {
    float x;
    float y;
};

/* vptr at +0 (handle objects returned by the manager lookups). */
class Unk802F8324_VT0 {
public:
    virtual ~Unk802F8324_VT0();
    virtual int s2();
    virtual int s3(int a);
    virtual int s4();
};

/* vptr at +0x8 (no dtor), slot N at vtable +8N. */
class Unk802F8324_VT8 {
public:
    char pad0[8];
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
};

/* vptr at +0x18, slot N at vtable +8N (dtor = slot 1): the UI/input manager
 * object at lbl_80619D10 and other player-side objects. */
class Unk802F8324_VT18 {
public:
    char pad0[0x18];
    virtual ~Unk802F8324_VT18();
    virtual int s2();
    virtual int s3(int a);
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
};

#endif /* GAME_TU_802F8324_H */
