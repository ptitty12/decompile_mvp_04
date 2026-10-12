/*
 * Database overlay code, .database_codeoverlay 0x805942E0-0x80596D88 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

extern "C" void fn_805942A8();

extern "C" DB_OVERLAY void fn_805947F0()
{
    fn_805942A8();
}

extern "C" DB_OVERLAY void fn_80595378()
{
    fn_805942A8();
}

extern "C" DB_OVERLAY void fn_80596748(float, float)
{
}
