/*
 * Front-end overlay code, .frontend_codeoverlay 0x80452120-0x80455038 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern char lbl_8067BB08[];
extern "C" FE_OVERLAY FeScr7Raw* fn_80452120(FeScr7Raw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648((FeScrRaw*)self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067BB08;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m16C = -1;
    self->m170 = -1;
    self->m23C = 0;
    self->m240 = 1;
    return self;
}

extern "C" FE_OVERLAY int fn_80452CD4(FeScr7* self)
{
    if (fn_80454D9C(self) != 0)
        return 0;
    int k = ((FeObjI*)self->m168)->v60();
    if (self->m168 == self->m13C)
        fn_80454890(self, k);
    else if (self->m168 == self->m140)
        fn_8045499C(self, k);
    return 1;
}

extern "C" int fn_80454E18(FeScr_8044974C* self, int a);
extern "C" FE_OVERLAY int fn_80452D64(FeScr_8044974C* self)
{
    Unk8007B2B0_Screen* s = lbl_8061930C;
    int sid;
    if (fn_800A2EFC(lbl_80619948) != 0
        || (fn_80454E18(self, self->m134) != 0
            && ((sid = s->fn_80075948(self->m134), s->fn_8007B3E0(0xE, sid) == 0)
                || (fn_80454E18(self, self->m134) != 0 && fn_80454E18(self, s->fn_8007B320(0, sid)) != 0
                    && fn_80454E18(self, s->fn_8007B320(1, sid)) != 0
                    && fn_80454E18(self, s->fn_8007B320(2, sid)) != 0
                    && fn_80454E18(self, s->fn_8007B320(3, sid)) != 0)))) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80452EE8(FeScr7* self)
{
    if (self->m1DC[24] == 0 || fn_80454D9C(self) == 1)
        return 0;
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    ((FeSub*)&self->m154->mDC)->s1();
    fn_80453F20(self, ((FeSub*)&self->m154->mDC)->s5());
    fn_80453980(self);
    return 1;
}

/*
 * Front-end overlay code, .frontend_codeoverlay 0x80452120-0x80455038 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

extern "C" void fn_80453980(FeScr_8044974C* self);
extern "C" FE_OVERLAY int fn_8045327C(FeScr_8044974C* self)
{
    self->m168->v50();
    fn_80453980(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804532CC(FeScr_8044974C* self)
{
    self->m168->v51();
    return 1;
}

extern "C" void fn_80453980(FeScr_8044974C* self);
extern "C" FE_OVERLAY int fn_80453308(FeScr_8044974C* self)
{
    self->m168->v52();
    fn_80453980(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_80453358(FeScr_8044974C* self)
{
    self->m168->v53();
    return 1;
}

extern "C" void fn_80453FD4(FeScr_8044974C* self, FeObj* a);
extern "C" void fn_80453980(FeScr_8044974C* self);
extern "C" FE_OVERLAY int fn_80453394(FeScr_8044974C* self)
{
    if (self->m168 != self->m13C)
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    fn_80453FD4(self, self->m13C);
    fn_80453980(self);
    return 0;
}

extern "C" FE_OVERLAY int fn_804533F0(FeScr7* self)
{
    if (self->m168 != self->m140)
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    fn_80453FD4(self, self->m140);
    fn_80453980(self);
    return 0;
}

extern "C" FE_OVERLAY int fn_8045344C(FeScr_8044974C* self)
{
    ((FeObj1*)self->m144)->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8045348C(FeScr_8044974C* self)
{
    self->m144->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804534C8(FeScr_8044974C* self)
{
    ((FeObj1*)self->m144)->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80453508(FeScr_8044974C* self)
{
    self->m144->v39();
    return 1;
}

extern "C" void fn_8045369C(FeScr_8044974C* self);
extern "C" void fn_80453980(FeScr_8044974C* self);
extern "C" FE_OVERLAY int fn_80453544(FeScr_8044974C* self)
{
    ((FeObj1*)self->m148)->v40(1);
    fn_8045369C(self);
    fn_80453980(self);
    return 1;
}

extern "C" void fn_8045369C(FeScr_8044974C* self);
extern "C" FE_OVERLAY int fn_804535A0(FeScr_8044974C* self)
{
    self->m148->v41();
    fn_8045369C(self);
    return 1;
}

extern "C" void fn_8045369C(FeScr_8044974C* self);
extern "C" void fn_80453980(FeScr_8044974C* self);
extern "C" FE_OVERLAY int fn_804535F0(FeScr_8044974C* self)
{
    ((FeObj1*)self->m148)->v38(1);
    fn_8045369C(self);
    fn_80453980(self);
    return 1;
}

extern "C" void fn_8045369C(FeScr_8044974C* self);
extern "C" FE_OVERLAY int fn_8045364C(FeScr_8044974C* self)
{
    self->m148->v39();
    fn_8045369C(self);
    return 1;
}

extern "C" FE_OVERLAY void fn_8045369C(FeScr7* self)
{
    int v = ((FeSub*)&self->m158->mDC)->s5();
    fn_800D0074(&self->m14C->m98, v, 1);
    fn_800D0074(&self->m150->mDC, v, 1);
    fn_80453D84(self, ((FeSub*)&self->m14C->m98)->s21());
}

extern "C" void fn_80453D84(FeScr_8044974C* self, int a);
extern "C" void fn_80453980(FeScr_8044974C* self);
extern "C" FE_OVERLAY void fn_80453BA8(FeScr_8044974C* self, int a, int b)
{
    fn_80453D84(self, b);
    fn_80453980(self);
}

extern "C" void fn_80454890(FeScr_8044974C* self, int a);
extern "C" void fn_80453FD4(FeScr_8044974C* self, FeObj* a);
extern "C" void fn_8045499C(FeScr_8044974C* self, int a);
extern "C" void fn_80453980(FeScr_8044974C* self);
extern "C" FE_OVERLAY int fn_80453BE0(FeScr_8044974C* self, FeObj* a, int unused, int b)
{
    if (a == self->m13C) {
        int t = self->m16C;
        if ((t == -1 && self->m170 == -1) || t == b)
            fn_80454890(self, b);
        fn_80453FD4(self, self->m13C);
    } else if (a == self->m140) {
        if (self->m16C == -1)
            fn_8045499C(self, b);
        fn_80453FD4(self, self->m140);
    }
    fn_80453980(self);
    return 0;
}

extern "C" void fn_80453FD4(FeScr_8044974C* self, FeObj* a);
extern "C" void fn_80453980(FeScr_8044974C* self);
extern "C" FE_OVERLAY int fn_80453C8C(FeScr_8044974C* self, FeObj* a, int unused, int b)
{
    if (a == self->m13C) {
        fn_80453FD4(self, a);
        ((FeObj1*)a)->v68(b);
        ((FeObj1*)self)->v44(fn_800C8070(self));
    } else if (a == self->m140) {
        fn_80453FD4(self, a);
        ((FeObj1*)a)->v68(b);
        ((FeObj1*)self)->v44(fn_800C8070(self));
    }
    fn_80453980(self);
    return 0;
}

extern "C" FE_OVERLAY void fn_80453F20(FeScr7* self, int a)
{
    self->m138 = a;
    ((FeSub*)&self->m154->mDC)->s6();
    fn_804540CC(self);
    ((FeObj1*)self->m168)->v68(0);
    ((FeObj1*)self->m13C)->v14(0);
    ((FeObj1*)self->m140)->v14(0);
}

extern "C" void fn_8045373C(FeScr_8044974C* self);
extern "C" FE_OVERLAY void fn_80453FD4(FeScr_8044974C* self, FeObj* a)
{
    ((FeObj1*)self->m13C)->v14(0);
    ((FeObj1*)self->m140)->v14(0);
    self->m168 = a;
    ((FeObj1*)a)->v14(1);
    if (a == self->m13C)
        ((FeObj2*)self->m160)->v84(0, 0);
    else if (a == self->m140)
        ((FeObj2*)self->m160)->v84(1, 0);
    fn_8045373C(self);
}

extern "C" FE_OVERLAY void fn_80454890(FeScr7* self, int a)
{
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    if (self->m16C == -1) {
        if (self->m170 == -1) {
            self->m16C = a;
            ((FeObj3*)self->m13C)->v90(a, 1, 1);
        } else {
            fn_80454AE0(self, a, self->m170);
        }
    } else if (a == self->m16C) {
        ((FeObj3*)self->m13C)->v90(a, 1, 0);
        self->m16C = -1;
    } else {
        ((FeObj3*)self->m13C)->v90(self->m16C, 1, 0);
        fn_80454BB0(self, a, self->m16C);
        self->m16C = -1;
        fn_804540CC(self);
    }
}

/* near-miss: retail indexes the 0x1D8 table with the byte offset in r0 (slwi r0; lwzx r0,r9,r0); ours puts the offset in r11 (6 slots) */
extern "C" FE_OVERLAY void fn_8045499C(FeScr7* self, int a)
{
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    int t = self->m170;
    if (t == -1) {
        if (self->m16C == -1) {
            if (FeGetI((char*)self + 0x1D8, a * 4) != 0) {
                self->m170 = a;
                ((FeObj3*)self->m140)->v90(a, 1, 1);
            }
        } else {
            if (FeGetI((char*)self + 0x1D8, a * 4) != 0)
                fn_80454AE0(self, self->m16C, a);
        }
    } else if (a == t) {
        ((FeObj3*)self->m140)->v90(a, 1, 0);
        self->m170 = -1;
    } else {
        ((FeObj3*)self->m140)->v90(t, 1, 0);
        self->m170 = a;
        ((FeObj3*)self->m140)->v90(a, 1, 1);
    }
}

extern "C" FE_OVERLAY void fn_80454AE0(FeScr7* self, int a, int b)
{
    int x = FeGetI((char*)lbl_80621650, a * 4);
    Unk8007DB74_A* s = (Unk8007DB74_A*)lbl_8061930C;
    int y = FeGetI((char*)self + 0x1D8, b * 4);
    if (x != 0) {
        ((FeObj3*)self->m13C)->v90(self->m16C, 1, 0);
        ((FeObj3*)self->m140)->v90(self->m16C, 1, 0);
        fn_8007DD38(s, self->m134, self->m138, x, y);
        self->m16C = -1;
        self->m170 = -1;
        fn_804540CC(self);
    }
}

extern "C" FE_OVERLAY int fn_80454CFC(FeScr_8044974C* self)
{
    if (self->m168 == self->m13C) {
        if (((FeObjI*)self->m160)->v86() != 0)
            return 1;
    }
    if (self->m168 == self->m140) {
        if (((FeObjI*)self->m160)->v87() != 0)
            return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80454D9C(FeScr_8044974C* self)
{
    int r = 0;
    if (((FeObjI*)self->m160)->v86() != 0 || ((FeObjI*)self->m160)->v87() != 0)
        r = 1;
    return r;
}

extern "C" void fn_80454F54(int a, FeScr_8044974C* self);
extern "C" FE_OVERLAY int fn_80454E18(FeScr_8044974C* self, int a)
{
    char buf[0x7D0];
    if (fn_8007F3A0((Unk8007F198_A*)lbl_8061930C, a) != 4)
        return 1;
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "POPUP");
    fn_800E4234(a, 4, buf);
    fn_800DFF0C(buf, (char*)fn_80090880(lbl_8061977C, 0x4F40));
    self->m244 = a;
    const char* s1 = fn_80090880(lbl_8061977C, 0x4558);
    const char* s2 = fn_80090880(lbl_8061977C, 0x4DA6);
    const char* s3 = fn_80090880(lbl_8061977C, 0x4F41);
    fn_801321D4(p, self, (FeCb)fn_80454F54, 0, buf, 3, -1, 1, s1, s2, s3, 0, 0, 0);
    p->v86();
    return 0;
}

extern "C" void fn_804540CC(FeScr_8044974C* self);
extern "C" FE_OVERLAY void fn_80454F54(int a, FeScr_8044974C* self)
{
    if (a != 0) {
        if (a == 1) {
            if (lbl_8061930C->fn_80075948(self->m244) == 0)
                fn_8055F5A0(self->m244);
            else
                fn_8055EAFC(self->m244);
            fn_804540CC(self);
            fn_80453980(self);
            fn_8045373C(self);
        } else if (a == 2) {
            UiMsg m;
            UiMsg* p = &m;
            fn_8035682C(p);
            fn_8040B830(p->name, "BACK", 15);
            p->name[15] = 0;
            fn_800B7B4C(UiGetMsgMgr(), &m, self);
        }
    }
}
