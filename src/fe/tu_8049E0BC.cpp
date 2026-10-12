/*
 * Front-end overlay code, .frontend_codeoverlay 0x8049E0BC-0x804A2AB4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" int fn_8055B048(int mgr, int a, int b);
extern const char lbl_805F76E0[];
extern "C" char* strncpy(char*, const char*, unsigned);
extern const char lbl_805F766C[];
extern "C" void fn_8049F2E4(void* x);
extern const char lbl_805F7634[];
extern "C" int fn_800D83C8(int* p);
extern "C" char* strcpy(char*, const char*);
extern "C" int fn_80075948__18Unk8007B2B0_Screeni(void*, int);
extern "C" int fn_8007B8C4__18Unk8007B2B0_Screenii(void*, int, int);
extern "C" void fn_800A2188(void*, int);
extern "C" void fn_805819A4(void*, int, int);
extern "C" void fn_805819C8(void*, int);
extern "C" void fn_800C2034(void*, int);
extern const char lbl_805F7504[];
extern const char lbl_805F4F48[];
extern const char lbl_805F75E8[];
extern "C" void fn_8055AC44(void*, int);
struct FeE6B8 : FeScrH {
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
};
extern "C" void fn_800DD800(void*, void*, int, int);
struct UiS;
void fn_800DDF2C(UiS*);
extern "C" void fn_8049FC58(void* x, int a);
extern const char lbl_805F57D0[];
extern const char lbl_805F75AC[];
extern const char lbl_805F5100[];
extern "C" FeW* fn_800C8038(FeW*);
extern "C" void fn_800DD204(FeW*, FeW*);
struct Unk80090880;
const char* fn_80090880(Unk80090880* t, int id);
extern Unk80090880* lbl_8061977C;
extern "C" void fn_804A15FC(char* x);
extern const char lbl_805F7664[];
extern "C" void fn_80529158(void);
extern "C" void fn_804A193C(int a, FeW* x);
extern "C" void fn_8049E94C(void* x);
extern "C" void fn_8049EDC8(void* x);
extern "C" void fn_8049F088(void* x);
extern "C" void fn_8049F50C(void* x);
extern "C" void fn_8049F6D0(void* x);
extern "C" void fn_8049F80C(void* x);
extern "C" void fn_8049F98C(void* x);
extern "C" void fn_8049FB38(FeW* x);
extern const char lbl_805F758C[];
extern const char lbl_805F7594[];
extern const char lbl_805F75A0[];
struct Fe0948Rec {
    int m0;
    int m4;
    int m8;
    FeW* mC;
    FeW* m10;
    int m14;
    int m18;
    int m1C;
    FeW* m20;
    FeW* m24;
};
extern const char lbl_805F4ECC[];
extern const char lbl_805F76E8[];
extern const char lbl_805F76F4[];
extern "C" int sprintf(char*, const char*, ...);
extern "C" int fn_8007F84C__FP13Unk8007F198_B(void* g);
extern char lbl_80649EC0[];
struct FeTrk {
    int m0;
    void* m4;
    const void* m8;
    ~FeTrk() { m8 = lbl_80649EC0; }
};
extern "C" FeTrk* fn_8054CBBC(FeTrk* o, int a, void* b);
extern "C" void fn_8054F2C4(FeTrk* o);
extern "C" void fn_8054CBD8(FeTrk* o, int a);
extern "C" void fn_8054F46C(FeTrk* o);
int fn_800E1990(int i); /* C++ symbol fn_800E1990__Fi */
extern "C" int fn_800A2E90(void* g);

extern "C" {

FE_OVERLAY int fn_8049E0BC(void* x)
{
    FeMem(x, 0x154)->fn_vslot40(1);
    return 1;
}

FE_OVERLAY int fn_8049E0FC(void* x)
{
    ((FeWV*)FeMem(x, 0x154))->s41();
    return 1;
}

FE_OVERLAY int fn_8049E138(void* x)
{
    FeMem(x, 0x154)->fn_vslot38(1);
    return 1;
}

FE_OVERLAY int fn_8049E178(void* x)
{
    FeMem(x, 0x154)->fn_vslot39();
    return 1;
}

FE_OVERLAY FeScrH* fn_8049E1B4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80674DC8);
    self->m130 = 0;
    FeI(self, 0x16C) = 0;
    return self;
}

FE_OVERLAY void fn_8049E6B8(FeE6B8* x)
{
    fn_800ECF18(x);
    FeState* st = fn_800B555C();
    x->m14C = 0;
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(w, x);
    int k = st->m0;
    fn_8055AC44((char*)x + 0x230, 0);
    fn_8055AC44((char*)x + 0x690, 1);
    fn_8055AC44((char*)x + 0xAF0, 2);
    fn_8055AC44((char*)x + 0xF50, 3);
    switch (k) {
    case 0x11:
        x->m140 = 0;
        x->m144 = 1;
        x->m14C = 1;
        fn_8049E830(x, 1);
        break;
    case 0x12:
        x->m144 = 0;
        x->m140 = 1;
        fn_8049E830(x, 6);
        break;
    case 0x13:
        x->m144 = 0;
        x->m14C = 0;
        x->m140 = 1;
        fn_8049E830(x, 1);
        break;
    case 0x15:
        fn_8049E830(x, 2);
        break;
    case 0xF:
        fn_8049E830(x, 3);
        break;
    case 0x10:
        fn_8049E830(x, 4);
        break;
    case 0x14:
        fn_8049E830(x, 5);
        break;
    }
}

FE_OVERLAY void fn_8049E830(void* x, int a)
{
    if (FeI(x, 0x16C) == 0) {
        FeI(x, 0x16C) = a;
    }
    switch (FeI(x, 0x174)) {
    case 0:
        break;
    case 2:
        break;
    case 1:
        fn_8049F00C((char*)x);
        break;
    case 6:
        fn_8049F2A8(x);
        break;
    }
    switch (a) {
    case 1:
        fn_8049EDC8(x);
        break;
    case 2:
        fn_8049F50C(x);
        break;
    case 3:
        fn_8049F6D0(x);
        break;
    case 4:
        fn_8049F80C(x);
        break;
    case 5:
        fn_8049F98C(x);
        break;
    case 6:
        fn_8049F088(x);
        break;
    case 7:
        fn_8049FB38((FeW*)x);
        break;
    }
    if (FeI(x, 0x16C) == 1) {
        FeI(x, 0x140) = FeI(x, 0x16C);
    }
    FeI(x, 0x174) = a;
    fn_8049E94C(x);
}

FE_OVERLAY void fn_8049ED34(void* a, void* cb)
{
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    if (FeI(fn_800B555C(), 0x588) == 0) {
        fn_80125268(w, 2, cb, 0);
    } else {
        fn_80125084(w, 2);
    }
}

FE_OVERLAY void fn_8049F00C(char* x)
{
    Unk8006A138_It<3> it(0);
    int i = 0;
    do {
        char* b = x + 0x18C;
        int o = i * 0x28;
        FeW* w = *(FeW**)(b + o);
        w->fn_vslot8(0);
        i = it.Next();
    } while (i <= 3);
}

FE_OVERLAY void fn_8049F2A8(void* x)
{
    FeMem(x, 0x180)->fn_vslot8(0);
}

FE_OVERLAY void fn_8049F50C(void* xx)
{
    FeW* x = (FeW*)xx;
    FeI(x, 0x134) = 0;
    FeI(x, 0x138) = 1;
    FeI(x, 0x164) = 0;
    FeI(x, 0x13C) = 0;
    FeI(x, 0x140) = 0;
    FeI(x, 0x144) = 1;
    FeI(x, 0x154) = 1;
    FeI(x, 0x150) = 0;
    FeI(x, 0x158) = 0;
    FeI(x, 0x15C) = 0;
    FeI(x, 0x160) = 0;
    FeI(x, 0x178) = fn_800B5520(FeI(fn_800B555C(), 0xC0));
    fn_804A15FC((char*)x);
    FeW* a = fn_800C8044(x->fn_vslot32(lbl_805F7594, 1));
    FeP(x, 0x180) = a;
    a->fn_vslot8(1);
    FeW* w = fn_800C8054(FeMem(x, 0x180)->fn_vslot32(lbl_805F4F48, 1));
    FeP(x, 0x224) = w;
    ((FeSubB*)((char*)w + 0x98))->s20(fn_800B548C(FeI(x, 0x178)), 0);
    FeI(x, 0x170) = (int)fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
    fn_8049F2E4(x);
    x->fn_vslot16(0);
    x->fn_vslot32(lbl_805F755C, 1)->fn_vslot14(0);
    fn_8049FC58(x, 2);
    fn_800A2188(lbl_80619948, fn_800B548C(FeI(x, 0x178)));
}

FE_OVERLAY void fn_8049F6D0(void* xx)
{
    FeW* x = (FeW*)xx;
    void* g = lbl_8061930C;
    FeI(x, 0x134) = 0;
    FeI(x, 0x138) = 1;
    FeI(x, 0x164) = 0;
    FeI(x, 0x13C) = 0;
    FeI(x, 0x140) = 0;
    FeI(x, 0x144) = 1;
    FeI(x, 0x15C) = 1;
    FeI(x, 0x14C) = 0;
    FeI(x, 0x150) = 0;
    FeI(x, 0x154) = 0;
    FeI(x, 0x158) = 0;
    FeI(x, 0x160) = 0;
    FeI(x, 0x178) = fn_800B5520((int)fn_8007F7D0__FP13Unk8007F198_BUi(g, 0));
    fn_804A15FC((char*)x);
    FeW* a = fn_800C8044(x->fn_vslot32(lbl_805F75A0, 1));
    FeP(x, 0x180) = a;
    a->fn_vslot8(1);
    FeW* w = fn_800C8054(FeMem(x, 0x180)->fn_vslot32(lbl_805F4F48, 1));
    FeP(x, 0x224) = w;
    ((FeSubB*)((char*)w + 0x98))->s20(fn_800B548C(FeI(x, 0x178)), 0);
    fn_8049FC58(x, 3);
}

/* near-miss (97.8%): 2 store slots swapped (stw 0x160 / li r4 position); hill-climbed 14 lines over 4 seeds */
FE_OVERLAY void fn_8049F80C(void* xx)
{
    FeW* x = (FeW*)xx;
    void** pg = &lbl_8061930C;
    void* g = *pg;
    FeI(x, 0x134) = 0;
    FeI(x, 0x15C) = 1;
    FeI(x, 0x164) = 0;
    FeI(x, 0x13C) = 0;
    FeI(x, 0x140) = 0;
    FeI(x, 0x144) = 1;
    FeI(x, 0x14C) = 0;
    FeI(x, 0x150) = 0;
    FeI(x, 0x154) = 0;
    FeI(x, 0x158) = 0;
    FeI(x, 0x138) = 1;
    FeI(x, 0x160) = 0;
    FeI(x, 0x178) = fn_800B5520((int)fn_8007F7D0__FP13Unk8007F198_BUi(g, 0));
    if (fn_800A2E90(lbl_80619948) != 0) {
        FeTrk t;
        fn_8054CBBC(&t, (int)fn_8007F7D0__FP13Unk8007F198_BUi(*pg, 0), *pg);
        fn_8054F2C4(&t);
    }
    fn_804A15FC((char*)x);
    FeW* a = fn_800C8044(x->fn_vslot32(lbl_805F75A0, 1));
    FeP(x, 0x180) = a;
    a->fn_vslot8(1);
    FeW* w = fn_800C8054(FeMem(x, 0x180)->fn_vslot32(lbl_805F4F48, 1));
    FeP(x, 0x224) = w;
    ((FeSubB*)((char*)w + 0x98))->s20(fn_800B548C(FeI(x, 0x178)), 0);
    fn_8049FC58(x, 4);
}

FE_OVERLAY void fn_8049F98C(void* xx)
{
    FeW* x = (FeW*)xx;
    void** pg = &lbl_8061930C;
    void* g = *pg;
    FeI(x, 0x134) = 0;
    FeI(x, 0x164) = 0;
    FeI(x, 0x13C) = 0;
    FeI(x, 0x140) = 0;
    FeI(x, 0x14C) = 0;
    FeI(x, 0x154) = 0;
    FeI(x, 0x15C) = 0;
    FeI(x, 0x138) = 1;
    FeI(x, 0x144) = 1;
    FeI(x, 0x150) = 1;
    FeI(x, 0x158) = 1;
    FeI(x, 0x160) = 1;
    FeI(x, 0x178) = fn_800B5520(fn_8007B320__18Unk8007B2B0_Screenii(g, 0, (int)fn_8007F7D0__FP13Unk8007F198_BUi(g, 0)));
    char* b8 = (char*)fn_800B555C() + 8;
    fn_800C2034(b8, fn_800E1990__Fi(FeI(x, 0x178)));
    if (FeI(fn_800B555C(), 0x674) == 0) {
        FeTrk t;
        fn_8054CBBC(&t, (int)fn_8007F7D0__FP13Unk8007F198_BUi(*pg, 0), *pg);
        fn_8054F46C(&t);
    }
    fn_804A15FC((char*)x);
    FeW* a = fn_800C8044(x->fn_vslot32(lbl_805F7594, 1));
    FeP(x, 0x180) = a;
    a->fn_vslot8(1);
    FeW* w = fn_800C8054(FeMem(x, 0x180)->fn_vslot32(lbl_805F4F48, 1));
    FeP(x, 0x224) = w;
    ((FeSubB*)((char*)w + 0x98))->s20(fn_800B548C(FeI(x, 0x178)), 0);
    fn_8049FC58(x, 5);
}

FE_OVERLAY void fn_8049FB38(FeW* x)
{
    FeI(x, 0x134) = 0;
    FeI(x, 0x138) = 1;
    FeI(x, 0x164) = 1;
    FeI(x, 0x13C) = 1;
    FeI(x, 0x140) = 1;
    FeI(x, 0x154) = 1;
    FeI(x, 0x144) = 0;
    FeI(x, 0x150) = 0;
    FeI(x, 0x158) = 0;
    FeI(x, 0x15C) = 0;
    FeI(x, 0x160) = 0;
    FeI(x, 0x178) = 0;
    fn_804A15FC((char*)x);
    FeW* a = fn_800C8044(x->fn_vslot32(lbl_805F7504, 1));
    FeP(x, 0x180) = a;
    a->fn_vslot8(1);
    FeW* w = fn_800C8054(FeMem(x, 0x180)->fn_vslot32(lbl_805F4F48, 1));
    FeP(x, 0x224) = w;
    ((FeSubB*)((char*)w + 0x98))->s20(fn_800B548C(FeI(x, 0x178)), 0);
    fn_8049FC58(x, 7);
}

FE_OVERLAY void fn_8049FC58(void* xx, int a)
{
    FeW* x = (FeW*)xx;
    Unk80090880* t = lbl_8061977C;
    const char* s = 0;
    switch (a) {
    case 1:
        if (FeI(x, 0x16C) == 1 && fn_800B555C()->m0 != 0x13)
            s = fn_80090880(t, 0x299B);
        else
            s = fn_80090880(t, 0x4DA2);
        break;
    case 2:
        s = fn_80090880(t, 0x1AEA);
        break;
    case 3:
        s = fn_80090880(t, 0x251C);
        break;
    case 4:
        s = fn_80090880(t, 0x3856);
        break;
    case 5:
        s = fn_80090880(t, 0x1F86);
        break;
    case 6:
        s = fn_80090880(t, 0x1AE0);
        break;
    case 7:
        s = fn_80090880(t, 0x299D);
        break;
    }
    FeW* p = fn_800C8044(x->fn_vslot32(lbl_805F57D0, 1));
    ((FeWQ*)fn_800C8040(p->fn_vslot32(lbl_805F57D0, 1)))->s28((int)s);
    ((FeWQ*)fn_800C8040(p->fn_vslot32(lbl_805F75AC, 1)))->s28((int)s);
    FeW* q = fn_800C8040(p->fn_vslot32(lbl_805F75AC, 1));
    fn_800DD204(q, fn_800C8038(p->fn_vslot32(lbl_805F5100, 1)));
}

FE_OVERLAY void fn_8049FE54(void* x)
{
    if (FeI(x, 0x14C) != 0) {
        int a = fn_800B548C(FeI(x, 0x178));
        int b = fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, a);
        fn_800A2188(lbl_80619948, b);
        if (fn_8007B3E0__18Unk8007B2B0_Screenii(lbl_8061930C, 0xF, (void*)b) == 0) {
            int c = fn_8007B8C4__18Unk8007B2B0_Screenii(lbl_8061930C, 0x37, a);
            fn_805819C8(FeP(lbl_8061930C, 0x2C), 1);
            if (FeI(fn_8007FE04((Unk8007F198_D*)lbl_8061930C), 0x1F4) == 1) {
                fn_805819C8(FeP(lbl_8061930C, 0x2C), 0);
            }
            fn_805819A4(FeP(lbl_8061930C, 0x2C), a, c);
        }
        fn_800C2034((char*)fn_800B555C() + 8, 0);
    }
}

FE_OVERLAY void fn_8049FF38(FeW* x, FeW* y)
{
    if (y == fn_800C805C(x->fn_vslot32(lbl_805F59C4, 1)) && FeI(x, 0x148) != 0) {
        FeI(x, 0x178) = fn_800B5520(((FeSubI*)((char*)fn_800C8058(y->fn_vslot32(lbl_805F535C, 1)) + 0xDC))->s11());
        fn_804A0B18(x);
    }
}

FE_OVERLAY int fn_8049FFF4(FeW* x)
{
    if (FeI(x, 0x140) == 1) {
        if (fn_800B555C()->m0 == 0x11) {
            FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
            fn_80132438(p, x, 0, fn_804A29F4, fn_804A2964, 0x3A61, -1, 1, 0.5f);
            p->fn_vslot86();
        } else {
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            if (fn_800B5758(fn_800B555C()) == 1 && fn_800B555C()->m0 == 0x11) {
                strncpy(mp->name, lbl_805F75B8, 15);
                mp->name[15] = 0;
            } else {
                strncpy(mp->name, lbl_805F4450, 15);
                mp->name[15] = 0;
            }
            fn_800B7B4C(FeGetMgr(), &m, x);
        }
    }
    return 1;
}

FE_OVERLAY int fn_804A0470(void) { return 0; }

FE_OVERLAY int fn_804A0478(void) { return 0; }

FE_OVERLAY int fn_804A0480(void) { return 0; }

FE_OVERLAY int fn_804A0488(void) { return 0; }

FE_OVERLAY int fn_804A0490(FeW* x)
{
    if (FeI(x, 0x14C) != 0) {
        FeW* p = fn_800C805C(x->fn_vslot32(lbl_805F59C4, 1));
        p->fn_vslot40(1);
        FeI(x, 0x178) = fn_800B5520(((FeSubI*)((char*)fn_800C8058(p->fn_vslot32(lbl_805F535C, 1)) + 0xDC))->s11());
        fn_804A0B18(x);
    }
    if (FeI(x, 0x13C) != 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F755C, 1))->fn_vslot50();
    }
    return 0;
}

FE_OVERLAY int fn_804A05B0(FeW* x)
{
    if (FeI(x, 0x14C) != 0) {
        FeW* p = fn_800C805C(x->fn_vslot32(lbl_805F59C4, 1));
        ((FeWV*)p)->s41();
        FeI(x, 0x178) = ((FeSubI*)((char*)fn_800C8058(p->fn_vslot32(lbl_805F535C, 1)) + 0xDC))->s5();
        fn_804A0B18(x);
    }
    if (FeI(x, 0x13C) != 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F755C, 1))->fn_vslot51();
    }
    return 0;
}

FE_OVERLAY int fn_804A06C8(FeW* x)
{
    if (FeI(x, 0x14C) != 0) {
        FeW* p = fn_800C805C(x->fn_vslot32(lbl_805F59C4, 1));
        p->fn_vslot38(1);
        FeI(x, 0x178) = ((FeSubI*)((char*)fn_800C8058(p->fn_vslot32(lbl_805F535C, 1)) + 0xDC))->s5();
        fn_804A0B18(x);
    }
    if (FeI(x, 0x13C) != 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F755C, 1))->fn_vslot52();
    }
    return 0;
}

FE_OVERLAY int fn_804A07E4(FeW* x)
{
    if (FeI(x, 0x14C) != 0) {
        FeW* p = fn_800C805C(x->fn_vslot32(lbl_805F59C4, 1));
        p->fn_vslot39();
        FeI(x, 0x178) = fn_800B5520(((FeSubI*)((char*)fn_800C8058(p->fn_vslot32(lbl_805F535C, 1)) + 0xDC))->s11());
        fn_804A0B18(x);
    }
    if (FeI(x, 0x13C) != 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F755C, 1))->fn_vslot53();
    }
    return 0;
}

FE_OVERLAY void fn_804A0900(void* a, int b, int c)
{
    int id = fn_80083FC0(b);
    fn_800B5520(fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, id, c));
}

FE_OVERLAY void fn_804A0948(char* x, int a)
{
    int k = fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, a);
    Unk8006A138_It<3> it(0);
    int i = 0;
    do {
        Fe0948Rec* r = (Fe0948Rec*)(x + 0x184 + i * 0x28);
        int v = ((int (*)(void*, int, int))fn_804A0900)(x, r->m4, k);
        r->m0 = v;
        int c = fn_800B548C(v);
        ((FeSubB*)((char*)r->mC + 0xDC))->s20(c, 0);
        ((FeSubB*)((char*)r->m10 + 0x98))->s20(c, 0);
        ((FeSubB*)((char*)r->m20 + 0x98))->s20(c, 0);
        ((FeSubB*)((char*)r->m24 + 0x98))->s20(c, 0);
        i = it.Next();
    } while (i <= 3);
}

FE_OVERLAY void fn_804A0A78(void* x, int a)
{
    ((FeSubB*)((char*)FeP(x, 0x224) + 0x98))->s20(a, 0);
    ((FeSubB*)((char*)FeP(x, 0x228) + 0x98))->s20(a, 0);
    ((FeSubB*)((char*)FeP(x, 0x22C) + 0x98))->s20(a, 0);
}

struct FeA13A8 {
    char pad0[0x14];
    void* arr[3];
};
FE_OVERLAY void fn_804A0D48(char* x)
{
    int arr[4];
    arr[0] = (int)(x + 0x230);
    arr[1] = (int)(x + 0x690);
    arr[2] = (int)(x + 0xAF0);
    arr[3] = (int)(x + 0xF50);
    Unk8006A138_It<3> it(0);
    int i = 0;
    do {
        int off = i * 0x28 + 0x184;
        FeW* w = fn_800C8044(FeMem(x + off, 8)->fn_vslot32(lbl_805F75E8, 1));
        int id = fn_800B548C(FeI(x, off));
        if (FeI(fn_800B555C(), 0x588) == 0)
            fn_800DD800(w, (void*)arr[it.v], id, 1);
        else
            fn_800DDF2C((UiS*)w);
        i = it.Next();
    } while (i <= 3);
}

FE_OVERLAY void fn_804A13A8(char* x)
{
    int i = 0;
    int mgr = FeI(lbl_8061930C, 0x68);
    FeA13A8* s = (FeA13A8*)(x + 0x184);
    do {
        int k = fn_8055B048(mgr, FeI(x, 0x178), i);
        void* w = s->arr[i];
        i++;
        ((FeSubB*)((char*)w + 0x98))->s20(k, 0);
    } while (i <= 2);
}

FE_OVERLAY void fn_804A1434(void* x, char* out)
{
    const char* s;
    *out = 0;
    if (FeI(x, 0x158) != 0) {
        int t = fn_800D83A0();
        FeI(fn_800B555C(), 0xC4) = t;
        if (FeI(x, 0x158) != 0 && FeI(fn_800B555C(), 0xC4) != 0) {
            FeI(fn_800B555C(), 0xC4) = 1;
            s = lbl_805F7634;
            goto done;
        }
    }
    if (FeI(x, 0x150) != 0) {
        int v = 0;
        if (fn_800D83C8(&v) != 0) {
            FeI(fn_800B555C(), 0xC0) = v;
            s = lbl_805F763C;
        } else {
            s = lbl_805F7648;
        }
    } else {
        s = (const char*)&lbl_805F36A0;
    }
done:
    strcpy(out, s);
}

FE_OVERLAY int fn_804A1510(void* x, FeEvt* ev)
{
    char* name = ev->name;
    if (FeI(x, 0x13C) != 0 && ev->m1C == 5 && (fn_8040B574(name, lbl_805F7654) == 0 || fn_8040B574(name, lbl_805F765C) == 0)) {
        fn_800B7ADC(FeGetMgr(), x);
        return 1;
    }
    return 0;
}

FE_OVERLAY void fn_804A15C0(char* x)
{
    *(int*)(x + 0x144) = 1;
    *(int*)(x + 0x140) = 0;
    *(int*)(x + 0x14C) = 1;
    fn_8049E830(x, 1);
}

FE_OVERLAY void fn_804A15FC(char* x)
{
    ((FeW*)x)->fn_vslot32(lbl_805F758C, 1)->fn_vslot8(0);
    ((FeW*)x)->fn_vslot32(lbl_805F7504, 1)->fn_vslot8(0);
    ((FeW*)x)->fn_vslot32(lbl_805F7594, 1)->fn_vslot8(0);
    ((FeW*)x)->fn_vslot32(lbl_805F75A0, 1)->fn_vslot8(0);
}

FE_OVERLAY void fn_804A1724(int a, FeW* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    x->fn_vslot16(1);
    fn_8035682C(mp);
    switch (a) {
    case 0: {
        void** pg = &lbl_8061930C;
        int c0 = FeI(fn_800B555C(), 0xC0);
        int k = fn_80075948__18Unk8007B2B0_Screeni(*pg, c0);
        if (FeI(x, 0x170) != k) {
            fn_800A2188(lbl_80619948, k);
        } else {
            FeTrk t;
            fn_8054CBBC(&t, (int)fn_8007F7D0__FP13Unk8007F198_BUi(*pg, 0), *pg);
            fn_8054CBD8(&t, 0);
        }
        strncpy(mp->name, lbl_805F7664, 15);
        mp->name[15] = 0;
        x->fn_vslot80(1);
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    }
    case 1:
        if (FeI(fn_800B555C(), 0xC4) != 0) {
            void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
            fn_80131F34((FeW*)p, x, (void (*)(int, void*))fn_804A193C, (int)fn_80529158, 0x1AF7, 2, -1, 1, 0x26DE, 0x26DF, 0, 0, 0, 0);
            ((FeW*)p)->fn_vslot86();
            x->fn_vslot16(0);
        } else {
            fn_804A15C0((char*)x);
        }
        break;
    case 2:
        break;
    }
}

FE_OVERLAY void fn_804A193C(int a, FeW* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    switch (a) {
    case 0:
        strncpy(mp->name, lbl_805F766C, 15);
        mp->name[15] = a;
        x->fn_vslot80(1);
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    case 1:
        fn_8049F2E4(x);
        break;
    }
    x->fn_vslot16(0);
}

FE_OVERLAY void fn_804A256C(void* a, FeW* x)
{
    x->fn_vslot80(1);
    fn_800B7ADC(FeGetMgr(), x);
    if (fn_800D83A0() == 0) {
        void* t = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
        int n = fn_8007B3E0__18Unk8007B2B0_Screenii(lbl_8061930C, 0xF, t);
        fn_8007B4A8__18Unk8007B2B0_Screeniii(lbl_8061930C, 0xF, t, n == 0x1D ? 0 : n + 1);
    }
}

FE_OVERLAY void fn_804A2634(void* x, int a, int b)
{
    FeI(x, 0x17C) = a;
    FeI(x, 0x178) = fn_800B5520(b);
    fn_804A0B18(x);
}

FE_OVERLAY void fn_804A2674(FeW* x, int a)
{
    fn_800ED310(x, a);
    x->fn_vslot32(lbl_805F755C, 1)->fn_vslot14(a);
    if (FeI(x, 0x14C) != 0) {
        FeMem(x, 0x180)->fn_vslot32(lbl_805F5060, 1)->fn_vslot14(a);
    }
}

FE_OVERLAY void fn_804A2734(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY void fn_804A275C(void* x, int a)
{
    if (a == 0) {
        if (fn_800B5758(fn_800B555C()) != 0) {
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            strncpy(mp->name, lbl_805F76E0, 15);
            mp->name[15] = a;
            fn_800B7B4C(FeGetMgr(), mp, x);
        } else {
            fn_8001BC4C()->fn_8001BDAC(0xA3);
            if (FeI(x, 0x174) == 1) {
                fn_8049E830(x, 6);
            } else {
                fn_8049E830(x, 1);
            }
        }
    }
}

FE_OVERLAY void fn_804A282C(FeW* x)
{
    char buf[0x20];
    void* g = lbl_8061930C;
    int n;
    if (fn_8007F84C__FP13Unk8007F198_B(g) != 0) {
        n = fn_8007B3E0__18Unk8007B2B0_Screenii(g, 0xF, fn_8007F7D0__FP13Unk8007F198_BUi(g, 0)) % 3;
    } else {
        n = 0;
    }
    sprintf(buf, lbl_805F4ECC, n + 1);
    ((FeWQ*)fn_800C8040(x->fn_vslot30(lbl_805F76E8, 1)))->s30((int)buf);
    sprintf(buf, lbl_805F4ECC, 3);
    ((FeWQ*)fn_800C8040(x->fn_vslot30(lbl_805F76F4, 1)))->s30((int)buf);
}

FE_OVERLAY void fn_804A2964(void)
{
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    ((FeWQ*)w)->s85(0);
    FeGlobal80619948* g = lbl_80619948;
    FeI(w, 0x314) = 1;
    fn_800A2030(g, 1);
}

/* near-miss (47/48 ins): retail's ternary sets r3 and r4 in each arm and shares r31 with the lbl_8061A32C lis. */
FE_OVERLAY void fn_804A29F4(FeW* x)
{
    FeMsg m;
    FeMsg* p = &m;
    x->fn_vslot80(1);
    fn_8035682C(p);
    if (fn_800B5758(fn_800B555C()) == 1) {
        fn_8040B830(p->name, lbl_805F75B8, 15);
        p->name[15] = 0;
    } else {
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = 0;
    }
    fn_800B7B4C(FeGetMgr(), &m, x);
}

}
