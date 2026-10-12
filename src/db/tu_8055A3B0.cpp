/*
 * Database overlay code, .database_codeoverlay 0x8055A3B0-0x8055F730 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"

struct Db8055A880_Rec {
    int m0;
    float m4;
};

extern "C" DB_OVERLAY int fn_8055A880(Db8055A880_Rec* a, Db8055A880_Rec* b)
{
    return a->m0 - b->m0;
}

extern "C" DB_OVERLAY int fn_8055A890(Db8055A880_Rec* a, Db8055A880_Rec* b)
{
    if (b->m4 < a->m4)
        return -1;
    return b->m4 > a->m4;
}

extern "C" DB_OVERLAY int fn_8055A8B0(Db8055A880_Rec* a, Db8055A880_Rec* b)
{
    if (b->m4 > a->m4)
        return -1;
    return b->m4 < a->m4;
}

struct Db8055B048_Tbl {
    int m0;
};

extern "C" DB_OVERLAY int fn_8055B048(Db8055B048_Tbl* t, int a, int b)
{
    if ((unsigned)b <= 2 && a <= 0x7B) {
        char* base = (char*)t + 4;
        int o = b * 4 + a * 16;
        return *(int*)(base + o);
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055CC28(int a)
{
    return a == 1;
}

extern "C" DB_OVERLAY int fn_8055CC38(int a)
{
    switch (a) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 12:
    case 13:
        return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055CC68(int a)
{
    switch (a) {
    case 6:
    case 7:
    case 8:
    case 11:
    case 13:
        return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055CCA0(int a)
{
    return a == 10;
}
