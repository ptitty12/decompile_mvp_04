/*
 * Types for tu_8015AA94.cpp (script system helpers). Reconstructed.
 */
#ifndef GAME_TU_8015AA94_H
#define GAME_TU_8015AA94_H

#include "game/tu_801527C8.h"

/* 0x48-byte record copied by value (24+24+24 word-copy loops). */
struct Unk8015AB2C_Blk {
    int w[18];
};

/* 0x4C-byte record (word at entry+4 followed by the 0x48-byte record): returned by
 * fn_8015ABB8 (24+24+24 loops plus a trailing word). */
struct Unk8015ABB8_Rec {
    int w[19];
};

/* Entry of the queue: time at +0, a word at +4, then the record at +8. Evidence:
 * fn_8015AB2C (stores the time, the word and copies the record to +8), fn_8015ABB8
 * (reads the time, copies 0x48 bytes starting at +4). */
struct Unk8015AB2C_Entry {
    int m0;
    int m4;
    Unk8015AB2C_Blk m8;
};

/* Event queue: count at +0, ten entries from +4, owner at +0x324. */
class Unk8015AB2C {
public:
    void fn_8015AB2C(int a, int b, Unk8015AB2C_Blk blk);
    Unk8015ABB8_Rec fn_8015ABB8(int t);

    int m0;
    Unk8015AB2C_Entry m4[10];
    Unk801527C8_Actor* m324;
};

/* Event record read by the event-to-code mappers fn_8015F744/fn_8015F7D0. */
struct Unk8015F744_Evt {
    int m0;
    char pad4[8];
    int mC;
};

/* Record whose first word is passed on and whose remaining 0x48 bytes are copied
 * (fn_8015FB08). */
struct Unk8015FB08_Rec {
    int m0;
    Unk8015AB2C_Blk m4;
};

struct Unk801A6D84_Obj {
    char pad0[0x3D90];
    int m3D90;
};
Unk801A6D84_Obj* fn_801A6D84(Unk801527C8_Actor* a, int i);
Unk80189300* fn_801A4B34(Unk801527C8_Actor* a);

/* Script runner: context pointer at +0xC. fn_80159F28 and fn_80157514 are in
 * tu_80156714.cpp, fn_8015AE08 in tu_8015AA94.cpp. */
class Unk80159F28 {
public:
    void fn_8015AA94();
    void fn_80159F28(int a, int b);
    void fn_80157514(int a, int b, int c, int d, int e, Unk8015AB2C_Blk blk);
    int fn_8015F744(Unk8015F744_Evt* e);
    int fn_8015F7D0(Unk8015F744_Evt* e);
    void fn_8015F840();
    void fn_8015F87C();
    void fn_8015F918(int a);
    void fn_8015FB08(int a, int b, Unk8015FB08_Rec rec);
    void fn_8015FB84(int a, int b, Unk8015FB08_Rec rec);
    int fn_80160DEC();
    int fn_80160E28();
    int fn_80160E64();
    int fn_80160F14();
    void fn_80161A34();
    int* fn_80161A5C(int a, int b);
    int fn_80162534();
    int fn_80162598();
    int fn_801625FC();
    int fn_80162664();
    int fn_80162850();
    int fn_80162A3C();

    char pad0[0xC];
    Unk801527C8_Actor* mC;
    char pad10[0x30C - 0x10];
    int m30C[7];
    char pad328[0];
    int m328;
};

#endif
