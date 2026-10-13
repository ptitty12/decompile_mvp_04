/*
 * Front-end overlay code, .frontend_codeoverlay 0x8048E6A0-0x80492680 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern const char lbl_805F66CC[];
extern const char lbl_805F66D8[];
extern const char lbl_805F66E4[];
extern const char lbl_805F66F0[];
extern const char lbl_805F6934[];
extern const char lbl_805F6940[];
extern const char lbl_805F69E4[];
extern "C" void fn_800E3418(int a, int b, int c, int d);
extern "C" {

extern "C" void fn_800E49DC(FeScrD* x);

FE_OVERLAY void fn_8048E6A0(FeScrO* x)
{
    if (fn_800B5758(fn_800B555C()) != 0) {
        x->m148 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66CC, 1));
        x->m14C = (int)fn_800C8044(x->fn_vslot32(lbl_805F66D8, 1));
    } else {
        x->m148 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66D8, 1));
        x->m14C = (int)fn_800C8044(x->fn_vslot32(lbl_805F66CC, 1));
    }
}

FE_OVERLAY int fn_8048E76C(FeScrO* x)
{
    if (x->m148 == 0) {
        fn_8048E6A0(x);
    }
    return x->m148;
}

FE_OVERLAY int fn_8048E7A8(FeScrO* x)
{
    if (x->m14C == 0) {
        fn_8048E6A0(x);
    }
    return x->m14C;
}

FE_OVERLAY void fn_8048E7E4(FeScrO* x)
{
    if (fn_800B5758(fn_800B555C()) != 0) {
        x->m150 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66E4, 1));
        x->m154 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66F0, 1));
    } else {
        x->m150 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66F0, 1));
        x->m154 = (int)fn_800C8044(x->fn_vslot32(lbl_805F66E4, 1));
    }
}

FE_OVERLAY int fn_8048E8B0(FeScrO* x)
{
    if (x->m150 == 0) {
        fn_8048E7E4(x);
    }
    return x->m150;
}

FE_OVERLAY int fn_8048E8EC(FeScrO* x)
{
    if (x->m154 == 0) {
        fn_8048E7E4(x);
    }
    return x->m154;
}

FE_OVERLAY FeScrH* fn_8048E928(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 0x12, lbl_806217F8);
    self->SetVptr(lbl_80676060);
    return self;
}

FE_OVERLAY void fn_8048E990(void* x)
{
    fn_804D3164(x);
    fn_804D2DC0(x, 0x2422);
}

FE_OVERLAY int fn_8048E9C8(void* x, int a)
{
    FeI(fn_800B555C(), 0x570) = a;
    fn_80132438(fn_804D2D50(x), x, fn_804D3BA0, fn_8048EC48, fn_8048EBC8, 0x3A61, -1, 1, lbl_805F66FC);
    fn_804D2D50(x)->fn_vslot86();
    ((FeWV*)x)->s40();
    return 1;
}

FE_OVERLAY void fn_8048EA74(FeW* x)
{
    FeMsg m;
    FeMsg* p = &m;
    int v = FeI(fn_800B555C(), 0x570);
    ((void (*)(void*, int))fn_804D32A0)(x, v);
    fn_800E2944(fn_804D2ED0(x, 0x52)->x4(), v);
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805F3CA8, 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
}

FE_OVERLAY void fn_8048EB38(FeScrD* x)
{
    fn_800E49DC(x);
}

FE_OVERLAY void fn_8048EB58(void* x)
{
    int v = fn_804D2ED0(x, 0x4D)->x4();
    if (v == 1 && FeI(x, 0x170) == 0) {
        fn_8007295C__18Unk8007A4DC_Screen(lbl_8061930C);
        FeI(x, 0x170) = v;
    }
}

FE_OVERLAY void fn_8048EBC8(void)
{
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    ((FeWQ*)w)->s85(0);
    FeI(w, 0x314) = 1;
}

FE_OVERLAY void fn_8048EC48(FeW* x)
{
    x->fn_vslot80(1);
    fn_8048EA74(x);
}

struct Fe8EC94_Slot {
    int m0;
    unsigned char m4;
    char pad5[3];
    int m8;
};
struct FeScrP : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    int m168;
    int m16C;
    int m170;
    int m174;
    float m178;
    float m17C;
    int m180;
    int m184;
    int m188;
    int m18C;
    int m190;
    int m194;
    int m198;
    char pad19C[0x4];
    int m1A0;
    int m1A4;
    char pad1A8[0x20];
    int m1C8;
    int m1CC;
    int m1D0;
    int m1D4;
    int m1D8;
    int m1DC;
    int m1E0;
    int m1E4;
    int m1E8;
    int m1EC;
    int m1F0;
    int m1F4;
    int m1F8;
    int m1FC;
    int m200;
    int m204;
    int m208;
    int m20C;
    int m210;
    int m214;
    int m218;
    int m21C;
    char pad220[0x10];
    int m230;
    int m234;
    int m238[2];
    int m240[2];
    int m248;
    int m24C[2];
    char pad254[0x10];
    int m264[2][25];
    int m32C;
    int m330;
    int m334;
    Fe8EC94_Slot m338[4];
};
extern const char lbl_80675DB8[];
extern "C" FE_OVERLAY FeScrP* fn_8048EC94(FeScrP* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80675DB8);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = -1;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m16C = 0;
    self->m170 = 0;
    self->m174 = 0;
    self->m178 = 0.0f;
    self->m17C = 0.0f;
    self->m180 = 0;
    self->m184 = 2;
    self->m188 = 2;
    self->m18C = 0;
    self->m190 = -1;
    self->m194 = -1;
    self->m198 = 0;
    self->m1A0 = 0;
    self->m1A4 = 0;
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
    self->m1F4 = 0;
    self->m1F8 = 0;
    self->m1FC = 0;
    self->m200 = 0;
    self->m204 = 0;
    self->m208 = 0;
    self->m20C = 0;
    self->m210 = 0;
    self->m214 = 0;
    self->m218 = 0;
    self->m21C = 0;
    self->m230 = 0;
    self->m234 = 0;
    self->m248 = 0;
    self->m32C = 0;
    self->m330 = 0;
    self->m334 = -1;
    for (int i = 0; i < 2; i++) {
        self->m238[i] = 0;
        self->m240[i] = 0;
        self->m24C[i] = 0;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 0x19; k++) {
                self->m264[j][k] = 0;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        self->m338[i].m0 = 0;
        self->m338[i].m4 = 0xFF;
        self->m338[i].m8 = 0;
    }
    for (int i = 0; i < 8; i++) {
        fn_80497B74((char*)self, i);
    }
    return self;
}

extern char lbl_805F5024[];
extern char lbl_805F64A0[];
extern char lbl_805F6494[];
extern char lbl_805F57D0[];
extern const char lbl_805F59C8[];
extern "C" {
FeW* fn_800C8050();
FeW* fn_800C8038();
int sprintf(char* dst, const char* fmt, ...);
}
extern const char lbl_805F54A8[];
extern const char lbl_805F6704[];
extern const char lbl_805F6718[];
extern const char lbl_805F6728[];
extern const char lbl_805F673C[];
extern const char lbl_805F674C[];
extern const char lbl_805F6758[];
extern const char lbl_805F6768[];
extern const char lbl_805F6778[];
extern const char lbl_805F6780[];
extern const char lbl_805F678C[];
extern const char lbl_805F6794[];
extern const char lbl_805F67A4[];
extern const char lbl_805F67B4[];
extern const char lbl_805F67C0[];
extern const char lbl_805F67CC[];
extern const char lbl_805F67E0[];
extern const char lbl_805F67E8[];
extern const char lbl_805F67F8[];
extern const char lbl_805F6808[];
struct FeW8EE94 : Unk800C7B40_Data {
    virtual ~FeW8EE94();
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
    virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90(); virtual void s91();
    virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95(); virtual void s96();
    virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100(); virtual void s101();
    virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105(int a);
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};
extern "C" FE_OVERLAY void fn_8048EE94(void* xv)
{
    FeW* x = (FeW*)xv;
    int i = 0;
    int off = 0;
    char b8[0x68];
    fn_800ECE34(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    FeI(x, 0x1D8) = (int)fn_800C8044(x->fn_vslot29(lbl_805F6704));
    FeI(x, 0x1DC) = (int)fn_800C8044(x->fn_vslot29(lbl_805F6718));
    FeI(x, 0x1E0) = (int)fn_800C8044(x->fn_vslot29(lbl_805F6728));
    FeI(x, 0x1E8) = (int)fn_800C8044(x->fn_vslot32(lbl_805F673C, 0));
    FeI(x, 0x1F4) = (int)fn_800C8044(FeMem(x, 0x1E8)->fn_vslot32(lbl_805F674C, 0));
    FeI(x, 0x1F8) = (int)fn_800C8044(FeMem(x, 0x1E8)->fn_vslot32(lbl_805F6758, 0));
    FeI(x, 0x1F0) = (int)fn_800C8044(FeMem(x, 0x1F8)->fn_vslot32(lbl_805F6768, 0));
    FeI(x, 0x1EC) = (int)fn_800C8044(FeMem(x, 0x1F8)->fn_vslot32(lbl_805F6778, 0));
    FeI(x, 0x1FC) = (int)fn_800C8044(FeMem(x, 0x1F8)->fn_vslot32(lbl_805F6780, 0));
    FeI(x, 0x1C8) = (int)fn_800C8040(FeMem(x, 0x1F8)->fn_vslot32(lbl_805F678C, 1));
    FeMem(x, 0x1C8)->fn_vslot8(0);
    FeI(x, 0x1CC) = (int)fn_800C8040(FeMem(x, 0x1E8)->fn_vslot32(lbl_805F6794, 1));
    FeI(x, 0x1D0) = (int)fn_800C8040(FeMem(x, 0x1E8)->fn_vslot32(lbl_805F67A4, 1));
    FeI(x, 0x1D4) = (int)fn_800C8040(FeMem(x, 0x1E8)->fn_vslot32(lbl_805F67B4, 1));
    FeI(x, 0x1E4) = (int)fn_800C8044(x->fn_vslot32(lbl_805F67C0, 0));
    FeI(x, 0x21C) = (int)fn_800C8060(FeMem(x, 0x1E4)->fn_vslot29(lbl_805F67CC));
    ((FeW8EE94*)FeMem(x, 0x21C))->s105(1);
    FeI(x, 0x160) = FeMem(x, 0x21C)->fn_vslot73(1, 4)->fn_vslot32(lbl_805F5024, 1)->m2A;
    do {
        sprintf(b8, lbl_805F67E0, i);
        i++;
        FeW* w = fn_800C8044(FeMem(x, 0x1EC)->fn_vslot32(b8, 1));
        char* b1 = (char*)x + 0x368;
        char* b2 = (char*)x + 0x36C;
        *(int*)(b1 + off) = w->m26;
        *(int*)(b2 + off) = w->m28;
        off += 8;
    } while (i <= 3);
    FeI(x, 0x238) = (int)fn_800C8040(FeMem(x, 0x1F0)->fn_vslot29(lbl_805F67E8));
    FeI(x, 0x23C) = (int)fn_800C8040(FeMem(x, 0x1F0)->fn_vslot29(lbl_805F67F8));
    FeI(x, 0x240) = (int)fn_800C8044(FeMem(x, 0x1E8)->fn_vslot32(lbl_805F64A0, 1));
    FeI(x, 0x244) = (int)fn_800C8044(FeMem(x, 0x1E8)->fn_vslot32(lbl_805F6494, 1));
    FeW* w2 = (FeW*)fn_800C8040(FeMem(x, 0x1F0)->fn_vslot32(lbl_805F6808, 1));
    FeI(x, 0x254) = w2->m26;
    FeI(x, 0x258) = w2->m28;
    FeW* w3 = (FeW*)fn_800C8040(FeMem(x, 0x1F0)->fn_vslot32(lbl_805F54A8, 1));
    FeI(x, 0x25C) = w3->m26;
    FeI(x, 0x260) = w3->m28;
    x->fn_vslot32(lbl_805F59C8, 1);
    FeI(x, 0x248) = (int)fn_800C8050();
    FeW* w4 = fn_800C8044(x->fn_vslot32(lbl_805F57D0, 0));
    FeI(x, 0x230) = (int)fn_800C8040(w4->fn_vslot33(4, 1));
    w4->fn_vslot33(2, 1);
    FeI(x, 0x234) = (int)fn_800C8038();
    fn_804983AC(x);
}

FE_OVERLAY void fn_8048FC64(void)
{
    ((FeStateX*)fn_800B555C())->m650 = 0;
    fn_800C33D0();
    fn_800C3BE0();
    fn_8001BC4C();
    fn_8001C168();
}

extern "C" int fn_80498478(void* x);
FE_OVERLAY int fn_8049140C(FeW* x)
{
    if (FeI(x, 0x13C) != 0 || (FeI(FeP(x, 0x198), 0x24) < 0 && FeI(x, 0x134) != 1)) {
        return 0;
    }
    switch (FeI(x, 0x134)) {
    case 0: {
        int v = 0;
        if (FeI(FeP(x, 0x1A4), 0x1CD0) != 0) {
            v = 1;
        }
        if (v == FeI(x, 0x188)) {
            fn_800C8060(FeMem(x, 0x1DC)->fn_vslot32(lbl_805F6934, 0))->fn_vslot50();
        } else {
            fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 0))->fn_vslot50();
        }
        break;
    }
    case 1:
        FeMem(x, 0x21C)->fn_vslot50();
        fn_800E3418(FeI(x, 0x1E4), FeI(x, 0x15C), 0, FeMem(x, 0x21C)->fn_vslot60());
        if (FeI(FeP(x, 0x198), 0x24) < 0) {
            if (FeI(x, 0x188) == 0) {
                fn_80126CF4((FeList*)FeP(x, 0x198), FeI(FeP(x, 0x198), 0x164), fn_80498478(x), FeI(FeP(x, 0x198), 0x134), FeI(FeP(x, 0x198), 0x16C), FeI(FeP(x, 0x198), 0x170), 0, FeI(FeP(x, 0x198), 0x138), FeI(FeP(x, 0x198), 0x13C), FeI(FeP(x, 0x198), 0x148), FeI(FeP(x, 0x198), 0x14C));
            } else {
                fn_80126CF4((FeList*)FeP(x, 0x198), fn_80498478(x), FeI(FeP(x, 0x198), 0x168), FeI(FeP(x, 0x198), 0x134), FeI(FeP(x, 0x198), 0x16C), FeI(FeP(x, 0x198), 0x170), 0, FeI(FeP(x, 0x198), 0x138), FeI(FeP(x, 0x198), 0x13C), FeI(FeP(x, 0x198), 0x148), FeI(FeP(x, 0x198), 0x14C));
            }
        }
        break;
    case 2:
        fn_800C8060(FeMem(x, 0x1E0)->fn_vslot32(lbl_805F69E4, 0))->fn_vslot50();
        break;
    }
    return 1;
}

extern "C" {
void fn_80496310(void* x);
void fn_8049724C(void* x);
void fn_80497590(void* x);
void fn_8049494C(void* x, int a);
void fn_800DA54C(void* a, int b, void* c, int d, int e);
}
extern const char lbl_805F68C0[];
extern const char lbl_805F6910[];
extern const char lbl_805F6920[];
extern const char lbl_805F6924[];
extern const char lbl_805F59C8[];
static inline float& Fe8FC9C_F(void* x, int off)
{
    return *(float*)((char*)x + off);
}
FE_OVERLAY void fn_8048FC9C(FeW* x)
{
    fn_800ECAA4(x);
    if (FeI(x, 0x13C) == 1 && FeI(x, 0x134) != 3 && fn_804977FC((char*)x) == 1) {
        fn_804920B8(x, 3);
    }
    fn_8001BC4C()->fn_8001BD40();
    ((void (*)(void*))fn_804983A8)(x);
    int n = FeI(x, 0x134);
    if (n == 0) {
        fn_80496310(x);
        if (FeI(x, 0x140) == 1) {
            FeI(x, 0x140) = n;
        }
        fn_8049724C(x);
        fn_80497590(x);
        int m = FeI(x, 0x144);
        if (m == 1) {
            if (!(Fe8FC9C_F(x, 0x178) <= 0.0f)) {
                Fe8FC9C_F(x, 0x178) = Fe8FC9C_F(x, 0x178) - 0.016666668f;
            } else if (fn_804977FC((char*)x) != 0 && FeI(FeP(x, 0x208), 0) == 0 && FeI(FeP(x, 0x210), 0) == 0) {
                if (FeI(x, 0x148) == 0) {
                    FeMem(x, 0x1FC)->fn_vslot8(0);
                    FeI(x, 0x148) = m;
                } else {
                    fn_8049494C(x, 0);
                }
            }
        }
    } else if (n == 3 && FeI(FeP(x, 0x218), 0) == 0) {
        FeI(x, 0x14C) = 1;
        fn_800DA54C(FeP(x, 0x19C), FeI(x, 0x13C), fn_800C8060(FeMem(x, 0x1F4)->fn_vslot32(lbl_805F6910, 0)), 1, 1);
        FeMem(x, 0x1F4)->fn_vslot8(1);
        FeMem(x, 0x1F8)->fn_vslot8(0);
    }
    FeW* a = fn_800C8044(x->fn_vslot32(lbl_805F68C0, 1))->fn_vslot32(lbl_805F6920, 1);
    a->fn_vslot8(((unsigned)FeI(fn_800C8044(x->fn_vslot32(lbl_805F68C0, 1))->fn_vslot32(lbl_805F59C8, 1), 0x24)) >> 31);
    FeW* b = fn_800C8044(x->fn_vslot32(lbl_805F68C0, 1))->fn_vslot32(lbl_805F6924, 1);
    b->fn_vslot8(((unsigned)FeI(fn_800C8044(x->fn_vslot32(lbl_805F68C0, 1))->fn_vslot32(lbl_805F59C8, 1), 0x24)) >> 31);
}

FE_OVERLAY int fn_80491630(FeW* x)
{
    if (FeI(x, 0x13C) == 1) {
        return 0;
    }
    switch (FeI(x, 0x134)) {
    case 0: {
        int v = 0;
        if (FeI(FeP(x, 0x1A4), 0x1CD0) != 0) {
            v = 1;
        }
        if (v == FeI(x, 0x188)) {
            fn_800C8060(FeMem(x, 0x1DC)->fn_vslot32(lbl_805F6934, 0))->fn_vslot51();
        } else {
            fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 0))->fn_vslot51();
        }
        break;
    }
    case 1:
        FeMem(x, 0x21C)->fn_vslot51();
        break;
    case 2:
        fn_800C8060(FeMem(x, 0x1E0)->fn_vslot32(lbl_805F69E4, 0))->fn_vslot51();
        break;
    }
    return 1;
}

FE_OVERLAY int fn_80491774(FeW* x)
{
    if (FeI(x, 0x13C) != 0 || (FeI(FeP(x, 0x198), 0x24) < 0 && FeI(x, 0x134) != 1)) {
        return 0;
    }
    switch (FeI(x, 0x134)) {
    case 0: {
        int v = 0;
        if (FeI(FeP(x, 0x1A4), 0x1CD0) != 0) {
            v = 1;
        }
        if (v == FeI(x, 0x188)) {
            fn_800C8060(FeMem(x, 0x1DC)->fn_vslot32(lbl_805F6934, 0))->fn_vslot52();
        } else {
            fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 0))->fn_vslot52();
        }
        break;
    }
    case 1:
        FeMem(x, 0x21C)->fn_vslot52();
        fn_800E3418(FeI(x, 0x1E4), FeI(x, 0x15C), 0, FeMem(x, 0x21C)->fn_vslot60());
        if (FeI(FeP(x, 0x198), 0x24) < 0) {
            if (FeI(x, 0x188) == 0) {
                fn_80126CF4((FeList*)FeP(x, 0x198), FeI(FeP(x, 0x198), 0x164), fn_80498478(x), FeI(FeP(x, 0x198), 0x134), FeI(FeP(x, 0x198), 0x16C), FeI(FeP(x, 0x198), 0x170), 0, FeI(FeP(x, 0x198), 0x138), FeI(FeP(x, 0x198), 0x13C), FeI(FeP(x, 0x198), 0x148), FeI(FeP(x, 0x198), 0x14C));
            } else {
                fn_80126CF4((FeList*)FeP(x, 0x198), fn_80498478(x), FeI(FeP(x, 0x198), 0x168), FeI(FeP(x, 0x198), 0x134), FeI(FeP(x, 0x198), 0x16C), FeI(FeP(x, 0x198), 0x170), 0, FeI(FeP(x, 0x198), 0x138), FeI(FeP(x, 0x198), 0x13C), FeI(FeP(x, 0x198), 0x148), FeI(FeP(x, 0x198), 0x14C));
            }
        }
        break;
    case 2:
        fn_800C8060(FeMem(x, 0x1E0)->fn_vslot32(lbl_805F69E4, 0))->fn_vslot52();
        break;
    }
    return 1;
}

FE_OVERLAY int fn_80491998(FeW* x)
{
    if (FeI(x, 0x13C) != 0) {
        return 0;
    }
    switch (FeI(x, 0x134)) {
    case 0: {
        int v = 0;
        if (FeI(FeP(x, 0x1A4), 0x1CD0) != 0) {
            v = 1;
        }
        if (v == FeI(x, 0x188)) {
            fn_800C8060(FeMem(x, 0x1DC)->fn_vslot32(lbl_805F6934, 0))->fn_vslot53();
        } else {
            fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 0))->fn_vslot53();
        }
        break;
    }
    case 1:
        FeMem(x, 0x21C)->fn_vslot53();
        break;
    case 2:
        fn_800C8060(FeMem(x, 0x1E0)->fn_vslot32(lbl_805F69E4, 0))->fn_vslot53();
        break;
    }
    return 1;
}

FE_OVERLAY void fn_80491ADC(void* x)
{
    FeI(x, 0x334) = FeMem(x, 0x198)->fn_vslot85();
}

FE_OVERLAY int fn_80491B24(void* x)
{
    if (FeMem(x, 0x198)->fn_vslot86() != 0 && FeW24(FeP(x, 0x198)) < 0 && FeMem(x, 0x198)->fn_vslot85() != FeI(x, 0x334)) {
        fn_8001BC4C()->fn_8001BDAC(0x9B);
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_80491BBC(void* x)
{
    if (FeMem(x, 0x198)->fn_vslot86() != 0 && FeW24(FeP(x, 0x198)) < 0 && FeMem(x, 0x198)->fn_vslot85() != FeI(x, 0x334)) {
        fn_8001BC4C()->fn_8001BDAC(0x9C);
        return 1;
    }
    return 0;
}

FE_OVERLAY int fn_80491C54(void* x)
{
    ((FeWV*)FeMem(x, 0x248))->s47();
    fn_80492E94(x);
    return 1;
}

FE_OVERLAY int fn_80491CA4(void* x)
{
    FeMem(x, 0x248)->fn_vslot48();
    return 1;
}

FE_OVERLAY int fn_80491CE0(void* x)
{
    ((FeWV*)FeMem(x, 0x248))->s45();
    fn_80492E94(x);
    return 1;
}

FE_OVERLAY int fn_80491D30(void* x)
{
    FeMem(x, 0x248)->fn_vslot46();
    return 1;
}

FE_OVERLAY int fn_80491D6C(FeW* x, FeW* w, int a)
{
    if (FeI(x, 0x13C) == 0) {
        if (FeI(x, 0x134) == 1) {
            if (FeW24(FeP(x, 0x198)) >= 0) {
                int u = ((FeWI*)FeMem(x, 0x21C))->s60();
                fn_800E3418(FeI(x, 0x1E4), FeI(x, 0x15C), 0, u);
            }
            return 1;
        }
        if ((w == fn_800C8060(FeMem(x, 0x1DC)->fn_vslot32(lbl_805F6934, 1))
                || w == fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 1))
                || w == fn_800C8060(FeMem(x, 0x1E0)->fn_vslot32(lbl_805F69E4, 1)))
            && FeW24(FeP(x, 0x198)) >= 0) {
            x->fn_vslot67(0, fn_800C8070((void*)a));
            return 1;
        }
    }
    return 0;
}

FE_OVERLAY void fn_80491EE0(char* x)
{
    int i = FeI(x, 0x188);
    int o = i * 4;
    char* a = x + 0x240;
    char* b = x + 0x24C;
    int r = fn_800E2E8C(*(int*)(a + o), i, *(int*)(b + o), 0);
    *(int*)(b + FeI(x, 0x188) * 4) = r;
}

FE_OVERLAY void fn_80491F34(void* x)
{
    void* w = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    ((int (*)(void*, int))fn_80125084)(w, 0);
    ((int (*)(void*, int))fn_80125084)(w, 1);
    ((int (*)(void*, int))fn_80125084)(w, 2);
    ((int (*)(void*, int))fn_80125084)(w, 3);
    switch (FeI(x, 0x134)) {
    case 0:
        ((int (*)(void*, int))fn_80125128)(w, 0);
        if (FeI(x, 0x13C) == 0) {
            fn_80125154(w, 1);
        }
        ((int (*)(void*, int, int, int))fn_801251CC)(w, 2, 0x4DA3, 3);
        ((int (*)(void*, int, int, int))fn_801251CC)(w, 3, 0x1A2F, 2);
        break;
    case 1:
        if (FeI(fn_800B555C(), 0x628) != 0) {
            FeI(fn_800B555C(), 0x628) = 0;
        } else {
            fn_80125154(w, 1);
        }
        ((int (*)(void*, int))fn_80125128)(w, 0);
        ((int (*)(void*, int, int, int))fn_801251CC)(w, 3, 0x1A2F, 2);
        break;
    case 2:
        ((int (*)(void*, int))fn_80125128)(w, 0);
        fn_80125154(w, 1);
        break;
    case 3:
        ((int (*)(void*, int, int, int))fn_801251CC)(w, 2, 0x4DA3, 3);
        ((int (*)(void*, int))fn_80125128)(w, 0);
        break;
    }
}

}

struct FeW20B8 : Unk800C7B40_Data {
    virtual ~FeW20B8();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(int a); virtual void s30(); virtual void s31();
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
    virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90(); virtual void s91();
    virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95(); virtual void s96();
    virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100(); virtual void s101();
    virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105(); virtual void s106();
    virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110(); virtual void s111();
    virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115(); virtual void s116();
    virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120(); virtual void s121();
    virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125(); virtual void s126();
    virtual void s127();
};
extern "C" {
void fn_800DD204__FP3UiST0(void* a, void* b);
void fn_80492680(void* x, int a, int b, int c);
void fn_80495AB4(void* x);
void fn_804965E0(void* x);
}
extern char lbl_805F57D0[];
extern "C" FE_OVERLAY void fn_804920B8(void* xv, int s)
{
    FeW* x = (FeW*)xv;
    int old = FeI(x, 0x134);
    FeI(x, 0x134) = s;
    FeI(x, 0x138) = old;
    fn_80491F34(x);
    switch (FeI(x, 0x138)) {
    case 0:
        FeMem(x, 0x1D8)->fn_vslot8(0);
        FeMem(x, 0x1D8)->fn_vslot14(0);
        FeMem(x, 0x1DC)->fn_vslot8(0);
        FeMem(x, 0x1DC)->fn_vslot14(0);
        if ((unsigned)(FeI(x, 0x134) - 2) > 1) {
            x->fn_vslot32(lbl_805F57D0, 0)->fn_vslot8(0);
            FeMem(x, 0x1E8)->fn_vslot8(0);
        }
        break;
    case 1:
        fn_80126CF4((FeList*)FeP(x, 0x198), 0, FeI(FeP(x, 0x198), 0x168), FeI(FeP(x, 0x198), 0x134), FeI(FeP(x, 0x198), 0x16C), FeI(FeP(x, 0x198), 0x170), 0, FeI(FeP(x, 0x198), 0x138), FeI(FeP(x, 0x198), 0x13C), FeI(FeP(x, 0x198), 0x148), FeI(FeP(x, 0x198), 0x14C));
        fn_80126CF4((FeList*)FeP(x, 0x198), FeI(FeP(x, 0x198), 0x164), 0, FeI(FeP(x, 0x198), 0x134), FeI(FeP(x, 0x198), 0x16C), FeI(FeP(x, 0x198), 0x170), 0, FeI(FeP(x, 0x198), 0x138), FeI(FeP(x, 0x198), 0x13C), FeI(FeP(x, 0x198), 0x148), FeI(FeP(x, 0x198), 0x14C));
        FeMem(x, 0x21C)->fn_vslot16(1);
        FeMem(x, 0x1E4)->fn_vslot8(0);
        x->fn_vslot32(lbl_805F57D0, 0)->fn_vslot8(0);
        break;
    case 2:
        FeMem(x, 0x1E0)->fn_vslot14(0);
        FeMem(x, 0x1E0)->fn_vslot8(0);
        break;
    }
    switch (FeI(x, 0x134)) {
    case 0:
        x->fn_vslot32(lbl_805F57D0, 0)->fn_vslot8(1);
        ((FeW20B8*)FeMem(x, 0x230))->s29(0x3C9F);
        fn_800DD204__FP3UiST0(FeP(x, 0x230), FeP(x, 0x234));
        FeMem(x, 0x1E8)->fn_vslot8(1);
        fn_800C8060(FeMem(x, 0x1DC)->fn_vslot32(lbl_805F6934, 1))->fn_vslot67(0, 0);
        fn_800C8060(FeMem(x, 0x1D8)->fn_vslot32(lbl_805F6940, 1))->fn_vslot67(0, 0);
        fn_804965E0(x);
        if (FeI(x, 0x138) != 2) {
            fn_80492680(x, 0, 0, 0);
        }
        break;
    case 1: {
        int h = *(volatile int*)((char*)x + 0x15C);
        int g = *(volatile int*)((char*)x + 0x1E4);
        fn_800E3418(g, h, 1, 1);
        FeMem(x, 0x1E4)->fn_vslot8(1);
        x->fn_vslot32(lbl_805F57D0, 0)->fn_vslot8(1);
        ((FeW20B8*)FeMem(x, 0x230))->s29(0x2628);
        fn_800DD204__FP3UiST0(FeP(x, 0x230), FeP(x, 0x234));
        break;
    }
    case 2: {
        fn_80495AB4(x);
        FeW* w = fn_800C8060(FeMem(x, 0x1E0)->fn_vslot32(lbl_805F69E4, 1));
        w->fn_vslot14(1);
        w->fn_vslot67(0, 0);
        FeMem(x, 0x1E0)->fn_vslot8(1);
        break;
    }
    case 3:
        FeMem(x, 0x1D8)->fn_vslot14(0);
        FeMem(x, 0x1DC)->fn_vslot14(0);
        FeMem(x, 0x1E0)->fn_vslot14(0);
        if (FeI(x, 0x14C) == 0) {
            fn_800CFB38(FeP(x, 0x218));
        }
        break;
    }
}
