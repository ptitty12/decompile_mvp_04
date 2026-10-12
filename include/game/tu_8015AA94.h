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

struct Unk8015F164_Evt {
    char pad0[4];
    float m4;
    int m8;
    int mC;
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

/* Sub-object at +0x5F4 of the script runner (ctor 0x80359ACC). */
struct Unk80359ACC {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};

/* Script runner: context pointer at +0xC. fn_80159F28 and fn_80157514 are in
 * tu_80156714.cpp, fn_8015AE08 in tu_8015AA94.cpp. */
class Unk80159F28 {
public:
    void fn_8015AA94();
    void fn_80159F28(int a, int b);
    void fn_80157514(int a, int b, int c, int d, int e, Unk8015AB2C_Blk blk);
    int fn_8015F164(Unk8015F164_Evt* e);
    Unk80326F44_Out fn_8015F1F4(Unk8015F164_Evt* e);
    int fn_8015F744(Unk8015F744_Evt* e);
    int fn_8015F7D0(Unk8015F744_Evt* e);
    int fn_8015F840();
    void fn_8015F87C();
    void fn_8015F918(int a);
    void fn_8015FB08(int a, int b, Unk8015FB08_Rec rec);
    void fn_8015FB84(int a, int b, Unk8015FB08_Rec rec);
    void fn_80167DCC(int p, struct Unk8015FB08_Rec rec);
    void fn_8016818C(int p, struct Unk8015FB08_Rec rec);
    int fn_80160DEC();
    int fn_80160E28();
    int fn_80160E64();
    int fn_80160F14();
    void fn_80161A34();
    int* fn_80161A5C(int a, int b);
    void fn_801653B0(int id, float t);
    void fn_80165328(struct Unk80165328_Evt* e, float t);
    void fn_801654F0(struct Unk801654F0_Evt* e, float t);
    void fn_80165578(struct Unk80165578_Evt* e, float t);
    void fn_80165738(struct Unk801654F0_Evt* e, float t);
    void fn_80165790(struct Unk80165790_Evt* e, float t);
    void fn_801657EC(struct Unk801657EC_Evt* e, float t);
    void fn_80165834(struct Unk80165834_Evt* e, float t);
    void fn_80165884(struct Unk80165884_Evt* e, float t);
    void fn_80165908(struct Unk80165834_Evt* e, float t);
    void fn_80165AF4(struct Unk80165AF4_Evt* e, float t);
    void fn_80165B68(struct Unk80165B68_Evt* e, float t);
    void fn_80165BE0(struct Unk80165BE0_Evt* e, float t);
    void fn_80163A98();
    void fn_80163AF4(int id);
    void fn_80161A74();
    void fn_80157410();
    void fn_801593D8();
    void fn_8015A1D4();
    void fn_8016CFC4(struct Unk8016C788_Obj* o);
    void fn_80169674();
    void fn_80163AF0();
    void fn_80163AF4();
    void fn_80163C50();
    void fn_80163CC4();
    void fn_80163CC4(int id, struct Unk80163CC4_Evt* e);
    void fn_80164624(struct Unk80164624_Evt* e);
    void fn_801655F0(struct Unk801655F0_Evt* e);
    void fn_80165978(struct Unk80165978_Evt* e, float t);
    void fn_80163748();
    void fn_80164CEC();
    void fn_80164DDC();
    void fn_8016482C();
    void fn_80164878();
    void fn_80164F48(struct Unk801654F0_Evt* e, float t);
    void fn_80165010(struct Unk801654F0_Evt* e);
    int fn_80165CC8();
    void fn_80165DA8(int p, Unk8015FB08_Rec rec);
    void fn_80165F94(int p, Unk8015FB08_Rec rec);
    void fn_80169458(int p, Unk8015FB08_Rec rec);
    void fn_801660A4(int p, Unk8015FB08_Rec rec);
    void fn_801661D8(int p, Unk8015FB08_Rec rec);
    void fn_8016630C(int p, Unk8015FB08_Rec rec);
    int fn_80162534();
    int fn_80162598();
    int fn_801625FC();
    int fn_80162664();
    int fn_80162850();
    int fn_80162A3C();

    char pad0[0xC];
    Unk801527C8_Actor* mC;
    int m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C, m40, m44, m48, m4C;
    char pad50[0x30C - 0x50];
    int m30C[7];
    int m328;
    int m32C;
    float m330;
    float m334;
    float m338;
    char pad33C[0x5F4 - 0x33C];
    Unk80359ACC m5F4;
};

#endif
