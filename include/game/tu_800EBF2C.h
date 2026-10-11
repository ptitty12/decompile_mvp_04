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
void fn_800ECE34(void* t);
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
    char padC[0x20 - 0xC];
    int m20;
    int m24;
    char pad28[0x2E - 0x28];
    short m2E;
    char pad30[0x3C - 0x30];
};
class UiV : public UiS0 {
public:
    virtual ~UiV();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(int a); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(int a); virtual void v15(); virtual void v16(int a);
    virtual void v17();
    virtual void v18(int a);
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual UiS* v30(const char* s, int a);
    virtual void v31();
    virtual UiS* v32(const char* s, int a);
    virtual UiLabel* v33(int a, int b); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52();
    virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual UiS* v70();
    virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual int v75(); virtual void v76();
    virtual int v77();
    virtual void v78();
    virtual void v79(); virtual void v80(int a); virtual int v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(int a); virtual void v86(); virtual void v87(); virtual void v88();
    virtual void v89(int a);
    virtual int v90();
    virtual void v91(); virtual void v92(); virtual void v93();
    virtual void v94(int a);
    virtual void v95(); virtual void v96();
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
    char pad180[0x1A8 - 0x180];
    int m1A8;
    int m1AC;
    int m1B0;
    char pad1B4[0x1C8 - 0x1B4];
    const void* m1C8;
    void* m1CC;
    char pad1D0[0x2F0 - 0x1D0];
    int m2F0;
    char pad2F4[0x314 - 0x2F4];
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
void fn_804D2AC0(void* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, const void* l);
void fn_8035686C(UiScrRaw* self);
void fn_8035686C(UiScrRaw* self, int a);
void fn_800CEEF0(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, float l);
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
};
struct UiRoot {
    int m0;
    UiW* m4;
    UiW* m8;
};
extern UiRoot* lbl_806192E0;
extern Unk8007B2B0_Screen* lbl_8061930C;
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
    char pad4[0x570 - 4];
    int m570;
};
void* operator new(unsigned int size, int heap);
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
struct Ui8011AA24 {
    char pad0[0x704];
    char m704[0x710 - 0x704];
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
#endif
