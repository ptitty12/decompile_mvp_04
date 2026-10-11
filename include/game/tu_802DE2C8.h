#ifndef GAME_TU_802DE2C8_H
#define GAME_TU_802DE2C8_H

/*
 * Declarations for game/tu_802DE2C8.cpp (reconstructed, placeholder names).
 * The first functions finish the pad base class Unk803414A4 (slots 46..48,
 * include/game/tu_80008540.h) and the pad manager destructor
 * (include/game/tu_802D73B4.h, vtable lbl_80664868). The rest is the
 * "geomlib" code: its assert strings name /mvp2004/source/common/geomlib/
 * {constraintgroup,conetocone,findintersection}.cpp and geomlib.h, and the
 * message "GeomLib Initialised\n".
 */
#include "game/tu_80008540.h"
#include "game/tu_802D73B4.h"

/* Service object at lbl_8061F68C (vptr at +4): slot 2 is assert(cond, file, line),
 * slot 3 prints a message (fn_802E213C), slot 5 frees an object (fn_802E2218). */
class Unk802DE2C8_Svc {
public:
    int m0;
    virtual ~Unk802DE2C8_Svc();
    virtual void s2(int cond, const char* file, int line);
    virtual void s3(const char* msg);
    virtual void* s4(unsigned size, const char* tag);
    virtual void s5(void* p);
};
extern Unk802DE2C8_Svc* lbl_8061F68C;

/* Node of the intrusive lists used by geomlib.h (prev/next at +0/+4). */
struct Unk802DE2C8_Node {
    Unk802DE2C8_Node* m0;
    Unk802DE2C8_Node* m4;
};
/* List header: first at +0, last at +4, count at +8. */
struct Unk802DE2C8_List {
    Unk802DE2C8_Node* m0;
    Unk802DE2C8_Node* m4;
    int m8;
    ~Unk802DE2C8_List();
    int fn_802E0400(Unk802DE2C8_Node* n);
    int fn_802E04BC(Unk802DE2C8_Node* n);
    void fn_802E056C();
};
/* Free pool at lbl_8061F688: free count at +0xC, first at +0x10, last at +0x14. */
struct Unk802DE2C8_Pool {
    int m0;
    int m4;
    int m8;
    int mC;
    Unk802DE2C8_Node* m10;
    Unk802DE2C8_Node* m14;
    Unk802DE2C8_Pool();
};
extern Unk802DE2C8_Pool* lbl_8061F688;

/* Record copied by fn_802E21FC (words at +8 and +0xC, byte at +1) and the
 * 0x18C-byte elements of the two-element array at +0x60 (fn_802E22C4, fn_802E2218). */
struct Unk802E21FC_R {
    char pad0[1];
    unsigned char m1;
    char pad2[6];
    int m8;
    int mC;
};
void fn_802E21FC(Unk802E21FC_R* d, Unk802E21FC_R* s);
struct Unk802E22C4_E {
    char pad0[8];
    int m8;
    int mC;
    char pad10[0x18C - 0x10];
};
struct Unk802E22C4_T {
    char pad0[8];
    int m8;
    int mC;
    char pad10[0x60 - 0x10];
    Unk802E22C4_E m60[2];
};

/* Axis-aligned box at +0x30 of the collider objects (min xyz at +0/4/8, max xyz
 * at +0x10/0x14/0x18; fn_802E0914). */
struct Unk802E0914_Box {
    float mx;
    float my;
    float mz;
    float pad;
    float Mx;
    float My;
    float Mz;
};
/* Collider (vptr at +0x5C, vtable lbl_80661618): type byte at +0, flag byte at +3,
 * child list (count +0x60, array +0x64). */
class Unk802E0914_ObjD {
public:
    unsigned char m0;
    char pad1[2];
    unsigned char m3;
    char pad4[0x30 - 4];
    Unk802E0914_Box m30;
    char pad4C[0x5C - 0x4C];
};
class Unk802E0914_ObjV : public Unk802E0914_ObjD {
public:
    virtual void s1();
    virtual void s2();
};
class Unk802E0914_Obj : public Unk802E0914_ObjV {
public:
    int m60;
    Unk802E0914_Obj** m64;
};
inline int Unk802E0914_Overlap(Unk802E0914_Box* a, Unk802E0914_Box* b)
{
    return !(a->mx >= b->Mx || a->Mx <= b->mx || a->my >= b->My || a->My <= b->my || a->mz >= b->Mz) && a->Mz > b->mz;
}
struct Unk802E0914_Out {
    int m0;
    int m4;
    int m8;
};

void fn_802DD224(int a, int b);
void fn_802DF870(void* a, void* b, void* c);
void fn_802DFD04(void* a, void* b, void* c);
void fn_802E0E50(void* a, void* b, void* c);

typedef int (*Unk802DE2C8_Fn)();
extern Unk802DE2C8_Fn lbl_806E0B98[12][12];
extern Unk802DE2C8_Fn lbl_806E0554[12][12];
extern int lbl_8061F680;

#endif
