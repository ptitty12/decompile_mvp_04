/*
 * Database overlay code, .database_codeoverlay 0x805A1A9C-0x805A2604 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

extern "C" void fn_80400560(void* p, int n);

extern "C" DB_OVERLAY void fn_805A1A9C(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1AC0(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1AE4(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1B08(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1B2C(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1B50(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1B74(void* p)
{
    fn_80400560(p, 0x28);
}

struct U {
    char pad0[0x4000];
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_806841F8[];

extern "C" void fn_80377408(void* p);

extern "C" DB_OVERLAY void fn_805A1B98(U* self, int chrg)
{
    PUT(0x14, lbl_806841F8);
    if (chrg & 1)
        fn_80377408(self);
}

extern char lbl_80683EF8[];

extern "C" DB_OVERLAY void fn_805A1BCC(U* self, int chrg)
{
    PUT(0x4, lbl_80683EF8);
    if (chrg & 1)
        fn_80377408(self);
}

extern char lbl_80683B78[];

extern "C" DB_OVERLAY void fn_805A2208(U* self, int chrg)
{
    PUT(0xc, lbl_80683B78);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A22A0(U* self, int chrg)
{
    PUT(0xc, lbl_80683B78);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A22D4(U* self, int chrg)
{
    PUT(0xc, lbl_80683B78);
    if (chrg & 1)
        fn_80377408(self);
}

extern char lbl_806837B8[];

extern "C" DB_OVERLAY void fn_805A2474(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}
