/*
 * Declarations for animation/tu_802A6334.cpp (reconstructed).
 *
 * Nothing here comes from original headers; see include/game/chooser.h for the
 * conventions. Names are placeholders: Unk<addr> = class named after its ctor
 * or first method.
 */
#ifndef GAME_TU_802A6334_H
#define GAME_TU_802A6334_H

#include "game/chooser.h"

/* One node of the pool's lists (0x10 bytes, ctor inline; the four stores in
 * fn_802A64E8, fn_802A65E4 and fn_802A66A0 are its constructor/Clear).
 * m0 is the payload pointer, m4 the sort key, m8/mC the next/prev links of the
 * doubly linked lists. Evidence: fn_802A6660 (link), fn_802A66A0 (unlink),
 * fn_802A6458 (sorted insert by m4) in tu_802A6334.cpp; the warps' tail
 * (animation/warps/tu_802A4584.cpp, Unk802A6250_Node) walks the used list
 * through m0 and m8. */
struct Unk802A6334_Node {
    void* m0;
    int m4;
    Unk802A6334_Node* m8;
    Unk802A6334_Node* mC;
    Unk802A6334_Node() { mC = 0; m8 = 0; m0 = 0; m4 = 0; }
    void Clear() { mC = 0; m8 = 0; m0 = 0; m4 = 0; }
};

/* Node pool with a free list and a sorted used list (ctor 0x802A6334, dtor
 * 0x802A638C, vtable 0x80664050 with only the dtor). Size 0x1C: the data is
 * 0x18 bytes, the vptr sits at +0x18. Embedded at +0x20 of Unk802A62CC
 * (animation/warps/tu_802A4584.cpp), where its mC is the list head read by
 * slot 12.
 *   m0   nodes allocated so far
 *   m4   nodes on the free list
 *   m8   growth step
 *   mC   used list (sorted by key, ascending)
 *   m10  free list
 *   m14  allocated blocks (the first node of each array links the blocks). */
class Unk802A6334 {
public:
    Unk802A6334(int count, int step);              /* 0x802A6334 */
    virtual ~Unk802A6334();                        /* 0x802A638C */
    void fn_802A63F8(Unk802A6334_Node* node);      /* release */
    Unk802A6334_Node* fn_802A6458(void* obj, int key);   /* take a node, insert sorted */
    void fn_802A64E8(int count);                   /* grow to count nodes */
    Unk802A6334_Node* fn_802A65E4();               /* take a node from the free list */
    void fn_802A6660(Unk802A6334_Node* prev, Unk802A6334_Node* next,
                     Unk802A6334_Node** head, Unk802A6334_Node* node);   /* link */
    void fn_802A66A0(Unk802A6334_Node* node, Unk802A6334_Node** head);  /* unlink */

    int m0;
    int m4;
    int m8;
    Unk802A6334_Node* mC;
    Unk802A6334_Node* m10;
    Unk802A6334_Node* m14;
};

/* Mid class of the event classes (dtor 0x8038B7E4, vtable 0x806850A0, no data;
 * every static local of fn_802A70F8 derives from it, and their inlined dtors
 * leave only this class's vptr store before the root's dtor call). */
class Unk8038B7E4 : public Unk8037B3E8 {
public:
    Unk8038B7E4(unsigned int hash) : Unk8037B3E8(hash) {}
};

#endif /* GAME_TU_802A6334_H */
