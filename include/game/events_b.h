/*
 * Shared declarations for the animation event classes, second half
 * (animation/events/tu_802A89C8.cpp). Reconstructed; see include/game/chooser.h
 * for the conventions. Nothing here comes from original headers.
 *
 * Hierarchy (from the vtables and the tail-of-TU destructors):
 *   Unk8037B3E8 (root, ctor 0x8037B3E8, vtable 0x806849D0, slots 1-10)
 *     <- Unk8038B7E4 (event mid class: vtable 0x806850A0, dtor 0x8038B7E4)
 *          <- the event classes (cStartSwing, cEndWarp, cFacialAnim, ...).
 * The mid class vtable adds slot 11 (pure; the events implement it with
 * 0x8035EA80, which calls slot 14, the event type id), slot 12 (default
 * 0x8037E68C: dispatches the event through 0x8037893C with its type id) and
 * slot 13 (0x8038B814, returns 0). The event classes add slot 14 (type id).
 * chooser.h's root class folds the choosers' slots 11-17 into itself, so the
 * slot numbers below do not match retail; none of the code in the unit makes
 * a virtual call, so this does not show.
 *
 * The event classes' ctors call the root ctor directly (the mid ctor is
 * inline). Slots 1 (implicit dtor), 3 (name), 4 (hash) and 14 (type id) of each
 * event class live in the unity-TU tail (0x802AC2CC..), together with the
 * vtable; each class declares slot 3/4 first so that g++ emits no vtable here.
 */
#ifndef GAME_EVENTS_B_H
#define GAME_EVENTS_B_H

#include "game/chooser.h"

/* First argument of 0x8037893C (the event dispatcher): word at +4 is the head
 * of a chain of handlers (table stride 0x14, index -1 ends it). Third argument is the
 * event; fifth is an optional extra target (null-checked). */
struct Unk8037893C_Mgr;
struct Unk8037893C_Target;
class Unk8038B7E4;
void fn_8037893C(Unk8037893C_Mgr* mgr, int type, Unk8038B7E4* ev, int arg, Unk8037893C_Target* t);

/* Event mid class: vtable 0x806850A0, dtor 0x8038B7E4 (stores the vptr and calls
 * the root dtor 0x8037B424). The ctor is inline, so the event classes call the
 * root ctor directly and only their own vptr store remains. */
class Unk8038B7E4 : public Unk8037B3E8 {
public:
    Unk8038B7E4(unsigned int hash) : Unk8037B3E8(hash) {}
};

/* Globals set by the static initializer fn_802AA7A4 (hashes of the event
 * class names that are not constants in the ctors). */
extern unsigned int lbl_8068D5C0;
extern unsigned int lbl_8068D5C4;
extern int lbl_8068D5C8;          /* compared with cHandAnim::m4 (signed) */
extern int lbl_8068D5CC;
extern unsigned int lbl_8068D5D0;
extern unsigned int lbl_8068D5D4;
extern unsigned int lbl_8068D5D8;
extern unsigned int lbl_8068D5DC;

extern const float lbl_805DE7F0;   /* 1.0f, used by the ctor of the head-tracking event */
extern const float lbl_805DE848;   /* 1.0f, used by cSwitchBallHand */

extern const char lbl_805DE7E4[];  /* "AnimState" */
extern const char lbl_805DE7F4[];  /* "HeadTrackingOnOff" */
extern const char lbl_805DE808[];  /* "DurationSeconds" */
extern const char lbl_805DE818[];  /* "0,10,.01" */
extern const char lbl_805DE824[];  /* "SecondsToTurn" */
extern const char lbl_805DE834[];  /* "0,2,.01" */
extern const char lbl_805DE83C[];  /* "LaunchHat" */
extern const char lbl_805DE84C[];  /* "TriggerType" */
extern const char lbl_805DE858[];  /* "UmpireSafe,UmpireSafeClose,..." */
extern const char lbl_805DCD6C[];  /* "1" */
extern const char lbl_805DBC10[];  /* 0x148-byte block shared with cMatrixChooser */
extern const char lbl_805DBD58[];  /* 0x34-byte block */

#endif /* GAME_EVENTS_B_H */
