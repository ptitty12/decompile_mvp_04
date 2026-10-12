/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8004B6BC-0x8004E364 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8004B6BC.h"

void fn_8004B910(Unk800493D4_Sm* s)
{
    int v = s->mA58;
    if (v != 0)
        s->mA58 = v - 1;
}

void fn_8004BDC4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int k = a->m284;
    if (k <= 9 || (k & 3) == 0) {
        if (k > 2) {
            if (k & 1)
                fn_8000F85C(fn_8001F8B8(a));
        } else {
            char* b = (char*)s + 4;
            int o = idx * 0x48;
            int x = fn_80044D3C(*(int*)(b + o));
            fn_8000F794(x, 0, fn_8001F8B8(a), 1);
        }
    }
}

void fn_8004C0E0(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (fn_8005000C(s, idx, 6) == -1) {
        char* b = (char*)s + 4;
        int o = idx * 0x48;
        fn_80013FD4(fn_80044D3C(*(int*)(b + o)));
    }
}

void fn_8004CA98(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    fn_8004EB58(s, idx, a);
    fn_8004FA94(s, idx, a);
    fn_8004D56C(s, idx, a);
}

void fn_8004CAEC(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    fn_8004EB58(s, idx, a);
    fn_8004FA94(s, idx, a);
    fn_8004D56C(s, idx, a);
}

void fn_8004DC18(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    fn_80058FE4(s->mA9C, 2);
    fn_80058FE4(s->mA9C, 0x3C, a);
}

/* near-miss (99.33%): retail saves r29 too (stmw r29, frame 0x18) although nothing uses it; ours saves r30-r31 only (frame 0x10) */
void fn_8004DC60(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (fn_8004FF78(s, s->m9D8, 3) >= 0) {
        fn_80054684((Unk80052794_Ctx*)s, idx, 0);
        fn_80054684((Unk80052794_Ctx*)s, idx, 1);
    }
}

int fn_8004E248(Unk800493D4_Sm* s, int idx)
{
    int r = -1;
    int off = idx * 0x48;
    int k = *(int*)((char*)s + off);
    if (k == 0x14 || k == 0x1B || k == 8 || k == 0x1C || k == 0xE) {
        char* b = (char*)s + 4;
        r = *(int*)(b + off);
    }
    return r;
}
