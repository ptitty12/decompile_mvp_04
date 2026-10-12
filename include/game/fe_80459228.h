/*
 * Shared types for the front-end overlay units fe/tu_80459228 .. fe/tu_8046F770
 * (0x80459228..0x80471EBC; reconstructed, placeholder names, nothing here comes
 * from original headers).
 *
 * All the code is methods of menu screens derived from the widget base
 * (Unk800C7B40_Widget, include/game/tu_8012C8CC.h; base ctor fn_800EC648, vptr at
 * +0x3C, {delta, pfn} vtable entries so virtual N is at +8N). The screens' vtables are
 * .data objects, so the methods are written as extern "C" functions taking the
 * screen explicitly; a screen's own fields start at +0x130.
 */
#ifndef GAME_FE_80459228_H
#define GAME_FE_80459228_H

#include "game/overlay.h"
#include "game/tu_8001B190.h"
#include "game/tu_8012C8CC.h"

typedef Unk800C7B40_Widget FeW;

/* BEGIN-FEWV */
/* The widget base with the slot signatures that differ from FeW's: reached by a cast when a
 * call site passes another argument list. Slot N is the vtable byte offset / 8. */
struct FeWV : Unk800C7B40_Data {
    virtual ~FeWV();
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
    virtual void s44(int a);
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
    virtual void s69(int a);
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
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
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual int s94(int a, int b);
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101(int a, int b);
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual void s116();
    virtual void s117();
    virtual void s118();
    virtual void s119();
    virtual void s120();
    virtual void s121();
    virtual void s122();
    virtual void s123();
    virtual void s124();
    virtual void s125();
    virtual void s126();
    virtual void s127();
};
/* END-FEWV */

/* Callees named after another unit's (one-argument) declarations; their real arguments are
 * passed through, so they are called here by their symbol names. */
extern void* lbl_8061930C;
extern "C" {
int fn_8007B6F0__18Unk8007B2B0_Screen(void* g, int a, int b, unsigned char c);
int fn_8007B714__18Unk8007B2B0_Screen(void* g, int a, int b, unsigned char c, int d);
int fn_8007B738__18Unk8007B2B0_Screen(void* g, int a);
int fn_80077BC4(void* g, int a);
int fn_80078A38__18Unk8007B2B0_Screeni(void* g, int a);
}

Unk8001BC8C* fn_8001BC4C();

/* A list widget (class of fn_8012E7FC, tu_8012C8CC.h users): fn_80126CF4 reads
 * most of these fields. */
struct FeList : FeW {
    char pad40[0xF0];
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
    int m174;
};


struct FePair {
    int a;
    int b;
};
extern "C" void fn_80360B80(FePair* p); /* FePair::FePair(): a = 0, b = 4 */

/* Position-select screen (fn_80459228..fn_8045B074). Evidence: m13C/m140 and m144 are widget
 * pairs picked by the index m14C (fn_8045953C, fn_8045987C); m164 is a 9x10 table of pairs
 * (row stride 0x50, fn_8045A85C), m434 the list of candidates (m7D4 entries, fn_8045A638). */
struct FeScrA : FeW {
    char pad40[0xF0];
    int m130;
    void* m134;
    FeList* m138;
    FeW* m13C[2];
    FeW* m144[2];
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    void* m160;
    FePair m164[9][10];
    FePair m434[116];
    int m7D4;
};

extern "C" {
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_800ECE34(void* x);
void* fn_800C33D0();
void fn_800C3AB4(void* p, int v);
void fn_800C3BE0();
int fn_80126CF4(FeList* x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
void fn_80458B58(FeScrA* x, int a);
int fn_8045A9AC(FeScrA* x, int a);
void fn_8045AE3C(FeScrA* x, int a);
void fn_80459FEC(FeScrA* x);
int fn_80459F14(FeScrA* x);
int fn_80459F5C(FeScrA* x);
FePair fn_8045A9C0(FeScrA* x, int idx);
FePair fn_8045AAB4(FeScrA* x, int idx);
}

/* Singleton at lbl_8061A32C (0xD8 bytes, ctor fn_800B64BC), created lazily. */
struct FeMsgMgr {
    char padB8[0xB8];
    int mB8;
};
extern FeMsgMgr* lbl_8061A32C;
extern "C" FeMsgMgr* fn_800B64BC(void* p);
inline FeMsgMgr* FeGetMgr()
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    return lbl_8061A32C;
}
/* Message / popup widget looked up by name through the manager (fn_800B7AB8). */
struct FeMsg {
    char name[16];
};
struct FePopup : FeW {
    char pad40[0x30C - 0x40];
    void* m30C;
};
struct FeGlobal80619948 {
    char pad0[0x58];
    int m58;
    char pad5C[0x74 - 0x5C];
    int m74;
    char pad78[0x80 - 0x78];
    int m80;
    char pad84[0x8C - 0x84];
    int m8C;
    int m90;
    char pad94[0xA4 - 0x94];
    int mA4;
};
extern FeGlobal80619948* lbl_80619948;
extern "C" {
void fn_8035682C(FeMsg* m);
char* fn_8040B830(char* dst, const char* src, unsigned n);
void fn_800B7B4C(FeMsgMgr* mgr, FeMsg* m, void* ctx);
FePopup* fn_800B7AB8(FeMsgMgr* mgr, const char* name);
void fn_8054899C(int v);
}
extern "C" {
void fn_800B7ADC(FeMsgMgr* m, void* s);
void fn_80125084(void* w, int a);
void fn_80125100(void* w);
void fn_80125180(void* w, int a, int b);
void fn_801251CC(void* w, int a, int b, int c);
}

/* The sign word at +0x24 of a widget (flag bits, see Unk800C7B40_Data). */
static inline int FeW24(void* w)
{
    return *(int*)((char*)w + 0x24);
}

/* Menu screen (ctor fn_8045B074, vtable lbl_8067B310): a list (m1EC) navigated through the
 * widget m1B8; m138/m13C/m140 are counts of the three id tables at m144/m1A8/m1B0
 * (fn_8045D420 maps a flat index onto them). */
struct FeScrB : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144[25];
    int m1A8[2];
    int m1B0[2];
    FeW* m1B8;
    FeW* m1BC;
    FeW* m1C0;
    FeW* m1C4;
    FeW* m1C8;
    FeW* m1CC;
    FeW* m1D0;
    FeW* m1D4;
    FeW* m1D8;
    FeW* m1DC;
    FeW* m1E0;
    FeW* m1E4;
    FeW* m1E8;
    FeList* m1EC;
    void* m1F0;
    int m1F4[3];
};
extern const char lbl_8067B310[];
extern "C" {
FeScrB* fn_8045B074(FeScrB* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_8045D338(FeScrB* x);
void fn_8045C8C0(FeScrB* x);
void fn_8045C79C(FeScrB* x);
int fn_8045D420(FeScrB* x, int idx);
void fn_8045D5B0(FeScrB* x, int a);
void fn_8045D71C(FeScrB* x, int a, int b);
}

/* Second base object at +0xDC of the list/spinner controls: vptr at +0x24 of that base. */
struct FeSubData {
    char pad0[0x24];
};
struct FeSub : FeSubData {
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
    virtual void s6(int a);
};
struct FeState {
    char pad0[0x570];
    int m570;
    char pad574[8];
    int m57C;
    char pad580[0x638 - 0x580];
    int m638;
};
extern "C" FeState* fn_800B555C();
extern "C" void fn_800ED254(void* x);
extern "C" void fn_800ED310(void* x, int a);

/* Menu screen (ctor fn_8045D920, vtable lbl_8067B068). m144/m148 are the two focus targets and
 * m14C the focused widget. */
struct FeScrD : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    FeW* m144;
    FeW* m148;
    FeW* m14C;
    FeW* m150;
    FeW* m154;
    FeW* m158;
    FeW* m15C;
    FeW* m160;
    int m164;
    int m168;
    int m16C;
    int m170;
    FeW* m174;
    char pad178[0x3468 - 0x178];
    int m3468[1];
    char pad346C[0x67A8 - 0x346C];
    FeW* m67A8;
};
extern "C" {
void fn_804613EC(FeScrD* x, FeW* w);
void fn_80460750(FeScrD* x);
void fn_8045FBF8(FeScrD* x);
int fn_80461218(FeScrD* x, int i);
void fn_80461228(FeScrD* x, int v);
void fn_804615DC(FeScrD* x);
void fn_804617C8(FeScrD* x);
void fn_80461910(FeScrD* x);
void fn_80461A14(FeScrD* x);
void fn_80461B18(FeScrD* x);
void fn_80461BF8(FeScrD* x);
void fn_80461D0C(FeScrD* x);
void fn_80461DB8(FeScrD* x);
void fn_80461E5C(FeScrD* x);
}

/* Menu screen (ctor fn_804625B4, vtable lbl_8067ADC0). m13C is the focused widget, one of
 * the two targets m134/m138; m14C the shared list. */
struct FeScrE : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
    FeW* m138;
    FeW* m13C;
    FeW* m140;
    FeW* m144;
    int m148;
    FeW* m14C;
    int m150;
    int m154;
    char pad158[0x2C8 - 0x158];
    int m2C8;
};
extern "C" {
int fn_800C8070(void* x);
int fn_800B548C(int v);
void fn_80463E40(FeScrE* x);
void fn_80463D60(FeScrE* x, FeW* w);
void fn_80463044(FeScrE* x);
int fn_80463CE4(FeScrE* x);
void fn_804637FC(FeScrE* x);
}

/* Menu screen (ctor fn_80464030, vtable lbl_8067AB18). */
struct FeScrF : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    FeW* m138;
    int m13C;
    int m140;
    char* m144;
};
extern const char lbl_805F4F0C[];
extern const char lbl_805F5284[];
extern const char lbl_805F528C[];
extern const char lbl_805F522C[];
extern const char lbl_805F5894[];
extern int lbl_8061A328;
extern "C" {
void fn_800ECAA4(void* x);
int fn_80360ED8(char* p);
void fn_80548EC0(char* p);
void fn_80548E68(char* p, int v);
void fn_8049AB94(FePopup* p);
void fn_8049ABD4(FePopup* p);
void fn_8046468C(FePopup* p);
void fn_80464AF0(void* x);
void fn_80464B60(void* x);
void fn_80464C94();
void fn_80464D68(void* x);
void fn_8046488C(int a, void* x);
void fn_80464A0C(int a, void* x);
void fn_80449168(FePopup* p, int a, void* x, void (*cb)(void*));
void fn_80131F34(FeW* w, void* self, void (*cb)(int, void*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
}

/* Menu screens with the 804D2AC0 base ctor (vtables lbl_80679BF0, lbl_80679920), the
 * 0x130-field screen of lbl_80679678 and the screen of lbl_80681C88. */
struct FeScrG : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[8];
    int m13C;
};
struct FeScrH : FeW {
    char pad40[0xF0];
    int m130;
};
struct FeScrI : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[4];
    FeW* m138;
    char pad13C[0x14C - 0x13C];
    FeW* m14C;
    char pad150[8];
    FeW* m158;
    char pad15C[0x16C - 0x15C];
    int m16C;
    char pad170[0x17C - 0x170];
    FeW* m17C;
    char pad180[0x208 - 0x180];
    int m208;
    int m20C;
    int m210;
};
extern const char lbl_8062167C[];
extern const char lbl_80621714[];
extern const char lbl_80679BF0[];
extern const char lbl_80679920[];
extern const char lbl_80679678[];
extern const char lbl_80681C88[];
extern const char lbl_8067AB18[];
extern const char lbl_805F4F84[];
extern const char lbl_805F3CA8[];
extern int lbl_8061A308;
extern "C" {
void* fn_804D2AC0(void* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, const char* l);
void fn_804D3164(void* x);
void fn_804D2DC0(void* x, int v);
int fn_804D32A0(void* x);
void fn_800ECF18(void* x);
void* fn_800B7A94(FeMsgMgr* m, const char* name);
void fn_80124FA8(void* w, void* x);
void fn_801250D8(void* w);
void fn_800A2030(FeGlobal80619948* g, int v);
}

/* Screen of lbl_80679128 (ctor fn_8046F770): m134 is the widget its nav buttons forward to. */
struct FeScrK : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
};
/* Message dialog screen (vtable lbl_80678D58, ctor fn_8046FED8): m314 is the dialog kind, m30C
 * the confirm callback, m324/m334/m338 its arguments. */
struct FeScrL : FeW {
    char pad40[0x29C];
    int m2DC;
    int m2E0;
    int m2E4;
    int m2E8;
    int m2EC;
    int m2F0;
    int m2F4;
    int m2F8;
    int m2FC;
    int m300;
    char pad304[8];
    void (*m30C)(int a, int b);
    void (*m310)();
    int m314;
    int m318;
    int m31C;
    int m320;
    int m324;
    int m328;
    float m32C;
    int m330;
    int m334;
    int m338;
    int m33C;
    int m340;
    int m344;
    int m348;
    int m34C;
    int m350;
    int m354;
    int m358;
};
struct FeEvt {
    char pad0[0xC];
    char name[0x10];
    int m1C;
};
struct FeObj138 {
    char pad0[0x138];
    int m138;
};
extern const char lbl_80679128[];
extern const char lbl_805F5CB8[];
extern const char lbl_805F4ED4[];
extern const char lbl_805F5D84[];
extern const char lbl_80678D58[];
extern float lbl_805F5BEC;
void fn_800E49A4();
extern "C" {
void fn_800A29C4(FeGlobal80619948* g, int v);
void fn_800A2948(FeGlobal80619948* g, int v);
int fn_800A2AE8(FeGlobal80619948* g);
int fn_800C2208(void* p);
void fn_80470E30(FeScrL* x, int a, int b, int c, int d);
void fn_8047091C(FeScrL* x);
void fn_80470C08(FeScrL* x, int c);
void fn_80471D8C(FeScrL* x);
void fn_8047083C(FeScrL* x);
void fn_800A2B10(FeGlobal80619948* g);
int fn_8040B574(const char* a, const char* b);
void fn_800EAC30(void* x);
void fn_800EC150(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
}

/* Menu screen of lbl_806793D0 (ctor fn_8046C63C): m144 is its message dialog (FeScrL), m150 a name
 * buffer written by fn_8046F3A8. */
struct FeScrJ : FeW {
    char pad40[0xF0];
    int m130;
    char pad134[4];
    FeW* m138;
    char pad13C[4];
    int m140;
    FeScrL* m144;
    int m148;
    int m14C;
    char m150[16];
};
struct FeObj144 {
    char pad0[0x144];
    int m144;
};
struct Unk8007F198_D;
struct FeRet1E0 {
    char pad0[0x1E0];
    int m1E0;
};
FeRet1E0* fn_8007FE04(Unk8007F198_D* g);
extern int lbl_8061A48C;
extern const char lbl_805F5AA4[];
extern const char lbl_805F5240[];
extern const char lbl_805F5B68[];
extern const char lbl_805F5B78[];
extern "C" {
void fn_80470710(FeScrL* x, int a);
void fn_804705F0(FeScrL* x, int a, int b, int c);
void fn_804704EC(FeScrL* x, int a, int b, int c, int d);
void fn_80470558(FeScrL* x, int a, int b, int c, int d);
void fn_8046DA10(FeScrJ* x);
void fn_8046EB7C(FeScrJ* x);
void fn_8046DC84(FeScrJ* x);
void fn_8046D9E8(FeScrJ* x);
void fn_8046F000(FeScrJ* x);
void fn_8046F3A8(FeScrJ* x, const char* s);
void fn_8049A760(FeScrL* x);
void fn_8049A7E4(FeScrL* x);
void fn_800E25E0(void* w, int a);
}

extern const char lbl_805F59C4[];
extern const char lbl_805F5A38[];
struct FeStr1 {
    char c0;
};
extern FeStr1 lbl_805F36A0;
extern const char lbl_806793D0[];
extern "C" {
FeW* fn_800C805C(FeW* w);
void fn_8046BBC0(FeScrI* x, int a);
int fn_8046C5C0(FeScrI* x);
void fn_800C21D0(void* p);
int fn_800C2248(void* p);
void fn_800C2210(void* p);
}

#endif
