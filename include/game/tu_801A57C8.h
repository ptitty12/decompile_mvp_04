#ifndef GAME_TU_801A57C8_H
#define GAME_TU_801A57C8_H

#include "game/tu_8019F8C0.h"

/*
 * Declarations for game/tu_801A57C8.cpp (reconstructed; placeholders only).
 */

/* Sub-object at +0x560 of the owner: pointer at +4 to an object with a state id at +0x14. */
struct Unk801A57C8_Mode {
    int m0;
    struct Unk801A57C8_ModeObj* m4;
};
struct Unk801A57C8_ModeObj {
    char pad0[0x14];
    unsigned m14;
};

/* Global at lbl_8068BF34 (0x424 bytes): int table from 0, counters near 0x310. */
struct Unk801A57C8_G {
    int m0[0xC4];
    int m310;
    int m314;
    int m318;
    int m31C;
    char pad320[0x424 - 0x320];
};

/* Root of the vptr-at-0 object family (ctor 0x801B5A44 stores m4, m8 and the vptr 0x8065FD38;
 * dtor 0x801B5A90 clears them and deletes when bit 0 of the in-charge argument is set).
 * Vtable slot 1 is a virtual before the destructor (slot 2) in every derived vtable. */
class Unk8035AB00 {
public:
    Unk8035AB00();
    virtual void fn_vslot1() = 0;
};

class Unk801B5A44 : public Unk8035AB00 {
public:
    Unk801B5A44(int a, int b);
    virtual void fn_vslot1() = 0;
    virtual ~Unk801B5A44();
    int m4;
    int m8;
};

/* Subclass with a third virtual (vtable 0x8065FD10, dtor 0x801B24D4, slot 3 0x801B25C4). */
class Unk801B2490 : public Unk801B5A44 {
public:
    Unk801B2490(int a, int b);
    virtual void fn_vslot1();
    virtual ~Unk801B2490();
    virtual void fn_vslot3();
    void Setup();
};

/* vtable 0x8065FAC0, ctor 0x801B10C8, dtor 0x801B110C. */
class Unk801B10C8 : public Unk801B2490 {
public:
    Unk801B10C8(int a, int b);
    virtual ~Unk801B10C8();
    void Init();
};

/* vtable 0x8065FCC8, dtor 0x801AB59C. */
class Unk801AB59C : public Unk801B2490 {
public:
    Unk801AB59C(int a, int b);
    virtual void fn_vslot1();
    virtual ~Unk801AB59C();
};

/* vtable 0x8065FAE8, dtor 0x801AE5C0. */
class Unk801AE5C0 : public Unk801B5A44 {
public:
    Unk801AE5C0(int a, int b);
    virtual void fn_vslot1();
    virtual ~Unk801AE5C0();
};

class Unk801A9610 : public Unk801B5A44 {
public:
    Unk801A9610(int a, int b);
    virtual void fn_vslot1();
    virtual ~Unk801A9610();
    void Init();
};

#endif
