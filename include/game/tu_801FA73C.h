/*
 * Types shared by game/tu_801FA73C.cpp and game/tu_801FE850.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * The 70 or so 0x16C-0x1B8 byte functions in these two units are menu "screen
 * setup" routines. Each takes one object (the screen) and issues a straight
 * sequence of calls: a menu object embedded at +0xA0 (init, per-item setup
 * fn_801F803C(menu, idx), finish), and per-slot calls that pair an item
 * selector fn_80205450(screen->m9C, slot) with a screen method taking small
 * constants. Evidence: every one of these functions loads only 0x9C(screen)
 * and takes the address 0xA0(screen); no other field offset is used.
 */
#ifndef GAME_TU_801FA73C_H
#define GAME_TU_801FA73C_H

struct Unk801FA73C_List;                 /* object at screen+0x9C */
struct Unk801FA73C_Menu { int m0; };     /* embedded at screen+0xA0 (size unknown) */
struct Unk801FA73C_Scr {
    char pad0[0x9C];
    Unk801FA73C_List* m9C;
    Unk801FA73C_Menu mA0;
};

extern "C" {
/* menu object methods (unit 0x801F6680) */
void fn_801F7F64(Unk801FA73C_Menu* m);
void fn_801F7FC4(Unk801FA73C_Menu* m, int a);
void fn_801F803C(Unk801FA73C_Menu* m, int a);
void fn_801F83F0(Unk801FA73C_Menu* m, int a);
void fn_801F8530(Unk801FA73C_Menu* m, int a);
void fn_801F86B0(Unk801FA73C_Menu* m, int a);
void fn_801F8D34(Unk801FA73C_Menu* m);
void fn_801F8E40(Unk801FA73C_Menu* m);
/* item selector (unit 0x802028E4) */
void fn_80205450(Unk801FA73C_List* l, int a);
/* screen methods (units 0x80212AC0..0x8021F080) */
void fn_802124B8(Unk801FA73C_Scr* s);
void fn_8021354C(Unk801FA73C_Scr* s, int a, int b);
void fn_802138AC(Unk801FA73C_Scr* s, int a, int b, float f);
void fn_80213B80(Unk801FA73C_Scr* s, int a, int b, int c);
void fn_80213DF4(Unk801FA73C_Scr* s, int a);
void fn_80213E30(Unk801FA73C_Scr* s, int a);
void fn_80213F10(Unk801FA73C_Scr* s, int a);
void fn_80213FAC(Unk801FA73C_Scr* s, int a);
void fn_80214040(Unk801FA73C_Scr* s);
void fn_8021458C(Unk801FA73C_Scr* s, int a, int b);
void fn_80214620(Unk801FA73C_Scr* s, int a);
void fn_80214B10(Unk801FA73C_Scr* s, int a, int b);
void fn_80214BE8(Unk801FA73C_Scr* s, int a, int b);
void fn_80214C68(Unk801FA73C_Scr* s, int a, int b);
void fn_80214CE8(Unk801FA73C_Scr* s, int a, int b, int c, int d, float f);
void fn_80214F1C(Unk801FA73C_Scr* s, int a, int b, float f);
void fn_80219328(Unk801FA73C_Scr* s);
void fn_802195D4(Unk801FA73C_Scr* s, int a);
void fn_802197A0(Unk801FA73C_Scr* s, int a);
int fn_80219B8C(Unk801FA73C_Scr* s, int a);
void fn_8021A4A0(Unk801FA73C_Scr* s, int a);
void fn_8021B6EC(Unk801FA73C_Scr* s, int a, int b);
void fn_8021D4A4(Unk801FA73C_Scr* s);
}

#endif
