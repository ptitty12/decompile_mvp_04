/*
 * Front-end overlay code, .frontend_codeoverlay 0x80452120-0x80455038 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

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
