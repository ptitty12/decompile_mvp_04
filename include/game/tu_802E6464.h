#ifndef GAME_TU_802E6464_H
#define GAME_TU_802E6464_H

/*
 * Declarations for game/tu_802E6464.cpp (reconstructed, placeholder names).
 * More geomlib shape classes on the base of include/game/tu_802E22EC.h.
 * Assert strings name geomskeleton.cpp (type 0xB), geomsphere*.cpp, geomray.cpp,
 * geomobb.cpp. Arrays that carry an element count at -8 are allocated through
 * slot 4 of the service at lbl_8061F68C and freed through slot 5.
 */
#include "game/tu_802E22EC.h"

/* Child entry: shape and the bone index (fn_802E7D88 scales it by 64). */
struct Unk802E78EC_Entry {
    Unk802E22EC_B* m0;
    int m4;
};

/* Type 0xB (vtable lbl_80664AD8, geomskeleton.cpp): m60 entries at m64. */
class Unk802E78EC : public Unk802E22EC_B {
public:
    int m60;
    Unk802E78EC_Entry* m64;
    int m68;
    Unk802E78EC();
    virtual ~Unk802E78EC();
    void fn_802E7A08();
    void fn_802E7AE0(Unk802E78EC_Entry* a, int n);
    void fn_802E7AEC(Unk802E78EC* o, int x);
    void fn_802E7C1C(Unk802E78EC* o, int x);
    void fn_802E7D88(char* mats);
    void fn_802E7E60();
};
Unk802E78EC* fn_802E7CDC(Unk802E78EC* o, int x);

/* Element of the arrays freed by fn_802E8AC4 (0x18C bytes, vptr at +0x5C). */
class Unk802E8AC4_E : public Unk802E22EC_B {
public:
    char pad60[0x18C - 0x60];
};

/* Type 7 (vtable lbl_80664C58, geomspheregroup.cpp): shared record at +0x60,
 * element count at +0x64, element array at +0x68. */
class Unk802E869C : public Unk802E22EC_B {
public:
    Unk802E22EC_Counted* m60;
    int m64;
    Unk802E8AC4_E* m68;
    int m6C;
    Unk802E869C();
    virtual ~Unk802E869C();
    void fn_802E87B8();
    void fn_802E8804(Unk802E869C* o, Unk802E4B98_V4* v);
    void fn_802E8AC4();
    void fn_802E8B6C(Unk802E22EC_Counted* c, int a, Unk802E4B98_V4* v);
    void fn_802E8D1C(Unk802E22EC_B* o);
    void fn_802E8FA4();
};
Unk802E869C* fn_802E884C(Unk802E869C* o, Unk802E4B98_V4* v);

/* Type 8 (vtable lbl_80664C18, geomspheremesh.cpp): two child shapes at +0x60/+0x64. */
class Unk802E8FB0 : public Unk802E22EC_B {
public:
    Unk802E22EC_B* m60;
    Unk802E22EC_B* m64;
    Unk802E8FB0();
    virtual ~Unk802E8FB0();
    void fn_802E90C8();
    void fn_802E9150(Unk802E22EC_B* o);
    void fn_802E9380();
};

/* Float-wise copyable 4-vector (the copy loads and stores floats). */
struct Unk802E7200_V4 {
    float m0;
    float m4;
    float m8;
    float mC;
    Unk802E7200_V4& operator=(const Unk802E7200_V4& o)
    {
        m0 = o.m0;
        m4 = o.m4;
        m8 = o.m8;
        mC = o.mC;
        return *this;
    }
};

/* Type 1 (vtable lbl_80664CD8, geomray.cpp): vectors at +0x60/+0x70, floats at +0xB0..+0xBC. */
class Unk802E7314 : public Unk802E22EC_B {
public:
    Unk802E7200_V4 m60;
    Unk802E7200_V4 m70;
    char pad80[0xB0 - 0x80];
    float mB0;
    float mB4;
    float mB8;
    float mBC;
    Unk802E7314()
    {
        m0 = 1;
        mB0 = 0.0f;
        mB8 = 10000000.0f;
        mBC = 1.0f / mB8;
    }
    virtual ~Unk802E7314();
    void fn_802E7200(Unk802E7314* o, int x);
    void fn_802E7298(Unk802E7314* o, float* s);
    void fn_802E78D4();
};
Unk802E7314* fn_802E7314(Unk802E7314* o, int x);
Unk802E6124* fn_802E65BC(Unk802E6124* o, Unk802E4B98_V4* v);

#endif
