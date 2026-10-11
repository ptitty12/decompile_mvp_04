/*
 * Game code, .text 0x800ACDA0-0x800AF248 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"

struct UnkAt1C {
    char pad0[0x1C];
    void* m1C;
};
struct UnkAt20F {
    char pad0[0x20];
    float m20;
};
struct UnkAtAA4 {
    char pad0[0xAA4];
    int mAA4;
};
struct UnkAtEF0 {
    char pad0[0xEF0];
    int mEF0;
};
struct UnkFEPair {
    int m0;
    int m4;
};
void fn_800ADE10(void* p);
void fn_800AD78C(void* p);
void fn_8033E4F0(void* p);
void fn_800AE574(void* p);
extern const float lbl_805B95B8;

/* ---- generated externs ---- */


/* ---- functions ---- */
extern "C" {

void fn_800ACDA0() {}

void fn_800ACF24(UnkAt1C* p)
{
    fn_800ADE10(p->m1C);
}

void fn_800ACF48(UnkAt20F* p)
{
    p->m20 = lbl_805B95B8;
}

void fn_800ACFE8() {}

void fn_800AD774(UnkAtAA4* p)
{
    if (p->mAA4 <= 7) {
        p->mAA4 = p->mAA4 + 1;
    }
}

UnkFEPair fn_800ADB34(char* base, int a, int b)
{
    return *(UnkFEPair*)(base + a * 0xe0 + b * 0x1c + 0x328);
}

void fn_800AE2E4(void* p)
{
    fn_800AD78C(p);
}

void fn_800AE944(void* p)
{
    fn_8033E4F0(p);
}

void fn_800AE964(UnkAtEF0* p, int v)
{
    p->mEF0 = v;
}

void fn_800AEA64() {}

void fn_800AEB88(char* p)
{
    fn_800AE574(p + 0x448);
}

void fn_800AEBAC(char* p)
{
    fn_800AE2E4(p + 0x448);
}

void fn_800AEC74() {}

char* fn_800AEC78(char* p)
{
    return p + 0x448;
}

int fn_800AF110()
{
    return 1;
}

}
