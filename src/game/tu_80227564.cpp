/*
 * Game code, .text 0x80227564-0x8022BB90 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern "C" {
int fn_802055F4(TaskInner* in);
void fn_80205450(TaskInner* in, int x);
void fn_802123D4(Task* t, int kind, int x);
void fn_801E81C8(Obj3A64* p);
void fn_801E8068(Obj3A64* p);
void fn_801E80F0(Obj3A64* p, int id);
int fn_801E8C1C(Obj3A64* p, int a, int* b, int* c);
int fn_801E8EF4(Obj3A64* p, int a, int* c);
void fn_8022A438(Task* t, int a, int b);
void fn_8022A580(Task* t, int a);
void fn_80229948(Task* t, int a);
void fn_8022AB14(Task* t, int a, RecQueue* q);
float fn_80218DCC(Task* t, void* x, void* y, int d);
int fn_802280E0(Task* t);
int fn_802281D0(Task* t, int a, int b, int c);
int fn_8024D41C(void* x);
}

inline void SetE8(Task* t, float v)
{
    t->mE8 = v;
}

extern "C" {

int fn_802278F4(Task* t)
{
    if (fn_802055F4(t->m9C) == 0) {
        return 0;
    }
    SetE8(t, -1.0f);
    t->m9C->m80 = 0;
    t->m9C->m40 = 0;
    int id = t->m9C->m4->m36C->m460;
    fn_801E81C8(t->m9C->m3A64);
    fn_801E8068(t->m9C->m3A64);
    fn_801E80F0(t->m9C->m3A64, id);
    return 1;
}

int fn_80227994(Task* t, int a)
{
    if (fn_802055F4(t->m9C) == 0) {
        return 0;
    }
    int id = t->m9C->m4->m36C->m460;
    fn_801E81C8(t->m9C->m3A64);
    fn_801E8068(t->m9C->m3A64);
    fn_801E80F0(t->m9C->m3A64, id);
    fn_80205450(t->m9C, id);
    fn_802123D4(t, 1, 1);
    fn_80229948(t, a);
    return 1;
}

int fn_80227A38(Task* t, int a)
{
    int s8 = -1;
    int r = 0;
    int sC = 0;
    if (fn_801E8C1C(t->m9C->m3A64, a, &s8, &sC) == 1) {
        r = 1;
        fn_80205450(t->m9C, a);
        fn_802123D4(t, 0, 0);
        fn_8022A438(t, s8, sC);
    } else if (fn_801E8EF4(t->m9C->m3A64, a, &sC) == 1) {
        r = 1;
        fn_80205450(t->m9C, a);
        fn_802123D4(t, 0, 0);
        fn_8022A580(t, sC);
    }
    return r;
}

int fn_8022921C(Task* t, int a)
{
    int r = -1;
    if (t->mF8 == 0.0f) {
        if (fn_802280E0(t) == 0) {
            TaskInner* in = t->m9C;
            int v = in->m1D8;
            if (v > 1) {
                r = in->m1F4;
                if (v > 2 && a == 0 && r == 1 && in->m20C == 2) {
                    r = 2;
                }
            } else {
                r = fn_802281D0(t, a, 1, 1);
            }
        } else if (a == 0) {
            TaskInner* in = t->m9C;
            if (in->mCA8 != 0) {
                Rec* e = in->mCA8->e;
                if (e != 0 && e->mBC != 0 && in->m1D8 > 1) {
                    r = in->m1F4;
                }
            }
        }
    }
    return r;
}

int fn_80229304(Task* t)
{
    return t->mF8 >= 2.0f;
}

float fn_80229324(Task* t)
{
    return t->mF8;
}

void fn_80229948(Task* t, int a)
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
    e->m4 = 3;
    e->m0 = 0x2b;
    e->m9C = 1;
    e->mA8 = 1;
    e->m80 = -1.0f;
    if (a == 1) {
        fn_8022AB14(t, t->m9C->m3A5C, t->m9C->m3A60);
    }
}

int fn_80229E50(Task* t, int a, int b, int c, int d)
{
    void* x = t->m9C->m8[a];
    void* y = t->m9C->m8[c];
    float f = fn_80218DCC(t, x, y, d);
    float k1 = 0.4f;
    float k2 = 0.85f;
    if (!(f >= 0.4f)) {
        if (fn_8024D41C(x) == 1) {
            return 2;
        }
    }
    return f <= 0.85f;
}

void fn_8022AB04(Task* t)
{
    t->m9C->m30 = 6;
}

}
