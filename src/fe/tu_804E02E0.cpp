/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E02E0-0x804E1A6C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

extern "C" void fn_804D32A0(void* menu, int a);

extern "C" FE_OVERLAY int fn_804E02E0(FeObj* self)
{
    if (fn_8040B574(((FeObjQ*)fn_800C8060(self->v32("CELL", 1)))->v70()->v33(5, 1)->name, "CREDITS") == 0) {
        fn_800E2BAC();
    } else {
        if (fn_8040B574(((FeObjQ*)fn_800C8060(self->v32("CELL", 1)))->v70()->v33(5, 1)->name, "PRESENTS") == 0)
            fn_800E2C08();
    }
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E0434(FeI134* self)
{
    self->m134 = 1;
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E0498(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY void fn_804E04F4(FeI134* self, char* out)
{
    if (self->m134 == 0) {
        FeObjQ* c = (FeObjQ*)fn_800C8060(self->v32("CELL", 1));
        fn_8040B830(out, c->v70()->v33(5, 1)->name, 16);
    }
}

extern char lbl_8066CFA0[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E059C(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066CFA0;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E05E8(FeObj* self)
{
    fn_800ECF18(self);
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(p, self);
    fn_80125100(p);
    fn_801250D8(p);
}

extern "C" FE_OVERLAY int fn_804E0664(FeObj* self)
{
    fn_800C8060(self->v32("CELL", 1))->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E06C4(FeObj* self)
{
    fn_800C8060(self->v32("CELL", 1))->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E0724(FeObj* self)
{
    fn_800C8060(self->v32("CELL", 1))->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E0784(FeObj* self)
{
    fn_800C8060(self->v32("CELL", 1))->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E07E4(FeObj* self)
{
    fn_800E2BAC();
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E0844(FeObj* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_800B7B4C(UiGetMsgMgr(), p, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E08B0(FeObj* self)
{
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY void fn_804E090C(FeObj* self, char* out)
{
    FeObjQ* c = (FeObjQ*)fn_800C8060(self->v32("CELL", 1));
    fn_8040B830(out, c->v70()->v33(5, 1)->name, 16);
}

/* near-miss: ours saves r27..r30 (retail keeps 0x3364 in r3 and only r28..r30); 6 spellings of the constants tried */
extern char lbl_806221CC[];
extern char lbl_8066E250[];
extern char lbl_8066E268[];
extern "C" FE_OVERLAY FeRaw174* fn_804E09A4(FeRaw174* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 1, 0x3364, 5, lbl_806221CC);
    fn_80134E38(self->m174, 0);
    self->m1BC = lbl_8066E250;
    self->m3C = lbl_8066E268;
    return self;
}

extern "C" FE_OVERLAY void fn_804E0A28(FeItems* self)
{
    int i = 0;
    fn_804D3164(self);
    fn_804D2DC0(self, 0x3386);
    for (i = 0; i < self->m154; i++)
        self->m1C0[i] = ((FeS10*)fn_804D2EC0(self, i))->s4();
}

extern "C" FE_OVERLAY void fn_804E0AB4(FeItems* self)
{
    for (int i = 0; i < self->m154; i++) {
        ((FeS10*)fn_804D2EC0(self, i))->s5(self->m1C0[i]);
        ((FeS10*)fn_804D2EC0(self, i))->s7();
    }
}

extern "C" FE_OVERLAY void fn_804E0B54(void* self, int i)
{
    ((FeS10*)fn_804D2EC0(self, i))->s7();
}

extern "C" FE_OVERLAY void fn_804E0B8C(void* self, int a)
{
    fn_804D32A0(self, a);
}

extern char lbl_8066D248[];
extern char lbl_8066D260[];
extern "C" FE_OVERLAY FeRaw0BAC* fn_804E0BAC(FeRaw0BAC* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_80135180(self, a, b, c, d, e, f, g, h, 0);
    self->m17C = lbl_8066D248;
    self->m3C = lbl_8066D260;
    fn_800D876C(&self->m1DC);
    self->m200 = 0;
    self->m1F0 = 0;
    self->m1F4 = 0;
    self->m1F8 = 0;
    self->m1FC = 0;
    self->m1D8 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E0C24(FeRaw0BAC* self, int chrg)
{
    self->m17C = lbl_8066D248;
    self->m3C = lbl_8066D260;
    if (self->m134 != 0) {
        delete self->m134;
        self->m134 = 0;
    }
    fn_80135200(self, chrg);
}

extern "C" FE_OVERLAY void fn_804E0EC4(FeObj* self)
{
    fn_800ED254(self);
    fn_8007DB74((Unk8007DB74_A*)lbl_8061930C, -1);
}

extern "C" FE_OVERLAY int fn_804E0EF4(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_804E0EFC(FeTitle* self, int a)
{
    int s = self->m1D8;
    if (s == 2)
        return 0;
    if (s > 2) {
        if (s == 3) {
            fn_8001BC4C()->fn_8001BDAC(0x9D);
            fn_804E1670(self);
            Unk8007B2B0_Screen* sc = lbl_8061930C;
            sc->fn_8007DA8C(a, sc->fn_8007DA28());
            return 1;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804E0F80(FeTitle* self)
{
    int s = self->m1D8;
    if (s == 2)
        return 0;
    if (s > 2) {
        if (s == 3) {
            fn_8001BC4C()->fn_8001BDAC(0x9D);
            fn_804E1670(self);
            return 1;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804E0FE0(FeTitle* self)
{
    fn_800ECAA4(self);
    if (self->m1F4 == 0)
        fn_804E1020(self);
}

extern "C" FE_OVERLAY void fn_804E15FC(FeTitle* self, char* out)
{
    if (self->m1D8 == 3 && fn_800D87C4(&self->m1DC) != 0) {
        *out = lbl_805F36A0[0];
    } else {
        lbl_806221E0 = 0;
        fn_8040B830(out, "PRESSSTART", 16);
    }
}

extern "C" FE_OVERLAY void fn_804E1670(FeTitle* self)
{
    ((FeObj1*)self->v32("LOADMESSAGE", 1))->v8(1);
    ((FeObjS*)fn_800C8040(self->v32("MESSAGE", 1)))->v30(lbl_805F36A0);
    self->m1D8 = 4;
    fn_804E14EC(self, 4);
}

extern char lbl_8066DFA8[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E1734(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->m3C = lbl_8066DFA8;
    self->m134 = -1;
    return self;
}

extern "C" FE_OVERLAY void fn_804E1788(void)
{
    fn_800B82D0(fn_800B8144(), 13, 0);
    fn_800B8144()->m1C = (FeVf)fn_804E18D4;
    fn_8001BC4C()->fn_8001BDAC(0xB2);
}

extern "C" FE_OVERLAY int fn_804E17D0(FeObj* self)
{
    fn_804E1840(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E17F4(FeObj* self)
{
    fn_804E1840(self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1818(void* self)
{
    fn_802D7EE4(fn_800C8070(self));
    return 0;
}

extern "C" FE_OVERLAY void fn_804E1840(FeObj* self)
{
    fn_8033E958("cFEDemoMovie::EndDemo()\n");
    fn_800B8144()->m1C = 0;
    fn_800B82D0(fn_800B8144(), -1, 1);
    fn_8001BC4C()->fn_8001BDAC(0xB1);
    fn_800E2C34();
    fn_800B7ADC(UiGetMsgMgr(), self);
}

extern "C" FE_OVERLAY void fn_804E18D4(void)
{
    fn_8033E958("cFEDemoMovie::MoveDone() callback\n");
    fn_804E1840(fn_800B7AB8(UiGetMsgMgr(), "DEMOMOVIE"));
}

extern char lbl_8065C4E0[];
extern char lbl_8066CA20[];
extern char lbl_8066CA38[];
extern "C" FE_OVERLAY FeRawTitle* fn_804E1940(FeRawTitle* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648((FeScrRaw*)self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->m3C = lbl_8065C4E0;
    fn_80134E38(self->m134, 0);
    self->m17C = lbl_8066CA20;
    self->m3C = lbl_8066CA38;
    self->m180 = 0;
    self->m184 = 0;
    self->m188 = -1;
    for (unsigned i = 0; i <= 8; i++) {
        if (fn_8005B9B0(fn_8005ACE4(), i) == 0)
            self->m188 ^= 1 << i;
    }
    return self;
}

extern "C" FE_OVERLAY void fn_804E19F8(FeTitle* self)
{
    fn_800ECE34(self);
    self->m184 = fn_800C8060(self->v32("CELL", 1));
    ((FeObj1*)self->m184)->v105(1);
}
