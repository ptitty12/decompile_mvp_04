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
    char pad15C[0x4];
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

extern const char lbl_80658730[];
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

// PROTOS-BEGIN
extern "C" {
void fn_8011D0D0(Scr* self);
void fn_8011D614(Scr* self, int a);
void fn_8011D67C(Scr* self, int unused, int a);
void fn_8011DBCC(Scr* self);
void fn_8011DC70(Scr* self, int a);
void fn_8011E220(Scr* self, int a);
void fn_8011E26C(Scr* self);
void fn_8011E2E8(Scr* self, int a);
void fn_8011E3B4();
void fn_8011E3F4(Scr* self);
void fn_8011E414(Scr* self);
void fn_8011E434(Scr* self, int a);
void fn_8011F0C0(Scr* self);
void fn_8011F410(Scr* self);
Wid* fn_8011F4B8(Scr* self, int i);
Wid* fn_8011F548(Scr* self, int i);
Wid* fn_8011F5D8(Scr* self, int i);
void fn_801203D0();
void fn_80120410(Scr* self);
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
int* fn_800ED2B0(Wid* container, const char* name);
void fn_800CFB38(int* p);
void fn_800CFE84(int* p);
void* fn_8004072C();
int fn_800412AC(void* o, int a, int b, int c, int d, int e);
void fn_8011DBCC(Scr* self);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
}

extern "C" {

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

void fn_8011F0C0(Scr* self)
{
    fn_8011C15C(self);
    fn_8011F0F4(self);
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

void fn_801203D0()
{
    int v = fn_8011AA24(0)->m6F8->m10->m6C;
    fn_800B555C()->m570 = v;
}

void fn_80120410(Scr* self)
{
    fn_8011C6D0(self);
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

}
