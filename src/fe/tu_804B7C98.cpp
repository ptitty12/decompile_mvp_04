/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B7C98-0x804B985C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"
struct FeRecN {
    float m0;
    float m4;
    int m8;
    int mC;
    int m10;
};
class FeObjS4 : public UiBase {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual FeObj* v32(const char* a, int b);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42(int a, int b, int c, int d);
    virtual void v43(int a, int b, char* c, int d);
    virtual void v44(int a, int b, char* c, int d);
};
extern "C" float fn_805922D4(int h, int a, int b);
extern "C" int sprintf(char* d, const char* f, ...);
extern "C" void fn_804B9740(int a, FeObj* w);
class FeV1Cf {
public:
    char pad0[0x1C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual float s4(int a, int b);
};
class FeV1Cr {
public:
    char pad0[0x1C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual int s7();
};
extern "C" int strcmp(const char* a, const char* b);
struct FeW06 {
    char pad0[0xC];
    int mC;
};
struct FeRoot06 {
    int m0;
    FeW06* m4;
};
extern FeRoot06* lbl_806192E0;
extern "C" void fn_8006F784(int a, int b);
extern "C" void fn_8006C698__11Unk80069F0C(FeW06* p);

extern const char lbl_805F4450[];
extern char lbl_80672830[];
extern char lbl_80672830[];

extern "C" FE_OVERLAY FeRaw* fn_804B7C98(FeRaw* self, int i, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m140 = i;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m3C = lbl_80672830;
    self->m13C = 0;
    self->m144 = 0;
    self->m144 = *(int*)((FeMgr30*)lbl_8061930C)->m30;
    return self;
}

extern "C" FE_OVERLAY void fn_804B7D2C(FeScr* x)
{
    fn_800ECE34(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)fn_800C8044(((FeObj*)x)->v32("BUYSELLGRID", 1)))->v32("GRID", 1));
    x->m138 = (FeObj*)fn_800C8044(((FeObj*)x)->v32("INFO", 1));
    ((FeObj1*)x->m134)->v105(1);
    ((FeObj1*)x->m134)->v88(0);
}

extern "C" FE_OVERLAY void fn_804B7E24(FeScr* x)
{
    fn_800ECF18(x);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("TITLE", 1)))->v29(((FeV1Cr*)x->m140)->s7());
    FeObj* t = fn_800C8040(((FeObj*)x)->v32("TITLE", 1));
    fn_800DD204(t, fn_800C8038(((FeObj*)x)->v32("SH1", 1)));
    x->m13C = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(x->m13C, x);
    ((FeObj*)x)->v85();
    ((FeObj*)x)->v87();
    ((FeObj*)x)->v89();
    ((FeObj*)x)->v88();
}

extern "C" FE_OVERLAY void fn_804B7FBC(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804B7FE4(FeScr* x)
{
    ((FeObjS79*)x->m134)->v79(FI(x->m140, 0x14), 0);
    x->m134->v3();
}

extern "C" FE_OVERLAY void fn_804B8050(FeScr* x, int kind, int u, int a, int b, int idx)
{
    char b8[0x68];
    char b70[0x38];
    switch (kind) {
    case 0:
        ((FeObjS4*)x->m134)->v42(a, b, ((FeRecN*)fn_80594240(x->m140, idx))->m10, 5);
        break;
    case 1:
        ((char* (*)(char*, int, int, float))fn_800DF254)(b8, 0, 3, ((FeRecN*)fn_80594240(x->m140, idx))->m0);
        ((FeObjS4*)x->m134)->v43(a, b, b8, 5);
        break;
    case 2: {
        int n = fn_80593E7C(x->m140, idx);
        sprintf(b70, "%d/%d", n, ((FeRecN*)fn_80594240(x->m140, idx))->m8);
        ((FeObjS4*)x->m134)->v44(a, b, b70, 5);
        break;
    }
    case 3:
        ((char* (*)(char*, int, int, float))fn_800DF254)(b8, 0, 3, ((FeRecN*)fn_80594240(x->m140, idx))->m4);
        ((FeObjS4*)x->m134)->v43(a, b, b8, 5);
        break;
    case 4: {
        FeRecN* r = (FeRecN*)fn_80594240(x->m140, idx);
        ((char* (*)(char*, int, int, float))fn_800DF254)(b8, 0, 3, r->m4 * (float)fn_80593E7C(x->m140, idx));
        ((FeObjS4*)x->m134)->v43(a, b, b8, 5);
        break;
    }
    case 5:
        ((char* (*)(char*, int, int, float))fn_800DF254)(b8, 0, 3, fn_805922D4(FI(x, 0x144), ((FeObjI*)x)->v84(), idx));
        ((FeObjS4*)x->m134)->v43(a, b, b8, 5);
        break;
    }
}

extern "C" FE_OVERLAY void fn_804B8288(FeScr* x)
{
    ((FeFnOI)fn_80125154)(x->m13C, 0);
    if (fn_80593E8C(x->m140, ((FeObjI*)x->m134)->v60()) > 0 && fn_80593EB0(x->m140, ((FeObjI*)x->m134)->v60(), 1) != 0)
        fn_801251CC(x->m13C, 0, 0xEA7, 1);
    else
        fn_80125084(x->m13C, 0);
    if (fn_80593E7C(x->m140, ((FeObjI*)x->m134)->v60()) > 0)
        fn_801251CC(x->m13C, 3, 0xEA6, 2);
    else
        fn_80125084(x->m13C, 3);
}

extern "C" FE_OVERLAY void fn_804B83A4(FeScr* x)
{
    char buf[0x400];
    fn_800DF254(buf, 0, 0, *(float*)((char*)FI(x, 0x144) + 0x12B78));
    ((FeObj1*)fn_800C8040(((FeObj*)x->m138)->v32("BANK", 1)))->v28((int)buf);
    fn_800E5380(x->m138);
}

extern "C" FE_OVERLAY void fn_804B8438(FeScr* x, int k)
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
    case 2:
        ((FeObj2*)x)->v91(((FeObjI*)x->m134)->v60(), 1);
        break;
    case 1:
        ((FeObj2*)x)->v91(((FeObjI*)x->m134)->v60(), 0);
        break;
    }
}

extern "C" FE_OVERLAY void fn_804B8570(FeScr* x, int a, int b)
{
    if (b != 0) {
        ((FeV1C*)x->m140)->s3(a, 1);
    } else {
        ((FeV1C*)x->m140)->s2(a, 1, -1.0f, -1.0f);
    }
}

extern "C" FE_OVERLAY void fn_804B85E4(FeScr* x)
{
    for (int i = 0; i < ((FeObjI*)x->m134)->v59(); i++) {
        if (fn_80593E8C(x->m140, i) == 0) {
            ((FeObj2*)x->m134)->v100(i, 1);
            ((FeObj2*)x->m134)->v101(i, 1);
        } else if (fn_80593EB0(x->m140, i, 1) != 0) {
            ((FeObj2*)x->m134)->v100(i, 0);
            ((FeObj2*)x->m134)->v101(i, 1);
        } else {
            ((FeObj2*)x->m134)->v101(i, 0);
        }
    }
}

extern "C" FE_OVERLAY int fn_804B86E8(FeScr* x)
{
    ((FeObj*)x->m134)->v52();
    ((FeObj*)x)->v89();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8748(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8784(FeScr* x)
{
    ((FeObj*)x->m134)->v50();
    ((FeObj*)x)->v89();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B87E4(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern char lbl_80672DC0[];
extern "C" FE_OVERLAY FeRaw* fn_804B8820(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80672DC0;
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804B8870(FeScr* x)
{
    fn_800ECE34(x);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)x)->v32("MENU", 1));
}

extern "C" FE_OVERLAY void fn_804B88C8(FeScr* x)
{
    fn_800ECF18(x);
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(p, x);
    ((FeFnOI)fn_80125154)(p, 0);
    ((FeFnOI)fn_80125128)(p, 1);
    if (fn_800A2E6C(lbl_80619948) != 0)
        ((FeObj3*)x->m134)->v91(3, 0, 0);
}

extern "C" FE_OVERLAY void fn_804B8988(FeScr* x, int k, int a)
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
        char* s = ((FeObjQ*)((FeObjQ*)x->m134)->v70())->v33(5, 1)->name;
        if (strcmp(s, "PREVIEW") == 0) {
            FeW06* w = lbl_806192E0->m4;
            fn_8006F784(w->mC, 0x22);
            fn_8006C698__11Unk80069F0C(w);
            fn_800B555C()->m570 = a;
        }
        fn_8040B830(p->name, s, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, x);
        break;
    }
    }
}

extern "C" FE_OVERLAY int fn_804B8AF4(FeScr* x)
{
    x->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8B30(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8B6C(FeScr* x)
{
    x->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8BA8(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern char lbl_80672B18[];
extern "C" FE_OVERLAY FeRaw* fn_804B8BE4(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80672B18;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804B8C30(FeScr* x)
{
    fn_800ECE34(x);
    fn_800E49A4();
}

extern "C" FE_OVERLAY void fn_804B8C54(FeScr* x)
{
    fn_800ECF18(x);
    FeObj* t1 = fn_800B7A94(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(t1, x);
    fn_80125100(t1);
    fn_801250D8(t1);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)x)->v32("GRID", 1));
}

extern "C" FE_OVERLAY void fn_804B8CFC(FeScr* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY void fn_804B8D1C(void) {}

extern "C" FE_OVERLAY int fn_804B8D20(FeObj* x)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_800B7B4C(UiGetMsgMgr(), p, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8D8C(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8DE8(FeScr* x)
{
    x->m134->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8E24(FeScr* x)
{
    x->m134->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8E60(FeScr* x)
{
    x->m134->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8E9C(FeScr* x)
{
    x->m134->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8ED8(FeScr* x)
{
    x->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8F14(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8F50(FeScr* x)
{
    x->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8F8C(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B8FC8(FeScr* x, int v)
{
    if (v == FI(x, 0x134)) {
        fn_800B7ADC(UiGetMsgMgr(), x);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804B9038(FeScr* x, char* dst)
{
    fn_8040B830(dst, ((FeObjQ*)((FeObjQ*)x->m134)->v70())->v33(5, 1)->name, 16);
}

extern char lbl_80672538[];
extern "C" FE_OVERLAY FeRaw* fn_804B90AC(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804B7C98(self, FI(((FeMgr30*)lbl_8061930C)->m30, 8), a, b, c, d, e, f, g, h);
    self->m3C = lbl_80672538;
    return self;
}

extern "C" FE_OVERLAY void fn_804B9138(FeScr* x)
{
    fn_804B7D2C(x);
}

extern "C" FE_OVERLAY void fn_804B9158(FeScr* x)
{
    fn_804B7E24(x);
}

extern "C" FE_OVERLAY void fn_804B9178(FeScr* x)
{
    int i = 0;
    fn_804B7FE4(x);
    while (i < FI(x->m140, 0x14)) {
        ((FeObjS86*)x)->v86(0, x->m134, i, 0, i);
        ((FeObjS86*)x)->v86(1, x->m134, i, 1, i);
        ((FeObjS86*)x)->v86(3, x->m134, i, 2, i);
        i++;
    }
    ((FeObj*)x)->v87();
    ((FeObj1*)x->m134)->v14(1);
}

extern "C" FE_OVERLAY void fn_804B927C(FeScr* x)
{
    fn_804B83A4(x);
    fn_800C4AC8(fn_800C33D0(), fn_800C8038(((FeObj*)x->m138)->v32("PIC", 1)), ((FeObjI*)x->m134)->v60());
    ((FeObj*)x)->v90();
    ((FeObj*)x)->v88();
}

extern "C" FE_OVERLAY void fn_804B933C(FeScr* x)
{
    FeObj* l = x->m140;
    ((FeObj1*)fn_800C8040(((FeObj*)x->m138)->v32("NAME", 1)))->v29(FI(fn_80594240(x->m140, ((FeObjI*)x->m134)->v60()), 0x10));
    ((FeObj1*)fn_800C8040(((FeObj*)x->m138)->v32("PROS", 1)))->v29(FI(fn_80593B68(l, ((FeObjI*)x->m134)->v60()), 0));
}

extern "C" FE_OVERLAY void fn_804B9464(FeScr* x, int k)
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
    case 2:
        ((FeObj2*)x)->v92(1, ((FeObjI*)x->m134)->v60());
        break;
    case 1:
        ((FeObj2*)x)->v92(0, ((FeObjI*)x->m134)->v60());
        break;
    }
}

extern "C" FE_OVERLAY void fn_804B959C(FeScr* x, int flag, int i)
{
    char buf[0x190];
    char b2[0x20];
    Unk80090880* t = lbl_8061977C;
    if (flag != 0) {
        ((char* (*)(char*, int, int, float))fn_800DF254)(b2, 0, 3, ((FeV1Cf*)x->m140)->s4(i, 1));
        fn_80403DE4(buf, fn_80090880(t, 0x14D7), fn_80090880(t, FI(fn_80594240(x->m140, i), 0x10)), b2);
    } else {
        fn_80403DE4(buf, fn_80090880(t, 0x14D6), fn_80090880(t, FI(fn_80594240(x->m140, i), 0x10)));
    }
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "POPUP");
    fn_801321D4(p, x, (FeCb)fn_804B9740, 0, buf, 2, -1, 1, fn_80090880(t, 0x26DF), fn_80090880(t, 0x26DE), 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_804B9740(int a, FeObj* w)
{
    if (a == 1)
        w->v93();
}

extern "C" FE_OVERLAY void fn_804B977C(FeScr* x)
{
    int a = ((FeObjI*)x->m134)->v60();
    FeObj* o = x->m140;
    fn_804B8570(x, a, fn_80593E7C(o, ((FeObjI*)x->m134)->v60()) > 0);
    ((FeObj*)x)->v87();
    ((FeObj1*)x->m134)->v14(1);
    ((FeObj*)x)->v89();
}
