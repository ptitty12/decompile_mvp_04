/*
 * Game code, .text 0x800FD438-0x80101254 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


void fn_800FD4F8()
{
}

void fn_800FE23C(UiV_1C4i* self, int a)
{
    fn_800C8044(self->m1C4)->v8(a);
}

extern char lbl_805BEE18[];
int fn_800FE390(UiV_1DCi* self)
{
    int r = self->m1DC;
    if (r != 0) {
        r = fn_800ED2B0(r, lbl_805BEE18);
        if (r != 0)
            r = fn_800CFB38();
    }
    return r;
}

extern char lbl_80659A60[];
UiWRaw::UiWRaw()
{
    mC = lbl_80659A60;
    m0 = 0;
    m4 = 0;
    m8 = 0;
}

void fn_800FEC24(UiV_0i_4i* self, int a, int b)
{
    self->m0 = a;
    self->m4 = b;
}

void fn_800FEC30(UiV_8* self)
{
    if (self->m8 != 0)
        self->m8->v71();
}

void fn_800FEC70(UiV_8* self)
{
    if (self->m8 != 0)
        self->m8->v72();
}

void fn_800FECB0(UiV_0* self)
{
    UiObj* o = self->m0;
    o->v67(1, fn_80101254(o));
}

extern char lbl_806599F0[];
UiW2::UiW2()
{
    m30 = 0;
    mC = lbl_806599F0;
}

void fn_800FF20C(UiFlagOwner* self, UiFlagged* a)
{
    self->m8 = a;
    a->bit7 = self->m30;
}

void fn_800FF224(UiV_8_2Ci* self)
{
    self->m2C = 0;
    self->m8->v79(0, 0);
}

int fn_800FF590(UiPtr0* self)
{
    return self->m0->m2AC;
}

void fn_800FFE28(UiV_4b* self, int a)
{
    self->m4->v8();
    fn_801A39B8(fn_8011AA24(0), a);
}

void fn_80100020(UiV_4b* self, int a)
{
    self->m4->v8();
    fn_801A39B8(fn_8011AA24(0), a);
}

void fn_80100150(UiV_4b* self, int a)
{
    self->m4->v8();
    fn_801A3A54(fn_8011AA24(0), a);
}

void fn_801002F4(UiV_4b* self, int a)
{
    self->m4->v8();
    fn_801A3A54(fn_8011AA24(0), a);
}

void fn_80100644(UiV_28i* self, int a)
{
    self->m28 = a;
    fn_80100744(self);
}

void fn_80100668(UiV_2Ci* self, int a)
{
    self->m2C = a;
    fn_80100744(self);
}

void fn_8010068C(UiV_20i* self, int a)
{
    self->m20 = a;
    fn_80100744(self);
}

void fn_801006B0(UiV_24i* self, int a)
{
    self->m24 = a;
    fn_80100744(self);
}

void fn_80100A08(UiV_30b* self)
{
    self->m30->v8();
}
