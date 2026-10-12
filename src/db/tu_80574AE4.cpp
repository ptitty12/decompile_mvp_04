/*
 * Database overlay code, .database_codeoverlay 0x80574AE4-0x8057CDB8 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

struct U {
    char pad0[0x4000];
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_8064A550[];

extern "C" void fn_80377408(void* p);

extern "C" DB_OVERLAY void fn_8057C99C(U* self, int chrg)
{
    PUT(0x10, lbl_8064A550);
    if (chrg & 1)
        fn_80377408(self);
}
