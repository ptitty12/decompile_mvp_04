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

}
