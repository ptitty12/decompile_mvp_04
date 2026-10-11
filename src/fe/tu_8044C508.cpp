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

extern "C" FE_OVERLAY void fn_8044E768(void)
{
    fn_80445DA8((FeScr2*)fn_800B7A94(UiGetMsgMgr(), "GAMECALENDAR"));
}

extern "C" FE_OVERLAY int fn_8044E7C4(void)
{
    ((FeObj1*)fn_800B7A94(UiGetMsgMgr(), "GAMECALENDAR"))->v14(1);
    return 1;
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
