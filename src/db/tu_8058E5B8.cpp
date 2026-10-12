/*
 * Database overlay code, .database_codeoverlay 0x8058E5B8-0x805902E0 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

struct U {
    char pad0[0x4000];
};

extern "C" void fn_8058F774(U* self);

extern "C" void fn_8058F550(U* self);

extern "C" DB_OVERLAY void fn_8058F7B4(U* self)
{
    fn_8058F774(self);
    fn_8058F550(self);
}

extern "C" int fn_80594100(void* a, int b, int c);

extern "C" DB_OVERLAY int fn_8058FA38(void* a, int b)
{
    return fn_80594100(a, b, 1);
}

extern "C" void fn_805942A8();

extern "C" DB_OVERLAY void fn_8058FEC0()
{
    fn_805942A8();
}
