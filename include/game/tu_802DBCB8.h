#ifndef GAME_TU_802DBCB8_H
#define GAME_TU_802DBCB8_H

/*
 * Declarations for game/tu_802DBCB8.cpp and tu_802DE2C8.cpp (reconstructed,
 * placeholder names). The units are methods of the pad base class
 * Unk803414A4 (include/game/tu_80008540.h, vtable lbl_806648E8) and of its
 * 0x24-byte sub-object at +0x1558 (Unk802DC9F8).
 */
#include "game/tu_80008540.h"

extern "C" void* fn_803FFC58(void* dst, int val, unsigned int n);   /* memset */
void fn_80377408(void* p);                                          /* __builtin_delete */
void* operator new[](unsigned int size, int heap);                  /* 0x803774A8 */
extern int lbl_806EFA04;

extern "C" int fn_802DC9C0();
void fn_803FEC4C(int h, int pos, char* buf, int n, int mode);
int fn_80409DAC(const char* s);
int fn_802DCCCC(int h, int* pos, int* out);

#endif
