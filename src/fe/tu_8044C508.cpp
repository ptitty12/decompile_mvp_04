/*
 * Front-end overlay code, .frontend_codeoverlay 0x8044C508-0x8044F550 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

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

extern "C" FE_OVERLAY void fn_8044DA44(FeScr5* self)
{
    fn_804454CC(self);
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
