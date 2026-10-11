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
    char pad0[0x700];
    Unk8023DB8C_Outer* m700;
};

struct Unk8023DB8C_P {
    char pad0[0x244];
    char m244[4];
    char pad248[0x39C - 0x248];
    unsigned m39C;
    char pad3A0[0x44C - 0x3A0];
    Unk8023DB8C_Ctx* m44C;
    char pad450[0x58C - 0x450];
    char m58C[4];
    char pad590[0x628 - 0x590];
    Unk8023DB8C_Slot* m628[31];
    int m6A4[6];
    int m6BC;
    int m6C0;
    char pad6C4[0xB54 - 0x6C4];
    int mB54;
    int mB58;
    int mB5C;
    int mB60;
};

#endif
