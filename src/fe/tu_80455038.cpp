/*
 * Front-end overlay code, .frontend_codeoverlay 0x80455038-0x80459228 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern "C" void fn_800ECAA4(void* self);
extern "C" FE_OVERLAY void fn_8045899C(void* self)
{
    fn_800ECAA4(self);
}

extern "C" FE_OVERLAY void fn_80458FD4(void)
{
}

extern "C" FE_OVERLAY int fn_80458FD8(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_80458FE0(void)
{
    return 1;
}

extern "C" FE_OVERLAY void fn_80459224(void)
{
}
