/*
 * Game code, .text 0x8011C5E8-0x8012068C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk800C7B40_Widget Wid;
/* Front-end HUD screens (HUDLEFTBMG ctor fn_8011C800, HUDRIGHTPMG ctor fn_8011E5BC; both derive from the
 * fn_8011BFAC class). Widget pointers by use; ints where the code does arithmetic on them. */
struct Unk8011C5E8_Hud : Unk80117D20_Scr {
    int m138;
    Wid* m13C;
    char pad140[0x4];
    Wid* m144;
    Wid* m148;
    Wid* m14C;
    Wid* m150;
    Wid* m154;
    Wid* m158;
    Wid* m15C;
    Wid* m160;
    Wid* m164;
    Wid* m168;
    Wid* m16C;
    Wid* m170;
    Wid* m174;
    Wid* m178;
    Wid* m17C;
    Wid* m180;
    Wid* m184;
    char pad188[0x4];
    Wid* m18C;
    Wid* m190;
    Wid* m194;
    Wid* m198;
    Wid* m19C;
    Wid* m1A0;
    Wid* m1A4;
    Wid* m1A8;
    Wid* m1AC;
    Wid* m1B0;
    Wid* m1B4;
    Wid* m1B8;
    Wid* m1BC;
    Wid* m1C0;
    Wid* m1C4;
    int m1C8;
    int m1CC;
    int m1D0;
    int m1D4;
    int m1D8;
    int m1DC;
    int m1E0;
};
typedef Unk8011C5E8_Hud Scr;

struct Unk8068B618 {
    char pad0[0x24];
    int m24;
};
extern Unk8068B618* lbl_8068B618;
extern char* lbl_8061A328;
extern const char lbl_805B97B4[];
extern const char lbl_805BA230[];
Unk8001C314* fn_8001C394();

extern const char lbl_80658730[];
extern const char lbl_805BFD3C[];
extern const char lbl_805C0240[];
extern const char lbl_80658A18[];
extern const float lbl_805C00F8;
extern int lbl_8061B3B8;
extern int lbl_8061977C;
extern const char lbl_805C0028[];
extern const char lbl_805BED00[];
extern const char lbl_805BED0C[];
extern const char lbl_805BED18[];
extern const char lbl_805BED24[];
extern const char lbl_805BED30[];
extern const char lbl_805BED3C[];
extern const char lbl_805C0250[];
extern const char lbl_805BE0C8[];
extern const float lbl_805C00EC;
extern const char lbl_805BC1A8[];
extern const char lbl_805C01F4[];
extern const char lbl_805C0200[];
extern const char lbl_805C0210[];
extern const char lbl_805C021C[];
extern const char lbl_805C0008[];
extern const char lbl_805C0018[];
extern const char lbl_805BE6A4[];
extern const char lbl_805C01E8[];
extern const char lbl_805BE69C[];
struct Unk800AEC80 {
    char pad0[0xD8];
    int mD8;
    char padDC[0x38];
    int m114;
};
extern const char lbl_8064FE18[];
extern const char lbl_805C0034[];
extern const char lbl_805C0040[];
extern const char lbl_805C004C[];
extern const char lbl_805C005C[];
extern const char lbl_805C00AC[];
extern const char lbl_805C00BC[];
extern const char lbl_805C00C8[];
extern const char lbl_805C00D4[];
extern const char lbl_805C00E0[];

extern const char lbl_805BE42C[];
extern const char lbl_805C006C[];
extern const char lbl_805C007C[];
extern const char lbl_805C008C[];
extern const char lbl_805C009C[];
extern const char lbl_805BA6D0[];
extern const char lbl_805C0268[];
extern "C" void fn_800ECF18(void*);
extern "C" void fn_802DC9C0();
extern "C" Wid* fn_800B7A94(UnkFEMgr* m, const char* name);
extern "C" void fn_80124FA8(Wid* w, void* x);
extern "C" void fn_801251CC(Wid* w, int a, int b, int c);
extern "C" void fn_800C80C0(Wid* w, int v);
extern "C" void fn_8012075C(void*);
// PROTOS-BEGIN
extern "C" {
void fn_8011C5E8(Unk80117D20_Scr* self);
void fn_8011C6D0(Scr* self);
void fn_8011C768(Scr* self);
void* fn_8011C800(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_8011D0D0(Scr* self);
void fn_8011D614(Scr* self, int a);
void fn_8011D67C(Scr* self, int unused, int a);
void fn_8011D6E4(Scr* self, int a);
void fn_8011D798(Scr* self, int a);
void fn_8011D850(Scr* self, int a, int b);
void fn_8011D8C8(Scr* self, int a, int b);
void fn_8011DBCC(Scr* self);
void fn_8011DC70(Scr* self, int a);
void fn_8011E220(Scr* self, int a);
void fn_8011E26C(Scr* self);
void fn_8011E2E8(Scr* self, int a);
void fn_8011E3B4();
void fn_8011E3F4(Scr* self);
void fn_8011E414(Scr* self);
void fn_8011E434(Scr* self, int a);
void fn_8011E4E4(Scr* self, float f);
void* fn_8011E5BC(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_8011EEB0(Scr* self, int a);
void fn_8011EF64(Scr* self, int a);
void fn_8011F020(Scr* self);
void fn_8011F070(Scr* self);
void fn_8011F0C0(Scr* self);
void fn_8011F0F4(Scr* self);
void fn_8011F1A4(Scr* self, int a, int b);
void fn_8011F274(Scr* self);
void fn_8011F360(Scr* self, int a);
void fn_8011F410(Scr* self);
Wid* fn_8011F4B8(Scr* self, int i);
Wid* fn_8011F548(Scr* self, int i);
Wid* fn_8011F5D8(Scr* self, int i);
int* fn_8011FAA4(Scr* self, int unused, int a, int b);
void fn_8011FFB4(Scr* self);
void fn_8012004C(Scr* self, int a, int b);
void fn_801200C4(Scr* self, int a);
void fn_80120144(Scr* self, float f);
void fn_8012031C(Unk80117D20_Scr* self);
void fn_801203D0();
void fn_80120410(Scr* self);
void fn_80120430(Scr* self);
void* fn_80120450(Unk80120450_Diff* self, int a, int b, int c, int d, int e, int f, int g, int h);
}
// PROTOS-END
extern "C" {
void fn_8011C6D0(Scr* self);
void fn_8011C768(Scr* self);
void fn_8011C114(Scr* self);
void fn_8011C15C(Scr* self);
void fn_8011F0F4(Scr* self);
void fn_803FFC58(void* p, int c, int n);
void fn_8011C04C(Scr* self);
void fn_8035682C(void* name);
void fn_8040B830(void* dst, const char* src, int n);
void fn_800B7B4C(UnkFEMgr* m, const void* name, void* obj);
int fn_8011B5A4();
void* fn_8011BFAC(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_8011B148(int a, Wid* w1, int* p1, Wid* w2, int* p2);
int fn_80090880(int mgr, int id);
int fn_80403DE4(void* buf, int fmt, ...);
void fn_800A74C8(void* p, int a);
Unk800AEC80* fn_800AEC80(int a);
void fn_8011AFD4(int a, UnkLabel* l1, int b, UnkLabel* l2, int c, int d, Wid* e);
void fn_802D7ADC();
void fn_801389A4(void* w, int a);
Wid* fn_800B7AB8(UnkFEMgr* m, const char* name);
int fn_800AB5C8(int a);
void fn_800AE964(int a, int b);
void fn_8011FFB4(Scr* self);
void fn_8011F410(Scr* self);
extern int lbl_80619D10;
int* fn_800ED2B0(Wid* container, const char* name);
int* fn_800CFB38(int* p);
void fn_800CFE84(int* p);
void* fn_8004072C();
int fn_800412AC(void* o, int a, int b, int c, int d, int e);
void fn_8011DBCC(Scr* self);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
}

extern "C" {

void fn_8011C5E8(Unk80117D20_Scr* self)
{
    fn_800CFB38(fn_800ED2B0(self, lbl_805B97B4));
    if (fn_8001C394()->fn_8001CC40(1) != 0)
        fn_800412AC(fn_8004072C(), 0x25, 0, 0, 0, 0);
    else
        fn_800412AC(fn_8004072C(), 0x30, 0, 0, 0, 0);
    self->m134 = (int)(lbl_8061A328 + 0x78);
    lbl_8068B618->m24 = 1;
    fn_802D7ADC();
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_801389A4(fn_800B7AB8(lbl_8061A32C, lbl_805BA230), 0);
}

void fn_8011C6D0(Scr* self)
{
    self->fn_vslot89();
    char nm[16];
    char* np = nm;
    fn_8035682C(np);
    fn_8040B830(np, lbl_805BFD3C, 0xF);
    np[15] = 0;
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7B4C(lbl_8061A32C, np, 0);
}

void fn_8011C768(Scr* self)
{
    self->fn_vslot89();
    char nm[16];
    char* np = nm;
    fn_8035682C(np);
    fn_8040B830(np, lbl_805B97B4, 0xF);
    np[15] = 0;
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7B4C(lbl_8061A32C, np, 0);
}

void* fn_8011C800(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_8011BFAC(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80658730);
    self->m138 = 0;
    self->m1A4 = 0;
    self->m1A8 = 0;
    self->m1AC = 0;
    self->m1B0 = 0;
    self->m1B4 = 0;
    self->m1B8 = 0;
    self->m1BC = 0;
    self->m1C0 = 0;
    self->m1C4 = 0;
    self->m1C8 = 0;
    self->m1CC = 0;
    self->m1D0 = 0;
    self->m1D4 = 0;
    self->m1D8 = -1;
    self->m1DC = 5;
    lbl_8061B3B8 = fn_8011B5A4();
    fn_803FFC58((char*)self + 0x13C, 0, 0x68);
    return self;
}

void fn_8011D0D0(Scr* self)
{
    fn_8011C114(self);
    fn_803FFC58((char*)self + 0x13C, 0, 0x68);
    self->m1B4 = 0;
}

void fn_8011D614(Scr* self, int a)
{
    if (a == 0)
        self->m1AC->fn_vslot8(0);
    else
        self->m1AC->fn_vslot8(1);
}

void fn_8011D67C(Scr* self, int unused, int a)
{
    if (a == 0)
        self->m1A8->fn_vslot8(0);
    else
        self->m1A8->fn_vslot8(1);
}

void fn_8011D6E4(Scr* self, int a)
{
    if (self->m1D8 != a && (unsigned)a <= 10) {
        self->m1D8 = a;
        Wid* w1 = fn_800C8054(self->m144);
        int* p1 = fn_800ED2B0(self->m1A4, lbl_805C0008);
        Wid* w2 = fn_800C8054(self->m148);
        fn_8011B148(a, w1, p1, w2, fn_800ED2B0(self->m1A4, lbl_805C0018));
        fn_800412AC(fn_8004072C(), 0x22, self->m1D8, 0, 0, 0);
    }
}

void fn_8011D798(Scr* self, int a)
{
    UnkTextArg buf;
    fn_80403DE4(&buf, fn_80090880(lbl_8061977C, 0x2338), a);
    fn_800C8040(fn_800C8044(self->m13C)->fn_vslot32(lbl_805C0028, 1))->fn_vslot28(&buf);
    fn_800A74C8((char*)lbl_806192E0->m4->mC + 0xA0, a);
}

void fn_8011D850(Scr* self, int a, int b)
{
    UnkLabel* l1 = fn_800C8040(self->m150);
    UnkLabel* l2 = fn_800C8040(self->m14C);
    int c = (int)self->m1B8;
    int d = (int)self->m1C0;
    fn_8011AFD4(a, l1, b, l2, c, d, fn_800C8038(self->m154));
}

void fn_8011D8C8(Scr* self, int a, int b)
{
    char buf[0x20];
    fn_804089B4(buf, lbl_805BC1A8, a);
    fn_800C8048(self->m158)->fn_vslot30(buf);
    if (a < 0)
        fn_800C8048(self->m158)->fn_vslot17(1);
    else
        fn_800C8048(self->m158)->fn_vslot17(0);
    fn_804089B4(buf, lbl_805BC1A8, b);
    fn_800C8048(self->m160)->fn_vslot30(buf);
    if (b < 0)
        fn_800C8048(self->m160)->fn_vslot17(1);
    else
        fn_800C8048(self->m160)->fn_vslot17(0);
}

void fn_8011DA18(Scr* self, int a)
{
    char buf[0x20];
    fn_804089B4(buf, lbl_805BC1A8, a);
    fn_800C8048(self->m15C)->fn_vslot30(buf);
    if (a < 0)
        fn_800C8048(self->m15C)->fn_vslot17(1);
    else
        fn_800C8048(self->m15C)->fn_vslot17(0);
    int* p = fn_800ED2B0(self->m1A4, lbl_805C0034);
    int* q = fn_800ED2B0(self->m1A4, lbl_805C0040);
    switch (a) {
    case 0x1F4:
        if (*p == 0)
            fn_800CFB38(p);
        *q = 0;
        fn_800C8038(self->m16C)->fn_vslot8(0);
        break;
    case 0x2EE:
        if (*q == 0)
            fn_800CFB38(q);
        *p = 0;
        fn_800C8038(self->m168)->fn_vslot8(0);
        break;
    default:
        *p = 0;
        fn_800C8038(self->m168)->fn_vslot8(0);
        *q = 0;
        fn_800C8038(self->m16C)->fn_vslot8(0);
        break;
    }
}

void fn_8011DBCC(Scr* self)
{
    int* a = fn_800ED2B0(self->m1A4, lbl_805C0034);
    int* b = fn_800ED2B0(self->m1A4, lbl_805C0040);
    *a = 0;
    fn_800C8038(self->m168)->fn_vslot8(0);
    *b = 0;
    fn_800C8038(self->m16C)->fn_vslot8(0);
}

void fn_8011DC70(Scr* self, int a)
{
    if ((int)self->m1C4 != a) {
        if (a != 0) {
            int* p = fn_800ED2B0(self->m1A4, lbl_805C004C);
            if (*p != 0)
                fn_800CFE84(p);
            fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C005C));
        } else {
            int* p = fn_800ED2B0(self->m1A4, lbl_805C005C);
            if (*p != 0)
                fn_800CFE84(p);
            fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C004C));
            fn_8011DBCC(self);
        }
    }
    self->m1C4 = (Wid*)a;
}

void fn_8011DD28(Scr* self, int a)
{
    char buf[0x20];
    fn_804089B4(buf, lbl_805BE42C, a);
    fn_800C8048(self->m170)->fn_vslot30(buf);
    switch (a) {
    case 0x32:
        fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C006C));
        break;
    case 0x64:
        fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C007C));
        break;
    case 0x190:
        fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C008C));
        break;
    case 0x3E8:
        fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C009C));
        break;
    }
}

void fn_8011E220(Scr* self, int a)
{
    fn_800C8044(self->m174)->fn_vslot8(a);
}

void fn_8011E26C(Scr* self)
{
    fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C00AC));
    fn_800412AC(fn_8004072C(), 0x24, 0, 0, 0, 0);
    fn_800C8044(self->m178)->fn_vslot8(1);
}

void fn_8011E2E8(Scr* self, int a)
{
    if (self->m1C8 != a) {
        if (a != 0) {
            int* p = fn_800ED2B0(self->m1A4, lbl_805C00BC);
            if (*p != 0)
                fn_800CFE84(p);
            fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C00C8));
            fn_800412AC(fn_8004072C(), 0x11, 0, 0, 0, 0);
        } else {
            int* p = fn_800ED2B0(self->m1A4, lbl_805C00C8);
            if (*p != 0)
                fn_800CFE84(p);
            fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C00BC));
        }
    }
    self->m1C8 = a;
}

void fn_8011E3B4()
{
    int v = fn_8011AA24(0)->m6F8->m10->m70;
    fn_800B555C()->m570 = v;
}

void fn_8011E3F4(Scr* self)
{
    fn_8011C6D0(self);
}

void fn_8011E414(Scr* self)
{
    fn_8011C768(self);
}

void fn_8011E434(Scr* self, int a)
{
    if (self->m1D4 != a) {
        if (a != 0) {
            int* p = fn_800ED2B0(self->m1A4, lbl_805C00D4);
            if (*p != 0)
                fn_800CFE84(p);
            fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C00E0));
        } else {
            int* p = fn_800ED2B0(self->m1A4, lbl_805C00E0);
            if (*p != 0)
                fn_800CFE84(p);
            fn_800CFB38(fn_800ED2B0(self->m1A4, lbl_805C00D4));
        }
    }
    self->m1D4 = a;
}

void fn_8011E4E4(Scr* self, float f)
{
    char buf[0x20];
    fn_804089B4(buf, lbl_805BE0C8, f * lbl_805C00EC);
    fn_800C8048(self->m19C)->fn_vslot30(buf);
    fn_800C8038(self->m1A0)->fn_vslot12((int)(f * (float)(int)self->m1BC));
}

void* fn_8011E5BC(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_8011BFAC(self, a, b, c, d, e, f, g, h);
    self->m1A8 = 0;
    self->m1AC = 0;
    self->m1B0 = 0;
    self->m1B4 = 0;
    self->m1B8 = 0;
    self->m1BC = 0;
    self->m1C0 = 0;
    self->m1C4 = 0;
    self->m1C8 = 0;
    self->m1CC = 0;
    self->m1DC = 0;
    self->m1E0 = 0;
    self->SetVptr(lbl_80658A18);
    *(float*)&self->m1D8 = lbl_805C00F8;
    fn_803FFC58((char*)self + 0x138, 0, 0x70);
    self->m1D4 = 0;
    return self;
}

void fn_8011EEB0(Scr* self, int a)
{
    self->m1B4->fn_vslot8(a);
    fn_800C8044(self->m1A4)->fn_vslot8(a);
    fn_800C8044(self->m18C)->fn_vslot32(lbl_805BE6A4, 1)->fn_vslot8(a);
}

void fn_8011EF64(Scr* self, int a)
{
    fn_800C8044(self->m18C)->fn_vslot32(lbl_805C01E8, 1)->fn_vslot8(a);
    fn_800C8044(self->m18C)->fn_vslot32(lbl_805BE69C, 1)->fn_vslot8(a);
}

void fn_8011F020(Scr* self)
{
    fn_8011C04C(self);
    fn_8011F410(self);
    fn_8011F0F4(self);
    fn_800AE964(fn_800AB5C8(lbl_80619D10), 1);
}

void fn_8011F070(Scr* self)
{
    fn_8011C114(self);
    fn_803FFC58((char*)self + 0x138, 0, 0x70);
    fn_800AE964(fn_800AB5C8(lbl_80619D10), 0);
}

void fn_8011F0C0(Scr* self)
{
    fn_8011C15C(self);
    fn_8011F0F4(self);
}

void fn_8011F0F4(Scr* self)
{
    UnkTextArg buf;
    Unk800AEC80* o = fn_800AEC80(fn_800AB5C8(lbl_80619D10));
    fn_80403DE4(&buf, fn_80090880(lbl_8061977C, 0x2338), o->m114 + 1);
    fn_800C8040(fn_800C8044(self->m18C)->fn_vslot32(lbl_805C0028, 1))->fn_vslot28(&buf);
}

void fn_8011F1A4(Scr* self, int a, int b)
{
    const char* name;
    Wid* w;
    if (b != 0) {
        name = lbl_805C01F4;
        w = self->m1C4;
    } else {
        name = lbl_805C0200;
        w = self->m1C0;
    }
    int* p = fn_800ED2B0(self, name);
    char buf[0x40];
    fn_80403DE4(&buf, fn_80090880(lbl_8061977C, 0x5A29), a);
    fn_800C8040(w->fn_vslot33(4, 1))->fn_vslot28(&buf);
    *p = 0;
    fn_800CFB38(p);
}

void fn_8011F274(Scr* self)
{
    if (fn_800AEC80(fn_800AB5C8(lbl_80619D10))->mD8 == 1)
        self->m1BC->fn_vslot32(lbl_805BE69C, 1)->fn_vslot8(0);
    else
        self->m1BC->fn_vslot32(lbl_805BE6A4, 1)->fn_vslot8(0);
    int* p = fn_800ED2B0(self, lbl_805C0210);
    *p = 0;
    fn_800CFB38(p);
}

void fn_8011F360(Scr* self, int a)
{
    char buf[0x40];
    fn_80403DE4(&buf, fn_80090880(lbl_8061977C, 0x5A2A), a);
    fn_800C8040(self->m1B8->fn_vslot33(4, 1))->fn_vslot28(&buf);
    int* p = fn_800ED2B0(self, lbl_805C021C);
    *p = 0;
    fn_800CFB38(p);
}

void fn_8011F410(Scr* self)
{
    self->m1B8->fn_vslot8(0);
    self->m1BC->fn_vslot8(0);
    self->m1C0->fn_vslot8(0);
    self->m1C4->fn_vslot8(0);
}

Wid* fn_8011F4B8(Scr* self, int i)
{
    switch (i) {
    case 0:
        return fn_800C8044(self->m148);
    case 1:
        return fn_800C8044(self->m14C);
    case 2:
        return fn_800C8044(self->m150);
    case 3:
        return fn_800C8044(self->m154);
    case 4:
        return fn_800C8044(self->m158);
    default:
        return 0;
    }
}

Wid* fn_8011F548(Scr* self, int i)
{
    switch (i) {
    case 0:
        return fn_800C8054(self->m160);
    case 1:
        return fn_800C8054(self->m164);
    case 2:
        return fn_800C8054(self->m168);
    case 3:
        return fn_800C8054(self->m16C);
    case 4:
        return fn_800C8054(self->m170);
    default:
        return 0;
    }
}

Wid* fn_8011F5D8(Scr* self, int i)
{
    switch (i) {
    case 0:
        return fn_800C8038(self->m174);
    case 1:
        return fn_800C8038(self->m178);
    case 2:
        return fn_800C8038(self->m17C);
    case 3:
        return fn_800C8038(self->m180);
    case 4:
        return fn_800C8038(self->m184);
    default:
        return 0;
    }
}

int* fn_8011FAA4(Scr* self, int unused, int a, int b)
{
    int c = 1;
    if (self->m1A8->b0 || (c = 0, self->m1AC->b0)) {
        const char* name;
        if (a != 0) {
            if (c != 0)
                name = lbl_805BED00;
            else
                name = lbl_805BED0C;
        } else if (b != 0) {
            if (c != 0)
                name = lbl_805BED18;
            else
                name = lbl_805BED24;
        } else {
            if (c != 0)
                name = lbl_805BED30;
            else
                name = lbl_805BED3C;
        }
        int* p = fn_800ED2B0(self, name);
        if (p != 0)
            p = fn_800CFB38(p);
        return p;
    }
    return (int*)self;
}

void fn_8011FFB4(Scr* self)
{
    self->fn_vslot89();
    char nm[16];
    char* np = nm;
    fn_8035682C(np);
    fn_8040B830(np, lbl_805C0240, 0xF);
    np[15] = 0;
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7B4C(lbl_8061A32C, np, 0);
}

void fn_8012004C(Scr* self, int a, int b)
{
    UnkLabel* l1 = fn_800C8040(self->m194);
    UnkLabel* l2 = fn_800C8040(self->m190);
    int c = self->m1DC;
    int d = self->m1E0;
    fn_8011AFD4(a, l1, b, l2, c, d, fn_800C8038(self->m198));
}

void fn_801200C4(Scr* self, int a)
{
    Wid* w1 = fn_800C8054(self->m19C);
    int* p1 = fn_800ED2B0(self->m1B0, lbl_805C0008);
    Wid* w2 = fn_800C8054(self->m1A0);
    fn_8011B148(a, w1, p1, w2, fn_800ED2B0(self->m1B0, lbl_805C0018));
}

void fn_80120144(Scr* self, float f)
{
    char buf[0x40];
    buf[0] = 0;
    fn_804089B4(buf, lbl_805C0250, f);
    ((UnkLabel*)self->m1B4)->fn_vslot30(buf);
}

extern "C" void fn_801201B4(float f, Scr* self, int a)
{
    Wid* w = fn_800C8044(self->m1A4);
    if (!(f <= 0.0f || f >= 100.0f)) {
        w->fn_vslot10(self->m1E0 + self->m1DC - (int)((float)self->m1DC * f));
        w->fn_vslot8(1);
        char buf[0x10];
        buf[0] = 0;
        fn_804089B4(buf, lbl_805BC1A8, a);
        fn_800C8040(w->fn_vslot33(4, 1))->fn_vslot30(buf);
    } else {
        w->fn_vslot8(0);
    }
}

void fn_8012031C(Unk80117D20_Scr* self)
{
    if (fn_800AEC80(fn_800AB5C8(lbl_80619D10))->mD8 == 0)
        fn_800C8040(fn_800C8044(self->fn_vslot32(lbl_805B97B4, 0))->fn_vslot33(4, 1))->fn_vslot29((const char*)0x1907);
    fn_8011C5E8(self);
}

void fn_801203D0()
{
    int v = fn_8011AA24(0)->m6F8->m10->m6C;
    fn_800B555C()->m570 = v;
}

void fn_80120410(Scr* self)
{
    fn_8011C6D0(self);
}

void fn_80120430(Scr* self)
{
    fn_8011FFB4(self);
}

void* fn_80120450(Unk80120450_Diff* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8064FE18);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    return self;
}

extern "C" void fn_801204A8(Unk80120450_Diff* self)
{
    fn_800ECF18(self);
    fn_802DC9C0();
    lbl_8061B8C0->m24 = 1;
    fn_802D7ADC();
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    Wid* w = fn_800B7A94(lbl_8061A32C, lbl_805BA6D0);
    fn_80124FA8(w, self);
    fn_801251CC(w, 0, 0x1A0A, 0);
    fn_800C80C0(w, fn_800B555C()->m570);
    fn_800C80C0(self, fn_800B555C()->m570);
    switch (lbl_806192E0->m4->m10->m74) {
    case 5:
        ((UnkSub*)((char*)fn_800C8058(self->fn_vslot32(lbl_805C0268, 1)) + 0xDC))->fn_vslot6(0);
        break;
    case 6:
        ((UnkSub*)((char*)fn_800C8058(self->fn_vslot32(lbl_805C0268, 1)) + 0xDC))->fn_vslot6(1);
        break;
    }
    int v = 0;
    switch (lbl_806192E0->m4->m10->m18) {
    case 0:
        break;
    case 1:
        v = 1;
        break;
    case 2:
        v = 2;
        break;
    case 3:
        v = 3;
        break;
    }
    self->m138->fn_vslot37(v);
    fn_8012075C(self);
}

}
