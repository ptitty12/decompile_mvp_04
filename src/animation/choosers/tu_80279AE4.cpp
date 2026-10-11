/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11); original file name unknown, placeholder.
 *
 * .text 0x80279AE4-0x8027A84C, .rodata 0x805DCEE8-0x805DCF60,
 * .data 0x8061E69C-0x8061E6A0. The end is where this group's float
 * constants end (the next group's start at 0x805DCF60).
 *
 * cShortestPathChooser: vtable 0x80661EA0 slot 3 (0x802ACB8C) returns the
 * pointer at 0x8061E69C -> "cShortestPathChooser".
 */
#include "game/chooser.h"

/* Class name; read by cShortestPathChooser's vtable slot 3 (0x802ACB8C). */
const char* lbl_8061E69C = "cShortestPathChooser";
extern unsigned int lbl_806EF9D8;     /* hash of the class name, read by slot 4 (0x802ACB98) */

class cShortestPathChooser : public Unk8037B3E8 {
public:
    /* Declared first and defined in the unit at 0x802AC8xx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cShortestPathChooser();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);
};

cShortestPathChooser::cShortestPathChooser() : Unk8037B3E8(lbl_8061E69C)
{
    lbl_806EF9D8 = fn_80378568(lbl_8061E69C, 0);
}

void cShortestPathChooser::fn_vslot2()
{
}

Unk8037B3E8* cShortestPathChooser::fn_vslot5()
{
    return new (lbl_806EF9B4) cShortestPathChooser;
}

int cShortestPathChooser::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    out->type = 0;
    out->id = 0;
    out->m14 = 1.0f;
    return Unk8037B3E8::fn_vslot17(out, obj, c, d, e, f);
}
