/*
 * Front-end overlay code, .frontend_codeoverlay 0x80471EBC-0x804740A8 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

struct Unk800C7B40_Data {
    int m0;
    int m4;
    int m8;
    char mC[16];
    int m1C;
    int m20;
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 1;
    unsigned b4 : 1;
    unsigned b5 : 1;
    unsigned b6 : 1;
    unsigned b7 : 1;
    unsigned b8 : 1;
    unsigned b9 : 1;
    unsigned b10 : 1;
    unsigned b11 : 1;
    unsigned b12 : 1;
    unsigned b13 : 1;
    unsigned b14 : 1;
    unsigned b15 : 1;
    short m26;
    short m28;
    short m2A;
    short m2C;
    short m2E;
    short m30;
    short m32;
    short m34;
    short m36;
    float m38;
};

struct Unk800C7B40_Widget : Unk800C7B40_Data {
    virtual ~Unk800C7B40_Widget();
    // BEGIN-SLOTS
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
    virtual void fn_vslot9(int a);
    virtual void fn_vslot10(int a);
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14(int a);
    virtual void fn_vslot15();
    virtual void fn_vslot16(int a);
    virtual void fn_vslot17();
    virtual void fn_vslot18(int a);
    virtual float fn_vslot19();
    virtual void fn_vslot20(float a);
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual Unk800C7B40_Widget* fn_vslot28(const char* name);
    virtual Unk800C7B40_Widget* fn_vslot29(const char* name);
    virtual Unk800C7B40_Widget* fn_vslot30(const char* name, int a);
    virtual int fn_vslot31();
    virtual Unk800C7B40_Widget* fn_vslot32(const char* name, int a);
    virtual Unk800C7B40_Widget* fn_vslot33(int a, int b);
    virtual const char* fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37(int a);
    virtual void fn_vslot38(int a);
    virtual void fn_vslot39();
    virtual void fn_vslot40(int a);
    virtual void fn_vslot41(int a);
    virtual void fn_vslot42();
    virtual void fn_vslot43(int a, int b, char* c, int d);
    virtual void fn_vslot44(int a, int b, char* c, int d);
    virtual void fn_vslot45();
    virtual void fn_vslot46();
    virtual void fn_vslot47(int a);
    virtual void fn_vslot48();
    virtual void fn_vslot49(int a);
    virtual void fn_vslot50();
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual void fn_vslot53();
    virtual void fn_vslot54();
    virtual void fn_vslot55();
    virtual void fn_vslot56();
    virtual void fn_vslot57();
    virtual int fn_vslot58();
    virtual int fn_vslot59();
    virtual int fn_vslot60();
    virtual int fn_vslot61();
    virtual void fn_vslot62();
    virtual void fn_vslot63();
    virtual void fn_vslot64();
    virtual void fn_vslot65();
    virtual void fn_vslot66();
    virtual void fn_vslot67(int a, int b);
    virtual void fn_vslot68(int a);
    virtual void fn_vslot69();
    virtual Unk800C7B40_Widget* fn_vslot70();
    virtual void fn_vslot71();
    virtual void fn_vslot72();
    virtual Unk800C7B40_Widget* fn_vslot73(int idx, int a);
    virtual void fn_vslot74();
    virtual void fn_vslot75();
    virtual void fn_vslot76();
    virtual void fn_vslot77();
    virtual void fn_vslot78();
    virtual void fn_vslot79(int a, int b);
    virtual void fn_vslot80(int a);
    virtual void fn_vslot81();
    virtual void fn_vslot82();
    virtual int fn_vslot83();
    virtual void fn_vslot84(int a, int b);
    virtual int fn_vslot85();
    virtual int fn_vslot86();
    virtual int fn_vslot87();
    virtual void fn_vslot88(int a);
    virtual void fn_vslot89(int a);
    virtual int fn_vslot90();
    virtual int fn_vslot91();
    virtual void fn_vslot92();
    virtual void fn_vslot93();
    virtual void fn_vslot94();
    virtual void fn_vslot95();
    virtual void fn_vslot96();
    virtual void fn_vslot97();
    virtual void fn_vslot98();
    virtual void fn_vslot99();
    virtual void fn_vslot100();
    virtual void fn_vslot101();
    virtual void fn_vslot102();
    virtual void fn_vslot103();
    virtual void fn_vslot104();
    virtual void fn_vslot105(int a);
    virtual void fn_vslot106();
    virtual void fn_vslot107();
    virtual void fn_vslot108();
    virtual void fn_vslot109();
    virtual void fn_vslot110();
    virtual void fn_vslot111();
    virtual void fn_vslot112();
    virtual void fn_vslot113();
    virtual void fn_vslot114();
    virtual void fn_vslot115();
    virtual void fn_vslot116();
    virtual void fn_vslot117();
    virtual void fn_vslot118();
    virtual void fn_vslot119();
    virtual void fn_vslot120();
    virtual void fn_vslot121();
    virtual void fn_vslot122();
    virtual void fn_vslot123();
    virtual void fn_vslot124();
    virtual void fn_vslot125();
    virtual void fn_vslot126();
    virtual void fn_vslot127();
    // END-SLOTS
    void SetVptr(const void* v) { *(const void**)((char*)this + 0x3C) = v; }
};

struct Unk80354D4_Obj : Unk800C7B40_Widget {    /* object at +0x180: the unit-2 screen class, +0x2F0 */
    char pad40[0x2B0];
    int m2F0;
};

struct Unk80135680 : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    char pad144[0x18];
    int m15C;
    int m160;
    char pad164[0x18];
    const void* m17C;
    Unk80354D4_Obj* m180;
    int m184[12];
    int m1B4[8];
    int m1D4;
    const char* m1D8;
    int m1DC;
    Unk800C7B40_Widget* m1E0;
    Unk800C7B40_Widget* m1E4;
    int m1E8;
    int m1EC;
};

typedef Unk80135680 Scr;

extern "C" void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);

extern const char lbl_80678AB0[];

extern "C" FE_OVERLAY Scr* fn_80471EBC(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80678AB0);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    return self;
}

typedef Unk800C7B40_Widget FeW;

struct FeScrK : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
};

extern "C" void fn_800ECAA4(void* x);

extern "C" FE_OVERLAY void fn_804731C4(FeScrK* x)
{
    fn_800ECAA4(x);
}

struct UiBase {
    char pad0[0x24];
    int m24;
    short m28;
    short m2A;
    short m2C;
    short m2E;
    short m30;
    short m32;
    short m34;
    short m36;
    float m38;
};

#define FE_LO(X) \
    X(1) X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) \
    X(18) X(19) X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30) X(31)

#define FE_V0(n) virtual void v##n();

#define FE_HI(X) \
    X(33) X(34) X(35) X(36) X(37) X(38) X(39) X(40) X(41) X(42) X(43) X(44) X(45) X(46) X(47) X(48) \
    X(49) X(50) X(51) X(52) X(53) X(54) X(55) X(56) X(57) X(58) X(59) X(60) X(61) X(62) X(63) X(64) \
    X(65) X(66) X(67) X(68) X(69) X(70) X(71) X(72) X(73) X(74) X(75) X(76) X(77) X(78) X(79) X(80) \
    X(81) X(82) X(83) X(84) X(85) X(86) X(87) X(88) X(89) X(90) X(91) X(92) X(93) X(94) X(95) X(96) \
    X(97) X(98) X(99) X(100) X(101) X(102) X(103) X(104) X(105) X(106) X(107) X(108) X(109) X(110) \
    X(111) X(112) X(113) X(114) X(115) X(116) X(117) X(118) X(119) X(120) X(121) X(122) X(123) \
    X(124) X(125) X(126) X(127)

class FeObj : public UiBase {
public:
    FE_LO(FE_V0) virtual FeObj* v32(const char* a, int b); FE_HI(FE_V0)
};

struct FePopup : FeObj {
    char pad40[0x134 - 0x40];
    int m134;
    int m138;
    int m13C;
    char pad140[8];
    int m148;
    int m14C;
    char pad150[0x164 - 0x150];
    int m164;
    char pad168[4];
    int m16C;
    int m170;
};

struct FeScr_80447264 : FeObj {
    char pad40[0x130 - 0x40];
    int m130;
    FeObj* m134;
    FeObj* m138;
    FeObj* m13C;
    FeObj* m140;
    FePopup* m144;
    FeObj* m148;
    FeObj* m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
};

extern "C" FE_OVERLAY int fn_804731E4(FeScr_80447264* self)
{
    self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473220(FeScr_80447264* self)
{
    self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047325C(FeScr_80447264* self)
{
    self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473298(FeScr_80447264* self)
{
    self->m134->v53();
    return 1;
}

extern "C" void fn_80473560(void* x);

extern "C" FE_OVERLAY void fn_80473630(FeScrK* x)
{
    fn_80473560(x);
}

struct UiObj;

extern "C" void fn_80473440(UiObj* a);

extern "C" FE_OVERLAY void fn_80473650(int a, UiObj* b)
{
    switch (a) {
    case 0:
        break;
    case 1:
        fn_80473440(b);
        break;
    }
}

struct FeScrN : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
    FeW* m138;
    FeW* m13C;
    FeW* m140;
    FeW* m144;
    FeW* m148;
    FeW* m14C;
    FeW* m150;
    FeW* m154;
    FeW* m158;
    FeW* m15C;
    FeW* m160;
    FeW* m164;
    FeW* m168;
    FeW* m16C;
    FeW* m170;
    FeW* m174;
    FeW* m178;
    FeW* m17C;
    FeW* m180;
    FeW* m184;
    FeW* m188;
    FeW* m18C;
    FeW* m190;
};

extern const char lbl_80678560[];

extern "C" FE_OVERLAY FeScrN* fn_80473AE8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80678560);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_80473EB4(FeScr_80447264* self)
{
    self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473EF0(FeScr_80447264* self)
{
    self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473F2C(FeScr_80447264* self)
{
    self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80473F68(FeScr_80447264* self)
{
    self->m134->v53();
    return 1;
}
