/*
 * Front-end overlay code, .frontend_codeoverlay 0x80529364-0x8052A208 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"

extern "C" void fn_80134EC8(void* self);
extern "C" void fn_800EC1B8(void* self);
extern "C" void fn_804BB988(float a, float b);
extern "C" void fn_80525670(int a, int b);
extern const float lbl_805FC4DC;
extern const float lbl_805FC4E0;
extern const char lbl_80667638[];
extern const char lbl_80667650[];
extern const char lbl_80668BB8[];
extern const char lbl_80669498[];
extern const char lbl_806694B0[];
extern const char lbl_8066CA20[];
extern const char lbl_8066CA38[];
extern const char lbl_8066E250[];
extern const char lbl_8066E268[];
extern "C" void fn_804BB17C(FeScrD* x);
extern const char lbl_80670C10[];
extern const char lbl_8066FE18[];
extern const char lbl_8066F0D0[];
extern const char lbl_8066DFA8[];
extern const char lbl_8066BA30[];
extern const char lbl_8066B788[];
extern const char lbl_8066ACE8[];
extern const char lbl_8066AA40[];
extern const char lbl_8066A798[];
extern const char lbl_8066A4F0[];
extern const char lbl_80669780[];
extern "C" void fn_804D2BCC(void* self);
extern const char lbl_806691F0[];
extern const char lbl_80668EA0[];
extern "C" void fn_800EC5F4__FP8UiScrRaw(void* self);
extern const char lbl_80668910[];
extern const char lbl_80668668[];
extern const char lbl_80668118[];
extern const char lbl_80667E70[];
extern const char lbl_80667BC8[];
extern const char lbl_80667920[];
extern const char lbl_80672168[];
extern "C" void fn_80377408(void* p);
extern const char lbl_80671D28[];
extern "C" void fn_804BFE54(void* x, int k, int a);
extern const char lbl_80666EC0[];
extern const char lbl_806672D8[];
extern "C" void fn_80330870(void* self, int c);
extern const char lbl_80667288[];
extern const char lbl_80667238[];
extern const char lbl_806671E8[];
extern const char lbl_80667198[];
extern "C" void fn_80529364(FeVptr<0xCC0>* self, int c);
extern "C" void fn_80529398(void* x, int a);
extern "C" int fn_805293A0(void* x);
extern "C" int fn_805293A8(void* x);
extern "C" void fn_805293C0(void* x, int a);
extern "C" int fn_805293C8(void* x);
extern "C" void fn_805293D0(FeScrN* x, int a);
extern "C" void fn_8052941C(FeVptr<0xCC0>* self, int c);
extern "C" void fn_80529450(FeScrD* x);
extern "C" void fn_80529520(FeScrN* self);
extern "C" void fn_80529558(FeScrN* self);
extern "C" int fn_80529590(void);
extern "C" void fn_80529598(FeScrN* self);
extern "C" void fn_805295D0(FeScrN* self);
extern "C" void fn_8052967C(FeScrN* self);
extern "C" int fn_805296B4(void);
extern "C" void fn_805296C0(FeScrN* self);
extern "C" void fn_8052974C(FeScrN* self);
extern "C" int fn_8052977C(void);
extern "C" int fn_80529784(void);
extern "C" void fn_805297E8(FeScrN* self);
extern "C" void fn_80529818(FeScrN* self);
extern "C" void fn_8052984C(FeScrN* self);
extern "C" void fn_8052987C(FeScrN* self);
extern "C" void fn_805298B0(FeScrN* self);
extern "C" void fn_805298E0(FeScrN* self);
extern "C" void fn_80529910(FeScrN* self);
extern "C" void fn_805299A8(FeScrN* self);
extern "C" void fn_805299D8(FeScrN* self);
extern "C" int fn_80529A08(void);
extern "C" int fn_80529A10(void);
extern "C" int fn_80529A18(void);
extern "C" int fn_80529A20(void);
extern "C" void fn_80529A28(void* x, int a);
extern "C" int fn_80529A30(void* x);
extern "C" void fn_80529AAC(FeScrN* self);
extern "C" void fn_80529ADC(FeScrN* self);
extern "C" void fn_80529C74(FeScrN* self);
extern "C" void fn_80529CA4(FeScrN* self);
extern "C" void fn_80529CD4(FeScrN* self);
extern "C" void fn_80529D04(FeScrN* self);
extern "C" int fn_80529D9C(void);
extern "C" void fn_80529600(void* x, int a);
extern "C" void fn_8052962C(void* x, int a);
extern "C" void fn_80529654(void* x, int a);
extern "C" void fn_80529DA4(FeScrN* self, int c);
extern "C" void fn_80529DE4(FeScrN* self, int c);
extern "C" void fn_80529E4C(FeScrN* self, int c);
extern "C" void fn_80529E90(FeScrN* self, int c);
extern "C" void fn_80529ED0(FeScrN* self, int c);
extern "C" int fn_805293B0(void* x, int i);
extern "C" int fn_80529408(void* x);
extern "C" void fn_80529470(FeVCC0* x, float a, float b, float c, float d);
extern "C" void fn_805294BC(float a, float b);
extern "C" void fn_805294F0(float a);
extern "C" void fn_805296F0(FeScrN* self, int c);
extern "C" void fn_8052978C(FeScrN* self, int c);
extern "C" void fn_80529940(FeScrN* self, int c);
extern "C" void fn_80529D34(FeScrN* self, int c);
extern "C" void fn_80529A38(FeScrN* self, int c);
extern "C" void fn_8052A1DC(void);

/* Element of the arrays destroyed by fn_80529B10 (vptr at +0x10; the destructor is called through vtable slot 15). */
class FeD10 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
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
    virtual void s15(int c);
};
extern const char lbl_806683C0[];
extern const char lbl_8064A550[];

extern const char lbl_8064B298[];
extern const char lbl_80667148[];
extern "C" void fn_804CE714(void* p, int c);

struct FeSubS {
    char pad0[8];
    int m8;
    char pad1[0x58 - 0xC];
    int m58;
    char pad2[0x2DC - 0x5C];
    int m2DC;
};

extern "C" FE_OVERLAY void fn_80529364(FeVptr<0xCC0>* self, int c)
{
    self->vp = lbl_80672168;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80529398(void* x, int a)
{
    FeI(x, 0xcb8) = a;
}

extern "C" FE_OVERLAY int fn_805293A0(void* x)
{
    return FeI(x, 0xcb8);
}

extern "C" FE_OVERLAY int fn_805293A8(void* x)
{
    return FeI(x, 0xcb4);
}

extern "C" FE_OVERLAY int fn_805293B0(void* x, int i)
{
    return FeKeyAt((char*)x + 0x344, i * 0x324);
}

extern "C" FE_OVERLAY void fn_805293C0(void* x, int a)
{
    FeI(x, 0x20) = a;
}

extern "C" FE_OVERLAY int fn_805293C8(void* x)
{
    return FeI(x, 0x20);
}

extern "C" FE_OVERLAY void fn_805293D0(FeScrN* x, int a)
{
    ((FeW*)FeI(x, 0xCBC))->fn_vslot8(a);
}

extern "C" FE_OVERLAY int fn_80529408(void* x)
{
    return FeP(x, 0xCBC)->b0;
}

extern "C" FE_OVERLAY void fn_80529418(void) {}

extern "C" FE_OVERLAY void fn_8052941C(FeVptr<0xCC0>* self, int c)
{
    self->vp = lbl_80672168;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80529450(FeScrD* x)
{
    fn_804BB17C(x);
}

extern "C" FE_OVERLAY void fn_80529470(FeVCC0* x, float a, float b, float c, float d)
{
    x->s27(b, d);
}

extern "C" FE_OVERLAY void fn_805294BC(float a, float b)
{
    fn_804BB988(lbl_805FC4DC, b);
}

extern "C" FE_OVERLAY void fn_805294F0(float a)
{
    fn_804BB988(lbl_805FC4E0, a);
}

extern "C" FE_OVERLAY void fn_80529520(FeScrN* self)
{
    self->SetVptr(lbl_80671D28);
    FeI(self, 0xe0c) = (int)lbl_80672168;
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529558(FeScrN* self)
{
    self->SetVptr(lbl_80671D28);
    FeI(self, 0xe0c) = (int)lbl_80672168;
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_80529590(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_80529598(FeScrN* self)
{
    self->SetVptr(lbl_80671D28);
    FeI(self, 0xe0c) = (int)lbl_80672168;
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_805295D0(FeScrN* self)
{
    self->SetVptr(lbl_80670C10);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529600(void* x, int a)
{
    fn_804BFE54(x, 0, a);
}

extern "C" FE_OVERLAY void fn_80529628(void) {}

extern "C" FE_OVERLAY void fn_8052962C(void* x, int a)
{
    fn_804BFE54(x, 0, a);
}

extern "C" FE_OVERLAY void fn_80529654(void* x, int a)
{
    fn_804BFE54(x, 1, a);
}

extern "C" FE_OVERLAY void fn_8052967C(FeScrN* self)
{
    self->SetVptr(lbl_8066FE18);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_805296AC(void) {}

extern "C" FE_OVERLAY void fn_805296B0(void) {}

extern "C" FE_OVERLAY int fn_805296B4(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_805296BC(void) {}

extern "C" FE_OVERLAY void fn_805296C0(FeScrN* self)
{
    self->SetVptr(lbl_8066F0D0);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_805296F0(FeScrN* self, int c)
{
    FeI(self, 0x1BC) = (int)lbl_8066E250;
    self->SetVptr(lbl_8066E268);
    ((FeDtorFn)fn_80134EC8)((char*)self + 0x174, 0);
    ((FeDtorFn)fn_804D2BCC)(self, c);
}

extern "C" FE_OVERLAY void fn_8052974C(FeScrN* self)
{
    self->SetVptr(lbl_8066DFA8);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_8052977C(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_80529784(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_8052978C(FeScrN* self, int c)
{
    FeI(self, 0x17C) = (int)lbl_8066CA20;
    self->SetVptr(lbl_8066CA38);
    ((FeDtorFn)fn_80134EC8)((char*)self + 0x134, 0);
    ((FeDtorFn)fn_8035686C)(self, c);
}

extern "C" FE_OVERLAY void fn_805297E8(FeScrN* self)
{
    self->SetVptr(lbl_8066BA30);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529818(FeScrN* self)
{
    self->SetVptr(lbl_8066B788);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529848(void) {}

extern "C" FE_OVERLAY void fn_8052984C(FeScrN* self)
{
    self->SetVptr(lbl_8066ACE8);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_8052987C(FeScrN* self)
{
    self->SetVptr(lbl_8066AA40);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_805298AC(void) {}

extern "C" FE_OVERLAY void fn_805298B0(FeScrN* self)
{
    self->SetVptr(lbl_8066A798);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_805298E0(FeScrN* self)
{
    self->SetVptr(lbl_8066A4F0);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529910(FeScrN* self)
{
    self->SetVptr(lbl_80669780);
    fn_804D2BCC(self);
}

extern "C" FE_OVERLAY void fn_80529940(FeScrN* self, int c)
{
    FeI(self, 0x1C4) = (int)lbl_80669498;
    self->SetVptr(lbl_806694B0);
    ((FeDtorFn)fn_80134EC8)((char*)self + 0x17C, 0);
    self->SetVptr(lbl_80669780);
    ((FeDtorFn)fn_804D2BCC)(self, c);
}

extern "C" FE_OVERLAY void fn_805299A8(FeScrN* self)
{
    self->SetVptr(lbl_806691F0);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_805299D8(FeScrN* self)
{
    self->SetVptr(lbl_80668EA0);
    fn_800EC5F4__FP8UiScrRaw(self);
}

extern "C" FE_OVERLAY int fn_80529A08(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80529A10(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80529A18(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80529A20(void)
{
    return 1;
}

extern "C" FE_OVERLAY void fn_80529A28(void* x, int a)
{
    FeI(x, 0x160) = a;
}

extern "C" FE_OVERLAY int fn_80529A30(void* x)
{
    return FeI(x, 0x160);
}

extern "C" FE_OVERLAY void fn_80529A38(FeScrN* self, int c)
{
    self->SetVptr(lbl_80668BB8);
    FeW* a = (FeW*)((char*)self + 0x440);
    a->SetVptr(lbl_80668EA0);
    ((FeDtorFn)fn_800EC5F4__FP8UiScrRaw)(a, 2);
    FeW* b = (FeW*)((char*)self + 0x2DC);
    b->SetVptr(lbl_80668EA0);
    ((FeDtorFn)fn_800EC5F4__FP8UiScrRaw)(b, 2);
    ((FeDtorFn)fn_800EC1B8)(self, c);
}

extern "C" FE_OVERLAY void fn_80529AAC(FeScrN* self)
{
    self->SetVptr(lbl_80668910);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529ADC(FeScrN* self)
{
    self->SetVptr(lbl_80668668);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529B0C(void) {}

extern "C" FE_OVERLAY void fn_80529B10(FeScrN* self, int c)
{
    self->SetVptr(lbl_806683C0);
    if ((char*)self + 0x30F60 != 0) {
        char* e = (char*)self + 0x31240;
        if ((char*)self + 0x30F60 != e) {
            do {
                e -= 0xB8;
                ((FeD10*)e)->s15(0);
            } while ((char*)self + 0x30F60 != e);
        }
    }
    if ((char*)self + 0x242A0 != 0) {
        char* e = (char*)self + 0x30F60;
        if ((char*)self + 0x242A0 != e) {
            do {
                e -= 0x1F8;
                ((FeD10*)e)->s15(0);
            } while ((char*)self + 0x242A0 != e);
        }
    }
    if ((char*)self + 0x1A2A0 != 0) {
        char* e = (char*)self + 0x242A0;
        if ((char*)self + 0x1A2A0 != e) {
            do {
                e -= 0x400;
                ((FeD10*)e)->s15(0);
            } while ((char*)self + 0x1A2A0 != e);
        }
    }
    FeVptr<0x10>* t = (FeVptr<0x10>*)((char*)self + 0x16FC0);
    t->vp = lbl_8064A550;
    if ((char*)self + 0x34C0 != 0) {
        char* e = (char*)t;
        if ((char*)self + 0x34C0 != e) {
            do {
                e -= 0x1F8;
                ((FeD10*)e)->s15(0);
            } while ((char*)self + 0x34C0 != e);
        }
    }
    ((FeDtorFn)fn_8035686C)(self, c);
}

extern "C" FE_OVERLAY void fn_80529C74(FeScrN* self)
{
    self->SetVptr(lbl_80668118);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529CA4(FeScrN* self)
{
    self->SetVptr(lbl_80667E70);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529CD4(FeScrN* self)
{
    self->SetVptr(lbl_80667BC8);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529D04(FeScrN* self)
{
    self->SetVptr(lbl_80667920);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529D34(FeScrN* self, int c)
{
    FeI(self, 0x1C4) = (int)lbl_80667638;
    self->SetVptr(lbl_80667650);
    ((FeDtorFn)fn_80134EC8)((char*)self + 0x17C, 0);
    self->SetVptr(lbl_80669780);
    ((FeDtorFn)fn_804D2BCC)(self, c);
}

extern "C" FE_OVERLAY int fn_80529D9C(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_80529DA4(FeScrN* self, int c)
{
    FeI(self, 0x2DC) = (int)lbl_806672D8;
    FeI(self, 0x33C) = (int)lbl_80666EC0;
    FeI(self, 0x2E8) = (int)lbl_80666EC0;
    fn_80330870(self, c);
}

extern "C" FE_OVERLAY void fn_80529DE4(FeScrN* self, int c)
{
    FeI(self, 0x2DC) = (int)lbl_80667288;
    FeI(self, 0x6D4) = (int)lbl_80666EC0;
    FeI(self, 0x66C) = (int)lbl_80666EC0;
    FeI(self, 0x608) = (int)lbl_80666EC0;
    FeI(self, 0x5A4) = (int)lbl_80666EC0;
    FeI(self, 0x540) = (int)lbl_80666EC0;
    FeI(self, 0x4DC) = (int)lbl_80666EC0;
    FeI(self, 0x47C) = (int)lbl_80666EC0;
    FeI(self, 0x418) = (int)lbl_80666EC0;
    FeI(self, 0x3CC) = (int)lbl_80666EC0;
    FeI(self, 0x380) = (int)lbl_80666EC0;
    FeI(self, 0x334) = (int)lbl_80666EC0;
    FeI(self, 0x2E8) = (int)lbl_80666EC0;
    fn_80330870(self, c);
}

extern "C" FE_OVERLAY void fn_80529E4C(FeScrN* self, int c)
{
    FeI(self, 0x2DC) = (int)lbl_80667238;
    FeI(self, 0x39C) = (int)lbl_80666EC0;
    FeI(self, 0x334) = (int)lbl_80666EC0;
    FeI(self, 0x2E8) = (int)lbl_80666EC0;
    fn_80330870(self, c);
}

extern "C" FE_OVERLAY void fn_80529E90(FeScrN* self, int c)
{
    FeI(self, 0x2DC) = (int)lbl_806671E8;
    FeI(self, 0x334) = (int)lbl_80666EC0;
    FeI(self, 0x2E8) = (int)lbl_80666EC0;
    fn_80330870(self, c);
}

extern "C" FE_OVERLAY void fn_80529ED0(FeScrN* self, int c)
{
    FeI(self, 0x2DC) = (int)lbl_80667198;
    FeI(self, 0x984) = (int)lbl_80666EC0;
    FeI(self, 0x930) = (int)lbl_80666EC0;
    FeI(self, 0x8CC) = (int)lbl_80666EC0;
    FeI(self, 0x878) = (int)lbl_80666EC0;
    FeI(self, 0x810) = (int)lbl_80666EC0;
    FeI(self, 0x7BC) = (int)lbl_80666EC0;
    FeI(self, 0x758) = (int)lbl_80666EC0;
    FeI(self, 0x6F4) = (int)lbl_80666EC0;
    FeI(self, 0x6A0) = (int)lbl_80666EC0;
    FeI(self, 0x63C) = (int)lbl_80666EC0;
    FeI(self, 0x5D8) = (int)lbl_80666EC0;
    FeI(self, 0x574) = (int)lbl_80666EC0;
    FeI(self, 0x510) = (int)lbl_80666EC0;
    FeI(self, 0x4AC) = (int)lbl_80666EC0;
    FeI(self, 0x458) = (int)lbl_80666EC0;
    FeI(self, 0x3F4) = (int)lbl_80666EC0;
    FeI(self, 0x390) = (int)lbl_80666EC0;
    FeI(self, 0x33C) = (int)lbl_80666EC0;
    FeI(self, 0x2E8) = (int)lbl_80666EC0;
    fn_80330870(self, c);
}

extern "C" FE_OVERLAY void fn_80529F54(void* self, int c)
{
    FeI(self, 0x2DC) = (int)lbl_80667148;
    char* pr3 = (char*)self + 0x36A4;
    FeI(self, 0x40E4) = (int)lbl_80666EC0;
    FeI(self, 0x4090) = (int)lbl_80666EC0;
    ((FeSubS*)pr3)->m2DC = (int)lbl_80667198;
    FeI(self, 0x4028) = (int)lbl_80666EC0;
    FeI(self, 0x3FD4) = (int)lbl_80666EC0;
    FeI(self, 0x3F70) = (int)lbl_80666EC0;
    FeI(self, 0x3F1C) = (int)lbl_80666EC0;
    FeI(self, 0x3EB4) = (int)lbl_80666EC0;
    FeI(self, 0x3E60) = (int)lbl_80666EC0;
    FeI(self, 0x3DFC) = (int)lbl_80666EC0;
    FeI(self, 0x3D98) = (int)lbl_80666EC0;
    FeI(self, 0x3D44) = (int)lbl_80666EC0;
    FeI(self, 0x3CE0) = (int)lbl_80666EC0;
    FeI(self, 0x3C7C) = (int)lbl_80666EC0;
    FeI(self, 0x3C18) = (int)lbl_80666EC0;
    FeI(self, 0x3BB4) = (int)lbl_80666EC0;
    FeI(self, 0x3B50) = (int)lbl_80666EC0;
    FeI(self, 0x3AFC) = (int)lbl_80666EC0;
    FeI(self, 0x3A98) = (int)lbl_80666EC0;
    FeI(self, 0x3A34) = (int)lbl_80666EC0;
    FeI(self, 0x39E0) = (int)lbl_80666EC0;
    FeI(self, 0x398C) = (int)lbl_80666EC0;
    fn_80330870(pr3, 2);
    char* pr11 = (char*)self + 0x3310;
    ((FeSubS*)pr11)->m2DC = (int)lbl_806671E8;
    FeI(self, 0x3644) = (int)lbl_80666EC0;
    FeI(self, 0x35F8) = (int)lbl_80666EC0;
    fn_80330870(pr11, 2);
    char* pr11_2 = (char*)self + 0x2F1C;
    ((FeSubS*)pr11_2)->m2DC = (int)lbl_80667238;
    FeI(self, 0x32B8) = (int)lbl_80666EC0;
    FeI(self, 0x3250) = (int)lbl_80666EC0;
    FeI(self, 0x3204) = (int)lbl_80666EC0;
    fn_80330870(pr11_2, 2);
    char* pr11_3 = (char*)self + 0x27E4;
    ((FeSubS*)pr11_3)->m2DC = (int)lbl_80667288;
    FeI(self, 0x2EB8) = (int)lbl_80666EC0;
    FeI(self, 0x2E50) = (int)lbl_80666EC0;
    FeI(self, 0x2DEC) = (int)lbl_80666EC0;
    FeI(self, 0x2D88) = (int)lbl_80666EC0;
    FeI(self, 0x2D24) = (int)lbl_80666EC0;
    FeI(self, 0x2CC0) = (int)lbl_80666EC0;
    FeI(self, 0x2C60) = (int)lbl_80666EC0;
    FeI(self, 0x2BFC) = (int)lbl_80666EC0;
    FeI(self, 0x2BB0) = (int)lbl_80666EC0;
    FeI(self, 0x2B64) = (int)lbl_80666EC0;
    FeI(self, 0x2B18) = (int)lbl_80666EC0;
    FeI(self, 0x2ACC) = (int)lbl_80666EC0;
    fn_80330870(pr11_3, 2);
    char* pr11_4 = (char*)self + 0x21D4;
    FeI(self, 0x2798) = (int)lbl_80666EC0;
    FeI(self, 0x2730) = (int)lbl_80666EC0;
    FeI(self, 0x26DC) = (int)lbl_80666EC0;
    FeI(self, 0x2674) = (int)lbl_80666EC0;
    FeI(self, 0x2620) = (int)lbl_80666EC0;
    FeI(self, 0x25B8) = (int)lbl_80666EC0;
    FeI(self, 0x2564) = (int)lbl_80666EC0;
    ((FeSubS*)pr11_4)->m2DC = (int)lbl_806672D8;
    FeI(self, 0x2510) = (int)lbl_80666EC0;
    FeI(self, 0x24BC) = (int)lbl_80666EC0;
    fn_80330870(pr11_4, 2);
    FeI(self, 0x2188) = (int)lbl_80666EC0;
    FeI(self, 0x2134) = (int)lbl_80666EC0;
    FeI(self, 0x20E8) = (int)lbl_80666EC0;
    char* pr11_5 = (char*)self + 0x1918;
    FeI(self, 0x2080) = (int)lbl_80666EC0;
    char* pr10 = (char*)self + 0x16B4;
    FeI(self, 0x2034) = (int)lbl_80666EC0;
    FeI(self, 0x1FE0) = (int)lbl_80666EC0;
    FeI(self, 0x1F8C) = (int)lbl_80666EC0;
    FeI(self, 0x1F38) = (int)lbl_80666EC0;
    FeI(self, 0x1EE4) = (int)lbl_80666EC0;
    FeI(self, 0x1E98) = (int)lbl_80666EC0;
    FeI(self, 0x1E4C) = (int)lbl_80666EC0;
    FeI(self, 0x1DE8) = (int)lbl_80666EC0;
    FeI(self, 0x1D9C) = (int)lbl_80666EC0;
    FeI(self, 0x1D38) = (int)lbl_80666EC0;
    FeI(self, 0x1CE4) = (int)lbl_80666EC0;
    FeI(self, 0x1C90) = (int)lbl_80666EC0;
    FeI(self, 0x1C3C) = (int)lbl_80666EC0;
    FeI(self, 0x1BD8) = (int)lbl_80666EC0;
    FeI(self, 0x1B84) = (int)lbl_80666EC0;
    ((FeSubS*)pr11_5)->m58 = (int)lbl_8064B298;
    ((FeSubS*)pr11_5)->m8 = (int)lbl_80666EC0;
    ((FeSubS*)pr10)->m58 = (int)lbl_8064B298;
    ((FeSubS*)pr10)->m8 = (int)lbl_80666EC0;
    FeI(self, 0x1668) = (int)lbl_80666EC0;
    FeI(self, 0x1614) = (int)lbl_80666EC0;
    FeI(self, 0x15C0) = (int)lbl_80666EC0;
    FeI(self, 0x156C) = (int)lbl_80666EC0;
    FeI(self, 0x1518) = (int)lbl_80666EC0;
    FeI(self, 0x14C4) = (int)lbl_80666EC0;
    FeI(self, 0x1478) = (int)lbl_80666EC0;
    FeI(self, 0x142C) = (int)lbl_80666EC0;
    FeI(self, 0x13D8) = (int)lbl_80666EC0;
    FeI(self, 0x1378) = (int)lbl_80666EC0;
    FeI(self, 0x132C) = (int)lbl_80666EC0;
    FeI(self, 0x12E0) = (int)lbl_80666EC0;
    FeI(self, 0x1294) = (int)lbl_80666EC0;
    FeI(self, 0x1248) = (int)lbl_80666EC0;
    FeI(self, 0x11FC) = (int)lbl_80666EC0;
    FeI(self, 0x11B0) = (int)lbl_80666EC0;
    FeI(self, 0x1164) = (int)lbl_80666EC0;
    FeI(self, 0x1118) = (int)lbl_80666EC0;
    FeI(self, 0x10CC) = (int)lbl_80666EC0;
    FeI(self, 0x1084) = (int)lbl_80666EC0;
    FeI(self, 0x101C) = (int)lbl_80666EC0;
    FeI(self, 0xFD4) = (int)lbl_80666EC0;
    FeI(self, 0xF70) = (int)lbl_80666EC0;
    FeI(self, 0xF28) = (int)lbl_80666EC0;
    FeI(self, 0xEE0) = (int)lbl_80666EC0;
    FeI(self, 0xE98) = (int)lbl_80666EC0;
    FeI(self, 0xE50) = (int)lbl_80666EC0;
    FeI(self, 0xDFC) = (int)lbl_80666EC0;
    FeI(self, 0xDB0) = (int)lbl_80666EC0;
    FeI(self, 0xD64) = (int)lbl_80666EC0;
    FeI(self, 0xD18) = (int)lbl_80666EC0;
    fn_804CE714((char*)self + 0x32C, 2);
    FeI(self, 0x2E8) = (int)lbl_80666EC0;
    fn_80330870(self, c);
}

extern "C" FE_OVERLAY void fn_8052A1DC(void)
{
    fn_80525670(1, 0xFFFF);
}
