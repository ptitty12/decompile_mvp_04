/*
 * Game code, .text 0x801EE438-0x801F263C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801EE438.h"

typedef Unk801EE438_Scr Scr;

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

/* near-miss (9 slots): accessor + strength-reduced loop match; retail keeps slot in r31 and p in r30 (ours
 * the reverse) and lays out the final "return 1" block before "return 0". */
inline Unk801EE438_Slot* SlotAtE77C(Unk801EE438_Slot* a, int i)
{
    Unk801EE438_Slot* q = a + i;
    return q;
}

int fn_801EE77C(Scr* p, int slot, int k)
{
    Unk801EE438_Slot* s = SlotAtE77C(p->m9C->mCA8, slot);
    if (s->m0 > 0) {
        if (fn_801E817C(p->m9C->m3A64) != 1 && fn_801E82DC(p->m9C->m3A64, slot) != 1) {
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

}
