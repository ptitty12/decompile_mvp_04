/*
 * Script-queue record builder shared by tu_8015F164.cpp and tu_80156714.cpp.
 * RecObj is the local 0x500-byte Unk8016D9A0_Rec: eight 0xA0-byte elements whose inline
 * constructors copy lbl_805EBA10 into three Unk80326F44_Out slots (three by-value temporaries
 * live together, as in retail), then call fn_80359624 (sub-object at +0x44) and fn_803596DC; the
 * object constructor ends with fn_803597C4. Evidence: fn_80162664 and the units' other record users.
 */
#ifndef GAME_TU_8015F164_H
#define GAME_TU_8015F164_H

#include "game/tu_8015AA94.h"
#include "game/tu_80167DCC.h"

extern const Unk80326F44_Out lbl_805EBA10;
struct Unk80359624 { int a; int b; int c; };
struct Unk8019F8C0_Owner;
extern const Unk8015AB2C_Blk lbl_8068B828;
void fn_80359624(Unk80359624* s);
extern "C" void fn_803596DC(void* p);
struct ElemRec8015F164 {
    char name[0x44];
    Unk80359624 x44;
    Unk80326F44_Out r50;
    Unk80326F44_Out r68;
    Unk80326F44_Out r80;
    int m98;
    int m9C;
    ElemRec8015F164();
};
inline Unk80326F44_Out DefRec8015F164() { return lbl_805EBA10; }
inline void SetRecs8015F164(ElemRec8015F164* e, Unk80326F44_Out a, Unk80326F44_Out b, Unk80326F44_Out c)
{
    e->r50 = a;
    e->r68 = b;
    e->r80 = c;
}
inline ElemRec8015F164::ElemRec8015F164()
{
    SetRecs8015F164(this, DefRec8015F164(), DefRec8015F164(), DefRec8015F164());
    fn_80359624(&x44);
    fn_803596DC(this);
}
struct Unk803597C4;
void fn_803597C4(Unk803597C4* s);
struct RecObj8015F164 {
    ElemRec8015F164 e[8];
    RecObj8015F164() { fn_803597C4((Unk803597C4*)this); }
};
Unk8016ACAC* fn_801A6D84(Unk8019F8C0_Owner* o, int i);
/* Same 0xA0 element seen as plain fields (the explicit re-initialisation loops). */
struct ElemView8015F164 {
    char name[0x3C];
    int m3C, m40, m44, m48, m4C;
    Unk80326F44_Out m50;
    Unk80326F44_Out m68;
    Unk80326F44_Out m80;
    int m98;
    int m9C;
};
extern "C" void fn_80169BF8(Unk8016D9A0_Rec* rec, const char* name, int a, int b, int c, int d, Unk8015AB2C_Blk blk, int e);

#endif
