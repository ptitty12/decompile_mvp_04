/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C713C-0x804C931C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

struct Unk8007F198_B;
int fn_8007F7D0(Unk8007F198_B* b, unsigned i);
int fn_8009047C(int a, int b);
extern "C" void fn_80125154(void* w, int a);
extern "C" int fn_804C7F30(FeScrN* x);
class FeVt18 {
public:
    char pad0[0x18];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
};
extern "C" void fn_800A2F9C(FeGlobal80619948* g, int a);

extern "C" void fn_804C81A0(FeScrN* x);
extern const char lbl_805F8060[];
extern const char lbl_805F806C[];
extern const char lbl_8066F378[];
extern "C" void fn_804C7ACC(FeScrN* x);
extern "C" void fn_804C7FE4(FeScrN* x);
extern "C" void fn_804C8354(void* x);
extern "C" void fn_804C86E8(void* x);
extern "C" void fn_804C87F0(void* x);
extern "C" void fn_804C7724(FeScrN* x);
extern "C" void fn_804C7744(FeScrN* x);
extern "C" int fn_804C77C0(FeScrN* x);
extern "C" int fn_804C77FC(FeScrN* x);
extern "C" int fn_804C7838(FeScrN* x);
extern "C" int fn_804C7874(FeScrN* x);
extern "C" int fn_804C78B0(void);
extern "C" int fn_804C78B8(void);
extern "C" int fn_804C78C0(void);
extern "C" int fn_804C78C8(void);
extern "C" int fn_804C78D0(FeScrN* x, int a);
extern "C" int fn_804C7900(FeScrN* x, FeW* w, int c, int d);
extern "C" void fn_804C794C(FeScrN* x);
extern "C" void fn_804C796C(FeScrN* x);
extern "C" void fn_804C7990(FeScrJ* x, int a);
extern "C" void fn_804C85BC();
extern "C" void fn_804C8634();
extern "C" void fn_804C92B0(FeScrN* x);
extern "C" FeScrH* fn_804C92D0(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804C8314(FeScrN* x, int a);
extern "C" void fn_804C776C(void* x, int a);
extern "C" int fn_804C713C(FeScrN* x, int a);

extern "C" FE_OVERLAY int fn_804C713C(FeScrN* x, int a)
{
    if (x->m138 != 0 && x->m134 == 0 && x->m13C == 0) {
        x->fn_vslot67(4, a);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804C7724(FeScrN* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_804C7744(FeScrN* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804C776C(void* x, int a)
{
    switch (a) {
    case 0:
        fn_804C8354(x);
        break;
    case 1:
        fn_804C86E8(x);
        break;
    case 2:
        fn_804C87F0(x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_804C77C0(FeScrN* x)
{
    x->m138->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C77FC(FeScrN* x)
{
    x->m138->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C7838(FeScrN* x)
{
    x->m138->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C7874(FeScrN* x)
{
    x->m138->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C78B0(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78B8(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78C0(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78C8(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_804C78D0(FeScrN* x, int a)
{
    if (a == (int)x->m138) {
        fn_804C92B0((FeScrN*)x);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804C7900(FeScrN* x, FeW* w, int c, int d)
{
    if ((int)w == (int)x->m138) {
        w->fn_vslot68(d);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804C794C(FeScrN* x)
{
    fn_804C92B0(x);
}

extern "C" FE_OVERLAY void fn_804C796C(FeScrN* x)
{
    fn_804C81A0(x);
}

extern "C" FE_OVERLAY void fn_804C798C(void) {}

extern "C" FE_OVERLAY void fn_804C7990(FeScrJ* x, int a)
{
    fn_800ED310(x, a);
    x->m138->fn_vslot14(a);
}

extern "C" FE_OVERLAY int fn_804C7F30(FeScrN* x)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int h = fn_8007F7D0((Unk8007F198_B*)s, 0);
    volatile int sp8 = 0;
    int i = 0;
    do {
        int a = fn_8008FE14(i);
        int b = fn_8008FD78(*(int*)&sp8);
        int r = s->fn_8007B380(a, h);
        if (r != 0 && fn_8009047C(b, r) == 0)
            return 1;
        int c = sp8;
        int t;
        if (c > 9)
            t = c;
        else
            t = c + 1;
        sp8 = t;
        i = t;
    } while (i <= 9);
    return 0;
}

extern "C" FE_OVERLAY void fn_804C81A0(FeScrN* x)
{
    if (fn_804C7F30(x) != 0)
        fn_80125084(x->m140, 1);
    else
        fn_80125154(x->m140, 0);
    if (fn_800B555C()->m0 == 0x13) {
        fn_801251CC(x->m140, 2, 0x4DA2, 2);
        return;
    }
    fn_801251CC(x->m140, 0, 0x5B06, 1);
}

extern "C" FE_OVERLAY void fn_804C8314(FeScrN* x, int a)
{
    if (a == (int)x->m160) {
        fn_804C7ACC(x);
        fn_804C7FE4(x);
    }
}

extern "C" FE_OVERLAY void fn_804C8544(int a, void* x)
{
    if (a != 0) {
        if (a == 1) {
            fn_800A2F9C(lbl_80619948, 1);
            ((FeVt18*)lbl_80619948)->s5();
            fn_800B555C()->m3C = 0;
            ((void (*)(void*))fn_804C85BC)(x);
        }
    }
}

extern "C" FE_OVERLAY void fn_804C85BC()
{
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F522C);
    p->m30C = (void*)fn_804C8634;
    fn_8049ABD4(p);
}

extern "C" FE_OVERLAY void fn_804C8634()
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F8060);
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F806C, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, p);
}

extern const char lbl_805F5B3C[];

extern "C" FE_OVERLAY void fn_804C87F0(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F5B3C, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY void fn_804C92B0(FeScrN* x)
{
    fn_804C7FE4(x);
}

extern "C" FE_OVERLAY FeScrH* fn_804C92D0(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066F378);
    self->m130 = 0;
    return self;
}
