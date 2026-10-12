/*
 * Front-end overlay code, .frontend_codeoverlay 0x80508C98-0x8050C9DC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804FE34C.h"

/* Q16-DECL-BEGIN */
struct Unk8007F198_B;
extern "C" int fn_805562B8();
int fn_8007F7D0(Unk8007F198_B* b, unsigned i);
class FeSubI8 {
public:
    char pad0[0x24];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual void s8(int a);
    virtual int s9();
    virtual int s10();
    virtual int s11();
};
extern const char lbl_805FA6D4[];
extern "C" {
int fn_804CE204(int a);
void* fn_800C33D0();
int fn_800C8038(FeW* w);
void fn_800C4568(void* g, int a, int b);
void fn_8050B220(FeScrN* x, int a, int b, int c);
}
extern "C" FeW* fn_8050C408(FeScrN* x);
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
struct FeScr8A9 : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
    char pad138[0x140 - 0x138];
    FeList* m140;
    FeW* m144;
    char pad148[0x150 - 0x148];
    int m150;
};
extern "C" {
int fn_805563C4(void* p);
int fn_80556410(void* p);
}
extern const char lbl_805F5068[];
extern const char lbl_805FA764[];
extern const char lbl_805FB670[];
extern const char lbl_805F4F84[];
extern "C" FeW* fn_800C805C(FeW* w);
extern "C" FeW* fn_800C8058(FeW* w);
extern "C" void fn_80124FA8(void* o, void* s);
struct FeStQ {
    int m0;
    int m4;
    char pad8[0x608 - 8];
    int m608;
};
int fn_80084114(int v);
extern "C" void fn_800C2018(void* o, int* a, int* b, int* c);
extern "C" void fn_800ECF18(void* x);
int fn_80083FC0(int a);
/* Q16-DECL-END */

extern const char lbl_80668118[];
extern "C" void fn_80556348(void* p);
extern int lbl_8061AC54;
extern const char lbl_80668668[];
extern const char lbl_805F4F8C[];
extern "C" void fn_802BA708__FP11Unk802B9F40(void* p);
extern "C" void fn_80083E84__FiPiT1(int a, int* b, int* c);
extern "C" int fn_8057CE00(int v);
extern "C" void fn_8050AE0C(FeScrQ* x, int a, int b, int c);
extern char* lbl_8061E978;
extern "C" void fn_8050A9F0(void* x);
extern const char lbl_805FB738[];
extern const char lbl_805FB744[];
extern const char lbl_805FB750[];
extern const char lbl_805F4EF4[];
extern const char lbl_805F4450[];
extern "C" FeScrQ* fn_80508C98(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_80508CF8(FeScrN* x);
extern "C" void fn_80508FBC(FeScrD* x);
extern "C" void fn_8050A4A8(void* x, int a);
extern "C" int fn_8050A4FC(FeScrN* x);
extern "C" int fn_8050A570(FeScrN* x);
extern "C" int fn_8050A5E4(FeScrN* x);
extern "C" int fn_8050A658(FeScrN* x);
extern "C" int fn_8050A6CC(FeScrN* x);
extern "C" int fn_8050A72C(FeScrN* x);
extern "C" int fn_8050A78C(FeScrN* x);
extern "C" int fn_8050A7EC(FeScrN* x);
extern "C" int fn_8050A84C(FeScrQ* x, FeW* w, int b, int n);
extern "C" void fn_8050A8DC(void* x, int v);
extern "C" int fn_8050A8E0(void);
extern "C" void fn_8050A8E8();
extern "C" void fn_8050A8EC(void* x);
extern "C" void fn_8050A970(void* p);
extern "C" FeRecList* fn_8050AB58(FeRecList* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_8050BED4(FeScrD* x);
extern "C" void fn_8050BEFC(FeScrN* x, int a);
extern "C" int fn_8050BFC0(FeScrN* x);
extern "C" int fn_8050C000(FeScrN* x, int a);
extern "C" int fn_8050C03C(FeScrN* x);
extern "C" int fn_8050C07C(FeScrN* x);
extern "C" int fn_8050C0B8(FeScrN* x);
extern "C" int fn_8050C0F4(FeScrN* x);
extern "C" int fn_8050C130(FeScrN* x);
extern "C" int fn_8050C16C(FeScrN* x);
extern "C" int fn_8050C1A8(FeScrN* x);
extern "C" int fn_8050C1E4(FeScrN* x);
extern "C" int fn_8050C220(FeScrN* x);
extern "C" int fn_8050C25C(FeScrN* x);
extern "C" FeW* fn_8050C380(FeScrN* x, int idx);
extern "C" FeW* fn_8050C408(FeScrN* x);
extern "C" int fn_8050C42C(FeRecList* x, int id);
extern "C" void fn_8050C68C(FeScrQ* x, int id);

extern "C" FE_OVERLAY FeScrQ* fn_80508C98(FeScrQ* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80668668);
    self->m130 = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m154 = -1;
    self->m158 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80508CF8(FeScrN* x)
{
    fn_800ECE34(x);
    x->m140 = (FeW*)fn_800B7AB8(FeGetMgr(), lbl_805F4F8C);
}

extern "C" FE_OVERLAY void fn_80508FBC(FeScrD* x)
{
    fn_800ED254(x);
}

extern "C" FE_OVERLAY void fn_8050A4A8(void* x, int a)
{
    switch (a) {
    case 0:
        fn_8050A8EC(x);
        break;
    case 1:
        fn_8050A970(x);
        break;
    case 2:
        fn_8050A9F0(x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_8050A4FC(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot56();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A570(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot57();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A5E4(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot54();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A658(FeScrN* x)
{
    if (FeW24(x->m140) >= 0) {
        fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot55();
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A6CC(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A72C(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A78C(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A7EC(FeScrN* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050A84C(FeScrQ* x, FeW* w, int b, int n)
{
    if (w == (FeW*)x->m134) {
        if (n > 0) {
            w->fn_vslot68(n);
            x->fn_vslot67(2, fn_800C8070(x));
        }
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_8050A8DC(void* x, int v)
{
}

extern "C" FE_OVERLAY int fn_8050A8E0(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_8050A8E8()
{
}

extern "C" FE_OVERLAY void fn_8050A8EC(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F4450, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY void fn_8050A970(void* p)
{
    FeScrN* x = (FeScrN*)p;
    int r = fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot61();
    fn_8050A8DC(x, r);
    fn_8001BC4C()->fn_8001BDAC(0xA3);
}

extern "C" FE_OVERLAY void fn_8050A9F0(void* p)
{
    FeScr8A9* x = (FeScr8A9*)p;
    if (((FeWQ87*)x->m140)->s87() == 0) {
        FeList* l = x->m140;
        fn_80126CF4(l, l->m164, x->m150, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        ((FeWQ87*)x->m140)->s84(1, 0);
        fn_801251CC(x->m144, 3, 0x37A2, 2);
        x->m134->fn_vslot16(0);
    } else {
        FeList* l = x->m140;
        fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
        fn_801251CC(x->m144, 3, 0x1A2F, 2);
        x->m134->fn_vslot16(1);
    }
    fn_8001BC4C()->fn_8001BDAC(0xA3);
}

extern "C" FE_OVERLAY FeRecList* fn_8050AB58(FeRecList* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    FeRec28* p = self->m14C;
    int i = 11;
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80668118);
    self->m130 = 0;
    ((FeScrQ*)self)->m134 = 0;
    ((FeScrQ*)self)->m138 = 0;
    ((FeScrQ*)self)->m13C = 0;
    ((FeScrQ*)self)->m140 = 0;
    ((FeScrQ*)self)->m144 = 0;
    self->m148 = 0;
    do {
        fn_80556348(p);
        p++;
    } while (i-- != 0);
    int one = 1;
    lbl_8061AC54 = one;
    return self;
}

extern "C" FE_OVERLAY void fn_8050ABE8(FeScrQ* x)
{
    fn_800ECF18(x);
    x->m13C = (int)fn_800C805C(x->fn_vslot32(lbl_805F5068, 1));
    x->m140 = (int)fn_800C8058(((FeW*)x->m13C)->fn_vslot32(lbl_805FA764, 1));
    x->m138 = (int)fn_800C8058(x->fn_vslot32(lbl_805FB670, 1));
    x->m144 = (int)fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    ((FeW*)x->m138)->fn_vslot8(0);
    fn_800C3AB4(fn_800C33D0(), 9);
    fn_80124FA8((void*)x->m144, x);
    if (fn_800B555C()->m0 == 0x1B)
        fn_80125128((void*)x->m144, 2);
    else
        fn_80125154((void*)x->m144, 0);
    int idx = ((FeStQ*)fn_800B555C())->m608;
    int a = 0;
    int b = 0;
    fn_80083E84__FiPiT1(idx, &a, &b);
    int c = 0;
    x->m134 = fn_8057CE00(idx);
    if (((FeStQ*)fn_800B555C())->m4 & 1) {
        Unk8007B2B0_Screen* g = (Unk8007B2B0_Screen*)lbl_8061930C;
        int t = fn_80083FC0(idx);
        a = g->fn_8007B8C4(0, g->fn_8007B320(t, fn_8007F7D0((Unk8007F198_B*)g, 0)));
    } else {
        fn_800C2018((char*)fn_800B555C() + 8, &x->m134, &c, &a);
        fn_80084114(a);
    }
    if (x->m134 == 3)
        x->m134 = 2;
    fn_8050AE0C(x, x->m134, c, a);
}

extern "C" FE_OVERLAY void fn_8050B12C(FeScrN* x, int a, int b, int c)
{
    x->fn_vslot32(lbl_805FA6D4, 1)->fn_vslot8(0);
    int h = fn_804CE204(c);
    void* g = fn_800C33D0();
    fn_800C4568(g, fn_800C8038(x->fn_vslot32(lbl_805FA6D4, 1)), h);
    ((FeSubI8*)((char*)x->m140 + 0xDC))->s8(c);
    fn_8050B220(x, a, b, c);
}

extern "C" FE_OVERLAY void fn_8050BED4(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_8050BEFC(FeScrN* x, int a)
{
    fn_800ED310(x, a);
    if (a != 0) {
        fn_8050C408(x)->fn_vslot16(1);
        fn_8050C408(x)->fn_vslot14(1);
    } else {
        x->fn_vslot14(0);
        fn_8050C408(x)->fn_vslot16(0);
    }
}

extern "C" FE_OVERLAY int fn_8050BFC0(FeScrN* x)
{
    x->m13C->fn_vslot40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C000(FeScrN* x, int a)
{
    x->m13C->fn_vslot41(a);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C03C(FeScrN* x)
{
    x->m13C->fn_vslot38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C07C(FeScrN* x)
{
    x->m13C->fn_vslot39();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C0B8(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C0F4(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C130(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C16C(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C1A8(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C1E4(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C220(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_8050C25C(FeScrN* x)
{
    fn_8050C408(x)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY void fn_8050C298()
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0);
    int c = fn_805562B8();
    if (c != 0) {
        fn_8040B830(mp->name, "WINNER", 15);
        mp->name[15] = 0;
    } else {
        fn_8040B830(mp->name, "ADVANCE", 15);
        mp->name[15] = c;
    }
    fn_800B7B4C(FeGetMgr(), &m, fn_800B7AB8(FeGetMgr(), "PLAYOFFTREE"));
}

extern "C" FE_OVERLAY FeW* fn_8050C380(FeScrN* x, int idx)
{
    if (idx == 0) {
        return fn_800C8060(x->fn_vslot32(lbl_805FB738, 1));
    }
    if (idx == 1) {
        return fn_800C8060(x->fn_vslot32(lbl_805FB744, 1));
    }
    if (idx == 2) {
        return fn_800C8060(x->fn_vslot32(lbl_805FB750, 1));
    }
    return 0;
}

extern "C" FE_OVERLAY FeW* fn_8050C408(FeScrN* x)
{
    return fn_8050C380(x, (int)x->m134);
}

int fn_80084114(int v);
/* near-miss: retail walks a pointer (r3 += 0x28) with n in r11 and i in r9; ours keeps the pointer in r9 and n in r10; 6 variants tried */
extern "C" FE_OVERLAY int fn_8050C42C(FeRecList* x, int id)
{
    int idx = 0;
    if (fn_80084114(id) != 0) {
        int n = x->m148;
        FeRec28* p = x->m14C;
        for (int i = 0; i < n; i++) {
            if (p->m0 == id) {
                idx = i;
                break;
            }
            p++;
        }
    }
    return idx;
}

extern "C" FE_OVERLAY void fn_8050C4B0(FeScrN* x, FeW* w)
{
    if (w == fn_8050C408(x)) {
        int v = w->fn_vslot61() * w->fn_vslot59() + w->fn_vslot60();
        int sel = ((FeSubI8*)((char*)x->m140 + 0xDC))->s11();
        char* e = (char*)x + ((fn_8050C42C((FeRecList*)x, sel) + v) * 0x28 + 0x14C);
        if (fn_805563C4(e) != fn_80556410(e))
            fn_801251CC(x->m144, 2, 0x34EE, 1);
        else
            fn_80125084(x->m144, 2);
    }
}

extern "C" FE_OVERLAY void fn_8050C5BC(FeScrN* x, int a)
{
    if (a == (int)x->m13C) {
        int sel = ((FeSubI8*)((char*)x->m140 + 0xDC))->s11();
        FeW* w = fn_8050C408(x);
        int v = w->fn_vslot61() * w->fn_vslot59() + w->fn_vslot60();
        fn_8050B12C(x, (int)x->m134, v, sel);
    }
}

extern "C" FE_OVERLAY void fn_8050C68C(FeScrQ* x, int id)
{
    fn_802BA708__FP11Unk802B9F40(lbl_8061E978 + 0xFAB0);
    int a = 0;
    int b = 0;
    fn_80083E84__FiPiT1(id, &a, &b);
    int t = fn_8057CE00(id) > 2 ? 2 : fn_8057CE00(id);
    x->m134 = t;
    fn_8050AE0C(x, t, 0, a);
}
