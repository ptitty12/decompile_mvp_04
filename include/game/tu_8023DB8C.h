#ifndef GAME_TU_8023DB8C_H
#define GAME_TU_8023DB8C_H

/*
 * Unk8023DB8C_P: a manager object whose fields these units read by offset only.
 * Evidence (offsets from the asm): +0x244 an embedded object passed to fn_80319330
 * with ids 0x18..0x1A (fn_8023F0FC/F144/F18C cache the result at +0xB58/+0xB5C/+0xB60),
 * +0x39C a packed word (fn_8023F1D4 compares its top 10 bits with 900), +0x58C an
 * embedded object (fn_8023DB8C), +0x628 an array of Slot pointers, +0x6A4 an int flag
 * array, +0x6BC/+0x6C0 ints, +0xB54 an int. Rows of 32 bytes start at +0xB0 (the flag word
 * read by fn_8023EBF4 is at +0xD0 of row 0 + i*32, bit 27).
 */
struct Unk8023DB8C_Flags {
    unsigned pad : 4;
    unsigned m4 : 1;
    unsigned rest : 27;
};

struct Unk8023DB8C_Slot {
    char pad0[0x448];
    int m448[3];
    int m454;
    int m458;
    int m45C;
    int m460;
    char pad464[0x46C - 0x464];
    int m46C;
};

struct Unk8023DB8C_Outer {
    char pad0[0x3AC];
    int m3AC;
};
struct Unk8023DB8C_Ctx {
    char pad0[0x6F4];
    int m6F4;
    struct Unk8023DDD0_S* m6F8;
    char pad6FC[4];
    Unk8023DB8C_Outer* m700;
};
struct Unk8023DDD0_E {
    char pad0[0x1CD0];
    int m1CD0;
};
struct Unk8023DDD0_S {
    char pad0[0x14];
    Unk8023DDD0_E* m14;
};
/* Sub-object at P+0xA0 (vptr at +0xB8): only virtual 5 is called (fn_8023DE48 family). */
class Unk8023DE48_Q {
public:
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct Unk8023DB8C_P {
    char pad0[0x244];
    char m244[4];
    char pad248[0x264 - 0x248];
    int m264;
    char pad268[0x39C - 0x268];
    unsigned m39C;
    char pad3A0[0x44C - 0x3A0];
    Unk8023DB8C_Ctx* m44C;
    char pad450[8];
    int m458;
    char pad45C[0x58C - 0x45C];
    char m58C[4];
    char pad590[0x628 - 0x590];
    Unk8023DB8C_Slot* m628[31];
    int m6A4[6];
    int m6BC;
    int m6C0;
    int m6C4[6];
    char pad6DC[0x708 - 0x6DC];
    int m708;
    char pad70C[0x9FC - 0x70C];
    int m9FC;
    int mA00;
    char padA04[4];
    int mA08;
    char padA0C[0xB54 - 0xA0C];
    int mB54;
    int mB58;
    int mB5C;
    int mB60;
};

#endif
