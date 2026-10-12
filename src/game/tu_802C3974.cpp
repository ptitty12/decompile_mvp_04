/*
 * Game code, .text 0x802C3974-0x802C79F0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802C3974.h"

extern unsigned char lbl_805E1B82[];
extern unsigned char lbl_805E1B9A[];
extern const void* lbl_80664238[];
extern int lbl_8061D39C;

void fn_80377408(void* p);
void* operator new(unsigned int n, int heap);
void fn_802B961C(int p, int a);
int fn_802C72F4(int a, int b, int c);
void fn_802C3EC0(Unk802C3B60* o);
extern const char lbl_805E15C4[];
extern const char lbl_805E137C[];
extern const char lbl_805E14CC[];
Unk802C2188* fn_802C610C(Unk802C3B60* o, Unk802C610C_Cfg* c, int flag);
extern const char lbl_805E15E8[];
extern Unk802C60A4_Rgb lbl_805E2256[];
char* fn_802C5970(char* buf, int a, int b, int c, int d);
extern const char lbl_805E0134[];
extern int lbl_8061D464;
extern int lbl_80620830;
extern const char lbl_805E1628[];
extern const char lbl_805E158C[];
extern const char lbl_805E1594[];
extern const char lbl_805E159C[];
extern const char lbl_805E15A4[];
extern const char lbl_805E15BC[];
extern const char lbl_805E1644[];
extern const char lbl_805E166C[];
extern const char lbl_805E1690[];
extern const char lbl_805E16B8[];
extern const char lbl_805E16C0[];
extern const char lbl_805E16E8[];
extern const char lbl_805E16F0[];
void fn_802C63B4(const char* name, const char* b, int* out1, int* out2);
extern const char lbl_805E15CC[];
extern const char lbl_805E15E0[];
int fn_803EBD14(int h, const char* k);
int fn_802B9954(int a, int b, int c);
int fn_802B98AC(int a, int b);
int fn_803EE310(int a);
void fn_803FFA60(int dst, int src, int n);
void fn_80433004(int p, int n);
void fn_803EDA0C(int p);
extern const char lbl_805DFC34[];
extern const char lbl_805E144C[];
extern const char lbl_805E1468[];
extern const char lbl_805E1480[];
extern const char lbl_805E1498[];
extern int lbl_8061EBF4[];
extern int lbl_8061EBC0[];
int fn_804089B4(char* buf, const char* fmt, ...);
int fn_802B9300(const char* name, int a, int b, int c);
void fn_802C6404(Unk802C3B60* o);
int fn_803EBD14(int h, int k);
void fn_803D74A0(int a, int b, int c);
void fn_803D74A0(int a, const char* b, int c);
void fn_802C4CB4(int a, int b, int c, int d);
void fn_802C51C0(int a, int b, int c, int d);
int fn_802C440C(Unk802C3B60* o, int* p, int x);

unsigned char* fn_802C3A2C(int a, int b);

void fn_802C3974(Unk802C2188* o)
{
    unsigned char* e = fn_802C3A2C(o->mA0, o->m9C);
    if (e) {
        o->mAC = *(Unk802C2188_Fmt*)e;
    } else {
        o->mAC.Set(o->mA0, o->m9C, (int)e, 2);
    }
}

int fn_802C39DC(unsigned char a, unsigned char b)
{
    unsigned char* e = fn_802C3A2C(a, b);
    if (e == 0) {
        return 0;
    }
    int r;
    if (lbl_805E1B82[e[3] * 2] & 8) r = 0; else r = 1;
    return r;
}

inline unsigned char Unk802C3A2C_At(unsigned char* b, int o) { return b[o]; }
unsigned char* fn_802C3A2C(int a, int b)
{
    unsigned char ua = a;
    unsigned char ub = b;
    int off = 0;
    for (int i = 0; i < 0x1AF; i++, off += 4) {
        if (Unk802C3A2C_At(lbl_805E1B9A, off) == ua && Unk802C3A2C_At(lbl_805E1B9A + 1, off) == ub) {
            return lbl_805E1B9A + off;
        }
    }
    return 0;
}

/* near-miss (9 vs 10 insns): retail copies i to r0, sets r3 = 0 before the compare and returns with bgtlr; every if/ternary/local spelling tried gives a
   separate out-of-line li. */
unsigned char* fn_802C3A7C(int i)
{
    if (i > 0x1AE) {
        return 0;
    }
    return lbl_805E1B9A + i * 4;
}

int fn_802C3AA0(Unk802C2188* o)
{
    if (lbl_805E1B82[o->mAC.c3 * 2] & 0x20) {
        return 1;
    }
    return 0;
}

int fn_802C3AC8(Unk802C2188* o)
{
    if (lbl_805E1B82[o->mAC.c3 * 2] & 0x40) {
        return 1;
    }
    return 0;
}

int fn_802C3AF0(Unk802C2188* o)
{
    if (lbl_805E1B82[o->mAC.c3 * 2] & 0x10) {
        return 1;
    }
    return 0;
}

int fn_802C3B18(Unk802C2188* o)
{
    int r;
    if (lbl_805E1B82[o->mAC.c3 * 2] & 4) r = 0; else r = 1;
    return r;
}

int fn_802C3B3C(Unk802C2188* o)
{
    int r;
    if (lbl_805E1B82[o->mAC.c3 * 2] & 8)
        r = 0;
    else
        r = 1;
    return r;
}

Unk802C3B60* fn_802C3B60(Unk802C3B60* o)
{
    o->m288 = lbl_80664238;
    fn_802C2188(&o->s0);
    fn_802C2188(&o->s1);
    fn_802C2188(&o->s2);
    o->m234 = 0;
    o->m238 = 0;
    o->m24C = 0;
    o->m250 = 0;
    o->m254 = 0;
    o->m258 = 0;
    o->m25C = 0;
    o->m260 = 0;
    o->m264 = 0;
    o->m268 = 0;
    o->m26C = 0;
    o->m270 = 0;
    o->m274 = 0;
    o->m278 = 0;
    o->m27C = 0;
    o->m280 = 0;
    o->m284 = 0;
    o->m238 = fn_802C72F4(8, 8, 0);
    return o;
}

void fn_802C3C08(Unk802C3B60* o, int c)
{
    o->m288 = lbl_80664238;
    fn_802C3EC0(o);
    if (o->m254 != 0) {
        fn_802B961C(o->m254, 1);
        o->m254 = 0;
    }
    int z = 0;
    o->m26C = z;
    o->m270 = z;
    if (o->m258 != 0) {
        fn_802B961C(o->m258, 1);
        o->m258 = z;
    }
    o->m274 = z;
    if (o->m25C != 0) {
        fn_802B961C(o->m25C, 1);
        o->m25C = z;
    }
    o->m278 = z;
    if (o->m260 != 0) {
        fn_802B961C(o->m260, 1);
        o->m260 = z;
    }
    o->m27C = z;
    if (o->m264 != 0) {
        fn_802B961C(o->m264, 1);
        o->m264 = z;
    }
    o->m280 = z;
    if (o->m268 != 0) {
        fn_802B961C(o->m268, 1);
        o->m268 = z;
    }
    o->m268 = z;
    fn_802C2214(&o->s2, 2);
    fn_802C2214(&o->s1, 2);
    fn_802C2214(&o->s0, 2);
    if (c & 1) {
        fn_80377408(o);
    }
}

struct Unk802C3D2C_Elem {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

extern const char lbl_805E1438[];
extern int lbl_806EE9F0;
void* fn_803774A8(unsigned n, int heap);
void* fn_802BB19C();
int fn_802BB27C(void* o, int idx);
int fn_803ED604(const char* name, int size, int flags);
int fn_803ED634(const char* name, int size, int flags);

/* near-miss (101/101 insns, register names only): retail keeps the byte offset in r27, the array base in r28 and the label hi-part in r26; ours r28/r26/r27 */
void fn_802C3D2C(Unk802C3B60* o, int n)
{
    if (o->m24C != 0)
        fn_802C3EC0(o);
    int i = 0;
    void* p = fn_803774A8((n + 3) * 0x30, 0);
    o->m250 = n;
    o->m24C = (int)p;
    int h = fn_802BB27C(fn_802BB19C(), 0);
    if (o->m250 + 3 > 0) {
        int off = 0;
        do {
            char* base = (char*)o->m24C;
            Unk802C3D2C_Elem* e = (Unk802C3D2C_Elem*)(base + off);
            e->m18 = fn_802C72F4(0x10, 0x10, 0x10);
            int v;
            if (i == 0 || i > 2) {
                e->mC = fn_802C72F4(0x100, 0x20, 0);
                e->m10 = fn_802C72F4(0x40, 0x40, 0);
                e->m14 = fn_802C72F4(0x20, 0x20, 0);
                e->m4 = fn_803ED634(lbl_805E1438, 0x4070, h | 0x400);
                if (e->m4 == 0)
                    e->m4 = fn_803ED604(lbl_805E1438, 0x4070, lbl_806EE9F0 | 0x400);
                v = e->m4;
            } else {
                e->mC = ((Unk802C3D2C_Elem*)o->m24C)->mC;
                e->m10 = ((Unk802C3D2C_Elem*)o->m24C)->m10;
                e->m14 = ((Unk802C3D2C_Elem*)o->m24C)->m14;
                e->m4 = ((Unk802C3D2C_Elem*)o->m24C)->m4;
                v = ((Unk802C3D2C_Elem*)o->m24C)->m0;
            }
            *(int*)(base + off) = v;
            i++;
            e->m24 = 0;
            off += 0x30;
            e->m8 = 0;
            e->m28 = 0;
            e->m2C = 0;
            e->m20 = 0;
            e->m1C = 0;
        } while (i < o->m250 + 3);
    }
}

void fn_803EC054(int h);
void fn_80377488(void* p);

void fn_802C3EC0(Unk802C3B60* o)
{
    int i = 0;
    if (o->m24C != 0) {
        for (i = 0; i < o->m250 + 3; i++) {
            Unk802C3D2C_Elem* e = (Unk802C3D2C_Elem*)(o->m24C + i * 0x30);
            if (i == 0) {
                ((Unk802C3D2C_Elem*)o->m24C)[1].m4 = i;
                ((Unk802C3D2C_Elem*)o->m24C)[2].m4 = i;
            }
            e->m8 = 0;
            if (e->m18 != 0)
                fn_803EC054(e->m18);
            if (i == 0 || i > 2) {
                if (e->mC != 0)
                    fn_803EC054(e->mC);
                if (e->m10 != 0)
                    fn_803EC054(e->m10);
                if (e->m14 != 0)
                    fn_803EC054(e->m14);
                if (e->m4 != 0) {
                    fn_803EDA0C(e->m4);
                    e->m4 = 0;
                }
            }
            e->m0 = 0;
            fn_802C40A0(o, (Unk802C40A0_Elem*)e);
        }
        if (o->m24C != 0) {
            delete[] (char*)o->m24C;
            o->m24C = 0;
        }
    }
    fn_802C2254(&o->s0);
    fn_802C2254(&o->s1);
    fn_802C2254(&o->s2);
    if (o->m234 != 0) {
        fn_802C2254(o->m234);
        if (o->m234 != 0) {
            fn_802C2214(o->m234, 3);
            o->m234 = 0;
        }
    }
    o->m250 = 0;
}

void fn_802C4030(Unk802C3B60* o)
{
    if (o->m24C != 0) {
        for (int i = 0; i < o->m250 + 3; i++) {
            fn_802C40A0(o, (Unk802C40A0_Elem*)(o->m24C + i * 0x30));
        }
    }
}

inline int HasBuf(Unk802C2188* t)
{
    int r = 1;
    if (t->m4 == 0) {
        r = 0;
    }
    return r;
}

void fn_802C40A0(Unk802C3B60*, Unk802C40A0_Elem* e)
{
    e->m28 = 0;
    e->m2C = 0;
    e->m20 = 0;
    e->m1C = 0;
    e->m24 = 0;
}

void fn_802C40BC(Unk802C3B60* o, Unk802C2188_Pair* a)
{
    fn_802C2314(&o->s0, a);
}

void fn_802C40DC(Unk802C3B60* o, Unk802C2188_Pair* a)
{
    fn_802C2314(&o->s1, a);
}

void fn_802C4100(Unk802C3B60* o, Unk802C2188_Pair* a)
{
    if (o->m234 == 0) {
        o->m234 = fn_802C2188((Unk802C2188*)operator new(0xBC, 0x100));
    }
    if (HasBuf(o->m234)) {
        fn_802C2254(o->m234);
    }
    fn_802C2314(o->m234, a);
}

void fn_802C417C(Unk802C3B60* o, Unk802C2188_Pair* a)
{
    fn_802C23BC(&o->s2, a);
}

/* near-miss (22 vs 35 insns): retail repeats the lis/lwz of the flag and the address setup in each of the four paths and only merges the
   cmpwi/bnelr/lwz tail of three of them; our single merged form is shorter. */
int fn_802C41A0(Unk802C3B60* o, int a, int b, int c)
{
    int r = 0x7D4;
    Unk802C2188* s;
    if (c == 0xE) {
        s = &o->s2;
    } else if (b != 0) {
        s = o->m234;
        if (s == 0) {
            return r;
        }
    } else if (a == 0) {
        s = &o->s0;
    } else {
        s = &o->s1;
    }
    r = 0x76C;
    if (lbl_8061D39C == 0) {
        r = s->mB0;
    }
    return r;
}

int fn_802C422C(Unk802C3B60* o, int a, int b)
{
    int r = 0;
    if (b != 0) {
        Unk802C2188* s = o->m234;
        if (s != 0) {
            r = s->mB8;
        }
    } else if (a == 0) {
        r = o->s0.mB8;
    } else {
        r = o->s1.mB8;
    }
    return r;
}

int fn_802C4260(Unk802C3B60* o, int a, int b)
{
    int r = 0;
    if (b != 0) {
        Unk802C2188* s = o->m234;
        if (s != 0) {
            r = s->mB4;
        }
    } else if (a == 0) {
        r = o->s0.mB4;
    } else {
        r = o->s1.mB4;
    }
    return r;
}

void fn_802C4294(Unk802C3B60* o)
{
    char buf[0x20];
    fn_804089B4(buf, lbl_805E144C, lbl_805DFC34);
    o->m23C = fn_802B9300(buf, 0x400, 1, 0);
    fn_804089B4(buf, lbl_805E1468, lbl_805DFC34);
    o->m240 = fn_802B9300(buf, 0x400, 1, 0);
    fn_804089B4(buf, lbl_805E1480, lbl_805DFC34);
    o->m244 = fn_802B9300(buf, 0x400, 1, 0);
    fn_804089B4(buf, lbl_805E1498, lbl_805DFC34);
    o->m248 = fn_802B9300(buf, 0x400, 1, 0);
    fn_802C6404(o);
}

void fn_802C4388(Unk802C3B60* o, int x, int y)
{
    for (int i = 1; i <= 12; i++) {
        int r = fn_802C440C(o, (int*)(y + 0x88 + i * 4), lbl_8061EBF4[i]);
        if (r == 0) {
            r = o->m238;
        }
        fn_803D74A0(x, lbl_8061EBC0[i], r);
    }
}

int fn_802C440C(Unk802C3B60* o, int* p, int x)
{
    int r = 0;
    if (*p == 0) {
        r = fn_803EBD14(o->m248, x);
    }
    if (r == 0) {
        r = o->m238;
    }
    return r;
}

void fn_802C445C(int a, int b, int c, int kind, int arg)
{
    switch (kind) {
    case 0:
    case 1:
    case 2:
        fn_802C4CB4(a, b, c, arg);
        break;
    case 3:
        fn_802C51C0(a, b, c, arg);
        break;
    }
}

void fn_802C44A8(int, int x, int h, int y, int z)
{
    fn_803D74A0(x, y, fn_803EBD14(h, z));
}

void fn_802C44F0(int, int x, Unk802C2188* h, int y, int z)
{
    fn_803D74A0(x, y, fn_802C2304(h, z));
}

extern const char lbl_805E1504[];
extern const char lbl_805E150C[];
extern const char lbl_805E1304[];
extern const char lbl_805E132C[];
extern const char lbl_805E1334[];
extern const char lbl_805E133C[];
extern const char lbl_805E1344[];
extern const char lbl_805E134C[];
extern const char lbl_805E1354[];
extern const char lbl_805E151C[];
extern const char lbl_805E1514[];
extern const char lbl_805E152C[];
extern const char lbl_805E1524[];
extern const char lbl_805E1534[];
extern const char lbl_805E136C[];
extern const char lbl_805E1374[];
extern const char lbl_805E153C[];
extern const char lbl_805E1544[];
extern const char lbl_805E154C[];
extern const char lbl_805E1554[];
extern const char lbl_805E155C[];
extern const char lbl_805E1564[];
extern const char lbl_805E156C[];
extern const char lbl_805E1574[];
extern const char lbl_805E157C[];
extern const char lbl_805E1584[];
extern const char lbl_805E158C[];
extern const char lbl_805E1594[];
extern const char lbl_805E159C[];
extern const char lbl_805E15A4[];
extern const char lbl_805E15AC[];
extern const char lbl_805E15B4[];
extern const char lbl_805E15BC[];
extern const char lbl_805E14B4[];
extern const char lbl_805E12DC[];
extern const char lbl_805E12E4[];
extern const char lbl_805E139C[];
extern const char lbl_805E12EC[];
extern const char lbl_805E12FC[];
extern const char lbl_805E12F4[];
extern const char lbl_805E1394[];
extern const char lbl_805E13A4[];
extern const char lbl_805E135C[];
extern const char lbl_805E1364[];
extern const char lbl_805E1314[];
extern const char lbl_805E1324[];
extern const char lbl_805E14BC[];
extern int lbl_8061EC5C;
struct Unk802C4CB4_Cfg;
void fn_802C4538(Unk802C3B60* o, int h, Unk802C2188* t, Unk802C4CB4_Cfg* cfg);
void fn_802C483C(Unk802C3B60* o, int h, Unk802C2188* t, Unk802C4CB4_Cfg* cfg, int year);
struct Unk802C4978_Req;
void fn_802C4978(Unk802C3B60* o, int h, Unk802C4978_Req* req, Unk802C2188* t, Unk802C4CB4_Cfg* cfg);
void fn_802C44A8(int, int x, int h, int y, int z);
void fn_802C44F0(int, int x, Unk802C2188* h, int y, int z);

struct Unk802C4CB4_Cfg {
    char pad0[0x40];
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    char pad5C[4];
    int m60;
    unsigned char m64b[4];
    int m68;
    int m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
    char pad80[4];
    int m84;
};

void fn_802C4538(Unk802C3B60* o, int h, Unk802C2188* t, Unk802C4CB4_Cfg* c)
{
    int a = 0;
    int b = 0;
    int d;
    int e;
    if (c->m68 == 0x11 && c->m6C == 0) {
        b = fn_802C2304(t, 0x1A);
        e = fn_802C2304(t, 0x1B);
        d = e;
    } else {
        d = fn_802C2304(t, 0x12);
        e = fn_802C2304(t, 0x13);
    }
    if (c->m70 != 0) {
        int tmp = d;
        d = e;
        e = tmp;
        fn_802C44F0((int)o, h, t, (int)lbl_805E14B4, 0x1C);
        fn_802C44F0((int)o, h, t, (int)lbl_805E12DC, 0x1D);
        if (c->m68 != 0x11 || c->m6C != 0)
            b = fn_802C2304(t, 0x21);
    } else {
        fn_802C44F0((int)o, h, t, (int)lbl_805E14B4, 1);
        fn_802C44F0((int)o, h, t, (int)lbl_805E12DC, 2);
        if (c->m68 != 0x11 || c->m6C != 0)
            b = fn_802C2304(t, 3);
    }
    int k = c->m68;
    if (k == 0xE) {
        a = fn_802C2304(t, 4);
    } else if (k == 0x11 && c->m6C == 0) {
        a = fn_802C2304(t, 0x19);
    } else if (c->m70 != 0) {
        switch (c->m74) {
        case 0:
            a = fn_802C2304(t, 0x1F);
            break;
        case 1:
            a = fn_802C2304(t, 0x1E);
            break;
        case 2:
            a = fn_802C2304(t, 0x20);
            break;
        }
    } else {
        switch (c->m74) {
        case 0:
            a = fn_802C2304(t, 5);
            break;
        case 1:
            a = fn_802C2304(t, 4);
            break;
        case 2:
            a = fn_802C2304(t, 6);
            break;
        }
    }
    fn_803D74A0(h, lbl_805E12E4, b);
    fn_803D74A0(h, lbl_805E139C, b);
    fn_803D74A0(h, lbl_805E12EC, a);
    fn_803D74A0(h, lbl_805E12FC, a);
    fn_803D74A0(h, lbl_805E12F4, a);
    fn_803D74A0(h, lbl_805E1394, a);
    fn_803D74A0(h, lbl_805E13A4, d);
    fn_803D74A0(h, lbl_805E135C, d);
    fn_803D74A0(h, lbl_805E1364, e);
}

void fn_802C483C(Unk802C3B60* o, int h, Unk802C2188* t, Unk802C4CB4_Cfg* c, int year)
{
    int v = 0;
    switch (c->m68) {
    case 1:
    case 16:
        v = fn_802C2304(t, 10);
        break;
    case 14:
        v = fn_802C2304(t, 9);
        break;
    default:
        if (year > 0x7C1) {
            int k = c->m4C;
            if (k == 2) {
                v = fn_802C2304(t, 0xB);
            } else if (k == 1) {
                v = fn_802C2304(t, 8);
            } else if (k == 0) {
                int sel = c->m84;
                if (sel <= 0x19) {
                    int m = c->m74;
                    if (m == 0)
                        sel = 0x1A;
                    else if (m == 1)
                        sel = 0x1F;
                    else if (m == 2)
                        sel = 0x24;
                }
                switch (sel) {
                case 0x1A:
                case 0x1C:
                case 0x20:
                    v = fn_802C2304(t, 0xB);
                    break;
                default:
                    v = fn_802C2304(t, 9);
                    break;
                }
            }
        } else {
            v = fn_802C2304(t, 9);
        }
        break;
    }
    fn_803D74A0(h, lbl_805E1314, v);
    fn_803D74A0(h, lbl_805E1324, v);
    fn_803D74A0(h, lbl_805E14BC, v);
}

struct Unk802C4978_Req {
    char pad0[0xC];
    int mC;
    int m10;
    int m14;
};

extern const char lbl_805E14C4[];
extern const char lbl_805E14CC[];
extern const char lbl_805E14D4[];
extern const char lbl_805E14DC[];
extern const char lbl_805E14E4[];
extern const char lbl_805E14EC[];
extern const char lbl_805E14F4[];
extern const char lbl_805E14FC[];
int fn_802C2C84(Unk802C2188* o);

/* near-miss (207/207 insns, register names only): retail keeps the cfg pointer in r26 and the first request value in r27; ours r27/r26.
   All 120 orderings of the five locals' declarations give the same result. */
void fn_802C4978(Unk802C3B60* o, int h, Unk802C4978_Req* req, Unk802C2188* t, Unk802C4CB4_Cfg* c)
{
    const char* nm;
    int val;
    int a = 0;
    int b = 0;
    int w = 0;
    if (req != 0) {
        a = req->m10;
        b = a;
        if (fn_802C2C84(t) != 0)
            b = req->m14;
        w = req->mC;
    }
    if (w == 0)
        w = o->m238;
    int k = c->m68;
    if (k == 0xE || k == 0x10 || k == 0x11) {
        b = o->m238;
        a = b;
        w = b;
    }
    int u = w;
    if (fn_802C3B3C(t) == 0)
        u = o->m238;
    int v = u;
    if (c->m7C != 0)
        v = o->m238;
    fn_803D74A0(h, lbl_805E14C4, v);
    if (c->m78 != 0) {
        fn_803D74A0(h, lbl_805E14CC, o->m238);
        fn_803D74A0(h, lbl_805E14D4, o->m238);
        fn_803D74A0(h, lbl_805E14DC, o->m238);
        fn_803D74A0(h, lbl_805E14E4, o->m238);
        fn_803D74A0(h, lbl_805E14EC, o->m238);
        nm = lbl_805E14F4;
        val = o->m238;
        goto tail;
    }
    fn_803D74A0(h, lbl_805E14CC, a);
    if (fn_802C3AC8(t) != 0) {
        if (c->m70 != 0) {
            fn_803D74A0(h, lbl_805E14D4, o->m238);
            fn_803D74A0(h, lbl_805E14DC, b);
        } else {
            fn_803D74A0(h, lbl_805E14D4, b);
            fn_803D74A0(h, lbl_805E14DC, o->m238);
        }
    } else {
        fn_803D74A0(h, lbl_805E14D4, o->m238);
        fn_803D74A0(h, lbl_805E14DC, o->m238);
    }
    if (fn_802C3AA0(t) != 0) {
        if (c->m70 != 0) {
            fn_803D74A0(h, lbl_805E14E4, o->m238);
            fn_803D74A0(h, lbl_805E14EC, b);
        } else {
            fn_803D74A0(h, lbl_805E14E4, b);
            fn_803D74A0(h, lbl_805E14EC, o->m238);
        }
    } else {
        fn_803D74A0(h, lbl_805E14E4, o->m238);
        fn_803D74A0(h, lbl_805E14EC, o->m238);
    }
    if (fn_802C3AF0(t) != 0) {
        if (c->m70 != 0) {
            fn_803D74A0(h, lbl_805E14F4, o->m238);
            fn_803D74A0(h, lbl_805E14FC, b);
            return;
        }
        nm = lbl_805E14F4;
        val = b;
    tail:
        fn_803D74A0(h, nm, val);
        fn_803D74A0(h, lbl_805E14FC, o->m238);
    } else {
        fn_803D74A0(h, lbl_805E14F4, o->m238);
        fn_803D74A0(h, lbl_805E14FC, o->m238);
    }
}

void fn_802C4CB4(Unk802C3B60* o, int h, Unk802C4978_Req* req, Unk802C4CB4_Cfg* c)
{
    int year = 0x76C;
    Unk802C2188* t = fn_802C610C(o, (Unk802C610C_Cfg*)c, 0);
    if (lbl_8061D39C == 0)
        year = t->mB0;
    int h2 = o->m23C;
    int h3 = o->m248;
    char ch;
    if (c->m60 <= 9)
        ch = *((unsigned char*)c + 0x63) + 0x30;
    else
        ch = *((unsigned char*)c + 0x63) + 0x57;
    char buf[0x10];
    fn_802C44A8((int)o, h, h3, (int)lbl_805E1504, (int)lbl_805E1504);
    fn_802C44A8((int)o, h, h3, (int)lbl_805E150C, (int)lbl_805E150C);
    fn_802C44F0((int)o, h, t, (int)lbl_805E1304, 7);
    fn_802C44F0((int)o, h, t, (int)lbl_805E132C, 0xC);
    fn_802C44F0((int)o, h, t, (int)lbl_805E1334, 0xD);
    fn_802C44F0((int)o, h, t, (int)lbl_805E133C, 0xE);
    fn_802C44F0((int)o, h, t, (int)lbl_805E1344, 0xF);
    fn_802C44F0((int)o, h, t, (int)lbl_805E134C, 0x10);
    fn_802C44F0((int)o, h, t, (int)lbl_805E1354, 0x11);
    fn_802C44A8((int)o, h, h3, (int)lbl_805E1514, (int)(c->m40 == 2 ? lbl_805E151C : lbl_805E1514));
    fn_802C44A8((int)o, h, h3, (int)lbl_805E1524, (int)(c->m44 == 0 ? lbl_805E152C : lbl_805E1524));
    fn_802C44A8((int)o, h, h3, (int)lbl_805E1534, (int)lbl_805E1534);
    fn_802C44F0((int)o, h, t, (int)lbl_805E136C, 0x14);
    fn_802C44F0((int)o, h, t, (int)lbl_805E1374, 0x15);
    int n1 = 4;
    if (year > 0x795)
        n1 = c->m54;
    fn_804089B4(buf, lbl_805E153C, n1);
    fn_802C44A8((int)o, h, o->m240, (int)lbl_805E1544, (int)buf);
    int n2 = 6;
    if (year > 0x795)
        n2 = c->m58;
    fn_804089B4(buf, lbl_805E154C, n2);
    fn_802C44A8((int)o, h, o->m244, (int)lbl_805E1554, (int)buf);
    if (c->m68 == 0x11 && c->m6C == 0) {
        fn_802C44F0((int)o, h, t, (int)lbl_805E155C, 0x1B);
    } else if (c->m48 != 0 || lbl_8061EC5C != 0) {
        fn_802C44F0((int)o, h, t, (int)lbl_805E155C, 0);
    } else {
        fn_804089B4(buf, lbl_805E1564, ch);
        fn_802C44A8((int)o, h, h2, (int)lbl_805E155C, (int)buf);
    }
    if (c->m50 == 0) {
        fn_804089B4(buf, lbl_805E156C, ch);
        fn_802C44A8((int)o, h, h2, (int)lbl_805E1574, (int)buf);
        fn_804089B4(buf, lbl_805E157C, ch);
        fn_802C44A8((int)o, h, h2, (int)lbl_805E1584, (int)buf);
    } else {
        fn_802C44F0((int)o, h, t, (int)lbl_805E1584, 0x17);
        fn_802C44F0((int)o, h, t, (int)lbl_805E1574, 0x18);
    }
    fn_802C4538(o, h, t, c);
    fn_802C483C(o, h, t, c, year);
    fn_802C4978(o, h, req, t, c);
    fn_803D74A0(h, lbl_805E158C, o->m26C);
    fn_803D74A0(h, lbl_805E1594, o->m270);
    fn_803D74A0(h, lbl_805E159C, o->m274);
    fn_803D74A0(h, lbl_805E15A4, o->m278);
    fn_803D74A0(h, lbl_805E15AC, o->m27C);
    fn_803D74A0(h, lbl_805E15B4, o->m280);
    fn_803D74A0(h, lbl_805E15BC, o->m284);
    fn_802C4388(o, h, (int)c);
}

void fn_802C51C0(Unk802C3B60* o, int h, Unk802C51C0_Req* req, Unk802C610C_Cfg* c)
{
    int v = 0;
    int lod = fn_802C2304(fn_802C610C(o, c, 0), 0x16);
    int x = 0;
    if (req != 0) {
        x = req->m18;
        v = req->m10;
    }
    fn_803D74A0(h, lbl_805E15C4, x);
    fn_803D74A0(h, lbl_805E137C, lod);
    if (c->m68 == 0xE || c->m68 == 0x10 || c->m68 == 0x11) {
        v = o->m238;
    }
    fn_803D74A0(h, lbl_805E14CC, v);
}

/* near-miss (39 vs 46 insns): retail masks each source value first (clrlwi) and then rlwimi-inserts it; C bit-fields (int/unsigned/short/char bases) and
   explicit mask expressions both fail to reproduce that clrlwi + rlwimi pair. Store order of the first three zero words is also swapped (retail 0, 8, 4). */
void fn_802C56F8(Unk802C56F8_Regs* out, Unk802C56F8_Cfg* c)
{
    out->w0 = 0;
    out->w2 = 0;
    out->w1 = 0;
    out->a.f5 = c->m84;
    if (c->m70 != 0) {
        out->a.f3 = 1;
    }
    out->a.f1 = c->m24;
    out->w2 = c->m20;
    out->a.f4 = c->m60;
    out->a.f2 = c->m64;
    out->a.f0 = 1;
    out->a.f6 = c->m2C;
    out->b.g0 = c->m34;
    out->b.g1 = c->m38;
    out->b.g2 = c->m3C;
}

void fn_802C58E0(int, Unk802C58E0_Slot* o, Unk802C59D0_Req* req)
{
    char buf[0x40] = "";
    fn_804089B4(buf, lbl_805E15CC, req->m2C, lbl_805DFC34);
    fn_802B9954((int)buf, o->m4, 0x4070);
    o->m0 = fn_803EBD14(o->m4, lbl_805E15E0);
}

char* fn_802C5970(char* buf, int a, int b, int c, int d)
{
    fn_804089B4(buf, lbl_805E15E8, a + 0x61, b + 0x61, c + 0x61, d + 0x61, lbl_805DFC34);
    return buf;
}

char* fn_802C59D0(char* buf, Unk802C59D0_Req* o)
{
    return fn_802C5970(buf, o->m2C - 0x385, o->m34, o->m3C, o->m38);
}

void fn_802C5A08(int, Unk802C58E0_Slot* o, Unk802C59D0_Req* req)
{
    char buf[0x40];
    fn_802C59D0(buf, req);
    int h = fn_802B98AC((int)buf, 0x500);
    fn_803FFA60(o->m4, h, fn_803EE310(h));
    fn_80433004(o->m4, 0x4070);
    fn_803EDA0C(h);
    o->m0 = fn_803EBD14(o->m4, lbl_805E15E0);
}

void fn_802C60A4(int, Unk802C60A4_Key* k, Unk802C60A4_Rgb* out)
{
    unsigned char* e = fn_802C3A2C(k->m0, k->m4);
    if (e) {
        *out = lbl_805E2256[e[2]];
    }
}

/* near-miss (9 slots): retail keeps o in r11 (mr r11,r3) and loads o->m234 straight into the return register in the shared tail. */
Unk802C2188* fn_802C610C(Unk802C3B60* o, Unk802C610C_Cfg* c, int flag)
{
    if (flag == 0 && c->m68 == 0xE) {
        return &o->s2;
    }
    if (c->m80 != 0 || (lbl_8061D464 != 0 && lbl_80620830 != 0 && o->m234 != 0 && c->m64 == 0 && c->m68 == 8)) {
        Unk802C2188* t = o->m234;
        if (t != 0) {
            return t;
        }
        return (Unk802C2188*)o;
    }
    if (c->m64 == 1) {
        return &o->s1;
    }
    return (Unk802C2188*)o;
}

void fn_802C63B4(const char* name, const char* b, int* out1, int* out2)
{
    int h = fn_802B9300(name, 0x400, 1, 0);
    *out1 = h;
    *out2 = fn_803EBD14(h, b);
}

void fn_802C6404(Unk802C3B60* o)
{
    char buf[0x40] = "";
    fn_804089B4(buf, lbl_805E1628, lbl_805DFC34);
    int h = fn_802B9300(buf, 0x400, 1, 0);
    o->m254 = h;
    o->m26C = fn_803EBD14(h, lbl_805E158C);
    o->m270 = fn_803EBD14(o->m254, lbl_805E1594);
    fn_802C63B4(lbl_805E1644, lbl_805E159C, &o->m258, &o->m274);
    fn_802C63B4(lbl_805E166C, lbl_805E15A4, &o->m25C, &o->m278);
    fn_802C63B4(lbl_805E1690, lbl_805E16B8, &o->m260, &o->m27C);
    fn_802C63B4(lbl_805E16C0, lbl_805E16E8, &o->m264, &o->m280);
    fn_802C63B4(lbl_805E16F0, lbl_805E15BC, &o->m268, &o->m284);
}

void fn_802C6B70()
{
}

unsigned fn_802C6B74(unsigned r, unsigned g, unsigned b)
{
    return ((r << 8) & 0xF800) | ((g << 3) & 0x7E0) | ((b >> 3) & 0x1F);
}

unsigned fn_802C6B8C(unsigned r, unsigned g, unsigned b)
{
    return (r << 16) | 0xFF000000 | (g << 8) | b;
}

struct Unk802C6BA4_Tex {
    char pad0[4];
    short m4;
    short m6;
    char pad8[4];
    unsigned int mC;
    int m10;
};
unsigned char* fn_803EC1C0(void* tex, int x, int y, int z);
Unk802C6BA4_Tex* fn_803EBF90(void* tex);
int fn_803EC6F8(void* tex);

/* near-miss (129/129 insns, 125 words equal): in the format-8 index search retail keeps p in r11, idx in r10 and the byte offset in r9 (formed after p); ours r9/r11/r11 */
void fn_802C6BA4(Unk802C6BA4_Tex* tex, int fmt)
{
    int w = tex->m4;
    int h = tex->m6;
    switch (fmt) {
    case 0xDE3: {
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                *(short*)fn_803EC1C0(tex, x, y, 0) = 0;
            }
        }
        break;
    }
    case 8: {
        int y = 0;
        Unk802C6BA4_Tex* t = fn_803EBF90(tex);
        int idx = -1;
        for (; y < t->m4; y++) {
            int o = y * 2;
            char* p;
            if (t->mC & 0x10000000)
                p = (char*)t + t->m10;
            else
                p = (char*)t + 0x10;
            if ((*(unsigned short*)(p + o) & 0xF000) == 0) {
                idx = y;
                break;
            }
        }
        unsigned char v = idx;
        for (y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                *fn_803EC1C0(tex, x, y, 0) = v;
            }
        }
        fn_80433004((int)tex, fn_803EC6F8(tex));
        break;
    }
    case 0xF:
    case 0x10: {
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                *(short*)fn_803EC1C0(tex, x, y, 0) = 0;
            }
        }
        break;
    }
    case 0x20: {
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                *(int*)fn_803EC1C0(tex, x, y, 0) = 0;
            }
        }
        break;
    }
    }
}

struct Unk802C72F4_Tex {
    char pad0[0xC];
    unsigned int mC;
    int m10;
};

int fn_803EBBA4(int a, int b, int c, int d, int e, int f, int g, int h);
Unk802C72F4_Tex* fn_803EBF90();
int fn_803EC984(int h);
void fn_803EC054(int h);
void fn_802C6BA4(int a, int b);

/* near-miss (51 vs 52 insns): retail copies the fn_803EC984 result into a second callee-saved register after fn_803EC054 (mr r31,r30) and returns that copy */
int fn_802C72F4(int a, int b, int c)
{
    int n = 8;
    if (c > 0)
        n = c;
    int h;
    if (n == 8) {
        h = fn_803EBBA4(a, b, 8, 0xF, 0, 0x500, 0, 0);
        Unk802C72F4_Tex* t = fn_803EBF90();
        int* p;
        if (t->mC & 0x10000000)
            p = (int*)((char*)t + t->m10);
        else
            p = (int*)((char*)t + 0x10);
        *p = 0;
    } else {
        h = fn_803EBBA4(a, b, n, 0, 0, 0x500, 0, 0);
    }
    int r = fn_803EC984(h);
    fn_803EC054(h);
    fn_802C6BA4(r, n);
    return r;
}
