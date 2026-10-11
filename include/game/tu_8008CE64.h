/*
 * Types for game/tu_8008CE64.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_8008CE64_H
#define GAME_TU_8008CE64_H

/* Element types of the table classes (strides proven by the mulli/slwi
 * factors in each family's constructor, clear and virtual-call methods). */
struct Unk8008CE64_T10 {
    char pad0[0x10];
};
struct Unk8008CE64_T1C {
    char pad0[0x1C];
};
struct Unk8008CE64_T3C {
    char pad0[0x3C];
};

/* Table class: base part, a result pointer at +0x14, a count at +0x1C, the
 * vptr at +0x20 and the table at +0x24 (same shape as Unk8007FF8C_I). */
template <class T>
struct Unk8008CE64_K {
    char pad0[0x14];
    void* m14;
    char pad18[4];
    unsigned m1C;
    void* m20;
    T* m24;
};

/* Vtable entry at +8 of an object's table: this-adjustment and function
 * pointer. */
struct Unk8008CE64_VT {
    char pad0[8];
    short delta;
    short padA;
    void (*pfn)(void* self, int a, void* p, int n);
};

struct Unk8008CE64_VObj {
    char pad0[4];
    Unk8008CE64_VT* m4;
};

/* Vtable entry at +0x28: this-adjustment and function pointer (the getter
 * methods that call through m20). */
struct Unk8008CE64_VT2 {
    char pad0[0x28];
    short delta;
    short pad2A;
    int (*pfn)(void* self, int k, int a);
};

struct Unk8008CE64_G {
    char pad0[0x20];
    Unk8008CE64_VT2* m20;
};

/* Two-field holder of fn_80090744 / fn_80090814: two owned pointers at +4 and
 * +8 and a word at +0. */
struct Unk8008CE64_Own {
    int m0;
    void* m4;
    void* m8;
};

/* Object type of the pointer-to-member tables (lbl_805B6C50): the member
 * functions are unknown, only the call shape is. It needs a virtual function,
 * or the compiler drops the virtual-call half of the member-pointer call. */
struct Unk8008CE64_Obj {
    virtual float M(int a);
};
typedef float (Unk8008CE64_Obj::*Unk8008CE64_Pmf)(int);

/* 0x1C-byte element read by fn_8008F950: a halfword and a flag bit at bit 16
 * of the first word. */
struct Unk8008CE64_E1C {
    unsigned short h0;
    unsigned f : 1;
    unsigned rest : 15;
    char pad4[0x18];
};

/* Counter of fn_8008FBE8: i lives in a local object with an (empty)
 * destructor, which keeps it in memory; Next() steps i up to N + 1. */
template <int N>
struct Unk8008CE64_Iter {
    int i;
    Unk8008CE64_Iter() { i = 0; }
    ~Unk8008CE64_Iter() {}
    int Next()
    {
        int n;
        if (i > N)
            n = i;
        else
            n = i + 1;
        i = n;
        return n;
    }
};

/* Store-only variant of the counter above (fn_8008FBE8, fn_8008FC40): the
 * slot is written, but the loop reads the value it passes in. */
template <int N>
struct Unk8008CE64_IterW {
    int i;
    Unk8008CE64_IterW() { i = 0; }
    ~Unk8008CE64_IterW() {}
    int Next(int c)
    {
        int n;
        if (c > N)
            n = c;
        else
            n = c + 1;
        i = n;
        return n;
    }
};

/* 0x3C-byte packed record behind Unk8008CE64_K<Unk8008CE64_T3C>::m24, as read by
 * fn_8008CFD8 (55 fields in the first eight words; widths from the shift/mask pairs). */
struct Unk8008CE64_PackE {
    unsigned short h0;
    unsigned short h2;
    unsigned f02 : 6;
    unsigned f03 : 8;
    unsigned f04 : 7;
    unsigned f05 : 4;
    unsigned f06 : 5;
    unsigned f07 : 2;
    unsigned f08 : 2;
    unsigned f09 : 1;
    unsigned f0A : 3;
    unsigned f0B : 1;
    unsigned f0C : 4;
    unsigned f0D : 7;
    unsigned f0E : 4;
    unsigned f0F : 4;
    unsigned f10 : 4;
    unsigned pad0 : 2;
    unsigned f11 : 4;
    unsigned f12 : 4;
    unsigned f13 : 4;
    unsigned f14 : 4;
    unsigned f15 : 4;
    unsigned f16 : 3;
    unsigned f17 : 1;
    unsigned f18 : 8;
    unsigned f19 : 3;
    unsigned f1A : 2;
    unsigned f1B : 2;
    unsigned f1C : 8;
    unsigned f1D : 7;
    unsigned f1E : 7;
    unsigned pad1 : 3;
    unsigned f1F : 8;
    unsigned f20 : 1;
    unsigned f21 : 7;
    unsigned f22 : 1;
    unsigned f23 : 4;
    unsigned f24 : 4;
    unsigned f25 : 3;
    unsigned f26 : 3;
    unsigned pad2 : 1;
    unsigned f27 : 3;
    unsigned f28 : 3;
    unsigned f29 : 2;
    unsigned f2A : 2;
    unsigned f2B : 3;
    unsigned f2C : 10;
    unsigned f2D : 1;
    unsigned f2E : 2;
    unsigned f2F : 2;
    unsigned f30 : 1;
    unsigned pad3 : 3;
    unsigned f31 : 7;
    unsigned f32 : 5;
    unsigned f33 : 1;
    unsigned f34 : 2;
    unsigned f35 : 2;
    unsigned f36 : 3;
    unsigned pad4 : 12;
    char pad20[0x1C];
};

struct Unk8008CE64_PackTabE {
    char pad0[0x1C];
    unsigned m1C;
    char pad20[4];
    Unk8008CE64_PackE* m24;
};

/* Packed 0x10-byte record behind K<..>::m24 as read by fn_8008ED04 (27 fields; widths from the shift/mask pairs). */
struct Unk8008CE64_PackF {
    unsigned f00 : 7;
    unsigned f01 : 7;
    unsigned f02 : 2;
    unsigned f03 : 2;
    unsigned f04 : 2;
    unsigned f05 : 2;
    unsigned f06 : 2;
    unsigned f07 : 2;
    unsigned f08 : 2;
    unsigned f09 : 2;
    unsigned f0A : 2;
    unsigned f0B : 4;
    unsigned f0C : 4;
    unsigned f0D : 4;
    unsigned f0E : 4;
    unsigned f0F : 4;
    unsigned f10 : 4;
    unsigned f11 : 4;
    unsigned f12 : 4;
    unsigned f13 : 4;
    unsigned f14 : 7;
    unsigned f15 : 7;
    unsigned f16 : 7;
    unsigned f17 : 7;
    unsigned f18 : 7;
    unsigned f19 : 7;
    unsigned f1A : 7;
    unsigned pad0 : 11;
};

struct Unk8008CE64_PackTabF {
    char pad0[0x1C];
    unsigned m1C;
    char pad20[4];
    Unk8008CE64_PackF* m24;
};

#endif
