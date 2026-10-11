/*
 * Declarations for src/game/tu_80008540.cpp (reconstructed, nothing here is
 * from original headers).
 *
 * The unit holds two controller ("gcpad") classes:
 *   Unk800085B0 (per-pad object, object size 0x1604) derives from
 *   Unk8000B258 (pad state holder, 0x5C bytes of state at +0x1580) which
 *   derives from Unk803414A4 (button-map base class, 0x1580 bytes).
 * Names are placeholders (Unk<addr> = class named after its ctor, m<offset>,
 * vslotN = vtable slot N) until evidence exists.
 *
 * Evidence for the layouts:
 *  - Unk803414A4: its ctor (fn_803414A4) fills 0x10B entries of 16 bytes at
 *    +0 (five shorts set to -1 at +0..+8 and a float at +0xC), constructs a
 *    sub-object at +0x1558 (dtor fn_802DC9F8 with in_chrg 2, seen in the
 *    inlined base dtor of fn_8000C1B4/fn_8000C23C) and stores its vptr at
 *    +0x157C. fn_8000B360 indexes the entry array: m0[0xEC + n].m0.
 *  - Unk8000B258: fn_8000B258 stores the vptr 0x806494E0 and clears 0x5C
 *    bytes at +0x1580; fn_8000B2AC copies 0x5C bytes there, fn_8000B2A4
 *    returns 0x5C (sizeof the state).
 *  - Unk800085B0: fn_800085B0 stores the vptr 0x80649350 and fields at
 *    +0x15DC..+0x1600; fn_80008540 allocates 0x1604 bytes per object.
 * Vtable slots: the 48 slots of vtable 0x806648E8 (base) are mirrored by
 * the vslotN declarations; slot numbers follow "virtual N at +8N" with the
 * function pointer at +8N+4 (see docs/PATTERNS.md).
 */
#ifndef GAME_TU_80008540_H
#define GAME_TU_80008540_H

void* operator new(unsigned int size, int heap);      /* 0x80377428 */

/* One 16-byte button-map entry (fn_803414A4 initializes +0..+0x8 to -1). */
struct Unk803414A4_Entry {
    short m0;
    short m2;
    short m4;
    short m6;
    short m8;
    short mA;
    float mC;
};

/* Sub-object at +0x1558 of Unk803414A4 (0x24 bytes; fn_802DC9CC ctor,
 * fn_802DC9F8 dtor: frees the pointers at +0xC and +0x10). */
struct Unk802DC9F8 {
    char m0[0x24];
    ~Unk802DC9F8();
};

/* Pad state written by the per-frame update and copied by fn_8000B2AC. */
struct Unk8000B258_State {
    int m0;
    float m4[20];
    int m54;
    float m58;
};

extern const char* lbl_80615848;                      /* "gcpad" */

class Unk803414A4 {
public:
    Unk803414A4_Entry m0[0x10B];
    char pad10B0[0x1558 - 0x10B0];
    Unk802DC9F8 m1558;

    Unk803414A4();
    virtual ~Unk803414A4() {}
    virtual void vslot2();
    virtual void vslot3();
    virtual void vslot4();
    virtual void vslot5();
    virtual int vslot6() = 0;
    virtual int vslot7() = 0;
    virtual float vslot8(int i) = 0;
    virtual void vslot9(int i, float f) = 0;
    virtual const char* vslot10() = 0;
    virtual int vslot11() = 0;
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual float vslot18() = 0;
    virtual void vslot19(float f) = 0;
    virtual void vslot20();
    virtual int vslot21();
    virtual void vslot22(int a, float f);
    virtual void vslot23(int a, float f);
    virtual void vslot24(int a);
    virtual int vslot25(int n);
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot30();
    virtual void vslot31();
    virtual void vslot32();
    virtual void vslot33();
    virtual void vslot34();
    virtual void vslot35();
    virtual void vslot36();
    virtual void vslot37();
    virtual void vslot38();
    virtual void vslot39();
    virtual void vslot40();
    virtual int vslot41() = 0;
    virtual void vslot42(Unk8000B258_State* out) = 0;
    virtual void vslot43(const Unk8000B258_State* s) = 0;
    virtual void vslot44();
    virtual void vslot45();
    virtual void vslot46();
    virtual void vslot47();
    virtual void vslot48();
};

class Unk8000B258 : public Unk803414A4 {
public:
    Unk8000B258_State m1580;

    Unk8000B258();
    virtual ~Unk8000B258() {}
    virtual int vslot6();
    virtual int vslot7();
    virtual float vslot8(int i);
    virtual void vslot9(int i, float f);
    virtual const char* vslot10() { return lbl_80615848; }
    virtual int vslot11() { return 0; }
    virtual float vslot18() { return m1580.m58; }
    virtual void vslot19(float f) { m1580.m58 = f; }
    virtual int vslot25(int n);
    virtual int vslot41();
    virtual void vslot43(const Unk8000B258_State* s);
};

class Unk800085B0 : public Unk8000B258 {
public:
    int m15DC;
    int m15E0;
    int m15E4;
    int m15E8;
    float m15EC;
    int m15F0;
    float m15F4;
    int m15F8;
    int m15FC;
    int m1600;

    Unk800085B0(int idx);
    virtual int vslot21() { return 1; }
    virtual void vslot22(int a, float f);
    virtual void vslot23(int a, float f);
    virtual void vslot24(int a);
    virtual void vslot39();
    virtual void vslot42(Unk8000B258_State* out);
    void fn_8000AEB4();
};

#endif
