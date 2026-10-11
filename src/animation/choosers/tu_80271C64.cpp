/*
 * Translation unit at 0x80271C64 (original file name unknown; placeholder).
 * Same directory evidence as animation/choosers/tu_80271748.cpp.
 *
 * .text 0x80271C64-0x80271F14, .rodata 0x805DC6C4-0x805DC70C,
 * .data 0x8061E660-0x8061E66C.
 *
 * cPitchChooser: vtable 0x806621F8 slot 3 (0x802ACA14) returns the pointer at
 * 0x8061E660 -> "cPitchChooser".
 */
#include "game/chooser_base.h"

/* Class name; read by cPitchChooser's vtable slot 3 (0x802ACA14). */
const char* lbl_8061E660 = "cPitchChooser";
unsigned int lbl_8061E664 = 0;    /* hash of "Stretch" */
unsigned int lbl_8061E668 = 0;    /* hash of "Stand" */

/* Global (not a literal): 0x802A7D6C in another unit loads this address. */
extern const char lbl_805DC6DC[];

class cPitchChooser : public Unk80362C2C {
public:
    /* Declared first and defined in the unit at 0x802AC8xx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cPitchChooser();
    virtual ~cPitchChooser();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);

    int m4;                    /* m8 filled */
    Unk80384F28 m8;            /* "pitchanimpairlist"/"pitchanimpairs" */
};

cPitchChooser::cPitchChooser() : Unk80362C2C(lbl_8061E660)
{
    if (!lbl_8061E664 || !lbl_8061E668) {
        lbl_8061E664 = fn_80378568("Stretch", 7);
        lbl_8061E668 = fn_80378568(lbl_805DC6DC, 5);
    }
    m4 = 0;
}

/* Defined here, after the constructor: retail places it between the
 * constructor's "Stretch" literal and fn_vslot2's literals. */
const char lbl_805DC6DC[] = "Stand";

void cPitchChooser::fn_vslot2()
{
    fn_8037B728("pitchanimpairlist", "pitchanimpairs", &m8, 0);
}

cPitchChooser::~cPitchChooser()
{
}

Unk8037B3E8* cPitchChooser::fn_vslot5()
{
    return new (lbl_806EF9B4) cPitchChooser;
}

int cPitchChooser::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    int stretch = 0;
    Unk80270BA0_X* x = obj->fn_vslot1();
    Unk8014D8AC_Ctx* ctx = x->m618->m880;
    unsigned int key;

    if (ctx->m6F4 == 1) {
        if (fn_8024DCFC(x->mB50)) {
            stretch = 1;
        }
    } else if (!fn_8024D4C0(x)) {
        stretch = fn_8022E998(ctx->m700->m3B0);
    }
    key = stretch ? lbl_8061E664 : lbl_8061E668;
    if (!m4) {
        m4 = 1;
        m8.fn_80385344(lbl_805DC0E4);
        m8.fn_80385344(lbl_805DC0F8);
    }
    out->type = 1;
    out->id = m8.fn_803851A0(key, 0);
    out->m14 = 1.0f;
    return Unk8037B3E8::fn_vslot17(out, x, c, d, e, f);
}
