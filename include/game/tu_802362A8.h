#ifndef GAME_TU_802362A8_H
#define GAME_TU_802362A8_H

#include "game/chooser.h"
#include "game/tu_8022FE34.h"

/*
 * cPitcherTunables (vtable 0x80660DA0, name string at 0x805D736C "cPitcherTunables"):
 * a chooser-family class (ctor passes hash 0x1011A855 to Unk8037B3E8). Slot 2
 * (fn_802362FC) registers the "ptu" attributes: floats at +0x1C..+0x74 in groups
 * and two list members at +4 and +0x10 (ctor fn_8033CCE0 each). Slots 3/4
 * (fn_8023BD44/fn_8023BD50) are defined in tu_8023A6C8, so the vtable is emitted there.
 * Evidence: ctor 0x802362A8 stores the vtable then constructs the lists; the
 * factory 0x8023667C does `new` of 0x78 bytes.
 */
extern "C" void fn_8033CCE0(void* p);
struct Unk802362A8_List {
    int d0;
    int d1;
    int d2;
    Unk802362A8_List() { fn_8033CCE0(this); }
};

class cPitcherTunables : public Unk8037B3E8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cPitcherTunables();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot8();

    Unk802362A8_List m4;
    Unk802362A8_List m10;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    float m48;
    float m4C;
    float m50;
    float m54;
    float m58;
    float m5C;
    float m60;
    float m64;
    float m68;
    float m6C;
    float m70;
    float m74;
};

/*
 * Slots: 0x94-byte record at CpuBase+4 (fn_80237114 clears three 11-entry int
 * arrays at +0, +0x2C, +0x58 to -1 and three ints at +0x84, +0x88, +0x8C).
 */
struct Unk802362A8_Slots {
    int m0[11];
    int m2C[11];
    int m58[11];
    int m84;
    int m88;
    int m8C;
    int m90;
    void fn_80237114();
};

/*
 * Cpu: the pitcher-AI CPU object (ctor fn_802376A0). Slots at +4, then eleven
 * 0x34-byte entries from +0x98 (vptr at +0x30 of each), a vptr at +0x2D8, and
 * three pointers: m2DC (the T owner, fn_8023A7F4 reaches m38 through it), m2E0
 * (a U) and m2E4 (the Ctx, ctx->m6F4 compared with 3 in fn_8023A7C4).
 */
struct Unk802362A8_Cpu {
    int m0;
    Unk802362A8_Slots m4;
    char pad98[0x2DC - 0x98];
    Unk8022FE34_Owner* m2DC;
    Unk8022FE34_U* m2E0;
    Unk8022FE34_Ctx* m2E4;
    float m2E8;
    int m2EC;
    int fn_8023A7C4();
    void fn_8023A7F4();
    void fn_8023A6C8(int a);
    void fn_8023A13C();
    void fn_8023A1C8(int a);
};

#endif
