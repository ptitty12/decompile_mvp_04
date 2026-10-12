/*
 * Front-end overlay code, .frontend_codeoverlay 0x80508C98-0x8050C9DC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

extern const char lbl_80668118[];
extern "C" void fn_80556348(void* p);
extern int lbl_8061AC54;
extern const char lbl_80668668[];
extern const char lbl_805F4F8C[];
extern "C" void fn_802BA708__FP11Unk802B9F40(void* p);
extern "C" void fn_80083E84__FiPiT1(int a, int* b, int* c);
extern "C" int fn_8057CE00(int v);
extern "C" void fn_8050AE0C(FeScrQ* x, int a, int b, int c);
extern char* lbl_8061E978;
extern "C" void fn_8050A9F0(void* x);
extern const char lbl_805FB738[];
extern const char lbl_805FB744[];
extern const char lbl_805FB750[];
extern const char lbl_805F4EF4[];
extern const char lbl_805F4450[];
extern "C" FeScrQ* fn_80508C98(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80508CF8(FeScrN* x);
extern "C" void fn_80508FBC(FeScrD* x);
extern "C" void fn_8050A4A8(void* x, int a);
extern "C" int fn_8050A4FC(FeScrN* x);
extern "C" int fn_8050A570(FeScrN* x);
extern "C" int fn_8050A5E4(FeScrN* x);
extern "C" int fn_8050A658(FeScrN* x);
extern "C" int fn_8050A6CC(FeScrN* x);
extern "C" int fn_8050A72C(FeScrN* x);
extern "C" int fn_8050A78C(FeScrN* x);
extern "C" int fn_8050A7EC(FeScrN* x);
extern "C" int fn_8050A84C(FeScrQ* x, FeW* w, int b, int n);
extern "C" void fn_8050A8DC(void* x, int v);
extern "C" int fn_8050A8E0(void);
extern "C" void fn_8050A8E8();
extern "C" void fn_8050A8EC(void* x);
extern "C" void fn_8050A970(void* p);
extern "C" FeRecList* fn_8050AB58(FeRecList* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_8050BED4(FeScrD* x);
extern "C" int fn_8050BFC0(FeScrN* x);
extern "C" int fn_8050C000(FeScrN* x, int a);
extern "C" int fn_8050C03C(FeScrN* x);
extern "C" int fn_8050C07C(FeScrN* x);
extern "C" int fn_8050C0B8(FeScrN* x);
extern "C" int fn_8050C0F4(FeScrN* x);
extern "C" int fn_8050C130(FeScrN* x);
extern "C" int fn_8050C16C(FeScrN* x);
extern "C" int fn_8050C1A8(FeScrN* x);
extern "C" int fn_8050C1E4(FeScrN* x);
extern "C" int fn_8050C220(FeScrN* x);
extern "C" int fn_8050C25C(FeScrN* x);
extern "C" FeW* fn_8050C380(FeScrN* x, int idx);
extern "C" FeW* fn_8050C408(FeScrN* x);
extern "C" int fn_8050C42C(FeRecList* x, int id);
extern "C" void fn_8050C68C(FeScrQ* x, int id);

extern "C" FE_OVERLAY FeScrQ* fn_80508C98(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80668668);
    self->m130 = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m154 = -1;
    self->m158 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80508CF8(FeScrN* x)
{
    fn_800ECE34(x);
    x->m140 = (FeW*)fn_800B7AB8(FeGetMgr(), lbl_805F4F8C);
}

extern "C" FE_OVERLAY void fn_80508FBC(FeScrD* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY void fn_8050A4A8(void* x, int a)
{
    switch (a) {
    case 0:
        fn_8050A8EC(x);
        break;
    case 1:
        fn_8050A970(x);
        break;
    case 2:
        fn_8050A9F0(x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_8050A4FC(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot56();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A570(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot57();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A5E4(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot54();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A658(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot55();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A6CC(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A72C(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A78C(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A7EC(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A84C(FeScrQ* x, FeW* w, int b, int n)
{
    if (w == (FeW*)x->m134) {
        if (n > 0) {
            w->fn_vslot68(n);
            x->fn_vslot67(2, fn_800C8070(x));
        }
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_8050A8DC(void* x, int v)
{
}

extern "C" FE_OVERLAY int fn_8050A8E0(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_8050A8E8()
{
}

extern "C" FE_OVERLAY void fn_8050A8EC(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F4450, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY void fn_8050A970(void* p)
{
    FeScrN* x = (FeScrN*)p;
    int r = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot61();
    fn_8050A8DC(x, r);
    fn_8001BC4C()->fn_8001BDAC(0xA3);
}

extern "C" FE_OVERLAY FeRecList* fn_8050AB58(FeRecList* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    FeRec28* p = self->m14C;
    int i = 11;
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80668118);
    self->m130 = 0;
    ((FeScrQ*)self)->m134 = 0;
    ((FeScrQ*)self)->m138 = 0;
    ((FeScrQ*)self)->m13C = 0;
    ((FeScrQ*)self)->m140 = 0;
    ((FeScrQ*)self)->m144 = 0;
    self->m148 = 0;
    do {
        fn_80556348(p);
        p++;
    } while (i-- != 0);
    int one = 1;
    lbl_8061AC54 = one;
    return self;
}

extern "C" FE_OVERLAY void fn_8050BED4(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_8050BFC0(FeScrN* x)
{
    x->m13C->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C000(FeScrN* x, int a)
{
    x->m13C->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C03C(FeScrN* x)
{
    x->m13C->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C07C(FeScrN* x)
{
    x->m13C->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C0B8(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C0F4(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C130(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C16C(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C1A8(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C1E4(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C220(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C25C(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY FeW* fn_8050C380(FeScrN* x, int idx)
{
    if (idx == 0) {
        return fn_800C8060(x->fn_vslot32(lbl_805FB738, 1));
    }
    if (idx == 1) {
        return fn_800C8060(x->fn_vslot32(lbl_805FB744, 1));
    }
    if (idx == 2) {
        return fn_800C8060(x->fn_vslot32(lbl_805FB750, 1));
    }
    return 0;
}

extern "C" FE_OVERLAY FeW* fn_8050C408(FeScrN* x)
{
    return fn_8050C380(x, (int)x->m134);
}

int fn_80084114(int v);
/* near-miss: retail walks a pointer (r3 += 0x28) with n in r11 and i in r9; ours keeps the pointer in r9 and n in r10; 6 variants tried */
extern "C" FE_OVERLAY int fn_8050C42C(FeRecList* x, int id)
{
    int idx = 0;
    if (fn_80084114(id) != 0) {
        int n = x->m148;
        FeRec28* p = x->m14C;
        for (int i = 0; i < n; i++) {
            if (p->m0 == id) {
                idx = i;
                break;
            }
            p++;
        }
    }
    return idx;
}

extern "C" FE_OVERLAY void fn_8050C68C(FeScrQ* x, int id)
{
    fn_802BA708__FP11Unk802B9F40(lbl_8061E978 + 0xFAB0);
    int a = 0;
    int b = 0;
    fn_80083E84__FiPiT1(id, &a, &b);
    int t = fn_8057CE00(id) > 2 ? 2 : fn_8057CE00(id);
    x->m134 = t;
    fn_8050AE0C(x, t, 0, a);
}
