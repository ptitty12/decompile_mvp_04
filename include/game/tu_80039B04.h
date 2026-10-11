/*
 * Types for game/tu_80039B04.cpp and the neighbouring game units (reconstructed,
 * placeholder names). Nothing here comes from original headers.
 */
#ifndef GAME_TU_80039B04_H
#define GAME_TU_80039B04_H

#include "game/chooser.h"

void* operator new(unsigned int size, int heap); /* 0x80377428 */

/* 0x14-byte object created by fn_80039D38 (ctor 0x80034E14). Evidence: the
 * delete in fn_80039DBC goes through a virtual dtor whose vptr sits at +8. */
struct Unk80034E14_Base {
    int m0;
    int m4;
};
class Unk80034E14_Mid : public Unk80034E14_Base {
public:
    virtual ~Unk80034E14_Mid();
};
class Unk80034E14 : public Unk80034E14_Mid {
public:
    Unk80034E14();
    virtual ~Unk80034E14();
    int mC;
    int m10;
};

/* Object returned by fn_800475EC(): +0xF4 is an enable flag, +0xC00 a signed
 * value whose sign gates the callers (fn_8003AA88 and the sound-event
 * functions of tu_8003AEE4.cpp). */
struct Unk800475EC_Obj {
    char padF4[0xF4];
    int mF4;
    char padF8[0xC00 - 0xF8];
    int mC00;
};

/* Six-byte record scanned by the three lookup functions (fn_8003A194,
 * fn_8003A354, fn_8003A498). */
struct Unk8003A194_Rec {
    signed char m0;
    signed char m1;
    signed char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
};

/* Object behind the first argument of fn_80039D28..fn_8003A498 (0x52CC-byte
 * header, then the pointer table at +0x52CC). Evidence: offsets used by
 * fn_80039D28, fn_80039D38, fn_80039DBC, fn_80039E2C, fn_80039E94,
 * fn_80039EF8, fn_80039F04, fn_80039F24, fn_8003A0B0, fn_8003A130,
 * fn_8003A194, fn_8003A2D8, fn_8003A354, fn_8003A498. */
struct Unk80039B04_Mgr {
    Unk80039B04_Mgr* fn_80038EB4();
    void fn_800396D0(int a);
    void fn_800395B0(int a);
    char pad0[0x4EB0];
    Unk8003A194_Rec m4EB0[0x68];
    Unk8003A194_Rec m5120[10];
    Unk8003A194_Rec m515C[0x32];
    char pad5288[0x30];
    int m52B8;
    char pad52BC[0x10];
    Unk80034E14* m52CC[8];
    int m52EC;
    int m52F0;
    int m52F4;
    int m52F8;
    int m52FC;
};

/* Event table entry at 0x80616F18 (26 entries): event id plus a
 * pointer to member function (8 bytes in g++ 2.95). */
class Unk8003A5DC;
struct Unk80616F18_Entry {
    int m0;
    void (Unk8003A5DC::*m4)(int);
};

/* Objects reached from Unk8003A5DC::m10C (the game object the manager is
 * bound to by fn_8003B2DC). Evidence: fn_8003ADD4 (flags at m65C[10..12]),
 * fn_8003AEE4/fn_8003AF68/fn_8003B008 (m700->m3B0), fn_8003B23C, fn_8003B2DC
 * and fn_8003B3F4 (m6F8). */
struct Unk8003B2DC_Sub0C {
    char pad0[0x24];
    int m24;
    char pad28[0x80 - 0x28];
    int m80;
};
struct Unk8003B3F4_Sub14 {
    char pad0[0x1CC8];
    unsigned char m1CC8;
    char pad1CC9[7];
    int m1CD0;
    char pad1CD4[0x1D50 - 0x1CD4];
    int m1D50;
};
struct Unk8003EAB0_Sub10 {
    char pad0[0x1C];
    int m1C;
};
struct Unk8003B2DC_Sub6F8 {
    char pad0[0xC];
    Unk8003B2DC_Sub0C* mC;
    Unk8003EAB0_Sub10* m10;
    Unk8003B3F4_Sub14* m14;
};
struct Unk8027107C_Outer;
struct Unk8003A5DC_Ctx {
    char pad0[0x48];
    unsigned int m48;
    char pad4C[0x65C - 0x4C];
    void* m65C[13];
    char pad690[0x6F8 - 0x690];
    Unk8003B2DC_Sub6F8* m6F8;
    char pad6FC[4];
    Unk8027107C_Outer* m700;
};

/* 16-byte slot, ten of them at +0x30 of Unk8003A5DC. */
struct Unk8003A5DC_Slot {
    int m0;
    int m4;
    int m8;
    int mC;
};

/* Crowd-like manager (ctor 0x8003A5DC, vtable 0x806499F0, size 0x1FC), derived
 * from the attribute-registered root (ctor 0x8037B3E8, hash 0xAB6EE03F).
 * Evidence: fn_8003A5DC (ctor), fn_8003A814 (slot 2, attributes at +4..+0x2C),
 * fn_8003AA88 (slot 11), fn_8003ACE0 (slot 12), fn_8003ADD4, fn_8003AEC0. */
class Unk8003A5DC : public Unk8037B3E8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk8003A5DC();
    virtual ~Unk8003A5DC();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot8();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    void fn_8003ADD4();
    void fn_8003AEC0();

    float m4;
    float m8;
    int mC;
    int m10;
    float m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    float m2C;
    Unk8003A5DC_Slot m30[10];
    int mD0;
    int mD4[10];
    int mFC;
    int m100;
    int m104;
    int m108;
    Unk8003A5DC_Ctx* m10C;
    int m110;
    int m114;
    float m118;
    int m11C;
    int m120;
    int m124;
    int m128;
    int m12C;
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    int m168;
    int m16C;
    int m170;
    int m174;
    int m178;
    float m17C;
    int m180;
    int m184;
    int m188;
    int m18C;
    int m190;
    int m194;
    int m198;
    int m19C;
    int m1A0;
    int m1A4;
    int m1A8;
    int m1AC;
    int m1B0;
    int m1B4;
    int m1B8[5];
    int m1CC[5];
    int m1E0[7];
};

#endif
