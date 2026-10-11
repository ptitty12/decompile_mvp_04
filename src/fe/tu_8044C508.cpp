/*
 * Front-end overlay code, .frontend_codeoverlay 0x8044C508-0x8044F550 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern "C" FE_OVERLAY int fn_8044C508(FeScr_8044974C* self, int a)
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
    fn_801321D4(p, self, (FeCb)fn_8044C644, 0, buf, 3, -1, 1, s1, s2, s3, 0, 0, 0);
    p->v86();
    return 0;
}

extern "C" FE_OVERLAY void fn_8044C644(int a, FeScr_8044974C* self)
{
    if (a != 0) {
        if (a == 1) {
            if (lbl_8061930C->fn_80075948(self->m244) == 0)
                fn_8055F5A0(self->m244);
            else
                fn_8055EAFC(self->m244);
            fn_8044B79C(self);
            fn_8044B050(self);
            fn_8044ADA4(self);
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

/*
 * Front-end overlay code, .frontend_codeoverlay 0x8044C508-0x8044F550 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

extern "C" void fn_80444890(FeX24* self);
extern "C" FE_OVERLAY void fn_8044C77C(FeX24* self)
{
    ((FeObj1*)self->m24)->v8(0);
    fn_80444890(self);
}

extern "C" FE_OVERLAY void fn_8044D270(FeS0_8* self)
{
    FeObj* c = fn_800C8044(self->m0->v32("CONTENTS", 1));
    if (self->m8 == 0) {
        ((FeObj1*)c->v32("OPPONENT", 1))->v8(1);
        ((FeObj1*)c->v32("BACKING", 1))->v8(1);
    } else {
        ((FeObj1*)c->v32("OPPONENT", 1))->v8(0);
        ((FeObj1*)c->v32("BACKING", 1))->v8(0);
    }
}

extern "C" FE_OVERLAY void fn_8044D3D8(FeX14* self)
{
    int v = lbl_8061930C->fn_80078A38(lbl_8062163C);
    fn_8007FDA8((Unk8007F198_C*)lbl_8061930C, self->m14, v);
}

extern "C" FE_OVERLAY void fn_8044D9E0(FeScr5* self)
{
    fn_800ECAA4(self);
    if (fn_80446AD4(self)->m8 == -1)
        fn_80125084(self->m170, 0);
    else
        fn_801251CC(self->m170, 0, 0x10, -1);
}

extern "C" FE_OVERLAY void fn_8044DA44(FeScr5* self, int a)
{
    fn_804454CC(self, a);
    ((FeObj1*)self->m16C)->v14(0);
}

extern "C" FE_OVERLAY void fn_8044DA90(FeScr5* self)
{
    char it[4];
    char* p = it;
    fn_804455B4(self);
    Unk8007F198_B* sc = (Unk8007F198_B*)lbl_8061930C;
    ((FeSub*)&self->m168->m98)->s15();
    Unk8007F198_B* tm = fn_8007F7D0(sc, 0);
    fn_804CDFE4(p);
    fn_804CDFF8(p, 0, tm);
    int v = fn_804CE004(p);
    if (v != 0) {
        do {
            ((FeSub1*)&self->m168->m98)->s18(v);
            ((FeSub1*)&self->m16C->mDC)->s18(v);
            v = fn_804CE038(p);
        } while (v != 0);
    }
    FeSub1* s1 = (FeSub1*)&self->m168->m98;
    s1->s8(self->m14C);
    FeSub1* s2 = (FeSub1*)&self->m16C->mDC;
    s2->s8(self->m14C);
}

extern "C" FE_OVERLAY void* fn_8044DBC0(char* base, int idx)
{
    int r = idx / 7;
    return base + (r * 0x118 + 0x174) + (idx - r * 7) * 0x28;
}

extern "C" FE_OVERLAY void* fn_8044DC00(char* base, int a, int b)
{
    return base + (a * 0x118 + 0x174) + b * 0x28;
}

extern "C" FE_OVERLAY void fn_8044DC18(FeScr5* self)
{
    FeObj* month = fn_800C8040(((FeObj*)self)->v32("MONTH", 1));
    ((FeObj1*)month)->v29(fn_800DD5E8(self->m144));
    fn_8044DDFC(self);
    fn_8044DCAC(self, self->m14C);
}

extern "C" FE_OVERLAY void fn_8044DCAC(FeScr5* self, int a)
{
    char buf[0x38];
    if (fn_800A2E90(lbl_80619948) != 0) {
        int x = lbl_8061930C->fn_80078A38(a);
        int y = lbl_8061930C->fn_8007B8C4(1, a);
        fn_804089B4(buf, "%.1f", fn_80574A04(fn_800A3A10(lbl_80619948, x), y, a));
        ((FeObj1*)fn_800C8040((void*)((FeObjP1*)self)->v29((int)"RIGHTSIDE/GB")))->v30((int)buf);
    } else {
        ((FeObj1*)((FeObjP1*)self)->v29((int)"RIGHTSIDE/GB"))->v8(0);
        ((FeObj1*)((FeObjP1*)self)->v29((int)"RIGHTSIDE/GBTXT"))->v8(0);
    }
}

extern "C" FE_OVERLAY void fn_8044DDFC(FeScr5* self)
{
    char buf[0x18];
    int a = 0;
    int b = 0;
    fn_8056AF84(lbl_80619948->m28, self->m14C, self->m144, &a, &b);
    fn_80403DE4(buf, fn_80090880(lbl_8061977C, 0x2335), a, b);
    ((FeObj1*)fn_800C8040(fn_800C8044(((FeObj*)self)->v32("RIGHTSIDE", 1))->v32("WLNUMBER", 1)))->v28((int)buf);
}

extern "C" FE_OVERLAY void fn_8044DEE4(FeScr5* self, int a)
{
    FeSub1* s = (FeSub1*)&self->m168->m98;
    s->s8(a);
    FeSub1* t = (FeSub1*)&self->m16C->mDC;
    t->s8(a);
    fn_8044DCAC(self, a);
}

extern "C" FE_OVERLAY void fn_8044DF60(FeScr5* self, FeRec8* r)
{
    char db[6];
    if (r->m8 != -1) {
        int c = 0;
        int sid = lbl_8061930C->fn_80078A38(self->m14C);
        *(int*)db = r->mC;
        int x = fn_80329E74((int*)db);
        if (r->m8 != 0) {
            *(int*)db = r->mC;
            if (fn_8044E08C((int)self, (unsigned*)db) == 0) {
                if (x == fn_800A2AE8(lbl_80619948) && fn_8056AB84(lbl_80619948->m28, x, sid) != 0)
                    c = 1;
            }
        }
        if (c != 0) {
            fn_8044E210(self, 0);
            return;
        }
        int cnt = fn_8007FB2C((Unk8007F198_C*)lbl_8061930C, sid);
        int w = fn_8007FBC0((Unk8007F198_C*)lbl_8061930C, cnt - 1, sid);
        if (r->m8 == 3 && x > w) {
            fn_8044E10C(self, sid, w);
            return;
        }
        fn_8044E210(self, 1);
    }
}

extern "C" FE_OVERLAY int fn_8044E08C(int a, unsigned* p)
{
    unsigned v = *p;
    unsigned char d[4];
    fn_80329FA0(d, fn_800A2AE8(lbl_80619948));
    unsigned hi = v >> 24;
    if (hi > d[0])
        return 0;
    if (hi == d[0] && ((v >> 16) & 0xFF) >= d[1])
        return 0;
    return 1;
}

extern "C" FE_OVERLAY void fn_8044E10C(FeScr5* self, int x, int y)
{
    char b20[0x40];
    char b60[0xC8];
    int d[2];
    Unk80090880* tbl = lbl_8061977C;
    fn_80329FA0(d, y);
    fn_800DD44C(d, b20, 2);
    const char* s1 = fn_80090880(tbl, 0x4634);
    fn_8040321C(b60, s1, fn_80090880(tbl, fn_80083F6C(x)), b20);
    FeObj* o = self->m140;
    fn_801321D4(o, self, (FeCb)fn_805288E4, 0, b60, 1, -1, 1, fn_80090880(tbl, 0x26DE), 0, 0, 0, 0, 0);
    self->m140->v86();
}

/* near-miss: same calls; retail loads self->m140 into r3 for the final v86 vcall and orders the stack-arg stores differently (18 slots) */
extern "C" FE_OVERLAY void fn_8044E210(FeScr5* self, int a)
{
    if (a != 0) {
        fn_80131F34(self->m140, self, (FeCb)fn_8044E304, fn_8044E7C4, 0, 4, -1, 1, 0x1903, 0x1906, 0x1902, 0x26DF, 0, 0);
    } else {
        fn_80131F34(self->m140, self, (FeCb)fn_8044E398, fn_8044E7C4, 0, 2, -1, 1, 0x1903, 0x26DF, 0, 0, 0, 0);
        self->m140->v86();
    }
}

extern "C" FE_OVERLAY void fn_8044E304(int a, FeObj* o)
{
    switch (a) {
    case 0:
        ((FeObj2*)o)->v67(0, 0);
        break;
    case 1:
        ((FeObj2*)o)->v67(1, 0);
        break;
    case 2:
        ((FeObj2*)o)->v67(2, 0);
        break;
    }
}

extern "C" FE_OVERLAY void fn_8044E398(int a, FeObj* o)
{
    if (a == 0)
        ((FeObj2*)o)->v67(0, 0);
}

extern "C" FE_OVERLAY void fn_8044E5EC(void)
{
    UiMsg m;
    FeObj* cal = fn_800B7AB8(UiGetMsgMgr(), "GAMECALENDAR");
    UiMsg* p = &m;
    ((FeObj1*)cal)->v80(1);
    fn_8035682C(p);
    if (fn_800A2EB4(lbl_80619948) != 0) {
        if (fn_805562B8(fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0)) != 0) {
            fn_8040B830(p->name, "WINNER", 15);
            p->name[15] = 0;
        } else {
            fn_8040B830(p->name, "PLAYOFFEND", 15);
            p->name[15] = 0;
        }
    } else if (fn_800A2E6C(lbl_80619948) != 0) {
        fn_8040B830(p->name, "SPRINGEND", 15);
        p->name[15] = 0;
    } else if (fn_800B56C4(fn_800B555C()) != 0) {
        fn_8040B830(p->name, "SEASONEND", 15);
        p->name[15] = 0;
    } else {
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
    }
    fn_800B7B4C(UiGetMsgMgr(), &m, cal);
}

extern "C" FE_OVERLAY void fn_8044E768(void)
{
    fn_80445DA8((FeScr2*)fn_800B7A94(UiGetMsgMgr(), "GAMECALENDAR"));
}

extern "C" FE_OVERLAY int fn_8044E7C4(void)
{
    ((FeObj1*)fn_800B7A94(UiGetMsgMgr(), "GAMECALENDAR"))->v14(1);
    return 1;
}

extern "C" FE_OVERLAY void fn_8044E83C(FeScr2* self, int a, int b)
{
    if (fn_800B5758(fn_800B555C()) != 0) {
        if (a == 0) {
            fn_801251CC(self->m170, 2, 0x170E, 3);
            ((FeObj1*)self->m6EC)->v8(1);
            ((FeObj1*)self->m6F0)->v8(1);
            ((FeObj1*)self->m6F4)->v8(1);
            ((FeObj1*)self->m6F8)->v8(1);
        } else {
            fn_80125084(self->m170, 2);
            ((FeObj1*)self->m6EC)->v8(0);
            ((FeObj1*)self->m6F0)->v8(0);
            ((FeObj1*)self->m6F4)->v8(0);
            ((FeObj1*)self->m6F8)->v8(0);
        }
    }
    fn_80445564(self, a, b);
}

extern "C" FE_OVERLAY void fn_8044E9B8(FeScr2* self, int k)
{
    int d;
    switch (k) {
    case 0: {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "VIEWDAYSGAMES", 15);
        p->name[15] = 0;
        FeTimer* t = fn_80446AD4(self);
        fn_800B555C()->m14 = *(int*)&t->mC;
        ((FeObj*)self)->v40();
        ((FeObj1*)self)->v80(1);
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
        break;
    }
    case 1: {
        d = *(int*)&fn_80446AD4(self)->mC;
        int x = fn_80329E74(&d);
        fn_80470404(self->m164, x, 1, 0, 0, 0);
        break;
    }
    case 2: {
        d = *(int*)&fn_80446AD4(self)->mC;
        int x = fn_80329E74(&d);
        fn_80470478(self->m164, x, 1, 0, 0, 1);
        break;
    }
    case 3: {
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        lbl_80621644 = lbl_80621644 ^ 1;
        int id = 0x170E;
        if (lbl_80621644 != 0) {
            id = 0x170F;
        }
        fn_801251CC(self->m170, 2, id, 3);
        fn_80445DA8(self);
        break;
    }
    default:
        fn_80446B60(self, k);
        break;
    }
}

/*
 * Front-end overlay code, .frontend_codeoverlay 0x8044C508-0x8044F550 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */


extern char lbl_8067C5D0[];
extern "C" FE_OVERLAY FeScrRaw* fn_8044EB7C(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067C5D0;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_8044F0D4(FeW138* self)
{
    self->m138->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044F110(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044F14C(FeW138* self)
{
    self->m138->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044F188(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY void fn_8044F1C4(void* self)
{
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, self, (FeCb)fn_8044F284, 0, 0x46B1, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_8044F284(int a, void* b)
{
    if (a != 0) {
        if (a == 1) {
            if (lbl_80619948->m80 == 0x12) {
                fn_8044F45C((int)b);
            } else {
                UiMsg m;
                UiMsg* p = &m;
                fn_8035682C(p);
                fn_8040B830(p->name, "DONE", 15);
                p->name[15] = 0;
                fn_800B7B4C(UiGetMsgMgr(), &m, b);
            }
        }
    }
}

extern "C" FE_OVERLAY void fn_8044F338(void* self)
{
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, self, (FeCb)fn_8044F3F8, 0, 0x4844, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    p->v86();
}

extern "C" FE_OVERLAY void fn_8044F3F8(int a, int b)
{
    if (a != 0) {
        if (a == 1) {
            fn_80560A24(fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0));
            fn_800A2F9C(lbl_80619948, 0);
            fn_8044F4CC((void*)b);
        }
    }
}

extern "C" FE_OVERLAY void fn_8044F45C(int self)
{
    fn_80449168((FeMeter*)fn_800B7AB8(UiGetMsgMgr(), "AUTOCOMPLETE"), 0x12, self, (void (*)(int))fn_8044F4CC);
}

extern "C" FE_OVERLAY void fn_8044F4CC(void* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "DONE", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), &m, self);
}
