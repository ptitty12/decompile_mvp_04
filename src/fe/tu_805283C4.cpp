/*
 * Front-end overlay code, .frontend_codeoverlay 0x805283C4-0x80528B78 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"

extern const char lbl_8064A550[];
extern const char lbl_8067ADC0[];

extern int lbl_80621640;
extern const char lbl_80655BA8[];
extern const char lbl_80655E98[];
extern const char lbl_8067CEB0[];
extern const char lbl_8067DF58[];
extern const char lbl_8067E5A0[];

extern const char lbl_80681F30[];
extern const char lbl_80680C08[];
extern const char lbl_806800B0[];
extern "C" void fn_800EC5F4__FP8UiScrRaw(void* self);
extern const char lbl_8067EED0[];
extern const char lbl_8067EBE8[];
extern "C" void fn_800EC1B8(void* self);
extern const char lbl_8067E8A8[];
extern const char lbl_8067E260[];
extern const char lbl_8067D478[];
extern const char lbl_8067CBD0[];
extern const char lbl_8067C058[];
extern "C" void fn_80360B60(void* self);
extern const char lbl_8067BDB0[];
extern const char lbl_8067B5B8[];
extern "C" void fn_8044C7CC(void* x, int k, int a);
extern const char lbl_806827B0[];
extern "C" void fn_80377408(void* p);
extern "C" void fn_805283C4(FeScrN* self);
extern "C" int fn_805283F4(void);
extern "C" int fn_80528400(FeScrN* x, int i);
extern "C" void fn_8052841C(FeScrN* self);
extern "C" int fn_80528450(void);
extern "C" void fn_8052846C(FeScrN* self);
extern "C" int fn_805284E4(void* x);
extern "C" void fn_805284EC(FeScrN* self);
extern "C" int fn_8052851C(void);
extern "C" void fn_80528528(FeScrN* self);
extern "C" void fn_80528558(FeScrN* self);
extern "C" void fn_80528618(FeScrN* self);
extern "C" void fn_805286D8(FeScrN* self);
extern "C" void fn_80528748(FePair* p, int a, int b);
extern "C" int fn_8052876C(void* x);
extern "C" int fn_80528774(void* x);
extern "C" void fn_8052877C(FeScrN* self);
extern "C" void fn_805287B8(void* x, int a);
extern "C" void fn_805287E0(void* x, int a);
extern "C" void fn_80528808(void* x, int a);
extern "C" void fn_80528830(void* x, int a);
extern "C" void fn_805288E8(FeScrN* self);
extern "C" int fn_80528918(void);
extern "C" void fn_80528924(FeScrN* self);
extern "C" void fn_80528954(FeScrN* self);
extern "C" int fn_80528988(void);
extern "C" int fn_805289D0(void);
extern "C" void fn_805289D8(FeVptr<0x10>* self, int c);
extern "C" void fn_80528A0C(FeVptr<0x10>* self, int c);
extern "C" void fn_80528A40(FeVptr<0x10>* self, int c);
extern "C" void fn_80528A74(FeVptr<0x10>* self, int c);
extern "C" void fn_80528AA8(FeVptr<0x10>* self, int c);
extern "C" void fn_80528ADC(FeVptr<0x10>* self, int c);
extern "C" void fn_80528B10(FeVptr<0x10>* self, int c);
extern "C" void fn_80528B44(FeVptr<0x10>* self, int c);
extern "C" int fn_80528458(FeScrN* x);
extern "C" void fn_8052849C(FeScrN* self);
extern "C" void fn_80528588(FeScrN* self, int c);
extern "C" void fn_80528648(FeScrN* self, int c);
extern "C" void fn_80528708(FeVptr<0x20>* self, int c);
extern "C" void fn_80528754(int* p);

extern "C" FE_OVERLAY void fn_805283C4(FeScrN* self)
{
    self->SetVptr(lbl_80681F30);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_805283F4(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_805283FC(void) {}

extern "C" FE_OVERLAY int fn_80528400(FeScrN* x, int i)
{
    return FeAt((char*)x->m134, i);
}

extern "C" FE_OVERLAY void fn_80528410(void) {}

extern "C" FE_OVERLAY void fn_80528414(void) {}

extern "C" FE_OVERLAY void fn_80528418(void) {}

extern "C" FE_OVERLAY void fn_8052841C(FeScrN* self)
{
    self->SetVptr(lbl_80680C08);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_8052844C(void) {}

extern "C" FE_OVERLAY int fn_80528450(void)
{
    return 0;
}

extern "C" FE_OVERLAY int fn_80528458(FeScrN* x)
{
    return ((int*)FeI(x, 0x134))[FeI(x, 0x140)];
}

extern "C" FE_OVERLAY void fn_8052846C(FeScrN* self)
{
    self->SetVptr(lbl_806800B0);
    fn_800EC5F4__FP8UiScrRaw(self);
}

/* near-miss: member-vptr dtor: all 6 store orders give mr r9,r3 where retail has mr r8,r3 (a fourth pseudo holds r9) */
extern "C" FE_OVERLAY void fn_8052849C(FeScrN* self)
{
    FeI(self, 0x1C8) = (int)lbl_80655E98;
    self->SetVptr(lbl_80655BA8);
    FeI(self, 0x184) = (int)lbl_80655E98;
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_805284DC(void) {}

extern "C" FE_OVERLAY void fn_805284E0(void) {}

extern "C" FE_OVERLAY int fn_805284E4(void* x)
{
    return FeI(x, 0x140);
}

extern "C" FE_OVERLAY void fn_805284EC(FeScrN* self)
{
    self->SetVptr(lbl_8067EED0);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_8052851C(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_80528524(void) {}

extern "C" FE_OVERLAY void fn_80528528(FeScrN* self)
{
    self->SetVptr(lbl_8067EBE8);
    fn_800EC1B8(self);
}

extern "C" FE_OVERLAY void fn_80528558(FeScrN* self)
{
    self->SetVptr(lbl_8067E8A8);
    fn_800EC5F4__FP8UiScrRaw(self);
}

/* near-miss: same member-vptr dtor pattern as fn_8052849C, plus lis order of the two vptr constants */
extern "C" FE_OVERLAY void fn_80528588(FeScrN* self, int c)
{
    self->SetVptr(lbl_8067E5A0);
    FeW* a = (FeW*)((char*)self + 0x3D0);
    a->SetVptr(lbl_8067E8A8);
    ((FeDtorFn)fn_800EC5F4__FP8UiScrRaw)(a, 2);
    FeW* b = (FeW*)((char*)self + 0x1F0);
    b->SetVptr(lbl_8067E8A8);
    ((FeDtorFn)fn_800EC5F4__FP8UiScrRaw)(b, 2);
    FeI(self, 0x1C8) = (int)lbl_80655E98;
    self->SetVptr(lbl_80655BA8);
    FeI(self, 0x184) = (int)lbl_80655E98;
    ((FeDtorFn)fn_8035686C)(self, c);
}

extern "C" FE_OVERLAY void fn_80528618(FeScrN* self)
{
    self->SetVptr(lbl_8067E260);
    fn_800EC5F4__FP8UiScrRaw(self);
}

/* near-miss: same as fn_80528588 */
extern "C" FE_OVERLAY void fn_80528648(FeScrN* self, int c)
{
    self->SetVptr(lbl_8067DF58);
    FeW* a = (FeW*)((char*)self + 0x434);
    a->SetVptr(lbl_8067E260);
    ((FeDtorFn)fn_800EC5F4__FP8UiScrRaw)(a, 2);
    FeW* b = (FeW*)((char*)self + 0x1E0);
    b->SetVptr(lbl_8067E260);
    ((FeDtorFn)fn_800EC5F4__FP8UiScrRaw)(b, 2);
    FeI(self, 0x1C8) = (int)lbl_80655E98;
    self->SetVptr(lbl_80655BA8);
    FeI(self, 0x184) = (int)lbl_80655E98;
    ((FeDtorFn)fn_8035686C)(self, c);
}

extern "C" FE_OVERLAY void fn_805286D8(FeScrN* self)
{
    self->SetVptr(lbl_8067D478);
    fn_800EC1B8(self);
}

extern "C" FE_OVERLAY void fn_80528708(FeVptr<0x20>* self, int c)
{
    self->vp = lbl_8067CEB0;
    lbl_80621640 = 0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528748(FePair* p, int a, int b)
{
    p->a = a;
    p->b = b;
}

extern "C" FE_OVERLAY void fn_80528754(int* p)
{
    lbl_80621640 = *p;
}

extern "C" FE_OVERLAY void fn_80528764(void) {}

extern "C" FE_OVERLAY void fn_80528768(void) {}

extern "C" FE_OVERLAY int fn_8052876C(void* x)
{
    return FeI(x, 0x8);
}

extern "C" FE_OVERLAY int fn_80528774(void* x)
{
    return FeI(x, 0x18);
}

extern "C" FE_OVERLAY void fn_8052877C(FeScrN* self)
{
    self->SetVptr(lbl_8067CBD0);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_805287AC(void) {}

extern "C" FE_OVERLAY void fn_805287B0(void) {}

extern "C" FE_OVERLAY void fn_805287B4(void) {}

extern "C" FE_OVERLAY void fn_805287B8(void* x, int a)
{
    fn_8044C7CC(x, 0, a);
}

extern "C" FE_OVERLAY void fn_805287E0(void* x, int a)
{
    fn_8044C7CC(x, 0, a);
}

extern "C" FE_OVERLAY void fn_80528808(void* x, int a)
{
    fn_8044C7CC(x, 0, a);
}

extern "C" FE_OVERLAY void fn_80528830(void* x, int a)
{
    fn_8044C7CC(x, 1, a);
}

extern "C" FE_OVERLAY void fn_805288E4(void) {}

extern "C" FE_OVERLAY void fn_805288E8(FeScrN* self)
{
    self->SetVptr(lbl_8067C058);
    fn_80360B60(self);
}

extern "C" FE_OVERLAY int fn_80528918(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_80528920(void) {}

extern "C" FE_OVERLAY void fn_80528924(FeScrN* self)
{
    self->SetVptr(lbl_8067BDB0);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80528954(FeScrN* self)
{
    self->SetVptr(lbl_8067B5B8);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY void fn_80528984(void) {}

extern "C" FE_OVERLAY int fn_80528988(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_80528990(FeScrN* self)
{
    self->SetVptr(lbl_8067ADC0);
    FeI(self, 0x220) = (int)lbl_8064A550;
    FeI(self, 0x168) = (int)lbl_8064A550;
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_805289D0(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_805289D8(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528A0C(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528A40(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528A74(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528AA8(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528ADC(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528B10(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_80528B44(FeVptr<0x10>* self, int c)
{
    self->vp = lbl_806827B0;
    if (c & 1) {
        fn_80377408(self);
    }
}
