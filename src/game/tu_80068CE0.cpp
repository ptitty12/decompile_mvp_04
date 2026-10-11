/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80068CE0-0x8006902C only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80067A20.h"

extern Unk803BA7C4_Obj lbl_806874FC;
extern Unk803BA7C4_Obj lbl_80687504;
extern Unk803BA7C4_Obj lbl_8068750C;
extern Unk803BA7C4_Obj lbl_80687514;
extern Unk803BA7C4_Obj lbl_8068751C;
extern Unk803BA7C4_Obj lbl_80687524;
extern Unk803BA7C4_Obj lbl_80687534;
extern Unk803BA7C4_Obj lbl_8068753C;
extern Unk803BA7C4_Obj lbl_80687544;
extern Unk803BA7C4_Obj lbl_8068754C;

void fn_80068CE0(int a)
{
    if (a < 0)
        a = 0;
    else if (a > 0x7fff)
        a = 0x7fff;
    fn_803BA7C4(&lbl_806874FC, &a);
}

void fn_80068D30(int a)
{
    if (a < 0)
        a = 0;
    else if (a > 0x7fff)
        a = 0x7fff;
    fn_803BA7C4(&lbl_80687504, &a);
}

void fn_80068D80(int a)
{
    if (a < 0)
        a = 0;
    else if (a > 0x7fff)
        a = 0x7fff;
    fn_803BA7C4(&lbl_8068750C, &a);
}

void fn_80068DD0(int a)
{
    if (a < 0)
        a = 0;
    else if (a > 0x7fff)
        a = 0x7fff;
    fn_803BA7C4(&lbl_80687514, &a);
}

void fn_80068E20(int a)
{
    if (a < 0)
        a = 0;
    else if (a > 0x7fff)
        a = 0x7fff;
    fn_803BA7C4(&lbl_8068751C, &a);
}

void fn_80068E70(int a)
{
    if (a < 0)
        a = 0;
    else if (a > 0x7fff)
        a = 0x7fff;
    fn_803BA7C4(&lbl_80687524, &a);
}

void fn_80068EC0(int a)
{
    if (a < 0)
        a = 0;
    else if (a > 0x7fff)
        a = 0x7fff;
    fn_803BA7C4(&lbl_80687534, &a);
}

void fn_80068F10(int a)
{
    if (a < 0)
        a = 0;
    else if (a > 0x7fff)
        a = 0x7fff;
    fn_803BA7C4(&lbl_8068753C, &a);
}

void fn_80068F60(int a)
{
    if (a < 0)
        a = 0;
    else if (a > 0x7fff)
        a = 0x7fff;
    fn_803BA7C4(&lbl_80687544, &a);
}

void fn_80068FB0(int a)
{
    if (a < 0)
        a = 0;
    else if (a > 0x7fff)
        a = 0x7fff;
    fn_803BA7C4(&lbl_8068754C, &a);
}

/* The TU's `_GLOBAL_.I.<first global>` wrapper: calls the static initializer
 * (fn_80065968) with (1, 0xFFFF). g++ emits it itself next to the initializer
 * in a real TU; this split puts the initializer in another unit
 * (tu_80064D48), so here it is an ordinary function with the same body. */
void fn_80069000(void)
{
    fn_80065968(1, 0xffff);
}
