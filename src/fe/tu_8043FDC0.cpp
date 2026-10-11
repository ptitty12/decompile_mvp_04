/*
 * Front-end overlay code, .frontend_codeoverlay 0x8043FDC0-0x804439E4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern "C" FE_OVERLAY void fn_8043FDC0(void)
{
}

extern "C" FE_OVERLAY void fn_8043FDC4(void)
{
}

extern "C" FE_OVERLAY void fn_8043FDC8(void)
{
}

extern "C" FE_OVERLAY void fn_8043FDCC(void)
{
}

extern "C" FE_OVERLAY void fn_8043FDD0(void)
{
    int i = lbl_8061930C->fn_8007DA28();
    if (i != -1) {
        lbl_8061930C->fn_8007D180(i, (int)FeTunableGet(&lbl_8061B9A0->m1DE0));
    }
}

extern "C" FE_OVERLAY void fn_8043FE44(void)
{
    fn_800A3DF4(lbl_80619948);
}

extern "C" FE_OVERLAY void fn_8043FE6C(void)
{
    unsigned n = fn_800734D4(lbl_8061930C, 0x100);
    void* a = fn_803774A8(n, 0x100);
    void* b = fn_803774A8(n, 0x100);
    Fe803567AC sp8;
    fn_80072E90(lbl_8061930C, a, n, 0x100, 0, &sp8);
    int len = fn_80401610(a, n, b, 1);
    fn_803FBFE0("rost.bin", b, len);
    fn_80377408(a);
    fn_80377408(b);
}

extern "C" FE_OVERLAY void fn_8043FF1C(void)
{
}

extern "C" FE_OVERLAY void fn_8043FF20(void)
{
}

/* near-miss: retail counts n down with subic./bgt and bumps i separately; every for/while/do-while spelling tried (7 slots off at best) keeps one induction variable and compares twice */
extern "C" FE_OVERLAY void fn_80440210(void)
{
    int i;
    int n = lbl_80621608;
    for (i = 0; i < n; i++) {
        fn_8043FF24(i + 1);
    }
}

extern "C" FE_OVERLAY void fn_8044025C(void)
{
    unsigned n = fn_800734D4(lbl_8061930C, 0x100);
    void* a = fn_803774A8(n, 0x100);
    Fe803567AC sp8;
    fn_80072E90(lbl_8061930C, a, n, 0x100, 0, &sp8);
    fn_803FBFE0("urost.bin", a, n);
}

extern "C" FE_OVERLAY void fn_804402D8(void)
{
}

extern "C" FE_OVERLAY void fn_804402DC(void)
{
    fn_800B8AF0((char*)UiGetMsgMgr() + 0x38);
    fn_80331294((char*)lbl_8061B998 + 0x24);
}

extern "C" FE_OVERLAY void fn_80440340(void)
{
    fn_8005B9D4(fn_8005ACE4(), 0);
}

extern "C" FE_OVERLAY void fn_80440368(void)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), &m, 0);
}

extern "C" FE_OVERLAY void fn_80442364(void* self, int a)
{
    fn_80330BC8(self, a);
}

extern "C" FE_OVERLAY void fn_80442488(FeMenuEmail* self)
{
    int z = 0;
    self->m204 = z;
    self->m208 = z;
    self->items[self->m174]->s3();
    self->m174 = z;
    self->items[z]->s2();
    FeItemSet(&self->m2E0, lbl_80622DC8);
    FeItemSet(&self->m334, lbl_80622DC4);
}

extern "C" FE_OVERLAY void fn_80442548(FeMenuEmail* self)
{
    lbl_80622DC8 = FeItemGet(&self->m2E0);
    lbl_80622DC4 = FeItemGet(&self->m334);
}

extern char lbl_80666A18[];
extern char lbl_806672D8[];
extern "C" FE_OVERLAY FeMenuEmail* fn_80442594(FeMenuEmail* self, int a)
{
    self->m174 = 0;
    self->m178 = 0;
    self->m1FC = 0;
    self->m200 = a;
    self->m2DC = lbl_80666A18;
    fn_803E4A50((char*)self + 0x210);
    self->m2D8 = 0;
    self->m2DC = lbl_806672D8;
    fn_8032F120(&self->m2E0, "Increase Spam", 0);
    fn_8032F120(&self->m334, "Test Champion Mail", 0);
    fn_80330ACC(self, &self->m2E0);
    fn_80330ACC(self, &self->m334);
    return self;
}

extern void* lbl_806215DC;
extern int lbl_806215E0;
extern "C" void fn_80377488(void* p);
/* near-miss: retail stores a fresh `li r0,0` for lbl_806215E0; ours reuses the zero register that the == 0 test proves (13 slots)  */
extern "C" FE_OVERLAY void fn_80442930(void)
{
    if (lbl_806215DC == 0) {
        lbl_806215DC = fn_803774A8(40000, 0x100);
        lbl_806215E0 = 0;
    }
}

extern "C" FE_OVERLAY void fn_80442E2C(void)
{
    if (lbl_806215DC != 0) {
        fn_80377488(lbl_806215DC);
        lbl_806215DC = 0;
    }
}

extern "C" FE_OVERLAY void fn_80443598(FeMenuEmail* self)
{
    int z = 0;
    self->m204 = z;
    self->m208 = z;
    self->items[self->m174]->s3();
    self->m174 = z;
    self->items[z]->s2();
}

extern "C" FE_OVERLAY void fn_80443610(void)
{
}

extern "C" FE_OVERLAY void fn_80443614(FeMenuSim* self, int a)
{
    fn_80330BC8(self, a);
    if ((unsigned)(a - 3) <= 1) {
        FeItem* cur = self->items[self->m174];
        if (cur == &self->m32C) {
            lbl_80621608 = FeItemGetB(cur);
        } else if (cur == &self->m394) {
            lbl_80621604 = cur->m4C;
            if ((unsigned)lbl_80621604 > 3)
                lbl_80621604 = 0;
        }
    }
}

extern "C" FE_OVERLAY void fn_804437EC(FeMenuEmail* self)
{
    int z = 0;
    self->m204 = z;
    self->m208 = z;
    self->items[self->m174]->s3();
    self->m174 = z;
    self->items[z]->s2();
}

extern "C" FE_OVERLAY void fn_80443864(void)
{
}

extern "C" FE_OVERLAY void fn_80443868(FeMenuSim* self, int a)
{
    fn_80330BC8(self, a);
    if ((unsigned)(a - 3) <= 1) {
        FeItem* cur = self->items[self->m174];
        if (cur == &self->m32C)
            lbl_80621608 = FeItemGetB(cur);
    }
}
