/*
 * Types for game/tu_80089894.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_80089894_H
#define GAME_TU_80089894_H

/* Object type of the pointer-to-member tables (lbl_805B6BA8 and friends):
 * the member functions are unknown, only the call shape is. The class needs
 * a virtual function, or the compiler drops the virtual-call half of the
 * member-pointer call sequence that retail contains. */
struct Unk80089894_Obj {
    virtual float M(int a);
};

/* Element types of the table classes (strides proven by the mulli/slwi
 * factors in each family's constructor, clear and virtual-call methods). */
struct Unk80089894_T14 {
    char pad0[0x14];
};
struct Unk80089894_TC {
    char pad0[0xC];
};
struct Unk80089894_T3C {
    char pad0[0x3C];
};

/* Table class: base part, a result pointer at +0x14, a count at +0x1C, the
 * vptr at +0x20 and the table at +0x24 (same shape as Unk8007FF8C_I). */
template <class T>
struct Unk80089894_K {
    char pad0[0x14];
    void* m14;
    char pad18[4];
    unsigned m1C;
    void* m20;
    T* m24;
};

/* Vtable entry at +8 of an object's table: this-adjustment and function
 * pointer. */
struct Unk80089894_VT {
    char pad0[8];
    short delta;
    short padA;
    void (*pfn)(void* self, int a, void* p, int n);
};

struct Unk80089894_VObj {
    char pad0[4];
    Unk80089894_VT* m4;
};

/* 12-byte packed record of the table behind Unk80089894_K<..>::m24 as read by
 * fn_8008AC94: three words split into 11/12/9, 10/10/12 and 13/13/2/4 bits. */
struct Unk80089894_Pack {
    unsigned a0 : 11;
    unsigned a1 : 12;
    unsigned a2 : 9;
    unsigned b0 : 10;
    unsigned b1 : 10;
    unsigned b2 : 12;
    unsigned c0 : 13;
    unsigned c1 : 13;
    unsigned c2 : 2;
    unsigned c3 : 4;
};

struct Unk80089894_PackTab {
    char pad0[0x1C];
    unsigned m1C;
    char pad20[4];
    Unk80089894_Pack* m24;
};

#endif
