/*
 * Front-end overlay code, .frontend_codeoverlay 0x8045B134-0x8045EDDC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"


extern "C" {
unsigned fn_8007F674__FP13Unk8007F198_Aii(void* g, int id);
int fn_8007F724__FP13Unk8007F198_Aiiii(void* g, int a, int b, int c, int d);
void fn_8007F5BC__FP13Unk8007F198_Aiiii(void* g, int a, int b, int c, int d);
void fn_8007F29C__FP13Unk8007F198_Aii(void* g, int a, int b);
int fn_800A2AE8(FeGlobal80619948* g);
}


extern void* lbl_8061977C;
extern const char lbl_805F4F0C[];
extern "C" {
const char* fn_80090880__FP11Unk80090880(void* t, int id);
unsigned fn_8007F198__FP13Unk8007F198_A(void* g, int id);
int fn_80078A64__18Unk8007A4DC_Screeniii(void* g, int a, int b, int c);
void fn_8007F61C__FP13Unk8007F198_Aiii(void* g, int a, int b, int c);
void fn_8007F330__FP13Unk8007F198_Aii(void* g, int a, int b);
void fn_801321D4(FeW* o, void* self, void (*cb)(int, void*), int (*cb2)(), const char* b, int c, int d, int e, const char* s1,
                 const char* s2, const char* s3, int f, int g, int h);
}


extern const char lbl_805F4F84[];
extern "C" {
void fn_80125084(void* w, int a);
int fn_8045C0FC(FeScrB* x);
}

struct FeW92 : Unk800C7B40_Data {
    virtual ~FeW92();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92(int a, int b, int c);
};
extern void* lbl_8061977C;
extern "C" const char* fn_80090880__FP11Unk80090880(void* t, int id);


struct FeArrL {
    char* m0;
    int m4;
    int m8;
    int mC;
    const void* m10;
    int m14;
};
extern const char lbl_8067B068[];
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A3B8[];
extern "C" {
void fn_8040074C(void* p, int n);
}

extern "C" {

FE_OVERLAY void fn_8045B4E8(void)
{
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY int fn_8045BC74(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_8045BCD0(FeScrB* x)
{
    x->m1B8->fn_vslot50();
    if (x->m1B8->fn_vslot60() == 1) {
        ((FeWV*)x->m1B8)->s101(0, 1);
        x->m1B8->fn_vslot68(0);
        ((FeWV*)x->m1B8)->s101(0, 0);
        x->m1B8->fn_vslot68(1);
    }
    fn_8045D338(x);
    fn_8045C8C0(x);
    return 1;
}

FE_OVERLAY int fn_8045BDD4(FeScrB* x)
{
    x->m1B8->fn_vslot52();
    fn_8045D338(x);
    fn_8045C8C0(x);
    return 1;
}

FE_OVERLAY int fn_8045BE2C(FeScrB* x)
{
    x->m1B8->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_8045BE68(FeScrB* x)
{
    x->m1B8->fn_vslot53();
    return 1;
}

FE_OVERLAY void fn_8045BEA4(FeScrB* x, int a)
{
    if (a == 0) {
        if (FeW24(x->m1EC) >= 0) {
            int id = x->m1B8->fn_vslot60();
            if (((FeWV*)x->m1B8)->s94(id, 2) != 0) {
                int r = fn_8045D420(x, id);
                FeList* l = x->m1EC;
                fn_80126CF4(l, l->m164, r, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                x->m1EC->fn_vslot84(1, 0);
                x->m1EC->fn_vslot8(1);
                x->m1B8->fn_vslot16(0);
                fn_8045D338(x);
            }
        } else {
            x->m1EC->fn_vslot84(2, 0);
            x->m1EC->fn_vslot8(0);
            x->m1B8->fn_vslot16(1);
            fn_8045D338(x);
        }
    }
}

FE_OVERLAY int fn_8045C04C(FeScrB* x, FeW* w, int b, int c)
{
    int r;
    if (w != x->m1B8) {
        r = 0;
    } else {
        w->fn_vslot68(c);
        fn_8045C8C0(x);
        fn_8045D338(x);
        r = 1;
    }
    return r;
}

FE_OVERLAY void fn_8045C0BC(FeScrB* x, int a, int b)
{
    x->m134 = b;
    fn_8045C79C(x);
    fn_8045C8C0(x);
    fn_8045D338(x);
}

FE_OVERLAY void fn_8045C38C(FeScrB* x, int a, int b)
{
    ((FeW92*)x->m1B8)->s92(a, 2, 0);
    x->m1B8->fn_vslot43(a, 5, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, b), 5);
    ((FeWV*)x->m1B8)->s101(a, 0);
}

FE_OVERLAY void fn_8045C79C(FeScrB* x)
{
    int n = fn_8045C0FC(x);
    x->m1BC->fn_vslot8(n > 0 ? 1 : 0);
    x->m1C0->fn_vslot8(n > 0 ? 1 : 0);
    if (n == 0) {
        FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F84);
        fn_80125084(p, 0);
        fn_80125084(p, 3);
    }
    x->m1B8->fn_vslot105(1);
    x->m1B8->fn_vslot14(1);
}

FE_OVERLAY void fn_8045D338(FeScrB* x)
{
    if (FeW24(x->m1EC) < 0) {
        fn_80125084(x->m1F0, 0);
        fn_801251CC(x->m1F0, 3, 0x37A2, 0);
    } else {
        fn_80125084(x->m1F0, 0);
        fn_80125084(x->m1F0, 3);
        int id = x->m1B8->fn_vslot60();
        if (((FeWV*)x->m1B8)->s94(id, 2) != 0) {
            fn_80125180(x->m1F0, 0, 0x10);
            fn_801251CC(x->m1F0, 3, 0x1A2F, 0);
        }
    }
    fn_80125100(x->m1F0);
}

FE_OVERLAY int fn_8045D420(FeScrB* x, int idx)
{
    int r = 0;
    int found = 0;
    int a = x->m138;
    a = a >? 1;
    int b = x->m13C;
    b = b >? 1;
    int c = x->m140;
    c = c >? 1;
    int k = idx - 1;
    if (k <= a) {
        r = x->m144[k];
        found = 1;
    }
    k -= a;
    k -= 1;
    if (found == 0 && k <= b) {
        r = x->m1A8[k];
        found = 1;
    }
    k -= b;
    k -= 1;
    if (found == 0 && k <= c) {
        r = x->m1B0[k];
        found = 1;
    }
    if (found == 0) {
        return 0;
    }
    return r;
}

FE_OVERLAY void fn_8045D4D8(int which, FeScrB* x)
{
    int id = fn_8045D420(x, x->m1B8->fn_vslot60());
    switch (x->m1F4[which]) {
    case 0:
        fn_8045D5B0(x, id);
        break;
    case 1:
        fn_8045D71C(x, id, 0);
        break;
    case 2:
        fn_8045D71C(x, id, 1);
        break;
    }
    fn_8045C79C(x);
    fn_8045C8C0(x);
    fn_8045D338(x);
}

FE_OVERLAY int fn_8045D5A8(void) { return 1; }

FE_OVERLAY void fn_8045D5B0(FeScrB* x, int a)
{
    void* g = lbl_8061930C;
    if (fn_8007F198__FP13Unk8007F198_A(g, x->m134) > 0x18U) {
        FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
        const char* s0 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x462E);
        const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x26DE);
        fn_801321D4(p, x, (void (*)(int, void*))fn_8045D4D8, (int (*)())fn_8045D5A8, s0, 1, -1, 1, s1, 0, 0, 0, 0, 0);
        x->m1F4[0] = 3;
        x->m1F4[1] = 3;
        x->m1F4[2] = 3;
        x->m200 = 3;
        p->fn_vslot86();
    } else {
        for (int i = 0; i <= 1; i++) {
            if (fn_80078A64__18Unk8007A4DC_Screeniii(g, x->m134, i, a) != 0) {
                fn_8007F61C__FP13Unk8007F198_Aiii(g, x->m134, i, a);
                fn_8007F330__FP13Unk8007F198_Aii(g, x->m134, a);
                break;
            }
        }
    }
}

/* near-miss: retail tests i == 0 twice (a second bne on the same cc) and copies b (r25) before the m134 load */
FE_OVERLAY void fn_8045D71C(FeScrB* x, int a, int b)
{
    void* g = lbl_8061930C;
    if (fn_8007F674__FP13Unk8007F198_Aii(g, x->m134) > 1U) {
        int r = fn_80078A64__18Unk8007A4DC_Screeniii(g, x->m134, b, a);
        if (r == 0) {
            FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
            const char* s0 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x462F);
            const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x26DE);
            fn_801321D4(p, x, (void (*)(int, void*))fn_8045D4D8, (int (*)())fn_8045D5A8, s0, 1, -1, 1, s1, 0, 0, 0, 0, 0);
            x->m1F4[0] = 3;
            x->m1F4[1] = 3;
            x->m1F4[2] = 3;
            x->m200 = 3;
            p->fn_vslot86();
            return;
        }
    }
    int found = 0;
    int d = 0;
    for (int i = 0; i <= 1; i++) {
        if (fn_80078A64__18Unk8007A4DC_Screeniii(g, x->m134, i, a) != 0) {
            if (i == 0 && b == 1) {
                d = 0xF - fn_8007F724__FP13Unk8007F198_Aiiii(g, x->m134, 0, a, fn_800A2AE8(lbl_80619948));
            }
            fn_8007F61C__FP13Unk8007F198_Aiii(g, x->m134, i, a);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        fn_8007F29C__FP13Unk8007F198_Aii(g, x->m134, a);
    }
    fn_8007F5BC__FP13Unk8007F198_Aiiii(g, x->m134, b, a, fn_800A2AE8(lbl_80619948) - d);
}

FE_OVERLAY FeScrD* fn_8045D920(FeScrD* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    FeArrL* s = (FeArrL*)((char*)self + 0x188);
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067B068);
    self->m130 = 0;
    self->m140 = 0;
    self->m168 = 0;
    self->m16C = 0;
    s->m10 = lbl_8064B298;
    s->m0 = (char*)self + 0x1A0;
    s->m8 = 0xCB2;
    fn_8040074C(s->m0, 0x32C8);
    s->m4 = 0;
    s->mC = 0;
    s->m10 = lbl_8064A550;
    fn_8040074C(s->m0, s->m8 * 4);
    s->m4 = 0;
    s->mC = 0;
    s->m14 = 0;
    s->m10 = lbl_8064A3B8;
    self->m6730[25] = 0;
    self->m6730[26] = 0;
    self->m6730[27] = 0;
    self->m6730[28] = 0;
    self->m6730[29] = 0;
    self->m67A8 = 0;
    self->m67B8 = 0;
    self->m67BC = 1;
    return self;
}

FE_OVERLAY void fn_8045EBBC(FeScrD* x)
{
    int v = ((FeSub*)((char*)x->m154 + 0xDC))->s5();
    fn_800B555C()->m57C = v;
}

FE_OVERLAY void fn_8045EC0C(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY void fn_8045EC34(FeScrD* x, int kind)
{
    switch (kind) {
    case 0:
        fn_804615DC(x);
        break;
    case 1:
        fn_804617C8(x);
        break;
    case 2:
        fn_80461910(x);
        break;
    case 3:
        fn_80461A14(x);
        break;
    case 4:
        fn_80461B18(x);
        break;
    case 5:
        fn_80461BF8(x);
        break;
    case 6:
        fn_80461D0C(x);
        break;
    case 7:
        fn_80461DB8(x);
        break;
    case 8:
        fn_80461E5C(x);
        break;
    }
}

FE_OVERLAY int fn_8045ECEC(FeScrD* x)
{
    x->m14C->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_8045ED28(FeScrD* x)
{
    x->m14C->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_8045ED64(FeScrD* x)
{
    x->m14C->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_8045EDA0(FeScrD* x)
{
    x->m14C->fn_vslot53();
    return 1;
}

}
