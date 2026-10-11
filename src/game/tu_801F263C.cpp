/*
 * Game code, .text 0x801F263C-0x801F6680 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801EE438.h"

typedef Unk801EE438_Scr Scr;

struct Unk80283934_Goal;
float fn_802855C4(Unk80283934_Goal* g);

struct Unk801F263C_Node {
    Unk801F263C_Node* m0;
    char pad4[0x10 - 4];
    int m10;
    int m14;
    char m18[1];
};

struct Unk801F263C_List {
    char pad0[0x934];
    Unk801F263C_Node* m934;
};

extern const float lbl_805D4EA8;

extern "C" {
int fn_80210D20(Unk801EE438_G** g, int a);
int fn_80210C98(Unk801EE438_G** g, int a);

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

inline int SubVal4EF4(int* base, int i)
{
    if (i == -1)
        return -1;
    int* q = base + i;
    return *q;
}

inline Unk801EE438_Player* PlayerAt4EF4(Unk801EE438_Player** a, int i)
{
    Unk801EE438_Player** q = a + i;
    return *q;
}

int fn_801F4EF4(Scr* p, int a1, int a2)
{
    Unk801EE438_G* g = p->m9C;
    Unk801EE438_Game* t = g->m0->m6CC;
    int v = SubVal4EF4(&g->mC0.m0, a1);
    if (v != -1) {
        if (t->m378 == PlayerAt4EF4(g->m8, a2) && t->m374 == PlayerAt4EF4(g->m8, v))
            return 0;
    }

    if (a1 == 3 && a2 != 1)
        return fn_80210D20(&p->m9C, 3) > 1;
    return fn_80210C98(&p->m9C, 1);
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

inline Unk801EE438_Player* PlayerAt5FD4(Unk801EE438_Player** a, int i)
{
    Unk801EE438_Player** q = a + i;
    return *q;
}

void fn_801F5FD4(Scr* p, int a)
{
    Unk801EE438_It it;
    fn_8014E09C(&it, p->m9C->m0, 1);
    Unk801EE438_It* ip = &it;
    while (ip->m8 != 10) {
        int i = ip->m8;
        fn_8024FC74(&PlayerAt5FD4(p->m9C->m8, i)->m4D8, a);
        fn_8014E108(ip);
    }
}

int fn_801F64E4(Unk801F263C_List* p)
{
    Unk801F263C_Node* n = p->m934;
    while (n != 0) {
        if (n->m14 == 0)
            break;
        n = n->m0;
    }
    if (n != 0) {
        Unk80283934_Goal* g = 0;
        if (n->m10 == 6)
            g = (Unk80283934_Goal*)n->m18;
        if (g != 0) {
            float f = fn_802855C4(g);
            if (f < lbl_805D4EA8)
                return 1;
        }
    }
    return 0;
}

}
