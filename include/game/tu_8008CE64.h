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

#endif
