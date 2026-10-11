/*
 * Game code, .text 0x8016F9A8-... (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8016F9A8.h"

extern const char lbl_805C8424[];
extern const char lbl_805C8520[];
extern const char lbl_805C8584[];
extern const char lbl_805C8594[];
extern const char lbl_805C85B8[];
extern const char lbl_805C8644[];
extern const char lbl_805C8690[];
extern const char lbl_805C86E8[];
extern const char lbl_805C8704[];
extern const char lbl_805C8870[];
extern const char lbl_805C8954[];
extern const char lbl_805C897C[];
extern const char lbl_805C8A0C[];
extern const char lbl_805C8A20[];
extern const char lbl_805C8A54[];
extern const char lbl_805C8BC8[];
extern const char lbl_805C8C08[];
extern const char lbl_805C9440[];
extern const char lbl_805C8954[];
extern int lbl_8068B7D8;

int cScriptReachGoal::fn_vslot4() { return 0x88EC4E63; }
cScriptReplay::~cScriptReplay() {}
const char* cScriptReplay::fn_vslot3() { return lbl_805C8424; }
int cScriptReplay::fn_vslot4() { return 0x2916F5EA; }
cScriptRunGoal::~cScriptRunGoal() {}
const char* cScriptRunGoal::fn_vslot3() { return lbl_805C8520; }
int cScriptRunGoal::fn_vslot4() { return 0x710FFB15; }
cSpawnProcess::~cSpawnProcess() {}
const char* cSpawnProcess::fn_vslot3() { return lbl_805C8584; }
int cSpawnProcess::fn_vslot4() { return lbl_8068B7D8; }
void cSpawnProcess::fn_vslot8() {}
cScriptUmpireSignal::~cScriptUmpireSignal() {}
const char* cScriptUmpireSignal::fn_vslot3() { return lbl_805C8594; }
int cScriptUmpireSignal::fn_vslot4() { return 0xD0D5A56D; }
cScriptWaitGoal::~cScriptWaitGoal() {}
const char* cScriptWaitGoal::fn_vslot3() { return lbl_805C85B8; }
int cScriptWaitGoal::fn_vslot4() { return 0x243A95F5; }
cSetCamera::~cSetCamera() {}
const char* cSetCamera::fn_vslot3() { return lbl_805C8644; }
int cSetCamera::fn_vslot4() { return 0x44DB939D; }
cScriptPIP::~cScriptPIP() {}
const char* cScriptPIP::fn_vslot3() { return lbl_805C8690; }
int cScriptPIP::fn_vslot4() { return 0x2C1A5FC6; }
cScriptViewport::~cScriptViewport() {}
const char* cScriptViewport::fn_vslot3() { return lbl_805C86E8; }
int cScriptViewport::fn_vslot4() { return 0x96C2CBDD; }
cSetOverlay::~cSetOverlay() {}
const char* cSetOverlay::fn_vslot3() { return lbl_805C8704; }
int cSetOverlay::fn_vslot4() { return 0xAC7B7956; }
cTeleportActor::~cTeleportActor() {}
const char* cTeleportActor::fn_vslot3() { return lbl_805C8870; }
int cTeleportActor::fn_vslot4() { return 0xEE89A570; }
cTransitionWipe::~cTransitionWipe() {}
const char* cTransitionWipe::fn_vslot3() { return lbl_805C8954; }
int cTransitionWipe::fn_vslot4() { return fn_80378568(lbl_805C8954, 0); }
cWait::~cWait() {}
const char* cWait::fn_vslot3() { return lbl_805C897C; }
int cWait::fn_vslot4() { return 0xF2FD99D; }
cWaitForAnimation::~cWaitForAnimation() {}
const char* cWaitForAnimation::fn_vslot3() { return lbl_805C8A0C; }
int cWaitForAnimation::fn_vslot4() { return 0x3C5D0164; }
cHomerunCelebration::~cHomerunCelebration() {}
const char* cHomerunCelebration::fn_vslot3() { return lbl_805C8A20; }
int cHomerunCelebration::fn_vslot4() { return 0xECDFF60E; }
cScriptParticleEffect::~cScriptParticleEffect() {}
const char* cScriptParticleEffect::fn_vslot3() { return lbl_805C8A54; }
int cScriptParticleEffect::fn_vslot4() { return 0x1A5105BE; }
cWaitForActiveActors::~cWaitForActiveActors() {}
const char* cWaitForActiveActors::fn_vslot3() { return lbl_805C8BC8; }
int cWaitForActiveActors::fn_vslot4() { return 0xDC217F0C; }
cSetDepthOfField::~cSetDepthOfField() {}
const char* cSetDepthOfField::fn_vslot3() { return lbl_805C8C08; }
int cSetDepthOfField::fn_vslot4() { return 0x98373702; }
cScriptLoadAnimations::~cScriptLoadAnimations() {}
const char* cScriptLoadAnimations::fn_vslot3() { return lbl_805C9440; }
int cScriptLoadAnimations::fn_vslot4() { return 0x339C4BD0; }

void fn_8016FF14()
{
    fn_8016E1B4(1, 0xFFFF);
}

Unk8016FF40::Unk8016FF40()
{
    m0 = 0;
    m108[4] = 0;
    m108[5] = 0;
    for (int i = 0; i < 4; i++) {
        m8[i] = 0;
    }
    fn_8040074C(m50, 0xB0);
    fn_8017008C(this, 0);
    fn_801700D8(this, 0);
    fn_80170158(this, 0);
    fn_801701B4(this, 0, 0);
    m100.m0 = (int)m50;
    m100.m4 = 0xB0;
    m108[0] = &m100;
}

Unk8016FF40::~Unk8016FF40() {}

Unk8016FF40_Entry* fn_80170034(Unk8016FF40* info, int idx)
{
    return info->m108[idx];
}
