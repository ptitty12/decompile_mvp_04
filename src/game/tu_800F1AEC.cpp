/*
 * Game code, .text 0x800F1AEC-0x800F56B4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


extern char lbl_8061B340[];
extern char lbl_8064BA88[];
UiScrRaw* fn_800F1B38(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 16, lbl_8061B340);
    self->m3C = lbl_8064BA88;
    self->m174 = 0;
    self->m178 = 0;
    return self;
}

extern char lbl_806549D8[];
UiScrRaw* fn_800F3220(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_806549D8;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern char lbl_806549D8[];
void fn_800F3274(UiScrRaw* self)
{
    self->m3C = lbl_806549D8;
    fn_8035686C(self);
}

int fn_800F362C(UiV_134* self)
{
    self->m134->v50();
    return 1;
}

int fn_800F3668(UiV_134* self)
{
    self->m134->v51();
    return 1;
}

int fn_800F36A4(UiV_134* self)
{
    self->m134->v52();
    return 1;
}

int fn_800F36E0(UiV_134* self)
{
    self->m134->v53();
    return 1;
}

void fn_800F388C(UiV_134* self, char* out)
{
    UiObj* o = self->m134->v70();
    fn_8040B830(out, o->v33(5, 1)->name, 16);
}

extern char lbl_80654730[];
UiScrRaw* fn_800F3900(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80654730;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    return self;
}

extern char lbl_80654730[];
void fn_800F3958(UiScrRaw* self)
{
    self->m3C = lbl_80654730;
    fn_8035686C(self);
}

void fn_800F49FC(UiObj* self)
{
    fn_800EBEA8(self);
    fn_800F4A30(self);
}

void fn_800F4FD0(UiObj* self)
{
    fn_800EB7D4(self);
    fn_800C33D0();
    fn_800C3BE0();
}

extern char lbl_8061B380[];
extern char lbl_80653B90[];
UiScrRaw* fn_800F50EC(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 7, lbl_8061B380);
    self->m3C = lbl_80653B90;
    return self;
}

void fn_800F5224()
{
    fn_8006C698(lbl_806192E0->m4);
}

void fn_800F5344(UiObj* self)
{
    fn_800ECAA4(self);
    self->v87();
}

extern char lbl_8061B39C[];
extern char lbl_806538C0[];
UiScrRaw* fn_800F5388(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 7, lbl_8061B39C);
    self->m3C = lbl_806538C0;
    return self;
}

void fn_800F5454()
{
    fn_8006C698(lbl_806192E0->m4);
}

void fn_800F5574(UiObj* self)
{
    fn_800ECAA4(self);
    self->v87();
}

extern char lbl_80651B88[];
UiScrRaw* fn_800F55B8(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80651B88;
    self->m130 = 0;
    return self;
}
