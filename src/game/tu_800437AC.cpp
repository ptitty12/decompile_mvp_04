/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x800437AC-0x80044C10 only: every data object is extern by its lbl_ name.
 *
 * Sound-event helpers: id to bit-mask mappings plus the small state block at
 * 0x806E0270 (eighteen words) and the three two-word records at 0x806EF990,
 * 0x806EF998 and 0x806EF9A0.
 */
#include "game/tu_800437AC.h"
#include "game/tu_8003EF18.h"

void* fn_800B555C();
int fn_800B57EC(void* p);
int fn_8009E1D4(void* p, int a, int b);
int fn_800B5898(void* p);
int fn_800B55A8(void* p);
int fn_8006A1B4(void* p);
int fn_80046828(float f);
int fn_800467C0(float f);
int fn_80046964(float f);
int fn_80046924(float f);

extern int lbl_805B1CDC[2][2][2];
extern int lbl_806E0270[];
extern int lbl_806E027C;
extern Unk800437AC_Pair lbl_806EF990;
extern Unk800437AC_Pair lbl_806EF998;
extern Unk800437AC_Pair lbl_806EF9A0;
extern int lbl_806EF9A8;
extern int lbl_806EF9AC;
extern int lbl_806EF9B0;

int fn_80044B2C(int a);
int fn_80044A20(int a);
int fn_80044A78(int a);

/* Byte-sum loop shared with tu_8003EF18.cpp (see the note there). */
inline unsigned int Unk80043884_Sum(Unk8003FC18_Entry* e)
{
    unsigned int acc = 0;
    unsigned int i;
    for (i = 0; i < 0x80; i++)
        acc += e->m1B4[(unsigned char)i];
    return acc;
}

int fn_800437AC(int a)
{
    unsigned int t = a - 1;
    int r = 0;
    if (t <= 4) {
        r = 1 << t;
        if ((unsigned int)(a - 4) <= 1)
            r |= 0x20;
    }
    return r;
}

/* near-miss: 41/42 slots. Retail sets the second index through r0 (li 3,
 * li 4, mr r8,r0) after loading the whole pointer chain before the branch;
 * nested-ternary and if/else forms did not reproduce the extra mr. */
int fn_800437DC(int a, Unk80043884_Obj* o)
{
    Unk80043884_Sub6F8* p = o->m130->m44C->m6F8;
    Unk8003FC18_Entry* e;
    int b;
    int s0;
    int s1;
    if (a > 2) {
        b = 3;
        if (a == 3)
            b = 4;
    } else {
        b = a == 0;
    }
    e = (Unk8003FC18_Entry*)p->m14;
    s0 = Unk80043884_Sum(e + a);
    s1 = Unk80043884_Sum(e + b);
    return s0 > s1;
}

/* near-miss: 29/29 slots, loop counter/base register numbers differ
 * (retail r8/r10, here r10/r11). */
int fn_80043884(Unk80043884_Obj* o)
{
    Unk8003FC18_Entry* e = (Unk8003FC18_Entry*)o->m130->m44C->m6F8->m14;
    unsigned int s0 = Unk80043884_Sum(e);
    unsigned int s1 = Unk80043884_Sum(e + 1);
    return (s0 ^ s1) == 0;
}

int fn_800438F8(Unk800438F8_Obj* o)
{
    return o->mC->m84 == 0;
}

int fn_8004390C(int a)
{
    if (a == 0)
        return 1;
    if (a != 1)
        return a == 2 ? 4 : 0;
    return 2;
}

/* near-miss: 30/30 slots; retail emits "li r10,1" after the first null
 * test and the pointer loads; every spelling tried (if/else, ternary, &&)
 * schedules it differently. */
extern const float lbl_805A8E3C;
extern const float lbl_805A8E40;
extern const float lbl_805A8E44;
inline float Unk80043940_Abs(float v) { return (float)__builtin_fabs(v); }

extern "C" int fn_80043940(int a, float x, float y)
{
    int r = 0;
    if (a == 0) {
        if (!(x <= lbl_805A8E3C)) {
            r = 4;
            if (y > lbl_805A8E3C)
                r = 0x44;
            else if (!(y >= lbl_805A8E3C))
                r = 0x84;
        } else if (!(x >= lbl_805A8E3C)) {
            r = 8;
            if (y > lbl_805A8E3C)
                r = 0x18;
            else if (!(y >= lbl_805A8E3C))
                r = 0x28;
        }
    } else {
        if (!(x >= lbl_805A8E3C)) {
            r = 4;
            if (!(y <= lbl_805A8E3C))
                r = 0x44;
            else if (!(y >= lbl_805A8E3C))
                r = 0x84;
        } else if (!(x <= lbl_805A8E3C)) {
            r = 8;
            if (!(y <= lbl_805A8E3C))
                r = 0x18;
            else if (!(y >= lbl_805A8E3C))
                r = 0x28;
        }
    }
    if (!(Unk80043940_Abs(y) >= lbl_805A8E40) && !(Unk80043940_Abs(x) >= lbl_805A8E40)
        && (Unk80043940_Abs(y) >= lbl_805A8E40 || x != lbl_805A8E3C))
        r |= 0x400;
    if (!(Unk80043940_Abs(y) >= lbl_805A8E44) && !(Unk80043940_Abs(x) >= lbl_805A8E44))
        r |= 0x100;
    else
        r |= 0x200;
    if (!(y <= lbl_805A8E3C))
        r |= 1;
    else if (!(y >= lbl_805A8E3C))
        r |= 2;
    return r;
}

int fn_80043B00(Unk80043B00_Pl* a, Unk80043B00_Pl* b, Unk80043B00_Pl* c)
{
    int x;
    int y;
    int z;
    x = 1;
    if (a == 0 || (a->m590 & 0x20000000) != 0)
        x = 0;
    y = 1;
    if (b == 0 || (b->m590 & 0x20000000) != 0)
        y = 0;
    z = 1;
    if (c == 0 || (c->m590 & 0x20000000) != 0)
        z = 0;
    return lbl_805B1CDC[x][y][z];
}

int fn_80043B78(int a)
{
    int r = 0;
    switch (a) {
    case 0:
        r = 0x24001;
        break;
    case 1:
        r = 0x20002;
        break;
    case 2:
        r = 0x24004;
        break;
    case 3:
        r = 0x24008;
        break;
    case 4:
        r = 0x24020;
        break;
    case 5:
        r = 0x24010;
        break;
    case 6:
        r = 0x28100;
        break;
    case 7:
        r = 0x28080;
        break;
    case 8:
        r = 0x28040;
        break;
    case 9:
        r = 0x200;
        break;
    }
    return r;
}

int fn_80043C60(int a, int b, int c)
{
    int r = 0;
    if (c != 0)
        return 0;
    switch (a) {
    case 0:
        r = 4;
        break;
    case 1:
        r = 0x44;
        break;
    case 2:
        r = 0x104;
        break;
    case 3:
        r = 1;
        break;
    case 4:
        r = 0x10;
        break;
    case 5:
        r = 8;
        break;
    case 6:
        r = 2;
        break;
    case 7:
        r = 0x22;
        break;
    case 8:
        r = 0x82;
        break;
    }
    if (b != 0) {
        int t = r | 0x10000;
        r = t | 0x8000;
        switch (a) {
        case 1:
            r = t | 0x9800;
            break;
        case 2:
            r = t | 0xe000;
            break;
        case 7:
            r = t | 0x8a00;
            break;
        case 8:
            r = t | 0xc400;
            break;
        }
    }
    return r;
}

int fn_80043D70(unsigned int a)
{
    int r = 0;
    if (a == 0)
        r = 8;
    else if (a - 1 <= 2)
        r = 1 << (a - 1);
    if (a <= 1)
        r |= 0x10;
    return r;
}

int fn_80043DAC(int a)
{
    int r = 0;
    switch (a) {
    case 0:
        r = 1;
        break;
    case 1:
        r = 4;
        break;
    case 2:
        r = 2;
        break;
    }
    return r;
}

int fn_80043DF0(Unk80043DF0_Obj* o)
{
    char* rec = o->m14;
    char* rec2 = rec + 0xe64;
    int h0 = fn_8009E1D4(rec + 0x8c, 0, 0);
    int h1 = fn_8009E1D4(rec + 0xef0, 0, 0);
    int k = o->mC->m84;
    int is0 = k == 0;
    int is1 = (k ^ 1) == 0;
    int is2 = (k ^ 2) == 0;
    int is3 = (k ^ 3) == 0;
    int v;
    if (fn_800B5898(fn_800B555C()) == 0) {
        if (is0 != 0) {
            if (h0 == 1 && h1 == 1)
                v = 0x200;
            else if (h0 == 0 && h1 == 0)
                v = 0x100;
            else
                v = 0x400;
        } else if (is1 != 0) {
            if (h0 == 2 && h1 == 2)
                v = 0x1000000;
            else if (h0 == 3 && h1 == 3)
                v = 0x4000000;
            else
                v = 0x400;
            v |= 0x20000;
        } else if (is2 != 0) {
            if (h0 == 4 && h1 == 4)
                v = 0x400000;
            else if (h0 == 6 && h1 == 6)
                v = 0x10000000;
            else
                v = 0x400;
            v |= 0x10000;
        } else {
            v = 0x1000;
            if (is3 != 0)
                v = 0x20000000;
        }
    } else {
        v = 0x800;
    }
    if (fn_800B57EC(fn_800B555C()) == 1) {
        int r = fn_8006A1B4(o);
        Unk800440E8_State st = *(Unk800440E8_State*)((char*)fn_800B555C() + 0x688);
        switch (st.m0) {
        case -1:
            if (r == 1)
                v = 1;
            break;
        case 0:
            v = 0x4000;
            if (is0 != 0) {
                if (h0 == 1 && h1 == 1)
                    v = 0x4080;
                else if (h0 == 0 && h1 == 0)
                    v |= 0x40;
            }
            break;
        case 1:
            v = 0x4000;
            if (is0 != 0) {
                if (h0 == 1 && h1 == 1)
                    v = 0x6020;
                else if (h0 == 0 && h1 == 0)
                    v |= 0x2010;
            }
            break;
        case 2:
            v = 0x4000;
            if (is0 != 0) {
                v = 0x4002;
                if (st.mC - 1 == st.m4 + st.m8)
                    v = 0xc002;
            }
            break;
        }
    } else {
        if (fn_800B55A8(fn_800B555C()) != 0)
            v = 0x1000;
    }
    if (*(int*)(rec + 0x198) == *(int*)(rec2 + 0x198))
        v = 0x1000;
    {
        int t = o->mC->m1C;
        if (t == 0)
            v = 0x200000;
        else if (t == 1)
            v = 0x800000;
    }
    return v;
}

int fn_800440E8(int a, int b, int c, Unk800438F8_Obj* o)
{
    int r = 0;
    int kind = -1;
    int sel = 0;
    if (fn_800B57EC(fn_800B555C()) == 1) {
        Unk800440E8_State st = *(Unk800440E8_State*)((char*)fn_800B555C() + 0x688);
        kind = st.m0;
        sel = st.m4 + st.m8 + 1;
    }
    if ((fn_800438F8(o) != 0 && kind == 0) || kind == 1 || kind == 2) {
        switch (sel) {
        case 1:
            r = 0x20;
            break;
        case 2:
            r = 0x40;
            break;
        case 3:
            r = 1;
            break;
        case 4:
            r = 2;
            break;
        case 5:
            r = 4;
            break;
        case 6:
            r = 8;
            break;
        case 7:
            r = 0x10;
            break;
        }
        switch (kind) {
        case 0:
            r |= 0x100;
            break;
        case 1:
            r |= 0x200;
            break;
        case 2:
            r |= 0x80;
            break;
        }
    }
    return r;
}

/* near-miss: 13/12 slots. Retail extracts (a == 0x1d) << 2 through
 * cmpwi cr7 + mfcr + rlwinm; plain C compiles to xori/addic/subfe. */
int fn_80044240(int a)
{
    if (a > 0x4f)
        return 1;
    if (a <= 0x36)
        return (a == 0x1d) << 2;
    return 2;
}

int fn_80044580(int a, int b, int c)
{
    int r = 0;
    switch (a) {
    case 0:
    case 3:
        r = 0x8001;
        if (b == 0)
            r |= 0x8000000;
        break;
    case 1:
        r = 0x1008001;
        if (b == 0)
            r = 0x9008001;
        else if ((unsigned int)(b - 1) <= 1)
            r = 0x100c001;
        else if (b == 3)
            r = 0x1008081;
        break;
    case 9:
        r = 0x800101;
        if (b == 0)
            r = 0x4800101;
        else if ((unsigned int)(b - 1) <= 1)
            r = 0x802101;
        else if (b == 3)
            r = 0x800141;
        break;
    case 7:
    case 10:
        r = 0x101;
        if (b == 0)
            r = 0x4000101;
        break;
    case 11:
        r = 0xb;
        break;
    case 12:
        r = 3;
        break;
    case 8:
        r = 0x4000101;
        break;
    case 2:
        r = 0x8008001;
        break;
    }
    if (c == 1)
        r |= 0x400000;
    return r;
}

int fn_800446D8(int a, float x, float y)
{
    int r = fn_80046828(x);
    r |= fn_800467C0(y);
    if (a != 0) {
        r |= fn_80046964(x);
        r |= fn_80046924(y);
    }
    return r;
}

int fn_80044744(int a, int b)
{
    if (a >= b)
        return (a > b) << 1;
    return 1;
}

int fn_8004475C(int a)
{
    switch (a) {
    case 0:
        return 0x40;
    case 1:
        return 0x10;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 4;
    case 5:
        return 0x200;
    case 6:
        return 0x20;
    case 7:
        return 8;
    case 8:
        return 0x80;
    case 9:
        return 0x400;
    default:
        return 0;
    }
}

int fn_80044820()
{
    return 1;
}

int fn_80044828(int a)
{
    return a == 0 ? 2 : 1;
}

int fn_8004483C(int u, int a, int b)
{
    int r = 0;
    if (a <= 0x12) {
        int v = lbl_806E0270[a - 1];
        if (a == 0xd) {
            r = lbl_806EF990.m0 == 0;
        } else if (a == 0x11) {
            if ((b & lbl_806EF998.m0) == 0)
                r = 1;
        } else if (a == 0x12) {
            if ((b & lbl_806EF9A0.m0) == 0)
                r = 1;
        } else if (a == 6) {
            r = fn_80044B2C(b);
        } else if (a == 5) {
            r = fn_80044A20(b);
        } else if (a == 4) {
            r = fn_80044A78(b);
        } else if (v != b) {
            r = 1;
        }
    }
    return r;
}

void fn_80044918()
{
    lbl_806EF998.m4 = 0;
    lbl_806EF9A8 = 0;
    lbl_806EF9AC = 0;
    lbl_806EF9A0.m0 = 0;
    lbl_806EF9A0.m4 = 0;
    lbl_806EF990.m0 = 0;
    lbl_806EF990.m4 = 0;
    lbl_806EF998.m0 = 0;
    lbl_806E0270[4] = 0;
    lbl_806E0270[5] = 0;
    lbl_806E0270[7] = 0;
    lbl_806E0270[3] = 0;
    lbl_806E0270[17] = 0;
}

void fn_8004497C()
{
    lbl_806E0270[0] = -1;
    lbl_806E0270[1] = -1;
}

void fn_80044994()
{
    lbl_806EF9A0.m0 = lbl_806EF9A0.m4;
    lbl_806EF990.m0 = lbl_806EF990.m4;
    lbl_806EF998.m0 = lbl_806EF998.m4;
    lbl_806EF9A0.m4 = 0;
    lbl_806EF990.m4 = 0;
    lbl_806EF998.m4 = 0;
}

void fn_800449D8()
{
    int i;
    for (i = 0; i < 0x12; i++)
        lbl_806E0270[i] = -1;
    lbl_806EF9A8 = 0;
    lbl_806EF9AC = 0;
    lbl_806EF9B0 = 0x738;
}

int fn_80044A20(int a)
{
    int g = lbl_806E027C;
    int r = 1;
    if (((a & 1) && (g & 4)) || ((a & 4) && (g & 0x20)) || ((a & 8) && (g & 4)) || ((a & 2) && (g & 8)))
        r = 0;
    return r;
}

int fn_80044A78(int a)
{
    int u = lbl_806E0270[4];
    int v = lbl_806E0270[5];
    int r = 1;
    if (((u & 1) && (a & 4)) || ((u & 4) && (a & 0x20)) || ((u & 8) && (a & 4)) || ((u & 2) && (a & 8)))
        r = 0;
    if ((v & 0x20000d) && (a & 0x80))
        r = 0;
    if ((v & 0x404840) && (a & 0x100))
        r = 0;
    if ((v & 0x1120200) && (a & 0x40))
        r = 0;
    return r;
}

int fn_80044B2C(int a)
{
    int g = lbl_806E027C;
    int r = 1;
    if (a & 0x20000d) {
        r = 0;
        if ((g & 0x80) == 0)
            r = 1;
    }
    if ((a & 0x404840) && (g & 0x100))
        r = 0;
    if ((a & 0x1120200) && (g & 0x40))
        r = 0;
    return r;
}

void fn_80044B94(int u, int a, int b)
{
    if (a > 0x12)
        return;
    if (a == 0x11) {
        Unk800437AC_Pair* p = &lbl_806EF998;
        p->m4 |= 1;
        return;
    }
    if (a == 0xd) {
        Unk800437AC_Pair* p = &lbl_806EF990;
        p->m4 |= 1;
        return;
    }
    if (a == 0x12) {
        Unk800437AC_Pair* p = &lbl_806EF9A0;
        p->m4 |= b;
        return;
    }
    if ((unsigned int)(a - 7) > 1)
        lbl_806E0270[a - 1] = b;
}
