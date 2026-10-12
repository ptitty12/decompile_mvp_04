/*
 * Database overlay code, .database_codeoverlay 0x8059FE24-0x805A1A9C (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

struct U {
    char pad0[0x4000];
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_80684800[];

extern "C" void fn_80377408(void* p);

extern "C" DB_OVERLAY void fn_805A166C(U* self, int chrg)
{
    PUT(0x1c, lbl_80684800);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" void fn_80400560(void* p, int n);

extern "C" DB_OVERLAY void fn_805A177C(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A187C(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1A78(void* p)
{
    fn_80400560(p, 0x28);
}
