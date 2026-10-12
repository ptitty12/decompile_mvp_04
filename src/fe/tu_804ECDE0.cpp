/*
 * Front-end overlay code, .frontend_codeoverlay 0x804ECDE0-0x804F81E0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

extern char lbl_8067F178[];

extern "C" FE_OVERLAY FeScrRaw* fn_804ECDE0(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067F178;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804ECE2C(FeWf134* self)
{
    fn_800ECF18(self);
    self->m134 = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(self->m134, self);
    fn_80125154(self->m134, 0);
}

extern "C" FE_OVERLAY void fn_804ECEA8(FeObj* self, int a)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    if (a == 0) {
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
}

extern "C" FE_OVERLAY void fn_804F4B2C(void* self, FeHolder* o)
{
    ((FeSubB*)&o->mDC)->s15();
    ((FeObj2*)o)->v51(0x35C, 0);
    ((FeSubB*)&o->mDC)->s6(0);
}

extern "C" FE_OVERLAY int fn_804F7C80(int a, FeObj1* self)
{
    if (a != 0) {
        self->v80(1);
        fn_800B7ADC(UiGetMsgMgr(), self);
    }
}

extern "C" FE_OVERLAY int fn_804F7CFC(FeS17* self)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    lbl_8061D384 = lbl_806221F8;
    lbl_8061D388 = lbl_806221FC;
    int id = 0x3A97;
    if (self->m630 != 1)
        id = 0x3A6E;
    fn_80131F34(p, self, (FeCb)fn_804F7C80, fn_805283F4, id, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->v86();
    return 1;
}

extern "C" FE_OVERLAY int fn_804F7DF8(FeWf604b* self)
{
    self->m604->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804F7E38(FeWf604* self)
{
    self->m604->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804F7E74(FeWf604b* self)
{
    self->m604->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804F7EB4(FeWf604* self)
{
    self->m604->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804F7EF0(FeS17* self)
{
    fn_804FC260(self);
    if (self->m618 != 0)
        self->m618->v50();
    FeSub* sb = (FeSub*)((char*)fn_800C8058(((FeObjQ*)self->m604)->v33(10, 1)) + 0xDC);
    if ((unsigned)(sb->s5() - 6) <= 1)
        fn_804FBF58(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804F7F9C(FeWf618* self)
{
    if (self->m618 != 0)
        self->m618->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804F7FE0(FeS17* self)
{
    fn_804FC260(self);
    if (self->m618 != 0)
        self->m618->v52();
    FeSub* sb = (FeSub*)((char*)fn_800C8058(((FeObjQ*)self->m604)->v33(10, 1)) + 0xDC);
    if ((unsigned)(sb->s5() - 6) <= 1)
        fn_804FBF58(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804F808C(FeWf618* self)
{
    if (self->m618 != 0)
        self->m618->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804F80D0(FeWf618* self)
{
    if (self->m618 != 0)
        self->m618->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804F8114(FeWf618* self)
{
    if (self->m618 != 0)
        self->m618->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804F8158(FeWf618* self)
{
    if (self->m618 != 0)
        self->m618->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804F819C(FeWf618* self)
{
    if (self->m618 != 0)
        self->m618->v55();
    return 1;
}
