/*
 * Front-end overlay code, .frontend_codeoverlay 0x8045EDDC-0x80462504 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"


struct FeInfo3 {
    float f;
    int n;
    int m;
};
extern "C" {
float fn_800799D0__18Unk8007B2B0_Screeni(void* g, int a);
int fn_8007A6A0__18Unk8007A4DC_Screenii(void* g, int a, int b);
int fn_8007A270__18Unk8007A4DC_Screeni(void* g, int a);
void fn_8007A808__18Unk8007A4DC_Screeniii(void* g, int a, int b, int c);
int fn_80079264(void* g, int a, int b, float* c, float* d, float* e);
unsigned fn_8007F198__FP13Unk8007F198_A(void* g, int id);
void fn_8007F330__FP13Unk8007F198_Aii(void* g, int a, int b);
void fn_80528984(int a, void* x);
int fn_80461218(FeScrD* x, int i);
}

/* Widget view whose slot 51 takes (int a, int b). */
struct FeW51 : Unk800C7B40_Data {
    virtual ~FeW51();
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
    virtual void s51(int a, int b);
};

extern "C" {
int fn_80075948__18Unk8007B2B0_Screeni(void* g, int a);
int fn_8007B320__18Unk8007B2B0_Screenii(void* g, int a, int b);
FeW* fn_800C8054();
}
extern const char lbl_805F5804[];


typedef void (*FeCbF)(int, void*);
extern void* lbl_8061977C;
extern "C" {
const char* fn_80090880__FP11Unk80090880(void* t, int id);
int fn_800E5D74__Fi(int v);
void fn_800DE440(char* buf, int a, int b);
void fn_804031F8(char* out, const char* a, const char* b);
void fn_801321D4(FeW* o, void* self, FeCbF cb, int a, void* b, int c, int d, int e, const char* s1, const char* s2,
                 const char* s3, int f, int g, int h);
void fn_8045FE04(FeScrD* x);
void fn_804622F8(FeScrD* x, int v);
void fn_80462284(FeScrD* x, int a);
void fn_8045F760(int a, FeScrD* x);
}


extern const char lbl_805F57EC[];
extern const char lbl_805F4450[];
extern "C" {
FeW* fn_800C8060(FeW* w);
int fn_800A18E4(FeGlobal80619948* g);
int fn_8013484C();
void fn_80134854();
void fn_8007F29C__FP13Unk8007F198_Aii(void* g, int a, int b);
void fn_80079564(void* g, int a, int b);
}
void fn_800E4B70();


struct FeStr10 {
    char b[10];
};
extern FeStr10 lbl_805F57F8;
extern const char lbl_805F3CA8[];
extern const char lbl_805F5868[];
struct FeSt500 {
    char pad0[0x500];
    int m500;
};
extern "C" {
int fn_80528988(void);
void fn_800D0074(void* w, int a, int b);
void fn_80460278(FeScrD* x);
void fn_80460E70(FeScrD* x);
void fn_8045F974(int a, FeScrD* x);
}

extern "C" {

FE_OVERLAY int fn_8045EDDC(FeScrD* x)
{
    if (x->m14C != x->m144) {
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    }
    fn_804613EC(x, x->m144);
    return 0;
}

FE_OVERLAY int fn_8045EE30(void) { return 0; }

FE_OVERLAY int fn_8045EE38(FeScrD* x)
{
    if (x->m14C != x->m148) {
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    }
    fn_804613EC(x, x->m148);
    return 0;
}

FE_OVERLAY int fn_8045EE8C(void) { return 0; }

FE_OVERLAY int fn_8045EE94(FeScrD* x)
{
    FeW* w = x->m158;
    if ((FeW24(w) & 0x40000000) == 0 || x->m14C == x->m144) {
        x->m150->fn_vslot40(1);
    } else {
        w->fn_vslot40(1);
    }
    return 0;
}

FE_OVERLAY int fn_8045EF14(FeScrD* x, int a)
{
    FeW* w = x->m158;
    if ((FeW24(w) & 0x40000000) == 0 || x->m14C == x->m144) {
        x->m150->fn_vslot41(a);
    } else {
        w->fn_vslot41(a);
    }
    return 0;
}

FE_OVERLAY int fn_8045EF8C(FeScrD* x)
{
    FeW* w = x->m158;
    if ((FeW24(w) & 0x40000000) == 0 || x->m14C == x->m144) {
        x->m150->fn_vslot38(1);
    } else {
        w->fn_vslot38(1);
    }
    return 0;
}

FE_OVERLAY int fn_8045F00C(FeScrD* x)
{
    FeW* w = x->m158;
    if ((FeW24(w) & 0x40000000) == 0 || x->m14C == x->m144) {
        x->m150->fn_vslot39();
    } else {
        w->fn_vslot39();
    }
    return 0;
}

FE_OVERLAY int fn_8045F084(FeScrD* x)
{
    FeW* w = x->m67A8;
    int r;
    if ((FeW24(w) & 0x40000000) == 0) {
        r = 0;
    } else {
        w->fn_vslot40(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_8045F0D8(FeScrD* x, int a)
{
    FeW* w = x->m67A8;
    int r;
    if ((FeW24(w) & 0x40000000) == 0) {
        r = 0;
    } else {
        w->fn_vslot41(a);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_8045F128(FeScrD* x)
{
    FeW* w = x->m67A8;
    int r;
    if ((FeW24(w) & 0x40000000) == 0) {
        r = 0;
    } else {
        w->fn_vslot38(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_8045F17C(FeScrD* x)
{
    FeW* w = x->m67A8;
    int r;
    if ((FeW24(w) & 0x40000000) == 0) {
        r = 0;
    } else {
        w->fn_vslot39();
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_8045F1CC(FeScrD* x, FeW* w)
{
    if (w == x->m144) {
        fn_804613EC(x, w);
    } else if (w == x->m148) {
        fn_804613EC(x, w);
    } else {
        FeW* r = fn_800C8060(x->fn_vslot32(lbl_805F57EC, 1));
        if (w == r) {
            x->fn_vslot67(7, -1);
        }
    }
    return 0;
}

FE_OVERLAY int fn_8045F27C(FeScrD* x, FeW* w, int unused, int a)
{
    if (w == x->m144) {
        fn_804613EC(x, w);
        w->fn_vslot68(a);
        x->fn_vslot67(8, fn_800C8070(x));
    } else if (w == x->m148) {
        fn_804613EC(x, w);
        w->fn_vslot68(a);
        x->fn_vslot67(8, fn_800C8070(x));
    }
    return 0;
}

FE_OVERLAY void fn_8045F374(FeScrD* x)
{
    fn_80460750(x);
}

FE_OVERLAY void fn_8045F6FC(FeScrD* x, FeStr10* out)
{
    if (x->m138 != 0) {
        *out = lbl_805F57F8;
    } else {
        out->b[0] = 0;
    }
}

FE_OVERLAY void fn_8045F734(FeScrD* x, FeScrD* y)
{
    if (x != 0) {
        fn_8045FBF8(y);
    }
}

FE_OVERLAY void fn_8045F760(int a, FeScrD* x)
{
    if (a == 1) {
        void* g = lbl_8061930C;
        int id = fn_80461218(x, x->m144->fn_vslot60());
        int k = x->m140;
        FeInfo3 s;
        s.f = fn_800799D0__18Unk8007B2B0_Screeni(g, fn_8007A6A0__18Unk8007A4DC_Screenii(g, 0x18, id));
        s.n = fn_8007A6A0__18Unk8007A4DC_Screenii(g, 0x19, id) > 1 ? fn_8007A6A0__18Unk8007A4DC_Screenii(g, 0x19, id) : 1;
        s.m = fn_8007A270__18Unk8007A4DC_Screeni(g, id) != 0 ? 0xE : 0xB;
        int r = 0;
        if (x->m134 == 4) {
            if (fn_8007F198__FP13Unk8007F198_A(g, k) <= 0x18U) {
                fn_8007F330__FP13Unk8007F198_Aii(g, k, id);
                if (fn_8007A6A0__18Unk8007A4DC_Screenii(g, 0x19, id) == 0)
                    fn_8007A808__18Unk8007A4DC_Screeniii(g, 0x19, id, 1);
            } else {
                r = 2;
            }
        } else {
            r = fn_80079264(g, id, k, &s.f, &s.f, &s.f);
        }
        if (r == 0) {
            ((FeWV*)x)->s38();
            ((FeWV*)x)->s37();
        } else if (r == 2) {
            fn_80131F34(x->m15C, x, (FeCbF)fn_80528984, (int)fn_80528988, 0x1A44, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
            x->m15C->fn_vslot86();
        }
    }
}

FE_OVERLAY void fn_8045F974(int a, FeScrD* x)
{
    if (a == 1) {
        fn_80126CF4((FeList*)x->m174, 0, ((FeList*)x->m174)->m168, ((FeList*)x->m174)->m134, ((FeList*)x->m174)->m16C,
                    ((FeList*)x->m174)->m170, 0, ((FeList*)x->m174)->m138, ((FeList*)x->m174)->m13C,
                    ((FeList*)x->m174)->m148, ((FeList*)x->m174)->m14C);
        fn_80126CF4((FeList*)x->m174, ((FeList*)x->m174)->m164, 0, ((FeList*)x->m174)->m134, ((FeList*)x->m174)->m16C,
                    ((FeList*)x->m174)->m170, 0, ((FeList*)x->m174)->m138, ((FeList*)x->m174)->m13C,
                    ((FeList*)x->m174)->m148, ((FeList*)x->m174)->m14C);
        x->m13C = a;
        x->fn_vslot16(0);
        FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F84);
        p->fn_vslot16(0);
        p->fn_vslot8(0);
    }
}

FE_OVERLAY void fn_8045FAB8(int a, FeScrD* x)
{
    if (a == 1) {
        int idx = x->m144->fn_vslot60();
        fn_80461228(x, fn_80461218(x, idx));
    }
}

FE_OVERLAY void fn_8045FB1C(int a, FeScrD* x)
{
    if (a == 1) {
        fn_800E4B70();
        FeMsg m;
        FeMsg* mp = &m;
        fn_8035682C(mp);
        ((FeSub*)((char*)x->m154 + 0xDC))->s6(((FeSub*)((char*)x->m154 + 0xDC))->s13() - 1);
        fn_8040B830(mp->name, lbl_805F4450, 15);
        mp->name[15] = 0;
        fn_800B555C()->m508 = -1;
        fn_800B7B4C(FeGetMgr(), mp, x);
    }
}

FE_OVERLAY void fn_8045FBF8(FeScrD* x)
{
    void* g = lbl_8061930C;
    int v = x->m6730[x->m148->fn_vslot60()];
    if (x->m134 == 4) {
        fn_8007F29C__FP13Unk8007F198_Aii(g, x->m140, v);
    } else {
        fn_80079564(g, v, 0);
    }
    ((FeWV*)x)->s38();
    ((FeWV*)x)->s37();
}

FE_OVERLAY void fn_8045FCAC(void) {}

FE_OVERLAY void fn_8045FCB0(FeScrD* x, int a)
{
    fn_800ED310(x, a);
    x->m14C->fn_vslot14(a);
}

FE_OVERLAY int fn_8045FD00(FeScrD* x)
{
    switch (((FeSub*)((char*)x->m154 + 0xDC))->s5()) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 4;
    case 4:
        return 5;
    case 5:
        return 7;
    case 6:
        return 6;
    case 7:
        return 8;
    case 8:
        return 0;
    case 9:
        break;
    case 10:
        return -1;
    }
    return 10;
}

FE_OVERLAY void fn_80460714(FeScrD* x)
{
    x->m160->fn_vslot8(0);
}

FE_OVERLAY int fn_80461218(FeScrD* x, int i)
{
    return x->m3468[i];
}

FE_OVERLAY void fn_80461228(FeScrD* x, int unused)
{
    int r = fn_800A18E4(lbl_80619948);
    if (r != 0) {
        int v;
        switch (r) {
        case 1:
            v = 0x3D72;
            break;
        case 2:
            v = 0x3D73;
            break;
        default:
            v = 0x3E9;
            break;
        }
        fn_80131F34(x->m15C, x, fn_80134854, (int)fn_8013484C, v, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
        x->m15C->fn_vslot86();
    }
}

FE_OVERLAY int fn_804612F0(FeScrD* x)
{
    if (x->m14C == x->m144) {
        return x->m174->fn_vslot86() != 0;
    }
    if (x->m14C == x->m148) {
        return x->m174->fn_vslot87() != 0;
    }
    return 0;
}

FE_OVERLAY int fn_80461370(FeScrD* x)
{
    int r = 0;
    if (x->m174->fn_vslot86() != 0 || x->m174->fn_vslot87() != 0) {
        r = 1;
    }
    return r;
}

FE_OVERLAY void fn_804613EC(FeScrD* x, FeW* w)
{
    x->m14C->fn_vslot14(0);
    x->m14C = w;
    w->fn_vslot14(1);
    if (w == x->m148) {
        x->m174->fn_vslot84(1, 0);
        if (x->m134 == 4) {
            x->m150->fn_vslot16(0);
            x->m158->fn_vslot16(1);
        } else if (x->m134 == 1) {
            x->m150->fn_vslot16(fn_80461370(x) ^ 1);
        }
    } else if (w == x->m144) {
        x->m174->fn_vslot84(0, 0);
        if (x->m134 == 4) {
            x->m150->fn_vslot16(fn_80461370(x) ^ 1);
            x->m158->fn_vslot16(0);
        } else if (x->m134 == 1) {
            x->m150->fn_vslot16(fn_80461370(x) ^ 1);
        }
    }
    fn_80460750(x);
}

FE_OVERLAY int fn_804615C4(FeScrD* x)
{
    return (unsigned)(x->m134 - 2) <= 2;
}

FE_OVERLAY void fn_804615DC(FeScrD* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F3CA8, 15);
    mp->name[15] = 0;
    FeSt500* s = (FeSt500*)((char*)fn_800B555C() + 8);
    s->m500 = x->m144->fn_vslot60();
    fn_800B7B4C(FeGetMgr(), mp, x);
}

FE_OVERLAY void fn_80461688(FeScrD* x, FeW* w)
{
    if (w == x->m150) {
        fn_8045FE04(x);
        fn_80460278(x);
        fn_80460750(x);
    }
    if (w == x->m67A8) {
        fn_80462284(x, ((FeSub*)((char*)x->m67AC + 0xDC))->s5());
    }
    if (w == x->m67A8 || w == x->m158) {
        int v = ((FeSub*)((char*)x->m67B4 + 0xDC))->s21();
        x->m140 = v;
        fn_804622F8(x, v);
        fn_8045FE04(x);
        fn_80460278(x);
        fn_80460714(x);
        fn_80460E70(x);
        fn_80460750(x);
    }
}

FE_OVERLAY void fn_80461780(FeScrD* x, int unused, int a)
{
    x->m140 = a;
    fn_80460278(x);
    fn_80460714(x);
    fn_80460E70(x);
    fn_80460750(x);
}

FE_OVERLAY void fn_804617C8(FeScrD* x)
{
    if (x->m134 == 1) {
        fn_80131F34(x->m15C, x, (FeCbF)fn_8045FB1C, 0, 0x4D9C, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
        x->m15C->fn_vslot86();
    } else {
        FeMsg m;
        FeMsg* mp = &m;
        fn_8035682C(mp);
        ((FeSub*)((char*)x->m154 + 0xDC))->s6(((FeSub*)((char*)x->m154 + 0xDC))->s13() - 1);
        fn_8040B830(mp->name, lbl_805F4450, 15);
        mp->name[15] = 0;
        fn_800B555C()->m508 = -1;
        fn_800B7B4C(FeGetMgr(), mp, x);
    }
}

FE_OVERLAY void fn_80461910(FeScrD* x)
{
    char big[2000];
    char small[400];
    fn_800DE440(small, x->m3468[x->m144->fn_vslot60()], 1);
    fn_804031F8(big, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x38D1), small);
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(x->m15C, x, (FeCbF)fn_8045FAB8, (int)fn_80528988, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    x->m15C->fn_vslot86();
}

FE_OVERLAY void fn_80461A14(FeScrD* x)
{
    char big[2000];
    char small[400];
    fn_800DE440(small, x->m3468[x->m144->fn_vslot60()], 1);
    fn_804031F8(big, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x38D0), small);
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(x->m15C, x, (FeCbF)fn_8045F760, (int)fn_80528988, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    x->m15C->fn_vslot86();
}

FE_OVERLAY void fn_80461B18(FeScrD* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    int idx = fn_80461218(x, x->m144->fn_vslot60());
    fn_800B555C()->m30 = idx;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F3CA8, 15);
    mp->name[15] = 0;
    FeSt500* s = (FeSt500*)((char*)fn_800B555C() + 8);
    s->m500 = x->m144->fn_vslot60();
    fn_800B7B4C(FeGetMgr(), mp, x);
}

FE_OVERLAY void fn_80461BF8(FeScrD* x)
{
    char big[2000];
    char small[400];
    int v = x->m6730[x->m148->fn_vslot60()];
    fn_800DE440(small, v, 1);
    fn_804031F8(big, fn_80090880__FP11Unk80090880(lbl_8061977C, fn_800E5D74__Fi(v)), small);
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(x->m15C, x, (FeCbF)fn_8045F734, (int)fn_80528988, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    x->m15C->fn_vslot86();
}

FE_OVERLAY void fn_80461D0C(FeScrD* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F5868, 15);
    mp->name[15] = 0;
    FeSt500* s = (FeSt500*)((char*)fn_800B555C() + 8);
    s->m500 = x->m144->fn_vslot60();
    fn_800B7B4C(FeGetMgr(), mp, x);
}

FE_OVERLAY void fn_80461DB8(FeScrD* x)
{
    int v = 0x5CFE;
    if (x->m134 == 1) {
        v = 0x38D2;
    }
    fn_80131F34(x->m15C, x, (FeCbF)fn_8045F974, (int)fn_80528988, v, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    x->m15C->fn_vslot86();
}

FE_OVERLAY void fn_80462284(FeScrD* x, int a)
{
    fn_800D0074((char*)x->m67B0 + 0x98, a, 1);
    fn_800D0074((char*)x->m67B4 + 0xDC, a, 1);
    x->m140 = ((FeSub*)((char*)x->m67B4 + 0xDC))->s21();
}

FE_OVERLAY void fn_804622F8(FeScrD* x, int a)
{
    ((FeSub*)((char*)x->m67B0 + 0x98))->s20(a, 1);
    ((FeSub*)((char*)x->m67B4 + 0xDC))->s20(a, 1);
    x->fn_vslot29(lbl_805F5804);
    FeSub* s0 = (FeSub*)((char*)fn_800C8054() + 0x98);
    s0->s20(a, 1);
    int g = fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, a);
    ((FeSub*)((char*)x->m67AC + 0xDC))->s15();
    int t0 = fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, 0, g);
    ((FeW51*)x->m67AC)->s51(0x3FB7, t0);
    int t1 = fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, 1, g);
    ((FeW51*)x->m67AC)->s51(0x3FB8, t1);
    int t2 = fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, 2, g);
    ((FeW51*)x->m67AC)->s51(0x3FB9, t2);
    int t3 = fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, 3, g);
    ((FeW51*)x->m67AC)->s51(0x5975, t3);
    FeSub* s = (FeSub*)((char*)x->m67AC + 0xDC);
    ((FeSub*)((char*)x->m67AC + 0xDC))->s6(s->s7(a));
}

}
