/*
 * Types for game/tu_800057D8.cpp (reconstructed; nothing here comes from
 * original headers). The unit is a save/load ("TRC"-message driven) state
 * machine class derived from the base constructed at 0x80170518.
 *
 * Offsets below are what the unit's functions access. Everything is named by
 * offset (m<off>) or address (Unk<addr>) until a string proves a real name.
 */
#ifndef GAME_TU_800057D8_H
#define GAME_TU_800057D8_H

void* operator new(unsigned int size, int heap); /* 0x80377428 */

extern "C" void fn_8040074C(void* p, unsigned n); /* bzero */

/* Entry returned by fn_80170034(info, idx) (info + 0x108 + idx * 4). */
struct Unk80170034_Entry {
    int m0;
    int m4;
};

/*
 * Descriptor at base+0x38. Strings at +0x78, +0x8E and +0xE4 (all passed to
 * string helpers by address), entry table at +0x108.
 */
struct Unk80170034_Info {
    int m0;
    char pad4[0x74];
    char m78[0x16];
    char m8E[0x56];
    char mE4[0x24];
    Unk80170034_Entry* m108[6];
    int m120;
};

/*
 * Message record returned by the service object's slot 21 (poll). m0 is the
 * message type (switch in the state handlers), m4/m8 are sub-codes.
 * Seen in fn_800061C8, fn_800064A0, fn_80006630, fn_80006F60, fn_800071F4,
 * fn_8000733C, fn_800074BC.
 */
struct Unk800074BC_Msg {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int pad14[4];
    int m24;
    int m28;
    int m2C;
    int m30;
    int pad34;
    int m38;
    int pad3C;
    char* m40;
    int pad44;
    int m48;
    int pad4C[2];
    int m54;
};

/* 0x30-byte parameter block at +0x110 handed to the service object. */
struct Unk800058BC_Param {
    Unk800058BC_Param()
    {
        m0 = 0;
        m4 = 0;
        m8 = 0;
        mC = 0;
        m10 = 0;
        m14 = 0;
        m18 = 0;
        m1C = 0;
        m20 = 0;
        m24 = 0;
        m28 = 0;
        m2C = 0;
    }
    char* m0;
    int m4;
    void* m8;
    char* mC;
    int m10;
    char* m14;
    int m18;
    void* m1C;
    void* m20;
    char* m24;
    char* m28;
    int m2C;
};

/* Object returned by the service's slot 26. */
class Unk80005B88_Obj {
public:
    virtual void vslot1();
    virtual int vslot2();
    virtual void vslot3(void* a, void* b);
};

/* Service object at base+0x64 (vtable slots used by the unit, 8 bytes each). */
class Unk80005B88_Svc {
public:
    virtual void vslot1();
    virtual void vslot2();
    virtual void vslot3(void* a);
    virtual void vslot4();
    virtual void vslot5(void* a);
    virtual void vslot6(void* a, void* b);
    virtual void vslot7(void* a, void* b);
    virtual void vslot8(void* a, void* b);
    virtual void vslot9(void* a, void* b);
    virtual void vslot10(void* a);
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot20();
    virtual Unk800074BC_Msg* vslot21(int ms);
    virtual void vslot22(int a, int b);
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual Unk80005B88_Obj* vslot26();
};

/*
 * Base class (ctor 0x80170518, dtor 0x8017061C, vtable 0x8065EDF8): data
 * 0x00..0xD4, vptr at 0xD4, derived data from 0xD8. It declares the 19
 * virtual slots the derived vtable (0x806492A8) uses; slots 4 and 9 are not
 * overridden (0x801757C8, 0x80170B3C).
 */
class Unk80170518 {
public:
    Unk80170518(int mode);
    virtual void fn_80005B88(Unk80170034_Info* info);
    virtual int fn_8000850C(int a);
    virtual int fn_80005B74(int a);
    virtual void fn_801757C8();
    virtual void fn_80005A7C(Unk80170034_Info* info);
    virtual int fn_80005E8C();
    virtual void fn_80005A50();
    virtual void fn_80005F4C(int a, int b, int c);
    virtual void fn_80170B3C();
    virtual void fn_80005C8C();
    virtual void fn_80005E38();
    virtual void fn_80006B60();
    virtual void fn_80006E94();
    virtual void fn_800069B4();
    virtual void fn_800060B4();
    virtual void fn_8000643C();
    virtual void fn_800065B4();
    virtual ~Unk80170518();
    virtual void fn_80005AB0(Unk80170034_Info* info);

    char pad00[0x2C];
    int m2C;
    int m30;
    int m34;
    Unk80170034_Info* m38;
    Unk80170034_Info** m3C;
    int m40;
    int m44;
    int m48;
    int* m4C;
    char m50[0x10];
    int m60;
    Unk80005B88_Svc* m64;
    unsigned short m68[0x1C];
    int mA0;
    int mA4[4];
    int mB4;
    int mB8;
    int mBC;
    int mC0;
    int mC4;
    int mC8;
    int mCC;
    int mD0;
};

struct Unk800058BC_Pair {
    Unk800058BC_Pair()
    {
        m0 = 0;
        m2 = 0;
    }
    short m0;
    short m2;
};

/* 0x30-byte object at +0x158 (cleared in the ctor body) */
struct Unk800058BC_A {
    Unk800058BC_A()
    {
        m0 = 0;
        m4 = 0;
    }
    int m0;
    int m4;
    char pad8[0x20];
    int m28;
    int m2C;
};

/* 8-byte object at +0x188 */
struct Unk800058BC_B {
    Unk800058BC_B() { m4 = 0; }
    int m0;
    int m4;
};

/* Request block built on the stack by fn_800060B4 (0x4C bytes). */
struct Unk800060B4_Req : public Unk800058BC_Param {
    Unk800060B4_Req()
    {
        m30 = 0;
        m3C = 0;
        m40 = 0;
        m44 = 0;
        m48 = 0;
        m38 = 0;
        fn_8040074C(this, 0x4C);
    }
    int m30;
    Unk800058BC_Pair m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
};

/* Entry of the 5-element list at +0x204 (stride 0xC). */
struct Unk800058BC_Item {
    int m0;
    int m4;
    int m8;
};

class Unk800058BC;
typedef void (Unk800058BC::*Unk800058BC_Fn)();

class Unk800058BC : public Unk80170518 {
public:
    Unk800058BC(int mode);
    virtual ~Unk800058BC();
    virtual void fn_80005B88(Unk80170034_Info* info);
    virtual int fn_8000850C(int a);
    virtual int fn_80005B74(int a);
    virtual void fn_80005A7C(Unk80170034_Info* info);
    virtual int fn_80005E8C();
    virtual void fn_80005A50();
    virtual void fn_80005F4C(int a, int b, int c);
    virtual void fn_80005C8C();
    virtual void fn_80005E38();
    virtual void fn_80006B60();
    virtual void fn_80006E94();
    virtual void fn_800069B4();
    virtual void fn_800060B4();
    virtual void fn_8000643C();
    virtual void fn_800065B4();
    virtual void fn_80005AB0(Unk80170034_Info* info);

    /* non-virtual state handlers (targets of the pointer at +0x144) */
    void fn_800061C8();
    void fn_800064A0();
    void fn_80006630();
    void fn_80006A2C();
    void fn_80006C14();
    void fn_80006F60();
    void fn_80005D40();
    void fn_800067FC();
    void fn_80007184(Unk800074BC_Msg* msg);
    void fn_800071F4(Unk800074BC_Msg* msg);
    void fn_8000733C(Unk800074BC_Msg* msg);
    void fn_800074BC(Unk800074BC_Msg* msg);

    char mD8[0x38];
    Unk800058BC_Param m110;
    Unk800058BC_Pair m140;
    Unk800058BC_Fn m144;
    int m14C;
    int m150;
    int m154;
    Unk800058BC_A m158;
    Unk800058BC_B m188;
    char m190[0x1B];
    char m1AB[0x51];
    void* m1FC;
    int m200;
    Unk800058BC_Item m204[5];
    int m240;
    int m244;
    int m248;
    int m24C;
    int m250;
};

#endif
