/*
 * Shared types for the front-end overlay code 0x8043FDC0-0x80459228 (units fe/tu_8043FDC0
 * .. fe/tu_80455038; reconstructed, placeholder names; nothing here comes from original
 * headers). Every function defined in these units carries FE_OVERLAY (game/overlay.h).
 */
#ifndef GAME_TU_8043FDC0_H
#define GAME_TU_8043FDC0_H

#include "game/overlay.h"
#include "game/tu_8007A4DC.h"
#include "game/tu_8001B190.h"

void* operator new(unsigned int size, int heap);

/* Data part of the widget base (written by the common base ctor fn_800EC648, 0x3C bytes; +0x24
 * is a word of flag bits). */
struct UiBase {
    char pad0[0x24];
    int m24;
    char pad28[0x3C - 0x28];
};

/* Message manager singleton (lbl_8061A32C), 0xD8 bytes, ctor fn_800B64BC; created lazily. */
struct UiMsg {
    char name[16];
};
struct UiMsgMgr {
    char pad0[0xBC];
    int mBC;
    char padC0[0xD8 - 0xC0];
    UiMsgMgr();
};
extern UiMsgMgr* lbl_8061A32C;
inline UiMsgMgr* UiGetMsgMgr()
{
    if (lbl_8061A32C == 0)
        lbl_8061A32C = new (0) UiMsgMgr;
    return lbl_8061A32C;
}
extern "C" {
void fn_8035682C(UiMsg* m);
void fn_800B7B4C(UiMsgMgr* mgr, UiMsg* m, void* ctx);
void fn_800B7ADC(UiMsgMgr* mgr, void* ctx);
char* fn_8040B830(char* dst, const char* src, unsigned n);
}

/* A tunable float: +0x48 points at an override value when non-null, else +0x4C is the
 * default. Evidence: fn_8043FDD0 (lbl_8061B9A0 + 0x1DE0). */
struct FeTunable {
    char pad0[0x48];
    float* m48;
    float m4C;
};
inline float FeTunableGet(FeTunable* t)
{
    if (t->m48 == 0)
        return t->m4C;
    return *t->m48;
}

struct FeTunHolder {
    char pad0[0x1DE0];
    FeTunable m1DE0;
};

/* 8-byte polymorphic object built by the out-of-line ctor fn_803567AC (m0 = 0, vptr lbl_8065D410
 * at +4). A class with virtuals stays in memory, so retail recomputes `addi rX,r1,8` per use. */
struct Fe803567AC {
    int m0;
    Fe803567AC(); /* fn_803567AC */
    virtual void vf0();
};

struct Unk8005ADD0_Obj;
Unk8005ADD0_Obj* fn_8005ACE4();
void fn_8005B9D4(Unk8005ADD0_Obj* o, int a);

extern "C" {
void fn_800A3DF4(int a);
void fn_803FBFE0(const char* name, void* buf, int len);
int fn_80401610(void* a, int b, void* c, int d);
void fn_80377408(void* p);
void* fn_803774A8(unsigned n, int heap);
void fn_80072E90(Unk8007B2B0_Screen* s, void* a, int b, int c, int d, void* out);
void fn_800B8AF0(void* p);
void fn_80331294(void* p);
}
unsigned fn_800734D4(void* s, unsigned flags);
extern int lbl_80619948;
extern int lbl_80621608;
extern int lbl_8061B998;
extern "C" void fn_8043FF24(int a);
extern Unk8007B2B0_Screen* lbl_8061930C;
extern FeTunHolder* lbl_8061B9A0;


/* Front-end widget classes (vptr at +0x3C after the 0x3C-byte data base UiBase; retail's vtables are
 * .data objects, so these never define a virtual). One class per call signature: cast to the class
 * that has the arity of the call site. Virtual N is at vtable +8N ({delta, pfn} entries). */
#define FE_LO(X) \
    X(1) X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) \
    X(18) X(19) X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30) X(31)
#define FE_HI(X) \
    X(33) X(34) X(35) X(36) X(37) X(38) X(39) X(40) X(41) X(42) X(43) X(44) X(45) X(46) X(47) X(48) \
    X(49) X(50) X(51) X(52) X(53) X(54) X(55) X(56) X(57) X(58) X(59) X(60) X(61) X(62) X(63) X(64) \
    X(65) X(66) X(67) X(68) X(69) X(70) X(71) X(72) X(73) X(74) X(75) X(76) X(77) X(78) X(79) X(80) \
    X(81) X(82) X(83) X(84) X(85) X(86) X(87) X(88) X(89) X(90) X(91) X(92) X(93) X(94) X(95) X(96) \
    X(97) X(98) X(99) X(100) X(101) X(102) X(103) X(104) X(105) X(106) X(107) X(108) X(109) X(110) \
    X(111) X(112) X(113) X(114) X(115) X(116) X(117) X(118) X(119) X(120) X(121) X(122) X(123) \
    X(124) X(125) X(126) X(127)
#define FE_V0(n) virtual void v##n();
#define FE_V1(n) virtual void v##n(int a);
#define FE_V2(n) virtual void v##n(int a, int b);
#define FE_V3(n) virtual void v##n(int a, int b, int c);
#define FE_VI0(n) virtual int v##n();
#define FE_VI1(n) virtual int v##n(int a);
#define FE_VF0(n) virtual float v##n();
class FeObj : public UiBase {
public:
    FE_LO(FE_V0) virtual FeObj* v32(const char* a, int b); FE_HI(FE_V0)
};
class FeObj1 : public UiBase {
public:
    FE_LO(FE_V1) virtual FeObj* v32(const char* a, int b); FE_HI(FE_V1)
};
class FeObj2 : public UiBase {
public:
    FE_LO(FE_V2) virtual FeObj* v32(const char* a, int b); FE_HI(FE_V2)
};
class FeObj3 : public UiBase {
public:
    FE_LO(FE_V3) virtual FeObj* v32(const char* a, int b); FE_HI(FE_V3)
};
class FeObjI : public UiBase {
public:
    FE_LO(FE_VI0) virtual FeObj* v32(const char* a, int b); FE_HI(FE_VI0)
};
class FeObjI1 : public UiBase {
public:
    FE_LO(FE_VI1) virtual FeObj* v32(const char* a, int b); FE_HI(FE_VI1)
};
class FeObjF : public UiBase {
public:
    FE_LO(FE_VF0) virtual FeObj* v32(const char* a, int b); FE_HI(FE_VF0)
};

/* Screen derived from the widget base: data after the vptr starts at +0x40. All of the
 * m130.. fields are widget pointers unless a function proves otherwise. */
struct FeScr : FeObj {
    char pad40[0x130 - 0x40];
    int m130;
    FeObj* m134;
    FeObj* m138;
    FeObj* m13C;
    FeObj* m140;
    FeObj* m144;
    FeObj* m148;
    FeObj* m14C;
    FeObj* m150;
    FeObj* m154;
    FeObj* m158;
    FeObj* m15C;
    FeObj* m160;
    FeObj* m164;
    FeObj* m168;
    FeObj* m16C;
    FeObj* m170;
};

/* Screen as plain data: the ctors store the vtable address (a retail .data object) by hand. */
struct FeScrRaw {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x130 - 0x40];
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
};
extern "C" {
FeScrRaw* fn_800EC648(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_800ECE34(void* self);
void fn_800ECF18(void* self);
void fn_800ECAA4(void* self);
}

/* Game state record returned by fn_800B555C(); only the fields the front-end reads. */
struct FeState {
    int m0;
    char pad4[0x570 - 4];
    int m570;
    char pad574[0x588 - 0x574];
    int m588;
    char pad58C[4];
    int m590;
};

typedef void (*FeCb)(int, void*);
extern "C" {
FeState* fn_800B555C();
FeObj* fn_800B7A94(UiMsgMgr* mgr, const char* name);
void fn_801251CC(FeObj* o, int a, int b, int c);
int fn_800A1960(int a);
int fn_80546B18(int a, int b, int c);
void fn_80126CF4(void* o, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
int fn_800B5758(FeState* st);
void fn_800E4B70();
FeObj* fn_800C8040(void* p);
FeObj* fn_800C8044(void* p);
FeObj* fn_800C8054(void* p);
FeObj* fn_800C8058(void* p);
FeObj* fn_800C805C(void* p);
FeObj* fn_800C8060(void* p);
void fn_80131F34(FeObj* o, void* self, FeCb cb, int a, int b, int c, int d, int e, int f,
                 int g, int h, int i, int j, int k);
}

Unk8001BC8C* fn_8001BC4C();

/* Popup widget behind FeScr_80447264::m144 (fields read by fn_80448334). */
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

/* Screen with ctor fn_80447264 (fields as the functions prove). */
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
extern "C" {
void fn_80448334(FeScr_80447264* self);
void fn_80448480(FeScr_80447264* self);
void fn_80448528(FeScr_80447264* self);
void fn_80447E60(int a, FeScr_80447264* self);
void fn_80448D68(int a, FeScr_80447264* self);
}

#endif
