/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11); original file name unknown, placeholder.
 *
 * .text 0x802A3704-0x802A4584, .rodata 0x805DE11C-0x805DE2F8, .data 0x8061E86C-0x8061E87C.
 *
 * Classes (names from vtable slot 3 -> name pointer -> string):
 * cCycleTimeWarp (vtable 0x80661E20), cGeneralRotationWarp (0x80661DA0),
 * cSetPosRotWarp (0x80661D20), cFudgePosRotWarp (0x80661CA0).
 *
 * All four derive from Unk8035EAE8 (dtor 0x8035EAE8, slots 11-14 empty
 * functions at 0x8035EB08..0x8035EB14), which derives from the root Unk8037B3E8
 * (see include/game/warp.h). The warps' ctors call the root ctor directly
 * (the mid class has an inline ctor), and the dtors pass their in-charge
 * argument on to fn_8035EAE8. Slot 3/4 and the vtables sit in the unity TU's
 * tail (0x802ACBA4..0x802ACBF8).
 */
#include "game/warp.h"

/* Class name; read by cCycleTimeWarp's vtable slot 3 (0x802ACBA4). */
const char* lbl_8061E86C = "cCycleTimeWarp";

class cCycleTimeWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cCycleTimeWarp();
    virtual void fn_vslot2();
    virtual ~cCycleTimeWarp();
    virtual void fn_vslot12(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h);
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* "enabled" */
};

cCycleTimeWarp::cCycleTimeWarp() : Unk8035EAE8(0x395EE741u)
{
    m4 = 1;
}

void cCycleTimeWarp::fn_vslot2()
{
    fn_8037B458("enabled", &m4, 0, 0);
}

cCycleTimeWarp::~cCycleTimeWarp()
{
}

void cCycleTimeWarp::fn_vslot12(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h)
{
    float total = 0.0f;

    if (m4) {
        int n = h->count;

        for (int i = 0; i < n; i++) {
            total += e[i].m1C;
        }
        if (total != 0.0f) {
            float acc = 0.0f;

            total = 1.0f / total;
            for (int i = 0; i < n; i++) {
                acc += (e[i].m10 - e[i].m14) * total * e[i].m1C;
            }
            for (int i = 0; i < n; i++) {
                e[i].m10 = e[i].m14 + acc;
            }
        }
    }
}

Unk8037B3E8* cCycleTimeWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cCycleTimeWarp;
}

/* Class name; read by cGeneralRotationWarp's vtable slot 3 (0x802ACBBC). */
const char* lbl_8061E870 = "cGeneralRotationWarp";

extern unsigned int lbl_8068D5A4;    /* type hash, set by the static initializer fn_802AA7A4 */

class cGeneralRotationWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cGeneralRotationWarp();
    virtual void fn_vslot2();
    virtual ~cGeneralRotationWarp();
    virtual void fn_vslot13(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    float m4;                  /* "Direction" */
};

cGeneralRotationWarp::cGeneralRotationWarp() : Unk8035EAE8(lbl_8068D5A4)
{
    m4 = 0.0f;
}

void cGeneralRotationWarp::fn_vslot2()
{
    fn_8037B50C("Direction", &m4, "-6.29,6.29,3", 0);
}

cGeneralRotationWarp::~cGeneralRotationWarp()
{
}

void cGeneralRotationWarp::fn_vslot13(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h, Unk80270BA0_Obj* obj)
{
    char buf[0x220];           /* unused local that retail allocates (frame 0x228); real type unknown */
    obj->fn_vslot1();
}

Unk8037B3E8* cGeneralRotationWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cGeneralRotationWarp;
}

/* Class name; read by cSetPosRotWarp's vtable slot 3 (0x802ACBD4). */
const char* lbl_8061E874 = "cSetPosRotWarp";

extern unsigned int lbl_8068D5A8;    /* type hash, set by the static initializer fn_802AA7A4 */

class cSetPosRotWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cSetPosRotWarp();
    virtual void fn_vslot2();
    virtual ~cSetPosRotWarp();
    virtual void fn_vslot13(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* "SetPos" */
    int m8;                    /* "SetDir" */
};

cSetPosRotWarp::cSetPosRotWarp() : Unk8035EAE8(lbl_8068D5A8)
{
    m8 = 0;
    m4 = 0;
}

void cSetPosRotWarp::fn_vslot2()
{
    fn_8037B458("SetDir", &m8, 0, 0);
    fn_8037B458("SetPos", &m4, 0, 0);
}

cSetPosRotWarp::~cSetPosRotWarp()
{
}

void cSetPosRotWarp::fn_vslot13(Unk802A37B4_Entry* e, Unk802A37B4_Hdr* h, Unk80270BA0_Obj* obj)
{
    int n = h->count;

    if (e->m10 < e->m14 || e->m14 == 0.0f || n == 0) {
        Unk80270BA0_X* x = obj->fn_vslot1();

        if (m4) {
            x->fn_vslot3(x->GetM320());
        }
        if (m8) {
            x->fn_80244858(x->GetM32C().y);
        }
    }
}

Unk8037B3E8* cSetPosRotWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cSetPosRotWarp;
}

/* Class name; read by cFudgePosRotWarp's vtable slot 3 (0x802ACBEC). */
const char* lbl_8061E878 = "cFudgePosRotWarp";

class cFudgePosRotWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cFudgePosRotWarp();
    virtual void fn_vslot2();
    virtual ~cFudgePosRotWarp();
    virtual void fn_vslot11(Unk802A3D8C_State* st, Unk80270BA0_Obj* obj);
    virtual void fn_vslot14(Unk80270BA0_Obj* obj, Unk8037B128* b);
    virtual Unk8037B3E8* fn_vslot5();
    void fn_802A3D8C(const Unk80273498_Vec3& a, Unk802A3D8C_State* st, Unk80270BA0_X* x, int flag, int n, const Unk80273498_Vec3& pos, float yaw);

    int m4;                    /* "Start" */
    int m8;                    /* "End" */
    int mC;                    /* "Enter" */
    int m10;                   /* "Target" */
};

cFudgePosRotWarp::cFudgePosRotWarp() : Unk8035EAE8(0x1B26D314u)
{
}

void cFudgePosRotWarp::fn_vslot2()
{
    fn_8037B638("Start", &m4, "_start_time_event_,Start,cReleaseBall,cCatchBall,cTouchBase,cBeginWarp");
    fn_8037B638("End", &m8, "_end_time_event_,End,cReleaseBall,cCatchBall,cTouchBase,cEndWarp");
    fn_8037B638("Enter", &mC, "_enter_event_,Start,cBlend1,cBlend2,cBlend3,cBeginWarp");
    fn_8037B638("Target", &m10, "_target_event_,End,cReleaseBall,cCatchBall,cTouchBase,cEndWarp");
}

cFudgePosRotWarp::~cFudgePosRotWarp()
{
}

void cFudgePosRotWarp::fn_vslot11(Unk802A3D8C_State* st, Unk80270BA0_Obj* obj)
{
    Unk80270BA0_X* x = obj->fn_vslot1();
    Unk80273498_Vec3 a = x->GetM93C();
    Unk80273498_Vec3 pos = x->m60;

    fn_802A3D8C(a, st, x, 1, x->m618->m838, pos, fn_80382BB8(x->m618));
}

/* Not matched yet: empty placeholder (0x744 bytes in retail). */
void cFudgePosRotWarp::fn_802A3D8C(const Unk80273498_Vec3& a, Unk802A3D8C_State* st, Unk80270BA0_X* x, int flag, int n, const Unk80273498_Vec3& pos, float yaw)
{
}

void cFudgePosRotWarp::fn_vslot14(Unk80270BA0_Obj* obj, Unk8037B128* b)
{
    Unk80273498_Vec3 pos = b->fn_8037B128();
    float yaw = b->fn_8037B1F0();
    Unk80270BA0_X* x = obj->fn_vslot1();

    fn_802A3D8C(b->mA4, &b->m44, x, 0, b->mA0, pos, yaw);
}

Unk8037B3E8* cFudgePosRotWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cFudgePosRotWarp;
}
