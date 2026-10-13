/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80044C10-0x80045C8C only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80044C10.h"

int fn_80044C10()
{
    if (lbl_806EF9A8 == 1) {
        lbl_806E0288 = -1;
        lbl_806EF9A8 = 0;
    } else if (lbl_806E0288 != -1) {
        lbl_806EF9A8 = 1;
    }
    if (lbl_806EF9AC == 2) {
        lbl_806E028C = -1;
        lbl_806EF9AC = 0;
    } else if (lbl_806E028C != -1) {
        lbl_806EF9AC += 1;
    }
    return 1;
}

void fn_80044C98(Unk80044C98_Arg* a)
{
    unsigned short t = a->mC;
    if (t != lbl_806EF9B0) {
        fn_80057C30(fn_800475EC()->mFC.mA9C, t);
        lbl_806EF9B0 = t;
    }
    fn_800475EC()->fn_80047DE0(a->m0, a->m4, a->m8, a->m1C);
}

int fn_80044D00(unsigned a)
{
    return a > 1 ? 1 : 2;
}

int fn_80044D14(unsigned a)
{
    return a > 1 ? 1 : 2;
}

int fn_80044D28(int a)
{
    return a <= 1 ? 2 : 1;
}

int fn_80044D3C(int a)
{
    switch (a) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 8;
    default:
        return 0;
    }
}

/* near-miss: result register is r7 here, r0 in retail, and the "r = 1" arm is hoisted above
 * the first compare (35 vs 36 insns) */
int fn_80044D90(unsigned a, unsigned b, int c, int d, int e, int f, int g)
{
    int r = 0;
    if (a != 0) {
        float t = (float)b / (float)a;
        if (!(t > 0.34f)) {
            r = 1;
        } else {
            r = 4;
            if (!(t > 0.67f))
                r = 2;
        }
    }
    return r;
}

int fn_80044E60(unsigned a, unsigned b, int c, int d);

void fn_80044E20(Unk80044C10_A* o)
{
    fn_80044E60(o->m130->m44C->m6F8->m10->m1C, o->m0, o->m1, o->m4D4);
}

int fn_80044E60(unsigned a, unsigned b, int c, int d)
{
    int r;
    if (d == 3) {
        r = 0x100;
        if (c == 0)
            r = 0x80;
    } else if (c == 0) {
        r = 8;
        if (b == a)
            r = 0x20;
    } else {
        r = 0x10;
    }
    if (b > a)
        return r | 4;
    if (b == a)
        return r | 0x40;
    return r;
}

int fn_80044EC0(int a, int b, int c, Unk80044C10_A* d, int e)
{
    float f;
    int r = 0;
    int ret = fn_80247858(e, &f);
    if (!(f <= 57600.0f))
        ret = -1;
    if (d && d->m458 == 1 && a != 0) {
        switch (ret) {
        case -1:
        case 3:
            break;
        case 0:
            r = 8;
            break;
        case 1:
            r = 2;
            break;
        case 2:
            r = 4;
            break;
        }
    } else if (c > 2) {
        if (b == 11)
            r = 1;
        else if (b == 5)
            r = 0x10;
        else
            r = 0x20;
    }
    return r;
}

int fn_80044FAC(unsigned a)
{
    int r = 0;
    if (a == 0)
        r = 0x400;
    else if (a <= 10)
        r = 1 << (a - 1);
    else if (a <= 19)
        r = 1 << a;
    return r;
}

int fn_80044FF0(unsigned a)
{
    int r = 1;
    if (a > 10)
        r = 0;
    else if (a == 0)
        r = 0x400;
    else
        r <<= a - 1;
    return r;
}

int fn_80045024(int a)
{
    int r = 1;
    unsigned t = a - 1;
    if (t > 30)
        r = 0;
    else
        r <<= t;
    return r;
}

int fn_80045044(int a, int b, int c, int d, int e, int f)
{
    int r = 0;
    if (a == 2)
        r = 2;
    else if (a == 3)
        r = 4;
    if (b == 1)
        r |= 1;
    if (d == 1)
        r |= 0x20;
    if (c == 1)
        r |= 0x40;
    if (e == 1)
        r |= 8;
    if (f == 12)
        r |= 0x10;
    return r;
}

int fn_800450A8(int a, int b, int c, int d, int e, Unk80044C10_A* o)
{
    float f, x, y;
    int r = 0;
    fn_8018CA5C(o->m6CC, &f, &x, &y);
    f *= 57.295773f;
    if (((!(f < 25.0f) && f <= 38.0f) || (!(f < 52.0f) && !(f > 63.0f))) && a == 0) {
        r = 0;
    } else if (b == 4 || b == 6) {
        switch (a) {
        case 0:
            break;
        case 1:
            r |= 0x800000;
            break;
        case 2:
            r |= 0x8000;
            break;
        case 3:
            r |= 0x100;
            if (d == 1)
                r |= 0x2000000;
            if (e == 1)
                r |= 0x4000000;
            break;
        }
    } else {
        switch (c) {
        case 0:
            switch (a) {
            case 0:
                r |= 0x80000;
                break;
            case 1:
                r |= 0x1800000;
                break;
            case 2:
                r |= 0x28000;
                break;
            case 3:
                r |= 0x20300;
                if (d == 1)
                    r |= 0x2100000;
                if (e == 1)
                    r |= 0x4000000;
                break;
            }
            break;
        case 1:
            switch (a) {
            case 0:
                r |= 0x80;
                break;
            case 1:
                r |= 0xA00080;
                break;
            case 2:
                r |= 0x8001;
                break;
            case 3:
                r |= 0x109;
                if (d == 1)
                    r |= 0x2000004;
                if (e == 1)
                    r |= 0x4000000;
                break;
            }
            break;
        case 2:
            switch (a) {
            case 0:
                r |= 0x2000;
                break;
            case 1:
                r |= 0xC00000;
                break;
            case 2:
                r |= 0x8800;
                break;
            case 3:
                r |= 0x940;
                if (d == 1)
                    r |= 0x2004000;
                if (e == 1)
                    r |= 0x4000000;
                break;
            }
            break;
        }
        if (b == 2) {
            r = 0x40020;
            if (a == 3)
                r = 0x40030;
        }
        if (b == 8) {
            r = 0x1020;
            if (a == 3)
                r = 0x1030;
        }
    }
    return r;
}

int fn_80045348(int a, int b)
{
    if (a != 0 || b == -1)
        return 0;
    if (b == 0)
        return 1;
    if ((unsigned)(b - 1) <= 1)
        return 2;
    return 4;
}

struct Unk80045388_Pos {
    char pad0[0x3F4];
    float m3F4;
};
struct Unk80045388_Outer {
    char pad0[0x3B8];
    int m3B8;
};
struct Unk80045388_Mid {
    char pad0[0x6CC];
    Unk80045388_Pos* m6CC;
    char pad6D0[0x700 - 0x6D0];
    Unk80045388_Outer* m700;
};
struct Unk80045388_V {
    float x;
    float y;
    float z;
};
extern "C" void fn_8018CA5C(Unk80045388_Pos* p, float* a, float* b, float* c);
extern "C" float fn_8018CAF0(Unk80045388_Pos* p);
extern "C" float atan2f(float y, float x);
extern "C" int fn_801DC1CC(int h, int* out, float* in);
extern "C" float fn_80248450(int h, int* out, int a, int b);
extern const float lbl_805A8E88;
extern const float lbl_805A8E8C;
extern const float lbl_806177F0;
extern const float lbl_806177F4;
extern const float lbl_806177F8;
extern const float lbl_806177FC;

/* The third int (r5) is unused; the caller declares the parameters as (a, b, c, d, e, f, g, h, i).
 * atan2f is retail's name for 0x80410CE8. `r = r | (flag | 2)` keeps r above d in the register allocation. */
extern "C" int fn_80045388(int a, int b, int unused, int c, int d, Unk80045388_Mid* e, Unk80045388_V* f, Unk80045388_V* g, Unk80045388_V* h)
{
    int r = 0;
    Unk80045388_Pos* pos = e->m6CC;
    float s0;
    float s1;
    float s2;
    fn_8018CA5C(pos, &s0, &s1, &s2);
    s0 = s0 * lbl_805A8E88;
    if (c == 0 || d == 8 || (d == 7 && a <= 1)) {
        float p_base = lbl_806177F0;
        float p0;
        float p1;
        float p3 = lbl_806177F8;
        if (!(lbl_806177FC >= lbl_806177F4)) {
            p0 = lbl_806177FC;
            p1 = lbl_806177F4;
        } else {
            p0 = lbl_806177F4;
            p1 = lbl_806177FC;
        }
        float th;
        if (!(s0 >= p0)) {
            th = (p0 - p_base) * lbl_805A8E8C;
            if (!(s0 - p_base <= th) && !(p0 - s0 <= th))
                r |= 0xC;
        } else if (!(s0 >= p1)) {
            th = (p1 - p0) * lbl_805A8E8C;
            if (!(s0 - p0 <= th) && !(p1 - s0 <= th))
                r |= 0x14;
        } else {
            th = (p3 - p1) * lbl_805A8E8C;
            if (!(s0 - p1 <= th) && !(p3 - s0 <= th))
                r |= 0x24;
        }
    } else if ((c == 2 && b > 1) || (c == 1 && a > 0)) {
        int flag = 0;
        float a1 = atan2f(f->x, f->z) * lbl_805A8E88;
        float a2 = atan2f(g->x, g->z) * lbl_805A8E88;
        float a3 = atan2f(h->x, h->z) * lbl_805A8E88;
        float th;
        if (!(a1 < s0) && !(s0 < a2)) {
            th = (a1 - a2) * lbl_805A8E8C;
            if (!(s0 - a2 <= th))
                {
                    int g = (a1 - s0) > th;
                    flag = g << 7;
                }
        } else if (!(a2 < s0) && !(s0 < a3)) {
            th = (a2 - a3) * lbl_805A8E8C;
            if (!(s0 - a3 <= th) && !(a2 - s0 <= th))
                flag = 0x40;
        }
        int buf[4];
        int hnd = fn_801DC1CC(e->m700->m3B8, buf, &th);
        float base = fn_8018CAF0(pos);
        if (flag != 0 && hnd != 0) {
            float q = fn_80248450(hnd, buf, 3, 9);
            if (!(q <= base - pos->m3F4)) {
                r = r | (flag | 2);
                if (a == 3) {
                    r |= 1;
                    if (r & 0x80)
                        r |= 0x200;
                    else if (r & 0x40)
                        r |= 0x100;
                }
            }
        }
    }
    return r;
}

int fn_8004570C(unsigned a)
{
    int r = 2;
    if (a == 0)
        r = 1;
    else if (a <= 30)
        r <<= a - 1;
    else
        r = 0;
    return r;
}

int fn_80045740(unsigned a)
{
    int r = 2;
    if (a == 0)
        r = 1;
    else if (a <= 30)
        r <<= a - 1;
    else
        r = 0;
    return r;
}

int fn_80045774(unsigned a)
{
    int r = 0;
    if (a > 10)
        r = 0x400;
    else if (a != 0)
        r = 1 << (a - 1);
    return r;
}

int fn_800457A4(unsigned a)
{
    return a > 1 ? 1 : 2;
}

int fn_800457B8(unsigned a)
{
    unsigned t = a - 1;
    int r = 0;
    if (t <= 19) {
        r = 1 << t;
        if (a > 6)
            return r | 0x100000;
    }
    return r;
}

int fn_800457E4(int a)
{
    switch (a) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 8;
    case 4:
        return 0x10;
    case 5:
        return 0x20;
    case 6:
        return 0x40;
    case 7:
        return 0x80;
    case 8:
        return 0x100;
    default:
        return 0;
    }
}

int fn_8004588C(int a)
{
    int r = 0;
    if ((unsigned)(a - 1) <= 19)
        r = 1 << a;
    return r;
}

int fn_800458AC(unsigned a)
{
    return a > 1 ? 1 : 2;
}

/* near-miss: last arm ("a >= 0.75f ? 1 : 2") comes out with the li hoisted and bns instead of
 * bso (23 vs 24 insns); ~10 spellings tried */
int fn_800458C0(float a)
{
    int r = 0;
    if (!(a < 0.0f)) {
        if (!(a > 0.4f))
            return 4;
        if (!(a >= 0.75f))
            return 2;
        r = 1;
    }
    return r;
}

int fn_80045920(int a)
{
    return a != 1 ? 2 : 1;
}

int fn_80045934(int a, int b)
{
    int r;
    if (b > 0x59)
        r = 1;
    else if (b > 0x54)
        r = 2;
    else
        r = 4;
    if (b > 0x63)
        return r | 8;
    if (b == 0x63)
        return r | 0x100;
    if (b == 0x62)
        return r | 0x80;
    if (b == 0x61)
        return r | 0x40;
    if (b == 0x60)
        return r | 0x20;
    if (b == 0x5F)
        return r | 0x10;
    return r;
}

/* near-miss: ~49 slots differ; the two 128-byte sum loops hoist the side base differently
 * (retail reloads C->m14 after the first loop) */
int fn_800459B0(Unk80044C10_A* o, unsigned a, unsigned b)
{
    Unk80044C10_B* tb = o->m44C;
    int s708 = o->m708;
    int side = 0;
    Unk80044C10_C* tc = tb->m6F8;
    int s460 = o->m460;
    int s704 = o->m704;
    int s458 = o->m458;
    if (tc->m14->m1CD0 != 0)
        side = 1;
    Unk80044C10_A* other = fn_801A4B34(tb);
    int r = 0;
    if (s708 == side) {
        if ((unsigned)(s458 - 10) <= 2)
            r = 0x800;
        else if (other->m460 == 9)
            r = 0x200;
        else if (other == o)
            r = 0x1000;
    } else if (s460 != 0) {
        r = fn_80043B78(s460);
    } else {
        int found = 0;
        int i = 0;
        r = 0x400;
        int oi = tb->m6F8->m14->m1CD0 == 0;
        Unk80044C10_Side* s = &tc->m14->sides[oi];
        for (i = 0; i < s->m54; i++) {
            if (s704 == s->m3E8[s->m50[(unsigned char)i]].m0) {
                found = 1;
                break;
            }
        }
        if (found == 1) {
            float ratio = (float)b / (float)a;
            int sum0 = 0;
            Unk80044C10_C* c2 = tb->m6F8;
            int oj = c2->m14->m1CD0 == 0;
            int j;
            for (j = 0; j < 0x80; j++)
                sum0 += c2->m14->sides[oj].m1B4[(unsigned char)j];
            int sum1 = 0;
            for (j = 0; j < 0x80; j++)
                sum1 += c2->m14->sides[side].m1B4[(unsigned char)j];
            if (!(ratio <= 0.67f) && sum0 > sum1 && sum0 - sum1 <= 3)
                r = 0x2000;
        }
    }
    return r;
}

int fn_80045BD8(Unk80044C10_A* o)
{
    Unk80044C10_B* tb = o->m44C;
    int s708 = o->m708;
    Unk80044C10_A* other = fn_801A4B34(tb);
    int side = 0;
    if (tb->m6F8->m14->m1CD0 != 0)
        side = 1;
    int r = 0;
    if (s708 == side) {
        if (other == o)
            r = fn_80043650(o->vslot24());
    } else if (o->m460 == 0) {
        r = fn_80043650(o->vslot22());
    }
    return r;
}
