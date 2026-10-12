/*
 * Front-end overlay code, .frontend_codeoverlay 0x804D3E00-0x804D6180 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804D08D0.h"

extern "C" {
FE_OVERLAY void fn_804D3E00(FeS804D3D74* x, FeW* w, int a)
{
    fn_800EC624__FP13Unk800EC624_Tiii(x, w, a);
    if (a != 0) {
        x->m154 = fn_800C8060(w->fn_vslot29(lbl_805F853C));
        x->m160 = fn_800C8054(w->fn_vslot29(lbl_805F8554));
    } else {
        x->m154 = fn_800C8060(w->fn_vslot29(lbl_805F8584));
        x->m160 = fn_800C8054(w->fn_vslot29(lbl_805F859C));
    }
    FeW* r = x->m154->fn_vslot28(lbl_805F85CC);
    if (r != 0) {
        r = fn_800C8054(x->m154->fn_vslot29(lbl_805F85CC));
    }
    x->m15C = r;
    if (((FeStateB*)fn_800B555C())->m0 == 0x43 || ((FeStateB*)fn_800B555C())->m0 == 0x44) {
        ((FeWX*)fn_800C8040(x->m154->fn_vslot29(lbl_805F85D8)))->s29(0x3CAF);
    } else {
        ((FeWX*)fn_800C8040(x->m154->fn_vslot29(lbl_805F85D8)))->s29(0x3CAB);
    }
    fn_800C8060(x->m154)->fn_vslot68(1);
    x->m154->fn_vslot8(0);
}

FE_OVERLAY void fn_804D4004(FeS804D3D74* x)
{
    x->m164 = 0;
    x->m154->fn_vslot8(0);
}

FE_OVERLAY void fn_804D4048(FeS804D3D74* x)
{
    x->m164 = 0;
    x->m154->fn_vslot8(0);
}

FE_OVERLAY void fn_804D408C(FeS804D3D74* x)
{
    x->m164 = 1;
    x->m154->fn_vslot8(1);
    if (x->m15C != 0) {
        ((FeSubX*)((char*)x->m15C + 0x98))->s20(((FeSubX*)((char*)x->m160 + 0x98))->s21(), 0);
    }
}

extern "C" FE_OVERLAY void fn_804D4134(void) {}

FE_OVERLAY void fn_804D4138(FeS804D3D74* x, int a)
{
    if (x->m154 != 0 && x->m164 != 0) {
        if (fn_800B5B04(fn_800B555C()) == 0) {
            if (x->m138 == -1) {
                x->m154->fn_vslot16(0);
                ((FeWY*)fn_800C8040(x->m154->fn_vslot29(lbl_805F85D8)))->s30((const char*)&lbl_805F36A0);
            } else {
                x->m154->fn_vslot16(1);
                fn_804D4430(x);
            }
        }
    }
    x->m138 = a;
}

FE_OVERLAY void fn_804D4230(FeS804D3D74* x)
{
    int v;
    switch (fn_800C8060(x->m154)->fn_vslot60()) {
    case 0:
        v = 0;
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
    default:
        v = 0;
        break;
    }
    FeG10* g = lbl_806192E0->m4->m10;
    if (x->m13C != 0) {
        g->m14 = v;
    } else {
        g->m18 = v;
    }
}

extern "C" FE_OVERLAY void fn_804D42E4(void) {}

FE_OVERLAY int fn_804D42E8(FeS804D3D74* x)
{
    x->m154->fn_vslot50();
    fn_804D4430(x);
    return 1;
}

FE_OVERLAY int fn_804D4338(FeS804D3D74* x)
{
    x->m154->fn_vslot51();
    fn_804D4430(x);
    return 1;
}

FE_OVERLAY int fn_804D4388(FeS804D3D74* x)
{
    x->m154->fn_vslot52();
    fn_804D4430(x);
    return 1;
}

FE_OVERLAY int fn_804D43D8(FeS804D3D74* x)
{
    x->m154->fn_vslot53();
    fn_804D4430(x);
    return 1;
}

extern "C" FE_OVERLAY void fn_804D4428(void) {}

extern "C" FE_OVERLAY void fn_804D442C(void) {}

FE_OVERLAY void fn_804D4430(FeS804D3D74* x)
{
    int v = 0;
    int k = x->m154->fn_vslot60();
    if (((FeStateB*)fn_800B555C())->m0 == 0x43 || ((FeStateB*)fn_800B555C())->m0 == 0x44) {
        switch (k) {
        case 0:
            v = 0x3CAE;
            break;
        case 1:
            v = 0x3CAF;
            break;
        case 2:
            v = 0x3CB1;
            break;
        case 3:
            v = 0x3CB0;
            break;
        }
    } else {
        switch (k) {
        case 0:
            v = 0x3CAA;
            break;
        case 1:
            v = 0x3CAB;
            break;
        case 2:
            v = 0x3CAD;
            break;
        case 3:
            v = 0x3CAC;
            break;
        }
    }
    if (v != 0) {
        ((FeWX*)fn_800C8040(x->m154->fn_vslot29(lbl_805F85D8)))->s29(v);
    }
}

FE_OVERLAY void fn_804D457C(FeS804D3D74* x)
{
    x->m148 = 1;
    x->m154->fn_vslot8(0);
}

FE_OVERLAY void fn_804D45C0(FeS804D3D74* x)
{
    x->m148 = 0;
    x->m154->fn_vslot8(1);
}

FE_OVERLAY int fn_804D4604(FeS804D3D74* x, int a)
{
    if (a == (int)x->m154) {
        fn_804D4430(x);
        fn_8001BC4C()->fn_8001BDAC(0x99);
    }
    return 1;
}

FE_OVERLAY void fn_804D4640(FeS804D3D74* x, int a)
{
    if (a == 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        x->m154->fn_vslot68(fn_804D46B8(x, 4));
        fn_804D4430(x);
    }
}

FE_OVERLAY int fn_804D46B8(FeS804D3D74* x, int n)
{
    int r = fn_8040ABA0() % 0xFFFF;
    return r & 3;
}

FE_OVERLAY FeS804D4704* fn_804D4704(FeS804D4704* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC594__FP8UiScrRawiiiiiiii(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806800B0);
    self->m15C = 1;
    self->m154 = 0;
    self->m158 = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m16C = 0;
    self->m170 = 0;
    self->m174 = 0;
    self->m178 = 0;
    self->m17C = 0;
    self->m180 = 0;
    self->m184 = 0;
    self->m188 = 0;
    self->m18C = 0;
    self->m190 = 0;
    return self;
}

FE_OVERLAY void fn_804D4E0C(FeS804D4704* x)
{
    x->m168->fn_vslot8(0);
    x->m16C->fn_vslot8(0);
}

FE_OVERLAY void fn_804D4E74(FeS804D4704* x)
{
    int v = ((FeSubX*)((char*)x->m194 + 0x98))->s21();
    if (x->m158 == 1) {
        x->m144 = v;
    }
    x->m168->fn_vslot8(0);
    x->m16C->fn_vslot8(0);
    x->m188->fn_vslot16(0);
    ((FeWX*)x->m188)->s44(0);
}

FE_OVERLAY void fn_804D4F4C(FeS804D4704* x)
{
    fn_804D53B8(x, x->m144);
    x->m198->fn_vslot8(0);
    x->m1A8->fn_vslot8(0);
    fn_804D512C(x);
    x->m168->fn_vslot8(1);
    x->m16C->fn_vslot8(1);
    if (x->m158 == 0) {
        ((FeWX*)x->m18C)->s44(0);
        x->m18C->fn_vslot29(lbl_805F8798)->fn_vslot8(0);
    }
    fn_800B555C();
    if (fn_800B57EC() != 0) {
        ((FeWX*)x->m18C)->s44(0);
    }
    if (x->m158 != 0) {
        FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
        fn_800B555C();
        if (fn_800B57EC() == 0) {
            fn_801251CC(p, 2, 0x3CA5, 0);
        }
        fn_801251CC(p, 3, 0x3BEE, -4);
    }
    fn_804D54DC(x);
    fn_804D563C(x);
}

FE_OVERLAY void fn_804D512C(FeS804D4704* x)
{
    FeBuf464 buf;
    int v = ((FeSubX*)((char*)x->m194 + 0x98))->s21();
    fn_8055AC44(&buf, fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, v));
    fn_800DD800(x->m174, &buf, v, 1);
}

FE_OVERLAY void fn_804D51A8(FeS804D4704* x, FeW* w, int a)
{
    if (w == x->m18C) {
        fn_804D53B8(x, ((FeSubX*)((char*)x->m194 + 0x98))->s21());
        if (*fn_800ED2B0(x->m140, lbl_805F5A48) == 0) {
            ((FeSubX*)((char*)x->m198 + 0x98))->s20(x->m160, 0);
            x->m198->fn_vslot8(1);
            ((FeSubX*)((char*)x->m1A8 + 0x98))->s20(x->m160, 0);
            x->m1A8->fn_vslot8(1);
            if (a == 0) {
                fn_800CFB38(x->m178);
            } else {
                fn_800CFB38(x->m17C);
            }
            x->m140->fn_vslot4();
        }
    } else if (w == x->m188) {
        fn_804D60AC(x, ((FeSubX*)((char*)fn_800C8058(w->fn_vslot32(lbl_805F5080, 1)) + 0xDC))->s5());
    }
    fn_804D512C(x);
}

FE_OVERLAY void fn_804D535C(FeS804D4704* x)
{
    x->m160 = ((FeSubX*)((char*)x->m194 + 0x98))->s21();
    fn_804D54DC(x);
    fn_804D563C(x);
}

FE_OVERLAY void fn_804D53B8(FeS804D4704* x, int a)
{
    ((FeSubX*)((char*)x->m194 + 0x98))->s20(a, 0);
    ((FeSubX*)((char*)x->m19C + 0x98))->s20(a, 0);
    ((FeSubX*)((char*)x->m1A0 + 0xDC))->s20(a, 0);
    ((FeSubX*)((char*)x->m1A4 + 0x98))->s20(a, 0);
    ((FeSubX*)((char*)x->m1AC + 0x98))->s20(a, 0);
    x->m188->fn_vslot37(*(int*)((char*)x->m194 + 0xA4));
    fn_804D54DC(x);
    fn_804D563C(x);
}

/* near-miss: 1 slot; retail re-reads lbl_8061930C via a callee-saved lis register, we cache the value (tried g = &lbl, if/else shapes) */
FE_OVERLAY void fn_804D54DC(FeS804D4704* x)
{
    if (x->m154 != 0) {
        int r;
        int t;
        if (FeW24(x->m168) >= 0 || (r = fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, ((FeSubX*)((char*)x->m194 + 0x98))->s21()), t = x->m138, t == 5) || t == -1) {
            x->m188->fn_vslot16(0);
            return;
        }
        if (x->m15C == 0 || x->m158 == 0 || fn_8007B3E0__18Unk8007B2B0_Screenii(lbl_8061930C, 0xE, r) == 0) {
            x->m188->fn_vslot16(0);
            ((FeWX*)x->m188)->s44(0);
            return;
        }
        x->m188->fn_vslot16(1);
        ((FeWX*)x->m188)->s44(1);
    }
}

FE_OVERLAY void fn_804D563C(FeS804D4704* x)
{
    if (x->m154 != 0 && x->m184 != 0) {
        int t = x->m138;
        if (t == 5 || t == -1 || (x->m180 != 0 && *x->m180 != 0)) {
            x->m184->fn_vslot8(0);
            return;
        }
        x->m184->fn_vslot8(1);
    }
}

FE_OVERLAY void fn_804D56D8(FeS804D4704* x, int a)
{
    fn_800ED310(x, a);
    x->m188->fn_vslot16(a);
}

FE_OVERLAY void fn_804D5728(FeS804D4704* x, int a)
{
    int v = 0;
    if (a == 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        switch (((FeSubX*)((char*)fn_800C8058(x->m188->fn_vslot32(lbl_805F5080, 1)) + 0xDC))->s5()) {
        case 0:
            v = fn_800ED4F0(x, 0x1E);
            break;
        case 1:
            v = fn_800ED4F0(x, 0x1E) + 0x20;
            break;
        case 2:
            v = fn_800ED4F0(x, 0x1E) + 0x3E;
            break;
        case 3:
            v = fn_800ED4F0(x, 0x1E) + 0x5C;
            break;
        }
        fn_804D53B8(x, fn_800B548C(v));
        fn_804D512C(x);
    }
}

FE_OVERLAY int fn_804D5844(FeS804D4704* x)
{
    fn_800B555C();
    if (fn_800B57EC() == 0 && x->m158 != 0) {
        x->m18C->fn_vslot40(1);
    }
    return 1;
}

FE_OVERLAY int fn_804D58AC(FeS804D4704* x)
{
    fn_800B555C();
    if (fn_800B57EC() == 0 && x->m158 != 0) {
        ((FeWX*)x->m18C)->s41();
    }
    return 1;
}

FE_OVERLAY int fn_804D5910(FeS804D4704* x)
{
    fn_800B555C();
    if (fn_800B57EC() == 0 && x->m158 != 0) {
        x->m18C->fn_vslot38(1);
    }
    return 1;
}

FE_OVERLAY int fn_804D5978(FeS804D4704* x)
{
    fn_800B555C();
    if (fn_800B57EC() == 0 && x->m158 != 0) {
        ((FeWX*)x->m18C)->s39();
    }
    return 1;
}

FE_OVERLAY int fn_804D59DC(FeS804D4704* x)
{
    ((FeWX*)x->m18C)->s39();
    ((FeWX*)x->m18C)->s41();
    return 0;
}

FE_OVERLAY int fn_804D5A40(FeS804D4704* x)
{
    ((FeWX*)x->m18C)->s39();
    ((FeWX*)x->m18C)->s41();
    return 0;
}

FE_OVERLAY int fn_804D5AA4(FeS804D4704* x)
{
    fn_800B555C();
    if ((fn_800B57EC() == 0 || fn_800B5B04(fn_800B555C()) != 0) && x->m158 != 0 && x->m15C != 0) {
        void* g = lbl_8061930C;
        int r = fn_80075948__18Unk8007B2B0_Screeni(g, ((FeSubX*)((char*)x->m194 + 0x98))->s21());
        if (fn_8007B3E0__18Unk8007B2B0_Screenii(g, 0xE, r) != 0) {
            x->m188->fn_vslot40(1);
            fn_804D60AC(x, ((FeSubX*)((char*)fn_800C8058(x->m188->fn_vslot32(lbl_805F5080, 1)) + 0xDC))->s5());
            fn_804D53B8(x, fn_8057CF60(r, ((FeSubX*)((char*)fn_800C8058(x->m188->fn_vslot32(lbl_805F5080, 1)) + 0xDC))->s5()));
        }
    }
    return 1;
}

FE_OVERLAY int fn_804D5C28(FeS804D4704* x)
{
    fn_800B555C();
    if ((fn_800B57EC() == 0 || fn_800B5B04(fn_800B555C()) != 0) && x->m158 != 0 && x->m15C != 0) {
        void* g = lbl_8061930C;
        int r = fn_80075948__18Unk8007B2B0_Screeni(g, ((FeSubX*)((char*)x->m194 + 0x98))->s21());
        if (fn_8007B3E0__18Unk8007B2B0_Screenii(g, 0xE, r) != 0) {
            ((FeWX*)x->m188)->s41();
            fn_804D60AC(x, ((FeSubX*)((char*)fn_800C8058(x->m188->fn_vslot32(lbl_805F5080, 1)) + 0xDC))->s5());
            fn_804D53B8(x, fn_8057CF60(r, ((FeSubX*)((char*)fn_800C8058(x->m188->fn_vslot32(lbl_805F5080, 1)) + 0xDC))->s5()));
        }
    }
    return 1;
}

FE_OVERLAY int fn_804D5DA8(FeS804D4704* x)
{
    fn_800B555C();
    if ((fn_800B57EC() == 0 || fn_800B5B04(fn_800B555C()) != 0) && x->m158 != 0 && x->m15C != 0) {
        void* g = lbl_8061930C;
        int r = fn_80075948__18Unk8007B2B0_Screeni(g, ((FeSubX*)((char*)x->m194 + 0x98))->s21());
        if (fn_8007B3E0__18Unk8007B2B0_Screenii(g, 0xE, r) != 0) {
            x->m188->fn_vslot38(1);
            fn_804D60AC(x, ((FeSubX*)((char*)fn_800C8058(x->m188->fn_vslot32(lbl_805F5080, 1)) + 0xDC))->s5());
            fn_804D53B8(x, fn_8057CF60(r, ((FeSubX*)((char*)fn_800C8058(x->m188->fn_vslot32(lbl_805F5080, 1)) + 0xDC))->s5()));
        }
    }
    return 1;
}

FE_OVERLAY int fn_804D5F2C(FeS804D4704* x)
{
    fn_800B555C();
    if ((fn_800B57EC() == 0 || fn_800B5B04(fn_800B555C()) != 0) && x->m158 != 0 && x->m15C != 0) {
        void* g = lbl_8061930C;
        int r = fn_80075948__18Unk8007B2B0_Screeni(g, ((FeSubX*)((char*)x->m194 + 0x98))->s21());
        if (fn_8007B3E0__18Unk8007B2B0_Screenii(g, 0xE, r) != 0) {
            ((FeWX*)x->m188)->s39();
            fn_804D60AC(x, ((FeSubX*)((char*)fn_800C8058(x->m188->fn_vslot32(lbl_805F5080, 1)) + 0xDC))->s5());
            fn_804D53B8(x, fn_8057CF60(r, ((FeSubX*)((char*)fn_800C8058(x->m188->fn_vslot32(lbl_805F5080, 1)) + 0xDC))->s5()));
        }
    }
    return 1;
}

FE_OVERLAY void fn_804D60AC(FeS804D4704* x, int a)
{
    ((FeWX*)x->m188)->s37();
    fn_800D0074((char*)x->m194 + 0x98, a, 0);
    fn_800D0074((char*)x->m198 + 0x98, a, 0);
    fn_800D0074((char*)x->m19C + 0x98, a, 0);
    fn_800D0074((char*)x->m1A0 + 0xDC, a, 0);
    fn_800D0074((char*)x->m1A4 + 0x98, a, 0);
    fn_800D0074((char*)x->m1A8 + 0x98, a, 0);
    fn_800D0074((char*)x->m1AC + 0x98, a, 0);
}

}
