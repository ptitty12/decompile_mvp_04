/*
 * Front-end overlay code, .frontend_codeoverlay 0x804654A0-0x8046C6F8 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"
struct FeS164 {
    char pad0[0x164];
    FeW* m164;
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

/* near-miss: 1 instruction short (retail hoists `li r3,1` ahead of the last beq; tried 12 tail forms) */
FE_OVERLAY int fn_804672F4(unsigned k, int a, int b)
{
    void* g = lbl_8061930C;
    if (k <= 1) {
        if (a == 0 || fn_8007B8C4__18Unk8007B2B0_Screenii(g, 0, fn_8007B320__18Unk8007B2B0_Screenii(g, 0, fn_80075948__18Unk8007B2B0_Screeni(g, a))) != k) {
            if (b != 0) {
                if (fn_8007B8C4__18Unk8007B2B0_Screenii(g, 0, fn_8007B320__18Unk8007B2B0_Screenii(g, 0, fn_80075948__18Unk8007B2B0_Screeni(g, b))) == k)
                    goto yes;
            }
            goto no;
        }
        goto yes;
    }
    if (a != 0 && fn_8007B8C4__18Unk8007B2B0_Screenii(g, 0, a) == k) {
yes:
        return 1;
    }
    if (b != 0) {
        if (fn_8007B8C4__18Unk8007B2B0_Screenii(g, 0, b) == k)
            goto yes;
    }
no:
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
