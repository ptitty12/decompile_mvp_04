/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80037250-0x80039B04 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80037250.h"

/*
 * near-miss (all twelve CSV row loaders, fn_80037250 .. fn_80038424): same
 * instruction count (+-1) as retail; retail keeps the address of the cursor
 * local in its own callee-saved register (r31) and the length (&n) in r30, the
 * build here recomputes &cur and swaps the two. Tried: declaration order,
 * pointer locals, a struct holding both.
 */
extern "C" void fn_80037250(char* buf, int out, const char* text)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800361D8(buf, &cur, &n, &v1, 0, 3, 0x2C)
                || !fn_80036628(buf, &v2, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + v0 * 0x40 + v1 * 0x10 + v2 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_800373A4(char* buf, int out, const char* text, int lo, int hi)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2, v3;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800361D8(buf, &cur, &n, &v1, lo, hi, 0x2C)
                || !fn_800368A8(buf, &v2, &cur, &n)
                || !fn_80036628(buf, &v3, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + v0 * 0x280 + v1 * 0xA0 + v2 * 0x10 + v3 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_80037530(char* buf, int out, const char* text, int lo, int hi)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2, v3, v4;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800361D8(buf, &cur, &n, &v1, lo, hi, 0x2C)
                || !fn_800362B4(buf, &v2, &cur, &n)
                || !fn_800368A8(buf, &v3, &cur, &n)
                || !fn_80036628(buf, &v4, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + v0 * 0x500 + v1 * 0x140 + v2 * 0xA0 + v3 * 0x10 + v4 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_800376EC(char* buf, int out, const char* text)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800366A8(buf, &v1, &cur, &n)
                || !fn_80036628(buf, &v2, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + v0 * 0x30 + v1 * 0x10 + v2 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_80037834(char* buf, int out, const char* text)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2, v3;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800367A8(buf, &v1, &cur, &n)
                || !fn_80036728(buf, &v2, &cur, &n)
                || !fn_800362B4(buf, &v3, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + v0 * 0xC8 + v1 * 0x28 + v2 * 8 + v3 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_800379A4(char* buf, int out, const char* text)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2, v3, v4;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800367A8(buf, &v1, &cur, &n)
                || !fn_800366A8(buf, &v2, &cur, &n)
                || !fn_800362B4(buf, &v3, &cur, &n)
                || !fn_80036628(buf, &v4, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + v0 * 0x1E0 + v1 * 0x60 + (v2 << 5) + v3 * 0x10 + v4 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_80037B44(char* buf, int out, const char* text)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2, v3, v4, v5;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800367A8(buf, &v1, &cur, &n)
                || !fn_80036728(buf, &v2, &cur, &n)
                || !fn_800362B4(buf, &v3, &cur, &n)
                || !fn_800362B4(buf, &v4, &cur, &n)
                || !fn_80036628(buf, &v5, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + v0 * 0x640 + v1 * 0x140 + (v2 << 6) + (v3 << 5) + v4 * 0x10 + v5 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_80037D0C(char* buf, int out, const char* text)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2, v3, v4, v5;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_80036828(buf, &v1, &cur, &n)
                || !fn_800362B4(buf, &v2, &cur, &n)
                || !fn_800362B4(buf, &v3, &cur, &n)
                || !fn_800362B4(buf, &v4, &cur, &n)
                || !fn_80036628(buf, &v5, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + v0 * 0x280 + (v1 << 7) + (v2 << 6) + (v3 << 5) + v4 * 0x10 + v5 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_80037EE0(char* buf, int out, const char* text, int lo, int hi)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2, v3, v4, v5;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800361D8(buf, &cur, &n, &v1, lo, hi, 0x2C)
                || !fn_800362B4(buf, &v2, &cur, &n)
                || !fn_800368A8(buf, &v3, &cur, &n)
                || !fn_800362B4(buf, &v4, &cur, &n)
                || !fn_80036628(buf, &v5, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + v0 * 0xA00 + v1 * 0x280 + v2 * 0x140 + (v3 << 5) + v4 * 0x10 + v5 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_800380D4(char* buf, int out, const char* text, int lo, int hi)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2, v3, v4, v5;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800369A8(buf, &v1, &cur, &n)
                || !fn_800361D8(buf, &cur, &n, &v2, lo, hi, 0x2C)
                || !fn_800362B4(buf, &v3, &cur, &n)
                || !fn_80036928(buf, &v4, &cur, &n)
                || !fn_80036628(buf, &v5, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + v0 * 0x480 + v1 * 0x180 + v2 * 0x60 + v3 * 0x30 + v4 * 0x10 + v5 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_800382BC(char* buf, int out, const char* text, int lo, int hi)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800361D8(buf, &cur, &n, &v1, lo, hi, 0x2C)
                || (v1 -= 1, !fn_80036628(buf, &v2, &cur, &n)))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + (v0 << 6) + v1 * 0x10 + v2 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" void fn_80038424(char* buf, int out, const char* text)
{
    unsigned int n = 0;
    const char* start = fn_802B9300(text, 0x500, 0xB, &n);
    const char* cur = start;
    const char* end = start + n;
    if (n != 0) {
        int v0, v1, v2;
        fn_803792AC(&cur, &n);
        while (cur != end && n > 1) {
            if (!fn_800365A4(buf, &v0, &cur, &n)
                || !fn_800362B4(buf, &v1, &cur, &n)
                || !fn_80036628(buf, &v2, &cur, &n))
                fn_803792AC(&cur, &n);
            else if (!fn_8003641C(buf, (unsigned char*)(out + (v0 << 5) + v1 * 0x10 + v2 * 4), &cur, &n))
                fn_803792AC(&cur, &n);
        }
    }
    fn_802B961C(start, 0xB);
}

extern "C" Unk80038570* fn_80038EB4()
{
    if (lbl_80616F0C == 0)
        lbl_80616F0C = fn_80038570(new (0) Unk80038570);
    return lbl_80616F0C;
}

Unk80038570::~Unk80038570()
{
}

extern "C" void fn_80038F28(int out)
{
    Unk800360F4 b;
    fn_800360F4(&b);
    fn_802B9098(lbl_80616EDC);
    fn_800370B8(b.buf, out, lbl_80616E9C, 1, 3, 0, 2);
    fn_800370B8(b.buf, out + 0x180, lbl_80616E8C, 0, 3, 1, 2);
    fn_800370B8(b.buf, out + 0x300, lbl_80616E90, 0, 3, 1, 2);
    fn_80037250(b.buf, out + 0x500, lbl_80616EA0);
    fn_80037250(b.buf, out + 0x480, lbl_80616E88);
    fn_800373A4(b.buf, out + 0x580, lbl_80616E94, 1, 3);
    fn_800373A4(b.buf, out + 0xA80, lbl_80616E98, 1, 3);
    fn_80037530(b.buf, out + 0xF80, lbl_80616EB0, 1, 3);
    fn_800376EC(b.buf, out + 0x1980, lbl_80616EB4);
    fn_80037834(b.buf, out + 0x19E0, lbl_80616EB8);
    fn_800379A4(b.buf, out + 0x1B70, lbl_80616EA8);
    fn_80037B44(b.buf, out + 0x1F30, lbl_80616EA4);
    fn_80037D0C(b.buf, out + 0x2BB0, lbl_80616EBC);
    fn_80037EE0(b.buf, out + 0x30B0, lbl_80616EAC, 1, 3);
    fn_800380D4(b.buf, out + 0x44B0, lbl_80616EC0, 1, 3);
    fn_800382BC(b.buf, out + 0x4DB0, lbl_80616EC4, 1, 4);
    fn_80038424(b.buf, out + 0x4E30, lbl_80616EC8);
    fn_80038424(b.buf, out + 0x4E70, lbl_80616ECC);
    fn_80036F14(b.buf, out + 0x515C, lbl_80616ED8);
    fn_80036D70(b.buf, out + 0x5120, lbl_80616ED4);
    fn_80036BCC(b.buf, out + 0x4EB0, lbl_80616ED0);
    fn_802B90EC();
    fn_80036108(&b, 2);
}

extern "C" int fn_80039178(Unk80038570* s)
{
    s->m52B4 = 1;
    s->m52B0 = 6;
    fn_80039E94();
    fn_80039C20(s);
    fn_80039F04(s);
    int a = s->m52C8;
    int zero = 0;
    lbl_80616EFC = zero;
    lbl_80616F00 = 0xB;
    if (a > s->m52C0)
        s->m52C0 = a;
    int v = s->m52C8;
    if (v < 0)
        v = 0;
    else if (v > 0x3E8)
        v = 0x3E8;
    fn_803BA7C4(lbl_80687354, &v);
    return s->m52B4;
}

extern "C" void fn_8003922C(Unk80038570* s)
{
    if (lbl_80616F10 == 1) {
        for (int i = 0; i <= 7; i++)
            fn_800393B0(s, i);
    }
    fn_80039664(s);
    if (lbl_80616F0C != 0) {
        delete lbl_80616F0C;
        lbl_80616F0C = 0;
    }
}

extern "C" int fn_800392A8(Unk80038570* s, int i)
{
    if (s->m5288 == 0) {
        s->m528C[i] = -3;
    } else {
        if (s->m528C[i] < 0) {
            if (s->m52B4 == 1 || fn_80039178(s) == 1) {
                int r = fn_80039D38(s, i);
                if (r == 1) {
                    s->m528C[i] = r;
                    fn_80039988(s);
                }
            } else {
                s->m528C[i] = -2;
            }
        }
    }
    switch (s->m528C[i]) {
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

extern "C" void fn_800393B0(Unk80038570* s, int i)
{
    s->m528C[i] = -1;
    for (int j = 0; j < 2; j++) {
        if (lbl_80616EF0[j] != 0)
            lbl_80616EF0[j] = 0;
    }
    lbl_80616F04 = -1;
    fn_80039DBC(s, &lbl_80616F04);
    fn_80039988(s);
}

extern "C" void fn_80039434(Unk80038570* s)
{
    if (lbl_80616F10 == 1) {
        if (s->m52F0 != 0) {
            fn_80039F24();
        } else {
            int t = s->m52B0;
            if (t > 0) {
                int n = t - 1;
                s->m52B0 = n;
                if (n == 0) {
                    int hi = s->m52C0;
                    int lo = s->m52C8;
                    if (hi > lo) {
                        int d = hi - 2;
                        s->m52C0 = d;
                        if (d < lo)
                            s->m52C0 = lo;
                        if (s->m52C0 < 0)
                            s->m52C0 = n;
                        int v = s->m52C0;
                        if (v < 0)
                            v = n;
                        else if (v > 0x3E8)
                            v = 0x3E8;
                        fn_803BA7C4(lbl_80687354, &v);
                    }
                    s->m52B0 = 6;
                }
            }
        }
        if (lbl_80616F08 != 0) {
            int j;
            lbl_80616EEC = lbl_80616F08 - 1;
            for (j = 0; j <= lbl_80616F04; j++) {
                Unk80038570_Obj734* o = lbl_80616EF0[j];
                if (o != 0)
                    fn_80306AC0(o->m734, lbl_80616EEC);
            }
            lbl_80616EF8 = 10;
            return;
        }
        if (lbl_80616EF8 > 0) {
            int u = lbl_80616EF8 - 1;
            lbl_80616EF8 = u;
            if (u == 0)
                fn_80039C20(s);
        }
    }
}

extern "C" void fn_800395B0(Unk80038570* s, int a)
{
    if (lbl_80616F10 == 1) {
        if (s->m52B8 < 0) {
            fn_800398E4(s, 0.0f);
            if ((a == 3 || a == 6) && s->m52BC < 0)
                s->m52BC = fn_800412AC(fn_8004072C(), 0x47, 0, 0, 0, 0);
            s->m52B8 = fn_800412AC(fn_8004072C(), 0x41, 0, 0, 0, 0);
        }
        s->m52FC = a;
    }
}

extern "C" void fn_80039664(Unk80038570* s)
{
    s->m52B4 = 0;
    fn_80039988(s);
}

extern "C" void fn_8003968C(Unk80038570* s)
{
    fn_80039664(s);
    if (fn_80039178(s) == 1)
        fn_80039988(s);
}

extern "C" void fn_800396D0(Unk80038570* s, int a)
{
    int g = lbl_80616F10;
    if (g == 1) {
        if (s->m52B8 >= 0) {
            fn_8004181C(fn_8004072C(), 0x41, s->m52B8, 0, 0, 0, 0);
            int v = g;
            fn_803BA7C4(lbl_8068742C, &v);
            s->m52B8 = -1;
        }
        if (a != 0 && s->m52BC >= 0) {
            fn_8004181C(fn_8004072C(), 0x47, s->m52BC, 0, 0, 0, 0);
            s->m52BC = -1;
        }
    }
}

extern "C" void fn_80039790(Unk80038570* s, float f)
{
    if (lbl_80616F10 == 1 && !(f < 0.0f) && !(f > 1.0f)) {
        int t = (int)(f * 1000.0f);
        if (t > s->m52C0) {
            s->m52C0 = t;
            int v = t;
            if (v < 0)
                v = 0;
            else if (v > 0x3E8)
                v = 0x3E8;
            fn_803BA7C4(lbl_80687354, &v);
            s->m52B0 = 6;
        }
    }
}

extern "C" void fn_80039854(Unk80038570* s, int a, float f)
{
    if (lbl_80616F10 == 1) {
        int t = (int)(f * 1000.0f);
        s->m52C8 = t;
        if (a != 0) {
            s->m52C0 = t;
            int v = t;
            if (v < 0)
                v = 0;
            else if (v > 0x3E8)
                v = 0x3E8;
            fn_803BA7C4(lbl_80687354, &v);
        }
    }
}

extern "C" void fn_800398E4(Unk80038570* s, float f)
{
    if (lbl_80616F10 == 1 && !(f < 0.0f) && !(f > 1.0f)) {
        int t = (int)(f * 1000.0f);
        s->m52C4 = t;
        int v = t;
        if (v < 0)
            v = 0;
        else if (v > 0x3E8)
            v = 0x3E8;
        fn_803BA7C4(lbl_8068735C, &v);
    }
}

extern "C" void fn_80039988(Unk80038570* s)
{
    s->m52AC = -1;
    for (int i = 0; i <= 7; i++) {
        if (s->m528C[i] >= 0) {
            s->m52AC = 0;
            break;
        }
    }
    int* g = &lbl_80616F10;
    int v = 0;
    if (s->m5288 == 1 && s->m52B4 == 1 && s->m52AC >= 0)
        v = (((Unk80038570_Obj5D0*)fn_8004072C())->m5D0 == 1);
    *g = v;
}

extern "C" void fn_80039A3C(int a, unsigned int b, unsigned int c)
{
    if (lbl_80616F10 == 1) {
        if (a != 10) {
            fn_800412AC(fn_8004072C(), lbl_805B17A0[a].m4, b, 0, 0, 0);
            fn_80039B04(a, b);
        } else {
            unsigned int d = c;
            if (d > 0x258)
                d = 0x258;
            if (c == 0)
                d = 0x12C;
            fn_800412AC(fn_8004072C(), 0x3E, d, 0, 0, 0);
        }
        lbl_80616F00 = a;
        lbl_80616EFC = b;
    }
}
