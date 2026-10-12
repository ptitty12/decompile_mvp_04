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
    virtual void fn_vslot32();
    virtual void fn_vslot33();
    virtual const char* fn_vslot34();
};
struct Unk8013C7C0_W2 : Unk8013C7C0_W {
    char pad40[0x30];
    unsigned m70;
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
    Unk8013C7C0_W2* m2DC;
    void (*m2E0)(unsigned short*);
    unsigned short m2E4[98];
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
struct Unk800B8144_Ret {
    char pad0[0x18];
    int m18;
};
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
Unk800B8144_Ret* fn_800B8144();
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
extern const char lbl_805C1B04[];
extern const char lbl_805C1B10[];
extern const char lbl_805C1B1C[];
extern "C" {
Unk800C7B40_Widget* fn_800C8060(Unk800C7B40_Widget* p);
Unk8013C7C0_W2* fn_800C8040(Unk800C7B40_Widget* p);
void fn_800EC1E8(void* x);
}
struct Unk8013CF6C_Msg {
    unsigned short m0;
    char m1;
};
extern const char lbl_805BA6D0[];
extern "C" {
int fn_8013D534(Scr* x, int c);
int fn_800DE9F4(unsigned short* buf, const char* s, int n);
Unk800C7B40_Widget* fn_800B7A94(Unk8061A32C* m, const char* name);
}
extern const char lbl_805C1B30[];
extern "C" Unk800C7B40_Widget* fn_800C8044(Unk800C7B40_Widget* p);
/* Second base object at +0xDC of the list/spinner controls: vptr at +0x24 of that base (+0x100). */
struct UnkDC_Data {
    char pad0[0x24];
};
struct UnkDC : UnkDC_Data {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6(int a);
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual int fn_vslot11();
};
extern "C" int fn_80076058(int a, int b);
extern const char lbl_805BA6D8[];
extern "C" {
Unk800C7B40_Widget* fn_800B7AB8(Unk8061A32C* m, const char* name);
void fn_80131F34(Unk800C7B40_Widget* o, Scr* x, void (*f)(), int a, int b, int c, int d, int e, int g, int h, int i, int j, int k, int l);
void fn_80147E54();
int fn_80403060(const char* s);
}
struct UnkDC_Owner : Unk800C7B40_Widget {
    char pad40[0x9C];
};
/* Screen class of unit 6 as seen from this unit (fn_8013ECA4). */
struct Unk8013ECA4 : Unk800C7B40_Widget {
    char pad40[0xF4];
    int m134;
    char pad138[0x1C];
    UnkDC_Owner* m154;
    int m158;
    char pad15C[0x14];
    UnkDC_Owner* m170;
    char pad174[0x4];
    UnkDC_Owner* m178;
    UnkDC_Owner* m17C;
    int m180;
    char pad184[0x4];
    UnkDC_Owner* m188;
    int m18C;
};
struct Unk8061E978 {
    int m0;
    int m4;
};
extern Unk8061E978* lbl_8061E978;
extern const int lbl_805C2074[];
extern "C" {
void fn_80141214(void* x, int a);
void fn_8013F60C(int a, int b, void* c, void* d);
void fn_8013F91C(void* x, int a);
void fn_801413E8(void* x, int a);
void fn_800C5E28();
void fn_800C6698();
void fn_8013E240(void* x);
void fn_801407AC(void* x);
void fn_8013E7A0(void* x);
void fn_80141084(void* x);
int fn_80140250(void* x, int a);
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

extern "C" void fn_8013BED0(Scr* x)
{
    fn_800EC1E8(x);
    x->m3A8 = fn_800C8060(x->fn_vslot32(lbl_805C1B04, 1));
    x->m2DC = fn_800C8040(x->fn_vslot32(lbl_805C1B10, 1));
    x->m2DC->m70 |= 0x20000000;
    x->m3CC = x->fn_vslot32(lbl_805C1B1C, 1);
    x->m3CC->fn_vslot18(x->m3CC->m2E + 1);
    x->m3D0 = 0;
    fn_8013D200(x);
    x->fn_vslot16(0);
    x->fn_vslot8(0);
    x->m3A8->fn_vslot67(2, 12);
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

extern "C" void fn_8013C0A8(Scr* x, int a, int b, int c)
{
    FE();
    x->m3D8 = lbl_8061A32C->mC0 ^ 1;
    x->m3DC = 1;
    FE();
    lbl_8061A32C->mC0 = 0;
    x->m3C0 = a;
    x->m3C8 = c;
    fn_8013C8E4(x, 1);
    x->m3E0 = 1;
    x->m3E4 = 1;
    if (b != 0) {
        fn_8001BC4C()->fn_8001BDAC(0x9D);
    }
    x->fn_vslot89(0);
    if (fn_800B8144()->m18 != 0) {
        x->m3B8 = 0;
    } else {
        x->m3B8 = 1;
        fn_800B83F8(fn_800B8144(), 1, 1);
    }
    FE();
    Unk800C7B40_Widget* w = fn_800B7A94(lbl_8061A32C, lbl_805BA6D0);
    if (w != 0) {
        w->fn_vslot16(0);
    }
    x->m3D0 = fn_80403060(x->m2DC->fn_vslot31());
    fn_8013D200(x);
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

extern "C" void fn_8013C69C(Scr* x)
{
    fn_80403144(x->m2E4, x->m2DC->fn_vslot31());
    int n;
    if (x->m3C4 == 0 && (n = fn_80403060((const char*)x->m2E4)) == 0) {
        FE();
        Unk800C7B40_Widget* o = fn_800B7AB8(lbl_8061A32C, lbl_805BA6D8);
        fn_80131F34(o, x, fn_80147E54, 0, 0x4886, 1, -1, 1, 0x26DE, n, n, n, n, n);
        o->fn_vslot86();
    } else {
        x->m3C4 = 1;
        fn_8013C014(x);
        x->m2E0(x->m2E4);
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

extern "C" void fn_8013CB70(Scr* x, int dir)
{
    int r = x->m3A8->fn_vslot60();
    int c = x->m3A8->fn_vslot61();
    if (dir == 0) {
        r = r - 1;
        if (r < 0) {
            r = x->m3A8->fn_vslot59() - 1;
        }
    } else if (dir == 1) {
        r = r + 1;
        if (r >= x->m3A8->fn_vslot59()) {
            r = 0;
        }
    }
    for (;;) {
        Unk800C7B40_Widget* w = x->m3A8->fn_vslot73(r, c);
        if (w->b1) {
            break;
        }
        if (fn_800C8044(w)->fn_vslot30(lbl_805C1B30, 1) != 0) {
            c = c + 1;
            if (c >= x->m3A8->fn_vslot58()) {
                c = 0;
            }
        } else {
            c = c - 1;
            if (c < 0) {
                c = x->m3A8->fn_vslot58() - 1;
            }
        }
    }
    fn_8001BC4C()->fn_8001BDAC(0x99);
    x->m3A8->fn_vslot67(r, c);
}

extern "C" void fn_8013CF6C(Scr* x, Unk8013CF6C_Msg* m)
{
    if (fn_8013D534(x, ((char*)m)[1]) != 0) {
        const unsigned short* s = (const unsigned short*)x->m2DC->fn_vslot31();
        int n = fn_80403060((const char*)s);
        if (n < x->m3B0) {
            unsigned short buf[100];
            int k;
            for (k = 0; k < x->m3D0; k++) {
                buf[k] = s[k];
            }
            buf[x->m3D0] = m->m0;
            for (k = x->m3D0; k <= n + 1; k++) {
                buf[k + 1] = s[k];
            }
            int bad = 0;
            if (x->m3C8 != 0) {
                if (fn_800DE9F4(buf, x->m2DC->fn_vslot34(), x->m3C8) != 0) {
                    bad = 1;
                }
            }
            if (bad == 0) {
                fn_8001BC4C()->fn_8001BDAC(0x99);
                x->m2DC->fn_vslot28((const char*)buf);
                x->m3D0 = x->m3D0 + 1;
                fn_8013D200(x);
            }
        }
    }
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

extern "C" void fn_8013D4CC(Scr* x, void (*a)(unsigned short*), void (*b)(), const char* c, int d, int e, int f, int g)
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
    self->m1B4 = 0;
    self->m1D8 = 5;
    self->m144 = *(char*)lbl_805B6F58;
    return self;
}

extern "C" void fn_8013E7A0(void* x)
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

extern "C" void fn_8013ECA4(Unk8013ECA4* x, int a)
{
    if (a == x->m158) {
        int v = ((UnkDC*)((char*)x->m154 + 0xDC))->fn_vslot11();
        int w = ((UnkDC*)((char*)x->m17C + 0xDC))->fn_vslot11();
        fn_80141214(x, v);
        ((UnkDC*)((char*)x->m170 + 0xDC))->fn_vslot6(lbl_805C2074[v]);
        fn_8013F60C(v, w, x->m17C, x->m178);
        fn_8013F91C(x, v);
        fn_801413E8(x, v);
        fn_800C5E28();
        fn_800C6698();
        fn_8013E240(x);
        if (fn_80140250(x, ((UnkDC*)((char*)x->m154 + 0xDC))->fn_vslot11()) != 0) {
            x->m17C->fn_vslot16(0);
            x->m178->fn_vslot16(0);
        }
        if (x->m134 == 1) {
            fn_801407AC(x);
        }
    } else if (a == x->m180) {
        fn_8013E7A0(x);
    } else if (a == x->m18C) {
        Unk8061E978* g = lbl_8061E978;
        g->m4 = ((UnkDC*)((char*)x->m188 + 0xDC))->fn_vslot11();
    }
    fn_80141084(x);
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

extern "C" void fn_8013F898(void* a, int* out1, void* b, int* out2)
{
    int va = ((UnkDC*)((char*)a + 0xDC))->fn_vslot11();
    int vb = ((UnkDC*)((char*)b + 0xDC))->fn_vslot11();
    *out1 = fn_80076058(va, vb);
    *out2 = vb;
}
