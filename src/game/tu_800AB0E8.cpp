/*
 * Game code, .text 0x800AB0E8-0x800ACDA0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"

struct UnkFEEntry {        /* one-element array, count, pointer (see fn_800AB0C4) */
    int m0[1];
    int m4;
    int m8;
};
struct UnkFETable {        /* +0x24 entry count, +0x440 table of 0xC-byte entries */
    char pad0[0x24];
    int m24;
    char pad28[0x440 - 0x28];
    UnkFEEntry* m440;
};
struct UnkAt1C {
    char pad0[0x1C];
    void* m1C;
};
struct UnkAt20F {
    char pad0[0x20];
    float m20;
};
void fn_800AB0C4(UnkFEEntry* a, int v);
void fn_800ADAD8(void* p);
extern const float lbl_805B9590;

/* ---- generated externs ---- */


/* ---- functions ---- */
extern "C" {

int fn_800AB1AC(UnkFEEntry* a, int i)
{
    if (i < a->m4) {
        return a->m0[i];
    }
    return 0;
}

void fn_800AB758(UnkFETable* t, int idx, int v)
{
    fn_800AB0C4(t->m440 + idx, v);
}

int fn_800AB850(UnkFETable* t, int i)
{
    if (i < t->m24) {
        return t->m440[i].m4;
    }
    return 0;
}

int fn_800ABC30(UnkFETable* t, int i)
{
    if (i < t->m24) {
        return t->m440[i].m8;
    }
    return 0;
}

void fn_800ACA08() {}

void fn_800ACB0C(UnkAt1C* p)
{
    fn_800ADAD8(p->m1C);
}

void fn_800ACC34(UnkAt20F* p)
{
    p->m20 = lbl_805B9590;
}

void fn_800ACC44() {}

}
