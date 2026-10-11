/*
 * Translation unit at 0x80271940 (original file name unknown; placeholder).
 * Same directory evidence as animation/choosers/tu_80271748.cpp.
 *
 * .text 0x80271940-0x80271C64, .rodata 0x805DC67C-0x805DC6C4,
 * .data 0x8061E654-0x8061E660.
 *
 * cHandChooser: vtable 0x80662290 slot 3 (0x802AC98C) returns the pointer at
 * 0x8061E654 -> "cHandChooser".
 */
#include "game/chooser.h"

/* Class name; read by cHandChooser's vtable slot 3 (0x802AC98C). */
const char* lbl_8061E654 = "cHandChooser";
unsigned int lbl_8061E658 = 0;    /* hash of "Left" */
unsigned int lbl_8061E65C = 0;    /* hash of "Right" */

class cHandChooser : public Unk8037B3E8 {
public:
    /* Declared first and defined in the unit at 0x802AC8xx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cHandChooser();
    virtual ~cHandChooser();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    void fn_80271A98();
    virtual void fn_vslot16(int a);
    virtual int fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);

    int m4;                    /* m8 filled */
    Unk80384F28 m8;            /* "handanimpairlist"/"handanimpairs" */
};

cHandChooser::cHandChooser() : Unk8037B3E8(lbl_8061E654)
{
    if (!lbl_8061E658 || !lbl_8061E65C) {
        lbl_8061E658 = fn_80378568("Left", 4);
        lbl_8061E65C = fn_80378568("Right", 5);
    }
    m4 = 0;
}

void cHandChooser::fn_vslot2()
{
    fn_8037B728("handanimpairlist", "handanimpairs", &m8, 0);
}

cHandChooser::~cHandChooser()
{
}

Unk8037B3E8* cHandChooser::fn_vslot5()
{
    return new (lbl_806EF9B4) cHandChooser;
}

void cHandChooser::fn_80271A98()
{
    if (!m4) {
        m4 = 1;
        m8.fn_80385344(lbl_805DC0E4);
        m8.fn_80385344(lbl_805DC0F8);
    }
}

void cHandChooser::fn_vslot16(int a)
{
    fn_80271A98();
    m8.fn_803852FC(a);
}

int cHandChooser::fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return fn_vslot17(out, obj, 1, 0, 0, 0);
}

int cHandChooser::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    Unk80270BA0_X* x = obj->fn_vslot1();
    unsigned int key = x->fn_vslot4() ? lbl_8061E658 : lbl_8061E65C;

    fn_80271A98();
    out->type = 1;
    out->id = m8.fn_803851A0(key, 0);
    out->m14 = 1.0f;
    return Unk8037B3E8::fn_vslot17(out, x, c, d, e, f);
}
