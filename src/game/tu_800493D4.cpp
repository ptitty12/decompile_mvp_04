/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x800493D4-0x8004B6BC only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800493D4.h"

void fn_8004961C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m50 == 0) {
        fn_80058FE4(s->mA9C, 8, a);
        fn_80058FE4(s->mA9C, 0x3F, a);
    }
}

void fn_80049778(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m4D4 == 3 || a->m50 == 0) {
        fn_80058FE4(s->mA9C, 7, a);
        fn_8004FCDC(s, idx, a);
    }
    fn_8004B910(s, idx, a);
}

void fn_800497F0(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m50 == 0 && a->m3CC <= 3) {
        fn_80058FE4(s->mA9C, 0x2D);
        fn_80058FE4(s->mA9C, 0x3F, a);
    }
}

void fn_8004A864(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m3DC == 0) {
        fn_80011890();
        s->mA68 = 1;
    }
}

void fn_8004A8A4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m3DC == 0) {
        int p = fn_8001F4F0(a);
        fn_8000F670(p, fn_8001E054(a));
    }
}

void fn_8004A8F8(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    s->mA34 = 0;
    fn_80058FE4(s->mA9C, 0x39, a);
    s->mA90 = 1;
    char* b = (char*)s + 0x3C;
    int o = idx * 0x48;
    fn_80046078(*(Unk80044C10_B**)(b + o));
}

void fn_8004AA40()
{
}

void fn_8004ADE0()
{
}

void fn_8004AF90()
{
}

void fn_8004B534()
{
}

void fn_8004B538(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    s->m9DC = idx;
    char* base = (char*)s + 0x3C;
    int off = idx * 0x48;
    fn_801A6D84(*(Unk80044C10_A**)(base + off), 1);
    if (fn_8016B9F4() == 0) {
        if (fn_8006BE18((*(Unk80044C10_B**)(base + off))->m6F8) == 0)
            fn_8004B5C0(s, idx, a);
        fn_80057B54(fn_800475EC()->mFC.mA9C, 0);
    }
}
