/*
 * Game code, .text 0x80171A10-0x80174318 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80171A10.h"

void fn_80172118() {}

void fn_8017211C() {}

void fn_8017227C(Unk8017227C_T* p, int a, int b, int i)
{
    p->m1C[i].m0 = a;
    p->m1C[i].m4 = b;
}

extern const Unk80171A10_Fn lbl_805CB114;

extern const Unk80171A10_Fn lbl_805CB11C;

extern const Unk80171A10_Fn lbl_805CB13C;

extern const Unk80171A10_Fn lbl_805CB144;

extern const Unk80171A10_Fn lbl_805CB134;

extern const Unk80171A10_Fn lbl_805CB14C;

extern const Unk80171A10_Fn lbl_805CB154;

extern const Unk80171A10_Fn lbl_805CB174;

extern const Unk80171A10_Fn lbl_805CB18C;

extern const Unk80171A10_Fn lbl_805CB1A4;

extern const Unk80171A10_Fn lbl_805CB1AC;

extern const Unk80171A10_Fn lbl_805CB1BC;

void fn_80172294(Unk80171A10_Menu* p, int a, const unsigned short* s)
{
    p->m64 = a;
    if (s) {
        fn_80403144(p->mDA, s);
    } else {
        p->mDA[0] = (unsigned short)(int)s;
    }
}

void fn_801722D0(Unk80171A10_Menu* p)
{
    p->m118 = 0;
    ((Unk80171A10_Svc*)fn_80173274((Unk80173274_T*)p))->mC4 = 1;
    fn_80174318(p, 0, lbl_805CB114);
}

void fn_80172334(Unk80171A10_Menu* p, int a, int b, const unsigned short* c, const char* d)
{
    p->m68 = a;
    p->m60 = 0;
    p->m4 = 0;
    fn_8040B61C(p->m88, d);
    fn_80172294(p, b, c);
    fn_80174318(p, 0, lbl_805CB114);
}

int fn_80172514(Unk80171A10_Menu* p)
{
    if (p->m70 <= 0xA) {
        fn_80174318(p, 1, lbl_805CB11C);
    }
    return 0;
}

void fn_80172564(Unk80171A10_Menu* p, const unsigned short* s)
{
    int f = 0;
    if (s != 0 && fn_80403060(s) > 0) {
        f = 1;
    }
    p->m54 = f;
    if (f != 0) {
        fn_80403144(p->mA4, s);
    }
}

int fn_801725C4(Unk80171A10_Menu* p, const unsigned short* s)
{
    if (p->m60 == 2) {
        if (s != 0) {
            fn_80403144(p->mA4, s);
            p->m60 = 0;
            return 1;
        }
        p->mA4[0] = -1;
    }
    return 0;
}

void fn_80172678(Unk80171A10_Menu* p)
{
    fn_801743E0(p);
    fn_80174438(p);
    fn_801744AC(p);
    p->m70 = 0x19;
    p->m7C = 0x19;
    p->m74 = 0;
    p->m80 = 0;
    p->m4 = 1;
    p->m18 = 4;
}

void fn_80172D00(Unk80171A10_Menu* p)
{
    int t = p->m4 + 1;
    p->m4 = t;
    if (t > 0) {
        p->m4 = 0;
    }
    fn_801728A0(p, 0, 4);
}

/* near-miss: native PTMF members give retail's separate zero registers; 3 slots of store order differ. */
void fn_801742C4(Unk80171A10_Menu* p)
{
    int t = p->m54;
    p->m60 = 0;
    p->m114 = -1;
    if (t == 0) {
        p->mA4[0] = (unsigned short)t;
    }
    p->m70 = p->m7C;
    p->m7C = 0x19;
    p->m74 = p->m80;
    p->m80 = 0;

}

int fn_801731D8(Unk80171A10_Menu* p, int idx)
{
    int id;
    switch (idx) {
    case 5: id = 5; break;
    case 6: id = 0xB; break;
    case 7: id = 0x11; break;
    case 8: id = 0xA; break;
    case 9: id = 0xD; break;
    default: id = 0x15; break;
    }
    if (id != 0x15) {
        fn_80172B60(p, id, 8);
        return 1;
    }
    return 0;
}

int fn_80173274(Unk80173274_T* p)
{
    int idx = p->m4;
    if (idx != 0) {
        return p->m0;
    }
    return *(int*)((char*)p + idx);
}

void fn_80173290(Unk80171A10_Menu* p)
{
    fn_80174438(p);
    p->m4 = 1;
    fn_80174318(p, 3, lbl_805CB134);
}

void fn_801732EC(Unk80171A10_Menu* p)
{
    fn_80172D00(p);
    if (p->m68 == 3) {
        fn_80174318(p, 4, lbl_805CB13C);
    } else {
        fn_80174318(p, 4, lbl_805CB144);
    }
}

/* near-miss: retail shares one tail call between the m40 path and the 805CB14C path (50 instrs); the
 * goto and pointer-variable spellings tried are 11+ slots off. */
void fn_80173378(Unk80171A10_Menu* p)
{
    p->m60 = 1;
    if (fn_80172D44(p, 0) == 0) {
        if (p->m40 != 0) {
            fn_80174318(p, 1, lbl_805CB11C);
            return;
        }
        if (((Unk80171A10_Svc*)fn_80173274((Unk80173274_T*)p))->mC4 == 0) {
            fn_80174318(p, 1, lbl_805CB11C);
            return;
        }
    }
    fn_80174318(p, 7, lbl_805CB14C);
}

void fn_80173A24(Unk80171A10_Menu* p)
{
    fn_80172B60(p, 7, 1);
    fn_80174318(p, 0xF, lbl_805CB174);
}

void fn_80173A80(Unk80171A10_Menu* p)
{
    fn_80172B60(p, 0xF, 0);
    fn_80174318(p, 0x11, lbl_805CB18C);
}

void fn_80173ADC(Unk80171A10_Menu* p)
{
    fn_80174318(p, 0x11, lbl_805CB18C);
}

void fn_80173BA4(Unk80171A10_Menu* p, unsigned short* buf)
{
    if (p->m48 != 0) {
        if (p->m64 == 0x11) {
            fn_80403144(buf, (const unsigned short*)fn_80090880(lbl_8061977C, 0x61C));
            return;
        }
        fn_80403144(buf, p->mDA);
    }
}

void fn_80173EBC(Unk80171A10_Menu* p)
{
    fn_80174318(p, 0x15, lbl_805CB1A4);
}

void fn_80173EFC(Unk80171A10_Menu* p)
{
    fn_80174318(p, 0x12, lbl_805CB1AC);
}

void fn_80174080(Unk80171A10_Menu* p)
{
    fn_80172B60(p, 0x10, 8);
    fn_80174318(p, 0x13, lbl_805CB1BC);
}

void fn_80174170(Unk80171A10_Menu* p)
{
    fn_80172B60(p, 0x14, 2);
    fn_80174318(p, 0, lbl_805CB114);
}

void fn_801741CC(Unk80171A10_Menu* p)
{
    if (((Unk80171A10_Svc*)fn_80173274((Unk80173274_T*)p))->mC4 != 0) {
        fn_80174318(p, 0x14, lbl_805CB154);
        if (p->m44 == 0) {
            fn_80172B60(p, 0x14, 8);
        }
    } else {
        fn_80174318(p, 1, lbl_805CB11C);
    }
}

void fn_80174274(Unk80174274_T* p)
{
    fn_80171A10(p->m3C, 5);
}

void fn_8017429C(Unk80174274_T* p)
{
    fn_80171A10(p->m3C, 6);
}
