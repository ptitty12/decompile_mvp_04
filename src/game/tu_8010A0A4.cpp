/*
 * Game code, .text 0x8010A0A4-0x8010E0F4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


int fn_8010A6C0()
{
    Ui700* o = fn_8011AA24(0)->m700;
    return fn_8017E030(o, fn_801059E4(), 0) == 0;
}

extern char lbl_8064F378[];
UiScrA70C* fn_8010A70C(UiScrA70C* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064F378;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 1;
    self->m154 = 1;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m234 = 1;
    fn_803FFC58(self->m238, 0, 12);
    return self;
}

int fn_8010A7A0(int a)
{
    switch (a) {
    case 0:
        return fn_80090880(lbl_8061977C, 0x2B34);
    case 2:
        return fn_80090880(lbl_8061977C, 0x2B35);
    case 1:
    default:
        return fn_80090880(lbl_8061977C, 0x2B33);
    }
}

/* near-miss: sth/li/addi order of the buffer setup differs from retail (addi r3 comes last there) */
void fn_8010AE78(int unused, UiObj* list, int a, int b)
{
    short buf[100];
    buf[0] = 0;
    fn_800DE274(buf, b, 1);
    list->v43(a, 1, (int)buf, 5);
}

extern char lbl_805BC1A8[];
void fn_8010AEE4(int unused, UiObj* list, int a, int b)
{
    char buf[100] = "";
    fn_804089B4(buf, lbl_805BC1A8, fn_8011B6F8(1, b));
    list->v44(a, 2, (int)buf, 5);
}

void fn_8010B060(int unused, UiObj* list, int a, char* ctx)
{
    fn_8025416C(ctx + 0x588, 5);
    list->v44(a, 0, fn_800E5F38(), 5);
}

void fn_8010B1E0(int unused, UiObj* list, int a, Ui8010B1E0* ctx, int b)
{
    fn_80097288(b, ctx->m704);
    list->v44(a, 0, fn_800E5E4C(), 5);
}

void fn_8010B24C(int unused, UiObj* list, int a, char* ctx)
{
    int t = fn_8025416C(ctx + 0x588, 9);
    list->v43(a, 2, fn_8010A7A0(t), 5);
}

void fn_8010B2B8(int unused, UiObj* list, int a, char* ctx)
{
    int t = fn_8025416C(ctx + 0x588, 8);
    list->v43(a, 2, fn_8010A7A0(t), 5);
}

void fn_8010B324(int unused, UiObj* list, int a, int b)
{
    char buf[100] = "";
    float f = fn_8011B81C(2, b, 2);
    fn_80119F48(buf, f);
    list->v44(a, 3, (int)buf, 5);
}

void fn_8010B3BC(int unused, UiObj* list, int a, int b)
{
    char buf[100] = "";
    float f = fn_8011B954(1, b);
    fn_80119FF0(buf, f);
    list->v44(a, 3, (int)buf, 5);
}

extern char lbl_805B6F58[];
void fn_8010B450(int unused, UiObj* list, int a, int b)
{
    list->v44(a, 0, (int)lbl_805B6F58, 5);
    list->v43(a, 1, fn_80090880(lbl_8061977C, b), 5);
    list->v44(a, 2, (int)lbl_805B6F58, 5);
    list->v44(a, 3, (int)lbl_805B6F58, 5);
}

extern char lbl_805B6F58[];
void fn_8010B53C(int unused, UiObj* list, int a, int b, int n)
{
    for (int j = 0; j < n; j++) {
        for (int i = a; i < b; i++)
            list->v44(i, j, (int)lbl_805B6F58, 5);
    }
    for (int i = a; i < b; i++)
        fn_8010B658(unused, list, i);
}

void fn_8010B5F8(int unused, UiObj* list, int a)
{
    for (int i = 0; i <= 4; i++)
        list->v91(a, i, 1);
}

void fn_8010B658(int unused, UiObj* list, int a)
{
    for (int i = 0; i <= 4; i++)
        list->v91(a, i, 0);
}

int fn_8010D1C8()
{
    return 0;
}

void fn_8010D1D0()
{
}

void fn_8010D8B4(void* self, char* out)
{
    *out = 0;
}

void fn_8010DC14(UiV_148i_14Ci_158i_15Ci_160i_164i* self)
{
    self->m148 = 0;
    self->m14C = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    fn_800ED254(self);
    fn_800C33D0();
    fn_800C3BE0();
}

void fn_8010DC5C(UiV_140i_148_14C* self, int a)
{
    fn_800ED310(self, a);
    if (a != 0) {
        switch (self->m140) {
        case 0:
        case 2:
            self->m148->v14(1);
            break;
        case 1:
            self->m14C->v14(1);
            break;
        }
    } else {
        self->m148->v14(0);
        self->m14C->v14(0);
    }
}
