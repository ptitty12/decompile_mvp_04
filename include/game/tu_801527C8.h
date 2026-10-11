/*
 * Script command classes of the game script system (units tu_801527C8 through
 * tu_80156714 and tu_8016BF30). Reconstructed; nothing here comes from original
 * headers. Names are the class-name strings stored behind vtable slot 3.
 *
 * Hierarchy (from the vtables 0x8065DB58..0x8065E968):
 *
 *   Unk8037B3E8      root (ctor 0x8037B3E8, vtable slots 1-10, chooser.h)
 *     Unk80359B48    script command base: dtor 0x80359B48, slots 2-5 pure
 *                    (0x804144B8), slot 11 empty (0x80359974), slot 12 returns
 *                    1 (0x8035998C), slot 13 returns a float constant
 *                    (0x803599A8)
 *       cXxx         concrete commands (object = vptr + fields)
 *
 * Every concrete ctor calls the root ctor directly and stores only its own
 * vptr (the base's vptr store is dead), the same as the event classes
 * (events.h). The base's virtuals are all out of line, so no vtable is emitted
 * here. chooser.h folds the choosers' slots 11-17 into the root, so the script
 * virtuals added below (fn_cslot*) follow those in the vtable; that doesn't
 * matter until a unit compiles a virtual call to one of them.
 *
 * Script slot 8 (vtable +0x44) is called fn_cslot8 here; the root's slot 8
 * is an empty (this) function and is not overridden by the commands.
 */
#ifndef GAME_TU_801527C8_H
#define GAME_TU_801527C8_H

#include "game/chooser.h"
#include "game/goals/tu_80287600.h"
#include "game/goals/tu_8027C728.h"

struct Unk801527C8_Ctx;

/* Script command base class (vtable of the dtor at 0x80359B48). The three
 * script virtuals take the run context, a state word and three floats
 * (f1..f3, spilled to the frame by every implementation). */
class Unk80359B48 : public Unk8037B3E8 {
public:
    Unk80359B48(unsigned int hash) : Unk8037B3E8(hash) {}
    Unk80359B48(const char* name) : Unk8037B3E8(name) {}
    virtual ~Unk80359B48();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual float fn_cslot13(float f1);

    /* More attribute registration functions of the root (called from the slot 2
     * implementations; chooser.h has the others). Declared here, not in
     * Unk8037B3E8, so that chooser.h stays untouched. */
    void fn_8037B5C0(const char* name, int* field, const char* typeList);          /* object reference */
    void fn_8037B584(const char* name, void* data, int len, const char* names);     /* script info / string field */
    void fn_8037B548(const char* name, const char* names);
    void fn_8037B728(const char* name, const char* name2, void* list, const char* classes);
};


/* Deeper objects of the script run context (only the fields the commands read). */
struct Unk801527C8_Team {
    char pad0[0x1B4];
    unsigned char m1B4[0x80];
    char pad234[0xD70 - 0x234];
    int mD70;
    char padD74[0xE64 - 0xD74];
};

struct Unk801527C8_Teams {
    Unk801527C8_Team m0[2];
    unsigned char m1CC8;
    char pad1CC9[7];
    int m1CD0;
};

struct Unk801527C8_Ent10 {
    char pad0[0x13C];
    int m13C;
};

struct Unk801527C8_Ent0C {
    char pad0[0x84];
    int m84;
};

struct Unk801527C8_Mgr {
    int fn_8006BE18();
    char pad0[0xC];
    Unk801527C8_Ent0C* mC;
    Unk801527C8_Ent10* m10;
    Unk801527C8_Teams* m14;
};

struct Unk801527C8_Ent3BC {
    char pad0[0x24];
    int m24;
};

struct Unk801527C8_Obj3A4 {
    char pad0[0x180];
    float m180;
};

struct Unk801527C8_Slots {
    char pad0[0x3A4];
    Unk801527C8_Obj3A4* m3A4;
    char pad3A8[4];
    void* m3AC;
    void* m3B0;
    void* m3B4;
    void* m3B8;
    Unk801527C8_Ent3BC* m3BC;
};

/* Sub-object at actor+0x50 (animation/state controller; passed to fn_80327274,
 * fn_803270C4, fn_80326E64). */
/* 0x18-byte result of Sub::fn_80326F44 (animation sample: type word at +0, time at +4). */
struct Unk80326F44_Out {
    int m0;
    float m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

struct Unk801527C8_Sub {
    void fn_80326EF4(float t, float k, int id, int a, int b, int flags);
    Unk80326F44_Out fn_80326F44(int id, int flag, float t);
    char pad0[0x40];
};

/* Object at actor+0x6CC (vptr at +0x98; slot 8 is called by cPlayerAttributes). */
struct Unk80189300_Data {
    char pad0[0x98];
};

class Unk80189300 : public Unk80189300_Data {
public:
    virtual void fn_v1();
    virtual void fn_v2();
    virtual void fn_v3();
    virtual int fn_v4();
    virtual void fn_v5();
    virtual struct Unk801527C8_PosHolder* fn_v6();
    virtual void fn_v7();
    virtual void fn_v8(int a);
};

/* Object returned by slot 6 of Unk80189300; a position vector at +0x60. */
struct Unk801527C8_PosHolder {
    char pad0[0x60];
    Unk80273498_Vec3 m60;
};

struct Unk801527C8_A50 {
    char pad0[0x3D44];
    int m3D44;
};

struct Unk801527C8_Actor {
    char pad0[4];
    int m4;
    char pad8[0x3C - 8];
    void* m3C;
    void* m40;
    int m44;
    char pad48[4];
    float m4C;
    Unk801527C8_Sub m50;
    char pad90[0x554 - 0x90];
    Unk8014D8AC* m554;
    char pad558[0x65C - 0x558];
    void* m65C[13];
    char pad690[0x6C0 - 0x690];
    void* m6C0;
    char pad6C4[0x6CC - 0x6C4];
    Unk80189300* m6CC;
    char pad6D0[0x6F4 - 0x6D0];
    int m6F4;
    Unk801527C8_Mgr* m6F8;
    int m6FC;
    Unk801527C8_Slots* m700;
    char pad704[0x738 - 0x704];
    void* m738;
};

struct Unk801527C8_Ctx {
    void fn_8016D2F4(const char* s);
    void fn_8016AC3C();
    Unk80189300* fn_8016C804(int id);
    void* fn_8016C7A8(unsigned int idx);
    char pad0[0xA14];
    int mA14;
    int mA18;
    char padA1C[0xA24 - 0xA1C];
    char mA24[4][10];
    Unk801527C8_Actor* mA4C;
    Unk801527C8_A50* mA50;
    Unk801527C8_Actor* mA54;
};

/* Script-object helper (fn_8016C788 looks up the target object of a command; its
 * goal node is created by fn_802448F4 and published with fn_8015152C). */
struct Unk8016C788_Sub {
    char pad0[0x40];
    int m40, m44, m48, m4C, m50, m54, m58, m5C, m60, m64, m68;
};
struct Unk8016C788_Obj {
    char pad0[0x360];
    Unk8016C788_Sub m360;
};
void fn_8027C728(Unk8027C728_Goal* g);
void fn_80189300(Unk80189300* p, Unk8016C788_Obj* o);
Unk8016C788_Obj* fn_8016C788(Unk801527C8_Ctx* ctx, int a);
Unk8027C728_Goal* fn_802448F4(Unk8016C788_Obj* o, int a);
void fn_8015152C(Unk8016C788_Obj* o, Unk8027C728_Goal* g);

/* Global object lbl_8061FEDC: a state block whose substructure at +0x40 holds
 * a handle at +4 and a float at +0xC (written by cBlendDepthOfField, cSetDepthOfField). */
struct Unk8061FEDC_Sub {
    int m0;
    int m4;
    int m8;
    float mC;
};
struct Unk8061FEDC_Obj {
    char pad0[0x40];
    Unk8061FEDC_Sub m40;
};
extern Unk8061FEDC_Obj* lbl_8061FEDC;

/* Global object lbl_80619D10 (vptr at +0x18; slot 23 is called by cSetOverlay). */
struct Unk80619D10_Data {
    char pad0[0x18];
};

class Unk80619D10 : public Unk80619D10_Data {
public:
    void fn_800AB9A8(int v);
    virtual void fn_v1();
    virtual void fn_v2();
    virtual void fn_v3();
    virtual void fn_v4();
    virtual void fn_v5();
    virtual void fn_v6();
    virtual void fn_v7();
    virtual void fn_v8();
    virtual void fn_v9();
    virtual void fn_v10();
    virtual void fn_v11();
    virtual void fn_v12();
    virtual void fn_v13();
    virtual void fn_v14();
    virtual void fn_v15();
    virtual void fn_v16();
    virtual void fn_v17();
    virtual void fn_v18();
    virtual void fn_v19();
    virtual void fn_v20();
    virtual void fn_v21();
    virtual void fn_v22();
    virtual void fn_v23(int a);
};

/* ---- Script commands (vptr at +0; fields start at +4) ---- */

/* ctor 0x801525F0 (other unit) */
class Unk8033CCE0 {
public:
    Unk8033CCE0();
    float fn_8033CDC4(float t);
    void fn_8033CD74();
    int m0;
    int m4;
    int m8;
};

class cBlendDepthOfField : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cBlendDepthOfField();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
    int m8;
    int mC;
    Unk8033CCE0 m10;
};

class cSimToEndOfPlay : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSimToEndOfPlay();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
};

class cAssignOnDeckBatter : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cAssignOnDeckBatter();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
};

class cScriptStopSavingReplay : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptStopSavingReplay();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
};

class cScriptCrowdCameraFlash : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptCrowdCameraFlash();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
};

/* Object at +0x50 of cGeneralScriptConditional (ctor 0x80151000, other unit). */
class Unk80151000 {
public:
    Unk80151000();
    int m0;
    int m4;
    int m8;
    int mC;
};

class cGeneralScriptConditional : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cGeneralScriptConditional();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
    float m8;
    int mC, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C, m40, m44, m48, m4C;
    Unk80151000 m50;
};

class cGosubRandom : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cGosubRandom();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    struct Entry {
        int mUse;       /* "UseScript%d" */
        int mName;      /* "ScriptName%d" */
    };
    Entry m4[8];
};

class cGosub : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cGosub();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;                    /* "Script" */
};

class cPlayManagerArgumentScript : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cPlayManagerArgumentScript();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
};

class cGoto : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cGoto();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;                    /* "Script" */
};

class cLoop : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cLoop();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
};

class cPause : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cPause();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual float fn_cslot13(float f1);

    float m4;                  /* "MinSeconds" */
    int m8;                    /* "OnlyOneTick" */
};

class cPlayAnimation : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cPlayAnimation();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;                    /* "AnimationState" */
};

class cPlayerAttributes : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cPlayerAttributes();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;                    /* "NoDirt" */
    int m8;                    /* "AttachBall" */
    int mC;                    /* "DetatchBall" */
};

class cScriptIdleGoal : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptIdleGoal();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
    int m8;
    int mC;
    int m10;
};

/* ---- units tu_801547AC / tu_80156714 ---- */

class cScriptReachGoal : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptReachGoal();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    float m4;
    float m8;
    float mC;
    float m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    float m24;
};

class cScriptReplay : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptReplay();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
    int m8;
    int mC;
    float m10;
    float m14;
    int m18;
    Unk8033CCE0 m1C;
};

class cScriptRunGoal : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptRunGoal();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
    float m8;
    float mC;
    float m10;
    int m14;
    int m18;
    float m1C;
};

class cSpawnProcess : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSpawnProcess();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
};

class cScriptUmpireSignal : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptUmpireSignal();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
};

class cScriptWaitGoal : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptWaitGoal();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    float m4;
    float m8;
    float mC;
};

class cSetCamera : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSetCamera();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
};

class cScriptPIP : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptPIP();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
    int m8;
    int mC;
    int m10;
};

class cScriptViewport : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptViewport();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
    int m8;
};

class cSetOverlay : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSetOverlay();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
};

class cTeleportActor : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cTeleportActor();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    char pad4[0x8];
    int mC;
    int m10;
    int m14;
    float m18;
    float m1C;
    float m20;
    Unk80273498_Vec3 m24;
};

class cTransitionWipe : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cTransitionWipe();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
    float m8;
};

struct Unk80156838_Entry {
    int m0;
    float m4;
    char pad8[0x14 - 8];
    int m14;
};

class cWait : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cWait();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);
    int fn_801567CC(Unk80156838_Entry* e);
    int fn_80156838(Unk80156838_Entry* e, int n, float t);
    int fn_80156904(Unk80156838_Entry* e, int n, float t);

    int m4;
    float m8;
    int mC;
    int m10;
};

class cWaitForAnimation : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cWaitForAnimation();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

};

class cHomerunCelebration : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cHomerunCelebration();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

};

class cScriptParticleEffect : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cScriptParticleEffect();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
};

class cWaitForActiveActors : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cWaitForActiveActors();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
    int m8;
};

class cSetDepthOfField : public Unk80359B48 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSetDepthOfField();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_cslot8();
    virtual int fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3);

    int m4;
};

#endif
