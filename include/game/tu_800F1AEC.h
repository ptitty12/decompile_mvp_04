/*
 * Shared types for the UI/menu game code 0x800F1AEC-0x8010E0F4 (units
 * game/tu_800F1AEC .. game/tu_8010A0A4; placeholder names, no strings name them).
 *
 * UiBase is the data written by the common base constructor fn_800EC648 /
 * fn_804D2AC0 (0x00-0x3B); UiObj adds the vtable pointer at +0x3C. Retail's
 * vtable entries are {delta, pfn} pairs, virtual N at +8N, so vslot N is the
 * call through `lha r,8N(vtbl); lwz r,8N+4(vtbl)`. The slots below are the ones
 * seen in this range; placeholders (void, no args) until a call site shows
 * the signature. The classes never define a virtual, so no vtable is emitted
 * here (retail's vtables are the lbl_80xxxxxx data objects).
 */
#ifndef GAME_TU_800F1AEC_H
#define GAME_TU_800F1AEC_H

struct UiObj;
struct UiItem {
    char pad0[0xC];
    char name[16];
};

struct UiBase {
    char pad0[0x24];
    int m24;
    char pad28[0x3C - 0x28];
};

class UiObj : public UiBase {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14(int a);
    virtual void v15();
    virtual void v16(int a);
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
    virtual void v28(char* s);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual UiItem* v33(int a, int b);
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38(int a);
    virtual void v39();
    virtual void v40(int a);
    virtual void v41(int a);
    virtual void v42();
    virtual void v43(int a, int b, int c, int d);
    virtual void v44(int a, int b, int c, int d);
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
    virtual int v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67(int a, int b);
    virtual void v68();
    virtual void v69();
    virtual UiObj* v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79(int a, int b);
    virtual void v80(int a);
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
    virtual void v91(int a, int b, int c);
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

/* Second virtual-call class: objects sharing UiBase whose slot signatures differ
 * from UiObj (slots 54-57 take the player index). */
class UiObjB : public UiBase {
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
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38(int a);
    virtual void v39();
    virtual void v40(int a);
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
    virtual void v54(int a);
    virtual void v55(int a);
    virtual void v56(int a);
    virtual void v57(int a);
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
    virtual void v70();
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

/* Views of a screen object (derived from UiObj, vptr at +0x3C): each names
 * only the field a function reads. Evidence: the functions using it. */
struct UiScr134 : UiObj {
    char pad40[0x134 - 0x40];
    UiObj* m134;
};

struct UiScr13C : UiObj {
    char pad40[0x13C - 0x40];
    UiObj* m13C;
    int m140;
    int m144;
    int m148;
};

struct UiScr140 : UiObj {
    char pad40[0x140 - 0x40];
    UiObj* m140;
};

/* A second object kind whose vptr sits at +0xC (menu-tab widget; also held in the slot
 * array at screen +0x244; fn_80101BC8, fn_80100BA4). Virtuals 1.. are placeholders. */
/* Per-player table object (reached through fn_8011AA24(0)->+0x700->+0x3C4, and held by
 * the menu-tab widget at +0x10): four two-entry int arrays. Evidence: fn_801006D4, fn_80100BA4. */
struct Ui3C4 {
    char pad0[0x38];
    int a38[2];
    int a40[2];
    int a48[2];
    int a50[2];
};
struct UiGet2AC;
struct Ui8011AA24;
struct UiWBase {
    UiGet2AC* m0;
    UiObjB* m4;
    UiObj* m8;
};
class UiW : public UiWBase {
public:
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6(Ui8011AA24* a, int b);
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
};
/* Data of the menu-tab widget after its vptr (+0x10, +0x14). */
class UiWM : public UiW {
public:
    Ui3C4* m10;
    int m14;
};

/* Screen with a widget slot array at +0x244 (index at +0x26C) and a button
 * object at +0x2A8. Evidence: fn_80101BC8, fn_80101CA0. */
struct UiScr2A8 : UiObj {
    char pad40[0x244 - 0x40];
    UiW* m244[10];
    int m26C;
    char pad270[0x2A8 - 0x270];
    UiObjB* m2A8;
};

struct UiV_134 : UiObj {
    char pad40[0x134 - 0x40];
    UiObj* m134;
};

struct UiV_138 : UiObj {
    char pad40[0x138 - 0x40];
    UiObj* m138;
};

struct UiV_1E0 : UiObj {
    char pad40[0x1E0 - 0x40];
    UiObj* m1E0;
};

struct UiV_1E4 : UiObj {
    char pad40[0x1E4 - 0x40];
    UiObj* m1E4;
};

struct UiV_30 {
    char pad0[0x30 - 0x0];
    UiObj* m30;
};

struct UiV_28i {
    char pad0[0x28 - 0x0];
    int m28;
};

struct UiV_2Ci {
    char pad0[0x2C - 0x0];
    int m2C;
};

struct UiV_20i {
    char pad0[0x20 - 0x0];
    int m20;
};

struct UiV_24i {
    char pad0[0x24 - 0x0];
    int m24;
};

struct UiV_13C : UiObj {
    char pad40[0x13C - 0x40];
    UiObj* m13C;
};

struct UiV_134i : UiObj {
    char pad40[0x134 - 0x40];
    int m134;
};

struct UiV_4 {
    char pad0[0x4 - 0x0];
    UiObj* m4;
};

struct UiV_2B4 : UiObj {
    char pad40[0x2B4 - 0x40];
    UiObj* m2B4;
};

struct UiV_2B4b : UiObj {
    char pad40[0x2B4 - 0x40];
    UiObjB* m2B4;
};

struct UiV_1E0b : UiObj {
    char pad40[0x1E0 - 0x40];
    UiObjB* m1E0;
};

struct UiV_1E4b : UiObj {
    char pad40[0x1E4 - 0x40];
    UiObjB* m1E4;
};

struct UiV_30b {
    char pad0[0x30 - 0x0];
    UiObjB* m30;
};

struct UiV_4b {
    char pad0[0x4 - 0x0];
    UiObjB* m4;
};

struct UiV_0i_4i {
    int m0;
    int m4;
};

struct UiV_140i : UiObj {
    char pad40[0x140 - 0x40];
    int m140;
};

struct UiV_150i : UiObj {
    char pad40[0x150 - 0x40];
    int m150;
};

struct UiV_17Ci : UiObj {
    char pad40[0x17C - 0x40];
    int m17C;
};

struct UiV_8_2Ci {
    char pad0[0x8 - 0x0];
    UiObj* m8;
    char padC[0x2C - 0xC];
    int m2C;
};

struct UiV_148i_14Ci_158i_15Ci_160i_164i : UiObj {
    char pad40[0x148 - 0x40];
    int m148;
    int m14C;
    char pad150[0x158 - 0x150];
    int m158;
    int m15C;
    int m160;
    int m164;
};

struct UiV_134f_198i : UiObj {
    char pad40[0x134 - 0x40];
    float m134;
    char pad138[0x198 - 0x138];
    int m198;
};

struct UiV_8 {
    char pad0[0x8 - 0x0];
    UiObj* m8;
};

struct UiV_1C4i : UiObj {
    char pad40[0x1C4 - 0x40];
    int m1C4;
};

struct UiV_1DCi : UiObj {
    char pad40[0x1DC - 0x40];
    int m1DC;
};

struct UiV_13C_140i : UiObj {
    char pad40[0x13C - 0x40];
    UiObj* m13C;
    int m140;
};

struct UiV_13Ci : UiObj {
    char pad40[0x13C - 0x40];
    int m13C;
};

struct UiV_0 {
    UiObj* m0;
};

struct UiV_174i_178i : UiObj {
    char pad40[0x174 - 0x40];
    int m174;
    int m178;
};

struct UiV_140i_148_14C : UiObj {
    char pad40[0x140 - 0x40];
    int m140;
    char pad144[0x148 - 0x144];
    UiObj* m148;
    UiObj* m14C;
};

struct UiV_158i_15Ci_160i_164i_168i : UiObj {
    char pad40[0x158 - 0x40];
    int m158;
    int m15C;
    int m160;
    int m164;
    int m168;
};

struct UiV_170i_174i_178i_17Ci_180i : UiObj {
    char pad40[0x170 - 0x40];
    int m170;
    int m174;
    int m178;
    int m17C;
    int m180;
};

struct UiV_184i_188i_18Ci_190i_194i : UiObj {
    char pad40[0x184 - 0x40];
    int m184;
    int m188;
    int m18C;
    int m190;
    int m194;
};

struct UiV_20i_24i_28i_2Ci {
    char pad0[0x20 - 0x0];
    int m20;
    int m24;
    int m28;
    int m2C;
};


/* fn_800B555C(): global input/menu state; +0x570 is the current player/slot index
 * compared by the button handlers. */
struct Ui800B555C {
    char pad0[0x570];
    int m570;
};
Ui800B555C* fn_800B555C();

int fn_800F5AE0(UiObj* self, int a);
int fn_800F7C34(UiScr13C* self, int a);
int fn_800F9B70(UiObj* self, int a);
int fn_801060EC(UiObj* self, int a);

/* Screen object seen as plain data (before its vptr is a live class): the
 * constructors store the vtable address (retail's lbl_xxx data object) by
 * hand. 0x00-0x3B belong to the base constructor fn_800EC648. */
struct UiScrRaw {
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
    int m174;
    int m178;
    int m17C;
    int m180;
    int m184;
    int m188;
    int m18C;
    int m190;
    int m194;
    int m198;
    int m19C;
    int m1A0;
    int m1A4;
    int m1A8;
    int m1AC;
    int m1B0;
};
void fn_800EC648(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h);

/* lbl_806192E0: pointer to the game state; +4 -> world with +0x10 and +0x14
 * (array of 0xE64-byte entries). Evidence: fn_800F1D98, fn_800F2C84. */
struct Ui806192E0_C {
    char pad0[0x1C];
    int m1C;
};
struct Ui806192E0_B {
    char pad0[0x10];
    Ui806192E0_C* m10;
    char* m14;
    char pad18[0x20 - 0x18];
    int m20;
};

struct Ui806192E0 {
    char pad0[4];
    Ui806192E0_B* m4;
};
extern Ui806192E0* lbl_806192E0;
void fn_8006C698(Ui806192E0_B* b);

/* Small hand-written views. */
struct UiGet2AC {
    char pad0[0x2AC];
    int m2AC;
};
struct UiPtr0 {
    UiGet2AC* m0;
};
/* Object with a bitfield at +0x24 (bit 0x01000000), written from the owner's +0x30
 * (fn_800FF20C). */
struct UiFlagged {
    char pad0[0x24];
    unsigned pad24 : 7;
    unsigned bit7 : 1;
    unsigned rest24 : 24;
};
struct UiFlagOwner {
    char pad0[8];
    UiFlagged* m8;
    char padC[0x30 - 0xC];
    int m30;
};
/* Small widget seen as plain data: three words, then the vptr at +0xC. */
struct UiWRaw {
    int m0;
    int m4;
    int m8;
    const void* mC;
    UiWRaw();
};
struct Ui700 {
    char pad0[0x3C4];
    Ui3C4* m3C4;
};
struct Ui8011AA24 {
    char pad0[0x700];
    Ui700* m700;
    char m704[0x788 - 0x704];
    int m788;
};
Ui8011AA24* fn_8011AA24(int a);
struct Ui800C33D0 {
    char pad0[0x5DA4];
    int m5DA4;
};
Ui800C33D0* fn_800C33D0();
/* lbl_8068B618 -> +8 -> +0x564 -> +0x14 (fn_80105AB8). */
struct Ui8068B618_C {
    char pad0[0x14];
    int m14;
};
struct Ui8068B618_B {
    char pad0[0x564];
    Ui8068B618_C* m564;
};
struct Ui8068B618_A {
    char pad0[8];
    Ui8068B618_B* m8;
    void* mC;
};
struct Ui801A6D84 {
    char pad0[0x3D90];
    int m3D90;
};
Ui801A6D84* fn_801A6D84(void* a, int b);
void fn_8011C15C(UiObj* self);
extern Ui8068B618_A* lbl_8068B618;

/* Derived widget: base UiWRaw (ctor fn_800FEC00) then +0x30. */
struct UiW2 : UiWRaw {
    char pad10[0x30 - 0x10];
    int m30;
    UiW2();
};
void fn_8011BFAC(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h);

/* lbl_8061B8C0: global object, +0x24 cleared by fn_800FCFAC. */
struct Ui8061B8C0 {
    char pad0[0x24];
    int m24;
};
extern Ui8061B8C0* lbl_8061B8C0;

/* Message manager singleton (lbl_8061A32C), 0xD8 bytes, ctor fn_800B64BC; created lazily. */
void* operator new(unsigned int size, int heap);
struct UiMsg {
    char name[16];
};
struct UiMsgMgr {
    char pad0[0xD8];
    UiMsgMgr();
};
extern UiMsgMgr* lbl_8061A32C;
inline UiMsgMgr* UiGetMsgMgr()
{
    if (lbl_8061A32C == 0)
        lbl_8061A32C = new (0) UiMsgMgr;
    return lbl_8061A32C;
}
void fn_8035682C(UiMsg* m);
void fn_800B7B4C(UiMsgMgr* mgr, UiMsg* m, UiObj* ctx);
UiObj* fn_800B7AB8(UiMsgMgr* mgr, const char* name);

/* Ring of byte indices at screen +0x168 (fn_800F26A0). */
struct UiRing {
    unsigned char* m0;
    unsigned int m4;
    int m8;
    unsigned int mC;
};
struct UiEntry34 {
    int m0;
    char pad4[0x34 - 4];
};
struct UiScr168 : UiObj {
    char pad40[0x168 - 0x40];
    unsigned char* m168;
    char pad16C[0x3E8 - 0x16C];
    UiEntry34 entries[1];
};

/* Screen with five-entry table at +0x13C (fn_800F5640). */
struct UiScr5640 {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x130 - 0x40];
    int m130;
    int m134;
    int m138;
    int m13C[5];
};
void fn_800EC648(UiScr5640* self, int a, int b, int c, int d, int e, int f, int g, int h);

/* Screen torn down by fn_800F3FCC: three embedded members at +0x37C/+0x4F0/+0x678
 * (destructed with in-charge 2) and an embedded UiObj-like part at +0x1CC. */
struct UiSub1CC {
    char pad0[0x3C];
    const void* m3C;
};
struct UiScr3FCC {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x184 - 0x40];
    const void* m184;
    char pad188[0x1C8 - 0x188];
    const void* m1C8;
    UiSub1CC m1CC;
    char pad20C[0x37C - 0x20C];
    char m37C[0x4F0 - 0x37C];
    char m4F0[0x678 - 0x4F0];
    char m678[0x7F0 - 0x678];
    const void* m7F0;
};
void fn_804D3DD0(char* p, int a);
void fn_804D61F4(char* p, int a);
void fn_80360F48(char* p, int a);
void fn_800EC5F4(UiSub1CC* p, int a);
void fn_8035686C(UiScr3FCC* self, int a);


struct Ui800ABF3C {
    char pad0[0x18];
    int m18;
};
Ui800ABF3C* fn_800ABF3C(int a, Ui8011AA24* b);
void fn_800AB5C8(int a);
void fn_800AEC80();
int fn_800B1FCC();
void fn_800C80C0(UiObj* o, int a);
void fn_80131F34(UiObj* o, UiObj* self, void (*cb)(int, UiObj*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
int fn_80403DE4(char* buf, const char* fmt, ...);
int fn_80090880(int a, int b);
UiObj* fn_800C8040();

struct Ui8010B1E0 {
    char pad0[0x704];
    int m704;
};
int fn_8025416C(char* p, int a);
void fn_800DE274(short* p, int a, int b);
int fn_800E5F38();
int fn_800E5E4C();
void fn_80097288(int a, int b);
extern int lbl_8061977C;
int fn_8010A7A0(int a);

int fn_804089B4(char* buf, const char* fmt, ...);
int fn_8011B6F8(int a, int b);
float fn_8011B81C(int a, int b, int c);
void fn_80119F48(char* buf, float f);
float fn_8011B954(int a, int b);
void fn_80119FF0(char* buf, float f);

/* Screen constructed by fn_8010A70C (fields up to +0x244). */
struct UiScrA70C {
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
    char pad16C[0x234 - 0x16C];
    int m234;
    char m238[12];
};
void fn_800EC648(UiScrA70C* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_803FFC58(char* p, int v, int n);

void fn_800F1970(UiObj* self);
void fn_804D2AC0(void* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, const void* l);
void fn_800ECF18(UiObj* self);
void fn_80107C94(UiObj* self);
void fn_800ED254(UiObj* self);
void fn_800EB7D4(UiObj* self);
void fn_800C3BE0();
int fn_800F9290(UiObj* self, int a);
char* fn_8040B830(char* dst, const char* src, unsigned n);
void fn_80100744(void* self);
void fn_800ED310(UiObj* self);
void fn_80108958(void* self, int a);
void fn_801094AC(void* self, int a);
void fn_80109E0C(void* self, int a);
void fn_801A39B8(void* a, int b);
void fn_801A3A54(void* a, int b);
void fn_8035686C(UiScrRaw* self);
void fn_800ECAA4(UiObj* self);
void fn_800EBEA8(UiObj* self);
void fn_800F4A30(UiObj* self);
void fn_80103920(UiObj* self);
int fn_80101254(void* self);
void fn_801018F4(UiScr2A8* self);
void fn_8017E264(Ui700* a);
void fn_800EB968(void* a, int b, int c);
void fn_800F7EBC(UiObj* a);
void fn_80105CA8(int a);
void fn_800EC84C();
int fn_8017E030(Ui700* a, int b, int c);
int fn_801059E4();
void fn_80105CA4(int a);
void fn_800DC50C(int a, float b, float c);
int fn_800ED2B0(int a, const char* s);
int fn_800CFB38();
int fn_800EC8B8(UiObj* self);

void fn_800AB6B8(int a, int b);
void fn_8035686C(UiScrRaw* self, int a);
void fn_802D7ACC();
void fn_8037893C(char* a, int b, int c, int d, int e);
void fn_801A3704(Ui8011AA24* a, int b);
UiObj* fn_804D2D50(UiObj* self);
UiObj* fn_804D2CE0(UiObj* self);
void fn_80096830(char* e, int v);
void fn_804D3328(UiObj* self, int a);
void fn_800F50B8(int a, UiV_17Ci* b);
void fn_80131F34(UiObj* o, UiObj* self, void (*cb)(int, UiV_17Ci*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
void fn_804D3164(UiObj* self);
void fn_804D2DC0(UiObj* self, int a);
void fn_804D3CA8(UiObj* self, int a);
void fn_800F289C(UiObj* self);
extern int lbl_80619D10;

void fn_800F817C(int a, UiObj* b);
void fn_8010B658(int unused, UiObj* list, int a);
void fn_800ED310(UiObj* self, int a);
void fn_80100A98(UiWM* self);
UiObj* fn_800C8054(int a);
UiObj* fn_800C8038(int a);
UiObj* fn_800C8044(int a);
void fn_80100A08(UiV_30b* self, int a);
void fn_80100668(UiV_2Ci* self, int a);

#endif
