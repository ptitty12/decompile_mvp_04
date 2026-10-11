/*
 * Shared types for the front-end overlay units fe/tu_8048E6A0 .. fe/tu_804ABCBC
 * (0x8048E6A0..0x804ABCBC; reconstructed, placeholder names, nothing here comes
 * from original headers). Builds on the widget-world header fe_80459228.h: screens
 * are Unk800C7B40_Widget-derived (vptr at +0x3C), methods are written as extern "C"
 * functions taking the screen explicitly. Add new screen structs below; evidence
 * (offsets, users) goes in a comment above each one.
 */
#ifndef GAME_FE_8048E6A0_H
#define GAME_FE_8048E6A0_H

#include "game/fe_80459228.h"


/* The widget stored at byte offset `off` of a screen. */
static inline FeW* FeMem(void* x, int off)
{
    return *(FeW**)((char*)x + off);
}

/* Callees and helpers shared by the units in this range (types refined as functions match). */
struct FeStateX {
    char pad0[0x650];
    int m650;
};
void fn_8001C168();
extern "C" {
void fn_804930F8(void* x);
void fn_80492FB4(void* x);
void fn_804920B8(void* x, int a);
void fn_8049A4DC(void* x);
void fn_804A7874(void* x, int a);
void fn_804A7FBC(void* x, int a);
int fn_804A8004(void* x, int a);
void fn_804A8750(void* x);
void fn_804A89D0(void* x);
void fn_804A8118(void* x);
void fn_804A83D0(void* x);
void fn_804A8B9C(void* x);
void fn_804A8C1C(void* x);
}

#endif
