/*
 * Game code, .text 0x801A22F4-0x801A57C8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8019F8C0.h"
#include "game/tu_801A57C8.h"

void fn_8017C82C(void* p);
void fn_8016B2B8(void* p);
void fn_8040B574(void* a, void* b);
void fn_8040A208(void* a, void* b, int n, void (*f)(char*, char*));
int fn_802AE374(void* a, void* b, void* c, void* d, void* e);
Unk8019F8C0_Ref* fn_801A6D84(Unk8019F8C0_Owner* o, int n);
Unk8019F8C0_Sub* fn_801A04A8(Unk8019F8C0_Owner* o, int i);
void fn_801A27E0(void* p);
int fn_800A8898(void* m);
void fn_80081D70(void* p);
void fn_80187354(void* p);
void fn_80242E28(int a, float f);
extern float lbl_805CE7E4;
void fn_8016C4A0(void* p);
int fn_802D7DB4(int a, int b);
void fn_801A2608(Unk8019F8C0_Owner* o);
void fn_8033E4F0(void* p);
void fn_8017A930(void* p);
void fn_801A55A8(Unk8019F8C0_Owner* o);
void fn_801A4E4C(Unk8019F8C0_Owner* o);
void fn_80164DDC(void* p);
void fn_801A7AB0(void* p);
void fn_801A2C84(Unk8019F8C0_Owner* o);
void fn_8017AC0C(void* p);
void fn_801A33E4(Unk8019F8C0_Owner* o);
void fn_801A9428(void* p);
void fn_801A6FBC(Unk8019F8C0_Owner* o);
void fn_801A6ED8(Unk8019F8C0_Owner* o);
void fn_801C4530(void* p);
void fn_80235164(void* p);
Unk8019F8C0_M2* fn_801A4CE8(Unk8019F8C0_Owner* o, int i);
extern int lbl_8061B9C8;
inline int Unk801A22F4_At(int* a, int off)
{
    return *(int*)((char*)a + off);
}
void fn_8024C0D0(int v);
int fn_800968C0(Unk8019F8C0_Inner* t, int key, int c);
int fn_80097300(Unk8019F8C0_Inner* t, int v);
int fn_80097190(Unk8019F8C0_Inner* t, int v);
int fn_801A49F0(Unk8019F8C0_Owner* o, int team, int key);
unsigned char fn_801A48F8(Unk8019F8C0_Owner* o, int i);
void fn_8016C4FC(void* p);
struct Unk801A22F4_G {
    char pad0[0x2C];
    int m2C;
};
extern Unk801A22F4_G* lbl_8068B618;
void fn_8031E1D4(void* a, void* b);
void fn_80316BC0(void* a, int b);
extern char lbl_805CE77C[];
extern char lbl_805CE78C[];
extern void* lbl_8061FEDC;
Unk8019F8C0_W* fn_801A4B34(Unk8019F8C0_Owner* o);
void fn_801A3860(Unk8019F8C0_Owner* o);
void fn_801A3920(Unk8019F8C0_Owner* o);
extern void* lbl_8061E978;

void fn_801A23B8(Unk8019F8C0_Owner* o, int flag)
{
    o->m58C[0] = o->m6F8->m10->m6C;
    o->m58C[1] = o->m6F8->m10->m70;
    if (flag) {
        fn_8017C82C(o->m700);
    }
}

int fn_801A2400(Unk8019F8C0_Owner* o)
{
    int r = 0;
    if ((unsigned)o->m4C <= 9 || o->m784 != 0 || o->m78C != 0 || o->m794 != 0 || o->m780 != 0
        || fn_801A4CE8(o, 1)->mC != 0 || fn_801A6D84(o, 1)->m3D90 != 0
        || ((Unk801A57C8_Mode*)o->m560)->m4->m14 == 4) {
        r = 1;
    }
    return r;
}

void fn_801A24AC(Unk8019F8C0_Owner* o)
{
    int i = 0;
    do {
        Unk8019F8C0_Ref* r = fn_801A6D84(o, i);
        i++;
        if (r) {
            fn_8016B2B8(r);
        }
    } while (i <= 5);
}

void fn_801A27E0(void* p) {}

void fn_801A27E4(Unk8019F8C0_Owner* o)
{
    if (o->m6F4 != 1) {
        if (o->m4C == 0) {
            ((Unk8019F8C0_OV*)o)->fn_vslot7();
        } else {
            lbl_8061B9C8 = 1;
            fn_801A6FBC(o);
            fn_801A6ED8(o);
            if (o->m700) {
                fn_801C4530(o->m700->m3A4);
                if (o->m6F8->m14[2].GetM1() <= 2) {
                    fn_80235164(o->m700->m3B0);
                }
            }
        }
    }
}

void fn_801A2890(Unk8019F8C0_Owner* o)
{
    if (o->m6F4 != 1) {
        lbl_8061B9C8 = 1;
        fn_801A6ED8(o);
        if (o->m700) {
            fn_801C4530(o->m700->m3A4);
            if (o->m6F8->m14[2].GetM1() <= 2) {
                fn_80235164(o->m700->m3B0);
            }
        }
        lbl_8061B9C8 = 2;
        ((Unk8019F8C0_OV*)o)->fn_vslot5();
    }
}

void fn_801A292C(Unk8019F8C0_Owner* o)
{
    if (o->m6F4 != 1) {
        fn_801A27E0(o);
        if (fn_802D7DB4(0, 0xa9)) {
            fn_801A2608(o);
        }
        fn_8033E4F0(o->m560);
        if (o->m700) {
            fn_8017A930(o->m700);
        }
        fn_801A55A8(o);
        fn_801A4E4C(o);
        fn_80164DDC(o->m710);
        fn_801A7AB0(o->m744);
    }
}

void fn_801A29B8(Unk8019F8C0_Owner* o)
{
    if (o->m6F4 != 1 && o->m6F4 != 0xc) {
        fn_801A2C84(o);
        if (o->m700) {
            fn_8017AC0C(o->m700);
        }
        fn_801A4CE8(o, 1)->fn_vslot5();
        fn_801A33E4(o);
        fn_801A9428(o->m744);
    }
}

void fn_801A3704(Unk8019F8C0_Owner* o, int v)
{
    if (v != 0) {
        if (o->m780 == 0) {
            Unk8019F8C0_Sub* s = fn_801A04A8(o, 5);
            if (s && s->m40) {
                fn_8016C4A0(s->m40);
            }
            s = fn_801A04A8(o, 0);
            if (s && s->m40) {
                fn_8016C4A0(s->m40);
            }
            s = fn_801A04A8(o, 1);
            if (s) {
                Unk8019F8C0_Ref* r = s->m40;
                if (r && r->m3D90 != 0) {
                    fn_8016C4FC(r);
                }
            }
        }
    } else if (o->m780 != 0) {
        lbl_8068B618->m2C = 7;
    }
    o->m780 = v;
}

void fn_801A3860(Unk8019F8C0_Owner* o)
{
    Unk8019F8C0_Sub* s = fn_801A04A8(o, 5);
    if (s) {
        Unk8019F8C0_W* w = fn_801A4B34(o);
        if (w && w->fn_vslot4() != 0) {
            fn_8031E1D4(s, lbl_805CE77C);
        } else {
            fn_8031E1D4(s, lbl_805CE78C);
        }
        s->m4 = 1;
        Unk8019F8C0_Sub* t = fn_801A04A8(o, 0);
        if (t) {
            t->m4 = 0;
        }
        fn_80316BC0(lbl_8061FEDC, 1);
    }
}

void fn_801A3920(Unk8019F8C0_Owner* o)
{
    Unk8019F8C0_Sub* s = fn_801A04A8(o, 5);
    if (s) {
        s->m4 = 0;
        if (fn_801A6D84(o, 0) && fn_801A6D84(o, 0)->m3D90 != 0) {
            Unk8019F8C0_Sub* t = fn_801A04A8(o, 0);
            if (t) {
                t->m4 = 1;
            }
            fn_80316BC0(lbl_8061FEDC, 0);
        }
    }
}

void fn_801A39B8(Unk8019F8C0_Owner* o, int v)
{
    if (v != o->m784) {
        if (v != 0 && o->m784 == 0) {
            Unk8019F8C0_Sub* s = fn_801A04A8(o, 0);
            if (s && s->m40) {
                fn_8016C4A0(s->m40);
            }
            fn_801A3860(o);
        }
        if (o->m784 != 0 && v == 0) {
            fn_801A3920(o);
        }
        o->m784 = v;
    }
}

void fn_801A3A54(Unk8019F8C0_Owner* o, int v)
{
    if (v != o->m78C) {
        if (v != 0 && o->m78C == 0) {
            fn_801A3860(o);
        }
        if (o->m78C != 0 && v == 0) {
            fn_801A3920(o);
        }
        o->m78C = v;
    }
}

void fn_801A3ACC(Unk8019F8C0_Owner* o, int v)
{
    if (v != o->m794) {
        if (v != 0 && o->m794 == 0) {
            Unk8019F8C0_Sub* s = fn_801A04A8(o, 0);
            if (s && s->m40) {
                fn_8016C4A0(s->m40);
            }
            fn_801A3860(o);
        }
        if (o->m794 != 0 && v == 0) {
            fn_801A3920(o);
        }
        o->m794 = v;
    }
}

void fn_801A3C7C(char* a, char* b)
{
    fn_8040B574(a + 4, b + 4);
}

void fn_801A3CA4(void* a, void* b)
{
    fn_8040A208(a, b, 0x14, fn_801A3C7C);
}

/* The team counter lives in memory (stack slot reloaded per use): a volatile local reproduces it. */
/* near-miss: same code; retail's registers for the memory counter / index (r0 vs r9) differ (5 slots). */
void fn_801A4674(Unk8019F8C0_Owner* o)
{
    volatile int c = 0;
    int t = 0;
    do {
        unsigned n = fn_801A48F8(o, t);
        unsigned k = 0;
        if (k < n) {
            int j = 0;
            do {
                k++;
                int v = Unk801A22F4_At(o->m594, j + c * 100);
                j += 4;
                fn_8024C0D0(v);
            } while (k < n);
        }
        int w = c;
        int r;
        if (w > 1) {
            r = w;
        } else {
            r = w + 1;
        }
        c = r;
        t = r;
    } while (t <= 1);
}

/* near-miss: same code; retail shares r0 between the byte offset and the loaded value (4 slots differ). */
void fn_801A4884(Unk8019F8C0_Owner* o)
{
    int row = 0;
    for (int a = 2; a != 0; a--) {
        int col = 0;
        for (int b = 25; b != 0; b--) {
            int v = Unk801A22F4_At(o->m594, col + row);
            col += 4;
            if (v) {
                fn_80242E28(v, lbl_805CE7E4);
            }
        }
        row += 100;
    }
}

unsigned char fn_801A48F8(Unk8019F8C0_Owner* o, int i)
{
    Unk8019F8C0_Inner* p = o->m6F8->m14 + i;
    return p->m3E4;
}

int fn_801A4A94(Unk8019F8C0_Owner* o, int key)
{
    volatile int c = 0;
    int i = 0;
    for (;;) {
        int r = fn_800968C0(&o->m6F8->m14[i], key, 0);
        if (r != 0xFF) {
            return Unk801A22F4_At(o->m594, c * 100 + r * 4);
        }
        int v = c;
        int n;
        if (v > 1) {
            n = v;
        } else {
            n = v + 1;
        }
        c = n;
        i = n;
        if (i > 1) {
            return 0;
        }
    }
}

Unk8019F8C0_W* fn_801A4B34(Unk8019F8C0_Owner* o)
{
    int f = 0;
    if (o->m6F8->m14[2].m8 != 0) {
        f = 1;
    }
    Unk8019F8C0_Inner* t = &o->m6F8->m14[f];
    return (Unk8019F8C0_W*)o->m594[f * 25 + t->m168.m0[t->m168.mC]];
}

void fn_801A4B7C(Unk8019F8C0_Owner* o, int a, int flag)
{
    int team;
    if (flag != 0) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        team = f;
    } else {
        team = o->m6F8->m14[2].m8 == 0;
    }
    Unk8019F8C0_Inner* t = &o->m6F8->m14[team];
    fn_801A49F0(o, team, fn_80097300(t, fn_80097190(t, a)));
}

int fn_801A4C20(Unk8019F8C0_Owner* o)
{
    if (o->m6F4 == 1) {
        return o->m594[0];
    }
    return 0;
}

int fn_801A4C3C(Unk8019F8C0_Owner* o, int a, int b)
{
    if (a == 0) {
        return o->m6B0[b];
    }
    return 0;
}

int fn_801A4C5C(Unk8019F8C0_Owner* o, int a, int b)
{
    return o->m6A0[a][b];
}

int fn_801A4C74(Unk8019F8C0_Owner* o, int i)
{
    return o->m690[i];
}

void fn_801A4C84(Unk8019F8C0_Owner* o)
{
    Unk8019F8C0_Mgr* m = o->m6F8;
    Unk8019F8C0_Ring* r = &m->m14[fn_800A8898(m)].m168;
    r->mC = (r->mC + 1) % r->m4;
    fn_80081D70(m->m14);
}

Unk8019F8C0_M2* fn_801A4CE8(Unk8019F8C0_Owner* o, int i)
{
    Unk8019F8C0_Sub* s = fn_801A04A8(o, i);
    return s ? s->m3C : 0;
}

void fn_801A5014(Unk8019F8C0_Owner* o)
{
    o->m6B8 = fn_802AE374(lbl_8061E978, o, &o->m6BC, &o->m6C0, &o->m740);
}

int fn_801A52D4(Unk8019F8C0_Owner* o, int key)
{
    int n = o->m6D8;
    for (int i = 0; i < n; i++) {
        if ((int)o->m6E0[i].m4 == key) {
            return i;
        }
    }
    return 0;
}

int fn_801A5318(Unk8019F8C0_Owner* o, int i)
{
    return (int)o->m6E0[i].m4;
}

void fn_801A532C(Unk8019F8C0_Owner* o)
{
    for (int i = 0; i < o->m6D8; i++) {
        fn_80187354(o->m6E0[i].m4);
    }
    o->m6CC = 0;
}

Unk8019F8C0_Obj4A4* fn_801A552C(Unk8019F8C0_Owner* o)
{
    int idx = o->m6D0;
    int n = o->m6D8;
    Unk8019F8C0_Obj4A4* found = 0;
    int start = idx;
    do {
        Unk8019F8C0_Obj4A4* e = o->m6E0[idx].m4;
        if (e->m4A4 & 0x4000000) {
            found = e;
        }
        idx--;
        idx = (idx + n) % n;
    } while (idx != start);
    return found;
}

int fn_801A5580(Unk8019F8C0_Owner* o)
{
    int i = o->m6D4;
    if (i == -1) {
        return 0;
    }
    return (int)o->m6E0[i].m4;
}

void fn_801A57B4() {}

int fn_801A57B8()
{
    char buf[0x80];
    return 0;
}
