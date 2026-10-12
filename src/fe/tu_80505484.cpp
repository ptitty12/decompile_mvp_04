/*
 * Front-end overlay code, .frontend_codeoverlay 0x80505484-0x80508C98 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

/* Q16-DECL-BEGIN */
#define FS_V(n) virtual void s##n();
#define FS_R2_83(X) \
    X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) X(18) X(19) \
    X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30) X(31) X(32) X(33) X(34) X(35) X(36) \
    X(37) X(38) X(39) X(40) X(41) X(42) X(43) X(44) X(45) X(46) X(47) X(48) X(49) X(50) X(51) X(52) X(53) \
    X(54) X(55) X(56) X(57) X(58) X(59) X(60) X(61) X(62) X(63) X(64) X(65) X(66) X(67) X(68) X(69) X(70) \
    X(71) X(72) X(73) X(74) X(75) X(76) X(77) X(78) X(79) X(80) X(81) X(82) X(83)
#define FS_R85_86(X) X(85) X(86)
#define FS_R88_127(X) \
    X(88) X(89) X(90) X(91) X(92) X(93) X(94) X(95) X(96) X(97) X(98) X(99) X(100) X(101) X(102) X(103) \
    X(104) X(105) X(106) X(107) X(108) X(109) X(110) X(111) X(112) X(113) X(114) X(115) X(116) X(117) \
    X(118) X(119) X(120) X(121) X(122) X(123) X(124) X(125) X(126) X(127)
/* Widget view whose slot 87 returns an int (the base FeW declares it void). */
struct FeWQ87 : Unk800C7B40_Data {
    virtual ~FeWQ87();
    FS_R2_83(FS_V) virtual void s84(int a, int b); FS_R85_86(FS_V) virtual int s87(); FS_R88_127(FS_V)
};
#define FS_E(X) \
    X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) X(18) X(19) \
    X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30) X(31) X(32) X(33) X(34) X(35) X(36) \
    X(37) X(38) X(39) X(40)
#define FS_F(X) \
    X(43) X(44) X(45) X(46) X(47) X(48) X(49) X(50) X(51) X(52) X(53) X(54) X(55) X(56) X(57) X(58) X(59) X(60) \
    X(61) X(62) X(63) X(64) X(65) X(66) X(67) X(68) X(69) X(70) X(71) X(72) X(73) X(74) X(75) X(76) X(77) \
    X(78) X(79) X(80) X(81) X(82) X(83) X(84) X(85) X(86) X(87) X(88) X(89) X(90) X(91) X(92) X(93) X(94) \
    X(95) X(96) X(97) X(98) X(99) X(100) X(101) X(102) X(103) X(104) X(105) X(106) X(107) X(108) X(109) \
    X(110) X(111) X(112) X(113) X(114) X(115) X(116) X(117) X(118) X(119) X(120) X(121) X(122) X(123) \
    X(124) X(125) X(126) X(127)
/* Screen view whose slots 41 and 42 take one int. */
struct FeWQ6 : Unk800C7B40_Data {
    virtual ~FeWQ6();
    FS_E(FS_V) virtual void s41(int a); virtual void s42(int a); FS_F(FS_V)
};
struct FeStX {
    char pad0[0x4F4];
    int m4F4;
};
extern "C" {
void fn_800B7B4C(FeMsgMgr* mgr, FeMsg* m, void* ctx);
}
struct FeWQ7 : Unk800C7B40_Data {
    virtual ~FeWQ7();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(int a); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(int a); virtual void s39(); virtual void s40(int a);
    virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
    virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
    virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56(); virtual void s57(); virtual void s58(); virtual int s59(); virtual int s60();
    virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65();
    virtual void s66(); virtual void s67(); virtual void s68(int a); virtual void s69(); virtual void s70();
    virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
    virtual void s76(); virtual int s77(); virtual void s78(int a); virtual void s79(); virtual void s80();
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
struct FeLstQ {
    int* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    const void* m10;
    int m14;
};
struct FeBigQ {
    char pad0[0x30F60];
    FeLstQ src;
    char pad30F78[0x31018 - 0x30F78];
    FeLstQ d1;
    char pad31030[0x310D0 - 0x31030];
    FeLstQ d2;
    char pad310E8[0x31188 - 0x310E8];
    FeLstQ d3;
};
extern "C" void fn_8040074C(void* p, int n);
extern "C" void fn_805371C4(FeLstQ* l, unsigned f);
extern "C" void fn_80537054(FeLstQ* l, int mode);
extern "C" void fn_80539AE8(FeLstQ* l, int k);
/* Q16-DECL-END */

extern "C" FeW* fn_800C8058(FeW* w);
extern int lbl_806222B0;
extern "C" void fn_80505FD4(FeScrQ* x, int a, int b, int c);
extern "C" void fn_805082D0(char* x);
extern const char lbl_805FB5E0[];
extern "C" void fn_80507DD0(FeScrQ* x);
extern int lbl_806222A4;
extern int lbl_806222A8;
extern int lbl_806222AC;
extern "C" void fn_80505760(FeScrD* x);
extern "C" void fn_80505E40(FeScrD* x);
extern "C" void fn_80505E60(FeScrQ* x);
extern "C" void fn_80505F1C(FeScrQ* x, int a);
extern "C" void fn_80505F40(FeScrQ* x, int a, int b, int c);
extern "C" void fn_80506C18();
extern "C" int fn_80506C1C();
extern "C" int fn_80506C40(FeScrN* x);
extern "C" int fn_80506D4C(FeScrQ* x, int a);
extern "C" int fn_80506DD0(FeScrQ* x, FeW* w, int b, int n);
extern "C" void fn_80506E70();
extern "C" int fn_80506FD4(FeScrQ* x);
extern "C" int fn_80507038();
extern "C" int fn_80507040(FeScrQ* x);
extern "C" int fn_805070A4();
extern "C" int fn_805070AC(FeScrQ* x);
extern "C" int fn_8050712C(FeScrN* x);
extern "C" int fn_80507184(FeScrQ* x);
extern "C" int fn_80507204(FeScrN* x);
extern "C" int fn_805073EC(FeScrN* x);
extern "C" int fn_80507640(FeScrN* x);
extern "C" int fn_8050787C(FeScrN* x, int a);
extern "C" int fn_80507A6C(FeScrN* x);
extern "C" int fn_80507C38(FeScrA* x);
extern "C" int fn_80507C80(FeScrA* x);
extern "C" int fn_80507CC8(FeScrA* x);
extern "C" void fn_80507D10(FeScrQ* q);
extern "C" int fn_80507DC4(void* self, int a);
extern "C" void fn_80507E8C(FeScrQ* q);
extern "C" FeW* fn_80507F8C(FeScrN* x);
extern "C" int fn_80507FB8(FeScrN* x);
extern "C" int fn_80507FF4(void* self, int k);
extern "C" int fn_805082B8(int c);
extern "C" int fn_80508BF4(char* x, int a, int b);

extern "C" FE_OVERLAY void fn_80505760(FeScrD* x)
{
    fn_800ECE34(x);
}

extern "C" FE_OVERLAY void fn_80505E40(FeScrD* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_80505E60(FeScrQ* x)
{
    ((FeW*)x->m13C)->fn_vslot14(0);
    ((FeW*)x->m140)->fn_vslot14(0);
    ((FeW*)x->m13C)->fn_vslot14(x->m154 == 0);
    ((FeW*)x->m140)->fn_vslot14((x->m154 ^ 1) == 0);
}

extern "C" FE_OVERLAY void fn_80505F1C(FeScrQ* x, int a)
{
    x->m154 = a;
    fn_80505E60(x);
}

extern "C" FE_OVERLAY void fn_80505F40(FeScrQ* x, int a, int b, int c)
{
    if (a != -1) {
        fn_80505FD4(x, a, b, c);
    }
    if (x->m154 == 0) {
        ((FeWX*)x->m144)->s44(1);
    } else {
        ((FeWX*)x->m144)->s44(0);
    }
    fn_80505E60(x);
    fn_80507D10(x);
}

extern "C" FE_OVERLAY void fn_80506C18()
{
}

extern "C" FE_OVERLAY int fn_80506C1C()
{
    lbl_806222A4 = -1;
    lbl_806222A8 = -1;
    lbl_806222AC = -1;
    return 1;
}

extern "C" FE_OVERLAY int fn_80506C40(FeScrN* x)
{
    lbl_806222A4 = ((FeSub*)((char*)fn_800C8058(x->m144->fn_vslot33(10, 1)) + 0xDC))->s5();
    lbl_806222A8 = x->m13C->fn_vslot60();
    lbl_806222AC = x->m140->fn_vslot60();
    lbl_806222B0 = ((FeSub*)((char*)fn_800C8058(x->m14C->fn_vslot33(10, 1)) + 0xDC))->s5();
    return 1;
}

extern "C" FE_OVERLAY int fn_80506D4C(FeScrQ* x, int a)
{
    if (a == x->m13C) {
        x->m154 = 0;
        fn_80507E8C(x);
        fn_80505F40(x, 1, -1, -1);
    } else if (a == x->m140) {
        x->m154 = 1;
        fn_80505F40(x, -1, -1, -1);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80506DD0(FeScrQ* x, FeW* w, int b, int n)
{
    if (w == (FeW*)x->m140) {
        x->m154 = 1;
        w->fn_vslot68(n);
        fn_80505F40(x, -1, -1, -1);
        ((FeWX*)x)->s44(fn_800C8070(x));
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80506E70()
{
}

extern "C" FE_OVERLAY int fn_80506E74(FeScrQ* q)
{
    FeScrA* x = (FeScrA*)q;
    if (x->m13C[1]->fn_vslot59() > 0) {
        if (x->m154 == 1 && ((FeWQ87*)x->m138)->s87() == 0) {
            int o = x->m13C[1]->fn_vslot60() * 4;
            FeList* l = x->m138;
            char* b = (char*)x + 0x1F8;
            fn_80126CF4(l, l->m164, *(int*)(b + o), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
            ((FeWQ87*)x->m138)->s84(1, 0);
        } else {
            FeList* l = x->m138;
            fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
        fn_80507D10(q);
        fn_8001BC4C()->fn_8001BDAC(0xA3);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_80506FD4(FeScrQ* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9B);
    x->m154 = fn_80507DC4(x, x->m154);
    fn_80507E8C(x);
    fn_80505F40(x, -1, -1, -1);
    return 1;
}

extern "C" FE_OVERLAY int fn_80507038()
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80507040(FeScrQ* x)
{
    fn_8001BC4C()->fn_8001BDAC(0x9C);
    x->m154 = fn_80507DC4(x, x->m154);
    fn_80507E8C(x);
    fn_80505F40(x, -1, -1, -1);
    return 1;
}

extern "C" FE_OVERLAY int fn_805070A4()
{
    return 1;
}

extern "C" FE_OVERLAY int fn_805070AC(FeScrQ* x)
{
    fn_80507F8C((FeScrN*)x)->fn_vslot50();
    if (x->m154 == 0) {
        fn_80507E8C(x);
        fn_80505F40(x, 1, -1, -1);
    }
    fn_80507DD0(x);
    fn_80507D10(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050712C(FeScrN* x)
{
    fn_80507F8C(x)->fn_vslot51();
    fn_80507DD0((FeScrQ*)x);
    fn_80507D10((FeScrQ*)x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80507184(FeScrQ* x)
{
    fn_80507F8C((FeScrN*)x)->fn_vslot52();
    if (x->m154 == 0) {
        fn_80507E8C(x);
        fn_80505F40(x, 1, -1, -1);
    }
    fn_80507DD0(x);
    fn_80507D10(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_80507204(FeScrN* x)
{
    fn_80507F8C(x)->fn_vslot53();
    fn_80507DD0((FeScrQ*)x);
    fn_80507D10((FeScrQ*)x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050725C(FeScrQ* q)
{
    FeScrA* s = (FeScrA*)q;
    if (s->m154 == 0) {
        ((FeWQ7*)s->m144[0])->s40(1);
        fn_80507E8C(q);
        fn_80505F40(q, 2, -1, -1);
    } else if (fn_80507C80(s) == 0) {
        if (((FeWQ7*)s->m13C[1])->s59() > 0) {
            if (((FeWQ7*)s->m13C[1])->s60() - 10 >= 0) {
                FeWQ7* t = (FeWQ7*)s->m13C[1];
                t->s68(t->s60() - 10);
            } else
                ((FeWQ7*)s->m13C[1])->s68(0);
            ((FeWQ7*)fn_800C805C(s->fn_vslot32(lbl_805FB5E0, 1)))->s40(1);
            fn_80507DD0(q);
            fn_80505F40(q, -1, -1, -1);
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_805073EC(FeScrN* x)
{
    ((FeWX*)x->m144)->s41();
    ((FeWX*)fn_800C805C(x->fn_vslot32(lbl_805FB5E0, 1)))->s41();
    return 0;
}

extern "C" FE_OVERLAY int fn_80507474(FeScrQ* q)
{
    FeScrA* s = (FeScrA*)q;
    if (s->m154 == 0) {
        ((FeWQ7*)s->m144[0])->s38(1);
        fn_80507E8C(q);
        fn_80505F40(q, 2, -1, -1);
    } else if (fn_80507C80(s) == 0) {
        if (((FeWQ7*)s->m13C[1])->s59() > 0) {
            if (((FeWQ7*)s->m13C[1])->s60() + 10 < ((FeWQ7*)s->m13C[1])->s59()) {
                FeWQ7* t = (FeWQ7*)s->m13C[1];
                t->s68(t->s60() + 10);
            } else {
                FeWQ7* t = (FeWQ7*)s->m13C[1];
                t->s68(t->s59() - 1);
            }
            ((FeWQ7*)fn_800C805C(s->fn_vslot32(lbl_805FB5E0, 1)))->s38(1);
            fn_80507DD0(q);
            fn_80505F40(q, -1, -1, -1);
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507640(FeScrN* x)
{
    x->m144->fn_vslot39();
    fn_800C805C(x->fn_vslot32(lbl_805FB5E0, 1))->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY int fn_805076C8(FeScrQ* q)
{
    FeScrA* s = (FeScrA*)q;
    int a = ((FeWQ7*)s->m13C[0])->s60();
    int b = ((FeWQ7*)s->m13C[0])->s77();
    ((FeWQ7*)s->m14C)->s40(1);
    fn_80507E8C(q);
    fn_80505F40(q, 0, -1, -1);
    if (a < ((FeWQ7*)s->m13C[0])->s59()) {
        ((FeWQ7*)s->m13C[0])->s78(b);
        ((FeWQ7*)s->m13C[0])->s68(a);
        ((FeWQ7*)s->m13C[0])->s14(1);
        fn_80505E60(q);
    } else {
        ((FeWQ7*)s->m13C[0])->s68(((FeWQ7*)s->m13C[0])->s59() - 1 > 0 ? ((FeWQ7*)s->m13C[0])->s59() - 1 : 0);
    }
    fn_80505F40(q, 1, -1, -1);
    return 0;
}

extern "C" FE_OVERLAY int fn_8050787C(FeScrN* x, int a)
{
    x->m14C->fn_vslot41(a);
    return 0;
}

extern "C" FE_OVERLAY int fn_805078B8(FeScrQ* q)
{
    FeScrA* s = (FeScrA*)q;
    int a = ((FeWQ7*)s->m13C[0])->s60();
    int b = ((FeWQ7*)s->m13C[0])->s77();
    ((FeWQ7*)s->m14C)->s38(1);
    fn_80507E8C(q);
    fn_80505F40(q, 0, -1, -1);
    if (a < ((FeWQ7*)s->m13C[0])->s59()) {
        ((FeWQ7*)s->m13C[0])->s78(b);
        ((FeWQ7*)s->m13C[0])->s68(a);
        ((FeWQ7*)s->m13C[0])->s14(1);
        fn_80505E60(q);
    } else {
        ((FeWQ7*)s->m13C[0])->s68(((FeWQ7*)s->m13C[0])->s59() - 1 > 0 ? ((FeWQ7*)s->m13C[0])->s59() - 1 : 0);
    }
    fn_80505F40(q, 1, -1, -1);
    return 0;
}

extern "C" FE_OVERLAY int fn_80507A6C(FeScrN* x)
{
    x->m14C->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY void fn_80507AA8(FeScrQ* q, int kind, int x)
{
    FeScrA* s = (FeScrA*)q;
    FeStX* st = (FeStX*)((char*)fn_800B555C() + 8);
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    switch (kind) {
    case 1:
        fn_8040B830(mp->name, "BACK", 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, s);
        ((FeWQ6*)s)->s42(x);
        break;
    case 0: {
        int off = s->m13C[1]->fn_vslot60() * 4;
        char* b = (char*)s + 0x1F8;
        st->m4F4 = *(int*)(b + off);
        fn_8040B830(mp->name, "ADVANCE", 15);
        mp->name[15] = kind;
        fn_800B7B4C(FeGetMgr(), mp, s);
        ((FeWQ6*)s)->s41(x);
        s->fn_vslot8(0);
        s->fn_vslot16(0);
        break;
    }
    }
}

extern "C" FE_OVERLAY int fn_80507C38(FeScrA* x)
{
    if (x->m138->fn_vslot86() != 0) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507C80(FeScrA* x)
{
    if (x->m138->fn_vslot87() != 0) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507CC8(FeScrA* x)
{
    if (x->m154 == 0) {
        return fn_80507C38(x);
    }
    if (x->m154 == 1) {
        return fn_80507C80(x);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80507D10(FeScrQ* q)
{
    FeScrA* x = (FeScrA*)q;
    fn_80125154(x->m134, 1);
    if (x->m154 == 1 && x->m13C[1]->fn_vslot59() > 0) {
        fn_80125128(x->m134, 0);
        void* t = x->m134;
        fn_80125180(t, 3, fn_80507CC8(x) ? 0x37A2 : 0x1A2F);
    } else {
        fn_80125084(x->m134, 0);
        fn_80125084(x->m134, 3);
    }
}

extern "C" FE_OVERLAY int fn_80507DC4(void* self, int a)
{
    return a == 0;
}

extern "C" FE_OVERLAY void fn_80507DD0(FeScrQ* q)
{
    FeScrA* x = (FeScrA*)q;
    if (x->m154 == 1) {
        if (((FeWQ87*)x->m138)->s87() != 0) {
            int o = x->m13C[1]->fn_vslot60() * 4;
            FeList* l = x->m138;
            char* b = (char*)x + 0x1F8;
            fn_80126CF4(l, l->m164, *(int*)(b + o), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        }
    }
}

extern "C" FE_OVERLAY void fn_80507E8C(FeScrQ* q)
{
    FeScrA* x = (FeScrA*)q;
    if (x->m154 == 1) {
        x->m144[1]->fn_vslot8(1);
    } else {
        x->m144[1]->fn_vslot8(0);
    }
    FeList* l = x->m138;
    fn_80126CF4(l, 0, l->m168, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    l = x->m138;
    fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    fn_80505E60(q);
}

extern "C" FE_OVERLAY FeW* fn_80507F8C(FeScrN* x)
{
    int c = (int)x->m154;
    if (c == 1) {
        return x->m140;
    }
    if (c == 0) {
        return x->m13C;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80507FB8(FeScrN* x)
{
    return ((FeSub11*)((char*)x->m150 + 0xDC))->s11();
}

enum FeKB { FeKB_Neg = -1, FeKB_0 = 0, FeKB_10 = 10 };
extern "C" FE_OVERLAY int fn_80507FF4(void* self, int k)
{
    switch ((FeKB)k) {
    case 0:
        return 0;
    case 10:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 1:
        return 6;
    case 6:
        return 7;
    case 7:
        return 8;
    case 8:
        return 9;
    }
    return 0;
}

#define FE_FILLQ(SRCINIT, D, K, DINIT)                              \
    do {                                                            \
        DINIT;                                                      \
        fn_8040074C(self->D.m0, d_->m8 * 4);                        \
        SRCINIT;                                                    \
        d_->m4 = 0;                                                 \
        d_->mC = 0;                                                 \
        d_->m14 = 0;                                                \
        for (unsigned i = 0; i < sp->m4; i++) {                     \
            char* bb = (char*)sp->m0;                               \
            int off = i * 4;                                        \
            int val = *(int*)(bb + off);                            \
            if (d_->m4 < d_->m8) {                                  \
                d_->m0[d_->m4] = val;                               \
                d_->m4++;                                           \
            }                                                       \
        }                                                           \
        d_->m14 = 1;                                                \
        fn_80539AE8(&self->D, K);                                   \
    } while (0)

/* near-miss: 96.6%; retail moves the r4 argument (li r4,K) before the r3 argument in the three fn_80539AE8 calls and in fn_80537054; return-type toggles of all callees did not change it */
extern "C" FE_OVERLAY void fn_805080B8(FeBigQ* self)
{
    FeLstQ* s = &self->src;
    FeLstQ* d1 = &self->d1;
    fn_805371C4(s, 0x2000003F);
    fn_80537054(s, 0);
    FE_FILLQ(FeLstQ* sp = s, d1, 1, FeLstQ* d_ = d1);
    FE_FILLQ(FeLstQ* sp = &self->src, d2, 2, FeLstQ* d_ = &self->d2);
    FE_FILLQ(FeLstQ* sp = &self->src, d3, 3, FeLstQ* d_ = &self->d3);
}

extern "C" FE_OVERLAY int fn_805082B8(int c)
{
    int t = c - 0x41;
    if ((unsigned char)t > 0x19) {
        t = -1;
    }
    return t;
}

extern "C" FE_OVERLAY int fn_80508BF4(char* x, int a, int b)
{
    switch (a) {
    case 0:
        if (*(int*)(x + b * 0x4EC0 + 0x34D4) == 1) {
            return 1;
        }
        break;
    case 1:
        if (*(int*)(x + b * 0x2800 + 0x1A2B4) == 1) {
            return 1;
        }
        break;
    case 2:
        if (*(int*)(x + b * 0x3330 + 0x242B4) == 1) {
            return 1;
        }
        break;
    }
    fn_805082D0(x);
    return 0;
}
