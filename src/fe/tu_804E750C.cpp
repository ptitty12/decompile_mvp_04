/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E750C-0x804EA2E4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#define FE_SCREEN_CF44_VOID

#include "game/fe_804E02E0.h"

/* Q16-DECL-BEGIN */
struct FeS7a : FeObj {
    char pad40[0x134 - 0x40];
    FeObj1* m134;
    int m138;
    FeObj* m13C;
    FeObjK* m140;
    FeObj1* m144;
    char pad148[0x14C - 0x148];
    FeObj* m14C;
    FeObj* m150;
    char pad154[0x164 - 0x154];
    FeObj* m164;
};
struct FeS7b : FeObj {
    char pad40[0x134 - 0x40];
    int m134;
    char pad138[0x150 - 0x138];
    FeObj* m150;
};
extern char lbl_805F4F84[];
extern char lbl_805FA7B4[];
extern "C" {
void fn_804E8B40(void);
void fn_8013D164(FeObj* w, int v);
void fn_804E8780(FeS7a* self);
int fn_804E8A30(FeS7b* self, unsigned short* s);
void fn_804E8CB4(FeS9* self);
void fn_800DFF5C(unsigned short* s);
int fn_80403060(const unsigned short* s);
int fn_804030C8(const unsigned short* a, const unsigned short* b);
}
unsigned fn_8007DBB0(Unk8007DB74_A* a);
#define FE_LO30(X) \
    X(1) X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) \
    X(18) X(19) X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30)
class FeObjR31 : public UiBase {
public:
    FE_LO30(FE_V0) virtual const void* v31(); virtual FeObj* v32(const char* a, int b); FE_HI(FE_V0)
};
struct FeS7c : FeObj {
    char pad40[0x134 - 0x40];
    int m134;
    char pad138[0x13C - 0x138];
    FeObjR31* m13C;
};
struct FeS7d : FeObj {
    char pad40[0x134 - 0x40];
    int m134;
    char pad138[0x160 - 0x138];
    int m160;
    char pad164[0x168 - 0x164];
    int m168;
    int m16C;
};
extern "C" int sprintf(char* d, const char* fmt, ...);
void fn_800E2944(int a, int b);
#define FE_R33_42(X) X(33) X(34) X(35) X(36) X(37) X(38) X(39) X(40) X(41) X(42)
#define FE_R44_66(X) \
    X(44) X(45) X(46) X(47) X(48) X(49) X(50) X(51) X(52) X(53) X(54) X(55) X(56) X(57) X(58) X(59) X(60) \
    X(61) X(62) X(63) X(64) X(65) X(66)
#define FE_R68_127(X) \
    X(68) X(69) X(70) X(71) X(72) X(73) X(74) X(75) X(76) X(77) X(78) X(79) X(80) X(81) X(82) X(83) X(84) \
    X(85) X(86) X(87) X(88) X(89) X(90) X(91) X(92) X(93) X(94) X(95) X(96) X(97) X(98) X(99) X(100) \
    X(101) X(102) X(103) X(104) X(105) X(106) X(107) X(108) X(109) X(110) X(111) X(112) X(113) X(114) \
    X(115) X(116) X(117) X(118) X(119) X(120) X(121) X(122) X(123) X(124) X(125) X(126) X(127)
/* List widget whose v43 takes (row, col, text, flags) and v67 two ints. */
class FeObjL43 : public UiBase {
public:
    FE_LO(FE_V0) virtual FeObj* v32(const char* a, int b); FE_R33_42(FE_V0) virtual void v43(int a, int b, void* c, int d);
    FE_R44_66(FE_V0) virtual void v67(int a, int b); FE_R68_127(FE_V0)
};
struct FeS7e : FeObj {
    char pad40[0x134 - 0x40];
    FeObj1* m134;
    char pad138[0x140 - 0x138];
    FeObjL43* m140;
    FeObj1* m144;
};
struct FeSt8x {
    char pad0[0x610];
    int m610;
};
/* Q16-DECL-END */

extern "C" FE_OVERLAY void fn_804E7860(void* self, int a)
{
    fn_800ECAA4(self);
}

extern "C" FE_OVERLAY int fn_804E7880(FeS7* self)
{
    if (self->m140->m24 & 0x40000000) {
        int a = ((FeObjK*)self->m140)->v60();
        if (a == ((FeObjK*)self->m140)->v59() - 1)
            fn_804E7D44(self, 0);
        else
            fn_804E7D44(self, 1);
    } else
        ((FeObj2*)self)->v67(0, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7940(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v50();
    else
        self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E79A8(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v51();
    else
        self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7A10(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v52();
    else
        self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7A78(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v53();
    else
        self->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7AE0(FeWf134* self)
{
    self->m134->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7B1C(FeWf134* self)
{
    self->m134->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7B58(FeWf134* self)
{
    self->m134->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7B94(FeWf134* self)
{
    self->m134->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7BD0(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804E7BD8(FeS7e* self)
{
    self->m144->v16(1);
    self->m144->v8(1);
    self->m134->v16(0);
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    ((FeObj1*)fn_800B7A94(UiGetMsgMgr(), lbl_805F4F84))->v16(0);
    Unk8007B2B0_Screen* sc = lbl_8061930C;
    unsigned short tmp[12];
    for (unsigned i = 0; i < fn_8007DBB0((Unk8007DB74_A*)sc); i++) {
        sc->fn_8007CF44(i, (int)tmp, 0);
        self->m140->v43(i, 0, tmp, 5);
    }
    self->m140->v67(0, 0);
}

extern "C" FE_OVERLAY void fn_804E7D44(FeS7* s7, int a)
{
    FeS7a* self = (FeS7a*)s7;
    self->m144->v16(0);
    self->m144->v8(0);
    self->m134->v16(1);
    ((FeObj1*)fn_800B7A94(UiGetMsgMgr(), lbl_805F4F84))->v16(1);
    if (a != 0) {
        self->m138 = self->m140->v60();
        ((FeObj2*)self)->v67(0, 0);
    } else {
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        self->m138 = -1;
    }
}

extern char lbl_8066BA30[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E80FC(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066BA30;
    self->m130 = 0;
    self->m134 = -1;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m160 = -1;
    self->m16C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E858C(FeS7a* self)
{
    fn_800ECF18(self);
    self->m164 = fn_800B7A94(UiGetMsgMgr(), lbl_805F4F84);
    fn_80124FA8(self->m164, self);
    fn_80125154(self->m164, 1);
    if (fn_800B555C()->m0 != 0x4D)
        fn_801251CC(self->m164, 0, 0x10, 0);
    fn_8013D164(self->m14C, 8);
    fn_804E8780(self);
}

extern "C" FE_OVERLAY void fn_804E8640(void)
{
}

extern "C" FE_OVERLAY void fn_804E8644(void* s)
{
    FeS7c* self = (FeS7c*)s;
    FeObj* a = fn_800C8044(self->v32("INFO", 1));
    FeObj* b = fn_800C8040(a->v32("NAME", 1));
    ((FeObj1*)b)->v28((int)self->m13C->v31());
    int k = 0;
    if (self->m134 != -1)
        k = lbl_8061930C->fn_8007D050(self->m134, 8);
    char buf[400];
    sprintf(buf, "%d", k);
    ((FeObjS*)fn_800C8040(a->v32("CREDITS", 1)))->v30(buf);
}

extern "C" FE_OVERLAY int fn_804E8A30(FeS7b* self, unsigned short* s)
{
    Unk8007B2B0_Screen* sc = lbl_8061930C;
    int cur = self->m134;
    unsigned short tmp[12];
    for (unsigned i = 0; i < fn_8007DBB0((Unk8007DB74_A*)lbl_8061930C); i++) {
        if ((int)i != cur) {
            sc->fn_8007CF44(i, (int)tmp, 0);
            if (fn_804030C8(tmp, s) == 0) {
                fn_80131F34(self->m150, self, (FeCb)fn_804E8B40, 0, 0x3FD7, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
                ((FeObj1*)self->m150)->v84(0);
                self->m150->v86();
                return 1;
            }
        }
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804E8B40(void)
{
}

extern "C" FE_OVERLAY void fn_804E8B44(unsigned short* name)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), lbl_805FA7B4);
    unsigned short buf[100];
    fn_80403144((char*)buf, (const char*)name);
    fn_800DFF5C(buf);
    ((FeObj1*)p)->v16(1);
    ((FeObj1*)p)->v8(1);
    if (fn_80403060(buf) > 0 && fn_804E8A30((FeS7b*)p, buf) == 0)
        ((void (*)(FeObj*, unsigned short*))fn_804E8CB4)(p, buf);
}

extern "C" FE_OVERLAY void fn_804E8C20(void)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "USERPROFEDIT");
    ((FeObj1*)p)->v16(1);
    ((FeObj1*)p)->v8(1);
}

extern "C" FE_OVERLAY void fn_804E8CB4(FeS9* self)
{
    self->m13C->v28();
    fn_804E8644(self);
}

extern "C" FE_OVERLAY void fn_804E8D00(int a, FeObj* self)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), lbl_805FA7B4);
    UiMsg m;
    UiMsg* mp = &m;
    fn_8035682C(mp);
    ((FeObj1*)p)->v16(1);
    ((FeObj1*)p)->v8(1);
    FeS7d* d = (FeS7d*)p;
    d->m16C = 0;
    if (a == 0)
        fn_800E2944(d->m134, d->m160);
    if (d->m168 != 0) {
        fn_8040B830(mp->name, "SAVE", 15);
        mp->name[15] = 0;
    } else {
        fn_8040B830(mp->name, "DONE", 15);
        mp->name[15] = 0;
    }
    ((FeObj1*)self)->v80(1);
    fn_800B7B4C(UiGetMsgMgr(), &m, self);
}

extern "C" FE_OVERLAY void fn_804E9220(FeS7* self)
{
    fn_800E29CC((int)self->m134);
}

extern "C" FE_OVERLAY void fn_804E9244(FeS7* self, int a)
{
    fn_800ED310(self, a);
    if (a != 0)
        ((FeObj1*)self->m138)->v14(1);
    else
        ((FeObj1*)self->m138)->v14(0);
}

extern "C" FE_OVERLAY int fn_804E92C0(FeS11* self)
{
    self->m138->v50();
    int a = ((FeObjK*)self->m138)->v60() + 1;
    if (a == ((FeObjK*)self->m138)->v59() || ((FeObjK*)self->m138)->v60() == 0)
        fn_801251CC(self->m164, 0, 16, 0);
    else
        fn_80125084(self->m164, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E9394(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E93D0(FeS11* self)
{
    self->m138->v52();
    int a = ((FeObjK*)self->m138)->v60() + 1;
    if (a == ((FeObjK*)self->m138)->v59() || ((FeObjK*)self->m138)->v60() == 0)
        fn_801251CC(self->m164, 0, 16, 0);
    else
        fn_80125084(self->m164, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E94A4(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E94E0(FeWf138* self)
{
    self->m138->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E951C(FeWf138* self)
{
    self->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E9558(FeWf138* self)
{
    self->m138->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E9594(FeWf138* self)
{
    self->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E95D0(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804E95D8(FeS8* self, int a)
{
    if (a == self->m144) {
        fn_800D0074(&self->m158->mDC, ((FeSub*)&self->m148->mDC)->s11(), 0);
        fn_800D0074(&self->m15C->m98, ((FeSub*)&self->m148->mDC)->s11(), 0);
    }
}

extern char lbl_8066B788[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E9810(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066B788;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E9868(FeS7* self)
{
    fn_800ECE34(self);
    self->m134 = fn_800C8060(self->v32("PROFILES", 1));
    ((FeObj1*)self->m134)->v105(1);
    self->m138 = fn_800C8044(self->v32("INFO", 1));
    if (fn_800B555C()->m0 == 0x4D)
        self->m13C = 1;
    else if (fn_800B555C()->m4 & 0x200)
        self->m13C = 2;
}

extern "C" FE_OVERLAY int fn_804E9C20(FeS7* self)
{
    int r;
    if (self->m13C != 0)
        r = ((FeObjK*)self->m134)->v60();
    else
        r = ((FeObjK*)self->m134)->v60() - 1;
    return r;
}

extern "C" FE_OVERLAY void fn_804EA038(FeS7* self, int a)
{
    if (a == (int)self->m134)
        fn_800E26B4(fn_804E9C20(self), (int)self->m138);
}

extern "C" FE_OVERLAY int fn_804EA078(FeScr_80447264* self)
{
    self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA0B4(FeScr_80447264* self)
{
    self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA0F0(FeScr_80447264* self)
{
    self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA12C(FeScr_80447264* self)
{
    self->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA168(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804EA170(FeS7* self, int kind, int x)
{
    switch (kind) {
    case 0: {
        UiMsg m;
        UiMsg* mp = &m;
        fn_8035682C(mp);
        if (self->m13C == 1) {
            fn_8040B830(mp->name, "EDIT", 15);
            mp->name[15] = 0;
            FeSt8x* st = (FeSt8x*)((char*)fn_800B555C() + 8);
            st->m610 = fn_804E9C20(self);
        } else if (self->m13C == 2) {
            fn_8040B830(mp->name, "SAVE", 15);
            mp->name[15] = 0;
            fn_800E29CC(fn_804E9C20(self));
        } else {
            fn_8040B830(mp->name, "SETACTIVE", 15);
            mp->name[15] = 0;
            fn_800E2944(fn_804E9C20(self), x);
        }
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
        break;
    }
    case 1: {
        UiMsg m;
        UiMsg* mp = &m;
        fn_8035682C(mp);
        fn_8040B830(mp->name, "BACK", 15);
        mp->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
        break;
    }
    }
}
