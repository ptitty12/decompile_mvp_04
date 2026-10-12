/*
 * Front-end overlay code, .frontend_codeoverlay 0x804D2AC0-0x804D3E00 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_804D08D0.h"

extern "C" {
/* near-miss: store schedule only; retail hoists the lbl_8061A32C load and cmpwi above the m138/m158 stores (22 diff lines) */
FE_OVERLAY void* fn_804D2AC0(void* p, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, const char* l)
{
    FeBase2* self = (FeBase2*)p;
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m134 = i;
    self->SetVptr(lbl_80679EC0);
    self->m138 = j;
    self->m158 = (int*)l;
    self->m160 = 0;
    self->m168 = 5;
    self->m130 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = k;
    self->m154 = k;
    self->m15C = 0;
    self->m164 = 5;
    int heap = ((FeMgr38*)FeGetMgr())->m38;
    self->m15C = (FeItem**)fn_803774A8(k * 4, heap);
    int n = 0;
    if (n < k) {
        do {
            self->m15C[n] = fn_80521184(fn_805210A0(), self->m158[n]);
            n++;
        } while (n < self->m150);
    }
    return self;
}

FE_OVERLAY void fn_804D2BCC(FeBase2* self, int c)
{
    self->SetVptr(lbl_80679EC0);
    for (int i = 0; i < self->m150; i++) {
        delete self->m15C[i];
    }
    if (self->m15C != 0) {
        fn_80377488(self->m15C);
    }
    fn_805210A0();
    fn_805228DC();
    fn_8035686C(self, c);
}

FE_OVERLAY FeW* fn_804D2C7C(FeBase2* x)
{
    if (x->m144 == 0) {
        x->m144 = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1));
    }
    return x->m144;
}

FE_OVERLAY FeW* fn_804D2CE0(FeBase2* x)
{
    if (x->m148 == 0) {
        x->m148 = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    }
    return x->m148;
}

FE_OVERLAY FeW* fn_804D2D50(FeBase2* x)
{
    if (x->m14C == 0) {
        x->m14C = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    }
    return x->m14C;
}

FE_OVERLAY void fn_804D2DC0(void* p, int v)
{
    FeBase2* x = (FeBase2*)p;
    FeW* t = fn_800C8040(x->fn_vslot32(lbl_805F54F8, 1));
    const char* s = fn_80090880__FP11Unk80090880(lbl_8061977C, v);
    t->fn_vslot28(s);
    fn_800C8040(x->fn_vslot32(lbl_805F851C, 1))->fn_vslot28(s);
    fn_800DD204__FP3UiST0(t, fn_800C8038(x->fn_vslot32(lbl_805F7BBC, 1)));
}

FE_OVERLAY FeItem* fn_804D2EC0(FeBase2* x, int i)
{
    return x->m15C[i];
}

FE_OVERLAY FeItem* fn_804D2ED0(FeBase2* x, int id)
{
    for (int i = 0; i < x->m154; i++) {
        FeItem* it = fn_804D2EC0(x, i);
        if (it->m4 == id) {
            return it;
        }
    }
    return 0;
}

FE_OVERLAY void fn_804D2F38(FeBase2* x)
{
    for (int i = 0; i < x->m154;) {
        FeItem* it = fn_804D2EC0(x, i);
        i++;
        it->s6();
    }
}

FE_OVERLAY void fn_804D2F9C(FeBase2* x)
{
    for (int i = 0; i < x->m154;) {
        FeItem* it = fn_804D2EC0(x, i);
        i++;
        it->s7();
    }
}

FE_OVERLAY void fn_804D3000(FeBase2* x)
{
    void* saved = lbl_80622648;
    lbl_80622648 = fn_8007FE04((Unk8007F198_D*)lbl_8061930C);
    fn_804D2F38(x);
    lbl_80622648 = saved;
}

FE_OVERLAY void fn_804D304C(FeBase2* x)
{
    void* saved = lbl_80622648;
    lbl_80622648 = fn_8007FE04((Unk8007F198_D*)lbl_8061930C);
    fn_804D2F9C(x);
    lbl_80622648 = saved;
}

FE_OVERLAY void fn_804D3098(FeBase2* x)
{
    for (int i = 0; i < x->m154; i++) {
        fn_804D2EC0(x, i)->m0 = i;
    }
    for (int i = 0; i < x->m154;) {
        FeItem* it = fn_804D2EC0(x, i);
        i++;
        it->s8();
    }
}

FE_OVERLAY void fn_804D312C(FeBase2* x)
{
    fn_800ECE34(x);
    fn_804D3CA8(x, 0);
}

FE_OVERLAY void fn_804D3164(void* p)
{
    FeBase2* x = (FeBase2*)p;
    fn_800ECF18(x);
    fn_804D2C7C(x);
    fn_804D2CE0(x);
    fn_804D2D50(x);
    fn_804D2C7C(x)->fn_vslot79(x->m154, 0);
    fn_804D2C7C(x)->fn_vslot3();
    lbl_80622644 = fn_804D2C7C(x);
    fn_804D3098(x);
    if (((FeStateB*)fn_800B555C())->m4 & 0x400) {
        lbl_80622648 = lbl_806192E0->m4->m10;
        fn_804D2F38(x);
    } else {
        fn_804D3000(x);
        lbl_80622648 = lbl_806192E0->m4->m10;
    }
    fn_80124FA8(fn_804D2CE0(x), x);
    fn_80125180(fn_804D2CE0(x), 1, 0x1A0B);
    fn_80125180(fn_804D2CE0(x), 0, 0x1FE1);
    x->m16C = 0;
    x->m170 = 0;
}

FE_OVERLAY int fn_804D32A0(void* p)
{
    FeBase2* x = (FeBase2*)p;
    int a; /* r4 passes through (second parameter not declared in fe_80459228.h) */
    if (fn_804D3B18(x, a) == 1) {
        fn_804D2F9C(x);
        if (((FeStateB*)fn_800B555C())->m4 & 0x200) {
            fn_804D304C(x);
        }
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

FE_OVERLAY int fn_804D3328(FeBase2* x, int a)
{
    if (fn_804D3B18(x, a) != 0) {
        if (x->m134 != 0 && x->m140 != 0) {
            FeW* pop = fn_804D2D50(x);
            fn_80131F34(pop, x, fn_804D3570, (int)fn_80528FB4, x->m138, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
            fn_804D2D50(x)->fn_vslot86();
        } else {
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, lbl_805F4450, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
        }
    }
    return 1;
}

FE_OVERLAY void fn_804D344C(FeBase2* x, int a)
{
    fn_800ED310(x, a);
    fn_804D2C7C(x)->fn_vslot14(a);
}

FE_OVERLAY void fn_804D34A0(FeBase2* x, int id, int v)
{
    for (int i = 0; i < x->m154; i++) {
        if (fn_8051F51C(fn_804D2EC0(x, i)) == id) {
            FeItem* it = fn_804D2EC0(x, i);
            it->s10(v);
            it->s9();
            ((FeWY*)x)->s85(i);
            x->m140 = 1;
        }
    }
}

FE_OVERLAY void fn_804D3570(int a, void* p)
{
    FeBase2* x = (FeBase2*)p;
    if (a != 0) {
        if (a == 1) {
            ((FeWX*)x)->s84();
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, lbl_805F4450, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
        }
    }
}

FE_OVERLAY int fn_804D361C(FeBase2* x, int a)
{
    if (fn_804D3B18(x, a) != 0) {
        fn_804D2C7C(x)->fn_vslot50();
    }
    return 1;
}

FE_OVERLAY int fn_804D3674(FeBase2* x, int a)
{
    if (fn_804D3B18(x, a) != 0) {
        fn_804D2C7C(x)->fn_vslot51();
    }
    return 1;
}

FE_OVERLAY int fn_804D36CC(FeBase2* x, int a)
{
    if (fn_804D3B18(x, a) != 0) {
        fn_804D2C7C(x)->fn_vslot52();
    }
    return 1;
}

FE_OVERLAY int fn_804D3724(FeBase2* x, int a)
{
    if (fn_804D3B18(x, a) != 0) {
        fn_804D2C7C(x)->fn_vslot53();
    }
    return 1;
}

FE_OVERLAY int fn_804D377C(FeBase2* x, int a)
{
    if (fn_804D3B18(x, a) != 0 && fn_804D3B48(x, a) != 0) {
        FeW* w = fn_800C8044(fn_804D2C7C(x)->fn_vslot70());
        fn_800C805C(w->fn_vslot32(lbl_805F7944, 1))->fn_vslot40(1);
    }
    return 1;
}

FE_OVERLAY int fn_804D3834(FeBase2* x, int a)
{
    if (fn_804D3B18(x, a) != 0 && fn_804D3B48(x, a) != 0) {
        FeW* w = fn_800C8044(fn_804D2C7C(x)->fn_vslot70());
        ((FeWX*)fn_800C805C(w->fn_vslot32(lbl_805F7944, 1)))->s41();
    }
    return 1;
}

FE_OVERLAY int fn_804D38E8(FeBase2* x, int a)
{
    if (fn_804D3B18(x, a) != 0 && fn_804D3B48(x, a) != 0) {
        FeW* w = fn_800C8044(fn_804D2C7C(x)->fn_vslot70());
        fn_800C805C(w->fn_vslot32(lbl_805F7944, 1))->fn_vslot38(1);
    }
    return 1;
}

FE_OVERLAY int fn_804D39A0(FeBase2* x, int a)
{
    if (fn_804D3B18(x, a) != 0 && fn_804D3B48(x, a) != 0) {
        FeW* w = fn_800C8044(fn_804D2C7C(x)->fn_vslot70());
        ((FeWX*)fn_800C805C(w->fn_vslot32(lbl_805F7944, 1)))->s39();
    }
    return 1;
}

FE_OVERLAY int fn_804D3A54(FeBase2* x, int a)
{
    int i = 0;
    FeW* w = fn_800C8044(fn_804D2C7C(x)->fn_vslot70());
    for (; i < x->m154; i++) {
        FeItem* it = fn_804D2EC0(x, i);
        if (fn_8051F42C(it) == w) {
            for (int j = 0x2B; j < 0x2F; j++) {
                if (it->m4 == j && a != j - 0x2B) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

FE_OVERLAY int fn_804D3B18(FeBase2* x, int a)
{
    if (x->m160 != 0 && a != x->m168 && a != x->m164) {
        return 0;
    }
    return 1;
}

FE_OVERLAY int fn_804D3B48(FeBase2* x, int a)
{
    int r;
    if (x->m13C == 0 || x->fn_vslot86() != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

FE_OVERLAY void fn_804D3BA0(FeBase2* x)
{
    x->m16C = x->m16C + 1;
    if (x->m16C > 0x14) {
        ((FeWY*)x)->s88();
    }
}

FE_OVERLAY void fn_804D3BEC(FeBase2* x)
{
    for (int j = 0x2B; j <= 0x2E; j++) {
        int k = j - 0x2B;
        if (fn_802D7CE0(k, 0) == 0 || fn_802D7D64__Fi(k) == 0) {
            fn_8051F42C(fn_804D2ED0(x, j))->fn_vslot16(0);
        } else {
            fn_8051F42C(fn_804D2ED0(x, j))->fn_vslot16(1);
        }
    }
}

FE_OVERLAY FeW* fn_804D3CA8(FeBase2* x, int a)
{
    FeW* w = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F852C);
    if (w != 0) {
        w = fn_801389A4(w, a);
    }
    x->m160 = a;
    if (a != 0) {
        FeG10* g = lbl_806192E0->m4->m10;
        x->m168 = g->m6C;
        x->m164 = g->m70;
    } else {
        x->m168 = 5;
        x->m164 = 5;
    }
    return w;
}

FE_OVERLAY void fn_804D3D54(FeScrD* x)
{
    fn_804D3164(x);
}

FE_OVERLAY FeS804D3D74* fn_804D3D74(FeS804D3D74* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC594__FP8UiScrRawiiiiiiii(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067FA30);
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    return self;
}

FE_OVERLAY void fn_804D3DD0(FeS804D3D74* x)
{
    x->SetVptr(lbl_8067FA30);
    fn_800EC5F4__FP8UiScrRaw(x);
}
}
