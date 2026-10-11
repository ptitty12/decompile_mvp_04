#ifndef GAME_TU_80033BC8_H
#define GAME_TU_80033BC8_H

/*
 * Types for src/game/tu_80033BC8.cpp (reconstructed). Two more members of the
 * Unk80021A60 family (tu_80030778.h): Unk80033BCC (0xE4 bytes, vtable
 * 0x806497F8) and Unk80034488 (0xD8 bytes, vtable 0x80649798).
 */
#include "game/tu_80030778.h"

struct Unk80033BCC;
typedef void (Unk80033BCC::*Unk80033BCC_Handler)(int);
struct Unk80033BCC_HEnt {
    int id;
    Unk80033BCC_Handler h;
};
extern Unk80033BCC_HEnt lbl_80616BF4[];

struct Unk80033BCC : public Unk80021A60 {
    Unk8002D15C_Cc* mBC[3];
    int mC8;
    int mCC;
    int mD0;
    int mD4;
    int mD8;
    int mDC;
    int mE0;
};

struct Unk80034488;
typedef void (Unk80034488::*Unk80034488_Handler)(int);
struct Unk80034488_HEnt {
    int id;
    Unk80034488_Handler h;
};
extern Unk80034488_HEnt lbl_80616C00[];

struct Unk80034488 : public Unk80021A60 {
    int mBC;
    int mC0;
    int mC4;
    int mC8;
    int mCC;
    int mD0;
    int mD4;
};

/* 0x10-byte object built by fn_80034B94 (vtable 0x80649D70 at +0xC). */
struct Unk80034B94 {
    int m0;
    int m4;
    int m8;
    const void* mC;
};
extern char lbl_80649D70[];

extern char lbl_806497F8[];
extern char lbl_80649798[];

extern "C" {
int fn_802D7DB4(int a, int b);
void fn_8005B9D4(void* o, int a);
void fn_8003465C(Unk80034488* self, int a);
int fn_80034734(Unk80034488* self);
void fn_80034854(Unk80034488* self, int i, Unk8002D15C_Msg* msg);
void fn_800222B4(Unk8002D15C_Owner* o, int* a, int* b, Unk8002D15C_Vec3 v);
void fn_80033DC0(Unk80033BCC* self, int a);
int fn_80033E98(Unk80033BCC* self);
void fn_80034028(Unk80033BCC* self, int i, Unk8002F894_Ev* ev);
void fn_80034144(Unk80033BCC* self, int i, Unk8002D15C_Msg* msg);
void fn_80034234(Unk80033BCC* self, Unk8002D15C_Owner* o, Unk8002D15C_Cc* c, int n);
void fn_8004181C(void* o, int a, int b, int c, int d, int e, int f);
void* fn_8004072C();
int fn_800412AC(void* o, int a, int b, int c, int d, int e);
}

#endif /* GAME_TU_80033BC8_H */
