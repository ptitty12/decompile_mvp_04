#ifndef GAME_TU_800EBF2C_H
#define GAME_TU_800EBF2C_H

class UiS;
struct UiLabel {
    char pad0[0xC];
    char name[16];
};

#include "game/tu_8001B190.h"
#include "game/tu_8007A4DC.h"

/*
 * Declarations for game/tu_800EBF2C.cpp (reconstructed; placeholders only).
 */

struct Unk800EC82C_N {
    char m0[0x24];
    Unk800EC82C_N* m24;
};
struct Unk800EC82C_T {
    char m0[0x4C];
    Unk800EC82C_N* m4C;
};
struct Unk800EC624_T {
    char m0[0x13C];
    int m13C;
    int m140;
    int m144;
};
struct Unk800EDB78_T {
    char m0[0x138];
    int m138;
};
extern "C" extern "C" void fn_800ECE34(UiS* t);
extern "C" void fn_800ED254(UiS* t);
char* fn_8040B61C(char* dst, const char* src);
struct Ui800B555C;
Ui800B555C* fn_800B555C();


/*
 * Screen object with its vptr at +0x3C (virtual N at +8N, {delta, pfn}
 * entries). UiS0 is the data below the vptr; retail's vtables are the lbl_
 * data objects, so no vtable is emitted here.
 * Evidence: fn_800EC84C/EC7C0/ECAA4 (m4/m8/m24/m40/m44 links), fn_800ED534.
 */
class UiS;
struct UiN {
    int m0;
    char name[0x20];
    UiN* m24;
};
struct UiS0 {
    char pad0[4];
    UiS* m4;
    UiS* m8;
    char padC[0x1C - 0xC];
    int m1C;
    int m20;
    int m24;
    char pad28[0x2A - 0x28];
    short m2A;
    short m2C;
    short m2E;
    char pad30[0x3C - 0x30];
};
class UiV : public UiS0 {
public:
    virtual ~UiV();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(int a); virtual void v9(int a); virtual void v10(int a);
    virtual void v11(); virtual void v12(int a); virtual void v13(int a); virtual void v14(int a); virtual void v15(); virtual void v16(int a);
    virtual void v17();
    virtual void v18(int a);
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(char* s); virtual void v29(int a);
    virtual UiS* v30(const char* s, int a);
    virtual int v31();
    virtual UiS* v32(const char* s, int a);
    virtual UiLabel* v33(int a, int b); virtual int v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52();
    virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(int a); virtual void v68(int a, int b); virtual void v69(int a); virtual UiS* v70();
    virtual void v71(); virtual void v72(); virtual void v73(int a); virtual void v74(); virtual int v75(); virtual void v76();
    virtual int v77();
    virtual void v78();
    virtual void v79(); virtual void v80(int a); virtual int v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(int a); virtual void v86(); virtual void v87(); virtual void v88();
    virtual void v89(int a);
    virtual int v90();
    virtual int v91(); virtual void v92(); virtual void v93();
    virtual void v94(int a);
    virtual void v95(); virtual void v96();
    virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102();
    virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108();
    virtual void v109(); virtual void v110(); virtual void v111(); virtual void v112(int a); virtual void v113(int a); virtual void v114(int a);
    virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119(); virtual void v120();
    virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126();
    virtual void v127(); virtual void v128();
};
/* Variant of UiV for call sites that pass other arguments to slots 86/89. */
class UiVB : public UiS0 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
    virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
    virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72();
    virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78();
    virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85();
    virtual void v86(int a, int b);
    virtual void v87();
    virtual int v88(int a);
    virtual void v89();
};
struct UiSubBase {
    char pad0[0x24];
};
/* Sub-object at +0xDC of some screens (its vptr is at +0x100). */
class UiSub : public UiSubBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(int a);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14();
    virtual void v15();
};
/* Variant of UiV: slot 51 takes two arguments. */
class UiVD : public UiS0 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50();
    virtual void v51(int a, int b);
};
/* Variant of UiV: slot 68 takes one argument, slot 79 two. */
class UiVF : public UiS0 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13();
    virtual void v14(int a);
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
    virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
    virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62();
    virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(int a);
    virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78();
    virtual void v79(int a, int b);
};
/* Variant of UiV: slot 31 takes two arguments and returns a screen, slot 78 one. */
class UiVG : public UiS0 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual UiS* v31(int a, int b);
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
    virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
    virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(int a);
};
/* Variant of UiV: slot 7 takes two screens and a float. */
class UiVH : public UiS0 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(UiS* a, UiS* b, float f);
};
/* Variant of UiV: slot 5 takes four ints. */
class UiVJ : public UiS0 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(int a, int b, int c, int d);
};
/* Variant of UiV: grid accessors (slots 44, 58, 59) and slot 79. */
class UiVK : public UiS0 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43();
    virtual void v44(int a, int b, const char* s, int c);
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
    virtual void v57();
    virtual int v58();
    virtual int v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78();
    virtual void v79(int a, int b);
};
/* Variant of UiV: slot 43 takes (int, int, char*, int). */
class UiVM : public UiS0 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(int a, int b, char* s, int c);
};
/* Variant of UiV: slot 94 takes no argument. */
class UiVN : public UiS0 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
    virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
    virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72();
    virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78();
    virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90();
    virtual void v91(); virtual void v92(); virtual void v93();
    virtual void v94();
};
/* Data after the vptr (the vptr sits behind the data of the class that introduces the virtuals). */
class UiS : public UiV {
public:
    UiS* m40;
    UiS* m44;
    unsigned m48;
    UiN* m4C;
    char pad50[0x130 - 0x50];
    union { int m130; UiS* p130; };
    union { int m134; UiS* p134; };
    union { int m138; UiS* p138; };
    union { int m13C; UiS* p13C; };
    union { int m140; UiS* p140; };
    union { int m144; UiS* p144; };
    union { int m148; UiS* p148; };
    union { int m14C; UiS* p14C; };
    char pad150[0x17C - 0x150];
    int m17C;
    char pad180[0x188 - 0x180];
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
    char pad1B4[0x1C8 - 0x1B4];
    const void* m1C8;
    void* m1CC;
    char pad1D0[0x2DC - 0x1D0];
    int m2DC;
    union { UiS* p2E0; int m2E0; };
    int m2E4;
    int m2E8;
    int m2EC;
    int m2F0;
    char pad2F4[0x304 - 0x2F4];
    int m304;
    int m308;
    char pad30C[0x314 - 0x30C];
    int m314;
};

/* Screen object seen as plain data: constructors store the vtable address
 * (retail's lbl_ data object) by hand. 0x00-0x3B belong to fn_800EC648. */
class UiNB {
public:
    char pad0[0x24];
    UiNB* m24;
    char pad28[8];
    virtual ~UiNB();
};
struct UiScrRaw {
    char pad0[4];
    UiS* m4;
    char pad8[0x1C - 8];
    int m1C;
    char pad20[0x3C - 0x20];
    const void* m3C;
    char pad40[4];
    int m44;
    unsigned m48;
    UiNB* m4C;
    char pad50[4];
    char m54;
    char pad55[0x64 - 0x55];
    UiScrRaw* m64;
    char pad68[0x130 - 0x68];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m150;
    char pad154[0x170 - 0x154];
    int m170;
    char pad174[0x1A8 - 0x174];
    int m1A8;
    int m1AC;
};
extern "C" UiScrRaw* fn_800EC648(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h);
int fn_804D2AC0(void* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, const void* l);
void fn_8035686C(UiScrRaw* self);
void fn_8035686C(UiScrRaw* self, int a);
UiScrRaw* fn_800CEEF0(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, float l);
void fn_800CEFEC(UiScrRaw* self, int a);
extern char lbl_8065C788[];
extern float lbl_805BE168;
void fn_80356838(UiScrRaw* self, int a);

extern char lbl_80659DC0[];
extern char lbl_80655EB0[];
extern char lbl_805BE188[];
extern char lbl_805BE190[];
extern char lbl_8065A430[];
extern char lbl_805BE1B8[];
extern char lbl_805BE1A8[];
extern char lbl_805BE1B0[];
extern char lbl_805BE1C4[];
extern char lbl_805BE19C[];
extern char lbl_805BE1CC[];
extern char lbl_8061B31C[];
extern char lbl_8061B320[];
extern char lbl_8061B324[];
extern char lbl_806551F8[];
extern char lbl_80654C80[];
extern char lbl_80653E60[];
extern char lbl_806518E0[];
struct UiX600 {
    char pad0[0x600];
    int m600;
};
struct UiW {
    char pad0[0xC];
    UiX600* mC;
    char* m10;
    char* m14;
};
struct UiRoot {
    int m0;
    UiW* m4;
    UiW* m8;
};
extern UiRoot* lbl_806192E0;
#ifndef GAME_LBL_8061930C_INT
extern Unk8007B2B0_Screen* lbl_8061930C;
#endif
void fn_8006C698(UiW* p);
int fn_8040ABA0();
Unk8001BC8C* fn_8001BC4C();
int fn_8040B574(const char* a, const char* b);
void fn_804D3164(UiScrRaw* p);
void fn_804D2DC0(UiScrRaw* p, int a);
void fn_804D3CA8(UiScrRaw* p, int a);
void fn_800EC8EC(UiS* p);
void fn_800ECB0C(UiS* p);
extern "C" UiN* fn_800ED2B0(UiS* p, const char* name);
void fn_800C7E0C(UiS* p, int a);
void fn_800CFB38(UiN* n);
void fn_800C6794(UiS* p);
void* fn_800C6CEC(UiS* p, const char* name);
void* fn_800C8040(void* p);
int fn_804D3B18(UiS* p);
void fn_804D32A0(UiS* p, int a);
void* fn_800B8144();
void fn_800B83F8(void* p, int a, int b);
struct UiGlob {
    char pad0[0x204];
    int m204;
};
extern UiGlob* lbl_8061FEDC;
UiS* fn_800C8060(UiS* p);
struct Ui800B555C {
    int m0;
    int m4;
    char pad8[0x4E8 - 0x8];
    void* m4E8;
    char pad4EC[0x518 - 0x4EC];
    int m518;
    char pad51C[0x520 - 0x51C];
    int m520;
    int m524;
    char pad528[0x530 - 0x528];
    int m530;
    char pad534[0x560 - 0x534];
    int m560;
    int m564;
    int m568;
    char pad56C[0x570 - 0x56C];
    int m570;
    char pad574[0x588 - 0x574];
    int m588;
    int m58C;
    int m590;
    char pad594[0x650 - 0x594];
    int m650;
};
void* operator new(unsigned int size, int heap);
struct UiMsgMgr {
    char pad0[0xB8];
    int mB8;
    char padBC[0xD8 - 0xBC];
    UiMsgMgr();
};
extern UiMsgMgr* lbl_8061A32C;
inline UiMsgMgr* UiGetMsgMgr()
{
    if (lbl_8061A32C == 0)
        lbl_8061A32C = new (0) UiMsgMgr;
    return lbl_8061A32C;
}
void fn_800B7ADC(UiMsgMgr* mgr, UiS* o);

struct UiP13C {
    char pad0[0x13C];
    UiS* m13C;
};
struct UiMsg {
    char name[16];
};
void fn_8035682C(UiMsg* m);
char* fn_8040B830(char* dst, const char* src, unsigned n);
void fn_800B7B4C(UiMsgMgr* mgr, UiMsg* m, UiS* ctx);
UiS* fn_804D2D50(UiS* self);
void fn_80132438(UiS* o, UiS* self, int (*cb)(), void (*cb2)(UiS*), void (*cb3)(), int a, int b, int c, float d);
struct Ui8061B8C0 {
    char pad0[0x20];
    int m20;
};
extern Ui8061B8C0* lbl_8061B8C0;
extern char lbl_8065B888[];
extern char lbl_80649DA0[];
/* Stack event: id, then a vptr switched between the derived (lbl_8065B888) and base
 * (lbl_80649DA0) vtables. The empty inline dtor makes the 8-byte object BLKmode, which
 * keeps its frame address folded into the stores (a plain 8-byte struct is DImode and
 * gets a callee-saved address register). */
struct UiEvtRaw {
    int id;
    const void* vt;
    ~UiEvtRaw() {}
};
struct Ui6F8 {
    char pad0[0x14];
    int m14;
};
struct Ui8011AA24 {
    char pad0[0x6F8];
    Ui6F8* m6F8;
    char pad6FC[0x704 - 0x6FC];
    char m704[0x708 - 0x704];
    int m708;
    char pad70C[0x710 - 0x70C];
};
Ui8011AA24* fn_8011AA24(int a);
void fn_8037893C(char* p, int id, UiEvtRaw* e, int a, int b);
UiLabel* fn_800C8048(UiLabel* p);
UiS* fn_800B7A94(UiMsgMgr* mgr, const char* name);
void fn_80125490(UiS* o, int a, int b, int c, int d);
void fn_801251CC(UiS* o, int a, int b, int c);
void fn_80125084(UiS* o, int a);
void fn_80131F34(UiS* o, UiS* self, void (*cb)(int, void*), int (*cb2)(), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
void fn_80131F34(UiS* o, UiS* self, void (*cb)(int, void*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
void fn_800C80C0(UiS* o, int a);
UiS* fn_800B7AB8(UiMsgMgr* mgr, const char* name);
void fn_80124FA8(UiS* o, UiS* self);
struct UiR3D90 {
    char pad0[0x3D90];
    int m3D90;
};
UiR3D90* fn_801A6D84(Ui8011AA24* a, int b);
void fn_8016C4A0(UiR3D90* p);
int fn_802D7CE0(int a, int b);
extern "C" void fn_800ECF18(UiS* self);
extern "C" void fn_800ED310(UiS* self, int a);
int fn_800B57EC(Ui800B555C* p);
struct UiOwn708 {
    char pad0[0x708];
    int m708;
};
UiOwn708* fn_801A4A94(Ui8011AA24* g, int b);
struct Ui198 {
    char pad0[0x198];
    int m198;
};
struct UiEvtPlain {
    int id;
    const void* vt;
};
void fn_800CEF98(UiS* self);
UiS* fn_800C8044(UiS* p);
void fn_804D27B4(char* sub, int a);
void fn_804D233C(char* sub);
void fn_804D292C(char* sub, int a);
void fn_800DD204(void* a, void* b);
void* fn_800C8038(UiS* p);
extern "C" void fn_800ECAA4(UiS* self);
struct UiRec12 {
    int m0;
    int m4;
    float m8;
};
extern "C" void fn_800ECC9C(UiS* self, UiS* node, UiRec12* arr, int n);

/* fn_800ED590: container with up to 100 children at +0x34 (count at +0x1C4); flag bit 0x40000000 at +0x24
 * of a child enables the pointer-to-member callback. */
struct Unk800ED590_B {
    char m0[0x24];
    unsigned int m24;
};
struct Unk800ED590_W : Unk800ED590_B {
    virtual int f(int a);
};
typedef int (Unk800ED590_W::*Unk800ED590_Fn)(int);
struct Unk800ED590_C {
    char m0[0x34];
    Unk800ED590_W* m34[100];
    int m1C4;
};
void fn_800ED590(Unk800ED590_C* self, int a, Unk800ED590_Fn f);
#endif
