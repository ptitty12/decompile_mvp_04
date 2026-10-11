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
struct FeGame;

/* Data part of the widget base (written by the common base ctor fn_800EC648, 0x3C bytes; +0x24
 * is a word of flag bits). */
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
void fn_800A3DF4(FeGame* g);
void fn_803FBFE0(const char* name, void* buf, int len);
int fn_80401610(void* a, int b, void* c, int d);
void fn_80377408(void* p);
void* fn_803774A8(unsigned n, int heap);
void fn_80072E90(Unk8007B2B0_Screen* s, void* a, int b, int c, int d, void* out);
void fn_800B8AF0(void* p);
void fn_80331294(void* p);
}
unsigned fn_800734D4(void* s, unsigned flags);
/* lbl_80619948: the game/franchise object (fields as the front-end reads them). */
struct FeGame {
    char pad0[0x28];
    int m28;
    char pad2C[0x74 - 0x2C];
    int m74;
    char pad78[0x80 - 0x78];
    int m80;
    int m84;
};
extern FeGame* lbl_80619948;
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
#define FE_VP2(n) virtual void* v##n(int a, int b);
#define FE_VP1(n) virtual FeObj* v##n(int a);
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
    int m4;
    char pad8[0x14 - 8];
    int m14;
    char pad18[0x570 - 0x18];
    int m570;
    char pad574[0x588 - 0x574];
    int m588;
    char pad58C[4];
    int m590;
    char pad594[0x608 - 0x594];
    int m608;
};

typedef void (*FeCb)(int, void*);
typedef int (*FeCb2)();
extern "C" {
FeState* fn_800B555C();
FeObj* fn_800B7A94(UiMsgMgr* mgr, const char* name);
FeObj* fn_800B7AB8(UiMsgMgr* mgr, const char* name);
void fn_801251CC(FeObj* o, int a, int b, int c);
int fn_800A1960(FeGame* g);
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
void fn_80131F34(FeObj* o, void* self, FeCb cb, FeCb2 cb2, int b, int c, int d, int e, int f,
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



/* Member object of a widget (at +0x98 or +0xDC) with its own vptr at +0x24 of the member (the
 * widget's +0xBC / +0x100). Reach it with ((FeSub*)&w->mDC)->sN(): a fresh cast at every use. */
class FeSub {
public:
    char pad0[0x24];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int s10();
    virtual int s11();
    virtual int s12();
    virtual int s13();
    virtual int s14();
    virtual int s15();
    virtual int s16();
    virtual int s17();
    virtual int s18();
    virtual int s19();
    virtual int s20();
    virtual int s21();
    virtual int s22();
    virtual int s23();
    virtual int s24();
    virtual int s25();
    virtual int s26();
    virtual int s27();
    virtual int s28();
    virtual int s29();
    virtual int s30();
};
struct FeHolder {
    char pad0[0x98];
    FeSub m98;
    char padC0[0xDC - 0xC0];
    FeSub mDC;
};
extern "C" void fn_800D0074(FeSub* s, int v, int f);
extern "C" int fn_800C8070(void* o);

/* Roster-popup screen family (ctor fn_8044974C). */
struct FeScrRawL {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x130 - 0x40];
    int m130, m134, m138, m13C, m140, m144, m148, m14C, m150, m154, m158, m15C, m160, m164, m168, m16C, m170, m174;
    char pad178[0x240 - 0x178];
    int m240, m244, m248;
};
struct FeScr_8044974C : FeObj {
    char pad40[0x130 - 0x40];
    int m130;
    int m134;
    int m138;
    FeObj* m13C;
    FeObj* m140;
    FeObj* m144;
    FeObj* m148;
    FeHolder* m14C;
    FeHolder* m150;
    FeHolder* m154;
    FeHolder* m158;
    int m15C;
    FeObj* m160;
    FeObj* m164;
    FeObj* m168;
    int m16C;
    int m170;
    int m174;
    int m178[25];
    int m1DC[25];
    int m240;
    int m244;
    int m248;
};
extern "C" {
void fn_8044BF38(FeScr_8044974C* self, int a);
void fn_8044C128(FeScr_8044974C* self, int a);
int fn_8044C48C(FeScr_8044974C* self);
void fn_8044B5F0(FeScr_8044974C* self, int a);
void fn_8044ADA4(FeScr_8044974C* self);
void fn_8044B79C(FeScr_8044974C* self);
void fn_8044C314(FeScr_8044974C* self, int a, int b);
void fn_80122D40(FeObj* o, int v, int a, int b, int c, int d);
void fn_8044B050(FeScr_8044974C* self);
void fn_8044AD04(FeScr_8044974C* self);
void fn_8044B454(FeScr_8044974C* self, int a);
void fn_8044B6A4(FeScr_8044974C* self, FeObj* a);
}

/* Meter-bar class (ctor fn_80449034). */
struct FeMeter : FeObj {
    char pad40[0x2DC - 0x40];
    int m2DC;
    int m2E0;
    int m2E4;
    int m2E8;
    int m2EC;
    float m2F0;
    int m2F4;
    int m2F8;
    int m2FC;
    FeGame* m300;
    FeObj* m304;
    void (*m308)(int);
    int m30C;
};
struct FeMeterRaw {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x2DC - 0x40];
    int m2DC, m2E0, m2E4, m2E8, m2EC;
    float m2F0;
    int m2F4, m2F8, m2FC, m300, m304, m308, m30C;
};
extern "C" FeMeterRaw* fn_800EC150(FeMeterRaw* self, int a, int b, int c, int d, int e, int f, int g, int h);

struct Unk8007F198_C;
int fn_8007FDA8(Unk8007F198_C* s, int a, int b);
extern int lbl_8062163C;
struct FeX24 {
    char pad0[0x24];
    FeObj* m24;
};
struct FeW138 : FeObj {
    char pad40[0x138 - 0x40];
    FeObj* m138;
};
struct FeW188 : FeObj {
    char pad40[0x188 - 0x40];
    FeObj* m188;
};
struct FeX14 {
    char pad0[0x14];
    int m14;
};

/* Timer-like object with its vptr at +0x20 (ctor fn_804447F0; fn_80444850 resets the fields). */
class FeTimer {
public:
    int m0;
    int m4;
    int m8;
    unsigned char mC;
    unsigned char mD;
    short mE;
    int m10;
    int m14;
    int m18;
    int m1C;
    virtual void s1();
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
};
struct FeBits4 {
    unsigned char a;
    unsigned char b;
    short c;
    void Clear()
    {
        a = 0;
        c = 0;
        b = 0;
    }
};
struct FeTimerRaw {
    int m0;
    int m4;
    int m8;
    union {
        FeBits4 mC4;
        struct {
            unsigned char mC;
            unsigned char mD;
            short mE;
        };
    };
    int m10;
    int m14;
    int m18;
    int m1C;
    const void* m20;
};
/* Screen of unit 804439E4 (ctor fn_80445104): fields as the functions prove. */
struct FeScr2 : FeObj {
    char pad40[0x130 - 0x40];
    int m130;
    FeObj* m134;
    FeObj* m138;
    FeObj* m13C;
    int m140, m144, m148, m14C;
    short m150;
    unsigned short m152;
    int m154, m158, m15C;
    int m160;
    FeObj* m164;
    char pad168[0x170 - 0x168];
    FeObj* m170;
    char pad174[0x6EC - 0x174];
    FeObj* m6EC;
    FeObj* m6F0;
    FeObj* m6F4;
    FeObj* m6F8;
};
struct FeRec1C {
    char pad0[0xC];
    char mC[16];
    int m1C;
};
extern "C" {
int fn_800A2E6C(FeGame* g);
int fn_800A2AE8(FeGame* g);
int fn_8040B574(const char* a, const char* b);
void fn_804A763C(FeObj* o, int a);
void fn_80444FE4(FeTimer* t);
void fn_80445BB4(FeScr2* s, int a);
void fn_80445DA8(FeScr2* s);
int fn_804464B0(FeScr2* s, int a);
}

/* Screens of unit 8044F550 (BATPITCHSTATS / GAMEGRID family). */
struct FePopupW : FeObj {
    char pad40[0x314 - 0x40];
    int m314;
};
struct FeSlotObj : FeObj {
    char pad40[0x2F0 - 0x40];
    void (*m2F0)(FeObj*, int);
    char pad2F4[0x30C - 0x2F4];
    void (*m30C)();
};
struct FeScr6 : FeObj {
    char pad40[0x130 - 0x40];
    int m130;
    FeObj* m134;
    FeObj* m138;
    FeObj* m13C;
    char pad140[0x17C - 0x140];
    int m17C;
    int m180;
    int m184;
    FeObj* m188;
    FeSlotObj* m18C;
    FeObj* m190;
    FeObj* m194;
    int m198;
    char pad19C[0x10F0 - 0x19C];
    FeObj* m10F0;
};
struct FeScr6Raw {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x130 - 0x40];
    int m130;
    char pad134[0x17C - 0x134];
    int m17C, m180, m184, m188, m18C, m190, m194, m198;
    char pad19C[0x10F0 - 0x19C];
    int m10F0;
};
extern "C" {
FeScr6Raw* fn_804D1070(FeScr6Raw* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_804D10D8(void* self);
int fn_804D1278(void* self);
void fn_80123858(FeObj* o, int a, int b);
void fn_801240C0(FeObj* o);
void fn_80125BC0(FeObj* o);
void fn_80132438(FeObj* p, void* self, int a, FeCb cb1, FeCb cb2, int b, int c, int d, float f);
void fn_800ED310(void* self, int a);
void fn_8044FE0C(FeScr6* s);
void fn_80450388(FeScr6* s);
void fn_80450EF8(FeScr6* s);
void fn_80450C4C(FeScr6* s);
void fn_804509E0(FeScr6* s, int a, int b);
void fn_8045081C(FeObj* o, int a);
void fn_80451028(FeScr6* s);
void fn_80450B44(FeScr6* s, int b);
void fn_8045124C(FeScr6* s, int b);
void fn_8044F284(int a, void* b);
void fn_8044F3F8(int a, int b);
void fn_80450FCC(FeScr6* s);
void fn_80450E44(FeScr6* s, int a);
}

/* Store through a base pointer and a byte offset: keeps `addi base` and the offset in separate registers. */
inline void FeSetI(char* b, int o, int v)
{
    *(int*)(b + o) = v;
}

/* Position-picker screen of unit 80455038 (ctor fn_80455038; vtable lbl_8067B860). */
inline int FeGetI(char* b, int o)
{
    return *(int*)(b + o);
}
struct FeScr8 : FeObj {
    char pad40[0x130 - 0x40];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    FeObj* m148[10];
    FeObj* m170[10];
    int m198[10];
    FeObj* m1C0;
    int m1C4;
    int m1C8;
    int m1CC;
};
/* Second screen of the unit (fn_80458AAC..): widget array at +0x13C indexed by m14C. */
struct FeScr8b : FeObj {
    char pad40[0x13C - 0x40];
    FeObj* m13C[4];
    char pad14C_[0];
    int m14C;
    int m150;
    int m154;
    int m158;
};
struct FeScr8Raw {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x130 - 0x40];
    int m130, m134, m138, m13C, m140, m144;
    int m148[10];
    int m170[10];
    char pad198[0x1C0 - 0x198];
    int m1C0, m1C4, m1C8, m1CC, m1D0;
};
extern int lbl_80621678;
extern "C" {
void fn_80457010(void* s, int a, int b);
void fn_80456A00(void* s, int a);
void fn_80456D6C(void* s, int a);
void fn_80457B94(void* s, int a, int b, int c, int d);
void fn_804589BC(void* s);
void fn_80459FEC(void* s);
void fn_80458BA4(void* s, int a);
void fn_8045AB6C(void* s);
void fn_8045AC2C(void* s);
void fn_80125084(FeObj* o, int a);
void fn_801250D8(FeObj* o);
}

/* Calendar screen of unit 8044C508 (ctor fn_8044D424): widget with FeSub members at +0x98 and +0xDC. */
class FeSub1 {
public:
    char pad0[0x24];
    virtual int s1(int a);
    virtual int s2(int a);
    virtual int s3(int a);
    virtual int s4(int a);
    virtual int s5(int a);
    virtual int s6(int a);
    virtual int s7(int a);
    virtual int s8(int a);
    virtual int s9(int a);
    virtual int s10(int a);
    virtual int s11(int a);
    virtual int s12(int a);
    virtual int s13(int a);
    virtual int s14(int a);
    virtual int s15(int a);
    virtual int s16(int a);
    virtual int s17(int a);
    virtual int s18(int a);
    virtual int s19(int a);
    virtual int s20(int a);
};
class FeSub2 {
public:
    char pad0[0x24];
    virtual int s1(int a, int b);
    virtual int s2(int a, int b);
    virtual int s3(int a, int b);
    virtual int s4(int a, int b);
    virtual int s5(int a, int b);
    virtual int s6(int a, int b);
    virtual int s7(int a, int b);
    virtual int s8(int a, int b);
    virtual int s9(int a, int b);
    virtual int s10(int a, int b);
    virtual int s11(int a, int b);
    virtual int s12(int a, int b);
    virtual int s13(int a, int b);
    virtual int s14(int a, int b);
    virtual int s15(int a, int b);
    virtual int s16(int a, int b);
    virtual int s17(int a, int b);
    virtual int s18(int a, int b);
    virtual int s19(int a, int b);
    virtual int s20(int a, int b);
};
struct FeWidgetS : FeObj {
    char pad40[0x98 - 0x40];
    FeSub m98;
    char padC0[0xDC - 0xC0];
    FeSub mDC;
};
struct FeScr5 : FeObj {
    char pad40[0x140 - 0x40];
    FeObj* m140;
    int m144;
    char pad148[4];
    int m14C;
    char pad150[0x168 - 0x150];
    FeWidgetS* m168;
    FeWidgetS* m16C;
    FeObj* m170;
};
struct Unk8007F198_B;
extern "C" {
FeTimer* fn_80446AD4(void* self);
void fn_804454CC(void* self, int a);
void fn_8044DDFC(FeScr5* s);
void fn_8044DCAC(FeScr5* s, int a);
void fn_8044F45C(int a);
void fn_8044F4CC(void* self);
int fn_80329FA0(void* buf, ...);
void fn_800A2F9C(FeGame* g, int a);
void fn_80560A24(Unk8007F198_B* o);
void fn_80449168(FeMeter* m, int a, int b, void (*cb)(int));
}
int fn_800DD5E8(int a);
Unk8007F198_B* fn_8007F7D0(Unk8007F198_B* s, unsigned a);

/* Debug-menu item (0x54 bytes, vptr at +8, ctor fn_8032F120): +0x48 points at a live value when non-null,
 * else +0x4C holds it. A menu keeps an array of item pointers at +0 indexed by m174. */
struct FeItemData {
    int m0;
    int m4;
};
class FeItemV : public FeItemData {
public:
    virtual void s1();
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
};
struct FeItem : FeItemV {
    char padC[0x48 - 0xC];
    int* m48;
    int m4C;
    int m50;
};
inline int FeItemGet(FeItem* it)
{
    return it->m48 ? *it->m48 : it->m4C;
}
inline void FeItemSet(FeItem* it, int v)
{
    if (it->m48 != 0)
        *it->m48 = v;
    else
        it->m4C = v;
}
extern "C" {
void fn_80330BC8(void* menu, int a);
void fn_803E4A50(void* p);
FeItem* fn_8032F120(FeItem* it, const char* name, int a);
void fn_80330ACC(void* menu, FeItem* it);
}
/* Email sub-menu (ctor fn_80442594). */
struct FeMenuEmail {
    FeItem* items[93];
    int m174;
    int m178;
    char pad17C[0x1FC - 0x17C];
    int m1FC;
    int m200;
    int m204;
    int m208;
    char pad20C[0x2D8 - 0x20C];
    int m2D8;
    const void* m2DC;
    FeItem m2E0;
    FeItem m334;
};
inline int FeItemGetB(FeItem* it)
{
    if (it->m48 == 0)
        return it->m4C;
    return *it->m48;
}
/* Sim-year sub-menu (ctors fn_804436B4 / fn_804438DC): items at +0x32C and +0x394. */
struct FeMenuSim {
    FeItem* items[93];
    int m174;
    int m178;
    char pad17C[0x1FC - 0x17C];
    int m1FC;
    int m200;
    int m204;
    int m208;
    char pad20C[0x32C - 0x20C];
    FeItem m32C;
    char pad380[0x394 - 0x380];
    FeItem m394;
};
extern int lbl_80621604;
extern int lbl_80621608;
struct FeMenuEmailRaw {
    int items[93];
    int m174, m178;
    char pad17C[0x1FC - 0x17C];
    int m1FC, m200, m204, m208;
    char m210[0xC8];
    int m2D8;
    const void* m2DC;
};
extern int lbl_80622DC4;
extern int lbl_80622DC8;

/* Strings table (lbl_8061977C): fn_80090880(table, id) returns the string. */
struct Unk80090880;
const char* fn_80090880(Unk80090880* t, int id);
extern Unk80090880* lbl_8061977C;
extern int lbl_8061A328;
extern "C" {
char* fn_80403144(char* dst, const char* src);
char* fn_80403DE4(char* dst, const char* fmt, ...);
void fn_800DFF0C(char* a, char* b);
void fn_804031F8(char* out, const char* a, const char* b);
}
/* Meter/caption class (FeMeter) extra members used by the caption functions. */
struct FeMeter2 : FeMeter {
};
extern "C" {
int fn_80449358(FeMeter* s);
void fn_804493EC(FeMeter* s, char* out);
void fn_80449530(FeMeter* s);
void fn_804495C4(FeMeter* s);
void fn_80449300(FeMeter* s);
void fn_800DC50C(FeObj* o, float a, float b);
}

struct Unk8007DB74_A;
int fn_8007E060(Unk8007DB74_A* s, int a, int b, int c);
void fn_8007DD38(Unk8007DB74_A* s, int a, int b, int c, int d);
void fn_8007DEF8(Unk8007DB74_A* s, int a, int b, int c, int d);
int fn_8007E0E4(Unk8007DB74_A* s, int a, int b);

extern "C" {
int fn_800A2EFC(FeGame* g);
int fn_8044C508(FeScr_8044974C* self, int a);
}

/* Roster-popup screen of unit 80452120 (ctor fn_80452120; the other copy of the FTOPBAR screen). */
typedef FeScr_8044974C FeScr7;  /* same layout; m23C is m1DC[24] */
struct FeScr7Raw {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x130 - 0x40];
    int m130, m134, m138, m13C, m140, m144, m148;
    char pad14C[0x154 - 0x14C];
    int m154, m158, m15C, m160, m164, m168, m16C, m170;
    char pad174[0x23C - 0x174];
    int m23C, m240;
};
extern "C" {
int fn_80454D9C(FeScr7* s);
void fn_80454890(FeScr7* s, int a);
void fn_8045499C(FeScr7* s, int a);
void fn_80453F20(FeScr7* s, int a);
void fn_80453980(FeScr7* s);
void fn_80453FD4(FeScr7* s, FeObj* a);
void fn_80454AE0(FeScr7* s, int a, int b);
void fn_80454BB0(FeScr7* s, int a, int b);
void fn_804540CC(FeScr7* s);
}

struct Unk8007F198_A;
/* fn_8007F3A0 passes its r4 on to fn_805A19C8, so it really takes (s, a): callers leave a in r4. */
int fn_8007F3A0(Unk8007F198_A* s, int a);
extern "C" {
void fn_800E4234(int a, int b, char* out);
void fn_801321D4(FeObj* o, void* self, FeCb cb, int a, void* b, int c, int d, int e, const char* s1, const char* s2,
                 const char* s3, int f, int g, int h);
void fn_8055F5A0(int a);
void fn_8055EAFC(int a);
void fn_8044C644(int a, FeScr_8044974C* self);
}

class FeObjP2 : public UiBase {
public:
    FE_LO(FE_VP2) virtual FeObj* v32(const char* a, int b); FE_HI(FE_VP2)
};
struct FeScr2Raw {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x130 - 0x40];
    int m130, m134, m138, m13C, m140, m144;
    char pad148[0x14C - 0x148];
    int m14C, m150, m154, m158, m15C, m160;
};
extern int lbl_8061AC54;
extern "C" {
int fn_8032A130(int a, int b, unsigned short c);
int fn_8032A2CC(int a, unsigned short c);
void fn_80453D84(FeScr_8044974C* s, int a);
}

extern "C" {
void fn_80528920(FeObj* o, int a);
int fn_8056AF84(int a, int b, int c, int* d, int* e);
void fn_800DD44C(int* a, char* b, int c);
}

struct UiItemN {
    char pad0[0xC];
    char name[16];
};
/* Widget view for the cell-name lookups: v33 returns a named item, v70 returns the cell content. */
class FeObjQ : public UiBase {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual FeObj* v32(const char* a, int b);
    virtual UiItemN* v33(int a, int b);
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual FeObjQ* v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
};

struct FeSt8 {
    char pad0[0x4F4];
    int m4F4;
};
extern int lbl_80621648;
extern "C" {
void fn_804D1CB8(void* self);
int fn_80528918(void);
}

extern "C" int fn_8045A9AC(void* s, int a);

inline FeObj* FeGetP(char* b, int o)
{
    return *(FeObj**)(b + o);
}

extern "C" {
int fn_8044E7C4(void);
void fn_8044E304(int a, FeObj* o);
void fn_8044E398(int a, FeObj* o);
void fn_804502F4(int a, FeScr6* b);
}

extern "C" void fn_800C1FC8(void* st, int a, int idx, int v);

extern "C" {
void fn_80330F98(void* menu, int a);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_80314688(void* o, int x, int y, char* s, int a, int b);
}
extern void* lbl_8061FEDC;

/* Menu with five float tunables (fn_80442840): m474's value word holds the target object. */
struct FeMenuF {
    char pad0[0x474];
    FeItem m474;
    char pad4C8[0x4D4 - 0x4C8];
    FeTunable m4D4;
    char pad524[0x538 - 0x524];
    FeTunable m538;
    char pad588[0x59C - 0x588];
    FeTunable m59C;
    char pad5EC[0x600 - 0x5EC];
    FeTunable m600;
    char pad650[0x6CC - 0x650];
    FeTunable m6CC;
    char pad71C[0x734 - 0x71C];
    void* m734;
};
inline void* FeItemObj(FeItem* it)
{
    return (void*)it->m4C;
}
extern "C" {
void fn_805519A0(void* o, int k, float v);
void fn_805519E0(void* o, float v);
}

/* 0x28-byte sample record kept in the buffer at lbl_806215DC (fn_80442D48). */
struct FeRec28 {
    int m0;
    float m4, m8, mC, m10, m14, m18, m1C, m20;
    int m24;
};
extern "C" void fn_80442984(void);

extern "C" {
void fn_80124FA8(FeObj* o, void* s);
void fn_80125154(FeObj* o, int a);
void fn_80451C78(void);
}

extern "C" {
int fn_800A2EB4(FeGame* g);
int fn_805562B8(Unk8007F198_B* o);
int fn_800B56C4(FeState* s);
}

extern "C" void fn_80445564(FeScr2* s, int a, int b);

struct FeS0_8 {
    FeObj* m0;
    int m4;
    int m8;
};

extern int lbl_80621650[];

int fn_80075808(int a);

extern "C" {
int fn_80329E74(int* p);
int fn_8056ADD4(int a, int b, int* arr, int cnt, int v);
int fn_8057CF60(Unk8007F198_B* s, int a);
int fn_8056A580(int a, int b, int c, int d);
void fn_80450750(FeScr6* s);
}

extern "C" {
int fn_8057CE00(int a);
void fn_804513E0(FeScr6* s, FeObj* o, int v, int a);
}

int fn_8007FBDC(Unk8007F198_C* s, int a, int b);
extern "C" {
void fn_8045156C(FeScr6* s, FeObj* o, int f, int v, int a);
int fn_8032A0C0(char* buf, ...);
void fn_800DD344(char* a, char* b);
}

extern "C" {
void fn_804455B4(FeScr5* s);
void fn_804CDFE4(char* it);
void fn_804CDFF8(char* it, int a, Unk8007F198_B* b);
int fn_804CE004(char* it);
int fn_804CE038(char* it);
}

class FeObjP1 : public UiBase {
public:
    FE_LO(FE_VP1) virtual FeObj* v32(const char* a, int b); FE_HI(FE_VP1)
};
extern "C" {
int fn_800A2E90(FeGame* g);
int fn_800A3A10(FeGame* g, int a);
float fn_80574A04(int a, int b, int c);
}

int fn_80083F6C(int a);
extern "C" {
void fn_8040321C(char* out, const char* a, const char* b, char* c);
void fn_805288E4(int a, void* b);
}

struct FeRec8 {
    char pad0[8];
    int m8;
    int mC;
};
int fn_8007FB2C(Unk8007F198_C* s, int a);
int fn_8007FBC0(Unk8007F198_C* s, int a, int b);
extern "C" {
int fn_8056AB84(int a, int b, int c);
int fn_8044E08C(int a, unsigned* p);
void fn_8044E10C(FeScr5* s, int x, int y);
void fn_8044E210(FeScr5* s, int a);
}

extern "C" {
int fn_800C203C(void* st);
void fn_800C1FD8(void* st, int* a, int* b, int* c);
void fn_80445B18(FeScr2* s);
void fn_80445EF4(FeScr2* s, int a);
int fn_804461A0(FeScr2* s, int a, int b, int c);
void fn_804469DC(FeScr2* s, int a);
void fn_80444738(int a);
void fn_80444850(FeTimerRaw* t);
void fn_80445DA8(FeScr2* s);
int fn_80445D5C(int a, int idx);
int fn_80445D7C(int a, int idx);
}

extern "C" void fn_8045AF68(void* s, int a);

extern int lbl_80621644;
extern "C" {
void fn_80470404(FeObj* o, int a, int b, int c, int d, int e);
void fn_80470478(FeObj* o, int a, int b, int c, int d, int e);
void fn_80446B60(FeScr2* s, int k);
}
#endif
