/*
 * Game code, .text 0x802028E4-0x80206B08 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801EE438.h"
#include "game/tu_802028E4.h"

typedef Unk802028E4_Obj Obj;

extern "C" {
void fn_80205A5C(Obj* o);
}

extern "C" void fn_80204AAC(Unk802028E4_Pair* o)
{
    o->m0 = -1;
    o->m4 = -1;
    o->m8 = 0;
    o->mC = 0;
}

extern "C" int fn_80204E58(Unk801EE438_Ent* e)
{
    if (e->mA8 == 1)
        return 1;
    switch (e->m0) {
    case 2:
    case 4:
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 16:
    case 18:
    case 24:
    case 25:
    case 26:
    case 28:
    case 32:
    case 35:
    case 36:
        return 1;
    }
    return 0;
}

extern "C" int fn_80204F04(Unk801EE438_Ent* e)
{
    switch (e->m0) {
    case 9:
    case 10:
    case 11:
    case 0x31:
        return 1;
    }
    return 0;
}

extern "C" int fn_80204F30(Unk801EE438_Ent* e)
{
    switch (e->m0) {
    case 9:
    case 10:
    case 11:
    case 0x1C:
    case 0x1D:
    case 0x2A:
    case 0x2C:
    case 0x2D:
    case 0x31:
        return 1;
    }
    return 0;
}

extern "C" int fn_80204F8C(Unk801EE438_Ent* e)
{
    switch (e->m0) {
    case 0:
    case 1:
    case 0x17:
    case 0x25:
    case 0x26:
    case 0x29:
        return 1;
    }
    return 0;
}

extern "C" void fn_802053AC(Unk801EE438_G* g)
{
    fn_80201738(g);
    g->mCA4 = 0;
    g->m3A68 = 0;
    g->m3A6C = 0;
    g->m3A5C = -1;
    g->m3A60 = 0;
    fn_802121D0(&g->m30);
    fn_80204AC8(&g->m6A8);
    Unk801EE438_Slot* s = g->mCA8;
    for (int i = 0; i < 9; i++, s++) {
        int n = s->m0;
        for (int j = 0; j < n; j++) {
        }
        s->m0 = 0;
    }
}

extern "C" void fn_80205434(Unk801EE438_G* g, int v)
{
    g->m3A64 = v;
}

extern "C" int fn_8020543C(Obj* o)
{
    return o->m0->m6F8->m14->m1CC9;
}

extern "C" void fn_80205450(Unk801EE438_G* g, int i)
{
    Unk801EE438_Slot* a = g->mCA8;
    g->m3A5C = i;
    g->m3A60 = &a[i];
}

extern "C" int fn_802055F4(Obj* o)
{
    Unk802028E4_Y* y = o->m0->m6F8;
    Unk802028E4_Z* z = y->m10;
    if (z->mC == 3)
        return 0;
    int f = y->m14->m1CD0 == 0;
    int r = 0;
    if (z->m6C[f] != -1)
        r = 1;
    return r;
}

extern "C" int fn_80205644(Obj* o)
{
    return o->m0->m6F8->m10->mC == 1;
}

extern "C" int fn_80205664(Obj* o)
{
    return o->m0->m6F8->m10->mC == 2;
}

extern "C" void fn_80205684()
{
}

extern "C" void fn_80205A3C(Obj* o)
{
    fn_80205A5C(o);
}
