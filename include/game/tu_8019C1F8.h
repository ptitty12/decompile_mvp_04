#ifndef GAME_TU_8019C1F8_H
#define GAME_TU_8019C1F8_H

/*
 * Types for src/game/tu_8019C1F8.cpp (reconstructed). Names are placeholders;
 * layouts come from the offsets observed in the functions of the unit.
 */
#include "game/tu_80194D44.h"

/* State-machine handlers (one class per state id): a data-only 8-byte part, the
 * polymorphic root Unk803785E4_Virt (ctor 0x803785E4 initialises the data and stores
 * its vptr at +8; vtable slots 2..6 are 0x803443D0, 0x803443CC and three per-state
 * handlers), then the common fields mC/m10/m14 (state id)/m18 (owner). The per-state
 * dtors (0x8035A3A4...) and vtables are in other units, so only the dtor is declared. */
struct Unk803785E4_Data {
    char pad0[8];
};
class Unk803785E4_Virt : public Unk803785E4_Data {
public:
    Unk803785E4_Virt();
    virtual ~Unk803785E4_Virt();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
/* Owner object (a stadium/game context): state at +0x6F4, current object at +0x6CC,
 * sub-objects at +0x700 / +0x710, the state list at +0x560. */
struct Unk8019E3C0_Own {
    char pad0[0x6CC];
    void* m6CC;
    char pad6D0[0x6F4 - 0x6D0];
    int m6F4;
    char pad6F8[0x700 - 0x6F8];
    void* m700;
    char pad704[0x710 - 0x704];
    void* m710;
};
class Unk8019E3C0_Base : public Unk803785E4_Virt {
public:
    int mC;
    int m10;
    int m14;
    Unk8019E3C0_Own* m18;
    Unk8019E3C0_Base(int id, Unk8019E3C0_Own* owner)
    {
        mC = 0;
        m10 = 0;
        m14 = id;
        m18 = owner;
    }
};
class Unk8019E3C0 : public Unk8019E3C0_Base {
public:
    Unk8019E3C0(Unk8019E3C0_Own* owner);
    virtual ~Unk8019E3C0();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    float m1C;
};
class Unk8019E55C : public Unk8019E3C0_Base {
public:
    Unk8019E55C(Unk8019E3C0_Own* owner);
    virtual ~Unk8019E55C();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Unk8019E6A4 : public Unk8019E3C0_Base {
public:
    Unk8019E6A4(Unk8019E3C0_Own* owner);
    virtual ~Unk8019E6A4();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    char pad1C[0x10];
};
class Unk8019EB10 : public Unk8019E3C0_Base {
public:
    Unk8019EB10(Unk8019E3C0_Own* owner);
    virtual ~Unk8019EB10();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    int m1C;
};
class Unk8019EF70 : public Unk8019E3C0_Base {
public:
    Unk8019EF70(Unk8019E3C0_Own* owner);
    virtual ~Unk8019EF70();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Unk8019F0F8 : public Unk8019E3C0_Base {
public:
    Unk8019F0F8(Unk8019E3C0_Own* owner);
    virtual ~Unk8019F0F8();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    int m1C;
    int m20;
};
class Unk8019F414 : public Unk8019E3C0_Base {
public:
    Unk8019F414(Unk8019E3C0_Own* owner);
    virtual ~Unk8019F414();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Unk8019F48C : public Unk8019E3C0_Base {
public:
    Unk8019F48C(Unk8019E3C0_Own* owner);
    virtual ~Unk8019F48C();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Unk8019F5EC : public Unk8019E3C0_Base {
public:
    Unk8019F5EC(Unk8019E3C0_Own* owner);
    virtual ~Unk8019F5EC();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Unk8019F728 : public Unk8019E3C0_Base {
public:
    Unk8019F728(Unk8019E3C0_Own* owner);
    virtual ~Unk8019F728();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Unk8019F81C : public Unk8019E3C0_Base {
public:
    Unk8019F81C(Unk8019E3C0_Own* owner);
    virtual ~Unk8019F81C();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

extern "C" {
void fn_8033E464(void* list, void* obj);
void fn_8033E3FC(void* o, int a);
void fn_8017B0D8(void* p);
void fn_801594A8(void* p);
void fn_8017BBF4(void* p);
void fn_8017AF30(void* p);
void fn_8017AF7C(void* p);
void fn_80158CB8(void* p);
void fn_8017B0A4(void* p);
int fn_8040ABA0();
void fn_801A505C(void* c);
void fn_8017BB60(void* p);
}

#endif /* GAME_TU_8019C1F8_H */
