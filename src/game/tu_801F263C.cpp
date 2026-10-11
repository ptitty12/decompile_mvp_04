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

struct Unk801F263C_Cmd {
    char pad0[0x14];
    int m14;
    char pad18[4];
    int m1C;
    int m20;
};

struct Unk801F263C_List {
    char pad0[0x934];
    Unk801F263C_Node* m934;
};

extern const float lbl_805D4EA8;
extern const float lbl_805D4E80;
extern Unk801EE438_Vec lbl_805D6790;
extern float lbl_805D4D68;

extern "C" {
int fn_801F5DD8(Scr* p, int a);
int fn_8024D408(int a);
int fn_8026D8E8(int a, int b);
int fn_80210FC4(Unk801EE438_G** g, int a, int b, int c);
int fn_80210DA8(Unk801EE438_G** g, int a, int b);
int fn_80211D34(void* p);
int fn_80247858(int a, int b);
int fn_80210D20(Unk801EE438_G** g, int a);
int fn_80210C98(Unk801EE438_G** g, int a);

void fn_801F263C(Scr* p, void* v)
{
    int tmp;
    fn_801F2668(p, &tmp, v, -1);
}

inline Unk801EE438_Player* PlayerAt5E18(Unk801EE438_Player** a, int i)
{
    Unk801EE438_Player** q = a + i;
    return *q;
}

Unk801EE438_Player* fn_801F29AC(Scr* p, Unk801EE438_Game* g, Unk801EE438_Player* x)
{
    Unk801EE438_Player* r = fn_801EDE4C(p, g);
    return r != 0 ? (r == x ? p->m9C->m8[0] : r)
                  : (g->m38C == 3 ? (g->m374 == x ? g->m378 : g->m374)
                                  : (p->m9C->mA4 != -1 ? p->m9C->m8[p->m9C->mA4] : p->m9C->m8[0]));
}

/* near-miss (6 slots): only the f11/f12 assignment of the double (0x4330...) and float constants is swapped. */
int fn_801F30B8(Scr* p, Unk801EE438_Vec* out, float* outf)
{
    Unk801EE438_G* g = p->m9C;
    if (!(g->mC80 <= (float)g->m0->m4C * lbl_805D4D68)) {
        *out = g->mC4C;
        if (outf != 0) {
            Unk801EE438_G* h = p->m9C;
            *outf = h->mC80 - (float)h->m0->m4C * lbl_805D4D68;
        }
        return 1;
    }
    return 0;
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

int fn_801F5DD8(Scr* unused, int a)
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

inline Unk801EE438_Player* PlayerAtIdx5EF0(Unk801EE438_Owner* o, unsigned k)
{
    if (k <= 12)
        return o->m65C[k];
    return 0;
}

inline Unk801EE438_Player* PlayerAt5EF0(Unk801EE438_Player** a, int i)
{
    Unk801EE438_Player** q = a + i;
    return *q;
}

void fn_801F5E18(Scr* p)
{
    int found = 0;
    Unk801EE438_G* g = p->m9C;
    Unk801EE438_Player* t = g->m4->m36C;
    if (t != 0) {
        float d2 = (t->m60 - lbl_805D6790.m0) * (t->m60 - lbl_805D6790.m0) + (t->m68 - lbl_805D6790.m8) * (t->m68 - lbl_805D6790.m8);
        found = d2 < lbl_805D4E80;
    }
    Unk801EE438_It it;
    fn_8014E09C(&it, g->m0, 1);
    Unk801EE438_It* ip = &it;
    while (it.m8 != 10) {
        int i = it.m8;
        Unk801EE438_Player* q = PlayerAt5E18(p->m9C->m8, i);
        if (q != 0)
            fn_8024FBEC(&q->m4D8, found);
        fn_8014E108(ip);
    }
}

void fn_801F5EF0(Scr* p)
{
    int found = 0;
    unsigned i = 9;
    do {
        Unk801EE438_Player* pl = PlayerAtIdx5EF0(p->m9C->m0, i);
        if (pl != 0 && fn_80254EA4(&pl->m58C, 0) != -1) {
            found = 1;
            break;
        }
        i++;
    } while ((int)i <= 12);
    if (found == 0) {
        Unk801EE438_It it;
        fn_8014E09C(&it, p->m9C->m0, 1);
        Unk801EE438_It* ip = &it;
        while (ip->m8 != 10) {
            int i = ip->m8;
            Unk801EE438_Player* q = PlayerAt5EF0(p->m9C->m8, i);
            if (q != 0)
                fn_8024FC94(&q->m4D8);
            fn_8014E108(ip);
        }
    }
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

int fn_801F6568(Scr* p, int a, Unk801F263C_Cmd* c)
{
    if (fn_801F5DD8(p, c->m14) == 1)
        return 0;
    if (fn_8024D408(a) != 0) {
        if (c->m20 == 5) {
            if (fn_80210FC4(&p->m9C, 2, 3, 0) == 1)
                return 1;
            if (c->m20 == 5 && fn_80210FC4(&p->m9C, 2, c->m1C, 0) == 0)
                return 1;
        }
        if (fn_8026D8E8(a, 0) == 1 && fn_80210DA8(&p->m9C, 4, fn_80211D34(&p->m9C->mE8)) == 0 &&
            fn_80247858(fn_80211D34(&p->m9C->mE8), 0) != c->m1C)
            return 1;
    }
    return 0;
}

}
