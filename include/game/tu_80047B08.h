#ifndef GAME_TU_80047B08_H
#define GAME_TU_80047B08_H

#include "game/tu_80046964.h"

/*
Types for game/tu_80047B08.cpp (see tu_80044C10.h for the shared game object and
the Unk8004763C manager).
*/

void fn_80392708();
void fn_80392DF4();
void fn_803EDA0C(void* p);
void fn_80377488(void* p); /* __builtin_vec_delete */
void fn_803917D0(int a);
void fn_80057778(void* p);
void fn_80057950(void* p);
void* fn_8005BA9C(void* p);
void fn_8005C654(void* a, void* b, int c, int d);
void fn_80048E50(Unk80048A10_Sub* p, int id, float f, int* a, void* b, void* w);
void fn_80049090(Unk80048A10_Sub* p, int a);
void fn_800490D0(Unk80048A10_Sub* p);
void fn_800490F8(Unk80048A10_Sub* p);
void fn_800490FC(Unk80048A10_Sub* p);
extern char lbl_805B09F4[];
extern char lbl_80649AB0[];
void fn_800575E4(void* sink, int c);

/* Object held at Sub + 0xADC: 0x7E0 data bytes, then the vptr; slot 1 is the virtual destructor (fn_80048B2C). */
struct Unk80048B2C_Base {
    char pad0[0x7E0];
};
class Unk80048B2C_Obj : public Unk80048B2C_Base {
public:
    virtual ~Unk80048B2C_Obj();
};
void fn_80048464(Unk8004763C* t, int i);
extern int lbl_80617804;
extern int lbl_80617808;

#endif
