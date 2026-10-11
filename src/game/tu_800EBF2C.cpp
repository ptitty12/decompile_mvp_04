/*
 * Game code, .text 0x800EBF2C-0x800EE048 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800EBF2C.h"

void fn_800EC1E8(void* t)
{
    fn_800ECE34(t);
}

void fn_800EC624(Unk800EC624_T* t, int a, int b, int c)
{
    t->m140 = a;
    t->m13C = b;
    t->m144 = c;
}

void fn_800EC634()
{
}

void fn_800EC638()
{
}

void fn_800EC63C()
{
}

void fn_800EC640()
{
}

void fn_800EC644()
{
}

void fn_800EC82C(Unk800EC82C_T* t, Unk800EC82C_N* v)
{
    Unk800EC82C_N* old = t->m4C;
    if (old == 0) {
        t->m4C = v;
    } else {
        v->m24 = old;
        t->m4C = v;
    }
}

void fn_800ECFC0()
{
}

int fn_800ECFC4()
{
    return 0;
}

int fn_800ECFCC()
{
    return 0;
}

void fn_800ED4CC(char* t, const char* s)
{
    fn_8040B61C(t + 0x54, s);
}

int fn_800EDB78(Unk800EDB78_T* t)
{
    if (t->m138 == 0) {
        fn_800B555C();
    }
    return 1;
}

void fn_800EDC24(void* t, char* c)
{
    *c = 0;
}

void fn_800EDF5C(void* t)
{
    fn_800ED254(t);
}
