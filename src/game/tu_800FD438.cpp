/*
 * Game code, .text 0x800FD438-0x80101254 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


void fn_800FD4F8()
{
}

void fn_800FFE28(UiV_4* self, int a)
{
    self->m4->v8();
    fn_801A39B8(fn_8011AA24(0), a);
}

void fn_80100020(UiV_4* self, int a)
{
    self->m4->v8();
    fn_801A39B8(fn_8011AA24(0), a);
}

void fn_80100150(UiV_4* self, int a)
{
    self->m4->v8();
    fn_801A3A54(fn_8011AA24(0), a);
}

void fn_801002F4(UiV_4* self, int a)
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

void fn_80100A08(UiV_30* self)
{
    self->m30->v8();
}
