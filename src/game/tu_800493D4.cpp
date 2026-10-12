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

extern "C" void fn_80049C0C();

extern "C" void fn_80049BEC()
{
    fn_80049C0C();
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

void fn_8004ADE4(Unk800493D4_Sm* s, int idx, Unk8004ADE4_Arg* a)
{
    int found = 0;
    int i;
    for (i = 0; i < a->m100; i++) {
        float v = fn_804028E4(a->m70[i].m0->m8E8) / ((float)lbl_8061B9C8 * 0.016666668f);
        if (!(v <= 0.0f)) {
            found = 1;
            break;
        }
    }
    if (found != 0)
        fn_80012988();
}

void fn_8004AEB4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    char* b = (char*)s + 0x3C;
    int o = idx * 0x48;
    if (fn_80258C90((*(Unk80044C10_B**)(b + o))->m700->m3B4) != 0)
        fn_8000F808();
}

void fn_8004AEF4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    char* b = (char*)s + 0x3C;
    int o = idx * 0x48;
    if (fn_80258C90((*(Unk80044C10_B**)(b + o))->m700->m3B4) != 0) {
        Unk800493D4_Ent* e = (Unk800493D4_Ent*)((char*)s + o);
        if (e->m8 != 0) {
            fn_80017130();
            return;
        }
        int x = fn_8001F3FC(a, e->m4);
        int y = fn_8001D8DC(a);
        fn_800119F8(x, y, fn_8001F45C(a, e->m4));
    }
}

void fn_8004AF90()
{
}

void fn_8004AF94(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int ok = 0;
    if (a->m104 == 3 && a->m1 == 1 && a->m0 >= EntObj(s, idx)->m6F8->m10->m1C
        && fn_80043884((Unk80043884_Obj*)a) != 0)
        ok = 1;
    if (ok == 1) {
        fn_80050324(s, idx, a, 1, 1);
        return;
    }
    int t = ((Unk8001CE80*)a)->fn_8001D5D8();
    int r;
    if (t == 2)
        r = fn_8001F904(a);
    else
        r = fn_8001F8B8(a);
    fn_80010548(t, r);
}

void fn_8004B314(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (fn_8004FF78(s, s->m9D8, 0x2D) == -1 && fn_8004FF78(s, s->m9D8, 0x49) == -1) {
        if ((a->m454 == 2 || a->m454 == 0) && a->m3FC != 0) {
            fn_80015BDC();
            return;
        }
        if ((a->m454 == 2 && a->m430 < 15.0f) || (a->m454 == 0 && !(a->m428 >= 15.0f))) {
            fn_80011160(((Unk8001CE80*)a)->fn_8001D6CC());
        }
    }
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
