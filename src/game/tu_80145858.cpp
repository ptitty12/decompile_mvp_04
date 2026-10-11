/*
 * Game code, .text 0x80145858-0x80145ECC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80144CF0.h"

struct UnkAt324F { char pad0[0x324]; float m324; };
struct UnkAt140 { char pad0[0x140]; int m140; };
struct UnkAt144 { char pad0[0x144]; int m144; };
struct UnkAt148 { char pad0[0x148]; int m148; };
struct UnkAt328 { char pad0[0x328]; void* m328; };
struct UnkAtCV { char pad0[0xC]; const void* mC; };
struct UnkAt4Scr { char pad0[4]; VT3C* m4; };
struct UnkAt8 { char pad0[0x8]; int m8; };
struct UnkAt30 { char pad0[0x30]; int m30; };
class UnkVCSlot13 {
public:
    int m0;
    int m4;
    int m8;
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int s10();
    virtual int s11();
    virtual int s12();
    virtual int s13();
};
struct UnkAt3CV { char pad0[0x3C]; const void* m3C; };
struct UnkAt34 { char pad0[0x34]; int m34; };
struct UnkAt38 { char pad0[0x38]; int m38; };
struct UnkAt3C { char pad0[0x3C]; int m3C; };
struct V4 { int a, b, c, d; };
struct UnkAt40V4 { char pad0[0x40]; V4 m40; };
struct UnkAt50V4 { char pad0[0x50]; V4 m50; };
struct UnkAt60 { char pad0[0x60]; int m60; };
struct UnkWithSub98 { char pad0[0x98]; VT24 m98; };
struct UnkAt50 { char pad0[0x50]; int m50; };
struct UnkAt54 { char pad0[0x54]; int m54; };
struct UnkAt40 { char pad0[0x40]; int m40; };
struct UnkAt44 { char pad0[0x44]; int m44; };
struct UnkAt48 { char pad0[0x48]; int m48; };
struct UnkAt4C { char pad0[0x4C]; int m4C; };

extern "C" {
float fn_80145858(UnkAt324F* p);
void fn_80145860(UnkAt140* p, int v);
void fn_80145868(UnkAt144* p, int v);
void fn_80145870(UnkAt148* p, int v);
int fn_80145878(UnkAt140* p);
int fn_80145880(UnkAt144* p);
int fn_80145888(UnkAt328* p);
void fn_801458BC(UnkAtCV* p, int c);
void fn_801458F0(void* a, void* b, int* r);
void fn_801458FC();
int fn_80145900();
int fn_80145908(UnkAt4Scr* p);
void fn_80145940(UnkAt8* p, int v);
void fn_80145948();
void fn_8014594C(UnkAt30* p, int v);
void fn_80145954(UnkAtCV* p, int c);
void fn_80145988(UnkAtCV* p, int c);
void fn_801459B8(UnkAtCV* p, int c);
void fn_801459EC(UnkAtCV* p, int c);
void fn_80145A1C(UnkAtCV* p, int c);
void fn_80145A50(UnkAtCV* p, int c);
void fn_80145A84(UnkVCSlot13* p, int a);
void fn_80145AC8();
void fn_80145ACC(UnkAtCV* p, int c);
void fn_80145B00(UnkAtCV* p, int c);
void fn_80145B34(UnkAtCV* p, int c);
void fn_80145B68(UnkAtCV* p, int c);
void fn_80145B9C();
void fn_80145BA0(UnkAt3CV* p, int c);
void fn_80145BD0(UnkAt3CV* p, int c);
int fn_80145C00();
int fn_80145C08();
int fn_80145C10();
int fn_80145C18();
int fn_80145C20();
int fn_80145C28(UnkAt34* p);
int fn_80145C30(char* p, int i);
int fn_80145C3C(UnkAt38* p);
void fn_80145C44(UnkAt38* p, int v);
int fn_80145C4C(UnkAt3C* p);
void fn_80145C54(UnkAt3C* p, int v);
V4 fn_80145C5C(UnkAt40V4* p);
void fn_80145C88(UnkAt40V4* p, V4* v);
void fn_80145CB0(UnkAt50V4* p, V4* v);
V4 fn_80145CD8(UnkAt50V4* p);
int fn_80145D04(UnkAt60* p);
void fn_80145D0C(UnkAt60* p, int v);
int fn_80145D14(UnkWithSub98* p, int a);
int fn_80145D80(UnkWithSub98* p);
char* fn_80145DE4(char* p, int i);
int fn_80145DF8(UnkAt50* p);
int fn_80145E00(UnkAt54* p);
int fn_80145E08(UnkAt40* p);
int fn_80145E10(UnkAt44* p);
void fn_80145E18(UnkAt44* p, int v);
int fn_80145E20(UnkAt48* p);
int fn_80145E28(UnkAt4C* p);
int fn_80145E30(VT3C* p);
int fn_80145E64(VT3C* p);
int fn_80145E98(VT3C* p);
int fn_803EE310(void*);
extern const char lbl_80659A60[];
void fn_80377408(void*);
extern const char lbl_80659908[];
void fn_80356CE0(void*, int);
extern const char lbl_80659828[];
extern const char lbl_80658A18[];
void fn_8011BFFC(void*, int);
extern const char lbl_80658730[];

float fn_80145858(UnkAt324F* p) { return p->m324; }

void fn_80145860(UnkAt140* p, int v) { p->m140 = v; }

void fn_80145868(UnkAt144* p, int v) { p->m144 = v; }

void fn_80145870(UnkAt148* p, int v) { p->m148 = v; }

int fn_80145878(UnkAt140* p) { return p->m140; }

int fn_80145880(UnkAt144* p) { return p->m144; }

int fn_80145888(UnkAt328* p)
{
    return p->m328 ? fn_803EE310(p->m328) : 0;
}

void fn_801458BC(UnkAtCV* p, int c) { p->mC = lbl_80659A60; if (c & 1) fn_80377408(p); }

void fn_801458F0(void* a, void* b, int* r) { *r = 0; }

void fn_801458FC() {}

int fn_80145900() { return 0x0; }

int fn_80145908(UnkAt4Scr* p)
{
    return p->m4->s8();
}

void fn_80145940(UnkAt8* p, int v) { p->m8 = v; }

void fn_80145948() {}

void fn_8014594C(UnkAt30* p, int v) { p->m30 = v; }

void fn_80145954(UnkAtCV* p, int c) { p->mC = lbl_80659A60; if (c & 1) fn_80377408(p); }

void fn_80145988(UnkAtCV* p, int c) { p->mC = lbl_80659908; fn_80356CE0(p, c); }

void fn_801459B8(UnkAtCV* p, int c) { p->mC = lbl_80659A60; if (c & 1) fn_80377408(p); }

void fn_801459EC(UnkAtCV* p, int c) { p->mC = lbl_80659828; fn_80356CE0(p, c); }

void fn_80145A1C(UnkAtCV* p, int c) { p->mC = lbl_80659A60; if (c & 1) fn_80377408(p); }

void fn_80145A50(UnkAtCV* p, int c) { p->mC = lbl_80659A60; if (c & 1) fn_80377408(p); }

void fn_80145A84(UnkVCSlot13* p, int a)
{
    if (a == p->m8) {
        p->s13();
    }
}

void fn_80145AC8() {}

void fn_80145ACC(UnkAtCV* p, int c) { p->mC = lbl_80659A60; if (c & 1) fn_80377408(p); }

void fn_80145B00(UnkAtCV* p, int c) { p->mC = lbl_80659A60; if (c & 1) fn_80377408(p); }

void fn_80145B34(UnkAtCV* p, int c) { p->mC = lbl_80659A60; if (c & 1) fn_80377408(p); }

void fn_80145B68(UnkAtCV* p, int c) { p->mC = lbl_80659A60; if (c & 1) fn_80377408(p); }

void fn_80145B9C() {}

void fn_80145BA0(UnkAt3CV* p, int c) { p->m3C = lbl_80658A18; fn_8011BFFC(p, c); }

void fn_80145BD0(UnkAt3CV* p, int c) { p->m3C = lbl_80658730; fn_8011BFFC(p, c); }

int fn_80145C00() { return 0x0; }

int fn_80145C08() { return 0x0; }

int fn_80145C10() { return 0x0; }

int fn_80145C18() { return 0x0; }

int fn_80145C20() { return 0x0; }

int fn_80145C28(UnkAt34* p) { return p->m34; }

int fn_80145C30(char* p, int i) { return *(int*)(p + (i << 2)); }

int fn_80145C3C(UnkAt38* p) { return p->m38; }

void fn_80145C44(UnkAt38* p, int v) { p->m38 = v; }

int fn_80145C4C(UnkAt3C* p) { return p->m3C; }

void fn_80145C54(UnkAt3C* p, int v) { p->m3C = v; }

V4 fn_80145C5C(UnkAt40V4* p) { return p->m40; }

void fn_80145C88(UnkAt40V4* p, V4* v) { p->m40 = *v; }

void fn_80145CB0(UnkAt50V4* p, V4* v) { p->m50 = *v; }

V4 fn_80145CD8(UnkAt50V4* p) { return p->m50; }

int fn_80145D04(UnkAt60* p) { return p->m60; }

void fn_80145D0C(UnkAt60* p, int v) { p->m60 = v; }

int fn_80145D14(UnkWithSub98* p, int a)
{
    return ((VT24*)&p->m98)->s9(((VT24*)&p->m98)->s5(), a);
}

int fn_80145D80(UnkWithSub98* p)
{
    return ((VT24*)&p->m98)->s10(((VT24*)&p->m98)->s5());
}

char* fn_80145DE4(char* p, int i) { return p + (i * 5 + 0xC0); }

int fn_80145DF8(UnkAt50* p) { return p->m50; }

int fn_80145E00(UnkAt54* p) { return p->m54; }

int fn_80145E08(UnkAt40* p) { return p->m40; }

int fn_80145E10(UnkAt44* p) { return p->m44; }

void fn_80145E18(UnkAt44* p, int v) { p->m44 = v; }

int fn_80145E20(UnkAt48* p) { return p->m48; }

int fn_80145E28(UnkAt4C* p) { return p->m4C; }

int fn_80145E30(VT3C* p) { return p->s38(); }

int fn_80145E64(VT3C* p) { return p->s39(); }

int fn_80145E98(VT3C* p) { return p->s40(); }

}
