/*
 * Types for game/tu_80082248.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_80082248_H
#define GAME_TU_80082248_H

/* Node of a search tree (left/right links at +4/+8, key at +0x10, a
 * sentinel node lbl_8061932C ends every branch). fn_80082F4C and
 * fn_80082FC4 walk it. The word at +0xC holds a flag in its low bit
 * (fn_80082308 and fn_800824D4 clear it). */
struct Unk80082248_Node {
    Unk80082248_Node* m0;
    Unk80082248_Node* m4;
    Unk80082248_Node* m8;
    unsigned mC;
    int m10;
    void* m14;
};

/* Entry of the chain at Unk80082248_Node::m14 (the word at +4 carries a flag
 * in its low bit, cleared by fn_80082308). */
struct Unk80082248_Link {
    Unk80082248_Link* m0;
    unsigned m4;
};

/* The tree object (fn_80082318 constructs it, fn_80082510 clears it): root
 * at +0, the cached last-found node at +4, 0x15FA0 bytes in all. Only the
 * fields the constructor stores are named. */
struct Unk80082248_Tree {
    Unk80082248_Node* m0;
    Unk80082248_Node* m4;
    Unk80082248_Node m8[3750]; /* 0x18 bytes each, 0x15F90 in all (fn_8008241C) */
    int m15F98;
    /* The vptr at +0x15F9C is the compiler's own (fn_80082318 stores it through
     * a cast); fn_80083C54 deletes the tree through its virtual destructor. */
    virtual ~Unk80082248_Tree() {}
};

/* Holder with a pointer to the tree at +0 and a vptr-like pointer at +4
 * (fn_80083BEC constructs it). */
struct Unk80082248_Holder {
    Unk80082248_Tree* m0;
    void* m4;
};

/* Record that fn_80083258 builds in its last argument (halfword at +4,
 * byte at +6, a 2-bit field at bits 24-25 of the word at +4); the same
 * layout as Unk8007FF8C_Node's tail. */
struct Unk80082248_Key {
    int m0;
    unsigned short h4;
    unsigned char b6;
    unsigned c : 2;
    unsigned rest : 6;
};

/* 0x14-byte record of the ring at lbl_80619324 (0x5000 of them): fn_80082248
 * hands one out, fn_80083778 copies one whole. Word at +4 holds a 16-bit id,
 * a byte, two 2-bit fields and the in-use flag in its low bit. */
struct Unk80082248_Rec {
    int m0;
    unsigned short h4;
    unsigned char b6;
    unsigned c : 2;
    unsigned d : 2;
    unsigned e : 3;
    unsigned used : 1;
    int m8;
    int mC;
    int m10;
};

/* Three words copied out of a record (+8) by fn_80083838. */
struct Unk80082248_V3 {
    int m0;
    int m4;
    int m8;
};

/* Stream the save/load slots write through (same shape as Unk80070DDC_Stream:
 * word at +0, vptr at +4, slot 1 = transfer(cursor, data, size), slot 2 = flag
 * test). The base constructor is fn_80353218. */
struct Unk80082248_Stream0 {
    int m0;
};
struct Unk80082248_Stream : Unk80082248_Stream0 {
    Unk80082248_Stream(); /* fn_80353218 */
    virtual int v08(char** cursor, void* data, int size);
    virtual int v10();
};

#endif
