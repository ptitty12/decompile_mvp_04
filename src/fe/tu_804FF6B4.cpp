/*
 * Front-end overlay code, .frontend_codeoverlay 0x804FF6B4-0x805002DC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

/* Q16-DECL-BEGIN */
extern "C" FeW* fn_800C8040(FeW* w);
/* Cursor list object embedded at +0x134 of the team-select screens: data pointer, count, capacity,
 * cursor, then its own vptr at +0x10. */
class FeLstV {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

inline int FeLstAtLast(FeLstV* l)
{
    if (l->m4 != 0)
        return l->mC == l->m4 - 1;
    return l->mC == 0;
}

struct FeScrLV : FeW {
    char pad40[0xF0];
    int m130;
    FeLstV ml;
    char pad148[0x1EC - 0x148];
    int m1EC;
};
extern "C" char* fn_800C8048(void* w);
/* Q16-DECL-END */

struct FeSub134 { int m0; int m4; int m8; int mC; };

extern float lbl_805FB59C;
extern "C" void fn_80132438(FePopup* p, void* self, int a, void* cb1, void* cb2, int b, int c, int d, float f);
extern const char lbl_80668910[];
extern "C" void fn_8007B924__18Unk8007B2B0_ScreeniiPc(void* g, int a, int b, char* out);
extern "C" int fn_800736EC__FPCc(const char* s);
extern "C" void fn_805371C4(void* p, int v);
extern "C" void fn_80536F28(void* p, int v);
extern "C" void fn_804FFBF4(void* x);
extern const char lbl_805F4F8C[];
extern const char lbl_805F7B70[];
extern "C" void fn_80125154(void* w, int v);
extern "C" void fn_80125128(void* w, int v);
extern const char lbl_805FB588[];
extern const char lbl_805FB57C[];
extern const char lbl_80680C08[];
extern const char lbl_805FA738[];
extern "C" int fn_804FF6B4(FeScrB* x);
extern "C" char* fn_804FF710(FeScrN* x, char* out);
extern "C" void fn_804FF834(FeScrD* x);
extern "C" void fn_804FF854(FeScrN* x);
extern "C" void fn_804FF8AC(FeScrN* x, int a);
extern "C" int fn_804FF8F8(FeS1EC* x, int a);
extern "C" int fn_804FF9EC(FeScrQ* x, int a);
extern "C" int fn_804FFB30(FeScrQ* x, int a);
extern "C" void fn_804FFBA8();
extern "C" int fn_804FFBAC(FeScrIdx* x);
extern "C" FeScrN* fn_804FFCB4(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804FFD08(FeScrN* x);
extern "C" int fn_804FFDBC(FeScrF* x);
extern "C" int fn_804FFDF8(FeScrF* x);
extern "C" int fn_804FFE34(FeScrF* x);
extern "C" int fn_804FFE70(FeScrF* x);
extern "C" int fn_804FFEAC(FeScrN* x);
extern "C" void fn_804FFEEC(FeScrN* x);
extern "C" void fn_804FFFB0();
extern "C" void fn_80500030(void* x);
extern "C" FeScrQ* fn_80500210(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80500278(FeScrN* x);

extern "C" FE_OVERLAY int fn_804FF6B4(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY char* fn_804FF710(FeScrN* x, char* out)
{
    return fn_8040B61C(out, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC);
}

extern "C" FE_OVERLAY void fn_804FF834(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_804FF854(FeScrN* x)
{
    FeSub134* p = (FeSub134*)&x->m134;
    fn_805371C4(p, 0x2000003F);
    fn_80536F28(p, 0);
    p->mC = 0;
    fn_804FFBF4(x);
}

extern "C" FE_OVERLAY void fn_804FF8AC(FeScrN* x, int a)
{
    fn_800ED310(x, a);
    x->fn_vslot8(a);
}

extern "C" FE_OVERLAY int fn_804FF8F8(FeS1EC* x, int a)
{
    x->m1EC = a;
    return 1;
}

extern "C" FE_OVERLAY int fn_804FF904(FeScrLV* x, int a)
{
    if (x->m1EC == a) {
        FeLstV* l = (FeLstV*)&x->ml;
        if (FeLstAtLast(l))
            l->mC = 0;
        else
            ((FeLstV*)&x->ml)->v6();
        fn_804FFBF4(x);
        ((FeWX*)x->fn_vslot32(lbl_805FB57C, 1))->s15(1);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804FF9EC(FeScrQ* x, int a)
{
    if (x->m1EC == a) {
        ((FeWX*)x->fn_vslot32(lbl_805FB57C, 1))->s15(0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804FFA64(FeScrLV* x, int a)
{
    if (x->m1EC == a) {
        FeLstV* l = (FeLstV*)&x->ml;
        if (l->mC == 0) {
            int c = l->m4;
            int r = 0;
            if (c != 0)
                r = c - 1;
            l->mC = r;
        } else
            ((FeLstV*)&x->ml)->v7();
        fn_804FFBF4(x);
        ((FeWX*)x->fn_vslot32(lbl_805FB588, 1))->s15(1);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804FFB30(FeScrQ* x, int a)
{
    if (x->m1EC == a) {
        ((FeWX*)x->fn_vslot32(lbl_805FB588, 1))->s15(0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804FFBA8()
{
}

extern "C" FE_OVERLAY int fn_804FFBAC(FeScrIdx* x)
{
    char buf[0x38];
    fn_8007B924__18Unk8007B2B0_ScreeniiPc(lbl_8061930C, 0, x->m134[x->m140], buf);
    return fn_800736EC__FPCc(buf);
}

extern "C" FE_OVERLAY void fn_804FFBF4(void* q)
{
    FeScrIdx* x = (FeScrIdx*)q;
    FeSub134* p = (FeSub134*)&x->m134;
    char buf[0x38];
    fn_8007B924__18Unk8007B2B0_ScreeniiPc(lbl_8061930C, 1, x->m134[p->mC], buf);
    fn_800C8040((FeW*)x->fn_vslot32("TEAMNAME", 1));
    fn_8007B924__18Unk8007B2B0_ScreeniiPc(lbl_8061930C, 3, x->m134[p->mC], buf);
    fn_800C8040((FeW*)x->fn_vslot32("TEAMCITY", 1));
}

extern "C" FE_OVERLAY FeScrN* fn_804FFCB4(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80680C08);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804FFD08(FeScrN* x)
{
    fn_800ECF18(x);
    x->m134 = (FeW*)fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    x->m138 = fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1));
    fn_80124FA8(x->m134, x);
    fn_80125154(x->m134, 0);
    fn_80125128(x->m134, 1);
}

extern "C" FE_OVERLAY int fn_804FFDBC(FeScrF* x)
{
    x->m138->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FFDF8(FeScrF* x)
{
    x->m138->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FFE34(FeScrF* x)
{
    x->m138->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FFE70(FeScrF* x)
{
    x->m138->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804FFEAC(FeScrN* x)
{
    x->fn_vslot67(1, 0);
    return 1;
}

extern "C" FE_OVERLAY void fn_804FFEEC(FeScrN* x)
{
    FePopup* p = (FePopup*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    fn_80132438(p, x, 0, (void*)fn_80500030, (void*)fn_804FFFB0, 0x3A61, -1, 1, lbl_805FB59C);
    ((FeWY*)p)->s84(0);
    p->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_804FFFB0()
{
    FePopup* p = (FePopup*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    ((FeWX*)p)->s85(0);
    *(int*)((char*)p + 0x314) = 1;
}

extern "C" FE_OVERLAY void fn_80500030(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805FA738, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY void fn_805000B4(FeScrN* x, int kind)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    switch (kind) {
    case 0:
        fn_8040B830(mp->name, lbl_805F4450, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    case 1:
        if (x->m138->fn_vslot60() != 0) {
            fn_8040B830(mp->name, fn_800C8048(x->m138->fn_vslot70()->fn_vslot33(5, 1)) + 0xC, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
        } else
            ((FeWX*)x)->s84();
        break;
    }
}

extern "C" FE_OVERLAY FeScrQ* fn_80500210(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80668910);
    self->m130 = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m1DC = 0;
    self->m1E0 = -1;
    self->m1E4 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80500278(FeScrN* x)
{
    fn_800ECE34(x);
    x->m154 = (FeW*)fn_800B7AB8(FeGetMgr(), lbl_805F4F8C);
}
