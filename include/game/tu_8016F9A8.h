#ifndef GAME_TU_8016F9A8_H
#define GAME_TU_8016F9A8_H

/*
 * Declarations for game/tu_8016F9A8.cpp (reconstructed; placeholders only).
 * The script/camera command classes of the second half of the unity-TU tail
 * (see game/tu_8016F45C.h) and the record class built at 0x8016FF40.
 */
#include "game/tu_8016F45C.h"

class cScriptReplay : public Unk80359B48 {
public:
    virtual ~cScriptReplay();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    char pad4[0x18];   /* root/mid data, size not known */
    Unk8033CD28 m1C;
};

class cScriptRunGoal : public Unk80359B48 {
public:
    virtual ~cScriptRunGoal();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cSpawnProcess : public Unk80359B48 {
public:
    virtual ~cSpawnProcess();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual void fn_vslot8();
};

class cScriptUmpireSignal : public Unk80359B48 {
public:
    virtual ~cScriptUmpireSignal();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cScriptWaitGoal : public Unk80359B48 {
public:
    virtual ~cScriptWaitGoal();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cSetCamera : public Unk80359B48 {
public:
    virtual ~cSetCamera();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cScriptPIP : public Unk80359B48 {
public:
    virtual ~cScriptPIP();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cScriptViewport : public Unk80359B48 {
public:
    virtual ~cScriptViewport();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cSetOverlay : public Unk80359B48 {
public:
    virtual ~cSetOverlay();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cTeleportActor : public Unk80359B48 {
public:
    virtual ~cTeleportActor();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cTransitionWipe : public Unk80359B48 {
public:
    virtual ~cTransitionWipe();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cWait : public Unk80359B48 {
public:
    virtual ~cWait();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cWaitForAnimation : public Unk80359B48 {
public:
    virtual ~cWaitForAnimation();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cHomerunCelebration : public Unk80359B48 {
public:
    virtual ~cHomerunCelebration();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cScriptParticleEffect : public Unk80359B48 {
public:
    virtual ~cScriptParticleEffect();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cWaitForActiveActors : public Unk80359B48 {
public:
    virtual ~cWaitForActiveActors();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cSetDepthOfField : public Unk80359B48 {
public:
    virtual ~cSetDepthOfField();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cScriptLoadAnimations : public Unk80359B48 {
public:
    virtual ~cScriptLoadAnimations();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

/* C library style helpers (placeholders; see the extern "C" declarations in
 * game/tu_800057D8.cpp, which this unit's records are shared with). */
extern "C" {
void fn_8040074C(void* p, unsigned n);                  /* clears n bytes */
}
void fn_8016E1B4(int a, int b);

/* Entry returned by fn_80170034(info, idx): {buffer pointer, size}. */
struct Unk8016FF40_Entry {
    int m0;
    int m4;
};

/* Record with a vptr at +0x124 (ctor 0x8016FF40, deleting dtor 0x80170000).
 * Evidence: the ctor clears +0, +0x8..0x14, +0x118, +0x11C, runs four
 * initializers on the embedded text buffers (+0xE4, +0xAE, +0x18, +0x78, +0x8E)
 * and stores {+0x50, 0xB0} at +0x100, +0x104 and &m100 in the table at +0x108;
 * 0x80170034 reads +0x108[i]. tu_800057D8 calls it Unk80170034_Info. */
class Unk8016FF40 {
public:
    Unk8016FF40();
    virtual ~Unk8016FF40();
    int fn_80170044(int x);
    int fn_80170218(Unk8016FF40* other);
    int fn_80170248();
    void fn_801702A4();
    void fn_80170420(int p, int n, int* out);
    int m0;
    int m4;
    int m8[4];
    unsigned short m18[0x1B];
    char pad4E[2];
    int m50[4];                  /* 0x50..0x100 is cleared as one 0xB0-byte block */
    int m60[4];
    char pad70[4];
    int m74;
    unsigned short m78[0xB];
    unsigned short m8E[0x10];
    unsigned short mAE[0x1B];
    char mE4[0x1C];
    Unk8016FF40_Entry m100;
    Unk8016FF40_Entry* m108[6];
    int m120;
};

extern "C" {
Unk8016FF40_Entry* fn_80170034(Unk8016FF40* info, int idx);
void fn_8017008C(Unk8016FF40* info, const char* name);
void fn_801700D8(Unk8016FF40* info, unsigned short* ws);
void fn_80170158(Unk8016FF40* info, unsigned short* ws);
void fn_801701B4(Unk8016FF40* info, unsigned short* ws, int a);
void fn_8017037C(Unk8016FF40* info);
}

#endif
