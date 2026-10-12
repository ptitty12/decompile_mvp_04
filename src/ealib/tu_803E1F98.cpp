/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803E1F98-0x803E2248 (code-only unit, 10 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

#include "../../include/game/tu_803E097C.h"

struct Unk803E2140_Init {
    int a, b, c;
};

extern Unk803E097C_Blk64* lbl_8062C310;
extern Unk803E2140_Init lbl_806AAB10;

extern "C" void fn_803E1EDC(void* self, void* node);
extern "C" Unk803E198C_View* fn_803E198C(Unk803E198C_View* v, Unk803E1F98_Node* node);
extern "C" void fn_803E1EE4(void* p, int c);

/* ctor of the 0x1AC-byte node (allocated by lbl_Owner::fn_803DA038 in tu_803D9FE8) */
extern "C" Unk803E1F98_Node* fn_803E1F98(Unk803E1F98_Node* n, lbl_Owner* owner)
{
    fn_803E1EDC(n, n);
    fn_803E198C(&n->mC, n);
    n->m4 = 0;
    n->m8 = 0;
    n->mC.mC = *lbl_8062C310;
    n->mC.m4C = *lbl_8062C310;
    n->mC.m8C = *lbl_8062C310;
    n->mC.m0 = owner;
    return n;
}

/* static initializer: Head(4, 4, 1) */
extern "C" void fn_803E2140(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        lbl_806AAB10.a = 4;
        lbl_806AAB10.b = 4;
        lbl_806AAB10.c = 1;
    }
}

extern "C" void fn_803E2178(Unk803E1F98_Node* n, int v)
{
    n->m8 = v;
}

extern "C" int fn_803E2180(Unk803E1F98_Node* n)
{
    return n->m8;
}

extern "C" void fn_803E2188(Unk803E1F98_Node* n, int chrg)
{
    fn_803E1EE4(n, 2);
    if (chrg & 1)
        lbl_8062C66C(n, 0x1AC);
}

extern "C" void fn_803E21DC(Unk803E1F98_Node* n, float* a, float* b, float* c, float* d)
{
    *a = n->mC.mE4;
    *b = n->mC.mE8;
    *c = n->mC.mEC;
    *d = n->mC.mF0;
}

extern "C" int fn_803E2200(Unk803E1F98_Node* n)
{
    return n->mC.m4;
}

extern "C" void fn_803E2208(Unk803E1F98_Node* n, int* src)
{
    n->mC.m8 = *src;
}

extern "C" Unk803E097C_Blk64* fn_803E2214(Unk803E1F98_Node* n)
{
    return &n->mC.m8C;
}

extern "C" void fn_803E2140(int initialize, int priority);

extern "C" void fn_803E221C()
{
    fn_803E2140(1, 0xFFFF);
}
