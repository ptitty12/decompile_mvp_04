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
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14(int a);
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
    virtual UiItem* v33(int a, int b);
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
    virtual UiObj* v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
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

/* A second object kind whose vptr sits at +0xC (widget held in the slot array
 * at screen +0x244; fn_80101BC8). Virtuals 1.. are placeholders. */
struct UiWBase {
    char pad0[0xC];
};
class UiW : public UiWBase {
public:
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
};

/* Screen with a widget slot array at +0x244 (index at +0x26C) and a button
 * object at +0x2A8. Evidence: fn_80101BC8, fn_80101CA0. */
struct UiScr2A8 : UiObj {
    char pad40[0x244 - 0x40];
    UiW* m244[10];
    int m26C;
    char pad270[0x2A8 - 0x270];
    UiObj* m2A8;
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
};
struct Ui806192E0 {
    char pad0[4];
    Ui806192E0_B* m4;
};
extern Ui806192E0* lbl_806192E0;
void fn_8006C698(Ui806192E0_B* b);

void fn_800F1970(UiObj* self);
void fn_804D2AC0(void* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, const void* l);
void fn_800ECF18(UiObj* self);
void fn_80107C94(UiObj* self);
void fn_800ED254(UiObj* self);
void fn_800EB7D4(UiObj* self);
void fn_800C33D0();
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
void* fn_8011AA24(int a);
void fn_8035686C(UiScrRaw* self);
void fn_800ECAA4(UiObj* self);
void fn_800EBEA8(UiObj* self);
void fn_800F4A30(UiObj* self);
void fn_80103920(UiObj* self);
int fn_80101254();

#endif
