/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): animation event classes, first half (cReleaseBall .. cHitByPitch's
 * slot 2). Original file boundary unknown; placeholder.
 *
 * .text 0x802A79BC-0x802A89C8 only: this region's data is interleaved with
 * other parts of the TU, so every data object it uses is declared extern by
 * its lbl_ name (no .rodata/.data split for this unit).
 *
 * Each event class has, in .text order: ctor, slot 2 (attribute registration; empty
 * ones are separate functions), slot 5 (factory `new (heap) cX`), plus the odd
 * slot 12 / slot 14 override. Slots 3/4 (name, hash), slots 14/16 getters and the
 * implicit dtors are in the tail of the unity TU (0x802AB840..0x802ABF18, another
 * unit). Class layout and base classes: include/game/events.h.
 *
 * Matching notes:
 *  - Constructors take the type hash as an immediate; the mid classes' inline
 *    ctors (include/game/events.h) leave only the final vptr store, except where
 *    the Vec4 member ctor sits between (cReleaseBall, cCatchBall, cTouchBase,
 *    cTagRunner, cAccessorize).
 *  - Attribute default values are strings in .rodata of the unity TU, referenced
 *    through the lbl_ externs below ("0" is lbl_805DBD58, "0,1" lbl_805DCD3C).
 */
#include "game/events.h"

/* Strings and constants in the unity TU's .rodata/.sbss (other units own them). */
extern const char lbl_805DBD58[];    /* "0" */
extern const char lbl_805DC6DC[];    /* "Stand" */
extern const char lbl_805DCD3C[];    /* "0,1" */
extern const char lbl_805DE158[];    /* "Direction" */
extern const char lbl_805DE570[];    /* "ThrowDifficulty" */
extern const char lbl_805DE580[];    /* "Routine,Easy,Medium,Hard,Extreme" */
extern const char lbl_805DE5A4[];    /* "ThrowSpeedMPH" */
extern const char lbl_805DE5B4[];    /* "0,120,0" */
extern const char lbl_805DE5BC[];    /* "65" */
extern const char lbl_805DE5C0[];    /* "Type_StJmpDvClmb" */
extern const char lbl_805DE5D4[];    /* "?,Jump,Dive,Climb,Stand,StandStretch,Run,RunStretch,Slide,ComebackerStand" */
extern const char lbl_805DE620[];    /* "Difficulty" */
extern const char lbl_805DE62C[];    /* "Easy" */
extern const char lbl_805DE634[];    /* "-180,180" */
extern const char lbl_805DE640[];    /* "CatchSpread" */
extern const char lbl_805DE64C[];    /* "0,360" */
extern const char lbl_805DE654[];    /* "180" */
extern const char lbl_805DE658[];    /* "Juggle" */
extern const char lbl_805DE660[];    /* "BackHand" */
extern const char lbl_805DE66C[];    /* "BareHand" */
extern const char lbl_805DE678[];    /* "OverShoulder" */
extern const char lbl_805DE688[];    /* "UseDuration" */
extern const char lbl_805DE694[];    /* "Drop" */
extern const char lbl_805DE69C[];    /* "Limb_RfLfRhLh" */
extern const char lbl_805DE6AC[];    /* "RightFoot,LeftFoot,RightHand,LeftHand,RootBone" */
extern const char lbl_805DE6DC[];    /* "TagDirection" */
extern const char lbl_805DE6EC[];    /* "TagSpread" */
extern const char lbl_805DE6FC[];    /* "PlayerSpeed" */
extern const char lbl_805DE708[];    /* "0,4,.1" */
extern const char lbl_805DE710[];    /* "PlayerLeaning" */
extern const char lbl_805DE720[];    /* "-5,5,.1" */
extern const char lbl_805DE728[];    /* "Dirt_Locations" */
extern const char lbl_805DE738[];    /* "Left_Butt" */
extern const char lbl_805DE744[];    /* "Right_Butt" */
extern const char lbl_805DE750[];    /* "Left_Quad" */
extern const char lbl_805DE75C[];    /* "Right_Quad" */
extern const char lbl_805DE768[];    /* "Left_Shin" */
extern const char lbl_805DE774[];    /* "Right_Shin" */
extern const char lbl_805DE780[];    /* "Chest" */
extern const char lbl_805DE788[];    /* "Front_Left_Rip" */
extern const char lbl_805DE798[];    /* "Front_Right_Rip" */
extern const char lbl_805DE7A8[];    /* "Back_Left_Rip" */
extern const char lbl_805DE7B8[];    /* "Back_Right_Rip" */
extern const char lbl_805DE7C8[];    /* "BatInHand" */
extern const char lbl_805DE7D8[];    /* "hitwhere" */
extern const float lbl_805DE6F8;    /* 0.0f (cLeft ctor) */
extern const float lbl_805DE7D4;    /* 0.0f (cRight ctor) */
extern char lbl_806EF9C6;    /* type id of cTouchBase limb 3 (slot 14) */
extern char lbl_806EF9C7;    /* type id of cTouchBase limb 4 (slot 14) */
extern char lbl_806EF9C9;    /* type id of cTouchBase limb 2 (slot 14) */
extern char lbl_806EF9CA;    /* type id of cTouchBase limb 1 (slot 14) */
extern char lbl_806EF9CB;    /* type id of cTouchBase limb 0 (slot 14) */

cReleaseBall::cReleaseBall() : Unk8035EAB4(0x2F71A764u)
{
}

void cReleaseBall::fn_vslot2()
{
    fn_8037B674(lbl_805DE570, &m24, lbl_805DE580, 0);
    fn_8037B50C(lbl_805DE5A4, &m20, lbl_805DE5B4, lbl_805DE5BC);
}

Unk8037B3E8* cReleaseBall::fn_vslot5()
{
    return new (lbl_806EF9B4) cReleaseBall;
}

cSwingContactPhase::cSwingContactPhase() : Unk8035EA80(0x9DB287CDu)
{
}

Unk8037B3E8* cSwingContactPhase::fn_vslot5()
{
    return new (lbl_806EF9B4) cSwingContactPhase;
}

cSwingMisTimedNonContactPhase::cSwingMisTimedNonContactPhase() : Unk8035EA80(0xA47337B4u)
{
}

Unk8037B3E8* cSwingMisTimedNonContactPhase::fn_vslot5()
{
    return new (lbl_806EF9B4) cSwingMisTimedNonContactPhase;
}

cSwingSweetSpot::cSwingSweetSpot() : Unk8035EA80(0xC45471DEu)
{
}

Unk8037B3E8* cSwingSweetSpot::fn_vslot5()
{
    return new (lbl_806EF9B4) cSwingSweetSpot;
}

cSwingBreaksStrikePlane::cSwingBreaksStrikePlane() : Unk8035EA80(0x4881D4AAu)
{
}

Unk8037B3E8* cSwingBreaksStrikePlane::fn_vslot5()
{
    return new (lbl_806EF9B4) cSwingBreaksStrikePlane;
}

cSwingComplete::cSwingComplete() : Unk8035EA80(0xFCF3F4A9u)
{
}

Unk8037B3E8* cSwingComplete::fn_vslot5()
{
    return new (lbl_806EF9B4) cSwingComplete;
}

cCatchBall::cCatchBall() : Unk8035EAB4(0x971949A6u)
{
    m40 = 0;
}

void cCatchBall::fn_vslot2()
{
    fn_8037B674(lbl_805DE5C0, &m20, lbl_805DE5D4, lbl_805DC6DC);
    fn_8037B674(lbl_805DE620, &m24, lbl_805DE580, lbl_805DE62C);
    fn_8037B50C(lbl_805DE158, &m28, lbl_805DE634, lbl_805DBD58);
    fn_8037B50C(lbl_805DE640, &m2C, lbl_805DE64C, lbl_805DE654);
    fn_8037B458(lbl_805DE658, &m30, lbl_805DCD3C, lbl_805DBD58);
    fn_8037B458(lbl_805DE660, &m34, lbl_805DCD3C, lbl_805DBD58);
    fn_8037B458(lbl_805DE66C, &m38, lbl_805DCD3C, lbl_805DBD58);
    fn_8037B458(lbl_805DE678, &m3C, lbl_805DCD3C, lbl_805DBD58);
    fn_8037B458(lbl_805DE688, &m40, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE694, &m44, lbl_805DCD3C, lbl_805DBD58);
}

Unk8037B3E8* cCatchBall::fn_vslot5()
{
    return new (lbl_806EF9B4) cCatchBall;
}

void cCatchBall::fn_evslot12(void* a, int b, float f1, float f2)
{
    if (m40) {
        m48 = f2;
    }
    Unk8038B7E4::fn_evslot12(a, b, f1, f2);
}

cTouchBase::cTouchBase() : Unk8035EAB4(0x8BF0ACA6u)
{
}

void cTouchBase::fn_vslot2()
{
    fn_8037B674(lbl_805DE69C, &m20, lbl_805DE6AC, 0);
}

/* Matching note: assigning a local in each arm and returning it gives retail's
 * per-arm `lbz r0; extsb r3,r0; blr`; a direct `return lbl;` in each arm gives
 * `lbz r3; extsb r3,r3`. The case 0/default arm is laid out first. */
char cTouchBase::fn_evslot14()
{
    char t;

    switch (m20) {
    case 0:
    default:
        t = lbl_806EF9CB;
        break;
    case 1:
        t = lbl_806EF9CA;
        break;
    case 2:
        t = lbl_806EF9C9;
        break;
    case 3:
        t = lbl_806EF9C6;
        break;
    case 4:
        t = lbl_806EF9C7;
        break;
    }
    return t;
}

Unk8037B3E8* cTouchBase::fn_vslot5()
{
    return new (lbl_806EF9B4) cTouchBase;
}

cFirstTouchBase::cFirstTouchBase() : Unk8035EA80(0xCF4ABDEEu)
{
}

void cFirstTouchBase::fn_vslot2()
{
}

Unk8037B3E8* cFirstTouchBase::fn_vslot5()
{
    return new (lbl_806EF9B4) cFirstTouchBase;
}

void cTagRunner::fn_vslot2()
{
    fn_8037B494(lbl_805DE6DC, &m20, lbl_805DE634, lbl_805DBD58);
    fn_8037B494(lbl_805DE6EC, &m24, lbl_805DE64C, lbl_805DE654);
}

cTagRunner::cTagRunner() : Unk8035EAB4(0x440397DEu)
{
}

Unk8037B3E8* cTagRunner::fn_vslot5()
{
    return new (lbl_806EF9B4) cTagRunner;
}

cBlend1::cBlend1() : Unk8035EA80(0x6A552F3Eu)
{
}

Unk8037B3E8* cBlend1::fn_vslot5()
{
    return new (lbl_806EF9B4) cBlend1;
}

cBlend2::cBlend2() : Unk8035EA80(0x6A552F3Fu)
{
}

Unk8037B3E8* cBlend2::fn_vslot5()
{
    return new (lbl_806EF9B4) cBlend2;
}

cBlend3::cBlend3() : Unk8035EA80(0x6A552F40u)
{
}

Unk8037B3E8* cBlend3::fn_vslot5()
{
    return new (lbl_806EF9B4) cBlend3;
}

cLeft::cLeft() : Unk8035EA80(0x0F29E213u)
{
    m8 = m4 = lbl_805DE6F8;
}

void cLeft::fn_vslot2()
{
    fn_8037B50C(lbl_805DE6FC, &m4, lbl_805DE708, lbl_805DBD58);
    fn_8037B50C(lbl_805DE710, &m8, lbl_805DE720, lbl_805DBD58);
}

Unk8037B3E8* cLeft::fn_vslot5()
{
    return new (lbl_806EF9B4) cLeft;
}

cSlide::cSlide() : Unk8035EA80(0xF4E8B1B9u)
{
}

Unk8037B3E8* cSlide::fn_vslot5()
{
    return new (lbl_806EF9B4) cSlide;
}

cDirtEvent::cDirtEvent() : Unk8035EA80(0xF8FAD63Du)
{
    m4 = 0;
    m8 = 0;
    mC = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m1C = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2C = 0;
}

void cDirtEvent::fn_vslot2()
{
    fn_8037B7E8(lbl_805DE728);
    fn_8037B458(lbl_805DE738, &m4, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE744, &m8, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE750, &mC, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE75C, &m10, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE768, &m14, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE774, &m18, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE780, &m1C, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE788, &m20, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE798, &m24, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE7A8, &m28, 0, lbl_805DBD58);
    fn_8037B458(lbl_805DE7B8, &m2C, 0, lbl_805DBD58);
    fn_8037B830(lbl_805DE728);
}

Unk8037B3E8* cDirtEvent::fn_vslot5()
{
    return new (lbl_806EF9B4) cDirtEvent;
}

cSpectacularAnimation::cSpectacularAnimation() : Unk8035EA80(0x429055BFu)
{
}

void cSpectacularAnimation::fn_vslot2()
{
}

Unk8037B3E8* cSpectacularAnimation::fn_vslot5()
{
    return new (lbl_806EF9B4) cSpectacularAnimation;
}

cSignatureHRToFirstCelebration::cSignatureHRToFirstCelebration() : Unk8035EA80(0xE80DB2C7u)
{
}

void cSignatureHRToFirstCelebration::fn_vslot2()
{
}

Unk8037B3E8* cSignatureHRToFirstCelebration::fn_vslot5()
{
    return new (lbl_806EF9B4) cSignatureHRToFirstCelebration;
}

cAccessorize::cAccessorize() : Unk8035EAB4(0x9E3C3363u)
{
    m20 = 0;
}

void cAccessorize::fn_vslot2()
{
    fn_8037B458(lbl_805DE7C8, &m20, 0, 0);
}

Unk8037B3E8* cAccessorize::fn_vslot5()
{
    return new (lbl_806EF9B4) cAccessorize;
}

cRight::cRight() : Unk8035EA80(0xF4D4EC26u)
{
    m8 = m4 = lbl_805DE7D4;
}

void cRight::fn_vslot2()
{
    fn_8037B50C(lbl_805DE6FC, &m4, lbl_805DE708, lbl_805DBD58);
    fn_8037B50C(lbl_805DE710, &m8, lbl_805DE720, lbl_805DBD58);
}

Unk8037B3E8* cRight::fn_vslot5()
{
    return new (lbl_806EF9B4) cRight;
}

cHitByPitch::cHitByPitch() : Unk8035EA80(0x6EC29540u)
{
}

void cHitByPitch::fn_vslot2()
{
    fn_8037B494(lbl_805DE7D8, &m4, lbl_805DCD3C, 0);
}
