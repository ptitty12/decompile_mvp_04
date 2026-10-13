/*
 * Front-end overlay code, .frontend_codeoverlay 0x80520BE0-0x805283C4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"
/* Widget view whose vtable slot 19 (+0x98) returns a float (fn_80525390 compares it with lbl_805FC4BC). */
class FeVF19 {
public:
    char pad0[0x3C];
    virtual void s1();
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
    virtual float s19();
};
extern "C" void fn_80525498(FeScrN* x, int mode);
extern float lbl_805FC4BC;
extern "C" void fn_800ECAA4(void* self);
struct FeScr2DC : FeScrN {
    char pad194[0x2DC - 0x194];
    int m2DC;
    int m2E0;
    int m2E4;
    float m2E8;
    int m2EC;
    int m2F0;
    int m2F4;
    int m2F8;
    int m2FC;
    int m300;
    int m304;
    int m308;
    int m30C;
    int m310;
    int m314[3];
    int m320[3];
    int m32C;
    int m330;
};
extern "C" int fn_800B5634(void* st);
extern "C" void fn_800E63A4__FP6Ue63A4(void* p);
extern "C" void fn_804D3CA8(void* x, int a);
extern int lbl_8061A308;
extern const char* lbl_80622650[];
extern const char lbl_8067EBE8[];
extern "C" int fn_8007A1D8__18Unk8007A4DC_Screeni(void* g, int a);
extern "C" int fn_800DE440(char* out, int a, int b);
extern "C" void fn_804D3D54(void* x);
extern "C" void fn_804D2DC0(void* x, int v);
extern "C" FeW* fn_800C806C(void);
extern "C" void fn_800EC1E8__FPv(void* x);
extern const char lbl_805FC0B8[];
extern const float lbl_805FC0B4;
extern "C" void* fn_8051F470(FeV10* x);

inline float& FeF(void* x, int off)
{
    return *(float*)((char*)x + off);
}

extern "C" void fn_800C62B8(void* self, int a, int b, char* c, int d, float e);
extern char lbl_80622800[];
extern "C" void fn_80522A94(void* x, int a, int b, int c);
extern "C" int fn_804D32A0(void* x);
extern "C" int fn_804D3B18(void* x, int a);
extern "C" void fn_80087A50__FP13Unk80084910_Si(void* s, int i);
extern "C" void fn_80524ABC(void* x, int mode);
extern "C" void fn_804D2F38(void* x);
extern "C" void fn_804D2F9C(void* x);
extern "C" void fn_804D3000(void* x);
extern "C" void fn_804D304C(void* x);
extern "C" void fn_804D3098(void* x);
extern const char lbl_805FC448[];
extern const char lbl_805FC43C[];

extern const char lbl_80667638[];
extern const char lbl_80667650[];
extern const char lbl_80669498[];
extern const char lbl_806694B0[];
extern const char lbl_80669780[];
extern const char lbl_80669CF8[];
extern const char lbl_80669FA0[];
extern const char lbl_8067A190[];
extern const char lbl_8067A1A8[];
extern "C" void fn_80523A90(void* x, int a);
extern "C" void fn_80524B54(FeW* x);
extern "C" void fn_804D34A0(void* x);
extern "C" void fn_8040B61C(void* p);
extern "C" void fn_80524408(void* x, int a);
extern "C" void fn_800EC208__FP3UiS(void* x);
extern "C" void* fn_8007FE04__FP13Unk8007F198_D(void* p);
extern "C" void fn_80087B10__Fv();
extern "C" void fn_800C5E28();
extern "C" void fn_800C618C();
extern "C" void fn_80134E38(void* p, int c);
extern const char lbl_8062265C[];
extern const char lbl_806226D4[];
extern "C" FeSingle* fn_805210A0(void);
extern "C" void fn_805210EC(void);
extern "C" int fn_80522890(FeSingle* x, unsigned i);
extern "C" void fn_805228DC(FeSingle* x);
extern "C" void fn_80522A74(FeScrD* x);
extern "C" int fn_8052388C(void* x, int a);
extern "C" int fn_805238EC(void* x, int a);
extern "C" int fn_8052390C(void* x, int a);
extern "C" int fn_80523960(void* x, int a);
extern "C" int fn_805239B4(void* x, int a);
extern "C" int fn_80523A08(void* x, int a);
extern "C" int fn_80523A5C(void* x, int a, int b, int c, int d);
extern "C" void fn_805243C4(void* x);
extern "C" FeScrN* fn_805244C8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_805246C4(FeScrG* x);
extern "C" FeScrN* fn_80524708(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80524850(void);
extern "C" void fn_80524BE8(void* x);
extern "C" FeScrN* fn_80524C1C(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80524C94(void* x);
extern "C" void fn_805255F8(void);
extern "C" FeScrH* fn_80525624(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80520C0C(FeV10B* x);
extern "C" void fn_80520C60(FeV10B* x);

//@80520BE0
FE_OVERLAY FeRecB::FeRecB(int a, int b)
{
    int k = 0x19;
    m4 = a;
    m0 = -1;
    m8 = b;
    mC = k;
    m10 = lbl_8067A1A8;
}

extern "C" FE_OVERLAY void fn_80520C0C(FeV10B* x)
{
    int v = fn_8051E910(x->m4, lbl_80622648);
    x->s3(v);
}

extern "C" FE_OVERLAY void fn_80520C60(FeV10B* x)
{
    fn_8051EDDC(x->m4, lbl_80622648, x->s2());
}

extern "C" FE_OVERLAY void fn_80520CBC(FeV10D* x)
{
    char buf[256];
    if (x->m14 != 0 && fn_8007A1D8__18Unk8007A4DC_Screeni(lbl_8061930C, x->m14) != 0) {
        fn_800DE440(buf, x->m14, 1);
        ((FeWV*)fn_8051F4D8(x))->s28(buf);
        return;
    }
    ((FeWV*)fn_8051F4D8(x))->s29(0x557);
}

extern "C" FE_OVERLAY void fn_80520FF8(FeV10* x)
{
    ((FeWV*)fn_8051F470(x))->s29(x->m8);
    void* w = fn_8051F4D8(x);
    ((FeSub24*)((char*)w + 0xDC))->s15();
    ((FeWV*)w)->s51(8, 0);
    x->s11();
}

extern "C" FE_OVERLAY FeSingle* fn_805210A0(void)
{
    if (lbl_8062264C == 0) {
        lbl_8062264C = new (0) FeSingle;
    }
    return lbl_8062264C;
}

/* near-miss: delete through the virtual dtor loads the pfn before the delta (lwz/lha swapped) */
extern "C" FE_OVERLAY void fn_805210EC(void)
{
    if (lbl_8062264C != 0) {
        delete (FeSingleV*)lbl_8062264C;
        lbl_8062264C = 0;
    }
}

//@80521144
FE_OVERLAY FeSingle::FeSingle()
{
    mB8 = lbl_8067A190;
    mA8 = 0;
    mAC = 0;
    mB0 = 0;
    mB4 = 0;
    for (int i = 0; i < 42; i++) {
        m0[i] = 0;
    }
}

extern "C" FE_OVERLAY int fn_80522890(FeSingle* x, unsigned i)
{
    if (i <= 0x29) {
        return x->m0[i];
    }
    if (i == 0x50) {
        return x->mAC;
    }
    if (i == 0x51) {
        return x->mB0;
    }
    if (i == 0x53) {
        return x->mB4;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_805228DC(FeSingle* x)
{
    for (int i = 0; i < 42; i++) {
        x->m0[i] = 0;
    }
    x->mA8 = 0;
    x->mAC = 0;
}

extern "C" FE_OVERLAY FeScr2DC* fn_80522904(FeScr2DC* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC150(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067EBE8);
    self->m2DC = 0;
    self->m2E0 = 0;
    self->m2E4 = -1;
    self->m2E8 = lbl_805FC0B4;
    self->m2EC = 0;
    self->m2F0 = 0;
    self->m2F4 = 0;
    self->m2F8 = 0;
    self->m2FC = 0;
    self->m300 = 0;
    self->m304 = 0;
    self->m308 = 0;
    self->m30C = 0;
    self->m310 = 0;
    self->m32C = 0;
    self->m330 = 0;
    for (int i = 0; i < 3; i++) {
        self->m314[i] = 0;
        self->m320[i] = 0;
    }
    return self;
}

extern "C" FE_OVERLAY void fn_805229C0(FeW* x)
{
    fn_800EC1E8__FPv(x);
    x->fn_vslot29(lbl_805FC0B8);
    FeF(x, 0x2E8) = fn_800C806C()->m2A;
    x->fn_vslot16(0);
    x->fn_vslot8(0);
}

extern "C" FE_OVERLAY void fn_80522A74(FeScrD* x)
{
    fn_800ECF18(x);
}

/* near-miss: retail interleaves the copies of d/e/f (r7, r8, r9) with the two stores and loads the vptr into r11; ours copies r9 first and uses r9 (store order swaps and local copies tried) */
extern "C" FE_OVERLAY void fn_80523824(FeW* x, int a, int b, int c, int d, int e, int f)
{
    FeI(x, 0x2E0) = b;
    FeI(x, 0x334) = c;
    ((FeWV*)x)->s88();
    fn_80522A94(x, d, e, f);
}

extern "C" FE_OVERLAY int fn_8052388C(void* x, int a)
{
    int r = fn_805238EC(x, a);
    if (r) {
        fn_80523A90(x, FeP(x, 0x2DC)->fn_vslot61());
        r = 1;
    }
    return r;
}

/* near-miss: retail loads r3 = 0 first and returns with bnelr (9 spellings tried) */
extern "C" FE_OVERLAY int fn_805238EC(void* x, int a)
{
    int v = FeI(x, 0x2E4);
    if (v != -1 && a == v) {
        return 1;
    }
    return 0;
}

/* near-miss (family fn_8052390C..fn_80523A08): retail tests the call result with cmpwi r3,0, ours emits mr. */
extern "C" FE_OVERLAY int fn_8052390C(void* x, int a)
{
    int r = fn_805238EC(x, a);
    if (r) {
        FeP(x, 0x2DC)->fn_vslot54();
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_80523960(void* x, int a)
{
    int r = fn_805238EC(x, a);
    if (r) {
        FeP(x, 0x2DC)->fn_vslot55();
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_805239B4(void* x, int a)
{
    int r = fn_805238EC(x, a);
    if (r) {
        FeP(x, 0x2DC)->fn_vslot56();
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_80523A08(void* x, int a)
{
    int r = fn_805238EC(x, a);
    if (r) {
        FeP(x, 0x2DC)->fn_vslot57();
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_80523A5C(void* x, int a, int b, int c, int d)
{
    if (a == FeI(x, 0x2DC)) {
        fn_80523A90(x, d);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_805243C4(void* x)
{
    if (FeI(x, 0x308) > 1) {
        fn_80524408(x, 0);
    }
    fn_800EC208__FP3UiS(x);
}

extern "C" FE_OVERLAY void fn_80524408(void* x, int a)
{
    unsigned i = 0;
    do {
        FeW* w = (FeW*)fn_800B7A94(FeGetMgr(), lbl_80622650[i]);
        if (w != 0) {
            w->fn_vslot8(a);
        }
        i++;
    } while (i <= 2);
    FeP(x, 0x148)->fn_vslot8(a);
}

/* near-miss: ours keeps 0x3364 in a callee-saved register (one more register saved than retail) */
extern "C" FE_OVERLAY FeScrN* fn_805244C8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 1, 0x3364, 0x1E, lbl_8062265C);
    self->SetVptr(lbl_80669780);
    FeI(self, 0x178) = 0;
    FeI(self, 0x174) = 0;
    fn_80134E38((char*)self + 0x17C, 0);
    FeI(self, 0x1C4) = (int)lbl_80669498;
    self->SetVptr(lbl_806694B0);
    return self;
}

extern "C" FE_OVERLAY void fn_80524564(FeW* x)
{
    FeLink10* t = lbl_806192E0->m4->m10;
    if (FeI(fn_800B555C(), 4) & 1) {
        if (lbl_8061A308 == 0) {
            void* r = fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C);
            FeI(r, 0x18) = FeI(t, 0x18);
            FeI(r, 0x14) = FeI(t, 0x14);
            fn_800E63A4__FP6Ue63A4(r);
        }
    } else if (lbl_8061A308 == 0 && (FeI(fn_800B555C(), 4) & 0x800)) {
        fn_800E63A4__FP6Ue63A4(t);
    }
    fn_804D3D54(x);
    fn_804D2DC0(x, 0x3390);
    FeI(x, 0x13C) = 1;
    x->fn_vslot87();
    if (fn_800B5634(fn_800B555C()) != 0) {
        fn_804D3CA8(x, 1);
    }
}

extern "C" FE_OVERLAY int fn_8052465C(void* x, int a)
{
    int r = ((int (*)(void*, int))fn_804D32A0)(x, a);
    if (fn_804D3B18(x, a) != 0 && (FeI(fn_800B555C(), 4) & 0x200)) {
        int v = 1;
        lbl_8061A308 = v;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_805246C4(FeScrG* x)
{
    fn_800ECAA4(x);
    x->fn_vslot87();
}

extern "C" FE_OVERLAY FeScrN* fn_80524708(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 1, 0x3364, 0x2E, lbl_806226D4);
    self->SetVptr(lbl_80669780);
    FeI(self, 0x178) = 0;
    FeI(self, 0x174) = 0;
    fn_80134E38((char*)self + 0x17C, 0);
    FeI(self, 0x1C4) = (int)lbl_80667638;
    self->SetVptr(lbl_80667650);
    return self;
}

extern "C" FE_OVERLAY void fn_805247A4(FeW* x)
{
    fn_804D3D54(x);
    fn_804D2DC0(x, 0x577);
    fn_80524ABC(x, 1);
    fn_80087A50__FP13Unk80084910_Si((void*)lbl_80622648, 1);
    fn_804D2F38(x);
    ((FeSub24*)((char*)fn_800C8058(x->fn_vslot32(lbl_805FC43C, 1)) + 0xDC))->s6(1);
    fn_80524B54(x);
}

extern "C" FE_OVERLAY void fn_80524850(void)
{
    fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C);
    fn_80087B10__Fv();
}

extern "C" FE_OVERLAY int fn_8052487C(void* x, int a)
{
    fn_80087A50__FP13Unk80084910_Si(fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C), FeI((void*)lbl_80622648, 0x234));
    int r = ((int (*)(void*, int))fn_804D32A0)(x, a);
    fn_80524ABC(x, 0);
    return r;
}

extern "C" FE_OVERLAY int fn_805248E4(FeW* x)
{
    fn_800C805C(x->fn_vslot32(lbl_805FC448, 1))->fn_vslot40(1);
    fn_80524B54(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8052495C(FeW* x)
{
    ((FeWV*)fn_800C805C(x->fn_vslot32(lbl_805FC448, 1)))->s41();
    fn_80524B54(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_805249D0(FeW* x)
{
    fn_800C805C(x->fn_vslot32(lbl_805FC448, 1))->fn_vslot38(1);
    fn_80524B54(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80524A48(FeW* x)
{
    ((FeWV*)fn_800C805C(x->fn_vslot32(lbl_805FC448, 1)))->s39();
    fn_80524B54(x);
    return 1;
}

extern "C" FE_OVERLAY void fn_80524ABC(void* x, int mode)
{
    int i = 0;
    do {
        void* s = fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C);
        void* g = (void*)lbl_80622648;
        fn_80087A50__FP13Unk80084910_Si(s, i);
        fn_80087A50__FP13Unk80084910_Si(g, i);
        i++;
        switch (mode) {
        case 0:
            fn_804D2F38(x);
            fn_804D304C(x);
            break;
        case 1:
            fn_804D3000(x);
            fn_804D2F9C(x);
            break;
        }
    } while (i <= 3);
}

extern "C" FE_OVERLAY void fn_80524B54(FeW* x)
{
    fn_804D2F9C(x);
    int v = lbl_80622648;
    FeSub24* s = (FeSub24*)((char*)fn_800C8058(x->fn_vslot32(lbl_805FC43C, 1)) + 0xDC);
    fn_80087A50__FP13Unk80084910_Si((void*)v, s->s5());
    fn_804D2F38(x);
    fn_804D3098(x);
}

extern "C" FE_OVERLAY void fn_80524BE8(void* x)
{
    fn_804D34A0(x);
    fn_80524B54((FeW*)x);
}

extern "C" FE_OVERLAY FeScrN* fn_80524C1C(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80669FA0);
    FeI(self, 0x130) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = 0;
    FeI(self, 0x158) = 0;
    FeI(self, 0x15C) = 0;
    FeI(self, 0x160) = 0;
    FeI(self, 0x164) = 0;
    FeI(self, 0x168) = 0;
    return self;
}

/* Widget at +0x164 of the screen of fn_80525498: its own vptr (+0x3C) has slot 33 taking an index; the sub-object at +0x98
 * has vptr +0x24 with an int getter (slot 5), a setter (slot 6) and a count (slot 13). */
class FeCycSub {
public:
    char pad0[0x24];
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual int c5();
    virtual void c6(int a);
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual int c13();
};
class FeCycW {
public:
    char pad0[0x3C];
    virtual void s1();
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
    virtual int s33(int a);
};
extern "C" void fn_800CFB38(int a);
extern float lbl_805FC4C0;

extern "C" FE_OVERLAY void fn_80524C94(void* x)
{
    fn_8040B61C((char*)x + 0x134);
    FeI(x, 0x148) = 1;
}

extern "C" FE_OVERLAY void fn_805252C0(void* x, float f)
{
    char* s = (char*)x + 0x134;
    ((char* (*)(char*, const char*))fn_8040B61C)(lbl_80622800, s);
    fn_800C62B8(((void* (*)())fn_800C5E28)(), FeI(x, 0x140), FeI(x, 0x144), s, 1, f);
}

extern "C" FE_OVERLAY void fn_8052531C(void* x, int a)
{
    fn_800ED310(x, a);
    if (a == 0) {
        FeI(x, 0x158) = lbl_8061A328;
        return;
    }
    int t = FeI(x, 0x158);
    if (t != 0) {
        FeI(x, 0x154) = FeI(x, 0x154) + (lbl_8061A328 - t);
        FeI(x, 0x158) = 0;
    }
}

extern "C" FE_OVERLAY void fn_80525390(FeScrN* self)
{
    if (FeW24(self) & 0x40000000) {
        fn_800ECAA4(self);
        switch (FeI(self, 0x168)) {
        case 0:
            if (!(((FeVF19*)self->m140)->s19() < lbl_805FC4BC)) {
                if (self->m15C == 0)
                    fn_80525498(self, 3);
                else
                    fn_80525498(self, 2);
            }
            break;
        case 1:
            if (FeI(self, 0x150) != 0) {
                if (FeI(self->m15C, 0) == 0)
                    goto L2;
            } else {
                if (FeI(self->m160, 0) == 0) {
        L2:
                    fn_80525498(self, 2);
                }
            }
            break;
        case 2:
            if (FeI(self, 0x154) < lbl_8061A328)
                fn_80525498(self, 1);
            break;
        }
    }
}

extern "C" FE_OVERLAY void fn_80525498(FeScrN* self, int mode)
{
    FeI(self, 0x168) = mode;
    switch (mode) {
    case 0:
        break;
    case 1:
        if (FeI(self, 0x164) != 0) {
            fn_800C5E28();
            fn_800C618C();
            int v = (((FeCycSub*)((char*)self->m164 + 0x98))->c5() + 1) % ((FeCycSub*)((char*)self->m164 + 0x98))->c13();
            ((FeCycSub*)((char*)self->m164 + 0x98))->c6(v);
            int w = ((FeCycW*)self->m164)->s33(v);
            ((void (*)(void*, int))fn_80524C94)(self, w);
            fn_805252C0(self, lbl_805FC4C0);
        }
        if (FeI(self, 0x150) != 0) {
            fn_800CFB38(FeI(self, 0x15C));
        } else {
            fn_800CFB38(FeI(self, 0x160));
        }
        break;
    case 2:
        FeI(self, 0x154) = lbl_8061A328 + 0x168;
        {
            int t = FeI(self, 0x160) != 0 ? FeI(self, 0x150) ^ 1 : 1;
            FeI(self, 0x150) = t;
        }
        break;
    }
}

extern "C" FE_OVERLAY void fn_805255F8(void)
{
    fn_800C5E28();
    fn_800C618C();
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY FeScrH* fn_80525624(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80669CF8);
    self->m130 = 0;
    return self;
}
