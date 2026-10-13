/*
 * Front-end overlay code, .frontend_codeoverlay 0x804A2AB4-0x804A721C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" void fn_804A3698(void* x, int a);
extern const char lbl_805F5828[];
extern const char lbl_805F4ECC[];
extern "C" int sprintf(char*, const char*, ...);
extern "C" int fn_8007DF5C__FP13Unk8007DB74_Aiii(void* g, int a, int b, int c);
extern "C" void fn_800E0C38(void* w, int a, int b, int c);
extern const char lbl_805F77C4[];
extern const char lbl_805F59C4[];
extern const char lbl_805F770C[];
extern const char lbl_805F632C[];
extern const char lbl_805F7818[];
#define FEW4S_(n) virtual void s##n(int a, int b, char* c, int d);
struct FeW4S : Unk800C7B40_Data {
    virtual ~FeW4S();
    FEW4S_(2) FEW4S_(3) FEW4S_(4) FEW4S_(5) FEW4S_(6) FEW4S_(7) FEW4S_(8) FEW4S_(9) FEW4S_(10) FEW4S_(11) FEW4S_(12) FEW4S_(13) FEW4S_(14) FEW4S_(15) FEW4S_(16) FEW4S_(17) FEW4S_(18) FEW4S_(19) FEW4S_(20) FEW4S_(21) FEW4S_(22) FEW4S_(23) FEW4S_(24) FEW4S_(25) FEW4S_(26) FEW4S_(27) FEW4S_(28) FEW4S_(29) FEW4S_(30) FEW4S_(31) FEW4S_(32) FEW4S_(33) FEW4S_(34) FEW4S_(35) FEW4S_(36) FEW4S_(37) FEW4S_(38) FEW4S_(39) FEW4S_(40) FEW4S_(41) FEW4S_(42) FEW4S_(43) FEW4S_(44) FEW4S_(45) FEW4S_(46) FEW4S_(47) FEW4S_(48) FEW4S_(49)
};
extern "C" int fn_8007DC08__FP13Unk8007DB74_AiiiPi(void* g, int a, int b, int c, int* out);
extern "C" int fn_800E5E4C(int a);
int fn_800DE1C4(char* buf, int a);
extern "C" int fn_800739E0__18Unk8007A4DC_Screeniiii(void* g, int a, int b, int c, int d);
extern "C" float fn_80073C10(void* g, int a, int b, int c, int d);
extern "C" void fn_80119F48(char* buf, float f);
char* fn_800DF034(char* buf);
extern "C" int fn_8007A984__18Unk8007A4DC_Screeni(void* g, int a);
int fn_80084014(int a, int b);
extern const char lbl_805F5828[];
extern "C" int fn_800A2E6C(void* g);
extern "C" int fn_800A2E90(void* g);
int fn_800E4FDC(void);
extern const char lbl_805F64F0[];
extern const char lbl_805F664C[];
extern const char lbl_805F653C[];
extern const char lbl_805F6548[];
extern const char lbl_805F77F8[];
extern const char lbl_805F5348[];
struct Udd344_T;
void fn_800DD344(Udd344_T*, void*);
extern "C" int fn_8032A0C0(char*, ...);
extern "C" int fn_8007FBDC__FP13Unk8007F198_Cii(void* g, int a, int b);
extern "C" void fn_800D0074(void* a, int b, int c);
extern "C" void fn_804A5E8C(FeW* x);
extern const char lbl_805F7824[];
extern const char lbl_805F5364[];
struct UiS;
struct Unk800D7008_Obj;
Unk800D7008_Obj* fn_800D6FA0(void);
float fn_800D7008(Unk800D7008_Obj*, int);
void fn_800DC580(UiS*, float);
extern "C" void fn_8055AC44(void*, int);
extern "C" void fn_800DD800(void*, void*, int, int);
extern "C" int fn_800D83C8(int* p);
struct FeSubM6 : FeSubBD {
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6(int a);
};
extern "C" {

FE_OVERLAY FeScrH* fn_804A2AB4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80674B20);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    return self;
}

FE_OVERLAY void fn_804A2B04(FeW* x)
{
    fn_800ECF18(x);
    void* nav = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(nav, x);
    fn_80125100(nav);
    fn_801250D8(nav);
    if (fn_800A2E6C(lbl_80619948) != 0) {
        FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), "FTOPBAR");
        p->fn_vslot8(0);
        fn_804A7760(p);
    }
    int a = 1;
    int b = 1;
    if (fn_800B57EC(fn_800B555C()) != 0) {
        FeP(x, 0x134) = fn_800C8060(x->fn_vslot32("FRANCHISE", 1));
        x->fn_vslot32("SEASON", 1)->fn_vslot8(0);
    } else {
        FeP(x, 0x134) = fn_800C8060(x->fn_vslot32("SEASON", 1));
        x->fn_vslot32("FRANCHISE", 1)->fn_vslot8(0);
    }
    FeMem(x, 0x134)->fn_vslot8(1);
    if (fn_800A2E90(lbl_80619948) == 0 && fn_800A2E6C(lbl_80619948) == 0)
        a = 0;
    if (fn_800E4FDC() == 0) {
        a = 0;
        b = 0;
    }
    if (a == 0) {
        ((FeW3*)FeMem(x, 0x134))->s91(0, 0, 0);
        ((FeWQ*)FeMem(x, 0x134))->s68(1);
    }
    if (b == 0)
        ((FeW3*)FeMem(x, 0x134))->s91(2, 0, 0);
}

FE_OVERLAY int fn_804A2DBC(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

FE_OVERLAY int fn_804A2E28(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_804A2E84(void* x)
{
    FeMem(x, 0x134)->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804A2EC0(void* x)
{
    FeMem(x, 0x134)->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_804A2EFC(void* x)
{
    FeMem(x, 0x134)->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804A2F38(void* x)
{
    FeMem(x, 0x134)->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804A2F74(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

struct FeScrN : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
    FeW* m138;
    FeW* m13C;
    FeW* m140;
    FeW* m144;
    FeW* m148;
    FeW* m14C;
    FeW* m150;
    FeW* m154;
    FeW* m158;
    FeW* m15C;
    FeW* m160;
    FeW* m164;
    FeW* m168;
    FeW* m16C;
    FeW* m170;
    FeW* m174;
    FeW* m178;
    FeW* m17C;
    FeW* m180;
    FeW* m184;
    FeW* m188;
    FeW* m18C;
    FeW* m190;
};

extern "C" FE_OVERLAY void fn_804A2FD0(FeScrN* x, char* dst)
{
    fn_8040B830(dst, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC, 16);
}


extern const char lbl_80674878[];
FE_OVERLAY FeScrH* fn_804A3044(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80674878);
    self->m130 = 0;
    return self;
}

FE_OVERLAY void fn_804A3090(FeScrD* x)
{
    fn_800ECE34(x);
}

FE_OVERLAY void fn_804A30B0(FeW* x)
{
    fn_800ECF18(x);
    void* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_801250D8(p);
    FeP(x, 0x134) = fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
    int k = fn_800B5520((int)fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0));
    ((FeSubM6*)((char*)fn_800C8054(x->fn_vslot32(lbl_805F632C, 1)) + 0x98))->s6(k);
    int sp;
    int r = fn_800D83C8(&sp);
    FeI(x, 0x138) = r;
    if (r != 0) {
        FeI(fn_800B555C(), 0xC0) = sp;
    }
}

FE_OVERLAY void fn_804A31D8(FeScrD* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY void fn_804A31F8(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY void fn_804A3218(void) {}

FE_OVERLAY void fn_804A321C(void) {}

FE_OVERLAY void fn_804A3220(void) {}

FE_OVERLAY int fn_804A3224(FeW* x)
{
    if (FeI(x, 0x138) != 0) {
        fn_800B7ADC(FeGetMgr(), x);
    } else {
        fn_80131F34(FeMem(x, 0x134), x, (void (*)(int, void*))fn_804A32F4, (int)fn_804A334C, 0x38CF, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
        ((FeWI*)FeMem(x, 0x134))->s86();
    }
    return 1;
}

FE_OVERLAY void fn_804A32F4(void* a, void* b)
{
    fn_800B7ADC(FeGetMgr(), b);
}

FE_OVERLAY int fn_804A334C(void) { return 0; }

FE_OVERLAY int fn_804A3354(void) { return 0; }

FE_OVERLAY void fn_804A335C(void* x, char* dst)
{
    const char* s = FeI(x, 0x138) ? lbl_805F763C : lbl_805F7648;
    fn_8040B830(dst, s, 16);
}

FE_OVERLAY FeScrH* fn_804A33A4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    /* near-miss (2 slots: the stw 0x134/0x138 pair swapped): all 720 orders of these six statements
     * with a shared int zero tried; the float needs an extern const float to hoist its lfs. */
    int z = 0;
    self->SetVptr(lbl_80682260);
    self->m130 = z;
    FeI(self, 0x138) = z;
    FeI(self, 0x134) = z;
    *(float*)((char*)self + 0x10E0) = lbl_805F7708;
    *(short*)((char*)self + 0x140) = z;
    return self;
}

FE_OVERLAY void fn_804A3408(FeW* x)
{
    fn_800ECE34(x);
    FeI(x, 0x13C) = (int)fn_800C8040(x->fn_vslot32(lbl_805F770C, 1));
    if (fn_800B57EC(fn_800B555C()) == 0) {
        FeI(x, 0x138) = 1;
        fn_804A3698(x, 0);
        x->fn_vslot8(0);
    } else {
        int s = ((FeStateY*)fn_800B555C())->m28;
        int t = ((FeStateY*)fn_800B555C())->m2C;
        if (t == 0) {
            fn_804A3698(x, 2);
        } else {
            fn_804A3698(x, t);
            FeI(x, 0x10E4) = s;
        }
        FeI(x, 0x138) = 0;
    }
    x->fn_vslot4();
}

FE_OVERLAY void fn_804A34F8(FeW* x)
{
    fn_800ECF18(x);
    ((FeWV*)x)->s40();
}

FE_OVERLAY void fn_804A353C(FeW* x)
{
    fn_800ECAA4(x);
    if (FeI(x, 0x138) == 0) {
        FeGetMgr();
        FeMem(x, 0x13C)->fn_vslot9(FeI(x, 0x10E4));
        ((FeWQ*)FeMem(x, 0x13C))->s28((int)((char*)x + 0x140));
        FeI(x, 0x10E4) = FeI(x, 0x10E4) - 1;
        if (!((float)FeI(x, 0x10E4) >= -*(float*)((char*)x + 0x10E0))) {
            FeI(x, 0x10E4) = 0x27F;
            switch (FeI(x, 0x134)) {
            case 2:
                fn_804A3698(x, 3);
                break;
            case 3:
                fn_804A3698(x, 2);
                break;
            }
        }
    }
}

FE_OVERLAY void fn_804A3658(void* x)
{
    ((FeStateY*)fn_800B555C())->m2C = FeI(x, 0x134);
    ((FeStateY*)fn_800B555C())->m28 = FeI(x, 0x10E4);
}

FE_OVERLAY void fn_804A4000(void* x)
{
    switch (FeI(x, 0x134)) {
    case 2:
        fn_804A3698(x, 3);
        break;
    case 3:
        fn_804A3698(x, 2);
        break;
    }
}

FE_OVERLAY FeScrH* fn_804A4048(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806745D0);
    self->m130 = 0;
    FeI(self, 0x134) = -1;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x210) = 0;
    FeI(self, 0x218) = 0;
    FeI(self, 0x21C) = 0;
    FeI(self, 0x220) = 0;
    FeI(self, 0x224) = 0;
    FeI(self, 0x228) = 0;
    FeI(self, 0x22C) = 0;
    FeI(self, 0x230) = 0;
    FeI(self, 0x234) = 0;
    FeI(self, 0x238) = 0;
    FeI(self, 0x23C) = 0;
    FeI(self, 0x240) = 0;
    FeI(self, 0x244) = 0;
    FeI(self, 0x248) = 1;
    FeI(self, 0x24C) = 0;
    return self;
}

FE_OVERLAY void fn_804A40EC(FeScrD* x)
{
    fn_800ECE34(x);
}

FE_OVERLAY void fn_804A410C(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY void fn_804A4AA8(void* x, int a, void* c)
{
    fn_804A4558(x, c);
    fn_804A560C(x);
    fn_804A5854(x, FeI(x, 0x210));
}

FE_OVERLAY void fn_804A4AEC(void* x)
{
    fn_800ECAA4(x);
    FeW* a = FeMem(x, 0x23C);
    if (FeW24(a) < 0 && FeI(x, 0x210) != 1) {
        a->fn_vslot8(0);
    }
    FeW* b = FeMem(x, 0x240);
    if (FeW24(b) < 0 && (unsigned)FeI(x, 0x210) <= 1) {
        b->fn_vslot8(0);
    }
}

FE_OVERLAY void fn_804A4B88(FeW* x, FeW* w, int d)
{
    if (w == fn_800C805C(fn_800C8044(x->fn_vslot32(lbl_805F77C4, 1))->fn_vslot32(lbl_805F59C4, 1))) {
        if (d == 1) {
            int k = FeI(x, 0x210);
            if (k <= 4) {
                fn_804A5854(x, k + 1);
            } else {
                fn_804A5854(x, 0);
            }
        } else {
            int k = FeI(x, 0x210);
            if (k > 0) {
                fn_804A5854(x, k - 1);
            } else {
                fn_804A5854(x, 5);
            }
        }
        fn_804A560C(x);
    }
    FeI(x, 0x24C) = 0;
}

FE_OVERLAY int fn_804A4F98(FeW* x, FeW* w, int a, int k)
{
    FeW* t = FeMem(x, 0x220);
    if (t == w && FeW24(FeP(x, 0x21C)) >= 0) {
        FeW* r = fn_800C8044(x->fn_vslot32(lbl_805F5828, 1));
        t->fn_vslot68(k);
        fn_800E0C38(r, fn_8007DF5C__FP13Unk8007DB74_Aiii(lbl_8061930C, FeI(x, 0x13C), FeI(x, 0x214), k), 2, 1);
        if (k != FeI(x, 0x24C)) {
            fn_8001BC4C()->fn_8001BDAC(0x99);
            FeI(x, 0x24C) = k;
        }
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_804A507C(void* x)
{
    int r;
    if (FeI(x, 0x13C) == 0 || FeW24(FeP(x, 0x21C)) < 0) {
        r = 0;
    } else {
        FeMem(x, 0x224)->fn_vslot40(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A50E0(void* x)
{
    int r;
    if (FeI(x, 0x13C) == 0 || FeW24(FeP(x, 0x21C)) < 0) {
        r = 0;
    } else {
        ((FeWV*)FeMem(x, 0x224))->s41();
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A5140(void* x)
{
    int r;
    if (FeI(x, 0x13C) == 0 || FeW24(FeP(x, 0x21C)) < 0) {
        r = 0;
    } else {
        FeMem(x, 0x224)->fn_vslot38(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A51A4(void* x)
{
    int r;
    if (FeI(x, 0x13C) == 0 || FeW24(FeP(x, 0x21C)) < 0) {
        r = 0;
    } else {
        FeMem(x, 0x224)->fn_vslot39();
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A5204(void* x)
{
    if (FeI(x, 0x13C) != 0) {
        int k = FeI(x, 0x210);
        if ((unsigned)(k - 2) <= 3) {
            if (FeW24(FeP(x, 0x21C)) < 0) {
                return 0;
            }
            FeW* r = fn_800C8044(((FeW*)x)->fn_vslot32(lbl_805F5828, 1));
            FeMem(x, 0x220)->fn_vslot50();
            int u = ((FeWI*)FeMem(x, 0x220))->s60();
            fn_800E0C38(r, fn_8007DF5C__FP13Unk8007DB74_Aiii(lbl_8061930C, FeI(x, 0x13C), FeI(x, 0x214), u), 2, 1);
            return 1;
        }
        if (k == 0) {
            if (FeI(x, 0x248) != 0) {
                FeMem(x, 0x228)->fn_vslot50();
                FeMem(x, 0x228)->fn_vslot14(1);
            }
            return 1;
        }
    }
    return 0;
}

FE_OVERLAY int fn_804A5348(void* x)
{
    if (FeI(x, 0x13C) != 0) {
        int k = FeI(x, 0x210);
        if ((unsigned)(k - 2) <= 3) {
            FeMem(x, 0x220)->fn_vslot51();
            return 1;
        }
        if (k == 0) {
            if (FeI(x, 0x248) != 0) {
                FeMem(x, 0x228)->fn_vslot51();
                FeMem(x, 0x228)->fn_vslot14(1);
            }
            return 1;
        }
    }
    return 0;
}

FE_OVERLAY int fn_804A5408(void* x)
{
    if (FeI(x, 0x13C) != 0) {
        int k = FeI(x, 0x210);
        if ((unsigned)(k - 2) <= 3) {
            if (FeW24(FeP(x, 0x21C)) < 0) {
                return 0;
            }
            FeW* r = fn_800C8044(((FeW*)x)->fn_vslot32(lbl_805F5828, 1));
            FeMem(x, 0x220)->fn_vslot52();
            int u = ((FeWI*)FeMem(x, 0x220))->s60();
            fn_800E0C38(r, fn_8007DF5C__FP13Unk8007DB74_Aiii(lbl_8061930C, FeI(x, 0x13C), FeI(x, 0x214), u), 2, 1);
            return 1;
        }
        if (k == 0) {
            if (FeI(x, 0x248) != 0) {
                FeMem(x, 0x228)->fn_vslot52();
                FeMem(x, 0x228)->fn_vslot14(1);
            }
            return 1;
        }
    }
    return 0;
}

FE_OVERLAY int fn_804A554C(void* x)
{
    if (FeI(x, 0x13C) != 0) {
        int k = FeI(x, 0x210);
        if ((unsigned)(k - 2) <= 3) {
            FeMem(x, 0x220)->fn_vslot53();
            return 1;
        }
        if (k == 0) {
            if (FeI(x, 0x248) != 0) {
                FeMem(x, 0x228)->fn_vslot53();
                FeMem(x, 0x228)->fn_vslot14(1);
            }
            return 1;
        }
    }
    return 0;
}


FE_OVERLAY void fn_804A560C(void* xx)
{
    FeW* x = (FeW*)xx;
    char b8[0x68];
    char b70[8];
    if (FeI(x, 0x218) != 0) {
        int s = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x13C));
        ((int (*)(char*, ...))fn_8032A0C0)(b70, fn_8007FBDC__FP13Unk8007F198_Cii(lbl_8061930C, FeI(x, 0x134), s));
        fn_804A5E8C(x);
        FeW* p = fn_800C8044(x->fn_vslot32(lbl_805F64F0, 1));
        FeW* w = fn_800C8054(p->fn_vslot32(lbl_805F664C, 1));
        FeP(x, 0x22C) = w;
        fn_800D0074((char*)w + 0x98, s, 0);
        FeW* w1 = FeMem(x, 0x22C);
        ((FeSubB*)((char*)w1 + 0x98))->s20(FeI(x, 0x13C), 0);
        FeW* w2 = fn_800C8054(p->fn_vslot32(lbl_805F77F8, 1));
        FeP(x, 0x230) = w2;
        ((FeSubB*)((char*)w2 + 0x98))->s20(FeI(x, 0x13C), 0);
        FeW* w3 = fn_800C8054(p->fn_vslot32(lbl_805F653C, 1));
        FeP(x, 0x234) = w3;
        ((FeSubB*)((char*)w3 + 0x98))->s20(FeI(x, 0x13C), 0);
        FeW* w4 = fn_800C8054(p->fn_vslot32(lbl_805F6548, 1));
        FeP(x, 0x238) = w4;
        ((FeSubB*)((char*)w4 + 0x98))->s20(FeI(x, 0x13C), 0);
        fn_800DD344((Udd344_T*)b70, b8);
        ((FeWQ*)fn_800C8040(p->fn_vslot32(lbl_805F5348, 1)))->s28((int)b8);
    }
}

FE_OVERLAY void fn_804A5E8C(FeW* x)
{
    fn_800C8044(x->fn_vslot32(lbl_805F7818, 1))->fn_vslot8(1);
    if (FeI(x, 0x218) == 1) {
        float f = fn_800D7008(fn_800D6FA0(), FeI(x, 0x13C));
        fn_800DC580((UiS*)fn_800C8044(fn_800C8044(x->fn_vslot32(lbl_805F7818, 1))->fn_vslot32(lbl_805F5364, 1)), f);
    } else {
        x->fn_vslot32(lbl_805F7818, 1)->fn_vslot8(0);
    }
    FeW* w = fn_800C8044(x->fn_vslot32(lbl_805F7824, 1));
    if (FeI(x, 0x218) == 1) {
        char sp10[0x460];
        char* p = sp10;
        fn_8055AC44(p, fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x13C)));
        fn_800DD800(w, p, FeI(x, 0x13C), 0);
        w->fn_vslot8(1);
    } else {
        w->fn_vslot8(0);
    }
}


FE_OVERLAY void fn_804A6EE8(FeW* x, int arg)
{
    char buf[0x190];
    char nm[0x50];
    float f;
    int ro;
    int first = 0;
    int row = 0;
    int w23 = (int)fn_800C8044(x->fn_vslot32(lbl_805F5828, 1));
    FeW* tbl = FeMem(x, 0x220);
    FeI(x, 0x214) = arg;
    ((FeWQ*)tbl)->s105(1);
    int t = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, FeI(x, 0x13C));
    int d = fn_80084014(t, 1);
    do {
        int id = fn_8007DF5C__FP13Unk8007DB74_Aiii(lbl_8061930C, FeI(x, 0x13C), FeI(x, 0x214), row);
        if (row == 0)
            first = id;
        int nr = row + 1;
        sprintf(buf, lbl_805F4ECC, nr);
        ((FeW4S*)FeMem(x, 0x220))->s44(row, 0, buf, 5);
        fn_8007DC08__FP13Unk8007DB74_AiiiPi(lbl_8061930C, FeI(x, 0x13C), id, FeI(x, 0x214), &ro);
        sprintf(buf, "%s", fn_800E5E4C(ro));
        ((FeW4S*)FeMem(x, 0x220))->s44(row, 1, buf, 5);
        fn_800DE440(nm, id, 1);
        ((FeW4S*)FeMem(x, 0x220))->s43(row, 2, nm, 5);
        fn_800DE1C4(nm, id);
        ((FeW4S*)FeMem(x, 0x220))->s43(row, 3, nm, 5);
        sprintf(buf, lbl_805F4ECC, fn_800739E0__18Unk8007A4DC_Screeniiii(lbl_8061930C, 0, id, d, 2));
        ((FeW4S*)FeMem(x, 0x220))->s44(row, 4, buf, 5);
        f = fn_80073C10(lbl_8061930C, 2, id, d, 2);
        fn_80119F48(buf, f);
        ((FeW4S*)FeMem(x, 0x220))->s44(row, 5, fn_800DF034(buf), 5);
        sprintf(buf, "%d%%", fn_8007A984__18Unk8007A4DC_Screeni(lbl_8061930C, id));
        FeW* tb2 = FeMem(x, 0x220);
        int r0 = row;
        row = nr;
        ((FeW4S*)tb2)->s44(r0, 6, buf, 5);
    } while (row <= 8);
    ((FeWQ*)FeMem(x, 0x220))->s68(0);
    fn_800E0C38((void*)w23, first, 2, 1);
}

}
