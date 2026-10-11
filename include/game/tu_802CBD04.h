/*
 * Types for game/tu_802CBD04.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_802CBD04_H
#define GAME_TU_802CBD04_H

struct Unk802CBD04_Vec3 {
    float x;
    float y;
    float z;
};

/* Virtual interface at +0xA0 (fn_802CC53C calls slot at +0x5C with the object as argument, fn_802CC8EC slot at +0x84). */
struct Unk802CBD04;
class Unk802CC53C_Target {
public:
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
    virtual void s11(Unk802CBD04* o);
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int s16();
};

/* Camera/rig object. Evidence: fn_802CBD90 (+0xA4/+0xA8/+0xAC), fn_802CBDBC (+0xA0/+0xDC/+0xE0),
 * fn_802CBE04 (three vectors at +0x160/+0x16C/+0x178), fn_802CC580 (+0xD8 data block). */
struct Unk802CBD04 {
    char pad0[0x60];
    Unk802CBD04_Vec3 m60;
    char pad6C[0xA0 - 0x6C];
    Unk802CC53C_Target* mA0;
    float mA4;
    float mA8;
    float mAC;
    char padB0[0xD4 - 0xB0];
    int mD4;
    char* mD8;
    int mDC;
    int mE0;
    char padE4[0x160 - 0xE4];
    Unk802CBD04_Vec3 m160;
    Unk802CBD04_Vec3 m16C;
    Unk802CBD04_Vec3 m178;
    char pad184[0x65C - 0x184];
    int m65C[13];
};

/* Cached transform: +0 valid flag, +0x20 a 0x40-byte matrix copied out by fn_802CC48C. */
struct Unk802CC48C_Mat {
    float m[16];
};
struct Unk802CC48C {
    int m0;
    char pad4[0x1C];
    Unk802CC48C_Mat m20;
};
/* Two offsets (x, y) and their source ranges (fn_802CF70C): +0 enable, +4/+8/+0xC and +0x10/+0x14/+0x18 inputs for the two axes. */
struct Unk802CF70C_In {
    int m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
};
struct Unk802CF70C_Out {
    float x;
    float y;
};
struct Unk802CF70C_Flags {
    char pad0[0x24];
    int m24;
};

/* Camera object seen by the attribute-registration slot (fn_802CF368, fn_802CF4B4): the root class Unk8037B3E8 (chooser.h) contributes
 * only the vptr, the camera's own data starts at +4. */
struct Unk802CF4B4_Self {
    const void* vptr;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    int m1C;
};

#include "game/chooser.h"
/* Camera base (mid class, vtable 0x806646F0) as seen by its attribute-registration slot fn_802CF368. */
class Unk802CF368_Self : public Unk8037B3E8 {
public:
    Unk802CF368_Self(const char* name);   /* never defined here; only the registration slot is */
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    void fn_8037B548(const char* name, int a);   /* begin/flag registration used with a null default */
};

#endif
