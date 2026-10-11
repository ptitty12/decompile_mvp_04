/*
 * Game code, .text 0x8013BE4C-0x8014013C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"

#include "game/tu_8001B190.h"

/* Object with its vptr at +0x3C whose slots 28 and 30 take just a name. */
struct Unk8013C7C0_Data {
    char pad0[0x3C];
};
struct Unk8013C7C0_W : Unk8013C7C0_Data {
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
    virtual void fn_vslot28(const char* name);
    virtual void fn_vslot29();
    virtual void fn_vslot30(const char* name);
    virtual const char* fn_vslot31();
};
/* Front-end text-entry screen of this unit (base ctor fn_800EC150). */
struct Unk8013BE4C : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    Unk800C7B40_Widget* m138;
    int m13C;
    int m140;
    unsigned char m144;
    char pad145[0x3];
    int m148;
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    int m168;
    int m16C;
    int m170;
    int m174;
    int m178;
    int m17C;
    int m180;
    int m184;
    int m188;
    Unk800C7B40_Widget* m18C;
    int m190;
    int m194;
    int m198;
    int m19C;
    int m1A0;
    int m1A4;
    Unk800C7B40_Widget* m1A8;
    int m1AC;
    int m1B0;
    int m1B4;
    int m1B8;
    int m1BC;
    int m1C0;
    int m1C4;
    int m1C8;
    int m1CC;
    int m1D0;
    int m1D4;
    int m1D8;
    char pad1DC[0x100];
    Unk8013C7C0_W* m2DC;
    int m2E0;
    char pad2E4[0xC4];
    Unk800C7B40_Widget* m3A8;
    void (*m3AC)();
    int m3B0;
    int m3B4;
    int m3B8;
    int m3BC;
    int m3C0;
    int m3C4;
    int m3C8;
    Unk800C7B40_Widget* m3CC;
    int m3D0;
    int m3D4;
    int m3D8;
    int m3DC;
    int m3E0;
    int m3E4;
};
typedef Unk8013BE4C Scr;
struct Unk8061A32C {
    char padC0[0xC0];
    int mC0;
};
extern Unk8061A32C* lbl_8061A32C;
static inline Unk8061A32C* FE();
struct Unk8013C340_B;

Unk8001BC8C* fn_8001BC4C();
extern const char lbl_805B6F58[];
extern const char lbl_806561F0[];
extern const unsigned char lbl_805B6F58_b[];
extern "C" {
void fn_80403144(unsigned short* dst, const char* src);
int fn_8014188C(Scr* x, int a);
void* fn_800B8144();
void fn_800B83F8(void* p, int a, int b);
Unk8061A32C* fn_800B64BC(void* p);
int fn_80403060(const char* s);
void fn_800ECAA4(void* x);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_800EC150(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
Unk800C7B40_Widget* fn_800C8048(Unk800C7B40_Widget* p);
void fn_8013CD30(Scr* x, Unk800C7B40_Widget* w);
void fn_8013D0E0(Scr* x, const char* s);
void fn_8013D164(Scr* x, int a);
void fn_8013C0A8(Scr* x, int a, int b, int c);
void fn_800EC84C(void* x);
void fn_800C5E28();
void fn_800C6604();
void fn_800C618C();
void fn_800C5080();
void fn_800C5B58();
void fn_800C5EB0();
void* fn_800C33D0();
void fn_800C3BE0();
void fn_800ED254(void* x);
void fn_8013CB70(Scr* x, int a);
void fn_8013C5C8(Scr* x);
void fn_8013C8E4(Scr* x, int a);
void fn_8013C014(Scr* x);
void fn_8013D200(Scr* x);
}
extern const char lbl_8064B798[];
extern "C" void fn_8013C7C0(Scr* x);
static inline Unk8061A32C* FE()
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    return lbl_8061A32C;
}

struct UnkW3A8 : Unk800C7B40_Widget {
    char pad40[0x368];
    Unk800C7B40_Widget* m3A8;
};

extern "C" Scr* fn_8013BE4C(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC150(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8064B798);
    self->m2DC = 0;
    self->m3A8 = 0;
    self->m3B0 = 0x60;
    self->m3B4 = 0;
    self->m3B8 = 0;
    self->m3BC = 0;
    self->m3C0 = 1;
    self->m3C4 = 1;
    self->m3C8 = 0;
    self->m3D0 = 0;
    self->m3D4 = 0;
    self->m3D8 = 0;
    self->m3DC = 0;
    return self;
}

extern "C" void fn_8013C014(Scr* x)
{
    if (x->m3B8 != 0) {
        fn_800B83F8(fn_800B8144(), 0, 0);
    }
    FE();
    lbl_8061A32C->mC0 = x->m3D8 ^ 1;
    x->fn_vslot89(1);
}

extern "C" void fn_8013C23C(Scr* x)
{
    int n = fn_80403060(x->m2DC->fn_vslot31());
    if (n < x->m3D0) {
        x->m3D0 = n;
        fn_8013D200(x);
    }
}

extern "C" void fn_8013C29C(Scr* x)
{
    fn_800ECAA4(x);
    if (x->m3DC != 0) {
        x->m3DC = 0;
    }
    x->m3D4 = x->m3D4 & 0x1F;
    x->m3CC->fn_vslot8(x->m3D4 <= 15);
    x->m3D4 = x->m3D4 + 1;
}

extern "C" void fn_8013C320(Scr* x)
{
    fn_800EC84C(x);
}

extern "C" int fn_8013C340(Scr* x)
{
    fn_8013CD30(x, fn_800C8048(x->m3A8->fn_vslot70()->fn_vslot33(5, 1)));
    return 1;
}

extern "C" int fn_8013C3B8(Scr* x)
{
    fn_8001BC4C()->fn_8001BDAC(0xA0);
    fn_8013C014(x);
    if (x->m3AC != 0) {
        x->m3AC();
    }
    return 1;
}

extern "C" int fn_8013C40C(Scr* x)
{
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    fn_8013C8E4(x, x->m3BC ^ 1);
    return 1;
}

extern "C" int fn_8013C454(Scr* x)
{
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    fn_8013C5C8(x);
    return 1;
}

extern "C" int fn_8013C494(Scr* x)
{
    fn_8013CB70(x, 0);
    return 1;
}

extern "C" int fn_8013C4BC(Scr* x)
{
    fn_8013CB70(x, 1);
    return 1;
}

extern "C" int fn_8013C4E4(UnkW3A8* x)
{
    x->m3A8->fn_vslot56();
    return 1;
}

extern "C" int fn_8013C520(UnkW3A8* x)
{
    x->m3A8->fn_vslot54();
    return 1;
}

extern "C" int fn_8013C55C(Scr* x)
{
    if (x->m3DC != 0) {
        x->m3DC = 0;
        return 1;
    }
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    x->fn_vslot92();
    return 1;
}

extern "C" void fn_8013C5C8(Scr* x)
{
    const char* s = x->m2DC->fn_vslot31();
    int n = fn_80403060(s);
    if (n > 0 && x->m3D0 > 0) {
        unsigned short buf[100];
        fn_80403144(buf, s);
        for (int i = x->m3D0; i <= n; i++) {
            buf[i - 1] = buf[i];
        }
        x->m3D0 = x->m3D0 - 1;
        x->m2DC->fn_vslot28((const char*)buf);
        fn_8013D200(x);
    }
}

extern "C" void fn_8013C7C0(Scr* x)
{
    x->m2DC->fn_vslot30(lbl_805B6F58);
    x->m3D0 = 0;
    fn_8013D200(x);
}

extern "C" void fn_8013C81C(Scr* x)
{
    if (x->m3D0 > 0) {
        fn_8001BC4C()->fn_8001BDAC(0x99);
        x->m3D0 = x->m3D0 - 1;
    }
    fn_8013D200(x);
}

extern "C" void fn_8013C870(Scr* x)
{
    int n = fn_80403060(x->m2DC->fn_vslot31());
    if (x->m3D0 < n) {
        fn_8001BC4C()->fn_8001BDAC(0x99);
        x->m3D0 = x->m3D0 + 1;
    }
    fn_8013D200(x);
}

extern "C" void fn_8013D0E0(Scr* x, const char* s)
{
    fn_8013C7C0(x);
    if (s != 0) {
        x->m2DC->fn_vslot28(s);
    }
    x->m3D0 = fn_80403060(x->m2DC->fn_vslot31());
    fn_8013D200(x);
}

extern "C" void fn_8013D164(Scr* x, int v)
{
    x->m3B0 = v;
}

extern "C" int fn_8013D16C(Scr* x, Unk800C7B40_Widget* a, int b, int c, int d)
{
    if (a == x->m3A8) {
        fn_8013CD30(x, fn_800C8048(a->fn_vslot73(c, d)->fn_vslot33(5, 1)));
    }
    return 0;
}

extern "C" int fn_8013D1F8() { return 0; }

extern "C" void fn_8013D4CC(Scr* x, int a, void (*b)(), const char* c, int d, int e, int f, int g)
{
    x->m2E0 = a;
    x->m3AC = b;
    fn_8013D0E0(x, c);
    fn_8013D164(x, d);
    fn_8013C0A8(x, e, f, g);
}

extern "C" int fn_8013D534(Scr* x, int c)
{
    if ((unsigned)(c - 0x41) <= 0x19 || (unsigned)(c - 0x61) <= 0x19) {
        return x->m3C0 & 1;
    }
    if ((unsigned)(c - 0x30) <= 9) {
        return (x->m3C0 >> 1) & 1;
    }
    if (c == 0x20) {
        return (x->m3C0 >> 3) & 1;
    }
    return (x->m3C0 >> 2) & 1;
}

/* near-miss: 54/54 insns, 10 slots: retail stores m1B4 and m1D8 right after the vptr, then the zero stores in field order, then m1D4 and the byte copy of lbl_805B6F58 at the end; all 24 orders of the four trailing stores tried */
extern "C" Scr* fn_8013D590(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806561F0);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m16C = 0;
    self->m170 = 0;
    self->m174 = 0;
    self->m178 = 0;
    self->m17C = 0;
    self->m180 = 0;
    self->m184 = 0;
    self->m188 = 0;
    self->m18C = 0;
    self->m190 = 0;
    self->m194 = 0;
    self->m198 = 0;
    self->m19C = 0;
    self->m1A0 = 0;
    self->m1A4 = 0;
    self->m1A8 = 0;
    self->m1AC = 0;
    self->m1B0 = 0;
    self->m1D4 = 5;
    self->m1D8 = 5;
    self->m144 = lbl_805B6F58[0];
    self->m1B4 = 0;
    return self;
}

extern "C" void fn_8013E7A0()
{
    fn_800C5E28();
    fn_800C6604();
}

extern "C" int fn_8013E7C4(Scr* x, int a)
{
    if (fn_8014188C(x, a) != 0) {
        if (x->m134 == 0) {
            x->m138->fn_vslot56();
        } else if (x->m134 == 1) {
            x->m1A8->fn_vslot56();
        }
    }
    return 1;
}

extern "C" int fn_8013E84C(Scr* x, int a)
{
    if (fn_8014188C(x, a) != 0) {
        if (x->m134 == 0) {
            x->m138->fn_vslot57();
        } else if (x->m134 == 1) {
            x->m1A8->fn_vslot57();
        }
    }
    return 1;
}

extern "C" int fn_8013E8D4(Scr* x, int a)
{
    if (fn_8014188C(x, a) != 0) {
        if (x->m134 == 0) {
            x->m138->fn_vslot54();
        } else if (x->m134 == 1) {
            x->m1A8->fn_vslot54();
        }
    }
    return 1;
}

extern "C" int fn_8013E95C(Scr* x, int a)
{
    if (fn_8014188C(x, a) != 0) {
        if (x->m134 == 0) {
            x->m138->fn_vslot55();
        } else if (x->m134 == 1) {
            x->m1A8->fn_vslot55();
        }
    }
    return 1;
}

extern "C" int fn_8013E9E4(Scr* x, int a)
{
    if (fn_8014188C(x, a) != 0) {
        if (x->m134 == 0) {
            x->m138->fn_vslot50();
        } else if (x->m134 == 1) {
            x->m1A8->fn_vslot50();
            if (!x->m18C->b1) {
                if (x->m1A8->fn_vslot60() == 2) {
                    x->m1A8->fn_vslot50();
                }
            }
        }
    }
    return 1;
}

extern "C" int fn_8013EABC(Scr* x, int a)
{
    if (fn_8014188C(x, a) != 0) {
        if (x->m134 == 0) {
            x->m138->fn_vslot51();
        } else if (x->m134 == 1) {
            x->m1A8->fn_vslot51();
        }
    }
    return 1;
}

extern "C" int fn_8013EB44(Scr* x, int a)
{
    if (fn_8014188C(x, a) != 0) {
        if (x->m134 == 0) {
            x->m138->fn_vslot52();
        } else if (x->m134 == 1) {
            x->m1A8->fn_vslot52();
            if (!x->m18C->b1) {
                if (x->m1A8->fn_vslot60() == 2) {
                    x->m1A8->fn_vslot52();
                }
            }
        }
    }
    return 1;
}

extern "C" int fn_8013EC1C(Scr* x, int a)
{
    if (fn_8014188C(x, a) != 0) {
        if (x->m134 == 0) {
            x->m138->fn_vslot53();
        } else if (x->m134 == 1) {
            x->m1A8->fn_vslot53();
        }
    }
    return 1;
}

extern "C" void fn_8013F2C0(Scr* x)
{
    fn_800ED254(x);
    fn_800C5E28();
    fn_800C618C();
    fn_800C33D0();
    fn_800C5080();
    fn_800C33D0();
    fn_800C5B58();
    fn_800C33D0();
    fn_800C3BE0();
    fn_800C5E28();
    fn_800C5EB0();
}
