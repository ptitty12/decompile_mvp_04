/*
 * Front-end overlay code, .frontend_codeoverlay 0x80529364-0x8052A208 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"

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
extern "C" void fn_80529450(FeScrD* x);
extern "C" int fn_80529590(void);
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
extern "C" void fn_80529AAC(FeScrN* self);
extern "C" void fn_80529ADC(FeScrN* self);
extern "C" void fn_80529C74(FeScrN* self);
extern "C" void fn_80529CA4(FeScrN* self);
extern "C" void fn_80529CD4(FeScrN* self);
extern "C" void fn_80529D04(FeScrN* self);
extern "C" int fn_80529D9C(void);
extern "C" void fn_80529398(void* x, int a);
extern "C" int fn_805293A0(void* x);
extern "C" int fn_805293A8(void* x);
extern "C" void fn_805293C0(void* x, int a);
extern "C" int fn_805293C8(void* x);
extern "C" int fn_80529A08(void);
extern "C" int fn_80529A10(void);
extern "C" int fn_80529A18(void);
extern "C" int fn_80529A20(void);
extern "C" void fn_80529A28(void* x, int a);
extern "C" int fn_80529A30(void* x);
extern "C" void fn_80529364(FeVptr<0xCC0>* self, int c);
extern "C" void fn_805293D0(FeScrN* x, int a);
extern "C" void fn_8052941C(FeVptr<0xCC0>* self, int c);
extern "C" void fn_80529520(FeScrN* self);
extern "C" void fn_80529558(FeScrN* self);
extern "C" void fn_80529598(FeScrN* self);

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

extern "C" FE_OVERLAY void fn_80529628(void) {}

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

extern "C" FE_OVERLAY int fn_80529D9C(void)
{
    return 0;
}
