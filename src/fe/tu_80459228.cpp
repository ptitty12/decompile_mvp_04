/*
 * Front-end overlay code, .frontend_codeoverlay 0x80459228-0x8045B134 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"



struct FeArrL {
    char* m0;
    int m4;
    int m8;
    int mC;
    const void* m10;
    int m14;
};
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A440[];
struct FeW88 : Unk800C7B40_Data {
    virtual ~FeW88();
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
    virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61();
    virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66();
    virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76();
    virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81();
    virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86();
    virtual void s87(); virtual void s88(int a); virtual void s89(); virtual void s90(); virtual void s91();
    virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95(); virtual void s96();
    virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(int a, int b); virtual void s102(); virtual void s103(); virtual void s104();
    virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109();
    virtual void s110(); virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114();
    virtual void s115(); virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124();
    virtual void s125(); virtual void s126(); virtual void s127();
};
extern "C" {
void fn_8040074C(void* p, int n);
void fn_80535360(FeArrL* l, int a);
void fn_80539380(FeArrL* l);
void fn_805362AC(FeArrL* l, int a);
int fn_8007A6A0__18Unk8007A4DC_Screenii(void* g, int a, int b);
}


extern const char lbl_805F5548[];
extern const char lbl_805F55A0[];
extern "C" {
FeW* fn_800C8058(FeW* w);
void fn_8045A638(FeScrA* x);
}


extern "C" void fn_804589BC(FeScrA* x);

struct FeW90 : Unk800C7B40_Data {
    virtual ~FeW90();
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
    virtual void s90(int a, int b, int c);
};

extern "C" {

FE_OVERLAY int fn_80459228(FeScrA* x)
{
    FePair p1 = fn_8045A9C0(x, x->m14C);
    if (p1.a != 0) {
        int idx = x->m14C;
        if (idx == 1) {
            if (x->m138->fn_vslot87() == 0) {
                FePair p2 = fn_8045A9C0(x, x->m14C);
                FeList* l = x->m138;
                fn_80126CF4(l, l->m164, p2.a, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                x->m138->fn_vslot84(1, 0);
            } else {
                FeList* l = x->m138;
                fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                x->m13C[1]->fn_vslot14(1);
            }
        } else if (idx == 0) {
            if (x->m138->fn_vslot86() == 0) {
                FePair p3 = fn_8045A9C0(x, x->m14C);
                FeList* l = x->m138;
                fn_80126CF4(l, p3.a, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                x->m138->fn_vslot84(0, 0);
            } else {
                FeList* l = x->m138;
                fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
                x->m13C[0]->fn_vslot16(1);
            }
        }
        fn_80459FEC(x);
        fn_8001BC4C()->fn_8001BDAC(0xA3);
    }
    return 1;
}

FE_OVERLAY int fn_80459484(FeScrA* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9B);
    x->m14C = fn_8045A9AC(x, x->m14C);
    fn_80458B58(x, -1);
    return 1;
}

FE_OVERLAY int fn_804594D8(void) { return 1; }

FE_OVERLAY int fn_804594E0(FeScrA* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9C);
    x->m14C = fn_8045A9AC(x, x->m14C);
    fn_80458B58(x, -1);
    return 1;
}

FE_OVERLAY int fn_80459534(void) { return 1; }

FE_OVERLAY int fn_8045953C(FeScrA* x)
{
    x->m13C[x->m14C]->fn_vslot50();
    fn_8045AE3C(x, x->m14C);
    fn_80459FEC(x);
    return 1;
}

FE_OVERLAY int fn_804595A4(FeScrA* x)
{
    x->m13C[x->m14C]->fn_vslot51();
    fn_8045AE3C(x, x->m14C);
    fn_80459FEC(x);
    return 1;
}

FE_OVERLAY int fn_8045960C(FeScrA* x)
{
    x->m13C[x->m14C]->fn_vslot52();
    fn_8045AE3C(x, x->m14C);
    fn_80459FEC(x);
    return 1;
}

FE_OVERLAY int fn_80459674(FeScrA* x)
{
    x->m13C[x->m14C]->fn_vslot53();
    fn_8045AE3C(x, x->m14C);
    fn_80459FEC(x);
    return 1;
}

FE_OVERLAY int fn_804596DC(FeScrA* x)
{
    FeW** a = x->m144;
    x->m154 = -1;
    x->m158 = -1;
    a[x->m14C]->fn_vslot40(1);
    if (x->m14C == 1) {
        FeSub* s = (FeSub*)((char*)fn_800C8058(a[1]->fn_vslot32(lbl_805F55A0, 1)) + 0xDC);
        x->m150 = s->s5();
        fn_8045A638(x);
        fn_80458B58(x, x->m14C);
    } else if (x->m14C == 0) {
        x->m15C = ((FeSub*)((char*)fn_800C8058(x->fn_vslot32(lbl_805F5548, 1)) + 0xDC))->s10(((FeSub*)((char*)fn_800C8058(x->fn_vslot32(lbl_805F5548, 1)) + 0xDC))->s5());
        fn_8045A638(x);
        if (x->m150 != 1)
            fn_80458B58(x, 2);
        else
            fn_80458B58(x, x->m14C);
    }
    return 0;
}

FE_OVERLAY int fn_8045987C(FeScrA* x, int a)
{
    x->m144[x->m14C]->fn_vslot41(a);
    return 0;
}

FE_OVERLAY int fn_804598C4(FeScrA* x)
{
    FeW** a = x->m144;
    x->m154 = -1;
    x->m158 = -1;
    a[x->m14C]->fn_vslot38(1);
    if (x->m14C == 1) {
        FeSub* s = (FeSub*)((char*)fn_800C8058(a[1]->fn_vslot32(lbl_805F55A0, 1)) + 0xDC);
        x->m150 = s->s5();
        fn_8045A638(x);
        fn_80458B58(x, x->m14C);
    } else if (x->m14C == 0) {
        x->m15C = ((FeSub*)((char*)fn_800C8058(x->fn_vslot32(lbl_805F5548, 1)) + 0xDC))->s10(((FeSub*)((char*)fn_800C8058(x->fn_vslot32(lbl_805F5548, 1)) + 0xDC))->s5());
        fn_8045A638(x);
        if (x->m150 != 1)
            fn_80458B58(x, 2);
        else
            fn_80458B58(x, x->m14C);
    }
    return 0;
}

FE_OVERLAY int fn_80459A64(FeScrA* x)
{
    x->m144[x->m14C]->fn_vslot39();
    return 0;
}

FE_OVERLAY int fn_80459AAC(void) { return 0; }

FE_OVERLAY int fn_80459AB4(void) { return 0; }

FE_OVERLAY int fn_80459ABC(void) { return 0; }

FE_OVERLAY int fn_80459AC4(void) { return 0; }

FE_OVERLAY int fn_80459F14(FeScrA* x)
{
    if (x->m138->fn_vslot86() != 0) {
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_80459F5C(FeScrA* x)
{
    if (x->m138->fn_vslot87() != 0) {
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_80459FA4(FeScrA* x)
{
    int m = x->m14C;
    int r;
    if (m == 0) {
        r = fn_80459F14(x);
    } else {
        r = 0;
        if (m == 1) {
            r = fn_80459F5C(x);
        }
    }
    return r;
}

FE_OVERLAY void fn_8045A638(FeScrA* x)
{
    FeArrL arr;
    char buf[480];
    FeArrL* s = &arr;
    s->m10 = lbl_8064B298;
    s->m0 = buf;
    s->m8 = 0x78;
    fn_8040074C(s->m0, 0x1E0);
    s->m4 = 0;
    s->mC = 0;
    s->m10 = lbl_8064A550;
    fn_8040074C(s->m0, s->m8 * 4);
    void* g = lbl_8061930C;
    s->m10 = lbl_8064A440;
    s->m4 = 0;
    s->mC = 0;
    s->m14 = 0;
    fn_80535360(s, (int)x->m160);
    fn_80539380(s);
    fn_805362AC(s, 1);
    int n = s->m4;
    s->mC = 0;
    x->m7D4 = n;
    if (x->m150 == 0) {
        int cnt = 0;
        int i;
        for (i = 0; i < x->m7D4; i++) {
            int o = s->mC * 4;
            if (x->m15C == fn_8007A6A0__18Unk8007A4DC_Screenii(g, 5, *(int*)(o + (int)arr.m0))) {
                int o2 = s->mC * 4;
                int v = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, fn_80077BC4(g, *(int*)(o2 + (int)arr.m0)));
                x->m434[cnt].b = v;
                int o3 = s->mC * 4;
                x->m434[cnt].a = *(int*)(o3 + (int)arr.m0);
                cnt++;
            }
            unsigned k = s->mC + 1;
            s->mC = k % (unsigned)s->m4;
        }
        x->m7D4 = cnt;
    } else {
        int cnt;
        for (cnt = 0; cnt < x->m7D4; cnt++) {
            int o2 = s->mC * 4;
            int v = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, fn_80077BC4(g, *(int*)(o2 + (int)arr.m0)));
            x->m434[cnt].b = v;
            int o3 = s->mC * 4;
            x->m434[cnt].a = *(int*)(o3 + (int)arr.m0);
            unsigned k = s->mC + 1;
            s->mC = k % (unsigned)s->m4;
        }
    }
    arr.m10 = lbl_8064A550;
}

FE_OVERLAY void fn_8045A85C(FeScrA* x)
{
    int i = 1;
    int rowoff = 0;
    do {
        int j = 0;
        int coloff = 0;
        do {
            void* g = lbl_8061930C;
            char* b = (char*)x + 0x164;
            int o = coloff + rowoff;
            fn_8007B714__18Unk8007B2B0_Screen(g, (int)x->m160, i, j, *(int*)(b + o));
            j++;
            coloff += 8;
        } while (j <= 9);
        i++;
        rowoff += 0x50;
    } while (i <= 9);
}

/* near-miss: same 53 insns; only x and the row pointer p swap callee-saved registers (retail x=r30, p=r29; ours x=r29,
 * p=r30): global-alloc priority, x has 7 uses over the whole function and p 4 over the inner loop, so p ranks first. */
FE_OVERLAY void fn_8045A8D8(FeScrA* x)
{
    int i = 1;
    char* q = (char*)x;
    int rowoff = 0;
    fn_8007B738__18Unk8007B2B0_Screen(lbl_8061930C, (int)x->m160);
    do {
        int j = 0;
        int coloff = 0;
        int* p = (int*)(q + 0x164);
        do {
            int off = coloff + rowoff;
            int v = fn_8007B6F0__18Unk8007B2B0_Screen(lbl_8061930C, (int)x->m160, i, j);
            j++;
            coloff += 8;
            char* b1 = (char*)x + 0x164;
            *(int*)(b1 + off) = v;
            int t = *p;
            p += 2;
            if (t == 0) {
                char* b2 = (char*)x + 0x168;
                *(int*)(b2 + off) = 4;
            } else {
                int h = fn_80077BC4(lbl_8061930C, v);
                int r = fn_80078A38__18Unk8007B2B0_Screeni(lbl_8061930C, h);
                char* b3 = (char*)x + 0x168;
                *(int*)(b3 + off) = r;
            }
        } while (j <= 9);
        i++;
        q += 0x50;
        rowoff += 0x50;
    } while (i <= 9);
}

FE_OVERLAY int fn_8045A9AC(FeScrA* x, int a)
{
    return a == 1 ? 0 : 1;
}

FE_OVERLAY FePair fn_8045A9C0(FeScrA* x, int idx)
{
    FePair r;
    fn_80360B80(&r);
    if (idx != 0) {
        if (idx == 1) {
            if (x->m13C[1]->fn_vslot60() < x->m7D4) {
                return x->m434[x->m13C[1]->fn_vslot60()];
            }
        }
    } else {
        int k = x->m15C - 1;
        return x->m164[k][x->m13C[0]->fn_vslot60()];
    }
    return r;
}

/* The extra 'return r;' copies matter: each return copies the pair through the hidden result pointer, and the
 * number of copies sets that pointer's global-alloc priority (cc1plus -dl: 8 uses over 44 insns with these
 * returns, 5 over 35 with one). At 8 uses it outranks idx (3 uses over 7 insns): result pointer r30, idx r29. */
FE_OVERLAY FePair fn_8045AAB4(FeScrA* x, int idx)
{
    FePair r;
    fn_80360B80(&r);
    if (idx != 0) {
        if (idx == 1) {
            int i = x->m154;
            if (i <= x->m7D4) {
                if (i != -1) {
                    return x->m434[i];
                }
                return r;
            }
            return r;
        }
        return r;
    } else {
        int j = x->m158;
        if (j != -1) {
            int k = x->m15C - 1;
            return x->m164[k][j];
        }
        return r;
    }
}

FE_OVERLAY void fn_8045AB6C(FeScrA* x)
{
    int i = 0;
    do {
        ((FeW90*)x->m13C[0])->s90(i, 1, i == x->m158);
        i++;
    } while (i <= 9);
    int j;
    for (j = 0; j < x->m7D4; j++) {
        ((FeW90*)x->m13C[1])->s90(j, 1, j == x->m154);
    }
}

FE_OVERLAY void fn_8045AC2C(FeScrA* x)
{
    ((FeW88*)x->m13C[1])->s88(0);
    for (int i = 0; i < x->m7D4; i++) {
        ((FeW88*)x->m13C[1])->s101(i, 1);
        int off = 0;
        for (int j = 10; j != 0; j--) {
            int q = (int)x;
            char* b = (char*)x + 0x164;
            char* p = b + off;
            int end = (int)x + 0x280;
            do {
                if (*(int*)p == *(int*)((char*)x + 0x434 + i * 8)) {
                    ((FeW88*)x->m13C[1])->s101(i, 0);
                }
                q += 0x50;
                p += 0x50;
            } while (q <= end);
            off += 8;
        }
    }
}

FE_OVERLAY void fn_8045AE3C(FeScrA* x, int k)
{
    if (k != 0) {
        if (k == 1) {
            if (x->m138->fn_vslot87() != 0) {
                FePair p = fn_8045A9C0(x, x->m14C);
                FeList* l = x->m138;
                fn_80126CF4(l, l->m164, p.a, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            }
        }
    } else {
        if (x->m138->fn_vslot86() != 0) {
            FePair p = fn_8045A9C0(x, x->m14C);
            FeList* l = x->m138;
            fn_80126CF4(l, p.a, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
    }
}

FE_OVERLAY void fn_8045AF68(FeScrA* x, int k)
{
    if (k == 0 || k == 2) {
        FeList* l = x->m138;
        fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        x->m13C[0]->fn_vslot14(1);
    }
    if ((unsigned)(k - 1) <= 1) {
        FeList* l = x->m138;
        fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        x->m13C[1]->fn_vslot14(1);
    }
    fn_804589BC(x);
}

FE_OVERLAY FeScrB* fn_8045B074(FeScrB* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067B310);
    self->m130 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m1B8 = 0;
    self->m1BC = 0;
    self->m1C0 = 0;
    self->m1C4 = 0;
    self->m1C8 = 0;
    self->m1CC = 0;
    self->m1D0 = 0;
    self->m1D4 = 0;
    self->m1D8 = 0;
    self->m1DC = 0;
    self->m1E0 = 0;
    self->m1E4 = 0;
    self->m1E8 = 0;
    self->m1EC = 0;
    self->m1F0 = 0;
    return self;
}

FE_OVERLAY void fn_8045B108(FeScrB* self)
{
    fn_800ECE34(self);
    fn_800C3AB4(fn_800C33D0(), 9);
}

}
