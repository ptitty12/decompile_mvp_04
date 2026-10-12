/*
 * Game code, .text 0x80137FFC-0x8013BE4C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"

#include "game/tu_8001B190.h"

/* Second base object at +0xDC of the list/spinner controls: vptr at +0x24 of that base (+0x100). */
struct UnkDC_Data {
    char pad0[0x24];
};
struct UnkDC : UnkDC_Data {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual int fn_vslot5();
    virtual void fn_vslot6(int a);
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20(int a, int b);
};
struct Unk80139ADC_Data {
    char pad0[0xC];
    int mC;
    char pad10[0x14];
};
struct Unk80139ADC_Sub : Unk80139ADC_Data {      /* sub-object at +0x98 of the +0x15C object; vptr at +0x24 */
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20(int a, int b);
    virtual int fn_vslot21();
};
struct Unk80139ADC_Obj {
    char pad0[0x98];
    Unk80139ADC_Sub m98;
};
struct Unk80137FFC_M134 {
    int m0;
};
struct Unk80138080_Node {
    int m0;
    int m4;
    Unk80138080_Node* m8;
};
/* Front-end screen class of this unit (base ctor fn_800EC648). */
struct Unk80137FFC : Unk800C7B40_Widget {
    Unk80138080_Node* m40;
    char pad44[0xEC];
    int m130;
    Unk80137FFC_M134* m134;
    int m138;
    Unk800C7B40_Widget* m13C;
    Unk800C7B40_Widget* m140;
    Unk800C7B40_Widget* m144;
    Unk800C7B40_Widget* m148;
    Unk800C7B40_Widget* m14C;
    Unk800C7B40_Widget* m150;
    Unk800C7B40_Widget* m154;
    int m158;
    Unk80139ADC_Obj* m15C;
    char pad160[0x4];
    int m164;
    int m168;
    int m16C;
    char pad170[0x4];
    int m174;
    char pad178[0x164];
    int m2DC;
    int m2E0;
    int m2E4;
    int m2E8;
    int m2EC;
    char pad2F0[0x2E8];
    int m5D8;
    int m5DC;
    int m5E0;
};
typedef Unk80137FFC Scr;


struct Unk800B555C {
    char pad0[4];
    int m4;
    char pad8[0x54C];
    int m554;
    char pad558[0x120];
    int m678;
    int m67C;
};
struct Unk80138854_Mgr_Unused;
struct Unk80139034_Mgr {
    int m0;
    struct Unk80139034_Slot {
        char pad0[0x14];
        int m14;
    }* m4;
    Unk80139034_Slot* m8;
};
struct Unk8061B8C0 {
    char pad0[0x24];
    int m24;
};
extern Unk80139034_Mgr* lbl_806192E0;
extern Unk8061B8C0* lbl_8061B8C0;
extern int lbl_8061EE14;
extern const char* lbl_8061B5C4[];
extern const int lbl_805C1428[];
extern const char lbl_8064C2D0[];
Unk8001BC8C* fn_8001BC4C();
struct Unk800B7AB8_Ret {
    char pad0[0x14C];
    int m14C;
};
struct Unk8035682C_V {
    int m0;
    int m4;
    int m8;
};
struct Unk8061A32C {
    char padB8[0xB8];
    int mB8;
    int mBC;
};
extern Unk8061A32C* lbl_8061A32C;
extern const char lbl_805BAECC[];
extern const char lbl_8064DE38[];
extern const char lbl_80654F50[];
static inline Unk8061A32C* FE();
struct Unk80138854_Obj {
    char pad0[0x6C];
    int m6C;
    int m70;
};
struct Unk80138854_Inner {
    char pad0[0x10];
    Unk80138854_Obj* m10;
};
struct Unk80138854_Mgr {
    int m0;
    Unk80138854_Inner* m4;
};
extern const char lbl_805BE138[];
extern const char lbl_805C0D30[];
extern const char lbl_80657EA0[];
extern int lbl_8061977C;
extern "C" {
int fn_8011AB48(int a);
Unk800C7B40_Widget* fn_800C8040(Unk800C7B40_Widget* p);
char* fn_80090880(int a, int b);
int fn_80403DE4(char* dst, const char* fmt, ...);
void fn_800EC1B8(void* x, int chrg);
Unk8061A32C* fn_800B64BC(void* p);
Unk800B7AB8_Ret* fn_800B7AB8(Unk8061A32C* m, const char* name);
void fn_800B7B4C(Unk8061A32C* m, void* v, Scr* x);
void fn_8035682C(void* v);
void fn_800ECAA4(void* x);
void fn_802D7ADC();
void fn_8013B0AC(Scr* x);

Unk800B555C* fn_800B555C();
void* fn_800C33D0();
void fn_800C3BE0();
void fn_800ED254(void* x);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
char* fn_8040B830(char* dst, const char* src, int n);
int fn_8057CE00(int a);
void fn_8013B3DC(Scr* x);

void fn_801399A8(Scr* x);
void fn_80138948(Scr* x);
void fn_802D7ACC();
void fn_80081004(int a, int b, int c);
void fn_800DD800(int a, void* b, int c, int d);
}
static inline Unk8061A32C* FE()
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    return lbl_8061A32C;
}
extern void* lbl_8061930C;
extern const char lbl_805BA6D8[];
extern "C" {
int fn_8007F7D0(void* g, int a);
int fn_80075948(void* g, int a);
void fn_80138128(Scr* x, Unk80138080_Node* n);
void fn_80138854(Scr* x);
void fn_801389A4(Scr* x, int v);
void fn_800EC150(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_800D0074(void* p, int a, int b);
Unk800C7B40_Widget* fn_800B7A94(Unk8061A32C* m, const char* name);
void fn_80131F34(Unk800C7B40_Widget* o, Scr* x, void (*f)(), void (*g)(), int a, int b, int c, int d, int e, int h, int i, int j, int k, int l);
void fn_8013BBEC();
void fn_80147CF4();
}
struct Unk8013BE4C_DCOwner;
extern const char lbl_805C0D18[];
extern const char lbl_805C0D28[];
extern const char lbl_805C0DFC[];
extern "C" {
int fn_800B57EC(Unk800B555C* s);
void fn_801386B4(Scr* unused, char* buf, int idx);

void fn_801395A0(Scr* x, int a);
void fn_80139760(Scr* x);
void fn_80139ADC(Scr* x);
void fn_801396B4(Scr* x, int a);
Unk800C7B40_Widget* fn_800C8058(Unk800C7B40_Widget* p);
}
extern "C" int fn_80138660(Scr* x);
extern const char lbl_805BDDB8[];
extern const char lbl_805BDD9C[];
extern "C" {
void* fn_8007DF5C(void* g, int a, int b, int c);
void fn_800E0C38(Unk800C7B40_Widget* w, void* o, int a, int b);
int fn_800DE440(char* buf, void* o, int a); /* tail-returns fn_800DE6A8 */
int fn_80139AD4(int i);
}
extern "C" Unk800C7B40_Widget* fn_800C8044(Unk800C7B40_Widget* p);
extern const char lbl_805BA6D0[];
extern "C" {
int fn_8007D464(void* g, int a, int b);
int fn_8007D38C(void* g, int a, int b);
int fn_8007D4AC(void* g, int a, int b);
int fn_8007D41C(void* g, int a, int b);
void fn_80125084(Unk800C7B40_Widget* w, int a);
void fn_80125180(Unk800C7B40_Widget* w, int a, int b);
}
extern const char lbl_805BAC44[];
extern "C" {
int fn_802D7CE0(int a, int b);
void fn_80138AFC(Scr* x);
void fn_80138B60(Scr* x, int a);
void fn_800EEB2C(Unk800C7B40_Widget* w);
}
/* Widget-like object with its vptr at +0x3C whose slot 30 takes just a name. */
struct Unk8013B218_Data {
    char pad0[0x3C];
};
struct Unk8013B218_W : Unk8013B218_Data {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual void fn_vslot28();
    virtual void fn_vslot29();
    virtual void fn_vslot30(const char* name);
};
extern const char lbl_805BC1A8[];
extern const char lbl_805BA714[];
extern const char lbl_805BD07C[];
extern const char lbl_805C1A7C[];
extern "C" {
int fn_8007D050(void* g, int a, int b);
int fn_8007D614(void* g, int a);
int fn_8007D658(void* g, int a);
int fn_8007D69C(void* g, int a);
int fn_8007D6E0(void* g, int a);
int fn_804089B4(char* dst, const char* fmt, ...);
}
extern const char lbl_805BF974[];
extern const char lbl_805C0E04[];
extern const char lbl_805C0E10[];
extern "C" {
int fn_8007AA84(void* g, int a, int b, int c);
unsigned fn_8007E0E4(void* g, int a, int b);

}
/* The screen seen through a vtable declaration where slot 40 takes no argument (r4 is left as is). */
struct Unk80139090_VData {
    char pad0[0x3C];
};
struct Unk80139090_V : Unk80139090_VData {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual void fn_vslot28();
    virtual void fn_vslot29();
    virtual void fn_vslot30();
    virtual void fn_vslot31();
    virtual void fn_vslot32();
    virtual void fn_vslot33();
    virtual void fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37();
    virtual void fn_vslot38();
    virtual void fn_vslot39();
    virtual void fn_vslot40();
};
extern const char lbl_805B955C[];

struct UnkW140 : Unk800C7B40_Widget {
    char pad40[0x100];
    Unk800C7B40_Widget* m140;
};
struct UnkW150 : Unk800C7B40_Widget {
    char pad40[0x110];
    Unk800C7B40_Widget* m150;
};
struct UnkW154 : Unk800C7B40_Widget {
    char pad40[0x114];
    Unk800C7B40_Widget* m154;
};

extern "C" void fn_80137FFC(Scr* x)
{
    fn_800ECAA4(x);
    if (x->m134 == 0 || x->m134->m0 == 0) {
        Unk8035682C_V v;
        Unk8035682C_V* p = &v;
        fn_8035682C(p);
        FE();
        fn_800B7B4C(lbl_8061A32C, p, x);
    }
}

extern "C" void fn_80138080(Scr* x)
{
    if (fn_800B555C()->m678 < 0) {
        x->m138 = fn_8007F7D0(lbl_8061930C, 0);
    } else {
        void* g = lbl_8061930C;
        x->m138 = fn_80075948(g, fn_800B555C()->m67C);
    }
    Unk80138080_Node* n = x->m40;
    if (n != 0) {
        do {
            fn_80138128(x, n);
            n = n->m8;
        } while (n != 0);
    }
    x->fn_vslot8(1);
}

extern "C" Scr* fn_801384B8(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, 0, c, d, e, f, g, h);
    self->SetVptr(lbl_8064C2D0);
    self->m130 = 0;
    return self;
}

extern "C" void fn_80138508()
{
    FE();
    fn_800B7AB8(lbl_8061A32C, lbl_805BAECC)->m14C = 1;
}

extern "C" void fn_80138568(Scr* x)
{
    char buf[16];
    char* p = buf;
    fn_8035682C(p);
    if (fn_800B555C()->m4 & 1) {
        int t = fn_800B57EC(fn_800B555C());
        if (t != 0) {
            fn_8040B830(p, lbl_805C0D18, 15);
            p[15] = 0;
        } else {
            fn_8040B830(p, lbl_805C0D28, 15);
            p[15] = t;
        }
    } else {
        fn_801386B4(x, p, fn_80138660(x));
    }
    x->fn_vslot80(1);
    FE();
    fn_800B7B4C(lbl_8061A32C, buf, x);
}

extern "C" int fn_80138660(Scr* x)
{
    int v = fn_800B555C()->m678;
    if (v >= 0) {
        return v + 0x39;
    }
    int r = 0x39;
    if (fn_8057CE00(0) == 3) {
        r = 0x3A;
    }
    return r;
}

extern "C" void fn_801386B4(Scr* unused, char* buf, int idx)
{
    int i = idx - 0x39;
    fn_8040B830(buf, *(const char**)((char*)lbl_8061B5C4 + i * 4), 15);
    buf[15] = 0;
}

extern "C" Scr* fn_80138704(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC150(self, a, 0, c, d, e, f, g, h);
    self->SetVptr(lbl_80657EA0);
    self->m2DC = 0;
    self->m2E0 = 0;
    self->m2E4 = 5;
    self->m2E8 = 5;
    self->m2EC = 5;
    fn_80138854(self);
    FE();
    if (lbl_8061A32C->mBC != 0) {
        fn_801389A4(self, 0);
    }
    return self;
}

extern "C" void fn_801387B0(Scr* x, int chrg)
{
    x->SetVptr(lbl_80657EA0);
    if (x->m2DC != 0) {
        int z = 0;
        lbl_8061EE14 = z;
    }
    FE();
    if (lbl_8061A32C->mB8 != 0 && x->m2E4 != 5) {
        fn_80138948(x);
    }
    fn_800EC1B8(x, chrg);
}

extern "C" void fn_80138854(Scr* x)
{
    FE();
    if (lbl_8061A32C->mB8 != 0) {
        x->m2E8 = fn_8011AB48(0);
        x->m2EC = fn_8011AB48(1);
    } else {
        Unk80138854_Obj* o = ((Unk80138854_Mgr*)lbl_806192E0)->m4->m10;
        x->m2E8 = o->m6C;
        x->m2EC = o->m70;
    }
}

extern "C" int fn_801388EC(Scr* x, int a)
{
    int r = 0;
    if (a == x->m2E4) {
        fn_80138948(x);
        x->fn_vslot87();
        r = 1;
    }
    return r;
}

extern "C" void fn_80138948(Scr* x)
{
    int s = x->m2E0;
    int z = 0;
    x->m2E4 = 5;
    lbl_8061EE14 = z;
    if (s == 0) {
        lbl_8061B8C0->m24 = z;
        fn_802D7ACC();
    }
    x->m2E0 = z;
}

extern "C" void fn_801389A4(Scr* x, int v)
{
    int t = v ^ 1;
    x->m2DC = t;
    lbl_8061EE14 = t;
}

extern "C" void fn_801389B8(Scr* x)
{
    if (!x->b0) {
        if (x->m2DC == 0) {
            int found = 0;
            if ((unsigned)x->m2E8 <= 3) {
                if (fn_802D7CE0(x->m2E8, 0) == 0) {
                    found = 1;
                    x->m2E4 = x->m2E8;
                }
            }
            if (found == 0) {
                if (x->m2EC >= 0) {
                    if (x->m2EC <= 3) {
                        if (fn_802D7CE0(x->m2EC, 0) == 0) {
                            found = 1;
                            x->m2E4 = x->m2EC;
                        }
                    }
                }
            }
            if (found != 0) {
                fn_80138AFC(x);
                fn_80138B60(x, x->m2E4);
                x->fn_vslot86();
                int one = 1;
                lbl_8061EE14 = one;
                FE();
                Unk800C7B40_Widget* w = fn_800B7A94(lbl_8061A32C, lbl_805BAC44);
                if (w != 0) {
                    fn_800EEB2C(w);
                }
            }
        }
    } else {
        if (lbl_8061B8C0->m24 == 0) {
            fn_80138AFC(x);
        }
    }
}

extern "C" void fn_80138AFC(Scr* x)
{
    if (x->m2E0 == 0 && lbl_8061B8C0->m24 != 0) {
        x->m2E0 = 1;
    } else {
        x->m2E0 = 0;
        lbl_8061B8C0->m24 = 1;
        fn_802D7ADC();
    }
}

extern "C" void fn_80138B60(Scr* x, int a)
{
    Unk800C7B40_Widget* w = fn_800C8040(x->fn_vslot32(lbl_805C0D30, 1));
    const char* fmt = fn_80090880(lbl_8061977C, 0x5D03);
    int n = a + 1;
    char buf[400];
    fn_80403DE4(buf, fmt, n, n);
    w->fn_vslot28(buf);
}

extern "C" Scr* fn_80138BFC(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80654F50);
    self->m130 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m5D8 = 1;
    self->m5DC = 0;
    return self;
}

extern "C" void fn_80138FF0(Scr* x)
{
    fn_800B555C()->m554 = x->m5DC;
    fn_800C33D0();
    fn_800C3BE0();
    fn_800ED254(x);
}

extern "C" void fn_80139034()
{
    Unk80139034_Mgr* g = lbl_806192E0;
    Unk80139034_Mgr::Unk80139034_Slot* b = g->m4;
    Unk80139034_Mgr::Unk80139034_Slot* a = g->m8;
    int v = fn_800B555C()->m554;
    fn_80081004(b->m14, v, 1);
    fn_80081004(a->m14, v, 1);
}

extern "C" void fn_80139090(Scr* x, int k)
{
    char buf[16];
    char* p = buf;
    fn_8035682C(p);
    switch (k) {
    case 0:
        fn_8040B830(p, lbl_805BE138, 15);
        p[15] = k;
        FE();
        fn_800B7B4C(lbl_8061A32C, p, x);
        break;
    case 1:
        fn_8040B830(p, lbl_805B955C, 15);
        p[15] = 0;
        FE();
        fn_800B7B4C(lbl_8061A32C, p, x);
        ((Unk80139090_V*)x)->fn_vslot40();
        break;
    }
}

extern "C" int fn_80139194(UnkW140* x)
{
    x->m140->fn_vslot40(1);
    return 1;
}

extern "C" int fn_801391D4(UnkW140* x, int a)
{
    x->m140->fn_vslot41(a);
    return 1;
}

extern "C" int fn_80139210(UnkW140* x)
{
    x->m140->fn_vslot38(1);
    return 1;
}

extern "C" int fn_80139250(UnkW140* x)
{
    x->m140->fn_vslot39();
    return 1;
}

extern "C" int fn_8013928C(UnkW154* x)
{
    x->m154->fn_vslot50();
    return 1;
}

extern "C" int fn_801392C8(UnkW154* x)
{
    x->m154->fn_vslot51();
    return 1;
}

extern "C" int fn_80139304(UnkW154* x)
{
    x->m154->fn_vslot52();
    return 1;
}

extern "C" int fn_80139340(UnkW154* x)
{
    x->m154->fn_vslot53();
    return 1;
}

extern "C" int fn_8013937C(UnkW150* x)
{
    x->m150->fn_vslot40(1);
    return 1;
}

extern "C" int fn_801393BC(UnkW150* x, int a)
{
    x->m150->fn_vslot41(a);
    return 1;
}

extern "C" int fn_801393F8(UnkW150* x)
{
    x->m150->fn_vslot38(1);
    return 1;
}

extern "C" int fn_80139438(UnkW150* x)
{
    x->m150->fn_vslot39();
    return 1;
}

extern "C" void fn_80139474(Scr* x, Unk800C7B40_Widget* a)
{
    if (a == x->m150) {
        fn_801395A0(x, ((Unk80139ADC_Sub*)((char*)x->m15C + 0x98))->fn_vslot21());
    } else if (a == x->m140) {
        UnkDC* d = (UnkDC*)((char*)fn_800C8058(a->fn_vslot32(lbl_805C0DFC, 1)) + 0xDC);
        fn_801396B4(x, d->fn_vslot5());
        fn_801395A0(x, ((Unk80139ADC_Sub*)((char*)x->m15C + 0x98))->fn_vslot21());
    }
    fn_80139760(x);
    fn_80139ADC(x);
}

extern "C" void fn_80139574(Scr* x, Unk800C7B40_Widget* a)
{
    if (a == x->m154) {
        fn_801399A8(x);
    }
}

extern "C" void fn_801395A0(Scr* x, int a)
{
    ((Unk80139ADC_Sub*)((char*)x->m15C + 0x98))->fn_vslot20(a, 0);
    ((Unk80139ADC_Sub*)((char*)x->m164 + 0x98))->fn_vslot20(a, 0);
    ((UnkDC*)((char*)x->m168 + 0xDC))->fn_vslot20(a, 0);
    ((Unk80139ADC_Sub*)((char*)x->m16C + 0x98))->fn_vslot20(a, 0);
    ((Unk80139ADC_Sub*)((char*)x->m174 + 0x98))->fn_vslot20(a, 0);
    x->m140->fn_vslot37(((Unk80139ADC_Sub*)((char*)x->m15C + 0x98))->mC);
}

extern "C" void fn_801396B4(Scr* x, int a)
{
    x->m140->fn_vslot37(a);
    fn_800D0074((char*)x->m15C + 0x98, a, 0);
    fn_800D0074((char*)x->m164 + 0x98, a, 0);
    fn_800D0074((char*)x->m168 + 0xDC, a, 0);
    fn_800D0074((char*)x->m16C + 0x98, a, 0);
    fn_800D0074((char*)x->m174 + 0x98, a, 0);
}

/* near-miss: 146/146 insns, 17 slots differ; retail keeps cnt/n/i/g in r23/r24/r25/r26 (here r24/r25/r27/r26), a callee-saved-register priority difference; the guarded while loop shape matches */
extern "C" void fn_80139760(Scr* x)
{
    unsigned i = 0;
    void* g = lbl_8061930C;
    x->m5DC = ((Unk80139ADC_Sub*)((char*)x->m15C + 0x98))->fn_vslot21();
    int cnt = x->m154->fn_vslot60();
    UnkDC* d = (UnkDC*)((char*)fn_800C8058(fn_800C8044(x->fn_vslot32(lbl_805BF974, 1))->fn_vslot32(lbl_805C0E04, 1)) + 0xDC);
    d->fn_vslot6(x->m5D8);
    unsigned n = fn_8007E0E4(g, x->m5DC, x->m5D8);
    {
        while (i < n) {
            char buf1[80];
            char buf2[36];
            unsigned next = i + 1;
            void* t = fn_8007DF5C(g, x->m5DC, x->m5D8, i);
            i = next;
            fn_800DE440(buf1, t, 1);
            x->m154->fn_vslot43(next, 0, buf1, 5);
            int a = fn_8007AA84(g, 0, (int)t, 0);
            fn_804089B4(buf2, lbl_805C0E10, a, fn_8007AA84(g, 0, (int)t, 1));
            x->m154->fn_vslot44(next, 1, buf2, 4);
        }
    }
    x->m154->fn_vslot105(1);
    x->m154->fn_vslot68(cnt);
    x->m154->fn_vslot14(1);
    fn_801399A8(x);
}

extern "C" void fn_801399A8(Scr* x)
{
    void* g = lbl_8061930C;
    int b = x->m5DC;
    int a = x->m5D8;
    int n = x->m154->fn_vslot60();
    n = n - x->m154->fn_vslot83();
    void* o = fn_8007DF5C(g, b, a, n);
    Unk800C7B40_Widget* w = fn_800C8044(x->fn_vslot32(lbl_805BDDB8, 1));
    fn_800E0C38(w, o, fn_80139AD4(x->m5D8), 1);
    char buf[200];
    fn_800DE440(buf, o, 1);
    fn_800C8040(w->fn_vslot32(lbl_805BDD9C, 1))->fn_vslot28(buf);
}

extern "C" int fn_80139AD4(int i) { return 1; }

extern "C" void fn_80139ADC(Scr* x)
{
    int r = ((Unk80139ADC_Sub*)((char*)x->m15C + 0x98))->fn_vslot21();
    fn_800DD800(x->m158, (char*)x + 0x178, r, 1);
}

extern "C" Scr* fn_80139B38(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8064DE38);
    self->m130 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    return self;
}

extern "C" void fn_80139EF4(Scr* x)
{
    fn_800ECAA4(x);
}

extern "C" int fn_8013A35C(Scr* x)
{
    char buf[16];
    char* p = buf;
    fn_8035682C(p);
    fn_8040B830(p, lbl_805BE138, 15);
    p[15] = 0;
    FE();
    fn_800B7B4C(lbl_8061A32C, p, x);
    return 1;
}

extern "C" int fn_8013A3E4(Scr* x)
{
    x->m14C->fn_vslot50();
    fn_8013B3DC(x);
    fn_8013B0AC(x);
    return 1;
}

extern "C" int fn_8013A43C(Scr* x)
{
    x->m14C->fn_vslot51();
    fn_8013B3DC(x);
    fn_8013B0AC(x);
    return 1;
}

extern "C" int fn_8013A494(Scr* x)
{
    x->m14C->fn_vslot52();
    fn_8013B3DC(x);
    fn_8013B0AC(x);
    return 1;
}

extern "C" int fn_8013A4EC(Scr* x)
{
    x->m14C->fn_vslot53();
    fn_8013B3DC(x);
    fn_8013B0AC(x);
    return 1;
}

extern "C" int fn_8013A544(Scr* x, Unk800C7B40_Widget* a, int b, int c)
{
    if (a == x->m14C) {
        a->fn_vslot68(c);
        fn_8013B0AC(x);
        return 1;
    }
    return 0;
}

extern "C" void fn_8013B0AC(Scr* x)
{
    FE();
    Unk800C7B40_Widget* w = fn_800B7A94(lbl_8061A32C, lbl_805BA6D0);
    int ok = 1;
    void* g = lbl_8061930C;
    int v = x->m14C->fn_vslot60();
    switch ((int)x->m134) {
    case 0:
        ok = 0;
        if (fn_8007D464(g, (int)x->m150, v) != 0 || v == 0x3D || v == 0x3E) {
            ok = 1;
        }
        break;
    case 1:
        ok = fn_8007D38C(g, (int)x->m150, v);
        break;
    case 2:
        ok = 0;
        if (fn_8007D4AC(g, (int)x->m150, v) != 0 || v == 0 || v == 1) {
            ok = 1;
        }
        break;
    case 3:
        ok = fn_8007D41C(g, (int)x->m150, v);
        break;
    }
    if (ok != 0) {
        fn_80125084(w, 0);
    } else {
        fn_80125180(w, 0, 0x416F);
    }
}

extern "C" void fn_8013B218(Scr* x)
{
    void* g = lbl_8061930C;
    char buf[400];
    fn_804089B4(buf, lbl_805BC1A8, fn_8007D050(g, (int)x->m150, 8));
    ((Unk8013B218_W*)fn_800C8040(((Unk800C7B40_Widget*)x->m138)->fn_vslot32(lbl_805BA714, 1)))->fn_vslot30(buf);
    int n;
    switch ((int)x->m134) {
    case 0:
        n = fn_8007D69C(g, (int)x->m150);
        fn_804089B4(buf, lbl_805BD07C, n, 0x3F);
        break;
    case 1:
        n = fn_8007D614(g, (int)x->m150);
        fn_804089B4(buf, lbl_805BD07C, n, 0x77);
        break;
    case 2:
        n = fn_8007D6E0(g, (int)x->m150);
        fn_804089B4(buf, lbl_805BD07C, n, 2);
        break;
    case 3:
        n = fn_8007D658(g, (int)x->m150);
        fn_804089B4(buf, lbl_805BD07C, n, 0xF);
        break;
    }
    ((Unk8013B218_W*)fn_800C8040(x->m140->fn_vslot32(lbl_805C1A7C, 1)))->fn_vslot30(buf);
}

extern "C" void fn_8013BB2C(Scr* x)
{
    FE();
    Unk800C7B40_Widget* o = fn_800B7A94(lbl_8061A32C, lbl_805BA6D8);
    fn_80131F34(o, x, fn_8013BBEC, fn_80147CF4, 0x4170, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    o->fn_vslot86();
}

extern "C" void fn_8013BBEC() {}

extern "C" int fn_8013BBF0(int a)
{
    for (int i = 0; i < 15; i++) {
        if (a == lbl_805C1428[i]) {
            return i;
        }
    }
    return -1;
}
