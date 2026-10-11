/*
 * Types for game/tu_802D3E44.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_802D3E44_H
#define GAME_TU_802D3E44_H

/* Camera objects have their vptr at +0 (vtable 0x806646F0 for the data-less mid class); the destructors fn_802D71B8 /
 * fn_802D722C / fn_802D7338 store it and chain to the root destructor fn_8037B424 with the in-charge argument. */
struct Unk802D71B8 {
    const void* vptr;
};

/* Camera object accessors: +0x20 / +0x54 hold data words returned by the getters. */
struct Unk802D7224 {
    char pad0[0x20];
    int m20;
    char pad24[0x30];
    int m54;
};

/* Camera whose +0x78 sub-camera is forwarded to fn_802CBD04 (fn_802D62D8). */
struct Unk802D62D8 {
    char pad0[0x78];
    void* m78;
};

/* Camera state flags read by fn_802D5C64: +0x14, +0x28, +0x7C. */
struct Unk802D5C64 {
    char pad0[0x14];
    int m14;
    char pad18[0x10];
    int m28;
    char pad2C[0x50];
    int m7C;
};

/* Camera controller: +0x18 flag, +0x60 owner, +0x64 view record, +0x78 sub-camera (Unk802CBD04), +0x7C / +0x80 modes,
 * +0x98..+0xC3 attached name (fn_802D5BF4). Evidence: fn_802D58E8, fn_802D5970, fn_802D5B64, fn_802D5BF4. */
struct Unk802D5B64_View {
    int m0;
    int m4;
};
struct Unk802D58E8_Owner {
    char pad0[0x6F4];
    int m6F4;
    char pad6F8[8];
    void* m700;
};
struct Unk802D58E8_Pad {
    char pad0[0x6C];
    int m6C;
};
struct Unk802D58E8_Flags {
    char pad0[0x2C];
    int m2C;
};
struct Unk802D58E8 {
    char pad0[0x18];
    int m18;
    char pad1C[0x44];
    Unk802D58E8_Owner* m60;
    Unk802D5B64_View* m64;
    char pad68[0x10];
    struct Unk802CBD04* m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    float m8C;
    int m90;
    char pad94[4];
    int m98;
    unsigned int m9C;
    int mA0;
    char mA4[0x1F];
    char mC3;
    char padC4[0x160 - 0xC4];
    int m160;
};

/* 0x48-byte block copied through a local by fn_802D5618 (from the view record's +0x40 object at +0x3D48 into +0x184 of the +0x70 object). */
struct Unk802D5618_Blob {
    int w[18];
};
struct Unk802D5618_A {
    char pad0[0x40];
    char* m40;
};
struct Unk802D5618 {
    char pad0[0x64];
    Unk802D5618_A* m64;
    char pad68[8];
    char* m70;
};

#endif
