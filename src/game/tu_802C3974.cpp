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
void fn_802C4CB4(int a, int b, int c, int d);
void fn_802C51C0(int a, int b, int c, int d);
int fn_802C440C(Unk802C3B60* o, int* p, int x);

/* near-miss (7 slots): retail keeps the byte offset in r3 (also the return register), the table base in r11 and the second byte as (base + 1)[off]. */
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

unsigned char* fn_802C3A2C(int a, int b)
{
    unsigned char ua = a;
    unsigned char ub = b;
    int off = 0;
    for (int i = 0; i < 0x1AF; i++, off += 4) {
        if (lbl_805E1B9A[off] == ua && lbl_805E1B9A[off + 1] == ub) {
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
