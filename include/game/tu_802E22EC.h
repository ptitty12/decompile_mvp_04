#ifndef GAME_TU_802E22EC_H
#define GAME_TU_802E22EC_H

/*
 * Declarations for game/tu_802E22EC.cpp (reconstructed, placeholder names).
 * Geomlib shape classes: every object starts with a type byte at +0 and has
 * its vptr at +0x5C (base vtable lbl_80661618, derived vtables lbl_80664B18
 * (type 0xA, group: assert strings name geomgroup.cpp), lbl_80664B58 (type 6,
 * mesh: geommesh.cpp), lbl_80664B98). Base slots: 1 = flag setter (called when
 * +3 is 0), 2 = destructor (called with 3 to delete), 4 = clone(x),
 * 5 = copy(other, x). The base destructor is inline (vptr store only);
 * operator delete forwards to slot 5 of the service at lbl_8061F68C
 * (include/game/tu_802DE2C8.h), and the "X"-tagged allocator is its slot 4.
 */
#include "game/tu_802DE2C8.h"

extern int lbl_8061F684;
extern int lbl_8068DF48;

/* Data of the base: type +0, flag bytes +1/+3, parent +4, words +8/+0xC (copied
 * by fn_802E21FC), 0x5C bytes in total. */
class Unk802E22EC_BD {
public:
    unsigned char m0;
    unsigned char m1;
    char pad2;
    unsigned char m3;
    Unk802E22EC_BD* m4;
    int m8;
    int mC;
    char pad10[0x30 - 0x10];
    Unk802E0914_Box m30;
    char pad4C[0x5C - 0x4C];
};

class Unk802E22EC_B : public Unk802E22EC_BD {
public:
    Unk802E22EC_B()
    {
        *fn_8035DD7C() = 0;
        *fn_8035DD84() = lbl_8061F684;
        *fn_8035DD8C() = 0;
        m3 = 0;
        *fn_8035DD94() = &lbl_8068DF48;
        fn_8035DD9C(1);
    }
    int* fn_8035DD7C();
    int* fn_8035DD84();
    char* fn_8035DD8C();
    int** fn_8035DD94();
    void fn_8035DD9C(int a);
    virtual void s1();
    virtual ~Unk802E22EC_B() {}
    virtual void s3();
    virtual Unk802E22EC_B* s4(int x);
    virtual void s5(Unk802E22EC_B* o, int x);
    virtual void s6(char* a, int b);
    void fn_802E3770();
    static void operator delete(void* p) { lbl_8061F68C->s5(p); }
    static void operator delete[](void* p) { lbl_8061F68C->s5(p); }
    static void* operator new(unsigned size, const char* tag) { return lbl_8061F68C->s4(size, tag); }
};

/* Two-element array at +0x60 of the type with vtable lbl_80664BD8 (fn_802E22C4, fn_802E2218);
 * elements are 0x18C-byte shapes. */
class Unk802E22C4_E : public Unk802E22EC_B {
public:
    char pad60[0x18C - 0x60];
};
class Unk802E22C4_T : public Unk802E22EC_B {
public:
    Unk802E22C4_E m60[2];
    virtual ~Unk802E22C4_T();
};
void fn_802E22C4(Unk802E22C4_T* t);

/* Box shared with the collider code (include/game/tu_802DE2C8.h): min xyz at +0/4/8,
 * max xyz at +0x10/0x14/0x18, at +0x30 of every shape. fn_8035F4EC is its copy
 * constructor. */
void fn_8035F4EC(Unk802E0914_Box* dst, Unk802E0914_Box* src);

/* Type 0xA (vtable lbl_80664B18): child array. */
class Unk802E313C : public Unk802E22EC_B {
public:
    int m60;
    Unk802E22EC_B** m64;
    Unk802E313C();
    virtual ~Unk802E313C();
    void fn_802E3254();
    void fn_802E32F8(int n);
    void fn_802E33D0(Unk802E313C* o, int x);
    void fn_802E3470(Unk802E313C* o, int x);
    void fn_802E35DC(char* a, int b);
    void fn_802E366C();
};
Unk802E313C* fn_802E3530(Unk802E313C* o, int x);

/* 64-byte block copied into +0x60 of the type 6 object (fn_802E4B98, fn_802E61BC). */
struct Unk802E4B98_M {
    int m[16];
};
extern Unk802E4B98_M lbl_806B98B0;
struct Unk802E4B98_V4 {
    float m0;
    float m4;
    float m8;
    float mC;
    Unk802E4B98_V4() {}
    Unk802E4B98_V4(float x, float y, float z, float w)
    {
        m0 = x;
        m4 = y;
        m8 = z;
        mC = w;
    }
    Unk802E4B98_V4& operator=(const Unk802E4B98_V4& o)
    {
        m0 = o.m0;
        m4 = o.m4;
        m8 = o.m8;
        mC = o.mC;
        return *this;
    }
};
/* Shared record whose use count is at +0 (fn_802E5840 decrements it). */
struct Unk802E22EC_Counted {
    int m0;
};

/* 16-byte elements of the two arrays of the type 6 object (fn_802E5714). */
struct Unk802E5714_E {
    float m[4];
    Unk802E5714_E();
};
struct Unk802E5714_F {
    float m[4];
    Unk802E5714_F() {}
};

/* 0x90-byte elements of the array at +0 of the manager (fn_802E3980): vptr at +0x74. */
class Unk802E3980_ED {
public:
    char pad0[0x74];
};
class Unk802E3980_EV : public Unk802E3980_ED {
public:
    virtual ~Unk802E3980_EV() {}
};
class Unk802E3980_E : public Unk802E3980_EV {
public:
    char pad78[0x90 - 0x78];
    static void operator delete[](void* p) { lbl_8061F68C->s5(p); }
};
struct Unk802E3980_Mgr {
    Unk802E3980_E* m0;
    int m4;
    void fn_802E3980();
};

/* Allocator block (fn_802E3A44 resets it). */
struct Unk802E3A44_Blk {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    void fn_802E3A44();
};

/* Type 6 (vtable lbl_80664B58, geommesh.cpp): block at +0x60, scale at +0xE0. */
class Unk802E4B98 : public Unk802E22EC_B {
public:
    Unk802E4B98_M m60;
    char padA0[0xE0 - 0xA0];
    float mE0;
    float mE4;
    float mE8;
    float mEC;
    char padF0[4];
    Unk802E22EC_Counted* mF4;
    int mF8;
    Unk802E5714_E* mFC;
    int m100;
    Unk802E5714_F* m104;
    int m108;
    Unk802E4B98();
    virtual ~Unk802E4B98();
    void fn_802E4D30();
    void fn_802E4D50(Unk802E4B98* o, Unk802E4B98_V4* v);
    void fn_802E4DFC(Unk802E4B98* o, Unk802E4B98_V4* v);
    void fn_802E4F8C(Unk802E22EC_Counted* c, int a, Unk802E4B98_V4* v);
    void fn_802E5714(int a, int b);
    void fn_802E5840();
    void fn_802E60C4();
};
Unk802E4B98* fn_802E4EE0(Unk802E4B98* o, Unk802E4B98_V4* v);

/* Type with vtable lbl_80664B98: block at +0x60, vector at +0x160, child at +0x170. */
class Unk802E6124 : public Unk802E22EC_B {
public:
    Unk802E4B98_M m60;
    char padA0[0x160 - 0xA0];
    Unk802E4B98_V4 m160;
    Unk802E22EC_B* m170;
    Unk802E6124()
    {
        m0 = 3;
        m170 = 0;
    }
    virtual ~Unk802E6124();
    void fn_802E715C();
    void fn_802E624C(Unk802E6124* o, Unk802E4B98_V4* v);
    void fn_802E61BC(const Unk802E4B98_M* m, const Unk802E4B98_V4* v);
};

#endif
