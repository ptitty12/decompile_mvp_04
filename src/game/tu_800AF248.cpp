/*
 * Game code, .text 0x800AF248-0x800B2AAC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"

struct UnkAt2C {
    char pad0[0x2C];
    int m2C;
    int m30;
    char pad34[4];
    int m38;
    int m3C;
    int m40;
};
struct UnkAt10 {
    char pad0[0x10];
    int m10;
};
struct UnkAt10P {
    char pad0[0x10];
    void* m10;
};
void fn_800AF110(void* p);
void fn_800FC6B4(void* p);
void fn_800B245C(void* p);

/* ---- generated externs ---- */


/* ---- functions ---- */
extern "C" {

void fn_800AF544(UnkAt2C* p)
{
    p->m38 = 0;
    p->m3C = 0;
    p->m40 = 0;
    p->m2C = 0;
    p->m30 = 0;
}

void fn_800AF878(void* p)
{
    fn_800AF110(p);
}

void fn_800B0564(UnkAt10* p)
{
    p->m10 = 0;
}

void fn_800B0884(UnkAt10P* p)
{
    if (p->m10) {
        fn_800FC6B4(p->m10);
    }
}

int fn_800B2034(char* p)
{
    int* q = (int*)(p + 0x24);
    return q[*(int*)(p + 0x70) * 3];
}

int fn_800B2048(char* p)
{
    int* q = (int*)(p + 0x20);
    return q[*(int*)(p + 0x70) * 3];
}

void fn_800B243C(void* p)
{
    fn_800B245C(p);
}

}
