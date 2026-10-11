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
struct Unk8019F040_Rec;
struct Unk8019E3C0_Own {
    char pad0[0x6CC];
    void* m6CC;
    char pad6D0[0x6F4 - 0x6D0];
    int m6F4;
    Unk801808A4_Y* m6F8;
    char pad6FC[4];
    void* m700;
    char pad704[0x710 - 0x704];
    void* m710;
    char pad714[0x71C - 0x714];
    Unk8019F040_Rec* m71C;
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
    int m1C;
    int m20;
    int m24;
    int m28;
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
    int m1C;
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

/* Object reached through the owner's +0x700 pointer: vptr at +0, virtual 1 takes no
 * arguments (called by the state handlers). */
class Unk8019E418_P {
public:
    virtual void v0();
    virtual void v1();
};
/* Destructor-only helper (fn_8019D014): out-of-line empty dtor. */
struct Unk8019D014 {
    ~Unk8019D014();
};
struct Unk8019F7A8_Own : public Unk8019E3C0_Own {
};
/* Global game object (lbl_80619D10): vptr at +0x18, virtual 25 (vtable offset 0xC8) is
 * queried by the state handlers. */
struct Unk80619D10_Base {
    char pad0[0x18];
};
class Unk80619D10_Virt : public Unk80619D10_Base {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual int v25();
};
struct Unk8019E6FC_Sub {
    char pad0[0x7C];
    int m7C;
};
struct Unk8019E6FC_Mid {
    char pad0[0x3B0];
    Unk8019E6FC_Sub* m3B0;
};
struct Unk8019F040_Rec {
    char pad0[0x68];
    int m68;
};
struct Unk8019E490_Rec {
    char pad0[4];
    int m4;
};
struct Unk8019E490_G {
    char pad0[8];
    void* m8;
    void* mC;
};
extern Unk8019E490_G* lbl_8061B8C0;
extern float lbl_8068BEB0;
extern float lbl_8068BEB4;
inline float Unk8019CF3C_Norm(float lo, float t, float hi)
{
    float span = hi - lo;
    if (!(span <= 0.0f))
        return (t - lo) / span;
    return 0.0f;
}
inline float Unk8019CF3C_Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}
extern int lbl_8061B9C8;
extern Unk80619D10_Virt* lbl_80619D10;

extern "C" {
void fn_8017AFA0(void* p);
void fn_80157734(void* p);
int fn_8011AA4C(void* p);
Unk8019E490_Rec* fn_801A04A8(void* p, int a);
void fn_8031E1D4(void* p, const char* s);
void fn_8017B238(void* p);
int fn_801A2034(void* c, int a);
int fn_80162534(void* p);
void fn_8033E530(void* list, int a);
void fn_8033E5C4(void* list, int a);
void fn_80158994(void* p);
void* fn_801A6D84(void* o, int a);
void fn_80169674(void* p);
void fn_801593F8(void* p);
void fn_800AB9A8(void* p, int a);
void fn_8017BE28(void* p);
void fn_801580A0(void* p);
void fn_8019CD04(void* o);
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
