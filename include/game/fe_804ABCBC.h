/*
 * Shared types for the front-end overlay units fe/tu_804ABCBC .. fe/tu_804BE560
 * (0x804ABCBC..0x804BE560; reconstructed, placeholder names; nothing here comes from
 * original headers). Builds on the widget view classes of game/tu_8043FDC0.h: FeObj
 * (vptr at +0x3C, virtual N at vtable offset 8N) and FeScr (screen fields from +0x130).
 * Every function defined in these units carries FE_OVERLAY (game/overlay.h).
 */
#ifndef GAME_FE_804ABCBC_H
#define GAME_FE_804ABCBC_H

#include "game/tu_8043FDC0.h"

struct FeRec4;

/* A widget pointer stored at a byte offset of a screen (beyond FeScr's named fields). */
#define FeP(x, o) (*(FeObj**)((char*)(x) + (o)))
/* An int field of a screen at a byte offset. */
#define FI(x, o) (*(int*)((char*)(x) + (o)))

/* Screen as plain data for the constructors (FeScrRaw extended to 0x400): the vtable address
 * (a retail .data object) is stored by hand; fields are ints at their byte offsets. */
struct FeRaw : FeScrRaw {
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
    int m1B4;
    int m1B8;
    int m1BC;
    int m1C0;
    int m1C4;
    int m1C8;
    int m1CC;
    int m1D0;
    int m1D4;
    int m1D8;
    int m1DC;
    int m1E0;
    int m1E4;
    int m1E8;
    int m1EC;
    int m1F0;
    int m1F4;
    int m1F8;
    int m1FC;
    int m200;
    int m204;
    int m208;
    int m20C;
    int m210;
    int m214;
    int m218;
    int m21C;
    int m220;
    int m224;
    int m228;
    int m22C;
    int m230;
    int m234;
    int m238;
    int m23C;
    int m240;
    int m244;
    int m248;
    int m24C;
    int m250;
    int m254;
    int m258;
    int m25C;
    int m260;
    int m264;
    int m268;
    int m26C;
    int m270;
    int m274;
    int m278;
    int m27C;
    int m280;
    int m284;
    int m288;
    int m28C;
    int m290;
    int m294;
    int m298;
    int m29C;
    int m2A0;
    int m2A4;
    int m2A8;
    int m2AC;
    int m2B0;
    int m2B4;
    int m2B8;
    int m2BC;
    int m2C0;
    int m2C4;
    int m2C8;
    int m2CC;
    int m2D0;
    int m2D4;
    int m2D8;
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
    int m304;
    int m308;
    int m30C;
    int m310;
    int m314;
    int m318;
    int m31C;
    int m320;
    int m324;
    int m328;
    int m32C;
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
    int m35C;
    int m360;
    int m364;
    int m368;
    int m36C;
    int m370;
    int m374;
    int m378;
    int m37C;
    int m380;
    int m384;
    int m388;
    int m38C;
    int m390;
    int m394;
    int m398;
    int m39C;
    int m3A0;
    int m3A4;
    int m3A8;
    int m3AC;
    int m3B0;
    int m3B4;
    int m3B8;
    int m3BC;
    int m3C0;
    int m3C4;
    int m3C8;
    int m3CC;
    int m3D0;
    int m3D4;
    int m3D8;
    int m3DC;
    int m3E0;
    int m3E4;
    int m3E8;
    int m3EC;
    int m3F0;
    int m3F4;
    int m3F8;
    int m3FC;
    int m400;
    int m404;
    int m408;
    int m40C;
    int m410;
    int m414;
    int m418;
    int m41C;
    int m420;
    int m424;
    int m428;
    int m42C;
    int m430;
    int m434;
    int m438;
    int m43C;
    int m440;
    int m444;
    int m448;
    int m44C;
    int m450;
    int m454;
    int m458;
    int m45C;
    int m460;
    int m464;
    int m468;
    int m46C;
    int m470;
    int m474;
    int m478;
    int m47C;
    int m480;
    int m484;
    int m488;
    int m48C;
    int m490;
    int m494;
    int m498;
    int m49C;
    int m4A0;
    int m4A4;
    int m4A8;
    int m4AC;
    int m4B0;
    int m4B4;
    int m4B8;
    int m4BC;
    int m4C0;
    int m4C4;
    int m4C8;
    int m4CC;
    int m4D0;
    int m4D4;
    int m4D8;
    int m4DC;
    int m4E0;
    int m4E4;
    int m4E8;
    int m4EC;
    int m4F0;
    int m4F4;
    int m4F8;
    int m4FC;
    int m500;
    int m504;
    int m508;
    int m50C;
    int m510;
    int m514;
    int m518;
    int m51C;
    int m520;
    int m524;
    int m528;
    int m52C;
    int m530;
    int m534;
    int m538;
    int m53C;
    int m540;
    int m544;
    int m548;
    int m54C;
    int m550;
    int m554;
    int m558;
    int m55C;
    int m560;
    int m564;
    int m568;
    int m56C;
    int m570;
    int m574;
    int m578;
    int m57C;
    int m580;
    int m584;
    int m588;
    int m58C;
    int m590;
    int m594;
    int m598;
    int m59C;
    int m5A0;
    int m5A4;
    int m5A8;
    int m5AC;
    int m5B0;
    int m5B4;
    int m5B8;
    int m5BC;
    int m5C0;
    int m5C4;
    int m5C8;
    int m5CC;
    int m5D0;
    int m5D4;
    int m5D8;
    int m5DC;
    int m5E0;
    int m5E4;
    int m5E8;
    int m5EC;
    int m5F0;
    int m5F4;
    int m5F8;
    int m5FC;
};

extern "C" {
void fn_800ED254(void* x);
void* fn_800C33D0();
void fn_800C3BE0();
void fn_800E49DC(FeScr* x);
void fn_804B47C0(FeScr* x);
void fn_804B5FC4(FeScr* x);
void fn_804B6108(FeScr* x);
void fn_804B7D2C(FeScr* x);
void fn_804B7E24(FeScr* x);
}

/* Screen of unit 804ABCBC (the request/list popups): m134/m138 are widgets, m140 is the selected
 * tab (0..3), m144 an array of item ids, m1C4/m1C8 a mode word and a cursor. Evidence:
 * fn_804ABCBC, fn_804AC114, fn_804AC1C0. */
struct FeSc1 : FeObj {
    char pad40[0x130 - 0x40];
    int m130;
    FeObj* m134;
    FeObj* m138;
    int m13C;
    int m140;
    int m144[32];
    int m1C4;
    int m1C8;
};
/* The screen manager (lbl_8061930C) as read by the list popups: +0x2C holds the list handle. */
struct FeScrMgrView {
    char pad0[0x2C];
    int m2C;
};

void fn_800736EC(const char* s); /* C++ symbol fn_800736EC__FPCc */
/* List-popup item record returned by fn_8008007C (+0x10 is a halfword level). */
struct Unk8007FF8C_G;
struct FeLvlRec {
    char pad0[0x10];
    unsigned short m10;
};
FeLvlRec* fn_8008007C(Unk8007FF8C_G* g, unsigned id);
/* The state record + 8 (fn_800B555C()) as the popups write it. */
struct FeBase8 {
    char pad0[0x38];
    int m38;
    char pad3C[0x6C - 0x3C];
    int m6C;
    int m70;
};
struct FeSt68 {
    char pad0[0x68];
    int m68;
};
extern "C" {
void fn_804AC564(FeSc1* x);
void fn_804ACA20(FeSc1* x);
void fn_804ABF48(FeSc1* x, int a);
void fn_804ABE1C(FeSc1* x);
void fn_804AC280(FeSc1* x);
void fn_804AC348(int a, FeSc1* x);
void fn_804AC114(FeSc1* x);
void fn_804AC1C0(FeSc1* x);
int fn_8058200C(int a, int b);
void fn_800C2034(void* p, int a);
void fn_800C2088(void* p, int a, int b);
void fn_805291C8(int a, void* b);
void fn_804AE300(int a, FeObj* w);
}

extern "C" void fn_804AFCCC(FeScr* x);
extern "C" void fn_804AF2A0(FeScr* x);

extern "C" void fn_804B1E70(FeScr* x, int p1);
extern "C" void fn_804B2B40(FeScr* x, int p1);

extern "C" void fn_800C3AB4(void* p, int v);
extern "C" void fn_804B3A14(FeScr* x, int p1);
extern "C" void fn_804D3164(FeScr* x);
extern "C" void fn_804D2DC0(FeScr* x, int p1);
extern "C" void fn_804B44AC(FeScr* x);


extern "C" void fn_804B4908(FeScr* x);

extern "C" void fn_804B83A4(FeScr* x);
extern "C" void fn_804B530C(FeScr* x);
extern "C" FeObj* fn_800C8038(FeObj* o);
extern "C" void fn_800C4AC8(void* a, FeObj* b, int c);
extern "C" void fn_800C4D28(void* a, FeObj* b, int c, int d);

extern "C" void fn_804B3260(int b);
extern "C" void fn_804B00D8(FeScr* x);
void fn_800E49A4(); /* C++ symbol fn_800E49A4__Fv */

/* fn_80125154 / fn_801251CC return a value that callers ignore; retail's callers treat them as int. */
typedef int (*FeFnOI)(FeObj*, int);
typedef int (*FeFnOIII)(FeObj*, int, int, int);

extern "C" void fn_804B243C(FeScr* x, int a);

extern "C" void fn_80125100(FeObj* p0);

extern "C" void fn_804BD4D0(FeScr* x, int p1);
extern "C" void fn_800DD204(FeObj* a, FeObj* b);

/* BEGIN-VIEWS */
/* Generated by a scratch script: widget/sub-object views that differ from FeObj in a few slot signatures. */
class FeObjS86 : public UiBase {
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
    virtual FeObj* v32(const char* a0, int a1);
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
    virtual void v86(int a0, FeObj* a1, int a2, int a3, int a4);
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
};
class FeObjS79 : public UiBase {
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
    virtual FeObj* v32(const char* a0, int a1);
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
    virtual void v79(int a0, int a1);
};
class FeV1C {
public:
    char pad0[0x1C];
    virtual void s1();
    virtual void s2(int a0, int a1, float a2, float a3);
    virtual void s3(int a0, int a1);
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
};
class FeObjS43 : public UiBase {
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
    virtual FeObj* v32(const char* a0, int a1);
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
    virtual void v43(int a0, int a1, char* a2, int a3);
};
class FeV4 {
public:
    char pad0[0x4];
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
    virtual FeRec4* s11(int a0);
};
/* END-VIEWS */

extern "C" {
int fn_80593E8C(FeObj* o, int i);
int fn_80593EB0(FeObj* o, int i, int a);
int fn_80593E7C(FeObj* o, int i);
void fn_80125128(FeObj* o, int a);
void fn_800DF254(char* out, int a, int b, float f);
void fn_800E5380(FeObj* o);
}

extern "C" void fn_804B8570(FeScr* x, int a, int b);


extern "C" void* fn_80594240(FeObj* l, int i);
extern "C" void* fn_80593B68(FeObj* l, int i);

extern "C" void fn_805818C8(int h, int id, int flag);

/* Record behind the list handle of fn_8058211C's object (fn_804AF2A0): +0 and +4 are flags, +0x28 a value. */
struct FeRec4 {
    int m0;
    int m4;
    char pad8[0x28 - 8];
    int m28;
};
inline int FeNz0(FeRec4* r)
{
    if (r->m0 != 0)
        return 1;
    return 0;
}
inline int FeNz1(FeRec4* r)
{
    int v = 1;
    if (r->m0 == 0)
        v = 0;
    return v;
}
extern "C" FeV4* fn_8058211C(int h);

extern "C" {
void* fn_800E4874(int i);
int fn_804ACAFC(FeSc1* x, int k);
void fn_800DE440(char* out, int a, int b);
void fn_804ACD0C(FeSc1* x, int i);
}

extern "C" void fn_804031BC(char* dst, const char* src);

int fn_800E190C(int i); /* C++ symbol fn_800E190C__Fi */
int fn_800E18D4(int i); /* C++ symbol fn_800E18D4__Fi */
extern "C" int fn_80077BC4(void* g, int a);

extern "C" void fn_8052DD58(void* p);

extern char lbl_80674080[];
extern char lbl_806841F8[];

/* Sub-object embedded at +0x144 of the screen of fn_804ACFC8: vptr at +0x14, ctor fn_8052DD58. */
struct FeSub14 {
    char pad0[0x14];
    const void* m14;
};


extern "C" int fn_804B797C(FeScr* x);
extern "C" int fn_800B5520(int a);

/* Drawing batch of unit 804BB110 (ctor fn_804BB110): eight floats (a rect), a flag word at +0x20,
 * four 0x324-byte records of 100 float pairs and a point count, then the record count (+0xCB4),
 * flags (+0xCB8), a widget (+0xCBC), the vptr (+0xCC0) and a scale (+0xCC4). */
struct FeCamPair {
    float a;
    float b;
};
struct FeCamRec {
    FeCamPair p[100];
    int cnt;
};
struct FeCam {
    float m0, m4, m8, mC, m10, m14, m18, m1C;
    int m20;
    FeCamRec rec[4];
    int mCB4;
    int mCB8;
    FeObj* mCBC;
    const void* mCC0;
    float mCC4;
};
struct FeTbl30 {
    char pad0[0x14];
    int m14;
    int m18;
    int m1C;
};
struct FeMgr30 {
    char pad0[0x30];
    FeTbl30* m30;
};
extern "C" void fn_804BB334(FeCam* c);
extern "C" void fn_804BB3D0(FeCam* c, float a, float b, float c2, float d);
extern "C" void fn_800CFB38(FeObj* w);

#endif
