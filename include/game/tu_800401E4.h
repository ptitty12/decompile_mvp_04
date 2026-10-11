/*
 * Declarations for game/tu_800401E4.cpp (reconstructed, placeholder names).
 * The unit is the audio (AEMS) manager: a 0x618-byte singleton owning
 * eighteen 0x3C-byte stream/bank slots.
 */
#ifndef GAME_TU_800401E4_H
#define GAME_TU_800401E4_H

void* operator new(unsigned int size, int heap); /* 0x80377428 */

/* 0x3C-byte slot (ctor 0x800401E4, vtable 0x80649BF8 at +0x38, whose only
 * virtual is the dtor 0x80040234). m8 == 1 means "loaded"; fn_8004028C loads,
 * fn_800403EC unloads. Evidence: those two, fn_800404E0, fn_80040598 and the
 * manager's per-slot loops (fn_80040C58, fn_80040E9C). */
class Unk800401E4 {
public:
    Unk800401E4();
    virtual ~Unk800401E4();
    int fn_8004028C(const char* name, int type, const char* name2, int flag);
    void fn_800403EC();
    int fn_800404E0(int* p, const char* name);
    int fn_80040598(int* p, const char* name, const char* name2, int flag);

    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14[8];
    int m34;
};

/* 0x204-byte table allocated by the manager ctor (64 eight-byte entries from
 * +4, a word at +0x200). */
struct Unk80040640_Tbl {
    int m0;
    int m4[2 * 64 - 1];
    int m200;
};

/* 0x7C-byte table entry at 0x805AEAB8; fn_80040BE8 reads the word at
 * +0x30 + a * 4 of every entry. */
struct Unk805AEAB8_Ent {
    char pad0[0x30];
    int m30[8];
    int m50;
    int m54;
    char pad58[0x78 - 0x58];
    int m78;
};

/* 0x18-byte table entry at 0x805AF688 (fn_800412AC, fn_80041350, fn_80041478). */
struct Unk805AF688_Ent {
    char pad0[8];
    int m8;
    int mC;
    int m10;
    int m14;
};

/* Entry of the 8-byte table at 0x805AF370: callback invoked by fn_800414FC. */
struct Unk805AF370_Ent {
    int (*m0)(int);
    int m4;
};

/* Playback request block at +0x600 of the manager (fn_80041478 fills it). */
struct Unk80040640_Req {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    unsigned char pad6[2];
    unsigned short m8;
    unsigned short mA;
    char padC[0x18 - 0xC];
};


/* The singleton (ctor 0x80040640, size 0x618) returned by fn_8004072C. */
class Unk80040640 {
public:
    Unk80040640();
    ~Unk80040640();

    Unk800401E4 m0[18];
    int m438[0x63];
    int m5C4;
    int m5C8;
    int m5CC;
    int m5D0;
    int m5D4[8];
    int m5F4;
    int m5F8;
    int m5FC;
    Unk80040640_Req m600;
};

#endif
