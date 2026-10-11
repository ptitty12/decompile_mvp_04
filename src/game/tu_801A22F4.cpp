/*
 * Game code, .text 0x801A22F4-0x801A57C8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8019F8C0.h"

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
extern void* lbl_8061E978;

void fn_801A23B8(Unk8019F8C0_Owner* o, int flag)
{
    o->m58C[0] = o->m6F8->m10->m6C;
    o->m58C[1] = o->m6F8->m10->m70;
    if (flag) {
        fn_8017C82C(o->m700);
    }
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

void fn_801A3C7C(char* a, char* b)
{
    fn_8040B574(a + 4, b + 4);
}

void fn_801A3CA4(void* a, void* b)
{
    fn_8040A208(a, b, 0x14, fn_801A3C7C);
}

/* near-miss: retail steps byte offsets (+4 per column, +100 per row) with count-down loops; 14 slots differ. */
void fn_801A4884(Unk8019F8C0_Owner* o)
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 25; j++) {
            int v = o->m594[i * 25 + j];
            if (v) {
                fn_80242E28(v, lbl_805CE7E4);
            }
        }
    }
}

unsigned char fn_801A48F8(Unk8019F8C0_Owner* o, int i)
{
    Unk8019F8C0_Inner* p = o->m6F8->m14 + i;
    return p->m3E4;
}

int fn_801A4B34(Unk8019F8C0_Owner* o)
{
    int f = 0;
    if (o->m6F8->m14[2].m8 != 0) {
        f = 1;
    }
    Unk8019F8C0_Inner* t = &o->m6F8->m14[f];
    return o->m594[f * 25 + t->m168.m0[t->m168.mC]];
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

void* fn_801A4CE8(Unk8019F8C0_Owner* o, int i)
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
