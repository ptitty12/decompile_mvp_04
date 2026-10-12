/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E5180-0x804E750C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

extern char lbl_8066C4D0[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E5180(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066C4D0;
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_804E5518(FeScr_80447264* self)
{
    self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E5554(FeScr_80447264* self)
{
    self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E5590(FeScr_80447264* self)
{
    self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E55CC(FeScr_80447264* self)
{
    self->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E58BC(FeObj* self)
{
    ((FeObj2*)self)->v67(1, fn_800C8070(self));
    return 1;
}

extern "C" FE_OVERLAY void fn_804E5914(void)
{
    fn_800E25E0((int)fn_800B7A94(UiGetMsgMgr(), "NAVBAR"), 0);
}

extern char lbl_8066C228[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E5974(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066C228;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_804E5EFC(FeS5* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    switch (((FeObjK*)self->m138)->v61()) {
    case 0:
        fn_8040B830(p->name, "CREDITS", 15);
        p->name[15] = 0;
        break;
    case 1:
        fn_8040B830(p->name, "TEAMS", 15);
        p->name[15] = 0;
        break;
    case 2:
        fn_8040B830(p->name, "PLAYERS", 15);
        p->name[15] = 0;
        break;
    case 3:
        fn_8040B830(p->name, "JERSEYS", 15);
        p->name[15] = 0;
        break;
    case 4:
        fn_8040B830(p->name, "STADIUMS", 15);
        p->name[15] = 0;
        break;
    default:
        return 0;
    }
    fn_800B7B4C(UiGetMsgMgr(), &m, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E6030(FeObj* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E60B8(FeWf138* self)
{
    self->m138->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E60F4(FeWf138* self)
{
    self->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E6130(FeWf138* self)
{
    self->m138->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E616C(FeWf138* self)
{
    self->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E61A8(FeWf138* self)
{
    self->m138->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E61E4(FeWf138* self)
{
    self->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E6220(FeWf138* self)
{
    self->m138->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E625C(FeWf138* self)
{
    self->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E6298(FeObj* self)
{
    ((FeObj1*)self)->v41(fn_800C8070(self));
    return 1;
}

extern "C" FE_OVERLAY void fn_804E62EC(FeS5* self)
{
    int v = ((FeObjK*)self->m138)->v61();
    if (self->m13C != v) {
        self->m13C = v;
        for (int i = 1; i <= 4; i++) {
            ((FeObj1*)((FeObjQ*)((FeObjK*)self->m138)->v73(0, i))->v32("UNLOCKED", 1))->v8(i == self->m13C);
        }
    }
}

extern char lbl_8066BF80[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E63C0(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066BF80;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E6428(FeS6* self)
{
    fn_800ECE34(self);
    fn_800C3AB4(fn_800C33D0(), 9);
    self->m134 = fn_800C8044(self->v32("USER", 1));
    self->m138 = fn_800C805C(self->v32("SPIN", 1));
    self->m13C = fn_800C8058(self->m138->v32("TROPHY", 1));
    self->m140 = fn_800C8040(self->v32("DESCRIPTION", 1));
    self->m144 = fn_800C8038(self->v32("TROPHY", 1));
    self->m148 = fn_800C8044(self->v32("HISTORY", 1));
    self->m14C = fn_800C8044(self->v32("TOTAL", 1));
}

extern "C" FE_OVERLAY int fn_804E687C(FeObj* self)
{
    fn_800C33D0();
    fn_800C3BE0();
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E690C(FeWf138b* self)
{
    self->m138->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E694C(FeWf138* self)
{
    self->m138->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E6988(FeWf138b* self)
{
    self->m138->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E69C8(FeWf138* self)
{
    self->m138->v39();
    return 1;
}

extern "C" FE_OVERLAY void fn_804E6A04(FeS4* self)
{
    FeHolder* h = (FeHolder*)self->m13C;
    self->m154 = ((FeSub*)&h->mDC)->s11();
    fn_804E6A58(self);
}

extern char lbl_8066BCD8[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E7218(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066BCD8;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = -1;
    self->m140 = 0;
    self->m144 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E7278(FeScrRaw* self, int chrg)
{
    self->m3C = lbl_8066BCD8;
    fn_8035686C(self, chrg);
}
