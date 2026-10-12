/*
 * Front-end overlay code, .frontend_codeoverlay 0x804BFB3C-0x804C19EC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"
class FeV1Cx {
public:
    char pad0[0x1C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10(int a, int b, int c);
};
struct FeScrC : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    char pad13C[4];
    FeW* m140;
    char pad144[0x14C - 0x144];
    FeW* m14C;
    char pad150[0x158 - 0x150];
    FeV1Cx* m158;
};
extern void* lbl_8061977C;
extern "C" void fn_80329FA0(void*, ...);
extern "C" int fn_8007FBC0__FP13Unk8007F198_Cii(void* g, int a, int b);
extern "C" void fn_800DD44C__FP13Unk800DD610_PPvi(void* a, void* b, int c);
extern "C" const char* fn_80090880__FP11Unk80090880(void* g, int id);
extern "C" void fn_80403DE4(char* dst, const char* fmt, ...);
extern char lbl_805F7EE8[];
struct FeS8 {
    char pad0[0x650];
    int m650;
    int m654;
};
struct FeScrGrid;
extern "C" void fn_80445454(FeScrGrid* x);
extern "C" void fn_80125154(void* w, int a);
extern "C" int fn_80075948__18Unk8007B2B0_Screeni(void* g, int a);
extern "C" int fn_8007B320__18Unk8007B2B0_Screenii(void* g, int a, int b);
extern "C" FeVt20* fn_80446AD4(FeScrGrid* x);
struct FeElemR;
struct FeWVa : Unk800C7B40_Data {
    virtual ~FeWVa();
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
    virtual FeW* s73(int a, int b);
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
    virtual FeElemR* s90(int a, int b);
};
extern char lbl_805F5198[];
struct FeScrGrid;
extern "C" void fn_80445190(FeScrGrid* x);
extern "C" FeW* fn_800C8060(FeW* w);
struct FeElemR {
    char pad0[0x20];
    const void* m20;
    int m24;
};
class FeElemV0 {
public:
    char pad0[0x20];
    virtual void s1(int c);
};
class FeElemV : public FeElemV0 {
public:
    int m24;
};
struct FeScrGrid : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[0x14C - 0x134];
    int m14C;
    char pad150[0x164 - 0x150];
    int m164;
    FeElemR m168[35];
};
extern char lbl_806700C0[];
extern char lbl_8067CBD0[];
extern "C" FeElemR* fn_804447F0(FeElemR* e);
extern "C" void* fn_80445104(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_800C203C(char* p);
extern "C" void fn_800C2034(char* p, int a);
extern "C" int fn_8056A2F8(int o, int cur, int mode, int a, int b, void* who, int p6, int p7, int s8, int sC);
extern "C" void fn_80445B74(FeScrN* x);
extern "C" void fn_80445BB4(FeScrN* x, int a);
struct FeRecA {
    char pad0[8];
    int m8;
    char padC[4];
    int m10;
    int m14;
};
struct FeM30 {
    char pad0[0x10];
    int m10;
};
struct FeMA {
    char pad0[0x30];
    FeM30* m30;
};
extern "C" int fn_80596538(int h, int a);
extern char lbl_805F4450[];
extern "C" void fn_804C0EC0(FeScrN* x);
extern "C" void fn_800C4C48(void* m, FeW* w, int idx);
struct FeEnt594240 {
    float m0;
    char pad4[0xC];
    int m10;
};
extern "C" FeEnt594240* fn_80594240(FeW* l, int i);
extern const char lbl_8066FE18[];
extern char lbl_805F7944[];

extern "C" void fn_804C1100(void* x);
extern "C" void fn_804C13F8(FeScrN* x);
extern const char lbl_806703A0[];
extern const char lbl_8067CEB0[];
extern int lbl_80621964;
extern int lbl_8062196C;
extern int lbl_80621640;
extern "C" void fn_80377408(void* p);
extern "C" int fn_8056A5B0(int a, int b, int c, int d);
extern "C" void fn_804BFD98(FeObjP* x);
extern "C" void* fn_804C0620(char* p, int i, int j);
extern "C" void fn_804C0BD8(FeScrN* x);
extern "C" void fn_804C10D4(int a, void* x);
extern "C" void fn_804C1484(FeScrN* x);
extern "C" int fn_804C1640(FeScrN* x);
extern "C" int fn_804C1778(FeScrN* x);
extern "C" int fn_804C19AC(FeScrN* x);
extern "C" void fn_804C0298(FeVt20* x);
extern "C" void fn_804BFB3C(FeD20* self, int c);
extern "C" char* fn_804C05E0(char* p, int i);
extern "C" int fn_804BFDE8(FeObj10* x);

extern "C" FE_OVERLAY void fn_804BFB3C(FeD20* self, int c)
{
    self->m20 = lbl_806703A0;
    lbl_80621964 = 0;
    lbl_80621968 = 0;
    lbl_8062196C = 0;
    self->m20 = lbl_8067CEB0;
    lbl_80621640 = 0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_804BFD98(FeObjP* x)
{
    x->m24->fn_vslot8(0);
    fn_80444890(x);
}

extern "C" FE_OVERLAY int fn_804BFDE8(FeObj10* x)
{
    if (x->m10 != -1
        && fn_8056A5B0(((Fe19948X*)lbl_80619948)->m28, ((FeStateX*)fn_800B555C())->m608, x->m10, lbl_8062163C) == 0) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804C0208(FeRecA* o)
{
    int r = 0;
    if (o->m8 == 1 || o->m8 == 4) {
        r = 1;
    }
    if (r != 0) {
        int b = o->m14;
        int h = ((FeMA*)lbl_8061930C)->m30->m10;
        r = fn_80596538(h, o->m10) ^ 1;
        if (r == 0 && b > -1) {
            r = fn_80596538(h, b) ^ 1;
        }
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804C0298(FeVt20* x)
{
    fn_800E5404(lbl_80621968, x->s13(), lbl_8062163C);
}

extern "C" FE_OVERLAY FeScrGrid* fn_804C02F0(FeScrGrid* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    FeElemR* row = self->m168;
    int i = 4;
    fn_80445104(self, a, b, c, d, e, f, g, h);
    self->m164 = 0;
    self->SetVptr(lbl_806700C0);
    do {
        FeElemR* el = row;
        int j = 6;
        do {
            fn_804447F0(el);
            el->m20 = lbl_806703A0;
            el->m24 = 0;
            el++;
        } while (j-- != 0);
        row += 7;
    } while (i-- != 0);
    self->m164 = fn_800C203C((char*)fn_800B555C() + 8);
    fn_800C2034((char*)fn_800B555C() + 8, 0);
    return self;
}

extern "C" FE_OVERLAY void fn_804C0458(FeScrGrid* x)
{
    int r = 0;
    fn_80445190(x);
    FeW* w = fn_800C8060(x->fn_vslot32(lbl_805F5198, 1));
    for (; r <= 4; r++) {
        for (int c = 0; c <= 6; c++) {
            FeElemR* e = ((FeWVa*)x)->s90(r, c);
            e->m24 = (int)((FeWVa*)w)->s73(r, c);
        }
    }
}

extern "C" FE_OVERLAY void fn_804C0518(FeScrGrid* x)
{
    fn_80445454(x);
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125154(p, -2);
    int a = fn_800C203C((char*)fn_800B555C() + 8);
    int b = fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, a);
    x->m14C = fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, 0, b);
    fn_80446AD4(x)->s3();
}

extern "C" FE_OVERLAY char* fn_804C05E0(char* p, int i)
{
    return p + ((i / 7) * 0x118 + 0x168) + (i % 7) * 0x28;
}

extern "C" FE_OVERLAY void* fn_804C0620(char* p, int i, int j)
{
    return p + (i * 0x118 + 0x168) + j * 0x28;
}

extern "C" FE_OVERLAY void fn_804C0638(FeW* x, FeRecA* y)
{
    FeMsg m;
    FeMsg* p = &m;
    int b = y->m10;
    int a = y->m14;
    FeS8* s = (FeS8*)((char*)fn_800B555C() + 8);
    s->m650 = b;
    s->m654 = a;
    ((FeWV*)x)->s40();
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805F7EE8, 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
}

extern "C" FE_OVERLAY void fn_804C06EC(FeScrN* x)
{
    int r = fn_8056A2F8(((Fe19948X*)lbl_80619948)->m28, 0, 0, 1, 0, x->m14C, 0, 0, 0, 0x1A);
    if (r != -1) {
        fn_80445BB4(x, fn_8007FBC0__FP13Unk8007F198_Cii(lbl_8061930C, r, 0));
    } else {
        fn_80445B74(x);
    }
}

extern "C" FE_OVERLAY FeScrN* fn_804C0784(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066FE18);
    self->m134 = (FeW*)1;
    self->m130 = 0;
    self->m138 = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804C0BD8(FeScrN* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804C0C00(FeScrC* x)
{
    char b8[0xC8];
    char bD0[0xC8];
    int d[2];
    int o = x->m138 * 4;
    char* b = (char*)x + 0x19C;
    fn_80329FA0(d, fn_8007FBC0__FP13Unk8007F198_Cii(lbl_8061930C, *(int*)(b + o), 0));
    fn_800DD44C__FP13Unk800DD610_PPvi(d, b8, 2);
    if (x->m134 != 0) {
        fn_80403DE4(bD0, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x176F), x->m138 + 1, b8);
        x->m140->fn_vslot28(bD0);
    } else {
        x->m140->fn_vslot28(b8);
    }
}

extern "C" FE_OVERLAY void fn_804C10D4(int a, void* x)
{
    if (a == 1) {
        fn_804C1100(x);
    }
}

extern "C" FE_OVERLAY void fn_804C1100(void* v)
{
    FeScrC* x = (FeScrC*)v;
    FeMsg m;
    FeMsg* p = &m;
    int k = x->m14C->fn_vslot60();
    int o1 = k * 4;
    int o2 = x->m138 * 4;
    char* b1 = (char*)x + 0x15C;
    char* b2 = (char*)x + 0x19C;
    x->m158->s10(k, *(int*)(b1 + o1), *(int*)(b2 + o2));
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805F5284, 15);
    p->name[15] = 0;
    x->fn_vslot80(1);
    fn_800B7B4C(FeGetMgr(), p, x);
}

extern "C" FE_OVERLAY float fn_804C1384(FeScrN* x, int i)
{
    FeEnt594240* p = fn_80594240(x->m158, i);
    int o = i * 4;
    char* b = (char*)x + 0x15C;
    float v = (float)*(int*)(b + o) * p->m0;
    return v;
}

extern "C" FE_OVERLAY void fn_804C13F8(FeScrN* x)
{
    int k = x->m14C->fn_vslot60();
    fn_800C4C48(fn_800C33D0(), x->m150, k);
    x->m154->fn_vslot29((const char*)fn_80594240(x->m158, k)->m10);
}

extern "C" FE_OVERLAY void fn_804C1484(FeScrN* x)
{
    fn_804C13F8(x);
}

extern "C" FE_OVERLAY void fn_804C14A4(FeScrN* x, int k)
{
    switch (k) {
    case 0: {
        FeMsg m;
        FeMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    }
    case 1:
        fn_804C0EC0(x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_804C1544(FeScrN* x)
{
    ((FeWV*)fn_800C805C(x->m14C->fn_vslot70()->fn_vslot32(lbl_805F7944, 1)))->s41();
    fn_800C805C(x->m14C->fn_vslot70()->fn_vslot32(lbl_805F7944, 1))->fn_vslot39();
    x->m14C->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C1640(FeScrN* x)
{
    x->m14C->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C167C(FeScrN* x)
{
    ((FeWV*)fn_800C805C(x->m14C->fn_vslot70()->fn_vslot32(lbl_805F7944, 1)))->s41();
    fn_800C805C(x->m14C->fn_vslot70()->fn_vslot32(lbl_805F7944, 1))->fn_vslot39();
    x->m14C->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C1778(FeScrN* x)
{
    x->m14C->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C17B4(FeScrN* x)
{
    fn_800C805C(x->m14C->fn_vslot70()->fn_vslot32(lbl_805F7944, 1))->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804C1834(FeScrN* x)
{
    ((FeWV*)fn_800C805C(x->m14C->fn_vslot70()->fn_vslot32(lbl_805F7944, 1)))->s41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C18B0(FeScrN* x)
{
    fn_800C805C(x->m14C->fn_vslot70()->fn_vslot32(lbl_805F7944, 1))->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804C1930(FeScrN* x)
{
    fn_800C805C(x->m14C->fn_vslot70()->fn_vslot32(lbl_805F7944, 1))->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C19AC(FeScrN* x)
{
    x->m144->fn_vslot40(1);
    return 1;
}
