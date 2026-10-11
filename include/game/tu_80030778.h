#ifndef GAME_TU_80030778_H
#define GAME_TU_80030778_H

/*
 * Types for src/game/tu_80030778.cpp (reconstructed). The unit starts with a
 * small manager object (0x38 bytes, singleton at lbl_80616B68) that keeps up
 * to three entries {id, object, handle, extra} (stride 0x10) and forwards
 * calls to the objects through the vtable at +0xB8 of each one.
 */
#include "game/tu_8002D15C.h"

struct Unk80030884_Slot {
    int m0;
    Unk8002D15C_Owner* m4;
    int m8;
    Unk80030C90_Base* mC;
};

struct Unk80030884 {
    Unk80030884_Slot m0[3];
    int m30;
    int m34;
    Unk80030884();
    ~Unk80030884();
};

/*
 * Object of size 0x144 (ctor fn_800311D0, vtable at 0x806498E0, stored at
 * +0xB8). Derived from the same base as Unk8002D15C (ctor fn_80021A60), with
 * three owner slots at +0x80 and per-slot arrays. Plain struct here: the
 * vtable is data of another unit, so the vptr is stored by hand.
 */
struct Unk800311D0 {
    char pad0[0x78];
    int m78;
    int m7C;
    Unk8002D15C_Owner* m80[3];
    char pad8C[0xB8 - 0x8C];
    const void* vptr;
    int mBC[3];
    int mC8[3];
    int mD4[3];
    int mE0[3];
    int mEC[3];
    int mF8[3];
    int m104[3];
    int m110[3];
    int m11C[3];
    int m128;
    int m12C;
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
};
extern char lbl_806498E0[];
extern int lbl_805B1A0C[];

extern int lbl_80616B64;
extern Unk80030884* lbl_80616B68;

extern "C" {
void fn_80030C90(Unk80030884* self, int i);
Unk8002D15C_Vec3 fn_80196E3C(int a, float f);
double fn_80410634(double x);
void fn_80021EB4(void* self, void* o, int a, int b, int c);
int fn_80031110(Unk800311D0* self, int a, int b);
Unk800311D0* fn_80021A60(Unk800311D0* self);
void fn_80021BB4(Unk800311D0* self, int chrg);
void* fn_8001C394();
int fn_8001CC40(void* p, int a);
void fn_8005B58C(void* p, int a);
void* fn_8005ACE4();
void fn_800396D0(int a, int b);
int fn_80039FD4(int a, int b);
void fn_8003A058(int a, int b);
void fn_8005C250(void* p, int a);
void fn_80039854(int a, int b, float f);
void fn_80039790(int a, float f);
void fn_800398E4(int a, float f);
void fn_800395B0(int a, int b);
void fn_8005AF00(void* p, int a);
}

void* operator new(unsigned int size, int heap); /* 0x80377428 */

#endif /* GAME_TU_80030778_H */
