/*
 * Database overlay code, .database_codeoverlay 0x80565FD4-0x8056A248 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"

/* Calendar record passed by value to fn_80329E74 (month, day, year); see db_8053967C.h. */
struct Db80565FD4_Date {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    Db80565FD4_Date() {}
};
extern "C" int fn_80329E74(Db80565FD4_Date d);
extern "C" int fn_8032A394(int a, int b);

extern "C" void fn_80567B58(int a, int b, int c);
extern "C" int fn_80568D64(Db80565CDC_S* s, int a, int b, int c);
extern "C" int fn_80566570(Db80565CDC_S* s);
extern "C" int fn_80568524(Db80565CDC_S* s, int a, int b);
extern "C" int fn_80568748(Db80565CDC_S* s, int a, int b);
extern "C" int fn_80568940(Db80565CDC_S* s, int a, int b);
extern "C" int fn_80568B40(Db80565CDC_S* s, int a, int b);
extern "C" void fn_80569228(Db80565CDC_S* s, int v);
extern "C" void fn_80569634(Db80565CDC_S* s, int v);
extern "C" void fn_805697A0(Db80565CDC_S* s, int v);
extern "C" void fn_80569984(Db80565CDC_S* s, int v);
extern "C" void fn_8056792C(int a, int b, int c);

inline int KeyAt(Unk8052B978_Tbl* t, int i)
{
    return *(unsigned short*)((char*)t->m8 + i * 0x1C);
}

extern unsigned char lbl_80692EF4[];
extern unsigned char lbl_80692EF8[];

struct Db805683AC_S : Db80565CDC_S {
    int m18_;
    int m1C_;
    int m20_;
};

#include "game/clampiter.h"
extern Unk80538DD8_G* lbl_80619948;
extern "C" int fn_800A3AF4(Unk80538DD8_G* g);
extern "C" int fn_800A3B38(Unk80538DD8_G* g);
extern "C" int fn_800A3B7C(Unk80538DD8_G* g);
extern "C" int fn_805656A0(Db80565CDC_S* s, int a);
extern "C" int fn_805658F8(Db80565CDC_S* s, int a);
extern "C" int fn_80565A50(Db80565CDC_S* s, int a);
extern "C" void fn_8056746C(int a, int b, int k);
extern "C" void fn_80567600(int a, int b, int c);
extern "C" void fn_80567B14(int a, int b, int k);
extern "C" void fn_80567D20(int a, int b, int c);

extern "C" int fn_800A3AB0(Unk80538DD8_G* g);
extern "C" int fn_80565448(Db80565CDC_S* s, int a);
/* forward declarations (definitions are in address order) */
extern "C" int fn_80566520(Db80565CDC_S* s);
extern "C" int fn_80566674(Db80565CDC_S* s);
extern "C" int fn_8056681C(Db80565CDC_S* s, int v);
extern "C" int fn_805668A4(Db80565CDC_S* s, int y);
extern "C" int fn_805668F0(Db80565CDC_S* s, int y);
extern "C" void fn_80567338(Db80565CDC_S* s, int k, int v);
extern "C" void fn_805678D8(int a, int b, int k);
extern "C" void fn_80567AD4(int a, int b, int c);
extern "C" void fn_80567AF4(int a, int b, int c);
extern "C" void fn_80567B14(int a, int b, int c);
extern "C" int fn_805683AC(Db805683AC_S* s, int a, int k);
extern "C" int fn_80568464(Db80565CDC_S* s, int a, int b, int k);
extern "C" int fn_80568EA8(Db80565CDC_S* self);
extern "C" int fn_80568F5C(Db80565CDC_S* self);
extern "C" int fn_80569000(Db80565CDC_S* self);
extern "C" int fn_80569094(Db80565CDC_S* self);
extern "C" int fn_8056A1DC(void* l, int k);

extern "C" DB_OVERLAY int fn_80566520(Db80565CDC_S* s)
{
    int a = fn_80566570(s);
    int b = fn_80566674(s);
    return a == 0 && b == 0;
}

extern "C" DB_OVERLAY int fn_80566674(Db80565CDC_S* s)
{
    Unk8052B978_Tbl* tb = s->m28;
    int key = KeyAt(tb, tb->m4 - 1);
    Unk80329FA0_Out o = fn_80329FA0(key);
    return key < fn_805668F0(s, o.m2);
}

/* near-miss: ours keeps &out in a saved register; retail forms the frame address per use (35 vs 34 insns). */
extern "C" DB_OVERLAY int fn_8056681C(Db80565CDC_S* s, int v)
{
    Unk80329FA0_Out o = fn_80329FA0(v);
    int base = fn_805668A4(s, o.m2);
    if (v < base)
        return -1;
    int d = v - base;
    if (d > 6) {
        if (d > 13) {
            if (d > 20)
                return 3;
            return 2;
        }
        return 1;
    }
    return 0;
}

/* near-miss: the stores and calls match; retail builds the by-value date in place (frame word at 8, address
 * in r9) while ours fills a local at 12 and copies it into the argument slot (20 vs 19 insns). */
extern "C" DB_OVERLAY int fn_805668A4(Db80565CDC_S* s, int y)
{
    Db80565FD4_Date d;
    unsigned char a = lbl_80692EF4[0];
    unsigned char b = lbl_80692EF4[1];
    d.m0 = a;
    d.m2 = y;
    d.m1 = b;
    int r = fn_80329E74(d);
    return fn_8032A394(r, 0);
}

extern "C" DB_OVERLAY int fn_805668F0(Db80565CDC_S* s, int y)
{
    Db80565FD4_Date d;
    d.m0 = lbl_80692EF8[0];
    d.m2 = y;
    d.m1 = lbl_80692EF8[1];
    return fn_8032A394(fn_80329E74(d), 0);
}

extern "C" DB_OVERLAY void fn_80567338(Db80565CDC_S* s, int k, int v)
{
    switch (k) {
    case 0:
        fn_80569228(s, v);
        break;
    case 1:
        fn_80569634(s, v);
        break;
    case 2:
        fn_805697A0(s, v);
        break;
    case 3:
        fn_80569984(s, v);
        break;
    }
}

extern "C" DB_OVERLAY void fn_805678D8(int a, int b, int k)
{
    if ((unsigned)(k - 13) <= 1)
        fn_8056792C(a, b, k);
    else if ((unsigned)(k - 15) <= 1)
        fn_80567AF4(a, b, k);
    else if ((unsigned)(k - 17) <= 1)
        fn_80567AD4(a, b, k);
}

extern "C" DB_OVERLAY void fn_80567AD4(int a, int b, int c)
{
    fn_80567B58(a, b, c);
}

extern "C" DB_OVERLAY void fn_80567AF4(int a, int b, int c)
{
    fn_80567B58(a, b, c);
}

extern "C" DB_OVERLAY void fn_80567B14(int a, int b, int c)
{
    fn_80567B58(a, b, c);
    fn_80567D20(a, b, c);
}

extern "C" DB_OVERLAY int fn_805683AC(Db805683AC_S* s, int a, int k)
{
    if (fn_80566570(s) == 0)
        return 0;
    int lim = 0;
    switch (k) {
    case 0:
        lim = s->m8 * 4 + s->mC * 2;
        break;
    case 1:
        lim = s->m14 * 4;
        break;
    case 2:
        lim = *(int*)((char*)s + 0x18) * 6;
        break;
    case 3:
        lim = *(int*)((char*)s + 0x20) * 0x12;
        break;
    }
    return (unsigned)a >= (unsigned)lim;
}

extern "C" DB_OVERLAY int fn_80568464(Db80565CDC_S* s, int a, int b, int k)
{
    if (fn_80566570(s) != 0) {
        switch (k) {
        case 0:
            return fn_80568524(s, a, b);
        case 1:
            return fn_80568748(s, a, b);
        case 2:
            return fn_80568940(s, a, b);
        case 3:
            return fn_80568B40(s, a, b);
        }
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_80568EA8(Db80565CDC_S* self)
{
    int g = fn_800A3AB0(lbl_80619948);
    if (fn_80565448(self, g) == 1)
        return 0;
    Unk8006A138_It<25> it(0);
    int k = 0;
    do {
        fn_8056746C((int)self, g, k);
        k = it.Next();
    } while (k <= 5);
    fn_80567600((int)self, g, 0);
    fn_80567600((int)self, g, 1);
    return 1;
}

extern "C" DB_OVERLAY int fn_80568F5C(Db80565CDC_S* self)
{
    int g = fn_800A3AF4(lbl_80619948);
    if (fn_805656A0(self, g) == 1)
        return 0;
    Unk8006A138_It<25> it(6);
    int k = 6;
    do {
        fn_8056746C((int)self, g, k);
        k = it.Next();
    } while (k <= 12);
    fn_80567600((int)self, g, 2);
    return 1;
}

extern "C" DB_OVERLAY int fn_80569000(Db80565CDC_S* self)
{
    int g = fn_800A3B38(lbl_80619948);
    if (fn_805658F8(self, g) == 1)
        return 0;
    Unk8006A138_It<25> it(13);
    int k = 13;
    do {
        fn_805678D8((int)self, g, k);
        k = it.Next();
    } while (k <= 18);
    return 1;
}

extern "C" DB_OVERLAY int fn_80569094(Db80565CDC_S* self)
{
    int g = fn_800A3B7C(lbl_80619948);
    if (fn_80565A50(self, g) == 1)
        return 0;
    Unk8006A138_It<25> it(19);
    int k = 19;
    do {
        fn_80567B14((int)self, g, k);
        k = it.Next();
    } while (k <= 24);
    return 1;
}

extern "C" DB_OVERLAY int fn_8056A1DC(void* l, int k)
{
    int r = 1;
    switch (k) {
    case 0:
        r = 1;
        break;
    case 1:
        r = 3;
        break;
    case 2:
    case 3:
        r = 5;
        break;
    case 4:
        r = 7;
        break;
    }
    return r;
}
