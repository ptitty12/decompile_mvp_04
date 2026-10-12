/*
 * Front-end overlay code, .frontend_codeoverlay 0x80512D10-0x80516990 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"
struct FeRec84;
struct FeRecP {
    char pad0[0x78];
    int m78[4];
    int m88;
    char pad8C[0x98 - 0x8C];
    FeW* m98;
    FeW* m9C;
    char padA0[0xA8 - 0xA0];
    FeW* mA8;
    char padAC[0xB4 - 0xAC];
    FeW* mB4;
};
struct FeWl : Unk800C7B40_Data {
    virtual ~FeWl();
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
    virtual void s67(); virtual int s68(int a); virtual void s69(); virtual void s70(); virtual void s71();
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
struct FeWk : Unk800C7B40_Data {
    virtual ~FeWk();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(int a); virtual void s45(); virtual void s46();
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
struct FeWj : Unk800C7B40_Data {
    virtual ~FeWj();
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
    virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100(); virtual void s101();
    virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105(); virtual void s106();
    virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110(); virtual void s111();
    virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115(); virtual void s116();
    virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120(); virtual void s121();
    virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125(); virtual void s126();
    virtual void s127();
};
struct FeWi : Unk800C7B40_Data {
    virtual ~FeWi();
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
    virtual void s67(); virtual void s68(); virtual void s69(int a); virtual void s70(); virtual void s71();
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
struct FeRecO {
    char pad0[0x94];
    FeW* m94;
    FeW* m98;
    FeW* m9C;
    FeW* mA0;
    FeW* mA4;
    FeW* mA8;
    FeW* mAC;
    FeW* mB0;
};
struct FeLst {
    char* m0;
    unsigned m4;
    int m8;
    unsigned mC;
    const void* m10;
    int m14;
};
class FeSubK {
public:
    char pad0[0x24];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8(int a);
    virtual void s9();
    virtual void s10();
    virtual int s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20(int a, int b);
    virtual int s21();
};
struct FeWh : Unk800C7B40_Data {
    virtual ~FeWh();
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
    virtual void s82(); virtual void s83(); virtual void s84(int a); virtual void s85(); virtual void s86();
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
struct FeWg : Unk800C7B40_Data {
    virtual ~FeWg();
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
    virtual void s92(); virtual int s93(int a, int b); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};
struct FeRec84 {
    char pad0[4];
    int m4[29];
    int m78[3];
    int m84;
    int m88;
    int m8C;
    int m90;
    FeW* m94;
    FeW* m98;
};
struct FeP298_1E0 { char pad[0x1E0]; FeW* m1E0; char pad2[0x298 - 0x1E0 - 4]; FeW* m298; };
extern "C" int fn_800B57EC(void* s);
extern "C" int fn_80516B1C(void* x);
extern "C" int fn_80545428(void* s, int a, int* out);
extern "C" void fn_80523824(void* p, void* self, int a, FeCbF cb, int b, int c, int d);
extern "C" void fn_80523C94(void* p, int a, int b, int c, int d);
extern "C" void fn_80516990(int a, void* x);
extern const char lbl_805FBA5C[];
extern "C" int sprintf(char*, const char*, ...);
extern "C" int fn_8007A6A0__18Unk8007A4DC_Screenii(void* g, int a, int b);
extern "C" float fn_8007A768__18Unk8007A4DC_Screenii(void* g, int a, int b);
extern "C" float fn_80079EFC__18Unk8007B2B0_Screeni(void* g, int a);
extern "C" int fn_800E5F38__Fi(int v);
extern "C" float fn_800E0164__Ff();
extern "C" void fn_8007824C(int v, int a);
extern "C" int fn_800DE440(unsigned short* buf, int a, int b);
extern "C" int fn_800DF254(unsigned short* buf, int a, int b, float f);
extern const char lbl_805F5010[];
extern "C" int fn_800C8070(void* x);
extern "C" int fn_805165B4(void* self, int w, int a, FeRec84* r);
extern "C" void fn_80516880(int unused, FeScrQ* x);
extern "C" int fn_800C2184(void* p);
extern "C" void fn_80599B24(void* s);
extern "C" void fn_80516DF0(void* a, void* b, void* w);
extern "C" void fn_805170C0(void* x, void* s);
extern "C" int fn_80545AFC(void* s);
extern "C" void fn_80546258(void* s);
extern "C" void fn_80134858(void* p);
extern "C" void fn_80134CD0(void* p);
extern "C" void fn_800E5100__FPUsi(unsigned short* out, void* s);
extern "C" const char* fn_80090880__FP11Unk80090880(void* t, int id);
extern void* lbl_8061977C;
extern "C" int fn_800A2EB4(void* g);
extern "C" int fn_800A2E6C(void* g);
extern "C" FeW* fn_800C8060(FeW* w);
extern "C" FeW* fn_800C8048(FeW* w);
extern "C" void fn_804A7760(void* p);
extern const char lbl_805FB920[];
extern const char lbl_805F5C28[];
extern const char lbl_805F4F84[];
extern const char lbl_805FB92C[];
extern const char lbl_805F4F20[];
extern "C" int fn_80075948__18Unk8007B2B0_Screeni(void* g, int a);
extern "C" int fn_800757B8__18Unk8007B2B0_Screeni(void* g, int a);
extern "C" void fn_80516B6C(void* x);
extern "C" void fn_80514C3C(FeScrQ* x, FeRecO* o);
extern "C" int fn_80516DA8(void* self, FeRecO* t, int k);
extern "C" void fn_800D0074(void* a, int b, int c);
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A4C8[];
extern "C" void fn_8040074C(void* p, int n);
extern "C" void fn_80535650(FeLst* l, int a);
extern "C" void fn_80539128(FeLst* l, int a);
extern "C" void fn_805362AC(FeLst* l, int a);
extern "C" int fn_8007F7D0__FP13Unk8007F198_BUi(void* g, unsigned i);
extern "C" int fn_8007B320__18Unk8007B2B0_Screenii(void* g, int a, int b);
extern "C" void fn_80514020(void* self, FeRec84* x);
extern "C" void fn_805169BC(int a, void* x);
extern "C" int fn_8052851C(void);
extern const char lbl_805F4F0C[];
extern "C" void fn_80514E3C(FeScrQ* self, FeRec84* r, int id);
extern "C" unsigned fn_80599C40(int w, int a);
extern "C" int fn_80599C50(int w, int a, int b);
extern "C" int fn_80516ACC(void* x);
extern "C" void fn_80516FEC(void* x);
extern "C" void fn_805168D8(void* self, FeRec84* x);
extern const char lbl_8067EED0[];
extern const char lbl_805FB9A8[];
extern const char lbl_805FB970[];
extern "C" void fn_8051457C(FeScrQ* x, void* y);
extern "C" void fn_805146C0(FeScrQ* x, void* y);
extern "C" void fn_805148D0(FeScrQ* x, void* y);
extern "C" void fn_805140D8(FeScrQ* x);
extern const char lbl_80667920[];
extern "C" FeScrN* fn_80512D10(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80512D60(FeScrD* x);
extern "C" int fn_80512F8C(FeScrK* x);
extern "C" int fn_80512FF8(FeScrB* x);
extern "C" int fn_80513054(FeScrN* x);
extern "C" int fn_80513090(FeScrN* x);
extern "C" int fn_805130CC(FeScrN* x);
extern "C" int fn_80513108(FeScrN* x);
extern "C" void fn_80513144(FeScrN* x, char* dst);
extern "C" int fn_805131B8(FeScrB* x);
extern "C" FeScrQ* fn_80513214(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80513270(FeScrD* x);
extern "C" void fn_80514340(FeScrQ* x, int a);
extern "C" void fn_80514538(FeScrQ* x);
extern "C" void fn_80514B78(void* self, FeP0B0* y);
extern "C" void fn_80514DB0(FeScrQ* x, void* y);
extern "C" int fn_80514DF8(void* self, FeIdTab* y, int v);
extern "C" int fn_805153AC(FeP2A8* x);
extern "C" void fn_805158B0();
extern "C" int fn_80515ED8(FeScrQ* x, int a);
extern "C" int fn_80515F64();
extern "C" int fn_80515F6C(FeScrQ* x, int a);
extern "C" int fn_80516014();
extern "C" int fn_8051601C(FeP2A8* x);
extern "C" int fn_8051605C(FeP2A8* x);
extern "C" int fn_8051609C(FeP2A8* x);
extern "C" int fn_805160DC(FeP2A8* x);
extern "C" int fn_8051611C(FeScrQ* x);
extern "C" int fn_805161E0(FeScrN* x);
extern "C" int fn_8051628C(FeScrQ* x);
extern "C" int fn_80516350(FeScrN* x);
extern "C" int fn_805163FC(FeScrQ* x);
extern "C" int fn_80516474(FeP298_1E0* x);
extern "C" int fn_805164D8(FeScrQ* x);
extern "C" int fn_80516550(FeP298_1E0* x);
extern "C" void fn_8051687C();
inline void FmtSecs(float f, unsigned short* b)
{
    fn_800DF254(b, 0, 3, f);
}
inline int& FeI(void* p, int off)
{
    return *(int*)((char*)p + off);
}
inline FeW*& FeP(void* p, int off)
{
    return *(FeW**)((char*)p + off);
}

extern "C" FE_OVERLAY FeScrN* fn_80512D10(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80667920);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80512D60(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_80512D80(FeScrN* x)
{
    fn_800ECF18(x);
    void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125100(p);
    fn_801250D8(p);
    x->fn_vslot32(lbl_805FB920, 1)->fn_vslot8(0);
    x->m134 = fn_800C8060(x->fn_vslot32(lbl_805F5C28, 1));
    ((FeWj*)x->m134)->s88(1);
    if (fn_800A2EB4(lbl_80619948) == 1) {
        ((FeWV*)fn_800C8048(x->m134->fn_vslot73(4, 0)->fn_vslot32(lbl_805FB92C, 1)))->s29(0x385E);
    } else if (fn_800A2E6C(lbl_80619948) != 0) {
        void* p2 = fn_800B7A94(FeGetMgr(), lbl_805F4F20);
        ((FeW*)p2)->fn_vslot8(0);
        fn_804A7760(p2);
    }
    x->m134->fn_vslot8(1);
}

extern "C" FE_OVERLAY int fn_80512F8C(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80512FF8(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80513054(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80513090(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_805130CC(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80513108(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY void fn_80513144(FeScrN* x, char* dst)
{
    fn_8040B830(dst, x->m134->fn_vslot70()->fn_vslot33(5, 1)->mC, 16);
}

extern "C" FE_OVERLAY int fn_805131B8(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

extern "C" FE_OVERLAY FeScrQ* fn_80513214(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067EED0);
    self->m130 = 0;
    self->m2A8 = 0;
    self->m2AC = 1;
    self->m2B4 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80513270(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_80514020(void* self, FeRec84* x)
{
    int tmp[3];
    int i;
    for (i = 0; i < 3; i++) {
        tmp[i] = x->m78[i];
    }
    fn_805168D8(self, x);
    x->m98->fn_vslot79(0, 0);
    x->m98->fn_vslot3();
    x->m88 = 0;
    for (i = 0; i < 3; i++) {
        x->m78[i] = 0;
    }
}

extern "C" FE_OVERLAY void fn_805140D8(FeScrQ* x)
{
    ((FeW*)x->m1C8)->fn_vslot14(0);
    ((FeW*)x->m1CC)->fn_vslot14(0);
    ((FeW*)x->m280)->fn_vslot14(0);
    ((FeW*)x->m284)->fn_vslot14(0);
    ((FeW*)x->m1D4)->fn_vslot16(0);
    ((FeW*)x->m1E0)->fn_vslot16(0);
    ((FeW*)x->m28C)->fn_vslot16(0);
    ((FeW*)x->m298)->fn_vslot16(0);
    int k = x->m2AC;
    if (k != 0) {
        if (k == 1) {
            x->m2A8 = (int)((char*)x + 0x134);
            ((FeW*)x->m2BC)->fn_vslot84(1, 0);
        }
    } else {
        x->m2A8 = (int)((char*)x + 0x1EC);
        ((FeW*)x->m2BC)->fn_vslot84(0, 0);
    }
    if (fn_80516ACC(x) == 0) {
        ((FeRecO*)x->m2A8)->m94->fn_vslot14(1);
        if (FeI(x, 0x2C4) != 0 || x->m2A8 != (int)((char*)x + 0x134)) {
            ((FeRecO*)x->m2A8)->mA0->fn_vslot16(1);
        }
        int c = fn_800757B8__18Unk8007B2B0_Screeni(lbl_8061930C, ((FeSubK*)((char*)((FeRecO*)x->m2A8)->mA8 + 0xDC))->s21());
        ((FeRecO*)x->m2A8)->mAC->fn_vslot16(c);
    }
}

extern "C" FE_OVERLAY void fn_80514340(FeScrQ* x, int a)
{
    x->m2AC = a;
    fn_805140D8(x);
}

extern "C" FE_OVERLAY void fn_80514364(FeScrQ* x)
{
    if (((FeW*)((FeRecO*)x->m2A8)->m94)->fn_vslot61() != 1) {
        ((FeWi*)((FeRecO*)x->m2A8)->m94)->s69(1);
    }
    FeRecO* r = (FeRecO*)x->m2A8;
    if (r == (FeRecO*)((char*)x + 0x1EC)) {
        if (((FeW*)x->m2BC)->fn_vslot86() != 0) {
            if (fn_805153AC((FeP2A8*)x) != ((FeW*)x->m2BC)->fn_vslot86()) {
                int t2 = fn_805153AC((FeP2A8*)x);
                FeList* q = (FeList*)x->m2BC;
                fn_80126CF4(q, t2, q->m168, q->m134, q->m16C, q->m170, 0, q->m138, q->m13C, q->m148, q->m14C);
            }
        }
    } else if (r == (FeRecO*)((char*)x + 0x134)) {
        if (((FeW*)x->m2BC)->fn_vslot87() != 0) {
            if (fn_805153AC((FeP2A8*)x) != ((FeW*)x->m2BC)->fn_vslot87()) {
                int t2 = fn_805153AC((FeP2A8*)x);
                FeList* q = (FeList*)x->m2BC;
                fn_80126CF4(q, q->m164, t2, q->m134, q->m16C, q->m170, 0, q->m138, q->m13C, q->m148, q->m14C);
            }
        }
    }
    fn_80516B6C(x);
}

extern "C" FE_OVERLAY void fn_80514538(FeScrQ* x)
{
    fn_80514DB0(x, &x->m134);
    fn_80514DB0(x, (char*)x + 0x1EC);
    fn_805140D8(x);
}

/* near-miss: retail emits `li r4,1` before `mr r3,r31` for the fn_805362AC call (2 of 81 insns); all return-type and cast variants tried */
extern "C" FE_OVERLAY void fn_8051457C(FeScrQ* x, void* yp)
{
    FeRec84* y = (FeRec84*)yp;
    FeLst lst;
    int buf[0x28];
    FeLst* s = &lst;
    s->m10 = lbl_8064B298;
    s->m0 = (char*)buf;
    s->m8 = 0x28;
    fn_8040074C(s->m0, 0xA0);
    s->m4 = 0;
    s->mC = 0;
    s->m10 = lbl_8064A550;
    fn_8040074C(s->m0, s->m8 * 4);
    s->m4 = 0;
    s->mC = 0;
    s->m10 = lbl_8064A4C8;
    s->m14 = 0;
    fn_80535650(s, ((FeSubK*)((char*)((FeRecO*)y)->mA8 + 0xDC))->s21());
    fn_80539128(s, 0);
    fn_805362AC(s, 1);
    int n = s->m4;
    s->mC = 0;
    y->m84 = n;
    for (int i = 0; i < y->m84; i++) {
        y->m4[i] = *(int*)(lst.m0 + s->mC * 4);
        s->mC = (s->mC + 1) % lst.m4;
    }
    lst.m10 = lbl_8064A550;
}

extern "C" FE_OVERLAY void fn_805146C0(FeScrQ* x, void* yp)
{
    FeRec84* y = (FeRec84*)yp;
    char sbuf[0x1F8];
    unsigned short wbuf[32];
    FeW* w = y->m94;
    int n = y->m84;
    int i = 0;
    void* g = lbl_8061930C;
    w->fn_vslot79(n, 0);
    w->fn_vslot3();
    for (; i < n; i++) {
        int v = y->m4[i];
        int t = fn_8007A6A0__18Unk8007A4DC_Screenii(g, 5, v);
        w->fn_vslot44(i, 0, (char*)fn_800E5F38__Fi(t), 5);
        fn_800DE440(wbuf, v, 1);
        w->fn_vslot43(i, 1, (char*)wbuf, 5);
        fn_8007824C(v, 0);
        float f = fn_800E0164__Ff();
        sprintf(sbuf, lbl_805F5010, f);
        w->fn_vslot44(i, 2, sbuf, 4);
        if (fn_8007A6A0__18Unk8007A4DC_Screenii(g, 0x19, v) <= 0) {
            ((FeWV*)w)->s101(i, 0);
        } else {
            ((FeWV*)w)->s101(i, 1);
        }
    }
    ((FeWj*)w)->s88(0);
    fn_805168D8(x, y);
    w->fn_vslot14(1);
}

extern "C" FE_OVERLAY void fn_805148D0(FeScrQ* x, void* yp)
{
    FeRecP* y = (FeRecP*)yp;
    char sbuf[0x1F8];
    unsigned short wbuf[32];
    FeW* w = y->m98;
    int n = y->m88;
    int i = 0;
    void* g = lbl_8061930C;
    float f;
    w->fn_vslot79(n, 0);
    y->m98->fn_vslot3();
    for (; i < n; i++) {
        int v = y->m78[i];
        int t = fn_8007A6A0__18Unk8007A4DC_Screenii(g, 5, v);
        w->fn_vslot44(i, 0, (char*)fn_800E5F38__Fi(t), 5);
        fn_800DE440(wbuf, v, 1);
        w->fn_vslot43(i, 1, (char*)wbuf, 5);
        fn_8007824C(v, 0);
        f = fn_800E0164__Ff();
        sprintf(sbuf, lbl_805F5010, f);
        w->fn_vslot44(i, 2, sbuf, 4);
    }
    w->fn_vslot14(1);
    f = 0.0f;
    for (int k = 0; k < y->m88; k++) {
        f += fn_8007A768__18Unk8007A4DC_Screenii(lbl_8061930C, 5, y->m78[k]);
    }
    FmtSecs(f, wbuf);
    ((FeWV*)y->m9C)->s28(wbuf);
    if (FeI(x, 0x2B4) != 0) {
        FmtSecs(fn_80079EFC__18Unk8007B2B0_Screeni(lbl_8061930C, fn_80075948__18Unk8007B2B0_Screeni(g, ((FeSubK*)((char*)y->mA8 + 0xDC))->s21())), wbuf);
        ((FeWV*)y->mB4)->s28(wbuf);
    }
}

extern "C" FE_OVERLAY void fn_80514B78(void* self, FeP0B0* y)
{
    FeW* w = y->mB0;
    ((FeSub15*)((char*)w + 0xDC))->s15();
    ((FeWX*)w)->s51(0x3FB7, 0);
    ((FeWX*)w)->s51(0x3FB8, 1);
    ((FeWX*)w)->s51(0x3FB9, 2);
    ((FeWX*)w)->s51(0x5A1A, 3);
}

extern "C" FE_OVERLAY void fn_80514C3C(FeScrQ* x, FeRecO* o)
{
    int id = ((FeSubK*)((char*)o->mB0 + 0xDC))->s11();
    fn_800D0074((char*)o->mA4 + 0x98, id, 0);
    fn_800D0074((char*)o->mA8 + 0xDC, id, 0);
    if (FeI(x, 0x2C4) == 0 && o == (FeRecO*)((char*)x + 0x134)) {
        void* g = lbl_8061930C;
        int k = fn_8007F7D0__FP13Unk8007F198_BUi(g, 0);
        int v;
        switch (id) {
        case 0:
            v = fn_8007B320__18Unk8007B2B0_Screenii(g, 0, k);
            break;
        case 1:
            v = fn_8007B320__18Unk8007B2B0_Screenii(g, 1, k);
            break;
        case 2:
            v = fn_8007B320__18Unk8007B2B0_Screenii(g, 2, k);
            break;
        case 3:
            v = fn_8007B320__18Unk8007B2B0_Screenii(g, 3, k);
            break;
        default:
            v = fn_8007B320__18Unk8007B2B0_Screenii(g, 0, k);
            break;
        }
        ((FeSubK*)((char*)o->mA4 + 0x98))->s20(v, 0);
        ((FeSubK*)((char*)o->mA8 + 0xDC))->s20(v, 0);
        o->mA0->fn_vslot16(0);
    }
}

extern "C" FE_OVERLAY void fn_80514DB0(FeScrQ* x, void* y)
{
    fn_8051457C(x, y);
    fn_805146C0(x, y);
    fn_805148D0(x, y);
}

extern "C" FE_OVERLAY int fn_80514DF8(void* self, FeIdTab* y, int v)
{
    int n = y->m88;
    for (int i = 0; i < n; i++) {
        if (v == y->m78[i]) {
            return 1;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80514E3C(FeScrQ* self, FeRec84* r, int id)
{
    int i = 0;
    int idx = -1;
    for (; i < r->m88; i++) {
        if (id == r->m78[i]) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        if (r->m88 <= 2) {
            r->m78[r->m88] = id;
            r->m88 = r->m88 + 1;
        }
    } else {
        for (int j = idx + 1; j < r->m88; j++) {
            r->m78[j - 1] = r->m78[j];
        }
        r->m88 = r->m88 - 1;
    }
    fn_805148D0(self, r);
    fn_805168D8(self, r);
}

extern "C" FE_OVERLAY void fn_80514F40(FeScrQ* x, int a)
{
    void* g = lbl_8061930C;
    FeRecO* o = (FeRecO*)((char*)x + 0x1EC);
    int k = fn_8007F7D0__FP13Unk8007F198_BUi(g, 0);
    int c0 = fn_8007B320__18Unk8007B2B0_Screenii(g, 0, k);
    int c1 = fn_8007B320__18Unk8007B2B0_Screenii(g, 1, k);
    int c2 = fn_8007B320__18Unk8007B2B0_Screenii(g, 2, k);
    int c3 = fn_8007B320__18Unk8007B2B0_Screenii(g, 3, k);
    int id = fn_80077BC4(g, a);
    if (id == c0 || id == c1 || id == c2 || id == c3) {
        o = (FeRecO*)((char*)x + 0x134);
    }
    ((FeSubK*)((char*)o->mA4 + 0x98))->s20(id, 0);
    ((FeSubK*)((char*)o->mA8 + 0xDC))->s20(id, 0);
    ((FeSubK*)((char*)o->mB0 + 0xDC))->s8(FeI(o->mA4, 0xA4));
    fn_80514020(x, (FeRec84*)o);
    fn_80514E3C(x, (FeRec84*)o, a);
}

extern "C" FE_OVERLAY void fn_805150A0(FeScrQ* x, int id, int flag)
{
    int i = 0;
    do {
        FeRecO* o = i == 0 ? (FeRecO*)((char*)x + 0x134) : (FeRecO*)((char*)x + 0x1EC);
        FeRecO* p = i == 0 ? (FeRecO*)((char*)x + 0x1EC) : (FeRecO*)((char*)x + 0x134);
        if (id == (int)o->mAC) {
            fn_80514C3C(x, o);
        }
        if (id == (int)o->mA0 || id == (int)o->mAC) {
            int a = fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, ((FeSubK*)((char*)o->mA8 + 0xDC))->s21());
            if (a == fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, ((FeSubK*)((char*)p->mA8 + 0xDC))->s21())) {
                if (flag == 0) {
                    o->mA0->fn_vslot36();
                } else {
                    o->mA0->fn_vslot35();
                }
            }
            int c = fn_800757B8__18Unk8007B2B0_Screeni(lbl_8061930C, ((FeSubK*)((char*)((FeRecO*)x->m2A8)->mA8 + 0xDC))->s21());
            o->mAC->fn_vslot16(c);
            if (id == (int)o->mAC) {
                fn_80514DB0(x, o);
                fn_805140D8(x);
            }
        }
        if (id == (int)o->mA0) {
            fn_80514020(x, (FeRec84*)o);
            fn_80514DB0(x, o);
            fn_805140D8(x);
        }
        i++;
    } while (i <= 1);
}

extern "C" FE_OVERLAY int fn_80515284(FeScrQ* x)
{
    if (x->m2A4 != 0) {
        FeW* p = (FeW*)fn_800B7AB8(FeGetMgr(), lbl_805F4F0C);
        fn_80131F34(p, x, (FeCbF)fn_805169BC, (int)fn_8052851C, 0x38EC, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
        ((FeWh*)p)->s84(1);
        p->fn_vslot86();
    } else {
        fn_800B7ADC(FeGetMgr(), x);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_805153AC(FeP2A8* x)
{
    int i = x->m2A8->m94->fn_vslot60();
    int r;
    if (i < x->m2A8->m84) {
        r = x->m2A8->m4[i];
    } else {
        r = 0;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_80515418(FeP2A8* x)
{
    if (fn_80516ACC(x) != 0) {
        return 0;
    }
    int t = fn_805153AC(x);
    if (t != 0) {
        if (((FeWg*)x->m2A8->m94)->s93(x->m2A8->m94->fn_vslot60(), x->m2A8->m94->fn_vslot61()) != 0) {
            fn_8001BC4C()->fn_8001BDAC(0xA3);
            fn_80514E3C((FeScrQ*)x, (FeRec84*)x->m2A8, t);
        } else {
            fn_80516FEC(x);
        }
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_805154FC(FeScrQ* x, int a, int unused, int b)
{
    if (a == x->m280) {
        fn_80514340(x, 0);
    } else if (a == x->m1C8) {
        fn_80514340(x, 1);
    } else {
        FeRecO* o = 0;
        if (a == x->m1CC) {
            fn_80514340(x, 1);
            o = (FeRecO*)((char*)x + 0x134);
        } else if (a == x->m284) {
            fn_80514340(x, 0);
            o = (FeRecO*)((char*)x + 0x1EC);
        }
        if (o != 0) {
            void* g = lbl_8061930C;
            int id = fn_80078A38__18Unk8007B2B0_Screeni(g, fn_80077BC4(g, ((FeRec84*)o)->m78[b]));
            if (id != ((FeSubK*)((char*)o->mB0 + 0xDC))->s11()) {
                ((FeSubK*)((char*)o->mB0 + 0xDC))->s8(id);
                fn_80514C3C(x, o);
                fn_80514DB0(x, o);
            }
            int r = fn_80516DA8(x, o, b);
            o->m94->fn_vslot68(r);
        }
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_805158B0()
{
}

extern "C" FE_OVERLAY int fn_805158B4(FeScrQ* x)
{
    char s[0x30];
    int out;
    if (fn_80516B1C(x) != 0) {
        return 0;
    }
    void* p1 = fn_800B7A94(FeGetMgr(), lbl_805FBA5C);
    void* p2 = fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    FeRecO* ra = (FeRecO*)((char*)x + 0x134);
    FeRecO* rb = (FeRecO*)((char*)x + 0x1EC);
    fn_80599B24(s);
    fn_80516DF0(ra, rb, s);
    int r = fn_80545428(s, x->m2B0, &out);
    if (r == 0) {
        if (x->m1BC > 0 && x->m274 > 0) {
            fn_801321D4((FeW*)p2, x, (FeCbF)fn_8051687C, (int)fn_8052851C, (void*)out, 1, -1, 1, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x26DE), (const char*)r, (const char*)r, r, r, r);
            ((FeWh*)p2)->s84(1);
            ((FeW*)p2)->fn_vslot86();
        }
    } else {
        int a1 = fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, ((FeSubK*)((char*)rb->mA8 + 0xDC))->s21());
        int a2 = fn_80075948__18Unk8007B2B0_Screeni(lbl_8061930C, ((FeSubK*)((char*)ra->mA8 + 0xDC))->s21());
        int m = x->m1BC < x->m274 ? x->m274 : x->m1BC;
        int i = 0;
        fn_80523824(p1, x, 0, (FeCbF)fn_80516990, a1, a2, m);
        for (; i < x->m274; i++) {
            int id = FeAt((char*)x + 0x264, i);
            fn_80523C94(p1, id, 0, i, fn_80077BC4(lbl_8061930C, id));
        }
        i = 0;
        for (; i < x->m1BC; i++) {
            int id = FeAt((char*)x + 0x1AC, i);
            fn_80523C94(p1, id, 1, i, fn_80077BC4(lbl_8061930C, id));
        }
        ((FeWh*)p1)->s84(1);
        ((FeW*)p1)->fn_vslot86();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80515BB8(FeScrQ* x)
{
    if (x->m2A8 == 0) {
        return 1;
    }
    if (fn_805153AC((FeP2A8*)x) == 0) {
        return 1;
    }
    FeRecO* o = (FeRecO*)x->m2A8;
    if (o == (FeRecO*)((char*)x + 0x134)) {
        if (((FeW*)x->m2BC)->fn_vslot87() == 0) {
            int t = fn_805153AC((FeP2A8*)x);
            FeList* q = (FeList*)x->m2BC;
            fn_80126CF4(q, q->m164, t, q->m134, q->m16C, q->m170, 0, q->m138, q->m13C, q->m148, q->m14C);
            ((FeW*)x->m2BC)->fn_vslot84(1, 0);
            ((FeRecO*)x->m2A8)->mA0->fn_vslot16(0);
            ((FeRecO*)x->m2A8)->mAC->fn_vslot16(0);
        } else {
            FeList* q = (FeList*)x->m2BC;
            fn_80126CF4(q, q->m164, 0, q->m134, q->m16C, q->m170, 0, q->m138, q->m13C, q->m148, q->m14C);
            if (fn_800B57EC(fn_800B555C()) == 0) {
                ((FeRecO*)x->m2A8)->mA0->fn_vslot16(1);
            }
            ((FeRecO*)x->m2A8)->mAC->fn_vslot16(1);
            ((FeW*)x->m1C8)->fn_vslot14(1);
        }
    } else if (o == (FeRecO*)((char*)x + 0x1EC)) {
        if (((FeW*)x->m2BC)->fn_vslot86() == 0) {
            int t = fn_805153AC((FeP2A8*)x);
            FeList* q = (FeList*)x->m2BC;
            fn_80126CF4(q, t, q->m168, q->m134, q->m16C, q->m170, 0, q->m138, q->m13C, q->m148, q->m14C);
            ((FeW*)x->m2BC)->fn_vslot84(0, 0);
            ((FeRecO*)x->m2A8)->mA0->fn_vslot16(0);
            ((FeRecO*)x->m2A8)->mAC->fn_vslot16(0);
        } else {
            FeList* q = (FeList*)x->m2BC;
            fn_80126CF4(q, 0, q->m168, q->m134, q->m16C, q->m170, 0, q->m138, q->m13C, q->m148, q->m14C);
            ((FeRecO*)x->m2A8)->mA0->fn_vslot16(1);
            ((FeRecO*)x->m2A8)->mAC->fn_vslot16(1);
            ((FeW*)x->m280)->fn_vslot14(1);
        }
    }
    fn_8001BC4C()->fn_8001BDAC(0xA3);
    return 1;
}

extern "C" FE_OVERLAY int fn_80515ED8(FeScrQ* x, int a)
{
    if (x->m2AC > 0) {
        fn_8001BC4C()->fn_8001BDAC(0x9B);
    }
    int v = x->m2AC - 1;
    x->m2AC = v;
    if (v < 0) {
        x->m2AC = 0;
    }
    fn_80514340(x, x->m2AC);
    ((FeWX*)x)->s55(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_80515F64()
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80515F6C(FeScrQ* x, int a)
{
    if (x->m2AC <= 0) {
        fn_8001BC4C()->fn_8001BDAC(0x9C);
    }
    int v = x->m2AC + 1;
    x->m2AC = v;
    if (v > 1) {
        x->m2AC = 1;
    }
    fn_80514340(x, x->m2AC);
    ((FeWX*)x)->s55(a);
    ((FeWX*)x)->s57(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_80516014()
{
    return 1;
}

extern "C" FE_OVERLAY int fn_8051601C(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051605C(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051609C(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_805160DC(FeP2A8* x)
{
    x->m2A8->m94->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8051611C(FeScrQ* x)
{
    if (x->m2AC == 0) {
        fn_800C805C(x->fn_vslot32(lbl_805FB9A8, 1))->fn_vslot40(1);
    } else if (x->m2AC == 1) {
        fn_800C805C(x->fn_vslot32(lbl_805FB970, 1))->fn_vslot40(1);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_805161E0(FeScrN* x)
{
    ((FeWX*)fn_800C805C(x->fn_vslot32(lbl_805FB9A8, 1)))->s41();
    ((FeWX*)fn_800C805C(x->fn_vslot32(lbl_805FB970, 1)))->s41();
    return 0;
}

extern "C" FE_OVERLAY int fn_8051628C(FeScrQ* x)
{
    if (x->m2AC == 0) {
        fn_800C805C(x->fn_vslot32(lbl_805FB9A8, 1))->fn_vslot38(1);
    } else if (x->m2AC == 1) {
        fn_800C805C(x->fn_vslot32(lbl_805FB970, 1))->fn_vslot38(1);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80516350(FeScrN* x)
{
    fn_800C805C(x->fn_vslot32(lbl_805FB9A8, 1))->fn_vslot39();
    fn_800C805C(x->fn_vslot32(lbl_805FB970, 1))->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_805163FC(FeScrQ* x)
{
    if (x->m2AC == 0) {
        ((FeW*)x->m298)->fn_vslot40(1);
    } else if (x->m2AC == 1) {
        ((FeW*)x->m1E0)->fn_vslot40(1);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80516474(FeP298_1E0* x)
{
    ((FeWX*)x->m298)->s41();
    ((FeWX*)x->m1E0)->s41();
    return 0;
}

extern "C" FE_OVERLAY int fn_805164D8(FeScrQ* x)
{
    if (x->m2AC == 0) {
        ((FeW*)x->m298)->fn_vslot38(1);
    } else if (x->m2AC == 1) {
        ((FeW*)x->m1E0)->fn_vslot38(1);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80516550(FeP298_1E0* x)
{
    x->m298->fn_vslot39();
    x->m1E0->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_805165B4(void* self, int w, int a, FeRec84* r)
{
    if (r->m88 != (int)fn_80599C40(w, a)) {
        return 0;
    }
    for (int k = 0; k < r->m88; k++) {
        int found = 0;
        for (unsigned j = 0; j < fn_80599C40(w, a); j++) {
            if (r->m78[k] == fn_80599C50(w, a, (unsigned char)j)) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_8051667C(FeScrQ* x)
{
    char s[0x30];
    unsigned short buf[1000];
    void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    int ok = 0;
    int g = fn_800C2184((char*)fn_800B555C() + 8);
    if (x->m2A4 != 0 && fn_805165B4(x, g, 0, (FeRec84*)((char*)x + 0x1EC)) != 0 && fn_805165B4(x, g, 1, (FeRec84*)((char*)x + 0x134)) != 0) {
        ok = 1;
    }
    fn_80599B24(s);
    fn_80516DF0((char*)x + 0x134, (char*)x + 0x1EC, s);
    fn_805170C0(x, s);
    int r;
    if (ok != 0 || (r = fn_80545AFC(s)) != 0) {
        unsigned short* bp = buf;
        fn_80546258(s);
        fn_80134858(p);
        fn_800E5100__FPUsi(bp, s);
        fn_801321D4((FeW*)p, x, (FeCbF)fn_80516880, (int)fn_8052851C, bp, 1, -1, 1, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x26DE), 0, 0, 0, 0, 0);
    } else {
        fn_80134858(p);
        fn_80131F34((FeW*)p, x, (FeCbF)fn_8051687C, (int)fn_8052851C, 0x238D, 1, -1, 1, 0x26DE, r, r, r, r, r);
    }
    ((FeWh*)p)->s84(0);
    ((FeW*)p)->fn_vslot86();
    fn_80134CD0(p);
}

extern "C" FE_OVERLAY void fn_8051687C()
{
}

extern "C" FE_OVERLAY void fn_80516880(int unused, FeScrQ* x)
{
    char* a[2];
    a[0] = (char*)x + 0x134;
    a[1] = (char*)x + 0x1EC;
    for (int i = 0; i < 2; i++) {
        *(int*)(a[i] + 0x88) = 0;
    }
    fn_80514538(x);
}

extern "C" FE_OVERLAY void fn_805168D8(void* self, FeRec84* x)
{
    for (int i = 0; i < x->m84; i++) {
        ((FeWV*)x->m94)->s90(i, 1, fn_80514DF8(self, (FeIdTab*)x, x->m4[i]));
    }
    x->m94->fn_vslot14(1);
}
