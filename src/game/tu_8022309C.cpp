/*
 * Game code, .text 0x8022309C-0x80227564 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern "C" {
int fn_8026D988(void* o, int x);
int fn_8026DB3C(void* o, int x);
int fn_8026DAE8(void* o, int x);
void fn_80205450(TaskInner* in, int x);
void fn_802123D4(Task* t, int kind, int x);
void fn_80213B80(Task* t, int a, int b, int c);
void fn_801EDE78(Task* t, int x);
void fn_801F0174(Task* t, int a, int b);
int fn_801E817C(Obj3A64* p, int x);
void fn_802278F4(Task* t);
void fn_801F0EA8(Task* t, int a);
void fn_801EE6F4(Task* t, int a);
void fn_80213988(Task* t, int a, int b);
void fn_8021D4A4(Task* t);
int fn_801F0F30(Task* t);
void fn_8022A71C(Task* t, int a, int b);
int fn_802055F4(TaskInner* in);
}

extern "C" {

extern Vec3f lbl_805D63F4;
void fn_8022321C(Task* t, int idx, RecQueue* q)
{
    Rec* e = &q->e[0];
    void* o = ObjAt(t->m9C->m8, idx);
    if (fn_8026D988(o, 0) == 1 || fn_8026DB3C(o, 0) == 1) {
        e->mA4 = 1;
        e->m80 = lbl_805D63F4.x;
        e->m9C = 0;
        e->mAC = 0;
    }
}

void fn_8022359C(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    e->m90 = e->m90 + 0.016666668f;
    t->m9C->m30 = 7;
    if (fn_80210C98((Sub*)&t->m9C, 3) == 1) {
        t->m9C->m19C = 0;
        fn_801EDE78(t, 1);
        fn_801F0174(t, a, 0);
    }
}

/* near-miss: 8 slots: retail forms in+3240 as its own base register (add. r10,r9,r11 / lwzx r0,r9,r11); ours folds it into the index */
void fn_80223910(Task* t, int a)
{
    TaskInner* in = t->m9C;
    int v = in->mC0.m[3];
    if (v == a || v == -1) {
        fn_80205450(in, a);
        fn_801F0EA8(t, a);
        fn_801EE6F4(t, a);
        fn_802123D4(t, 1, 1);
        fn_80213988(t, 3, 1);
    } else {
        Slots4* s = &in->mD4;
        int k = s->m[3];
        if (k != -1) {
            RecQueue* rq = &in->mCA8[k];
            if (rq && rq->count != 0) {
                if ((unsigned)(rq->e[0].m0 - 0xC) <= 1) {
                    fn_80211BA0(s, 3);
                }
            } else {
                fn_80205450(in, k);
                fn_801EE6F4(t, k);
                fn_802123D4(t, 1, 0);
                fn_8021D4A4(t);
            }
        }
        fn_80205450(t->m9C, a);
        fn_801F0EA8(t, a);
        fn_801EE6F4(t, a);
        fn_802123D4(t, 1, 1);
        fn_80213B80(t, 3, 2, 3);
    }
}

int fn_8022559C(Task* t)
{
    if (fn_8026DAE8(t->m9C->m8[0], 0) != 0) {
        fn_80205450(t->m9C, 0);
        fn_802123D4(t, 0, 0);
        fn_80213B80(t, 3, 2, 3);
        return 1;
    }
    return 0;
}

int fn_80225614(Task* t, int a)
{
    TaskInner* in = t->m9C;
    Obj4_36C* c = in->m0->m6CC;
    Obj36C* o = c->m374;
    if (c->m36C == 0 && o != 0) {
        int v = fn_80211BB0(&in->mC0, o->m460);
        fn_80205450(t->m9C, a);
        if (fn_802055F4(t->m9C) == 1 && (v != 3 || fn_801F0F30(t) == -1)) {
            fn_802123D4(t, 0, 0);
            fn_8022A71C(t, v, c->m378);
            fn_8021D4A4(t);
            return 1;
        }
    }
    return 0;
}

void fn_802258FC(Task* t)
{
    TaskInner* in = t->m9C;
    Obj3A64* o = in->m3A64;
    Obj4_36C* c = in->m0->m6CC;
    int ok = 0;
    if (c->m36C != 0) {
        t->mB8 = 0;
        ok = fn_801E817C(o, c->m36C->m460) == 0;
    }
    if (ok) {
        fn_802278F4(t);
    }
}

}
