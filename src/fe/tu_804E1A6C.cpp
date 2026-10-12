/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E1A6C-0x804E5180 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

struct Unk8007F198_D;
struct FeRetA {
    char pad0[0xA];
    unsigned short mA;
};
FeRetA* fn_8007FE04(Unk8007F198_D* g);

extern "C" FE_OVERLAY int fn_804E1A6C(FeMask* self)
{
    FeObjK* o = (FeObjK*)self->m184;
    ((FeObj1*)fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1)))->v15(0);
    ((FeObjK*)self->m184)->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1B34(FeWf184* self)
{
    self->m184->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1B70(FeMask* self)
{
    FeObjK* o = (FeObjK*)self->m184;
    ((FeObj1*)fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1)))->v15(0);
    ((FeObjK*)self->m184)->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1C38(FeWf184* self)
{
    self->m184->v53();
    return 1;
}

extern "C" FE_OVERLAY void fn_804E1C74(FeMask* self)
{
    int v = ((FeObjK*)self->m184)->v60();
    if (v >= 0) {
        fn_804E26E4(self, v);
        ((FeObj1*)self->m184)->v14(1);
    }
}

extern "C" FE_OVERLAY int fn_804E1CEC(FeMask* self)
{
    ((FeObjK*)self->m184)->v69(1);
    FeObjK* o = (FeObjK*)self->m184;
    ((FeObj1*)fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1)))->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1DB8(FeMask* self)
{
    ((FeObjK*)self->m184)->v69(1);
    FeObjK* o = (FeObjK*)self->m184;
    fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1))->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1E80(FeMask* self)
{
    ((FeObjK*)self->m184)->v69(1);
    FeObjK* o = (FeObjK*)self->m184;
    ((FeObj1*)fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1)))->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1F4C(FeMask* self)
{
    ((FeObjK*)self->m184)->v69(1);
    FeObjK* o = (FeObjK*)self->m184;
    fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1))->v39();
    return 1;
}

extern "C" FE_OVERLAY void fn_804E2014(FeMask* self)
{
    for (unsigned i = 0; i <= 8; i++)
        fn_8005B87C(fn_8005ACE4(), i, fn_804E2274(self, self->m18A, i));
}

extern "C" FE_OVERLAY void fn_804E2074(int a, FeMask* self)
{
    if (a == 1) {
        fn_804E2014(self);
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
}

extern "C" FE_OVERLAY int fn_804E2108(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804E2110(FeMask* self, int sel)
{
    switch (sel) {
    case 0: {
        FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
        if (self->m180 != 0) {
            fn_80131F34(p, self, (FeCb)fn_804E2074, fn_804E2108, 0x3364, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
            p->v86();
        } else {
            fn_804E2074(1, self);
        }
        break;
    }
    case 1: {
        fn_8007FE04((Unk8007F198_D*)lbl_8061930C)->mA = self->m188;
        UiMsg m;
        UiMsg* mp = &m;
        fn_8035682C(mp);
        fn_8040B830(mp->name, "BACK", 15);
        mp->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), mp, self);
        break;
    }
    }
}

extern "C" FE_OVERLAY int fn_804E2274(void* self, int v, int i)
{
    return (v >> i) & 1;
}

extern "C" FE_OVERLAY void fn_804E2280(FeMask* self, int idx)
{
    FeObj1* w = (FeObj1*)fn_800C805C(((FeObjQ*)((FeObjK*)self->m184)->v73(idx, 2))->v33(11, 1));
    w->v37(fn_804E2274(self, self->m188, idx) == 0);
}

extern "C" FE_OVERLAY void fn_804E26E4(FeMask* self, int idx)
{
    self->m188 ^= 1 << idx;
    fn_8005B87C(fn_8005ACE4(), idx, fn_804E2274(self, self->m188, idx));
    fn_804E2280(self, idx);
    fn_8001BC4C()->fn_8001BDAC(0xA3);
}

extern "C" FE_OVERLAY void fn_804E2764(FeMask* self)
{
    fn_804E1C74(self);
    self->m180 = 1;
}

extern char lbl_8066B238[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E2798(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066B238;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_804E2B14(FeS3* self)
{
    self->m138->v50();
    fn_804E3174(self, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2B68(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2BA4(FeS3* self)
{
    self->m138->v52();
    fn_804E3174(self, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2BF8(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2C34(FeS3* self)
{
    if (fn_804EAF54(((FeGameB*)lbl_80619948)->m64) > 1) {
        ((FeObjS2*)self->m13C)->v56();
        do {
            self->m144--;
            if (self->m144 < 0)
                self->m144 = 3;
        } while (FeKeyAt((char*)((FeGameB*)lbl_80619948)->m64 + 4, self->m144 * 0x4F4) == 0);
        fn_804E3174(self, 1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2CE0(FeWf13C* self)
{
    self->m13C->v57();
    return 0;
}

extern "C" FE_OVERLAY int fn_804E2D1C(FeS3* self)
{
    if (fn_804EAF54(((FeGameB*)lbl_80619948)->m64) > 1) {
        ((FeObjS2*)self->m13C)->v54();
        do {
            self->m144++;
            if (self->m144 >= 4)
                self->m144 = 0;
        } while (FeKeyAt((char*)((FeGameB*)lbl_80619948)->m64 + 4, self->m144 * 0x4F4) == 0);
        fn_804E3174(self, 1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2DC4(FeWf13C* self)
{
    self->m13C->v55();
    return 0;
}

extern "C" FE_OVERLAY int fn_804E2F28(FeS3* self, FeObjR* a, int b, int c)
{
    if ((FeObj*)a == self->m138) {
        a->v68(c);
        return 1;
    } else
        return 0;
}

extern "C" FE_OVERLAY void fn_804E3154(void* self, int a)
{
    fn_800ECAA4(self);
}

extern char lbl_8066C778[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E378C(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066C778;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = -1;
    return self;
}

extern "C" FE_OVERLAY void fn_804E3B08(FeS3* self)
{
    fn_800ECAA4(self);
    int v = ((FeObjK*)self->m13C)->v77();
    if (v != self->m14C) {
        self->m14C = v;
        fn_804E46B8(self);
    }
}

extern "C" FE_OVERLAY int fn_804E3B68(FeObj* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3BF0(FeS3* self)
{
    fn_804E46B8(self);
    self->m13C->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3C3C(FeWf13C* self)
{
    self->m13C->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3C78(FeS3* self)
{
    fn_804E46B8(self);
    self->m13C->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3CC4(FeWf13C* self)
{
    self->m13C->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3D00(FeWf140b* self)
{
    self->m140->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3D40(FeWf140* self)
{
    self->m140->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3D7C(FeWf140b* self)
{
    self->m140->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3DBC(FeWf140* self)
{
    self->m140->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3DF8(FeS3* self, FeObjR* a, int b, int c)
{
    if ((FeObj*)a == self->m13C) {
        a->v68(c);
        return 1;
    } else
        return 0;
}

extern "C" FE_OVERLAY void fn_804E3E4C(FeS3* self, FeObj* a)
{
    if (a == self->m140) {
        FeObj* c = fn_800C8058(a->v32("CATEGORY", 1));
        FeSub* sb = (FeSub*)((char*)c + 0xDC);
        self->m148 = sb->s11();
        fn_800C33D0();
        fn_800C3BE0();
        fn_800C3AB4(fn_800C33D0(), 9);
        self->m150 = -1;
        fn_804E3EF8(self);
        fn_804E46B8(self);
    }
}

extern "C" FE_OVERLAY int fn_804E4694(void* self, unsigned idx)
{
    if (idx > 0x67)
        return 6;
    return lbl_805F9DEC[idx];
}
