/*
 * Game code, .text 0x802028E4-0x80206B08 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801EE438.h"
#include "game/tu_802028E4.h"

typedef Unk802028E4_Obj Obj;
typedef Unk801EE438_Scr Scr;

extern "C" {
void fn_80205A5C(Obj* o);
}

inline void SetAt(int* b, int i, int v)
{
    int* q = b + i;
    *q = v;
}

extern const Unk801EE438_Vec lbl_805D6760;
extern float lbl_8061D560;
extern float lbl_8061D040;
extern const float lbl_805D5254;
extern const float lbl_805D5258;
extern "C" float fn_804028E4(float x); /* square root */
extern "C" float fn_80250338(void* o, float a, float b);
extern "C" float fn_80189D88(Unk801EE438_Game* g, Unk801EE438_Player* pl, Unk801EE438_Vec* pos, Unk801EE438_Vec* v, float f);
extern "C" void fn_8023CAF0(Unk801EE438_Player* pl);

inline Unk801EE438_Vec VecSub28E4(const Unk801EE438_Vec& a, const Unk801EE438_Vec& b)
{
    Unk801EE438_Vec r;
    r.m0 = a.m0 - b.m0;
    r.m4 = a.m4 - b.m4;
    r.m8 = a.m8 - b.m8;
    return r;
}

inline float Len28E4(Unk801EE438_Vec v)
{
    return fn_804028E4(v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8);
}

extern "C" float fn_802028E4(Scr* s, Unk801EE438_Player* pl, Unk801EE438_Vec* pos)
{
    Unk801EE438_Vec a = lbl_805D6760;
    Unk801EE438_Game* g = s->m9C->m4;
    fn_8023CAF0(pl);
    a.m4 = lbl_8061D560 * lbl_805D5254;
    float r = ((float*)pos)[3] + lbl_8061D040;
    float k = lbl_805D5258;
    float c = fn_80250338((char*)pl + 0x4D8, Len28E4(VecSub28E4(*pos, a)), lbl_805D5258);
    r += fn_80189D88(g, pl, pos, &a, c);
    return r;
}

extern "C" void fn_80204610(Scr* p, int a1, int a2, int a3)
{
    int x;
    if (((Unk801EE438_Sel*)p->m9C->m3A64)->m794 > 0)
        x = fn_801E82CC((Unk801EE438_Sel*)p->m9C->m3A64, 0);
    else
        x = -1;
    int y;
    if (((Unk801EE438_Sel*)p->m9C->m3A64)->m798 > 0)
        y = fn_801E816C((Unk801EE438_Sel*)p->m9C->m3A64, 0);
    else
        y = -1;
    if (p->m9C->mA4 != a1 && x != a1 && y != a1) {
        fn_80205450(p->m9C, a1);
        fn_801EE6F4(p, a1);
        fn_801F0EA8(p, a1);
        fn_802123D4(p, 1, 1);
        fn_80211BA0(&p->m9C->mC0, a2);
        SetAt(&p->m9C->mD4.m0, a2, a3);
        fn_80213988(p, a2, 1);
    }
}

struct Unk802049E8_Rec {
    int m0;
    int m4;
    Unk801EE438_Vec m8;
    float m14;
    float m18;
    int m1C;
    Unk801EE438_Vec m20;
    float m2C;
    float m30;
    int m34;
    Unk801EE438_Vec m38;
    float m44;
    int m48;
    int m4C;
    float m50;
    float m54;
    int m58;
};

extern const Unk801EE438_Vec lbl_806055AC;
extern const float lbl_805D5348;
extern const float lbl_805D534C;

extern "C" void fn_802049E8(Unk801EE438_Rec5C* rec)
{
    Unk802049E8_Rec* r = (Unk802049E8_Rec*)rec;
    r->m0 = 0;
    r->m4 = 0;
    r->m8 = lbl_806055AC;
    r->m14 = lbl_805D5348;
    r->m18 = lbl_805D5348;
    r->m1C = -1;
    r->m2C = lbl_805D5348;
    r->m20 = lbl_806055AC;
    r->m30 = lbl_805D5348;
    r->m34 = -1;
    r->m38 = lbl_806055AC;
    r->m44 = lbl_805D5348;
    r->m48 = -1;
    r->m4C = 0;
    r->m50 = lbl_805D534C;
    r->m54 = lbl_805D534C;
    r->m58 = 3;
}

extern "C" void fn_80204AAC(Unk802028E4_Pair* o)
{
    o->m0 = -1;
    o->m4 = -1;
    o->m8 = 0;
    o->mC = 0;
}

struct Unk80204CCC_Rec {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    Unk801EE438_Vec v[7];
    char pad80[0x80 - 0x80];
    float m80;
    float m84;
    float m88;
    float m8C;
    float m90;
    int m94;
    int m98;
    int m9C;
    int mA0;
    int mA4;
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    int mB8;
    int mBC;
    int mC0;
    int mC4;
    int mC8;
    int mCC;
    int mD0;
    int mD4;
};

extern const Unk801EE438_Vec lbl_806055DC;
extern const float lbl_805D5358;
extern const float lbl_805D535C;

/* near-miss (50 slots after a 14-pass swap/move hill climb from ascending order; the true statement order is
   not reached): all stores and the 7 Vec copies are present, frame and length (99 insns) match */
extern "C" void fn_80204CCC(Unk80204CCC_Rec* r)
{
    r->m80 = lbl_805D5358;
    r->m0 = 0;
    r->mCC = -1;
    r->m8C = lbl_805D535C;
    r->mC = 2;
    r->m10 = 0xA;
    r->mA4 = 1;
    r->m14 = 0;
    r->m18 = 0;
    r->m1C = -1;
    r->m20 = 0;
    r->m24 = 0;
    r->v[3] = lbl_806055DC;
    r->mA0 = 0;
    r->m84 = lbl_805D535C;
    r->m88 = lbl_805D535C;
    r->m8 = 2;
    r->m90 = lbl_805D535C;
    r->m94 = 0;
    r->m98 = 0;
    r->m9C = 0;
    r->mC8 = 0x11;
    r->mA8 = 0;
    r->mAC = 0;
    r->mB0 = 0;
    r->mB4 = 0;
    r->mB8 = 0;
    r->v[5] = lbl_806055DC;
    r->mBC = 0;
    r->mC0 = 0;
    r->mC4 = 0;
    r->m28 = 0;
    r->m4 = 0;
    r->mD0 = 0;
    r->v[2] = lbl_806055DC;
    r->v[1] = lbl_806055DC;
    r->v[4] = lbl_806055DC;
    r->v[0] = lbl_806055DC;
    r->v[6] = lbl_806055DC;
    r->mD4 = 0;
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

struct Unk80205468_G {
    Unk801EE438_Owner* m0;
    Unk801EE438_Game* m4;
    char pad8[0xA8 - 8];
    float mA8;
};

extern const float lbl_805D5680;
extern const float lbl_805D5684;

extern "C" int fn_80205468(Unk80205468_G* g)
{
    return (g->m4->m36C != 0 || !(g->mA8 - (float)g->m0->m4C * lbl_805D5680 >= lbl_805D5684)) ? 1 : 0;
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

struct Unk802054E0_Game {
    char pad0[0x3F4];
    float m3F4;
};

struct Unk802054E0_G {
    Unk801EE438_Owner* m0;
    Unk802054E0_Game* m4;
    char pad8[0xC78 - 8];
    float mC78;
};

extern const float lbl_805D5688;
extern const float lbl_805D5698;
extern "C" float fn_8018CDB8(void* o, int k, float f);

extern "C" int fn_802054E0(Unk802054E0_G* g, float f)
{
    Unk802054E0_Game* m4 = g->m4;
    float a = fn_8018CDB8(m4, 0xB, m4->m3F4);
    if (!(a <= lbl_805D5688)) {
        a = a - m4->m3F4;
        a = (float)g->m0->m4C * lbl_805D5698 + a;
        if (!(g->mC78 <= lbl_805D5688)) {
            if (!(a <= g->mC78))
                a = g->mC78;
        }
        if ((float)g->m0->m4C * lbl_805D5698 + f < a)
            return 1;
    }
    return 0;
}

extern "C" void fn_80205684()
{
}

/* near-miss (far): both 0x80-byte sum loops compile to retail's mtctr/bdnz shape; retail computes
 * w + (m1CD0 == 0) * 0xE64 once before the first loop (subfic/adde, mulli, add) and keeps +0x1B4 inside the loop,
 * ours branches on the flag and reorders the prologue loads. */
extern "C" int fn_80205688(Scr* p)
{
    Unk802028E4_Y* y = p->m0->m0->m6F8;
    if (y == 0)
        return 1;
    Unk802028E4_W* w = y->m14;
    int total = y->m10->m1C;
    int cur = w->m1CC8 + 1;
    int a = 0;
    int f = w->m1CD0 == 0;
    Unk802028E4_Team* t = &w->m0[f];
    for (int n = 0; n < 0x80; n++)
        a += t->m1B4[(unsigned char)n];
    int s = 0;
    if (w->m1CD0 != 0)
        s = 1;
    int b = 0;
    Unk802028E4_Team* u = &w->m0[s];
    for (int n = 0; n < 0x80; n++)
        b += u->m1B4[(unsigned char)n];
    if (cur >= total - 1) {
        if (a == b || a == b + 1)
            return 3;
    }
    if (cur > total - 2 && a >= b + 3)
        return 2;
    return 1;
}

struct Unk8020667C_Rec {
    int m0;
    int m4;
    float m8;
    int mC;
    int m10;
    int m14;
};

extern const float lbl_805D56D4;

inline Unk8020667C_Rec* RecAt667C(Unk801EE438_G* g, int i)
{
    char* b = (char*)g + 0x2B4;
    int o = i * 0x40 - 0x94;
    Unk8020667C_Rec* r = (Unk8020667C_Rec*)(b + o);
    if ((unsigned)(i - 9) > 3)
        r = 0;
    return r;
}

struct Unk8020593C_Pl {
    char pad0[0x708];
    int m708;
};

inline Unk8020593C_Pl* PlAt593C(Unk801EE438_Owner* o, unsigned k)
{
    if (k <= 12)
        return (Unk8020593C_Pl*)o->m65C[k];
    return 0;
}

/* near-miss (same family as fn_80205688): retail reloads w->m1CD0 after the first 0x80-byte sum loop, ours keeps the value
   loaded before it in a register (volatile reads and re-derived w did not help) */
extern "C" int fn_8020593C(Scr* p, int idx)
{
    if (idx == -1)
        return 0;
    Unk802028E4_Y* y = p->m0->m0->m6F8;
    int total = y->m10->m1C;
    int cur = y->m14->m1CC8 + 1;
    Unk8020593C_Pl* pl = PlAt593C(p->m0->m0, idx);
    Unk802028E4_W* w = y->m14;
    int flag = pl->m708 == 0;
    int a = 0;
    int f = w->m1CD0 == 0;
    Unk802028E4_Team* t = &w->m0[f];
    for (int n = 0; n < 0x80; n++)
        a += t->m1B4[(unsigned char)n];
    int s = 0;
    if (w->m1CD0 != 0)
        s = 1;
    int b = 0;
    Unk802028E4_Team* u = &w->m0[s];
    for (int n = 0; n < 0x80; n++)
        b += u->m1B4[(unsigned char)n];
    if (cur < total || flag != 1 || a != b)
        return 0;
    return 1;
}

extern "C" void fn_80205A3C(Obj* o)
{
    fn_80205A5C(o);
}

extern "C" int fn_8020667C(Scr* p)
{
    for (int i = 12; i >= 9; i--) {
        Unk8020667C_Rec* r = RecAt667C(p->m0, i);
        if (r->m4 == 2 && r->m14 == 1 && r->mC == 1 && !(r->m8 >= lbl_805D56D4))
            return r->m0;
    }
    return -1;
}
