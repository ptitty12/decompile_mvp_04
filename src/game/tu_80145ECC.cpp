/*
 * Game code, .text 0x80145ECC-0x801465AC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80144CF0.h"

struct UnkAt44 { char pad0[0x44]; int m44; };
struct UnkAt78 { char pad0[0x78]; int m78; };
struct UnkAt7C { char pad0[0x7C]; int m7C; };
struct UnkAt54 { char pad0[0x54]; int m54; };
struct UnkAt50 { char pad0[0x50]; int m50; };
struct UnkAt68 { char pad0[0x68]; int m68; };
struct UnkAt6C { char pad0[0x6C]; int m6C; };
struct UnkAt48 { char pad0[0x48]; int m48; };
struct UnkAt4C { char pad0[0x4C]; int m4C; };
struct UnkAt58 { char pad0[0x58]; int m58; };
struct UnkAt5C { char pad0[0x5C]; int m5C; };
struct UnkAt80B2 { char pad0[0x80]; unsigned : 2; unsigned b : 1; };
struct UnkAt74 { char pad0[0x74]; int m74; };
struct UnkAt70 { char pad0[0x70]; int m70; };
struct UnkAt60 { char pad0[0x60]; int m60; };
struct UnkAt64 { char pad0[0x64]; int m64; };
struct UnkAt80B4 { char pad0[0x80]; unsigned : 4; unsigned b : 1; };
struct UnkAt80B8 { char pad0[0x80]; unsigned : 8; unsigned b : 1; };
struct UnkAt80B5 { char pad0[0x80]; unsigned : 5; unsigned b : 1; };
struct UnkAt3CV { char pad0[0x3C]; const void* m3C; };
struct V4 { int a, b, c, d; };
struct UnkAt44V4 { char pad0[0x44]; V4 m44; };
struct UnkAt54V4 { char pad0[0x54]; V4 m54; };
struct UnkAt14C { char pad0[0x14C]; int m14C; };
struct UnkAt148 { char pad0[0x148]; int m148; };

extern "C" {
int fn_80145ECC(VT3C* p);
int fn_80145F00(VT3C* p);
int fn_80145F34(VT3C* p);
int fn_80145F68(VT3C* p);
int fn_80145F9C(VT3C* p);
int fn_80145FD0(VT3C* p);
int fn_80146004(VT3C* p);
int fn_80146038(VT3C* p);
int fn_8014606C(VT3C* p);
void fn_801460A0(UnkAt44* p, int v);
void fn_801460A8(UnkAt78* p, int v);
void fn_801460B0(UnkAt7C* p, int v);
int fn_801460B8(UnkAt54* p);
int fn_801460C0(UnkAt50* p);
int fn_801460C8(UnkAt68* p);
int fn_801460D0(UnkAt6C* p);
int fn_801460D8(UnkAt48* p);
int fn_801460E0(UnkAt4C* p);
int fn_801460E8(UnkAt58* p);
int fn_801460F0(UnkAt5C* p);
int fn_801460F8(UnkAt80B2* p);
int fn_80146104(VT3CD* p, int a);
int fn_8014613C(VT3CD* p, int a);
int fn_80146178(UnkAt74* p);
void fn_80146180(VT3CD* p, int a);
int fn_801461C4(UnkAt70* p);
void fn_801461CC(VT3CD* p, int a);
void fn_80146210(UnkAt58* p, int v);
void fn_80146218(UnkAt5C* p, int v);
int fn_80146220(UnkAt60* p);
int fn_80146228(UnkAt64* p);
int fn_80146230(VT3CD* p);
void fn_80146270(UnkAt80B4* p, int v);
int fn_80146280(UnkAt80B4* p);
int fn_8014628C(VT3CD* p);
void fn_80146328(UnkAt80B8* p, int v);
void fn_80146338(UnkAt80B5* p, int v);
int fn_80146348(UnkAt80B5* p);
int fn_80146354(VT3CD* p);
int fn_801463B4();
int fn_801463BC();
void fn_801463C4(UnkAt3CV* p, int c);
int fn_801463F4(UnkAt44* p);
int fn_801463FC(UnkAt48* p);
int fn_80146404(VT3CD* p, float a);
void fn_80146448(UnkAt44V4* p, V4* v);
void fn_80146470(UnkAt54V4* p, V4* v);
void fn_80146498(void* p, int a);
void fn_801464C0(void* p, int a);
void fn_801464E8(void* p, int a);
void fn_80146510(void* p, int a);
void fn_80146538(void* p, int a);
int fn_80146560();
void fn_80146568(UnkAt14C* p);
void fn_80146574(UnkAt14C* p);
int fn_80146580();
int fn_80146588();
int fn_80146590();
int fn_80146598();
void fn_801465A0(UnkAt148* p);
int fn_803EE310(void*);
extern const char lbl_806571E8[];
void fn_80356838(void*, int);
void fn_80125720(void*, int, int);

int fn_80145ECC(VT3C* p) { return p->s41(); }

int fn_80145F00(VT3C* p) { return p->s42(); }

int fn_80145F34(VT3C* p) { return p->s43(); }

int fn_80145F68(VT3C* p) { return p->s38(); }

int fn_80145F9C(VT3C* p) { return p->s39(); }

int fn_80145FD0(VT3C* p) { return p->s40(); }

int fn_80146004(VT3C* p) { return p->s41(); }

int fn_80146038(VT3C* p) { return p->s42(); }

int fn_8014606C(VT3C* p) { return p->s43(); }

void fn_801460A0(UnkAt44* p, int v) { p->m44 = v; }

void fn_801460A8(UnkAt78* p, int v) { p->m78 = v; }

void fn_801460B0(UnkAt7C* p, int v) { p->m7C = v; }

int fn_801460B8(UnkAt54* p) { return p->m54; }

int fn_801460C0(UnkAt50* p) { return p->m50; }

int fn_801460C8(UnkAt68* p) { return p->m68; }

int fn_801460D0(UnkAt6C* p) { return p->m6C; }

int fn_801460D8(UnkAt48* p) { return p->m48; }

int fn_801460E0(UnkAt4C* p) { return p->m4C; }

int fn_801460E8(UnkAt58* p) { return p->m58; }

int fn_801460F0(UnkAt5C* p) { return p->m5C; }

int fn_801460F8(UnkAt80B2* p) { return p->b; }

int fn_80146104(VT3CD* p, int a)
{
    return p->s67(a, p->m6C);
}

int fn_8014613C(VT3CD* p, int a)
{
    return p->s67(p->m68, a);
}

int fn_80146178(UnkAt74* p) { return p->m74; }

void fn_80146180(VT3CD* p, int a)
{
    p->m74 = a;
    if (p->m7C) {
        p->m7C->s35();
    }
}

int fn_801461C4(UnkAt70* p) { return p->m70; }

void fn_801461CC(VT3CD* p, int a)
{
    p->m70 = a;
    if (p->m78) {
        p->m78->s35();
    }
}

void fn_80146210(UnkAt58* p, int v) { p->m58 = v; }

void fn_80146218(UnkAt5C* p, int v) { p->m5C = v; }

int fn_80146220(UnkAt60* p) { return p->m60; }

int fn_80146228(UnkAt64* p) { return p->m64; }

int fn_80146230(VT3CD* p)
{
    return p->s111(p->m68, p->m6C);
}

void fn_80146270(UnkAt80B4* p, int v) { p->b = v; }

int fn_80146280(UnkAt80B4* p) { return p->b; }

int fn_8014628C(VT3CD* p)
{
    int a = p->m88 ? fn_803EE310(p->m88) : 0;
    int r = a;
    if (p->m8C) {
        r += fn_803EE310(p->m8C);
    }
    if (p->m90) {
        r += fn_803EE310(p->m90);
    }
    if (p->m94) {
        r += fn_803EE310(p->m94);
    }
    if (p->m98) {
        r += fn_803EE310(p->m98);
    }
    return r;
}

void fn_80146328(UnkAt80B8* p, int v) { p->b = v; }

void fn_80146338(UnkAt80B5* p, int v) { p->b = v; }

int fn_80146348(UnkAt80B5* p) { return p->b; }

int fn_80146354(VT3CD* p)
{
    int r = 0;
    if (!(p->m80 & 0x8000000) || p->s93()) {
        r = 1;
    }
    return r;
}

int fn_801463B4() { return 0x0; }

int fn_801463BC() { return 0x0; }

void fn_801463C4(UnkAt3CV* p, int c) { p->m3C = lbl_806571E8; fn_80356838(p, c); }

int fn_801463F4(UnkAt44* p) { return p->m44; }

int fn_801463FC(UnkAt48* p) { return p->m48; }

int fn_80146404(VT3CD* p, float a)
{
    return p->s20(a * *(float*)&p->m6C);
}

void fn_80146448(UnkAt44V4* p, V4* v) { p->m44 = *v; }

void fn_80146470(UnkAt54V4* p, V4* v) { p->m54 = *v; }

void fn_80146498(void* p, int a) { fn_80125720(p, 0x1, a); }

void fn_801464C0(void* p, int a) { fn_80125720(p, 0x2, a); }

void fn_801464E8(void* p, int a) { fn_80125720(p, 0x3, a); }

void fn_80146510(void* p, int a) { fn_80125720(p, 0x4, a); }

void fn_80146538(void* p, int a) { fn_80125720(p, 0x0, a); }

int fn_80146560() { return 0x0; }

void fn_80146568(UnkAt14C* p) { p->m14C = 0x1; }

void fn_80146574(UnkAt14C* p) { p->m14C = 0x0; }

int fn_80146580() { return 0x0; }

int fn_80146588() { return 0x0; }

int fn_80146590() { return 0x0; }

int fn_80146598() { return 0x0; }

void fn_801465A0(UnkAt148* p) { p->m148 = 0x1; }

}
