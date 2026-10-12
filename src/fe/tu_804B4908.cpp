/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B4908-0x804B7C98 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern "C" void fn_804BB17C(FeCam* c, FeObj* w, int n);
extern "C" void fn_804BC414(FeCam* c, float a);
extern "C" void fn_804BC2B0(FeCam* c, float a, float b);
extern "C" int fn_804BB8B4(FeCam* c, int a);
extern "C" void fn_804BB780(FeCam* c, const char* s, int n);
extern "C" void fn_804BB58C(FeCam* c, char* s, int n);
extern "C" void fn_804BC42C(FeCam* c, int a, int b);
struct FeSt3 { int m0; int m4; int m8; };
extern "C" FeSt3* fn_805932E4(int a, int b, int c, int d);
extern "C" int fn_800B57EC();
extern "C" int fn_8056A5F4(int a, int b, int c, int d);
extern "C" int fn_8056A2F8(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern FeGame* lbl_80619948;

extern "C" FE_OVERLAY void fn_804B4BC4(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804B52E4(FeScr* x)
{
    fn_80125154(x->m144, 0);
}

extern "C" FE_OVERLAY void fn_804B530C(FeScr* x)
{
    char buf[0x400];
    fn_800DF254(buf, 0, 0, *(float*)((char*)FI(x, 0xE18) + 0x12B78));
    ((FeObj1*)fn_800C8040(((FeObj*)x->m140)->v32("BANK", 1)))->v28((int)buf);
    fn_800E5380(x->m140);
    ((FeObj*)x)->v88();
}

extern "C" FE_OVERLAY void fn_804B5FC4(FeScr* x)
{
    char buf[8];
    char* p = buf;
    FeCam* c = (FeCam*)((char*)x + 0x14C);
    fn_804BB17C(c, fn_800C8044(x->m138->v32("BARGRAPH", 1)), 0x4B);
    fn_804BC414(c, 0.5f);
    fn_804BC2B0(c, 0.0f, 100.0f);
    fn_804BB780(c, "Item", fn_804BB8B4(c, 4));
    fn_804BB780(c, "Avg.", fn_804BB8B4(c, 4));
    fn_804031BC(p, "");
    fn_804BB58C(c, p, (int)fn_80090880(lbl_8061977C, 0x57FA));
    fn_804BC42C(c, 0x1A4B, 0);
    fn_804BC42C(c, 0x1A4B, 1);
    fn_804BC42C(c, 0x1A4B, 2);
    fn_804BC42C(c, 0x1A4B, 3);
}

extern "C" FE_OVERLAY void fn_804B65D0(FeScr* x, int a)
{
    if (a != 0)
        FI(x, 0x148) = FI(x, 0x148) + 1;
    else
        FI(x, 0x148) = FI(x, 0x148) - 1;
    int t = FI(x, 0x148);
    if (t > 5)
        FI(x, 0x148) = 0;
    else if (t < 0)
        FI(x, 0x148) = 5;
    if (fn_804B797C(x) == 0 && (unsigned)(FI(x, 0x148) - 3) <= 1) {
        ((FeObj1*)x)->v93(a);
        return;
    }
    ((FeObj*)x)->v87();
}

extern "C" FE_OVERLAY void fn_804B7044(FeObj* x, int b)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    if (b == 0) {
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), &m, x);
    }
}

extern "C" FE_OVERLAY int fn_804B70D0(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v41();
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v39();
    ((FeObj*)x->m134)->v52();
    ((FeObj*)x)->v87();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B722C(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B7268(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v41();
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v39();
    ((FeObj*)x->m134)->v50();
    ((FeObj*)x)->v87();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B73C4(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B7400(FeScr* x)
{
    FeObj* w = x->m134;
    if (FI(w, 0x24) & 0x40000000) {
        ((FeObj1*)x)->v95(((FeObjI*)w)->v60());
        FeObj* c = (FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1);
        ((FeObj1*)fn_800C805C(c->v32("PRICE", 1)))->v40(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804B74FC(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B75A4(FeScr* x)
{
    FeObj* w = x->m134;
    if (FI(w, 0x24) & 0x40000000) {
        ((FeObj1*)x)->v94(((FeObjI*)w)->v60());
        FeObj* c = (FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1);
        ((FeObj1*)fn_800C805C(c->v32("PRICE", 1)))->v38(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804B76A0(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B7748(FeScr* x)
{
    FeObj* w = x->m13C;
    if (FI(w, 0x24) & 0x40000000) {
        ((FeObj1*)w)->v38(1);
        ((FeObj1*)x)->v93(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804B77BC(FeScr* x)
{
    x->m13C->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B77F8(FeScr* x)
{
    FeObj* w = x->m13C;
    if (FI(w, 0x24) & 0x40000000) {
        ((FeObj1*)w)->v40(1);
        ((FeObj1*)x)->v93(0);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804B786C(FeScr* x)
{
    x->m13C->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B78A8(FeScr* x)
{
    int r = 0;
    int g = lbl_80619948->m28;
    fn_800B555C();
    if (fn_800B57EC() == 1) {
        r = fn_8056A2F8(g, 0, 0, 1, 0, ((FeObjI*)x)->v96(), 0, 0, r, 0x1A);
    } else {
        r = -1;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804B7948(void)
{
    fn_8057CF60(fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0), 0);
}

extern "C" FE_OVERLAY int fn_804B797C(FeScr* x)
{
    int r = fn_804B78A8(x);
    if (r != -1) {
        int g = lbl_80619948->m28;
        int s = fn_800B555C()->m608;
        return fn_8056A5F4(g, s, r, ((FeObjI*)x)->v96());
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804B79FC(FeScr* x)
{
    int r = fn_804B797C(x);
    if (r != 0)
        return fn_800B5520(r);
    return 0x7C;
}

extern "C" FE_OVERLAY int fn_804B7A30(FeScr* x, int a, int b)
{
    if (fn_805932E4(FI(x, 0xE18), ((FeObjI*)x)->v98(), a, b)->m4 > 0) {
        FeSt3* p = fn_805932E4(FI(x, 0xE18), ((FeObjI*)x)->v98(), a, b);
        return p->m8 * 100 / fn_805932E4(FI(x, 0xE18), ((FeObjI*)x)->v98(), a, b)->m4;
    }
    return 0;
}
