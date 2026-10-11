/*
 * Translation unit at 0x80271748 (original file name unknown; placeholder).
 * Directory: between animation/choosers/playeridchooser.cpp and
 * animation/choosers/randomloadedchooser.cpp, and the same chooser pattern.
 *
 * .text 0x80271748-0x80271940, .rodata 0x805DC644-0x805DC67C,
 * .data 0x8061E650-0x8061E654.
 *
 * cEventChooser: vtable 0x80662328 slot 3 (0x802AC96C) returns the pointer at
 * 0x8061E650 -> "cEventChooser".
 */
#include "game/chooser_base.h"

extern unsigned int lbl_8068D57C; /* cEventChooser type hash */

/* Class name; read by cEventChooser's vtable slot 3 (0x802AC96C). */
const char* lbl_8061E650 = "cEventChooser";

class cEventChooser : public Unk80362C2C {
public:
    /* Declared first and defined in the unit at 0x802AC8xx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cEventChooser();
    virtual ~cEventChooser();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);

    int m4;                    /* m8 filled */
    Unk80384F28 m8;            /* "eventanimpairlist"/"eventanimpairs" */
};

cEventChooser::cEventChooser() : Unk80362C2C(lbl_8068D57C)
{
    m4 = 0;
}

void cEventChooser::fn_vslot2()
{
    fn_8037B728("eventanimpairlist", "eventanimpairs", &m8, 0);
}

cEventChooser::~cEventChooser()
{
}

Unk8037B3E8* cEventChooser::fn_vslot5()
{
    return new (lbl_806EF9B4) cEventChooser;
}

int cEventChooser::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    Unk80270BA0_X* x = obj->fn_vslot1();

    if (!m4) {
        m4 = 1;
        m8.fn_80385344(lbl_805DC0E4);
        m8.fn_80385344(lbl_805DC0F8);
    }
    out->type = 1;
    out->id = m8.fn_803851A0(f, 0);
    out->m14 = 1.0f;
    return Unk8037B3E8::fn_vslot17(out, x, c, d, e, f);
}
