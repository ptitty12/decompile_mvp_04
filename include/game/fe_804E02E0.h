/*
 * Shared types for the front-end overlay units fe/tu_804E02E0 .. fe/tu_804F81E0
 * (0x804E02E0..0x804FE34C; reconstructed, placeholder names, nothing here comes from
 * original headers). The widget view classes (FeObj family) come from tu_8043FDC0.h.
 */
#ifndef GAME_FE_804E02E0_H
#define GAME_FE_804E02E0_H

#include "game/tu_8043FDC0.h"

#include "game/tu_8007DB74.h"

/* Callees of the 804E02E0.. screens (declared here; their definitions are other units). */
void fn_800E2BAC();
void fn_800E2C08();
void fn_800E2C34();
void fn_8007DB74(Unk8007DB74_A* a, int b);
extern "C" {
void fn_800ED254(void* x);
void fn_802D7EE4(int a);
void fn_80125100(FeObj* o);
void fn_8033E958(const char* fmt, ...);
FeObj* fn_800C8038(void* p);
FeObj* fn_800C8048(void* p);
void* fn_804D2EC0(void* self, int i);
}

/* Member object returned by fn_804D2EC0: its own vptr at +0x10 (slot N at vtable +8N). */
class FeS10 {
public:
    char pad0[0x10];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4();
    virtual int s5(int a);
    virtual void s6();
    virtual void s7();
    virtual void s8();
};

/* Timer object of the title screens (0x14 bytes at +0x1DC; fn_800D876C resets it). */
struct Unk800D876C_A {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
void fn_800D876C(Unk800D876C_A* t);
int fn_800D87C4(Unk800D876C_A* t);
void fn_800D878C(Unk800D876C_A* t);
int fn_8005B9B0(Unk8005ADD0_Obj* o, int a);

/* TITLESLIDE-like screen (ctor fn_804E1940): state word m1D8, timer object at m1DC. */
struct FeTitle : FeObj {
    char pad40[0x130 - 0x40];
    int m130;
    char m134[0x48];
    const void* m17C;
    int m180;
    FeObj* m184;
    short m188;
    char pad18A[0x1D8 - 0x18A];
    int m1D8;
    Unk800D876C_A m1DC;
    int m1F0;
    int m1F4;
    int m1F8;
    int m1FC;
    short m200;
};
struct FeI134 : FeObj {
    char pad40[0x134 - 0x40];
    int m134;
};
extern "C" {
void fn_804E1670(FeTitle* self);
void fn_804E1020(FeTitle* self);
void fn_804E1840(FeObj* self);
void fn_804E18D4();
}


typedef void (*FeVf)();
struct FeB8144 {
    char pad0[0x1C];
    FeVf m1C;
};
extern "C" {
FeB8144* fn_800B8144();
void fn_800B82D0(FeB8144* b, int a, int c);
void* fn_80134E38(void* s, int a);
void fn_804D3164(void* x);
void fn_804D2DC0(void* x, int v);
void fn_804E14EC(FeTitle* self, int a);
}

/* Widget view whose slot signatures take one string. */
#define FE_VS1(n) virtual void v##n(const char* a);
class FeObjS : public UiBase {
public:
    FE_LO(FE_VS1) virtual FeObj* v32(const char* a, int b); FE_HI(FE_VS1)
};

/* Screen with a count at +0x154 and a table of per-item words at +0x1C0 (fn_804E0A28..). */
struct FeItems : FeObj {
    char pad40[0x154 - 0x40];
    int m154;
    char pad158[0x1C0 - 0x158];
    int m1C0[4];
};

/* Raw views of the screens being constructed (the vtable addresses are stored by hand). */
struct FeRawTitle {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x130 - 0x40];
    int m130;
    char m134[0x48];
    const void* m17C;
    int m180;
    int m184;
    unsigned short m188;
};
struct FeRaw174 {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x174 - 0x40];
    char m174[0x48];
    const void* m1BC;
};
extern "C" void fn_804D2AC0(void* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, const void* l);
extern char lbl_805F36A0[];
extern int lbl_806221E0;

/* Widget owned through m134 of the title screens: its vptr sits at +0x120. */
class FeD120 {
public:
    char pad0[0x120];
    virtual ~FeD120();
};
/* Title screen ctor view (base ctor fn_80135180, timer at m1DC). */
struct FeRaw0BAC {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x134 - 0x40];
    FeD120* m134;
    char pad138[0x17C - 0x138];
    const void* m17C;
    char pad180[0x1D8 - 0x180];
    int m1D8;
    Unk800D876C_A m1DC;
    int m1F0;
    int m1F4;
    int m1F8;
    int m1FC;
    short m200;
};
extern "C" {
void* fn_80135180(void* self, int a, int b, int c, int d, int e, int f, int g, int h, int i);
void fn_80135200(void* self, int chrg);
}

class FeObjK : public UiBase {
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
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37(int a);
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
    virtual int v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69(int a);
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual FeObjQ* v73(int a, int b);
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual int v77();
};

/* Category-mask screen (units 804E1A6C..): the list widget at +0x184, a bit mask at +0x188. */
struct FeMask : FeObj {
    char pad40[0x180 - 0x40];
    int m180;
    FeObj* m184;
    unsigned short m188;
    unsigned short m18A;
};
extern "C" {
int fn_804E2274(void* self, int v, int i);
void fn_804E2280(FeMask* self, int idx);
void fn_804E26E4(FeMask* self, int idx);
void fn_804E2014(FeMask* self);
}
void fn_8005B87C(Unk8005ADD0_Obj* o, int i, int v);

extern "C" {
void fn_804E3174(void* self, int a);
void fn_804E3EF8(void* self);
void fn_804E46B8(void* self);
void* fn_800C33D0();
void fn_800C3AB4(void* p, int v);
void fn_800C3BE0();
}
/* Screen with list widgets at +0x138/+0x13C/+0x140 and a cursor at +0x14C (units 804E1A6C..). */
struct FeS3 : FeObj {
    char pad40[0x130 - 0x40];
    int m130;
    int m134;
    FeObj* m138;
    FeObj* m13C;
    FeObj* m140;
    int m144;
    int m148;
    int m14C;
    int m150;
};
extern int lbl_805F9DEC[];

class FeObjR : public UiBase {
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
    virtual void v68(int a);
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual int v77();
};

/* Four-player table (stride 0x4F4; +4 is the "slot in use" word) and the game record's pointer to it. */
struct FeP4Ent {
    int m0;
    int m4;
    int m8;
    char padC[0x4F4 - 0xC];
};
struct FeP4Tab {
    FeP4Ent e[4];
};
struct FeGameB {
    char pad0[0x64];
    FeP4Tab* m64;
};
extern "C" int fn_804EAF54(FeP4Tab* t);
inline int FeKeyAt(char* base, int off)
{
    return *(int*)(base + off);
}

class FeObjS2 : public UiBase {
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
};

/* BEGIN-VWRAP */
/* Screens whose only data is one widget pointer at the given offset (one-call button handlers). */
struct FeWf134 : FeObj { char pad40[0x134 - 0x40]; FeObj* m134; };
struct FeWf138 : FeObj { char pad40[0x138 - 0x40]; FeObj* m138; };
struct FeWf138b : FeObj { char pad40[0x138 - 0x40]; FeObj1* m138; };
struct FeWf13C : FeObj { char pad40[0x13C - 0x40]; FeObj* m13C; };
struct FeWf140 : FeObj { char pad40[0x140 - 0x40]; FeObj* m140; };
struct FeWf140b : FeObj { char pad40[0x140 - 0x40]; FeObj1* m140; };
struct FeWf184 : FeObj { char pad40[0x184 - 0x40]; FeObj* m184; };
struct FeWf604 : FeObj { char pad40[0x604 - 0x40]; FeObj* m604; };
struct FeWf604b : FeObj { char pad40[0x604 - 0x40]; FeObj1* m604; };
/* END-VWRAP */

#endif
