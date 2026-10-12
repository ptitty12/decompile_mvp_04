/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B13FC-0x804B38C4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern "C" float fn_8058FA38(void* o, int i);

class FeV1Cz { public: char pad0[0x1C]; virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual int s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(int a); virtual int s14(); };

class FeSrcD { public: char pad0[0xC]; virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(int a); };

extern "C" void fn_8058F698(int a, int b);
class FeSrcC { public: char pad0[0xC]; virtual void s1(); virtual int s2(); virtual int s3(int a); virtual int s4(); };

#define FE_VI2(n) virtual int v##n(int a, int b);

class FeObjI2 : public UiBase { public: FE_LO(FE_VI2) virtual FeObj* v32(const char* a, int b); FE_HI(FE_VI2) };

extern "C" void fn_804B330C(FeScr* x);
extern "C" void fn_804B3424(FeScr* x);
extern const char lbl_805F4450[];
extern "C" void fn_804B2E18(FeScr* x, int k);
extern "C" void fn_804B34B8(FeScr* x);
extern "C" void fn_8058F09C(int a);
class FeV1Cx { public: char pad0[0x1C]; virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(int a, float b, float c); };

extern "C" FE_OVERLAY int fn_804B13FC(void) { return 0; }

extern char lbl_8066AA40[];
extern char lbl_8066ACE8[];
extern char lbl_8066ACE8[];
extern "C" FE_OVERLAY FeRaw* fn_804B1404(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066ACE8;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    int* p = &self->m154;
    for (int i = 0; i < 13; i++) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p += 3;
    }
    self->m144 = FI(lbl_8061930C, 0x34);
    return self;
}

extern char lbl_8066AA40[];
extern "C" FE_OVERLAY void fn_804B1B84(int unused, FeSrcC* src, FeObj* dst)
{
    FeHolder* h = (FeHolder*)dst;
    int i = 0;
    int n = src->s2();
    ((FeSub*)&h->mDC)->s15();
    while (i < n) {
        ((FeObj2*)dst)->v51(src->s3(i), 0);
        i++;
    }
    int v = src->s4();
    ((FeSub1*)&h->mDC)->s6(v);
}

extern "C" FE_OVERLAY void fn_804B1C78(FeScr* x)
{
    fn_800ECAA4(x);
    if (((FeSub*)((char*)FeP(x, 0x1BC) + 0xDC))->s5() == 0)
        ((FeObj3*)x->m140)->v91(9, 0, 0);
    else
        ((FeObj3*)x->m140)->v91(9, 0, 1);
}

extern "C" FE_OVERLAY void fn_804B1D20(FeScr* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

/* near-miss: retail keeps the element offset in its own register (addi 12 per step) and recomputes the base; 12 slots differ */
extern "C" FE_OVERLAY void fn_804B1D48(FeScr* x, int v)
{
    FI(x, 0x150) = 1;
    int i;
    int o = 0;
    for (i = 0; i <= 12; i++) {
        int k = o;
        o += 12;
        if (FI(x, 0x158 + k) == v)
            break;
    }
    fn_804B1E70(x, i);
}

extern "C" FE_OVERLAY void fn_804B1DA0(FeScr* x, int a)
{
    ((FeObj1*)FeP(x, 0x15C))->v8(a ^ 1);
    ((FeObj1*)x->m13C)->v8(a);
    FeObj* r = (FeObj*)((FeObjP2*)x->m140)->v73(0, 0);
    ((FeObj1*)((FeObj*)r)->v32("BUTTON", 1))->v8(a);
}

extern "C" FE_OVERLAY void fn_804B20A8(FeScr* x)
{
    int o = 0;
    int n = 13;
    do {
        char* wb = (char*)x + 0x15C;
        FeHolder* h = *(FeHolder**)(wb + o);
        int v = ((FeSub*)&h->mDC)->s5();
        char* sb = (char*)x + 0x154;
        FeSrcD* e = *(FeSrcD**)(sb + o);
        o += 12;
        e->s7(v);
    } while (--n != 0);
    FeHolder* h0 = (FeHolder*)FeP(x, 0x15C);
    if (((FeSub*)&h0->mDC)->s5() == 0)
        fn_8058F698(FI(x, 0x154), ((FeObjI*)x->m13C)->v31());
}

extern "C" FE_OVERLAY void fn_804B23D8(FeScr* x)
{
    fn_804B243C((FeScr*)(void*)fn_800B7AB8(UiGetMsgMgr(), "CSSETUP"), (int)x);
}

extern "C" FE_OVERLAY void fn_804B243C(FeScr* x, int a)
{
    FI(x, 0x150) = 1;
    ((FeObj*)x->m138)->v28();
    ((FeObj1*)x->m13C)->v28(a);
}

extern "C" FE_OVERLAY void fn_804B24AC(int a, FeObj* w)
{
    if (a == 1)
        ((FeObj2*)w)->v67(0, 0);
}

extern "C" FE_OVERLAY int fn_804B24F4(FeScr* x)
{
    ((FeObj*)x->m140)->v52();
    fn_804B1E70(x, ((FeObjI*)x->m140)->v60());
    return 1;
}

extern "C" FE_OVERLAY int fn_804B2564(FeScr* x)
{
    x->m140->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B25A0(FeScr* x)
{
    ((FeObj*)x->m140)->v50();
    fn_804B1E70(x, ((FeObjI*)x->m140)->v60());
    return 1;
}

extern "C" FE_OVERLAY int fn_804B2610(FeScr* x)
{
    x->m140->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B264C(FeScr* x)
{
    x->m140->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B2688(FeScr* x)
{
    x->m140->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B26C4(FeScr* x)
{
    x->m140->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B2700(FeScr* x)
{
    x->m140->v57();
    return 1;
}

extern "C" FE_OVERLAY FeRaw* fn_804B273C(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066AA40;
    self->m13C = 0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m13C = FI(lbl_8061930C, 0x34);
    return self;
}

extern "C" FE_OVERLAY void fn_804B2B18(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804B2D6C(FeScr* x, int k)
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
    case 1:
    case 2:
    case 3:
        fn_804B2E18(x, k);
        break;
    }
}

/* near-miss: one argument move; in the cur == sel arm retail passes sel (r29), ours cur (r31) */
extern "C" FE_OVERLAY void fn_804B3110(FeScr* x, char* out)
{
    float sum;
    int cur;
    int sel;
    sel = ((FeObjI*)x->m134)->v60();
    cur = ((FeV1Cz*)x->m144)->s9();
    if (sel > ((FeV1Cz*)x->m144)->s9() || cur == 0) {
        fn_80403144(out, fn_80090880(lbl_8061977C, 0x1A4B));
    } else {
        sum = 0.5f;
        if (cur == sel) {
            sum += fn_8058FA38(x->m144, sel);
        } else if (cur > sel) {
            do {
                int t = cur;
                cur--;
                sum += fn_8058FA38(x->m144, t);
            } while (cur > sel);
        }
        fn_800DF254(out, 0, 3, sum);
    }
}

extern "C" FE_OVERLAY void fn_804B3234(int a, int b)
{
    if (a == 1)
        fn_804B3260(b);
}

extern "C" FE_OVERLAY void fn_804B3260(int a)
{
    FeScr* x = (FeScr*)a;
    if (((FeObjI2*)x->m134)->v95(((FeObjI*)x->m134)->v60(), 0) != 0)
        fn_804B330C(x);
    else
        fn_804B3424(x);
    fn_804B2B40(x, ((FeObjI*)x->m134)->v60());
}

extern "C" FE_OVERLAY void fn_804B330C(FeScr* x)
{
    int cur = ((FeV1Cz*)x->m144)->s9();
    if (cur != 0) {
        int sel = ((FeObjI*)x->m134)->v60();
        if (sel == cur) {
            ((FeV1Cz*)x->m144)->s13(sel);
        } else if (((FeV1Cz*)x->m144)->s14() != 0) {
            cur = ((FeV1Cz*)x->m144)->s9();
            while (cur > sel) {
                ((FeV1Cz*)x->m144)->s13(cur);
                cur--;
            }
        }
        fn_804B34B8(x);
    }
}

extern "C" FE_OVERLAY void fn_804B3424(FeScr* x)
{
    int r = ((FeObjI*)x->m134)->v60();
    if (r != 0) {
        ((FeV1Cx*)x->m144)->s12(r, -1.0f, -1.0f);
        fn_8058F09C((int)x->m13C);
    }
    fn_804B34B8(x);
    fn_804B2B40(x, r);
}

extern "C" FE_OVERLAY int fn_804B3704(FeScr* x)
{
    ((FeObj*)x->m134)->v52();
    fn_804B2B40(x, ((FeObjI*)x->m134)->v60());
    return 1;
}

extern "C" FE_OVERLAY int fn_804B3774(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B37B0(FeScr* x)
{
    ((FeObj*)x->m134)->v50();
    fn_804B2B40(x, ((FeObjI*)x->m134)->v60());
    return 1;
}

extern "C" FE_OVERLAY int fn_804B3820(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern char lbl_8066A798[];
extern char lbl_8066A798[];
extern "C" FE_OVERLAY FeRaw* fn_804B385C(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066A798;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m13C = FI(lbl_8061930C, 0x34);
    return self;
}
