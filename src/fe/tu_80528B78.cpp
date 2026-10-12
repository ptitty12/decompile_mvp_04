/*
 * Front-end overlay code, .frontend_codeoverlay 0x80528B78-0x80529364 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"

extern "C" void fn_804D2BCC(void* self);
extern const char lbl_80655808[];
extern "C" void fn_800EC1B8(void* self);
extern const char lbl_80678AB0[];
extern const char lbl_80676060[];
extern const char lbl_80674328[];
extern const char lbl_80673B30[];
extern const char lbl_80673068[];
extern const char lbl_80672DC0[];
extern const char lbl_80672830[];
extern const char lbl_806827B0[];
extern "C" void fn_80377408(void* p);
extern const char lbl_80674080[];
extern const char lbl_806841F8[];
extern const char lbl_80673DD8[];
extern const char lbl_8064A550[];
extern "C" int fn_80528FB4(void);
extern "C" void fn_80528FC0(FeScrN* self);
extern "C" void fn_80528FF0(FeScrN* self);
extern "C" int fn_80529020(void);
extern "C" void fn_8052902C(FeScrN* self);
extern "C" void fn_805290B0(FeScrN* self);
extern "C" int fn_805290E0(void);
extern "C" void fn_805290E8(FeScrN* self);
extern "C" int fn_80529118(void);
extern "C" void fn_80529120(FeScrN* self);
extern "C" int fn_80529150(void);
extern "C" int fn_80529158(void);
extern "C" void fn_80529160(FeScrN* self);
extern "C" void fn_80529204(FeScrN* self);
extern "C" void fn_80529234(FeScrN* self);
extern "C" void fn_80529264(FeScrN* self);
extern "C" void fn_80529298(FeScrN* self);
extern "C" void fn_805292C8(FeScrN* self);
extern "C" void fn_80529334(FeScrN* self);
extern "C" int fn_80528DC0(void* x);
extern "C" int fn_80528F04(void* x);
extern "C" int fn_805290A8(void);
extern "C" int fn_805292F8(void);
extern "C" void fn_80528C88(FeVptr<0x10>* self, int c);
extern "C" void fn_80528CBC(FeVptr<0x10>* self, int c);
extern "C" void fn_80528CF0(FeVptr<0x10>* self, int c);
extern "C" void fn_80528D24(FeVptr<0x10>* self, int c);
extern "C" void fn_80528D58(FeVptr<0x10>* self, int c);
extern "C" void fn_80528D8C(FeVptr<0x10>* self, int c);
extern "C" void fn_80528E68(FeVptr<0x10>* self, int c);
extern "C" void fn_80528E9C(FeVptr<0x10>* self, int c);
extern "C" void fn_80528ED0(FeVptr<0x10>* self, int c);
extern "C" void fn_80528B78(void* x);
extern "C" void fn_80528C00(void* x);
extern "C" void fn_80528DC8(FeV10D* x, int a);
extern "C" void fn_80528E00(FeV10* x);
extern "C" void fn_80528E34(FeV10* x);
extern "C" void fn_80528F0C(FeV10D* x, int a);
extern "C" void fn_80528F44(FeV10* x);
extern "C" void fn_80528F78(FeV10* x);
extern "C" void fn_80529190(FeScrN* self);
extern "C" void fn_805291CC(FeScrN* self);
extern "C" void fn_80529300(FeScrN* x);

extern "C" FE_OVERLAY void fn_80528B78(void* x)
{
    FeSubOf(x)->s5();
}

extern "C" FE_OVERLAY void fn_80528C00(void* x)
{
    FeSubOf(x)->s11();
}

extern "C" FE_OVERLAY void fn_80528C88(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528CBC(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528CF0(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528D24(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528D58(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528D8C(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY int fn_80528DC0(void* x)
{
    return FeI(x, 0x20);
}

extern "C" FE_OVERLAY void fn_80528DC8(FeV10D* x, int a)
{
    x->m20 = a;
    x->s11();
}

extern "C" FE_OVERLAY void fn_80528E00(FeV10* x)
{
    x->s2();
}

extern "C" FE_OVERLAY void fn_80528E34(FeV10* x)
{
    x->s3();
}

extern "C" FE_OVERLAY void fn_80528E68(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528E9C(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528ED0(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY int fn_80528F04(void* x)
{
    return FeI(x, 0x14);
}

extern "C" FE_OVERLAY void fn_80528F0C(FeV10D* x, int a)
{
    x->m14 = a;
    x->s11();
}

extern "C" FE_OVERLAY void fn_80528F44(FeV10* x)
{
    x->s2();
}

extern "C" FE_OVERLAY void fn_80528F78(FeV10* x)
{
    x->s3();
}

extern "C" FE_OVERLAY void fn_80528FAC(void) {}

extern "C" FE_OVERLAY void fn_80528FB0(void) {}

extern "C" FE_OVERLAY int fn_80528FB4(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_80528FBC(void) {}

extern "C" FE_OVERLAY void fn_80528FC0(FeScrN* self)
{
    self->SetVptr(lbl_80679BF0);
    fn_804D2BCC(self);
}

extern "C" FE_OVERLAY void fn_80528FF0(FeScrN* self)
{
    self->SetVptr(lbl_80679920);
    fn_804D2BCC(self);
}

extern "C" FE_OVERLAY int fn_80529020(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_80529028(void) {}

extern "C" FE_OVERLAY void fn_8052902C(FeScrN* self)
{
    self->SetVptr(lbl_80655808);
    fn_800EC1B8(self);
}

extern "C" FE_OVERLAY int fn_805290A8(void)
{
    return 1;
}

extern "C" FE_OVERLAY void fn_805290B0(FeScrN* self)
{
    self->SetVptr(lbl_80678AB0);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_805290E0(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_805290E8(FeScrN* self)
{
    self->SetVptr(lbl_80655808);
    fn_800EC1B8(self);
}

extern "C" FE_OVERLAY int fn_80529118(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_80529120(FeScrN* self)
{
    self->SetVptr(lbl_80676060);
    fn_804D2BCC(self);
}

extern "C" FE_OVERLAY int fn_80529150(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_80529158(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_80529160(FeScrN* self)
{
    self->SetVptr(lbl_80674328);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529190(FeScrN* self)
{
    self->SetVptr(lbl_80674080);
    FeI(self, 0x158) = (int)lbl_806841F8;
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_805291C8(void) {}

extern "C" FE_OVERLAY void fn_805291CC(FeScrN* self)
{
    self->SetVptr(lbl_80673DD8);
    FeI(self, 0x1ac) = (int)lbl_8064A550;
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529204(FeScrN* self)
{
    self->SetVptr(lbl_80673B30);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529234(FeScrN* self)
{
    self->SetVptr(lbl_80673068);
    fn_804D2BCC(self);
}

extern "C" FE_OVERLAY void fn_80529264(FeScrN* self)
{
    self->SetVptr(lbl_80672DC0);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80529294(void) {}

extern "C" FE_OVERLAY void fn_80529298(FeScrN* self)
{
    self->SetVptr(lbl_80672830);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_805292C8(FeScrN* self)
{
    self->SetVptr(lbl_80672830);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_805292F8(void)
{
    return 8;
}

extern "C" FE_OVERLAY void fn_80529300(FeScrN* x)
{
    x->fn_vslot93();
}

extern "C" FE_OVERLAY void fn_80529334(FeScrN* self)
{
    self->SetVptr(lbl_80672830);
    fn_8035686C(self);
}
