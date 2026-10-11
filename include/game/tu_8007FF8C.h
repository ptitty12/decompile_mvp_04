/*
 * Types for game/tu_8007FF8C.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_8007FF8C_H
#define GAME_TU_8007FF8C_H

/* Block behind Unk8007FF8C_E::m1C (fn_8007FF8C reads the int at +0x800; the
 * other fn_8007FF98.. methods pass the pointer to fn_8059Axxx). */
struct Unk8007FF8C_EI {
    char pad0[0x800];
    int m800;
};

struct Unk8007FF8C_E {
    char pad0[0x1C];
    Unk8007FF8C_EI* m1C;
};

/* 0x18-byte element of the list behind Unk8007FF8C_G::m20 (fn_8008007C). */
struct Unk8007FF8C_Item {
    char pad0[0x18];
};

/* List header: count at +0, 0x18-byte items from +4. */
struct Unk8007FF8C_List {
    unsigned m0;
    Unk8007FF8C_Item m4[1];
};

/* 0x20-byte element of the array behind Unk8007FF8C_G::m24 (fn_800800C8,
 * fn_80080110: indices 0..0x18). */
struct Unk8007FF8C_Slot {
    char pad0[0x20];
};

/* Buffer of three halfwords that fn_80329FA0 fills in (fn_80080198 returns the
 * second; a 4-byte buffer changes the frame, so the size is 6). */
struct Unk8007FF8C_Pair {
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

/* Block behind Unk8007FF8C_G::mC; its +8 is a pointer to a halfword. */
struct Unk8007FF8C_CI {
    char pad0[8];
    unsigned short* m8;
};

/* Object of fn_8007FF8C..fn_80080198: pointers at +0xC, +0x20, +0x24, +0x28
 * (and an int at +0x1F0 read by fn_800801DC). */
struct Unk8007FF8C_G {
    char pad0[0xC];
    Unk8007FF8C_CI* mC;
    char pad10[0xC];
    Unk8007FF8C_EI* m1C;
    Unk8007FF8C_List* m20;
    Unk8007FF8C_Slot* m24;
    void* m28;
    char pad2C[0x1F0 - 0x2C];
    int m1F0;
};

/* 12-byte record: two bytes, then two ints (fn_80080B98 clears, fn_80080BB4
 * fills; the entries at Unk8007FF8C_Z::q are indexed with stride 0xC). */
struct Unk8007FF8C_Q {
    unsigned char m0;
    unsigned char m1;
    int m4;
    int m8;
};

/* 0x3C-byte block (two copies in Unk8007FF8C_Y, at +0x1CC8 and +0x1D04):
 * six bytes, an int at +8 (set to 1 by fn_80082034), four Q from +0xC.
 * fn_80080CEC / fn_80080DBC copy one block over the other. */
struct Unk8007FF8C_Z {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    short pad6;
    int m8;
    Unk8007FF8C_Q q[4];
};

/* Entry of the singly linked list at Unk8007FF8C_Y::m14 (fn_800820C0 searches
 * it by halfword at +4, byte at +6 and the 2-bit field at bits 24-25 of the
 * word at +4; fn_80082108 tests bit 31 of that word). */
struct Unk8007FF8C_Node {
    Unk8007FF8C_Node* m0;
    unsigned short h4;
    unsigned char b6;
    unsigned c : 2;
    unsigned mid : 5;
    unsigned f : 1;
};

/* Object of fn_80080BFC onwards: two 0xE64-byte sub-objects from +0 (the
 * second at +0xE64), a list head at +0x14, an int at +0x164, objects at
 * +0x198 and +0xFFC, two Z blocks at +0x1CC8 and +0x1D04, then an int and
 * floats from +0x1D40. */
struct Unk8007FF8C_Y {
    char pad0[0x14];
    Unk8007FF8C_Node* m14;
    char pad18[0x164 - 0x18];
    int m164;
    char pad168[0x1CC8 - 0x168];
    Unk8007FF8C_Z z0;
    Unk8007FF8C_Z z1;
    int m1D40;
    float m1D44;
    float m1D48;
    float m1D4C;
    int m1D50;
};

/* Word of the table behind Unk8007FF8C_I::m24 (fn_80080724 / fn_80080828):
 * an 11-bit, a 6-bit and a 10-bit field. */
struct Unk8007FF8C_W {
    unsigned a : 11;
    unsigned b : 6;
    unsigned c : 10;
    unsigned d : 5;
};

/* Object of the constructor fn_800805FC: base part, a count at +0x1C, the
 * vptr at +0x20 and the table at +0x24. */
struct Unk8007FF8C_I {
    char pad0[0x14];
    void* m14;
    char pad18[4];
    unsigned m1C;
    void* m20;
    Unk8007FF8C_W* m24;
};

/* Counter of the two-level loops in this unit: i is stored in a local object
 * (it has a destructor, which keeps it in memory); Next() steps i up to N + 1
 * and returns it. */
template <int N>
struct Unk8007FF8C_Iter {
    int i;
    Unk8007FF8C_Iter() { i = 0; }
    ~Unk8007FF8C_Iter() {}
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

/* Vtable entry of Unk8007FF8C_I at +0x28 (fn_800808F8, fn_80080A08): a
 * this-adjustment halfword and a function pointer. */
struct Unk8007FF8C_VT2 {
    char pad0[0x28];
    short delta;
    short pad2A;
    int (*pfn)(void* self, int k, int a);
};

/* Vtable entry at +8 of an object's table (fn_80080B3C). */
struct Unk8007FF8C_VT {
    char pad0[8];
    short delta;
    short padA;
    void (*pfn)(void* self, int a, void* p, int n);
};

struct Unk8007FF8C_VObj {
    char pad0[4];
    Unk8007FF8C_VT* m4;
};

#endif
