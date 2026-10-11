/*
 * Game code, .text 0x8021ADDC-0x8021F080 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern "C" {
void fn_80205450(TaskInner* in, int x);
void fn_802123D4(Task* t, int kind, int x);
void fn_80229EF8(Task* t, int a, int b, int c, int d);
void fn_8021D4A4(Task* t);
void fn_8021D5D4(Task* t);
int fn_802055F4(TaskInner* in);
void fn_801E8A3C(Obj3A64* p, int a, int b);
void fn_8021C24C(Task* t, Player* p);
void fn_801EE6F4(Task* t, int a);
void fn_8021B430(Task* t, int a, int b, int c, int d, float f);
void fn_801F0174(Task* t, int a, int b);
}

extern "C" {

void fn_8021C424(Task* t, int a)
{
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 0x2f;
    e->m0 = 0x28;
    e->m88 = -1.0f;
    e->m9C = 0;
    e->m80 = -1.0f;
    e->mD4 = a;
}

void fn_8021D4A4(Task* t)
{
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 0;
    e->m0 = 0x29;
    e->m9C = 1;
}

void fn_8021D548(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    fn_80205450(t->m9C, a);
    fn_802123D4(t, 0, 1);
    fn_80229EF8(t, a, e->m1C, e->m28->m460, 0);
    fn_8021D4A4(t);
}

void fn_8021D5B4(Task* t)
{
    fn_8021D5D4(t);
}

/* The zero comes from a global struct so the load stays below the record stores (see fn_8021247C). */
extern Vec3f lbl_805D617C;
void fn_8021DB40(Task* t, int idx, RecQueue* q)
{
    Rec* e = &q->e[0];
    Player* p = (Player*)ObjAt(t->m9C->m8, idx);
    if (fn_802055F4(t->m9C) == 1) {
        fn_801E8A3C(t->m9C->m3A64, idx, -1);
    }
    if (p->m570 == 0) {
        e->mA4 = 1;
        e->m80 = lbl_805D617C.x;
        e->m9C = 0;
        e->mAC = 0;
    }
}

void fn_8021DBC8(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    if (!(e->m90 < 0.0f)) {
        e->m90 = e->m90 - 0.016666668f;
        return;
    }
    e->mA4 = 1;
    e->m80 = 0.0f;
    e->m9C = 0;
    e->mAC = 0;
    fn_80205450(t->m9C, a);
    fn_802123D4(t, 0, 1);
    if (e->m28) {
        fn_8021C24C(t, e->m28);
    } else {
        fn_801F0174(t, a, 0);
    }
}

extern Vec3f lbl_805D6188;
void fn_8021DC7C(Task* t, int idx, RecQueue* q)
{
    TaskInner* in = t->m9C;
    Obj36C* x = in->m4->m36C;
    if (x != ObjAt(in->m8, idx)) {
        Rec* e = &q->e[0];
        e->mA4 = 1;
        e->m80 = lbl_805D6188.x;
        e->m9C = 0;
        e->mAC = 0;
    } else if (x->m460 != idx) {
        Rec* e = &q->e[0];
        e->mA4 = 1;
        e->m80 = lbl_805D6188.x;
        e->m9C = 0;
        e->mAC = 0;
    }
}

extern Vec3f lbl_805D6198;
inline int Is3(Obj4_36C* o) { return o->m38C == 3; }
/* near-miss: 2 slots: retail emits mr r4,r30 before mr r3,r31 for the first fn_801EE6F4 call of the else-if arm */
void fn_8021DFF4(Task* t, int idx, RecQueue* q)
{
    TaskInner* in = t->m9C;
    Obj4_36C* o = in->m4;
    void* cur = ObjAt(in->m8, idx);
    if (Is3(o) == 1) {
        Rec* e = &q->e[0];
        e->mA4 = 1;
        e->m80 = lbl_805D6198.x;
        e->m9C = 0;
        e->mAC = 0;
        fn_801EE6F4(t, idx);
        fn_80205450(t->m9C, idx);
        fn_802123D4(t, 1, 1);
        fn_8021B430(t, 1, 1, 0, 0, 1.0f);
    } else if ((void*)o->m36C == cur) {
        fn_801EE6F4(t, idx);
        fn_801F0174(t, idx, 0);
    }
}

}
