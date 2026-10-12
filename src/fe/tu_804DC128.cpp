/*
 * Front-end overlay code, .frontend_codeoverlay 0x804DC128-0x804DDAB4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804D08D0.h"
class FeSub24 {
public:
    char pad0[0x24];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20(int a, int b);
};
extern "C" void fn_804CF304(FeS804DC128* x);
extern "C" void fn_804D28B4(FeNav* n);
extern "C" void fn_804CF6A4(FeS804DC128* x);
extern "C" void fn_80125084(void* w, int a);

extern "C" unsigned fn_8007DBB0__FP13Unk8007DB74_A(void* g);
extern "C" void fn_8007CF44__18Unk8007B2B0_ScreenUiii(void* g, unsigned i, char* out, int a);

extern "C" FeW* fn_800C8048(FeW* w);

extern "C" {

FE_OVERLAY FeS804DC128* fn_804DC128(FeS804DC128* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC594__FP8UiScrRawiiiiiiii(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80668EA0);
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 1;
    return self;
}

FE_OVERLAY void fn_804DC184(FeS804DC128* x)
{
    fn_800ECE34(x);
    if (x->m13C != 0) {
        x->m154 = fn_800C8044(x->m140->fn_vslot32(lbl_805F85E0, 1));
    } else {
        x->m154 = fn_800C8044(x->m140->fn_vslot32(lbl_805F8698, 1));
    }
    x->m158 = fn_800C8060(x->m154->fn_vslot32(lbl_805F4EF4, 1));
    x->m15C = fn_800C8040(x->m154->fn_vslot32(lbl_805F977C, 1));
    x->m154->fn_vslot8(0);
    ((FeWX*)x->m158)->s104(0);
    x->m150 = 0;
}

FE_OVERLAY void fn_804DC2A4(FeS804DC128* x)
{
    fn_804DC4A4(x);
    fn_804DC764(x);
    x->m154->fn_vslot8(1);
    x->m154->fn_vslot32(lbl_805F9788, 1)->fn_vslot8(x->m160);
    x->m150 = 0;
}

FE_OVERLAY void fn_804DC344(FeS804DC128* x)
{
    x->m154->fn_vslot8(0);
}

FE_OVERLAY void fn_804DC380(FeS804DC128* x)
{
    fn_804DC344(x);
}

FE_OVERLAY int fn_804DC3A0(FeS804DC128* x)
{
    return x->m154->b0 == 0;
}

FE_OVERLAY int fn_804DC3B4(FeS804DC128* x)
{
    x->m158->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804DC3F0(FeS804DC128* x)
{
    x->m158->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804DC42C(FeS804DC128* x)
{
    x->m158->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804DC468(FeS804DC128* x)
{
    x->m158->fn_vslot53();
    return 1;
}

FE_OVERLAY void fn_804DC4A4(FeS804DC128* x)
{
    char buf[0x18];
    void* s = lbl_8061930C;
    unsigned i = 0;
    unsigned n = fn_8007DBB0__FP13Unk8007DB74_A(s);
    x->m158->fn_vslot79(n + 1, 0);
    x->m158->fn_vslot3();
    x->m158->fn_vslot43(0, 0, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3FB5), 5);
    int sel = fn_8007DA34__18Unk8007B2B0_Screeni(s, x->m138);
    for (; i < n; i++) {
        fn_8007CF44__18Unk8007B2B0_ScreenUiii(s, i, buf, 9);
        x->m158->fn_vslot43(i + 1, 0, buf, 5);
    }
    fn_804DC64C(x);
    if (sel == -1)
        x->m158->fn_vslot67(0, 0);
    else
        x->m158->fn_vslot67(sel + 1, 0);
    x->m158->fn_vslot14(1);
}

FE_OVERLAY void fn_804DC64C(FeS804DC128* x)
{
    if (x->m138 != -1) {
        int i = 1;
        void* g = lbl_8061930C;
        for (; i < x->m158->fn_vslot59(); i++) {
            ((FeWZ*)x->m158)->s91(i, 0, 1);
        }
        for (int j = 0; j <= 3; j++) {
            if (j != x->m138) {
                int r = fn_8007DA34__18Unk8007B2B0_Screeni(g, j);
                if (r != -1) {
                    ((FeWZ*)x->m158)->s91(r + 1, 0, 0);
                }
            }
        }
    }
}

FE_OVERLAY void fn_804DC73C(FeS804DC128* x)
{
    fn_804DC64C(x);
}

FE_OVERLAY int fn_804DC75C(void) { return 0; }

FE_OVERLAY void fn_804DC764(FeS804DC128* x)
{
    if (x->m158->fn_vslot60() != 0) {
        ((FeWV*)x->m15C)->s28((void*)fn_800C8048(x->m158->fn_vslot70()->fn_vslot33(5, 1))->fn_vslot31());
    } else {
        ((FeWX*)x->m15C)->s29(0xBBC);
    }
}

FE_OVERLAY void fn_804DC854(FeS804DC128* x)
{
    if (x->m158->fn_vslot60() == 0) {
        fn_8007DA8C__18Unk8007B2B0_Screenii(lbl_8061930C, x->m138, -1);
        return;
    }
    int j = 0;
    int sel = x->m158->fn_vslot60() - 1;
    void* g = lbl_8061930C;
    for (; j <= 3; j++) {
        if (j != x->m138) {
            int r = fn_8007DA34__18Unk8007B2B0_Screeni(g, j);
            if (r != -1 && sel == r) {
                sel = -1;
                break;
            }
        }
    }
    fn_8007DA8C__18Unk8007B2B0_Screenii(lbl_8061930C, x->m138, sel);
}

FE_OVERLAY void fn_804DC934(FeS804DC128* x, int a)
{
    if (a == -1) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        fn_804DC854(x);
        fn_804DC344(x);
        x->m150 = 1;
    } else if (a == -2) {
        fn_8001BC4C()->fn_8001BDAC(0xA0);
        x->m150 = 2;
        fn_804DC344(x);
    }
}

FE_OVERLAY void fn_804DC9B0(void) {}

FE_OVERLAY void fn_804DC9B4(FeS804DC128* x)
{
    ((FeStateD*)fn_800B555C())->m650 = 1;
    x->m1D4 = 1;
    fn_804D24E8((FeNav*)((char*)x + 0x144), (FeW*)((char*)x + 0x1F0));
    fn_804D24E8((FeNav*)((char*)x + 0x188), (FeW*)((char*)x + 0x3D0));
    fn_800C3AB4(fn_800C33D0(), 9);
    fn_804CEF98(x);
    x->m1E0 = fn_800C8054(fn_800C8044(x->fn_vslot32(lbl_805F972C, 1))->fn_vslot29(lbl_805F978C));
    x->m1EC = fn_800C8054(fn_800C8044(x->fn_vslot32(lbl_805F972C, 1))->fn_vslot29(lbl_805F97A0));
    x->m1E4 = fn_800C8054(fn_800C8044(x->fn_vslot32(lbl_805F9720, 1))->fn_vslot29(lbl_805F978C));
    x->m1E8 = fn_800C8054(fn_800C8044(x->fn_vslot32(lbl_805F9720, 1))->fn_vslot29(lbl_805F97A0));
}

FE_OVERLAY void fn_804DCEBC(FeS804DC128* x)
{
    fn_800C33D0();
    fn_800C3BE0();
    fn_804CF368(x);
    ((FeStateD*)fn_800B555C())->m650 = 0;
}

FE_OVERLAY void fn_804DCF00(FeS804DC128* x, signed char a, int b)
{
    if (((FeWX*)x)->s88(b) != 0) {
        if (a == 0) {
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, lbl_805F97CC, 15);
            mp->name[15] = a;
            fn_800B7B4C(FeGetMgr(), mp, x);
        } else {
            fn_804CF948(x, a, b);
        }
    }
}

FE_OVERLAY void fn_804DCFC8(FeS804DC128* x)
{
    ((FeStateD*)fn_800B555C())->m650 = 1;
    x->m1D4 = 1;
    fn_804D24E8((FeNav*)((char*)x + 0x144), (FeW*)((char*)x + 0x1E0));
    fn_804D24E8((FeNav*)((char*)x + 0x188), (FeW*)((char*)x + 0x434));
    fn_800C3AB4(fn_800C33D0(), 9);
    fn_804CEF98(x);
    FeW* a = fn_800C8044(x->fn_vslot32(lbl_805F972C, 1));
    FeW* b = fn_800C8044(x->fn_vslot32(lbl_805F9720, 1));
    x->m698 = fn_800C8044(a->fn_vslot32(lbl_805F5284, 1));
    x->m69C = fn_800C8044(b->fn_vslot32(lbl_805F5284, 1));
    x->m688 = fn_800C8054(a->fn_vslot29(lbl_805F97D8));
    x->m694 = fn_800C8054(a->fn_vslot29(lbl_805F97EC));
    x->m68C = fn_800C8054(b->fn_vslot29(lbl_805F97D8));
    x->m690 = fn_800C8054(b->fn_vslot29(lbl_805F97EC));
}

extern "C" FE_OVERLAY void fn_804DD170(FeS804DC128* x)
{
    fn_804CF304(x);
    void* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    FeNav* a = (FeNav*)((char*)x + 0x144);
    FeNav* b = (FeNav*)((char*)x + 0x188);
    fn_80124FA8(p, x);
    ((int (*)(void*, int))fn_80125154)(p, -2);
    ((int (*)(void*, int, int, int))fn_801251CC)(p, 2, 0x3BED, 1);
    ((int (*)(void*, int, int, int))fn_801251CC)(p, 0, 0x3BEC, 0);
    ((int (*)(void*, int, int, int))fn_801251CC)(p, 3, 0x1A2F, -5);
    fn_804D28B4(a);
    fn_804D28B4(b);
    if (a->m38 == -1) {
        fn_804D2118(a, 0);
        x->m698->fn_vslot8(0);
        x->m698->fn_vslot14(0);
    } else if (b->m38 == -1) {
        fn_804D2118(b, 0);
        x->m69C->fn_vslot8(0);
        x->m69C->fn_vslot14(0);
    }
    fn_8012E1C4((void*)x->m138, 1, 0x245F);
    fn_8012E1C4((void*)x->m138, 0, 0x245F);
    FeTeamRec* tr = lbl_806192E0->m4->m14;
    int s1 = ((FeTeamRec*)((char*)tr + 0xE64))->m198;
    int s0 = tr->m198;
    ((FeSub24*)((char*)x->m688 + 0x98))->s20(s1, 0);
    ((FeSub24*)((char*)x->m694 + 0x98))->s20(s1, 0);
    ((FeSub24*)((char*)x->m68C + 0x98))->s20(s0, 0);
    ((FeSub24*)((char*)x->m690 + 0x98))->s20(s0, 0);
}

extern "C" FE_OVERLAY void fn_804DD3C8(FeS804DC128* x)
{
    fn_804CF6A4(x);
    void* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    FeG10* g = lbl_806192E0->m4->m10;
    int a = g->m70;
    int b = g->m6C;
    if (a != -1) {
        if (b != -1) {
            if ((FeW24(x->m698) & 0x10000000) && (FeW24(x->m69C) & 0x10000000)) {
                ((int (*)(void*, int))fn_80125084)(p, 2);
                ((int (*)(void*, int))fn_80125084)(p, 3);
                ((int (*)(void*, int, int, int))fn_801251CC)(p, 0, 0x1A0D, 0);
                return;
            }
            ((int (*)(void*, int, int, int))fn_801251CC)(p, 2, 0x3BED, 1);
            ((int (*)(void*, int, int, int))fn_801251CC)(p, 0, 0x3BEC, 0);
            ((int (*)(void*, int, int, int))fn_801251CC)(p, 3, 0x1A2F, -5);
            return;
        }
        int r1 = FeW24(x->m698);
        if (r1 & 0x10000000) {
            if (r1 & 0x40000000) {
                ((int (*)(void*, int))fn_80125084)(p, 2);
                ((int (*)(void*, int))fn_80125084)(p, 3);
                ((int (*)(void*, int, int, int))fn_801251CC)(p, 0, 0x1A0D, 0);
                return;
            }
        }
    }
    if (b != -1) {
        int r2 = FeW24(x->m69C);
        if (r2 & 0x10000000) {
            if (r2 & 0x40000000) {
                ((int (*)(void*, int))fn_80125084)(p, 2);
                ((int (*)(void*, int))fn_80125084)(p, 3);
                ((int (*)(void*, int, int, int))fn_801251CC)(p, 0, 0x1A0D, 0);
                return;
            }
        }
    }
    ((int (*)(void*, int, int, int))fn_801251CC)(p, 2, 0x3BED, 1);
    ((int (*)(void*, int, int, int))fn_801251CC)(p, 0, 0x3BEC, 0);
    ((int (*)(void*, int, int, int))fn_801251CC)(p, 3, 0x1A2F, -5);
}

FE_OVERLAY void fn_804DD55C(FeS804DC128* x)
{
    fn_800C33D0();
    fn_800C3BE0();
    fn_804CF368(x);
    ((FeStateD*)fn_800B555C())->m650 = 0;
}

FE_OVERLAY void fn_804DD5A0(void)
{
    fn_800B555C();
    if (fn_800B57EC() == 1 || fn_800B5BD4(fn_800B555C()) == 1) {
        fn_800A3578(lbl_80619948);
    }
}

FE_OVERLAY void fn_804DD5E8(FeS804DC128* x, signed char a, int b)
{
    if (((FeWX*)x)->s88(b) != 0) {
        if (fn_804DD6A0(x, b) != 0 && a != -2) {
            if (a == 0) {
                fn_804CF948(x, -1, b);
            }
        } else if (fn_804DD6EC(x, b) == 0 || a != -5) {
            fn_804CF948(x, a, b);
        }
    }
}

FE_OVERLAY int fn_804DD6A0(FeS804DC128* x, int a)
{
    if ((FeW24(x->m698) & 0x10000000) && a == x->m17C) {
        return 1;
    }
    if ((FeW24(x->m69C) & 0x10000000) && a == x->m1C0) {
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_804DD6EC(FeS804DC128* x, int a)
{
    int r;
    if (a == x->m17C && fn_804DBC40((FeS804DB050*)((char*)x + 0x1E0)) != 0) {
        r = 1;
    } else if (a == x->m1C0 && fn_804DBC40((FeS804DB050*)((char*)x + 0x434)) != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

FE_OVERLAY FeS804DD760* fn_804DD760(FeS804DD760* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_80131380(self, a, 0, c, d, e, f, g, h);
    self->SetVptr(lbl_80681998);
    return self;
}

FE_OVERLAY void fn_804DD7A8(FeS804DD760* x)
{
    x->SetVptr(lbl_80681998);
    fn_80131450(x);
}

FE_OVERLAY void fn_804DD7D8(FeS804DD760* x)
{
    fn_801314B8(x);
}

FE_OVERLAY void fn_804DD7F8(FeS804DD760* x)
{
    fn_801315AC(x);
}

FE_OVERLAY void fn_804DD818(FeS804DD760* x)
{
    fn_801315CC(x);
}

FE_OVERLAY void fn_804DD838(FeS804DD760* x)
{
    fn_80134700(x);
}

FE_OVERLAY int fn_804DD858(void) { return 0; }

FE_OVERLAY void fn_804DD860(FeS804DC128* x, int a)
{
    if (a != 0) {
        x->fn_vslot16(0);
        x->fn_vslot8(0);
        return;
    }
    x->fn_vslot16(1);
    x->fn_vslot8(1);
}

FE_OVERLAY FeS804DD904* fn_804DD904(FeS804DD904* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066D508);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

FE_OVERLAY void fn_804DD954(FeS804DD904* x, int c)
{
    x->SetVptr(lbl_8066D508);
    fn_8035686C(x, c);
}

FE_OVERLAY void fn_804DD984(FeS804DD904* x)
{
    fn_800ECF18(x);
    void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125100(p);
    fn_801250D8(p);
    x->m134 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
}

FE_OVERLAY void fn_804DDA2C(FeS804DC128* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY int fn_804DDA4C(FeS804DD904* x, int a)
{
    ((FeState*)fn_800B555C())->m570 = a;
    fn_800B7ADC(FeGetMgr(), x);
    return 1;
}

}
