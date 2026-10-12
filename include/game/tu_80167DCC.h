/*
 * Types for tu_80167DCC.cpp (script commands and the script manager object).
 * Reconstructed.
 */
#ifndef GAME_TU_80167DCC_H
#define GAME_TU_80167DCC_H

#include "game/tu_8016BF30.h"

/* Script command that preloads up to three sound banks (strings of 10 bytes at
 * +4, +0xE, +0x18). Object size 0x24 (factory fn_80169878). */
class cScriptLoadAnimations : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptLoadAnimations();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    char m4[10];               /* "BankToLoad1" */
    char mE[10];               /* "BankToLoad2" */
    char m18[10];              /* "BankToLoad3" */
    char pad22[2];
};

/* One of the three script slots of the manager (stride 0xA5C); +0xA20 is the
 * hash of the slot's current script. */
struct Unk8016ACAC_Slot {
    void fn_8016B3A8();
    void fn_8016C448();
    void fn_8016D368(float* t);
    void fn_8016A6AC();
    void fn_8016C6DC();
    Unk8016C1C4_List mLists[15];
    char padA14[0xA20 - 0xA14];
    int mA20;
    char padA24[0xA5C - 0xA24];
};

/* Record of the script queue (0x500 bytes): eight 0xA0-byte elements, each a name
 * string with a hash/id word at +0x44. */
struct Unk8016D9A0_Rec {
    char m[0x500];
};

/* Queue object embedded at +4 of the manager: six records, count at +0x1E00, a
 * list of up to six ids at +0x1E04 (count +0x1E1C) and a flag at +0x1E20.
 * Evidence: fn_8016D9A0/fn_8016DBF0/fn_8016E18C/fn_8016E0E8. */
class Unk8016D9A0 {
public:
    void fn_8016D9A0(Unk8016D9A0_Rec* rec);
    void fn_8016DA48(Unk8016D9A0_Rec* rec);
    int fn_8016DBF0();
    void fn_8016DFD0();
    void fn_8016E0E8(const char* rec);
    void fn_8016E18C();

    Unk8016D9A0_Rec m0[6];
    int m1E00;
    int m1E04[6];
    int m1E1C;
    int m1E20;
};

/* Script manager: three slots from +0x1E28, context at +0x3D3C. */
class Unk8016ACAC {
public:
    int fn_8016ACAC();
    int fn_8016AD44();
    int fn_8016AD7C(int idx);
    int fn_8016AE34();
    int fn_8016AE94();
    int fn_8016AEEC();
    int fn_8016AF4C();
    int fn_8016AF9C();
    int fn_8016B174();
    void fn_8016B2B8();
    int fn_8016C39C();
    int fn_8016C344();
    int fn_8016C764(int idx);
    void fn_8016D2A4();
    void fn_8016A7A8(Unk8016D9A0_Rec* rec);
    void fn_8016A814(Unk8016D9A0_Rec* rec);
    int fn_8016B9F4();
    void fn_8016B1D4();
    void fn_8016B2F0();
    void fn_8016B95C();
    void fn_8016B8CC(int x);
    void fn_8016BA48(int x, int a, int b, Unk8015AB2C_Blk blk, int c);
    void fn_8016BB50(const char* name, int a, int b, Unk8015AB2C_Blk blk, int c);
    void fn_8016BCCC();
    void fn_8016C4FC();
    void fn_8016BBF4(Unk8016D9A0_Rec* rec);
    void fn_8016A708();
    void fn_8016BF30(char* elem);
    void fn_8016C4A0();
    void fn_8016A880();
    void fn_8016D128();

    int m0;
    Unk8016D9A0 m4;
    Unk8016ACAC_Slot m1E28[3];
    Unk801527C8_Actor* m3D3C;
    int m3D40;
    int m3D44;
    Unk8015AB2C_Blk m3D48;
    int m3D90;
    char m3D94[8][0xA0];
    Unk801527C8_Actor* m4294;
    int m4298;
    int m429C[5];
};

#endif
