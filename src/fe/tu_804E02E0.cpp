/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E02E0-0x804E1A6C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

struct Unk80171A10_Menu;
struct Unk80174318_T;
void fn_80172334(Unk80171A10_Menu* m, int a, int b, const unsigned short* t, const char* s);
void fn_80174760(Unk80174318_T* t);
extern "C" void fn_8013501C(void* p);
struct FeMenuP {
    char pad0[0x40];
    int m40;
    int m44;
};

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
    /* The provider at 0x800D876C returns the initialized timer pointer. */
    ((Unk800D876C_A* (*)(Unk800D876C_A*))fn_800D876C)(&self->m1DC);
    self->m1F0 = 0;
    self->m1F4 = 0;
    self->m1F8 = 0;
    self->m1FC = 0;
    self->m1D8 = 0;
    self->m200 = 0;
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


extern "C" void* fn_800C5E28();
extern "C" void fn_800C62B8(void*, FeObj*, FeObj*, const char*, float, int);
extern "C" void fn_80135264(void*);
extern "C" void fn_803D9E1C(int);
extern const char lbl_805F7B80[], lbl_805F9928[], lbl_805F9930[], lbl_805F9938[];
extern char lbl_805F994C[];
extern const char lbl_805F9940[], lbl_805F9958[], lbl_805F9978[];
extern float lbl_805F999C;
#define FE_CA4_GET(n) virtual FeObj* v##n(const char*);
class FeLookup804E0CA4 : public UiBase {
public:
    FE_LO(FE_CA4_GET) virtual FeObj* v32(const char*,int); FE_HI(FE_CA4_GET)
};
#undef FE_CA4_GET
extern "C" FE_OVERLAY void fn_804E0CA4(FeTitle* self)
{
    fn_800ECF18(self);
    FeObj* popup = fn_800B7AB8(UiGetMsgMgr(), lbl_805F7B80);
    FeObj* first = fn_800C8038(popup->v32(lbl_805F9928, 1));
    FeObj* second = fn_800C8038(popup->v32(lbl_805F9930, 1));
    fn_800C62B8(fn_800C5E28(), first, second, lbl_805F9938, lbl_805F999C, 0);
    ((FeMsgMgrB*)UiGetMsgMgr())->mC0 = 0;
    fn_80135264(self);
    self->m1F4 = 0;
    ((FeObj1*)self->v32(lbl_805F9940, 1))->v8(0);
    ((FeObj1*)self->v32(lbl_805F994C, 1))->v8(1);
    fn_803D9E1C(1);
    ((FeObj1*)fn_800C8048(((FeLookup804E0CA4*)self)->v29(lbl_805F9958)))->v29(0x37C8);
    ((FeObj1*)fn_800C8040(((FeLookup804E0CA4*)self)->v29(lbl_805F9978)))->v29(0x37C8);
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

extern int lbl_80692664;
extern int lbl_8061B8B8;
extern char lbl_805F994C[], lbl_805F99A0[];
extern "C" int fn_80400DA4();
extern "C" void fn_800B7280(UiMsgMgr*, int);
extern "C" int fn_802DC9C0();
extern "C" int fn_800D8938(Unk800D876C_A*);
extern "C" void* fn_800ED2B0(FeObj*, const char*);
extern "C" void fn_800CFB38(void*);
extern "C" void fn_804E1200(FeTitle*);
extern "C" FE_OVERLAY void fn_804E1020(FeTitle* self)
{
    switch (self->m1D8) {
    case 0:
        if (lbl_80692664 + 300 <= fn_80400DA4()) {
            ((FeObj1*)self)->v8(1);
            ((FeObj1*)self->v32(lbl_805F994C, 1))->v8(0);
            self->m1F0 = 0;
            self->m1D8 = 1;
            self->m1F8 = fn_80400DA4();
        }
        break;
    case 1:
        if (self->m1F8 + 15 <= fn_80400DA4()) {
            fn_800B7280(UiGetMsgMgr(), 1);
            self->m1D8 = 2;
        }
        break;
    case 2:
        if (self->m1F8 + 240 <= fn_80400DA4()) {
            self->m1D8 = 3;
            fn_800D878C(&self->m1DC);
            fn_800CFB38(fn_800ED2B0(self, lbl_805F99A0));
        }
        break;
    case 3:
        fn_802DC9C0();
        if (fn_800D8938(&self->m1DC) != 0) {
            ++lbl_8061B8B8;
            fn_800B7ADC(UiGetMsgMgr(), self);
        }
        break;
    case 8: case 9:
        break;
    default:
        fn_804E1200(self);
        break;
    }
}


struct FeEvent804E1200 {
    int type;
    int active;
    int field8;
    const unsigned short* text;
};
extern "C" FeEvent804E1200* fn_801723B8__FP16Unk80171A10_Menu(void*);
extern "C" int fn_801718E8__11Unk80171760(FeEvent804E1200*);
extern "C" unsigned char* fn_8007FE04__FP13Unk8007F198_D(void*);
extern "C" void fn_80135328(void*, FeEvent804E1200*);
extern "C" void fn_801354D4(void*);
extern "C" void fn_80134F98(void*);
extern "C" void fn_8040316C(unsigned short*, const unsigned short*, int);
extern "C" int fn_804030C8(const unsigned short*, const unsigned short*);
extern const char lbl_805F99A8[];
extern int lbl_8061A308;
extern "C" FE_OVERLAY void fn_804E1200(FeTitle* self)
{
    FeEvent804E1200* event = fn_801723B8__FP16Unk80171A10_Menu(*(void**)self->m134);
    if (event != 0) {
        if (event->active != 0) {
            ((FeObj1*)self->v32(lbl_805F9940, 1))->v8(0);
            ((FeObj1*)self->v32(lbl_805F99A8, 1))->v8(0);
            int type = event->type;
            if (type == 1) {
                if (self->m1FC == 0 || fn_801718E8__11Unk80171760(event) != 0) {
                    fn_80135328(self, event);
                    fn_8040316C((unsigned short*)((char*)self + 0x200), event->text, 0x200);
                    self->m1FC = type;
                } else {
                    unsigned short* text = (unsigned short*)((char*)self + 0x200);
                    if (fn_804030C8(event->text, text) != 0) {
                        fn_801354D4(self);
                        fn_80135328(self, event);
                        fn_8040316C(text, event->text, 0x200);
                    }
                }
            }
        }
        if (event->type == 5) {
            if ((unsigned)(self->m1D8 - 5) <= 1)
                fn_80134F98(self->m134);
            if (self->m1D8 == 5) {
                unsigned char* settings = fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C);
                unsigned char* levels = settings + 4;
                fn_8001BC4C()->fn_8001C05C(0, (unsigned)levels[0] * (1.0f / 255.0f), 1);
                fn_8001BC4C()->fn_8001C05C(3, (unsigned)levels[3] * (1.0f / 255.0f), 1);
                fn_8001BC4C()->fn_8001C05C(1, (unsigned)levels[1] * (1.0f / 255.0f), 1);
                fn_8001BC4C()->fn_8001C05C(4, (unsigned)levels[4] * (1.0f / 255.0f), 1);
                fn_8001BC4C()->fn_8001C05C(2, (unsigned)levels[2] * (1.0f / 255.0f), 1);
                int loaded = 1;
                lbl_8061A308 = loaded;
            }
            fn_804E14EC(self, ++self->m1D8);
        }
        if (event->type == 6) {
            fn_804E14EC(self, ++self->m1D8);
            if (self->m1D8 == 7)
                fn_801354D4(self);
        }
    }
}

extern "C" FE_OVERLAY void fn_804E14EC(FeTitle* self, int a)
{
    switch (a) {
    case 4:
        fn_8013501C(self->m134);
        *(int*)(self->m134 + 0x28) = 0;
        fn_80174760(*(Unk80174318_T**)self->m134);
        break;
    case 5: {
        (*(FeMenuP**)self->m134)->m40 = 1;
        (*(FeMenuP**)self->m134)->m44 = 1;
        *(int*)(self->m134 + 0x28) = 0x11;
        fn_8013501C(self->m134);
        const unsigned short* s = (const unsigned short*)fn_80090880(lbl_8061977C, 0x60E);
        fn_80172334(*(Unk80171A10_Menu**)self->m134, 0, *(int*)(self->m134 + 0x28), s, "Save Game");
        break;
    }
    case 6:
        fn_804E14EC(self, ++self->m1D8);
        break;
    case 7:
        fn_800B7ADC(UiGetMsgMgr(), self);
        break;
    }
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
