/*
 * Game code, .text 0x801465AC-0x80147748 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80144CF0.h"

struct UnkAt148 { char pad0[0x148]; int m148; };
struct UnkAt138 { char pad0[0x138]; int m138; };
struct UnkAt3CV { char pad0[0x3C]; const void* m3C; };
struct UnkAt140 { char pad0[0x140]; int m140; };
struct UnkAt0V { const void* m0; };
struct UnkAt160 { char pad0[0x160]; int m160; };
struct UnkAt164 { char pad0[0x164]; int m164; };
struct UnkAt14C { char pad0[0x14C]; int m14C; };
struct Unk3CVMulti { char pad0[0x3C]; const void* m3C; char pad1[0x184 - 0x40]; const void* m184; char pad2[0x1C8 - 0x188]; const void* m1C8; };

extern "C" {
void fn_801465AC(UnkAt148* p);
void fn_801465B8();
void fn_801465BC(UnkAt138* p, int v);
int fn_801465C4();
void fn_801465CC();
void fn_801465D0();
int fn_801465D4();
void fn_801465DC(UnkAt3CV* p, int c);
int fn_8014660C(VT3C* p, int a);
int fn_80146698(VT3C* p, int a);
int fn_80146724(VT3C* p, int a);
int fn_801467B0(VT3C* p, int a);
int fn_8014683C(VT3C* p, int a);
int fn_801468C8(VT3C* p, int a);
int fn_80146954(VT3C* p, int a);
int fn_801469E0(VT3C* p, int a);
int fn_80146A6C(VT3C* p, int a);
int fn_80146AF8(VT3C* p, int a);
int fn_80146B84(VT3C* p, int a);
int fn_80146C10(VT3C* p, int a);
int fn_80146C9C(VT3C* p, int a);
int fn_80146D28(VT3C* p, int a);
int fn_80146DB4(VT3C* p, int a);
int fn_80146E40(VT3C* p, int a);
int fn_80146ECC(VT3C* p, int a);
int fn_80146F58();
int fn_80146F60();
int fn_80146F68();
int fn_80146F70();
int fn_80146F78();
void fn_80146F80(UnkAt140* p);
int fn_80146F8C(UnkAt140* p);
void fn_80146F94(UnkAt3CV* p, int c);
void fn_80146FC4();
void fn_80146FC8();
void fn_80146FCC();
void fn_80146FD0(UnkAt0V* p, int c);
void fn_80147000();
int fn_80147020();
char* fn_8014702C();
void fn_80147038(UnkAt3CV* p, int c);
int fn_80147068(UnkAt160* p);
int fn_80147070(UnkAt164* p);
void fn_80147078(UnkAt14C* p, int v);
void fn_80147080(UnkAt3CV* p, int c);
void fn_801470B0(UnkAt3CV* p, int c);
/* near-miss: only the 'this' copy register differs (retail mr r8,r3; we use r9); all six store orders
   and local-pointer forms give the same r9 */
void fn_801470E0(Unk3CVMulti* p, int c);
void fn_80147120();
void fn_80147124();
int fn_80147128(UnkAt140* p);
int fn_80147130(VT3C* p, int a);
int fn_801471CC(VT3C* p, int a);
int fn_80147268(VT3C* p, int a);
int fn_80147304(VT3C* p, int a);
int fn_801473A0(VT3C* p, int a);
int fn_8014743C(VT3C* p, int a);
int fn_801474D8(VT3C* p, int a);
int fn_80147574(VT3C* p, int a);
int fn_80147610(VT3C* p, int a);
int fn_801476AC(VT3C* p, int a);
extern const char lbl_80655BA8[];
void fn_8035686C(void*, int);
extern const char lbl_80655808[];
void fn_800EC1B8(void*, int);
extern const char lbl_806557A8[];
void fn_8037B424(void*, int);
extern char lbl_805BA490[];
extern const char lbl_806554C8[];
extern const char lbl_806551F8[];
void fn_804D2BCC(void*, int);
extern const char lbl_80654C80[];
extern const char lbl_80655E98[];
void fn_800F4A30(void*);

void fn_801465AC(UnkAt148* p) { p->m148 = 0x0; }

void fn_801465B8() {}

void fn_801465BC(UnkAt138* p, int v) { p->m138 = v; }

int fn_801465C4() { return 0x1; }

void fn_801465CC() {}

void fn_801465D0() {}

int fn_801465D4() { return 0x0; }

void fn_801465DC(UnkAt3CV* p, int c) { p->m3C = lbl_80655BA8; fn_8035686C(p, c); }

int fn_8014660C(VT3C* p, int a) { return p->s88() ? p->s84(a)->s46(a) : 0; }

int fn_80146698(VT3C* p, int a) { return p->s88() ? p->s84(a)->s47(a) : 0; }

int fn_80146724(VT3C* p, int a) { return p->s88() ? p->s84(a)->s48(a) : 0; }

int fn_801467B0(VT3C* p, int a) { return p->s88() ? p->s84(a)->s49(a) : 0; }

int fn_8014683C(VT3C* p, int a) { return p->s88() ? p->s84(a)->s50(a) : 0; }

int fn_801468C8(VT3C* p, int a) { return p->s88() ? p->s84(a)->s51(a) : 0; }

int fn_80146954(VT3C* p, int a) { return p->s88() ? p->s84(a)->s52(a) : 0; }

int fn_801469E0(VT3C* p, int a) { return p->s88() ? p->s84(a)->s53(a) : 0; }

int fn_80146A6C(VT3C* p, int a) { return p->s88() ? p->s84(a)->s54(a) : 0; }

int fn_80146AF8(VT3C* p, int a) { return p->s88() ? p->s84(a)->s55(a) : 0; }

int fn_80146B84(VT3C* p, int a) { return p->s88() ? p->s84(a)->s56(a) : 0; }

int fn_80146C10(VT3C* p, int a) { return p->s88() ? p->s84(a)->s57(a) : 0; }

int fn_80146C9C(VT3C* p, int a) { return p->s88() ? p->s84(a)->s58(a) : 0; }

int fn_80146D28(VT3C* p, int a) { return p->s88() ? p->s84(a)->s59(a) : 0; }

int fn_80146DB4(VT3C* p, int a) { return p->s88() ? p->s84(a)->s60(a) : 0; }

int fn_80146E40(VT3C* p, int a) { return p->s88() ? p->s84(a)->s61(a) : 0; }

int fn_80146ECC(VT3C* p, int a) { return p->s88() ? p->s84(a)->s66(a) : 0; }

int fn_80146F58() { return 0x0; }

int fn_80146F60() { return 0x0; }

int fn_80146F68() { return 0x0; }

int fn_80146F70() { return 0x0; }

int fn_80146F78() { return 0x0; }

void fn_80146F80(UnkAt140* p) { p->m140 = 0x1; }

int fn_80146F8C(UnkAt140* p) { return p->m140; }

void fn_80146F94(UnkAt3CV* p, int c) { p->m3C = lbl_80655808; fn_800EC1B8(p, c); }

void fn_80146FC4() {}

void fn_80146FC8() {}

void fn_80146FCC() {}

void fn_80146FD0(UnkAt0V* p, int c) { p->m0 = lbl_806557A8; fn_8037B424(p, c); }

void fn_80147000() { fn_8014702C(); }

int fn_80147020() { return 0x6BC2DEDF; }

char* fn_8014702C() { return lbl_805BA490; }

void fn_80147038(UnkAt3CV* p, int c) { p->m3C = lbl_806554C8; fn_8035686C(p, c); }

int fn_80147068(UnkAt160* p) { return p->m160; }

int fn_80147070(UnkAt164* p) { return p->m164; }

void fn_80147078(UnkAt14C* p, int v) { p->m14C = v; }

void fn_80147080(UnkAt3CV* p, int c) { p->m3C = lbl_806551F8; fn_804D2BCC(p, c); }

void fn_801470B0(UnkAt3CV* p, int c) { p->m3C = lbl_80654C80; fn_804D2BCC(p, c); }

/* near-miss: only the 'this' copy register differs (retail mr r8,r3; we use r9); all six store orders
   and local-pointer forms give the same r9 */
void fn_801470E0(Unk3CVMulti* p, int c)
{
    p->m184 = lbl_80655E98;
    p->m3C = lbl_80655BA8;
    p->m1C8 = lbl_80655E98;
    fn_8035686C(p, c);
}

void fn_80147120() {}

void fn_80147124() {}

int fn_80147128(UnkAt140* p) { return p->m140; }

int fn_80147130(VT3C* p, int a) { int r = p->s88() ? p->s84(a)->s46(a) : 0; fn_800F4A30(p); return r; }

int fn_801471CC(VT3C* p, int a) { int r = p->s88() ? p->s84(a)->s47(a) : 0; fn_800F4A30(p); return r; }

int fn_80147268(VT3C* p, int a) { int r = p->s88() ? p->s84(a)->s48(a) : 0; fn_800F4A30(p); return r; }

int fn_80147304(VT3C* p, int a) { int r = p->s88() ? p->s84(a)->s49(a) : 0; fn_800F4A30(p); return r; }

int fn_801473A0(VT3C* p, int a) { int r = p->s88() ? p->s84(a)->s50(a) : 0; fn_800F4A30(p); return r; }

int fn_8014743C(VT3C* p, int a) { int r = p->s88() ? p->s84(a)->s51(a) : 0; fn_800F4A30(p); return r; }

int fn_801474D8(VT3C* p, int a) { int r = p->s88() ? p->s84(a)->s52(a) : 0; fn_800F4A30(p); return r; }

int fn_80147574(VT3C* p, int a) { int r = p->s88() ? p->s84(a)->s53(a) : 0; fn_800F4A30(p); return r; }

int fn_80147610(VT3C* p, int a) { int r = p->s88() ? p->s84(a)->s54(a) : 0; fn_800F4A30(p); return r; }

int fn_801476AC(VT3C* p, int a) { int r = p->s88() ? p->s84(a)->s55(a) : 0; fn_800F4A30(p); return r; }

}
