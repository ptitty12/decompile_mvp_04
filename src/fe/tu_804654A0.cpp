/*
 * Front-end overlay code, .frontend_codeoverlay 0x804654A0-0x8046C6F8 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"
struct FeS164 {
    char pad0[0x164];
    FeW* m164;
};
struct FeW100 : Unk800C7B40_Data {
    virtual ~FeW100();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46();
    virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56();
    virtual void s57(); virtual void s58(); virtual int s59(); virtual void s60(); virtual void s61();
    virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66();
    virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76();
    virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81();
    virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86();
    virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90(); virtual void s91();
    virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95(); virtual void s96();
    virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100(int a, int b);
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};
extern "C" {
FeW* fn_800C8058(FeW* w);
}
extern "C" {
void fn_80465FB4(FeScrI* x, int sel);
void fn_80466F94(FeScrI* x);
void fn_804673EC(FeScrI* x);
void fn_80469274(FeScrI* x);
void fn_80469C8C(FeScrI* x);
void fn_8046A558(FeScrI* x);
void fn_8046B390(FeScrI* x);
}
extern "C" int fn_80468D44(FeW* w, int v);
extern "C" {
FeW* fn_800C8060(FeW* w);
int fn_804687C0(FeW* w, int v);
void* memset(void* p, int c, unsigned n);
const char* fn_80090880__FP11Unk80090880(void* t, int id);
}
extern void* lbl_8061977C;
extern "C" {
int fn_8007B320__18Unk8007B2B0_Screenii(void* g, int a, int b);
int fn_8007B8C4__18Unk8007B2B0_Screenii(void* g, int a, int b);
}
struct FeSub11 : FeSubData {
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
    virtual int s11();
};
extern const char lbl_805F59C4[];
extern "C" {
void fn_800D0074(void* p, int v, int c);
int fn_80078A38__18Unk8007B2B0_Screeni(void* g, int a);
int fn_80075948__18Unk8007B2B0_Screeni(void* g, int a);
}

static inline FeW*& FeWpq(void* x, int off)
{
    return *(FeW**)((char*)x + off);
}

extern "C" {
FE_OVERLAY void fn_80466BB4(void* p, int b)
{
    FeS164* x = (FeS164*)p;
    int cur = ((FeSub*)((char*)x->m164 + 0xDC))->s5();
    ((FeSub*)((char*)x->m164 + 0xDC))->s15();
    ((FeWV*)x->m164)->s51(0x404D, 0);
    ((FeWV*)x->m164)->s51(0x404E, 1);
    if (b != 0) {
        ((FeWV*)x->m164)->s51(0x404F, 2);
        ((FeWV*)x->m164)->s51(0x4050, 3);
        ((FeWV*)x->m164)->s51(0x4051, 4);
        ((FeWV*)x->m164)->s51(0x4052, 5);
        ((FeWV*)x->m164)->s51(0x4053, 6);
        ((FeWV*)x->m164)->s51(0x5976, 7);
        ((FeWV*)x->m164)->s51(0x5977, 8);
        ((FeWV*)x->m164)->s51(0x5978, 9);
    }
    if (cur < ((FeSub*)((char*)x->m164 + 0xDC))->s13())
        ((FeSub*)((char*)x->m164 + 0xDC))->s6(cur);
    else
        ((FeSub*)((char*)x->m164 + 0xDC))->s6(0);
}

FE_OVERLAY void fn_80466E08(void* x)
{
    FeW* a = FeWpq(x, 0x15C);
    int v = ((FeSub11*)((char*)a + 0xDC))->s11();
    fn_800D0074((char*)FeWpq(x, 0x150) + 0x98, v, 0);
    fn_800D0074((char*)FeWpq(x, 0x154) + 0xDC, v, 0);
    ((FeWV*)x)->s68(fn_800C805C(FeWpq(x, 0x13C)->fn_vslot32(lbl_805F59C4, 1)), 1);
}

FE_OVERLAY int fn_80466ED0(int a, int b, int c)
{
    void* g = lbl_8061930C;
    if (fn_80078A38__18Unk8007B2B0_Screeni(g, a) == 0) {
        if (b == 0 || fn_80075948__18Unk8007B2B0_Screeni(g, a) != fn_80075948__18Unk8007B2B0_Screeni(g, b)) {
            if (c != 0) {
                if (fn_80075948__18Unk8007B2B0_Screeni(g, a) == fn_80075948__18Unk8007B2B0_Screeni(g, c)) {
                    goto yes;
                }
                goto no;
            }
            goto no;
        }
        goto yes;
    }
    if (b == a || c == a) {
    yes:
        return 1;
    }
no:
    return 0;
}

FE_OVERLAY int fn_804672F4(unsigned k, int a, int b)
{
    void* g = lbl_8061930C;
    if (k <= 1) {
        if (a == 0 || fn_8007B8C4__18Unk8007B2B0_Screenii(g, 0, fn_8007B320__18Unk8007B2B0_Screenii(g, 0, fn_80075948__18Unk8007B2B0_Screeni(g, a))) != k) {
            if (b != 0 && fn_8007B8C4__18Unk8007B2B0_Screenii(g, 0, fn_8007B320__18Unk8007B2B0_Screenii(g, 0, fn_80075948__18Unk8007B2B0_Screeni(g, b))) == k)
                return 1;
            return 0;
        }
        return 1;
    }
    if (a != 0 && fn_8007B8C4__18Unk8007B2B0_Screenii(g, 0, a) == k)
        return 1;
    if (b != 0 && fn_8007B8C4__18Unk8007B2B0_Screenii(g, 0, b) == k)
        return 1;
    return 0;
}

FE_OVERLAY void fn_80468490(void* x)
{
    char* buf = (char*)x + 0x1E4;
    FeW* w = fn_800C8060(FeWpq(x, 0x178));
    int v = ((FeSub11*)((char*)FeWpq(x, 0x150) + 0x98))->s11();
    int r = fn_804687C0(w, v);
    memset(buf, 0, 0x24);
    if (v == *(int*)((char*)x + 0x214)) {
        memset(buf, 0xFF, 0x24);
        fn_8046BBC0((FeScrI*)x, 1);
    }
    if (r == 0) {
        FeWpq(x, 0x184)->fn_vslot8(1);
        ((FeWV*)FeWpq(x, 0x184))->s28((void*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x334D));
        w->fn_vslot8(0);
        w->fn_vslot16(0);
    } else {
        FeWpq(x, 0x184)->fn_vslot8(0);
        w->fn_vslot8(1);
        w->fn_vslot16(1);
    }
}

FE_OVERLAY void fn_80468628(void* x)
{
    char* buf = (char*)x + 0x1E4;
    FeW* w = fn_800C8060(FeWpq(x, 0x178));
    int v = ((FeSub11*)((char*)FeWpq(x, 0x150) + 0x98))->s11();
    int r = fn_80468D44(w, v);
    memset(buf, 0, 0x24);
    if (v == *(int*)((char*)x + 0x214)) {
        memset(buf, 0xFF, 0x24);
        fn_8046BBC0((FeScrI*)x, 1);
    }
    if (r == 0) {
        FeWpq(x, 0x184)->fn_vslot8(1);
        ((FeWV*)FeWpq(x, 0x184))->s28((void*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x4D26));
        w->fn_vslot8(0);
        w->fn_vslot16(0);
    } else {
        FeWpq(x, 0x184)->fn_vslot8(0);
        w->fn_vslot8(1);
        w->fn_vslot16(1);
    }
}

FE_OVERLAY void fn_8046B980(FeScrI* x, FeW* w)
{
    int sel = ((FeSub*)((char*)fn_800C8058(fn_800C805C(x->m138->fn_vslot33(0xB, 1))->fn_vslot33(0xA, 1)) + 0xDC))->s5();
    if (sel != x->m208) {
        fn_80465FB4(x, sel);
        return;
    }
    switch (sel) {
    case 0:
        if (w == fn_800C805C(FeWpq(x, 0x13C)->fn_vslot32(lbl_805F59C4, 1))) {
            fn_80466F94(x);
        } else if (w == x->m158) {
            fn_80466E08(x);
        }
        break;
    case 1:
        if (w == fn_800C805C(FeWpq(x, 0x13C)->fn_vslot32(lbl_805F59C4, 1))) {
            fn_80468490(x);
        } else if (w == x->m158) {
            fn_80466E08(x);
        }
        break;
    case 2:
        if (w == fn_800C805C(FeWpq(x, 0x13C)->fn_vslot32(lbl_805F59C4, 1))) {
            fn_80468628(x);
        } else if (w == x->m158) {
            fn_80466E08(x);
        }
        break;
    case 3:
        if (w == FeWpq(x, 0x160))
            fn_804673EC(x);
        break;
    case 4:
        if (w == FeWpq(x, 0x160))
            fn_80469274(x);
        break;
    case 5:
        if (w == FeWpq(x, 0x160))
            fn_80469C8C(x);
        break;
    case 6:
        fn_8046A558(x);
        break;
    case 7:
    case 8:
        if (w == FeWpq(x, 0x160))
            fn_8046B390(x);
        break;
    }
}

FE_OVERLAY void fn_8046BBC0(FeScrI* x, int a)
{
    int f = 0;
    switch (x->m208) {
    case 0:
    case 3:
        f = 1;
        break;
    case 1:
    case 2:
        ((FeSub11*)((char*)FeWpq(x, 0x150) + 0x98))->s11();
        f = (((FeSub11*)((char*)FeWpq(x, 0x150) + 0x98))->s11() == *(int*)((char*)x + 0x214));
        break;
    case 4:
    case 5: {
        FeW* t = FeWpq(x, 0x15C);
        f = (((FeSub11*)((char*)t + 0xDC))->s11() == *(int*)((char*)x + 0x218));
        break;
    }
    case 6: {
        FeW* t = FeWpq(x, 0x168);
        f = (((FeSub11*)((char*)t + 0xDC))->s11() == *(int*)((char*)x + 0x218));
        break;
    }
    case 7:
    case 8: {
        FeW* t = FeWpq(x, 0x164);
        f = (((FeSub11*)((char*)t + 0xDC))->s11() == *(int*)((char*)x + 0x218));
        break;
    }
    }
    if (f != 0) {
        int i = 0;
        int n = ((FeW100*)x->m17C)->s59();
        if (i < n) {
            do {
                int q = i / 32;
                char* b = (char*)x + 0x1E4;
                int off = q * 4;
                if ((*(int*)(b + off) >> (i - (q << 5))) & 1) {
                    ((FeW100*)x->m17C)->s100(i, 1);
                } else {
                    ((FeW100*)x->m17C)->s100(i, 0);
                }
                i++;
            } while (i < n);
        }
    } else {
        int i = 0;
        int n = ((FeW100*)x->m17C)->s59();
        if (i < n) {
            do {
                ((FeW100*)x->m17C)->s100(i, 0);
                i++;
            } while (i < n);
        }
    }
}

FE_OVERLAY int fn_8046BDE0(FeScrI* x)
{
    if (fn_8046C5C0(x) != 0) {
        x->m17C->fn_vslot52();
    }
    fn_8046BBC0(x, 0);
    return 1;
}

FE_OVERLAY int fn_8046BE40(FeScrI* x)
{
    x->m17C->fn_vslot53();
    fn_8046BBC0(x, 0);
    return 1;
}

FE_OVERLAY int fn_8046BE94(FeScrI* x)
{
    if (fn_8046C5C0(x) != 0) {
        x->m17C->fn_vslot50();
    }
    fn_8046BBC0(x, 0);
    return 1;
}

FE_OVERLAY int fn_8046BEF4(FeScrI* x)
{
    x->m17C->fn_vslot51();
    fn_8046BBC0(x, 0);
    return 1;
}

FE_OVERLAY int fn_8046BF48(FeScrI* x)
{
    fn_800C805C(x->m138->fn_vslot32(lbl_805F59C4, 1))->fn_vslot40(1);
    return 1;
}

FE_OVERLAY int fn_8046BFB0(FeScrI* x)
{
    ((FeWV*)fn_800C805C(x->m138->fn_vslot32(lbl_805F59C4, 1)))->s41();
    return 1;
}

FE_OVERLAY int fn_8046C014(FeScrI* x)
{
    fn_800C805C(x->m138->fn_vslot32(lbl_805F59C4, 1))->fn_vslot38(1);
    return 1;
}

FE_OVERLAY int fn_8046C07C(FeScrI* x)
{
    fn_800C805C(x->m138->fn_vslot32(lbl_805F59C4, 1))->fn_vslot39();
    return 1;
}

FE_OVERLAY int fn_8046C0E0(FeScrI* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY int fn_8046C13C(void) { return 0; }

FE_OVERLAY int fn_8046C144(FeScrI* x)
{
    fn_800C805C(x->m14C->fn_vslot32(lbl_805F59C4, 1))->fn_vslot38(1);
    return 0;
}

FE_OVERLAY int fn_8046C1AC(FeScrI* x)
{
    fn_800C805C(x->m14C->fn_vslot32(lbl_805F59C4, 1))->fn_vslot39();
    return 0;
}

FE_OVERLAY int fn_8046C210(FeScrI* x)
{
    fn_800C805C(x->m14C->fn_vslot32(lbl_805F59C4, 1))->fn_vslot40(1);
    fn_8046BBC0(x, 1);
    return 0;
}

FE_OVERLAY int fn_8046C290(FeScrI* x)
{
    ((FeWV*)fn_800C805C(x->m14C->fn_vslot32(lbl_805F59C4, 1)))->s41();
    fn_8046BBC0(x, 1);
    return 0;
}

FE_OVERLAY int fn_8046C30C(FeScrI* x)
{
    if (x->m20C == 0 && x->m208 == 6) {
        fn_800C805C(x->m14C->fn_vslot32(lbl_805F5A38, 1))->fn_vslot38(1);
    } else if ((unsigned)x->m208 <= 2) {
        x->m158->fn_vslot38(1);
    }
    return 0;
}

FE_OVERLAY int fn_8046C3BC(FeScrI* x)
{
    if (x->m20C == 0 && x->m208 == 6) {
        fn_800C805C(x->m14C->fn_vslot32(lbl_805F5A38, 1))->fn_vslot39();
    } else if ((unsigned)x->m208 <= 2) {
        x->m158->fn_vslot39();
    }
    return 0;
}

FE_OVERLAY int fn_8046C464(FeScrI* x)
{
    if (x->m20C == 0 && x->m208 == 6) {
        fn_800C805C(x->m14C->fn_vslot32(lbl_805F5A38, 1))->fn_vslot40(1);
    } else if ((unsigned)x->m208 <= 2) {
        x->m158->fn_vslot40(1);
    }
    return 0;
}

FE_OVERLAY int fn_8046C514(FeScrI* x)
{
    if (x->m20C == 0 && x->m208 == 6) {
        ((FeWV*)fn_800C805C(x->m14C->fn_vslot32(lbl_805F5A38, 1)))->s41();
    } else if ((unsigned)x->m208 <= 2) {
        ((FeWV*)x->m158)->s41();
    }
    return 0;
}

FE_OVERLAY void fn_8046C5BC(void) {}

FE_OVERLAY int fn_8046C5C0(FeScrI* x)
{
    switch (x->m208) {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 1;
    case 5:
        return 1;
    case 6:
        return x->m20C;
    case 7:
        return 0;
    case 8:
        return 0;
    }
    return 1;
}

FE_OVERLAY FeScrJ* fn_8046C63C(FeScrJ* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806793D0);
    self->m130 = 0;
    self->m138 = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 1;
    self->m150[0] = lbl_805F36A0.c0;
    fn_800C21D0((char*)fn_800B555C() + 8);
    return self;
}

FE_OVERLAY void fn_8046C6B8(FeScrJ* x)
{
    fn_800ECE34(x);
    if (fn_800C2248((char*)fn_800B555C() + 8) == 0) {
        fn_800C2210((char*)fn_800B555C() + 8);
    }
}

}
