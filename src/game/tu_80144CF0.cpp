/*
 * Game code, .text 0x80144CF0-0x80145858 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80144CF0.h"

struct UnkAt18V { char pad0[0x18]; const void* m18; };
struct UnkAt8V28V { char pad0[0x8]; const void* m8; char pad1[0x1C]; const void* m28; };
struct UnkAt38 { char pad0[0x38]; int m38; };
struct UnkAt8VCV { char pad0[0x8]; const void* m8; char pad1[0x0]; const void* mC; };
struct UnkAt8V58V { char pad0[0x8]; const void* m8; char pad1[0x4C]; const void* m58; };
struct UnkAt3CV { char pad0[0x3C]; const void* m3C; };
struct UnkAt0 { int m0; };
struct UnkAt4 { char pad0[0x4]; int m4; };
struct UnkAt8B1 { char pad0[0x8]; unsigned : 1; unsigned b : 1; };
struct UnkWithSubDC { char pad0[0xDC]; VT24 mDC; };
struct UnkAt328F { char pad0[0x328]; float m328; };
struct UnkAt31CF { char pad0[0x31C]; float m31C; };
struct UnkAt320F { char pad0[0x320]; float m320; };

extern "C" {
int fn_80144CF0();
void fn_80144CF8();
void fn_80144CFC(UnkAt18V* p, int c);
int fn_80144D4C();
void fn_80144D54(UnkAt18V* p, int c);
int fn_80144D84();
void fn_80144D8C(UnkAt8V28V* p, int c);
int fn_80144DCC(VT8* p);
void fn_80144E00();
void fn_80144E04(UnkAt38* p, int v);
void fn_80144E0C(UnkAt8V28V* p, int c);
int fn_80144E4C();
void fn_80144E54(UnkAt8VCV* p, int c);
void fn_80144E94();
int fn_80144E98();
void fn_80144EA0();
void fn_80144EA4(UnkAt8V58V* p, int c);
int fn_80144EE4();
void fn_80144EEC();
void fn_80144EF0();
void fn_80144EF4();
int fn_80144EF8();
void fn_80144F00(UnkAt3CV* p, int c);
int fn_80144F30();
int fn_80144F38(VT1C8* p, int a);
int fn_80144F88(VT1C8* p, int a);
int fn_80144FD8(VT1C8* p, int a);
int fn_80145028(VT1C8* p, int a);
int fn_80145078(VT1C8* p, int a);
int fn_801450C8(VT1C8* p, int a);
int fn_80145118(VT1C8* p, int a);
int fn_80145168(VT1C8* p, int a);
int fn_801451B8(VT1C8* p, int a);
int fn_80145208(VT1C8* p, int a);
int fn_80145258(VT1C8* p, int a);
int fn_801452A8(VT1C8* p, int a);
int fn_801452F8(VT1C8* p, int a);
int fn_80145348(VT1C8* p, int a);
int fn_80145398(VT1C8* p, int a);
int fn_801453E8(VT1C8* p, int a);
int fn_80145438(VT1C8* p, int a);
int fn_80145488(VT1C8* p, int a);
int fn_801454D8(VT1C8* p, int a);
int fn_80145528(VT1C8* p, int a);
int fn_80145578(VT1C8* p, int a);
int fn_801455C8(VT1C8* p, int a);
int fn_80145618(VT1C8* p, int a);
int fn_80145668(VT1C8* p, int a);
int fn_801456B8(VT1C8* p, int a);
int fn_80145708(UnkAt0* p);
int fn_80145710(UnkAt4* p);
void fn_80145718(UnkAt4* p, int v);
void fn_80145720(UnkAt8B1* p, int v);
int fn_80145730(UnkAt8B1* p);
int fn_8014573C(VT24* p);
int fn_80145770(UnkWithSubDC* p, int a);
int fn_801457DC(UnkWithSubDC* p);
float fn_80145840(UnkAt328F* p);
float fn_80145848(UnkAt31CF* p);
float fn_80145850(UnkAt320F* p);
extern const char lbl_8065B010[];
void fn_800AD17C(void*, int);
void fn_800AB308(void*, int);
extern const char lbl_8065AF38[];
extern const char lbl_8065BA20[];
extern const char lbl_8065B360[];
void fn_80377408(void*);
extern const char lbl_8065B9C0[];
extern const char lbl_8065BA00[];
extern const char lbl_8065A640[];
void fn_8011BFFC(void*, int);
extern const Z8 lbl_805B9908;
extern const Z8 lbl_805B9910;
extern const Z8 lbl_805B9918;
extern const Z8 lbl_805B9920;
extern const Z8 lbl_805B9928;
extern const Z8 lbl_805B9930;
extern const Z8 lbl_805B9938;
extern const Z8 lbl_805B9940;
extern const Z8 lbl_805B9948;
extern const Z8 lbl_805B9950;
extern const Z8 lbl_805B9958;
extern const Z8 lbl_805B9960;
extern const Z8 lbl_805B9968;
extern const Z8 lbl_805B9970;
extern const Z8 lbl_805B9978;
extern const Z8 lbl_805B9980;
extern const Z8 lbl_805B9988;
extern const Z8 lbl_805B9990;
extern const Z8 lbl_805B9998;
extern const Z8 lbl_805B99A0;
extern const Z8 lbl_805B99A8;
extern const Z8 lbl_805B99B0;
extern const Z8 lbl_805B99B8;
extern const Z8 lbl_805B99C0;
extern const Z8 lbl_805B99C8;

int fn_80144CF0() { return 0x1; }

void fn_80144CF8() {}

void fn_80144CFC(UnkAt18V* p, int c)
{
    p->m18 = lbl_8065B010;
    fn_800AD17C((char*)p + 0x448, 2);
    fn_800AB308(p, c);
}

int fn_80144D4C() { return 0x1; }

void fn_80144D54(UnkAt18V* p, int c) { p->m18 = lbl_8065AF38; fn_800AB308(p, c); }

int fn_80144D84() { return 0x1; }

void fn_80144D8C(UnkAt8V28V* p, int c) { p->m28 = lbl_8065BA20; p->m8 = lbl_8065B360; if (c & 1) fn_80377408(p); }

int fn_80144DCC(VT8* p) { return p->s18(); }

void fn_80144E00() {}

void fn_80144E04(UnkAt38* p, int v) { p->m38 = v; }

void fn_80144E0C(UnkAt8V28V* p, int c) { p->m28 = lbl_8065BA20; p->m8 = lbl_8065B360; if (c & 1) fn_80377408(p); }

int fn_80144E4C() { return 0x1; }

void fn_80144E54(UnkAt8VCV* p, int c) { p->mC = lbl_8065B9C0; p->m8 = lbl_8065B360; if (c & 1) fn_80377408(p); }

void fn_80144E94() {}

int fn_80144E98() { return 0x1; }

void fn_80144EA0() {}

void fn_80144EA4(UnkAt8V58V* p, int c) { p->m58 = lbl_8065BA00; p->m8 = lbl_8065B360; if (c & 1) fn_80377408(p); }

int fn_80144EE4() { return 0x1; }

void fn_80144EEC() {}

void fn_80144EF0() {}

void fn_80144EF4() {}

int fn_80144EF8() { return 0x0; }

void fn_80144F00(UnkAt3CV* p, int c) { p->m3C = lbl_8065A640; fn_8011BFFC(p, c); }

int fn_80144F30() { return 0x1; }

int fn_80144F38(VT1C8* p, int a) { return p->s3(a, lbl_805B9908); }

int fn_80144F88(VT1C8* p, int a) { return p->s3(a, lbl_805B9910); }

int fn_80144FD8(VT1C8* p, int a) { return p->s3(a, lbl_805B9918); }

int fn_80145028(VT1C8* p, int a) { return p->s3(a, lbl_805B9920); }

int fn_80145078(VT1C8* p, int a) { return p->s3(a, lbl_805B9928); }

int fn_801450C8(VT1C8* p, int a) { return p->s3(a, lbl_805B9930); }

int fn_80145118(VT1C8* p, int a) { return p->s3(a, lbl_805B9938); }

int fn_80145168(VT1C8* p, int a) { return p->s3(a, lbl_805B9940); }

int fn_801451B8(VT1C8* p, int a) { return p->s3(a, lbl_805B9948); }

int fn_80145208(VT1C8* p, int a) { return p->s3(a, lbl_805B9950); }

int fn_80145258(VT1C8* p, int a) { return p->s3(a, lbl_805B9958); }

int fn_801452A8(VT1C8* p, int a) { return p->s3(a, lbl_805B9960); }

int fn_801452F8(VT1C8* p, int a) { return p->s3(a, lbl_805B9968); }

int fn_80145348(VT1C8* p, int a) { return p->s3(a, lbl_805B9970); }

int fn_80145398(VT1C8* p, int a) { return p->s3(a, lbl_805B9978); }

int fn_801453E8(VT1C8* p, int a) { return p->s3(a, lbl_805B9980); }

int fn_80145438(VT1C8* p, int a) { return p->s3(a, lbl_805B9988); }

int fn_80145488(VT1C8* p, int a) { return p->s3(a, lbl_805B9990); }

int fn_801454D8(VT1C8* p, int a) { return p->s3(a, lbl_805B9998); }

int fn_80145528(VT1C8* p, int a) { return p->s3(a, lbl_805B99A0); }

int fn_80145578(VT1C8* p, int a) { return p->s3(a, lbl_805B99A8); }

int fn_801455C8(VT1C8* p, int a) { return p->s3(a, lbl_805B99B0); }

int fn_80145618(VT1C8* p, int a) { return p->s3(a, lbl_805B99B8); }

int fn_80145668(VT1C8* p, int a) { return p->s3(a, lbl_805B99C0); }

int fn_801456B8(VT1C8* p, int a) { return p->s3(a, lbl_805B99C8); }

int fn_80145708(UnkAt0* p) { return p->m0; }

int fn_80145710(UnkAt4* p) { return p->m4; }

void fn_80145718(UnkAt4* p, int v) { p->m4 = v; }

void fn_80145720(UnkAt8B1* p, int v) { p->b = v; }

int fn_80145730(UnkAt8B1* p) { return p->b; }

int fn_8014573C(VT24* p) { return p->s11(); }

int fn_80145770(UnkWithSubDC* p, int a)
{
    return ((VT24*)&p->mDC)->s9(((VT24*)&p->mDC)->s5(), a);
}

int fn_801457DC(UnkWithSubDC* p)
{
    return ((VT24*)&p->mDC)->s10(((VT24*)&p->mDC)->s5());
}

float fn_80145840(UnkAt328F* p) { return p->m328; }

float fn_80145848(UnkAt31CF* p) { return p->m31C; }

float fn_80145850(UnkAt320F* p) { return p->m320; }

}
