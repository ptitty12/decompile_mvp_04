#ifndef GAME_TU_802EFF28_H
#define GAME_TU_802EFF28_H

/*
 * Declarations for game/tu_802EFF28.cpp (reconstructed, placeholder names): geomlib
 * collision tests behind argument-swapping wrappers that pass r5 through.
 */

void fn_802EFF54(void* a, void* b, void* c);
void fn_802F1EAC(void* a, void* b, void* c);
void fn_802F335C(void* a, void* b);

#include "game/tu_802E6464.h"

/* Type with vtable lbl_80664C98: a ray shape (type 1, fn_802E7314) embedded at +0x60. */
class Unk802F3A04 : public Unk802E22EC_B {
public:
    Unk802E7314 m60;
    virtual ~Unk802F3A04();
    virtual int s8();
    virtual int s9();
};
void fn_802F398C(int a, int b);

#endif
