/*
 * Game code, .text 0x800B2AAC-0x800B5C68 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"

struct UnkAt5C {
    char pad0[0x5C];
    int m5C;
};
struct UnkAtA8 {
    char pad0[0xA8];
    int mA8;
};
struct UnkAt1C24 {
    char pad0[0x1C];
    void* m1C;
    int m20;
    int m24;
};
extern int lbl_805C3CC4[];
extern const char* lbl_80619D34[];
extern int lbl_8061A114[];
void fn_800736EC(const char* s);

/* ---- generated externs ---- */


/* ---- functions ---- */
extern "C" {

int fn_800B2B78()
{
    return 0;
}

void fn_800B385C(UnkAt5C* p)
{
    p->m5C = 0;
}

void fn_800B3868() {}

int fn_800B386C(UnkAtA8* p)
{
    int r;
    if (p->mA8 > 3) {
        r = (p->mA8 - 3) * 500;
    } else {
        r = 0;
    }
    return r + 2000;
}

int fn_800B4C64()
{
    return 1;
}

void* fn_800B4CFC(UnkAt1C24* p)
{
    void* r = 0;
    if (p->m24 == 0) {
        r = p->m1C;
    }
    return r;
}

int fn_800B53A4(int a, int i)
{
    return lbl_805C3CC4[i];
}

void fn_800B548C(int i)
{
    fn_800736EC(lbl_80619D34[i]);
}

int fn_800B54BC(int i)
{
    return lbl_8061A114[i];
}

}
