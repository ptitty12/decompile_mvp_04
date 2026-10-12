/*
 * Front-end overlay code, .frontend_codeoverlay 0x804AECD0-0x804B13FC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"

extern char lbl_80673B30[];
extern "C" FE_OVERLAY FeRaw* fn_804AFF98(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80673B30;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern char lbl_8067CF28[];
extern "C" FE_OVERLAY FeRaw* fn_804B0BA0(FeRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067CF28;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804B0BEC(FeScr* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_804B0F28(FeScr* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_804B0F48(FeScr* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY int fn_804B10F0(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}


extern "C" FE_OVERLAY int fn_804B0A2C(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B0B64(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY void fn_804B0F68(void) {}

extern "C" FE_OVERLAY int fn_804AFDE8(FeScr* x)
{
    ((FeObj*)x->m138)->v50();
    ((FeObj*)x->m13C)->v50();
    fn_804AFCCC(x);
    fn_804AF2A0(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804AFE5C(FeScr* x)
{
    ((FeObj*)x->m138)->v51();
    ((FeObj*)x->m13C)->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804AFEC0(FeScr* x)
{
    ((FeObj*)x->m138)->v52();
    ((FeObj*)x->m13C)->v52();
    fn_804AFCCC(x);
    fn_804AF2A0(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_804AFF34(FeScr* x)
{
    ((FeObj*)x->m138)->v53();
    ((FeObj*)x->m13C)->v53();
    return 1;
}

extern "C" FE_OVERLAY void fn_804AFFEC(FeScr* x)
{
    fn_800ECE34(x);
    x->m134 = (FeObj*)fn_800C8060(((FeObj*)x)->v32("CELL", 1));
}


extern "C" FE_OVERLAY int fn_804B0738(FeScr* x)
{
    ((FeObj1*)fn_800C805C(((FeObj*)((FeObjQ*)x->m134)->v70())->v32("SG", 1)))->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804B07B8(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjQ*)x->m134)->v70())->v32("SG", 1)))->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B0834(FeScr* x)
{
    ((FeObj1*)fn_800C805C(((FeObj*)((FeObjQ*)x->m134)->v70())->v32("SG", 1)))->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804B08B4(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjQ*)x->m134)->v70())->v32("SG", 1)))->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B0930(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjQ*)x->m134)->v70())->v32("SG", 1)))->v41();
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjQ*)x->m134)->v70())->v32("SG", 1)))->v39();
    ((FeObj*)x->m134)->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B0A68(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjQ*)x->m134)->v70())->v32("SG", 1)))->v41();
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjQ*)x->m134)->v70())->v32("SG", 1)))->v39();
    ((FeObj*)x->m134)->v52();
    return 1;
}

extern "C" FE_OVERLAY void fn_804B0F6C(FeScr* x)
{
    FeObj* c = fn_800C8060(((FeObj*)x)->v32("CELL", 1));
    x->m134 = (FeObj*)((FeObjI*)c)->v77();
    x->m138 = (FeObj*)((FeObjI*)c)->v75();
}

extern "C" FE_OVERLAY int fn_804B114C(FeScr* x)
{
    ((FeObj*)fn_800C8060(((FeObj*)x)->v32("FIRSTCELL", 1)))->v50();
    ((FeObj*)fn_800C8060(((FeObj*)x)->v32("CELL", 1)))->v50();
    return 0;
}

extern "C" FE_OVERLAY int fn_804B11F8(FeScr* x)
{
    ((FeObj*)fn_800C8060(((FeObj*)x)->v32("FIRSTCELL", 1)))->v51();
    ((FeObj*)fn_800C8060(((FeObj*)x)->v32("CELL", 1)))->v51();
    return 0;
}

extern "C" FE_OVERLAY int fn_804B12A4(FeScr* x)
{
    ((FeObj*)fn_800C8060(((FeObj*)x)->v32("FIRSTCELL", 1)))->v52();
    ((FeObj*)fn_800C8060(((FeObj*)x)->v32("CELL", 1)))->v52();
    return 0;
}

extern "C" FE_OVERLAY int fn_804B1350(FeScr* x)
{
    ((FeObj*)fn_800C8060(((FeObj*)x)->v32("FIRSTCELL", 1)))->v53();
    ((FeObj*)fn_800C8060(((FeObj*)x)->v32("CELL", 1)))->v53();
    return 0;
}

extern "C" FE_OVERLAY void fn_804AF1B8(char* p, int i, int a, int b)
{
    if (i > 9)
        return;
    int o = i * 8;
    char* b1 = p + 0x150;
    *(int*)(b1 + o) = a;
    char* b2 = p + 0x14C;
    *(int*)(b2 + o) = b;
}

extern "C" FE_OVERLAY void fn_804AFDA8(FeScr* x, int v)
{
    if (v == FI(x, 0x13C))
        fn_804AFCCC(x);
    else if (v == FI(x, 0x138))
        fn_804AF2A0(x);
}

extern "C" FE_OVERLAY void fn_804B04F8(FeScr* x)
{
    FI(x, 0x138) = 1;
}

extern "C" FE_OVERLAY void fn_804B0044(FeScr* x)
{
    fn_800ECF18(x);
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(p, x);
    ((FeFnOI)fn_80125154)(p, 0);
    ((FeFnOIII)fn_801251CC)(p, 0, 0x1A0A, 2);
    fn_804B00D8(x);
}

extern "C" FE_OVERLAY void fn_804AF1D8(FeScr* x, int a, int b)
{
    char buf[0x40];
    char buf2[8];
    if (a == 0) {
        fn_80403144(buf, fn_80090880(lbl_8061977C, 0xBBC));
    } else {
        fn_80329FA0(buf2, a);
        fn_800DD44C((int*)buf2, buf, 2);
    }
    ((FeObjS43*)x->m138)->v43(b, 1, buf, 5);
    ((FeObj3*)x->m138)->v92(b, 1, 1);
}

extern "C" FE_OVERLAY void fn_804B0504(int a, FeObj* w)
{
    if (a == 1)
        ((FeObj2*)w)->v67(1, 0);
}

extern "C" FE_OVERLAY void fn_804B0FF8(FeScr* x)
{
    FeObj* c = fn_800C8060(((FeObj*)x)->v32("CELL", 1));
    int r = ((FeObjI*)c)->v77();
    if (r != FI(x, 0x134)) {
        FeObj* d = fn_800C8060(((FeObj*)x)->v32("FIRSTCELL", 1));
        ((FeObj1*)d)->v78(r);
        ((FeObj1*)d)->v14(1);
        ((FeObj1*)d)->v14(0);
    }
}

extern "C" FE_OVERLAY void fn_804B03F8(FeScr* x)
{
    int i = 0;
    int n = ((FeObjI*)x->m134)->v59();
    int h = ((FeScrMgrView*)lbl_8061930C)->m2C;
    if (i < n) {
        int o = 0;
        do {
            FeObj* cell = (FeObj*)((FeObjP2*)x->m134)->v73(i, 1);
            FeHolder* p = (FeHolder*)fn_800C8058(cell->v32("TL", 1));
            char* b = (char*)x + 0x13C;
            int id = *(int*)(b + o);
            fn_805818C8(h, id, ((FeSub*)((char*)p + 0xDC))->s5() != 0);
            i++;
            o += 4;
        } while (i < n);
    }
}

extern "C" FE_OVERLAY void fn_804AFCCC(FeScr* x)
{
    if (FI(x->m140, 0x24) < 0) {
        int* sub = (int*)((char*)x + 0x19C);
        if (sub[1] != 0) {
            int idx = ((FeObjI*)x->m13C)->v60();
            int o = idx * 4;
            int id = *(int*)((char*)sub[0] + o);
            fn_80126CF4(x->m148, id, FI(x->m148, 0x168), FI(x->m148, 0x134), FI(x->m148, 0x16C), FI(x->m148, 0x170), 0, FI(x->m148, 0x138), FI(x->m148, 0x13C), FI(x->m148, 0x148), FI(x->m148, 0x14C));
            ((FeObj2*)x->m148)->v88(0, (unsigned)sub[1] > 1);
        }
    }
}

/* near-miss: retail keeps the first table word in r4 and loads vptr halfword first; 10 slots differ */
extern "C" FE_OVERLAY void fn_804AF2A0(FeScr* x)
{
    if (FI(x->m140, 0x24) >= 0) {
        int v27 = 0;
        int v29 = 0;
        int v28 = 0;
        int i8 = ((FeObjI*)x->m138)->v60() * 8;
        char* b1 = (char*)x + 0x150;
        int t = *(int*)(b1 + i8);
        int h = ((FeScrMgrView*)lbl_8061930C)->m2C;
        char* b2 = (char*)x + 0x14C;
        int id = *(int*)(b2 + i8);
        if (t != 0x10) {
            FeRec4* rec = ((FeV4*)fn_8058211C(h))->s11(id);
            if (FeNz1(rec) == 0) {
                if (rec->m4 != 0) {
                    v28 = 1;
                } else {
                    v27 = rec->m28;
                    v29 = 1;
                }
            }
        }
        if (v29 != 0) {
            if (v27 != 0) {
                ((FeFnOIII)fn_801251CC)(x->m134, 0, 0x1D0D, 2);
                return;
            }
            ((FeFnOIII)fn_801251CC)(x->m134, 0, 0x1D0D, 1);
            return;
        }
        if (v28 != 0) {
            ((FeFnOIII)fn_801251CC)(x->m134, 0, 0x1D13, 4);
            return;
        }
        fn_80125084(x->m134, 0);
    }
}
