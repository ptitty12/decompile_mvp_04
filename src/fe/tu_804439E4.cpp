/*
 * Front-end overlay code, .frontend_codeoverlay 0x804439E4-0x80446CE8 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern "C" void fn_80330BC8(void* self);
extern "C" FE_OVERLAY void fn_80444090(void* self)
{
    fn_80330BC8(self);
}
