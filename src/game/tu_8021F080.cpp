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
void fn_802044A4(Task* t, int a, void* p, float f);
void fn_801F0EA8(Task* t, int a);
}

extern char lbl_80660C48[];

class Unk802A9B9C : public EvBase {
public:
    int m8;
    int mC;
    Unk802A9B9C(int id) : EvBase(id)
    {
        m4 = lbl_80660C48;
        mC = 0;
        m8 = 0;
    }
    ~Unk802A9B9C() { m4 = lbl_80649DA0; }
    void fn_802A9B9C(int a);
    void fn_802A9BA4(int a);
};

extern const float lbl_805D6320;
extern const float lbl_805D6330;
extern const float lbl_805D6334;

extern "C" {

float fn_802478A0(void* o, void* p, int a, int b);

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

void fn_80220E48(Task* t, int a, Player* p)
{
    TaskInner* in = t->m9C;
    int z = in->m74;
    if (z == 0 && in->m70 == 1) {
        int f = p->m58C.m4b;
        if (f == 1) {
            Unk802A9B9C e(0x6E);
            e.fn_802A9B9C((int)p);
            e.fn_802A9BA4(a);
            fn_8037893C(t->m9C->m0->m704, e.m0, &e, 0, 0);
            t->m9C->m74 = f;
        }
    }
}

void fn_802217E0(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    void* x = ObjAt(t->m9C->m8, a);
    if (e->mA4 == 1) {
        if (!(e->m80 >= lbl_805D6320)) {
            e->m80 = (float)t->m9C->m0->m4C * lbl_805D6330 + fn_802478A0(x, (char*)q + 0x3C, e->mC, e->m10) + lbl_805D6334;
        }
        e->mA4 = 0;
    }
}

extern Vec3f lbl_805D6338;
void fn_802218A4(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    Obj4_36C* o = t->m9C->m4;
    if (e->mA4 == 1) {
        fn_802044A4(t, a, (char*)q + 0x48, e->m84);
        e->mA4 = 0;
    }
    Obj36C* x = o->m36C;
    if (x != 0) {
        if ((void*)x == ObjAt(t->m9C->m8, a)) {
            t->m9C->mA4 = -1;
            t->m9C->m30 = 4;
            fn_801F0EA8(t, a);
            fn_801F0174(t, a, 0);
            return;
        }
        e->mA4 = 1;
        e->m80 = lbl_805D6338.x;
        e->m9C = 0;
        e->mAC = 0;
    }
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
    fn_8014E09C(&it, t->m9C->m0, 1);
    IterObj* p = &it;
    while (p->m8 != 10) {
        int i = p->m8;
        if (fn_8026D940(ObjAt(t->m9C->m8, i), 0) != 0) {
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
