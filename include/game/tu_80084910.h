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

/* Packed 0x30-byte record behind K<T30>::m24 as read by fn_80084C50 (22 fields in the first five words). */
struct Unk80084910_PackA {
    unsigned top0 : 8;
    unsigned a00 : 16;
    unsigned pad0 : 8;
    unsigned a01 : 15;
    unsigned a02 : 1;
    unsigned a03 : 6;
    unsigned a04 : 8;
    unsigned pad1 : 2;
    unsigned a05 : 7;
    unsigned a06 : 10;
    unsigned a07 : 1;
    unsigned a08 : 7;
    unsigned a09 : 4;
    unsigned a0A : 2;
    unsigned pad2 : 1;
    unsigned a0B : 4;
    unsigned a0C : 3;
    unsigned a0D : 4;
    unsigned a0E : 1;
    unsigned a0F : 7;
    unsigned a10 : 3;
    unsigned a11 : 1;
    unsigned a12 : 7;
    unsigned pad3 : 2;
    unsigned a13 : 7;
    unsigned a14 : 7;
    unsigned a15 : 7;
    unsigned pad4 : 11;
    char padw14[0x1C];
};

struct Unk80084910_PackTabA {
    char pad0[0x1C];
    unsigned m1C;
    char pad20[4];
    Unk80084910_PackA* m24;
};

#endif
