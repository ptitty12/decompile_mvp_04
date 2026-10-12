/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B985C-0x804BB110 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern "C" void fn_804B7FE4(FeScr* x);
extern int lbl_80621940[];
extern int lbl_80621928[];
extern "C" void fn_800C4B28(void* a, FeObj* b, int c);
extern "C" void fn_800C4B88(void* a, FeObj* b, int c);
extern const char lbl_805F4450[];
extern "C" int fn_80595398(int a, int b);
extern "C" int fn_80594810(int a, int b);
extern int lbl_806218F0[];
extern int lbl_806218BC[];
extern "C" void fn_800C4BE8(void* a, FeObj* b, int c);
extern "C" void fn_800C4A68(void* a, FeObj* b, int c);
#define FE_V4X(n) virtual void v##n(int a, int b, char* c, int d);

class FeObj4X : public UiBase { public: FE_LO(FE_V4X) virtual FeObj* v32(const char* a, int b); FE_HI(FE_V4X) };

extern "C" int fn_804089B4(char* dst, const char* fmt, ...);
extern "C" void fn_804B4BEC(FeScr* x);
extern "C" int fn_80590188(int a, int b);
extern "C" int fn_804BB0DC(void);
extern "C" FeRaw* fn_804B7C98(FeRaw* self, int i, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" FeRaw* fn_804B46CC(FeRaw* self, int i, int a, int b, int c, int d, int e, int f, int g, int h);
extern char lbl_80671A08[];
extern "C" FE_OVERLAY FeRaw* fn_804B985C(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804B46CC(self, FI(((FeMgr30*)lbl_8061930C)->m30, 0x14), a, b, c, d, e, f, g, h);
    self->m3C = lbl_80671A08;
    FI(self, 0xE24) = FI(((FeMgr30*)lbl_8061930C)->m30, 0x14);
    return self;
}

extern "C" FE_OVERLAY void fn_804B98F8(FeScr* x)
{
    fn_804B47C0(x);
}

extern "C" FE_OVERLAY void fn_804B9918(FeScr* x)
{
    fn_804B5FC4(x);
}

extern "C" FE_OVERLAY void fn_804B9938(FeScr* x)
{
    fn_804B4908(x);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER1", 1)))->v29(22400);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER2", 1)))->v29(22401);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER3", 1)))->v29(22402);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER4", 1)))->v29(22403);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER5", 1)))->v29(22404);
}

extern "C" FE_OVERLAY void fn_804B9AB8(FeScr* x)
{
    char buf[0x38];
    fn_804B4BEC(x);
    for (int i = 0; i < FI(FI(x, 0xE14), 0xC); i++) {
        fn_804089B4(buf, "%d", fn_80590188(FI(x, 0xE1C), i));
        ((FeObj4X*)x->m134)->v44(i, 2, buf, 5);
    }
    ((FeObj1*)x->m134)->v14(1);
}

extern "C" FE_OVERLAY void fn_804B9B70(FeScr* x)
{
    fn_804B530C(x);
    void* a = fn_800C33D0();
    FeObj* b = fn_800C8038(x->m140->v32("PIC", 1));
    int c = FI(x, 0xE20);
    fn_800C4D28(a, b, c, ((FeObjI*)x->m134)->v60());
}

extern "C" FE_OVERLAY void fn_804B9C08(FeScr* x)
{
    fn_804B6108(x);
}

extern "C" FE_OVERLAY void fn_804B9C28(FeScr* x)
{
    for (int i = 0; i < FI(FI(x, 0xE14), 0xC); i++) {
        ((FeObj2*)x->m134)->v101(i, fn_80590188(FI(x, 0xE1C), i) > 0 ? 1 : 0);
    }
    ((FeObj1*)x->m134)->v14(1);
}

extern "C" FE_OVERLAY int fn_804B9E6C(void)
{
    if (fn_800B555C()->m0 == 0x5C)
        return 2;
    return 1;
}

extern "C" FE_OVERLAY void fn_804B9EA0(FeScr* x)
{
    fn_804B47C0(x);
}

extern "C" FE_OVERLAY void fn_804B9EC0(FeScr* x)
{
    fn_804B5FC4(x);
}

extern "C" FE_OVERLAY void fn_804B9EE0(FeScr* x)
{
    fn_804B4908(x);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER1", 1)))->v29(22410);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER2", 1)))->v29(22401);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER3", 1)))->v29(22409);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER4", 1)))->v29(22403);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("HEADER5", 1)))->v29(22404);
}

extern "C" FE_OVERLAY void fn_804BA060(FeScr* x)
{
    char buf[56];
    fn_804B4BEC(x);
    for (int i = 0; i < FI(FI(x, 0xE14), 0xC); i++) {
        if (((FeObjI*)x)->v98() == 2) {
            fn_804089B4(buf, "%d", fn_80595398(FI(((FeMgr30*)lbl_8061930C)->m30, 0xC), i));
            ((FeObj4X*)x->m134)->v44(i, 2, buf, 5);
        } else {
            fn_804089B4(buf, "%d", fn_80594810(FI(((FeMgr30*)lbl_8061930C)->m30, 4), i));
            ((FeObj4X*)x->m134)->v44(i, 2, buf, 5);
        }
    }
    ((FeObj1*)x->m134)->v14(1);
}

extern "C" FE_OVERLAY void fn_804BA1A8(FeScr* x)
{
    fn_804B530C(x);
    if (((FeObjI*)x)->v98() == 2) {
        void* a = fn_800C33D0();
        FeObj* b = fn_800C8038(x->m140->v32("PIC", 1));
        fn_800C4BE8(a, b, lbl_806218F0[((FeObjI*)x->m134)->v60()]);
    } else {
        void* a = fn_800C33D0();
        FeObj* b = fn_800C8038(x->m140->v32("PIC", 1));
        fn_800C4A68(a, b, lbl_806218BC[((FeObjI*)x->m134)->v60()]);
    }
}

extern "C" FE_OVERLAY void fn_804BA2D8(FeScr* x)
{
    fn_804B6108(x);
}

extern char lbl_80672248[];
extern "C" FE_OVERLAY void fn_804BA2F8(FeScr* x)
{
    int any = 0;
    int i;
    for (i = 0; i < FI(FI(x, 0xE14), 0xC); i++) {
        int f = (((FeObjI*)x)->v98() == 2 ? fn_80595398(FI(((FeMgr30*)lbl_8061930C)->m30, 0xC), i) : fn_80594810(FI(((FeMgr30*)lbl_8061930C)->m30, 4), i)) > 0;
        ((FeObj2*)x->m134)->v101(i, f);
        any = any || f;
    }
    if (any == 0) {
        ((FeObj1*)x->m134)->v68(0);
        ((FeObj1*)x->m134)->v16(0);
        ((FeObj1*)x->m13C)->v16(0);
    }
    ((FeObj1*)x->m134)->v14(1);
}

extern char lbl_80672248[];
extern "C" FE_OVERLAY FeRaw* fn_804BA47C(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804B7C98(self, 0, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80672248;
    if (((int (*)(void*))fn_804BB0DC)(self) == 10)
        self->m140 = FI(((FeMgr30*)lbl_8061930C)->m30, 4);
    else
        self->m140 = FI(((FeMgr30*)lbl_8061930C)->m30, 0xC);
    return self;
}

extern "C" FE_OVERLAY void fn_804BA52C(FeScr* x)
{
    fn_804B7D2C(x);
}

extern "C" FE_OVERLAY void fn_804BA54C(FeScr* x)
{
    fn_804B7E24(x);
}

extern "C" FE_OVERLAY void fn_804BA56C(FeScr* x)
{
    int i = 0;
    fn_804B7FE4(x);
    for (i = 0; i < FI(x->m140, 0x14); i++) {
        ((FeObjS86*)x)->v86(0, x->m134, i, 0, i);
        ((FeObjS86*)x)->v86(1, x->m134, i, 1, i);
        ((FeObjS86*)x)->v86(3, x->m134, i, 3, i);
        ((FeObjS86*)x)->v86(2, x->m134, i, 2, i);
        ((FeObjS86*)x)->v86(5, x->m134, i, 4, i);
    }
    ((FeObjS86*)x)->v87();
    ((FeObj1*)x->m134)->v14(1);
}

extern "C" FE_OVERLAY void fn_804BA6C8(FeScr* x)
{
    fn_804B83A4(x);
    if (((FeObjI*)x)->v84() == 10) {
        void* a = fn_800C33D0();
        FeObj* b = fn_800C8038(x->m138->v32("PIC", 1));
        fn_800C4B28(a, b, lbl_80621940[((FeObjI*)x->m134)->v60()]);
    } else {
        void* a = fn_800C33D0();
        FeObj* b = fn_800C8038(x->m138->v32("PIC", 1));
        fn_800C4B88(a, b, lbl_80621928[((FeObjI*)x->m134)->v60()]);
    }
    ((FeObj*)x)->v90();
    ((FeObj*)x)->v88();
}

extern "C" FE_OVERLAY void fn_804BA828(FeScr* x, int k)
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
        FI(x, 0x148) = 1;
        ((FeObj2*)x)->v92(1, ((FeObjI*)x->m134)->v60());
        break;
    case 1:
        FI(x, 0x148) = 0;
        ((FeObj2*)x)->v92(0, ((FeObjI*)x->m134)->v60());
        break;
    }
}

extern "C" FE_OVERLAY void fn_804BAB14(int a, FeScr* x)
{
    if (a == 1)
        ((FeObj2*)x)->v91(((FeObjI*)x->m134)->v60(), FI(x, 0x148));
}

extern "C" FE_OVERLAY void fn_804BAB88(FeScr* x, int a)
{
    ((void (*)(FeScr*, int))fn_804B8570)(x, a);
    ((FeObjS86*)x)->v86(2, x->m134, a, 2, a);
    ((FeObjS86*)x)->v86(5, x->m134, a, 4, a);
    ((FeObjS86*)x)->v87();
    ((FeObj1*)x->m134)->v14(1);
    ((FeObjS86*)x)->v89();
}

extern "C" FE_OVERLAY int fn_804BB0DC(void)
{
    if (fn_800B555C()->m0 == 0x5C)
        return 0xB;
    return 0xA;
}
