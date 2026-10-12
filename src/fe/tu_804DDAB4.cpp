/*
 * Front-end overlay code, .frontend_codeoverlay 0x804DDAB4-0x804DE730 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804D08D0.h"

extern "C" {

FE_OVERLAY int fn_804DDAB4(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

FE_OVERLAY int fn_804DDB20(FeS804DDB20* x)
{
    x->m134->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804DDB5C(FeS804DDB20* x)
{
    x->m134->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804DDB98(FeS804DDB20* x)
{
    x->m134->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804DDBD4(FeS804DDB20* x)
{
    x->m134->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_804DDC10(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

/* near-miss: 79 vs 80 insns; retail shares the m4C4/m4C8/m4CC tail between the SAVE and DELETE branches (24 store orders tried) */
FE_OVERLAY void fn_804DDC6C(FeS804DDB20* x, char* out)
{
    FeW* w = x->m134->fn_vslot70();
    char* s = (char*)w->fn_vslot33(5, 1) + 0xC;
    int t1 = (int)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x60E);
    int t2 = (int)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x60E);
    int v = fn_8040B574(s, lbl_805F9804);
    if (v == 0) {
        FeStateE* st = (FeStateE*)((char*)fn_800B555C() + 8);
        st->m4D0 = t1;
        st->m4C4 = 1;
        st->m4C8 = 0x11;
        st->m4CC = v;
    } else {
        v = fn_8040B574(s, lbl_805F9810);
        if (v == 0) {
            FeStateE* st = (FeStateE*)((char*)fn_800B555C() + 8);
            st->m4D0 = t1;
            st->m4C8 = 0x11;
            st->m4CC = v;
            st->m4C4 = v;
        } else {
            v = fn_8040B574(s, lbl_805F981C);
            if (v == 0) {
                FeStateE* st = (FeStateE*)((char*)fn_800B555C() + 8);
                st->m4D0 = t2;
                st->m4C4 = 2;
                st->m4C8 = 0x11;
                st->m4CC = v;
            }
        }
    }
    fn_8040B830(out, s, 16);
}

FE_OVERLAY FeS804DDDA8* fn_804DDDA8(FeS804DDDA8* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8065C4E0);
    fn_80134E38(self->m134, 0);
    self->m17C = lbl_8066CCE0;
    self->SetVptr(lbl_8066CCF8);
    self->m180 = 0;
    self->m184 = 0;
    self->m188 = 0;
    self->m18C = 0;
    self->m190 = 0;
    self->m194 = 0;
    self->m198 = 0;
    return self;
}

FE_OVERLAY void fn_804DDE34(FeS804DDDA8* x, int c)
{
    x->m17C = lbl_8066CCE0;
    x->SetVptr(lbl_8066CCF8);
    fn_80134EC8(x->m134, 0);
    fn_8035686C(x, c);
}

FE_OVERLAY void fn_804DDE90(FeS804DDDA8* x)
{
    fn_800ECF18(x);
    void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125100(p);
    ((int (*)(void*, int, int))fn_80125180)(p, 0, 0x1FE1);
    ((int (*)(void*, int, int))fn_80125180)(p, 2, 0x3B70);
    x->m180 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
    x->m184 = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    fn_804DE138(x);
}

FE_OVERLAY void fn_804DDF8C(FeScrD* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY int fn_804DDFAC(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_804DE008(FeS804DDDA8* x)
{
    if (x->m198 != 0) {
        fn_80131F34(x->m184, x, (void (*)(int, void*))fn_804DE55C, (int)fn_80529784, 0x3364, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
        x->m184->fn_vslot86();
    } else {
        FeMsg m;
        FeMsg* mp = &m;
        fn_8035682C(mp);
        fn_800B7B4C(FeGetMgr(), mp, x);
    }
    return 1;
}

FE_OVERLAY int fn_804DE0F0(FeS804DDDA8* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    fn_804DE138(x);
    return 1;
}

FE_OVERLAY int fn_804DE130(void) { return 0; }

FE_OVERLAY void fn_804DE138(FeS804DDDA8* x) {}

FE_OVERLAY void fn_804DE13C(FeS804DDDA8* x) {}

FE_OVERLAY int fn_804DE140(FeS804DDDA8* x)
{
    x->m180->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804DE17C(FeS804DDDA8* x)
{
    x->m180->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804DE1B8(FeS804DDDA8* x)
{
    x->m180->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804DE1F4(FeS804DDDA8* x)
{
    x->m180->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_804DE230(FeS804DDDA8* x)
{
    if (x->m180->fn_vslot60() == 0) {
        int a = x->m188;
        int c = a - 1;
        x->m18C = a;
        x->m188 = (c + x->m190) % x->m190;
        fn_804DE13C(x);
    } else {
        FeW* w = fn_800C8044(x->m180->fn_vslot70());
        fn_800C805C(w->fn_vslot32(lbl_805F7944, 1))->fn_vslot40(1);
    }
    return 1;
}

FE_OVERLAY int fn_804DE314(FeS804DDDA8* x)
{
    if (x->m180->fn_vslot60() != 0) {
        FeW* w = fn_800C8044(x->m180->fn_vslot70());
        ((FeWX*)fn_800C805C(w->fn_vslot32(lbl_805F7944, 1)))->s41();
    }
    return 1;
}

FE_OVERLAY int fn_804DE3C4(FeS804DDDA8* x)
{
    if (x->m180->fn_vslot60() == 0) {
        int a = x->m188;
        x->m18C = a;
        x->m188 = (a + 1) % x->m190;
        fn_804DE13C(x);
    } else {
        FeW* w = fn_800C8044(x->m180->fn_vslot70());
        fn_800C805C(w->fn_vslot32(lbl_805F7944, 1))->fn_vslot38(1);
    }
    return 1;
}

FE_OVERLAY int fn_804DE4A4(FeS804DDDA8* x)
{
    if (x->m180->fn_vslot60() != 0) {
        FeW* w = fn_800C8044(x->m180->fn_vslot70());
        ((FeWX*)fn_800C805C(w->fn_vslot32(lbl_805F59C4, 1)))->s39();
    }
    return 1;
}

FE_OVERLAY void fn_804DE554(void) {}

FE_OVERLAY void fn_804DE558(void* x) {}

FE_OVERLAY void fn_804DE55C(int a, void* x)
{
    if (a != 0) {
        if (a == 1) {
            fn_804DE558(x);
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, lbl_805F4450, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
        }
    }
}

/* near-miss: frame 56 vs 40 (-ffloat-store spill of the u8 -> float product) */
FE_OVERLAY FeS804DE5F8* fn_804DE5F8(FeS804DE5F8* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    int z = 0;
    int i = 0;
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = z;
    self->m134 = z;
    self->SetVptr(lbl_8066D7B0);
    fn_800D876C__FP13Unk800D876C_A(self->m138);
    self->m158 = z;
    unsigned char* rec = (unsigned char*)fn_8007FE04((Unk8007F198_D*)lbl_8061930C);
    self->m14C = z;
    self->m150 = z;
    self->m154 = z;
    Unk8001BC8C* snd = fn_8001BC4C();
    do {
        snd->fn_8001C05C(i, (float)rec[4 + i] * lbl_805F9830, 1);
        i++;
    } while (i <= 4);
    snd->fn_8001C28C(*(unsigned short*)(rec + 0xA));
    fn_8001BC4C()->fn_8001BDAC(0xB1);
    return self;
}

FE_OVERLAY void fn_804DE6E4(FeS804DDDA8* x)
{
    fn_800ECE34(x);
    fn_8007FDD4__FP13Unk8007F198_D(lbl_8061930C, 0);
    if (lbl_8061ABD8 != 0) {
        fn_800C3AB4(fn_800C33D0(), 9);
    }
}

}
