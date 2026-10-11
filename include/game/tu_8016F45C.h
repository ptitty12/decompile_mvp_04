#ifndef GAME_TU_8016F45C_H
#define GAME_TU_8016F45C_H

/*
 * Declarations for game/tu_8016F45C.cpp and tu_8016F9A8.cpp (reconstructed;
 * placeholders only). The script/camera command classes of the g++ 2.95
 * unity-TU tail (0x8016F45C..0x8016FF10): each class contributes its implicit
 * destructor (vtable slot 1), slot 3 (class name string), slot 4 (type hash)
 * and sometimes the empty slots 2 and 8, in vtable order.
 *
 * Evidence: vtables at 0x8065D888..0x8065E8F0 (one per class, 0x78 bytes,
 * laid out in reverse source order), whose slots 1..4 and 8 point at these
 * functions; slot 3 returns a "cXxx" string, slot 4 a constant or global.
 * Every class stores the vptr of Unk80359B48 (vtable 0x8065EC68) and then
 * calls the root destructor 0x8037B424, so the mid class is data-less with an
 * inline `{}` destructor. Slots 2..5 are __pure_virtual (0x804144B8) in it.
 */

/* Root (vtable 0x806849D0, destructor 0x8037B424). Slots 6..10 are empty
 * virtuals (0x8037D750..0x8037D760). */
class Unk8037B3E8 {
public:
    virtual ~Unk8037B3E8();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
};

/* Script command base (vtable 0x8065EC68, destructor 0x80359B48 is an inline `{}`). */
class Unk80359B48 : public Unk8037B3E8 {
public:
    virtual ~Unk80359B48() {}
    virtual void fn_vslot2() = 0;
    virtual const char* fn_vslot3() = 0;
    virtual int fn_vslot4() = 0;
    virtual Unk8037B3E8* fn_vslot5() = 0;
};

unsigned int fn_80378568(const char* token, int len);

/* Member with an out-of-line destructor (80151048), size not known. */
class Unk80151048 {
public:
    ~Unk80151048();
    char m0[4];
};

/* Member with an out-of-line destructor (8033CD28), size not known. */
class Unk8033CD28 {
public:
    ~Unk8033CD28();
    char m0[4];
};

class cBlendCameras : public Unk80359B48 {
public:
    virtual ~cBlendCameras();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cDebugPrint : public Unk80359B48 {
public:
    virtual ~cDebugPrint();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cBlendDepthOfField : public Unk80359B48 {
public:
    virtual ~cBlendDepthOfField();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    char pad4[0xC];   /* root/mid data, size not known */
    Unk8033CD28 m10;
};

class cSimToEndOfPlay : public Unk80359B48 {
public:
    virtual ~cSimToEndOfPlay();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual void fn_vslot8();
};

class cAssignOnDeckBatter : public Unk80359B48 {
public:
    virtual ~cAssignOnDeckBatter();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cScriptStopSavingReplay : public Unk80359B48 {
public:
    virtual ~cScriptStopSavingReplay();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual void fn_vslot8();
};

class cScriptCrowdCameraFlash : public Unk80359B48 {
public:
    virtual ~cScriptCrowdCameraFlash();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual void fn_vslot8();
};

class cGeneralScriptConditional : public Unk80359B48 {
public:
    virtual ~cGeneralScriptConditional();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    char pad4[0x4C];   /* root/mid data, size not known */
    Unk80151048 m50;
};

class cGosubRandom : public Unk80359B48 {
public:
    virtual ~cGosubRandom();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cGosub : public Unk80359B48 {
public:
    virtual ~cGosub();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cPlayManagerArgumentScript : public Unk80359B48 {
public:
    virtual ~cPlayManagerArgumentScript();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cGoto : public Unk80359B48 {
public:
    virtual ~cGoto();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cLoop : public Unk80359B48 {
public:
    virtual ~cLoop();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cPause : public Unk80359B48 {
public:
    virtual ~cPause();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cPlayAnimation : public Unk80359B48 {
public:
    virtual ~cPlayAnimation();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cPlayerAttributes : public Unk80359B48 {
public:
    virtual ~cPlayerAttributes();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cScriptIdleGoal : public Unk80359B48 {
public:
    virtual ~cScriptIdleGoal();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cScriptReachGoal : public Unk80359B48 {
public:
    virtual ~cScriptReachGoal();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

#endif
