/*
 * Shared declarations for the animation warp classes (reconstructed).
 *
 * Nothing here comes from original headers; see include/game/chooser.h for the
 * conventions. The warps share their root class (ctor 0x8037B3E8, vtable
 * 0x806849D0, slots 1-10) with the choosers. chooser.h folds the choosers' own
 * extra virtuals (slots 11-17) into that root; the warps add four of their own
 * (slots 11-14) in Unk8035EAE8 below. Until chooser.h's class is split, the
 * warp virtuals follow the choosers' slot 17 in the vtable (the code of the
 * warp units does not depend on the slot numbers).
 */
#ifndef GAME_WARP_B_H
#define GAME_WARP_B_H

#include "game/chooser.h"

/* Marker (16 bytes) in an animation's marker list; +0 is the hash that
 * fn_8037E64C compares, +0x8 the time. Evidence: fn_8037E64C (0x8037E64C) and
 * fn_802A4864 (tu_802A4584.cpp). */
struct Unk802A4864_Marker {
    int m0;
    char pad4[4];
    float m8;
    char padC[4];
};

/* Marker list at AnimData+0x10: +4 count, +8 array. fn_8037E64C returns the
 * index of the marker with the given hash, or -1. */
class Unk8037E64C {
public:
    int fn_8037E64C(int hash);
    char pad0[4];
    int m4;
    Unk802A4864_Marker* m8;
};

/* Global manager (pointer at 0x8061E978; method 0x802AEB4C looks an animation
 * up by id and returns a float of it). */
class Unk802AEB4C {
public:
    float fn_802AEB4C(int id);
};
extern Unk802AEB4C* lbl_8061E978;

/* Type ids set by the static initializer fn_802AA7A4 (hashes from fn_80378568).
 * D5AC/D5B0 are const: retail schedules their loads across the vptr store in
 * cTimeWarp::cTimeWarp, which needs unchanging memory. D5B4..D5BC as const break
 * cLimbLockWarp::fn_vslot13, so they stay plain. */
extern const int lbl_8068D5AC;
extern const int lbl_8068D5B0;
extern int lbl_8068D5B4;
extern int lbl_8068D5B8;
extern int lbl_8068D5BC;

/* Animation data reached through Entry::m4. */
struct Unk802A4864_Anim {
    char pad0[4];
    float m4;                  /* read by cGenericTimeWarp's slot 12 (0x802A4B94) */
    char pad8[0x10 - 0x8];
    Unk8037E64C m10;
};

/* One animation entry (0x68 bytes) of the warps' first argument.
 * Evidence: stride 0x68 and m10/m14 in fn_802A4674, fn_802A4B94, fn_802A5124;
 * m0/m4 in fn_802A4864; m10 in fn_802A5830. */
struct Unk802A4674_Entry {
    int m0;
    Unk802A4864_Anim* m4;
    char pad8[0x10 - 0x8];
    float m10;
    float m14;
    char pad18[0x68 - 0x18];
};

/* Header of the warps' second argument: signed 4-bit entry count at the top of
 * word 0. Evidence: srawi 28 in fn_802A4674, fn_802A4B94, fn_802A5124,
 * fn_802A5258; m2C/m50/m54/m58 in fn_802A4864 and fn_802A5830. */
struct Unk802A4674_Hdr {
    int count : 4;
    int pad0 : 28;
    char pad4[0x2C - 0x4];
    int m2C;
    char pad30[0x50 - 0x30];
    float m50;
    float m54;
    float m58;
};

/* Four floats; the default ctor (0x80379324) sets all of them to the float at
 * 0x80605638. Evidence: fn_802A5CA4 (tu_802A4584.cpp) builds one as the member at
 * +0x7C of the local Unk8035A618 and as the in/out operands of its transform. */
struct Unk80379324_Vec4 {
    float x;
    float y;
    float z;
    float w;
};

struct Unk80379324 : public Unk80379324_Vec4 {
    Unk80379324();
};

/* Local transform object of cHeadingWarp's slot 13 (fn_802A5CA4). Layout from
 * the ctor-side function 0x8035A618 (it initializes +0x0 .. +0x94), the virtuals
 * 0x8035A6BC / 0x8035A6F4 (which write the vector at +0x60) and the vptr at
 * +0x98 (vtable 0x806604F8: dtor 0x8035A688, slots 2 and 3 as above). The
 * constructor and destructor are inline (the dtor leaves only a vptr store);
 * the transform is 0x8037D824. */
class Unk8035A618 {
public:
    Unk8035A618() { fn_8035A618(); }
    virtual ~Unk8035A618() {}
    virtual void fn_vslot2(float x, float y, float z);
    virtual void fn_vslot3(const Unk80273498_Vec3& v);
    void fn_8035A618();                                          /* initializer */
    void SetAngle(float a) { m0 = 0; m6C = 0; m74 = a; }         /* guess for the inlined setter */
    void fn_8037D824(const Unk80379324_Vec4* in, Unk80379324_Vec4* out);   /* transform */

    int m0;
    char pad4[0x60 - 0x4];
    float m60;
    float m64;
    float m68;
    int m6C;
    float m70;
    float m74;
    float m78;
    Unk80379324 m7C;
    float m8C;
    float m90;
    float m94;
};

/* Mid class of the warps (dtor 0x8035EAE8, no vptr store: it adds no vtable
 * of its own to the root's; slots 11-14 are empty functions at
 * 0x8035EB08..0x8035EB14). The dtor is implicit. */
class Unk8035EAE8 : public Unk8037B3E8 {
public:
    Unk8035EAE8(unsigned int hash) : Unk8037B3E8(hash) {}
    virtual void fn_vslot11(float* a, Unk80270BA0_Obj* obj) {}
    virtual void fn_vslot12(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj) {}
    virtual void fn_vslot13(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj) {}
    virtual void fn_vslot14(Unk80270BA0_Obj* obj, float* b) {}
};

#endif /* GAME_WARP_B_H */
