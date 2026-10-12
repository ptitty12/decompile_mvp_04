/*
 * Database overlay code, .database_codeoverlay 0x805A2604-0x805A2BB0 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

struct U {
    char pad0[0x4000];
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_806837B8[];

extern "C" void fn_80377408(void* p);

extern "C" DB_OVERLAY void fn_805A262C(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A2670(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A26BC(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A2708(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A2754(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A27A0(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A27E4(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A2838(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A2884(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A28C8(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A2914(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A2958(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A29A4(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A29E8(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" void fn_805A07C4(int a, int b);

extern "C" DB_OVERLAY void fn_805A2B84()
{
    fn_805A07C4(1, 0xFFFF);
}
