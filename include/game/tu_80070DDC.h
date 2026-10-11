#ifndef GAME_TU_80070DDC_H
#define GAME_TU_80070DDC_H

#include "game/tu_8007A4DC.h"
#include "game/tu_8006902C.h"

/*
 * 0x80070DDC-0x80073914. Names are placeholders.
 *
 * Unk80071604: the 0x28-byte base of the widget/attribute-table family (the type
 * the screens call through as W). fn_80071604 is its ctor: it stores the vptr
 * lbl_8064B548 at +0x20 and copies a name into the first 0x10 bytes (fn_8040B61C
 * is called with the object itself as destination). m10 is the Obj list that
 * fn_80071718/fn_80071784/fn_80071814 search (fn_80377E90 / fn_80377DBC), m14 is
 * the fallback id, m1C the element count and m24 the element array. The vptr is
 * a plain pointer here: the class is written non-virtually so no vtable is emitted.
 *
 * Unk80070DDC_Stream: the object the (de)serializer slots write through; its
 * vptr is at +4 (virtual 0 at vtable +8 takes (id, data, size)).
 *
 * Unk80070ED8_Obj: 0x10-byte object whose vptr sits at +0xC and whose destructor
 * is virtual (fn_80070E80 calls it with in_chrg 3 through the vtable).
 * Unk80071FA0_Obj: the 0x210-byte singleton at lbl_8061930C (vptr at +0x20C).
 */
struct Unk80070DDC_Stream0 {
    int m0;
};
struct Unk80070DDC_Stream : Unk80070DDC_Stream0 {
    virtual int v08(int a, void* data, int size);
    virtual int v10();
};

struct Unk8052AE7C_Obj;

struct Unk80071604 {
    char m0[16];
    Obj* m10;
    int m14;
    int m18;
    unsigned m1C;
    void* m20;
    char* m24;
};

struct Unk80070ED8_Data {
    int m0;
    int m4;
    int m8;
};
struct Unk80070ED8_Obj : Unk80070ED8_Data {
    virtual ~Unk80070ED8_Obj();
};

/* The two-player manager at lbl_806192E0 (fn_80070ED8 builds it): m0 is the shared
 * context (0x604 bytes), m4[2] the session objects (0x5C bytes each, built with
 * the context). Its vptr is at +0xC (lbl_80649EF0). The *_V types are views with a
 * virtual destructor (vptr at +8) for the `delete` calls in fn_80070F64. */
struct Unk80070ED8_Mgr {
    Unk8006902C_Ctx* m0;
    Unk80069F0C* m4[2];
    void* mC;
};
struct Unk80070F64_Base8 {
    char pad0[8];
};
struct Unk80070F64_SessionV : Unk80070F64_Base8 {
    virtual ~Unk80070F64_SessionV();
};
struct Unk80070F64_CtxV : Unk80070F64_Base8 {
    virtual ~Unk80070F64_CtxV();
};

struct Unk80071FA0_Data {
    char pad0[0x20C];
};
struct Unk80071FA0_Obj : Unk80071FA0_Data {
    virtual ~Unk80071FA0_Obj();
};

#endif
