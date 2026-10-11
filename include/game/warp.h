/*
 * Shared declarations for the animation warp classes (reconstructed).
 *
 * Nothing here comes from original headers; see include/game/chooser.h for the
 * conventions. The warps share their root class (ctor 0x8037B3E8) with the
 * choosers, but chooser.h folds the choosers' own extra virtuals (slots 11-17)
 * into that root. The warps add different ones (slots 11-14), so this header
 * declares the root again with slots 0..10 only and does not include chooser.h.
 * The two cannot be included together until the lead splits chooser.h's class.
 */
#ifndef GAME_WARP_H
#define GAME_WARP_H

void* operator new(unsigned int size, int heap);      /* 0x80377428 */

extern int lbl_806EF9B4;          /* default heap passed to new */

/* Root of the choosers and the warps (ctor 0x8037B3E8, dtor 0x8037B424,
 * vtable 0x806849D0). Only the vptr (+0) is data. */
class Unk8037B3E8 {
public:
    Unk8037B3E8(unsigned int hash);
    virtual ~Unk8037B3E8();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    /* Attribute registration helpers used by the slot 2 overrides. */
    void fn_8037B458(const char* name, int* field, int a, int b);                  /* 0x8037B458 */
    void fn_8037B50C(const char* name, float* field, const char* range, int a);    /* 0x8037B50C */
    void fn_8037B638(const char* name, int* field, const char* values);            /* 0x8037B638 */
};

struct Unk802A37B4_Entry {
    char pad0[0x10];
    float m10;
    float m14;
    char pad18[4];
    float m1C;
    char pad20[0x68 - 0x20];
};

struct Unk802A37B4_Hdr {
    int count : 4;
    int pad0 : 28;
};

/* Three floats (x, y, z); same as chooser.h's Unk80273498_Vec3. */
struct Unk80273498_Vec3 {
    float x;
    float y;
    float z;
};

class Unk80270BA0_X;

/* Reached through Unk80270BA0_X::m618 (chooser.h's Unk80271DBC_Link, which
 * also has m880). */
struct Unk80271DBC_Link {
    char pad0[0x838];
    int m838;
    char pad83C[0x888 - 0x83C];
    float m888;
};
float fn_80382BB8(Unk80271DBC_Link* p);                  /* returns m888 */

/* Second argument of the warps' slots 11, 13 and 14; only its first virtual is
 * used here (same layout as chooser.h's Unk80270BA0_Obj). */
class Unk80270BA0_Obj {
public:
    virtual Unk80270BA0_X* fn_vslot1();
};

/* The player object (chooser.h has the fuller picture; only what the warps
 * touch is spelled out here). Its vptr is at +0x98 and a second base
 * (Unk80270BA0_Obj) sits at +0x5F0. */
struct Unk80270BA0_XBase {
    char pad0[0x60];
    Unk80273498_Vec3 m60;
    char pad6C[0x98 - 0x6C];
};

class Unk80270BA0_XVirt : public Unk80270BA0_XBase {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3(const Unk80273498_Vec3& v);
    virtual int fn_vslot4();
};

class Unk80270BA0_XMid : public Unk80270BA0_XVirt {
public:
    char pad9C[0x320 - 0x9C];
    Unk80273498_Vec3 m320;
    Unk80273498_Vec3 m32C;
    char pad338[0x5F0 - 0x338];
    /* By-value getters: reading the vectors through these gives the direct
     * stack copies of retail (a plain local copy takes an address register). */
    Unk80273498_Vec3 GetM320() { return m320; }
    Unk80273498_Vec3 GetM32C() { return m32C; }
};

class Unk80270BA0_X : public Unk80270BA0_XMid, public Unk80270BA0_Obj {
public:
    char pad5F4[0x618 - 0x5F4];
    Unk80271DBC_Link* m618;
    char pad61C[0x93C - 0x61C];
    Unk80273498_Vec3 m93C;
    void fn_80244858(float a);
    Unk80273498_Vec3 GetM93C() { return m93C; }
};

/* State record at +0x44 of the Unk8037B128 object (second argument of
 * cFudgePosRotWarp::fn_802A3D8C; slot 11 receives it directly). */
struct Unk802A3D8C_State {
    char pad0[0x24];
    int m24;
    char pad28[0x30 - 0x28];
    Unk80273498_Vec3 m30;
    float m3C;
    float m40;
};

/* Object passed to the warps' slot 14 (matrix at +0, position at +0x30; ctor
 * unknown). fn_8037B128 returns the position and fn_8037B1F0 the heading from
 * the first row. */
class Unk8037B128 {
public:
    Unk80273498_Vec3 fn_8037B128();
    float fn_8037B1F0();
    char pad0[0x44];
    Unk802A3D8C_State m44;
    char pad_after44[0xA0 - 0x44 - sizeof(Unk802A3D8C_State)];
    int mA0;
    Unk80273498_Vec3 mA4;
};

/* Mid class of the warps (dtor 0x8035EAE8; slots 11-14 are empty functions at
 * 0x8035EB08..0x8035EB14). */
class Unk8035EAE8 : public Unk8037B3E8 {
public:
    Unk8035EAE8(unsigned int hash) : Unk8037B3E8(hash) {}
    virtual ~Unk8035EAE8();
    virtual void fn_vslot11(Unk802A3D8C_State* st, Unk80270BA0_Obj* obj);
    virtual void fn_vslot12(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h);
    virtual void fn_vslot13(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h, Unk80270BA0_Obj* obj);
    virtual void fn_vslot14(Unk80270BA0_Obj* obj, Unk8037B128* b);
};

#endif /* GAME_WARP_H */
