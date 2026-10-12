/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B38C4-0x804B4908 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern "C" void fn_800E1B7C(int a, FeObj* b, void* c, int d, int e, float f);
extern "C" void* fn_80594240(FeObj* l, int i);
extern "C" FeObj* fn_800C8040(void* p);
extern "C" int fn_80125180(FeObj* o, int a, int b);
Unk8007F198_B* fn_8007F7D0(Unk8007F198_B* b, unsigned i);
extern "C" void fn_80551A80(int a, int b);
extern "C" void fn_80552054();
extern "C" void fn_80590910(int a);

class FeV1Ci { public: char pad0[0x1C]; virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual int s9(); virtual int s10(); };

extern "C" FeV1Ci* fn_8058F1F0(int a, int b);
extern "C" void fn_804BB110(FeCam* c);
extern char lbl_80671D28[];
extern char lbl_80672048[];
extern "C" void fn_804B4088(int a, FeObj* x);
extern const char lbl_805F3CA8[];
extern "C" FeObj* fn_804D2D50(void* x);
extern "C" void fn_804D3BA0(void* x);
extern "C" void fn_804B4600(void);
extern "C" void fn_804B4680(FeScr* x);
extern "C" void fn_804D32A0(void* x, int v);
extern void fn_800E2944(int a, int b);
struct FeD10 { char pad0[0x10]; };
class FeX10 : public FeD10 { public: virtual void x1(); virtual void x2(); virtual void x3(); virtual int x4(); };

extern "C" FE_OVERLAY void fn_804B38C4(FeScr* x)
{
    fn_800ECE34(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)x)->v32("MENU", 1));
    x->m138 = (FeObj*)fn_800C8044(((FeObj*)x)->v32("INFO", 1));
}

extern "C" FE_OVERLAY void fn_804B3954(FeScr* x)
{
    fn_800ECF18(x);
    fn_804B3A14(x, 0);
    FeObj* t2 = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(t2, x);
    ((FeFnOI)fn_80125154)(t2, 0);
    ((FeFnOIII)fn_801251CC)(t2, 0, 16, 1);
}

extern char lbl_80673068[];
extern char lbl_80621868[];
extern const char lbl_805F4450[];
extern "C" FeX10* fn_804D2ED0(void* x, int a);
extern "C" void fn_80524C94(void* o, const void* p);
extern "C" void fn_804D312C();
extern "C" void fn_804D2AC0(void* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, const void* l);

extern "C" FE_OVERLAY void fn_804B39EC(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern char lbl_8066AF90[];
extern "C" FE_OVERLAY void fn_804B3A14(FeScr* x, int idx)
{
    float f;
    char buf[100];
    FeV1Ci* l = ((FeV1Ci * (*)(int)) fn_8058F1F0)(FI(x, 0x13C));
    f = *(float*)((char*)*(int*)((FeMgr30*)lbl_8061930C)->m30 + 0x12B78);
    int s = l->s9();
    fn_800E1B7C(1, x->m138, l, idx, s, f);
    FeObj* w = fn_800C8040(x->m138->v32("NEXT", 1));
    int n = l->s10();
    if (n >= 0) {
        char* p = buf;
        ((char* (*)(char*, int, int, float))fn_800DF254)(p, 0, 3, *(float*)fn_80594240((FeObj*)l, n));
        ((FeObj1*)w)->v28((int)p);
    } else {
        ((FeObj1*)w)->v29(0x1A4B);
    }
}

extern "C" FE_OVERLAY void fn_804B3B4C(FeScr* x, int k)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    switch (k) {
    case 0:
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = k;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    case 1: {
        char* b = (char*)fn_800B555C() + 8;
        FI(b, 0x64C) = ((FeObjI*)x->m134)->v60();
        fn_8040B830(p->name, lbl_805F3CA8, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    }
    }
}

extern "C" FE_OVERLAY int fn_804B3C60(FeScr* x)
{
    ((FeObj*)x->m134)->v52();
    fn_804B3A14(x, ((FeObjI*)x->m134)->v60());
    return 1;
}

extern "C" FE_OVERLAY int fn_804B3CD0(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B3D0C(FeScr* x)
{
    ((FeObj*)x->m134)->v50();
    fn_804B3A14(x, ((FeObjI*)x->m134)->v60());
    return 1;
}

extern "C" FE_OVERLAY int fn_804B3D7C(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY FeRaw* fn_804B3DB8(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066AF90;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804B3E0C(FeScr* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_804B3E2C(FeScr* x)
{
    fn_800ECF18(x);
    x->m138 = fn_800B7AB8(UiGetMsgMgr(), "POPUP");
    FeObj* w = fn_800B7A94(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(w, x);
    fn_80125180(w, 1, 0x1A0C);
    fn_80125180(w, 0, 0x1A0D);
    int t = (int)fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0);
    int r = lbl_8061930C->fn_8007B320(0, t);
    fn_80552054();
    fn_80551A80(r, 1);
    fn_80590910(FI(lbl_8061930C, 0x30));
}

extern "C" FE_OVERLAY void fn_804B3F2C(FeScr* x)
{
    fn_800ECAA4(x);
    FeObj* w = x->m134;
    if (w != 0 && FI(w, 0) == 0)
        fn_800CFB38(w);
}

extern "C" FE_OVERLAY void fn_804B3F74(FeScr* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY void fn_804B3F94(void) {}

extern "C" FE_OVERLAY void fn_804B3F98(void) {}

extern "C" FE_OVERLAY void fn_804B3F9C(void) {}

extern char lbl_8066A4F0[];
extern "C" FE_OVERLAY int fn_804B3FA0(FeScr* x)
{
    if (fn_800B555C()->m590 != 0 || fn_800B555C()->m588 != 0) {
        fn_80131F34(x->m138, x, (FeCb)fn_804B4088, 0, 0x5CAA, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
        ((FeObj*)x->m138)->v86();
    } else {
        fn_800B7ADC(UiGetMsgMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_804B4088(int a, FeObj* x)
{
    if (a != 0) {
        fn_800E4B70();
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
    }
}

extern "C" FE_OVERLAY int fn_804B4118(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804B4174(void) { return 0; }

extern "C" FE_OVERLAY void fn_804B417C(int unused, char* dst)
{
    fn_8040B830(dst, "", 16);
}

extern "C" FE_OVERLAY FeRaw* fn_804B41AC(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066A4F0;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804B41F8(FeScr* x)
{
    fn_800ECF18(x);
    FeObj* t1 = fn_800B7A94(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(t1, x);
    ((FeFnOI)fn_80125154)(t1, 0);
}

extern "C" FE_OVERLAY void fn_804B4270(FeObj* x, int c)
{
    if (c == 0) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = c;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
    }
}

extern "C" FE_OVERLAY FeRaw* fn_804B42F8(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 0x15, lbl_80621868);
    self->m3C = lbl_80673068;
    return self;
}

extern "C" FE_OVERLAY void fn_804B4360(void)
{
    fn_804D312C();
    FeObj* w = fn_800B7AB8(UiGetMsgMgr(), "BACKIMAGE");
    fn_80524C94(w, "09bd");
}

extern "C" FE_OVERLAY void fn_804B43C8(FeScr* x)
{
    fn_804D3164(x);
    fn_804D2DC0(x, 22331);
}

extern "C" FE_OVERLAY int fn_804B4400(FeScr* x, int a)
{
    fn_800B555C()->m570 = a;
    fn_80132438(fn_804D2D50(x), x, (int)fn_804D3BA0, (FeCb)fn_804B4680, (FeCb)fn_804B4600, 0x3A61, -1, 1, 1.2f);
    ((FeObj*)fn_804D2D50(x))->v86();
    ((FeObj*)x)->v40();
    return 1;
}

extern "C" FE_OVERLAY void fn_804B44AC(FeScr* x)
{
    UiMsg m;
    UiMsg* p = &m;
    int v = fn_800B555C()->m570;
    ((void (*)(void*, int))fn_804D32A0)(x, v);
    fn_800E2944(fn_804D2ED0(x, 0x52)->x4(), v);
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805F3CA8, 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, x);
}

extern "C" FE_OVERLAY void fn_804B4570(FeScr* x)
{
    fn_800E49DC(x);
}

extern "C" FE_OVERLAY void fn_804B4590(FeScr* x)
{
    int v = fn_804D2ED0(x, 0x4D)->x4();
    if (v == 1 && FI(x, 0x170) == 0) {
        ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007295C();
        FI(x, 0x170) = v;
    }
}

extern "C" FE_OVERLAY void fn_804B4600(void)
{
    FeObj* t0 = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    ((FeObj1*)t0)->v85(0);
    FI(t0, 0x314) = 1;
}

extern "C" FE_OVERLAY void fn_804B4680(FeScr* x)
{
    ((FeObj1*)x)->v80(1);
    fn_804B44AC(x);
}

extern "C" FE_OVERLAY FeRaw* fn_804B46CC(FeRaw* self, int i, int a, int b, int c, int d, int e, int f, int g, int h)
{
    FeCam* cam = (FeCam*)((char*)self + 0x14C);
    Unk8007B2B0_Screen** pm = &lbl_8061930C;
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m3C = lbl_80671D28;
    fn_804BB110(cam);
    FeMgr30* m = (FeMgr30*)*pm;
    cam->mCC0 = lbl_80672048;
    FI(self, 0xE18) = 0;
    FI(self, 0xE14) = i;
    FI(self, 0xE18) = *(int*)m->m30;
    FeV1Ci* w = fn_8058F1F0(FI(m, 0x34), 1);
    FeMgr30* m2 = (FeMgr30*)*pm;
    FI(self, 0xE1C) = (int)w;
    FI(self, 0xE20) = fn_8058F1F0(FI(m2, 0x34), 1)->s9();
    return self;
}

extern "C" FE_OVERLAY void fn_804B47C0(FeScr* x)
{
    fn_800ECE34(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    x->m140 = (FeObj*)fn_800C8044(((FeObj*)x)->v32("INFO", 1));
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)fn_800C8044(((FeObj*)x)->v32("PRICEGRID", 1)))->v32("GRID", 1));
    FeObj* t10 = fn_800C8044(((FeObj*)x)->v32("TOPRIGHT", 1));
    x->m138 = (FeObj*)t10;
    x->m13C = (FeObj*)fn_800C805C(((FeObj*)t10)->v32("SUBSECTION", 1));
    ((FeObj1*)x->m134)->v105(1);
    ((FeObj*)x)->v84();
}
