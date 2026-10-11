#ifndef GAME_TU_8017D640_H
#define GAME_TU_8017D640_H

/*
 * Declarations for game/tu_8017D640.cpp (reconstructed; placeholders only).
 */

/* Root of the event/script classes (vtable 0x806849D0, dtor 0x8037B424), as in
 * tu_8016F45C.h plus the hash constructor 0x8037B3E8. */
class Unk8037B3E8 {
public:
    Unk8037B3E8(unsigned int hash);
    virtual ~Unk8037B3E8();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
};

void* operator new(unsigned int size, int heap);        /* 0x80377428 */
extern int lbl_806EF9B4;                                /* default heap */

struct Unk8017DD64_Item {
    char pad0[0x78];
    int m78;
    char pad7C[0xE64 - 0x7C];
};
struct Unk8017DD64_Rec {
    char pad0[0x14];
    Unk8017DD64_Item* m14;
};
struct Unk8017DD64_Ctx {
    char pad0[0x6F8];
    Unk8017DD64_Rec* m6F8;
    char pad6FC[0x704 - 0x6FC];
    int m704;
};

struct Unk8017EE58_Rec {
    char pad0[0x1CCA];
    unsigned char m1CCA;
};
struct Unk8017EE58_Mid {
    char pad0[0x14];
    Unk8017EE58_Rec* m14;
};
struct Unk8017EE58_Ctx {
    char pad0[0x6F8];
    Unk8017EE58_Mid* m6F8;
};

/* Pointer-owning handle: ctx at +0, m8/mC/m10 state, vptr at +0x18. */
struct Unk8017EE24_T {
    Unk8017EE58_Ctx* m0;
    char pad4[4];
    int m8;
    int mC;
    int m10;
};

/* Table object: ints at +0 and +0x50 (20 each), +0xA0, +0xA4 and +0x110 (27 each). */
struct Unk8017EED0_T {
    int m0[20];
    int m50[20];
    int mA0;
    int mA4[27];
    int m110[27];
};

class Unk8017EDF0 {
public:
    virtual ~Unk8017EDF0();
    char pad4[0x18];
};

/* Event class, 0x70 bytes, hash 0xEF8A9748 (vtable 0x806602A8). */
class Unk8017EF7C : public Unk8037B3E8 {
public:
    Unk8017EF7C();
    virtual ~Unk8017EF7C();
    Unk8037B3E8* fn_vslot5();
    char pad4[0x70 - 4];
};

struct Unk8017F8A0_T {
    char pad0[0x28];
    float m28;
    float m2C;
    float m30;
    char pad34[0x48 - 0x34];
    int m48;
};

void fn_8017EF00(void* p);
void fn_801800B8(void* p);
void fn_8017FF74(void* p);

#endif
