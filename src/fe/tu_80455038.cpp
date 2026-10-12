/*
 * Front-end overlay code, .frontend_codeoverlay 0x80455038-0x80459228 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern char lbl_8067B860[];
extern "C" FE_OVERLAY FeScr8Raw* fn_80455038(FeScr8Raw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    int i;
    fn_800EC648((FeScrRaw*)self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067B860;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m1C0 = 0;
    self->m1C4 = 0;
    self->m1C8 = 0;
    self->m1CC = -1;
    self->m1D0 = 0;
    for (i = 0; i < 10; i++) {
        self->m148[i] = 0;
        self->m170[i] = 0;
    }
    return self;
}

extern "C" FE_OVERLAY void fn_80455CFC(FeScr8* self)
{
    lbl_80621678 = self->m140;
}

extern "C" FE_OVERLAY void fn_80455D0C(FeScr8* self)
{
    fn_800ECAA4(self);
    FeObj* nb = fn_800B7A94(UiGetMsgMgr(), "NAVBAR");
    if (self->m1CC == -1 && self->m198[self->m140] != 0)
        fn_80125084(nb, 0);
    else
        fn_801250D8(nb);
}

extern "C" FE_OVERLAY int fn_80455DA0(FeScr8* self)
{
    fn_80457010(self, 1, 1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80455DCC(FeScr8* self)
{
    if (self->m1CC == -1)
        self->m140 = 0;
    fn_80457010(self, 2, 1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80455E0C(FeScr8* self, FeRec1C* rec)
{
    if (rec->m1C == 14) {
        int i;
        for (i = 0; i <= 9; i++) {
            if ((void*)self->m148[i]->v32("FC2", 0) == (void*)rec) {
                self->m140 = i;
                fn_80456A00(self, i);
                return 1;
            }
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80456110(FeScr8* self)
{
    if (self->m1CC == -1) {
        int t = self->m140;
        if (t != 0 && t != 3 && t != 5 && t != 8) {
            self->m140 = t == 0 ? 9 : t - 1;
            fn_80456A00(self, self->m140);
            fn_8001BC4C()->fn_8001BDAC(0x99);
            return 1;
        }
    }
    return 0;
}

/* near-miss: retail copies self to r11 at entry (mr r11,r3); ours keeps it in r3 (1 slot, 5 spellings tried) */
extern "C" FE_OVERLAY int fn_8045618C(FeScr8* self)
{
    if (self->m1CC == -1) {
        int t = self->m140;
        if (t != 2 && t != 4 && t != 7 && t != 9) {
            int n = t + 1;
            self->m140 = n;
            fn_80456A00(self, n);
            fn_8001BC4C()->fn_8001BDAC(0x9A);
            return 1;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804564A0(FeScr8* self)
{
    if (self->m1CC != -1) {
        FeObj* o = fn_800C8060(self->m1C0->v32("PLAYERGRID", 1));
        if (o->m24 >= 0) {
            FeObj* bat = fn_800C8060(self->m1C0->v32("BATTING", 1));
            o = fn_800C8060(self->m1C0->v32("PITCHING", 1));
            if (bat->m24 < 0) {
                bat->v51();
                return 1;
            }
            if (o->m24 >= 0)
                return 0;
        }
        o->v51();
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80456858(FeScr8* self)
{
    if (self->m1CC != -1) {
        FeObj* o = fn_800C8060(self->m1C0->v32("PLAYERGRID", 1));
        if (o->m24 >= 0) {
            FeObj* bat = fn_800C8060(self->m1C0->v32("BATTING", 1));
            o = fn_800C8060(self->m1C0->v32("PITCHING", 1));
            if (bat->m24 < 0) {
                bat->v53();
                return 1;
            }
            if (o->m24 >= 0)
                return 0;
        }
        o->v53();
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80456978(FeScr8* self, int a, int b)
{
    fn_80456D6C(self, b);
    FeObj* g = fn_800C8060(self->m1C0->v32("PLAYERGRID", 1));
    if (g->m24 < 0)
        ((FeObj1*)g)->v68(0);
}

extern "C" FE_OVERLAY void fn_80456F94(FeScr8* self)
{
    unsigned i;
    for (i = 0; i <= 9; i++) {
        fn_80457B94(self, FeGetI((char*)&self->m170, i * 4), i, 3, 1);
        ((FeObj1*)self->m170[i])->v14(0);
    }
}

extern "C" FE_OVERLAY int fn_80458200(int a, int b)
{
    switch (b) {
    case 0:
        return 6;
    case 1:
        return 7;
    case 2:
        return 8;
    case 3:
        return 5;
    case 4:
        return 3;
    case 5:
        return 4;
    case 6:
        return 0;
    case 7:
        return 2;
    case 8:
        return 1;
    case 9:
        return 10;
    default:
        return 14;
    }
}

/*
 * Front-end overlay code, .frontend_codeoverlay 0x80455038-0x80459228 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

extern "C" void fn_800ECAA4(void* self);
extern "C" FE_OVERLAY void fn_8045899C(void* self)
{
    fn_800ECAA4(self);
}

extern "C" FE_OVERLAY void fn_804589BC(void* s)
{
    FeScr8b* self = (FeScr8b*)s;
    FeObj** bot = &self->m13C[2];
    ((FeObj1*)self->m13C[0])->v14(0);
    ((FeObj1*)self->m13C[1])->v14(0);
    ((FeObj1*)self->m13C[self->m14C])->v14(1);
    ((FeObj1*)bot[self->m14C])->v44(1);
    int k = fn_8045A9AC(self, self->m14C);
    ((FeObj1*)FeGetP((char*)bot, k * 4))->v44(0);
}

extern "C" FE_OVERLAY void fn_80458AAC(FeScr8b* self, int a)
{
    self->m14C = a;
    fn_804589BC(self);
}

extern "C" FE_OVERLAY void fn_80458AD0(FeScr8b* self)
{
    FeObj** a = self->m13C;
    if (((FeObjI*)a[self->m14C])->v61() != 1)
        ((FeObj1*)a[self->m14C])->v69(1);
    fn_80459FEC(self);
}

extern "C" FE_OVERLAY void fn_80458B58(FeScr8b* self, int a)
{
    if (a != -1)
        fn_80458BA4(self, a);
    fn_8045AB6C(self);
    fn_8045AC2C(self);
    fn_804589BC(self);
}

extern "C" FE_OVERLAY void fn_80458FD4(void)
{
}

extern "C" FE_OVERLAY int fn_80458FD8(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80458FE0(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80458FE8(void* s, FeObj* a, int unused, int c)
{
    FeScr8b* self = (FeScr8b*)s;
    fn_8045AF68(self, 2);
    if (a == self->m13C[1]) {
        fn_80458AAC(self, 1);
        if (self->m158 == -1 && self->m154 == -1)
            goto L0A4;
        if (self->m154 == c)
            ((FeObj2*)self)->v67(1, fn_800C8070(self));
    } else if (a == self->m13C[0]) {
        fn_80458AAC(self, 0);
        if (self->m158 == -1 && self->m154 == -1) {
        L0A4:
            ((FeObj2*)self)->v67(0, fn_800C8070(self));
        } else if (self->m158 == c)
            ((FeObj2*)self)->v67(1, fn_800C8070(self));
    }
    fn_804589BC(self);
    return 0;
}

extern "C" FE_OVERLAY int fn_80459130(void* s, FeObj* a, int unused, int c)
{
    FeScr8b* self = (FeScr8b*)s;
    if (a == self->m13C[1]) {
        fn_80458AAC(self, 1);
        ((FeObj1*)a)->v68(c);
        ((FeObj1*)self)->v44(fn_800C8070(self));
    } else if (a == self->m13C[0]) {
        fn_80458AAC(self, 0);
        ((FeObj1*)a)->v68(c);
        ((FeObj1*)self)->v44(fn_800C8070(self));
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80459224(void)
{
}
