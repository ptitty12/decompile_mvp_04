/*
 * Types for game/tu_80084910.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_80084910_H
#define GAME_TU_80084910_H

/* Element types of the two table classes below (sizes proven by the strides
 * in fn_80084A10 / fn_80084AE8 and fn_80085A3C / fn_80085B14). */
struct Unk80084910_T30 {
    char pad0[0x30];
};

struct Unk80084910_T8 {
    char pad0[8];
};

/* Table class, seen with 0x30-byte and 8-byte elements: base part, a result
 * pointer at +0x14, a count at +0x1C, the vptr at +0x20 and the table at
 * +0x24 (the same shape as Unk8007FF8C_I). */
template <class T>
struct Unk80084910_K {
    char pad0[0x14];
    void* m14;
    char pad18[4];
    unsigned m1C;
    void* m20;
    T* m24;
};

/* Vtable entry at +8 of an object's table: this-adjustment and function
 * pointer (fn_800859E0, fn_80085B94). */
struct Unk80084910_VT {
    char pad0[8];
    short delta;
    short padA;
    void (*pfn)(void* self, int a, void* p, int n);
};

struct Unk80084910_VObj {
    char pad0[4];
    Unk80084910_VT* m4;
};

/* Vtable entry at +0x28: this-adjustment and function pointer (the getter
 * methods that call through m20). */
struct Unk80084910_VT2 {
    char pad0[0x28];
    short delta;
    short pad2A;
    int (*pfn)(void* self, int k, int a);
};

struct Unk80084910_G {
    char pad0[0x20];
    Unk80084910_VT2* m20;
};

/* Object type of the pointer-to-member table lbl_805B6B60 (see
 * Unk80089894_Obj): a virtual function keeps the virtual-call half of the
 * member-pointer call sequence. */
struct Unk80084910_PObj {
    virtual float M(int a);
};
typedef float (Unk80084910_PObj::*Unk80084910_Pmf)(int);

#endif
