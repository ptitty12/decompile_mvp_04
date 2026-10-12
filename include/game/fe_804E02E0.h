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
    virtual int v59();
    virtual int v60();
    virtual int v61();
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
void fn_804E6A58(void* self);
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
struct FeP4Rec {
    int m0;
    int m4;
    int m8;
    char padC[0x4F0 - 0xC];
    int m4F0;
};
struct FeP4Tab {
    int m0;
    FeP4Rec e[4];
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

void fn_800E25E0(int a, int b);
extern "C" void fn_8035686C(void* self, int chrg);
struct FeS4 : FeObj {
    char pad40[0x13C - 0x40];
    FeObj* m13C;
    char pad140[0x154 - 0x140];
    int m154;
};
struct FeS5 : FeObj {
    char pad40[0x138 - 0x40];
    FeObj* m138;
    int m13C;
};

struct FeS6 : FeObj {
    char pad40[0x134 - 0x40];
    FeObj* m134;
    FeObj* m138;
    FeObj* m13C;
    FeObj* m140;
    FeObj* m144;
    FeObj* m148;
    FeObj* m14C;
};

/* Profile-list screens (units 804E750C..): widgets at +0x134/+0x138/+0x140, FeHolder pairs at +0x148..0x15C. */
struct FeS7 : FeObj {
    char pad40[0x134 - 0x40];
    FeObj* m134;
    FeObj* m138;
    int m13C;
    FeObj* m140;
};
struct FeS8 : FeObj {
    char pad40[0x144 - 0x40];
    int m144;
    FeHolder* m148;
    char pad14C[0x158 - 0x14C];
    FeHolder* m158;
    FeHolder* m15C;
};
struct FeS9 : FeObj {
    char pad40[0x13C - 0x40];
    FeObj* m13C;
};
extern "C" {
void fn_804E7D44(FeS7* self, int a);
void fn_804E8644(void* self);
void fn_800E26B4(int a, int b);
}

struct FeS11 : FeObj {
    char pad40[0x138 - 0x40];
    FeObj* m138;
    char pad13C[0x164 - 0x13C];
    FeObj* m164;
};
extern "C" void fn_80125084(FeObj* o, int a);

struct FeS12 : FeObj {
    char pad40[0x138 - 0x40];
    FeObj* m138;
    FeObj* m13C;
};
struct FeMsgMgrB {
    char pad0[0xC0];
    int mC0;
};
struct FeS13 : FeObj {
    char pad40[0x1D8 - 0x40];
    int m1D8;
    int m1DC;
    int m1E0;
    int m1E4;
    char pad1E8[0x1FC - 0x1E8];
    int m1FC;
    int m200;
};
struct FeRaw1D8 {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x17C - 0x40];
    const void* m17C;
    char pad180[0x1D8 - 0x180];
    int m1D8;
    int m1DC;
    int m1E0;
    int m1E4;
    int m1E8;
    int m1EC;
    int m1F0;
    char pad1F4[0x1FC - 0x1F4];
    int m1FC;
    int m200;
};
extern void* lbl_8061FEDC;
extern int lbl_8061A328;
extern "C" {
void fn_804EA6D0(void* self);
void fn_804EB2C8(void* self);
void fn_80313634(void* p);
void fn_803136A0(void* p);
}
inline void FeSetAt(char* base, int off, int v)
{
    *(int*)(base + off) = v;
}

struct FeS14b {
    char pad0[0xB90];
    int mB90;
};
class FeDB94 {
public:
    char pad0[0xB94];
    virtual ~FeDB94();
};
struct FeS14 : FeObj {
    char pad40[0x134 - 0x40];
    FeS14b* m134;
    char pad138[0x158 - 0x138];
    int m158;
    int m15C;
};
struct FeRaw14 {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x130 - 0x40];
    int m130, m134, m138, m13C, m140, m144, m148, m14C, m150, m154, m158, m15C, m160, m164, m168, m16C, m170, m174, m178;
};
struct FeRawD {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x134 - 0x40];
    FeDB94* m134;
};
struct FeS15 : FeObj {
    char pad40[0x160 - 0x40];
    int m160;
    int m164;
    int m168;
    int m16C;
    char pad170[0x178 - 0x170];
    int m178;
    int m17C[25];
    int m1E0[25];
};
extern "C" {
void* fn_803773D8(unsigned n);
void* fn_800B5E68(void* p, int a);
void fn_80125180(FeObj* o, int a, int b);
}
void fn_800E2BCC();
extern int lbl_806221E4;

class FeD64 {
public:
    char pad0[0x64];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
};
struct FeS16;
extern "C" void fn_804EBCB4(FeS16* self);
extern "C" void fn_804EC68C(FeS16* self, FeD64* o);
struct FeS16 : FeObj {
    char pad40[0x140 - 0x40];
    FeObj* m140;
    FeObj* m144;
    char pad148[0x158 - 0x148];
    int m158;
};
extern "C" {
FeD64* fn_80528400(void* self, int a);
void fn_804EBD68(void* self, FeD64* o);
void fn_804EBF7C(void* self, FeD64* o);
void fn_804EC294(void* self, FeD64* o);
void fn_800B82AC(FeB8144* b);
}

/* Member object at +0xDC whose slot signatures take one int (see FeSub in tu_8043FDC0.h). */
class FeSubB {
public:
    char pad0[0x24];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6(int a);
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int s10();
    virtual int s11();
    virtual int s12();
    virtual int s13();
    virtual int s14();
    virtual int s15();
};
struct FeS17 : FeObj {
    char pad40[0x604 - 0x40];
    FeObj* m604;
    char pad608[0x618 - 0x608];
    FeObj* m618;
    char pad61C[0x630 - 0x61C];
    int m630;
};
extern "C" {
int fn_805283F4();
void fn_804FC260(void* self);
void fn_804FBF58(void* self);
}
extern int lbl_806221F8;
extern int lbl_806221FC;
extern int lbl_8061D384;
extern int lbl_8061D388;

/* Create-a-player screens (unit 804F81E0..): per-slot records (stride 0xC) from +0x1F8, mode at +0x630, id at +0x86C. */
struct FeE12 {
    int a;
    int b;
    int c;
};
struct FeS18 : FeObj {
    char pad40[0x1F8 - 0x40];
    FeE12 e[25];
};
struct FeS19 : FeObj {
    char pad40[0x630 - 0x40];
    int m630;
    char pad634[0x86C - 0x634];
    int m86C;
};
struct FeS20 : FeObj {
    char pad40[0x844 - 0x40];
    int m844;
    int m848;
};
struct FeS21 : FeObj {
    char pad40[0x4A0 - 0x40];
    int m4A0;
    char pad4A4[0x4B4 - 0x4A4];
    int m4B4;
    char pad4B8[0x4C8 - 0x4B8];
    int m4C8;
    char pad4CC[0x4DC - 0x4CC];
    int m4DC;
};
int fn_800765A8(int a);
void fn_803043D4(int a, int b);

struct FeRawBig {
    char pad0[0x3C];
    const void* m3C;
    char pad40[0x10EC - 0x40];
    int m10EC, m10F0, m10F4, m10F8, m10FC, m1100;
};

extern "C" {
int fn_804089B4(char* dst, const char* fmt, ...);
void fn_804F8534(void* self);
}
void fn_802AEBF0(void* a, void* b);
extern void* lbl_8061E978;
extern int lbl_805FD1A0[];
extern int lbl_805FD2A8[];
struct FeS22 : FeObj {
    char pad40[0x3B4 - 0x40];
    int m3B4;
    char pad3B8[0x484 - 0x3B8];
    int m484;
    char pad488[0x604 - 0x488];
    FeObj* m604;
    char pad608[0x630 - 0x608];
    int m630;
    char pad634[0x82C - 0x634];
    FeObj* m82C[8];
    char pad84C[0x864 - 0x84C];
    int m864;
    int m868;
};

extern float lbl_80622220[];
extern float lbl_80622240[];
extern float lbl_80622260[];
extern float lbl_80622280[];
struct FeS23 : FeObj {
    char pad40[0x870 - 0x40];
    int m870;
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
struct FeWf618 : FeObj { char pad40[0x618 - 0x40]; FeObj* m618; };
/* END-VWRAP */

#endif
