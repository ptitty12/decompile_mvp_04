/*
 * Front-end overlay code, .frontend_codeoverlay 0x804D6180-0x804DA10C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804D08D0.h"

extern "C" {

FE_OVERLAY void fn_804D6180(void) {}

FE_OVERLAY FeS804D6184* fn_804D6184(FeS804D6184* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC594__FP8UiScrRawiiiiiiii(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067FD70);
    self->m154 = 0;
    self->m158 = 0;
    self->m160 = 0;
    self->m174 = 0;
    self->m178 = 0;
    self->m17C = 0;
    self->m180 = 0;
    self->m170 = -1;
    self->m184 = 0;
    return self;
}

FE_OVERLAY void fn_804D61F4(FeS804D6184* x)
{
    x->SetVptr(lbl_8067FD70);
    fn_800EC5F4__FP8UiScrRaw(x);
}

FE_OVERLAY void fn_804D67A8(FeS804D6184* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    if (x->m17C != 0) {
        x->m17C = 0;
        if (--lbl_80621AF4 == 0) {
            fn_80125128(p, -1);
        }
    }
    x->m15C->fn_vslot37(0);
    x->m15C->fn_vslot8(0);
    x->m164->fn_vslot8(0);
    x->m154->fn_vslot32(lbl_805F95D4, 1)->fn_vslot8(0);
    x->m154->fn_vslot32(lbl_805F95DC, 1)->fn_vslot8(0);
    x->m154->fn_vslot32(lbl_805F95E8, 1)->fn_vslot8(0);
    x->m154->fn_vslot8(0);
    fn_800C4720(fn_800C33D0(), x->m160);
}

FE_OVERLAY void fn_804D6E00(void) {}

FE_OVERLAY void fn_804D6E04(FeS804D6184* x)
{
    fn_800ECAA4(x);
    FeRec3* r = FeCurRec(x);
    int t = fn_8007DA28__18Unk8007B2B0_Screen(lbl_8061930C);
    if (r->m3 == 0x70 && fn_800E62C4__Fii(t, x->m174) == 0) {
        x->m15C->fn_vslot35();
    }
    fn_804D6EC0(x);
}

FE_OVERLAY void fn_804D772C(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY int fn_804D774C(FeS804D6184* x)
{
    if (x->m148 == 0) {
        x->m15C->fn_vslot40(1);
        if (FeCurRec(x)->m3 == 0x70) {
            if (fn_800E62C4__Fii(fn_8007DA34__18Unk8007B2B0_Screeni(lbl_8061930C, x->m138), x->m174) == 0) {
                ((FeWX*)x->m15C)->s36();
            }
        }
        fn_804D7C78(x);
    }
    return 1;
}

FE_OVERLAY int fn_804D7834(FeS804D6184* x)
{
    if (x->m148 == 0) {
        ((FeWX*)x->m15C)->s41();
        fn_804D7C78(x);
    }
    return 1;
}

FE_OVERLAY int fn_804D7890(FeS804D6184* x)
{
    if (x->m148 == 0) {
        x->m15C->fn_vslot38(1);
        if (FeCurRec(x)->m3 == 0x70) {
            if (fn_800E62C4__Fii(fn_8007DA34__18Unk8007B2B0_Screeni(lbl_8061930C, x->m138), x->m174) == 0) {
                ((FeWX*)x->m15C)->s35();
            }
        }
        fn_804D7C78(x);
    }
    return 1;
}

FE_OVERLAY int fn_804D7978(FeS804D6184* x)
{
    if (x->m148 == 0) {
        ((FeWX*)x->m15C)->s39();
        fn_804D7C78(x);
    }
    return 1;
}

FE_OVERLAY int fn_804D79D4(FeS804D6184* x)
{
    ((FeWX*)x->m15C)->s39();
    ((FeWX*)x->m15C)->s41();
    fn_804D7C78(x);
    return 0;
}

FE_OVERLAY int fn_804D7A40(FeS804D6184* x)
{
    ((FeWX*)x->m15C)->s39();
    ((FeWX*)x->m15C)->s41();
    fn_804D7C78(x);
    return 0;
}

FE_OVERLAY void fn_804D7AAC(void) {}

FE_OVERLAY void fn_804D7AB0(FeS804D6184* x, FeW* w, int a)
{
    if (w == x->m15C && *fn_800ED2B0(x->m140, lbl_805F5A48) == 0) {
        if (FeCurRec(x)->m3 == 0x70) {
            if (fn_800E62C4__Fii(fn_8007DA34__18Unk8007B2B0_Screeni(lbl_8061930C, x->m138), x->m174) == 0) {
                if (a == 0) {
                    ((FeWX*)x->m15C)->s36();
                } else {
                    ((FeWX*)x->m15C)->s35();
                }
            }
        }
        if (fn_804D6EC0(x) == 0) {
            fn_800CFB38((void*)x->m16C);
        }
        x->m140->fn_vslot4();
    }
    fn_804D7C78(x);
}

FE_OVERLAY void fn_804D7BF0(FeS804D6184* x)
{
    x->m148 = 1;
    x->m154->fn_vslot8(0);
}

FE_OVERLAY void fn_804D7C34(FeS804D6184* x)
{
    x->m148 = 0;
    x->m154->fn_vslot8(1);
}

FE_OVERLAY void fn_804D7C78(FeS804D6184* x)
{
    int i = 0;
    int found = -1;
    FeRec3* r = FeCurRec(x);
    for (; i <= 0x1B0; i++) {
        if (fn_8040B574((const char*)r, lbl_80621AF8[i]) == 0) {
            found = i;
            break;
        }
    }
    ((FeWX*)x->m184)->s29(lbl_805FCADC[found]);
}

FE_OVERLAY void fn_804D7F0C(FeS804D6184* x, int a)
{
    int found = -1;
    for (int i = 0; i < ((FeSubX*)((char*)x->m160 + 0x98))->s13(); i++) {
        int c = ((FeWX*)x->m160)->s33(i)->m3;
        if (lbl_806221BC[a] == c) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        found = 0;
    }
    ((FeSubX*)((char*)x->m160 + 0x98))->s6(found);
}

FE_OVERLAY FeS804D7FE0* fn_804D7FE0(FeS804D7FE0* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC594__FP8UiScrRawiiiiiiii(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066E840);
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 1;
    self->m16C = 1;
    self->m170 = 0;
    return self;
}

FE_OVERLAY void fn_804D8048(FeS804D7FE0* x, FeW* w, int a)
{
    fn_800EC624__FP13Unk800EC624_Tiii(x, w, a);
    if (a != 0) {
        x->m154 = fn_800C8060(w->fn_vslot29(lbl_805F9614));
        x->m158 = fn_800C8054(w->fn_vslot29(lbl_805F8554));
        x->m170 = fn_800C8044(w->fn_vslot29(lbl_805F962C));
        x->m15C = fn_800C8058(w->fn_vslot29(lbl_805F9644));
        x->m168 = 1;
    } else {
        x->m154 = fn_800C8060(w->fn_vslot29(lbl_805F9660));
        x->m158 = fn_800C8054(w->fn_vslot29(lbl_805F859C));
        x->m170 = fn_800C8044(w->fn_vslot29(lbl_805F9678));
        x->m15C = fn_800C8058(w->fn_vslot29(lbl_805F9690));
        x->m168 = a;
    }
    x->m164 = 1;
}

FE_OVERLAY void fn_804D91F8(FeS804D7FE0* x)
{
    x->m154->fn_vslot8(0);
    x->m170->fn_vslot8(0);
    x->m164 = 1;
}

FE_OVERLAY void fn_804D9268(FeS804D7FE0* x)
{
    int v = 1;
    x->m164 = x->m154->fn_vslot60();
    x->m154->fn_vslot8(0);
    x->m170->fn_vslot8(0);
    if (((FeWY*)fn_800C8040(fn_800C8044(x->m154->fn_vslot32(lbl_805F4EE0, 1))->fn_vslot32(lbl_805F565C, 1)))->s32() == 0x199A) {
        v = 0;
    }
    ((FeStateC*)fn_800B555C())->m664 = v;
}

FE_OVERLAY void fn_804D9374(FeS804D7FE0* x)
{
    x->m154->fn_vslot8(1);
    fn_804D87CC(x);
    x->m154->fn_vslot68(x->m164);
    fn_804D81DC(x);
    if (fn_800B5B04(fn_800B555C()) == 0) {
        x->m170->fn_vslot8(1);
    }
    x->fn_vslot4();
}

FE_OVERLAY int fn_804D9434(FeS804D7FE0* x)
{
    x->m154->fn_vslot50();
    fn_804D81DC(x);
    return 1;
}

FE_OVERLAY int fn_804D9484(FeS804D7FE0* x)
{
    x->m154->fn_vslot51();
    fn_804D81DC(x);
    return 1;
}

FE_OVERLAY int fn_804D94D4(FeS804D7FE0* x)
{
    x->m154->fn_vslot52();
    fn_804D81DC(x);
    return 1;
}

FE_OVERLAY int fn_804D9524(FeS804D7FE0* x)
{
    x->m154->fn_vslot53();
    fn_804D81DC(x);
    return 1;
}

FE_OVERLAY int fn_804D9574(FeS804D7FE0* x, int a)
{
    if (a == (int)x->m154) {
        fn_804D81DC(x);
    }
    return 1;
}

FE_OVERLAY void fn_804D95A4(FeS804D7FE0* x, int a)
{
    int v = x->m154->fn_vslot59();
    if (a == 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        int idx = fn_800ED4F0(x, v - 1) + 1;
        x->m154->fn_vslot68(idx);
        fn_804D81DC(x);
    }
}

FE_OVERLAY int fn_804D9D64(FeS804D7FE0* x)
{
    if (((FeStateB*)fn_800B555C())->m0 == 0x42) {
        ((FeWX*)fn_800C805C(x->m154->fn_vslot29(lbl_805F96D8)))->s41();
    }
    return 1;
}

FE_OVERLAY int fn_804D9EF4(FeS804D7FE0* x)
{
    if (((FeStateB*)fn_800B555C())->m0 == 0x42) {
        ((FeWX*)fn_800C805C(x->m154->fn_vslot29(lbl_805F96D8)))->s39();
    }
    return 1;
}

FE_OVERLAY void fn_804D9F70(FeS804D7FE0* x)
{
    fn_800ECAA4(x);
    if (fn_800B5B04(fn_800B555C()) != 0) {
        fn_800C8040(x->m154->fn_vslot29(lbl_805F96B8))->fn_vslot8(FeFlag());
        fn_800C8040(x->m154->fn_vslot29(lbl_805F96C4))->fn_vslot8(0);
        if (((FeStateB*)fn_800B555C())->m0 == 0x42 && x->m138 != -1 && x->m138 != 5) {
            fn_800C805C(x->m154->fn_vslot29(lbl_805F96D8))->fn_vslot8(FeFlag());
        } else {
            fn_800C805C(x->m154->fn_vslot29(lbl_805F96D8))->fn_vslot8(0);
        }
    }
}

}
