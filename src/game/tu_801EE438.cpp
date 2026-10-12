/*
 * Game code, .text 0x801EE438-0x801F263C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801EE438.h"

typedef Unk801EE438_Scr Scr;

extern "C" int fn_802055F4(Unk801EE438_G* g);

extern float lbl_805D4CB0;

extern "C" {

int fn_801EE6F4(Scr* p, int a)
{
    int r = 0;
    int k = fn_80211BB0(&p->m9C->mC0, a);
    if (k != -1) {
        r = 1;
        fn_80211BA0(&p->m9C->mC0, k);
    }
    k = fn_80211BB0(&p->m9C->mD4, a);
    if (k != -1) {
        r = 1;
        fn_80211BA0(&p->m9C->mD4, k);
    }
    return r;
}

/* near-miss (3 slots): the pass-through slot argument of fn_801E817C fixed the register split; retail still lays out the
 * final "return 1" block before "return 0" (ternary and early-return spellings tried). */
inline Unk801EE438_Slot* SlotAtE77C(Unk801EE438_Slot* a, int i)
{
    Unk801EE438_Slot* q = a + i;
    return q;
}

int fn_801EE77C(Scr* p, int slot, int k)
{
    Unk801EE438_Slot* s = SlotAtE77C(p->m9C->mCA8, slot);
    if (s->m0 > 0) {
        if (((int (*)(int, int))fn_801E817C)(p->m9C->m3A64, slot) != 1 && fn_801E82DC(p->m9C->m3A64, slot) != 1) {
            int i;
            Unk801EE438_Ent* e = 0;
            for (i = 0; i < s->m0; i++) {
                e = &s->m4[i];
                if (fn_80204F8C(e) != 1)
                    break;
            }
            if (i < s->m0) {
                if ((fn_80204E58(e) == 0 && e->m4 != 0x1F) || (e->m0 == 0x10 && e->m1C == k))
                    return 1;
            }
        }
        return 0;
    }
    return 1;
}

int fn_801EEFA8(Scr* p, int a)
{
    int r = 0;
    int k = fn_80211BB0(&p->m9C->mD4, a);
    if (k != -1) {
        r = 1;
        fn_80211BA0(&p->m9C->mD4, k);
    }
    return r;
}

inline int PickVal(int* base, int i)
{
    if (i == -1)
        return -1;
    int* q = base + i;
    return *q;
}

int fn_801EF460(Scr* p, int a, int b)
{
    Unk801EE438_Pair* pr = &p->m9C->m684;
    int hit = 0;
    int x = pr->m8;
    if ((a == x || a == pr->m14) && (b == x || b == pr->m14))
        hit = 1;
    if (hit == 0 || fn_802055F4(p->m9C) == 1) {
        p->m9C->m684.m8 = a;
        p->m9C->m684.m14 = b;
        fn_801EDE78(p, 1);
        fn_801EF000(p, a, b);
        p->m9C->m684.m0 = PickVal(&p->m9C->mC0.m0, a);
        p->m9C->m684.m4 = PickVal(&p->m9C->mD4.m0, a);
        p->m9C->m684.mC = PickVal(&p->m9C->mC0.m0, b);
        p->m9C->m684.m10 = PickVal(&p->m9C->mD4.m0, b);
    }
    fn_801F1928(p);
}

struct Unk801EFC48_Row {
    int m0;
    char pad4[0x14];
    float m18;
    char pad1C[0x38 - 0x1C];
    Unk801EE438_Vec m38;
    float m44;
    char pad48[0x5C - 0x48];
};

struct Unk801EFC48_G {
    char pad0[4];
    Unk801EE438_Game* m4;
    char pad8[0xA8 - 8];
    float mA8;
    Unk801EE438_Vec mAC;
    char padB8[0x6B8 - 0xB8];
    Unk801EFC48_Row m6B8[10];
};

extern const float lbl_805D4C08;
extern "C" void fn_80206B08(void* p);
extern "C" void fn_80207B00(void* p);
extern "C" void fn_80208060(void* p);
extern "C" void fn_8020883C(void* p);
extern "C" void fn_80208C84(void* p, int a, int b);

/* near-miss (2 insns): retail loads the first word of the selected Vec inside each branch (ahead of the shared copy tail) */
void fn_801EFC48(Scr* p, int idx)
{
    Unk801EFC48_G* g = (Unk801EFC48_G*)p->m9C;
    if (g->m4->m36C != 0) {
        g->mA8 = lbl_805D4C08;
        Unk801EFC48_G* h = (Unk801EFC48_G*)p->m9C;
        h->mAC = *(Unk801EE438_Vec*)&g->m4->m36C->m60;
        return;
    }
    void* sub = (char*)p + 0xA8;
    fn_80206B08(sub);
    fn_80208060(sub);
    fn_80207B00(sub);
    fn_8020883C(sub);
    fn_80208C84(sub, 0, 0);
    Unk801EFC48_G* q = (Unk801EFC48_G*)p->m9C;
    Unk801EE438_Vec* src;
    if (q->m6B8[idx].m0 == 1) {
        q->mA8 = q->m6B8[idx].m18;
        q = (Unk801EFC48_G*)p->m9C;
        src = (Unk801EE438_Vec*)((char*)&q->m6B8[idx] + 8);
    } else {
        q->mA8 = q->m6B8[idx].m44;
        q = (Unk801EFC48_G*)p->m9C;
        src = &q->m6B8[idx].m38;
    }
    q->mAC = *src;
}

int fn_801EFD64(Scr* p, int i)
{
    Unk801EE438_Slot* a = p->m9C->mCA8;
    Unk801EE438_Slot* s = &a[i];
    if (s->m0 != 0 && s->m4[0].mA8 == 1)
        return 1;
    return 0;
}

void fn_801F0194(Scr* p);
void fn_801F0174(Scr* p)
{
    fn_801F0194(p);
}

int fn_801F0E78(Scr* p);
extern const float lbl_805D4C50;

inline Unk801EE438_Vec VecSub0CF0(const Unk801EE438_Vec& a, const Unk801EE438_Vec& b)
{
    Unk801EE438_Vec r;
    r.m0 = a.m0 - b.m0;
    r.m4 = a.m4 - b.m4;
    r.m8 = a.m8 - b.m8;
    return r;
}

inline Unk801EE438_Player* PlayerAt0CF0(Unk801EE438_Player** a, int i)
{
    int o = i * 4;
    return *(Unk801EE438_Player**)((char*)a + o);
}

int fn_801F0CF0(Scr* p, int a, int b, int* out)
{
    if (a == 0)
        return -1;
    int r = -1;
    float best = lbl_805D4C50;
    if (fn_801F0E78(p) == -1)
        return -1;
    Unk801EE438_G* g = p->m9C;
    Unk801EE438_Sub* q = (Unk801EE438_Sub*)&g->m1B8;
    if (q->m8 == a || q->mC == a) {
        if (out != 0)
            *out = a;
        return g->m1B8;
    }
    Unk801EE438_Player* p1 = PlayerAt0CF0(g->m8, g->m1B8);
    Unk801EE438_Player* p2 = PlayerAt0CF0(g->m8, b);
    float d2;
    Unk801EE438_Vec d = VecSub0CF0(*(Unk801EE438_Vec*)&p1->m60, *(Unk801EE438_Vec*)&p2->m60);
    d2 = d.m0 * d.m0 + d.m8 * d.m8;
    if (!(d2 >= best)) {
        r = g->m1B8;
        best = d2;
        if (out != 0)
            *out = q->mC;
    }
    return r;
}

int fn_801F0E78(Scr* p);
int fn_801F0E30(Scr* p, int a)
{
    int r = -1;
    if (a == fn_801F0E78(p))
        r = p->m9C->m1C4;
    return r;
}

int fn_801F0E78(Scr* p)
{
    return p->m9C->m1B8;
}

int fn_801F0E84(Scr* p)
{
    return p->m9C->m1BC;
}

void fn_801F0E90(Scr* p, int v)
{
    p->m9C->m1B8 = v;
}

void fn_801F0E9C(Scr* p, int v)
{
    p->m9C->m1BC = v;
}

void fn_801F0EA8(Scr* p, int a)
{
    if (a == fn_801F0E78(p))
        fn_801F0E90(p, -1);
}

void fn_801F0EEC(Scr* p, int a)
{
    if (a == fn_801F0E84(p))
        fn_801F0E9C(p, -1);
}

int fn_801F0F30(Scr* p)
{
    return p->m9C->m1CC;
}

void fn_801F0F3C(Scr* p, int v)
{
    p->m9C->m1CC = v;
}

void fn_801F0F48(Scr* p, int a)
{
    if (a == fn_801F0F30(p))
        fn_801F0F3C(p, -1);
}

void fn_801F0F8C(Scr* p, int v)
{
    p->m9C->m1D0 = v;
}

}

extern "C" {

void fn_801F174C(Scr* p, int a)
{
    fn_80205450(p->m9C, 0);
    fn_801F0EA8(p, 0);
    fn_802123D4(p, 0, 1);
    if (a == 1) {
        fn_8021BA44(p);
        p->m9C->m30 = 7;
    } else {
        fn_8021CE28(p, lbl_805D4CB0);
        fn_8021B6EC(p, 2, 1);
        fn_8021BA44(p);
        p->m9C->m30 = 5;
    }
}

void fn_801F17F0(Scr* p, int a)
{
    Unk801EE438_It it;
    fn_80211B58(&p->m9C->mC0);
    fn_80211B58(&p->m9C->mD4);
    fn_801F0EA8(p, a);
    fn_8014E09C(&it, p->m9C->m0, 1);
    Unk801EE438_It* ip = &it;
    while (ip->m8 != 10) {
        fn_80205450(p->m9C, ip->m8);
        fn_802123D4(p, 1, 1);
        fn_8021C4E0(p);
        fn_8014E108(ip);
    }
    p->m9C->m30 = 6;
}

}

extern "C" {

/* near-miss (9 slots): retail ends with cmpwi cr7,n,2; mfcr; rlwinm 29,31,31 (a signed LT test kept as
 * LT 2); ours canonicalizes to cmpwi n,1 + cror. The accessor gives retail's r9/r11 loop registers. */
inline int SlotCnt(Unk801EE438_Slot* a, int i)
{
    Unk801EE438_Slot* q = a + i;
    return q->m0;
}

int fn_801F18A0(Scr* p)
{
    Unk801EE438_It it;
    int n = 0;
    fn_8014E09C(&it, p->m9C->m0, 1);
    Unk801EE438_It* ip = &it;
    while (ip->m8 != 10) {
        if (SlotCnt(p->m9C->mCA8, ip->m8) != 0)
            n++;
        fn_8014E108(ip);
    }
    return n < 2;
}

void fn_801F1CA0()
{
}

extern const float lbl_805D4CDC;
extern const Unk801EE438_Vec lbl_805D6760[];

extern const float lbl_805D4CE0;
extern "C" float fn_804028E4(float x); /* square root */

inline Unk801EE438_Vec VecSub1DB4(const Unk801EE438_Vec& a, const Unk801EE438_Vec& b)
{
    Unk801EE438_Vec r;
    r.m0 = a.m0 - b.m0;
    r.m4 = a.m4 - b.m4;
    r.m8 = a.m8 - b.m8;
    return r;
}

int fn_801F1CA4(Scr*, Unk801EE438_Vec* pos, float* out)
{
    float bestD = lbl_805D4CDC;
    int best = -1;
    int cnt = 0;
    int e = 0;
    do {
        float d2;
        Unk801EE438_Vec d = VecSub1DB4(*pos, lbl_805D6760[e]);
        d2 = d.m0 * d.m0 + d.m8 * d.m8;
        if (best == -1 || !(d2 >= bestD)) {
            best = *(volatile int*)&cnt;
            bestD = d2;
        }
        int c = *(volatile int*)&cnt;
        int t;
        if (c > 3)
            t = c;
        else
            t = c + 1;
        *(volatile int*)&cnt = t;
        e = t;
    } while (e <= 3);
    if (out != 0)
        *out = fn_804028E4(bestD);
    return best;
}

inline Unk801EE438_Player* PlayerAt1DB4(Unk801EE438_Player** a, int i)
{
    int o = i * 4;
    return *(Unk801EE438_Player**)((char*)a + o);
}

int fn_801F1DB4(Scr* p, Unk801EE438_Vec* pos, float* out)
{
    float bestD = lbl_805D4CE0;
    int best = -1;
    Unk801EE438_It it;
    Unk801EE438_It* ip = &it;
    fn_8014E09C(ip, p->m9C->m0, 1);
    while (it.m8 != 10) {
        int i = it.m8;
        Unk801EE438_Player* pl = PlayerAt1DB4(p->m9C->m8, i);
        float d2;
        Unk801EE438_Vec d = VecSub1DB4(*pos, *(Unk801EE438_Vec*)&pl->m60);
        d2 = d.m0 * d.m0 + d.m8 * d.m8;
        if (best == -1 || !(d2 >= bestD)) {
            best = i;
            bestD = d2;
        }
        fn_8014E108(ip);
    }
    if (out != 0)
        *out = fn_804028E4(bestD);
    return best;
}

}
