/*
 * Front-end overlay code, .frontend_codeoverlay 0x80464090-0x804654A0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"
#include "game/tu_80090880.h"

extern "C" char* strncpy(char* dst, const char* src, unsigned n);


extern const char lbl_805F5068[];
extern const char lbl_805F4F20[];
extern const char lbl_805F588C[];
struct FeSt630 {
    char pad0[0x630];
    int m630;
};
extern "C" {
FeW* fn_800C8040(FeW* w);
void fn_800C2034(void* p, int a);
}


extern const char lbl_805F5274[];
extern "C" {
int fn_80360ED0__FP11Unk80360ED0(char* p);
int fn_80360EF0__FP11Unk80360ED0(char* p);
void* fn_8007F7D0__FP13Unk8007F198_BUi(void* g, unsigned a);
FeW* fn_800C8044(FeW* w);
void fn_800E4C1C(void* a, FeW* w);
int fn_8013484C();
void fn_80134854();
void fn_804644D8(FeScrF* x);
}


extern void* lbl_8061977C;
extern "C" {
void fn_80403DE4(unsigned short* dst, const unsigned short* fmt, ...);
}


extern const char lbl_805F4EF4[];
extern "C" {
FeW* fn_800C8060(FeW* w);
void fn_804647CC(FeScrF* x);
void fn_8046494C(FeScrF* x);
void fn_80464BF4(FeScrF* x);
}


extern "C" {
void fn_800A2F14(FeGlobal80619948* g);
int fn_800B5758(FeState* st);
void fn_80464CF0();
}

extern "C" {

FE_OVERLAY void fn_80464090(FeScrF* x)
{
    fn_800ECF18(x);
    x->m144 = (char*)lbl_80619948->m58;
    x->m134 = (int)fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8((void*)x->m134, x);
    fn_801250D8((void*)x->m134);
    FeW* o = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F20);
    o->fn_vslot32(lbl_805F5068, 1)->fn_vslot8(0);
    o->fn_vslot32(lbl_805F5068, 1)->fn_vslot16(0);
    fn_800C2034((char*)fn_800B555C() + 8, 0);
    x->m138 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
    x->m13C = (int)fn_800C8040(x->fn_vslot32(lbl_805F588C, 1));
    FeSt630* st = (FeSt630*)((char*)fn_800B555C() + 8);
    if (fn_800B555C()->m0 == 0x54)
        st->m630 = x->m140;
    else
        x->m140 = st->m630;
    fn_804644D8(x);
    void* r = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
    fn_800E4C1C(r, fn_800C8044(x->fn_vslot32(lbl_805F5274, 1)));
}

FE_OVERLAY void fn_804642AC(FeScrF* x)
{
    fn_800ECAA4(x);
    if (fn_80360ED8(x->m144 + 0xCE8) != 0) {
        if (lbl_8061A328 % 5 == 0) {
            fn_80548EC0(x->m144);
        }
    }
}

FE_OVERLAY void fn_80464324(FeScrF* x, int a)
{
    fn_800ED310(x, a);
    if (a != 0) {
        x->m138->fn_vslot14(1);
    } else {
        x->m138->fn_vslot14(0);
    }
}

FE_OVERLAY void fn_804643A0(FeScrF* x, int sel)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    switch (sel) {
    case 5:
        fn_804647CC(x);
        return;
    case 6:
        fn_8046494C(x);
        return;
    case 0:
        fn_80464BF4(x);
        return;
    case 1:
    case 2:
    case 3:
    case 4:
    default:
        strncpy(mp->name, fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot70()->fn_vslot33(5, 1)->mC, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        return;
    }
}

FE_OVERLAY void fn_804644D8(FeScrF* x)
{
    unsigned short buf[0x34];
    if (x->m140 <= 6) {
        fn_80403DE4(buf, ((unsigned short* (*)(Unk80090880*, int))fn_80090880)((Unk80090880*)lbl_8061977C, 0x419E), x->m140, 6);
        ((FeW*)x->m13C)->fn_vslot28((const char*)buf);
        ((FeWV*)x->m138)->s101(0, 1);
        ((FeWV*)x->m138)->s101(2, 1);
        ((FeWV*)x->m138)->s101(5, 1);
    } else {
        ((FeW*)x->m13C)->fn_vslot29((const char*)0x4157);
        ((FeWV*)x->m138)->s101(0, 0);
        ((FeWV*)x->m138)->s101(2, 0);
        ((FeWV*)x->m138)->s101(5, 0);
    }
    ((FeWV*)x->m138)->s101(1, *(int*)(x->m144 + 0xCE4) != 0 ? 1 : 0);
}

FE_OVERLAY void fn_8046468C(FePopup* p)
{
    FeScrF* x = (FeScrF*)p;
    fn_804644D8(x);
    while (fn_80360EF0__FP11Unk80360ED0(x->m144 + 0xCE8) != 6)
        fn_80548EC0(x->m144);
    if (fn_80360ED0__FP11Unk80360ED0(x->m144 + 0xCE8) != 0) {
        FePopup* pp = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
        fn_80131F34(pp, x, (void (*)(int, void*))fn_80134854, (int)fn_8013484C, 0x4780, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
        pp->fn_vslot86();
        void* r = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
        fn_800E4C1C(r, fn_800C8044(x->fn_vslot32(lbl_805F5274, 1)));
    }
}

FE_OVERLAY void fn_804647CC(FeScrF* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
    fn_80131F34(p, x, fn_8046488C, 0, 0x46B2, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->fn_vslot86();
}

FE_OVERLAY void fn_8046488C(int a, void* x)
{
    if (a != 0) {
        if (a == 1) {
            if (lbl_80619948->m80 == 0x13) {
                fn_80464AF0(x);
                return;
            }
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            strncpy(mp->name, lbl_805F5284, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
            fn_8054899C(lbl_80619948->m58);
        }
    }
}

FE_OVERLAY void fn_8046494C(FeScrF* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
    fn_80131F34(p, x, fn_80464A0C, 0, 0x4846, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->fn_vslot86();
}

FE_OVERLAY void fn_80464A0C(int a, void* x)
{
    if (a != 0) {
        if (a == 1) {
            if (lbl_80619948->m80 == 0x13) {
                fn_800A2F14(lbl_80619948);
                fn_80464AF0(x);
                return;
            }
            if (fn_800B5758(fn_800B555C()) == 0) {
                ((void (*)(void*))fn_80464CF0)(x);
            } else {
                FeMsg m;
                FeMsg* mp = &m;
                fn_8035682C(mp);
                strncpy(mp->name, lbl_805F5284, 15);
                mp->name[15] = 0;
                fn_800B7B4C(FeGetMgr(), mp, x);
            }
            fn_8054899C(lbl_80619948->m58);
        }
    }
}

FE_OVERLAY void fn_80464AF0(void* x)
{
    fn_80449168(fn_800B7AB8(FeGetMgr(), lbl_805F528C), 0x13, x, fn_80464B60);
}

FE_OVERLAY void fn_80464B60(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    strncpy(mp->name, lbl_805F5284, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
    fn_8054899C(lbl_80619948->m58);
}

FE_OVERLAY void fn_80464BF4(FeScrF* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    x->m140 = x->m140 + 1;
    fn_800B555C()->m638 = x->m140;
    fn_80548E68(x->m144, x->m140);
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F522C);
    p->m30C = (void*)fn_80464C94;
    fn_8049AB94(p);
}

FE_OVERLAY void fn_80464C94()
{
    fn_8046468C(fn_800B7AB8(FeGetMgr(), lbl_805F5894));
}

FE_OVERLAY void fn_80464CF0()
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F522C);
    p->m30C = (void*)fn_80464D68;
    fn_8049ABD4(p);
}

FE_OVERLAY void fn_80464D68()
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F5894);
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    strncpy(mp->name, lbl_805F5284, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, p);
}

FE_OVERLAY int fn_80464E1C(FeScrF* x)
{
    x->m138->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_80464E58(FeScrF* x)
{
    x->m138->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_80464E94(FeScrF* x)
{
    x->m138->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_80464ED0(FeScrF* x)
{
    x->m138->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_80464F0C(FeScrF* x, FeW* w, int b, int c)
{
    int r;
    if (w != x->m138) {
        r = 0;
    } else {
        x->fn_vslot67(c, 0);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_80464F64(FeScrF* x)
{
    x->fn_vslot80(0);
    x->fn_vslot67(x->m138->fn_vslot60(), 0);
    return 1;
}

FE_OVERLAY FeScrG* fn_80464FF0(FeScrG* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 1, 0x3364, 0x26, lbl_8062167C);
    self->SetVptr(lbl_80679BF0);
    return self;
}

FE_OVERLAY void fn_80465058(FeScrG* x)
{
    fn_804D3164(x);
    fn_804D2DC0(x, 0xC1B);
    x->m13C = 1;
    x->fn_vslot87();
}

FE_OVERLAY void fn_804650B0(FeScrG* x)
{
    fn_800ECAA4(x);
    x->fn_vslot87();
}

FE_OVERLAY void fn_804650F4(FeScrG* x)
{
    fn_804D32A0(x);
    int one = 1;
    lbl_8061A308 = one;
}

FE_OVERLAY FeScrG* fn_80465120(FeScrG* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 1, 0x3364, 0x26, lbl_80621714);
    self->SetVptr(lbl_80679920);
    return self;
}

FE_OVERLAY void fn_80465188(FeScrG* x)
{
    fn_804D3164(x);
    fn_804D2DC0(x, 0xC1B);
    x->m13C = 1;
    x->fn_vslot87();
}

FE_OVERLAY void fn_804651E0(FeScrG* x)
{
    fn_800ECAA4(x);
    x->fn_vslot87();
}

FE_OVERLAY void fn_80465224(FeScrG* x)
{
    fn_804D32A0(x);
    int one = 1;
    lbl_8061A308 = one;
}

FE_OVERLAY FeScrH* fn_80465250(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80679678);
    self->m130 = 0;
    return self;
}

FE_OVERLAY void fn_8046529C(FeScrH* x)
{
    fn_800ECE34(x);
}

FE_OVERLAY void fn_804652BC(FeScrH* x)
{
    fn_800ECF18(x);
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(w, x);
    fn_801250D8(w);
}

FE_OVERLAY void fn_80465330(FeScrH* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY void fn_80465350(FeScrH* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_80465370(void) {}

FE_OVERLAY void fn_80465374(void) {}

FE_OVERLAY void fn_80465378(void) {}

FE_OVERLAY int fn_8046537C(FeScrH* x)
{
    fn_800A2030(lbl_80619948, 1);
    fn_800B7ADC(FeGetMgr(), x);
    return 1;
}

FE_OVERLAY int fn_804653E8(void) { return 0; }

FE_OVERLAY void fn_804653F0(int a, char* dst)
{
    strncpy(dst, lbl_805F3CA8, 16);
}

FE_OVERLAY FeScrI* fn_80465420(FeScrI* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80681C88);
    self->m130 = 0;
    self->m16C = 0;
    self->m208 = 0;
    self->m20C = 0;
    self->m210 = 1;
    return self;
}

FE_OVERLAY void fn_80465480(FeScrI* x)
{
    fn_800ECE34(x);
}

}
