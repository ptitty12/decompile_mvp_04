/*
 * Game code, .text 0x8021F080-0x8022309C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern "C" {
int fn_802055F4(TaskInner* in);
int fn_80205664(TaskInner* in);
int fn_80226BC0(Task* t);
void fn_8014E09C(IterObj* it, CtxOwner* c, int x);
void fn_8014E108(IterObj* it);
int fn_8026D940(void* o, int x);
void fn_801EDE78(Task* t, int x);
void fn_801F0174(Task* t, int a, int b);
}

extern "C" {

extern Vec3f lbl_805D6244;
void fn_8021FFD4(Task* t, int, RecQueue* q)
{
    Rec* e = &q->e[0];
    TaskInner* in = t->m9C;
    Obj4_36C* o4 = in->m4;
    if (e->mA4 == 1) {
        e->mA4 = 0;
    }
    if (e->m28 == 0) {
        return;
    }
    if (o4->m36C == 0) {
        return;
    }
    if ((void*)o4->m36C == (void*)e->m28) {
        return;
    }
    e->mA4 = 1;
    e->m80 = lbl_805D6244.x;
    e->m9C = 0;
    e->mAC = 0;
}

int fn_80221974(Task* t)
{
    if (fn_802055F4(t->m9C) == 1 && fn_80205664(t->m9C) == 0) {
        Obj3A64* o = t->m9C->m3A64;
        if (o->m798 != 0 || o->m794 != 0) {
            return fn_80226BC0(t);
        }
    }
    return 1;
}

int fn_802219EC(Task* t)
{
    IterObj it;
    IterObj* p = &it;
    fn_8014E09C(p, t->m9C->m0, 1);
    while (p->m8 != 10) {
        if (fn_8026D940(t->m9C->m8[p->m8], 0) != 0) {
            return 1;
        }
        fn_8014E108(p);
    }
    return 0;
}

void fn_80222AE0(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    if (e->mA4 == 1) {
        e->mA4 = 0;
    }
    if (fn_80210C98((Sub*)&t->m9C, 3) == 1) {
        fn_801EDE78(t, 1);
        fn_801F0174(t, a, 0);
    }
}

}
