/*
 * Chooser base class (reconstructed; placeholder name, see chooser.h).
 *
 * Kept out of chooser.h on purpose: its inline ctors change g++ 2.95's code
 * for unrelated functions in units that include chooser.h without using them
 * (fn_80287C70 in animation/goals/tu_80287600.cpp went from 100% to 94%), so
 * only the units that derive from it include this header.
 */
#ifndef GAME_CHOOSER_BASE_H
#define GAME_CHOOSER_BASE_H

#include "game/chooser.h"

/* Base of the choosers, between the root and each chooser class. Evidence:
 * - dtor 0x80362C2C: an empty body that passes in_chrg on to the root dtor
 *   0x8037B424 (no vptr store). Every chooser dtor calls it (cRandom,
 *   ICommonPlayerID, cSignatureChooser, cEventChooser, cHandChooser,
 *   cPitchChooser, cRandomLoaded, cMatrixChooser, cCircleChooser,
 *   cLinearChooser, cShortestPathChooser, and cFitnessChooser at 0x80276F4C),
 *   while the event, warp and script-command classes call 0x8037B424;
 * - vtable 0x80684F68 (lbl_80684F48 + 0x20): slot 1 = 0x80362C2C, slots 2..5
 *   and 13 and 17 pure, 6..10 the root's, 11 = 0x80382D70, 12 = 0x8038B860,
 *   14..16 = 0x8038B868, 0x8038B89C, 0x8038B8A4. Nothing stores it;
 * - no out-of-line ctor: the chooser ctors call the root ctor 0x8037B3E8
 *   directly, and g++ drops this inline ctor's vptr store as dead. */
class Unk80362C2C : public Unk8037B3E8 {
public:
    Unk80362C2C(unsigned int hash) : Unk8037B3E8(hash) {}
    Unk80362C2C(const char* name) : Unk8037B3E8(name) {}
    virtual ~Unk80362C2C();               /* 0x80362C2C */
};


#endif /* GAME_CHOOSER_BASE_H */
