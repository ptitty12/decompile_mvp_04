/*
 * Database overlay code, .database_codeoverlay 0x80563954-0x80565FD4 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"
#include "game/clampiter.h"
/* Source object (lbl_8061930C): four ints from +0xC copied into the singleton (fn_80564D40). */
struct Db80564D40_Src {
    char pad0[0xC];
    int mC[4];
};
/* Singleton (lbl_80622D88 holds it, lbl_80622D8C counts it; dtor fn_80564E28): m0 source, m4 flag,
 * constants at +8..+0x24, four ints at +0x28 (fn_80564D40). */
struct Db80564D40_S {
    Db80564D40_Src* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28[4];
};
extern Db80564D40_Src* lbl_8061930C;
/* lbl_80619948 as read by fn_805652E8: only the table-set pointer at +0x28. */
struct Db80619948_G {
    char pad0[0x28];
    Unk8052B978_Tbl** m28;
};
extern Db80619948_G* lbl_80619948;
extern "C" int fn_800B548C();
int fn_80075CC0(int a);
int fn_80076104(int a, int b, int c);
int fn_80084408(int a);
int fn_80084458(int a);

extern "C" int fn_80565D48(Db80565CDC_S* s);
extern "C" int fn_80565DDC(Db80565CDC_S* s);
extern "C" int fn_8056AC74(Unk8052B978_Tbl** t, Unk8052B978_Tbl* tb, int idx);
extern "C" int fn_80565E9C(Db80565CDC_S* s);
extern "C" int fn_80568D64(Db80565CDC_S* s, int a, int b, int c);
extern "C" float fn_80563954(float f);
extern "C" Unk8007F198_S12 fn_8052BD58(Unk8052B978_Tbl* t);
extern "C" void fn_805650DC(Db80565CDC_S* s, int y);
extern "C" int fn_8056516C(Db80565CDC_S* s, int y);
extern "C" void* fn_800B555C();
extern "C" int fn_800B57EC(void* p);
extern "C" int fn_80565448(Db80565CDC_S* s, int a);
extern "C" int fn_805656A0(Db80565CDC_S* s, int a);
extern "C" int fn_805658F8(Db80565CDC_S* s, int a);
extern "C" int fn_80565A50(Db80565CDC_S* s, int a);
extern "C" void fn_80377408(void* p);
extern float lbl_805FF864;
extern float lbl_805FF868;
extern float lbl_805FF86C;
extern float lbl_805FF870;
extern float lbl_805FF874;
extern float lbl_805FF8A4;
extern float lbl_805FF914;
extern int lbl_80622D88;
extern int lbl_80622D8C;
struct Db80563F0C_S {
    int m0;
    float m4;
    float m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
};

extern "C" int fn_80555EB0(int k, int i);
extern "C" int fn_80555F18(int k, int i);

extern "C" void fn_8052BA70(Unk8052B978_Tbl* self);
extern "C" void fn_8052BBF8(Unk8052B978_Tbl* self, int idx);
extern "C" void fn_8052BC4C(Unk8052B978_Tbl* self, int v);
extern "C" int fn_805668A4(Db80565CDC_S* self, int y);
void fn_802B8D74();
void fn_802B8DDC();

/* near-miss: 17 slots, register allocation of the loop (retail keeps the index in r31 starting at 4 and self in r28) */
inline Unk8052B978_Tbl* Db805650DC_At(Db80565CDC_S* s, int off)
{
    char* b = (char*)s + 0x28;
    return *(Unk8052B978_Tbl**)(b + off);
}

/* forward declarations (definitions are in address order) */
extern "C" int fn_80563B4C(float f);
extern "C" float fn_80563BA0(int a);
extern "C" void fn_80563F0C(Db80563F0C_S* s);
extern "C" void fn_80564A98(Db80563F0C_S* s);
extern "C" void fn_80564E28(void* self, int chrg);
extern "C" void fn_80564E6C(Db80565CDC_S* s);
extern "C" void fn_8056503C(Db80565CDC_S* s);
extern "C" void fn_80565090(Db80565CDC_S* s);
extern "C" void fn_805650DC(Db80565CDC_S* self, int y);
extern "C" int fn_805653B4(Db80565CDC_S* s, int a, int b, int c, int d);
extern "C" int fn_80565BFC(Db80565CDC_S* s);
extern "C" int fn_80565C70(Db80565CDC_S* s, int k);
extern "C" int fn_80565CDC(Db80565CDC_S* s);
extern "C" int fn_80565D48(Db80565CDC_S* self);
extern "C" int fn_80565DDC(Db80565CDC_S* self);
extern "C" int fn_80565E9C(Db80565CDC_S* self);

extern "C" DB_OVERLAY int fn_80563B4C(float f)
{
    volatile float pad;
    float r = fn_80563954(f);
    return (int)((r - lbl_805FF864) / lbl_805FF868);
}

extern "C" DB_OVERLAY float fn_80563BA0(int a)
{
    float r;
    if (a == 0 || a == 10)
        r = lbl_805FF86C;
    else if ((unsigned)(a - 1) <= 4)
        r = lbl_805FF870;
    else
        r = lbl_805FF874;
    return r;
}

/* near-miss: retail's ctor-shaped bodies copy r3 (mr r9,r3) and load the float in r11 (one more insn).
 * Tried an inline method and a placement-new constructor. */
extern "C" DB_OVERLAY void fn_80563F0C(Db80563F0C_S* s)
{
    s->m0 = 0;
    s->m1C = 0;
    s->m8 = s->m4 = lbl_805FF8A4;
    s->mC = 0;
    s->m10 = 0;
    s->m18 = 0;
}

/* near-miss: same (8 vs 9 insns). */
extern "C" DB_OVERLAY void fn_80564A98(Db80563F0C_S* s)
{
    s->m0 = 0;
    s->m8 = lbl_805FF914;
    s->mC = 0;
    s->m4 = lbl_805FF914;
}

extern "C" DB_OVERLAY Db80564D40_S* fn_80564D40(Db80564D40_S* s)
{
    if (lbl_80622D88 != 0) {
        if (s != 0)
            fn_80564E28(s, 3);
    } else {
        lbl_80622D88 = (int)s;
        lbl_80622D8C = lbl_80622D8C + 1;
        s->m0 = lbl_8061930C;
        Unk8006A138_It<3> it(0);
        int k = 0;
        do {
            s->m28[k] = s->m0->mC[k];
            k = it.Next();
        } while (k <= 3);
        s->m4 = 1;
        s->m20 = 3;
        s->m8 = 5;
        s->mC = 7;
        s->m10 = 7;
        s->m14 = 5;
        s->m18 = 5;
        s->m24 = 5;
        s->m1C = 7;
    }
    return s;
}

extern "C" DB_OVERLAY void fn_80564E28(void* self, int chrg)
{
    lbl_80622D88 = 0;
    lbl_80622D8C = lbl_80622D8C - 1;
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_80564E6C(Db80565CDC_S* s)
{
    if (fn_800B57EC(fn_800B555C()) == 1)
        fn_8056516C(s, 0x7D5);
}

/* near-miss: the 12-byte and 4-byte results are read straight from the frame in retail; ours forms their
 * addresses in saved registers (22 vs 21 insns). */
extern "C" DB_OVERLAY void fn_8056503C(Db80565CDC_S* s)
{
    Unk8007F198_S12 t = fn_8052BD58(s->m28);
    Unk80329FA0_Out o = fn_80329FA0(t.w0);
    fn_805650DC(s, o.m2 + 1);
}

/* near-miss: as fn_8056503C (20 vs 19 insns). */
extern "C" DB_OVERLAY void fn_80565090(Db80565CDC_S* s)
{
    Unk80329FA0_Out o = fn_80329FA0(*(unsigned short*)s->m28->m8);
    fn_8056516C(s, o.m2);
}

extern "C" DB_OVERLAY void fn_805650DC(Db80565CDC_S* self, int y)
{
    fn_802B8D74();
    int i;
    for (i = 0; i < 3; i++)
        fn_8052BA70(Db805650DC_At(self, i * 4 + 4));
    Unk8052B978_Tbl* t = *(Unk8052B978_Tbl**)((char*)self + 0x28);
    int h = fn_805668A4(self, (unsigned short)y);
    y -= 0x7D5;
    fn_8052BBF8(t, y % 2);
    fn_8052BC4C(t, h);
    fn_802B8DDC();
}

extern "C" DB_OVERLAY void fn_805652E8(Unk8007B2B0_Screen** pp, Unk8052B978_Tbl* tb, int a)
{
    unsigned i = 0;
    fn_80076104(fn_80075CC0(a), 0, 0);
    int k = fn_800B548C();
    int g = (*pp)->fn_8007B8C4(0, k);
    int v1 = fn_80084408(g);
    int v2 = fn_80084458(g);
    unsigned n = tb->m4;
    Unk8052B978_Tbl** t = lbl_80619948->m28;
    for (; i < n; i++) {
        if (fn_8056AC74(t, tb, i) == 1) {
            *(int*)((char*)tb->m8 + i * 0x1C + 4) = v1;
            *(int*)((char*)tb->m8 + i * 0x1C + 0x10) = v2;
        }
    }
}

extern "C" DB_OVERLAY int fn_805653B4(Db80565CDC_S* s, int a, int b, int c, int d)
{
    int r0 = fn_80565448(s, a);
    int r1 = fn_805656A0(s, b);
    int r2 = fn_805658F8(s, c);
    int r3 = fn_80565A50(s, d);
    int ok = 0;
    if (r0 && r1 && r2 && r3)
        ok = 1;
    return ok;
}

extern "C" DB_OVERLAY int fn_80565BFC(Db80565CDC_S* s)
{
    Unk8006A138_It<3> it(0);
    int k = 0;
    do {
        if (fn_80565C70(s, k) == 0)
            return 0;
        k = it.Next();
    } while (k <= 3);
    return 1;
}

extern "C" DB_OVERLAY int fn_80565C70(Db80565CDC_S* s, int k)
{
    switch (k) {
    case 0:
        return fn_80565CDC(s);
    case 1:
        return fn_80565D48(s);
    case 2:
        return fn_80565DDC(s);
    case 3:
        return fn_80565E9C(s);
    }
    return 1;
}

extern "C" DB_OVERLAY int fn_80565CDC(Db80565CDC_S* s)
{
    int a = s->m8 * 4 + s->mC * 2;
    int b = s->m10;
    if (s->m28->m4 >= (unsigned)(a + b)) {
        if (fn_80568D64(s, a, b, 0) != 0)
            return 1;
        return 0;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_80565D48(Db80565CDC_S* self)
{
    int n = self->m14;
    int res = 0;
    int c = n * 4;
    if (self->m2C->m4 >= (unsigned)(c + (n + n))) {
        int a = fn_80568D64(self, c, n, 1);
        int b = fn_80568D64(self, c | 1, n, 1);
        int t = 0;
        if (a != 0 && b != 0)
            t = 1;
        res = t;
    }
    return res;
}

extern "C" DB_OVERLAY int fn_80565DDC(Db80565CDC_S* self)
{
    int n = *(int*)((char*)self + 0x18);
    int k = *(int*)((char*)self + 0x1C);
    int res = 0;
    int c = (n + n + n) * 2;
    if ((*(Unk8052B978_Tbl**)((char*)self + 0x30))->m4 >= (unsigned)(c + (n + n + k))) {
        int a = fn_80568D64(self, c, n, 2);
        int b = fn_80568D64(self, c + 1, n, 2);
        int d = fn_80568D64(self, c + 2, k, 2);
        int t = 0;
        if (a != 0 && b != 0 && d != 0)
            t = 1;
        res = t;
    }
    return res;
}

extern "C" DB_OVERLAY int fn_80565E9C(Db80565CDC_S* self)
{
    int p0 = fn_80555EB0(0, 3) * fn_80555F18(0, 7);
    int p1 = fn_80555EB0(1, 3) * fn_80555F18(1, 7);
    int s = p0 + p1;
    int p2 = fn_80555EB0(2, 3) * fn_80555F18(2, 7);
    int t = s + p2;
    int res = 0;
    if ((*(Unk8052B978_Tbl**)((char*)self + 0x34))->m4 >= (unsigned)t) {
        int a = fn_80568D64(self, s, fn_80555F18(2, 7), 3);
        int b = fn_80568D64(self, s + 1, fn_80555F18(2, 8), 3);
        int c = fn_80568D64(self, s + 2, fn_80555F18(2, 9), 3);
        int r = 0;
        if (a != 0 && b != 0 && c != 0)
            r = 1;
        res = r;
    }
    return res;
}
