/*
 * Database overlay code, .database_codeoverlay 0x8057CDB8-0x8058154C (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

extern "C" void fn_80377408(void* p);

extern "C" DB_OVERLAY void fn_8057DF38(void* p, int c)
{
    if (c & 1)
        fn_80377408(p);
}

extern "C" void fn_80542FCC();

extern "C" DB_OVERLAY void fn_8057DF60()
{
    fn_80542FCC();
}
