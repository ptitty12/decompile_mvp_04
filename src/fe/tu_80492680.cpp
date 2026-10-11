/*
 * Front-end overlay code, .frontend_codeoverlay 0x80492680-0x804987EC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" {

FE_OVERLAY void fn_804933A0(void* x)
{
    fn_804930F8(x);
    fn_80492FB4(x);
}

FE_OVERLAY int fn_804977FC(char* x)
{
    int i;
    for (i = 0; i < 8; i++) {
        char* b = x + 0x38C;
        int o = i * 0x44;
        if (*(int*)(b + o) != 0) {
            return 0;
        }
    }
    return 1;
}

FE_OVERLAY void fn_80497C08(void* x, int a)
{
    switch (a) {
    case -1:
        break;
    case 0:
        fn_80495248(x);
        break;
    case 1:
        fn_8049535C(x);
        break;
    }
}

FE_OVERLAY void fn_804983A8(void) {}

FE_OVERLAY void fn_80498438(char* x)
{
    if (*(void**)(x + 0x32C) != 0) {
        fn_80377488(*(void**)(x + 0x32C));
        *(int*)(x + 0x32C) = 0;
    }
}

FE_OVERLAY void fn_80498580(void) {}

FE_OVERLAY void fn_80498584(void)
{
    char buf[0xA0];
}

FE_OVERLAY void fn_804987C0(void* a, void* b)
{
    fn_804920B8(b, 1);
}

FE_OVERLAY void fn_804987E8(void) {}

}
