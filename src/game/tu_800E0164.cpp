/*
 * Game code, .text 0x800E0164-0x800E4234 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800E0164.h"

int fn_800E01C8(float f)
{
    int r = (int)(f * lbl_805BDBB8 + lbl_805BDBBC);
    if (r > 0x63) {
        r = 0x63;
    }
    return r;
}

int fn_800E0208(int a, unsigned int b)
{
    if (a == 12 || a == 14 || a == 15 || a == 16 || a == 17 || a == 18 || a == 19 || a == 20 || a == 21) {
        if (b <= 15) {
            return lbl_805C3B80[b];
        }
        return 0;
    }
    return b;
}

int fn_800E027C(int a, unsigned int b)
{
    if (a == 1 || a == 2 || a == 7 || a == 12 || a == 17 || a == 22) {
        if (b <= 15) {
            return lbl_805C3B80[b];
        }
        return 0;
    }
    return b;
}

int fn_800E18B0(int x)
{
    return fn_800E1B68(fn_80075D80(x));
}

int fn_800E18D4(int x)
{
    return fn_800E18F8(fn_800B5520(x));
}

int fn_800E18F8(int i)
{
    return lbl_805C2F00[i];
}

int fn_800E190C(int x)
{
    return fn_800E1930(fn_800B5520(x));
}

int fn_800E1930(int i)
{
    return lbl_805C30F0[i];
}

int fn_800E1944(int x)
{
    return fn_800E1968(fn_800B5520(x));
}

int fn_800E1968(int i)
{
    return lbl_805C32E0[i];
}

int fn_800E197C(int i)
{
    return lbl_805C34D0[i];
}

int fn_800E1990(int x)
{
    if (x <= 0x1F) {
        return 0;
    }
    if (x <= 0x3D) {
        return 1;
    }
    if (x <= 0x5B) {
        return 2;
    }
    if (x <= 0x79) {
        return 3;
    }
    return 0;
}

int fn_800E19CC(int x)
{
    int r = 0;
    if (fn_800E1990(x) == 0 && x != 0x1E && x != 0x1F) {
        r = 1;
    }
    return r;
}

int fn_800E1AC8(int i)
{
    return lbl_805C36C0[i];
}

/* near-miss: retail shares the tail of the 0x20 and 0x3E table cases and lays the 0x7A case out inline (9 slots) */
int fn_800E1ADC(int x)
{
    if (x <= 0x1F) {
        return lbl_805C3990[x];
    }
    if (x <= 0x3D) {
        return lbl_805C3A10[x - 0x20];
    }
    if (x <= 0x5B) {
        return lbl_805C3A88[x - 0x3E];
    }
    if (x > 0x79) {
        return lbl_805C3B78[x - 0x7A];
    }
    return lbl_805C3B00[x - 0x5C];
}

int fn_800E1B68(int i)
{
    return lbl_805C38B0[i];
}

void fn_800E2944(int a, int b)
{
    int o = lbl_8061930C;
    fn_8007DA58(o, a);
    int r = fn_80075C64(o, a);
    fn_8007DA8C(o, b, a);
    if (r != b && r <= 3 && a != -1) {
        fn_8007DA8C(o, r, -1);
    }
}

int fn_800E2B84()
{
    return fn_802B041C(lbl_8061E978);
}

int fn_800E2BAC()
{
    return fn_800E2B84();
}

int fn_800E2C08()
{
    fn_800E2D8C(lbl_805BA54C);
    return fn_800E2B84();
}
