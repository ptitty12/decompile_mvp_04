/*
 * Game code, .text 0x801F263C-0x801F6680 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801EE438.h"

typedef Unk801EE438_Scr Scr;

extern "C" {

void fn_801F263C(Scr* p, void* v)
{
    int tmp;
    fn_801F2668(p, &tmp, v, -1);
}

Unk801EE438_Player* fn_801F29AC(Scr* p, Unk801EE438_Game* g, Unk801EE438_Player* x)
{
    Unk801EE438_Player* r = fn_801EDE4C(p, g);
    return r != 0 ? (r == x ? p->m9C->m8[0] : r)
                  : (g->m38C == 3 ? (g->m374 == x ? g->m378 : g->m374)
                                  : (p->m9C->mA4 != -1 ? p->m9C->m8[p->m9C->mA4] : p->m9C->m8[0]));
}

int fn_801F3B54(Scr* p)
{
    Unk801EE438_G* g = p->m9C;
    int r = 0;
    if (g->m54 == 1)
        r = g->m5C == 1;
    return r;
}

void fn_801F418C(Scr* p, int v)
{
    p->m9C->m1C4 = v;
}

void fn_801F4198(Scr* p, int v)
{
    p->m9C->m1C0 = v;
}

int fn_801F5214(float* a, float* b)
{
    return *a > *b;
}

int fn_801F5394()
{
    char buf[0xB8];
    return 0;
}

int fn_801F5DD8(int unused, int a)
{
    if (a == 0x11 || a == 0x13 || a == 0x12 || a == 0x14 || a == 0x16 || a == 0x15)
        return 1;
    return 0;
}

/* near-miss (3 slots): retail keeps the index in r11 (BASE_REGS) where ours uses r0 for slwi/lwzx. */
void fn_801F5FD4(Scr* p, int a)
{
    Unk801EE438_It it;
    fn_8014E09C(&it, p->m9C->m0, 1);
    Unk801EE438_It* ip = &it;
    while (ip->m8 != 10) {
        int i = ip->m8;
        fn_8024FC74(&p->m9C->m8[i]->m4D8, a);
        fn_8014E108(ip);
    }
}

}
