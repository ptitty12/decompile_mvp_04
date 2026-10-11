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

void fn_80172294(Unk80171A10_Menu* p, int a, const unsigned short* s)
{
    p->m64 = a;
    if (s) {
        fn_80403144(p->mDA, s);
    } else {
        p->mDA[0] = (unsigned short)(int)s;
    }
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

/* near-miss: retail uses separate zero registers for the two cleared pointer-to-member pairs (m74/m78 and
 * m80/m84, 28 instrs); about 400 statement orders and chained forms all reuse one. */
void fn_80172678(Unk80171A10_Menu* p)
{
    fn_801743E0(p);
    fn_80174438(p);
    fn_801744AC(p);
    p->m7C = 0x19;
    p->m18 = 4;
    p->m80 = 0;
    p->m84 = 0;
    p->m4 = 1;
    p->m70 = 0x19;
    p->m74 = 0;
    p->m78 = 0;
}

int fn_80173274(Unk80173274_T* p)
{
    int idx = p->m4;
    if (idx != 0) {
        return p->m0;
    }
    return *(int*)((char*)p + idx);
}

void fn_80174274(Unk80174274_T* p)
{
    fn_80171A10(p->m3C, 5);
}

void fn_8017429C(Unk80174274_T* p)
{
    fn_80171A10(p->m3C, 6);
}
