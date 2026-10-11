/*
 * Types for game/tu_802CFED4.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_802CFED4_H
#define GAME_TU_802CFED4_H

struct Unk802D0B4C_Vec3 {
    float x;
    float y;
    float z;
};

/* Per-camera state record (ctor fn_802D0B4C): +0xC position copied from the zero vector at 0x806055AC, +0x18 = 1.0f. */
class Unk802D0B4C {
public:
    Unk802D0B4C();
    int m0;
    int m4;
    int m8;
    Unk802D0B4C_Vec3 mC;
    float m18;
};

/* Object whose vptr sits at +8 (two data words first); fn_802D3E10 calls virtual slot 7 through it. */
struct Unk802D3E10_Data {
    int m0;
    int m4;
};
class Unk802D3E10 : public Unk802D3E10_Data {
public:
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
};

/* Scene setup object read by fn_802D38E8 / fn_802D3920 (lbl_8061FEDC): +0x204 / +0x208 widescreen flags. */
struct Unk802D38E8_Cfg {
    char pad0[0x204];
    int m204;
    int m208;
};
/* Camera with a 4x4 matrix at +0x20 and its cached copy at +0x120 (fn_802D3958), a position at +0x30 and a scalar at +0x3C (fn_802D36D0). */
struct Unk802D3958_Mat {
    float m[16];
};
struct Unk802D3958 {
    char pad0[0x20];
    Unk802D3958_Mat m20;
    char pad60[0x120 - 0x60];
    Unk802D3958_Mat m120;
};
struct Unk802D36D0 {
    char pad0[0x30];
    Unk802D0B4C_Vec3 m30;
    float m3C;
};
struct Unk802D3320_Vec3 {
    float x;
    float y;
    float z;
    inline void Scale(float k)
    {
        x *= k;
        y *= k;
        z *= k;
    }
};
struct Unk802D3320 {
    char pad0[0x20];
    Unk802D3320_Vec3 m20;
};

/* Camera classes created by the factories (constructors fn_802D10A0 / fn_802D1278 / fn_802D1EA4 / fn_802D3268). Sizes from the
 * factories' operator new arguments. */
class Unk802D10A0 {
public:
    Unk802D10A0();
    char data[0xF0];
};
class Unk802D1278 {
public:
    Unk802D1278();
    char data[0x44];
};
class Unk802D1EA4 {
public:
    Unk802D1EA4();
    char data[0x134];
};
class Unk802D3268 {
public:
    Unk802D3268();
    char data[0x40];
};

/* Pole camera fields scaled by fn_802D2344. */
struct Unk802D2344 {
    char pad0[0x38];
    Unk802D3320_Vec3 m38;
    char pad44[0x5C - 0x44];
    float m5C;
    char pad60[4];
    float m64;
    float m68;
    float m6C;
};

/* Camera object seen by the destructors: vptr at +0 (mid vtable 0x806646F0 while the root destructor runs). */
struct Unk802D116C {
    const void* vptr;
    char pad4[0x28];
    char m2C[4];
};

#include "game/chooser.h"
/* Registration helper methods that chooser.h does not declare yet (calls on the registrar object). */
class Unk802D0B94_Reg : public Unk8037B3E8 {
public:
    Unk802D0B94_Reg(const char* name);   /* never defined */
    void fn_8037B548(const char* name, const char* def);
    void fn_8037B5C0(const char* name, int* field, const char* values);
};
/* Location record registered by fn_802D0B94 (fields at +0, +4, +8 ints; +0xC, +0x10, +0x14, +0x18 floats). */
struct Unk802D0B94_Self {
    int m0;
    int m4;
    int m8;
    float mC;
    float m10;
    float m14;
    float m18;
};

#endif
