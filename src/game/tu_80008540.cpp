/*
 * Translation unit at 0x80008540 (original file name unknown; placeholder).
 * A real TU: it ends with its static-initializer wrapper (docs/UNITS.md
 * ctor anchors). 26 functions.
 *
 * .text 0x80008540-0x8000C2C4, .rodata 0x805A3A54-0x805A3B38, .data 0x80615848-0x80615850, .bss 0x80686A4C-0x80686AF8.
 * Not split (declare extern if used): small-data (.sdata/.sbss) objects and
 * any second, non-contiguous range of a section.
 *
 * Game controller ("gcpad") classes; layouts and evidence are in
 * include/game/tu_80008540.h.
 */
#include "game/tu_80008540.h"

extern "C" {
void fn_8043BA64(int);                      /* called once before the pads are created */
void* fn_8040B320(void* dst, int val, unsigned int n);   /* memset */
void* fn_803FFC58(void* dst, int val, unsigned int n);   /* memset */
void fn_804393B4(unsigned int mask);
}
extern char lbl_806E0210[0x30];             /* two 0x30-byte buffers (common symbols) */
extern char lbl_806E0240[0x30];

const char* lbl_80615848 = "gcpad";

/* Allocates the pad objects into arr and returns n. */
int fn_80008540(Unk800085B0** arr, int n)
{
    fn_8043BA64(1);
    for (int i = 0; i < n; i++) {
        arr[i] = new (0) Unk800085B0(i);
    }
    return n;
}

void fn_800085AC()
{
}

static const int lbl_805A3B18[4] = { 0x80000000, 0x40000000, 0x20000000, 0x10000000 };

Unk800085B0::Unk800085B0(int idx)
{
    m15DC = idx;
    m15E0 = 0;
    m15E4 = 0;
    m15E8 = -1;
    m15EC = 0.0f;
    m15F0 = -1;
    m15F4 = 0.0f;
    m15F8 = 0;
    m15FC = 0;
    fn_803FFC58(lbl_806E0210, 0, 0x30);
    fn_803FFC58(lbl_806E0240, 0, 0x30);
    fn_804393B4(lbl_805A3B18[m15DC]);
}

void Unk800085B0::vslot39()
{
}

void Unk800085B0::vslot42(Unk8000B258_State* out)
{
}

void Unk800085B0::vslot22(int a, float f)
{
    if (m15E4) {
        if (!m15F8 && m1600 <= 0) {
            m15E8 = a;
            m15E0 = 1;
            m15EC = f;
            m15F8 = 1;
        }
        m1600 = 5;
    }
}

void Unk800085B0::vslot23(int a, float f)
{
    if (m15E4) {
        if (!m15F8 && m1600 <= 0) {
            m15F0 = a;
            m15E0 = 1;
            m15F8 = 1;
            if (f > 1.0f)
                f = 1.0f;
            else if (!(f >= 0.0f))
                f = 0.0f;
            m15F4 = f;
        }
        m1600 = 5;
    }
}

void Unk800085B0::vslot24(int a)
{
    if (m15E4 != a) {
        m15E4 = a;
        m15EC = 0.0f;
        m15F4 = 0.0f;
        m15E0 = 1;
    }
}

Unk8000B258::Unk8000B258()
{
    fn_8040B320(&m1580, 0, sizeof(m1580));
}

int Unk8000B258::vslot41()
{
    return sizeof(Unk8000B258_State);
}

void Unk8000B258::vslot43(const Unk8000B258_State* s)
{
    m1580 = *s;
}

int Unk8000B258::vslot6()
{
    return m1580.m0;
}

int Unk8000B258::vslot7()
{
    return 0x15;
}

float Unk8000B258::vslot8(int i)
{
    return m1580.m4[i];
}

void Unk8000B258::vslot9(int i, float f)
{
    m1580.m4[i] = f;
}

int Unk8000B258::vslot25(int n)
{
    if (n <= 0)
        return n;
    if (n > 0x18)
        return n;
    return m0[n + 0xEC].m0;
}
