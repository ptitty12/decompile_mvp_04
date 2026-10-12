/*
 * Game code, .text 0x800E0164-0x800E4234 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800E0164.h"

float fn_800E0164(float f)
{
    float r = fn_8033CDC4(lbl_8068B4C0, f);
    if (r > 1.0f)
        r = 1.0f;
    else if (!(r >= 0.0f))
        r = 0.0f;
    return r;
}

int fn_800E01C8(float f)
{
    int r = (int)(f * lbl_805BDBB8 + lbl_805BDBBC);
    if (r > 0x63) {
        r = 0x63;
    }
    return r;
}

int fn_800E0208(int a, unsigned int b)
{
    if (a == 12 || a == 14 || a == 15 || a == 16 || a == 17 || a == 18 || a == 19 || a == 20 || a == 21) {
        if (b <= 15) {
            return lbl_805C3B80[b];
        }
        return 0;
    }
    return b;
}

int fn_800E027C(int a, unsigned int b)
{
    if (a == 1 || a == 2 || a == 7 || a == 12 || a == 17 || a == 22) {
        if (b <= 15) {
            return lbl_805C3B80[b];
        }
        return 0;
    }
    return b;
}

void fn_800E02D4(UiS* self)
{
    ((UiSub*)((char*)self + 0xDC))->v15();
    for (int i = 0; i <= 15; i++)
        ((UiVD*)self)->v51(lbl_805C3BC0[i], i);
    ((UiSub*)((char*)self + 0xDC))->v6(5);
}

extern "C" void fn_800E0AD4(UiS* self, int a1, int a2, int a3, int a4)
{
    UiS* w1 = fn_800C8060(self->v32(lbl_805BDBF4, 1));
    UiS* w2 = fn_800C8060(self->v32(lbl_805BDC04, 1));
    int o = 0;
    int s = 5;
    fn_800DC3D8(&o, &s, a1);
    if (fn_800DC0F4((char*)o, s, a1) != 0) {
        w1->v8(0);
        w2->v8(1);
        fn_800E1388(self, a1, a3, a4);
        return;
    }
    w1->v8(1);
    w2->v8(0);
    fn_800E0C38(self, a1, a2, a3);
}

int fn_800E18B0(int x)
{
    return fn_800E1B68(fn_80075D80(x));
}

int fn_800E18D4(int x)
{
    return fn_800E18F8(fn_800B5520(x));
}

int fn_800E18F8(int i)
{
    return lbl_805C2F00[i];
}

int fn_800E190C(int x)
{
    return fn_800E1930(fn_800B5520(x));
}

int fn_800E1930(int i)
{
    return lbl_805C30F0[i];
}

int fn_800E1944(int x)
{
    return fn_800E1968(fn_800B5520(x));
}

int fn_800E1968(int i)
{
    return lbl_805C32E0[i];
}

int fn_800E197C(int i)
{
    return lbl_805C34D0[i];
}

int fn_800E1990(int x)
{
    if (x <= 0x1F) {
        return 0;
    }
    if (x <= 0x3D) {
        return 1;
    }
    if (x <= 0x5B) {
        return 2;
    }
    if (x <= 0x79) {
        return 3;
    }
    return 0;
}

int fn_800E19CC(int x)
{
    int r = 0;
    if (fn_800E1990(x) == 0 && x != 0x1E && x != 0x1F) {
        r = 1;
    }
    return r;
}

void fn_800E1A1C(int a, unsigned short* dst)
{
    int base = lbl_8061977C;
    int v = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B8C4(0, a);
    int w = fn_80084114(v);
    unsigned short* s1 = fn_80090880(base, 0x2337);
    unsigned short* s2 = fn_80090880(base, fn_800E190C(a));
    unsigned short* s3 = fn_80090880(base, fn_80083F6C(w));
    unsigned short buf[0x20];
    fn_8040321C(buf, s1, s2, s3);
    fn_80403144(dst, buf);
}

int fn_800E1AC8(int i)
{
    return lbl_805C36C0[i];
}

/* near-miss: retail shares the tail of the 0x20 and 0x3E table cases and lays the 0x7A case out inline (9 slots) */
int fn_800E1ADC(int x)
{
    if (x <= 0x1F) {
        return lbl_805C3990[x];
    }
    if (x <= 0x3D) {
        return lbl_805C3A10[x - 0x20];
    }
    if (x <= 0x5B) {
        return lbl_805C3A88[x - 0x3E];
    }
    if (x > 0x79) {
        return lbl_805C3B78[x - 0x7A];
    }
    return lbl_805C3B00[x - 0x5C];
}

int fn_800E1B68(int i)
{
    return lbl_805C38B0[i];
}

int fn_800E2400(int x)
{
    switch (x) {
    case 30:
        return 0x7E5;
    case 31:
    case 33:
        return 0x7E4;
    case 32:
        return 0x7D6;
    case 34:
        return 0x7D1;
    case 35:
        return 0x7E7;
    case 36:
        return 0x3EB2;
    case 37:
    case 39:
        return 0x5D2E;
    case 38:
        return 0x7D9;
    case 40:
        return 0x7ED;
    case 41:
        return 0x7EC;
    case 42:
        return 0x7DB;
    case 43:
        return 0x7E8;
    case 44:
        return 0x7D7;
    case 45:
        return 0x7E2;
    }
    return -1;
}

int fn_800E24F4(int x)
{
    switch (x) {
    case 30:
        return 0x44E6;
    case 31:
    case 33:
        return 0x44E5;
    case 32:
        return 0x44D7;
    case 34:
        return 0x44DC;
    case 35:
        return 0x44E8;
    case 36:
        return 0x44EC;
    case 37:
    case 39:
        return 0x5D2F;
    case 38:
        return 0x44DA;
    case 40:
        return 0x44DD;
    case 41:
        return 0x44E3;
    case 42:
    case 45:
        return 0x44ED;
    case 43:
        return 0x44E9;
    case 44:
        return 0x44D8;
    }
    return -1;
}

/* near-miss: 1 call differs: retail sets r3 before the other arguments of s->fn_8007CF44, which needs the method declared void (tu_8007CAC4.cpp defines it int) */
void fn_800E25E0(int a, int b)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int h = s->fn_8007DA28();
    if (h != -1) {
        char buf[0x18];
        s->fn_8007CF44(h, (int)buf, 0);
        fn_801254EC(a, 1, 3, buf, b);
        if (s->fn_8007DADC(h) != 0) {
            fn_80125C84(a, 1);
            fn_80125CF8(a);
            return;
        }
        fn_80125C84(a, 0);
        return;
    }
    fn_80125C84(a, 0);
    fn_80125490(a, 1, 3, 0x3FB4, b);
}

struct Ue26B4_Scr {
    void fn_8007CF44(unsigned i, int a, int b);
};
class Ue26B4_S {
public:
    char pad0[0x24];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20(int a, int b);
};
class Ue26B4_P {
public:
    char pad0[0x3C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30(const char* s);
};
UiS* fn_800C8054(UiS* p);
extern char lbl_805BDC84[];
extern char lbl_805BDD84[];
extern char lbl_805BA714[];
extern char lbl_805BDD8C[];
extern char lbl_805BC1A8[];
extern "C" int sprintf(char*, const char*, ...);
void fn_800E1A1C(int a, unsigned short* dst);

extern "C" void fn_800E26B4(int sel, UiS* self)
{
    char b8[0x40];
    char b48[0x10];
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    UiS* w1 = (UiS*)fn_800C8040(self->v32(lbl_805BDC84, 1));
    UiS* w2 = (UiS*)fn_800C8040(self->v32(lbl_805BDD84, 1));
    UiS* w3 = (UiS*)fn_800C8040(self->v32(lbl_805BA714, 1));
    UiS* w4 = fn_800C8054(self->v32(lbl_805BDD8C, 1));
    if (sel == -1) {
        w1->v28((char*)fn_80090880(lbl_8061977C, 0x3FB5));
        w2->v28((char*)fn_80090880(lbl_8061977C, 0x1A4B));
        w3->v28((char*)fn_80090880(lbl_8061977C, 0x1A4B));
        w4->v8(0);
    } else {
        ((Ue26B4_Scr*)sc)->fn_8007CF44(sel, (int)b8, 0);
        w1->v28(b8);
        int val = sc->fn_8007D098(sel, 0);
        fn_800E1A1C(val, (unsigned short*)b8);
        w2->v28(b8);
        sprintf(b48, lbl_805BC1A8, sc->fn_8007D050(sel, 8));
        ((Ue26B4_P*)w3)->s30(b48);
        ((Ue26B4_S*)((char*)w4 + 0x98))->s20(val, 0);
        w4->v8(1);
    }
}

void fn_800E2944(int a, int b)
{
    int o = lbl_8061930C;
    fn_8007DA58(o, a);
    int r = fn_80075C64(o, a);
    fn_8007DA8C(o, b, a);
    if (r != b && r <= 3 && a != -1) {
        fn_8007DA8C(o, r, -1);
    }
}

/* near-miss: 3 slots, order of the constant loads (li 1 / lis 0x20 / li 0) before the three stores */
void fn_800E29CC(int a)
{
    if (a != -1) {
        Ui800B555C_B* p = (Ui800B555C_B*)((char*)fn_800B555C() + 8);
        p->m4D0 = (int)fn_80090880(lbl_8061977C, 0x60D);
        p->m4C8 = 0x200000;
        p->m4CC = 0;
        p->m4C4 = 1;
        void* s = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007CFDC(a);
        fn_800B555C()->m4E8 = s;
        fn_8007DB74((Unk8007B2B0_Screen*)lbl_8061930C, a);
    }
}

void fn_800E2A58(int unused)
{
    char* nm = lbl_805BB0FC;
    int i = 0;
    fn_802B91C0();
    int g = lbl_8061E978;
    fn_802B03F4(g);
    int p = fn_802B9804((int)nm, 0x100);
    int n = fn_803FC4C0();
    int d = n / 11;
    char buf[0x80];
    float f1 = lbl_805BDD94;
    float f2 = lbl_805BDD98;
    int sp90;
    fn_803FED48((int)nm, 0x100, 0, &sp90);
    for (; i < n; i++) {
        fn_802B0388(g, fn_803FC548(p, i, buf), 1);
        if (i % d == 1) {
            f1 += f2;
            fn_80316614((int)lbl_8061FEDC, 4, f1);
        }
    }
    fn_803FEDB8(sp90, 0x64);
    if (p != 0)
        fn_80377488(p);
    fn_802B9218();
}

int fn_800E2B84()
{
    return fn_802B041C(lbl_8061E978);
}

int fn_800E2BAC()
{
    return fn_800E2B84();
}

void fn_800E2BCC()
{
    fn_8001BC4C()->fn_8001BDAC(0xB2);
    fn_800E2A58(0x500);
    fn_8001BC4C()->fn_8001BDAC(0xB1);
}

int fn_800E2C08()
{
    fn_800E2D8C(lbl_805BA54C);
    return fn_800E2B84();
}

void fn_800E2C34()
{
    fn_8001BC4C()->fn_8001BDAC(0xB2);
    fn_800E2C80(lbl_805BA54C, 0x400);
    fn_800E2A58(0x500);
    fn_8001BC4C()->fn_8001BDAC(0xB1);
}

void fn_800E2C80(char* a, int b)
{
    int g = lbl_8061E978;
    int p = fn_802B9804((int)a, 0x100);
    int n = fn_803FC4C0();
    if (fn_8040B574(a, lbl_805BA560) == 0) {
        fn_80149F70(p, 2);
        fn_8014A0EC();
    } else if (fn_8040B574(a, lbl_805BA54C) == 0) {
        fn_80149F70(p, 1);
        fn_8014A0EC();
    }
    char buf[0x80];
    int sp88;
    fn_803FED48((int)a, 0x100, 0, &sp88);
    for (int i = 0; i < n; i++)
        fn_802B0140(g, fn_803FC548(p, i, buf), 1, b, 0);
    fn_803FEDB8(sp88, 0x64);
    if (p != 0)
        fn_80377488(p);
}

void fn_800E2D8C(char* a)
{
    int g = lbl_8061E978;
    int p = fn_802B9804((int)a, 0x100);
    int n = fn_803FC4C0();
    if (fn_8040B574(a, lbl_805BA560) == 0) {
        fn_80149F70(p, 2);
        fn_8014A0EC();
    } else if (fn_8040B574(a, lbl_805BA54C) == 0) {
        fn_80149F70(p, 1);
        fn_8014A0EC();
    }
    char buf[0x80];
    int sp88;
    fn_803FED48((int)a, 0x100, 0, &sp88);
    for (int i = 0; i < n; i++)
        fn_802B0638(g, fn_803FC548(p, i, buf), 1);
    fn_803FEDB8(sp88, 0x64);
    if (p != 0)
        fn_80377488(p);
}

int fn_800E2E8C(void* t, int idx, int b, int c)
{
    char* e = lbl_806192E0->m4->m14 + idx * 0xE64;
    int r = fn_80097210(e, 0);
    if (r != b || c != 0)
        fn_800E2F24(t, e, r);
    fn_800E31A8(t, e, r);
    fn_800E3D4C(t, r);
    return r;
}

class Ue31A8_P {
public:
    char pad0[0x3C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual int s30(const char* s, int a);
};
class Ue31A8_W {
public:
    char pad0[0x3C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44(int a, int b, char* c, int d);
};
extern "C" int fn_800968C0(int g, int b, int c);
extern "C" float fn_80097B60(int g, int a, int t, int c, int d);
extern "C" int fn_80097A9C(int g, int a, int t, int c, int d);
extern "C" int fn_8009764C(int g, int a, int t, int c);
extern "C" void fn_80099B7C(int g);
extern "C" int fn_800DC580(UiS* w);
extern char lbl_805BDDA8[];
extern char lbl_805BC1A8[];
extern char lbl_805BC180[];
extern "C" int sprintf(char*, const char*, ...);

extern "C" int fn_800C33D0();
int fn_800DE440(char* out, int a, int b);
extern "C" void fn_800C3ED4(int h, int a, int b);
extern "C" int fn_80097318(int a, int b);
extern "C" int fn_80097380(int a, int b);
extern "C" int fn_800973E8(int a, int b);
extern "C" int fn_80097450(int a, int b);
extern "C" int fn_800974B8(int a, int b);
extern char lbl_805BDC38[];
extern char lbl_805BDC40[];
extern char lbl_805BDD9C[];

extern "C" void fn_800E2F24(UiS* self, int a1, int a2)
{
    char buf[200];
    int h = fn_800C33D0();
    fn_800C3ED4(h, (int)fn_800C8038((UiS*)self->v32(lbl_805BDC38, 1)), a2);
    fn_800DE440(buf, a2, 3);
    ((UiS*)fn_800C8040(self->v32(lbl_805BDD9C, 1)))->v28(buf);
    if (fn_80097318(a1, a2) == 1) {
        ((UiS*)fn_800C8040(self->v32(lbl_805BDC40, 1)))->v29(0xE80);
    } else if (fn_80097380(a1, a2) == 1) {
        ((UiS*)fn_800C8040(self->v32(lbl_805BDC40, 1)))->v29(0xE83);
    } else if (fn_800973E8(a1, a2) == 1) {
        ((UiS*)fn_800C8040(self->v32(lbl_805BDC40, 1)))->v29(0xE84);
    } else if (fn_80097450(a1, a2) == 1) {
        ((UiS*)fn_800C8040(self->v32(lbl_805BDC40, 1)))->v29(0xE85);
    } else if (fn_800974B8(a1, a2) == 1) {
        ((UiS*)fn_800C8040(self->v32(lbl_805BDC40, 1)))->v29(0xE7F);
    } else {
        ((UiS*)fn_800C8040(self->v32(lbl_805BDC40, 1)))->v29(0xE88);
    }
}

extern "C" int fn_800E31A8(UiS* self, int g, int a2)
{
    char buf[0x68];
    unsigned char t = fn_800968C0(g, a2, 1);
    int v0 = (int)fn_80097B60(g, 0, t, 2, 0);
    int v1 = fn_80097A9C(g, 2, t, 2, 0);
    int v2 = fn_8009764C(g, 6, t, 0);
    int v3 = fn_80097A9C(g, 7, t, 2, 0);
    int v4 = fn_80097A9C(g, 0, t, 2, 0);
    Ue31A8_W* w = (Ue31A8_W*)fn_800C8060(self->v32(lbl_805BDDA8, 1));
    sprintf(buf, lbl_805BC1A8, v0);
    w->s44(0, 1, buf, 4);
    sprintf(buf, lbl_805BC1A8, v1);
    w->s44(1, 1, buf, 4);
    sprintf(buf, lbl_805BC1A8, v2);
    w->s44(2, 1, buf, 4);
    sprintf(buf, lbl_805BC1A8, v3);
    w->s44(3, 1, buf, 4);
    sprintf(buf, lbl_805BC1A8, v4);
    w->s44(4, 1, buf, 4);
    int r = ((Ue31A8_P*)self)->s30(lbl_805BC180, 1);
    if (r != 0) {
        UiS* x = fn_800C8044((UiS*)r);
        fn_80099B7C(g);
        r = fn_800DC580(x);
    }
    return r;
}

class Ue3FE0_W {
public:
    char pad0[0x3C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43(int a, int b, char* c, int d);
    virtual void s44(int a, int b, char* c, int d);
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101(int a, int b);
};
extern "C" int fn_80077BC4(void* g, int a);
extern "C" int fn_80084014(int a, int b);
extern "C" float fn_800748D4(int s, int a, int b, int c);
extern "C" void fn_80119FF0(char* buf, float f);
extern "C" int fn_800DB9A8(int o, int a, int s, int g);
extern "C" float fn_8007824C(int a, int b);
extern "C" int sprintf(char*, const char*, ...);
extern char lbl_805BDDEC[];
extern char lbl_805BD07C[];
extern char lbl_805BDBC8[];

void fn_800E3FE0(UiS* self, int slot, int g, int k)
{
    char text[0x190];
    char name[200];
    int* gp = &lbl_8061930C;
    int o = 0;
    int s = 5;
    Ue3FE0_W* w = (Ue3FE0_W*)self;
    fn_800DC3D8(&o, &s, g);
    fn_800DE440(name, g, 1);
    w->s43(slot, 0, name, 5);
    int r1 = fn_80077BC4((void*)*gp, g);
    int t = fn_80084014(((Unk8007B2B0_Screen*)*gp)->fn_80078A38(r1), 1);
    int v3 = ((Unk8007A4DC_Screen*)*gp)->fn_80074754(3, g, t);
    int v4 = ((Unk8007A4DC_Screen*)*gp)->fn_80074754(4, g, t);
    sprintf(text, lbl_805BDDEC, v3, v4);
    w->s44(slot, 1, text, 5);
    float f = fn_800748D4(*gp, 1, g, t);
    fn_80119FF0(text, f);
    w->s44(slot, 2, text, 5);
    int a = fn_800DB9A8(o, 0x1B, s, g);
    int b = fn_800DB9A8(o, 0, s, g);
    sprintf(text, lbl_805BD07C, a, b);
    w->s44(slot, 3, text, 5);
    float x = fn_800E0164(fn_8007824C(g, 0));
    sprintf(text, lbl_805BDBC8, x);
    w->s44(slot, 4, text, 4);
    w->s101(slot, k);
}
