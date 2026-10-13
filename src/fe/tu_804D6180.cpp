/*
 * Front-end overlay code, .frontend_codeoverlay 0x804D6180-0x804DA10C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804D08D0.h"
extern int lbl_805FC724[];
extern int lbl_805FC548[];
extern "C" int fn_8007DA28__18Unk8007B2B0_Screen(void* g);
extern "C" int fn_8007D38C__18Unk8007B2B0_ScreenUii(void* g, int a, unsigned b);
extern "C" void fn_804D7C78(FeS804D6184* x);
struct FeRec8 {
    int m0;
    int m4;
    FeRec8()
    {
        m0 = 0;
        m4 = 0;
    }
};
struct FeG10R {
    char pad0[0x78];
    FeRec8 m78[1];
};
struct FeState538 {
    char pad0[0x538];
    int m538;
};
extern "C" int strcmp(const char* a, const char* b);
extern "C" char* strcpy(char* d, const char* s);
extern const char lbl_805F95F4[];
extern "C" void fn_80085FF8__FP13Unk80084910_Ni(FeRec8* p, int k);
extern "C" int fn_800B5520();
extern "C" int fn_800A2E6C(void* g);

extern "C" void fn_804D98E8(FeS804D7FE0* x, FeTmp18* t);
extern "C" void fn_804D9638(FeS804D7FE0* x, FeTmp18* t);

struct FeVA : Unk800C7B40_Data {
    virtual ~FeVA();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual FeW* s29(const char* a); virtual void s30();
    virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40();
    virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
    virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
    virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60();
    virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65();
    virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70();
    virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
    virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80();
    virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85();
    virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90();
    virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};
struct FeVB : Unk800C7B40_Data {
    virtual ~FeVB();
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
struct FeVC : Unk800C7B40_Data {
    virtual ~FeVC();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(const char* a);
    virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40();
    virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
    virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
    virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60();
    virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65();
    virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70();
    virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
    virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80();
    virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85();
    virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90();
    virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};
struct FeVD : Unk800C7B40_Data {
    virtual ~FeVD();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(int a, int b, const char* c, int d);
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
    virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54();
    virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
    virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64();
    virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69();
    virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74();
    virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84();
    virtual void s85(); virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89();
    virtual void s90(); virtual void s91(); virtual void s92(int a, int b, int c); virtual void s93();
    virtual void s94(); virtual void s95(); virtual void s96(); virtual void s97(); virtual void s98();
    virtual void s99(); virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103();
    virtual void s104(); virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108();
    virtual void s109(); virtual void s110(); virtual void s111(); virtual void s112(); virtual void s113();
    virtual void s114(); virtual void s115(); virtual void s116(); virtual void s117(); virtual void s118();
    virtual void s119(); virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123();
    virtual void s124(); virtual void s125(); virtual void s126(); virtual void s127();
};
class FeLst {
public:
    int* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5();
    virtual int s6(); virtual int s7(); virtual int s8(); virtual int s9(); virtual void s10();
};
extern "C" int fn_800E5C74__Fiii(int a, int b, int c);
extern "C" int sprintf(char* buf, const char* fmt, ...);
class FeSub98 {
public:
    char pad0[0x24];
    virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5();
    virtual int s6(); virtual int s7(); virtual int s8(); virtual int s9(); virtual int s10();
    virtual int s11(); virtual int s12(); virtual int s13(); virtual int s14(); virtual int s15();
    virtual int s16(); virtual int s17(); virtual int s18(); virtual int s19(); virtual int s20();
    virtual int s21();
};
struct FeH98 {
    char pad0[0x98];
    FeSub98 m98;
};
extern "C" int fn_8007FDF8__FP13Unk8007F198_D(void* g);
extern "C" void fn_80536C5C(FeTmp18* l, int a);
extern "C" void fn_80535650(FeTmp18* l, int a);
extern "C" int fn_80075094__18Unk8007A4DC_Screeniiii(void* g, int a, int b, int c, int d);
extern "C" int fn_800739E0__18Unk8007A4DC_Screeniiii(void* g, int a, int b, int c, int d);
extern "C" int fn_80357074__Fff(float a, float b);
extern "C" void fn_80539128(FeTmp18* l, int a);
extern float lbl_805F9710;
extern "C" {

FE_OVERLAY void fn_804D6180(void) {}

FE_OVERLAY FeS804D6184* fn_804D6184(FeS804D6184* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC594__FP8UiScrRawiiiiiiii(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8067FD70);
    self->m154 = 0;
    self->m158 = 0;
    self->m160 = 0;
    self->m174 = 0;
    self->m178 = 0;
    self->m17C = 0;
    self->m180 = 0;
    self->m170 = -1;
    self->m184 = 0;
    return self;
}

FE_OVERLAY void fn_804D61F4(FeS804D6184* x)
{
    x->SetVptr(lbl_8067FD70);
    fn_800EC5F4__FP8UiScrRaw(x);
}

FE_OVERLAY void fn_804D67A8(FeS804D6184* x)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    if (x->m17C != 0) {
        x->m17C = 0;
        if (--lbl_80621AF4 == 0) {
            fn_80125128(p, -1);
        }
    }
    x->m15C->fn_vslot37(0);
    x->m15C->fn_vslot8(0);
    x->m164->fn_vslot8(0);
    x->m154->fn_vslot32(lbl_805F95D4, 1)->fn_vslot8(0);
    x->m154->fn_vslot32(lbl_805F95DC, 1)->fn_vslot8(0);
    x->m154->fn_vslot32(lbl_805F95E8, 1)->fn_vslot8(0);
    x->m154->fn_vslot8(0);
    fn_800C4720(fn_800C33D0(), x->m160);
}

extern "C" FE_OVERLAY void fn_804D6990(FeS804D6184* x)
{
    char buf[16];
    FeW* w = x->m160;
    int id = ((FeSubX*)((char*)w + 0x98))->s5();
    strcpy(buf, ((FeWX*)w)->s33(id)->name);
    ((FeSubX*)((char*)x->m180 + 0x98))->s21();
    int v = fn_800B5520();
    FeRec8 rec;
    x->m174 = v;
    rec.m0 = v;
    if (strcmp(buf, lbl_805F95F4) == 0) {
        fn_800B555C();
        if (fn_800B57EC() != 0 && fn_800A2E6C(lbl_80619948) != 0) {
            rec.m4 = 0xE;
        } else if (x->m13C == 0 && (unsigned)(x->m174 - 0x1E) > 1 && x->m174 != 0x7A && x->m174 != 0x7B) {
            rec.m4 = 1;
        } else {
            rec.m4 = 0;
        }
    } else {
        fn_80085FF8__FP13Unk80084910_Ni(&rec, buf[3]);
    }
    ((FeState538*)fn_800B555C())->m538 = id;
    ((FeG10R*)lbl_806192E0->m4->m10)->m78[x->m178] = rec;
    x->m154->fn_vslot8(0);
}

FE_OVERLAY void fn_804D6E00(void) {}

FE_OVERLAY void fn_804D6E04(FeS804D6184* x)
{
    fn_800ECAA4(x);
    FeRec3* r = FeCurRec(x);
    int t = fn_8007DA28__18Unk8007B2B0_Screen(lbl_8061930C);
    if (r->m3 == 0x70 && fn_800E62C4__Fii(t, x->m174) == 0) {
        x->m15C->fn_vslot35();
    }
    fn_804D6EC0(x);
}

FE_OVERLAY void fn_804D772C(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY int fn_804D774C(FeS804D6184* x)
{
    if (x->m148 == 0) {
        x->m15C->fn_vslot40(1);
        if (FeCurRec(x)->m3 == 0x70) {
            if (fn_800E62C4__Fii(fn_8007DA34__18Unk8007B2B0_Screeni(lbl_8061930C, x->m138), x->m174) == 0) {
                ((FeWX*)x->m15C)->s36();
            }
        }
        fn_804D7C78(x);
    }
    return 1;
}

FE_OVERLAY int fn_804D7834(FeS804D6184* x)
{
    if (x->m148 == 0) {
        ((FeWX*)x->m15C)->s41();
        fn_804D7C78(x);
    }
    return 1;
}

FE_OVERLAY int fn_804D7890(FeS804D6184* x)
{
    if (x->m148 == 0) {
        x->m15C->fn_vslot38(1);
        if (FeCurRec(x)->m3 == 0x70) {
            if (fn_800E62C4__Fii(fn_8007DA34__18Unk8007B2B0_Screeni(lbl_8061930C, x->m138), x->m174) == 0) {
                ((FeWX*)x->m15C)->s35();
            }
        }
        fn_804D7C78(x);
    }
    return 1;
}

FE_OVERLAY int fn_804D7978(FeS804D6184* x)
{
    if (x->m148 == 0) {
        ((FeWX*)x->m15C)->s39();
        fn_804D7C78(x);
    }
    return 1;
}

FE_OVERLAY int fn_804D79D4(FeS804D6184* x)
{
    ((FeWX*)x->m15C)->s39();
    ((FeWX*)x->m15C)->s41();
    fn_804D7C78(x);
    return 0;
}

FE_OVERLAY int fn_804D7A40(FeS804D6184* x)
{
    ((FeWX*)x->m15C)->s39();
    ((FeWX*)x->m15C)->s41();
    fn_804D7C78(x);
    return 0;
}

FE_OVERLAY void fn_804D7AAC(void) {}

FE_OVERLAY void fn_804D7AB0(FeS804D6184* x, FeW* w, int a)
{
    if (w == x->m15C && *fn_800ED2B0(x->m140, lbl_805F5A48) == 0) {
        if (FeCurRec(x)->m3 == 0x70) {
            if (fn_800E62C4__Fii(fn_8007DA34__18Unk8007B2B0_Screeni(lbl_8061930C, x->m138), x->m174) == 0) {
                if (a == 0) {
                    ((FeWX*)x->m15C)->s36();
                } else {
                    ((FeWX*)x->m15C)->s35();
                }
            }
        }
        if (fn_804D6EC0(x) == 0) {
            fn_800CFB38((void*)x->m16C);
        }
        x->m140->fn_vslot4();
    }
    fn_804D7C78(x);
}

FE_OVERLAY void fn_804D7BF0(FeS804D6184* x)
{
    x->m148 = 1;
    x->m154->fn_vslot8(0);
}

FE_OVERLAY void fn_804D7C34(FeS804D6184* x)
{
    x->m148 = 0;
    x->m154->fn_vslot8(1);
}

FE_OVERLAY void fn_804D7C78(FeS804D6184* x)
{
    int i = 0;
    int found = -1;
    FeRec3* r = FeCurRec(x);
    for (; i <= 0x1B0; i++) {
        if (fn_8040B574((const char*)r, lbl_80621AF8[i]) == 0) {
            found = i;
            break;
        }
    }
    ((FeWX*)x->m184)->s29(lbl_805FCADC[found]);
}

extern "C" FE_OVERLAY void fn_804D7D50(FeS804D6184* x, int a)
{
    int buf[16];
    if (a == 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        int n = 0;
        int sel = fn_8007DA28__18Unk8007B2B0_Screen(lbl_8061930C);
        for (int i = 0; i < x->m170; i++) {
            int ok = 1;
            FeRec3* rec = ((FeWX*)x->m160)->s33(i);
            if (strcmp(rec->name, lbl_805F95F4) != 0) {
                int c = (signed char)rec->m3;
                int k = c - 0x61;
                if ((unsigned)(c - 0x67) <= 7) {
                    for (int j = 0; j <= 0x76; j++) {
                        if (lbl_805FC724[j] == x->m174 && lbl_805FC548[j] == k
                            && (sel == -1 || fn_8007D38C__18Unk8007B2B0_ScreenUii(lbl_8061930C, sel, j) == 0)) {
                            ok = 0;
                        }
                    }
                }
                if (((FeSubX*)((char*)x->m160 + 0x98))->s5() == i)
                    ok = 0;
                if (ok != 0)
                    buf[n++] = i;
            }
        }
        ((FeSubX*)((char*)x->m160 + 0x98))->s6(buf[fn_800ED4F0(x, n)]);
        fn_804D7C78(x);
    }
}

FE_OVERLAY void fn_804D7F0C(FeS804D6184* x, int a)
{
    int found = -1;
    for (int i = 0; i < ((FeSubX*)((char*)x->m160 + 0x98))->s13(); i++) {
        int c = ((FeWX*)x->m160)->s33(i)->m3;
        if (lbl_806221BC[a] == c) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        found = 0;
    }
    ((FeSubX*)((char*)x->m160 + 0x98))->s6(found);
}

FE_OVERLAY FeS804D7FE0* fn_804D7FE0(FeS804D7FE0* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC594__FP8UiScrRawiiiiiiii(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066E840);
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 1;
    self->m16C = 1;
    self->m170 = 0;
    return self;
}

FE_OVERLAY void fn_804D8048(FeS804D7FE0* x, FeW* w, int a)
{
    fn_800EC624__FP13Unk800EC624_Tiii(x, w, a);
    if (a != 0) {
        x->m154 = fn_800C8060(w->fn_vslot29(lbl_805F9614));
        x->m158 = fn_800C8054(w->fn_vslot29(lbl_805F8554));
        x->m170 = fn_800C8044(w->fn_vslot29(lbl_805F962C));
        x->m15C = fn_800C8058(w->fn_vslot29(lbl_805F9644));
        x->m168 = 1;
    } else {
        x->m154 = fn_800C8060(w->fn_vslot29(lbl_805F9660));
        x->m158 = fn_800C8054(w->fn_vslot29(lbl_805F859C));
        x->m170 = fn_800C8044(w->fn_vslot29(lbl_805F9678));
        x->m15C = fn_800C8058(w->fn_vslot29(lbl_805F9690));
        x->m168 = a;
    }
    x->m164 = 1;
}

FE_OVERLAY void fn_804D91F8(FeS804D7FE0* x)
{
    x->m154->fn_vslot8(0);
    x->m170->fn_vslot8(0);
    x->m164 = 1;
}

FE_OVERLAY void fn_804D9268(FeS804D7FE0* x)
{
    int v = 1;
    x->m164 = x->m154->fn_vslot60();
    x->m154->fn_vslot8(0);
    x->m170->fn_vslot8(0);
    if (((FeWY*)fn_800C8040(fn_800C8044(x->m154->fn_vslot32(lbl_805F4EE0, 1))->fn_vslot32(lbl_805F565C, 1)))->s32() == 0x199A) {
        v = 0;
    }
    ((FeStateC*)fn_800B555C())->m664 = v;
}

FE_OVERLAY void fn_804D9374(FeS804D7FE0* x)
{
    x->m154->fn_vslot8(1);
    fn_804D87CC(x);
    x->m154->fn_vslot68(x->m164);
    fn_804D81DC(x);
    if (fn_800B5B04(fn_800B555C()) == 0) {
        x->m170->fn_vslot8(1);
    }
    x->fn_vslot4();
}

FE_OVERLAY int fn_804D9434(FeS804D7FE0* x)
{
    x->m154->fn_vslot50();
    fn_804D81DC(x);
    return 1;
}

FE_OVERLAY int fn_804D9484(FeS804D7FE0* x)
{
    x->m154->fn_vslot51();
    fn_804D81DC(x);
    return 1;
}

FE_OVERLAY int fn_804D94D4(FeS804D7FE0* x)
{
    x->m154->fn_vslot52();
    fn_804D81DC(x);
    return 1;
}

FE_OVERLAY int fn_804D9524(FeS804D7FE0* x)
{
    x->m154->fn_vslot53();
    fn_804D81DC(x);
    return 1;
}

FE_OVERLAY int fn_804D9574(FeS804D7FE0* x, int a)
{
    if (a == (int)x->m154) {
        fn_804D81DC(x);
    }
    return 1;
}

FE_OVERLAY void fn_804D95A4(FeS804D7FE0* x, int a)
{
    int v = x->m154->fn_vslot59();
    if (a == 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        int idx = fn_800ED4F0(x, v - 1) + 1;
        x->m154->fn_vslot68(idx);
        fn_804D81DC(x);
    }
}

FE_OVERLAY void fn_804D9638(FeS804D7FE0* x, FeTmp18* t)
{
    if (((FeStateB*)fn_800B555C())->m0 == 0x42) {
        if (x->m16C != 0)
            ((FeVB*)fn_800C8040(((FeVA*)x->m154)->s29(lbl_805F96B8)))->s29(0x199A);
        else
            ((FeVB*)fn_800C8040(((FeVA*)x->m154)->s29(lbl_805F96B8)))->s29(0x1999);
    } else {
        ((FeVC*)fn_800C8040(((FeVA*)x->m154)->s29(lbl_805F96B8)))->s30("PROG");
    }
    FeLst* l = (FeLst*)t;
    l->s1();
    unsigned i = 1;
    while (i < t->m4 + 1) {
        if (FeFlag() != 0) {
            int a = 13;
            int b = 0;
            if (((FeStateB*)fn_800B555C())->m0 == 0x42) {
                a = 7;
                b = (x->m16C == 0);
            } else if (((FeStateB*)fn_800B555C())->m0 == 0x43) {
                a = 8;
            }
            int r = fn_800E5C74__Fiii(l->s3(), a, b);
            char buf[4];
            if (r > 0)
                sprintf(buf, "+%d", r);
            else if (r < 0)
                sprintf(buf, "%d", r);
            else
                strcpy(buf, "0");
            ((FeVD*)x->m154)->s92(i, 1, 1);
            ((FeVD*)x->m154)->s44(i, 1, buf, 5);
        } else {
            ((FeVD*)x->m154)->s92(i, 1, 0);
        }
        l->s10();
        i++;
    }
    x->m154->fn_vslot14(1);
}

FE_OVERLAY void fn_804D98E8(FeS804D7FE0* x, FeTmp18* t)
{
    float sp8;
    float spC;
    void* g = lbl_8061930C;
    int k = ((FeSub98*)&((FeH98*)x->m158)->m98)->s21();
    if (fn_8007FDF8__FP13Unk8007F198_D(g) == 8 || (fn_8007FDF8__FP13Unk8007F198_D(g) == 9 && x->m168 != 0)
        || ((FeStateB*)fn_800B555C())->m0 == 0x43 || ((FeStateB*)fn_800B555C())->m0 == 0x44) {
        fn_80536C5C(t, k);
        unsigned n = t->m4;
        if (n != 0) {
            int (*cmp)(float, float) = fn_80357074__Fff;
            unsigned i = 0;
            void* g2 = lbl_8061930C;
            sp8 = lbl_805F9710;
            spC = lbl_805F9710;
            if (i < n) {
                unsigned lim = n - 1;
                unsigned lim2 = lim;
                do {
                    unsigned j = 0;
                    if (j < lim) {
                        do {
                            int* d = t->m0;
                            int o1 = j * 4;
                            unsigned j1 = j + 1;
                            int v0 = *(int*)((char*)d + o1);
                            int o2 = j1 * 4;
                            int v1 = *(int*)((char*)d + o2);
                            sp8 = (float)fn_80075094__18Unk8007A4DC_Screeniiii(g2, 2, v0, 1, 2);
                            spC = (float)fn_80075094__18Unk8007A4DC_Screeniiii(g2, 2, v1, 1, 2);
                            if (cmp(sp8, spC) != 0) {
                                if (j >= t->m4)
                                    t->m4 = j1;
                                *(int*)(o1 + (int)t->m0) = v1;
                                if (j1 >= t->m4)
                                    t->m4 = j1 + 1;
                                *(int*)(o2 + (int)t->m0) = v0;
                            }
                            j = j1;
                        } while (j < lim2);
                    }
                    i++;
                    lim2--;
                    lim--;
                } while (i < n);
            }
        }
    } else {
        fn_80535650(t, k);
        unsigned n = t->m4;
        if (n != 0) {
            int (*cmp)(float, float) = fn_80357074__Fff;
            unsigned i = 0;
            void* g2 = lbl_8061930C;
            sp8 = lbl_805F9710;
            spC = lbl_805F9710;
            if (i < n) {
                unsigned lim = n - 1;
                unsigned lim2 = lim;
                do {
                    unsigned j = 0;
                    if (j < lim) {
                        do {
                            int* d = t->m0;
                            int o1 = j * 4;
                            unsigned j1 = j + 1;
                            int v0 = *(int*)((char*)d + o1);
                            int o2 = j1 * 4;
                            int v1 = *(int*)((char*)d + o2);
                            sp8 = (float)fn_800739E0__18Unk8007A4DC_Screeniiii(g2, 0, v0, 1, 2);
                            spC = (float)fn_800739E0__18Unk8007A4DC_Screeniiii(g2, 0, v1, 1, 2);
                            if (cmp(sp8, spC) != 0) {
                                if (j >= t->m4)
                                    t->m4 = j1;
                                *(int*)(o1 + (int)t->m0) = v1;
                                if (j1 >= t->m4)
                                    t->m4 = j1 + 1;
                                *(int*)(o2 + (int)t->m0) = v0;
                            }
                            j = j1;
                        } while (j < lim2);
                    }
                    i++;
                    lim2--;
                    lim--;
                } while (i < n);
            }
        }
    }
    fn_800B555C();
    if (fn_800B57EC() != 0)
        fn_80539128(t, 0);
}

FE_OVERLAY int fn_804D9C50(FeS804D7FE0* x)
{
    if (((FeStateB*)fn_800B555C())->m0 == 0x42) {
        FeTmp18 t;
        int buf[0x28];
        FeTmp18* q = &t;
        q->C1(buf, 0x28);
        q->C2();
        q->C3(lbl_8064A4C8);
        fn_800C805C(x->m154->fn_vslot29(lbl_805F96D8))->fn_vslot40(1);
        x->m16C ^= 1;
        fn_804D98E8(x, q);
        fn_804D9638(x, q);
        t.D();
    }
    return 1;
}

FE_OVERLAY int fn_804D9D64(FeS804D7FE0* x)
{
    if (((FeStateB*)fn_800B555C())->m0 == 0x42) {
        ((FeWX*)fn_800C805C(x->m154->fn_vslot29(lbl_805F96D8)))->s41();
    }
    return 1;
}

FE_OVERLAY int fn_804D9DE0(FeS804D7FE0* x)
{
    if (((FeStateB*)fn_800B555C())->m0 == 0x42) {
        FeTmp18 t;
        int buf[0x28];
        FeTmp18* q = &t;
        q->C1(buf, 0x28);
        q->C2();
        q->C3(lbl_8064A4C8);
        fn_800C805C(x->m154->fn_vslot29(lbl_805F96D8))->fn_vslot38(1);
        x->m16C ^= 1;
        fn_804D98E8(x, q);
        fn_804D9638(x, q);
        t.D();
    }
    return 1;
}

FE_OVERLAY int fn_804D9EF4(FeS804D7FE0* x)
{
    if (((FeStateB*)fn_800B555C())->m0 == 0x42) {
        ((FeWX*)fn_800C805C(x->m154->fn_vslot29(lbl_805F96D8)))->s39();
    }
    return 1;
}

FE_OVERLAY void fn_804D9F70(FeS804D7FE0* x)
{
    fn_800ECAA4(x);
    if (fn_800B5B04(fn_800B555C()) != 0) {
        fn_800C8040(x->m154->fn_vslot29(lbl_805F96B8))->fn_vslot8(FeFlag());
        fn_800C8040(x->m154->fn_vslot29(lbl_805F96C4))->fn_vslot8(0);
        if (((FeStateB*)fn_800B555C())->m0 == 0x42 && x->m138 != -1 && x->m138 != 5) {
            fn_800C805C(x->m154->fn_vslot29(lbl_805F96D8))->fn_vslot8(FeFlag());
        } else {
            fn_800C805C(x->m154->fn_vslot29(lbl_805F96D8))->fn_vslot8(0);
        }
    }
}

}
