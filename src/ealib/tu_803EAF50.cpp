/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803EAF50-0x803EB2AC (code-only unit, 3 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 *
 * fn_803EB000 is not written: it is a hand-scheduled paired-single matrix kernel (ps_muls0 / ps_madds0 on
 * f14-f24, with r14 as a base register); that needs instructions only the original code can emit.
 */

extern char lbl_8060DABC[];
extern char lbl_8060DAE0[];
extern char lbl_8060DB00[];
extern char lbl_8060DB20[];
extern char lbl_8060DB44[];
extern char lbl_8060DB6C[];
extern char lbl_806AA990[];
extern char lbl_806AA9D0[];
extern char lbl_806AAA10[];
extern char lbl_806AAA50[];
extern char lbl_806AAA90[];
extern char lbl_806AAAD0[];

extern "C" char* fn_803E9B3C(const char* name, void* value);

/* registers six named objects in the table at lbl_806AAB6C */
extern "C" void fn_803EAF50()
{
    fn_803E9B3C(lbl_8060DABC, lbl_806AA990);
    fn_803E9B3C(lbl_8060DAE0, lbl_806AA9D0);
    fn_803E9B3C(lbl_8060DB00, lbl_806AAA10);
    fn_803E9B3C(lbl_8060DB20, lbl_806AAA50);
    fn_803E9B3C(lbl_8060DB44, lbl_806AAA90);
    fn_803E9B3C(lbl_8060DB6C, lbl_806AAAD0);
}

struct Unk803EAFE4 {
    int m0, m4, m8, mC;
};

extern "C" Unk803EAFE4* fn_803EAFE4(Unk803EAFE4* o)
{
    o->m0 = 0;
    o->m8 = 0;
    o->mC = 0;
    o->m4 = 0;
    return o;
}
