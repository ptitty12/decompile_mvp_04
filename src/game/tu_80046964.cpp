/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80046964-0x80047B08 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80046964.h"

/* near-miss: interval classifier; same length as retail but x is kept in f13 here, retail keeps the
 * lfs value in f13 and the fmr copy in f12 and reloads from the slot later (family: 80046964..80046E68) */
int fn_80046964(float x)
{
    int r = 0;
    if (!(x < 0.0) && !(x >= 0.4))
        r = 0x1000;
    if (!(x < 0.4) && !(x >= 0.6))
        r |= 0x2000;
    if (!(x < 0.6) && !(x >= 1.01))
        r |= 0x400;
    return r;
}

inline int SumSide(Unk80044C10_Side* s)
{
    int t = 0;
    for (int i = 0; i < 0x80; i++)
        t += s->m1B4[(unsigned char)i];
    return t;
}

int fn_80046F94(int a)
{
    int r = (unsigned)a <= 1 ? 0x200 : 0;
    if (a > 2)
        return r | 0x400;
    return r;
}

int fn_80046FB4(int a)
{
    int r = (unsigned)a <= 5 ? 0x40 : 0;
    if (a > 6)
        return r | 1;
    return r;
}

int fn_80046FD4(int a)
{
    int r = (unsigned)a <= 3;
    if ((unsigned)(a - 4) <= 2)
        r |= 2;
    if (a > 6)
        r |= 4;
    if (a == 0)
        r |= 8;
    unsigned t = a - 1;
    if (t <= 2)
        r |= 0x10;
    if (t <= 5)
        r |= 0x20;
    if (t <= 9)
        r |= 0x40;
    if (a > 10)
        r |= 0x80;
    if (a == 1)
        r |= 0x100;
    if (a > 5)
        return r | 0x200;
    return r;
}

int fn_8004705C(int a)
{
    int f = a == 0;
    int r = f << 3;
    if (a == 1)
        r |= 0x20;
    if ((unsigned)a <= 1)
        r |= 0x800;
    if ((unsigned)a <= 3)
        r |= 0x80;
    if ((unsigned)a <= 6)
        r |= 0x100;
    if ((unsigned)a <= 10)
        r |= 0x200;
    if (a > 5)
        r |= 0x100000;
    if (a > 10)
        r |= 0x400;
    if (a > 0)
        r |= 0xC0000;
    if (a > 2) {
        r |= 0x8000;
        r |= 0x10000;
    }
    if (a > 4)
        r |= 0x4040;
    if (a > 9)
        r |= 0x1000;
    if ((unsigned)a <= 3)
        r |= 1;
    if ((unsigned)(a - 4) <= 2)
        r |= 2;
    if (a > 6)
        r |= 4;
    return r;
}

int fn_80047118(int a)
{
    return (unsigned)a <= 5 ? 0x2000 : 0;
}

int fn_800471B0(int a)
{
    int r = (a ^ 1) == 0;
    if (a == 0)
        r |= 2;
    if (a == 2)
        return r | 4;
    return r;
}

int fn_800471DC(int a, int b, int c)
{
    int* tbl = lbl_805B1CFC;
    int t = 0;
    if (c != 0)
        t = 4;
    int i = t;
    if (b != 0)
        i += 8;
    if (a != 0)
        i += 0x10;
    return *(int*)((char*)tbl + i);
}

int fn_80047218(int a)
{
    int r = 0;
    if (a == 0)
        r = 1;
    else if (a == 1)
        r = 2;
    else if (a == 2)
        r = 4;
    return r;
}

/* near-miss: 97 vs 98 insns; the four 128-byte sum loops allocate their address/index temps
 * in the other order (clrlwi r9 / addi r11 / lbzx r0 in retail) */
int fn_80047250(Unk80044C10_B* b)
{
    Unk80044C10_C* c = b->m6F8;
    Unk80044C10_E* e = c->m14;
    int s0 = SumSide(&e->sides[0]);
    int s1 = SumSide(&e->sides[1]);
    int so = SumSide(&e->sides[e->m1CD0 == 0]);
    int flag = 0;
    if (e->m1CD0 != 0)
        flag = 1;
    int sf = SumSide(&e->sides[flag]);
    if (__builtin_abs(s0 - s1) <= 3) {
        int r = 1;
        float ratio = (float)(e->m1CC8 + 1) / (float)c->m10->m1C;
        if (!(ratio <= 0.66f))
            r = 8;
        return r;
    }
    int r = 2;
    if (so > sf)
        r = 4;
    return r;
}

int fn_800473D4(int a)
{
    int r = 0;
    if (a == 1)
        r = 1;
    else if (a == 2)
        r = 2;
    else if (a == 3)
        r = 4;
    return r;
}

int fn_8004740C(int a)
{
    int r = 0;
    switch (a) {
    case 0:
        r = 0x40;
        break;
    case 1:
        r = 0x10;
        break;
    case 2:
        r = 2;
        break;
    case 3:
        r = 1;
        break;
    case 4:
        r = 4;
        break;
    case 5:
        r = 8;
        break;
    case 6:
        r = 0x200;
        break;
    case 7:
        r = 0x20;
        break;
    case 8:
        break;
    }
    return r;
}

/* near-miss: 5 slots differ (loop temps r9/r11/r0 and the E pointer register) */
int fn_800474A4(Unk80044C10_A* o)
{
    Unk80044C10_C* c = o->m130->m44C->m6F8;
    Unk80044C10_E* e = c->m14;
    unsigned lim = c->m10->m1C;
    int a = SumSide(&e->sides[0]);
    int b = SumSide(&e->sides[1]);
    int hi = a;
    int lo = b;
    int r = 0;
    int flip = 0;
    if (hi < lo) {
        hi = b;
        flip = 1;
        lo = a;
    }
    if (b == a) {
        r = 1;
        if (o->m3B4 == 0 && o->m0 >= lim)
            r = 4;
    } else if (flip != o->m3B4 && hi - lo == 1) {
        r = 2;
    }
    return r;
}

int fn_80047584(int a)
{
    unsigned t = a - 1;
    int r = 0;
    if (t <= 9)
        r = 1 << t;
    return r;
}

int fn_800475A4(int a)
{
    int r = 0;
    if (a > 90)
        r = 2;
    else if (a > 80)
        r = 4;
    else if (a > 60)
        r = 8;
    else if (a >= 0)
        r = 0x10;
    return r;
}

Unk8004763C* fn_800475EC()
{
    if (lbl_80617800 == 0) {
        lbl_80617800 = fn_8004763C(new (0) Unk8004763C);
        fn_803EE7BC();
    }
    return lbl_80617800;
}

void fn_8004778C(Unk8004763C* t, int flags)
{
    fn_80048B2C(&t->mFC, 2);
    if (flags & 1)
        fn_80377408(t);
}

void fn_800477D4(Unk8004763C* t)
{
    if (t->mF4 == 1) {
        if (t->mF8 == 0)
            t->mF8 = fn_80047B08(t);
        int i = 0;
        int off = 0;
        do {
            if (t->mSlots[i].mC == 0)
                fn_8004838C(t, i);
            int s0 = t->mSlots[i].m0;
            if (s0 == 1) {
                if (t->mSlots[i].m4 == 0 && t->mSlots[i].mC != 0 && fn_800484A8(t, i) > 0)
                    t->mSlots[i].m4 = s0;
            }
            i++;
            off += 0x1C;
        } while (i <= 7);
        fn_80048BC0(&t->mFC);
    }
}

void fn_80047898(Unk8004763C* t)
{
    unsigned f = 0;
    if (t->mF4 == 1) {
        int v = t->mC00;
        f = (unsigned)~v >> 31;
    }
    if (f == 1) {
        int i = 0;
        do {
            fn_80047D40(t, i);
            i++;
        } while (i <= 7);
    }
    int j = 0;
    do {
        fn_80048818(t, j);
        j++;
    } while (j <= 7);
    if (t->mF8 == 1)
        fn_80047CA4(t);
    fn_80048BE4(&t->mFC);
    if (lbl_80617800 != 0) {
        fn_8004778C(lbl_80617800, 3);
        lbl_80617800 = 0;
    }
}

/* near-miss: 2 slots differ (li r9,0 vs addi r11,r31,0xBE0 order before the scan loop) */
int fn_80047958(Unk8004763C* t, int idx)
{
    if (t->mF4 == 0) {
        t->mBE0[idx] = -3;
    } else if (t->mBE0[idx] < 0) {
        if (t->mF8 == 0)
            t->mF8 = fn_80047B08(t);
        if (t->mF8 == 1) {
            int v;
            switch (fn_80048294(t, idx)) {
            case -3:
                v = -3;
                break;
            case 0:
                v = 0;
                break;
            case 1:
                v = 1;
                break;
            case -1:
                v = -1;
                break;
            case -2:
                v = -2;
                break;
            default:
                v = -2;
                break;
            }
            t->mBE0[idx] = v;
        }
        t->mC00 = -1;
        int k;
        for (k = 0; k < 8; k++) {
            if (t->mBE0[k] >= 0) {
                t->mC00 = t->mBE0[k];
                break;
            }
        }
        if (idx == 3 || idx == 6) {
            fn_800490F4(&t->mFC);
            t->mC04 = t->mC04 + 1;
            fn_80391348(t->mC04);
        }
    }
    switch (t->mBE0[idx]) {
    case -3:
        return -3;
    case -1:
        return -1;
    case 0:
        return 0;
    case 1:
        return 1;
    case -2:
        return -2;
    default:
        return -2;
    }
}

void fn_80047B04()
{
}
